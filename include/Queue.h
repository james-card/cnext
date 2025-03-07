///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              02.23.2019
///
/// @file              Queue.h
///
/// @brief             These are the functions and data structures that make
///                    up the queue data structure.
///
/// @details           This functionality is built on top of list data
///                    structure functionality and support.
///
/// @copyright
///                   Copyright (c) 2012-2025 James Card
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

#ifndef QUEUE_H
#define QUEUE_H

#include "StringLib.h"
#include "DataTypes.h"
#include "List.h"

#ifdef __cplusplus
extern "C"
{
#endif

Queue* queueCreate(TypeDescriptor *dataType);
QueueNode* queuePushEntry_(Queue *queue,
  const volatile void *data, TypeDescriptor *type, ...);
#define queuePushEntry(queue, data, ...) queuePushEntry_(queue, data, ##__VA_ARGS__, NULL)
void* queuePop(Queue *queue);
Queue* queueDestroy(Queue *queue);
#define queueToString(queue) listToString((List*) queue)
int queueFlush(Queue *queue, int numItems);
#define queueFlushAll(queue) \
  queueFlush(queue, (queue != NULL) ? queue->size : 0)
#define queueToJson(queue) listToJson((List*) queue)
#define queueIsEmpty(queue) (listLength((List*) queue) == 0)
#define queueLength(queue) listLength((List*) queue)
#define queueCompare(queueA, queueB) \
  listCompare((List*) queueA, (List*) queueB)
bool queueUnitTest();

#ifdef __cplusplus
} // extern "C"
#endif

#if (defined __cplusplus) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 201710L)

// This must come last and must come outside the extern "C" block.
#include "TypeSafeQueuePush.h"

#endif // TypeSafeQueuePush.h

#endif // QUEUE_H

