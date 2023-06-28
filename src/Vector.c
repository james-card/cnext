////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                     Copyright (c) 2012-2023 James Card                     //
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

#include "List.h"
#include "Vector.h"
#include "HashTable.h" // for JSON
#include "Scope.h"

#ifdef DS_LOGGING_ENABLED
#include "LoggingLib.h"
#else
#undef printLog
#define printLog(...) {}
#define logFile stderr
#define LOG_MALLOC_FAILURE(...) {}
#endif

#include "StringLib.h"

/// @fn Vector *vectorCreate_(TypeDescriptor *keyType, bool disableThreadSafety, u64 size, ...)
///
/// @brief Create a vector with the specified key type.
///
/// @param keyType is the type of key to use for the vector.
/// @param disableThreadSafety Whether or not to disable thread safety for the
///   Vector.
/// @param size The initial size of the vector.
///
/// @note This function is wrapped by a macro of the same name (minus the
/// trailing underscore) that automatically provides false for
/// disableThreadSafety and 0 for the size parameter.
///
/// @return Returns a newly-initialized vector on success, NULL on failure.
Vector *vectorCreate_(TypeDescriptor *keyType, bool disableThreadSafety, u64 size, ...) {
  if (keyType == NULL) {
    printLog(ERR, "keyType is NULL.\n");
    return NULL;
  }
  printLog(TRACE, "ENTER vectorCreate(keyType=%s)\n", keyType->name);
  
  Vector *returnValue = (Vector*) calloc(1, sizeof(Vector));
  if (returnValue == NULL) {
    LOG_MALLOC_FAILURE();
    printLog(NEVER, "EXIT vectorCreate(keyType=%s) = {%p}\n",
      keyType->name, returnValue);
    return NULL;
  }
  
  // No reason to NULL-ify variables.
  returnValue->keyType = keyType;
  if (disableThreadSafety == false) {
    // The lock mtx_t member variable has to be zeored, so use calloc.
    returnValue->lock = (mtx_t*) calloc(1, sizeof(mtx_t));
    if (mtx_init(returnValue->lock, mtx_plain | mtx_recursive) != thrd_success) {
      printLog(ERR, "Could not initialize vector mutex lock.\n");
    }
  }
  
  if (size > 0) {
    VectorNode *array = (VectorNode*) malloc(size * sizeof(VectorNode));
    if (array == NULL) {
      LOG_MALLOC_FAILURE();
      printLog(NEVER, "EXIT vectorCreate(keyType=%s) = {%p}\n",
        keyType->name, returnValue);
      return NULL;
    }
    for (u64 i = 0; i < size; i++) {
      array[i].allocated = false;
    }
    returnValue->array = array;
    returnValue->arraySize = size;
  }
  returnValue->filePointer = NULL;
  
  printLog(TRACE, "EXIT vectorCreate(keyType=%s) = {%p}\n",
    keyType->name, returnValue);
  return returnValue;
}

/// @fn VectorNode *kvVectorSetEntry_(Vector *vector, u64 index, const volatile void *key, const volatile void *value, TypeDescriptor *type, ...)
///
/// @brief Set a specific index of a vector to the specified value.
///
/// @param vector The vector to modify.
/// @param index The index of the vector to modify.
/// @param value The new value of the index.
/// @param type The type of the value.
///
/// @note This function is wrapped by a define of the same name, minus the
/// leading underscore.  The type parameter is optional when the define is
/// used.
///
/// @return Returns a pointer to the modified index on success, NULL on failure.
VectorNode *kvVectorSetEntry_(Vector *vector, u64 index,
  const volatile void *key, const volatile void *value, TypeDescriptor *type,
  ...
) {
  printLog(TRACE,
    "ENTER kvVectorSetEntry(vector=%p, index=%llu, key=%p, value=%p, type=%p)\n",
    vector, llu(index), key, value, type);
  
  // Argument check.
  if (vector == NULL) {
    printLog(ERR, "vector is NULL.\n");
    printLog(TRACE,
      "EXIT kvVectorSetEntry(vector=%p, index=%llu, key=%p, value=%p, type=%s) = {%p}\n",
      vector, llu(index), key, value, (type != NULL) ? type->name : "NULL",
      (void*) NULL);
    return NULL;
  }
  
  if ((vector->lock != NULL) && (mtx_lock(vector->lock) != thrd_success)) {
    printLog(WARN, "Could not lock vector mutex.\n");
  }
  
  if (type == NULL) {
    if ((vector->arraySize > index) && (vector->array[index].allocated)) {
      type = vector->array[index].type;
    } else if (vector->tail != NULL) {
      type = vector->tail->type;
      printLog(DEBUG, "Defaulting to type of tail.\n");
    } else {
      type = vector->keyType;
      printLog(DEBUG, "Defaulting to type of key.\n");
    }
  }
  
  if (index >= vector->arraySize) {
    u64 newSize = index + 1;
    VectorNode *array = (VectorNode*) realloc(
      vector->array, newSize * sizeof(VectorNode));
    if (array == NULL) {
      LOG_MALLOC_FAILURE();
      printLog(TRACE,
        "EXIT kvVectorSetEntry(vector=%p, index=%llu, key=%p, value=%p, type=%s) = {%p}\n",
        vector, llu(index), key, value, type->name, (void*) NULL);
      return NULL;
    }
    for (u64 i = vector->arraySize; i < newSize; i++) {
      array[i].allocated = false;
    }
    
    if (array != vector->array) {
      // This operation just got a lot more expensive.  Because we're in a new
      // block of memory, we have to fix all the pointers.  Lesson here:  Do
      // *NOT* dynamically resize the vector unless you have no choice.
      //
      // We have to go ahead and set the array of the vector here because we
      // need the vectorFind*Allocated functions to work and those work with
      // vectors.
      vector->array = array;
      if (array[0].allocated) {
        vector->head = &array[0];
      } else {
        vector->head = vectorFindNextAllocated(vector, 0);
      }
      // Nothing above the original arraySize is allocated since we just
      // extended it above, so we can save ourselves a little trouble and just
      // evaluate up to the old max.
      if (vector->arraySize > 0) {
        vector->tail = vectorFindPreviousAllocated(vector, vector->arraySize - 1);
      } // else vector->tail remains NULL
      for (u64 i = 0; i < vector->arraySize; i++) {
        if (array[i].allocated) {
          array[i].next = vectorFindNextAllocated(vector, i);
          array[i].prev = vectorFindPreviousAllocated(vector, i);
        }
      }
    }
    vector->arraySize = newSize;
  }
  
  VectorNode *returnValue = &vector->array[index];
  if (returnValue->allocated) {
    vector->keyType->destroy(returnValue->key);
    returnValue->type->destroy(returnValue->value);
  }
  
  returnValue->value = type->copy(value);
  returnValue->type = type;
  returnValue->key = vector->keyType->copy(key);
  returnValue->prev = vectorFindPreviousAllocated(vector, index);
  if (returnValue->prev != NULL) {
    returnValue->prev->next = returnValue;
  }
  returnValue->next = vectorFindNextAllocated(vector, index);
  if (returnValue->next != NULL) {
    returnValue->next->prev = returnValue;
  }
  returnValue->byteOffset = 0;
  bool oldIndexAllocated = returnValue->allocated;
  // We have to mark this index allocated before we search for head and tail
  // below so that the vectorFind*Allocated functions work correctly.
  returnValue->allocated = true;
  
  if (!oldIndexAllocated) {
    // We're adding a value.  Adjust the Vector metadata.
    vector->size++;
    if (vector->array[0].allocated) {
      vector->head = &vector->array[0];
    } else {
      vector->head = vectorFindNextAllocated(vector, 0);
    }
    // If we made it this far, vector->arraySize is guaranteed to be at least 1,
    // so decrementing it here is OK.
    vector->tail = vectorFindPreviousAllocated(vector, vector->arraySize - 1);
  }
  
  if (vector->lock != NULL) {
    mtx_unlock(vector->lock);
  }
  
  printLog(TRACE,
    "EXIT kvVectorSetEntry(vector=%p, index=%llu, key=%p, value=%p, type=%s) = {%p}\n",
    vector, llu(index), key, value, type->name, returnValue);
  return returnValue;
}

/// @fn VectorNode *vectorGetEntry(Vector *vector, u64 index)
///
/// @brief Get the node at the specified index of the vector.
///
/// @param vector The Vector to retrieve from.
/// @param index The index of the Vector to retrieve.
///
/// @return Returns a pointer to the specified node on success, NULL on failure.
VectorNode *vectorGetEntry(Vector *vector, u64 index) {
  printLog(TRACE, "ENTER vectorGetEntry(vector=%p, index=%llu)\n",
    vector, llu(index));
  
  if (vector == NULL) {
    printLog(ERR, "vector is NULL.\n");
    printLog(TRACE, "EXIT vectorGet(vector=%p, index=%llu) = {%p}\n",
      vector, llu(index), (void*) NULL);
    return NULL;
  }
  
  VectorNode *returnValue = NULL;
  
  if ((vector->lock != NULL) && (mtx_lock(vector->lock) != thrd_success)) {
    printLog(WARN, "Could not lock vector mutex.\n");
  }
  
  if (index < vector->arraySize) {
    returnValue = &vector->array[index];
    if (returnValue->allocated == false) {
      returnValue = NULL;
    }
  }
  
  if (vector->lock != NULL) {
    mtx_unlock(vector->lock);
  }
  
  printLog(TRACE, "EXIT vectorGetEntry(vector=%p, index=%llu) = {%p}\n",
    vector, llu(index), returnValue);
  return returnValue;
}

/// @fn void* vectorGetValue(Vector *vector, u64 index)
///
/// @brief Get the value of a VectorNode, if any.
///
/// @param vector The Vector to retrieve from.
/// @param index The index of the Vector to retrieve.
///
/// @return Returns a pointer to the specified node on success, NULL on failure.
void* vectorGetValue(Vector *vector, u64 index) {
  printLog(TRACE, "ENTER vectorGetValue(vector=%p, index=%llu)\n",
    vector, llu(index));
  
  void *returnValue = NULL;
  if (vector == NULL) {
    printLog(DEBUG,  "NULL vector provided.\n");
    printLog(TRACE, "EXIT vectorGetValue(vector=%p, index=%llu) = {%p}\n",
      vector, llu(index), returnValue);
    return returnValue;
  }
  
  if ((vector->lock != NULL) && (mtx_lock(vector->lock) != thrd_success)) {
    printLog(WARN, "Could not lock vector mutex.\n");
  }
  
  if ((vector->arraySize > index) && (vector->array[index].allocated)) {
    returnValue = (void*) vector->array[index].value;
  }
  
  if (vector->lock != NULL) {
    mtx_unlock(vector->lock);
  }
  
  printLog(TRACE, "EXIT vectorGetValue(vector=%p, index=%llu) = {%p}\n",
    vector, llu(index), returnValue);
  return returnValue;
}

/// @fn VectorNode* kvVectorGetEntry(Vector *vector, const volatile void *key)
///
/// @brief Get a node from a Vector given its key.  This performs a linear
/// search through the Vector.
///
/// @param vector A pointer to a previously-created Vector object.
/// @param key A pointer to a key to search for.
///
/// @return Returns a pointer to the first VectorNode with the provided key on
/// success, NULL on failure.
VectorNode* kvVectorGetEntry(Vector *vector, const volatile void *key) {
  SCOPE_ENTER("vector=%p, key=%p", vector, key);
  
  VectorNode *returnValue = (VectorNode*) listGet((List*) vector, key);
  
  SCOPE_EXIT("vector=%p, key=%p", "%p", vector, key, returnValue);
  return returnValue;
}

/// @fn void* kvVectorGetValue(Vector *vector, const volatile void *key)
///
/// @brief Get the value from a VectorNode given its key.  This performs a
/// linear search through the Vector.
///
/// @param vector A pointer to a previously-created Vector object.
/// @param key A pointer to a key to search for.
///
/// @return Returns a pointer to the value of the first VectorNode with the
/// provided key on success, NULL on failure.
void* kvVectorGetValue(Vector *vector, const volatile void *key) {
  SCOPE_ENTER("vector=%p, key=%p", vector, key);
  
  void *returnValue = NULL;
  VectorNode *node = (VectorNode*) listGet((List*) vector, key);
  if (node != NULL) {
    returnValue = (void*) node->value;
  }
  
  SCOPE_EXIT("vector=%p, key=%p", "%p", vector, key, returnValue);
  return returnValue;
}

/// @fn VectorNode* vectorFindPreviousAllocated(Vector *vector, u64 index)
///
/// @brief Find the vector node previous to the specified index that is marked
/// as allocated (if any).
///
/// @param vector A previously-created Vector object.
/// @param index The index to find the previous allocated node of.  The search
///   starts at the index prior to this (if any) and runs to the beginning of
///   the array.
///
/// @return Returns a pointer to the allocated node found on success,
/// NULL on failure.
VectorNode* vectorFindPreviousAllocated(Vector *vector, u64 index) {
  SCOPE_ENTER("vector=%p, index=%llu", vector, llu(index));
  
  VectorNode *returnValue = NULL;
  
  if (vector == NULL) {
    printLog(ERR, "vector is NULL.\n");
    SCOPE_EXIT("vector=%p, index=%llu", "%p", vector, llu(index), returnValue);
    return returnValue; // NULL
  }
  
  if ((vector->lock != NULL) && (mtx_lock(vector->lock) != thrd_success)) {
    printLog(WARN, "Could not lock vector mutex.\n");
  }
  
  if (index < vector->arraySize) {
    // Find the previously allocated node.
    VectorNode *array = vector->array;
    for (u64 i = 0; i < index; i++) {
      // We're guaranteed that index - i is never 0, so it's safe to subtract
      // 1 from the unsigned integers here.
      u64 allocatedCandidate = index - i - 1;
      if (array[allocatedCandidate].allocated) {
        returnValue = &array[allocatedCandidate];
        break;
      }
    }
  }
  
  if (vector->lock != NULL) {
    mtx_unlock(vector->lock);
  }
  
  SCOPE_EXIT("vector=%p, index=%llu", "%p", vector, llu(index), returnValue);
  return returnValue;
}

/// @fn VectorNode* vectorFindNextAllocated(Vector *vector, u64 index)
///
/// @brief Find the vector node previous to the specified index that is marked
/// as allocated (if any).
///
/// @param vector A previously-created Vector object.
/// @param index The index to find the previous allocated node of.  The search
///   starts at the index prior to this (if any) and runs to the beginning of
///   the array.
///
/// @return Returns a pointer to the allocated node found on success,
/// NULL on failure.
VectorNode* vectorFindNextAllocated(Vector *vector, u64 index) {
  SCOPE_ENTER("vector=%p, index=%llu", vector, llu(index));
  
  VectorNode *returnValue = NULL;
  
  if (vector == NULL) {
    printLog(ERR, "vector is NULL.\n");
    SCOPE_EXIT("vector=%p, index=%llu", "%p", vector, llu(index), returnValue);
    return returnValue; // NULL
  }
  
  if ((vector->lock != NULL) && (mtx_lock(vector->lock) != thrd_success)) {
    printLog(WARN, "Could not lock vector mutex.\n");
  }
  
  u64 i = index + 1;
  u64 arraySize = vector->arraySize;
  if (i < arraySize) {
    // Find the next allocated node.
    VectorNode *array = vector->array;
    for (; i < arraySize; i++) {
      if (array[i].allocated) {
        returnValue = &array[i];
        break;
      }
    }
  }
  
  if (vector->lock != NULL) {
    mtx_unlock(vector->lock);
  }
  
  SCOPE_EXIT("vector=%p, index=%llu", "%p", vector, llu(index), returnValue);
  return returnValue;
}

/// @fn i32 vectorRemove(Vector *vector, u64 index)
///
/// @brief Remove a specified node from the Vector.
///
/// @note This is an *EXPENSIVE* operation because everything after the removed
/// index has to be moved down, which involves multiple operations at each
/// index.  *DON'T* do it unless you have to.
///
/// @param vector The Vector to remove from.
/// @param index The index of the Vector to remove.
///
/// Returns 0 on success, -1 on failure.
i32 vectorRemove(Vector *vector, u64 index) {
  printLog(TRACE, "ENTER vectorRemove(vector=%p, index=%llu)\n",
    vector, llu(index));
  
  if (vector == NULL) {
    printLog(ERR, "vector is NULL.\n");
    printLog(TRACE, "EXIT vectorRemove(vector=%p, index=%llu) = {%d}\n",
      vector, llu(index), -1);
    return -1;
  }
  
  if ((vector->lock != NULL) && (mtx_lock(vector->lock) != thrd_success)) {
    printLog(WARN, "Could not lock vector mutex.\n");
  }
  
  u64 arraySize = vector->arraySize;
  if (index < arraySize) {
    VectorNode *array = vector->array;
    VectorNode *cur = &array[index];
    
    if (cur->allocated) {
      // Remove the data.
      if (vector->keyType != NULL) {
        vector->keyType->destroy(cur->key);
      }
      if (cur->type != NULL) {
        cur->type->destroy(cur->value);
      }
      cur->allocated = false;
    }
    
    // First, scoot everything down.
    // arraySize is guaranteed to be at least 1, so it's safe to decrement the
    // unsigned integer value here.
    arraySize--;
    for (u64 i = index; i < arraySize; i++) {
      cur = &array[i];
      VectorNode *next = &array[i + 1];
      *cur = *next;
    }
    
    // Clear the last index;
    array[arraySize].allocated = false;
    
    // Fix all the links.
    for (u64 i = index; i < arraySize; i++) {
      cur = &array[i];
      if (cur->allocated) {
        cur->prev = vectorFindPreviousAllocated(vector, i);
        if (cur->prev != NULL) {
          cur->prev->next = cur;
        }
        cur->next = vectorFindNextAllocated(vector, i);
        if (cur->next != NULL) {
          cur->next->prev = cur;
        }
      }
    }
    
    // Fix head and tail if needed.
    if (vector->size > 0) {
      vector->size--;
      if (vector->size > 0) {
        if (vector->array[0].allocated) {
          vector->head = &vector->array[0];
        } else {
          vector->head = vectorFindNextAllocated(vector, 0);
        }
        
        vector->tail = vectorFindPreviousAllocated(vector, arraySize);
      } else {
        vector->head = NULL;
        vector->tail = NULL;
      }
    }
  }
  
  if (vector->lock != NULL) {
    mtx_unlock(vector->lock);
  }
  
  printLog(TRACE, "EXIT vectorRemove(vector=%p, index=%llu) = {%d}\n",
    vector, llu(index), 0);
  return 0;
}

/// @fn Vector* vectorDestroy(Vector *vector)
///
/// @brief Destroy and deallocate all contents of a previously-allocated Vector.
///
/// @param vector The Vector to destroy.
///
/// @return This function returns no value.
Vector* vectorDestroy(Vector *vector) {
  printLog(TRACE, "ENTER vectorDestroy(vector=%p)\n", vector);
  
  Vector *returnValue = NULL;
  if (vector == NULL) {
    // Not an error, but nothing to do.
    printLog(TRACE, "EXIT vectorDestroy(vector=%p) = {%p}\n",
      vector, returnValue);
    return returnValue;
  }
  
  VectorNode *node = vector->head;
  TypeDescriptor *keyType = vector->keyType;
  if (keyType == NULL) {
    keyType = typePointerNoOwn;
  }
  while (node != NULL) {
    VectorNode *nextNode = node->next;
    
    keyType->destroy(node->key);
    if (node->type != NULL) {
      node->type->destroy(node->value);
    }
    node->allocated = false;
    
    node = nextNode;
  }
  
  if (vector->filePointer != NULL) {
    fclose(vector->filePointer); vector->filePointer = NULL;
  }
  
  if (vector->lock != NULL) {
    mtx_destroy(vector->lock);
  }
  vector->lock = (mtx_t*) pointerDestroy(vector->lock);
  vector->array = (VectorNode*) pointerDestroy(vector->array);
  
  vector = (Vector*) pointerDestroy(vector);
  
  printLog(TRACE, "EXIT vectorDestroy(vector=%p) = {%p}\n",
    vector, returnValue);
  return returnValue;
}

/// @fn Bytes vectorToXml_(const Vector *vector, const char *elementName, bool indent, ...)
///
/// @brief Convert a Vector to an XML string representation.
///
/// @param vector The Vector to convert to XML.
/// @param elementName The name of the root element this Vector will serve as.
/// @param indent Whether or not to indent the text output.
///
/// @return Returns a pointer to a C string with an XML representation of the
/// Vector on success, NULL on failure.
Bytes vectorToXml_(const Vector *vector, const char *elementName, bool indent, ...) {
  printLog(TRACE, "ENTER vectorToXml(vector=%p, elementName=\"%s\")\n", vector, elementName);
  
  Bytes returnValue = listToXml((List*) vector, elementName, indent);
  
  printLog(TRACE, "EXIT vectorToXml(vector=%p, elementName=\"%s\") = {%s}\n",
    vector, elementName, str(returnValue));
  return returnValue;
}

/// @fn int vectorCompare(Vector *vectorA, Vector *vectorB)
///
/// @brief Compare the contents of two Vectors.
///
/// @param vectorA The Vector on the left of the inequality.
/// @param vectorB The Vector on the right of the inequality.
///
/// @return Returns 0 if the two Vectors evaluate as equal, <0 if vectorA
/// evaluates as being logically less than vectorB, >0 if vectorA evaluates as
/// being logically greater than vectorB.
int vectorCompare(Vector *vectorA, Vector *vectorB) {
  printLog(TRACE, "ENTER vectorCompare(vectorA=%p, vectorB=%p)\n", vectorA, vectorB);
  
  int returnValue = listCompare((List*) vectorA, (List*) vectorB);
  
  printLog(TRACE, "EXIT vectorCompare(vectorA=%p, vectorB=%p) = {%d}\n", vectorA, vectorB, returnValue);
  return returnValue;
}

/// @fn Vector *vectorCopy(Vector *vector)
///
/// @brief Create a copy of a previously-allocated Vector.
///
/// @param vector The Vector to copy.
///
/// @return Returns a pointer to a new Vector, which is a copy of the provided
/// Vector, on success, NULL on failure.
Vector *vectorCopy(Vector *vector) {
  printLog(TRACE, "ENTER vectorCopy(vector=%p)\n", vector);
  if (vector == NULL) {
    printLog(ERR, "vector is NULL\n");
    printLog(TRACE, "EXIT vectorCopy(vector=%p) = {NULL}\n", vector);
    return NULL;
  }
  
  Vector *returnValue = (Vector*) malloc(sizeof(Vector));
  if (returnValue == NULL) {
    LOG_MALLOC_FAILURE();
    printLog(NEVER, "EXIT vectorCopy(vector=%p) = {%p}\n", vector, returnValue);
    return returnValue; // NULL
  }
  if (vector->lock != NULL) {
    // Have to use calloc here to avoid tripping over pthread's check for an
    // initialized mutex inside the init function...
    returnValue->lock = (mtx_t*) calloc(1, sizeof(mtx_t));
    if (returnValue->lock == NULL) {
      LOG_MALLOC_FAILURE();
      returnValue = (Vector*) pointerDestroy(returnValue);
      printLog(NEVER, "EXIT vectorCopy(vector=%p) = {%p}\n", vector, returnValue);
      return returnValue; // NULL
    }
    if (mtx_init(returnValue->lock, mtx_plain | mtx_recursive) != thrd_success) {
      printLog(ERR, "Could not initialize returnValue->lock mutex.\n");
      returnValue->lock = (mtx_t*) pointerDestroy(returnValue->lock);
      returnValue = (Vector*) pointerDestroy(returnValue);
      printLog(NEVER, "EXIT vectorCopy(vector=%p) = {%p}\n", vector, returnValue);
      return returnValue; // NULL
    }
  } else {
    returnValue->lock = NULL;
  }
  returnValue->arraySize = 0;
  
  u64 arraySize = vector->arraySize;
  VectorNode *returnValueArray = NULL;
  TypeDescriptor *keyType = vector->keyType;
  returnValue->keyType = keyType;
  if (arraySize > 0) {
    returnValueArray = (VectorNode*) malloc(arraySize * sizeof(VectorNode));
    VectorNode *vectorArray = vector->array;
    returnValue->arraySize = arraySize;
    returnValue->array = returnValueArray;
    
    // First, copy all the data.
    for (u64 i = 0; i < arraySize; i++) {
      if (vectorArray[i].allocated) {
        TypeDescriptor *valueType = vectorArray[i].type;
        returnValueArray[i].value = valueType->copy(vectorArray[i].value);
        returnValueArray[i].key = keyType->copy(vectorArray[i].key);
        returnValueArray[i].type = valueType;
        // byteOffset is currently unused, so skip it.
        returnValueArray[i].allocated = true;
      } else {
        returnValueArray[i].allocated = false;
      }
    }
    
    // Next, fix all the links.
    for (u64 i = 0; i < arraySize; i++) {
      if (vectorArray[i].allocated) {
        returnValueArray[i].next = vectorFindNextAllocated(returnValue, i);
        returnValueArray[i].prev
          = vectorFindPreviousAllocated(returnValue, i);
      }
    }
    
    if (returnValueArray[0].allocated) {
      returnValue->head = &returnValueArray[0];
    } else {
      returnValue->head = vectorFindNextAllocated(returnValue, 0);
    }
    returnValue->tail = vectorFindPreviousAllocated(returnValue, arraySize - 1);
  } else {
    returnValue->arraySize = 0;
    returnValue->array = NULL;
    returnValue->head = NULL;
    returnValue->tail = NULL;
  }
  
  returnValue->size = vector->size;
  returnValue->filePointer = NULL;
  
  printLog(TRACE, "EXIT vectorCopy(vector=%p) = {%p}\n", vector, returnValue);
  return returnValue;
}

/// @var _sortType
///
/// @brief The thread-specific storage that holds a pointer to a TypeDescriptor
/// that describes the keys of a vector for a sort operation.
static ZEROINIT(tss_t _sortType);

/// @var _sortOrder
/// @brief The thread-specific storage holding the order to sort in.
/// 1 = Ascending, -1 = Descending.
static ZEROINIT(tss_t _sortOrder);

/// @var _sortMetadataSetup
///
/// @brief A once_flag variable to guarantee that setupVectorSortMetadata is only
/// called once per program execution.
static once_flag _sortMetadataSetup = ONCE_FLAG_INIT;

/// @fn void setupVectorSortMetadata(void)
///
/// @brief Setup the thread-specific storage for the sort operation variables.
///
/// @return This function returns no value.
void setupVectorSortMetadata(void) {
  int status = tss_create(&_sortType, NULL);
  if (status != thrd_success) {
    fprintf(stderr, "Could not initialze _sortType thread-specific storage.\n");
  }
  
  status = tss_create(&_sortOrder, NULL);
  if (status != thrd_success) {
    fprintf(stderr, "Could not initialze _sortOrder thread-specific storage.\n");
  }
}

/// @fn static int vectorNodeCompare(const void *nodeAPointer, const void *nodeBPointer)
///
/// @brief Compare two nodes of a Vector.
///
/// @note This has to be passed to qsort as its __compar_fn_t parameter, so the
/// function signature is dictated by that typedef.
///
/// @param nodeAPointer A pointer to a node in a vector.
/// @param nodeBPointer A pointer to a node in the same vector as nodeAPointer.
///
/// @return If sortOrder is 1, returns a value less than 0 if the key of nodeA
/// is less than the key of nodeB, 0 if the key of nodeA is equal to the key of
/// nodeB, a value greater than 0 if the key of nodeA is greater than the key of
/// nodeB.  If sortOrder is -1, the return values are inverted.
int vectorNodeCompare(const void *nodeAPointer, const void *nodeBPointer) {
  printLog(FLOOD, "ENTER vectorNodeCompare(nodeAPointer=%p, nodeBPointer=%p)\n",
    nodeAPointer, nodeBPointer);
  VectorNode *nodeA = *((VectorNode**) nodeAPointer);
  VectorNode *nodeB = *((VectorNode**) nodeBPointer);
  
  TypeDescriptor *sortType = (TypeDescriptor*) tss_get(_sortType);
  i32 *sortOrder = (i32*) tss_get(_sortOrder);
  
  if ((sortType == NULL) || (sortOrder == NULL)) {
    printLog(ERR, "sortType or sortOrder not defined.\n");
    printLog(FLOOD,
      "EXIT vectorNodeCompare(nodeAPointer=%p, nodeBPointer=%p) = {%d}\n",
      nodeAPointer, nodeBPointer, 0);
    return 0;
  }
  
  int returnValue = (*sortOrder) * sortType->compare(nodeA->key, nodeB->key);
  
  printLog(FLOOD, "EXIT vectorNodeCompare(nodeAPointer=%p, nodeBPointer=%p) = {%d}\n",
    nodeAPointer, nodeBPointer, returnValue);
  return returnValue;
}

/// @fn VectorNode **vectorSort(Vector *vector, i32 order)
///
/// @brief Sort the contents of a vector.
///
/// @param vector The Vector to sort.
/// @param order The sort order to use.  1 = Ascending, -1 = Descending.
///
/// @return Returns a pointer to a sorted array of VectorNodes on success,
/// NULL on failure.  The contents of the Vector provided are not modified.
VectorNode **vectorSort(Vector *vector, i32 order) {
  printLog(TRACE, "ENTER vectorSort(vector=%p, order=%d)\n", vector, order);
  call_once(&_sortMetadataSetup, setupVectorSortMetadata);
  
  VectorNode **returnValue = NULL;
  
  if ((vector == NULL) || (vector->array == NULL)) {
    printLog(ERR, "vector or vector->array is NULL.\n");
    printLog(TRACE, "EXIT vectorSort(vector=%p, order=%d) = {%p}\n",
      vector, order, returnValue);
    return returnValue; // NULL
  }
  
  if ((vector->lock != NULL) && (mtx_lock(vector->lock) != thrd_success)) {
    printLog(WARN, "Could not lock vector mutex.\n");
  }
  
  returnValue = (VectorNode**) malloc(vector->size * sizeof(VectorNode*));
  if (returnValue == NULL) {
    LOG_MALLOC_FAILURE();
    printLog(NEVER, "EXIT vectorSort(vector=%p, order=%d) = {%p}\n",
      vector, order, returnValue);
    return returnValue; // NULL
  }
  u64 returnValueIndex = 0;
  // Traversing from head to tail will give us only the allocated elements,
  // which is what we want.  Doing it this way will be faster than evaluating
  // every element in the array and determining if it's allocated since all the
  // nodes in this list are guaranteed to be allocated.
  for (VectorNode *cur = vector->head; cur != NULL; cur = cur->next) {
    returnValue[returnValueIndex++] = cur;
  }
  tss_set(_sortType, vector->keyType);
  tss_set(_sortOrder, &order);
  qsort(returnValue, vector->size, sizeof(VectorNode*), vectorNodeCompare);
  
  if (vector->lock != NULL) {
    mtx_unlock(vector->lock);
  }
  
  return returnValue;
}

// jsonToKvVector implementation from generic macro.
JSON_TO_DATA_STRUCTURE(KvVector, kvVector)

/// @fn Vector *vectorFromByteArray_(const volatile void *array, u64 *length, bool inPlaceData, bool disableThreadSafety, ...)
///
/// @brief Convert a properly-formatted byte array into a vector.
///
/// @param array The array of bytes to convert.
/// @param length As an input, this is the number of bytes in array.  As an
///   output, this is the number of bytes consumed by this call.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned list.
///
/// @return Returns a pointer to a Vector on success, NULL on failure.
Vector* vectorFromByteArray_(const volatile void *array, u64 *length, bool inPlaceData, bool disableThreadSafety, ...) {
  char *byteArray = (char*) array;
  Vector *vector = NULL;
  u64 index = 0;
  i16 typeIndex = 0, keyTypeIndex = 0;
  printLog(TRACE,
    "ENTER vectorFromByteArray(array=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    array, length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  u64 size = 0;
  TypeDescriptor *keyType = NULL, *keyTypeNoCopy = NULL;
  
  if (array == NULL) {
    printLog(ERR, "array parameter is NULL.\n");
    printLog(TRACE,
      "EXIT vectorFromByteArray(array=NULL, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {NULL}\n",
      length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
    return NULL;
  } else if (length == NULL) {
    printLog(ERR, "length parameter is NULL.\n");
    printLog(TRACE,
      "EXIT vectorFromByteArray(array=%p, length=NULL, inPlaceData=%s, disableThreadSafety=%s) = {NULL}\n",
      array, boolNames[inPlaceData], boolNames[disableThreadSafety]);
    return NULL;
  }
  
  // Length check
  u64 arrayLength = *length;
  if (arrayLength < sizeof(DsMarker) + sizeof(DsVersion)
    + sizeof(typeIndex) + sizeof(size)
  ) {
    printLog(ERR, "Insufficient data provided.\n");
    printLog(ERR, "If this input came from this library, please "
      "report this as a bug.\n");
    return NULL;
  }
  *length = 0;
  
  // Metadata check
  u16 dsMarker = *((u16*) &byteArray[index]);
  littleEndianToHost(&dsMarker, sizeof(dsMarker));
  if (dsMarker != DsMarker) {
    printLog(ERR, "Unknown byte array.\n");
    printLog(ERR, "If this input came from this library, please "
      "report this as a bug.\n");
    return NULL;
  }
  index += sizeof(u16);
  
  u32 dsVersion = *((u32*) &byteArray[index]);
  littleEndianToHost(&dsVersion, sizeof(dsVersion));
  if (dsVersion != 10) {
    printLog(ERR, "Don't know how to parse version %u of input byte array.\n",
      dsVersion);
    printLog(ERR, "If this input came from this library, please "
      "report this as a bug.\n");
    return NULL;
  }
  index += sizeof(u32);
  
  keyTypeIndex = *((i16*) &byteArray[index]);
  littleEndianToHost(&keyTypeIndex, sizeof(i16));
  index += sizeof(i16);
  if (keyTypeIndex < 1) {
    // Index is not valid.
    *length = index;
    printLog(ERR, "Improperly formatted byte array.  Cannot create vector.\n");
    printLog(TRACE,
      "EXIT vectorFromByteArray(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], vector);
    return NULL;
  }
  keyType = getTypeDescriptorFromIndex(keyTypeIndex);
  keyTypeNoCopy = getTypeDescriptorFromIndex(keyTypeIndex + 1);
  
  size = *((u64*) &byteArray[index]);
  littleEndianToHost(&size, sizeof(size));
  index += sizeof(size);
  vector = vectorCreate(keyTypeNoCopy, disableThreadSafety, size);
  if (vector == NULL) {
    LOG_MALLOC_FAILURE();
    printLog(NEVER,
      "EXIT vectorFromByteArray(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], vector);
    return NULL;
  }
  
  // Complex data types (which will have type indexes greater than or equal
  // to that of typeList) will need to be handled slightly differently than
  // primitives in the case that inPlaceData is true, so grab the index for
  // typeList now so that we can compare it later.
  i64 listIndex = getIndexFromTypeDescriptor(typeList);
  
  VectorNode *node = NULL;
  while ((index < arrayLength) && (vector->size < size)) {
    void *key = NULL, *value = NULL;
    u64 keySize = 0, valueSize = 0;
    TypeDescriptor *valueType = NULL, *valueTypeNoCopy = NULL;
    
    typeIndex = *((i16*) &byteArray[index]);
    littleEndianToHost(&typeIndex, sizeof(i16));
    if (typeIndex < 1) {
      // Index is not valid.
      *length = index;
      printLog(ERR,
        "Improperly formatted byte array.  Cannot continue processing\n");
      printLog(TRACE,
        "EXIT vectorFromByteArray(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
        array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], vector);
      if (inPlaceData) {
        // Optimize for this case.
        if (keyTypeIndex >= listIndex) {
          // See notes at the bottom of this function about this logic.
          vector->keyType = keyType;
        }
      } else {
        vector->keyType = keyType;
      }
      return vector;
    }
    valueType = getTypeDescriptorFromIndex(typeIndex);
    valueTypeNoCopy = getTypeDescriptorFromIndex(typeIndex + 1);
    index += sizeof(i16);
    valueSize = arrayLength - index;
    
    value = valueType->fromByteArray(&byteArray[index], &valueSize, inPlaceData, disableThreadSafety);
    index += valueSize;
    if (value == NULL) {
      *length = index;
      printLog(ERR, "NULL value detected.  Cannot process.\n");
      printLog(TRACE,
        "EXIT vectorFromByteArray(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
        array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], vector);
      if (inPlaceData) {
        // Optimize for this case.
        if (keyTypeIndex >= listIndex) {
          // See notes at the bottom of this function about this logic.
          vector->keyType = keyType;
        }
      } else {
        vector->keyType = keyType;
      }
      return vector;
    }
    
    keySize = arrayLength - index;
    key = keyType->fromByteArray(&byteArray[index], &keySize, inPlaceData, disableThreadSafety);
    index += keySize;
    if (key == NULL) {
      *length = index;
      printLog(ERR, "NULL key detected.  Cannot process.\n");
      printLog(TRACE,
        "EXIT vectorFromByteArray(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
        array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], vector);
      if (inPlaceData) {
        // Optimize for this case.
        if (keyTypeIndex >= listIndex) {
          // See notes at the bottom of this function about this logic.
          vector->keyType = keyType;
        }
      } else {
        vector->keyType = keyType;
      }
      return vector;
    }
    
    node = kvVectorAddEntry(vector, key, value, valueTypeNoCopy);
    if (node != NULL) {
      if (inPlaceData) {
        // Optimize for this case.
        if (typeIndex >= listIndex) {
          // Memory has to be allocated to hold the top-level structures of
          // complex data.  Only the primitives in the byte arrays involve no
          // memory allocations at all.  So, for complex data, we need to set
          // the node's type back to the base value type so that the destructor
          // is called.  The destructors for all the primitives will be omitted.
          node->type = valueType;
        }
      } else {
        node->type = valueType;
      }
    } else {
      printLog(ERR, "Failed to add node to vector.\n");
    }
  }
  if (vector->size < size) {
    printLog(ERR, "Expected %llu entries, but only found %llu.\n",
      llu(size), llu(vector->size));
    printLog(ERR, "If this input came from this library, please "
      "report this as a bug.\n");
    if (node != NULL) {
      printLog(ERR, "Last-added node was a %s type.\n", node->type->name);
    } // else The failure to add the node was printed above.
  }
  
  *length = index;
  if (inPlaceData) {
    // Optimize for this case.
    if (keyTypeIndex >= listIndex) {
      // See note above for value types.  Not sure why anyone would want to have
      // a comlex data type as a key, but it is possible, so cover the case.
      vector->keyType = keyType;
    }
  } else {
    vector->keyType = keyType;
  }
  
  printLog(TRACE,
    "EXIT vectorFromByteArray(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], vector);
  return vector;
}

/// @fn Bytes vectorToJson(const Vector *vector)
///
/// @brief Converts a Vector to a JSON-formatted string.  This function will
///   always return an allocated string, even if it's a zero-length (one null
///   byte) string.
///
/// @param vector is the Vector to convert.
///
/// @return Returns a JSON-formatted Bytes object representation of the vector.
Bytes vectorToJson(const Vector *vector) {
  printLog(TRACE, "ENTER vectorToJson(vector=%p)\n", vector);
  
  Bytes returnValue = NULL;
  VectorNode *node = NULL;
  
  if (vector == NULL) {
    printLog(ERR, "Vector provided was NULL.\n");
    bytesAllocate(&returnValue, 0);
    
    printLog(TRACE, "EXIT vectorToJson(vector=%p) = {%s}\n", vector, returnValue);
    return returnValue;
  }
  
  if ((vector->lock != NULL) && (mtx_lock(vector->lock) != thrd_success)) {
    printLog(WARN, "Could not lock vector mutex.\n");
  }
  
  int listTypeIndex = getIndexFromTypeDescriptor(typeList);
  bytesAddStr(&returnValue, "[\n");
  for (node = vector->head; node != NULL; node = node->next) {
    if (getIndexFromTypeDescriptor(node->type) < listTypeIndex) {
      // Append end of key, start of value.
      bytesAddStr(&returnValue, "  ");
      if ((node->type == typeString) || (node->type == typeStringNoCopy)
        || (node->type == typeBytes) || (node->type == typeBytesNoCopy)
      ) {
        bytesAddStr(&returnValue, "\"");
      }
      char *valueString = node->type->toString(node->value);
      bytesAddStr(&returnValue, valueString);
      valueString = stringDestroy(valueString);
      if ((node->type == typeString) || (node->type == typeStringNoCopy)
        || (node->type == typeBytes) || (node->type == typeBytesNoCopy)
      ) {
        bytesAddStr(&returnValue, "\"");
      }
    } else if ((node->type == typePointer) && (node->value == NULL)) {
      // NULL value.
      bytesAddStr(&returnValue, "  null");
    } else if (node->type == typeVector) {
      // Value's type is a vector data structure, not a primitive.
      Bytes valueString = vectorToJson((Vector*) node->value);
      char *indentedValue = indentText(str(valueString), 2);
      valueString = bytesDestroy(valueString);
      bytesAddStr(&returnValue, indentedValue);
      indentedValue = stringDestroy(indentedValue);
    } else {
      // Value's type is a non-vector data structure, not a primitive.
      Bytes valueString = listToJson((List*) node->value);
      char *indentedValue = indentText(str(valueString), 2);
      valueString = bytesDestroy(valueString);
      bytesAddStr(&returnValue, indentedValue);
      indentedValue = stringDestroy(indentedValue);
    }
    
    if (node->next != NULL) {
      // End of the vector
      bytesAddStr(&returnValue, ",\n");
    }
  }
  bytesAddStr(&returnValue, "\n]");
  
  if (vector->lock != NULL) {
    mtx_unlock(vector->lock);
  }
  
  printLog(TRACE, "EXIT vectorToJson(vector=%p) = {%s}\n", vector, returnValue);
  return returnValue;
}

/// @fn Vector* jsonToVector(const char *jsonText, long long int *position)
///
/// @brief Converts a JSON-formatted string to a list.
///
/// @param jsonText The text to convert.
/// @param position A pointer to the current byte postion within the jsonText.
///
/// @return Returns a pointer to a new Vector on success, NULL on failure.
Vector* jsonToVector(const char *jsonText, long long int *position) {
  printLog(TRACE, "ENTER jsonToVector(jsonText=\"%s\", position=%p)\n",
    (jsonText != NULL) ? jsonText : "NULL", position);
  Vector *returnValue = NULL;
  
  if (jsonText == NULL) {
    printLog(ERR, "jsonText parameter is NULL.\n");
    printLog(TRACE, "EXIT jsonToVector(jsonText=NULL, position=%p) = {NULL}\n",
      position);
    return NULL;
  } else if (position == NULL) {
    printLog(ERR, "position parameter is NULL.\n");
    printLog(TRACE,
      "EXIT jsonToVector(jsonText=\"%s\", position=NULL) = {NULL}\n",
      jsonText);
  }
  
  const char *charAt
    = &(jsonText[*position + strspn(&jsonText[*position], " \t\r\n")]);
  if (*charAt != '[') {
    printLog(ERR, "No opening bracket in jsonText.  Malformed JSON input.\n");
    printLog(TRACE,
      "EXIT jsonToVector(jsonText=\"%s\", position=%lld) = {NULL}\n",
      jsonText, lli(*position));
    return NULL;
  }
  
  returnValue = vectorCreate(typeString);
  int i = 0;
  
  *position += ((long long int) ((intptr_t) charAt))
    - ((long long int) ((intptr_t) &jsonText[*position]));
  (*position)++;
  while ((*position >= 0) && (jsonText[*position] != '\0')) {
    *position += strspn(&jsonText[*position], " \t\r\n");
    char charAtPosition = jsonText[*position];
    if (charAtPosition == ']') {
      // End of vector.
      (*position)++;
      break;
    }
    
    if ((charAtPosition != '"') && (charAtPosition != '{')
      && (charAtPosition != '[') && !stringIsNumber(&jsonText[*position])
      && !stringIsBoolean(&jsonText[*position])
      && (strncmp(&jsonText[*position], "null", 4) != 0)
    ) {
      printLog(ERR, "Malformed JSON input.\n");
      returnValue = vectorDestroy(returnValue);
      printLog(TRACE,
        "EXIT jsonToVector(jsonText=\"%s\", position=%lld) = {NULL}\n", jsonText,
        lli(*position));
      return NULL;
    }
    if (charAtPosition == '"') {
      // Get the string between the quotes.
      Bytes stringValue = getBytesBetween(&jsonText[*position], "\"", "\"");
      vectorSetEntry(returnValue, i++, stringValue, typeString);
      *position += bytesLength(stringValue) + 2;
      stringValue = bytesDestroy(stringValue);
    } else if (stringIsNumber(&jsonText[*position])) {
      // Parse the number.
      char *endpos = NULL;
      if (stringIsInteger(&jsonText[*position])) {
        i64 longLongValue = (i64) strtoll(&jsonText[*position], &endpos, 10);
        vectorSetEntry(returnValue, i++, &longLongValue, typeI64);
      } else { // stringIsFloat(&jsonText[*position])
        double doubleValue = strtod(&jsonText[*position], &endpos);
        vectorSetEntry(returnValue, i++, &doubleValue, typeDouble);
      }
      *position
        += ((long long int) ((intptr_t) endpos))
        - ((long long int) ((intptr_t) &jsonText[*position]));
    } else if (stringIsBoolean(&jsonText[*position])) {
      // Parse the boolean.
      char *endpos = NULL;
      bool boolValue = strtobool(&jsonText[*position], &endpos);
      vectorSetEntry(returnValue, i++, &boolValue, typeBool);
      *position
        += ((long long int) ((intptr_t) endpos))
        - ((long long int) ((intptr_t) &jsonText[*position]));
    } else if (charAtPosition == '{') {
      // Parse the key-value data structure (list).
      HashTable *dataStructure = jsonToHashTable(jsonText, position);
      if (dataStructure == NULL) {
        printLog(ERR, "Malformed JSON input.\n");
        returnValue = vectorDestroy(returnValue);
        printLog(TRACE,
          "EXIT jsonToVector(jsonText=\"%s\", position=%lld) = {NULL}\n",
          jsonText, lli(*position));
        return returnValue;
      }
      VectorNode *node = vectorSetEntry(returnValue, i++, dataStructure,
        typeHashTableNoCopy);
      node->type = typeHashTable;
      // position is automatically updated in this case.
    } else if (charAtPosition == '[') {
      // Parse the vector.
      Vector *vector = jsonToVector(jsonText, position);
      if (vector == NULL) {
        printLog(ERR, "Malformed JSON input.\n");
        returnValue = vectorDestroy(returnValue);
        printLog(TRACE,
          "EXIT jsonToVector(jsonText=\"%s\", position=%lld) = {NULL}\n",
          jsonText, lli(*position));
        return returnValue;
      }
      VectorNode *node = vectorSetEntry(returnValue, i++, vector, typeVectorNoCopy);
      node->type = typeVector;
      // position is automatically updated in this case.
    } else { // (strncmp(&jsonText[*position], "null", 4) != 0)
      vectorSetEntry(returnValue, i++, NULL, typePointer);
      *position += 4;
    }
    *position += strspn(&jsonText[*position], " \t\r\n");;
    if (jsonText[*position] == ',') {
      (*position)++;
    }
  }
  
  printLog(TRACE, "EXIT jsonToVector(jsonText=\"%s\", position=%lld) = {%p}\n",
    jsonText, lli(*position), returnValue);
  return returnValue;
}

/// @fn i32 vectorClear(Vector *vector)
///
/// @brief Clear and deallocate the contents of a previously-allocated Vector,
/// but do not deallocate the Vector object itself.
///
/// @param vector The Vector to clear.
///
/// @return This function returns no value.
i32 vectorClear(Vector *vector) {
  printLog(TRACE, "ENTER vectorClear(vector=%p)\n", vector);
  
  i32 returnValue = 0;
  if (vector == NULL) {
    printLog(ERR, "NULL vector provided.\n");
    printLog(TRACE, "EXIT vectorClear(vector=NULL) = {-1}\n");
    return -1;
  }
  
  if ((vector->lock != NULL) && (mtx_lock(vector->lock) != thrd_success)) {
    printLog(WARN, "Could not lock vector mutex.\n");
  }
  
  VectorNode *node = vector->head;
  TypeDescriptor *keyType = vector->keyType;
  if (keyType == NULL) {
    keyType = typePointerNoOwn;
  }
  while (node != NULL) {
    VectorNode *nextNode = node->next;
    
    keyType->destroy(node->key);
    if (node->type != NULL) {
      node->type->destroy(node->value);
    }
    node->allocated = false;
    
    node = nextNode;
  }
  
  vector->size = 0;
  vector->head = NULL;
  vector->tail = NULL;
  
  if (vector->filePointer != NULL) {
    fclose(vector->filePointer); vector->filePointer = NULL;
  }
  
  // Do *NOT* alter the storage of the array or change the arraySize.  The only
  // time we ever actually shrink the array is when we destroy the Vector.
  
  if (vector->lock != NULL) {
    mtx_unlock(vector->lock);
  }
  
  printLog(TRACE, "EXIT vectorClear(vector=%p) = {%d}\n", vector, returnValue);
  return returnValue;
}

/// @fn VectorNode* vectorGetIndex(Vector *vector, char *index)
///
/// @brief Get a VectorNode at the specified index of the vector.
///
/// @param vector A pointer to the Vector to get the VectorNode from.
/// @param index A pointer to a string describing the index to get in the form
///   "[N]", where N is a non-negative integer.
///
/// @return Returns a pointer to the VectorNode in the vector on success,
///   NULL on failure.
VectorNode* vectorGetIndex(Vector *vector, char *index) {
  printLog(TRACE, "ENTER vectorGetIndex(vector=%p, index=%p)\n",
    vector, index);
  
  if (vector == NULL) {
    printLog(ERR, "vector parameter is NULL.\n");
    printLog(TRACE, "EXIT vectorGetIndex(vector=NULL, index=%p) = {NULL}\n",
      index);
    return NULL;
  } else if (index == NULL) {
    printLog(ERR, "indexparameter is NULL.\n");
    printLog(TRACE, "EXIT vectorGetIndex(vector=%p, index=NULL) = {NULL}\n",
      vector);
    return NULL;
  }
  
  // Both parameters are valid.  Parse the index.
  if (*index != '[') {
    printLog(ERR, "Invaid index string \"%s\".\n", index);
    printLog(TRACE, "EXIT vectorGetIndex(vector=%p, index=\"%s\") = {NULL}\n",
      vector, index);
    return NULL;
  }
  
  Bytes indexString = getBytesBetween(index, "[", "]");
  if (!isInteger((char*) indexString)) {
    printLog(ERR, "Invalid index \"%s\".\n", (char*) indexString);
    indexString = bytesDestroy(indexString);
    printLog(TRACE, "EXIT vectorGetIndex(vector=%p, index=\"%s\") = {NULL}\n",
      vector, index);
    return NULL;
  }
  int indexValue = strtol((char*) indexString, NULL, 10);
  if (indexValue < 0) {
    printLog(ERR, "Invalid index %d.\n", indexValue);
    indexString = bytesDestroy(indexString);
    printLog(TRACE, "EXIT vectorGetIndex(vector=%p, index=\"%s\") = {NULL}\n",
      vector, index);
    return NULL;
  }
  VectorNode *node = vectorGetEntry(vector, indexValue);
  char *startOfNextIndex = index + bytesLength(indexString) + 2;
  if ((node != NULL) && (node->type == typeVector)
    && (*startOfNextIndex == '[')
  ) {
    // We have all the requirements to get the next level down.
    node = vectorGetIndex((Vector*) node->value, startOfNextIndex);
  } else if (((node != NULL) && (node->type == typeVector))
    || (*startOfNextIndex == '[')
  ) {
    // We have conflicting information.  The type of the node and the next part
    // of the index don't match.  Fail.
    node = NULL;
  }
  indexString = bytesDestroy(indexString);
  
  printLog(TRACE, "EXIT vectorGetIndex(vector=%p, index=\"%s\") = {%p}\n",
    vector, index, node);
  return node;
}

/// @var typeVector
///
/// @brief TypeDescriptor describing how libraries should interact with
///   vector data.
TypeDescriptor _typeVector = {
  .name          = "Vector",
  .xmlName       = NULL,
  .toString      = (char* (*)(const volatile void*)) listToString,
  .toBytes       = (Bytes (*)(const volatile void*)) listToBytes,
  .compare       = (int (*)(const volatile void*, const volatile void*)) listCompare,
  .create        = (void* (*)(const volatile void*, ...)) vectorCreate_,
  .copy          = (void* (*)(const volatile void*)) vectorCopy,
  .destroy       = (void* (*)(volatile void*)) vectorDestroy,
  .size          = listSize,
  .toByteArray   = (void* (*)(const volatile void*, u64*)) listToByteArray,
  .fromByteArray = (void* (*)(const volatile void*, u64*, bool, bool)) vectorFromByteArray_,
  .hashFunction  = NULL,
  .clear         = (i32 (*)(volatile void*)) vectorClear,
  .toXml         = (Bytes (*)(const volatile void*, const char *elementName, bool indent, ...)) vectorToXml_,
  .toJson        = (Bytes (*)(const volatile void*)) vectorToJson,
};
TypeDescriptor *typeVector = &_typeVector;

/// @var typeVectorNoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with
///   vector data that is not copied from its original source.
///
/// @details This exists because, by default, a copy of the input data is made
///   whenever a new data element is added to any data structure.  In some
///   situations, this is not desirable because the input serves no purpose
///   other than to be added to the data structure.  In such cases, this data
///   type may be specified to avoid the unnecessary copy.  The real
///   typeVector type can then be set after the data is added.
TypeDescriptor _typeVectorNoCopy = {
  .name          = "Vector",
  .xmlName       = NULL,
  .toString      = (char* (*)(const volatile void*)) listToString,
  .toBytes       = (Bytes (*)(const volatile void*)) listToBytes,
  .compare       = (int (*)(const volatile void*, const volatile void*)) listCompare,
  .create        = (void* (*)(const volatile void*, ...)) vectorCreate_,
  .copy          = (void* (*)(const volatile void*)) shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = listSize,
  .toByteArray   = (void* (*)(const volatile void*, u64*)) listToByteArray,
  .fromByteArray = (void* (*)(const volatile void*, u64*, bool, bool)) vectorFromByteArray_,
  .hashFunction  = NULL,
  .clear         = (i32 (*)(volatile void*)) vectorClear,
  .toXml         = (Bytes (*)(const volatile void*, const char *elementName, bool indent, ...)) vectorToXml_,
  .toJson        = (Bytes (*)(const volatile void*)) vectorToJson,
};
TypeDescriptor *typeVectorNoCopy = &_typeVectorNoCopy;

//// /// @def VECTOR_UNIT_TEST
//// ///
//// /// @brief Unit test functionality for vector data structure.
//// /// @details Implementing this as a macro instead of raw code allows this to
//// /// be skipped by the code coverage metrics.
//// ///
//// /// @return Returns true on success, false on failure.
//// #define VECTOR_UNIT_TEST
bool vectorUnitTest() { 
  Vector *vector = NULL, *vector2 = NULL; 
  VectorNode *node = NULL; 
  VectorNode **array= NULL; 
  u64 index = 4; 
  const char *value = "marklar"; 
  char *stringValue = NULL; 
  TypeDescriptor *type = NULL; 
  List *list = NULL; 
  u64 length = 0; 
   
  vector = vectorCreate(NULL); 
  if (vector != NULL) { 
    printLog(ERR, 
      "vectorCreate with NULL type succeeded and should not have.\n"); 
    return false; 
  } 
   
  node = vectorSetEntry(NULL, index, value, type); 
  if (node != NULL) { 
    printLog(ERR, "vectorSetEntry on NULL vector succeeded and should not have.\n"); 
    return false; 
  } 
   
  node = vectorGetEntry(NULL, index); 
  if (node != NULL) { 
    printLog(ERR, 
      "vectorGetEntry on NULL vector succeeded and should not have.\n"); 
    return false; 
  } 
   
  if (vectorRemove(NULL, index) == 0) { 
    printLog(ERR, 
      "vectorRemove on NULL vector succeeded and should not have.\n"); 
    return false; 
  } 
   
  node = (VectorNode*) vectorGetValue(NULL, index); 
  if (node != NULL) { 
    printLog(ERR, 
      "vectorGetValue on NULL vector succeeded and should not have.\n"); 
    return false; 
  } 
   
  vector = (Vector*) vectorDestroy(NULL); 
  if (vector != NULL) { 
    printLog(ERR, "Error detected in vectorDestroy.\n"); 
    return false; 
  } 
   
  stringValue = vectorToString(NULL); 
  if (stringValue == NULL) { 
    printLog(ERR, 
      "vectorToString on NULL vector did not succeed and should have.\n"); 
    return false; 
  } 
  if (strcmp(stringValue, "") != 0) { 
    printLog(ERR, "Expected empty string from vectorToString, got \"%s\"\n", stringValue); 
    return false; 
  } 
  stringValue = stringDestroy(stringValue); 
   
  list = vectorToList(NULL); 
  if (list != NULL) { 
    printLog(ERR, 
      "vectorToList on NULL vector succeeded and should not have.\n"); 
    return false; 
  } 
   
  Bytes bytesValue = vectorToXml(NULL, "root"); 
  if (bytesValue == NULL) { 
    printLog(ERR, 
      "vectorToXml on NULL vector yielded NULL pointer.\n"); 
    return false; 
  } 
  if (strcmp(str(bytesValue), "<root></root>") != 0) { 
    printLog(ERR, 
      "vectorToXml on NULL vector yielded \"%s\" instead of empty XML.", value); 
    return false; 
  } 
  bytesValue = bytesDestroy(bytesValue); 
   
  if (vectorCompare(NULL, NULL) != 0) { 
    printLog(ERR, "vectorCompare on two NULL vectors did not return 0.\n"); 
    return false; 
  } 
   
  vector2 = vectorCopy(NULL); 
  if (vector2 != NULL) { 
    printLog(ERR, "vectorCopy of NULL vector yielded non-NULL vector copy.\n"); 
    return false; 
  } 
   
  array = vectorSort(NULL, ASCENDING); 
  if (array != NULL) { 
    printLog(ERR, 
      "Ascending vectorSort of NULL vector yielded non-NULL VectorNode array.\n"); 
    return false; 
  } 
   
  array = vectorSort(NULL, DESCENDING); 
  if (array != NULL) { 
    printLog(ERR, 
      "Descending vectorSort of NULL vector yielded non-NULL VectorNode array.\n"); 
    return false; 
  } 
   
  vector = vectorCreate(typeString); 
  if (vector == NULL) { 
    printLog(ERR, 
      "vectorCreate with valid type failed and should not have.\n"); 
    return false; 
  } 
   
  node = vectorSetEntry(vector, index, value); 
  if (node == NULL) { 
    printLog(ERR, "vectorSetEntry on empty vector failed and should not have.\n"); 
    return false; 
  } 
  node = vectorSetEntry(vector, index + 1, NULL); 
  if (node == NULL) { 
    printLog(ERR, "vectorSetEntry on populated vector failed and should not have.\n"); 
    return false; 
  } 
   
  node = vectorGetEntry(vector, index); 
  if (node == NULL) { 
    printLog(ERR, 
      "vectorGetEntry on valid vector failed and should not have.\n"); 
    return false; 
  } 
  if (strcmp((char*) node->value, "marklar") != 0) { 
    printLog(ERR, "Expected marklar from vectorGetEntry, got \"%s\"\n", 
      (char*) node->value); 
    return false; 
  } 
   
  if (vectorRemove(vector, index) != 0) { 
    printLog(ERR, 
      "vectorRemove on valid vector failed and should not have.\n"); 
    return false; 
  } 
  if (vector->size != 1) { 
    printLog(ERR, "Expected vector of size 1 after vectorRemove.  Got size " 
      "%llu\n", llu(vector->size)); 
    return false; 
  } 
   
  node = (VectorNode*) vectorGetValue(vector, index); 
  if (node != NULL) { 
    printLog(ERR, 
      "vectorGetValue succeeded on missing index and should not have.\n"); 
    return false; 
  } 
 
  node = vectorSetEntry(vector, 2, "marklar", typeString); 
  if (node == NULL) { 
    printLog(ERR,  "Expected non-NULL from vectorSetEntry at index 2, got NULL.\n"); 
    return false; 
  } 
   
  stringValue = vectorToString(vector); 
  if (stringValue == NULL) { 
    printLog(ERR, 
      "vectorToString on (mostly) empty vector failed and should not have.\n"); 
    return false; 
  } 
  stringValue = stringDestroy(stringValue); 
   
  list = vectorToList(vector); 
  if (list == NULL) { 
    printLog(ERR, 
      "vectorToList on (mostly) empty vector failed and should not have.\n"); 
    return false; 
  } 
  listDestroy(list); 
   
  bytesValue = vectorToXml(vector, "root"); 
  if (bytesValue == NULL) { 
    printLog(ERR, 
      "vectorToXml on (mostly) empty vector failed and should not have.\n"); 
    return false; 
  } 
  bytesValue = bytesDestroy(bytesValue); 
   
  if (vectorCompare(vector, vector2) != 1) { 
    printLog(ERR, "vectorCompare on non-NULL and NULL vectors did not " 
      "return 1.\n"); 
    return false; 
  } 
   
  if (vectorCompare(vector2, vector) != -1) { 
    printLog(ERR, "vectorCompare on NULL and non-NULL vectors did not " 
      "return -1.\n"); 
    return false; 
  } 
   
  vector2 = vectorCopy(vector); 
  if (vector2 == NULL) { 
    printLog(ERR, "vectorCopy of NULL vector yielded non-NULL vector copy.\n"); 
    return false; 
  } 
   
  if (vectorCompare(vector, vector2) != 0) { 
    char *vectorString = vectorToString(vector);
    printLog(DEBUG, "vector = \"%s\".\n", vectorString);
    vectorString = stringDestroy(vectorString);
    vectorString = vectorToString(vector2);
    printLog(DEBUG, "vector2 = \"%s\".\n", vectorString);
    vectorString = stringDestroy(vectorString);
    printLog(ERR, "vectorCompare on two non-NULL vectors did not return 0.\n"); 
    return false; 
  } 
   
  array = vectorSort(vector, ASCENDING); 
  if (array == NULL) { 
    printLog(ERR, 
      "Ascending vectorSort of (mostly) empty vector yielded NULL VectorNode " 
      "array.\n"); 
    return false; 
  } 
  array = (VectorNode**) pointerDestroy(array); 
   
  array = vectorSort(vector, DESCENDING); 
  if (array == NULL) { 
    printLog(ERR, 
      "Descending vectorSort of (mostly) empty vector yielded NULL VectorNode " 
      "array.\n"); 
    return false; 
  } 
  array = (VectorNode**) pointerDestroy(array); 
   
  vector = (Vector*) vectorDestroy(vector); 
  if (vector != NULL) { 
    printLog(ERR, "Error detected in vectorDestroy with (mostly) empty " 
      "vector.\n"); 
    return false; 
  } 
   
  vector2 = (Vector*) vectorDestroy(vector2); 
  if (vector2 != NULL) { 
    printLog(ERR, "Error detected in vectorDestroy with (mostly) empty " 
      "vector.\n"); 
    return false; 
  } 
   
  vector = vectorCreate(typeI32); 
  /* Deliberately creating a vector where index 99 is skipped. */ 
  /* This will yield a Vector with an arraySize of 199 and a size of 198. */ 
  for (int i = 1; i < 100; i++) { 
    vectorSetEntry(vector, i + 99, &i); 
  } 
  for (int i = -1; i > -100; i--) { 
    vectorSetEntry(vector, i + 99, &i); 
  } 
  list = vectorToList(vector); 
  if (list == NULL) { 
    printLog(ERR, "vectorToList did not populate a list.\n"); 
    return false; 
  } else if (list->size != 198) { 
    printLog(ERR,
      "vectorToList returned a %llu element list, expected 198 elements.\n",
      llu(list->size)); 
    ZEROINIT(i32 array[199]); 
    for (ListNode *node = list->head; node != NULL; node = node->next) { 
      array[*((i32*) node->value) + 99]++; 
    } 
    printLog(ERR, "Not seen:\n"); 
    for (int i = 0; i < 199; i++) { 
      if ((array[i] == 0) && (i != 99)) { 
        printLog(ERR, "%d\n", i); 
      } 
    } 
    return false; 
  } 
  vector = (Vector*) vectorDestroy(vector); 
  listDestroy(list); list = NULL; 
   
  long long int jsonPosition = 0; 
  vector 
    = jsonToVector("[\"value1\",false,null]", 
    &jsonPosition); 
  if (vector == NULL) { 
    printLog(ERR, "Could not convert unformatted JSON to list.\n"); 
    return false; 
  } 
  vector = vectorDestroy(vector); 
  
  const char *jsonString = "{\n" 
    "  \"myVector1\": {\n" 
    "    \"key1\": \"value1\",\n" 
    "    \"key2\": \"value2\"\n" 
    "  },\n" 
    "  \"key3\": \"value3\",\n" 
    "  \"myVector2\": {\n" 
    "    \"key4\": \"value4\",\n" 
    "    \"key5\": \"value5\",\n" 
    "    \"key6\": \"value6\"\n" 
    "  },\n" 
    "  \"myVector3\": {\n" 
    "    \"myVector4\": {\n" 
    "      \"key7\": \"value7\",\n" 
    "      \"key8\": \"value8\"\n" 
    "    },\n" 
    "    \"key9\": \"value9\"\n" 
    "  }\n" 
    "}"; 
  long long int startPosition = 0; 
  vector = jsonToKvVector(jsonString, &startPosition); 
  if (vector == NULL) { 
    printLog(ERR, "jsonToKvVector returned NULL.\n"); 
    return false; 
  } 
  void *byteArray = vectorToByteArray(vector, &length); 
  vector = vectorDestroy(vector); 
  vector = vectorFromByteArray(byteArray, &length, true, true); 
  stringValue = vectorToString(vector); 
  printLog(INFO, "Vector: %s\n", stringValue); 
  stringValue = stringDestroy(stringValue); 
  stringValue = (char*) kvVectorGetValue(vector, "key3"); 
  if (stringValue == NULL) { 
    printLog(ERR, "Value for key3 was NULL.\n"); 
    return false; 
  } else if (strcmp(stringValue, "value3") != 0) { 
    printLog(ERR, "Expected \"value3\", got \"%s\".\n", stringValue); 
    return false; 
  } 
  vector2 = (Vector*) kvVectorGetValue(vector, "myVector1"); 
  if (vector2 == NULL) { 
    printLog(ERR, "Value for myVector1 was NULL.\n"); 
    return false; 
  } else if (kvVectorGetEntry(vector, "myVector1")->type != typeVector) { 
    printLog(ERR, "Expected myVector1 to be \"%s\", found \"%s\".\n", 
      typeVector->name, kvVectorGetEntry(vector, "myVector1")->type->name); 
    return false; 
  } 
  stringValue = (char*) kvVectorGetValue(vector2, "key1"); 
  if (stringValue == NULL) { 
    printLog(ERR, "Value for key1 was NULL.\n"); 
    return false; 
  } else if (strcmp(stringValue, "value1") != 0) { 
    printLog(ERR, "Expected \"value1\", got \"%s\".\n", stringValue); 
    return false; 
  } 
  stringValue = (char*) kvVectorGetValue(vector2, "key2"); 
  if (stringValue == NULL) { 
    printLog(ERR, "Value for key2 was NULL.\n"); 
    return false; 
  } else if (strcmp(stringValue, "value2") != 0) { 
    printLog(ERR, "Expected \"value2\", got \"%s\".\n", stringValue); 
    return false; 
  } 
  stringValue = (char*) kvVectorGetValue(vector2, "key6"); 
  vector2 = (Vector*) kvVectorGetValue(vector, "myVector2"); 
  if (vector2 == NULL) { 
    printLog(ERR, "Value for myVector2 was NULL.\n"); 
    return false; 
  } else if (kvVectorGetEntry(vector, "myVector2")->type != typeVector) { 
    printLog(ERR, "Expected myVector2 to be \"%s\", found \"%s\".\n", 
      typeVector->name, kvVectorGetEntry(vector, "myVector2")->type->name); 
    return false; 
  } 
  stringValue = (char*) kvVectorGetValue(vector2, "key4"); 
  if (stringValue == NULL) { 
    printLog(ERR, "Value for key4 was NULL.\n"); 
    return false; 
  } else if (strcmp(stringValue, "value4") != 0) { 
    printLog(ERR, "Expected \"value4\", got \"%s\".\n", stringValue); 
    return false; 
  } 
  stringValue = (char*) kvVectorGetValue(vector2, "key5"); 
  if (stringValue == NULL) { 
    printLog(ERR, "Value for key5 was NULL.\n"); 
    return false; 
  } else if (strcmp(stringValue, "value5") != 0) { 
    printLog(ERR, "Expected \"value5\", got \"%s\".\n", stringValue); 
    return false; 
  } 
  stringValue = (char*) kvVectorGetValue(vector2, "key6"); 
  if (stringValue == NULL) { 
    printLog(ERR, "Value for key6 was NULL.\n"); 
    return false; 
  } else if (strcmp(stringValue, "value6") != 0) { 
    printLog(ERR, "Expected \"value6\", got \"%s\".\n", stringValue); 
    return false; 
  } 
  vector2 = (Vector*) kvVectorGetValue(vector, "myVector3"); 
  if (vector2 == NULL) { 
    printLog(ERR, "Value for myVector3 was NULL.\n"); 
    return false; 
  } else if (kvVectorGetEntry(vector, "myVector3")->type != typeVector) { 
    printLog(ERR, "Expected myVector3 to be \"%s\", found \"%s\".\n", 
      typeVector->name, kvVectorGetEntry(vector, "myVector3")->type->name); 
    return false; 
  } 
  stringValue = (char*) kvVectorGetValue(vector2, "key9"); 
  if (stringValue == NULL) { 
    printLog(ERR, "Value for key9 was NULL.\n"); 
    return false; 
  } else if (strcmp(stringValue, "value9") != 0) { 
    printLog(ERR, "Expected \"value9\", got \"%s\".\n", stringValue); 
    return false; 
  } 
  if (kvVectorGetValue(vector2, "myVector4") == NULL) { 
    printLog(ERR, "Value for myVector4 was NULL.\n"); 
    return false; 
  } else if (kvVectorGetEntry(vector2, "myVector4")->type != typeVector) { 
    printLog(ERR, "Expected myVector4 to be \"%s\", found \"%s\".\n", 
      typeVector->name, kvVectorGetEntry(vector, "myVector4")->type->name); 
    return false; 
  } 
  vector2 = (Vector*) kvVectorGetValue(vector2, "myVector4"); 
  stringValue = (char*) kvVectorGetValue(vector2, "key7"); 
  if (stringValue == NULL) { 
    printLog(ERR, "Value for key7 was NULL.\n"); 
    return false; 
  } else if (strcmp(stringValue, "value7") != 0) { 
    printLog(ERR, "Expected \"value7\", got \"%s\".\n", stringValue); 
    return false; 
  } 
  stringValue = (char*) kvVectorGetValue(vector2, "key8"); 
  if (stringValue == NULL) { 
    printLog(ERR, "Value for key8 was NULL.\n"); 
    return false; 
  } else if (strcmp(stringValue, "value8") != 0) { 
    printLog(ERR, "Expected \"value8\", got \"%s\".\n", stringValue); 
    return false; 
  } 
  byteArray = pointerDestroy(byteArray); 
  vector = vectorDestroy(vector); 
  
  return true; 
}
//// VECTOR_UNIT_TEST

