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

#include "LoggingLib.h"
#include "Queue.h"
#include "OsApi.h"
#include "AuxMemory.h"

/// @var logFile
/// The log file used by this library.
FILE *logFile = NULL;

/// @var logThreshold
///
/// @brief This is the initial value of the logThreshold before any arguments
/// are processed to set up logging.
LogLevel logThreshold = DETAIL;

/// @var loggingForbidden
///
/// @brief Thread-specific storage to determine whether or not printing is
/// already in progress on this thread.
ZEROINIT(tss_t loggingForbidden);

/// @var _threadLoggingThreshold_
///
/// @brief Thread-specific storage for a thread-specific log threshold.
tss_t *_threadLoggingThreshold_ = NULL;

/// @var LogLevelName
///
/// @brief These are the string values of the log levels defined in the
/// LogLevel enum. These are used in printLog to indicate the level of log
/// information being saved.
const char *LogLevelName[NUM_LOG_LEVELS] = {
  "NEVER",
  "FLOOD",
  "TRACE",
  "DEBUG",
  "DETAIL",
  "INFO",
  "WARNING",
  "ERROR",
  "CRITICAL",
  "BOX",
  "BANNER",
  "NONE",
};

/// @var exitNow
///
/// @brief This global variable deterines whether or not we must exit.
bool exitNow = false;

/// @var _vprintFunctions
///
/// @brief Array of function pointers to the appropriate vprint function based
/// on the log level.  This variable is private to this file (static).
static int (*_vprintFunctions[NUM_LOG_LEVELS])(const char *fileName,
  const char *functionName, int lineNumber, LogLevel logLevel,
  const char *formatString, va_list args
) = {
  vprintLog,    // NEVER
  vprintLog,    // FLOOD
  vprintLog,    // TRACE
  vprintLog,    // DEBUG
  vprintLog,    // DETAIL
  vprintLog,    // INFO
  vprintLog,    // WARNING
  vprintLog,    // ERROR
  vprintLog,    // CRITICAL
  vprintBox,    // BOX
  vprintBanner, // BANNER
  vprintLog,    // NONE
};

// Internal state variables
static char *_logFilename = NULL;
static char* (*_makeLogHeader)(LogLevel logLevel, const char *fileName,
  const char *functionName, int lineNumber) = NULL;
static int (*_userLogHandler)(void *message, u64 length) = NULL;
static void* (*_encryptLogMessage)(void *message, u64 *length, void *key);
static void *_encryptionKey = NULL;
static int (*_userPlaintextLogHandler)(void *message, u64 length) = NULL;
static const char *_hostname = NULL;
static bool _loggingInitialized = false;
static Queue *_logQueue = NULL;
ZEROINIT(thrd_t _loggingQueueThread);
int _loggingQueueFunction(void *args);
bool _runLoggingQueueFunction = false;
FILE *_fileToWriteTo = NULL;
ZEROINIT(cnd_t _writeMessagesCondition);
ZEROINIT(mtx_t _writeMessagesMutex);
ZEROINIT(mtx_t _headerMessageMutex);

/// @fn int loggingStart_(const char *logFilename, char* (*makeLogHeader)(LogLevel logLevel, const char *fileName, const char *functionName, int lineNumber), int (*userLogHandler)(void *message, u64 length), void* (*encryptLogMessage)(void *message, u64 *length), int (*userPlaintextLogHandler)(void *message, u64 length), ...)
///
/// @brief Initialize all the logging components.
///
/// @param logFilename The filename of the logfile to use.
/// @param makeLogHeader The user-specified function to generate the header of
///   each log message.
/// @param usrLogHandler The user-specified log handler to call once we log
///   our message internally.
/// @param ... Unused.
///
/// @return Returns 0 on success, -1 on failure.
int loggingStart_(const char *logFilename,
  char* (*makeLogHeader)(LogLevel logLevel, const char *fileName, const char *functionName, int lineNumber),
  int (*userLogHandler)(void *message, u64 length),
  void* (*encryptLogMessage)(void *message, u64 *length, void *key),
  void *encryptionKey,
  int (*userPlaintextLogHandler)(void *message, u64 length),
  ...
) {
  int returnValue = 0;
  
  if (_loggingInitialized == false) {
    // The print functions call loggingStart if _loggingInitialized is false.
    // That means we need to set this to true before we do anything else lest
    // some function that we call during initialization results in a recursive
    // call to printLog somewhere down the line.
    _loggingInitialized = true;
    
    // This is the first time this function has been called.  Initialize
    // everything.
    int status = tss_create(&loggingForbidden, NULL);
    if (status != thrd_success) {
      fputs("Could not initialize loggingForbidden.\n", stderr);
      returnValue = -1;
    }
    
    _threadLoggingThreshold_ = (tss_t*) calloc(1, sizeof(tss_t));
    if (_threadLoggingThreshold_ != NULL) {
      status = tss_create(_threadLoggingThreshold_, NULL);
      if (status != thrd_success) {
        fputs("Could not initialize _threadLoggingThreshold_.\n", stderr);
        returnValue = -1;
      }
    } else {
      LOG_MALLOC_FAILURE();
      returnValue = -1;
    }
    
    status = mtx_init(&_writeMessagesMutex, mtx_plain);
    if (status != thrd_success) {
      fputs("Could not initialize writeMessagesMutex.\n", stderr);
      returnValue = -1;
    }

    status = mtx_init(&_headerMessageMutex, mtx_plain);
    if (status != thrd_success) {
      fputs("Could not initialize headerMessageMutex.\n", stderr);
      returnValue = -1;
    }

    status = cnd_init(&_writeMessagesCondition);
    if (status != thrd_success) {
      fputs("Could not initialize writeMessagesCondition.\n", stderr);
      returnValue = -1;
    }
    
    _logQueue = queueCreate(typePointerNoCopy);
    if (_logQueue == NULL) {
      fputs("Could not initialize _logQueue.\n", stderr);
      returnValue = -1;
    }
    
    // Timestamps need to be in UTC, so make sure the timezone global variable
    // is defined correctly.
    tzset();
  } else if (_runLoggingQueueFunction == false) {
    // _loggingInitialized is true and _runLoggingQueueFunction is false.  This
    // indicates that we're either in the middle of running loggingStart or in
    // the middle of running loggingStop in another thread.  Don't proceed any
    // further.  Return good status in this case.
    return 0;
  } else if ((logFile != NULL) && (logFile != DEBUG_LOGFILE_POINTER)) {
    // We've opened a log file before and we're re-entering.  Close the old
    // log file.
    fclose(logFile); logFile = NULL;
  }
  
  if (_logFilename != NULL) {
    _logFilename = stringDestroy(_logFilename);
  }
  
  if (logFilename != NULL) {
    logFile = fopen(logFilename, "a");
    if (logFile == NULL) {
      // Failed to open the logfile.
      fputs("ERR:  Could not open log file \"", stderr);
      fputs(logFilename, stderr);
      fputs("\".\n", stderr);
      const char *errorString = NULL;
      errorString = strerror(errno);
      fputs("Error returned: \"", stderr);
      fputs(errorString, stderr);
      fputs("\".\n", stderr);
      returnValue = -1;
    }
  } else {
    logFile = NULL;
    straddstr(&_logFilename, ""); // Empty but non-NULL filename marker.
  }
  
  if (returnValue != 0) {
    // Some part of our initialization has failed.  The system is in a bad
    // state.  We still need to log if we can.  Redirect everything to stderr.
    logFile = stderr;
  }
  
  straddstr(&_logFilename, logFilename); // Make a copy.
  _makeLogHeader = makeLogHeader;
  _userLogHandler = userLogHandler;
  _encryptLogMessage = encryptLogMessage;
  _encryptionKey = encryptionKey;
  _userPlaintextLogHandler = userPlaintextLogHandler;
  _hostname = getenv("HOSTNAME");
  if ((_hostname == NULL) || (*_hostname == '\0')) {
    _hostname = getenv("COMPUTERNAME");
  }
  if ((_hostname == NULL) || (*_hostname == '\0')) {
    _hostname = "localhost";
  }
  
  // Set _fileToWriteTo so that we don't have to recompute what to log to on
  // each pass of the while loop.
  if ((logFile != DEBUG_LOGFILE_POINTER) && (logFile != NULL)) {
    _fileToWriteTo = logFile;
  } else {
    _fileToWriteTo = stdout;
  }
  
  if (_runLoggingQueueFunction == false) {
    // loggingQueueFunction's initialization depends on some of the variables
    // above being setup, so we have to start it last.
    _runLoggingQueueFunction = true;
    thrd_create(&_loggingQueueThread, _loggingQueueFunction, NULL);
  }
  
  return returnValue;
}

/// @fn void loggingStop()
///
/// @brief Stop logging and free all resources.  Logging cannot be used after
///   this call.
///
/// @return This function returns no value.
void loggingStop() {
  if (_loggingInitialized == true) {
    // We need to set _runLoggingQueueFunction before signaling.
    _runLoggingQueueFunction = false;
    mtx_lock(&_writeMessagesMutex);
    cnd_signal(&_writeMessagesCondition);
    mtx_unlock(&_writeMessagesMutex);
    int result = 0; // Unused dummy variable for thrd_join.
    thrd_join(_loggingQueueThread, &result);
    tryLockResource(loggingForbidden);
    _logQueue = queueDestroy(_logQueue);
    unlockResource(loggingForbidden);
    _fileToWriteTo = NULL;
    
    mtx_destroy(&_headerMessageMutex);
    mtx_destroy(&_writeMessagesMutex);
    cnd_destroy(&_writeMessagesCondition);
    
    _logFilename = stringDestroy(_logFilename);
    if ((logFile != NULL) && (logFile != DEBUG_LOGFILE_POINTER)
    ) {
      fclose(logFile); logFile = NULL;
    }
    
    tss_delete(loggingForbidden);
    memset(&loggingForbidden, 0, sizeof(loggingForbidden));
    tss_delete(*_threadLoggingThreshold_);
    _threadLoggingThreshold_
      = (tss_t*) pointerDestroy(_threadLoggingThreshold_);
    
    _makeLogHeader = NULL;
    _userLogHandler = NULL;
    _encryptLogMessage = NULL;
    _encryptionKey = NULL;
    _userPlaintextLogHandler = NULL;
    _hostname = NULL;
  }
  
  _loggingInitialized = false;
  
  return;
}

/// @fn int setLogThreshold(LogLevel logLevel, const char *user)
///
/// @brief This sets the log level threshold below which we will not print.
/// The new log level is always echoed to the log file since the message is
/// critical.
///
/// @param logLevel is the new log level.
/// @param user is the user who initiated the command.
///
/// @return This function return 0 on success, -1 on failure.
int setLogThreshold(LogLevel logLevel, const char *user) {
  printLog(TRACE, "ENTER setLogThreshold(logLevel=\"%s\", user=\"%s\")\n",
    (logLevel < NUM_LOG_LEVELS) ? LogLevelName[logLevel] : "INVALID", user);
  
  if (logLevel >= NUM_LOG_LEVELS) {
    printLog(ERR, "Invalid logLevel %d specified.\n", logLevel);
    printLog(TRACE, "EXIT setLogThreshold(logLevel=INVALID, \"%s\") = {-1}\n",
      user);
    return -1;
  }
  
  const char *oldThreshold = LogLevelName[logThreshold];
  logThreshold = logLevel;
  printLog(CRITICAL, "%s has changed the log level from %s to %s\n", user,
    oldThreshold, LogLevelName[logThreshold]);
  (void) oldThreshold; // In case logging is disabled and printLog is compiled
                       // out.
  
  printLog(TRACE, "EXIT setLogThreshold(logLevel=\"%s\", \"%s\") = {0}\n",
    LogLevelName[logLevel], user);
  return 0;
}

/// @fn char *getTimestamp(struct timespec *time)
///
/// @brief This function returns a timestamp in a standard format used.  Any
/// functions that require a timestamp MUST call this function to get it.
///
/// @param time A pointer to a struct timespec representing the time to make
///   this timestamp for.  If NULL is provided, the current time will be used.
///
/// @return A timestamp representing the current time will be returned.
///
/// @note This function is one of the few that does not print out ENTER and
/// EXIT information to the log as that would create a situation of infinite
/// recursion.
char *getTimestamp(struct timespec *time) {
  char *timestamp = NULL;
  
  // Timestamp variables
  #define timestampSize 30
  struct timespec now;
  if (time == NULL) {
    // This is the expected usual case, so optimize for that.
    timespec_get(&now, TIME_UTC);
  } else {
    now = *time;
  }
  ZEROINIT(struct tm nowStruct);
  gmtime_r(&now.tv_sec, &nowStruct);
  
  timestamp = (char*) malloc(timestampSize);
  snprintf(timestamp, timestampSize, "%4d-%02d-%02d %02d:%02d:%02d.%09ld",
    nowStruct.tm_year + 1900,
    nowStruct.tm_mon + 1,
    nowStruct.tm_mday,
    nowStruct.tm_hour,
    nowStruct.tm_min,
    nowStruct.tm_sec,
    (long) now.tv_nsec);
  
  #undef timestampSize
  return timestamp;
}

/// @fn char *loggingHeaderGenerator(LogLevel logLevel, const char *fileName, const char *functionName, int lineNumber)
///
/// @brief Creates a header for a log entry in the form:<br />
/// "[YYYY-MM-DD HH:MM:SS.NNNNNNNNN HostInfo Module LogLevel] "<br />
/// Module will be constructed from the fileName, functionName, and lineNumber
///
/// @param logLevel is the LogLevel the message was logged with
/// @param fileName is the name of the file the header is for
/// @param functionName is the name of the function the header is for
/// @param lineNumber is the line number the header is for
///
/// @return Returns a newly-allocated string containing the log header.
///
/// @note This function is one of the few that does not print out ENTER and
///       EXIT information to the log as that would create a situation of
///       infinite recursion.
char *loggingHeaderGenerator(LogLevel logLevel, const char *fileName,
  const char *functionName, int lineNumber
) {
  char *logHeader = NULL;
  
  // Timestamp variables
  char *timestamp = NULL;
  timestamp = getTimestamp(NULL);
  
  const char *slashAt = strrchr(fileName, '/');
  if (slashAt == NULL) {
    slashAt = strrchr(fileName, '\\');
  }
  if (slashAt != NULL) {
    fileName = slashAt + 1;
  }
  
  u64 threadId = loggingGetThreadId();
  u32 pid = 0;
  pid = (u32) getpid();
  
  // "[YYYY-MM-DD HH:MM:SS.NNNNNNNNN HostInfo Module LogLevel] "
  // HostInfo = hostname:pid.thread
  // We may have forked since loggingStart was called, so have to call getpid
  // every time.  We can assume we're running on the same host, though.
  // Module = fileName:functionName.lineNumber
  if (asprintf(&logHeader, "[%s %s:%u.%llu %s:%s.%d %s] ", timestamp,
    _hostname, (unsigned int) pid, (long long unsigned int) threadId,
    fileName, functionName, lineNumber,
    LogLevelName[logLevel]) < 0
  ) {
    // Do nothing.  We can't log an error.  logHeader will be NULL.  This is
    // just here to make the complier happy.
  }
  timestamp = stringDestroy(timestamp);
  
  return logHeader;
}

/// @fn int _rolloverLog(void)
///
/// @brief Check to see if we need to roll over the log into an arhive log and
///   start a new one if so.
///
/// @return Returns 0 on success, -1 on failure.
int _rolloverLog(void) {
  if ((exitNow == false) && (logFile != NULL)
    && (logFile != DEBUG_LOGFILE_POINTER)
    && (_logFilename != NULL) && (*_logFilename != '\0')
  ) {
    int logSize = 0;
    logSize = ftell(logFile);
    if (logSize >= LOG_ROLLOVER_SIZE) {
      FILE *_logFile = logFile;
      // Change the globl logFile in case any non-LoggingLib calls try to write
      // to it whiile we're rolling over.
      logFile = stderr;
      
      char *timestamp = NULL;
      timestamp = getTimestamp(NULL);
      char *archiveLogFilename = NULL;
      straddstr(&archiveLogFilename, _logFilename);
      // timestamp format = "YYYY-MM-DD HH:MM:SS.NNNNNNNNN "
      //                     0123456789012345678901234567890
      // We can't use ':' in a file name, and let's not use ' ' or '.' either.
      timestamp[10] = '_';
      timestamp[13] = '-';
      timestamp[16] = '-';
      timestamp[19] = '-';
      timestamp[29] = '\0';
      straddstr(&archiveLogFilename, "_");
      straddstr(&archiveLogFilename, timestamp);
      timestamp = stringDestroy(timestamp);
      Bytes fileContent = NULL;
      fileContent = getFileContent(_logFilename);
      putFileContent(archiveLogFilename, fileContent, bytesLength(fileContent));
      fileContent = bytesDestroy(fileContent);
      archiveLogFilename = stringDestroy(archiveLogFilename);
      if (ftruncate(fileno(_logFile), 0) != 0) {
        // Do nothing.  We can't log an error here.  Also, if we can't
        // truncate the file, we don't lose data, so we don't care.  This
        // check is just here to make the compiler happy.
      }
      
      // Reset the logFile.
      logFile = _logFile;
    }
  }
  
  return 0;
}

/// @struct LogMessage
///
/// @brief Structure for containing all the information needed to log a message
/// to the log file.  Messages printed to the log file may be ASCII or binary,
/// so we have to have a pointer and a length rather than a string.
///
/// @param buffer A pointer to the contnets to print to the log file.
/// @param length The number of bytes pointed to by the buffer pointer.
typedef struct LogMessage {
  void *buffer;
  size_t length;
} LogMessage;

/// @fn void loggingFlush()
///
/// @brief Block until all of the log messages in the queue have been flushed
/// to the log file.
///
/// @return This function returns no value.
void loggingFlush() {
  while ((_runLoggingQueueFunction == true) && (_logQueue->size > 0));
  
  return;
}

/// @fn int _loggingQueueFunction(void *args)
///
/// @brief Thread function for popping the _logQueue and printing to the log
/// file.
///
/// args Parameter supplied for compatibility with C threads function pointer
///   prototype.  Ignored by this function.
///
/// @return This function always returns 0.
int _loggingQueueFunction(void *args) {
  (void) args;
  LogMessage *message = NULL;
  void *buffer = NULL;
  size_t length = 0;
  
  // Prevent this thread from generating any logging messages.
  bool logLock = tryLockResource(loggingForbidden);
  
  // Pop and print for as long as _runLoggingQueueFunction is true.
  while ((_runLoggingQueueFunction == true) || (_logQueue->size > 0)) {
    message = (LogMessage*) queuePop(_logQueue);
    while (message != NULL) {
      // Print the message and flush the buffer.
      buffer = message->buffer;
      length = message->length;
      if (buffer != NULL) {
        fwrite(buffer, length, 1, _fileToWriteTo);
      }
      
      buffer = pointerDestroy(buffer);
      message = (LogMessage*) pointerDestroy(message);
      length = 0;
      
      _rolloverLog();
      message = (LogMessage*) queuePop(_logQueue);
    }
    fflush(_fileToWriteTo);
    if (_runLoggingQueueFunction == true) {
      // Wait to be signaled before checking again.
      mtx_lock(&_writeMessagesMutex);
      if (cnd_wait(&_writeMessagesCondition, &_writeMessagesMutex)
        != thrd_success
      ) {
        // Something's wrong with the condition.  Bail.
        mtx_unlock(&_writeMessagesMutex);
        break;
      }
      mtx_unlock(&_writeMessagesMutex);
    }
  }
  
  if (logLock) {
    unlockResource(loggingForbidden);
  }
  
  return 0;
}

/// @fn int vprintLog(const char *fileName, const char *functionName, int lineNumber, LogLevel logLevel, const char *formatString, va_list args)
///
/// @brief Prints a formatted string to the log file noting the log level IF
/// the log level is above the threshold speciefied.  If the log level
/// specified is not sufficient to warrant printing, the function just returns
/// as successful.
///
/// @details
/// Logs will take the following form:
/// [log header] [log message]
///
/// The contents of [log header] will be defined by the application-specific
/// function _makeLogHeader.  The contents of [log message] will be defined by
/// the format string and optional arguments.
///
/// @param fileName is the name of the file from which the call is made.
/// @param functionName is the name of the function making the call.
/// @param lineNumber is the line of the file the printLog call is made from.
/// @param logLevel is the level of the message to be printed.
/// @param formatString is the formatted string to print.
/// @param args is the va_list of arguments the formatString requires.
///
/// @return Returns a status integer corresponding to the status of the print
/// calls.
int vprintLog(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, const char *formatString, va_list args
) {
  int returnValue = 0;
  va_list args2;
  
  if (_loggingInitialized == false) {
    loggingStart(NULL);
  }
  
  // If we're debugging, send to stdout FIRST before we do anything fancy.
  // If we could not initialize the log file then logFile may be pointing to
  // stdout.  In this case we'll skip the debug print since it would echo the
  // same information to the same file descriptor twice which may be confusing
  if (logFile == DEBUG_LOGFILE_POINTER) {
    va_copy(args2, args);
    returnValue = vfprintf(stdout, formatString, args2);
    fflush(stdout);
    va_end(args2);
  }
  
  // Our lock on logging, if any.
  bool logLock = false;
  
  // Disable logging for other functions on THIS thread while we're trying
  // to print.
  logLock = tryLockResource(loggingForbidden);
  if (logLock == true) {
    char *logString = NULL;
    mtx_lock(&_headerMessageMutex);
    if (_makeLogHeader != NULL) {
      logString = _makeLogHeader(logLevel, (char*) fileName,
      (char*) functionName, lineNumber);
    }

    // Add the formatString that was passed in.
    straddstr(&logString, formatString);
    if (logString == NULL) {
      // Memory allocation failure.  Bail.
      unlockResource(loggingForbidden);
      LOG_MALLOC_FAILURE();
      return -1;
    }
    int logStringLength = 0;
    logStringLength = (int) strlen(logString);
    if (logString[logStringLength - 1] != '\n') {
      straddstr(&logString, "\n");
    }
    
    char *buffer = NULL;
    u64 length = 0;
    va_copy(args2, args);
    length = vasprintf(&buffer, logString, args2);
    va_end(args2);
    
    if ((length <= 0) || (buffer == NULL)) {
      // Memory allocation failure.  Bail.
      logString = stringDestroy(logString);
      unlockResource(loggingForbidden);
      LOG_MALLOC_FAILURE();
      return length;
    }
    
    if (_encryptLogMessage != NULL) {
      if (_userPlaintextLogHandler != NULL) {
        // The user wants to log the plaintext message.  Do it.
        _userPlaintextLogHandler(buffer, length);
      }
      char *encryptedLogMessage = NULL;
      encryptedLogMessage = (char*) _encryptLogMessage((void*) buffer,
        &length, _encryptionKey);
      if (encryptedLogMessage != NULL) {
        buffer = stringDestroy(buffer);
        buffer = encryptedLogMessage;
      }
    }
    
    // Need to envoke the user's log handler (if any) to avoid
    // _loggingQueueFunction freeing the buffer before the user's handler
    // processes it.
    if (_userLogHandler != NULL) {
      _userLogHandler(buffer, length);
    }
    
    LogMessage *message = (LogMessage*) malloc(sizeof(LogMessage));
    if ((_runLoggingQueueFunction == true) && (message != NULL)) {
      message->buffer = buffer;
      message->length = length;
      queuePushEntry(_logQueue, message);
      mtx_unlock(&_headerMessageMutex);
      mtx_lock(&_writeMessagesMutex);
      cnd_signal(&_writeMessagesCondition);
      mtx_unlock(&_writeMessagesMutex);
    } else {
      mtx_unlock(&_headerMessageMutex);
      // buffer didn't get queued, so won't be freed by
      // _loggingQueueFunction.  Free it here.
      buffer = stringDestroy(buffer);
      message = (LogMessage*) pointerDestroy(message);
    }
    
    logString = stringDestroy(logString);
    
    // Unlock logging for the rest of the thread.
    unlockResource(loggingForbidden);
  }
  
  return returnValue;
}

/// @fn int printLog_(const char *fileName, const char *functionName, int lineNumber, LogLevel logLevel, const char *formatString, ...)
///
/// @brief Prints a formatted string to the log file noting the log level IF
/// the log level is above the threshold speciefied.  If the log level
/// specified is not sufficient to warrant printing, the function just returns
/// as successful.
///
/// @details
/// Logs will take the following form:
/// [log header] [log message]
///
/// The contents of [log header] will be defined by the application-specific
/// function _makeLogHeader.  The contents of [log message] will be defined by
/// the format string and optional arguments.
///
/// This function is wrapped by a #define (without the leading underscore) that
/// automatically proivdes the fileName, functionName, and lineNumber arguments.
/// The caller need only provide the logLevel, format string, and optional
/// parameters.
///
/// @param fileName is the name of the file from which the call is made.
/// @param functionName is the name of the function making the call.
/// @param lineNumber is the line of the file the printLog call is made from.
/// @param logLevel is the level of the message to be printed.
/// @param formatString is the formatted string to print.
/// @param ... optional arguments may be provided depending on the formatString.
///
/// @return Returns a status integer corresponding to the status of the print
/// calls.
///
/// @note This function is one of the few that does not print out ENTER and
///       EXIT information to the log as that would create a situation of
///       infinite recursion.
int printLog_(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, const char *formatString, ...
) {
  int returnValue = 0;
  
  // Variable argument variables
  va_list args;
  
  va_start(args, formatString);
  returnValue = _vprintFunctions[logLevel](fileName, functionName, lineNumber,
    logLevel, formatString, args);
  va_end(args);
  
  return returnValue;
}

/// @fn int printBinary_(const char *fileName, const char *functionName, int lineNumber, LogLevel logLevel, const void *data, u64 dataLength)
///
/// @brief Prints a binary message to the log file noting the log level IF
/// the log level is above the threshold speciefied.  If the log level
/// specified is not sufficient to warrant printing, the function just returns
/// as successful.
///
/// @details
/// Logs will take the following form:
/// [log header] [log message]
///
/// The contents of [log header] will be defined by the application-specific
/// function _makeLogHeader.  The contents of [log message] will be defined by
/// the data argument.
///
/// This function is wrapped by a #define (without the leading underscore) that
/// automatically proivdes the fileName, functionName, and lineNumber arguments.
/// The caller need only provide the logLevel, data , and length.
///
/// @param fileName is the name of the file from which the call is made.
/// @param functionName is the name of the function making the call.
/// @param lineNumber is the line of the file the printBinary call is made from.
/// @param logLevel is the level of the message to be printed.
/// @param data is the data to be printed.
/// @param dataLength is the length of the data.
///
/// @return Returns a status integer corresponding to the status of the print
/// calls.
///
/// @note This function is one of the few that does not print out ENTER and
///       EXIT information to the log as that would create a situation of
///       infinite recursion.
int printBinary_(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, const void *data, u64 dataLength
) {
  int returnValue = 0;
  
  if (_loggingInitialized == false) {
    loggingStart(NULL);
  }
  
  // If we're debugging, send to stdout FIRST before we do anything fancy.
  // If we could not initialize the log file then logFile may be pointing to
  // stdout.  In this case we'll skip the debug print since it would echo the
  // same information to the same file descriptor twice which may be confusing
  if (logFile == DEBUG_LOGFILE_POINTER) {
    if (fwrite(data, dataLength, 1, stdout) == 1) {
      returnValue = (int) dataLength;
    }
    fflush(stdout);
  }
  
  // Our lock on logging, if any.
  bool logLock = false;
  
  // Disable logging for other functions on THIS thread while we're trying
  // to print.
  logLock = tryLockResource(loggingForbidden);
  if (logLock == true) {
    char *logString = NULL;
    u64 length = 0;
    mtx_lock(&_headerMessageMutex);
    if (_makeLogHeader != NULL) {
      logString = _makeLogHeader(logLevel, (char*) fileName,
      (char*) functionName, lineNumber);
      length = (int) strlen(logString);
    }

    // Add the data that was passed in.
    length = dataAddData((void**) &logString, (u64) length,
      data, dataLength);
    length = dataAddData((void**) &logString, (u64) length, "\n", 1);
    
    if (_encryptLogMessage != NULL) {
      if (_userPlaintextLogHandler != NULL) {
        // The user wants to log the plaintext message.  Do it.
        _userPlaintextLogHandler(logString, length);
      }
      char *encryptedLogMessage = NULL;
      encryptedLogMessage = (char*) _encryptLogMessage((void*) logString,
        &length, _encryptionKey);
      logString = stringDestroy(logString);
      logString = encryptedLogMessage;
    }
    
    // Need to envoke the user's log handler (if any) before queueing to
    // avoid _loggingQueueFunction freeing the buffer before the user's
    // handler processes it.
    if (_userLogHandler != NULL) {
      _userLogHandler(logString, length);
    }
    
    LogMessage *message = (LogMessage*) malloc(sizeof(LogMessage));
    if ((_runLoggingQueueFunction == true) && (message != NULL)) {
      message->buffer = logString;
      message->length = length;
      queuePushEntry(_logQueue, message);
      mtx_unlock(&_headerMessageMutex);
      mtx_lock(&_writeMessagesMutex);
      cnd_signal(&_writeMessagesCondition);
      mtx_unlock(&_writeMessagesMutex);
    } else {
      mtx_unlock(&_headerMessageMutex);
      // logString didn't get queued, so won't be freed by
      // _loggingQueueFunction.  Free it here.
      logString = stringDestroy(logString);
      message = (LogMessage*) pointerDestroy(message);
    }
    
    // Unlock logging for the rest of the thread.
    unlockResource(loggingForbidden);
  }
  
  return returnValue;
}

/// @fn int vprintBox(const char *fileName, const char *functionName, int lineNumber, LogLevel logLevel, const char *formatString, va_list args)
///
/// @brief Prints a formatted string with an ASCII box around it to the log file
/// noting the log level IF the log level is above the threshold speciefied.
/// If the log level specified is not sufficient to warrant printing, the
/// function just returns as successful.
///
/// @details
/// Logs will take the following form:<br />
/// [log header] +---------------+<br />
/// [log header] | [log message] |<br />
/// [log header] +---------------+<br />
///
/// The contents of [log header] will be defined by the application-specific
/// function _makeLogHeader.  The contents of [log message] will be defined by
/// the format string and optional arguments.
///
/// @param fileName is the name of the file from which the call is made.
/// @param functionName is the name of the function making the call.
/// @param lineNumber is the line of the file the printBox call is made from.
/// @param logLevel is the level of the message to be printed.
/// @param formatString is the formatted string to print.
/// @param args is the va_list of arguments the formatString requires.
///
/// @return Returns a status integer corresponding to the status of the print
/// calls.
///
/// @note This function is one of the few that does not print out ENTER and
///       EXIT information to the log as that would create a situation of
///       infinite recursion.
int vprintBox(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, const char *formatString, va_list args
) {
  int returnValue = 0;
  va_list args2;
  
  if (_loggingInitialized == false) {
    loggingStart(NULL);
  }
  
  char *printString = NULL;
  straddstr(&printString, "| ");
  straddstr(&printString, formatString);
  if (printString == NULL) {
    // Memory allocation failure.  Bail.
    LOG_MALLOC_FAILURE();
    return -1;
  }
  int printStringLength = 0;
  printStringLength = (int) strlen(printString);
  if (printString[printStringLength - 1] == '\n') {
    printString[printStringLength - 1] = '\0';
  }
  straddstr(&printString, " |");
  
  // Get the length of the message to be printed.
  va_copy(args2, args);
  int bufferSize = 0;
  bufferSize = vsnprintf(NULL, 0, printString, args2);
  bufferSize++;
  va_end(args2);
  
  if (bufferSize > 4) { // space for "|  |"
    char *boxBorder = NULL;
    char *logHeader = NULL;
    if (_makeLogHeader != NULL) {
      logHeader = _makeLogHeader(logLevel, (char*)fileName,
        (char*)functionName, lineNumber);
    }
    
    straddchr(&printString, '\n');
    if (printString == NULL) {
      // Memory allocation failure.  Bail.
      LOG_MALLOC_FAILURE();
      return -1;
    }
    straddchr(&boxBorder, '+');
    // subtract 1 for \0 in bufferSize, and 1 for each '+' in border
    for (int i = 0; i < bufferSize - 3; i++) {
      straddchr(&boxBorder, '-');
    }
    straddchr(&boxBorder, '+');
    straddchr(&boxBorder, '\n');
    if (boxBorder == NULL) {
      // Memory allocation failure.  Bail.
      LOG_MALLOC_FAILURE();
      return -1;
    }
      
    // If we're debugging, send to stdout FIRST before we do anything fancy.
    // If we could not initialize the log file then logFile may be pointing to
    // stdout.  In this case we'll skip the debug print since it would echo
    // the same information to the same file descriptor twice which may be
    // confusing.
    if (logFile == DEBUG_LOGFILE_POINTER) {
      va_copy(args2, args);
      returnValue  = fputs(boxBorder, stdout);
      returnValue += vfprintf(stdout, printString, args2);
      returnValue += fputs(boxBorder, stdout);
      fflush(stdout);
      va_end(args2);
    }
    
    // Our lock on logging, if any.
    bool logLock = false;
    char *borderWithHeader = NULL;
    char *printStringWithHeader = NULL;
    char *expandedPrintString = NULL;
    straddstr(&borderWithHeader, logHeader);
    straddstr(&borderWithHeader, boxBorder);
    straddstr(&printStringWithHeader, logHeader);
    straddstr(&printStringWithHeader, printString);
    va_copy(args2, args);
    u64 length = 0;
    length = vasprintf(&expandedPrintString, printStringWithHeader, args2);
    va_end(args2);
    char *buffer = NULL;
    straddstr(&buffer, borderWithHeader);
    straddstr(&buffer, expandedPrintString);
    straddstr(&buffer, borderWithHeader);
    length *= 3;
    expandedPrintString = stringDestroy(expandedPrintString);
    borderWithHeader = stringDestroy(borderWithHeader);
    printStringWithHeader = stringDestroy(printStringWithHeader);
    boxBorder = stringDestroy(boxBorder);
    logHeader = stringDestroy(logHeader);
    
    if (buffer == NULL) {
      // Memory allocation failure.  Bail.
      printString = stringDestroy(printString);
      LOG_MALLOC_FAILURE();
      return -1;
    }
    
    // Disable logging for other functions on THIS thread while we're trying
    // to print.
    logLock = tryLockResource(loggingForbidden);
    if (logLock == true) {
      mtx_lock(&_headerMessageMutex);
      if (_encryptLogMessage != NULL) {
        if (_userPlaintextLogHandler != NULL) {
          // The user wants to log the plaintext message.  Do it.
          _userPlaintextLogHandler(buffer, length);
        }
        char *encryptedLogMessage = NULL;
        encryptedLogMessage = (char*) _encryptLogMessage((void*) buffer,
          &length, _encryptionKey);
        if (encryptedLogMessage != NULL) {
          buffer = stringDestroy(buffer);
          buffer = encryptedLogMessage;
        }
      }
      
      // Need to envoke the user's handler (if any) before queueing the
      // message to avoid _loggingQueueFunction freeing the buffer before
      // the user's handler processes it.
      if (_userLogHandler != NULL) {
        _userLogHandler(buffer, length);
      }
      
      LogMessage *message = (LogMessage*) malloc(sizeof(LogMessage));
      if ((_runLoggingQueueFunction == true) && (message != NULL)) {
        message->buffer = buffer;
        message->length = length;
        queuePushEntry(_logQueue, message);
        mtx_unlock(&_headerMessageMutex);
        mtx_lock(&_writeMessagesMutex);
        cnd_signal(&_writeMessagesCondition);
        mtx_unlock(&_writeMessagesMutex);
      } else {
        mtx_unlock(&_headerMessageMutex);
        // buffer didn't get queued, so won't be freed by
        // _loggingQueueFunction.  Free it here.
        buffer = stringDestroy(buffer);
        message = (LogMessage*) pointerDestroy(message);
      }
      
      // Unlock logging for the rest of the thread.
      unlockResource(loggingForbidden);
    } else {
      returnValue = -1;
    }
  } else {
    returnValue = bufferSize;
  }
  
  printString = stringDestroy(printString);
  
  return returnValue;
}

/// @fn int printBox_(const char *fileName, const char *functionName, int lineNumber, LogLevel logLevel, const char *formatString, ...)
///
/// @brief Prints a formatted string with an ASCII box around it to the log file
/// noting the log level IF the log level is above the threshold speciefied.
/// If the log level specified is not sufficient to warrant printing, the
/// function just returns as successful.
///
/// @details
/// Logs will take the following form:<br />
/// [log header] +---------------+<br />
/// [log header] | [log message] |<br />
/// [log header] +---------------+<br />
///
/// The contents of [log header] will be defined by the application-specific
/// function _makeLogHeader.  The contents of [log message] will be defined by
/// the format string and optional arguments.
///
/// This function is wrapped by a #define (without the leading underscore) that
/// automatically proivdes the fileName, functionName, and lineNumber arguments.
/// The caller need only provide the logLevel, format string, and optional
/// parameters.
///
/// @param fileName is the name of the file from which the call is made.
/// @param functionName is the name of the function making the call.
/// @param lineNumber is the line of the file the printBox call is made from.
/// @param logLevel is the level of the message to be printed.
/// @param formatString is the formatted string to print.
/// @param ... optional arguments may be provided depending on the formatString.
///
/// @return Returns a status integer corresponding to the status of the print
/// calls.
///
/// @note This function is one of the few that does not print out ENTER and
///       EXIT information to the log as that would create a situation of
///       infinite recursion.
int printBox_(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, const char *formatString, ...
) {
  int returnValue = 0;
  
  // Variable argument variables
  va_list args;
  
  va_start(args, formatString);
  returnValue = vprintBox(fileName, functionName, lineNumber, logLevel,
    formatString, args);
  va_end(args);
  
  return returnValue;
}

/// @var NUM_CHAR_ROWS
///
/// @brief This defines the number of rows a single banner character will use.
#define NUM_CHAR_ROWS 10

/// @var asciiCharset
///
/// @brief This array defines how letters will be printed in banner format.
extern const char *asciiCharset[128][NUM_CHAR_ROWS];

/// @fn int vprintBanner(const char *fileName, const char *functionName, int lineNumber, LogLevel logLevel, const char *formatString, va_list args)
///
/// @brief Prints a formatted string using the ASCII maps above to the log file
/// noting the log level IF the log level is above the threshold speciefied.
/// If the log level specified is not sufficient to warrant printing, the
/// function just returns as successful.
///
/// @details
/// Logs will take the following form:<br />
/// [log header]<br />
/// [log header] [log message]<br />
/// [log header] [log message]<br />
/// [log header] [log message]<br />
/// [log header] [log message]<br />
/// [log header] [log message]<br />
/// [log header] [log message]<br />
/// [log header] [log message]<br />
/// [log header] [log message]<br />
/// [log header] [log message]<br />
/// [log header]<br />
///
/// The contents of [log header] will be defined by the application-specific
/// function _makeLogHeader.  The contents of [log message] will be defined by
/// the format string and optional arguments and will be expanded using the
/// ASCII character maps below.
///
/// @param fileName is the name of the file from which the call is made.
/// @param functionName is the name of the function making the call.
/// @param lineNumber is the line of the file the printBanner call is made from.
/// @param logLevel is the level of the message to be printed.
/// @param formatString is the formatted string to print.
/// @param args is the va_list of arguments the formatString requires.
///
/// @return Returns a status integer corresponding to the status of the print
/// calls.
///
/// @note This function is one of the few that does not print out ENTER and
///       EXIT information to the log as that would create a situation of
///       infinite recursion.
int vprintBanner(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, const char *formatString, va_list args
) {
  int returnValue = 0;
  
  // Variable argument variables
  va_list args2;
  
  if (_loggingInitialized == false) {
    loggingStart(NULL);
  }
  
  // Our lock on logging, if any.
  bool logLock = false;
  
  // Disable logging for other functions on THIS thread while we're trying
  // to print.
  logLock = tryLockResource(loggingForbidden);
  if (logLock == true) {
    // Get the length of the message to be printed.
    va_copy(args2, args);
    int bufferSize = 0;
    bufferSize = vsnprintf(NULL, 0, formatString, args2);
    va_end(args2);
    
    if (bufferSize > 0) {
      bufferSize++;
      char *logHeader = NULL;
      int logHeaderLength = 0;
      mtx_lock(&_headerMessageMutex);
      if (_makeLogHeader != NULL) {
        logHeader = _makeLogHeader(logLevel, (char*)fileName,
          (char*)functionName, lineNumber);
        logHeaderLength = (int) strlen(logHeader);
      }
      
      char *printString = NULL;
      printString = (char*) malloc(bufferSize);
      if (printString == NULL) {
        // Memory allocation failure.  Bail.
        logHeader = stringDestroy(logHeader);
        mtx_unlock(&_headerMessageMutex);
        unlockResource(loggingForbidden);
        LOG_MALLOC_FAILURE();
        return -1;
      }
      va_copy(args2, args);
      returnValue = vsprintf(printString, formatString, args2);
      va_end(args2);
      int printStringLength = 0;
      printStringLength = (int) strlen(printString);
      if (printString[printStringLength - 1] == '\n') {
        printString[printStringLength - 1] = '\0';
        printStringLength--;
        bufferSize--;
      }
      
      char *unformattedPrintString = NULL;
      unformattedPrintString = unformatString(printString);
      if (unformattedPrintString == NULL) {
        // Memory allocation failure.  Bail.
        printString = stringDestroy(printString);
        logHeader = stringDestroy(logHeader);
        mtx_unlock(&_headerMessageMutex);
        unlockResource(loggingForbidden);
        LOG_MALLOC_FAILURE();
        return -1;
      }
      
      // If we're debugging, send to stdout FIRST before we do anything fancy.
      // If we could not initialize the log file then logFile may be pointing to
      // stdout.  In this case we'll skip the debug print since it would echo
      // the same information to the same file descriptor twice which may be
      // confusing.
      if (logFile == DEBUG_LOGFILE_POINTER) {
        fprintf(stdout, "\n");
        fprintf(stdout, "BANNER: ");
        fputs(unformattedPrintString, stdout);
        fprintf(stdout, "\n");
        fprintf(stdout, "\n");
        fflush(stdout);
      }
      
      char *buffer = NULL;
      u64 length = 0;
      
      straddstr(&buffer, logHeader);
      length += logHeaderLength;
      straddstr(&buffer, "BANNER: ");
      length += (int) strlen("BANNER: ");
      straddstr(&buffer, unformattedPrintString);
      length += (int) strlen(unformattedPrintString);
      straddstr(&buffer, "\n");
      length += 1;
      for (int i = 0; i < NUM_CHAR_ROWS; i++) {
        straddstr(&buffer, logHeader);
        length += logHeaderLength;
        for (int j = 0; j < printStringLength; j++) {
          // ASCII only defines the first 128 characters possible in a char
          // type, so limit what we add to what's defined.
          straddstr(&buffer, asciiCharset[(int) (printString[j] & 0x7f)][i]);
          straddstr(&buffer, " ");
          // There are five (5) characters per row of the asciiCharset array
          // and we have to add one extra space for padding between
          // characters, so increment our length by six (6).
          length += 6;
        }
        straddstr(&buffer, "\n");
        length += 1;
      }
      straddstr(&buffer, logHeader);
      length += logHeaderLength;
      straddstr(&buffer, "\n");
      length += 1;
      if (buffer == NULL) {
        // Memory allocation failure.  Bail.
        printString = stringDestroy(printString);
        logHeader = stringDestroy(logHeader);
        mtx_unlock(&_headerMessageMutex);
        unlockResource(loggingForbidden);
        LOG_MALLOC_FAILURE();
        return -1;
      }
      
      if (_encryptLogMessage != NULL) {
        if (_userPlaintextLogHandler != NULL) {
          // The user wants to log the plaintext message.  Do it.
          _userPlaintextLogHandler(buffer, length);
        }
        char *encryptedLogMessage = NULL;
        encryptedLogMessage = (char*) _encryptLogMessage((void*) buffer,
          &length, _encryptionKey);
        if (encryptedLogMessage != NULL) {
          buffer = stringDestroy(buffer);
          buffer = encryptedLogMessage;
        }
      }
      
      // Need to envoke the user's log handler (if any) before queueing
      // the buffer in case _loggingQueueFunction frees the buffer before
      // the user handles it.
      if (_userLogHandler != NULL) {
        _userLogHandler(buffer, length);
      }
      
      LogMessage *message = (LogMessage*) malloc(sizeof(LogMessage));
      if ((_runLoggingQueueFunction == true) && (message != NULL)) {
        message->buffer = buffer;
        message->length = length;
        queuePushEntry(_logQueue, message);
        mtx_lock(&_writeMessagesMutex);
        cnd_signal(&_writeMessagesCondition);
        mtx_unlock(&_writeMessagesMutex);
      } else {
        // buffer was not queued and so won't be freed by
        // _loggingQueueFunction.  Free it here.
        buffer = stringDestroy(buffer);
        message = (LogMessage*) pointerDestroy(message);
      }
      unformattedPrintString = stringDestroy(unformattedPrintString);
      
      printString = stringDestroy(printString);
      logHeader = stringDestroy(logHeader);
      
      mtx_unlock(&_headerMessageMutex);
    } else {
      returnValue = bufferSize;
    }
    // Unlock logging for the rest of the thread.
    unlockResource(loggingForbidden);
  } else {
    returnValue = -1;
  }
  
  return returnValue;
}

/// @fn int printBanner_(const char *fileName, const char *functionName, int lineNumber, LogLevel logLevel, const char *formatString, ...)
///
/// @brief Prints a formatted string using the ASCII maps above to the log file
/// noting the log level IF the log level is above the threshold speciefied.
/// If the log level specified is not sufficient to warrant printing, the
/// function just returns as successful.
///
/// @details
/// Logs will take the following form:<br />
/// [log header]<br />
/// [log header] [log message]<br />
/// [log header] [log message]<br />
/// [log header] [log message]<br />
/// [log header] [log message]<br />
/// [log header] [log message]<br />
/// [log header] [log message]<br />
/// [log header] [log message]<br />
/// [log header] [log message]<br />
/// [log header] [log message]<br />
/// [log header]<br />
///
/// The contents of [log header] will be defined by the application-specific
/// function _makeLogHeader.  The contents of [log message] will be defined by
/// the format string and optional arguments and will be expanded using the
/// ASCII character maps below.
///
/// This function is wrapped by a #define (without the leading underscore) that
/// automatically proivdes the fileName, functionName, and lineNumber arguments.
/// The caller need only provide the logLevel, format string, and optional
/// parameters.
///
/// @param fileName is the name of the file from which the call is made.
/// @param functionName is the name of the function making the call.
/// @param lineNumber is the line of the file the printBanner call is made from.
/// @param logLevel is the level of the message to be printed.
/// @param formatString is the formatted string to print.
/// @param ... optional arguments may be provided depending on the formatString.
///
/// @return Returns a status integer corresponding to the status of the print calls.
///
/// @note This function is one of the few that does not print out ENTER and
///       EXIT information to the log as that would create a situation of
///       infinite recursion.
int printBanner_(const char *fileName, const char *functionName, int lineNumber,
  LogLevel logLevel, const char *formatString, ...
) {
  int returnValue = 0;
  
  // Variable argument variables
  va_list args;
  
  va_start(args, formatString);
  returnValue = vprintBanner(fileName, functionName, lineNumber, logLevel,
    formatString, args);
  va_end(args);
  
  return returnValue;
}

/// @fn bool tryLockResource(tss_t resource)
///
/// @brief Attempts to lock a resource handled by the provided tss_t.  This
/// lock is in effect for all functions on this thread.  The intent is to
/// prevent issues of infinite recursion or recursive mutex locks.
///
/// @param resource The thread-specific storage for the resource.
///
/// @note This function may not make use of print functions.  They use this
/// function to determine if they can print.
///
/// @return Returns true on success, false on failure.
bool tryLockResource(tss_t resource) {
  bool returnValue = false;
  
  if (tss_get(resource) == NULL) {
    // Lock is not set.  Set it and return true.
    tss_set(resource, (void*) 1);
    returnValue = true;
  }
  
  return returnValue;
}

/// @fn void unlockResource(tss_t resource)
///
/// @brief Unlocks the resource for the thread.
///
/// @param resource The thread-specific storage for the resource.
///
/// @note This function may not make use of print functions.  They use this
/// function to determine if they can print.
///
/// @return There is no return value for this call.
void unlockResource(tss_t resource) {
  tss_set(resource, (void*) NULL);
  
  return;
}

/// @fn void setThreadLogThreshold(LogLevel threadLogThreshold)
///
/// @brief Set the thread-specific log threshold.
///
/// @param threadLogThreshold The LogLevel value to set for the thread-specific
///   log threshold.
///
/// @return This function returns no value.
void setThreadLogThreshold(LogLevel threadLogThreshold) {
  if (_threadLoggingThreshold_ != NULL) {
    tss_set(*_threadLoggingThreshold_,
      (void*) ((uintptr_t) threadLogThreshold));
  }
}

/// @def MAX_FRAMES
///
/// @brief The maximum number of stack frames that can be processed by
/// the printStackTrace function.
#define MAX_FRAMES 64

/// @fn void printStackTrace(LogLevel logLevel)
///
/// @brief Print the current call stack of the calling function.
///
/// @note Code must be linked with -rdynamic for this to work.
///
/// @param logLevel is the logging level at which the information should be
///   logged.  (This information will be printed if the log threshold is
///   less-than or equal to the log level.)
///
/// @return This function returns no value.

#if !_MSC_VER && !_WIN32

#include <execinfo.h>
#ifdef __cplusplus
#include <cxxabi.h>
#endif
void printStackTrace(LogLevel logLevel) {
  if (logLevel < CRITICAL) {
    if ((logLevel == NEVER) || (logLevel < logThreshold)
      || (logThreshold == NONE)
    ) {
      return;
    }
  }
  
  // Bypass all real memory allocation calls for the duration of this function.
  initAuxMemory();
  useAuxMemory();
  
  // Storage array for stack trace address data
  void *addressList[MAX_FRAMES];
  
  // Retrieve current stack addresses
  int addressLength = 0;
  addressLength
    = backtrace(addressList, sizeof(addressList) / sizeof(void*));
  
  if (addressLength == 0) {
    if ((logLevel >= CRITICAL) || (logFile == NULL)) {
      fputs("backtrace empty, possibly corrupt.\n", stderr);
    }
    if (logFile != NULL) {
      fputs("backtrace empty, possibly corrupt.\n", logFile);
    }
    useNormalMemory();
    return;
  }
  
  // We're bypassing real memory system calls right now, so we can safely call
  // malloc and allocate from our static buffer right now.  Just remember to
  // free it again later.  If it's reallocated by __cxa_demangle, that will go
  // through our bypass calls too, so no big deal.
  size_t functionNameSize = 128;
  char *functionName = (char*) malloc(functionNameSize);
  if (functionName == NULL) {
    LOG_MALLOC_FAILURE();
    useNormalMemory();
    return;
  }
  
  // FILEs that we're going to be printing to.
  FILE *outputFiles[] = {
    stderr,
    logFile
  };
  int startIndex = 1;
  int endIndex = numElements(outputFiles);
  if (logLevel >= CRITICAL) {
    startIndex = 0;
  }
  if (startIndex == 0) {
    if ((logFile == stderr) || (logFile == stdout)) {
      endIndex = 1;
    }
  }
  if (logFile == NULL) {
    startIndex = 0;
    endIndex = 1;
  }
  
  for (int j = startIndex; j < endIndex; j++) {
    FILE *outputFile = outputFiles[j];
    fputs("Stack trace:\n", outputFile);
    
    // Resolve addresses into strings containing "filename(function+address)".
    // This array must be freed later.
    char** symbolList = NULL;
    symbolList = backtrace_symbols(addressList, addressLength);
    
    // Iterate over the returned lines.  Skip the first since it's the
    // address of this function.
    for (int i = 1; i < addressLength; i++) {
      char *startOfName = NULL, *startOfOffset = NULL, *endOfOffset = NULL;
      
      // Find parentheses and address offset surrounding the mangled name.
      // Data takes the form:
      // module(function+0x###) [0x#######]
      for (char *c = symbolList[i]; *c != '\0'; c++) {
        if (*c == '(') {
          startOfName = c;
        } else if (*c == '+') {
          startOfOffset = c;
        } else if (*c == ')' && startOfOffset != NULL && *startOfOffset != '\0') {
          endOfOffset = c;
          break;
        }
      }
      
      if ((startOfName != NULL) && (*startOfName != '\0')
        && (startOfOffset != NULL) && (*startOfOffset != '\0')
        && (endOfOffset != NULL) && (*endOfOffset != '\0')
        && (startOfName < startOfOffset)) {
        *startOfName = '\0';
        startOfName++;
        *startOfOffset = '\0';
        startOfOffset++;
        *endOfOffset = '\0';
        
        // If we're using C++, mangled name is now in [startOfName, startOfOffset)
        // and caller offset is in [startOfOffset, endOfOffset).  We can use
        // __cxa_demangle() to get the real name of the function.  If we're using
        // straight C, then the plain name will be in [startOfName, startOfOffset)
        // and we need not do anything else.
#ifdef __cplusplus
        int status = 0;
        char *demangledFunctionName = abi::__cxa_demangle(startOfName,
          functionName, &functionNameSize, &status);
        if (demangledFunctionName != NULL) {
          functionName = demangledFunctionName;
        }
        if (status == 0) {
          fputs("  ", outputFile);
          fputs(symbolList[i], outputFile);
          fputs(": ", outputFile);
          fputs(functionName, outputFile);
          fputs("+", outputFile);
          fputs(startOfOffset, outputFile);
          fputs("\n", outputFile);
        } else {
          // Demangling failed. Output function name as a C function.
          // This print must work if at all possible.  Print to outputFile.
          fputs("  ", outputFile);
          fputs(symbolList[i], outputFile);
          fputs(": ", outputFile);
          fputs(startOfName, outputFile);
          fputs("()+", outputFile);
          fputs(startOfOffset, outputFile);
          fputs("\n", outputFile);
        }
#else
        (void) functionNameSize; // Avoid compiler warnings when compiled for C.
        // This print must work if at all possible.  Print to outputFile.
        fputs("  ", outputFile);
        fputs(symbolList[i], outputFile);
        fputs(": ", outputFile);
        fputs(startOfName, outputFile);
        fputs("()+", outputFile);
        fputs(startOfOffset, outputFile);
        fputs("\n", outputFile);
#endif
      } else {
        // We couldn't parse the line.  Print the whole line.
        // This print must work if at all possible.  Print to stderr.
        fputs("  ", outputFile);
        fputs(symbolList[i], stderr);
        fputs("\n", stderr);
      }
    }
    
    symbolList = (char**) pointerDestroy(symbolList);
  }
  
  // As a general rule, we want to avoid using raw free at all times and use a
  // proper, type-specific destructor.  However, all destructors make use of
  // printLog calls and we have to avoid that at all costs while printing a
  // stack trace.  So, just use the raw free function here.
  free(functionName); functionName  = NULL;
  
  // Resume regular memory allocation calls.
  useNormalMemory();
  return;
}

#else // _MSC_VER OR _WIN32 is defined

static inline char* u64ToHex(u64 number, char *buffer) {
  if (buffer == NULL) {
    return buffer;
  }
  
  int numBits = 0;
  u64 numberCopy = number;
  for (; numberCopy; numBits++, numberCopy >>= 1);
  int numBytes = (numBits >> 2) + 1;
  if ((numBits & (numBits - 1)) == 0) {
    // numBits is an even power of 2.  We've overallocated.
    numBytes--;
  }
  
  buffer[0]  = '0';
  buffer[1]  = 'x';
  buffer[2]  = '0';
  buffer[3]  = '0';
  buffer[4]  = '0';
  buffer[5]  = '0';
  buffer[6]  = '0';
  buffer[7]  = '0';
  buffer[8]  = '0';
  buffer[9]  = '0';
  buffer[10] = '0';
  buffer[11] = '0';
  buffer[12] = '0';
  buffer[13] = '0';
  buffer[14] = '0';
  buffer[15] = '0';
  buffer[16] = '0';
  buffer[17] = '0';
  
  u64 digitVal = 0;
  for (int ii = numBytes + 1; number; ii--, number >>= 4) {
    digitVal = number & ((u64) 0xf);
    if (digitVal < 10) {
      buffer[ii] = '0' + digitVal;
    } else {
      buffer[ii] = 'a' + (digitVal - 10);
    }
  }
  buffer[numBytes + 2]  = '\0';
  
  return buffer;
}

#include <dbghelp.h>
void printStackTrace(LogLevel logLevel) {
  if (logLevel < CRITICAL) {
    if ((logLevel == NEVER) || (logLevel < logThreshold)
      || (logThreshold == NONE)
    ) {
      return;
    }
  }
  
  // Bypass all real memory allocation calls for the duration of this function.
  initAuxMemory();
  useAuxMemory();
  
  HANDLE process = GetCurrentProcess();
  HANDLE thread = GetCurrentThread();
  CONTEXT context;
  ZEROINIT(STACKFRAME frame);
  DWORD machineType;
  ZEROINIT(char symbolBuffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME]);
  PSYMBOL_INFO symbol = (PSYMBOL_INFO) symbolBuffer;
  symbol->MaxNameLen = MAX_SYM_NAME;
  symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
  
  RtlCaptureContext(&context);
  
#ifdef _M_IX86
  machineType = IMAGE_FILE_MACHINE_I386;
  frame.AddrPC.Offset = context.Eip;
  frame.AddrPC.Mode = AddrModeFlat;
  frame.AddrFrame.Offset = context.Ebp;
  frame.AddrFrame.Mode = AddrModeFlat;
  frame.AddrStack.Offset = context.Esp;
  frame.AddrStack.Mode = AddrModeFlat;
#elif _M_X64
  machineType = IMAGE_FILE_MACHINE_AMD64;
  frame.AddrPC.Offset = context.Rip;
  frame.AddrPC.Mode = AddrModeFlat;
  frame.AddrFrame.Offset = context.Rsp;
  frame.AddrFrame.Mode = AddrModeFlat;
  frame.AddrStack.Offset = context.Rsp;
  frame.AddrStack.Mode = AddrModeFlat;
#else
  #error "Unsupported platform"
#endif
  
  DWORD options = SymGetOptions();
  SymSetOptions(options | SYMOPT_LOAD_LINES | SYMOPT_DEBUG);
  SymInitialize(process, NULL, TRUE);
  
  // FILEs that we're going to be printing to.
  FILE *outputFiles[] = {
    stderr,
    logFile
  };
  int startIndex = 1;
  int endIndex = numElements(outputFiles);
  if (logLevel >= CRITICAL) {
    startIndex = 0;
  }
  if (startIndex == 0) {
    if ((logFile == stderr) || (logFile == stdout)) {
      endIndex = 1;
    }
  }
  if (logFile == NULL) {
    startIndex = 0;
    endIndex = 1;
  }
  
  ZEROINIT(char hexBuffer[19]);
  DWORD64 address = 0;
  for (int ii = startIndex; ii < endIndex; ii++) {
    FILE *outputFile = outputFiles[ii];
    fputs("Stack trace:\n", outputFile);
    
    // The top of the stack is the printStackTrace function itself, which we
    // don't want to print.  Make sure we can do the first call, then enter the
    // main loop.
    if ((!StackWalk(
      machineType,
      process,
      thread,
      &frame,
      &context,
      NULL,
      SymFunctionTableAccess,
      SymGetModuleBase,
      NULL)) || (frame.AddrPC.Offset == 0)
    ) {
      break;
    }
    while (StackWalk(
      machineType,
      process,
      thread,
      &frame,
      &context,
      NULL,
      SymFunctionTableAccess,
      SymGetModuleBase,
      NULL)
    ) {
      address = frame.AddrPC.Offset;
      if (address == 0) {
        break;
      }
      
      DWORD64 displacement = 0;
      const char *functionName = "<UNKNOWN>";
      if (SymFromAddr(process, address, &displacement, symbol)) {
        functionName = symbol->Name;
      }
      fputs("  ", outputFile);
      fputs(u64ToHex(address, hexBuffer), outputFile);
      fputs(": ", outputFile);
      fputs(functionName, outputFile);
      fputs("()+", outputFile);
      fputs(u64ToHex(displacement, hexBuffer), outputFile);
      fputs("\n", outputFile);
    }
  }
  
  SymCleanup(process);
  SymSetOptions(options);
  
  // Resume regular memory allocation calls.
  useNormalMemory();
  return;
}

#endif // _MSC_VER

/// @var hostIsLittleEndian
///
/// @brief State variable to keep track of whether or not the host is a little
/// endian system.  If the value is less than 0, it has not been initialized.
static int hostIsLittleEndian = -1;

/// @fn u32 loggingGetThreadId()
///
/// @brief Get a 64-bit thread ID for the currently running thread.
///
/// @return Returns a 64-bit thread ID.
u64 loggingGetThreadId() {
  ZEROINIT(thrd_t threadIdRaw);
  threadIdRaw = thrd_current();
  
  if (hostIsLittleEndian < 0) {
    u32 multiByteValue = 1;
    if (*((u8*) &multiByteValue) == 1) {
      hostIsLittleEndian = 1;
    } else {
      hostIsLittleEndian = 0;
    }
  }
  
  if (hostIsLittleEndian == 0) {
    // Host is big endian.  Swap the bytes.
    u8 *bytes = (u8*) &threadIdRaw;
    size_t i = 0, j = 0;
    for (i = 0, j = sizeof(threadIdRaw) - 1; i < j; i++, j--) {
      u8 temp = bytes[i];
      bytes[i] = bytes[j];
      bytes[j] = temp;
    }
  }
  
  u64 threadId = 0;
  if (sizeof(threadIdRaw) >= sizeof(threadId)) {
    memcpy(&threadId, &threadIdRaw, sizeof(threadId));
  } else if (sizeof(threadIdRaw) == 4) {
    memcpy(&threadId, &threadIdRaw, 4);
  } else if (sizeof(threadIdRaw) == 2) {
    memcpy(&threadId, &threadIdRaw, 2);
  } else { // sizeof(threadIdRaw) == 1
    memcpy(&threadId, &threadIdRaw, 1);
  }
  littleEndianToHost(&threadId, sizeof(threadId));
  
  return threadId;
}

/// @fn LogLevel logLevelFromName(const char *levelName)
///
/// @brief Get a LogLevel given its textual representation.
///
/// @param levelName The textual representation (LogLevelName) of the log level.
///
/// @return Returns the corresponding LogLevel on success, NUM_LOG_LEVELS on
/// failure.
LogLevel logLevelFromName(const char *levelName) {
  LogLevel returnValue = NUM_LOG_LEVELS;
  
  if (levelName == NULL) {
    return NUM_LOG_LEVELS;
  }
  
  for (u32 i = FLOOD; i < NUM_LOG_LEVELS; i++) {
    if (strcmp(levelName, LogLevelName[i]) == 0) {
      // Log level found.
      returnValue = (LogLevel) i;
      break;
    }
  }
  
  return returnValue;
}

const char *asciiCharset[128][NUM_CHAR_ROWS] = {
  {
    "     ",
    "     ",
    "     ",
    " 0x00",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x01",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x02",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x03",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x04",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x05",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x06",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x07",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x08",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x09",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x0a",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x0b",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x0c",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x0d",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x0e",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x0f",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x10",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x11",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x12",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x13",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x14",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x15",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x16",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x17",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x18",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x19",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x1a",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x1b",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x1c",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x1d",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x1e",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x1f",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "  !  ",
    "  !  ",
    "  !  ",
    "  !  ",
    "  !  ",
    "     ",
    "  !  ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    " \" \" ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    " # # ",
    "#####",
    " # # ",
    "#####",
    " # # ",
    "     ",
    "     ",
    "     "
  },
  {
    "  $  ",
    " $$$ ",
    "$    ",
    " $$$ ",
    "    $",
    " $$$ ",
    "  $  ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "    %",
    " % % ",
    "  %  ",
    " % % ",
    "%    ",
    "     ",
    "     ",
    "     "
  },
  {
    " &&  ",
    "&  & ",
    "&  & ",
    " &&  ",
    "&  & ",
    "&  & ",
    " && &",
    "     ",
    "     ",
    "     "
  },
  {
    "  '  ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "   ( ",
    "  (  ",
    " (   ",
    " (   ",
    " (   ",
    "  (  ",
    "   ( ",
    "     ",
    "     ",
    "     "
  },
  {
    " )   ",
    "  )  ",
    "   ) ",
    "   ) ",
    "   ) ",
    "  )  ",
    " )   ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "* * *",
    " *** ",
    "  *  ",
    " *** ",
    "* * *",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "  +  ",
    "  +  ",
    "+++++",
    "  +  ",
    "  +  ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    " ,,  ",
    "  ,  ",
    " ,   ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    "-----",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "..   ",
    "..   ",
    "     ",
    "     ",
    "     "
  },
  {
    "    /",
    "   / ",
    "   / ",
    "  /  ",
    " /   ",
    " /   ",
    "/    ",
    "     ",
    "     ",
    "     "
  },
  {
    " 000 ",
    "0   0",
    "0  00",
    "0 0 0",
    "00  0",
    "0   0",
    " 000 ",
    "     ",
    "     ",
    "     "
  },
  {
    "111  ",
    "  1  ",
    "  1  ",
    "  1  ",
    "  1  ",
    "  1  ",
    "11111",
    "     ",
    "     ",
    "     "
  },
  {
    " 222 ",
    "2   2",
    "    2",
    "  22 ",
    " 2   ",
    "2    ",
    "22222",
    "     ",
    "     ",
    "     "
  },
  {
    " 333 ",
    "3   3",
    "    3",
    "  33 ",
    "    3",
    "3   3",
    " 333 ",
    "     ",
    "     ",
    "     "
  },
  {
    "   4 ",
    "  44 ",
    " 4 4 ",
    "4  4 ",
    "44444",
    "   4 ",
    "   4 ",
    "     ",
    "     ",
    "     "
  },
  {
    "55555",
    "5    ",
    "5    ",
    " 555 ",
    "    5",
    "5   5",
    " 555 ",
    "     ",
    "     ",
    "     "
  },
  {
    " 666 ",
    "6    ",
    "6    ",
    "6666 ",
    "6   6",
    "6   6",
    " 666 ",
    "     ",
    "     ",
    "     "
  },
  {
    "77777",
    "   7 ",
    "   7 ",
    "  7  ",
    " 7   ",
    " 7   ",
    "7    ",
    "     ",
    "     ",
    "     "
  },
  {
    " 888 ",
    "8   8",
    "8   8",
    " 888 ",
    "8   8",
    "8   8",
    " 888 ",
    "     ",
    "     ",
    "     "
  },
  {
    " 999 ",
    "9   9",
    "9   9",
    " 9999",
    "    9",
    "    9",
    " 999 ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    " ::: ",
    " ::: ",
    "     ",
    " ::: ",
    " ::: ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    " ;;; ",
    " ;;; ",
    "     ",
    " ;;; ",
    " ;;; ",
    " ;;  ",
    "     ",
    "     ",
    "     "
  },
  {
    "    <",
    "   < ",
    " <   ",
    "<    ",
    " <   ",
    "   < ",
    "    <",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    " === ",
    "     ",
    " === ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    ">    ",
    " >   ",
    "   > ",
    "    >",
    "   > ",
    " >   ",
    ">    ",
    "     ",
    "     ",
    "     "
  },
  {
    " ??? ",
    "?   ?",
    "    ?",
    "  ?? ",
    "  ?  ",
    "     ",
    "  ?  ",
    "     ",
    "     ",
    "     "
  },
  {
    " @@@ ",
    "@   @",
    "@  @@",
    "@ @ @",
    "@  @@",
    "@    ",
    " @@@ ",
    "     ",
    "     ",
    "     "
  },
  {
    "  A  ",
    " A A ",
    "A   A",
    "A   A",
    "AAAAA",
    "A   A",
    "A   A",
    "     ",
    "     ",
    "     "
  },
  {
    "BBBB ",
    "B   B",
    "B   B",
    "BBBB ",
    "B   B",
    "B   B",
    "BBBB ",
    "     ",
    "     ",
    "     "
  },
  {
    " CCC ",
    "C   C",
    "C    ",
    "C    ",
    "C    ",
    "C   C",
    " CCC ",
    "     ",
    "     ",
    "     "
  },
  {
    "DDDD ",
    "D   D",
    "D   D",
    "D   D",
    "D   D",
    "D   D",
    "DDDD ",
    "     ",
    "     ",
    "     "
  },
  {
    "EEEEE",
    "E    ",
    "E    ",
    "EEEE ",
    "E    ",
    "E    ",
    "EEEEE",
    "     ",
    "     ",
    "     "
  },
  {
    "FFFFF",
    "F    ",
    "F    ",
    "FFFF ",
    "F    ",
    "F    ",
    "F    ",
    "     ",
    "     ",
    "     "
  },
  {
    " GGG ",
    "G   G",
    "G    ",
    "G  GG",
    "G   G",
    "G   G",
    " GGG ",
    "     ",
    "     ",
    "     "
  },
  {
    "H   H",
    "H   H",
    "H   H",
    "HHHHH",
    "H   H",
    "H   H",
    "H   H",
    "     ",
    "     ",
    "     "
  },
  {
    "IIIII",
    "  I  ",
    "  I  ",
    "  I  ",
    "  I  ",
    "  I  ",
    "IIIII",
    "     ",
    "     ",
    "     "
  },
  {
    " JJJJ",
    "    J",
    "    J",
    "    J",
    "    J",
    "J   J",
    " JJJ ",
    "     ",
    "     ",
    "     "
  },
  {
    "K   K",
    "K  K ",
    "K K  ",
    "KK   ",
    "K K  ",
    "K  K ",
    "K   K",
    "     ",
    "     ",
    "     "
  },
  {
    "L    ",
    "L    ",
    "L    ",
    "L    ",
    "L    ",
    "L    ",
    "LLLLL",
    "     ",
    "     ",
    "     "
  },
  {
    "M   M",
    "MM MM",
    "M M M",
    "M   M",
    "M   M",
    "M   M",
    "M   M",
    "     ",
    "     ",
    "     "
  },
  {
    "N   N",
    "NN  N",
    "NN  N",
    "N N N",
    "N  NN",
    "N  NN",
    "N   N",
    "     ",
    "     ",
    "     "
  },
  {
    " OOO ",
    "O   O",
    "O   O",
    "O   O",
    "O   O",
    "O   O",
    " OOO ",
    "     ",
    "     ",
    "     "
  },
  {
    "PPPP ",
    "P   P",
    "P   P",
    "PPPP ",
    "P    ",
    "P    ",
    "P    ",
    "     ",
    "     ",
    "     "
  },
  {
    " QQQ ",
    "Q   Q",
    "Q   Q",
    "Q   Q",
    "Q Q Q",
    "Q  QQ",
    " QQQQ",
    "     ",
    "     ",
    "     "
  },
  {
    "RRRR ",
    "R   R",
    "R   R",
    "RRRR ",
    "R R  ",
    "R  R ",
    "R   R",
    "     ",
    "     ",
    "     "
  },
  {
    " SSS ",
    "S   S",
    "S    ",
    " SSS ",
    "    S",
    "S   S",
    " SSS ",
    "     ",
    "     ",
    "     "
  },
  {
    "TTTTT",
    "  T  ",
    "  T  ",
    "  T  ",
    "  T  ",
    "  T  ",
    "  T  ",
    "     ",
    "     ",
    "     "
  },
  {
    "U   U",
    "U   U",
    "U   U",
    "U   U",
    "U   U",
    "U   U",
    " UUU ",
    "     ",
    "     ",
    "     "
  },
  {
    "V   V",
    "V   V",
    "V   V",
    " V V ",
    " V V ",
    " V V ",
    "  V  ",
    "     ",
    "     ",
    "     "
  },
  {
    "W   W",
    "W   W",
    "W   W",
    "W   W",
    "W W W",
    "W W W",
    " WWW ",
    "     ",
    "     ",
    "     "
  },
  {
    "X   X",
    "X   X",
    " X X ",
    "  X  ",
    " X X ",
    "X   X",
    "X   X",
    "     ",
    "     ",
    "     "
  },
  {
    "Y   Y",
    "Y   Y",
    " Y Y ",
    "  Y  ",
    "  Y  ",
    "  Y  ",
    "  Y  ",
    "     ",
    "     ",
    "     "
  },
  {
    "ZZZZZ",
    "    Z",
    "   Z ",
    "  Z  ",
    " Z   ",
    "Z    ",
    "ZZZZZ",
    "     ",
    "     ",
    "     "
  },
  {
    "[[[  ",
    "[    ",
    "[    ",
    "[    ",
    "[    ",
    "[    ",
    "[[[  ",
    "     ",
    "     ",
    "     "
  },
  {
    "\\    ",
    " \\   ",
    " \\   ",
    "  \\  ",
    "   \\ ",
    "   \\ ",
    "    \\",
    "     ",
    "     ",
    "     "
  },
  {
    "  ]]]",
    "    ]",
    "    ]",
    "    ]",
    "    ]",
    "    ]",
    "  ]]]",
    "     ",
    "     ",
    "     "
  },
  {
    "  ^  ",
    " ^ ^ ",
    "^   ^",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "_____",
    "     ",
    "     ",
    "     "
  },
  {
    "  `  ",
    "   ` ",
    "    `",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "  aa ",
    "    a",
    " aaaa",
    "a   a",
    " aaaa",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "b    ",
    "b    ",
    "bbbb ",
    "b   b",
    "b   b",
    "bbbb ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " ccc ",
    "c    ",
    "c    ",
    " ccc ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "    d",
    "    d",
    " dddd",
    "d   d",
    "d   d",
    " dddd",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    " eee ",
    "e   e",
    "eeeee",
    "e    ",
    " eee ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "   ff",
    "  f  ",
    "  f  ",
    " fff ",
    "  f  ",
    "  f  ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " gggg",
    "g   g",
    "g   g",
    " gggg",
    "    g",
    "g   g",
    " ggg "
  },
  {
    "     ",
    "h    ",
    "h    ",
    "hhhh ",
    "h   h",
    "h   h",
    "h   h",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "  i  ",
    "     ",
    " ii  ",
    "  i  ",
    "  i  ",
    " iii ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "   j ",
    "     ",
    "  jj ",
    "   j ",
    "   j ",
    "   j ",
    "   j ",
    "   j ",
    " jjj "
  },
  {
    "k    ",
    "k    ",
    "k   k",
    "k k  ",
    "kk   ",
    "k k  ",
    "k   k",
    "     ",
    "     ",
    "     "
  },
  {
    " ll  ",
    "  l  ",
    "  l  ",
    "  l  ",
    "  l  ",
    "  l  ",
    "   ll",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    "mmmm ",
    "m m m",
    "m m m",
    "m m m",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    "nnnn ",
    "n   n",
    "n   n",
    "n   n",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " ooo ",
    "o   o",
    "o   o",
    " ooo ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    "pppp ",
    "p   p",
    "p   p",
    "pppp ",
    "p    ",
    "p    ",
    "p    "
  },
  {
    "     ",
    "     ",
    "     ",
    " qqqq",
    "q   q",
    "q   q",
    " qqqq",
    "    q",
    "    q",
    "    q"
  },
  {
    "     ",
    "     ",
    "     ",
    "rrrr ",
    "r   r",
    "r    ",
    "r    ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    " sss ",
    "s    ",
    " sss ",
    "    s",
    " sss ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "  t  ",
    " tttt",
    "  t  ",
    "  t  ",
    "  ttt",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    "u   u",
    "u   u",
    "u   u",
    " uuu ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    "v   v",
    " v v ",
    " v v ",
    "  v  ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    "w   w",
    "w   w",
    "w w w",
    " www ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "x   x",
    " x x ",
    "  x  ",
    " x x ",
    "x   x",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    "y   y",
    " y  y",
    "  y y",
    "   y ",
    "   y ",
    "   y ",
    " yy  "
  },
  {
    "     ",
    "     ",
    "zzzzz",
    "   z ",
    "  z  ",
    " z   ",
    "zzzzz",
    "     ",
    "     ",
    "     "
  },
  {
    "   { ",
    "  {  ",
    "  {  ",
    " {   ",
    "  {  ",
    "  {  ",
    "   { ",
    "     ",
    "     ",
    "     "
  },
  {
    "  |  ",
    "  |  ",
    "  |  ",
    "  |  ",
    "  |  ",
    "  |  ",
    "  |  ",
    "     ",
    "     ",
    "     "
  },
  {
    " }   ",
    "  }  ",
    "  }  ",
    "   } ",
    "  }  ",
    "  }  ",
    " }   ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    " ~   ",
    "~ ~ ~",
    "   ~ ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  },
  {
    "     ",
    "     ",
    "     ",
    " 0x7f",
    "     ",
    "     ",
    "     ",
    "     ",
    "     ",
    "     "
  }
};

