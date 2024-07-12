///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              04.12.2023
///
/// @file              DataStructuresExample.c
///
/// @brief             Examples of using data structures libraries.
///
/// @details
///
/// @copyright
///                   Copyright (c) 2012-2024 James Card
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

#include "List.h"
#include "HashTable.h"
#include "Scope.h"
#include "Queue.h"
#include "Stack.h"
#include "Vector.h"

#include <stdio.h>

int main(int argc, char **argv) {
  (void) argc;
  (void) argv;
  scopeBegin();

  List *myList = listCreate(typeString);
  if (myList == NULL) {
    fputs("ERROR:  Could not create myList!.\n", stderr);
    return 1;
  }
  
  scopeAdd(myList, listDestroy);
  unsigned char unsignedLetter = 'b';
  bool myBool = true;

  if (!listAddBack(myList, "key", "value")) {
    fprintf(stderr, "Could not add \"key\", \"value\" to myList.\n");
    myList = listDestroy(myList);
    return 1;
  }
  printf("Successfully added \"key\", \"value\" to myList.\n");
  
  if (!listAddBack(myList, "number", -32)) {
    fprintf(stderr, "Could not add \"number\", -32 to myList.\n");
    myList = listDestroy(myList);
    return 1;
  }
  printf("Successfully added \"number\", -32 to myList.\n");
  
  if (!listAddBack(myList, "letter", 'a')) {
    fprintf(stderr, "Could not add \"letter\", 'a' to myList.\n");
    myList = listDestroy(myList);
    return 1;
  }
  printf("Successfully added \"letter\", 'a' to myList.\n");
  
  if (!listAddBack(myList, "unsignedLetter", unsignedLetter)) {
    fprintf(stderr, "Could not add \"unsignedLetter\", 'b' to myList.\n");
    myList = listDestroy(myList);
    return 1;
  }
  printf("Successfully added \"unsignedLetter\", 'b' to myList.\n");
  
  if (!listAddBack(myList, "myBool", myBool)) {
    fprintf(stderr, "Could not add \"myBool\", myBool to myList.\n");
    myList = listDestroy(myList);
    return 1;
  }
  printf("Successfully added \"myBool\", myBool to myList.\n");
  
  printf("myList = %s\n", str(scopeAdd(listToString(myList))));
  
  HashTable *myHashTable = htCreate(typeString);
  scopeAdd(myHashTable, htDestroy);
  
  if (!htAdd(myHashTable, "key", "value")) {
    fprintf(stderr, "Could not add \"key\", \"value\" to myHashTable.\n");
    scopeEnd();
    return 1;
  }
  printf("Successfully added \"key\", \"value\" to myHashTable.\n");
  
  if (!htAdd(myHashTable, "number", -32)) {
    fprintf(stderr, "Could not add \"number\", -32 to myHashTable.\n");
    scopeEnd();
    return 1;
  }
  printf("Successfully added \"number\", -32 to myHashTable.\n");
  
  if (!htAdd(myHashTable, "letter", 'a')) {
    fprintf(stderr, "Could not add \"letter\", 'a' to myHashTable.\n");
    scopeEnd();
    return 1;
  }
  printf("Successfully added \"letter\", 'a' to myHashTable.\n");
  
  if (!htAdd(myHashTable, "unsignedLetter", unsignedLetter)) {
    fprintf(stderr, "Could not add \"unsignedLetter\", 'b' to myHashTable.\n");
    scopeEnd();
    return 1;
  }
  printf("Successfully added \"unsignedLetter\", 'b' to myHashTable.\n");
  
  if (!htAdd(myHashTable, "myBool", myBool)) {
    fprintf(stderr, "Could not add \"myBool\", myBool to myHashTable.\n");
    scopeEnd();
    return 1;
  }
  printf("Successfully added \"myBool\", myBool to myHashTable.\n");
  
  printf("myHashTable = %s\n", str(scopeAdd(htToString(myHashTable))));
  
  Queue *myQueue = queueCreate(typeString);
  scopeAdd(myQueue, queueDestroy);
  
  queuePush(myQueue, 45);
  queuePush(myQueue, 'a');
  queuePush(myQueue, unsignedLetter);
  queuePush(myQueue, myBool);
  queuePush(myQueue, "value");
  
  printf("myQueue = %s\n", str(scopeAdd(queueToString(myQueue))));
  
  Vector *myVector = vectorCreate(typePointer);
  scopeAdd(myVector, vectorDestroy);
  
  vectorSet(myVector, 0, 45);
  vectorSet(myVector, 1, 'a');
  vectorSet(myVector, 2, unsignedLetter);
  vectorSet(myVector, 3, myBool);
  vectorSet(myVector, 4, "value");
  
  printf("myVector = %s\n", str(scopeAdd(vectorToString(myVector))));
  
  scopeEnd();
  return 0;
}

