///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              11.22.2024
///
/// @file              CThreadsMessages.h
///
/// @brief             Inter-thread message functionality for C threads.
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

#ifndef CTHREAD_MESSAGES_H
#define CTHREAD_MESSAGES_H

#include <stdint.h>
#include <stdbool.h>
#include "CThreads.h"
#include "Messages.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Message queue functions
msg_t* thrd_msg_q_peek(void);
msg_t* thrd_msg_q_pop(void);
msg_t* thrd_msg_q_pop_type(int type);
msg_t* thrd_msg_q_wait(const struct timespec *ts);
msg_t* thrd_msg_q_wait_for_type(int type, const struct timespec *ts);
int thrd_msg_q_push(thrd_t thr, msg_t *msg);

#ifdef __cplusplus
}
#endif

#endif // CTHREAD_MESSAGES_H

