////////////////////////////////////////////////////////////////////////////////
///
/// @author            James B. Card
/// @date              08.09.2022
///
/// @file              Scope.h
///
/// @brief             This library implements the Scope object that keeps track
///                    of and properly deallocates objects allocated on the heap
///                    that are intended to be temporary.
///
/// @copyright
///       (c) Copyright 2012-2022 James B. Card  All Rights Reserved.
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
///                              James B. Card
///                         http://www.jamescard.org
///
////////////////////////////////////////////////////////////////////////////////

#ifndef SCOPE_H
#define SCOPE_H

#include "TypeDefinitions.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef MAX_SCOPE_VARS
#define MAX_SCOPE_VARS 512 // The minimum maximum number of variables per block.
#endif

typedef struct VariableAndDestructor {
  volatile void* variable;
  Destructor     destructor;
} VariableAndDestructor;

typedef struct Scope {
  u64            numVars;
  u64            maxVars;
  VariableAndDestructor variablesAndDestructors[MAX_SCOPE_VARS];
} Scope;

#define scopeBegin() \
  Scope _scope_; \
  _scope_.numVars = 0; \
  _scope_.maxVars = MAX_SCOPE_VARS; \

void* scopeAdd_(Scope *scope, volatile void *pointer, ...);
#define scopeAdd(pointer, ...) \
  scopeAdd_(&_scope_, (pointer), ##__VA_ARGS__, free)
void scopePop_(Scope *scope, u64 numEntries);
#define scopePop(numEntries) \
  scopePop_(&_scope_, (numEntries))
#define scopePopAll() \
  scopePop_(&_scope_, _scope_.numVars)
void* scopeDestroy_(Scope *scope, volatile void *pointer);
#define scopeDestroy(pointer) \
  scopeDestroy_(&_scope_, pointer)
void* scopeUpdate_(Scope *scope, volatile void *oldPointer, volatile void *newPointer);
#define scopeUpdate(oldPointer, newPointer) \
  { \
    void *_tmpOldPointer_ = (oldPointer); \
    void *_tmpNewPointer_ = (newPointer); \
    void *temp = scopeUpdate_(&_scope_, _tmpOldPointer_, _tmpNewPointer_); \
    void **variableAddress = (void**) &(oldPointer); \
    *variableAddress = temp; \
  }
#define scopeRemove(oldPointer) \
  scopeUpdate_(&_scope_, (oldPointer), NULL)

#define SCOPE_ENTER(argFormat, ...) \
  printLog(TRACE, "ENTER %s(" argFormat ")", __func__, ##__VA_ARGS__); \
  scopeBegin();
#define SCOPE_EXIT(argFormat, returnFormat, ...) \
  printLog(TRACE, "EXIT %s(" argFormat ") = {" returnFormat "}", __func__, ##__VA_ARGS__); \
  scopeEnd_(&_scope_);

int scopeEnd_(Scope *scope);
#define scopeEnd() \
  ((_scope_.numVars > 0) ? scopeEnd_(&_scope_) : TRINARY_ZERO)

bool scopeUnitTest();

#ifdef __cplusplus
} // extern "C"
#endif

#endif // SCOPE_H

