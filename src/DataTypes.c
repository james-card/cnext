////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                     Copyright (c) 2012-2024 James Card                     //
//                                                                            //
// Permission is hereby granted, free of charge, to any person obtaining a    //
// copy of this software and associated documentation files (the "Software"), //
// to deal in the Software without restriction, including without limitation  //
// the rights to use, copy, modify, merge, publish, distribute, sublicense,   //
// and/or sell copies of the Software, and to permit persons to whom the      //
// Software is furnished to do so, subject to the following conditions:       //
//                                                                            //
// The above copyright notice and this permission notice shall be included    //
// in all copies or substantial portions of the Software.                     //
//                                                                            //
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR //
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   //
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    //
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER //
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    //
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER        //
// DEALINGS IN THE SOFTWARE.                                                  //
//                                                                            //
//                                 James Card                                 //
//                          http://www.jamescard.org                          //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

// Doxygen marker
/// @file

#include "DataTypes.h"
#include "StringLib.h"
#ifdef DS_LOGGING_ENABLED
#include "LoggingLib.h"
#else
#undef printLog
#define printLog(...) {}
#define LOG_MALLOC_FAILURE() {}
#define logFile stderr
#endif

const bool       boolZero       = 0;
const i8         i8Zero         = 0;
const u8         u8Zero         = 0;
const i16        i16Zero        = 0;
const u16        u16Zero        = 0;
const i32        i32Zero        = 0;
const u32        u32Zero        = 0;
const i64        i64Zero        = 0;
const u64        u64Zero        = 0;
const i128       i128Zero       = 0;
const u128       u128Zero       = 0;
const float      floatZero      = 0;
const double     doubleZero     = 0;
const longDouble longDoubleZero = 0;

/// @var DsMarker
///
/// @brief 16-bit marker used in data structure to/from bytearray functions to
/// validate that the data stream originated from this library.
u16 DsMarker = 0x4ABC;

/// @var DsVersion
///
/// @brief Version information for data structures in to/from bytearray
/// functions to determine how to parse them.
u32 DsVersion = 10;

/// @var boolNames
///
/// @brief The string name equivalents of bool values.
const char *boolNames[2] = {
  "false",
  "true"
};

/// @var littleEndianUnion
///
/// @brief Constant variable that concretely identifies whether or not the
/// system is little endian.  This is the instance of the variable decalred in 
/// DataTypes.h.
EndianUnion const littleEndianUnion = {.integer = 1};

/// @fn int byteSwapIfNotLittleEndian(volatile void *value, size_t size)
///
/// @brief Convert the host byte format to little endian format.  Almost a
/// no-op if the host format is already little endian.
///
/// @return Returns 0 on success, -1 on failure (if value is NULL).
int byteSwapIfNotLittleEndian(volatile void *value, size_t size) {
  printLog(TRACE, "ENTER byteSwapIfNotLittleEndian(value=%p, size=%llu)\n",
    value, llu(size));
  if (value == NULL) {
    printLog(ERR, "value is NULL.  Cannot convert to little endian.\n");
    printLog(TRACE, "EXIT byteSwapIfNotLittleEndian(value=%p, size=%llu) = {-1}\n",
      value, llu(size));
    return -1;
  }
  
  if (HOST_IS_LITTLE_ENDIAN) {
    printLog(TRACE, "EXIT byteSwapIfNotLittleEndian(value=%p, size=%llu) = {0}\n",
      value, llu(size));
    return 0;
  }
  
  // Swap the bytes.
  reverseMemory(value, size);
  
  printLog(TRACE, "EXIT byteSwapIfNotLittleEndian(value=%p, size=%llu) = {0}\n",
    value, llu(size));
  return 0;
}

/// @fn int byteSwapIfNotBigEndian(volatile void *value, size_t size)
///
/// @brief Convert the host byte format to big endian format.  Almost a
/// no-op if the host format is already big endian.
///
/// @return Returns 0 on success, -1 on failure (if value is NULL).
int byteSwapIfNotBigEndian(volatile void *value, size_t size) {
  printLog(TRACE, "ENTER byteSwapIfNotBigEndian(value=%p, size=%llu)\n",
    value, llu(size));
  if (value == NULL) {
    printLog(ERR, "value is NULL.  Cannot convert to little endian.\n");
    printLog(TRACE, "EXIT byteSwapIfNotBigEndian(value=%p, size=%llu) = {-1}\n",
      value, llu(size));
    return -1;
  }
  
  if (HOST_IS_LITTLE_ENDIAN) {
    // Swap the bytes.
    reverseMemory(value, size);
  }
  
  printLog(TRACE, "EXIT byteSwapIfNotBigEndian(value=%p, size=%llu) = {0}\n",
    value, llu(size));
  return 0;
}

// Clear functions.  These functions are shared between types, so it doesn't
// make sense to colocate them with an individual type.

/// @fn i32 clearNull(volatile void *value)
///
/// @brief Do nothing.
///
/// @return This function always returns 0.
i32 clearNull(volatile void *value) {
  (void) value;
  printLog(TRACE, "ENTER clearNull(value=%p)\n", value);
  
  printLog(TRACE, "EXIT clearNull(value=%p) = {0}\n", value);
  return 0;
}

/// @fn i32 clearBool(volatile void *value)
///
/// @brief Clear but do not deallocate a bool value.
///
/// @return Returns 0 on success, -1 on failure.
i32 clearBool(volatile void *value) {
  printLog(TRACE, "ENTER clearBool(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(ERR, "NULL value provided.\n");
    printLog(TRACE, "EXIT clearBool(value=NULL) = {0}\n");
    return -1;
  }
  
  bool *boolValue = (bool*) value;
  *boolValue = false;
  
  printLog(TRACE, "EXIT clearBool(value=%p) = {0}\n", value);
  return 0;
}

/// @fn i32 clear8(volatile void *value)
///
/// @brief Clear but do not deallocate an 8-bit value.
///
/// @return Returns 0 on success, -1 on failure.
i32 clear8(volatile void *value) {
  printLog(TRACE, "ENTER clear8(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(ERR, "NULL value provided.\n");
    printLog(TRACE, "EXIT clear8(value=NULL) = {0}\n");
    return -1;
  }
  
  u8 *u8Value = (u8*) value;
  *u8Value = 0;
  
  printLog(TRACE, "EXIT clear8(value=%p) = {0}\n", value);
  return 0;
}

/// @fn i32 clear16(volatile void *value)
///
/// @brief Clear but do not deallocate a 16-bit value.
///
/// @return Returns 0 on success, -1 on failure.
i32 clear16(volatile void *value) {
  printLog(TRACE, "ENTER clear16(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(ERR, "NULL value provided.\n");
    printLog(TRACE, "EXIT clear16(value=NULL) = {0}\n");
    return -1;
  }
  
  u16 *u16Value = (u16*) value;
  *u16Value = 0;
  
  printLog(TRACE, "EXIT clear16(value=%p) = {0}\n", value);
  return 0;
}

/// @fn i32 clear32(volatile void *value)
///
/// @brief Clear but do not deallocate a 32-bit value.
///
/// @return Returns 0 on success, -1 on failure.
i32 clear32(volatile void *value) {
  printLog(TRACE, "ENTER clear32(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(ERR, "NULL value provided.\n");
    printLog(TRACE, "EXIT clear32(value=NULL) = {0}\n");
    return -1;
  }
  
  u32 *u32Value = (u32*) value;
  *u32Value = 0;
  
  printLog(TRACE, "EXIT clear32(value=%p) = {0}\n", value);
  return 0;
}

/// @fn i32 clear64(volatile void *value)
///
/// @brief Clear but do not deallocate a 64-bit value.
///
/// @return Returns 0 on success, -1 on failure.
i32 clear64(volatile void *value) {
  printLog(TRACE, "ENTER clear64(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(ERR, "NULL value provided.\n");
    printLog(TRACE, "EXIT clear64(value=NULL) = {0}\n");
    return -1;
  }
  
  u64 *u64Value = (u64*) value;
  *u64Value = 0;
  
  printLog(TRACE, "EXIT clear64(value=%p) = {0}\n", value);
  return 0;
}

/// @fn i32 clear128(volatile void *value)
///
/// @brief Clear but do not deallocate a 128-bit value.
///
/// @return Returns 0 on success, -1 on failure.
i32 clear128(volatile void *value) {
  printLog(TRACE, "ENTER clear128(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(ERR, "NULL value provided.\n");
    printLog(TRACE, "EXIT clear128(value=NULL) = {0}\n");
    return -1;
  }
  
  u128 *u128Value = (u128*) value;
  *u128Value = 0;
  
  printLog(TRACE, "EXIT clear128(value=%p) = {0}\n", value);
  return 0;
}

/// @fn i32 clearFloat(volatile void *value)
///
/// @brief Clear but do not deallocate a float value.
///
/// @return Returns 0 on success, -1 on failure.
i32 clearFloat(volatile void *value) {
  printLog(TRACE, "ENTER clearFloat(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(ERR, "NULL value provided.\n");
    printLog(TRACE, "EXIT clearFloat(value=NULL) = {0}\n");
    return -1;
  }
  
  float *floatValue = (float*) value;
  *floatValue = 0.0;
  
  printLog(TRACE, "EXIT clearFloat(value=%p) = {0}\n", value);
  return 0;
}

/// @fn i32 clearDouble(volatile void *value)
///
/// @brief Clear but do not deallocate a double value.
///
/// @return Returns 0 on success, -1 on failure.
i32 clearDouble(volatile void *value) {
  printLog(TRACE, "ENTER clearDouble(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(ERR, "NULL value provided.\n");
    printLog(TRACE, "EXIT clearDouble(value=NULL) = {0}\n");
    return -1;
  }
  
  double *doubleValue = (double*) value;
  *doubleValue = 0.0;
  
  printLog(TRACE, "EXIT clearDouble(value=%p) = {0}\n", value);
  return 0;
}

/// @fn i32 clearLongDouble(volatile void *value)
///
/// @brief Clear but do not deallocate a long double value.
///
/// @return Returns 0 on success, -1 on failure.
i32 clearLongDouble(volatile void *value) {
  printLog(TRACE, "ENTER clearLongDouble(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(ERR, "NULL value provided.\n");
    printLog(TRACE, "EXIT clearLongDouble(value=NULL) = {0}\n");
    return -1;
  }
  
  long double *longDoubleValue = (long double*) value;
  *longDoubleValue = 0.0;
  
  printLog(TRACE, "EXIT clearLongDouble(value=%p) = {0}\n", value);
  return 0;
}

/// @fn i32 clearString(volatile void *value)
///
/// @brief Clear but do not deallocate a string value.
///
/// @return Returns 0 on success, -1 on failure.
i32 clearString(volatile void *value) {
  printLog(TRACE, "ENTER clearString(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(ERR, "NULL value provided.\n");
    printLog(TRACE, "EXIT clearString(value=NULL) = {0}\n");
    return -1;
  }
  
  char *stringValue = (char*) value;
  *stringValue = '\0';
  
  printLog(TRACE, "EXIT clearString(value=%p) = {0}\n", value);
  return 0;
}

/// @fn i32 clearBytes(volatile void *value)
///
/// @brief Clear but do not deallocate a Bytes value.
///
/// @return Returns 0 on success, -1 on failure.
i32 clearBytes(volatile void *value) {
  printLog(TRACE, "ENTER clearBytes(value=%p)\n", value);
  
  if (value == NULL) {
    // This is not an error.  NULL is a valid value for bytes.  Just return.
    printLog(TRACE, "EXIT clearBytes(value=NULL) = {0}\n");
    return -1;
  }
  
  Bytes bytesValue = (Bytes) value;
  bytesSetLength(bytesValue, 0);
  if (bytesSize(bytesValue) > 0) {
    *ustr(bytesValue) = '\0';
  }
  
  printLog(TRACE, "EXIT clearBytes(value=%p) = {0}\n", value);
  return 0;
}

/// @fn char *boolToString(const volatile void *value)
///
/// @brief Convert a bool value to its string representation.
///
/// @param value A pointer to the bool value to convert to a string.
///
/// @return Returns a string representation of the value on success,
///   NULL on failure.
char *boolToString(const volatile void *value) {
  printLog(TRACE, "ENTER boolToString(value=%u)\n", (value == NULL) ? 0 : *((bool*) value));
  
  char *boolString = NULL;
  if (value == NULL) {
    straddstr(&boolString, "(null)");
    
    printLog(TRACE, "EXIT boolToString(value=%u) = {%s}\n", (value == NULL) ? 0 : *((bool*) value), boolString);
    return boolString;
  }
  
  bool boolValue = *((bool*) value);
  if (boolValue == false) {
    straddstr(&boolString, "false");
  } else {
    // Any non-zero value is interpreted as true.
    straddstr(&boolString, "true");
  }
  
  printLog(TRACE, "EXIT boolToString(value=%u) = {%s}\n", (value == NULL) ? 0 : *((bool*) value), boolString);
  return boolString;
}

/// @fn Bytes boolToBytes(const volatile void *value)
///
/// @brief Convert a bool value to its Bytes representation.
///
/// @param value A pointer to the bool value to convert to a string.
///
/// @return Returns a Bytes representation of the value on success,
///   NULL on failure.
Bytes boolToBytes(const volatile void *value) {
  printLog(TRACE, "ENTER boolToBytes(value=%u)\n",
    (value == NULL) ? 0 : *((bool*) value));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT boolToBytes(value=%u) = {NULL}\n",
      (value == NULL) ? 0 : *((bool*) value));
    return NULL;
  }
  
  Bytes boolBytes = NULL;
  bool boolValue = *((bool*) value);
  if (boolValue == false) {
    bytesAddStr(&boolBytes, "false");
  } else {
    // Any non-zero value is interpreted as true.
    bytesAddStr(&boolBytes, "true");
  }
  
  printLog(TRACE, "EXIT boolToBytes(value=%u) = {%s}\n",
    (value == NULL) ? 0 : *((bool*) value), (char*) boolBytes);
  return boolBytes;
}

/// @fn int boolCompare(const volatile void *valueA, const volatile void *valueB)
///
/// @brief Compare two bool values.
///
/// @param valueA, valueB are pointers to the values to compare.
///
/// @return Returns -1 if *valueA < *valueB, 0 if *valueA == *valueB,
///   1 if *valueA > *valueB.
int boolCompare(const volatile void *valueA, const volatile void *valueB) {
  printLog(TRACE, "ENTER boolCompare(valueA=%u, valueB=%u)\n", (valueA == NULL) ? 0 : *((bool*) valueA), (valueB == NULL) ? 0 : *((bool*) valueB));
  
  int returnValue = 0;
  
  if (valueA == NULL) {
    printLog(WARN, "valueA is NULL.\n");
    returnValue--;
  }
  if (valueB == NULL) {
    printLog(WARN, "valueB is NULL.\n");
    returnValue++;
  }
  if ((valueA == NULL) || (valueB == NULL)) {
    printLog(TRACE, "EXIT boolCompare(valueA=%p, valueB=%p) = {%d}\n", valueA,
      valueB, returnValue);
    return returnValue;
  }
  
  bool boolValueA = *((bool*) valueA);
  bool boolValueB = *((bool*) valueB);
  
  if (boolValueA < boolValueB) {
    returnValue = -1;
  } else if (boolValueA > boolValueB) {
    returnValue = 1;
  } else { // boolValueA == boolValueB
    returnValue = 0;
  }
  
  printLog(TRACE, "EXIT boolCompare(valueA=%u, valueB=%u) = {%d}\n",
    boolValueA, boolValueB, returnValue);
  return returnValue;
}

/// @fn void *boolCreate(const volatile void *parameter1, ...)
///
/// @brief Allocate memory for a new bool value and initialize it to 0.
///
/// @param parameter1 Dummy parameter for the sake of conformance to
///   TypeDescriptor definition.  Unused by this function.
///
/// @return Returns a pointer to the newly-initialized value.
void *boolCreate(const volatile void *parameter1, ...) {
  printLog(TRACE, "ENTER boolCreate()\n");
  
  (void) parameter1; // Keep the compiler from complaining.
  
  bool *value = (bool*) malloc(sizeof(bool));
  *value = false;
  
  printLog(TRACE, "EXIT boolCreate() = {%u}\n", *((bool*) value));
  return (void*) value;
}

/// @fn void *boolCopy(const volatile void *value)
///
/// @brief Create a new bool value and assign it the value of the input value.
///
/// @param value Pointer to the value to copy.
///
/// @return A pointer to a new bool with the specified value.
void *boolCopy(const volatile void *value) {
  printLog(TRACE, "ENTER boolCopy(value=%u)\n", (value == NULL) ? 0 : *((bool*) value));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT boolCopy(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  bool *valueCopy = (bool*) malloc(sizeof(bool));
  if (valueCopy != NULL) {
    *valueCopy = *((bool*) value);
  }
  
  printLog(TRACE, "EXIT boolCopy(value=%u) = {%p}\n", *((bool*) value), valueCopy);
  return valueCopy;
}

/// @fn void *boolDestroy(volatile void *value)
///
/// @brief Release the memory associated with a bool value.
///
/// @param value A pointer to the memory to be released.
///
/// @return Returns a null pointer on success, the input pointer on failure.
///   NOTE: Use of the pointer returned by this function will result in
///   undefined behavior.
void *boolDestroy(volatile void *value) {
  printLog(TRACE, "ENTER boolDestroy(value=%u)\n", (value == NULL) ? 0 : *((bool*) value));
  
  value = pointerDestroy(value);
  
  printLog(TRACE, "EXIT boolDestroy(value=%p) = {%p}\n", value, value);
  return (void*) value;
}

/// @fn size_t boolSize(const volatile void *value)
///
/// @brief Return the size of a bool type.
///
/// @param value A pointer to a bool variable.
///
/// @return Return the size of a bool type.
size_t boolSize(const volatile void *value) {
  size_t size = 0;
  printLog(TRACE, "ENTER boolSize(value=%p)\n", value);
  
  if (value != NULL) {
    size = sizeof(bool);
  }
  
  printLog(TRACE, "EXIT boolSize(value=%p) = {%llu}\n", value, llu(size));
  return size;
}

/// @fn Bytes boolToBlob(const volatile void *value)
///
/// @brief Convert a bool value to an array of bytes.
///
/// @param value A pointer to the bool value to convert.
///
/// @return Returns a Bytes object with the encoded byte array on success,
/// NULL on failure.
Bytes boolToBlob(const volatile void *value) {
  Bytes returnValue = NULL;
  printLog(TRACE,
    "ENTER boolToBlob(value=%u)\n",
    (value == NULL) ? 0 : *((bool*) value));
  
  if (value == NULL) {
    printLog(ERR, "Cannot convert to byte array.  Parameter is NULL.\n");
    printLog(TRACE,
      "EXIT boolToBlob(value=%u) = {%p}\n",
      (value == NULL) ? 0 : *((bool*) value), returnValue);
    return returnValue;
  }
  
  bytesAddData(&returnValue, value, sizeof(bool));
  // Set the size to match the length.  This is so data structures that are
  // building byte arrays encode the right amount of data, which does not
  // include the string terminator in our case.
  bytesSetSize(returnValue, bytesLength(returnValue));
  
  printLog(TRACE,
    "EXIT boolToBlob(value=%u) = {%p}\n",
    (value == NULL) ? 0 : *((bool*) value), returnValue);
  return returnValue;
}

/// @fn void* boolFromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety)
///
/// @brief Convert a bool value to an array of bytes.
///
/// @param value A pointer to the bool value to convert.
/// @param length The length of the resulting byte array.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned data.  Not used by this function.
///
/// @return Returns a pointer to a valid byte array on success, NULL on failure.
void* boolFromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety) {
  (void) disableThreadSafety;
  void *returnValue = NULL;
  printLog(TRACE,
    "ENTER boolFromBlob(value=%u, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    (value == NULL) ? 0 : *((bool*) value), length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  
  if ((value == NULL) || (length == NULL)) {
    printLog(ERR, "Cannot convert to/from byte array.  Parameter is NULL.\n");
    printLog(TRACE,
      "EXIT boolFromBlob(value=%u, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      (value == NULL) ? 0 : *((bool*) value), length, boolNames[inPlaceData], boolNames[disableThreadSafety],
      returnValue);
    return returnValue; // NULL
  } else if (*length < sizeof(bool)) {
    printLog(ERR, "Cannot convert from byte array.  Insufficient data.\n");
    printLog(ERR, "Needed at least %llu bytes, only have %llu.\n",
      llu(sizeof(bool)), llu(*length));
    printLog(TRACE,
      "EXIT boolFromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return returnValue; // NULL
  }
  
  if (inPlaceData) {
    // Optimize for this case.
    returnValue = (void*) value;
  } else {
    returnValue = boolCopy(value);
  }
  if (returnValue != NULL) {
    *length = sizeof(bool);
  } else {
    *length = 0;
  }
  
  printLog(TRACE,
    "EXIT boolFromBlob(value=%u, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    (value == NULL) ? 0 : *((bool*) value), llu(*length),
    boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
  return returnValue;
}

/// @var typeBool
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the bool type.
TypeDescriptor _typeBool = {
  .name          = "bool",
  .xmlName       = "xs:boolean",
  .dataIsPointer = false,
  .toString      = boolToString,
  .toBytes       = boolToBytes,
  .compare       = boolCompare,
  .create        = boolCreate,
  .copy          = boolCopy,
  .destroy       = boolDestroy,
  .size          = boolSize,
  .toBlob        = boolToBlob,
  .fromBlob      = boolFromBlob,
  .hashFunction  = NULL,
  .clear         = clearBool,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeBool = &_typeBool;

/// @var typeBoolNoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the bool type that is not to be copied.
TypeDescriptor _typeBoolNoCopy = {
  .name          = "bool",
  .xmlName       = "xs:boolean",
  .dataIsPointer = true,
  .toString      = boolToString,
  .toBytes       = boolToBytes,
  .compare       = boolCompare,
  .create        = boolCreate,
  .copy          = shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = boolSize,
  .toBlob        = boolToBlob,
  .fromBlob      = boolFromBlob,
  .hashFunction  = NULL,
  .clear         = clearBool,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeBoolNoCopy = &_typeBoolNoCopy;

/// @fn char *u8ToString(const volatile void *value)
///
/// @brief Convert a u8 value to its string representation.
///
/// @param value A pointer to the u8 value to converted to a string.
///
/// @return Returns a string representation of the value on success,
///   NULL on failure.
char *u8ToString(const volatile void *value) {
  printLog(TRACE, "ENTER u8ToString(value=%u)\n", (value == NULL) ? 0 : *((u8*) value));
  
  char *u8String = NULL;
  if (value == NULL) {
    straddstr(&u8String, "(null)");
    
    printLog(TRACE, "EXIT u8ToString(value=%u) = {%s}\n", (value == NULL) ? 0 : *((u8*) value), u8String);
    return u8String;
  }
  
  u8 u8Value = *((u8*) value);
  char digit = '\0';
  
  while (u8Value != 0) {
    digit = '0' + (u8Value % 10);
    straddchr(&u8String, digit);
    u8Value /= 10;
  }
  
  if (u8String == NULL) {
    straddchr(&u8String, '0');
  }
  
  reverseString(u8String);
  
  printLog(TRACE, "EXIT u8ToString(value=%u) = {%s}\n", (value == NULL) ? 0 : *((u8*) value), u8String);
  return u8String;
}

/// @fn Bytes u8ToBytes(const volatile void *value)
///
/// @brief Convert a u8 value to its Bytes representation.
///
/// @param value A pointer to the u8 value to converted to a Bytes object.
///
/// @return Returns a Bytes representation of the value on success,
///   NULL on failure.
Bytes u8ToBytes(const volatile void *value) {
  printLog(TRACE, "ENTER u8ToBytes(value=%u)\n", (value == NULL) ? 0 : *((u8*) value));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT u8ToBytes(value=%u) = {NULL}\n",
      (value == NULL) ? 0 : *((u8*) value));
    return NULL;
  }
  
  Bytes u8Bytes = NULL;
  u8 u8Value = *((u8*) value);
  char digit = '\0';
  
  while (u8Value != 0) {
    digit = '0' + (u8Value % 10);
    bytesAddData(&u8Bytes, &digit, sizeof(digit));
    u8Value /= 10;
  }
  
  if (u8Bytes == NULL) {
    digit = '0';
    bytesAddData(&u8Bytes, &digit, sizeof(digit));
  }
  
  reverseMemory(u8Bytes, bytesLength(u8Bytes));
  
  printLog(TRACE, "EXIT u8ToBytes(value=%u) = {%s}\n",
    (value == NULL) ? 0 : *((u8*) value), (char*) u8Bytes);
  return u8Bytes;
}

/// @fn int u8Compare(const volatile void *valueA, const volatile void *valueB)
///
/// @brief Compare two u8 values.
///
/// @param valueA, valueB are pointers to the values to compare.
///
/// @return Returns -1 if *valueA < *valueB, 0 if *valueA == *valueB,
///   1 if *valueA > *valueB.
int u8Compare(const volatile void *valueA, const volatile void *valueB) {
  printLog(TRACE, "ENTER u8Compare(valueA=%u, valueB=%u)\n", (valueA == NULL) ? 0 : *((u8*) valueA), (valueB == NULL) ? 0 : *((u8*) valueB));
  
  int returnValue = 0;
  
  if (valueA == NULL) {
    printLog(WARN, "valueA is NULL.\n");
    returnValue--;
  }
  if (valueB == NULL) {
    printLog(WARN, "valueB is NULL.\n");
    returnValue++;
  }
  if ((valueA == NULL) || (valueB == NULL)) {
    printLog(TRACE, "EXIT u8Compare(valueA=%p, valueB=%p) = {%d}\n", valueA,
      valueB, returnValue);
    return returnValue;
  }
  
  u8 u8ValueA = *((u8*) valueA);
  u8 u8ValueB = *((u8*) valueB);
  
  if (u8ValueA < u8ValueB) {
    returnValue = -1;
  } else if (u8ValueA > u8ValueB) {
    returnValue = 1;
  } else { // u8ValueA == u8ValueB
    returnValue = 0;
  }
  
  printLog(TRACE, "EXIT u8Compare(valueA=%u, valueB=%u) = {%d}\n",
    u8ValueA, u8ValueB, returnValue);
  return returnValue;
}

/// @fn void *u8Create(const volatile void *parameter1, ...)
///
/// @brief Allocate memory for a new u8 value and initialize it to 0.
///
/// @param parameter1 Dummy parameter for the sake of conformance to
///   TypeDescriptor definition.  Unused by this function.
///
/// @return Returns a pointer to the newly-initialized value.
void *u8Create(const volatile void *parameter1, ...) {
  printLog(TRACE, "ENTER u8Create()\n");
  
  (void) parameter1; // Keep the compiler from complaining.
  
  u8 *value = (u8*) malloc(sizeof(u8));
  *value = 0;
  
  printLog(TRACE, "EXIT u8Create() = {%u}\n", *((u8*) value));
  return (void*) value;
}

/// @fn void *u8Copy(const volatile void *value)
///
/// @brief Create a new u8 value and assign it the value of the input value.
///
/// @param value Pointer to the value to copy.
///
/// @return A pointer to a new u8 with the specified value.
void *u8Copy(const volatile void *value) {
  printLog(TRACE, "ENTER u8Copy(value=%u)\n", (value == NULL) ? 0 : *((u8*) value));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT u8Copy(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  u8 *valueCopy = (u8*) malloc(sizeof(u8));
  if (valueCopy != NULL) {
    *valueCopy = *((u8*) value);
  }
  
  printLog(TRACE, "EXIT u8Copy(value=%u) = {%p}\n", *((u8*) value), valueCopy);
  return valueCopy;
}

/// @fn void *u8Destroy(volatile void *value)
///
/// @brief Release the memory associated with a u8 value.
///
/// @param value A pointer to the memory to be released.
///
/// @return Returns a null pointer on success, the input pointer on failure.
///   NOTE: Use of the pointer returned by this function will result in
///   undefined behavior.
void *u8Destroy(volatile void *value) {
  printLog(TRACE, "ENTER u8Destroy(value=%u)\n", (value == NULL) ? 0 : *((u8*) value));
  
  value = pointerDestroy(value);
  
  printLog(TRACE, "EXIT u8Destroy(value=%p) = {%p}\n", value, value);
  return (void*) value;
}

/// @fn size_t u8Size(const volatile void *value)
///
/// @brief Return the size of a u8 type.
///
/// @param value A pointer to a u8 variable.
///
/// @return Return the size of a u8 type.
size_t u8Size(const volatile void *value) {
  size_t size = 0;
  printLog(TRACE, "ENTER u8Size(value=%p)\n", value);
  
  if (value != NULL) {
    size = sizeof(u8);
  }
  
  printLog(TRACE, "EXIT u8Size(value=%p) = {%llu}\n", value, llu(size));
  return size;
}

/// @fn Bytes u8ToBlob(const volatile void *value)
///
/// @brief Convert a u8 value to an array of bytes.
///
/// @param value A pointer to the u8 value to convert.
///
/// @return Returns a Bytes object with the encoded byte array on success,
/// NULL on failure.
Bytes u8ToBlob(const volatile void *value) {
  Bytes returnValue = NULL;
  printLog(TRACE, "ENTER u8ToBlob(value=%u)\n",
    (value == NULL) ? 0 : *((u8*) value));
  
  if (value == NULL) {
    printLog(ERR, "Cannot convert to byte array.  Parameter is NULL.\n");
    printLog(TRACE, "EXIT u8ToBlob(value=%u) = {%p}\n",
      (value == NULL) ? 0 : *((u8*) value), returnValue);
    return returnValue;
  }
  
  bytesAddData(&returnValue, value, sizeof(u8));
  // Set the size to match the length.  This is so data structures that are
  // building byte arrays encode the right amount of data, which does not
  // include the string terminator in our case.
  bytesSetSize(returnValue, bytesLength(returnValue));
  
  printLog(TRACE, "EXIT u8ToBlob(value=%u) = {%p}\n",
    (value == NULL) ? 0 : *((u8*) value), returnValue);
  return returnValue;
}

/// @fn void* u8FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety)
///
/// @brief Convert a u8 value to an array of bytes.
///
/// @param value A pointer to the u8 value to convert.
/// @param length The length of the resulting byte array.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned data.  Not used by this function.
///
/// @return Returns a pointer to a valid byte array on success, NULL on failure.
void* u8FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety) {
  (void) disableThreadSafety;
  void *returnValue = NULL;
  printLog(TRACE,
    "ENTER u8FromBlob(value=%u, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    (value == NULL) ? 0 : *((u8*) value), length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  
  if ((value == NULL) || (length == NULL)) {
    printLog(ERR, "Cannot convert to/from byte array.  Parameter is NULL.\n");
    printLog(TRACE,
      "EXIT u8FromBlob(value=%u, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      (value == NULL) ? 0 : *((u8*) value), length, boolNames[inPlaceData], boolNames[disableThreadSafety],
      returnValue);
    return returnValue; // NULL
  } else if (*length < sizeof(u8)) {
    printLog(ERR, "Cannot convert from byte array.  Insufficient data.\n");
    printLog(ERR, "Needed at least %llu bytes, only have %llu.\n",
      llu(sizeof(u8)), llu(*length));
    printLog(TRACE,
      "EXIT u8FromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return returnValue; // NULL
  }
  
  if (inPlaceData) {
    // Optimize for this case.
    returnValue = (void*) value;
  } else {
    returnValue = u8Copy(value);
  }
  if (returnValue != NULL) {
    *length = sizeof(u8);
  } else {
    *length = 0;
  }
  
  printLog(TRACE,
    "EXIT u8FromBlob(value=%u, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    (value == NULL) ? 0 : *((u8*) value), llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety],
    returnValue);
  return returnValue;
}

/// @var typeU8
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the u8 type.
TypeDescriptor _typeU8 = {
  .name          = "u8",
  .xmlName       = "xs:unsignedByte",
  .dataIsPointer = false,
  .toString      = u8ToString,
  .toBytes       = u8ToBytes,
  .compare       = u8Compare,
  .create        = u8Create,
  .copy          = u8Copy,
  .destroy       = u8Destroy,
  .size          = u8Size,
  .toBlob        = u8ToBlob,
  .fromBlob      = u8FromBlob,
  .hashFunction  = NULL,
  .clear         = clear8,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeU8 = &_typeU8;

/// @var typeU8NoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the u8 type that is not to be copied.
TypeDescriptor _typeU8NoCopy = {
  .name          = "u8",
  .xmlName       = "xs:unsignedByte",
  .dataIsPointer = true,
  .toString      = u8ToString,
  .toBytes       = u8ToBytes,
  .compare       = u8Compare,
  .create        = u8Create,
  .copy          = shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = u8Size,
  .toBlob        = u8ToBlob,
  .fromBlob      = u8FromBlob,
  .hashFunction  = NULL,
  .clear         = clear8,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeU8NoCopy = &_typeU8NoCopy;

/// @fn char *u16ToString(const volatile void *value)
///
/// @brief Convert a u16 value to its string representation.
///
/// @param value A pointer to the u16 value to convert to a string.
///
/// @return Returns a string representation of the value on success,
///   NULL on failure.
char *u16ToString(const volatile void *value) {
  printLog(TRACE, "ENTER u16ToString(value=%u)\n", (value == NULL) ? 0 : *((u16*) value));
  
  char *u16String = NULL;
  if (value == NULL) {
    straddstr(&u16String, "(null)");
    
    printLog(TRACE, "EXIT u16ToString(value=NULL) = {%s}\n", u16String);
    return u16String;
  }
  
  u16 u16Value = *((u16*) value);
  char digit = '\0';
  
  while (u16Value != 0) {
    digit = '0' + (u16Value % 10);
    straddchr(&u16String, digit);
    u16Value /= 10;
  }
  
  if (u16String == NULL) {
    straddchr(&u16String, '0');
  }
  
  reverseString(u16String);
  
  printLog(TRACE, "EXIT u16ToString(value=%u) = {%s}\n", *((u16*) value), u16String);
  return u16String;
}

/// @fn Bytes u16ToBytes(const volatile void *value)
///
/// @brief Convert a u16 value to its Bytes representation.
///
/// @param value A pointer to the u16 value to convert to a Bytes object.
///
/// @return Returns a Bytes representation of the value on success,
///   NULL on failure.
Bytes u16ToBytes(const volatile void *value) {
  printLog(TRACE, "ENTER u16ToBytes(value=%u)\n",
    (value == NULL) ? 0 : *((u16*) value));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT u16ToBytes(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  Bytes u16Bytes = NULL;
  u16 u16Value = *((u16*) value);
  char digit = '\0';
  
  while (u16Value != 0) {
    digit = '0' + (u16Value % 10);
    bytesAddData(&u16Bytes, &digit, sizeof(digit));
    u16Value /= 10;
  }
  
  if (u16Bytes == NULL) {
    digit = '0';
    bytesAddData(&u16Bytes, &digit, sizeof(digit));
  }
  
  reverseMemory(u16Bytes, bytesLength(u16Bytes));
  
  printLog(TRACE, "EXIT u16ToBytes(value=%u) = {%s}\n",
    *((u16*) value), (char*) u16Bytes);
  return u16Bytes;
}

/// @fn int u16Compare(const volatile void *valueA, const volatile void *valueB)
///
/// @brief Compare two u16 values.
///
/// @param valueA, valueB are pointers to the values to compare.
///
/// @return Returns -1 if *valueA < *valueB, 0 if *valueA == *valueB,
///   1 if *valueA > *valueB.
int u16Compare(const volatile void *valueA, const volatile void *valueB) {
  printLog(TRACE, "ENTER u16Compare(valueA=%u, valueB=%u)\n", (valueA == NULL) ? 0 : *((u16*) valueA), (valueB == NULL) ? 0 : *((u16*) valueB));
  
  int returnValue = 0;
  
  if (valueA == NULL) {
    printLog(WARN, "valueA is NULL.\n");
    returnValue--;
  }
  if (valueB == NULL) {
    printLog(WARN, "valueB is NULL.\n");
    returnValue++;
  }
  if ((valueA == NULL) || (valueB == NULL)) {
    printLog(TRACE, "EXIT u16Compare(valueA=%p, valueB=%p) = {%d}\n", valueA,
      valueB, returnValue);
    return returnValue;
  }

  u16 u16ValueA = *((u16*) valueA);
  u16 u16ValueB = *((u16*) valueB);
  
  if (u16ValueA < u16ValueB) {
    printLog(TRACE, "EXIT u16Compare(valueA=%u, valueB=%u) = {-1}\n", *((u16*) valueA), *((u16*) valueB));
    returnValue = -1;
  } else if (u16ValueA > u16ValueB) {
    printLog(TRACE, "EXIT u16Compare(valueA=%u, valueB=%u) = {1}\n", *((u16*) valueA), *((u16*) valueB));
    returnValue = 1;
  } else { // u16ValueA == u16ValueB
    returnValue = 0;
  }
  
  printLog(TRACE, "EXIT u16Compare(valueA=%u, valueB=%u) = {%d}\n",
    u16ValueA, u16ValueB, returnValue);
  return returnValue;
}

/// @fn void *u16Create(const volatile void *parameter1, ...)
///
/// @brief Allocate memory for a new u16 value and initialize it to 0.
///
/// @param parameter1 Dummy parameter for the sake of conformance to
///   TypeDescriptor definition.  Unused by this function.
///
/// @return Returns a pointer to the newly-initialized value.
void *u16Create(const volatile void *parameter1, ...) {
  printLog(TRACE, "ENTER u16Create()\n");
  
  (void) parameter1; // Keep the compiler from complaining.
  
  u16 *value = (u16*) malloc(sizeof(u16));
  *value = 0;
  
  printLog(TRACE, "EXIT u16Create() = {%u}\n", *((u16*) value));
  return (void*) value;
}

/// @fn void *u16Copy(const volatile void *value)
///
/// @brief Create a new u16 value and assign it the value of the input value.
///
/// @param value Pointer to the value to copy.
///
/// @return A pointer to a new u16 with the specified value.
void *u16Copy(const volatile void *value) {
  printLog(TRACE, "ENTER u16Copy(value=%u)\n", (value == NULL) ? 0 : *((u16*) value));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT u16Copy(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  u16 *valueCopy = (u16*) malloc(sizeof(u16));
  if (valueCopy != NULL) {
    *valueCopy = *((u16*) value);
  }
  
  printLog(TRACE, "EXIT u16Copy(value=%u) = {%p}\n", *((u16*) value), valueCopy);
  return valueCopy;
}

/// @fn void *u16Destroy(volatile void *value)
///
/// @brief Release the memory associated with a u16 value.
///
/// @param value A pointer to the memory to be released.
///
/// @return Returns a null pointer on success, the input pointer on failure.
///   NOTE: Use of the pointer returned by this function will result in
///   undefined behavior.
void *u16Destroy(volatile void *value) {
  printLog(TRACE, "ENTER u16Destroy(value=%u)\n", (value == NULL) ? 0 : *((u16*) value));
  
  value = pointerDestroy(value);
  
  printLog(TRACE, "EXIT u16Destroy(value=%p) = {%p}\n", value, value);
  return (void*) value;
}

/// @fn size_t u16Size(const volatile void *value)
///
/// @brief Return the size of a u16 type.
///
/// @param value A pointer to a u16 variable.
///
/// @return Return the size of a u16 type.
size_t u16Size(const volatile void *value) {
  size_t size = 0;
  printLog(TRACE, "ENTER u16Size(value=%p)\n", value);
  
  if (value != NULL) {
    size = sizeof(u16);
  }
  
  printLog(TRACE, "EXIT u16Size(value=%p) = {%llu}\n", value, llu(size));
  return size;
}

/// @fn Bytes u16ToBlob(const volatile void *value)
///
/// @brief Convert a u16 value to an array of bytes.
///
/// @param value A pointer to the u16 value to convert.
///
/// @return Returns a Bytes object with the encoded byte array on success,
/// NULL on failure.
Bytes u16ToBlob(const volatile void *value) {
  Bytes returnValue = NULL;
  printLog(TRACE, "ENTER u16ToBlob(value=%u)\n",
    (value == NULL) ? 0 : *((u16*) value));
  
  if (value == NULL) {
    printLog(ERR, "Cannot convert to byte array.  Parameter is NULL.\n");
    printLog(TRACE, "EXIT u16ToBlob(value=%u) = {%p}\n",
      (value == NULL) ? 0 : *((u16*) value), returnValue);
    return returnValue;
  }
  
  bytesAddData(&returnValue, value, sizeof(u16));
  hostToLittleEndian(returnValue, sizeof(u16));
  // Set the size to match the length.  This is so data structures that are
  // building byte arrays encode the right amount of data, which does not
  // include the string terminator in our case.
  bytesSetSize(returnValue, bytesLength(returnValue));
  
  printLog(TRACE, "EXIT u16ToBlob(value=%u) = {%p}\n",
    (value == NULL) ? 0 : *((u16*) value), returnValue);
  return returnValue;
}

/// @fn void* u16FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety)
///
/// @brief Convert a u16 value to an array of bytes.
///
/// @param value A pointer to the u16 value to convert.
/// @param length The length of the resulting byte array.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned data.  Not used by this function.
///
/// @return Returns a pointer to a valid byte array on success, NULL on failure.
void* u16FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety) {
  (void) disableThreadSafety;
  void *returnValue = NULL;
  printLog(TRACE,
    "ENTER u16FromBlob(value=%u, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    (value == NULL) ? 0 : *((u16*) value), length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  
  if ((value == NULL) || (length == NULL)) {
    printLog(ERR, "Cannot convert to/from byte array.  Parameter is NULL.\n");
    printLog(TRACE,
      "EXIT u16FromBlob(value=%u, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      (value == NULL) ? 0 : *((u16*) value), length, boolNames[inPlaceData], boolNames[disableThreadSafety],
      returnValue);
    return returnValue; // NULL
  } else if (*length < sizeof(u16)) {
    printLog(ERR, "Cannot convert from byte array.  Insufficient data.\n");
    printLog(ERR, "Needed at least %llu bytes, only have %llu.\n",
      llu(sizeof(u16)), llu(*length));
    printLog(TRACE,
      "EXIT u16FromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return returnValue; // NULL
  }
  
  if (inPlaceData) {
    // Optimize for this case.
    returnValue = (void*) value;
  } else {
    returnValue = u16Copy(value);
  }
  littleEndianToHost(returnValue, sizeof(u16));
  if (returnValue != NULL) {
    *length = sizeof(u16);
  } else {
    *length = 0;
  }
  
  printLog(TRACE,
    "EXIT u16FromBlob(value=%u, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    (value == NULL) ? 0 : *((u16*) value), llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety],
    returnValue);
  return returnValue;
}

/// @var typeU16
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the u16 type.
TypeDescriptor _typeU16 = {
  .name          = "u16",
  .xmlName       = "xs:unsignedShort",
  .dataIsPointer = false,
  .toString      = u16ToString,
  .toBytes       = u16ToBytes,
  .compare       = u16Compare,
  .create        = u16Create,
  .copy          = u16Copy,
  .destroy       = u16Destroy,
  .size          = u16Size,
  .toBlob        = u16ToBlob,
  .fromBlob      = u16FromBlob,
  .hashFunction  = NULL,
  .clear         = clear16,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeU16 = &_typeU16;

/// @var typeU16NoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the u16 type that is not to be copied.
TypeDescriptor _typeU16NoCopy = {
  .name          = "u16",
  .xmlName       = "xs:unsignedShort",
  .dataIsPointer = true,
  .toString      = u16ToString,
  .toBytes       = u16ToBytes,
  .compare       = u16Compare,
  .create        = u16Create,
  .copy          = shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = u16Size,
  .toBlob        = u16ToBlob,
  .fromBlob      = u16FromBlob,
  .hashFunction  = NULL,
  .clear         = clear16,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeU16NoCopy = &_typeU16NoCopy;

/// @fn char *u32ToString(const volatile void *value)
///
/// @brief Convert a u32 value to its string representation.
///
/// @param value A pointer to the u32 value to convert to a string.
///
/// @return Returns a string representation of the value on success,
///   NULL on failure.
char *u32ToString(const volatile void *value) {
  printLog(TRACE, "ENTER u32ToString(value=%u)\n", (value == NULL) ? 0 : *((u32*) value));
  
  char *u32String = NULL;
  if (value == NULL) {
    straddstr(&u32String, "(null)");
    
    printLog(TRACE, "EXIT u32ToString(value=NULL) = {%s}\n", u32String);
    return u32String;
  }
  
  u32 u32Value = *((u32*) value);
  char digit = '\0';
  
  while (u32Value != 0) {
    digit = '0' + (u32Value % 10);
    straddchr(&u32String, digit);
    u32Value /= 10;
  }
  
  if (u32String == NULL) {
    straddchr(&u32String, '0');
  }
  
  reverseString(u32String);
  
  printLog(TRACE, "EXIT u32ToString(value=%u) = {%s}\n", *((u32*) value), u32String);
  return u32String;
}

/// @fn Bytes u32ToBytes(const volatile void *value)
///
/// @brief Convert a u32 value to its Bytes representation.
///
/// @param value A pointer to the u32 value to convert to a Bytes object.
///
/// @return Returns a Bytes representation of the value on success,
///   NULL on failure.
Bytes u32ToBytes(const volatile void *value) {
  printLog(TRACE, "ENTER u32ToBytes(value=%u)\n",
    (value == NULL) ? 0 : *((u32*) value));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT u32ToBytes(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  Bytes u32Bytes = NULL;
  u32 u32Value = *((u32*) value);
  char digit = '\0';
  
  while (u32Value != 0) {
    digit = '0' + (u32Value % 10);
    bytesAddData(&u32Bytes, &digit, sizeof(digit));
    u32Value /= 10;
  }
  
  if (u32Bytes == NULL) {
    digit = '0';
    bytesAddData(&u32Bytes, &digit, sizeof(digit));
  }
  
  reverseMemory(u32Bytes, bytesLength(u32Bytes));
  
  printLog(TRACE, "EXIT u32ToBytes(value=%u) = {%s}\n",
    *((u32*) value), (char*) u32Bytes);
  return u32Bytes;
}

/// @fn int u32Compare(const volatile void *valueA, const volatile void *valueB)
///
/// @brief Compare two u32 values.
///
/// @param valueA, valueB are pointers to the values to compare.
///
/// @return Returns -1 if *valueA < *valueB, 0 if *valueA == *valueB,
///   1 if *valueA > *valueB.
int u32Compare(const volatile void *valueA, const volatile void *valueB) {
  printLog(TRACE, "ENTER u32Compare(valueA=%u, valueB=%u)\n", (valueA == NULL) ? 0 : *((u32*) valueA), (valueB == NULL) ? 0 : *((u32*) valueB));
  
  int returnValue = 0;
  
  if (valueA == NULL) {
    printLog(WARN, "valueA is NULL.\n");
    returnValue--;
  }
  if (valueB == NULL) {
    printLog(WARN, "valueB is NULL.\n");
    returnValue++;
  }
  if ((valueA == NULL) || (valueB == NULL)) {
    printLog(TRACE, "EXIT u32Compare(valueA=%p, valueB=%p) = {%d}\n", valueA,
      valueB, returnValue);
    return returnValue;
  }
  
  u32 u32ValueA = *((u32*) valueA);
  u32 u32ValueB = *((u32*) valueB);
  
  if (u32ValueA < u32ValueB) {
    returnValue = -1;
  } else if (u32ValueA > u32ValueB) {
    returnValue = 1;
  } else { // u32ValueA == u32ValueB
    returnValue = 0;
  }
  
  printLog(TRACE, "EXIT u32Compare(valueA=%u, valueB=%u) = {%d}\n",
    u32ValueA, u32ValueB, returnValue);
  return returnValue;
}

/// @fn void *u32Create(const volatile void *parameter1, ...)
///
/// @brief Allocate memory for a new u32 value and initialize it to 0.
///
/// @param parameter1 Dummy parameter for the sake of conformance to
///   TypeDescriptor definition.  Unused by this function.
///
/// @return Returns a pointer to the newly-initialized value.
void *u32Create(const volatile void *parameter1, ...) {
  printLog(TRACE, "ENTER u32Create()\n");
  
  (void) parameter1; // Keep the compiler from complaining.
  
  u32 *value = (u32*) malloc(sizeof(u32));
  *value = 0;
  
  printLog(TRACE, "EXIT u32Create() = {%u}\n", *((u32*) value));
  return (void*) value;
}

/// @fn void *u32Copy(const volatile void *value)
///
/// @brief Create a new u32 value and assign it the value of the input value.
///
/// @param value Pointer to the value to copy.
///
/// @return A pointer to a new u32 with the specified value.
void *u32Copy(const volatile void *value) {
  printLog(TRACE, "ENTER u32Copy(value=%u)\n", (value == NULL) ? 0 : *((u32*) value));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT u32Copy(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  u32 *valueCopy = (u32*) malloc(sizeof(u32));
  if (valueCopy != NULL) {
    *valueCopy = *((u32*) value);
  }
  
  printLog(TRACE, "EXIT u32Copy(value=%u) = {%p}\n", *((u32*) value), valueCopy);
  return valueCopy;
}

/// @fn void *u32Destroy(volatile void *value)
///
/// @brief Release the memory associated with a u32 value.
///
/// @param value A pointer to the memory to be released.
///
/// @return Returns a null pointer on success, the input pointer on failure.
///   NOTE: Use of the pointer returned by this function will result in
///   undefined behavior.
void *u32Destroy(volatile void *value) {
  printLog(TRACE, "ENTER u32Destroy(value=%u)\n", (value == NULL) ? 0 : *((u32*) value));
  
  value = pointerDestroy(value);
  
  printLog(TRACE, "EXIT u32Destroy(value=%p) = {%p}\n", value, value);
  return (void*) value;
}

/// @fn size_t u32Size(const volatile void *value)
///
/// @brief Return the size of a u32 type.
///
/// @param value A pointer to a u32 variable.
///
/// @return Return the size of a u32 type.
size_t u32Size(const volatile void *value) {
  size_t size = 0;
  printLog(TRACE, "ENTER u32Size(value=%p)\n", value);
  
  if (value != NULL) {
    size = sizeof(u32);
  }
  
  printLog(TRACE, "EXIT u32Size(value=%p) = {%llu}\n", value, llu(size));
  return size;
}

/// @fn Bytes u32ToBlob(const volatile void *value)
///
/// @brief Convert a u32 value to an array of bytes.
///
/// @param value A pointer to the u32 value to convert.
///
/// @return Returns a Bytes object with the encoded byte array on success,
/// NULL on failure.
Bytes u32ToBlob(const volatile void *value) {
  Bytes returnValue = NULL;
  printLog(TRACE, "ENTER u32ToBlob(value=%u)\n",
    (value == NULL) ? 0 : *((u32*) value));
  
  if (value == NULL) {
    printLog(ERR, "Cannot convert to byte array.  Parameter is NULL.\n");
    printLog(TRACE, "EXIT u32ToBlob(value=%u) = {%p}\n",
      (value == NULL) ? 0 : *((u32*) value), returnValue);
    return returnValue;
  }
  
  bytesAddData(&returnValue, value, sizeof(u32));
  hostToLittleEndian(returnValue, sizeof(u32));
  // Set the size to match the length.  This is so data structures that are
  // building byte arrays encode the right amount of data, which does not
  // include the string terminator in our case.
  bytesSetSize(returnValue, bytesLength(returnValue));
  
  printLog(TRACE, "EXIT u32ToBlob(value=%u) = {%p}\n",
    (value == NULL) ? 0 : *((u32*) value), returnValue);
  return returnValue;
}

/// @fn void* u32FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety)
///
/// @brief Convert a u32 value to an array of bytes.
///
/// @param value A pointer to the u32 value to convert.
/// @param length The length of the resulting byte array.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned data.  Not used by this function.
///
/// @return Returns a pointer to a valid byte array on success, NULL on failure.
void* u32FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety) {
  (void) disableThreadSafety;
  void *returnValue = NULL;
  printLog(TRACE,
    "ENTER u32FromBlob(value=%u, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    (value == NULL) ? 0 : *((u32*) value), length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  
  if ((value == NULL) || (length == NULL)) {
    printLog(ERR, "Cannot convert to/from byte array.  Parameter is NULL.\n");
    printLog(TRACE,
      "EXIT u32FromBlob(value=%u, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      (value == NULL) ? 0 : *((u32*) value), length, boolNames[inPlaceData], boolNames[disableThreadSafety],
      returnValue);
    return returnValue; // NULL
  } else if (*length < sizeof(u32)) {
    printLog(ERR, "Cannot convert from byte array.  Insufficient data.\n");
    printLog(ERR, "Needed at least %llu bytes, only have %llu.\n",
      llu(sizeof(u32)), llu(*length));
    printLog(TRACE,
      "EXIT u32FromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return returnValue; // NULL
  }
  
  if (inPlaceData) {
    // Optimize for this case.
    returnValue = (void*) value;
  } else {
    returnValue = u32Copy(value);
  }
  littleEndianToHost(returnValue, sizeof(u32));
  if (returnValue != NULL) {
    *length = sizeof(u32);
  } else {
    *length = 0;
  }
  
  printLog(TRACE,
    "EXIT u32FromBlob(value=%u, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    (value == NULL) ? 0 : *((u32*) value), llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety],
    returnValue);
  return returnValue;
}

/// @var typeU32
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the u32 type.
TypeDescriptor _typeU32 = {
  .name          = "u32",
  .xmlName       = "xs:unsignedInt",
  .dataIsPointer = false,
  .toString      = u32ToString,
  .toBytes       = u32ToBytes,
  .compare       = u32Compare,
  .create        = u32Create,
  .copy          = u32Copy,
  .destroy       = u32Destroy,
  .size          = u32Size,
  .toBlob        = u32ToBlob,
  .fromBlob      = u32FromBlob,
  .hashFunction  = NULL,
  .clear         = clear32,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeU32 = &_typeU32;

/// @var typeU32NoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the u32 type that is not to be copied.
TypeDescriptor _typeU32NoCopy = {
  .name          = "u32",
  .xmlName       = "xs:unsignedInt",
  .dataIsPointer = true,
  .toString      = u32ToString,
  .toBytes       = u32ToBytes,
  .compare       = u32Compare,
  .create        = u32Create,
  .copy          = shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = u32Size,
  .toBlob        = u32ToBlob,
  .fromBlob      = u32FromBlob,
  .hashFunction  = NULL,
  .clear         = clear32,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeU32NoCopy = &_typeU32NoCopy;

/// @fn char *u64ToString(const volatile void *value)
///
/// @brief Convert a u64 value to its string representation.
///
/// @param value A pointer to the u64 value to convert to a string.
///
/// @return Returns a string representation of the value on success,
///   NULL on failure.
char *u64ToString(const volatile void *value) {
  printLog(TRACE, "ENTER u64ToString(value=%llu)\n", (value == NULL) ? 0 : llu(*((u64*) value)));
  
  char *u64String = NULL;
  if (value == NULL) {
    straddstr(&u64String, "(null)");
    printLog(TRACE, "EXIT u64ToString(value=NULL) = {%s}\n", u64String);
    return u64String;
  }
  
  u64 u64Value = *((u64*) value);
  char digit = '\0';
  
  while (u64Value != 0) {
    digit = '0' + (u64Value % 10);
    straddchr(&u64String, digit);
    u64Value /= 10;
  }
  
  if (u64String == NULL) {
    straddchr(&u64String, '0');
  }
  
  reverseString(u64String);
  
  printLog(TRACE, "EXIT u64ToString(value=%llu) = {%s}\n", llu(*((u64*) value)), u64String);
  return u64String;
}

/// @fn Bytes u64ToBytes(const volatile void *value)
///
/// @brief Convert a u64 value to its Bytes representation.
///
/// @param value A pointer to the u64 value to convert to a Bytes object.
///
/// @return Returns a Bytes representation of the value on success,
///   NULL on failure.
Bytes u64ToBytes(const volatile void *value) {
  printLog(TRACE, "ENTER u64ToBytes(value=%llu)\n",
    (value == NULL) ? 0 : llu(*((u64*) value)));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT u64ToBytes(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  Bytes u64Bytes = NULL;
  u64 u64Value = *((u64*) value);
  char digit = '\0';
  
  while (u64Value != 0) {
    digit = '0' + (u64Value % 10);
    bytesAddData(&u64Bytes, &digit, sizeof(digit));
    u64Value /= 10;
  }
  
  if (u64Bytes == NULL) {
    digit = '0';
    bytesAddData(&u64Bytes, &digit, sizeof(digit));
  }
  
  reverseMemory(u64Bytes, bytesLength(u64Bytes));
  
  printLog(TRACE, "EXIT u64ToBytes(value=%llu) = {%s}\n",
    llu(*((u64*) value)), (char*) u64Bytes);
  return u64Bytes;
}

/// @fn int u64Compare(const volatile void *valueA, const volatile void *valueB)
///
/// @brief Compare two u64 values.
///
/// @param valueA, valueB are pointers to the values to compare.
///
/// @return Returns -1 if *valueA < *valueB, 0 if *valueA == *valueB,
///   1 if *valueA > *valueB.
int u64Compare(const volatile void *valueA, const volatile void *valueB) {
  printLog(TRACE, "ENTER u64Compare(valueA=%llu, valueB=%llu)\n", (valueA == NULL) ? 0 : llu(*((u64*) valueA)), (valueB == NULL) ? 0 : llu(*((u64*) valueB)));
  
  int returnValue = 0;
  
  if (valueA == NULL) {
    printLog(ERR, "valueA is NULL.\n");
    returnValue--;
  }
  if (valueB == NULL) {
    printLog(ERR, "valueB is NULL.\n");
    returnValue++;
  }
  if ((valueA == NULL) || (valueB == NULL)) {
    printLog(TRACE, "EXIT u64Compare(valueA=%p, valueB=%p) = {%d}\n", valueA,
      valueB, returnValue);
    return returnValue;
  }

  u64 u64ValueA = *((u64*) valueA);
  u64 u64ValueB = *((u64*) valueB);
  
  if (u64ValueA < u64ValueB) {
    returnValue = -1;
  } else if (u64ValueA > u64ValueB) {
    returnValue = 1;
  } else { // u64ValueA == u64ValueB
    returnValue = 0;
  }
  
  printLog(TRACE, "EXIT u64Compare(valueA=%llu, valueB=%llu) = {%d}\n",
    llu(u64ValueA), llu(u64ValueB), returnValue);
  return returnValue;
}

/// @fn void *u64Create(const volatile void *parameter1, ...)
///
/// @brief Allocate memory for a new u64 value and initialize it to 0.
///
/// @param parameter1 Dummy parameter for the sake of conformance to
///   TypeDescriptor definition.  Unused by this function.
///
/// @return Returns a pointer to the newly-initialized value.
void *u64Create(const volatile void *parameter1, ...) {
  printLog(TRACE, "ENTER u64Create()\n");
  
  (void) parameter1; // Keep the compiler from complaining.
  
  u64 *value = (u64*) malloc(sizeof(u64));
  *value = 0;
  
  printLog(TRACE, "EXIT u64Create() = {%llu}\n", llu(*((u64*) value)));
  return (void*) value;
}

/// @fn void *u64Copy(const volatile void *value)
///
/// @brief Create a new u64 value and assign it the value of the input value.
///
/// @param value Pointer to the value to copy.
///
/// @return A pointer to a new u64 with the specified value.
void *u64Copy(const volatile void *value) {
  printLog(TRACE, "ENTER u64Copy(value=%llu)\n", (value == NULL) ? 0 : llu(*((u64*) value)));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT u64Copy(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  u64 *valueCopy = (u64*) malloc(sizeof(u64));
  if (valueCopy != NULL) {
    *valueCopy = *((u64*) value);
  }
  
  printLog(TRACE, "EXIT u64Copy(value=%llu) = {%p}\n", llu(*((u64*) value)), valueCopy);
  return valueCopy;
}

/// @fn void *u64Destroy(volatile void *value)
///
/// @brief Release the memory associated with a u64 value.
///
/// @param value A pointer to the memory to be released.
///
/// @return Returns a null pointer on success, the input pointer on failure.
///   NOTE: Use of the pointer returned by this function will result in
///   undefined behavior.
void *u64Destroy(volatile void *value) {
  printLog(TRACE, "ENTER u64Destroy(value=%llu)\n", (value == NULL) ? 0 : llu(*((u64*) value)));
  
  value = pointerDestroy(value);
  
  printLog(TRACE, "EXIT u64Destroy(value=%p) = {%p}\n", value, value);
  return (void*) value;
}

/// @fn size_t u64Size(const volatile void *value)
///
/// @brief Return the size of a u64 type.
///
/// @param value A pointer to a u64 variable.
///
/// @return Return the size of a u64 type.
size_t u64Size(const volatile void *value) {
  size_t size = 0;
  printLog(TRACE, "ENTER u64Size(value=%p)\n", value);
  
  if (value != NULL) {
    size = sizeof(u64);
  }
  
  printLog(TRACE, "EXIT u64Size(value=%p) = {%llu}\n", value, llu(size));
  return size;
}

/// @fn Bytes u64ToBlob(const volatile void *value)
///
/// @brief Convert a u64 value to an array of bytes.
///
/// @param value A pointer to the u64 value to convert.
///
/// @return Returns a Bytes object with the encoded byte array on success,
/// NULL on failure.
Bytes u64ToBlob(const volatile void *value) {
  Bytes returnValue = NULL;
  printLog(TRACE, "ENTER u64ToBlob(value=%llu)\n",
    (value == NULL) ? 0 : llu(*((u64*) value)));
  
  if (value == NULL) {
    printLog(ERR, "Cannot convert to byte array.  Parameter is NULL.\n");
    printLog(TRACE, "EXIT u64ToBlob(value=%llu) = {%p}\n",
      (value == NULL) ? 0 : llu(*((u64*) value)), returnValue);
    return returnValue;
  }
  
  bytesAddData(&returnValue, value, sizeof(u64));
  hostToLittleEndian(returnValue, sizeof(u64));
  // Set the size to match the length.  This is so data structures that are
  // building byte arrays encode the right amount of data, which does not
  // include the string terminator in our case.
  bytesSetSize(returnValue, bytesLength(returnValue));
  
  printLog(TRACE, "EXIT u64ToBlob(value=%llu) = {%p}\n",
    (value == NULL) ? 0 : llu(*((u64*) value)), returnValue);
  return returnValue;
}

/// @fn void* u64FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety)
///
/// @brief Convert a u64 value to an array of bytes.
///
/// @param value A pointer to the u64 value to convert.
/// @param length The length of the resulting byte array.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned data.  Not used by this function.
///
/// @return Returns a pointer to a valid byte array on success, NULL on failure.
void* u64FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety) {
  (void) disableThreadSafety;
  void *returnValue = NULL;
  printLog(TRACE,
    "ENTER u64FromBlob(value=%llu, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    (value == NULL) ? 0 : llu(*((u64*) value)), length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  
  if ((value == NULL) || (length == NULL)) {
    printLog(ERR, "Cannot convert to/from byte array.  Parameter is NULL.\n");
    printLog(TRACE,
      "EXIT u64FromBlob(value=%llu, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      (value == NULL) ? 0 : llu(*((u64*) value)), length, boolNames[inPlaceData], boolNames[disableThreadSafety],
      returnValue);
    return returnValue; // NULL
  } else if (*length < sizeof(u64)) {
    printLog(ERR, "Cannot convert from byte array.  Insufficient data.\n");
    printLog(ERR, "Needed at least %llu bytes, only have %llu.\n",
      llu(sizeof(u64)), llu(*length));
    printLog(TRACE,
      "EXIT u64FromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return returnValue; // NULL
  }
  
  if (inPlaceData) {
    // Optimize for this case.
    returnValue = (void*) value;
  } else {
    returnValue = u64Copy(value);
  }
  littleEndianToHost(returnValue, sizeof(u64));
  if (returnValue != NULL) {
    *length = sizeof(u64);
  } else {
    *length = 0;
  }
  
  printLog(TRACE,
    "EXIT u64FromBlob(value=%llu, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    (value == NULL) ? 0 : llu(*((u64*) value)), llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety],
    returnValue);
  return returnValue;
}

/// @var typeU64
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the u64 type.
TypeDescriptor _typeU64 = {
  .name          = "u64",
  .xmlName       = "xs:unsignedLong",
  .dataIsPointer = false,
  .toString      = u64ToString,
  .toBytes       = u64ToBytes,
  .compare       = u64Compare,
  .create        = u64Create,
  .copy          = u64Copy,
  .destroy       = u64Destroy,
  .size          = u64Size,
  .toBlob        = u64ToBlob,
  .fromBlob      = u64FromBlob,
  .hashFunction  = NULL,
  .clear         = clear64,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeU64 = &_typeU64;

/// @var typeU64NoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the u64 type that is not to be copied.
TypeDescriptor _typeU64NoCopy = {
  .name          = "u64",
  .xmlName       = "xs:unsignedLong",
  .dataIsPointer = true,
  .toString      = u64ToString,
  .toBytes       = u64ToBytes,
  .compare       = u64Compare,
  .create        = u64Create,
  .copy          = shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = u64Size,
  .toBlob        = u64ToBlob,
  .fromBlob      = u64FromBlob,
  .hashFunction  = NULL,
  .clear         = clear64,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeU64NoCopy = &_typeU64NoCopy;

/// @fn char *u128ToString(const volatile void *value)
///
/// @brief Convert a u128 value to its string representation.
///
/// @param value A pointer to the u128 value to convert to a string.
///
/// @return Returns a string representation of the value on success,
///   NULL on failure.
char *u128ToString(const volatile void *value) {
  printLog(TRACE, "ENTER u128ToString(value=%p)\n", value);
  
  char *u128String = NULL;
  if (value == NULL) {
    straddstr(&u128String, "(null)");
    
    printLog(TRACE, "EXIT u128ToString(value=NULL) = {%s}\n", u128String);
    return u128String;
  }
  
  u128 u128Value = *((u128*) value);
  char digit = '\0';
  
  while (u128Value != 0) {
    digit = '0' + (u128Value % 10);
    straddchr(&u128String, digit);
    u128Value /= 10;
  }
  
  if (u128String == NULL) {
    straddchr(&u128String, '0');
  }
  
  reverseString(u128String);
  
  printLog(TRACE, "EXIT u128ToString(value=%p) = {%s}\n", value, u128String);
  return u128String;
}

/// @fn char *u128ToBytes(const volatile void *value)
///
/// @brief Convert a u128 value to its Bytes representation.
///
/// @param value A pointer to the u128 value to convert to a Bytes object.
///
/// @return Returns a Bytes representation of the value on success,
///   NULL on failure.
Bytes u128ToBytes(const volatile void *value) {
  printLog(TRACE, "ENTER u128ToBytes(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(TRACE, "EXIT u128ToBytes(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  Bytes u128Bytes = NULL;
  u128 u128Value = *((u128*) value);
  char digit = '\0';
  
  while (u128Value != 0) {
    digit = '0' + (u128Value % 10);
    bytesAddData(&u128Bytes, &digit, sizeof(digit));
    u128Value /= 10;
  }
  
  if (u128Bytes == NULL) {
    digit = '0';
    bytesAddData(&u128Bytes, &digit, sizeof(digit));
  }
  
  reverseMemory(u128Bytes, bytesLength(u128Bytes));
  
  printLog(TRACE, "EXIT u128ToBytes(value=%p) = {%s}\n", value, u128Bytes);
  return u128Bytes;
}

/// @fn int u128Compare(const volatile void *valueA, const volatile void *valueB)
///
/// @brief Compare two u128 values.
///
/// @param valueA, valueB are pointers to the values to compare.
///
/// @return Returns -1 if *valueA < *valueB, 0 if *valueA == *valueB,
///   1 if *valueA > *valueB.
int u128Compare(const volatile void *valueA, const volatile void *valueB) {
  printLog(TRACE, "ENTER u128Compare(valueA=%p, valueB=%p)\n", valueA, valueB);
  
  int returnValue = 0;
  
  if (valueA == NULL) {
    printLog(WARN, "valueA is NULL.\n");
    returnValue--;
  }
  if (valueB == NULL) {
    printLog(WARN, "valueB is NULL.\n");
    returnValue++;
  }
  if ((valueA == NULL) || (valueB == NULL)) {
    printLog(TRACE, "EXIT u128Compare(valueA=%p, valueB=%p) = {%d}\n", valueA,
      valueB, returnValue);
    return returnValue;
  }

  u128 u128ValueA = *((u128*) valueA);
  u128 u128ValueB = *((u128*) valueB);
  
  if (u128ValueA < u128ValueB) {
    returnValue = -1;
  } else if (u128ValueA > u128ValueB) {
    returnValue = 1;
  } else { // u128ValueA == u128ValueB
    returnValue = 0;
  }
  
  printLog(TRACE, "EXIT u128Compare(valueA=%p, valueB=%p) = {%d}\n", valueA,
    valueB, returnValue);
  return returnValue;
}

/// @fn void *u128Create(const volatile void *parameter1, ...)
///
/// @brief Allocate memory for a new u128 value and initialize it to 0.
///
/// @param parameter1 Dummy parameter for the sake of conformance to
///   TypeDescriptor definition.  Unused by this function.
///
/// @return Returns a pointer to the newly-initialized value.
void *u128Create(const volatile void *parameter1, ...) {
  printLog(TRACE, "ENTER u128Create()");
  
  (void) parameter1; // Keep the compiler from complaining.
  
  u128 *value = (u128*) malloc(sizeof(u128));
  *value = 0;
  
  printLog(TRACE, "EXIT u128Create() = {%p}\n", value);
  return (void*) value;
}

/// @fn void *u128Copy(const volatile void *value)
///
/// @brief Create a new u128 value and assign it the value of the input value.
///
/// @param value Pointer to the value to copy.
///
/// @return A pointer to a new u128 with the specified value.
void *u128Copy(const volatile void *value) {
  printLog(TRACE, "ENTER u128Copy(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(TRACE, "EXIT u128Copy(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  u128 *valueCopy = (u128*) malloc(sizeof(u128));
  if (valueCopy != NULL) {
    *valueCopy = *((u128*) value);
  }
  
  printLog(TRACE, "EXIT u128Copy(value=%p) = {%p}\n", value, valueCopy);
  return valueCopy;
}

/// @fn void *u128Destroy(volatile void *value)
///
/// @brief Release the memory associated with a u128 value.
///
/// @param value A pointer to the memory to be released.
///
/// @return Returns a null pointer on success, the input pointer on failure.
///   NOTE: Use of the pointer returned by this function will result in
///   undefined behavior.
void *u128Destroy(volatile void *value) {
  printLog(TRACE, "ENTER u128Destroy(value=%p)\n", value);
  
  value = pointerDestroy(value);
  
  printLog(TRACE, "EXIT u128Destroy(value=%p) = {%p}\n", value, value);
  return (void*) value;
}

/// @fn size_t u128Size(const volatile void *value)
///
/// @brief Return the size of a u128 type.
///
/// @param value A pointer to a u128 variable.
///
/// @return Return the size of a u128 type.
size_t u128Size(const volatile void *value) {
  size_t size = 0;
  printLog(TRACE, "ENTER u128Size(value=%p)\n", value);
  
  if (value != NULL) {
    size = sizeof(u128);
  }
  
  printLog(TRACE, "EXIT u128Size(value=%p) = {%llu}\n", value, llu(size));
  return size;
}

/// @fn Bytes u128ToBlob(const volatile void *value)
///
/// @brief Convert a u128 value to an array of bytes.
///
/// @param value A pointer to the u128 value to convert.
///
/// @return Returns a Bytes object with the encoded byte array on success,
/// NULL on failure.
Bytes u128ToBlob(const volatile void *value) {
  Bytes returnValue = NULL;
  printLog(TRACE, "ENTER u128ToBlob(value=%p)\n",
    (value == NULL) ? 0 : value);
  
  if (value == NULL) {
    printLog(ERR, "Cannot convert to byte array.  Parameter is NULL.\n");
    printLog(TRACE, "EXIT u128ToBlob(value=%p) = {%p}\n",
      (value == NULL) ? 0 : value, returnValue);
    return returnValue;
  }
  
  bytesAddData(&returnValue, value, sizeof(u128));
  hostToLittleEndian(returnValue, sizeof(u128));
  // Set the size to match the length.  This is so data structures that are
  // building byte arrays encode the right amount of data, which does not
  // include the string terminator in our case.
  bytesSetSize(returnValue, bytesLength(returnValue));
  
  printLog(TRACE, "EXIT u128ToBlob(value=%p) = {%p}\n",
    (value == NULL) ? 0 : value, returnValue);
  return returnValue;
}

/// @fn void* u128FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety)
///
/// @brief Convert a u128 value to an array of bytes.
///
/// @param value A pointer to the u128 value to convert.
/// @param length The length of the resulting byte array.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned data.  Not used by this function.
///
/// @return Returns a pointer to a valid byte array on success, NULL on failure.
void* u128FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety) {
  (void) disableThreadSafety;
  void *returnValue = NULL;
  printLog(TRACE,
    "ENTER u128FromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    value, length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  
  if ((value == NULL) || (length == NULL)) {
    printLog(ERR, "Cannot convert to/from byte array.  Parameter is NULL.\n");
    printLog(TRACE,
      "EXIT u128FromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return returnValue; // NULL
  } else if (*length < sizeof(u128)) {
    printLog(ERR, "Cannot convert from byte array.  Insufficient data.\n");
    printLog(ERR, "Needed at least %llu bytes, only have %llu.\n",
      llu(sizeof(u128)), llu(*length));
    printLog(TRACE,
      "EXIT u128FromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return returnValue; // NULL
  }
  
  if (inPlaceData) {
    // Optimize for this case.
    returnValue = (void*) value;
  } else {
    returnValue = u128Copy(value);
  }
  littleEndianToHost(returnValue, sizeof(u128));
  if (returnValue != NULL) {
    *length = sizeof(u128);
  } else {
    *length = 0;
  }
  
  printLog(TRACE,
    "EXIT u128FromBlob(value=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    value, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety],
    returnValue);
  return returnValue;
}

/// @var typeU128
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the u128 type.
TypeDescriptor _typeU128 = {
  .name          = "u128",
  .xmlName       = "xs:nonNegativeInteger",
  .dataIsPointer = false,
  .toString      = u128ToString,
  .toBytes       = u128ToBytes,
  .compare       = u128Compare,
  .create        = u128Create,
  .copy          = u128Copy,
  .destroy       = u128Destroy,
  .size          = u128Size,
  .toBlob        = u128ToBlob,
  .fromBlob      = u128FromBlob,
  .hashFunction  = NULL,
  .clear         = clear128,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeU128 = &_typeU128;

/// @var typeU128NoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the u128 type that is not to be copied.
TypeDescriptor _typeU128NoCopy = {
  .name          = "u128",
  .xmlName       = "xs:nonNegativeInteger",
  .dataIsPointer = true,
  .toString      = u128ToString,
  .toBytes       = u128ToBytes,
  .compare       = u128Compare,
  .create        = u128Create,
  .copy          = shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = u128Size,
  .toBlob        = u128ToBlob,
  .fromBlob      = u128FromBlob,
  .hashFunction  = NULL,
  .clear         = clear128,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeU128NoCopy = &_typeU128NoCopy;

/// @fn char *i8ToString(const volatile void *value)
///
/// @brief Convert a i8 value to its string representation.
///
/// @param value A pointer to the i8 value to convert to a string.
///
/// @return Returns a string representation of the value on success,
///   NULL on failure.
char *i8ToString(const volatile void *value) {
  printLog(TRACE, "ENTER i8ToString(value=%d)\n", (value == NULL) ? 0 : *((i8*) value));
  
  char *i8String = NULL;
  if (value == NULL) {
    straddstr(&i8String, "(null)");
    
    printLog(TRACE, "EXIT i8ToString(value=NULL) = {%s}\n", i8String);
    return i8String;
  }
  
  // We need an unsigned value in case the value is the maximum negative value.
  u8 i8Value = *((u8*) value);
  char digit = '\0';
  char sign = '\0';
  // Can't compare our i8Value to < 0 since it's actually an unsigned type.
  if (*((i8*) value) < 0) {
    // We can't use -i8Value here since i8Value is actually unsigned.
    i8Value = ~i8Value + 1;
    sign = '-';
  }
  
  while (i8Value != 0) {
    digit = '0' + (i8Value % 10);
    straddchr(&i8String, digit);
    i8Value /= 10;
  }
  
  straddchr(&i8String, sign);
  
  if (*i8String == '\0') {
    straddchr(&i8String, '0');
  }
  
  reverseString(i8String);
  
  printLog(TRACE, "EXIT i8ToString(value=%d) = {%s}\n", *((i8*) value), i8String);
  return i8String;
}

/// @fn Bytes i8ToBytes(const volatile void *value)
///
/// @brief Convert a i8 value to its Bytes representation.
///
/// @param value A pointer to the i8 value to convert to a Bytes object.
///
/// @return Returns a Bytes representation of the value on success,
///   NULL on failure.
Bytes i8ToBytes(const volatile void *value) {
  printLog(TRACE, "ENTER i8ToBytes(value=%d)\n",
    (value == NULL) ? 0 : *((i8*) value));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT i8ToBytes(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  Bytes i8Bytes = NULL;
  // We need an unsigned value in case the value is the maximum negative value.
  u8 i8Value = *((u8*) value);
  char digit = '\0';
  char sign = '\0';
  // Can't compare our i8Value to < 0 since it's actually an unsigned type.
  if (*((i8*) value) < 0) {
    // We can't use -i8Value here since i8Value is actually unsigned.
    i8Value = ~i8Value + 1;
    sign = '-';
  }
  
  while (i8Value != 0) {
    digit = '0' + (i8Value % 10);
    bytesAddData(&i8Bytes, &digit, sizeof(digit));
    i8Value /= 10;
  }
  
  if (sign != '\0') {
    bytesAddData(&i8Bytes, &sign, sizeof(sign));
  }
  
  if (i8Bytes == NULL) {
    digit = '0';
    bytesAddData(&i8Bytes, &digit, sizeof(digit));
  }
  
  reverseMemory(i8Bytes, bytesLength(i8Bytes));
  
  printLog(TRACE, "EXIT i8ToBytes(value=%d) = {%s}\n",
    *((i8*) value), i8Bytes);
  return i8Bytes;
}

/// @fn int i8Compare(const volatile void *valueA, const volatile void *valueB)
///
/// @brief Compare two i8 values.
///
/// @param valueA, valueB are pointers to the values to compare.
///
/// @return Returns -1 if *valueA < *valueB, 0 if *valueA == *valueB,
///   1 if *valueA > *valueB.
int i8Compare(const volatile void *valueA, const volatile void *valueB) {
  printLog(TRACE, "ENTER i8Compare(valueA=%d, valueB=%d)\n", (valueA == NULL) ? 0 : *((i8*) valueA), (valueB == NULL) ? 0 : *((i8*) valueB));
  
  int returnValue = 0;
  
  if (valueA == NULL) {
    printLog(WARN, "valueA is NULL.\n");
    returnValue--;
  }
  if (valueB == NULL) {
    printLog(WARN, "valueB is NULL.\n");
    returnValue++;
  }
  if ((valueA == NULL) || (valueB == NULL)) {
    printLog(TRACE, "EXIT i8Compare(valueA=%p, valueB=%p) = {%d}\n", valueA,
      valueB, returnValue);
    return returnValue;
  }
  
  i8 i8ValueA = *((i8*) valueA);
  i8 i8ValueB = *((i8*) valueB);
  
  if (i8ValueA < i8ValueB) {
    returnValue = -1;
  } else if (i8ValueA > i8ValueB) {
    returnValue = 1;
  } else { // i8ValueA == i8ValueB
    returnValue = 0;
  }
  
  printLog(TRACE, "EXIT i8Compare(valueA=%d, valueB=%d) = {%d}\n",
    i8ValueA, i8ValueB, returnValue);
  return returnValue;
}

/// @fn void *i8Create(const volatile void *parameter1, ...)
///
/// @brief Allocate memory for a new i8 value and initialize it to 0.
///
/// @param parameter1 Dummy parameter for the sake of conformance to
///   TypeDescriptor definition.  Unused by this function.
///
/// @return Returns a pointer to the newly-initialized value.
void *i8Create(const volatile void *parameter1, ...) {
  printLog(TRACE, "ENTER i8Create()\n");
  
  (void) parameter1; // Keep the compiler from complaining.
  
  i8 *value = (i8*) malloc(sizeof(i8));
  *value = 0;
  
  printLog(TRACE, "EXIT i8Create() = {%d}\n", *((i8*) value));
  return (void*) value;
}

/// @fn void *i8Copy(const volatile void *value)
///
/// @brief Create a new i8 value and assign it the value of the input value.
///
/// @param value Pointer to the value to copy.
///
/// @return A pointer to a new i8 with the specified value.
void *i8Copy(const volatile void *value) {
  printLog(TRACE, "ENTER i8Copy(value=%d)\n", (value == NULL) ? 0 : *((i8*) value));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT i8Copy(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  i8 *valueCopy = (i8*) malloc(sizeof(i8));
  if (valueCopy != NULL) {
    *valueCopy = *((i8*) value);
  }
  
  printLog(TRACE, "EXIT i8Copy(value=%d) = {%p}\n", *((i8*) value), valueCopy);
  return valueCopy;
}

/// @fn void *i8Destroy(volatile void *value)
///
/// @brief Release the memory associated with a i8 value.
///
/// @param value A pointer to the memory to be released.
///
/// @return Returns a null pointer on success, the input pointer on failure.
///   NOTE: Use of the pointer returned by this function will result in
///   undefined behavior.
void *i8Destroy(volatile void *value) {
  printLog(TRACE, "ENTER i8Destroy(value=%d)\n", (value == NULL) ? 0 : *((i8*) value));
  
  value = pointerDestroy(value);
  
  printLog(TRACE, "EXIT i8Destroy(value=%p) = {%p}\n", value, value);
  return (void*) value;
}

/// @fn size_t i8Size(const volatile void *value)
///
/// @brief Return the size of a i8 type.
///
/// @param value A pointer to a i8 variable.
///
/// @return Return the size of a i8 type.
size_t i8Size(const volatile void *value) {
  size_t size = 0;
  printLog(TRACE, "ENTER i8Size(value=%p)\n", value);
  
  if (value != NULL) {
    size = sizeof(i8);
  }
  
  printLog(TRACE, "EXIT i8Size(value=%p) = {%llu}\n", value, llu(size));
  return size;
}

/// @fn Bytes i8ToBlob(const volatile void *value)
///
/// @brief Convert a i8 value to an array of bytes.
///
/// @param value A pointer to the i8 value to convert.
///
/// @return Returns a Bytes object with the encoded byte array on success,
/// NULL on failure.
Bytes i8ToBlob(const volatile void *value) {
  Bytes returnValue = NULL;
  printLog(TRACE, "ENTER i8ToBlob(value=%u)\n",
    (value == NULL) ? 0 : *((i8*) value));
  
  if (value == NULL) {
    printLog(ERR, "Cannot convert to byte array.  Parameter is NULL.\n");
    printLog(TRACE, "EXIT i8ToBlob(value=%u) = {%p}\n",
      (value == NULL) ? 0 : *((i8*) value), returnValue);
    return returnValue;
  }
  
  bytesAddData(&returnValue, value, sizeof(i8));
  // Set the size to match the length.  This is so data structures that are
  // building byte arrays encode the right amount of data, which does not
  // include the string terminator in our case.
  bytesSetSize(returnValue, bytesLength(returnValue));
  
  printLog(TRACE, "EXIT i8ToBlob(value=%u) = {%p}\n",
    (value == NULL) ? 0 : *((i8*) value), returnValue);
  return returnValue;
}

/// @fn void* i8FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety)
///
/// @brief Convert a i8 value to an array of bytes.
///
/// @param value A pointer to the i8 value to convert.
/// @param length The length of the resulting byte array.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned data.  Not used by this function.
///
/// @return Returns a pointer to a valid byte array on success, NULL on failure.
void* i8FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety) {
  (void) disableThreadSafety;
  void *returnValue = NULL;
  printLog(TRACE,
    "ENTER i8FromBlob(value=%d, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    (value == NULL) ? 0 : *((i8*) value), length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  
  if ((value == NULL) || (length == NULL)) {
    printLog(ERR, "Cannot convert to/from byte array.  Parameter is NULL.\n");
    printLog(TRACE,
      "EXIT i8FromBlob(value=%d, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      (value == NULL) ? 0 : *((i8*) value), length, boolNames[inPlaceData], boolNames[disableThreadSafety],
      returnValue);
    return returnValue; // NULL
  } else if (*length < sizeof(i8)) {
    printLog(ERR, "Cannot convert from byte array.  Insufficient data.\n");
    printLog(ERR, "Needed at least %llu bytes, only have %llu.\n",
      llu(sizeof(i8)), llu(*length));
    printLog(TRACE,
      "EXIT i8FromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return returnValue; // NULL
  }
  
  if (inPlaceData) {
    // Optimize for this case.
    returnValue = (void*) value;
  } else {
    returnValue = i8Copy(value);
  }
  littleEndianToHost(returnValue, sizeof(i8));
  if (returnValue != NULL) {
    *length = sizeof(i8);
  } else {
    *length = 0;
  }
  
  printLog(TRACE,
    "EXIT i8FromBlob(value=%d, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    (value == NULL) ? 0 : *((i8*) value), llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety],
    returnValue);
  return returnValue;
}

/// @var typeI8
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the i8 type.
TypeDescriptor _typeI8 = {
  .name          = "i8",
  .xmlName       = "xs:byte",
  .dataIsPointer = false,
  .toString      = i8ToString,
  .toBytes       = i8ToBytes,
  .compare       = i8Compare,
  .create        = i8Create,
  .copy          = i8Copy,
  .destroy       = i8Destroy,
  .size          = i8Size,
  .toBlob        = i8ToBlob,
  .fromBlob      = i8FromBlob,
  .hashFunction  = NULL,
  .clear         = clear8,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeI8 = &_typeI8;

/// @var typeI8NoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the i8 type that is not to be copied.
TypeDescriptor _typeI8NoCopy = {
  .name          = "i8",
  .xmlName       = "xs:byte",
  .dataIsPointer = true,
  .toString      = i8ToString,
  .toBytes       = i8ToBytes,
  .compare       = i8Compare,
  .create        = i8Create,
  .copy          = shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = i8Size,
  .toBlob        = i8ToBlob,
  .fromBlob      = i8FromBlob,
  .hashFunction  = NULL,
  .clear         = clear8,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeI8NoCopy = &_typeI8NoCopy;

/// @fn char *i16ToString(const volatile void *value)
///
/// @brief Convert a i16 value to its string representation.
///
/// @param value A pointer to the i16 value to convert to a string.
///
/// @return Returns a string representation of the value on success,
///   NULL on failure.
char *i16ToString(const volatile void *value) {
  printLog(TRACE, "ENTER i16ToString(value=%d)\n", (value == NULL) ? 0 : *((i16*) value));
  
  char *i16String = NULL;
  if (value == NULL) {
    straddstr(&i16String, "(null)");
    
    printLog(TRACE, "EXIT i16ToString(value=NULL) = {%s}\n", i16String);
    return i16String;
  }
  
  // We need an unsigned value in case the value is the maximum negative value.
  u16 i16Value = *((u16*) value);
  char digit = '\0';
  char sign = '\0';
  // Can't compare our i16Value to < 0 since it's actually an unsigned type.
  if (*((i16*) value) < 0) {
    // We can't use -i16Value here since i16Value is actually unsigned.
    i16Value = ~i16Value + 1;
    sign = '-';
  }
  
  while (i16Value != 0) {
    digit = '0' + (i16Value % 10);
    straddchr(&i16String, digit);
    i16Value /= 10;
  }
  
  straddchr(&i16String, sign);
  
  if (*i16String == '\0') {
    straddchr(&i16String, '0');
  }
  
  reverseString(i16String);
  
  printLog(TRACE, "EXIT i16ToString(value=%d) = {%s}\n", *((i16*) value), i16String);
  return i16String;
}

/// @fn Bytes i16ToBytes(const volatile void *value)
///
/// @brief Convert a i16 value to its Bytes representation.
///
/// @param value A pointer to the i16 value to convert to a Bytes object.
///
/// @return Returns a Bytes representation of the value on success,
///   NULL on failure.
Bytes i16ToBytes(const volatile void *value) {
  printLog(TRACE, "ENTER i16ToBytes(value=%d)\n",
    (value == NULL) ? 0 : *((i16*) value));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT i16ToBytes(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  Bytes i16Bytes = NULL;
  // We need an unsigned value in case the value is the maximum negative value.
  u16 i16Value = *((u16*) value);
  char digit = '\0';
  char sign = '\0';
  // Can't compare our i16Value to < 0 since it's actually an unsigned type.
  if (*((i16*) value) < 0) {
    // We can't use -i16Value here since i16Value is actually unsigned.
    i16Value = ~i16Value + 1;
    sign = '-';
  }
  
  while (i16Value != 0) {
    digit = '0' + (i16Value % 10);
    bytesAddData(&i16Bytes, &digit, sizeof(digit));
    i16Value /= 10;
  }
  
  if (sign != '\0') {
    bytesAddData(&i16Bytes, &sign, sizeof(sign));
  }
  
  if (i16Bytes == NULL) {
    digit = '0';
    bytesAddData(&i16Bytes, &digit, sizeof(digit));
  }
  
  reverseMemory(i16Bytes, bytesLength(i16Bytes));
  
  printLog(TRACE, "EXIT i16ToBytes(value=%d) = {%s}\n",
    *((i16*) value), i16Bytes);
  return i16Bytes;
}

/// @fn int i16Compare(const volatile void *valueA, const volatile void *valueB)
///
/// @brief Compare two i16 values.
///
/// @param valueA, valueB are pointers to the values to compare.
///
/// @return Returns -1 if *valueA < *valueB, 0 if *valueA == *valueB,
///   1 if *valueA > *valueB.
int i16Compare(const volatile void *valueA, const volatile void *valueB) {
  printLog(TRACE, "ENTER i16Compare(valueA=%d, valueB=%d)\n", (valueA == NULL) ? 0 : *((i16*) valueA), (valueB == NULL) ? 0 : *((i16*) valueB));
  
  int returnValue = 0;
  if (valueA == NULL) {
    printLog(WARN, "valueA is NULL.\n");
    returnValue--;
  }
  if (valueB == NULL) {
    printLog(WARN, "valueB is NULL.\n");
    returnValue++;
  }
  if ((valueA == NULL) || (valueB == NULL)) {
    printLog(TRACE, "EXIT i16Compare(valueA=%p, valueB=%p) = {%d}\n", valueA,
      valueB, returnValue);
    return returnValue;
  }
  
  i16 i16ValueA = *((i16*) valueA);
  i16 i16ValueB = *((i16*) valueB);
  
  if (i16ValueA < i16ValueB) {
    returnValue = -1;
  } else if (i16ValueA > i16ValueB) {
    returnValue = 1;
  } else { // i16ValueA == i16ValueB
    returnValue = 0;
  }
  
  printLog(TRACE, "EXIT i16Compare(valueA=%d, valueB=%d) = {%d}\n",
    i16ValueA, i16ValueB, returnValue);
  return returnValue;
}

/// @fn void *i16Create(const volatile void *parameter1, ...)
///
/// @brief Allocate memory for a new i16 value and initialize it to 0.
///
/// @param parameter1 Dummy parameter for the sake of conformance to
///   TypeDescriptor definition.  Unused by this function.
///
/// @return Returns a pointer to the newly-initialized value.
void *i16Create(const volatile void *parameter1, ...) {
  printLog(TRACE, "ENTER i16Create()\n");
  
  (void) parameter1; // Keep the compiler from complaining.
  
  i16 *value = (i16*) malloc(sizeof(i16));
  *value = 0;
  
  printLog(TRACE, "EXIT i16Create() = {%d}\n", *((i16*) value));
  return (void*) value;
}

/// @fn void *i16Copy(const volatile void *value)
///
/// @brief Create a new i16 value and assign it the value of the input value.
///
/// @param value Pointer to the value to copy.
///
/// @return A pointer to a new i16 with the specified value.
void *i16Copy(const volatile void *value) {
  printLog(TRACE, "ENTER i16Copy(value=%d)\n", (value == NULL) ? 0 : *((i16*) value));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT i16Copy(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  i16 *valueCopy = (i16*) malloc(sizeof(i16));
  if (valueCopy != NULL) {
    *valueCopy = *((i16*) value);
  }
  
  printLog(TRACE, "EXIT i16Copy(value=%d) = {%p}\n", *((i16*) value), valueCopy);
  return valueCopy;
}

/// @fn void *i16Destroy(volatile void *value)
///
/// @brief Release the memory associated with a i16 value.
///
/// @param value A pointer to the memory to be released.
///
/// @return Returns a null pointer on success, the input pointer on failure.
///   NOTE: Use of the pointer returned by this function will result in
///   undefined behavior.
void *i16Destroy(volatile void *value) {
  printLog(TRACE, "ENTER i16Destroy(value=%d)\n", (value == NULL) ? 0 : *((i16*) value));
  
  value = pointerDestroy(value);
  
  printLog(TRACE, "EXIT i16Destroy(value=%p) = {%p}\n", value, value);
  return (void*) value;
}

/// @fn size_t i16Size(const volatile void *value)
///
/// @brief Return the size of a i16 type.
///
/// @param value A pointer to a i16 variable.
///
/// @return Return the size of a i16 type.
size_t i16Size(const volatile void *value) {
  size_t size = 0;
  printLog(TRACE, "ENTER i16Size(value=%p)\n", value);
  
  if (value != NULL) {
    size = sizeof(i16);
  }
  
  printLog(TRACE, "EXIT i16Size(value=%p) = {%llu}\n", value, llu(size));
  return size;
}

/// @fn Bytes i16ToBlob(const volatile void *value)
///
/// @brief Convert a i16 value to an array of bytes.
///
/// @param value A pointer to the i16 value to convert.
///
/// @return Returns a Bytes object with the encoded byte array on success,
/// NULL on failure.
Bytes i16ToBlob(const volatile void *value) {
  Bytes returnValue = NULL;
  printLog(TRACE, "ENTER i16ToBlob(value=%u)\n",
    (value == NULL) ? 0 : *((i16*) value));
  
  if (value == NULL) {
    printLog(ERR, "Cannot convert to byte array.  Parameter is NULL.\n");
    printLog(TRACE, "EXIT i16ToBlob(value=%u) = {%p}\n",
      (value == NULL) ? 0 : *((i16*) value), returnValue);
    return returnValue;
  }
  
  bytesAddData(&returnValue, value, sizeof(i16));
  hostToLittleEndian(returnValue, sizeof(i16));
  // Set the size to match the length.  This is so data structures that are
  // building byte arrays encode the right amount of data, which does not
  // include the string terminator in our case.
  bytesSetSize(returnValue, bytesLength(returnValue));
  
  printLog(TRACE, "EXIT i16ToBlob(value=%u) = {%p}\n",
    (value == NULL) ? 0 : *((i16*) value), returnValue);
  return returnValue;
}

/// @fn void* i16FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety)
///
/// @brief Convert a i16 value to an array of bytes.
///
/// @param value A pointer to the i16 value to convert.
/// @param length The length of the resulting byte array.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned data.  Not used by this function.
///
/// @return Returns a pointer to a valid byte array on success, NULL on failure.
void* i16FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety) {
  (void) disableThreadSafety;
  void *returnValue = NULL;
  printLog(TRACE,
    "ENTER i16FromBlob(value=%d, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    (value == NULL) ? 0 : *((i16*) value), length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  
  if ((value == NULL) || (length == NULL)) {
    printLog(ERR, "Cannot convert to/from byte array.  Parameter is NULL.\n");
    printLog(TRACE,
      "EXIT i16FromBlob(value=%d, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      (value == NULL) ? 0 : *((i16*) value), length, boolNames[inPlaceData], boolNames[disableThreadSafety],
      returnValue);
    return returnValue; // NULL
  } else if (*length < sizeof(i16)) {
    printLog(ERR, "Cannot convert from byte array.  Insufficient data.\n");
    printLog(ERR, "Needed at least %llu bytes, only have %llu.\n",
      llu(sizeof(i16)), llu(*length));
    printLog(TRACE,
      "EXIT i16FromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return returnValue; // NULL
  }
  
  if (inPlaceData) {
    // Optimize for this case.
    returnValue = (void*) value;
  } else {
    returnValue = i16Copy(value);
  }
  littleEndianToHost(returnValue, sizeof(i16));
  if (returnValue != NULL) {
    *length = sizeof(i16);
  } else {
    *length = 0;
  }
  
  printLog(TRACE,
    "EXIT i16FromBlob(value=%d, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    (value == NULL) ? 0 : *((i16*) value), llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety],
    returnValue);
  return returnValue;
}

/// @var typeI16
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the i16 type.
TypeDescriptor _typeI16 = {
  .name          = "i16",
  .xmlName       = "xs:short",
  .dataIsPointer = false,
  .toString      = i16ToString,
  .toBytes       = i16ToBytes,
  .compare       = i16Compare,
  .create        = i16Create,
  .copy          = i16Copy,
  .destroy       = i16Destroy,
  .size          = i16Size,
  .toBlob        = i16ToBlob,
  .fromBlob      = i16FromBlob,
  .hashFunction  = NULL,
  .clear         = clear16,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeI16 = &_typeI16;

/// @var typeI16NoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the i16 type that is not to be copied.
TypeDescriptor _typeI16NoCopy = {
  .name          = "i16",
  .xmlName       = "xs:short",
  .dataIsPointer = true,
  .toString      = i16ToString,
  .toBytes       = i16ToBytes,
  .compare       = i16Compare,
  .create        = i16Create,
  .copy          = shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = i16Size,
  .toBlob        = i16ToBlob,
  .fromBlob      = i16FromBlob,
  .hashFunction  = NULL,
  .clear         = clear16,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeI16NoCopy = &_typeI16NoCopy;

/// @fn char *i32ToString(const volatile void *value)
///
/// @brief Convert a i32 value to its string representation.
///
/// @param value A pointer to the i32 value to convert to a string.
///
/// @return Returns a string representation of the value on success,
///   NULL on failure.
char *i32ToString(const volatile void *value) {
  printLog(TRACE, "ENTER i32ToString(value=%d)\n", (value == NULL) ? 0 : *((i32*) value));
  
  char *i32String = NULL;
  if (value == NULL) {
    straddstr(&i32String, "(null)");
    
    printLog(TRACE, "EXIT i32ToString(value=NULL) = {%s}\n", i32String);
    return i32String;
  }
  
  // We need an unsigned value in case the value is the maximum negative value.
  u32 i32Value = *((u32*) value);
  char digit = '\0';
  char sign = '\0';
  // Can't compare our i32Value to < 0 since it's actually an unsigned type.
  if (*((i32*) value) < 0) {
    // We can't use -i32Value here since i32Value is actually unsigned.
    i32Value = ~i32Value + 1;
    sign = '-';
  }
  
  while (i32Value != 0) {
    digit = '0' + (i32Value % 10);
    straddchr(&i32String, digit);
    i32Value /= 10;
  }
  
  straddchr(&i32String, sign);
  
  if (*i32String == '\0') {
    straddchr(&i32String, '0');
  }
  
  reverseString(i32String);
  
  printLog(TRACE, "EXIT i32ToString(value=%d) = {%s}\n", *((i32*) value), i32String);
  return i32String;
}

/// @fn Bytes i32ToBytes(const volatile void *value)
///
/// @brief Convert a i32 value to its Bytes representation.
///
/// @param value A pointer to the i32 value to convert to a Bytes object.
///
/// @return Returns a Bytes representation of the value on success,
///   NULL on failure.
Bytes i32ToBytes(const volatile void *value) {
  printLog(TRACE, "ENTER i32ToBytes(value=%d)\n",
    (value == NULL) ? 0 : *((i32*) value));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT i32ToBytes(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  Bytes i32Bytes = NULL;
  // We need an unsigned value in case the value is the maximum negative value.
  u32 i32Value = *((u32*) value);
  char digit = '\0';
  char sign = '\0';
  // Can't compare our i32Value to < 0 since it's actually an unsigned type.
  if (*((i32*) value) < 0) {
    // We can't use -i32Value here since i32Value is actually unsigned.
    i32Value = ~i32Value + 1;
    sign = '-';
  }
  
  while (i32Value != 0) {
    digit = '0' + (i32Value % 10);
    bytesAddData(&i32Bytes, &digit, sizeof(digit));
    i32Value /= 10;
  }
  
  if (sign != '\0') {
    bytesAddData(&i32Bytes, &sign, sizeof(sign));
  }
  
  if (i32Bytes == NULL) {
    digit = '0';
    bytesAddData(&i32Bytes, &digit, sizeof(digit));
  }
  
  reverseMemory(i32Bytes, bytesLength(i32Bytes));
  
  printLog(TRACE, "EXIT i32ToBytes(value=%d) = {%s}\n",
    *((i32*) value), i32Bytes);
  return i32Bytes;
}

/// @fn int i32Compare(const volatile void *valueA, const volatile void *valueB)
///
/// @brief Compare two i32 values.
///
/// @param valueA, valueB are pointers to the values to compare.
///
/// @return Returns -1 if *valueA < *valueB, 0 if *valueA == *valueB,
///   1 if *valueA > *valueB.
int i32Compare(const volatile void *valueA, const volatile void *valueB) {
  printLog(TRACE, "ENTER i32Compare(valueA=%d, valueB=%d)\n", (valueA == NULL) ? 0 : *((i32*) valueA), (valueB == NULL) ? 0 : *((i32*) valueB));
  
  int returnValue = 0;
  
  if (valueA == NULL) {
    printLog(WARN, "valueA is NULL.\n");
    returnValue--;
  }
  if (valueB == NULL) {
    printLog(WARN, "valueB is NULL.\n");
    returnValue++;
  }
  if ((valueA == NULL) || (valueB == NULL)) {
    printLog(TRACE, "EXIT i32Compare(valueA=%p, valueB=%p) = {%d}\n", valueA,
      valueB, returnValue);
    return returnValue;
  }
  
  i32 i32ValueA = *((i32*) valueA);
  i32 i32ValueB = *((i32*) valueB);
  
  if (i32ValueA < i32ValueB) {
    returnValue = -1;
  } else if (i32ValueA > i32ValueB) {
    returnValue = 1;
  } else { // i32ValueA == i32ValueB
    returnValue = 0;
  }
  
  printLog(TRACE, "EXIT i32Compare(valueA=%d, valueB=%d) = {%d}\n",
    i32ValueA, i32ValueB, returnValue);
  return returnValue;
}

/// @fn void *i32Create(const volatile void *parameter1, ...)
///
/// @brief Allocate memory for a new i32 value and initialize it to 0.
///
/// @param parameter1 Dummy parameter for the sake of conformance to
///   TypeDescriptor definition.  Unused by this function.
///
/// @return Returns a pointer to the newly-initialized value.
void *i32Create(const volatile void *parameter1, ...) {
  printLog(TRACE, "ENTER i32Create()\n");
  
  (void) parameter1; // Keep the compiler from complaining.
  
  i32 *value = (i32*) malloc(sizeof(i32));
  *value = 0;
  
  printLog(TRACE, "EXIT i32Create()= {%d}\n", *((i32*) value));
  return (void*) value;
}

/// @fn void *i32Copy(const volatile void *value)
///
/// @brief Create a new i32 value and assign it the value of the input value.
///
/// @param value Pointer to the value to copy.
///
/// @return A pointer to a new i32 with the specified value.
void *i32Copy(const volatile void *value) {
  printLog(TRACE, "ENTER i32Copy(value=%d)\n", (value == NULL) ? 0 : *((i32*) value));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT i32Copy(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  i32 *valueCopy = (i32*) malloc(sizeof(i32));
  if (valueCopy != NULL) {
    *valueCopy = *((i32*) value);
  }
  
  printLog(TRACE, "EXIT i32Copy(value=%d) = {%p}\n", *((i32*) value), valueCopy);
  return valueCopy;
}

/// @fn void *i32Destroy(volatile void *value)
///
/// @brief Release the memory associated with a i32 value.
///
/// @param value A pointer to the memory to be released.
///
/// @return Returns a null pointer on success, the input pointer on failure.
///   NOTE: Use of the pointer returned by this function will result in
///   undefined behavior.
void *i32Destroy(volatile void *value) {
  printLog(TRACE, "ENTER i32Destroy(value=%d)\n", (value == NULL) ? 0 : *((i32*) value));
  
  value = pointerDestroy(value);
  
  printLog(TRACE, "EXIT i32Destroy(value=%p) = {%p}\n", value, value);
  return (void*) value;
}

/// @fn size_t i32Size(const volatile void *value)
///
/// @brief Return the size of a i32 type.
///
/// @param value A pointer to a i32 variable.
///
/// @return Return the size of a i32 type.
size_t i32Size(const volatile void *value) {
  size_t size = 0;
  printLog(TRACE, "ENTER i32Size(value=%p)\n", value);
  
  if (value != NULL) {
    size = sizeof(i32);
  }
  
  printLog(TRACE, "EXIT i32Size(value=%p) = {%llu}\n", value, llu(size));
  return size;
}

/// @fn Bytes i32ToBlob(const volatile void *value)
///
/// @brief Convert a i32 value to an array of bytes.
///
/// @param value A pointer to the i32 value to convert.
///
/// @return Returns a Bytes object with the encoded byte array on success,
/// NULL on failure.
Bytes i32ToBlob(const volatile void *value) {
  Bytes returnValue = NULL;
  printLog(TRACE, "ENTER i32ToBlob(value=%u)\n",
    (value == NULL) ? 0 : *((i32*) value));
  
  if (value == NULL) {
    printLog(ERR, "Cannot convert to byte array.  Parameter is NULL.\n");
    printLog(TRACE, "EXIT i32ToBlob(value=%u) = {%p}\n",
      (value == NULL) ? 0 : *((i32*) value), returnValue);
    return returnValue;
  }
  
  bytesAddData(&returnValue, value, sizeof(i32));
  hostToLittleEndian(returnValue, sizeof(i32));
  // Set the size to match the length.  This is so data structures that are
  // building byte arrays encode the right amount of data, which does not
  // include the string terminator in our case.
  bytesSetSize(returnValue, bytesLength(returnValue));
  
  printLog(TRACE, "EXIT i32ToBlob(value=%u) = {%p}\n",
    (value == NULL) ? 0 : *((i32*) value), returnValue);
  return returnValue;
}

/// @fn void* i32FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety)
///
/// @brief Convert a i32 value to an array of bytes.
///
/// @param value A pointer to the i32 value to convert.
/// @param length The length of the resulting byte array.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned data.  Not used by this function.
///
/// @return Returns a pointer to a valid byte array on success, NULL on failure.
void* i32FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety) {
  (void) disableThreadSafety;
  void *returnValue = NULL;
  printLog(TRACE,
    "ENTER i32FromBlob(value=%d, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    (value == NULL) ? 0 : *((i32*) value), length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  
  if ((value == NULL) || (length == NULL)) {
    printLog(ERR, "Cannot convert to/from byte array.  Parameter is NULL.\n");
    printLog(TRACE,
      "EXIT i32FromBlob(value=%d, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      (value == NULL) ? 0 : *((i32*) value), length, boolNames[inPlaceData], boolNames[disableThreadSafety],
      returnValue);
    return returnValue; // NULL
  } else if (*length < sizeof(i32)) {
    printLog(ERR, "Cannot convert from byte array.  Insufficient data.\n");
    printLog(ERR, "Needed at least %llu bytes, only have %llu.\n",
      llu(sizeof(i32)), llu(*length));
    printLog(TRACE,
      "EXIT i32FromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return returnValue; // NULL
  }
  
  if (inPlaceData) {
    // Optimize for this case.
    returnValue = (void*) value;
  } else {
    returnValue = i32Copy(value);
  }
  littleEndianToHost(returnValue, sizeof(i32));
  if (returnValue != NULL) {
    *length = sizeof(i32);
  } else {
    *length = 0;
  }
  
  printLog(TRACE,
    "EXIT i32FromBlob(value=%d, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    (value == NULL) ? 0 : *((i32*) value), llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety],
    returnValue);
  return returnValue;
}

/// @var typeI32
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the i32 type.
TypeDescriptor _typeI32 = {
  .name          = "i32",
  .xmlName       = "xs:int",
  .dataIsPointer = false,
  .toString      = i32ToString,
  .toBytes       = i32ToBytes,
  .compare       = i32Compare,
  .create        = i32Create,
  .copy          = i32Copy,
  .destroy       = i32Destroy,
  .size          = i32Size,
  .toBlob        = i32ToBlob,
  .fromBlob      = i32FromBlob,
  .hashFunction  = NULL,
  .clear         = clear32,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeI32 = &_typeI32;

/// @var typeI32NoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the i32 type that is not to be copied.
TypeDescriptor _typeI32NoCopy = {
  .name          = "i32",
  .xmlName       = "xs:int",
  .dataIsPointer = true,
  .toString      = i32ToString,
  .toBytes       = i32ToBytes,
  .compare       = i32Compare,
  .create        = i32Create,
  .copy          = shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = i32Size,
  .toBlob        = i32ToBlob,
  .fromBlob      = i32FromBlob,
  .hashFunction  = NULL,
  .clear         = clear32,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeI32NoCopy = &_typeI32NoCopy;

/// @fn char *i64ToString(const volatile void *value)
///
/// @brief Convert a i64 value to its string representation.
///
/// @param value A pointer to the i64 value to convert to a string.
///
/// @return Returns a string representation of the value on success,
///   NULL on failure.
char *i64ToString(const volatile void *value) {
  printLog(TRACE, "ENTER i64ToString(value=%lld)\n", (value == NULL) ? 0 : lli(*((i64*) value)));
  
  char *i64String = NULL;
  if (value == NULL) {
    straddstr(&i64String, "(null)");
    
    printLog(TRACE, "EXIT i64ToString(value=NULL) = {%s}\n", i64String);
    return i64String;
  }
  
  // We need an unsigned value in case the value is the maximum negative value.
  u64 i64Value = *((u64*) value);
  char digit = '\0';
  char sign = '\0';
  // Can't compare our i64Value to < 0 since it's actually an unsigned type.
  if (*((i64*) value) < 0) {
    // We can't use -i64Value here since i64Value is actually unsigned.
    i64Value = ~i64Value + 1;
    sign = '-';
  }
  
  while (i64Value != 0) {
    digit = '0' + (i64Value % 10);
    straddchr(&i64String, digit);
    i64Value /= 10;
  }
  
  straddchr(&i64String, sign);
  
  if (*i64String == '\0') {
    straddchr(&i64String, '0');
  }
  
  reverseString(i64String);
  
  printLog(TRACE, "EXIT i64ToString(value=%lld) = {%s}\n", lli(*((i64*) value)), i64String);
  return i64String;
}

/// @fn Bytes i64ToBytes(const volatile void *value)
///
/// @brief Convert a i64 value to its Bytes representation.
///
/// @param value A pointer to the i64 value to convert to a Bytes object.
///
/// @return Returns a Bytes representation of the value on success,
///   NULL on failure.
Bytes i64ToBytes(const volatile void *value) {
  printLog(TRACE, "ENTER i64ToBytes(value=%lld)\n",
    (value == NULL) ? 0 : lli(*((i64*) value)));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT i64ToBytes(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  Bytes i64Bytes = NULL;
  // We need an unsigned value in case the value is the maximum negative value.
  u64 i64Value = *((u64*) value);
  char digit = '\0';
  char sign = '\0';
  // Can't compare our i64Value to < 0 since it's actually an unsigned type.
  if (*((i64*) value) < 0) {
    // We can't use -i64Value here since i64Value is actually unsigned.
    i64Value = ~i64Value + 1;
    sign = '-';
  }
  
  while (i64Value != 0) {
    digit = '0' + (i64Value % 10);
    bytesAddData(&i64Bytes, &digit, sizeof(digit));
    i64Value /= 10;
  }
  
  if (sign != '\0') {
    bytesAddData(&i64Bytes, &sign, sizeof(sign));
  }
  
  if (i64Bytes == NULL) {
    digit = '0';
    bytesAddData(&i64Bytes, &digit, sizeof(digit));
  }
  
  reverseMemory(i64Bytes, bytesLength(i64Bytes));
  
  printLog(TRACE, "EXIT i64ToBytes(value=%lld) = {%s}\n",
    lli(*((i64*) value)), i64Bytes);
  return i64Bytes;
}

/// @fn int i64Compare(const volatile void *valueA, const volatile void *valueB)
///
/// @brief Compare two i64 values.
///
/// @param valueA, valueB are pointers to the values to compare.
///
/// @return Returns -1 if *valueA < *valueB, 0 if *valueA == *valueB,
///   1 if *valueA > *valueB.
int i64Compare(const volatile void *valueA, const volatile void *valueB) {
  printLog(TRACE, "ENTER i64Compare(valueA=%lld, valueB=%lld)\n", (valueA == NULL) ? 0 : lli(*((i64*) valueA)), (valueB == NULL) ? 0 : lli(*((i64*) valueB)));
  
  int returnValue = 0;
  if (valueA == NULL) {
    printLog(WARN, "valueA is NULL.\n");
    returnValue--;
  }
  if (valueB == NULL) {
    printLog(WARN, "valueB is NULL.\n");
    returnValue++;
  }
  if ((valueA == NULL) || (valueB == NULL)) {
    printLog(TRACE, "EXIT i64Compare(valueA=%p, valueB=%p) = {%d}\n", valueA,
      valueB, returnValue);
    return returnValue;
  }
  
  i64 i64ValueA = *((i64*) valueA);
  i64 i64ValueB = *((i64*) valueB);
  
  if (i64ValueA < i64ValueB) {
    returnValue = -1;
  } else if (i64ValueA > i64ValueB) {
    returnValue = 1;
  } else { // i64ValueA == i64ValueB
    returnValue = 0;
  }
  
  printLog(TRACE, "EXIT i64Compare(valueA=%lld, valueB=%lld) = {%d}\n",
    lli(i64ValueA), lli(i64ValueB), returnValue);
  return returnValue;
}

/// @fn void *i64Create(const volatile void *parameter1, ...)
///
/// @brief Allocate memory for a new i64 value and initialize it to 0.
///
/// @param parameter1 Dummy parameter for the sake of conformance to
///   TypeDescriptor definition.  Unused by this function.
///
/// @return Returns a pointer to the newly-initialized value.
void *i64Create(const volatile void *parameter1, ...) {
  printLog(TRACE, "ENTER i64Create()\n");
  
  (void) parameter1; // Keep the compiler from complaining.
  
  i64 *value = (i64*) malloc(sizeof(i64));
  *value = 0;
  
  printLog(TRACE, "EXIT i64Create() = {%lld}\n", lli(*((i64*) value)));
  return (void*) value;
}

/// @fn void *i64Copy(const volatile void *value)
///
/// @brief Create a new i64 value and assign it the value of the input value.
///
/// @param value Pointer to the value to copy.
///
/// @return A pointer to a new i64 with the specified value.
void *i64Copy(const volatile void *value) {
  printLog(TRACE, "ENTER i64Copy(value=%lld)\n", (value == NULL) ? 0 : lli(*((i64*) value)));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT i64Copy(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  i64 *valueCopy = (i64*) malloc(sizeof(i64));
  if (valueCopy != NULL) {
    *valueCopy = *((i64*) value);
  }
  
  printLog(TRACE, "EXIT i64Copy(value=%lld) = {%p}\n", lli(*((i64*) value)), valueCopy);
  return valueCopy;
}

/// @fn void *i64Destroy(volatile void *value)
///
/// @brief Release the memory associated with a i64 value.
///
/// @param value A pointer to the memory to be released.
///
/// @return Returns a null pointer on success, the input pointer on failure.
///   NOTE: Use of the pointer returned by this function will result in
///   undefined behavior.
void *i64Destroy(volatile void *value) {
  printLog(TRACE, "ENTER i64Destroy(value=%lld)\n", (value == NULL) ? 0 : lli(*((i64*) value)));
  
  value = pointerDestroy(value);
  
  printLog(TRACE, "EXIT i64Destroy(value=%p) = {%p}\n", value, value);
  return (void*) value;
}

/// @fn size_t i64Size(const volatile void *value)
///
/// @brief Return the size of a i64 type.
///
/// @param value A pointer to a i64 variable.
///
/// @return Return the size of a i64 type.
size_t i64Size(const volatile void *value) {
  size_t size = 0;
  printLog(TRACE, "ENTER i64Size(value=%p)\n", value);
  
  if (value != NULL) {
    size = sizeof(i64);
  }
  
  printLog(TRACE, "EXIT i64Size(value=%p) = {%llu}\n", value, llu(size));
  return size;
}

/// @fn Bytes i64ToBlob(const volatile void *value)
///
/// @brief Convert a i64 value to an array of bytes.
///
/// @param value A pointer to the i64 value to convert.
///
/// @return Returns a Bytes object with the encoded byte array on success,
/// NULL on failure.
Bytes i64ToBlob(const volatile void *value) {
  Bytes returnValue = NULL;
  printLog(TRACE, "ENTER i64ToBlob(value=%lld)\n",
    (value == NULL) ? 0 : lld(*((i64*) value)));
  
  if (value == NULL) {
    printLog(ERR, "Cannot convert to byte array.  Parameter is NULL.\n");
    printLog(TRACE, "EXIT i64ToBlob(value=%lld) = {%p}\n",
      (value == NULL) ? 0 : lld(*((i64*) value)), returnValue);
    return returnValue;
  }
  
  bytesAddData(&returnValue, value, sizeof(i64));
  hostToLittleEndian(returnValue, sizeof(i64));
  // Set the size to match the length.  This is so data structures that are
  // building byte arrays encode the right amount of data, which does not
  // include the string terminator in our case.
  bytesSetSize(returnValue, bytesLength(returnValue));
  
  printLog(TRACE, "EXIT i64ToBlob(value=%lld) = {%p}\n",
    (value == NULL) ? 0 : lld(*((i64*) value)), returnValue);
  return returnValue;
}

/// @fn void* i64FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety)
///
/// @brief Convert a i64 value to an array of bytes.
///
/// @param value A pointer to the i64 value to convert.
/// @param length The length of the resulting byte array.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned data.  Not used by this function.
///
/// @return Returns a pointer to a valid byte array on success, NULL on failure.
void* i64FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety) {
  (void) disableThreadSafety;
  void *returnValue = NULL;
  printLog(TRACE,
    "ENTER i64FromBlob(value=%lld, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    (value == NULL) ? 0 : lld(*((i64*) value)), length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  
  if ((value == NULL) || (length == NULL)) {
    printLog(ERR, "Cannot convert to/from byte array.  Parameter is NULL.\n");
    printLog(TRACE,
      "EXIT i64FromBlob(value=%lld, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      (value == NULL) ? 0 : lld(*((i64*) value)), length, boolNames[inPlaceData], boolNames[disableThreadSafety],
      returnValue);
    return returnValue; // NULL
  } else if (*length < sizeof(i64)) {
    printLog(ERR, "Cannot convert from byte array.  Insufficient data.\n");
    printLog(ERR, "Needed at least %llu bytes, only have %llu.\n",
      llu(sizeof(i64)), llu(*length));
    printLog(TRACE,
      "EXIT i64FromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return returnValue; // NULL
  }
  
  if (inPlaceData) {
    // Optimize for this case.
    returnValue = (void*) value;
  } else {
    returnValue = i64Copy(value);
  }
  littleEndianToHost(returnValue, sizeof(i64));
  if (returnValue != NULL) {
    *length = sizeof(i64);
  } else {
    *length = 0;
  }
  
  printLog(TRACE,
    "EXIT i64FromBlob(value=%lld, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    (value == NULL) ? 0 : lld(*((i64*) value)), llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety],
    returnValue);
  return returnValue;
}

/// @var typeI64
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the i64 type.
TypeDescriptor _typeI64 = {
  .name          = "i64",
  .xmlName       = "xs:long",
  .dataIsPointer = false,
  .toString      = i64ToString,
  .toBytes       = i64ToBytes,
  .compare       = i64Compare,
  .create        = i64Create,
  .copy          = i64Copy,
  .destroy       = i64Destroy,
  .size          = i64Size,
  .toBlob        = i64ToBlob,
  .fromBlob      = i64FromBlob,
  .hashFunction  = NULL,
  .clear         = clear64,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeI64 = &_typeI64;

/// @var typeI64NoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the i64 type that is not to be copied.
TypeDescriptor _typeI64NoCopy = {
  .name          = "i64",
  .xmlName       = "xs:long",
  .dataIsPointer = true,
  .toString      = i64ToString,
  .toBytes       = i64ToBytes,
  .compare       = i64Compare,
  .create        = i64Create,
  .copy          = shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = i64Size,
  .toBlob        = i64ToBlob,
  .fromBlob      = i64FromBlob,
  .hashFunction  = NULL,
  .clear         = clear64,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeI64NoCopy = &_typeI64NoCopy;

/// @fn char *i128ToString(const volatile void *value)
///
/// @brief Convert a i128 value to its string representation.
///
/// @param value A pointer to the i128 value to convert to a string.
///
/// @return Returns a string representation of the value on success,
///   NULL on failure.
char *i128ToString(const volatile void *value) {
  printLog(TRACE, "ENTER i128ToString(value=%p)\n", value);
  
  char *i128String = NULL;
  if (value == NULL) {
    straddstr(&i128String, "(null)");
    
    printLog(TRACE, "EXIT i128ToString(value=%p) = {%s}\n", value, i128String);
    return i128String;
  }
  
  // We need an unsigned value in case the value is the maximum negative value.
  u128 i128Value = *((u128*) value);
  char digit = '\0';
  char sign = '\0';
  // Can't compare our i128Value to < 0 since it's actually an unsigned type.
  if (*((i128*) value) < 0) {
    // We can't use -i128Value here since i128Value is actually unsigned.
    i128Value = ~i128Value + 1;
    sign = '-';
  }
  
  while (i128Value != 0) {
    digit = '0' + (i128Value % 10);
    straddchr(&i128String, digit);
    i128Value /= 10;
  }
  
  straddchr(&i128String, sign);
  
  if (*i128String == '\0') {
    straddchr(&i128String, '0');
  }
  
  reverseString(i128String);
  
  printLog(TRACE, "EXIT i128ToString(value=%p) = {%s}\n", value, i128String);
  return i128String;
}

/// @fn Bytes i128ToBytes(const volatile void *value)
///
/// @brief Convert a i128 value to its Bytes representation.
///
/// @param value A pointer to the i128 value to convert to a Bytes object.
///
/// @return Returns a Bytes representation of the value on success,
///   NULL on failure.
Bytes i128ToBytes(const volatile void *value) {
  printLog(TRACE, "ENTER i128ToBytes(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(TRACE, "EXIT i128ToBytes(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  Bytes i128Bytes = NULL;
  // We need an unsigned value in case the value is the maximum negative value.
  u128 i128Value = *((u128*) value);
  char digit = '\0';
  char sign = '\0';
  // Can't compare our i128Value to < 0 since it's actually an unsigned type.
  if (*((i128*) value) < 0) {
    // We can't use -i128Value here since i128Value is actually unsigned.
    i128Value = ~i128Value + 1;
    sign = '-';
  }
  
  while (i128Value != 0) {
    digit = '0' + (i128Value % 10);
    bytesAddData(&i128Bytes, &digit, sizeof(digit));
    i128Value /= 10;
  }
  
  if (sign != '\0') {
    bytesAddData(&i128Bytes, &sign, sizeof(sign));
  }
  
  if (i128Bytes == NULL) {
    digit = '0';
    bytesAddData(&i128Bytes, &digit, sizeof(digit));
  }
  
  reverseMemory(i128Bytes, bytesLength(i128Bytes));
  
  printLog(TRACE, "EXIT i128ToBytes(value=%p) = {%s}\n", value, i128Bytes);
  return i128Bytes;
}

/// @fn int i128Compare(const volatile void *valueA, const volatile void *valueB)
///
/// @brief Compare two i128 values.
///
/// @param valueA, valueB are pointers to the values to compare.
///
/// @return Returns -1 if *valueA < *valueB, 0 if *valueA == *valueB,
///   1 if *valueA > *valueB.
int i128Compare(const volatile void *valueA, const volatile void *valueB) {
  printLog(TRACE, "ENTER i128Compare(valueA=%p, valueB=%p)\n", valueA, valueB);
  
  int returnValue = 0;
  
  if (valueA == NULL) {
    printLog(WARN, "valueA is NULL.\n");
    returnValue--;
  }
  if (valueB == NULL) {
    printLog(WARN, "valueB is NULL.\n");
    returnValue++;
  }
  if ((valueA == NULL) || (valueB == NULL)) {
    printLog(TRACE, "EXIT i128Compare(valueA=%p, valueB=%p) = {%d}\n", valueA,
      valueB, returnValue);
    return returnValue;
  }
  
  i128 i128ValueA = *((i128*) valueA);
  i128 i128ValueB = *((i128*) valueB);
  
  if (i128ValueA < i128ValueB) {
    returnValue = -1;
  } else if (i128ValueA > i128ValueB) {
    returnValue = 1;
  } else { // i128ValueA == i128ValueB
    returnValue = 0;
  }
  
  printLog(TRACE, "EXIT i128Compare(valueA=%p, valueB=%p) = {%d}\n", valueA,
    valueB, returnValue);
  return returnValue;
}

/// @fn void *i128Create(const volatile void *parameter1, ...)
///
/// @brief Allocate memory for a new i128 value and initialize it to 0.
///
/// @param parameter1 Dummy parameter for the sake of conformance to
///   TypeDescriptor definition.  Unused by this function.
///
/// @return Returns a pointer to the newly-initialized value.
void *i128Create(const volatile void *parameter1, ...) {
  printLog(TRACE, "ENTER i128Create()\n");
  
  (void) parameter1; // Keep the compiler from complaining.
  
  i128 *value = (i128*) malloc(sizeof(i128));
  *value = 0;
  
  printLog(TRACE, "EXIT i128Create() = {%p}\n", value);
  return (void*) value;
}

/// @fn void *i128Copy(const volatile void *value)
///
/// @brief Create a new i128 value and assign it the value of the input value.
///
/// @param value Pointer to the value to copy.
///
/// @return A pointer to a new i128 with the specified value.
void *i128Copy(const volatile void *value) {
  printLog(TRACE, "ENTER i128Copy(value=%p)\n", value);
  
  if (value == NULL) {
    return NULL;
  }
  
  i128 *valueCopy = (i128*) malloc(sizeof(i128));
  if (valueCopy != NULL) {
    *valueCopy = *((i128*) value);
  }
  
  printLog(TRACE, "EXIT i128Copy(value=%p) = {%p}\n", value, valueCopy);
  return valueCopy;
}

/// @fn void *i128Destroy(volatile void *value)
///
/// @brief Release the memory associated with a i128 value.
///
/// @param value A pointer to the memory to be released.
///
/// @return Returns a null pointer on success, the input pointer on failure.
///   NOTE: Use of the pointer returned by this function will result in
///   undefined behavior.
void *i128Destroy(volatile void *value) {
  printLog(TRACE, "ENTER i128Destroy(value=%p)\n", value);
  
  value = pointerDestroy(value);
  
  printLog(TRACE, "EXIT i128Destroy(value=%p) = {%p}\n", value, value);
  return (void*) value;
}

/// @fn size_t i128Size(const volatile void *value)
///
/// @brief Return the size of a i128 type.
///
/// @param value A pointer to a i128 variable.
///
/// @return Return the size of a i128 type.
size_t i128Size(const volatile void *value) {
  size_t size = 0;
  printLog(TRACE, "ENTER i128Size(value=%p)\n", value);
  
  if (value != NULL) {
    size = sizeof(i128);
  }
  
  printLog(TRACE, "EXIT i128Size(value=%p) = {%llu}\n", value, llu(size));
  return size;
}

/// @fn Bytes i128ToBlob(const volatile void *value)
///
/// @brief Convert a i128 value to an array of bytes.
///
/// @param value A pointer to the i128 value to convert.
///
/// @return Returns a Bytes object with the encoded byte array on success,
/// NULL on failure.
Bytes i128ToBlob(const volatile void *value) {
  Bytes returnValue = NULL;
  printLog(TRACE, "ENTER i128ToBlob(value=%p)\n",
    (value == NULL) ? 0 : value);
  
  if (value == NULL) {
    printLog(ERR, "Cannot convert to byte array.  Parameter is NULL.\n");
    printLog(TRACE, "EXIT i128ToBlob(value=%p) = {%p}\n",
      (value == NULL) ? 0 : value, returnValue);
    return returnValue;
  }
  
  bytesAddData(&returnValue, value, sizeof(i128));
  hostToLittleEndian(returnValue, sizeof(i128));
  // Set the size to match the length.  This is so data structures that are
  // building byte arrays encode the right amount of data, which does not
  // include the string terminator in our case.
  bytesSetSize(returnValue, bytesLength(returnValue));
  
  printLog(TRACE, "EXIT i128ToBlob(value=%p) = {%p}\n",
    (value == NULL) ? 0 : value, returnValue);
  return returnValue;
}

/// @fn void* i128FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety)
///
/// @brief Convert a i128 value to an array of bytes.
///
/// @param value A pointer to the i128 value to convert.
/// @param length The length of the resulting byte array.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned data.  Not used by this function.
///
/// @return Returns a pointer to a valid byte array on success, NULL on failure.
void* i128FromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety) {
  (void) disableThreadSafety;
  void *returnValue = NULL;
  printLog(TRACE,
    "ENTER i128FromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    value, length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  
  if ((value == NULL) || (length == NULL)) {
    printLog(ERR, "Cannot convert to/from byte array.  Parameter is NULL.\n");
    printLog(TRACE,
      "EXIT i128FromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety],
      returnValue);
    return returnValue; // NULL
  } else if (*length < sizeof(i128)) {
    printLog(ERR, "Cannot convert from byte array.  Insufficient data.\n");
    printLog(ERR, "Needed at least %llu bytes, only have %llu.\n",
      llu(sizeof(i128)), llu(*length));
    printLog(TRACE,
      "EXIT i128FromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return returnValue; // NULL
  }
  
  if (inPlaceData) {
    // Optimize for this case.
    returnValue = (void*) value;
  } else {
    returnValue = i128Copy(value);
  }
  littleEndianToHost(returnValue, sizeof(i128));
  if (returnValue != NULL) {
    *length = sizeof(i128);
  } else {
    *length = 0;
  }
  
  printLog(TRACE,
    "EXIT i128FromBlob(value=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    value, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety],
    returnValue);
  return returnValue;
}

/// @var typeI128
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the i128 type.
TypeDescriptor _typeI128 = {
  .name          = "i128",
  .xmlName       = "xs:integer",
  .dataIsPointer = false,
  .toString      = i128ToString,
  .toBytes       = i128ToBytes,
  .compare       = i128Compare,
  .create        = i128Create,
  .copy          = i128Copy,
  .destroy       = i128Destroy,
  .size          = i128Size,
  .toBlob        = i128ToBlob,
  .fromBlob      = i128FromBlob,
  .hashFunction  = NULL,
  .clear         = clear128,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeI128 = &_typeI128;

/// @var typeI128NoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the i128 type that is not to be copied.
TypeDescriptor _typeI128NoCopy = {
  .name          = "i128",
  .xmlName       = "xs:integer",
  .dataIsPointer = true,
  .toString      = i128ToString,
  .toBytes       = i128ToBytes,
  .compare       = i128Compare,
  .create        = i128Create,
  .copy          = shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = i128Size,
  .toBlob        = i128ToBlob,
  .fromBlob      = i128FromBlob,
  .hashFunction  = NULL,
  .clear         = clear128,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeI128NoCopy = &_typeI128NoCopy;

/// @fn char *floatToString(const volatile void *value)
///
/// @brief Convert a float value to its string representation.
///
/// @param value A pointer to the float value to convert to a string.
///
/// @return Returns a string representation of the value on success,
///   NULL on failure.
char *floatToString(const volatile void *value) {
  printLog(TRACE, "ENTER floatToString(value=%f)\n", (value == NULL) ? 0 : *((float*) value));
  
  char *floatString = NULL;
  if (value == NULL) {
    straddstr(&floatString, "(null)");
    
    printLog(TRACE, "EXIT floatToString(value=NULL) = {%s}\n", floatString);
    return floatString;
  }
  
  float floatValue = *((float*) value);
  if (asprintf(&floatString, "%f", floatValue) < 0) {
    // Do nothing.  Caller has to handle the case where a null string is
    // returned.  This check is just here to make the compiler happy.
  }
  
  if ((*((u64*) floatString) == *((u64*) "0.000000"))
    || (*((u64*) floatString) == *((u64*) "-0.000000"))
  ) {
    floatString = stringDestroy(floatString);
    (void) asprintf(&floatString, "%g", floatValue);
  }
  
  printLog(TRACE, "EXIT floatToString(value=%f) = {%s}\n", *((float*) value), floatString);
  return floatString;
}

/// @fn Bytes floatToBytes(const volatile void *value)
///
/// @brief Convert a float value to its Bytes representation.
///
/// @param value A pointer to the float value to convert to a Bytes object.
///
/// @return Returns a Bytes representation of the value on success,
///   NULL on failure.
Bytes floatToBytes(const volatile void *value) {
  printLog(TRACE, "ENTER floatToBytes(value=%f)\n",
    (value == NULL) ? 0 : *((float*) value));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT floatToBytes(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  Bytes floatBytes = NULL;
  float floatValue = *((float*) value);
  abprintf(&floatBytes, "%f", floatValue);
  
  if ((*((u64*) floatBytes) == *((u64*) "0.000000"))
    || (*((u64*) floatBytes) == *((u64*) "-0.000000"))
  ) {
    floatBytes = bytesDestroy(floatBytes);
    (void) abprintf(&floatBytes, "%g", floatValue);
  }
  
  printLog(TRACE, "EXIT floatToBytes(value=%f) = {%s}\n",
    *((float*) value), floatBytes);
  return floatBytes;
}

/// @fn int floatCompare(const volatile void *valueA, const volatile void *valueB)
///
/// @brief Compare two float values.
///
/// @param valueA, valueB are pointers to the values to compare.
///
/// @return Returns -1 if *valueA < *valueB, 0 if *valueA == *valueB,
///   1 if *valueA > *valueB.
int floatCompare(const volatile void *valueA, const volatile void *valueB) {
  printLog(TRACE, "ENTER floatCompare(valueA=%f, valueB=%f)\n", (valueA == NULL) ? 0 : *((float*) valueA), (valueB == NULL) ? 0 : *((float*) valueB));
  
  int returnValue = 0;
  
  if (valueA == NULL) {
    printLog(ERR, "valueA is NULL.\n");
    returnValue--;
  }
  if (valueB == NULL) {
    printLog(ERR, "valueB is NULL.\n");
    returnValue++;
  }
  if ((valueA == NULL) || (valueB == NULL)) {
    printLog(TRACE, "EXIT floatCompare(valueA=%p, valueB=%p) = {%d}\n", valueA,
      valueB, returnValue);
    return returnValue;
  }
  
  float floatValueA = *((float*) valueA);
  float floatValueB = *((float*) valueB);
  
  if (floatValueA < floatValueB) {
    returnValue = -1;
  } else if (floatValueA > floatValueB) {
    returnValue = 1;
  } else { // floatValueA == floatValueB
    returnValue = 0;
  }
  
  printLog(TRACE, "EXIT floatCompare(valueA=%f, valueB=%f) = {%d}\n",
    floatValueA, floatValueB, returnValue);
  return returnValue;
}

/// @fn void *floatCreate(const volatile void *parameter1, ...)
///
/// @brief Allocate memory for a new float value and initialize it to 0.
///
/// @param parameter1 Dummy parameter for the sake of conformance to
///   TypeDescriptor definition.  Unused by this function.
///
/// @return Returns a pointer to the newly-initialized value.
void *floatCreate(const volatile void *parameter1, ...) {
  printLog(TRACE, "ENTER floatCreate()\n");
  
  (void) parameter1; // Keep the compiler from complaining.
  
  float *value = (float*) malloc(sizeof(float));
  *value = 0.0;
  
  printLog(TRACE, "EXIT floatCreate() = {%f}\n", *((float*) value));
  return (void*) value;
}

/// @fn void *floatCopy(const volatile void *value)
///
/// @brief Create a new float value and assign it the value of the input value.
///
/// @param value Pointer to the value to copy.
///
/// @return A pointer to a new float with the specified value.
void *floatCopy(const volatile void *value) {
  printLog(TRACE, "ENTER floatCopy(value=%f)\n", (value == NULL) ? 0 : *((float*) value));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT floatCopy(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  float *valueCopy = (float*) malloc(sizeof(float));
  if (valueCopy != NULL) {
    *valueCopy = *((float*) value);
  }
  
  printLog(TRACE, "EXIT floatCopy(value=%f) = {%p}\n", *((float*) value), valueCopy);
  return valueCopy;
}

/// @fn void *floatDestroy(volatile void *value)
///
/// @brief Release the memory associated with a float value.
///
/// @param value A pointer to the memory to be released.
///
/// @return Returns a null pointer on success, the input pointer on failure.
///   NOTE: Use of the pointer returned by this function will result in
///   undefined behavior.
void *floatDestroy(volatile void *value) {
  printLog(TRACE, "ENTER floatDestroy(value=%f)\n", (value == NULL) ? 0 : *((float*) value));
  
  value = pointerDestroy(value);
  
  printLog(TRACE, "EXIT floatDestroy(value=%p) = {%p}\n", value, value);
  return (void*) value;
}

/// @fn size_t floatSize(const volatile void *value)
///
/// @brief Return the size of a float type.
///
/// @param value A pointer to a float variable.
///
/// @return Return the size of a float type.
size_t floatSize(const volatile void *value) {
  size_t size = 0;
  printLog(TRACE, "ENTER floatSize(value=%p)\n", value);
  
  if (value != NULL) {
    size = sizeof(float);
  }
  
  printLog(TRACE, "EXIT floatSize(value=%p) = {%llu}\n", value, llu(size));
  return size;
}

/// @fn Bytes floatToBlob(const volatile void *value)
///
/// @brief Convert a float value to an array of bytes.
///
/// @param value A pointer to the float value to convert.
///
/// @return Returns a Bytes object with the encoded byte array on success,
/// NULL on failure.
Bytes floatToBlob(const volatile void *value) {
  Bytes returnValue = NULL;
  printLog(TRACE, "ENTER floatToBlob(value=%f)\n",
    (value == NULL) ? 0 : *((float*) value));
  
  if (value == NULL) {
    printLog(ERR, "Cannot convert to byte array.  Parameter is NULL.\n");
    printLog(TRACE, "EXIT floatToBlob(value=%f) = {%p}\n",
      (value == NULL) ? 0 : *((float*) value), returnValue);
    return returnValue;
  }
  
  bytesAddData(&returnValue, value, sizeof(float));
  // Set the size to match the length.  This is so data structures that are
  // building byte arrays encode the right amount of data, which does not
  // include the string terminator in our case.
  bytesSetSize(returnValue, bytesLength(returnValue));
  
  printLog(TRACE, "EXIT floatToBlob(value=%f) = {%p}\n",
    (value == NULL) ? 0 : *((float*) value), returnValue);
  return returnValue;
}

/// @fn void* floatFromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety)
///
/// @brief Convert a float value to an array of bytes.
///
/// @param value A pointer to the float value to convert.
/// @param length The length of the resulting byte array.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned data.  Not used by this function.
///
/// @return Returns a pointer to a valid byte array on success, NULL on failure.
void* floatFromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety) {
  (void) disableThreadSafety;
  void *returnValue = NULL;
  printLog(TRACE,
    "ENTER floatFromBlob(value=%f, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    (value == NULL) ? 0 : *((float*) value), length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  
  if ((value == NULL) || (length == NULL)) {
    printLog(ERR, "Cannot convert to/from byte array.  Parameter is NULL.\n");
    printLog(TRACE,
      "EXIT floatFromBlob(value=%f, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      (value == NULL) ? 0 : *((float*) value), length, boolNames[inPlaceData], boolNames[disableThreadSafety],
      returnValue);
    return returnValue; // NULL
  } else if (*length < sizeof(float)) {
    printLog(ERR, "Cannot convert from byte array.  Insufficient data.\n");
    printLog(ERR, "Needed at least %llu bytes, only have %llu.\n",
      llu(sizeof(float)), llu(*length));
    printLog(TRACE,
      "EXIT floatFromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return returnValue; // NULL
  }
  
  if (inPlaceData) {
    // Optimize for this case.
    returnValue = (void*) value;
  } else {
    returnValue = floatCopy(value);
  }
  littleEndianToHost(returnValue, sizeof(float));
  if (returnValue != NULL) {
    *length = sizeof(float);
  } else {
    *length = 0;
  }
  
  printLog(TRACE,
    "EXIT floatFromBlob(value=%f, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    (value == NULL) ? 0 : *((float*) value), llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety],
    returnValue);
  return returnValue;
}

/// @var typeFloat
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the float type.
TypeDescriptor _typeFloat = {
  .name          = "float",
  .xmlName       = "xs:float",
  .dataIsPointer = false,
  .toString      = floatToString,
  .toBytes       = floatToBytes,
  .compare       = floatCompare,
  .create        = floatCreate,
  .copy          = floatCopy,
  .destroy       = floatDestroy,
  .size          = floatSize,
  .toBlob        = floatToBlob,
  .fromBlob      = floatFromBlob,
  .hashFunction  = NULL,
  .clear         = clearFloat,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeFloat = &_typeFloat;

/// @var typeFloatNoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the float type that is not to be copied.
TypeDescriptor _typeFloatNoCopy = {
  .name          = "float",
  .xmlName       = "xs:float",
  .dataIsPointer = true,
  .toString      = floatToString,
  .toBytes       = floatToBytes,
  .compare       = floatCompare,
  .create        = floatCreate,
  .copy          = shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = floatSize,
  .toBlob        = floatToBlob,
  .fromBlob      = floatFromBlob,
  .hashFunction  = NULL,
  .clear         = clearFloat,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeFloatNoCopy = &_typeFloatNoCopy;

/// @fn char *doubleToString(const volatile void *value)
///
/// @brief Convert a double value to its string representation.
///
/// @param value A pointer to the double value to convert to a string.
///
/// @return Returns a string representation of the value on success,
///   NULL on failure.
char *doubleToString(const volatile void *value) {
  printLog(TRACE, "ENTER doubleToString(value=%lf)\n", (value == NULL) ? 0 : *((double*) value));
  
  char *doubleString = NULL;
  if (value == NULL) {
    straddstr(&doubleString, "(null)");
    
    printLog(TRACE, "EXIT doubleToString(value=NULL) = {%s}\n", doubleString);
    return doubleString;
  }
  
  double doubleValue = *((double*) value);
  if (asprintf(&doubleString, "%lf", doubleValue) < 0) {
    // Do nothing.  Caller has to handle the case where a null string is
    // returned.  This check is just here to make the compiler happy.
  }
  
  if ((*((u64*) doubleString) == *((u64*) "0.000000"))
    || (*((u64*) doubleString) == *((u64*) "-0.000000"))
  ) {
    doubleString = stringDestroy(doubleString);
    (void) asprintf(&doubleString, "%lg", doubleValue);
  }
  
  printLog(TRACE, "EXIT doubleToString(value=%lf) = {%s}\n", *((double*) value), doubleString);
  return doubleString;
}

/// @fn Bytes doubleToBytes(const volatile void *value)
///
/// @brief Convert a double value to its Bytes representation.
///
/// @param value A pointer to the double value to convert to a Bytes object.
///
/// @return Returns a Bytes representation of the value on success,
///   NULL on failure.
Bytes doubleToBytes(const volatile void *value) {
  printLog(TRACE, "ENTER doubleToBytes(value=%f)\n",
    (value == NULL) ? 0 : *((double*) value));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT doubleToBytes(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  Bytes doubleBytes = NULL;
  double doubleValue = *((double*) value);
  abprintf(&doubleBytes, "%lf", doubleValue);
  
  if ((*((u64*) doubleBytes) == *((u64*) "0.000000"))
    || (*((u64*) doubleBytes) == *((u64*) "-0.000000"))
  ) {
    doubleBytes = bytesDestroy(doubleBytes);
    (void) abprintf(&doubleBytes, "%lg", doubleValue);
  }
  
  printLog(TRACE, "EXIT doubleToBytes(value=%f) = {%s}\n",
    *((double*) value), doubleBytes);
  return doubleBytes;
}

/// @fn int doubleCompare(const volatile void *valueA, const volatile void *valueB)
///
/// @brief Compare two double values.
///
/// @param valueA, valueB are pointers to the values to compare.
///
/// @return Returns -1 if *valueA < *valueB, 0 if *valueA == *valueB,
///   1 if *valueA > *valueB.
int doubleCompare(const volatile void *valueA, const volatile void *valueB) {
  printLog(TRACE, "ENTER doubleCompare(valueA=%lf, valueB=%lf)\n", (valueA == NULL) ? 0 : *((double*) valueA), (valueB == NULL) ? 0 : *((double*) valueB));
  
  int returnValue = 0;
  
  if (valueA == NULL) {
    printLog(WARN, "valueA is NULL.\n");
    returnValue--;
  }
  if (valueB == NULL) {
    printLog(WARN, "valueB is NULL.\n");
    returnValue++;
  }
  if ((valueA == NULL) || (valueB == NULL)) {
    printLog(TRACE, "EXIT doubleCompare(valueA=%p, valueB=%p) = {%d}\n", valueA,
      valueB, returnValue);
    return returnValue;
  }
  
  double doubleValueA = *((double*) valueA);
  double doubleValueB = *((double*) valueB);
  
  if (doubleValueA < doubleValueB) {
    returnValue = -1;
  } else if (doubleValueA > doubleValueB) {
    returnValue = 1;
  } else { // doubleValueA == doubleValueB
    returnValue = 0;
  }
  
  printLog(TRACE, "EXIT doubleCompare(valueA=%lf, valueB=%lf) = {%d}\n",
    doubleValueA, doubleValueB, returnValue);
  return returnValue;
}

/// @fn void *doubleCreate(const volatile void *parameter1, ...)
///
/// @brief Allocate memory for a new double value and initialize it to 0.
///
/// @param parameter1 Dummy parameter for the sake of conformance to
///   TypeDescriptor definition.  Unused by this function.
///
/// @return Returns a pointer to the newly-initialized value.
void *doubleCreate(const volatile void *parameter1, ...) {
  printLog(TRACE, "ENTER doubleCreate()\n");
  
  (void) parameter1; // Keep the compiler from complaining.
  
  double *value = (double*) malloc(sizeof(double));
  *value = 0.0;
  
  printLog(TRACE, "EXIT doubleCreate() = {%lf}\n", *((double*) value));
  return (void*) value;
}

/// @fn void *doubleCopy(const volatile void *value)
///
/// @brief Create a new double value and assign it the value of the input value.
///
/// @param value Pointer to the value to copy.
///
/// @return A pointer to a new double with the specified value.
void *doubleCopy(const volatile void *value) {
  printLog(TRACE, "ENTER doubleCopy(value=%lf)\n", (value == NULL) ? 0 : *((double*) value));
  
  if (value == NULL) {
    printLog(TRACE, "EXIT doubleCopy(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  double *valueCopy = (double*) malloc(sizeof(double));
  if (valueCopy != NULL) {
    *valueCopy = *((double*) value);
  }
  
  printLog(TRACE, "EXIT doubleCopy(value=%lf) = {%p}\n", *((double*) value), valueCopy);
  return valueCopy;
}

/// @fn void *doubleDestroy(volatile void *value)
///
/// @brief Release the memory associated with a double value.
///
/// @param value A pointer to the memory to be released.
///
/// @return Returns a null pointer on success, the input pointer on failure.
///   NOTE: Use of the pointer returned by this function will result in
///   undefined behavior.
void *doubleDestroy(volatile void *value) {
  printLog(TRACE, "ENTER doubleDestroy(value=%lf)\n", (value == NULL) ? 0 : *((double*) value));
  
  value = pointerDestroy(value);
  
  printLog(TRACE, "EXIT doubleDestroy(value=%p) = {%p}\n", value, value);
  return (void*) value;
}

/// @fn size_t doubleSize(const volatile void *value)
///
/// @brief Return the size of a double type.
///
/// @param value A pointer to a double variable.
///
/// @return Return the size of a double type.
size_t doubleSize(const volatile void *value) {
  size_t size = 0;
  printLog(TRACE, "ENTER doubleSize(value=%p)\n", value);
  
  if (value != NULL) {
    size = sizeof(double);
  }
  
  printLog(TRACE, "EXIT doubleSize(value=%p) = {%llu}\n", value, llu(size));
  return size;
}

/// @fn Bytes doubleToBlob(const volatile void *value)
///
/// @brief Convert a double value to an array of bytes.
///
/// @param value A pointer to the double value to convert.
///
/// @return Returns a Bytes object with the encoded byte array on success,
/// NULL on failure.
Bytes doubleToBlob(const volatile void *value) {
  Bytes returnValue = NULL;
  printLog(TRACE, "ENTER doubleToBlob(value=%lf)\n",
    (value == NULL) ? 0 : *((double*) value));
  
  if (value == NULL) {
    printLog(ERR, "Cannot convert to byte array.  Parameter is NULL.\n");
    printLog(TRACE, "EXIT doubleToBlob(value=%lf) = {%p}\n",
      (value == NULL) ? 0 : *((double*) value), returnValue);
    return returnValue;
  }
  
  bytesAddData(&returnValue, value, sizeof(double));
  // Set the size to match the length.  This is so data structures that are
  // building byte arrays encode the right amount of data, which does not
  // include the string terminator in our case.
  bytesSetSize(returnValue, bytesLength(returnValue));
  
  printLog(TRACE, "EXIT doubleToBlob(value=%lf) = {%p}\n",
    (value == NULL) ? 0 : *((double*) value), returnValue);
  return returnValue;
}

/// @fn void* doubleFromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety)
///
/// @brief Convert a double value to an array of bytes.
///
/// @param value A pointer to the double value to convert.
/// @param length The length of the resulting byte array.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned data.  Not used by this function.
///
/// @return Returns a pointer to a valid byte array on success, NULL on failure.
void* doubleFromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety) {
  (void) disableThreadSafety;
  void *returnValue = NULL;
  printLog(TRACE,
    "ENTER doubleFromBlob(value=%lf, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    (value == NULL) ? 0 : *((double*) value), length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  
  if ((value == NULL) || (length == NULL)) {
    printLog(ERR, "Cannot convert to/from byte array.  Parameter is NULL.\n");
    printLog(TRACE,
      "EXIT doubleFromBlob(value=%lf, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      (value == NULL) ? 0 : *((double*) value), length, boolNames[inPlaceData], boolNames[disableThreadSafety],
      returnValue);
    return returnValue; // NULL
  } else if (*length < sizeof(double)) {
    printLog(ERR, "Cannot convert from byte array.  Insufficient data.\n");
    printLog(ERR, "Needed at least %llu bytes, only have %llu.\n",
      llu(sizeof(double)), llu(*length));
    printLog(TRACE,
      "EXIT doubleFromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return returnValue; // NULL
  }
  
  if (inPlaceData) {
    // Optimize for this case.
    returnValue = (void*) value;
  } else {
    returnValue = doubleCopy(value);
  }
  littleEndianToHost(returnValue, sizeof(double));
  if (returnValue != NULL) {
    *length = sizeof(double);
  } else {
    *length = 0;
  }
  
  printLog(TRACE,
    "EXIT doubleFromBlob(value=%lf, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    (value == NULL) ? 0 : *((double*) value), llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety],
    returnValue);
  return returnValue;
}

/// @var typeDouble
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the double type.
TypeDescriptor _typeDouble = {
  .name          = "double",
  .xmlName       = "xs:double",
  .dataIsPointer = false,
  .toString      = doubleToString,
  .toBytes       = doubleToBytes,
  .compare       = doubleCompare,
  .create        = doubleCreate,
  .copy          = doubleCopy,
  .destroy       = doubleDestroy,
  .size          = doubleSize,
  .toBlob        = doubleToBlob,
  .fromBlob      = doubleFromBlob,
  .hashFunction  = NULL,
  .clear         = clearDouble,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeDouble = &_typeDouble;

/// @var typeDoubleNoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the double type that is not to be copied.
TypeDescriptor _typeDoubleNoCopy = {
  .name          = "double",
  .xmlName       = "xs:double",
  .dataIsPointer = true,
  .toString      = doubleToString,
  .toBytes       = doubleToBytes,
  .compare       = doubleCompare,
  .create        = doubleCreate,
  .copy          = shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = doubleSize,
  .toBlob        = doubleToBlob,
  .fromBlob      = doubleFromBlob,
  .hashFunction  = NULL,
  .clear         = clearDouble,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeDoubleNoCopy = &_typeDoubleNoCopy;

/// @fn char *longDoubleToString(const volatile void *value)
///
/// @brief Convert a long double value to its string representation.
///
/// @param value A pointer to the long double value to convert to a string.
///
/// @return Returns a string representation of the value on success,
///   NULL on failure.
char *longDoubleToString(const volatile void *value) {
  printLog(TRACE, "ENTER longDoubleToString(value=%p)\n", value);
  
  char *longDoubleString = NULL;
  if (value == NULL) {
    straddstr(&longDoubleString, "(null)");
    
    printLog(TRACE, "EXIT longDoubleToString(value=NULL) = {%s}\n",
      longDoubleString);
    return longDoubleString;
  }
  
  long double longDoubleValue = *((long double*) value);
  if (asprintf(&longDoubleString, "%Lf", longDoubleValue) < 0) {
    // Do nothing.  Caller has to handle the case where a null string is
    // returned.  This check is just here to make the compiler happy.
  }
  
  if ((*((u64*) longDoubleString) == *((u64*) "0.000000"))
    || (*((u64*) longDoubleString) == *((u64*) "-0.000000"))
  ) {
    longDoubleString = stringDestroy(longDoubleString);
    (void) asprintf(&longDoubleString, "%Lg", longDoubleValue);
  }
  
  printLog(TRACE, "EXIT longDoubleToString(value=%Lf) = {%s}\n",
    longDoubleValue, longDoubleString);
  return longDoubleString;
}

/// @fn Bytes longDoubleToBytes(const volatile void *value)
///
/// @brief Convert a long double value to its Bytes representation.
///
/// @param value A pointer to the long double value to convert to a Bytes object.
///
/// @return Returns a Bytes representation of the value on success,
///   NULL on failure.
Bytes longDoubleToBytes(const volatile void *value) {
  printLog(TRACE, "ENTER longDoubleToBytes(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(TRACE, "EXIT longDoubleToBytes(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  Bytes longDoubleBytes = NULL;
  long double longDoubleValue = *((long double*) value);
  abprintf(&longDoubleBytes, "%Lf", longDoubleValue);
  
  if ((*((u64*) longDoubleBytes) == *((u64*) "0.000000"))
    || (*((u64*) longDoubleBytes) == *((u64*) "-0.000000"))
  ) {
    longDoubleBytes = bytesDestroy(longDoubleBytes);
    (void) abprintf(&longDoubleBytes, "%Lg", longDoubleValue);
  }
  
  printLog(TRACE, "EXIT longDoubleToBytes(value=%Lf) = {%s}\n",
    longDoubleValue, longDoubleBytes);
  return longDoubleBytes;
}

/// @fn int longDoubleCompare(const volatile void *valueA, const volatile void *valueB)
///
/// @brief Compare two long double values.
///
/// @param valueA, valueB are pointers to the values to compare.
///
/// @return Returns -1 if *valueA < *valueB, 0 if *valueA == *valueB,
///   1 if *valueA > *valueB.
int longDoubleCompare(const volatile void *valueA, const volatile void *valueB) {
  printLog(TRACE, "ENTER longDoubleCompare(valueA=%p, valueB=%p)\n",
    valueA, valueB);
  
  int returnValue = 0;
  
  if (valueA == NULL) {
    printLog(WARN, "valueA is NULL.\n");
    returnValue--;
  }
  if (valueB == NULL) {
    printLog(WARN, "valueB is NULL.\n");
    returnValue++;
  }
  if ((valueA == NULL) || (valueB == NULL)) {
    printLog(TRACE, "EXIT longDoubleCompare(valueA=%p, valueB=%p) = {%d}\n",
      valueA, valueB, returnValue);
    return returnValue;
  }
  
  long double longDoubleValueA = *((long double*) valueA);
  long double longDoubleValueB = *((long double*) valueB);
  
  if (longDoubleValueA < longDoubleValueB) {
    returnValue = -1;
  } else if (longDoubleValueA > longDoubleValueB) {
    returnValue = 1;
  } else { // longDoubleValueA == longDoubleValueB
    returnValue = 0;
  }
  
  printLog(TRACE, "EXIT longDoubleCompare(valueA=%Lf, valueB=%Lf) = {%d}\n",
    longDoubleValueA, longDoubleValueB, returnValue);
  return returnValue;
}

/// @fn void *longDoubleCreate(const volatile void *parameter1, ...)
///
/// @brief Allocate memory for a new long double value and initialize it to 0.
///
/// @param parameter1 Dummy parameter for the sake of conformance to
///   TypeDescriptor definition.  Unused by this function.
///
/// @return Returns a pointer to the newly-initialized value.
void *longDoubleCreate(const volatile void *parameter1, ...) {
  printLog(TRACE, "ENTER longDoubleCreate()\n");
  
  (void) parameter1; // Keep the compiler from complaining.
  
  long double *value = (long double*) malloc(sizeof(long double));
  *value = 0.0;
  
  printLog(TRACE, "EXIT longDoubleCreate() = {%Lf}\n", *value);
  return (void*) value;
}

/// @fn void *longDoubleCopy(const volatile void *value)
///
/// @brief Create a new long double value and assign it the value of the input value.
///
/// @param value Pointer to the value to copy.
///
/// @return A pointer to a new long double with the specified value.
void *longDoubleCopy(const volatile void *value) {
  printLog(TRACE, "ENTER longDoubleCopy(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(TRACE, "EXIT longDoubleCopy(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  long double *valueCopy = (long double*) malloc(sizeof(long double));
  if (valueCopy != NULL) {
    *valueCopy = *((long double*) value);
  }
  
  printLog(TRACE, "EXIT longDoubleCopy(value=%Lf) = {%p}\n",
    *((longDouble*) value), valueCopy);
  return valueCopy;
}

/// @fn void *longDoubleDestroy(volatile void *value)
///
/// @brief Release the memory associated with a long double value.
///
/// @param value A pointer to the memory to be released.
///
/// @return Returns a null pointer on success, the input pointer on failure.
///   NOTE: Use of the pointer returned by this function will result in
///   undefined behavior.
void *longDoubleDestroy(volatile void *value) {
  printLog(TRACE, "ENTER longDoubleDestroy(value=%p)\n", value);
  
  value = (volatile void*) pointerDestroy(value);
  
  printLog(TRACE, "EXIT longDoubleDestroy(value=%p) = {%p}\n", value, value);
  return (void*) value;
}

/// @fn size_t longDoubleSize(const volatile void *value)
///
/// @brief Return the size of a longDouble type.
///
/// @param value A pointer to a longDouble variable.
///
/// @return Return the size of a longDouble type.
size_t longDoubleSize(const volatile void *value) {
  size_t size = 0;
  printLog(TRACE, "ENTER longDoubleSize(value=%p)\n", value);
  
  if (value != NULL) {
    size = sizeof(longDouble);
  }
  
  printLog(TRACE, "EXIT longDoubleSize(value=%p) = {%llu}\n", value, llu(size));
  return size;
}

/// @fn Bytes longDoubleToBlob(const volatile void *value)
///
/// @brief Convert a longDouble value to an array of bytes.
///
/// @param value A pointer to the longDouble value to convert.
///
/// @return Returns a Bytes object with the encoded byte array on success,
/// NULL on failure.
Bytes longDoubleToBlob(const volatile void *value) {
  Bytes returnValue = NULL;
  printLog(TRACE, "ENTER longDoubleToBlob(value=%Lf)\n",
    (value == NULL) ? 0 : *((longDouble*) value));
  
  if (value == NULL) {
    printLog(ERR, "Cannot convert to byte array.  Parameter is NULL.\n");
    printLog(TRACE, "EXIT longDoubleToBlob(value=%Lf) = {%p}\n",
      (value == NULL) ? 0 : *((longDouble*) value), returnValue);
    return returnValue;
  }
  
  longDouble longDoubleValue = *((longDouble*) value);
  abprintf(&returnValue, "%.100Lf", longDoubleValue);
  printLog(TRACE, "returnValue = %s\n", (char*) returnValue);
  
  printLog(TRACE, "EXIT longDoubleToBlob(value=%Lf) = {%p}\n",
    (value == NULL) ? 0 : *((longDouble*) value), returnValue);
  return returnValue;
}

/// @fn void* longDoubleFromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety)
///
/// @brief Convert a long double value to an array of bytes.
///
/// @param value A pointer to the long double value to convert.
/// @param length The length of the resulting byte array.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned data.  Not used by this function.
///
/// @return Returns a pointer to a valid byte array on success, NULL on failure.
void* longDoubleFromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety) {
  (void) disableThreadSafety;
  void *returnValue = NULL;
  printLog(TRACE,
    "ENTER longDoubleFromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    value, length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  
  if ((value == NULL) || (length == NULL)) {
    printLog(ERR, "Cannot convert from byte array.  Parameter is NULL.\n");
    printLog(TRACE,
      "EXIT longDoubleFromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return returnValue;
  }
  printLog(DEBUG, "value = %s\n", (char*) value);
  
  // There's no way to use the data in place for this encoding, so there's no
  // case for that here.  Just ignore the parameter.
  (void) inPlaceData;
  returnValue = (long double*) malloc(sizeof(long double));
  if (returnValue != NULL) {
    sscanf(str(value), "%Lf", (long double*) returnValue);
    *length = strlen(str(value)) + 1;
  }
  
  printLog(TRACE,
    "EXIT longDoubleFromBlob(value=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%LF}\n",
    value, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], *((longDouble*) returnValue));
  return returnValue;
}

/// @var typeLongDouble
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the long double type.
TypeDescriptor _typeLongDouble = {
  .name          = "longDouble",
  .xmlName       = "xs:decimal",
  .dataIsPointer = false,
  .toString      = longDoubleToString,
  .toBytes       = longDoubleToBytes,
  .compare       = longDoubleCompare,
  .create        = longDoubleCreate,
  .copy          = longDoubleCopy,
  .destroy       = longDoubleDestroy,
  .size          = longDoubleSize,
  .toBlob        = longDoubleToBlob,
  .fromBlob      = longDoubleFromBlob,
  .hashFunction  = NULL,
  .clear         = clearLongDouble,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeLongDouble = &_typeLongDouble;

/// @var typeLongDoubleNoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the long double type that is not to be copied.
TypeDescriptor _typeLongDoubleNoCopy = {
  .name          = "longDouble",
  .xmlName       = "xs:decimal",
  .dataIsPointer = true,
  .toString      = longDoubleToString,
  .toBytes       = longDoubleToBytes,
  .compare       = longDoubleCompare,
  .create        = longDoubleCreate,
  .copy          = shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = longDoubleSize,
  .toBlob        = longDoubleToBlob,
  .fromBlob      = longDoubleFromBlob,
  .hashFunction  = NULL,
  .clear         = clearLongDouble,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeLongDoubleNoCopy = &_typeLongDoubleNoCopy;

/// @fn char *stringToString(const volatile void *value)
///
/// @brief Convert a string value to its string representation.
///
/// @param value A pointer to the string value to convert to a string.
///
/// @return Returns a string representation of the value on success,
///   NULL on failure.
char *stringToString(const volatile void *value) {
  printLog(TRACE, "ENTER stringToString(value=%p)\n", value);
  
  char *stringString = NULL;
  if (value == NULL) {
    straddstr(&stringString, "(null)");
    
    printLog(TRACE, "EXIT stringToString(value=%p) = {%s}\n", value, stringString);
    return stringString;
  }
  
  const char *stringValue = (const char*) value;
  straddstr(&stringString, stringValue);
  
  printLog(TRACE, "EXIT stringToString(value=%p) = {%s}\n", value, stringString);
  return stringString;
}

/// @fn Bytes stringToBytes(const volatile void *value)
///
/// @brief Convert a string value to its Bytes representation.
///
/// @param value A pointer to the string value to convert to a Bytes object.
///
/// @return Returns a Bytes representation of the value on success,
///   NULL on failure.
Bytes stringToBytes(const volatile void *value) {
  printLog(TRACE, "ENTER stringToBytes(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(TRACE, "EXIT stringToBytes(value=%p) = {NULL}\n", value);
    return NULL;
  }
  
  const char *stringValue = (const char*) value;
  Bytes stringBytes = NULL;
  bytesAddStr(&stringBytes, stringValue);
  
  printLog(TRACE, "EXIT stringToBytes(value=%p) = {%s}\n", value, stringBytes);
  return stringBytes;
}

/// @fn int stringCompare(const volatile void *valueA, const volatile void *valueB)
///
/// @brief Compare two string values.
///
/// @param valueA, valueB are pointers to the values to compare.
///
/// @return Returns -1 if *valueA < *valueB, 0 if *valueA == *valueB,
///   1 if *valueA > *valueB.
int stringCompare(const volatile void *valueA, const volatile void *valueB) {
  printLog(TRACE, "ENTER stringCompare(valueA=%p, valueB=%p)\n", valueA, valueB);
  
  int returnValue = 0;
  
  if (valueA == NULL) {
    printLog(WARN, "valueA is NULL.\n");
    returnValue--;
  }
  if (valueB == NULL) {
    printLog(WARN, "valueB is NULL.\n");
    returnValue++;
  }
  if ((valueA == NULL) || (valueB == NULL)) {
    printLog(TRACE, "EXIT stringCompare(valueA=%p, valueB=%p) = {%d}\n", valueA,
      valueB, returnValue);
    return returnValue;
  }
  
  returnValue = strcmp((char*) valueA, (char*) valueB);
  // If we made it this far, strcmp didn't segfault, so we can assume both
  // values are printable strings.
  printLog(TRACE, "EXIT stringCompare(valueA=\"%s\", valueB=\"%s\") = {%d}\n",
    str(valueA), str(valueB), returnValue);
  return returnValue;
}

/// @fn void *stringCreate(const volatile void *parameter1, ...)
///
/// @brief Allocate memory for a new string value and initialize it to "".
///
/// @param parameter1 Dummy parameter for the sake of conformance to
///   TypeDescriptor definition.  Unused by this function.
///
/// @return Returns a pointer to the newly-initialized value.
void *stringCreate(const volatile void *parameter1, ...) {
  printLog(TRACE, "ENTER stringCreate()\n");
  
  (void) parameter1; // Keep the compiler from complaining.
  
  char *value = (char*) malloc(1);
  *value = '\0';
  
  printLog(TRACE, "EXIT stringCreate() = {%s}\n", value);
  return (void*) value;
}

/// @fn void *stringCopy(const volatile void *value)
///
/// @brief Create a new string value and assign it the value of the input value.
///
/// @param value Pointer to the value to copy.
///
/// @return A pointer to a new string with the specified value.
void *stringCopy(const volatile void *value) {
  printLog(TRACE, "ENTER stringCopy(value=%s)\n",
    (value == NULL) ? "NULL" : (char*) value);
  
  if (value == NULL) {
    printLog(TRACE, "EXIT stringCopy(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  char *stringValue = (char*) value;
  char *valueCopy = NULL;
  straddstr(&valueCopy, stringValue);
  
  printLog(TRACE, "EXIT stringCopy(value=%s) = {%p}\n",
    (char*) value, valueCopy);
  return (void*) valueCopy;
}

/// @fn size_t stringSize(const volatile void *value)
///
/// @brief Return the size of a string type.
///
/// @param value A pointer to a string variable.
///
/// @return Return the size of a string type.
size_t stringSize(const volatile void *value) {
  size_t size = 0;
  printLog(TRACE, "ENTER stringSize(value=%p)\n", value);
  
  if (value != NULL) {
    size = strlen((char*) value) + 1;
  }
  
  printLog(TRACE, "EXIT stringSize(value=%p) = {%llu}\n", value, llu(size));
  return size;
}

/// @fn Bytes stringToBlob(const volatile void *value)
///
/// @brief Convert a string value to an array of bytes.
///
/// @param value A pointer to the string value to convert.
/// @param length The length of the resulting byte array.
///
/// @return Returns a Bytes object with the encoded byte array on success,
/// NULL on failure.
Bytes stringToBlob(const volatile void *value) {
  Bytes returnValue = NULL;
  printLog(TRACE, "ENTER stringToBlob(value=\"%s\")\n",
    (value == NULL) ? "" : (char*) value);
  
  if (value == NULL) {
    printLog(ERR, "Cannot convert to byte array.  Parameter is NULL.\n");
    printLog(TRACE, "EXIT stringToBlob(value=\"%s\") = {%p}\n",
      (value == NULL) ? "" : (char*) value, returnValue);
    return returnValue;
  }
  
  bytesAddStr(&returnValue, str(value));
  
  printLog(TRACE, "EXIT stringToBlob(value=\"%s\") = {%p}\n",
    (value == NULL) ? "" : (char*) value, returnValue);
  return returnValue;
}

/// @fn void* stringFromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety)
///
/// @brief Convert a string value to an array of bytes.
///
/// @param value A pointer to the string value to convert.
/// @param length The length of the resulting byte array.
///
/// @return Returns a pointer to a valid byte array on success, NULL on failure.
void* stringFromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety) {
  (void) disableThreadSafety;
  void *returnValue = NULL;
  printLog(TRACE,
    "ENTER stringFromBlob(value=\"%s\", length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    (value == NULL) ? "" : (char*) value, length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  
  if ((value == NULL) || (length == NULL)) {
    printLog(ERR, "Cannot convert to/from byte array.  Parameter is NULL.\n");
    printLog(TRACE,
      "EXIT stringFromBlob(value=\"%s\", length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      (value == NULL) ? "" : (char*) value, length, boolNames[inPlaceData], boolNames[disableThreadSafety],
      returnValue);
    return returnValue;
  }
  
  if (inPlaceData) {
    // Optimize for this case.
    returnValue = (void*) value;
  } else {
    returnValue = stringCopy(value);
  }
  if (returnValue != NULL) {
    *length = strlen((char*) value) + 1;
  } else {
    *length = 0;
  }
  
  printLog(TRACE,
    "EXIT stringFromBlob(value=\"%s\", length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    (value == NULL) ? "" : (char*) value, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety],
    returnValue);
  return returnValue;
}

/// @fn u64 stringHashFunction(const volatile void *value)
///
/// @brief Specialized hash function for strings.  This is the same algorithm
/// as is in HashTable.c, and indeed we could just use that.  However, that
/// relies on calling typeString->size, which calls strlen, which, of course
/// itereates through the whole string until the NULL terminator is found to
/// compute the size of the string.  This means that we go through the string
/// TWICE when computing the hash this way.  That's inefficient, so we have a
/// custom algorithm that just goes through it once.
///
/// @param value The string to be hashed.
///
/// @return Returns a register-width integer repsresenting the case-insensitive
/// hash of the string.
u64 stringHashFunction(const volatile void *value) {
  printLog(TRACE, "ENTER stringHashFunction(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(TRACE, "EXIT stringHashFunction(value=%p) = {%llu}\n",
      value, 0ULL);
    return 0;
  }
  
  const char *key = (const char*) value;
  u64 hash = 0;
  
  for (u64 i = 0; key[i] != '\0'; i++) {
    hash += key[i];
    hash += hash << 10;
    hash ^= hash >> 6;
  }
   
  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 15;
  
  printLog(TRACE, "EXIT stringHashFunction(value=\"%s\") = {%llu}\n",
    str(value), llu(hash));
  return hash;
}

/// @var typeString
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the string type.
TypeDescriptor _typeString = {
  .name          = "string",
  .xmlName       = "xs:string",
  .dataIsPointer = true,
  .toString      = stringToString,
  .toBytes       = stringToBytes,
  .compare       = stringCompare,
  .create        = stringCreate,
  .copy          = stringCopy,
  .destroy       = pointerDestroyFunction,
  .size          = stringSize,
  .toBlob        = stringToBlob,
  .fromBlob      = stringFromBlob,
  .hashFunction  = stringHashFunction,
  .clear         = clearString,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeString = &_typeString;

/// @fn int _strcmpci(const volatile void *s1, const volatile void *s2)
///
/// @brief Do a case-insensitive comparison between two strings.
/// The only reason this is here is to provide a proper function pointer for the
/// type below since strcmpci is a macro in StringLib.h.
///
/// @param s1 A pointer to the first string to compare.
/// @param s2 A pointer to the second string to compare.
///
/// @return Returns < 0 if valueA < valueB, 0 if valueA == valueB,
///   1 if valueA > valueB.
int _strcmpci(const volatile void *valueA, const volatile void *valueB) {
  return strcmpci((const char*) valueA, (const char*) valueB);
}

/// @fn u64 stringCiHashFunction(const volatile void *value)
///
/// @brief Specialized hash function to provide a case-insensitive hash.  This
/// is accomplished by translating all lower-case letters in the string to their
/// upper-case counterparts and hashing those values.
///
/// @param value The string to be hashed.
///
/// @return Returns a register-width integer repsresenting the case-insensitive
/// hash of the string.
u64 stringCiHashFunction(const volatile void *value) {
  printLog(TRACE, "ENTER stringCiHashFunction(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(TRACE, "EXIT stringCiHashFunction(value=%p) = {%llu}\n",
      value, 0ULL);
    return 0;
  }
  
  const char *key = (const char*) value;
  u64 hash = 0;
  
  for (u64 i = 0; key[i] != '\0'; i++) {
    char c = key[i];
    if ((c >= 'a') && (c <= 'z')) {
      c -= 32;
    }
    hash += c;
    hash += hash << 10;
    hash ^= hash >> 6;
  }
   
  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 15;
  
  printLog(TRACE, "EXIT stringCiHashFunction(value=%p) = {%llu}\n",
    value, llu(hash));
  return hash;
}

/// @var typeStringNoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the string type that is not copied from its original source.
///
/// @details This exists because, by default, a copy of the input data is made
///   whenever a new data element is added to any data structure.  In some
///   situations, this is not desirable because the input serves no purpose
///   other than to be added to the data structure.  In such cases, this data
///   type may be specified to avoid the unnecessary copy.  The real
///   typeString type can then be set after the data is added.
TypeDescriptor _typeStringNoCopy = {
  .name          = "string",
  .xmlName       = "xs:string",
  .dataIsPointer = true,
  .toString      = stringToString,
  .toBytes       = stringToBytes,
  .compare       = stringCompare,
  .create        = stringCreate,
  .copy          = shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = stringSize,
  .toBlob        = stringToBlob,
  .fromBlob      = stringFromBlob,
  .hashFunction  = stringHashFunction,
  .clear         = clearString,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeStringNoCopy = &_typeStringNoCopy;

/// @var typeStringCi
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the case-insensitive string type.
TypeDescriptor _typeStringCi = {
  .name          = "case-insensitive string",
  .xmlName       = "xs:string",
  .dataIsPointer = true,
  .toString      = stringToString,
  .toBytes       = stringToBytes,
  .compare       = _strcmpci,
  .create        = stringCreate,
  .copy          = stringCopy,
  .destroy       = pointerDestroyFunction,
  .size          = stringSize,
  .toBlob        = stringToBlob,
  .fromBlob      = stringFromBlob,
  .hashFunction  = stringCiHashFunction,
  .clear         = clearString,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeStringCi = &_typeStringCi;

/// @var typeStringCiNoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the case-insensitive string type that is not copied from its
///   original source.
TypeDescriptor _typeStringCiNoCopy = {
  .name          = "case-insensitive string",
  .xmlName       = "xs:string",
  .dataIsPointer = true,
  .toString      = stringToString,
  .toBytes       = stringToBytes,
  .compare       = _strcmpci,
  .create        = stringCreate,
  .copy          = shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = stringSize,
  .toBlob        = stringToBlob,
  .fromBlob      = stringFromBlob,
  .hashFunction  = stringCiHashFunction,
  .clear         = clearString,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeStringCiNoCopy = &_typeStringCiNoCopy;

/// @fn void *shallowCopy(const volatile void *value)
///
/// @brief Shallow copy of a pointer value.
///
/// @param value The pointer to be copied.
///
/// @return Returns a copy of the value passed in.
void *shallowCopy(const volatile void *value) {
  printLog(TRACE, "ENTER shallowCopy(value=%p)\n", value);
  printLog(TRACE, "EXIT shallowCopy(value=%p) = {%p}\n", value, value);
  return (void*) value;
}

/// @fn void *nullFunction(volatile void *value, ...)
///
/// @brief Function that does nothing and returns NULL.
///
/// @param value A dummy value.  Unused
/// @param ... Unused optional parameters.
///
/// @return This function always returns NULL
void *nullFunction(volatile void *value, ...) {
  (void) value; // In case logging is disabled.
  printLog(TRACE, "ENTER nullFunction(value=%p)\n", value);
  printLog(TRACE, "EXIT nullFunction(value=%p) = {%p}\n", value, (void*) NULL);
  return NULL;
}

/// @fn char *pointerToString(const volatile void *value)
///
/// @brief Convert a pointer value to its string representation.
///
/// @param value A pointer value to convert to a string.
///
/// @return Returns a string representation of the value on success,
///   NULL on failure.
char *pointerToString(const volatile void *value) {
  printLog(TRACE, "ENTER pointerToString(value=%p)\n", value);
  
  char *pointerString = NULL;
  (void) asprintf(&pointerString, "%p", value);
  
  printLog(TRACE, "EXIT pointerToString(value=%p) = {%s}\n", value, pointerString);
  return pointerString;
}

/// @fn Bytes pointerToBytes(const volatile void *value)
///
/// @brief Convert a pointer value to its Bytes representation.
///
/// @param value A pointer value to convert to a Bytes object.
///
/// @return Returns a Bytes representation of the value on success,
///   NULL on failure.
Bytes pointerToBytes(const volatile void *value) {
  printLog(TRACE, "ENTER pointerToBytes(value=%p)\n", value);
  
  Bytes pointerBytes = NULL;
  abprintf(&pointerBytes, "0x%llx", llu((intptr_t) value));
  
  printLog(TRACE, "EXIT pointerToBytes(value=%p) = {%s}\n", value, pointerBytes);
  return pointerBytes;
}

/// @fn int pointerCompare(const volatile void *valueA, const volatile void *valueB)
///
/// @brief Compare two u64 values.
///
/// @param valueA, valueB are pointers to the values to compare.
///
/// @return Returns -1 if *valueA < *valueB, 0 if *valueA == *valueB,
///   1 if *valueA > *valueB.
int pointerCompare(const volatile void *valueA, const volatile void *valueB) {
  printLog(TRACE, "ENTER pointerCompare(valueA=%p, valueB=%p)\n", valueA, valueB);
  
  u64 u64ValueA = ((u64) ((intptr_t) valueA));
  u64 u64ValueB = ((u64) ((intptr_t) valueB));
  
  if (u64ValueA < u64ValueB) {
    printLog(TRACE, "EXIT pointerCompare(valueA=%p, valueB=%p) = {-1}\n", valueA, valueB);
    return -1;
  } else if (u64ValueA > u64ValueB) {
    printLog(TRACE, "EXIT pointerCompare(valueA=%p, valueB=%p) = {1}\n", valueA, valueB);
    return 1;
  } else { // u64ValueA == u64ValueB
    printLog(TRACE, "EXIT pointerCompare(valueA=%p, valueB=%p) = {0}\n", valueA, valueB);
    return 0;
  }
}

/// @fn size_t pointerSize(const volatile void *value)
///
/// @brief Return the size of a pointer type.
///
/// @param value A pointer variable.
///
/// @return This function always returns 0.
size_t pointerSize(const volatile void *value) {
  (void) value; // In case logging is disabled.
  size_t size = 0;
  printLog(TRACE, "ENTER pointerSize(value=%p)\n", value);
  
  printLog(TRACE, "EXIT pointerSize(value=%p) = {%llu}\n", value, llu(size));
  return size;
}

/// @fn Bytes pointerToBlob(const volatile void *value)
///
/// @brief Convert a pointer value to an array of bytes.
///
/// @param value A pointer value.
/// @param length The length of the resulting byte array.
///
/// @return Returns a Bytes object with the encoded byte array on success,
/// NULL on failure.
Bytes pointerToBlob(const volatile void *value) {
  printLog(TRACE, "ENTER pointerToBlob(value=%p)\n",
    value);
  Bytes returnValue = NULL;
  if (value == NULL) {
    // No-op.
    printLog(TRACE, "EXIT pointerToBlob(value=%p) = {%p}\n",
      value, returnValue);
    return returnValue;
  }
  
  bytesAddData(&returnValue, &value, sizeof(void*));
  // Set the size to match the length.  This is so data structures that are
  // building byte arrays encode the right amount of data, which does not
  // include the string terminator in our case.
  bytesSetSize(returnValue, bytesLength(returnValue));
  
  printLog(TRACE, "EXIT pointerToBlob(value=%p) = {%p}\n",
    value, returnValue);
  return returnValue;
}

/// @fn void* pointerFromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety)
///
/// @brief Convert an array of bytes to a pointer value.
///
/// @param array A pointer to an array of bytes holding a pointer value.
/// @param length The number of bytes consumed by the function in converting
///   the data to a pointer value.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned data.  Not used by this function.
///
/// @return Returns an allocated copy of the value of the pointer provided on
/// success, NULL on failure.
void* pointerFromBlob(const volatile void *array, u64 *length, bool inPlaceData, bool disableThreadSafety) {
  (void) disableThreadSafety;
  printLog(TRACE,
    "ENTER pointerFromBlob(array=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    array, length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  void *returnValue = NULL;
  
  if ((array == NULL) || (length == NULL)) {
    printLog(ERR, "Cannot convert from byte array.  Parameter is NULL.\n");
    printLog(TRACE,
      "EXIT pointerFromBlob(array=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      array, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return returnValue; // NULL
  } else if (*length < sizeof(void*)) {
    printLog(ERR, "Cannot convert from byte array.  Insufficient data.\n");
    printLog(ERR, "Needed at least %llu bytes, only have %llu.\n",
      llu(sizeof(void*)), llu(*length));
    printLog(TRACE,
      "EXIT pointerFromBlob(array=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      array, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return returnValue; // NULL
  }
  
  // In this case, the data is the same irrespective of the value of
  // inPlaceData, so just ignore the parameter.
  (void) inPlaceData;
  returnValue = *((void**) array);
  *length = sizeof(void*);
  
  printLog(TRACE,
    "EXIT pointerFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
  return returnValue;
}

/// @fn void* pointerDestroyFunction(volatile void *pointer)
///
/// @brief Destroy a generic pointer of any type (void*) and return NULL.
///
/// @param pointer A pointer to any type of a block of memory to free.
///
/// @return This function always returns NULL.
void* pointerDestroyFunction(volatile void *pointer) {
  free((void*) pointer);
  return NULL;
}

/// @fn u64 pointerHashFunction(const volatile void *value)
///
/// @brief Hash function for pointer types.
///
/// @details
/// By definition, every pointer value in a program is unique.  If someone is
/// using generic pointers as keys in a data structure (which is the only reason
/// this function would be called), there's no reason to compute a fancy hash.
/// We really just need to return the numeric version of the pointer provided.
///
/// @param value A pointer to the value being used as a key.
///
/// @return Returns a hash value of the pointer, which is the numeric value of
/// the pointer cast to a REGISTER_INT.
u64 pointerHashFunction(const volatile void *value) {
  return (u64) ((intptr_t) value);
}

/// @var typePointer
///
/// @brief TypeDescriptor describing how libraries should interact with simple
///   pointers.  This type cannot be included in the typeDescriptors array.
///   This type takes ownership of the pointer.  That is, it will destroy the
///   pointer via free when a data structure is done with the data.  To avoid
///   that behavior, use typePointerNoCopy.
TypeDescriptor _typePointer = {
  .name          = "Pointer",
  .xmlName       = NULL,
  .dataIsPointer = true,
  .toString      = pointerToString,
  .toBytes       = pointerToBytes,
  .compare       = pointerCompare,
  .create        = (void* (*)(const volatile void*, ...)) nullFunction,
  .copy          = (void* (*)(const volatile void*)) shallowCopy,
  .destroy       = pointerDestroyFunction,
  .size          = pointerSize,
  .toBlob        = pointerToBlob,
  .fromBlob      = pointerFromBlob,
  .hashFunction  = pointerHashFunction,
  .clear         = clearNull,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typePointer = &_typePointer;

/// @var typePointerNoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with simple
///   pointers.  This type cannot be included in the typeDescriptors array.
///   This type takes no ownerhip of the pointer and the memory is not freed
///   via the destroy call.
TypeDescriptor _typePointerNoCopy = {
  .name          = "Pointer",
  .xmlName       = NULL,
  .dataIsPointer = true,
  .toString      = pointerToString,
  .toBytes       = pointerToBytes,
  .compare       = pointerCompare,
  .create        = (void* (*)(const volatile void*, ...)) nullFunction,
  .copy          = (void* (*)(const volatile void*)) shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = pointerSize,
  .toBlob        = pointerToBlob,
  .fromBlob      = pointerFromBlob,
  .hashFunction  = pointerHashFunction,
  .clear         = clearNull,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typePointerNoCopy = &_typePointerNoCopy;
TypeDescriptor *typePointerNoOwn = &_typePointerNoCopy;

/// @fn char *bytesToString(const volatile void *value)
///
/// @brief Convert a Bytes value to its string representation.
///
/// @param value A pointer to the Bytes value to convert to a string.
///
/// @return Returns a string representation of the value on success,
///   NULL on failure.
char *bytesToString(const volatile void *value) {
  printLog(TRACE, "ENTER bytesToString(value=%p)\n", value);
  
  char *bytesString = NULL;
  if (value == NULL) {
    straddstr(&bytesString, "");
    
    printLog(TRACE, "EXIT bytesToString(value=%p) = {%s}\n", value, bytesString);
    return bytesString;
  }
  
  u64 length = bytesLength((Bytes) value);
  // Max length of the string is (3 * length) + 1 if every character is escapaed
  bytesString = (char*) malloc((length << 2) + length + 1);
  u64 bytesStringIndex = 0;
  const char *bytesValue = (const char*) value;
  char escapeSequence[4] = {0};
  
  for (u64 i = 0; i < length; i++) {
    u64 escapeSequenceLength = 1;
    if ((((bytesValue[i] < 32) || (bytesValue[i] > 126))
        && ((bytesValue[i] != '\n') && (bytesValue[i] != '\r')))
      || (bytesValue[i] == '%')
    ) {
      sprintf(escapeSequence, "%%%02X", (u8) bytesValue[i]);
      escapeSequenceLength = 3;
    } else {
      escapeSequence[0] = bytesValue[i];
      escapeSequence[1] = '\0';
    }
    strcpy(&bytesString[bytesStringIndex], escapeSequence);
    bytesStringIndex += escapeSequenceLength;
  }
  bytesString[bytesStringIndex] = '\0';
  
  printLog(TRACE, "EXIT bytesToString(value=%p) = {%s}\n", value, bytesString);
  return bytesString;
}

/// @fn Bytes bytesToBytes(const volatile void *value)
///
/// @brief Convert a Bytes value to its Bytes representation.
///
/// @param value A pointer to the Bytes value to convert to a Bytes object.
///
/// @return Returns a Bytes representation of the value on success,
///   NULL on failure.
Bytes bytesToBytes(const volatile void *value) {
  printLog(TRACE, "ENTER bytesToBytes(value=%p)\n", value);
  
  if (value == NULL) {
    printLog(TRACE, "EXIT bytesToBytes(value=%p) = {NULL}\n", value);
    return NULL;
  }
  
  const Bytes bytesValue = (Bytes) value;
  Bytes bytesBytes = NULL;
  bytesAddBytes(&bytesBytes, bytesValue);
  if (bytesBytes == NULL) {
    // This isn't right.  The input value was not NULL.  For bytesBytes to still
    // be NULL means that the provided value was an allocated, zero-length
    // string.  Fix this.
    bytesAddStr(&bytesBytes, "");
  }
  
  printLog(TRACE, "EXIT bytesToBytes(value=%p) = {%s}\n", value, bytesBytes);
  return bytesBytes;
}

/// @fn void *bytesCreate(const volatile void *input, ...)
///
/// @brief Allocate memory for a new Bytes value and initialize it to a
/// zero length array.
///
/// @param input A pointer to the data to put in the Bytes return value.
/// @param ... One additional u64 parameter is required representing the number
///   of bytes at the input pointer.
///
/// @return Returns a pointer to the newly-initialized value.
void *bytesCreate(const volatile void *input, ...) {
  printLog(TRACE, "ENTER bytesCreate()\n");
  
  u64 length = 0;
  if (input != NULL) {
    va_list args;
    va_start(args, input);
    length = va_arg(args, u64);
    va_end(args);
  }
  
  Bytes returnValue = NULL;
  bytesAddData(&returnValue, input, length);
  
  printLog(TRACE, "EXIT bytesCreate() = {%p}\n", returnValue);
  return (void*) returnValue;
}

/// @fn void *bytesCopy(const volatile void *value)
///
/// @brief Create a new Bytes value and assign it the value of the input value.
///
/// @param value Pointer to the value to copy.
///
/// @return A pointer to a new Bytes with the specified value.
void *bytesCopy(const volatile void *value) {
  printLog(TRACE, "ENTER bytesCopy(value=%p)\n", (value == NULL) ? "NULL" : value);
  
  if (value == NULL) {
    printLog(TRACE, "EXIT bytesCopy(value=NULL) = {NULL}\n");
    return NULL;
  }
  
  Bytes valueCopy = NULL;
  bytesAddData(&valueCopy, (Bytes) value, bytesLength((Bytes) value));
  
  printLog(TRACE, "EXIT bytesCopy(value=%p) = {%p}\n", value, valueCopy);
  return (void*) valueCopy;
}

/// @fn size_t _bytesSize(const volatile void *value)
///
/// @brief Return the size of a Bytes type.
///
/// @param value A pointer to a Bytes variable.
///
/// @return Return the size of a Bytes type.
size_t _bytesSize(const volatile void *value) {
  size_t size = 0;
  printLog(TRACE, "ENTER _bytesSize(value=%p)\n", value);
  
  if (value != NULL) {
    size = (size_t) bytesLength((Bytes) value);
  }
  
  printLog(TRACE, "EXIT _bytesSize(value=%p) = {%llu}\n", value, llu(size));
  return size;
}

/// @fn Bytes bytesToBlob(const volatile void *value)
///
/// @brief Convert a Bytes value to an array of bytes.
///
/// @param value A pointer to the Bytes value to convert.
///
/// @return Returns a Bytes object with the encoded byte array on success,
/// NULL on failure.
Bytes bytesToBlob(const volatile void *value) {
  Bytes returnValue = NULL;
  printLog(TRACE, "ENTER bytesToBlob(value=%p)\n", value);
  
  if (value == NULL) {
    // No-op.
    printLog(TRACE, "EXIT bytesToBlob(value=%p) = {%p}\n",
      value, returnValue);
    return returnValue;
  }
  
  Bytes bytesValue = (Bytes) value;
  BytesHeader *bytesHeader
    = (BytesHeader*) (bytesValue - sizeof(BytesHeader));
  // The BytesHeader is two (2) 64-bit values, so there should be no issue with
  // packing or data alignment here.
  bytesAddData(&returnValue,
    bytesHeader, bytesLength(bytesValue) + sizeof(BytesHeader) + 1);
  
  bytesHeader = (BytesHeader*) returnValue;
  bytesValue = ((Bytes) bytesHeader) + sizeof(BytesHeader);
  // Truncate the size of the copy to only what was allocated.
  bytesSetSize(bytesValue, bytesLength(bytesValue) + 1);
  hostToLittleEndian(&bytesHeader->length, sizeof(bytesHeader->length));
  hostToLittleEndian(&bytesHeader->size, sizeof(bytesHeader->size));
  
  // Truncate the size of the Bytes we return to only the bytes object we
  // allocated (no final NULL byte or anything else).
  bytesValue = (Bytes) returnValue;
  bytesSetSize(bytesValue, bytesLength(bytesValue));
  
  printLog(TRACE, "EXIT bytesToBlob(value=%p) = {%p}\n",
    value, returnValue);
  return returnValue;
}

/// @fn void* bytesFromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety)
///
/// @brief Convert a byte array representation of Bytes to bytes.
///
/// @param value A pointer to the byte array value to convert.
/// @param length The length of the input byte array on call.  The number of
///   bytes consumed by this function on return.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned data.  Not used by this function.
///
/// @return Returns a pointer to a valid Bytes object on success, NULL on failure.
void* bytesFromBlob(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety) {
  (void) disableThreadSafety;
  void *returnValue = NULL;
  printLog(TRACE,
    "ENTER bytesFromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    value, length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  
  if ((value == NULL) || (length == NULL)) {
    printLog(ERR, "Cannot convert from byte array.  Parameter is NULL.\n");
    printLog(TRACE,
      "EXIT bytesFromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return (void*) returnValue; // NULL
  } else if (*length < sizeof(BytesHeader)) {
    printLog(ERR, "Cannot convert from byte array.  Insufficient data.\n");
    printLog(ERR, "Needed at least %llu bytes, only have %llu.\n",
      llu(sizeof(BytesHeader)), llu(*length));
    printLog(TRACE,
      "EXIT bytesFromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return returnValue; // NULL
  }
  
  BytesHeader *bytesHeader = (BytesHeader*) value;
  littleEndianToHost(&bytesHeader->length, sizeof(bytesHeader->length));
  littleEndianToHost(&bytesHeader->size, sizeof(bytesHeader->size));
  
  // Move the pointer back to the beginning of the data.  The BytesHeader is
  // two (2) 64-bit values, so there should be no issue with packing or data
  // alignment here.
  Bytes bytesValue = ((Bytes) value) + sizeof(BytesHeader);
  // We want the size here, not the length.  The size attribute holds the full
  // amount of allocated memory while the length attribute just tells us how
  // many bytes are valid.
  u64 valueLength = bytesSize(bytesValue);
  if (valueLength > *length) {
    printLog(ERR, "Cannot convert from byte array.  Insufficient data.\n");
    printLog(ERR, "Needed at least %llu bytes, only have %llu.\n",
      llu(valueLength + sizeof(BytesHeader)), llu(*length));
    printLog(TRACE,
      "EXIT bytesFromBlob(value=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      value, length, boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
    return (void*) returnValue;
  }
  
  if (inPlaceData) {
    // Optimize for this case.
    returnValue = (void*) bytesValue;
  } else {
    bytesAddBytes((Bytes*) &returnValue, bytesValue);
  }
  if (returnValue != NULL) {
    *length = valueLength + sizeof(BytesHeader);
  } else {
    *length = 0;
  }
  
  printLog(TRACE,
    "EXIT bytesFromBlob(value=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    value, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], returnValue);
  return returnValue;
}

/// @fn int _bytesCompare(const volatile void *s1, const volatile void *s2)
///
/// @brief Do a comparison of two Bytes objects.
/// The only reason this is here is to provide a proper function pointer for the
/// type below since bytesCompare is a macro in StringLib.h.
///
/// @param s1 A pointer to the first Bytes object to compare.
/// @param s2 A pointer to the second Bytes object to compare.
///
/// @return Returns < 0 if valueA < valueB, 0 if valueA == valueB,
///   1 if valueA > valueB.
int _bytesCompare(const volatile void *valueA, const volatile void *valueB) {
  return bytesCompare((Bytes) valueA, (Bytes) valueB);
}

/// @var typeBytes
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the Bytes type.
TypeDescriptor _typeBytes = {
  .name          = "bytes",
  .xmlName       = "",
  .dataIsPointer = true,
  .toString      = bytesToString,
  .toBytes       = bytesToBytes,
  .compare       = _bytesCompare,
  .create        = bytesCreate,
  .copy          = bytesCopy,
  .destroy       = (void* (*)(volatile void*)) bytesDestroy,
  .size          = _bytesSize,
  .toBlob        = bytesToBlob,
  .fromBlob      = bytesFromBlob,
  .hashFunction  = NULL,
  .clear         = clearBytes,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeBytes = &_typeBytes;

/// @var typeBytesNoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with data
///   that is of the Bytes type type that is not copied from its original source.
///
/// @details This exists because, by default, a copy of the input data is made
///   whenever a new data element is added to any data structure.  In some
///   situations, this is not desirable because the input serves no purpose
///   other than to be added to the data structure.  In such cases, this data
///   type may be specified to avoid the unnecessary copy.  The real
///   typeBytes type can then be set after the data is added.
TypeDescriptor _typeBytesNoCopy = {
  .name          = "bytes",
  .xmlName       = "",
  .dataIsPointer = true,
  .toString      = bytesToString,
  .toBytes       = bytesToBytes,
  .compare       = _bytesCompare,
  .create        = bytesCreate,
  .copy          = shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = _bytesSize,
  .toBlob        = bytesToBlob,
  .fromBlob      = bytesFromBlob,
  .hashFunction  = NULL,
  .clear         = clearBytes,
  .toXml         = NULL,
  .toJson        = NULL,
};
TypeDescriptor *typeBytesNoCopy = &_typeBytesNoCopy;

extern TypeDescriptor _typeList;
extern TypeDescriptor _typeListNoCopy;
extern TypeDescriptor _typeQueue;
extern TypeDescriptor _typeQueueNoCopy;
extern TypeDescriptor _typeStack;
extern TypeDescriptor _typeStackNoCopy;
extern TypeDescriptor _typeRbTree;
extern TypeDescriptor _typeRbTreeNoCopy;
extern TypeDescriptor _typeHashTable;
extern TypeDescriptor _typeHashTableNoCopy;
extern TypeDescriptor _typeVector;
extern TypeDescriptor _typeVectorNoCopy;
//// extern TypeDescriptor _typeArray;
//// extern TypeDescriptor _typeArrayNoCopy;

/// @var typeDescriptors
///
/// @brief Array of TypeDescriptor pointers for lookup and comparison.
TypeDescriptor *typeDescriptors[] = {
  &_typeBool,
  &_typeBoolNoCopy,
  &_typeI8,
  &_typeI8NoCopy,
  &_typeU8,
  &_typeU8NoCopy,
  &_typeI16,
  &_typeI16NoCopy,
  &_typeU16,
  &_typeU16NoCopy,
  &_typeI32,
  &_typeI32NoCopy,
  &_typeU32,
  &_typeU32NoCopy,
  &_typeI64,
  &_typeI64NoCopy,
  &_typeU64,
  &_typeU64NoCopy,
  &_typeI128,
  &_typeI128NoCopy,
  &_typeU128,
  &_typeU128NoCopy,
  &_typeFloat,
  &_typeFloatNoCopy,
  &_typeDouble,
  &_typeDoubleNoCopy,
  &_typeLongDouble,
  &_typeLongDoubleNoCopy,
  &_typeString,
  &_typeStringNoCopy,
  &_typeStringCi,
  &_typeStringCiNoCopy,
  &_typeBytes,
  &_typeBytesNoCopy,
  &_typeList,
  &_typeListNoCopy,
  &_typeQueue,
  &_typeQueueNoCopy,
  &_typeStack,
  &_typeStackNoCopy,
  &_typeRbTree,
  &_typeRbTreeNoCopy,
  &_typeHashTable,
  &_typeHashTableNoCopy,
  &_typeVector,
  &_typeVectorNoCopy,
  //// &_typeArray,
  //// &_typeArrayNoCopy,
  &_typePointer,
  &_typePointerNoCopy,
  (TypeDescriptor*) STOP
};

// We need our HashTable for managing the lookups of the TypeDescriptors.
#include "HashTable.h"

/// @var _typeDescriptorTablesSetup
///
/// @brief A once_flag to keep track of whether or not the thread-specific
/// storage for this library has been initialized.
static once_flag _typeDescriptorTablesSetup = ONCE_FLAG_INIT;

/// @var _typeDescriptorsToIndexes
///
/// @brief A lookup table from TypeDescriptors to their indexes.
static HashTable *_typeDescriptorsToIndexes = NULL;

/// @var _indexesToTypeDescriptors
///
/// @brief A lookup table from indexes to their TypeDescriptors.
static HashTable *_indexesToTypeDescriptors = NULL;

/// @var _initTypeDescriptorTableInProgress
///
/// @brief Variable to break the deadlock while we're in the middle of
/// initializing the tables.
static bool _initTypeDescriptorTableInProgress = false;

/// @fn void initTypeDescriptorTable(void)
///
/// @brief Function to run once to initialize the typeDescriptor lookup tables.
///
/// @return This function returns no value.
void initTypeDescriptorTable(void) {
  _initTypeDescriptorTableInProgress = true;
  
  _typeDescriptorsToIndexes = htCreate(typePointerNoOwn);
  if (_typeDescriptorsToIndexes == NULL) {
    LOG_MALLOC_FAILURE();
    // Leave _initTypeDescriptorTableInProgress set to true to force a linear
    // search.
    return;
  }
  
  _indexesToTypeDescriptors = htCreate(typeI64);
  if (_indexesToTypeDescriptors == NULL) {
    LOG_MALLOC_FAILURE();
    _typeDescriptorsToIndexes = htDestroy(_typeDescriptorsToIndexes);
    // Leave _initTypeDescriptorTableInProgress set to true to force a linear
    // search.
    return;
  }
  
  for (i64 i = 0; typeDescriptors[i] != STOP; i++) {
    htAddEntry(_typeDescriptorsToIndexes, typeDescriptors[i], &i, typeI64);
    htAddEntry(_indexesToTypeDescriptors, &i, typeDescriptors[i], typePointerNoOwn);
  }
  _initTypeDescriptorTableInProgress = false;
}

/// @fn i64 getIndexFromTypeDescriptor(TypeDescriptor *typeDescriptor)
///
/// @brief Get the index of the typeDescriptors array the specified 
/// typeDescriptor is at.
///
/// @param typeDescriptor the TypeDescriptor to search for.
///
/// @return Returns the index of the TypeDescriptor if found, -1 on failure.
i64 getIndexFromTypeDescriptor(TypeDescriptor *typeDescriptor) {
  i64 index = -1;
  
  if (typeDescriptor == NULL) {
    return index; // -1
  }
  
  // Run a linear search on the array first since that's faster.
  for (i64 i = 0; typeDescriptors[i] != STOP; i++) {
    if (typeDescriptors[i] == typeDescriptor) {
      index = i;
      break;
    }
  }
  if ((index == -1) && (_initTypeDescriptorTableInProgress == false)) {
    call_once(&_typeDescriptorTablesSetup, initTypeDescriptorTable);
    
    // Try the hash table.
    i64 *tsIndex = (i64*) htGetValue(_typeDescriptorsToIndexes, typeDescriptor);
    if (tsIndex != NULL) {
      index = *tsIndex;
    } // else index remains -1
  }
  
  return index;
}

/// @fn u64 getNumTypeDescriptors()
///
/// @brief Return the number of known, static type descriptors on the system.
///
/// @return Returns the number of known type descriptors as an integer value.
u64 getNumTypeDescriptors() {
  if (_initTypeDescriptorTableInProgress == false) {
    call_once(&_typeDescriptorTablesSetup, initTypeDescriptorTable);
    return _typeDescriptorsToIndexes->size;
  } else {
    u64 numTypeDescriptors = 0;
    for (; typeDescriptors[numTypeDescriptors] != STOP; numTypeDescriptors++);
    return numTypeDescriptors;
  }
}

/// @fn int registerTypeDescriptor(TypeDescriptor *typeDescriptor)
///
/// @brief Register a TypeDescriptor other than one of the static ones.
///
/// @param typeDescriptor The pointer to the TypeDescriptor to register.
///
/// @return Returns 0 on success, -1 on failure.
int registerTypeDescriptor(TypeDescriptor *typeDescriptor) {
  // We're making use of other functions that invoke initTypeDescriptorTable,
  // so no need to use call_once here.
  
  if (getIndexFromTypeDescriptor(typeDescriptor) > -1) {
    // Type is already registered.  No-op.
    return 0;
  }
  
  int returnValue = 0;
  if (_initTypeDescriptorTableInProgress == false) {
    mtx_lock(_typeDescriptorsToIndexes->lock);
    mtx_lock(_indexesToTypeDescriptors->lock);
    
    i64 numTypeDescriptors = (i64) _typeDescriptorsToIndexes->size;
    
    htAddEntry(_typeDescriptorsToIndexes,
      typeDescriptor, &numTypeDescriptors, typeI64);
    htAddEntry(_indexesToTypeDescriptors,
      &numTypeDescriptors, typeDescriptor, typePointerNoOwn);
    
    mtx_unlock(_indexesToTypeDescriptors->lock);
    mtx_unlock(_typeDescriptorsToIndexes->lock);
  } else {
    // The tables are not setup and there's nothing we can do.  Fail.
    returnValue = -1;
  }
  
  return returnValue;
}

/// @fn TypeDescriptor* getTypeDescriptorFromIndex(i64 typeDescriptorIndex)
///
/// @brief Get a pointer to a TypeDescriptor given its index.
///
/// @param typeDescriptorIndex The index of a previously-registered
///   TypeDescriptor.
///
/// @return Returns a pointer to the specified TypeDescriptor on success,
/// NULL on failure.
TypeDescriptor* getTypeDescriptorFromIndex(i64 typeDescriptorIndex) {
  call_once(&_typeDescriptorTablesSetup, initTypeDescriptorTable);
  
  TypeDescriptor *typeDescriptor = NULL;
  if (typeDescriptorIndex < 0) {
    // Invalid index.
    return typeDescriptor; // NULL
  }
  
  // Try the array first since that's faster.
  if (typeDescriptorIndex
    < ((i64) ((sizeof(typeDescriptors) / sizeof(TypeDescriptor*)) - 1))
  ) {
    typeDescriptor = typeDescriptors[typeDescriptorIndex];
  } else if (_initTypeDescriptorTableInProgress == false) {
    typeDescriptor = (TypeDescriptor*)
      htGetValue(_indexesToTypeDescriptors, &typeDescriptorIndex);
  }
  
  return typeDescriptor;
}

/// @fn bool stringIsInteger(const char *str)
///
/// @brief Determine whether or not a string is a representation of an integer.
///
/// @param str The string to examine.
///
/// @return Returns true if the string is a representation of an integer, false
/// otherwise.
bool stringIsInteger(const char *str) {
  const char *strp = str;
  
  if ((*strp == '-') || (*strp == '+')) {
    // Possible sign prefix.  Skip.
    strp++;
  }
  
  int numNumerals = 0;
  while (((*strp >= '0') && (*strp <= '9')) || (*strp == '.')
  ) {
    if ((*strp == '.') && (strp[1] >= '0') && (strp[1] <= '9')) {
      return false;
    } else if (*strp != '.') {
      numNumerals++;
    }
    
    strp++;
  }
  
  return (numNumerals > 0);
}

/// @fn bool stringIsFloat(const char *str)
///
/// @brief Determine whether or not a string is a representation of a
/// floating-point number.
///
/// @param str The string to examine.
///
/// @return Returns true if the string is a representation of a floating-point
/// number, false otherwise.
bool stringIsFloat(const char *str) {
  const char *strp = str;
  
  if ((*strp == '-') || (*strp == '+')) {
    // Possible sign prefix.  Skip.
    strp++;
  }
  
  int numDecimals = 0;
  int numNumerals = 0;
  int numExponents = 0;
  while (((*strp >= '0') && (*strp <= '9')) || (*strp == '.')
    || (*strp == '-') || (*strp == 'e') || (*strp == 'E')
  ) {
    if ((*strp == '.') && (strp[1] >= '0') && (strp[1] <= '9')) {
      numDecimals++;
    } else if (((*strp == 'e') || (*strp == 'E'))
      && (strp[1] >= '0') && (strp[1] <= '9')
    ) {
      numExponents++;
    } else {
      numNumerals++;
    }
    
    if ((numDecimals > 1) || (numExponents > 1)) {
      return false;
    }
    
    strp++;
  }
  
  return ((numNumerals > 0) && ((numDecimals == 1) || (numExponents == 1)));
}

/// @fn bool stringIsNumber(const char *str)
///
/// @brief Determine whether or not a string is a representation of a number.
///
/// @param str The string to examine.
///
/// @return Returns true if the string is a representation of a number,
/// false otherwise.
bool stringIsNumber(const char *str) {
  return (stringIsFloat(str) || stringIsInteger(str));
}

/// @fn bool stringIsBoolean(const char *str)
///
/// @brief Determine whether or not a string is a representation of a boolean.
///
/// @param str The string to examine.
///
/// @return Returns true if the string is a representation of a boolean value,
/// false otherwise.
bool stringIsBoolean(const char *str) {
  if (strncmp(str, "true", 4) == 0) {
    return true;
  } else if (strncmp(str, "false", 5) == 0) {
    return true;
  }
  
  return false;
}

/// @fn bool strtobool(const char *str, char **endptr)
///
/// @brief Convert a string representation of a boolean value to its bool
/// equivalent.
///
/// @param str The string to convert.
/// @param endptr If this parameter is non-NULL, it will be set to the first
///   character past the end of the parsed value.
///
/// @return Returns true if the string at str is "true", false otherwise.
bool strtobool(const char *str, char **endptr) {
  if (strncmp(str, "true", 4) == 0) {
    if (endptr != NULL) {
      *endptr = ((char*) str) + 4;
    }
    return true;
  }
  
  if ((strncmp(str, "false", 5) == 0) && (endptr != NULL)) {
    *endptr = ((char*) str) + 5;
  }
  
  return false;
}

/// @def DATA_TYPE_UNIT_TEST
///
/// @brief Template for unit tests for dataTypes functionality.
///
/// @return Returns true on success, false on failure.
#define DATA_TYPE_UNIT_TEST(SMALL_TYPE, BIG_TYPE, MIN_VALUE, MAX_VALUE, SIZE) \
bool SMALL_TYPE##UnitTest() { \
  const SMALL_TYPE value1 = MAX_VALUE; \
  const SMALL_TYPE value2 = MIN_VALUE; \
  char *string = NULL; \
  SMALL_TYPE *newValue = NULL; \
  u64 length = 0; \
   \
  string = type##BIG_TYPE->toString(NULL); \
  if (strcmp(string, "(null)") != 0) { \
    printLog(ERR, "type%s->toString returned \"%s\" instead of \"%s\".\n", \
      #BIG_TYPE, string, "(null)"); \
    string = stringDestroy(string); \
    return false; \
  } \
  string = stringDestroy(string); \
  string = type##BIG_TYPE->toString(&value1); \
  if (strcmp(string, #MAX_VALUE) != 0) { \
    printLog(ERR, "type%s->toString returned \"%s\" instead of \"%s\".\n", \
      #BIG_TYPE, string, #MAX_VALUE); \
    string = stringDestroy(string); \
    return false; \
  } \
  string = stringDestroy(string); \
  string = type##BIG_TYPE->toString(&value2); \
  if (strcmp(string, #MIN_VALUE) != 0) { \
    printLog(ERR, "type%s->toString returned \"%s\" instead of \"%s\".\n", \
      #BIG_TYPE, string, #MIN_VALUE); \
    string = stringDestroy(string); \
    return false; \
  } \
  string = stringDestroy(string); \
   \
  string = (char*) type##BIG_TYPE->toBytes(NULL); \
  if (string != NULL) { \
    printLog(ERR, "type%s->toBytes returned \"%s\" instead of NULL.\n", \
      #BIG_TYPE, string); \
    string = (char*) typeBytes->destroy(string); \
    return false; \
  } \
  string = (char*) typeBytes->destroy(string); \
  string = (char*) type##BIG_TYPE->toBytes(&value1); \
  if (strcmp(string, #MAX_VALUE) != 0) { \
    printLog(ERR, "type%s->toBytes returned \"%s\" instead of \"%s\".\n", \
      #BIG_TYPE, string, #MAX_VALUE); \
    string = (char*) typeBytes->destroy(string); \
    return false; \
  } \
  string = (char*) typeBytes->destroy(string); \
  string = (char*) type##BIG_TYPE->toBytes(&value2); \
  if (strcmp(string, #MIN_VALUE) != 0) { \
    printLog(ERR, "type%s->toBytes returned \"%s\" instead of \"%s\".\n", \
      #BIG_TYPE, string, #MIN_VALUE); \
    string = (char*) typeBytes->destroy(string); \
    return false; \
  } \
  string = (char*) typeBytes->destroy(string); \
   \
  if (type##BIG_TYPE->compare(&value1, &value1) != 0) { \
    printLog(ERR, "type%s->compare(%s, %s) did not return 0.\n", #BIG_TYPE, \
      #MAX_VALUE, #MAX_VALUE); \
    return false; \
  } \
  if (type##BIG_TYPE->compare(&value2, &value2) != 0) { \
    printLog(ERR, "type%s->compare(%s, %s) did not return 0.\n", #BIG_TYPE, \
      #MIN_VALUE, #MIN_VALUE); \
    return false; \
  } \
  if (type##BIG_TYPE->compare(&value1, &value2) <= 0) { \
    printLog(ERR, "type%s->compare(%s, %s) did not return 1.\n", #BIG_TYPE, \
      #MAX_VALUE, #MIN_VALUE); \
    return false; \
  } \
  if (type##BIG_TYPE->compare(&value2, &value1) >= 0) { \
    printLog(ERR, "type%s->compare(%s, %s) did not return -1.\n", #BIG_TYPE, \
      #MIN_VALUE, #MAX_VALUE); \
    return false; \
  } \
  if (type##BIG_TYPE->compare(&value1, NULL) <= 0) { \
    printLog(ERR, "type%s->compare(%s, NULL) did not return 1.\n", #BIG_TYPE, \
      #MAX_VALUE); \
    return false; \
  } \
  if (type##BIG_TYPE->compare(NULL, &value1) >= 0) { \
    printLog(ERR, "type%s->compare(NULL, %s) did not return -1.\n", #BIG_TYPE, \
      #MAX_VALUE); \
    return false; \
  } \
   \
  newValue = (SMALL_TYPE*) type##BIG_TYPE->create(NULL); \
  if (newValue == NULL) { \
    printLog(ERR, "type%s->create failed.\n", #BIG_TYPE); \
    return false; \
  } \
  if (*newValue != 0) { \
    newValue = (SMALL_TYPE*) pointerDestroy(newValue); \
    printLog(ERR, "type%s->create did not initialize newValue to 0.\n", \
      #BIG_TYPE); \
    return false; \
  } \
  newValue = (SMALL_TYPE*) pointerDestroy(newValue); \
   \
  newValue = (SMALL_TYPE*) type##BIG_TYPE->copy(NULL); \
  if (newValue != NULL) { \
    printLog(ERR, "type%s->copy returned non-NULL pointer for NULL input.\n", \
      #BIG_TYPE); \
    return false; \
  } \
  newValue = (SMALL_TYPE*) type##BIG_TYPE->copy(&value1); \
  if (newValue == NULL) { \
    printLog(ERR, "type%s->copy failed.\n", #BIG_TYPE); \
    return false; \
  } \
  if (type##BIG_TYPE->compare(newValue, &value1) != 0) { \
    newValue = (SMALL_TYPE*) pointerDestroy(newValue); \
    printLog(ERR, "type%s->copy did not initialize newValue to %s.\n", \
      #BIG_TYPE, #MAX_VALUE); \
    return false; \
  } \
   \
  newValue = (SMALL_TYPE*) type##BIG_TYPE->destroy(newValue); \
  if (newValue != NULL) { \
    printLog(ERR, "Error in type%s->destroy.\n", #BIG_TYPE); \
    return false; \
  } \
   \
  if (type##BIG_TYPE->size(NULL) != 0) { \
    printLog(ERR, "type%s->size did not return 0 for NULL pointer.\n", \
      #BIG_TYPE); \
    return false; \
  } \
  if (type##BIG_TYPE->size(&value1) != SIZE) { \
    printLog(ERR, "type%s->size did not return %d for non-NULL pointer.\n", \
      #BIG_TYPE, SIZE); \
    return false; \
  } \
   \
  Bytes byteArray = type##BIG_TYPE->toBlob(NULL); \
  if (byteArray != NULL) { \
    printLog(ERR, "type%s->toBlob(NULL) did not return NULL.\n", \
      #BIG_TYPE); \
    return false; \
  } \
  byteArray = type##BIG_TYPE->toBlob(&value1); \
  if (byteArray == NULL) { \
    printLog(ERR, "type%s->toBlob(NULL) returned NULL for non-NULL input.\n", \
      #BIG_TYPE); \
    return false; \
  } \
  length = bytesLength(byteArray); \
  newValue = (SMALL_TYPE*) type##BIG_TYPE->fromBlob(byteArray, &length, false, false); \
  byteArray = bytesDestroy(byteArray); \
  if (newValue == NULL) { \
    printLog(ERR, "type%s->fromBlob returned NULL for non-NULL input.\n", \
      #BIG_TYPE); \
    return false; \
  } \
  if (type##BIG_TYPE->compare(newValue, &value1) != 0) { \
    printLog(ERR, "type%s->toBlob(&value1) did not yield a " \
      "pointer to a %s equal to value1.\n", #BIG_TYPE, #SMALL_TYPE); \
    char *valueString = type##BIG_TYPE->toString(&value1); \
    printLog(ERR, "value1 = %s\n", valueString); \
    valueString = stringDestroy(valueString); \
    valueString = type##BIG_TYPE->toString(newValue); \
    printLog(ERR, "newValue = %s\n", valueString); \
    valueString = stringDestroy(valueString); \
    printLog(ERR, "delta = %.80LF\n", (longDouble) (((longDouble) value1) - ((longDouble) *newValue))); \
    return false; \
  } \
  newValue = (SMALL_TYPE*) pointerDestroy(newValue); \
   \
  newValue = (SMALL_TYPE*) type##BIG_TYPE->fromBlob(NULL, NULL, false, false); \
  if (newValue != NULL) { \
    printLog(ERR, "type%s->fromBlob(NULL, NULL, false, false) did not return NULL.\n", \
      #BIG_TYPE); \
    return false; \
  } \
  newValue = (SMALL_TYPE*) type##BIG_TYPE->fromBlob(NULL, &length, false, false); \
  if (newValue != NULL) { \
    printLog(ERR, "type%s->fromBlob(NULL, &length, false, false) did not return " \
      "NULL.\n", #BIG_TYPE); \
    return false; \
  } \
  newValue = (SMALL_TYPE*) type##BIG_TYPE->fromBlob(&value1, NULL, false, false); \
  if (newValue != NULL) { \
    printLog(ERR, "type%s->fromBlob(&value1, NULL, false, false) did not return " \
      "NULL.\n", #BIG_TYPE); \
    return false; \
  } \
   \
  return true; \
}

#include <limits.h>
#include <float.h>
DATA_TYPE_UNIT_TEST(bool, Bool, false, true, 1)
DATA_TYPE_UNIT_TEST(u8, U8, 0, 255, 1)
DATA_TYPE_UNIT_TEST(u16, U16, 0, 65535, 2)
DATA_TYPE_UNIT_TEST(u32, U32, 0, 4294967295, 4)
DATA_TYPE_UNIT_TEST(u64, U64, 0, 4294967295, 8)
DATA_TYPE_UNIT_TEST(i8, I8, -128, 127, 1)
DATA_TYPE_UNIT_TEST(i16, I16, -32768, 32767, 2)
// Min value for i32 should be -2147483648, but this causes a compile error
// in Windows.
DATA_TYPE_UNIT_TEST(i32, I32, -2147483647, 2147483647, 4)
// Min value for i64 should be -2147483648, but this causes a compile error
// in Windows.
DATA_TYPE_UNIT_TEST(i64, I64, -2147483647, 2147483647, 8)
DATA_TYPE_UNIT_TEST(float, Float, 0, 3.140000, 4)
DATA_TYPE_UNIT_TEST(double, Double, 0, 3.140000, 8)
DATA_TYPE_UNIT_TEST(longDouble, LongDouble, 0, 3.140000, ((int) sizeof(long double)))

/// @def STRING_UNIT_TEST 
///
/// @brief Unit test for string functionality.
/// @details Implementing this as a macro instead of raw code allows this to
/// be skipped by the code coverage metrics.
///
/// @return Returns true on success, false on failure.
#define STRING_UNIT_TEST \
bool stringUnitTest() { \
  const char *value1 = "abcdefghijklmnopqrstuvwxyz" \
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ" \
    "0123456789"; \
  const char *value2 = ""; \
  char *string = NULL; \
  char *newValue = NULL; \
  u64 length = 0; \
   \
  if (!firstFourEq(NULL, NULL)) { \
    printLog(ERR, "firstFourEq(NULL, NULL) returned false.\n"); \
    return false; \
  } \
  if (!firstFourEq("", "")) { \
    printLog(ERR, "firstFourEq(\"\", \"\") returned false.\n"); \
    return false; \
  } \
  if (!firstFourEq("RUNNING", "RUNNING")) { \
    printLog(ERR, "firstFourEq(\"RUNNING\", \"RUNNING\") returned false.\n"); \
    return false; \
  } \
  if (firstFourEq("RUNNING", "PASS")) { \
    printLog(ERR, "firstFourEq(\"RUNNING\", \"PASS\") returned true.\n"); \
    return false; \
  } \
  if (firstFourEq(NULL, "PASS")) { \
    printLog(ERR, "firstFourEq(NULL, \"PASS\") returned true.\n"); \
    return false; \
  } \
  if (firstFourEq("", "PASS")) { \
    printLog(ERR, "firstFourEq(\"\", \"PASS\") returned true.\n"); \
    return false; \
  } \
  if (firstFourEq("RUNNING", NULL)) { \
    printLog(ERR, "firstFourEq(\"RUNNING\", NULL) returned true.\n"); \
    return false; \
  } \
  if (firstFourEq("RUNNING", "")) { \
    printLog(ERR, "firstFourEq(\"RUNNING\", \"\") returned true.\n"); \
    return false; \
  } \
   \
  string = typeString->toString(NULL); \
  if (strcmp(string, "(null)") != 0) { \
    printLog(ERR, "type%s->toString returned \"%s\" instead of \"%s\".\n", \
      "String", string, "(null)"); \
    string = stringDestroy(string); \
    return false; \
  } \
  string = stringDestroy(string); \
  string = typeString->toString(value1); \
  if (strcmp(string, value1) != 0) { \
    printLog(ERR, "type%s->toString returned \"%s\" instead of \"%s\".\n", \
      "String", string, value1); \
    string = stringDestroy(string); \
    return false; \
  } \
  string = stringDestroy(string); \
  string = typeString->toString(value2); \
  if (strcmp(string, value2) != 0) { \
    printLog(ERR, "type%s->toString returned \"%s\" instead of \"%s\".\n", \
      "String", string, value2); \
    string = stringDestroy(string); \
    return false; \
  } \
  string = stringDestroy(string); \
   \
  newValue = (char*) typeString->toBytes(value1); \
  if ((newValue == NULL) || (strcmp(newValue, value1) != 0)) { \
    printLog(ERR, "typeString->toBytes returned \"%s\" instead of \"%s\".\n", \
      newValue, value1); \
    newValue = (char*) typeBytes->destroy(newValue); \
    return false; \
  } \
  newValue = (char*) typeBytes->destroy(newValue); \
   \
  if (typeString->compare(value1, value1) != 0) { \
    printLog(ERR, "type%s->compare(%s, %s) did not return 0.\n", "String", \
      value1, value1); \
    return false; \
  } \
  if (typeString->compare(value2, value2) != 0) { \
    printLog(ERR, "type%s->compare(%s, %s) did not return 0.\n", "String", \
      value2, value2); \
    return false; \
  } \
  if (typeString->compare(value1, value2) <= 0) { \
    printLog(ERR, "type%s->compare(%s, %s) did not return 1.\n", "String", \
      value1, value2); \
    return false; \
  } \
  if (typeString->compare(value2, value1) >= 0) { \
    printLog(ERR, "type%s->compare(%s, %s) did not return -1.\n", "String", \
      value2, value1); \
    return false; \
  } \
  if (typeString->compare(value1, NULL) <= 0) { \
    printLog(ERR, "type%s->compare(%s, NULL) did not return 1.\n", "String", \
      value1); \
    return false; \
  } \
  if (typeString->compare(NULL, value1) >= 0) { \
    printLog(ERR, "type%s->compare(NULL, %s) did not return -1.\n", "String", \
      value1); \
    return false; \
  } \
   \
  newValue = (char*) typeString->create(NULL); \
  if (newValue == NULL) { \
    printLog(ERR, "type%s->create failed.\n", "String"); \
    return false; \
  } \
  if (*newValue != 0) { \
    newValue = stringDestroy(newValue); \
    printLog(ERR, "type%s->create did not initialize newValue to 0.\n", \
      "String"); \
    return false; \
  } \
  newValue = stringDestroy(newValue); \
   \
  newValue = (char*) typeString->copy(NULL); \
  if (newValue != NULL) { \
    printLog(ERR, "type%s->copy returned non-NULL pointer for NULL input.\n", \
      "String"); \
    return false; \
  } \
  newValue = (char*) typeString->copy(value1); \
  if (newValue == NULL) { \
    printLog(ERR, "type%s->copy failed.\n", "String"); \
    return false; \
  } \
  if (typeString->compare(newValue, value1) != 0) { \
    newValue = stringDestroy(newValue); \
    printLog(ERR, "type%s->copy did not initialize newValue to %s.\n", \
      "String", value1); \
    return false; \
  } \
   \
  newValue = (char*) typeString->destroy(newValue); \
  if (newValue != NULL) { \
    printLog(ERR, "Error in type%s->destroy.\n", "String"); \
    return false; \
  } \
   \
  if (typeString->size(NULL) != 0) { \
    printLog(ERR, "type%s->size did not return 0 for NULL pointer.\n", \
      "String"); \
    return false; \
  } \
  if (typeString->size(value1) != 63) { \
    printLog(ERR, "type%s->size did not return %d for non-NULL pointer.\n", \
      "String", 63); \
    return false; \
  } \
   \
  Bytes bytesValue = typeString->toBlob(NULL); \
  if (newValue != NULL) { \
    printLog(ERR, "type%s->toBlob(NULL) did not return NULL.\n", \
      "String"); \
    return false; \
  } \
  bytesValue = typeString->toBlob(value1); \
  length = bytesSize(bytesValue); \
  if (bytesValue == NULL) { \
    printLog(ERR, "type%s->toBlob returned NULL for non-NULL input.\n", \
      "String"); \
    return false; \
  } \
  if (typeString->compare(bytesValue, value1) != 0) { \
    printLog(ERR, "type%s->toBlob(&value1) did not yield a " \
      "pointer to a %s equal to value1.\n", "String", "string"); \
    return false; \
  } \
  if (length != 63) { \
    printLog(ERR, "type%s->toBlob(&value1) yielded a length of " \
      "%lld instead of %d.\n", "String", lld(length), 63); \
    return false; \
  } \
   \
  newValue = (char*) typeString->fromBlob(NULL, NULL, false, false); \
  if (newValue != NULL) { \
    printLog(ERR, "type%s->fromBlob(NULL, NULL, false, false) did not return NULL.\n", \
      "String"); \
    return false; \
  } \
  newValue = (char*) typeString->fromBlob(NULL, &length, false, false); \
  if (newValue != NULL) { \
    printLog(ERR, "type%s->fromBlob(NULL, &length, false, false) did not return " \
      "NULL.\n", "String"); \
    return false; \
  } \
  newValue = (char*) typeString->fromBlob(bytesValue, NULL, false, false); \
  if (newValue != NULL) { \
    printLog(ERR, "type%s->fromBlob(&value1, NULL, false, false) did not return " \
      "NULL.\n", "String"); \
    return false; \
  } \
  newValue = (char*) typeString->fromBlob(bytesValue, &length, false, false); \
  if (newValue == NULL) { \
    printLog(ERR, "type%s->fromBlob returned NULL for non-NULL input.\n", \
      "String"); \
    return false; \
  } \
  if (typeString->compare(newValue, value1) != 0) { \
    printLog(ERR, "type%s->fromBlob(&value1, &length, false, false) did not yield a " \
      "pointer to a %s equal to value1.\n", "String", "string"); \
    return false; \
  } \
  if (length != 63) { \
    printLog(ERR, "type%s->fromBlob(&value1, &length, false, false) did not yield a " \
      "length of %d.\n", "String", 63); \
    return false; \
  } \
  newValue = stringDestroy(newValue); \
  bytesValue = bytesDestroy(bytesValue); \
   \
  return true; \
}
STRING_UNIT_TEST

/// @def POINTER_UNIT_TEST 
///
/// @brief Unit test for pointer functionality.
/// @details Implementing this as a macro instead of raw code allows this to
/// be skipped by the code coverage metrics.
///
/// @return Returns true on success, false on failure.
#define POINTER_UNIT_TEST \
bool pointerUnitTest() { \
  const char *value1 = (const char*) 0xffffffffffffffff; \
  const char *value2 = (const char*) 0x1; \
  char *string = NULL; \
  char *newValue = NULL; \
  u64 length = 0; \
   \
  string = typePointerNoCopy->toString(NULL); \
  if (strcmp(string, "(nil)") != 0) { \
    printLog(ERR, "type%s->toString returned \"%s\" instead of \"%s\".\n", \
      "PointerNoCopy", string, "(nil)"); \
    string = stringDestroy(string); \
    return false; \
  } \
  string = stringDestroy(string); \
  string = typePointerNoCopy->toString(value1); \
  if ((strcmp(string, "0xffffffffffffffff") != 0) \
    && (strcmp(string, "0xffffffff") != 0)) \
  { \
    printLog(ERR, \
      "type%s->toString returned \"%s\" instead of \"%s\" or \"%s\".\n", \
      "PointerNoCopy", string, "0xffffffffffffffff", "0xffffffff"); \
    string = stringDestroy(string); \
    return false; \
  } \
  newValue = (char*) typePointerNoCopy->toBytes(value1); \
  if (strcmp(string, newValue) != 0) { \
    printLog(ERR, "typePointerNoCopy->toString returned \"%s\".\n", string); \
    printLog(ERR, "typePointerNoCopy->toBytes returned \"%s\".\n", newValue); \
    newValue = (char*) typeBytes->destroy(newValue); \
    string = stringDestroy(string); \
  } \
  newValue = (char*) typeBytes->destroy(newValue); \
  string = stringDestroy(string); \
  string = typePointerNoCopy->toString(value2); \
  if (strcmp(string, "0x1") != 0) { \
    printLog(ERR, "type%s->toString returned \"%s\" instead of \"%s\".\n", \
      "PointerNoCopy", string, "0x1"); \
    string = stringDestroy(string); \
    return false; \
  } \
  string = stringDestroy(string); \
   \
  if (typePointerNoCopy->compare(value1, value1) != 0) { \
    printLog(ERR, "type%s->compare(%s, %s) did not return 0.\n", \
      "PointerNoCopy", value1, value1); \
    return false; \
  } \
  if (typePointerNoCopy->compare(value2, value2) != 0) { \
    printLog(ERR, "type%s->compare(%s, %s) did not return 0.\n", \
      "PointerNoCopy", value2, value2); \
    return false; \
  } \
  if (typePointerNoCopy->compare(value1, value2) <= 0) { \
    printLog(ERR, "type%s->compare(%s, %s) did not return 1.\n", \
      "PointerNoCopy", value1, value2); \
    return false; \
  } \
  if (typePointerNoCopy->compare(value2, value1) >= 0) { \
    printLog(ERR, "type%s->compare(%s, %s) did not return -1.\n", \
      "PointerNoCopy", value2, value1); \
    return false; \
  } \
  if (typePointerNoCopy->compare(value1, NULL) <= 0) { \
    printLog(ERR, "type%s->compare(%s, NULL) did not return 1.\n", \
      "PointerNoCopy", value1); \
    return false; \
  } \
  if (typePointerNoCopy->compare(NULL, value1) >= 0) { \
    printLog(ERR, "type%s->compare(NULL, %s) did not return -1.\n", \
      "PointerNoCopy", value1); \
    return false; \
  } \
   \
  newValue = (char*) typePointerNoCopy->create(NULL); \
  if (newValue != NULL) { \
    printLog(ERR, "type%s->create failed.\n", "PointerNoCopy"); \
    return false; \
  } \
  newValue = stringDestroy(newValue); \
   \
  newValue = (char*) typePointerNoCopy->copy(NULL); \
  if (newValue != NULL) { \
    printLog(ERR, "type%s->copy returned non-NULL pointer for NULL input.\n", \
      "PointerNoCopy"); \
    return false; \
  } \
  newValue = (char*) typePointerNoCopy->copy(value1); \
  if (newValue == NULL) { \
    printLog(ERR, "type%s->copy failed.\n", "PointerNoCopy"); \
    return false; \
  } \
  if (typePointerNoCopy->compare(newValue, value1) != 0) { \
    newValue = stringDestroy(newValue); \
    printLog(ERR, "type%s->copy did not initialize newValue to %s.\n", \
      "PointerNoCopy", value1); \
    return false; \
  } \
   \
  newValue = (char*) typePointerNoCopy->destroy(newValue); \
  if (newValue != NULL) { \
    printLog(ERR, "Error in type%s->destroy.\n", "PointerNoCopy"); \
    return false; \
  } \
   \
  if (typePointerNoCopy->size(NULL) != 0) { \
    printLog(ERR, "type%s->size did not return 0 for NULL pointer.\n", \
      "PointerNoCopy"); \
    return false; \
  } \
  if (typePointerNoCopy->size(value1) != 0) { \
    printLog(ERR, "type%s->size did not return 0 for non-NULL pointer.\n", \
      "PointerNoCopy"); \
    return false; \
  } \
   \
  Bytes byteArray = typePointerNoCopy->toBlob(NULL); \
  if (byteArray != NULL) { \
    printLog(ERR, "type%s->toBlob(NULL) did not return NULL.\n", \
      "PointerNoCopy"); \
    return false; \
  } \
  byteArray = typePointerNoCopy->toBlob(value1); \
  length = bytesLength(byteArray); \
  if (byteArray == NULL) { \
    printLog(ERR, "type%s->toBlob returned NULL value.\n", \
      "PointerNoCopy"); \
    return false; \
  } \
  newValue = stringDestroy(newValue); \
  if ((length != 8) && (length != 4)) { \
    printLog(ERR, \
      "type%s->toBlob(&value1) yielded a length of %llu " \
      "instead of 8 or 4.\n", "PointerNoCopy", llu(length)); \
    return false; \
  } \
   \
  newValue = (char*) typePointerNoCopy->fromBlob(NULL, NULL, false, false); \
  if (newValue != NULL) { \
    printLog(ERR, "type%s->fromBlob(NULL, NULL, false, false) did not return NULL.\n", \
      "PointerNoCopy"); \
    return false; \
  } \
  newValue = (char*) typePointerNoCopy->fromBlob(NULL, &length, false, false); \
  if (newValue != NULL) { \
    printLog(ERR, "type%s->fromBlob(NULL, &length, false, false) did not return " \
      "NULL.\n", "PointerNoCopy"); \
    return false; \
  } \
  newValue = (char*) typePointerNoCopy->fromBlob(byteArray, NULL, false, false); \
  if (newValue != NULL) { \
    printLog(ERR, "type%s->fromBlob(&value1, NULL, false, false) did not return " \
      "NULL.\n", "PointerNoCopy"); \
    return false; \
  } \
  newValue = (char*) typePointerNoCopy->fromBlob(byteArray, &length, false, false); \
  if (newValue == NULL) { \
    printLog(ERR, "type%s->fromBlob returned NULL value.\n", \
      "PointerNoCopy"); \
    return false; \
  } \
  if ((length != 8) && (length != 4)) { \
    printLog(ERR, \
      "type%s->fromBlob(&value1, &length, false, false) yielded a length of %llu " \
      "instead of 8 or 4.\n", "PointerNoCopy", llu(length)); \
    return false; \
  } \
  byteArray = bytesDestroy(byteArray); \
  /* value returned is a true pointer (to an invalid memory location) and */ \
  /* cannot be free'd */ \
   \
  return true; \
}
POINTER_UNIT_TEST

/// @def BYTES_UNIT_TEST 
///
/// @brief Unit test for Bytes functionality.
/// @details Implementing this as a macro instead of raw code allows this to
/// be skipped by the code coverage metrics.
///
/// @return Returns true on success, false on failure.
#define BYTES_UNIT_TEST \
bool bytesUnitTest() { \
  const char *value1 = "abcdefghijklmnopqrstuvwxyz" \
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ" \
    "0123456789"; \
  const char *value2 = ""; \
  Bytes bytesValue1 = NULL; \
  bytesAddStr(&bytesValue1, value1); \
  Bytes bytesValue2 = (Bytes) typeBytes->create(value2, llu(strlen(value2))); \
  char *string = NULL; \
  char *newValue = NULL; \
  u64 length = 0; \
   \
  if (bytesLength(bytesValue1) != strlen(value1)) { \
    printLog(ERR, "bytesLength(bytesValue1) = %llu, expected %llu.\n", \
      llu(bytesLength(bytesValue1)), llu(strlen(value1)) + 1); \
    return false; \
  } \
   \
  if (bytesLength(bytesValue2) != (strlen(value2))) { \
    printLog(ERR, "bytesLength(bytesValue2) = %llu, expected %llu.\n", \
      llu(bytesLength(bytesValue2)), llu(strlen(value2))); \
    return false; \
  } \
   \
  string = typeBytes->toString(NULL); \
  if (strcmp(string, "") != 0) { \
    printLog(ERR, "type%s->toString returned \"%s\" instead of \"%s\".\n", \
      "Bytes", string, "(null)"); \
    string = stringDestroy(string); \
    return false; \
  } \
  newValue = (char*) typeBytes->toBytes(NULL); \
  if (newValue != NULL) { \
    printLog(ERR, "type%s->toBytes returned \"%s\" instead of NULL.\n", \
      "Bytes", newValue); \
    newValue = (char*) typeBytes->destroy(newValue); \
    return false; \
  } \
  string = stringDestroy(string); \
  string = typeBytes->toString(bytesValue1); \
  if (strncmp(string, value1, strlen(value1)) != 0) { \
    printLog(ERR, "type%s->toString returned \"%s\" instead of \"%s\".\n", \
      "Bytes", string, value1); \
    string = stringDestroy(string); \
    return false; \
  } \
  newValue = (char*) typeBytes->toBytes(bytesValue1); \
  if (typeBytes->compare(newValue, bytesValue1) != 0) { \
    printLog(ERR, "type%s->toBytes returned \"%s\" instead of \"%s\".\n", \
      "Bytes", newValue, (char*) bytesValue1); \
    newValue = (char*) typeBytes->destroy(newValue); \
    return false; \
  } \
  if (strcmp(string, newValue) != 0) { \
    printLog(ERR, \
      "typeBytes->toString returned \"%s\", typeBytes->toBytes returned \"%s\".\n", \
      string, newValue); \
    string = stringDestroy(string); \
    newValue = (char*) typeBytes->destroy(newValue); \
    return false; \
  } \
  string = stringDestroy(string); \
  newValue = (char*) typeBytes->destroy(newValue); \
  string = typeBytes->toString(bytesValue2); \
  if (strcmp(string, value2) != 0) { \
    printLog(ERR, "type%s->toString returned \"%s\" instead of \"%s\".\n", \
      "Bytes", string, bytesValue2); \
    string = stringDestroy(string); \
    return false; \
  } \
  string = stringDestroy(string); \
  newValue = (char*) typeBytes->toBytes(bytesValue2); \
  if (typeBytes->compare(newValue, bytesValue2) != 0) { \
    printLog(ERR, "type%s->toBytes returned \"%s\" instead of \"%s\".\n", \
      "Bytes", newValue, (char*) bytesValue2); \
    newValue = (char*) typeBytes->destroy(newValue); \
    return false; \
  } \
  newValue = (char*) typeBytes->destroy(newValue); \
   \
  if (typeBytes->compare(bytesValue1, bytesValue1) != 0) { \
    printLog(ERR, "type%s->compare(%s, %s) did not return 0.\n", "Bytes", \
      bytesValue1, bytesValue1); \
    return false; \
  } \
  if (typeBytes->compare(bytesValue2, bytesValue2) != 0) { \
    printLog(ERR, "type%s->compare(%s, %s) did not return 0.\n", "Bytes", \
      bytesValue2, bytesValue2); \
    return false; \
  } \
  if (typeBytes->compare(bytesValue1, bytesValue2) <= 0) { \
    printLog(ERR, "type%s->compare(%s, %s) did not return 1.\n", "Bytes", \
      bytesValue1, bytesValue2); \
    return false; \
  } \
  if (typeBytes->compare(bytesValue2, bytesValue1) >= 0) { \
    printLog(ERR, "type%s->compare(%s, %s) did not return -1.\n", "Bytes", \
      bytesValue2, bytesValue1); \
    return false; \
  } \
  if (typeBytes->compare(bytesValue1, NULL) <= 0) { \
    printLog(ERR, "type%s->compare(%s, NULL) did not return 1.\n", "Bytes", \
      bytesValue1); \
    return false; \
  } \
  if (typeBytes->compare(NULL, bytesValue1) >= 0) { \
    printLog(ERR, "type%s->compare(NULL, %s) did not return -1.\n", "Bytes", \
      bytesValue1); \
    return false; \
  } \
   \
  newValue = (char*) typeBytes->create(NULL); \
  if (newValue != NULL) { \
    printLog(ERR, "type%s->create failed.\n", "Bytes"); \
    return false; \
  } \
  newValue = (char*) typeBytes->destroy(newValue); \
   \
  newValue = (char*) typeBytes->copy(NULL); \
  if (newValue != NULL) { \
    printLog(ERR, "type%s->copy returned non-NULL pointer for NULL input.\n", \
      "Bytes"); \
    return false; \
  } \
  newValue = (char*) typeBytes->copy(bytesValue1); \
  if (newValue == NULL) { \
    printLog(ERR, "type%s->copy failed.\n", "Bytes"); \
    return false; \
  } \
  if (typeBytes->compare(newValue, bytesValue1) != 0) { \
    newValue = stringDestroy(newValue); \
    printLog(ERR, "type%s->copy did not initialize newValue to %s.\n", \
      "Bytes", bytesValue1); \
    return false; \
  } \
   \
  newValue = (char*) typeBytes->destroy(newValue); \
  if (newValue != NULL) { \
    printLog(ERR, "Error in type%s->destroy.\n", "Bytes"); \
    return false; \
  } \
   \
  if (typeBytes->size(NULL) != 0) { \
    printLog(ERR, "type%s->size did not return 0 for NULL pointer.\n", \
      "Bytes"); \
    return false; \
  } \
  if (typeBytes->size(bytesValue1) != strlen(value1)) { \
    printLog(ERR, "type%s->size did not return %d for non-NULL pointer.\n", \
      "Bytes", 63); \
    return false; \
  } \
   \
  Bytes byteArray = typeBytes->toBlob(NULL); \
  if (byteArray != NULL) { \
    printLog(ERR, "type%s->toBlob(NULL) did not return NULL.\n", \
      "Bytes"); \
    return false; \
  } \
  byteArray = typeBytes->toBlob(bytesValue1); \
  if (byteArray == NULL) { \
    printLog(ERR, "type%s->toBlob returned NULL for non-NULL input.\n", \
      "Bytes"); \
    return false; \
  } \
  length = bytesLength(byteArray); \
  if (length != 63 + sizeof(BytesHeader)) { \
    printLog(ERR, "type%s->toBlob(&bytesValue1) yielded a " \
      "length of %llu instead of %llu.\n", \
      "Bytes", llu(length), llu(63 + sizeof(BytesHeader))); \
    return false; \
  } \
  if (strncmp(str(byteArray + sizeof(BytesHeader)), value1, strlen(value1)) != 0) { \
    printLog(ERR, "type%s->toBlob(&bytesValue1) did not yield " \
      "\"%s\".\n", "Bytes", value1); \
    return false; \
  } \
   \
  char *newValue2 = (char*) typeBytes->fromBlob(NULL, NULL, false, false); \
  if (newValue2 != NULL) { \
    printLog(ERR, "type%s->fromBlob(NULL, NULL, false, false) did not return NULL.\n", \
      "Bytes"); \
    return false; \
  } \
  newValue2 = (char*) typeBytes->fromBlob(NULL, &length, false, false); \
  if (newValue2 != NULL) { \
    printLog(ERR, "type%s->fromBlob(NULL, &length, false, false) did not return " \
      "NULL.\n", "Bytes"); \
    return false; \
  } \
  newValue2 = (char*) typeBytes->fromBlob(byteArray, NULL, false, false); \
  if (newValue2 != NULL) { \
    printLog(ERR, "type%s->fromBlob(newValue, NULL, false, false) did not return " \
      "NULL.\n", "Bytes"); \
    return false; \
  } \
  newValue2 = (char*) typeBytes->fromBlob(byteArray, &length, false, false); \
  if (newValue2 == NULL) { \
    printLog(ERR, \
      "type%s->fromBlob(newValue, &length, false, false) returned NULL for non-NULL input.\n", \
      "Bytes"); \
    return false; \
  } \
  if (length != 63 + sizeof(BytesHeader)) { \
    printLog(ERR, "type%s->fromBlob(newValue, &length, false, false) yielded a " \
      "length of %llu instead of %llu.\n", "Bytes", \
      llu(length), llu(63 + sizeof(BytesHeader))); \
    return false; \
  } \
  if (typeBytes->compare(bytesValue1, newValue2) != 0) { \
    printLog(ERR, "type%s->fromBlob(newValue, &length, false, false) did not yield a " \
      "pointer to %s equal to bytesValue1.\n", "Bytes", "bytes"); \
    return false; \
  } \
  byteArray = bytesDestroy(byteArray); \
  newValue2 = (char*) typeBytes->destroy(newValue2); \
   \
  bytesAddData(&bytesValue1, "", 1); \
  printLog(DEBUG, "bytesValue1 = \"%s\"\n", (char*) bytesValue1); \
  bytesValue1 = (Bytes) typeBytes->destroy(bytesValue1); \
  bytesValue2 = (Bytes) typeBytes->destroy(bytesValue2); \
  return true; \
}
BYTES_UNIT_TEST

bool structUnitTest() {
  typedef struct Struct1 {
    i32 myInt;
    double myDouble;
  } Struct1;
  
  typedef struct Struct2 {
    float myFloat;
    i16 myShort;
    Struct1 myStruct;
  } Struct2;
  
  ZEROINIT(Struct1 struct1[2]);
  ZEROINIT(Struct2 struct2[2]);
  
  if (structcmp(struct1[0], struct1[1]) != 0) {
    printLog(ERR, "structcmp(struct1[0], struct1[1]) returned non-equal.\n");
    return false;
  }
  
  if (structcmp(struct2[0], struct2[1]) != 0) {
    printLog(ERR, "structcmp(struct2[0], struct2[1]) returned non-equal.\n");
    return false;
  }
  
  if (structcmp(struct1[0], struct2[0]) == 0) {
    printLog(ERR, "structcmp(struct1[0], struct2[0]) returned equal.\n");
    return false;
  }
  
  struct1[0].myInt = 1;
  if (structcmp(struct1[0], struct1[1]) == 0) {
    printLog(ERR, "structcmp(struct1[0], struct1[1]) returned equal.\n");
    return false;
  }
  
  struct1[1].myInt = 1;
  if (structcmp(struct1[0], struct1[1]) != 0) {
    printLog(ERR, "structcmp(struct1[0], struct1[1]) returned non-equal.\n");
    return false;
  }
  
  struct2[0].myStruct.myInt = 1;
  if (structcmp(struct2[0], struct2[1]) == 0) {
    printLog(ERR, "structcmp(struct2[0], struct2[1]) returned equal.\n");
    return false;
  }
  
  struct2[1].myStruct.myInt = 1;
  if (structcmp(struct2[0], struct2[1]) != 0) {
    printLog(ERR, "structcmp(struct2[0], struct2[1]) returned non-equal.\n");
    return false;
  }
  
  return true;
}

#include "Scope.h"
bool valueToStringUnitTest() {
  scopeBegin(MAX_SCOPE_VARS);
  
  bool boolValue = true;
  i8 i8Value = 1;
  u8 u8Value = 1;
  i16 i16Value = 1;
  u16 u16Value = 1;
  i32 i32Value = 1;
  u32 u32Value = 1;
  i64 i64Value = 1;
  u64 u64Value = 1;
  float floatValue = 1.0;
  double doubleValue = 1.0;
  long double longDoubleValue = 1.0;
  ZEROINIT(List listValue);
  ZEROINIT(Queue queueValue);
  ZEROINIT(Stack stackValue);
  ZEROINIT(RedBlackTree redBlackTreeValue);
  ZEROINIT(HashTable hashTableValue);
  ZEROINIT(Vector vectorValue);
  
  char *stringValue = NULL;
  
  stringValue = 
    str(scopeAdd(valueToString(boolValue), pointerDestroyFunction));
  printLog(INFO, "valueToString(boolValue) = %s\n", stringValue);
  stringValue = 
    str(scopeAdd(valueToString(i8Value), pointerDestroyFunction));
  printLog(INFO, "valueToString(i8Value) = %s\n", stringValue);
  stringValue = 
    str(scopeAdd(valueToString(u8Value), pointerDestroyFunction));
  printLog(INFO, "valueToString(u8Value) = %s\n", stringValue);
  stringValue = 
    str(scopeAdd(valueToString(i16Value), pointerDestroyFunction));
  printLog(INFO, "valueToString(i16Value) = %s\n", stringValue);
  stringValue = 
    str(scopeAdd(valueToString(u16Value), pointerDestroyFunction));
  printLog(INFO, "valueToString(u16Value) = %s\n", stringValue);
  stringValue = 
    str(scopeAdd(valueToString(i32Value), pointerDestroyFunction));
  printLog(INFO, "valueToString(i32Value) = %s\n", stringValue);
  stringValue = 
    str(scopeAdd(valueToString(u32Value), pointerDestroyFunction));
  printLog(INFO, "valueToString(u32Value) = %s\n", stringValue);
  stringValue = 
    str(scopeAdd(valueToString(i64Value), pointerDestroyFunction));
  printLog(INFO, "valueToString(i64Value) = %s\n", stringValue);
  stringValue = 
    str(scopeAdd(valueToString(u64Value), pointerDestroyFunction));
  printLog(INFO, "valueToString(u64Value) = %s\n", stringValue);
  stringValue = 
    str(scopeAdd(valueToString(floatValue), pointerDestroyFunction));
  printLog(INFO, "valueToString(floatValue) = %s\n", stringValue);
  stringValue = 
    str(scopeAdd(valueToString(doubleValue), pointerDestroyFunction));
  printLog(INFO, "valueToString(doubleValue) = %s\n", stringValue);
  stringValue = 
    str(scopeAdd(valueToString(longDoubleValue), pointerDestroyFunction));
  printLog(INFO, "valueToString(longDoubleValue) = %s\n", stringValue);
  stringValue = 
    str(scopeAdd(valueToString(listValue), pointerDestroyFunction));
  printLog(INFO, "valueToString(listValue) = %s\n", stringValue);
  stringValue = 
    str(scopeAdd(valueToString(queueValue), pointerDestroyFunction));
  printLog(INFO, "valueToString(queueValue) = %s\n", stringValue);
  stringValue = 
    str(scopeAdd(valueToString(stackValue), pointerDestroyFunction));
  printLog(INFO, "valueToString(stackValue) = %s\n", stringValue);
  stringValue = 
    str(scopeAdd(valueToString(redBlackTreeValue), pointerDestroyFunction));
  printLog(INFO, "valueToString(redBlackTreeValue) = %s\n", stringValue);
  stringValue = 
    str(scopeAdd(valueToString(hashTableValue), pointerDestroyFunction));
  printLog(INFO, "valueToString(hashTableValue) = %s\n", stringValue);
  stringValue = 
    str(scopeAdd(valueToString(vectorValue), pointerDestroyFunction));
  printLog(INFO, "valueToString(vectorValue) = %s\n", stringValue);
  
  (void) stringValue;
  
  scopeEnd();
  return true;
}

