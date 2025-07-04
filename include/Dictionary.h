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
///                   Copyright (c) 2012-2025 James Card
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
#include "RedBlackTree.h"

typedef RedBlackNode DictionaryEntry;
typedef RedBlackTree Dictionary;

#ifdef __cplusplus
extern "C"
{
#endif

#define typeDictionary typeRedBlackTree
#define typeDictionaryNoCopy typeRedBlackTreeNoCopy

// Helper functions.
int keyValueStringToDictionaryEntry(Dictionary *dictionary, char *inputString);
Dictionary* kvStringToDictionary(const char *inputString,
  const char *separator);
Dictionary* parseCommandLine(int argc, char **argv);
char* getUserValue(Dictionary *args, const char *argName, const char *prompt,
  const char *defaultValue);

// Dictionary functions.
extern Dictionary* (*jsonToDictionary)(
  const char *jsonText, long long int *position);
extern char* (*dictionaryToString)(const Dictionary *dictionary);
extern DictionaryEntry* (*dictionaryAddEntry_)(
  Dictionary *dictionary, const volatile void *key,
  const volatile void *value, TypeDescriptor *type, ...);
#define dictionaryAddEntry(dictionary, key, value, ...) \
  dictionaryAddEntry_(dictionary, key, value, ##__VA_ARGS__, typeString)
extern Dictionary* (*dictionaryDestroy)(Dictionary*);
extern int (*dictionaryRemove)(
  Dictionary *dictionary, const volatile void *key);
extern Bytes (*dictionaryToXml_)(
  const Dictionary *dictionary, const char *elementName, bool indent, ...);
#define dictionaryToXml(dictionary, elementName, ...)  \
  dictionaryToXml_(dictionary, elementName, ##__VA_ARGS__, false)
extern DictionaryEntry* (*dictionaryGetEntry)(
  const Dictionary *dictionary, const volatile void *key);
extern void* (*dictionaryGetValue)(
  const Dictionary *dictionary, const volatile void *key);
extern List* (*dictionaryToList)(Dictionary *dictionary);
extern Bytes (*dictionaryToJson)(const Dictionary *dictionary);
extern int (*dictionaryCompare)(
  const Dictionary *dictionaryA, const Dictionary *dictionaryB);
extern Dictionary* (*dictionaryCreate_)(
  TypeDescriptor *type, bool disableThreadSafety, ...);
#define dictionaryCreate(keyType, ...) \
  dictionaryCreate_(keyType, ##__VA_ARGS__, 0)
extern char* (*dictionaryToKeyValueString)(const Dictionary *dictionary,
  const char *separator);
extern Dictionary* (*dictionaryCopy)(const Dictionary *dictionary);
extern Dictionary* (*listToDictionary)(const List *list);
extern Dictionary* (*dictionaryFromBlob_)(const volatile void *array,
  u64 *length, bool inPlaceData, bool disableThreadSafety, ...);
#define dictionaryFromBlob(array, length, ...) \
  dictionaryFromBlob_(array, length, ##__VA_ARGS__, 0, 0)
extern Bytes (*dictionaryToBlob)(const Dictionary *dictionary);
extern Dictionary* (*xmlToDictionary)(const char *inputData);
extern int (*dictionaryDestroyNode)(
  Dictionary *dictionary, DictionaryEntry *node);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // DICTIONARY_H

