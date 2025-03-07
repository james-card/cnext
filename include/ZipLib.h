///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              06.15.2022
///
/// @file              ZipLib.h
///
/// @brief             This library contains the function and structure
///                    definitions that make up the Zip data structure.
///
/// @details           This library relies on the miniz implementation.
///
/// @copyright
///                   Copyright (c) 2012-2025 James Card
///
/// Permission is hereby granted, free of charge, to any person obtaining a
/// copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation
/// the rights to use, copy, modify, merge, publish, distribute, sublicense,
/// and/or sell copies of the Software, and to permit persons to whom the
/// Software is furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included
/// in all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
/// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
/// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
/// DEALINGS IN THE SOFTWARE.
///
///                                James Card
///                         http://www.jamescard.org
///
///////////////////////////////////////////////////////////////////////////////

#ifndef ZIP_LIB_H
#define ZIP_LIB_H


#include "miniz.h"
#include "TypeDefinitions.h"
#include "CThreads.h"
#include "StringLib.h"
#include "HashTable.h"


#ifdef __cplusplus
extern "C"
{
#endif

// Constants.
#ifndef ZIP_DEFAULT_COMPRESSION_LEVEL
// Always use level 9 by default.  There really should be no reason
// to change this.
#define ZIP_DEFAULT_COMPRESSION_LEVEL 9
#endif // ZIP_DEFAULT_COMPRESSION_LEVEL


// Functionality for data in memory.

/// @struct CompressedData
///
/// @brief Data structure to represent the information needed to decompress
/// in-memory data.
///
/// @param data The compressed data.
/// @param dataLength The length, in bytes, of the data member.
/// @param dataIsRaw If true, the data is not compressible and is in its
///   its original format.  It should not be run through the decompressor.
/// @param dataIsStatic If true, data is not malloced and cannot be freed.
typedef struct CompressedData {
  void *data;
  i64   dataLength;
  bool  dataIsRaw;
  bool  dataIsStatic;
} CompressedData;

CompressedData* compressData(const volatile void *data, i64 dataLength);
void*           decompressData_(const CompressedData *compressedData, i64 *dataLength, ...);
#define decompressData(compressedData, ...) \
  decompressData_(compressedData, ##__VA_ARGS__, NULL)
Bytes           decompressDataToBytes(const CompressedData *compressedData);
i64             compressedDataGetLength(const CompressedData *compressedData);
void*           compressedDataGetData(const CompressedData *compressedData);
bool            compressedDataIsRaw(const CompressedData *compressedData);
CompressedData* compressedDataCreate(const volatile void *data, i64 dataLength,
  bool dataIsRaw, bool dataIsStatic);
CompressedData* compressedDataDestroy(CompressedData *compressedData);
Bytes           compressedDataToBlob(const CompressedData *compressedData);
CompressedData* compressedDataFromBlob(const volatile void *array, i64 *length);


// Formal zip functionality.

/// @enum ZipMode
///
/// @brief The mode of a Zip archive.
///
/// @details
/// The miniz library only allows the mz_zip_archive to be in one state (read or
/// write) at a time.  This enum allows us to keep track of the state so that we
/// can transparently switch states as needed under the covers.
///
/// @param ZIP_MODE_NOT_OPEN The archive is not opened.
/// @param ZIP_MODE_READ The archive is opened for reading.
/// @param ZIP_MODE_WRITE The archive is opened for writing.
/// @param NUM_ZIP_MODES The number of modes in this enum.
typedef enum ZipMode {
  ZIP_MODE_NOT_OPEN,
  ZIP_MODE_READ,
  ZIP_MODE_WRITE,
  NUM_ZIP_MODES
} ZipMode;

/// @enum ZipLocation
///
/// @brief The location of a Zip archive.
///
/// @details
/// The miniz library has different calls for an archive that's in memory than
/// for an archive that's in a file on disk.  We want to abstract all that, so
/// we have to keep track of the location of our data in our own object.
///
/// @param ZIP_LOCATION_NONE There is no data associated with this archive.
/// @param ZIP_LOCATION_MEMORY The data for the archive is in memory (at the
///   data member of the Zip object below).
/// @param ZIP_LOCATION_FILE The data for the archive is on disk.
/// @param NUM_ZIP_LOCATIONS The number of locations in this enum.
typedef enum ZipLocation {
  ZIP_LOCATION_NONE,
  ZIP_LOCATION_MEMORY,
  ZIP_LOCATION_FILE,
  NUM_ZIP_LOCATIONS
} ZipLocation;

/// @struct Zip
///
/// @brief Data structure to represent the information to operate on a
/// zip archive.
///
/// @param data A pointer to the in-memory data for the archive, if any.
/// @param dataLength The length, in bytes, of the data parameter.
/// @param archive The underlying mz_zip_archive required by miniz.
/// @param fileName The full file name of the archive on disk, if any.
/// @param zipMode The ZipMode for the archive.
/// @param zipLocation The ZipLocation for the archive.
/// @param numEntries The number of entries in the archive.
/// @param entryNames The names of the entries in the archive, if any.
/// @param entrySizes The sizes, in bytes, of the entries in the archive.
/// @param lock A mtx_t that guards access.
/// @param leaseData Whether or not the data is leased (not owned).
typedef struct Zip {
  // These first two entries need to come first and in this order to be
  // compatible with CompressedData.
  void            *data;
  i64              dataLength;
  mz_zip_archive  *archive;
  char            *fileName;
  ZipMode          zipMode;
  ZipLocation      zipLocation;
  i64              numEntries;
  char           **entryNames;
  i64             *entrySizes;
  mtx_t           lock;
  bool            leaseData;
} Zip;

// Constructors/Destructors.
Zip*   zipCreate();
Zip*   zipOpenFile(const char *fileName);
Zip*   zipOpenMemory_(const volatile void *memoryPointer, i64 memoryLength,
  const char *fileName, bool leaseData, ...);
#define zipOpenMemory(memoryPointer, memoryLength, ...) \
  zipOpenMemory_(memoryPointer, memoryLength, ##__VA_ARGS__, 0, 0)
i32    zipClose(Zip *zip);
i32    zipFlush_(Zip *zip, const char *fileName, ...);
#define zipFlush(zip, ...) zipFlush_(zip, ##__VA_ARGS__, NULL)
Zip*   zipDestroy(Zip *zip);

// Housekeeping.
i32 zipLock(Zip *zip);
i32 zipUnlock(Zip *zip);
i32 zipSetFileName(Zip *zip, const char *fileName);
const char* zipGetFileName(const Zip *zip);
i64 zipGetLength(const Zip *zip);
const void* zipGetData(const Zip *zip);
void* zipDetachData(Zip *zip);

// Entry-based access.
void*        zipReadEntryByName(const Zip *zip, const char *entryName,
  i64 *entryLength);
void*        zipReadEntryByIndex(const Zip *zip, i64 entryIndex, i64 *entryLength);
i32          zipAddEntry_(Zip *zip, const char *entryName,
  const volatile void *data, i64 dataLength, int level, ...);
#define zipAddEntry(zip, entryName, data, dataLength, ...) \
  zipAddEntry_(zip, entryName, data, dataLength, ##__VA_ARGS__, \
    ZIP_DEFAULT_COMPRESSION_LEVEL)
i64          zipGetNumEntries(Zip *zip);
const char** zipGetEntryNames(Zip *zip);
const char*  zipGetEntryName(Zip *zip, i64 index);
const i64*   zipGetEntrySizes(Zip *zip);
i64          zipGetEntrySize(Zip *zip, i64 index);
bool         zipHasEntry(Zip *zip, const char *entryName);


// Unit tests.
bool compressedDataUnitTest();
bool zipUnitTest();


#ifdef __cplusplus
} // extern "C"
#endif

#endif // ZIP_LIB_H

