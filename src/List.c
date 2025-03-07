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

#include "List.h"
#include "StringLib.h"
#ifdef DS_LOGGING_ENABLED
#include "LoggingLib.h"
#else
#undef printLog
#define printLog(...) {}
#define logFile stderr
#define LOG_MALLOC_FAILURE(...) {}
#endif

#include "Vector.h" // For to/from JSON support

/// @fn List *listCreate_(TypeDescriptor *keyType, bool disableThreadSafety, ...)
///
/// @brief Create a new linked list data structure.
///
/// @param keyType The TypeDescriptor that specifies what kind of key is to be
///   used with this list.
/// @param disableThreadSafety Whether or not to disable thread safety for the
///   List.
///
/// @note This function is wrapped by a macro of the same name (minus the
/// trailing underscore) that automatically provides false for the
/// dsiableThreadSafety parameter.
///
/// @return Returns a new list on success, NULL on failure.
List *listCreate_(TypeDescriptor *keyType, bool disableThreadSafety, ...) {
  if (keyType == NULL) {
    // Can't make a functional list.
    printLog(ERR, "keyType is NULL.\n");
    return NULL;
  }
  
  printLog(TRACE, "ENTER listCreate(keyType=%s)\n", keyType->name);
  
  List *list = (List*) calloc(1, sizeof(List));
  if (list == NULL) {
    // Out of memory.  Fail.
    LOG_MALLOC_FAILURE();
    printLog(ERR, "Could not allocate space for list.\n");
    return NULL;
  }
  list->keyType = keyType;
  
  if (disableThreadSafety == false) {
    // The mtx_t lock member has to be zeroed, so use calloc here.
    list->lock = (mtx_t*) calloc(1, sizeof(mtx_t));
    if (mtx_init(list->lock, mtx_plain | mtx_recursive) != thrd_success) {
      printLog(ERR, "Could not initialize list mutex lock.\n");
    }
  }
  
  printLog(TRACE, "EXIT listCreate(keyType=%s) = {%p}\n", keyType->name, list);
  return list;
}

/// @fn ListNode *listAddFrontEntry_(List *list, const volatile void *key, const volatile void *value, TypeDescriptor *type)
///
/// @brief Add a new key-value pair to the front of the list.
///
/// @param list is the list to add to.
/// @param key is the key to use.
/// @param value is the value to use.
/// @param type is the TypeDescriptor that describes the value data.
///
/// @note This function is wrapped by a define of the same name, minus the
/// leading underscore.  The type parameter is optional when the define is
/// used.
///
/// @return Returns a pointer to the newly-created ListNode on success,
///   NULL on failure.
ListNode *listAddFrontEntry_(List *list, const volatile void *key,
  const volatile void *value, TypeDescriptor *type, ...
) {
  printLog(TRACE, "ENTER listAddFrontEntry(list=%p, key=%p, value=%p, type=%s)\n",
    list, key, value, (type != NULL) ? type->name : "NULL");
  
  if (list == NULL) {
    // Can't add to a NULL list.
    printLog(DEBUG, "List provided is NULL.\n");
    
    printLog(TRACE,
      "EXIT listAddFrontEntry(list=%p, key=%p, value=%p, type=%s) = {%p}\n",
      list, key, value, (type != NULL) ? type->name : "NULL", (void*) NULL);
    return NULL;
  }
  
  if ((list->lock != NULL) && (mtx_lock(list->lock) != thrd_success)) {
    printLog(WARN, "Could not lock list mutex.\n");
  }
  
  if (type == NULL) {
    if (list->head != NULL) {
      type = list->head->type;
      printLog(DEBUG, "Defaulting to type of head.\n");
    } else {
      type = list->keyType;
      printLog(DEBUG, "Defaulting to type of key.\n");
    }
  }
  
  ListNode *node = (ListNode*) malloc(sizeof(ListNode));
  if (node == NULL) {
    // Out of memory.  Fail.
    printLog(ERR, "Could not allocate memory for list node.\n");
    
    if (list->lock != NULL) {
      mtx_unlock(list->lock);
    }
    
    printLog(TRACE,
      "EXIT listAddFrontEntry(list=%p, key=%p, value=%p, type=%s) = {%p}\n",
      list, key, value, type->name, (void*) NULL);
    return NULL;
  }
  
  node->type = type;
  node->key = list->keyType->copy(key);
  node->value = type->copy(value);
  node->next = list->head;
  node->prev = NULL;
  node->byteOffset = 0;
  
  if (list->head != NULL) {
    list->head->prev = node;
  }
  list->head = node;
  if (list->tail== NULL) {
    list->tail = node;
  }
  list->size++;
  
  if (list->lock != NULL) {
    mtx_unlock(list->lock);
  }
  
  printLog(TRACE, "EXIT listAddFrontEntry(list=%p, key=%p, value=%p, type=%s) = {%p}\n", list, key, value, type->name, node);
  return node;
}

/// @fn ListNode *listAddBackEntry_(List *list, const volatile void *key, const volatile void *value, TypeDescriptor *type, ...)
///
/// @brief Add a new key-value pair to the back of the list.
///
/// @param list is the list to add to.
/// @param key is the key to use.
/// @param value is the value to use.
/// @param type is the TypeDescriptor that describes the value data.
///
/// @note This function is wrapped by a define of the same name, minus the
/// leading underscore.  The type parameter is optional when the define is
/// used.
///
/// @return Returns a pointer to the newly-created ListNode on success,
///   NULL on failure.
ListNode *listAddBackEntry_(List *list, const volatile void *key,
  const volatile void *value, TypeDescriptor *type, ...
) {
  printLog(TRACE, "ENTER listAddBackEntry(list=%p, key=%p, value=%p, type=%s)\n",
    list, key, value, (type != NULL) ? type->name : "NULL");
  
  if (list == NULL) {
    // Can't add to a NULL list.
    printLog(DEBUG, "List provided is NULL.\n");
    
    printLog(TRACE,
      "EXIT listAddBackEntry(list=%p, key=%p, value=%p, type=%s) = {%p}\n",
      list, key, value, (type != NULL) ? type->name : "NULL", (void*) NULL);
    return NULL;
  }
  
  if ((list->lock != NULL) && (mtx_lock(list->lock) != thrd_success)) {
    printLog(WARN, "Could not lock list mutex.\n");
  }
  
  if (type == NULL) {
    if (list->tail != NULL) {
      type = list->tail->type;
      printLog(DEBUG, "Defaulting to type of tail.\n");
    } else {
      type = list->keyType;
      printLog(DEBUG, "Defaulting to type of key.\n");
    }
  }
  
  ListNode *node = (ListNode*) malloc(sizeof(ListNode));
  if (node == NULL) {
    // Out of memory.  Fail.
    printLog(ERR, "Could not allocate memory for list node.\n");
    
    if (list->lock != NULL) {
      mtx_unlock(list->lock);
    }
    
    printLog(TRACE,
      "EXIT listAddBackEntry(list=%p, key=%p, value=%p, type=%s) = {%p}\n",
      list, key, value, type->name, (void*) NULL);
    return NULL;
  }
  
  node->type = type;
  node->key = list->keyType->copy(key);
  node->value = type->copy(value);
  node->next = NULL;
  node->prev = list->tail;
  node->byteOffset = 0;
  
  if (list->tail != NULL) {
    list->tail->next = node;
  }
  list->tail = node;
  if (list->head == NULL) {
    list->head = node;
  }
  list->size++;
  
  if (list->lock != NULL) {
    mtx_unlock(list->lock);
  }
  
  printLog(TRACE, "EXIT listAddBackEntry(list=%p, key=%p, value=%p, type=%s) = {%p}\n", list, key, value, type->name, node);
  return node;
}

/// @fn int listRemoveFront(List *list)
///
/// @brief Remove a key-value pair from the front of the list.
///
/// @param list is the list to remove the key-value pair from.
///
/// @return Returns 0 on success, any other value is failure.
int listRemoveFront(List *list) {
  printLog(TRACE, "ENTER listRemoveFront(list=%p)\n", list);
  
  if (list == NULL) {
    // Can't use NULL list.
    printLog(DEBUG, "List provided is NULL.\n");
    
    printLog(TRACE, "EXIT listRemoveFront(list=%p) = {-1}\n", list);
    return -1;
  }
  
  if ((list->lock != NULL) && (mtx_lock(list->lock) != thrd_success)) {
    printLog(WARN, "Could not lock list mutex.\n");
  }
  
  ListNode *node = list->head;
  if (list->head != NULL) {
    list->head = list->head->next;
  }
  
  int returnValue = listDestroyNode(list, node);
  
  if (list->lock != NULL) {
    mtx_unlock(list->lock);
  }
  
  printLog(TRACE, "EXIT listRemoveFront(list=%p) = {%d}\n", list, returnValue);
  return returnValue;
}

/// @fn int listRemoveBack(List *list)
///
/// @brief Remove a key-value pair from the back of the list.
///
/// @param list is the list to remove the key-value pair from.
///
/// @return Returns 0 on success, any other value is failure.
int listRemoveBack(List *list) {
  printLog(TRACE, "ENTER listRemoveBack(list=%p)\n", list);
  
  if (list == NULL) {
    // Can't use NULL list.
    printLog(DEBUG, "List provided is NULL.\n");
    
    printLog(TRACE, "EXIT listRemoveBack(list=%p) = {-1}\n", list);
    return -1;
  }
  
  if ((list->lock != NULL) && (mtx_lock(list->lock) != thrd_success)) {
    printLog(WARN, "Could not lock list mutex.\n");
  }
  
  ListNode *node = list->tail;
  if (list->tail != NULL) {
    list->tail = list->tail->prev;
  }
  
  int returnValue = listDestroyNode(list, node);
  
  if (list->lock != NULL) {
    mtx_unlock(list->lock);
  }
  
  printLog(TRACE, "EXIT listRemoveBack(list=%p) = {%d}\n", list, returnValue);
  return returnValue;
}

/// @fn int listRemove(List *list, const volatile void *key)
///
/// @brief Remove from the list the key-value pair specified by the key.
///
/// @param list is the list to remove the key-value pair from.
/// @param key is the key to find in the list.
///
/// @return Returns 0 on success, any other value is failure.
int listRemove(List *list, const volatile void *key) {
  printLog(TRACE, "ENTER listRemove(list=%p)\n", list);
  
  if (list == NULL) {
    // Can't use NULL list.
    printLog(DEBUG, "List provided is NULL.\n");
    
    printLog(TRACE, "EXIT listRemove(list=%p) = {-1}\n", list);
    return -1;
  }
  
  if ((list->lock != NULL) && (mtx_lock(list->lock) != thrd_success)) {
    printLog(WARN, "Could not lock list mutex.\n");
  }
  
  ListNode *node = list->head;
  while ((node != NULL) && (list->keyType->compare(node->key, key) != 0)) {
    node = node->next;
  }
  
  int returnValue = listDestroyNode(list, node);
  
  if (list->lock != NULL) {
    mtx_unlock(list->lock);
  }
  
  printLog(TRACE, "EXIT listRemove(list=%p) = {%d}\n", list, returnValue);
  return returnValue;
}

/// @fn ListNode *listGetFront(const List *list)
///
/// @brief Get the ListNode at the front of the list.
///   The list is not modified.
///
/// @param list is the list to get the front ListNode from.
///
/// @return Returns a pointer to the front list node on success,
///   NULL on failure.
ListNode *listGetFront(const List *list) {
  printLog(TRACE, "ENTER listGetFront(list=%p)\n", list);
  
  if (list == NULL) {
    // Can't use NULL list.
    printLog(TRACE, "EXIT listGetFront(list=%p) = {%p}\n", list, (void*) NULL);
    return NULL;
  }
  
  ListNode *returnValue = list->head;
  
  printLog(TRACE, "EXIT listGetFront(list=%p) = {%p}\n", list, returnValue);
  return returnValue;
}

/// @fn ListNode *listGetBack(const List *list)
///
/// @brief Get the ListNode at the back of the list.
///   The list is not modified.
///
/// @param list is the list to get the back ListNode from.
///
/// @return Returns a pointer to the back list node on success,
///   NULL on failure.
ListNode *listGetBack(const List *list) {
  printLog(TRACE, "ENTER listGetBack(list=%p)\n", list);
  
  if (list == NULL) {
    // Can't use NULL list.
    printLog(TRACE, "EXIT listGetBack(list=%p) = {%p}\n", list, (void*) NULL);
    return NULL;
  }
  
  ListNode *returnValue = list->tail;
  
  printLog(TRACE, "EXIT listGetBack(list=%p) = {%p}\n", list, returnValue);
  return returnValue;
}

/// @fn ListNode *listGetForward(const List *list, const volatile void *key)
///
/// @brief Get the ListNode at the specified key starting from the head node.
/// The list is not modified.
///
/// @param list is the list to get the back ListNode from.
/// @param key is the key of the node of interest to get.
///
/// @return Returns a pointer to the found list node on success,
///   NULL on failure.
ListNode *listGetForward(const List *list, const volatile void *key) {
  printLog(TRACE, "ENTER listGetForward(list=%p, key=%p)\n", list, key);
  
  if (list == NULL) {
    // Can't use NULL list.
    printLog(TRACE, "EXIT listGetForward(list=%p, key=%p) = {%p}\n",
      list, key, (void*) NULL);
    return NULL;
  }
  
  if ((list->lock != NULL) && (mtx_lock(list->lock) != thrd_success)) {
    printLog(WARN, "Could not lock list mutex.\n");
  }
  
  ListNode *node = NULL;
  for (node = list->head; node != NULL; node = node->next) {
    if (list->keyType->compare(node->key, key) == 0) {
      break;
    }
  }
  
  if (list->lock != NULL) {
    mtx_unlock(list->lock);
  }
  
  printLog(TRACE, "EXIT listGetForward(list=%p, key=%p) = {%p}\n", list, key, node);
  return node;
}

/// @fn ListNode *listGetReverse(const List *list, const volatile void *key)
///
/// @brief Get the ListNode at the specified key starting from the head node.
/// The list is not modified.
///
/// @param list is the list to get the back ListNode from.
/// @param key is the key of the node of interest to get.
///
/// @return Returns a pointer to the found list node on success,
///   NULL on failure.
ListNode *listGetReverse(const List *list, const volatile void *key) {
  printLog(TRACE, "ENTER listGetReverse(list=%p, key=%p)\n", list, key);
  
  if (list == NULL) {
    // Can't use NULL list.
    printLog(TRACE, "EXIT listGetReverse(list=%p, key=%p) = {%p}\n",
      list, key, (void*) NULL);
    return NULL;
  }
  
  if ((list->lock != NULL) && (mtx_lock(list->lock) != thrd_success)) {
    printLog(WARN, "Could not lock list mutex.\n");
  }
  
  ListNode *node = NULL;
  for (node = list->tail; node != NULL; node = node->prev) {
    if (list->keyType->compare(node->key, key) == 0) {
      break;
    }
  }
  
  if (list->lock != NULL) {
    mtx_unlock(list->lock);
  }
  
  printLog(TRACE, "EXIT listGetReverse(list=%p, key=%p) = {%p}\n", list, key, node);
  return node;
}

/// @fn int listDestroyNode(List *list, ListNode *node)
///
/// @brief Deallocate a list node and associated data/metadata.
///
/// @param list is the list the node is a part of.
/// @param node is the node within the list to deallocate.
///
/// @return Returns 0 on success, any other value is failure.
///
/// @note The list that the node is a part of is necessary because the key
///   TypeDescriptor is carried as part of the list, not the list node.
int listDestroyNode(List *list, ListNode *node) {
  printLog(TRACE, "ENTER listDestroyNode(list=%p, node=%p)\n", list, node);
  
  if ((list == NULL) || (node == NULL)) {
    // Can't destroy with NULLs.
    printLog(ERR, "List or node provided is NULL.\n");
    
    printLog(TRACE, "EXIT listDestroyNode(list=%p, node=%p) = {-1}\n", list, node);
    return -1;
  }
  
  if ((list->lock != NULL) && (mtx_lock(list->lock) != thrd_success)) {
    printLog(WARN, "Could not lock list mutex.\n");
  }
  
  if (list->keyType != NULL) {
    list->keyType->destroy(node->key);
  }
  if (node->type != NULL) {
    node->type->destroy(node->value);
  }
  if (node->prev != NULL) {
    node->prev->next = node->next;
  }
  if (node->next != NULL) {
    node->next->prev = node->prev;
  }
  if (node == list->head) {
    list->head = node->next;
  }
  if (node == list->tail) {
    list->tail = node->prev;
  }
  node = (ListNode*) pointerDestroy(node);
  list->size--;
  
  if (list->lock != NULL) {
    mtx_unlock(list->lock);
  }
  
  printLog(TRACE, "EXIT listDestroyNode(list=%p, node=%p) = {0}\n", list, node);
  return 0;
}

/// @fn List* listDestroy(List *list)
///
/// @brief Deallocate a list and all associated data/metadata.
///
/// @param list is the list to deallocate.
///
/// @return Returns NULL on success, pointer ot the list on failure.
List* listDestroy(List *list) {
  printLog(TRACE, "ENTER listDestroy(list=%p)\n", list);
  
  if (list == NULL) {
    // Can't destroy a NULL list.
    printLog(DEBUG, "List provided is NULL.\n");
    
    printLog(TRACE, "EXIT listDestroy(list=%p) = {-1}\n", list);
    return NULL;
  }
  
  ListNode *node = list->head;
  while (node != NULL) {
    ListNode *nextNode = node->next;
    listDestroyNode(list, node);
    node = nextNode;
  }
  
  if (list->filePointer != NULL) {
    fclose(list->filePointer); list->filePointer = NULL;
  }
  
  if (list->lock != NULL) {
    mtx_destroy(list->lock);
  }
  list->lock = (mtx_t*) pointerDestroy(list->lock);
  
  list = (List*) pointerDestroy(list);
  
  printLog(TRACE, "EXIT listDestroy(list=%p) = {0}\n", list);
  return NULL;
}

/// @fn char *listToString(const List *list)
///
/// @brief Converts a List to a string.  This function will always return an
///   allocated string, even if it's a zero-length (one null byte) string.
///
/// @param list is the List to convert.
///
/// @return Returns a string representation of the list.
char *listToString(const List *list) {
  printLog(TRACE, "ENTER listToString(list=%p)\n", list);
  
  char *returnValue = NULL;
  ListNode *node = NULL;
  
  if (list == NULL) {
    printLog(DEBUG, "List provided was NULL.\n");
    returnValue = (char*) malloc(1);
    *returnValue = '\0';
    
    printLog(TRACE, "EXIT listToString(list=%p) = {%s}\n", list, returnValue);
    return returnValue;
  }
  
  if ((list->lock != NULL) && (mtx_lock(list->lock) != thrd_success)) {
    printLog(WARN, "Could not lock list mutex.\n");
  }
  
  straddstr(&returnValue, "{\n");
  char *size = NULL;
  if (asprintf(&size, "  size=%llu\n", llu(list->size)) < 0) {
    printLog(ERR, "Cannot allocate memory for return value.\n");
    printLog(TRACE, "EXIT listToString(list=%p) = {%p}\n", list, returnValue);
    return returnValue;
  }
  straddstr(&returnValue, size);
  size = stringDestroy(size);
  
  straddstr(&returnValue, "  keyType=");
  straddstr(&returnValue,
    (list->keyType != NULL) ? list->keyType->name : "NULL");
  
  ListNode *end = (list->tail != NULL) ? list->tail->next : NULL;
  u64 listSize = list->size;
  u64 index = 0;
  for (node = list->head;
    (node != end) && (index++ < listSize);
    node = node->next
  ) {
    if (node->type == NULL) {
      continue;
    }
    straddstr(&returnValue, "\n");
    
    straddstr(&returnValue, "  {\n");
    
    straddstr(&returnValue, "    address=");
    char *addressString = typePointer->toString(node);
    straddstr(&returnValue, addressString);
    addressString = stringDestroy(addressString);
    straddstr(&returnValue, "\n");
    straddstr(&returnValue, "    valueType=");
    straddstr(&returnValue, node->type->name);
    straddstr(&returnValue, "\n");
    straddstr(&returnValue, "    key={\n");
    char *keyString = NULL;
    if (list->keyType == typeString) {
      straddchr(&keyString, '"');
      straddstr(&keyString, str(node->key));
      straddchr(&keyString, '"');
    } else {
      keyString = list->keyType->toString(node->key);
    }
    char *indentedKey = indentText(keyString, 6);
    keyString = stringDestroy(keyString);
    straddstr(&returnValue, indentedKey);
    indentedKey = stringDestroy(indentedKey);
    straddstr(&returnValue, "\n    }\n");
    
    straddstr(&returnValue, "    value={\n");
    char *valueString = NULL;
    if (node->type == typeString) {
      straddchr(&valueString, '"');
      straddstr(&valueString, str(node->value));
      straddchr(&valueString, '"');
    } else {
      valueString = node->type->toString(node->value);
    }
    char *indentedValue = indentText(valueString, 6);
    valueString = stringDestroy(valueString);
    straddstr(&returnValue, indentedValue);
    indentedValue = stringDestroy(indentedValue);
    straddstr(&returnValue, "\n    }\n");
    
    straddstr(&returnValue, "  }");
  }
  straddstr(&returnValue, "\n}");
  
  if (list->lock != NULL) {
    mtx_unlock(list->lock);
  }
  
  printLog(TRACE, "EXIT listToString(list=%p) = {%s}\n", list, returnValue);
  return returnValue;
}

/// @fn Bytes listToBytes(const List *list)
///
/// @brief Converts a List to a Bytes object.
///
/// @param list is the List to convert.
///
/// @note If this function is successful, the output will be identical to that
///   of listToString.  That is by design.  This function is intended to be used
///   in other functions that convert data types to tabular representations and
///   those representations should be strings except for the fact that they must
///   be allocated as Bytes objects.
///
/// @return Returns a Bytes representation of the list on success,
///   NULL on failure.
Bytes listToBytes(const List *list) {
  printLog(TRACE, "ENTER listToBytes(list=%p)\n", list);
  
  Bytes returnValue = NULL;
  ListNode *node = NULL;
  
  if (list == NULL) {
    printLog(DEBUG, "List provided was NULL.\n");
    
    printLog(TRACE, "EXIT listToBytes(list=%p) = {NULL}\n", list);
    return NULL;
  }
  
  if ((list->lock != NULL) && (mtx_lock(list->lock) != thrd_success)) {
    printLog(WARN, "Could not lock list mutex.\n");
  }
  
  bytesAddStr(&returnValue, "size=");
  Bytes listSizeBytes = typeU64->toBytes(&list->size);
  bytesAddBytes(&returnValue, listSizeBytes);
  listSizeBytes = bytesDestroy(listSizeBytes);
  
  bytesAddStr(&returnValue, "\n{");
  u64 size = list->size;
  u64 index = 0;
  for (node = list->head;
    (node != NULL) && (index++ < size);
    node = node->next
  ) {
    bytesAddStr(&returnValue, "\n");
    
    bytesAddStr(&returnValue, "  {\n");
    
    bytesAddStr(&returnValue, "    key={\n");
    char *keyString = list->keyType->toString(node->key);
    char *indentedKey = indentText(keyString, 6);
    keyString = stringDestroy(keyString);
    bytesAddStr(&returnValue, indentedKey);
    indentedKey = stringDestroy(indentedKey);
    bytesAddStr(&returnValue, "\n    }\n");
    
    bytesAddStr(&returnValue, "    value={\n");
    char *valueString = NULL;
    valueString = node->type->toString(node->value);
    char *indentedValue = indentText(valueString, 6);
    valueString = stringDestroy(valueString);
    bytesAddStr(&returnValue, indentedValue);
    indentedValue = stringDestroy(indentedValue);
    bytesAddStr(&returnValue, "\n    }\n");
    
    bytesAddStr(&returnValue, "  }");
    
    if (node->next == NULL) {
      // End of the list
      bytesAddStr(&returnValue, "\n");
    }
  }
  bytesAddStr(&returnValue, "}");
  
  if (list->lock != NULL) {
    mtx_unlock(list->lock);
  }
  
  printLog(TRACE, "EXIT listToBytes(list=%p) = {%s}\n", list, returnValue);
  return returnValue;
}

/// @fn List *xmlToList(const char *inputData)
///
/// @brief Take SOAP data and return a list of key-value objects.
///
/// @param inputData is the full data string from a POST call.
///
/// @return Returns a List containing the ListNodes parsed.
List *xmlToList(const char *inputData) {
  char *separatorAt = NULL;
  char *listString = NULL, *indentedListString = NULL;
  List *list = NULL;
  char *key = NULL;
  Bytes value = NULL;
  char *xmlString = NULL;
  
  printLog(TRACE, "ENTER xmlToList(inputData=\"%s\")\n", inputData);
  
  if (inputData == NULL) {
    printLog(ERR, "NULL inputData provided.\n");
    printLog(TRACE, "EXIT xmlToHashList(inputData=NULL) = {NULL}\n");
    return NULL;
  }
  
  const char *startAt = &(inputData[strspn(inputData, " \t\n")]);
  if (*startAt != '<') {
    printLog(DEBUG, "No XML provided.\n");
    printLog(TRACE, "EXIT xmlToList(inputData=NULL) = {NULL}\n");
    return NULL;
  }
  straddstr(&xmlString, startAt);
  
  list = listCreate(typeString);
  // No need to lock the list since nothing else can be using it yet.
  
  separatorAt = strstr(xmlString, "Request");
  if (separatorAt == NULL) {
    // Might be response data we're parsing instead of request data.  Try that.
    separatorAt = strstr(xmlString, "Response");
  }
  if (separatorAt == NULL) {
    // See if it's just generic XML, maybe.
    printLog(DEBUG, "Looking for generic XML data.\n");
    separatorAt = strchr(xmlString, '>');
    if (separatorAt != NULL && separatorAt != xmlString) {
      printLog(DEBUG, "Generic XML data found.\n");
      separatorAt--;
    }
  }
  if (separatorAt != NULL) {
    separatorAt = strchr(separatorAt, '>'); // Skip over the request header
    if (separatorAt != NULL) {
      separatorAt = strchr(separatorAt, '<');
      // We're now either at the first field or the close of the request
    }
  }
  
  while (separatorAt != NULL && *(separatorAt + 1) != '/') {
    char *endOfLine = strchr(separatorAt, '\n');
    // separatorAt should point to a '<'
    char *endOfTag = strchr((++separatorAt), ' ');
    printLog(DEBUG, "In separatorAt while.\n");
    
    if (endOfLine == NULL) {
      // XML is all on one line
      endOfLine = separatorAt + strlen(separatorAt);
    }
    
    if (endOfTag != NULL && strchr(separatorAt, '>') &&
      strchr(separatorAt, '>') < endOfTag) {
      endOfTag = strchr((separatorAt), '>');
    }
    
    if (endOfTag == NULL || endOfTag > endOfLine) {
      endOfTag = strchr((separatorAt), '>');
    }
    
    if (endOfTag != NULL) {
      char *valueAt = NULL;
      char *closeTag = NULL;
      
      if (*endOfTag == '>' && *(endOfTag - 1) == '/') {
        // There is no value for this key
        valueAt = NULL;
      } else if (*endOfTag == '>') {
        valueAt = endOfTag + 1;
      } else { // endOfTag is ' '
        valueAt = strchr((separatorAt + 1), '>');
        if (valueAt) {
          valueAt = valueAt + 1;
        }
      }
      *endOfTag = '\0';
      key = (char *) malloc(strlen(separatorAt) + 1);
      strcpy(key, separatorAt);
      straddstr(&closeTag, "</");
      straddstr(&closeTag, key);
      if (valueAt) {
        endOfTag = strstr(valueAt, closeTag);
      } else {
        endOfTag = NULL;
      }
      if (endOfTag != NULL) {
        *endOfTag = '\0';
        value = NULL;
        bytesAddStr(&value, valueAt);
      } else {
        // No value but there WAS a tag so we can't just leave the value
        // NULL.  Make it an empty string.
        value = NULL;
        bytesAddData(&value, "", 1);
      }
      closeTag = stringDestroy(closeTag);
      
      // OK.  We're parsing XML data.  It's possible that what we just parsed
      // is really just more XML.  If so, it should be added to a subordinate
      // List.  Try to detect this case and act intelligently.
      if (strstr(str(value), "<") != NULL &&
        strrchr(str(value), '>') != NULL &&
        strstr(str(value), "<") < strrchr(str(value), '>')) {
        // Probably more XML.  Make it look like XML and parse again.
        char *xmlValue = NULL;
        straddstr(&xmlValue, "<");
        straddstr(&xmlValue, key);
        straddstr(&xmlValue, ">\n");
        straddstr(&xmlValue, str(value));
        straddstr(&xmlValue, "</");
        straddstr(&xmlValue, key);
        straddstr(&xmlValue, ">\n");
        value = bytesDestroy(value);
        List *subList = xmlToList(xmlValue);
        xmlValue = stringDestroy(xmlValue);
        ListNode *newNode = listAddBackEntry(list, key, subList, typeListNoCopy);
        if (newNode == NULL) {
          printLog(ERR, "listAddBackEntry returned an error.\n");
        }
        newNode->type = typeList;
      }
    } else {
      // No end of tag?  Is this possible?
    }
    
    if (value != NULL) {
      ListNode *node = listAddBackEntry(list, key, value, typeBytesNoCopy);
      if (node != NULL) {
        node->type = typeBytes;
      } else {
        printLog(ERR, "listAddBackEntry failed when adding key/value pair.\n");
      }
    }
    key = stringDestroy(key);
    
    // separatorAt should now be at the beginning of the value
    // endOfTag should now be at the '<' of the closing tag but set to '\0'
    if (endOfTag != NULL) {
      separatorAt = strchr((endOfTag + 1), '<');
    } else {
      separatorAt = separatorAt + 1;
      separatorAt = strchr(separatorAt, '<');
    }
    // separatorAt should now be at the '<' of the opening tag of the next value
  }
  
  xmlString = stringDestroy(xmlString);
  listString = listToString(list);
  indentedListString = indentText(listString, 2);
  listString = stringDestroy(listString);
  printLog(TRACE, "EXIT xmlToList(inputData=\"%s\") = {%s}\n", inputData, indentedListString);
  indentedListString = stringDestroy(indentedListString);
  return list;
}

/// @fn Bytes listToXml(const List *list, const char *elementName)
///
/// @brief Convert a list to its XML representation.
///
/// @param list is the list to convert to XML.
/// @param elementName is the XML tag name to use for the list.
/// @param indent is a boolean to indicate whether or not to indent the XML.
/// @param ... All further parameters are ignored.
///
/// @note This function is wrapped by a macro of the same name, minus the
/// leading underscore, that defaults the indent parameter to false.
///
/// @return Returns a C string with the XML representation of the list.
Bytes listToXml_(const List *list, const char *elementName, bool indent, ...) {
  printLog(TRACE, "ENTER listToXml(list=%p, elementName=%s, indent=%s)\n",
    list, elementName, (indent == true) ? "true" : "false");
  
  ListNode *cur = NULL;
  Bytes listXml = NULL;
  
  bytesAddStr(&listXml, "<");
  bytesAddStr(&listXml, elementName);
  bytesAddStr(&listXml, ">");
  if (indent == true) {
    bytesAddStr(&listXml, "\n");
  }
  
  if (list == NULL) {
    bytesAddStr(&listXml, "</");
    bytesAddStr(&listXml, elementName);
    bytesAddStr(&listXml, ">");
    
    printLog(TRACE,
      "EXIT listToXml(list=%p, elementName=%s, indent=%s) = {%s}\n",
      list, elementName, (indent == true) ? "true" : "false", listXml);
    return listXml;
  }
  
  if ((list->lock != NULL) && (mtx_lock(list->lock) != thrd_success)) {
    printLog(WARN, "Could not lock list mutex.\n");
  }
  
  i64 stringTypeIndex = getIndexFromTypeDescriptor(typeString);
  i64 stringCiNoCopyTypeIndex = getIndexFromTypeDescriptor(typeStringCiNoCopy);
  i64 bytesTypeIndex = getIndexFromTypeDescriptor(typeBytes);
  i64 bytesNoCopyTypeIndex = getIndexFromTypeDescriptor(typeBytesNoCopy);
  u64 size = list->size;
  u64 index = 0;
  for (cur = list->head; (cur != NULL) && (index < size); cur = cur->next) {
    if (indent == true) {
      bytesAddStr(&listXml, "  ");
    }
    bytesAddStr(&listXml, "<");
    char *keyString = list->keyType->toString(cur->key);
    bytesAddStr(&listXml, keyString);
    bytesAddStr(&listXml, ">");
    i64 typeIndex = getIndexFromTypeDescriptor(cur->type);
    if (typeIndex < stringTypeIndex) {
      if (cur->value != NULL) {
        char *valueString = cur->type->toString(cur->value);
        bytesAddStr(&listXml, valueString);
        valueString = stringDestroy(valueString);
      }
    } else if ((typeIndex >= stringTypeIndex)
      && (typeIndex <= stringCiNoCopyTypeIndex)
    ) {
      bytesAddStr(&listXml, str(cur->value));
    } else if ((typeIndex >= bytesTypeIndex)
      && (typeIndex <= bytesNoCopyTypeIndex)
    ) {
      bytesAddBytes(&listXml, (Bytes) cur->value);
    } else { // cur->type >= typeList
      char *subListName = list->keyType->toString(cur->key);
      straddstr(&subListName, cur->type->name);
      Bytes subListXml
        = cur->type->toXml((List*) cur->value, subListName, indent);
      subListName = stringDestroy(subListName);
      if (indent == true) {
        bytesAddStr(&listXml, "\n");
        char *indentedXml = indentText(str(subListXml), 2);
        subListXml = bytesDestroy(subListXml);
        bytesAddStr(&subListXml, indentedXml);
        indentedXml = stringDestroy(indentedXml);
      }
      bytesAddBytes(&listXml, subListXml);
      subListXml = bytesDestroy(subListXml);
      if (indent == true) {
        bytesAddStr(&listXml, "\n");
      }
    }
    bytesAddStr(&listXml, "</");
    bytesAddStr(&listXml, keyString);
    keyString = stringDestroy(keyString);
    bytesAddStr(&listXml, ">");
    if (indent == true) {
      bytesAddStr(&listXml, "\n");
    }
  }
  
  if (list->lock != NULL) {
    mtx_unlock(list->lock);
  }
  
  bytesAddStr(&listXml, "</");
  bytesAddStr(&listXml, elementName);
  bytesAddStr(&listXml, ">");
  
  printLog(TRACE, "EXIT listToXml(list=%p, elementName=%s, indent=%s) = {%s}\n",
    list, elementName, (indent == true) ? "true" : "false", str(listXml));
  return listXml;
}

/// @fn int listCompare(const List *listA, const List *listB)
///
/// @brief Compare the contents of two lists.
///
/// @param listA, listB are the lists to compare.
///
/// @return Returns 0 if the contents are the same, non-zero otherwise.
///
/// @note Non-zero return values from this function are meaningless other than
///   that they express that the two lists are not the same.  There is no
///   standard for evaluating meaning of non-zero values otherwise.
int listCompare(const List *listA, const List *listB) {
  int returnValue = 0; // Assume equal by default
  ListNode *nodeA = NULL, *nodeB = NULL;
  printLog(TRACE, "ENTER listCompare(listA=%p, listB=%p)\n", listA, listB);
  
  if ((listA == NULL) && (listB == NULL)) {
    printLog(TRACE, "EXIT listCompare(listA=%p, listB=%p) = {%d}\n", listA, listB, returnValue);
    return returnValue; // lists are equal
  } else if ((listA == NULL) && (listB != NULL)) {
    returnValue = -1;
    
    printLog(TRACE, "EXIT listCompare(listA=%p, listB=%p) = {%d}\n", listA, listB, returnValue);
    return returnValue; // lists are not equal
  } else if ((listA != NULL) && (listB == NULL)) {
    returnValue = 1;
    
    printLog(TRACE, "EXIT listCompare(listA=%p, listB=%p) = {%d}\n", listA, listB, returnValue);
    return returnValue; // lists are not equal
  }
  
  if (listA->keyType != listB->keyType) {
    returnValue = getIndexFromTypeDescriptor(listA->keyType) - getIndexFromTypeDescriptor(listB->keyType);
    if (returnValue == 0) {
      // Two unknown types.  Use the value of strcmp on the names.
      returnValue = strcmp(listA->keyType->name, listB->keyType->name);
    }
    printLog(DEBUG, "listA->keyType = %s, listB->keyType = %s\n", listA->keyType->name, listB->keyType->name);
    
    printLog(TRACE, "EXIT listCompare(listA=%p, listB=%p) = {%d}\n", listA, listB, returnValue);
    return returnValue; // lists are not equal
  }
  
  if (listA->size != listB->size) {
    if (listA->size > listB->size) {
      returnValue = 1;
      
      printLog(TRACE, "EXIT listCompare(listA=%p, listB=%p) = {%d}\n", listA, listB, returnValue);
      return returnValue; // lists are not equal
    } else {
      returnValue = -1;
      
      printLog(TRACE, "EXIT listCompare(listA=%p, listB=%p) = {%d}\n", listA, listB, returnValue);
      return returnValue; // lists are not equal
    }
  }
  
  if ((listA->lock != NULL) && (mtx_lock(listA->lock) != thrd_success)) {
    printLog(WARN, "Could not lock listA mutex.\n");
  }
  if ((listB->lock != NULL) && (mtx_lock(listB->lock) != thrd_success)) {
    printLog(WARN, "Could not lock listB mutex.\n");
  }
  
  nodeA = listA->head;
  nodeB = listB->head;
  // Lists are the same size, so it doesn't matter which size we use.
  u64 listSize = listA->size;
  u64 index = 0;
  while ((returnValue == 0) && (index++ < listSize)) {
    if ((nodeA == NULL) && (nodeB != NULL)) {
      returnValue = -1;
      break;
    } else if ((nodeA != NULL) && (nodeB == NULL)) {
      returnValue = 1;
      break;
    } else if ((nodeA == NULL) && (nodeB == NULL)) {
      returnValue = 0;
      break;
    }
    
    if (nodeA->type != nodeB->type) {
      printLog(DEBUG, "nodeA->type = %s, nodeB->type = %s\n", nodeA->type->name, nodeB->type->name);
      returnValue = getIndexFromTypeDescriptor(nodeA->type) - getIndexFromTypeDescriptor(nodeB->type);
      if (returnValue == 0) {
        // Two unknown types.  Use the value of strcmp on the names.
        returnValue = strcmp(nodeA->type->name, nodeB->type->name);
      }
      break;
    }
    
    // Both nodes are valid and are of the same data type.  We can compare them.
    // Note that we're not comparing keys here.  That's deliberate.  Comparing
    // keys of a data structure would be equivalent to comparing indexes of
    // items in an array.  That's not useful.  Also, some data structures don't
    // have keys at all, so the comaprsion is of no value.  We're interested in
    // a value-based comparison, so only comparing values is relevant.
    returnValue = nodeA->type->compare(nodeA->value, nodeB->value);
    if (returnValue != 0) {
      char *nodeAString = nodeA->type->toString(nodeA->value);
      char *nodeBString = nodeB->type->toString(nodeB->value);
      printLog(DEBUG, "nodeA = \"%s\", nodeB = \"%s\"\n", nodeAString, nodeBString);
      nodeAString = stringDestroy(nodeAString);
      nodeBString = stringDestroy(nodeBString);
    }
    nodeA = nodeA->next;
    nodeB = nodeB->next;
  }
  
  if (listA->lock != NULL) {
    mtx_unlock(listA->lock);
  }
  if (listB->lock != NULL) {
    mtx_unlock(listB->lock);
  }
  
  printLog(TRACE, "EXIT listCompare(listA=%p, listB=%p) = {%d}\n", listA, listB, returnValue);
  return returnValue;
}

/// @fn List *listCopy(const List *list)
///
/// @brief Make a copy of a list and all its contents.
///
/// @param list is the list to copy.
///
/// @return Returns a newly-allocated list with contents identical to the input
///   list on success, NULL on failure.
List *listCopy(const List *list) {
  printLog(TRACE, "ENTER listCopy(list=%p)\n", list);
  
  List *copy = NULL;
  ListNode *node = NULL;
  
  if (list == NULL) {
    printLog(DEBUG, "List provided is NULL.\n");
    
    printLog(TRACE, "EXIT listCopy(list=%p) = {%p}\n", list, copy);
    return copy;
  }
  
  copy = listCreate(list->keyType);
  
  if ((list->lock != NULL) && (mtx_lock(list->lock) != thrd_success)) {
    printLog(WARN, "Could not lock list mutex.\n");
  }
  
  i64 listTypeIndex = getIndexFromTypeDescriptor(typeList);
  i64 pointerTypeIndex = getIndexFromTypeDescriptor(typePointer);
  u64 size = list->size;
  u64 index = 0;
  for (node = list->head;
    (node != NULL) && (index++ < size);
    node = node->next
  ) {
    i64 typeIndex = getIndexFromTypeDescriptor(node->type);
    printLog(DEBUG, "Copying %s type value.\n", node->type->name);
    if ((typeIndex < listTypeIndex) || (typeIndex >= pointerTypeIndex)) {
      listAddBackEntry(copy, node->key, node->value, node->type);
    } else { // node->type >= typeList
      List *subCopy = listCopy((List*) node->value);
      ListNode *subNode
        = listAddBackEntry(copy, node->key, subCopy, typeListNoCopy);
      if (subNode != NULL) {
        subNode->type = typeList;
      } else {
        printLog(ERR, "Could not add sub-list to copy.\n");
        subCopy = (List*) listDestroy(subCopy);
      }
    }
  }
  
  if (list->lock != NULL) {
    mtx_unlock(list->lock);
  }
  
  printLog(TRACE, "EXIT listCopy(list=%p) = {%p}\n", list, copy);
  return copy;
}

/// @fn size_t listSize(const volatile void *value)
///
/// @brief Compute the size of a list structure in memory.
///
/// @return Returns the size of the list structure in bytes.
size_t listSize(const volatile void *value) {
  size_t size = 0;
  List *list= (List*) value;
  printLog(TRACE, "ENTER listSize(value=\"%p\")\n", value);
  
  if (list != NULL) {
    size = sizeof(List);
  }
  
  printLog(TRACE, "EXIT listSize(value=\"%p\") = {%llu}\n", value, llu(size));
  return size;
}

/// @fn Bytes listToBlob(const List *list)
///
/// @brief Convert a List to a single array of bytes.
///
/// @param list The List (or compatible data structure) to convert.
///
/// @return Returns a Bytes object with the encoded list on success,
/// NULL on failure.
Bytes listToBlob(const List *list) {
  Bytes returnValue = NULL;
  i16 typeIndex = 0;
  u64 size = 0;
  printLog(TRACE, "ENTER listToBlob(list=%p)\n", list);
  
  if (list== NULL) {
    printLog(ERR, "One or more NULL parameters.\n");
    printLog(TRACE, "EXIT listToBlob(list=%p) = {%p}\n", list,
      returnValue);
    return returnValue;
  }
  
  if ((list->lock != NULL) && (mtx_lock(list->lock) != thrd_success)) {
    printLog(WARN, "Could not lock list mutex.\n");
  }
  
  // Metadata
  u16 dsMarker = DsMarker;
  hostToLittleEndian(&dsMarker, sizeof(dsMarker));
  bytesAddData(&returnValue, &dsMarker, sizeof(DsMarker));
  u32 dsVersion = DsVersion;
  hostToLittleEndian(&dsVersion, sizeof(dsVersion));
  bytesAddData(&returnValue, &dsVersion, sizeof(dsVersion));
  
  typeIndex = getIndexFromTypeDescriptor(list->keyType);
  if (typeIndex < 0) {
    // Index is invalid.  TypeDescriptor was not found.
    printLog(ERR, "Could not find list key type \"%s\".\n",
      list->keyType->name);
    if (list->lock != NULL) {
      mtx_unlock(list->lock);
    }
    
    printLog(TRACE, "EXIT listToBlob(list=%p) = {%p}\n", list,
      returnValue);
    return returnValue;
  }
  if (list->keyType->copy == typeStringNoCopy->copy) {
    // Use the base type instead of the NoCopy type.
    typeIndex--;
  }
  hostToLittleEndian(&typeIndex, sizeof(i16));
  bytesAddData(&returnValue, &typeIndex, sizeof(i16));
  
  size = list->size;
  hostToLittleEndian(&size, sizeof(size));
  bytesAddData(&returnValue, &size, sizeof(size));
  
  // Construct a default value for NULL values.
  void* defaultKey = list->keyType->create(NULL);
  Bytes defaultValue = list->keyType->toBlob(defaultKey);
  defaultKey = list->keyType->destroy(defaultKey);
  
  ListNode *node = NULL;
  u64 listSize = list->size;
  u64 index = 0;
  for (node = list->head;
    (node != NULL) && (index++ < listSize);
    node = node->next
  ) {
    Bytes value = NULL, key = NULL;
    typeIndex = getIndexFromTypeDescriptor(node->type);
    if (typeIndex < 0) {
      // Index is invalid.  TypeDescriptor was not found.
      printLog(ERR, "Could not find node type \"%s\".  Skipping node.\n",
        node->type->name);
      continue;
    }
    if (node->type->copy == typeStringNoCopy->copy) {
      // Use the base type instead of the NoCopy type.
      typeIndex--;
    }
    hostToLittleEndian(&typeIndex, sizeof(i16));
    value = node->type->toBlob(node->value);
    if (value == NULL) {
      value = defaultValue;
    }
    key = list->keyType->toBlob(node->key);
    if (key == NULL) {
      key = defaultValue;
    }
    
    bytesAddData(&returnValue, &typeIndex, sizeof(i16));
    // *DO NOT* use bytesAddBytes or bytesLength here.  The toBlob call
    // above will set the size to be the full amount of data encoded.
    // bytesAddBytes and bytesLength do not return the full amount of data
    // encoded for string values (it doesn't include the NULL terminator).
    // We need to gurantee that we get the full data.
    bytesAddData(&returnValue, value, bytesSize(value));
    if (value != defaultValue) {
      value = bytesDestroy(value);
    }
    value = NULL;
    bytesAddData(&returnValue, key, bytesSize(key));
    if (key != defaultValue) {
      key = bytesDestroy(key);
    }
    key = NULL;
  }
  
  defaultValue = bytesDestroy(defaultValue);
  
  if (list->lock != NULL) {
    mtx_unlock(list->lock);
  }
  
  // Set the size to match the length.  This is so recursive toBlob calls
  // will encode the right amount of data, which does not include the NULL
  // string terminator in our case.
  bytesSetSize(returnValue, bytesLength(returnValue));
  
  printLog(TRACE, "EXIT listToBlob(list=%p) = {%p}\n", list, returnValue);
  return returnValue;
}

/// @fn List *listFromBlob_(const volatile void *array, u64 *length, bool inPlaceData, bool disableThreadSafety, ...)
///
/// @brief Convert a properly-formatted byte array into a list.
///
/// @param array The array of bytes to convert.
/// @param length As an input, this is the number of bytes in array.  As an
///   output, this is the number of bytes consumed by this call.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned list.
///
/// @return Returns a pointer to a List on success, NULL on failure.
List *listFromBlob_(const volatile void *array, u64 *length, bool inPlaceData, bool disableThreadSafety, ...) {
  char *byteArray = (char*) array;
  List *list = NULL;
  u64 index = 0;
  i16 typeIndex = 0, keyTypeIndex = 0;
  printLog(TRACE,
    "ENTER listFromBlob(array=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    array, length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  u64 size = 0;
  TypeDescriptor *keyType = NULL, *keyTypeNoCopy = NULL;
  
  if ((array == NULL) || (length == NULL)) {
    printLog(ERR, "One or more NULL parameters.\n");
    printLog(TRACE,
      "EXIT listFromBlob(array=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      list, length, boolNames[inPlaceData], boolNames[disableThreadSafety], list);
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
    printLog(ERR, "Improperly formatted byte array.  Cannot create list.\n");
    printLog(TRACE,
      "EXIT listFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], list);
    return NULL;
  }
  keyType = getTypeDescriptorFromIndex(keyTypeIndex);
  keyTypeNoCopy = getTypeDescriptorFromIndex(keyTypeIndex + 1);
  
  size = *((u64*) &byteArray[index]);
  littleEndianToHost(&size, sizeof(size));
  index += sizeof(size);
  list = listCreate(keyTypeNoCopy, disableThreadSafety);
  if (list == NULL) {
    LOG_MALLOC_FAILURE();
    printLog(NEVER,
      "EXIT listFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], list);
    return NULL;
  }
  
  // Complex data types (which will have type indexes greater than or equal
  // to that of typeList) will need to be handled sliglistly differently than
  // primitives in the case that inPlaceData is true, so grab the index for
  // typeList now so that we can compare it later.
  i64 listIndex = getIndexFromTypeDescriptor(typeList);
  
  ListNode *node = NULL;
  while ((index < arrayLength) && (list->size < size)) {
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
        "EXIT listFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
        array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], list);
      if (inPlaceData) {
        // Optimize for this case.
        if (keyTypeIndex >= listIndex) {
          // See notes at the bottom of this function about this logic.
          list->keyType = keyType;
        }
      } else {
        list->keyType = keyType;
      }
      return list;
    }
    valueType = getTypeDescriptorFromIndex(typeIndex);
    valueTypeNoCopy = getTypeDescriptorFromIndex(typeIndex + 1);
    index += sizeof(i16);
    valueSize = arrayLength - index;
    
    value = valueType->fromBlob(&byteArray[index], &valueSize, inPlaceData, disableThreadSafety);
    index += valueSize;
    if (value == NULL) {
      *length = index;
      printLog(ERR, "NULL value detected.  Cannot process.\n");
      printLog(TRACE,
        "EXIT listFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
        array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], list);
      if (inPlaceData) {
        // Optimize for this case.
        if (keyTypeIndex >= listIndex) {
          // See notes at the bottom of this function about this logic.
          list->keyType = keyType;
        }
      } else {
        list->keyType = keyType;
      }
      return list;
    }
    
    keySize = arrayLength - index;
    key = keyType->fromBlob(&byteArray[index], &keySize, inPlaceData, disableThreadSafety);
    index += keySize;
    if (key == NULL) {
      *length = index;
      printLog(ERR, "NULL key detected.  Cannot process.\n");
      printLog(TRACE,
        "EXIT listFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
        array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], list);
      if (inPlaceData) {
        // Optimize for this case.
        if (keyTypeIndex >= listIndex) {
          // See notes at the bottom of this function about this logic.
          list->keyType = keyType;
        }
      } else {
        list->keyType = keyType;
      }
      return list;
    }
    
    node = listAddBackEntry(list, key, value, valueTypeNoCopy);
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
      printLog(ERR, "Failed to add node to list.\n");
    }
  }
  if (list->size < size) {
    printLog(ERR, "Expected %llu entries, but only found %llu.\n",
      llu(size), llu(list->size));
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
      list->keyType = keyType;
    }
  } else {
    list->keyType = keyType;
  }
  
  printLog(TRACE,
    "EXIT listFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], list);
  return list;
}

/// @fn Bytes listToJson(const List *list)
///
/// @brief Converts a List to a JSON-formatted string.  This function will
///   always return an allocated string, even if it's a zero-length (one null
///   byte) string.
///
/// @param list is the List to convert.
///
/// @return Returns a JSON-formatted Bytes object representation of the list.
Bytes listToJson(const List *list) {
  printLog(TRACE, "ENTER listToJson(list=%p)\n", list);
  
  Bytes returnValue = NULL;
  ListNode *node = NULL;
  
  if (list == NULL) {
    printLog(DEBUG, "List provided was NULL.\n");
    bytesAllocate(&returnValue, 0);
    
    printLog(TRACE, "EXIT listToJson(list=%p) = {%s}\n", list, returnValue);
    return returnValue;
  }
  
  if ((list->lock != NULL) && (mtx_lock(list->lock) != thrd_success)) {
    printLog(WARN, "Could not lock list mutex.\n");
  }
  
  i64 listTypeIndex = getIndexFromTypeDescriptor(typeList);
  bytesAddStr(&returnValue, "{\n");
  u64 size = list->size;
  u64 index = 0;
  for (node = list->head;
    (node != NULL) && (index++ < size);
    node = node->next
  ) {
    bytesAddStr(&returnValue, "  \"");
    char *keyString = list->keyType->toString(node->key);
    bytesAddStr(&returnValue, keyString);
    keyString = stringDestroy(keyString);
    bytesAddStr(&returnValue, "\"");
    
    if (getIndexFromTypeDescriptor(node->type) < listTypeIndex) {
      // Append end of key, start of value.
      bytesAddStr(&returnValue, ": ");
      char *valueString = NULL;
      if ((node->type == typeString) || (node->type == typeStringNoCopy)
        || (node->type == typeStringCi) || (node->type == typeStringCiNoCopy)
        || (node->type == typeBytes) || (node->type == typeBytesNoCopy)
      ) {
        bytesAddStr(&returnValue, "\"");
        if ((node->type == typeBytes) || (node->type == typeBytesNoCopy)) {
          valueString = escapeBytes((Bytes) node->value);
        } else { // some kind of string
          valueString = escapeString(str(node->value));
        }
      } else {
        valueString = node->type->toString(node->value);
      }
      bytesAddStr(&returnValue, valueString);
      valueString = stringDestroy(valueString);
      if ((node->type == typeString) || (node->type == typeStringNoCopy)
        || (node->type == typeStringCi) || (node->type == typeStringCiNoCopy)
        || (node->type == typeBytes) || (node->type == typeBytesNoCopy)
      ) {
        bytesAddStr(&returnValue, "\"");
      }
    } else if (
      ((node->type == typePointer) || (node->type == typePointerNoCopy))
      && (node->value == NULL)
    ) {
      // NULL value.
      bytesAddStr(&returnValue, ": null");
    } else { // Value's type is a data structure, not a primitive.
      Bytes valueString = node->type->toJson(node->value);
      // In this case, valueString starts with '{' or '[' on its own line and
      // ends with '}' or ']' on its own line.  After the indent, the
      // valueString will be correct except that we need to change the first
      // character to a ':' to properly end the key.
      char *indentedValue = indentText(str(valueString), 2);
      valueString = bytesDestroy(valueString);
      indentedValue[0] = ':';
      bytesAddStr(&returnValue, indentedValue);
      indentedValue = stringDestroy(indentedValue);
    }
    
    if (node->next != NULL) {
      // End of the list
      bytesAddStr(&returnValue, ",\n");
    }
  }
  bytesAddStr(&returnValue, "\n}");
  
  if (list->lock != NULL) {
    mtx_unlock(list->lock);
  }
  
  printLog(TRACE, "EXIT listToJson(list=%p) = {%s}\n", list, returnValue);
  return returnValue;
}

// jsonToList implementation from generic macro.
#define listAddEntry listAddBackEntry
JSON_TO_DATA_STRUCTURE(List, list)
#undef listAddEntry

/// @fn char* listToKeyValueString(const List *list, const char *separator)
///
/// @brief Convert a List to a separator-delimited set of key-value pairs.
///
/// @param list A pointer to the List to convert.
/// @param separator A C string that will separate the key-value pairs.
///
/// @return Returns a string containing the key-value pairs on success, NULL
/// on failure.
char* listToKeyValueString(const List *list, const char *separator) {
  printLog(TRACE,
    "ENTER listToKeyValueString(list=%p, separator=\"%s\")\n",
    list, separator);
  char *returnValue = NULL;
  
  i64 keyTypeIndex = getIndexFromTypeDescriptor(list->keyType);
  i64 stringTypeIndex = getIndexFromTypeDescriptor(typeString);
  i64 bytesNoCopyTypeIndex = getIndexFromTypeDescriptor(typeBytesNoCopy);
  
  if ((keyTypeIndex < 0) || (keyTypeIndex > bytesNoCopyTypeIndex)) {
    printLog(ERR, "Invalid key type.\n");
    printLog(TRACE,
      "EXIT listToKeyValueString(list=%p, separator=\"%s\") = {%s}\n",
      list, separator, returnValue);
    return returnValue; // NULL
  }
  
  ListNode *cur = NULL;
  u64 size = list->size;
  u64 index = 0;
  for (cur = list->head; (cur != NULL) && (index++ < size); cur = cur->next) {
    i64 valueTypeIndex = getIndexFromTypeDescriptor(cur->type);
    if (valueTypeIndex < 0) {
      // Invalid value type.  Skip this node.
      continue;
    } else if (cur->key == NULL) {
      // Invalid key.  Skip this node.
      continue;
    }
    
    char *key = NULL;
    if ((keyTypeIndex >= stringTypeIndex)
      && (keyTypeIndex <= bytesNoCopyTypeIndex)
    ) {
      // Key type is string compatible.  Just use it directly.
      straddstr(&key, (char*) cur->key);
    } else {
      // Convert the key to a string.
      key = list->keyType->toString(cur->key);
    }
    
    char *value = NULL;
    if ((valueTypeIndex >= stringTypeIndex)
      && (valueTypeIndex <= bytesNoCopyTypeIndex)
    ) {
      // Value type is string compatible.  Just use it directly.
      straddstr(&value, (char*) cur->value);
    } else {
      // Convert the value to a string.
      if (cur->value != NULL) {
        value = cur->type->toString(cur->value);
      }
    }
    char *escapedValue = escapeString(value);
    value = stringDestroy(value);
    
    // Add the pair.
    straddstr(&returnValue, key);
    key = stringDestroy(key);
    straddstr(&returnValue, "=");
    straddstr(&returnValue, escapedValue);
    value = stringDestroy(escapedValue);
    if (cur->next != NULL) {
      straddstr(&returnValue, separator);
    }
  }
  
  printLog(TRACE,
    "EXIT listToKeyValueString(list=%p, separator=\"%s\") = {%s}\n",
    list, separator, returnValue);
  return returnValue;
}

/// @fn i32 listClear(List *list)
///
/// @brief Destroy all the nodes of the List (starting with list->head and
/// ending with list->tail), but do not destroy the List object or any of its
/// other members.
///
/// @param list A pointer to a List object to clear.
///
/// @return Returns 0 on success, -1 on failure.
i32 listClear(List *list) {
  printLog(TRACE, "ENTER listClear(list=%p)\n", list);
  
  i32 returnValue = 0;
  if (list == NULL) {
    // No-op.
    printLog(TRACE, "EXIT listClear(list=%p) = {%d}\n", list, returnValue);
    return returnValue;
  }
  
  // Make sure we're not deleting while someone else is accessing.
  if ((list->lock != NULL) && (mtx_lock(list->lock) != thrd_success)) {
    printLog(WARN, "Could not lock list mutex.\n");
  }
  
  for (ListNode *cur = list->head; cur != NULL;) {
    ListNode *node = cur;
    cur = cur->next;
    returnValue |= listDestroyNode(list, node);
  }
  list->head = NULL;
  list->tail = NULL;
  
  if (list->lock != NULL) {
    mtx_unlock(list->lock);
  }
  
  printLog(TRACE, "EXIT listClear(list=%p) = {%d}\n", list, returnValue);
  return returnValue;
}

/// @fn u64 listLength(List *list)
///
/// @brief Get the number of elements in the list.
///
/// @param list A pointer to a previously-instantiated List object.
///
/// @return Returns the number of elements in the list.
u64 listLength(List *list) {
  printLog(TRACE, "ENTER listLength(list=%p)\n", list);
  
  u64 returnValue = 0;
  if (list == NULL) {
    printLog(TRACE, "EXIT listLength(list=%p) = {%llu}\n", list,
      llu(returnValue));
    return returnValue; // 0
  }
  
  if ((list->lock != NULL) && (mtx_lock(list->lock) != thrd_success)) {
    printLog(WARN, "Could not lock list mutex.\n");
  }
  returnValue = list->size;
  if (list->lock != NULL) {
    mtx_unlock(list->lock);
  }
  
  printLog(TRACE, "EXIT listLength(list=%p) = {%llu}\n", list,
    llu(returnValue));
  return returnValue;
}

/// @var typeList
///
/// @brief TypeDescriptor describing how libraries should interact with
///   list data.
TypeDescriptor _typeList = {
  .name          = "List",
  .xmlName       = NULL,
  .dataIsPointer = true,
  .toString      = (char* (*)(const volatile void*)) listToString,
  .toBytes       = (Bytes (*)(const volatile void*)) listToBytes,
  .compare       = (int (*)(const volatile void*, const volatile void*)) listCompare,
  .create        = (void* (*)(const volatile void*, ...)) listCreate_,
  .copy          = (void* (*)(const volatile void*)) listCopy,
  .destroy       = (void* (*)(volatile void*)) listDestroy,
  .size          = listSize,
  .toBlob        = (Bytes (*)(const volatile void*)) listToBlob,
  .fromBlob      = (void* (*)(const volatile void*, u64*, bool, bool)) listFromBlob_,
  .hashFunction  = NULL,
  .clear         = (i32 (*)(volatile void *)) listClear,
  .toXml         = (Bytes (*)(const volatile void*, const char *elementName, bool indent, ...)) listToXml_,
  .toJson        = (Bytes (*)(const volatile void*)) listToJson,
};
TypeDescriptor *typeList = &_typeList;

/// @var typeListNoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with
///   list data that is not copied from its original source.
///
/// @details This exists because, by default, a copy of the input data is made
///   whenever a new data element is added to any data structure.  In some
///   situations, this is not desirable because the input serves no purpose
///   other than to be added to the data structure.  In such cases, this data
///   type may be specified to avoid the unnecessary copy.  The real
///   typeList type can then be set after the data is added.
TypeDescriptor _typeListNoCopy = {
  .name          = "List",
  .xmlName       = NULL,
  .dataIsPointer = true,
  .toString      = (char* (*)(const volatile void*)) listToString,
  .toBytes       = (Bytes (*)(const volatile void*)) listToBytes,
  .compare       = (int (*)(const volatile void*, const volatile void*)) listCompare,
  .create        = (void* (*)(const volatile void*, ...)) listCreate_,
  .copy          = (void* (*)(const volatile void*)) shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = listSize,
  .toBlob        = (Bytes (*)(const volatile void*)) listToBlob,
  .fromBlob      = (void* (*)(const volatile void*, u64*, bool, bool)) listFromBlob_,
  .hashFunction  = NULL,
  .clear         = (i32 (*)(volatile void *)) listClear,
  .toXml         = (Bytes (*)(const volatile void*, const char *elementName, bool indent, ...)) listToXml_,
  .toJson        = (Bytes (*)(const volatile void*)) listToJson,
};
TypeDescriptor *typeListNoCopy = &_typeListNoCopy;

/// @def LIST_TEST_CASES
///
/// @brief Test case implementations for listUnitTest.
/// @details Implementing this as a macro instead of raw code allows this to
/// be skipped by the code coverage metrics.
///
/// @brief param list is a pointer to a list, which may be NULL or a valid list.
///
/// @return Returns true on success, false on failure.
#define LIST_TEST_CASES \
bool listTestCases(List *list) { \
  List *list2 = NULL; \
  ListNode *node = NULL; \
  char *stringValue = NULL; \
 \
  printLog(INFO, "Adding to front of %s list.\n", (list == NULL) ? "NULL" : "empty"); \
  node = listAddFrontEntry(list, NULL, NULL); \
  if ((list == NULL) && (node != NULL)) { \
    printLog(ERR, "Expected NULL node.  Got %p.\n", node); \
    return false; \
  } else if ((list != NULL) && (node == NULL)) { \
    printLog(ERR, "Expected valid node.  Got NULL.\n"); \
    return false; \
  } \
  if (list != NULL) { \
    listDestroy(list); list = NULL; \
    list = listCreate(typeString); \
  } \
 \
  printLog(INFO, "Adding to back of %s list.\n", (list == NULL) ? "NULL" : "empty"); \
  node = listAddBackEntry(list, NULL, NULL); \
  if ((list == NULL) && (node != NULL)) { \
    printLog(ERR, "Expected NULL node.  Got %p.\n", node); \
    return false; \
  } else if ((list != NULL) && (node == NULL)) { \
    printLog(ERR, "Expected valid node.  Got NULL.\n"); \
    return false; \
  } \
  if (list != NULL) { \
    listDestroy(list); list = NULL; \
    list = listCreate(typeString); \
  } \
 \
  printLog(INFO, "Adding to somewhere of %s list.\n", (list == NULL) ? "NULL" : "empty"); \
  node = listAddBackEntry(list, NULL, NULL); \
  if ((list == NULL) && (node != NULL)) { \
    printLog(ERR, "Expected NULL node.  Got %p.\n", node); \
    return false; \
  } else if ((list != NULL) && (node == NULL)) { \
    printLog(ERR, "Expected valid node.  Got NULL.\n"); \
    return false; \
  } \
  if (list != NULL) { \
    listDestroy(list); list = NULL; \
    list = listCreate(typeString); \
  } \
 \
  printLog(INFO, "Removing front of %s list.\n", (list == NULL) ? "NULL" : "empty"); \
  if (listRemoveFront(list) != -1) { \
    printLog(ERR, "Expected failure status from listRemoveFront.\n"); \
    printLog(ERR, "Got good status.\n"); \
    return false; \
  } \
 \
  printLog(INFO, "Removing back of %s list.\n", (list == NULL) ? "NULL" : "empty"); \
  if (listRemoveBack(list) != -1) { \
    printLog(ERR, "Expected failure status from listRemoveBack.\n"); \
    printLog(ERR, "Got good status.\n"); \
    return false; \
  } \
 \
  printLog(INFO, "Removing NULL key from %s list.\n", (list == NULL) ? "NULL" : "empty"); \
  if (listRemove(list, NULL) != -1) { \
    printLog(ERR, "Expected failure status from listRemove.\n"); \
    printLog(ERR, "Got good status.\n"); \
    return false; \
  } \
 \
  printLog(INFO, "Getting front of %s list.\n", (list == NULL) ? "NULL" : "empty"); \
  node = listGetFront(list); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from listGetFront.\n"); \
    printLog(ERR, "Got %p.\n", node); \
    return false; \
  } \
 \
  printLog(INFO, "Getting back of %s list.\n", (list == NULL) ? "NULL" : "empty"); \
  node = listGetBack(list); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from listGetBack.\n"); \
    printLog(ERR, "Got %p.\n", node); \
    return false; \
  } \
 \
  printLog(INFO, "Getting NULL key of %s list.\n", (list == NULL) ? "NULL" : "empty"); \
  node = listGetForward(list, NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from listGetForward.\n"); \
    printLog(ERR, "Got %p.\n", node); \
    return false; \
  } \
  node = listGetReverse(list, NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from listGetReverse.\n"); \
    printLog(ERR, "Got %p.\n", node); \
    return false; \
  } \
 \
  printLog(INFO, "Destroying NULL node in %s list.\n", (list == NULL) ? "NULL" : "empty"); \
  if (listDestroyNode(list, NULL) != -1) { \
    printLog(ERR, "Got unexpected good status from listDestroyNode.\n"); \
    return false; \
  } \
 \
  printLog(INFO, "Converting list to string.\n"); \
  stringValue = listToString(list); \
  if ((list == NULL) && (stringValue[0] != '\0')) { \
    printLog(ERR, "Expected empty string from listToString.\n"); \
    printLog(ERR, "Got \"%s\"\n", stringValue); \
    stringValue = stringDestroy(stringValue); \
    return false; \
  } else if ((list != NULL) && (strcmp(stringValue, "{\n  size=0\n  keyType=string\n}") != 0)) { \
    printLog(ERR, "Expected empty list string from listToString.\n"); \
    printLog(ERR, "Got \"%s\"\n", stringValue); \
    stringValue = stringDestroy(stringValue); \
    return false; \
  } \
  stringValue = stringDestroy(stringValue); \
 \
  printLog(INFO, "Converting list to XML.\n"); \
  Bytes bytesValue = listToXml(list, NULL); \
  if (strcmp(str(bytesValue), "<></>") != 0) { \
    printLog(ERR, "Expected empty XML from listToXml.\n"); \
    printLog(ERR, "Got \"%s\"\n", stringValue); \
    stringValue = stringDestroy(stringValue); \
    return false; \
  } \
  bytesValue = bytesDestroy(bytesValue); \
 \
  if (list != NULL) { \
    listAddBackEntry(list, "key1", "value1"); \
    listAddBackEntry(list, "key4", "value4"); \
    listAddBackEntry(list, "key2", "value2"); \
    listAddFrontEntry(list, "key3", "value3"); \
    list2 = listCreate(typeString); \
    listAddBackEntry(list2, "key1", "value1"); \
    listAddBackEntry(list2, "key4", "value4"); \
    listAddBackEntry(list2, "key2", "value2"); \
    listAddFrontEntry(list2, "key3", "value3"); \
    listAddBackEntry(list, "key5", list2, typeList); \
    listDestroy(list2); list2 = NULL; \
    list2 = listCopy(list); \
    printLog(INFO, "Converting list with sub-list to XML.\n"); \
    bytesValue = listToXml(list, "root"); \
    Bytes bytesValue2 = listToXml(list2, "root"); \
    if (bytesCompare(bytesValue, bytesValue2) != 0) { \
      printLog(ERR, "XML for lists with sub-lists did not match.\n"); \
      return false; \
    } \
    bytesValue = bytesDestroy(bytesValue); \
    bytesValue2 = bytesDestroy(bytesValue2); \
    if (listCompare(list, list2) != 0) { \
      printLog(ERR, "Comparsion of identical lists with sub-lists did not " \
        "return 0.\n"); \
      return false; \
    } \
    listDestroy(list2); list2 = NULL; \
    listDestroy(list); list = NULL; \
    list = listCreate(typeString); \
  } \
 \
  printLog(INFO, "Converting NULL XML to list.\n"); \
  list2 = xmlToList(NULL); \
  if (list2 != NULL) { \
    printLog(ERR, "Non-empty list generated from NULL XML.\n"); \
    return false; \
  } \
  if (list == NULL) { \
    listDestroy(list2); list2 = NULL; \
  } else { \
    list2 = listCreate(list->keyType); \
  } \
 \
  printLog(INFO, "Comparing %s lists.\n", (list == NULL) ? "NULL" : "empty"); \
  if (listCompare(list, list2) != 0) { \
    printLog(ERR, "list and list2 are not equal.\n"); \
    return false; \
  } \
  if (list2 != NULL) { \
    listDestroy(list2); list2 = NULL; \
  } \
 \
  printLog(INFO, "Copying %s list.\n", (list == NULL) ? "NULL" : "empty"); \
  list2 = listCopy(list); \
  if ((list == NULL) && (list2 != NULL)) { \
    printLog(ERR, "list is NULL, but list2 is not.\n"); \
    return false; \
  } else if ((list != NULL) && (listCompare(list, list2) != 0)) { \
    printLog(ERR, "list and list2 are not identical.\n"); \
    return false; \
  } \
  list2 = (List*) listDestroy(list2); \
 \
  listAddBackEntry(list, "key1", "value1"); \
  listAddBackEntry(list, "key4", "value4"); \
  listAddBackEntry(list, "key2", "value2"); \
  listAddFrontEntry(list, "key3", "value3"); \
 \
  Bytes byteArray = listToBlob(list); \
  u64 length = bytesLength(byteArray); \
  list2 = listFromBlob(byteArray, &length); \
  byteArray = bytesDestroy(byteArray); \
  if (listCompare(list, list2) != 0) { \
    printLog(ERR, "list and list2 were not equal.\n"); \
    return false; \
  } \
  list2 = (List*) listDestroy(list2); \
 \
  node = listGetForward(list, "key1"); \
  if ((list != NULL) && (node == NULL)) { \
    printLog(ERR, "Could not get key1 from list.\n"); \
    return false; \
  } \
  node = listGetForward(list, "key2"); \
  if ((list != NULL) && (node == NULL)) { \
    printLog(ERR, "Could not get key2 from list.\n"); \
    return false; \
  } \
  node = listGetForward(list, "key3"); \
  if ((list != NULL) && (node == NULL)) { \
    printLog(ERR, "Could not get key3 from list.\n"); \
    return false; \
  } \
  node = listGetForward(list, "key4"); \
  if ((list != NULL) && (node == NULL)) { \
    printLog(ERR, "Could not get key4 from list.\n"); \
    return false; \
  } \
  node = listGetForward(list, "key5"); \
  if (node != NULL) { \
    printLog(ERR, "Got key5 from list.\n"); \
    return false; \
  } \
  node = listGetReverse(list, "key1"); \
  if ((list != NULL) && (node == NULL)) { \
    printLog(ERR, "Could not get key1 from list.\n"); \
    return false; \
  } \
  node = listGetReverse(list, "key2"); \
  if ((list != NULL) && (node == NULL)) { \
    printLog(ERR, "Could not get key2 from list.\n"); \
    return false; \
  } \
  node = listGetReverse(list, "key3"); \
  if ((list != NULL) && (node == NULL)) { \
    printLog(ERR, "Could not get key3 from list.\n"); \
    return false; \
  } \
  node = listGetReverse(list, "key4"); \
  if ((list != NULL) && (node == NULL)) { \
    printLog(ERR, "Could not get key4 from list.\n"); \
    return false; \
  } \
  node = listGetReverse(list, "key5"); \
  if (node != NULL) { \
    printLog(ERR, "Got key5 from list.\n"); \
    return false; \
  } \
  listRemoveBack(list); \
  listRemove(list, "key4"); \
  listRemove(list, "key3"); \
  listRemoveFront(list); \
 \
  listDestroy(list2); list2 = NULL; \
  listDestroy(list); list = NULL; \
 \
  return true; \
}
LIST_TEST_CASES

/// @def LIST_UNIT_TEST
///
/// @brief Unit tests for list functionality.
/// @details Implementing this as a macro instead of raw code allows this to
/// be skipped by the code coverage metrics.
///
/// @return Returns true on success, false on failure.
#define LIST_UNIT_TEST \
bool listUnitTest() { \
  List *list = NULL; \
 \
  printLog(INFO, "Testing List data structure.\n"); \
 \
  if (listTestCases(NULL) == false) { \
    printLog(ERR, "listTestCases(NULL) failed.\n"); \
    return false; \
  } \
 \
  list = listCreate(typeString); \
 \
  if (listTestCases(list) == false) { \
    printLog(ERR, "listTestCases(list) failed.\n"); \
    return false; \
  } \
 \
  const char *xmlToParse = \
    "<list>" \
      "<myList1>" \
        "<key1>value1</key1>" \
        "<key2>value2</key2>" \
      "</myList1>" \
      "<key3>value3</key3>" \
      "<myList2>" \
        "<key4>value4</key4>" \
        "<key5>value5</key5>" \
        "<key6>value6</key6>" \
      "</myList2>" \
      "<myList3>" \
        "<myList4>" \
          "<key7>value7</key7>" \
          "<key8>value8</key8>" \
        "</myList4>" \
        "<key9>value9</key9>" \
      "</myList3>" \
    "</list>"; \
  printLog(INFO, "Parsing XML into list.\n"); \
  list = xmlToList(xmlToParse); \
  if (list == NULL) { \
    printLog(ERR, "Could not parse XML into list.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting myList1 from parsed list.\n"); \
  ListNode *node = listGetForward(list, "myList1"); \
  if (node == NULL) { \
    printLog(ERR, "myList1 did not appear in parsed list.\n"); \
    return false; \
  } \
  if (node->type != typeList) { \
    printLog(ERR, "myList1 was of type %lld instead of typeList.\n", \
      lld(getIndexFromTypeDescriptor(node->type))); \
    return false; \
  } \
  printLog(INFO, "Getting key1 from myList1.\n"); \
  if (listGetForward((List*) node->value, "key1") == NULL) { \
    printLog(ERR, "key1 did not appear in myList1.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting key2 from myList1.\n"); \
  if (listGetForward((List*) node->value, "key2") == NULL) { \
    printLog(ERR, "key2 did not appear in myList1.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting key3 from parsed list.\n"); \
  node = listGetForward(list, "key3"); \
  if (node == NULL) { \
    printLog(ERR, "key3 did not appear in parsed list.\n"); \
    return false; \
  } \
  if (strcmp("value3", (char*) node->value) != 0) { \
    printLog(ERR, "Expected value of key3 to be value3, got \"%s\".\n", \
      (char*) node->value); \
    return false; \
  } \
  printLog(INFO, "Getting myList2 from parsed list.\n"); \
  node = listGetForward(list, "myList2"); \
  if (node == NULL) { \
    printLog(ERR, "myList2 did not appear in parsed list.\n"); \
    return false; \
  } \
  if (node->type != typeList) { \
    printLog(ERR, "myList2 was of type %lld instead of typeList.\n", \
      lld(getIndexFromTypeDescriptor(node->type))); \
    return false; \
  } \
  printLog(INFO, "Getting key4 from myList2.\n"); \
  if (listGetForward((List*) node->value, "key4") == NULL) { \
    printLog(ERR, "key4 did not appear in myList2.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting key5 from myList2.\n"); \
  if (listGetForward((List*) node->value, "key5") == NULL) { \
    printLog(ERR, "key5 did not appear in myList2.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting key6 from myList2.\n"); \
  if (listGetForward((List*) node->value, "key6") == NULL) { \
    printLog(ERR, "key6 did not appear in myList2.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting myList3 from parsed list.\n"); \
  node = listGetForward(list, "myList3"); \
  if (node == NULL) { \
    printLog(ERR, "myList3 did not appear in parsed list.\n"); \
    return false; \
  } \
  if (node->type != typeList) { \
    printLog(ERR, "myList3 was of type %lld instead of typeList.\n", \
      lld(getIndexFromTypeDescriptor(node->type))); \
    return false; \
  } \
  printLog(INFO, "Getting key9 from myList3.\n"); \
  if (listGetForward((List*) node->value, "key9") == NULL) { \
    printLog(ERR, "key9 did not appear in myList3.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting myList4 from myList3.\n"); \
  node = listGetForward((List*) node->value, "myList4"); \
  printLog(INFO, "node = %p\n", node); \
  if (node == NULL) { \
    printLog(ERR, "myList4 did not appear in myList3.\n"); \
    return false; \
  } \
  printLog(INFO, "node->type = %p\n", node->type); \
  if (node->type != typeList) { \
    printLog(ERR, "myList4 type was wrong.\n"); \
    printLog(ERR, "myList4 was of type %lld instead of typeList.\n", \
      lld(getIndexFromTypeDescriptor(node->type))); \
    return false; \
  } \
  printLog(INFO, "Getting key7 from myList4.\n"); \
  if (listGetForward((List*) node->value, "key7") == NULL) { \
    printLog(ERR, "key7 did not appear in myList4.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting key8 from myList4.\n"); \
  if (listGetForward((List*) node->value, "key8") == NULL) { \
    printLog(ERR, "key8 did not appear in myList4.\n"); \
    return false; \
  } \
 \
  printLog(INFO, "Getting myList1 from parsed list.\n"); \
  node = listGetReverse(list, "myList1"); \
  if (node == NULL) { \
    printLog(ERR, "myList1 did not appear in parsed list.\n"); \
    return false; \
  } \
  if (node->type != typeList) { \
    printLog(ERR, "myList1 was of type %lld instead of typeList.\n", \
      lld(getIndexFromTypeDescriptor(node->type))); \
    return false; \
  } \
  printLog(INFO, "Getting key1 from myList1.\n"); \
  if (listGetReverse((List*) node->value, "key1") == NULL) { \
    printLog(ERR, "key1 did not appear in myList1.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting key2 from myList1.\n"); \
  if (listGetReverse((List*) node->value, "key2") == NULL) { \
    printLog(ERR, "key2 did not appear in myList1.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting key3 from parsed list.\n"); \
  node = listGetReverse(list, "key3"); \
  if (node == NULL) { \
    printLog(ERR, "key3 did not appear in parsed list.\n"); \
    return false; \
  } \
  if (strcmp("value3", (char*) node->value) != 0) { \
    printLog(ERR, "Expected value of key3 to be value3, got \"%s\".\n", \
      (char*) node->value); \
    return false; \
  } \
  printLog(INFO, "Getting myList2 from parsed list.\n"); \
  node = listGetReverse(list, "myList2"); \
  if (node == NULL) { \
    printLog(ERR, "myList2 did not appear in parsed list.\n"); \
    return false; \
  } \
  if (node->type != typeList) { \
    printLog(ERR, "myList2 was of type %lld instead of typeList.\n", \
      lld(getIndexFromTypeDescriptor(node->type))); \
    return false; \
  } \
  printLog(INFO, "Getting key4 from myList2.\n"); \
  if (listGetReverse((List*) node->value, "key4") == NULL) { \
    printLog(ERR, "key4 did not appear in myList2.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting key5 from myList2.\n"); \
  if (listGetReverse((List*) node->value, "key5") == NULL) { \
    printLog(ERR, "key5 did not appear in myList2.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting key6 from myList2.\n"); \
  if (listGetReverse((List*) node->value, "key6") == NULL) { \
    printLog(ERR, "key6 did not appear in myList2.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting myList3 from parsed list.\n"); \
  node = listGetReverse(list, "myList3"); \
  if (node == NULL) { \
    printLog(ERR, "myList3 did not appear in parsed list.\n"); \
    return false; \
  } \
  if (node->type != typeList) { \
    printLog(ERR, "myList3 was of type %lld instead of typeList.\n", \
      lld(getIndexFromTypeDescriptor(node->type))); \
    return false; \
  } \
  printLog(INFO, "Getting key9 from myList3.\n"); \
  if (listGetReverse((List*) node->value, "key9") == NULL) { \
    printLog(ERR, "key9 did not appear in myList3.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting myList4 from myList3.\n"); \
  node = listGetReverse((List*) node->value, "myList4"); \
  printLog(INFO, "node = %p\n", node); \
  if (node == NULL) { \
    printLog(ERR, "myList4 did not appear in myList3.\n"); \
    return false; \
  } \
  printLog(INFO, "node->type = %p\n", node->type); \
  if (node->type != typeList) { \
    printLog(ERR, "myList4 type was wrong.\n"); \
    printLog(ERR, "myList4 was of type %lld instead of typeList.\n", \
      lld(getIndexFromTypeDescriptor(node->type))); \
    return false; \
  } \
  printLog(INFO, "Getting key7 from myList4.\n"); \
  if (listGetReverse((List*) node->value, "key7") == NULL) { \
    printLog(ERR, "key7 did not appear in myList4.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting key8 from myList4.\n"); \
  if (listGetReverse((List*) node->value, "key8") == NULL) { \
    printLog(ERR, "key8 did not appear in myList4.\n"); \
    return false; \
  } \
 \
  int value = 10; \
  node = listAddBackEntry(list, "key10", &value, typeI32); \
  if (node == NULL) { \
    printLog(ERR, "listAdd of key10 failed.\n"); \
    return false; \
  } \
  bool boolean = true; \
  node = listAddBackEntry(list, "key11", &boolean, typeBool); \
  if (node == NULL) { \
    printLog(ERR, "listAdd of key11 failed.\n"); \
    return false; \
  } \
  Vector *vector = vectorCreate(typeString); \
  vectorSetEntry(vector, 0, "one", typeString); \
  vectorSetEntry(vector, 1, "two", typeString); \
  vectorSetEntry(vector, 2, "three", typeString); \
  node = listAddBackEntry(list, "key12", vector, typeVectorNoCopy); \
  node->type = typeVector; \
 \
  Bytes listJson = listToJson(list); \
  printLog(INFO, "List JSON: %s\n", listJson); \
 \
  long long int jsonPosition = 0; \
  List *list2 = jsonToList(str(listJson), &jsonPosition); \
  Bytes list2Json = listToJson(list2); \
  if (bytesCompare(listJson, list2Json) != 0) { \
    printLog(ERR, \
      "list after serialization/deserialization to JSON did not match " \
      "original.\n"); \
    char *listString = listToString(list2); \
    printLog(ERR, "Second list:  %s\n", listString); \
    listString = stringDestroy(listString); \
    return false; \
  } \
  list2Json = bytesDestroy(list2Json); \
  listJson = bytesDestroy(listJson); \
 \
  list2 = listDestroy(list2); \
  list = listDestroy(list); \
 \
  jsonPosition = 0; \
  list2 = jsonToList("{\"key1\":\"value1\",\"key2\":false,\"key3\":null}", \
    &jsonPosition); \
  if (list2 == NULL) { \
    printLog(ERR, "Could not convert unformatted JSON to list.\n"); \
    return false; \
  } \
  list2 = listDestroy(list2); \
 \
  return true; \
}
LIST_UNIT_TEST

