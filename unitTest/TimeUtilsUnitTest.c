///////////////////////////////////////////////////////////////////////////////
///
/// @file              timeUtilsUnitTest.c
///
/// @brief             Unit test for the TimeUtils library.
///
/// @details           Tests all functions in TimeUtils.h with valid parameters
///                    and corner cases including NULL parameters.
///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "TimeUtils.h"
#include "LoggingLib.h"

// Test constants
static const char *VALID_TIMESTAMP = "2024-07-14 15:30:45.123456789";
static const char *VALID_TIMESTAMP_NO_NS = "2024-07-14 15:30:45";
static const char *INVALID_TIMESTAMP = "not-a-timestamp";
static const char *PARTIAL_TIMESTAMP = "2024-07-14";
static const char *EMPTY_STRING = "";

///
/// @fn bool testWeekdayToString()
///
/// @brief Test the weekdayToString function with valid and invalid inputs.
///
/// @return Returns true if all tests pass, false otherwise.
///
bool testWeekdayToString() {
  const char *result;
  
  printLog(DEBUG, "Testing weekdayToString function...\n");
  
  // Test valid weekdays (0-6)
  for (int ii = 0; ii <= 6; ii++) {
    result = weekdayToString(ii);
    if (result == NULL) {
      printLog(ERR, "weekdayToString(%d) returned NULL\n", ii);
      return false;
    }
    if (strlen(result) == 0) {
      printLog(ERR, "weekdayToString(%d) returned empty string\n", ii);
      return false;
    }
    printLog(DEBUG, "weekdayToString(%d) = %s\n", ii, result);
  }
  
  // Test invalid weekdays
  int invalidDays[] = {-1, 7, 100, -100};
  for (int ii = 0; ii < 4; ii++) {
    result = weekdayToString(invalidDays[ii]);
    if (result == NULL) {
      printLog(ERR, "weekdayToString(%d) returned NULL for invalid day\n", 
               invalidDays[ii]);
      return false;
    }
    printLog(DEBUG, "weekdayToString(%d) = %s\n", invalidDays[ii], result);
  }
  
  printLog(DEBUG, "weekdayToString tests passed\n");
  return true;
}

///
/// @fn bool testUtcTimestampToTime()
///
/// @brief Test the utcTimestampToTime function with valid and invalid inputs.
///
/// @return Returns true if all tests pass, false otherwise.
///
bool testUtcTimestampToTime() {
  i64 result;
  
  printLog(DEBUG, "Testing utcTimestampToTime function...\n");
  
  // Test valid timestamp
  result = utcTimestampToTime(VALID_TIMESTAMP_NO_NS);
  if (result == 0) {
    printLog(ERR, "utcTimestampToTime failed for valid timestamp: %s\n", 
             VALID_TIMESTAMP_NO_NS);
    return false;
  }
  printLog(DEBUG, "utcTimestampToTime('%s') = %lld\n", 
           VALID_TIMESTAMP_NO_NS, (long long)result);
  
  // Test NULL parameter
  result = utcTimestampToTime(NULL);
  if (result != (i64) 0x8000000000000000) {
    printLog(ERR, "utcTimestampToTime(NULL) should return 0x8000000000000000, got %lld\n", 
             (long long)result);
    return false;
  }
  
  // Test empty string
  result = utcTimestampToTime(EMPTY_STRING);
  if (result != (i64) 0x8000000000000000) {
    printLog(ERR, "utcTimestampToTime('') should return 0x8000000000000000, got %lld\n", 
             (long long)result);
    return false;
  }
  
  // Test invalid timestamp
  result = utcTimestampToTime(INVALID_TIMESTAMP);
  if (result != (i64) 0x8000000000000000) {
    printLog(ERR, "utcTimestampToTime('%s') should return 0x8000000000000000, got %lld\n", 
             INVALID_TIMESTAMP, (long long)result);
    return false;
  }
  
  // Test partial timestamp
  result = utcTimestampToTime(PARTIAL_TIMESTAMP);
  if (result != (i64) 0x8000000000000000) {
    printLog(ERR, "utcTimestampToTime('%s') should return 0x8000000000000000, got %lld\n", 
             PARTIAL_TIMESTAMP, (long long)result);
    return false;
  }
  
  printLog(DEBUG, "utcTimestampToTime tests passed\n");
  return true;
}

///
/// @fn bool testLocalTimestampToTime()
///
/// @brief Test the localTimestampToTime function with valid and invalid inputs.
///
/// @return Returns true if all tests pass, false otherwise.
///
bool testLocalTimestampToTime() {
  i64 result;
  
  printLog(DEBUG, "Testing localTimestampToTime function...\n");
  
  // Test valid timestamp
  result = localTimestampToTime(VALID_TIMESTAMP_NO_NS);
  if (result == 0) {
    printLog(ERR, "localTimestampToTime failed for valid timestamp: %s\n", 
             VALID_TIMESTAMP_NO_NS);
    return false;
  }
  printLog(DEBUG, "localTimestampToTime('%s') = %lld\n", 
           VALID_TIMESTAMP_NO_NS, (long long)result);
  
  // Test NULL parameter
  result = localTimestampToTime(NULL);
  if (result != 0) {
    printLog(ERR, "localTimestampToTime(NULL) should return 0, got %lld\n", 
             (long long)result);
    return false;
  }
  
  // Test empty string
  result = localTimestampToTime(EMPTY_STRING);
  if (result != 0) {
    printLog(ERR, "localTimestampToTime('') should return 0, got %lld\n", 
             (long long)result);
    return false;
  }
  
  // Test invalid timestamp
  result = localTimestampToTime(INVALID_TIMESTAMP);
  if (result != 0) {
    printLog(ERR, "localTimestampToTime('%s') should return 0, got %lld\n", 
             INVALID_TIMESTAMP, (long long)result);
    return false;
  }
  
  printLog(DEBUG, "localTimestampToTime tests passed\n");
  return true;
}

///
/// @fn bool testGetTimezoneNanosecondsFromTimestamp()
///
/// @brief Test the getTimezoneNanosecondsFromTimestamp function.
///
/// @return Returns true if all tests pass, false otherwise.
///
bool testGetTimezoneNanosecondsFromTimestamp() {
  i64 result;
  
  printLog(DEBUG, "Testing getTimezoneNanosecondsFromTimestamp function...\n");
  
  // Test valid timestamp
  result = getTimezoneNanosecondsFromTimestamp(VALID_TIMESTAMP_NO_NS);
  printLog(DEBUG, "getTimezoneNanosecondsFromTimestamp('%s') = %lld\n", 
           VALID_TIMESTAMP_NO_NS, (long long)result);
  
  // Test NULL parameter
  result = getTimezoneNanosecondsFromTimestamp(NULL);
  if (result != (i64) 0x8000000000000000) {
    printLog(ERR, 
             "getTimezoneNanosecondsFromTimestamp(NULL) should return 0x8000000000000000, "
             "got %lld\n", (long long)result);
    return false;
  }
  
  // Test empty string
  result = getTimezoneNanosecondsFromTimestamp(EMPTY_STRING);
  if (result != (i64) 0x8000000000000000) {
    printLog(ERR, 
      "getTimezoneNanosecondsFromTimestamp('') should return 0x8000000000000000, "
      "got %lld\n", (long long)result);
    return false;
  }
  
  // Test invalid timestamp
  result = getTimezoneNanosecondsFromTimestamp(INVALID_TIMESTAMP);
  if (result != (i64) 0x8000000000000000) {
    printLog(ERR, 
      "getTimezoneNanosecondsFromTimestamp('%s') should return 0x8000000000000000, "
      "got %lld\n", INVALID_TIMESTAMP, (long long)result);
    return false;
  }
  
  printLog(DEBUG, "getTimezoneNanosecondsFromTimestamp tests passed\n");
  return true;
}

///
/// @fn bool testNanosecondsToTimestamp()
///
/// @brief Test the nanosecondsToTimestamp function.
///
/// @return Returns true if all tests pass, false otherwise.
///
bool testNanosecondsToTimestamp() {
  char *result;
  char buffer[50];
  i64 testNanoseconds = 1721826645123456789LL; // Corresponds to a valid time
  
  printLog(DEBUG, "Testing nanosecondsToTimestamp function...\n");
  
  // Test with NULL buffer (function should allocate)
  result = nanosecondsToTimestamp(testNanoseconds, NULL);
  if (result == NULL) {
    printLog(ERR, "nanosecondsToTimestamp returned NULL with NULL buffer\n");
    return false;
  }
  if (strlen(result) == 0) {
    printLog(ERR, "nanosecondsToTimestamp returned empty string\n");
    free(result);
    return false;
  }
  printLog(DEBUG, "nanosecondsToTimestamp(%lld, NULL) = %s\n", 
           (long long)testNanoseconds, result);
  free(result);
  
  // Test with provided buffer
  result = nanosecondsToTimestamp(testNanoseconds, buffer);
  if (result != buffer) {
    printLog(ERR, "nanosecondsToTimestamp should return provided buffer\n");
    return false;
  }
  if (strlen(result) == 0) {
    printLog(ERR, "nanosecondsToTimestamp returned empty string in buffer\n");
    return false;
  }
  printLog(DEBUG, "nanosecondsToTimestamp(%lld, buffer) = %s\n", 
           (long long)testNanoseconds, result);
  
  // Test with zero nanoseconds (epoch)
  result = nanosecondsToTimestamp(0, NULL);
  if (result == NULL) {
    printLog(ERR, "nanosecondsToTimestamp(0) returned NULL\n");
    return false;
  }
  printLog(DEBUG, "nanosecondsToTimestamp(0, NULL) = %s\n", result);
  free(result);
  
  printLog(DEBUG, "nanosecondsToTimestamp tests passed\n");
  return true;
}

///
/// @fn bool testTimestampToNanoseconds()
///
/// @brief Test the timestampToNanoseconds function.
///
/// @return Returns true if all tests pass, false otherwise.
///
bool testTimestampToNanoseconds() {
  i64 result;
  
  printLog(DEBUG, "Testing timestampToNanoseconds function...\n");
  
  // Test valid timestamp with nanoseconds
  result = timestampToNanoseconds(VALID_TIMESTAMP);
  if (result == 0) {
    printLog(ERR, "timestampToNanoseconds failed for valid timestamp: %s\n", 
             VALID_TIMESTAMP);
    return false;
  }
  printLog(DEBUG, "timestampToNanoseconds('%s') = %lld\n", 
           VALID_TIMESTAMP, (long long)result);
  
  // Test valid timestamp without nanoseconds
  result = timestampToNanoseconds(VALID_TIMESTAMP_NO_NS);
  if (result == 0) {
    printLog(ERR, 
             "timestampToNanoseconds failed for valid timestamp without ns: "
             "%s\n", VALID_TIMESTAMP_NO_NS);
    return false;
  }
  printLog(DEBUG, "timestampToNanoseconds('%s') = %lld\n", 
           VALID_TIMESTAMP_NO_NS, (long long)result);
  
  // Test NULL parameter
  result = timestampToNanoseconds(NULL);
  if (result != 0) {
    printLog(ERR, "timestampToNanoseconds(NULL) should return 0, got %lld\n", 
             (long long)result);
    return false;
  }
  
  // Test empty string
  result = timestampToNanoseconds(EMPTY_STRING);
  if (result != 0) {
    printLog(ERR, "timestampToNanoseconds('') should return 0, got %lld\n", 
             (long long)result);
    return false;
  }
  
  // Test invalid timestamp
  result = timestampToNanoseconds(INVALID_TIMESTAMP);
  if (result != 0) {
    printLog(ERR, "timestampToNanoseconds('%s') should return 0, got %lld\n", 
             INVALID_TIMESTAMP, (long long)result);
    return false;
  }
  
  printLog(DEBUG, "timestampToNanoseconds tests passed\n");
  return true;
}

///
/// @fn bool testIsDst()
///
/// @brief Test the isDst function with various time values.
///
/// @return Returns true if all tests pass, false otherwise.
///
bool testIsDst() {
  time_t result;
  time_t testTime;
  
  printLog(DEBUG, "Testing isDst function...\n");
  
  // Test with current time
  testTime = time(NULL);
  result = isDst(testTime);
  printLog(DEBUG, "isDst(current_time) = %ld\n", (long)result);
  
  // Test with epoch time (January 1, 1970 - should not be DST)
  testTime = 0;
  result = isDst(testTime);
  printLog(DEBUG, "isDst(0) = %ld\n", (long)result);
  
  // Test with a known summer time (July 15, 2024)
  testTime = 1721001600; // Approximately July 15, 2024
  result = isDst(testTime);
  printLog(DEBUG, "isDst(summer_2024) = %ld\n", (long)result);
  
  // Test with a known winter time (January 15, 2024)
  testTime = 1705276800; // Approximately January 15, 2024
  result = isDst(testTime);
  printLog(DEBUG, "isDst(winter_2024) = %ld\n", (long)result);
  
  printLog(DEBUG, "isDst tests passed\n");
  return true;
}

///
/// @fn bool testGetNowNanoseconds()
///
/// @brief Test the getNowNanoseconds function.
///
/// @return Returns true if all tests pass, false otherwise.
///
bool testGetNowNanoseconds() {
  i64 result1, result2;
  
  printLog(DEBUG, "Testing getNowNanoseconds function...\n");
  
  // Get current time twice and ensure the second is greater than or equal
  result1 = getNowNanoseconds();
  if (result1 == 0) {
    printLog(ERR, "getNowNanoseconds() returned 0\n");
    return false;
  }
  
  // Small delay to ensure time progresses
  for (volatile int ii = 0; ii < 1000000; ii++) {
    // Busy wait
  }
  
  result2 = getNowNanoseconds();
  if (result2 < result1) {
    printLog(ERR, 
             "getNowNanoseconds() time went backwards: %lld -> %lld\n", 
             (long long)result1, (long long)result2);
    return false;
  }
  
  printLog(DEBUG, "getNowNanoseconds() first call = %lld\n", 
           (long long)result1);
  printLog(DEBUG, "getNowNanoseconds() second call = %lld\n", 
           (long long)result2);
  printLog(DEBUG, "Time difference = %lld nanoseconds\n", 
           (long long)(result2 - result1));
  
  printLog(DEBUG, "getNowNanoseconds tests passed\n");
  return true;
}

///
/// @fn bool testRoundTripConversions()
///
/// @brief Test round-trip conversions between timestamps and nanoseconds.
///
/// @return Returns true if all tests pass, false otherwise.
///
bool testRoundTripConversions() {
  const char *originalTimestamp = VALID_TIMESTAMP;
  i64 nanoseconds;
  char *convertedTimestamp;
  i64 convertedNanoseconds;
  
  printLog(DEBUG, "Testing round-trip conversions...\n");
  
  // Convert timestamp to nanoseconds and back
  nanoseconds = timestampToNanoseconds(originalTimestamp);
  if (nanoseconds == 0) {
    printLog(ERR, "Failed to convert timestamp to nanoseconds\n");
    return false;
  }
  
  convertedTimestamp = nanosecondsToTimestamp(nanoseconds, NULL);
  if (convertedTimestamp == NULL) {
    printLog(ERR, "Failed to convert nanoseconds back to timestamp\n");
    return false;
  }
  
  // Convert back to nanoseconds to verify
  convertedNanoseconds = timestampToNanoseconds(convertedTimestamp);
  
  printLog(DEBUG, "Original timestamp: %s\n", originalTimestamp);
  printLog(DEBUG, "Converted to nanoseconds: %lld\n", (long long)nanoseconds);
  printLog(DEBUG, "Converted back to timestamp: %s\n", convertedTimestamp);
  printLog(DEBUG, "Final nanoseconds: %lld\n", (long long)convertedNanoseconds);
  
  // The nanoseconds should match exactly
  if (nanoseconds != convertedNanoseconds) {
    printLog(ERR, 
             "Round-trip conversion failed: %lld != %lld\n", 
             (long long)nanoseconds, (long long)convertedNanoseconds);
    free(convertedTimestamp);
    return false;
  }
  
  free(convertedTimestamp);
  printLog(DEBUG, "Round-trip conversion tests passed\n");
  return true;
}

///
/// @fn bool testTimeConstants()
///
/// @brief Test the defined time constants for correctness.
///
/// @return Returns true if all tests pass, false otherwise.
///
bool testTimeConstants() {
  printLog(DEBUG, "Testing time constants...\n");
  
  // Verify the constants are defined correctly
  if (MINUTE_NANOSECONDS != 60000000000LL) {
    printLog(ERR, "MINUTE_NANOSECONDS incorrect: expected 60000000000, "
             "got %lld\n", (long long)MINUTE_NANOSECONDS);
    return false;
  }
  
  if (HOUR_NANOSECONDS != (60LL * MINUTE_NANOSECONDS)) {
    printLog(ERR, "HOUR_NANOSECONDS incorrect\n");
    return false;
  }
  
  if (DAY_NANOSECONDS != (24LL * HOUR_NANOSECONDS)) {
    printLog(ERR, "DAY_NANOSECONDS incorrect\n");
    return false;
  }
  
  if (WEEK_NANOSECONDS != (7LL * DAY_NANOSECONDS)) {
    printLog(ERR, "WEEK_NANOSECONDS incorrect\n");
    return false;
  }
  
  if (YEAR_NANOSECONDS != (365LL * DAY_NANOSECONDS)) {
    printLog(ERR, "YEAR_NANOSECONDS incorrect\n");
    return false;
  }
  
  if (LEAP_YEAR_NANOSECONDS != (366LL * DAY_NANOSECONDS)) {
    printLog(ERR, "LEAP_YEAR_NANOSECONDS incorrect\n");
    return false;
  }
  
  printLog(DEBUG, "MINUTE_NANOSECONDS = %lld\n", 
           (long long)MINUTE_NANOSECONDS);
  printLog(DEBUG, "HOUR_NANOSECONDS = %lld\n", (long long)HOUR_NANOSECONDS);
  printLog(DEBUG, "DAY_NANOSECONDS = %lld\n", (long long)DAY_NANOSECONDS);
  printLog(DEBUG, "WEEK_NANOSECONDS = %lld\n", (long long)WEEK_NANOSECONDS);
  printLog(DEBUG, "YEAR_NANOSECONDS = %lld\n", (long long)YEAR_NANOSECONDS);
  printLog(DEBUG, "LEAP_YEAR_NANOSECONDS = %lld\n", 
           (long long)LEAP_YEAR_NANOSECONDS);
  
  printLog(DEBUG, "Time constants tests passed\n");
  return true;
}

///
/// @fn bool timeUtilsUnitTest(void)
///
/// @brief Main unit test function for the TimeUtils library.
///
/// @return Returns true if all tests pass, false if any test fails.
///
bool timeUtilsUnitTest(void) {
  printLog(DEBUG, "Starting TimeUtils unit tests...\n");
  
  if (!testWeekdayToString()) {
    printLog(ERR, "testWeekdayToString failed\n");
    return false;
  }
  
  if (!testUtcTimestampToTime()) {
    printLog(ERR, "testUtcTimestampToTime failed\n");
    return false;
  }
  
  if (!testLocalTimestampToTime()) {
    printLog(ERR, "testLocalTimestampToTime failed\n");
    return false;
  }
  
  if (!testGetTimezoneNanosecondsFromTimestamp()) {
    printLog(ERR, "testGetTimezoneNanosecondsFromTimestamp failed\n");
    return false;
  }
  
  if (!testNanosecondsToTimestamp()) {
    printLog(ERR, "testNanosecondsToTimestamp failed\n");
    return false;
  }
  
  if (!testTimestampToNanoseconds()) {
    printLog(ERR, "testTimestampToNanoseconds failed\n");
    return false;
  }
  
  if (!testIsDst()) {
    printLog(ERR, "testIsDst failed\n");
    return false;
  }
  
  if (!testGetNowNanoseconds()) {
    printLog(ERR, "testGetNowNanoseconds failed\n");
    return false;
  }
  
  if (!testRoundTripConversions()) {
    printLog(ERR, "testRoundTripConversions failed\n");
    return false;
  }
  
  if (!testTimeConstants()) {
    printLog(ERR, "testTimeConstants failed\n");
    return false;
  }
  
  printLog(DEBUG, "All TimeUtils unit tests passed successfully!\n");
  return true;
}
