///////////////////////////////////////////////////////////////////////////////
///
/// @file              VectorUnitTest.c
///
/// @brief             Comprehensive unit test for the Vector data structure
///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Vector.h"
#include "DataTypes.h"
#include "LoggingLib.h"

///////////////////////////////////////////////////////////////////////////////
/// @brief Helper function to create test strings
/// @param index The index to incorporate into the string
/// @return A dynamically allocated string that must be freed
///////////////////////////////////////////////////////////////////////////////
char* createVectorTestString(int index) {
  char *result = (char*) malloc(32);
  if (result != NULL) {
    snprintf(result, 32, "TestString%d", index);
  }
  return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Helper function to create test integers
/// @param value The integer value to create
/// @return A dynamically allocated integer pointer
///////////////////////////////////////////////////////////////////////////////
int32_t* createTestInt(int value) {
  int32_t *result = (int32_t*) malloc(sizeof(int32_t));
  if (result != NULL) {
    *result = value;
  }
  return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Test vector creation and destruction
/// @return true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testVectorCreateDestroy(void) {
  printLog(DEBUG, "Testing vector creation and destruction...\n");
  
  // Test basic vector creation
  Vector *vector = vectorCreate(typeString);
  if (vector == NULL) {
    printLog(ERR, "Failed to create basic vector\n");
    return false;
  }
  
  // Test vector destruction
  Vector *destroyResult = vectorDestroy(vector);
  if (destroyResult != NULL) {
    printLog(ERR, "Vector destruction failed\n");
    return false;
  }
  
  // Test key-value vector creation
  Vector *kvVector = kvVectorCreate(typeString, typeI32);
  if (kvVector == NULL) {
    printLog(ERR, "Failed to create key-value vector\n");
    return false;
  }
  
  destroyResult = kvVectorDestroy(kvVector);
  if (destroyResult != NULL) {
    printLog(ERR, "Key-value vector destruction failed\n");
    return false;
  }
  
  // Test destroying NULL vector (should succeed)
  destroyResult = vectorDestroy(NULL);
  if (destroyResult != NULL) {
    printLog(ERR, "Destroying NULL vector should succeed\n");
    return false;
  }
  
  printLog(DEBUG, "Vector creation and destruction tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Test vector entry operations
/// @return true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testVectorEntryOperations(void) {
  printLog(DEBUG, "Testing vector entry operations...\n");
  
  Vector *vector = vectorCreate(typeString);
  if (vector == NULL) {
    printLog(ERR, "Failed to create vector for entry operations test\n");
    return false;
  }
  
  // Test setting entries
  char *testStr1 = createVectorTestString(1);
  char *testStr2 = createVectorTestString(2);
  char *testStr3 = createVectorTestString(3);
  
  if (testStr1 == NULL || testStr2 == NULL || testStr3 == NULL) {
    printLog(ERR, "Failed to create test strings\n");
    free(testStr1);
    free(testStr2);
    free(testStr3);
    vectorDestroy(vector);
    return false;
  }
  
  VectorNode *node1 = vectorSetEntry(vector, 0, testStr1);
  VectorNode *node2 = vectorSetEntry(vector, 1, testStr2);
  VectorNode *node3 = vectorSetEntry(vector, 5, testStr3); // Non-contiguous
  
  if (node1 == NULL || node2 == NULL || node3 == NULL) {
    printLog(ERR, "Failed to set vector entries\n");
    free(testStr1);
    free(testStr2);
    free(testStr3);
    vectorDestroy(vector);
    return false;
  }
  
  // Test getting entries
  VectorNode *retrievedNode1 = vectorGetEntry(vector, 0);
  VectorNode *retrievedNode2 = vectorGetEntry(vector, 1);
  VectorNode *retrievedNode3 = vectorGetEntry(vector, 5);
  
  if (retrievedNode1 == NULL || retrievedNode2 == NULL || 
      retrievedNode3 == NULL) {
    printLog(ERR, "Failed to get vector entries\n");
    free(testStr1);
    free(testStr2);
    free(testStr3);
    vectorDestroy(vector);
    return false;
  }
  
  // Test getting values directly
  void *value1 = vectorGetValue(vector, 0);
  void *value2 = vectorGetValue(vector, 1);
  void *value3 = vectorGetValue(vector, 5);
  
  if (value1 == NULL || value2 == NULL || value3 == NULL) {
    printLog(ERR, "Failed to get vector values\n");
    free(testStr1);
    free(testStr2);
    free(testStr3);
    vectorDestroy(vector);
    return false;
  }
  
  // Test getting non-existent entry
  VectorNode *nonExistent = vectorGetEntry(vector, 10);
  if (nonExistent != NULL) {
    printLog(ERR, "Getting non-existent entry should return NULL\n");
    free(testStr1);
    free(testStr2);
    free(testStr3);
    vectorDestroy(vector);
    return false;
  }
  
  // Test getting value from non-existent entry
  void *nonExistentValue = vectorGetValue(vector, 10);
  if (nonExistentValue != NULL) {
    printLog(ERR, "Getting value from non-existent entry should return NULL\n");
    free(testStr1);
    free(testStr2);
    free(testStr3);
    vectorDestroy(vector);
    return false;
  }
  
  // Test operations on NULL vector
  VectorNode *nullResult = vectorSetEntry(NULL, 0, testStr1);
  if (nullResult != NULL) {
    printLog(ERR, "Setting entry on NULL vector should return NULL\n");
    free(testStr1);
    free(testStr2);
    free(testStr3);
    vectorDestroy(vector);
    return false;
  }
  
  VectorNode *nullGetResult = vectorGetEntry(NULL, 0);
  if (nullGetResult != NULL) {
    printLog(ERR, "Getting entry from NULL vector should return NULL\n");
    free(testStr1);
    free(testStr2);
    free(testStr3);
    vectorDestroy(vector);
    return false;
  }
  
  void *nullValueResult = vectorGetValue(NULL, 0);
  if (nullValueResult != NULL) {
    printLog(ERR, "Getting value from NULL vector should return NULL\n");
    free(testStr1);
    free(testStr2);
    free(testStr3);
    vectorDestroy(vector);
    return false;
  }
  
  free(testStr1);
  free(testStr2);
  free(testStr3);
  vectorDestroy(vector);
  
  printLog(DEBUG, "Vector entry operations tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Test key-value vector operations
/// @return true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testKvVectorOperations(void) {
  printLog(DEBUG, "Testing key-value vector operations...\n");
  
  Vector *kvVector = kvVectorCreate(typeString, typeI32);
  if (kvVector == NULL) {
    printLog(ERR, "Failed to create key-value vector\n");
    return false;
  }
  
  // Create test data
  char *key1 = createVectorTestString(1);
  char *key2 = createVectorTestString(2);
  int32_t *value1 = createTestInt(100);
  int32_t *value2 = createTestInt(200);
  
  if (key1 == NULL || key2 == NULL || value1 == NULL || value2 == NULL) {
    printLog(ERR, "Failed to create test data for key-value vector\n");
    free(key1);
    free(key2);
    free(value1);
    free(value2);
    kvVectorDestroy(kvVector);
    return false;
  }
  
  // Test setting key-value entries
  VectorNode *kvNode1 = kvVectorSetEntry(kvVector, 0, key1, value1);
  VectorNode *kvNode2 = kvVectorSetEntry(kvVector, 1, key2, value2);
  
  if (kvNode1 == NULL || kvNode2 == NULL) {
    printLog(ERR, "Failed to set key-value entries\n");
    free(key1);
    free(key2);
    free(value1);
    free(value2);
    kvVectorDestroy(kvVector);
    return false;
  }
  
  // Test adding key-value entries
  char *key3 = createVectorTestString(3);
  int32_t *value3 = createTestInt(300);
  
  if (key3 == NULL || value3 == NULL) {
    printLog(ERR, "Failed to create test data for adding entry\n");
    free(key1);
    free(key2);
    free(value1);
    free(value2);
    free(key3);
    free(value3);
    kvVectorDestroy(kvVector);
    return false;
  }
  
  VectorNode *kvNode3 = kvVectorAddEntry(kvVector, key3, value3);
  if (kvNode3 == NULL) {
    printLog(ERR, "Failed to add key-value entry\n");
    free(key1);
    free(key2);
    free(value1);
    free(value2);
    free(key3);
    free(value3);
    kvVectorDestroy(kvVector);
    return false;
  }
  
  // Test getting entries by key
  VectorNode *retrievedKvNode1 = kvVectorGetEntry(kvVector, key1);
  VectorNode *retrievedKvNode2 = kvVectorGetEntry(kvVector, key2);
  
  if (retrievedKvNode1 == NULL || retrievedKvNode2 == NULL) {
    printLog(ERR, "Failed to get key-value entries by key\n");
    free(key1);
    free(key2);
    free(value1);
    free(value2);
    free(key3);
    free(value3);
    kvVectorDestroy(kvVector);
    return false;
  }
  
  // Test getting values by key
  void *retrievedValue1 = kvVectorGetValue(kvVector, key1);
  void *retrievedValue2 = kvVectorGetValue(kvVector, key2);
  
  if (retrievedValue1 == NULL || retrievedValue2 == NULL) {
    printLog(ERR, "Failed to get values by key\n");
    free(key1);
    free(key2);
    free(value1);
    free(value2);
    free(key3);
    free(value3);
    kvVectorDestroy(kvVector);
    return false;
  }
  
  // Test getting non-existent key
  char *nonExistentKey = createVectorTestString(999);
  if (nonExistentKey == NULL) {
    printLog(ERR, "Failed to create non-existent key\n");
    free(key1);
    free(key2);
    free(value1);
    free(value2);
    free(key3);
    free(value3);
    kvVectorDestroy(kvVector);
    return false;
  }
  
  VectorNode *nonExistentEntry = kvVectorGetEntry(kvVector, nonExistentKey);
  void *nonExistentValue = kvVectorGetValue(kvVector, nonExistentKey);
  
  if (nonExistentEntry != NULL || nonExistentValue != NULL) {
    printLog(ERR, "Getting non-existent key should return NULL\n");
    free(key1);
    free(key2);
    free(value1);
    free(value2);
    free(key3);
    free(value3);
    free(nonExistentKey);
    kvVectorDestroy(kvVector);
    return false;
  }
  
  // Test operations on NULL vector
  VectorNode *nullKvResult = kvVectorGetEntry(NULL, key1);
  void *nullKvValueResult = kvVectorGetValue(NULL, key1);
  
  if (nullKvResult != NULL || nullKvValueResult != NULL) {
    printLog(ERR, "Key-value operations on NULL vector should return NULL\n");
    free(key1);
    free(key2);
    free(value1);
    free(value2);
    free(key3);
    free(value3);
    free(nonExistentKey);
    kvVectorDestroy(kvVector);
    return false;
  }
  
  free(key1);
  free(key2);
  free(value1);
  free(value2);
  free(key3);
  free(value3);
  free(nonExistentKey);
  kvVectorDestroy(kvVector);
  
  printLog(DEBUG, "Key-value vector operations tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Test vector navigation functions
/// @return true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testVectorNavigation(void) {
  printLog(DEBUG, "Testing vector navigation functions...\n");
  
  Vector *vector = vectorCreate(typeString);
  if (vector == NULL) {
    printLog(ERR, "Failed to create vector for navigation test\n");
    return false;
  }
  
  // Create sparse vector with entries at indices 0, 5, 10
  char *str0 = createVectorTestString(0);
  char *str5 = createVectorTestString(5);
  char *str10 = createVectorTestString(10);
  
  if (str0 == NULL || str5 == NULL || str10 == NULL) {
    printLog(ERR, "Failed to create test strings for navigation\n");
    free(str0);
    free(str5);
    free(str10);
    vectorDestroy(vector);
    return false;
  }
  
  vectorSetEntry(vector, 0, str0);
  vectorSetEntry(vector, 5, str5);
  vectorSetEntry(vector, 10, str10);
  
  // Test finding previous allocated entry
  VectorNode *prevNode = vectorFindPreviousAllocated(vector, 7);
  if (prevNode == NULL) {
    printLog(ERR, "Failed to find previous allocated entry\n");
    free(str0);
    free(str5);
    free(str10);
    vectorDestroy(vector);
    return false;
  }
  
  // Test finding next allocated entry
  VectorNode *nextNode = vectorFindNextAllocated(vector, 7);
  if (nextNode == NULL) {
    printLog(ERR, "Failed to find next allocated entry\n");
    free(str0);
    free(str5);
    free(str10);
    vectorDestroy(vector);
    return false;
  }
  
  // Test edge cases
  VectorNode *prevFromStart = vectorFindPreviousAllocated(vector, 0);
  if (prevFromStart != NULL) {
    printLog(ERR,
      "vectorFindPreviousAllocated from start of vector returned non-NULL\n");
    return false;
  }
  VectorNode *nextFromEnd = vectorFindNextAllocated(vector, 10);
  if (nextFromEnd != NULL) {
    printLog(ERR,
      "vectorFindNextAllocated from end of vector returned non-NULL\n");
    return false;
  }
  
  // Test with NULL vector
  VectorNode *nullPrev = vectorFindPreviousAllocated(NULL, 5);
  VectorNode *nullNext = vectorFindNextAllocated(NULL, 5);
  
  if (nullPrev != NULL || nullNext != NULL) {
    printLog(ERR, "Navigation on NULL vector should return NULL\n");
    free(str0);
    free(str5);
    free(str10);
    vectorDestroy(vector);
    return false;
  }
  
  free(str0);
  free(str5);
  free(str10);
  vectorDestroy(vector);
  
  printLog(DEBUG, "Vector navigation tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Test vector remove operations
/// @return true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testVectorRemove(void) {
  printLog(DEBUG, "Testing vector remove operations...\n");
  
  Vector *vector = vectorCreate(typeString);
  if (vector == NULL) {
    printLog(ERR, "Failed to create vector for remove test\n");
    return false;
  }
  
  // Add some entries
  char *str1 = createVectorTestString(1);
  char *str2 = createVectorTestString(2);
  
  if (str1 == NULL || str2 == NULL) {
    printLog(ERR, "Failed to create test strings for remove test\n");
    free(str1);
    free(str2);
    vectorDestroy(vector);
    return false;
  }
  
  vectorSetEntry(vector, 0, str1);
  vectorSetEntry(vector, 1, str2);
  
  // Test removing existing entry
  i32 removeResult = vectorRemove(vector, 0);
  if (removeResult != 0) {
    printLog(ERR, "Failed to remove existing entry\n");
    free(str1);
    free(str2);
    vectorDestroy(vector);
    return false;
  }
  
  // Verify entry was removed
  VectorNode *newNode0 = vectorGetEntry(vector, 0);
  if ((newNode0 == NULL) || (newNode0->allocated == false)) {
    printLog(ERR, "Invalid vector entry found at index 0\n");
    free(str1);
    free(str2);
    vectorDestroy(vector);
    return false;
  } else if (typeString->compare(newNode0->value, str2) != 0) {
    printLog(ERR,
      "Expected node at index 0 to hold value \"%s\", found \"%s\".\n",
    str2, str(newNode0->value));
    free(str1);
    free(str2);
    vectorDestroy(vector);
    return false;
  }
  
  // Test removing non-existent entry
  i32 removeNonExistent = vectorRemove(vector, 10);
  if (removeNonExistent != 0) {
    printLog(ERR, "Removing non-existent entry should succeed\n");
    free(str1);
    free(str2);
    vectorDestroy(vector);
    return false;
  }
  
  // Test removing from NULL vector
  i32 removeFromNull = vectorRemove(NULL, 0);
  if (removeFromNull == 0) {
    printLog(ERR, "Removing from NULL vector should fail\n");
    free(str1);
    free(str2);
    vectorDestroy(vector);
    return false;
  }
  
  free(str1);
  free(str2);
  vectorDestroy(vector);
  
  printLog(DEBUG, "Vector remove tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Test vector comparison and copying
/// @return true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testVectorCompareAndCopy(void) {
  printLog(DEBUG, "Testing vector comparison and copying...\n");
  
  Vector *vector1 = vectorCreate(typeString);
  Vector *vector2 = vectorCreate(typeString);
  
  if (vector1 == NULL || vector2 == NULL) {
    printLog(ERR, "Failed to create vectors for comparison test\n");
    vectorDestroy(vector1);
    vectorDestroy(vector2);
    return false;
  }
  
  // Add same data to both vectors
  char *str1a = createVectorTestString(1);
  char *str1b = createVectorTestString(1); // Same content as str1a
  char *str2a = createVectorTestString(2);
  char *str2b = createVectorTestString(2); // Same content as str2a
  
  if (str1a == NULL || str1b == NULL || str2a == NULL || str2b == NULL) {
    printLog(ERR, "Failed to create test strings for comparison\n");
    free(str1a);
    free(str1b);
    free(str2a);
    free(str2b);
    vectorDestroy(vector1);
    vectorDestroy(vector2);
    return false;
  }
  
  vectorSetEntry(vector1, 0, str1a);
  vectorSetEntry(vector1, 1, str2a);
  vectorSetEntry(vector2, 0, str1b);
  vectorSetEntry(vector2, 1, str2b);
  
  // Test vector comparison
  int compareResult = vectorCompare(vector1, vector2);
  if (compareResult != 0) {
    printLog(ERR, "Identical vectors should compare equal\n");
    free(str1a);
    free(str1b);
    free(str2a);
    free(str2b);
    vectorDestroy(vector1);
    vectorDestroy(vector2);
    return false;
  }
  
  // Test vector copying
  Vector *copiedVector = vectorCopy(vector1);
  if (copiedVector == NULL) {
    printLog(ERR, "Failed to copy vector\n");
    free(str1a);
    free(str1b);
    free(str2a);
    free(str2b);
    vectorDestroy(vector1);
    vectorDestroy(vector2);
    return false;
  }
  
  // Test comparison with copied vector
  int copyCompareResult = vectorCompare(vector1, copiedVector);
  if (copyCompareResult != 0) {
    printLog(ERR, "Original and copied vectors should compare equal\n");
    free(str1a);
    free(str1b);
    free(str2a);
    free(str2b);
    vectorDestroy(vector1);
    vectorDestroy(vector2);
    vectorDestroy(copiedVector);
    return false;
  }
  
  // Test with NULL parameters
  int nullCompare1 = vectorCompare(NULL, vector1);
  if (nullCompare1 >= 0) {
    printLog(ERR, "Expected nullCompare1 to be less than 0, found %d.\n",
      nullCompare1);
    return false;
  }
  int nullCompare2 = vectorCompare(vector1, NULL);
  if (nullCompare2 <= 0) {
    printLog(ERR, "Expected nullCompare2 to be greater than 0, found %d.\n",
      nullCompare2);
    return false;
  }
  int nullCompare3 = vectorCompare(NULL, NULL);
  if (nullCompare3 != 0) {
    printLog(ERR, "Expected nullCompare3 to be equal to 0, found %d.\n",
      nullCompare3);
    return false;
  }
  
  Vector *nullCopy = vectorCopy(NULL);
  if (nullCopy != NULL) {
    printLog(ERR, "Copying NULL vector should return NULL\n");
    free(str1a);
    free(str1b);
    free(str2a);
    free(str2b);
    vectorDestroy(vector1);
    vectorDestroy(vector2);
    vectorDestroy(copiedVector);
    return false;
  }
  
  free(str1a);
  free(str1b);
  free(str2a);
  free(str2b);
  vectorDestroy(vector1);
  vectorDestroy(vector2);
  vectorDestroy(copiedVector);
  
  printLog(DEBUG, "Vector comparison and copying tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Test vector serialization functions
/// @return true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testVectorSerialization(void) {
  printLog(DEBUG, "Testing vector serialization functions...\n");
  
  Vector *vector = vectorCreate(typeString);
  if (vector == NULL) {
    printLog(ERR, "Failed to create vector for serialization test\n");
    return false;
  }
  
  // Add test data
  char *str1 = createVectorTestString(1);
  char *str2 = createVectorTestString(2);
  
  if (str1 == NULL || str2 == NULL) {
    printLog(ERR, "Failed to create test strings for serialization\n");
    free(str1);
    free(str2);
    vectorDestroy(vector);
    return false;
  }
  
  vectorSetEntry(vector, 0, str1);
  vectorSetEntry(vector, 1, str2);
  
  // Test toString (via macro to listToString)
  char *toStringResult = vectorToString(vector);
  if (toStringResult == NULL) {
    printLog(ERR, "vectorToString should not return NULL for valid vector\n");
    free(str1);
    free(str2);
    vectorDestroy(vector);
    return false;
  }
  toStringResult = stringDestroy(toStringResult);
  
  // Test toXml
  Bytes xmlResult = vectorToXml(vector, "TestVector");
  if (xmlResult == NULL) {
    printLog(ERR, "vectorToXml should not return NULL for valid vector\n");
    free(str1);
    free(str2);
    vectorDestroy(vector);
    return false;
  }
  bytesDestroy(xmlResult);
  
  // Test toJson
  Bytes jsonResult = vectorToJson(vector);
  if (jsonResult == NULL) {
    printLog(ERR, "vectorToJson should not return NULL for valid vector\n");
    free(str1);
    free(str2);
    vectorDestroy(vector);
    return false;
  }
  Vector *derivedVector = jsonToVector(str(jsonResult), NULL);
  if (derivedVector == NULL) {
    printLog(ERR, "jsonToVector with valid blob returned NULL.\n");
    free(str1);
    free(str2);
    vectorDestroy(vector);
    bytesDestroy(jsonResult);
    return false;
  } else if (typeVector->compare(vector, derivedVector) != 0) {
    printLog(ERR, "vector and derivedVector are not identical.\n");
    free(str1);
    free(str2);
    vectorDestroy(vector);
    bytesDestroy(jsonResult);
    vectorDestroy(derivedVector);
    return false;
  }
  
  if (typeVector->size(derivedVector) != sizeof(Vector)) {
    printLog(ERR, "Expected size of valid vector to be %d, found %d.\n",
      (int) sizeof(Vector), (int) typeVector->size(derivedVector));
    free(str1);
    free(str2);
    vectorDestroy(vector);
    bytesDestroy(xmlResult);
    vectorDestroy(derivedVector);
    return false;
  } else if (derivedVector->size == 0) {
    printLog(ERR, "Expected derivedVector->size to be non-zero.\n");
    free(str1);
    free(str2);
    vectorDestroy(vector);
    bytesDestroy(xmlResult);
    vectorDestroy(derivedVector);
    return false;
  }
  
  typeVector->clear(derivedVector);
  if (derivedVector->size != 0) {
    printLog(ERR, "Expected cleared derivedVector->size to be zero.\n");
    free(str1);
    free(str2);
    vectorDestroy(vector);
    bytesDestroy(xmlResult);
    vectorDestroy(derivedVector);
    return false;
  }
  
  derivedVector = vectorDestroy(derivedVector);
  if (typeVector->size(derivedVector) != 0) {
    printLog(ERR, "Expected size of destroyed vector to be 0, found %d.\n",
      (int) typeVector->size(derivedVector));
    free(str1);
    free(str2);
    vectorDestroy(vector);
    bytesDestroy(xmlResult);
    return false;
  }
  
  // Test toBlob
  Bytes blobResult = vectorToBlob(vector);
  if (blobResult == NULL) {
    printLog(ERR, "vectorToBlob should not return NULL for valid vector\n");
    free(str1);
    free(str2);
    vectorDestroy(vector);
    bytesDestroy(jsonResult);
    return false;
  }
  u64 blobLength = bytesLength(blobResult);
  derivedVector
    = (Vector*) typeVector->fromBlob(blobResult, &blobLength, false, false);
  if (derivedVector == NULL) {
    printLog(ERR, "typeVector->fromBlob with valid blob returned NULL.\n");
    free(str1);
    free(str2);
    vectorDestroy(vector);
    bytesDestroy(jsonResult);
    bytesDestroy(blobResult);
    return false;
  } else if (typeVector->compare(vector, derivedVector) != 0) {
    printLog(ERR, "vector and derivedVector are not identical.\n");
    free(str1);
    free(str2);
    vectorDestroy(vector);
    bytesDestroy(jsonResult);
    bytesDestroy(blobResult);
    vectorDestroy(derivedVector);
    return false;
  }
  vectorDestroy(derivedVector);
  
  // Test with NULL vector (should return empty string)
  char *nullToString = vectorToString(NULL);
  if (nullToString == NULL) {
    printLog(ERR, "vectorToString should return empty string for NULL vector\n");
    free(str1);
    free(str2);
    vectorDestroy(vector);
    bytesDestroy(jsonResult);
    bytesDestroy(blobResult);
    return false;
  }
  
  free(str1);
  free(str2);
  vectorDestroy(vector);
  bytesDestroy(jsonResult);
  bytesDestroy(blobResult);
  nullToString = stringDestroy(nullToString);
  
  printLog(DEBUG, "Vector serialization tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Test vector sorting functionality
/// @return true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testVectorSort(void) {
  printLog(DEBUG, "Testing vector sorting functionality...\n");
  
  Vector *vector = vectorCreate(typeI32);
  if (vector == NULL) {
    printLog(ERR, "Failed to create vector for sorting test\n");
    return false;
  }
  
  // Add test data in random order
  int32_t *val3 = createTestInt(3);
  int32_t *val1 = createTestInt(1);
  int32_t *val4 = createTestInt(4);
  int32_t *val2 = createTestInt(2);
  
  if (val1 == NULL || val2 == NULL || val3 == NULL || val4 == NULL) {
    printLog(ERR, "Failed to create test integers for sorting\n");
    free(val1);
    free(val2);
    free(val3);
    free(val4);
    vectorDestroy(vector);
    return false;
  }
  
  vectorSetEntry(vector, 0, val3);
  vectorSetEntry(vector, 1, val1);
  vectorSetEntry(vector, 2, val4);
  vectorSetEntry(vector, 3, val2);
  
  // Test ascending sort
  void *ascendingResult = vectorSort(vector, ASCENDING, true);
  if (ascendingResult == NULL) {
    printLog(ERR, "vectorSort should not return NULL for valid parameters\n");
    free(val1);
    free(val2);
    free(val3);
    free(val4);
    vectorDestroy(vector);
    return false;
  }
  
  // Test descending sort
  void *descendingResult = vectorSort(vector, DESCENDING, true);
  if (descendingResult == NULL) {
    printLog(ERR, "vectorSort should not return NULL for valid parameters\n");
    free(val1);
    free(val2);
    free(val3);
    free(val4);
    vectorDestroy(vector);
    return false;
  }
  
  // Test with NULL vector
  void *nullSortResult = vectorSort(NULL, ASCENDING, true);
  if (nullSortResult != NULL) {
    printLog(ERR, "vectorSort should return NULL for NULL vector\n");
    free(val1);
    free(val2);
    free(val3);
    free(val4);
    vectorDestroy(vector);
    return false;
  }
  
  free(val1);
  free(val2);
  free(val3);
  free(val4);
  vectorDestroy(vector);
  
  printLog(DEBUG, "Vector sorting tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Main unit test function for Vector data structure
/// @return true if all tests pass, false if any test fails
///////////////////////////////////////////////////////////////////////////////
bool vectorUnitTest(void) {
  printLog(DEBUG, "Starting Vector unit tests...\n");
  
  if (!testVectorCreateDestroy()) {
    printLog(ERR, "Vector create/destroy tests failed\n");
    return false;
  }
  
  if (!testVectorEntryOperations()) {
    printLog(ERR, "Vector entry operations tests failed\n");
    return false;
  }
  
  if (!testKvVectorOperations()) {
    printLog(ERR, "Key-value vector operations tests failed\n");
    return false;
  }
  
  if (!testVectorNavigation()) {
    printLog(ERR, "Vector navigation tests failed\n");
    return false;
  }
  
  if (!testVectorRemove()) {
    printLog(ERR, "Vector remove tests failed\n");
    return false;
  }
  
  if (!testVectorCompareAndCopy()) {
    printLog(ERR, "Vector comparison and copying tests failed\n");
    return false;
  }
  
  if (!testVectorSerialization()) {
    printLog(ERR, "Vector serialization tests failed\n");
    return false;
  }
  
  if (!testVectorSort()) {
    printLog(ERR, "Vector sorting tests failed\n");
    return false;
  }
  
  printLog(DEBUG, "All Vector unit tests passed successfully!\n");
  return true;
}
