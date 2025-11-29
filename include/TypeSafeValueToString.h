///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              09.29.2023
///
/// @file              TypeSafeValueToString.h
///
/// @brief             This header contains type-safe versions of the
///                    valueToString function.
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


#ifndef TYPE_SAFE_TO_STRING_H
#define TYPE_SAFE_TO_STRING_H

#include "DataTypes.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Type-safe inline functions.

static inline char* valueToStringBool(bool value) {
  return typeBool->toString(&value);
}
static inline char* valueToStringBoolP(const volatile bool *value) {
  return typeBool->toString(value);
}
static inline char* valueToStringI16(i16 value) {
  return typeI16->toString(&value);
}
static inline char* valueToStringI16P(const volatile i16 *value) {
  return typeI16->toString(value);
}
static inline char* valueToStringU16(u16 value) {
  return typeU16->toString(&value);
}
static inline char* valueToStringU16P(const volatile u16 *value) {
  return typeU16->toString(value);
}
static inline char* valueToStringI32(i32 value) {
  return typeI32->toString(&value);
}
static inline char* valueToStringI32P(const volatile i32 *value) {
  return typeI32->toString(value);
}
static inline char* valueToStringU32(u32 value) {
  return typeU32->toString(&value);
}
static inline char* valueToStringU32P(const volatile u32 *value) {
  return typeU32->toString(value);
}
static inline char* valueToStringI64(i64 value) {
  return typeI64->toString(&value);
}
static inline char* valueToStringI64P(const volatile i64 *value) {
  return typeI64->toString(value);
}
static inline char* valueToStringU64(u64 value) {
  return typeU64->toString(&value);
}
static inline char* valueToStringU64P(const volatile u64 *value) {
  return typeU64->toString(value);
}
static inline char* valueToStringFloat(float value) {
  return typeFloat->toString(&value);
}
static inline char* valueToStringFloatP(const volatile float *value) {
  return typeFloat->toString(value);
}
static inline char* valueToStringDouble(double value) {
  return typeDouble->toString(&value);
}
static inline char* valueToStringDoubleP(const volatile double *value) {
  return typeDouble->toString(value);
}
static inline char* valueToStringLongDouble(long double value) {
  return typeLongDouble->toString(&value);
}
static inline char* valueToStringLongDoubleP(const volatile long double *value) {
  return typeLongDouble->toString(value);
}
static inline char* valueToStringList(List value) {
  return typeList->toString(&value);
}
static inline char* valueToStringListP(const volatile List *value) {
  return typeList->toString(value);
}
static inline char* valueToStringQueue(Queue value) {
  return typeQueue->toString(&value);
}
static inline char* valueToStringQueueP(const volatile Queue *value) {
  return typeQueue->toString(value);
}
static inline char* valueToStringStack(Stack value) {
  return typeStack->toString(&value);
}
static inline char* valueToStringStackP(const volatile Stack *value) {
  return typeStack->toString(value);
}
static inline char* valueToStringRedBlackTree(RedBlackTree value) {
  return typeRedBlackTree->toString(&value);
}
static inline char* valueToStringRedBlackTreeP(const volatile RedBlackTree *value) {
  return typeRedBlackTree->toString(value);
}
static inline char* valueToStringHashTable(HashTable value) {
  return typeHashTable->toString(&value);
}
static inline char* valueToStringHashTableP(const volatile HashTable *value) {
  return typeHashTable->toString(value);
}
static inline char* valueToStringVector(Vector value) {
  return typeVector->toString(&value);
}
static inline char* valueToStringVectorP(const volatile Vector *value) {
  return typeVector->toString(value);
}
static inline char* valueToStringPointer(void *value) {
  return typePointer->toString(&value);
}
static inline char* valueToStringI8(i8 value) {
  return typeI8->toString(&value);
}
static inline char* valueToStringU8(u8 value) {
  return typeU8->toString(&value);
}

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#if defined __STDC_VERSION__

#if __STDC_VERSION__ >= 201710L
#define TYPE_SAFE_TO_STRING

#define TYPE_TO_STRING_GENERIC_CASES(value) \
  bool:                         valueToStringBool,            \
  bool*:                        valueToStringBoolP,           \
  const volatile bool*:         valueToStringBoolP,           \
  i16:                          valueToStringI16,             \
  i16*:                         valueToStringI16P,            \
  const volatile i16*:          valueToStringI16P,            \
  u16:                          valueToStringU16,             \
  u16*:                         valueToStringU16P,            \
  const volatile u16*:          valueToStringU16P,            \
  i32:                          valueToStringI32,             \
  i32*:                         valueToStringI32P,            \
  const volatile i32*:          valueToStringI32P,            \
  u32:                          valueToStringU32,             \
  u32*:                         valueToStringU32P,            \
  const volatile u32*:          valueToStringU32P,            \
  i64:                          valueToStringI64,             \
  i64*:                         valueToStringI64P,            \
  const volatile i64*:          valueToStringI64P,            \
  u64:                          valueToStringU64,             \
  u64*:                         valueToStringU64P,            \
  const volatile u64*:          valueToStringU64P,            \
  float:                        valueToStringFloat,           \
  float*:                       valueToStringFloatP,          \
  const volatile float*:        valueToStringFloatP,          \
  double:                       valueToStringDouble,          \
  double*:                      valueToStringDoubleP,         \
  const volatile double*:       valueToStringDoubleP,         \
  long double:                  valueToStringLongDouble,      \
  long double*:                 valueToStringLongDoubleP,     \
  const volatile long double*:  valueToStringLongDoubleP,     \
  List:                         valueToStringList,            \
  List*:                        valueToStringListP,           \
  const volatile List*:         valueToStringListP,           \
  Queue:                        valueToStringQueue,           \
  Queue*:                       valueToStringQueueP,          \
  const volatile Queue*:        valueToStringQueueP,          \
  Stack:                        valueToStringStack,           \
  Stack*:                       valueToStringStackP,          \
  const volatile Stack*:        valueToStringStackP,          \
  RedBlackTree:                 valueToStringRedBlackTree,    \
  RedBlackTree*:                valueToStringRedBlackTreeP,   \
  const volatile RedBlackTree*: valueToStringRedBlackTreeP,   \
  HashTable:                    valueToStringHashTable,       \
  HashTable*:                   valueToStringHashTableP,      \
  const volatile HashTable*:    valueToStringHashTableP,      \
  Vector:                       valueToStringVector,          \
  Vector*:                      valueToStringVectorP,         \
  const volatile Vector*:       valueToStringVectorP,         \
  void*:                        valueToStringPointer,         \
  i8:                           valueToStringI8,              \
  u8:                           valueToStringU8               \

#define valueToString(value) _Generic((value), \
  TYPE_TO_STRING_GENERIC_CASES(value) \
  )(value)

#endif // __STDC_VERSION__

#elif defined __cplusplus // __STDC_VERSION__ is *NOT* defined
#define TYPE_SAFE_TO_STRING

// Define the C++ function overloads.

static inline char* valueToString(bool value) {
  return typeBool->toString(&value);
}
static inline char* valueToString(const volatile bool *value) {
  return typeBool->toString(value);
}
static inline char* valueToString(i16 value) {
  return typeI16->toString(&value);
}
static inline char* valueToString(const volatile i16 *value) {
  return typeI16->toString(value);
}
static inline char* valueToString(u16 value) {
  return typeU16->toString(&value);
}
static inline char* valueToString(const volatile u16 *value) {
  return typeU16->toString(value);
}
static inline char* valueToString(i32 value) {
  return typeI32->toString(&value);
}
static inline char* valueToString(const volatile i32 *value) {
  return typeI32->toString(value);
}
static inline char* valueToString(u32 value) {
  return typeU32->toString(&value);
}
static inline char* valueToString(const volatile u32 *value) {
  return typeU32->toString(value);
}
static inline char* valueToString(i64 value) {
  return typeI64->toString(&value);
}
static inline char* valueToString(const volatile i64 *value) {
  return typeI64->toString(value);
}
static inline char* valueToString(u64 value) {
  return typeU64->toString(&value);
}
static inline char* valueToString(const volatile u64 *value) {
  return typeU64->toString(value);
}
static inline char* valueToString(float value) {
  return typeFloat->toString(&value);
}
static inline char* valueToString(const volatile float *value) {
  return typeFloat->toString(value);
}
static inline char* valueToString(double value) {
  return typeDouble->toString(&value);
}
static inline char* valueToString(const volatile double *value) {
  return typeDouble->toString(value);
}
static inline char* valueToString(long double value) {
  return typeLongDouble->toString(&value);
}
static inline char* valueToString(const volatile long double *value) {
  return typeLongDouble->toString(value);
}
static inline char* valueToString(List value) {
  return typeList->toString(&value);
}
static inline char* valueToString(const volatile List *value) {
  return typeList->toString(value);
}
static inline char* valueToString(Queue value) {
  return typeQueue->toString(&value);
}
static inline char* valueToString(const volatile Queue *value) {
  return typeQueue->toString(value);
}
static inline char* valueToString(Stack value) {
  return typeStack->toString(&value);
}
static inline char* valueToString(const volatile Stack *value) {
  return typeStack->toString(value);
}
static inline char* valueToString(RedBlackTree value) {
  return typeRedBlackTree->toString(&value);
}
static inline char* valueToString(const volatile RedBlackTree *value) {
  return typeRedBlackTree->toString(value);
}
static inline char* valueToString(HashTable value) {
  return typeHashTable->toString(&value);
}
static inline char* valueToString(const volatile HashTable *value) {
  return typeHashTable->toString(value);
}
static inline char* valueToString(Vector value) {
  return typeVector->toString(&value);
}
static inline char* valueToString(const volatile Vector *value) {
  return typeVector->toString(value);
}
static inline char* valueToString(void *value) {
  return typePointer->toString(&value);
}
static inline char* valueToString(i8 value) {
  return typeI8->toString(&value);
}
static inline char* valueToString(u8 value) {
  return typeU8->toString(&value);
}

#endif // __cplusplus

#endif // TYPE_SAFE_TO_STRING_H

