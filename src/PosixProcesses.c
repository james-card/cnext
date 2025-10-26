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

#ifndef _MSC_VER

#include "PosixProcesses.h"
#include "DirectoryLib.h"
#include "StringLib.h"
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>
#include <signal.h>


/// @fn char** posixProcessesFreeArgArray(char **args)
///
/// @brief Free a previously-allocated arguments array.
///
/// @param args is the array of arguments to free.
///
/// @return This function returns no value.
char** posixProcessesFreeArgArray(char **args) {
  if (args != NULL) {
    for (int i = 0; args[i] != NULL; i++) {
      free(args[i]); args[i] = NULL;
    }
    free(args); args = NULL;
  }
  return NULL;
}

/// @fn char** posixProcessesStringToStringArray(const char *input, const char *fieldDelimiter)
///
/// Convert a fieldDelim-separated string into a single-dimensional,
///   null-terminated array of strings.
///
/// @param input The string to convert.
/// @param fieldDelimiter The field delimiter string.
///
/// @return Returns a null-terminated, one-dimensional array of C strings
///   on success, NULL on failure.
char** posixProcessesStringToStringArray(const char *input, const char *fieldDelimiter) {
  char **returnValue = NULL;
  int numFields = 0;
  const char *nextField = NULL;
  
  if ((input == NULL) || (fieldDelimiter == NULL)) {
    return NULL;
  }
  
  returnValue = (char**) malloc(sizeof(char**));
  if (returnValue == NULL) {
    // Memory allocation failure.  Just fail.
    return NULL;
  }
  returnValue[0] = NULL;
  
  size_t fieldDelimiterLength = strlen(fieldDelimiter);
  size_t inputLength = strlen(input);
  char *inputCopy = (char*) malloc(inputLength + 1);
  strcpy(inputCopy, input);
  
  nextField = inputCopy;
  while (nextField) {
    const char *field = nextField;
    char *delimiterAt = (char*) strstr(nextField, fieldDelimiter);
    if (delimiterAt != NULL) {
      *delimiterAt = '\0';
    }
    size_t fieldLength = strlen(field);
    
    numFields++;
    void* check = realloc(returnValue,
      ((numFields + 1) * sizeof(char*)));
    if (check == NULL) {
      // Memory allocation failure.  Just fail.
      posixProcessesFreeArgArray(returnValue);
      free(inputCopy);
      return NULL;
    }
    returnValue = (char**) check;
    check = malloc(fieldLength + 1);
    if (check == NULL) {
      // Memory allocation failure.  Just fail.
      posixProcessesFreeArgArray(returnValue);
      free(inputCopy);
      return NULL;
    }
    returnValue[numFields - 1] = (char*) check;
    strcpy(returnValue[numFields - 1], field);
    returnValue[numFields] = NULL;
    
    if (delimiterAt != NULL) {
      nextField += fieldLength + fieldDelimiterLength;
    } else {
      // We're processing the last field.
      nextField = NULL;
    }
  };
  free(inputCopy);
  
  return returnValue;
}

/// @fn char** posixProcessesStringToArgs(const char *parseString)
///
/// @brief Convert a string of space-delimited arguments into an array of
/// separate string pointers.
///
/// @param parseString is the string to parse.
///
/// @return Returns an array of argument strings on success, NULL otherwise.
char** posixProcessesStringToArgs(const char *parseString) {
  char **argArray = NULL;
  argArray = posixProcessesStringToStringArray(parseString, " ");
  if (argArray == NULL) {
    return NULL;
  }
  void *check = NULL;
  
  int i = 0, j = 0;
  while (argArray[i] != NULL) {
    if ((*argArray[i] == '"')
      && (argArray[i][strlen(argArray[i]) - 1] != '"')
    ) {
      // Erase the opening double-qoute.
      int iLength = strlen(argArray[i]);
      for (j = 0; j < iLength; j++) {
        argArray[i][j] = argArray[i][j + 1];
      }
      iLength--;
      argArray[i][j] = '\0';
      // Look for closing double-quote.
      j = i + 1;
      while (argArray[j] != NULL) {
        int jLength = strlen(argArray[j]);
        if ((argArray[j][jLength - 1] == '"')
          && ((jLength == 1) || (argArray[j][jLength - 2] != '\\'))
        ) {
          // Closing double-quote found.
          if (jLength > 1) {
            // Terminate the argument at the double-quote.
            jLength--;
          }
          argArray[j][jLength] = '\0';
          check = realloc(argArray[i], iLength + jLength + 2);
          if (check == NULL) {
            // Memory allocation failure.  Fail.
            argArray = posixProcessesFreeArgArray(argArray);
            return NULL;
          }
          argArray[i] = (char*) check;
          strcat(argArray[i], " ");
          strcat(argArray[i], argArray[j]);
          break;
        }
        check = realloc(argArray[i], iLength + jLength + 2);
        if (check == NULL) {
          // Memory allocation failure.  Fail.
          argArray = posixProcessesFreeArgArray(argArray);
          return NULL;
        }
        argArray[i] = (char*) check;
        strcat(argArray[i], " ");
        strcat(argArray[i], argArray[j]);
        iLength += jLength + 1;
        j++;
      }
    } else if (*argArray[i] == '"') {
      // argArray[i][strlen(argArray[i]) - 1] == '"'
      // Erase both double-quotes.
      int iLength = strlen(argArray[i]);
      for (j = 0; j < iLength - 2; j++) {
        argArray[i][j] = argArray[i][j + 1];
      }
      argArray[i][j] = '\0';
      j = i; // Don't trip the argument shift below.
    } else if ((*argArray[i] == '\'')
      && (argArray[i][strlen(argArray[i]) - 1] != '\'')
    ) {
      // Erase the opening single-qoute.
      int iLength = strlen(argArray[i]);
      for (j = 0; j < iLength; j++) {
        argArray[i][j] = argArray[i][j + 1];
      }
      iLength--;
      argArray[i][j] = '\0';
      // Look for closing single-quote.
      j = i + 1;
      while (argArray[j] != NULL) {
        int jLength = strlen(argArray[j]);
        if ((argArray[j][jLength - 1] == '\'')
          && ((jLength == 1) || (argArray[j][jLength - 2] != '\\'))
        ) {
          // Closing single-quote found.
          if (jLength > 1) {
            // Terminate the argument at the single-quote.
            jLength--;
          }
          argArray[j][jLength] = '\0';
          check = realloc(argArray[i], iLength + jLength + 2);
          if (check == NULL) {
            // Memory allocation failure.  Fail.
            argArray = posixProcessesFreeArgArray(argArray);
            return NULL;
          }
          argArray[i] = (char*) check;
          strcat(argArray[i], " ");
          strcat(argArray[i], argArray[j]);
          break;
        }
        check = realloc(argArray[i], iLength + jLength + 2);
        if (check == NULL) {
          // Memory allocation failure.  Fail.
          argArray = posixProcessesFreeArgArray(argArray);
          return NULL;
        }
        argArray[i] = (char*) check;
        strcat(argArray[i], " ");
        strcat(argArray[i], argArray[j]);
        iLength += jLength + 1;
        j++;
      }
    } else if (*argArray[i] == '\'') {
      // argArray[i][strlen(argArray[i]) - 1] != '\''
      // Erase both single-quotes.
      int iLength = strlen(argArray[i]);
      for (j = 0; j < iLength - 2; j++) {
        argArray[i][j] = argArray[i][j + 1];
      }
      argArray[i][j] = '\0';
      j = i; // Don't trip the argument shift below.
    }
    
    if (j > i) {
      // Shift all the arguments down to the appropriate places.
      int k = 0;
      // First free and clear all the intermediaries
      for (k = i + 1; k <= j; k++) {
        free(argArray[k]); argArray[k] = NULL;
      }
      // Next, slide down all the remaining arguments
      if (argArray[j] != NULL) {
        for (k = j + 1, j = i + 1; argArray[k] != NULL; k++) {
          argArray[j] = argArray[k];
          j++;
        }
        // Lastly, copy over the NULL terminator at argArray[k]
        argArray[j] = argArray[k];
      }
      
      i++;
      j = i;
    } else {
      i++;
      j = i;
    }
  }
  
  return argArray;
}

/// @fn bool startPosixProcess(const char *args, uint32_t *processId, FILE **readFile, FILE **writeFile, const char* workingDirectory, char* environmentVariables[])
///
/// @brief Start a process and set up file descriptors for read-write access.
///
/// @param args is an unparsed string containing the name of the program to
///   run and the arguments with which to call it.  It will be parsed by this
///   function.
/// @param processId is the PID of the process that is started upon success
/// @param readFile is the FILE object used to read data from the program
/// @param writeFile is the FILE object used to write data to the program
/// @param workingDirectory The full path to the working directory for the
///   child process.  A value of NULL will use the parent's working directory
/// @param environmentVariables A NULL-terminated, one-dimensional array of
///   environment variables and their values in "name=value" format.  A value
///   of NULL will use the parent's environment variables.
///
/// @return Returns true on success, false otherwise
bool startPosixProcess(
  const char *args, uint32_t *processId, FILE **readFile, FILE **writeFile,
  const char* workingDirectory, char* environmentVariables[]
) {
  char **argArray = posixProcessesStringToArgs(args);
  
  int  pipeId[2];
  bool returnValue = false;
  const int stdIn  = 0;
  const int stdOut = 1;
  const int stdErr = 2;
  
  if (pipe(pipeId) >= 0) {
    *processId = fork();
    if (*processId > 0) {
      // We are the parent.
      int flags = 0;
      
      *readFile = fdopen(pipeId[stdIn], "r");
      flags = fcntl(fileno(*readFile), F_GETFL, 0);
      flags |= O_NONBLOCK;
      fcntl(fileno(*readFile), F_SETFL, flags);
      
      *writeFile = fdopen(pipeId[stdOut], "w");
      flags = fcntl(fileno(*readFile), F_GETFL, 0);
      flags |= O_NONBLOCK;
      fcntl(fileno(*readFile), F_SETFL, flags);
      
      returnValue = true;
    } else if (*processId == 0) {
      // We are the child.
      // This process will become the process to run.  Setup and go.
      // Note that this portion should not produce log output of any level since
      // it will be almost guaranteed to mangle the log file.  If we must have
      // log output, it should be ONLY at the DEBUG level.
      if (workingDirectory != NULL) {
        chdir(workingDirectory);
      }
      
      bool dupSucceeded = true;
      
      // Make our process id the process group leader.
      setpgid(0, 0);
      
      fflush(stdout);
      fflush(stderr);
      
      // Set up new file descriptors for stdin, stdout, stderr
      close(stdIn);
      if (dup(pipeId[stdIn]) < 0) {
        dupSucceeded = false;
        perror("dup of stdin for pipe failed");
      }
      close(stdOut);
      if (dup(pipeId[stdOut]) < 0) {
        dupSucceeded = false;
        perror("dup of stdout for pipe failed");
      }
      close(stdErr);
      if (dup(pipeId[stdOut]) < 0) { // stderr goes to stdout
        dupSucceeded = false;
        perror("dup of stderr for pipe failed");
      }
      
      if (dupSucceeded == true) {
        // Close these since we dup()'ed what we needed.
        close(pipeId[stdIn]);
        close(pipeId[stdOut]);
      }
      
      // Close any other file descriptors we inherited from the parent.
      for (int i = 3; i < FD_SETSIZE; i++) {
        int fd = dup(i);
        if (fd >= 0) {
          close(fd);
          close(i);
        }
      }
      
      if (argArray == NULL) {
        // Parsing the command failed.  Alert the parent and exit.
        fprintf(stderr, "Could not parse command line \"%s\".\n", args);
        fprintf(stderr, "Exiting.\n");
        exit(1);
      }
      
      execve(argArray[0], argArray, environmentVariables);
      
      // If we get this far then the command above failed.
      // Since we forked above, continuing on will spawn off more instances
      // of the process.  Exit to avoid that scenario.
      fprintf(stderr, "startPosixProcess(): execve(%s) failed!\n", argArray[0]);
      fprintf(stderr, "[ERROR] %s\n", strerror(errno));
      argArray = posixProcessesFreeArgArray(argArray);
      exit(1);
    } else { // fork() failed.  Major system problem.
      close(pipeId[stdIn]);
      close(pipeId[stdOut]);
      fprintf(stderr, "startPosixProcess(): fork() failed\n");
    }
  } else {
    // We couldn't create a pipe.  Why?
    if (errno == EFAULT) {
      fprintf(stderr, "pipefd is not valid.\n");
    } else if (errno == EINVAL) {
      fprintf(stderr, "(pipe2()) Invalid value in flags.\n");
    } else if (errno == EMFILE) {
      fprintf(stderr,
        "The per-process limit on the number of open file descriptors "
        "has been reached.\n");
    } else if (errno == ENFILE) {
      fprintf(stderr,
        "The system-wide limit on the total number of open files "
        "has been reached.\n");
    } else {
      fprintf(stderr, "Unknown error in pipe().\n");
    }
  }
  
  argArray = posixProcessesFreeArgArray(argArray);
  return returnValue;
}

/// @var environ
///
/// @brief NULL-terminated, one-dimensional array of environment variables in
/// name=value format.
extern char **environ;

/// @fn Process* startProcess_(const char *commandLineArgs, const char *workingDirectory, char *environmentVariables[], ...)
///
/// @brief Start a process specified by a command and its arguments.
///
/// @param commandLineArgs A single string containing the full path to the
///   command binary and all of its arguments.
/// @param workingDirectory The full path to the working directory for the
///   child process.  A value of NULL will use the parent's working directory
/// @param environmentVariables A NULL-terminated, one-dimensional array of
///   environment variables and their values in "name=value" format.  A value
///   of NULL will use the parent's environment variables.
/// @param ... All further parameters are ignored.
///
/// @return Returnss a pointer to a Process instance on success,
/// NULL on failure.
Process* startProcess_(const char* commandLineArgs,
  const char *workingDirectory, char *environmentVariables[], ...
) {
  Process *returnValue = (Process*) calloc(1, sizeof(Process));
  if (environmentVariables == NULL) {
    environmentVariables = environ;
  }
  if (!startPosixProcess(commandLineArgs, &returnValue->processId,
    &returnValue->stdOut, &returnValue->stdIn,
    workingDirectory, environmentVariables)
  ) {
    // Could not start the process.
    free(returnValue); returnValue = NULL;
  }
  
  return returnValue;
}

/// @fn bool processHasExited(Process *process)
///
/// @brief Determine whether or not a process has exited.
///
/// @param process A pointer to a Process instance.
///
/// @return Returns true if the process has exited, false if not.
bool processHasExited(Process *process) {
  if ((process == NULL) || (process->killed == true)) {
    return true;
  }
  
  if (process->processStatus == 0) {
    // Collect the status.
    if (waitpid(process->processId, &process->processStatus, WNOHANG) <= 0) {
      return false;
    }
  }

  // Check the state of the process and report accordingly.
  return (WIFEXITED(process->processStatus)
    || WIFSIGNALED(process->processStatus));
}

/// @fn int processExitStatus(Process *process)
///
/// @brief Get the exit status of a completed process.
///
/// @param process A pointer to a Process instance.
/// 
/// @return Returns the positive exit status on success, negative value if the
/// process did not exit normally (and therefore did not provide an exit
/// status).
int processExitStatus(Process *process) {
  if ((WIFSIGNALED(process->processStatus)) || (process->killed == true)) {
    // Process exited abnormally.
    return -1;
  }
  
  return WEXITSTATUS(process->processStatus);
}

/// @fn char* readProcessStdout_(Process *process, uint64_t *outputLength, ...)
///
/// @brief Read from a process's stdout pipe until the pipe is empty.
///
/// @param process A pointer to a Process instance.
/// @param outputLength A pointer to a uint64_t value that will hold the length
///   of the returned output.
/// @param ... All further parameters are ignored.
///
/// @return Returns a Bytes object with the contents of the process's stdout
/// on success, NULL on failure.
char* readProcessStdout_(Process *process, uint64_t *outputLength, ...) {
  uint32_t bufferSize = 4096;
  char *processOutput = NULL;
  size_t processOutputLength = 0;
  
  char tempBuffer[4096];
  
  // In the event that the user has given us a bad command to run, we
  // might wind up in a situation where fread blocks forever.  Need to
  // put the file descriptor in non-blocking mode to avoid this.
  // JBC 2020-09-24
  int fd = fileno(process->stdOut);
  
  size_t numBytesRead = 0;
  do {
    fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | O_NONBLOCK);
    numBytesRead = fread(tempBuffer, 1, bufferSize, process->stdOut);
    fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) & ~O_NONBLOCK);
    if (numBytesRead > 0) {
      void* check = realloc(processOutput,
        processOutputLength + (size_t) numBytesRead + 1);
      if (check == NULL) {
        // Memory allocation failure.  Just fail.
        free(processOutput);
        return NULL;
      }
      processOutput = (char*) check;
      memcpy(&processOutput[processOutputLength], tempBuffer, numBytesRead);
      processOutputLength += (size_t) numBytesRead;
      processOutput[processOutputLength] = '\0';
    }
  } while (numBytesRead > 0);
  
  if (outputLength != NULL) {
    *outputLength = (uint64_t) processOutputLength;
  }
  return processOutput;
}

/// @fn bool writeProcessStdin_(Process *process, const char *data, uint64_t dataLength, ...)
///
/// @brief Write to a process's stdin pipe.
///
/// @param process A pointer to a Process instance.
/// @param data A pointer to a C string with the data to write to the process's
///   stdin buffer.
/// @param dataLength The length of the data pointed to by data.
/// @param ... All further parameters are ignored.
///
/// @return Returns true on a successful write (all bytes were written),
/// false on failure.
bool writeProcessStdin_(Process *process, const char* data, uint64_t dataLength, ...) {
  if ((dataLength == 0) && (data != NULL)) {
    dataLength = (uint64_t) strlen(data);
  }
  size_t numBytesWritten = fwrite(data, dataLength, 1, process->stdIn);
  return (((uint64_t) numBytesWritten) == dataLength);
}

/// @fn Process* closeProcess(Process *process)
///
/// @brief Close a process and all its associated information and deallocate
/// the Process instance.
///
/// @param process A pointer to a Process instance.
///
/// @return This function always succeeds and always returns NULL.
Process* closeProcess(Process *process) {
  process->processId = 0;
  fclose(process->stdOut); process->stdOut = NULL;
  fclose(process->stdIn); process->stdIn = NULL;
  free(process); process = NULL;
  
  return NULL;
}

/// @fn int killProcessTree(uint32_t processId)
///
/// @brief Recursively kill a process and all it's child processes.
///
/// @note This is a *LINUX* implementation, not a *POSIX* implementation.
/// Interacting with the process tree is OS-specific.  There is no POSIX
/// standard way to do this.  I'll need to add in support for other systems
/// in the future.
/// JBC 2024-07-07
///
/// @param processId The 32-bit ID of the process to foribly kill.
///
/// @return Returns the exit status of the process.
int killProcessTree(uint32_t processId) {
  char path[256];
  sprintf(path, "/proc/%u/task", processId);
  
  // Collect infomration about all the children.
  Bytes childrenBytes = NULL;
  char **directories = getDirectoryDirectories(path);
  if (directories != NULL) {
    for (uint32_t ii = 0; directories[ii] != NULL; ii++) {
      sprintf(path, "/proc/%u/task/%s/children", processId, directories[ii]);
      Bytes fileContent = NULL;
      i64 length = 4096;
      for (;
        (bytesLength(fileContent) == 0) && (length > 0);
        length >>= 1
      ) {
        fileContent = bytesDestroy(fileContent);
        fileContent = getFileContent(path, 0, length);
      }
      for (;
        bytesLength(fileContent) != 0;
        length++
      ) {
        fileContent = bytesDestroy(fileContent);
        fileContent = getFileContent(path, 0, length);
      }
      fileContent = bytesDestroy(fileContent);
      for (;
        (bytesLength(fileContent) == 0) && (length > 0);
        length--
      ) {
        fileContent = bytesDestroy(fileContent);
        fileContent = getFileContent(path, 0, length);
      }
      bytesAddBytes(&childrenBytes, fileContent);
      bytesAddStr(&childrenBytes, " ");
      fileContent = bytesDestroy(fileContent);
    }
    directories = destroyDirectoryEntries(directories);
  }
  
  // Recursively kill all the children.
  char *nextPid = (childrenBytes == NULL)
    ? (char*) ""
    : (char*) &childrenBytes[strcspn(str(childrenBytes), "0123456789")];
  while (*nextPid != '\0') {
    uint32_t childPid = (uint32_t) strtol(nextPid, &nextPid, 10);
    killProcessTree(childPid);
    nextPid = &nextPid[strcspn(nextPid, "0123456789")];
  }
  childrenBytes = bytesDestroy(childrenBytes);
  
  // Finally, kill the root process.  Forcibly kill it.
  int processStatus;
  kill(processId, SIGKILL);
  // Collect the zombie.
  waitpid(processId, &processStatus, 0);
  
  return processStatus;
}

/// @fn int stopProcess(Process *process)
///
/// @brief Halt a process's execution.
///
/// @param process A pointer to a Process instance.
///
/// @return This function always succeeds and always returns 0.
int stopProcess(Process *process) {
  process->processStatus = killProcessTree(process->processId);
  process->killed = true;
  
  return 0;
}

#endif // _MSC_VER

