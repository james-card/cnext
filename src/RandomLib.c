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

// Standard C includes.
#include <stdio.h>
#include <stdlib.h>

// C.next includes.
#include "RandomLib.h"
#include "CThreads.h"

#ifdef LOGGING_ENABLED
#include "LoggingLib.h"
#else
#undef printLog
#define printStackTrace(...) {}
#define printLog(...) {}
#define loggingStop() {}
#define LOG_MALLOC_FAILURE() {}
#define logFile stderr
static bool exitNow = false;
#endif

/// @var _internalSeed
///
/// @brief The seed to use if none is specified when calling getU32.
static u64 _internalSeed = 0;

/// @var _randomSetup
///
/// @brief once_flag to make sure we only initialize the random number generator
/// mutex once.
static once_flag _randomSetup = ONCE_FLAG_INIT;

/// @var prngMutex
///
/// @brief Mutex to ensure that random number operations are atomic.
ZEROINIT(static mtx_t prngMutex);

#define RANDOM_MAX 0xffffffffffffULL
#define RANDOM_MULTIPLIER 25214903917ULL
#define RANDOM_INCREMENT 11ULL
#define RANDOM_MODULUS ((u64) ((1ULL << 48) - 1))

/// @fn void setupRandomMetadata(void)
///
/// @brief Initializer for components needed for random number generation.
///
/// @return This function returns no value.
void setupRandomMetadata(void) {
  int status = mtx_init(&prngMutex, mtx_plain | mtx_recursive);
  if (status != thrd_success) {
    fprintf(stderr, "Could not initialize prngMutex.\n");
  }
}

/// @fn u48 getU48_(u64 upperBound, bool useProvidedSeed, u64 seed, ...)
///
/// @brief Gets a random, unsigned-integer value less-than or equal-to the value
/// passed in.
///
/// @param upperBound The ceiling for the call.
/// @param useProvidedSeed Whether or not to use the seed parameter in the
///   generation of the random number.  If false, the last-generated value will
///   be used.
/// @param seed The seed to use in the calculations.
///
/// @note This function is wrapped by a macro of the same name (minus the
/// trailing underscore) that automatcially provides false for useProvidedSeed
/// and 0 for the seed.
///
/// @return Returns a pseudo-random, unsigned, 64-bit integer value with 48
/// bits of significance.
u64 getU48_(u64 upperBound, bool useProvidedSeed, u64 seed, ...) {
  printLog(TRACE,
    "ENTER getU48(upperBound=%llu, useProvidedSeed=%s, seed=%llu)\n",
    llu(upperBound), (useProvidedSeed == true) ? "true" : "false", llu(seed));
  
  call_once(&_randomSetup, setupRandomMetadata);
  
  u64 returnValue = 0;
  
  // Use a linear congruential algorithm to generate a random number.
  if (!useProvidedSeed) {
    // This is the expected case.  Use and update the internal seed.
    mtx_lock(&prngMutex);
    returnValue
      = ((RANDOM_MULTIPLIER * _internalSeed) + RANDOM_INCREMENT)
      & RANDOM_MODULUS;
    _internalSeed = returnValue;
    mtx_unlock(&prngMutex);
  } else {
    // Use the user's provided seed.  This requires no mutex locking.
    returnValue
      = ((RANDOM_MULTIPLIER * seed) + RANDOM_INCREMENT) & RANDOM_MODULUS;
  }
  
  // Bound the random value by the upperBound.
  if (upperBound != 0) {
    if (upperBound < 0x10000) {
      returnValue = (upperBound * returnValue) >> 48;
    } else {
      returnValue %= upperBound;
    }
  }
  
  printLog(TRACE,
    "EXIT getU48(upperBound=%llu, useProvidedSeed=%s, seed=%llu) = {%llu}\n",
    llu(upperBound), (useProvidedSeed == true) ? "true" : "false", llu(seed),
    llu(returnValue));
  return returnValue;
}

/// @fn u32 getU32_(u32 upperBound, bool useProvidedSeed, u64 seed, ...)
///
/// @brief Gets a random, unsigned-integer value less-than or equal-to the value
/// passed in.
///
/// @param upperBound The ceiling for the call.  If 0 is used then the upper
///   bound will be the maximum 32-bit value (0xffffffff).
/// @param useProvidedSeed Whether or not to use the seed parameter in the
///   generation of the random number.  If false, the last-generated value will
///   be used.
/// @param seed The seed to use in the calculations.
///
/// @note This function is wrapped by a macro of the same name (minus the
/// trailing underscore) that automatcially provides false for useProvidedSeed
/// and 0 for the seed.
///
/// @return Returns a pseudo-random, unsigned, 32-bit integer value.
u32 getU32_(u32 upperBound, bool useProvidedSeed, u64 seed, ...) {
  printLog(TRACE,
    "ENTER getU32(upperBound=%u, useProvidedSeed=%s, seed=%llu)\n",
    upperBound, (useProvidedSeed == true) ? "true" : "false", llu(seed));
  
  u64 returnValue = getU48(0, useProvidedSeed, seed) & 0xffffffff;
  if (upperBound > 0) {
    // We should divide (upperBound * returnValue) by (max random number + 1).
    // The maximum random number from this function is 0xffffffff, so dividing
    // by one more than that is equivalent to right bit-shifting by 32.  Bit
    // shifting will save us a few CPU cycles.
    returnValue = (((u64) upperBound) * returnValue) >> 32;
  }
  
  printLog(TRACE,
    "EXIT getU32(upperBound=%u, useProvidedSeed=%s, seed=%llu) = {%u}\n",
    upperBound, (useProvidedSeed == true) ? "true" : "false", llu(seed),
    (u32) returnValue);
  return (u32) returnValue;
}

/// @fn u64 startRandom(u64 seed)
///
/// @brief Starts the random number generator.
///
/// @param seed The seed to use.  A seed of zero will result in the use of a
/// semi-random seed based on the time and process ID.  There is never a need
/// to call this function with a value of 0 because that's what the internal
/// seed is initialized to anyway.
///
/// @return Returns the seed used for starting the random number generator.
u64 startRandom(u64 seed) {
  printLog(TRACE, "ENTER startRandom(seed=%llu)\n", llu(seed));
  
  call_once(&_randomSetup, setupRandomMetadata);
  
  mtx_lock(&prngMutex);
  
  if (seed == 0) {
    // Manufacture a seed.  Start by clearing the seed value.
    _internalSeed = 0;
    struct timespec now;
    u64 pid = (u64) getpid();
    // The gitpid call adds a little non-determinism to the timespec_get call.
    timespec_get(&now, TIME_UTC);
    // Assume that the pid has at least 16 significant bits, but possibly more.
    seed = pid << 32;
    seed ^= (u64) ((i64) now.tv_nsec);
    if ((now.tv_nsec % 100) == 0) {
      // We're only guaranteed hundreds of nanoseconds, so provide something
      // for the lsb 0s.  tv_nsec is a 30-bit number, so grap the top 7 bits.
      seed |= (u64) (((i64) now.tv_nsec) >> 23);
    }
  }
  
  _internalSeed = (u64) seed;
  
  mtx_unlock(&prngMutex);
  
  printLog(TRACE, "EXIT startRandom(seed=%llu) = {%llu}\n",
    llu(seed), llu(seed));
  return (u64) seed;
}

/// @fn char *getRandomString_(u32 length, const char *userAlphabet, ...)
///
/// @brief Get a random string of the specified length.
///
/// @param length The number of charcters the output string should be.
/// @param userAlphabet The alphabet of characters the user wants to use.
///   Defaults to all printable ASCII characters if NULL.
///
/// @return Returns a newly-allocated random string on success, NULL on failure
/// (memory allocation failure).
char *getRandomString_(u32 length, const char *userAlphabet, ...) {
  printLog(TRACE, "ENTER getRandomString(length=%u)\n", length);
  
  const char *alphabet
    = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
      "0123456789!@#$%^&*(),./;'[]\\-=`<>?:\"{}|_+~ \t\n";
  if (userAlphabet != NULL) {
    alphabet = userAlphabet;
  }
  u32 alphabetMax = strlen(alphabet) - 1;
  
  char *randomString = (char*) malloc(length + 1);
  if (randomString == NULL) {
    LOG_MALLOC_FAILURE();
    return randomString;
  }
  randomString[length] = '\0';
  
  for (u32 index = 0; index < length; ++index) {
    randomString[index] = alphabet[getU32(alphabetMax)];
  }
  
  printLog(TRACE, "EXIT getRandomString(length=%u) = {%s}\n",
    length, randomString);
  return randomString;
}


