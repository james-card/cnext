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

#include "ZipLib.h"
#ifdef LOGGING_ENABLED
#include "LoggingLib.h"
#else
#undef printLog
#define printLog(...) {}
#define printBinary(...) {}
#define LOG_MALLOC_FAILURE(...) {}
#define logFile stderr
#endif


/// @fn CompressedData* compressData(const volatile void *data, i64 dataLength)
///
/// @brief Compress arbitrary in-memory data to a CompressedData object.  The
/// output data is guaranteed to be no larger than the input data.
///
/// @param data A pointer to the data to compress.
/// @param dataLength The length, in bytes, of the data parameter.
///
/// @return Returns a pointer to an allocated CompressedData object on success,
/// NULL on failure.
CompressedData* compressData(const volatile void *data, i64 dataLength) {
  printLog(TRACE,
    "ENTER compressData(data=%p, dataLength=%llu)\n",
    data, llu(dataLength));
  
  if ((data == NULL) || (dataLength == 0)) {
    // Not an error, but nothing to do.
    printLog(TRACE,
      "EXIT compressData(data=%p, dataLength=%llu) = {NULL}\n",
      data, llu(dataLength));
    return NULL;
  }
  
  CompressedData *compressedData
    = (CompressedData*) calloc(1, sizeof(CompressedData));
  if (compressedData == NULL) {
    // Nothing more we can do.
    LOG_MALLOC_FAILURE();
    printLog(TRACE,
      "EXIT compressData(data=%p, dataLength=%llu) = {NULL}\n",
      data, llu(dataLength));
    return NULL;
  }
  
  size_t sourceLength = (size_t) dataLength;
  size_t destinationLength = 0;
  compressedData->data = tdefl_compress_mem_to_heap((void*) data, sourceLength,
    &destinationLength, TDEFL_MAX_PROBES_MASK);
  
  if ((compressedData->data == NULL) || (destinationLength > sourceLength)) {
    // Most likely, the data was not compressible and we've wound up with output
    // larger than the input.  This is not acceptable.  Do a raw copy of the
    // input to the output and set the flag so we know not to decompress this.
    printLog(DEBUG, "Invalid return from tdefl_compress_mem_to_heap.\n");
    compressedData->data = pointerDestroy(compressedData->data);
    
    compressedData->data = malloc(dataLength);
    if (compressedData == NULL) {
      LOG_MALLOC_FAILURE();
      printLog(TRACE,
        "EXIT compressData(data=%p, dataLength=%llu) = {NULL}\n",
        data, llu(dataLength));
      return NULL;
    }
    
    memcpy(compressedData->data, (void*) data, sourceLength);
    compressedData->dataLength = dataLength;
    compressedData->dataIsRaw = true;
    
    printLog(TRACE,
      "EXIT compressData(data=%p, dataLength=%llu) = {%p}\n",
      data, llu(dataLength), compressedData);
    return compressedData;
  }
  compressedData->dataLength = (i64) destinationLength;
  
  printLog(TRACE,
    "EXIT compressData(data=%p, dataLength=%llu) = {%p}\n",
    data, llu(dataLength), compressedData);
  return compressedData;
}

/// @fn void* decompressData_(const CompressedData *compressedData, i64 *dataLength, ...)
///
/// @brief Decompress a previously-compressed piece of data.
///
/// @note This function is wrapped by a macro of the same name (without the
/// trailing underscore) that automatically provides NULL as the dataLength
/// parameter if none is provided.
///
/// @param compressedData A pointer to a previously-constructed CompressedData
///   object representing compressed data.
/// @param dataLength A pointer to a i64 that will hold the length, in bytes,
///   of the returned value.
///
/// @return Returns a pointer to the decompressed data on success,
/// NULL on failure.
void* decompressData_(const CompressedData *compressedData,
  i64 *dataLength, ...
) {
  printLog(TRACE,
    "ENTER decompressData(compresseddData=%p, dataLength=%p)\n",
    compressedData, dataLength);
  
  if (compressedData == NULL) {
    // Not an error, but nothing to do.
    printLog(TRACE,
      "EXIT decompressData(compressedData=%p, dataLength=%p) = {NULL}\n",
      compressedData, dataLength);
    return NULL;
  }
  // It's not an error for dataLength to be NULL.
  
  size_t sourceLength = (size_t) compressedDataGetLength(compressedData);
  size_t destinationLength = 0;
  
  void *data = NULL;
  if (compressedData->dataIsRaw == false) {
    //  The expected case.
    data = tinfl_decompress_mem_to_heap(
      compressedDataGetData(compressedData), sourceLength,
      &destinationLength, 0);
    if (data == NULL) {
      printLog(ERR, "tinfl_decompress_mem_to_heap returned NULL.\n");
      printLog(TRACE,
        "EXIT decompressData(compressedData=%p, dataLength=%p) = {NULL}\n",
        compressedData, dataLength);
      return NULL;
    }
  } else {
    // Compression failed and the data is the raw bytes at input.  Do a
    // straight copy.
    data = malloc(compressedDataGetLength(compressedData));
    if (data == NULL) {
      LOG_MALLOC_FAILURE();
      printLog(TRACE,
        "EXIT decompressData(compressedData=%p, dataLength=%p) = {NULL}\n",
        compressedData, dataLength);
      return NULL;
    }
    
    destinationLength = (size_t) compressedDataGetLength(compressedData);
    memcpy(data, compressedDataGetData(compressedData), destinationLength);
  }
  
  if (dataLength != NULL) {
    *dataLength = (i64) destinationLength;
  }
  
  printLog(TRACE,
    "EXIT decompressData(compressedData=%p, dataLength=%llu) = {%p}\n",
    compressedData, (dataLength != NULL) ? llu(*dataLength) : 0, data);
  return data;
}

/// @fn Bytes decompressDataToBytes(const CompressedData *compressedData)
///
/// @brief Decompress a CompressedData object directly to a Bytes object.
///
/// @param compressedData A pointer to a CompressedData object with compressed
///   data in it.
///
/// @return Returns a newly-allocated Bytes object with the decompressed data
/// on success, NULL on failure.
Bytes decompressDataToBytes(const CompressedData *compressedData) {
  printLog(TRACE,
    "ENTER decompressDataToBytes(compresseddData=%p)\n",
    compressedData);
  
  if (compressedData == NULL) {
    // Not an error, but nothing to do.
    printLog(TRACE,
      "EXIT decompressDataToBytes(compressedData=%p) = {NULL}\n",
      compressedData);
    return NULL;
  }
  
  size_t sourceLength = (size_t) compressedDataGetLength(compressedData);
  void *data = NULL;
  size_t destinationLength = 0;
  Bytes returnValue = NULL;
  
  if (compressedData->dataIsRaw == false) {
    //  The expected case.
    data = tinfl_decompress_mem_to_heap(
      compressedDataGetData(compressedData), sourceLength,
      &destinationLength, 0);
    if (data == NULL) {
      printLog(ERR, "tinfl_decompress_mem_to_heap returned NULL.\n");
      printLog(TRACE,
        "EXIT decompressDataToBytes(compressedData=%p) = {NULL}\n",
        compressedData);
      return NULL;
    }
    
    bytesAddData(&returnValue, data, destinationLength);
    data = pointerDestroy(data);
  } else {
    // Compression failed and the data is the raw bytes at input.  Do a
    // straight copy.
    data = compressedDataGetData(compressedData);
    destinationLength = (size_t) compressedDataGetLength(compressedData);
    bytesAddData(&returnValue, data, destinationLength);
  }
  
  printLog(TRACE,
    "EXIT decompressDataToBytes(compressedData=%p) = {%p}\n",
    compressedData, returnValue);
  return returnValue;
}

/// @fn i64 compressedDataGetLength(const CompressedData *compressedData)
///
/// @brief Get the length, in bytes, of data of a CompressedData object.
///
/// @param compressedData A pointer to a CompressedData object to get the
///   length of.  This parameter may be NULL.
///
/// @return Returns the number of compressed data bytes of the supplied
/// CompressedData object.
i64 compressedDataGetLength(const CompressedData *compressedData) {
  printLog(TRACE, "ENTER compressedDataGetLength(compressedData=%p)\n",
    compressedData);
  
  i64 dataLength = 0;
  if (compressedData != NULL) {
    dataLength = compressedData->dataLength;
  }
  
  printLog(TRACE, "EXIT compressedDataGetLength(compressedData=%p) = {%llu}\n",
    compressedData, llu(dataLength));
  return dataLength;
}

/// @fn void* compressedDataGetData(const CompressedData *compressedData)
///
/// @brief Get the data member of a CompressedData object.
///
/// @param compressedData A pointer to a CompressedData object to get the
///   data from.  This parameter may be NULL.
///
/// @return Returns the data member pointer of the provided CompressedData
/// object.
void* compressedDataGetData(const CompressedData *compressedData) {
  printLog(TRACE, "ENTER compressedDataGetData(compressedData=%p)\n",
    compressedData);
  
  void *data = NULL;
  if (compressedData != NULL) {
    data = compressedData->data;
  }
  
  printLog(TRACE, "EXIT compressedDataGetData(compressedData=%p) = {%p}\n",
    compressedData, data);
  return data;
}

/// @fn bool compressedDataIsRaw(const CompressedData *compressedData)
///
/// @brief Get whether or not CompressedData is raw.
///
/// @param compressedData A pointer to a CompressedData object.
///
/// @return Returns true if the CompressedData is raw, false if not.
bool compressedDataIsRaw(const CompressedData *compressedData) {
  printLog(TRACE, "ENTER compressedDataIsRaw(compressedData=%p)\n",
    compressedData);
  
  bool dataIsRaw = true;
  
  if (compressedData != NULL) {
    dataIsRaw = compressedData->dataIsRaw;
  }
  
  printLog(TRACE, "EXIT compressedDataIsRaw(compressedData=%p) = {%s}\n",
    compressedData, boolNames[dataIsRaw]);
  return dataIsRaw;
}

/// @fn CompressedData* compressedDataCreate(const volatile void *data, i64 dataLength, bool dataIsRaw, bool dataIsStatic)
///
/// @brief Initialize a CompressedData object from parameters.
///
/// @param data A pointer to memory containing compressed data.
/// @param dataLength The number of bytes at the data pointer.
/// @param dataIsRaw Whether or not the data is raw and uncompressed.
/// @param dataIsStatic Whether or not the data is static (cannot be freed).
///
/// @return Returns a pointer to a newly-allocated and initialized
/// CompressedData object on success, NULL on failure.
CompressedData* compressedDataCreate(const volatile void *data, i64 dataLength,
  bool dataIsRaw, bool dataIsStatic
) {
  printLog(TRACE,
    "ENTER compressedDataCreate(data=%p, dataLength=%lld, "
    "dataIsRaw=%s, dataIsStatic=%s)\n",
    data, lld(dataLength), boolNames[dataIsRaw], boolNames[dataIsStatic]);
  
  CompressedData *returnValue = NULL;
  
  if ((data == NULL) || (dataLength <= 0)) {
    printLog(DEBUG, "Invalid parameter.\n");
    printLog(TRACE,
      "EXIT compressedDataCreate(data=%p, dataLength=%lld, "
      "dataIsRaw=%s, dataIsStatic=%s) = {NULL}\n",
      data, lld(dataLength), boolNames[dataIsRaw], boolNames[dataIsStatic]);
    return returnValue; // NULL
  }
  
  returnValue = (CompressedData*) calloc(1, sizeof(CompressedData));
  if (returnValue == NULL) {
    LOG_MALLOC_FAILURE();
    printLog(TRACE,
      "EXIT compressedDataCreate(data=%p, dataLength=%lld, "
      "dataIsRaw=%s, dataIsStatic=%s) = {NULL}\n",
      data, lld(dataLength), boolNames[dataIsRaw], boolNames[dataIsStatic]);
    return returnValue; // NULL
  }
  
  returnValue->data = (void*) data;
  returnValue->dataLength = dataLength;
  returnValue->dataIsRaw = dataIsRaw;
  returnValue->dataIsStatic = dataIsStatic;
  
  printLog(TRACE,
    "EXIT compressedDataCreate(data=%p, dataLength=%lld, "
    "dataIsRaw=%s, dataIsStatic=%s) = {%p}\n",
    data, lld(dataLength), boolNames[dataIsRaw], boolNames[dataIsStatic],
    returnValue);
  return returnValue;
}

/// @fn CompressedData* compressedDataDestroy(CompressedData *compressedData)
///
/// @brief Deallocate a previously-constructed CompressedData object.
///
/// @param compressedData A pointer to a CompressedData object.
///
/// @return This function always succeeds and always returns NULL.
CompressedData* compressedDataDestroy(CompressedData *compressedData) {
  printLog(TRACE,
    "ENTER compressedDataDestroy(compressedData=%p)\n", compressedData);
  
  if (compressedData == NULL) {
    // Not an error, but nothing to do.
    printLog(TRACE,
      "EXIT compressedDataDestroy(compressedData=NULL) = {NULL}\n");
    return NULL;
  }
  
  if (compressedData->dataIsStatic == false) {
    compressedData->data = pointerDestroy(compressedData->data);
  }
  compressedData = (CompressedData*) pointerDestroy(compressedData);
  
  printLog(TRACE,
    "EXIT compressedDataDestroy(compressedData=%p) = {NULL}\n",
    compressedData);
  return NULL;
}

/// @def COMPRESSED_DATA_HEADER_LENGTH
///
/// @brief Length of header for CompressedData byte array.  We need 4 bytes
/// for the dataLength.  The dataIsRaw bool will be encoded as the low-order
/// bit of the header.
#define COMPRESSED_DATA_HEADER_LENGTH 4

/// @fn Bytes compressedDataToBlob(const CompressedData *compressedData)
///
/// @brief Convert a CompressedData object to a single array of bytes.
///
/// @param compressedData A pointer to the CompressedData object.
///
/// @return Returns a Bytes object with the compressed data on success,
/// NULL on failure.
Bytes compressedDataToBlob(const CompressedData *compressedData) {
  printLog(TRACE,
    "ENTER compressedDataToBlob(compressedData=%p)\n", compressedData);
  
  if (compressedData == NULL) {
    printLog(ERR, "One or more NULL parameters.\n");
    printLog(TRACE,
      "EXIT compressedDataToBlob(compressedData=%p) = {NULL}\n",
      compressedData);
    return NULL;
  }
  
  // Header plus length of the data itself.
  u32 compressedDataLength = (u32) compressedDataGetLength(compressedData);
  if (compressedDataLength > 0xfffffffe) {
    printLog(ERR,
      "Compressed data length 0x%x exceeds maximum length 0xfffffffe.\n",
      compressedDataLength);
    printLog(TRACE,
      "EXIT compressedDataToBlob(compressedData=%p) = {NULL}\n",
      compressedData);
    return NULL;
  }
  bool initializeLastByte = false;
  if (compressedDataLength & 1) {
    // Pad with an extra byte.
    compressedDataLength++;
    initializeLastByte = true;
  }
  u64 byteArraySize = COMPRESSED_DATA_HEADER_LENGTH + compressedDataLength;
  Bytes byteArray = NULL;
  bytesAllocate(&byteArray, byteArraySize);
  if (byteArray == NULL) {
    LOG_MALLOC_FAILURE();
    printLog(TRACE,
      "EXIT compressedDataToBlob(compressedData=%p) "
      "= {NULL}\n", compressedData);
    return NULL;
  }
  if (initializeLastByte == true) {
    byteArray[byteArraySize] =  '\0';
  }
  
  u32 header = ((u32) compressedDataLength) & 0xfffffffe;
  header |= (u32) compressedData->dataIsRaw;
  hostToLittleEndian(&header, sizeof(u32));
  bytesAddData(&byteArray, &header, sizeof(header));
  bytesAddData(&byteArray,
    compressedDataGetData(compressedData),
    compressedDataGetLength(compressedData));
  
  printLog(TRACE,
    "EXIT compressedDataToBlob(compressedData=%p) = {%p}\n",
    compressedData, byteArray);
  return byteArray;
}

/// @fn CompressedData* compressedDataFromBlob(const volatile void *array, i64 *length)
///
/// @brief Convert a properly-formatted byte array into a CompressedData object.
///
/// @param array The array of bytes to convert.
/// @param length As an input, this is the number of bytes in array.  As an
///   output, this is the number of bytes consumed by this call.
///
/// @return Returns a pointer to a CompressedData object on success,
/// NULL on failure.
CompressedData* compressedDataFromBlob(const volatile void *array, i64 *length) {
  printLog(TRACE,
    "ENTER compressedDataFromBlob(array=%p, length=%p)\n",
    array, length);
  
  if ((array == NULL) || (length == NULL)) {
    printLog(ERR, "One or more NULL parameters.\n");
    printLog(TRACE,
      "EXIT compressedDataFromBlob(array=%p, length=%p) = {NULL}\n",
      array, length);
    return NULL;
  }
  
  CompressedData *compressedData
    = (CompressedData*) calloc(1, sizeof(CompressedData));
  if (compressedData == NULL) {
    LOG_MALLOC_FAILURE();
    *length = 0;
    printLog(TRACE,
      "EXIT compressedDataFromBlob(array=%p, length=%llu) = {NULL}\n",
      array, llu(*length));
    return NULL;
  }
  
  u8 *u8Array = (u8*) array;
  u32 *header = (u32*) array;
  compressedData->dataLength = *header;
  littleEndianToHost(&compressedData->dataLength, sizeof(u32));
  compressedData->dataIsRaw = (bool) (compressedData->dataLength & 1);
  compressedData->dataLength &= 0xfffffffe;
  
  if ((compressedDataGetLength(compressedData) + COMPRESSED_DATA_HEADER_LENGTH)
    > *length
  ) {
    // Input is invalid.  We're going to create a segmentation fault if we
    // continue.  Bail.
    printLog(ERR, "Length of compressedData exceeds input length.\n");
    compressedData = compressedDataDestroy(compressedData);
    *length = 0;
    printLog(TRACE,
      "EXIT compressedDataFromBlob(array=%p, length=%llu) = {NULL}\n",
      array, llu(*length));
    return NULL;
  }
  
  compressedData->data = malloc(compressedDataGetLength(compressedData));
  if (compressedData->data == NULL) {
    LOG_MALLOC_FAILURE();
    compressedData = compressedDataDestroy(compressedData);
    *length = 0;
    printLog(TRACE,
      "EXIT compressedDataFromBlob(array=%p, length=%llu) = {NULL}\n",
      array, llu(*length));
    return NULL;
  }
  
  memcpy(compressedData->data, &u8Array[COMPRESSED_DATA_HEADER_LENGTH],
    compressedDataGetLength(compressedData));
  *length = compressedDataGetLength(compressedData) + COMPRESSED_DATA_HEADER_LENGTH;
  
  printLog(TRACE,
    "EXIT compressedDataFromBlob(array=%p, length=%llu) = {%p}\n",
    array, llu(*length), compressedData);
  return compressedData;
}


// Formal zip support functions.

/// @fn bool _zipEnsureReadable(Zip *zip)
///
/// @brief Ensure that a Zip archive is readable or return bad status.
///
/// @note This is a support function for this library.  It is not intended to
/// be exposed to the outside world.
///
/// @param zip A pointer to the Zip archive to ensure readability for.
///
/// @return Returns true on success, false on failure.
bool _zipEnsureReadable(Zip *zip) {
  printLog(TRACE, "ENTER _zipEnsureReadable(zip=%p)\n", zip);
  
  if ((zip == NULL) || (zip->archive == NULL)) {
    // Nothing we can do.
    printLog(TRACE, "EXIT _zipEnsureReadable(zip=%p) = {NOT successful}\n", zip);
    return false;
  }
  
  if (zip->zipMode == ZIP_MODE_READ) {
    printLog(TRACE, "EXIT _zipEnsureReadable(zip=%p) = {successful}\n", zip);
    return true;
  }
  
  if (zip->zipMode == ZIP_MODE_WRITE) {
    if (zipClose(zip) != 0) {
      printLog(ERR, "Could not close writable Zip.\n");
      printLog(TRACE,
        "EXIT _zipEnsureReadable(zip=%p) = {NOT successful}\n",
        zip);
      return false;
    }
  }
  
  // Zip is ready for reading.
  if ((zip->zipLocation == ZIP_LOCATION_FILE) && (zip->fileName != NULL)) {
    // Zip is a file-based archive.
    if (!mz_zip_reader_init_file(zip->archive, zip->fileName,
      MZ_ZIP_FLAG_CASE_SENSITIVE)
    ) {
      printLog(ERR, "Cannot open Zip file \"%s\" for reading.\n",
        zip->fileName);
      printLog(TRACE,
        "EXIT _zipEnsureReadable(zip=%p) = {NOT successful}\n",
        zip);
      return false;
    }
  } else if ((zip->zipLocation == ZIP_LOCATION_MEMORY) && (zip->data != NULL)) {
    // Zip is a "heap archive".
    if (!mz_zip_reader_init_mem(zip->archive, zipGetData(zip),
      (size_t) zipGetLength(zip), MZ_ZIP_FLAG_CASE_SENSITIVE)
    ) {
      printLog(ERR, "Cannot open Zip memory %p for reading.\n", zipGetData(zip));
      printLog(TRACE,
        "EXIT _zipEnsureReadable(zip=%p) = {NOT successful}\n",
        zip);
      return false;
    }
  } else {
    printLog(ERR, "Insufficient information to open Zip for reading.\n");
    printLog(TRACE,
      "EXIT _zipEnsureReadable(zip=%p) = {NOT successful}\n",
      zip);
    return false;
  }
  zip->zipMode = ZIP_MODE_READ;
  
  if (zip->entryNames != NULL) {
    // Clear out any metadata that's there.
    for (i64 index = 0; index < zip->numEntries; index++) {
      zip->entryNames[index] = stringDestroy(zip->entryNames[index]);
    }
    zip->entryNames = (char**) pointerDestroy(zip->entryNames);
    zip->entrySizes = (i64*) pointerDestroy(zip->entrySizes);
  }
  
  // Rebuild the entryNames and entrySizes arrays.
  zip->numEntries = (i64) mz_zip_reader_get_num_files(zip->archive);
  zip->entryNames = (char**) calloc(1, zip->numEntries * sizeof(char*));
  zip->entrySizes = (i64*) calloc(1, zip->numEntries * sizeof(i64));
  if ((zip->entryNames == NULL) || (zip->entrySizes == NULL)) {
    zip->entryNames = (char**) pointerDestroy(zip->entryNames);
    zip->entrySizes = (i64*) pointerDestroy(zip->entrySizes);
    LOG_MALLOC_FAILURE();
    printLog(TRACE,
      "EXIT _zipEnsureReadable(zip=%p) = {NOT successful}\n",
      zip);
    return false;
  }
  
  for (i64 index = 0; index < zip->numEntries; index++) {
    ZEROINIT(mz_zip_archive_file_stat stat);
    if (!mz_zip_reader_file_stat(zip->archive, index, &stat)) {
      printLog(ERR, "Could not retrieve entry metadata for Zip archive.\n");
      printLog(TRACE,
        "EXIT _zipEnsureReadable(zip=%p) = {NOT successful}\n",
        zip);
      return false;
    }
    
    straddstr(&zip->entryNames[index], stat.m_filename);
    zip->entrySizes[index] = stat.m_uncomp_size;
  }
  
  printLog(TRACE, "EXIT _zipEnsureReadable(zip=%p) = {successful}\n", zip);
  return true;
}

/// @fn bool _zipEnsureWritable(Zip *zip)
///
/// @brief Ensure that a Zip archive is writable or return bad status.
///
/// @note This is a support function for this library.  It is not intended to
/// be exposed to the outside world.
///
/// @param zip A pointer to the Zip archive to ensure writability for.
///
/// @return Returns true on success, false on failure.
bool _zipEnsureWritable(Zip *zip) {
  printLog(TRACE, "ENTER _zipEnsureWritable(zip=%p)\n", zip);
  
  if ((zip == NULL) || (zip->archive == NULL)) {
    // Nothing we can do.
    printLog(TRACE, "EXIT _zipEnsureWritable(zip=%p) = {NOT successful}\n", zip);
    return false;
  }
  
  if (zip->zipMode == ZIP_MODE_WRITE) {
    printLog(TRACE, "EXIT _zipEnsureWritable(zip=%p) = {successful}\n", zip);
    return true;
  }
  
  if (zip->zipMode == ZIP_MODE_READ) {
    if (!mz_zip_writer_init_from_reader(zip->archive, zip->fileName)) {
      printLog(ERR, "Could not convert readable Zip archive to writeable.\n");
      printLog(TRACE,
        "EXIT _zipEnsureWritable(zip=%p) = {NOT successful}\n",
        zip);
      return false;
    }
  } else {
    // We're creating a new archive.
    if ((zip->zipLocation == ZIP_LOCATION_FILE) && (zip->fileName != NULL)) {
      // Zip is a file-based archive.
      if (!mz_zip_writer_init_file(zip->archive, zip->fileName, 0)) {
        printLog(ERR, "Could not open Zip archive \"%s\" for writing.\n",
          zip->fileName);
        printLog(TRACE,
          "EXIT _zipEnsureWritable(zip=%p) = {NOT successful}\n",
          zip);
        return false;
      }
    } else if (zip->zipLocation == ZIP_LOCATION_MEMORY) {
      // Zip is a "heap archive".
      if (!mz_zip_writer_init_heap(zip->archive, 0, 0)) {
        printLog(ERR, "Could not open Zip heap archive for writing.\n");
        printLog(TRACE,
          "EXIT _zipEnsureWritable(zip=%p) = {NOT successful}\n",
          zip);
        return false;
      }
    } else {
      printLog(ERR, "Insufficient information to open Zip for writing.\n");
      printLog(TRACE,
        "EXIT _zipEnsureWritable(zip=%p) = {NOT successful}\n",
        zip);
      return false;
    }
  }
  
  zip->zipMode = ZIP_MODE_WRITE;
  // Invalidate the metadata.
  if (zip->entryNames != NULL) {
    for (i64 index = 0; index < zip->numEntries; index++) {
      zip->entryNames[index] = stringDestroy(zip->entryNames[index]);
    }
    zip->entryNames = (char**) pointerDestroy(zip->entryNames);
    zip->entrySizes = (i64*) pointerDestroy(zip->entrySizes);
  }
  
  printLog(TRACE, "EXIT _zipEnsureWritable(zip=%p) = {successful}\n", zip);
  return true;
}

/// @fn Zip* zipCreate()
///
/// @brief Base constructor for a Zip object.
///
/// @return Returns a pointer to an initalized Zip read object on success,
/// NULL on failure.
Zip* zipCreate() {
  printLog(TRACE, "ENTER zipCreate()\n");
  
  Zip *zip = (Zip*) calloc(1, sizeof(Zip));
  if (zip == NULL) {
    LOG_MALLOC_FAILURE();
    printLog(TRACE, "EXIT zipCreate() = {NULL}\n");
    return NULL;
  }
  
  // zip->dataLength is set to 0 by calloc
  // zip->data is set to NULL by calloc
  
  zip->archive = (mz_zip_archive*) calloc(1, sizeof(mz_zip_archive));
  if (zip->archive == NULL) {
    LOG_MALLOC_FAILURE();
    zip = zipDestroy(zip);
    printLog(TRACE, "EXIT zipCreate() = {NULL}\n");
    return NULL;
  }
  
  // zip->fileName is set to NULL by calloc
  // zip->zipMode is set to ZIP_MODE_NOT_OPEN by calloc
  // zip->zipLocation is set to ZIP_LOCATION_NONE by calloc
  // zip->numEntries is set to 0 by calloc
  // zip->entryNames is set to NULL by calloc
  // zip->entrySizes is set to NULL by calloc
  
  if (mtx_init(&zip->lock, mtx_plain | mtx_recursive) != thrd_success) {
    printLog(ERR, "Could not initialize Zip mutex.\n");
    zip = zipDestroy(zip);
    printLog(TRACE, "EXIT zipCreate() = {NULL}\n");
    return NULL;
  }
  
  printLog(TRACE, "EXIT zipCreate() = {%p}\n", zip);
  return zip;
}

/// @fn Zip* zipOpenFile(const char *fileName)
///
/// @brief Open a zip archive on the filesystem.  If the archive does not exist,
/// it will be created and the Zip object will be opened in write mode.
///
/// @param fileName The full path and file name for the archive.
///
/// @return Returns a pointer to an initalized Zip object on success,
/// NULL on failure.
Zip* zipOpenFile(const char *fileName) {
  printLog(TRACE, "ENTER zipOpenFile(fileName=\"%s\")\n", fileName);
  
  if (fileName == NULL) {
    printLog(ERR, "NULL fileName provided.\n");
    printLog(TRACE, "EXIT zipOpenFile(fileName=NULL) = {NULL}\n");
    return NULL;
  }
  
  Zip *zip = zipCreate();
  if (zip == NULL) {
    // Error was already logged.  Just return NULL.
    printLog(TRACE, "EXIT zipOpenFile(fileName=\"%s\") = {NULL}\n", fileName);
    return NULL;
  }
  
  ZipMode zipMode = ZIP_MODE_READ;
  FILE *zipFile = fopen(fileName, "r");
  if (zipFile == NULL) {
    // File doens't exist or access is denied.  Try creating it.
    zipFile = fopen(fileName, "w");
    if (zipFile == NULL) {
      // Access is denied.  We're toast.
      printLog(ERR, "Access is denied for file \"%s\".", fileName);
      zip = zipDestroy(zip);
      printLog(TRACE, "EXIT zipOpenFile(fileName=\"%s\") = {NULL}\n", fileName);
      return NULL;
    }
    zipMode = ZIP_MODE_WRITE;
  }
  fclose(zipFile); zipFile = NULL;
  
  // We succeeded at opening the file, so log the fileName in the Zip object.
  zip->zipLocation = ZIP_LOCATION_FILE;
  straddstr(&zip->fileName, fileName);
  
  // Open the archive.
  if (zipMode == ZIP_MODE_READ) {
    // Open for reading.
    if (!_zipEnsureReadable(zip)) {
      printLog(ERR, "Could not open zip file \"%s\" for reading.\n", fileName);
      zip = zipDestroy(zip);
      printLog(TRACE, "EXIT zipOpenFile(fileName=\"%s\") = {NULL}\n", fileName);
      return NULL;
    }
  } else if (zipMode == ZIP_MODE_WRITE) {
    // Open for writing.
    if (!_zipEnsureWritable(zip)) {
      printLog(ERR, "Could not open zip file \"%s\" for writing.\n", fileName);
      zip = zipDestroy(zip);
      printLog(TRACE, "EXIT zipOpenFile(fileName=\"%s\") = {NULL}\n", fileName);
      return NULL;
    }
  }
  
  // zip->dataLength is set to 0 by the base constructor
  // zip->data is set to NULL by the base constructor
  // zip->lock is initialized by the base constructor
  
  printLog(TRACE,
    "EXIT zipOpenFile(fileName=\"%s\") = {%p}\n",
    fileName, zip);
  return zip;
}

/// @fn Zip* zipOpenMemory_(const volatile void *memoryPointer, i64 memoryLength, const char *fileName, bool leaseData, ...)
///
/// @brief Open an in-memory zip archive.
///
/// @note This function is wrapped by a macro of the same name (without the
/// trailing underscore) that automatically provides NULL as the fileName
/// parameter and false as the leaseData parameter if none are supplied.
///
/// @param memoryPointer A pointer to the memory associated with the archive.
/// @param memoryLength The number of bytes at the memoryPointer.
/// @param fileName Optional file name for the archive.
/// @param leaseData Whether or not to lease the data or take ownership.
///
/// @note The Zip object will take ownership of the pointer provided and it
/// will be freed when the object is destroyed unless zipDetachData is called
/// on the Zip before the destructor is called or the leaseData parameter is
/// set to true.  This means that if a bytes pointer is used as the
/// memoryPointer parameter, zipDetachData *MUST* be called before the Zip
/// destructor is called or leaseData must be set to set to true when this
/// function is called since Bytes are actually objects that must be destroyed
/// with their own destructor.
///
/// If the Zip is modified in any way, the provided pointer passed as this
/// parameter must be considered invalid and must not be used.  This means
/// that the provided pointer *CANNOT BE A Bytes POINTER* if the Zip is to be
/// modified since Bytes objects cannot be modified by this library.
///
/// @return Returns a pointer to a newly-constructed Zip object on success,
/// NULL on failure.
Zip* zipOpenMemory_(const volatile void *memoryPointer, i64 memoryLength,
  const char *fileName, bool leaseData, ...
) {
  printLog(TRACE,
    "ENTER zipOpenMemory(memoryPointer=%p, memoryLength=%llu, "
    "fileName=\"%s\", leaseData=%s)\n", memoryPointer, llu(memoryLength),
    fileName, boolNames[leaseData]);
  
  Zip *zip = zipCreate();
  if (zip == NULL) {
    // Error was already logged.  Just return NULL.
    printLog(TRACE,
      "EXIT zipOpenMemory(memoryPointer=%p, memoryLength=%llu, "
      "fileName=\"%s\", leaseData=%s) = {NULL}\n", memoryPointer,
      llu(memoryLength), fileName, boolNames[leaseData]);
    return NULL;
  }
  
  ZipMode zipMode = ZIP_MODE_READ;
  if ((memoryPointer != NULL) && (memoryLength != 0)) {
    // We're reading the input data.
    zip->data = (void*) memoryPointer;
    zip->dataLength = memoryLength;
    zip->leaseData = leaseData;
  } else {
    // No memory supplied, so the intention must be to write.
    zipMode = ZIP_MODE_WRITE;
  }
  
  zip->zipLocation = ZIP_LOCATION_MEMORY;
  if (fileName != NULL) {
    straddstr(&zip->fileName, fileName);
  }
  
  // Open the archive.
  if (zipMode == ZIP_MODE_READ) {
    // Open for reading.
    if (!_zipEnsureReadable(zip)) {
      printLog(ERR, "Could not open zip file \"%s\" for reading.\n", fileName);
      zip = zipDestroy(zip);
      printLog(TRACE,
        "EXIT zipOpenMemory(memoryPointer=%p, memoryLength=%llu, "
        "fileName=\"%s\", leaseData=%s) = {NULL}\n", memoryPointer,
        llu(memoryLength), fileName, boolNames[leaseData]);
      return NULL;
    }
  } else if (zipMode == ZIP_MODE_WRITE) {
    // Open for writing.
    if (!_zipEnsureWritable(zip)) {
      printLog(ERR, "Could not open zip file \"%s\" for writing.\n", fileName);
      zip = zipDestroy(zip);
      printLog(TRACE,
        "EXIT zipOpenMemory(memoryPointer=%p, memoryLength=%llu, "
        "fileName=\"%s\", leaseData=%s) = {NULL}\n", memoryPointer,
        llu(memoryLength), fileName, boolNames[leaseData]);
      return NULL;
    }
  }
  
  printLog(TRACE,
    "EXIT zipOpenMemory(memoryPointer=%p, memoryLength=%llu, "
    "fileName=\"%s\", leaseData=%s) = {%p}\n", memoryPointer,
    llu(memoryLength), fileName, boolNames[leaseData], zip);
  return zip;
}

/// @fn i32 zipLock(Zip *zip)
///
/// @brief Lock a Zip object for access by this library.
///
/// @param zip A pointer to the Zip object to lock.
///
/// @return Returns 0 on success, -1 on failure.
i32 zipLock(Zip *zip) {
  printLog(TRACE, "ENTER zipLock(zip=%p)\n", zip);
  
  if (zip == NULL) {
    printLog(ERR, "Invalid parameter.\n");
    printLog(TRACE, "EXIT zipLock(zip=%p) = {-1}\n", zip);
    return -1;
  }
  
  i32 status = 0;
  if (mtx_lock(&zip->lock) != thrd_success) {
    printLog(ERR, "Could not lock Zip.\n");
    status = -1;
  }
  
  printLog(TRACE, "EXIT zipLock(zip=%p) = {%d}\n", zip, status);
  return status;
}

/// @fn i32 zipUnlock(Zip *zip)
///
/// @brief Unlock a previously-locked Zip object.
///
/// @param zip A pointer to the Zip object to unlock.
///
/// @return Returns 0 on success, -1 on failure.
i32 zipUnlock(Zip *zip) {
  printLog(TRACE, "ENTER zipUnlock(zip=%p)\n", zip);
  
  if (zip == NULL) {
    printLog(ERR, "Invalid parameter.\n");
    printLog(TRACE, "EXIT zipUnlock(zip=%p) = {-1}\n", zip);
    return -1;
  }
  
  i32 status = 0;
  if (mtx_unlock(&zip->lock) != thrd_success) {
    printLog(ERR, "Could not unlock Zip.\n");
    status = -1;
  }
  
  printLog(TRACE, "EXIT zipUnlock(zip=%p) = {%d}\n", zip, status);
  return status;
}

/// @fn i32 zipSetFileName(Zip *zip, const char *fileName)
///
/// @brief Set the file name of a Zip object.
///
/// @param zip A pointer to the Zip object to set the file name of.
/// @param fileName The file name for the Zip.  This parameter may be NULL.
///
/// @return Returns 0 on success, -1 on failure.
i32 zipSetFileName(Zip *zip, const char *fileName) {
  printLog(TRACE, "ENTER zipSetFileName(zip=%p, fileName=\"%s\")\n",
    zip, fileName);
  
  if (zip == NULL) {
    printLog(ERR, "No Zip provided.\n");
    printLog(TRACE, "EXIT zipSetFileName(zip=%p, fileName=\"%s\") = {-1}\n",
      zip, fileName);
    return -1;
  }
  
  zip->fileName = stringDestroy(zip->fileName);
  if (fileName != NULL) {
    straddstr(&zip->fileName, fileName);
  }
  
  printLog(TRACE, "EXIT zipSetFileName(zip=%p, fileName=\"%s\") = {0}\n",
    zip, fileName);
  return 0;
}

/// @fn const char* zipGetFileName(const Zip *zip)
///
/// @brief Get the file name of a Zip object.
///
/// @param zip A pointer to a Zip object to get the file name of.
///
/// @return Returns the pointer to the file name on success, NULL on failure.
const char* zipGetFileName(const Zip *zip) {
  printLog(TRACE, "ENTER zipGetFileName(zip=%p)\n", zip);
  
  const char *fileName = "";
  if ((zip != NULL) && (zip->fileName != NULL)) {
    fileName = zip->fileName;
  }
  
  printLog(TRACE, "EXIT zipGetFileName(zip=%p) = {\"%s\"}\n", zip, fileName);
  return fileName;
}

/// @fn i64 zipGetLength(const Zip *zip)
///
/// @brief Get the length of the data managed by a Zip object.
///
/// @param zip A pointer to a Zip object to get the length of.
///
/// @return Returns the length of the data managed by the Zip object.
i64 zipGetLength(const Zip *zip) {
  printLog(TRACE, "ENTER zipGetLength(zip=%p)\n", zip);
  
  i64 dataLength = 0;
  if (zip != NULL) {
    dataLength = zip->dataLength;
  }
  
  printLog(TRACE, "EXIT zipGetLength(zip=%p) = {%llu}\n", zip, llu(dataLength));
  return dataLength;
}

/// @fn void* zipGetData(const Zip *zip)
///
/// @brief Get the data pointer from a Zip object.
///
/// @param zip A pointer to a Zip object to get the data pointer of.
///
/// @return Returns the pointer to the data of the Zip on success,
/// NULL on failure.
const void* zipGetData(const Zip *zip) {
  printLog(TRACE, "ENTER zipGetData(zip=%p)\n", zip);
  
  const void *data = NULL;
  if (zip != NULL) {
    data = zip->data;
  }
  
  printLog(TRACE, "EXIT zipGetData(zip=%p) = {%p}\n", zip, data);
  return data;
}

/// @fn void* zipDetachData(Zip *zip)
///
/// @brief Detach data from being managed by a Zip object.
///
/// @param zip A pointer to a Zip object to datach the data of.
///
/// @return Returns a pointer to the data previously managed by the Zip, if any.
void* zipDetachData(Zip *zip) {
  printLog(TRACE, "ENTER zipDetachData(zip=%p)\n", zip);
  
  void *data = NULL;
  if (zip != NULL) {
    data = zip->data;
    zip->data = NULL;
    zip->dataLength = 0;
  }
  
  printLog(TRACE, "EXIT zipDetachData(zip=%p) = {%p}\n", zip, data);
  return data;
}

/// @fn void* zipReadEntryByName(const Zip *zip, const char *entryName, i64 *entryLength)
///
/// @brief Read an entry from the Zip selected by its file name.
///
/// @param zip A pointer to the Zip object to read the entry from.
/// @param entryName The name of the entry in the Zip archive.
/// @param entryLength Output parameter holding the number of bytes in the
///   return value.  This may be a NULL pointer.
///
/// @return Returns a pointer to the decompressed data specified on success,
/// NULL on failure.
void* zipReadEntryByName(const Zip *zip, const char *entryName,
  i64 *entryLength
) {
  printLog(TRACE,
    "ENTER zipReadEntryByName(zip=%p, entryName=\"%s\", entryLength=%p)\n",
    zip, entryName, entryLength);
  
  if ((zip == NULL) || (entryName == NULL)) {
    printLog(ERR, "NULL parameter provided.\n");
    printLog(TRACE,
      "EXIT zipReadEntryByName(zip=%p, entryName=\"%s\", entryLength=%p) "
      "= {NULL}\n", zip, entryName, entryLength);
    return NULL;
  }
  
  // Cast to non-const so that we can lock it, unlock it, and make sure it's
  // readable.  The actual contents of the Zip will not be modified, so the
  // parameter needs to be const.
  zipLock((Zip*) zip);
  
  if (!_zipEnsureReadable((Zip*) zip)) {
    printLog(ERR, "Could not read Zip.\n");
    printLog(TRACE,
      "EXIT zipReadEntryByName(zip=%p, entryName=\"%s\", entryLength=%p) "
      "= {NULL}\n", zip, entryName, entryLength);
    zipUnlock((Zip*) zip);
    return NULL;
  }
  
  size_t size = 0;
  void *decompressedData = mz_zip_reader_extract_file_to_heap(zip->archive,
    entryName, &size, MZ_ZIP_FLAG_CASE_SENSITIVE);
  if (entryLength != NULL) {
    *entryLength = (i64) size;
  }
  
  zipUnlock((Zip*) zip);
  
  printLog(TRACE,
    "EXIT zipReadEntryByName(zip=%p, entryName=\"%s\", entryLength=%llu) "
    "= {%p}\n", zip, entryName, llu(size), decompressedData);
  return decompressedData;
}

/// @fn void* zipReadEntryByIndex(const Zip *zip, i64 entryIndex, i64 *entryLength)
///
/// @brief Read an entry from the Zip selected by its index.
///
/// @param zip A pointer to the Zip object to read the entry from.
/// @param entryIndex The index of the entry in the Zip table of contents.
/// @param entryLength Output parameter holding the number of bytes in the
///   return value.  This may be a NULL pointer.
///
/// @return Returns a pointer to the decompressed data specified on success,
/// NULL on failure.
void* zipReadEntryByIndex(const Zip *zip, i64 entryIndex, i64 *entryLength) {
  printLog(TRACE,
    "ENTER zipReadEntryByIndex(zip=%p, entryIndex=%llu, entryLength=%p)\n",
    zip, llu(entryIndex), entryLength);
  
  if (zip == NULL) {
    printLog(ERR, "NULL parameter provided.\n");
    printLog(TRACE,
      "EXIT zipReadEntryByIndex(zip=%p, entryIndex=%llu, entryLength=%p) "
      "= {NULL}\n", zip, llu(entryIndex), entryLength);
    return NULL;
  }
  
  // Cast to non-const so that we can lock it, unlock it, and make sure it's
  // readable.  The actual contents of the Zip will not be modified, so the
  // parameter needs to be const.
  zipLock((Zip*) zip);
  
  if (!_zipEnsureReadable((Zip*) zip)) {
    printLog(ERR, "Could not read Zip.\n");
    printLog(TRACE,
      "EXIT zipReadEntryByIndex(zip=%p, entryIndex=%llu, entryLength=%p) "
      "= {NULL}\n", zip, llu(entryIndex), entryLength);
    zipUnlock((Zip*) zip);
    return NULL;
  }
  
  size_t size = 0;
  void *decompressedData = mz_zip_reader_extract_to_heap(zip->archive,
    entryIndex, &size, MZ_ZIP_FLAG_CASE_SENSITIVE);
  if (entryLength != NULL) {
    *entryLength = (i64) size;
  }
  
  zipUnlock((Zip*) zip);
  
  printLog(TRACE,
    "EXIT zipReadEntryByIndex(zip=%p, entryIndex=%llu, entryLength=%p) "
    "= {%p}\n", zip, llu(entryIndex), entryLength, decompressedData);
  return decompressedData;
}

/// @fn i32 zipAddEntry_(Zip *zip, const char *entryName, const volatile void *data, i64 dataLength, int level, ...)
///
/// @brief Add a new entry to an existing Zip object.
///
/// @note This function is wrapped by a macro of the same name (minus the
/// trailing underscore) that automatically provides
/// ZIP_DEFAULT_COMPRESSION_LEVEL as the compression level.
///
/// @param zip A pointer to the Zip object to add an entry to.
/// @param entryName A string representing the name of the entry in the Zip.
///   If the entry to be added is a directory, end the name with a trailing '/'.
/// @param data A pointer to the data for the entry.
/// @param dataLength A i64 with the number of bytes held at the data pointer.
/// @param level Optional parameter for the compression level.  Must be one of
///   the compression levels supported by zip archives (0 to 9, inclusive).
///
/// @return Returns 0 on success, -1 on failure.
i32 zipAddEntry_(Zip *zip, const char *entryName,
  const volatile void *data, i64 dataLength, int level, ...
) {
  printLog(TRACE,
    "ENTER zipAddEntry(zip=%p, entryName=\"%s\", data=%p, dataLength=%llu, "
    "level=%d)\n", zip, entryName, data, llu(dataLength), level);
  
  if ((zip == NULL) || (entryName == NULL)) {
    printLog(ERR, "One or more NULL required parameters.\n");
    printLog(TRACE,
      "EXIT zipAddEntry(zip=%p, entryName=\"%s\", data=%p, dataLength=%llu, "
      "level=%d) = {-1}\n", zip, entryName, data, llu(dataLength), level);
    return -1;
  } else if ((*entryName == '/') || (strchr(entryName, '\\'))
    || (strchr(entryName, ':'))
  ) {
    printLog(ERR, "entryName cannot start with '/' or contain '\\' or ':'.\n");
    printLog(TRACE,
      "EXIT zipAddEntry(zip=%p, entryName=\"%s\", data=%p, dataLength=%llu, "
      "level=%d) = {-1}\n", zip, entryName, data, llu(dataLength), level);
    return -1;
  }
  
  // It's not an error for data to be NULL or dataLength to be 0.  In fact, this
  // is required when adding a directory.
  
  zipLock(zip);
  
  if (!_zipEnsureWritable(zip)) {
    printLog(ERR, "Could not make Zip writable.\n");
    printLog(TRACE,
      "EXIT zipAddEntry(zip=%p, entryName=\"%s\", data=%p, dataLength=%llu, "
      "level=%d) = {-1}\n", zip, entryName, data, llu(dataLength), level);
    zipUnlock(zip);
    return -1;
  }
  
  size_t size = (size_t) dataLength;
  mz_uint flags = level | MZ_ZIP_FLAG_CASE_SENSITIVE;
  mz_uint32 attributes = MINIZ_ATTRIBUTE_UNIX_PERMISSIONS(00600); // owner RW
  size_t entryNameLength = strlen(entryName);
  if ((entryNameLength > 0) && (entryName[entryNameLength - 1] != '/')) {
    attributes |= MINIZ_ATTRIBUTE_NORMAL;
  }
  const char *fileExtension = strrchr(entryName, '.');
  if ((fileExtension != NULL) && (strcmp(fileExtension, ".exe") == 0)) {
    // Make it executable for the owner on UNIX systems.
    attributes |= MINIZ_ATTRIBUTE_UNIX_PERMISSIONS(00100);
  }

  if (!mz_zip_writer_add_mem_ex(zip->archive, entryName, (void*) data, size,
    NULL /*comment*/, 0 /*comment_size*/,
    flags, 0 /*uncomp_size*/, 0 /*uncomp_crc32*/,
    attributes)
  ) {
    printLog(ERR, "Could not add memory to Zip archive.\n");
    printLog(TRACE,
      "EXIT zipAddEntry(zip=%p, entryName=\"%s\", data=%p, dataLength=%llu, "
      "level=%d) = {-1}\n", zip, entryName, data, llu(dataLength), level);
    zipUnlock(zip);
    return -1;
  }
  
  // Adding the data was successful.  Update our metadata.
  zip->numEntries++;
  
  zipUnlock(zip);
  
  printLog(TRACE,
    "EXIT zipAddEntry(zip=%p, entryName=\"%s\", data=%p, dataLength=%llu, "
    "level=%d) = {0}\n", zip, entryName, data, llu(dataLength), level);
  return 0;
}

/// @fn i64 zipGetNumEntries(Zip *zip)
///
/// @brief Get the number of entries in a Zip archive.
///
/// @note As of today (2022-06-20), the numEntries member of a Zip object is
/// always valid and up-to-date.  However, this may not be true in the future,
/// so this abstraction is provided.  The numEntries member of the Zip object
/// should *NOT* be relied on in general.  For now, however, we just return the
/// value of the member variable.
///
/// @param zip A pointer to the Zip object to get the number of entries of.
///
/// @return Returns the number of entries in the Zip object.
i64 zipGetNumEntries(Zip *zip) {
  printLog(TRACE, "ENTER zipGetNumEntries(zip=%p)\n", zip);
  
  zipLock(zip);
  i64 returnValue = zip->numEntries;
  zipUnlock(zip);
  
  printLog(TRACE, "EXIT zipGetNumEntries(zip=%p) = {%llu}",
    zip, llu(returnValue));
  return returnValue;
}

/// @fn const char** zipGetEntryNames(Zip *zip)
///
/// @brief Get the array of entry names for the Zip.
///
/// @param zip A pointer to the Zip object to get the entry names of.
///
/// @return Returns a pointer to a one-dimensional array of entry names on
/// success, NULL on failure.
const char** zipGetEntryNames(Zip *zip) {
  printLog(TRACE, "ENTER zipGetEntryNames(zip=%p)", zip);
  
  if (zip == NULL) {
    printLog(ERR, "No Zip provided.\n");
    printLog(TRACE, "EXIT zipGetEntryNames(zip=%p) = {NULL}", zip);
    return NULL;
  }
  
  zipLock(zip);
  if (!_zipEnsureReadable(zip)) {
    printLog(ERR, "Could not read Zip.\n");
    printLog(TRACE, "EXIT zipGetEntryNames(zip=%p) = {NULL}", zip);
    zipUnlock(zip);
    return NULL;
  }
  zipUnlock(zip);
  
  printLog(TRACE, "EXIT zipGetEntryNames(zip=%p) = {%p}", zip, zip->entryNames);
  return (const char**) zip->entryNames;
}

/// @fn const char* zipGetEntryName(Zip *zip, i64 index)
///
/// @brief Get a single entry name from a Zip object.
///
/// @param zip A pointer to the Zip object to get the entry name from.
/// @param index A i64 indicating the index of the entry name to get.
///
/// @return Returns a pointer to the specified entry name on success,
/// NULL on failure.
const char* zipGetEntryName(Zip *zip, i64 index) {
  printLog(TRACE, "ENTER zipGetEntryName(zip=%p)", zip);
  
  if (zip == NULL) {
    printLog(ERR, "No Zip provided.\n");
    printLog(TRACE, "EXIT zipGetEntryName(zip=%p) = {NULL}", zip);
    return NULL;
  }
  
  zipLock(zip);
  if (!_zipEnsureReadable(zip)) {
    printLog(ERR, "Could not read Zip.\n");
    printLog(TRACE, "EXIT zipGetEntryName(zip=%p) = {NULL}", zip);
    zipUnlock(zip);
    return NULL;
  }
  zipUnlock(zip);
  
  if (index > zip->numEntries) {
    printLog(ERR, "Index out of range.\n");
    printLog(TRACE, "EXIT zipGetEntryName(zip=%p) = {NULL}", zip);
    return NULL;
  }
  
  printLog(TRACE, "EXIT zipGetEntryName(zip=%p) = {%p}",
    zip, zip->entryNames[index]);
  return zip->entryNames[index];
}

/// @fn const i64* zipGetEntrySizes(Zip *zip)
///
/// @brief Get the array of entry sizes for the Zip.
///
/// @param zip A pointer to the Zip object to get the entry sizes of.
///
/// @return Returns a pointer to a one-dimensional array of entry sizes on
/// success, NULL on failure.
const i64* zipGetEntrySizes(Zip *zip) {
  printLog(TRACE, "ENTER zipGetEntrySizes(zip=%p)", zip);
  
  if (zip == NULL) {
    printLog(ERR, "No Zip provided.\n");
    printLog(TRACE, "EXIT zipGetEntrySizes(zip=%p) = {NULL}", zip);
    return NULL;
  }
  
  zipLock(zip);
  if (!_zipEnsureReadable(zip)) {
    printLog(ERR, "Could not read Zip.\n");
    printLog(TRACE, "EXIT zipGetEntrySizes(zip=%p) = {NULL}", zip);
    zipUnlock(zip);
    return NULL;
  }
  zipUnlock(zip);
  
  printLog(TRACE, "EXIT zipGetEntrySizes(zip=%p) = {%p}", zip, zip->entrySizes);
  return zip->entrySizes;
}

/// @fn const char* zipGetEntrySize(Zip *zip, i64 index)
///
/// @brief Get a single entry size from a Zip object.
///
/// @param zip A pointer to the Zip object to get the entry size from.
/// @param index A i64 indicating the index of the entry size to get.
///
/// @return Returns a i64 of the specified entry size on success, 0 on failure.
i64 zipGetEntrySize(Zip *zip, i64 index) {
  printLog(TRACE, "ENTER zipGetEntrySize(zip=%p)", zip);
  
  u64 entrySize = 0;
  if (zip == NULL) {
    printLog(ERR, "No Zip provided.\n");
    printLog(TRACE, "EXIT zipGetEntrySize(zip=%p) = {0}", zip);
    return entrySize; // 0
  }
  
  zipLock(zip);
  if (!_zipEnsureReadable(zip)) {
    printLog(ERR, "Could not read Zip.\n");
    printLog(TRACE, "EXIT zipGetEntrySize(zip=%p) = {0}", zip);
    zipUnlock(zip);
    return entrySize; // 0
  }
  
  if (index > zip->numEntries) {
    zipUnlock(zip);
    printLog(ERR, "Index out of range.\n");
    printLog(TRACE, "EXIT zipGetEntrySize(zip=%p) = {0}", zip);
    return entrySize; // 0
  }
  
  entrySize = zip->entrySizes[index];
  
  zipUnlock(zip);
  
  printLog(TRACE, "EXIT zipGetEntrySize(zip=%p) = {%llu}",
    zip, llu(entrySize));
  return entrySize;
}

/// @fn bool zipHasEntry(Zip *zip, const char *entryName)
///
/// @brief Determine whether or not a zip archive has an entry of a specified
/// name.
///
/// @param zip A pointer to the Zip object to get the entry size from.
/// @param entryName The name of the entry to search for.
///
/// @return Returns true if the specified name is found in the Zip object,
/// false if not.
bool zipHasEntry(Zip *zip, const char *entryName) {
  printLog(TRACE, "ENTER zipHasEntry(zip=%p, entryName=%p)",
    zip, entryName);
  
  bool entryFound = false;
  
  if ((zip == NULL) || (entryName == NULL)) {
    printLog(ERR, "One or more NULL parameters provided.\n");
    printLog(TRACE, "EXIT zipHasEntry(zip=%p, entryName=%p) = {false}",
      zip, entryName);
    return entryFound; // false
  }
  
  zipLock(zip);
  if (!_zipEnsureReadable(zip)) {
    zipUnlock(zip);
    printLog(ERR, "Could not read Zip.\n");
    printLog(TRACE, "EXIT zipHasEntry(zip=%p, entryName=\"%s\") = {false}",
      zip, entryName);
    return entryFound; // false
  }
  
  for (i64 index = 0; index < zip->numEntries; index++) {
    char **entryNames = zip->entryNames;
    if (strcmp(entryNames[index], entryName) == 0) {
      entryFound = true;
      break;
    }
  }
  
  zipUnlock(zip);
  
  printLog(TRACE, "EXIT zipHasEntry(zip=%p, entryName=\"%s\") = {%s}",
    zip, entryName, boolNames[entryFound]);
  return entryFound;
}

/// @fn i32 zipClose(Zip *zip)
///
/// @brief Close out a Zip archive so that it can be properly used by something
/// else.
///
/// @param zip A pointer to the Zip archive to close.
///
/// @return Returns 0 on success, -1 on failure.
i32 zipClose(Zip *zip) {
  printLog(TRACE, "ENTER zipClose(zip=%p)\n", zip);
  
  if ((zip == NULL) || (zip->archive == NULL)
    || (zip->zipMode == ZIP_MODE_NOT_OPEN)
  ) {
    // Nothing to do.
    printLog(TRACE, "EXIT zipClose(zip=%p) = {0}\n", zip);
    return 0;
  }
  
  if (zip->zipMode == ZIP_MODE_READ) {
    // This is the expected case.
    if (!mz_zip_reader_end(zip->archive)) {
      printLog(ERR, "Could not end Zip reader.\n");
      printLog(TRACE, "EXIT zipClose(zip=%p) = {-1}\n", zip);
      return -1;
    }
  } else { // zip->zipMode == ZIP_MODE_WRITE
    // Close everything out for the write.
    if (zip->zipLocation == ZIP_LOCATION_MEMORY) {
      // Zip is a "heap archive".
      size_t dataLength = (size_t) zip->dataLength;
      if (mz_zip_writer_finalize_heap_archive(
        zip->archive, &zip->data, &dataLength)
      ) {
        // Update zip->dataLength so we can write the data correctly below.
        zip->dataLength = (i64) dataLength;
        
        if (!mz_zip_writer_end(zip->archive)) {
          printLog(ERR, "Could not end in-memory Zip writer.\n");
          printLog(TRACE, "EXIT zipClose(zip=%p) = {-1}\n", zip);
          return -1;
        }
      } else {
        printLog(ERR, "Could not finalize in-memory Zip writer.\n");
        printLog(TRACE, "EXIT zipClose(zip=%p) = {-1}\n", zip);
        return -1;
      }
      
      if ((zip->dataLength > 0) && (zip->fileName != NULL)) {
        // Write the file to disk.
        i64 bytesWritten
          = putFileContent(zip->fileName, zip->data, zip->dataLength);
        if (bytesWritten != zip->dataLength) {
          printLog(ERR, "Only wrote %llu of %llu Bytes to Zip file.\n",
            llu(bytesWritten), llu(zip->dataLength));
          printLog(TRACE, "EXIT zipClose(zip=%p) = {-1}\n", zip);
          return -1;
        }
      }
    } else if (zip->zipLocation == ZIP_LOCATION_FILE) {
      // Zip is a file-based archive.
      if (mz_zip_writer_finalize_archive(zip->archive)) {
        if (!mz_zip_writer_end(zip->archive)) {
          printLog(ERR, "Could not end on-disk Zip writer.\n");
          printLog(TRACE, "EXIT zipClose(zip=%p) = {-1}\n", zip);
          return -1;
        }
      } else {
        printLog(ERR, "Could not finalize on-disk Zip writer.\n");
        printLog(TRACE, "EXIT zipClose(zip=%p) = {-1}\n", zip);
        return -1;
      }
    } // else zip->zipLocation == ZIP_LOCATION_NONE
  }
  
  zip->zipMode = ZIP_MODE_NOT_OPEN;
  
  printLog(TRACE, "EXIT zipClose(zip=%p) = {0}\n", zip);
  return 0;
}

/// @fn i32 zipFlush_(Zip *zip, const char *fileName, ...)
///
/// @brief Flush a Zip archive to disk, if possible.
///
/// @note This function is wrapped by a macro of the same name (minus the
/// trailing underscore) that automatically provides NULL for the fileName
/// parameter if none is provided.
///
/// @param zip A pointer to a Zip object to flush to disk.
/// @param fileName The name of the file to flush the Zip to.  This parameter
///  may be NULL.  The fileName member of the Zip object will be used if so.
///
/// @return Returns 0 on success, -1 on failure.
i32 zipFlush_(Zip *zip, const char *fileName, ...) {
  printLog(TRACE, "ENTER zipFlush(zip=%p, fileName=\"%s\")\n",
    zip, (fileName != NULL) ? fileName : "");
  
  if (zip == NULL) {
    // Nothing to do.
    printLog(TRACE, "EXIT zipFlush(zip=%p, fileName=\"%s\") = {0}\n",
      zip, (fileName != NULL) ? fileName : "");
    return 0;
  }
  
  if (zip->zipMode == ZIP_MODE_WRITE) {
    i32 returnValue = zipClose(zip);
    if (returnValue != 0) {
      printLog(ERR, "Could not close and flush Zip.\n");
      return returnValue;
    }
    
    if (fileName == NULL) {
      // There's nothing more for us to do beyond what was done in zipClose.
      printLog(TRACE, "EXIT zipFlush(zip=%p, fileName=\"%s\") = {0}\n",
        zip, (fileName != NULL) ? fileName : "");
      return 0;
    }
  }
  
  if (fileName == NULL) {
    // We're intended to flush to the file specified in the Zip.
    fileName = zip->fileName;
  }
  
  if (fileName == NULL) {
    // Nothing to do.
    printLog(TRACE, "EXIT zipFlush(zip=%p, fileName=\"%s\") = {0}\n",
      zip, (fileName != NULL) ? fileName : "");
    return 0;
  }
  
  // fileName is valid.  Write the Zip.
  if (zip->zipLocation == ZIP_LOCATION_MEMORY) {
    // Write the content of the data member to disk.
    if ((zip->data == NULL) || (zip->dataLength == 0)) {
      printLog(ERR, "Cannot flush Zip due to missing data.\n");
      printLog(TRACE, "EXIT zipFlush(zip=%p, fileName=\"%s\") = {-1}\n",
        zip, (fileName != NULL) ? fileName : "");
      return -1;
    }
    
    if (putFileContent(fileName,
      zip->data, zip->dataLength) != zip->dataLength
    ) {
      printLog(ERR, "Failed to write Zip data to \"%s\".\n", fileName);
      printLog(TRACE, "EXIT zipFlush(zip=%p, fileName=\"%s\") = {-1}\n",
        zip, (fileName != NULL) ? fileName : "");
      return -1;
    }
  } else if (zip->zipLocation == ZIP_LOCATION_FILE) {
    // Read the file in and write it to the new location if it makes sense to
    // do so.
    if (zip->fileName == NULL) {
      printLog(ERR, "Cannot flush Zip due to missing Zip file name.\n");
      printLog(TRACE, "EXIT zipFlush(zip=%p, fileName=\"%s\") = {-1}\n",
        zip, (fileName != NULL) ? fileName : "");
      return -1;
    }
    
    if (strcmp(zip->fileName, fileName) == 0) {
      // Input file and output file are the same.  No-op.
      printLog(TRACE, "EXIT zipFlush(zip=%p, fileName=\"%s\") = {0}\n",
        zip, (fileName != NULL) ? fileName : "");
      return 0;
    }
    
    Bytes zipData = getFileContent(zip->fileName);
    if (bytesLength(zipData) == 0) {
      zipData = bytesDestroy(zipData);
      printLog(ERR, "Cannot flush Zip due to zero-length input file.\n");
      printLog(TRACE, "EXIT zipFlush(zip=%p, fileName=\"%s\") = {-1}\n",
        zip, (fileName != NULL) ? fileName : "");
      return -1;
    }
    
    if (putFileContent(fileName,
      zipData, bytesLength(zipData)) != zip->dataLength
    ) {
      zipData = bytesDestroy(zipData);
      printLog(ERR, "Failed to write Zip data to \"%s\".\n", fileName);
      printLog(TRACE, "EXIT zipFlush(zip=%p, fileName=\"%s\") = {-1}\n",
        zip, (fileName != NULL) ? fileName : "");
      return -1;
    }
    zipData = bytesDestroy(zipData);
  } // else zip->location == ZIP_LOCATION_NONE and there's nothing to do
  
  printLog(TRACE, "EXIT zipFlush(zip=%p, fileName=\"%s\") = {0}\n",
    zip, (fileName != NULL) ? fileName : "");
  return 0;
}

/// @fn Zip* zipDestroy(Zip *zip)
///
/// @brief Close a Zip archive (if it's not already closed) and release its
/// resources.
///
/// @param zip A pointer to the Zip archive to close and destroy.
///
/// @return This function always succeeds and always returns NULL.
Zip* zipDestroy(Zip *zip) {
  printLog(TRACE, "ENTER zipDestroy(zip=%p)\n", zip);
  
  if (zip == NULL) {
    // Not an error, but nothing to do.
    printLog(TRACE, "EXIT zipDestroy(zip=NULL) = {NULL}\n");
    return NULL;
  }
  
  mtx_destroy(&zip->lock);
  
  if (zip->entryNames != NULL) {
    for (i64 i = 0; i < zip->numEntries; i++) {
      zip->entryNames[i] = stringDestroy(zip->entryNames[i]);
    }
    zip->entryNames = (char**) pointerDestroy(zip->entryNames);
  }
  
  zip->entrySizes = (i64*) pointerDestroy(zip->entrySizes);
  
  // No need to free zip->numEntries
  // No need to free zip->zipMode (we need it to close the Zip anyway)
  // No need to free zip->zipLocation (we need it to close the Zip anyway)
  
  if (zipClose(zip) != 0) {
    printLog(ERR, "Could not close Zip.\n");
  }
  
  zip->fileName = stringDestroy(zip->fileName);
  if (zip->leaseData == false) {
    zip->data = pointerDestroy(zip->data);
  } else {
    zip->data = NULL;
  }
  zip->archive = (mz_zip_archive*) pointerDestroy(zip->archive);
  zip = (Zip*) pointerDestroy(zip);
  
  printLog(TRACE, "EXIT zipDestroy(zip=%p) = {NULL}\n", zip);
  return NULL;
}


/// @def COMPRESSED_DATA_UNIT_TEST
///
/// @brief Unit test for compressed data functionality.
/// @details Implementing this as a macro instead of raw code allows this to
/// be skipped by the code coverage metrics.
///
/// @return Returns true on success, false on failure.
#define COMPRESSED_DATA_UNIT_TEST \
bool compressedDataUnitTest() { \
  const char *inputData = "The quick brown fox jumped over the lazy dogs."; \
  i64 inputDataLength = (i64) strlen(inputData) + 1; \
  char *outputData = NULL; \
  i64 outputDataLength = 0; \
   \
  CompressedData *compressedData = compressData(inputData, inputDataLength); \
  if (compressedData == NULL) { \
    printLog(ERR, "compressData with valid input data returned NULL.\n"); \
    return false; \
  } \
  if (compressedDataGetLength(compressedData) > inputDataLength) { \
    printLog(ERR, "Compressed data is %llu Bytes longer than the input.\n", \
      llu(compressedDataGetLength(compressedData) - inputDataLength)); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
  printLog(INFO, "compressData returned %llu bytes.\n", \
    llu(compressedDataGetLength(compressedData))); \
  printLog(INFO, "Data:\n"); \
  printBinary(INFO, compressedDataGetData(compressedData), \
    compressedDataGetLength(compressedData)); \
   \
  outputData = (char*) decompressData(compressedData); \
  if (outputData == NULL) { \
    printLog(ERR, "decompressData with valid CompressedData returned NULL.\n"); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
  if (strcmp(inputData, outputData) != 0) { \
    printLog(ERR, "Decompressed data did not match inputData.\n"); \
    printLog(ERR, "Expected \"%s\"\n.", inputData); \
    printLog(ERR, "Got \"%s\"\n.", outputData); \
    outputData = stringDestroy(outputData); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
  outputData = stringDestroy(outputData); \
   \
  outputData = (char*) decompressData(compressedData, &outputDataLength); \
  if (outputData == NULL) { \
    printLog(ERR, \
      "decompressData with valid outputDataLength returned NULL.\n"); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
  if (outputDataLength != inputDataLength) { \
    printLog(ERR, "inputDataLength did not match outputDataLength.\n"); \
    printLog(ERR, "Expected %llu.\n", llu(inputDataLength + 1)); \
    printLog(ERR, "Got %llu.\n", llu(outputDataLength)); \
    outputData = stringDestroy(outputData); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
  if (strcmp(inputData, outputData) != 0) { \
    printLog(ERR, "Decompressed data did not match inputData.\n"); \
    printLog(ERR, "Expected \"%s\"\n.", inputData); \
    printLog(ERR, "Got \"%s\"\n.", outputData); \
    outputData = stringDestroy(outputData); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
  outputData = stringDestroy(outputData); \
  compressedData = compressedDataDestroy(compressedData); \
   \
  inputData = "The quick brown fox jumped over the lazy dogs." \
    "The quick brown fox jumped over the lazy dogs."; \
  inputDataLength = (i64) strlen(inputData) + 1; \
  outputData = NULL; \
  outputDataLength = 0; \
  compressedData = compressData(inputData, inputDataLength); \
  if (compressedData == NULL) { \
    printLog(ERR, "compressData with valid input data returned NULL.\n"); \
    return false; \
  } \
  if (compressedDataGetLength(compressedData) > inputDataLength) { \
    printLog(ERR, "Compressed data is %llu Bytes longer than the input.\n", \
      llu(compressedDataGetLength(compressedData) - inputDataLength)); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
  printLog(INFO, "compressData returned %llu bytes.\n", \
    llu(compressedDataGetLength(compressedData))); \
  printLog(INFO, "Data:\n"); \
  printBinary(INFO, compressedDataGetData(compressedData), \
    compressedDataGetLength(compressedData)); \
   \
  outputData = (char*) decompressData(compressedData, &outputDataLength); \
  if (outputData == NULL) { \
    printLog(ERR, \
      "decompressData with valid outputDataLength returned NULL.\n"); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
  if (outputDataLength != inputDataLength) { \
    printLog(ERR, "inputDataLength did not match outputDataLength.\n"); \
    printLog(ERR, "Expected %llu.\n", llu(inputDataLength + 1)); \
    printLog(ERR, "Got %llu.\n", llu(outputDataLength)); \
    outputData = stringDestroy(outputData); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
  if (strcmp(inputData, outputData) != 0) { \
    printLog(ERR, "Decompressed data did not match inputData.\n"); \
    printLog(ERR, "Expected \"%s\"\n.", inputData); \
    printLog(ERR, "Got \"%s\"\n.", outputData); \
    outputData = stringDestroy(outputData); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
  outputData = stringDestroy(outputData); \
  compressedData = compressedDataDestroy(compressedData); \
   \
  compressedData = compressData(NULL, inputDataLength); \
  if (compressedData != NULL) { \
    printLog(ERR, "compressData returned non-NULL with NULL inputData.\n"); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
   \
  compressedData = compressData(inputData, 0); \
  if (compressedData != NULL) { \
    printLog(ERR, \
      "compressData returned non-NULL with zero-length inputData.\n"); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
   \
  compressedData = compressData(NULL, 0); \
  if (compressedData != NULL) { \
    printLog(ERR, \
      "compressData returned non-NULL with NULL and zero-length inputData.\n"); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
   \
  outputData = (char*) decompressData(NULL, &outputDataLength); \
  if (outputData != NULL) { \
    printLog(ERR, \
      "decompressData returned non-NULL with NULL compressedData.\n"); \
    outputData = stringDestroy(outputData); \
    return false; \
  } \
   \
  outputData = (char*) decompressData(NULL, NULL); \
  if (outputData != NULL) { \
    printLog(ERR, \
      "decompressData returned non-NULL with NULL compressedData and " \
      "output length.\n"); \
    outputData = stringDestroy(outputData); \
    return false; \
  } \
   \
  /* Get a legitimate CompressedData object to play with. */ \
  compressedData = compressData(inputData, inputDataLength); \
  if (compressedData == NULL) { \
    printLog(ERR, "compressData with valid input data returned NULL.\n"); \
    return false; \
  } \
  outputData = stringDestroy(outputData); \
  outputDataLength = 0; \
   \
  Bytes compressedBytes \
    = compressedDataToBlob(compressedData); \
  if (compressedBytes == NULL) { \
    printLog(ERR, "compressedDataToBlob with good input returned NULL.\n"); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
  outputDataLength = bytesSize(compressedBytes); \
   \
  CompressedData *newCompressedData \
    = compressedDataFromBlob(compressedBytes, &outputDataLength); \
  compressedBytes = bytesDestroy(compressedBytes); \
  if (newCompressedData == NULL) { \
    printLog(ERR, \
      "compressedDataFromBlob with good input returned NULL.\n"); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
   \
  outputData = (char*) decompressData(newCompressedData); \
  if (outputData == NULL) { \
    printLog(ERR, "decompressData with newCompressedData returned NULL.\n"); \
    newCompressedData = compressedDataDestroy(newCompressedData); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
  if (strcmp(inputData, outputData) != 0) { \
    printLog(ERR, \
      "Data returned from decompressData with newCompressedData was not " \
      "as expected.\n"); \
    printLog(ERR, "Expected \"%s\".\n", inputData); \
    printLog(ERR, "Found \"%s\".\n", outputData); \
    outputData = stringDestroy(outputData); \
    newCompressedData = compressedDataDestroy(newCompressedData); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
   \
  outputData = stringDestroy(outputData); \
  newCompressedData = compressedDataDestroy(newCompressedData); \
  compressedData = compressedDataDestroy(compressedData); \
   \
  /* Verify that encoding the dataIsRaw bit as the high-order bit of the */ \
  /* header works correctly. */ \
  inputData = "The quick brown fox jumped over the lazy dogs."; \
  inputDataLength = (i64) strlen(inputData) + 1; \
  compressedData = compressData(inputData, inputDataLength); \
  if (compressedData == NULL) { \
    printLog(ERR, "compressData with valid input data returned NULL.\n"); \
    return false; \
  } \
  compressedBytes \
    = compressedDataToBlob(compressedData); \
  if (compressedBytes == NULL) { \
    printLog(ERR, "compressedDataToBlob with good input returned NULL.\n"); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
  outputDataLength = bytesSize(compressedBytes); \
  newCompressedData \
    = compressedDataFromBlob(compressedBytes, &outputDataLength); \
  compressedBytes = bytesDestroy(compressedBytes); \
  if (newCompressedData == NULL) { \
    printLog(ERR, \
      "compressedDataFromBlob with good input returned NULL.\n"); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
  outputData = (char*) decompressData(newCompressedData); \
  if (outputData == NULL) { \
    printLog(ERR, "decompressData with newCompressedData returned NULL.\n"); \
    newCompressedData = compressedDataDestroy(newCompressedData); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
  if (strcmp(inputData, outputData) != 0) { \
    printLog(ERR, \
      "Data returned from decompressData with newCompressedData was not " \
      "as expected.\n"); \
    printLog(ERR, "Expected \"%s\".\n", inputData); \
    printLog(ERR, "Found \"%s\".\n", outputData); \
    outputData = stringDestroy(outputData); \
    newCompressedData = compressedDataDestroy(newCompressedData); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
   \
  outputData = stringDestroy(outputData); \
  newCompressedData = compressedDataDestroy(newCompressedData); \
   \
  /* Verify negative cases. */ \
  compressedBytes = compressedDataToBlob(NULL); \
  if (outputData != NULL) { \
    printLog(ERR, \
      "compressedDataToBlob with NULL input returned non-NULL.\n"); \
    outputData = stringDestroy(outputData); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
   \
  compressedBytes \
    = compressedDataToBlob(compressedData); \
  outputDataLength = bytesSize(compressedBytes); \
  if (compressedBytes == NULL) { \
    printLog(ERR, "compressedDataToBlob with good input returned NULL.\n"); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
   \
  outputDataLength -= 2; \
  newCompressedData \
    = compressedDataFromBlob(compressedBytes, &outputDataLength); \
  if (newCompressedData != NULL) { \
    printLog(ERR, \
      "compressedDataFromBlob with short data length " \
      "returned non-NULL.\n"); \
    newCompressedData = compressedDataDestroy(newCompressedData); \
    compressedBytes = bytesDestroy(compressedBytes); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
   \
  compressedBytes = bytesDestroy(compressedBytes); \
  compressedData = compressedDataDestroy(compressedData); \
   \
  /* Verify encoding/decoding. */ \
  inputData = "The quick brown fox jumped over the lazy dogs." \
    "The quick brown fox jumped over the lazy dogs."; \
  inputDataLength = (i64) strlen(inputData) + 1; \
  compressedData = compressData(inputData, inputDataLength); \
  if (compressedDataGetLength(compressedData) >= inputDataLength) { \
    printLog(ERR, "Could not compress compressible data.\n"); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
  outputData = (char*) decompressData(compressedData, &outputDataLength); \
  if ((outputDataLength != inputDataLength) \
    || (strcmp(outputData, inputData) != 0) \
  ) { \
    printLog(ERR, "outputData did not match inputData.\n"); \
    printLog(ERR, "Expected \"%s\" (%lld bytes).\n", \
      inputData, lld(inputDataLength)); \
    printLog(ERR, "Got \"%s\" (%lld bytes).\n", \
      outputData, lld(outputDataLength)); \
    outputData = stringDestroy(outputData); \
    return false; \
  } \
  outputData = stringDestroy(outputData); \
   \
  char *escapedString = escapeData(compressedDataGetData(compressedData), \
    compressedDataGetLength(compressedData)); \
  Bytes escapedBytes = NULL; \
  bytesAddStr(&escapedBytes, escapedString); \
  escapedString = stringDestroy(escapedString); \
  unescapeBytes(escapedBytes); \
  if ((bytesLength(escapedBytes) \
      != (u64) compressedDataGetLength(compressedData)) \
    || (memcmp((void*) escapedBytes, compressedDataGetData(compressedData), \
      bytesLength(escapedBytes)) != 0) \
  ) { \
    printLog(ERR, "Unescaped Bytes did not match compressedData.\n"); \
    printLog(ERR, "Expected %llu bytes, got %llu.\n", \
      llu(compressedDataGetLength(compressedData)), \
      llu(bytesLength(escapedBytes))); \
    u64 length = bytesLength(escapedBytes); \
    if ((u64) compressedDataGetLength(compressedData) < length) { \
      length = (u64) compressedDataGetLength(compressedData); \
    } \
    unsigned char *data \
      = (unsigned char*) compressedDataGetData(compressedData); \
    for (u64 i = 0; i < length; i++) { \
      if (escapedBytes[i] != data[i]) { \
        printLog(ERR, "Byte %llu, expected '%c' (0x%02X), got '%c' (0x%02X).\n", \
          llu(i), data[i], data[i], escapedBytes[i], escapedBytes[i]); \
        if (i > 0) { \
          printLog(ERR, "Byte %llu, was '%c' (0x%02X).\n",  \
            llu(i - 1), data[i - 1], data[i - 1]); \
        } \
        break; \
      } \
    } \
    escapedBytes = bytesDestroy(escapedBytes); \
    compressedData = compressedDataDestroy(compressedData); \
    return false; \
  } \
  compressedData = compressedDataDestroy(compressedData); \
   \
  compressedData = compressedDataCreate(escapedBytes, bytesLength(escapedBytes), \
    false, true); \
  outputData = (char*) decompressData(compressedData, &outputDataLength); \
  compressedData = compressedDataDestroy(compressedData); \
  escapedBytes = bytesDestroy(escapedBytes); \
   \
  if ((outputDataLength != inputDataLength) \
    || (strcmp(outputData, inputData) != 0) \
  ) { \
    printLog(ERR, "outputData did not match inputData.\n"); \
    printLog(ERR, "Expected \"%s\" (%lld bytes).\n", \
      inputData, lld(inputDataLength)); \
    printLog(ERR, "Got \"%s\" (%lld bytes).\n", \
      outputData, lld(outputDataLength)); \
    outputData = stringDestroy(outputData); \
    return false; \
  } \
  outputData = stringDestroy(outputData); \
   \
  return true; \
}
COMPRESSED_DATA_UNIT_TEST

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

bool zipUnitTest() {
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

