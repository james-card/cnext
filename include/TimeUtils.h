///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// Revised:           07.14.2024
///
/// @file              TimeUtils.h
///
/// @brief             This is the header for the time utilities library.
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

#ifndef TIME_UTILS_H
#define TIME_UTILS_H

// Standard C includes.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// C.next includes.
#include "TypeDefinitions.h"
#include "CThreads.h"

#ifdef __cplusplus
extern "C"
{
#endif

const char *weekdayToString(int weekday);

#ifdef _MSC_VER
#ifndef timezone
#define timezone _timezone
#endif // timezone
#endif // _MSC_VER

/// @fn static inline i64 timestampToTime(const char *timestamp)
///
/// @brief Convert a UTC timestamp in the format "YYYY-MM-DD HH:MM:SS" to a
/// time_t value.
///
/// @param timestamp The string containing the timestamp to convert.
///
/// @return Returns the time_t value of the timestamp on success, 0 on failure.
static inline i64 timestampToTime(const char *timestamp) {
  struct tm timestampStruct;
  int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
  i64 returnValue = 0;
  
  if (timestamp != NULL && *timestamp != '\0') {
    if (sscanf(timestamp, "%d-%d-%d %d:%d:%d",
      &year, &month, &day, &hour, &minute, &second) != 6
    ) {
      // This isn't a timestamp.  Bail.
      return returnValue; // 0
    }
    
    timestampStruct.tm_year = year - 1900;
    timestampStruct.tm_mon = month - 1;
    timestampStruct.tm_mday = day;
    timestampStruct.tm_hour = hour;
    timestampStruct.tm_min = minute;
    timestampStruct.tm_sec = second;
    // These next three shouldn't be needed but valgrind will complain if they're
    // not initialized.
    timestampStruct.tm_wday = 0;
    timestampStruct.tm_yday = 0;
    timestampStruct.tm_isdst = -1;
    
    tzset();
    returnValue = (i64) mktime(&timestampStruct);
    returnValue -= (i64) timezone;
    if (timestampStruct.tm_isdst == 1) {
      returnValue += 3600;
    }
  }
  
  return returnValue;
}

/// @fn static inline char* nanosecondsToTimestamp(i64 nanoseconds, char *timestamp)
///
/// @brief Convert a number of nanoseconds since midnight, Jan 1, 1970 to a UTC
/// timestamp in the form YYYY-MM-DD hh:mm:ss.nnnnnnnnn.
///
/// @param nanoseconds The nanoseconds representing the time to convert.
/// @param timestamp Character buffer to hold the output timestamp.  This
///   parameter may be NULL.  A buffer will be allocated if it is not provided.
static inline char* nanosecondsToTimestamp(i64 nanoseconds, char *timestamp) {
  #define timestampSize 30
  struct timespec timeValue = {
    /* time_t */ .tv_sec  = (time_t) (nanoseconds / 1000000000),
    /* long   */ .tv_nsec = (long)   (nanoseconds % 1000000000)
  };
  ZEROINIT(struct tm timestampStruct);
  gmtime_r(&timeValue.tv_sec, &timestampStruct);
  
  if (timestamp == NULL) {
    // No buffer provided, so allocate one.
    timestamp = (char*) malloc(timestampSize);
  }
  
  snprintf(timestamp, timestampSize, "%4d-%02d-%02d %02d:%02d:%02d.%09ld",
    timestampStruct.tm_year + 1900,
    timestampStruct.tm_mon + 1,
    timestampStruct.tm_mday,
    timestampStruct.tm_hour,
    timestampStruct.tm_min,
    timestampStruct.tm_sec,
    (long) timeValue.tv_nsec);
  
  #undef timestampSize
  return timestamp;
}

/// @fn static inline i64 timestampToNanoseconds(const char *timestamp)
///
/// @brief Convert a timestamp in the format YYYY-MM-DD hh:mm:ss.nnnnnnnnn to
/// its nanosecond representation.  The timestamp is assumed to be in UTC time
/// (since that's what everything in this library uses.
///
/// @param timestamp The timestamp to convert.
///
/// @return Returns the number of nanoseconds since midnight, Jan 1, 1970 UTC
/// on success, 0 on failure.
static inline i64 timestampToNanoseconds(const char *timestamp) {
  struct tm timestampStruct;
  int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
  long int nanoseconds = 0;
  i64 returnValue = 0;
  
  if (timestamp != NULL && *timestamp != '\0') {
    if (sscanf(timestamp, "%d-%d-%d %d:%d:%d.%ld",
      &year, &month, &day, &hour, &minute, &second, &nanoseconds) < 6
    ) {
      // This isn't a timestamp.  Bail.
      return returnValue; // 0
    }
    
    timestampStruct.tm_year = year - 1900;
    timestampStruct.tm_mon = month - 1;
    timestampStruct.tm_mday = day;
    timestampStruct.tm_hour = hour;
    timestampStruct.tm_min = minute;
    timestampStruct.tm_sec = second;
    // These next three shouldn't be needed but valgrind will complain if they're
    // not initialized.
    timestampStruct.tm_wday = 0;
    timestampStruct.tm_yday = 0;
    timestampStruct.tm_isdst = -1;
    
    tzset();
    returnValue = (i64) mktime(&timestampStruct);
    returnValue -= (i64) timezone;
    if (timestampStruct.tm_isdst == 1) {
      returnValue += 3600;
    }
    returnValue *= 1000000000;
    returnValue += (i64) nanoseconds;
  }
  
  return returnValue;
}

/// @fn static inline time_t isDst(time_t timeValue)
///
/// @brief Determine whether or not a UNIX time value represents a time that
/// for which DST is in efffect.
///
/// @param timeValue The number of seconds since Jan 1, 1970, UTC that
///   represents the time.
///
/// @return Returns 1 if the time represents a time during which DST is in
/// effect, 0 if not or if the answer could not be determined.
static inline time_t isDst(time_t timeValue) {
  ZEROINIT(struct tm timeValueStruct);
  gmtime_r(&timeValue, &timeValueStruct);
  timeValueStruct.tm_isdst = -1;
  tzset();
  mktime(&timeValueStruct);
  return (time_t) (timeValueStruct.tm_isdst == 1);
}

/// @fn static inline i64 getNowNanoseconds()
///
/// @brief Get the current time as the number of nanoseconds since midnight,
/// Jan 1, 1970.
///
/// @return Returns the number of nanoseconds since midnight, Jan 1, 1970.
static inline i64 getNowNanoseconds() {
  struct timespec now;
  timespec_get(&now, TIME_UTC);
  return (((i64) now.tv_sec) * ((i64) 1000000000)) + (i64) now.tv_nsec;
}

#define MINUTE_NANOSECONDS 60000000000LL
#define HOUR_NANOSECONDS (60LL * MINUTE_NANOSECONDS)
#define DAY_NANOSECONDS (24LL * HOUR_NANOSECONDS)
#define WEEK_NANOSECONDS (7LL * DAY_NANOSECONDS)
#define YEAR_NANOSECONDS (365LL * DAY_NANOSECONDS)
#define LEAP_YEAR_NANOSECONDS (366LL * DAY_NANOSECONDS)
  
#ifdef __cplusplus
} // extern "C"
#endif

#endif // TIME_UTILS_H

