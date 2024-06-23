///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              12.21.2020
///
/// @file              WinProcesses.h
///
/// @brief             These are the support functions that allow Visual Studio
///                    to spawn and interact with child processes via an OS-
///                    agnostic API.
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

#ifndef WIN_PROCESSES_H
#define WIN_PROCESSES_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <process.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include <strsafe.h>
#include <string.h>


#ifdef __cplusplus
extern "C"
{
#endif

/// @struct Process
/// @brief Type to handle the OS-specific details of managing and interacting
///   with child processes.
/// @param processId is the numerical ID of the process
/// @param stdOut is the FILE object used to read data from the program
/// @param stdIn is the FILE object used to write data to the program
/// @param killed is a boolean to keep track of whether or not the process
///   has been forcibly killed
/// @param errorMessage is a string containing an error message if the
///   process failed to start
/// @param criticalSection is a Windows CRITICAL_SECTION to guard access to
///   the member variables
/// @param numWindows is the number of windows the process has at the current
///   time
/// @param windows is a one-dimensional, NULL-terminated array of Windows HWND
///   window handles representing the windows for the process
typedef struct Process {
  HANDLE stdOutRd;
  HANDLE stdInWr;
  HANDLE processHandle;
  HANDLE threadHandle;
  bool killed;
  char *errorMessage;
  CRITICAL_SECTION criticalSection;
  size_t numWindows;
  HWND *windows;
} Process;


Process* startProcess_(const char* commandLineArgs, const char* workingDirectory, char* environmentVariables[], ...);
#define startProcess(commandLineArgs, ...) startProcess_(commandLineArgs, ##__VA_ARGS__, NULL, NULL)
bool processHasExited(Process *process);
int processExitStatus(Process *process);
char* readProcessStdout_(Process *process, uint64_t *outputLength, ...);
#define readProcessStdout(process, ...) readProcessStdout_(process, ##__VA_ARGS__, NULL)
bool writeProcessStdin_(Process *process, const char *data, uint64_t dataLength, ...);
#define writeProcessStdin(process, data, ...) writeProcessStdin_(process, data, ##__VA_ARGS__, 0)
Process* closeProcess(Process *process);
uint32_t getProcessId(Process *process);
int stopProcess(Process *process);


#ifdef __cplusplus
} // extern "C"
#endif

#endif // WIN_PROCESSES_H

