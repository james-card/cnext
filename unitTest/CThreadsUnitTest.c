///////////////////////////////////////////////////////////////////////////////
///
/// @file              cThreadsUnitTest.c
///
/// @brief             Unit test for PosixCThreads.h functionality
///
/// @details           Comprehensive test covering all functions with both
///                    valid parameters and corner cases including NULL
///                    parameters.
///
///////////////////////////////////////////////////////////////////////////////

#include "PosixCThreads.h"
#include "LoggingLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

// Global test variables
static bool onceCallbackExecuted = false;
static int threadTestValue = 0;

///////////////////////////////////////////////////////////////////////////////
/// @brief Test callback for call_once functionality
///
/// @details This function is called by call_once to test the once_flag
///          functionality.
///////////////////////////////////////////////////////////////////////////////
void onceCallback(void) {
  onceCallbackExecuted = true;
  printLog(DEBUG, "Once callback executed\n");
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Thread function for testing thread creation and execution
///
/// @param arg Pointer to integer argument passed to thread
///
/// @return Thread exit code
///////////////////////////////////////////////////////////////////////////////
int testThreadFunction(void* arg) {
  if (arg == NULL) {
    printLog(ERR, "Thread function received NULL argument\n");
    return thrd_error;
  }
  
  int* value = (int*) arg;
  threadTestValue = *value * 2;
  printLog(DEBUG, "Thread function executed with value %d\n", *value);
  return thrd_success;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Thread function for testing thread termination
///
/// @param arg Unused parameter
///
/// @return Does not return normally
///////////////////////////////////////////////////////////////////////////////
int terminationTestThreadFunction(void* arg) {
  (void) arg;
  printLog(DEBUG, "terminationTestThreadFunction running...\n");
  
  // Sleep for a while to allow termination
  while (1) {
    sleep(1);
  }
  return thrd_success;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Destructor function for thread-specific storage
///
/// @param ptr Pointer to data being destroyed
///////////////////////////////////////////////////////////////////////////////
void tssDestructor(void* ptr) {
  if (ptr != NULL) {
    printLog(DEBUG, "TSS destructor called\n");
    free(ptr);
  }
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Test call_once functionality
///
/// @return true if test passes, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testCallOnce(void) {
  printLog(DEBUG, "Testing call_once functionality\n");
  
  once_flag flag = ONCE_FLAG_INIT;
  onceCallbackExecuted = false;
  
  // Test normal call_once
  call_once(&flag, onceCallback);
  if (!onceCallbackExecuted) {
    printLog(ERR, "call_once failed to execute callback\n");
    return false;
  }
  
  // Test that subsequent calls don't execute the callback again
  onceCallbackExecuted = false;
  call_once(&flag, onceCallback);
  if (onceCallbackExecuted) {
    printLog(ERR, "call_once executed callback multiple times\n");
    return false;
  }
  
  // Test NULL flag (should not crash)
  call_once(NULL, onceCallback);
  
  // Test NULL function (should not crash)
  once_flag flag2 = ONCE_FLAG_INIT;
  call_once(&flag2, NULL);
  
  printLog(DEBUG, "call_once tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Test mutex functionality
///
/// @return true if test passes, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testMutex(void) {
  printLog(DEBUG, "Testing mutex functionality\n");
  
  mtx_t mutex;
  
  // Test mutex initialization
  if (mtx_init(&mutex, mtx_plain) != 0) {
    printLog(ERR, "mtx_init failed for plain mutex\n");
    return false;
  }
  
  // Test mutex lock
  if (mtx_lock(&mutex) != 0) {
    printLog(ERR, "mtx_lock failed\n");
    return false;
  }
  
  // Test mutex trylock (should fail since already locked)
  if (mtx_trylock(&mutex) == 0) {
    printLog(ERR, "mtx_trylock succeeded on already locked mutex\n");
    return false;
  }
  
  // Test mutex unlock
  if (mtx_unlock(&mutex) != 0) {
    printLog(ERR, "mtx_unlock failed\n");
    return false;
  }
  
  // Test mutex trylock (should succeed now)
  if (mtx_trylock(&mutex) != 0) {
    printLog(ERR, "mtx_trylock failed on unlocked mutex\n");
    return false;
  }
  
  mtx_unlock(&mutex);
  
  // Test timed lock
  struct timespec timeout;
  timespec_get(&timeout, TIME_UTC);
  timeout.tv_sec += 1; // 1 second timeout
  
  if (mtx_timedlock(&mutex, &timeout) != 0) {
    printLog(ERR, "mtx_timedlock failed\n");
    return false;
  }
  
  mtx_unlock(&mutex);
  mtx_destroy(&mutex);
  
  // Test recursive mutex
  if (mtx_init(&mutex, mtx_recursive) != 0) {
    printLog(ERR, "mtx_init failed for recursive mutex\n");
    return false;
  }
  
  // Lock multiple times
  if (mtx_lock(&mutex) != 0 || mtx_lock(&mutex) != 0) {
    printLog(ERR, "Recursive mutex lock failed\n");
    return false;
  }
  
  // Unlock multiple times
  if (mtx_unlock(&mutex) != 0 || mtx_unlock(&mutex) != 0) {
    printLog(ERR, "Recursive mutex unlock failed\n");
    return false;
  }
  
  mtx_destroy(&mutex);
  
  // Test timed mutex
  if (mtx_init(&mutex, mtx_timed) != 0) {
    printLog(ERR, "mtx_init failed for timed mutex\n");
    return false;
  }
  
  mtx_destroy(&mutex);
  
  // Test NULL parameters
  mtx_init(NULL, mtx_plain);
  mtx_lock(NULL);
  mtx_unlock(NULL);
  mtx_trylock(NULL);
  mtx_timedlock(NULL, &timeout);
  mtx_timedlock(&mutex, NULL);
  mtx_destroy(NULL);
  
  printLog(DEBUG, "Mutex tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Test condition variable functionality
///
/// @return true if test passes, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testCondition(void) {
  printLog(DEBUG, "Testing condition variable functionality\n");
  
  cnd_t condition;
  mtx_t mutex;
  
  // Initialize mutex and condition
  if (mtx_init(&mutex, mtx_plain) != 0) {
    printLog(ERR, "mtx_init failed in condition test\n");
    return false;
  }
  
  if (cnd_init(&condition) != 0) {
    printLog(ERR, "cnd_init failed\n");
    return false;
  }
  
  // Test signal (no waiters)
  if (cnd_signal(&condition) != 0) {
    printLog(ERR, "cnd_signal failed\n");
    return false;
  }
  
  // Test broadcast (no waiters)
  if (cnd_broadcast(&condition) != 0) {
    printLog(ERR, "cnd_broadcast failed\n");
    return false;
  }
  
  // Test timed wait with immediate timeout
  struct timespec timeout;
  timespec_get(&timeout, TIME_UTC);
  // Don't add time so it times out immediately
  
  mtx_lock(&mutex);
  int result = cnd_timedwait(&condition, &mutex, &timeout);
  mtx_unlock(&mutex);
  
  if (result != thrd_timedout) {
    printLog(ERR, "cnd_timedwait should have timed out\n");
    return false;
  }
  
  cnd_destroy(&condition);
  mtx_destroy(&mutex);
  
  // Test NULL parameters
  cnd_init(NULL);
  cnd_signal(NULL);
  cnd_broadcast(NULL);
  cnd_wait(NULL, &mutex);
  cnd_wait(&condition, NULL);
  cnd_timedwait(NULL, &mutex, &timeout);
  cnd_timedwait(&condition, NULL, &timeout);
  cnd_timedwait(&condition, &mutex, NULL);
  cnd_destroy(NULL);
  
  printLog(DEBUG, "Condition variable tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Test thread functionality
///
/// @return true if test passes, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testThread(void) {
  printLog(DEBUG, "Testing thread functionality\n");
  
  thrd_t thread;
  int testValue = 42;
  int result;
  
  // Test thread creation and execution
  threadTestValue = 0;
  if (thrd_create(&thread, testThreadFunction, &testValue) != thrd_success) {
    printLog(ERR, "thrd_create failed\n");
    return false;
  }
  
  // Test thread join
  if (thrd_join(thread, &result) != thrd_success) {
    printLog(ERR, "thrd_join failed\n");
    return false;
  }
  
  if (result != thrd_success) {
    printLog(ERR, "Thread returned error code\n");
    return false;
  }
  
  if (threadTestValue != 84) {
    printLog(ERR, "Thread did not execute correctly\n");
    return false;
  }
  
  // Test thread detach
  if (thrd_create(&thread, testThreadFunction, &testValue) != thrd_success) {
    printLog(ERR, "thrd_create failed for detach test\n");
    return false;
  }
  
  if (thrd_detach(thread) != thrd_success) {
    printLog(ERR, "thrd_detach failed\n");
    return false;
  }
  
  // Test current thread
  thrd_t currentThread = thrd_current();
  
  // Test thread equality
  if (!thrd_equal(currentThread, currentThread)) {
    printLog(ERR, "thrd_equal failed on same thread\n");
    return false;
  }
  
  // Test thread sleep
  struct timespec sleepTime = {0, 100000000}; // 100ms
  struct timespec remaining;
  if (thrd_sleep(&sleepTime, &remaining) != 0) {
    printLog(ERR, "thrd_sleep failed\n");
    return false;
  }
  
  // Test thread yield
  thrd_yield();
  
  // Test thread termination
  printLog(DEBUG, "Launching terminationTestThreadFunction.\n");
  if (thrd_create(&thread, terminationTestThreadFunction, NULL) 
      != thrd_success) {
    printLog(ERR, "thrd_create failed for termination test\n");
    return false;
  }
  printLog(DEBUG, "terminationTestThreadFunction launched successfully.\n");
  
  printLog(DEBUG,
    "Sleeping for 1 second to give terminationTestThreadFunction time to start.\n");
  sleep(1);
  
  printLog(DEBUG, "Terminating terminationTestThreadFunction.\n");
  if (thrd_terminate(thread) != thrd_success) {
    printLog(ERR, "thrd_terminate failed\n");
    return false;
  }
  printLog(DEBUG, "terminationTestThreadFunction terminated.\n");
  
  int terminateStatus = 0;
  if (thrd_join(thread, &terminateStatus) != thrd_success) {
    printLog(ERR, "thrd_join on termianted thread failed.\n");
    return false;
  } else if (terminateStatus != thrd_terminated) {
    printLog(ERR, "Expected terminateStatus to be %d, got %d.\n",
      thrd_terminated, terminateStatus);
    return false;
  }
  printLog(DEBUG, "terminateStatus is thrd_terminated as expected.\n");
  
  // Test NULL parameters
  printLog(DEBUG, "Testing thrd_create with NULL thrd parameter.\n");
  thrd_create(NULL, testThreadFunction, &testValue);
  printLog(DEBUG, "Testing thrd_create with NULL func parameter.\n");
  thrd_create(&thread, NULL, &testValue);
  printLog(DEBUG, "Testing thrd_sleep with NULL ts parameter.\n");
  thrd_sleep(NULL, &remaining);
  printLog(DEBUG, "Testing thrd_sleep with NULL rem parameter.\n");
  thrd_sleep(&sleepTime, NULL);
  
  printLog(DEBUG, "Thread tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Test thread-specific storage functionality
///
/// @return true if test passes, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testThreadSpecificStorage(void) {
  printLog(DEBUG, "Testing thread-specific storage functionality\n");
  
  tss_t key;
  
  // Test TSS creation
  if (tss_create(&key, tssDestructor) != thrd_success) {
    printLog(ERR, "tss_create failed\n");
    return false;
  }
  
  // Test initial get (should be NULL)
  if (tss_get(key) != NULL) {
    printLog(ERR, "tss_get should return NULL initially\n");
    return false;
  }
  
  // Test set and get
  char* testData = (char*) malloc(10);
  if (testData == NULL) {
    printLog(ERR, "malloc failed in TSS test\n");
    return false;
  }
  strcpy(testData, "test");
  
  if (tss_set(key, testData) != thrd_success) {
    printLog(ERR, "tss_set failed\n");
    free(testData);
    return false;
  }
  
  char* retrievedData = (char*) tss_get(key);
  if (retrievedData != testData) {
    printLog(ERR, "tss_get returned wrong value\n");
    free(testData);
    return false;
  }
  
  if (strcmp(retrievedData, "test") != 0) {
    printLog(ERR, "TSS data corrupted\n");
    free(testData);
    return false;
  }
  
  // Test setting to NULL
  if (tss_set(key, NULL) != thrd_success) {
    printLog(ERR, "tss_set to NULL failed\n");
    free(testData);
    return false;
  }
  
  if (tss_get(key) != NULL) {
    printLog(ERR, "tss_get should return NULL after setting to NULL\n");
    free(testData);
    return false;
  }
  
  free(testData);
  tss_delete(key);
  
  // Test TSS creation without destructor
  if (tss_create(&key, NULL) != thrd_success) {
    printLog(ERR, "tss_create without destructor failed\n");
    return false;
  }
  
  tss_delete(key);
  
  // Test NULL parameters
  tss_create(NULL, tssDestructor);
  tss_get(key); // Invalid key after delete
  tss_set(key, NULL); // Invalid key after delete
  tss_delete(key); // Invalid key after delete
  
  printLog(DEBUG, "Thread-specific storage tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Test timespec_get functionality
///
/// @return true if test passes, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool testTimespecGet(void) {
  printLog(DEBUG, "Testing timespec_get functionality\n");
  
  struct timespec spec;
  
  // Test normal timespec_get
  if (timespec_get(&spec, TIME_UTC) != TIME_UTC) {
    printLog(ERR, "timespec_get failed\n");
    return false;
  }
  
  if (spec.tv_sec <= 0) {
    printLog(ERR, "timespec_get returned invalid time\n");
    return false;
  }
  
#ifdef _WIN32
  // Test NULL parameter
  if (timespec_get(NULL, TIME_UTC) != 0) {
    printLog(ERR,
      "timespec_get with NULL timespec parameter did not return 0.\n");
    return false;
  }
  
  // Test invalid base
  if (timespec_get(&spec, 999) != 0) {
    printLog(ERR,
      "timespec_get with invalid base parameter parameter did not return 0.\n");
    return false;
  }
#endif // _WIN32
  
  printLog(DEBUG, "timespec_get tests passed\n");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Main unit test function for PosixCThreads
///
/// @return true if all tests pass, false if any test fails
///////////////////////////////////////////////////////////////////////////////
bool cThreadsUnitTest(void) {
  printLog(DEBUG, "Starting PosixCThreads unit test\n");
  
  if (!testCallOnce()) {
    printLog(ERR, "call_once test failed\n");
    return false;
  }
  
  if (!testMutex()) {
    printLog(ERR, "Mutex test failed\n");
    return false;
  }
  
  if (!testCondition()) {
    printLog(ERR, "Condition variable test failed\n");
    return false;
  }
  
  if (!testThread()) {
    printLog(ERR, "Thread test failed\n");
    return false;
  }
  
  if (!testThreadSpecificStorage()) {
    printLog(ERR, "Thread-specific storage test failed\n");
    return false;
  }
  
  if (!testTimespecGet()) {
    printLog(ERR, "timespec_get test failed\n");
    return false;
  }
  
  printLog(DEBUG, "All PosixCThreads unit tests passed\n");
  return true;
}
