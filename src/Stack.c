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
#ifdef DS_LOGGING_ENABLED
#include "LoggingLib.h"
#else
#undef printLog
#define printLog(...) {}
#define logFile stderr
#endif

/// @fn Stack *stackCreate(TypeDescriptor *dataType)
///
/// @brief Create and initialize a newly-allocated Stack.
///
/// @param dataType TypeDescriptor describing the type of data in the Stack.
///
/// @return Returns a pointer to a newly-allocated and initialized Stack.
///
/// @note This implementation uses List as the underlying infrastructure.
Stack *stackCreate(TypeDescriptor *dataType) {
  printLog(TRACE, "ENTER stackCreate(dataType=%s)\n", (dataType == NULL) ? "NULL" : dataType->name);
  
  Stack *stack = (Stack*) listCreate(dataType);
  
  printLog(TRACE, "EXIT stackCreate(dataType=%s) = {%p}\n", (dataType == NULL) ? "NULL" : dataType->name, stack);
  return stack;
}

/// @fn StackNode *stackPushEntry_(Stack *stack, const volatile void *data, TypeDescriptor *type, ...)
///
/// @brief Push new data onto the top of the stack.
///
/// @param stack The Stack to push data onto.
/// @param data The data to push onto the stack.
/// @param type The TypeDescriptor for the data.  This parameter is optional.
/// @param ... All further arguments are ignored.
///
/// @note This function is wrapped by a #define (without the leading underscore)
/// that automatically appends a null when the stack and data are provided and
/// provides a type if it is provided.
///
/// @return Returns a pointer to the newly-allocated node on the top of the
///   Stack.
StackNode *stackPushEntry_(Stack *stack, const volatile void *data,
  TypeDescriptor *type, ...
) {
  printLog(TRACE, "ENTER stackPushEntry(stack=%p, data=%p)\n", stack, data);
  
  StackNode *returnValue
    = (StackNode*) listAddFrontEntry((List*) stack, NULL, data, type);
  
  printLog(TRACE, "EXIT stackPushEntry(stack=%p, data=%p) = {%p}\n",
    stack, data, returnValue);
  return returnValue;
}

/// @fn void *stackPop(Stack *stack)
///
/// @brief Return a copy of the data on the top of the stack and remove it
///   from the Stack.
///
/// @param stack The Stack to pop from.
///
/// @return Returns a pointer to a copy of the data that was on the top of the
///   Stack.
void *stackPop(Stack *stack) {
  printLog(TRACE, "ENTER stackPop(stack=%p)\n", stack);
  
  void *returnValue = NULL;
  
  if (stack == NULL) {
    // Can't pop a NULL stack.
    printLog(TRACE, "EXIT stackPop(queue=%p) = {%p}\n", stack, returnValue);
    return returnValue;
  }
  
  mtx_lock(stack->lock);
  
  ListNode *node = listGetFront((List*) stack);
  if (node != NULL) {
    returnValue = (void*) node->value;
    node->value = NULL;
  }
  listRemoveFront((List*) stack);
  
  mtx_unlock(stack->lock);
  
  printLog(TRACE, "EXIT stackPop(stack=%p) = {%p}\n", stack, returnValue);
  return returnValue;
}

/// @fn Stack* stackDestroy(Stack *stack)
///
/// @brief Deallocate a Stack and all supporting data and metadata.
///
/// @param stack is the Stack to deallocate.
///
/// @return Returns a NULL pointer.
Stack* stackDestroy(Stack *stack) {
  printLog(TRACE, "ENTER stackDestroy(stack=%p)\n", stack);
  
  Stack *returnValue = (Stack*) listDestroy((List*) stack);
  
  printLog(TRACE, "EXIT stackDestroy(stack=%p) = {%p}\n", stack, returnValue);
  return returnValue;
}

/// @fn int stackFlush(Queue *stack, int numItems)
///
/// @brief Remove items from the stack and discard them.
///
/// @param stack The Queue to flush.
/// @param numItems The number of items to flush from the stack.
///
/// @return Returns 0 on success, -1 on failure.
int stackFlush(Stack *stack, int numItems) {
  printLog(TRACE, "ENTER stackFlush(stack=%p, numItems=%u)\n", stack, numItems);
  
  for (int i = 0; i < numItems; i++) {
    listRemoveFront((List*) stack);
  }
  
  printLog(TRACE, "EXIT stackFlush(stack=%p, numItems=%u) = {%p}\n",
    stack, numItems, (void*) NULL);
  return 0;
}

/// @var typeStack
///
/// @brief TypeDescriptor describing how libraries should interact with
///   stack data.
TypeDescriptor _typeStack = {
  .name          = "Stack",
  .xmlName       = NULL,
  .dataIsPointer = true,
  .toString      = (char* (*)(const volatile void*)) listToString,
  .toBytes       = (Bytes (*)(const volatile void*)) listToBytes,
  .compare       = (int (*)(const volatile void*, const volatile void*)) listCompare,
  .create        = (void* (*)(const volatile void*, ...)) stackCreate,
  .copy          = (void* (*)(const volatile void*)) listCopy,
  .destroy       = (void* (*)(volatile void*)) stackDestroy,
  .size          = listSize,
  .toBlob        = (Bytes (*)(const volatile void*)) listToBlob,
  .fromBlob      = (void* (*)(const volatile void*, u64*, bool, bool)) listFromBlob_,
  .hashFunction  = NULL,
  .clear         = (i32 (*)(volatile void *)) listClear,
  .toXml         = (Bytes (*)(const volatile void*, const char *elementName, bool indent, ...)) listToXml_,
  .toJson        = (Bytes (*)(const volatile void*)) listToJson,
};
TypeDescriptor *typeStack = &_typeStack;

/// @var typeStackNoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with
///   stack data that is not copied from its original source.
///
/// @details This exists because, by default, a copy of the input data is made
///   whenever a new data element is added to any data structure.  In some
///   situations, this is not desirable because the input serves no purpose
///   other than to be added to the data structure.  In such cases, this data
///   type may be specified to avoid the unnecessary copy.  The real
///   typeStack type can then be set after the data is added.
TypeDescriptor _typeStackNoCopy = {
  .name          = "Stack",
  .xmlName       = NULL,
  .dataIsPointer = true,
  .toString      = (char* (*)(const volatile void*)) listToString,
  .toBytes       = (Bytes (*)(const volatile void*)) listToBytes,
  .compare       = (int (*)(const volatile void*, const volatile void*)) listCompare,
  .create        = (void* (*)(const volatile void*, ...)) stackCreate,
  .copy          = (void* (*)(const volatile void*)) shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = listSize,
  .toBlob        = (Bytes (*)(const volatile void*)) listToBlob,
  .fromBlob      = (void* (*)(const volatile void*, u64*, bool, bool)) listFromBlob_,
  .hashFunction  = NULL,
  .clear         = (i32 (*)(volatile void *)) listClear,
  .toXml         = (Bytes (*)(const volatile void*, const char *elementName, bool indent, ...)) listToXml_,
  .toJson        = (Bytes (*)(const volatile void*)) listToJson,
};
TypeDescriptor *typeStackNoCopy = &_typeStackNoCopy;

