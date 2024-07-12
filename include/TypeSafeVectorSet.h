///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              04.21.2024
///
/// @file              TypeSafeVectorSet.h
///
/// @brief             This header contains type-safe versions of the
///                    vectorSet function.
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


#ifndef TYPE_SAFE_VECTOR_SET_H
#define TYPE_SAFE_VECTOR_SET_H

#include "DataTypes.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Type-safe inline functions.

static inline VectorNode* vectorSetBool(Vector *dataStructure, u64 index, bool value) {
  return vectorSetEntry(dataStructure, index, &value, typeBool);
}
static inline VectorNode* vectorSetBoolP(Vector *dataStructure, u64 index, const volatile bool* value) {
  return vectorSetEntry(dataStructure, index, value, typeBoolNoCopy);
}
static inline VectorNode* vectorSetI16(Vector *dataStructure, u64 index, i16 value) {
  return vectorSetEntry(dataStructure, index, &value, typeI16);
}
static inline VectorNode* vectorSetI16P(Vector *dataStructure, u64 index, const volatile i16* value) {
  return vectorSetEntry(dataStructure, index, value, typeI16NoCopy);
}
static inline VectorNode* vectorSetU16(Vector *dataStructure, u64 index, u16 value) {
  return vectorSetEntry(dataStructure, index, &value, typeU16);
}
static inline VectorNode* vectorSetU16P(Vector *dataStructure, u64 index, const volatile u16* value) {
  return vectorSetEntry(dataStructure, index, value, typeU16NoCopy);
}
static inline VectorNode* vectorSetI32(Vector *dataStructure, u64 index, i32 value) {
  return vectorSetEntry(dataStructure, index, &value, typeI32);
}
static inline VectorNode* vectorSetI32P(Vector *dataStructure, u64 index, const volatile i32* value) {
  return vectorSetEntry(dataStructure, index, value, typeI32NoCopy);
}
static inline VectorNode* vectorSetU32(Vector *dataStructure, u64 index, u32 value) {
  return vectorSetEntry(dataStructure, index, &value, typeU32);
}
static inline VectorNode* vectorSetU32P(Vector *dataStructure, u64 index, const volatile u32* value) {
  return vectorSetEntry(dataStructure, index, value, typeU32NoCopy);
}
static inline VectorNode* vectorSetI64(Vector *dataStructure, u64 index, i64 value) {
  return vectorSetEntry(dataStructure, index, &value, typeI64);
}
static inline VectorNode* vectorSetI64P(Vector *dataStructure, u64 index, const volatile i64* value) {
  return vectorSetEntry(dataStructure, index, value, typeI64NoCopy);
}
static inline VectorNode* vectorSetU64(Vector *dataStructure, u64 index, u64 value) {
  return vectorSetEntry(dataStructure, index, &value, typeU64);
}
static inline VectorNode* vectorSetU64P(Vector *dataStructure, u64 index, const volatile u64* value) {
  return vectorSetEntry(dataStructure, index, value, typeU64NoCopy);
}
static inline VectorNode* vectorSetFloat(Vector *dataStructure, u64 index, float value) {
  return vectorSetEntry(dataStructure, index, &value, typeFloat);
}
static inline VectorNode* vectorSetFloatP(Vector *dataStructure, u64 index, const volatile float* value) {
  return vectorSetEntry(dataStructure, index, value, typeFloatNoCopy);
}
static inline VectorNode* vectorSetDouble(Vector *dataStructure, u64 index, double value) {
  return vectorSetEntry(dataStructure, index, &value, typeDouble);
}
static inline VectorNode* vectorSetDoubleP(Vector *dataStructure, u64 index, const volatile double* value) {
  return vectorSetEntry(dataStructure, index, value, typeDoubleNoCopy);
}
static inline VectorNode* vectorSetLongDouble(Vector *dataStructure, u64 index, long double value) {
  return vectorSetEntry(dataStructure, index, &value, typeLongDouble);
}
static inline VectorNode* vectorSetLongDoubleP(Vector *dataStructure, u64 index, const volatile long double* value) {
  return vectorSetEntry(dataStructure, index, value, typeLongDoubleNoCopy);
}
static inline VectorNode* vectorSetList(Vector *dataStructure, u64 index, List value) {
  return vectorSetEntry(dataStructure, index, &value, typeList);
}
static inline VectorNode* vectorSetListP(Vector *dataStructure, u64 index, const volatile List* value) {
  return vectorSetEntry(dataStructure, index, value, typeListNoCopy);
}
static inline VectorNode* vectorSetQueue(Vector *dataStructure, u64 index, Queue value) {
  return vectorSetEntry(dataStructure, index, &value, typeQueue);
}
static inline VectorNode* vectorSetQueueP(Vector *dataStructure, u64 index, const volatile Queue* value) {
  return vectorSetEntry(dataStructure, index, value, typeQueueNoCopy);
}
static inline VectorNode* vectorSetStack(Vector *dataStructure, u64 index, Stack value) {
  return vectorSetEntry(dataStructure, index, &value, typeStack);
}
static inline VectorNode* vectorSetStackP(Vector *dataStructure, u64 index, const volatile Stack* value) {
  return vectorSetEntry(dataStructure, index, value, typeStackNoCopy);
}
static inline VectorNode* vectorSetRedBlackTree(Vector *dataStructure, u64 index, RedBlackTree value) {
  return vectorSetEntry(dataStructure, index, &value, typeRedBlackTree);
}
static inline VectorNode* vectorSetRedBlackTreeP(Vector *dataStructure, u64 index, const volatile RedBlackTree* value) {
  return vectorSetEntry(dataStructure, index, value, typeRedBlackTreeNoCopy);
}
static inline VectorNode* vectorSetHashTable(Vector *dataStructure, u64 index, HashTable value) {
  return vectorSetEntry(dataStructure, index, &value, typeHashTable);
}
static inline VectorNode* vectorSetHashTableP(Vector *dataStructure, u64 index, const volatile HashTable* value) {
  return vectorSetEntry(dataStructure, index, value, typeHashTableNoCopy);
}
static inline VectorNode* vectorSetVector(Vector *dataStructure, u64 index, Vector value) {
  return vectorSetEntry(dataStructure, index, &value, typeVector);
}
static inline VectorNode* vectorSetVectorP(Vector *dataStructure, u64 index, const volatile Vector* value) {
  return vectorSetEntry(dataStructure, index, value, typeVectorNoCopy);
}
static inline VectorNode* vectorSetString(Vector *dataStructure, u64 index, const volatile char* value) {
  return vectorSetEntry(dataStructure, index, value, typeString);
}
static inline VectorNode* vectorSetStringP(Vector *dataStructure, u64 index, const volatile char** value) {
  return vectorSetEntry(dataStructure, index, *value, typeStringNoCopy);
}
static inline VectorNode* vectorSetBytes(Vector *dataStructure, u64 index, Bytes value) {
  return vectorSetEntry(dataStructure, index, value, typeBytes);
}
static inline VectorNode* vectorSetBytesP(Vector *dataStructure, u64 index, const volatile Bytes* value) {
  return vectorSetEntry(dataStructure, index, *value, typeBytesNoCopy);
}
static inline VectorNode* vectorSetPointer(Vector *dataStructure, u64 index, void* value) {
  return vectorSetEntry(dataStructure, index, value, typePointer);
}
static inline VectorNode* vectorSetPointerP(Vector *dataStructure, u64 index, const volatile void** value) {
  return vectorSetEntry(dataStructure, index, *value, typePointerNoCopy);
}
static inline VectorNode* vectorSetI8(Vector *dataStructure, u64 index, i8 value) {
  return vectorSetEntry(dataStructure, index, &value, typeI8);
}
static inline VectorNode* vectorSetU8(Vector *dataStructure, u64 index, u8 value) {
  return vectorSetEntry(dataStructure, index, &value, typeU8);
}

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#if defined __STDC_VERSION__

#if __STDC_VERSION__ >= 201710L
#define TYPE_SAFE_VECTOR

#define VECTOR_SET_GENERIC_CASES(dataStructure, index, value) \
  bool:                  vectorSetBool,                              \
  bool*:                 vectorSetBoolP,                             \
  const volatile bool*:  vectorSetBoolP,                             \
  i16:                   vectorSetI16,                               \
  i16*:                  vectorSetI16P,                              \
  const volatile i16*:   vectorSetI16P,                              \
  u16:                   vectorSetU16,                               \
  u16*:                  vectorSetU16P,                              \
  const volatile u16*:   vectorSetU16P,                              \
  i32:                   vectorSetI32,                               \
  i32*:                  vectorSetI32P,                              \
  const volatile i32*:   vectorSetI32P,                              \
  u32:                   vectorSetU32,                               \
  u32*:                  vectorSetU32P,                              \
  const volatile u32*:   vectorSetU32P,                              \
  i64:                   vectorSetI64,                               \
  i64*:                  vectorSetI64P,                              \
  const volatile i64*:   vectorSetI64P,                              \
  u64:                   vectorSetU64,                               \
  u64*:                  vectorSetU64P,                              \
  const volatile u64*:   vectorSetU64P,                              \
  float:                 vectorSetFloat,                             \
  float*:                vectorSetFloatP,                            \
  const volatile float*: vectorSetFloatP,                            \
  double:                vectorSetDouble,                            \
  double*:               vectorSetDoubleP,                           \
  const volatile double*: vectorSetDoubleP,                           \
  long double:           vectorSetLongDouble,                        \
  long double*:          vectorSetLongDoubleP,                       \
  const volatile long double*: vectorSetLongDoubleP,                       \
  List:                  vectorSetList,                              \
  List*:                 vectorSetListP,                             \
  const volatile List*:  vectorSetListP,                             \
  Queue:                 vectorSetQueue,                             \
  Queue*:                vectorSetQueueP,                            \
  const volatile Queue*: vectorSetQueueP,                            \
  Stack:                 vectorSetStack,                             \
  Stack*:                vectorSetStackP,                            \
  const volatile Stack*: vectorSetStackP,                            \
  RedBlackTree:          vectorSetRedBlackTree,                      \
  RedBlackTree*:         vectorSetRedBlackTreeP,                     \
  const volatile RedBlackTree*: vectorSetRedBlackTreeP,                     \
  HashTable:             vectorSetHashTable,                         \
  HashTable*:            vectorSetHashTableP,                        \
  const volatile HashTable*: vectorSetHashTableP,                        \
  Vector:                vectorSetVector,                            \
  Vector*:               vectorSetVectorP,                           \
  const volatile Vector*: vectorSetVectorP,                           \
  char*:                 vectorSetString,                            \
  const volatile char*:  vectorSetString,                            \
  char**:                vectorSetStringP,                           \
  const volatile char**: vectorSetStringP,                           \
  Bytes:                 vectorSetBytes,                             \
  Bytes*:                vectorSetBytesP,                            \
  const volatile Bytes*: vectorSetBytesP,                            \
  void*:                 vectorSetPointer,                           \
  void**:                vectorSetPointerP,                          \
  const volatile void**: vectorSetPointerP,                          \
  i8:                    vectorSetI8,                                \
  u8:                    vectorSetU8                                 \

#define vectorSet(dataStructure, index, value) _Generic((value), \
  VECTOR_SET_GENERIC_CASES(dataStructure, index, value) \
  )(dataStructure, index, value)

#endif // __STDC_VERSION__

#elif defined __cplusplus // __STDC_VERSION__ is *NOT* defined
#define TYPE_SAFE_VECTOR

// Define the C++ function overloads.

static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, bool value) {
  return vectorSetBool(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile bool* value) {
  return vectorSetBoolP(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, i16 value) {
  return vectorSetI16(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile i16* value) {
  return vectorSetI16P(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, u16 value) {
  return vectorSetU16(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile u16* value) {
  return vectorSetU16P(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, i32 value) {
  return vectorSetI32(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile i32* value) {
  return vectorSetI32P(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, u32 value) {
  return vectorSetU32(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile u32* value) {
  return vectorSetU32P(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, i64 value) {
  return vectorSetI64(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile i64* value) {
  return vectorSetI64P(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, u64 value) {
  return vectorSetU64(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile u64* value) {
  return vectorSetU64P(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, float value) {
  return vectorSetFloat(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile float* value) {
  return vectorSetFloatP(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, double value) {
  return vectorSetDouble(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile double* value) {
  return vectorSetDoubleP(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, long double value) {
  return vectorSetLongDouble(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile long double* value) {
  return vectorSetLongDoubleP(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, List value) {
  return vectorSetList(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile List* value) {
  return vectorSetListP(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, Queue value) {
  return vectorSetQueue(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile Queue* value) {
  return vectorSetQueueP(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, Stack value) {
  return vectorSetStack(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile Stack* value) {
  return vectorSetStackP(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, RedBlackTree value) {
  return vectorSetRedBlackTree(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile RedBlackTree* value) {
  return vectorSetRedBlackTreeP(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, HashTable value) {
  return vectorSetHashTable(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile HashTable* value) {
  return vectorSetHashTableP(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, Vector value) {
  return vectorSetVector(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile Vector* value) {
  return vectorSetVectorP(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile char* value) {
  return vectorSetString(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile char** value) {
  return vectorSetStringP(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, Bytes value) {
  return vectorSetBytes(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile Bytes* value) {
  return vectorSetBytesP(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, void* value) {
  return vectorSetPointer(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, const volatile void** value) {
  return vectorSetPointerP(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, i8 value) {
  return vectorSetI8(dataStructure, index, value);
}
static inline VectorNode* vectorSet(Vector *dataStructure, u64 index, u8 value) {
  return vectorSetU8(dataStructure, index, value);
}

#endif // __cplusplus

#endif // TYPE_SAFE_VECTOR_SET_H

