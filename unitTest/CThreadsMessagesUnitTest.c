///////////////////////////////////////////////////////////////////////////////
///
/// @file              CThreadsMessagesUnitTest.c
///
/// @brief             Unit tests for CThreadsMessages functionality.
///
///////////////////////////////////////////////////////////////////////////////

#include "CThreads.h"
#include "CThreadsMessages.h"
#include "LoggingLib.h"
#include "Messages.h"
#include "MessagesUnitTest.h"

// Test message types
#define TEST_MSG_TYPE_SIMPLE    1
#define TEST_MSG_TYPE_COMPLEX   2
#define TEST_MSG_TYPE_RESPONSE  3
#define TEST_MSG_TYPE_TIMEOUT   4

// Global variables for thread communication
static thrd_t producerThread;
static thrd_t consumerThread;
static bool testThreadsRunning = false;

///
/// @brief Helper function to create a timeout timespec.
///
/// @param milliseconds The number of milliseconds for the timeout.
///
/// @return A timespec structure with the specified timeout.
///
static struct timespec createTimeout(int milliseconds) {
  struct timespec ts;
  timespec_get(&ts, TIME_UTC);
  ts.tv_nsec += milliseconds * 1000000;
  if (ts.tv_nsec >= 1000000000) {
    ts.tv_sec += ts.tv_nsec / 1000000000;
    ts.tv_nsec %= 1000000000;
  }
  return ts;
}

///
/// @brief Helper function to compare test data.
///
/// @param data1 First TestData structure to compare.
/// @param data2 Second TestData structure to compare.
///
/// @return true if the structures are equal, false otherwise.
///
static bool compareTestData(const TestData *data1, const TestData *data2) {
  if (data1 == NULL || data2 == NULL) {
    return (data1 == data2);
  }
  return (data1->value == data2->value && 
          strcmp(data1->text, data2->text) == 0);
}

///
/// @brief Producer thread function for testing message queue operations.
///
/// @param arg Unused argument.
///
/// @return Thread return value (always 0).
///
int producerThreadFunction(void *arg) {
  (void)arg; // Suppress unused parameter warning
  
  printLog(DEBUG, "Producer thread started");
  
  for (int ii = 0; ii < 5 && testThreadsRunning; ii++) {
    msg_t *message = msg_create(MSG_THRD_SAFE);
    if (message == NULL) {
      printLog(DEBUG, "Failed to create message in producer thread");
      continue;
    }
    
    TestData *testData = (TestData *) malloc(sizeof(TestData));
    if (testData == NULL) {
      msg_destroy(message);
      printLog(DEBUG, "Failed to allocate test data in producer thread");
      continue;
    }
    
    testData->value = ii * 10;
    snprintf(testData->text, sizeof(testData->text), "Message %d", ii);
    
    int result = msg_init(message, MSG_THRD_SAFE, TEST_MSG_TYPE_SIMPLE,
                         testData, sizeof(TestData), false);
    if (result != msg_success) {
      free(testData);
      msg_destroy(message);
      printLog(DEBUG, "Failed to initialize message in producer thread");
      continue;
    }
    
    result = thrd_msg_q_push(thrd_current(), message);
    if (result != msg_success) {
      free(testData);
      msg_destroy(message);
      printLog(DEBUG, "Failed to push message in producer thread");
      continue;
    }
    
    printLog(DEBUG, "Producer sent message %d", ii);
    struct timespec sleepTime = {.tv_sec = 0, .tv_nsec = 100000000}; // 100ms
    thrd_sleep(&sleepTime, NULL);
  }
  
  printLog(DEBUG, "Producer thread finished");
  return 0;
}

///
/// @brief Consumer thread function for testing message queue operations.
///
/// @param arg Unused argument.
///
/// @return Thread return value (always 0).
///
int consumerThreadFunction(void *arg) {
  (void)arg; // Suppress unused parameter warning
  
  printLog(DEBUG, "Consumer thread started");
  
  for (int ii = 0; ii < 5 && testThreadsRunning; ii++) {
    struct timespec timeout = createTimeout(1000); // 1 second timeout
    msg_t *message = thrd_msg_q_wait(&timeout);
    
    if (message == NULL) {
      printLog(DEBUG, "Consumer thread timed out waiting for message %d", ii);
      continue;
    }
    
    if (msg_type(message) != TEST_MSG_TYPE_SIMPLE) {
      printLog(DEBUG, "Consumer received unexpected message type: %d", 
               msg_type(message));
      msg_release(message);
      continue;
    }
    
    TestData *receivedData = (TestData *) msg_data(message);
    if (receivedData != NULL) {
      printLog(DEBUG, "Consumer received: value=%d, text='%s'",
               receivedData->value, receivedData->text);
      free(receivedData);
    }
    
    msg_set_done(message);
    msg_release(message);
    printLog(DEBUG, "Consumer processed message %d", ii);
  }
  
  printLog(DEBUG, "Consumer thread finished");
  return 0;
}

///
/// @brief Test basic message creation and destruction.
///
/// @return true if test passes, false otherwise.
///
bool testMessageCreation(void) {
  printLog(DEBUG, "Testing message creation and destruction...");
  
  // Test message creation
  msg_t *message = msg_create(MSG_THRD_SAFE);
  if (message == NULL) {
    printLog(ERR, "Failed to create message");
    return false;
  }
  
  // Test message initialization
  TestData testData = {42, "Hello World"};
  int result = msg_init(message, MSG_THRD_SAFE, TEST_MSG_TYPE_SIMPLE,
                       &testData, sizeof(TestData), false);
  if (result != msg_success) {
    printLog(ERR, "Failed to initialize message");
    msg_destroy(message);
    return false;
  }
  
  // Verify message properties
  if (msg_type(message) != TEST_MSG_TYPE_SIMPLE) {
    printLog(ERR, "Message type mismatch: expected %d, got %d",
             TEST_MSG_TYPE_SIMPLE, msg_type(message));
    msg_destroy(message);
    return false;
  }
  
  if (msg_size(message) != sizeof(TestData)) {
    printLog(ERR, "Message size mismatch: expected %zu, got %zu",
             sizeof(TestData), msg_size(message));
    msg_destroy(message);
    return false;
  }
  
  TestData *retrievedData = (TestData *) msg_data(message);
  if (!compareTestData(&testData, retrievedData)) {
    printLog(ERR, "Message data mismatch");
    msg_destroy(message);
    return false;
  }
  
  // Test message destruction
  msg_t *destroyResult = msg_destroy(message);
  if (destroyResult != NULL) {
    printLog(ERR, "Message destruction did not return NULL");
    return false;
  }
  
  printLog(DEBUG, "Message creation and destruction test passed");
  return true;
}

///
/// @brief Test message queue operations.
///
/// @return true if test passes, false otherwise.
///
bool testMessageQueue(void) {
  printLog(DEBUG, "Testing message queue operations...");
  
  // Create a message queue
  ZEROINIT(msg_q_t queue);
  
  if (msg_q_create(&queue, MSG_THRD_SAFE) != &queue) {
    printLog(ERR, "Failed to create message queue");
    return false;
  }
  
  // Test empty queue operations
  msg_t *peekedMessage = msg_q_peek(&queue);
  if (peekedMessage != NULL) {
    printLog(ERR, "Peek on empty queue should return NULL");
    msg_q_destroy(&queue);
    return false;
  }
  
  msg_t *poppedMessage = msg_q_pop(&queue);
  if (poppedMessage != NULL) {
    printLog(ERR, "Pop on empty queue should return NULL");
    msg_q_destroy(&queue);
    return false;
  }
  
  // Create and push messages
  const int numMessages = 3;
  msg_t *messages[numMessages];
  TestData testData[numMessages];
  
  for (int ii = 0; ii < numMessages; ii++) {
    messages[ii] = msg_create(MSG_THRD_SAFE);
    if (messages[ii] == NULL) {
      printLog(ERR, "Failed to create message %d", ii);
      // Clean up previously created messages
      for (int jj = 0; jj < ii; jj++) {
        msg_destroy(messages[jj]);
      }
      msg_q_destroy(&queue);
      return false;
    }
    
    testData[ii].value = ii * 100;
    snprintf(testData[ii].text, sizeof(testData[ii].text), "Queue Test %d", ii);
    
    int result = msg_init(messages[ii], MSG_THRD_SAFE, TEST_MSG_TYPE_COMPLEX,
                         &testData[ii], sizeof(TestData), false);
    if (result != msg_success) {
      printLog(ERR, "Failed to initialize message %d", ii);
      for (int jj = 0; jj <= ii; jj++) {
        msg_destroy(messages[jj]);
      }
      msg_q_destroy(&queue);
      return false;
    }
    
    result = msg_q_push(&queue, NULL, messages[ii]);
    if (result != msg_success) {
      printLog(ERR, "Failed to push message %d", ii);
      for (int jj = 0; jj <= ii; jj++) {
        msg_destroy(messages[jj]);
      }
      msg_q_destroy(&queue);
      return false;
    }
  }
  
  // Test peek operation
  msg_t *firstMessage = msg_q_peek(&queue);
  if (firstMessage == NULL) {
    printLog(ERR, "Peek should return first message");
    msg_q_destroy(&queue);
    return false;
  }
  
  if (msg_type(firstMessage) != TEST_MSG_TYPE_COMPLEX) {
    printLog(ERR, "Peeked message has wrong type");
    msg_q_destroy(&queue);
    return false;
  }
  
  // Test pop operations
  for (int ii = 0; ii < numMessages; ii++) {
    msg_t *poppedMsg = msg_q_pop(&queue);
    if (poppedMsg == NULL) {
      printLog(ERR, "Failed to pop message %d", ii);
      msg_q_destroy(&queue);
      return false;
    }
    
    if (msg_type(poppedMsg) != TEST_MSG_TYPE_COMPLEX) {
      printLog(ERR, "Popped message %d has wrong type", ii);
      msg_release(poppedMsg);
      msg_q_destroy(&queue);
      return false;
    }
    
    TestData *poppedData = (TestData *) msg_data(poppedMsg);
    if (!compareTestData(&testData[ii], poppedData)) {
      printLog(ERR, "Popped message %d has wrong data", ii);
      msg_release(poppedMsg);
      msg_q_destroy(&queue);
      return false;
    }
    
    msg_release(poppedMsg);
  }
  
  // Verify queue is empty again
  msg_t *emptyCheck = msg_q_pop(&queue);
  if (emptyCheck != NULL) {
    printLog(ERR, "Queue should be empty after popping all messages");
    msg_release(emptyCheck);
    msg_q_destroy(&queue);
    return false;
  }
  
  // Clean up
  int result = msg_q_destroy(&queue);
  if (result != msg_success) {
    printLog(ERR, "Failed to destroy message queue");
    return false;
  }
  
  printLog(DEBUG, "Message queue operations test passed");
  return true;
}

///
/// @brief Test message type filtering operations.
///
/// @return true if test passes, false otherwise.
///
bool testMessageTypeFiltering(void) {
  printLog(DEBUG, "Testing message type filtering...");
  
  msg_q_t *queue = msg_q_create(NULL, MSG_THRD_SAFE);
  if (queue == NULL) {
    printLog(ERR, "Failed to create message queue for type filtering test");
    return false;
  }
  
  // Create messages with different types
  const int messageTypes[] = {TEST_MSG_TYPE_SIMPLE, TEST_MSG_TYPE_COMPLEX, 
                             TEST_MSG_TYPE_SIMPLE, TEST_MSG_TYPE_RESPONSE};
  const int numMessages = sizeof(messageTypes) / sizeof(messageTypes[0]);
  
  for (int ii = 0; ii < numMessages; ii++) {
    msg_t *message = msg_create(MSG_THRD_SAFE);
    if (message == NULL) {
      printLog(ERR, "Failed to create message %d for type filtering", ii);
      msg_q_destroy(queue);
      return false;
    }
    
    TestData *testData = (TestData*) malloc(sizeof(TestData));
    testData->value = ii;
    snprintf(testData->text, sizeof(testData->text), "Type test %d", ii);
    
    int result = msg_init(message, MSG_THRD_SAFE, messageTypes[ii],
                         testData, sizeof(TestData), false);
    if (result != msg_success) {
      printLog(ERR, "Failed to initialize message %d for type filtering", ii);
      msg_destroy(message);
      msg_q_destroy(queue);
      return false;
    }
    
    result = msg_q_push(queue, NULL, message);
    if (result != msg_success) {
      printLog(ERR, "Failed to push message %d for type filtering", ii);
      msg_destroy(message);
      msg_q_destroy(queue);
      return false;
    }
  }
  
  // Test pop by type - should get first SIMPLE message
  msg_t *simpleMessage = msg_q_pop_type(queue, TEST_MSG_TYPE_SIMPLE);
  if (simpleMessage == NULL) {
    printLog(ERR, "Failed to pop SIMPLE type message");
    msg_q_destroy(queue);
    return false;
  }
  
  if (msg_type(simpleMessage) != TEST_MSG_TYPE_SIMPLE) {
    printLog(ERR, "Popped message is not SIMPLE type");
    msg_release(simpleMessage);
    msg_q_destroy(queue);
    return false;
  }
  
  TestData *simpleData = (TestData *) msg_data(simpleMessage);
  if (simpleData->value != 0) { // First SIMPLE message has value 0
    printLog(ERR, "Popped SIMPLE message has wrong data");
    msg_release(simpleMessage);
    msg_q_destroy(queue);
    return false;
  }
  free(simpleData);
  
  msg_release(simpleMessage);
  
  // Test pop by type - should get COMPLEX message
  msg_t *complexMessage = msg_q_pop_type(queue, TEST_MSG_TYPE_COMPLEX);
  if (complexMessage == NULL) {
    printLog(ERR, "Failed to pop COMPLEX type message");
    msg_q_destroy(queue);
    return false;
  }
  
  if (msg_type(complexMessage) != TEST_MSG_TYPE_COMPLEX) {
    printLog(ERR, "Popped message is not COMPLEX type");
    msg_release(complexMessage);
    msg_q_destroy(queue);
    return false;
  }
  free(msg_data(complexMessage));
  
  msg_release(complexMessage);
  
  // Clean up remaining messages
  msg_t *remainingMessage;
  while ((remainingMessage = msg_q_pop(queue)) != NULL) {
    free(msg_data(remainingMessage));
    msg_release(remainingMessage);
  }
  
  msg_q_destroy(queue);
  printLog(DEBUG, "Message type filtering test passed");
  return true;
}

///
/// @brief Test timeout operations.
///
/// @return true if test passes, false otherwise.
///
bool testTimeoutOperations(void) {
  printLog(DEBUG, "Testing timeout operations...");
  
  msg_q_t *queue = msg_q_create(NULL, MSG_THRD_SAFE);
  if (queue == NULL) {
    printLog(ERR, "Failed to create message queue for timeout test");
    return false;
  }
  
  // Test timeout on empty queue
  struct timespec shortTimeout = createTimeout(100); // 100ms
  msg_t *timeoutMessage = msg_q_wait(queue, &shortTimeout);
  if (timeoutMessage != NULL) {
    printLog(ERR, "Wait on empty queue should timeout and return NULL");
    msg_release(timeoutMessage);
    msg_q_destroy(queue);
    return false;
  }
  
  // Test timeout waiting for specific type on empty queue
  timeoutMessage = msg_q_wait_for_type(queue, TEST_MSG_TYPE_TIMEOUT, 
                                      &shortTimeout);
  if (timeoutMessage != NULL) {
    printLog(ERR, 
             "Wait for type on empty queue should timeout and return NULL");
    msg_release(timeoutMessage);
    msg_q_destroy(queue);
    return false;
  }
  
  // Add a message and test successful wait
  msg_t *message = msg_create(MSG_THRD_SAFE);
  if (message == NULL) {
    printLog(ERR, "Failed to create message for timeout test");
    msg_q_destroy(queue);
    return false;
  }
  
  TestData testData = {999, "Timeout Test"};
  int result = msg_init(message, MSG_THRD_SAFE, TEST_MSG_TYPE_TIMEOUT,
                       &testData, sizeof(TestData), false);
  if (result != msg_success) {
    printLog(ERR, "Failed to initialize message for timeout test");
    msg_destroy(message);
    msg_q_destroy(queue);
    return false;
  }
  
  result = msg_q_push(queue, NULL, message);
  if (result != msg_success) {
    printLog(ERR, "Failed to push message for timeout test");
    msg_destroy(message);
    msg_q_destroy(queue);
    return false;
  }
  
  // Test successful wait with timeout
  struct timespec longTimeout = createTimeout(1000); // 1 second
  msg_t *waitedMessage = msg_q_wait(queue, &longTimeout);
  if (waitedMessage == NULL) {
    printLog(ERR, "Wait should succeed when message is available");
    msg_q_destroy(queue);
    return false;
  }
  
  if (msg_type(waitedMessage) != TEST_MSG_TYPE_TIMEOUT) {
    printLog(ERR, "Waited message has wrong type");
    msg_release(waitedMessage);
    msg_q_destroy(queue);
    return false;
  }
  
  msg_release(waitedMessage);
  msg_q_destroy(queue);
  printLog(DEBUG, "Timeout operations test passed");
  return true;
}

///
/// @brief Test thread-specific message operations.
///
/// @return true if test passes, false otherwise.
///
bool testThreadMessageOperations(void) {
  printLog(DEBUG, "Testing thread-specific message operations...");
  
  testThreadsRunning = true;
  
  // Create producer and consumer threads
  int producerResult = thrd_create(&producerThread, producerThreadFunction, 
                                  NULL);
  if (producerResult != thrd_success) {
    printLog(ERR, "Failed to create producer thread");
    testThreadsRunning = false;
    return false;
  }
  
  int consumerResult = thrd_create(&consumerThread, consumerThreadFunction, 
                                  NULL);
  if (consumerResult != thrd_success) {
    printLog(ERR, "Failed to create consumer thread");
    testThreadsRunning = false;
    thrd_join(producerThread, NULL);
    return false;
  }
  
  // Let threads run for a while
  struct timespec runTime = {.tv_sec = 2, .tv_nsec = 0}; // 2 seconds
  thrd_sleep(&runTime, NULL);
  
  // Signal threads to stop
  testThreadsRunning = false;
  
  // Wait for threads to complete
  int producerExitCode, consumerExitCode;
  thrd_join(producerThread, &producerExitCode);
  thrd_join(consumerThread, &consumerExitCode);
  
  if (producerExitCode != 0) {
    printLog(ERR, "Producer thread exited with error code: %d", 
             producerExitCode);
    return false;
  }
  
  if (consumerExitCode != 0) {
    printLog(ERR, "Consumer thread exited with error code: %d", 
             consumerExitCode);
    return false;
  }
  
  printLog(DEBUG, "Thread-specific message operations test passed");
  return true;
}

///
/// @brief Test message waiting and synchronization.
///
/// @return true if test passes, false otherwise.
///
bool testMessageWaitingAndSync(void) {
  printLog(DEBUG, "Testing message waiting and synchronization...");
  
  // Create a message with waiting flag
  msg_t *message = msg_create(MSG_THRD_SAFE);
  if (message == NULL) {
    printLog(ERR, "Failed to create message for waiting test");
    return false;
  }
  
  TestData testData = {123, "Waiting Test"};
  int result = msg_init(message, MSG_THRD_SAFE, TEST_MSG_TYPE_RESPONSE,
                       &testData, sizeof(TestData), true); // waiting = true
  if (result != msg_success) {
    printLog(ERR, "Failed to initialize waiting message");
    msg_destroy(message);
    return false;
  }
  
  // Verify waiting flag is set
  if (!msg_waiting(message)) {
    printLog(ERR, "Message waiting flag should be true");
    msg_destroy(message);
    return false;
  }
  
  // Verify done flag is initially false
  if (msg_done(message)) {
    printLog(ERR, "Message done flag should initially be false");
    msg_destroy(message);
    return false;
  }
  
  // Set message as done
  result = msg_set_done(message);
  if (result != msg_success) {
    printLog(ERR, "Failed to set message as done");
    msg_destroy(message);
    return false;
  }
  
  // Verify done flag is now true
  if (!msg_done(message)) {
    printLog(ERR, "Message done flag should be true after setting");
    msg_destroy(message);
    return false;
  }
  
  // Test waiting for done with short timeout (should succeed immediately)
  struct timespec shortTimeout = createTimeout(100);
  result = msg_wait_for_done(message, &shortTimeout);
  if (result != msg_success) {
    printLog(ERR, "Wait for done should succeed when message is done");
    msg_destroy(message);
    return false;
  }
  
  msg_destroy(message);
  printLog(DEBUG, "Message waiting and synchronization test passed");
  return true;
}

///
/// @brief Test NULL parameter handling for message functions.
///
/// @return true if test passes, false otherwise.
///
bool testCThreadsMessagesNullParameterHandling(void) {
  printLog(DEBUG, "Testing NULL parameter handling...");
  
  // Test msg_destroy with NULL
  msg_t *nullResult = msg_destroy(NULL);
  if (nullResult != NULL) {
    printLog(ERR, "msg_destroy(NULL) should return NULL");
    return false;
  }
  
  // Test msg_init with NULL message
  TestData testData = {42, "Test"};
  int result = msg_init(NULL, MSG_THRD_SAFE, TEST_MSG_TYPE_SIMPLE,
                       &testData, sizeof(TestData), false);
  if (result == msg_success) {
    printLog(ERR, "msg_init with NULL message should fail");
    return false;
  }
  
  // Test msg_init with NULL data (should be allowed)
  msg_t *message = msg_create(MSG_THRD_SAFE);
  if (message == NULL) {
    printLog(ERR, "Failed to create message for NULL data test");
    return false;
  }
  
  result = msg_init(message, MSG_THRD_SAFE, TEST_MSG_TYPE_SIMPLE,
                   NULL, 0, false);
  if (result != msg_success) {
    printLog(ERR, "msg_init with NULL data should succeed");
    msg_destroy(message);
    return false;
  }
  
  // Verify NULL data is handled correctly
  void *retrievedData = msg_data(message);
  if (retrievedData != NULL) {
    printLog(ERR, "Message with NULL data should return NULL from msg_data");
    msg_destroy(message);
    return false;
  }
  
  msg_destroy(message);
  
  // Test msg_release with NULL
  result = msg_release(NULL);
  if (result != msg_success) {
    printLog(ERR, "msg_release(NULL) should succeed");
    return false;
  }
  
  // Test msg_set_done with NULL
  result = msg_set_done(NULL);
  if (result == msg_success) {
    printLog(ERR, "msg_set_done(NULL) should fail");
    return false;
  }
  
  // Test msg_wait_for_done with NULL message
  struct timespec timeout = createTimeout(100);
  result = msg_wait_for_done(NULL, &timeout);
  if (result == msg_success) {
    printLog(ERR, "msg_wait_for_done with NULL message should fail");
    return false;
  }
  
  // Test msg_wait_for_done with NULL timeout (should be allowed)
  message = msg_create(MSG_THRD_SAFE);
  if (message == NULL) {
    printLog(ERR, "Failed to create message for NULL timeout test");
    return false;
  }
  
  result = msg_init(message, MSG_THRD_SAFE, TEST_MSG_TYPE_SIMPLE,
                   &testData, sizeof(TestData), true);
  if (result != msg_success) {
    printLog(ERR, "Failed to initialize message for NULL timeout test");
    msg_destroy(message);
    return false;
  }
  
  // Set message as done first
  msg_set_done(message);
  
  result = msg_wait_for_done(message, NULL);
  if (result != msg_success) {
    printLog(ERR, "msg_wait_for_done with NULL timeout should succeed when "
             "message is already done");
    msg_destroy(message);
    return false;
  }
  
  msg_destroy(message);
  
  // Test msg_wait_for_reply with NULL
  msg_t *replyResult = msg_wait_for_reply(NULL, false, &timeout);
  if (replyResult != NULL) {
    printLog(ERR, "msg_wait_for_reply with NULL message should return NULL");
    msg_release(replyResult);
    return false;
  }
  
  // Test msg_wait_for_reply_with_type with NULL
  replyResult = msg_wait_for_reply_with_type(NULL, false, 
                                            TEST_MSG_TYPE_SIMPLE, &timeout);
  if (replyResult != NULL) {
    printLog(ERR, 
             "msg_wait_for_reply_with_type with NULL message should return NULL");
    msg_release(replyResult);
    return false;
  }
  
  printLog(DEBUG, "NULL parameter handling test passed");
  return true;
}

///
/// @brief Test NULL parameter handling for message queue functions.
///
/// @return true if test passes, false otherwise.
///
bool testNullQueueParameterHandling(void) {
  printLog(DEBUG, "Testing NULL parameter handling for message queues...");
  
  // Test msg_q_destroy with NULL
  int result = msg_q_destroy(NULL);
  if (result != msg_success) {
    printLog(ERR, "msg_q_destroy(NULL) should succeed");
    return false;
  }
  
  // Test msg_q_peek with NULL
  msg_t *peekResult = msg_q_peek(NULL);
  if (peekResult != NULL) {
    printLog(ERR, "msg_q_peek(NULL) should return NULL");
    msg_release(peekResult);
    return false;
  }
  
  // Test msg_q_pop with NULL
  msg_t *popResult = msg_q_pop(NULL);
  if (popResult != NULL) {
    printLog(ERR, "msg_q_pop(NULL) should return NULL");
    msg_release(popResult);
    return false;
  }
  
  // Test msg_q_pop_type with NULL
  popResult = msg_q_pop_type(NULL, TEST_MSG_TYPE_SIMPLE);
  if (popResult != NULL) {
    printLog(ERR, "msg_q_pop_type(NULL, type) should return NULL");
    msg_release(popResult);
    return false;
  }
  
  // Test msg_q_wait with NULL queue
  struct timespec timeout = createTimeout(100);
  msg_t *waitResult = msg_q_wait(NULL, &timeout);
  if (waitResult != NULL) {
    printLog(ERR, "msg_q_wait(NULL, timeout) should return NULL");
    msg_release(waitResult);
    return false;
  }
  
  // Test msg_q_wait with NULL timeout (should be allowed for some implementations)
  msg_q_t *queue = msg_q_create(NULL, MSG_THRD_SAFE);
  if (queue == NULL) {
    printLog(ERR, "Failed to create queue for NULL timeout test");
    return false;
  }
  
  // This should timeout immediately or return NULL since queue is empty
  timeout = createTimeout(0);
  waitResult = msg_q_wait(queue, &timeout);
  if (waitResult != NULL) {
    printLog(ERR, "msg_q_wait on empty queue with NULL timeout should return NULL");
    msg_release(waitResult);
    msg_q_destroy(queue);
    return false;
  }
  
  // Test msg_q_wait_for_type with NULL queue
  waitResult = msg_q_wait_for_type(NULL, TEST_MSG_TYPE_SIMPLE, &timeout);
  if (waitResult != NULL) {
    printLog(ERR, "msg_q_wait_for_type(NULL, type, timeout) should return NULL");
    msg_release(waitResult);
    msg_q_destroy(queue);
    return false;
  }
  
  // Test msg_q_wait_for_type with NULL timeout
  waitResult = msg_q_wait_for_type(queue, TEST_MSG_TYPE_SIMPLE, &timeout);
  if (waitResult != NULL) {
    printLog(ERR, 
             "msg_q_wait_for_type on empty queue with NULL timeout should return NULL");
    msg_release(waitResult);
    msg_q_destroy(queue);
    return false;
  }
  
  // Test msg_q_push with NULL queue
  msg_t *message = msg_create(MSG_THRD_SAFE);
  if (message == NULL) {
    printLog(ERR, "Failed to create message for push test");
    msg_q_destroy(queue);
    return false;
  }
  
  TestData testData = {42, "Push Test"};
  result = msg_init(message, MSG_THRD_SAFE, TEST_MSG_TYPE_SIMPLE,
                   &testData, sizeof(TestData), false);
  if (result != msg_success) {
    printLog(ERR, "Failed to initialize message for push test");
    msg_destroy(message);
    msg_q_destroy(queue);
    return false;
  }
  
  result = msg_q_push(NULL, NULL, message);
  if (result == msg_success) {
    printLog(ERR, "msg_q_push(NULL, NULL, message) should fail");
    msg_destroy(message);
    msg_q_destroy(queue);
    return false;
  }
  
  // Test msg_q_push with NULL message
  result = msg_q_push(queue, NULL, NULL);
  if (result == msg_success) {
    printLog(ERR, "msg_q_push(queue, NULL, NULL) should fail");
    msg_destroy(message);
    msg_q_destroy(queue);
    return false;
  }
  
  // Test valid push to clean up message
  result = msg_q_push(queue, NULL, message);
  if (result != msg_success) {
    printLog(ERR, "Valid msg_q_push should succeed");
    msg_destroy(message);
    msg_q_destroy(queue);
    return false;
  }
  
  // Clean up
  msg_t *cleanupMessage = msg_q_pop(queue);
  if (cleanupMessage != NULL) {
    msg_release(cleanupMessage);
  }
  
  msg_q_destroy(queue);
  printLog(DEBUG, "NULL parameter handling for message queues test passed");
  return true;
}

///
/// @brief Test NULL parameter handling for thread message functions.
///
/// @return true if test passes, false otherwise.
///
bool testNullThreadParameterHandling(void) {
  printLog(DEBUG, "Testing NULL parameter handling for thread message functions...");
  
  printLog(DEBUG, "Test thrd_msg_q_peek with current thread (should work)\n");
  msg_t *peekResult = thrd_msg_q_peek();
  printLog(DEBUG, "This should return NULL since no messages are queued, but shouldn't crash\n");
  if (peekResult != NULL) {
    printLog(ERR, "thrd_msg_q_peek should return NULL when no messages queued");
    msg_release(peekResult);
    return false;
  }
  
  printLog(DEBUG, "Test thrd_msg_q_pop with current thread (should work)\n");
  msg_t *popResult = thrd_msg_q_pop();
  printLog(DEBUG, "This should return NULL since no messages are queued, but shouldn't crash\n");
  if (popResult != NULL) {
    printLog(ERR, "thrd_msg_q_pop should return NULL when no messages queued");
    msg_release(popResult);
    return false;
  }
  
  printLog(DEBUG, "Test thrd_msg_q_pop_type with current thread (should work)\n");
  popResult = thrd_msg_q_pop_type(TEST_MSG_TYPE_SIMPLE);
  printLog(DEBUG, "This should return NULL since no messages are queued, but shouldn't crash\n");
  if (popResult != NULL) {
    printLog(ERR, 
             "thrd_msg_q_pop_type should return NULL when no messages queued");
    msg_release(popResult);
    return false;
  }
  
  printLog(DEBUG, "Test thrd_msg_q_wait with 0 timeout\n");
  struct timespec shortTimeout = createTimeout(0);
  msg_t *waitResult = thrd_msg_q_wait(&shortTimeout);
  printLog(DEBUG, "This should return NULL immediately since no messages are queued\n");
  if (waitResult != NULL) {
    printLog(ERR, 
             "thrd_msg_q_wait with NULL timeout should return NULL when no messages queued");
    msg_release(waitResult);
    return false;
  }
  
  printLog(DEBUG, "Test thrd_msg_q_wait with valid timeout\n");
  shortTimeout = createTimeout(50); // 50ms
  waitResult = thrd_msg_q_wait(&shortTimeout);
  printLog(DEBUG, "This should timeout and return NULL\n");
  if (waitResult != NULL) {
    printLog(ERR, "thrd_msg_q_wait should timeout and return NULL");
    msg_release(waitResult);
    return false;
  }
  
  printLog(DEBUG, "Test thrd_msg_q_wait_for_type with 0 timeout\n");
  shortTimeout = createTimeout(0);
  waitResult = thrd_msg_q_wait_for_type(TEST_MSG_TYPE_SIMPLE, &shortTimeout);
  printLog(DEBUG, "This should return NULL immediately since no messages are queued\n");
  if (waitResult != NULL) {
    printLog(ERR, 
             "thrd_msg_q_wait_for_type with NULL timeout should return NULL when no messages queued");
    msg_release(waitResult);
    return false;
  }
  
  printLog(DEBUG, "Test thrd_msg_q_wait_for_type with valid timeout\n");
  shortTimeout = createTimeout(50);
  waitResult = thrd_msg_q_wait_for_type(TEST_MSG_TYPE_SIMPLE, &shortTimeout);
  printLog(DEBUG, "This should timeout and return NULL\n");
  if (waitResult != NULL) {
    printLog(ERR, "thrd_msg_q_wait_for_type should timeout and return NULL");
    msg_release(waitResult);
    return false;
  }
  
  printLog(DEBUG, "Test thrd_msg_q_push with invalid thread ID (implementation dependent)\n");
  msg_t *message = msg_create(MSG_THRD_SAFE);
  if (message == NULL) {
    printLog(ERR, "Failed to create message for thread push test");
    return false;
  }
  
  TestData testData = {42, "Thread Push Test"};
  int result = msg_init(message, MSG_THRD_SAFE, TEST_MSG_TYPE_SIMPLE,
                       &testData, sizeof(TestData), false);
  if (result != msg_success) {
    printLog(ERR, "Failed to initialize message for thread push test");
    msg_destroy(message);
    return false;
  }
  
  printLog(DEBUG, "Test thrd_msg_q_push with NULL message\n");
  result = thrd_msg_q_push(thrd_current(), NULL);
  if (result == msg_success) {
    printLog(ERR, "thrd_msg_q_push with NULL message should fail");
    msg_destroy(message);
    return false;
  }
  
  printLog(DEBUG, "Test valid push to current thread\n");
  result = thrd_msg_q_push(thrd_current(), message);
  if (result != msg_success) {
    printLog(ERR, "Valid thrd_msg_q_push to current thread should succeed");
    msg_destroy(message);
    return false;
  }
  
  printLog(DEBUG, "Clean up the message we just pushed\n");
  msg_t *cleanupMessage = thrd_msg_q_pop();
  if (cleanupMessage != NULL) {
    msg_release(cleanupMessage);
  }
  
  printLog(DEBUG, "NULL parameter handling for thread message functions test passed");
  return true;
}

///
/// @brief Test NULL parameter handling for message element accessors.
///
/// @return true if test passes, false otherwise.
///
bool testNullElementAccessorHandling(void) {
  printLog(DEBUG, "Testing NULL parameter handling for message element accessors...");
  
  // Test msg_element with NULL message
  void *elementResult = msg_element(NULL, MSG_ELEMENT_TYPE);
  if (elementResult != NULL) {
    printLog(ERR, "msg_element(NULL, element) should return NULL");
    return false;
  }
  
  // Create a valid message for testing accessors
  msg_t *message = msg_create(MSG_THRD_SAFE);
  if (message == NULL) {
    printLog(ERR, "Failed to create message for element accessor test");
    return false;
  }
  
  TestData testData = {123, "Element Test"};
  int result = msg_init(message, MSG_THRD_SAFE, TEST_MSG_TYPE_SIMPLE,
                       &testData, sizeof(TestData), false);
  if (result != msg_success) {
    printLog(ERR, "Failed to initialize message for element accessor test");
    msg_destroy(message);
    return false;
  }
  
  // Test that accessors work with valid message
  int messageType = msg_type(message);
  if (messageType != TEST_MSG_TYPE_SIMPLE) {
    printLog(ERR, "msg_type should return correct type");
    msg_destroy(message);
    return false;
  }
  
  void *messageData = msg_data(message);
  if (messageData == NULL) {
    printLog(ERR, "msg_data should return valid data pointer");
    msg_destroy(message);
    return false;
  }
  
  size_t messageSize = msg_size(message);
  if (messageSize != sizeof(TestData)) {
    printLog(ERR, "msg_size should return correct size");
    msg_destroy(message);
    return false;
  }
  
  bool waitingFlag = msg_waiting(message);
  if (waitingFlag != false) {
    printLog(ERR, "msg_waiting should return false for non-waiting message");
    msg_destroy(message);
    return false;
  }
  
  bool doneFlag = msg_done(message);
  if (doneFlag != false) {
    printLog(ERR, "msg_done should return false for new message");
    msg_destroy(message);
    return false;
  }
  
  bool inUseFlag = msg_in_use(message);
  // in_use flag behavior is implementation dependent, just verify it doesn't crash
  (void)inUseFlag;
  
  // Test from and to endpoints (these might be uninitialized, but shouldn't crash)
  msg_endpoint_t fromEndpoint = msg_from(message);
  msg_endpoint_t toEndpoint = msg_to(message);
  (void)fromEndpoint;
  (void)toEndpoint;
  
  msg_destroy(message);
  printLog(DEBUG, "NULL parameter handling for message element accessors test passed");
  return true;
}

///
/// @brief Test edge cases with message queue operations.
///
/// @return true if test passes, false otherwise.
///
bool testMessageQueueEdgeCases(void) {
  printLog(DEBUG, "Testing message queue edge cases...");
  
  // Test creating queue with NULL q parameter (should allocate new queue)
  msg_q_t *queue = msg_q_create(NULL, MSG_THRD_SAFE);
  if (queue == NULL) {
    printLog(ERR, "msg_q_create(NULL, MSG_THRD_SAFE) should succeed");
    return false;
  }
  
  // Test operations on empty queue multiple times
  for (int ii = 0; ii < 3; ii++) {
    msg_t *peekResult = msg_q_peek(queue);
    if (peekResult != NULL) {
      printLog(ERR, "Repeated peek on empty queue should return NULL");
      msg_release(peekResult);
      msg_q_destroy(queue);
      return false;
    }
    
    msg_t *popResult = msg_q_pop(queue);
    if (popResult != NULL) {
      printLog(ERR, "Repeated pop on empty queue should return NULL");
      msg_release(popResult);
      msg_q_destroy(queue);
      return false;
    }
    
    msg_t *popTypeResult = msg_q_pop_type(queue, TEST_MSG_TYPE_SIMPLE);
    if (popTypeResult != NULL) {
      printLog(ERR, "Repeated pop_type on empty queue should return NULL");
      msg_release(popTypeResult);
      msg_q_destroy(queue);
      return false;
    }
  }
  
  // Test timeout operations with very short timeouts
  struct timespec veryShortTimeout = createTimeout(1); // 1ms
  msg_t *timeoutResult = msg_q_wait(queue, &veryShortTimeout);
  if (timeoutResult != NULL) {
    printLog(ERR, "Very short timeout wait should return NULL");
    msg_release(timeoutResult);
    msg_q_destroy(queue);
    return false;
  }
  
  timeoutResult = msg_q_wait_for_type(queue, TEST_MSG_TYPE_SIMPLE, 
                                     &veryShortTimeout);
  if (timeoutResult != NULL) {
    printLog(ERR, "Very short timeout wait_for_type should return NULL");
    msg_release(timeoutResult);
    msg_q_destroy(queue);
    return false;
  }
  
  // Test pushing message with zero-sized data
  msg_t *zeroSizeMessage = msg_create(MSG_THRD_SAFE);
  if (zeroSizeMessage == NULL) {
    printLog(ERR, "Failed to create zero-size message");
    msg_q_destroy(queue);
    return false;
  }
  
  int result = msg_init(zeroSizeMessage, MSG_THRD_SAFE, TEST_MSG_TYPE_SIMPLE,
                       NULL, 0, false);
  if (result != msg_success) {
    printLog(ERR, "Failed to initialize zero-size message");
    msg_destroy(zeroSizeMessage);
    msg_q_destroy(queue);
    return false;
  }
  
  result = msg_q_push(queue, NULL, zeroSizeMessage);
  if (result != msg_success) {
    printLog(ERR, "Failed to push zero-size message");
    msg_destroy(zeroSizeMessage);
    msg_q_destroy(queue);
    return false;
  }
  
  // Verify we can retrieve the zero-size message
  msg_t *retrievedMessage = msg_q_pop(queue);
  if (retrievedMessage == NULL) {
    printLog(ERR, "Failed to pop zero-size message");
    msg_q_destroy(queue);
    return false;
  }
  
  if (msg_size(retrievedMessage) != 0) {
    printLog(ERR, "Zero-size message should have size 0");
    msg_release(retrievedMessage);
    msg_q_destroy(queue);
    return false;
  }
  
  if (msg_data(retrievedMessage) != NULL) {
    printLog(ERR, "Zero-size message should have NULL data");
    msg_release(retrievedMessage);
    msg_q_destroy(queue);
    return false;
  }
  
  msg_release(retrievedMessage);
  msg_q_destroy(queue);
  printLog(DEBUG, "Message queue edge cases test passed");
  return true;
}

///
/// @brief Main unit test function for CThreadsMessages.
///
/// @return true if all tests pass, false if any test fails.
///
bool cThreadsMessagesUnitTest(void) {
  printLog(DEBUG, "Starting CThreadsMessages unit tests...");
  
  bool allTestsPassed = true;
  
  // Run all test functions
  if (!testMessageCreation()) {
    printLog(ERR, "Message creation test FAILED");
    allTestsPassed = false;
  }
  
  if (!testMessageQueue()) {
    printLog(ERR, "Message queue test FAILED");
    allTestsPassed = false;
  }
  
  if (!testMessageTypeFiltering()) {
    printLog(ERR, "Message type filtering test FAILED");
    allTestsPassed = false;
  }
  
  if (!testTimeoutOperations()) {
    printLog(ERR, "Timeout operations test FAILED");
    allTestsPassed = false;
  }
  
  if (!testThreadMessageOperations()) {
    printLog(ERR, "Thread message operations test FAILED");
    allTestsPassed = false;
  }
  
  if (!testMessageWaitingAndSync()) {
    printLog(ERR, "Message waiting and synchronization test FAILED");
    allTestsPassed = false;
  }
  
  // New NULL parameter handling tests
  if (!testCThreadsMessagesNullParameterHandling()) {
    printLog(ERR, "NULL parameter handling test FAILED");
    allTestsPassed = false;
  }
  
  if (!testNullQueueParameterHandling()) {
    printLog(ERR, "NULL queue parameter handling test FAILED");
    allTestsPassed = false;
  }
  
  if (!testNullThreadParameterHandling()) {
    printLog(ERR, "NULL thread parameter handling test FAILED");
    allTestsPassed = false;
  }
  
  if (!testNullElementAccessorHandling()) {
    printLog(ERR, "NULL element accessor handling test FAILED");
    allTestsPassed = false;
  }
  
  if (!testMessageQueueEdgeCases()) {
    printLog(ERR, "Message queue edge cases test FAILED");
    allTestsPassed = false;
  }
  
  if (allTestsPassed) {
    printLog(DEBUG, "All CThreadsMessages unit tests PASSED");
  } else {
    printLog(ERR, "Some CThreadsMessages unit tests FAILED");
  }
  
  return allTestsPassed;
}
