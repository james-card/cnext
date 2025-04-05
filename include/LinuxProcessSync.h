///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              03.30.2025
///
/// @file              LinuxProcessSync.h
///
/// @brief             These are the support functions and primitives that
///                    enable inter-thread synchronization on Linux.
///
/// @details
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

#ifndef LINUX_PROCESS_SYNC_H
#define LINUX_PROCESS_SYNC_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <linux/futex.h>
#include <sys/syscall.h>
#include <errno.h>
#include <sys/time.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include <limits.h>

#ifdef __cplusplus
extern "C"
{
#endif

/// @typedef proc_t
///
/// @brief The type by which processes identify themselves in inter-process
/// communication.
typedef pid_t proc_t;

// Process synchronization function return values.

#define proc_success    0
#define proc_busy       1
#define proc_error      2
#define proc_nomem      3
#define proc_timedout   4
#define proc_terminated 5

// Mutex support.

// Mutex types
#define proc_mtx_plain     0
#define proc_mtx_recursive 1
#define proc_mtx_timed     2

/// @struct proc_mtx_t
///
/// @brief Structure to represent an inter-process mutex object in Linux.
///
/// @param lock The integer value to use with the Linux futex calls.  A value
///   of 0 indicates unlocked and a value of 1 indicates locked.
/// @param flags The bitwise-OR of the proc_mtx_* values in use for this mutex.
/// @param lock_count The number of times the the current process has
///   successfully locked the mutex.
typedef struct proc_mtx_t {
  uint32_t lock;
  uint32_t flags;
  uint32_t lock_count;
} proc_mtx_t;

int proc_mtx_init(proc_mtx_t *proc_mtx, int type);
int proc_mtx_lock(proc_mtx_t *proc_mtx);
int proc_mtx_unlock(proc_mtx_t *proc_mtx);
void proc_mtx_destroy(proc_mtx_t *proc_mtx);
int proc_mtx_timedlock(proc_mtx_t *proc_mtx, const struct timespec *ts);
int proc_mtx_trylock(proc_mtx_t *proc_mtx);

// Condition support.

/// @struct proc_cnd_t
///
/// @brief Structure to represent an inter-process condition object in Linux.
///
/// @param condition The integer value to use with the Linux futex calls.  This
///   will be a counter of the number of waiters.
typedef struct proc_cnd_t {
  uint32_t condition;
} proc_cnd_t;

int proc_cnd_broadcast(proc_cnd_t *proc_cond);
void proc_cnd_destroy(proc_cnd_t *proc_cond);
int proc_cnd_init(proc_cnd_t *proc_cond);
int proc_cnd_signal(proc_cnd_t *proc_cond);
int proc_cnd_timedwait(proc_cnd_t *proc_cond, proc_mtx_t *proc_mtx,
  const struct timespec *ts);
int proc_cnd_wait(proc_cnd_t *proc_cond, proc_mtx_t *proc_mtx);


#ifdef __cplusplus
}
#endif

#endif // LINUX_PROCESS_SYNC_H

