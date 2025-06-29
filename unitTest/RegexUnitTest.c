#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Regex.h"
#include "LoggingLib.h"

///
/// Helper function to initialize a test regex object
/// @param regex Pointer to the regex object to initialize
///
void initializeTestRegex(Regex *regex) {
  if (regex != NULL) {
    memset(regex, 0, sizeof(Regex));
    regex->isPatternValid = false;
    regex->errorMessage = NULL;
  }
}

///
/// Helper function to initialize a test matcher object
/// @param matcher Pointer to the matcher object to initialize
///
void initializeTestMatcher(Matcher *matcher) {
  if (matcher != NULL) {
    matcher->foundAtIndex = -1;
    matcher->matchLength = 0;
    matcher->isFound = false;
  }
}

///
/// Test function for regexCompile and regexCompileLength functions
/// @return true if all tests pass, false otherwise
///
bool testRegexCompile(void) {
  Regex regex;
  
  printLog(DEBUG, "Testing regexCompile and regexCompileLength functions");
  
  // Test with NULL regex parameter
  regexCompile(NULL, "test");
  printLog(DEBUG, "regexCompile with NULL regex handled");
  
  // Test with NULL pattern parameter
  initializeTestRegex(&regex);
  regexCompile(&regex, NULL);
  if (regex.isPatternValid) {
    printLog(ERR, "regexCompile should fail with NULL pattern");
    return false;
  } else if (strcmp(regex.errorMessage, "NULL pattern string") != 0) {
    printLog(ERR, "Got unexpected error message \"%s\".\n", regex.errorMessage);
    return false;
  }
  
  // Test with valid simple pattern
  initializeTestRegex(&regex);
  regexCompile(&regex, "test");
  if (!regex.isPatternValid) {
    printLog(ERR, "regexCompile should succeed with valid pattern 'test'");
    return false;
  }
  
  // Test with empty pattern
  initializeTestRegex(&regex);
  regexCompile(&regex, "");
  // Empty pattern should be valid
  if (regex.isPatternValid) {
    printLog(ERR, "regexCompile should fail with empty pattern");
    return false;
  } else if (strcmp(regex.errorMessage, "Empty pattern string") != 0) {
    printLog(ERR, "Got unexpected error message \"%s\".\n", regex.errorMessage);
    return false;
  }
  
  // Test regexCompileLength with NULL regex
  regexCompileLength(NULL, "test", 4);
  printLog(DEBUG, "regexCompileLength with NULL regex handled");
  
  // Test regexCompileLength with NULL pattern
  initializeTestRegex(&regex);
  regexCompileLength(&regex, NULL, 0);
  if (regex.isPatternValid) {
    printLog(ERR, "regexCompileLength should fail with NULL pattern");
    return false;
  } else if (strcmp(regex.errorMessage, "NULL pattern string") != 0) {
    printLog(ERR, "Got unexpected error message \"%s\".\n", regex.errorMessage);
    return false;
  }
  
  // Test regexCompileLength with valid pattern
  initializeTestRegex(&regex);
  regexCompileLength(&regex, "test", 4);
  if (!regex.isPatternValid) {
    printLog(ERR, "regexCompileLength should succeed with valid pattern");
    return false;
  }
  
  // Test regexCompileLength with zero length
  initializeTestRegex(&regex);
  regexCompileLength(&regex, "test", 0);
  if (!regex.isPatternValid) {
    printLog(ERR, "regexCompileLength should succeed with zero length");
    return false;
  }
  
  // Test with complex pattern containing various regex features
  initializeTestRegex(&regex);
  regexCompile(&regex, "^[a-zA-Z0-9]+\\w*\\d{2,5}$");
  if (!regex.isPatternValid) {
    printLog(ERR, "regexCompile should succeed with complex pattern");
    return false;
  }
  
  printLog(DEBUG, "regexCompile tests passed");
  return true;
}

///
/// Test function for regexMatch and regexMatchMatcher functions
/// @return true if all tests pass, false otherwise
///
bool testRegexMatch(void) {
  Regex regex;
  Matcher matcher;
  
  printLog(DEBUG, "Testing regexMatch and regexMatchMatcher functions");
  
  // Test with NULL regex parameter
  initializeTestMatcher(&matcher);
  bool result = regexMatchMatcher(NULL, "test", &matcher);
  if (result) {
    printLog(ERR, "regexMatchMatcher should fail with NULL regex");
    return false;
  }
  
  // Test with NULL text parameter
  initializeTestRegex(&regex);
  regexCompile(&regex, "test");
  initializeTestMatcher(&matcher);
  result = regexMatchMatcher(&regex, NULL, &matcher);
  if (result) {
    printLog(ERR, "regexMatchMatcher should fail with NULL text");
    return false;
  }
  
  // Test with NULL matcher parameter
  initializeTestRegex(&regex);
  regexCompile(&regex, "test");
  result = regexMatchMatcher(&regex, "test", NULL);
  // This might succeed or fail depending on implementation
  printLog(DEBUG, "regexMatchMatcher with NULL matcher handled");
  
  // Test with invalid regex
  initializeTestRegex(&regex);
  regex.isPatternValid = false;
  initializeTestMatcher(&matcher);
  result = regexMatchMatcher(&regex, "test", &matcher);
  if (result) {
    printLog(ERR, "regexMatchMatcher should fail with invalid regex");
    return false;
  }
  
  // Test successful match
  initializeTestRegex(&regex);
  regexCompile(&regex, "test");
  if (!regex.isPatternValid) {
    printLog(ERR, "Failed to compile regex for match test");
    return false;
  }
  initializeTestMatcher(&matcher);
  result = regexMatchMatcher(&regex, "this is a test string", &matcher);
  if (!result || !matcher.isFound) {
    printLog(ERR, "regexMatchMatcher should find match in 'this is a test string'");
    return false;
  }
  
  // Test no match
  initializeTestRegex(&regex);
  regexCompile(&regex, "xyz");
  if (!regex.isPatternValid) {
    printLog(ERR, "Failed to compile regex for no match test");
    return false;
  }
  initializeTestMatcher(&matcher);
  result = regexMatchMatcher(&regex, "this is a test string", &matcher);
  if (result && matcher.isFound) {
    printLog(ERR, "regexMatchMatcher should not find match for 'xyz'");
    return false;
  }
  
  // Test regexMatch function (wrapper)
  initializeTestRegex(&regex);
  regexCompile(&regex, "test");
  if (!regex.isPatternValid) {
    printLog(ERR, "Failed to compile regex for regexMatch test");
    return false;
  }
  matcher = regexMatch(&regex, "this is a test string");
  if (!matcher.isFound) {
    printLog(ERR, "regexMatch should find match in 'this is a test string'");
    return false;
  }
  
  // Test regexMatch with NULL regex
  matcher = regexMatch(NULL, "test");
  if (matcher.isFound) {
    printLog(ERR, "regexMatch should not find match with NULL regex");
    return false;
  }
  
  // Test regexMatch with NULL text
  initializeTestRegex(&regex);
  regexCompile(&regex, "test");
  matcher = regexMatch(&regex, NULL);
  if (matcher.isFound) {
    printLog(ERR, "regexMatch should not find match with NULL text");
    return false;
  }
  
  // Test with empty text
  initializeTestRegex(&regex);
  regexCompile(&regex, "test");
  matcher = regexMatch(&regex, "");
  if (matcher.isFound) {
    printLog(ERR, "regexMatch should not find match in empty text");
    return false;
  }
  
  // Test with regex patterns that should match
  initializeTestRegex(&regex);
  regexCompile(&regex, "^test$");
  if (!regex.isPatternValid) {
    printLog(ERR, "Failed to compile anchored regex");
    return false;
  }
  matcher = regexMatch(&regex, "test");
  if (!matcher.isFound) {
    printLog(ERR, "Anchored regex should match exact string");
    return false;
  }
  
  printLog(DEBUG, "regexMatch tests passed");
  return true;
}

///
/// Test function for substitute function and macro
/// @return true if all tests pass, false otherwise
///
bool testSubstitute(void) {
  char buffer[1024];
  bool successful;
  const char *errorMessage;
  uint64_t result;
  
  printLog(DEBUG, "Testing substitute function");
  
  // Test with NULL haystack
  memset(buffer, 0, sizeof(buffer));
  result = substitute_(NULL, "test", "replacement", false, buffer, 
                      sizeof(buffer), &successful, &errorMessage);
  if (successful) {
    printLog(ERR, "substitute should fail with NULL haystack");
    return false;
  }
  
  // Test with NULL pattern
  memset(buffer, 0, sizeof(buffer));
  result = substitute_("this is a test", NULL, "replacement", false, buffer, 
                      sizeof(buffer), &successful, &errorMessage);
  if (successful) {
    printLog(ERR, "substitute should fail with NULL pattern");
    return false;
  }
  
  // Test with NULL replacement
  memset(buffer, 0, sizeof(buffer));
  result = substitute_("this is a test", "test", NULL, false, buffer, 
                      sizeof(buffer), &successful, &errorMessage);
  if (successful) {
    printLog(ERR, "substitute should fail with NULL replacement");
    return false;
  }
  
  // Test with NULL buffer
  result = substitute_("this is a test", "test", "replacement", false, NULL, 
                      1024, &successful, &errorMessage);
  if (successful) {
    printLog(ERR, "substitute should fail with NULL buffer");
    return false;
  }
  
  // Test with zero buffer length
  memset(buffer, 0, sizeof(buffer));
  result = substitute_("this is a test", "test", "replacement", false, buffer, 
                      0, &successful, &errorMessage);
  if (successful) {
    printLog(ERR, "substitute should fail with zero buffer length");
    return false;
  }
  
  // Test successful substitution
  memset(buffer, 0, sizeof(buffer));
  result = substitute_("this is a test", "test", "replacement", false, buffer, 
                      sizeof(buffer), &successful, &errorMessage);
  if (!successful) {
    printLog(ERR, "substitute should succeed with valid parameters");
    return false;
  }
  if (strcmp(buffer, "this is a replacement") != 0) {
    printLog(ERR, "substitute result should be 'this is a replacement', got '%s'", buffer);
    return false;
  }
  
  // Test with greedy substitution
  memset(buffer, 0, sizeof(buffer));
  result = substitute_("test test test", "test", "replacement", true, buffer, 
                      sizeof(buffer), &successful, &errorMessage);
  if (!successful) {
    printLog(ERR, "substitute should succeed with greedy substitution");
    return false;
  }
  
  // Test macro version (without optional parameters)
  memset(buffer, 0, sizeof(buffer));
  result = substitute("this is a test", "test", "replacement", false, buffer, 
                     sizeof(buffer));
  if (result == 0) {
    printLog(ERR, "substitute macro should return non-zero on success");
    return false;
  }
  
  // Test with no match
  memset(buffer, 0, sizeof(buffer));
  result = substitute_("this is a string", "xyz", "replacement", false, buffer, 
                      sizeof(buffer), &successful, &errorMessage);
  // Should still be successful even if no match
  if (!successful) {
    printLog(ERR, "substitute should succeed even with no match");
    return false;
  }
  
  printLog(DEBUG, "substitute tests passed");
  return true;
}

///
/// Test function for substituteMatch function and macro
/// @return true if all tests pass, false otherwise
///
bool testSubstituteMatch(void) {
  char buffer[1024];
  bool successful;
  const char *errorMessage;
  uint64_t result;
  
  printLog(DEBUG, "Testing substituteMatch function");
  
  // Test with NULL haystack
  memset(buffer, 0, sizeof(buffer));
  result = substituteMatch_(NULL, "\\(test\\)", "replacement", false, buffer, 
                           sizeof(buffer), &successful, &errorMessage);
  if (successful) {
    printLog(ERR, "substituteMatch should fail with NULL haystack");
    return false;
  }
  
  // Test with NULL pattern
  memset(buffer, 0, sizeof(buffer));
  result = substituteMatch_("this is a test", NULL, "replacement", false, 
                           buffer, sizeof(buffer), &successful, &errorMessage);
  if (successful) {
    printLog(ERR, "substituteMatch should fail with NULL pattern");
    return false;
  }
  
  // Test with NULL replacement
  memset(buffer, 0, sizeof(buffer));
  result = substituteMatch_("this is a test", "\\(test\\)", NULL, false, 
                           buffer, sizeof(buffer), &successful, &errorMessage);
  if (successful) {
    printLog(ERR, "substituteMatch should fail with NULL replacement");
    return false;
  }
  
  // Test with NULL buffer
  result = substituteMatch_("this is a test", "\\(test\\)", "replacement", 
                           false, NULL, 1024, &successful, &errorMessage);
  if (successful) {
    printLog(ERR, "substituteMatch should fail with NULL buffer");
    return false;
  }
  
  // Test with zero buffer length
  memset(buffer, 0, sizeof(buffer));
  result = substituteMatch_("this is a test", "\\(test\\)", "replacement", 
                           false, buffer, 0, &successful, &errorMessage);
  if (successful) {
    printLog(ERR, "substituteMatch should fail with zero buffer length");
    return false;
  }
  
  // Test successful substitution with subexpression
  memset(buffer, 0, sizeof(buffer));
  result = substituteMatch_("this is a test", "\\(test\\)", "replacement", 
                           false, buffer, sizeof(buffer), &successful, 
                           &errorMessage);
  if (!successful) {
    printLog(ERR, "substituteMatch should succeed with valid parameters");
    return false;
  }
  
  // Test macro version
  memset(buffer, 0, sizeof(buffer));
  result = substituteMatch("this is a test", "\\(test\\)", "replacement", 
                          false, buffer, sizeof(buffer));
  if (result == 0) {
    printLog(ERR, "substituteMatch macro should return non-zero on success");
    return false;
  }
  
  // Test with no match
  memset(buffer, 0, sizeof(buffer));
  result = substituteMatch_("this is a string", "\\(xyz\\)", "replacement", 
                           false, buffer, sizeof(buffer), &successful, 
                           &errorMessage);
  // Should still be successful even if no match
  if (!successful) {
    printLog(ERR, "substituteMatch should succeed even with no match");
    return false;
  }
  
  printLog(DEBUG, "substituteMatch tests passed");
  return true;
}

///
/// Test function for substituteMultiple function and macro
/// @return true if all tests pass, false otherwise
///
bool testSubstituteMultiple(void) {
  char buffer1[1024];
  char buffer2[1024];
  char *buffers[2] = {buffer1, buffer2};
  bool successful;
  const char *errorMessage;
  unsigned int finalIndex;
  uint64_t result;
  
  Substitution substitutions[] = {
    {"test", "replacement"},
    {"is", "was"},
    {NULL, NULL}  // NULL-terminated array
  };
  
  printLog(DEBUG, "Testing substituteMultiple function");
  
  // Test with NULL haystack
  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));
  result = substituteMultiple(NULL, substitutions, false, buffers, 
                              sizeof(buffer1), &finalIndex, &successful, 
                              &errorMessage, substitute_);
  if (successful) {
    printLog(ERR, "substituteMultiple should fail with NULL haystack");
    return false;
  }
  
  // Test with NULL substitutions
  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));
  result = substituteMultiple("this is a test", NULL, false, buffers, 
                              sizeof(buffer1), &finalIndex, &successful, 
                              &errorMessage, substitute_);
  if (successful) {
    printLog(ERR, "substituteMultiple should fail with NULL substitutions");
    return false;
  }
  
  // Test with NULL buffers
  result = substituteMultiple("this is a test", substitutions, false, NULL, 
                              sizeof(buffer1), &finalIndex, &successful, 
                              &errorMessage, substitute_);
  if (successful) {
    printLog(ERR, "substituteMultiple should fail with NULL buffers");
    return false;
  }
  
  // Test with NULL finalIndex
  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));
  result = substituteMultiple("this is a test", substitutions, false, buffers, 
                              sizeof(buffer1), NULL, &successful, 
                              &errorMessage, substitute_);
  if (successful) {
    printLog(ERR, "substituteMultiple should fail with NULL finalIndex");
    return false;
  }
  
  // Test with zero buffer length
  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));
  result = substituteMultiple("this is a test", substitutions, false, buffers, 
                              0, &finalIndex, &successful, &errorMessage, 
                              substitute_);
  if (successful) {
    printLog(ERR, "substituteMultiple should fail with zero buffer length");
    return false;
  }
  
  // Test with NULL substitute function
  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));
  result = substituteMultiple("this is a test", substitutions, false, buffers, 
                              sizeof(buffer1), &finalIndex, &successful, 
                              &errorMessage, NULL);
  if (!successful) {
    printLog(ERR, "substituteMultiple should succeed with NULL substitute function");
    return false;
  }
  
  // Test successful multiple substitutions
  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));
  strcpy(buffer1, "this is a test");  // Initialize first buffer
  result = substituteMultiple("this is a test", substitutions, false, buffers, 
                              sizeof(buffer1), &finalIndex, &successful, 
                              &errorMessage, substitute_);
  if (!successful) {
    printLog(ERR, "substituteMultiple should succeed with valid parameters");
    return false;
  }
  
  // Test macro version
  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));
  strcpy(buffer1, "this is a test");  // Initialize first buffer
  result = substituteMultiple("this is a test", substitutions, false, buffers, 
                             sizeof(buffer1), &finalIndex);
  if (result == 0) {
    printLog(ERR, "substituteMultiple macro should return non-zero on success");
    return false;
  }
  
  // Test with empty substitutions array
  Substitution emptySubstitutions[] = {
    {NULL, NULL}  // Immediately NULL-terminated
  };
  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));
  strcpy(buffer1, "this is a test");
  result = substituteMultiple("this is a test", emptySubstitutions, false, 
                              buffers, sizeof(buffer1), &finalIndex, 
                              &successful, &errorMessage, substitute_);
  if (!successful) {
    printLog(ERR, "substituteMultiple should succeed with empty substitutions");
    return false;
  }
  
  printLog(DEBUG, "substituteMultiple tests passed");
  return true;
}

///
/// Main unit test function that runs all regex tests
/// @return true if all tests pass, false if any test fails
///
bool regexUnitTest(void) {
  printLog(DEBUG, "Starting Regex unit tests");
  
  // Test regexCompile functions
  if (!testRegexCompile()) {
    printLog(ERR, "regexCompile tests failed");
    return false;
  }
  
  // Test regexMatch functions
  if (!testRegexMatch()) {
    printLog(ERR, "regexMatch tests failed");
    return false;
  }
  
  // Test substitute function
  if (!testSubstitute()) {
    printLog(ERR, "substitute tests failed");
    return false;
  }
  
  // Test substituteMatch function
  if (!testSubstituteMatch()) {
    printLog(ERR, "substituteMatch tests failed");
    return false;
  }
  
  // Test substituteMultiple function
  if (!testSubstituteMultiple()) {
    printLog(ERR, "substituteMultiple tests failed");
    return false;
  }
  
  printLog(DEBUG, "All Regex unit tests passed successfully");
  return true;
}
