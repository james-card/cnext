///////////////////////////////////////////////////////////////////////////////
///
/// @file              HashTableUnitTest.c
///
/// @brief             Unit test for HashTable functions
///
///////////////////////////////////////////////////////////////////////////////

#include "LoggingLib.h"
#include "StringLib.h"
#include "HashTable.h"
#include "Vector.h"
#include "Scope.h"

/// @fn bool hashTableUnitTest(void)
///
/// @brief Unit tests for hash table functionality.
///
/// @return Returns true on success, false on failure.
bool hashTableUnitTest(void) {
  HashTable *hashTable = NULL, *hashTable2 = NULL;
  u64 hashValue = 0;
  HashNode *node = NULL;
  char *stringValue = NULL;
  Bytes byteArray = NULL;
  u64 length = 0;

  printLog(INFO, "Testing HashTable data structure.\n");

  hashTable = htCreate(NULL);
  if (hashTable != NULL) {
    printLog(ERR, "Expected NULL from htCreate, got %p\n", hashTable);
    return false;
  }

  hashTable = htCreate(typeString, false, 1);
  if (hashTable == NULL) {
    printLog(ERR, "Expected valid pointer from htCreate(typeString, false, 1), got "
      "NULL\n");
    return false;
  }

  htDestroy(NULL);
  htDestroy(hashTable); hashTable = NULL;

  hashValue = htGetHash(NULL, NULL);
  if (hashValue != 0) {
    printLog(ERR, "Got invalid hash value from htGetHash.\n");
  }

  node = htAddEntry(NULL, NULL, NULL, NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from htAddEntry, got %p\n", node);
    return false;
  }
  node = htAddEntry(NULL, "key", NULL, NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from htAddEntry, got %p\n", node);
    return false;
  }
  node = htAddEntry(NULL, "key", "value", NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from htAddEntry, got %p\n", node);
    return false;
  }
  node = htAddEntry(NULL, NULL, NULL, typeString);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from htAddEntry, got %p\n", node);
    return false;
  }

  node = htGetEntry(NULL, NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from htGetEntry, got %p\n", node);
    return false;
  }

  if (htRemoveEntry(NULL, NULL) >= 0) {
    printLog(ERR, "htGetEntry succeeded with NULL table and key.\n");
    return false;
  }

  stringValue = (char*) htGetValue(NULL, NULL);
  if (stringValue != NULL) {
    printLog(ERR, "Expected NULL from htGetValue, got %p\n", node);
    return false;
  }

  hashTable = xmlToHashTable(NULL);
  if (hashTable != NULL) {
    printLog(ERR, "Expected NULL from xmlToHashTable, got %p\n", hashTable);
    return false;
  }

  hashTable = htCreate(typeString);
  if (hashTable == NULL) {
    printLog(ERR, "Expected table from htCreate, got NULL\n");
    return false;
  }

  hashValue = htGetHash(hashTable, NULL);
  if (hashValue != 0) {
    printLog(ERR, "Got invalid hash value from htGetHash.\n");
  }

  node = htAddEntry(hashTable, NULL, NULL, NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from htAddEntry, got %p\n", node);
    return false;
  }
  node = htAddEntry(hashTable, NULL, NULL, typeString);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from htAddEntry, got %p\n", node);
    return false;
  }

  node = htGetEntry(hashTable, NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from htGetEntry, got %p\n", node);
    return false;
  }

  if (htRemoveEntry(hashTable, NULL) >= 0) {
    printLog(ERR, "htGetEntry succeeded with NULL table and key.\n");
    return false;
  }

  stringValue = (char*) htGetValue(hashTable, NULL);
  if (stringValue != NULL) {
    printLog(ERR, "Expected NULL from htGetValue, got %p\n", node);
    return false;
  }

  node = htAddEntry(hashTable, "key1", "value1", typeString);
  if (node == NULL) {
    printLog(ERR, "Expected valid node from htAddEntry for key1, got NULL\n");
    return false;
  }
  node = htAddEntry(hashTable, "key2", "value2", typeString);
  if (node == NULL) {
    printLog(ERR, "Expected valid node from htAddEntry for key2, got NULL\n");
    return false;
  }
  node = htAddEntry(hashTable, "key3", "value3");
  if (node == NULL) {
    printLog(ERR, "Expected valid node from htAddEntry for key3, got NULL\n");
    return false;
  }

  if (htRemoveEntry(hashTable, "key2") != 0) {
    printLog(ERR, "htRemoveEntry for key2 did not succeed.\n");
    return false;
  }

  List *list = htToList(hashTable);
  if ((list == NULL) || (list->size == 0)) {
    printLog(ERR, "htToList did not populate a list.\n");
    return false;
  }
  listDestroy(list); list = NULL;
  
  if (htCompare(hashTable, NULL) <= 0) {
    printLog(ERR, "Populated hash table was not greater than NULL.\n");
    return false;
  }
  if (htCompare(NULL, hashTable) >= 0) {
    printLog(ERR, "Populated hash table was not greater than NULL.\n");
    return false;
  }
  if (htCompare(NULL, NULL) != 0) {
    printLog(ERR, "Populated hash table was not greater than NULL.\n");
    return false;
  }

  hashTable2 = htCopy(NULL);
  if (hashTable2 != NULL) {
    printLog(ERR, "Copy of NULL hash table resulted in non-NULL hash table "
      "copy.");
    return false;
  }
  hashTable2 = htCopy(hashTable);
  if (htCompare(hashTable, hashTable2) != 0) {
    printLog(ERR, "hashTable and hashTable2 are not equal after htCopy.\n");
    return false;
  }
  htAddEntry(hashTable2, "key2", "value2");
  if (htCompare(hashTable, hashTable2) == 0) {
    printLog(ERR, "hashTable and hashTable2 are equal after htAddEntry.\n");
    return false;
  }
  htRemoveEntry(hashTable, "key3");
  if (htCompare(hashTable, hashTable2) == 0) {
    printLog(ERR, "hashTable and hashTable2 are equal after htRemoveEntry.\n");
    return false;
  }
  htDestroy(hashTable2);
  hashTable2 = listToHashTable((List*) hashTable);
  if (htCompare(hashTable, hashTable2) != 0) {
    printLog(ERR, "hashTable and hashTable2 are not equal after listToHashTable.\n");
    return false;
  }
  htDestroy(hashTable2);
  hashTable2 = htCreate(typeU32);
  u32 u32Key = 4;
  u32 u32Value = 5;
  htAddEntry(hashTable2, &u32Key, &u32Value);
  u32Key--;
  htAddEntry(hashTable2, &u32Key, &u32Value);
  if (htCompare(hashTable, hashTable2) == 0) {
    printLog(ERR, "hashTable and hashTable2 are equal after new hashTable2 created.\n");
    return false;
  }
  htDestroy(hashTable2);

  byteArray = htToBlob(NULL);
  if (byteArray != NULL) {
    printLog(ERR, "byteArray not NULL after htToBlob(NULL)\n");
    return false;
  }
  byteArray = htToBlob(hashTable);
  length = bytesLength(byteArray);
  if (byteArray == NULL) {
    printLog(ERR, "byteArray NULL after htToBlob(hashTable)\n");
    return false;
  }
  hashTable2 = htFromBlob(NULL, NULL);
  if (hashTable2 != NULL) {
    printLog(ERR, "hashTable2 not NULL after htFromBlob(NULL, NULL)\n");
    return false;
  }
  hashTable2 = htFromBlob(byteArray, NULL);
  if (hashTable2 != NULL) {
    printLog(ERR, "hashTable2 not NULL after htFromBlob(byteArray, NULL)\n");
    return false;
  }
  hashTable2 = htFromBlob(NULL, &length);
  if (hashTable2 != NULL) {
    printLog(ERR, "hashTable2 not NULL after htFromBlob(NULL, &length)\n");
    return false;
  }
  hashTable2 = htFromBlob(byteArray, &length);
  if (hashTable2 == NULL) {
    printLog(ERR, "hashTable2 NULL after htFromBlob(byteArray, &length)\n");
    return false;
  }
  byteArray = bytesDestroy(byteArray);
  if (htCompare(hashTable, hashTable2) != 0) {
    char *hashTableString = NULL;
    printLog(ERR, "hashTable and hashTable2 are not equal after htFromBlob.\n");
    hashTableString = htToString(hashTable);
    printLog(ERR, "hashTable = %s\n", hashTableString);
    hashTableString = stringDestroy(hashTableString);
    hashTableString = htToString(hashTable2);
    printLog(ERR, "hashTable2 = %s\n", hashTableString);
    hashTableString = stringDestroy(hashTableString);
    return false;
  }
  htDestroy(hashTable2);

  int size = typeHashTable->size(hashTable);
  if (size == 0) {
    printLog(ERR, "htSize returned 0 for non-empty hash table.\n");
    return false;
  }
  
  htDestroy(hashTable);

  hashTable = htCreate(typeI32, false, 2048);
  for (int i = 1; i < 100; i++) {
    htAddEntry(hashTable, &i, &i);
  }
  for (int i = -1; i > -100; i--) {
    htAddEntry(hashTable, &i, &i);
  }
  htDestroy(hashTable);

  hashTable = htCreate(typeI32);
  for (int i = 1; i < 100; i++) {
    htAddEntry(hashTable, &i, &i);
  }
  for (int i = -1; i > -100; i--) {
    htAddEntry(hashTable, &i, &i);
  }
  list = htToList(hashTable);
  if (list == NULL) {
    printLog(ERR, "htToList did not populate a list.\n");
    return false;
  } else if (list->size != 198) {
    printLog(ERR, "htToList returned a %llu element list, expected 198 elements."
      "\n", llu(list->size));
    i32 array[199] = {0};
    for (ListNode *node = list->head; node != NULL; node = node->next) {
      array[*((i32*) node->value) + 99]++;
    }
    printLog(ERR, "Not seen:\n");
    for (int i = 0; i < 199; i++) {
      if ((array[i] == 0) && (i != 99)) {
        printLog(ERR, "%d\n", i - 99);
      }
    }
    return false;
  }
  listDestroy(list); list = NULL;
  htDestroy(hashTable);

  const char *xmlToParse =
    "<hashTable>"
      "<myHashTable1>"
        "<key1>value1</key1>"
        "<key2>value2</key2>"
      "</myHashTable1>"
      "<key3>value3</key3>"
      "<myHashTable2>"
        "<key4>value4</key4>"
        "<key5>value5</key5>"
        "<key6>value6</key6>"
      "</myHashTable2>"
      "<myHashTable3>"
        "<myHashTable4>"
          "<key7>value7</key7>"
          "<key8>value8</key8>"
        "</myHashTable4>"
        "<key9>value9</key9>"
      "</myHashTable3>"
    "</hashTable>";
  printLog(INFO, "Parsing XML into list.\n");
  hashTable = xmlToHashTable(xmlToParse);
  if (hashTable == NULL) {
    printLog(ERR, "Could not parse XML into hash table.\n");
    return false;
  }
  printLog(INFO, "Getting myHashTable1 from parsed list.\n");
  node = htGetEntry(hashTable, "myHashTable1");
  if (node == NULL) {
    printLog(ERR, "myHashTable1 did not appear in parsed hash table.\n");
    return false;
  }
  if (node->type != typeHashTable) {
    printLog(ERR, "myHashTable1 was of type %lld instead of typeHashTable.\n",
      lld(getIndexFromTypeDescriptor(node->type)));
    return false;
  }
  printLog(INFO, "Getting key1 from myHashTable1.\n");
  if (htGetEntry((HashTable*) node->value, "key1") == NULL) {
    printLog(ERR, "key1 did not appear in myHashTable1.\n");
    return false;
  }
  printLog(INFO, "Getting key2 from myHashTable1.\n");
  if (htGetEntry((HashTable*) node->value, "key2") == NULL) {
    printLog(ERR, "key2 did not appear in myHashTable1.\n");
    return false;
  }
  printLog(INFO, "Getting key3 from parsed hash table.\n");
  node = htGetEntry(hashTable, "key3");
  if (node == NULL) {
    printLog(ERR, "key3 did not appear in parsed hash table.\n");
    return false;
  }
  if (strcmp("value3", (char*) node->value) != 0) {
    printLog(ERR, "Expected value of key3 to be value3, got \"%s\".\n",
      (char*) node->value);
    return false;
  }
  printLog(INFO, "Getting myHashTable2 from parsed hash table.\n");
  node = htGetEntry(hashTable, "myHashTable2");
  if (node == NULL) {
    printLog(ERR, "myHashTable2 did not appear in parsed hash table.\n");
    return false;
  }
  if (node->type != typeHashTable) {
    printLog(ERR, "myHashTable2 was of type %lld instead of typeHashTable.\n",
      lld(getIndexFromTypeDescriptor(node->type)));
    return false;
  }
  printLog(INFO, "Getting key4 from myHashTable2.\n");
  if (htGetEntry((HashTable*) node->value, "key4") == NULL) {
    printLog(ERR, "key4 did not appear in myHashTable2.\n");
    return false;
  }
  printLog(INFO, "Getting key5 from myHashTable2.\n");
  if (htGetEntry((HashTable*) node->value, "key5") == NULL) {
    printLog(ERR, "key5 did not appear in myHashTable2.\n");
    return false;
  }
  printLog(INFO, "Getting key6 from myHashTable2.\n");
  if (htGetEntry((HashTable*) node->value, "key6") == NULL) {
    printLog(ERR, "key6 did not appear in myHashTable2.\n");
    return false;
  }
  printLog(INFO, "Getting myHashTable3 from parsed list.\n");
  node = htGetEntry(hashTable, "myHashTable3");
  if (node == NULL) {
    printLog(ERR, "myHashTable3 did not appear in parsed hash table.\n");
    return false;
  }
  if (node->type != typeHashTable) {
    printLog(ERR, "myHashTable3 was of type %lld instead of typeHashTable.\n",
      lld(getIndexFromTypeDescriptor(node->type)));
    return false;
  }
  printLog(INFO, "Getting key9 from myHashTable.\n");
  if (htGetEntry((HashTable*) node->value, "key9") == NULL) {
    printLog(ERR, "key9 did not appear in myHashTable3.\n");
    return false;
  }
  printLog(INFO, "Getting myHashTable4 from myHashTable3.\n");
  node = htGetEntry((HashTable*) node->value, "myHashTable4");
  printLog(INFO, "node = %p\n", node);
  if (node == NULL) {
    printLog(ERR, "myHashTable4 did not appear in myHashTable3.\n");
    return false;
  }
  printLog(INFO, "node->type = %p\n", node->type);
  if (node->type != typeHashTable) {
    printLog(ERR, "myHashTable4 was of type %lld instead of typeHashTable.\n",
      lld(getIndexFromTypeDescriptor(node->type)));
    return false;
  }
  printLog(INFO, "Getting key7 from myHashTable4.\n");
  if (htGetEntry((HashTable*) node->value, "key7") == NULL) {
    printLog(ERR, "key7 did not appear in myHashTable4.\n");
    return false;
  }
  printLog(INFO, "Getting key8 from myHashTable4.\n");
  if (htGetEntry((HashTable*) node->value, "key8") == NULL) {
    printLog(ERR, "key8 did not appear in myHashTable4.\n");
    return false;
  }
  htDestroy(hashTable); hashTable = NULL;

  hashTable = htCreate(typeStringCi);
  htAddEntry(hashTable, "SOAPAction", "myValue");
  htAddEntry(hashTable, "Host", "127.0.0.1");
  htAddEntry(hashTable, "User-Agent", "Zeep");
  stringValue = (char*) htGetValue(hashTable, "SoapAction");
  if (stringValue == NULL) {
    printLog(ERR, "htGetValue(hashTable, \"SoapAction\") returned NULL.\n");
    return false;
  } else if (strcmp(stringValue, "myValue") != 0) {
    printLog(ERR, "htGetValue(hashTable, \"SoapAction\") returned %s.\n", stringValue);
    return false;
  }
  printLog(INFO, "Case-insensitive hash table passed.\n");
  stringValue = htToString(hashTable);
  printLog(INFO, "Table: %s\n", stringValue);
  Bytes bytesValue = typeHashTable->toBytes(hashTable);
  if (strcmp(stringValue, str(bytesValue)) != 0) {
    printLog(ERR,
      "Expected htToBytes output to be identical to htToStirng.  Got %s.\n",
      str(bytesValue));
    return false;
  }
  bytesValue = bytesDestroy(bytesValue);
  stringValue = stringDestroy(stringValue);

  HashNode *hashNode = htGetEntry(hashTable, "Host");
  if (hashNode == NULL) {\
    printLog(ERR, "Could not get hash table node for \"Host\".\n");
    return false;
  }
  if (htDestroyNode(hashTable, hashNode) != 0) {\
    printLog(ERR, "htDestroyNode returned an error.\n");
    return false;
  }

  if (htClear(hashTable) != 0) {\
    printLog(ERR, "htClear returned an error.\n");
    return false;
  } else if (hashTable->size != 0) {\
    printLog(ERR,
      "Expected hashTable->size to be 0 after clear, found %lld.\n",
      lld(hashTable->size));
    return false;
  }

  hashTable = htDestroy(hashTable);

  const char *jsonString = "{\n"
    "  \"myHashTable1\": {\n"
    "    \"key1\": \"value1\",\n"
    "    \"key2\": \"value2\"\n"
    "  },\n"
    "  \"key3\": \"value3\",\n"
    "  \"myHashTable2\": {\n"
    "    \"key4\": \"value4\",\n"
    "    \"key5\": \"value5\",\n"
    "    \"key6\": \"value6\"\n"
    "  },\n"
    "  \"myHashTable3\": {\n"
    "    \"myHashTable4\": {\n"
    "      \"key7\": \"value7\",\n"
    "      \"key8\": \"value8\"\n"
    "    },\n"
    "    \"key9\": \"value9\"\n"
    "  }\n"
    "}";
  long long int startPosition = 0;
  hashTable = jsonToHashTable(jsonString, &startPosition);
  if (hashTable == NULL) {
    printLog(ERR, "jsonToHashTable returned NULL.\n");
    return false;
  }
  byteArray = htToBlob(hashTable);
  length = bytesLength(byteArray);
  hashTable = htDestroy(hashTable);
  hashTable = htFromBlob(byteArray, &length, true);
  stringValue = htToString(hashTable);
  printLog(INFO, "Table: %s\n", stringValue);
  stringValue = stringDestroy(stringValue);
  stringValue = (char*) htGetValue(hashTable, "key3");
  if (stringValue == NULL) {
    printLog(ERR, "Value for key3 was NULL.\n");
    return false;
  } else if (strcmp(stringValue, "value3") != 0) {
    printLog(ERR, "Expected \"value3\", got \"%s\".\n", stringValue);
    return false;
  }
  hashTable2 = (HashTable*) htGetValue(hashTable, "myHashTable1");
  if (hashTable2 == NULL) {
    printLog(ERR, "Value for myHashTable1 was NULL.\n");
    return false;
  } else if (htGetEntry(hashTable, "myHashTable1")->type != typeHashTable) {
    printLog(ERR, "Expected myHashTable1 to be \"%s\", found \"%s\".\n",
      typeHashTable->name, htGetEntry(hashTable, "myHashTable1")->type->name);
    return false;
  }
  stringValue = (char*) htGetValue(hashTable2, "key1");
  if (stringValue == NULL) {
    printLog(ERR, "Value for key1 was NULL.\n");
    return false;
  } else if (strcmp(stringValue, "value1") != 0) {
    printLog(ERR, "Expected \"value1\", got \"%s\".\n", stringValue);
    return false;
  }
  stringValue = (char*) htGetValue(hashTable2, "key2");
  if (stringValue == NULL) {
    printLog(ERR, "Value for key2 was NULL.\n");
    return false;
  } else if (strcmp(stringValue, "value2") != 0) {
    printLog(ERR, "Expected \"value2\", got \"%s\".\n", stringValue);
    return false;
  }
  stringValue = (char*) htGetValue(hashTable2, "key6");
  hashTable2 = (HashTable*) htGetValue(hashTable, "myHashTable2");
  if (hashTable2 == NULL) {
    printLog(ERR, "Value for myHashTable2 was NULL.\n");
    return false;
  } else if (htGetEntry(hashTable, "myHashTable2")->type != typeHashTable) {
    printLog(ERR, "Expected myHashTable2 to be \"%s\", found \"%s\".\n",
      typeHashTable->name, htGetEntry(hashTable, "myHashTable2")->type->name);
    return false;
  }
  stringValue = (char*) htGetValue(hashTable2, "key4");
  if (stringValue == NULL) {
    printLog(ERR, "Value for key4 was NULL.\n");
    return false;
  } else if (strcmp(stringValue, "value4") != 0) {
    printLog(ERR, "Expected \"value4\", got \"%s\".\n", stringValue);
    return false;
  }
  stringValue = (char*) htGetValue(hashTable2, "key5");
  if (stringValue == NULL) {
    printLog(ERR, "Value for key5 was NULL.\n");
    return false;
  } else if (strcmp(stringValue, "value5") != 0) {
    printLog(ERR, "Expected \"value5\", got \"%s\".\n", stringValue);
    return false;
  }
  stringValue = (char*) htGetValue(hashTable2, "key6");
  if (stringValue == NULL) {
    printLog(ERR, "Value for key6 was NULL.\n");
    return false;
  } else if (strcmp(stringValue, "value6") != 0) {
    printLog(ERR, "Expected \"value6\", got \"%s\".\n", stringValue);
    return false;
  }
  hashTable2 = (HashTable*) htGetValue(hashTable, "myHashTable3");
  if (hashTable2 == NULL) {
    printLog(ERR, "Value for myHashTable3 was NULL.\n");
    return false;
  } else if (htGetEntry(hashTable, "myHashTable3")->type != typeHashTable) {
    printLog(ERR, "Expected myHashTable3 to be \"%s\", found \"%s\".\n",
      typeHashTable->name, htGetEntry(hashTable, "myHashTable3")->type->name);
    return false;
  }
  stringValue = (char*) htGetValue(hashTable2, "key9");
  if (stringValue == NULL) {
    printLog(ERR, "Value for key9 was NULL.\n");
    return false;
  } else if (strcmp(stringValue, "value9") != 0) {
    printLog(ERR, "Expected \"value9\", got \"%s\".\n", stringValue);
    return false;
  }
  if (htGetValue(hashTable2, "myHashTable4") == NULL) {
    printLog(ERR, "Value for myHashTable4 was NULL.\n");
    return false;
  } else if (htGetEntry(hashTable2, "myHashTable4")->type != typeHashTable) {
    printLog(ERR, "Expected myHashTable4 to be \"%s\", found \"%s\".\n",
      typeHashTable->name, htGetEntry(hashTable, "myHashTable4")->type->name);
    return false;
  }
  hashTable2 = (HashTable*) htGetValue(hashTable2, "myHashTable4");
  stringValue = (char*) htGetValue(hashTable2, "key7");
  if (stringValue == NULL) {
    printLog(ERR, "Value for key7 was NULL.\n");
    return false;
  } else if (strcmp(stringValue, "value7") != 0) {
    printLog(ERR, "Expected \"value7\", got \"%s\".\n", stringValue);
    return false;
  }
  stringValue = (char*) htGetValue(hashTable2, "key8");
  if (stringValue == NULL) {
    printLog(ERR, "Value for key8 was NULL.\n");
    return false;
  } else if (strcmp(stringValue, "value8") != 0) {
    printLog(ERR, "Expected \"value8\", got \"%s\".\n", stringValue);
    return false;
  }
  byteArray = bytesDestroy(byteArray);
  hashTable = htDestroy(hashTable);

  return true;
}

