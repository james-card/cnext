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

#ifdef __linux__

#include "LinuxProcessSync.h"

// Direct futex system call wrapper
static int futex(uint32_t *futex_addr, int futex_op, uint32_t compare_val,
                const struct timespec *timeout, uint32_t *futex_addr2, uint32_t wake_val) {
    return syscall(SYS_futex, futex_addr, futex_op, compare_val, timeout, futex_addr2, wake_val);
}

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
    proc_mtx->lock = 0;
    proc_mtx->flags = type;
    proc_mtx->lock_count = 0;
    return_value = proc_success;
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
  uint32_t current_value = 0;
  
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

  // Try fast path first: attempt to atomically change 0 -> 1
  if (__atomic_exchange_n(&proc_mtx->lock, 1, __ATOMIC_ACQUIRE) == 0) {
    // Successfully acquired lock without kernel involvement
    proc_mtx->lock_count++;
    return proc_success;
  }
  
  // Slow path: contention occurred, need to wait
  do {
    // Load the current value of the mutex
    current_value = __atomic_load_n(&proc_mtx->lock, __ATOMIC_RELAXED);
    
    // Wait if mutex is still locked (equals 1)
    if (current_value == 1) {
      futex(&proc_mtx->lock, FUTEX_WAIT, 1, NULL, NULL, 0);
    }

    // Try again to acquire lock after being woken up
    current_value = __atomic_exchange_n(&proc_mtx->lock, 1, __ATOMIC_ACQUIRE);
  } while (current_value != 0);

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
  } else if (__atomic_load_n(&proc_mtx->lock, __ATOMIC_RELAXED) == 0) {
    // Unlocking an unlocked mutex.  Nothing more to do.
    return proc_success;
  }

  proc_mtx->lock_count--;

  if (proc_mtx->lock_count == 0) {
    // Release the lock
    __atomic_store_n(&proc_mtx->lock, 0, __ATOMIC_RELEASE);
    
    // Wake one waiter
    futex(&proc_mtx->lock, FUTEX_WAKE, 1, NULL, NULL, 0);
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
    proc_mtx->lock = 0;
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
  uint32_t current_value = 0;
  
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

  // Try fast path first: attempt to atomically change 0 -> 1
  if (__atomic_exchange_n(&proc_mtx->lock, 1, __ATOMIC_ACQUIRE) == 0) {
    // Successfully acquired lock without kernel involvement
    proc_mtx->lock_count++;
    return proc_success;
  }
  
  // Slow path: contention occurred, need to wait
  int64_t future_nanoseconds
    = (((int64_t) ts->tv_sec) * ((int64_t) 1000000000LL))
    + ((int64_t) ts->tv_nsec);
  struct timespec now, delta;
  int64_t now_nanoseconds = 0, delta_nanoseconds = 0;
  do {
    // Load the current value of the mutex
    current_value = __atomic_load_n(&proc_mtx->lock, __ATOMIC_RELAXED);
    
    // Wait if mutex is still locked (equals 1)
    if (current_value == 1) {
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
        // Our time period to wait for the mutex to become unlocked has expired.
        return proc_timedout;
      }

      delta.tv_sec = delta_nanoseconds / ((int64_t) 1000000000LL);
      delta.tv_nsec = delta_nanoseconds % ((int64_t) 1000000000LL);
      futex(&proc_mtx->lock, FUTEX_WAIT, 1, &delta, NULL, 0);
    }

    // Try again to acquire lock after being woken up
    current_value = __atomic_exchange_n(&proc_mtx->lock, 1, __ATOMIC_ACQUIRE);
  } while (current_value != 0);

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

  // Try fast path first: attempt to atomically change 0 -> 1
  if (__atomic_exchange_n(&proc_mtx->lock, 1, __ATOMIC_ACQUIRE) == 0) {
    // Successfully acquired lock without kernel involvement
    proc_mtx->lock_count++;
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

  // Increment the condition counter to avoid spurious wakeups.
  __atomic_fetch_add(&proc_cond->condition, 1, __ATOMIC_RELEASE);
  
  // Wake ONE waiting process.
  futex(&proc_cond->condition, FUTEX_WAKE, INT_MAX, NULL, NULL, 0);

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

  // This is not really necessary, but let's be good citizens.
  proc_cond->condition = 0;
}

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

  proc_cond->condition = 0;

  return proc_success;
}

/// @fn int proc_cnd_signal(proc_cnd_t *proc_cond)
///
/// @brief Futex-based condition signal.
///
/// @param proc_cond A pointer to the process condition to signal.
///
/// @return Returns proc_success on successful signalling, proc_error if the
/// call could not be honored (cond is NULL).
int proc_cnd_signal(proc_cnd_t *proc_cond) {
  if (proc_cond == NULL) {
    return proc_error;
  }

  // Increment the condition counter to avoid spurious wakeups.
  __atomic_fetch_add(&proc_cond->condition, 1, __ATOMIC_RELEASE);
  
  // Wake ONE waiting process.
  futex(&proc_cond->condition, FUTEX_WAKE, 1, NULL, NULL, 0);

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

  // Grab the current value before unlocking.
  uint32_t cond_value = proc_cond->condition;

  // Release mutex before waiting.
  proc_mtx_unlock(proc_mtx);
  
  int64_t future_nanoseconds
    = (((int64_t) ts->tv_sec) * ((int64_t) 1000000000LL))
    + ((int64_t) ts->tv_nsec);
  struct timespec now, delta;
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
    // Our time period to wait for the mutex to become unlocked has expired.
    return proc_timedout;
  }

  delta.tv_sec = delta_nanoseconds / ((int64_t) 1000000000LL);
  delta.tv_nsec = delta_nanoseconds % ((int64_t) 1000000000LL);

  // Wait on condition if it hasn't changed from expected value.
  futex(&proc_cond->condition, FUTEX_WAIT, cond_value, &delta, NULL, 0);
  
  // Re-acquire mutex after waking up.
  proc_mtx_lock(proc_mtx);

  if (proc_cond->condition == cond_value) {
    // Timeout was reached without the value changing.
    return proc_timedout;
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

  // Grab the current value before unlocking.
  uint32_t cond_value = proc_cond->condition;

  // Release mutex before waiting.
  proc_mtx_unlock(proc_mtx);
  
  // Wait on condition if it hasn't changed from expected value.
  futex(&proc_cond->condition, FUTEX_WAIT, cond_value, NULL, NULL, 0);
  
  // Re-acquire mutex after waking up.
  proc_mtx_lock(proc_mtx);

  return proc_success;
}

#endif // __linux__

