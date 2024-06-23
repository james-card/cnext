///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              04.06.2019
///
/// @file              Stack.h
///
/// @brief             These are the functions and data structures that make
///                    up the stack data structure.
///
/// @details           This library is built on top of the list data
///                    structure.
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

#ifndef STACK_H
#define STACK_H

#include "StringLib.h"
#include "DataTypes.h"
#include "List.h"

#ifdef __cplusplus
extern "C"
{
#endif

Stack *stackCreate(TypeDescriptor *dataType);
StackNode *stackPushEntry_(Stack *stack,
  const volatile void *data, TypeDescriptor *type, ...);
#define stackPushEntry(stack, data, ...) stackPushEntry_(stack, data, ##__VA_ARGS__, NULL)
void *stackPop(Stack *stack);
Stack* stackDestroy(Stack *stack);
#define stackToString(stack) listToString((List*) stack)
int stackFlush(Stack *stack, int numItems);
#define stackFlushAll(stack) \
  stackFlush(stack, (stack != NULL) ? stack->size : 0)
#define stackToJson(stack) listToJson((List*) stack)
#define stackCompare(stackA, stackB) \
  listCompare((List*) stackA, (List*) stackB)
bool stackUnitTest();

#ifdef __cplusplus
} // extern "C"
#endif

#if (defined __cplusplus) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 201710L)

// This must come last and must come outside the extern "C" block.
#include "TypeSafeStackPush.h"

#endif // TypeSafeStackPush.h

#endif // STACK_H

