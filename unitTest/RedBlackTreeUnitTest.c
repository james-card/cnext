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
#include "Vector.h"
#include "LoggingLib.h"

bool redBlackTreeUnitTest(void) {
  RedBlackTree *tree = NULL, *tree2 = NULL;
  RedBlackNode *node = NULL;
  char *stringValue = NULL;
  List *list = NULL;

  printLog(INFO, "Testing RedBlackTree data structure.\n");

  tree = rbTreeCreate(NULL);
  if (tree != NULL) {
    printLog(ERR, "Expected NULL tree from rbTreeCreate, got %p\n", tree);
    return false;
  }

  node = rbTreeAddEntry(NULL, NULL, NULL, NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from rbTreeAddEntry, got %p\n", node);
    return false;
  }
  node = rbTreeAddEntry(NULL, "key", NULL, NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from rbTreeAddEntry, got %p\n", node);
    return false;
  }
  node = rbTreeAddEntry(NULL, "key", "value", NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from rbTreeAddEntry, got %p\n", node);
    return false;
  }

  node = rbQuery(NULL, NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from rbQuery, got %p\n", node);
    return false;
  }

  if (rbTreeRemove(NULL, NULL) >= 0) {
    printLog(ERR, "rbTreeRemove succeeded and should not have.\n");
    return false;
  }

  stringValue = rbTreeToString(NULL);
  if (stringValue == NULL) {
    printLog(ERR, "Got NULL pointer back from rbTreeToString.\n");
    return false;
  }
  if (*stringValue != '\0') {
    printLog(ERR, "Expected empty string from rbTreeToString, got \"%s\"\n", stringValue);
    return false;
  }
  stringValue = stringDestroy(stringValue);

  rbTreeDestroyNode(NULL, NULL);

  if (rbTreeDestroy(NULL) != NULL) {
    printLog(ERR, "rbTreeDestroy returned non-NULL value.\n");
    return false;
  }

  node = rbTreePredecessor(NULL, NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from rbTreePredecessor, got %p\n", node);
    return false;
  }

  node = rbTreeSuccessor(NULL, NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from rbTreeSuccessor, got %p\n", node);
    return false;
  }

  node = rbTreeFirst(NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from rbTreeFirst, got %p\n", node);
    return false;
  }

  list = rbEnumerate(NULL, NULL, NULL);
  if (list != NULL) {
    printLog(ERR, "Expected NULL from rbEnumerate, got %p\n", list);
    return false;
  }

  Bytes bytesValue = rbTreeToXml(NULL, "element");
  if (bytesValue == NULL) {
    printLog(ERR, "Expected empty XML from rbTreeToXml, got NULL.\n");
    return false;
  }
  if (strcmp(str(bytesValue), "<element></element>") != 0) {
    printLog(ERR, "Expected empty XML from rbTreeToXml, got \"%s\".\n", stringValue);
    return false;
  }
  bytesValue = bytesDestroy(bytesValue);

  list = rbTreeToList(NULL);
  if (list != NULL) {
    printLog(ERR, "Expected NULL from rbTreeToList, got %p\n", list);
    return false;
  }

  tree2 = rbTreeCopy(NULL);
  if (tree2 != NULL) {
    printLog(ERR, "Expected NULL from rbTreeCopy, got %p\n", tree2);
    return false;
  }

  if (rbTreeCompare(NULL, NULL) != 0) {
    printLog(ERR, "tree and tree2 were computed to be unequal.\n");
    return false;
  }

  tree = rbTreeCreate(typeString);
  if (tree == NULL) {
    printLog(ERR, "Expected tree from rbTreeCreate, got NULL.\n");
    return false;
  }

  node = rbTreeAddEntry(tree, NULL, NULL, NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from rbTreeAddEntry, got %p\n", node);
    return false;
  }

  node = rbQuery(tree, NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from rbQuery, got %p\n", node);
    return false;
  }

  if (rbTreeRemove(tree, NULL) >= 0) {
    printLog(ERR, "rbTreeRemove succeeded and should not have.\n");
    return false;
  }

  stringValue = rbTreeToString(tree);
  if (stringValue == NULL) {
    printLog(ERR, "Got NULL pointer back from rbTreeToString.\n");
    return false;
  }
  if (strcmp(stringValue, "{\n  size=0\n  keyType=string\n}") != 0) {
    printLog(ERR, "Expected empty tree string from rbTreeToString, got \"%s\"\n", stringValue);
    return false;
  }
  stringValue = stringDestroy(stringValue);

  rbTreeDestroyNode(tree, NULL);

  if (rbTreeDestroy(tree) != NULL) {
    printLog(ERR, "rbTreeDestroy returned non-NULL value.\n");
    return false;
  }
  tree = rbTreeCreate(typeString);

  node = rbTreePredecessor(tree, NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from rbTreePredecessor, got %p\n", node);
    return false;
  }

  node = rbTreeSuccessor(tree, NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from rbTreeSuccessor, got %p\n", node);
    return false;
  }

  node = rbTreeFirst(tree);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from rbTreeFirst, got %p\n", node);
    return false;
  }

  list = rbEnumerate(tree, NULL, NULL);
  if (list != NULL) {
    printLog(ERR, "Expected NULL from rbEnumerate, got %p\n", list);
    return false;
  }

  bytesValue = rbTreeToXml(tree, "element");
  if (bytesValue == NULL) {
    printLog(ERR, "Expected empty XML from rbTreeToXml, got NULL.\n");
    return false;
  }
  if (strcmp(str(bytesValue), "<element></element>") != 0) {
    printLog(ERR, "Expected empty XML from rbTreeToXml, got \"%s\".\n", stringValue);
    return false;
  }
  bytesValue = bytesDestroy(bytesValue);

  list = rbTreeToList(tree);
  if (list == NULL) {
    printLog(ERR, "Expected list from rbTreeToList, got NULL\n");
    return false;
  }
  if (list->size != 0) {
    printLog(ERR, "List size is %llu.\n", llu(list->size));
    return false;
  }
  listDestroy(list); list = NULL;

  tree2 = rbTreeCopy(tree);
  if (tree2 == NULL) {
    printLog(ERR, "Expected tree from rbTreeCopy, got NULL\n");
    return false;
  }

  if (rbTreeCompare(NULL, tree) >= 0) {
    printLog(ERR, "Non-null tree was detected to be equal or greater than NULL "
      "pointer.\n");
    return false;
  }
  if (rbTreeCompare(tree, NULL) <= 0) {
    printLog(ERR, "Non-null tree was detected to be equal or less than NULL "
      "pointer.\n");
    return false;
  }
  if (rbTreeCompare(tree, tree2) != 0) {
    printLog(ERR, "Empty tree and tree2 were computed to be unequal.\n");
    return false;
  }

  tree2 = (RedBlackTree*) rbTreeDestroy(tree2);

  rbTreeAddEntry(tree, "key2", "value2");
  rbTreeAddEntry(tree, "key1", "value1");
  rbTreeAddEntry(tree, "key3", "value3", typeString);

  tree2 = rbTreeCopy(tree);
  if (rbTreeCompare(tree, tree2) != 0) {
    printLog(ERR, "Populated tree and tree2 were computed to be unequal after rbTreeCopy.\n");
    return false;
  }
  tree2 = (RedBlackTree*) rbTreeDestroy(tree2);
  tree2 = listToRbTree((List*) tree);
  if (rbTreeCompare(tree, tree2) != 0) {
    printLog(ERR, "Populated tree and tree2 were computed to be unequal after listToRbTree.\n");
    return false;
  }
  tree2 = (RedBlackTree*) rbTreeDestroy(tree2);

  RedBlackNode *node2 = rbQuery(tree, "key2");
  if (node2 == NULL) {
    printLog(ERR, "Expected non-NULL from rbQuery, got %p\n", node);
    return false;
  }
  node = rbTreePredecessor(tree, node2);
  if (node == NULL) {
    printLog(ERR, "Expected non-NULL from rbTreePredecessor, got %p\n", node);
    return false;
  }
  if (strcmp((char*) node->key, "key1") != 0) {
    printLog(ERR, "Expected key1 from rbTreePredecessor, got \"%s\"\n",
      (char*) node->key);
    return false;
  }

  node = rbTreeSuccessor(tree, node2);
  if (node == NULL) {
    printLog(ERR, "Expected non-NULL from rbTreeSuccessor, got %p\n", node);
    return false;
  }
  if (strcmp((char*) node->key, "key3") != 0) {
    printLog(ERR, "Expected key3 from rbTreePredecessor, got \"%s\"\n",
      (char*) node->key);
    return false;
  }

  node = rbTreeFirst(tree);
  if (node == NULL) {
    printLog(ERR, "Expected non-NULL from rbTreeFirst, got %p\n", node);
    return false;
  }
  if (strcmp((char*) node->key, "key1") != 0) {
    printLog(ERR, "Expected key1 from rbTreeFirst, got \"%s\"\n",
      (char*) node->key);
    return false;
  }

  list = rbEnumerate(tree, "key1", "key3");
  if (list == NULL) {
    printLog(ERR, "Expected non-NULL from rbEnumerate, got %p\n", list);
    return false;
  }
  if (list->size != 3) {
    printLog(ERR, "Expected list of size 3 from rbEnumerate, got list of size "
      "%llu", llu(list->size));
    return false;
  }
  ListNode *listNode = listGetFront(list);
  if (listNode == NULL) {
    printLog(ERR, "Got NULL from listGetFront.\n");
    return false;
  }
  if (strcmp((char*) listNode->key, "key1") != 0) {
    printLog(ERR, "Expected key1 as first item, got \"%s\".\n",
      (char*) listNode->key);
    return false;
  }
  listNode = listNode->next;
  if (listNode == NULL) {
    printLog(ERR, "Got NULL from first listNode->next.\n");
    return false;
  }
  if (strcmp((char*) listNode->key, "key2") != 0) {
    printLog(ERR, "Expected key2 as second item, got \"%s\".\n",
      (char*) listNode->key);
    return false;
  }
  listNode = listNode->next;
  if (listNode == NULL) {
    printLog(ERR, "Got NULL from second listNode->next.\n");
    return false;
  }
  if (strcmp((char*) listNode->key, "key3") != 0) {
    printLog(ERR, "Expected key3 as third item, got \"%s\".\n",
      (char*) listNode->key);
    return false;
  }
  listNode = listNode->next;
  if (listNode != NULL) {
    printLog(ERR, "Got \"%s\" from third listNode->next.\n",
      (char*) listNode->key);
    return false;
  }
  listDestroy(list);

  node = rbTreeLast(NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from rbTreeLast, got %p\n", node);
    return false;
  }
  node = rbTreeLast(tree);
  if (node == NULL) {
    printLog(ERR, "Expected non-NULL from rbTreeLast, got NULL\n");
    return false;
  }
  if (strcmp((char*) node->key, "key3") != 0) {
    printLog(ERR, "Expected key3 from rbTreeLast, got \"%s\"\n",
      (char*) node->key);
    return false;
  }

  node = rbQuery(tree, "key1");
  if (node == NULL) {
    printLog(ERR, "Expected non-NULL from rbQuery, got NULL\n");
    return false;
  }
  if (strcmp((char*) node->key, "key1") != 0) {
    printLog(ERR, "Expected key1 from rbQuery, got \"%s\"\n",
      (char*) node->key);
    return false;
  }

  if (rbTreeRemove(tree, "key2") != 0) {
    printLog(ERR, "Could not remove key2 from tree.\n");
    return false;
  }

  tree = (RedBlackTree*) rbTreeDestroy(tree);

  tree = rbTreeCreate(typeI32);
  for (int i = 1; i < 100; i++) {
    rbTreeAddEntry(tree, &i, &i);
  }
  for (int i = -1; i > -100; i--) {
    rbTreeAddEntry(tree, &i, &i);
  }
  list = rbTreeToList(tree);
  if (list == NULL) {
    printLog(ERR, "rbTreeToList did not populate a list.\n");
    return false;
  } else if (list->size != 198) {
    printLog(ERR, "rbTreeToList returned a %llu element list, expected 198 elements."
      "\n", llu(list->size));
    i32 array[199] = {0};
    for (ListNode *node = list->head; node != NULL; node = node->next) {
      array[*((i32*) node->value) + 99]++;
    }
    printLog(ERR, "Not seen:\n");
    for (int i = 0; i < 199; i++) {
      if ((array[i] == 0) && (i != 99)) {
        printLog(ERR, "%d\n", i - 99);
      }
    }
    return false;
  }
  listDestroy(list); list = NULL;
  tree = (RedBlackTree*) rbTreeDestroy(tree);

  const char *jsonString = "{\n"
    "  \"myRedBlackTree1\": {\n"
    "    \"key1\":1,\n"
    "    \"key2\":-2.0\n"
    "  },\n"
    "  \"key3\":-1E3,\n"
    "  \"myRedBlackTree2\": {\n"
    "    \"key4\":\"value4\",\n"
    "    \"key5\":\"value5\",\n"
    "    \"key6\":\"value6\"\n"
    "  },\n"
    "  \"myRedBlackTree3\":{\n"
    "    \"myRedBlackTree4\":{\n"
    "      \"key7\": \"value7\",\n"
    "      \"key8\": \"value8\"\n"
    "    },\n"
    "    \"key9\":\"value9\"\n"
    "  }\n"
    "}";
  long long int startPosition = 0;
  tree = jsonToRedBlackTree(jsonString, &startPosition);
  if (tree == NULL) {
    printLog(ERR, "jsonToRedBlackTree returned NULL.\n");
    return false;
  }
  Bytes byteArray = typeRedBlackTree->toBlob(tree);
  u64 length = bytesLength(byteArray);
  tree = rbTreeDestroy(tree);
  tree = rbTreeFromBlob(byteArray, &length, true);
  stringValue = rbTreeToString(tree);
  printLog(INFO, "Table: %s\n", stringValue);
  stringValue = stringDestroy(stringValue);
  stringValue = (char*) rbTreeGetValue(tree, "key3");
  if (stringValue == NULL) {
    printLog(ERR, "Value for key3 was NULL.\n");
    return false;
  } else if (*((double*) stringValue) != -1E3) {
    printLog(ERR, "Expected \"value3\", got \"%s\".\n", stringValue);
    return false;
  }
  tree2 = (RedBlackTree*) rbTreeGetValue(tree, "myRedBlackTree1");
  if (tree2 == NULL) {
    printLog(ERR, "Value for myRedBlackTree1 was NULL.\n");
    return false;
  } else if (rbTreeGetEntry(tree, "myRedBlackTree1")->type != typeRedBlackTree) {
    printLog(ERR, "Expected myRedBlackTree1 to be \"%s\", found \"%s\".\n",
      typeRedBlackTree->name, rbTreeGetEntry(tree, "myRedBlackTree1")->type->name);
    return false;
  }
  stringValue = (char*) rbTreeGetValue(tree2, "key1");
  if (stringValue == NULL) {
    printLog(ERR, "Value for key1 was NULL.\n");
    return false;
  } else if (*((i64*) stringValue) != 1) {
    printLog(ERR, "Expected 1, got %lld.\n", lld(*((i64*) stringValue)));
    return false;
  }
  stringValue = (char*) rbTreeGetValue(tree2, "key2");
  if (stringValue == NULL) {
    printLog(ERR, "Value for key2 was NULL.\n");
    return false;
  } else if (*((double*) stringValue) != -2.0) {
    printLog(ERR, "Expected -2.0, got %lf.\n", *((double*) stringValue));
    return false;
  }
  stringValue = (char*) rbTreeGetValue(tree2, "key6");
  tree2 = (RedBlackTree*) rbTreeGetValue(tree, "myRedBlackTree2");
  if (tree2 == NULL) {
    printLog(ERR, "Value for myRedBlackTree2 was NULL.\n");
    return false;
  } else if (rbTreeGetEntry(tree, "myRedBlackTree2")->type != typeRedBlackTree) {
    printLog(ERR, "Expected myRedBlackTree2 to be \"%s\", found \"%s\".\n",
      typeRedBlackTree->name, rbTreeGetEntry(tree, "myRedBlackTree2")->type->name);
    return false;
  }
  stringValue = (char*) rbTreeGetValue(tree2, "key4");
  if (stringValue == NULL) {
    printLog(ERR, "Value for key4 was NULL.\n");
    return false;
  } else if (strcmp(stringValue, "value4") != 0) {
    printLog(ERR, "Expected \"value4\", got \"%s\".\n", stringValue);
    return false;
  }
  stringValue = (char*) rbTreeGetValue(tree2, "key5");
  if (stringValue == NULL) {
    printLog(ERR, "Value for key5 was NULL.\n");
    return false;
  } else if (strcmp(stringValue, "value5") != 0) {
    printLog(ERR, "Expected \"value5\", got \"%s\".\n", stringValue);
    return false;
  }
  stringValue = (char*) rbTreeGetValue(tree2, "key6");
  if (stringValue == NULL) {
    printLog(ERR, "Value for key6 was NULL.\n");
    return false;
  } else if (strcmp(stringValue, "value6") != 0) {
    printLog(ERR, "Expected \"value6\", got \"%s\".\n", stringValue);
    return false;
  }
  tree2 = (RedBlackTree*) rbTreeGetValue(tree, "myRedBlackTree3");
  if (tree2 == NULL) {
    printLog(ERR, "Value for myRedBlackTree3 was NULL.\n");
    return false;
  } else if (rbTreeGetEntry(tree, "myRedBlackTree3")->type != typeRedBlackTree) {
    printLog(ERR, "Expected myRedBlackTree3 to be \"%s\", found \"%s\".\n",
      typeRedBlackTree->name, rbTreeGetEntry(tree, "myRedBlackTree3")->type->name);
    return false;
  }
  stringValue = (char*) rbTreeGetValue(tree2, "key9");
  if (stringValue == NULL) {
    printLog(ERR, "Value for key9 was NULL.\n");
    return false;
  } else if (strcmp(stringValue, "value9") != 0) {
    printLog(ERR, "Expected \"value9\", got \"%s\".\n", stringValue);
    return false;
  }
  if (rbTreeGetValue(tree2, "myRedBlackTree4") == NULL) {
    printLog(ERR, "Value for myRedBlackTree4 was NULL.\n");
    return false;
  } else if (rbTreeGetEntry(tree2, "myRedBlackTree4")->type != typeRedBlackTree) {
    printLog(ERR, "Expected myRedBlackTree4 to be \"%s\", found \"%s\".\n",
      typeRedBlackTree->name, rbTreeGetEntry(tree, "myRedBlackTree4")->type->name);
    return false;
  }
  tree2 = (RedBlackTree*) rbTreeGetValue(tree2, "myRedBlackTree4");
  stringValue = (char*) rbTreeGetValue(tree2, "key7");
  if (stringValue == NULL) {
    printLog(ERR, "Value for key7 was NULL.\n");
    return false;
  } else if (strcmp(stringValue, "value7") != 0) {
    printLog(ERR, "Expected \"value7\", got \"%s\".\n", stringValue);
    return false;
  }
  stringValue = (char*) rbTreeGetValue(tree2, "key8");
  if (stringValue == NULL) {
    printLog(ERR, "Value for key8 was NULL.\n");
    return false;
  } else if (strcmp(stringValue, "value8") != 0) {
    printLog(ERR, "Expected \"value8\", got \"%s\".\n", stringValue);
    return false;
  }
  byteArray = bytesDestroy(byteArray);

  if (tree->size == 0) {
    printLog(ERR, "Expected tree->size is 0.\n");
    return false;
  }
  if (rbTreeClear(tree) != 0) {
    printLog(ERR, "rbTreeClear failed.\n");
    return false;
  }

  if (typeRbTree->size(tree) != sizeof(RedBlackTree)) {
    printLog(ERR, "Expected typeRbTree->size(tree) to return %d, got %d.\n",
      (int) sizeof(RedBlackTree), (int) typeRbTree->size(tree));
    return false;
  } else if (typeRbTree->size(NULL) != 0) {
    printLog(ERR, "Expected typeRbTree->size(NULL) to return 0, got %d.\n",
      (int) typeRbTree->size(tree));
    return false;
  }

  tree = rbTreeDestroy(tree);

  return true;
}

