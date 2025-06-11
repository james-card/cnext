///////////////////////////////////////////////////////////////////////////////
///
/// @file              MessagesUnitTest.h
///
/// @brief             Common definitions and types for messages unit tests.
///
///////////////////////////////////////////////////////////////////////////////

/// @struct TestData
///
/// @brief Data structure to be passed as a message value between message queues
///
/// @param value An arbitrary value.
/// @param text An arbitrary string.
typedef struct TestData {
  int value;
  char text[64];
} TestData;

