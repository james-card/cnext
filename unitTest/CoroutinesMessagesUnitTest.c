///////////////////////////////////////////////////////////////////////////////
///
/// @file              CoroutinesMessagesUnitTest.c
///
/// @brief             Unit test for coroutines messages functionality.
///
///////////////////////////////////////////////////////////////////////////////

#include "Coroutines.h"
#include "LoggingLib.h"
#include "Messages.h"
#include "MessagesUnitTest.h"

// Test message types
#define TEST_MESSAGE_TYPE_1 100
#define TEST_MESSAGE_TYPE_2 200
#define TEST_MESSAGE_TYPE_3 300

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
/// @brief Creates test data for message testing.
///
/// @param testData Pointer to TestData structure to initialize.
/// @param value Integer value to set.
/// @param text Text string to copy.
///
/// @return None.
///
void createTestData(TestData *testData, int value, const char *text) {
  if (testData == NULL) {
    return;
  }
  
  testData->value = value;
  if (text != NULL) {
    strncpy(testData->text, text, sizeof(testData->text) - 1);
    testData->text[sizeof(testData->text) - 1] = '\0';
  } else {
    testData->text[0] = '\0';
  }
}

///
/// @brief Tests message creation and destruction functions.
///
/// @return Returns true if all tests pass, false otherwise.
///
bool testMessageCreateDestroy(void) {
  printLog(DEBUG, "Testing message create/destroy functions...\n");
  
  // Test normal message creation
  msg_t *message = msg_create(MSG_CORO_SAFE);
  if (message == NULL) {
    printLog(ERR, "Failed to create message\n");
    return false;
  }
  
  // Verify message is properly initialized
  if (!msg_in_use(message)) {
    printLog(ERR, "Message not marked as in use after creation\n");
    msg_destroy(message);
    return false;
  }
  
  // Test message destruction
  msg_t *result = msg_destroy(message);
  if (result != NULL) {
    printLog(ERR, "Message destroy should return NULL\n");
    return false;
  }
  
  // Test destroying NULL message (should be safe)
  result = msg_destroy(NULL);
  if (result != NULL) {
    printLog(ERR, "Destroying NULL message should return NULL\n");
    return false;
  }
  
  printLog(DEBUG, "Message create/destroy tests passed\n");
  return true;
}

///
/// @brief Tests message initialization and release functions.
///
/// @return Returns true if all tests pass, false otherwise.
///
bool testMessageInitRelease(void) {
  printLog(DEBUG, "Testing message init/release functions...\n");
  
  ZEROINIT(msg_t message);
  TestData testData;
  createTestData(&testData, 42, "Test message data");
  
  // Test message initialization
  int result = msg_init(&message, MSG_CORO_SAFE, TEST_MESSAGE_TYPE_1, 
                       &testData, sizeof(testData), true);
  if (result != msg_success) {
    printLog(ERR, "Failed to initialize message: %d\n", result);
    return false;
  }
  
  // Verify message fields
  if (msg_type(&message) != TEST_MESSAGE_TYPE_1) {
    printLog(ERR, "Message type not set correctly\n");
    return false;
  }
  
  if (msg_data(&message) != &testData) {
    printLog(ERR, "Message data pointer not set correctly\n");
    return false;
  }
  
  if (msg_size(&message) != sizeof(testData)) {
    printLog(ERR, "Message size not set correctly\n");
    return false;
  }
  
  if (!msg_waiting(&message)) {
    printLog(ERR, "Message waiting flag not set correctly\n");
    return false;
  }
  
  if (!msg_in_use(&message)) {
    printLog(ERR, "Message in_use flag not set correctly\n");
    return false;
  }
  
  // Test message release
  result = msg_release(&message);
  if (result != msg_success) {
    printLog(ERR, "Failed to release message: %d\n", result);
    return false;
  }
  
  // Test releasing NULL message
  result = msg_release(NULL);
  if (result != msg_success) {
    printLog(ERR, "Releasing NULL message should succeed\n");
    return false;
  }
  
  // Test initializing NULL message
  result = msg_init(NULL, MSG_CORO_SAFE, TEST_MESSAGE_TYPE_1, 
                   &testData, sizeof(testData), false);
  if (result == msg_success) {
    printLog(ERR, "Initializing NULL message should fail\n");
    return false;
  }
  
  printLog(DEBUG, "Message init/release tests passed\n");
  return true;
}

///
/// @brief Tests message done flag functions.
///
/// @return Returns true if all tests pass, false otherwise.
///
bool testMessageDone(void) {
  printLog(DEBUG, "Testing message done functions...\n");
  
  msg_t *message = msg_create(MSG_CORO_SAFE);
  if (message == NULL) {
    printLog(ERR, "Failed to create message for done test\n");
    return false;
  }
  
  TestData testData;
  createTestData(&testData, 123, "Done test data");
  
  int result = msg_init(message, MSG_CORO_SAFE, TEST_MESSAGE_TYPE_2, 
                       &testData, sizeof(testData), true);
  if (result != msg_success) {
    printLog(ERR, "Failed to initialize message for done test\n");
    msg_destroy(message);
    return false;
  }
  
  // Initially, message should not be done
  if (msg_done(message)) {
    printLog(ERR, "Message should not be done initially\n");
    msg_destroy(message);
    return false;
  }
  
  // Set message as done
  result = msg_set_done(message);
  if (result != msg_success) {
    printLog(ERR, "Failed to set message done: %d\n", result);
    msg_destroy(message);
    return false;
  }
  
  // Verify message is now done
  if (!msg_done(message)) {
    printLog(ERR, "Message should be done after msg_set_done\n");
    msg_destroy(message);
    return false;
  }
  
  // Test with timeout (should return immediately since message is done)
  struct timespec ts;
  ts = createTimeout(1000);
  result = msg_wait_for_done(message, &ts);
  if (result != msg_success) {
    printLog(ERR, "Wait for done should succeed immediately: %d\n", result);
    msg_destroy(message);
    return false;
  }
  
  // Test NULL parameters
  result = msg_set_done(NULL);
  if (result == msg_success) {
    printLog(ERR, "Setting done on NULL message should fail\n");
    msg_destroy(message);
    return false;
  }
  
  result = msg_wait_for_done(NULL, &ts);
  if (result == msg_success) {
    printLog(ERR, "Waiting for done on NULL message should fail\n");
    msg_destroy(message);
    return false;
  }
  
  msg_destroy(message);
  printLog(DEBUG, "Message done tests passed\n");
  return true;
}

///
/// @brief Tests message queue creation and destruction functions.
///
/// @return Returns true if all tests pass, false otherwise.
///
bool testMessageQueueCreateDestroy(void) {
  printLog(DEBUG, "Testing message queue create/destroy functions...\n");
  
  // Test queue creation with NULL parameter (should create new queue)
  msg_q_t *queue = msg_q_create(NULL, MSG_CORO_SAFE);
  if (queue == NULL) {
    printLog(ERR, "Failed to create message queue\n");
    return false;
  }
  
  // Test queue destruction
  int result = msg_q_destroy(queue);
  if (result != msg_success) {
    printLog(ERR, "Failed to destroy message queue: %d\n", result);
    return false;
  }
  
  // Test queue creation with existing queue parameter
  msg_q_t existingQueue;
  queue = msg_q_create(&existingQueue, MSG_CORO_SAFE);
  if (queue != &existingQueue) {
    printLog(ERR, "Queue creation should return existing queue pointer\n");
    return false;
  }
  
  // Test destroying NULL queue (should be safe)
  result = msg_q_destroy(NULL);
  if (result != msg_success) {
    printLog(ERR, "Destroying NULL queue should succeed\n");
    return false;
  }
  
  printLog(DEBUG, "Message queue create/destroy tests passed\n");
  return true;
}

///
/// @brief Tests message queue basic operations (push, pop, peek).
///
/// @return Returns true if all tests pass, false otherwise.
///
bool testMessageQueueOperations(void) {
  printLog(DEBUG, "Testing message queue operations...\n");
  
  msg_q_t *queue = msg_q_create(NULL, MSG_CORO_SAFE);
  if (queue == NULL) {
    printLog(ERR, "Failed to create queue for operations test\n");
    return false;
  }
  
  // Test peek on empty queue
  msg_t *peeked = msg_q_peek(queue);
  if (peeked != NULL) {
    printLog(ERR, "Peek on empty queue should return NULL\n");
    msg_q_destroy(queue);
    return false;
  }
  
  // Test pop on empty queue
  msg_t *popped = msg_q_pop(queue);
  if (popped != NULL) {
    printLog(ERR, "Pop on empty queue should return NULL\n");
    msg_q_destroy(queue);
    return false;
  }
  
  // Create test messages
  msg_t *message1 = msg_create(MSG_CORO_SAFE);
  msg_t *message2 = msg_create(MSG_CORO_SAFE);
  msg_t *message3 = msg_create(MSG_CORO_SAFE);
  
  if (message1 == NULL || message2 == NULL || message3 == NULL) {
    printLog(ERR, "Failed to create test messages\n");
    msg_destroy(message1);
    msg_destroy(message2);
    msg_destroy(message3);
    msg_q_destroy(queue);
    return false;
  }
  
  TestData testData1, testData2, testData3;
  createTestData(&testData1, 1, "Message 1");
  createTestData(&testData2, 2, "Message 2");
  createTestData(&testData3, 3, "Message 3");
  
  msg_init(message1, MSG_CORO_SAFE, TEST_MESSAGE_TYPE_1, 
           &testData1, sizeof(testData1), false);
  msg_init(message2, MSG_CORO_SAFE, TEST_MESSAGE_TYPE_2, 
           &testData2, sizeof(testData2), false);
  msg_init(message3, MSG_CORO_SAFE, TEST_MESSAGE_TYPE_1, 
           &testData3, sizeof(testData3), false);
  
  // Test push operations
  int result = msg_q_push(queue, NULL, message1);
  if (result != msg_success) {
    printLog(ERR, "Failed to push message1: %d\n", result);
    msg_destroy(message1);
    msg_destroy(message2);
    msg_destroy(message3);
    msg_q_destroy(queue);
    return false;
  }
  
  result = msg_q_push(queue, NULL, message2);
  if (result != msg_success) {
    printLog(ERR, "Failed to push message2: %d\n", result);
    msg_destroy(message2);
    msg_destroy(message3);
    msg_q_destroy(queue);
    return false;
  }
  
  result = msg_q_push(queue, NULL, message3);
  if (result != msg_success) {
    printLog(ERR, "Failed to push message3: %d\n", result);
    msg_destroy(message3);
    msg_q_destroy(queue);
    return false;
  }
  
  // Test peek (should return first message without removing it)
  peeked = msg_q_peek(queue);
  if (peeked != message1) {
    printLog(ERR, "Peek should return first message\n");
    msg_q_destroy(queue);
    return false;
  }
  
  // Peek again (should still return same message)
  peeked = msg_q_peek(queue);
  if (peeked != message1) {
    printLog(ERR, "Second peek should return same message\n");
    msg_q_destroy(queue);
    return false;
  }
  
  // Test pop (should return and remove first message)
  popped = msg_q_pop(queue);
  if (popped != message1) {
    printLog(ERR, "Pop should return first message\n");
    msg_q_destroy(queue);
    return false;
  }
  
  // Now peek should return second message
  peeked = msg_q_peek(queue);
  if (peeked != message2) {
    printLog(ERR, "Peek after pop should return second message\n");
    msg_q_destroy(queue);
    return false;
  }
  
  // Test pop by type
  popped = msg_q_pop_type(queue, TEST_MESSAGE_TYPE_1);
  if (popped != message3) {
    printLog(ERR, "Pop by type should return message3\n");
    msg_q_destroy(queue);
    return false;
  }
  
  // Pop remaining message
  popped = msg_q_pop(queue);
  if (popped != message2) {
    printLog(ERR, "Final pop should return message2\n");
    msg_q_destroy(queue);
    return false;
  }
  
  // Queue should now be empty
  peeked = msg_q_peek(queue);
  if (peeked != NULL) {
    printLog(ERR, "Queue should be empty after all pops\n");
    msg_q_destroy(queue);
    return false;
  }
  
  // Test NULL parameters
  result = msg_q_push(NULL, NULL, message1);
  if (result == msg_success) {
    printLog(ERR, "Push to NULL queue should fail\n");
    msg_destroy(message1);
    msg_q_destroy(queue);
    return false;
  }
  
  result = msg_q_push(queue, NULL, NULL);
  if (result == msg_success) {
    printLog(ERR, "Push NULL message should fail\n");
    msg_destroy(message1);
    msg_q_destroy(queue);
    return false;
  }
  
  peeked = msg_q_peek(NULL);
  if (peeked != NULL) {
    printLog(ERR, "Peek NULL queue should return NULL\n");
    msg_destroy(message1);
    msg_q_destroy(queue);
    return false;
  }
  
  popped = msg_q_pop(NULL);
  if (popped != NULL) {
    printLog(ERR, "Pop NULL queue should return NULL\n");
    msg_destroy(message1);
    msg_q_destroy(queue);
    return false;
  }
  
  popped = msg_q_pop_type(NULL, TEST_MESSAGE_TYPE_1);
  if (popped != NULL) {
    printLog(ERR, "Pop type from NULL queue should return NULL\n");
    msg_destroy(message1);
    msg_q_destroy(queue);
    return false;
  }
  
  // Clean up
  msg_destroy(message1);
  msg_q_destroy(queue);
  
  printLog(DEBUG, "Message queue operations tests passed\n");
  return true;
}

///
/// @brief Tests message queue wait operations with timeouts.
///
/// @return Returns true if all tests pass, false otherwise.
///
bool testMessageQueueWait(void) {
  printLog(DEBUG, "Testing message queue wait operations...\n");
  
  msg_q_t *queue = msg_q_create(NULL, MSG_CORO_SAFE);
  if (queue == NULL) {
    printLog(ERR, "Failed to create queue for wait test\n");
    return false;
  }
  
  struct timespec ts;
  ts = createTimeout(1000);
  
  // Test wait on empty queue with timeout (should timeout)
  msg_t *waited = msg_q_wait(queue, &ts);
  if (waited != NULL) {
    printLog(ERR, "Wait on empty queue should timeout and return NULL\n");
    msg_q_destroy(queue);
    return false;
  }
  
  // Test wait for specific type on empty queue (should timeout)
  waited = msg_q_wait_for_type(queue, TEST_MESSAGE_TYPE_1, &ts);
  if (waited != NULL) {
    printLog(ERR, "Wait for type on empty queue should timeout\n");
    msg_q_destroy(queue);
    return false;
  }
  
  // Add a message to the queue
  msg_t *message = msg_create(MSG_CORO_SAFE);
  if (message == NULL) {
    printLog(ERR, "Failed to create message for wait test\n");
    msg_q_destroy(queue);
    return false;
  }
  
  TestData testData;
  createTestData(&testData, 999, "Wait test message");
  
  int result = msg_init(message, MSG_CORO_SAFE, TEST_MESSAGE_TYPE_1, 
                       &testData, sizeof(testData), false);
  if (result != msg_success) {
    printLog(ERR, "Failed to init message for wait test\n");
    msg_destroy(message);
    msg_q_destroy(queue);
    return false;
  }
  
  result = msg_q_push(queue, NULL, message);
  if (result != msg_success) {
    printLog(ERR, "Failed to push message for wait test\n");
    msg_destroy(message);
    msg_q_destroy(queue);
    return false;
  }
  
  // Now wait should return immediately
  ts = createTimeout(1000);
  waited = msg_q_wait(queue, &ts);
  if (waited != message) {
    printLog(ERR, "Wait should return immediately when message available\n");
    msg_q_destroy(queue);
    return false;
  }
  
  // Test wait for specific type that exists
  result = msg_q_push(queue, NULL, message);
  if (result != msg_success) {
    printLog(ERR, "Failed to push message back for type wait test\n");
    msg_destroy(message);
    msg_q_destroy(queue);
    return false;
  }
  
  ts = createTimeout(1000);
  waited = msg_q_wait_for_type(queue, TEST_MESSAGE_TYPE_1, &ts);
  if (waited != message) {
    printLog(ERR, "Wait for type should return matching message\n");
    msg_q_destroy(queue);
    return false;
  }
  
  // Test NULL parameters
  waited = msg_q_wait(NULL, &ts);
  if (waited != NULL) {
    printLog(ERR, "Wait on NULL queue should return NULL\n");
    msg_destroy(message);
    msg_q_destroy(queue);
    return false;
  }
  
  waited = msg_q_wait_for_type(NULL, TEST_MESSAGE_TYPE_1, &ts);
  if (waited != NULL) {
    printLog(ERR, "Wait for type on NULL queue should return NULL\n");
    msg_destroy(message);
    msg_q_destroy(queue);
    return false;
  }
  
  // Clean up
  msg_destroy(message);
  msg_q_destroy(queue);
  
  printLog(DEBUG, "Message queue wait tests passed\n");
  return true;
}

///
/// @brief Tests message element accessor functions and macros.
///
/// @return Returns true if all tests pass, false otherwise.
///
bool testMessageElementAccessors(void) {
  printLog(DEBUG, "Testing message element accessors...\n");
  
  msg_t *message = msg_create(MSG_CORO_SAFE);
  if (message == NULL) {
    printLog(ERR, "Failed to create message for accessor test\n");
    return false;
  }
  
  TestData testData;
  createTestData(&testData, 777, "Accessor test data");
  
  int result = msg_init(message, MSG_CORO_SAFE, TEST_MESSAGE_TYPE_3, 
                       &testData, sizeof(testData), true);
  if (result != msg_success) {
    printLog(ERR, "Failed to init message for accessor test\n");
    msg_destroy(message);
    return false;
  }
  
  // Test type accessor
  void *typePtr = msg_element(message, MSG_ELEMENT_TYPE);
  if (typePtr == NULL || *((int*) typePtr) != TEST_MESSAGE_TYPE_3) {
    printLog(ERR, "Type element accessor failed\n");
    msg_destroy(message);
    return false;
  }
  
  if (msg_type(message) != TEST_MESSAGE_TYPE_3) {
    printLog(ERR, "Type macro accessor failed\n");
    msg_destroy(message);
    return false;
  }
  
  // Test data accessor
  void *dataPtr = msg_element(message, MSG_ELEMENT_DATA);
  if (dataPtr == NULL || *((void**) dataPtr) != &testData) {
    printLog(ERR, "Data element accessor failed\n");
    msg_destroy(message);
    return false;
  }
  
  if (msg_data(message) != &testData) {
    printLog(ERR, "Data macro accessor failed\n");
    msg_destroy(message);
    return false;
  }
  
  // Test size accessor
  void *sizePtr = msg_element(message, MSG_ELEMENT_SIZE);
  if (sizePtr == NULL || *((size_t*) sizePtr) != sizeof(testData)) {
    printLog(ERR, "Size element accessor failed\n");
    msg_destroy(message);
    return false;
  }
  
  if (msg_size(message) != sizeof(testData)) {
    printLog(ERR, "Size macro accessor failed\n");
    msg_destroy(message);
    return false;
  }
  
  // Test waiting accessor
  void *waitingPtr = msg_element(message, MSG_ELEMENT_WAITING);
  if (waitingPtr == NULL || *((bool*) waitingPtr) != true) {
    printLog(ERR, "Waiting element accessor failed\n");
    msg_destroy(message);
    return false;
  }
  
  if (msg_waiting(message) != true) {
    printLog(ERR, "Waiting macro accessor failed\n");
    msg_destroy(message);
    return false;
  }
  
  // Test done accessor (should be false initially)
  void *donePtr = msg_element(message, MSG_ELEMENT_DONE);
  if (donePtr == NULL || *((bool*) donePtr) != false) {
    printLog(ERR, "Done element accessor failed\n");
    msg_destroy(message);
    return false;
  }
  
  if (msg_done(message) != false) {
    printLog(ERR, "Done macro accessor failed\n");
    msg_destroy(message);
    return false;
  }
  
  // Test in_use accessor
  void *inUsePtr = msg_element(message, MSG_ELEMENT_IN_USE);
  if (inUsePtr == NULL || *((bool*) inUsePtr) != true) {
    printLog(ERR, "In_use element accessor failed\n");
    msg_destroy(message);
    return false;
  }
  
  if (msg_in_use(message) != true) {
    printLog(ERR, "In_use macro accessor failed\n");
    msg_destroy(message);
    return false;
  }
  
  // Test NULL parameters
  void *nullResult = msg_element(NULL, MSG_ELEMENT_TYPE);
  if (nullResult != NULL) {
    printLog(ERR, "Element accessor with NULL message should return NULL\n");
    msg_destroy(message);
    return false;
  }
  
  // Test invalid element type
  void *invalidResult = msg_element(message, NUM_MSG_ELEMENTS);
  if (invalidResult != NULL) {
    printLog(ERR, "Element accessor with invalid type should return NULL\n");
    msg_destroy(message);
    return false;
  }
  
  // Clean up
  msg_destroy(message);
  
  printLog(DEBUG, "Message element accessor tests passed\n");
  return true;
}

///
/// @brief Tests message reply functionality.
///
/// @return Returns true if all tests pass, false otherwise.
///
bool testMessageReply(void) {
  printLog(DEBUG, "Testing message reply functionality...\n");
  
  // Create original message
  msg_t *originalMessage = msg_create(MSG_CORO_SAFE);
  if (originalMessage == NULL) {
    printLog(ERR, "Failed to create original message for reply test\n");
    return false;
  }
  
  TestData testData;
  createTestData(&testData, 555, "Original message");
  
  int result = msg_init(originalMessage, MSG_CORO_SAFE, TEST_MESSAGE_TYPE_1, 
                       &testData, sizeof(testData), true);
  if (result != msg_success) {
    printLog(ERR, "Failed to init original message for reply test\n");
    msg_destroy(originalMessage);
    return false;
  }
  
  // Test waiting for reply on message that's not done yet
  struct timespec ts;
  ts = createTimeout(1000);
  
  msg_t *reply = msg_wait_for_reply(originalMessage, false, &ts);
  if (reply != NULL) {
    printLog(ERR, "Wait for reply should timeout when no reply sent\n");
    msg_destroy(originalMessage);
    return false;
  }
  
  // Test waiting for reply with specific type
  reply = msg_wait_for_reply_with_type(originalMessage, false, 
                                      TEST_MESSAGE_TYPE_2, &ts);
  if (reply != NULL) {
    printLog(ERR, "Wait for reply with type should timeout when no reply\n");
    msg_destroy(originalMessage);
    return false;
  }
  
  // Test NULL parameters
  reply = msg_wait_for_reply(NULL, false, &ts);
  if (reply != NULL) {
    printLog(ERR, "Wait for reply on NULL message should return NULL\n");
    msg_destroy(originalMessage);
    return false;
  }
  
  reply = msg_wait_for_reply_with_type(NULL, false, TEST_MESSAGE_TYPE_1, &ts);
  if (reply != NULL) {
    printLog(ERR, "Wait for reply with type on NULL should return NULL\n");
    msg_destroy(originalMessage);
    return false;
  }
  
  // Clean up
  msg_destroy(originalMessage);
  
  printLog(DEBUG, "Message reply tests passed\n");
  return true;
}

///
/// @brief Coroutine function that does nothing just to satisfy the creation
/// in testCoroutineMessageQueueFunctions below.
///
/// @param args Any arguments provided to the coroutine cast to a void*.
///   Ignored by this function.
///
/// @return This function always returns NULL.
void* dummyCoroutine(void *args) {
  (void) args;
  return NULL;
}

///
/// @brief Tests all comessageQueue* functions with NULL parameters and edge cases.
///
/// @return Returns true if all tests pass, false if any test fails.
///
bool testCoroutineMessageQueueFunctions(void) {
  printLog(DEBUG, "Testing coroutine message queue functions...\n");
  
  // First, we need to set up a coroutine environment since these functions
  // operate on the running coroutine's message queue
  Coroutine *mainCoroutine = NULL;
  Coroutine *testCoroutine = NULL;
  bool allTestsPassed = true;
  
  // Create a test coroutine to work with
  int result = coroutineCreate(&testCoroutine, dummyCoroutine, NULL);
  if (result != coroutineSuccess || testCoroutine == NULL) {
    printLog(ERR, "Failed to create test coroutine: %d\n", result);
    return false;
  }
  
  mainCoroutine = getRunningCoroutine();
  if (mainCoroutine == NULL) {
    printLog(ERR, "Failed to get running coroutine\n");
    return false;
  }
  
  // Test 1: comessageQueuePeek() on empty queue
  printLog(DEBUG, "Testing comessageQueuePeek() on empty queue...\n");
  msg_t *peeked = comessageQueuePeek();
  if (peeked != NULL) {
    printLog(ERR, "comessageQueuePeek() should return NULL on empty queue\n");
    allTestsPassed = false;
  }
  
  // Test 2: comessageQueuePop() on empty queue
  printLog(DEBUG, "Testing comessageQueuePop() on empty queue...\n");
  msg_t *popped = comessageQueuePop();
  if (popped != NULL) {
    printLog(ERR, "comessageQueuePop() should return NULL on empty queue\n");
    allTestsPassed = false;
  }
  
  // Test 3: comessageQueuePopType() on empty queue
  printLog(DEBUG, "Testing comessageQueuePopType() on empty queue...\n");
  popped = comessageQueuePopType(TEST_MESSAGE_TYPE_1);
  if (popped != NULL) {
    printLog(ERR, "comessageQueuePopType() should return NULL on empty queue\n");
    allTestsPassed = false;
  }
  
  // Test 4: comessageQueueWait() with timeout on empty queue
  printLog(DEBUG, "Testing comessageQueueWait() with timeout on empty queue...\n");
  struct timespec shortTimeout;
  clock_gettime(CLOCK_REALTIME, &shortTimeout);
  shortTimeout.tv_nsec += 100000000; // 100ms timeout
  if (shortTimeout.tv_nsec >= 1000000000) {
    shortTimeout.tv_sec += 1;
    shortTimeout.tv_nsec -= 1000000000;
  }
  
  msg_t *waited = comessageQueueWait(&shortTimeout);
  if (waited != NULL) {
    printLog(ERR, "comessageQueueWait() should timeout and return NULL\n");
    allTestsPassed = false;
  }
  
  // Test 5: comessageQueueWaitForType() with timeout on empty queue
  printLog(DEBUG, "Testing comessageQueueWaitForType() with timeout...\n");
  clock_gettime(CLOCK_REALTIME, &shortTimeout);
  shortTimeout.tv_nsec += 100000000; // 100ms timeout
  if (shortTimeout.tv_nsec >= 1000000000) {
    shortTimeout.tv_sec += 1;
    shortTimeout.tv_nsec -= 1000000000;
  }
  
  waited = comessageQueueWaitForType(TEST_MESSAGE_TYPE_1, &shortTimeout);
  if (waited != NULL) {
    printLog(ERR, "comessageQueueWaitForType() should timeout and return NULL\n");
    allTestsPassed = false;
  }
  
  // Test 6: comessageQueuePush() with NULL coroutine parameter
  printLog(DEBUG, "Testing comessageQueuePush() with NULL coroutine...\n");
  msg_t *testMessage = msg_create(MSG_CORO_SAFE);
  if (testMessage == NULL) {
    printLog(ERR, "Failed to create test message\n");
    return false;
  }
  
  TestData testData;
  createTestData(&testData, 123, "Test push message");
  
  result = msg_init(testMessage, MSG_CORO_SAFE, TEST_MESSAGE_TYPE_1, 
                   &testData, sizeof(testData), false);
  if (result != msg_success) {
    printLog(ERR, "Failed to initialize test message\n");
    msg_destroy(testMessage);
    return false;
  }
  
  result = comessageQueuePush(NULL, testMessage);
  if (result == msg_success) {
    printLog(ERR, "comessageQueuePush() with NULL coroutine should fail\n");
    allTestsPassed = false;
  }
  
  // Test 7: comessageQueuePush() with NULL message parameter
  printLog(DEBUG, "Testing comessageQueuePush() with NULL message...\n");
  result = comessageQueuePush(testCoroutine, NULL);
  if (result == msg_success) {
    printLog(ERR, "comessageQueuePush() with NULL message should fail\n");
    allTestsPassed = false;
  }
  
  // Test 8: comessageQueuePush() with valid parameters
  printLog(DEBUG, "Testing comessageQueuePush() with valid parameters...\n");
  result = comessageQueuePush(mainCoroutine, testMessage);
  if (result != msg_success) {
    printLog(ERR, "comessageQueuePush() with valid params should succeed: %d\n", 
             result);
    allTestsPassed = false;
    msg_destroy(testMessage);
    return false;
  }
  
  // Test 9: comessageQueuePeek() on non-empty queue
  printLog(DEBUG, "Testing comessageQueuePeek() on non-empty queue...\n");
  peeked = comessageQueuePeek();
  if (peeked != testMessage) {
    printLog(ERR, "comessageQueuePeek() should return the pushed message\n");
    allTestsPassed = false;
  }
  
  // Test 10: comessageQueuePeek() again (should return same message)
  printLog(DEBUG, "Testing comessageQueuePeek() consistency...\n");
  msg_t *peeked2 = comessageQueuePeek();
  if (peeked2 != peeked) {
    printLog(ERR, "comessageQueuePeek() should return same message consistently\n");
    allTestsPassed = false;
  }
  
  // Test 11: Add more messages to test ordering and type-specific operations
  printLog(DEBUG, "Adding more test messages...\n");
  msg_t *testMessage2 = msg_create(MSG_CORO_SAFE);
  msg_t *testMessage3 = msg_create(MSG_CORO_SAFE);
  
  if (testMessage2 == NULL || testMessage3 == NULL) {
    printLog(ERR, "Failed to create additional test messages\n");
    msg_destroy(testMessage2);
    msg_destroy(testMessage3);
    return false;
  }
  
  TestData testData2, testData3;
  createTestData(&testData2, 456, "Second test message");
  createTestData(&testData3, 789, "Third test message");
  
  result = msg_init(testMessage2, MSG_CORO_SAFE, TEST_MESSAGE_TYPE_2, 
                   &testData2, sizeof(testData2), false);
  if (result != msg_success) {
    printLog(ERR, "Failed to initialize second test message\n");
    msg_destroy(testMessage2);
    msg_destroy(testMessage3);
    return false;
  }
  
  result = msg_init(testMessage3, MSG_CORO_SAFE, TEST_MESSAGE_TYPE_1, 
                   &testData3, sizeof(testData3), false);
  if (result != msg_success) {
    printLog(ERR, "Failed to initialize third test message\n");
    msg_destroy(testMessage2);
    msg_destroy(testMessage3);
    return false;
  }
  
  result = comessageQueuePush(mainCoroutine, testMessage2);
  if (result != msg_success) {
    printLog(ERR, "Failed to push second message: %d\n", result);
    allTestsPassed = false;
  }
  
  result = comessageQueuePush(mainCoroutine, testMessage3);
  if (result != msg_success) {
    printLog(ERR, "Failed to push third message: %d\n", result);
    allTestsPassed = false;
  }
  
  // Test 12: comessageQueuePopType() for specific type
  printLog(DEBUG, "Testing comessageQueuePopType() for specific type...\n");
  popped = comessageQueuePopType(TEST_MESSAGE_TYPE_2);
  if (popped != testMessage2) {
    printLog(ERR, "comessageQueuePopType() should return message of requested type\n");
    allTestsPassed = false;
  }
  
  // Test 13: comessageQueuePop() should return messages in FIFO order
  printLog(DEBUG, "Testing comessageQueuePop() FIFO order...\n");
  popped = comessageQueuePop();
  if (popped != testMessage) {
    printLog(ERR, "comessageQueuePop() should return first message (FIFO)\n");
    allTestsPassed = false;
  }
  
  // Test 14: comessageQueueWait() should return immediately when message available
  printLog(DEBUG, "Testing comessageQueueWait() with message available...\n");
  struct timespec longTimeout;
  clock_gettime(CLOCK_REALTIME, &longTimeout);
  longTimeout.tv_sec += 10; // 10 second timeout (should not be reached)
  
  waited = comessageQueueWait(&longTimeout);
  if (waited != testMessage3) {
    printLog(ERR, "comessageQueueWait() should return immediately when message available\n");
    allTestsPassed = false;
  }
  
  // Test 15: Push a message back and test comessageQueueWaitForType()
  printLog(DEBUG, "Testing comessageQueueWaitForType() with message available...\n");
  result = comessageQueuePush(mainCoroutine, testMessage3);
  if (result != msg_success) {
    printLog(ERR, "Failed to push message back for wait test: %d\n", result);
    allTestsPassed = false;
  }
  
  clock_gettime(CLOCK_REALTIME, &longTimeout);
  longTimeout.tv_sec += 10; // 10 second timeout (should not be reached)
  
  waited = comessageQueueWaitForType(TEST_MESSAGE_TYPE_1, &longTimeout);
  if (waited != testMessage3) {
    printLog(ERR, "comessageQueueWaitForType() should return matching type immediately\n");
    allTestsPassed = false;
  }
  
  // Test 16: comessageQueueWaitForType() with non-matching type
  printLog(DEBUG, "Testing comessageQueueWaitForType() with non-matching type...\n");
  
  // Push a message of different type
  result = comessageQueuePush(mainCoroutine, testMessage2);
  if (result != msg_success) {
    printLog(ERR, "Failed to push message for non-matching type test: %d\n", result);
    allTestsPassed = false;
  }
  
  clock_gettime(CLOCK_REALTIME, &shortTimeout);
  shortTimeout.tv_nsec += 100000000; // 100ms timeout
  if (shortTimeout.tv_nsec >= 1000000000) {
    shortTimeout.tv_sec += 1;
    shortTimeout.tv_nsec -= 1000000000;
  }
  
  waited = comessageQueueWaitForType(TEST_MESSAGE_TYPE_3, &shortTimeout);
  if (waited != NULL) {
    printLog(ERR, "comessageQueueWaitForType() should timeout for non-matching type\n");
    allTestsPassed = false;
  }
  
  // Test 17: Test with NULL timespec parameters
  printLog(DEBUG, "Testing comessageQueueWait() with NULL timespec...\n");
  waited = comessageQueueWait(NULL);
  if (waited != testMessage2) {
    printLog(ERR, "comessageQueueWait() with NULL timespec should return immediately if message available\n");
    allTestsPassed = false;
  }
  
  // Test 18: Test comessageQueueWaitForType() with NULL timespec
  printLog(DEBUG, "Testing comessageQueueWaitForType() with NULL timespec...\n");
  
  // Push message back for this test
  result = comessageQueuePush(mainCoroutine, testMessage2);
  if (result != msg_success) {
    printLog(ERR, "Failed to push message for NULL timespec test: %d\n", result);
    allTestsPassed = false;
  }
  
  waited = comessageQueueWaitForType(TEST_MESSAGE_TYPE_2, NULL);
  if (waited != testMessage2) {
    printLog(ERR, "comessageQueueWaitForType() with NULL timespec should return immediately if matching message available\n");
    allTestsPassed = false;
  }
  
  // Test 19: Test edge case with invalid message type
  printLog(DEBUG, "Testing comessageQueuePopType() with invalid type...\n");
  popped = comessageQueuePopType(-1);
  if (popped != NULL) {
    printLog(ERR, "comessageQueuePopType() with invalid type should return NULL\n");
    allTestsPassed = false;
  }
  
  // Test 20: Test edge case with very large message type
  printLog(DEBUG, "Testing comessageQueuePopType() with very large type...\n");
  popped = comessageQueuePopType(INT_MAX);
  if (popped != NULL) {
    printLog(ERR, "comessageQueuePopType() with very large type should return NULL\n");
    allTestsPassed = false;
  }
  
  // Test 21: Test comessageQueueWaitForType() with invalid type
  printLog(DEBUG, "Testing comessageQueueWaitForType() with invalid type...\n");
  clock_gettime(CLOCK_REALTIME, &shortTimeout);
  shortTimeout.tv_nsec += 100000000; // 100ms timeout
  if (shortTimeout.tv_nsec >= 1000000000) {
    shortTimeout.tv_sec += 1;
    shortTimeout.tv_nsec -= 1000000000;
  }
  
  waited = comessageQueueWaitForType(-999, &shortTimeout);
  if (waited != NULL) {
    printLog(ERR, "comessageQueueWaitForType() with invalid type should timeout\n");
    allTestsPassed = false;
  }
  
  // Test 22: Verify queue is empty after all operations
  printLog(DEBUG, "Verifying queue is empty after all operations...\n");
  peeked = comessageQueuePeek();
  if (peeked != NULL) {
    printLog(ERR, "Queue should be empty after all test operations\n");
    allTestsPassed = false;
  }
  
  // Clean up messages
  msg_destroy(testMessage);
  msg_destroy(testMessage2);
  msg_destroy(testMessage3);
  
  // Clean up coroutines if necessary
  if (testCoroutine != NULL) {
    // Note: Actual cleanup may depend on your coroutine implementation
    // coroutineTerminate(testCoroutine, NULL);
  }
  
  if (allTestsPassed) {
    printLog(DEBUG, "All coroutine message queue function tests PASSED\n");
  } else {
    printLog(ERR, "Some coroutine message queue function tests FAILED\n");
  }
  
  return allTestsPassed;
}

///
/// @brief Main unit test function for coroutines messages functionality.
///
/// @return Returns true if all tests pass, false if any test fails.
///
/// @note This test requires that coroutineConfig was already called properly
/// before being called.
bool coroutinesMessagesUnitTest(void) {
  printLog(DEBUG, "Starting coroutines messages unit test...\n");
  
  bool allTestsPassed = true;
  
  // Run all test functions
  if (!testMessageCreateDestroy()) {
    printLog(ERR, "Message create/destroy tests failed\n");
    allTestsPassed = false;
  }
  
  if (!testMessageInitRelease()) {
    printLog(ERR, "Message init/release tests failed\n");
    allTestsPassed = false;
  }
  
  if (!testMessageDone()) {
    printLog(ERR, "Message done tests failed\n");
    allTestsPassed = false;
  }
  
  if (!testMessageQueueCreateDestroy()) {
    printLog(ERR, "Message queue create/destroy tests failed\n");
    allTestsPassed = false;
  }
  
  if (!testMessageQueueOperations()) {
    printLog(ERR, "Message queue operations tests failed\n");
    allTestsPassed = false;
  }
  
  if (!testMessageQueueWait()) {
    printLog(ERR, "Message queue wait tests failed\n");
    allTestsPassed = false;
  }
  
  if (!testMessageElementAccessors()) {
    printLog(ERR, "Message element accessor tests failed\n");
    allTestsPassed = false;
  }
  
  if (!testMessageReply()) {
    printLog(ERR, "Message reply tests failed\n");
    allTestsPassed = false;
  }
  
  if (!testCoroutineMessageQueueFunctions()) {
    printLog(ERR, "Coroutine message queue tests failed\n");
    allTestsPassed = false;
  }
  
  if (allTestsPassed) {
    printLog(DEBUG, "All coroutines messages unit tests PASSED\n");
  } else {
    printLog(ERR, "Some coroutines messages unit tests FAILED\n");
  }
  
  return allTestsPassed;
}
