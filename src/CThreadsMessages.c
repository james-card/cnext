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

#include "CThreadsMessages.h"

#if LOGGING_ENABLED && CTHREADS_LOGGING_ENABLED
#include "LoggingLib.h"
#else
#undef printLog
#define printLog(...) {}
#define logFile stderr
#define LOG_MALLOC_FAILURE(...) {}
#endif

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct thrd_msg_q_t thrd_msg_q_t;
void thrd_msg_q_storage_init(void);
int thrd_msg_q_create(void);
int thrd_msg_q_destroy(thrd_msg_q_t *queue);

#ifdef __cplusplus
}
#endif

/// @var thrd_msg_q_storage_initialized
///
/// @brief once_flag to keep track of whether or not the root storage for thread
/// message queues has been created.
once_flag thrd_msg_q_storage_initialized = ONCE_FLAG_INIT;

/// @var message_queues
///
/// @brief Root storage for the message queues.  Keys are thrd_t values.  Values
/// are thrd_msg_q_t values.  There is one thrd_msg_q_t in the tree for ever
/// thread that is currently running.  Queues are created when a thread starts
/// and destroyed when it exits.
Trie *message_queues = NULL;

// Message queue functions

/// @fn void thrd_msg_q_storage_init(void)
///
/// @brief call_once function that initializes the message_queues radix tree
/// storage that will be used to hold the queues for each thread.
///
/// @return This function returns no value.
void thrd_msg_q_storage_init(void) {
  message_queues = trieCreate(NULL);
  if (message_queues == NULL) {
    // No tree.  Can't proceed.
    LOG_MALLOC_FAILURE();
    exit(1);
  }
  
  return;
}

/// @fn int thrd_msg_q_create(void)
///
/// @brief Dynamically allocate and initialize a thrd_msg_q_t that will server as the
/// message queue for the current thread and associate it with this thread's
/// thrd_t value in the message_queues radix tree.
///
/// @return Returns thrd_success on success, thrd_error on failure.
int thrd_msg_q_create(void) {
  int return_value = thrd_success;
  thrd_msg_q_t *old_queue = NULL;
  
  if (get_thread_thrd_msg_q() != NULL) {
    // This should be impossible, but already have a queue for this thread.
    // Nothing to do.
    return return_value; // thrd_success
  }
  
  thrd_t thr = thrd_current();
  thrd_msg_q_t *new_queue = (thrd_msg_q_t*) calloc(1, sizeof(thrd_msg_q_t));
  if (new_queue == NULL) {
    goto new_queue_calloc_failure;
  }
  
  // new_queue->head and new_queue->tail are initialized to NULL by the
  // calloc call.
  if (cnd_init(&new_queue->condition) != thrd_success) {
    // Can't proceed.  Bail.
    goto cnd_init_failure;
  }
  
  if (mtx_init(&new_queue->lock, mtx_plain | mtx_timed)
    != thrd_success
  ) {
    // Can't proceed.  Bail.
    goto mtx_init_failure;
  }
  
  old_queue =
    (thrd_msg_q_t*) trieSetValue(message_queues, &thr, sizeof(thr), new_queue);
  if (old_queue != NULL) {
    // This shouldn't be possible, but we have to destroy the old queue.
    thrd_msg_q_destroy(old_queue);
  }
  
  return return_value; // thrd_success
  
mtx_init_failure:
  cnd_destroy(&new_queue->condition);
cnd_init_failure:
  free(new_queue); new_queue = NULL;
new_queue_calloc_failure:
  return_value = thrd_error;
  
  return return_value; // thrd_error
}

/// @fn int thrd_msg_q_destroy(thrd_msg_q_t *queue)
///
/// @brief Destroy the specified message queue.  If none is specifiied, remove
/// the queue for the current thread and destroy it.
///
/// @param queue The queue to destroy.  If this value is NULL, the message queue
/// for the current thread will be destroyed.
///
/// @return Returns thrd_success on success, thrd_error on failure.
int thrd_msg_q_destroy(thrd_msg_q_t *queue) {
  int return_value = thrd_success;
  thrd_t thr = thrd_current();
  
  // trieSetValue will do an atomic swap to keep any other thread from
  // trying to push messages onto the queue while we're in the middle of
  // deleting it.
  if (queue == NULL) {
    queue =
      (thrd_msg_q_t*) trieSetValue(message_queues, &thr, sizeof(thr), NULL);
    
    // Delete the node storage for the queue in the radix tree.
    trieDeleteValue(message_queues, &thr, sizeof(thr));
    
    if (queue == NULL) {
      // This shouldn't be possible, but there's no queue for this thread.
      // Nothing to do.
      return return_value; // thrd_success
    }
  }
  
  for (msg_t *cur = queue->head; cur != NULL; ) {
    msg_t *next = cur->next;
    msg_destroy(cur);
    cur = next;
  }
  
  mtx_destroy(&queue->lock);
  cnd_destroy(&queue->condition);
  free(queue); queue = NULL;
  
  return return_value;
}

/// @fn msg_t* thrd_msg_q_peek(void)
///
/// @brief Get the head of the current thread's message queue but do not remove
/// it from the queue.
///
/// @return Returns the head of the message queue, which may be NULL.
msg_t* thrd_msg_q_peek(void) {
  msg_t *head = NULL;
  
  thrd_msg_q_t *queue = get_thread_thrd_msg_q();
  if (queue != NULL) {
    head = queue->head;
  }
  
  return head;
}

/// @fn msg_t* thrd_msg_q_peek(void)
///
/// @brief Get the head of the current thread's message queue and remove it.
///
/// @return Returns the head of the message queue, which may be NULL.
msg_t* thrd_msg_q_pop(void) {
  thrd_msg_q_t *queue = get_thread_thrd_msg_q();
  msg_t *head = NULL;
  
  if ((queue == NULL) || (mtx_lock(&queue->lock) != thrd_success)) {
    // Error case.
    return head; // NULL
  }
  
  head = queue->head;
  if (head != NULL) {
    queue->head = head->next;
    head->next = NULL;
    
    if (queue->head == NULL) {
      // Empty queue.  Set queue->tail to NULL too.
      queue->tail = NULL;
    }
  }
  
  mtx_unlock(&queue->lock);
  
  return head;
}

/// @fn msg_t* thrd_msg_q_pop_type(int type)
///
/// @brief Get the first message of the specified type from the current
/// thread's message queue and remove it from the queue.
///
/// @param type The message type to look for.
///
/// @return Returns the first message of the queue with the specified type on
/// success, NULL on failure.
msg_t* thrd_msg_q_pop_type(int type) {
  thrd_msg_q_t *queue = get_thread_thrd_msg_q();
  msg_t *return_value = NULL;
  msg_t *prev = NULL;
  msg_t *cur = queue->head;
  msg_t **prev_next = &queue->head;
  
  if (mtx_lock(&queue->lock) != thrd_success) {
    // Error case.
    return return_value; // NULL
  }
  
  while ((cur != NULL) && (cur->type != type)) {
    prev = cur;
    prev_next = &cur->next;
    cur = cur->next;
  }
  
  if (cur != NULL) {
    // Desired type was found.  Remove the message from the queue.
    return_value = cur;
    *prev_next = cur->next;
    
    if (queue->head == NULL) {
      // Empty queue.  Set queue->tail to NULL too.
      queue->tail = NULL;
    }
    if (queue->tail == cur) {
      queue->tail = prev;
    }
    cur->next = NULL;
  }
  
  mtx_unlock(&queue->lock);
  
  return return_value;
}

/// @fn msg_t* thrd_msg_q_wait_for_type_(int *type, const struct timespec *ts)
///
/// @brief Wait for a message of a given type to be available in the message
/// queue or until a specified time has elapsed.  Remove the message from the
/// queue and return it if one is available before the specified time is
/// reached.
///
/// @param type A pointer to the message type to look for.  If this parameter is
///   NULL then the first message of any type will be returned.
/// @param ts A pointer to a struct timespec that specifies the end of the time
///   period to wait for.  If this parameter is NULL then an infinite timeout
///   will be used.
///
/// @return Returns the first message of the provided type if one is available
/// before the specified time.  Returns NULL if no such message is available
/// within that time period or if an error occurrs.
msg_t* thrd_msg_q_wait_for_type_(int *type, const struct timespec *ts) {
  thrd_msg_q_t *queue = get_thread_thrd_msg_q();
  msg_t *return_value = NULL;
  msg_t *prev = NULL;
  msg_t *cur = queue->head;
  msg_t **prev_next = &queue->head;
  int lock_status = thrd_success;
  int wait_status = thrd_success;
  int search_type = 0;
  if (type != NULL) {
    // This saves us from having to dereference the pointer on each iteration
    // of the loop below.
    search_type = *type;
  }
  
  if (ts == NULL) {
    lock_status = mtx_lock(&queue->lock);
  } else {
    lock_status = mtx_timedlock(&queue->lock, ts);
  }
  if (lock_status != thrd_success) {
    // Error case.
    return return_value; // NULL
  }
  // mtx_timedlock will return thrd_timedout if the timeout is reached, so we'll
  // never reach this point if we've exceeded our timeout.
  
  while (return_value == NULL) {
    while ((cur != NULL) && (type != NULL) && (cur->type != search_type)) {
      prev = cur;
      prev_next = &cur->next;
      cur = cur->next;
    }
    
    if (cur != NULL) {
      // Desired type was found.  Remove the message from the queue.
      return_value = cur;
      *prev_next = cur->next;
      
      if (queue->head == NULL) {
        // Empty queue.  Set queue->tail to NULL too.
        queue->tail = NULL;
      }
      if (queue->tail == cur) {
        queue->tail = prev;
      }
      cur->next = NULL;
    } else {
      // Desired type was not found.  Block until something else is pushed.
      if (ts == NULL) {
        wait_status = cnd_wait(&queue->condition, &queue->lock);
      } else {
        wait_status = cnd_timedwait(&queue->condition, &queue->lock, ts);
      }
      if (wait_status != thrd_success) {
        break;
      }
      // cnd_timedwait will return thrd_timedout if the timeout is reached, so
      // we won't continue the loop if we've exceeded our timeout.
    }
    
    prev = NULL;
    cur = queue->head;
    prev_next = &queue->head;
  }
  
  mtx_unlock(&queue->lock);
  
  return return_value;
}

/// @fn msg_t* thrd_msg_q_wait(const struct timespec *ts)
///
/// @brief Wait until there is a message in the queue or until a specified has
/// been reached.  If there is a message in the queue before the timeout, pop
/// it from the queue.
///
/// @param ts A pointer to a struct timespec that specifies the end of the time
///   period to wait for.  If this parameter is NULL then an infinite timeout
///   will be used.
///
/// @return Returns the first message in the queue if one is available before
/// the specified time.  Returns NULL if no such message is available within
/// that time period or if an error occurrs.
msg_t* thrd_msg_q_wait(const struct timespec *ts) {
  return thrd_msg_q_wait_for_type_(NULL, ts);
}

/// @fn msg_t* thrd_msg_q_wait_for_type(int type, const struct timespec *ts)
///
/// @brief Wait until there is a message of a specified type in the queue or
/// until a specified has been reached.  If there is a message of the specified
/// type in the queue before the timeout, pop it from the queue.
///
///
/// @param type The message type to look for.
/// @param ts A pointer to a struct timespec that specifies the end of the time
///   period to wait for.  If this parameter is NULL then an infinite timeout
///   will be used.
///
/// @return Returns the first message of the provided type if one is available
/// before the specified time.  Returns NULL if no such message is available
/// within that time period or if an error occurrs.
msg_t* thrd_msg_q_wait_for_type(int type, const struct timespec *ts) {
  return thrd_msg_q_wait_for_type_(&type, ts);
}


/// @fn int thrd_msg_q_push(thrd_t thr, msg_t *msg)
///
/// @brief Push a message onto the message queue of a specified thread.
///
/// @param thr The thrd_t that identifies the destination thread.
/// @param msg A pointer to the msg_t to push onto the destination thread's
/// message queue.
///
/// @return Returns thrd_success on success, thrd_error on failure.
int thrd_msg_q_push(thrd_t thr, msg_t *msg) {
  int return_value = thrd_error;
  
  if (msg == NULL) {
    // Invalid.
    return return_value; // thrd_error
  }
  
  thrd_msg_q_t *queue
    = (thrd_msg_q_t*) trieGetValue(message_queues, &thr, sizeof(thr));
  if (queue == NULL) {
    // Destination thread has exited.  Fail.
    return return_value; // thrd_error
  }
  
  if (mtx_lock(&queue->lock) != thrd_success) {
    // Error case.
    return return_value; // thrd_error
  }
  
  msg->thrd_from = thrd_current();
  msg->thrd_to = thr;
  msg->next = NULL;
  if (queue->tail != NULL) {
    queue->tail->next = msg;
    queue->tail = msg;
  } else {
    // Empty queue.  Populate both queue->head and queue->tail.
    queue->head = msg;
    queue->tail = msg;
  }
  msg->recipient = MESSAGE_RECIPIENT_THREAD;
  
  // Let all the waiters know that there's something new in the queue now.
  return_value = cnd_broadcast(&queue->condition);
  
  mtx_unlock(&queue->lock);
  
  return return_value;
}

