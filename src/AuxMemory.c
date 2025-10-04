////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                     Copyright (c) 2012-2025 James Card                     //
//                                                                            //
// Permission is hereby granted, free of charge, to any person obtaining a    //
// copy of this software and associated documentation files (the "Software"), //
// to deal in the Software without restriction, including without limitation  //
// the rights to use, copy, modify, merge, publish, distribute, sublicense,   //
// and/or sell copies of the Software, and to permit persons to whom the      //
// Software is furnished to do so, subject to the following conditions:       //
//                                                                            //
// The above copyright notice and this permission notice shall be included    //
// in all copies or substantial portions of the Software.                     //
//                                                                            //
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR //
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   //
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    //
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER //
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    //
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER        //
// DEALINGS IN THE SOFTWARE.                                                  //
//                                                                            //
//                                 James Card                                 //
//                          http://www.jamescard.org                          //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

// Doxygen marker
/// @file

#include <stdio.h>

#include "AuxMemory.h"
#include "OsApi.h"
#include "TypeDefinitions.h"

#ifdef MEM_LOGGING_ENABLED
#include "LoggingLib.h"
#else // MEM_LOGGING_ENABLED
#undef printLog
#define printLog(...) {}
#define logFile stderr
#undef printStackTrace
#define printStackTrace(...) {}
#define LOG_MALLOC_FAILURE(...) {}
#endif // MEM_LOGGING_ENABLED


// We need to wrap memory management functions for printStackTrace.  The reason
// is that this function may be called when the system is in a degraded state
// (i.e. there's something that is preventing memory management from working
// correctly).  While printStackTrace is running, we need to avoid calling the
// real functions.  Other than that, we need to pass through to the real calls.

/// @struct MemNode
///
/// @brief Metadata that's placed right before the memory pointer that's
/// returned by one one of the memory allocation functions.  These nodes are
/// used when the pointer is deallocated.
///
/// @param prev A pointer to the previous MemNode.
/// @param size The number of bytes allocated for this node.
typedef struct MemNode {
  struct MemNode *prev;
  size_t          size;
} MemNode;

/// @def memNode
///
/// @brief Get a pointer to the MemNode for a memory address.
#define memNode(ptr) \
  (((ptr) != NULL) ? &((MemNode*) (ptr))[-1] : NULL)

/// @def sizeOfMemory
///
/// @brief Retrieve the size of a block of dynamic memory.  This information is
/// stored in the MemNode before the pointer.
#define sizeOfMemory(ptr) \
  (((ptr) != NULL) ? memNode(ptr)->size : 0)

/// @def isStaticPointer
///
/// @brief Determine whether or not a pointer was allocated from the static
/// memory pool.
#define isStaticPointer(ptr) \
  ((((uintptr_t) (ptr)) >= _mallocStart) && (((uintptr_t) (ptr)) <= _mallocEnd))

// Function pointers to the real system memory management functions.
static void* (*realMalloc)(size_t size) = NULL;
static void  (*realFree)(void *ptr) = NULL;
static void* (*realCalloc)(size_t nmemb, size_t size) = NULL;
static void* (*realRealloc)(void *ptr, size_t size) = NULL;

/// @var _bypassRealMemorySystemCalls
///
/// @brief Whether or not the real memory calls are currently being bypassed.
/// Initialized to 0.  When auxMemoryInit is looking up the real
/// memory calls, it is set to a value less than 0.  When the memory functions
/// detect this case, they will not attempt to lock the mutex since it will not
/// have been initialized yet.  In all other cases where the real memory calls
/// need to be bypassed, the value is incremented when the bypass is needed and
/// decremented the bypass is no longer needed.
static int _bypassRealMemorySystemCalls = 0;

/// @var auxMemoryInitRun
///
/// @brief once_flag variable to keep track of whether or not
/// auxMemoryInit has run yet.
once_flag auxMemoryInitRun = ONCE_FLAG_INIT;

/// @def MALLOC_BUFFER_SIZE
///
/// @brief The size in bytes of the statically allocated buffer to use for
/// memory allocation when system memory calls are being bypassed.
#define MALLOC_BUFFER_SIZE 65536

/// @var _mallocStaticBuffer
///
/// @brief Static buffer to return from a wrapper when bypassing the real
/// memory management system calls.
static char _mallocStaticBuffer[MALLOC_BUFFER_SIZE];

/// @var _mallocNext
///
/// @brief Pointer to the next free segment of memory within
/// _mallocStaticBuffer.
static char *_mallocNext = &_mallocStaticBuffer[sizeof(MemNode)];

/// @var _mallocStart
///
/// @brief Numerical address of the start of the static malloc buffer.
static const uintptr_t _mallocStart
  = (uintptr_t) &_mallocStaticBuffer[sizeof(MemNode)];

/// @var _mallocEnd
///
/// @brief Numerical address of the end of the static malloc buffer.
static const uintptr_t _mallocEnd
  = (uintptr_t) &_mallocStaticBuffer[MALLOC_BUFFER_SIZE - sizeof(MemNode) - 1];

/// @var _staticBufferLock
///
/// @brief Mutex to guard access to the metadata for the static bufer.
ZEROINIT(static mtx_t _staticBufferLock);

/// @var _loggingMemoryInitialized
///
/// @brief State variable to keep track of whether or not the memory variables
/// above have been initialized.
static bool _loggingMemoryInitialized = false;

#ifdef __cplusplus
extern "C"
{
#endif

#if !_MSC_VER && !_WIN32

#ifndef __USE_GNU
#define __USE_GNU
#endif
#include <dlfcn.h>

/// @fn void initGccMemoryFunctions()
///
/// @brief Use the GCC calls to populate the function pointers for the system
/// memory management functions.
///
/// @return This function returns no value.
void initGccMemoryFunctions() {
  // We need to mark _bypassRealMemorySystemCalls when trying to resolve the
  // pointer for realCalloc.  Once we do this, all further calls to dlsym
  // will utilize the real calloc in glibc.  Resolving the realCalloc
  // function pointer first ensures that we only need to return the
  // static buffer once, thereby avoiding the need to clear the buffer
  // each time.
  _bypassRealMemorySystemCalls = -1;
  *((void**) &realCalloc) = dlsym(RTLD_NEXT, "calloc");
  *((void**) &realMalloc) = dlsym(RTLD_NEXT, "malloc");
  *((void**) &realFree) = dlsym(RTLD_NEXT, "free");
  *((void**) &realRealloc) = dlsym(RTLD_NEXT, "realloc");
  _bypassRealMemorySystemCalls = 0;
}

#else // _MSC_VER OR _WIN32 is defined

#include <windows.h>

/// @fn void initWindowsMemoryFunctions()
///
/// @brief Use the Windows calls to populate the function pointers for the
/// system memory management functions.
///
/// @return This function returns no value.
void initWindowsMemoryFunctions() {
  _bypassRealMemorySystemCalls = -1;
  HMODULE hModule = LoadLibraryA("C:\\Windows\\system32\\msvcrt.dll");
  if (hModule == NULL) {
    fputs("Could not load C:\\Windows\\system32\\msvcrt.dll\n", stderr);
    exit(1);
  }

  *((void**) &realCalloc) = GetProcAddress(hModule, "calloc");
  *((void**) &realMalloc) = GetProcAddress(hModule, "malloc");
  *((void**) &realFree) = GetProcAddress(hModule, "free");
  *((void**) &realRealloc) = GetProcAddress(hModule, "realloc");

  FreeLibrary(hModule);
  _bypassRealMemorySystemCalls = 0;
}

#endif // _MSC_VER

/// @fn void auxMemoryInit(void)
///
/// @brief Initialize the pointers to the real system calls and the metadata
/// needed for our static memory functions.
///
/// @return This function returns no value.
void auxMemoryInit(void) {
  // First, initialize the function pointers to the system-specific memory
  // management calls.
#if !_MSC_VER && !_WIN32
  initGccMemoryFunctions();
#else // _MSC_VER OR _WIN32 is defined
  initWindowsMemoryFunctions();
#endif // _MSC_VER
  
  // Initialize our own metadata.
  if (mtx_init(&_staticBufferLock, mtx_plain | mtx_recursive) != thrd_success) {
    fputs("WARNING:  Could not initialize _staticBufferLock.\n", stderr);
    fputs("          Possible system problem.\n", stderr);
  }
  
  memNode(_mallocNext)->prev = NULL;
  memNode(_mallocNext)->size = 0;
  
  _loggingMemoryInitialized = true;
}

/// @fn void free(void *ptr)
///
/// @brief Free previously-allocated memory.  The provided pointer may have
/// been allocated either by the system memory functions or from our static
/// memory pool.
///
/// @param ptr A pointer to the block of memory to free.
///
/// @return This function always succeeds and returns no value.
void free(void *ptr) {
  call_once(&auxMemoryInitRun, auxMemoryInit);
  
  char *charPointer = (char*) ptr;
  
  if ((_bypassRealMemorySystemCalls != 0) || (isStaticPointer(ptr))) {
    if (_loggingMemoryInitialized == true) {
      mtx_lock(&_staticBufferLock);
    } // else we're initializing and the mutex isn't setup yet
    if (isStaticPointer(ptr)) {
      // This is static memory that was previously allocated from one of our
      // wrappers while the system calls were being bypassed.  Do *NOT* attempt
      // to free this with realFree.  Handle it ourselves.
      
      // Check the size of the memory in case someone tries to free the same
      // pointer more than once.
      if (sizeOfMemory(ptr) > 0) {
        if ((charPointer + sizeOfMemory(ptr) + sizeof(MemNode))
          == _mallocNext
        ) {
          // Special case.  The value being freed is the last one that was
          // allocated.  Do memory compaction.
          _mallocNext = (char*) charPointer;
          for (MemNode *cur = memNode(ptr)->prev;
            (cur != NULL) && (cur->size == 0);
            cur = cur->prev
          ) {
            _mallocNext = (char*) &cur[1];
          }
        }
        
        // Clear out the size.
        memNode(charPointer)->size = 0;
        
        if (_loggingMemoryInitialized == true) {
          mtx_unlock(&_staticBufferLock);
        } // else we're initializing and the mutex isn't setup yet
      }
      return;
    }
    if (_loggingMemoryInitialized == true) {
      mtx_unlock(&_staticBufferLock);
    }
  }
  
  // Pointer was not allocated from the static pool.  Call the real function.
  if (charPointer != NULL) {
    charPointer -= sizeof(MemNode);
  }
  realFree(charPointer);
  return;
}
void (*localFree)(void *ptr) = free;

/// @fn void* realloc(void *ptr, size_t size)
///
/// @brief Reallocate a provided pointer to a new size.
///
/// @param ptr A pointer to the original block of dynamic memory.  If this value
///   is NULL, new memory will be allocated.
/// @param size The new size desired for the memory block at ptr.  If this value
///   is 0, the provided pointer will be freed.
///
/// @return Returns a pointer to size-adjusted memory on success, NULL on
/// failure or free.
void* realloc(void *ptr, size_t size) {
  char *charPointer = (char*) ptr;
  char *returnValue = NULL;
  
  call_once(&auxMemoryInitRun, auxMemoryInit);
  
  if (_bypassRealMemorySystemCalls != 0) {
    if (_loggingMemoryInitialized == true) {
      mtx_lock(&_staticBufferLock);
    }
    do {
      if (size == 0) {
        // In this case, there's no point in going through any path below.  Just
        // free it, return NULL, and be done with it.
        localFree(ptr);
        if (_loggingMemoryInitialized == true) {
          mtx_unlock(&_staticBufferLock);
        }
        return NULL;
      }
      
      if (isStaticPointer(ptr)) {
        // This pointer was allocated from the static memory pool.
        if (size <= sizeOfMemory(ptr)) {
          // We're fitting into a block that's larger than or equal to the size
          // being requested.  *DO NOT* update the size in this case.  Just
          // return the current pointer.
          if (_loggingMemoryInitialized == true) {
            mtx_unlock(&_staticBufferLock);
          }
          return ptr;
        } else if ((charPointer + sizeOfMemory(ptr) + sizeof(MemNode))
          == _mallocNext
        ) {
          // The pointer we're reallocating is the last one allocated.  We have
          // an opportunity to just reuse the existing block of memory instead
          // of allocating a new block.
          if ((uintptr_t) (charPointer + size + sizeof(MemNode))
            <= _mallocEnd
          ) {
            // Update the size before returning the pointer.
            memNode(charPointer)->size = size;
            if (_loggingMemoryInitialized == true) {
              mtx_unlock(&_staticBufferLock);
            }
            return ptr;
          } else {
            // Out of memory.  Fail the request.
            if (_loggingMemoryInitialized == true) {
              mtx_unlock(&_staticBufferLock);
            }
            return NULL;
          }
        }
        // else we have to allocate new memory.  Fall through to the case below.
      } else if (ptr != NULL) {
        // We shouldn't reallocate system dynamic memory with this algorithm
        // Wait for the system allocator to come back online.
        if (_loggingMemoryInitialized == true) {
          mtx_unlock(&_staticBufferLock);
        }
        while (_bypassRealMemorySystemCalls != 0) {
          msleep(1);
        }
        
        // Fall through to the system realloc below.
        break;
      }
      
      // We're allocating new memory from our static memory pool.
      if ((((uintptr_t) (_mallocNext + size + sizeof(MemNode)))
        <= _mallocEnd)
      ) {
        returnValue = _mallocNext;
        memNode(returnValue)->size = size;
        _mallocNext += size + sizeof(MemNode);
        memNode(_mallocNext)->prev = memNode(returnValue);
        memNode(_mallocNext)->size = 0;
      } // else we don't have enough memory left to satisfy the request.
      if (_loggingMemoryInitialized == true) {
        mtx_unlock(&_staticBufferLock);
      }
      
      if ((returnValue != NULL) && (ptr != NULL)) {
        // Because of the logic above, we're guaranteed that this means that the
        // address of returnValue is not the same as the address of ptr.  Copy
        // the data from the old memory to the new memory and free the old
        // memory.
        memcpy(returnValue, ptr, sizeOfMemory(ptr));
        localFree(ptr);
      }
      
      return returnValue;
    } while(0);
  } else if (isStaticPointer(ptr)) {
    // We're being asked to use the real allocation functions to reallocate a
    // pointer that was previously allocated from the static memory pool.  Need
    // to handle this special case gracefully.
    if (size > 0) {
      returnValue = (char*) realRealloc(NULL, size + sizeof(MemNode));
    }
    if (returnValue != NULL) {
      returnValue += sizeof(MemNode);
      memNode(returnValue)->size = size;
      memNode(returnValue)->prev = NULL;
      memcpy(returnValue, ptr, sizeOfMemory(ptr));
    }
    localFree(ptr);
    
    return returnValue;
  }
  
  // Call the real function.
  if (charPointer != NULL) {
    charPointer -= sizeof(MemNode);
  }
  returnValue = (char*) realRealloc(charPointer, size + sizeof(MemNode));
  if (returnValue != NULL) {
    returnValue += sizeof(MemNode);
    memNode(returnValue)->size = size;
    memNode(returnValue)->prev = NULL;
  }
  return returnValue;
}
void* (*localRealloc)(void *ptr, size_t size) = realloc;

/// @fn void* malloc(size_t size)
///
/// @brief Allocate but do not clear memory.
///
/// @param size The size of the block of memory to allocate in bytes.
///
/// @return Returns a pointer to newly-allocated memory of the specified size
/// on success, NULL on failure.
void* malloc(size_t size) {
  void *returnValue = localRealloc(NULL, size);
  
  return returnValue;
}
void* (*localMalloc)(size_t size) = malloc;

/// @fn void* calloc(size_t nmemb, size_t size)
///
/// @brief Allocate memory and clear all the bytes to 0.
///
/// @param nmemb The number of elements to allocate in the memory block.
/// @param size The size of each element to allocate in the memory block.
///
/// @return Returns a pointer to zeroed newly-allocated memory of the specified
/// size on success, NULL on failure.
void* calloc(size_t nmemb, size_t size) {
  char *returnValue = NULL;
  size_t totalSize = nmemb * size;
  
  if (_bypassRealMemorySystemCalls != 0) {
    returnValue = (char*) localRealloc(NULL, totalSize);
    if (returnValue != NULL) {
      memset(returnValue, 0, totalSize);
    }
    return returnValue;
  }
  
  call_once(&auxMemoryInitRun, auxMemoryInit);
  
  returnValue = (char*) realCalloc(1, totalSize + sizeof(MemNode));
  if (returnValue != NULL) {
    returnValue += sizeof(MemNode);
    memNode(returnValue)->size = size;
  }
  return returnValue;
}
void* (*localCalloc)(size_t nmemb, size_t size) = calloc;

#ifdef __cplusplus
} // extern "C"
#endif

/// @fn void useAuxMemory(void)
///
/// @brief Set the necessary state variables to ensure that auxiliary memory
/// is used by the process and normal memory is bypassed.
///
/// @return This function returns no value.
void useAuxMemory(void) {
  if (_bypassRealMemorySystemCalls == 0) {
    mtx_lock(&_staticBufferLock);
    _bypassRealMemorySystemCalls++;
  }
}

/// @fn void useNormalMemory(void)
///
/// @brief Set the necessary state variables to ensure that normal memory is
/// used by the process and auxiliary is bypassed.
void useNormalMemory(void) {
  if (_bypassRealMemorySystemCalls > 0) {
    _bypassRealMemorySystemCalls--;
    mtx_unlock(&_staticBufferLock);
  }
}

