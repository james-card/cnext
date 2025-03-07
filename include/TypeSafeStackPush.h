///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              04.21.2024
///
/// @file              TypeSafeStackPush.h
///
/// @brief             This header contains type-safe versions of the
///                    stackPush function.
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


#ifndef TYPE_SAFE_STACK_PUSH_H
#define TYPE_SAFE_STACK_PUSH_H

#include "DataTypes.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Type-safe inline functions.

static inline StackNode* stackPushBool(Stack *dataStructure, bool value) {
  return stackPushEntry(dataStructure, &value, typeBool);
}
static inline StackNode* stackPushBoolP(Stack *dataStructure, const volatile bool* value) {
  return stackPushEntry(dataStructure, value, typeBoolNoCopy);
}
static inline StackNode* stackPushI16(Stack *dataStructure, i16 value) {
  return stackPushEntry(dataStructure, &value, typeI16);
}
static inline StackNode* stackPushI16P(Stack *dataStructure, const volatile i16* value) {
  return stackPushEntry(dataStructure, value, typeI16NoCopy);
}
static inline StackNode* stackPushU16(Stack *dataStructure, u16 value) {
  return stackPushEntry(dataStructure, &value, typeU16);
}
static inline StackNode* stackPushU16P(Stack *dataStructure, const volatile u16* value) {
  return stackPushEntry(dataStructure, value, typeU16NoCopy);
}
static inline StackNode* stackPushI32(Stack *dataStructure, i32 value) {
  return stackPushEntry(dataStructure, &value, typeI32);
}
static inline StackNode* stackPushI32P(Stack *dataStructure, const volatile i32* value) {
  return stackPushEntry(dataStructure, value, typeI32NoCopy);
}
static inline StackNode* stackPushU32(Stack *dataStructure, u32 value) {
  return stackPushEntry(dataStructure, &value, typeU32);
}
static inline StackNode* stackPushU32P(Stack *dataStructure, const volatile u32* value) {
  return stackPushEntry(dataStructure, value, typeU32NoCopy);
}
static inline StackNode* stackPushI64(Stack *dataStructure, i64 value) {
  return stackPushEntry(dataStructure, &value, typeI64);
}
static inline StackNode* stackPushI64P(Stack *dataStructure, const volatile i64* value) {
  return stackPushEntry(dataStructure, value, typeI64NoCopy);
}
static inline StackNode* stackPushU64(Stack *dataStructure, u64 value) {
  return stackPushEntry(dataStructure, &value, typeU64);
}
static inline StackNode* stackPushU64P(Stack *dataStructure, const volatile u64* value) {
  return stackPushEntry(dataStructure, value, typeU64NoCopy);
}
static inline StackNode* stackPushFloat(Stack *dataStructure, float value) {
  return stackPushEntry(dataStructure, &value, typeFloat);
}
static inline StackNode* stackPushFloatP(Stack *dataStructure, const volatile float* value) {
  return stackPushEntry(dataStructure, value, typeFloatNoCopy);
}
static inline StackNode* stackPushDouble(Stack *dataStructure, double value) {
  return stackPushEntry(dataStructure, &value, typeDouble);
}
static inline StackNode* stackPushDoubleP(Stack *dataStructure, const volatile double* value) {
  return stackPushEntry(dataStructure, value, typeDoubleNoCopy);
}
static inline StackNode* stackPushLongDouble(Stack *dataStructure, long double value) {
  return stackPushEntry(dataStructure, &value, typeLongDouble);
}
static inline StackNode* stackPushLongDoubleP(Stack *dataStructure, const volatile long double* value) {
  return stackPushEntry(dataStructure, value, typeLongDoubleNoCopy);
}
static inline StackNode* stackPushList(Stack *dataStructure, List value) {
  return stackPushEntry(dataStructure, &value, typeList);
}
static inline StackNode* stackPushListP(Stack *dataStructure, const volatile List* value) {
  return stackPushEntry(dataStructure, value, typeListNoCopy);
}
static inline StackNode* stackPushQueue(Stack *dataStructure, Queue value) {
  return stackPushEntry(dataStructure, &value, typeQueue);
}
static inline StackNode* stackPushQueueP(Stack *dataStructure, const volatile Queue* value) {
  return stackPushEntry(dataStructure, value, typeQueueNoCopy);
}
static inline StackNode* stackPushStack(Stack *dataStructure, Stack value) {
  return stackPushEntry(dataStructure, &value, typeStack);
}
static inline StackNode* stackPushStackP(Stack *dataStructure, const volatile Stack* value) {
  return stackPushEntry(dataStructure, value, typeStackNoCopy);
}
static inline StackNode* stackPushRedBlackTree(Stack *dataStructure, RedBlackTree value) {
  return stackPushEntry(dataStructure, &value, typeRedBlackTree);
}
static inline StackNode* stackPushRedBlackTreeP(Stack *dataStructure, const volatile RedBlackTree* value) {
  return stackPushEntry(dataStructure, value, typeRedBlackTreeNoCopy);
}
static inline StackNode* stackPushHashTable(Stack *dataStructure, HashTable value) {
  return stackPushEntry(dataStructure, &value, typeHashTable);
}
static inline StackNode* stackPushHashTableP(Stack *dataStructure, const volatile HashTable* value) {
  return stackPushEntry(dataStructure, value, typeHashTableNoCopy);
}
static inline StackNode* stackPushVector(Stack *dataStructure, Vector value) {
  return stackPushEntry(dataStructure, &value, typeVector);
}
static inline StackNode* stackPushVectorP(Stack *dataStructure, const volatile Vector* value) {
  return stackPushEntry(dataStructure, value, typeVectorNoCopy);
}
static inline StackNode* stackPushString(Stack *dataStructure, const volatile char* value) {
  return stackPushEntry(dataStructure, value, typeString);
}
static inline StackNode* stackPushStringP(Stack *dataStructure, const volatile char** value) {
  return stackPushEntry(dataStructure, *value, typeStringNoCopy);
}
static inline StackNode* stackPushBytes(Stack *dataStructure, Bytes value) {
  return stackPushEntry(dataStructure, value, typeBytes);
}
static inline StackNode* stackPushBytesP(Stack *dataStructure, const volatile Bytes* value) {
  return stackPushEntry(dataStructure, *value, typeBytesNoCopy);
}
static inline StackNode* stackPushPointer(Stack *dataStructure, void* value) {
  return stackPushEntry(dataStructure, value, typePointer);
}
static inline StackNode* stackPushPointerP(Stack *dataStructure, const volatile void** value) {
  return stackPushEntry(dataStructure, *value, typePointerNoCopy);
}
static inline StackNode* stackPushI8(Stack *dataStructure, i8 value) {
  return stackPushEntry(dataStructure, &value, typeI8);
}
static inline StackNode* stackPushU8(Stack *dataStructure, u8 value) {
  return stackPushEntry(dataStructure, &value, typeU8);
}

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#if defined __STDC_VERSION__

#if __STDC_VERSION__ >= 201710L
#define TYPE_SAFE_STACK

#define STACK_PUSH_GENERIC_CASES(dataStructure, value) \
  bool:                  stackPushBool,                              \
  bool*:                 stackPushBoolP,                             \
  const volatile bool*:  stackPushBoolP,                             \
  i16:                   stackPushI16,                               \
  i16*:                  stackPushI16P,                              \
  const volatile i16*:   stackPushI16P,                              \
  u16:                   stackPushU16,                               \
  u16*:                  stackPushU16P,                              \
  const volatile u16*:   stackPushU16P,                              \
  i32:                   stackPushI32,                               \
  i32*:                  stackPushI32P,                              \
  const volatile i32*:   stackPushI32P,                              \
  u32:                   stackPushU32,                               \
  u32*:                  stackPushU32P,                              \
  const volatile u32*:   stackPushU32P,                              \
  i64:                   stackPushI64,                               \
  i64*:                  stackPushI64P,                              \
  const volatile i64*:   stackPushI64P,                              \
  u64:                   stackPushU64,                               \
  u64*:                  stackPushU64P,                              \
  const volatile u64*:   stackPushU64P,                              \
  float:                 stackPushFloat,                             \
  float*:                stackPushFloatP,                            \
  const volatile float*: stackPushFloatP,                            \
  double:                stackPushDouble,                            \
  double*:               stackPushDoubleP,                           \
  const volatile double*: stackPushDoubleP,                           \
  long double:           stackPushLongDouble,                        \
  long double*:          stackPushLongDoubleP,                       \
  const volatile long double*: stackPushLongDoubleP,                       \
  List:                  stackPushList,                              \
  List*:                 stackPushListP,                             \
  const volatile List*:  stackPushListP,                             \
  Queue:                 stackPushQueue,                             \
  Queue*:                stackPushQueueP,                            \
  const volatile Queue*: stackPushQueueP,                            \
  Stack:                 stackPushStack,                             \
  Stack*:                stackPushStackP,                            \
  const volatile Stack*: stackPushStackP,                            \
  RedBlackTree:          stackPushRedBlackTree,                      \
  RedBlackTree*:         stackPushRedBlackTreeP,                     \
  const volatile RedBlackTree*: stackPushRedBlackTreeP,                     \
  HashTable:             stackPushHashTable,                         \
  HashTable*:            stackPushHashTableP,                        \
  const volatile HashTable*: stackPushHashTableP,                        \
  Vector:                stackPushVector,                            \
  Vector*:               stackPushVectorP,                           \
  const volatile Vector*: stackPushVectorP,                           \
  char*:                 stackPushString,                            \
  const volatile char*:  stackPushString,                            \
  char**:                stackPushStringP,                           \
  const volatile char**: stackPushStringP,                           \
  Bytes:                 stackPushBytes,                             \
  Bytes*:                stackPushBytesP,                            \
  const volatile Bytes*: stackPushBytesP,                            \
  void*:                 stackPushPointer,                           \
  void**:                stackPushPointerP,                          \
  const volatile void**: stackPushPointerP,                          \
  i8:                    stackPushI8,                                \
  u8:                    stackPushU8                                 \

#define stackPush(dataStructure, value) _Generic((value), \
  STACK_PUSH_GENERIC_CASES(dataStructure, value) \
  )(dataStructure, value)

#endif // __STDC_VERSION__

#elif defined __cplusplus // __STDC_VERSION__ is *NOT* defined
#define TYPE_SAFE_STACK

// Define the C++ function overloads.

static inline StackNode* stackPush(Stack *dataStructure, bool value) {
  return stackPushBool(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile bool* value) {
  return stackPushBoolP(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, i16 value) {
  return stackPushI16(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile i16* value) {
  return stackPushI16P(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, u16 value) {
  return stackPushU16(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile u16* value) {
  return stackPushU16P(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, i32 value) {
  return stackPushI32(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile i32* value) {
  return stackPushI32P(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, u32 value) {
  return stackPushU32(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile u32* value) {
  return stackPushU32P(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, i64 value) {
  return stackPushI64(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile i64* value) {
  return stackPushI64P(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, u64 value) {
  return stackPushU64(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile u64* value) {
  return stackPushU64P(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, float value) {
  return stackPushFloat(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile float* value) {
  return stackPushFloatP(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, double value) {
  return stackPushDouble(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile double* value) {
  return stackPushDoubleP(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, long double value) {
  return stackPushLongDouble(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile long double* value) {
  return stackPushLongDoubleP(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, List value) {
  return stackPushList(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile List* value) {
  return stackPushListP(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, Queue value) {
  return stackPushQueue(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile Queue* value) {
  return stackPushQueueP(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, Stack value) {
  return stackPushStack(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile Stack* value) {
  return stackPushStackP(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, RedBlackTree value) {
  return stackPushRedBlackTree(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile RedBlackTree* value) {
  return stackPushRedBlackTreeP(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, HashTable value) {
  return stackPushHashTable(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile HashTable* value) {
  return stackPushHashTableP(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, Vector value) {
  return stackPushVector(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile Vector* value) {
  return stackPushVectorP(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile char* value) {
  return stackPushString(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile char** value) {
  return stackPushStringP(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, Bytes value) {
  return stackPushBytes(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile Bytes* value) {
  return stackPushBytesP(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, void* value) {
  return stackPushPointer(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, const volatile void** value) {
  return stackPushPointerP(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, i8 value) {
  return stackPushI8(dataStructure, value);
}
static inline StackNode* stackPush(Stack *dataStructure, u8 value) {
  return stackPushU8(dataStructure, value);
}

#endif // __cplusplus

#endif // TYPE_SAFE_STACK_PUSH_H

