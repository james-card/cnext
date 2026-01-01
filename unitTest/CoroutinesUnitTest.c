///////////////////////////////////////////////////////////////////////////////
///
/// @file              CoroutinesUnitTest.c
///
/// @brief             Unit tests for the Coroutines and CoroutineSync APIs
///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

#include "Coroutines.h"
#include "CoroutineSync.h"
#include "LoggingLib.h"
#include "OsApi.h"

// Test helper variables
static bool testCallbackCalled = false;
static void *testCallbackStateData = NULL;
static Comutex *testCallbackComutex = NULL;
static Cocondition *testCallbackCocondition = NULL;

// Test coroutine functions
void *simpleCoroutineFunction(void *arg);
void *yieldingCoroutineFunction(void *arg);
void *mutexTestCoroutineFunction(void *arg);
void *conditionTestCoroutineFunction(void *arg);
void *recursiveMutexCoroutineFunction(void *arg);
void *timedMutexCoroutineFunction(void *arg);
void *timedConditionCoroutineFunction(void *arg);

// Test callback functions
void testComutexUnlockCallback(void *stateData, Comutex *comutex);
void testCoconditionSignalCallback(void *stateData, 
  Cocondition *cocondition);

// Individual test functions
bool testCoroutineBasicFunctionality(void);
bool testCoroutineIdFunctionality(void);
bool testCoroutineStateFunctionality(void);
bool testCoroutineNullParameters(void);
bool testComutexBasicFunctionality(void);
bool testComutexRecursiveFunctionality(void);
bool testComutexTimedFunctionality(void);
bool testComutexNullParameters(void);
bool testCoconditionBasicFunctionality(void);
bool testCoconditionTimedFunctionality(void);
bool testCoconditionNullParameters(void);
bool testCoroutineTermination(void);

///
/// @brief Simple coroutine function that just returns its argument
///
/// @param arg The argument passed to the coroutine
///
/// @return Returns the same argument that was passed in
///
void *simpleCoroutineFunction(void *arg) {
  printLog(DEBUG, "Simple coroutine function called with arg: %p\n", arg);
  return arg;
}

///
/// @brief Coroutine function that yields once before returning
///
/// @param arg The argument passed to the coroutine
///
/// @return Returns the argument multiplied by 2 (cast as pointer)
///
void *yieldingCoroutineFunction(void *arg) {
  intptr_t value = (intptr_t) arg;
  printLog(DEBUG, "Yielding coroutine function called with value: %ld\n", 
    (long int) value);
  
  void *yieldResult = coroutineYield((void *) (value + 1), 0);
  printLog(DEBUG, "Yielding coroutine resumed with: %ld\n", 
    (long int) ((intptr_t) yieldResult));
  
  return (void *) (value * 2);
}

///
/// @brief Coroutine function for testing mutex functionality
///
/// @param arg Pointer to a Comutex to test with
///
/// @return Returns NULL on success, non-NULL on error
///
void *mutexTestCoroutineFunction(void *arg) {
  Comutex *mutex = (Comutex *) arg;
  
  if (mutex == NULL) {
    printLog(ERR, "Mutex test coroutine received NULL mutex\n");
    return (void *) 1;
  }
  
  printLog(DEBUG, "Mutex test coroutine attempting to lock mutex\n");
  int result = comutexLock(mutex);
  if (result != 0) {
    printLog(ERR, "Failed to lock mutex in test coroutine: %d\n", result);
    return (void *) 2;
  }
  
  printLog(DEBUG, "Mutex test coroutine acquired lock, yielding\n");
  coroutineYield(NULL, 0);
  
  printLog(DEBUG, "Mutex test coroutine unlocking mutex\n");
  result = comutexUnlock(mutex);
  if (result != 0) {
    printLog(ERR, "Failed to unlock mutex in test coroutine: %d\n", result);
    return (void *) 3;
  }
  
  return NULL;
}

///
/// @brief Coroutine function for testing condition functionality
///
/// @param arg Pointer to a Cocondition to test with
///
/// @return Returns NULL on success, non-NULL on error
///
void *conditionTestCoroutineFunction(void *arg) {
  Cocondition *condition = (Cocondition *) arg;
  Comutex mutex;
  
  if (condition == NULL) {
    printLog(ERR, "Condition test coroutine received NULL condition\n");
    return (void *) 1;
  }
  
  int result = comutexInit(&mutex, comutexPlain);
  if (result != 0) {
    printLog(ERR, "Failed to initialize mutex in condition test: %d\n", 
      result);
    return (void *) 2;
  }
  
  result = comutexLock(&mutex);
  if (result != 0) {
    printLog(ERR, "Failed to lock mutex in condition test: %d\n", result);
    comutexDestroy(&mutex);
    return (void *) 3;
  }
  
  printLog(DEBUG, "Condition test coroutine waiting on condition\n");
  result = coconditionWait(condition, &mutex);
  if (result != 0) {
    printLog(ERR, "Failed to wait on condition: %d\n", result);
    comutexUnlock(&mutex);
    comutexDestroy(&mutex);
    return (void *) 4;
  }
  
  printLog(DEBUG, "Condition test coroutine woke up from wait\n");
  comutexUnlock(&mutex);
  comutexDestroy(&mutex);
  
  return NULL;
}

///
/// @brief Coroutine function for testing recursive mutex functionality
///
/// @param arg Pointer to a Comutex to test with
///
/// @return Returns NULL on success, non-NULL on error
///
void *recursiveMutexCoroutineFunction(void *arg) {
  Comutex *mutex = (Comutex *) arg;
  
  if (mutex == NULL) {
    return (void *) 1;
  }
  
  // Lock the mutex multiple times
  for (int ii = 0; ii < 3; ii++) {
    int result = comutexLock(mutex);
    if (result != 0) {
      printLog(ERR, "Failed to lock recursive mutex (iteration %d): %d\n", 
        ii, result);
      return (void *) ((intptr_t) (2 + ii));
    }
    printLog(DEBUG, "Locked recursive mutex %d times\n", ii + 1);
  }
  
  // Unlock the mutex the same number of times
  for (int ii = 0; ii < 3; ii++) {
    int result = comutexUnlock(mutex);
    if (result != 0) {
      printLog(ERR, "Failed to unlock recursive mutex (iteration %d): %d\n", 
        ii, result);
      return (void *) ((intptr_t) (5 + ii));
    }
    printLog(DEBUG, "Unlocked recursive mutex, %d locks remaining\n", 2 - ii);
  }
  
  return NULL;
}

///
/// @brief Coroutine function for testing timed mutex functionality
///
/// @param arg Pointer to a Comutex to test with
///
/// @return Returns NULL on success, non-NULL on error
///
void *timedMutexCoroutineFunction(void *arg) {
  Comutex *mutex = (Comutex *) arg;
  struct timespec timeout;
  
  if (mutex == NULL) {
    return (void *) 1;
  }
  
  // Set timeout to 100ms from now
  timespec_get(&timeout, TIME_UTC);
  timeout.tv_nsec += 100000000; // 100ms
  if (timeout.tv_nsec >= 1000000000) {
    timeout.tv_sec++;
    timeout.tv_nsec -= 1000000000;
  }
  
  printLog(DEBUG, "Timed mutex coroutine attempting timed lock\n");
  int result = comutexTimedLock(mutex, &timeout);
  
  if (result == coroutineTimedout) {
    printLog(DEBUG, "Timed mutex lock timed out as expected\n");
    return NULL;
  } else if (result == 0) {
    printLog(DEBUG, "Timed mutex lock succeeded\n");
    comutexUnlock(mutex);
    return NULL;
  } else {
    printLog(ERR, "Timed mutex lock failed with error: %d\n", result);
    return (void *) 2;
  }
}

///
/// @brief Coroutine function for testing timed condition functionality
///
/// @param arg Pointer to a Cocondition to test with
///
/// @return Returns NULL on success, non-NULL on error
///
void *timedConditionCoroutineFunction(void *arg) {
  Cocondition *condition = (Cocondition *) arg;
  Comutex mutex;
  struct timespec timeout;
  
  if (condition == NULL) {
    return (void *) 1;
  }
  
  int result = comutexInit(&mutex, comutexPlain);
  if (result != 0) {
    return (void *) 2;
  }
  
  result = comutexLock(&mutex);
  if (result != 0) {
    comutexDestroy(&mutex);
    return (void *) 3;
  }
  
  // Set timeout to 100ms from now
  timespec_get(&timeout, TIME_UTC);
  timeout.tv_nsec += 100000000; // 100ms
  if (timeout.tv_nsec >= 1000000000) {
    timeout.tv_sec++;
    timeout.tv_nsec -= 1000000000;
  }
  
  printLog(DEBUG, "Timed condition coroutine attempting timed wait\n");
  result = coconditionTimedWait(condition, &mutex, &timeout);
  
  if (result == coroutineTimedout) {
    printLog(DEBUG, "Timed condition wait timed out as expected\n");
  } else if (result == 0) {
    printLog(DEBUG, "Timed condition wait succeeded\n");
  } else {
    printLog(ERR, "Timed condition wait failed with error: %d\n", result);
    comutexUnlock(&mutex);
    comutexDestroy(&mutex);
    return (void *) 4;
  }
  
  comutexUnlock(&mutex);
  comutexDestroy(&mutex);
  return NULL;
}

///
/// @brief Test callback for comutex unlock events
///
/// @param stateData State data passed to the callback
/// @param comutex The comutex that was unlocked
///
void testComutexUnlockCallback(void *stateData, Comutex *comutex) {
  printLog(DEBUG, "Comutex unlock callback called\n");
  testCallbackCalled = true;
  testCallbackStateData = stateData;
  testCallbackComutex = comutex;
}

///
/// @brief Test callback for cocondition signal events
///
/// @param stateData State data passed to the callback
/// @param cocondition The cocondition that was signalled
///
void testCoconditionSignalCallback(void *stateData, 
  Cocondition *cocondition) {
  printLog(DEBUG, "Cocondition signal callback called\n");
  testCallbackCalled = true;
  testCallbackStateData = stateData;
  testCallbackCocondition = cocondition;
}

///
/// @brief Test basic coroutine functionality
///
/// @return Returns true if all tests pass, false otherwise
///
bool testCoroutineBasicFunctionality(void) {
  printLog(DEBUG, "Testing basic coroutine functionality\n");
  
  // Test coroutineCreate and coroutineResume with simple function
  Coroutine *coroutine = NULL;
  void *testArg = (void *) 0x12345678;
  
  int result = coroutineCreate(&coroutine, simpleCoroutineFunction, testArg);
  if (result != coroutineSuccess) {
    printLog(ERR, "Failed to create simple coroutine: %d\n", result);
    return false;
  }
  
  if (coroutine == NULL) {
    printLog(ERR, "coroutineCreate returned success but coroutine is NULL\n");
    return false;
  }
  
  if (!coroutineResumable(coroutine)) {
    printLog(ERR, "New coroutine should be resumable\n");
    return false;
  }
  
  void *resumeResult = coroutineResume(coroutine, NULL);
  if (resumeResult != testArg) {
    printLog(ERR, "Simple coroutine should return its original argument\n");
    return false;
  }
  
  if (coroutineResumable(coroutine)) {
    printLog(ERR, "Completed coroutine should not be resumable\n");
    return false;
  }
  
  if (!coroutineFinished(coroutine)) {
    printLog(ERR, "Completed coroutine should be finished\n");
    return false;
  }
  
  // Test yielding coroutine
  result = coroutineCreate(&coroutine, yieldingCoroutineFunction, 
    (void *) 10);
  if (result != coroutineSuccess) {
    printLog(ERR, "Failed to create yielding coroutine: %d\n", result);
    return false;
  }
  
  resumeResult = coroutineResume(coroutine, NULL);
  if ((intptr_t) resumeResult != 11) {
    printLog(ERR, "Yielding coroutine should yield value + 1\n");
    return false;
  }
  
  if (!coroutineResumable(coroutine)) {
    printLog(ERR, "Yielded coroutine should be resumable\n");
    return false;
  }
  
  if (coroutineFinished(coroutine)) {
    printLog(ERR, "Yielded coroutine should not be finished\n");
    return false;
  }
  
  resumeResult = coroutineResume(coroutine, (void *) 99);
  if ((intptr_t) resumeResult != 20) {
    printLog(ERR, "Resumed coroutine should return original arg * 2\n");
    return false;
  }
  
  if (!coroutineFinished(coroutine)) {
    printLog(ERR, "Completed yielding coroutine should be finished\n");
    return false;
  }
  
  printLog(DEBUG, "Basic coroutine functionality tests passed\n");
  return true;
}

///
/// @brief Test coroutine ID functionality
///
/// @return Returns true if all tests pass, false otherwise
///
bool testCoroutineIdFunctionality(void) {
  printLog(DEBUG, "Testing coroutine ID functionality\n");
  
  Coroutine *coroutine = NULL;
  int result = coroutineCreate(&coroutine, simpleCoroutineFunction, NULL);
  if (result != coroutineSuccess) {
    printLog(ERR, "Failed to create coroutine for ID test: %d\n", result);
    return false;
  }
  
  // Test initial ID value
  CoroutineId initialId = coroutineId(coroutine);
  if (initialId != COROUTINE_ID_NOT_SET) {
    printLog(ERR, "New coroutine should have ID set to COROUTINE_ID_NOT_SET\n");
    return false;
  }
  
  // Test setting and getting ID
  CoroutineId testId = 42;
  result = coroutineSetId(coroutine, testId);
  if (result != coroutineSuccess) {
    printLog(ERR, "Failed to set coroutine ID: %d\n", result);
    return false;
  }
  
  CoroutineId retrievedId = coroutineId(coroutine);
  if (retrievedId != testId) {
    printLog(ERR, "Retrieved coroutine ID doesn't match set ID\n");
    return false;
  }
  
  // Clean up
  coroutineResume(coroutine, NULL);
  
  printLog(DEBUG, "Coroutine ID functionality tests passed\n");
  return true;
}

///
/// @brief Test coroutine state functionality
///
/// @return Returns true if all tests pass, false otherwise
///
bool testCoroutineStateFunctionality(void) {
  printLog(DEBUG, "Testing coroutine state functionality\n");
  
  Coroutine *coroutine = NULL;
  int result = coroutineCreate(&coroutine, yieldingCoroutineFunction, NULL);
  if (result != coroutineSuccess) {
    printLog(ERR, "Failed to create coroutine for state test: %d\n", result);
    return false;
  }
  
  // Test initial state
  CoroutineState state = coroutineState(coroutine);
  if (state != COROUTINE_STATE_BLOCKED) {
    printLog(ERR, "New coroutine should be in NOT_RUNNING state\n");
    return false;
  }
  
  if (!coroutineRunning(coroutine)) {
    printLog(ERR, "New coroutine should be considered running\n");
    return false;
  }
  
  // Resume to yield point
  coroutineResume(coroutine, NULL);
  
  state = coroutineState(coroutine);
  if (state != COROUTINE_STATE_BLOCKED) {
    printLog(ERR, "Yielded coroutine should be in NOT_RUNNING state\n");
    return false;
  }
  
  // Complete the coroutine
  coroutineResume(coroutine, NULL);
  
  state = coroutineState(coroutine);
  if (state != COROUTINE_STATE_NOT_RUNNING) {
    printLog(ERR, "Completed coroutine should be in NOT_RUNNING state\n");
    return false;
  }
  
  printLog(DEBUG, "Coroutine state functionality tests passed\n");
  return true;
}

///
/// @brief Test coroutine functions with NULL parameters
///
/// @return Returns true if all tests pass, false otherwise
///
bool testCoroutineNullParameters(void) {
  printLog(DEBUG, "Testing coroutine functions with NULL parameters\n");
  
  // Test coroutineCreate with NULL coroutine pointer
  int result = coroutineCreate(NULL, simpleCoroutineFunction, NULL);
  if (result == coroutineSuccess) {
    printLog(ERR, "coroutineCreate should fail with NULL coroutine pointer\n");
    return false;
  }
  
  // Test coroutineCreate with NULL function
  Coroutine *coroutine = NULL;
  result = coroutineCreate(&coroutine, NULL, NULL);
  if (result == coroutineSuccess) {
    printLog(ERR, "coroutineCreate should fail with NULL function\n");
    return false;
  }
  
  // Test coroutineResume with NULL coroutine
  void *resumeResult = coroutineResume(NULL, NULL);
  if ((resumeResult != COROUTINE_ERROR) || (coroutineResumable((coro_t) NULL))) {
    printLog(ERR, "coroutineResume should return COROUTINE_NOT_RESUMABLE "
      "for NULL coroutine\n");
    return false;
  }
  
  // Test coroutineId with NULL coroutine
  CoroutineId id = coroutineId(NULL);
  if (id != COROUTINE_ID_NOT_SET) {
    printLog(ERR, "coroutineId should return COROUTINE_ID_NOT_SET "
      "for NULL coroutine\n");
    return false;
  }
  
  // Test coroutineSetId with NULL coroutine
  result = coroutineSetId(NULL, 42);
  if (result == coroutineSuccess) {
    printLog(ERR, "coroutineSetId should fail with NULL coroutine\n");
    return false;
  }
  
  // Test coroutineState with NULL coroutine
  CoroutineState state = coroutineState(NULL);
  if (state != COROUTINE_STATE_NOT_RUNNING) {
    printLog(ERR, "coroutineState should return COROUTINE_STATE_NOT_RUNNING "
      "for NULL coroutine\n");
    return false;
  }
  
  printLog(DEBUG, "Coroutine NULL parameter tests passed\n");
  return true;
}

///
/// @brief Test basic comutex functionality
///
/// @return Returns true if all tests pass, false otherwise
///
bool testComutexBasicFunctionality(void) {
  printLog(DEBUG, "Testing basic comutex functionality\n");
  
  Comutex mutex;
  
  // Test comutexInit
  int result = comutexInit(&mutex, comutexPlain);
  if (result != 0) {
    printLog(ERR, "Failed to initialize plain comutex: %d\n", result);
    return false;
  }
  
  // Test comutexTryLock on unlocked mutex
  result = comutexTryLock(&mutex);
  if (result != 0) {
    printLog(ERR, "Failed to try-lock unlocked comutex: %d\n", result);
    return false;
  }
  
  // Test comutexTryLock on locked mutex (should fail)
  result = comutexTryLock(&mutex);
  if (result == 0) {
    printLog(ERR, "Try-lock should fail on already locked comutex\n");
    return false;
  }
  
  // Test comutexUnlock
  result = comutexUnlock(&mutex);
  if (result != 0) {
    printLog(ERR, "Failed to unlock comutex: %d\n", result);
    return false;
  }
  
  // Test comutexLock and comutexUnlock
  result = comutexLock(&mutex);
  if (result != 0) {
    printLog(ERR, "Failed to lock comutex: %d\n", result);
    return false;
  }
  
  result = comutexUnlock(&mutex);
  if (result != 0) {
    printLog(ERR, "Failed to unlock comutex after lock: %d\n", result);
    return false;
  }
  
  // Test comutexLastYieldValue
  void *lastYield = comutexLastYieldValue(&mutex);
  if (lastYield != NULL) {
    printLog(ERR, "Last yield value should be NULL for unused mutex\n");
    return false;
  }
  
  // Create coroutine to test locking
  Coroutine *coroutine;
  result = coroutineCreate(&coroutine, mutexTestCoroutineFunction,
    &mutex);
  if (result != coroutineSuccess) {
    printLog(ERR, "Failed to create recursive mutex test coroutine: %d\n", 
      result);
    comutexDestroy(&mutex);
    return false;
  }
  
  void *resumeResult = coroutineResume(coroutine, NULL);
  if (resumeResult != NULL) {
    printLog(ERR, "Recursive mutex test coroutine failed: %p\n", 
      resumeResult);
    comutexDestroy(&mutex);
    return false;
  }
  
  // The coroutine locked the mutex before yielding.  Resume it and let it
  // finish.
  resumeResult = coroutineResume(coroutine, NULL);
  if (resumeResult != NULL) {
    printLog(ERR, "Recursive mutex test coroutine failed: %p\n", 
      resumeResult);
    comutexDestroy(&mutex);
    return false;
  }
  
  // Clean up
  comutexDestroy(&mutex);
  
  printLog(DEBUG, "Basic comutex functionality tests passed\n");
  return true;
}

///
/// @brief Test recursive comutex functionality
///
/// @return Returns true if all tests pass, false otherwise
///
bool testComutexRecursiveFunctionality(void) {
  printLog(DEBUG, "Testing recursive comutex functionality\n");
  
  Comutex mutex;
  
  // Test comutexInit with recursive type
  int result = comutexInit(&mutex, comutexRecursive);
  if (result != 0) {
    printLog(ERR, "Failed to initialize recursive comutex: %d\n", result);
    return false;
  }
  
  // Create coroutine to test recursive locking
  Coroutine *coroutine = NULL;
  result = coroutineCreate(&coroutine, recursiveMutexCoroutineFunction, 
    &mutex);
  if (result != coroutineSuccess) {
    printLog(ERR, "Failed to create recursive mutex test coroutine: %d\n", 
      result);
    comutexDestroy(&mutex);
    return false;
  }
  
  void *resumeResult = coroutineResume(coroutine, NULL);
  if (resumeResult != NULL) {
    printLog(ERR, "Recursive mutex test coroutine failed: %p\n", 
      resumeResult);
    comutexDestroy(&mutex);
    return false;
  }
  
  // Clean up
  comutexDestroy(&mutex);
  
  printLog(DEBUG, "Recursive comutex functionality tests passed\n");
  return true;
}

///
/// @brief Test timed comutex functionality
///
/// @return Returns true if all tests pass, false otherwise
///
bool testComutexTimedFunctionality(void) {
  printLog(DEBUG, "Testing timed comutex functionality\n");
  
  Comutex mutex;
  
  // Test comutexInit with timed type
  int result = comutexInit(&mutex, comutexTimed);
  if (result != 0) {
    printLog(ERR, "Failed to initialize timed comutex: %d\n", result);
    return false;
  }
  
  // Lock the mutex first
  result = comutexLock(&mutex);
  if (result != 0) {
    printLog(ERR, "Failed to lock timed comutex: %d\n", result);
    comutexDestroy(&mutex);
    return false;
  }
  
  // Create coroutine to test timed locking (should timeout)
  Coroutine *coroutine = NULL;
  result = coroutineCreate(&coroutine, timedMutexCoroutineFunction, &mutex);
  if (result != coroutineSuccess) {
    printLog(ERR, "Failed to create timed mutex test coroutine: %d\n", 
      result);
    comutexUnlock(&mutex);
    comutexDestroy(&mutex);
    return false;
  }
  
  void *resumeResult = coroutineResume(coroutine, NULL);
  while (coroutineState(coroutine) == COROUTINE_STATE_TIMEDWAIT) {
    resumeResult = coroutineResume(coroutine, NULL);
  }
  if (resumeResult != NULL) {
    printLog(ERR, "Timed mutex test coroutine failed: %p\n", resumeResult);
    comutexUnlock(&mutex);
    comutexDestroy(&mutex);
    return false;
  }
  
  // Unlock and clean up
  comutexUnlock(&mutex);
  comutexDestroy(&mutex);
  
  printLog(DEBUG, "Timed comutex functionality tests passed\n");
  return true;
}

///
/// @brief Test comutex functions with NULL parameters
///
/// @return Returns true if all tests pass, false otherwise
///
bool testComutexNullParameters(void) {
  printLog(DEBUG, "Testing comutex functions with NULL parameters\n");
  
  // Test comutexInit with NULL mutex
  int result = comutexInit(NULL, comutexPlain);
  if (result == 0) {
    printLog(ERR, "comutexInit should fail with NULL mutex\n");
    return false;
  }
  
  // Test comutexLock with NULL mutex
  result = comutexLock(NULL);
  if (result == 0) {
    printLog(ERR, "comutexLock should fail with NULL mutex\n");
    return false;
  }
  
  // Test comutexUnlock with NULL mutex
  result = comutexUnlock(NULL);
  if (result == 0) {
    printLog(ERR, "comutexUnlock should fail with NULL mutex\n");
    return false;
  }
  
  // Test comutexTryLock with NULL mutex
  result = comutexTryLock(NULL);
  if (result == 0) {
    printLog(ERR, "comutexTryLock should fail with NULL mutex\n");
    return false;
  }
  
  // Test comutexTimedLock with NULL mutex
  struct timespec ts;
  timespec_get(&ts, TIME_UTC);
  result = comutexTimedLock(NULL, &ts);
  if (result == 0) {
    printLog(ERR, "comutexTimedLock should fail with NULL mutex\n");
    return false;
  }
  
  // Test comutexTimedLock with NULL timespec
  Comutex mutex;
  comutexInit(&mutex, comutexTimed);
  result = comutexTimedLock(&mutex, NULL);
  if (result == 0) {
    printLog(ERR, "comutexTimedLock should fail with NULL timespec\n");
    comutexDestroy(&mutex);
    return false;
  }
  comutexDestroy(&mutex);
  
  // Test comutexLastYieldValue with NULL mutex
  void *lastYield = comutexLastYieldValue(NULL);
  if (lastYield != NULL) {
    printLog(ERR, "comutexLastYieldValue should return NULL for NULL mutex\n");
    return false;
  }
  
  // Test comutexDestroy with NULL mutex (should not crash)
  comutexDestroy(NULL);
  
  printLog(DEBUG, "Comutex NULL parameter tests passed\n");
  return true;
}

///
/// @brief Test basic cocondition functionality
///
/// @return Returns true if all tests pass, false otherwise
///
bool testCoconditionBasicFunctionality(void) {
  printLog(DEBUG, "Testing basic cocondition functionality\n");
  
  Cocondition condition;
  
  // Test coconditionInit
  int result = coconditionInit(&condition);
  if (result != 0) {
    printLog(ERR, "Failed to initialize cocondition: %d\n", result);
    return false;
  }
  
  // Test coconditionSignal on condition with no waiters
  result = coconditionSignal(&condition);
  if (result != 0) {
    printLog(ERR, "Failed to signal cocondition with no waiters: %d\n", 
      result);
    return false;
  }
  
  // Test coconditionBroadcast on condition with no waiters
  result = coconditionBroadcast(&condition);
  if (result != 0) {
    printLog(ERR, "Failed to broadcast cocondition with no waiters: %d\n", 
      result);
    return false;
  }
  
  // Test coconditionLastYieldValue
  void *lastYield = coconditionLastYieldValue(&condition);
  if (lastYield != NULL) {
    printLog(ERR, "Last yield value should be NULL for unused condition\n");
    coconditionDestroy(&condition);
    return false;
  }
  
  // Create coroutine to test condition waiting
  Coroutine *coroutine = NULL;
  result = coroutineCreate(&coroutine, conditionTestCoroutineFunction, 
    &condition);
  if (result != coroutineSuccess) {
    printLog(ERR, "Failed to create condition test coroutine: %d\n", result);
    coconditionDestroy(&condition);
    return false;
  }
  
  // Resume coroutine to start waiting
  void *resumeResult = coroutineResume(coroutine, NULL);
  if (!coroutineResumable(coroutine)) {
    printLog(ERR, "Condition test coroutine should be waiting\n");
    coconditionDestroy(&condition);
    return false;
  }
  
  // Signal the condition to wake up the coroutine
  result = coconditionSignal(&condition);
  if (result != 0) {
    printLog(ERR, "Failed to signal cocondition with waiter: %d\n", result);
    coconditionDestroy(&condition);
    return false;
  }
  
  // Resume the coroutine to complete
  resumeResult = coroutineResume(coroutine, NULL);
  if (resumeResult != NULL) {
    printLog(ERR, "Condition test coroutine failed: %p\n", resumeResult);
    coconditionDestroy(&condition);
    return false;
  }
  
  // Clean up
  coconditionDestroy(&condition);
  
  printLog(DEBUG, "Basic cocondition functionality tests passed\n");
  return true;
}

///
/// @brief Test timed cocondition functionality
///
/// @return Returns true if all tests pass, false otherwise
///
bool testCoconditionTimedFunctionality(void) {
  printLog(DEBUG, "Testing timed cocondition functionality\n");
  
  Cocondition condition;
  
  // Test coconditionInit
  int result = coconditionInit(&condition);
  if (result != 0) {
    printLog(ERR, "Failed to initialize timed cocondition: %d\n", result);
    return false;
  }
  
  // Create coroutine to test timed waiting (should timeout)
  Coroutine *coroutine = NULL;
  result = coroutineCreate(&coroutine, timedConditionCoroutineFunction, 
    &condition);
  if (result != coroutineSuccess) {
    printLog(ERR, "Failed to create timed condition test coroutine: %d\n", 
      result);
    coconditionDestroy(&condition);
    return false;
  }
  
  void *resumeResult = coroutineResume(coroutine, NULL);
  while (coroutineState(coroutine) == COROUTINE_STATE_TIMEDWAIT) {
    resumeResult = coroutineResume(coroutine, NULL);
  }
  if (resumeResult != NULL) {
    printLog(ERR, "Timed condition test coroutine failed: %p\n", 
      resumeResult);
    coconditionDestroy(&condition);
    return false;
  }
  
  // Clean up
  coconditionDestroy(&condition);
  
  printLog(DEBUG, "Timed cocondition functionality tests passed\n");
  return true;
}

///
/// @brief Test cocondition functions with NULL parameters
///
/// @return Returns true if all tests pass, false otherwise
///
bool testCoconditionNullParameters(void) {
  printLog(DEBUG, "Testing cocondition functions with NULL parameters\n");
  
  // Test coconditionInit with NULL condition
  int result = coconditionInit(NULL);
  if (result == 0) {
    printLog(ERR, "coconditionInit should fail with NULL condition\n");
    return false;
  }
  
  // Test coconditionSignal with NULL condition
  result = coconditionSignal(NULL);
  if (result == 0) {
    printLog(ERR, "coconditionSignal should fail with NULL condition\n");
    return false;
  }
  
  // Test coconditionBroadcast with NULL condition
  result = coconditionBroadcast(NULL);
  if (result == 0) {
    printLog(ERR, "coconditionBroadcast should fail with NULL condition\n");
    return false;
  }
  
  // Test coconditionWait with NULL condition
  Comutex mutex;
  comutexInit(&mutex, comutexPlain);
  result = coconditionWait(NULL, &mutex);
  if (result == 0) {
    printLog(ERR, "coconditionWait should fail with NULL condition\n");
    comutexDestroy(&mutex);
    return false;
  }
  
  // Test coconditionWait with NULL mutex
  Cocondition condition;
  coconditionInit(&condition);
  result = coconditionWait(&condition, NULL);
  if (result == 0) {
    printLog(ERR, "coconditionWait should fail with NULL mutex\n");
    coconditionDestroy(&condition);
    return false;
  }
  
  // Test coconditionTimedWait with NULL condition
  struct timespec ts;
  timespec_get(&ts, TIME_UTC);
  result = coconditionTimedWait(NULL, &mutex, &ts);
  if (result == 0) {
    printLog(ERR, "coconditionTimedWait should fail with NULL condition\n");
    comutexDestroy(&mutex);
    coconditionDestroy(&condition);
    return false;
  }
  
  // Test coconditionTimedWait with NULL mutex
  result = coconditionTimedWait(&condition, NULL, &ts);
  if (result == 0) {
    printLog(ERR, "coconditionTimedWait should fail with NULL mutex\n");
    coconditionDestroy(&condition);
    comutexDestroy(&mutex);
    return false;
  }
  
  // Test coconditionTimedWait with NULL timespec
  result = coconditionTimedWait(&condition, &mutex, NULL);
  if (result == 0) {
    printLog(ERR, "coconditionTimedWait should fail with NULL timespec\n");
    coconditionDestroy(&condition);
    comutexDestroy(&mutex);
    return false;
  }
  
  // Test coconditionLastYieldValue with NULL condition
  void *lastYield = coconditionLastYieldValue(NULL);
  if (lastYield != NULL) {
    printLog(ERR, "coconditionLastYieldValue should return NULL for NULL "
      "condition\n");
    coconditionDestroy(&condition);
    comutexDestroy(&mutex);
    return false;
  }
  
  // Test coconditionDestroy with NULL condition (should not crash)
  coconditionDestroy(NULL);
  
  // Clean up
  coconditionDestroy(&condition);
  comutexDestroy(&mutex);
  
  printLog(DEBUG, "Cocondition NULL parameter tests passed\n");
  return true;
}

///
/// @brief Test coroutine termination functionality
///
/// @return Returns true if all tests pass, false otherwise
///
bool testCoroutineTermination(void) {
  printLog(DEBUG, "Testing coroutine termination functionality\n");
  
  // Create a coroutine that will yield
  Coroutine *coroutine = NULL;
  int result = coroutineCreate(&coroutine, yieldingCoroutineFunction, NULL);
  if (result != coroutineSuccess) {
    printLog(ERR, "Failed to create coroutine for termination test: %d\n", 
      result);
    return false;
  }
  
  // Resume to yield point
  coroutineResume(coroutine, NULL);
  if (!coroutineResumable(coroutine)) {
    printLog(ERR, "Coroutine should be resumable after yield\n");
    return false;
  }
  
  // Terminate the coroutine
  result = coroutineTerminate(coroutine, NULL);
  if (result != coroutineSuccess) {
    printLog(ERR, "Failed to terminate coroutine: %d\n", result);
    return false;
  }
  
  // Verify coroutine is no longer resumable
  if (coroutineResumable(coroutine)) {
    printLog(ERR, "Terminated coroutine should not be resumable\n");
    return false;
  }
  
  // Test terminating NULL coroutine
  result = coroutineTerminate(NULL, NULL);
  if (result == coroutineSuccess) {
    printLog(ERR, "coroutineTerminate should fail with NULL coroutine\n");
    return false;
  }
  
  printLog(DEBUG, "Coroutine termination functionality tests passed\n");
  return true;
}

/// @fn void* lockingCoroutine(void *args)
///
/// @brief Coroutine that will lock all of the passed in mutexes, yielding
/// after each lock.
///
/// @param args A null-terminated array of Comutex objects, cast to a void*.
///
/// @return This function returns NULL on completion.
void* lockingCoroutine(void *args) {
  Comutex **mutexes = (Comutex**) args;
  
  for (int ii = 0; mutexes[ii] != NULL; ii++) {
    int rv = comutexLock(mutexes[ii]);
    if (rv != coroutineSuccess) {
      printLog(ERR, "comutexLock retunred status %d!\n", rv);
      // Signal to the caller that we've hit an error by returning non-NULL.
      return COROUTINE_ERROR;
    }
    coroutineYield(NULL, 0);
  }
  
  return NULL;
}

/// @fn void* timedLockingCoroutine(void *args)
///
/// @brief Coroutine that will wait for up to 60 seconds to lock all of the
/// passed in mutexes, yielding after each lock.
///
/// @param args A null-terminated array of Comutex objects, cast to a void*.
///
/// @return This function returns NULL on completion.
void* timedLockingCoroutine(void *args) {
  Comutex **mutexes = (Comutex**) args;
  struct timespec ts;
  timespec_get(&ts, TIME_UTC);
  ts.tv_sec += 3;
  
  int numLocked = 0;
  for (int ii = 0; mutexes[ii] != NULL; ii++) {
    int rv = comutexTimedLock(mutexes[ii], &ts);
    if (rv == coroutineSuccess) {
      numLocked++;
    } else {
      if (rv != coroutineTimedout) {
        printLog(ERR, "comutexTimedLock returned status %d\n", rv);
        // Signal to the caller that we've hit an error by returning non-NULL.
        return COROUTINE_ERROR;
      }
      //  We're done
      break;
    }
    coroutineYield(NULL, 0);
  }
  
  for (int ii = 0; ii < numLocked; ii++) {
    comutexUnlock(mutexes[ii]);
  }
  
  return NULL;
}

/// @fn bool testCoroutineDeadlock(void)
///
/// @brief Test that we can cause and properly detect deadlock, then terminate
/// the offending coroutines and validate that a non-deadlock situation is not
/// mis-detected as deadlock.
///
/// @return Returns true if all the test cases pass, false if not.
bool testCoroutineDeadlock(void) {
  Coroutine *coroutineA = NULL;
  Coroutine *coroutineB = NULL;
  
  Comutex comutexA;
  Comutex comutexB;
  
  comutexInit(&comutexA, comutexPlain | comutexTimed);
  comutexInit(&comutexB, comutexPlain | comutexTimed);
  
  Comutex *forwardList[] = {
    &comutexA,
    &comutexB,
    NULL,
  };
  
  Comutex *reverseList[] = {
    &comutexB,
    &comutexA,
    NULL,
  };
  
  int rv = coroutineCreate(&coroutineA, lockingCoroutine, forwardList);
  if (rv != coroutineSuccess) {
    printLog(ERR, "coroutineCreate for coroutine A returned status %d\n", rv);
    return false;
  }
  printLog(INFO, "coroutineA = %p\n", coroutineA);
  coroutineSetId(coroutineA, 0);
  
  coroutineCreate(&coroutineB, lockingCoroutine, reverseList);
  if (rv != coroutineSuccess) {
    printLog(ERR, "coroutineCreate for coroutine B returned status %d\n", rv);
    return false;
  }
  printLog(INFO, "coroutineB = %p\n", coroutineB);
  coroutineSetId(coroutineB, 1);
  
  Coroutine *coroutines[] = {
    coroutineA,
    coroutineB,
  };
  
  for (int ii = 0; ii < 4; ii++) {
    void *resumeStatus = coroutineResume(coroutines[ii & 1], NULL);
    if (resumeStatus != NULL) {
      printLog(ERR, "Resuming coroutine %d (%p) returned %p\n",
        (ii & 1), coroutines[ii & 1], resumeStatus);
      printLog(ERR, "coroutineCorrupted = %s\n",
        boolNames[coroutineCorrupted(coroutines[ii & 1])]);
      printLog(ERR, "coroutineResumable = %s\n",
        boolNames[coroutineResumable(coroutines[ii & 1])]);
      return false;
    }
  }
  
  if (!coroutineDeadlocked(coroutineA)) {
    printLog(ERR, "coroutineA not deadlocked as expected!\n");
    return false;
  }
  printLog(INFO, "coroutineA is deadlocked as expected\n");
  
  if (!coroutineDeadlocked(coroutineB)) {
    printLog(ERR, "coroutineB not deadlocked as expected!\n");
    return false;
  }
  printLog(INFO, "coroutineB is deadlocked as expected\n");
  
  if (coroutineTerminate(coroutineA, forwardList) != coroutineSuccess) {
    printLog(ERR, "Could not terminate coroutineA!\n");
    return false;
  }
  printLog(INFO, "Terminated coroutineA\n");
  
  if (coroutineTerminate(coroutineB, reverseList) != coroutineSuccess) {
    printLog(ERR, "Could not terminate coroutineB!\n");
    return false;
  }
  printLog(INFO, "Terminated coroutineB\n");
  
  coroutineCreate(&coroutineA, lockingCoroutine, forwardList);
  coroutineSetId(coroutineA, 0);
  coroutines[0] = coroutineA;
  coroutineCreate(&coroutineB, timedLockingCoroutine, reverseList);
  coroutineSetId(coroutineB, 1);
  coroutines[1] = coroutineB;
  
  for (int ii = 0; ii < 4; ii++) {
    void *resumeStatus = coroutineResume(coroutines[ii & 1], NULL);
    if (resumeStatus != NULL) {
      printLog(ERR, "Resuming coroutine %d (%p) returned %p\n",
        (ii & 1), coroutines[ii & 1], resumeStatus);
      printLog(ERR, "coroutineCorrupted = %s\n",
        boolNames[coroutineCorrupted(coroutines[ii & 1])]);
      printLog(ERR, "coroutineResumable = %s\n",
        boolNames[coroutineResumable(coroutines[ii & 1])]);
      return false;
    }
  }
  
  if (coroutineDeadlocked(coroutineA)) {
    printLog(ERR, "coroutineA was unexpectedly deadlocked!\n");
    return false;
  }
  printLog(INFO, "coroutineA is not deadlocked as expected\n");
  
  if (coroutineDeadlocked(coroutineB)) {
    printLog(ERR, "coroutineB was unexpectedly deadlocked!\n");
    return false;
  }
  printLog(INFO, "coroutineB is not deadlocked as expected\n");
  
  int64_t startTime = getElapsedMicroseconds(0);
  while (getElapsedMicroseconds(startTime) < 5000000) {
    for (int ii = 0; ii < 2; ii++) {
      if (coroutineResumable(coroutines[ii])) {
        void *resumeStatus = coroutineResume(coroutines[ii], NULL);
        if (resumeStatus != NULL) {
          printLog(ERR, "Resuming coroutine %d (%p) returned %p\n",
            (ii & 1), coroutines[ii & 1], resumeStatus);
          printLog(ERR, "coroutineCorrupted = %s\n",
            boolNames[coroutineCorrupted(coroutines[ii & 1])]);
          printLog(ERR, "coroutineResumable = %s\n",
            boolNames[coroutineResumable(coroutines[ii & 1])]);
          return false;
        }
      }
    }
  }
  
  if (coroutineDeadlocked(coroutineA)) {
    printLog(ERR, "coroutineA was unexpectedly deadlocked!\n");
    return false;
  }
  printLog(INFO, "coroutineA is not deadlocked as expected\n");
  
  if (coroutineDeadlocked(coroutineB)) {
    printLog(ERR, "coroutineB was unexpectedly deadlocked!\n");
    return false;
  }
  printLog(INFO, "coroutineB is not deadlocked as expected\n");
  
  if (coroutineRunning(coroutineA)) {
    printLog(ERR, "coroutineA was unexpectedly running!\n");
    return false;
  }
  printLog(INFO, "coroutineA is still running as expected\n");
  
  if (coroutineRunning(coroutineB)) {
    printLog(ERR, "coroutineB was unexpectedly running!\n");
    return false;
  }
  printLog(INFO, "coroutineB is NOT running as expected\n");
  
  if (comutexA.coroutine != coroutineA) {
    printLog(ERR, "comutexA's locking coroutine was not coroutineA as expected!\n");
    return false;
  }
  printLog(INFO, "comutexA is owned by coroutineA as expected\n");
  
  if (comutexB.coroutine != coroutineA) {
    printLog(ERR, "comutexB's locking coroutine was not coroutineA as expected!\n");
    return false;
  }
  printLog(INFO, "comutexB is owned by coroutineA as expected\n");
  
  return true;
}

/// @var globalCoroutine
///
/// @brief The coroutine that will hold the state for the root coroutine.  This
/// must be declared outside a function because it must persist after any
/// function completes.
static Coroutine globalCoroutine;

///
/// @brief Main unit test function for coroutines
///
/// @return Returns true if all tests pass, false if any test fails
///
bool coroutinesUnitTest(void) {
  printLog(DEBUG, "Starting coroutines unit test suite\n");
  
  // Initialize coroutine system with test callbacks
  void *testStateData = (void *) 0xDEADBEEF;
  Coroutine threadCoroutine;
  CoroutineConfigOptions coroutineConfigOptions = {
    .stackSize = COROUTINE_DEFAULT_STACK_SIZE + 512 + 256 + 128 + 64 + 32,
    .stateData = testStateData,
    .coroutineYieldCallback = NULL,
    .comutexUnlockCallback = testComutexUnlockCallback,
    .coconditionSignalCallback = testCoconditionSignalCallback,
  };
  
  int result = coroutineConfig(&globalCoroutine, &coroutineConfigOptions);
  if (result != coroutineSuccess) {
    printLog(ERR, "Failed to configure coroutine system: %d\n", result);
    return false;
  }
  
  bool allTestsPassed = true;
  
  for (int ii = 0; ii < 3; ii++) {
    // Run all test functions
    if (!testCoroutineBasicFunctionality()) {
      allTestsPassed = false;
    }
    
    if (!testCoroutineIdFunctionality()) {
      allTestsPassed = false;
    }
    
    if (!testCoroutineStateFunctionality()) {
      allTestsPassed = false;
    }
    
    if (!testCoroutineNullParameters()) {
      allTestsPassed = false;
    }
    
    if (!testComutexBasicFunctionality()) {
      allTestsPassed = false;
    }
    
    if (!testComutexRecursiveFunctionality()) {
      allTestsPassed = false;
    }
    
    if (!testComutexTimedFunctionality()) {
      allTestsPassed = false;
    }
    
    if (!testComutexNullParameters()) {
      allTestsPassed = false;
    }
    
    if (!testCoconditionBasicFunctionality()) {
      allTestsPassed = false;
    }
    
    if (!testCoconditionTimedFunctionality()) {
      allTestsPassed = false;
    }
    
    if (!testCoconditionNullParameters()) {
      allTestsPassed = false;
    }
    
    if (!testCoroutineTermination()) {
      allTestsPassed = false;
    }
    
    if (!testCoroutineDeadlock()) {
      allTestsPassed = false;
    }
    
    // Test getRunningCoroutine function
    Coroutine *runningCoroutine = getRunningCoroutine();
    if (runningCoroutine == NULL) {
      printLog(ERR, "getRunningCoroutine should return non-NULL\n");
      allTestsPassed = false;
    } else {
      printLog(DEBUG, "getRunningCoroutine returned valid coroutine\n");
    }
    
    // Test getRunningCoroutineId macro
    CoroutineId runningId = getRunningCoroutineId();
    if (runningId == COROUTINE_ID_NOT_SET) {
      printLog(DEBUG, "Running coroutine ID is not set (expected)\n");
    } else {
      printLog(DEBUG, "Running coroutine ID: %lu\n", (unsigned long) runningId);
    }
    
#ifdef THREAD_SAFE_COROUTINES
    // Test threading support functions if available
    coroutineSetThreadingSupportEnabled(true);
#endif
    
    // coroutineConfig should reset the state of everything and let us go again.
    result = coroutineConfig(&threadCoroutine, &coroutineConfigOptions);
    if (result != coroutineSuccess) {
      printLog(ERR, "Failed to configure coroutine system: %d\n", result);
      return false;
    }
  }
  
#ifdef THREAD_SAFE_COROUTINES
  // Turn thread support off again.
  coroutineSetThreadingSupportEnabled(false);
#endif
  
  // Test coroutineGetNanoseconds function
  struct timespec ts;
  timespec_get(&ts, TIME_UTC);
  int64_t nanoseconds = coroutineGetNanoseconds(&ts);
  if (nanoseconds <= 0) {
    printLog(ERR, "coroutineGetNanoseconds should return positive value\n");
    allTestsPassed = false;
  } else {
    printLog(DEBUG, "coroutineGetNanoseconds returned: %lld\n", lld(nanoseconds));
  }
  
#ifdef THREAD_SAFE_COROUTINES
  // Test threading support functions if available
  bool originalState = coroutineThreadingSupportEnabled();
  printLog(DEBUG, "Original threading support state: %s\n", 
    originalState ? "enabled" : "disabled");
  
  coroutineSetThreadingSupportEnabled(!originalState);
  bool newState = coroutineThreadingSupportEnabled();
  if (newState == originalState) {
    printLog(ERR, "Threading support state should have changed\n");
    allTestsPassed = false;
  }
  
  // Restore original state
  coroutineSetThreadingSupportEnabled(originalState);
#endif
  
  result = coroutineConfig(&globalCoroutine, &coroutineConfigOptions);
  if (result != coroutineSuccess) {
    printLog(ERR, "Failed to set final coroutine config: %d\n", result);
    return false;
  }
  
  if (allTestsPassed) {
    printLog(DEBUG, "All coroutines unit tests PASSED\n");
  } else {
    printLog(ERR, "Some coroutines unit tests FAILED\n");
  }
  
  return allTestsPassed;
}
