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

#ifdef _MSC_VER
#include "WinProcesses.h"


/// @fn char* winProcessesStringToTchar(char *input)
///
/// @brief Convert a char*-style string to a MS tchar-style character array.
///
/// @param input The char*-style string to convert.
///
/// @return On success, returns a C string that can be used as a
/// tchar-style parameter to functions that expect that format.  Should be
/// free'd later by the caller.  Returns NULL on failure.
char* winProcessesStringToTchar(char *input) {
  char* returnValue = NULL;
  if (input == NULL) {
    // Can't continue.
    return NULL;
  }
  
  int inputLength = strlen(input);
  returnValue = (char*) calloc(1, (inputLength + 1) << 1);
  for (int i = 0; i <= inputLength; i++) {
    returnValue[i << 1] = input[i];
  }
  
  return returnValue;
}

/// @fn char* winProcessesTcharToString(LPSTR tchar)
///
/// @brief Convert a tchar-style character array to a standard char* string.
///
/// @param tchar A pointer to a tchar-formatted character array.
///
/// @return Returns a pointer to a char*-style character array on success,
/// NULL on failure.
char* winProcessesTcharToString(LPSTR tchar) {
  char *returnValue = NULL;
  if (tchar == NULL) {
    // Can't continue.
    return NULL;
  }
  
  char *byteArray = (char*) tchar;
  for (int i = 0; byteArray[i] != '\0'; i += 2) {
    straddchr(&returnValue, byteArray[i]);
  }

  return returnValue;
}

/// @fn char* winProcessesGetErrorMessage(DWORD errorCode)
///
/// @brief Get a char*-style error message string given an input errror code.
///
/// @param errorCode An error code returned by a call to GetLastError.
///
/// @return Returns a char*-style string on success.  NULL on failure.
char* winProcessesGetErrorMessage(DWORD errorCode) {
  LPVOID lpMsgBuf;
  FormatMessage(
    FORMAT_MESSAGE_ALLOCATE_BUFFER |
    FORMAT_MESSAGE_FROM_SYSTEM |
    FORMAT_MESSAGE_IGNORE_INSERTS,      // Flags
    NULL,                               // Source - not relevant in this call
    errorCode,                          // Message ID
    0,                                  // Language ID
    &lpMsgBuf,                          // Pointer to output message buffer
    0,                                  // Size of message buffer
    NULL);                              // va_list* of arguments (none here)

  char *returnValue = winProcessesTcharToString(lpMsgBuf);
  LocalFree(lpMsgBuf);

  return returnValue;
}

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
/// @param ... All furhter parameters are ignored.
///
/// @return Returnss a pointer to a Process instance on success,
/// NULL on failure.
Process* startProcess_(const char *commandLineArgs, const char *workingDirectory, char *environmentVariables[], ...) {
  // Example of how to do this taken from:
  // https://docs.microsoft.com/en-us/windows/win32/procthread/creating-a-child-process-with-redirected-input-and-output
  
  Process *process = calloc(1, sizeof(Process));
  if (process == NULL) {
    // Malloc failure.  We're toast.
    return NULL;
  }

  HANDLE stdOutWr;
  HANDLE stdInRd;
  
  SECURITY_ATTRIBUTES securityAttributes;
  
  // Set the bInheritHandle flag so pipe handles are inherited.
  securityAttributes.nLength = sizeof(SECURITY_ATTRIBUTES);
  securityAttributes.bInheritHandle = TRUE;
  securityAttributes.lpSecurityDescriptor = NULL;
  
  // Create a pipe for the child process's stdout
  if (!CreatePipe(&process->stdOutRd, &stdOutWr, &securityAttributes, 0)) {
    fprintf(stderr, "Could not create a pipe for process's stdout.\n");
    char *errorMessage = winProcessesGetErrorMessage(GetLastError());
    fprintf(stderr, "%s\n", errorMessage);
    free(errorMessage); errorMessage = NULL;
    free(process); process = NULL;
    return NULL;
  }
  
  // Ensure the read handle to the pipe for stdout is not inherited.
  if (!SetHandleInformation(process->stdOutRd, HANDLE_FLAG_INHERIT, 0)) {
    fprintf(stderr, "Could not set handle information for stdOutRd.\n");
    char *errorMessage = winProcessesGetErrorMessage(GetLastError());
    fprintf(stderr, "%s\n", errorMessage);
    free(errorMessage); errorMessage = NULL;
    CloseHandle(stdOutWr);
    CloseHandle(process->stdOutRd);
    CloseHandle(process->stdInWr);
    free(process); process = NULL;
    return NULL;
  }

  // Create a pipe for the child process's stdin
  if (!CreatePipe(&stdInRd, &process->stdInWr, &securityAttributes, 0)) {
    fprintf(stderr, "Could not create a pipe for process's stdin.\n");
    char *errorMessage = winProcessesGetErrorMessage(GetLastError());
    fprintf(stderr, "%s\n", errorMessage);
    free(errorMessage); errorMessage = NULL;
    CloseHandle(stdOutWr);
    CloseHandle(process->stdOutRd);
    free(process); process = NULL;
    return NULL;
  }
  
  // Ensure the write handle to the pipe for stdin is not inherited.
  if (!SetHandleInformation(process->stdInWr, HANDLE_FLAG_INHERIT, 0)) {
    fprintf(stderr, "Could not set handle information for stdInWr.\n");
    char *errorMessage = winProcessesGetErrorMessage(GetLastError());
    fprintf(stderr, "%s\n", errorMessage);
    free(errorMessage); errorMessage = NULL;
    CloseHandle(stdOutWr);
    CloseHandle(stdInRd);
    CloseHandle(process->stdOutRd);
    CloseHandle(process->stdInWr);
    free(process); process = NULL;
    return NULL;
  }
  
  PROCESS_INFORMATION processInformation;
  STARTUPINFO startupInfo;
  BOOL successful = FALSE;
  
  // Set up members of the PROCESS_INFORMATION structure.
  ZeroMemory(&processInformation, sizeof(PROCESS_INFORMATION));
  
  // Set up members of the STARTUPINFO structure.
  // This structure specifies the STDIN and STDOUT handles for redirection.
  
  ZeroMemory(&startupInfo, sizeof(STARTUPINFO));
  startupInfo.cb = sizeof(STARTUPINFO);
  startupInfo.hStdError = stdOutWr;
  startupInfo.hStdOutput = stdOutWr;
  startupInfo.hStdInput = stdInRd;
  startupInfo.dwFlags |= STARTF_USESTDHANDLES;
  
  char *commandLineTchar = winProcessesStringToTchar(commandLineArgs);
  char *workingDirectoryTchar = winProcessesStringToTchar(workingDirectory);
  
  // Create the process.
  successful = CreateProcess(
    NULL,                  // application name (not used by this library)
    commandLineTchar,      // command line
    NULL,                  // process security attributes; NULL means the started process cannot inherit the handle created for it
    NULL,                  // primary thread security attributes; NULL means the started thread cannot inherit the handle created for it
    TRUE,                  // handles ARE inherited; it's critical that this be TRUE for this to work correctly
    0,                     // creation flags; child inherits error mode and console of the parent, enviroment block is ANSI, DOS apps run in a shared VDM
    environmentVariables,  // environment variables for the process
    workingDirectoryTchar, // working directory for the process
    &startupInfo,          // STARTUPINFO pointer
    &processInformation);  // receives PROCESS_INFORMATION
  
  free(commandLineTchar); commandLineTchar = NULL;
  free(workingDirectoryTchar); workingDirectoryTchar = NULL;

  if (successful == FALSE) {
    fprintf(stderr, "Could not create process.\n");
    process->errorMessage = winProcessesGetErrorMessage(GetLastError());
    process->killed = true;
    fprintf(stderr, "%s\n", process->errorMessage);
    CloseHandle(process->stdOutRd);
    CloseHandle(stdOutWr);
    CloseHandle(stdInRd);
    CloseHandle(process->stdInWr);
    return process;
  }
  
  process->processHandle = processInformation.hProcess;
  process->threadHandle = processInformation.hThread;
  
  // Close handles to the stdin and stdout pipes no longer needed by the
  // process.  If they are not explicitly closed, there is no way to recognize
  // that the process has ended.
  
  CloseHandle(stdOutWr);
  CloseHandle(stdInRd);
  
  ZeroMemory(&process->criticalSection, sizeof(CRITICAL_SECTION));
  InitializeCriticalSection(&process->criticalSection);

  return process;
}

/// @fn bool processHasExited(Process *process)
///
/// @brief Determine whether or not a process has exited.
///
/// @param process A pointer to a Process instance.
///
/// @return Returns true if the process has exited, false if not.
bool processHasExited(Process *process) {
  if (process != NULL) {
    EnterCriticalSection(&process->criticalSection);
  }

  if ((process == NULL) || (process->killed == true)) {
    if (process != NULL) {
      LeaveCriticalSection(&process->criticalSection);
    }
    return true;
  }
  DWORD exitCode = 0;

  if (!GetExitCodeProcess(process->processHandle, &exitCode)) {
    // Call failed.  Assume process is dead.
    LeaveCriticalSection(&process->criticalSection);
    return true;
  }
  
  LeaveCriticalSection(&process->criticalSection);
  return (exitCode != STILL_ACTIVE);
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
  if (process != NULL) {
    EnterCriticalSection(&process->criticalSection);
  }

  if ((process == NULL) || (process->killed == true)) {
    if (process != NULL) {
      LeaveCriticalSection(&process->criticalSection);
    }
    return -1;
  }
  DWORD exitCode = 0;

  if (!GetExitCodeProcess(process->processHandle, &exitCode)) {
    // Call failed.  Assume process is dead.
    LeaveCriticalSection(&process->criticalSection);
    return -1;
  }
  
  LeaveCriticalSection(&process->criticalSection);
  return exitCode;
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
/// @return Returns a C string with the contents of the process's stdout
/// on success, NULL on failure.
char* readProcessStdout_(Process *process, uint64_t *outputLength, ...) {
  char *returnValue = NULL;
  size_t returnValueLength = 0;

  if (process != NULL) {
    EnterCriticalSection(&process->criticalSection);
  }

  if ((process != NULL) && (process->errorMessage != NULL)) {
    bytesAddData(&returnValue,
      process->errorMessage, strlen(process->errorMessage));
    free(process->errorMessage); process->errorMessage = NULL;
  } else if ((process == NULL) || (process->killed == true)) {
    if (process != NULL) {
      LeaveCriticalSection(&process->criticalSection);
    }
    return NULL;
  }
  // Read from process->stdOutRd
  BOOL readSuccessful = FALSE;
  DWORD numBytesRead = 0;
  DWORD numBytesAvailable = 0;
  DWORD numBytesLeft = 0;
  CHAR data[4096] = { 0 };
  
  do {
    readSuccessful
      = PeekNamedPipe(process->stdOutRd, data, 4096, &numBytesRead,
        &numBytesAvailable, &numBytesLeft);
    if ((readSuccessful) && (numBytesRead > 0)) {
      readSuccessful
        = ReadFile(process->stdOutRd, data, 4096, &numBytesRead, NULL);
    }
    if ((readSuccessful) && (numBytesRead > 0)) {
      void* check
        = realloc(returnValue, returnValueLength + (size_t) numBytesRead + 1);
      if (check == NULL) {
        // Memory allocation failure.  Return what we have.
        LeaveCriticalSection(&process->criticalSection);
        return returnValue;
      }
      returnValue = (char*) check;
      memcpy(&returnValue[returnValueLength], data, numBytesRead);
      returnValueLength += (size_t)numBytesRead;
      returnValue[returnValueLength] = '\0';
    }
  } while ((readSuccessful) && (numBytesRead > 0));
  
  if (outputLength != NULL) {
    *outputLength = (uint64_t) returnValueLength;
  }
  LeaveCriticalSection(&process->criticalSection);
  return returnValue;
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
bool writeProcessStdin_(Process *process, const char *data, uint64_t dataLength, ...) {
  if (process != NULL) {
    EnterCriticalSection(&process->criticalSection);
  }

  if ((process == NULL) || (process->killed == true) || (data == NULL)) {
    if (process != NULL) {
      LeaveCriticalSection(&process->criticalSection);
    }
    return false;
  }
  
  if (dataLength == 0) {
    // data is non-NULL because of the check above.
    dataLength = (uint64_t) strlen(data);
  }
  
  // Write to process->stdInWr
  BOOL writeSuccessful = FALSE;
  DWORD numBytesWritten = 0;
  uint32_t totalBytesWritten = 0;
  
  do {
    writeSuccessful = WriteFile(process->stdInWr, &data[totalBytesWritten],
      dataLength - totalBytesWritten, &numBytesWritten, NULL);
    if (numBytesWritten >= 0) {
      totalBytesWritten += numBytesWritten;
    }
  } while ((writeSuccessful) && (totalBytesWritten < dataLength));
  
  LeaveCriticalSection(&process->criticalSection);
  return (totalBytesWritten == dataLength);
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
  if (process == NULL) {
    return NULL;
  }

  if (process->killed == false) {
    CloseHandle(process->processHandle);
    CloseHandle(process->threadHandle);
    CloseHandle(process->stdOutRd);
    CloseHandle(process->stdInWr);
  }

  free(process->errorMessage); process->errorMessage = NULL;
  free(process); process = NULL;
  return NULL;
}

/// @fn uint32_t getProcessId(Process *process)
///
/// @brief Return the process ID (PID) of the specified process.
///
/// @param process A pointer to a Process instance.
///
/// @return Returns the ID of the process cast to a u32.
uint32_t getProcessId(Process *process) {
  if (process != NULL) {
    EnterCriticalSection(&process->criticalSection);
  }

  if ((process == NULL) || (process->killed == true)) {
    if (process != NULL) {
      LeaveCriticalSection(&process->criticalSection);
    }
    return 0;
  }

  uint32_t processId = (uint32_t) GetProcessId(process->processHandle);
  /*
  if (processId == 0) {
    DWORD windowPid = 0;
    GetWindowThreadProcessId(process->processHandle, &windowPid);
    processId = (uint32_t) windowPid;
  }
  */

  LeaveCriticalSection(&process->criticalSection);
  return processId;
}

#include <TlHelp32.h>
/// @fn void winProcessesKillProcessTree(DWORD myprocID)
///
/// @brief Kill a process and all its subprocesses.
///
/// @note This code was taken from the suggestion of user2346536 at
/// https://stackoverflow.com/questions/1173342/terminate-a-process-tree-c-for-windows
/// It's licensed under Creative Commons Attribution-ShareAlike license
/// (https://creativecommons.org/licenses/by-sa/4.0/)
/// The format was changed to be consistent with the format of this library but
/// is otherwise the same as the original suggestion.
///
/// @param myprocID The numeric process ID of the process to kill.
///
/// @return This function returns no value.
void winProcessesKillProcessTree(DWORD myprocID) {
  PROCESSENTRY32 pe;
  
  memset(&pe, 0, sizeof(PROCESSENTRY32));
  pe.dwSize = sizeof(PROCESSENTRY32);
  
  HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  
  if (Process32First(hSnap, &pe)) {
    do { // Recursion
      if ((pe.th32ProcessID != myprocID)
        && (pe.th32ParentProcessID == myprocID)
      ) {
        winProcessesKillProcessTree(pe.th32ProcessID);
      }
    } while (Process32Next(hSnap, &pe));
  }
  
  // kill the main process
  HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, myprocID);
  
  if (hProc) {
    TerminateProcess(hProc, 1);
    CloseHandle(hProc);
  }
}

/// @fn int stopProcess(Process *process)
///
/// @brief Halt a process's execution.
///
/// @param process A pointer to a Process instance.
///
/// @return Returns 0 on success, -1 on failure.
int stopProcess(Process *process) {
  if (process != NULL) {
    EnterCriticalSection(&process->criticalSection);
  }

  if ((process == NULL) || (process->killed == true)) {
    if (process != NULL) {
      LeaveCriticalSection(&process->criticalSection);
    }
    return 0;
  }
  
  // We must (recursively) kill all the process's children FIRST and then
  // terminate the process.  If we leave children running, TerminateProcess
  // will block until they all complete, which is *NOT* what we want.  Call
  // winProcessesKillProcessTree here to do this.
  winProcessesKillProcessTree(getProcessId(process));
  process->killed = true;

  CloseHandle(process->processHandle);
  CloseHandle(process->threadHandle);
  CloseHandle(process->stdOutRd);
  CloseHandle(process->stdInWr);
  
  LeaveCriticalSection(&process->criticalSection);
  return 0;
}


#endif // _MSC_VER

