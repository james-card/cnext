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

#include "Queue.h"
#include "LoggingLib.h"

bool queueUnitTest(void) {
  Queue *queue = NULL;
  QueueNode *node = NULL;

  printLog(INFO, "Testing Queue data structure.\n");

  printLog(INFO, "Creating queue with NULL type descriptor.\n");
  queue = queueCreate(NULL);
  if (queue != NULL) {
    printLog(ERR, "Expected NULL queue, but got non-NULL queue.\n");
    return false;
  }

  printLog(INFO, "Pushing NULL onto NULL queue.\n");
  node = queuePushEntry(queue, NULL);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from queuePushEntry, got %p.\n", node);
    return false;
  }

  printLog(INFO, "Popping NULL queue.\n");
  node = (QueueNode*) queuePop(queue);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from queuePop, got %p.\n", node);
    return false;
  }

  printLog(INFO, "Destroying NULL queue.\n");
  queue = (Queue*) queueDestroy(queue);
  if (queue != NULL) {
    printLog(ERR, "Expected NULL queue, but got non-NULL queue.\n");
    return false;
  }

  printLog(INFO, "Creating empty queue.\n");
  queue = queueCreate(typeString);
  if (queue == NULL) {
    printLog(ERR, "Expected non-NULL queue, but got NULL queue.\n");
    return false;
  }

  printLog(INFO, "Pushing NULL onto empty queue.\n");
  node = queuePushEntry(queue, NULL);
  if (node == NULL) {
    printLog(ERR, "Expected non-NULL from queuePushEntry, got NULL.\n");
    return false;
  }
  queue = (Queue*) queueDestroy(queue);
  queue = queueCreate(typeString);

  printLog(INFO, "Popping empty queue.\n");
  node = (QueueNode*) queuePop(queue);
  if (node != NULL) {
    printLog(ERR, "Expected NULL from queuePop, got %p.\n", node);
    return false;
  }

  queuePushEntry(queue, "one");
  queuePushEntry(queue, "two");
  queuePushEntry(queue, "three");
  if (queueLength(queue) != 3) {
    printLog(ERR, "Expected 3 elements in queue, found %llu.\n",
      llu(queueLength(queue)));
  }
  char *queueTop = (char*) queuePop(queue);
  if (queueTop == NULL) {
    printLog(ERR, "Expected \"one\" from queue.  Got NULL.\n");
    return false;
  }
  if (strcmp(queueTop, "one") != 0) {
    printLog(ERR, "Expected \"one\" from queue.  Got \"%s\".\n", queueTop);
    return false;
  }
  printLog(INFO, "Top of queue was \"one\".");
  queueTop = stringDestroy(queueTop);
  queueTop = (char*) queuePop(queue);
  if (queueTop == NULL) {
    printLog(ERR, "Expected \"two\" from queue.  Got NULL.\n");
    return false;
  }
  if (strcmp(queueTop, "two") != 0) {
    printLog(ERR, "Expected \"two\" from queue.  Got \"%s\".\n", queueTop);
    return false;
  }
  printLog(INFO, "Top of queue was \"two\".");
  queueTop = stringDestroy(queueTop);
  queueTop = (char*) queuePop(queue);
  if (queueTop == NULL) {
    printLog(ERR, "Expected \"three\" from queue.  Got NULL.\n");
    return false;
  }
  if (strcmp(queueTop, "three") != 0) {
    printLog(ERR, "Expected \"three\" from queue.  Got \"%s\".\n", queueTop);
    return false;
  }
  printLog(INFO, "Top of queue was \"three\".");
  queueTop = stringDestroy(queueTop);
  if (!queueIsEmpty(queue)) {
    printLog(ERR, "Queue is not empty as expected.\n");
    return false;
  }

  printLog(INFO, "Rebuilding three-item queue.\n");
  queuePushEntry(queue, "one");
  queuePushEntry(queue, "two");
  queuePushEntry(queue, "three");

  printLog(INFO, "Converting queue to byte array.\n");
  Bytes byteArray = typeQueue->toBlob(queue);
  u64 length = bytesLength(byteArray);
  printLog(INFO, "Converting byte array to queue.\n");
  Queue *queue2 = (Queue*) typeQueue->fromBlob(byteArray, &length, false, false);
  if (queueCompare(queue, queue2) != 0) {
    printLog(ERR, "queue and queue2 were not identical.\n");
    return false;
  }
  byteArray = bytesDestroy(byteArray);
  queue2 = (Queue*) queueDestroy(queue2);
  if (queue2 != NULL) {
    printLog(ERR, "Could not destroy queue2.\n");
    return false;
  }
 
  printLog(INFO, "Flushing entire queue.\n");
  queueFlushAll(queue);

  printLog(INFO, "Destroying empty queue.\n");
  queue = (Queue*) queueDestroy(queue);
  if (queue != NULL) {
    printLog(ERR, "Expected NULL queue, but got non-NULL queue.\n");
    return false;
  }

  return true;
}

