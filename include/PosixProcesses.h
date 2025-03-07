///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              12.20.2020
///
/// @file              PosixProcesses.h
///
/// @brief             These are the support functions that enable POSIX systems
///                    to spawn and interact with child processes via an OS-
///                    agnostic API.
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

#ifndef POSIX_PROCESSES_H
#define POSIX_PROCESSES_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>


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
/// @param killed is set to true when the process is forcibly killed,
///   false otherwise.
typedef struct Process {
  uint32_t processId;
  FILE *stdOut;
  FILE *stdIn;
  int processStatus;
  bool killed;
} Process;


Process* startProcess_(const char *commandLineArgs, const char *workingDirectory, char *environmentVariables[], ...);
#define startProcess(commandLineArgs, ...) startProcess_(commandLineArgs, ##__VA_ARGS__, NULL, NULL)
bool processHasExited(Process *process);
int processExitStatus(Process *process);
char* readProcessStdout_(Process *process, uint64_t *outputLength, ...);
#define readProcessStdout(process, ...) readProcessStdout_(process, ##__VA_ARGS__, 0)
bool writeProcessStdin_(Process *process, const char *data, uint64_t dataLength, ...);
#define writeProcessStdin(process, data, ...) writeProcessStdin_(process, data, ##__VA_ARGS__, NULL)
Process* closeProcess(Process *process);
#define getProcessId(process) ((process != NULL) ? process->processId : 0)
int stopProcess(Process *process);


#ifdef __cplusplus
}
#endif

#endif // POSIX_PROCESSES_H

