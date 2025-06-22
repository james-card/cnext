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

#include "RedBlackTree.h"
#include "StringLib.h"
#include "HashTable.h"
#include "Vector.h" // For JSON

#ifdef DS_LOGGING_ENABLED
#include "LoggingLib.h"
#else
#undef printLog
#define printLog(...) {}
#define logFile stderr
#define LOG_MALLOC_FAILURE(...) {}
#define TRACE 2
#define logThreshold 11 // NONE
#endif

/// @fn RedBlackTree *rbTreeCreate_(TypeDescriptor *keyType, bool disableThreadSafety, ...)
///
/// @brief Allocates a new RedBlackTree and associated metadata.
///
/// @param keyType is the TypeDescriptor to use for the keys in the tree.
/// @param disableThreadSafety Whether or not to disable thread safety for the
///   RedBlackTree.
///
/// @note This function is wrapped by a macro of the same name (minus the
/// trailing underscore) that automatically provides false for the
/// dsiableThreadSafety parameter.
///
/// @return Returns a pointer to a newly-created RedBlackTree.
RedBlackTree *rbTreeCreate_(TypeDescriptor *keyType, bool disableThreadSafety, ...) {
  printLog(TRACE, "ENTER rbTreeCreate(keyType=%s)\n",
    (keyType != NULL) ? keyType->name : "NULL");
  
  if (keyType == NULL) {
    printLog(ERR, "keyType provided is NULL.\n");
    printLog(TRACE, "EXIT rbTreeCreate(keyType=NULL) = {%p}\n", (void*) NULL);
    return NULL;
  }
  
  RedBlackTree *newTree = NULL;
  RedBlackNode *temp = NULL;
  
  newTree = (RedBlackTree*) calloc(1, sizeof(RedBlackTree));
  if (newTree == NULL) {
    LOG_MALLOC_FAILURE();
    return NULL;
  }
  // No need to NULL-ify member varialbes since we used calloc.
  newTree->keyType = keyType;
  if (disableThreadSafety == false) {
    // The lock mtx_t member variable has to be zeroed, so use calloc here.
    newTree->lock = (mtx_t*) calloc(1, sizeof(mtx_t));
    if (mtx_init(newTree->lock, mtx_plain | mtx_recursive) != thrd_success) {
      printLog(ERR, "Could not initialize red black tree mutex lock.\n");
    }
  }
  
  // See the comment in the RedBlackTree structure in RedBlackTree.h
  // for information on nil and root.
  temp = newTree->nil = (RedBlackNode*) rbSafeMalloc(sizeof(RedBlackNode));
  temp->parent = temp->left = temp->right = temp;
  temp->type = NULL;
  temp->red  = false;
  temp->key  = NULL;
  temp = newTree->root =
    (RedBlackNode*) rbSafeMalloc(sizeof(RedBlackNode));
  temp->parent = temp->left = temp->right = newTree->nil;
  temp->type = NULL;
  temp->key  = NULL;
  temp->red  = false;
  
  printLog(TRACE, "EXIT rbTreeCreate(keyType=%s) = {%p}\n", keyType->name, newTree);
  return newTree;
}

/// @fn static void leftRotate(RedBlackTree *tree, RedBlackNode *x)
///
/// @brief Rotates as described in _Introduction_To_Algorithms_ by
///   Cormen, Leiserson, Rivest (Chapter 14).
///
/// @details
/// Basically this makes the parent of x be to the left of x, x the parent of
/// its parent before the rotation and fixes other pointers accordingly.
///
/// @param tree is a pointer to the RedBlackTree to modify.
/// @param x is a pointer to the node to rotate.
///
/// @note The tree pointer is used so that this function can access the
///   appropriate root and nil pointers.
///
/// @return This function returns no value.
void leftRotate(RedBlackTree *tree, RedBlackNode *x) {
  printLog(TRACE, "ENTER leftRotate(tree=%p, x=%p) = {}\n", tree, x);
  
  RedBlackNode *y = NULL;
  RedBlackNode *nil = tree->nil;
  
  // The author originally wrote this function to use the sentinel for
  // nil to avoid checking for nil.  However this introduces a
  // very subtle bug because sometimes this function modifies
  // the parent pointer of nil.  This can be a problem if a
  // function which calls leftRotate also uses the nil sentinel
  // and expects the nil sentinel's parent pointer to be unchanged
  // after calling this function.  For example, when rbTreeDestroyNodeFixUp
  // calls leftRotate it expects the parent pointer of nil to be
  // unchanged.
  
  y = x->right;
  x->right = y->left;

  if (y->left != nil) {
    y->left->parent = x; // Formerly used a sentinel here
    // and did an unconditional assignment instead of testing for nil.
  }
  
  y->parent = x->parent;   

  // Instead of checking if x->parent is the root as in the book, we
  // count on the root sentinel to implicitly take care of this case.
  if (x == x->parent->left) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }
  y->left = x;
  x->parent = y;

#ifdef DEBUG_ASSERT
  rbAssert((tree->nil->red == false), "nil not black in leftRotate");
#endif
  printLog(TRACE, "EXIT leftRotate(tree=%p, x=%p) = {}\n", tree, x);
}

/// @fn static void rightRotate(RedBlackTree *tree, RedBlackNode *y)
///
/// @brief Rotates as described in _Introduction_To_Algorithms_ by
///   Cormen, Leiserson, Rivest (Chapter 14).
///
/// @details
/// Basically this makes the parent of x be to the left of x, x the parent of
/// its parent before the rotation and fixes other pointers accordingly.
///
/// @param tree is a pointer to the RedBlackTree to modify.
/// @param y is a pointer to the node to rotate.
///
/// @note The tree pointer is used so that this function can access the
///   appropriate root and nil pointers.
///
/// @return This function returns no value.
void rightRotate(RedBlackTree *tree, RedBlackNode *y) {
  printLog(TRACE, "ENTER rightRotate(tree=%p, y=%p)\n", tree, y);
  
  RedBlackNode *x = NULL;
  RedBlackNode *nil = tree->nil;

  // The author originally wrote this function to use the sentinel for
  // nil to avoid checking for nil.  However this introduces a
  // very subtle bug because sometimes this function modifies
  // the parent pointer of nil.  This can be a problem if a
  // function which calls rightRotate also uses the nil sentinel
  // and expects the nil sentinel's parent pointer to be unchanged
  // after calling this function.  For example, when rbTreeDestroyNodeFixUp
  // calls rightRotate it expects the parent pointer of nil to be
  // unchanged.

  x = y->left;
  y->left = x->right;

  if (nil != x->right) {
    x->right->parent = y; // Formerly used a sentinel here
    // and did an unconditional assignment instead of testing for nil.
  }

  // Instead of checking if x->parent is the root as in the book, we
  // count on the root sentinel to implicitly take care of this case.
  x->parent = y->parent;
  if (y == y->parent->left) {
    y->parent->left = x;
  } else {
    y->parent->right = x;
  }
  x->right = y;
  y->parent = x;

#ifdef DEBUG_ASSERT
  rbAssert((tree->nil->red == false), "nil not black in rightRotate");
#endif
  printLog(TRACE, "EXIT rightRotate(tree=%p, y=%p) = {}\n", tree, y);
}

/// @fn static void treeInsertHelp(RedBlackTree *tree, RedBlackNode *z)
///
/// @brief Inserts a RedBlackNode into a tree as if it were a regular binary
///   search tree.
///
/// @details
/// Uses the algorithm described in _Introduction_To_Algorithms_ by
///   Cormen et al.
///
/// @note This funciton is only intended to be called by the rbTreeAddEntry function
///   and not by the user.
///
/// @param tree is a pointer to the RedBlackTree to insert into.
/// @param z is a pointer to the RedBlackNode to insert into the tree.
///
/// @return This function returns no value.
///
/// @note Before calling treeInsertHelp, the node z should have its key set.
void treeInsertHelp(RedBlackTree *tree, RedBlackNode *z) {
  printLog(TRACE, "ENTER treeInsertHelp(tree=%p, z=%p)\n", tree, z);
  
  // This function should only be called by rbTreeAddEntry (see above)
  RedBlackNode *x = NULL;
  RedBlackNode *y = NULL;
  RedBlackNode *nil = tree->nil;
  
  z->left = z->right = nil;
  y = tree->root;
  x = tree->root->left;
  while (x != nil) {
    y = x;
    if (tree->keyType->compare(x->key, z->key) > 0) { // x->key > z->key
      x = x->left;
    } else { // x->key <= z->key
      x = x->right;
    }
  }
  z->parent = y;
  if ((y == tree->root) ||
       (tree->keyType->compare(y->key, z->key) > 0)) { // y->key > z->key
    y->left = z;
  } else { // y->key <= z->key
    y->right = z;
  }

#ifdef DEBUG_ASSERT
  rbAssert((tree->nil->red == false), "nil not black in treeInsertHelp");
#endif
  printLog(TRACE, "EXIT treeInsertHelp(tree=%p, z=%p)\n", tree, z);
}

/// @fn RedBlackNode *rbTreeAddEntry_(RedBlackTree *tree, const volatile void *key, const volatile void *value, TypeDescriptor *type, ...)
///
/// @brief Insert a new key/value pair into a RedBlackTree.
///
/// @details Creates a node node which contains the appropriate key and
///   value pointers and inserts it into the tree.
///
/// @param tree is a pointer ot the RedBlackTree to insert the key/value pair
///   into.
/// @param key is the key of the key/value pair to use for insertion.
/// @param value is the value of the key/value pair to use for insertion.
/// @param type is the TypeDescriptor that describes the value provided.
///
/// @note This function is wrapped by a define of the same name, minus the
/// leading underscore.  The type parameter is optional when the define is
/// used.
///
/// @return This function returns a pointer to the newly inserted node
///   which is guarunteed to be valid until this node is deleted.
///   What this means is if another data structure stores this
///   pointer then the tree does not need to be searched when this
///   is to be deleted.
RedBlackNode *rbTreeAddEntry_(RedBlackTree *tree, const volatile void *key,
  const volatile void *value, TypeDescriptor *type, ...
) {
  printLog(TRACE, "ENTER rbTreeAddEntry(tree=%p, key=%p, value=%p, type=%s)\n",
    tree, key, value, (type != NULL) ? type->name : "NULL");
  RedBlackNode *x = NULL;
  RedBlackNode *y = NULL;
  RedBlackNode *newNode = NULL, *neighbor = NULL;
  RedBlackNode *nil = NULL;

  // Sanity check the parameters
  if (tree == NULL) {
    printLog(ERR, "NULL tree provided.\n");
    printLog(TRACE,
      "EXIT rbTreeAddEntry(tree=%p, key=%p, value=%p, type=%s) = {%p}\n",
      tree, key, value, (type != NULL) ? type->name : "NULL", (void*) NULL);
    return NULL;
  }
  if (key == NULL) {
    printLog(ERR, "NULL key provided.\n");
    printLog(TRACE,
      "EXIT rbTreeAddEntry(tree=%p, key=%p, value=%p, type=%s) = {%p}\n",
      tree, key, value, (type != NULL) ? type->name : "NULL", (void*) NULL);
    return NULL;
  }
  
  if ((tree->lock != NULL) && (mtx_lock(tree->lock) != thrd_success)) {
    printLog(WARN, "Could not lock red black tree mutex.\n");
  }
  
  if (type == NULL) {
    if (tree->lastAddedType != NULL) {
      type = tree->lastAddedType;
      printLog(DEBUG, "Defaulting to type of last added element.\n");
    } else {
      type = tree->keyType;
      printLog(DEBUG, "Defaulting to type of key.\n");
    }
  }
  
  nil = tree->nil;
  x = (RedBlackNode*) rbSafeMalloc(sizeof(RedBlackNode));
  x->key = tree->keyType->copy(key);
  x->value = type->copy(value);
  x->type = type;
  x->byteOffset = 0;
  x->left = nil;
  x->right = nil;

  treeInsertHelp(tree, x);
  newNode = x;
  x->red = true;
  while (x->parent->red == true) { // use sentinel instead of checking for root
    if (x->parent == x->parent->parent->left) {
      y = x->parent->parent->right;
      if (y->red == true) {
        x->parent->red = false;
        y->red = false;
        x->parent->parent->red = true;
        x = x->parent->parent;
      } else {
        if (x == x->parent->right) {
          x = x->parent;
          leftRotate(tree, x);
        }
        x->parent->red = false;
        x->parent->parent->red = true;
        rightRotate(tree, x->parent->parent);
      } 
    } else { // case for x->parent == x->parent->parent->right
      y = x->parent->parent->left;
      if (y->red == true) {
        x->parent->red = false;
        y->red = false;
        x->parent->parent->red = true;
        x = x->parent->parent;
      } else {
        if (x == x->parent->left) {
          x = x->parent;
          rightRotate(tree, x);
        }
        x->parent->red = false;
        x->parent->parent->red = true;
        leftRotate(tree, x->parent->parent);
      } 
    }
  }
  tree->root->left->red = false;
  tree->size++;

  neighbor = rbTreePredecessor(tree, newNode);
  if (neighbor == nil) {
    neighbor = NULL;
  }
  if (neighbor != NULL) {
    neighbor->next = newNode;
  }
  newNode->prev = neighbor;
  neighbor = rbTreeSuccessor(tree, newNode);
  if (neighbor == nil) {
    neighbor = NULL;
  }
  if (neighbor != NULL) {
    neighbor->prev = newNode;
  }
  newNode->next = neighbor;
  
  if (newNode->prev == NULL) {
    // First node in the tree
    tree->head = newNode;
  }
  if (newNode->next == NULL) {
    // Last node in the tree
    tree->tail = newNode;
  }
  
  // If we made it this far then the add was successful.  Record the type for
  // future use if desired.
  tree->lastAddedType = type;
  
  if (tree->lock != NULL) {
    mtx_unlock(tree->lock);
  }
  
#ifdef DEBUG_ASSERT
  rbAssert((tree->nil->red == false), "nil not black in rbTreeAddEntry");
  rbAssert((tree->root->red == false), "root not black in rbTreeAddEntry");
#endif
  
  printLog(TRACE, "EXIT rbTreeAddEntry(tree=%p, key=%p, value=%p, type=%s) = {%p}\n",
    tree, key, value, type->name, newNode);
  return newNode;
}

/// @fn RedBlackNode *rbTreeSuccessor(RedBlackTree *tree, RedBlackNode *x)
///
/// @brief find the successor of a RedBlackNode in a tree.
///
/// @param tree is a pointer to the RedBlackTree to search.
/// @param x is a pointer to the node to find the successor of.
///
/// @return This function returns the successor of x or NULL if no
///   successor exists.
///
/// @note Uses the algorithm in _Introduction_To_Algorithms_.
RedBlackNode *rbTreeSuccessor(RedBlackTree *tree, RedBlackNode *x) {
  printLog(TRACE, "ENTER rbTreeSuccessor(tree=%p, x=%p)\n", tree, x);
  
  // Parameter check.
  if (tree == NULL) {
    printLog(ERR, "tree is NULL.\n");
    printLog(TRACE, "EXIT rbTreeSuccessor(tree=%p, x=%p) = {%p}\n",
      tree, x, (void*) NULL);
    return NULL;
  }
  if (x == NULL) {
    printLog(ERR, "x is NULL.\n");
    printLog(TRACE, "EXIT rbTreeSuccessor(tree=%p, x=%p) = {%p}\n",
      tree, x, (void*) NULL);
    return NULL;
  }
  
  if ((tree->lock != NULL) && (mtx_lock(tree->lock) != thrd_success)) {
    printLog(WARN, "Could not lock red black tree mutex.\n");
  }
  
  RedBlackNode *y = NULL;
  RedBlackNode *nil = tree->nil;
  RedBlackNode *root = tree->root;
  
  if (nil != (y = x->right)) { // assignment to y is intentional
    while (y->left != nil) { // returns the minium of the right subtree of x
      y = y->left;
    }
    
    if (tree->lock != NULL) {
      mtx_unlock(tree->lock);
    }
    
    printLog(TRACE, "EXIT rbTreeSuccessor(tree=%p, x=%p) = {%p}\n", tree, x, y);
    return y;
  } else {
    y = x->parent;
    while (x == y->right) { // sentinel used instead of checking for nil
      x = y;
      y = y->parent;
    }
    
    if (tree->lock != NULL) {
      mtx_unlock(tree->lock);
    }
    
    if (y == root) {
      printLog(TRACE, "EXIT rbTreeSuccessor(tree=%p, x=%p) = {NULL}\n", tree, x);
      return NULL;
    }
    
    printLog(TRACE, "EXIT rbTreeSuccessor(tree=%p, x=%p) = {%p}\n", tree, x, y);
    return y;
  }
}

/// @fn RedBlackNode *rbTreePredecessor(RedBlackTree *tree, RedBlackNode *x)
///
/// @brief Finds the predecessor of a node in a RedBlackTree.
///
/// @param tree is a pointer to the RedBlackTree to search.
/// @param x is a pointer to the node to find the predecessor of.
///
/// @return This function returns the predecessor of x or NULL if no
///   predecessor exists.
///
/// @note Uses the algorithm in _Introduction_To_Algorithms_.
RedBlackNode *rbTreePredecessor(RedBlackTree *tree, RedBlackNode *x) {
  printLog(TRACE, "ENTER rbTreePredecessor(tree=%p, x=%p)\n", tree, x);
  
  // Parameter check.
  if (tree == NULL) {
    printLog(ERR, "tree is NULL.\n");
    printLog(TRACE, "EXIT rbTreePredecessor(tree=%p, x=%p) = {%p}\n",
      tree, x, (void*) NULL);
    return NULL;
  }
  if (x == NULL) {
    printLog(ERR, "x is NULL.\n");
    printLog(TRACE, "EXIT rbTreePredecessor(tree=%p, x=%p) = {%p}\n",
      tree, x, (void*) NULL);
    return NULL;
  }
  
  if ((tree->lock != NULL) && (mtx_lock(tree->lock) != thrd_success)) {
    printLog(WARN, "Could not lock red black tree mutex.\n");
  }
  
  RedBlackNode *y = NULL;
  RedBlackNode *nil = tree->nil;
  RedBlackNode *root = tree->root;

  if (nil != (y = x->left)) { // assignment to y is intentional
    while (y->right != nil) { // returns the maximum of the left subtree of x
      y = y->right;
    }
    
    if (tree->lock != NULL) {
      mtx_unlock(tree->lock);
    }
    
    printLog(TRACE, "EXIT rbTreePredecessor(tree=%p, x=%p) = {%p}\n", tree, x, y);
    return y;
  } else {
    y = x->parent;
    while (x == y->left) { 
      if (y == root) {
        if (tree->lock != NULL) {
          mtx_unlock(tree->lock);
        }
        
        printLog(TRACE, "EXIT rbTreePredecessor(tree=%p, x=%p) = {NULL}\n", tree, x);
        return NULL; 
      }
      x = y;
      y = y->parent;
    }
    
    if (tree->lock != NULL) {
      mtx_unlock(tree->lock);
    }
    
    printLog(TRACE, "EXIT rbTreePredecessor(tree=%p, x=%p) = {%p}\n", tree, x, y);
    return y;
  }
}

/// @fn RedBlackNode *rbTreeFirst(RedBlackTree *tree)
///
/// @brief Find the left-most node (the first node) in the tree.
///
/// @param tree is the red-black tree to parse.
///
/// @return Returns a pointer to the left-most node in the tree or NULL if the
///   tree is empty.
RedBlackNode *rbTreeFirst(RedBlackTree *tree) {
  printLog(TRACE, "ENTER rbTreeFirst(tree=%p)\n", tree);
  
  // Parameter check.
  if (tree == NULL) {
    printLog(ERR, "tree is NULL.\n");
    printLog(TRACE, "EXIT rbTreeFirst(tree=%p) = {%p}\n", tree, (void*) NULL);
    return NULL;
  }
  
  /* Suboptimal now
   * JBC 2019-09-29
   * RedBlackNode *nil = tree->nil;
   * RedBlackNode *x = tree->root->left;
   * RedBlackNode *y = NULL;
   * 
   * while (x != nil) {
   *   y = x;
   *   x = x->left;
   * }
   */
  
  printLog(TRACE, "EXIT rbTreeFirst(tree=%p) = {%p}\n", tree, tree->head);
  return tree->head;
}

/// @fn RedBlackNode *rbTreeLast(RedBlackTree *tree)
///
/// @brief Find the right-most node (the last node) in the tree.
///
/// @param tree is the red-black tree to parse.
///
/// @return Returns a pointer to the right-most node in the tree or NULL if the
///   tree is empty.
RedBlackNode *rbTreeLast(RedBlackTree *tree) {
  printLog(TRACE, "ENTER rbTreeLast(tree=%p)\n", tree);
  
  // Parameter check.
  if (tree == NULL) {
    printLog(ERR, "tree is NULL.\n");
    printLog(TRACE, "EXIT rbTreeLast(tree=%p) = {%p}\n", tree, (void*) NULL);
    return NULL;
  }
  
  /* Suboptimal now
   * JBC 2019-09-29
   * RedBlackNode *nil = tree->nil;
   * RedBlackNode *x = tree->root->left;
   * RedBlackNode *y = NULL;
   * 
   * while (x != nil) {
   *   y = x;
   *   x = x->right;
   * }
   */
  
  printLog(TRACE, "EXIT rbTreeLast(tree=%p) = {%p}\n", tree, tree->tail);
  return tree->tail;
}


/// @fn static void treeDestroyHelper(RedBlackTree *tree, RedBlackNode *x)
///
/// @brief This function recursively destroys the nodes of the tree
///   postorder using the tree->keyType->destroy and x->type->destroy functions.
///
/// @param tree is the tree to destroy
/// @param x is the current node
///
/// @return This function returns no value.
///
/// @note This function should only be called by rbTreeDestroy.
void treeDestroyHelper(RedBlackTree *tree, RedBlackNode *x) {
  printLog(TRACE, "ENTER treeDestroyHelper(tree=%p, x=%p)\n", tree, x);
  
  RedBlackNode *nil = tree->nil;
  if (x != nil) {
    treeDestroyHelper(tree, x->left); x->left = NULL;
    treeDestroyHelper(tree, x->right); x->right = NULL;
    tree->keyType->destroy(x->key); x->key = NULL;
    x->type->destroy(x->value); x->value = NULL;
    x = (RedBlackNode*) pointerDestroy(x);
    tree->size--;
  }
  
  printLog(TRACE, "EXIT treeDestroyHelper(tree=%p, x=%p) = {}\n", tree, x);
}

/// @fn RedBlackTree *rbTreeDestroy(RedBlackTree *tree)
///
/// @brief Destroys the tree and frees memory.
///
/// @param tree is the tree to destroy
///
/// @return Returns a NULL pointer to indicate that the tree is deallocated.
RedBlackTree *rbTreeDestroy(RedBlackTree *tree) {
  printLog(TRACE, "ENTER rbTreeDestroy(tree=%p)\n", tree);
  
  if (tree == NULL) {
    printLog(TRACE, "EXIT rbTreeDestroy(tree=%p) = {%p}\n", tree, (void*) NULL);
    return NULL;
  }
  
  treeDestroyHelper(tree, tree->root->left); tree->root->left = NULL;
  tree->root = (RedBlackNode*) pointerDestroy(tree->root);
  tree->nil = (RedBlackNode*) pointerDestroy(tree->nil);
  if (tree->lock != NULL) {
    mtx_destroy(tree->lock);
  }
  tree->lock = (mtx_t*) pointerDestroy(tree->lock);
  tree = (RedBlackTree*) pointerDestroy(tree);
  
  printLog(TRACE, "EXIT rbTreeDestroy(tree=%p) = {%p}\n", tree, (void*) NULL);
  return NULL;
}

/// @fn i32 rbTreeClear(RedBlackTree *tree)
///
/// @brief Clears the tree but does not free memory.
///
/// @param tree The tree to clear.
///
/// @return Returns 0 on success, -1 on failure.
i32 rbTreeClear(RedBlackTree *tree) {
  printLog(TRACE, "ENTER rbTreeClear(tree=%p)\n", tree);
  
  if (tree == NULL) {
    printLog(ERR, "NULL tree provided.\n");
    printLog(TRACE, "EXIT rbTreeClear(tree=%p) = {%p}\n", tree, (void*) NULL);
    return -1;
  }
  
  if ((tree->lock != NULL) && (mtx_lock(tree->lock) != thrd_success)) {
    printLog(WARN, "Could not lock red black tree mutex.\n");
  }
  
  treeDestroyHelper(tree, tree->root->left); tree->root->left = tree->nil;
  tree->head = NULL;
  tree->tail = NULL;
  if (tree->filePointer != NULL) {
    fclose(tree->filePointer); tree->filePointer = NULL;
  }
  tree->head = NULL;
  tree->tail = NULL;
  
  if (tree->lock != NULL) {
    mtx_unlock(tree->lock);
  }
  
  printLog(TRACE, "EXIT rbTreeClear(tree=%p) = {%p}\n", tree, (void*) NULL);
  return 0;
}

/// @fn RedBlackNode *rbQuery(const RedBlackTree *tree, const volatile void *q)
///
/// @brief Find the RedBlackNode in the tree with a key equal to q.
///
/// @details
/// If there are multiple nodes with key equal to q, this function returns
///   the one highest in the tree.
///
/// @param tree is a pointer to the RedBlackTree to search.
/// @param q is the key value to search for
///
/// @return A RedBlackTree with key equal to q on success or NULL on failure.
RedBlackNode *rbQuery(const RedBlackTree *tree, const volatile void *q) {
  printLog(TRACE, "ENTER rbQuery(tree=%p, q=%p)\n", tree, q);
  
  if (tree == NULL) {
    printLog(DEBUG, "Tree provided is NULL.\n");
    
    printLog(TRACE, "EXIT rbQuery(tree=%p, q=%p) = {%p}\n",
      tree, q, (void*) NULL);
    return NULL;
  }
  
  if ((tree->lock != NULL) && (mtx_lock(tree->lock) != thrd_success)) {
    printLog(WARN, "Could not lock red black tree mutex.\n");
  }
  
  RedBlackNode *x = tree->root->left;
  RedBlackNode *nil = tree->nil;
  int compVal = 0;
  if (x == nil) {
    if (tree->lock != NULL) {
      mtx_unlock(tree->lock);
    }
    
    printLog(TRACE, "EXIT rbQuery(tree=%p, q=%p) = {%p}\n",
      tree, q, (void*) NULL);
    return NULL;
  }
  compVal = tree->keyType->compare(x->key, q);
  while (compVal != 0) { //assignemnt
    if (compVal > 0) { // x->key > q
      x = x->left;
    } else { // x->key <= q
      x = x->right;
    }
    if ((x == nil) || (x == NULL)) {
      if (tree->lock != NULL) {
        mtx_unlock(tree->lock);
      }
      
      printLog(TRACE, "EXIT rbQuery(tree=%p, q=%p) = {%p}\n",
        tree, q, (void*) NULL);
      return NULL;
    }
    compVal = tree->keyType->compare(x->key, q);
  }
  
  if (tree->lock != NULL) {
    mtx_unlock(tree->lock);
  }
  
  printLog(TRACE, "EXIT rbQuery(tree=%p, q=%p) = {%p}\n", tree, q, x);
  return x;
}


/// @fn static void rbTreeDestroyNodeFixUp(RedBlackTree *tree, RedBlackNode *x)
///
/// @brief Performs rotations and changes colors to restore red-black
///   properties after a node is deleted.
///
/// @param tree is the tree to fix.
/// @param x is the child of the spliced out node in rbTreeDelete.
///
/// @note The algorithm for this function is from _Introduction_To_Algorithms_.
void rbTreeDestroyNodeFixUp(RedBlackTree *tree, RedBlackNode *x) {
  printLog(TRACE, "ENTER rbTreeDestroyNodeFixUp(tree=%p, x=%p)\n", tree, x);
  
  RedBlackNode *root = tree->root->left;
  RedBlackNode *w = NULL;

  while ((x->red == false) && (root != x)) {
    if (x == x->parent->left) {
      w = x->parent->right;
      if (w->red == true) {
        w->red = false;
        x->parent->red = true;
        leftRotate(tree, x->parent);
        w = x->parent->right;
      }
      if ((w->right->red == false) && (w->left->red == false)) { 
        w->red = true;
        x = x->parent;
      } else {
        if (w->right->red == false) {
          w->left->red = false;
          w->red = true;
          rightRotate(tree, w);
          w = x->parent->right;
        }
        w->red = x->parent->red;
        x->parent->red = false;
        w->right->red = false;
        leftRotate(tree, x->parent);
        x = root; // this is to exit while loop
      }
    } else { // the code below is has left and right switched from above
      w = x->parent->left;
      if (w->red == true) {
        w->red = false;
        x->parent->red = true;
        rightRotate(tree, x->parent);
        w = x->parent->left;
      }
      if ((w->right->red == false) && (w->left->red == false)) { 
        w->red = true;
        x = x->parent;
      } else {
        if (w->left->red == false) {
          w->right->red = false;
          w->red = true;
          leftRotate(tree, w);
          w = x->parent->left;
        }
        w->red = x->parent->red;
        x->parent->red = false;
        w->left->red = false;
        rightRotate(tree, x->parent);
        x = root; // this is to exit while loop
      }
    }
  }
  x->red = false;

#ifdef DEBUG_ASSERT
  rbAssert((tree->nil->red == false), "nil not black in rbTreeDestroyNodeFixUp");
#endif
  printLog(TRACE, "EXIT rbTreeDestroyNodeFixUp(tree=%p, x=%p) = {}\n", tree, x);
}


/// @fn int rbTreeDestroyNode(RedBlackTree *tree, RedBlackNode *z)
///
/// @brief Deletes z from tree and frees the key and value of z
///   using tree->keyType->destory and z->type->destroy.
///
/// @details  This function calls rbTreeDestroyNodeFixUp to restore red-black
///   properties after the deletion of z.
///
/// @param tree is the tree to remove the node from.
/// @param z is the node to remove.
///
/// @return Returns 0 on success, -1 on failure.
///
/// @note The algorithm for this function is from _Introduction_To_Algorithms_.
int rbTreeDestroyNode(RedBlackTree *tree, RedBlackNode *z) {
  printLog(TRACE, "ENTER rbTreeDestroyNode(tree=%p, z=%p) = {}\n", tree, z);
  
  int returnValue = 0;
  
  // Parameter check.
  if (tree == NULL) {
    printLog(ERR, "tree is NULL.\n");
    returnValue = -1;
    printLog(TRACE, "EXIT rbTreeDestroyNode(tree=%p, z=%p) = {%d}\n",
      tree, z, returnValue);
    return returnValue;
  }
  if (z == NULL) {
    printLog(ERR, "z is NULL.\n");
    returnValue = -1;
    printLog(TRACE, "EXIT rbTreeDestroyNode(tree=%p, z=%p) = {%d}\n",
      tree, z, returnValue);
    return returnValue;
  }
  
  if ((tree->lock != NULL) && (mtx_lock(tree->lock) != thrd_success)) {
    printLog(WARN, "Could not lock red black tree mutex.\n");
  }
  
  RedBlackNode *x = NULL;
  RedBlackNode *y = NULL;
  RedBlackNode *nil = tree->nil;
  RedBlackNode *root = tree->root;
  
  if (z->prev != NULL) {
    z->prev->next = z->next;
  }
  if (z->next != NULL) {
    z->next->prev = z->prev;
  }
  
  y = ((z->left == nil) || (z->right == nil)) ? z : rbTreeSuccessor(tree, z);
  x = (y->left == nil) ? y->right : y->left;
  if (root == (x->parent = y->parent)) {
    // assignment of y->parent to x->parent above is intentional
    root->left = x;
  } else {
    if (y == y->parent->left) {
      y->parent->left = x;
    } else {
      y->parent->right = x;
    }
  }
  if (y != z) { // y should not be nil in this case
    // We're removing z in this case.
#ifdef DEBUG_ASSERT
    rbAssert((y != tree->nil), "y is nil in rbTreeDestroyNode\n");
#endif
    
    // y is the node to splice out and x is its child
    if (y->red == false) {
      rbTreeDestroyNodeFixUp(tree, x);
    }
    
    // Fix the linked-list portions.
    if (tree->head == z) {
      tree->head = z->next;
    }
    if (tree->tail == z) {
      tree->tail = z->prev;
    }
    if (z->prev != NULL) {
      z->prev->next = z->next;
    }
    if (z->next != NULL) {
      z->next->prev = z->prev;
    }
    
    tree->keyType->destroy(z->key); z->key = NULL;
    z->type->destroy(z->value); z->value = NULL;
    y->left = z->left;
    y->right = z->right;
    y->parent = z->parent;
    y->red = z->red;
    z->left->parent = z->right->parent = y;
    if (z == z->parent->left) {
      z->parent->left = y; 
    } else {
      z->parent->right = y;
    }
    z = (RedBlackNode*) pointerDestroy(z);
  } else {
    // We're removing y in this case.
    // Fix the linked-list portions.
    if (tree->head == y) {
      tree->head = y->next;
    }
    if (tree->tail == y) {
      tree->tail = y->prev;
    }
    if (y->prev != NULL) {
      y->prev->next = y->next;
    }
    if (y->next != NULL) {
      y->next->prev = y->prev;
    }
    
    tree->keyType->destroy(y->key); y->key = NULL;
    y->type->destroy(y->value); y->value = NULL;
    if (y->red == false) {
      rbTreeDestroyNodeFixUp(tree, x);
    }
    y = (RedBlackNode*) pointerDestroy(y);
  }
  tree->size--;
  
  if (tree->lock != NULL) {
    mtx_unlock(tree->lock);
  }
  
#ifdef DEBUG_ASSERT
  rbAssert((tree->nil->red == false) ,"nil not black in rbTreeDestroyNode");
#endif
  printLog(TRACE, "EXIT rbTreeDestroyNode(tree=%p, z=%p) = {%d}\n",
    tree, z, returnValue);
  return returnValue;
}

/// @fn int rbTreeRemove(RedBlackTree *tree, const volatile void *key)
///
/// @brief Remove and destroy a node from the tree identified by key.
///
/// @param tree is a pointer to the RedBlackTree to remove from.
/// @param key is the key to match in a node.
///
/// @return Returns 0 if a matching node was found and destroyed, -1 otherwise.
///
/// @note If there are multiple nodes with a matching key, this function
///   removes and destorys the matching node highest in the tree.
int rbTreeRemove(RedBlackTree *tree, const volatile void *key) {
  printLog(TRACE, "ENTER rbTreeRemove(tree=%p, key=%p)\n", tree, key);
  
  if (tree == NULL) {
    printLog(TRACE, "EXIT rbTreeRemove(tree=%p, key=%p) = {%p}\n",
      tree, key, (void*) NULL);
    return -1;
  }
  
  if ((tree->lock != NULL) && (mtx_lock(tree->lock) != thrd_success)) {
    printLog(WARN, "Could not lock red black tree mutex.\n");
  }
  
  RedBlackNode *node = rbQuery(tree, key);
  if (node != NULL) {
    rbTreeDestroyNode(tree, node);
    if (tree->lock != NULL) {
      mtx_unlock(tree->lock);
    }
    
    printLog(TRACE, "EXIT rbTreeRemove(tree=%p, key=%p) = {0}\n", tree, key);
    return 0;
  } else {
    if (tree->lock != NULL) {
      mtx_unlock(tree->lock);
    }
    
    printLog(TRACE, "EXIT rbTreeRemove(tree=%p, key=%p) = {-1}\n", tree, key);
    return -1;
  }
}

/// @fn List *rbEnumerate(const RedBlackTree *tree, const volatile void *low, const volatile void *high)
///
/// @brief Create a list containing node contents between low and high,
///   inclusive.
///
/// @param tree is a pointer to the RedBlackTree to search.
/// @param low is the minimum value to return.
/// @param high is the maximum value to return.
///
/// @return Returns a list containing tree contents between low and high,
///   inclusive.
List *rbEnumerate(const RedBlackTree *tree,
  const volatile void *low, const volatile void *high
) {
  printLog(TRACE, "ENTER rbEnumerate(tree=%p, low=%p, high=%p)\n",
    tree, low, high);
  
  // Parameter check.
  if (tree == NULL) {
    printLog(ERR, "tree is NULL.\n");
    printLog(TRACE, "EXIT rbEnumerate(tree=%p, low=%p, high=%p) = {%p}\n",
      tree, low, high, (void*) NULL);
    return NULL;
  }
  if (low == NULL) {
    printLog(ERR, "low is NULL.\n");
    printLog(TRACE, "EXIT rbEnumerate(tree=%p, low=%p, high=%p) = {%p}\n",
      tree, low, high, (void*) NULL);
    return NULL;
  }
  if (high == NULL) {
    printLog(ERR, "high is NULL.\n");
    printLog(TRACE, "EXIT rbEnumerate(tree=%p, low=%p, high=%p) = {%p}\n",
      tree, low, high, (void*) NULL);
    return NULL;
  }
  
  if ((tree->lock != NULL) && (mtx_lock(tree->lock) != thrd_success)) {
    printLog(WARN, "Could not lock red black tree mutex.\n");
  }
  
  List *enumResultStack = NULL;
  RedBlackNode *nil = tree->nil;
  RedBlackNode *x = tree->root->left;
  RedBlackNode *lastBest = nil;

  enumResultStack = listCreate(tree->keyType);
  
  while (x != nil) {
    if (tree->keyType->compare(x->key, high) > 0) { // x->key > high
      x = x->left;
    } else { // x->key <= high
      lastBest = x;
      x = x->right;
    }
  }
  while ((lastBest != NULL) && (tree->keyType->compare(low, lastBest->key) <= 0)) {
    listAddFrontEntry(enumResultStack, lastBest->key, lastBest->value, lastBest->type);
    /* Suboptimal now.
     * JBC 2019-09-29
     * lastBest = rbTreePredecessor(tree, lastBest);
     */
    lastBest = lastBest->prev;
  }
  
  if (tree->lock != NULL) {
    mtx_unlock(tree->lock);
  }
    
  // Top of stack now contains first tree entry >= low.  Bottom of stack now
  // contains last tree entry <= high.
  printLog(TRACE, "EXIT rbEnumerate(tree=%p, low=%p, high=%p) = {%p}\n", tree, low, high, enumResultStack);
  return enumResultStack;
}

/// @fn void rbAssert(bool assertion, const char *error)
///
/// @brief Verify that a condition is true and exit if not.
///
/// @param assertion is the condition to evaluate.
/// @param error is the error message to be generated if assertion is false.
///
/// @return This function returns no value.
///
/// @note If DEBUG_ASSERT is not defined then assertions should not
///       be in use as they will slow down the code.  Therefore the
///       compiler will complain if an assertion is used when
///       DEBUG_ASSERT is undefined.
void rbAssert(bool assertion, const char *error) {
  if (assertion == false) {
    fprintf(stderr, "rbAssertion Failed: %s\n", error);
    fflush(stderr);
    exit(-1);
  }
}

/// @fn void *rbSafeMalloc(size_t size)
///
/// @brief Allocate memory or exit the program if the memory cannot be
///   allocated.
///
/// @param size is the size to malloc.
///
/// @return Returns pointer to allocated memory if succesful.
void *rbSafeMalloc(size_t size) {
  void *result;

  if ((result = malloc(size))) { // assignment intentional
    return result;
  } else {
    printLog(CRITICAL, "memory overflow: malloc failed in rbSafeMalloc.");
    printLog(CRITICAL, "  Exiting Program.\n");
    exit(-1);
    return NULL;
  }
}

/// @fn int rbTreeCompare(const RedBlackTree *treeA, const RedBlackTree *treeB)
///
/// @brief Compare two RedBlackTrees.
///
/// @param treeA,treeB are the trees to compare.
///
/// @return Returns 0 if the contents of the two trees are identical, non-zero
///   otherwise.
int rbTreeCompare(const RedBlackTree *treeA, const RedBlackTree *treeB) {
  printLog(TRACE, "ENTER rbTreeCompare(treeA=%p, treeB=%p)\n", treeA, treeB);
  
  int returnValue = listCompare((List*) treeA, (List*) treeB);
  
  printLog(TRACE, "EXIT rbTreeCompare(treeA=%p, treeB=%p) = {%d}\n", treeA, treeB, returnValue);
  return returnValue;
}

/// @fn RedBlackTree *rbTreeCopy(const RedBlackTree *tree)
///
/// @brief Create a copy of an existing RedBlackTree into a new RedBlackTree.
///
/// @param tree is a pointer to the tree to copy.
///
/// @return Returns a newly-allocated tree with contents identical to the
///   input tree.
RedBlackTree *rbTreeCopy(const RedBlackTree *tree) {
  printLog(TRACE, "ENTER rbTreeCopy(tree=%p)\n", tree);
  
  RedBlackTree *treeCopy = NULL;
  RedBlackNode *node = NULL;
  
  if (tree == NULL) {
    printLog(ERR, "Tree provided is NULL.\n");
    
    printLog(TRACE, "EXIT rbTreeCopy(tree=%p) = {%p}\n", tree, treeCopy);
    return treeCopy; // NULL
  }
  treeCopy = rbTreeCreate(tree->keyType);
  
  if ((tree->lock != NULL) && (mtx_lock(tree->lock) != thrd_success)) {
    printLog(WARN, "Could not lock red black tree mutex.\n");
  }
  
  if (tree->tail == NULL) {
    // Empty tree.  We're done with the copy.
    if (tree->lock != NULL) {
      mtx_unlock(tree->lock);
    }
      
    printLog(TRACE, "EXIT rbTreeCopy(tree=%p) = {%p}\n", tree, treeCopy);
    return treeCopy; // Empty tree
  }
  
  for (node = tree->head; node != tree->tail->next; node = node->next) {
    rbTreeAddEntry(treeCopy, node->key, node->value, node->type);
  }
  
  if (tree->lock != NULL) {
    mtx_unlock(tree->lock);
  }
  
  printLog(TRACE, "EXIT rbTreeCopy(tree=%p) = {%p}\n", tree, treeCopy);
  return treeCopy;
}

/// @fn size_t rbTreeSize(const volatile void *value)
///
/// @brief Compute the size of a RedBlackTree structure in memory.
///
/// @return Returns the size of the RedBlackTree structure in bytes.
size_t rbTreeSize(const volatile void *value) {
  size_t size = 0;
  RedBlackTree *tree = (RedBlackTree*) value;
  printLog(TRACE, "ENTER rbTreeSize(value=\"%p\")\n", value);
  
  if (tree != NULL) {
    size = sizeof(RedBlackTree);
  }
  
  printLog(TRACE, "EXIT rbTreeSize(value=\"%p\") = {%llu}\n", value, llu(size));
  return size;
}

/// @fn RedBlackTree *rbTreeFromBlob_(const volatile void *array, u64 *length, bool inPlaceData, bool disableThreadSafety, ...)
///
/// @brief Convert a properly-formatted byte array into a red-black tree.
///
/// @param array The array of bytes to convert.
/// @param length As an input, this is the number of bytes in array.  As an
///   output, this is the number of bytes consumed by this call.
/// @param inPlaceData Whether the data should be used in place (true) or a
///   copy should be made and returned (false).
/// @param disableThreadSafety Whether or not thread safety should be disabled
///   in the returned list.
///
/// @return Returns a pointer to a RedBlackTree on success, NULL on failure.
RedBlackTree *rbTreeFromBlob_(const volatile void *array, u64 *length, bool inPlaceData, bool disableThreadSafety, ...) {
  char *byteArray = (char*) array;
  RedBlackTree *rbTree = NULL;
  u64 index = 0;
  i16 typeIndex = 0, keyTypeIndex = 0;
  printLog(TRACE,
    "ENTER rbTreeFromBlob(array=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s)\n",
    array, length, boolNames[inPlaceData], boolNames[disableThreadSafety]);
  u64 size = 0;
  TypeDescriptor *keyType = NULL, *keyTypeNoCopy = NULL;
  
  if ((array == NULL) || (length == NULL)) {
    printLog(ERR, "One or more NULL parameters.\n");
    printLog(TRACE,
      "EXIT rbTreeFromBlob(array=%p, length=%p, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      rbTree, length, boolNames[inPlaceData], boolNames[disableThreadSafety], rbTree);
    return NULL;
  }
  
  // Length check
  u64 arrayLength = *length;
  if (arrayLength < sizeof(DsMarker) + sizeof(DsVersion)
    + sizeof(typeIndex) + sizeof(size)
  ) {
    printLog(ERR, "Insufficient data provided.\n");
    printLog(ERR, "If this input came from this library, please "
      "report this as a bug.\n");
    return NULL;
  }
  *length = 0;
  
  // Metadata check
  u16 dsMarker = *((u16*) &byteArray[index]);
  littleEndianToHost(&dsMarker, sizeof(dsMarker));
  if (dsMarker != DsMarker) {
    printLog(ERR, "Unknown byte array.\n");
    printLog(ERR, "If this input came from this library, please "
      "report this as a bug.\n");
    return NULL;
  }
  index += sizeof(u16);
  
  u32 dsVersion = *((u32*) &byteArray[index]);
  littleEndianToHost(&dsVersion, sizeof(dsVersion));
  if (dsVersion != 10) {
    printLog(ERR, "Don't know how to parse version %u of input byte array.\n",
      dsVersion);
    printLog(ERR, "If this input came from this library, please "
      "report this as a bug.\n");
    return NULL;
  }
  index += sizeof(u32);
  
  keyTypeIndex = *((i16*) &byteArray[index]);
  littleEndianToHost(&keyTypeIndex, sizeof(i16));
  index += sizeof(i16);
  if (keyTypeIndex < 1) {
    // Index is not valid.
    *length = index;
    printLog(ERR, "Improperly formatted byte array.  Cannot create rbTree.\n");
    printLog(TRACE,
      "EXIT rbTreeFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], rbTree);
    return NULL;
  }
  keyType = getTypeDescriptorFromIndex(keyTypeIndex);
  keyTypeNoCopy = getTypeDescriptorFromIndex(keyTypeIndex + 1);
  
  size = *((u64*) &byteArray[index]);
  littleEndianToHost(&size, sizeof(size));
  index += sizeof(size);
  rbTree = rbTreeCreate(keyTypeNoCopy, disableThreadSafety);
  if (rbTree == NULL) {
    LOG_MALLOC_FAILURE();
    printLog(NEVER,
      "EXIT rbTreeFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
      array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], rbTree);
    return NULL;
  }
  
  // Complex data types (which will have type indexes greater than or equal
  // to that of typeRedBlackTree) will need to be handled sligrbTreely differently than
  // primitives in the case that inPlaceData is true, so grab the index for
  // typeRedBlackTree now so that we can compare it later.
  i64 rbTreeIndex = getIndexFromTypeDescriptor(typeRedBlackTree);
  
  RedBlackNode *node = NULL;
  while ((index < arrayLength) && (rbTree->size < size)) {
    void *key = NULL, *value = NULL;
    u64 keySize = 0, valueSize = 0;
    TypeDescriptor *valueType = NULL, *valueTypeNoCopy = NULL;
    
    typeIndex = *((i16*) &byteArray[index]);
    littleEndianToHost(&typeIndex, sizeof(i16));
    if (typeIndex < 1) {
      // Index is not valid.
      *length = index;
      printLog(ERR,
        "Improperly formatted byte array.  Cannot continue processing\n");
      printLog(TRACE,
        "EXIT rbTreeFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
        array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], rbTree);
      if (inPlaceData) {
        // Optimize for this case.
        if (keyTypeIndex >= rbTreeIndex) {
          // See notes at the bottom of this function about this logic.
          rbTree->keyType = keyType;
        }
      } else {
        rbTree->keyType = keyType;
      }
      return rbTree;
    }
    valueType = getTypeDescriptorFromIndex(typeIndex);
    valueTypeNoCopy = getTypeDescriptorFromIndex(typeIndex + 1);
    index += sizeof(i16);
    valueSize = arrayLength - index;
    
    value = valueType->fromBlob(&byteArray[index], &valueSize, inPlaceData, disableThreadSafety);
    index += valueSize;
    if (value == NULL) {
      *length = index;
      printLog(ERR, "NULL value detected.  Cannot process.\n");
      printLog(TRACE,
        "EXIT rbTreeFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
        array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], rbTree);
      if (inPlaceData) {
        // Optimize for this case.
        if (keyTypeIndex >= rbTreeIndex) {
          // See notes at the bottom of this function about this logic.
          rbTree->keyType = keyType;
        }
      } else {
        rbTree->keyType = keyType;
      }
      return rbTree;
    }
    
    keySize = arrayLength - index;
    key = keyType->fromBlob(&byteArray[index], &keySize, inPlaceData, disableThreadSafety);
    index += keySize;
    if (key == NULL) {
      *length = index;
      printLog(ERR, "NULL key detected.  Cannot process.\n");
      printLog(TRACE,
        "EXIT rbTreeFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
        array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], rbTree);
      if (inPlaceData) {
        // Optimize for this case.
        if (keyTypeIndex >= rbTreeIndex) {
          // See notes at the bottom of this function about this logic.
          rbTree->keyType = keyType;
        }
      } else {
        rbTree->keyType = keyType;
      }
      return rbTree;
    }
    
    node = rbTreeAddEntry(rbTree, key, value, valueTypeNoCopy);
    if (node != NULL) {
      if (inPlaceData) {
        // Optimize for this case.
        if (typeIndex >= rbTreeIndex) {
          // Memory has to be allocated to hold the top-level structures of
          // complex data.  Only the primitives in the byte arrays involve no
          // memory allocations at all.  So, for complex data, we need to set
          // the node's type back to the base value type so that the destructor
          // is called.  The destructors for all the primitives will be omitted.
          node->type = valueType;
        }
      } else {
        node->type = valueType;
      }
    } else {
      printLog(ERR, "Failed to add node to rbTree.\n");
    }
  }
  if (rbTree->size < size) {
    printLog(ERR, "Expected %llu entries, but only found %llu.\n",
      llu(size), llu(rbTree->size));
    printLog(ERR, "If this input came from this library, please "
      "report this as a bug.\n");
    if (node != NULL) {
      printLog(ERR, "Last-added node was a %s type.\n", node->type->name);
    } // else The failure to add the node was printed above.
  }
  
  *length = index;
  if (inPlaceData) {
    // Optimize for this case.
    if (keyTypeIndex >= rbTreeIndex) {
      // See note above for value types.  Not sure why anyone would want to have
      // a comlex data type as a key, but it is possible, so cover the case.
      rbTree->keyType = keyType;
    }
  } else {
    rbTree->keyType = keyType;
  }
  
  printLog(TRACE,
    "EXIT rbTreeFromBlob(array=%p, length=%llu, inPlaceData=%s, disableThreadSafety=%s) = {%p}\n",
    array, llu(*length), boolNames[inPlaceData], boolNames[disableThreadSafety], rbTree);
  return rbTree;
}

/// @fn RedBlackTree* listToRbTree(const List *list)
///
/// @brief Convert a List (or compatible data structure) to a red-black tree.
///
/// @return Returns a pointer to a new red-black tree on success, NULL on
/// failure.
RedBlackTree* listToRbTree(const List *list) {
  printLog(TRACE, "ENTER listToRbTree(list=%p)\n", list);
  
  if (list == NULL) {
    printLog(DEBUG, "List provided is NULL.\n");
    
    printLog(TRACE, "EXIT listToRbTree(list=%p) = {%p}\n", list, (void*) NULL);
    return NULL;
  }
  
  RedBlackTree *tree = rbTreeCreate(list->keyType);
  
  if ((list->lock != NULL) && (mtx_lock(list->lock) != thrd_success)) {
    printLog(WARN, "Could not lock list mutex.\n");
  }
  
  i64 listIndex = getIndexFromTypeDescriptor(typeList);
  for (ListNode *node = list->head; node != NULL; node = node->next) {
    if (getIndexFromTypeDescriptor(node->type) < listIndex) {
      // The usual case, so put it first.
      rbTreeAddEntry(tree, node->key, node->value, node->type);
    } else {
      rbTreeAddEntry(tree, node->key, listToRbTree((List*) node->value),
        typeRedBlackTreeNoCopy)->type = typeRedBlackTree;
    }
  }
  
  if (list->lock != NULL) {
    mtx_unlock(list->lock);
  }
    
  printLog(TRACE, "EXIT listToRbTree(list=%p) = {%p}\n", list, tree);
  return tree;
}

/// @fn void *rbTreeGetValue(const RedBlackTree *tree, const volatile void *key)
///
/// @brief Get a value from the red black tree given the key for its node.
///
/// @param tree A pointer to the RedBlackTree to search.
/// @param key A pointer to the key to search for.
///
/// @return Returns a pointer to the found value on success, NULL on failure.
void *rbTreeGetValue(const RedBlackTree *tree, const volatile void *key) {
  printLog(TRACE, "ENTER rbTreeGetValue(tree=%p, key=%p)\n", tree, key);
  
  if ((tree == NULL) || (key == NULL)) {
    printLog(DEBUG, "Invalid parameters.\n");
    printLog(TRACE, "EXIT rbTreeGetValue(tree=%p, key=%p) = {NULL}\n", tree, key);
    return NULL;
  }
  
  RedBlackNode *node = rbQuery(tree, key);
  void *x = NULL;
  if (node != NULL) {
    x = (void*) node->value;
  }
  
  printLog(TRACE, "EXIT rbTreeGetValue(tree=%p, key=%p) = {%p}\n", tree, key, x);
  return x;
}

/// @fn RedBlackTree *xmlToRedBlackTree(const char *inputData)
///
/// @brief Take SOAP data and return a hash table of key-value objects.
///
/// @param inputData is the full data string from a POST call.
///
/// @return Returns a RedBlackTree containing the data parsed.
RedBlackTree *xmlToRedBlackTree(const char *inputData) {
  char *separatorAt = NULL;
  char *rbTreeString = NULL, *indentedRedBlackTreeString = NULL;
  RedBlackTree *rbTree= NULL;
  char *key = NULL;
  Bytes value = NULL;
  char *xmlString = NULL;
  
  printLog(TRACE, "ENTER xmlToRedBlackTree(inputData=\"%s\")\n", inputData);
  
  if (inputData == NULL) {
    printLog(ERR, "NULL inputData provided.\n");
    printLog(TRACE, "EXIT xmlToRedBlackTree(inputData=NULL) = {NULL}\n");
    return NULL;
  }
  
  const char *startAt = &(inputData[strspn(inputData, " \t\n")]);
  if (*startAt != '<') {
    printLog(DEBUG, "No XML provided.\n");
    printLog(TRACE, "EXIT xmlToRedBlackTree(inputData=NULL) = {NULL}\n");
    return NULL;
  }
  straddstr(&xmlString, startAt);
  
  rbTree = rbTreeCreate(typeString);
  
  separatorAt = strstr(xmlString, "Request");
  if (separatorAt == NULL) {
    // Might be response data we're parsing instead of request data.  Try that.
    separatorAt = strstr(xmlString, "Response");
  }
  if (separatorAt == NULL) {
    // See if it's just generic XML, maybe.
    printLog(DEBUG, "Looking for generic XML data.\n");
    separatorAt = strchr(xmlString, '>');
    if (separatorAt != NULL && separatorAt != xmlString) {
      printLog(DEBUG, "Generic XML data found.\n");
      separatorAt--;
    }
  }
  if (separatorAt != NULL) {
    separatorAt = strchr(separatorAt, '>'); // Skip over the request header
    if (separatorAt != NULL) {
      separatorAt = strchr(separatorAt, '<');
      // We're now either at the first field or the close of the request
    }
  }
  
  while (separatorAt != NULL && *(separatorAt + 1) != '/') {
    char *endOfLine = strchr(separatorAt, '\n');
    // separatorAt should point to a '<'
    char *endOfTag = strchr((++separatorAt), ' ');
    printLog(DEBUG, "In separatorAt while.\n");
    
    if (endOfLine == NULL) {
      // XML is all on one line
      endOfLine = separatorAt + strlen(separatorAt);
    }
    
    if (endOfTag != NULL && strchr(separatorAt, '>') &&
      strchr(separatorAt, '>') < endOfTag) {
      endOfTag = strchr((separatorAt), '>');
    }
    
    if (endOfTag == NULL || endOfTag > endOfLine) {
      endOfTag = strchr((separatorAt), '>');
    }
    
    if (endOfTag != NULL) {
      char *valueAt = NULL;
      char *closeTag = NULL;
      
      if (*endOfTag == '>' && *(endOfTag - 1) == '/') {
        // There is no value for this key
        valueAt = NULL;
      } else if (*endOfTag == '>') {
        valueAt = endOfTag + 1;
      } else { // endOfTag is ' '
        valueAt = strchr((separatorAt + 1), '>');
        if (valueAt) {
          valueAt = valueAt + 1;
        }
      }
      *endOfTag = '\0';
      key = (char *) malloc(strlen(separatorAt) + 1);
      strcpy(key, separatorAt);
      straddstr(&closeTag, "</");
      straddstr(&closeTag, key);
      if (valueAt) {
        endOfTag = strstr(valueAt, closeTag);
      } else {
        endOfTag = NULL;
      }
      if (endOfTag != NULL) {
        *endOfTag = '\0';
        value = NULL;
        bytesAddStr(&value, valueAt);
      } else {
        // No value but there WAS a tag so we can't just leave the value
        // NULL.  Make it an empty string.
        value = NULL;
        bytesAddData(&value, "", 1);
      }
      closeTag = stringDestroy(closeTag);
      
      // OK.  We're parsing XML data.  It's possible that what we just parsed
      // is really just more XML.  If so, it should be added to a subordinate
      // List.  Try to detect this case and act intelligently.
      if (strstr(str(value), "<") != NULL &&
        strrchr(str(value), '>') != NULL &&
        strstr(str(value), "<") < strrchr(str(value), '>')) {
        // Probably more XML.  Make it look like XML and parse again.
        char *xmlValue = NULL;
        straddstr(&xmlValue, "<");
        straddstr(&xmlValue, key);
        straddstr(&xmlValue, ">\n");
        straddstr(&xmlValue, str(value));
        straddstr(&xmlValue, "</");
        straddstr(&xmlValue, key);
        straddstr(&xmlValue, ">\n");
        value = bytesDestroy(value);
        RedBlackTree *subTable = xmlToRedBlackTree(xmlValue);
        xmlValue = stringDestroy(xmlValue);
        HashNode *node = rbTreeAddEntry(rbTree, key, subTable,
          typeRedBlackTreeNoCopy);
        if (node == NULL) {
          printLog(ERR, "rbTreeAddEntry failed when adding key/table pair.\n");
        } else {
          node->type = typeRedBlackTree;
        }
      }
    } else {
      // No end of tag?  Is this possible?
    }
    
    if (value != NULL) {
      HashNode *node = rbTreeAddEntry(rbTree, key, value, typeBytesNoCopy);
      if (node != NULL) {
        node->type = typeBytes;
      } else {
        printLog(ERR, "rbTreeAddEntry failed when adding key/value pair.\n");
      }
    }
    key = stringDestroy(key);
    
    // separatorAt should now be at the beginning of the value
    // endOfTag should now be at the '<' of the closing tag but set to '\0'
    if (endOfTag != NULL) {
      separatorAt = strchr((endOfTag + 1), '<');
    } else {
      separatorAt = separatorAt + 1;
      separatorAt = strchr(separatorAt, '<');
    }
    // separatorAt should now be at the '<' of the opening tag of the next value
  }
  
  xmlString = stringDestroy(xmlString);
  if (logThreshold <= TRACE) {
    rbTreeString = rbTreeToString(rbTree);
    indentedRedBlackTreeString = indentText(rbTreeString, 2);
    rbTreeString = stringDestroy(rbTreeString);
  }
  printLog(TRACE, "EXIT xmlToRedBlackTree(inputData=\"%s\") = {%s}\n",
    inputData, indentedRedBlackTreeString);
  indentedRedBlackTreeString = stringDestroy(indentedRedBlackTreeString);
  return rbTree;
}

// jsonToRedBlackTree implementation from generic macro.
JSON_TO_DATA_STRUCTURE(RedBlackTree, rbTree)

/// @var typeRbTree
///
/// @brief TypeDescriptor describing how libraries should interact with
///   RedBlackTree data.
TypeDescriptor _typeRbTree = {
  .name          = "RbTree",
  .xmlName       = NULL,
  .dataIsPointer = true,
  .toString      = (char* (*)(const volatile void*)) listToString,
  .toBytes       = (Bytes (*)(const volatile void*)) listToBytes,
  .compare       = (int (*)(const volatile void*, const volatile void*)) rbTreeCompare,
  .create        = (void* (*)(const volatile void*, ...)) rbTreeCreate_,
  .copy          = (void* (*)(const volatile void*)) rbTreeCopy,
  .destroy       = (void* (*)(volatile void*)) rbTreeDestroy,
  .size          = rbTreeSize,
  .toBlob        = (Bytes (*)(const volatile void*)) listToBlob,
  .fromBlob      = (void* (*)(const volatile void*, u64*, bool, bool)) rbTreeFromBlob_,
  .hashFunction  = NULL,
  .clear         = (i32 (*)(volatile void*)) rbTreeClear,
  .toXml         = (Bytes (*)(const volatile void*, const char *elementName, bool indent, ...)) listToXml_,
  .toJson        = (Bytes (*)(const volatile void*)) listToJson,
};
TypeDescriptor *typeRbTree = &_typeRbTree;

/// @var typeRbTreeNoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with
///   RedBlackTree data that is not copied from its original source.
///
/// @details This exists because, by default, a copy of the input data is made
///   whenever a new data element is added to any data structure.  In some
///   situations, this is not desirable because the input serves no purpose
///   other than to be added to the data structure.  In such cases, this data
///   type may be specified to avoid the unnecessary copy.  The real
///   typeRbTree type can then be set after the data is added.
TypeDescriptor _typeRbTreeNoCopy = {
  .name          = "RbTree",
  .xmlName       = NULL,
  .dataIsPointer = true,
  .toString      = (char* (*)(const volatile void*)) listToString,
  .toBytes       = (Bytes (*)(const volatile void*)) listToBytes,
  .compare       = (int (*)(const volatile void*, const volatile void*)) rbTreeCompare,
  .create        = (void* (*)(const volatile void*, ...)) rbTreeCreate_,
  .copy          = (void* (*)(const volatile void*)) shallowCopy,
  .destroy       = (void* (*)(volatile void*)) nullFunction,
  .size          = rbTreeSize,
  .toBlob        = (Bytes (*)(const volatile void*)) listToBlob,
  .fromBlob      = (void* (*)(const volatile void*, u64*, bool, bool)) rbTreeFromBlob_,
  .hashFunction  = NULL,
  .clear         = (i32 (*)(volatile void*)) rbTreeClear,
  .toXml         = (Bytes (*)(const volatile void*, const char *elementName, bool indent, ...)) listToXml_,
  .toJson        = (Bytes (*)(const volatile void*)) listToJson,
};
TypeDescriptor *typeRbTreeNoCopy = &_typeRbTreeNoCopy;

/// @def RED_BLACK_TREE_UNIT_TEST
///
/// @brief Unit test for red-black tree functionality.
/// @details Implementing this as a macro instead of raw code allows this to
/// be skipped by the code coverage metrics.
///
/// @return Returns true on success, false on failure.
#define RED_BLACK_TREE_UNIT_TEST \
bool redBlackTreeUnitTest() { \
  RedBlackTree *tree = NULL, *tree2 = NULL; \
  RedBlackNode *node = NULL; \
  char *stringValue = NULL; \
  List *list = NULL; \
 \
  printLog(INFO, "Testing RedBlackTree data structure.\n"); \
 \
  tree = rbTreeCreate(NULL); \
  if (tree != NULL) { \
    printLog(ERR, "Expected NULL tree from rbTreeCreate, got %p\n", tree); \
    return false; \
  } \
 \
  node = rbTreeAddEntry(NULL, NULL, NULL, NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from rbTreeAddEntry, got %p\n", node); \
    return false; \
  } \
  node = rbTreeAddEntry(NULL, "key", NULL, NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from rbTreeAddEntry, got %p\n", node); \
    return false; \
  } \
  node = rbTreeAddEntry(NULL, "key", "value", NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from rbTreeAddEntry, got %p\n", node); \
    return false; \
  } \
 \
  node = rbQuery(NULL, NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from rbQuery, got %p\n", node); \
    return false; \
  } \
 \
  if (rbTreeRemove(NULL, NULL) >= 0) { \
    printLog(ERR, "rbTreeRemove succeeded and should not have.\n"); \
    return false; \
  } \
 \
  stringValue = rbTreeToString(NULL); \
  if (stringValue == NULL) { \
    printLog(ERR, "Got NULL pointer back from rbTreeToString.\n"); \
    return false; \
  } \
  if (*stringValue != '\0') { \
    printLog(ERR, "Expected empty string from rbTreeToString, got \"%s\"\n", stringValue); \
    return false; \
  } \
  stringValue = stringDestroy(stringValue); \
 \
  rbTreeDestroyNode(NULL, NULL); \
 \
  if (rbTreeDestroy(NULL) != NULL) { \
    printLog(ERR, "rbTreeDestroy returned non-NULL value.\n"); \
    return false; \
  } \
 \
  node = rbTreePredecessor(NULL, NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from rbTreePredecessor, got %p\n", node); \
    return false; \
  } \
 \
  node = rbTreeSuccessor(NULL, NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from rbTreeSuccessor, got %p\n", node); \
    return false; \
  } \
 \
  node = rbTreeFirst(NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from rbTreeFirst, got %p\n", node); \
    return false; \
  } \
 \
  list = rbEnumerate(NULL, NULL, NULL); \
  if (list != NULL) { \
    printLog(ERR, "Expected NULL from rbEnumerate, got %p\n", list); \
    return false; \
  } \
 \
  Bytes bytesValue = rbTreeToXml(NULL, "element"); \
  if (bytesValue == NULL) { \
    printLog(ERR, "Expected empty XML from rbTreeToXml, got NULL.\n"); \
    return false; \
  } \
  if (strcmp(str(bytesValue), "<element></element>") != 0) { \
    printLog(ERR, "Expected empty XML from rbTreeToXml, got \"%s\".\n", stringValue); \
    return false; \
  } \
  bytesValue = bytesDestroy(bytesValue); \
 \
  list = rbTreeToList(NULL); \
  if (list != NULL) { \
    printLog(ERR, "Expected NULL from rbTreeToList, got %p\n", list); \
    return false; \
  } \
 \
  tree2 = rbTreeCopy(NULL); \
  if (tree2 != NULL) { \
    printLog(ERR, "Expected NULL from rbTreeCopy, got %p\n", tree2); \
    return false; \
  } \
 \
  if (rbTreeCompare(NULL, NULL) != 0) { \
    printLog(ERR, "tree and tree2 were computed to be unequal.\n"); \
    return false; \
  } \
 \
  tree = rbTreeCreate(typeString); \
  if (tree == NULL) { \
    printLog(ERR, "Expected tree from rbTreeCreate, got NULL.\n"); \
    return false; \
  } \
 \
  node = rbTreeAddEntry(tree, NULL, NULL, NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from rbTreeAddEntry, got %p\n", node); \
    return false; \
  } \
 \
  node = rbQuery(tree, NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from rbQuery, got %p\n", node); \
    return false; \
  } \
 \
  if (rbTreeRemove(tree, NULL) >= 0) { \
    printLog(ERR, "rbTreeRemove succeeded and should not have.\n"); \
    return false; \
  } \
 \
  stringValue = rbTreeToString(tree); \
  if (stringValue == NULL) { \
    printLog(ERR, "Got NULL pointer back from rbTreeToString.\n"); \
    return false; \
  } \
  if (strcmp(stringValue, "{\n  size=0\n  keyType=string\n}") != 0) { \
    printLog(ERR, "Expected empty tree string from rbTreeToString, got \"%s\"\n", stringValue); \
    return false; \
  } \
  stringValue = stringDestroy(stringValue); \
 \
  rbTreeDestroyNode(tree, NULL); \
 \
  if (rbTreeDestroy(tree) != NULL) { \
    printLog(ERR, "rbTreeDestroy returned non-NULL value.\n"); \
    return false; \
  } \
  tree = rbTreeCreate(typeString); \
 \
  node = rbTreePredecessor(tree, NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from rbTreePredecessor, got %p\n", node); \
    return false; \
  } \
 \
  node = rbTreeSuccessor(tree, NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from rbTreeSuccessor, got %p\n", node); \
    return false; \
  } \
 \
  node = rbTreeFirst(tree); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from rbTreeFirst, got %p\n", node); \
    return false; \
  } \
 \
  list = rbEnumerate(tree, NULL, NULL); \
  if (list != NULL) { \
    printLog(ERR, "Expected NULL from rbEnumerate, got %p\n", list); \
    return false; \
  } \
 \
  bytesValue = rbTreeToXml(tree, "element"); \
  if (bytesValue == NULL) { \
    printLog(ERR, "Expected empty XML from rbTreeToXml, got NULL.\n"); \
    return false; \
  } \
  if (strcmp(str(bytesValue), "<element></element>") != 0) { \
    printLog(ERR, "Expected empty XML from rbTreeToXml, got \"%s\".\n", stringValue); \
    return false; \
  } \
  bytesValue = bytesDestroy(bytesValue); \
 \
  list = rbTreeToList(tree); \
  if (list == NULL) { \
    printLog(ERR, "Expected list from rbTreeToList, got NULL\n"); \
    return false; \
  } \
  if (list->size != 0) { \
    printLog(ERR, "List size is %llu.\n", llu(list->size)); \
    return false; \
  } \
  listDestroy(list); list = NULL; \
 \
  tree2 = rbTreeCopy(tree); \
  if (tree2 == NULL) { \
    printLog(ERR, "Expected tree from rbTreeCopy, got NULL\n"); \
    return false; \
  } \
 \
  if (rbTreeCompare(NULL, tree) >= 0) { \
    printLog(ERR, "Non-null tree was detected to be equal or greater than NULL " \
      "pointer.\n"); \
    return false; \
  } \
  if (rbTreeCompare(tree, NULL) <= 0) { \
    printLog(ERR, "Non-null tree was detected to be equal or less than NULL " \
      "pointer.\n"); \
    return false; \
  } \
  if (rbTreeCompare(tree, tree2) != 0) { \
    printLog(ERR, "Empty tree and tree2 were computed to be unequal.\n"); \
    return false; \
  } \
 \
  tree2 = (RedBlackTree*) rbTreeDestroy(tree2); \
 \
  rbTreeAddEntry(tree, "key2", "value2"); \
  rbTreeAddEntry(tree, "key1", "value1"); \
  rbTreeAddEntry(tree, "key3", "value3", typeString); \
 \
  tree2 = rbTreeCopy(tree); \
  if (rbTreeCompare(tree, tree2) != 0) { \
    printLog(ERR, "Populated tree and tree2 were computed to be unequal after rbTreeCopy.\n"); \
    return false; \
  } \
  tree2 = (RedBlackTree*) rbTreeDestroy(tree2); \
  tree2 = listToRbTree((List*) tree); \
  if (rbTreeCompare(tree, tree2) != 0) { \
    printLog(ERR, "Populated tree and tree2 were computed to be unequal after listToRbTree.\n"); \
    return false; \
  } \
  tree2 = (RedBlackTree*) rbTreeDestroy(tree2); \
 \
  RedBlackNode *node2 = rbQuery(tree, "key2"); \
  if (node2 == NULL) { \
    printLog(ERR, "Expected non-NULL from rbQuery, got %p\n", node); \
    return false; \
  } \
  node = rbTreePredecessor(tree, node2); \
  if (node == NULL) { \
    printLog(ERR, "Expected non-NULL from rbTreePredecessor, got %p\n", node); \
    return false; \
  } \
  if (strcmp((char*) node->key, "key1") != 0) { \
    printLog(ERR, "Expected key1 from rbTreePredecessor, got \"%s\"\n", \
      (char*) node->key); \
    return false; \
  } \
 \
  node = rbTreeSuccessor(tree, node2); \
  if (node == NULL) { \
    printLog(ERR, "Expected non-NULL from rbTreeSuccessor, got %p\n", node); \
    return false; \
  } \
  if (strcmp((char*) node->key, "key3") != 0) { \
    printLog(ERR, "Expected key3 from rbTreePredecessor, got \"%s\"\n", \
      (char*) node->key); \
    return false; \
  } \
 \
  node = rbTreeFirst(tree); \
  if (node == NULL) { \
    printLog(ERR, "Expected non-NULL from rbTreeFirst, got %p\n", node); \
    return false; \
  } \
  if (strcmp((char*) node->key, "key1") != 0) { \
    printLog(ERR, "Expected key1 from rbTreeFirst, got \"%s\"\n", \
      (char*) node->key); \
    return false; \
  } \
 \
  list = rbEnumerate(tree, "key1", "key3"); \
  if (list == NULL) { \
    printLog(ERR, "Expected non-NULL from rbEnumerate, got %p\n", list); \
    return false; \
  } \
  if (list->size != 3) { \
    printLog(ERR, "Expected list of size 3 from rbEnumerate, got list of size " \
      "%llu", llu(list->size)); \
    return false; \
  } \
  ListNode *listNode = listGetFront(list); \
  if (listNode == NULL) { \
    printLog(ERR, "Got NULL from listGetFront.\n"); \
    return false; \
  } \
  if (strcmp((char*) listNode->key, "key1") != 0) { \
    printLog(ERR, "Expected key1 as first item, got \"%s\".\n", \
      (char*) listNode->key); \
    return false; \
  } \
  listNode = listNode->next; \
  if (listNode == NULL) { \
    printLog(ERR, "Got NULL from first listNode->next.\n"); \
    return false; \
  } \
  if (strcmp((char*) listNode->key, "key2") != 0) { \
    printLog(ERR, "Expected key2 as second item, got \"%s\".\n", \
      (char*) listNode->key); \
    return false; \
  } \
  listNode = listNode->next; \
  if (listNode == NULL) { \
    printLog(ERR, "Got NULL from second listNode->next.\n"); \
    return false; \
  } \
  if (strcmp((char*) listNode->key, "key3") != 0) { \
    printLog(ERR, "Expected key3 as third item, got \"%s\".\n", \
      (char*) listNode->key); \
    return false; \
  } \
  listNode = listNode->next; \
  if (listNode != NULL) { \
    printLog(ERR, "Got \"%s\" from third listNode->next.\n", \
      (char*) listNode->key); \
    return false; \
  } \
  listDestroy(list); \
 \
  node = rbTreeLast(NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from rbTreeLast, got %p\n", node); \
    return false; \
  } \
  node = rbTreeLast(tree); \
  if (node == NULL) { \
    printLog(ERR, "Expected non-NULL from rbTreeLast, got NULL\n"); \
    return false; \
  } \
  if (strcmp((char*) node->key, "key3") != 0) { \
    printLog(ERR, "Expected key3 from rbTreeLast, got \"%s\"\n", \
      (char*) node->key); \
    return false; \
  } \
 \
  node = rbQuery(tree, "key1"); \
  if (node == NULL) { \
    printLog(ERR, "Expected non-NULL from rbQuery, got NULL\n"); \
    return false; \
  } \
  if (strcmp((char*) node->key, "key1") != 0) { \
    printLog(ERR, "Expected key1 from rbQuery, got \"%s\"\n", \
      (char*) node->key); \
    return false; \
  } \
 \
  if (rbTreeRemove(tree, "key2") != 0) { \
    printLog(ERR, "Could not remove key2 from tree.\n"); \
    return false; \
  } \
 \
  tree = (RedBlackTree*) rbTreeDestroy(tree); \
 \
  tree = rbTreeCreate(typeI32); \
  for (int i = 1; i < 100; i++) { \
    rbTreeAddEntry(tree, &i, &i); \
  } \
  for (int i = -1; i > -100; i--) { \
    rbTreeAddEntry(tree, &i, &i); \
  } \
  list = rbTreeToList(tree); \
  if (list == NULL) { \
    printLog(ERR, "rbTreeToList did not populate a list.\n"); \
    return false; \
  } else if (list->size != 198) { \
    printLog(ERR, "rbTreeToList returned a %llu element list, expected 198 elements." \
      "\n", llu(list->size)); \
    i32 array[199] = {0}; \
    for (ListNode *node = list->head; node != NULL; node = node->next) { \
      array[*((i32*) node->value) + 99]++; \
    } \
    printLog(ERR, "Not seen:\n"); \
    for (int i = 0; i < 199; i++) { \
      if ((array[i] == 0) && (i != 99)) { \
        printLog(ERR, "%d\n", i - 99); \
      } \
    } \
    return false; \
  } \
  listDestroy(list); list = NULL; \
  tree = (RedBlackTree*) rbTreeDestroy(tree); \
 \
  const char *jsonString = "{\n" \
    "  \"myRedBlackTree1\": {\n" \
    "    \"key1\":1,\n" \
    "    \"key2\":-2.0\n" \
    "  },\n" \
    "  \"key3\":-1E3,\n" \
    "  \"myRedBlackTree2\": {\n" \
    "    \"key4\":\"value4\",\n" \
    "    \"key5\":\"value5\",\n" \
    "    \"key6\":\"value6\"\n" \
    "  },\n" \
    "  \"myRedBlackTree3\":{\n" \
    "    \"myRedBlackTree4\":{\n" \
    "      \"key7\": \"value7\",\n" \
    "      \"key8\": \"value8\"\n" \
    "    },\n" \
    "    \"key9\":\"value9\"\n" \
    "  }\n" \
    "}"; \
  long long int startPosition = 0; \
  tree = jsonToRedBlackTree(jsonString, &startPosition); \
  if (tree == NULL) { \
    printLog(ERR, "jsonToRedBlackTree returned NULL.\n"); \
    return false; \
  } \
  Bytes byteArray = typeRedBlackTree->toBlob(tree); \
  u64 length = bytesLength(byteArray); \
  tree = rbTreeDestroy(tree); \
  tree = rbTreeFromBlob(byteArray, &length, true); \
  stringValue = rbTreeToString(tree); \
  printLog(INFO, "Table: %s\n", stringValue); \
  stringValue = stringDestroy(stringValue); \
  stringValue = (char*) rbTreeGetValue(tree, "key3"); \
  if (stringValue == NULL) { \
    printLog(ERR, "Value for key3 was NULL.\n"); \
    return false; \
  } else if (*((double*) stringValue) != -1E3) { \
    printLog(ERR, "Expected \"value3\", got \"%s\".\n", stringValue); \
    return false; \
  } \
  tree2 = (RedBlackTree*) rbTreeGetValue(tree, "myRedBlackTree1"); \
  if (tree2 == NULL) { \
    printLog(ERR, "Value for myRedBlackTree1 was NULL.\n"); \
    return false; \
  } else if (rbTreeGetEntry(tree, "myRedBlackTree1")->type != typeRedBlackTree) { \
    printLog(ERR, "Expected myRedBlackTree1 to be \"%s\", found \"%s\".\n", \
      typeRedBlackTree->name, rbTreeGetEntry(tree, "myRedBlackTree1")->type->name); \
    return false; \
  } \
  stringValue = (char*) rbTreeGetValue(tree2, "key1"); \
  if (stringValue == NULL) { \
    printLog(ERR, "Value for key1 was NULL.\n"); \
    return false; \
  } else if (*((i64*) stringValue) != 1) { \
    printLog(ERR, "Expected 1, got %lld.\n", lld(*((i64*) stringValue))); \
    return false; \
  } \
  stringValue = (char*) rbTreeGetValue(tree2, "key2"); \
  if (stringValue == NULL) { \
    printLog(ERR, "Value for key2 was NULL.\n"); \
    return false; \
  } else if (*((double*) stringValue) != -2.0) { \
    printLog(ERR, "Expected -2.0, got %lf.\n", *((double*) stringValue)); \
    return false; \
  } \
  stringValue = (char*) rbTreeGetValue(tree2, "key6"); \
  tree2 = (RedBlackTree*) rbTreeGetValue(tree, "myRedBlackTree2"); \
  if (tree2 == NULL) { \
    printLog(ERR, "Value for myRedBlackTree2 was NULL.\n"); \
    return false; \
  } else if (rbTreeGetEntry(tree, "myRedBlackTree2")->type != typeRedBlackTree) { \
    printLog(ERR, "Expected myRedBlackTree2 to be \"%s\", found \"%s\".\n", \
      typeRedBlackTree->name, rbTreeGetEntry(tree, "myRedBlackTree2")->type->name); \
    return false; \
  } \
  stringValue = (char*) rbTreeGetValue(tree2, "key4"); \
  if (stringValue == NULL) { \
    printLog(ERR, "Value for key4 was NULL.\n"); \
    return false; \
  } else if (strcmp(stringValue, "value4") != 0) { \
    printLog(ERR, "Expected \"value4\", got \"%s\".\n", stringValue); \
    return false; \
  } \
  stringValue = (char*) rbTreeGetValue(tree2, "key5"); \
  if (stringValue == NULL) { \
    printLog(ERR, "Value for key5 was NULL.\n"); \
    return false; \
  } else if (strcmp(stringValue, "value5") != 0) { \
    printLog(ERR, "Expected \"value5\", got \"%s\".\n", stringValue); \
    return false; \
  } \
  stringValue = (char*) rbTreeGetValue(tree2, "key6"); \
  if (stringValue == NULL) { \
    printLog(ERR, "Value for key6 was NULL.\n"); \
    return false; \
  } else if (strcmp(stringValue, "value6") != 0) { \
    printLog(ERR, "Expected \"value6\", got \"%s\".\n", stringValue); \
    return false; \
  } \
  tree2 = (RedBlackTree*) rbTreeGetValue(tree, "myRedBlackTree3"); \
  if (tree2 == NULL) { \
    printLog(ERR, "Value for myRedBlackTree3 was NULL.\n"); \
    return false; \
  } else if (rbTreeGetEntry(tree, "myRedBlackTree3")->type != typeRedBlackTree) { \
    printLog(ERR, "Expected myRedBlackTree3 to be \"%s\", found \"%s\".\n", \
      typeRedBlackTree->name, rbTreeGetEntry(tree, "myRedBlackTree3")->type->name); \
    return false; \
  } \
  stringValue = (char*) rbTreeGetValue(tree2, "key9"); \
  if (stringValue == NULL) { \
    printLog(ERR, "Value for key9 was NULL.\n"); \
    return false; \
  } else if (strcmp(stringValue, "value9") != 0) { \
    printLog(ERR, "Expected \"value9\", got \"%s\".\n", stringValue); \
    return false; \
  } \
  if (rbTreeGetValue(tree2, "myRedBlackTree4") == NULL) { \
    printLog(ERR, "Value for myRedBlackTree4 was NULL.\n"); \
    return false; \
  } else if (rbTreeGetEntry(tree2, "myRedBlackTree4")->type != typeRedBlackTree) { \
    printLog(ERR, "Expected myRedBlackTree4 to be \"%s\", found \"%s\".\n", \
      typeRedBlackTree->name, rbTreeGetEntry(tree, "myRedBlackTree4")->type->name); \
    return false; \
  } \
  tree2 = (RedBlackTree*) rbTreeGetValue(tree2, "myRedBlackTree4"); \
  stringValue = (char*) rbTreeGetValue(tree2, "key7"); \
  if (stringValue == NULL) { \
    printLog(ERR, "Value for key7 was NULL.\n"); \
    return false; \
  } else if (strcmp(stringValue, "value7") != 0) { \
    printLog(ERR, "Expected \"value7\", got \"%s\".\n", stringValue); \
    return false; \
  } \
  stringValue = (char*) rbTreeGetValue(tree2, "key8"); \
  if (stringValue == NULL) { \
    printLog(ERR, "Value for key8 was NULL.\n"); \
    return false; \
  } else if (strcmp(stringValue, "value8") != 0) { \
    printLog(ERR, "Expected \"value8\", got \"%s\".\n", stringValue); \
    return false; \
  } \
  byteArray = bytesDestroy(byteArray); \
  tree = rbTreeDestroy(tree); \
 \
  return true; \
}
RED_BLACK_TREE_UNIT_TEST

