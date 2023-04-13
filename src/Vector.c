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

#ifdef DS_LOGGING_ENABLED
#include "LoggingLib.h"
#else
#undef printLog
#define printLog(...) {}
#define logFile stderr
#endif

#include "StringLib.h"

/// @fn Vector *vectorCreate(TypeDescriptor *keyType)
///
/// @brief Create a vector with the specified key type.
///
/// @param keyType is the type of key to use for the vector.
///
/// @return Returns a newly-initialized vector on success, NULL on failure.
Vector *vectorCreate(TypeDescriptor *keyType) {
  if (keyType == NULL) {
    printLog(ERR, "keyType is NULL.\n");
    return NULL;
  }
  printLog(TRACE, "ENTER vectorCreate(keyType=%s)\n", keyType->name);
  
  Vector *returnValue = (Vector*) calloc(1, sizeof(Vector));
  if (returnValue == NULL) {
    printLog(ERR, "Could not allocate memory for vector.\n");
    return NULL;
  }
  
  // No reason to NULL-ify variables.
  returnValue->keyType = keyType;
  // The lock mtx_t member varialbe has to be zeored, so use calloc.
  returnValue->lock = (mtx_t*) calloc(1, sizeof(mtx_t));
  if (mtx_init(returnValue->lock, mtx_plain | mtx_recursive) != thrd_success) {
    printLog(ERR, "Could not initialize vector mutex lock.\n");
  }
  returnValue->array = NULL;
  
  printLog(TRACE, "EXIT vectorCreate(keyType=%s) = {%p}\n", keyType->name, returnValue);
  return returnValue;
}

/// @fn VectorNode *vectorSetEntry_(Vector *vector, u64 index, const volatile void *value, TypeDescriptor *type, ...)
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
VectorNode *vectorSetEntry_(Vector *vector, u64 index, const volatile void *value, TypeDescriptor *type, ...) {
  printLog(TRACE, "ENTER vectorSetEntry(vector=%p, index=%llu, value=%p, type=%p)\n",
    vector, llu(index), value, type);
  
  // Argument check.
  if (vector == NULL) {
    printLog(ERR, "vector is NULL.\n");
    printLog(TRACE,
      "EXIT vectorSetEntry(vector=%p, index=%llu, value=%p, type=%s) = {%p}\n",
      vector, llu(index), value, (type != NULL) ? type->name : "NULL",
      (void*) NULL);
    return NULL;
  }
  
  if (mtx_lock(vector->lock) != thrd_success) {
    printLog(WARN, "Could not lock vector mutex.\n");
  }
  
  if (type == NULL) {
    if (vector->size > index) {
      type = vector->array[index]->type;
    } else if (vector->tail != NULL) {
      type = vector->tail->type;
      printLog(DEBUG, "Defaulting to type of tail.\n");
    } else {
      type = vector->keyType;
      printLog(DEBUG, "Defaulting to type of key.\n");
    }
  }
  
  if (vector->size <= index) {
    VectorNode **array = (VectorNode**) realloc(
      vector->array, (index + 1) * sizeof(VectorNode*));
    if (array == NULL) {
      printLog(ERR, "Could not allocate memory for vector array.\n");
      printLog(TRACE,
        "EXIT vectorSetEntry(vector=%p, index=%llu, value=%p, type=%s) = {%p}\n",
        vector, llu(index), value, type->name, (void*) NULL);
      return NULL;
    }
    vector->array = array;
    for (u64 i = vector->size; i <= index; i++) {
      VectorNode *vectorNode = listAddBackEntry((List*) vector, NULL, NULL,
        typePointerNoCopy);
      vector->array[i] = vectorNode;
    }
  }
  
  VectorNode *returnValue = vector->array[index];
  vector->keyType->destroy(returnValue->key);
  returnValue->type->destroy(returnValue->value);
  
  returnValue->key = NULL;
  returnValue->value = type->copy(value);
  returnValue->type = type;
  
  mtx_unlock(vector->lock);
  
  printLog(TRACE,
    "EXIT vectorSetEntry(vector=%p, index=%llu, value=%p, type=%s) = {%p}\n",
    vector, llu(index), value, type->name, returnValue);
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
  
  if (mtx_lock(vector->lock) != thrd_success) {
    printLog(WARN, "Could not lock vector mutex.\n");
  }
  
  if (vector->size > index) {
    returnValue = vector->array[index];
  }
  
  mtx_unlock(vector->lock);
  
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
  VectorNode *node = vectorGetEntry(vector, index);
  
  if (node != NULL) {
    returnValue = (void*) node->value;
  }
  
  printLog(TRACE, "EXIT vectorGetValue(vector=%p, index=%llu) = {%p}\n",
    vector, llu(index), returnValue);
  return returnValue;
}

/// @fn i32 vectorRemove(Vector *vector, u64 index)
///
/// @brief Remove a specified node from the Vector.
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
  
  if (mtx_lock(vector->lock) != thrd_success) {
    printLog(WARN, "Could not lock vector mutex.\n");
  }
  
  if (vector->size > index) {
    VectorNode *node = vector->array[index];
    
    // Fix the links.
    if (node->prev != NULL) {
      node->prev->next = node->next;
    }
    if (node->next != NULL) {
      node->next->prev = node->prev;
    }
    
    // Fix the array.
    for (u64 i = index + 1; i < vector->size; i++) {
      vector->array[i - 1] = vector->array[i];
    }
    vector->size--;
    VectorNode **array
      = (VectorNode**) realloc(vector->array,
      vector->size * sizeof(VectorNode*));
    if (array != NULL) {
      vector->array = array;
    } else {
      // This should NEVER happen.  We're making the array smaller, not larger.
      // Checking anyway just to be sure.  The good news is that in this case,
      // vector->array should remain intact.
      printLog(WARN, "Could not shrink vector array.\n");
    }
    // Note that the vector itself is correct at this point.  We could actually
    // return here and finish the rest on another thread if we wanted to...
    
    // Deallocate the node.
    vector->keyType->destroy(node->key); node->key = NULL;
    node->type->destroy(node->value); node->value = NULL;
    node = (VectorNode*) pointerDestroy(node);
  }
  
  mtx_unlock(vector->lock);
  
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
  
  if (vector != NULL) {
    if (vector->array != NULL) {
      vector->array = (VectorNode**) pointerDestroy(vector->array);
    }
    returnValue = (Vector*) listDestroy((List*) vector); vector = NULL;
  }
  
  printLog(TRACE, "EXIT vectorDestroy(vector=%p) = {%p}\n", vector, returnValue);
  return returnValue;
}

/// @fn char *vectorToXml(Vector *vector, const char *elementName)
///
/// @brief Convert a Vector to an XML string representation.
///
/// @param vector The Vector to convert to XML.
/// @param elementName The name of the root element this Vector will serve as.
///
/// @return Returns a pointer to a C string with an XML representation of the
/// Vector on success, NULL on failure.
char *vectorToXml(Vector *vector, const char *elementName) {
  printLog(TRACE, "ENTER vectorToXml(vector=%p, elementName=\"%s\")\n", vector, elementName);
  
  char *returnValue = listToXml((List*) vector, elementName);
  
  printLog(TRACE, "EXIT vectorToXml(vector=%p, elementName=\"%s\") = {%s}\n", vector, elementName, returnValue);
  return returnValue;
}

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
  
  List *list = listCopy((List*) vector);
  if (list == NULL) {
    printLog(ERR, "Out of memory.\n");
    printLog(TRACE, "EXIT vectorCopy(vector=%p) = {NULL}\n", vector);
    return NULL;
  }
  Vector *returnValue = (Vector*) realloc(list, sizeof(Vector));
  if (returnValue == NULL) {
    listDestroy(list); list = NULL;
    printLog(ERR, "Out of memory.\n");
    printLog(TRACE, "EXIT vectorCopy(vector=%p) = {NULL}\n", vector);
    return NULL;
  }
  list = NULL;
  returnValue->array = (VectorNode**) malloc(returnValue->size * sizeof(VectorNode*));
  if (returnValue->array == NULL) {
    vectorDestroy(returnValue); returnValue = NULL;
    printLog(ERR, "Out of memory.\n");
    printLog(TRACE, "EXIT vectorCopy(vector=%p) = {NULL}\n", vector);
    return NULL;
  }
  
  int i = 0;
  for (VectorNode* cur = returnValue->head; cur != NULL; cur = cur->next) {
    returnValue->array[i++] = cur;
  }
  
  printLog(TRACE, "EXIT vectorCopy(vector=%p) = {%p}\n", vector, returnValue);
  return returnValue;
}

/// @var sortType The TypeDescriptor that describes the keys of a vector for
/// a sort operation.
static TypeDescriptor *sortType = NULL;

/// @var sortOrder The order to sort in.  1 = Ascending, -1 = Descending.
static i32 sortOrder = 0;

/// @fn static int nodeCompare(const void *nodeAPointer, const void *nodeBPointer)
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
int nodeCompare(const void *nodeAPointer, const void *nodeBPointer) {
  printLog(FLOOD, "ENTER nodeCompare(nodeAPointer=%p, nodeBPointer=%p)\n", nodeAPointer, nodeBPointer);
  VectorNode *nodeA = *((VectorNode**) nodeAPointer);
  VectorNode *nodeB = *((VectorNode**) nodeBPointer);
  
  if (sortType == NULL) {
    printLog(ERR, "sortType not defined.\n");
    printLog(FLOOD, "EXIT nodeCompare(nodeAPointer=%p, nodeBPointer=%p) = {%d}\n", nodeAPointer, nodeBPointer, 0);
    return 0;
  }
  
  int returnValue = sortOrder * sortType->compare(nodeA->key, nodeB->key);
  
  printLog(FLOOD, "EXIT nodeCompare(nodeAPointer=%p, nodeBPointer=%p) = {%d}\n", nodeAPointer, nodeBPointer, returnValue);
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
  
  VectorNode **returnValue = NULL;
  
  if ((vector == NULL) || (vector->array == NULL)) {
    printLog(ERR, "vector or vector->array is NULL.\n");
    printLog(TRACE, "EXIT vectorSort(vector=%p, order=%d) = {%p}\n", vector,
      order, returnValue);
    return returnValue;
  }
  
  if (mtx_lock(vector->lock) != thrd_success) {
    printLog(WARN, "Could not lock vector mutex.\n");
  }
  
  returnValue = (VectorNode**) malloc(vector->size * sizeof(VectorNode*));
  if (returnValue == NULL) {
    printLog(ERR, "Out of memory.\n");
    return NULL;
  }
  for (u64 i = 0; i < vector->size; i++) {
    returnValue[i] = vector->array[i];
  }
  sortType = vector->keyType;
  sortOrder = order;
  qsort(returnValue, vector->size, sizeof(VectorNode*), nodeCompare);
  
  mtx_unlock(vector->lock);
  
  printLog(TRACE, "EXIT vectorSort(vector=%p, order=%d) = {%p}\n", vector, order, returnValue);
  return returnValue;
}

Vector* vectorFromByteArray(const volatile void *array, u64 *length) {
  printLog(TRACE, "ENTER vectorFromByteArray(array=%p, length=%p)\n", array,
    length);
  if (array == NULL) {
    printLog(ERR, "array parameter is NULL.\n");
    printLog(TRACE,
      "EXIT vectorFromByteArray(array=NULL, length=%p) = {NULL}\n", length);
    return NULL;
  } else if (length == NULL) {
    printLog(ERR, "length parameter is NULL.\n");
    printLog(TRACE,
      "EXIT vectorFromByteArray(array=%p, length=NULL) = {NULL}\n", array);
    return NULL;
  }
  
  List *list = listFromByteArray(array, length);
  if (list == NULL) {
    printLog(ERR, "Could not construct list from byte array.");
    printLog(TRACE,
      "EXIT vectorFromByteArray(array=%p, length=%llu) = {NULL}\n",
      array, llu(*length));
    return NULL;
  }
  
  Vector *vector = (Vector*) realloc(list, sizeof(Vector));
  if (vector == NULL) {
    // Out of memory.
    list = listDestroy(list);
    printLog(ERR, "Out of memory.\n");
    printLog(TRACE,
      "EXIT vectorFromByteArray(array=%p, length=%llu) = {NULL}\n",
      array, llu(*length));
    return NULL;
  }
  list = NULL;
  
  vector->array = (VectorNode**) malloc(vector->size * sizeof(VectorNode*));
  if (vector->array == NULL) {
    // Out of memory.
    vectorDestroy(vector); vector = NULL;
    printLog(ERR, "Out of memory.\n");
    printLog(TRACE,
      "EXIT vectorFromByteArray(array=%p, length=%llu) = {NULL}\n",
      array, llu(*length));
    return NULL;
  }
  
  int i = 0;
  for (VectorNode* cur = vector->head; cur != NULL; cur = cur->next) {
    vector->array[i++] = cur;
  }
  
  printLog(TRACE,
    "EXIT vectorFromByteArray(array=%p, length=%llu) = {%p}\n",
    array, llu(*length), vector);
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
  
  if (mtx_lock(vector->lock) != thrd_success) {
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
  
  mtx_unlock(vector->lock);
  
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
    = &(jsonText[*position + strspn(&jsonText[*position], " \t\n")]);
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
  while ((*position >= 0) && (jsonText[*position] != '\0')) {
    (*position)++;
    *position += strspn(&jsonText[*position], " \t\n");
    char charAtPosition = jsonText[*position];
    if (charAtPosition == ']') {
      // End of vector.
      (*position)++;
      break;
    }
    
    if ((charAtPosition != '"') && (charAtPosition != '{')
      && (charAtPosition != '[') && !stringIsNumber(&jsonText[*position])
      && !stringIsBoolean(&jsonText[*position])
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
      if (jsonText[*position] == ',') {
        (*position)++;
      }
    } else if (stringIsNumber(&jsonText[*position])) {
      // Parse the number.
      if (stringIsInteger(&jsonText[*position])) {
        i64 longLongValue = (i64) strtoll(&jsonText[*position], NULL, 10);
        vectorSetEntry(returnValue, i++, &longLongValue, typeI64);
      } else { // stringIsFloat(&jsonText[*position])
        double doubleValue = strtod(&jsonText[*position], NULL);
        vectorSetEntry(returnValue, i++, &doubleValue, typeDouble);
      }
      *position
        += ((long long int) ((intptr_t) strchr(&jsonText[*position], '\n')))
        - ((long long int) ((intptr_t) &jsonText[*position]));
    } else if (stringIsBoolean(&jsonText[*position])) {
      // Parse the boolean.
      bool boolValue = strtobool(&jsonText[*position]);
      vectorSetEntry(returnValue, i++, &boolValue, typeBool);
      *position
        += ((long long int) ((intptr_t) strchr(&jsonText[*position], '\n')))
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
    } else { // (charAtPosition == '[')
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
  
  if (vector == NULL) {
    printLog(ERR, "NULL vector provided.\n");
    printLog(TRACE, "EXIT vectorClear(vector=NULL) = {-1}\n");
    return -1;
  }
  
  mtx_lock(vector->lock);
  
  if (vector->array != NULL) {
    vector->array = (VectorNode**) pointerDestroy(vector->array);
  }
  i32 returnValue = listClear((List*) vector);
  
  mtx_unlock(vector->lock);
  
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
  .create        = (void* (*)(const volatile void*, ...)) vectorCreate,
  .copy          = (void* (*)(const volatile void*)) vectorCopy,
  .destroy       = (void* (*)(volatile void*)) vectorDestroy,
  .size          = listSize,
  .toByteArray   = (void* (*)(const volatile void*, u64*)) listToByteArray,
  .fromByteArray = (void* (*)(const volatile void*, u64*)) vectorFromByteArray,
  .hashFunction  = NULL,
  .clear         = (i32 (*)(volatile void*)) vectorClear,
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
  .create        = (void* (*)(const volatile void*, ...)) vectorCreate,
  .copy          = (void* (*)(const volatile void*)) shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = listSize,
  .toByteArray   = (void* (*)(const volatile void*, u64*)) listToByteArray,
  .fromByteArray = (void* (*)(const volatile void*, u64*)) vectorFromByteArray,
  .hashFunction  = NULL,
  .clear         = (i32 (*)(volatile void*)) vectorClear,
};
TypeDescriptor *typeVectorNoCopy = &_typeVectorNoCopy;

/// @def VECTOR_UNIT_TEST
///
/// @brief Unit test functionality for vector data structure.
/// @details Implementing this as a macro instead of raw code allows this to
/// be skipped by the code coverage metrics.
///
/// @return Returns true on success, false on failure.
#define VECTOR_UNIT_TEST \
bool vectorUnitTest() { \
  Vector *vector = NULL, *vector2 = NULL; \
  VectorNode *node = NULL; \
  VectorNode **array= NULL; \
  u64 index = 4; \
  const char *value = "marklar"; \
  char *stringValue = NULL; \
  TypeDescriptor *type = NULL; \
  List *list = NULL; \
   \
  vector = vectorCreate(NULL); \
  if (vector != NULL) { \
    printLog(ERR, \
      "vectorCreate with NULL type succeeded and should not have.\n"); \
    return false; \
  } \
   \
  node = vectorSetEntry(NULL, index, value, type); \
  if (node != NULL) { \
    printLog(ERR, "vectorSetEntry on NULL vector succeeded and should not have.\n"); \
    return false; \
  } \
   \
  node = vectorGetEntry(NULL, index); \
  if (node != NULL) { \
    printLog(ERR, \
      "vectorGetEntry on NULL vector succeeded and should not have.\n"); \
    return false; \
  } \
   \
  if (vectorRemove(NULL, index) == 0) { \
    printLog(ERR, \
      "vectorRemove on NULL vector succeeded and should not have.\n"); \
    return false; \
  } \
   \
  node = (VectorNode*) vectorGetValue(NULL, index); \
  if (node != NULL) { \
    printLog(ERR, \
      "vectorGetValue on NULL vector succeeded and should not have.\n"); \
    return false; \
  } \
   \
  vector = (Vector*) vectorDestroy(NULL); \
  if (vector != NULL) { \
    printLog(ERR, "Error detected in vectorDestroy.\n"); \
    return false; \
  } \
   \
  stringValue = vectorToString(NULL); \
  if (stringValue == NULL) { \
    printLog(ERR, \
      "vectorToString on NULL vector did not succeed and should have.\n"); \
    return false; \
  } \
  if (strcmp(stringValue, "") != 0) { \
    printLog(ERR, "Expected empty string from vectorToString, got \"%s\"\n", stringValue); \
    return false; \
  } \
  stringValue = stringDestroy(stringValue); \
   \
  list = vectorToList(NULL); \
  if (list != NULL) { \
    printLog(ERR, \
      "vectorToList on NULL vector succeeded and should not have.\n"); \
    return false; \
  } \
   \
  stringValue = vectorToXml(NULL, "root"); \
  if (stringValue == NULL) { \
    printLog(ERR, \
      "vectorToXml on NULL vector yielded NULL pointer.\n"); \
    return false; \
  } \
  if (strcmp(stringValue, "<root></root>") != 0) { \
    printLog(ERR, \
      "vectorToXml on NULL vector yielded \"%s\" instead of empty XML.", value); \
    return false; \
  } \
  stringValue = stringDestroy(stringValue); \
   \
  if (vectorCompare(NULL, NULL) != 0) { \
    printLog(ERR, "vectorCompare on two NULL vectors did not return 0.\n"); \
    return false; \
  } \
   \
  vector2 = vectorCopy(NULL); \
  if (vector2 != NULL) { \
    printLog(ERR, "vectorCopy of NULL vector yielded non-NULL vector copy.\n"); \
    return false; \
  } \
   \
  array = vectorSort(NULL, ASCENDING); \
  if (array != NULL) { \
    printLog(ERR, \
      "Ascending vectorSort of NULL vector yielded non-NULL VectorNode array.\n"); \
    return false; \
  } \
   \
  array = vectorSort(NULL, DESCENDING); \
  if (array != NULL) { \
    printLog(ERR, \
      "Descending vectorSort of NULL vector yielded non-NULL VectorNode array.\n"); \
    return false; \
  } \
   \
  vector = vectorCreate(typeString); \
  if (vector == NULL) { \
    printLog(ERR, \
      "vectorCreate with valid type failed and should not have.\n"); \
    return false; \
  } \
   \
  node = vectorSetEntry(vector, index, value); \
  if (node == NULL) { \
    printLog(ERR, "vectorSetEntry on empty vector failed and should not have.\n"); \
    return false; \
  } \
  node = vectorSetEntry(vector, index + 1, NULL); \
  if (node == NULL) { \
    printLog(ERR, "vectorSetEntry on populated vector failed and should not have.\n"); \
    return false; \
  } \
   \
  node = vectorGetEntry(vector, index); \
  if (node == NULL) { \
    printLog(ERR, \
      "vectorGetEntry on valid vector failed and should not have.\n"); \
    return false; \
  } \
  if (strcmp((char*) node->value, "marklar") != 0) { \
    printLog(ERR, "Expected marklar from vectorGetEntry, got \"%s\"\n", \
      (char*) node->value); \
    return false; \
  } \
   \
  if (vectorRemove(vector, index) != 0) { \
    printLog(ERR, \
      "vectorRemove on valid vector failed and should not have.\n"); \
    return false; \
  } \
  if (vector->size != 5) { \
    printLog(ERR, "Expected vector of size 5 after vectorRemove.  Got size " \
      "%llu\n", llu(vector->size)); \
    return false; \
  } \
   \
  node = (VectorNode*) vectorGetValue(vector, index); \
  if (node != NULL) { \
    printLog(ERR, \
      "vectorGetValue succeeded on missing index and should not have.\n"); \
    return false; \
  } \
 \
  node = vectorSetEntry(vector, 2, "marklar", typeString); \
  if (node == NULL) { \
    printLog(ERR,  "Expected non-NULL from vectorSetEntry at index 2, got NULL.\n"); \
    return false; \
  } \
   \
  stringValue = vectorToString(vector); \
  if (stringValue == NULL) { \
    printLog(ERR, \
      "vectorToString on (mostly) empty vector failed and should not have.\n"); \
    return false; \
  } \
  stringValue = stringDestroy(stringValue); \
   \
  list = vectorToList(vector); \
  if (list == NULL) { \
    printLog(ERR, \
      "vectorToList on (mostly) empty vector failed and should not have.\n"); \
    return false; \
  } \
  listDestroy(list); \
   \
  stringValue = vectorToXml(vector, "root"); \
  if (stringValue == NULL) { \
    printLog(ERR, \
      "vectorToXml on (mostly) empty vector failed and should not have.\n"); \
    return false; \
  } \
  stringValue = stringDestroy(stringValue); \
   \
  if (vectorCompare(vector, vector2) != 1) { \
    printLog(ERR, "vectorCompare on non-NULL and NULL vectors did not " \
      "return 1.\n"); \
    return false; \
  } \
   \
  if (vectorCompare(vector2, vector) != -1) { \
    printLog(ERR, "vectorCompare on NULL and non-NULL vectors did not " \
      "return -1.\n"); \
    return false; \
  } \
   \
  vector2 = vectorCopy(vector); \
  if (vector2 == NULL) { \
    printLog(ERR, "vectorCopy of NULL vector yielded non-NULL vector copy.\n"); \
    return false; \
  } \
   \
  if (vectorCompare(vector, vector2) != 0) { \
    printLog(ERR, "vectorCompare on two non-NULL vectors did not return 0.\n"); \
    return false; \
  } \
   \
  array = vectorSort(vector, ASCENDING); \
  if (array == NULL) { \
    printLog(ERR, \
      "Ascending vectorSort of (mostly) empty vector yielded NULL VectorNode " \
      "array.\n"); \
    return false; \
  } \
  array = (VectorNode**) pointerDestroy(array); \
   \
  array = vectorSort(vector, DESCENDING); \
  if (array == NULL) { \
    printLog(ERR, \
      "Descending vectorSort of (mostly) empty vector yielded NULL VectorNode " \
      "array.\n"); \
    return false; \
  } \
  array = (VectorNode**) pointerDestroy(array); \
   \
  vector = (Vector*) vectorDestroy(vector); \
  if (vector != NULL) { \
    printLog(ERR, "Error detected in vectorDestroy with (mostly) empty " \
      "vector.\n"); \
    return false; \
  } \
   \
  vector2 = (Vector*) vectorDestroy(vector2); \
  if (vector2 != NULL) { \
    printLog(ERR, "Error detected in vectorDestroy with (mostly) empty " \
      "vector.\n"); \
    return false; \
  } \
   \
  vector = vectorCreate(typeI32); \
  for (int i = 1; i < 100; i++) { \
    vectorSetEntry(vector, i + 99, &i); \
  } \
  for (int i = -1; i > -100; i--) { \
    vectorSetEntry(vector, i + 99, &i); \
  } \
  list = vectorToList(vector); \
  if (list == NULL) { \
    printLog(ERR, "vectorToList did not populate a list.\n"); \
    return false; \
  } else if (list->size != 199) { \
    printLog(ERR, "vectorToList returned a %llu element list, expected 199 elements." \
      "\n", llu(list->size)); \
    ZEROINIT(i32 array[199]); \
    for (ListNode *node = list->head; node != NULL; node = node->next) { \
      array[*((i32*) node->value) + 99]++; \
    } \
    printLog(ERR, "Not seen:\n"); \
    for (int i = 0; i < 199; i++) { \
      if ((array[i] == 0) && (i != 99)) { \
        printLog(ERR, "%d\n", i - 99); \
      } \
    } \
    return false; \
  } \
  vector = (Vector*) vectorDestroy(vector); \
  listDestroy(list); list = NULL; \
  return true; \
}
VECTOR_UNIT_TEST

