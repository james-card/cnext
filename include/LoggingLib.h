///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              12.22.2018
///
/// @file              LoggingLib.h
///
/// @brief             These are the support functions that handle standard
///                    output and logging.
///
/// @details
///
/// @copyright
///                   Copyright (c) 2012-2024 James Card
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

#ifndef LOGGING_LIB_H
#define LOGGING_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <stdarg.h>

#include "CThreads.h"
#include "TypeDefinitions.h"
#include "StringLib.h"

#ifdef __cplusplus
extern "C"
{
#endif

/// @def LOG_ROLLOVER_SIZE
/// This is the size the logfile has to be before we roll over to a new file.
#define LOG_ROLLOVER_SIZE (5 * 1024 * 1024) // 5 MB

/// @def DEBUG_LOGFILE_POINTER
/// This is the FILE pointer used to indicate that logging is running in debug
/// mode and should provide extra output to stdout.
#define DEBUG_LOGFILE_POINTER ((FILE*) -1)

/// @def MALLOC_FAILURE_MESSAGE
/// Standard error message to log in the event of a malloc failure.
#define MALLOC_FAILURE_MESSAGE "malloc failure\n"

/// @def LOG_MALLOC_FAILURE
/// Attempt to log a memory allocation failure to whatever log file we can.
/// Cannot make use of anything that would allocate memory.  Do everything in
/// our power to print a message SOMEWHERE.  This is intended to be a last gasp
/// for the program.
#define LOG_MALLOC_FAILURE() \
  do { \
    FILE *errLog = logFile; \
    if ((errLog == NULL) || (errLog == DEBUG_LOGFILE_POINTER)) { \
      errLog = stderr; \
    } \
    int fputsStatus = fputs(__FILE__, errLog); \
    if ((fputsStatus == EOF) && (errLog != stderr)) { \
      /* Try again from the beginning with errLog set to stderr. */ \
      errLog = stderr; \
      fputsStatus = fputs(__FILE__, errLog); \
    } \
    fputsStatus = fputs(":", errLog); \
    if ((fputsStatus == EOF) && (errLog != stderr)) { \
      /* Try again from the beginning with errLog set to stderr. */ \
      errLog = stderr; \
      fputsStatus = fputs(__FILE__, errLog); \
      fputsStatus = fputs(":", errLog); \
    } \
    fputsStatus = fputs(__func__, errLog); \
    if ((fputsStatus == EOF) && (errLog != stderr)) { \
      /* Try again from the beginning with errLog set to stderr. */ \
      errLog = stderr; \
      fputsStatus = fputs(__FILE__, errLog); \
      fputsStatus = fputs(":", errLog); \
      fputsStatus = fputs(__func__, errLog); \
    } \
    fputsStatus = fputs(".", errLog); \
    if ((fputsStatus == EOF) && (errLog != stderr)) { \
      /* Try again from the beginning with errLog set to stderr. */ \
      errLog = stderr; \
      fputsStatus = fputs(__FILE__, errLog); \
      fputsStatus = fputs(":", errLog); \
      fputsStatus = fputs(__func__, errLog); \
      fputsStatus = fputs(".", errLog); \
    } \
    fputsStatus = fputs(STRINGIFY(__LINE__) ": " MALLOC_FAILURE_MESSAGE, errLog); \
    if ((fputsStatus == EOF) && (errLog != stderr)) { \
      /* Try again from the beginning with errLog set to stderr. */ \
      errLog = stderr; \
      fputsStatus = fputs(__FILE__, errLog); \
      fputsStatus = fputs(":", errLog); \
      fputsStatus = fputs(__func__, errLog); \
      fputsStatus = fputs(".", errLog); \
      fputsStatus = fputs(STRINGIFY(__LINE__) ": " MALLOC_FAILURE_MESSAGE, errLog); \
    } \
    fflush(errLog); \
  } while (0)

/// @enum LogLevel
/// This defines the possible log levels in the logging library
typedef enum LogLevel {
  NEVER,
  FLOOD,
  TRACE,
  DEBUG,
  DETAIL,
  INFO,
  WARN,
  ERR, // ERROR conflicts with something in windows.h
  CRITICAL,
  BOX,
  BANNER,
  NONE,
  NUM_LOG_LEVELS
} LogLevel;

/// @var LogLevelName
/// The string representations of the LogLevel enum values.
extern const char *LogLevelName[NUM_LOG_LEVELS];

/// @var logThreshold
/// The current log threshold value.  Log messages with a log level greater-than
///   or equal-to this value will be printed.
extern LogLevel logThreshold;

/// @var exitNow
/// Whether or not we must exit
extern bool exitNow;

#undef logFile

/// @var logFileMutex
/// Mutex to protect the log file during writes
extern mtx_t logFileMutex;

/// @var loggingForbidden
/// Thread-specific storage to determine whether logging is permitted on the
/// current thread.
extern tss_t loggingForbidden;

/// @var _threadLoggingThreshold_
/// Thread-specific logging threshold.
extern tss_t *_threadLoggingThreshold_;

/// @var logFile
/// The log file used by this library.
extern FILE *logFile;

int loggingStart_(const char *logFilename,
  char* (*makeLogHeader)(LogLevel logLevel, const char *fileName, const char *functionName, int lineNumber),
  int (*userLogHandler)(void *message, u64 length),
  void* (*encryptLogMessage)(void *message, u64 *length, void *key),
  void *encryptionKey,
  int (*userPlaintextLogHandler)(void *message, u64 length), ...);
#define loggingStart(logFilename, ...) \
  loggingStart_(logFilename, ##__VA_ARGS__, NULL, NULL, NULL, NULL, NULL)
void loggingStop();
bool tryLockResource(tss_t resource);
void unlockResource(tss_t resource);
void setThreadLogThreshold(LogLevel threadLogThreshold);
void printStackTrace(LogLevel logLevel);
u64 loggingGetThreadId();
LogLevel logLevelFromName(const char *levelName);
void loggingFlush();

int setLogThreshold(LogLevel logLevel, const char *user);
char *getTimestamp(struct timespec *time);
char *loggingHeaderGenerator(LogLevel logLevel, const char *fileName, const char *functionName, int lineNumber);

int vprintLog(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, const char *formatString, va_list args);
int vprintBox(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, const char *formatString, va_list args);
int vprintBanner(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, const char *formatString, va_list args);
#if defined _MSC_VER
int printLog_(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, _Printf_format_string_ const char *formatString, ...);
int printBox_(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, _Printf_format_string_ const char *formatString, ...);
int printBanner_(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, _Printf_format_string_ const char *formatString, ...);
#elif defined __MINGW32__
int printLog_(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, const char *formatString, ...)
  __attribute__((format(__MINGW_PRINTF_FORMAT, 5, 6)));
int printBox_(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, const char *formatString, ...)
  __attribute__((format(__MINGW_PRINTF_FORMAT, 5, 6)));
int printBanner_(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, const char *formatString, ...)
  __attribute__((format(__MINGW_PRINTF_FORMAT, 5, 6)));
#else // Assume GCC
int printLog_(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, const char *formatString, ...)
  __attribute__((format(printf, 5, 6)));
int printBox_(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, const char *formatString, ...)
  __attribute__((format(printf, 5, 6)));
int printBanner_(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, const char *formatString, ...)
  __attribute__((format(printf, 5, 6)));
#endif
int printBinary_(const char *fileName, const char *functionName,
  int lineNumber, LogLevel logLevel, const void *data, u64 dataLength);

#undef printLog // Take care of any previous definitions
#ifndef LOGGING_DISABLED

// C and C++ treat the empty part of the ?: differently.
#ifdef __cplusplus
#define LOGGING_ZERO (( 0 ))
#else // C
#define LOGGING_ZERO ((void) 0)
#endif

/// @def shouldLog(logLevel)
/// Determine whether or not logging should be done at the specified level.
#define shouldLog(logLevel) ( \
  (logLevel >= logThreshold) && (logLevel != NEVER) \
  && (logThreshold != NONE) \
  && ((_threadLoggingThreshold_ == NULL) \
    || (logLevel >= ((uintptr_t) tss_get(*_threadLoggingThreshold_))) \
  ) \
)

/// @def printLog
/// Wrapper macro that provides additional information to printLog_.
#define printLog(logLevel, formatString, ...) ( \
  (shouldLog(logLevel)) \
  ? printLog_(__FILE__, __func__, __LINE__, logLevel, formatString, ##__VA_ARGS__) \
  : LOGGING_ZERO \
)
  
/// @def printBinary
/// Wrapper macro that provides additional information to printBinary_.
#define printBinary(logLevel, data, length) ( \
  (shouldLog(logLevel)) \
  ? printBinary_(__FILE__, __func__, __LINE__, logLevel, data, length) \
  : LOGGING_ZERO \
)
  
/// @def printBox
/// Wrapper macro that provides additional information to printBox_.
#define printBox(logLevel, formatString, ...) ( \
  (shouldLog(logLevel)) \
  ? printBox_(__FILE__, __func__, __LINE__, logLevel, formatString, ##__VA_ARGS__) \
  : LOGGING_ZERO \
)
  
/// @def printBanner
/// Wrapper macro that provides additional information to printBanner_.
#define printBanner(logLevel, formatString, ...) ( \
  (shouldLog(logLevel)) \
  ? printBanner_(__FILE__, __func__, __LINE__, logLevel, formatString, ##__VA_ARGS__) \
  : LOGGING_ZERO \
)
  
#else
// Logging is disabled.  Fill with blanks.
#define printLog(logLevel, ...) {}
#define printBinary(logLevel, ...) {}
#define printBox(logLevel, ...) {}
#define printBanner(logLevel, ...) {}
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LOGGING_LIB_H

