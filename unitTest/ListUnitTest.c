///////////////////////////////////////////////////////////////////////////////
///
/// @file              ListUnitTest.c
///
/// @brief             Comprehensive unit test for the List data structure
///
/// @details           Tests all List functions with valid parameters and 
///                    corner cases including NULL parameters
///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"
#include "LoggingLib.h"

///////////////////////////////////////////////////////////////////////////////
/// @brief             Helper function to create a test string
/// @param value       The integer value to convert to string
/// @return            Allocated string that must be freed by caller
///////////////////////////////////////////////////////////////////////////////
char* createTestString(int value) {
  char* result = (char*) malloc(32);
  if (result != NULL) {
    snprintf(result, 32, "test_%d", value);
  }
  return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief             Test listCreate function with valid and invalid params
/// @return            true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testListCreate(void) {
  printLog(DEBUG, "Testing listCreate...\n");
  
  // Test with valid type descriptor
  List* list = listCreate(typeString);
  if (list == NULL) {
    printLog(ERR, "listCreate with valid type failed\n");
    return false;
  }
  
  // Clean up
  if (listDestroy(list) != NULL) {
    printLog(ERR, "listDestroy failed in testListCreate\n");
    return false;
  }
  
  // Test with NULL type descriptor (should fail)
  list = listCreate(NULL);
  if (list != NULL) {
    printLog(ERR, "listCreate with NULL type should have failed\n");
    listDestroy(list);
    return false;
  }
  
  printLog(DEBUG, "listCreate tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief             Test list add functions
/// @return            true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testListAdd(void) {
  printLog(DEBUG, "Testing list add functions...\n");
  
  List* list = listCreate(typeString);
  if (list == NULL) {
    printLog(ERR, "Failed to create list for add tests\n");
    return false;
  }
  
  // Test addFrontEntry with valid parameters
  char* key1 = createTestString(1);
  char* value1 = createTestString(10);
  ListNode* node1 = listAddFrontEntry(list, key1, value1, typeString);
  if (node1 == NULL) {
    printLog(ERR, "listAddFrontEntry with valid params failed\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  
  // Test addBackEntry with valid parameters
  char* key2 = createTestString(2);
  char* value2 = createTestString(20);
  ListNode* node2 = listAddBackEntry(list, key2, value2, typeString);
  if (node2 == NULL) {
    printLog(ERR, "listAddBackEntry with valid params failed\n");
    free(key1);
    free(value1);
    free(key2);
    free(value2);
    listDestroy(list);
    return false;
  }
  
  // Test addFrontEntry with NULL list (should fail)
  char* key3 = createTestString(3);
  char* value3 = createTestString(30);
  ListNode* node3 = listAddFrontEntry(NULL, key3, value3, typeString);
  if (node3 != NULL) {
    printLog(ERR, "listAddFrontEntry with NULL list should have failed\n");
    free(key1);
    free(value1);
    free(key2);
    free(value2);
    free(key3);
    free(value3);
    listDestroy(list);
    return false;
  }
  
  // Test addBackEntry with NULL list (should fail)
  ListNode* node4 = listAddBackEntry(NULL, key3, value3, typeString);
  if (node4 != NULL) {
    printLog(ERR, "listAddBackEntry with NULL list should have failed\n");
    free(key1);
    free(value1);
    free(key2);
    free(value2);
    free(key3);
    free(value3);
    listDestroy(list);
    return false;
  }
  
  // Clean up
  free(key1);
  free(value1);
  free(key2);
  free(value2);
  free(key3);
  free(value3);
  listDestroy(list);
  
  printLog(DEBUG, "List add tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief             Test list remove functions
/// @return            true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testListRemove(void) {
  printLog(DEBUG, "Testing list remove functions...\n");
  
  List* list = listCreate(typeString);
  if (list == NULL) {
    printLog(ERR, "Failed to create list for remove tests\n");
    return false;
  }
  
  // Add some test data
  char* key1 = createTestString(1);
  char* value1 = createTestString(10);
  char* key2 = createTestString(2);
  char* value2 = createTestString(20);
  
  if (listAddFrontEntry(list, key1, value1, typeString) == NULL ||
      listAddBackEntry(list, key2, value2, typeString) == NULL) {
    printLog(ERR, "Failed to add test data for remove tests\n");
    free(key1);
    free(value1);
    free(key2);
    free(value2);
    listDestroy(list);
    return false;
  }
  
  // Test removeFront with valid list
  if (listRemoveFront(list) != 0) {
    printLog(ERR, "listRemoveFront with valid list failed\n");
    free(key1);
    free(value1);
    free(key2);
    free(value2);
    listDestroy(list);
    return false;
  }
  
  // Test removeBack with valid list
  if (listRemoveBack(list) != 0) {
    printLog(ERR, "listRemoveBack with valid list failed\n");
    free(key1);
    free(value1);
    free(key2);
    free(value2);
    listDestroy(list);
    return false;
  }
  
  // Test remove functions with NULL list (should fail)
  if (listRemoveFront(NULL) == 0) {
    printLog(ERR, "listRemoveFront with NULL list should have failed\n");
    free(key1);
    free(value1);
    free(key2);
    free(value2);
    listDestroy(list);
    return false;
  }
  
  if (listRemoveBack(NULL) == 0) {
    printLog(ERR, "listRemoveBack with NULL list should have failed\n");
    free(key1);
    free(value1);
    free(key2);
    free(value2);
    listDestroy(list);
    return false;
  }
  
  if (listRemove(NULL, key1) == 0) {
    printLog(ERR, "listRemove with NULL list should have failed\n");
    free(key1);
    free(value1);
    free(key2);
    free(value2);
    listDestroy(list);
    return false;
  }
  
  // Clean up
  free(key1);
  free(value1);
  free(key2);
  free(value2);
  listDestroy(list);
  
  printLog(DEBUG, "List remove tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief             Test list get functions
/// @return            true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testListGet(void) {
  printLog(DEBUG, "Testing list get functions...\n");
  
  List* list = listCreate(typeString);
  if (list == NULL) {
    printLog(ERR, "Failed to create list for get tests\n");
    return false;
  }
  
  // Test get functions with empty list
  if (listGetFront(list) != NULL) {
    printLog(ERR, "listGetFront on empty list should return NULL\n");
    listDestroy(list);
    return false;
  }
  
  if (listGetBack(list) != NULL) {
    printLog(ERR, "listGetBack on empty list should return NULL\n");
    listDestroy(list);
    return false;
  }
  
  // Add test data
  char* key1 = createTestString(1);
  char* value1 = createTestString(10);
  char* key2 = createTestString(2);
  char* value2 = createTestString(20);
  
  if (listAddFrontEntry(list, key1, value1, typeString) == NULL ||
      listAddBackEntry(list, key2, value2, typeString) == NULL) {
    printLog(ERR, "Failed to add test data for get tests\n");
    free(key1);
    free(value1);
    free(key2);
    free(value2);
    listDestroy(list);
    return false;
  }
  
  // Test get functions with populated list
  ListNode* frontNode = listGetFront(list);
  if (frontNode == NULL) {
    printLog(ERR, "listGetFront on populated list failed\n");
    free(key1);
    free(value1);
    free(key2);
    free(value2);
    listDestroy(list);
    return false;
  }
  
  ListNode* backNode = listGetBack(list);
  if (backNode == NULL) {
    printLog(ERR, "listGetBack on populated list failed\n");
    free(key1);
    free(value1);
    free(key2);
    free(value2);
    listDestroy(list);
    return false;
  }
  
  // Test getForward and getReverse
  ListNode* forwardNode = listGetForward(list, key1);
  if (forwardNode == NULL) {
    printLog(ERR, "listGetForward with valid key failed\n");
    free(key1);
    free(value1);
    free(key2);
    free(value2);
    listDestroy(list);
    return false;
  }
  
  ListNode* reverseNode = listGetReverse(list, key2);
  if (reverseNode == NULL) {
    printLog(ERR, "listGetReverse with valid key failed\n");
    free(key1);
    free(value1);
    free(key2);
    free(value2);
    listDestroy(list);
    return false;
  }
  
  // Test get functions with NULL list (should fail)
  if (listGetFront(NULL) != NULL) {
    printLog(ERR, "listGetFront with NULL list should return NULL\n");
    free(key1);
    free(value1);
    free(key2);
    free(value2);
    listDestroy(list);
    return false;
  }
  
  if (listGetBack(NULL) != NULL) {
    printLog(ERR, "listGetBack with NULL list should return NULL\n");
    free(key1);
    free(value1);
    free(key2);
    free(value2);
    listDestroy(list);
    return false;
  }
  
  if (listGetForward(NULL, key1) != NULL) {
    printLog(ERR, "listGetForward with NULL list should return NULL\n");
    free(key1);
    free(value1);
    free(key2);
    free(value2);
    listDestroy(list);
    return false;
  }
  
  if (listGetReverse(NULL, key1) != NULL) {
    printLog(ERR, "listGetReverse with NULL list should return NULL\n");
    free(key1);
    free(value1);
    free(key2);
    free(value2);
    listDestroy(list);
    return false;
  }
  
  // Clean up
  free(key1);
  free(value1);
  free(key2);
  free(value2);
  listDestroy(list);
  
  printLog(DEBUG, "List get tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief             Test list utility functions
/// @return            true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testListUtilities(void) {
  printLog(DEBUG, "Testing list utility functions...\n");
  
  List* list = listCreate(typeString);
  if (list == NULL) {
    printLog(ERR, "Failed to create list for utility tests\n");
    return false;
  }
  
  // Test length, size, and isEmpty on empty list
  if (listLength(list) != 0) {
    printLog(ERR, "listLength on empty list should return 0\n");
    listDestroy(list);
    return false;
  }
  
  if (listSize(list) != sizeof(List)) {
    printLog(ERR, "listSize on allocated list should return %d\n",
      (int) sizeof(List));
    listDestroy(list);
    return false;
  }
  
  if (!listIsEmpty(list)) {
    printLog(ERR, "listIsEmpty on empty list should return true\n");
    listDestroy(list);
    return false;
  }
  
  // Add test data
  char* key1 = createTestString(1);
  char* value1 = createTestString(10);
  
  if (listAddFrontEntry(list, key1, value1, typeString) == NULL) {
    printLog(ERR, "Failed to add test data for utility tests\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  
  // Test length and isEmpty on populated list
  if (listLength(list) != 1) {
    printLog(ERR, "listLength on populated list should return 1\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  
  if (listIsEmpty(list)) {
    printLog(ERR, "listIsEmpty on populated list should return false\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  
  // Test toString
  char* stringRep = listToString(list);
  if (stringRep == NULL) {
    printLog(ERR, "listToString with valid list failed\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  free(stringRep);
  
  // Test toBytes
  Bytes bytesRep = listToBytes(list);
  if (bytesRep == NULL) {
    printLog(ERR, "listToBytes with valid list failed\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  bytesRep = bytesDestroy(bytesRep);
  
  // Test toBlob
  Bytes blobRep = listToBlob(list);
  if (blobRep == NULL) {
    printLog(ERR, "listToBlob with valid list failed\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  blobRep = bytesDestroy(blobRep);
  
  // Test toJson
  Bytes jsonRep = listToJson(list);
  if (jsonRep == NULL) {
    printLog(ERR, "listToJson with valid list failed\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  jsonRep = bytesDestroy(jsonRep);
  
  // Test toXml
  Bytes xmlRep = listToXml(list, "testElement");
  if (xmlRep == NULL) {
    printLog(ERR, "listToXml with valid list failed\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  xmlRep = bytesDestroy(xmlRep);
  
  // Test toKeyValueString
  char* kvString = listToKeyValueString(list, "=");
  if (kvString == NULL) {
    printLog(ERR, "listToKeyValueString with valid list failed\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  free(kvString);
  
  // Test with NULL parameters (should fail)
  stringRep = listToString(NULL);
  if (stringRep == NULL) {
    printLog(ERR,
      "listToString with NULL list should return an empty string, got NULL\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  } else if (*stringRep != '\0') {
    printLog(ERR,
      "listToString with NULL list should return an empty string, got \"%s\"\n",
      stringRep);
    free(stringRep);
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  free(stringRep);
  
  if (listToBytes(NULL) != NULL) {
    printLog(ERR, "listToBytes with NULL list should return NULL\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  
  if (listLength(NULL) != 0) {
    printLog(ERR, "listLength with NULL list should return 0\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  
  if (listSize(NULL) != 0) {
    printLog(ERR, "listSize with NULL list should return 0\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  
  // Test clear
  if (listClear(list) != 0) {
    printLog(ERR, "listClear with valid list failed\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  
  if (listClear(NULL) != 0) {
    printLog(ERR, "listClear with NULL list should have succeeded\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  
  // Clean up
  free(key1);
  free(value1);
  listDestroy(list);
  
  printLog(DEBUG, "List utility tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief             Test list copy and compare functions
/// @return            true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testListCopyCompare(void) {
  printLog(DEBUG, "Testing list copy and compare functions...\n");
  
  List* list1 = listCreate(typeString);
  List* list2 = listCreate(typeString);
  if (list1 == NULL || list2 == NULL) {
    printLog(ERR, "Failed to create lists for copy/compare tests\n");
    if (list1) listDestroy(list1);
    if (list2) listDestroy(list2);
    return false;
  }
  
  // Add test data to list1
  char* key1 = createTestString(1);
  char* value1 = createTestString(10);
  
  if (listAddFrontEntry(list1, key1, value1, typeString) == NULL) {
    printLog(ERR, "Failed to add test data for copy/compare tests\n");
    free(key1);
    free(value1);
    listDestroy(list1);
    listDestroy(list2);
    return false;
  }
  
  // Test copy
  List* copiedList = listCopy(list1);
  if (copiedList == NULL) {
    printLog(ERR, "listCopy with valid list failed\n");
    free(key1);
    free(value1);
    listDestroy(list1);
    listDestroy(list2);
    return false;
  }
  
  // Test compare with identical lists
  if (listCompare(list1, copiedList) != 0) {
    printLog(ERR, "listCompare with identical lists should return 0\n");
    free(key1);
    free(value1);
    listDestroy(list1);
    listDestroy(list2);
    listDestroy(copiedList);
    return false;
  }
  
  // Test compare with different lists
  if (listCompare(list1, list2) == 0) {
    printLog(ERR, "listCompare with different lists should not return 0\n");
    free(key1);
    free(value1);
    listDestroy(list1);
    listDestroy(list2);
    listDestroy(copiedList);
    return false;
  }
  
  // Test with NULL parameters (should fail)
  if (listCopy(NULL) != NULL) {
    printLog(ERR, "listCopy with NULL list should return NULL\n");
    free(key1);
    free(value1);
    listDestroy(list1);
    listDestroy(list2);
    listDestroy(copiedList);
    return false;
  }
  
  // Note: listCompare with NULL may have defined behavior, 
  // so we won't test it as failure
  
  // Clean up
  free(key1);
  free(value1);
  listDestroy(list1);
  listDestroy(list2);
  listDestroy(copiedList);
  
  printLog(DEBUG, "List copy and compare tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief             Test list serialization functions
/// @return            true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testListSerialization(void) {
  printLog(DEBUG, "Testing list serialization functions...\n");
  
  // Test xmlToList and jsonToList with NULL input
  List* listFromXml = xmlToList(NULL);
  if (listFromXml != NULL) {
    printLog(ERR, "xmlToList with NULL input should return NULL\n");
    listDestroy(listFromXml);
    return false;
  }
  
  long long int position = 0;
  List* listFromJson = jsonToList(NULL, &position);
  if (listFromJson != NULL) {
    printLog(ERR, "jsonToList with NULL input should return NULL\n");
    listDestroy(listFromJson);
    return false;
  }
  
  // Test listFromBlob with NULL input
  u64 length = 0;
  List* listFromBlob = listFromBlob(NULL, &length);
  if (listFromBlob != NULL) {
    printLog(ERR, "listFromBlob with NULL input should return NULL\n");
    listDestroy(listFromBlob);
    return false;
  }
  
  printLog(DEBUG, "List serialization tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief             Test list destroy node function
/// @return            true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testListDestroyNode(void) {
  printLog(DEBUG, "Testing listDestroyNode function...\n");
  
  List* list = listCreate(typeString);
  if (list == NULL) {
    printLog(ERR, "Failed to create list for destroyNode tests\n");
    return false;
  }
  
  // Add test data
  char* key1 = createTestString(1);
  char* value1 = createTestString(10);
  
  ListNode* node = listAddFrontEntry(list, key1, value1, typeString);
  if (node == NULL) {
    printLog(ERR, "Failed to add test data for destroyNode tests\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  
  // Test destroyNode with valid parameters
  if (listDestroyNode(list, node) != 0) {
    printLog(ERR, "listDestroyNode with valid parameters failed\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  
  // Test destroyNode with NULL parameters (should fail)
  if (listDestroyNode(NULL, NULL) == 0) {
    printLog(ERR, "listDestroyNode with NULL parameters should have failed\n");
    free(key1);
    free(value1);
    listDestroy(list);
    return false;
  }
  
  // Clean up
  free(key1);
  free(value1);
  listDestroy(list);
  
  printLog(DEBUG, "listDestroyNode tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief             Main unit test function for List data structure
/// @return            true if all tests pass, false if any test fails
///////////////////////////////////////////////////////////////////////////////
bool listUnitTest(void) {
  printLog(DEBUG, "Starting List unit tests...\n");
  
  // Test list creation
  if (!testListCreate()) {
    printLog(ERR, "List creation tests failed\n");
    return false;
  }
  
  // Test list add functions
  if (!testListAdd()) {
    printLog(ERR, "List add tests failed\n");
    return false;
  }
  
  // Test list remove functions
  if (!testListRemove()) {
    printLog(ERR, "List remove tests failed\n");
    return false;
  }
  
  // Test list get functions
  if (!testListGet()) {
    printLog(ERR, "List get tests failed\n");
    return false;
  }
  
  // Test list utility functions
  if (!testListUtilities()) {
    printLog(ERR, "List utility tests failed\n");
    return false;
  }
  
  // Test list copy and compare functions
  if (!testListCopyCompare()) {
    printLog(ERR, "List copy/compare tests failed\n");
    return false;
  }
  
  // Test list serialization functions
  if (!testListSerialization()) {
    printLog(ERR, "List serialization tests failed\n");
    return false;
  }
  
  // Test list destroy node function
  if (!testListDestroyNode()) {
    printLog(ERR, "List destroyNode tests failed\n");
    return false;
  }
  
  printLog(DEBUG, "All List unit tests passed successfully!\n");
  return true;
}
