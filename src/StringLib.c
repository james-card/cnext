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

#include "StringLib.h"
#include "OsApi.h"
#ifdef DS_LOGGING_ENABLED
#include "LoggingLib.h"
#else
#undef printLog
#define printLog(...) {}
#define printStackTrace(...) {}
#define logFile stderr
#define LOG_MALLOC_FAILURE(...) {}
#endif

/// @def PAGES_TO_READ
///
/// @brief Number of pages to read/write to/from a file at a time.
#define PAGES_TO_READ 1

/// @def PAGE_SIZE
///
/// @brief Size in bytes of one page of data.
#define PAGE_SIZE 4096

/// @var fieldDelim
///
/// @brief The common delimiter used to separate fields of data in a string.
const char *fieldDelim = "`";

/// @var recordDelim
///
/// @brief The common delimiter used to separate records of data in a string.
const char *recordDelim = "\n";

/// @fn char *indentText(const char *inputText, u32 columns)
///
/// @brief Indents each line in a body of text.
///
/// @param inputText is the body of text to indent.
/// @param columns is the number of columns (spaces) to indent.
///
/// @return Returns a string with the text indented.
char *indentText(const char *inputText, u32 columns) {
  char *indentedText = NULL;
  char *indentSpacing = (char*) malloc(1);
  char *newlineLocation = NULL;
  char *input = NULL, *originalInput = NULL;
  u32 i = 0;
  
  printLog(FLOOD, "ENTER indentText(inputText=\"%s\", columns=%u)\n",
    inputText, columns);
  
  straddstr(&input, inputText);
  originalInput = input;
  
  if (inputText) {
    // Construct the indent spacing.
    *indentSpacing = '\0';
    for (i = 0; i < columns; i++) {
      straddstr(&indentSpacing, " ");
    }
    
    // Indent the input text.
    straddstr(&indentedText, indentSpacing);
    for (newlineLocation = (char*) strchr(input, '\n');
      newlineLocation != NULL && *(newlineLocation + 1) != '\0';
      newlineLocation = (char*) strchr(input, '\n')) {
      
      *newlineLocation = '\0';
      straddstr(&indentedText, input);
      straddstr(&indentedText, "\n");
      input= newlineLocation + 1;
      straddstr(&indentedText, indentSpacing);
    }
    if (*input!= '\0') {
      straddstr(&indentedText, input);
    }
  }
  
  indentSpacing = stringDestroy(indentSpacing);
  originalInput = stringDestroy(originalInput);
  input = NULL;
  printLog(FLOOD, "EXIT indentText(inputText=\"%s\", columns=%u) = {%s}\n",
    inputText, columns, indentedText);
  return indentedText;
}

/// @fn void unescapeString(char *inputString)
///
/// @brief This function unescapes a URL-encoded string.  The string is
///   modified in place.
///
/// @param inputString is the URL-encoded string to unescape.
///
/// @return There is no return value for this function.
void unescapeString(char *inputString) {
  size_t i = 0, j = 0;
  
  printLog(FLOOD, "ENTER unescapeString(inputString=\"%s\")\n", inputString);
  
  if (inputString == NULL) {
    printLog(ERR, "NULL pointer provided to unescapeString.\n");
    printLog(FLOOD, "EXIT unescapeString(inputString=NULL) = {}\n");
    return;
  }
  
  size_t inputStringLength = strlen(inputString);
  
  for (i = 0, j = 0;
    (i < inputStringLength)
      && (j < inputStringLength)
      && (inputString[j] != '\0');
    i++, j++
  ) {
    inputString[i] = inputString[j];
    if (inputString[j] == '%') {
      char tempChar = hexToChar(&inputString[j + 1]);
      if (tempChar != '\0') {
        inputString[i] = tempChar;
        j += 2;
      }
    } else if (inputString[j] == '&') {
      char tempChar = unampersand(&inputString[j]);
      if (tempChar != '\0') {
        inputString[i] = tempChar;
        while ((inputString[j] != 0) && (inputString[j] != ';')) {
          j++;
        }
      }
    } else if (inputString[j] == '+') {
      inputString[i] = ' ';
    }
  }
  inputString[i] = '\0';
  
  printLog(FLOOD, "EXIT unescapeString(inputString=\"%s\") = {}\n", inputString);
  return;
}

/// @fn void plusToSpace(char *inputString)
///
/// @brief This function converts the '+' characters in a url string to spaces.
///   The string is modified in place.
///
/// @param inputString is the string to modify in place.
///
/// @return There is no return value for this function.
void plusToSpace(char *inputString) {
  int i;
  
  printLog(TRACE, "ENTER plusToSpace(inputString=\"%s\")\n", inputString);
  
  if (inputString != NULL) {
    printLog(DEBUG, "inputString is NOT NULL.\n");
    for (i = 0; inputString[i] != '\0'; i++) {
      if (inputString[i] == '+') {
        inputString[i] = ' ';
      }
    }
  } else {
    printLog(DEBUG, "inputString is NULL.\n");
  }
  
  printLog(TRACE, "EXIT plusToSpace(inputString=\"%s\") = {}\n", inputString);
}

/// @fn void dosToUnix(char *str)
///
/// @brief This function removes ^M characters in strings.  The string is
///   modified in place.
///
/// @param str is the string to modify.
///
/// @return There is no return value for this function.
void dosToUnix(char *str) {
  int i = 0, len = (int) strlen(str);
  char *pos = str;
  
  printLog(TRACE, "ENTER dosToUnix(str=\"%s\")\n", str);
  
  for (i = 0; i < len; i++) {
    if (!(str[i] == '\r' && i < len - 1 && str[i+1] == '\n')) {
      *(pos++) = str[i];
    }
  }
  *pos = '\0';
  
  printLog(TRACE, "EXIT dosToUnix(str=\"%s\") = {}\n", str);
}

/// @fn char* straddstr(char **buffer, const char *input)
///
/// @brief This function appends the string input to the string referenced by
///   buffer.
///
/// @param buffer is a pointer to a string pointer (a double pointer).
/// @param input is a pointer to the string which should be appended to buffer.
///
/// @return Returns a status integer.  0 is success, all other values are
///   failures.
char* straddstr(char **buffer, const char *input) {
  printLog(FLOOD, "ENTER straddstr(*buffer=\"%s\", input=\"%s\")\n",
    (buffer != NULL) ? ((*buffer != NULL) ? *buffer : "NULL") : "NULL",
    (input != NULL) ? input : "NULL");
  
  if ((input != NULL) && (buffer != NULL)) {
    if (*buffer == NULL) {
      *buffer = (char *) malloc(strlen(input) + 1);
      if (*buffer != NULL) {
        strcpy(*buffer, input);
      } else {
        // Nothing else we can do.
        return *buffer;
      }
    } else if (strlen(input) > 0) {
      size_t bufferLength = strlen(*buffer);
      void *check = realloc(*buffer, bufferLength + strlen(input) + 1);
      if (check == NULL) {
        fprintf(stderr, "Error reallocating buffer in straddstr\n");
        fprintf(stderr, "strlen(*buffer) = %llu, strlen(input) = %llu\n",
          llu(strlen(*buffer)), llu(strlen(input)));
        fflush(stderr);
        fprintf(logFile, "Error reallocating buffer in straddstr\n");
        fprintf(logFile, "strlen(*buffer) = %llu, strlen(input) = %llu\n",
          llu(strlen(*buffer)), llu(strlen(input)));
        fflush(logFile);
        printStackTrace(CRITICAL);
        
        *buffer = stringDestroy(*buffer);
        
        return *buffer;
      }

      if (check != *buffer) {
        *buffer = (char*) check;
      }
      strcpy(&((*buffer)[bufferLength]), input);
    }
  } else if ((buffer != NULL) && (*buffer == NULL)) {
    // Calling functions assume that this function allocates memory.  Don't
    // disappoint them.
    *buffer = (char *) malloc(1);
    if (*buffer != NULL) {
      **buffer = '\0';
    } else {
      // Nothing else we can do.
      return *buffer;
    }
  }
  
  printLog(FLOOD, "EXIT straddstr(*buffer=\"%s\", input=\"%s\") = {%p}\n",
    (buffer != NULL) ? ((*buffer != NULL) ? *buffer : "NULL") : "NULL",
    (input != NULL) ? input : "NULL", *buffer);
  
  if (buffer != NULL) {
    return *buffer;
  } else {
    return NULL;
  }
}

/// @fn char* straddchr(char **buffer, char input)
///
/// @brief This function appends the character input to the string referenced
/// by buffer.
///
/// @param buffer is a pointer to a string pointer (a double pointer).
/// @param input is a single character.
///
/// @return Returns a status integer.  0 is success, all other values are
/// failures.
char* straddchr(char **buffer, char input) {
  char *returnValue = NULL;
  char inputString[2];
  
  printLog(FLOOD, "ENTER straddchr(*buffer=\"%s\", input='%c')\n",
    (buffer != NULL) ? ((*buffer != NULL) ? *buffer : "NULL") : "NULL", input);
  
  inputString[0] = input;
  inputString[1] = '\0';
  returnValue = straddstr(buffer, inputString);
  
  printLog(FLOOD, "EXIT straddchr(*buffer=\"%s\", input='%c') = {%p}\n",
    (buffer != NULL) ? ((*buffer != NULL) ? *buffer : "NULL") : "NULL", input,
    returnValue);
  return returnValue;
}

/// @fn u64 dataAddData(void **buffer, u64 bufferLength, const volatile void *input, u64 inputLength)
///
/// @brief This function appends the contents of a memory block to a memory
///   buffer.
///
/// @param buffer is a double-pointer to a block of memory.
/// @param bufferLength is the size of the memory block pointed to by *buffer.
/// @param input is a pointer to a memory block which should be appended to
///   *buffer.
/// @param inputLength is the size of the memory block pointed to by input.
///
/// @return Returns the new size of *buffer.
u64 dataAddData(void **buffer, u64 bufferLength, const volatile void *input, u64 inputLength) {
  void *check = NULL;
  
  printLog(FLOOD, "ENTER dataAddData(*buffer=%p, bufferLength=%llu, input=%p, inputLength=%llu)\n",
    (buffer) ? *buffer : (void*) NULL,
    llu(bufferLength),
    input,
    llu(inputLength));
  
  if ((buffer != NULL) && (input != NULL) && (inputLength != 0)) {
    if (*buffer == NULL) {
      *buffer = malloc(inputLength);
      if (*buffer != NULL) {
        memcpy(*buffer, (const void*) input, inputLength);
        bufferLength = inputLength;
      }
    } else {
      check = realloc(*buffer, bufferLength + inputLength);
      if (check == NULL) {
        fprintf(stderr, "Error reallocating buffer in dataAddData\n");
        fprintf(stderr, "bufferLength = %llu, inputLength = %llu\n",
          llu(bufferLength), llu(inputLength));
        fflush(stderr);
        fprintf(logFile, "Error reallocating buffer in dataAddData\n");
        fprintf(logFile, "bufferLength = %llu, inputLength = %llu\n",
          llu(bufferLength), llu(inputLength));
        fflush(logFile);
        printStackTrace(CRITICAL);
        
        *buffer = pointerDestroy(*buffer);
        
        return 0;
      }

      if (check != *buffer) {
        *buffer = check;
      }
      memcpy((void*)(&(((char*)(*buffer))[bufferLength])), (const void*) input,
        inputLength);
      bufferLength += inputLength;
    }
  }

  printLog(FLOOD, "EXIT dataAddData(*buffer=%p, bufferLength=%llu, input=%p, inputLength=%llu) = {%llu}\n",
    (buffer) ? *buffer : (void*) NULL,
    llu(bufferLength),
    input,
    llu(inputLength),
    llu(bufferLength));
  return bufferLength;
}

/// @fn u64 getFileLength(const char *fullPath)
///
/// @brief Get the size, in bytes, of a file on the file system.
///
/// @param fullPath A string containing the full path of the file to get the
///   size of.
///
/// @return Returns the number of bytes in the specified file on success,
/// -1 on failure.
i64 getFileLength(const char *fullPath) {
  printLog(TRACE,
    "ENTER getFileLength(fullPath=\"%s\")\n",
    (fullPath != NULL) ? fullPath : "NULL"
  );
  
  // Open the file.
  FILE *requestedFile = NULL;
  if (fullPath != NULL) {
    requestedFile = fopen(fullPath, "rb");
  }
  if (requestedFile == NULL) {
    printLog(DEBUG, "Could not open file \"%s\" in getFileLength.\n",
      (fullPath != NULL) ? fullPath : "NULL");
    printLog(TRACE,
      "EXIT getFileLength(fullPath=\"%s\") = {-1}\n",
      (fullPath != NULL) ? fullPath : "NULL");
    return -1;
  }
  
  fseek(requestedFile, 0, SEEK_END);
  i64 fileSize = (i64) ftell(requestedFile);
  fclose(requestedFile); requestedFile = NULL;
  
  printLog(TRACE,
    "EXIT getFileLength(fullPath=\"%s\") = {%llu}\n",
    (fullPath != NULL) ? fullPath : "NULL", llu(fileSize));
  return fileSize;
}

/// @fn Bytes getFileContent_(const char *fullPath, i64 start, u32 length, ...)
///
/// @brief Retrieves the content of a file.
///
/// @param fullPath The full path to the file to get.
/// @param start If non-negative, start is the number of bytes from the start of
///   the file to begin reading from.  If negative, start is the number of
///   bytes from the end of the file to begin reading from.
/// @param length The number of bytes to read.  If 0, file contents from
///   start to the end of the file are read.
/// @param ... All further parameters are ignored.
///
/// @note This function is wrapped with a macro of the same name, without the
/// leading underscore, that automatically provieds 0 for the values of start
/// and length.
///
/// @return Returns a Bytes object with the contents read in on success,
/// NULL on failure.
Bytes getFileContent_(const char *fullPath, i64 start, i64 length, ...) {
  FILE *requestedFile = NULL;
  Bytes returnValue = NULL;
  
  printLog(TRACE,
    "ENTER getFileContent(fullPath=\"%s\", start=%lld, length=%lld)\n",
    (fullPath != NULL) ? fullPath : "NULL", lli(start), lli(length));
  
  // Open the file.
  if (fullPath != NULL) {
    requestedFile = fopen(fullPath, "rb");
  }
  if (requestedFile == NULL) {
    printLog(DEBUG, "Could not open file \"%s\" in getFileContent.\n",
      (fullPath != NULL) ? fullPath : "NULL");
    printLog(TRACE,
      "EXIT getFileContent(fullPath=\"%s\", start=%lld, length=%lld) = {NULL}\n",
      (fullPath != NULL) ? fullPath : "NULL", lli(start), lli(length));
    return NULL;
  }
  
  // Get the file size and allocate the buffer.
  fseek(requestedFile, 0, SEEK_END);
  i64 fileSize = (i64) ftell(requestedFile);
  if (start > fileSize) {
    // Not an error, but nothing to read.
    fclose(requestedFile); requestedFile = NULL;
    printLog(TRACE,
      "EXIT getFileContent(fullPath=\"%s\", start=%lld, length=%lld) = {NULL}\n",
      (fullPath != NULL) ? fullPath : "NULL", lli(start), lli(length));
    return NULL;
  }
  
  // Adjust the start and length.
  if (start < 0) {
    start += fileSize;
  }
  fseek(requestedFile, start, SEEK_SET);
  if (length == 0) {
    length = fileSize - start;
    if (length <= 0) {
      // Nothing to read.
      fclose(requestedFile); requestedFile = NULL;
      printLog(TRACE,
        "EXIT getFileContent(fullPath=\"%s\", start=%lld, length=%lld) = {NULL}\n",
        (fullPath != NULL) ? fullPath : "NULL", lli(start), lli(length));
      return NULL;
    }
  }
  
  returnValue = (Bytes) malloc(length + sizeof(BytesHeader) + 1);
  if (returnValue == NULL) {
    fclose(requestedFile); requestedFile = NULL;
    LOG_MALLOC_FAILURE();
    printLog(TRACE,
      "EXIT getFileContent(fullPath=\"%s\", start=%lld, length=%lld) = {NULL}\n",
      (fullPath != NULL) ? fullPath : "NULL", lli(start), lli(length));
    return NULL;
  }
  
  // Read the file content.
  if (fread((void*) (returnValue + sizeof(BytesHeader)),
    (size_t) length, 1, requestedFile) != 1
  ) {
    // We haven't moved the pointer to be a proper Bytes object yet, so use
    // pointerDestroy instead of bytesDestroy here.
    returnValue = (Bytes) pointerDestroy(returnValue);
    fclose(requestedFile); requestedFile = NULL;
    printLog(ERR, "Could not read %lld Bytes from \"%s\"\n",
      lld(length), fullPath);
    printLog(TRACE,
      "EXIT getFileContent(fullPath=\"%s\", start=%lld, length=%lld) = {NULL}\n",
      (fullPath != NULL) ? fullPath : "NULL", lli(start), lli(length));
    return NULL;
  }
  fclose(requestedFile); requestedFile = NULL;
  returnValue = (Bytes) &(((BytesHeader*) returnValue)[1]);
  bytesSetLength(returnValue, length);
  bytesSetSize(returnValue, length + 1);
  returnValue[length] = '\0';
  
  printLog(TRACE,
    "EXIT getFileContent(fullPath=\"%s\", start=%lld, length=%lld) = {%p}\n",
    (fullPath != NULL) ? fullPath : "NULL", lli(start), lli(length), returnValue);
  return returnValue;
}

/// @fn i64 putFileContent_(const char *fullPath, const volatile void *dataBuffer, i64 dataLength, i64 start, ...)
///
/// @brief Writes the content of a buffer to a file (overwrites existing
/// content).
///
/// @param fullPath The full path to the file to write out.
/// @param dataBuffer A pointer to the block of memory to read from.
/// @param dataLength The length of the block of memory at dataBuffer.
/// @param start If non-negative, start is the number of bytes from the start of
///   the file to begin writing at.  If negative, start is the number of
///   bytes from the end of the file to begin writing at.  The file will first
///   be resized to the starting position before writing.
/// @param ... All further parameters are ignored.
///
/// @note This function is wrapped by a macro of the same name (minus the
/// trailing underscore) that automatically provides 0 for the start parameter.
///
/// @return Returns the number of bytes written.
i64 putFileContent_(
  const char *fullPath, const volatile void *dataBuffer, i64 dataLength, i64 start, ...
) {
  i64 totalBytesWritten = 0, pagesWritten = 0;
  FILE *requestedFile = NULL;
  i64 quotient = 0, remainder = 0;
  
  printLog(TRACE, "ENTER putFileContent(fullPath=\"%s\", *dataBuffer=%p, dataLength=%lld)\n",
    (fullPath != NULL) ? fullPath : "NULL",
    dataBuffer,
    lli(dataLength));
  
  if ((fullPath == NULL) || (dataBuffer == NULL)) {
    printLog(ERR, "One or more NULL parameters.\n");
    printLog(TRACE, "EXIT putFileContent(fullPath=\"%s\", *dataBuffer=%p, dataLength=%lld) = {%lld}\n",
      (fullPath != NULL) ? fullPath : "NULL",
      dataBuffer,
      lli(dataLength),
      llu(totalBytesWritten));
    return 0;
  }
  
  quotient = dataLength / PAGE_SIZE;
  remainder = dataLength % PAGE_SIZE;
  
  if (start == 0) {
    // The expected case.
    requestedFile = fopen(fullPath, "wb");
  } else {
    if (start < 0) {
      // Start is the number of bytes from the end.
      i64 fileLength = getFileLength(fullPath);
      if (fileLength > 0) {
        // This is the expected case since start is non-zero.
        start += fileLength;
      } else {
        // The file does not exist and a negative start value does not make
        // sense.  Set it to zero.
        start = 0;
      }
    }
    
    requestedFile = fopen(fullPath, "ab");
    if (requestedFile != NULL) {
      if (ftruncate(fileno(requestedFile), start) == 0) {
        fseek(requestedFile, 0, SEEK_END);
      } else {
        // We can't put the file content where directed.  Fail.
        printLog(ERR, "Could not truncate file to %lld bytes.\n", lli(start));
        fclose(requestedFile); requestedFile = NULL;
      }
    } // else we can't open the file for writing.  Fail below.
  }
  
  // Write the file content.
  if (requestedFile != NULL) {
    pagesWritten = fwrite((const void*) dataBuffer, PAGE_SIZE, quotient, requestedFile);
    totalBytesWritten += pagesWritten * PAGE_SIZE;
    dataBuffer = ((char*) dataBuffer) + totalBytesWritten;
    pagesWritten = fwrite((void*) dataBuffer, remainder, 1, requestedFile);
    totalBytesWritten += remainder;
    fflush(requestedFile);
    fclose(requestedFile);
  } else {
    printLog(ERR, "Could not open file \"%s\" in putFileContent\n", fullPath);
  }
  
  printLog(TRACE, "EXIT putFileContent(fullPath=\"%s\", *dataBuffer=%p, dataLength=%lld) = {%lld}\n",
    fullPath,
    dataBuffer,
    lli(dataLength),
    lli(totalBytesWritten));
  return totalBytesWritten;
}

/// @fn u64 getFileLine(FILE *requestedFile, char **dataBuffer)
///
/// @brief Retrieves a single line of input (including the \n) from an open
/// file no matter how long the line is.
///
/// @param requestedFile is the file pointer to the file opened in "rb" mode.
/// @param dataBuffer is a double-pointer to the string to append to.
///
/// @return Returns the length of the contents read in.
u64 getFileLine(FILE *requestedFile, char **dataBuffer) {
  u64 returnValue = 0;
  
  printLog(TRACE, "ENTER getFileLine(requestedFile=%p, *dataBuffer=%p)\n",
    requestedFile, (dataBuffer != NULL) ? *dataBuffer : NULL);
  
  // Get the file content.
  if (requestedFile != NULL && dataBuffer != NULL) {
    char inputBuffer[PAGE_SIZE], *status = (char*) 1;
    inputBuffer[PAGE_SIZE - 1] = '\0';
    inputBuffer[PAGE_SIZE - 2] = '\0';
    
    printLog(DEBUG, "Getting first page.\n");
    status = fgets(inputBuffer, PAGE_SIZE, requestedFile);
    printLog(DEBUG, "Got first page.\n");
    while (status != NULL && !feof(requestedFile) &&
      inputBuffer[PAGE_SIZE - 2] != '\0') {
      printLog(DEBUG, "In requestedFile while.\n");
      straddstr(dataBuffer, inputBuffer);
      inputBuffer[PAGE_SIZE - 2] = '\0';
      printLog(DEBUG, "Getting next page in while.\n");
      status = fgets(inputBuffer, PAGE_SIZE - 1, requestedFile);
    }
    printLog(DEBUG, "Got all pages.\n");
    if (status != NULL) {
      straddstr(dataBuffer, inputBuffer);
      int dataBufferLength = (int) strlen(*dataBuffer);
      if ((*dataBuffer)[dataBufferLength - 1] == '\n') {
        (*dataBuffer)[dataBufferLength - 1] = '\0';
        dataBufferLength--;
      }
      returnValue = dataBufferLength;
    }
  } else if (requestedFile == NULL) {
    printLog(TRACE, "No valid file passed in.\n");
    printLog(TRACE, "EXIT getFileLine(requestedFile=%p, *dataBuffer=%p) = {%d}\n",
      requestedFile, *dataBuffer, 0);
    return 0;
  } else if (dataBuffer == NULL) {
    printLog(TRACE, "No valid data buffer passed in.\n");
    printLog(TRACE, "EXIT getFileLine(requestedFile=%p, *dataBuffer=%p) = {%d}\n",
      requestedFile, (void*) NULL, 0);
    return 0;
  }
  
  printLog(TRACE, "EXIT getFileLine(requestedFile=%p, *dataBuffer=%p) = {%llu}\n",
    requestedFile, (dataBuffer != NULL) ? *dataBuffer : NULL, llu(returnValue));
  return returnValue;
}

/// @fn char unampersand(const char *inputString)
///
/// @brief This function converts HTML ampersand syntax to standard ASCII.
///
/// @param inputString is the command to convert.
///
/// @return Returns the converted character on success.
///   NULL character on failure.
char unampersand(const char *inputString) {
  char character = '\0';
  printLog(FLOOD, "ENTER unampersand(inputString=\"%s\")\n", inputString);
  
  if (strncmp(inputString, "&quot;", 6) == 0) {
    character = '"';
  } else if (strncmp(inputString, "&lt;", 3) == 0) {
    character = '<';
  } else if (strncmp(inputString, "&gt;", 3) == 0) {
    character = '>';
  } else if (strncmp(inputString, "&apos;", 6) == 0) {
    character = '\'';
  } else if (strncmp(inputString, "&amp;", 5) == 0) {
    character = '&';
  }
  
  printLog(FLOOD, "EXIT unampersand(inputString=\"%s\") = {%c}\n", inputString, character);
  return character;
}

/// @fn char hexToChar(const char *inputString)
///
/// @brief This function unescapes a singe character code in a url string to a
/// single character.  It supports the function unescapeString.
///
/// @param inputString is a pointer to the beginning of a % encoded two-digit
///   hexadecimal value.
///
/// @return Returns the character that's been converted.
char hexToChar(const char *inputString) {
  unsigned char character = '\0';
  
  printLog(FLOOD, "ENTER hexToChar(inputString=\"%s\")\n", inputString);
  
  if (inputString == NULL) {
    printLog(WARN, "NULL provided to hexToChar.\n");
    printLog(FLOOD, "EXIT hexToChar(inputString=NULL) = {\\0}\n");
    return '\0';
  }
  
  if ((inputString[0] >= 'A') && (inputString[0] <= 'F')) {
    character = (((unsigned char) inputString[0]) - ((unsigned char) 'A')) + 10;
  } else if ((inputString[0] >= 'a') && (inputString[0] <= 'f')) {
    character = (((unsigned char) inputString[0]) - ((unsigned char) 'a')) + 10;
  } else if ((inputString[0] >= '0') && (inputString[0] <= '9')) {
    character = ((unsigned char) inputString[0]) - ((unsigned char) '0');
  } else {
    // Invalid input
    printLog(FLOOD, "EXIT hexToChar(inputString=\"%s\") = {\\0}\n",
      inputString);
    return '\0';
  }
  
  character <<= 4; // *= 16;
  
  if ((inputString[1] >= 'A') && (inputString[1] <= 'F')) {
    character += (((unsigned char) inputString[1]) - ((unsigned char) 'A')) + 10;
  } else if ((inputString[1] >= 'a') && (inputString[1] <= 'f')) {
    character += (((unsigned char) inputString[1]) - ((unsigned char) 'a')) + 10;
  } else if ((inputString[1] >= '0') && (inputString[1] <= '9')) {
    character += ((unsigned char) inputString[1]) - ((unsigned char) '0');
  } else {
    // Invalid input
    printLog(FLOOD, "EXIT hexToChar(inputString=\"%s\") = {\\0}\n",
      inputString);
    return '\0';
  }
  
  printLog(FLOOD, "EXIT hexToChar(inputString=\"%s\") = {%c}\n",
    inputString, character);
  return character;
}

/// @fn char *strReplaceOneStr(const char *inputString, const char *findWhat, const char *replaceText, bool *replacementMade)
///
/// @brief Replace every occurrance of findWhat in inputString with replaceText.
///
/// @param inputString The string to examine.
/// @param findWhat The text to find in inputString.  If '*' is the last
///   character (and not preceded with a '\'), then the matching portion of the
///   inputString and evereything thereafter is replaced with the replaceText.
/// @param replaceText The text that is to replace findWhat in inputString.
/// @param replacementMade A pointer to a Boolean variable that will be set to
///   true if findWhat was found and a replacement was made and false otherwise.
///   This parameter is optional and may be NULL.
///
/// @return Returns a new string that has all instances of findWhat replaced
///   with replaceText on success.  NULL on failure.
char *strReplaceOneStr(
  const char *inputString, const char *findWhat, const char *replaceText,
  bool *replacementMade
) {
  char *returnValue = NULL;
  
  printLog(FLOOD,
    "ENTER strReplaceOneStr(inputString=\"%s\", findWhat=\"%s\", "
    "replaceText=\"%s\")\n",
    inputString,
    findWhat,
    replaceText);
  
  if (replacementMade != NULL) {
    *replacementMade = false;
  }
  
  if ((inputString == NULL) || (replaceText == NULL) || (findWhat == NULL)) {
    // Nothing to replace.  Provide what was given.
    straddstr(&returnValue, inputString);
    printLog(FLOOD,
      "EXIT strReplaceOneStr(inputString=\"%s\", findWhat=\"%s\", "
      "replaceText=\"%s\") = {\"%s\"}\n",
      inputString,
      findWhat,
      replaceText,
      returnValue);
    return returnValue;
  }
  
  int findWhatLength = strlen(findWhat);
  bool replaceToEnd = false;
  char *findWhatCopy = NULL;
  straddstr(&findWhatCopy, findWhat);
  if (findWhat[findWhatLength - 1] == '*') {
    if (findWhat[findWhatLength - 2] == '\\') {
      // We're looking for a literal '*' at the end of findWhat.
      findWhatCopy[findWhatLength - 2] = '*';
      findWhatCopy[findWhatLength - 1] = '\0';
      findWhatLength--;
    } else {
      // We're looking for everything from findWhat to the end of the string.
      findWhatCopy[findWhatLength - 1] = '\0';
      findWhatLength--;
      // This means we only need to do one pass.
      replaceToEnd = true;
    }
  }
  
  const char *currentString = inputString;
  Bytes nonReplacedString = getBytesBetween(currentString, "", findWhatCopy);
  if (nonReplacedString != NULL) {
    // Concatenate the nonReplacedString with findWhat.
    straddstr(&returnValue, (char*) nonReplacedString);
    straddstr(&returnValue, replaceText);
    
    if (replaceToEnd == false) {
      // Concatenate the new string with what's left of the input string.
      currentString += bytesLength(nonReplacedString);
      currentString += findWhatLength;
      straddstr(&returnValue, currentString);
    }
    nonReplacedString = bytesDestroy(nonReplacedString);
    
    if (replacementMade != NULL) {
      *replacementMade = true;
    }
  } else {
    // findWhat not found.  Return a copy of the input string.
    straddstr(&returnValue, inputString);
  }
  findWhatCopy = stringDestroy(findWhatCopy);
  
  printLog(FLOOD,
    "EXIT strReplaceOneStr(inputString=\"%s\", findWhat=\"%s\", "
    "replaceText=\"%s\") = {\"%s\"}\n",
    inputString,
    findWhat,
    replaceText,
    returnValue);
  return returnValue;
}

/// @fn char *strReplaceStr(const char *inputString, const char *findWhat, const char *replaceText)
///
/// @brief Replace every occurrance of findWhat in inputString with replaceText.
///
/// @param inputString is the string to examine
/// @param findWhat is the text to find in str.  If '*' is the last character,
///   then the matching portion of the inputString and evereything thereafter
///   is replaced with the replaceText.
/// @param replaceText is the text that is to replace findWhat in str
///
/// @return Returns a new string that has all instances of findWhat replaced
///   with replaceText on success.  NULL on failure.
char *strReplaceStr(
  const char *inputString, const char *findWhat, const char *replaceText
) {
  char *returnValue = NULL;
  
  printLog(FLOOD,
    "ENTER strReplaceStr(inputString=\"%s\", findWhat=\"%s\", "
    "replaceText=\"%s\")\n",
    inputString,
    findWhat,
    replaceText);
  
  if ((inputString == NULL) || (replaceText == NULL) || (findWhat == NULL)) {
    // Nothing to replace.  Provide what was given.
    straddstr(&returnValue, inputString);
    printLog(FLOOD,
      "EXIT strReplaceStr(inputString=\"%s\", findWhat=\"%s\", "
      "replaceText=\"%s\") = {\"%s\"}\n",
      inputString,
      findWhat,
      replaceText,
      returnValue);
    return returnValue;
  }
  
  int findWhatLength = strlen(findWhat);
  bool replaceToEnd = false;
  char *findWhatCopy = NULL;
  straddstr(&findWhatCopy, findWhat);
  if (findWhat[findWhatLength - 1] == '*') {
    if (findWhat[findWhatLength - 2] == '\\') {
      // We're looking for a literal '*' at the end of findWhat.
      findWhatCopy[findWhatLength - 2] = '*';
      findWhatCopy[findWhatLength - 1] = '\0';
      findWhatLength--;
    } else {
      // We're looking for everything from findWhat to the end of the string.
      findWhatCopy[findWhatLength - 1] = '\0';
      findWhatLength--;
      // This means we only need to do one pass.
      replaceToEnd = true;
    }
  }
  
  const char *currentString = inputString;
  do {
    Bytes nonReplacedBytes = getBytesBetween(currentString, "", findWhatCopy);
    if (nonReplacedBytes == NULL) {
      // findWhat not found.
      nonReplacedBytes = bytesDestroy(nonReplacedBytes);
      straddstr(&returnValue, currentString);
      break;
    }
    
    straddstr(&returnValue, str(nonReplacedBytes));
    currentString += bytesLength(nonReplacedBytes);
    currentString += findWhatLength;
    nonReplacedBytes = bytesDestroy(nonReplacedBytes);
    straddstr(&returnValue, replaceText);
  } while ((replaceToEnd == false) && (*currentString != '\0'));
  findWhatCopy = stringDestroy(findWhatCopy);
  
  printLog(FLOOD,
    "EXIT strReplaceStr(inputString=\"%s\", findWhat=\"%s\", "
    "replaceText=\"%s\") = {\"%s\"}\n",
    inputString,
    findWhat,
    replaceText,
    returnValue);
  return returnValue;
}

/// @fn char *escapeString(const char *inputString)
///
/// @brief Converts unwanted characters in a string to their escaped,
///   hexadecimal equivalents.
///
/// @param inputString is the string to convert
///
/// @return Returns a newly-allocated string that has been escaped on success,
/// NULL on failure.
char *escapeString(const char *inputString) {
  char *returnValue = NULL;
  
  printLog(FLOOD, "ENTER escapeString(inputString=\"%s\")\n", inputString);
  
  if (inputString != NULL) {
    returnValue = escapeData(inputString, strlen(inputString));
  }
  
  printLog(FLOOD, "EXIT escapeString(inputString=\"%s\") = {\"%s\"}\n",
    inputString,
    returnValue);
  return returnValue;
}

/// @fn char *escapeData(const volatile void *data, u64 length) {
///
/// @brief Converts a memory block with unwanted characters to its escaped,
/// hexadecimal equivalent.
///
/// @param input The data to convert.
/// @param length The number of bytes of memory to convert.
///
/// @return Returns a newly-allocated string that has been escaped on success,
/// NULL on failure.
char *escapeData(const volatile void *data, u64 length) {
  char *returnValue = NULL;
  
  printLog(FLOOD, "ENTER escapeData(data=%p, length=%llu)\n",
    data, llu(length));
  
  if (data != NULL) {
    const char *input = (const char*) data;
    char escapedValue[4];
    
    // Allocate the maximum amount of space we'll use.
    returnValue = (char*) malloc((length * 3) + 1);
    if (returnValue == NULL) {
      LOG_MALLOC_FAILURE();
      printLog(FLOOD, "EXIT escapeData(data=%p, length=%llu) = {NULL}\n",
        data, llu(length));
      return returnValue; // NULL
    }
    u64 returnValueIndex = 0;
    
    for (u64 i = 0; i < length ; i++) {
      u64 escapedValueLength = 3; // default
      
      if (input[i] < 32 || input[i] > 126) {
        sprintf(escapedValue, "%%%02X", (u8) input[i]);
      } else if (input[i] == '%') {
        strcpy(escapedValue, "%25");
      } else if (input[i] == '`') {
        strcpy(escapedValue, "%60");
      } else if (input[i] == '(') {
        strcpy(escapedValue, "%28");
      } else if (input[i] == ')') {
        strcpy(escapedValue, "%29");
      } else if (input[i] == '\\') {
        strcpy(escapedValue, "%5C");
      } else if (input[i] == '&') {
        strcpy(escapedValue, "%26");
      } else if (input[i] == '"') {
        strcpy(escapedValue, "%22");
      } else if (input[i] == '<') {
        strcpy(escapedValue, "%3C");
      } else if (input[i] == '>') {
        strcpy(escapedValue, "%3E");
      } else if (input[i] == '+') {
        strcpy(escapedValue, "%2B");
      } else if (input[i] == ' ') {
        strcpy(escapedValue, "%20");
      } else {
        escapedValue[0] = input[i];
        escapedValue[1] = '\0';
        escapedValueLength = 1;
      }
      
      strcpy(&returnValue[returnValueIndex], escapedValue);
      returnValueIndex += escapedValueLength;
    }
    
    returnValue[returnValueIndex] = '\0';
  }
  
  printLog(FLOOD, "EXIT escapeData(data=%p, length=%llu) = {\"%s\"}\n",
    data, llu(length), returnValue);
  return returnValue;
}

/// @fn Bytes escapeDataToBytes(const volatile void *data, u64 length) {
///
/// @brief Converts a memory block with unwanted characters to its escaped,
/// hexadecimal equivalent.
///
/// @param input The data to convert.
/// @param length The number of bytes of memory to convert.
///
/// @return Returns a newly-allocated Bytes object that has been escaped on
/// success, NULL on failure.
Bytes escapeDataToBytes(const volatile void *data, u64 length) {
  Bytes returnValue = NULL;
  
  printLog(FLOOD, "ENTER escapeDataToBytes(data=%p, length=%llu)\n",
    data, llu(length));
  
  if (data != NULL) {
    const char *input = (const char*) data;
    char escapedValue[4];
    
    // Allocate the maximum amount of space we'll use.
    bytesAllocate(&returnValue, length * 3);
    if (returnValue == NULL) {
      LOG_MALLOC_FAILURE();
      printLog(FLOOD, "EXIT escapeDataToBytes(data=%p, length=%llu) = {NULL}\n",
        data, llu(length));
      return returnValue; // NULL
    }
    u64 returnValueIndex = 0;
    
    for (u64 i = 0; i < length ; i++) {
      u64 escapedValueLength = 3; // default
      
      if (input[i] < 32 || input[i] > 126) {
        sprintf(escapedValue, "%%%02X", (u8) input[i]);
      } else if (input[i] == '%') {
        strcpy(escapedValue, "%25");
      } else if (input[i] == '`') {
        strcpy(escapedValue, "%60");
      } else if (input[i] == '(') {
        strcpy(escapedValue, "%28");
      } else if (input[i] == ')') {
        strcpy(escapedValue, "%29");
      } else if (input[i] == '\\') {
        strcpy(escapedValue, "%5C");
      } else if (input[i] == '&') {
        strcpy(escapedValue, "%26");
      } else if (input[i] == '"') {
        strcpy(escapedValue, "%22");
      } else if (input[i] == '<') {
        strcpy(escapedValue, "%3C");
      } else if (input[i] == '>') {
        strcpy(escapedValue, "%3E");
      } else if (input[i] == '+') {
        strcpy(escapedValue, "%2B");
      } else if (input[i] == ' ') {
        strcpy(escapedValue, "%20");
      } else {
        escapedValue[0] = input[i];
        escapedValue[1] = '\0';
        escapedValueLength = 1;
      }
      
      strcpy(str(&returnValue[returnValueIndex]), escapedValue);
      returnValueIndex += escapedValueLength;
    }
    
    returnValue[returnValueIndex] = '\0';
  }
  
  printLog(FLOOD, "EXIT escapeDataToBytes(data=%p, length=%llu) = {\"%s\"}\n",
    data, llu(length), str(returnValue));
  return returnValue;
}

/// @fn char *escapeBytes(const Bytes input)
///
/// @brief Converts a Bytes object with unwanted characters to its escaped,
/// hexadecimal equivalent.
///
/// @param input The Bytes object to convert
///
/// @return Returns a newly-allocated string that has been escaped on success,
/// NULL on failure.
char *escapeBytes(const Bytes input) {
  printLog(FLOOD, "ENTER escapeBytes(input=%p)\n", input);
  
  char *returnValue = escapeData(input, bytesLength(input));
  
  printLog(FLOOD, "EXIT escapeBytes(input=%p) = {\"%s\"}\n",
    input, returnValue);
  return returnValue;
}

/// @fn char *strrstr(const char *haystack, const char *needle)
///
/// @brief Finds the last occurrance of needle in haystack.
///
/// @param haystack is the string in which to search.
/// @param needle is the string to search for.
///
/// @return Returns a pointer to the beginning of the found string in haystack
///   on success, NULL on failure.
const char *strrstr(const char *haystack, const char *needle) {
  const char *returnValue = NULL;
  printLog(TRACE, "ENTER strrstr(haystack=\"%s\", needle=\"%s\")\n", haystack,
    needle);
  
  if (haystack != NULL && needle != NULL) {
    size_t needleLen = strlen(needle);
    size_t haystackLen = strlen(haystack);
    if (needleLen > haystackLen) {
      printLog(TRACE, "EXIT strrstr(haystack=\"%s\", needle=\"%s\") = {NULL}\n",
        haystack, needle);
      return NULL;
    }
    
    const char *searchString = &haystack[haystackLen - needleLen];
    while (searchString != haystack) {
      if (strncmp(searchString, needle, needleLen) == 0) {
        returnValue = searchString;
        break;
      }
      searchString--;
    }
    if ((returnValue == NULL) && (searchString == haystack)) {
      // Check to see if the very beginning of the string matches.
      if (strncmp(searchString, needle, needleLen) == 0) {
        returnValue = searchString;
      }
    }
  }
  
  printLog(TRACE, "EXIT strrstr(haystack=\"%s\", needle=\"%s\") = {%p}\n",
    haystack, needle, returnValue);
  return returnValue;
}

/// @fn Bytes** stringToBytesTable_(const char *input, const char *recordDelimiter, const char *fieldDelimiter, ...)
///
/// @brief Convert a recordDelim-delimited, fieldDelim-separated string into a
///   two-dimensional, null-terminated array of Bytes objects.
///
/// @param input is the string to convert.
/// @param recordDelimiter The record delimiter string.
/// @param fieldDelimiter The field delimiter string.
/// @param ... Unused.
///
/// @return Returns a null-terminated, two-dimensional array of Bytes objects
///   on succes, NULL on failure.
Bytes** stringToBytesTable_(const char *input,
  const char *recordDelimiter, const char *fieldDelimiter, ...
) {
  Bytes **returnValue = NULL;
  int numRecords = 0;
  const char *nextRecord = NULL;
  
  printLog(TRACE, "ENTER stringToBytesTable(input=\"%s\")\n", input);
  
  if ((input == NULL)
    || (recordDelimiter == NULL) || (fieldDelimiter == NULL)
  ) {
    printLog(TRACE, "EXIT stringToBytesTable(input=\"%s\") = {%p}\n",
      input, (void*) NULL);
    return NULL;
  }
  
  returnValue = (Bytes**) malloc(sizeof(Bytes**));
  if (returnValue == NULL) {
    // Memory allocation failure.  Can't use printLog.  Just fail.
    return NULL;
  }
  returnValue[0] = NULL;
  
  int recordDelimiterLength = strlen(recordDelimiter);
  nextRecord = input;
  do {
    Bytes workingRecord = getBytesBetween(nextRecord, "", recordDelimiter);
    if (workingRecord == NULL) {
      // recordDelimiter not found.  We're processing the last record.
      workingRecord = getBytesBetween(nextRecord, "", "");
      if (workingRecord == NULL) {
        // Memory allocation failure.  Can't use printLog.  Just fail.
        freeBytesTable(returnValue);
        LOG_MALLOC_FAILURE();
        printLog(NEVER, "EXIT stringToBytesTable(input=\"%s\") = {NULL}\n",
          input);
        return NULL;
      }
    }
    
    if (*workingRecord != '\0') {
      Bytes *recordArray
        = stringToBytesArray((char*) workingRecord, fieldDelimiter);
      if (recordArray != NULL) {
        numRecords++;
        Bytes **check = (Bytes**) realloc(returnValue,
          ((numRecords + 1) * sizeof(Bytes*)));
        if (check != NULL) {
          returnValue = check;
        } else {
          // Memory allocation failure.  Can't use printLog.  Just fail.
          freeBytesTable(returnValue);
          recordArray = freeBytesArray(recordArray);
          workingRecord = bytesDestroy(workingRecord);
          LOG_MALLOC_FAILURE();
          printLog(NEVER, "EXIT stringToBytesTable(input=\"%s\") = {NULLl}\n",
            input);
          return NULL;
        }
        returnValue[numRecords - 1] = recordArray;
        returnValue[numRecords] = NULL;
      }
    }
    
    nextRecord += bytesLength(workingRecord);
    if (strncmp(nextRecord, recordDelimiter, recordDelimiterLength) == 0) {
      nextRecord += recordDelimiterLength;
    } else {
      nextRecord = NULL;
    }
    workingRecord = bytesDestroy(workingRecord);
  } while (nextRecord);
  
  printLog(TRACE, "EXIT stringToBytesTable(input=\"%s\") = {%p}\n",
    input, returnValue);
  return returnValue;
}

/// @fn Bytes* stringToBytesArray_(const char *input, ...)
///
/// Convert a delimited string into a single-dimensional, null-terminated array
/// of Bytes objects.
///
/// @param input The string to convert.
/// @param ... The field delimiters to separte on, terminated with NULL.  If
///   the first field delimiter is NULL, then a single field delimiter of
///   fieldDelim will be used.
///
/// @return Returns a null-terminated, one-dimensional array of Bytes objects
///   on success, NULL on failure.
Bytes* stringToBytesArray_(const char *input, ...) {
  Bytes *returnValue = NULL;
  int numFields = 0;
  const char *nextField = NULL;
  
  printLog(TRACE, "ENTER stringToBytesArray(input=\"%s\")\n", input);
  
  if (input == NULL) {
    printLog(TRACE, "EXIT stringToBytesArray(input=\"%s\") = {%p}\n",
      input, (void*) NULL);
    return NULL;
  }
  
  returnValue = (Bytes*) malloc(sizeof(char**));
  if (returnValue == NULL) {
    // Memory allocation failure.  Can't use printLog.  Just fail.
    return NULL;
  }
  returnValue[0] = NULL;
  
  va_list args;
  va_start(args, input);
  const char *fieldDelimiter = va_arg(args, char*);
  if (fieldDelimiter == NULL) {
    fieldDelimiter = fieldDelim;
    
    int fieldDelimiterLength = strlen(fieldDelimiter);
    nextField = input;
    do {
      Bytes field = getBytesBetween(nextField, "", fieldDelimiter);
      if (field == NULL) {
        // fieldDelimiter not found.  We're processing the last field.
        field = getBytesBetween(nextField, "", "");
        if (field == NULL) {
          // Memory allocation failure.  Can't use printLog.  Just fail.
          freeBytesArray(returnValue);
          LOG_MALLOC_FAILURE();
          printLog(NEVER, "EXIT stringToBytesArray(input=\"%s\") = {NULL}\n",
            input);
          return NULL;
        }
      }
      
      numFields++;
      Bytes *check = (Bytes*) realloc(returnValue,
        ((numFields + 1) * sizeof(Bytes)));
      if (check != NULL) {
        returnValue = check;
      } else {
        // Memory allocation failure.  Can't use printLog.  Just fail.
        freeBytesArray(returnValue);
        field = bytesDestroy(field);
        LOG_MALLOC_FAILURE();
        printLog(NEVER, "EXIT stringToBytesArray(input=\"%s\") = {NULL}\n",
          input);
        return NULL;
      }
      returnValue[numFields - 1] = field;
      returnValue[numFields] = NULL;
      
      nextField += bytesLength(field);
      if (strncmp(nextField, fieldDelimiter, fieldDelimiterLength) == 0) {
        nextField += fieldDelimiterLength;
      } else {
        nextField = NULL;
      }
    } while (nextField);
  } else {
    nextField = input;
    do {
      // Find the next delimiter.
      const char *nextDelimiterAt = strstr(nextField, fieldDelimiter);
      for (const char *delimiterCandidate = va_arg(args, char*);
        delimiterCandidate != NULL;
        delimiterCandidate = va_arg(args, char*)
      ) {
        const char *delimiterCandidateAt
          = strstr(nextField, delimiterCandidate);
        if ((delimiterCandidateAt != NULL)
          && ((delimiterCandidateAt < nextDelimiterAt)
            || (nextDelimiterAt == NULL)
          )
        ) {
          nextDelimiterAt = delimiterCandidateAt;
          fieldDelimiter = delimiterCandidate;
        }
      }
      int fieldDelimiterLength = strlen(fieldDelimiter);
      
      Bytes field = getBytesBetween(nextField, "", fieldDelimiter);
      if (field == NULL) {
        // fieldDelimiter not found.  We're processing the last field.
        field = getBytesBetween(nextField, "", "");
        if (field == NULL) {
          // Memory allocation failure.  Can't use printLog.  Just fail.
          freeBytesArray(returnValue);
          LOG_MALLOC_FAILURE();
          printLog(NEVER, "EXIT stringToBytesArray(input=\"%s\") = {NULL}\n",
            input);
          return NULL;
        }
      }
      
      numFields++;
      Bytes *check = (Bytes*) realloc(returnValue,
        ((numFields + 1) * sizeof(Bytes)));
      if (check != NULL) {
        returnValue = check;
      } else {
        // Memory allocation failure.  Can't use printLog.  Just fail.
        freeBytesArray(returnValue);
        field = bytesDestroy(field);
        LOG_MALLOC_FAILURE();
        printLog(NEVER, "EXIT stringToBytesArray(input=\"%s\") = {NULL}\n",
          input);
        return NULL;
      }
      returnValue[numFields - 1] = field;
      returnValue[numFields] = NULL;
      
      nextField += bytesLength(field);
      if (strncmp(nextField, fieldDelimiter, fieldDelimiterLength) == 0) {
        nextField += fieldDelimiterLength;
      } else {
        nextField = NULL;
      }
      
      // We're now at the end of the va_list.  Reset.
      va_end(args);
      va_start(args, input);
      fieldDelimiter = va_arg(args, char*);
    } while (nextField);
  }
  va_end(args);
  
  printLog(TRACE, "EXIT stringToBytesArray(input=\"%s\") = {%p}\n",
    input, returnValue);
  return returnValue;
}

/// @fn Bytes* freeBytesArray(Bytes *array)
///
/// @brief Free the memory previously allocated for an array that was parsed
///   from a string.
///
/// @param array is the one-dimensional, null-terminated array of Bytes objects
///   to free.
///
/// @return Returns NULL on success, a pointer to the unfreed table on failure.
Bytes* freeBytesArray(Bytes *array) {
  printLog(TRACE, "ENTER freeBytesArray(array=%p)\n", array);
  
  if (array != NULL) {
    for (int i = 0; array[i] != NULL; i++) {
      array[i] = bytesDestroy(array[i]);
    }
    array = (Bytes*) pointerDestroy(array);
  }
  
  printLog(TRACE, "EXIT freeBytesArray(array=%p) = {%p}\n", array, array);
  return array;
}

/// @fn Bytes** freeBytesTable(Bytes **table)
///
/// @brief Free the memory previously allocated for a table that was parsed
///   from a string.
///
/// @param table is the two-dimensional, null-terminated array of bytes-objects
///   to free.
///
/// @return Returns NULL on success, a pointer to the unfreed table on failure.
Bytes** freeBytesTable(Bytes** table) {
  printLog(TRACE, "ENTER freeBytesTable(table=%p)\n", table);
  
  if (table != NULL) {
    for (int i = 0; table[i] != NULL; i++) {
      table[i] = freeBytesArray(table[i]);
    }
    table = (Bytes**) pointerDestroy(table);
  }
  
  printLog(TRACE, "EXIT freeBytesTable(table=%p) = {%p}\n", table,
    (void*) NULL);
  return NULL;
}

/// @fn char *bytesArrayToString_(const Bytes *array, const char *fieldDelimiter, ...)
///
/// @brief Convert a one-dimensional string array to a single string.
///
/// @param array The one-dimensional string array.
/// @param fieldDelimiter The field delimiter string.
/// @param ... Unused.
///
/// @return Returns a pointer to a string on success, NULL on failure.
char *bytesArrayToString_(const Bytes *array, const char *fieldDelimiter, ...) {
  char *returnValue = NULL;
  printLog(TRACE,
    "ENTER bytesArrayToString(array=%p)\n", array);
  
  if (array!= NULL) {
    straddstr(&returnValue, "");
    
    for (int i = 0; array[i] != NULL; i++) {
      straddstr(&returnValue, (char*) array[i]);
      if (array[i + 1] != NULL) {
        straddstr(&returnValue, fieldDelimiter);
      }
    }
  }
  
  printLog(TRACE,
    "EXIT bytesArrayToString(array=%p) = {\"%s\"}\n", array, returnValue);
  return returnValue;
}

/// @fn char *bytesTableToString_(const Bytes **table, const char *recordDelimiter, const char *fieldDelimiter, ...)
///
/// @brief Convert a two-dimensional string table to a single string.
///
/// @param table The two-dimensional string table.
/// @param recordDelimiter The record delimiter string.
/// @param fieldDelimiter The field delimiter string.
/// @param ... Unused.
///
/// @note This function does not use stringArrayToString because that would create
/// extra memory allocations and deallocations for substrings.
///
/// @return Returns a pointer to a string on success, NULL on failure.
char *bytesTableToString_(const Bytes **table,
  const char *recordDelimiter, const char *fieldDelimiter, ...
) {
  char *returnValue = NULL;
  printLog(TRACE,
    "ENTER bytesTableToString(table=%p)\n", table);
  
  if (table != NULL) {
    straddstr(&returnValue, "");
    
    for (int i = 0; table[i] != NULL; i++) {
      for (int j = 0; table[i][j] != NULL; j++) {
        straddstr(&returnValue, (char*) table[i][j]);
        if (table[i][j + 1] != NULL) {
          straddstr(&returnValue, fieldDelimiter);
        }
      }
      if (table[i + 1] != NULL) {
        straddstr(&returnValue, recordDelimiter);
      }
    }
  }
  
  printLog(TRACE,
    "EXIT bytesTableToString(table=%p) = {\"%s\"}\n", table, returnValue);
  return returnValue;
}

/// @fn int vasprintf(char **buffer, const char *formatString, va_list args)
///
/// @brief Allocate a buffer for a string and print a formatted string to the
///   buffer.
///
/// @param buffer is the pointer to a char* to be allocated
/// @param formatString is the format string
/// @param args All further arguments are dictated by the formatString
///
/// @return Returns the number of bytes printed on success, -1 on failure.
///   On success, *buffer contains the contents of the printed string.  On
///   failure, *buffer is unmodified.
int vasprintf(char **buffer, const char *formatString, va_list args) {
  int returnValue = 0;
  if (buffer == NULL) {
    fprintf(logFile, "ERROR: buffer is null in asprintf.  Cannot execute.\n");
    fflush(logFile);
    returnValue = -1;
    return returnValue;
  }
  
  va_list args2;
  va_copy(args2, args);
  
  int bufferSize = vsnprintf(NULL, 0, formatString, args) + 1;
  
  char *tempBuffer = (char*) malloc(bufferSize);
  
  if ((bufferSize > 0) && (tempBuffer != NULL)) {
    returnValue = vsprintf(tempBuffer, formatString, args2);
  } else {
    returnValue = -1;
  }
  va_end(args2);
  
  if (returnValue > -1) {
    *buffer = tempBuffer;
  } else {
    tempBuffer = stringDestroy(tempBuffer);
  }
  
  return returnValue;
}

/// @fn int asprintf(char **buffer, const char *formatString, ...)
///
/// @brief Allocate a buffer for a string and print a formatted string to the
///   buffer.
///
/// @param buffer is the pointer to a char* to be allocated
/// @param formatString is the format string
/// @param ... All further arguments are dictated by the formatString
///
/// @return Returns the number of bytes printed on success, -1 on failure.
///   On success, *buffer contains the contents of the printed string.  On
///   failure, *buffer is unmodified.
int asprintf(char **buffer, const char *formatString, ...) {
  int returnValue = 0;
  va_list args;
  
  va_start(args, formatString);
  returnValue = vasprintf(buffer, formatString, args);
  va_end(args);
  
  return returnValue;
}

/// @fn char *unformatString(char *str)
///
/// @brief Adds additional '%' character to existing '%' characters to avoid
///   accidental formatting of a string.
///
/// @param str is the string to unformat
///
/// @return Returns a copy of str with any '%' characters unformatted.
char *unformatString(char *str) {
  char *unformattedString = NULL;
  char toBeAdded[2] = {'\0', '\0'};
  char *cur = NULL;
  printLog(TRACE, "ENTER unformatString(str=\"%s\")\n", str);
  
  if ((str != NULL) && (*str != '\0')) {
    for (cur = str; *cur != '\0'; cur++) {
      printLog(DEBUG, "In cur for.\n");
      if (*cur == '%') {
        // Adding a %.  Add another one first.
        toBeAdded[0] = '%';
        straddstr(&unformattedString, toBeAdded);
      }
      toBeAdded[0] = *cur;
      straddstr(&unformattedString, toBeAdded);
    }
  } else if ((str != NULL) && (*str == '\0')) {
    unformattedString = (char*) malloc(1 * sizeof(char));
    *unformattedString = '\0';
  }
  
  printLog(TRACE, "EXIT unformatString(str=\"%s\") = {%s}\n", str,
    unformattedString);
  return unformattedString;
}

/// @fn i32 reverseString(char *inputString)
///
/// @brief Reverses the contents of a string in place.
///
/// @param inputString is the string to reverse.
///
/// @return Returns 0 on success.  Any other value is failure.
i32 reverseString(char *inputString) {
  if (inputString == NULL) {
    return -1;
  }
  
  reverseMemory(inputString, strlen(inputString));
  
  return 0;
}

/// @fn Bytes bytesAllocate(Bytes *buffer, u64 size)
///
/// @brief Allocate enough space to accommodate the requested size.
///
/// @details
/// This function will allocate AT LEAST as much space as requested on success.
/// The purpose here is to have enough space in the buffer for whatever copying
/// comes next (usually by bytesAddData), however we also have the goal to
/// minimize the total number of allocations necessary.  To that end, if we
/// detect that we're reallocating space, we will actually allocate twice as
/// much space as requested so that we hopefully avoid the need to repeatedly
/// reallocate on each additional call to bytesAddData.
///
/// @param buffer A pointer to the Bytes object to allocate space for.
/// @param size The amount of memory, in bytes, requested for the buffer.
///
/// @return Returns a pointer to the allocated buffer on success, NULL on
/// failure.
Bytes bytesAllocate(Bytes *buffer, u64 size) {
  printLog(FLOOD, "ENTER bytesAllocate(*buffer=%p, size=%llu)\n",
    (buffer) ? *buffer : NULL, llu(size));
  
  u64 bufferSize = 0;
  size++; // Always allocate at least one byte.
  
  if (buffer != NULL) {
    bufferSize = bytesSize(*buffer);
    if (size > bufferSize) {
      if (*buffer == NULL) {
        // Initial allocation.  Assume the user got it right and allocate
        // exactly as much space as requested (plus space for the header).
        bufferSize = size;
        *buffer = (Bytes) malloc(bufferSize + sizeof(BytesHeader));
        if (*buffer == NULL) {
          LOG_MALLOC_FAILURE();
          return *buffer;
        }
        
        // Move the pointer to the beginning of the Bytes content.
        *buffer += sizeof(BytesHeader);
        bytesSetLength(*buffer, 0); // Initialize the length.
        **buffer = '\0'; // Initialize the buffer.
      } else {
        // Move the pointer back to the beginning of the allocated space.
        BytesHeader *bytesHeader = &(((BytesHeader*) *buffer)[-1]);
        
        // We're being asked to extend our buffer.  Rather than allocating just
        // enough space, allocate twice the amount of requested space.  This
        // will reduce the need to resize this buffer in the future.
        bufferSize = size << 1;
        BytesHeader *check = (BytesHeader*) realloc(bytesHeader,
          bufferSize + sizeof(BytesHeader));
        if (check == NULL) {
          LOG_MALLOC_FAILURE();
          bytesHeader = (BytesHeader*) pointerDestroy(bytesHeader);
          *buffer = NULL;
          return *buffer;
        } else if (check != bytesHeader) {
          bytesHeader = check;
        }
        
        // Return the pointer to the beginning of the Bytes content.
        *buffer = (Bytes) &(bytesHeader[1]);
      }
      
      bytesSetSize(*buffer, bufferSize);
    }
  }
  
  size--; // Reset for the logging statement.
  
  printLog(FLOOD, "EXIT bytesAllocate(*buffer=%p, size=%llu) = {%p}\n",
    (buffer) ? *buffer : NULL, llu(size), *buffer);
  return *buffer;
}

/// @fn Bytes bytesAddData(Bytes *buffer, const volatile void *input, u64 inputLength)
///
/// @brief This function appends the contents of a memory block to a bytes
///   object.  A NULL byte will then be appended to the resulting object, but
///   this byte will not be counted in the length returned by bytesLength.
///   This allows for the Bytes objects to be directly treated as strings if
///   desired.
///
/// @param buffer is a pointer to an allocated Bytes object or NULL.
/// @param input is a pointer to a memory block which should be appended to
///   *buffer.
/// @param inputLength is the size of the memory block pointed to by input.
///
/// @return Returns the value of of *buffer.
Bytes bytesAddData(Bytes *buffer, const volatile void *input, u64 inputLength) {
  printLog(FLOOD, "ENTER bytesAddData(*buffer=%p, input=%p, inputLength=%llu)\n",
    (buffer) ? *buffer : NULL, input, llu(inputLength));
  
  Bytes returnValue = NULL;
  
  if (buffer == NULL) {
    printLog(DEBUG, "NULL base buffer pointer detected in bytesAddData.\n");
    printLog(FLOOD,
      "EXIT bytesAddData(*buffer=%p, input=%p, inputLength=%llu) = {%p}\n",
      (buffer) ? *buffer : NULL, input, llu(inputLength), returnValue);
    return returnValue;
  } else if (input == NULL) {
    // No-op.
    printLog(FLOOD,
      "EXIT bytesAddData(*buffer=%p, input=%p, inputLength=%llu) = {%p}\n",
      (buffer) ? *buffer : NULL, input, llu(inputLength), returnValue);
    return returnValue;
  }
  
  u64 bufferLength = bytesLength(*buffer);
  if (bytesAllocate(buffer, bufferLength + inputLength) != NULL) {
    memcpy((void*)(&(((*buffer))[bufferLength])), (const void*) input,
      inputLength);
    bufferLength += inputLength;
    (*buffer)[bufferLength] = '\0';
  }
  
  bytesSetLength(*buffer, bufferLength);
  returnValue = (buffer) ? *buffer : NULL;
  
  printLog(FLOOD,
    "EXIT bytesAddData(*buffer=%p, input=%p, inputLength=%llu) = {%p}\n",
    returnValue, input, llu(inputLength), returnValue);
  return returnValue;
}

/// @fn Bytes bytesAddBytes(Bytes *buffer, const Bytes input)
///
/// @brief This function appends the contents of a Bytes object to a bytes
///   object.
///
/// @param buffer is a pointer to an allocated Bytes object or NULL.
/// @param input is a pointer to a Bytes object which should be appended to
///   *buffer.
///
/// @return Returns the new size of *buffer.
Bytes bytesAddBytes(Bytes *buffer, const Bytes input) {
  u64 inputLength = 0;
  
  printLog(FLOOD, "ENTER bytesAddBytes(*buffer=%p, input=%p)\n",
    (buffer) ? *buffer : NULL,
    input);
  
  if (input != NULL) {
    inputLength = bytesLength(input);
  }
  Bytes returnValue = bytesAddData(buffer, input, inputLength);

  printLog(FLOOD, "EXIT bytesAddBytes(*buffer=%p, input=%p) = {%p}\n",
    (buffer) ? *buffer : NULL,
    input,
    returnValue);
  return returnValue;
}

/// @fn Bytes bytesAddStr(Bytes *buffer, const char *input)
///
/// @brief This function appends the contents of a string to a bytes
///   object.
///
/// @param buffer is a pointer to an allocated Bytes object or NULL.
/// @param input is a pointer to a string which should be appended to
///   *buffer.
///
/// @return Returns the pointer to the new buffer.
Bytes bytesAddStr(Bytes *buffer, const char *input) {
  printLog(FLOOD, "ENTER bytesAddStr(*buffer=%p, input=%p)\n",
    (buffer) ? *buffer : NULL,
    input);
  
  u64 inputLength = 0;
  Bytes returnValue = NULL;
  
  if (input != NULL) {
    inputLength = strlen(input);
    if (inputLength > 0) {
      returnValue = bytesAddData(buffer, input, inputLength);
    } else if ((buffer != NULL) && (*buffer == NULL)) {
      // Special case for adding a zero-length string.
      *buffer = (Bytes) calloc(1, sizeof(BytesHeader) + 1);
      if (*buffer != NULL) {
        *buffer += sizeof(BytesHeader);
        bytesSetSize(*buffer, 1);
        // length is already set to 0 by calloc
        // the buffer is already NULL-terminated by calloc
      } else {
        LOG_MALLOC_FAILURE();
      }
    }
  }
  
  printLog(FLOOD, "EXIT bytesAddStr(*buffer=%p, input=%p) = {%p}\n",
    (buffer) ? *buffer : NULL,
    input,
    returnValue);
  return returnValue;
}

/// @fn Bytes bytesAddChr(Bytes *buffer, char input)
///
/// @brief Add a single character to a Bytes buffer.
///
/// @param buffer A pointer to an allocated Bytes object or NULL.
/// @param input A charcter which should be appended to *buffer.
///
/// @return Returns the pointer to the new buffer.
Bytes bytesAddChr(Bytes *buffer, char input) {
  printLog(TRACE, "ENTER bytesAddChr(*buffer=%p, input=%c)\n",
    (buffer) ? *buffer : NULL, input);
  
  char stringBuffer[2] = { input, '\0' };
  Bytes returnValue = bytesAddStr(buffer, stringBuffer);
  
  printLog(TRACE, "EXIT bytesAddChr(*buffer=%p, input=%c) = {%p}\n",
    (buffer) ? *buffer : NULL, input, returnValue);
  return returnValue;
}

/// @fn Bytes bytesDestroy(Bytes value)
///
/// @brief Release the memory associated with a Bytes value.
///
/// @param value A pointer to the memory to be released.
///
/// @return Returns a null pointer on success, the input pointer on failure.
///   NOTE: Use of the pointer returned by this function will result in
///   undefined behavior.
Bytes bytesDestroy(Bytes value) {
  printLog(TRACE, "ENTER bytesDestroy(value=%p)\n", value);
  
  if (value != NULL) {
    BytesHeader *bytesHeader = &(((BytesHeader*) value)[-1]);
    bytesHeader = (BytesHeader*) pointerDestroy(bytesHeader);
    value = NULL;
  }
  
  printLog(TRACE, "EXIT bytesDestroy(value=%p) = {%p}\n", value, value);
  return value;
}

/// @fn int arrayFindValueIndex(const char **array, const char *value)
///
/// @brief Find the index of a value in a string array.
///
/// @param array The array of strings to search.
/// @param value The string value to search for.
///
/// @return Returns the index of the value in the array on success,
/// -1 on failure.
int arrayFindValueIndex(const char **array, const char *value) {
  printLog(TRACE, "ENTER arrayFindValueIndex(array=%p, value=\"%s\")\n",
    array, (value != NULL) ? value : "");
  
  // Fail by default.
  int returnValue = -1;
  
  if ((array == NULL) || (value == NULL)) {
    // Invalid parameter
    printLog(TRACE, "EXIT arrayFindValueIndex(array=%p, value=\"%s\") = {%d}\n",
      array, (value != NULL) ? value : "", returnValue);
    return returnValue;
  }
  
  for (int i = 0; array[i] != NULL; i++) {
    if (strcmp(array[i], value) == 0) {
      returnValue = i;
      break;
    }
  }
  
  printLog(TRACE, "EXIT arrayFindValueIndex(array=%p, value=\"%s\") = {%d}\n",
    array, (value != NULL) ? value : "", returnValue);
  return returnValue;
}

/// @fn int arrayRemoveValue(char **array, const char *value)
///
/// @brief Remove a value from a previously-allocated string array.
///
/// @param array A single-dimensional string array.
/// @param value The value to search for and remove from the array.
///
/// @return Returns 0 on success, negative error code on failure.
int arrayRemoveValue(char **array, const char *value) {
  printLog(TRACE, "ENTER arrayRemoveValue(array=%p, value=\"%s\")\n",
    array, (value != NULL) ? value : "");
  
  int returnValue = 0;
  
  if ((array == NULL) || (value == NULL)) {
    // Invalid parameter
    returnValue = -1;
    printLog(TRACE, "EXIT arrayRemoveValue(array=%p, value=\"%s\") = {%d}\n",
      array, (value != NULL) ? value : "", returnValue);
    return returnValue;
  }
  
  int i = arrayFindValueIndex((const char**) array, value);
  if (i >= 0) {
    array[i] = stringDestroy(array[i]);
    for (int j = i + 1; array[j] != NULL; j++, i++) {
      array[i] = array[j];
    }
    array[i] = NULL; // Terminate the array
    // If we were concerned about memory usage, we'd realloc here to
    // shorten the array by one index since it's no longer being used.  We
    // generally don't care THAT much, so really no point in wasting the
    // time to do it.  Note, though, that if we did want to do that, we'd
    // need to take a pointer to the array instead of the array's address
    // itself.
  }
  
  printLog(TRACE, "EXIT arrayRemoveValue(array=%p, value=\"%s\") = {%d}\n",
    array, (value != NULL) ? value : "", returnValue);
  return returnValue;
}

/// @fn void stringToLowerCase(char *string)
///
/// @brief Convert a string to a lower-case version of itself.  Modifies the
/// string in place.
///
/// @param string The string to convert to lower-case.  Modified in place.
///
/// @return This function returns no value.
void stringToLowerCase(char *string) {
  printLog(TRACE, "ENTER stringToLowerCase(string=\"%s\")\n",
    (string != NULL) ? string : "{NULL}");
  
  if (string == NULL) {
    printLog(TRACE, "EXIT stringToLowerCase(string=NULL)\n");
    return;
  }
  
  int stringLength = strlen(string);
  for (int i = 0; i < stringLength; i++) {
    string[i] = (char) tolower((unsigned char) string[i]);
  }
  
  printLog(TRACE, "EXIT stringToLowerCase(string=\"%s\")\n", string);
  return;
}

/// @fn char *strstrci(const char *haystack, const char *needle)
///
/// @brief Case-insensitive version of strstr.  Finds the first occcurence of
/// needle within haystack, if present, without respect to case.
///
/// @param haystack The string to search within.
/// @param needle The string to search for within haystack.
///
/// @return Returns a pointer to the first character of needle within haystack
/// on success, NULL on failure.
char *strstrci(const char *haystack, const char *needle) {
  printLog(TRACE, "ENTER strstrci(haystack=\"%s\", needle=\"%s\")\n",
    (haystack != NULL) ? haystack : "{NULL}",
    (needle != NULL) ? needle : "{NULL}");
  
  if ((haystack == NULL) || (needle == NULL)) {
    printLog(TRACE, "EXIT strstrci(haystack=\"%s\", needle=\"%s\") = {NULL}\n",
      (haystack != NULL) ? haystack : "{NULL}",
      (needle != NULL) ? needle : "{NULL}");
    return NULL;
  }
  
  size_t needleLength = strlen(needle);
  
  char firstChar = *needle;
  if ((firstChar >= 'A') && (firstChar <= 'Z')) {
    firstChar += 32;
  }
  
  const char *returnValue = NULL;
  for (const char *where = haystack; *where != '\0'; where++) {
    char c = *where;
    if ((c >= 'A') && (c <= 'Z')) {
      c += 32;
    }
    
    if ((c == firstChar) && (strncmpci(where, needle, needleLength) == 0)) {
      returnValue = where;
      break;
    }
  }
  
  printLog(TRACE, "EXIT strstrci(haystack=\"%s\", needle=\"%s\") = {%p}\n",
    haystack, needle, returnValue);
  return (char*) returnValue;
}

/// @fn int strncmpci(const char *s1, const char *s2, size_t len)
///
/// @brief Case-insensitive version of strcmp.  Compares the two strings
/// s1 and s2.
///
/// @param s1 The first string.
/// @param s2 The second string.
/// @param len The number of bytes in the two strings to compare.
///
/// @return Returns -1 if s1 < s2, 0 if s1 == s2, and 1 if s1 > s2.
int strncmpci(const char *s1, const char *s2, size_t len) {
  printLog(TRACE, "ENTER strncmpci(s1=\"%s\", s2=\"%s\", len=%llu)\n",
    (s1 != NULL) ? s1 : "{NULL}",
    (s2 != NULL) ? s2 : "{NULL}",
    llu(len));
  
  int returnValue = 0;
  
  if (s1 == NULL) {
    printLog(WARN, "s1 is NULL.\n");
    returnValue--;
  }
  if (s2 == NULL) {
    printLog(WARN, "s2 is NULL.\n");
    returnValue++;
  }
  if ((s1 == NULL) || (s2 == NULL)) {
    printLog(TRACE, "EXIT strncmpci(s1=\"%s\", s2=\"%s\", len=%llu) = {%d}\n",
      (s1 != NULL) ? s1 : "{NULL}",
      (s2 != NULL) ? s2 : "{NULL}",
      llu(len),
      returnValue);
    return returnValue;
  }
  
  size_t i = 0;
  const char *initialS1 = s1, *initialS2 = s2;
  (void) initialS1; // In case logging is disabled.
  (void) initialS2; // In case logging is disabled.
  for (;
    (returnValue == 0)
    && (i < len)
    && (*s1 != '\0') && (*s2 != '\0');
    s1++, s2++, i++
  ) {
    char c1 = *s1;
    char c2 = *s2;
    
    if ((c1 >= 'A') && (c1 <= 'Z')) {
      c1 += 32;
    }
    if ((c2 >= 'A') && (c2 <= 'Z')) {
      c2 += 32;
    }
    
    returnValue = c1 - c2;
  }
  
  if ((returnValue == 0) && (i < len)) {
    // We are either comparing the NULL byte on the end of one string to the
    // NULL byte on the end of the other or we're comparing the the NULL byte
    // on one string to a valid character on the other.
    char c1 = *s1;
    char c2 = *s2;
    
    if ((c1 >= 'A') && (c1 <= 'Z')) {
      c1 += 32;
    }
    if ((c2 >= 'A') && (c2 <= 'Z')) {
      c2 += 32;
    }
    
    returnValue = c1 - c2;
  }
  
  printLog(TRACE, "EXIT strncmpci(s1=\"%s\", s2=\"%s\", len=%llu) = {%d}\n",
    initialS1, initialS2, llu(len), returnValue);
  return returnValue;
}

/// @fn Bytes getBytesBetweenCi(const char *haystack, const char *start, const char *end)
///
/// @brief Get the text within a haystack between a starting string and an
/// ending string, but not including either string.  Do a case-insensitive
/// search.
///
/// @param haystack The string to search.
/// @param start The starting string string to look for within haystack.  If
///   this is an empty string, copy from the beginning of haystack.
/// @param end The ending string to look for within haystack.  If this is an
///   empty string, copy to the end of haystack.
///
/// @return Returns a substring of haystack from the first character past the
/// end of start in haystack until the last character before end in haystack,
/// inclusive.  Return value is a new Bytes object.
///
/// @note Because we're doing case-insensitive searching, we need custom logic
/// for this function and can't make it a simple wrapper around getDataBetween.
Bytes getBytesBetweenCi(const char *haystack, const char *start, const char *end) {
  printLog(TRACE, "ENTER getBytesBetweenCi(haystack=%s, start=%s, end=%s)\n",
    (haystack != NULL) ? haystack : "NULL",
    (start != NULL) ? start: "NULL",
    (end != NULL) ? end : "NULL");
  
  if ((haystack == NULL) || (start == NULL) || (end == NULL)) {
    printLog(ERR, "One or more invalid parameters.\n");
    printLog(TRACE,
      "EXIT getBytesBetweenCi(haystack=%s, start=%s, end=%s) = {NULL}\n",
      (haystack != NULL) ? haystack : "NULL",
      (start != NULL) ? start: "NULL",
      (end != NULL) ? end : "NULL");
    return NULL;
  }
  
  unsigned char *startAt = (unsigned char*) haystack;
  if (*start != '\0') {
    startAt = (unsigned char*) strstrci(haystack, start);
    if (startAt == NULL) {
      printLog(TRACE,
        "EXIT getBytesBetweenCi(haystack=%s, start=%s, end=%s) = {NULL}\n",
        haystack, start, end);
      return NULL;
    }
    startAt += strlen(start);
  }
  
  u64 length = 0;
  if (*end != '\0') {
    unsigned char *endAt = (unsigned char*) strstrci(
      (char*) startAt, end);
    if (endAt != NULL) {
      length = endAt - startAt;
    } else {
      printLog(TRACE,
        "EXIT getBytesBetweenCi(haystack=%s, start=%s, end=%s) = {NULL}\n",
        haystack, start, end);
      return NULL;
    }
  } else {
    // We copy until the end of the haystack.
    length = (u64) strlen(start);
  }
  
  Bytes returnValue = (Bytes) malloc(sizeof(BytesHeader) + length + 1);
  if (returnValue == NULL) {
    LOG_MALLOC_FAILURE();
    printLog(NEVER,
      "EXIT getBytesBetweenCi(haystack=%s, start=%s, end=%s) = {NULL}\n",
      haystack, start, end);
    return NULL;
  }
  returnValue += sizeof(BytesHeader);
  bytesSetLength(returnValue, length);
  bytesSetSize(returnValue, length + 1);
  memcpy((void*) returnValue, startAt, length);
  returnValue[length] = '\0';
  
  printLog(TRACE,
    "EXIT getBytesBetweenCi(haystack=%s, start=%s, end=%s) = {%s}\n",
    haystack, start, end, returnValue);
  return returnValue;
}

/// @fn void unescapeBytes(Bytes input)
///
/// @brief This function unescapes URL-encoded bytes.  The bytes are
///   modified in place.
///
/// @param input The URL-encoded Bytes to unescape.
///
/// @return There is no return value for this function.
void unescapeBytes(Bytes input) {
  printLog(FLOOD, "ENTER unescapeBytes(input=\"%s\")\n", input);
  
  if (input != NULL) {
    u64 inputLength = bytesLength(input);
    u64 i = 0, j = 0;
    
    for (i = 0, j = 0;
      (i < inputLength)
        && (j < inputLength);
      i++, j++
    ) {
      input[i] = input[j];
      if (input[j] == '%') {
        char tempChar = hexToChar((char*) &input[j + 1]);
        input[i] = tempChar;
        j += 2;
      } else if (input[j] == '&') {
        char tempChar = unampersand((char*) &input[j]);
        if (tempChar != '\0') {
          input[i] = tempChar;
          while ((j < inputLength) && (input[j] != ';')) {
            j++;
          }
        }
      } else if (input[j] == '+') {
        input[i] = ' ';
      }
    }
    // Adjust the data length of the bytes.
    bytesSetLength(input, i);
    input[bytesLength(input)] = '\0';
  }
  
  printLog(FLOOD, "EXIT unescapeBytes(input=\"%s\") = {}\n", input);
  return;
}

/// @fn u64 straddbytes(char **buffer, const Bytes input)
///
/// @brief This function appends the contents of a Bytes object to a string.
///
/// @param buffer is a pointer to an allocated string or NULL.
/// @param input is a pointer to a Bytes object should be appended to *buffer.
///
/// @return Returns the new size of *buffer.
u64 straddbytes(char **buffer, const Bytes input) {
  u64 bufferLength = 0;
  
  printLog(TRACE, "ENTER straddbytes(*buffer=%p, input=%p)\n",
    (buffer) ? *buffer : NULL, input);
  
  if (buffer == NULL) {
    // Nothing to be done.
    printLog(TRACE, "EXIT straddbytes(*buffer=%p, input=%p) = {%llu}\n",
      (buffer) ? *buffer : NULL, input, llu(0));
    return 0;
  }
  
  if (*buffer != NULL) {
    bufferLength = strlen(*buffer);
  }
  bufferLength = dataAddData((void**) buffer, bufferLength,
    input, bytesLength(input));
  // Terminate the string with a NULL byte.
  bufferLength = dataAddData((void**) buffer, bufferLength, "", 1);

  printLog(TRACE, "EXIT straddbytes(*buffer=%p, input=%p) = {%llu}\n",
    (buffer) ? *buffer : NULL, input, llu(bufferLength));
  return bufferLength;
}

/// @fn int bytesNCompare(const Bytes valueA, const Bytes valueB, u64 len)
///
/// @brief Compare two Bytes values.
///
/// @param valueA A pointer to the first value to compare.
/// @param valueB A pointer to the second value to compare.
/// @param len The maximum number of bytes to compare.
///
/// @return Returns -1 if *valueA < *valueB, 0 if *valueA == *valueB,
///   1 if *valueA > *valueB.
int bytesNCompare(const Bytes valueA, const Bytes valueB, u64 len) {
  printLog(TRACE,
    "ENTER bytesNCompare(valueA=\"%s\", valueB=\"%s\", len=%llu)\n",
    str(valueA), str(valueB), llu(len));
  
  int returnValue = 0;
  
  if (valueA == NULL) {
    printLog(WARN, "valueA is NULL.\n");
    returnValue--;
  }
  if (valueB == NULL) {
    printLog(WARN, "valueB is NULL.\n");
    returnValue++;
  }
  if ((valueA == NULL) || (valueB == NULL)) {
    printLog(TRACE,
      "EXIT bytesNCompare(valueA=\"%s\", valueB=\"%s\", len=%llu) = {%d}\n",
      str(valueA), str(valueB), llu(len), returnValue);
    return returnValue;
  }
  
  u64 comparisonLength = MIN(bytesLength(valueA), bytesLength(valueB));
  returnValue = memcmp(valueA, valueB, (size_t) MIN(comparisonLength, len));
  
  if ((returnValue == 0) && (comparisonLength < len)) {
    // We are either comparing the NULL byte on the end of one string to the
    // NULL byte on the end of the other or we're comparing the the NULL byte
    // on one string to a valid character on the other.
    char c1 = (char) valueA[comparisonLength];
    char c2 = (char) valueB[comparisonLength];
    returnValue = ((int) c1) - ((int) c2);
  }
  
  printLog(TRACE,
    "EXIT bytesNCompare(valueA=\"%s\", valueB=\"%s\", len=%llu) = {%d}\n",
    str(valueA), str(valueB), llu(len), returnValue);
  return returnValue;
}

/// @fn Bytes bytesReplaceStr(const Bytes input, const char *findWhat, const char *replaceText)
///
/// @brief Replace every occurrance of findWhat in inputString with replaceText.
///
/// @param inputString is the string to examine
/// @param findWhat is the text to find in str.  If '*' is the last character,
///   then the matching portion of the inputString and evereything thereafter
///   is replaced with the replaceText.
/// @param replaceText is the text that is to replace findWhat in str
///
/// @return Returns a new Bytes object that has all instances of findWhat
///   replaced with replaceText on success.  NULL on failure.
Bytes bytesReplaceStr(
  const Bytes input, const char *findWhat, const char *replaceText
) {
  const char *inputString = (const char*) input;
  Bytes returnValue = NULL;
  
  printLog(TRACE,
    "ENTER bytesReplaceStr(inputString=\"%s\", findWhat=\"%s\", "
    "replaceText=\"%s\")\n",
    inputString,
    findWhat,
    replaceText);
  
  if ((input == NULL) || (replaceText == NULL) || (findWhat == NULL)) {
    // Nothing to replace.  Provide what was given.
    bytesAddStr(&returnValue, inputString);
    printLog(TRACE,
      "EXIT bytesReplaceStr(inputString=\"%s\", findWhat=\"%s\", "
      "replaceText=\"%s\") = {\"%s\"}\n",
      inputString,
      findWhat,
      replaceText,
      returnValue);
    return returnValue;
  }
  
  int findWhatLength = strlen(findWhat);
  bool replaceToEnd = false;
  char *findWhatCopy = NULL;
  straddstr(&findWhatCopy, findWhat);
  if (findWhat[findWhatLength - 1] == '*') {
    if (findWhat[findWhatLength - 2] == '\\') {
      // We're looking for a literal '*' at the end of findWhat.
      findWhatCopy[findWhatLength - 2] = '*';
      findWhatCopy[findWhatLength - 1] = '\0';
      findWhatLength--;
    } else {
      // We're looking for everything from findWhat to the end of the string.
      findWhatCopy[findWhatLength - 1] = '\0';
      findWhatLength--;
      // This means we only need to do one pass.
      replaceToEnd = true;
    }
  }
  
  const char *currentString = inputString;
  do {
    Bytes nonReplacedBytes = getBytesBetween(currentString, "", findWhatCopy);
    if (nonReplacedBytes == NULL) {
      // findWhat not found.
      nonReplacedBytes = bytesDestroy(nonReplacedBytes);
      bytesAddStr(&returnValue, currentString);
      break;
    }
    
    bytesAddBytes(&returnValue, nonReplacedBytes);
    currentString += bytesLength(nonReplacedBytes);
    currentString += findWhatLength;
    nonReplacedBytes = bytesDestroy(nonReplacedBytes);
    bytesAddStr(&returnValue, replaceText);
  } while ((replaceToEnd == false) && (*currentString != '\0'));
  findWhatCopy = stringDestroy(findWhatCopy);
  
  printLog(TRACE,
    "EXIT bytesReplaceStr(inputString=\"%s\", findWhat=\"%s\", "
    "replaceText=\"%s\") = {\"%s\"}\n",
    inputString,
    findWhat,
    replaceText,
    returnValue);
  return returnValue;
}

/// @fn Bytes bytesFindBytes(const Bytes haystack, const Bytes needle)
///
/// @param haystack The Bytes object to search.
/// @param needle The Bytes object to search for.
///
/// @return Returns a pointer to the beginning of the first instance of needle
/// in haystack if needle is found, NULL if not.
Bytes bytesFindBytes(const Bytes haystack, const Bytes needle) {
  printLog(TRACE, "ENTER bytesFindBytes(haystack=\"%s\", needle=\"%s\")\n",
    (const char*) haystack, (const char*) needle);
  
  u64 haystackLength = bytesLength(haystack);
  u64 needleLength = bytesLength(needle);
  
  if (needleLength > haystackLength) {
    printLog(TRACE,
      "EXIT bytesFindBytes(haystack=\"%s\", needle=\"%s\") = {NULL}\n",
      (const char*) haystack, (const char*) needle);
    return NULL;
  }
  u64 lastIndex = haystackLength - needleLength;
  
  // Cast haystack to non-const to avoid compiler complaints.
  Bytes searchBytes = (Bytes) haystack;
  for (u64 i = 0; i < lastIndex; i++) {
    if (memcmp((void*) searchBytes, (void*) needle,
      (size_t) needleLength) == 0
    ) {
      break;
    }
    searchBytes++;
  }
  if (searchBytes > &haystack[lastIndex]) {
    // needle not found.
    printLog(TRACE,
      "EXIT bytesFindBytes(haystack=\"%s\", needle=\"%s\") = {NULL}\n",
      (const char*) haystack, (const char*) needle);
    return NULL;
  }
  
  // searchBytes is at the location we're interested in for the return value.
  u64 returnValueLength = haystackLength - (searchBytes - haystack);
  Bytes returnValue = NULL;
  bytesAddData(&returnValue, searchBytes, returnValueLength);
  
  printLog(TRACE,
    "EXIT bytesFindBytes(haystack=\"%s\", needle=\"%s\") = {%s}\n",
    (const char*) haystack, (const char*) needle, (const char*) returnValue);
  return returnValue;
}

/// @fn Bytes bytesTableToCsv(const Bytes **table)
///
/// @brief Convert a two-dimensional Bytes table to a single CSV-formatted
/// Bytes object.
///
/// @param table The two-dimensional Bytes table.
///
/// @return Returns a new CSV-formatted Bytes object success, NULL on failure.
Bytes bytesTableToCsv(const Bytes **table) {
  Bytes returnValue = NULL;
  printLog(TRACE, "ENTER bytesTableToCsv(table=%p)\n", table);
  
  if (table != NULL) {
    bytesAddStr(&returnValue, "");
    
    for (int i = 0; table[i] != NULL; i++) {
      for (int j = 0; table[i][j] != NULL; j++) {
        Bytes escapedField = bytesReplaceStr(table[i][j], "\"", "\"\"");
        bytesAddStr(&returnValue, "\"");
        bytesAddBytes(&returnValue, escapedField);
        escapedField = bytesDestroy(escapedField);
        bytesAddStr(&returnValue, "\"");
        
        if (table[i][j + 1] != NULL) {
          bytesAddStr(&returnValue, ",");
        }
      }
      
      if (table[i + 1] != NULL) {
        bytesAddStr(&returnValue, "\r\n");
      }
    }
  }
  
  printLog(TRACE,
    "EXIT bytesTableToCsv(table=%p) = {\"%s\"}\n", table, (char*) returnValue);
  return returnValue;
}

/// @fn int charToHex(char c, bool upperCase, char output[3])
///
/// @brief Convert a character to it's hexadecimal string equivalent.
///
/// @param character The character to convert.
/// @param upperCase Whether or not the output hexadecimal values should use
///   upper case (true) or lower case (false).
/// @param output The three-character array to place the hexadecimal string
///   into.
///
/// @return Returns 0 on success, -1 on failure.
int charToHex(char c, bool upperCase, char output[3]) {
  printLog(FLOOD, "ENTER charToHex(c='%c', upperCase=%s, output=%p)\n",
    c, (upperCase) ? "true" : "false", output);
  
  char a = 'A';
  if (upperCase == false) {
    a = 'a';
  }
  
  int nibble = (c >> 4) & 0x0f;
  if (nibble < 10) {
    output[0] = nibble + '0';
  } else {
    output[0] = nibble - 10 + a;
  }
  
  nibble = c & 0x0f;
  if (nibble < 10) {
    output[1] = nibble + '0';
  } else {
    output[1] = nibble - 10 + a;
  }
  
  output[2] = '\0';
  
  printLog(FLOOD, "EXIT charToHex(c='%c', upperCase=%s, output=%p) = {0}\n",
    c, (upperCase) ? "true" : "false", output);
  return 0;
}

/// @fn void *dataFindData(const volatile void *haystack, u64 haystackLength, const volatile void *needle, u64 needleLength)
///
/// @brief Find the first occurrence of needle in haystack if, if present.
///
/// @param vHaystack A pointer to the data to search.
/// @param haystackLength The length of data pointed to by vHaystack.
/// @param vNeedle A pointer to the data to find.
/// @param needleLength The length of the data pointed to by vNeedle.
void *dataFindData(const volatile void *vHaystack, u64 haystackLength,
  const volatile void *vNeedle, u64 needleLength
) {
  printLog(TRACE,
    "ENTER dataFindData(vHaystack=%p, haystackLength=%llu, "
    "vNeedle=%p, needleLength=%llu)\n",
    vHaystack, llu(haystackLength), vNeedle, llu(needleLength));
  
  if ((vHaystack == NULL) || (vNeedle == NULL)
    || (needleLength > haystackLength)
    || (needleLength == 0) || (haystackLength == 0)
  ) {
    // Cannot evaluate.
    printLog(TRACE,
      "EXIT dataFindData(vHaystack=%p, haystackLength=%llu, "
      "vNeedle=%p, needleLength=%llu) = {NULL}\n",
      vHaystack, llu(haystackLength), vNeedle, llu(needleLength));
    return NULL;
  }
  
  void *returnValue = NULL;
  const unsigned char *haystack = (unsigned char*) vHaystack;
  const unsigned char *needle = (unsigned char*) vNeedle;
  unsigned char firstNeedleChar = *needle;
  u64 maxIndex = haystackLength - needleLength;
  
  // We'll only be comparing from the second character of needle onward, so
  // adjust accordingly;
  ++needle;
  --needleLength;
  
  for (u64 i = 0; i <= maxIndex; ++i, ++haystack) {
    if (*haystack == firstNeedleChar) {
      // No need to compare the first character a second time.
      if ((needleLength == 0)
        || (memcmp((haystack + 1), needle, needleLength) == 0)
      ) {
        returnValue = (void*) haystack;
        break;
      }
    }
  }
  
  printLog(TRACE,
    "EXIT dataFindData(vHaystack=%p, haystackLength=%llu, "
    "vNeedle=%p, needleLength=%llu) = {%p}\n",
    vHaystack, llu(haystackLength), vNeedle, llu(needleLength), returnValue);
  return returnValue;
}

/// @fn Bytes getDataBetween(const volatile void *vHaystack, u64 haystackLength, const volatile void *start, u64 startLength, const volatile void *end, u64 endLength)
///
/// @brief Get the data within a haystack between a starting piece of data and
/// an ending piece of data, but not including either piece of data.  Return the
/// resulting data as a Bytes object.
///
/// @param vHaystack A pointer to the data to search.
/// @param haystackLength The length of the data at haystack.
/// @param start The starting data string to look for within haystack.
/// @param startLength The length of the data at start.  If the length is zero,
///   copy from the beginning of the haystack.
/// @param end The ending data to look for within haystack.
/// @param endLength The length of the data at end.  If the length is zero, copy
///   to the end of haystack.
///
/// @return On success, returns a Bytes object containing the portion of
/// haystack from the first character past the end of start in haystack until
/// the last character before end in haystack, inclusive.  Returns NULL on
/// failure.
Bytes getDataBetween(const volatile void *vHaystack, u64 haystackLength,
  const volatile void *start, u64 startLength,
  const volatile void *end, u64 endLength
) {
  const unsigned char *haystack = (const unsigned char*) vHaystack;
  
  printLog(TRACE,
    "ENTER getDataBetween(haystack=%p, haystackLength=%llu, "
    "start=%p, startLength=%llu, end=%p, endLength=%llu)\n",
    haystack, llu(haystackLength), start, llu(startLength), end, llu(endLength));
  
  // If the haystack is NULL then we have to return NULL.  It's not valid to
  // return any data, including empty data, if we don't have a haystack.  All
  // other combinations of parameters, including zero-length haystacks, are
  // valid.
  if (haystack == NULL) {
    printLog(TRACE,
      "EXIT getDataBetween(haystack=%p, haystackLength=%llu, "
      "start=%p, startLength=%llu, end=%p, endLength=%llu) = {NULL}\n",
      haystack, llu(haystackLength), start, llu(startLength), end, llu(endLength));
    return NULL;
  }
  
  unsigned char *startAt = (unsigned char*) haystack;
  if (startLength != 0) {
    startAt = (unsigned char*) dataFindData(
      haystack, haystackLength, start, startLength);
    if (startAt == NULL) {
      printLog(TRACE,
        "EXIT getDataBetween(haystack=%p, haystackLength=%llu, "
        "start=%p, startLength=%llu, end=%p, endLength=%llu) = {NULL}\n",
        haystack, llu(haystackLength), start, llu(startLength), end, llu(endLength));
      return NULL;
    }
    startAt += startLength;
  }
  
  u64 length = haystackLength - (startAt - haystack);
  if (endLength != 0) {
    unsigned char *endAt = (unsigned char*) dataFindData(
      startAt, length, end, endLength);
    if (endAt != NULL) {
      length = endAt - startAt;
    } else {
      printLog(TRACE,
        "EXIT getDataBetween(haystack=%p, haystackLength=%llu, "
        "start=%p, startLength=%llu, end=%p, endLength=%llu) = {NULL}\n",
        haystack, llu(haystackLength), start, llu(startLength), end, llu(endLength));
      return NULL;
    }
  } // else we copy until the end of the haystack.
  
  Bytes returnValue = (Bytes) malloc(sizeof(BytesHeader) + length + 1);
  if (returnValue == NULL) {
    LOG_MALLOC_FAILURE();
    printLog(NEVER,
      "EXIT getDataBetween(haystack=%p, haystackLength=%llu, "
      "start=%p, startLength=%llu, end=%p, endLength=%llu) = {NULL}\n",
      haystack, llu(haystackLength), start, llu(startLength), end, llu(endLength));
    return NULL;
  }
  returnValue += sizeof(BytesHeader);
  bytesSetLength(returnValue, length);
  bytesSetSize(returnValue, length + 1);
  memcpy((void*) returnValue, startAt, length);
  returnValue[length] = '\0';
  
  printLog(TRACE,
    "EXIT getDataBetween(haystack=%p, haystackLength=%llu, "
    "start=%p, startLength=%llu, end=%p, endLength=%llu) = {%p}\n",
    haystack, llu(haystackLength), start, llu(startLength), end, llu(endLength), returnValue);
  return returnValue;
}

/// @fn int vabprintf(Bytes *buffer, const char *formatString, va_list args)
///
/// @brief Allocate a buffer for a string and print a formatted string to the
///   buffer.
///
/// @param buffer is the pointer to a Bytes object to be allocated
/// @param formatString is the format string
/// @param args All further arguments are dictated by the formatString
///
/// @return Returns the number of bytes printed on success, -1 on failure.
///   On success, *buffer contains the contents of the printed string.  On
///   failure, *buffer is unmodified.
int vabprintf(Bytes *buffer, const char *formatString, va_list args) {
  int returnValue = 0;
  if (buffer == NULL) {
    fprintf(logFile, "ERROR: buffer is null in abprintf.  Cannot execute.\n");
    fflush(logFile);
    returnValue = -1;
    return returnValue;
  }
  
  va_list args2;
  va_copy(args2, args);
  
  u64 stringLength = vsnprintf(NULL, 0, formatString, args);
  if (stringLength > 0) {
    if (bytesAllocate(buffer, stringLength) == NULL) {
      fputs("Failed to allocate Bytes in vabprintf.\n", logFile);
      fflush(logFile);
      va_end(args2);
      returnValue = -1;
      return returnValue;
    }
    
    returnValue = vsprintf(str(*buffer), formatString, args2);
    bytesSetLength(*buffer, stringLength);
  }
  va_end(args2);
  
  return returnValue;
}

/// @fn int abprintf(Bytes *buffer, const char *formatString, ...)
///
/// @brief Allocate a buffer for a string and print a formatted string to the
///   buffer.
///
/// @param buffer is the pointer to a Bytes object to be allocated
/// @param formatString is the format string
/// @param ... All further arguments are dictated by the formatString
///
/// @return Returns the number of bytes printed on success, -1 on failure.
///   On success, *buffer contains the contents of the printed string.  On
///   failure, *buffer is unmodified.
int abprintf(Bytes *buffer, const char *formatString, ...) {
  int returnValue = 0;
  va_list args;
  
  va_start(args, formatString);
  returnValue = vabprintf(buffer, formatString, args);
  va_end(args);
  
  return returnValue;
}

/// @fn bool isInteger(const char *string)
///
/// @brief Determine whether or not the value in a string is a representation
///   of an integer.
///
/// @param string The string to evaluate.
///
/// @return Retuns true if all the characters in string constitute an integer,
///   false otherwise.
bool isInteger(const char *string) {
  bool returnValue = true;
  printLog(TRACE, "ENTER isInteger(string=\"%s\")\n", string);
  
  if (string == NULL) {
    printLog(TRACE, "EXIT isInteger(string=\"%s\") = {%s}\n", string,
      "false");
    return false;
  }
  
  int startIndex = 0;
  if ((string[0] == '+') || (string[0] == '-')) {
    startIndex = 1;
  }
  
  for (int i = startIndex; string[i] != '\0'; i++) {
    if (string[i] < '0' || string[i] > '9') {
      returnValue = false;
      break;
    }
  }
  
  printLog(TRACE, "EXIT isInteger(string=\"%s\") = {%s}\n", string,
    (returnValue == true) ? "true" : "false");
  return returnValue;
}

/// @fn bool isNumber(const char *string)
///
/// @brief Determine whether or not the value in a string is a representation
///   of a number.
///
/// @param string The string to evaluate.
///
/// @return Retuns true if all the characters in string are numeric, false
///   otherwise.
bool isNumber(const char *string) {
  bool returnValue = true;
  printLog(TRACE, "ENTER isNumber(string=\"%s\")\n", string);
  
  if (string == NULL) {
    printLog(TRACE, "EXIT isNumber(string=\"%s\") = {%s}\n", string,
      "false");
    return false;
  }
  
  int startIndex = 0;
  if ((string[0] == '+') || (string[0] == '-')) {
    startIndex = 1;
  }
  if (string[startIndex] < '0' || string[startIndex] > '9') {
    printLog(TRACE, "EXIT isNumber(string=\"%s\") = {%s}\n", string,
      "false");
    return false;
  }
  startIndex++;
  
  bool dotSeen = false;
  bool eSeen = false;
  for (int i = startIndex; string[i] != '\0'; i++) {
    if (string[i] == '.') {
      if (dotSeen == false) {
        dotSeen = true;
        i++;
        if (string[i] < '0' || string[i] > '9') {
          returnValue = false;
          break;
        }
      } else {
        returnValue = false;
        break;
      }
    } else if ((string[i] == 'e') || (string[i] == 'E')) {
      if ((eSeen == false) && (dotSeen == true)) {
        eSeen = true;
        i++;
        if ((string[i] != '+') && (string[i] != '-')) {
          returnValue = false;
          break;
        }
        i++;
        if (string[i] < '0' || string[i] > '9') {
          returnValue = false;
          break;
        }
      } else {
        returnValue = false;
        break;
      }
    } else if (string[i] < '0' || string[i] > '9') {
      returnValue = false;
      break;
    }
  }
  
  printLog(TRACE, "EXIT isNumber(string=\"%s\") = {%s}\n", string,
    (returnValue == true) ? "true" : "false");
  return returnValue;
}

/// @fn const char *getProgramName(const char *argv0)
///
/// @brief Get the program name (the leaf) from the value of argv[0].
///
/// @return This function always succeeds and always returns a valid
/// program name.
const char *getProgramName(const char *argv0) {
  const char *programName = strrchr(argv0, '/');
  if (programName == NULL) {
    programName = strrchr(argv0, '\\');
  }
  if (programName != NULL) {
    programName = programName + 1;
  } else {
    programName = argv0;
  }
  
  return programName;
}

/// @fn bool stringStartsWith(const char *haystack, const char *beginning)
///
/// @brief Determine if a given haystack starts with a given beginning.
///
/// @param haystack The string to examine.
/// @param beginning The beginning to look for.
///
/// @return Returns true if haystack starts with beginning, false if not.
bool stringStartsWith(const char *haystack, const char *beginning) {
  printLog(TRACE,
    "ENTER stringStartsWith(haystack=\"%s\", beginning=\"%s\")\n",
    haystack, beginning);
  
  bool startsWithBeginning = false;
  if ((haystack == NULL) || (beginning == NULL)) {
    printLog(TRACE,
      "EXIT stringStartsWith(haystack=\"%s\", beginning=\"%s\") = {%s}\n",
      haystack, beginning, (startsWithBeginning == true) ? "true" : "false");
    return startsWithBeginning; // false
  }
  
  startsWithBeginning
    = (strncmp(haystack, beginning, strlen(beginning)) == 0);
  
  printLog(TRACE,
    "EXIT stringStartsWith(haystack=\"%s\", beginning=\"%s\") = {%s}\n",
    haystack, beginning, (startsWithBeginning == true) ? "true" : "false");
  return startsWithBeginning;
}

/// @fn bool stringStartsWithCi(const char *haystack, const char *beginning)
///
/// @brief Determine if a given haystack starts with a given beginning using
/// case-insensitve comparsion.
///
/// @param haystack The string to examine.
/// @param beginning The beginning to look for.
///
/// @return Returns true if haystack starts with beginning, false if not.
bool stringStartsWithCi(const char *haystack, const char *beginning) {
  printLog(TRACE,
    "ENTER stringStartsWithCi(haystack=\"%s\", beginning=\"%s\")\n",
    haystack, beginning);
  
  bool startsWithBeginning
    = (strncmpci(haystack, beginning, strlen(beginning)) == 0);
  
  printLog(TRACE,
    "EXIT stringStartsWithCi(haystack=\"%s\", beginning=\"%s\") = {%s}\n",
    haystack, beginning, (startsWithBeginning == true) ? "true" : "false");
  return startsWithBeginning;
}

/// @fn bool bytesArrayAddField(Bytes **array, u64 beforeIndex)
///
/// @brief Add a new field in an existing Bytes array before a specified index.
///
/// @param array A pointer to an existing, one-dimensional, NULL-terminated
///   Bytes array.  This array will be extended by one index on success.
/// @param beforeIndex The index before which a new field should be added.
///
/// @return Returns true on success, false on failure.  The array will be
/// unmodified on failure.
bool bytesArrayAddField(Bytes **array, u64 beforeIndex) {
  printLog(TRACE, "ENTER bytesArrayAddField(array=%p, beforeIndex=%llu)\n",
    array, llu(beforeIndex));
  
  bool successful = true;
  
  // Parameter check the array.
  if (array == NULL) {
    printLog(ERR, "Invalid array parameter.\n");
    successful = false;
    printLog(TRACE,
      "EXIT bytesArrayAddField(array=%p, beforeIndex=%llu) = {%s}\n",
      array, llu(beforeIndex),
      (successful == true) ? "successful" : "NOT successful");
    return successful;
  } else if (*array == NULL) {
    if (beforeIndex == 0) {
      // We're being asked to create a new array with one index.
      // Zero-initialize a single-element array.
      *array = (Bytes*) calloc(1, sizeof(Bytes));
      if (*array == NULL) {
        LOG_MALLOC_FAILURE();
        successful = false;
        printLog(TRACE,
          "EXIT bytesArrayAddField(array=%p, beforeIndex=%llu) = {%s}\n",
          array, llu(beforeIndex),
          (successful == true) ? "successful" : "NOT successful");
        return successful;
      }
    } else {
      printLog(ERR, "Invalid array and beforeIndex parameters.\n");
      successful = false;
      printLog(TRACE,
        "EXIT bytesArrayAddField(array=%p, beforeIndex=%llu) = {%s}\n",
        array, llu(beforeIndex),
        (successful == true) ? "successful" : "NOT successful");
      return successful;
    }
  }
  
  // Compute the array length and parameter check beforeIndex.
  u64 arrayLength = 0;
  for (; (*array)[arrayLength] != NULL; arrayLength++);
  if (beforeIndex > arrayLength) {
    printLog(ERR, "Invalid beforeIndex.\n");
    successful = false;
    printLog(TRACE,
      "EXIT bytesArrayAddField(array=%p, beforeIndex=%llu) = {%s}\n",
      array, llu(beforeIndex),
      (successful == true) ? "successful" : "NOT successful");
    return successful;
  }
  
  // Extend the array.
  Bytes *check = (Bytes*) realloc(*array, sizeof(Bytes) * (arrayLength + 2));
  if (check == NULL) {
    LOG_MALLOC_FAILURE();
    successful = false;
    return successful;
  }
  *array = check;
  
  // arrayLength is now the index of the last cell in the array.  Move
  // everything from the new index down one index and allocate the new index
  // so that it's not NULL.
  for (u64 arrayIndex = arrayLength + 1;
    arrayIndex > beforeIndex;
    arrayIndex--
  ) {
    (*array)[arrayIndex] = (*array)[arrayIndex - 1];
  }
  u64 newIndex = beforeIndex;
  (*array)[newIndex] = NULL;
  bytesAddStr(&(*array)[newIndex], "");
  
  printLog(TRACE,
    "EXIT bytesArrayAddField(array=%p, beforeIndex=%llu) = {%s}\n",
    array, llu(beforeIndex),
    (successful == true) ? "successful" : "NOT successful");
  return successful;
}

/// @fn bool bytesTableAddField(Bytes ***table, u64 beforeIndex)
///
/// @brief Add a new field in an existing Bytes table before a specified index.
///
/// @param table A pointer to an existing, two-dimensional, NULL-terminated
///   Bytes table.
/// @param beforeIndex The index before which a new field should be added.
///
/// @return Returns true on success, false on failure.
bool bytesTableAddField(Bytes ***table, u64 beforeIndex) {
  printLog(TRACE,
    "ENTER bytesTableAddField(table=%p, beforeIndex=%llu)\n",
    table, llu(beforeIndex));
  
  bool successful = true;
  
  // Parameter check the table.
  if ((table == NULL) || (*table == NULL)) {
    printLog(ERR, "Invalid table parameter.\n");
    successful = false;
    printLog(TRACE,
      "EXIT bytesTableAddField(table=%p, beforeIndex=%llu) = {%s}\n",
      table, llu(beforeIndex),
      (successful == true) ? "successful" : "NOT successful");
    return successful;
  }
  
  // Extend all the rows in the table.
  for (u64 rowIndex = 0; (*table)[rowIndex] != NULL; rowIndex++)
  {
    successful &= bytesArrayAddField(&(*table)[rowIndex], beforeIndex);
  }
  
  printLog(TRACE,
    "EXIT bytesTableAddField(table=%p, beforeIndex=%llu) = {%s}\n",
    table, llu(beforeIndex),
    (successful == true) ? "successful" : "NOT successful");
  return successful;
}

/// @fn Bytes dataToHexBytes(const volatile void *data, u64 length)
///
/// @brief Convert a data blob to a Bytes object containing the data's
/// hexadecimal representation.
///
/// @param data A pointer to the data to convert.
/// @param length The number of bytes that make up the data.
///
/// @return Returns a newly-allocated Bytes object with the encoded data on
/// success, NULL on failure.
Bytes dataToHexBytes(const volatile void *data, u64 length) {
  printLog(TRACE, "ENTER dataToHexBytes(data=%p, length=%llu)\n",
    data, llu(length));
  
  Bytes returnValue = NULL;
  if ((data == NULL) || (length == 0)) {
    printLog(TRACE, "EXIT dataToHexBytes(data=%p, length=%llu) = {%p}\n",
      data, llu(length), returnValue);
    return returnValue;
  }
  
  u64 returnValueLength = length << 1;
  if (bytesAllocate(&returnValue, returnValueLength) == NULL) {
    LOG_MALLOC_FAILURE();
    return NULL;
  }
  
  char *characters = (char*) data;
  
  for (u64 i = 0, j = 0; i < length; i++, j += 2) {
    // charToHex always returns 0, so there's no point in checking the return
    // value here.
    (void) charToHex(characters[i], false, str(&returnValue[j]));
  }
  bytesSetLength(returnValue, returnValueLength);
  returnValue[returnValueLength] = '\0';
  
  printLog(TRACE, "EXIT dataToHexBytes(data=%p, length=%llu) = {%p}\n",
    data, llu(length), returnValue);
  return returnValue;
}

/// @fn Bytes hexStringToBytes(const char *hexString, u64 length)
///
/// @brief Convert a string of hexadecimal characters to its raw data equivalent
/// in bytes form.
///
/// @param hexString A pointer to a string of purely-hexadecimal characters.
/// @param length The number of bytes that make up the hexString.
///
/// @return Returns a newly-allocated Bytes object with the decoded data on
/// success, NULL on failure.
Bytes hexStringToBytes(const char *hexString, u64 length) {
  printLog(TRACE, "ENTER hexStringToBytes(hexString=%p, length=%llu)\n",
    hexString, llu(length));
  
  Bytes returnValue = NULL;
  if ((hexString == NULL) || (length == 0)) {
    // Nothing to do.
    printLog(TRACE, "EXIT hexStringToBytes(hexString=%p, length=%llu) = {%p}\n",
      hexString, llu(length), returnValue);
    return returnValue;
  }
  
  u64 returnValueLength = length >> 1;
  if (bytesAllocate(&returnValue, returnValueLength) == NULL) {
    LOG_MALLOC_FAILURE();
    return NULL;
  }
  
  for (u64 i = 0, j = 0; i < returnValueLength; i++, j += 2) {
    returnValue[i] = hexToChar(&hexString[j]);
  }
  bytesSetLength(returnValue, returnValueLength);
  returnValue[returnValueLength] = '\0';
  
  printLog(TRACE, "EXIT hexStringToBytes(hexString=%p, length=%llu) = {%p}\n",
    hexString, llu(length), returnValue);
  return returnValue;
}

/// @fn bool dataIsString(const volatile void *data, u64 dataLength)
///
/// @brief Determine whether or not a block of arbitrary data constitutes a
/// C string.
///
/// @param data A pointer to an arbitrary block of memory (cast to a void*).
/// @param dataLength The number of bytes pointed to by the data pointer.
///
/// @return Returns true if the data provided constitutes a C string, false
/// if not.
bool dataIsString(const volatile void *data, u64 dataLength) {
  printLog(TRACE, "ENTER dataIsString(data=%p, dataLength=%llu)\n",
    data, llu(dataLength));
  
  u8 *dataBytes = (u8*) data;
  bool returnValue = true;
  u64 lastCharIndex = 0;
  if (dataLength > 0) {
    lastCharIndex = dataLength - 1;
  }
  
  if (data == NULL) {
    // NULL data is not a string.
    returnValue = false;
    printLog(TRACE, "EXIT dataIsString(data=%p, dataLength=%llu) = {%s}\n",
      data, llu(dataLength), boolNames[returnValue]);
    return returnValue;
  }
  
  u64 i = 0;
  for (i = 0; i < lastCharIndex; i++) {
    if (((dataBytes[i] < 32) || (dataBytes[i] > 126))
      && (dataBytes[i] != '\r') && (dataBytes[i] != '\n')
      && (dataBytes[i] != '\0')
    ) {
      returnValue = false;
      break;
    }
  }
  
  if (dataBytes[i] != '\0') {
    returnValue = false;
  }
  
  printLog(TRACE, "EXIT dataIsString(data=%p, dataLength=%llu) = {%s}\n",
    data, llu(dataLength), boolNames[returnValue]);
  return returnValue;
}

extern char base64Characters[64];
extern u32 base64Values[128];

/// @fn Bytes dataToBase64(const volatile void *data, u64 dataLength)
///
/// @brief Convert an arbitrary blob of data to its base64 representation.
///
/// @param data A pointer to the data to encode.
/// @param dataLength The number of bytes to encode at the data pointer.
///
/// @return Returns a new Bytes object with the base64-encoded string on
/// success, NULL on failure.
Bytes dataToBase64(const volatile void *data, u64 dataLength) {
  printLog(TRACE, "ENTER dataToBase64(data=%p, dataLength=%llu)\n",
    data, llu(dataLength));
  
  u64 outputLength = (dataLength << 2) / 3;
  u64 remainder = dataLength % 3;
  if (remainder == 1) {
    outputLength += 3;
  } else if (remainder == 2) {
    outputLength += 2;
  }
  Bytes output = NULL;
  bytesAllocate(&output, outputLength);
  bytesSetLength(output, outputLength);
  
  unsigned char *dataChars = (unsigned char*) data;
  char *outputChars = (char*) output;
  u64 numBytesInLoop = (dataLength / 3) * 3;
  u32 numberToEncode = 0;
  u64 ii = 0;
  for (ii = 0; ii < numBytesInLoop; ii += 3) {
    // First, convert three characters to a 24-bit number stored in a 32-bit
    // number.
    numberToEncode
      = (((u32) dataChars[0]) << 16)
      | (((u32) dataChars[1]) <<  8)
      | (((u32) dataChars[2])      );
    dataChars += 3;
    
    // Next, map the numbers to their corrsponding Base64 ASCII characters.
    outputChars[0] = base64Characters[(numberToEncode >> 18) & 0x3f];
    outputChars[1] = base64Characters[(numberToEncode >> 12) & 0x3f];
    outputChars[2] = base64Characters[(numberToEncode >>  6) & 0x3f];
    outputChars[3] = base64Characters[(numberToEncode      ) & 0x3f];
    outputChars += 4;
  }
  if (ii < dataLength) {
    numberToEncode
      = (((u32) dataChars[0]) << 16)
      | (((dataLength - ii) > 1) ? (((u32) dataChars[1]) <<  8) : 0)
      | (((dataLength - ii) > 2) ? (((u32) dataChars[2])      ) : 0);
    dataChars += 3;
    
    outputChars[0] = base64Characters[(numberToEncode >> 18) & 0x3f];
    outputChars[1] = base64Characters[(numberToEncode >> 12) & 0x3f];
    outputChars[2] = ((dataLength - ii) > 1)
      ? base64Characters[(numberToEncode >> 6) & 0x3f]
      : '=';
    outputChars[3] = ((dataLength - ii) > 2)
      ? base64Characters[numberToEncode & 0x3f]
      : '=';
    outputChars += 4;
  }
  *outputChars = '\0';
  
  printLog(TRACE, "EXIT dataToBase64(data=%p, dataLength=%llu) = {%p}\n",
    data, llu(dataLength), output);
  return output;
}

/// @fn Bytes base64ToBytes(const char *base64String, u64 base64StringLength)
///
/// @brief Convert a base64-encoded string back to its binary representation.
///
/// @param base64String The base64-encoded string to decode.
/// @param base64StringLength The number of bytes that make up the base64String.
///
/// @return Returns a Bytes object with the decoded content on success, NULL on
/// failure.
Bytes base64ToBytes(const char *base64String, u64 base64StringLength) {
  printLog(TRACE,
    "ENTER base64ToBytes(base64String=%p, base64StringLength=%llu)\n",
    base64String, llu(base64StringLength));
  
  Bytes output = NULL;
  if ((base64StringLength * 3) % 4) {
    printLog(ERR, "Invalid base64StringLength %llu.\n",
      llu(base64StringLength));
    printLog(TRACE,
      "EXIT base64ToBytes(base64String=%p, base64StringLength=%llu) = {%p}\n",
      base64String, llu(base64StringLength), output);
    return output; // NULL
  }
  
  u64 outputLength = (base64StringLength * 3) >> 2;
  bytesAllocate(&output, outputLength);
  unsigned char *outputChars = output;
  
  for (u64 ii = 0; ii < base64StringLength; ii += 4) {
    // C doesn't like it when array indexes are chars, so cast them to size_t.
    u32 numberToDecode
      = (base64Values[(size_t) base64String[0]] << 18)
      | (base64Values[(size_t) base64String[1]] << 12)
      | (base64Values[(size_t) base64String[2]] <<  6)
      | (base64Values[(size_t) base64String[3]]      );
    base64String += 4;

    outputChars[0] = numberToDecode >> 16 & 0xff;
    outputChars[1] = numberToDecode >>  8 & 0xff;
    outputChars[2] = numberToDecode       & 0xff;
    outputChars += 3;
  }
  if (outputLength > 0) {
    for (; output[outputLength - 1] == '\0'; outputLength--);
  }
  bytesSetLength(output, outputLength);
  
  printLog(TRACE,
    "EXIT base64ToBytes(base64String=%p, base64StringLength=%llu) = {%p}\n",
    base64String, llu(base64StringLength), output);
  return output;
}

/// @var base64Characters
///
/// @brief Mapping of Base64 values to their corresponding characters.
char base64Characters[64] = {
  'A',
  'B',
  'C',
  'D',
  'E',
  'F',
  'G',
  'H',
  'I',
  'J',
  'K',
  'L',
  'M',
  'N',
  'O',
  'P',
  'Q',
  'R',
  'S',
  'T',
  'U',
  'V',
  'W',
  'X',
  'Y',
  'Z',
  'a',
  'b',
  'c',
  'd',
  'e',
  'f',
  'g',
  'h',
  'i',
  'j',
  'k',
  'l',
  'm',
  'n',
  'o',
  'p',
  'q',
  'r',
  's',
  't',
  'u',
  'v',
  'w',
  'x',
  'y',
  'z',
  '0',
  '1',
  '2',
  '3',
  '4',
  '5',
  '6',
  '7',
  '8',
  '9',
  '+',
  '/'
};

/// @var base64Values
///
/// @brief Mapping of Base64 characters to their corresponding values.
u32 base64Values[128] = {
  0,  // 0
  0,  // 1
  0,  // 2
  0,  // 3
  0,  // 4
  0,  // 5
  0,  // 6
  0,  // 7
  0,  // 8
  0,  // 9
  0,  // 10
  0,  // 11
  0,  // 12
  0,  // 13
  0,  // 14
  0,  // 15
  0,  // 16
  0,  // 17
  0,  // 18
  0,  // 19
  0,  // 20
  0,  // 21
  0,  // 22
  0,  // 23
  0,  // 24
  0,  // 25
  0,  // 26
  0,  // 27
  0,  // 28
  0,  // 29
  0,  // 30
  0,  // 31
  0,  // space
  0,  // !
  0,  // "
  0,  // #
  0,  // $
  0,  // %
  0,  // &
  0,  // '
  0,  // (
  0,  // )
  0,  // *
  62, // +
  0,  // ,
  0,  // -
  0,  // .
  63, // /
  52, // 0
  53, // 1
  54, // 2
  55, // 3
  56, // 4
  57, // 5
  58, // 6
  59, // 7
  60, // 8
  61, // 9
  0,  // :
  0,  // ;
  0,  // <
  0,  // =
  0,  // >
  0,  // ?
  0,  // @
  0,  // A
  1,  // B
  2,  // C
  3,  // D
  4,  // E
  5,  // F
  6,  // G
  7,  // H
  8,  // I
  9,  // J
  10, // K
  11, // L
  12, // M
  13, // N
  14, // O
  15, // P
  16, // Q
  17, // R
  18, // S
  19, // T
  20, // U
  21, // V
  22, // W
  23, // X
  24, // Y
  25, // Z
  0,  // [
  0,  // backslash
  0,  // ]
  0,  // ^
  0,  // _
  0,  // `
  26, // a
  27, // b
  28, // c
  29, // d
  30, // e
  31, // f
  32, // g
  33, // h
  34, // i
  35, // j
  36, // k
  37, // l
  38, // m
  39, // n
  40, // o
  41, // p
  42, // q
  43, // r
  44, // s
  45, // t
  46, // u
  47, // v
  48, // w
  49, // x
  50, // y
  51, // z
  0,  // {
  0,  // |
  0,  // }
  0,  // ~
  0   // delete
};

