///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              04.21.2024
///
/// @file              TypeSafeQueuePush.h
///
/// @brief             This header contains type-safe versions of the
///                    queuePush function.
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


#ifndef TYPE_SAFE_QUEUE_PUSH_H
#define TYPE_SAFE_QUEUE_PUSH_H

#include "DataTypes.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Type-safe inline functions.

static inline QueueNode* queuePushBool(Queue *dataStructure, bool value) {
  return queuePushEntry(dataStructure, &value, typeBool);
}
static inline QueueNode* queuePushBoolP(Queue *dataStructure, const volatile bool* value) {
  return queuePushEntry(dataStructure, value, typeBoolNoCopy);
}
static inline QueueNode* queuePushI16(Queue *dataStructure, i16 value) {
  return queuePushEntry(dataStructure, &value, typeI16);
}
static inline QueueNode* queuePushI16P(Queue *dataStructure, const volatile i16* value) {
  return queuePushEntry(dataStructure, value, typeI16NoCopy);
}
static inline QueueNode* queuePushU16(Queue *dataStructure, u16 value) {
  return queuePushEntry(dataStructure, &value, typeU16);
}
static inline QueueNode* queuePushU16P(Queue *dataStructure, const volatile u16* value) {
  return queuePushEntry(dataStructure, value, typeU16NoCopy);
}
static inline QueueNode* queuePushI32(Queue *dataStructure, i32 value) {
  return queuePushEntry(dataStructure, &value, typeI32);
}
static inline QueueNode* queuePushI32P(Queue *dataStructure, const volatile i32* value) {
  return queuePushEntry(dataStructure, value, typeI32NoCopy);
}
static inline QueueNode* queuePushU32(Queue *dataStructure, u32 value) {
  return queuePushEntry(dataStructure, &value, typeU32);
}
static inline QueueNode* queuePushU32P(Queue *dataStructure, const volatile u32* value) {
  return queuePushEntry(dataStructure, value, typeU32NoCopy);
}
static inline QueueNode* queuePushI64(Queue *dataStructure, i64 value) {
  return queuePushEntry(dataStructure, &value, typeI64);
}
static inline QueueNode* queuePushI64P(Queue *dataStructure, const volatile i64* value) {
  return queuePushEntry(dataStructure, value, typeI64NoCopy);
}
static inline QueueNode* queuePushU64(Queue *dataStructure, u64 value) {
  return queuePushEntry(dataStructure, &value, typeU64);
}
static inline QueueNode* queuePushU64P(Queue *dataStructure, const volatile u64* value) {
  return queuePushEntry(dataStructure, value, typeU64NoCopy);
}
static inline QueueNode* queuePushFloat(Queue *dataStructure, float value) {
  return queuePushEntry(dataStructure, &value, typeFloat);
}
static inline QueueNode* queuePushFloatP(Queue *dataStructure, const volatile float* value) {
  return queuePushEntry(dataStructure, value, typeFloatNoCopy);
}
static inline QueueNode* queuePushDouble(Queue *dataStructure, double value) {
  return queuePushEntry(dataStructure, &value, typeDouble);
}
static inline QueueNode* queuePushDoubleP(Queue *dataStructure, const volatile double* value) {
  return queuePushEntry(dataStructure, value, typeDoubleNoCopy);
}
static inline QueueNode* queuePushLongDouble(Queue *dataStructure, long double value) {
  return queuePushEntry(dataStructure, &value, typeLongDouble);
}
static inline QueueNode* queuePushLongDoubleP(Queue *dataStructure, const volatile long double* value) {
  return queuePushEntry(dataStructure, value, typeLongDoubleNoCopy);
}
static inline QueueNode* queuePushList(Queue *dataStructure, List value) {
  return queuePushEntry(dataStructure, &value, typeList);
}
static inline QueueNode* queuePushListP(Queue *dataStructure, const volatile List* value) {
  return queuePushEntry(dataStructure, value, typeListNoCopy);
}
static inline QueueNode* queuePushQueue(Queue *dataStructure, Queue value) {
  return queuePushEntry(dataStructure, &value, typeQueue);
}
static inline QueueNode* queuePushQueueP(Queue *dataStructure, const volatile Queue* value) {
  return queuePushEntry(dataStructure, value, typeQueueNoCopy);
}
static inline QueueNode* queuePushStack(Queue *dataStructure, Stack value) {
  return queuePushEntry(dataStructure, &value, typeStack);
}
static inline QueueNode* queuePushStackP(Queue *dataStructure, const volatile Stack* value) {
  return queuePushEntry(dataStructure, value, typeStackNoCopy);
}
static inline QueueNode* queuePushRedBlackTree(Queue *dataStructure, RedBlackTree value) {
  return queuePushEntry(dataStructure, &value, typeRedBlackTree);
}
static inline QueueNode* queuePushRedBlackTreeP(Queue *dataStructure, const volatile RedBlackTree* value) {
  return queuePushEntry(dataStructure, value, typeRedBlackTreeNoCopy);
}
static inline QueueNode* queuePushHashTable(Queue *dataStructure, HashTable value) {
  return queuePushEntry(dataStructure, &value, typeHashTable);
}
static inline QueueNode* queuePushHashTableP(Queue *dataStructure, const volatile HashTable* value) {
  return queuePushEntry(dataStructure, value, typeHashTableNoCopy);
}
static inline QueueNode* queuePushVector(Queue *dataStructure, Vector value) {
  return queuePushEntry(dataStructure, &value, typeVector);
}
static inline QueueNode* queuePushVectorP(Queue *dataStructure, const volatile Vector* value) {
  return queuePushEntry(dataStructure, value, typeVectorNoCopy);
}
static inline QueueNode* queuePushString(Queue *dataStructure, const volatile char* value) {
  return queuePushEntry(dataStructure, value, typeString);
}
static inline QueueNode* queuePushStringP(Queue *dataStructure, const volatile char** value) {
  return queuePushEntry(dataStructure, *value, typeStringNoCopy);
}
static inline QueueNode* queuePushBytes(Queue *dataStructure, Bytes value) {
  return queuePushEntry(dataStructure, value, typeBytes);
}
static inline QueueNode* queuePushBytesP(Queue *dataStructure, const volatile Bytes* value) {
  return queuePushEntry(dataStructure, *value, typeBytesNoCopy);
}
static inline QueueNode* queuePushPointer(Queue *dataStructure, void* value) {
  return queuePushEntry(dataStructure, value, typePointer);
}
static inline QueueNode* queuePushPointerP(Queue *dataStructure, const volatile void** value) {
  return queuePushEntry(dataStructure, *value, typePointerNoCopy);
}
static inline QueueNode* queuePushI8(Queue *dataStructure, i8 value) {
  return queuePushEntry(dataStructure, &value, typeI8);
}
static inline QueueNode* queuePushU8(Queue *dataStructure, u8 value) {
  return queuePushEntry(dataStructure, &value, typeU8);
}

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#if defined __STDC_VERSION__

#if __STDC_VERSION__ >= 201710L
#define TYPE_SAFE_QUEUE

#define QUEUE_PUSH_GENERIC_CASES(dataStructure, value) \
  bool:                  queuePushBool,                              \
  bool*:                 queuePushBoolP,                             \
  const volatile bool*:  queuePushBoolP,                             \
  i16:                   queuePushI16,                               \
  i16*:                  queuePushI16P,                              \
  const volatile i16*:   queuePushI16P,                              \
  u16:                   queuePushU16,                               \
  u16*:                  queuePushU16P,                              \
  const volatile u16*:   queuePushU16P,                              \
  i32:                   queuePushI32,                               \
  i32*:                  queuePushI32P,                              \
  const volatile i32*:   queuePushI32P,                              \
  u32:                   queuePushU32,                               \
  u32*:                  queuePushU32P,                              \
  const volatile u32*:   queuePushU32P,                              \
  i64:                   queuePushI64,                               \
  i64*:                  queuePushI64P,                              \
  const volatile i64*:   queuePushI64P,                              \
  u64:                   queuePushU64,                               \
  u64*:                  queuePushU64P,                              \
  const volatile u64*:   queuePushU64P,                              \
  float:                 queuePushFloat,                             \
  float*:                queuePushFloatP,                            \
  const volatile float*: queuePushFloatP,                            \
  double:                queuePushDouble,                            \
  double*:               queuePushDoubleP,                           \
  const volatile double*: queuePushDoubleP,                           \
  long double:           queuePushLongDouble,                        \
  long double*:          queuePushLongDoubleP,                       \
  const volatile long double*: queuePushLongDoubleP,                       \
  List:                  queuePushList,                              \
  List*:                 queuePushListP,                             \
  const volatile List*:  queuePushListP,                             \
  Queue:                 queuePushQueue,                             \
  Queue*:                queuePushQueueP,                            \
  const volatile Queue*: queuePushQueueP,                            \
  Stack:                 queuePushStack,                             \
  Stack*:                queuePushStackP,                            \
  const volatile Stack*: queuePushStackP,                            \
  RedBlackTree:          queuePushRedBlackTree,                      \
  RedBlackTree*:         queuePushRedBlackTreeP,                     \
  const volatile RedBlackTree*: queuePushRedBlackTreeP,                     \
  HashTable:             queuePushHashTable,                         \
  HashTable*:            queuePushHashTableP,                        \
  const volatile HashTable*: queuePushHashTableP,                        \
  Vector:                queuePushVector,                            \
  Vector*:               queuePushVectorP,                           \
  const volatile Vector*: queuePushVectorP,                           \
  char*:                 queuePushString,                            \
  const volatile char*:  queuePushString,                            \
  char**:                queuePushStringP,                           \
  const volatile char**: queuePushStringP,                           \
  Bytes:                 queuePushBytes,                             \
  Bytes*:                queuePushBytesP,                            \
  const volatile Bytes*: queuePushBytesP,                            \
  void*:                 queuePushPointer,                           \
  void**:                queuePushPointerP,                          \
  const volatile void**: queuePushPointerP,                          \
  i8:                    queuePushI8,                                \
  u8:                    queuePushU8                                 \

#define queuePush(dataStructure, value) _Generic((value), \
  QUEUE_PUSH_GENERIC_CASES(dataStructure, value) \
  )(dataStructure, value)

#endif // __STDC_VERSION__

#elif defined __cplusplus // __STDC_VERSION__ is *NOT* defined
#define TYPE_SAFE_QUEUE

// Define the C++ function overloads.

static inline QueueNode* queuePush(Queue *dataStructure, bool value) {
  return queuePushBool(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile bool* value) {
  return queuePushBoolP(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, i16 value) {
  return queuePushI16(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile i16* value) {
  return queuePushI16P(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, u16 value) {
  return queuePushU16(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile u16* value) {
  return queuePushU16P(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, i32 value) {
  return queuePushI32(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile i32* value) {
  return queuePushI32P(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, u32 value) {
  return queuePushU32(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile u32* value) {
  return queuePushU32P(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, i64 value) {
  return queuePushI64(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile i64* value) {
  return queuePushI64P(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, u64 value) {
  return queuePushU64(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile u64* value) {
  return queuePushU64P(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, float value) {
  return queuePushFloat(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile float* value) {
  return queuePushFloatP(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, double value) {
  return queuePushDouble(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile double* value) {
  return queuePushDoubleP(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, long double value) {
  return queuePushLongDouble(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile long double* value) {
  return queuePushLongDoubleP(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, List value) {
  return queuePushList(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile List* value) {
  return queuePushListP(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, Queue value) {
  return queuePushQueue(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile Queue* value) {
  return queuePushQueueP(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, Stack value) {
  return queuePushStack(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile Stack* value) {
  return queuePushStackP(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, RedBlackTree value) {
  return queuePushRedBlackTree(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile RedBlackTree* value) {
  return queuePushRedBlackTreeP(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, HashTable value) {
  return queuePushHashTable(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile HashTable* value) {
  return queuePushHashTableP(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, Vector value) {
  return queuePushVector(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile Vector* value) {
  return queuePushVectorP(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile char* value) {
  return queuePushString(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile char** value) {
  return queuePushStringP(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, Bytes value) {
  return queuePushBytes(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile Bytes* value) {
  return queuePushBytesP(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, void* value) {
  return queuePushPointer(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, const volatile void** value) {
  return queuePushPointerP(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, i8 value) {
  return queuePushI8(dataStructure, value);
}
static inline QueueNode* queuePush(Queue *dataStructure, u8 value) {
  return queuePushU8(dataStructure, value);
}

#endif // __cplusplus

#endif // TYPE_SAFE_QUEUE_PUSH_H

