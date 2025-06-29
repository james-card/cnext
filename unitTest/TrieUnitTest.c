///////////////////////////////////////////////////////////////////////////////
///
/// @file              trieUnitTest.c
///
/// @brief             Unit test for the Trie data structure implementation.
///
///////////////////////////////////////////////////////////////////////////////

#include "Trie.h"
#include "LoggingLib.h"
#include <string.h>
#include <stdio.h>

// Test data structures and constants
#define TEST_STRING_1 "hello"
#define TEST_STRING_2 "world"
#define TEST_STRING_3 "test"
#define TEST_VALUE_1 ((void*) 0x1234)
#define TEST_VALUE_2 ((void*) 0x5678)
#define TEST_VALUE_3 ((void*) 0x9ABC)

static int destructorCallCount = 0;

///
/// @brief Test destructor function to track destructor calls.
///
/// @param value The value being destroyed.
///
void testDestructor(void *value) {
  if (value != NULL) {
    destructorCallCount++;
    printLog(DEBUG, "Destructor called for value %p", value);
  }
}

///
/// @brief Test basic trie creation and destruction.
///
/// @return true if test passes, false otherwise.
///
bool testTrieCreateDestroy(void) {
  printLog(DEBUG, "Testing trie creation and destruction");
  
  // Test creation with NULL destructor
  Trie *trie1 = trieCreate(NULL);
  if (trie1 == NULL) {
    printLog(ERR, "Failed to create trie with NULL destructor");
    return false;
  }
  
  // Test creation with valid destructor
  Trie *trie2 = trieCreate(testDestructor);
  if (trie2 == NULL) {
    printLog(ERR, "Failed to create trie with valid destructor");
    trieDestroy(trie1);
    return false;
  }
  
  // Test destruction
  Trie *result1 = trieDestroy(trie1);
  if (result1 != NULL) {
    printLog(ERR, "trieDestroy should return NULL on success");
    trieDestroy(trie2);
    return false;
  }
  
  Trie *result2 = trieDestroy(trie2);
  if (result2 != NULL) {
    printLog(ERR, "trieDestroy should return NULL on success");
    return false;
  }
  
  // Test destruction of NULL trie
  Trie *result3 = trieDestroy(NULL);
  if (result3 != NULL) {
    printLog(ERR, "trieDestroy(NULL) should return NULL");
    return false;
  }
  
  printLog(DEBUG, "Trie creation and destruction tests passed");
  return true;
}

///
/// @brief Test basic value operations (set/get/delete).
///
/// @return true if test passes, false otherwise.
///
bool testBasicValueOperations(void) {
  printLog(DEBUG, "Testing basic value operations");
  
  Trie *trie = trieCreate(testDestructor);
  if (trie == NULL) {
    printLog(ERR, "Failed to create trie for basic operations test");
    return false;
  }
  
  // Test setting and getting a string key
  void *result = trieSetValue(trie, TEST_STRING_1, strlen(TEST_STRING_1), 
                             TEST_VALUE_1);
  if (result != NULL) {
    printLog(ERR, "trieSetValue should return the previous value (NULL)");
    trieDestroy(trie);
    return false;
  }
  
  void *getValue = trieGetValue(trie, TEST_STRING_1, strlen(TEST_STRING_1));
  if (getValue != TEST_VALUE_1) {
    printLog(ERR, "trieGetValue failed to retrieve set value");
    trieDestroy(trie);
    return false;
  }
  
  // Test setting a different key
  result = trieSetValue(trie, TEST_STRING_2, strlen(TEST_STRING_2), 
                       TEST_VALUE_2);
  if (result != NULL) {
    printLog(ERR, "trieSetValue failed for second key");
    trieDestroy(trie);
    return false;
  }
  
  // Verify first key is still there
  getValue = trieGetValue(trie, TEST_STRING_1, strlen(TEST_STRING_1));
  if (getValue != TEST_VALUE_1) {
    printLog(ERR, "First key value was corrupted");
    trieDestroy(trie);
    return false;
  }
  
  // Test overwriting a value
  destructorCallCount = 0;
  result = trieSetValue(trie, TEST_STRING_1, strlen(TEST_STRING_1), 
                       TEST_VALUE_3);
  if (result != TEST_VALUE_1) {
    printLog(ERR, "trieSetValue failed to overwrite value 1");
    trieDestroy(trie);
    return false;
  }
  
  if (destructorCallCount != 0) {
    printLog(ERR, "Destructor should not have been called for overwrite");
    trieDestroy(trie);
    return false;
  }
  
  // Test deletion
  destructorCallCount = 0;
  int deleteResult = trieDeleteValue(trie, TEST_STRING_1, 
                                    strlen(TEST_STRING_1));
  if (deleteResult != 0) {
    printLog(ERR, "trieDeleteValue failed");
    trieDestroy(trie);
    return false;
  }
  
  if (destructorCallCount != 1) {
    printLog(ERR, "Destructor should have been called once for delete");
    trieDestroy(trie);
    return false;
  }
  
  // Verify value is gone
  getValue = trieGetValue(trie, TEST_STRING_1, strlen(TEST_STRING_1));
  if (getValue != NULL) {
    printLog(ERR, "Value should be NULL after deletion");
    trieDestroy(trie);
    return false;
  }
  
  trieDestroy(trie);
  printLog(DEBUG, "Basic value operations tests passed");
  return true;
}

///
/// @brief Test dual key operations (set/get/delete with two keys).
///
/// @return true if test passes, false otherwise.
///
bool testDualKeyOperations(void) {
  printLog(DEBUG, "Testing dual key operations");
  
  Trie *trie = trieCreate(testDestructor);
  if (trie == NULL) {
    printLog(ERR, "Failed to create trie for dual key operations test");
    return false;
  }
  
  // Test setting value with two keys
  void *result = trieSetValue2(trie, TEST_STRING_1, strlen(TEST_STRING_1),
                              TEST_STRING_2, strlen(TEST_STRING_2),
                              TEST_VALUE_1, testDestructor);
  if (result != NULL) {
    printLog(ERR, "trieSetValue2 should return the previous value (NULL)");
    trieDestroy(trie);
    return false;
  }
  
  // Test getting value with two keys
  void *getValue = trieGetValue2(trie, TEST_STRING_1, strlen(TEST_STRING_1),
                                TEST_STRING_2, strlen(TEST_STRING_2));
  if (getValue != TEST_VALUE_1) {
    printLog(ERR, "trieGetValue2 failed to retrieve set value");
    trieDestroy(trie);
    return false;
  }
  
  // Test getting with wrong second key
  getValue = trieGetValue2(trie, TEST_STRING_1, strlen(TEST_STRING_1),
                          TEST_STRING_3, strlen(TEST_STRING_3));
  if (getValue != NULL) {
    printLog(ERR, "trieGetValue2 should return NULL for wrong key");
    trieDestroy(trie);
    return false;
  }
  
  // Test deletion with two keys
  destructorCallCount = 0;
  int deleteResult = trieDeleteValue2(trie, TEST_STRING_1, 
                                     strlen(TEST_STRING_1),
                                     TEST_STRING_2, strlen(TEST_STRING_2));
  if (deleteResult != 0) {
    printLog(ERR, "trieDeleteValue2 failed");
    trieDestroy(trie);
    return false;
  }
  
  if (destructorCallCount != 1) {
    printLog(ERR, "Destructor should have been called once for delete2");
    trieDestroy(trie);
    return false;
  }
  
  // Verify value is gone
  getValue = trieGetValue2(trie, TEST_STRING_1, strlen(TEST_STRING_1),
                          TEST_STRING_2, strlen(TEST_STRING_2));
  if (getValue != NULL) {
    printLog(ERR, "Value should be NULL after deletion2");
    trieDestroy(trie);
    return false;
  }
  
  trieDestroy(trie);
  printLog(DEBUG, "Dual key operations tests passed");
  return true;
}

///
/// @brief Test corner cases and NULL parameter handling.
///
/// @return true if test passes, false otherwise.
///
bool testTrieCornerCases(void) {
  printLog(DEBUG, "Testing corner cases and NULL parameters");
  
  Trie *trie = trieCreate(NULL);
  if (trie == NULL) {
    printLog(ERR, "Failed to create trie for corner cases test");
    return false;
  }
  
  // Test NULL trie parameter
  void *result = trieGetValue(NULL, TEST_STRING_1, strlen(TEST_STRING_1));
  if (result != NULL) {
    printLog(ERR, "trieGetValue(NULL trie) should return NULL");
    trieDestroy(trie);
    return false;
  }
  
  result = trieSetValue(NULL, TEST_STRING_1, strlen(TEST_STRING_1), 
                       TEST_VALUE_1);
  if (result != NULL) {
    printLog(ERR, "trieSetValue(NULL trie) should return NULL");
    trieDestroy(trie);
    return false;
  }
  
  int deleteResult = trieDeleteValue(NULL, TEST_STRING_1, 
                                    strlen(TEST_STRING_1));
  if (deleteResult == 0) {
    printLog(ERR, "trieDeleteValue(NULL trie) should fail");
    trieDestroy(trie);
    return false;
  }
  
  // Test NULL key parameter
  result = trieGetValue(trie, NULL, 5);
  if (result != NULL) {
    printLog(ERR, "trieGetValue(NULL key) should return NULL");
    trieDestroy(trie);
    return false;
  }
  
  result = trieSetValue(trie, NULL, 5, TEST_VALUE_1);
  if (result != NULL) {
    printLog(ERR, "trieSetValue(NULL key) should return NULL");
    trieDestroy(trie);
    return false;
  }
  
  deleteResult = trieDeleteValue(trie, NULL, 5);
  if (deleteResult == 0) {
    printLog(ERR, "trieDeleteValue(NULL key) should fail");
    trieDestroy(trie);
    return false;
  }
  
  // Test zero key size
  result = trieGetValue(trie, TEST_STRING_1, 0);
  if (result != NULL) {
    printLog(ERR, "trieGetValue(zero size) should return NULL");
    trieDestroy(trie);
    return false;
  }
  
  // Test setting NULL value
  result = trieSetValue(trie, TEST_STRING_1, strlen(TEST_STRING_1), NULL);
  if (result != NULL) {
    printLog(ERR, "trieSetValue(NULL value) should return NULL");
    trieDestroy(trie);
    return false;
  }
  
  // Test TRIE_STRING_KEY constant
  result = trieSetValue(trie, TEST_STRING_1, TRIE_STRING_KEY, TEST_VALUE_1);
  if (result != NULL) {
    printLog(ERR, "trieSetValue with TRIE_STRING_KEY should return previous value (NULL)");
    trieDestroy(trie);
    return false;
  }
  
  result = trieGetValue(trie, TEST_STRING_1, TRIE_STRING_KEY);
  if (result != TEST_VALUE_1) {
    printLog(ERR, "trieGetValue with TRIE_STRING_KEY should work");
    trieDestroy(trie);
    return false;
  }
  
  // Test dual key functions with NULL parameters
  result = trieGetValue2(NULL, TEST_STRING_1, strlen(TEST_STRING_1),
                        TEST_STRING_2, strlen(TEST_STRING_2));
  if (result != NULL) {
    printLog(ERR, "trieGetValue2(NULL trie) should return NULL");
    trieDestroy(trie);
    return false;
  }
  
  result = trieGetValue2(trie, NULL, strlen(TEST_STRING_1),
                        TEST_STRING_2, strlen(TEST_STRING_2));
  if (result != NULL) {
    printLog(ERR, "trieGetValue2(NULL key1) should return NULL");
    trieDestroy(trie);
    return false;
  }
  
  result = trieGetValue2(trie, TEST_STRING_1, strlen(TEST_STRING_1),
                        NULL, strlen(TEST_STRING_2));
  if (result != NULL) {
    printLog(ERR, "trieGetValue2(NULL key2) should return NULL");
    trieDestroy(trie);
    return false;
  }
  
  // Test deleting non-existent key
  deleteResult = trieDeleteValue(trie, TEST_STRING_3, strlen(TEST_STRING_3));
  if (deleteResult != 0) {
    printLog(ERR, "trieDeleteValue(non-existent) should succeed");
    trieDestroy(trie);
    return false;
  }
  
  trieDestroy(trie);
  printLog(DEBUG, "Corner cases and NULL parameter tests passed");
  return true;
}

///
/// @brief Test binary key handling.
///
/// @return true if test passes, false otherwise.
///
bool testBinaryKeys(void) {
  printLog(DEBUG, "Testing binary key handling");
  
  Trie *trie = trieCreate(NULL);
  if (trie == NULL) {
    printLog(ERR, "Failed to create trie for binary key test");
    return false;
  }
  
  // Test with binary data containing null bytes
  uint8_t binaryKey[] = {0x00, 0x01, 0x02, 0x00, 0xFF, 0xFE};
  size_t binaryKeySize = sizeof(binaryKey);
  
  void *result = trieSetValue(trie, binaryKey, binaryKeySize, TEST_VALUE_1);
  if (result != NULL) {
    printLog(ERR, "trieSetValue failed with binary key");
    trieDestroy(trie);
    return false;
  }
  
  void *getValue = trieGetValue(trie, binaryKey, binaryKeySize);
  if (getValue != TEST_VALUE_1) {
    printLog(ERR, "trieGetValue failed with binary key");
    trieDestroy(trie);
    return false;
  }
  
  // Test with different but similar binary key
  uint8_t binaryKey2[] = {0x00, 0x01, 0x02, 0x00, 0xFF, 0xFD};
  getValue = trieGetValue(trie, binaryKey2, sizeof(binaryKey2));
  if (getValue != NULL) {
    printLog(ERR, "trieGetValue should return NULL for different binary key");
    trieDestroy(trie);
    return false;
  }
  
  // Test deletion of binary key
  int deleteResult = trieDeleteValue(trie, binaryKey, binaryKeySize);
  if (deleteResult != 0) {
    printLog(ERR, "trieDeleteValue failed with binary key");
    trieDestroy(trie);
    return false;
  }
  
  trieDestroy(trie);
  printLog(DEBUG, "Binary key handling tests passed");
  return true;
}

///
/// @brief Main unit test function that runs all trie tests.
///
/// @return true if all tests pass, false if any test fails.
///
bool trieUnitTest(void) {
  printLog(DEBUG, "Starting Trie unit tests");
  
  if (!testTrieCreateDestroy()) {
    printLog(ERR, "Trie creation/destruction test failed");
    return false;
  }
  
  if (!testBasicValueOperations()) {
    printLog(ERR, "Basic value operations test failed");
    return false;
  }
  
  if (!testDualKeyOperations()) {
    printLog(ERR, "Dual key operations test failed");
    return false;
  }
  
  if (!testTrieCornerCases()) {
    printLog(ERR, "Corner cases test failed");
    return false;
  }
  
  if (!testBinaryKeys()) {
    printLog(ERR, "Binary key handling test failed");
    return false;
  }
  
  printLog(DEBUG, "All Trie unit tests passed successfully");
  return true;
}
