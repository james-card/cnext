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
#include "Trie.h"

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

void thrd_msg_q_storage_init(void);
int thrd_msg_q_create(void);
int thrd_msg_q_destroy(msg_q_t *queue);

#ifdef __cplusplus
}
#endif

/// @var message_queues
///
/// @brief Root storage for the message queues.  Keys are thrd_t values.  Values
/// are msg_q_t values.  There is one msg_q_t in the tree for every thread that
/// is currently running.  Queues are created when a thread starts and destroyed
/// when it exits.
static Trie *message_queues = NULL;

/// @fn msg_q_t* get_thread_thrd_msg_q(void)
///
/// @brief Get the message queue for the current thread.
///
/// @return Returns a pointer to the msg_q_t for the thread making this call.
/// This should always be a non-NULL value unless something is wrong with the
/// system.
static inline msg_q_t* get_thread_thrd_msg_q(void) {
  thrd_t thr = thrd_current();
  return (msg_q_t*) trieGetValue(message_queues, &thr, sizeof(thr));
}

/// @var thrd_msg_q_storage_initialized
///
/// @brief once_flag to keep track of whether or not the root storage for thread
/// message queues has been created.
once_flag thrd_msg_q_storage_initialized = ONCE_FLAG_INIT;

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

// Underlying worker function in Messages.c.  Expose the prototype here so that
// we can bypass a layer of abstraction into the Messages library.
msg_t* msg_wait_for_reply_with_type_(
  msg_q_t *queue, msg_t *sent, bool release,
  int *type, const struct timespec *ts);

/// @fn msg_t* thrd_msg_wait_for_reply(msg_t *sent, bool release,
///   const struct timespec *ts)
///
/// @brief Block until a reply has been received from the original recipient of
/// the provided message or until a specified future time has been reached.
///
/// @param sent The message that was originally sent to the recipient.
/// @param release Whether or not the provided sent message should be released
///   (*NOT* destroyed) after the recipient has indicated that they're done
///   processing our sent message.
/// @param ts A pointer to a struct timespec that holds the end time to wait
///   until for a reply.  If this parameter is NULL, then an infinite timeout
///   will be used.
///
/// @return Returns a pointer to the msg_t received from the recipient of
/// the original message on success, NULL on failure.
msg_t* thrd_msg_wait_for_reply(msg_t *sent, bool release,
  const struct timespec *ts
) {
  msg_q_t *queue = get_thread_thrd_msg_q();
  return msg_wait_for_reply_with_type_(queue, sent, release, NULL, ts);
}

/// @fn msg_t* thrd_msg_wait_for_reply_with_type(msg_t *sent, bool release,
///   int type, const struct timespec *ts)
///
/// @brief Block until a reply of a specified type has been received from the
/// original recipient of the provided message or until a specified future time
/// has been reached.
///
/// @param sent The message that was originally sent to the recipient.
/// @param release Whether or not the provided sent message should be released
///   (*NOT* destroyed) after the recipient has indicated that they're done
///   processing our sent message.
/// @param type An integer type of message that the caller is waiting for.
/// @param ts A pointer to a struct timespec that holds the end time to wait
///   until for a reply.  If this parameter is NULL, then an infinite timeout
///   will be used.
///
/// @return Returns a pointer to the msg_t received from the recipient of
/// the original message of the specified tyep on success, NULL on failure or if
/// the provided timeout time is reached.
msg_t* thrd_msg_wait_for_reply_with_type(msg_t *sent, bool release, int type,
  const struct timespec *ts
) {
  msg_q_t *queue = get_thread_thrd_msg_q();
  return msg_wait_for_reply_with_type_(queue, sent, release, &type, ts);
}

/// @fn int thrd_msg_q_create(void)
///
/// @brief Dynamically allocate and initialize a msg_q_t that will serve as the
/// message queue for the current thread and associate it with this thread's
/// thrd_t value in the message_queues radix tree.
///
/// @return Returns thrd_success on success, thrd_error on failure.
int thrd_msg_q_create(void) {
  int return_value = thrd_success;
  msg_q_t *old_queue = NULL;
  
  if (get_thread_thrd_msg_q() != NULL) {
    // This should be impossible, but already have a queue for this thread.
    // Nothing to do.
    return return_value; // thrd_success
  }
  
  thrd_t thr = thrd_current();
  msg_q_t *new_queue = msg_q_create(NULL, MSG_THRD_SAFE, NULL, NULL);
  if (new_queue == NULL) {
    goto new_queue_calloc_failure;
  }
  
  old_queue =
    (msg_q_t*) trieSetValue(message_queues, &thr, sizeof(thr), new_queue);
  if (old_queue != NULL) {
    // This shouldn't be possible, but we have to destroy the old queue.
    thrd_msg_q_destroy(old_queue);
  }
  
  return return_value; // thrd_success
  
new_queue_calloc_failure:
  return_value = thrd_error;
  
  return return_value; // thrd_error
}

/// @fn int thrd_msg_q_destroy(msg_q_t *queue)
///
/// @brief Destroy the specified message queue.  If none is specifiied, remove
/// the queue for the current thread and destroy it.
///
/// @param queue The queue to destroy.  If this value is NULL, the message queue
/// for the current thread will be destroyed.
///
/// @return Returns thrd_success on success, thrd_error on failure.
int thrd_msg_q_destroy(msg_q_t *queue) {
  int return_value = thrd_success;
  thrd_t thr = thrd_current();
  
  // trieSetValue will do an atomic swap to keep any other thread from
  // trying to push messages onto the queue while we're in the middle of
  // deleting it.
  if (queue == NULL) {
    queue =
      (msg_q_t*) trieSetValue(message_queues, &thr, sizeof(thr), NULL);
    
    // Delete the node storage for the queue in the radix tree.
    trieDeleteValue(message_queues, &thr, sizeof(thr));
    
    if (queue == NULL) {
      // This shouldn't be possible, but there's no queue for this thread.
      // Nothing to do.
      return return_value; // thrd_success
    }
  }

  return_value = msg_q_destroy(queue);
  
  return return_value;
}

/// @fn msg_t* thrd_msg_q_peek(void)
///
/// @brief Get the head of the current thread's message queue but do not remove
/// it from the queue.
///
/// @return Returns the head of the message queue, which may be NULL.
msg_t* thrd_msg_q_peek(void) {
  msg_q_t *queue = get_thread_thrd_msg_q();
  return msg_q_peek(queue);
}

/// @fn msg_t* thrd_msg_q_peek(void)
///
/// @brief Get the head of the current thread's message queue and remove it.
///
/// @return Returns the head of the message queue, which may be NULL.
msg_t* thrd_msg_q_pop(void) {
  msg_q_t *queue = get_thread_thrd_msg_q();
  return msg_q_pop(queue);
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
  msg_q_t *queue = get_thread_thrd_msg_q();
  return msg_q_pop_type(queue, type);
}

// Underlying worker function in Messages.c.  Expose the prototype here so that
// we can bypass a layer of abstraction into the Messages library.
msg_t* msg_q_wait_for_type_(msg_q_t *queue, int *type,
  const struct timespec *ts);

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
  msg_q_t *queue = get_thread_thrd_msg_q();
  return msg_q_wait_for_type_(queue, NULL, ts);
}

/// @fn msg_t* thrd_msg_q_wait_for_type(int type, const struct timespec *ts)
///
/// @brief Wait until there is a message of a specified type in the queue or
/// until a specified has been reached.  If there is a message of the specified
/// type in the queue before the timeout, pop it from the queue.
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
  msg_q_t *queue = get_thread_thrd_msg_q();
  return msg_q_wait_for_type_(queue, &type, ts);
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
  
  msg_q_t *queue
    = (msg_q_t*) trieGetValue(message_queues, &thr, sizeof(thr));
  if (queue == NULL) {
    // Destination thread has exited.  Fail.
    return return_value; // thrd_error
  }
  
  msg->from.thrd = thrd_current();
  msg->to.thrd = thr;
  
  return msg_q_push(queue, msg);
}

