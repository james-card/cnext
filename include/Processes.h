///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              12.20.2020
///
/// @file              Processes.h
///
/// @brief             This is the root header that can be included from
///                    libraries that make use of child processes.  This header
///                    will determine the system and include the correct system-
///                    specific header (PosixProcesses.h, or WinProcesses.h).
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

#ifndef PROCESSES_H
#define PROCESSES_H

// Figure out how to support processes.
#ifdef _WIN32
// Windows system.
#include "WinProcesses.h"
#else
// Non-Visual Studio.  Assume POSIX.
#include "PosixProcesses.h"
#endif // child processes support

#endif // PROCESSES_H

