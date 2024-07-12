///////////////////////////////////////////////////////////////////////////////
///
/// @author            Emin Martinian
/// @author            James Card
/// @date              04.06.2019
///
/// @file              RedBlackTree.h
///
/// @brief             These are the functions and data structures that make
///                    up the red black tree data structure.
///
/// @details           This library has dependencies on other data
///                    structures for export purposes.  Specifically, this
///                    library is aware of lists and hash tables.
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

#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

// ORIGINAL LICENSE:
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that neither the name of Emin
// Martinian nor the names of any contributors are be used to endorse or
// promote products derived from this software without specific prior
// written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// CHANGES:
// Sat Feb 09, 2019: James combined all related material into single library
//                   and cleaned up formatting of the code to bring into
//                   compliance with other code in this repository.  Also
//                   fixed a bug in comparison tests that were explicitly
//                   checking for a return value of 1 instead of > 0.  This
//                   allows for the standard strcmp to be used as a comparison
//                   function.
//
// Sun Jan 09, 2005: Emin fixed a bug that caused the test_rb program to
//                   go into an infinite loop if the user entered an
//                   invalid key.  Thanks to Amores Perros for pointing
//                   out this problem.
// 
// Wed Sep 19, 2001: Emin some bugs and memory leaks pointed out
//                   by Brett Donahue and added some rudimentary
//                   memory checking tests to the makefile.
// 
// CONVENTIONS:
//                Function names: Each word in a function name begins with
//                a capital letter EXCEPT the first letter of the function.
//                An example funcntion name is rbTreeCreate(a, b, c).
//                Red-black tree function names begin with "rb".
//
//                Type names: Each word in a type name begins with a capital
//                letter.  Names of complex types (structures or unions) begin
//                with a capital letter.  Names of primitive types begin with
//                a lower-case letter.
//
//                Variable names: Each word in a variable name begins with
//                a capital letter EXCEPT the first letter of the variable
//                name.  For example, int newLongInt.  Global variables have
//                names beginning with "g".  An example of a global
//                variable name is gNewtonsConstant.

#include <stdio.h>
#include <stdlib.h>

#ifdef DMALLOC
#include <dmalloc.h>
#endif

#include "DataTypes.h"
#include "List.h"

#ifdef __cplusplus
extern "C"
{
#endif

// This code has been thoroughly tested.  Length of paths from root to leaves 
// is bound by 2 * lg(n) and asserts in the code have been verified many times.
// There is no longer any reason to have this in place, but leaving in case
// that changes in the future.
// JBC 2019-02-16
// #define DEBUG_ASSERT 1


RedBlackTree *rbTreeCreate_(TypeDescriptor *keyType, bool disableThreadSafety, ...);
#define rbTreeCreate(keyType, ...) rbTreeCreate_(keyType, ##__VA_ARGS__, 0)
RedBlackNode *rbInsert_(RedBlackTree *tree, const volatile void *key,
  const volatile void *value, TypeDescriptor *type, ...);
#define rbInsert(tree, key, value, ...) \
  rbInsert_(tree, key, value, ##__VA_ARGS__, NULL)
extern RedBlackNode* (*rbTreeAddEntry_)(RedBlackTree *tree,
  const volatile void *key, const volatile void *value, TypeDescriptor *type, ...);
#define rbTreeAddEntry(tree, key, value, ...) \
  rbTreeAddEntry_(tree, key, value, ##__VA_ARGS__, NULL)
RedBlackNode *rbQuery(const RedBlackTree *tree, const volatile void *key);
#define rbTreeGetEntry rbQuery
void *rbTreeGetValue(const RedBlackTree *tree, const volatile void *key);
int rbTreeRemove(RedBlackTree *tree, const volatile void *key);
int rbTreeDestroyNode(RedBlackTree*, RedBlackNode*);
RedBlackTree *rbTreeDestroy(RedBlackTree*);
RedBlackNode *rbTreePredecessor(RedBlackTree*, RedBlackNode*);
RedBlackNode *rbTreeSuccessor(RedBlackTree*, RedBlackNode*);
RedBlackNode *rbTreeFirst(RedBlackTree*);
RedBlackNode *rbTreeLast(RedBlackTree *tree);
List *rbEnumerate(const RedBlackTree *tree,
  const volatile void *low, const volatile void *high);
void rbAssert(bool assertion, const char *error);
void *rbSafeMalloc(size_t size);
#define rbTreeToXml(tree, elementName) \
  listToXml((List*) tree, elementName)
#define rbTreeToList(tree) listCopy((List*) tree)
#define rbTreeToString(tree) listToString((List*) tree)
int rbTreeCompare(const RedBlackTree *treeA, const RedBlackTree *treeB);
RedBlackTree *rbTreeCopy(const RedBlackTree *tree);
RedBlackTree* listToRbTree(const List *list);
#define rbTreeToBlob(tree) listToBlob((List*) tree)
#define rbTreeToJson(tree) listToJson((List*) tree)
RedBlackTree* jsonToRedBlackTree(const char *jsonText, long long int *position);
RedBlackTree *xmlToRedBlackTree(const char *inputData);
i32 rbTreeClear(RedBlackTree *tree);
RedBlackTree *rbTreeFromBlob_(const volatile void *array, u64 *length, bool inPlaceData, bool disableThreadSafety, ...);
#define rbTreeFromBlob(array, length, ...) \
  rbTreeFromBlob_(array, length, ##__VA_ARGS__, 0, 0)
bool redBlackTreeUnitTest();

#ifdef __cplusplus
} // extern "C"
#endif

#if (defined __cplusplus) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 201710L)

// This must come last and must come outside the extern "C" block.
#include "TypeSafeRbTreeAdd.h"

#endif // TypeSafeRbTreeAdd.h

#endif // RED_BLACK_TREE_H

