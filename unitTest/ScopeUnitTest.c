////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                     Copyright (c) 2012-2025 James Card                     //
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

#include "Scope.h"
#include "LoggingLib.h"
#include <stdlib.h>
#include "StringLib.h"

bool scopeUnitTest() {
  bool returnValue = true;
  
  SCOPE_ENTER("");
  
  // Test adding and removing.
  char *myString = (char*) scopeAdd(malloc(20), pointerDestroyFunction);
  if (myString == NULL) {
    printLog(ERR, "myString was NULL after scopeAdd().\n");
    returnValue = false;
    SCOPE_EXIT("", "%s", (returnValue == true) ? "true" : "false");
    return returnValue;
  }
  
  // Make sure the pointer's valid.  If it's not, we should segfault here.
  strcpy(myString, "Hello, world!");
  if (strcmp(myString, "Hello, world!") != 0) {
    printLog(ERR, "Expected myString to be \"Hello, world!\", got \"%s\".\n",
      myString);
    returnValue = false;
    SCOPE_EXIT("", "%s", (returnValue == true) ? "true" : "false");
    return returnValue;
  }
  
  if (scopeDestroy(myString) != NULL) {
    printLog(ERR, "scopeDestroy(myString) returned non-NULL.\n");
    returnValue = false;
    SCOPE_EXIT("", "%s", (returnValue == true) ? "true" : "false");
    return returnValue;
  }
  
  // Test adding and popping.
  myString = (char*) scopeAdd(malloc(20));
  if (myString == NULL) {
    printLog(ERR, "myString was NULL after scopeAdd().\n");
    returnValue = false;
    SCOPE_EXIT("", "%s", (returnValue == true) ? "true" : "false");
    return returnValue;
  }
  
  scopePopAll();
  if (_scope_.numVars != 0) {
    printLog(ERR, "Expected _scope_.numVars == 0, found %llu.\n",
      llu(_scope_.numVars));
    printLog(ERR, "Expected _scope_.numVars == 0, found %llu.\n",
      llu(_scope_.numVars));
    returnValue = false;
    SCOPE_EXIT("", "%s", (returnValue == true) ? "true" : "false");
    return returnValue;
  }
  
  // Test adding and replacing.
  myString = (char*) scopeAdd(malloc(20));
  if (myString == NULL) {
    printLog(ERR, "myString was NULL after scopeAdd().\n");
    returnValue = false;
    SCOPE_EXIT("", "%s", (returnValue == true) ? "true" : "false");
    return returnValue;
  }
  *myString = '\0'; // For the straddstr to work correctly.
  
  scopeUpdate(myString, straddstr(&myString, "Hello, world!"));
  if (strcmp(myString, "Hello, world!") != 0) {
    printLog(ERR, "Expected myString to be \"Hello, world!\", got \"%s\".\n",
      myString);
    returnValue = false;
    SCOPE_EXIT("", "%s", (returnValue == true) ? "true" : "false");
    return returnValue;
  }
  
  free(myString); // NEVER use free in real life!!!
  scopeUpdate(myString, malloc(20));
  // If the above failed then the below should segfault.
  strcpy(myString, "Goodbye, world!");
  if (strcmp(myString, "Goodbye, world!") != 0) {
    printLog(ERR, "Expected myString to be \"Goodbye, world!\", got \"%s\".\n",
      myString);
    returnValue = false;
    SCOPE_EXIT("", "%s", (returnValue == true) ? "true" : "false");
    return returnValue;
  }
  
  char *myString2 = (char*) scopeAdd(malloc(20), free);
  scopeRemove(myString2);
  myString2 = stringDestroy(myString2);
  
  SCOPE_EXIT("", "%s", (returnValue == true) ? "true" : "false");
  
  return returnValue;
}

