#include "DataTypes.h"
#include "LoggingLib.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

///
/// @brief Comprehensive unit test for DataTypes.h functions and macros
///
/// @return Returns true if all tests pass, false if any test fails
///
bool dataTypesUnitTest(void) {
  printLog(DEBUG, "Starting DataTypes unit tests\n");
  
  bool allTestsPassed = true;
  
  // Test string validation functions
  printLog(DEBUG, "Testing string validation functions\n");
  
  // Test stringIsInteger
  if (!stringIsInteger("123")) {
    printLog(ERR, "stringIsInteger failed for valid integer\n");
    allTestsPassed = false;
  }
  if (!stringIsInteger("-456")) {
    printLog(ERR, "stringIsInteger failed for negative integer\n");
    allTestsPassed = false;
  }
  if (stringIsInteger("123.45")) {
    printLog(ERR, "stringIsInteger incorrectly accepted float\n");
    allTestsPassed = false;
  }
  if (stringIsInteger("abc")) {
    printLog(ERR, "stringIsInteger incorrectly accepted non-numeric string\n");
    allTestsPassed = false;
  }
  if (stringIsInteger(NULL)) {
    printLog(ERR, "stringIsInteger incorrectly accepted NULL\n");
    allTestsPassed = false;
  }
  if (stringIsInteger("")) {
    printLog(ERR, "stringIsInteger incorrectly accepted empty string\n");
    allTestsPassed = false;
  }
  
  // Test stringIsFloat
  if (!stringIsFloat("123.45")) {
    printLog(ERR, "stringIsFloat failed for valid float\n");
    allTestsPassed = false;
  }
  if (!stringIsFloat("-67.89")) {
    printLog(ERR, "stringIsFloat failed for negative float\n");
    allTestsPassed = false;
  }
  if (!stringIsFloat("1.23e-4")) {
    printLog(ERR, "stringIsFloat failed for scientific notation\n");
    allTestsPassed = false;
  }
  if (stringIsFloat("abc")) {
    printLog(ERR, "stringIsFloat incorrectly accepted non-numeric string\n");
    allTestsPassed = false;
  }
  if (stringIsFloat(NULL)) {
    printLog(ERR, "stringIsFloat incorrectly accepted NULL\n");
    allTestsPassed = false;
  }
  
  // Test stringIsNumber
  if (!stringIsNumber("123")) {
    printLog(ERR, "stringIsNumber failed for integer\n");
    allTestsPassed = false;
  }
  if (!stringIsNumber("123.45")) {
    printLog(ERR, "stringIsNumber failed for float\n");
    allTestsPassed = false;
  }
  if (stringIsNumber("abc")) {
    printLog(ERR, "stringIsNumber incorrectly accepted non-numeric string\n");
    allTestsPassed = false;
  }
  if (stringIsNumber(NULL)) {
    printLog(ERR, "stringIsNumber incorrectly accepted NULL\n");
    allTestsPassed = false;
  }
  
  // Test stringIsBoolean
  if (!stringIsBoolean("true")) {
    printLog(ERR, "stringIsBoolean failed for 'true'\n");
    allTestsPassed = false;
  }
  if (!stringIsBoolean("false")) {
    printLog(ERR, "stringIsBoolean failed for 'false'\n");
    allTestsPassed = false;
  }
  if (stringIsBoolean("maybe")) {
    printLog(ERR, "stringIsBoolean incorrectly accepted invalid boolean\n");
    allTestsPassed = false;
  }
  if (stringIsBoolean(NULL)) {
    printLog(ERR, "stringIsBoolean incorrectly accepted NULL\n");
    allTestsPassed = false;
  }
  
  // Test strtobool
  char *endPtr = NULL;
  if (!strtobool("true", &endPtr)) {
    printLog(ERR, "strtobool failed for 'true'\n");
    allTestsPassed = false;
  }
  if (strtobool("false", &endPtr)) {
    printLog(ERR, "strtobool failed for 'false'\n");
    allTestsPassed = false;
  }
  if (strtobool(NULL, &endPtr)) {
    printLog(ERR, "strtobool incorrectly accepted NULL\n");
    allTestsPassed = false;
  }
  
  // Test utility functions
  printLog(DEBUG, "Testing utility functions\n");
  
  // Test shallowCopy
  int testValue = 42;
  void *copiedValue = shallowCopy(&testValue);
  if (copiedValue == NULL) {
    printLog(ERR, "shallowCopy failed for valid input\n");
    allTestsPassed = false;
  }
  if (shallowCopy(NULL) != NULL) {
    printLog(ERR, "shallowCopy should return NULL for NULL input\n");
    allTestsPassed = false;
  }
  
  // Test nullFunction
  if (nullFunction(NULL) != NULL) {
    printLog(ERR, "nullFunction should return NULL\n");
    allTestsPassed = false;
  }
  if (nullFunction(&testValue) != NULL) {
    printLog(ERR, "nullFunction should return NULL for any input\n");
    allTestsPassed = false;
  }
  
  // Test clearNull
  if (clearNull(NULL) != 0) {
    printLog(ERR, "clearNull should return 0 for NULL input\n");
    allTestsPassed = false;
  }
  if (clearNull(&testValue) != 0) {
    printLog(ERR, "clearNull should return 0 for any input\n");
    allTestsPassed = false;
  }
  
  // Test type descriptor functions
  printLog(DEBUG, "Testing type descriptor functions\n");
  
  // Test getIndexFromTypeDescriptor
  i64 index = getIndexFromTypeDescriptor(typeBool);
  if (index < 0 || index >= NUM_TYPE_DESCRIPTOR_INDEXES) {
    printLog(ERR, "getIndexFromTypeDescriptor returned invalid index\n");
    allTestsPassed = false;
  }
  if (getIndexFromTypeDescriptor(NULL) >= 0) {
    printLog(ERR, "getIndexFromTypeDescriptor should return negative for NULL\n");
    allTestsPassed = false;
  }
  
  // Test getNumTypeDescriptors
  u64 numDescriptors = getNumTypeDescriptors();
  if (numDescriptors == 0) {
    printLog(ERR, "getNumTypeDescriptors should return non-zero count\n");
    allTestsPassed = false;
  }
  
  // Test getTypeDescriptorFromIndex
  TypeDescriptor *typeDesc = getTypeDescriptorFromIndex(TYPE_BOOL);
  if (typeDesc == NULL) {
    printLog(ERR, "getTypeDescriptorFromIndex failed for valid index\n");
    allTestsPassed = false;
  }
  if (getTypeDescriptorFromIndex(-1) != NULL) {
    printLog(ERR, "getTypeDescriptorFromIndex should return NULL for invalid index\n");
    allTestsPassed = false;
  }
  if (getTypeDescriptorFromIndex(NUM_TYPE_DESCRIPTOR_INDEXES) != NULL) {
    printLog(ERR, "getTypeDescriptorFromIndex should return NULL for out-of-bounds index\n");
    allTestsPassed = false;
  }
  
  // Test pointer functions
  printLog(DEBUG, "Testing pointer functions\n");
  
  // Test pointerDestroyFunction
  int *testPtr = (int*) malloc(sizeof(int));
  if (testPtr != NULL) {
    *testPtr = 123;
    void *result = pointerDestroyFunction(testPtr);
    if (result != NULL) {
      printLog(ERR, "pointerDestroyFunction should return NULL\n");
      allTestsPassed = false;
    }
  }
  if (pointerDestroyFunction(NULL) != NULL) {
    printLog(ERR, "pointerDestroyFunction should return NULL for NULL input\n");
    allTestsPassed = false;
  }
  
  // Test pointerToString
  int testInt = 42;
  char *stringResult = pointerToString(&testInt);
  if (stringResult == NULL) {
    printLog(ERR, "pointerToString failed for valid pointer\n");
    allTestsPassed = false;
  } else {
    free(stringResult);
  }
  stringResult = pointerToString(NULL);
  if (stringResult == NULL) {
    printLog(ERR, "pointerToString should handle NULL input\n");
    allTestsPassed = false;
  } else {
    free(stringResult);
  }
  
  // Test pointerToBytes
  Bytes bytesResult = pointerToBytes(&testInt);
  if (bytesResult == NULL) {
    printLog(ERR, "pointerToBytes failed for valid pointer\n");
    allTestsPassed = false;
  }
  bytesResult = bytesDestroy(bytesResult);
  
  // Test pointerCompare
  int *valueA = (int*) 10;
  int *valueB = (int*) 20;
  
  int compareResult = pointerCompare(valueA, valueB);
  if (compareResult >= 0) {
    printLog(ERR, "pointerCompare failed: should be negative\n");
    allTestsPassed = false;
  }
  
  compareResult = pointerCompare(valueB, valueA);
  if (compareResult <= 0) {
    printLog(ERR, "pointerCompare failed: should be positive\n");
    allTestsPassed = false;
  }
  
  if (pointerCompare(NULL, valueA) == 0) {
    printLog(ERR, "pointerCompare should handle NULL first parameter\n");
    allTestsPassed = false;
  }
  
  if (pointerCompare(valueA, NULL) == 0) {
    printLog(ERR, "pointerCompare should handle NULL second parameter\n");
    allTestsPassed = false;
  }
  
  // Test pointerToBlob
  Bytes blobResult = pointerToBlob(&testInt);
  if (blobResult == NULL) {
    printLog(ERR, "pointerToBlob failed for valid pointer\n");
    allTestsPassed = false;
  }
  
  // Test pointerFromBlob
  if (blobResult != NULL) {
    u64 length = bytesLength(blobResult);
    void *fromBlobResult = pointerFromBlob(blobResult, &length, false, false);
    if (fromBlobResult == NULL) {
      printLog(ERR, "pointerFromBlob failed for valid blob\n");
      allTestsPassed = false;
    }
  }
  blobResult = bytesDestroy(blobResult);
  
  if (pointerFromBlob(NULL, NULL, false, false) != NULL) {
    printLog(ERR, "pointerFromBlob should handle NULL input\n");
    allTestsPassed = false;
  }
  
  // Test endianness functions
  printLog(DEBUG, "Testing endianness functions\n");
  
  // Test byteSwapIfNotLittleEndian
  u32 testEndianValue = 0x12345678;
  u32 originalValue = testEndianValue;
  int swapResult = byteSwapIfNotLittleEndian(&testEndianValue, sizeof(u32));
  if (swapResult < 0) {
    printLog(ERR, "byteSwapIfNotLittleEndian failed\n");
    allTestsPassed = false;
  }
  
  if (byteSwapIfNotLittleEndian(NULL, sizeof(u32)) >= 0) {
    printLog(ERR, "byteSwapIfNotLittleEndian should fail for NULL input\n");
    allTestsPassed = false;
  }
  
  // Test byteSwapIfNotBigEndian
  testEndianValue = originalValue;
  swapResult = byteSwapIfNotBigEndian(&testEndianValue, sizeof(u32));
  if (swapResult < 0) {
    printLog(ERR, "byteSwapIfNotBigEndian failed\n");
    allTestsPassed = false;
  }
  
  if (byteSwapIfNotBigEndian(NULL, sizeof(u32)) >= 0) {
    printLog(ERR, "byteSwapIfNotBigEndian should fail for NULL input\n");
    allTestsPassed = false;
  }
  
  // Test endianness macros
  u16 testU16 = 0x1234;
  u16 originalU16 = testU16;
  
  hostToLittleEndian(&testU16, sizeof(u16));
  // Value should be in little endian format now
  
  littleEndianToHost(&testU16, sizeof(u16));
  // Value should be back to host format
  
  testU16 = originalU16;
  hostToBigEndian(&testU16, sizeof(u16));
  // Value should be in big endian format now
  
  bigEndianToHost(&testU16, sizeof(u16));
  // Value should be back to host format
  
  // Test HOST_IS_LITTLE_ENDIAN macro
  printLog(DEBUG, "Host is %s endian\n", 
    HOST_IS_LITTLE_ENDIAN ? "little" : "big");
  
  // Test reverseMemory macro
  printLog(DEBUG, "Testing reverseMemory macro\n");
  
  char testArray[] = "abcdef";
  reverseMemory(testArray, strlen(testArray));
  if (strcmp(testArray, "fedcba") != 0) {
    printLog(ERR, "reverseMemory macro failed\n");
    allTestsPassed = false;
  }
  
  // Test with single character (edge case)
  char singleChar = 'x';
  reverseMemory(&singleChar, 1);
  if (singleChar != 'x') {
    printLog(ERR, "reverseMemory failed for single character\n");
    allTestsPassed = false;
  }
  
  // Test with empty array (edge case)
  reverseMemory(testArray, 0);
  // Should not crash and should not change anything
  
  // Test stringIsTrue macro
  printLog(DEBUG, "Testing stringIsTrue macro\n");
  
  if (!stringIsTrue("true")) {
    printLog(ERR, "stringIsTrue macro failed for 'true'\n");
    allTestsPassed = false;
  }
  
  if (stringIsTrue("false")) {
    printLog(ERR, "stringIsTrue macro incorrectly accepted 'false'\n");
    allTestsPassed = false;
  }
  
  if (stringIsTrue("True")) {
    printLog(ERR, "stringIsTrue macro should be case sensitive\n");
    allTestsPassed = false;
  }
  
  if (stringIsTrue(NULL)) {
    printLog(ERR, "stringIsTrue macro should handle NULL\n");
    allTestsPassed = false;
  }
  
  if (stringIsTrue("")) {
    printLog(ERR, "stringIsTrue macro should handle empty string\n");
    allTestsPassed = false;
  }
  
  // Test literal macro
  printLog(DEBUG, "Testing literal macro\n");
  
  REGISTER_INT literalValue = literal(12345);
  if (literalValue != 12345) {
    printLog(ERR, "literal macro failed\n");
    allTestsPassed = false;
  }
  
  // Test zero constants
  printLog(DEBUG, "Testing zero constants\n");
  
  if (boolZero != false) {
    printLog(ERR, "boolZero constant is incorrect\n");
    allTestsPassed = false;
  }
  
  if (i8Zero != 0) {
    printLog(ERR, "i8Zero constant is incorrect\n");
    allTestsPassed = false;
  }
  
  if (u8Zero != 0) {
    printLog(ERR, "u8Zero constant is incorrect\n");
    allTestsPassed = false;
  }
  
  if (i16Zero != 0) {
    printLog(ERR, "i16Zero constant is incorrect\n");
    allTestsPassed = false;
  }
  
  if (u16Zero != 0) {
    printLog(ERR, "u16Zero constant is incorrect\n");
    allTestsPassed = false;
  }
  
  if (i32Zero != 0) {
    printLog(ERR, "i32Zero constant is incorrect\n");
    allTestsPassed = false;
  }
  
  if (u32Zero != 0) {
    printLog(ERR, "u32Zero constant is incorrect\n");
    allTestsPassed = false;
  }
  
  if (i64Zero != 0) {
    printLog(ERR, "i64Zero constant is incorrect\n");
    allTestsPassed = false;
  }
  
  if (u64Zero != 0) {
    printLog(ERR, "u64Zero constant is incorrect\n");
    allTestsPassed = false;
  }
  
  if (floatZero != 0.0f) {
    printLog(ERR, "floatZero constant is incorrect\n");
    allTestsPassed = false;
  }
  
  if (doubleZero != 0.0) {
    printLog(ERR, "doubleZero constant is incorrect\n");
    allTestsPassed = false;
  }
  
  if (longDoubleZero != 0.0L) {
    printLog(ERR, "longDoubleZero constant is incorrect\n");
    allTestsPassed = false;
  }
  
  // Test boolNames array
  if (boolNames[0] == NULL || boolNames[1] == NULL) {
    printLog(ERR, "boolNames array contains NULL values\n");
    allTestsPassed = false;
  }
  
  if (strcmp(boolNames[0], "false") != 0) {
    printLog(ERR, "boolNames[0] should be 'false'\n");
    allTestsPassed = false;
  }
  
  if (strcmp(boolNames[1], "true") != 0) {
    printLog(ERR, "boolNames[1] should be 'true'\n");
    allTestsPassed = false;
  }
  
  // Test all type descriptors exist and are valid
  printLog(DEBUG, "Testing type descriptor existence\n");
  
  TypeDescriptor *allTypes[] = {
    typeBool, typeBoolNoCopy,
    typeU8, typeU8NoCopy,
    typeU16, typeU16NoCopy,
    typeU32, typeU32NoCopy,
    typeU64, typeU64NoCopy,
    typeU128, typeU128NoCopy,
    typeI8, typeI8NoCopy,
    typeI16, typeI16NoCopy,
    typeI32, typeI32NoCopy,
    typeI64, typeI64NoCopy,
    typeI128, typeI128NoCopy,
    typeFloat, typeFloatNoCopy,
    typeDouble, typeDoubleNoCopy,
    typeLongDouble, typeLongDoubleNoCopy,
    typeString, typeStringNoCopy,
    typeStringCi, typeStringCiNoCopy,
    typeBytes, typeBytesNoCopy,
    typeList, typeListNoCopy,
    typeQueue, typeQueueNoCopy,
    typeStack, typeStackNoCopy,
    typeRbTree, typeRbTreeNoCopy,
    typeHashTable, typeHashTableNoCopy,
    typeVector, typeVectorNoCopy,
    typePointer, typePointerNoCopy,
    typePointerNoOwn
  };
  
  for (size_t ii = 0; ii < sizeof(allTypes) / sizeof(allTypes[0]); ii++) {
    if (allTypes[ii] == NULL) {
      printLog(ERR, "Type descriptor at index %zu is NULL\n", ii);
      allTestsPassed = false;
    } else {
      if (allTypes[ii]->name == NULL) {
        printLog(ERR, "Type descriptor name at index %zu is NULL\n", ii);
        allTestsPassed = false;
      }
    }
  }
  
  TypeDescriptor newType = *typeString;
  int lastTypeIndex = getIndexFromTypeDescriptor(typePointerNoCopy);
  if (registerTypeDescriptor(&newType) != 0) {
    printLog(ERR, "registerTypeDescriptor(&newType) failed.\n");
    allTestsPassed = false;
  }
  if (getIndexFromTypeDescriptor(&newType) != lastTypeIndex + 1) {
    printLog(ERR,
      "Expected getIndexFromTypeDescriptor(&newType) to be %d, got %d.\n",
      lastTypeIndex + 1,
      (int) getIndexFromTypeDescriptor(&newType));
    allTestsPassed = false;
  }
  
  // Test edge cases for string functions with various inputs
  printLog(DEBUG, "Testing edge cases\n");
  
  // Empty string tests
  if (stringIsInteger("")) {
    printLog(ERR, "stringIsInteger should reject empty string\n");
    allTestsPassed = false;
  }
  
  if (stringIsFloat("")) {
    printLog(ERR, "stringIsFloat should reject empty string\n");
    allTestsPassed = false;
  }
  
  if (stringIsNumber("")) {
    printLog(ERR, "stringIsNumber should reject empty string\n");
    allTestsPassed = false;
  }
  
  if (stringIsBoolean("")) {
    printLog(ERR, "stringIsBoolean should reject empty string\n");
    allTestsPassed = false;
  }
  
  // Whitespace tests
  if (stringIsInteger(" 123 ")) {
    printLog(ERR, "stringIsInteger should handle whitespace appropriately\n");
    allTestsPassed = false;
  }
  
  // Very large number tests
  if (!stringIsInteger("9223372036854775807")) {
    printLog(ERR, "stringIsInteger should accept large valid integers\n");
    allTestsPassed = false;
  }
  
  // Leading zero tests
  if (!stringIsInteger("0123")) {
    printLog(ERR, "stringIsInteger should accept integers with leading zeros\n");
    allTestsPassed = false;
  }
  
  // Multiple sign tests
  if (stringIsInteger("--123")) {
    printLog(ERR, "stringIsInteger should reject multiple signs\n");
    allTestsPassed = false;
  }
  
  if (stringIsFloat("++123.45")) {
    printLog(ERR, "stringIsFloat should reject multiple signs\n");
    allTestsPassed = false;
  }
  
  // Test pointerDestroy macro
  int *testMacroPtr = (int*) malloc(sizeof(int));
  if (testMacroPtr != NULL) {
    *testMacroPtr = 456;
    void *macroResult = pointerDestroy(testMacroPtr);
    if (macroResult != NULL) {
      printLog(ERR, "pointerDestroy macro should return NULL\n");
      allTestsPassed = false;
    }
  }
  
  // Test with NULL for macro (should not crash)
  void *nullMacroResult = pointerDestroy(NULL);
  if (nullMacroResult != NULL) {
    printLog(ERR, "pointerDestroy macro should return NULL for NULL input\n");
    allTestsPassed = false;
  }
  
  // Test constants for boundary conditions
  if (DsMarker == 0) {
    printLog(ERR, "DsMarker should be non-zero\n");
    allTestsPassed = false;
  }
  
  if (DsVersion == 0) {
    printLog(ERR, "DsVersion should be non-zero\n");
    allTestsPassed = false;
  }
  
  // Final test summary
  if (allTestsPassed) {
    printLog(DEBUG, "All DataTypes unit tests PASSED\n");
  } else {
    printLog(ERR, "Some DataTypes unit tests FAILED\n");
  }
  
  return allTestsPassed;
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
  /* 128-bit types can return 8 bytes on 32-bit systems. So, allow for that.  */ \
  if ((type##BIG_TYPE->size(&value1) != SIZE) \
    && (type##BIG_TYPE->size(&value1) != (SIZE >> 1)) \
  ) { \
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
  if (type##BIG_TYPE->clear(NULL) == 0) {\
    printLog(ERR, "type%s->clear(NULL) returned good status.\n", #BIG_TYPE); \
    return false; \
  } \
   \
  SMALL_TYPE value3 = 1; \
  if (type##BIG_TYPE->clear(&value3) != 0) {\
    printLog(ERR, "type%s->clear(&value3) did not return good status.\n", #BIG_TYPE); \
    return false; \
  } \
   \
  if (value3 != 0) { \
    printLog(ERR, "value3 is %d after clear.\n", (int) value3); \
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
DATA_TYPE_UNIT_TEST(u128, U128, 0, 4294967295, 16)
DATA_TYPE_UNIT_TEST(i8, I8, -128, 127, 1)
DATA_TYPE_UNIT_TEST(i16, I16, -32768, 32767, 2)
// Min value for i32 should be -2147483648, but this causes a compile error
// in Windows.
DATA_TYPE_UNIT_TEST(i32, I32, -2147483647, 2147483647, 4)
// Min value for i64 should be -2147483648, but this causes a compile error
// in Windows.
DATA_TYPE_UNIT_TEST(i64, I64, -2147483647, 2147483647, 8)
DATA_TYPE_UNIT_TEST(i128, I128, -2147483647, 2147483647, 16)
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
   \
  if (typeString->clear(NULL) == 0) {\
    printLog(ERR, "type%s->clear(NULL) returned good status.\n", "String"); \
    return false; \
  } \
   \
  if (typeString->clear(newValue) != 0) {\
    printLog(ERR, "type%s->clear(newValue) did not return good status.\n", "String"); \
    return false; \
  } \
   \
  if (*newValue != '\0') { \
    printLog(ERR, "newValue is %s after clear.\n", newValue); \
    return false; \
  } \
   \
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
  if ((strcmp(string, "(nil)") != 0) \
    && (strcmp(string, "0000000000000000") != 0) \
  ) { \
    printLog(ERR, "type%s->toString returned \"%s\" instead of \"%s\".\n", \
      "PointerNoCopy", string, "(nil)"); \
    string = stringDestroy(string); \
    return false; \
  } \
  string = stringDestroy(string); \
  string = typePointerNoCopy->toString(value1); \
  if ((strcmp(string, "0xffffffffffffffff") != 0) \
    && (strcmp(string, "0xffffffff") != 0) \
    && (strcmp(string, "FFFFFFFFFFFFFFFF") != 0) \
    && (strcmp(string, "FFFFFFFF") != 0) \
  ) { \
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
  if ((strcmp(string, "0x1") != 0) \
    && (strcmp(string, "0000000000000001") != 0) \
    && (strcmp(string, "00000001") != 0) \
  ) { \
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
   \
  if (typeBytes->clear(NULL) == 0) {\
    printLog(ERR, "type%s->clear(NULL) returned good status.\n", "Bytes"); \
    return false; \
  } \
   \
  *bytesValue1 = 'g'; \
  if (typeBytes->clear(bytesValue1) != 0) {\
    printLog(ERR, "type%s->clear(bytesValue1) did not return good status.\n", "Bytes"); \
    return false; \
  } \
   \
  if (*bytesValue1 != '\0') { \
    printLog(ERR, "bytesValue1 is %s after clear.\n", bytesValue1); \
    return false; \
  } \
   \
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

bool amongUnitTest(void) {
  scopeBegin(MAX_SCOPE_VARS);
  
  if (among(0, 1, 2, 3, 4)) {
    printLog(ERR, "among(0, 1, 2, 3, 4) returned true!\n");
    return false;
  }
  
  if (!amongZeroOr(0, 1, 2, 3, 4)) {
    printLog(ERR, "amongZeroOr(0, 1, 2, 3, 4) returned false!\n");
    return false;
  }
  
  if (!among(1, 1, 2, 3, 4)) {
    printLog(ERR, "among(1, 1, 2, 3, 4) returned false!\n");
    return false;
  }
  
  if (among(-1, 1, 2, 3, 4)) {
    printLog(ERR, "among(-1, 1, 2, 3, 4) returned true!\n");
    return false;
  }
  
  if (!among(-1, -1, -2, -3, -4)) {
    printLog(ERR, "among(-1, -1, -2, -3, -4) returned false!\n");
    return false;
  }
  
  if (among(0.0, 1.0, 2.0, 3.0, 4.0)) {
    printLog(ERR, "among(0.0, 1.0, 2.0, 3.0, 4.0) returned true!\n");
    return false;
  }
  
  if (!amongZeroOr(0.0, 1.0, 2.0, 3.0, 4.0)) {
    printLog(ERR, "amongZeroOr(0.0, 1.0, 2.0, 3.0, 4.0) returned false!\n");
    return false;
  }
  
  if (!among(1.0, 1.0, 2.0, 3.0, 4.0)) {
    printLog(ERR, "among(1.0, 1.0, 2.0, 3.0, 4.0) returned false!\n");
    return false;
  }
  
  if (among('\0', 'a', 'b', 'c', 'd')) {
    printLog(ERR, "among('\\0', 'a', 'b', 'c', 'd') returned true!\n");
    return false;
  }
  
  if (!amongZeroOr('\0', 'a', 'b', 'c', 'd')) {
    printLog(ERR, "amongZeroOr('\\0', 'a', 'b', 'c', 'd') returned false!\n");
    return false;
  }
  
  if (!among('a', 'a', 'b', 'c', 'd')) {
    printLog(ERR, "among('a', 'a', 'b', 'c', 'd') returned false!\n");
    return false;
  }
  
  if (among((char*) NULL, "one", "two", "three", "four")) {
    printLog(ERR, "among(NULL, \"one\", \"two\", \"three\", \"four\") returned true!\n");
    return false;
  }
  
  if (!amongNullOr((char*) NULL, "one", "two", "three", "four")) {
    printLog(ERR, "amongZeroOr(NULL, \"one\", \"two\", \"three\", \"four\") returned false!\n");
    return false;
  }
  
  if (!among("one", "one", "two", "three", "four")) {
    printLog(ERR, "among(\"one\", \"one\", \"two\", \"three\", \"four\") returned false!\n");
    return false;
  }
  
  u8 u8Zero  = 0;
  u8 u8One   = 1;
  u8 u8Two   = 2;
  u8 u8Three = 3;
  u8 u8Four  = 4;
  
  if (among(u8Zero, u8One, u8Two, u8Three, u8Four)) {
    printLog(ERR, "among(u8Zero, u8One, u8Two, u8Three, u8Four) returned true!\n");
    return false;
  }
  
  if (!amongZeroOr(u8Zero, u8One, u8Two, u8Three, u8Four)) {
    printLog(ERR, "amongZeroOr(u8Zero, u8One, u8Two, u8Three, u8Four) returned false!\n");
    return false;
  }
  
  if (!among(u8One, u8One, u8Two, u8Three, u8Four)) {
    printLog(ERR, "among(u8One, u8One, u8Two, u8Three, u8Four) returned false!\n");
    return false;
  }
  
  i8 i8Zero     =  0;
  i8 i8One      =  1;
  i8 i8Two      =  2;
  i8 i8Three    =  3;
  i8 i8Four     =  4;
  i8 i8NegOne   = -1;
  i8 i8NegTwo   = -2;
  i8 i8NegThree = -3;
  i8 i8NegFour  = -4;
  
  if (among(i8Zero, i8One, i8Two, i8Three, i8Four)) {
    printLog(ERR, "among(i8Zero, i8One, i8Two, i8Three, i8Four) returned true!\n");
    return false;
  }
  
  if (!amongZeroOr(i8Zero, i8One, i8Two, i8Three, i8Four)) {
    printLog(ERR, "amongZeroOr(i8Zero, i8One, i8Two, i8Three, i8Four) returned false!\n");
    return false;
  }
  
  if (!among(i8One, i8One, i8Two, i8Three, i8Four)) {
    printLog(ERR, "among(i8One, i8One, i8Two, i8Three, i8Four) returned false!\n");
    return false;
  }
  
  if (among(i8NegOne, i8One, i8Two, i8Three, i8Four)) {
    printLog(ERR, "among(i8NegOne, i8One, i8Two, i8Three, i8Four) returned true!\n");
    return false;
  }
  
  if (!among(i8NegOne, i8NegOne, i8NegTwo, i8NegThree, i8NegFour)) {
    printLog(ERR, "among(i8NegOne, i8NegOne, i8NegTwo, i8NegThree, i8NegFour) returned false!\n");
    return false;
  }
  
  u16 u16Zero  = 0;
  u16 u16One   = 1;
  u16 u16Two   = 2;
  u16 u16Three = 3;
  u16 u16Four  = 4;
  
  if (among(u16Zero, u16One, u16Two, u16Three, u16Four)) {
    printLog(ERR, "among(u16Zero, u16One, u16Two, u16Three, u16Four) returned true!\n");
    return false;
  }
  
  if (!amongZeroOr(u16Zero, u16One, u16Two, u16Three, u16Four)) {
    printLog(ERR, "amongZeroOr(u16Zero, u16One, u16Two, u16Three, u16Four) returned false!\n");
    return false;
  }
  
  if (!among(u16One, u16One, u16Two, u16Three, u16Four)) {
    printLog(ERR, "among(u16One, u16One, u16Two, u16Three, u16Four) returned false!\n");
    return false;
  }
  
  i16 i16Zero     =  0;
  i16 i16One      =  1;
  i16 i16Two      =  2;
  i16 i16Three    =  3;
  i16 i16Four     =  4;
  i16 i16NegOne   = -1;
  i16 i16NegTwo   = -2;
  i16 i16NegThree = -3;
  i16 i16NegFour  = -4;
  
  if (among(i16Zero, i16One, i16Two, i16Three, i16Four)) {
    printLog(ERR, "among(i16Zero, i16One, i16Two, i16Three, i16Four) returned true!\n");
    return false;
  }
  
  if (!amongZeroOr(i16Zero, i16One, i16Two, i16Three, i16Four)) {
    printLog(ERR, "amongZeroOr(i16Zero, i16One, i16Two, i16Three, i16Four) returned false!\n");
    return false;
  }
  
  if (!among(i16One, i16One, i16Two, i16Three, i16Four)) {
    printLog(ERR, "among(i16One, i16One, i16Two, i16Three, i16Four) returned false!\n");
    return false;
  }
  
  if (among(i16NegOne, i16One, i16Two, i16Three, i16Four)) {
    printLog(ERR, "among(i16NegOne, i16One, i16Two, i16Three, i16Four) returned true!\n");
    return false;
  }
  
  if (!among(i16NegOne, i16NegOne, i16NegTwo, i16NegThree, i16NegFour)) {
    printLog(ERR, "among(i16NegOne, i16NegOne, i16NegTwo, i16NegThree, i16NegFour) returned false!\n");
    return false;
  }
  
  u32 u32Zero  = 0;
  u32 u32One   = 1;
  u32 u32Two   = 2;
  u32 u32Three = 3;
  u32 u32Four  = 4;
  
  if (among(u32Zero, u32One, u32Two, u32Three, u32Four)) {
    printLog(ERR, "among(u32Zero, u32One, u32Two, u32Three, u32Four) returned true!\n");
    return false;
  }
  
  if (!amongZeroOr(u32Zero, u32One, u32Two, u32Three, u32Four)) {
    printLog(ERR, "amongZeroOr(u32Zero, u32One, u32Two, u32Three, u32Four) returned false!\n");
    return false;
  }
  
  if (!among(u32One, u32One, u32Two, u32Three, u32Four)) {
    printLog(ERR, "among(u32One, u32One, u32Two, u32Three, u32Four) returned false!\n");
    return false;
  }
  
  i32 i32Zero     =  0;
  i32 i32One      =  1;
  i32 i32Two      =  2;
  i32 i32Three    =  3;
  i32 i32Four     =  4;
  i32 i32NegOne   = -1;
  i32 i32NegTwo   = -2;
  i32 i32NegThree = -3;
  i32 i32NegFour  = -4;
  
  if (among(i32Zero, i32One, i32Two, i32Three, i32Four)) {
    printLog(ERR, "among(i32Zero, i32One, i32Two, i32Three, i32Four) returned true!\n");
    return false;
  }
  
  if (!amongZeroOr(i32Zero, i32One, i32Two, i32Three, i32Four)) {
    printLog(ERR, "amongZeroOr(i32Zero, i32One, i32Two, i32Three, i32Four) returned false!\n");
    return false;
  }
  
  if (!among(i32One, i32One, i32Two, i32Three, i32Four)) {
    printLog(ERR, "among(i32One, i32One, i32Two, i32Three, i32Four) returned false!\n");
    return false;
  }
  
  if (among(i32NegOne, i32One, i32Two, i32Three, i32Four)) {
    printLog(ERR, "among(i32NegOne, i32One, i32Two, i32Three, i32Four) returned true!\n");
    return false;
  }
  
  if (!among(i32NegOne, i32NegOne, i32NegTwo, i32NegThree, i32NegFour)) {
    printLog(ERR, "among(i32NegOne, i32NegOne, i32NegTwo, i32NegThree, i32NegFour) returned false!\n");
    return false;
  }
  
  u64 u64Zero  = 0;
  u64 u64One   = 1;
  u64 u64Two   = 2;
  u64 u64Three = 3;
  u64 u64Four  = 4;
  
  if (among(u64Zero, u64One, u64Two, u64Three, u64Four)) {
    printLog(ERR, "among(u64Zero, u64One, u64Two, u64Three, u64Four) returned true!\n");
    return false;
  }
  
  if (!amongZeroOr(u64Zero, u64One, u64Two, u64Three, u64Four)) {
    printLog(ERR, "amongZeroOr(u64Zero, u64One, u64Two, u64Three, u64Four) returned false!\n");
    return false;
  }
  
  if (!among(u64One, u64One, u64Two, u64Three, u64Four)) {
    printLog(ERR, "among(u64One, u64One, u64Two, u64Three, u64Four) returned false!\n");
    return false;
  }
  
  i64 i64Zero     =  0;
  i64 i64One      =  1;
  i64 i64Two      =  2;
  i64 i64Three    =  3;
  i64 i64Four     =  4;
  i64 i64NegOne   = -1;
  i64 i64NegTwo   = -2;
  i64 i64NegThree = -3;
  i64 i64NegFour  = -4;
  
  if (among(i64Zero, i64One, i64Two, i64Three, i64Four)) {
    printLog(ERR, "among(i64Zero, i64One, i64Two, i64Three, i64Four) returned true!\n");
    return false;
  }
  
  if (!amongZeroOr(i64Zero, i64One, i64Two, i64Three, i64Four)) {
    printLog(ERR, "amongZeroOr(i64Zero, i64One, i64Two, i64Three, i64Four) returned false!\n");
    return false;
  }
  
  if (!among(i64One, i64One, i64Two, i64Three, i64Four)) {
    printLog(ERR, "among(i64One, i64One, i64Two, i64Three, i64Four) returned false!\n");
    return false;
  }
  
  if (among(i64NegOne, i64One, i64Two, i64Three, i64Four)) {
    printLog(ERR, "among(i64NegOne, i64One, i64Two, i64Three, i64Four) returned true!\n");
    return false;
  }
  
  if (!among(i64NegOne, i64NegOne, i64NegTwo, i64NegThree, i64NegFour)) {
    printLog(ERR, "among(i64NegOne, i64NegOne, i64NegTwo, i64NegThree, i64NegFour) returned false!\n");
    return false;
  }
  
  float floatZero     =  0.0;
  float floatOne      =  1.0;
  float floatTwo      =  2.0;
  float floatThree    =  3.0;
  float floatFour     =  4.0;
  float floatNegOne   = -1.0;
  float floatNegTwo   = -2.0;
  float floatNegThree = -3.0;
  float floatNegFour  = -4.0;
  
  if (among(floatZero, floatOne, floatTwo, floatThree, floatFour)) {
    printLog(ERR, "among(floatZero, floatOne, floatTwo, floatThree, floatFour) returned true!\n");
    return false;
  }
  
  if (!amongZeroOr(floatZero, floatOne, floatTwo, floatThree, floatFour)) {
    printLog(ERR, "amongZeroOr(floatZero, floatOne, floatTwo, floatThree, floatFour) returned false!\n");
    return false;
  }
  
  if (!among(floatOne, floatOne, floatTwo, floatThree, floatFour)) {
    printLog(ERR, "among(floatOne, floatOne, floatTwo, floatThree, floatFour) returned false!\n");
    return false;
  }
  
  if (among(floatNegOne, floatOne, floatTwo, floatThree, floatFour)) {
    printLog(ERR, "among(floatNegOne, floatOne, floatTwo, floatThree, floatFour) returned true!\n");
    return false;
  }
  
  if (!among(floatNegOne, floatNegOne, floatNegTwo, floatNegThree, floatNegFour)) {
    printLog(ERR, "among(floatNegOne, floatNegOne, floatNegTwo, floatNegThree, floatNegFour) returned false!\n");
    return false;
  }
  
  double doubleZero     =  0.0;
  double doubleOne      =  1.0;
  double doubleTwo      =  2.0;
  double doubleThree    =  3.0;
  double doubleFour     =  4.0;
  double doubleNegOne   = -1.0;
  double doubleNegTwo   = -2.0;
  double doubleNegThree = -3.0;
  double doubleNegFour  = -4.0;
  
  if (among(doubleZero, doubleOne, doubleTwo, doubleThree, doubleFour)) {
    printLog(ERR, "among(doubleZero, doubleOne, doubleTwo, doubleThree, doubleFour) returned true!\n");
    return false;
  }
  
  if (!amongZeroOr(doubleZero, doubleOne, doubleTwo, doubleThree, doubleFour)) {
    printLog(ERR, "amongZeroOr(doubleZero, doubleOne, doubleTwo, doubleThree, doubleFour) returned false!\n");
    return false;
  }
  
  if (!among(doubleOne, doubleOne, doubleTwo, doubleThree, doubleFour)) {
    printLog(ERR, "among(doubleOne, doubleOne, doubleTwo, doubleThree, doubleFour) returned false!\n");
    return false;
  }
  
  if (among(doubleNegOne, doubleOne, doubleTwo, doubleThree, doubleFour)) {
    printLog(ERR, "among(doubleNegOne, doubleOne, doubleTwo, doubleThree, doubleFour) returned true!\n");
    return false;
  }
  
  if (!among(doubleNegOne, doubleNegOne, doubleNegTwo, doubleNegThree, doubleNegFour)) {
    printLog(ERR, "among(doubleNegOne, doubleNegOne, doubleNegTwo, doubleNegThree, doubleNegFour) returned false!\n");
    return false;
  }
  
  u16 *u16Null = NULL;
  
  if (among(u16Null, &u16One, &u16Two, &u16Three, &u16Four)) {
    printLog(ERR, "among(u16Null, &u16One, &u16Two, &u16Three, &u16Four) returned true!\n");
    return false;
  }
  
  if (!amongNullOr(u16Null, &u16One, &u16Two, &u16Three, &u16Four)) {
    printLog(ERR, "amongNullOr(u16Null, &u16One, &u16Two, &u16Three, &u16Four) returned false!\n");
    return false;
  }
  
  if (!among(&u16One, &u16One, &u16Two, &u16Three, &u16Four)) {
    printLog(ERR, "among(&u16One, &u16One, &u16Two, &u16Three, &u16Four) returned false!\n");
    return false;
  }
  
  i16 *i16Null = NULL;
  
  if (among(i16Null, &i16One, &i16Two, &i16Three, &i16Four)) {
    printLog(ERR, "among(i16Null, &i16One, &i16Two, &i16Three, &i16Four) returned true!\n");
    return false;
  }
  
  if (!amongNullOr(i16Null, &i16One, &i16Two, &i16Three, &i16Four)) {
    printLog(ERR, "amongNullOr(i16Null, &i16One, &i16Two, &i16Three, &i16Four) returned false!\n");
    return false;
  }
  
  if (!among(&i16One, &i16One, &i16Two, &i16Three, &i16Four)) {
    printLog(ERR, "among(&i16One, &i16One, &i16Two, &i16Three, &i16Four) returned false!\n");
    return false;
  }
  
  if (among(&i16NegOne, &i16One, &i16Two, &i16Three, &i16Four)) {
    printLog(ERR, "among(&i16NegOne, &i16One, &i16Two, &i16Three, &i16Four) returned true!\n");
    return false;
  }
  
  if (!among(&i16NegOne, &i16NegOne, &i16NegTwo, &i16NegThree, &i16NegFour)) {
    printLog(ERR, "among(&i16NegOne, &i16NegOne, &i16NegTwo, &i16NegThree, &i16NegFour) returned false!\n");
    return false;
  }
  
  u32 *u32Null = NULL;
  
  if (among(u32Null, &u32One, &u32Two, &u32Three, &u32Four)) {
    printLog(ERR, "among(u32Null, &u32One, &u32Two, &u32Three, &u32Four) returned true!\n");
    return false;
  }
  
  if (!amongNullOr(u32Null, &u32One, &u32Two, &u32Three, &u32Four)) {
    printLog(ERR, "amongNullOr(u32Null, &u32One, &u32Two, &u32Three, &u32Four) returned false!\n");
    return false;
  }
  
  if (!among(&u32One, &u32One, &u32Two, &u32Three, &u32Four)) {
    printLog(ERR, "among(&u32One, &u32One, &u32Two, &u32Three, &u32Four) returned false!\n");
    return false;
  }
  
  i32 *i32Null = NULL;
  
  if (among(i32Null, &i32One, &i32Two, &i32Three, &i32Four)) {
    printLog(ERR, "among(i32Null, &i32One, &i32Two, &i32Three, &i32Four) returned true!\n");
    return false;
  }
  
  if (!amongNullOr(i32Null, &i32One, &i32Two, &i32Three, &i32Four)) {
    printLog(ERR, "amongNullOr(i32Null, &i32One, &i32Two, &i32Three, &i32Four) returned false!\n");
    return false;
  }
  
  if (!among(&i32One, &i32One, &i32Two, &i32Three, &i32Four)) {
    printLog(ERR, "among(&i32One, &i32One, &i32Two, &i32Three, &i32Four) returned false!\n");
    return false;
  }
  
  if (among(&i32NegOne, &i32One, &i32Two, &i32Three, &i32Four)) {
    printLog(ERR, "among(&i32NegOne, &i32One, &i32Two, &i32Three, &i32Four) returned true!\n");
    return false;
  }
  
  if (!among(&i32NegOne, &i32NegOne, &i32NegTwo, &i32NegThree, &i32NegFour)) {
    printLog(ERR, "among(&i32NegOne, &i32NegOne, &i32NegTwo, &i32NegThree, &i32NegFour) returned false!\n");
    return false;
  }
  
  u64 *u64Null = NULL;
  
  if (among(u64Null, &u64One, &u64Two, &u64Three, &u64Four)) {
    printLog(ERR, "among(u64Null, &u64One, &u64Two, &u64Three, &u64Four) returned true!\n");
    return false;
  }
  
  if (!amongNullOr(u64Null, &u64One, &u64Two, &u64Three, &u64Four)) {
    printLog(ERR, "amongNullOr(u64Null, &u64One, &u64Two, &u64Three, &u64Four) returned false!\n");
    return false;
  }
  
  if (!among(&u64One, &u64One, &u64Two, &u64Three, &u64Four)) {
    printLog(ERR, "among(&u64One, &u64One, &u64Two, &u64Three, &u64Four) returned false!\n");
    return false;
  }
  
  i64 *i64Null = NULL;
  
  if (among(i64Null, &i64One, &i64Two, &i64Three, &i64Four)) {
    printLog(ERR, "among(&i64Null, &i64One, &i64Two, &i64Three, &i64Four) returned true!\n");
    return false;
  }
  
  if (!amongNullOr(i64Null, &i64One, &i64Two, &i64Three, &i64Four)) {
    printLog(ERR, "amongZeroOr(i64Null, &i64One, &i64Two, &i64Three, &i64Four) returned false!\n");
    return false;
  }
  
  if (!among(&i64One, &i64One, &i64Two, &i64Three, &i64Four)) {
    printLog(ERR, "among(&i64One, &i64One, &i64Two, &i64Three, &i64Four) returned false!\n");
    return false;
  }
  
  if (among(&i64NegOne, &i64One, &i64Two, &i64Three, &i64Four)) {
    printLog(ERR, "among(&i64NegOne, &i64One, &i64Two, &i64Three, &i64Four) returned true!\n");
    return false;
  }
  
  if (!among(&i64NegOne, &i64NegOne, &i64NegTwo, &i64NegThree, &i64NegFour)) {
    printLog(ERR, "among(&i64NegOne, &i64NegOne, &i64NegTwo, &i64NegThree, &i64NegFour) returned false!\n");
    return false;
  }
  
  float *floatNull = NULL;
  
  if (among(floatNull, &floatOne, &floatTwo, &floatThree, &floatFour)) {
    printLog(ERR, "among(floatNull, &floatOne, &floatTwo, &floatThree, &floatFour) returned true!\n");
    return false;
  }
  
  if (!amongNullOr(floatNull, &floatOne, &floatTwo, &floatThree, &floatFour)) {
    printLog(ERR, "amongNullOr(floatNull, &floatOne, &floatTwo, &floatThree, &floatFour) returned false!\n");
    return false;
  }
  
  if (!among(&floatOne, &floatOne, &floatTwo, &floatThree, &floatFour)) {
    printLog(ERR, "among(&floatOne, &floatOne, &floatTwo, &floatThree, &floatFour) returned false!\n");
    return false;
  }
  
  if (among(&floatNegOne, &floatOne, &floatTwo, &floatThree, &floatFour)) {
    printLog(ERR, "among(&floatNegOne, &floatOne, &floatTwo, &floatThree, &floatFour) returned true!\n");
    return false;
  }
  
  if (!among(&floatNegOne, &floatNegOne, &floatNegTwo, &floatNegThree, &floatNegFour)) {
    printLog(ERR, "among(&floatNegOne, &floatNegOne, &floatNegTwo, &floatNegThree, &floatNegFour) returned false!\n");
    return false;
  }
  
  double *doubleNull = NULL;
  
  if (among(doubleNull, &doubleOne, &doubleTwo, &doubleThree, &doubleFour)) {
    printLog(ERR, "among(doubleNull, &doubleOne, &doubleTwo, &doubleThree, &doubleFour) returned true!\n");
    return false;
  }
  
  if (!amongNullOr(doubleNull, &doubleOne, &doubleTwo, &doubleThree, &doubleFour)) {
    printLog(ERR, "amongNullOr(doubleNull, &doubleOne, &doubleTwo, &doubleThree, &doubleFour) returned false!\n");
    return false;
  }
  
  if (!among(&doubleOne, &doubleOne, &doubleTwo, &doubleThree, &doubleFour)) {
    printLog(ERR, "among(&doubleOne, &doubleOne, &doubleTwo, &doubleThree, &doubleFour) returned false!\n");
    return false;
  }
  
  if (among(&doubleNegOne, &doubleOne, &doubleTwo, &doubleThree, &doubleFour)) {
    printLog(ERR, "among(&doubleNegOne, &doubleOne, &doubleTwo, &doubleThree, &doubleFour) returned true!\n");
    return false;
  }
  
  if (!among(&doubleNegOne, &doubleNegOne, &doubleNegTwo, &doubleNegThree, &doubleNegFour)) {
    printLog(ERR, "among(&doubleNegOne, &doubleNegOne, &doubleNegTwo, &doubleNegThree, &doubleNegFour) returned false!\n");
    return false;
  }
  
  Bytes bytesNull  = NULL;
  Bytes bytesOne   = NULL;
  Bytes bytesTwo   = NULL;
  Bytes bytesThree = NULL;
  Bytes bytesFour  = NULL;
  
  bytesAddStr(&bytesOne, "one");
  scopeAdd(bytesOne, bytesDestroy);
  bytesAddStr(&bytesTwo, "two");
  scopeAdd(bytesTwo, bytesDestroy);
  bytesAddStr(&bytesThree, "three");
  scopeAdd(bytesThree, bytesDestroy);
  bytesAddStr(&bytesFour, "four");
  scopeAdd(bytesFour, bytesDestroy);
  
  if (among(bytesNull, bytesOne, bytesTwo, bytesThree, bytesFour)) {
    printLog(ERR, "among(bytesNull, bytesOne, bytesTwo, bytesThree, bytesFour) returned true!\n");
    return false;
  }
  
  if (!amongNullOr(bytesNull, bytesOne, bytesTwo, bytesThree, bytesFour)) {
    printLog(ERR, "amongNullOr(bytesNull, bytesOne, bytesTwo, bytesThree, bytesFour) returned false!\n");
    return false;
  }
  
  if (!among(bytesOne, bytesOne, bytesTwo, bytesThree, bytesFour)) {
    printLog(ERR, "among(bytesOne, bytesOne, bytesTwo, bytesThree, bytesFour) returned false!\n");
    return false;
  }
  
  scopeEnd();
  return true;
}

