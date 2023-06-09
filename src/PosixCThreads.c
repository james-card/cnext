////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                     Copyright (c) 2012-2023 James Card                     //
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

#ifndef _MSC_VER
#include "PosixCThreads.h"
#include <stdlib.h>

#ifdef __cplusplus
#define ZEROINIT(x) x = {}
#else // __cplusplus not defined
#define ZEROINIT(x) x = {0}
#endif // __cplusplus

int mtx_init(mtx_t *mtx, int type) {
  int returnValue = thrd_success;
  
  if ((type & mtx_recursive) != 0) {
    pthread_mutexattr_t attribs;
    memset(&attribs, 0, sizeof(attribs));
    pthread_mutexattr_settype(&attribs, PTHREAD_MUTEX_RECURSIVE);
    returnValue = pthread_mutex_init(mtx, &attribs);
  } else {
     returnValue = pthread_mutex_init(mtx, NULL);
  }
  
  if (returnValue != 0) {
    returnValue = thrd_error;
  }
  
  return returnValue;
}

int mtx_timedlock(mtx_t* mtx, const struct timespec* ts) {
  int returnValue = thrd_success;
  
  returnValue = pthread_mutex_timedlock(mtx, ts);
  
  if (returnValue == ETIMEDOUT) {
    returnValue = thrd_timedout;
  } else if (returnValue != 0) {
    returnValue = thrd_error;
  }
  
  return returnValue;
}

int mtx_trylock(mtx_t *mtx) {
  int returnValue = thrd_success;
  
  returnValue = pthread_mutex_trylock(mtx);
  
  if (returnValue == EBUSY) {
    returnValue = thrd_busy;
  } else if (returnValue != 0) {
    returnValue = thrd_error;
  }
  
  return returnValue;
}

int mtx_lock(mtx_t *mtx) {
  int returnValue = thrd_success;
  
  returnValue = pthread_mutex_lock(mtx);
  
  if (returnValue != 0) {
    returnValue = thrd_error;
  }
  
  return returnValue;
}

int mtx_unlock(mtx_t *mtx) {
  int returnValue = thrd_success;
  
  returnValue = pthread_mutex_unlock(mtx);
  
  if (returnValue != 0) {
    returnValue = thrd_error;
  }
  
  return returnValue;
}

#ifndef _WIN32
int timespec_get(struct timespec* spec, int base) {
  clock_gettime(CLOCK_REALTIME, spec);
  return base;
}
#else // We're in MinGW and need to supply a Windows method.
/// @fn int timespec_get(struct timespec* spec, int base)
///
/// @brief Get the system time in seconds and nanoseconds.
/// This was taken from:
/// https://stackoverflow.com/questions/5404277/porting-clock-gettime-to-windows
///
/// @param spec The struct timespec structure to fill from the calling function.
/// @param base The base to use as defined on page 287 of the ISO/IEC 9899_2018
///   spec.
///
/// @return This function always returns base.
///
/// @note This only produces a time value down to 1/10th of a microsecond.
int timespec_get(struct timespec* spec, int base) {
  __int64 wintime = 0;
  FILETIME filetime = { 0, 0 };

  GetSystemTimeAsFileTime(&filetime);
  wintime = (((__int64) filetime.dwHighDateTime) << 32)
    | ((__int64) filetime.dwLowDateTime);

  wintime -= 116444736000000000LL;       // 1-Jan-1601 to 1-Jan-1970
  spec->tv_sec = wintime / 10000000LL;       // seconds
  spec->tv_nsec = wintime % 10000000LL * 100; // nano-seconds

  return base;
}
#endif

typedef struct PthreadCreateWrapperArgs {
  thrd_start_t func;
  void *arg;
} PthreadCreateWrapperArgs;

void *pthread_create_wrapper(void* wrapper_args) {
  // We want to be able to kill this thread if we need to.
  pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
  
  PthreadCreateWrapperArgs *cthread_args
    = (PthreadCreateWrapperArgs*) wrapper_args;
  thrd_start_t func = cthread_args->func;
  void *arg = cthread_args->arg;
  // Free our args so that the called function has as much memory as possible.
  free(cthread_args); cthread_args = NULL;
  
  // The C17 specification changed the definition of errno to be thread-local
  // storage.  However, it says that the value is initialized to zero only on
  // the main thread.  It is undefined on all other threads.  Fix this.
  errno = 0;
  
  int return_value = func(arg);
  thrd_exit(return_value);
  return (void*) ((intptr_t) return_value);
}

int thrd_create(thrd_t *thr, thrd_start_t func, void *arg) {
  int returnValue = thrd_success;
  
  PthreadCreateWrapperArgs *wrapper_args
    = (PthreadCreateWrapperArgs*) malloc(sizeof(PthreadCreateWrapperArgs));
  if (wrapper_args == NULL) {
    return thrd_error;
  }
  
  wrapper_args->func = func;
  wrapper_args->arg = arg;
  
  returnValue = pthread_create(thr, NULL,
    pthread_create_wrapper, wrapper_args);
  
  if (returnValue != 0) {
    returnValue = thrd_error;
    free(wrapper_args); wrapper_args = NULL;
  }
  
  return returnValue;
}

int thrd_join(thrd_t thr, int *res) {
  int returnValue = thrd_success;
  intptr_t threadReturnValue = 0;
  
  // The return value of the function is an int cast to a void pointer,
  // however pthread_join writes to a void pointer, so the variable we provide
  // has to be large enough to hold a void pointer value.  We can then downcast
  // the value to a standard int.
  returnValue = pthread_join(thr, (void**) &threadReturnValue);
  if (res != NULL) {
    *res = (int) threadReturnValue;
  }
  
  if (returnValue != 0) {
    returnValue = thrd_error;
  }
  
  return returnValue;
}

int tss_create(tss_t *key, tss_dtor_t dtor) {
  int returnValue = thrd_success;
  
  returnValue = pthread_key_create(key, dtor);
  
  if (returnValue != 0) {
    returnValue = thrd_error;
  }
  
  return returnValue;
}

int tss_set(tss_t key, void *val) {
  int returnValue = thrd_success;
  
  returnValue = pthread_setspecific(key, val);
  
  if (returnValue != 0) {
    returnValue = thrd_error;
  }
  
  return returnValue;
}

int cnd_broadcast(cnd_t *cond) {
  int returnValue = thrd_success;
  
  returnValue = pthread_cond_broadcast(cond);
  
  if (returnValue != 0) {
    returnValue = thrd_error;
  }
  
  return returnValue;
}

int cnd_init(cnd_t *cond) {
  int returnValue = thrd_success;
  
  returnValue = pthread_cond_init(cond, NULL);
  
  if (returnValue != 0) {
    returnValue = thrd_error;
  }
  
  return returnValue;
}

int cnd_signal(cnd_t *cond) {
  int returnValue = thrd_success;
  
  returnValue = pthread_cond_signal(cond);
  
  if (returnValue != 0) {
    returnValue = thrd_error;
  }
  
  return returnValue;
}

int cnd_timedwait(cnd_t* cond, mtx_t* mtx, const struct timespec* ts) {
  int returnValue = thrd_success;
  
  returnValue = pthread_cond_timedwait(cond, mtx, ts);
  
  if (returnValue == ETIMEDOUT) {
    returnValue = thrd_timedout;
  } else if (returnValue != 0) {
    returnValue = thrd_error;
  }
  
  return returnValue;
}

int cnd_wait(cnd_t *cond, mtx_t *mtx) {
  int returnValue = thrd_success;
  
  returnValue = pthread_cond_wait(cond, mtx);
  
  if (returnValue != 0) {
    returnValue = thrd_error;
  }
  
  return returnValue;
}

#endif // _MSC_VER

