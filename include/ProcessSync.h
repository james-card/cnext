///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              03.30.2025
///
/// @file              ProcessSync.h
///
/// @brief             This is the root header that can be included from
///                    libraries that make use of inter-process synchronization
///                    primitives.  This file will include the correct OS-
///                    specific header (LinuxProcessSync.h, or 
///                    WinProcessSync.h).
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

#ifndef PROCESS_SYNC_H
#define PROCESS_SYNC_H

// Figure out how to support process synchronization.
#if defined(_WIN32)
#include "WinProcessSync.h"
#elif defined(__linux__)
#include "LinuxProcessSync.h"
#endif // 

#endif // PROCESS_SYNC_H

