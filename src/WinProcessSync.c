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

#ifdef _WIN32

#include "WinProcessSync.h"
#include "WinCThreads.h"

/// @var proc_mtx_index
///
/// @brief Variable to ensure that mutexes get unique names in the system.
LONG proc_mtx_index = 0;

/// @fn int proc_mtx_init(proc_mtx_t *proc_mtx, int type)
///
/// @brief Initialize a proc_mtx_t for use with Linux futexes.
///
/// @param proc_mtx A pointer to an allocated proc_mtx_t value.
/// @param type The bitwise-OR of the proc_mtx_* values to use.
///
/// @param Returns proc_success on success, proc_error on failure.
int proc_mtx_init(proc_mtx_t *proc_mtx, int type) {
  int return_value = proc_error;

  if (proc_mtx != NULL) {
    char mutexName[35];
    sprintf(mutexName, "Global\\%uMutex%u",
      (uint32_t) GetCurrentProcessId(),
      (uint32_t) InterlockedExchangeAdd(&proc_mtx_index, 1));
    proc_mtx->lock = CreateMutex(
      NULL,     // Default security attributes
      FALSE,    // Initially not owned
      mutexName // Named mutex, shared across processes
    );
    if (proc_mtx->lock != NULL) {
      proc_mtx->flags = type;
      proc_mtx->lock_count = 0;
      return_value = proc_success;
    }
  }

  return return_value;
}

/// @fn int proc_mtx_lock(proc_mtx_t *proc_mtx)
///
/// @brief Futex-based mutex lock.
///
/// @param proc_mtx A pointer to a previously-initialized proc_mtx_t value.
///
/// @return Returns proc_success on success, error code on failure.
int proc_mtx_lock(proc_mtx_t *proc_mtx) {
  if (proc_mtx == NULL) {
    return proc_error;
  } else if ((proc_mtx->flags & proc_mtx_recursive)
    && (proc_mtx->lock_count > 0)
  ) {
    // Mutex is already locked by this process.  Just increase the lock count
    // and return success.
    proc_mtx->lock_count++;
    return proc_success;
  }

  DWORD wait_result = WaitForSingleObject(
    proc_mtx->lock, // handle to mutex
    INFINITE);      // infinite time-out interval
  if (wait_result != WAIT_OBJECT_0) {
    return proc_error;
  }

  proc_mtx->lock_count++;
  return proc_success;
}

/// int proc_mtx_unlock(proc_mtx_t *proc_mtx) {
///
/// @brief Futex-based mutex unlock.
///
/// @param proc_mtx A pointer to a locked proc_mtx_t value.
///
/// @return Returns proc_success on success, proc_error on failure.
int proc_mtx_unlock(proc_mtx_t *proc_mtx) {
  if (proc_mtx == NULL) {
    return proc_error;
  } else if (proc_mtx->lock_count == 0) {
    // Unlocking an unlocked mutex.  Nothing more to do.
    return proc_success;
  }

  proc_mtx->lock_count--;

  if (proc_mtx->lock_count == 0) {
    // Release the lock
    if (ReleaseMutex(proc_mtx->lock) == 0) {
      return proc_error;
    }
  }

  return proc_success;
}

/// @fn void proc_mtx_destroy(proc_mtx_t *proc_mtx)
///
/// @brief Release all resources that were allocated during proc_mtx_init.
///
/// @param proc_mtx A pointer to a previously-initialized proc_mtx_t value.
///
/// @return This function returns no value.
void proc_mtx_destroy(proc_mtx_t *proc_mtx) {
  if (proc_mtx != NULL) {
    // Not really necessary, but be a good citizen anyway.
    CloseHandle(proc_mtx->lock);
    proc_mtx->flags = 0;
    proc_mtx->lock_count = 0;
  }

  return;
}

/// @fn int proc_mtx_timedlock(proc_mtx_t *proc_mtx, const struct timespec *ts)
///
/// @brief Attempt to lock a mutex.  If the mutex is locked, block until it
/// becomes unlocked or until a specified future time is reached, whichever
/// comes first.
///
/// @param proc_mtx A pointer to a previously-initialized proc_mtx_t value.
/// @param ts A pointer to a struct timespec value that holds a future time by
///   which the operation must either succeed or timeout.
///
/// @return Returns proc_success if the lock is acquired before the timeout is
/// reached, proc_timeout if the timeout is reached before the lock is acquired,
/// and proc_error if the mutex is not a timed mutex, if the current system time
/// could not be acquired, or if one of the provided parameters is NULL.
int proc_mtx_timedlock(proc_mtx_t *proc_mtx, const struct timespec *ts) {
  if ((proc_mtx == NULL) || (ts == NULL)) {
    return proc_error;
  } else if ((proc_mtx->flags & proc_mtx_recursive)
    && (proc_mtx->lock_count > 0)
  ) {
    // Mutex is already locked by this process.  Just increase the lock count
    // and return success.
    proc_mtx->lock_count++;
    return proc_success;
  }

  int64_t future_nanoseconds
    = (((int64_t) ts->tv_sec) * ((int64_t) 1000000000LL))
    + ((int64_t) ts->tv_nsec);
  struct timespec now;
  int64_t now_nanoseconds = 0, delta_nanoseconds = 0;

  if (timespec_get(&now, TIME_UTC) != TIME_UTC) {
    // There's a failure with the system time.  We can't honor the timeout.
    // Fail.
    return proc_error;
  }
  now_nanoseconds
    = (((int64_t) now.tv_sec) * ((int64_t) 1000000000LL))
    + ((int64_t) now.tv_nsec);

  delta_nanoseconds = future_nanoseconds - now_nanoseconds;
  if (delta_nanoseconds <= 0) {
    delta_nanoseconds = 0;
  }

  DWORD wait_result
    = WaitForSingleObject(proc_mtx->lock, delta_nanoseconds / 1000000);
  if (wait_result == WAIT_TIMEOUT) {
    return proc_timedout;
  } else if (wait_result != WAIT_OBJECT_0) {
    return proc_error;
  }

  proc_mtx->lock_count++;
  return proc_success;
}

/// @fn int proc_mtx_trylock(proc_mtx_t *mtx)
///
/// @brief Attempt to lock a process mutex.
///
/// @param proc_mtx A pointer to a previously-initialized proc_mtx_t value.
///
/// @return Returns proc_success if the mutex is unlocked or if the current
/// process has the lock and the mutex is recursive, proc_busy if the mutex is
/// locked by antoher process, and proc_error under any other conditions.
int proc_mtx_trylock(proc_mtx_t *proc_mtx) {
  if (proc_mtx == NULL) {
    return proc_error;
  } else if ((proc_mtx->flags & proc_mtx_recursive)
    && (proc_mtx->lock_count > 0)
  ) {
    // Mutex is already locked by this process.  Just increase the lock count
    // and return success.
    proc_mtx->lock_count++;
    return proc_success;
  }

  DWORD wait_result = WaitForSingleObject(
    proc_mtx->lock, // handle to mutex
    0);             // don't wait at all
  if (wait_result == WAIT_OBJECT_0) {
    return proc_success;
  }
  
  // If we made it this far then the mutex is already locked and we're not going
  // to block waiting it to become unlocked.  Just return busy.
  return proc_busy;
}

/// @fn int proc_cnd_broadcast(proc_cnd_t *proc_cond)
///
/// @brief Futex-based condition broadcast.
///
/// @param proc_cond A pointer to the process condition to broadcast.
///
/// @return Returns proc_success on successful broadcasting, proc_error if the
/// call could not be honored (cond is NULL).
int proc_cnd_broadcast(proc_cnd_t *proc_cond) {
  if (proc_cond == NULL) {
    return proc_error;
  }

  if (SetEvent(proc_cond->condition) == 0) {
    return proc_error;
  }
  proc_cond->num_signals = proc_cond->num_waiters;

  return proc_success;
}

/// @fn void proc_cnd_destroy(proc_cnd_t *proc_cond)
///
/// @brief Release any resources allocated during proc_cnd_init.
///
/// @param proc_cond A pointer to a preveiously-initialized proc_cnd_t.
///
/// @return This function returns no value.
void proc_cnd_destroy(proc_cnd_t *proc_cond) {
  if (proc_cond == NULL) {
    return;
  }

  // Set the metadata before closing the handle.
  proc_cond->num_waiters = 0;
  proc_cond->num_signals = -1;
  CloseHandle(proc_cond->condition);
}

/// @var proc_cnd_index
///
/// @brief Variable to ensure that conditions get unique names in the system.
LONG proc_cnd_index = 0;

/// @fn int proc_cnd_init(proc_cnd_t *proc_cond)
///
/// @brief Initialize all the resources needed for a futex condition.
///
/// @param proc_cond An allocated proc_cnd_t value to initialize.
///
/// @return Returns proc_success on success, proc_error on failure.
int proc_cnd_init(proc_cnd_t *proc_cond) {
  if (proc_cond == NULL) {
    return proc_error;
  }

  char conditionName[35];
  sprintf(conditionName, "Global\\%uEvent%u",
    (uint32_t) GetCurrentProcessId(),
    (uint32_t) InterlockedExchangeAdd(&proc_cnd_index, 1));
  proc_cond->condition = CreateEvent(
    NULL,         // Default security attributes
    TRUE,         // Manual-reset event
    FALSE,        // Initial state is nonsignaled
    conditionName // Named event, shared across processes
  );
  if (proc_cond->condition == NULL) {
    return proc_error;
  }
  proc_cond->num_waiters = 0;
  proc_cond->num_signals = 0;

  return proc_success;
}

/// @fn int proc_cnd_signal(proc_cnd_t *proc_cond)
///
/// @brief Futex-based condition signal.
///
/// @param proc_cond A pointer to the process condition to signal.
///
/// @return Returns proc_success on successful signalling, proc_error if the
/// call could not be honored (cond is NULL or signalling failure).
int proc_cnd_signal(proc_cnd_t *proc_cond) {
  if (proc_cond == NULL) {
    return proc_error;
  }

  if (SetEvent(proc_cond->condition) == 0) {
    return proc_error;
  }
  proc_cond->num_signals++;

  return proc_success;
}

/// @fn int proc_cnd_timedwait(proc_cnd_t *proc_cond, proc_mtx_t *proc_mtx,
///   const struct timespec *ts)
///
/// @brief Futex-based condition timed wait.
///
/// @param proc_cond A pointer to the condition to wait on.
/// @param proc_mtx A mutex for the condition that must be locked before this
///   call is made.  It will be unlocked before blocking on the condition and
///   locked again before the function returns.
/// @param ts A struct timespec that specifies the future deadline of the wait.
///
/// @return Returns proc_success on success, proc_timedout if the deadline is
/// reached before the condition is signalled, or proc_error if the request
/// could not be honored (a parameter is NULL or timespec_get fails).
int proc_cnd_timedwait(proc_cnd_t *proc_cond, proc_mtx_t *proc_mtx,
  const struct timespec *ts
) {
  if ((proc_cond == NULL) || (proc_mtx == NULL)) {
    return proc_error;
  }

  // Release mutex before waiting.
  proc_mtx_unlock(proc_mtx);
  
  int64_t future_nanoseconds
    = (((int64_t) ts->tv_sec) * ((int64_t) 1000000000LL))
    + ((int64_t) ts->tv_nsec);
  struct timespec now;
  int64_t now_nanoseconds = 0, delta_nanoseconds = 0;

  if (timespec_get(&now, TIME_UTC) != TIME_UTC) {
    // There's a failure with the system time.  We can't honor the timeout.
    // Fail.
    return proc_error;
  }
  now_nanoseconds
    = (((int64_t) now.tv_sec) * ((int64_t) 1000000000LL))
    + ((int64_t) now.tv_nsec);

  delta_nanoseconds = future_nanoseconds - now_nanoseconds;
  if (delta_nanoseconds <= 0) {
    delta_nanoseconds = 0;
  }

  DWORD wait_result
    = WaitForSingleObject(proc_cond->condition, delta_nanoseconds / 1000000);
  if (wait_result == WAIT_TIMEOUT) {
    return proc_timedout;
  } else if (wait_result != WAIT_OBJECT_0) {
    return proc_error;
  }

  // Re-acquire mutex after waking up.
  proc_mtx_lock(proc_mtx);

  if (proc_cond->num_signals > 0) {
    proc_cond->num_signals--;
    proc_cond->num_waiters--;
    if (proc_cond->num_signals == 0) {
      ResetEvent(proc_cond->condition);
    }
  } else {
    return proc_error;
  }

  return proc_success;
}

/// @fn int proc_cnd_wait(proc_cnd_t *proc_cond, proc_mtx_t *proc_mtx)
///
/// @brief Futex-based condition wait
///
/// @param proc_cond A pointer to the condition to wait on.
/// @param proc_mtx A mutex for the condition that must be locked before this
///   call is made.  It will be unlocked before blocking on the condition and
///   locked again before the function returns.
///
/// @return Returns proc_success on success or proc_error if the request could
/// not be honored (one or more NULL parameters).
int proc_cnd_wait(proc_cnd_t *proc_cond, proc_mtx_t *proc_mtx) {
  if ((proc_cond == NULL) || (proc_mtx == NULL)) {
    return proc_error;
  }

  // Release mutex before waiting.
  proc_mtx_unlock(proc_mtx);
  
  DWORD wait_result = WaitForSingleObject(proc_cond->condition, INFINITE);
  if (wait_result != WAIT_OBJECT_0) {
    return proc_error;
  }

  // Re-acquire mutex after waking up.
  proc_mtx_lock(proc_mtx);

  if (proc_cond->num_signals > 0) {
    proc_cond->num_signals--;
    proc_cond->num_waiters--;
    if (proc_cond->num_signals == 0) {
      ResetEvent(proc_cond->condition);
    }
  } else {
    return proc_error;
  }

  return proc_success;
}

#endif // _WIN32
