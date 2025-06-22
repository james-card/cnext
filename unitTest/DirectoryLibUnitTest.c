///////////////////////////////////////////////////////////////////////////////
///
/// @file              DirectoryLibUnitTest.c
///
/// @brief             Unit test for DirectoryLib functions
///
/// @details           Comprehensive unit test that exercises all non-WIN32
///                    specific functions in DirectoryLib.h including corner
///                    cases and error conditions.
///
///////////////////////////////////////////////////////////////////////////////

#include "DirectoryLib.h"
#include "LoggingLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

// Test constants
#define TEST_BASE_DIR "/tmp/directorylib_test"
#define MAX_PATH_LENGTH 1024

///////////////////////////////////////////////////////////////////////////////
/// @brief Creates a test file with specified content
/// @param filePath The path where the file should be created
/// @param content The content to write to the file (can be NULL for empty file)
/// @return true if file was created successfully, false otherwise
///////////////////////////////////////////////////////////////////////////////
static bool createTestFile(const char *filePath, const char *content) {
  if (filePath == NULL) {
    return false;
  }
  
  FILE *file = fopen(filePath, "w");
  if (file == NULL) {
    printLog(ERR, "Failed to create test file: %s", filePath);
    return false;
  }
  
  if (content != NULL) {
    if (fprintf(file, "%s", content) < 0) {
      fclose(file);
      return false;
    }
  }
  
  fclose(file);
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Checks if a file exists
/// @param filePath The path to check
/// @return true if file exists, false otherwise
///////////////////////////////////////////////////////////////////////////////
static bool fileExists(const char *filePath) {
  if (filePath == NULL) {
    return false;
  }
  
  struct stat statBuffer;
  return (stat(filePath, &statBuffer) == 0);
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Counts the number of strings in a NULL-terminated array
/// @param stringArray The array to count
/// @return The number of strings in the array
///////////////////////////////////////////////////////////////////////////////
static int countStringArray(char **stringArray) {
  if (stringArray == NULL) {
    return 0;
  }
  
  int count = 0;
  while (stringArray[count] != NULL) {
    count++;
  }
  
  return count;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Checks if a string exists in a NULL-terminated string array
/// @param stringArray The array to search
/// @param target The string to find
/// @return true if string is found, false otherwise
///////////////////////////////////////////////////////////////////////////////
static bool stringInArray(char **stringArray, const char *target) {
  if (stringArray == NULL || target == NULL) {
    return false;
  }
  
  for (int ii = 0; stringArray[ii] != NULL; ii++) {
    if (strcmp(stringArray[ii], target) == 0) {
      return true;
    }
  }
  
  return false;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Sets up the test environment by creating base directory structure
/// @return true if setup was successful, false otherwise
///////////////////////////////////////////////////////////////////////////////
static bool setupTestEnvironment(void) {
  // Clean up any existing test directory first
  rmdirRecursive(TEST_BASE_DIR);
  
  // Create base test directory
  if (mkpath(TEST_BASE_DIR, 0755) != 0) {
    printLog(ERR, "Failed to create test base directory: %s", TEST_BASE_DIR);
    return false;
  }
  
  printLog(DEBUG, "Test environment setup completed");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Cleans up the test environment
/// @return true if cleanup was successful, false otherwise
///////////////////////////////////////////////////////////////////////////////
static bool cleanupTestEnvironment(void) {
  int result = rmdirRecursive(TEST_BASE_DIR);
  if (result == 0) {
    printLog(DEBUG, "Test environment cleanup completed");
    return true;
  } else {
    printLog(ERR, "Failed to cleanup test environment");
    return false;
  }
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Tests the isDirectory function
/// @return true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
static bool testIsDirectory(void) {
  printLog(DEBUG, "Testing isDirectory function");
  
  // Test with NULL parameter
  if (isDirectory(NULL) != false) {
    printLog(ERR, "isDirectory(NULL) should return false");
    return false;
  }
  
  // Test with non-existent path
  if (isDirectory("/tmp/nonexistent_path_12345") != false) {
    printLog(ERR, "isDirectory with non-existent path should return false");
    return false;
  }
  
  // Test with existing directory
  if (isDirectory(TEST_BASE_DIR) != true) {
    printLog(ERR, "isDirectory should return true for existing directory");
    return false;
  }
  
  // Create a test file and verify it's not identified as directory
  char testFilePath[MAX_PATH_LENGTH];
  snprintf(testFilePath, sizeof(testFilePath), "%s/testfile.txt", 
           TEST_BASE_DIR);
  
  if (!createTestFile(testFilePath, "test content")) {
    printLog(ERR, "Failed to create test file for isDirectory test");
    return false;
  }
  
  if (isDirectory(testFilePath) != false) {
    printLog(ERR, "isDirectory should return false for regular file");
    return false;
  }
  
  // Test with empty string
  if (isDirectory("") != false) {
    printLog(ERR, "isDirectory with empty string should return false");
    return false;
  }
  
  printLog(DEBUG, "isDirectory tests passed");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Tests the mkpath function
/// @return true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
static bool testMkpath(void) {
  printLog(DEBUG, "Testing mkpath function");
  
  // Test with NULL parameter
  if (mkpath(NULL, 0755) == 0) {
    printLog(ERR, "mkpath(NULL) should fail");
    return false;
  }
  
  // Test creating nested directory structure
  char nestedPath[MAX_PATH_LENGTH];
  snprintf(nestedPath, sizeof(nestedPath), "%s/level1/level2/level3", 
           TEST_BASE_DIR);
  
  if (mkpath(nestedPath, 0755) != 0) {
    printLog(ERR, "mkpath should succeed for nested directory creation");
    return false;
  }
  
  if (!isDirectory(nestedPath)) {
    printLog(ERR, "Created nested directory should exist");
    return false;
  }
  
  // Test creating existing directory (should succeed)
  if (mkpath(nestedPath, 0755) != 0) {
    printLog(ERR, "mkpath should succeed for existing directory");
    return false;
  }
  
  // Test with empty string
  if (mkpath("", 0755) == 0) {
    printLog(ERR, "mkpath with empty string should fail");
    return false;
  }
  
  printLog(DEBUG, "mkpath tests passed");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Tests the rmdirRecursive function
/// @return true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
static bool testRmdirRecursive(void) {
  printLog(DEBUG, "Testing rmdirRecursive function");
  
  // Test with NULL parameter
  if (rmdirRecursive(NULL) == 0) {
    printLog(ERR, "rmdirRecursive(NULL) should fail");
    return false;
  }
  
  // Create a complex directory structure with files
  char testDir[MAX_PATH_LENGTH];
  snprintf(testDir, sizeof(testDir), "%s/recursive_test", TEST_BASE_DIR);
  
  if (mkpath(testDir, 0755) != 0) {
    printLog(ERR, "Failed to create test directory for recursive removal");
    return false;
  }
  
  // Create subdirectories and files
  char subDir1[MAX_PATH_LENGTH];
  char subDir2[MAX_PATH_LENGTH];
  char file1[MAX_PATH_LENGTH];
  char file2[MAX_PATH_LENGTH];
  char file3[MAX_PATH_LENGTH];
  
  snprintf(subDir1, sizeof(subDir1), "%s/subdir1", testDir);
  snprintf(subDir2, sizeof(subDir2), "%s/subdir1/subdir2", testDir);
  snprintf(file1, sizeof(file1), "%s/file1.txt", testDir);
  snprintf(file2, sizeof(file2), "%s/subdir1/file2.txt", testDir);
  snprintf(file3, sizeof(file3), "%s/subdir1/subdir2/file3.txt", testDir);
  
  if (mkpath(subDir2, 0755) != 0) {
    printLog(ERR, "Failed to create nested test directories");
    return false;
  }
  
  if (!createTestFile(file1, "content1") ||
      !createTestFile(file2, "content2") ||
      !createTestFile(file3, "content3")) {
    printLog(ERR, "Failed to create test files for recursive removal");
    return false;
  }
  
  // Test recursive removal
  if (rmdirRecursive(testDir) != 0) {
    printLog(ERR, "rmdirRecursive should succeed");
    return false;
  }
  
  if (fileExists(testDir)) {
    printLog(ERR, "Directory should be removed after rmdirRecursive");
    return false;
  }
  
  // Test with non-existent directory
  if (rmdirRecursive("/tmp/nonexistent_dir_12345") == 0) {
    printLog(ERR, "rmdirRecursive should fail for non-existent directory");
    return false;
  }
  
  // Test with empty string
  if (rmdirRecursive("") == 0) {
    printLog(ERR, "rmdirRecursive with empty string should fail");
    return false;
  }
  
  printLog(DEBUG, "rmdirRecursive tests passed");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Tests the destroyDirectoryEntries function
/// @return true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
static bool testDestroyDirectoryEntries(void) {
  printLog(DEBUG, "Testing destroyDirectoryEntries function");
  
  // Test with NULL parameter
  char **result = destroyDirectoryEntries(NULL);
  if (result != NULL) {
    printLog(ERR, "destroyDirectoryEntries(NULL) should return NULL");
    return false;
  }
  
  // Create a directory with some entries to get a real array
  char testDir[MAX_PATH_LENGTH];
  snprintf(testDir, sizeof(testDir), "%s/destroy_test", TEST_BASE_DIR);
  
  if (mkpath(testDir, 0755) != 0) {
    printLog(ERR, "Failed to create test directory for destroy test");
    return false;
  }
  
  char file1[MAX_PATH_LENGTH];
  char file2[MAX_PATH_LENGTH];
  snprintf(file1, sizeof(file1), "%s/file1.txt", testDir);
  snprintf(file2, sizeof(file2), "%s/file2.txt", testDir);
  
  if (!createTestFile(file1, "content1") ||
      !createTestFile(file2, "content2")) {
    printLog(ERR, "Failed to create test files for destroy test");
    return false;
  }
  
  char **entries = getDirectoryEntries(testDir);
  if (entries == NULL) {
    printLog(ERR, "Failed to get directory entries for destroy test");
    return false;
  }
  
  // Test destroying the array
  result = destroyDirectoryEntries(entries);
  if (result != NULL) {
    printLog(ERR, "destroyDirectoryEntries should return NULL");
    return false;
  }
  
  printLog(DEBUG, "destroyDirectoryEntries tests passed");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Tests the getDirectoryEntries function
/// @return true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
static bool testGetDirectoryEntries(void) {
  printLog(DEBUG, "Testing getDirectoryEntries function");
  
  // Test with NULL parameter
  char **entries = getDirectoryEntries(NULL);
  if (entries != NULL) {
    printLog(ERR, "getDirectoryEntries(NULL) should return NULL");
    return false;
  }
  
  // Test with non-existent directory
  entries = getDirectoryEntries("/tmp/nonexistent_dir_12345");
  if (entries != NULL) {
    printLog(ERR, "getDirectoryEntries should return NULL for non-existent dir");
    return false;
  }
  
  // Create test directory with known contents
  char testDir[MAX_PATH_LENGTH];
  snprintf(testDir, sizeof(testDir), "%s/entries_test", TEST_BASE_DIR);
  
  if (mkpath(testDir, 0755) != 0) {
    printLog(ERR, "Failed to create test directory for entries test");
    return false;
  }
  
  // Create test files and subdirectories
  char file1[MAX_PATH_LENGTH];
  char file2[MAX_PATH_LENGTH];
  char subDir[MAX_PATH_LENGTH];
  
  snprintf(file1, sizeof(file1), "%s/test_file1.txt", testDir);
  snprintf(file2, sizeof(file2), "%s/test_file2.txt", testDir);
  snprintf(subDir, sizeof(subDir), "%s/test_subdir", testDir);
  
  if (!createTestFile(file1, "content1") ||
      !createTestFile(file2, "content2") ||
      mkpath(subDir, 0755) != 0) {
    printLog(ERR, "Failed to create test contents for entries test");
    return false;
  }
  
  // Get directory entries
  entries = getDirectoryEntries(testDir);
  if (entries == NULL) {
    printLog(ERR, "getDirectoryEntries should succeed for valid directory");
    return false;
  }
  
  int entryCount = countStringArray(entries);
  if (entryCount != 3) {
    printLog(ERR, "Expected there to be 3 entries but found %d.\n", entryCount);
    return false;
  }
  
  // Should contain at least our created items (. and .. might also be included)
  bool foundFile1 = stringInArray(entries, "test_file1.txt");
  bool foundFile2 = stringInArray(entries, "test_file2.txt");
  bool foundSubDir = stringInArray(entries, "test_subdir");
  
  if (!foundFile1 || !foundFile2 || !foundSubDir) {
    printLog(ERR, "getDirectoryEntries should return all created items");
    destroyDirectoryEntries(entries);
    return false;
  }
  
  destroyDirectoryEntries(entries);
  
  // Test with empty directory
  char emptyDir[MAX_PATH_LENGTH];
  snprintf(emptyDir, sizeof(emptyDir), "%s/empty_dir", TEST_BASE_DIR);
  
  if (mkpath(emptyDir, 0755) != 0) {
    printLog(ERR, "Failed to create empty test directory");
    return false;
  }
  
  entries = getDirectoryEntries(emptyDir);
  if (entries == NULL) {
    printLog(ERR, "getDirectoryEntries should succeed for empty directory");
    return false;
  }
  
  // Empty directory might still contain . and .. entries
  destroyDirectoryEntries(entries);
  
  // Test with empty string
  entries = getDirectoryEntries("");
  if (entries != NULL) {
    printLog(ERR, "getDirectoryEntries with empty string should return NULL");
    destroyDirectoryEntries(entries);
    return false;
  }
  
  printLog(DEBUG, "getDirectoryEntries tests passed");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Tests the selectDirectoryEntries function
/// @return true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
static bool testSelectDirectoryEntries(void) {
  printLog(DEBUG, "Testing selectDirectoryEntries function");
  
  // Test with NULL parameters
  char **result = selectDirectoryEntries(NULL, NULL, ENTRY_TYPE_FILE);
  if (result != NULL) {
    printLog(ERR, "selectDirectoryEntries with NULL path should return NULL");
    return false;
  }
  
  // Create test directory with mixed content
  char testDir[MAX_PATH_LENGTH];
  snprintf(testDir, sizeof(testDir), "%s/select_test", TEST_BASE_DIR);
  
  if (mkpath(testDir, 0755) != 0) {
    printLog(ERR, "Failed to create test directory for select test");
    return false;
  }
  
  // Create files and directories
  char file1[MAX_PATH_LENGTH];
  char file2[MAX_PATH_LENGTH];
  char dir1[MAX_PATH_LENGTH];
  char dir2[MAX_PATH_LENGTH];
  
  snprintf(file1, sizeof(file1), "%s/select_file1.txt", testDir);
  snprintf(file2, sizeof(file2), "%s/select_file2.txt", testDir);
  snprintf(dir1, sizeof(dir1), "%s/select_dir1", testDir);
  snprintf(dir2, sizeof(dir2), "%s/select_dir2", testDir);
  
  if (!createTestFile(file1, "content1") ||
      !createTestFile(file2, "content2") ||
      mkpath(dir1, 0755) != 0 ||
      mkpath(dir2, 0755) != 0) {
    printLog(ERR, "Failed to create test contents for select test");
    return false;
  }
  
  // Get all entries first
  char **allEntries = getDirectoryEntries(testDir);
  if (allEntries == NULL) {
    printLog(ERR, "Failed to get all directory entries for select test");
    return false;
  }
  
  // Test selecting files
  result = selectDirectoryEntries(testDir, (const char**)allEntries, 
                                  ENTRY_TYPE_FILE);
  if (result == NULL) {
    printLog(ERR, "selectDirectoryEntries should succeed for files");
    destroyDirectoryEntries(allEntries);
    return false;
  }
  
  bool foundFile1 = stringInArray(result, "select_file1.txt");
  bool foundFile2 = stringInArray(result, "select_file2.txt");
  bool foundDir1 = stringInArray(result, "select_dir1");
  bool foundDir2 = stringInArray(result, "select_dir2");
  
  if (!foundFile1 || !foundFile2) {
    printLog(ERR, "selectDirectoryEntries should find all files");
    destroyDirectoryEntries(result);
    destroyDirectoryEntries(allEntries);
    return false;
  }
  
  if (foundDir1 || foundDir2) {
    printLog(ERR, "selectDirectoryEntries for files should not return dirs");
    destroyDirectoryEntries(result);
    destroyDirectoryEntries(allEntries);
    return false;
  }
  
  destroyDirectoryEntries(result);
  
  // Test selecting directories
  result = selectDirectoryEntries(testDir, (const char**)allEntries, 
                                  ENTRY_TYPE_DIRECTORY);
  if (result == NULL) {
    printLog(ERR, "selectDirectoryEntries should succeed for directories");
    destroyDirectoryEntries(allEntries);
    return false;
  }
  
  foundFile1 = stringInArray(result, "select_file1.txt");
  foundFile2 = stringInArray(result, "select_file2.txt");
  foundDir1 = stringInArray(result, "select_dir1");
  foundDir2 = stringInArray(result, "select_dir2");
  
  if (!foundDir1 || !foundDir2) {
    printLog(ERR, "selectDirectoryEntries should find all directories");
    destroyDirectoryEntries(result);
    destroyDirectoryEntries(allEntries);
    return false;
  }
  
  if (foundFile1 || foundFile2) {
    printLog(ERR, "selectDirectoryEntries for dirs should not return files");
    destroyDirectoryEntries(result);
    destroyDirectoryEntries(allEntries);
    return false;
  }
  
  destroyDirectoryEntries(result);
  destroyDirectoryEntries(allEntries);
  
  // Test with empty entries array
  const char *emptyEntries[] = { NULL };
  result = selectDirectoryEntries(testDir, emptyEntries, ENTRY_TYPE_FILE);
  if (result == NULL) {
    printLog(ERR, "selectDirectoryEntries should handle empty entries array");
    return false;
  }
  
  if (countStringArray(result) != 0) {
    printLog(ERR, "selectDirectoryEntries should return empty array for empty input");
    destroyDirectoryEntries(result);
    return false;
  }
  
  destroyDirectoryEntries(result);
  
  printLog(DEBUG, "selectDirectoryEntries tests passed");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Tests the getDirectoryFiles function
/// @return true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
static bool testGetDirectoryFiles(void) {
  printLog(DEBUG, "Testing getDirectoryFiles function");
  
  // Test with NULL parameter
  char **files = getDirectoryFiles(NULL);
  if (files != NULL) {
    printLog(ERR, "getDirectoryFiles(NULL) should return NULL");
    return false;
  }
  
  // Test with non-existent directory
  files = getDirectoryFiles("/tmp/nonexistent_dir_12345");
  if (files != NULL) {
    printLog(ERR, "getDirectoryFiles should return NULL for non-existent dir");
    return false;
  }
  
  // Create test directory with files and subdirectories
  char testDir[MAX_PATH_LENGTH];
  snprintf(testDir, sizeof(testDir), "%s/files_test", TEST_BASE_DIR);
  
  if (mkpath(testDir, 0755) != 0) {
    printLog(ERR, "Failed to create test directory for files test");
    return false;
  }
  
  char file1[MAX_PATH_LENGTH];
  char file2[MAX_PATH_LENGTH];
  char subDir[MAX_PATH_LENGTH];
  
  snprintf(file1, sizeof(file1), "%s/files_test1.txt", testDir);
  snprintf(file2, sizeof(file2), "%s/files_test2.txt", testDir);
  snprintf(subDir, sizeof(subDir), "%s/files_subdir", testDir);
  
  if (!createTestFile(file1, "content1") ||
      !createTestFile(file2, "content2") ||
      mkpath(subDir, 0755) != 0) {
    printLog(ERR, "Failed to create test contents for files test");
    return false;
  }
  
  // Get directory files
  files = getDirectoryFiles(testDir);
  if (files == NULL) {
    printLog(ERR, "getDirectoryFiles should succeed for valid directory");
    return false;
  }
  
  bool foundFile1 = stringInArray(files, "files_test1.txt");
  bool foundFile2 = stringInArray(files, "files_test2.txt");
  bool foundSubDir = stringInArray(files, "files_subdir");
  
  if (!foundFile1 || !foundFile2) {
    printLog(ERR, "getDirectoryFiles should return all files");
    destroyDirectoryEntries(files);
    return false;
  }
  
  if (foundSubDir) {
    printLog(ERR, "getDirectoryFiles should not return directories");
    destroyDirectoryEntries(files);
    return false;
  }
  
  destroyDirectoryEntries(files);
  
  // Test with empty string
  files = getDirectoryFiles("");
  if (files != NULL) {
    printLog(ERR, "getDirectoryFiles with empty string should return NULL");
    destroyDirectoryEntries(files);
    return false;
  }
  
  printLog(DEBUG, "getDirectoryFiles tests passed");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Tests the getDirectoryDirectories function
/// @return true if all tests pass, false otherwise
///////////////////////////////////////////////////////////////////////////////
static bool testGetDirectoryDirectories(void) {
  printLog(DEBUG, "Testing getDirectoryDirectories function");
  
  // Test with NULL parameter
  char **directories = getDirectoryDirectories(NULL);
  if (directories != NULL) {
    printLog(ERR, "getDirectoryDirectories(NULL) should return NULL");
    return false;
  }
  
  // Test with non-existent directory
  directories = getDirectoryDirectories("/tmp/nonexistent_dir_12345");
  if (directories != NULL) {
    printLog(ERR, "getDirectoryDirectories should return NULL for non-existent dir");
    return false;
  }
  
  // Create test directory with files and subdirectories
  char testDir[MAX_PATH_LENGTH];
  snprintf(testDir, sizeof(testDir), "%s/dirs_test", TEST_BASE_DIR);
  
  if (mkpath(testDir, 0755) != 0) {
    printLog(ERR, "Failed to create test directory for directories test");
    return false;
  }
  
  char file1[MAX_PATH_LENGTH];
  char file2[MAX_PATH_LENGTH];
  char subDir1[MAX_PATH_LENGTH];
  char subDir2[MAX_PATH_LENGTH];
  
  snprintf(file1, sizeof(file1), "%s/dirs_file1.txt", testDir);
  snprintf(file2, sizeof(file2), "%s/dirs_file2.txt", testDir);
  snprintf(subDir1, sizeof(subDir1), "%s/dirs_subdir1", testDir);
  snprintf(subDir2, sizeof(subDir2), "%s/dirs_subdir2", testDir);
  
  if (!createTestFile(file1, "content1") ||
      !createTestFile(file2, "content2") ||
      mkpath(subDir1, 0755) != 0 ||
      mkpath(subDir2, 0755) != 0) {
    printLog(ERR, "Failed to create test contents for directories test");
    return false;
  }
  
  // Get directory directories
  directories = getDirectoryDirectories(testDir);
  if (directories == NULL) {
    printLog(ERR, "getDirectoryDirectories should succeed for valid directory");
    return false;
  }
  
  bool foundFile1 = stringInArray(directories, "dirs_file1.txt");
  bool foundFile2 = stringInArray(directories, "dirs_file2.txt");
  bool foundSubDir1 = stringInArray(directories, "dirs_subdir1");
  bool foundSubDir2 = stringInArray(directories, "dirs_subdir2");
  
  if (!foundSubDir1 || !foundSubDir2) {
    printLog(ERR, "getDirectoryDirectories should return all directories");
    destroyDirectoryEntries(directories);
    return false;
  }
  
  if (foundFile1 || foundFile2) {
    printLog(ERR, "getDirectoryDirectories should not return files");
    destroyDirectoryEntries(directories);
    return false;
  }
  
  destroyDirectoryEntries(directories);
  
  // Test with empty string
  directories = getDirectoryDirectories("");
  if (directories != NULL) {
    printLog(ERR, "getDirectoryDirectories with empty string should return NULL");
    destroyDirectoryEntries(directories);
    return false;
  }
  
  printLog(DEBUG, "getDirectoryDirectories tests passed");
  return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Main unit test function for DirectoryLib
/// @return true if all tests pass, false if any test fails
///////////////////////////////////////////////////////////////////////////////
bool directoryLibUnitTest(void) {
  printLog(DEBUG, "Starting DirectoryLib unit tests");
  
  // Setup test environment
  if (!setupTestEnvironment()) {
    printLog(ERR, "Failed to setup test environment");
    return false;
  }
  
  // Run all tests - stop on first failure
  if (!testIsDirectory()) {
    cleanupTestEnvironment();
    return false;
  }
  
  if (!testMkpath()) {
    cleanupTestEnvironment();
    return false;
  }
  
  if (!testRmdirRecursive()) {
    cleanupTestEnvironment();
    return false;
  }
  
  if (!testDestroyDirectoryEntries()) {
    cleanupTestEnvironment();
    return false;
  }
  
  if (!testGetDirectoryEntries()) {
    cleanupTestEnvironment();
    return false;
  }
  
  if (!testSelectDirectoryEntries()) {
    cleanupTestEnvironment();
    return false;
  }
  
  if (!testGetDirectoryFiles()) {
    cleanupTestEnvironment();
    return false;
  }
  
  if (!testGetDirectoryDirectories()) {
    cleanupTestEnvironment();
    return false;
  }
  
  // Cleanup test environment
  if (!cleanupTestEnvironment()) {
    printLog(ERR, "Failed to cleanup test environment");
    return false;
  }
  
  printLog(DEBUG, "All DirectoryLib unit tests passed successfully");
  return true;
}
