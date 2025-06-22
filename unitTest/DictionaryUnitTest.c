///////////////////////////////////////////////////////////////////////////////
///
/// @author            James B. Card
/// @date              06.22.2025
///
/// @file              DictionaryUnitTest.c
///
/// @brief             Unit test for Dictionary.c functionality
///
///////////////////////////////////////////////////////////////////////////////

#include "Dictionary.h"
#include "LoggingLib.h"

/// @fn bool dictionaryUnitTest()
///
/// @brief Unit tests for dictionary functionality.
///
/// @return Returns true on success, false on failure.
bool dictionaryUnitTest() {
  Dictionary *dictionary = NULL;
  char *stringValue = NULL;
  List *dictList = NULL;
  const char *argv[] = {
    "programPath",
    "--arg1",
    "value1",
    "--booleanArg",
    "-flags"
  };
  int argc = 5;

  printLog(INFO, "Testing Dictionary data structure.\n");

  dictionary = parseCommandLine(argc, (char**) argv);
  if (dictionaryGetEntry(dictionary, "arg1") == NULL) {
    printLog(ERR, "arg1 was not loaded into dictionary.\n");
    return false;
  }
  stringValue = (char*) dictionaryGetEntry(dictionary, "arg1")->value;
  if ((stringValue == NULL) || (strcmp(stringValue, "value1") != 0)) {
    printLog(ERR, "Value of arg1 was not \"value1\".\n");
    return false;
  }
  if (dictionaryGetEntry(dictionary, "booleanArg") == NULL) {
    printLog(ERR, "booleanArg was not loaded into dictionary.\n");
    return false;
  }
  if (dictionaryGetEntry(dictionary, "f") == NULL) {
    printLog(ERR, "f was not loaded into dictionary.\n");
    return false;
  }
  if (dictionaryGetEntry(dictionary, "l") == NULL) {
    printLog(ERR, "l was not loaded into dictionary.\n");
    return false;
  }
  if (dictionaryGetEntry(dictionary, "a") == NULL) {
    printLog(ERR, "a was not loaded into dictionary.\n");
    return false;
  }
  if (dictionaryGetEntry(dictionary, "g") == NULL) {
    printLog(ERR, "g was not loaded into dictionary.\n");
    return false;
  }
  if (dictionaryGetEntry(dictionary, "s") == NULL) {
    printLog(ERR, "s was not loaded into dictionary.\n");
    return false;
  }

  ungets("\n", stdin);
  char *userValue = getUserValue(dictionary, "arg2", "arg2:", "val2");
  if (strcmp(userValue, "val2") != 0) {
    printLog(ERR, "Expected userValue to be \"val2\", got \"%s\".\n",
      userValue);
    return false;
  }
  printLog(DEBUG, "userValue was \"val2\" as expected.\n");

  ungets("marklar\n", stdin);
  userValue = getUserValue(dictionary, "arg2", "arg2:", "val2");
  if (strcmp(userValue, "marklar") != 0) {
    printLog(ERR, "Expected userValue to be \"marklar\", got \"%s\".\n",
      userValue);
    return false;
  }
  printLog(DEBUG, "userValue was \"marklar\" as expected.\n");

  dictionaryDestroy(dictionary); dictionary = NULL;

  printLog(INFO, "Converting NULL dictionary to string.\n");
  stringValue = dictionaryToString(NULL);
  if (stringValue == NULL) {
    printLog(ERR, "Expected non-NULL string from dictionaryToString.\n");
    printLog(ERR, "Got \"%p\"\n", stringValue);
    return false;
  } else if (*stringValue != '\0') {
    printLog(ERR, "Expected empty string from dictionaryToString.\n");
    printLog(ERR, "Got \"%s\"\n", stringValue);
    stringValue = stringDestroy(stringValue);
    return false;
  }
  stringValue = stringDestroy(stringValue);

  printLog(INFO, "Destroying NULL dictionary.\n");
  dictionary = dictionaryDestroy(dictionary);

  printLog(INFO, "Removing NULL key from NULL dictionary.\n");
  dictionaryRemove(dictionary, NULL);

  printLog(INFO, "Converting NULL dictionary to XML with NULL root.\n");
  Bytes bytesValue = dictionaryToXml(dictionary, NULL);
  if (bytesValue == NULL) {
    printLog(ERR, "Expected non-NULL string from dictionaryToXml.\n");
    printLog(ERR, "Got \"%p\"\n", stringValue);
    return false;
  } else if (strcmp(str(bytesValue), "<></>") != 0) {
    printLog(ERR, "Expected empty XML from dictionaryToXml.\n");
    printLog(ERR, "Got \"%s\"\n", stringValue);
    stringValue = stringDestroy(stringValue);
    return false;
  }
  bytesValue = bytesDestroy(bytesValue);

  printLog(INFO, "Getting NULL key from NULL dictionary.\n");
  stringValue = (char*) dictionaryGetValue(dictionary, NULL);
  if (stringValue != NULL) {
    printLog(ERR, "Expected NULL pointer from dictionaryGetValue.\n");
    printLog(ERR, "Got \"%p\"\n", stringValue);
    return false;
  }

  printLog(INFO, "Making list from NULL dictionary.\n");
  dictList = dictionaryToList(NULL);
  if (dictList != NULL) {
    printLog(ERR, "Expected NULL list from dictionaryToList.\n");
    printLog(ERR, "Got \"%p\"\n", dictList);
    return false;
  }

  printLog(INFO, "Adding NULL key and value to NULL dictionary.\n");
  dictionaryAddEntry(dictionary, NULL, NULL);
  dictionaryDestroy(dictionary); dictionary = NULL;

  printLog(INFO, "Creating empty dictionary.\n");
  dictionary = dictionaryCreate(typeString);

  printLog(INFO, "Converting empty dictionary to string.\n");
  stringValue = dictionaryToString(dictionary);
  if (stringValue == NULL) {
    printLog(ERR, "Expected empty string from dictionaryToString.\n");
    printLog(ERR, "Got NULL.\n");
    return false;
  } else if (strcmp(stringValue, "{\n  size=0\n  keyType=string\n}") != 0) {
    printLog(ERR,
      "Expected (almost) empty string from dictionaryToString.\n");
    printLog(ERR, "Got \"%s\".\n", stringValue);
    return false;
  }
  stringValue = stringDestroy(stringValue);

  printLog(INFO, "Converting empty dictionary to XML with NULL element.\n");
  bytesValue = dictionaryToXml(dictionary, NULL);
  if (bytesValue == NULL) {
    printLog(ERR, "Expected empty string from dictionaryToXml.\n");
    printLog(ERR, "Got NULL.\n");
    return false;
  } else if (strcmp(str(bytesValue), "<></>") != 0) {
    printLog(ERR, "Expected empty XML from dictionaryToXml.\n");
    printLog(ERR, "Got \"%s\".\n", stringValue);
    return false;
  }
  bytesValue = bytesDestroy(bytesValue);

  printLog(INFO, "Removing NULL key from empty dictionary.\n");
  dictionaryRemove(dictionary, NULL);

  printLog(INFO, "Getting NULL key from empty dictionary.\n");
  stringValue = (char*) dictionaryGetValue(dictionary, NULL);

  printLog(INFO, "Making list from empty dictionary.\n");
  dictList = dictionaryToList(dictionary);
  if (dictList == NULL) {
    printLog(ERR, "Expected empty list from dictionaryToList.\n");
    printLog(ERR, "Got NULL.\n");
    return false;
  } else if (dictList->size != 0) {
    stringValue = listToString(dictList);
    printLog(ERR, "Expected empty list from dictionaryToList.\n");
    printLog(ERR, "Got \"%s\".\n", stringValue);
    stringValue = stringDestroy(stringValue);
    return false;
  }
  listDestroy(dictList); dictList = NULL;

  printLog(INFO, "Destroying empty dictionary.\n");
  dictionaryDestroy(dictionary); dictionary = NULL;

  return true;
}

