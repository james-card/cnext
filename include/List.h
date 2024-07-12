///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              02.22.2019
///
/// @file              List.h
///
/// @brief             This library contains the function and structure
///                    definitions that make up the list data structure.
///
/// @details           This library underpins both queue and stack.
///
/// @copyright
///                   Copyright (c) 2012-2024 James Card
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

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "DataTypes.h"

#ifdef __cplusplus
extern "C"
{
#endif

List *listCreate_(TypeDescriptor *keyType, bool disableThreadSafety, ...);
#define listCreate(keyType, ...) listCreate_(keyType, ##__VA_ARGS__, 0)
ListNode *listAddFrontEntry_(List *list, const volatile void *key, const volatile void *value, TypeDescriptor *type, ...);
#define listAddFrontEntry(list, key, value, ...) listAddFrontEntry_(list, key, value, ##__VA_ARGS__, NULL)
ListNode *listAddBackEntry_(List *list, const volatile void *key, const volatile void *value, TypeDescriptor *type, ...);
#define listAddBackEntry(list, key, value, ...) listAddBackEntry_(list, key, value, ##__VA_ARGS__, NULL)
int listRemoveFront(List *list);
int listRemoveBack(List *list);
int listRemove(List *list, const volatile void *key);
ListNode *listGetFront(const List *list);
ListNode *listGetBack(const List *list);
ListNode *listGetForward(const List *list, const volatile void *key);
ListNode *listGetReverse(const List *list, const volatile void *key);
int listDestroyNode(List *list, ListNode *node);
List* listDestroy(List *list);
char *listToString(const List *list);
Bytes listToBytes(const List *list);
List *xmlToList(const char *inputData);
Bytes listToXml_(const List *list, const char *elementName, bool indent, ...);
#define listToXml(list, elementName, ...) \
  listToXml_(list, elementName, ##__VA_ARGS__, false)
int listCompare(const List *listA, const List *listB);
List *listCopy(const List *list);
size_t listSize(const volatile void *value);
Bytes listToBlob(const List *list);
List *listFromBlob_(const volatile void *array, u64 *length, bool inPlaceData, bool disableThreadSafety, ...);
#define listFromBlob(array, length, ...) \
  listFromBlob_(array, length, ##__VA_ARGS__, 0, 0)
Bytes listToJson(const List *list);
List* jsonToList(const char *jsonText, long long int *position);
char* listToKeyValueString(const List *list, const char *separator);
i32 listClear(List *list);
u64 listLength(List *list);
#define listIsEmpty(list) (listLength(list) == 0)
bool listUnitTest();

#ifdef __cplusplus
} // extern "C"
#endif


#if (defined __cplusplus) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 201710L)

// These must come last and must come outside the extern "C" block.
#include "TypeSafeListAddFront.h"
#include "TypeSafeListAddBack.h"

#endif // TypeSafeListAddFront.h and TypeSafeListAddBack.h

#endif // LIST_H

