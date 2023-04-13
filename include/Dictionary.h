///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              02.17.2019
///
/// @file              Dictionary.h
///
/// @brief             These are the functions for support of a data
///                    structure-agnostic dictionary.  They are used in
///                    many places.
///
/// @details
///
/// @copyright
///                   Copyright (c) 2012-2023 James Card
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

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "TypeDefinitions.h"
#include "StringLib.h"
#include "List.h"
#include "HashTable.h"

typedef RedBlackNode DictionaryEntry;
typedef HashTable Dictionary;

#ifdef __cplusplus
extern "C"
{
#endif

#define typeDictionary typeHashTable
#define typeDictionaryNoCopy typeHashTableNoCopy
#define jsonToDictionary jsonToHashTable

typedef Variant (*UserFunctionHandler)(
  void *context, Dictionary *args);
/// @union UserFuncData
///
/// @brief Translation between a user function pointer and a data pointer.
///
/// @details We sometimes need to pass and return function pointers to functions
/// that take aand return data pointers.  ISO C doesn't permit casting between
/// these two, so we use a union to do the conversion.
///
/// @param func The function pointer portion of the pointer value.
/// @param data The data pointer portion of the pointer value.
typedef union UserFuncData {
  UserFunctionHandler func;
  void* data;
} UserFuncData;

#define userFuncToData(function) (((UserFuncData){.func = function}).data)
#define dataToUserFunc(userData) (((UserFuncData){.data = userData}).func)

// Helper functions.
int keyValueStringToDictionaryEntry(Dictionary **dictionary, char *inputString);
Dictionary* kvStringToDictionary(const char *inputString,
  const char *separator);
Dictionary* parseCommandLine(int argc, char **argv);
extern Dictionary* (*xmlToDictionary)(const char *inputData);
char* getUserValue(Dictionary *args, const char *argName, const char *prompt,
  const char *defaultValue);
Dictionary* functionCallToDictionary(const char *call);

// Dictionary functions.
extern char* (*dictionaryToString)(const Dictionary *dictionary);
#define dictionaryAdd htAddEntry
DictionaryEntry* dictionaryAddEntry_(Dictionary **dictionary, const volatile void *key,
  const volatile void *value, TypeDescriptor *type, ...);
#define dictionaryAddEntry(dictionary, key, value, ...) \
  dictionaryAddEntry_(dictionary, key, value, ##__VA_ARGS__, typeString)
extern Dictionary* (*dictionaryDestroy)(Dictionary *dictionary);
extern int (*dictionaryRemove)(Dictionary *dictionary, const char *key);
/// @def dictionaryToXml
/// Method for converting a dictionary to its XML representation.
#define dictionaryToXml(dictionary, elementName, ...)  \
  listToXml_((const List*) dictionary, elementName, ##__VA_ARGS__, false)
extern DictionaryEntry* (*dictionaryGetEntry)(const Dictionary *dictionary, const char *key);
/// @def dictionaryGetValue
/// Convenience method for returning the value of a dictionaryEntry, if any.
#define dictionaryGetValue(dictionary, key) htGetValue(dictionary, (void*) key)
#define dictionaryToList htToList
extern int (*dictionaryCompare)(const Dictionary *dictionaryA, const Dictionary *dictionaryB);
Dictionary *dictionaryCreate(TypeDescriptor *type);
#define dictionaryToJson(dictionary) listToJson((List*) dictionary)
bool dictionaryUnitTest();
#define dictionaryToKeyValueString(dictionary) \
  listToKeyValueString((List*) dictionary)
#define dictionaryCopy htCopy
#define listToDictionary listToHashTable

// Language functions.
Variant* getObjectProperty(Dictionary *object, const char *propertyName);
bool getLhsRhs(Dictionary *object, const char *condition, const char *testType, char **lhs, char **rhs);
bool testCondition(const char *condition, Dictionary *object);
DictionaryEntry* dictionaryAddVariable(Dictionary *variables,
  const char *variableName, const void *value, TypeDescriptor *type);
int dictionaryRemoveVariable(Dictionary *variables, const char *variableName);
char *strReplaceVariables(void *context, const char *inputString,
  Dictionary *variables);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // DICTIONARY_H

