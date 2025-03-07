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

#include "Scope.h"
#include <stdarg.h>

#ifdef DS_LOGGING_ENABLED
#include "LoggingLib.h"
#else
#undef printLog
#define printLog(...) {}
#define LOG_MALLOC_FAILURE(...) {}
#define logFile stderr
#endif

/// @union FuncData
///
/// @brief Translation between a function pointer and a data pointer.
///
/// @details Due to the way this library works, we sometimes need to pass and
/// return function pointers to and from our data structures, which take and
/// return data pointers.  ISO C doesn't permit casting between these two, so
/// we use a union to do the conversion.
///
/// @param func The function pointer portion of the pointer value.
/// @param data The data pointer portion of the pointer value.
typedef union FuncData {
  void (*func)(void*);
  void *data;
} FuncData;

/// @fn void* scopeAdd_(Scope *scope, volatile void *pointer, Destructor destructor, ...)
///
/// @brief Add an entry to the Scope object.
///
/// @note This function is wrapped by the a macro of the same name (minus the
/// trailing underscore) that automatically provides the standard destructor
/// of free if none is provided.
///
/// @param scope A pointer to the Scope object to add to.
/// @param pointer A pointer to the memory to be freed later.
/// @param ... A function pointer to call to free the pointer when it's
///   no longer needed (i.e. goes out of scope).
///
// @return Returns the value of the pointer parameter.  Any malloc failures
/// during this call will cause the program to exit.
void* scopeAdd_(Scope *scope, volatile void *pointer, ...) {
  printLog(TRACE, "ENTER scopeAdd(scope=%p, pointer=%p)\n",
    scope, pointer);
  
  va_list args;
  va_start(args, pointer);
  Destructor destructor = va_arg(args, Destructor);
  va_end(args);
  
  if (destructor == NULL) {
    // This should be impossible.  This function should only be called with the
    // macro wrapper that provides a default destructor.  For this to be the
    // case, someone has to deliberately call this method badly, but we still
    // need to check for it.
    printLog(ERR, "No destructor provided.\n");
    // Don't even attempt to track this data.  We'll eventually segfault in
    // somewhere unpredicatble and hard to debug.
    printLog(TRACE,
      "EXIT scopeAdd(scope=%p, pointer=%p, destructor=%p) = {%p}\n",
      scope, pointer, destructor, pointer);
    return (void*) pointer;
  } else if (scope == NULL) {
    printLog(ERR, "Invalid Scope object.\n");
    // pointer is non-NULL.  We can't track the memory, so we have to free it.
    destructor((void*) pointer); pointer = NULL;
    printLog(TRACE,
      "EXIT scopeAdd(scope=%p, pointer=%p, destructor=%p) = {%p}\n",
      scope, pointer, destructor, pointer);
    return (void*) pointer;
  }
  
  if (scope->numVars == scope->maxVars) {
    printLog(ERR, "Maximum number of variables in scope reached.\n");
    // pointer is non-NULL.  We can't track the memory, so we have to free it.
    destructor((void*) pointer); pointer = NULL;
    printLog(TRACE,
      "EXIT scopeAdd(scope=%p, pointer=%p, destructor=%p) = {%p}\n",
      scope, pointer, destructor, pointer);
    return (void*) pointer;
  }
  
  scope->variablesAndDestructors[scope->numVars].variable = pointer;
  scope->variablesAndDestructors[scope->numVars].destructor = destructor;
  scope->numVars++;
  
  printLog(TRACE, "EXIT scopeAdd(scope=%p, pointer=%p, destructor=%p) = {%p}\n",
    scope, pointer, destructor, pointer);
  return (void*) pointer;
}

/// @fn void scopePop_(Scope *scope, u64 numEntries)
///
/// @brief Remove 0 or more entries from the top of a Scope object.
///
/// @param scope A pointer to the Scope object to remove entries from.
/// @param numEntries The number of entries to remove from the top of the Scope
///   stack.  If this number is greater than the size of the stack, it is
///   reduced to the size of the stack.
///
/// @return This function always succeeds and returns no value.
void scopePop_(Scope *scope, u64 numEntries) {
  printLog(TRACE, "ENTER scopePop(scope=%p, numEntries=%llu)\n",
     scope, llu(numEntries));
  
  if (scope == NULL) {
    printLog(ERR, "Invalid Scope object.\n");
    printLog(TRACE, "EXIT scopeAdd(scope=%p, numEntries=%llu)\n",
      scope, llu(numEntries));
    return;
  } else if (numEntries > scope->numVars) {
    printLog(WARN, "numEntries exceeds Scope size.  Truncating.\n");
    numEntries = scope->numVars;
  }
  
  // If scope->numVars is 0, this will underflow.  However, the for loop below
  // only iterates to a maximum of scope->numVars because of the else if above.
  u64 maxIndex = scope->numVars - 1;
  
  // We bound numEntries to the size of the stack above, so no need to check for
  // NULL nodes, just the number of iterations.
  for (u64 iteration = 0; iteration < numEntries; iteration++) {
    u64 index = maxIndex - iteration;
    void *variable = (void*) scope->variablesAndDestructors[index].variable;
    Destructor destructor = scope->variablesAndDestructors[index].destructor;
    if (variable != NULL) {
      destructor(variable);
    }
  }
  
  scope->numVars -= numEntries;
  
  printLog(TRACE, "EXIT scopePop(scope=%p, numEntries=%llu)\n",
     scope, llu(numEntries));
  return;
}

/// @fn void scopeDestroy_(Scope *scope, volatile void *pointer)
///
/// @brief Remove and destroy an arbitrary entry from a Scope object.
///
/// @param scope A pointer to the Scope object to remove an entry from.
/// @param pointer A pointer to the memory that was previously added to the
///   Scope object.
///
/// @return Returns NULL on success, the original pointer value on failure.
void* scopeDestroy_(Scope *scope, volatile void *pointer) {
  printLog(TRACE, "ENTER scopeDestroy(scope=%p, pointer=%p)\n", scope, pointer);
  
  if ((scope == NULL) || (pointer == NULL)) {
    printLog(ERR, "One or more NULL parameters.\n");
    printLog(TRACE, "EXIT scopeDestroy(scope=%p, pointer=%p) = {%p}\n",
      scope, pointer, pointer);
    return (void*) pointer;
  }
  
  u64 numVars = scope->numVars;
  u64 index = 0;
  void *variable = NULL;
  for (; index < numVars; index++) {
    variable = (void*) scope->variablesAndDestructors[index].variable;
    if (variable == pointer) {
      break;
    }
  }
  if (index == numVars) {
    // Someone is trying to remove an entry that's not tracked by this object.
    printLog(ERR, "Removal of untracked pointer attempted.\n");
    printLog(TRACE, "EXIT scopeDestroy(scope=%p, pointer=%p) = {%p}\n",
      scope, pointer, pointer);
    return (void*) pointer;
  }
  
  // Call the destructor.
  Destructor destructor = scope->variablesAndDestructors[index].destructor;
  destructor(variable);
  pointer = NULL;
  
  // Scoot everything down.
  numVars--; // Stop one before the last index.
  for (; index < numVars; index++) {
    scope->variablesAndDestructors[index]
      = scope->variablesAndDestructors[index + 1];
  }
  scope->numVars = numVars;
  
  printLog(TRACE, "EXIT scopeDestroy(scope=%p, pointer=%p) = {NULL}\n",
    scope, pointer);
  return (void*) pointer;
}

/// @fn void scopeUpdate_(Scope *scope, volatile void *oldPointer, volatile void *newPointer)
///
/// @brief Replace a reference to a tracked pointer with a new pointer.  Does
/// not destroy the old pointer.
///
/// @note This function is wrapped by a macro of the same name (minus the
/// trailing underscore) that first caches the old pointer and uses the cached
/// version as the oldPointer parameter so that the variable can be used
/// as part of an update function for the newPointer if desired.
///
/// @param scope A pointer to the Scope object to remove an entry from.
/// @param oldPointer A pointer to the memory that was previously added to the
///   Scope object for which tracking is to be removed.
/// @param newPointer A pointer to the new memory to be tracked in place of the
///   old pointer.  If this value is NULL, no new tracking is added.
///
/// @return Returns the value being tracked.
void* scopeUpdate_(Scope *scope, volatile void *oldPointer, volatile void *newPointer) {
  printLog(TRACE,
    "ENTER scopeUpdate(scope=%p, oldPointer=%p, newPointer=%p)\n",
    scope, oldPointer, newPointer);
  
  if ((scope == NULL) || (oldPointer == NULL)) {
    printLog(ERR, "One or more NULL parameters.\n");
    printLog(TRACE,
      "EXIT scopeUpdate(scope=%p, oldPointer=%p, newPointer=%p) = {NULL}\n",
      scope, oldPointer, newPointer);
    return (void*) oldPointer;
  }
  
  u64 numVars = scope->numVars;
  u64 index = 0;
  void *variable = NULL;
  for (; index < numVars; index++) {
    variable = (void*) scope->variablesAndDestructors[index].variable;
    if (variable == oldPointer) {
      break;
    }
  }
  if (index == numVars) {
    // Someone is trying to remove an entry that's not tracked by this object.
    printLog(ERR, "Removal of untracked pointer attempted.\n");
    printLog(TRACE,
      "EXIT scopeUpdate(scope=%p, oldPointer=%p, newPointer=%p) = {NULL}\n",
      scope, oldPointer, newPointer);
    return NULL;
  }
  
  // *DO NOT* call the destructor.
  
  // Update the pointer the node tracks.
  scope->variablesAndDestructors[index].variable = newPointer;
  
  if (newPointer == NULL) {
    // Scoot everything down.
    numVars--; // Stop one before the last index.
    for (; index < numVars; index++) {
      scope->variablesAndDestructors[index]
        = scope->variablesAndDestructors[index + 1];
    }
    scope->numVars = numVars;
  }
  
  printLog(TRACE,
    "EXIT scopeUpdate(scope=%p, oldPointer=%p, newPointer=%p) = {%p}\n",
    scope, oldPointer, newPointer, newPointer);
  return (void*) newPointer;
}

/// @fn int scopeEnd_(Scope *scope)
///
/// @brief Remove all entries from the Scope object and free its resources.
///
/// @param scope A pointer to the scope object to destroy.
///
/// @return This function always succeeds and returns 0.
int scopeEnd_(Scope *scope) {
  printLog(TRACE, "ENTER scopeEnd(scope=%p)\n", scope);
  
  if (scope == NULL) {
    // Not an error, but nothing to do.
    printLog(TRACE, "EXIT scopeEnd(scope=%p) = {0}\n", scope);
    return 0;
  }
  
  scopePop_(scope, scope->numVars);
  
  printLog(TRACE, "EXIT scopeEnd(scope=%p) = {0}\n", scope);
  scope = NULL;
  return 0;
}

#include <stdlib.h>
#include "StringLib.h"

bool scopeUnitTest() {
  bool returnValue = true;
  
  SCOPE_ENTER("");
  
  // Test adding and removing.
  char *myString = (char*) scopeAdd(malloc(20), pointerDestroyFunction);
  if (myString == NULL) {
    printLog(ERR, "myString was NULL after scopeAdd().\n");
    returnValue = false;
    SCOPE_EXIT("", "%s", (returnValue == true) ? "true" : "false");
    return returnValue;
  }
  
  // Make sure the pointer's valid.  If it's not, we should segfault here.
  strcpy(myString, "Hello, world!");
  if (strcmp(myString, "Hello, world!") != 0) {
    printLog(ERR, "Expected myString to be \"Hello, world!\", got \"%s\".\n",
      myString);
    returnValue = false;
    SCOPE_EXIT("", "%s", (returnValue == true) ? "true" : "false");
    return returnValue;
  }
  
  if (scopeDestroy(myString) != NULL) {
    printLog(ERR, "scopeDestroy(myString) returned non-NULL.\n");
    returnValue = false;
    SCOPE_EXIT("", "%s", (returnValue == true) ? "true" : "false");
    return returnValue;
  }
  
  // Test adding and popping.
  myString = (char*) scopeAdd(malloc(20));
  if (myString == NULL) {
    printLog(ERR, "myString was NULL after scopeAdd().\n");
    returnValue = false;
    SCOPE_EXIT("", "%s", (returnValue == true) ? "true" : "false");
    return returnValue;
  }
  
  scopePopAll();
  if (_scope_.numVars != 0) {
    printLog(ERR, "Expected _scope_.numVars == 0, found %llu.\n",
      llu(_scope_.numVars));
    printLog(ERR, "Expected _scope_.numVars == 0, found %llu.\n",
      llu(_scope_.numVars));
    returnValue = false;
    SCOPE_EXIT("", "%s", (returnValue == true) ? "true" : "false");
    return returnValue;
  }
  
  // Test adding and replacing.
  myString = (char*) scopeAdd(malloc(20));
  if (myString == NULL) {
    printLog(ERR, "myString was NULL after scopeAdd().\n");
    returnValue = false;
    SCOPE_EXIT("", "%s", (returnValue == true) ? "true" : "false");
    return returnValue;
  }
  *myString = '\0'; // For the straddstr to work correctly.
  
  scopeUpdate(myString, straddstr(&myString, "Hello, world!"));
  if (strcmp(myString, "Hello, world!") != 0) {
    printLog(ERR, "Expected myString to be \"Hello, world!\", got \"%s\".\n",
      myString);
    returnValue = false;
    SCOPE_EXIT("", "%s", (returnValue == true) ? "true" : "false");
    return returnValue;
  }
  
  free(myString); // NEVER use free in real life!!!
  scopeUpdate(myString, malloc(20));
  // If the above failed then the below should segfault.
  strcpy(myString, "Goodbye, world!");
  if (strcmp(myString, "Goodbye, world!") != 0) {
    printLog(ERR, "Expected myString to be \"Goodbye, world!\", got \"%s\".\n",
      myString);
    returnValue = false;
    SCOPE_EXIT("", "%s", (returnValue == true) ? "true" : "false");
    return returnValue;
  }
  
  char *myString2 = (char*) scopeAdd(malloc(20), free);
  scopeRemove(myString2);
  myString2 = stringDestroy(myString2);
  
  SCOPE_EXIT("", "%s", (returnValue == true) ? "true" : "false");
  
  return returnValue;
}

