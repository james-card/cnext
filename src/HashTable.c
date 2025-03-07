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

#ifdef DS_LOGGING_ENABLED
#include "LoggingLib.h"
#else
#undef printLog
#define printLog(...) {}
#define logFile stderr
#define LOG_MALLOC_FAILURE(...) {}
#endif

#include "StringLib.h"
#include "HashTable.h"
#include "Vector.h"
#include "Scope.h"

/// @fn HashTable *htCreate_(TypeDescriptor *keyType, bool disableThreadSafety, u64 size, ...)
///
/// @brief Create a hash table with the specified type as the key.
///
/// @param keyType The TypeDescriptor representing the kind of key to use.
/// @param disableThreadSafety Whether or not to disable thread safety for the
///   HashTable.
/// @param size The minimum size for the hash table.
/// @param ... Ignored parameters.
///
/// @note This function is wrapped by a macro of the same name (minus the
/// trailing underscore) that automatically provides false for
/// disableThreadSafety and 0 for the size.
///
/// @return Returns a pointer to a new hash table on success, NULL on failure.
HashTable *htCreate_(TypeDescriptor *keyType, bool disableThreadSafety, u64 size, ...) {
  printLog(TRACE, "ENTER htCreate(keyType=%s)\n", (keyType != NULL) ? keyType->name : "NULL");
  
  // Make sure we have sensible parameters.
  if (keyType == NULL) {
    printLog(ERR, "NULL keyType provided to htCreate.  Cannot create table.\n");
    printLog(TRACE, "EXIT htCreate(keyType=%s) = {NULL}\n", "NULL");
    return NULL;
  }
  
  // Allocate all the memory...
  HashTable *table = (HashTable*) calloc(1, sizeof(HashTable));
  if (size == 0) {
    table->tableSize = OPTIMAL_HASH_TABLE_SIZE;
  } else if (size < REGISTER_BIT_WIDTH) {
    table->tableSize = REGISTER_BIT_WIDTH;
  } else {
    table->tableSize = size;
  }
  table->table = (RedBlackTree**)
    calloc(1, table->tableSize * sizeof(RedBlackTree*));
  
  // Initialize everything that shouldn't be NULL.
  table->keyType = keyType;
  if (disableThreadSafety == false) {
    table->lock = (mtx_t*) calloc(1, sizeof(mtx_t));
    if (mtx_init(table->lock, mtx_plain | mtx_recursive) != thrd_success) {
      printLog(ERR, "Could not initialize table mutex lock.\n");
    }
  }
  
  printLog(TRACE, "EXIT htCreate(keyType=%s) = {%p}\n", keyType->name, table);
  return table;
}

/// @fn HashTable* htDestroy(HashTable *table)
///
/// @brief Deallocate a previously allocated hash table and all associated
///   metadata.
///
/// @param table The table to deallocate.
///
/// @return NULL on success, pointer to the table on failure.
HashTable* htDestroy(HashTable *table) {
  printLog(TRACE, "ENTER htDestroy(table=%p)\n", table);
  
  if (table == NULL) {
    // Don't print out an error here.  Just return silently.
    
    printLog(TRACE, "EXIT htDestroy(table=%p) = {NULL}\n", table);
    return NULL;
  }
  
  // Make sure we're not deleting while someone else is accessing.
  if ((table->lock != NULL) && (mtx_lock(table->lock) != thrd_success)) {
    printLog(WARN, "Could not lock table mutex.\n");
  }
  
  // Destroy the allocated red-black trees.
  for (u64 i = 0; i < table->tableSize; i++) {
    if (table->table[i] != NULL) {
      rbTreeDestroy(table->table[i]);
    }
  }
  
  table->table = (RedBlackTree**) pointerDestroy(table->table);
  
  if (table->filePointer != NULL) {
    fclose(table->filePointer); table->filePointer = NULL;
  }
  
  if (table->lock != NULL) {
    mtx_unlock(table->lock);
  }
  if (table->lock != NULL) {
    mtx_destroy(table->lock);
  }
  table->lock = (mtx_t*) pointerDestroy(table->lock);
  
  table = (HashTable*) pointerDestroy(table);
  
  printLog(TRACE, "EXIT htDestroy(table=%p) = {NULL}\n", table);
  return NULL;
}

/// @fn u6y4 htGetHash(const HashTable *table, const volatile void *rawKey)
///
/// @brief Calculate a hash value of a provided key.  This is an
/// implementation of the Jenkins one_at_a_time hash function, described
/// at https://en.wikipedia.org/wiki/Jenkins_hash_function
///
/// @param table is the table of interest.
/// @param rawKey is the key of interest.
///
/// @return Returns an integer value representing the hash of the key mod the
///   number of entries in the hash table.
u64 htGetHash(const HashTable *table, const volatile void *rawKey) {
  printLog(TRACE, "ENTER htGetHash(table=%p, rawKey=%p)\n", table, rawKey);
  
  u64 length = 0;
  Bytes key = NULL;
  bool keyCopied = false;
  u64 hash = 0;
  
  if ((table == NULL) || (rawKey == NULL)) {
    printLog(TRACE, "EXIT htGetHash(table=%p, rawKey=%p) = {%llu}\n",
      table, rawKey, 0ULL);
    return 0;
  }
  
  if (table->keyType->hashFunction != NULL) {
    u64 returnValue
      = table->keyType->hashFunction(rawKey) % table->tableSize;
    printLog(DEBUG, "tableSize = %llu\n", llu(table->tableSize));
    printLog(TRACE, "EXIT htGetHash(table=%p, rawKey=%p) = {%llu}\n",
      table, rawKey, llu(returnValue));
    return returnValue;
  }
  
  i64 keyTypeIndex = getIndexFromTypeDescriptor(table->keyType);
  if ((keyTypeIndex < getIndexFromTypeDescriptor(typeList)) && (keyTypeIndex > 0)
  ) { // key type is primitive
    key = (Bytes) rawKey;
    length = table->keyType->size(rawKey);
  } else { // key type is non-primitive
    key = table->keyType->toBlob(rawKey);
    length = bytesLength(key);
    keyCopied = true;
  }
  
  for (u64 i = 0; i != length; ++i) {
    hash += key[i];
    hash += hash << 10;
    hash ^= hash >> 6;
  }
   
  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 15;
  
  u64 returnValue = hash % table->tableSize;
  
  if (keyCopied == true) {
    key = bytesDestroy(key);
  }
  
  printLog(TRACE, "EXIT htGetHash(table=%p, rawKey=%p) = {%llu}\n",
    table, rawKey, llu(returnValue));
  return returnValue;
}

/// @fn static int updateTreeLinks(HashTable *table, u64 index)
///
/// @brief Fix the links of a table when a tree is updated.
///
/// @param table The HashTable to update.
/// @param index The index of the RedBlackTree that was updated.
///
/// @return Returns 0 on success, -1 on failure.
int updateTreeLinks(HashTable *table, u64 index) {
  printLog(TRACE, "ENTER updateTreeLinks(table=%p, index=%llu)\n", table, llu(index));
  
  // This function is only called from htAddEntry, which guarantees that the
  // arguments are correct, so no need to check them.  We also are guaranteed
  // that there's at least one other tree in the table, so no need to check for
  // that either.
  
  // When a RedBlackTree has a new node inserted, tree->head->prev will be
  // NULL if the newly-inserted node is the new tree->head and tree->tail->next
  // will be NULL if the newly-inserted node is the new tree->tail.  If niether
  // is NULL, we have nothing to do.
  RedBlackTree *tree = table->table[index];
  if ((tree->head->prev != NULL) && (tree->tail->next != NULL)) {
    // All is well.  Exit.
    printLog(TRACE, "EXIT updateTreeLinks(table=%p, index=%llu) = {%d}\n",
      table, llu(index), 0);
    return 0;
  }
  
  HashNode *prev = NULL;
  HashNode *next = NULL;
  
  if (tree->tail->next == NULL) {
    u64 tableSize = table->tableSize;
    for (u64 i = index + 1; i < tableSize; i++) {
      if (table->table[i] != NULL) {
        next = table->table[i]->head;
        prev = next->prev;
        break;
      }
    }
    
    if (next != NULL) {
      tree->tail->next = next;
      next->prev = tree->tail;
    }
    
    if (prev != NULL) {
      tree->head->prev = prev;
      prev->next = tree->head;
    }
  }
  
  if ((tree->head->prev == NULL) && (index > 0)) {
    for (u64 i = index - 1; i > 0; i--) {
      if (table->table[i] != NULL) {
        prev = table->table[i]->tail;
        next = prev->next;
        break;
      }
    }
    
    if (prev == NULL) {
      // Check index 0.
      if (table->table[0] != NULL) {
        prev = table->table[0]->tail;
        next = prev->next;
      }
    }
    
    if (prev != NULL) {
      tree->head->prev = prev;
      prev->next = tree->head;
    }
    
    if (next != NULL) {
      tree->tail->next = next;
      next->prev = tree->tail;
    }
  }
  
  printLog(TRACE, "EXIT updateTreeLinks(table=%p, index=%llu) = {%d}\n", table, llu(index), 0);
  return 0;
}

/// @fn HashNode *htAddEntry_(HashTable *table, const volatile void *key, const volatile void *value, TypeDescriptor *type, ...)
///
/// @brief Add a new entry (key-value pair) to an existing hash table.
///
/// @param table is the hash table to add a new entry into.
/// @param key is the key for the entry.
/// @param value is the value for the entry.
/// @param type is the TypeDescriptor used to describe the value provided.
///
/// @note This function is wrapped by a define of the same name, minus the
/// leading underscore.  The type parameter is optional when the define is
/// used.
///
/// @return Returns a pointer to the new HashNode created on success, NULL
///   on failure.
HashNode *htAddEntry_(HashTable *table, const volatile void *key,
  const volatile void *value, TypeDescriptor *type, ...
) {
  printLog(TRACE, "ENTER htAddEntry(table=%p, key=%p, value=%p, type=%s)\n",
    table, key, value, (type != NULL) ? type->name : "NULL");
  
  // Parameter check
  if (table == NULL) {
    printLog(ERR, "NULL table provided.\n");
    printLog(TRACE,
      "EXIT htAddEntry(table=%p, key=%p, value=%p, type=%s) = {%p}\n",
      table, key, value, (type != NULL) ? type->name : "NULL", (void*) NULL);
    return NULL;
  }
  if (key == NULL) {
    printLog(ERR, "NULL key provided.\n");
    printLog(TRACE,
      "EXIT htAddEntry(table=%p, key=%p, value=%p, type=%s) = {%p}\n",
      table, key, value, (type != NULL) ? type->name : "NULL", (void*) NULL);
    return NULL;
  }
  if (type == NULL) {
    if (table->lastAddedType != NULL) {
      type = table->lastAddedType;
      printLog(DEBUG, "Defaulting to type of last added element.\n");
    } else {
      type = table->keyType;
      printLog(DEBUG, "Defaulting to type of key.\n");
    }
  }
  
  if ((table->lock != NULL) && (mtx_lock(table->lock) != thrd_success)) {
    printLog(WARN, "Could not lock table mutex.\n");
  }
  
  u64 index = htGetHash(table, key);
  if (table->table[index] == NULL) {
    table->table[index] = rbTreeCreate(table->keyType);
  }
  
  // Make sure the head and tail finding algorithm can work correctly.
  // The trees get linked when an iterator is requested.
  RedBlackNode *prev = NULL;
  RedBlackNode *next = NULL;
  
  if (table->table[index]->head != NULL) {
    prev = table->table[index]->head->prev;
  }
  if (table->table[index]->tail != NULL) {
    next = table->table[index]->tail->next;
  }
  
  RedBlackNode *node = rbInsert(table->table[index], key, value, type);
  if (node == NULL) {
    printLog(ERR, "NULL node returned from rbInsert.\n");
    if (table->lock != NULL) {
      mtx_unlock(table->lock);
    }
    
    printLog(TRACE,
      "EXIT htAddEntry(table=%p, key=%p, value=%p, type=%s) = {%p}\n",
      table, key, value, type->name, (void*) NULL);
    return NULL;
  }
  
  // If we made it this far then the add was successful.  Record the type for
  // future use if desired.
  table->lastAddedType = type;
  
  table->table[index]->head->prev = prev;
  if (prev != NULL) {
    prev->next = table->table[index]->head;
  }
  table->table[index]->tail->next = next;
  if (next != NULL) {
    next->prev = table->table[index]->tail;
  }
  
  table->size++;
  if ((table->table[index]->size == 1) && (table->size != 1)) {
    // New tree and other trees present.  Update links around the tree.
    updateTreeLinks(table, index);
  }
  
  if (table->table[index]->head->prev == NULL) {
    // tree->head is the head of the table.
    table->head = table->table[index]->head;
  }
  if (table->table[index]->tail->next == NULL) {
    // tree->tail is the tail of the table.
    table->tail = table->table[index]->tail;
  }
  
  if (table->lock != NULL) {
    mtx_unlock(table->lock);
  }
  
  printLog(TRACE,
    "EXIT htAddEntry(table=%p, key=%p, value=%p, type=%s) = {%p}\n",
    table, key, value, type->name, node);
  return node;
}

/// @fn HashNode *htGetEntry(const HashTable *table, const volatile void *key)
///
/// @brief Retrieve a previously-added entry from a hash table.
///
/// @param table is the hash table of interest.
/// @param key is the key for the value of interest.
///
/// @return Returns the matching HashNode on success, NULL on failure.
HashNode *htGetEntry(const HashTable *table, const volatile void *key) {
  printLog(TRACE, "ENTER htGetEntry(table=%p, key=%p)\n", table, key);
  
  if (table == NULL) {
    printLog(TRACE, "EXIT htGetEntry(table=%p, key=%p) = {%p}\n", table, key, (void*) NULL);
    return NULL;
  }
  
  if ((table->lock != NULL) && (mtx_lock(table->lock) != thrd_success)) {
    printLog(WARN, "Could not lock table mutex.\n");
  }
  
  u64 index = htGetHash(table, key);
  printLog(DEBUG, "Getting value from tree %llu.\n", llu(index));
  HashNode *returnValue = rbQuery(table->table[index], key);
  
  if (table->lock != NULL) {
    mtx_unlock(table->lock);
  }
  
  printLog(TRACE, "EXIT htGetEntry(table=%p, key=%p) = {%p}\n", table, key, returnValue);
  return returnValue;
}

/// @fn void *htGetValue(const HashTable *table, const volatile void *key)
///
/// @brief Get the value of a HashNode, if any.
///
/// @param table is the hash table of interest.
/// @param key is the key for the value of interest.
///
/// @return Returns the value of the corresponding HashNode on success, NULL on
/// failure.
void *htGetValue(const HashTable *table, const volatile void *key) {
  printLog(TRACE, "ENTER htGetValue(table=%p, key=%p)\n", table, key);
  
  void *returnValue = NULL;
  HashNode *node = htGetEntry(table, key);
  if (node != NULL) {
    returnValue = (void*) node->value;
  }
  
  printLog(TRACE, "EXIT htGetValue(table=%p, key=%p) = {%p}\n",
    table, key, returnValue);
  return returnValue;
}

/// @fn i32 htRemoveEntry(HashTable *table, const volatile void *key)
///
/// @brief Remove a previously-added entry from a hash table.
///
/// @param table is the table to remove the entry from.
/// @param key is the key of the value to remove.
///
/// @return Returns 0 on success.  Any other value is failure.
i32 htRemoveEntry(HashTable *table, const volatile void *key) {
  printLog(TRACE, "ENTER htRemoveEntry(table=%p, key=%p)\n", table, key);
  
  if (table == NULL) {
    printLog(ERR, "NULL table provided.\n");
    printLog(TRACE, "EXIT htRemoveEntry(table=%p, key=%p) = {-1}\n", table, key);
    return -1;
  }
  if (key == NULL) {
    printLog(ERR, "NULL key provided.\n");
    printLog(TRACE, "EXIT htRemoveEntry(table=%p, key=%p) = {-1}\n", table, key);
    return -1;
  }

  if ((table->lock != NULL) && (mtx_lock(table->lock) != thrd_success)) {
    printLog(WARN, "Could not lock table mutex.\n");
  }
  
  u64 index = htGetHash(table, key);
  RedBlackTree *tree = NULL;
  
  tree = table->table[index];
  if (tree != NULL) {
    RedBlackNode *node = rbQuery(tree, key);
    if (node != NULL) {
      if (table->head == node) {
        table->head = node->next;
      }
      if (table->tail == node) {
        table->tail = node->prev;
      }
      table->size--;
    }
    rbTreeRemove(tree, key);
    if (tree->size == 0) {
      rbTreeDestroy(tree);
      table->table[index] = NULL;
    }
  }
  
  if (table->lock != NULL) {
    mtx_unlock(table->lock);
  }
  
  printLog(TRACE, "EXIT htRemoveEntry(table=%p, key=%p) = {0}\n", table, key);
  return 0;
}

/// @fn char *htToString(const HashTable *table)
///
/// @brief Create a string representation of the hash table.
///
/// @param table The table to represent as a string.
///
/// @return Returns a C string representing the table on success,
///   NULL on failure.
char *htToString(const HashTable *table) {
  printLog(TRACE, "ENTER htToString(table=%p)\n", table);
  
  char *returnValue = NULL;
  
  if (table == NULL) {
    straddstr(&returnValue, "");
    printLog(TRACE, "EXIT htToString(table=%p) = {%s}\n", table, returnValue);
    return returnValue;
  }
  
  if ((table->lock != NULL) && (mtx_lock(table->lock) != thrd_success)) {
    printLog(WARN, "Could not lock table mutex.\n");
  }
  
  if (asprintf(&returnValue, "size=%llu\ntableSize=%llu\n",
    llu(table->size), llu(table->tableSize)) < 0
  ) {
    printLog(ERR, "Cannot allocate memory for return value.\n");
    printLog(TRACE, "EXIT htToString(table=%p) = {%p}\n", table, returnValue);
    return returnValue;
  }
  
  u64 numTablesPrinted = 0;
  for (u64 i = 0; i < table->tableSize; i++) {
    if (table->table[i] != NULL) {
      if (numTablesPrinted > 0) {
        straddstr(&returnValue, "\n");
      }
      
      char *indexString = NULL;
      if (asprintf(&indexString, "table[%llu]={\n", llu(i)) > 0) {
        straddstr(&returnValue, indexString);
        indexString = stringDestroy(indexString);
      }
      char *treeString = rbTreeToString(table->table[i]);
      char *indentedTreeString = indentText(treeString, 2);
      treeString = stringDestroy(treeString);
      straddstr(&returnValue, indentedTreeString);
      indentedTreeString = stringDestroy(indentedTreeString);
      straddstr(&returnValue, "\n}");
      
      numTablesPrinted++;
    }
  }
  
  if (table->lock != NULL) {
    mtx_unlock(table->lock);
  }
  
  char *indentedText = indentText(returnValue, 2);
  returnValue = stringDestroy(returnValue);
  asprintf(&returnValue, "{\n%s\n}", indentedText);
  indentedText = stringDestroy(indentedText);
  
  printLog(TRACE, "EXIT htToString(table=%p) = {%s}\n", table, returnValue);
  return returnValue;
}

/// @fn Bytes htToBytes(const HashTable *table)
///
/// @brief Create a Bytes representation of the hash table.
///
/// @param table The table to represent as a Bytes object.
///
/// @note If this function is successful, the output will be identical to that
///   of htToString.  That is by design.  This function is intended to be used
///   in other functions that convert data types to tabular representations and
///   those representations should be strings except for the fact that they must
///   be allocated as Bytes objects.
///
/// @return Returns a Bytes object representing the table on success,
///   NULL on failure.
Bytes htToBytes(const HashTable *table) {
  printLog(TRACE, "ENTER htToBytes(table=%p)\n", table);
  
  Bytes returnValue = NULL;
  
  if (table == NULL) {
    printLog(TRACE, "EXIT htToBytes(table=NULL) = {NULL}\n");
    return NULL;
  }
  
  if ((table->lock != NULL) && (mtx_lock(table->lock) != thrd_success)) {
    printLog(WARN, "Could not lock table mutex.\n");
  }
  
  bytesAddStr(&returnValue, "size=");
  Bytes tableSizeBytes = typeU64->toBytes(&table->size);
  bytesAddBytes(&returnValue, tableSizeBytes);
  tableSizeBytes = bytesDestroy(tableSizeBytes);
  bytesAddStr(&returnValue, "\n");
  
  for (u64 i = 0; i < table->tableSize; i++) {
    if (table->table[i] != NULL) {
      char *indexString = NULL;
      if (asprintf(&indexString, "table[%llu]={\n", llu(i)) > 0) {
        bytesAddStr(&returnValue, indexString);
        indexString = stringDestroy(indexString);
      }
      char *treeString = rbTreeToString(table->table[i]);
      char *indentedTreeString = indentText(treeString, 2);
      treeString = stringDestroy(treeString);
      bytesAddStr(&returnValue, indentedTreeString);
      indentedTreeString = stringDestroy(indentedTreeString);
      bytesAddStr(&returnValue, "}\n");
    }
  }
  
  if (table->lock != NULL) {
    mtx_unlock(table->lock);
  }
  
  printLog(TRACE, "EXIT htToBytes(table=%p) = {%s}\n", table, returnValue);
  return returnValue;
}

/// @fn HashTable *htCopy(const HashTable *table)
///
/// @brief Create a copy of an existing hash table.
///
/// @param table is the hash table to copy.  It is not modified.
///
/// @return Returns a newly-allocated copy of the input hash table on success,
///   NULL on failure.
HashTable *htCopy(const HashTable *table) {
  printLog(TRACE, "ENTER htCopy(table=%p)\n", table);
  
  HashTable *copy = NULL;
  
  if (table == NULL) {
    printLog(ERR, "HashTable provided is NULL.\n");
    printLog(TRACE, "EXIT htCopy(table=%p) = {%p}\n", table, copy);
    return copy;
  }
  
  bool disableThreadSafety = false;
  if (table->lock == NULL) {
    disableThreadSafety = true;
  }
  copy = htCreate(table->keyType, disableThreadSafety, table->tableSize);
  
  if ((table->lock != NULL) && (mtx_lock(table->lock) != thrd_success)) {
    printLog(WARN, "Could not lock table mutex.\n");
  }
  
  for (HashNode *cur = table->head; cur != NULL; cur = cur->next) {
    htAddEntry(copy, cur->key, cur->value, cur->type);
  }
  
  if (table->lock != NULL) {
    mtx_unlock(table->lock);
  }
  
  printLog(TRACE, "EXIT htCopy(table=%p) = {%p}\n", table, copy);
  return copy;
}

/// @fn int htCompare(const HashTable *htA, const HashTable *htB)
///
/// @brief Compare the contents of two hash tables.
///
/// @param htA,htB are the hash tables to compare.
///
/// @return Returns 0 if the contents are the same, non-zero otherwise.
///
/// @note Non-zero return values from this function are meaningless other than
///   that they express that the two tables are not the same.  There is no
///   standard for evaluating meaning of non-zero values otherwise.
int htCompare(const HashTable *htA, const HashTable *htB) {
  printLog(TRACE, "ENTER htCompare(htA=%p, htB=%p)\n", htA, htB);
  
  int returnValue = listCompare((List*) htA, (List*) htB);
  
  printLog(TRACE, "EXIT htCompare(htA=%p, htB=%p) = {%d}\n", htA, htB, returnValue);
  return returnValue;
}

/// @fn HashTable *xmlToHashTable(const char *inputData)
///
/// @brief Take SOAP data and return a hash table of key-value objects.
///
/// @param inputData is the full data string from a POST call.
///
/// @return Returns a HashTable containing the data parsed.
HashTable *xmlToHashTable(const char *inputData) {
  char *separatorAt = NULL;
  char *hashTableString = NULL, *indentedHashTableString = NULL;
  HashTable *hashTable= NULL;
  char *key = NULL;
  Bytes value = NULL;
  char *xmlString = NULL;
  
  printLog(TRACE, "ENTER xmlToHashTable(inputData=\"%s\")\n", inputData);
  
  if (inputData == NULL) {
    printLog(ERR, "NULL inputData provided.\n");
    printLog(TRACE, "EXIT xmlToHashTable(inputData=NULL) = {NULL}\n");
    return NULL;
  }
  
  const char *startAt = &(inputData[strspn(inputData, " \t\n")]);
  if (*startAt != '<') {
    printLog(DEBUG, "No XML provided.\n");
    printLog(TRACE, "EXIT xmlToHashTable(inputData=NULL) = {NULL}\n");
    return NULL;
  }
  straddstr(&xmlString, startAt);
  
  hashTable = htCreate(typeString);
  
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
        HashTable *subTable = xmlToHashTable(xmlValue);
        xmlValue = stringDestroy(xmlValue);
        HashNode *node = htAddEntry(hashTable, key, subTable,
          typeHashTableNoCopy);
        if (node == NULL) {
          printLog(ERR, "htAddEntry failed when adding key/table pair.\n");
        } else {
          node->type = typeHashTable;
        }
      }
    } else {
      // No end of tag?  Is this possible?
    }
    
    if (value != NULL) {
      HashNode *node = htAddEntry(hashTable, key, value, typeBytesNoCopy);
      if (node != NULL) {
        node->type = typeBytes;
      } else {
        printLog(ERR, "htAddEntry failed when adding key/value pair.\n");
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
  hashTableString = htToString(hashTable);
  indentedHashTableString = indentText(hashTableString, 2);
  hashTableString = stringDestroy(hashTableString);
  printLog(TRACE, "EXIT xmlToHashTable(inputData=\"%s\") = {%s}\n", inputData, indentedHashTableString);
  indentedHashTableString = stringDestroy(indentedHashTableString);
  return hashTable;
}

/// @fn size_t htSize(const volatile void *value)
///
/// @brief Compute the size of a hash table structure in memory.
///
/// @return Returns the size of the table in bytes.
size_t htSize(const volatile void *value) {
  size_t size = 0;
  HashTable *table = (HashTable*) value;
  printLog(TRACE, "ENTER htSize(value=\"%p\")\n", value);
  
  if (table != NULL) {
    size = sizeof(HashTable);
  }
  
  printLog(TRACE, "EXIT htSize(value=\"%p\") = {%llu}\n", value, llu(size));
  return size;
}

/// @fn HashTable *htFromBlob_(const volatile void *array, u64 *length, bool inPlaceData, bool disableThreadSafety, ...)
///
/// @brief Convert a properly-formatted byte array into a hash table.
///
/// @param array The array of bytes to convert.
/// @param length As an input, this is the number of bytes in array.  As an
///   output, this is the number of bytes consumed by this call.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned list.
///
/// @return Returns a pointer to a HashTable on success, NULL on failure.
HashTable *htFromBlob_(const volatile void *array, u64 *length, bool inPlaceData, bool disableThreadSafety, ...) {
  char *byteArray = (char*) array;
  HashTable *table = NULL;
  u64 index = 0;
  i16 typeIndex = 0, keyTypeIndex = 0;
  printLog(TRACE,
    "ENTER htFromBlob(array=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    array, length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  u64 size = 0;
  TypeDescriptor *keyType = NULL, *keyTypeNoCopy = NULL;
  
  if ((array == NULL) || (length == NULL)) {
    printLog(ERR, "One or more NULL parameters.\n");
    printLog(TRACE,
      "EXIT htFromBlob(array=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      table, length, boolNames[inPlaceData], boolNames[disableThreadSafety], table);
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
    printLog(ERR, "Improperly formatted byte array.  Cannot create table.\n");
    printLog(TRACE,
      "EXIT htFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], table);
    return NULL;
  }
  keyType = getTypeDescriptorFromIndex(keyTypeIndex);
  if (keyType == NULL) {
    printLog(ERR, "No value type for typeIndex %d.\n", keyTypeIndex);
    *length = index;
    printLog(ERR, "Improperly formatted byte array.  Cannot create table.\n");
    printLog(TRACE,
      "EXIT htFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], table);
    return NULL;
  }
  keyTypeNoCopy = getTypeDescriptorFromIndex(keyTypeIndex + 1);
  
  size = *((u64*) &byteArray[index]);
  littleEndianToHost(&size, sizeof(size));
  index += sizeof(size);
  table = htCreate(keyTypeNoCopy, disableThreadSafety, size);
  if (table == NULL) {
    LOG_MALLOC_FAILURE();
    printLog(NEVER,
      "EXIT htFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], table);
    return NULL;
  }
  
  // Complex data types (which will have type indexes greater than or equal
  // to that of typeList) will need to be handled slightly differently than
  // primitives in the case that inPlaceData is true, so grab the index for
  // typeList now so that we can compare it later.
  i64 listIndex = getIndexFromTypeDescriptor(typeList);
  
  HashNode *node = NULL;
  while ((index < arrayLength) && (table->size < size)) {
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
        "EXIT htFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
        array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], table);
      if (inPlaceData) {
        // Optimize for this case.
        if (keyTypeIndex >= listIndex) {
          // See notes at the bottom of this function about this logic.
          htSetKeyType(table, keyType);
        }
      } else {
        htSetKeyType(table, keyType);
      }
      return table;
    }
    valueType = getTypeDescriptorFromIndex(typeIndex);
    if (valueType != NULL) {
      printLog(DEBUG, "Adding value of type %s.\n", valueType->name);
    } else {
      printLog(ERR, "No value type for typeIndex %d.\n", typeIndex);
      *length = index;
      printLog(ERR,
        "Improperly formatted byte array.  Cannot continue processing\n");
      printLog(TRACE,
        "EXIT htFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
        array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], table);
      if (inPlaceData) {
        // Optimize for this case.
        if (keyTypeIndex >= listIndex) {
          // See notes at the bottom of this function about this logic.
          htSetKeyType(table, keyType);
        }
      } else {
        htSetKeyType(table, keyType);
      }
      return table;
    }
    valueTypeNoCopy = getTypeDescriptorFromIndex(typeIndex + 1);
    index += sizeof(i16);
    valueSize = arrayLength - index;
    
    value = valueType->fromBlob(&byteArray[index], &valueSize, inPlaceData, disableThreadSafety);
    index += valueSize;
    if (value == NULL) {
      *length = index;
      printLog(ERR, "NULL value detected.  Cannot process.\n");
      printLog(TRACE,
        "EXIT htFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
        array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], table);
      if (inPlaceData) {
        // Optimize for this case.
        if (keyTypeIndex >= listIndex) {
          // See notes at the bottom of this function about this logic.
          htSetKeyType(table, keyType);
        }
      } else {
        htSetKeyType(table, keyType);
      }
      return table;
    }
    
    keySize = arrayLength - index;
    key = keyType->fromBlob(&byteArray[index], &keySize, inPlaceData, disableThreadSafety);
    index += keySize;
    if (key == NULL) {
      *length = index;
      printLog(ERR, "NULL key detected.  Cannot process.\n");
      printLog(TRACE,
        "EXIT htFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
        array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], table);
      if (inPlaceData) {
        // Optimize for this case.
        if (keyTypeIndex >= listIndex) {
          // See notes at the bottom of this function about this logic.
          htSetKeyType(table, keyType);
        }
      } else {
        htSetKeyType(table, keyType);
      }
      return table;
    }
    
    node = htAddEntry(table, key, value, valueTypeNoCopy);
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
      printLog(ERR, "Failed to add node to table.\n");
    }
  }
  if (table->size < size) {
    printLog(ERR, "Expected %llu entries, but only found %llu.\n",
      llu(size), llu(table->size));
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
      htSetKeyType(table, keyType);
    }
  } else {
    htSetKeyType(table, keyType);
  }
  
  printLog(TRACE,
    "EXIT htFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], table);
  return table;
}

/// @fn HashTable* listToHashTable(List *list)
///
/// @brief Convert a list (or compatible type) to a HashTable.
///
/// @param list A pointer to the List to convert.
///
/// @return Returns a pointer to a new HashTable on success, NULL on failure.
HashTable* listToHashTable(List *list) {
  printLog(TRACE, "ENTER listToHashTable(list=%p)\n", list);
  
  if (list == NULL) {
    printLog(DEBUG, "List provided is NULL.\n");
    printLog(TRACE, "EXIT listToHashTable(list=%p) = {%p}\n",
      list, (void*) NULL);
    return NULL;
  }
  
  if ((list->lock != NULL) && (mtx_lock(list->lock) != thrd_success)) {
    printLog(WARN, "Could not lock list mutex.\n");
  }
  
  bool disableThreadSafety = false;
  if (list->lock == NULL) {
    disableThreadSafety = true;
  }
  HashTable *table = htCreate(list->keyType, disableThreadSafety, list->size);
  
  for (ListNode *node = list->head; node != NULL; node = node->next) {
    if (node->type != typeList) {
      htAddEntry(table, node->key, node->value, node->type);
    } else {
      HashNode *newNode = htAddEntry(table,
        node->key, listToHashTable((List*) node->value), typeHashTableNoCopy);
      newNode->type = typeHashTable;
    }
  }
  
  if (list->lock != NULL) {
    mtx_unlock(list->lock);
  }
  
  printLog(TRACE, "EXIT listToHashTable(list=%p) = {%p}\n", list, table);
  return table;
}

// jsonToHashTable implementation from generic macro.
JSON_TO_DATA_STRUCTURE(HashTable, ht)

/// @fn i32 htClear(HashTable *table)
///
/// @brief Destroy all the nodes of the HashTable (starting with table->head and
/// ending with table->tail), but do not destroy the HashTable object or any of its
/// other members.
///
/// @param table A pointer to a HashTable object to clear.
///
/// @return Returns 0 on success, -1 on failure.
i32 htClear(HashTable *table) {
  printLog(TRACE, "ENTER htClear(table=%p)\n", table);
  
  i32 returnValue = 0;
  if (table == NULL) {
    // No-op.
    printLog(TRACE, "EXIT htClear(table=%p) = {%d}\n", table, returnValue);
    return returnValue;
  }
  
  // Make sure we're not deleting while someone else is accessing.
  if ((table->lock != NULL) && (mtx_lock(table->lock) != thrd_success)) {
    printLog(WARN, "Could not lock table mutex.\n");
  }
  
  // Destroy the allocated red-black trees.
  for (u64 i = 0; i < table->tableSize; i++) {
    if (table->table[i] != NULL) {
      table->table[i] = rbTreeDestroy(table->table[i]);
    }
  }
  table->size = 0;
  table->head = NULL;
  table->tail = NULL;
  if (table->filePointer != NULL) {
    fclose(table->filePointer); table->filePointer = NULL;
  }
  
  if (table->lock != NULL) {
    mtx_unlock(table->lock);
  }
  
  printLog(TRACE, "EXIT htClear(table=%p) = {%d}\n", table, returnValue);
  return returnValue;
}

int htDestroyNode(HashTable *table, HashNode *node) {
  SCOPE_ENTER("table=%p, node=%p", table, node);
  
  int returnValue = 0;
  if ((table == NULL) || (node == NULL)) {
    printLog(ERR, "One or more NULL parameters.\n");
    returnValue = -1;
    SCOPE_EXIT("table=%p, node=%p", "%d", table, node, returnValue);
    return returnValue;
  }
  
  u64 index = htGetHash(table, node->key);
  printLog(DEBUG, "Destroying node in tree %llu.\n", llu(index));
  returnValue = rbTreeDestroyNode(table->table[index], node);
  
  SCOPE_EXIT("table=%p, node=%p", "%d", table, node, returnValue);
  return returnValue;
}

/// @var typeHashTable
///
/// @brief TypeDescriptor describing how libraries should interact with
///   hash table data.
TypeDescriptor _typeHashTable = {
  .name          = "HashTable",
  .xmlName       = NULL,
  .dataIsPointer = true,
  .toString      = (char* (*)(const volatile void*)) htToString,
  .toBytes       = (Bytes (*)(const volatile void*)) htToBytes,
  .compare       = (int (*)(const volatile void*, const volatile void*)) htCompare,
  .create        = (void* (*)(const volatile void*, ...)) htCreate_,
  .copy          = (void* (*)(const volatile void*)) htCopy,
  .destroy       = (void* (*)(volatile void*)) htDestroy,
  .size          = htSize,
  .toBlob        = (Bytes (*)(const volatile void*)) listToBlob,
  .fromBlob      = (void* (*)(const volatile void*, u64*, bool, bool)) htFromBlob_,
  .hashFunction  = NULL,
  .clear         = (i32 (*)(volatile void *)) listClear,
  .toXml         = (Bytes (*)(const volatile void*, const char *elementName, bool indent, ...)) listToXml_,
  .toJson        = (Bytes (*)(const volatile void*)) listToJson,
};
TypeDescriptor *typeHashTable = &_typeHashTable;

/// @var typeHashTableNoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with
///   hash table data that is not copied from its original source.
///
/// @details This exists because, by default, a copy of the input data is made
///   whenever a new data element is added to any data structure.  In some
///   situations, this is not desirable because the input serves no purpose
///   other than to be added to the data structure.  In such cases, this data
///   type may be specified to avoid the unnecessary copy.  The real
///   typeHashTable type can then be set after the data is added.
TypeDescriptor _typeHashTableNoCopy = {
  .name          = "HashTable",
  .xmlName       = NULL,
  .dataIsPointer = true,
  .toString      = (char* (*)(const volatile void*)) htToString,
  .toBytes       = (Bytes (*)(const volatile void*)) htToBytes,
  .compare       = (int (*)(const volatile void*, const volatile void*)) htCompare,
  .create        = (void* (*)(const volatile void*, ...)) htCreate_,
  .copy          = (void* (*)(const volatile void*)) shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = htSize,
  .toBlob        = (Bytes (*)(const volatile void*)) listToBlob,
  .fromBlob      = (void* (*)(const volatile void*, u64*, bool, bool)) htFromBlob_,
  .hashFunction  = NULL,
  .clear         = (i32 (*)(volatile void *)) listClear,
  .toXml         = (Bytes (*)(const volatile void*, const char *elementName, bool indent, ...)) listToXml_,
  .toJson        = (Bytes (*)(const volatile void*)) listToJson,
};
TypeDescriptor *typeHashTableNoCopy = &_typeHashTableNoCopy;

/// @def HASH_TABLE_UNIT_TEST
///
/// @brief Unit tests for hash table functionality.
/// @details Implementing this as a macro instead of raw code allows this to
/// be skipped by the code coverage metrics.
///
/// @return Returns true on success, false on failure.
#define HASH_TABLE_UNIT_TEST \
bool hashTableUnitTest() { \
  HashTable *hashTable = NULL, *hashTable2 = NULL; \
  u64 hashValue = 0; \
  HashNode *node = NULL; \
  char *stringValue = NULL; \
  Bytes byteArray = NULL; \
  u64 length = 0; \
 \
  printLog(INFO, "Testing HashTable data structure.\n"); \
 \
  hashTable = htCreate(NULL); \
  if (hashTable != NULL) { \
    printLog(ERR, "Expected NULL from htCreate, got %p\n", hashTable); \
    return false; \
  } \
 \
  hashTable = htCreate(typeString, false, 1); \
  if (hashTable == NULL) { \
    printLog(ERR, "Expected valid pointer from htCreate(typeString, false, 1), got " \
      "NULL\n"); \
    return false; \
  } \
 \
  htDestroy(NULL); \
  htDestroy(hashTable); hashTable = NULL; \
 \
  hashValue = htGetHash(NULL, NULL); \
  if (hashValue != 0) { \
    printLog(ERR, "Got invalid hash value from htGetHash.\n"); \
  } \
 \
  node = htAddEntry(NULL, NULL, NULL, NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from htAddEntry, got %p\n", node); \
    return false; \
  } \
  node = htAddEntry(NULL, "key", NULL, NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from htAddEntry, got %p\n", node); \
    return false; \
  } \
  node = htAddEntry(NULL, "key", "value", NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from htAddEntry, got %p\n", node); \
    return false; \
  } \
  node = htAddEntry(NULL, NULL, NULL, typeString); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from htAddEntry, got %p\n", node); \
    return false; \
  } \
 \
  node = htGetEntry(NULL, NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from htGetEntry, got %p\n", node); \
    return false; \
  } \
 \
  if (htRemoveEntry(NULL, NULL) >= 0) { \
    printLog(ERR, "htGetEntry succeeded with NULL table and key.\n"); \
    return false; \
  } \
 \
  stringValue = (char*) htGetValue(NULL, NULL); \
  if (stringValue != NULL) { \
    printLog(ERR, "Expected NULL from htGetValue, got %p\n", node); \
    return false; \
  } \
 \
  hashTable = xmlToHashTable(NULL); \
  if (hashTable != NULL) { \
    printLog(ERR, "Expected NULL from xmlToHashTable, got %p\n", hashTable); \
    return false; \
  } \
 \
  hashTable = htCreate(typeString); \
  if (hashTable == NULL) { \
    printLog(ERR, "Expected table from htCreate, got NULL\n"); \
    return false; \
  } \
 \
  hashValue = htGetHash(hashTable, NULL); \
  if (hashValue != 0) { \
    printLog(ERR, "Got invalid hash value from htGetHash.\n"); \
  } \
 \
  node = htAddEntry(hashTable, NULL, NULL, NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from htAddEntry, got %p\n", node); \
    return false; \
  } \
  node = htAddEntry(hashTable, NULL, NULL, typeString); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from htAddEntry, got %p\n", node); \
    return false; \
  } \
 \
  node = htGetEntry(hashTable, NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from htGetEntry, got %p\n", node); \
    return false; \
  } \
 \
  if (htRemoveEntry(hashTable, NULL) >= 0) { \
    printLog(ERR, "htGetEntry succeeded with NULL table and key.\n"); \
    return false; \
  } \
 \
  stringValue = (char*) htGetValue(hashTable, NULL); \
  if (stringValue != NULL) { \
    printLog(ERR, "Expected NULL from htGetValue, got %p\n", node); \
    return false; \
  } \
 \
  node = htAddEntry(hashTable, "key1", "value1", typeString); \
  if (node == NULL) { \
    printLog(ERR, "Expected valid node from htAddEntry for key1, got NULL\n"); \
    return false; \
  } \
  node = htAddEntry(hashTable, "key2", "value2", typeString); \
  if (node == NULL) { \
    printLog(ERR, "Expected valid node from htAddEntry for key2, got NULL\n"); \
    return false; \
  } \
  node = htAddEntry(hashTable, "key3", "value3"); \
  if (node == NULL) { \
    printLog(ERR, "Expected valid node from htAddEntry for key3, got NULL\n"); \
    return false; \
  } \
 \
  if (htRemoveEntry(hashTable, "key2") != 0) { \
    printLog(ERR, "htRemoveEntry for key2 did not succeed.\n"); \
    return false; \
  } \
 \
  List *list = htToList(hashTable); \
  if ((list == NULL) || (list->size == 0)) { \
    printLog(ERR, "htToList did not populate a list.\n"); \
    return false; \
  } \
  listDestroy(list); list = NULL; \
   \
  if (htCompare(hashTable, NULL) <= 0) { \
    printLog(ERR, "Populated hash table was not greater than NULL.\n"); \
    return false; \
  } \
  if (htCompare(NULL, hashTable) >= 0) { \
    printLog(ERR, "Populated hash table was not greater than NULL.\n"); \
    return false; \
  } \
  if (htCompare(NULL, NULL) != 0) { \
    printLog(ERR, "Populated hash table was not greater than NULL.\n"); \
    return false; \
  } \
 \
  hashTable2 = htCopy(NULL); \
  if (hashTable2 != NULL) { \
    printLog(ERR, "Copy of NULL hash table resulted in non-NULL hash table " \
      "copy."); \
    return false; \
  } \
  hashTable2 = htCopy(hashTable); \
  if (htCompare(hashTable, hashTable2) != 0) { \
    printLog(ERR, "hashTable and hashTable2 are not equal after htCopy.\n"); \
    return false; \
  } \
  htAddEntry(hashTable2, "key2", "value2"); \
  if (htCompare(hashTable, hashTable2) == 0) { \
    printLog(ERR, "hashTable and hashTable2 are equal after htAddEntry.\n"); \
    return false; \
  } \
  htRemoveEntry(hashTable, "key3"); \
  if (htCompare(hashTable, hashTable2) == 0) { \
    printLog(ERR, "hashTable and hashTable2 are equal after htRemoveEntry.\n"); \
    return false; \
  } \
  htDestroy(hashTable2); \
  hashTable2 = listToHashTable((List*) hashTable); \
  if (htCompare(hashTable, hashTable2) != 0) { \
    printLog(ERR, "hashTable and hashTable2 are not equal after listToHashTable.\n"); \
    return false; \
  } \
  htDestroy(hashTable2); \
  hashTable2 = htCreate(typeU32); \
  u32 u32Key = 4; \
  u32 u32Value = 5; \
  htAddEntry(hashTable2, &u32Key, &u32Value); \
  u32Key--; \
  htAddEntry(hashTable2, &u32Key, &u32Value); \
  if (htCompare(hashTable, hashTable2) == 0) { \
    printLog(ERR, "hashTable and hashTable2 are equal after new hashTable2 created.\n"); \
    return false; \
  } \
  htDestroy(hashTable2); \
 \
  byteArray = htToBlob(NULL); \
  if (byteArray != NULL) { \
    printLog(ERR, "byteArray not NULL after htToBlob(NULL)\n"); \
    return false; \
  } \
  byteArray = htToBlob(hashTable); \
  length = bytesLength(byteArray); \
  if (byteArray == NULL) { \
    printLog(ERR, "byteArray NULL after htToBlob(hashTable)\n"); \
    return false; \
  } \
  hashTable2 = htFromBlob(NULL, NULL); \
  if (hashTable2 != NULL) { \
    printLog(ERR, "hashTable2 not NULL after htFromBlob(NULL, NULL)\n"); \
    return false; \
  } \
  hashTable2 = htFromBlob(byteArray, NULL); \
  if (hashTable2 != NULL) { \
    printLog(ERR, "hashTable2 not NULL after htFromBlob(byteArray, NULL)\n"); \
    return false; \
  } \
  hashTable2 = htFromBlob(NULL, &length); \
  if (hashTable2 != NULL) { \
    printLog(ERR, "hashTable2 not NULL after htFromBlob(NULL, &length)\n"); \
    return false; \
  } \
  hashTable2 = htFromBlob(byteArray, &length); \
  if (hashTable2 == NULL) { \
    printLog(ERR, "hashTable2 NULL after htFromBlob(byteArray, &length)\n"); \
    return false; \
  } \
  byteArray = bytesDestroy(byteArray); \
  if (htCompare(hashTable, hashTable2) != 0) { \
    char *hashTableString = NULL; \
    printLog(ERR, "hashTable and hashTable2 are not equal after htFromBlob.\n"); \
    hashTableString = htToString(hashTable); \
    printLog(ERR, "hashTable = %s\n", hashTableString); \
    hashTableString = stringDestroy(hashTableString); \
    hashTableString = htToString(hashTable2); \
    printLog(ERR, "hashTable2 = %s\n", hashTableString); \
    hashTableString = stringDestroy(hashTableString); \
    return false; \
  } \
  htDestroy(hashTable2); \
 \
  int size = htSize(hashTable); \
  if (size == 0) { \
    printLog(ERR, "htSize returned 0 for non-empty hash table.\n"); \
    return false; \
  } \
   \
  htDestroy(hashTable); \
 \
  hashTable = htCreate(typeI32, false, 2048); \
  for (int i = 1; i < 100; i++) { \
    htAddEntry(hashTable, &i, &i); \
  } \
  for (int i = -1; i > -100; i--) { \
    htAddEntry(hashTable, &i, &i); \
  } \
  htDestroy(hashTable); \
 \
  hashTable = htCreate(typeI32); \
  for (int i = 1; i < 100; i++) { \
    htAddEntry(hashTable, &i, &i); \
  } \
  for (int i = -1; i > -100; i--) { \
    htAddEntry(hashTable, &i, &i); \
  } \
  list = htToList(hashTable); \
  if (list == NULL) { \
    printLog(ERR, "htToList did not populate a list.\n"); \
    return false; \
  } else if (list->size != 198) { \
    printLog(ERR, "htToList returned a %llu element list, expected 198 elements." \
      "\n", llu(list->size)); \
    i32 array[199] = {0}; \
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
  listDestroy(list); list = NULL; \
  htDestroy(hashTable); \
 \
  const char *xmlToParse = \
    "<hashTable>" \
      "<myHashTable1>" \
        "<key1>value1</key1>" \
        "<key2>value2</key2>" \
      "</myHashTable1>" \
      "<key3>value3</key3>" \
      "<myHashTable2>" \
        "<key4>value4</key4>" \
        "<key5>value5</key5>" \
        "<key6>value6</key6>" \
      "</myHashTable2>" \
      "<myHashTable3>" \
        "<myHashTable4>" \
          "<key7>value7</key7>" \
          "<key8>value8</key8>" \
        "</myHashTable4>" \
        "<key9>value9</key9>" \
      "</myHashTable3>" \
    "</hashTable>"; \
  printLog(INFO, "Parsing XML into list.\n"); \
  hashTable = xmlToHashTable(xmlToParse); \
  if (hashTable == NULL) { \
    printLog(ERR, "Could not parse XML into hash table.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting myHashTable1 from parsed list.\n"); \
  node = htGetEntry(hashTable, "myHashTable1"); \
  if (node == NULL) { \
    printLog(ERR, "myHashTable1 did not appear in parsed hash table.\n"); \
    return false; \
  } \
  if (node->type != typeHashTable) { \
    printLog(ERR, "myHashTable1 was of type %lld instead of typeHashTable.\n", \
      lld(getIndexFromTypeDescriptor(node->type))); \
    return false; \
  } \
  printLog(INFO, "Getting key1 from myHashTable1.\n"); \
  if (htGetEntry((HashTable*) node->value, "key1") == NULL) { \
    printLog(ERR, "key1 did not appear in myHashTable1.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting key2 from myHashTable1.\n"); \
  if (htGetEntry((HashTable*) node->value, "key2") == NULL) { \
    printLog(ERR, "key2 did not appear in myHashTable1.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting key3 from parsed hash table.\n"); \
  node = htGetEntry(hashTable, "key3"); \
  if (node == NULL) { \
    printLog(ERR, "key3 did not appear in parsed hash table.\n"); \
    return false; \
  } \
  if (strcmp("value3", (char*) node->value) != 0) { \
    printLog(ERR, "Expected value of key3 to be value3, got \"%s\".\n", \
      (char*) node->value); \
    return false; \
  } \
  printLog(INFO, "Getting myHashTable2 from parsed hash table.\n"); \
  node = htGetEntry(hashTable, "myHashTable2"); \
  if (node == NULL) { \
    printLog(ERR, "myHashTable2 did not appear in parsed hash table.\n"); \
    return false; \
  } \
  if (node->type != typeHashTable) { \
    printLog(ERR, "myHashTable2 was of type %lld instead of typeHashTable.\n", \
      lld(getIndexFromTypeDescriptor(node->type))); \
    return false; \
  } \
  printLog(INFO, "Getting key4 from myHashTable2.\n"); \
  if (htGetEntry((HashTable*) node->value, "key4") == NULL) { \
    printLog(ERR, "key4 did not appear in myHashTable2.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting key5 from myHashTable2.\n"); \
  if (htGetEntry((HashTable*) node->value, "key5") == NULL) { \
    printLog(ERR, "key5 did not appear in myHashTable2.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting key6 from myHashTable2.\n"); \
  if (htGetEntry((HashTable*) node->value, "key6") == NULL) { \
    printLog(ERR, "key6 did not appear in myHashTable2.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting myHashTable3 from parsed list.\n"); \
  node = htGetEntry(hashTable, "myHashTable3"); \
  if (node == NULL) { \
    printLog(ERR, "myHashTable3 did not appear in parsed hash table.\n"); \
    return false; \
  } \
  if (node->type != typeHashTable) { \
    printLog(ERR, "myHashTable3 was of type %lld instead of typeHashTable.\n", \
      lld(getIndexFromTypeDescriptor(node->type))); \
    return false; \
  } \
  printLog(INFO, "Getting key9 from myHashTable.\n"); \
  if (htGetEntry((HashTable*) node->value, "key9") == NULL) { \
    printLog(ERR, "key9 did not appear in myHashTable3.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting myHashTable4 from myHashTable3.\n"); \
  node = htGetEntry((HashTable*) node->value, "myHashTable4"); \
  printLog(INFO, "node = %p\n", node); \
  if (node == NULL) { \
    printLog(ERR, "myHashTable4 did not appear in myHashTable3.\n"); \
    return false; \
  } \
  printLog(INFO, "node->type = %p\n", node->type); \
  if (node->type != typeHashTable) { \
    printLog(ERR, "myHashTable4 was of type %lld instead of typeHashTable.\n", \
      lld(getIndexFromTypeDescriptor(node->type))); \
    return false; \
  } \
  printLog(INFO, "Getting key7 from myHashTable4.\n"); \
  if (htGetEntry((HashTable*) node->value, "key7") == NULL) { \
    printLog(ERR, "key7 did not appear in myHashTable4.\n"); \
    return false; \
  } \
  printLog(INFO, "Getting key8 from myHashTable4.\n"); \
  if (htGetEntry((HashTable*) node->value, "key8") == NULL) { \
    printLog(ERR, "key8 did not appear in myHashTable4.\n"); \
    return false; \
  } \
  htDestroy(hashTable); hashTable = NULL; \
 \
  hashTable = htCreate(typeStringCi); \
  htAddEntry(hashTable, "SOAPAction", "myValue"); \
  htAddEntry(hashTable, "Host", "127.0.0.1"); \
  htAddEntry(hashTable, "User-Agent", "Zeep"); \
  stringValue = (char*) htGetValue(hashTable, "SoapAction"); \
  if (stringValue == NULL) { \
    printLog(ERR, "htGetValue(hashTable, \"SoapAction\") returned NULL.\n"); \
    return false; \
  } else if (strcmp(stringValue, "myValue") != 0) { \
    printLog(ERR, "htGetValue(hashTable, \"SoapAction\") returned %s.\n", stringValue); \
    return false; \
  } \
  printLog(INFO, "Case-insensitive hash table passed.\n"); \
  stringValue = htToString(hashTable); \
  printLog(INFO, "Table: %s\n", stringValue); \
  stringValue = stringDestroy(stringValue); \
  hashTable = htDestroy(hashTable); \
 \
  const char *jsonString = "{\n" \
    "  \"myHashTable1\": {\n" \
    "    \"key1\": \"value1\",\n" \
    "    \"key2\": \"value2\"\n" \
    "  },\n" \
    "  \"key3\": \"value3\",\n" \
    "  \"myHashTable2\": {\n" \
    "    \"key4\": \"value4\",\n" \
    "    \"key5\": \"value5\",\n" \
    "    \"key6\": \"value6\"\n" \
    "  },\n" \
    "  \"myHashTable3\": {\n" \
    "    \"myHashTable4\": {\n" \
    "      \"key7\": \"value7\",\n" \
    "      \"key8\": \"value8\"\n" \
    "    },\n" \
    "    \"key9\": \"value9\"\n" \
    "  }\n" \
    "}"; \
  long long int startPosition = 0; \
  hashTable = jsonToHashTable(jsonString, &startPosition); \
  if (hashTable == NULL) { \
    printLog(ERR, "jsonToHashTable returned NULL.\n"); \
    return false; \
  } \
  byteArray = htToBlob(hashTable); \
  length = bytesLength(byteArray); \
  hashTable = htDestroy(hashTable); \
  hashTable = htFromBlob(byteArray, &length, true); \
  stringValue = htToString(hashTable); \
  printLog(INFO, "Table: %s\n", stringValue); \
  stringValue = stringDestroy(stringValue); \
  stringValue = (char*) htGetValue(hashTable, "key3"); \
  if (stringValue == NULL) { \
    printLog(ERR, "Value for key3 was NULL.\n"); \
    return false; \
  } else if (strcmp(stringValue, "value3") != 0) { \
    printLog(ERR, "Expected \"value3\", got \"%s\".\n", stringValue); \
    return false; \
  } \
  hashTable2 = (HashTable*) htGetValue(hashTable, "myHashTable1"); \
  if (hashTable2 == NULL) { \
    printLog(ERR, "Value for myHashTable1 was NULL.\n"); \
    return false; \
  } else if (htGetEntry(hashTable, "myHashTable1")->type != typeHashTable) { \
    printLog(ERR, "Expected myHashTable1 to be \"%s\", found \"%s\".\n", \
      typeHashTable->name, htGetEntry(hashTable, "myHashTable1")->type->name); \
    return false; \
  } \
  stringValue = (char*) htGetValue(hashTable2, "key1"); \
  if (stringValue == NULL) { \
    printLog(ERR, "Value for key1 was NULL.\n"); \
    return false; \
  } else if (strcmp(stringValue, "value1") != 0) { \
    printLog(ERR, "Expected \"value1\", got \"%s\".\n", stringValue); \
    return false; \
  } \
  stringValue = (char*) htGetValue(hashTable2, "key2"); \
  if (stringValue == NULL) { \
    printLog(ERR, "Value for key2 was NULL.\n"); \
    return false; \
  } else if (strcmp(stringValue, "value2") != 0) { \
    printLog(ERR, "Expected \"value2\", got \"%s\".\n", stringValue); \
    return false; \
  } \
  stringValue = (char*) htGetValue(hashTable2, "key6"); \
  hashTable2 = (HashTable*) htGetValue(hashTable, "myHashTable2"); \
  if (hashTable2 == NULL) { \
    printLog(ERR, "Value for myHashTable2 was NULL.\n"); \
    return false; \
  } else if (htGetEntry(hashTable, "myHashTable2")->type != typeHashTable) { \
    printLog(ERR, "Expected myHashTable2 to be \"%s\", found \"%s\".\n", \
      typeHashTable->name, htGetEntry(hashTable, "myHashTable2")->type->name); \
    return false; \
  } \
  stringValue = (char*) htGetValue(hashTable2, "key4"); \
  if (stringValue == NULL) { \
    printLog(ERR, "Value for key4 was NULL.\n"); \
    return false; \
  } else if (strcmp(stringValue, "value4") != 0) { \
    printLog(ERR, "Expected \"value4\", got \"%s\".\n", stringValue); \
    return false; \
  } \
  stringValue = (char*) htGetValue(hashTable2, "key5"); \
  if (stringValue == NULL) { \
    printLog(ERR, "Value for key5 was NULL.\n"); \
    return false; \
  } else if (strcmp(stringValue, "value5") != 0) { \
    printLog(ERR, "Expected \"value5\", got \"%s\".\n", stringValue); \
    return false; \
  } \
  stringValue = (char*) htGetValue(hashTable2, "key6"); \
  if (stringValue == NULL) { \
    printLog(ERR, "Value for key6 was NULL.\n"); \
    return false; \
  } else if (strcmp(stringValue, "value6") != 0) { \
    printLog(ERR, "Expected \"value6\", got \"%s\".\n", stringValue); \
    return false; \
  } \
  hashTable2 = (HashTable*) htGetValue(hashTable, "myHashTable3"); \
  if (hashTable2 == NULL) { \
    printLog(ERR, "Value for myHashTable3 was NULL.\n"); \
    return false; \
  } else if (htGetEntry(hashTable, "myHashTable3")->type != typeHashTable) { \
    printLog(ERR, "Expected myHashTable3 to be \"%s\", found \"%s\".\n", \
      typeHashTable->name, htGetEntry(hashTable, "myHashTable3")->type->name); \
    return false; \
  } \
  stringValue = (char*) htGetValue(hashTable2, "key9"); \
  if (stringValue == NULL) { \
    printLog(ERR, "Value for key9 was NULL.\n"); \
    return false; \
  } else if (strcmp(stringValue, "value9") != 0) { \
    printLog(ERR, "Expected \"value9\", got \"%s\".\n", stringValue); \
    return false; \
  } \
  if (htGetValue(hashTable2, "myHashTable4") == NULL) { \
    printLog(ERR, "Value for myHashTable4 was NULL.\n"); \
    return false; \
  } else if (htGetEntry(hashTable2, "myHashTable4")->type != typeHashTable) { \
    printLog(ERR, "Expected myHashTable4 to be \"%s\", found \"%s\".\n", \
      typeHashTable->name, htGetEntry(hashTable, "myHashTable4")->type->name); \
    return false; \
  } \
  hashTable2 = (HashTable*) htGetValue(hashTable2, "myHashTable4"); \
  stringValue = (char*) htGetValue(hashTable2, "key7"); \
  if (stringValue == NULL) { \
    printLog(ERR, "Value for key7 was NULL.\n"); \
    return false; \
  } else if (strcmp(stringValue, "value7") != 0) { \
    printLog(ERR, "Expected \"value7\", got \"%s\".\n", stringValue); \
    return false; \
  } \
  stringValue = (char*) htGetValue(hashTable2, "key8"); \
  if (stringValue == NULL) { \
    printLog(ERR, "Value for key8 was NULL.\n"); \
    return false; \
  } else if (strcmp(stringValue, "value8") != 0) { \
    printLog(ERR, "Expected \"value8\", got \"%s\".\n", stringValue); \
    return false; \
  } \
  byteArray = bytesDestroy(byteArray); \
  hashTable = htDestroy(hashTable); \
 \
  return true; \
}
HASH_TABLE_UNIT_TEST

