///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              04.06.2019
///
/// @file              StringLib.h
///
/// @brief             These are the support functions that handle string
///                    manipulation and file IO.
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

#ifndef STRING_LIB_H
#define STRING_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "DataTypes.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Utility defines.
#define _STRINGIFY(x) #x
#define STRINGIFY(x) _STRINGIFY(x)
#define fputb(bytes, stream) fputs((char*) bytes, stream)
#define putb(bytes) puts((char*) bytes)
#define strjoin(str1, str2) str1 str2
#define strOrNull(str) ((str != NULL) ? ((char*) str) : "NULL")
#define strOrEmpty(str) ((str != NULL) ? ((char*) str) : "")

/// @var fieldDelim
/// Character used to delimit fields in ASCII text strings.
extern const char *fieldDelim;

/// @var recordDelim
/// Character used to delimit records in ASCII text strings.
extern const char *recordDelim;

// String and data functions.
char *indentText(const char *inputText, u32 columns);
void unescapeString(char *inputString);
void plusToSpace(char *inputString);
void dosToUnix(char *inputString);
char* straddstr(char **buffer, const char *input);
char* straddchr(char **buffer, char input);
u64 dataAddData(void **buffer, u64 bufferLength, const volatile void *input, u64 inputLength);
i64 getFileLength(const char *fullPath);
Bytes getFileContent_(const char *fullPath, i64 start, i64 length, ...);
#define getFileContent(fullPath, ...) \
  getFileContent_(fullPath, ##__VA_ARGS__, 0, 0)
i64 putFileContent_(
  const char *fullPath, const volatile void *dataBuffer, i64 dataLength, i64 start, ...);
#define putFileContent(fullPath, dataBuffer, dataLength, ...) \
  putFileContent_(fullPath, dataBuffer, dataLength, ##__VA_ARGS__, 0)
u64 getFileLine(FILE *requestedFile, char **dataBuffer);
char unampersand(const char *inputString);
char hexToChar(const char *inputString);
char *strReplaceOneStr(
  const char *inputString, const char *findWhat, const char *replaceText,
  bool *replacementMade);
char *strReplaceStr(const char *inputString, const char *findWhat,
  const char *replaceText);
char *escapeString(const char *inputString);
const char *strrstr(const char *haystack, const char *needle);
Bytes **stringToBytesTable_(const char *inputString,
  const char *recordDelimiter, const char *fieldDelimiter, ...);
// stringToBytesTable macro makes recordDelimiter and fieldDelimieter parameters
// optional.  Note, however, that if one is specified, the other must also
// be specified.  (You cannot only specify one of the optional parameters.)
#define stringToBytesTable(inputString, ...) \
  stringToBytesTable_(inputString, ##__VA_ARGS__, recordDelim, fieldDelim)
Bytes *stringToBytesArray_(const char *inputString, ...);
// stringToBytesArray macro makes fieldDelimieter parameter optional.
#define stringToBytesArray(inputString, ...) \
  stringToBytesArray_(inputString, ##__VA_ARGS__, NULL)
Bytes* freeBytesArray(Bytes *array);
Bytes** freeBytesTable(Bytes **table);
char *bytesTableToString_(
  const Bytes **table, const char *recordDelimiter, const char *fieldDelimiter, ...);
// bytesTableToString macro makes recordDelimiter and fieldDelimieter parameters
// optional.  Note, however, that if one is specified, the other must also
// be specified.  (You cannot only specify one of the optional parameters.)
#define bytesTableToString(table, ...) \
  bytesTableToString_(table, ##__VA_ARGS__, recordDelim, fieldDelim)
char *bytesArrayToString_(const Bytes *array, const char *fieldDelimiter, ...);
// bytesArrayToString macro makes fieldDelimiter parameter optional.
#define bytesArrayToString(array, ...) \
  bytesArrayToString_(array, ##__VA_ARGS__, fieldDelim)
// Make sure we're using our version of asprintf, not the system version.
#ifdef vasprintf
#undef vasprintf
#endif // vasprintf
int vasprintf(char **buffer, const char *formatString, va_list args);
#ifdef asprintf
#undef asprintf
#endif // asprintf
#if defined _MSC_VER
int asprintf(char **buffer, _Printf_format_string_ const char *printString, ...);
#elif defined __MINGW32__
int asprintf(char **buffer, const char *printString, ...)
  __attribute__((format(__MINGW_PRINTF_FORMAT, 2, 3)));
#else // Assume GCC
int asprintf(char **buffer, const char *printString, ...)
  __attribute__((format(printf, 2, 3)));
#endif
char *unformatString(char *inputString);
i32 reverseString(char *inputString);
int arrayFindValueIndex(const char **array, const char *value);
int arrayRemoveValue(char **array, const char *value);
void stringToLowerCase(char *string);
char *strstrci(const char *haystack, const char *needle);
int strncmpci(const char *s1, const char *s2, size_t len);
// strcmpci is just strncmpci with the maximum possible value for len
#define strcmpci(s1, s2) strncmpci(s1, s2, ((size_t) -1))
#define getBytesBetween(haystack, start, end) ( \
  ((haystack != NULL) && (start != NULL) && (end != NULL)) \
  ? getDataBetween(haystack, strlen(haystack), \
      start, strlen(start), end, strlen(end)) \
  : NULL \
)
#define getBytesBetweenBytes(haystack, start, end) ( \
  ((haystack != NULL) && (start != NULL) && (end != NULL)) \
  ? getDataBetween(haystack, bytesLength(haystack), \
      start, strlen(start), end, strlen(end)) \
  : NULL \
)
Bytes getBytesBetweenCi(
  const char *haystack, const char *start, const char *end);
char *escapeData(const volatile void *data, u64 length);
Bytes escapeDataToBytes(const volatile void *data, u64 length);
void unescapeBytes(Bytes input);
u64 straddbytes(char **buffer, const Bytes input);
int bytesNCompare(const Bytes valueA, const Bytes valueB, u64 len);
#define bytesCompare(valueA, valueB) bytesNCompare(valueA, valueB, ((u64) -1))
Bytes bytesTableToCsv(const Bytes **table);
int charToHex(char c, bool upperCase, char output[3]);
Bytes bytesReplaceStr(
  const Bytes input, const char *findWhat, const char *replaceText
);
void *dataFindData(const volatile void *vHaystack, u64 haystackLength,
  const volatile void *vNeedle, u64 needleLength
);
Bytes getDataBetween(const volatile void *vHaystack, u64 haystackLength,
  const volatile void *start, u64 startLength,
  const volatile void *end, u64 endLength
);
#define stringDestroy(string) ((char*) (free((void*) string), NULL))
int vabprintf(Bytes *buffer, const char *formatString, va_list args);
#if defined _MSC_VER
int abprintf(Bytes *buffer, _Printf_format_string_ const char *printString, ...);
#elif defined __MINGW32__
int abprintf(Bytes *buffer, const char *printString, ...)
  __attribute__((format(__MINGW_PRINTF_FORMAT, 2, 3)));
#else // Assume GCC
int abprintf(Bytes *buffer, const char *printString, ...)
  __attribute__((format(printf, 2, 3)));
#endif
bool isInteger(const char *string);
bool isNumber(const char *string);
const char *getProgramName(const char *argv0);
bool stringStartsWith(const char *haystack, const char *beginning);
bool stringStartsWithCi(const char *haystack, const char *beginning);
bool dataIsString(const volatile void *data, u64 dataLength);
bool dataIsAscii(const volatile void *data, u64 dataLength);
bool nonPrintableToWhitespace(const volatile void *data, u64 dataLength);
#define firstFourEq(strA, strB) \
  ( \
    ((strA == NULL) || (strB == NULL)) \
      ? (((intptr_t) strA) == ((intptr_t) strB)) \
      : ((*((char*) strA) == '\0') || (*((char*) strB) == '\0'))\
        ? (*((char*) strA) == *((char*) strB)) \
        : (*((u32*) strA) == *((u32*) strB)) \
  )
bool dataEndsWith(const volatile void *haystack, u64 haystackLength,
  const volatile void *needle, u64 needleLength);
#define strEndsWithStr(str1, str2) \
  dataEndsWith(str1, strlen(str(str1)), str2, strlen(str(str2)))
#define strEndsWithBytes(str1, bytes2) \
  dataEndsWith(str1, strlen(str(str1)), bytes2, bytesLength(bytes2))
#define bytesEndsWithStr(bytes1, str2) \
  dataEndsWith(bytes1, bytesLength(bytes1), str2, strlen(str(str2)))
#define bytesEndsWithBytes(bytes1, bytes2) \
  dataEndsWith(bytes1, bytesLength(bytes1), bytes2, bytesLength(bytes2))

/// @fn static inline char* getToken(char *start, char **end, const char *delimiters)
///
/// @brief Get the next token a string given an alphabet of delimiters.
///
/// @param start The beginning of the string to search.  Characters in the
///   delimiter alphabet at the beginning of the string will be skipped.
/// @param end A pointer to be populated with the first character past the end
///   of the token.  i.e. The first character in the delimiter alphabet after
///   the return value.
/// @param delimiters A string containing the delimiter alphabet.
///
/// @return Returns a pointer to the next token after start if there is one,
/// NULL otherwise.  If the end pointer is not null, it will be set to the first
/// character not in the delimiter alphabet if the return value is not NULL and
/// will be set to NULL if the return value is NULL.
static inline char* getToken(char *start, char **end,
  const char *delimiters
) {
  char *returnValue = NULL;
  if (start == NULL) {
    return returnValue; // NULL
  }
  
  // First, get the next token after start.
  returnValue = &start[strspn(start, delimiters)];
  if (*returnValue == '\0') {
    // We're at the end of the string and there is no next token.  Return NULL.
    returnValue = NULL;
  }
  
  if (end != NULL) {
    if (returnValue != NULL) {
      // Find the next instance of a delimiter.
      *end = &returnValue[strcspn(returnValue, delimiters)];
    } else {
      // Set end to NULL too.
      *end = NULL;
    }
  }
  
  return returnValue;
}

// Bytes functions
Bytes bytesAllocate(Bytes *buffer, u64 size);
Bytes bytesAddData(Bytes *buffer, const volatile void *input, u64 inputLength);
Bytes bytesAddBytes(Bytes *buffer, const Bytes input);
Bytes bytesAddStr(Bytes *buffer, const char *input);
Bytes bytesAddChr(Bytes *buffer, char input);
Bytes bytesReplace(Bytes *buffer, const volatile void *input, u64 inputLength);
Bytes bytesDestroy(Bytes value);
// These next four functions are delcared inline because they were originally
// macros, but those were not type safe because of the casts involved.
static inline u64 bytesLength(const Bytes value) {
  return ((value) ? ((BytesHeader*) value)[-1].length : (u64) 0);
}
static inline u64 bytesSize(const Bytes value) {
  return ((value) ? ((BytesHeader*) value)[-1].size : (u64) 0);
}
static inline void bytesSetLength(Bytes value, u64 valueLength) {
  if (value != NULL) {
    ((BytesHeader*) value)[-1].length = valueLength;
  }
}
static inline void bytesSetSize(Bytes value, u64 valueSize) {
  if (value != NULL) {
    ((BytesHeader*) value)[-1].size = valueSize;
  }
}
char *escapeBytes(const Bytes input);
bool bytesArrayAddField(Bytes **array, u64 beforeIndex);
bool bytesTableAddField(Bytes ***table, u64 beforeIndex);
Bytes dataToHexBytes(const volatile void *data, u64 length);
Bytes hexStringToBytes(const char *hexString, u64 length);
Bytes dataToBase64(const volatile void *data, u64 dataLength);
Bytes base64ToBytes(const char *base64String, u64 base64StringLength);


#ifdef __cplusplus
} // extern "C"
#endif

#endif // STRING_LIB_H

