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

#include "Stack.h"
#include "LoggingLib.h"

bool stackUnitTest(void) {
  Stack *stack = NULL;
  StackNode *node = NULL;

  printLog(INFO, "Testing Stack data structure.\n");

  printLog(INFO, "Creating stack with NULL type descriptor.\n");
  stack = stackCreate(NULL);
  if (stack != NULL) {
    printLog(ERR, "Expected NULL stack, but got non-NULL stack.\n");
    return false;
  }

  printLog(INFO, "Pushing NULL onto NULL stack.\n");
  node = stackPushEntry(stack, NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from stackPushEntry, got %p.\n", node);
    return false;
  }

  printLog(INFO, "Popping NULL stack.\n");
  node = (StackNode*) stackPop(stack);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from stackPop, got %p.\n", node);
    return false;
  }

  printLog(INFO, "Destroying NULL stack.\n");
  stack = (Stack*) stackDestroy(stack);
  if (stack != NULL) {
    printLog(ERR, "Expected NULL stack, but got non-NULL stack.\n");
    return false;
  }

  printLog(INFO, "Creating empty stack.\n");
  stack = stackCreate(typeString);
  if (stack == NULL) {
    printLog(ERR, "Expected non-NULL stack, but got NULL stack.\n");
    return false;
  }

  printLog(INFO, "Pushing NULL onto empty stack.\n");
  node = stackPushEntry(stack, NULL);
  if (node == NULL) {
    printLog(ERR, "Expected non-NULL from stackPushEntry, got NULL.\n");
    return false;
  }
  stack = (Stack*) stackDestroy(stack);
  stack = stackCreate(typeString);

  printLog(INFO, "Popping empty stack.\n");
  node = (StackNode*) stackPop(stack);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from stackPop, got %p.\n", node);
    return false;
  }

  stackPushEntry(stack, "three");
  stackPushEntry(stack, "two");
  stackPushEntry(stack, "one");
  char *stackTop = (char*) stackPop(stack);
  if (stackTop == NULL) {
    printLog(ERR, "Expected \"one\" from stack.  Got NULL.\n");
    return false;
  }
  if (strcmp(stackTop, "one") != 0) {
    printLog(ERR, "Expected \"one\" from stack.  Got \"%s\".\n", stackTop);
    return false;
  }
  printLog(INFO, "Top of stack was \"one\".");
  stackTop = stringDestroy(stackTop);
  stackTop = (char*) stackPop(stack);
  if (stackTop == NULL) {
    printLog(ERR, "Expected \"two\" from stack.  Got NULL.\n");
    return false;
  }
  if (strcmp(stackTop, "two") != 0) {
    printLog(ERR, "Expected \"two\" from stack.  Got \"%s\".\n", stackTop);
    return false;
  }
  printLog(INFO, "Top of stack was \"two\".");
  stackTop = stringDestroy(stackTop);
  stackTop = (char*) stackPop(stack);
  if (stackTop == NULL) {
    printLog(ERR, "Expected \"three\" from stack.  Got NULL.\n");
    return false;
  }
  if (strcmp(stackTop, "three") != 0) {
    printLog(ERR, "Expected \"three\" from stack.  Got \"%s\".\n", stackTop);
    return false;
  }
  printLog(INFO, "Top of stack was \"three\".");
  stackTop = stringDestroy(stackTop);

  printLog(INFO, "Rebuilding three-item stack.\n");
  stackPushEntry(stack, "three");
  stackPushEntry(stack, "two");
  stackPushEntry(stack, "one");

  printLog(INFO, "Converting stack to byte array.\n");
  Bytes byteArray = typeStack->toBlob(stack);
  u64 length = bytesLength(byteArray);
  printLog(INFO, "Converting byte array to stack.\n");
  Stack *stack2 = (Stack*) typeStack->fromBlob(byteArray, &length, false, false);
  if (stackCompare(stack, stack2) != 0) {
    printLog(ERR, "stack and stack2 were not identical.\n");
    return false;
  }
  byteArray = bytesDestroy(byteArray);
  stack2 = stackDestroy(stack2);
  if (stack2 != NULL) {
    printLog(ERR, "Could not destroy stack2.\n");
    return false;
  }
 
  printLog(INFO, "Flushing entire stack.\n");
  stackFlushAll(stack);

  printLog(INFO, "Destroying empty stack.\n");
  stack = stackDestroy(stack);
  if (stack != NULL) {
    printLog(ERR, "Expected NULL stack, but got non-NULL stack.\n");
    return false;
  }

  return true;
}

