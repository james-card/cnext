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
#ifdef DS_LOGGING_ENABLED
#include "LoggingLib.h"
#else
#undef printLog
#define printLog(...) {}
#define logFile stderr
#endif

/// @fn Queue *queueCreate(TypeDescriptor *dataType)
///
/// @brief Allocate a new Queue data structure.
///
/// @param dataType specifies the kind of data this queue handles.
///
/// @return Returns a pointer to a new Queue data structure.
///
/// @note This implementation uses List as the backing infrastructure.
Queue *queueCreate(TypeDescriptor *dataType) {
  printLog(TRACE, "ENTER queueCreate(dataType=%s)\n",
    (dataType == NULL) ? "NULL" : dataType->name);
  
  Queue *queue = (Queue*) listCreate(dataType);
  
  printLog(TRACE, "EXIT queueCreate(dataType=%s) = {%p}\n",
    (dataType == NULL) ? "NULL" : dataType->name, queue);
  return queue;
}

/// @fn QueueNode *queuePushEntry_(Queue *queue, const volatile void *data, TypeDescriptor *type, ...)
///
/// @brief Push a new data item onto the back of the Queue.
///
/// @param queue The Queue to push data to.
/// @param data The new data item to add to the Queue.
/// @param type The TypeDescriptor for the data.  This parameter is optional.
/// @param ... All further arguments are ignored.
///
/// @note This function is wrapped by a #define (without the leading underscore)
/// that automatically appends a null when the stack and data are provided and
/// provides a type if it is provided.
///
/// @return Returns a pointer to the newly-added QueueNode in the Queue.
QueueNode *queuePushEntry_(Queue *queue, const volatile void *data,
  TypeDescriptor *type, ...
) {
  printLog(TRACE, "ENTER queuePushEntry(queue=%p, data=%p)\n", queue, data);
  
  QueueNode *returnValue
    = (QueueNode*) listAddBackEntry((List*) queue, NULL, data, type);
  
  printLog(TRACE, "EXIT queuePushEntry(queue=%p, data=%p) = {%p}\n",
    queue, data, returnValue);
  return returnValue;
}

/// @fn void *queuePop(Queue *queue)
///
/// @brief Get the item at the front of the queue and remove it from the Queue.
///
/// @param queue is the Queue to retrieve data from.
///
/// @return Returns a pointer to a copy of the item at the front of the Queue.
void *queuePop(Queue *queue) {
  printLog(TRACE, "ENTER queuePop(queue=%p)\n", queue);
  
  void *returnValue = NULL;
  
  if (queue == NULL) {
    // Can't pop a NULL queue.
    printLog(TRACE, "EXIT queuePop(queue=%p) = {%p}\n", queue, returnValue);
    return returnValue;
  }
  
  mtx_lock(queue->lock);
  
  ListNode *node = listGetFront((List*) queue);
  if (node != NULL) {
    returnValue = (void*) node->value;
    node->value = NULL;
  }
  listRemoveFront((List*) queue);
  
  mtx_unlock(queue->lock);
  
  printLog(TRACE, "EXIT queuePop(queue=%p) = {%p}\n", queue, returnValue);
  return returnValue;
}

/// @fn Queue* queueDestroy(Queue *queue)
///
/// @brief Deallocate a Queue and all its subordinate data and metadata.
///
/// @param queue is the Queue to deallocate.
///
/// @return Returns a NULL pointer.
Queue* queueDestroy(Queue *queue) {
  printLog(TRACE, "ENTER queueDestroy(queue=%p)\n", queue);
  
  Queue *returnValue = (Queue*) listDestroy((List*) queue);
  
  printLog(TRACE, "EXIT queueDestroy(queue=%p) = {%p}\n",
    queue, returnValue);
  return returnValue;
}

/// @fn int queueFlush(Queue *queue, int numItems)
///
/// @brief Remove items from the queue and discard them.
///
/// @param queue The Queue to flush.
/// @param numItems The number of items to flush from the queue.
///
/// @return Returns 0 on success, -1 on failure.
int queueFlush(Queue *queue, int numItems) {
  printLog(TRACE, "ENTER queueFlush(queue=%p, numItems=%u)\n", queue, numItems);
  
  for (int i = 0; i < numItems; i++) {
    listRemoveFront((List*) queue);
  }
  
  printLog(TRACE, "EXIT queueFlush(queue=%p, numItems=%u) = {%p}\n",
    queue, numItems, (void*) NULL);
  return 0;
}

/// @var typeQueue
///
/// @brief TypeDescriptor describing how libraries should interact with
///   queue data.
TypeDescriptor _typeQueue = {
  .name          = "Queue",
  .xmlName       = NULL,
  .dataIsPointer = true,
  .toString      = (char* (*)(const volatile void*)) listToString,
  .toBytes       = (Bytes (*)(const volatile void*)) listToBytes,
  .compare       = (int (*)(const volatile void*, const volatile void*)) listCompare,
  .create        = (void* (*)(const volatile void*, ...)) queueCreate,
  .copy          = (void* (*)(const volatile void*)) listCopy,
  .destroy       = (void* (*)(volatile void*)) queueDestroy,
  .size          = listSize,
  .toBlob        = (Bytes (*)(const volatile void*)) listToBlob,
  .fromBlob      = (void* (*)(const volatile void*, u64*, bool, bool)) listFromBlob_,
  .hashFunction  = NULL,
  .clear         = (i32 (*)(volatile void *)) listClear,
  .toXml         = (Bytes (*)(const volatile void*, const char *elementName, bool indent, ...)) listToXml_,
  .toJson        = (Bytes (*)(const volatile void*)) listToJson,
};
TypeDescriptor *typeQueue = &_typeQueue;

/// @var typeQueueNoCopy
///
/// @brief TypeDescriptor describing how libraries should interact with
///   queue data that is not copied from its original source.
///
/// @details This exists because, by default, a copy of the input data is made
///   whenever a new data element is added to any data structure.  In some
///   situations, this is not desirable because the input serves no purpose
///   other than to be added to the data structure.  In such cases, this data
///   type may be specified to avoid the unnecessary copy.  The real
///   typeQueue type can then be set after the data is added.
TypeDescriptor _typeQueueNoCopy = {
  .name          = "Queue",
  .xmlName       = NULL,
  .dataIsPointer = true,
  .toString      = (char* (*)(const volatile void*)) listToString,
  .toBytes       = (Bytes (*)(const volatile void*)) listToBytes,
  .compare       = (int (*)(const volatile void*, const volatile void*)) listCompare,
  .create        = (void* (*)(const volatile void*, ...)) queueCreate,
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
TypeDescriptor *typeQueueNoCopy = &_typeQueueNoCopy;

/// @def QUEUE_UNIT_TEST
///
/// @brief Unit test for queue functionality.
/// @details Implementing this as a macro instead of raw code allows this to
/// be skipped by the code coverage metrics.
///
/// @return Returns true on success, false on failure.
#define QUEUE_UNIT_TEST \
bool queueUnitTest() { \
  Queue *queue = NULL; \
  QueueNode *node = NULL; \
 \
  printLog(INFO, "Testing Queue data structure.\n"); \
 \
  printLog(INFO, "Creating queue with NULL type descriptor.\n"); \
  queue = queueCreate(NULL); \
  if (queue != NULL) { \
    printLog(ERR, "Expected NULL queue, but got non-NULL queue.\n"); \
    return false; \
  } \
 \
  printLog(INFO, "Pushing NULL onto NULL queue.\n"); \
  node = queuePushEntry(queue, NULL); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from queuePushEntry, got %p.\n", node); \
    return false; \
  } \
 \
  printLog(INFO, "Popping NULL queue.\n"); \
  node = (QueueNode*) queuePop(queue); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from queuePop, got %p.\n", node); \
    return false; \
  } \
 \
  printLog(INFO, "Destroying NULL queue.\n"); \
  queue = (Queue*) queueDestroy(queue); \
  if (queue != NULL) { \
    printLog(ERR, "Expected NULL queue, but got non-NULL queue.\n"); \
    return false; \
  } \
 \
  printLog(INFO, "Creating empty queue.\n"); \
  queue = queueCreate(typeString); \
  if (queue == NULL) { \
    printLog(ERR, "Expected non-NULL queue, but got NULL queue.\n"); \
    return false; \
  } \
 \
  printLog(INFO, "Pushing NULL onto empty queue.\n"); \
  node = queuePushEntry(queue, NULL); \
  if (node == NULL) { \
    printLog(ERR, "Expected non-NULL from queuePushEntry, got NULL.\n"); \
    return false; \
  } \
  queue = (Queue*) queueDestroy(queue); \
  queue = queueCreate(typeString); \
 \
  printLog(INFO, "Popping empty queue.\n"); \
  node = (QueueNode*) queuePop(queue); \
  if (node != NULL) { \
    printLog(ERR, "Expected NULL from queuePop, got %p.\n", node); \
    return false; \
  } \
 \
  queuePushEntry(queue, "one"); \
  queuePushEntry(queue, "two"); \
  queuePushEntry(queue, "three"); \
  if (queueLength(queue) != 3) { \
    printLog(ERR, "Expected 3 elements in queue, found %llu.\n", \
      llu(queueLength(queue))); \
  } \
  char *queueTop = (char*) queuePop(queue); \
  if (queueTop == NULL) { \
    printLog(ERR, "Expected \"one\" from queue.  Got NULL.\n"); \
    return false; \
  } \
  if (strcmp(queueTop, "one") != 0) { \
    printLog(ERR, "Expected \"one\" from queue.  Got \"%s\".\n", queueTop); \
    return false; \
  } \
  printLog(INFO, "Top of queue was \"one\"."); \
  queueTop = stringDestroy(queueTop); \
  queueTop = (char*) queuePop(queue); \
  if (queueTop == NULL) { \
    printLog(ERR, "Expected \"two\" from queue.  Got NULL.\n"); \
    return false; \
  } \
  if (strcmp(queueTop, "two") != 0) { \
    printLog(ERR, "Expected \"two\" from queue.  Got \"%s\".\n", queueTop); \
    return false; \
  } \
  printLog(INFO, "Top of queue was \"two\"."); \
  queueTop = stringDestroy(queueTop); \
  queueTop = (char*) queuePop(queue); \
  if (queueTop == NULL) { \
    printLog(ERR, "Expected \"three\" from queue.  Got NULL.\n"); \
    return false; \
  } \
  if (strcmp(queueTop, "three") != 0) { \
    printLog(ERR, "Expected \"three\" from queue.  Got \"%s\".\n", queueTop); \
    return false; \
  } \
  printLog(INFO, "Top of queue was \"three\"."); \
  queueTop = stringDestroy(queueTop); \
  if (!queueIsEmpty(queue)) { \
    printLog(ERR, "Queue is not empty as expected.\n"); \
    return false; \
  } \
 \
  printLog(INFO, "Rebuilding three-item queue.\n"); \
  queuePushEntry(queue, "one"); \
  queuePushEntry(queue, "two"); \
  queuePushEntry(queue, "three"); \
 \
  printLog(INFO, "Converting queue to byte array.\n"); \
  Bytes byteArray = typeQueue->toBlob(queue); \
  u64 length = bytesLength(byteArray); \
  printLog(INFO, "Converting byte array to queue.\n"); \
  Queue *queue2 = (Queue*) typeQueue->fromBlob(byteArray, &length, false, false); \
  if (queueCompare(queue, queue2) != 0) { \
    printLog(ERR, "queue and queue2 were not identical.\n"); \
    return false; \
  } \
  byteArray = bytesDestroy(byteArray); \
  queue2 = (Queue*) queueDestroy(queue2); \
  if (queue2 != NULL) { \
    printLog(ERR, "Could not destroy queue2.\n"); \
    return false; \
  } \
  \
  printLog(INFO, "Flushing entire queue.\n"); \
  queueFlushAll(queue); \
 \
  printLog(INFO, "Destroying empty queue.\n"); \
  queue = (Queue*) queueDestroy(queue); \
  if (queue != NULL) { \
    printLog(ERR, "Expected NULL queue, but got non-NULL queue.\n"); \
    return false; \
  } \
 \
  return true; \
}
QUEUE_UNIT_TEST

