////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                     Copyright (c) 2012-2024 James Card                     //
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

#ifdef _WIN32
#include "WinProcesses.h"
#include "StringLib.h"

#include "WinProcesses.h"
#include <dwmapi.h>

#ifdef _MSC_VER
#pragma comment(lib, "dwmapi.lib")
#endif // _MSC_VER

/// @fn int getWindows(Process *process)
///
/// @brief Find all windows associated with a process.
/// 
/// @param process A pointer to the Process to get windows of.
/// 
/// @return Returns zero on success, -1 on failure.
int getWindows(Process *process) {
  DWORD processId = (DWORD) getProcessId(process);
  int returnValue = 0;
  size_t numWindows = 0;
  HWND* windows = (HWND*)malloc(sizeof(HWND));
  if (windows == NULL) {
    // Memory allocation failure.  Nothing we can do.
    returnValue = -1;
    return returnValue; // -1
  }
  windows[numWindows] = NULL;

  for (HWND currentWindow = FindWindowEx(NULL, NULL, NULL, NULL);
    currentWindow != NULL;
    currentWindow = FindWindowEx(NULL, currentWindow, NULL, NULL)
  ) {
    if (currentWindow != NULL) {
      DWORD currentProcessId = 0;
      GetWindowThreadProcessId(currentWindow, &currentProcessId);
      if (currentProcessId == processId) {
        numWindows++;
        HWND* check = (HWND*)realloc(windows, (numWindows + 1) * sizeof(HWND));
        if (check == NULL) {
          // Memory allocation failure.  Nothing we can do.
          free(windows); windows = NULL;
          returnValue = -1;
          return returnValue; // -1
        }
        windows = check;

        windows[numWindows - 1] = currentWindow;
        windows[numWindows] = NULL;
      }
    }
  }

  free(process->windows);
  process->windows = windows;
  process->numWindows = numWindows;

  return returnValue;
}

/// @fn int captureWindowImage(HWND hWnd)
///
/// @brief Capture the image of a window.
/// 
/// @note This function is a placeholder.  It currently writes the resulting
/// image to a hard-coded path.  This is (obviously) not what we want to do.
/// Update this in the future to produce something more useful.
/// 
/// @param hWnd An HWND pointer.
/// 
/// @return Returns 0 on success, -1 on failure.
int captureWindowImage(HWND hWnd)
{
  HDC hdcWindow;
  HDC hdcMemDC = NULL;
  HBITMAP hbmWindow = NULL;
  BITMAP bmpWindow;
  DWORD dwBytesWritten = 0;
  DWORD dwSizeofDIB = 0;
  HANDLE hFile = NULL;
  char* lpbitmap = NULL;
  HANDLE hDIB = NULL;
  DWORD dwBmpSize = 0;

  hdcWindow = GetDC(hWnd);

  // Create a compatible DC, which is used in a BitBlt from the window DC.
  hdcMemDC = CreateCompatibleDC(hdcWindow);
  if (hdcMemDC == NULL) {
    MessageBoxA(hWnd, "CreateCompatibleDC has failed", "Failed", MB_OK);
    goto hdcMemDCAllocFailed;
  }

  // Get the client area for size calculation.
  RECT rcClient;
  GetClientRect(hWnd, &rcClient);
  
  // Get the frame without the extended shadow
  RECT rcFrame;
  DwmGetWindowAttribute(hWnd, DWMWA_EXTENDED_FRAME_BOUNDS,
    &rcFrame, sizeof(rcFrame));
  // The frame includes the one-pixel border on the left and right of the
  // window.  So, we need to add one to the left and subtract one from the
  // right.
  rcFrame.left += 1;
  rcFrame.right -= 1;

  // Create a compatible bitmap from the Window DC.
  hbmWindow = CreateCompatibleBitmap(hdcWindow, rcFrame.right - rcFrame.left, rcClient.bottom - rcClient.top);
  if (hbmWindow == NULL) {
    MessageBoxA(hWnd, "CreateCompatibleBitmap Failed", "Failed", MB_OK);
    goto hbmWindowAllocFailed;
  }

  // Select the compatible bitmap into the compatible memory DC.
  SelectObject(hdcMemDC, hbmWindow);

  // Bit block transfer into our compatible memory DC.
  if (!BitBlt(hdcMemDC,
    0, 0,
    rcFrame.right - rcFrame.left, rcClient.bottom - rcClient.top,
    hdcWindow,
    0, 0,
    SRCCOPY))
  {
    MessageBoxA(hWnd, "BitBlt has failed", "Failed", MB_OK);
    goto done;
  }

  // Get the BITMAP from the HBITMAP.
  GetObject(hbmWindow, sizeof(BITMAP), &bmpWindow);

  BITMAPFILEHEADER   bmfHeader;
  BITMAPINFOHEADER   bi;

  bi.biSize = sizeof(BITMAPINFOHEADER);
  bi.biWidth = bmpWindow.bmWidth;
  bi.biHeight = bmpWindow.bmHeight;
  bi.biPlanes = 1;
  bi.biBitCount = 32;
  bi.biCompression = BI_RGB;
  bi.biSizeImage = 0;
  bi.biXPelsPerMeter = 0;
  bi.biYPelsPerMeter = 0;
  bi.biClrUsed = 0;
  bi.biClrImportant = 0;

  dwBmpSize = ((bmpWindow.bmWidth * bi.biBitCount + 31) / 32) * 4 * bmpWindow.bmHeight;

  // Starting with 32-bit Windows, GlobalAlloc and LocalAlloc are implemented as wrapper functions that 
  // call HeapAlloc using a handle to the process's default heap. Therefore, GlobalAlloc and LocalAlloc 
  // have greater overhead than HeapAlloc.
  hDIB = GlobalAlloc(GHND, dwBmpSize);
  if (hDIB == NULL) {
    MessageBoxA(hWnd, "GlobalAlloc(GHND, dwBmpSize) Failed", "Failed", MB_OK);
    goto done;
  }
  lpbitmap = (char*) GlobalLock(hDIB);

  // Gets the "bits" from the bitmap, and copies them into a buffer 
  // that's pointed to by lpbitmap.
  GetDIBits(hdcWindow, hbmWindow, 0,
    (UINT)bmpWindow.bmHeight,
    lpbitmap,
    (BITMAPINFO*)&bi, DIB_RGB_COLORS);

  // A file is created, this is where we will save the screen capture.
  hFile = CreateFileA("/Users/jbcar/Pictures/WindowCapture.bmp",
    GENERIC_WRITE,
    0,
    NULL,
    CREATE_ALWAYS,
    FILE_ATTRIBUTE_NORMAL, NULL);

  // Add the size of the headers to the size of the bitmap to get the total file size.
  dwSizeofDIB = dwBmpSize + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

  // Offset to where the actual bitmap bits start.
  bmfHeader.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER) + (DWORD)sizeof(BITMAPINFOHEADER);

  // Size of the file.
  bmfHeader.bfSize = dwSizeofDIB;

  // bfType must always be BM for Bitmaps.
  bmfHeader.bfType = 0x4D42; // BM.

  WriteFile(hFile, (LPSTR)&bmfHeader, sizeof(BITMAPFILEHEADER), &dwBytesWritten, NULL);
  WriteFile(hFile, (LPSTR)&bi, sizeof(BITMAPINFOHEADER), &dwBytesWritten, NULL);
  WriteFile(hFile, (LPSTR)lpbitmap, dwBmpSize, &dwBytesWritten, NULL);

  // Unlock and Free the DIB from the heap.
  GlobalUnlock(hDIB);
  GlobalFree(hDIB);

  // Close the handle for the file that was created.
  CloseHandle(hFile);

  // Clean up.
done:
  DeleteObject(hbmWindow);
hbmWindowAllocFailed:
  DeleteObject(hdcMemDC);
hdcMemDCAllocFailed:
  ReleaseDC(hWnd, hdcWindow);

  return 0;
}

/// @fn char* winProcessesGetErrorMessage(DWORD errorCode)
///
/// @brief Get a char*-style error message string given an input errror code.
///
/// @param errorCode An error code returned by a call to GetLastError.
///
/// @return Returns a char*-style string on success.  NULL on failure.
char* winProcessesGetErrorMessage(DWORD errorCode) {
  LPTSTR lpMsgBuf = NULL;
  FormatMessageA(
    FORMAT_MESSAGE_ALLOCATE_BUFFER |
    FORMAT_MESSAGE_FROM_SYSTEM |
    FORMAT_MESSAGE_IGNORE_INSERTS,      // Flags
    NULL,                               // Source - not relevant in this call
    errorCode,                          // Message ID
    0,                                  // Language ID
    (LPTSTR) &lpMsgBuf,                 // Pointer to output message buffer
    0,                                  // Size of message buffer
    NULL);                              // va_list* of arguments (none here)

  char *returnValue = NULL;
  straddstr(&returnValue, lpMsgBuf);
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
  
  // Create the process.
  successful = CreateProcessA(
    NULL,                    // application name (not used by this library)
    (char*) commandLineArgs, // command line
    NULL,                    // process security attributes; NULL means the started process cannot inherit the handle created for it
    NULL,                    // primary thread security attributes; NULL means the started thread cannot inherit the handle created for it
    TRUE,                    // handles ARE inherited; it's critical that this be TRUE for this to work correctly
    0,                       // creation flags; child inherits error mode and console of the parent, enviroment block is ANSI, DOS apps run in a shared VDM
    environmentVariables,    // environment variables for the process
    workingDirectory,        // working directory for the process
    &startupInfo,            // STARTUPINFO pointer
    &processInformation);    // receives PROCESS_INFORMATION
  
  ZeroMemory(&process->criticalSection, sizeof(CRITICAL_SECTION));
  InitializeCriticalSection(&process->criticalSection);

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
  getWindows(process);
  
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
    straddstr(&returnValue, process->errorMessage);
    free(process->errorMessage); process->errorMessage = NULL;
    *outputLength = strlen(returnValue);
    LeaveCriticalSection(&process->criticalSection);
    return returnValue;
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
    if (writeSuccessful == TRUE) {
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
  free(process->windows); process->windows = NULL;
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

#include <tlhelp32.h>
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

