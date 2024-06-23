///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              04.06.2019
///
/// @file              TypeDefinitions.h
///
/// @brief             These are the primitive type definitions that are
///                    used across the data structure libraries and
///                    elsewhere.
///
/// @details
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

#ifndef TYPE_DEFINITIONS_H
#define TYPE_DEFINITIONS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <string.h> // For memcmp

#ifdef __cplusplus
extern "C"
{
#endif

// Define sized-based types.
typedef uint8_t                  u8;
typedef uint16_t                u16;
typedef uint32_t                u32;
typedef uint64_t                u64;
#ifdef _MSC_VER
typedef long long unsigned int u128;
#else // gcc
#if ( __WORDSIZE == 64 )
typedef __uint128_t            u128;
#else
typedef long long unsigned int u128;
#endif // 64-bit
#endif // _MSC_VER

typedef int8_t                   i8;
typedef int16_t                 i16;
typedef int32_t                 i32;
typedef int64_t                 i64;
#ifdef _MSC_VER
typedef long long int          i128;
#else // gcc
#if ( __WORDSIZE == 64 )
typedef __int128_t             i128;
#else
typedef long long int          i128;
#endif // 64-bit
#endif // _MSC_VER

typedef float                   f32;
typedef double                  f64;
typedef long double      longDouble;

/// @struct BytesHeader
///
/// @brief The header for a Bytes object that is before the pointer.
///
/// @param length The length of the data at the pointer, minus the trailing
///   NULL terminator byte.
/// @param size The number of bytes actually allocated at the pointer.  This is
///   oftentimes length + 1;
typedef struct BytesHeader {
  u64 length;
  u64 size;
} BytesHeader;

typedef unsigned char Byte;
typedef Byte *Bytes;


#define llu(x)   ((long long unsigned int) (x))
#define lli(x)   ((long long int) (x))
#define lld      lli
#define str(x)   ((char*) ((void*) (x)))
#define ustr(x)  ((unsigned char*) ((void*) (x)))

/// @def literalU128
/// Convenience macro for defining a 128-bit unsigned literal.
#define literalU128(high, midHigh, midLow, low) ( \
  (((u128) high)    << 96) | \
  (((u128) midHigh) << 64) | \
  (((u128) midLow)  << 32) | \
  (((u128) low)     << 0) \
)

/// @def literalI128
/// Convenience macro for defining a 128-bit signed literal.
#define literalI128(high, midHigh, midLow, low) ( \
  (((i128) high)    << 96) | \
  (((i128) midHigh) << 64) | \
  (((i128) midLow)  << 32) | \
  (((i128) low)     << 0) \
)

/// @def literalU64
/// Convenience macro for defining a 64-bit unsigned literal.
#define literalU64(high, low) ( \
  (((u64) high) << 32) | \
  (((u64) low)  << 0) \
)

/// @def literalI64
/// Convenience macro for defining a 64-bit signed literal.
#define literalI64(high, low) ( \
  (((i64) high) << 32) | \
  (((i64) low)  << 0) \
)

#define STOP               ((void*) -1)
#define VOID_POINTER_TRUE  ((void*) ((intptr_t) true))
#define VOID_POINTER_FALSE ((void*) ((intptr_t) false))

#define tssInc(tss) \
  do { \
    intptr_t tssVal = (intptr_t) tss_get(tss); \
    tssVal++; \
    tss_set(tss, (void*) tssVal); \
  } while (0)
#define tssDec(tss) \
  do { \
    intptr_t tssVal = (intptr_t) tss_get(tss); \
    tssVal--; \
    tss_set(tss, (void*) tssVal); \
  } while (0)
#define tssEqual(tss, val) \
  ((intptr_t) tss_get(tss) == (intptr_t) val)

#ifdef __cplusplus
#ifdef _MSC_VER
#define ZEROINIT(x) x = {0}
#else // Non-Visual Studio C++
#define ZEROINIT(x) x = {}
#endif // _MSC_VER
#else // __cplusplus not defined
#define ZEROINIT(x) x = {0}
#endif // __cplusplus

#if defined(_MSC_VER) && !defined(ssize_t)
#ifdef _WIN64
#define ssize_t __int64
#else
#define ssize_t long
#endif
#endif // _MSC_VER && !ssize_t

#ifdef _MSC_VER
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable : 4996)
#endif // _MSC_VER

#define MAX(x, y) (((x) > (y)) ? (x) : (y) )
#define MIN(x, y) (((x) < (y)) ? (x) : (y) )
#define ABS(x)    (((x) >= 0 ) ? (x) : (-x))

#define structcmp(struct1, struct2) \
  ((sizeof(struct1) == sizeof(struct2)) \
    ? memcmp(&(struct1), &(struct2), sizeof(struct1)) \
    /* structs can only be compared for equality.  If they're not the same */ \
    /* size, they're not equal, so any non-zero value will do. */ \
    : -1 \
  )

#define numElements(array) ((int) (sizeof(array) / sizeof(array[0])))
#define zeroArray(array) \
  for (size_t ii = 0; ii < numElements(array); ++ii) array[ii] = 0

typedef void (*Destructor)(void*);

#define ptrDiff(larger, smaller) \
  (u64) (((uintptr_t) larger) - ((uintptr_t) smaller))

#ifdef __cplusplus
} // extern "C"
#endif

#endif // TYPE_DEFINITIONS_H

