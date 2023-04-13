///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              02.18.2019
///
/// @file              HashTable.h
///
/// @brief             This library contains the function and structure
///                    definitions that make up the hash table data
///                    structure.
///
/// @details           This library is currently the underpinning of the
///                    dictionary.
///
/// @copyright
///                   Copyright (c) 2012-2023 James Card
///
/// Permission is hereby granted, free of charge, to any person obtaining a
/// copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation
/// the rights to use, copy, modify, merge, publish, distribute, sublicense,
/// and/or sell copies of the Software, and to permit persons to whom the
/// Software is furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included
/// in all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
/// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
/// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
/// DEALINGS IN THE SOFTWARE.
///
///                                James Card
///                         http://www.jamescard.org
///
///////////////////////////////////////////////////////////////////////////////

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

// Forward declarations.
typedef struct RedBlackNode HashNode;
typedef struct RedBlackNode HashTableNode; // For consistency with other names
typedef struct RedBlackTree RedBlackTree;
typedef struct HashTable HashTable;

#include <stdio.h>
#include <string.h>

#include "DataTypes.h"
#include "List.h"
#include "RedBlackTree.h"

#ifdef __cplusplus
extern "C"
{
#endif

/// @def OPTIMAL_HASH_TABLE_SIZE
///
/// @brief The optimal (default) number of trees in a hash table.
///
/// @details We have to be careful with this value.  The table is backed by
/// binary search trees.  Too small a value will bring us closer to the access
/// time of the trees (O(lg(n))), while too large a value can incur a
/// significant performance hit if we're building many tables at once due to
/// the operating system's memory allocation.  In my experiments, the
/// creation time pentalty for tables of size 256 relative to tables of size 64
/// is 22%, while the creation time penalty for tables of size 512 relative to
/// tables of size 64 is 77%.  There were no significant differences to
/// hash table access time performance irrespective of table size.  These
/// experiments were done on Linux kernel 5.2.17.
#define OPTIMAL_HASH_TABLE_SIZE 64

HashTable *htCreate_(TypeDescriptor *keyType, u64 size, ...);
#define htCreate(keyType, ...) htCreate_(keyType, ##__VA_ARGS__, 0)
HashTable* htDestroy(HashTable *table);
u64 htGetHash(const HashTable *table, const volatile void *key);
HashNode *htAddEntry_(HashTable *table, const volatile void *key,
  const volatile void *value, TypeDescriptor *type, ...);
#define htAddEntry(table, key, value, ...) htAddEntry_(table, key, value, ##__VA_ARGS__, NULL)
HashNode *htGetEntry(const HashTable *table, const volatile void *key);
void *htGetValue(const HashTable *table, const volatile void *key);
i32 htRemoveEntry(HashTable *table, const volatile void *key);
char *htToString(const HashTable *table);
#define htToXml(table, elementName, ...) \
  listToXml_((const List*) table, elementName, ##__VA_ARGS__, false)
#define htToList(table) listCopy((List*) table)
HashTable *xmlToHashTable(const char *inputData);
HashTable *htFromByteArray(const volatile void *array, u64 *length);
HashTable* listToHashTable(List *list);
#define htToByteArray(table, length) listToByteArray((List*) table, length)
HashTable *htCopy(const HashTable *table);
int htCompare(const HashTable *htA, const HashTable *htB);
#define htToJson(table) listToJson((List*) table)
HashTable* jsonToHashTable(const char *jsonText, long long int *position);
i32 htClear(HashTable *table);
bool hashTableUnitTest();

#ifdef __cplusplus
} // extern "C"
#endif

#if (defined __cplusplus) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 201710L)

// This must come last and must come outside the extern "C" block.
#include "TypeSafeHtAdd.h"

#endif // TypeSafeHtAdd.h

#endif //HASH_TABLE_H
