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

// Defines common to both C and C++

#define AMONG_SELF(dataType, size, typeType) \
static inline bool among##typeType(dataType needle, dataType haystack, ...) { \
  va_list args; \
  va_start(args, haystack); \
  /* AMONG_SELF is only used for unsigned types, so no casting needed. */ \
  bool returnValue = amongVa##size(needle, haystack, args); \
  va_end(args); \
  return returnValue; \
}

#define AMONG_INT(dataType, typeChar, typePChar, typeShort, typePShort, \
  typeInt, typePInt, typeLong, typePLong, typeLonglong, typePLonglong) \
static inline bool among##typeChar(const volatile dataType needle, char haystack, ...) { \
  va_list args; \
  va_start(args, haystack); \
  bool returnValue = amongVaChar((unsigned char) needle, (unsigned char) haystack, args); \
  va_end(args); \
  return returnValue; \
} \
static inline bool among##typePChar(const volatile dataType *needle, char haystack, ...) { \
  if (needle == NULL) { \
    return false; \
  } \
  va_list args; \
  va_start(args, haystack); \
  bool returnValue = amongVaChar((unsigned char) *needle, (unsigned char) haystack, args); \
  va_end(args); \
  return returnValue; \
} \
static inline bool among##typeShort(dataType needle, short haystack, ...) { \
  va_list args; \
  va_start(args, haystack); \
  bool returnValue = amongVaShort((unsigned short) needle, (unsigned short) haystack, args); \
  va_end(args); \
  return returnValue; \
} \
static inline bool among##typePShort(const volatile dataType *needle, short haystack, ...) { \
  if (needle == NULL) { \
    return false; \
  } \
  va_list args; \
  va_start(args, haystack); \
  bool returnValue = amongVaShort((unsigned short) *needle, (unsigned short) haystack, args); \
  va_end(args); \
  return returnValue; \
} \
static inline bool among##typeInt(dataType needle, int haystack, ...) { \
  va_list args; \
  va_start(args, haystack); \
  bool returnValue = amongVaInt((unsigned int) needle, (unsigned int) haystack, args); \
  va_end(args); \
  return returnValue; \
} \
static inline bool among##typePInt(const volatile dataType *needle, int haystack, ...) { \
  if (needle == NULL) { \
    return false; \
  } \
  va_list args; \
  va_start(args, haystack); \
  bool returnValue = amongVaInt((unsigned int) *needle, (unsigned int) haystack, args); \
  va_end(args); \
  return returnValue; \
} \
static inline bool among##typeLong(dataType needle, long haystack, ...) { \
  va_list args; \
  va_start(args, haystack); \
  bool returnValue = amongVaLong((unsigned long) needle, (unsigned long) haystack, args); \
  va_end(args); \
  return returnValue; \
} \
static inline bool among##typePLong(const volatile dataType *needle, long haystack, ...) { \
  if (needle == NULL) { \
    return false; \
  } \
  va_list args; \
  va_start(args, haystack); \
  bool returnValue = amongVaLong((unsigned long) *needle, (unsigned long) haystack, args); \
  va_end(args); \
  return returnValue; \
} \
static inline bool among##typeLonglong(dataType needle, long long haystack, ...) { \
  va_list args; \
  va_start(args, haystack); \
  bool returnValue = amongVaLonglong((unsigned long long) needle, (unsigned long long) haystack, args); \
  va_end(args); \
  return returnValue; \
} \
static inline bool among##typePLonglong(const volatile dataType *needle, long long haystack, ...) { \
  if (needle == NULL) { \
    return false; \
  } \
  va_list args; \
  va_start(args, haystack); \
  bool returnValue = amongVaLonglong((unsigned long long) *needle, (unsigned long long) haystack, args); \
  va_end(args); \
  return returnValue; \
}

#define AMONG_POINTER(dataType, comparisonFn, typePTypeP) \
static inline bool among##typePTypeP(const volatile dataType *needle, const volatile dataType *haystack, ...) { \
  va_list args; \
  va_start(args, haystack); \
  bool returnValue = amongVaPointer(comparisonFn, needle, haystack, args); \
  va_end(args); \
  return returnValue; \
}

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Prototypes for functions defined in DataTypes.c
bool amongVaPointer(
  int (*compare)(const volatile void*, const volatile void*),
  const volatile void *needle, const volatile void *haystack, va_list args);
bool amongVaFloat(float needle, float haystack, va_list args);
bool amongVaDouble(double needle, double haystack, va_list args);
bool amongVaChar(unsigned char needle, unsigned char haystack, va_list args);
bool amongVaShort(unsigned short needle, unsigned short haystack, va_list args);
bool amongVaInt(unsigned int needle, unsigned int haystack, va_list args);
bool amongVaLong(unsigned long needle, unsigned long haystack, va_list args);
bool amongVaLonglong(unsigned long long needle, unsigned long long haystack, va_list args);

// New comparison functions that we had to add just for among.
int shortCompare(const volatile void *valueA, const volatile void *valueB);
int intCompare(const volatile void *valueA, const volatile void *valueB);
int longCompare(const volatile void *valueA, const volatile void *valueB);
int longlongCompare(const volatile void *valueA, const volatile void *valueB);
int ushortCompare(const volatile void *valueA, const volatile void *valueB);
int uintCompare(const volatile void *valueA, const volatile void *valueB);
int ulongCompare(const volatile void *valueA, const volatile void *valueB);
int ulonglongCompare(const volatile void *valueA, const volatile void *valueB);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

// Handle strings and Bytes specially
static inline bool amongString(const volatile char *needle, const volatile char *haystack, ...) {
  va_list args;
  va_start(args, haystack);
  bool returnValue = amongVaPointer(typeString->compare, needle, haystack, args);
  va_end(args);
  return returnValue;
}
static inline bool amongBytes(const volatile Bytes needle, const volatile Bytes haystack, ...) {
  va_list args;
  va_start(args, haystack);
  bool returnValue = amongVaPointer(typeBytes->compare, needle, haystack, args);
  va_end(args);
  return returnValue;
}

// Handling strings and Bytes specially means we also have to handle char and
// unsigned char types specially.  Specifically, we can't use AMONG_POINTER.
AMONG_INT(signed char, ICharChar, ICharPChar, ICharShort, ICharPShort, ICharInt, ICharPInt,
  ICharLong, ICharPLong, ICharLonglong, ICharPLonglong)
AMONG_INT(char, CharChar, CharPChar, CharShort, CharPShort, CharInt, CharPInt,
  CharLong, CharPLong, CharLonglong, CharPLonglong)

AMONG_SELF(unsigned char, Char, UCharUChar)
AMONG_INT(unsigned char, UCharChar, UCharPChar,
  UCharShort, UCharPShort, UCharInt, UCharPInt,
  UCharLong, UCharPLong, UCharLonglong, UCharPLonglong)

// Now do all the other types.  We can't use AMONG_SELF for the signed-integer
// types because that's already covered by AMONG_INT.

AMONG_INT(short, ShortChar, ShortPChar, ShortShort, ShortPShort,
  ShortInt, ShortPInt, ShortLong, ShortPLong, ShortLonglong, ShortPLonglong)
AMONG_POINTER(short, shortCompare, ShortPShortP)

AMONG_SELF(unsigned short, Short, UShortUShort)
AMONG_INT(unsigned short, UShortChar, UShortPChar,
  UShortShort, UShortPShort, UShortInt, UShortPInt,
  UShortLong, UShortPLong, UShortLonglong, UShortPLonglong)
AMONG_POINTER(unsigned short, ushortCompare, UShortPUShortP)

AMONG_INT(int, IntChar, IntPChar, IntShort, IntPShort, IntInt, IntPInt,
  IntLong, IntPLong, IntLonglong, IntPLonglong)
AMONG_POINTER(int, intCompare, IntPIntP)

AMONG_SELF(unsigned int, Int, UIntUInt)
AMONG_INT(unsigned int, UIntChar, UIntPChar, UIntShort, UIntPShort, UIntInt, UIntPInt,
  UIntLong, UIntPLong, UIntLonglong, UIntPLonglong)
AMONG_POINTER(unsigned int, uintCompare, UIntPUIntP)

AMONG_INT(long, LongChar, LongPChar, LongShort, LongPShort, LongInt, LongPInt,
  LongLong, LongPLong, LongLonglong, LongPLonglong)
AMONG_POINTER(long, longCompare, LongPLongP)

AMONG_SELF(unsigned long, Long, ULongULong)
AMONG_INT(unsigned long, ULongChar, ULongPChar, ULongShort, ULongPShort,
  ULongInt, ULongPInt, ULongLong, ULongPLong, ULongLonglong, ULongPLonglong)
AMONG_POINTER(unsigned long, ulongCompare, ULongPULongP)

AMONG_INT(long long, LonglongChar, LonglongPChar,
  LonglongShort, LonglongPShort, LonglongInt, LonglongPInt,
  LonglongLong, LonglongPLong, LonglongLonglong, LonglongPLonglong)
AMONG_POINTER(long long, longlongCompare, LonglongPLonglongP)

AMONG_SELF(unsigned long long, Longlong, ULonglongULonglong)
AMONG_INT(unsigned long long, ULonglongChar, ULonglongPChar,
  ULonglongShort, ULonglongPShort, ULonglongInt, ULonglongPInt,
  ULonglongLong, ULonglongPLong, ULonglongLonglong, ULonglongPLonglong)
AMONG_POINTER(unsigned long long, ulonglongCompare, ULonglongPULonglongP)

static inline bool amongFloatFloat(float needle, float haystack, ...) {
  va_list args;
  va_start(args, haystack);
  bool returnValue = amongVaFloat(needle, haystack, args);
  va_end(args);
  return returnValue;
}
static inline bool amongFloatDouble(float needle, double haystack, ...) {
  va_list args;
  va_start(args, haystack);
  bool returnValue = amongVaDouble((double) needle, haystack, args);
  va_end(args);
  return returnValue;
}
static inline bool amongFloatPDouble(float *needle, double haystack, ...) {
  va_list args;
  va_start(args, haystack);
  bool returnValue = amongVaDouble((double) *needle, haystack, args);
  va_end(args);
  return returnValue;
}
AMONG_POINTER(float, typeFloat->compare, FloatPFloatP)

static inline bool amongDoubleDouble(double needle, double haystack, ...) {
  va_list args;
  va_start(args, haystack);
  bool returnValue = amongVaDouble(needle, haystack, args);
  va_end(args);
  return returnValue;
}
static inline bool amongDoublePDouble(double *needle, double haystack, ...) {
  va_list args;
  va_start(args, haystack);
  bool returnValue = amongVaDouble(*needle, haystack, args);
  va_end(args);
  return returnValue;
}
AMONG_POINTER(double, typeDouble->compare, DoublePDoubleP)

#if defined __STDC_VERSION__

#if __STDC_VERSION__ >= 201710L
#define TYPE_SAFE_AMONG

#define amongIChar(haystack) _Generic((haystack),                \
  char:                               amongICharChar,            \
  short:                              amongICharShort,           \
  int:                                amongICharInt,             \
  long:                               amongICharLong,            \
  long long:                          amongICharLonglong,        \
                                                                 \
  default:                            amongICharInt              \
  )
#define amongICharP(haystack) _Generic((haystack),               \
  char:                               amongICharPChar,           \
  short:                              amongICharPShort,          \
  int:                                amongICharPInt,            \
  long:                               amongICharPLong,           \
  long long:                          amongICharPLonglong,       \
                                                                 \
  char*:                              amongString,               \
  const volatile char*:               amongString,               \
                                                                 \
  default:                            amongICharPInt             \
  )
#define amongChar(haystack) _Generic((haystack),                 \
  char:                               amongCharChar,             \
  short:                              amongCharShort,            \
  int:                                amongCharInt,              \
  long:                               amongCharLong,             \
  long long:                          amongCharLonglong,         \
                                                                 \
  default:                            amongCharInt               \
  )
#define amongCharP(haystack) _Generic((haystack),                \
  char:                               amongCharPChar,            \
  short:                              amongCharPShort,           \
  int:                                amongCharPInt,             \
  long:                               amongCharPLong,            \
  long long:                          amongCharPLonglong,        \
                                                                 \
  char*:                              amongString,               \
  const volatile char*:               amongString,               \
                                                                 \
  default:                            amongCharPInt              \
  )
#define amongUChar(haystack) _Generic((haystack),                \
  unsigned char:                      amongUCharUChar,           \
  char:                               amongUCharChar,            \
  short:                              amongUCharShort,           \
  int:                                amongUCharInt,             \
  long:                               amongUCharLong,            \
  long long:                          amongUCharLonglong,        \
                                                                 \
  default:                            amongUCharInt              \
  )
#define amongUCharP(haystack) _Generic((haystack),               \
  char:                               amongUCharPChar,           \
  short:                              amongUCharPShort,          \
  int:                                amongUCharPInt,            \
  long:                               amongUCharPLong,           \
  long long:                          amongUCharPLonglong,       \
                                                                 \
  unsigned char*:                     amongBytes,                \
  const volatile unsigned char*:      amongBytes,                \
                                                                 \
  default:                            amongUCharPInt             \
  )
#define amongShort(haystack) _Generic((haystack),                \
  char:                               amongShortChar,            \
  short:                              amongShortShort,           \
  int:                                amongShortInt,             \
  long:                               amongShortLong,            \
  long long:                          amongShortLonglong,        \
                                                                 \
  default:                            amongShortInt              \
  )
#define amongShortP(haystack) _Generic((haystack),               \
  char:                               amongShortPChar,           \
  short:                              amongShortPShort,          \
  int:                                amongShortPInt,            \
  long:                               amongShortPLong,           \
  long long:                          amongShortPLonglong,       \
                                                                 \
  short*:                             amongShortPShortP,         \
  const volatile short*:              amongShortPShortP,         \
                                                                 \
  default:                            amongShortPInt             \
  )
#define amongUShort(haystack) _Generic((haystack),               \
  unsigned short:                     amongUShortUShort,         \
  char:                               amongUShortChar,           \
  short:                              amongUShortShort,          \
  int:                                amongUShortInt,            \
  long:                               amongUShortLong,           \
  long long:                          amongUShortLonglong,       \
                                                                 \
  default:                            amongUShortInt             \
  )
#define amongUShortP(haystack) _Generic((haystack),              \
  char:                               amongUShortPChar,          \
  short:                              amongUShortPShort,         \
  int:                                amongUShortPInt,           \
  long:                               amongUShortPLong,          \
  long long:                          amongUShortPLonglong,      \
                                                                 \
  unsigned short*:                    amongUShortPUShortP,       \
  const volatile short*:              amongUShortPUShortP,       \
                                                                 \
  default:                            amongUShortPInt            \
  )
#define amongInt(haystack) _Generic((haystack),                  \
  char:                               amongIntChar,              \
  short:                              amongIntShort,             \
  int:                                amongIntInt,               \
  long:                               amongIntLong,              \
  long long:                          amongIntLonglong,          \
                                                                 \
  default:                            amongIntInt                \
  )
#define amongIntP(haystack) _Generic((haystack),                 \
  char:                               amongIntPChar,             \
  short:                              amongIntPShort,            \
  int:                                amongIntPInt,              \
  long:                               amongIntPLong,             \
  long long:                          amongIntPLonglong,         \
                                                                 \
  int*:                               amongIntPIntP,             \
  const volatile int*:                amongIntPIntP,             \
                                                                 \
  default:                            amongIntPInt               \
  )
#define amongUInt(haystack) _Generic((haystack),                 \
  unsigned int:                       amongUIntUInt,             \
  char:                               amongUIntChar,             \
  short:                              amongUIntShort,            \
  int:                                amongUIntInt,              \
  long:                               amongUIntLong,             \
  long long:                          amongUIntLonglong,         \
                                                                 \
  default:                            amongUIntInt               \
  )
#define amongUIntP(haystack) _Generic((haystack),                \
  char:                               amongUIntPChar,            \
  short:                              amongUIntPShort,           \
  int:                                amongUIntPInt,             \
  long:                               amongUIntPLong,            \
  long long:                          amongUIntPLonglong,        \
                                                                 \
  unsigned int*:                      amongUIntPUIntP,           \
  const volatile unsigned int*:       amongUIntPUIntP,           \
                                                                 \
  default:                            amongUIntPInt              \
  )
#define amongLong(haystack) _Generic((haystack),                 \
  char:                               amongLongChar,             \
  short:                              amongLongShort,            \
  int:                                amongLongInt,              \
  long:                               amongLongLong,             \
  long long:                          amongLongLonglong,         \
                                                                 \
  default:                            amongLongInt               \
  )
#define amongLongP(haystack) _Generic((haystack),                \
  char:                               amongLongPChar,            \
  short:                              amongLongPShort,           \
  int:                                amongLongPInt,             \
  long:                               amongLongPLong,            \
  long long:                          amongLongPLonglong,        \
                                                                 \
  long*:                              amongLongPLongP,           \
  const volatile long*:               amongLongPLongP,           \
                                                                 \
  default:                            amongLongPInt              \
  )
#define amongULong(haystack) _Generic((haystack),                \
  unsigned long:                      amongULongULong,           \
  char:                               amongULongChar,            \
  short:                              amongULongShort,           \
  int:                                amongULongInt,             \
  long:                               amongULongLong,            \
  long long:                          amongULongLonglong,        \
                                                                 \
  default:                            amongULongInt              \
  )
#define amongULongP(haystack) _Generic((haystack),               \
  char:                               amongULongPChar,           \
  short:                              amongULongPShort,          \
  int:                                amongULongPInt,            \
  long:                               amongULongPLong,           \
  long long:                          amongULongPLonglong,       \
                                                                 \
  unsigned long*:                     amongULongPULongP,         \
  const volatile unsigned long*:      amongULongPULongP,         \
                                                                 \
  default:                            amongULongPInt             \
  )
#define amongLonglong(haystack) _Generic((haystack),             \
  char:                               amongLonglongChar,         \
  short:                              amongLonglongShort,        \
  int:                                amongLonglongInt,          \
  long:                               amongLonglongLong,         \
  long long:                          amongLonglongLonglong,     \
                                                                 \
  default:                            amongLonglongInt           \
  )
#define amongLonglongP(haystack) _Generic((haystack),            \
  char:                               amongLonglongPChar,        \
  short:                              amongLonglongPShort,       \
  int:                                amongLonglongPInt,         \
  long:                               amongLonglongPLong,        \
  long long:                          amongLonglongPLonglong,    \
                                                                 \
  long long*:                         amongLonglongPLonglongP,   \
  const volatile long long*:          amongLonglongPLonglongP,   \
                                                                 \
  default:                            amongLonglongPInt          \
  )
#define amongULonglong(haystack) _Generic((haystack),            \
  unsigned long long:                 amongULonglongULonglong,   \
  char:                               amongULonglongChar,        \
  short:                              amongULonglongShort,       \
  int:                                amongULonglongInt,         \
  long:                               amongULonglongLong,        \
  long long:                          amongULonglongLonglong,    \
                                                                 \
  default:                            amongULonglongInt          \
  )
#define amongULonglongP(haystack) _Generic((haystack),           \
  char:                               amongULonglongPChar,       \
  short:                              amongULonglongPShort,      \
  int:                                amongULonglongPInt,        \
  long:                               amongULonglongPLong,       \
  long long:                          amongULonglongPLonglong,   \
                                                                 \
  unsigned long long*:                amongULonglongPULonglongP, \
  const volatile unsigned long long*: amongULonglongPULonglongP, \
                                                                 \
  default:                            amongULonglongPInt         \
  )
#define amongFloat(haystack) _Generic((haystack),                \
  float:                              amongFloatFloat,           \
  double:                             amongFloatDouble,          \
                                                                 \
  default:                            amongFloatDouble           \
  )
#define amongFloatP(haystack) _Generic((haystack),               \
  double:                             amongFloatPDouble,         \
  float*:                             amongFloatPFloatP,         \
  const volatile float*:              amongFloatPFloatP,         \
                                                                 \
  default:                            amongFloatPDouble          \
  )
#define amongDoubleP(haystack) _Generic((haystack),              \
  double:                             amongDoublePDouble,        \
  double*:                            amongDoublePDoubleP,       \
  const volatile double*:             amongDoublePDoubleP,       \
                                                                 \
  default:                            amongDoublePDouble         \
  )

#define AMONG_GENERIC_CASES(haystack)                            \
  signed char:                        amongIChar(haystack),      \
  signed char*:                       amongICharP(haystack),     \
  const volatile signed char*:        amongICharP(haystack),     \
                                                                 \
  char:                               amongChar(haystack),       \
  char*:                              amongCharP(haystack),      \
  const volatile char*:               amongCharP(haystack),      \
                                                                 \
  unsigned char:                      amongUChar(haystack),      \
  unsigned char*:                     amongUCharP(haystack),     \
  const volatile unsigned char*:      amongUCharP(haystack),     \
                                                                 \
  short:                              amongShort(haystack),      \
  short*:                             amongShortP(haystack),     \
  const volatile short*:              amongShortP(haystack),     \
                                                                 \
  unsigned short:                     amongUShort(haystack),     \
  unsigned short*:                    amongUShortP(haystack),    \
  const volatile unsigned short*:     amongUShortP(haystack),    \
                                                                 \
  int:                                amongInt(haystack),        \
  int*:                               amongIntP(haystack),       \
  const volatile int*:                amongIntP(haystack),       \
                                                                 \
  unsigned int:                       amongUInt(haystack),       \
  unsigned int*:                      amongUIntP(haystack),      \
  const volatile unsigned int*:       amongUIntP(haystack),      \
                                                                 \
  long:                               amongLong(haystack),       \
  long*:                              amongLongP(haystack),      \
  const volatile long*:               amongLongP(haystack),      \
                                                                 \
  unsigned long:                      amongULong(haystack),      \
  unsigned long*:                     amongULongP(haystack),     \
  const volatile unsigned long*:      amongULongP(haystack),     \
                                                                 \
  long long:                          amongLonglong(haystack),   \
  long long*:                         amongLonglongP(haystack),  \
  const volatile long long*:          amongLonglongP(haystack),  \
                                                                 \
  unsigned long long:                 amongULonglong(haystack),  \
  unsigned long long*:                amongULonglongP(haystack), \
  const volatile unsigned long long*: amongULonglongP(haystack), \
                                                                 \
  float:                              amongFloat(haystack),      \
  float*:                             amongFloatP(haystack),     \
  const volatile float*:              amongFloatP(haystack),     \
                                                                 \
  double:                             amongDoubleDouble,         \
  double*:                            amongDoubleP(haystack),    \
  const volatile double*:             amongDoubleP(haystack)     \

#define among_(needle, haystack, ...) _Generic((needle), \
  AMONG_GENERIC_CASES(haystack) \
  )(needle, haystack, ##__VA_ARGS__)

#endif // __STDC_VERSION__ >= 201710L

#elif defined __cplusplus // __STDC_VERSION__ is *NOT* defined
#define TYPE_SAFE_AMONG

// Define the C++ function overloads.

// Handle strings and Bytes specially
static inline bool among_(const volatile char *needle, const volatile char *haystack, ...) {
  va_list args;
  va_start(args, haystack);
  bool returnValue = amongVaPointer(typeString->compare, needle, haystack, args);
  va_end(args);
  return returnValue;
}
static inline bool among_(const volatile Bytes needle, const volatile Bytes haystack, ...) {
  va_list args;
  va_start(args, haystack);
  bool returnValue = amongVaPointer(typeBytes->compare, needle, haystack, args);
  va_end(args);
  return returnValue;
}

// Handling strings and Bytes specially means we also have to handle char and
// unsigned char types specially.  Specifically, we can't use AMONG_POINTER.
AMONG_INT(signed char, _, _, _, _, _, _, _, _, _, _)
AMONG_INT(char, _, _, _, _, _, _, _, _, _, _)

AMONG_SELF(unsigned char, Char, _)
AMONG_INT(unsigned char, _, _, _, _, _, _, _, _, _, _)

// Now do all the other types.  We can't use AMONG_SELF for the signed-integer
// types because that's already covered by AMONG_INT.

AMONG_INT(short, _, _, _, _, _, _, _, _, _, _)
AMONG_POINTER(short, shortCompare, _)

AMONG_SELF(unsigned short, Short, _)
AMONG_INT(unsigned short, _, _, _, _, _, _, _, _, _, _)
AMONG_POINTER(unsigned short, ushortCompare, _)

AMONG_INT(int, _, _, _, _, _, _, _, _, _, _)
AMONG_POINTER(int, intCompare, _)

AMONG_SELF(unsigned int, Int, _)
AMONG_INT(unsigned int, _, _, _, _, _, _, _, _, _, _)
AMONG_POINTER(unsigned int, uintCompare, _)

AMONG_INT(long, _, _, _, _, _, _, _, _, _, _)
AMONG_POINTER(long, longCompare, _)

AMONG_SELF(unsigned long, Long, _)
AMONG_INT(unsigned long, _, _, _, _, _, _, _, _, _, _)
AMONG_POINTER(unsigned long, ulongCompare, _)

AMONG_INT(long long, _, _, _, _, _, _, _, _, _, _)
AMONG_POINTER(long long, longlongCompare, _)

AMONG_SELF(unsigned long long, Longlong, _)
AMONG_INT(unsigned long long, _, _, _, _, _, _, _, _, _, _)
AMONG_POINTER(unsigned long long, ulonglongCompare, _)

static inline bool among_(float needle, float haystack, ...) {
  va_list args;
  va_start(args, haystack);
  bool returnValue = amongVaFloat(needle, haystack, args);
  va_end(args);
  return returnValue;
}
static inline bool among_(float needle, double haystack, ...) {
  va_list args;
  va_start(args, haystack);
  bool returnValue = amongVaDouble((double) needle, haystack, args);
  va_end(args);
  return returnValue;
}
static inline bool among_(float *needle, double haystack, ...) {
  va_list args;
  va_start(args, haystack);
  bool returnValue = amongVaDouble((double) *needle, haystack, args);
  va_end(args);
  return returnValue;
}
AMONG_POINTER(float, typeFloat->compare, _)

static inline bool among_(double needle, double haystack, ...) {
  va_list args;
  va_start(args, haystack);
  bool returnValue = amongVaDouble(needle, haystack, args);
  va_end(args);
  return returnValue;
}
static inline bool among_(double *needle, double haystack, ...) {
  va_list args;
  va_start(args, haystack);
  bool returnValue = amongVaDouble(*needle, haystack, args);
  va_end(args);
  return returnValue;
}
AMONG_POINTER(double, typeDouble->compare, _)

#endif // __cplusplus

#define among(needle, haystack, ...) among_(needle, haystack, ##__VA_ARGS__, \
  ((u64) 0), ((u64) 0), ((double) 0), ((double) 0))

#endif // TYPE_SAFE_AMONG_H

