///////////////////////////////////////////////////////////////////////////////
///
/// @file              StringLibUnitTest.c
///
/// @brief             Unit test for StringLib functions
///
/// @details           Comprehensive test suite for all StringLib functions
///                    including corner cases and NULL parameter handling
///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "StringLib.h"
#include "LoggingLib.h"

// Test helper macros
#define TEST_ASSERT(condition, message) \
  do { \
    if (!(condition)) { \
      printLog(ERR, "Test failed: %s", message); \
      return false; \
    } \
  } while (0)

#define TEST_ASSERT_NULL(ptr, message) \
  TEST_ASSERT((ptr) == NULL, message)

#define TEST_ASSERT_NOT_NULL(ptr, message) \
  TEST_ASSERT((ptr) != NULL, message)

#define TEST_ASSERT_STR_EQ(str1, str2, message) \
  TEST_ASSERT(strcmp((str1), (str2)) == 0, message)

#define TEST_ASSERT_EQ(val1, val2, message) \
  TEST_ASSERT((val1) == (val2), message)

///
/// @brief Test the indentText function
///
/// @return Returns true on success, false on failure
///
bool testIndentText(void) {
  printLog(DEBUG, "Testing indentText function");
  
  // Test with valid input
  char *result = indentText("Hello\nWorld", 4);
  TEST_ASSERT_NOT_NULL(result, "indentText should not return NULL for valid input");
  
  // Clean up
  if (result != NULL) {
    result = stringDestroy(result);
  }
  
  // Test with NULL input
  result = indentText(NULL, 4);
  TEST_ASSERT_NULL(result, "indentText should return NULL for NULL input");
  
  // Test with zero columns
  result = indentText("Hello", 0);
  TEST_ASSERT_NOT_NULL(result, "indentText should handle zero columns");
  if (result != NULL) {
    result = stringDestroy(result);
  }
  
  return true;
}

///
/// @brief Test the unescapeString function
///
/// @return Returns true on success, false on failure
///
bool testUnescapeString(void) {
  printLog(DEBUG, "Testing unescapeString function");
  
  // Test with valid input
  char testStr[] = "Hello\\nWorld\\t";
  unescapeString(testStr);
  
  // Test with NULL input (should not crash)
  unescapeString(NULL);
  
  return true;
}

///
/// @brief Test the plusToSpace function
///
/// @return Returns true on success, false on failure
///
bool testPlusToSpace(void) {
  printLog(DEBUG, "Testing plusToSpace function");
  
  // Test with valid input
  char testStr[] = "Hello+World+Test";
  plusToSpace(testStr);
  TEST_ASSERT_STR_EQ(testStr, "Hello World Test", "plusToSpace should convert + to spaces");
  
  // Test with NULL input (should not crash)
  plusToSpace(NULL);
  
  return true;
}

///
/// @brief Test the dosToUnix function
///
/// @return Returns true on success, false on failure
///
bool testDosToUnix(void) {
  printLog(DEBUG, "Testing dosToUnix function");
  
  // Test with valid input
  char testStr[] = "Hello\r\nWorld\r\n";
  dosToUnix(testStr);
  TEST_ASSERT_STR_EQ(testStr, "Hello\nWorld\n", "dosToUnix should convert CRLF to LF");
  
  // Test with NULL input (should not crash)
  dosToUnix(NULL);
  
  return true;
}

///
/// @brief Test the straddstr function
///
/// @return Returns true on success, false on failure
///
bool testStraddstr(void) {
  printLog(DEBUG, "Testing straddstr function");
  
  // Test with valid input
  char *buffer = NULL;
  char *result = straddstr(&buffer, "Hello");
  TEST_ASSERT_NOT_NULL(result, "straddstr should return valid pointer");
  TEST_ASSERT_STR_EQ(buffer, "Hello", "straddstr should add string to buffer");
  
  // Add more text
  result = straddstr(&buffer, " World");
  TEST_ASSERT_NOT_NULL(result, "straddstr should return valid pointer for append");
  TEST_ASSERT_STR_EQ(buffer, "Hello World", "straddstr should append string");
  
  buffer = stringDestroy(buffer);
  
  // Test with NULL buffer pointer
  result = straddstr(NULL, "test");
  TEST_ASSERT_NULL(result, "straddstr should return NULL for NULL buffer pointer");
  
  // Test with NULL input string
  buffer = NULL;
  result = straddstr(&buffer, NULL);
  TEST_ASSERT_STR_EQ(buffer, "", "straddstr should be empty for NULL input");
  buffer = stringDestroy(buffer);
  
  return true;
}

///
/// @brief Test the straddchr function
///
/// @return Returns true on success, false on failure
///
bool testStraddchr(void) {
  printLog(DEBUG, "Testing straddchr function");
  
  // Test with valid input
  char *buffer = NULL;
  char *result = straddchr(&buffer, 'A');
  TEST_ASSERT_NOT_NULL(result, "straddchr should return valid pointer");
  TEST_ASSERT_EQ(buffer[0], 'A', "straddchr should add character to buffer");
  TEST_ASSERT_EQ(buffer[1], '\0', "straddchr should null-terminate");
  
  buffer = stringDestroy(buffer);
  
  // Test with NULL buffer pointer
  result = straddchr(NULL, 'A');
  TEST_ASSERT_NULL(result, "straddchr should return NULL for NULL buffer pointer");
  
  return true;
}

///
/// @brief Test the dataAddData function
///
/// @return Returns true on success, false on failure
///
bool testDataAddData(void) {
  printLog(DEBUG, "Testing dataAddData function");
  
  // Test with valid input
  void *buffer = NULL;
  char testData[] = "Hello";
  u64 result = dataAddData(&buffer, 0, testData, 5);
  TEST_ASSERT_EQ(result, 5, "dataAddData should return correct length");
  TEST_ASSERT_NOT_NULL(buffer, "dataAddData should allocate buffer");
  
  free(buffer);
  
  // Test with NULL buffer pointer
  result = dataAddData(NULL, 0, testData, 5);
  TEST_ASSERT_EQ(result, 0, "dataAddData should return 0 for NULL buffer pointer");
  
  // Test with NULL input
  buffer = NULL;
  result = dataAddData(&buffer, 0, NULL, 5);
  TEST_ASSERT_EQ(result, 0, "dataAddData should return 0 for NULL input");
  
  return true;
}

///
/// @brief Test the getFileLength function
///
/// @return Returns true on success, false on failure
///
bool testGetFileLength(void) {
  printLog(DEBUG, "Testing getFileLength function");
  
  // Test with NULL input
  i64 result = getFileLength(NULL);
  TEST_ASSERT_EQ(result, -1, "getFileLength should return -1 for NULL input");
  
  // Test with non-existent file
  result = getFileLength("non_existent_file.txt");
  TEST_ASSERT_EQ(result, -1, "getFileLength should return -1 for non-existent file");
  
  return true;
}

///
/// @brief Test the getFileContent function
///
/// @return Returns true on success, false on failure
///
bool testGetFileContent(void) {
  printLog(DEBUG, "Testing getFileContent function");
  
  // Test with NULL input
  Bytes result = getFileContent(NULL);
  TEST_ASSERT_NULL(result, "getFileContent should return NULL for NULL input");
  
  // Test with non-existent file
  result = getFileContent("non_existent_file.txt");
  TEST_ASSERT_NULL(result, "getFileContent should return NULL for non-existent file");
  
  return true;
}

///
/// @brief Test the putFileContent function
///
/// @return Returns true on success, false on failure
///
bool testPutFileContent(void) {
  printLog(DEBUG, "Testing putFileContent function");
  
  // Test with NULL filename
  char testData[] = "Hello";
  i64 result = putFileContent(NULL, testData, 5);
  TEST_ASSERT_EQ(result, -1, "putFileContent should return -1 for NULL filename");
  
  // Test with NULL data
  result = putFileContent("test.txt", NULL, 5);
  TEST_ASSERT_EQ(result, -1, "putFileContent should return -1 for NULL data");
  
  return true;
}

///
/// @brief Test the getFileLine function
///
/// @return Returns true on success, false on failure
///
bool testGetFileLine(void) {
  printLog(DEBUG, "Testing getFileLine function");
  
  // Test with NULL file pointer
  char *buffer = NULL;
  u64 result = getFileLine(NULL, &buffer);
  TEST_ASSERT_EQ(result, 0, "getFileLine should return 0 for NULL file");
  
  // Test with NULL buffer pointer
  result = getFileLine(stdin, NULL);
  TEST_ASSERT_EQ(result, 0, "getFileLine should return 0 for NULL buffer pointer");
  
  return true;
}

///
/// @brief Test the unampersand function
///
/// @return Returns true on success, false on failure
///
bool testUnampersand(void) {
  printLog(DEBUG, "Testing unampersand function");
  
  // Test with valid input
  char result = unampersand("&amp;");
  TEST_ASSERT_EQ(result, '&', "unampersand should decode &amp; to &");
  
  // Test with NULL input
  result = unampersand(NULL);
  TEST_ASSERT_EQ(result, '\0', "unampersand should return null char for NULL input");
  
  return true;
}

///
/// @brief Test the hexToChar function
///
/// @return Returns true on success, false on failure
///
bool testHexToChar(void) {
  printLog(DEBUG, "Testing hexToChar function");
  
  // Test with valid input
  char result = hexToChar("41");
  TEST_ASSERT_EQ(result, 'A', "hexToChar should convert 41 to A");
  
  // Test with NULL input
  result = hexToChar(NULL);
  TEST_ASSERT_EQ(result, '\0', "hexToChar should return null char for NULL input");
  
  return true;
}

///
/// @brief Test the strReplaceOneStr function
///
/// @return Returns true on success, false on failure
///
bool testStrReplaceOneStr(void) {
  printLog(DEBUG, "Testing strReplaceOneStr function");
  
  // Test with valid input
  bool replacementMade = false;
  char *result = strReplaceOneStr("Hello World", "World", "Universe", &replacementMade);
  TEST_ASSERT_NOT_NULL(result, "strReplaceOneStr should return valid pointer");
  TEST_ASSERT_STR_EQ(result, "Hello Universe", "strReplaceOneStr should replace text");
  TEST_ASSERT_EQ(replacementMade, true, "strReplaceOneStr should set replacement flag");
  result = stringDestroy(result);
  
  // Test with NULL input string
  result = strReplaceOneStr(NULL, "World", "Universe", &replacementMade);
  TEST_ASSERT_STR_EQ(result, "",
    "strReplaceOneStr should produce empty string with NULL input");
  result = stringDestroy(result);
  
  // Test with NULL find string
  result = strReplaceOneStr("Hello", NULL, "Universe", &replacementMade);
  TEST_ASSERT_STR_EQ(result, "Hello",
    "strReplaceOneStr should produce input with NULL find string");
  result = stringDestroy(result);
  
  return true;
}

///
/// @brief Test the strReplaceStr function
///
/// @return Returns true on success, false on failure
///
bool testStrReplaceStr(void) {
  printLog(DEBUG, "Testing strReplaceStr function");
  
  // Test with valid input
  char *result = strReplaceStr("Hello World World", "World", "Universe");
  TEST_ASSERT_NOT_NULL(result, "strReplaceStr should return valid pointer");
  TEST_ASSERT_STR_EQ(result, "Hello Universe Universe", "strReplaceStr should replace all occurrences");
  result = stringDestroy(result);
  
  // Test with NULL input
  result = strReplaceStr(NULL, "World", "Universe");
  TEST_ASSERT_STR_EQ(result, "", "strReplaceStr should return empty string for NULL input");
  
  return true;
}

///
/// @brief Test the escapeString function
///
/// @return Returns true on success, false on failure
///
bool testEscapeString(void) {
  printLog(DEBUG, "Testing escapeString function");
  
  printLog(DEBUG, "Test with valid input\n");
  char *result = escapeString("Hello\nWorld");
  TEST_ASSERT_NOT_NULL(result, "escapeString should return valid pointer");
  result = stringDestroy(result);
  
  printLog(DEBUG, "Test with NULL input\n");
  result = escapeString(NULL);
  TEST_ASSERT_NULL(result, "escapeString should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the strrstr function
///
/// @return Returns true on success, false on failure
///
bool testStrrstr(void) {
  printLog(DEBUG, "Testing strrstr function");
  
  // Test with valid input
  const char *result = strrstr("Hello World World", "World");
  TEST_ASSERT_NOT_NULL(result, "strrstr should find last occurrence");
  
  // Test with NULL haystack
  result = strrstr(NULL, "World");
  TEST_ASSERT_NULL(result, "strrstr should return NULL for NULL haystack");
  
  // Test with NULL needle
  result = strrstr("Hello", NULL);
  TEST_ASSERT_NULL(result, "strrstr should return NULL for NULL needle");
  
  return true;
}

///
/// @brief Test the stringToBytesTable function
///
/// @return Returns true on success, false on failure
///
bool testStringToBytesTable(void) {
  printLog(DEBUG, "Testing stringToBytesTable function");
  
  // Test with valid input
  Bytes **result = stringToBytesTable("a,b\nc,d", "\n", ",");
  TEST_ASSERT_NOT_NULL(result, "stringToBytesTable should return valid pointer");
  freeBytesTable(result);
  
  // Test with NULL input
  result = stringToBytesTable(NULL);
  TEST_ASSERT_NULL(result, "stringToBytesTable should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the stringToBytesArray function
///
/// @return Returns true on success, false on failure
///
bool testStringToBytesArray(void) {
  printLog(DEBUG, "Testing stringToBytesArray function");
  
  // Test with valid input
  Bytes *result = stringToBytesArray("a,b,c", ",");
  TEST_ASSERT_NOT_NULL(result, "stringToBytesArray should return valid pointer");
  freeBytesArray(result);
  
  // Test with NULL input
  result = stringToBytesArray(NULL);
  TEST_ASSERT_NULL(result, "stringToBytesArray should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the freeBytesArray function
///
/// @return Returns true on success, false on failure
///
bool testFreeBytesArray(void) {
  printLog(DEBUG, "Testing freeBytesArray function");
  
  // Test with NULL input (should not crash)
  Bytes *result = freeBytesArray(NULL);
  TEST_ASSERT_NULL(result, "freeBytesArray should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the freeBytesTable function
///
/// @return Returns true on success, false on failure
///
bool testFreeBytesTable(void) {
  printLog(DEBUG, "Testing freeBytesTable function");
  
  // Test with NULL input (should not crash)
  Bytes **result = freeBytesTable(NULL);
  TEST_ASSERT_NULL(result, "freeBytesTable should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the bytesTableToString function
///
/// @return Returns true on success, false on failure
///
bool testBytesTableToString(void) {
  printLog(DEBUG, "Testing bytesTableToString function");
  
  // Test with NULL input
  char *result = bytesTableToString(NULL);
  TEST_ASSERT_NULL(result, "bytesTableToString should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the bytesArrayToString function
///
/// @return Returns true on success, false on failure
///
bool testBytesArrayToString(void) {
  printLog(DEBUG, "Testing bytesArrayToString function");
  
  // Test with NULL input
  char *result = bytesArrayToString(NULL);
  TEST_ASSERT_NULL(result, "bytesArrayToString should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the vasprintf function
///
/// @return Returns true on success, false on failure
///
bool testVasprintf(void) {
  printLog(DEBUG, "Testing vasprintf function");
  
  // Test with NULL buffer pointer
  int result = vasprintf(NULL, "test", NULL);
  TEST_ASSERT_EQ(result, -1, "vasprintf should return -1 for NULL buffer pointer");
  
  return true;
}

///
/// @brief Test the asprintf function
///
/// @return Returns true on success, false on failure
///
bool testAsprintf(void) {
  printLog(DEBUG, "Testing asprintf function");
  
  // Test with valid input
  char *buffer = NULL;
  int result = asprintf(&buffer, "Hello %s", "World");
  TEST_ASSERT(result > 0, "asprintf should return positive value for success");
  TEST_ASSERT_NOT_NULL(buffer, "asprintf should allocate buffer");
  TEST_ASSERT_STR_EQ(buffer, "Hello World", "asprintf should format string correctly");
  buffer = stringDestroy(buffer);
  
  // Test with NULL buffer pointer
  result = asprintf(NULL, "test");
  TEST_ASSERT_EQ(result, -1, "asprintf should return -1 for NULL buffer pointer");
  
  return true;
}

///
/// @brief Test the unformatString function
///
/// @return Returns true on success, false on failure
///
bool testUnformatString(void) {
  printLog(DEBUG, "Testing unformatString function");
  
  // Test with NULL input
  char *result = unformatString(NULL);
  TEST_ASSERT_NULL(result, "unformatString should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the reverseString function
///
/// @return Returns true on success, false on failure
///
bool testReverseString(void) {
  printLog(DEBUG, "Testing reverseString function");
  
  // Test with valid input
  char testStr[] = "Hello";
  i32 result = reverseString(testStr);
  TEST_ASSERT_EQ(result, 0, "reverseString should return 0 for success");
  TEST_ASSERT_STR_EQ(testStr, "olleH", "reverseString should reverse the string");
  
  // Test with NULL input
  result = reverseString(NULL);
  TEST_ASSERT(result != 0, "reverseString should return non-zero for NULL input");
  
  return true;
}

///
/// @brief Test the arrayFindValueIndex function
///
/// @return Returns true on success, false on failure
///
bool testArrayFindValueIndex(void) {
  printLog(DEBUG, "Testing arrayFindValueIndex function");
  
  // Test with valid input
  const char *testArray[] = {"Hello", "World", NULL};
  int result = arrayFindValueIndex(testArray, "World");
  TEST_ASSERT_EQ(result, 1, "arrayFindValueIndex should return correct index");
  
  // Test with NULL array
  result = arrayFindValueIndex(NULL, "World");
  TEST_ASSERT_EQ(result, -1, "arrayFindValueIndex should return -1 for NULL array");
  
  // Test with NULL value
  result = arrayFindValueIndex(testArray, NULL);
  TEST_ASSERT_EQ(result, -1, "arrayFindValueIndex should return -1 for NULL value");
  
  return true;
}

///
/// @brief Test the arrayRemoveValue function
///
/// @return Returns true on success, false on failure
///
bool testArrayRemoveValue(void) {
  printLog(DEBUG, "Testing arrayRemoveValue function");
  
  // Test with NULL array
  int result = arrayRemoveValue(NULL, "test");
  TEST_ASSERT(result != 0, "arrayRemoveValue should return non-zero for NULL array");
  
  return true;
}

///
/// @brief Test the stringToLowerCase function
///
/// @return Returns true on success, false on failure
///
bool testStringToLowerCase(void) {
  printLog(DEBUG, "Testing stringToLowerCase function");
  
  // Test with valid input
  char testStr[] = "HELLO World";
  stringToLowerCase(testStr);
  TEST_ASSERT_STR_EQ(testStr, "hello world", "stringToLowerCase should convert to lowercase");
  
  // Test with NULL input (should not crash)
  stringToLowerCase(NULL);
  
  return true;
}

///
/// @brief Test the strstrci function
///
/// @return Returns true on success, false on failure
///
bool testStrstrci(void) {
  printLog(DEBUG, "Testing strstrci function");
  
  // Test with valid input
  char *result = strstrci("Hello WORLD", "world");
  TEST_ASSERT_NOT_NULL(result, "strstrci should find case-insensitive match");
  
  // Test with NULL haystack
  result = strstrci(NULL, "world");
  TEST_ASSERT_NULL(result, "strstrci should return NULL for NULL haystack");
  
  // Test with NULL needle
  result = strstrci("Hello", NULL);
  TEST_ASSERT_NULL(result, "strstrci should return NULL for NULL needle");
  
  return true;
}

///
/// @brief Test the strncmpci function
///
/// @return Returns true on success, false on failure
///
bool testStrncmpci(void) {
  printLog(DEBUG, "Testing strncmpci function");
  
  // Test with valid input
  int result = strncmpci("Hello", "HELLO", 5);
  TEST_ASSERT_EQ(result, 0, "strncmpci should return 0 for case-insensitive match");
  
  // Test with NULL strings
  result = strncmpci(NULL, "hello", 5);
  TEST_ASSERT(result != 0, "strncmpci should return non-zero for NULL first string");
  
  result = strncmpci("hello", NULL, 5);
  TEST_ASSERT(result != 0, "strncmpci should return non-zero for NULL second string");
  
  return true;
}

///
/// @brief Test the getBytesBetweenCi function
///
/// @return Returns true on success, false on failure
///
bool testGetBytesBetweenCi(void) {
  printLog(DEBUG, "Testing getBytesBetweenCi function");
  
  // Test with valid input
  Bytes result = getBytesBetweenCi("Hello [WORLD] Test", "[", "]");
  TEST_ASSERT_NOT_NULL(result, "getBytesBetweenCi should return valid pointer");
  bytesDestroy(result);
  
  // Test with NULL haystack
  result = getBytesBetweenCi(NULL, "[", "]");
  TEST_ASSERT_NULL(result, "getBytesBetweenCi should return NULL for NULL haystack");
  
  return true;
}

///
/// @brief Test the escapeData function
///
/// @return Returns true on success, false on failure
///
bool testEscapeData(void) {
  printLog(DEBUG, "Testing escapeData function");
  
  // Test with valid input
  char testData[] = "Hello\nWorld";
  char *result = escapeData(testData, strlen(testData));
  TEST_ASSERT_NOT_NULL(result, "escapeData should return valid pointer");
  result = stringDestroy(result);
  
  // Test with NULL input
  result = escapeData(NULL, 0);
  TEST_ASSERT_NULL(result, "escapeData should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the escapeDataToBytes function
///
/// @return Returns true on success, false on failure
///
bool testEscapeDataToBytes(void) {
  printLog(DEBUG, "Testing escapeDataToBytes function");
  
  // Test with valid input
  char testData[] = "Hello\nWorld";
  Bytes result = escapeDataToBytes(testData, strlen(testData));
  TEST_ASSERT_NOT_NULL(result, "escapeDataToBytes should return valid pointer");
  bytesDestroy(result);
  
  // Test with NULL input
  result = escapeDataToBytes(NULL, 0);
  TEST_ASSERT_NULL(result, "escapeDataToBytes should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the unescapeBytes function
///
/// @return Returns true on success, false on failure
///
bool testUnescapeBytes(void) {
  printLog(DEBUG, "Testing unescapeBytes function");
  
  // Test with NULL input (should not crash)
  unescapeBytes(NULL);
  
  return true;
}

///
/// @brief Test the straddbytes function
///
/// @return Returns true on success, false on failure
///
bool testStraddbytes(void) {
  printLog(DEBUG, "Testing straddbytes function");
  
  // Test with NULL buffer pointer
  u64 result = straddbytes(NULL, NULL);
  TEST_ASSERT_EQ(result, 0, "straddbytes should return 0 for NULL buffer pointer");
  
  return true;
}

///
/// @brief Test the bytesNCompare function
///
/// @return Returns true on success, false on failure
///
bool testBytesNCompare(void) {
  printLog(DEBUG, "Testing bytesNCompare function");
  
  // Test with NULL inputs
  int result = bytesNCompare(NULL, NULL, 5);
  TEST_ASSERT_EQ(result, 0, "bytesNCompare should return 0 for both NULL");
  
  return true;
}

///
/// @brief Test the bytesTableToCsv function
///
/// @return Returns true on success, false on failure
///
bool testBytesTableToCsv(void) {
  printLog(DEBUG, "Testing bytesTableToCsv function");
  
  // Test with NULL input
  Bytes result = bytesTableToCsv(NULL);
  TEST_ASSERT_NULL(result, "bytesTableToCsv should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the charToHex function
///
/// @return Returns true on success, false on failure
///
bool testCharToHex(void) {
  printLog(DEBUG, "Testing charToHex function");
  
  // Test with valid input
  char output[3];
  int result = charToHex('A', false, output);
  TEST_ASSERT_EQ(result, 0, "charToHex should return 0 for success");
  TEST_ASSERT_STR_EQ(output, "41", "charToHex should convert A to 41");
  
  // Test with NULL output
  result = charToHex('A', false, NULL);
  TEST_ASSERT(result != 0, "charToHex should return non-zero for NULL output");
  
  return true;
}

///
/// @brief Test the bytesReplaceStr function
///
/// @return Returns true on success, false on failure
///
bool testBytesReplaceStr(void) {
  printLog(DEBUG, "Testing bytesReplaceStr function");
  
  // Test with NULL input
  Bytes result = bytesReplaceStr(NULL, "find", "replace");
  TEST_ASSERT_NULL(result, "bytesReplaceStr should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the dataFindData function
///
/// @return Returns true on success, false on failure
///
bool testDataFindData(void) {
  printLog(DEBUG, "Testing dataFindData function");
  
  // Test with NULL inputs
  void *result = dataFindData(NULL, 0, NULL, 0);
  TEST_ASSERT_NULL(result, "dataFindData should return NULL for NULL inputs");
  
  return true;
}

///
/// @brief Test the getDataBetween function
///
/// @return Returns true on success, false on failure
///
bool testGetDataBetween(void) {
  printLog(DEBUG, "Testing getDataBetween function");
  
  // Test with NULL inputs
  Bytes result = getDataBetween(NULL, 0, NULL, 0, NULL, 0);
  TEST_ASSERT_NULL(result, "getDataBetween should return NULL for NULL inputs");
  
  return true;
}

///
/// @brief Test the vabprintf function
///
/// @return Returns true on success, false on failure
///
bool testVabprintf(void) {
  printLog(DEBUG, "Testing vabprintf function");
  
  // Test with NULL buffer pointer
  int result = vabprintf(NULL, "test", NULL);
  TEST_ASSERT_EQ(result, -1, "vabprintf should return -1 for NULL buffer pointer");
  
  return true;
}

///
/// @brief Test the abprintf function
///
/// @return Returns true on success, false on failure
///
bool testAbprintf(void) {
  printLog(DEBUG, "Testing abprintf function");
  
  // Test with valid input
  Bytes buffer = NULL;
  int result = abprintf(&buffer, "Hello %s", "World");
  TEST_ASSERT(result > 0, "abprintf should return positive value for success");
  TEST_ASSERT_NOT_NULL(buffer, "abprintf should allocate buffer");
  bytesDestroy(buffer);
  
  // Test with NULL buffer pointer
  result = abprintf(NULL, "test");
  TEST_ASSERT_EQ(result, -1, "abprintf should return -1 for NULL buffer pointer");
  
  return true;
}

///
/// @brief Test the isInteger function
///
/// @return Returns true on success, false on failure
///
bool testIsInteger(void) {
  printLog(DEBUG, "Testing isInteger function");
  
  // Test with valid integer
  bool result = isInteger("123");
  TEST_ASSERT_EQ(result, true, "isInteger should return true for valid integer");
  
  // Test with non-integer
  result = isInteger("123.45");
  TEST_ASSERT_EQ(result, false, "isInteger should return false for non-integer");
  
  // Test with NULL input
  result = isInteger(NULL);
  TEST_ASSERT_EQ(result, false, "isInteger should return false for NULL input");
  
  return true;
}

///
/// @brief Test the isNumber function
///
/// @return Returns true on success, false on failure
///
bool testIsNumber(void) {
  printLog(DEBUG, "Testing isNumber function");
  
  // Test with valid number
  bool result = isNumber("123.45");
  TEST_ASSERT_EQ(result, true, "isNumber should return true for valid number");
  
  // Test with non-number
  result = isNumber("abc");
  TEST_ASSERT_EQ(result, false, "isNumber should return false for non-number");
  
  // Test with NULL input
  result = isNumber(NULL);
  TEST_ASSERT_EQ(result, false, "isNumber should return false for NULL input");
  
  return true;
}

///
/// @brief Test the getProgramName function
///
/// @return Returns true on success, false on failure
///
bool testGetProgramName(void) {
  printLog(DEBUG, "Testing getProgramName function");
  
  // Test with valid input
  const char *result = getProgramName("/usr/bin/test");
  TEST_ASSERT_NOT_NULL(result, "getProgramName should return valid pointer");
  TEST_ASSERT_STR_EQ(result, "test", "getProgramName should extract program name");
  
  // Test with NULL input
  result = getProgramName(NULL);
  TEST_ASSERT_NULL(result, "getProgramName should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the stringStartsWith function
///
/// @return Returns true on success, false on failure
///
bool testStringStartsWith(void) {
  printLog(DEBUG, "Testing stringStartsWith function");
  
  // Test with valid input
  bool result = stringStartsWith("Hello World", "Hello");
  TEST_ASSERT_EQ(result, true, "stringStartsWith should return true for match");
  
  // Test with no match
  result = stringStartsWith("Hello World", "World");
  TEST_ASSERT_EQ(result, false, "stringStartsWith should return false for no match");
  
  // Test with NULL haystack
  result = stringStartsWith(NULL, "Hello");
  TEST_ASSERT_EQ(result, false, "stringStartsWith should return false for NULL haystack");
  
  // Test with NULL beginning
  result = stringStartsWith("Hello", NULL);
  TEST_ASSERT_EQ(result, false, "stringStartsWith should return false for NULL beginning");
  
  return true;
}

///
/// @brief Test the stringStartsWithCi function
///
/// @return Returns true on success, false on failure
///
bool testStringStartsWithCi(void) {
  printLog(DEBUG, "Testing stringStartsWithCi function");
  
  // Test with valid input
  bool result = stringStartsWithCi("Hello World", "HELLO");
  TEST_ASSERT_EQ(result, true, "stringStartsWithCi should return true for case-insensitive match");
  
  // Test with NULL haystack
  result = stringStartsWithCi(NULL, "Hello");
  TEST_ASSERT_EQ(result, false, "stringStartsWithCi should return false for NULL haystack");
  
  // Test with NULL beginning
  result = stringStartsWithCi("Hello", NULL);
  TEST_ASSERT_EQ(result, false, "stringStartsWithCi should return false for NULL beginning");
  
  return true;
}

///
/// @brief Test the dataIsString function
///
/// @return Returns true on success, false on failure
///
bool testDataIsString(void) {
  printLog(DEBUG, "Testing dataIsString function");
  
  // Test with valid string
  bool result = dataIsString("Hello", 5);
  TEST_ASSERT_EQ(result, true, "dataIsString should return true for valid string");
  
  // Test with NULL input
  result = dataIsString(NULL, 5);
  TEST_ASSERT_EQ(result, false, "dataIsString should return false for NULL input");
  
  return true;
}

///
/// @brief Test the dataIsAscii function
///
/// @return Returns true on success, false on failure
///
bool testDataIsAscii(void) {
  printLog(DEBUG, "Testing dataIsAscii function");
  
  // Test with ASCII data
  bool result = dataIsAscii("Hello", 5);
  TEST_ASSERT_EQ(result, true, "dataIsAscii should return true for ASCII data");
  
  // Test with NULL input
  result = dataIsAscii(NULL, 5);
  TEST_ASSERT_EQ(result, false, "dataIsAscii should return false for NULL input");
  
  return true;
}

///
/// @brief Test the nonPrintableToWhitespace function
///
/// @return Returns true on success, false on failure
///
bool testNonPrintableToWhitespace(void) {
  printLog(DEBUG, "Testing nonPrintableToWhitespace function");
  
  // Test with NULL input
  bool result = nonPrintableToWhitespace(NULL, 5);
  TEST_ASSERT_EQ(result, false, "nonPrintableToWhitespace should return false for NULL input");
  
  return true;
}

///
/// @brief Test the dataEndsWith function
///
/// @return Returns true on success, false on failure
///
bool testDataEndsWith(void) {
  printLog(DEBUG, "Testing dataEndsWith function");
  
  // Test with valid input
  bool result = dataEndsWith("Hello World", 11, "World", 5);
  TEST_ASSERT_EQ(result, true, "dataEndsWith should return true for match");
  
  // Test with NULL haystack
  result = dataEndsWith(NULL, 11, "World", 5);
  TEST_ASSERT_EQ(result, false, "dataEndsWith should return false for NULL haystack");
  
  // Test with NULL needle
  result = dataEndsWith("Hello", 5, NULL, 5);
  TEST_ASSERT_EQ(result, false, "dataEndsWith should return false for NULL needle");
  
  return true;
}

///
/// @brief Test the ungets function
///
/// @return Returns true on success, false on failure
///
bool testUngets(void) {
  printLog(DEBUG, "Testing ungets function");
  
  // Test with NULL string
  ssize_t result = ungets(NULL, stdout);
  TEST_ASSERT_EQ(result, -1, "ungets should return -1 for NULL string");
  
  // Test with NULL stream
  result = ungets("test", NULL);
  TEST_ASSERT_EQ(result, -1, "ungets should return -1 for NULL stream");
  
  return true;
}

///
/// @brief Test the getToken function
///
/// @return Returns true on success, false on failure
///
bool testGetToken(void) {
  printLog(DEBUG, "Testing getToken function");
  
  // Test with valid input
  char testStr[] = "  hello,world  ";
  char *end = NULL;
  char *result = getToken(testStr, &end, " ,");
  TEST_ASSERT_NOT_NULL(result, "getToken should return valid pointer");
  if (strncmp(result, "hello", 5) != 0) {
    printLog(ERR, "Expected result to start with \"hello\", found \"%s\".\n",
      result);
    return false;
  } else if (*end != ',') {
    printLog(ERR, "Expected end to be ',', found '%c'.\n", *end);
    return false;
  }
  
  // Test with NULL input
  result = getToken(NULL, &end, " ,");
  TEST_ASSERT_NULL(result, "getToken should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the bytesAllocate function
///
/// @return Returns true on success, false on failure
///
bool testBytesAllocate(void) {
  printLog(DEBUG, "Testing bytesAllocate function");
  
  printLog(DEBUG, "Test with valid input\n");
  Bytes buffer = NULL;
  Bytes result = bytesAllocate(&buffer, 10);
  TEST_ASSERT_NOT_NULL(result, "bytesAllocate should return valid pointer");
  TEST_ASSERT_EQ(bytesSize(result), 11, "bytesAllocate should set correct size");
  bytesDestroy(result);
  
  printLog(DEBUG, "Test with NULL buffer pointer");
  result = bytesAllocate(NULL, 10);
  TEST_ASSERT_NULL(result, "bytesAllocate should return NULL for NULL buffer pointer");
  
  return true;
}

///
/// @brief Test the bytesAddData function
///
/// @return Returns true on success, false on failure
///
bool testBytesAddData(void) {
  printLog(DEBUG, "Testing bytesAddData function");
  
  // Test with valid input
  Bytes buffer = NULL;
  char testData[] = "Hello";
  Bytes result = bytesAddData(&buffer, testData, 5);
  TEST_ASSERT_NOT_NULL(result, "bytesAddData should return valid pointer");
  TEST_ASSERT_EQ(bytesLength(result), 5, "bytesAddData should set correct length");
  bytesDestroy(result);
  
  // Test with NULL buffer pointer
  result = bytesAddData(NULL, testData, 5);
  TEST_ASSERT_NULL(result, "bytesAddData should return NULL for NULL buffer pointer");
  
  return true;
}

///
/// @brief Test the bytesAddBytes function
///
/// @return Returns true on success, false on failure
///
bool testBytesAddBytes(void) {
  printLog(DEBUG, "Testing bytesAddBytes function");
  
  // Test with NULL buffer pointer
  Bytes result = bytesAddBytes(NULL, NULL);
  TEST_ASSERT_NULL(result, "bytesAddBytes should return NULL for NULL buffer pointer");
  
  return true;
}

///
/// @brief Test the bytesAddStr function
///
/// @return Returns true on success, false on failure
///
bool testBytesAddStr(void) {
  printLog(DEBUG, "Testing bytesAddStr function");
  
  // Test with valid input
  Bytes buffer = NULL;
  Bytes result = bytesAddStr(&buffer, "Hello");
  TEST_ASSERT_NOT_NULL(result, "bytesAddStr should return valid pointer");
  bytesDestroy(result);
  
  // Test with NULL buffer pointer
  result = bytesAddStr(NULL, "Hello");
  TEST_ASSERT_NULL(result, "bytesAddStr should return NULL for NULL buffer pointer");
  
  return true;
}

///
/// @brief Test the bytesAddChr function
///
/// @return Returns true on success, false on failure
///
bool testBytesAddChr(void) {
  printLog(DEBUG, "Testing bytesAddChr function");
  
  // Test with valid input
  Bytes buffer = NULL;
  Bytes result = bytesAddChr(&buffer, 'A');
  TEST_ASSERT_NOT_NULL(result, "bytesAddChr should return valid pointer");
  bytesDestroy(result);
  
  // Test with NULL buffer pointer
  result = bytesAddChr(NULL, 'A');
  TEST_ASSERT_NULL(result, "bytesAddChr should return NULL for NULL buffer pointer");
  
  return true;
}

///
/// @brief Test the bytesReplace function
///
/// @return Returns true on success, false on failure
///
bool testBytesReplace(void) {
  printLog(DEBUG, "Testing bytesReplace function");
  
  // Test with NULL buffer pointer
  Bytes result = bytesReplace(NULL, "test", 4);
  TEST_ASSERT_NULL(result, "bytesReplace should return NULL for NULL buffer pointer");
  
  return true;
}

///
/// @brief Test the bytesDestroy function
///
/// @return Returns true on success, false on failure
///
bool testBytesDestroy(void) {
  printLog(DEBUG, "Testing bytesDestroy function");
  
  // Test with NULL input (should not crash and should return NULL)
  Bytes result = bytesDestroy(NULL);
  TEST_ASSERT_NULL(result, "bytesDestroy should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the escapeBytes function
///
/// @return Returns true on success, false on failure
///
bool testEscapeBytes(void) {
  printLog(DEBUG, "Testing escapeBytes function");
  
  // Test with NULL input
  char *result = escapeBytes(NULL);
  TEST_ASSERT_NULL(result, "escapeBytes should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the bytesArrayAddField function
///
/// @return Returns true on success, false on failure
///
bool testBytesArrayAddField(void) {
  printLog(DEBUG, "Testing bytesArrayAddField function");
  
  // Test with NULL array pointer
  bool result = bytesArrayAddField(NULL, 0);
  TEST_ASSERT_EQ(result, false, "bytesArrayAddField should return false for NULL array pointer");
  
  return true;
}

///
/// @brief Test the bytesTableAddField function
///
/// @return Returns true on success, false on failure
///
bool testBytesTableAddField(void) {
  printLog(DEBUG, "Testing bytesTableAddField function");
  
  // Test with NULL table pointer
  bool result = bytesTableAddField(NULL, 0);
  TEST_ASSERT_EQ(result, false, "bytesTableAddField should return false for NULL table pointer");
  
  return true;
}

///
/// @brief Test the dataToHexBytes function
///
/// @return Returns true on success, false on failure
///
bool testDataToHexBytes(void) {
  printLog(DEBUG, "Testing dataToHexBytes function");
  
  // Test with valid input
  char testData[] = "ABC";
  Bytes result = dataToHexBytes(testData, 3);
  TEST_ASSERT_NOT_NULL(result, "dataToHexBytes should return valid pointer");
  bytesDestroy(result);
  
  // Test with NULL input
  result = dataToHexBytes(NULL, 0);
  TEST_ASSERT_NULL(result, "dataToHexBytes should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the hexStringToBytes function
///
/// @return Returns true on success, false on failure
///
bool testHexStringToBytes(void) {
  printLog(DEBUG, "Testing hexStringToBytes function");
  
  // Test with valid input
  Bytes result = hexStringToBytes("414243", 6);
  TEST_ASSERT_NOT_NULL(result, "hexStringToBytes should return valid pointer");
  bytesDestroy(result);
  
  // Test with NULL input
  result = hexStringToBytes(NULL, 0);
  TEST_ASSERT_NULL(result, "hexStringToBytes should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the dataToBase64 function
///
/// @return Returns true on success, false on failure
///
bool testDataToBase64(void) {
  printLog(DEBUG, "Testing dataToBase64 function");
  
  // Test with valid input
  char testData[] = "Hello";
  Bytes result = dataToBase64(testData, 5);
  TEST_ASSERT_NOT_NULL(result, "dataToBase64 should return valid pointer");
  bytesDestroy(result);
  
  // Test with NULL input
  result = dataToBase64(NULL, 0);
  TEST_ASSERT_NULL(result, "dataToBase64 should return NULL for NULL input");
  
  return true;
}

///
/// @brief Test the base64ToBytes function
///
/// @return Returns true on success, false on failure
///
bool testBase64ToBytes(void) {
  printLog(DEBUG, "Testing base64ToBytes function");
  
  // Test with valid input
  Bytes result = base64ToBytes("SGVsbG8=", 8);
  TEST_ASSERT_NOT_NULL(result, "base64ToBytes should return valid pointer");
  bytesDestroy(result);
  
  // Test with NULL input
  result = base64ToBytes(NULL, 0);
  TEST_ASSERT_NULL(result, "base64ToBytes should return NULL for NULL input");
  
  return true;
}

///
/// @brief Main unit test function that runs all StringLib tests
///
/// @return Returns true if all tests pass, false if any test fails
///
bool stringLibUnitTest(void) {
  printLog(DEBUG, "Starting StringLib unit tests");
  
  // Run all test functions
  if (!testIndentText()) return false;
  if (!testUnescapeString()) return false;
  if (!testPlusToSpace()) return false;
  if (!testDosToUnix()) return false;
  if (!testStraddstr()) return false;
  if (!testStraddchr()) return false;
  if (!testDataAddData()) return false;
  if (!testGetFileLength()) return false;
  if (!testGetFileContent()) return false;
  if (!testPutFileContent()) return false;
  if (!testGetFileLine()) return false;
  if (!testUnampersand()) return false;
  if (!testHexToChar()) return false;
  if (!testStrReplaceOneStr()) return false;
  if (!testStrReplaceStr()) return false;
  if (!testEscapeString()) return false;
  if (!testStrrstr()) return false;
  if (!testStringToBytesTable()) return false;
  if (!testStringToBytesArray()) return false;
  if (!testFreeBytesArray()) return false;
  if (!testFreeBytesTable()) return false;
  if (!testBytesTableToString()) return false;
  if (!testBytesArrayToString()) return false;
  if (!testVasprintf()) return false;
  if (!testAsprintf()) return false;
  if (!testUnformatString()) return false;
  if (!testReverseString()) return false;
  if (!testArrayFindValueIndex()) return false;
  if (!testArrayRemoveValue()) return false;
  if (!testStringToLowerCase()) return false;
  if (!testStrstrci()) return false;
  if (!testStrncmpci()) return false;
  if (!testGetBytesBetweenCi()) return false;
  if (!testEscapeData()) return false;
  if (!testEscapeDataToBytes()) return false;
  if (!testUnescapeBytes()) return false;
  if (!testStraddbytes()) return false;
  if (!testBytesNCompare()) return false;
  if (!testBytesTableToCsv()) return false;
  if (!testCharToHex()) return false;
  if (!testBytesReplaceStr()) return false;
  if (!testDataFindData()) return false;
  if (!testGetDataBetween()) return false;
  if (!testVabprintf()) return false;
  if (!testAbprintf()) return false;
  if (!testIsInteger()) return false;
  if (!testIsNumber()) return false;
  if (!testGetProgramName()) return false;
  if (!testStringStartsWith()) return false;
  if (!testStringStartsWithCi()) return false;
  if (!testDataIsString()) return false;
  if (!testDataIsAscii()) return false;
  if (!testNonPrintableToWhitespace()) return false;
  if (!testDataEndsWith()) return false;
  if (!testUngets()) return false;
  if (!testGetToken()) return false;
  if (!testBytesAllocate()) return false;
  if (!testBytesAddData()) return false;
  if (!testBytesAddBytes()) return false;
  if (!testBytesAddStr()) return false;
  if (!testBytesAddChr()) return false;
  if (!testBytesReplace()) return false;
  if (!testBytesDestroy()) return false;
  if (!testEscapeBytes()) return false;
  if (!testBytesArrayAddField()) return false;
  if (!testBytesTableAddField()) return false;
  if (!testDataToHexBytes()) return false;
  if (!testHexStringToBytes()) return false;
  if (!testDataToBase64()) return false;
  if (!testBase64ToBytes()) return false;
  
  printLog(DEBUG, "All StringLib unit tests passed successfully");
  return true;
}
