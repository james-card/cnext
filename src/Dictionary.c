////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                     Copyright (c) 2012-2023 James Card                     //
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

#include "Dictionary.h"
#include "Vector.h"

#ifdef LOGGING_ENABLED
#include "LoggingLib.h"
#else
#undef printLog
#define printLog(...) {}
#define logFile stderr
#endif

Dictionary* (*xmlToDictionary)(const char*) = xmlToHashTable;
int (*dictionaryRemove)(Dictionary*, const char*) = (int (*)(Dictionary*, const char*)) htRemoveEntry;
Dictionary* (*dictionaryDestroy)(Dictionary*) = htDestroy;
char* (*dictionaryToString)(const Dictionary*) = htToString;
DictionaryEntry* (*dictionaryGetEntry)(const Dictionary*, const char*) = (DictionaryEntry* (*)(const Dictionary*, const char*)) htGetEntry;
int (*dictionaryCompare)(const Dictionary *dictionaryA, const Dictionary *dictionaryB) = htCompare;

/// @fn Dictionary *dictionaryCreate(TypeDescriptor *type)
///
/// @brief Constructor for a dictionary.
///
/// @param type The TypeDescrptor for the Dictionary keys.
///
/// @return Returns a pointer to a newly-constructed Dictionary on success,
/// NULL on failure.
Dictionary *dictionaryCreate(TypeDescriptor *type) {
  if (type == NULL) {
    type = typeString;
  }
  
  printLog(TRACE, "ENTER dictionaryCreate(type=%s)\n", type->name);
  
  Dictionary *returnValue = htCreate(type, 0);
  
  printLog(TRACE, "EXIT dictionaryCreate(type=%s) = {%p}\n",
    type->name, returnValue);
  return returnValue;
}

/// @fn DictionaryEntry* dictionaryAddEntry_(Dictionary **dictionary, const volatile void *key, const volatile void *value, TypeDescriptor *type, ...)
///
/// @brief Adds a DictionaryEntry to a Dictionary.
///
/// @param dictionary is a pointer to the Dictionary to add the new
///   DictionaryEntry to.
/// @param key is the key of the DictionaryEntry to add.
/// @param value is the value of the DictionaryEntry to add.
///
/// @note the dictionaryAddEntry macro that wraps this function provides
/// typeString as the type by default.
///
/// @return Returns a pointer to a new DictionaryEntry on success, NULL on failure.
DictionaryEntry* dictionaryAddEntry_(Dictionary **dictionary, const volatile void *key,
  const volatile void *value, TypeDescriptor *type, ...
) {
  char *dictionaryString = NULL;
  
  if (dictionary == NULL) {
    printLog(ERR, "NULL dictionary provided.\n");
    return NULL;
  }
  
  dictionaryString = dictionaryToString(*dictionary);
  const char *keyString = NULL;
  (void) keyString; // In case logging is not enabled.
  if (*dictionary == NULL) {
    keyString = type->name;
  } else if (((*dictionary)->keyType == typeString)
    || ((*dictionary)->keyType == typeStringNoCopy)
    || ((*dictionary)->keyType == typeStringCi)
  ) {
    keyString = (const char*) key;
  } else {
    keyString = (*dictionary)->keyType->name;
  }
  printLog(TRACE, "ENTER dictionaryAddEntry(dictionary={%s}, key=\"%s\", value=\"%s\")\n",
    dictionaryString, keyString, (type == typeString) ? (char*) value : type->name);
  
  // Make sure the list is good.
  if (*dictionary == NULL) {
    *dictionary = htCreate(typeString);
    if (*dictionary == NULL) {
      printLog(ERR,  "Could not create hash table for dictionary.\n");
      printLog(TRACE,
        "EXIT dictionaryAddEntry(dictionary={%s}, key=\"%s\", value=\"%s\") = {NULL}\n",
        dictionaryString,
        ((*dictionary)->keyType == typeString) ? (char*) key : (*dictionary)->keyType->name,
        (type == typeString) ? (char*) value : type->name);
      dictionaryString = stringDestroy(dictionaryString);
      return NULL;
    }
  }
  
  DictionaryEntry *returnValue = htAddEntry(*dictionary, key, value, type);
  if (returnValue == NULL) {
    printLog(ERR, "Could not add entry into dictionary.\n");
    printLog(TRACE,
      "EXIT dictionaryAddEntry(dictionary={%s}, key=\"%s\", value=\"%s\") = {NULL}\n",
      dictionaryString,
      ((*dictionary)->keyType == typeString) ? (char*) key : (*dictionary)->keyType->name,
      (type == typeString) ? (char*) value : type->name);
    dictionaryString = stringDestroy(dictionaryString);
    return NULL;
  }
  
  printLog(TRACE,
    "EXIT dictionaryAddEntry(dictionary={%s}, key=\"%s\", value=\"%s\") = {%p}\n",
    dictionaryString,
    ((*dictionary)->keyType == typeString) ? (char*) key : (*dictionary)->keyType->name,
    (type == typeString) ? (char*) value : type->name,
    returnValue);
  dictionaryString = stringDestroy(dictionaryString);
  return returnValue;
}

///////////////////////////////////////////////////////////////////////////////
// Code below this point uses only dictionary-based functions and does not   //
// require modification based on the underlying data structure of the        //
// dictionary.                                                               //
///////////////////////////////////////////////////////////////////////////////

/// @fn int keyValueStringToDictionaryEntry(Dictionary **kvList, char *inputString)
///
/// @brief Convert an '='-delimited key-value string to a DictionaryEntry.
///
/// @param kvList is the list to put the parsed key-value pairs into.
/// @param inputString is the string to parse.  It is not modified.
///
/// @return Returns 0 on success, any other value is failure
int keyValueStringToDictionaryEntry(Dictionary **kvList, char *inputString) {
  int returnValue = 0;
  printLog(TRACE, "ENTER keyValueStringToDictionaryEntry(inputString=\"%s\")\n", inputString);
  
  if (inputString != NULL) {
    char *stringCopy = NULL;
    straddstr(&stringCopy, inputString);
    char *equalAt = strstr(stringCopy, "=");
    if (equalAt != NULL) {
      *equalAt = '\0';
      equalAt++;
      char *key = stringCopy;
      char *value = equalAt;
      unescapeString(key);
      unescapeString(value);
      
      returnValue = -(dictionaryAddEntry(kvList, key, value) == NULL);
    }
    stringCopy = stringDestroy(stringCopy);
  }
  
  printLog(TRACE, "EXIT keyValueStringToDictionaryEntry(inputString=\"%s\") = {\"%d\"}\n", inputString, returnValue);
  return returnValue;
}

/// @fn Dictionary *kvStringToDictionary(const char *inputString, const char *separator)
///
/// @brief Convert a separator-separated key-value list to a Dictionary
///
/// @param inputString is the string to parse.  It is not modified.
/// @param separator is the string that divides the key-value pairs.
///
/// @return Returns a pointer to a Dictionary on success, NULL on failure.
Dictionary *kvStringToDictionary(const char *inputString,
  const char *separator
) {
  Dictionary *returnValue = dictionaryCreate(typeString);
  printLog(TRACE,
    "ENTER kvStringToDictionary(inputString=\"%s\", separator=\"%s\")\n",
    inputString, separator);
  
  int separatorLength = strlen(separator);
  if ((inputString != NULL) && (separator != NULL)) {
    char *stringCopy = NULL;
    straddstr(&stringCopy, inputString);
    char *originalStringCopy = stringCopy;
    
    char *separatorAt = strstr(stringCopy, separator);
    while (separatorAt != NULL) {
      *separatorAt = '\0';
      if (keyValueStringToDictionaryEntry(&returnValue, stringCopy) != 0) {
        printLog(ERR, "Could not add \"%s\" to new Dictionary.\n",
          stringCopy);
      }
      separatorAt += separatorLength;
      stringCopy = separatorAt;
      separatorAt = strstr(separatorAt, separator);
    }
    if (keyValueStringToDictionaryEntry(&returnValue, stringCopy) != 0) {
      printLog(ERR, "Could not add \"%s\" to new Dictionary.\n",
        stringCopy);
    }
    originalStringCopy = stringDestroy(originalStringCopy);
  }
  
  printLog(TRACE,
    "EXIT kvStringToDictionary(inputString=\"%s\", separator=\"%s\") = {\"%p\"}\n",
    inputString, separator, returnValue);
  return returnValue;
}

/// @fn Dictionary *parseCommandLine(int argc, char **argv)
///
/// @brief Parse any command-line arguments passed in and create a dictionary
///   representation.
///
/// @param argc is the number of arguments passed in from the command line
/// @param argv is an array of strings representing the arguments passed in
///
/// @return A Dictionary representing the arguments on success, NULL otherwise.
Dictionary *parseCommandLine(int argc, char **argv) {
  Dictionary *returnValue = NULL;
  u32 unnamedParameterIndex = 0;
  
  printLog(TRACE, "ENTER parseCommandLine(argc=%d, argv=%p)\n", argc, argv);
  
  dictionaryAddEntry(&returnValue, "programPath", argv[0]);
  
  if (argc > 1) {
    // There are arguments to parse.  Parse them.
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] == '-') {
        // Argument is some sort of flag
        if (argv[i][1] == '-') {
          // Argument is long flag
          char *name = NULL;
          straddstr(&name, &(argv[i][2]));
          if (strchr(name, '=')) {
            // Argument is in the form --name=value
            char *value = strchr(name, '=');
            *value = '\0';
            value++;
            dictionaryAddEntry(&returnValue, name, value);
          } else if (i < argc - 1 && argv[i + 1][0] != '-') {
            // The next argument is the value for the argument.
            char *value = argv[i + 1];
            dictionaryAddEntry(&returnValue, name, value);
            i++; // Skip over the value for the next pass.
          } else {
            // Argument represents a boolean.
            const char *value = "";
            dictionaryAddEntry(&returnValue, name, value);
          }
          name = stringDestroy(name);
        } else {
          // Argument is one or more single-character flags.
          int arglen = strlen(argv[i]);
          char name[2];
          name[0] = '\0';
          name[1] = '\0';
          const char *value = "";
          for (int j = 1; j < arglen - 1; j++) {
            name[0] = argv[i][j];
            dictionaryAddEntry(&returnValue, name, value);
          }
          // We've taken care of all but the last flag in this argument.
          name[0] = argv[i][arglen - 1];
          if ((i == argc - 1) || (argv[i + 1][0] == '-')) {
            // Next argument is named or does not exist.
            // This flag is a boolean.
            dictionaryAddEntry(&returnValue, name, value);
          } else {
            // Next argument is unnamed.  Use it as the value.
            value = argv[i + 1];
            dictionaryAddEntry(&returnValue, name, value);
            i++; // Skip over the value for the next pass.
          }
        }
      } else {
        char *name = NULL;
        char *value = argv[i];
        if (asprintf(&name, "unnamedParameter%u", unnamedParameterIndex++) > 0) {
          dictionaryAddEntry(&returnValue, name, value);
          name = stringDestroy(name);
        }
      }
    }
  }
  // else:  No arguments to parse.
  
  printLog(TRACE, "EXIT parseCommandLine(argc=%d, argv=%p) = {%p}\n", argc,
    argv, returnValue);
  return returnValue;
}

/// @fn char* getUserValue(Dictionary *args, const char *argName, const char *prompt, const char *defaultValue)
///
/// @brief Get a value from the user.
///
/// @param args The parsed command line arguments.
/// @param argName The name of the argument on the command line, if provided.
/// @param prompt The prompt to provide the user if there's no command line
///   value.
/// @param defaultValue The default value to provide if the user provides none.
///
/// @return Returns a newly-allocated string value with the appropriate value.
char* getUserValue(Dictionary *args, const char *argName, const char *prompt,
  const char *defaultValue
) {
  char *returnValue = NULL;
  static char buffer[4096];

  char *argValue = (char*) dictionaryGetValue(args, argName);
  if (argValue == NULL) {
    printf("%s [%s]: ", prompt, defaultValue);
    argValue = fgets(buffer, sizeof(buffer), stdin);
    if (*argValue == '\n') {
      argValue = NULL;
    } else {
      // Remove the trailing newline.
      argValue[strlen(argValue) - 1] = '\0';
    }
  }

  if (argValue == NULL) {
    straddstr(&returnValue, defaultValue);
  } else {
    straddstr(&returnValue, argValue);
  }

  return returnValue;
}

/// @fn Dictionary *functionCallToDictionary(const char *call)
///
/// @brief Parse any command-line arguments passed in and create a dictionary
///   representation.
///
/// @param argv is an array of strings representing the arguments passed in
///
/// @return A Dictionary representing the arguments on success, NULL otherwise.
Dictionary *functionCallToDictionary(const char *call) {
  Dictionary *returnValue = NULL;
  u32 unnamedParameterIndex = 0;
  
  printLog(TRACE, "ENTER functionCallToDictionary(call=\"%s\")\n", call);
  
  char *callCopy = NULL;
  straddstr(&callCopy, call);
  char *openParenthesis = strchr(callCopy, '(');
  if (openParenthesis == NULL) {
    // Invalid input.
    callCopy = stringDestroy(callCopy);
    printLog(TRACE, "EXIT functionCallToDictionary(call=\"%s\") = {%p}\n",
      call, returnValue);
    return returnValue;
  }
  *openParenthesis = '\0';
  dictionaryAddEntry(&returnValue, "@functionName", callCopy);
  char *nextParameter = openParenthesis + 1;
  
  char *closeParenthesis = strchr(nextParameter, ')');
  if (closeParenthesis == NULL) {
    // Invalid input.
    returnValue = dictionaryDestroy(returnValue);
    callCopy = stringDestroy(callCopy);
    printLog(TRACE, "EXIT functionCallToDictionary(call=\"%s\") = {%p}\n",
      call, returnValue);
    return returnValue;
  }
  *closeParenthesis = '\0';
  
  while ((nextParameter != NULL) && (*nextParameter != '\0')) {
    char *commaAt = strchr(nextParameter, ',');
    if (commaAt != NULL) {
      *commaAt = '\0';
    }
    
    char *name = nextParameter;
    char *value = nextParameter;
    
    char *equalAt = strchr(nextParameter, '=');
    if (equalAt != NULL) {
      *equalAt = '\0';
      value = equalAt + 1;
    }
    
    // Trim the spaces from around the value.
    value = &value[strspn(value, " 	\n")];
    char *spaceAt = &value[strcspn(value, " 	\n")];
    if (spaceAt != NULL) {
      *spaceAt = '\0';
    }
    
    if (name != value) {
      // The usual case.
      // Trim the spaces from around the name.
      name = &name[strspn(name, " 	\n")];
      char *spaceAt = &name[strcspn(name, " 	\n")];
      if (spaceAt != NULL) {
        *spaceAt = '\0';
      }
      
      dictionaryAddEntry(&returnValue, name, value);
    } else {
      name = NULL;
      if (asprintf(&name, "unnamedParameter%u", unnamedParameterIndex++) > 0) {
        dictionaryAddEntry(&returnValue, name, value);
        name = stringDestroy(name);
      }
    }
    
    if (commaAt != NULL) {
      nextParameter = commaAt + 1;
    } else {
      nextParameter = NULL;
    }
  }
  
  callCopy = stringDestroy(callCopy);
  
  printLog(TRACE, "EXIT functionCallToDictionary(call=\"%s\") = {%p}\n",
    call, returnValue);
  return returnValue;
}

/// @fn DictionaryEntry* dictionaryAddVariable(Dictionary *variables, const char *variableName, const void *value, TypeDescriptor *type)
///
/// @brief Add a variable to an existing variable dictionary.  If the name of
/// the variable name is in obeject.name format, a new sub-dictionary will be
/// created and the variable will be added to that sub-dictionary in a recursive
/// call.
///
/// @param variables An existing Dictionary of variables.
/// @param variableName The name of the variable to add.
/// @param value The value to associate with the variable name.
/// @param type The TypeDescriptor for the value.
///
/// @return Returns a pointer to the new DictionaryEntry added on success,
/// NULL on failure.
DictionaryEntry* dictionaryAddVariable(Dictionary *variables,
  const char *variableName, const void *value, TypeDescriptor *type
) {
  printLog(TRACE,
    "ENTER dictionaryAddVariable(variables=%p, variableName=%s, "
    "value=%p, type=%p)\n",
    variables, (variableName != NULL) ? variableName : "NULL", value, type);
  
  if ((variables == NULL) || (variableName == NULL) || (type == NULL)) {
    printLog(ERR, "One or more invalid (NULL) parameters.\n");
    printLog(TRACE,
      "EXIT dictionaryAddVariable(variables=%p, variableName=%s, "
      "value=%p, type=%p) = {%p}\n",
      variables, (variableName != NULL) ? variableName : "NULL", value, type,
      (void*) NULL);
    return NULL;
  }
  
  DictionaryEntry *returnValue = NULL;
  
  const char *dotAt = strchr(variableName, '.');
  if (dotAt == NULL) {
    // variableName is a simple name
    returnValue = dictionaryAdd(variables, variableName, value, type);
  } else {
    // variableName is in object.name format
    Bytes subVariablesName = getBytesBetween(variableName, "", ".");
    DictionaryEntry *subVariablesNode
      = dictionaryGetEntry(variables, str(subVariablesName));
    Dictionary *subVariables = NULL;
    if (subVariablesNode == NULL) {
      subVariables = dictionaryCreate(variables->keyType); // Probably typeString
    } else {
      subVariables = (Dictionary*) subVariablesNode->value;
    }
    returnValue = dictionaryAddVariable(subVariables, dotAt + 1, value, type);
    if ((subVariablesNode == NULL) && (returnValue != NULL)) {
      // Add the new list to our variables list, but don't make a copy.
      subVariablesNode = dictionaryAdd(variables,
        subVariablesName, subVariables, typeDictionaryNoCopy);
      if (subVariablesNode != NULL) {
        // Convert the type to a full list so that it's properly destroyed.
        subVariablesNode->type = typeDictionary;
      } else {
        returnValue = NULL;
        subVariables = dictionaryDestroy(subVariables);
      }
    } else if (subVariablesNode == NULL) { // returnValue != 0
      subVariables = dictionaryDestroy(subVariables);
    }
    subVariablesName = bytesDestroy(subVariablesName);
  }
  
  printLog(TRACE,
    "EXIT dictionaryAddVariable(variables=%p, variableName=%s, "
    "value=%p, type=%p) = {%p}\n",
    variables, (variableName != NULL) ? variableName : "NULL", value, type,
    returnValue);
  return returnValue;
}

/// @fn int dictionaryRemoveVariable(Dictionary *variables, const char *variableName)
///
/// @brief Remove a variable from a dictionary of variables given its name.  The
/// variable name may either be a simple name or a name in object.name format.
///
/// @param variables The dictionary of variables to remove from.
/// @param variableName The name of the variable to remove.
///
/// @return Returns 0 on success, -1 on failure.
int dictionaryRemoveVariable(Dictionary *variables, const char *variableName) {
  printLog(TRACE,
    "ENTER dictionaryRemoveVariable(variables=%p, variableName=%s)\n",
    variables, (variableName != NULL) ? variableName : "NULL");
  
  if ((variables == NULL) || (variableName == NULL)) {
    printLog(ERR, "One or more invalid (NULL) parameters.\n");
    printLog(TRACE,
      "EXIT dictionaryRemoveVariable(variables=%p, variableName=%s) = {%d}\n",
      variables, (variableName != NULL) ? variableName : "NULL", -1);
    return -1;
  }
  
  int returnValue = 0;
  
  const char *dotAt = strchr(variableName, '.');
  if (dotAt == NULL) {
    // variableName is a simple name
    returnValue = dictionaryRemove(variables, variableName);
  } else {
    // variableName is in object.name format
    Bytes subVariablesName = getBytesBetween(variableName, "", ".");
    DictionaryEntry *subVariablesNode
      = dictionaryGetEntry(variables, str(subVariablesName));
    subVariablesName = bytesDestroy(subVariablesName);
    if (subVariablesNode != NULL) {
      returnValue
        = dictionaryRemoveVariable((Dictionary*) subVariablesNode->value,
        dotAt + 1);
    } else {
      returnValue = -1;
    }
  }
  
  printLog(TRACE,
    "EXIT dictionaryRemoveVariable(variables=%p, variableName=%s) = {%d}\n",
    variables, (variableName != NULL) ? variableName : "NULL", returnValue);
  return returnValue;
}

/// @fn char *strReplaceVariables(void *context, const char *inputString, Dictionary *variables)
///
/// @brief Replace ${variableName}-style variables with the values as defined
/// by the dictionary of input variables.  Variables may be simple names or may
/// be in object.name syntax.  Variables may be in "func(...)" or
/// "object.func(...)" syntax to be replaced by the return value of a function
/// call.
///
/// @param context A pointer to a user-defined object holding contex for
///   function execution.  This value will be passed to any handler functions.
/// @param inputString The string that contains the ${} variables to replace.
/// @param variables A pointer to a Dictionary that contains the names of the
///   variables as keys and the values as values.  Values may be subordinate
///   dictionaries if object.name syntax is used.
///
/// @return Returns a newly-allocated string with the ${} variables replaced
/// by variables described by the input variable list.  Variables in ${} not
/// found by this function are left as they are.
char *strReplaceVariables(void *context, const char *inputString,
  Dictionary *variables
) {
  printLog(TRACE,
    "ENTER strReplaceVariables(context=%p, inputString=\"%s\", variables=%p)\n",
    context, inputString, variables);
  
  char *outputString = NULL;
  straddstr(&outputString, inputString);
  
  if ((inputString == NULL) || (variables == NULL)) {
    printLog(ERR, "One or more invalid (NULL) parameters.\n");
    printLog(TRACE,
      "EXIT strReplaceVariables(context=%p, inputString=\"%s\", variables=%p) "
      "= {%s})\n", context, inputString, variables, outputString);
    return NULL;
  }
  
  const char *searchString = inputString;
  Bytes variable = getBytesBetween(searchString, "${", "}");
  while (variable != NULL) {
    searchString += bytesLength(variable);
    char *variableStart = &str(variable)[strspn(str(variable), " \t\n")];
    char *variableEnd = &variableStart[strcspn(variableStart, " \t\n")];
    *variableEnd = '\0';
    
    char *value = NULL;
    if (!strchr(variableStart, '(')) {
      // Variable is just a variable.  Get its value.
      // This is the expected case.
      Variant *variantValue = getObjectProperty(variables, variableStart);
      if (variantValue != NULL) {
        value = variantValue->type->toString(variantValue->value);
      }
    } else {
      // Variable is a function call.
      Dictionary *functionCall = functionCallToDictionary(variableStart);
      const char *functionName
        = (char*) dictionaryGetValue(functionCall, "@functionName");
      Variant *variantValue = getObjectProperty(variables, functionName);
      if ((variantValue != NULL) && (variantValue->type == typePointerNoOwn)) {
        UserFunctionHandler userFunctionHandler
          = dataToUserFunc((void*) variantValue->value);
        Variant userFunctionData = userFunctionHandler(context, functionCall);
        if (userFunctionData.type == typeString) {
          // This is the expected case.
          value = str(userFunctionData.value);
        } else {
          value = userFunctionData.type->toString(userFunctionData.value);
          userFunctionData.type->destroy(userFunctionData.value);
        }
      }
    }
    
    if (value != NULL) {
      // We know the variable is part of the string, so no need to capture
      // whether or not a replacement is made because it's guaranteed.
      Bytes fullVariable = NULL;
      bytesAddStr(&fullVariable, "${");
      bytesAddBytes(&fullVariable, variable);
      bytesAddStr(&fullVariable, "}");
      char *temp
        = strReplaceOneStr(outputString, str(fullVariable), value, NULL);
      fullVariable = bytesDestroy(fullVariable);
      value = stringDestroy(value);
      outputString = stringDestroy(outputString);
      outputString = temp;
    }
    
    variable = bytesDestroy(variable);
    variable = getBytesBetween(searchString, "${", "}");
  }
  
  printLog(TRACE,
    "EXIT strReplaceVariables(context=%p, inputString=\"%s\", variables=%p) "
    "= {%s})\n", context, inputString, variables, outputString);
  return outputString;
}

/// @fn Variant* getObjectProperty(Dictionary *object, const char *propertyName)
///
/// @brief Return the value of a property given a name and a Dictionary
///   representing an object.
///
/// @param object The Dictionary representing the object.
/// @param propertyName The fully-qualified property name with respect to
///   the object.
///
/// @return Returns a pointer to the Variant found on success, NULL on failure.
Variant* getObjectProperty(Dictionary *object, const char *propertyName) {
  printLog(TRACE, "ENTER getObjectProperty(object=%p, propertyName=\"%s\")\n",
    object, propertyName);
  
  char *propertyNameCopy = NULL;
  straddstr(&propertyNameCopy, propertyName);
  
  char *bracketAt = strchr(propertyNameCopy, '[');
  
  char *dotAt = strchr(propertyNameCopy, '.');
  if (dotAt != NULL) {
    *dotAt = '\0';
  }
  
  char *indexString = NULL;
  if ((bracketAt != NULL) && (bracketAt < dotAt)) {
    Bytes textBetween = getBytesBetween(propertyNameCopy, "[", "");
    straddstr(&indexString, "[");
    straddstr(&indexString, (char*) textBetween);
    textBetween = bytesDestroy(textBetween);
    *bracketAt = '\0';
  }
  
  Variant *returnValue = NULL;
  DictionaryEntry *nameValue = dictionaryGetEntry(object, propertyNameCopy);
  if (nameValue != NULL) {
    if (((nameValue->type == typeDictionary)
      || (nameValue->type == typeDictionaryNoCopy)) && (dotAt != NULL)
    ) {
      returnValue = getObjectProperty((Dictionary*) nameValue->value, (dotAt + 1));
    } else if (((nameValue->type == typeVector)
      || (nameValue->type == typeVectorNoCopy)) && (bracketAt != NULL)
    ) {
      VectorNode *node
        = vectorGetIndex((Vector*) nameValue->value, indexString);
      if ((node != NULL) && (node->type == typeDictionary)) {
        if (dotAt == NULL) {
          dotAt = strchr(indexString, '.');
        }
        if (dotAt != NULL) {
          returnValue
            = getObjectProperty((Dictionary*) node->value, (dotAt + 1));
        } // else we're going to return a NULL because propertyName is malformed
      } else if (node != NULL) {
        // This is the value we're looking for.
        returnValue = (Variant*) node;
      }
    } else if (nameValue->type != typeDictionary && dotAt != NULL) {
      // propertyName references an undefined value.
      returnValue = NULL;
    } else {
      // Found the value we're looking for.
      returnValue = (Variant*) nameValue;
    }
  }
  indexString = stringDestroy(indexString);
  propertyNameCopy = stringDestroy(propertyNameCopy);
  
  printLog(TRACE, "EXIT getObjectProperty(object=%p, propertyName=\"%s\") = {%p}\n",
    object, propertyName, returnValue);
  return returnValue;
}

/// @fn bool getLhsRhs(Dictionary *object, const char *condition, const char *testType, char **lhs, char **rhs)
///
/// @brief Get the left-hand side and the right-hand side of a test condition
///   based on the values available in an object.
///
/// @param object is the List that represents the object's properties
/// @param condition is the string that is being evaluated
/// @param testType is the type of test being evaluated (!=, ==, etc.)
/// @param lhs is a pointer to a string that will hold the left-hand value
/// @param rhs is a pointer to a stirng that will hold the right-hand value
///
/// @return Returns true on success, false on failure.
bool getLhsRhs(Dictionary *object, const char *condition, const char *testType,
  char **lhs, char **rhs
) {
  bool returnValue = false;
  char *testAt = NULL;
  
  printLog(TRACE, "ENTER getLhsRhs(object=%p, condition=\"%s\", testType=\"%s\", *lhs=\"%s\", *rhs=\"%s\")\n",
    object, condition, testType, *lhs, *rhs);
  
  char *conditionCopy = NULL;
  straddstr(&conditionCopy, condition);
  
  if ((testAt = strstr(conditionCopy, testType)) != NULL) {
    *testAt = '\0';
    
    char *valueAt = testAt + 1;
    while ((*valueAt == ' ') || (*valueAt == '\t') || (*valueAt == '=')) {
      valueAt++;
    }
    
    char *spaceAt = strchr(conditionCopy, ' ');
    if (spaceAt != NULL) {
      *spaceAt = '\0';
    }
    Variant *variant = getObjectProperty(object, conditionCopy);
    if (variant != NULL) {
      *lhs = variant->type->toString(variant->value);
    } else {
      *lhs = NULL;
    }
    
    spaceAt = strchr(valueAt, ' ');
    if (spaceAt != NULL) {
      *spaceAt = '\0';
    }
    variant = getObjectProperty(object, valueAt);
    if (variant != NULL) {
      *rhs = variant->type->toString(variant->value);
    } else {
      // Use the string representation of the value we're looking for.
      straddstr(rhs, valueAt);
    }
    
    returnValue = true;
  }
  
  conditionCopy = stringDestroy(conditionCopy);
  
  printLog(TRACE, "EXIT getLhsRhs(object=%p, condition=\"%s\", testType=\"%s\", *lhs=\"%s\", *rhs=\"%s\") = {\"%d\"}\n",
    object, condition, testType, *lhs, *rhs, returnValue);
  return returnValue;
}

/// @fn bool testCondition(char *conditionString, Dictionary *object)
///
/// @brief Evaluate whether an object meets a specified condition.
///
/// @param conditionString is the condition to evalutate and test it may take
///   the form:<br />
///   object [test] value<br />
///          OR<br />
///   object.property [test] value<br />
///   where value is either a primitive or an object and [test] is one of:<br />
///   != OR == OR <= OR >= OR < OR > OR<br />
///   condition may also be a complex condition in the form of:<br />
///   (condition) [operator] (condition)<br />
///   where operator is one of "||" OR "&&"<br />
/// @param object is the Dictionary that represents the object to evalutate
///
/// @return Returns true if the object satisfies the condition, false otherwise.
bool testCondition(const char *conditionString, Dictionary *object) {
  int returnValue = true;
  int conditionIndex = 0;
  int startCondition = 0;
  
  printLog(TRACE,
    "ENTER testCondition(conditionString=\"%s\", object=%p)\n",
    conditionString, object);
  
  char *condition = NULL;
  straddstr(&condition, conditionString);
  
  if (condition == NULL || object == NULL) {
    returnValue = false;
    printLog(ERR, "Invalid condition or object provided.\n");
    printLog(TRACE,
      "EXIT testCondition(condition=\"%s\", object=%p) = {%d}\n", condition,
      object, returnValue);
    condition = stringDestroy(condition);
    return returnValue;
  }
  
  if (condition[conditionIndex] == '(') {
    // Condition is complex
    // Find closing parenthesis
    int numParentheses = 1;
    conditionIndex++;
    while (numParentheses > 0 && condition[conditionIndex] != '\0') {
      if (condition[conditionIndex] == '(') {
        numParentheses++;
        if (numParentheses > 15) {
          returnValue = false;
          printLog(ERR, "Too many parentheses for condition \"%s\".\n", condition);
          printLog(TRACE,
            "EXIT testCondition(condition=\"%s\", object=%p) = {%d}\n", condition,
            object, returnValue);
          condition = stringDestroy(condition);
          return returnValue;
        }
      } else if (condition[conditionIndex] == ')') {
        numParentheses--;
      }
      conditionIndex++;
    }
    // Error check
    if (numParentheses != 0) {
      returnValue = false;
      printLog(ERR, "Mis-matched parentheses in condition.\n");
      printLog(TRACE,
        "EXIT testCondition(condition=\"%s\", object=%p) = {%d}\n", condition,
        object, returnValue);
      condition = stringDestroy(condition);
      return returnValue;
    }
    
    // Condition is everything between startCondition and conditionIndex - 1,
    // exclusive
    char *subCondition = (char*) malloc(conditionIndex - startCondition - 1);
    strncpy(subCondition, &condition[startCondition + 1],
      conditionIndex - startCondition - 2);
    subCondition[conditionIndex - startCondition - 2] = '\0';
    bool subConditionValue = testCondition(subCondition, object);
    subCondition = stringDestroy(subCondition);
    
    if (condition[conditionIndex] != '\0') {
      startCondition = conditionIndex;
      while (condition[startCondition] != '(' &&
        condition[startCondition] != '\0') {
        startCondition++;
      }
      char *andAt = strstr(&condition[conditionIndex], "&&");
      char *orAt = strstr(&condition[conditionIndex], "||");
      if (((andAt != NULL && orAt != NULL && andAt < orAt) ||
        (andAt != NULL)) &&
        (andAt < &condition[startCondition])) {
        // Next condtion should be and-ed with the current condition
        returnValue = subConditionValue &
          testCondition(&condition[startCondition], object);
      } else if (((andAt != NULL && orAt != NULL && orAt < andAt) ||
        (orAt != NULL)) &&
        (orAt < &condition[startCondition])) {
        // Next condtion should be or-ed with the current condition
        returnValue = subConditionValue |
          testCondition(&condition[startCondition], object);
      } else {
        // No more conditions to evaluate
        printLog(INFO, "Non ')'-terminated condition detected.\n");
        returnValue = subConditionValue;
      }
    } else {
      returnValue = subConditionValue;
    }
    printLog(TRACE,
      "EXIT testCondition(condition=\"%s\", object=%p) = {%d}\n", condition,
      object, returnValue);
    condition = stringDestroy(condition);
    return returnValue;
  }
  
  // Condition is not complex.  Evaluate.
  char *testAt = NULL;
  if ((testAt = strstr(condition, "!=")) != NULL) {
    // Evaluate for inequality.
    char *lhs = NULL, *rhs = NULL;
    
    getLhsRhs(object, condition, "!=", &lhs, &rhs);
    if (strcmp(rhs, "null") == 0) {
      returnValue = (lhs != NULL);
    } else if ((lhs == NULL && rhs != NULL) || (lhs != NULL && rhs == NULL)) {
      // Something is not right with this condition.  Part of it could not be
      // resolved.  This could be a constant in the lhs.  Anyway, they're not
      // comparable so return true.
      returnValue = true;
    } else {
      returnValue = (strcmp(lhs, rhs) != 0);
    }
    lhs = stringDestroy(lhs);
    rhs = stringDestroy(rhs);
  } else if ((testAt = strstr(condition, "==")) != NULL) {
    // Evaluate for equality.
    char *lhs = NULL, *rhs = NULL;
    
    getLhsRhs(object, condition, "==", &lhs, &rhs);
    if (strcmp(rhs, "null") == 0) {
      returnValue = (lhs == NULL);
    } else if ((lhs == NULL && rhs != NULL) || (lhs != NULL && rhs == NULL)) {
      // Something is not right with this condition.  Part of it could not be
      // resolved.  This could be a constant in the lhs.  Anyway, they're not
      // comparable so return false.
      returnValue = false;
    } else {
      if ((rhs[0] == '"') && (rhs[strlen(rhs) - 1] == '"')) {
        // Evaluate the string in the quotes.
        rhs[strlen(rhs) - 1] = '\0';
        char *tempString = NULL;
        straddstr(&tempString, &rhs[1]);
        rhs = stringDestroy(rhs);
        rhs = tempString;
      }
      returnValue = (strcmp(lhs, rhs) == 0);
    }
    lhs = stringDestroy(lhs);
    rhs = stringDestroy(rhs);
  } else if ((testAt = strstr(condition, "<=")) != NULL) {
    // Evaluate for less-than or equal-to.
    char *lhs = NULL, *rhs = NULL;
    
    getLhsRhs(object, condition, "<=", &lhs, &rhs);
    if (isNumber(lhs) && isNumber(rhs)) {
      // Compare numerically
      long double lhsNumber = strtold(lhs, NULL);
      long double rhsNumber = strtold(rhs, NULL);
      returnValue = (lhsNumber <= rhsNumber);
    } else if (isNumber(lhs) || isNumber(rhs)) {
      // One of the values is a number, the other is not.  Not a match
      returnValue = false;
    } else if ((lhs == NULL && rhs != NULL) || (lhs != NULL && rhs == NULL)) {
      // Something is not right with this condition.  Part of it could not be
      // resolved.  This could be a constant in the lhs.  Anyway, they're not
      // comparable so return false.
      returnValue = false;
    } else {
      // Compare strings
      if ((rhs[0] == '"') && (rhs[strlen(rhs) - 1] == '"')) {
        // Evaluate the string in the quotes.
        rhs[strlen(rhs) - 1] = '\0';
        char *tempString = NULL;
        straddstr(&tempString, &rhs[1]);
        rhs = stringDestroy(rhs);
        rhs = tempString;
      }
      returnValue = (strcmp(lhs, rhs) <= 0);
    }
    lhs = stringDestroy(lhs);
    rhs = stringDestroy(rhs);
  } else if ((testAt = strstr(condition, ">=")) != NULL) {
    // Evaluate for greater-than or equal-to.
    char *lhs = NULL, *rhs = NULL;
    
    getLhsRhs(object, condition, ">=", &lhs, &rhs);
    if (isNumber(lhs) && isNumber(rhs)) {
      // Compare numerically
      long double lhsNumber = strtold(lhs, NULL);
      long double rhsNumber = strtold(rhs, NULL);
      returnValue = (lhsNumber >= rhsNumber);
    } else if (isNumber(lhs) || isNumber(rhs)) {
      // One of the values is a number, the other is not.  Not a match
      returnValue = false;
    } else if ((lhs == NULL && rhs != NULL) || (lhs != NULL && rhs == NULL)) {
      // Something is not right with this condition.  Part of it could not be
      // resolved.  This could be a constant in the lhs.  Anyway, they're not
      // comparable so return false.
      returnValue = false;
    } else {
      // Compare strings
      if ((rhs[0] == '"') && (rhs[strlen(rhs) - 1] == '"')) {
        // Evaluate the string in the quotes.
        rhs[strlen(rhs) - 1] = '\0';
        char *tempString = NULL;
        straddstr(&tempString, &rhs[1]);
        rhs = stringDestroy(rhs);
        rhs = tempString;
      }
      returnValue = (strcmp(lhs, rhs) >= 0);
    }
    lhs = stringDestroy(lhs);
    rhs = stringDestroy(rhs);
  } else if ((testAt = strstr(condition, "<")) != NULL) {
    // Evaluate for less-than.
    char *lhs = NULL, *rhs = NULL;
    
    getLhsRhs(object, condition, "<", &lhs, &rhs);
    if (isNumber(lhs) && isNumber(rhs)) {
      // Compare numerically
      long double lhsNumber = strtold(lhs, NULL);
      long double rhsNumber = strtold(rhs, NULL);
      returnValue = (lhsNumber < rhsNumber);
    } else if (isNumber(lhs) || isNumber(rhs)) {
      // One of the values is a number, the other is not.  Not a match
      returnValue = false;
    } else if ((lhs == NULL && rhs != NULL) || (lhs != NULL && rhs == NULL)) {
      // Something is not right with this condition.  Part of it could not be
      // resolved.  This could be a constant in the lhs.  Anyway, they're not
      // comparable so return false.
      returnValue = false;
    } else {
      // Compare strings
      if ((rhs[0] == '"') && (rhs[strlen(rhs) - 1] == '"')) {
        // Evaluate the string in the quotes.
        rhs[strlen(rhs) - 1] = '\0';
        char *tempString = NULL;
        straddstr(&tempString, &rhs[1]);
        rhs = stringDestroy(rhs);
        rhs = tempString;
      }
      returnValue = (strcmp(lhs, rhs) < 0);
    }
    lhs = stringDestroy(lhs);
    rhs = stringDestroy(rhs);
  } else if ((testAt = strstr(condition, ">")) != NULL) {
    // Evaluate for greater-than.
    char *lhs = NULL, *rhs = NULL;
    
    getLhsRhs(object, condition, ">", &lhs, &rhs);
    if (isNumber(lhs) && isNumber(rhs)) {
      // Compare numerically
      long double lhsNumber = strtold(lhs, NULL);
      long double rhsNumber = strtold(rhs, NULL);
      returnValue = (lhsNumber > rhsNumber);
    } else if (isNumber(lhs) || isNumber(rhs)) {
      // One of the values is a number, the other is not.  Not a match
      returnValue = false;
    } else if ((lhs == NULL && rhs != NULL) || (lhs != NULL && rhs == NULL)) {
      // Something is not right with this condition.  Part of it could not be
      // resolved.  This could be a constant in the lhs.  Anyway, they're not
      // comparable so return false.
      returnValue = false;
    } else {
      // Compare strings
      if ((rhs[0] == '"') && (rhs[strlen(rhs) - 1] == '"')) {
        // Evaluate the string in the quotes.
        rhs[strlen(rhs) - 1] = '\0';
        char *tempString = NULL;
        straddstr(&tempString, &rhs[1]);
        rhs = stringDestroy(rhs);
        rhs = tempString;
      }
      returnValue = (strcmp(lhs, rhs) > 0);
    }
    lhs = stringDestroy(lhs);
    rhs = stringDestroy(rhs);
  } else {
    printLog(DETAIL,
      "No test operator provided.  Assuming empty requirement.\n");
    returnValue = true;
  }
  
  condition = stringDestroy(condition);
  
  printLog(TRACE,
    "EXIT testCondition(conditionString=\"%s\", object=%p) = {%d}\n",
    conditionString, object, returnValue);
  
  return returnValue;
}

/// @fn bool dictionaryUnitTest()
///
/// @brief Unit tests for dictionary functionality.
/// @details Implementing this as a macro instead of raw code allows this to
/// be skipped by the code coverage metrics.
///
/// @return Returns true on success, false on failure.
///
/// @note
/// NULL string should result in an unmodified dictionary
/// Improperly formatted string should result in an unmodified dictionary
/// Properly formatted string should result in a dictionary with a new
///   node.
///
/// @todo
////keyValueStringToDictionaryEntry(Dictionary **dictionary, char *inputString);
////Dictionary *kvStringToDictionary(char *inputString);
////Dictionary *parseCommandLine(int argc, char **argv);
////extern Dictionary* (*xmlToDictionary)(char *inputData);
#define DICTIONARY_UNIT_TEST \
bool dictionaryUnitTest() { \
  Dictionary *dictionary = NULL; \
  char *stringValue = NULL; \
  List *dictList = NULL; \
  const char *argv[] = { \
    "programPath", \
    "--arg1", \
    "value1", \
    "--booleanArg", \
    "-flags" \
  }; \
  int argc = 5; \
 \
  printLog(INFO, "Testing Dictionary data structure.\n"); \
 \
  dictionary = parseCommandLine(argc, (char**) argv); \
  if (dictionaryGetEntry(dictionary, "arg1") == NULL) { \
    printLog(ERR, "arg1 was not loaded into dictionary.\n"); \
    return false; \
  } \
  stringValue = (char*) dictionaryGetEntry(dictionary, "arg1")->value; \
  if ((stringValue == NULL) || (strcmp(stringValue, "value1") != 0)) { \
    printLog(ERR, "Value of arg1 was not \"value1\".\n"); \
    return false; \
  } \
  if (dictionaryGetEntry(dictionary, "booleanArg") == NULL) { \
    printLog(ERR, "booleanArg was not loaded into dictionary.\n"); \
    return false; \
  } \
  if (dictionaryGetEntry(dictionary, "f") == NULL) { \
    printLog(ERR, "f was not loaded into dictionary.\n"); \
    return false; \
  } \
  if (dictionaryGetEntry(dictionary, "l") == NULL) { \
    printLog(ERR, "l was not loaded into dictionary.\n"); \
    return false; \
  } \
  if (dictionaryGetEntry(dictionary, "a") == NULL) { \
    printLog(ERR, "a was not loaded into dictionary.\n"); \
    return false; \
  } \
  if (dictionaryGetEntry(dictionary, "g") == NULL) { \
    printLog(ERR, "g was not loaded into dictionary.\n"); \
    return false; \
  } \
  if (dictionaryGetEntry(dictionary, "s") == NULL) { \
    printLog(ERR, "s was not loaded into dictionary.\n"); \
    return false; \
  } \
  dictionaryDestroy(dictionary); dictionary = NULL; \
 \
  printLog(INFO, "Converting NULL dictionary to string.\n"); \
  stringValue = dictionaryToString(NULL); \
  if (stringValue == NULL) { \
    printLog(ERR, "Expected non-NULL string from dictionaryToString.\n"); \
    printLog(ERR, "Got \"%p\"\n", stringValue); \
    return false; \
  } else if (*stringValue != '\0') { \
    printLog(ERR, "Expected empty string from dictionaryToString.\n"); \
    printLog(ERR, "Got \"%s\"\n", stringValue); \
    stringValue = stringDestroy(stringValue); \
    return false; \
  } \
  stringValue = stringDestroy(stringValue); \
 \
  printLog(INFO, "Destroying NULL dictionary.\n"); \
  dictionaryDestroy(dictionary); \
 \
  printLog(INFO, "Removing NULL key from NULL dictionary.\n"); \
  dictionaryRemove(dictionary, NULL); \
 \
  printLog(INFO, "Converting NULL dictionary to XML with NULL root.\n"); \
  stringValue = dictionaryToXml(dictionary, NULL); \
  if (stringValue == NULL) { \
    printLog(ERR, "Expected non-NULL string from dictionaryToXml.\n"); \
    printLog(ERR, "Got \"%p\"\n", stringValue); \
    return false; \
  } else if (strcmp(stringValue, "<></>") != 0) { \
    printLog(ERR, "Expected empty XML from dictionaryToXml.\n"); \
    printLog(ERR, "Got \"%s\"\n", stringValue); \
    stringValue = stringDestroy(stringValue); \
    return false; \
  } \
  stringValue = stringDestroy(stringValue); \
 \
  printLog(INFO, "Getting NULL key from NULL dictionary.\n"); \
  stringValue = (char*) dictionaryGetValue(dictionary, NULL); \
  if (stringValue != NULL) { \
    printLog(ERR, "Expected NULL pointer from dictionaryGetValue.\n"); \
    printLog(ERR, "Got \"%p\"\n", stringValue); \
    return false; \
  } \
 \
  printLog(INFO, "Making list from NULL dictionary.\n"); \
  dictList = dictionaryToList(NULL); \
  if (dictList != NULL) { \
    printLog(ERR, "Expected NULL list from dictionaryToList.\n"); \
    printLog(ERR, "Got \"%p\"\n", dictList); \
    return false; \
  } \
 \
  printLog(INFO, "Adding NULL key and value to NULL dictionary.\n"); \
  dictionaryAddEntry(&dictionary, NULL, NULL); \
  dictionaryDestroy(dictionary); dictionary = NULL; \
 \
  printLog(INFO, "Creating empty dictionary.\n"); \
  dictionary = htCreate(typeString); \
 \
  printLog(INFO, "Converting empty dictionary to string.\n"); \
  stringValue = dictionaryToString(dictionary); \
  if (stringValue == NULL) { \
    printLog(ERR, "Expected empty string from dictionaryToString.\n"); \
    printLog(ERR, "Got NULL.\n"); \
    return false; \
  } else if (strcmp(stringValue, "size=0\ntableSize=64\n") != 0) { \
    printLog(ERR, \
      "Expected (almost) empty string from dictionaryToString.\n"); \
    printLog(ERR, "Got \"%s\".\n", stringValue); \
    return false; \
  } \
  stringValue = stringDestroy(stringValue); \
 \
  printLog(INFO, "Converting empty dictionary to XML with NULL element.\n"); \
  stringValue = dictionaryToXml(dictionary, NULL); \
  if (stringValue == NULL) { \
    printLog(ERR, "Expected empty string from dictionaryToXml.\n"); \
    printLog(ERR, "Got NULL.\n"); \
    return false; \
  } else if (strcmp(stringValue, "<></>") != 0) { \
    printLog(ERR, "Expected empty XML from dictionaryToXml.\n"); \
    printLog(ERR, "Got \"%s\".\n", stringValue); \
    return false; \
  } \
  stringValue = stringDestroy(stringValue); \
 \
  printLog(INFO, "Removing NULL key from empty dictionary.\n"); \
  dictionaryRemove(dictionary, NULL); \
 \
  printLog(INFO, "Getting NULL key from empty dictionary.\n"); \
  stringValue = (char*) dictionaryGetValue(dictionary, NULL); \
 \
  printLog(INFO, "Making list from empty dictionary.\n"); \
  dictList = dictionaryToList(dictionary); \
  if (dictList == NULL) { \
    printLog(ERR, "Expected empty list from dictionaryToList.\n"); \
    printLog(ERR, "Got NULL.\n"); \
    return false; \
  } else if (dictList->size != 0) { \
    stringValue = listToString(dictList); \
    printLog(ERR, "Expected empty list from dictionaryToList.\n"); \
    printLog(ERR, "Got \"%s\".\n", stringValue); \
    stringValue = stringDestroy(stringValue); \
    return false; \
  } \
  listDestroy(dictList); dictList = NULL; \
 \
  printLog(INFO, "Destroying empty dictionary.\n"); \
  dictionaryDestroy(dictionary); dictionary = NULL; \
 \
  dictionary = functionCallToDictionary("myfunc(param1=val1, param2=val2)"); \
  if (dictionary == NULL) { \
    printLog(ERR, "functionCallToDictionary resulted in NULL Dictionary.\n"); \
    return false; \
  } else if (strcmp((char*) dictionaryGetValue(dictionary, "@functionName"), \
    "myfunc") != 0 \
  ) { \
    printLog(ERR, "Expected @functionName to be \"myfunc\", found \"%s\".\n", \
      (char*) dictionaryGetEntry(dictionary, "@functionName")); \
    return false; \
  } else if (strcmp((char*) dictionaryGetValue(dictionary, "param1"), \
    "val1") != 0 \
  ) { \
    printLog(ERR, "Expected param1 to be \"val1\", found \"%s\".\n", \
      (char*) dictionaryGetEntry(dictionary, "param1")); \
    return false; \
  } else if (strcmp((char*) dictionaryGetValue(dictionary, "param2"), \
    "val2") != 0 \
  ) { \
    printLog(ERR, "Expected param2 to be \"val2\", found \"%s\".\n", \
      (char*) dictionaryGetEntry(dictionary, "param2")); \
    return false; \
  } \
  dictionary = dictionaryDestroy(dictionary); \
 \
  dictionary = functionCallToDictionary( \
    "myobj.myfunc( param1	 = 	val1   , \nparam2      =			val2    )"); \
  if (dictionary == NULL) { \
    printLog(ERR, "functionCallToDictionary resulted in NULL Dictionary.\n"); \
    return false; \
  } else if (strcmp((char*) dictionaryGetValue(dictionary, "@functionName"), \
    "myobj.myfunc") != 0 \
  ) { \
    printLog(ERR, "Expected @functionName to be \"myobj.myfunc\", found \"%s\".\n", \
      (char*) dictionaryGetEntry(dictionary, "@functionName")); \
    return false; \
  } else if (strcmp((char*) dictionaryGetValue(dictionary, "param1"), \
    "val1") != 0 \
  ) { \
    printLog(ERR, "Expected param1 to be \"val1\", found \"%s\".\n", \
      (char*) dictionaryGetEntry(dictionary, "param1")); \
    return false; \
  } else if (strcmp((char*) dictionaryGetValue(dictionary, "param2"), \
    "val2") != 0 \
  ) { \
    printLog(ERR, "Expected param2 to be \"val2\", found \"%s\".\n", \
      (char*) dictionaryGetEntry(dictionary, "param2")); \
    return false; \
  } \
  dictionary = dictionaryDestroy(dictionary); \
 \
  return true; \
}
DICTIONARY_UNIT_TEST

