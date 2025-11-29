///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              09.29.2023
///
/// @file              TypeSafeAmong.h
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

#ifndef TYPE_SAFE_AMONG_H
#define TYPE_SAFE_AMONG_H

#include <stdarg.h>
#include "DataTypes.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Prototypes for functions defined in DataTypes.c
bool amongVaPointer(
  int (*compare)(const volatile void*, const volatile void*),
  const volatile void *needle, va_list args);
bool amongVa64(u64 needle, va_list args);
bool amongVa32(u32 needle, va_list args);
bool amongVa16(u16 needle, va_list args);
bool amongVa8(u8 needle, va_list args);
bool amongVaFloat(float needle, va_list args);
bool amongVaDouble(double needle, va_list args);

static inline bool amongI8(i8 needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVa8(*((u8*) &needle), args);
  va_end(args);
  return returnValue;
}
static inline bool amongU8(u8 needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVa8(*((u8*) &needle), args);
  va_end(args);
  return returnValue;
}
static inline bool amongI16(i16 needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVa16(*((u16*) &needle), args);
  va_end(args);
  return returnValue;
}
static inline bool amongI16P(const volatile i16 *needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeI16->compare, needle, args);
  va_end(args);
  return returnValue;
}
static inline bool amongU16(u16 needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVa16(*((u16*) &needle), args);
  va_end(args);
  return returnValue;
}
static inline bool amongU16P(const volatile u16 *needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeU16->compare, needle, args);
  va_end(args);
  return returnValue;
}
static inline bool amongI32(i32 needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVa32(*((u32*) &needle), args);
  va_end(args);
  return returnValue;
}
static inline bool amongI32P(const volatile i32 *needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeI32->compare, needle, args);
  va_end(args);
  return returnValue;
}
static inline bool amongU32(u32 needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVa32(*((u32*) &needle), args);
  va_end(args);
  return returnValue;
}
static inline bool amongU32P(const volatile u32 *needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeU32->compare, needle, args);
  va_end(args);
  return returnValue;
}
static inline bool amongI64(i64 needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVa64(*((u64*) &needle), args);
  va_end(args);
  return returnValue;
}
static inline bool amongI64P(const volatile i64 *needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeI64->compare, needle, args);
  va_end(args);
  return returnValue;
}
static inline bool amongU64(u64 needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVa64(*((u64*) &needle), args);
  va_end(args);
  return returnValue;
}
static inline bool amongU64P(const volatile u64 *needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeU64->compare, needle, args);
  va_end(args);
  return returnValue;
}
static inline bool amongFloat(float needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaFloat(needle, args);
  va_end(args);
  return returnValue;
}
static inline bool amongFloatP(const volatile float *needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeFloat->compare, needle, args);
  va_end(args);
  return returnValue;
}
static inline bool amongDouble(double needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaDouble(needle, args);
  va_end(args);
  return returnValue;
}
static inline bool amongDoubleP(const volatile double *needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeDouble->compare, needle, args);
  va_end(args);
  return returnValue;
}
static inline bool amongString(const volatile char *needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeString->compare, needle, args);
  va_end(args);
  return returnValue;
}
static inline bool amongBytes(const volatile Bytes needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeBytes->compare, needle, args);
  va_end(args);
  return returnValue;
}

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#if defined __STDC_VERSION__

#if __STDC_VERSION__ >= 201710L
#define TYPE_SAFE_AMONG

#define AMONG_GENERIC_CASES(needle)      \
  i8:                           amongI8,      \
                                              \
  u8:                           amongU8,      \
                                              \
  i16:                          amongI16,     \
  i16*:                         amongI16P,    \
  const volatile i16*:          amongI16P,    \
                                              \
  u16:                          amongU16,     \
  u16*:                         amongU16P,    \
  const volatile u16*:          amongU16P,    \
                                              \
  i32:                          amongI32,     \
  i32*:                         amongI32P,    \
  const volatile i32*:          amongI32P,    \
                                              \
  u32:                          amongU32,     \
  u32*:                         amongU32P,    \
  const volatile u32*:          amongU32P,    \
                                              \
  i64:                          amongI64,     \
  i64*:                         amongI64P,    \
  const volatile i64*:          amongI64P,    \
                                              \
  u64:                          amongU64,     \
  u64*:                         amongU64P,    \
  const volatile u64*:          amongU64P,    \
                                              \
  float:                        amongFloat,   \
  float*:                       amongFloatP,  \
  const volatile float*:        amongFloatP,  \
                                              \
  double:                       amongDouble,  \
  double*:                      amongDoubleP, \
  const volatile double*:       amongDoubleP, \
                                              \
  char*:                        amongString,  \
  const volatile char*:         amongString,  \
                                              \
  Bytes:                        amongBytes,   \
  const volatile Bytes:         amongBytes    \

#define among_(needle, ...) _Generic((needle), \
  AMONG_GENERIC_CASES(needle) \
  )(needle, __VA_ARGS__)

#endif // __STDC_VERSION__

#elif defined __cplusplus // __STDC_VERSION__ is *NOT* defined
#define TYPE_SAFE_AMONG

// Define the C++ function overloads.

static inline bool among_(i8 needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVa8(*((u8*) &needle), args);
  va_end(args);
  return returnValue;
}
static inline bool among_(u8 needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVa8(*((u8*) &needle), args);
  va_end(args);
  return returnValue;
}
static inline bool among_(i16 needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVa16(*((u16*) &needle), args);
  va_end(args);
  return returnValue;
}
static inline bool among_(const volatile i16 *needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeI16->compare, needle, args);
  va_end(args);
  return returnValue;
}
static inline bool among_(u16 needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVa16(*((u16*) &needle), args);
  va_end(args);
  return returnValue;
}
static inline bool among_(const volatile u16 *needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeU16->compare, needle, args);
  va_end(args);
  return returnValue;
}
static inline bool among_(i32 needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVa32(*((u32*) &needle), args);
  va_end(args);
  return returnValue;
}
static inline bool among_(const volatile i32 *needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeI32->compare, needle, args);
  va_end(args);
  return returnValue;
}
static inline bool among_(u32 needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVa32(*((u32*) &needle), args);
  va_end(args);
  return returnValue;
}
static inline bool among_(const volatile u32 *needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeU32->compare, needle, args);
  va_end(args);
  return returnValue;
}
static inline bool among_(i64 needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVa64(*((u64*) &needle), args);
  va_end(args);
  return returnValue;
}
static inline bool among_(const volatile i64 *needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeI64->compare, needle, args);
  va_end(args);
  return returnValue;
}
static inline bool among_(u64 needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVa64(*((u64*) &needle), args);
  va_end(args);
  return returnValue;
}
static inline bool among_(const volatile u64 *needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeU64->compare, needle, args);
  va_end(args);
  return returnValue;
}
static inline bool among_(float needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaFloat(needle, args);
  va_end(args);
  return returnValue;
}
static inline bool among_(const volatile float *needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeFloat->compare, needle, args);
  va_end(args);
  return returnValue;
}
static inline bool among_(double needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaDouble(needle, args);
  va_end(args);
  return returnValue;
}
static inline bool among_(const volatile double *needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeDouble->compare, needle, args);
  va_end(args);
  return returnValue;
}
static inline bool among_(const volatile char *needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeString->compare, needle, args);
  va_end(args);
  return returnValue;
}
static inline bool among_(const volatile Bytes needle, ...) {
  va_list args;
  va_start(args, needle);
  bool returnValue = amongVaPointer(typeBytes->compare, needle, args);
  va_end(args);
  return returnValue;
}

#endif // __cplusplus

#define among(needle, ...) among_(needle, __VA_ARGS__, ((u64) 0), ((u64) 0))
#define amongZeroOr(needle, ...) \
  ((needle == 0) || (among(needle, __VA_ARGS__)))
#define amongNullOr(needle, ...) \
  ((needle == NULL) || (among(needle, __VA_ARGS__)))

#endif // TYPE_SAFE_AMONG_H

