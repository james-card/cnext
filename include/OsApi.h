///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              11.13.2020
///
/// @file              OsApi.h
///
/// @brief             This is the root header that can be included from
///                    libraries that make use of OS APIs.  This header will
///                    determine the system and include the correct system-
///                    specific definitions (unistd.h or equivalent).
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


#ifndef OSAPI_H
#define OSAPI_H

#include <stdint.h>
#include <time.h>
#include "CThreads.h"

#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// Taken from https://stackoverflow.com/questions/341817/is-there-a-replacement-for-unistd-h-for-windows-visual-c

#include <stdlib.h>
#include <io.h>
//#include <getopt.h> /* getopt at: https://gist.github.com/ashelly/7776712 */
#include <process.h> /* for getpid() and the exec..() family */
#define getpid _getpid
#include <direct.h> /* for _getcwd() and _chdir() */

#define sleep(seconds) Sleep(seconds * 1000)

#define srandom srand
#define random rand

/* Values for the second argument to access.
 * These may be OR'd together.
 */
#define R_OK    4       /* Test for read permission.  */
#define W_OK    2       /* Test for write permission.  */
//#define   X_OK    1       /* execute permission - unsupported in windows*/
#define F_OK    0       /* Test for existence.  */

#define access _access
#define dup2 _dup2
#define execve _execve
#define ftruncate _chsize
#define unlink _unlink
#define fileno _fileno
#define getcwd _getcwd
#define chdir _chdir
#define isatty _isatty
#define lseek _lseek
/* read, write, and close are NOT being #defined here, because while there are
 * file handle specific versions for Windows, they probably don't work for
 * sockets. You need to look at your app and consider whether to call
 * e.g. closesocket().
 */

#ifdef _WIN64
#define ssize_t __int64
#else
#define ssize_t long
#endif

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
/* should be in some equivalent to <sys/types.h> */
/*
typedef __int8            int8_t;
typedef __int16           int16_t; 
typedef __int32           int32_t;
typedef __int64           int64_t;
typedef unsigned __int8   uint8_t;
typedef unsigned __int16  uint16_t;
typedef unsigned __int32  uint32_t;
typedef unsigned __int64  uint64_t;
*/

#ifndef tzset
#define tzset _tzset
#endif
#ifndef daylight
#define daylight _daylight
#endif
#ifndef timezone
#define timezone _timezone
#endif
#ifndef tzname
#define tzname _tzname
#endif

#else // POSIX

#include <unistd.h>

#endif // _MSC_VER

static inline uint64_t getElapsedMicroseconds(uint64_t previousTime) {
  uint64_t returnValue = 0;
  
  struct timespec now;
  // Pre-C11: clock_gettime(CLOCK_REALTIME, &now);
  timespec_get(&now, TIME_UTC);
  uint64_t microseconds = (now.tv_sec * 1000000) + (now.tv_nsec / 1000);
  returnValue = microseconds - previousTime;
  
  return returnValue;
}

static inline int msleep(int milliseconds) {
  int returnValue = 0;
  
#ifdef _WIN32
  Sleep(milliseconds);
#else // POSIX
  struct timespec sleepTime = {0, milliseconds * 1000000};
  returnValue = nanosleep(&sleepTime, NULL);
#endif
  
  return returnValue;
}

#endif // OSAPI_H
