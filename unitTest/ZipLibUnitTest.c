////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                     Copyright (c) 2012-2025 James Card                     //
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

#include "ZipLib.h"
#include "LoggingLib.h"

bool compressedDataUnitTest(void) {
  const char *inputData = "The quick brown fox jumped over the lazy dogs.";
  i64 inputDataLength = (i64) strlen(inputData) + 1;
  char *outputData = NULL;
  i64 outputDataLength = 0;
  
  CompressedData *compressedData = compressData(inputData, inputDataLength);
  if (compressedData == NULL) {
    printLog(ERR, "compressData with valid input data returned NULL.\n");
    return false;
  }
  if (compressedDataGetLength(compressedData) > inputDataLength) {
    printLog(ERR, "Compressed data is %llu Bytes longer than the input.\n",
      llu(compressedDataGetLength(compressedData) - inputDataLength));
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  printLog(INFO, "compressData returned %llu bytes.\n",
    llu(compressedDataGetLength(compressedData)));
  printLog(INFO, "Data:\n");
  printBinary(INFO, compressedDataGetData(compressedData),
    compressedDataGetLength(compressedData));
  
  outputData = (char*) decompressData(compressedData);
  if (outputData == NULL) {
    printLog(ERR, "decompressData with valid CompressedData returned NULL.\n");
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  if (strcmp(inputData, outputData) != 0) {
    printLog(ERR, "Decompressed data did not match inputData.\n");
    printLog(ERR, "Expected \"%s\"\n.", inputData);
    printLog(ERR, "Got \"%s\"\n.", outputData);
    outputData = stringDestroy(outputData);
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  outputData = stringDestroy(outputData);
  
  outputData = (char*) decompressData(compressedData, &outputDataLength);
  if (outputData == NULL) {
    printLog(ERR,
      "decompressData with valid outputDataLength returned NULL.\n");
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  if (outputDataLength != inputDataLength) {
    printLog(ERR, "inputDataLength did not match outputDataLength.\n");
    printLog(ERR, "Expected %llu.\n", llu(inputDataLength + 1));
    printLog(ERR, "Got %llu.\n", llu(outputDataLength));
    outputData = stringDestroy(outputData);
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  if (strcmp(inputData, outputData) != 0) {
    printLog(ERR, "Decompressed data did not match inputData.\n");
    printLog(ERR, "Expected \"%s\"\n.", inputData);
    printLog(ERR, "Got \"%s\"\n.", outputData);
    outputData = stringDestroy(outputData);
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  outputData = stringDestroy(outputData);
  compressedData = compressedDataDestroy(compressedData);
  
  inputData = "The quick brown fox jumped over the lazy dogs."
    "The quick brown fox jumped over the lazy dogs.";
  inputDataLength = (i64) strlen(inputData) + 1;
  outputData = NULL;
  outputDataLength = 0;
  compressedData = compressData(inputData, inputDataLength);
  if (compressedData == NULL) {
    printLog(ERR, "compressData with valid input data returned NULL.\n");
    return false;
  }
  if (compressedDataGetLength(compressedData) > inputDataLength) {
    printLog(ERR, "Compressed data is %llu Bytes longer than the input.\n",
      llu(compressedDataGetLength(compressedData) - inputDataLength));
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  printLog(INFO, "compressData returned %llu bytes.\n",
    llu(compressedDataGetLength(compressedData)));
  printLog(INFO, "Data:\n");
  printBinary(INFO, compressedDataGetData(compressedData),
    compressedDataGetLength(compressedData));
  
  outputData = (char*) decompressData(compressedData, &outputDataLength);
  if (outputData == NULL) {
    printLog(ERR,
      "decompressData with valid outputDataLength returned NULL.\n");
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  if (outputDataLength != inputDataLength) {
    printLog(ERR, "inputDataLength did not match outputDataLength.\n");
    printLog(ERR, "Expected %llu.\n", llu(inputDataLength + 1));
    printLog(ERR, "Got %llu.\n", llu(outputDataLength));
    outputData = stringDestroy(outputData);
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  if (strcmp(inputData, outputData) != 0) {
    printLog(ERR, "Decompressed data did not match inputData.\n");
    printLog(ERR, "Expected \"%s\"\n.", inputData);
    printLog(ERR, "Got \"%s\"\n.", outputData);
    outputData = stringDestroy(outputData);
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  outputData = stringDestroy(outputData);
  compressedData = compressedDataDestroy(compressedData);
  
  compressedData = compressData(NULL, inputDataLength);
  if (compressedData != NULL) {
    printLog(ERR, "compressData returned non-NULL with NULL inputData.\n");
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  
  compressedData = compressData(inputData, 0);
  if (compressedData != NULL) {
    printLog(ERR,
      "compressData returned non-NULL with zero-length inputData.\n");
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  
  compressedData = compressData(NULL, 0);
  if (compressedData != NULL) {
    printLog(ERR,
      "compressData returned non-NULL with NULL and zero-length inputData.\n");
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  
  outputData = (char*) decompressData(NULL, &outputDataLength);
  if (outputData != NULL) {
    printLog(ERR,
      "decompressData returned non-NULL with NULL compressedData.\n");
    outputData = stringDestroy(outputData);
    return false;
  }
  
  outputData = (char*) decompressData(NULL, NULL);
  if (outputData != NULL) {
    printLog(ERR,
      "decompressData returned non-NULL with NULL compressedData and "
      "output length.\n");
    outputData = stringDestroy(outputData);
    return false;
  }
  
  /* Get a legitimate CompressedData object to play with. */
  compressedData = compressData(inputData, inputDataLength);
  if (compressedData == NULL) {
    printLog(ERR, "compressData with valid input data returned NULL.\n");
    return false;
  }
  outputData = stringDestroy(outputData);
  outputDataLength = 0;
  
  Bytes compressedBytes
    = compressedDataToBlob(compressedData);
  if (compressedBytes == NULL) {
    printLog(ERR, "compressedDataToBlob with good input returned NULL.\n");
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  outputDataLength = bytesSize(compressedBytes);
  
  CompressedData *newCompressedData
    = compressedDataFromBlob(compressedBytes, &outputDataLength);
  compressedBytes = bytesDestroy(compressedBytes);
  if (newCompressedData == NULL) {
    printLog(ERR,
      "compressedDataFromBlob with good input returned NULL.\n");
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  
  outputData = (char*) decompressData(newCompressedData);
  if (outputData == NULL) {
    printLog(ERR, "decompressData with newCompressedData returned NULL.\n");
    newCompressedData = compressedDataDestroy(newCompressedData);
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  if (strcmp(inputData, outputData) != 0) {
    printLog(ERR,
      "Data returned from decompressData with newCompressedData was not "
      "as expected.\n");
    printLog(ERR, "Expected \"%s\".\n", inputData);
    printLog(ERR, "Found \"%s\".\n", outputData);
    outputData = stringDestroy(outputData);
    newCompressedData = compressedDataDestroy(newCompressedData);
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  
  outputData = stringDestroy(outputData);
  newCompressedData = compressedDataDestroy(newCompressedData);
  compressedData = compressedDataDestroy(compressedData);
  
  /* Verify that encoding the dataIsRaw bit as the high-order bit of the */
  /* header works correctly. */
  inputData = "The quick brown fox jumped over the lazy dogs.";
  inputDataLength = (i64) strlen(inputData) + 1;
  compressedData = compressData(inputData, inputDataLength);
  if (compressedData == NULL) {
    printLog(ERR, "compressData with valid input data returned NULL.\n");
    return false;
  }
  compressedBytes
    = compressedDataToBlob(compressedData);
  if (compressedBytes == NULL) {
    printLog(ERR, "compressedDataToBlob with good input returned NULL.\n");
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  outputDataLength = bytesSize(compressedBytes);
  newCompressedData
    = compressedDataFromBlob(compressedBytes, &outputDataLength);
  compressedBytes = bytesDestroy(compressedBytes);
  if (newCompressedData == NULL) {
    printLog(ERR,
      "compressedDataFromBlob with good input returned NULL.\n");
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  outputData = (char*) decompressData(newCompressedData);
  if (outputData == NULL) {
    printLog(ERR, "decompressData with newCompressedData returned NULL.\n");
    newCompressedData = compressedDataDestroy(newCompressedData);
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  if (strcmp(inputData, outputData) != 0) {
    printLog(ERR,
      "Data returned from decompressData with newCompressedData was not "
      "as expected.\n");
    printLog(ERR, "Expected \"%s\".\n", inputData);
    printLog(ERR, "Found \"%s\".\n", outputData);
    outputData = stringDestroy(outputData);
    newCompressedData = compressedDataDestroy(newCompressedData);
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  
  outputData = stringDestroy(outputData);
  newCompressedData = compressedDataDestroy(newCompressedData);
  
  /* Verify negative cases. */
  compressedBytes = compressedDataToBlob(NULL);
  if (outputData != NULL) {
    printLog(ERR,
      "compressedDataToBlob with NULL input returned non-NULL.\n");
    outputData = stringDestroy(outputData);
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  
  compressedBytes
    = compressedDataToBlob(compressedData);
  outputDataLength = bytesSize(compressedBytes);
  if (compressedBytes == NULL) {
    printLog(ERR, "compressedDataToBlob with good input returned NULL.\n");
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  
  outputDataLength -= 2;
  newCompressedData
    = compressedDataFromBlob(compressedBytes, &outputDataLength);
  if (newCompressedData != NULL) {
    printLog(ERR,
      "compressedDataFromBlob with short data length "
      "returned non-NULL.\n");
    newCompressedData = compressedDataDestroy(newCompressedData);
    compressedBytes = bytesDestroy(compressedBytes);
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  
  compressedBytes = bytesDestroy(compressedBytes);
  compressedData = compressedDataDestroy(compressedData);
  
  /* Verify encoding/decoding. */
  inputData = "The quick brown fox jumped over the lazy dogs."
    "The quick brown fox jumped over the lazy dogs.";
  inputDataLength = (i64) strlen(inputData) + 1;
  compressedData = compressData(inputData, inputDataLength);
  if (compressedDataGetLength(compressedData) >= inputDataLength) {
    printLog(ERR, "Could not compress compressible data.\n");
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  outputData = (char*) decompressData(compressedData, &outputDataLength);
  if ((outputDataLength != inputDataLength)
    || (strcmp(outputData, inputData) != 0)
  ) {
    printLog(ERR, "outputData did not match inputData.\n");
    printLog(ERR, "Expected \"%s\" (%lld bytes).\n",
      inputData, lld(inputDataLength));
    printLog(ERR, "Got \"%s\" (%lld bytes).\n",
      outputData, lld(outputDataLength));
    outputData = stringDestroy(outputData);
    return false;
  }
  outputData = stringDestroy(outputData);
  
  char *escapedString = escapeData(compressedDataGetData(compressedData),
    compressedDataGetLength(compressedData));
  Bytes escapedBytes = NULL;
  bytesAddStr(&escapedBytes, escapedString);
  escapedString = stringDestroy(escapedString);
  unescapeBytes(escapedBytes);
  if ((bytesLength(escapedBytes)
      != (u64) compressedDataGetLength(compressedData))
    || (memcmp((void*) escapedBytes, compressedDataGetData(compressedData),
      bytesLength(escapedBytes)) != 0)
  ) {
    printLog(ERR, "Unescaped Bytes did not match compressedData.\n");
    printLog(ERR, "Expected %llu bytes, got %llu.\n",
      llu(compressedDataGetLength(compressedData)),
      llu(bytesLength(escapedBytes)));
    u64 length = bytesLength(escapedBytes);
    if ((u64) compressedDataGetLength(compressedData) < length) {
      length = (u64) compressedDataGetLength(compressedData);
    }
    unsigned char *data
      = (unsigned char*) compressedDataGetData(compressedData);
    for (u64 i = 0; i < length; i++) {
      if (escapedBytes[i] != data[i]) {
        printLog(ERR, "Byte %llu, expected '%c' (0x%02X), got '%c' (0x%02X).\n",
          llu(i), data[i], data[i], escapedBytes[i], escapedBytes[i]);
        if (i > 0) {
          printLog(ERR, "Byte %llu, was '%c' (0x%02X).\n", 
            llu(i - 1), data[i - 1], data[i - 1]);
        }
        break;
      }
    }
    escapedBytes = bytesDestroy(escapedBytes);
    compressedData = compressedDataDestroy(compressedData);
    return false;
  }
  compressedData = compressedDataDestroy(compressedData);
  
  compressedData = compressedDataCreate(escapedBytes, bytesLength(escapedBytes),
    false, true);
  outputData = (char*) decompressData(compressedData, &outputDataLength);
  compressedData = compressedDataDestroy(compressedData);
  escapedBytes = bytesDestroy(escapedBytes);
  
  if ((outputDataLength != inputDataLength)
    || (strcmp(outputData, inputData) != 0)
  ) {
    printLog(ERR, "outputData did not match inputData.\n");
    printLog(ERR, "Expected \"%s\" (%lld bytes).\n",
      inputData, lld(inputDataLength));
    printLog(ERR, "Got \"%s\" (%lld bytes).\n",
      outputData, lld(outputDataLength));
    outputData = stringDestroy(outputData);
    return false;
  }
  outputData = stringDestroy(outputData);
  
  return true;
}

/// @fn bool zipVerifyEntry(Zip *zip, i64 entryIndex, const char *entryName, const char *expectedData)
///
/// @brief Verify a single entry within a known zip archive.
///
/// @param zip A pointer to the Zip object the entry is in.
/// @param entryIndex The index of the entry in the zip archive.
/// @param entryName The name of the entry in the zip archive.
/// @param expectedData The expected content of the entry data.
///
/// @return Returns true on success, false on failure.
bool zipVerifyEntry(Zip *zip, i64 entryIndex, const char *entryName,
  const char *expectedData
) {
  i64 expectedDataLength = (i64) strlen(expectedData);
  
  void *data = zipReadEntryByName(zip, entryName, NULL);
  if (data == NULL) {
    printLog(ERR, "NULL data returned when trying to read %s.\n", entryName);
    zip = zipDestroy(zip);
    return false;
  } else if (strncmp((char*) data, expectedData, expectedDataLength) != 0) {
    printLog(ERR, "Expected data to be \"%s\".  Found \"%s\".\n",
      expectedData, (char*) data);
    zip = zipDestroy(zip);
    return false;
  }
  data = pointerDestroy(data);
  
  i64 dataLength = 0;
  data = zipReadEntryByName(zip, entryName, &dataLength);
  if (data == NULL) {
    printLog(ERR, "NULL data returned when trying to read %s.\n", entryName);
    zip = zipDestroy(zip);
    return false;
  } else if (dataLength != expectedDataLength) {
    printLog(ERR, "Expected dataLength to be %llu.  Found %llu.\n",
      llu(expectedDataLength), llu(dataLength));
    zip = zipDestroy(zip);
    return false;
  } else if (strncmp((char*) data, expectedData, expectedDataLength) != 0) {
    printLog(ERR, "Expected data to be \"%s\".  Found \"%s\".\n",
      expectedData, (char*) data);
    zip = zipDestroy(zip);
    return false;
  }
  data = pointerDestroy(data);
  
  data = zipReadEntryByIndex(zip, entryIndex, NULL);
  if (data == NULL) {
    printLog(ERR, "NULL data returned when trying to read entry %llu.\n",
      llu(entryIndex));
    zip = zipDestroy(zip);
    return false;
  } else if (strncmp((char*) data, expectedData, expectedDataLength) != 0) {
    printLog(ERR, "Expected data to be \"%s\".  Found \"%s\".\n",
      expectedData, (char*) data);
    zip = zipDestroy(zip);
    return false;
  }
  data = pointerDestroy(data);
  
  data = zipReadEntryByIndex(zip, entryIndex, &dataLength);
  if (data == NULL) {
    printLog(ERR, "NULL data returned when trying to read entry %llu.\n",
      llu(entryIndex));
    zip = zipDestroy(zip);
    return false;
  } else if (dataLength != expectedDataLength) {
    printLog(ERR, "Expected dataLength to be %llu.  Found %llu.\n",
      llu(expectedDataLength), llu(dataLength));
    zip = zipDestroy(zip);
    return false;
  } else if (strncmp((char*) data, expectedData, expectedDataLength) != 0) {
    printLog(ERR, "Expected data to be \"%s\".  Found \"%s\".\n",
      expectedData, (char*) data);
    zip = zipDestroy(zip);
    return false;
  }
  data = pointerDestroy(data);
  
  return true;
}

/// @fn bool zipVerifyZip(Zip *zip, const char *fileName, const volatile void *data, i64 dataLength)
///
/// @brief Verify a known zip archive.
///
/// @param zip A pointer to the Zip object to verify.
/// @param fileName The expected fileName of the Zip.  This parameter
///   may be NULL.
/// @param data The expected data of the Zip.  This parameter may be NULL.
/// @param dataLength The expected dataLength of the Zip.
///
/// @return Returns true on success, false on failure.
bool zipVerifyZip(Zip *zip, const char *fileName,
  const volatile void *data, i64 dataLength
) {
  if (zip == NULL) {
    printLog(ERR, "Opening %s resulted in NULL Zip object.\n",
      (fileName != NULL) ? fileName : "MEMORY");
    return false;
  } else if (zipGetNumEntries(zip) != 3) {
    printLog(ERR, "Expected 3 entries in file.zip, found %llu.\n",
       llu(zipGetNumEntries(zip)));
    zip = zipDestroy(zip);
    return false;
  }
  
  if ((fileName != NULL) && (strcmp(zipGetFileName(zip), fileName) != 0)) {
    printLog(ERR, "Expected filename to be \"file.zip\", found \"%s\".\n",
      zipGetFileName(zip));
    zip = zipDestroy(zip);
    return false;
  } else if ((fileName == NULL) && (*zipGetFileName(zip) != '\0')) {
    printLog(ERR, "Expected filename to be \"\", found \"%s\".\n",
      zipGetFileName(zip));
    zip = zipDestroy(zip);
    return false;
  }
  
  if (zipGetData(zip) != data) {
    printLog(ERR, "Expected data to be %p, found %p.\n", data, zipGetData(zip));
    zip = zipDestroy(zip);
    return false;
  } else if ((data != NULL) && (zipGetLength(zip) != dataLength)) {
    printLog(ERR, "Expected dataLength to be %llu, found %llu.\n",
      llu(dataLength), llu(zipGetLength(zip)));
    zip = zipDestroy(zip);
    return false;
  }
  
  if ((!zipHasEntry(zip, "file1")) || (!zipHasEntry(zip, "file2"))
    || (!zipHasEntry(zip, "file3"))
  ) {
    printLog(ERR, "Expected entry names not found.\n");
    zip = zipDestroy(zip);
    return false;
  }
  
  const char **entryNames = zipGetEntryNames(zip);
  if (entryNames == NULL) {
    printLog(ERR, "zipGetEntryNames returned NULL.\n");
    zip = zipDestroy(zip);
    return false;
  } else if ((strcmp(entryNames[0], "file3") != 0)
    || (strcmp(zipGetEntryName(zip, 0), "file3") != 0)
  ) {
    printLog(ERR, "Expected entryNames[0] to be \"file3\".  Found \"%s\".\n",
      entryNames[0]);
    zip = zipDestroy(zip);
    return false;
  } else if ((strcmp(entryNames[1], "file1") != 0)
    || (strcmp(zipGetEntryName(zip, 1), "file1") != 0)
  ) {
    printLog(ERR, "Expected entryNames[1] to be \"file1\".  Found \"%s\".\n",
      entryNames[0]);
    zip = zipDestroy(zip);
    return false;
  } else if ((strcmp(entryNames[2], "file2") != 0)
    || (strcmp(zipGetEntryName(zip, 2), "file2") != 0)
  ) {
    printLog(ERR, "Expected entryNames[2] to be \"file2\".  Found \"%s\".\n",
      entryNames[0]);
    zip = zipDestroy(zip);
    return false;
  }
  
  const i64 *entrySizes = zipGetEntrySizes(zip);
  if (entrySizes == NULL) {
    printLog(ERR, "zipGetEntrySizes returned NULL.\n");
    zip = zipDestroy(zip);
    return false;
  } else if ((entrySizes[0] != 8) || (zipGetEntrySize(zip, 0) != 8)) {
    printLog(ERR, "Expected entrySizes[0] to be 8.  Found %llu.\n",
      llu(entrySizes[0]));
    zip = zipDestroy(zip);
    return false;
  } else if ((entrySizes[1] != 6) || (zipGetEntrySize(zip, 1) != 6)) {
    printLog(ERR, "Expected entrySizes[1] to be 6.  Found %llu.\n",
      llu(entrySizes[1]));
    zip = zipDestroy(zip);
    return false;
  } else if ((entrySizes[2] != 7) || (zipGetEntrySize(zip, 2) != 7)) {
    printLog(ERR, "Expected entrySizes[2] to be 7.  Found %llu.\n",
      llu(entrySizes[2]));
    zip = zipDestroy(zip);
    return false;
  }
  
  if (zipVerifyEntry(zip, 0, "file3", "file3  \n") == false) {
    // Zip was already destroyed.
    printLog(ERR, "Verification for file1 failed.\n");
    return false;
  } else if (zipVerifyEntry(zip, 1, "file1", "file1\n") == false) {
    // Zip was already destroyed.
    printLog(ERR, "Verification for file2 failed.\n");
    return false;
  } else if (zipVerifyEntry(zip, 2, "file2", "file2 \n") == false) {
    // Zip was already destroyed.
    printLog(ERR, "Verification for file3 failed.\n");
    return false;
  }
  
  return true;
}

bool zipUnitTest(void) {
  remove("newFile.zip");
  
  /* Basic positive tests. */
  Zip *zip = zipCreate();
  if (zip == NULL) {
    printLog(ERR, "NULL Zip object created from base constructor.\n");
    return false;
  } else if (zip->data != NULL) {
    printLog(ERR, "Base constructor produced non-NULL zip->data.\n");
    zip = zipDestroy(zip);
    return false;
  } else if (zip->dataLength != 0) {
    printLog(ERR, "Base constructor produced non-zero zip->dataLenth.\n");
    zip = zipDestroy(zip);
    return false;
  } else if (zip->archive == NULL) {
    printLog(ERR, "Base constructor produced NULL zip->archive.\n");
    zip = zipDestroy(zip);
    return false;
  } else if (zip->fileName != NULL) {
    printLog(ERR, "Base constructor produced non-NULL zip->fileName.\n");
    zip = zipDestroy(zip);
    return false;
  } else if (zip->zipMode != ZIP_MODE_NOT_OPEN) {
    printLog(ERR,
      "Base constructor produced non-ZIP_MODE_NOT_OPEN zip->zipMode.\n");
    zip = zipDestroy(zip);
    return false;
  } else if (zip->zipLocation != ZIP_LOCATION_NONE) {
    printLog(ERR,
      "Base constructor produced non-ZIP_LOCATION_NONE zip->zipLocation.\n");
    zip = zipDestroy(zip);
    return false;
  } else if (zip->numEntries != 0) {
    printLog(ERR, "Base constructor produced non-zero zip->numEntries.\n");
    zip = zipDestroy(zip);
    return false;
  } else if (zip->entryNames != NULL) {
    printLog(ERR, "Base constructor produced non-NULL zip->entryNames.\n");
    zip = zipDestroy(zip);
    return false;
  } else if (zip->entrySizes != NULL) {
    printLog(ERR, "Base constructor produced non-NULL zip->entrySizes.\n");
    zip = zipDestroy(zip);
    return false;
  }
  zip = zipDestroy(zip);
  
  zip = zipOpenFile("file.zip");
  if (zipVerifyZip(zip, "file.zip", NULL, 0) == false) {
    // Zip was already destroyed.
    printLog(ERR, "Verification for file.zip failed.\n");
    return false;
  }
  zip = zipDestroy(zip);
  
  Bytes zipData = getFileContent("file.zip");
  if (bytesLength(zipData) == 0) {
    printLog(ERR, "Could not read file.zip.\n");
    zipData = bytesDestroy(zipData);
    return false;
  }
  void *data = malloc(bytesLength(zipData));
  // Not checking return value here.  This is a test and we're not testing
  // malloc.
  memcpy(data, (void*) zipData, bytesLength(zipData));
  
  zip = zipOpenMemory(data, bytesLength(zipData));
  if (zipVerifyZip(zip, NULL, data, bytesLength(zipData)) == false) {
    // Zip was already destroyed.
    printLog(ERR, "Verification for memory Zip failed.\n");
    zipData = bytesDestroy(zipData);
    return false;
  }
  
  if (zipSetFileName(zip, "file.zip") != 0) {
    printLog(ERR, "Could not set file name for Zip.\n");
    zip = zipDestroy(zip);
    zipData = bytesDestroy(zipData);
    return false;
  }
  if (zipVerifyZip(zip, "file.zip", data, bytesLength(zipData)) == false) {
    // Zip was already destroyed.
    printLog(ERR, "Verification for memory Zip failed.\n");
    zipData = bytesDestroy(zipData);
    return false;
  }
  
  zip = zipDestroy(zip);
  if (zip != NULL) {
    printLog(ERR, "Could not destroy memory Zip.\n");
    zipData = bytesDestroy(zipData);
    return false;
  }
  // data was freed by zipDestroy
  data = NULL;
  
  zip = zipOpenMemory((void*) zipData, bytesLength(zipData));
  if (zip == NULL) {
    printLog(ERR, "Could not open zipData.\n");
    zipData = bytesDestroy(zipData);
    return false;
  }
  
  data = zipDetachData(zip);
  if (data != zipData) {
    printLog(ERR, "Detached data was not zipData.\n");
    zip = zipDestroy(zip);
    zipData = bytesDestroy(zipData);
    return false;
  } else if (zipGetData(zip) != NULL) {
    printLog(ERR, "Data still managed by Zip after detach.\n");
    zip = zipDestroy(zip);
    zipData = bytesDestroy(zipData);
    return false;
  } else if (zipGetLength(zip) != 0) {
    printLog(ERR, "Non-zero data length in Zip after detach.\n");
    zip = zipDestroy(zip);
    zipData = bytesDestroy(zipData);
    return false;
  }
  
  zip = zipDestroy(zip);
  if (zip != NULL) {
    printLog(ERR, "Could not destroy memory Zip.\n");
    zipData = bytesDestroy(zipData);
    return false;
  }
  zipData = bytesDestroy(zipData);
  data = NULL;
  
  Zip *newZip = zipOpenMemory(NULL, 0); // Open for writing.
  if (newZip == NULL) {
    printLog(ERR, "Could not open new memory-based Zip for writing.\n");
    return false;
  }
  
  if (zipAddEntry(newZip, "file3", "file3  \n", 8) != 0) {
    printLog(ERR, "Could not add file3 to newZip.\n");
    newZip = zipDestroy(newZip);
    return false;
  }
  if (zipAddEntry(newZip, "file1", "file1\n", 6) != 0) {
    printLog(ERR, "Could not add file1 to newZip.\n");
    newZip = zipDestroy(newZip);
    return false;
  }
  if (zipAddEntry(newZip, "file2", "file2 \n", 7) != 0) {
    printLog(ERR, "Could not add file2 to newZip.\n");
    newZip = zipDestroy(newZip);
    return false;
  }
  
  if (zipVerifyZip(newZip, NULL, NULL, 0) == false) {
    // Zip was already destroyed.
    printLog(ERR, "Verification for new memory Zip failed.\n");
    return false;
  }
  
  if (zipFlush(newZip, "newFile.zip") != 0) {
    printLog(ERR, "Could not flush newZip to newFile.zip.\n");
    newZip = zipDestroy(newZip);
    return false;
  }
  newZip = zipDestroy(newZip);
  
  newZip = zipOpenMemory(NULL, 0); // Open for writing.
  
  if (zipAddEntry(newZip, "somedir/", NULL, 0) != 0) {
     printLog(ERR, "Could not add \"%s\" to new zip file.\n",
       "somedir/");
    newZip = zipDestroy(newZip);
    return false;
  }
  if (zipAddEntry(newZip, "somedir/file3", "file3  \n", 8) != 0) {
    printLog(ERR, "Could not add file3 to newZip.\n");
    newZip = zipDestroy(newZip);
    return false;
  }
  if (zipHasEntry(newZip, "somedir/") == false) {
    printLog(ERR, "Did not find entry \"somedir/\" in newZip.\n");
    newZip = zipDestroy(newZip);
    return false;
  }
  if (zipAddEntry(newZip, "somedir/file1", "file1\n", 6) != 0) {
    printLog(ERR, "Could not add file1 to newZip.\n");
    newZip = zipDestroy(newZip);
    return false;
  }
  if (zipHasEntry(newZip, "somedir/") == false) {
    printLog(ERR, "Did not find entry \"somedir/\" in newZip.\n");
    newZip = zipDestroy(newZip);
    return false;
  }
  if (zipAddEntry(newZip, "somedir/file2", "file2 \n", 7) != 0) {
    printLog(ERR, "Could not add file2 to newZip.\n");
    newZip = zipDestroy(newZip);
    return false;
  }
  if (zipHasEntry(newZip, "somedir/") == false) {
    printLog(ERR, "Did not find entry \"somedir/\" in newZip.\n");
    newZip = zipDestroy(newZip);
    return false;
  }
  newZip = zipDestroy(newZip);
  
  newZip = zipOpenFile("newFile.zip");
  if (newZip == NULL) {
    remove("newFile.zip");
    printLog(ERR, "Could not open newZip.zip.\n");
    return false;
  }
  
  if (zipVerifyZip(newZip, "newFile.zip", NULL, 0) == false) {
    remove("newFile.zip");
    printLog(ERR, "Could not verify newFile.zip.\n");
    newZip = zipDestroy(newZip);
    return false;
  }
  
  remove("newFile.zip");
  newZip = zipDestroy(newZip);
  
  newZip = zipOpenMemory(NULL, 0); // Open for writing.
  if (newZip == NULL) {
    printLog(ERR, "Could not open new memory-based Zip for writing.\n");
    return false;
  }
  
  if (zipAddEntry(newZip, "/tmp/", NULL, 0) == 0) {
    printLog(ERR, "Added /tmp/ to newZip and should not have.\n");
    newZip = zipDestroy(newZip);
    return false;
  }
  
  if (zipAddEntry(newZip, "/tmp/file1", "file1\n", 6) == 0) {
    printLog(ERR, "Added /tmp/file1 to newZip and should not have.\n");
    newZip = zipDestroy(newZip);
    return false;
  }
  
  if (zipAddEntry(newZip, "tmp/", NULL, 0) != 0) {
    printLog(ERR, "Could not add /tmp/ to newZip.\n");
    newZip = zipDestroy(newZip);
    return false;
  }
  
  if (zipAddEntry(newZip, "tmp/file1:file", "file1\n", 6) == 0) {
    printLog(ERR, "Added tmp/file1:file to newZip and should not have.\n");
    newZip = zipDestroy(newZip);
    return false;
  }
  
  if (zipAddEntry(newZip, "tmp/file1\\file", "file1\n", 6) == 0) {
    printLog(ERR, "Added tmp/file1\\file to newZip and should not have.\n");
    newZip = zipDestroy(newZip);
    return false;
  }
  
  if (zipAddEntry(newZip, "tmp/file1", "file1\n", 6) != 0) {
    printLog(ERR, "Could not add file1 to newZip.\n");
    newZip = zipDestroy(newZip);
    return false;
  }
  
  newZip = zipDestroy(newZip);
  
  const char *badData
    = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  zip = zipOpenMemory(badData, strlen(badData), NULL, true);
  if (zip != NULL) {
    printLog(ERR, "zipOpenMemory returned non-NULL when opening bad data.\n");
    zip = zipDestroy(zip);
    return false;
  }
  
  return true;
}


