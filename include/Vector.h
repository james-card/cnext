///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              09.29.2019
///
/// @file              Vector.h
///
/// @brief             This library contains the function and structure
///                    definitions make up the vector data structure.
///
/// @copyright
///                   Copyright (c) 2012-2025 James Card
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

#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>

#include "DataTypes.h"
#include "List.h"

#ifdef __cplusplus
extern "C"
{
#endif

Vector *vectorCreate_(TypeDescriptor *keyType, TypeDescriptor *valueType,
  bool disableThreadSafety, u64 size, ...);
#define vectorCreate(valueType, ...) \
  vectorCreate_(NULL, valueType, ##__VA_ARGS__, 0, 0)
#define kvVectorCreate(keyType, ...) \
  vectorCreate_(keyType, ##__VA_ARGS__, 0, 0, 0)
VectorNode *kvVectorSetEntry_(Vector *vector, u64 index,
  const volatile void *key, const volatile void *value, TypeDescriptor *type,
  ...);
#define vectorSetEntry(vector, index, value, ...) \
  kvVectorSetEntry_(vector, index, NULL, value, ##__VA_ARGS__, NULL)
#define kvVectorSetEntry(vector, index, key, value, ...) \
  kvVectorSetEntry_(vector, index, key, value, ##__VA_ARGS__, NULL)
#define kvVectorAddEntry(vector, key, value, ...) \
  kvVectorSetEntry(vector, vector->size, key, value, ##__VA_ARGS__, NULL)
VectorNode *vectorGetEntry(Vector *vector, u64 index);
VectorNode* vectorFindPreviousAllocated(Vector *vector, u64 index);
VectorNode* vectorFindNextAllocated(Vector *vector, u64 index);
i32 vectorRemove(Vector *vector, u64 index);
void* vectorGetValue(Vector *vector, u64 index);
VectorNode* kvVectorGetEntry(Vector *vector, const volatile void *key);
void* kvVectorGetValue(Vector *vector, const volatile void *key);
Vector* vectorDestroy(Vector *vector);
#define kvVectorDestroy vectorDestroy
#define vectorToString(vector) listToString((List*) vector)
#define vectorToList(vector) listCopy((List*) vector)
Bytes vectorToXml_(const Vector *vector, const char *elementName, bool indent, ...);
#define vectorToXml(vector, elementName, ...) \
  vectorToXml_(vector, elementName, ##__VA_ARGS__, false)
int vectorCompare(Vector *vectorA, Vector *vectorB);
Vector *vectorCopy(Vector *vector);
// ASCENDING and DESCENDING are defined in both Vector.h and Array.h, so take
// care not to define them twice and make the compiler complain.
#ifndef ASCENDING
#define ASCENDING (1)
#endif // ASCENDING
#ifndef DESCENDING
#define DESCENDING (-1)
#endif // DESCENDING
void* vectorSort(Vector *vector, i32 order, bool sortValues);
#define vectorToBlob(vector) listToBlob((List*) vector)
Bytes vectorToJson(const Vector *vector);
Vector* jsonToVector(const char *jsonText, long long int *position);
Vector* jsonToKvVector(const char *jsonText, long long int *position);
VectorNode* vectorGetIndex(Vector *vector, char *index);
Vector* vectorFromBlob_(const volatile void *array, u64 *length, bool inPlaceData, bool disableThreadSafety, ...);
#define vectorFromBlob(array, length, ...) \
  vectorFromBlob_(array, length, ##__VA_ARGS__, 0, 0)
bool vectorUnitTest();

#ifdef __cplusplus
} // extern "C"
#endif

#if (defined __cplusplus) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 201710L)

// This must come last and must come outside the extern "C" block.
#include "TypeSafeVectorSet.h"

#endif // TypeSafeVectorSet.h

#endif // VECTOR_H

