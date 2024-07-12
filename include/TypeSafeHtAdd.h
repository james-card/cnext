///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              04.21.2024
///
/// @file              TypeSafeHtAdd.h
///
/// @brief             This header contains type-safe versions of the
///                    htAdd function.
///
/// @copyright
///                   Copyright (c) 2012-2024 James Card
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


#ifndef TYPE_SAFE_HT_ADD_H
#define TYPE_SAFE_HT_ADD_H

#include "DataTypes.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Type-safe inline functions.

static inline HashTableNode* htAddBoolBool(HashTable *dataStructure, bool key, bool value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeBool);
}
static inline HashTableNode* htAddBoolBoolP(HashTable *dataStructure, bool key, const volatile bool* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddBoolPBool(HashTable *dataStructure, const volatile bool* key, bool value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddBoolPBoolP(HashTable *dataStructure, const volatile bool* key, const volatile bool* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddBoolI16(HashTable *dataStructure, bool key, i16 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI16);
}
static inline HashTableNode* htAddBoolI16P(HashTable *dataStructure, bool key, const volatile i16* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddBoolPI16(HashTable *dataStructure, const volatile bool* key, i16 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddBoolPI16P(HashTable *dataStructure, const volatile bool* key, const volatile i16* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddBoolU16(HashTable *dataStructure, bool key, u16 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU16);
}
static inline HashTableNode* htAddBoolU16P(HashTable *dataStructure, bool key, const volatile u16* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddBoolPU16(HashTable *dataStructure, const volatile bool* key, u16 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddBoolPU16P(HashTable *dataStructure, const volatile bool* key, const volatile u16* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddBoolI32(HashTable *dataStructure, bool key, i32 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI32);
}
static inline HashTableNode* htAddBoolI32P(HashTable *dataStructure, bool key, const volatile i32* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddBoolPI32(HashTable *dataStructure, const volatile bool* key, i32 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddBoolPI32P(HashTable *dataStructure, const volatile bool* key, const volatile i32* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddBoolU32(HashTable *dataStructure, bool key, u32 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU32);
}
static inline HashTableNode* htAddBoolU32P(HashTable *dataStructure, bool key, const volatile u32* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddBoolPU32(HashTable *dataStructure, const volatile bool* key, u32 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddBoolPU32P(HashTable *dataStructure, const volatile bool* key, const volatile u32* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddBoolI64(HashTable *dataStructure, bool key, i64 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI64);
}
static inline HashTableNode* htAddBoolI64P(HashTable *dataStructure, bool key, const volatile i64* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddBoolPI64(HashTable *dataStructure, const volatile bool* key, i64 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddBoolPI64P(HashTable *dataStructure, const volatile bool* key, const volatile i64* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddBoolU64(HashTable *dataStructure, bool key, u64 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU64);
}
static inline HashTableNode* htAddBoolU64P(HashTable *dataStructure, bool key, const volatile u64* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddBoolPU64(HashTable *dataStructure, const volatile bool* key, u64 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddBoolPU64P(HashTable *dataStructure, const volatile bool* key, const volatile u64* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddBoolFloat(HashTable *dataStructure, bool key, float value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline HashTableNode* htAddBoolFloatP(HashTable *dataStructure, bool key, const volatile float* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddBoolPFloat(HashTable *dataStructure, const volatile bool* key, float value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddBoolPFloatP(HashTable *dataStructure, const volatile bool* key, const volatile float* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddBoolDouble(HashTable *dataStructure, bool key, double value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline HashTableNode* htAddBoolDoubleP(HashTable *dataStructure, bool key, const volatile double* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddBoolPDouble(HashTable *dataStructure, const volatile bool* key, double value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddBoolPDoubleP(HashTable *dataStructure, const volatile bool* key, const volatile double* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddBoolLongDouble(HashTable *dataStructure, bool key, long double value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline HashTableNode* htAddBoolLongDoubleP(HashTable *dataStructure, bool key, const volatile long double* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddBoolPLongDouble(HashTable *dataStructure, const volatile bool* key, long double value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddBoolPLongDoubleP(HashTable *dataStructure, const volatile bool* key, const volatile long double* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddBoolList(HashTable *dataStructure, bool key, List value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeList);
}
static inline HashTableNode* htAddBoolListP(HashTable *dataStructure, bool key, const volatile List* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline HashTableNode* htAddBoolPList(HashTable *dataStructure, const volatile bool* key, List value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddBoolPListP(HashTable *dataStructure, const volatile bool* key, const volatile List* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddBoolQueue(HashTable *dataStructure, bool key, Queue value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline HashTableNode* htAddBoolQueueP(HashTable *dataStructure, bool key, const volatile Queue* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddBoolPQueue(HashTable *dataStructure, const volatile bool* key, Queue value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddBoolPQueueP(HashTable *dataStructure, const volatile bool* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddBoolStack(HashTable *dataStructure, bool key, Stack value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeStack);
}
static inline HashTableNode* htAddBoolStackP(HashTable *dataStructure, bool key, const volatile Stack* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddBoolPStack(HashTable *dataStructure, const volatile bool* key, Stack value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddBoolPStackP(HashTable *dataStructure, const volatile bool* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddBoolRedBlackTree(HashTable *dataStructure, bool key, RedBlackTree value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddBoolRedBlackTreeP(HashTable *dataStructure, bool key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddBoolPRedBlackTree(HashTable *dataStructure, const volatile bool* key, RedBlackTree value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddBoolPRedBlackTreeP(HashTable *dataStructure, const volatile bool* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddBoolHashTable(HashTable *dataStructure, bool key, HashTable value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline HashTableNode* htAddBoolHashTableP(HashTable *dataStructure, bool key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddBoolPHashTable(HashTable *dataStructure, const volatile bool* key, HashTable value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddBoolPHashTableP(HashTable *dataStructure, const volatile bool* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddBoolVector(HashTable *dataStructure, bool key, Vector value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeVector);
}
static inline HashTableNode* htAddBoolVectorP(HashTable *dataStructure, bool key, const volatile Vector* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddBoolPVector(HashTable *dataStructure, const volatile bool* key, Vector value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddBoolPVectorP(HashTable *dataStructure, const volatile bool* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddBoolString(HashTable *dataStructure, bool key, const volatile char* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeString);
}
static inline HashTableNode* htAddBoolStringP(HashTable *dataStructure, bool key, const volatile char** value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddBoolPString(HashTable *dataStructure, const volatile bool* key, const volatile char* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddBoolPStringP(HashTable *dataStructure, const volatile bool* key, const volatile char** value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddBoolBytes(HashTable *dataStructure, bool key, Bytes value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBytes);
}
static inline HashTableNode* htAddBoolBytesP(HashTable *dataStructure, bool key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddBoolPBytes(HashTable *dataStructure, const volatile bool* key, Bytes value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddBoolPBytesP(HashTable *dataStructure, const volatile bool* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddBoolPointer(HashTable *dataStructure, bool key, void* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typePointer);
}
static inline HashTableNode* htAddBoolPointerP(HashTable *dataStructure, bool key, const volatile void** value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddBoolPPointer(HashTable *dataStructure, const volatile bool* key, void* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddBoolPPointerP(HashTable *dataStructure, const volatile bool* key, const volatile void** value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddBoolI8(HashTable *dataStructure, bool key, i8 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI8);
}
static inline HashTableNode* htAddBoolPI8(HashTable *dataStructure, const volatile bool* key, i8 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddBoolU8(HashTable *dataStructure, bool key, u8 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU8);
}
static inline HashTableNode* htAddBoolPU8(HashTable *dataStructure, const volatile bool* key, u8 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}
static inline HashTableNode* htAddI16Bool(HashTable *dataStructure, i16 key, bool value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeBool);
}
static inline HashTableNode* htAddI16BoolP(HashTable *dataStructure, i16 key, const volatile bool* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddI16PBool(HashTable *dataStructure, const volatile i16* key, bool value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddI16PBoolP(HashTable *dataStructure, const volatile i16* key, const volatile bool* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddI16I16(HashTable *dataStructure, i16 key, i16 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI16);
}
static inline HashTableNode* htAddI16I16P(HashTable *dataStructure, i16 key, const volatile i16* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddI16PI16(HashTable *dataStructure, const volatile i16* key, i16 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddI16PI16P(HashTable *dataStructure, const volatile i16* key, const volatile i16* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddI16U16(HashTable *dataStructure, i16 key, u16 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU16);
}
static inline HashTableNode* htAddI16U16P(HashTable *dataStructure, i16 key, const volatile u16* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddI16PU16(HashTable *dataStructure, const volatile i16* key, u16 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddI16PU16P(HashTable *dataStructure, const volatile i16* key, const volatile u16* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddI16I32(HashTable *dataStructure, i16 key, i32 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI32);
}
static inline HashTableNode* htAddI16I32P(HashTable *dataStructure, i16 key, const volatile i32* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddI16PI32(HashTable *dataStructure, const volatile i16* key, i32 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddI16PI32P(HashTable *dataStructure, const volatile i16* key, const volatile i32* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddI16U32(HashTable *dataStructure, i16 key, u32 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU32);
}
static inline HashTableNode* htAddI16U32P(HashTable *dataStructure, i16 key, const volatile u32* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddI16PU32(HashTable *dataStructure, const volatile i16* key, u32 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddI16PU32P(HashTable *dataStructure, const volatile i16* key, const volatile u32* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddI16I64(HashTable *dataStructure, i16 key, i64 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI64);
}
static inline HashTableNode* htAddI16I64P(HashTable *dataStructure, i16 key, const volatile i64* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddI16PI64(HashTable *dataStructure, const volatile i16* key, i64 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddI16PI64P(HashTable *dataStructure, const volatile i16* key, const volatile i64* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddI16U64(HashTable *dataStructure, i16 key, u64 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU64);
}
static inline HashTableNode* htAddI16U64P(HashTable *dataStructure, i16 key, const volatile u64* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddI16PU64(HashTable *dataStructure, const volatile i16* key, u64 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddI16PU64P(HashTable *dataStructure, const volatile i16* key, const volatile u64* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddI16Float(HashTable *dataStructure, i16 key, float value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline HashTableNode* htAddI16FloatP(HashTable *dataStructure, i16 key, const volatile float* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddI16PFloat(HashTable *dataStructure, const volatile i16* key, float value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddI16PFloatP(HashTable *dataStructure, const volatile i16* key, const volatile float* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddI16Double(HashTable *dataStructure, i16 key, double value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline HashTableNode* htAddI16DoubleP(HashTable *dataStructure, i16 key, const volatile double* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddI16PDouble(HashTable *dataStructure, const volatile i16* key, double value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddI16PDoubleP(HashTable *dataStructure, const volatile i16* key, const volatile double* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddI16LongDouble(HashTable *dataStructure, i16 key, long double value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline HashTableNode* htAddI16LongDoubleP(HashTable *dataStructure, i16 key, const volatile long double* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddI16PLongDouble(HashTable *dataStructure, const volatile i16* key, long double value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddI16PLongDoubleP(HashTable *dataStructure, const volatile i16* key, const volatile long double* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddI16List(HashTable *dataStructure, i16 key, List value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeList);
}
static inline HashTableNode* htAddI16ListP(HashTable *dataStructure, i16 key, const volatile List* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline HashTableNode* htAddI16PList(HashTable *dataStructure, const volatile i16* key, List value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddI16PListP(HashTable *dataStructure, const volatile i16* key, const volatile List* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddI16Queue(HashTable *dataStructure, i16 key, Queue value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline HashTableNode* htAddI16QueueP(HashTable *dataStructure, i16 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddI16PQueue(HashTable *dataStructure, const volatile i16* key, Queue value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddI16PQueueP(HashTable *dataStructure, const volatile i16* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddI16Stack(HashTable *dataStructure, i16 key, Stack value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeStack);
}
static inline HashTableNode* htAddI16StackP(HashTable *dataStructure, i16 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddI16PStack(HashTable *dataStructure, const volatile i16* key, Stack value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddI16PStackP(HashTable *dataStructure, const volatile i16* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddI16RedBlackTree(HashTable *dataStructure, i16 key, RedBlackTree value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddI16RedBlackTreeP(HashTable *dataStructure, i16 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddI16PRedBlackTree(HashTable *dataStructure, const volatile i16* key, RedBlackTree value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddI16PRedBlackTreeP(HashTable *dataStructure, const volatile i16* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddI16HashTable(HashTable *dataStructure, i16 key, HashTable value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline HashTableNode* htAddI16HashTableP(HashTable *dataStructure, i16 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddI16PHashTable(HashTable *dataStructure, const volatile i16* key, HashTable value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddI16PHashTableP(HashTable *dataStructure, const volatile i16* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddI16Vector(HashTable *dataStructure, i16 key, Vector value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeVector);
}
static inline HashTableNode* htAddI16VectorP(HashTable *dataStructure, i16 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddI16PVector(HashTable *dataStructure, const volatile i16* key, Vector value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddI16PVectorP(HashTable *dataStructure, const volatile i16* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddI16String(HashTable *dataStructure, i16 key, const volatile char* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeString);
}
static inline HashTableNode* htAddI16StringP(HashTable *dataStructure, i16 key, const volatile char** value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddI16PString(HashTable *dataStructure, const volatile i16* key, const volatile char* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddI16PStringP(HashTable *dataStructure, const volatile i16* key, const volatile char** value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddI16Bytes(HashTable *dataStructure, i16 key, Bytes value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBytes);
}
static inline HashTableNode* htAddI16BytesP(HashTable *dataStructure, i16 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddI16PBytes(HashTable *dataStructure, const volatile i16* key, Bytes value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddI16PBytesP(HashTable *dataStructure, const volatile i16* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddI16Pointer(HashTable *dataStructure, i16 key, void* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typePointer);
}
static inline HashTableNode* htAddI16PointerP(HashTable *dataStructure, i16 key, const volatile void** value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddI16PPointer(HashTable *dataStructure, const volatile i16* key, void* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddI16PPointerP(HashTable *dataStructure, const volatile i16* key, const volatile void** value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddI16I8(HashTable *dataStructure, i16 key, i8 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI8);
}
static inline HashTableNode* htAddI16PI8(HashTable *dataStructure, const volatile i16* key, i8 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddI16U8(HashTable *dataStructure, i16 key, u8 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU8);
}
static inline HashTableNode* htAddI16PU8(HashTable *dataStructure, const volatile i16* key, u8 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}
static inline HashTableNode* htAddU16Bool(HashTable *dataStructure, u16 key, bool value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeBool);
}
static inline HashTableNode* htAddU16BoolP(HashTable *dataStructure, u16 key, const volatile bool* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddU16PBool(HashTable *dataStructure, const volatile u16* key, bool value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddU16PBoolP(HashTable *dataStructure, const volatile u16* key, const volatile bool* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddU16I16(HashTable *dataStructure, u16 key, i16 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI16);
}
static inline HashTableNode* htAddU16I16P(HashTable *dataStructure, u16 key, const volatile i16* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddU16PI16(HashTable *dataStructure, const volatile u16* key, i16 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddU16PI16P(HashTable *dataStructure, const volatile u16* key, const volatile i16* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddU16U16(HashTable *dataStructure, u16 key, u16 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU16);
}
static inline HashTableNode* htAddU16U16P(HashTable *dataStructure, u16 key, const volatile u16* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddU16PU16(HashTable *dataStructure, const volatile u16* key, u16 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddU16PU16P(HashTable *dataStructure, const volatile u16* key, const volatile u16* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddU16I32(HashTable *dataStructure, u16 key, i32 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI32);
}
static inline HashTableNode* htAddU16I32P(HashTable *dataStructure, u16 key, const volatile i32* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddU16PI32(HashTable *dataStructure, const volatile u16* key, i32 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddU16PI32P(HashTable *dataStructure, const volatile u16* key, const volatile i32* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddU16U32(HashTable *dataStructure, u16 key, u32 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU32);
}
static inline HashTableNode* htAddU16U32P(HashTable *dataStructure, u16 key, const volatile u32* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddU16PU32(HashTable *dataStructure, const volatile u16* key, u32 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddU16PU32P(HashTable *dataStructure, const volatile u16* key, const volatile u32* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddU16I64(HashTable *dataStructure, u16 key, i64 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI64);
}
static inline HashTableNode* htAddU16I64P(HashTable *dataStructure, u16 key, const volatile i64* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddU16PI64(HashTable *dataStructure, const volatile u16* key, i64 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddU16PI64P(HashTable *dataStructure, const volatile u16* key, const volatile i64* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddU16U64(HashTable *dataStructure, u16 key, u64 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU64);
}
static inline HashTableNode* htAddU16U64P(HashTable *dataStructure, u16 key, const volatile u64* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddU16PU64(HashTable *dataStructure, const volatile u16* key, u64 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddU16PU64P(HashTable *dataStructure, const volatile u16* key, const volatile u64* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddU16Float(HashTable *dataStructure, u16 key, float value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline HashTableNode* htAddU16FloatP(HashTable *dataStructure, u16 key, const volatile float* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddU16PFloat(HashTable *dataStructure, const volatile u16* key, float value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddU16PFloatP(HashTable *dataStructure, const volatile u16* key, const volatile float* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddU16Double(HashTable *dataStructure, u16 key, double value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline HashTableNode* htAddU16DoubleP(HashTable *dataStructure, u16 key, const volatile double* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddU16PDouble(HashTable *dataStructure, const volatile u16* key, double value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddU16PDoubleP(HashTable *dataStructure, const volatile u16* key, const volatile double* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddU16LongDouble(HashTable *dataStructure, u16 key, long double value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline HashTableNode* htAddU16LongDoubleP(HashTable *dataStructure, u16 key, const volatile long double* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddU16PLongDouble(HashTable *dataStructure, const volatile u16* key, long double value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddU16PLongDoubleP(HashTable *dataStructure, const volatile u16* key, const volatile long double* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddU16List(HashTable *dataStructure, u16 key, List value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeList);
}
static inline HashTableNode* htAddU16ListP(HashTable *dataStructure, u16 key, const volatile List* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline HashTableNode* htAddU16PList(HashTable *dataStructure, const volatile u16* key, List value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddU16PListP(HashTable *dataStructure, const volatile u16* key, const volatile List* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddU16Queue(HashTable *dataStructure, u16 key, Queue value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline HashTableNode* htAddU16QueueP(HashTable *dataStructure, u16 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddU16PQueue(HashTable *dataStructure, const volatile u16* key, Queue value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddU16PQueueP(HashTable *dataStructure, const volatile u16* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddU16Stack(HashTable *dataStructure, u16 key, Stack value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeStack);
}
static inline HashTableNode* htAddU16StackP(HashTable *dataStructure, u16 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddU16PStack(HashTable *dataStructure, const volatile u16* key, Stack value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddU16PStackP(HashTable *dataStructure, const volatile u16* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddU16RedBlackTree(HashTable *dataStructure, u16 key, RedBlackTree value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddU16RedBlackTreeP(HashTable *dataStructure, u16 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddU16PRedBlackTree(HashTable *dataStructure, const volatile u16* key, RedBlackTree value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddU16PRedBlackTreeP(HashTable *dataStructure, const volatile u16* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddU16HashTable(HashTable *dataStructure, u16 key, HashTable value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline HashTableNode* htAddU16HashTableP(HashTable *dataStructure, u16 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddU16PHashTable(HashTable *dataStructure, const volatile u16* key, HashTable value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddU16PHashTableP(HashTable *dataStructure, const volatile u16* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddU16Vector(HashTable *dataStructure, u16 key, Vector value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeVector);
}
static inline HashTableNode* htAddU16VectorP(HashTable *dataStructure, u16 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddU16PVector(HashTable *dataStructure, const volatile u16* key, Vector value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddU16PVectorP(HashTable *dataStructure, const volatile u16* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddU16String(HashTable *dataStructure, u16 key, const volatile char* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeString);
}
static inline HashTableNode* htAddU16StringP(HashTable *dataStructure, u16 key, const volatile char** value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddU16PString(HashTable *dataStructure, const volatile u16* key, const volatile char* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddU16PStringP(HashTable *dataStructure, const volatile u16* key, const volatile char** value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddU16Bytes(HashTable *dataStructure, u16 key, Bytes value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBytes);
}
static inline HashTableNode* htAddU16BytesP(HashTable *dataStructure, u16 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddU16PBytes(HashTable *dataStructure, const volatile u16* key, Bytes value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddU16PBytesP(HashTable *dataStructure, const volatile u16* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddU16Pointer(HashTable *dataStructure, u16 key, void* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typePointer);
}
static inline HashTableNode* htAddU16PointerP(HashTable *dataStructure, u16 key, const volatile void** value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddU16PPointer(HashTable *dataStructure, const volatile u16* key, void* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddU16PPointerP(HashTable *dataStructure, const volatile u16* key, const volatile void** value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddU16I8(HashTable *dataStructure, u16 key, i8 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI8);
}
static inline HashTableNode* htAddU16PI8(HashTable *dataStructure, const volatile u16* key, i8 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddU16U8(HashTable *dataStructure, u16 key, u8 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU8);
}
static inline HashTableNode* htAddU16PU8(HashTable *dataStructure, const volatile u16* key, u8 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}
static inline HashTableNode* htAddI32Bool(HashTable *dataStructure, i32 key, bool value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeBool);
}
static inline HashTableNode* htAddI32BoolP(HashTable *dataStructure, i32 key, const volatile bool* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddI32PBool(HashTable *dataStructure, const volatile i32* key, bool value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddI32PBoolP(HashTable *dataStructure, const volatile i32* key, const volatile bool* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddI32I16(HashTable *dataStructure, i32 key, i16 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI16);
}
static inline HashTableNode* htAddI32I16P(HashTable *dataStructure, i32 key, const volatile i16* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddI32PI16(HashTable *dataStructure, const volatile i32* key, i16 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddI32PI16P(HashTable *dataStructure, const volatile i32* key, const volatile i16* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddI32U16(HashTable *dataStructure, i32 key, u16 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU16);
}
static inline HashTableNode* htAddI32U16P(HashTable *dataStructure, i32 key, const volatile u16* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddI32PU16(HashTable *dataStructure, const volatile i32* key, u16 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddI32PU16P(HashTable *dataStructure, const volatile i32* key, const volatile u16* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddI32I32(HashTable *dataStructure, i32 key, i32 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI32);
}
static inline HashTableNode* htAddI32I32P(HashTable *dataStructure, i32 key, const volatile i32* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddI32PI32(HashTable *dataStructure, const volatile i32* key, i32 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddI32PI32P(HashTable *dataStructure, const volatile i32* key, const volatile i32* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddI32U32(HashTable *dataStructure, i32 key, u32 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU32);
}
static inline HashTableNode* htAddI32U32P(HashTable *dataStructure, i32 key, const volatile u32* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddI32PU32(HashTable *dataStructure, const volatile i32* key, u32 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddI32PU32P(HashTable *dataStructure, const volatile i32* key, const volatile u32* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddI32I64(HashTable *dataStructure, i32 key, i64 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI64);
}
static inline HashTableNode* htAddI32I64P(HashTable *dataStructure, i32 key, const volatile i64* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddI32PI64(HashTable *dataStructure, const volatile i32* key, i64 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddI32PI64P(HashTable *dataStructure, const volatile i32* key, const volatile i64* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddI32U64(HashTable *dataStructure, i32 key, u64 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU64);
}
static inline HashTableNode* htAddI32U64P(HashTable *dataStructure, i32 key, const volatile u64* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddI32PU64(HashTable *dataStructure, const volatile i32* key, u64 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddI32PU64P(HashTable *dataStructure, const volatile i32* key, const volatile u64* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddI32Float(HashTable *dataStructure, i32 key, float value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline HashTableNode* htAddI32FloatP(HashTable *dataStructure, i32 key, const volatile float* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddI32PFloat(HashTable *dataStructure, const volatile i32* key, float value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddI32PFloatP(HashTable *dataStructure, const volatile i32* key, const volatile float* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddI32Double(HashTable *dataStructure, i32 key, double value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline HashTableNode* htAddI32DoubleP(HashTable *dataStructure, i32 key, const volatile double* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddI32PDouble(HashTable *dataStructure, const volatile i32* key, double value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddI32PDoubleP(HashTable *dataStructure, const volatile i32* key, const volatile double* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddI32LongDouble(HashTable *dataStructure, i32 key, long double value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline HashTableNode* htAddI32LongDoubleP(HashTable *dataStructure, i32 key, const volatile long double* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddI32PLongDouble(HashTable *dataStructure, const volatile i32* key, long double value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddI32PLongDoubleP(HashTable *dataStructure, const volatile i32* key, const volatile long double* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddI32List(HashTable *dataStructure, i32 key, List value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeList);
}
static inline HashTableNode* htAddI32ListP(HashTable *dataStructure, i32 key, const volatile List* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline HashTableNode* htAddI32PList(HashTable *dataStructure, const volatile i32* key, List value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddI32PListP(HashTable *dataStructure, const volatile i32* key, const volatile List* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddI32Queue(HashTable *dataStructure, i32 key, Queue value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline HashTableNode* htAddI32QueueP(HashTable *dataStructure, i32 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddI32PQueue(HashTable *dataStructure, const volatile i32* key, Queue value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddI32PQueueP(HashTable *dataStructure, const volatile i32* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddI32Stack(HashTable *dataStructure, i32 key, Stack value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeStack);
}
static inline HashTableNode* htAddI32StackP(HashTable *dataStructure, i32 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddI32PStack(HashTable *dataStructure, const volatile i32* key, Stack value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddI32PStackP(HashTable *dataStructure, const volatile i32* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddI32RedBlackTree(HashTable *dataStructure, i32 key, RedBlackTree value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddI32RedBlackTreeP(HashTable *dataStructure, i32 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddI32PRedBlackTree(HashTable *dataStructure, const volatile i32* key, RedBlackTree value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddI32PRedBlackTreeP(HashTable *dataStructure, const volatile i32* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddI32HashTable(HashTable *dataStructure, i32 key, HashTable value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline HashTableNode* htAddI32HashTableP(HashTable *dataStructure, i32 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddI32PHashTable(HashTable *dataStructure, const volatile i32* key, HashTable value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddI32PHashTableP(HashTable *dataStructure, const volatile i32* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddI32Vector(HashTable *dataStructure, i32 key, Vector value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeVector);
}
static inline HashTableNode* htAddI32VectorP(HashTable *dataStructure, i32 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddI32PVector(HashTable *dataStructure, const volatile i32* key, Vector value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddI32PVectorP(HashTable *dataStructure, const volatile i32* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddI32String(HashTable *dataStructure, i32 key, const volatile char* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeString);
}
static inline HashTableNode* htAddI32StringP(HashTable *dataStructure, i32 key, const volatile char** value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddI32PString(HashTable *dataStructure, const volatile i32* key, const volatile char* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddI32PStringP(HashTable *dataStructure, const volatile i32* key, const volatile char** value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddI32Bytes(HashTable *dataStructure, i32 key, Bytes value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBytes);
}
static inline HashTableNode* htAddI32BytesP(HashTable *dataStructure, i32 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddI32PBytes(HashTable *dataStructure, const volatile i32* key, Bytes value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddI32PBytesP(HashTable *dataStructure, const volatile i32* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddI32Pointer(HashTable *dataStructure, i32 key, void* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typePointer);
}
static inline HashTableNode* htAddI32PointerP(HashTable *dataStructure, i32 key, const volatile void** value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddI32PPointer(HashTable *dataStructure, const volatile i32* key, void* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddI32PPointerP(HashTable *dataStructure, const volatile i32* key, const volatile void** value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddI32I8(HashTable *dataStructure, i32 key, i8 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI8);
}
static inline HashTableNode* htAddI32PI8(HashTable *dataStructure, const volatile i32* key, i8 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddI32U8(HashTable *dataStructure, i32 key, u8 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU8);
}
static inline HashTableNode* htAddI32PU8(HashTable *dataStructure, const volatile i32* key, u8 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}
static inline HashTableNode* htAddU32Bool(HashTable *dataStructure, u32 key, bool value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeBool);
}
static inline HashTableNode* htAddU32BoolP(HashTable *dataStructure, u32 key, const volatile bool* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddU32PBool(HashTable *dataStructure, const volatile u32* key, bool value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddU32PBoolP(HashTable *dataStructure, const volatile u32* key, const volatile bool* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddU32I16(HashTable *dataStructure, u32 key, i16 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI16);
}
static inline HashTableNode* htAddU32I16P(HashTable *dataStructure, u32 key, const volatile i16* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddU32PI16(HashTable *dataStructure, const volatile u32* key, i16 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddU32PI16P(HashTable *dataStructure, const volatile u32* key, const volatile i16* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddU32U16(HashTable *dataStructure, u32 key, u16 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU16);
}
static inline HashTableNode* htAddU32U16P(HashTable *dataStructure, u32 key, const volatile u16* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddU32PU16(HashTable *dataStructure, const volatile u32* key, u16 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddU32PU16P(HashTable *dataStructure, const volatile u32* key, const volatile u16* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddU32I32(HashTable *dataStructure, u32 key, i32 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI32);
}
static inline HashTableNode* htAddU32I32P(HashTable *dataStructure, u32 key, const volatile i32* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddU32PI32(HashTable *dataStructure, const volatile u32* key, i32 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddU32PI32P(HashTable *dataStructure, const volatile u32* key, const volatile i32* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddU32U32(HashTable *dataStructure, u32 key, u32 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU32);
}
static inline HashTableNode* htAddU32U32P(HashTable *dataStructure, u32 key, const volatile u32* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddU32PU32(HashTable *dataStructure, const volatile u32* key, u32 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddU32PU32P(HashTable *dataStructure, const volatile u32* key, const volatile u32* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddU32I64(HashTable *dataStructure, u32 key, i64 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI64);
}
static inline HashTableNode* htAddU32I64P(HashTable *dataStructure, u32 key, const volatile i64* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddU32PI64(HashTable *dataStructure, const volatile u32* key, i64 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddU32PI64P(HashTable *dataStructure, const volatile u32* key, const volatile i64* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddU32U64(HashTable *dataStructure, u32 key, u64 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU64);
}
static inline HashTableNode* htAddU32U64P(HashTable *dataStructure, u32 key, const volatile u64* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddU32PU64(HashTable *dataStructure, const volatile u32* key, u64 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddU32PU64P(HashTable *dataStructure, const volatile u32* key, const volatile u64* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddU32Float(HashTable *dataStructure, u32 key, float value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline HashTableNode* htAddU32FloatP(HashTable *dataStructure, u32 key, const volatile float* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddU32PFloat(HashTable *dataStructure, const volatile u32* key, float value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddU32PFloatP(HashTable *dataStructure, const volatile u32* key, const volatile float* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddU32Double(HashTable *dataStructure, u32 key, double value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline HashTableNode* htAddU32DoubleP(HashTable *dataStructure, u32 key, const volatile double* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddU32PDouble(HashTable *dataStructure, const volatile u32* key, double value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddU32PDoubleP(HashTable *dataStructure, const volatile u32* key, const volatile double* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddU32LongDouble(HashTable *dataStructure, u32 key, long double value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline HashTableNode* htAddU32LongDoubleP(HashTable *dataStructure, u32 key, const volatile long double* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddU32PLongDouble(HashTable *dataStructure, const volatile u32* key, long double value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddU32PLongDoubleP(HashTable *dataStructure, const volatile u32* key, const volatile long double* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddU32List(HashTable *dataStructure, u32 key, List value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeList);
}
static inline HashTableNode* htAddU32ListP(HashTable *dataStructure, u32 key, const volatile List* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline HashTableNode* htAddU32PList(HashTable *dataStructure, const volatile u32* key, List value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddU32PListP(HashTable *dataStructure, const volatile u32* key, const volatile List* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddU32Queue(HashTable *dataStructure, u32 key, Queue value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline HashTableNode* htAddU32QueueP(HashTable *dataStructure, u32 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddU32PQueue(HashTable *dataStructure, const volatile u32* key, Queue value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddU32PQueueP(HashTable *dataStructure, const volatile u32* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddU32Stack(HashTable *dataStructure, u32 key, Stack value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeStack);
}
static inline HashTableNode* htAddU32StackP(HashTable *dataStructure, u32 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddU32PStack(HashTable *dataStructure, const volatile u32* key, Stack value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddU32PStackP(HashTable *dataStructure, const volatile u32* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddU32RedBlackTree(HashTable *dataStructure, u32 key, RedBlackTree value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddU32RedBlackTreeP(HashTable *dataStructure, u32 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddU32PRedBlackTree(HashTable *dataStructure, const volatile u32* key, RedBlackTree value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddU32PRedBlackTreeP(HashTable *dataStructure, const volatile u32* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddU32HashTable(HashTable *dataStructure, u32 key, HashTable value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline HashTableNode* htAddU32HashTableP(HashTable *dataStructure, u32 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddU32PHashTable(HashTable *dataStructure, const volatile u32* key, HashTable value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddU32PHashTableP(HashTable *dataStructure, const volatile u32* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddU32Vector(HashTable *dataStructure, u32 key, Vector value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeVector);
}
static inline HashTableNode* htAddU32VectorP(HashTable *dataStructure, u32 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddU32PVector(HashTable *dataStructure, const volatile u32* key, Vector value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddU32PVectorP(HashTable *dataStructure, const volatile u32* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddU32String(HashTable *dataStructure, u32 key, const volatile char* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeString);
}
static inline HashTableNode* htAddU32StringP(HashTable *dataStructure, u32 key, const volatile char** value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddU32PString(HashTable *dataStructure, const volatile u32* key, const volatile char* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddU32PStringP(HashTable *dataStructure, const volatile u32* key, const volatile char** value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddU32Bytes(HashTable *dataStructure, u32 key, Bytes value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBytes);
}
static inline HashTableNode* htAddU32BytesP(HashTable *dataStructure, u32 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddU32PBytes(HashTable *dataStructure, const volatile u32* key, Bytes value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddU32PBytesP(HashTable *dataStructure, const volatile u32* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddU32Pointer(HashTable *dataStructure, u32 key, void* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typePointer);
}
static inline HashTableNode* htAddU32PointerP(HashTable *dataStructure, u32 key, const volatile void** value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddU32PPointer(HashTable *dataStructure, const volatile u32* key, void* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddU32PPointerP(HashTable *dataStructure, const volatile u32* key, const volatile void** value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddU32I8(HashTable *dataStructure, u32 key, i8 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI8);
}
static inline HashTableNode* htAddU32PI8(HashTable *dataStructure, const volatile u32* key, i8 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddU32U8(HashTable *dataStructure, u32 key, u8 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU8);
}
static inline HashTableNode* htAddU32PU8(HashTable *dataStructure, const volatile u32* key, u8 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}
static inline HashTableNode* htAddI64Bool(HashTable *dataStructure, i64 key, bool value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeBool);
}
static inline HashTableNode* htAddI64BoolP(HashTable *dataStructure, i64 key, const volatile bool* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddI64PBool(HashTable *dataStructure, const volatile i64* key, bool value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddI64PBoolP(HashTable *dataStructure, const volatile i64* key, const volatile bool* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddI64I16(HashTable *dataStructure, i64 key, i16 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI16);
}
static inline HashTableNode* htAddI64I16P(HashTable *dataStructure, i64 key, const volatile i16* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddI64PI16(HashTable *dataStructure, const volatile i64* key, i16 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddI64PI16P(HashTable *dataStructure, const volatile i64* key, const volatile i16* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddI64U16(HashTable *dataStructure, i64 key, u16 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU16);
}
static inline HashTableNode* htAddI64U16P(HashTable *dataStructure, i64 key, const volatile u16* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddI64PU16(HashTable *dataStructure, const volatile i64* key, u16 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddI64PU16P(HashTable *dataStructure, const volatile i64* key, const volatile u16* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddI64I32(HashTable *dataStructure, i64 key, i32 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI32);
}
static inline HashTableNode* htAddI64I32P(HashTable *dataStructure, i64 key, const volatile i32* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddI64PI32(HashTable *dataStructure, const volatile i64* key, i32 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddI64PI32P(HashTable *dataStructure, const volatile i64* key, const volatile i32* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddI64U32(HashTable *dataStructure, i64 key, u32 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU32);
}
static inline HashTableNode* htAddI64U32P(HashTable *dataStructure, i64 key, const volatile u32* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddI64PU32(HashTable *dataStructure, const volatile i64* key, u32 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddI64PU32P(HashTable *dataStructure, const volatile i64* key, const volatile u32* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddI64I64(HashTable *dataStructure, i64 key, i64 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI64);
}
static inline HashTableNode* htAddI64I64P(HashTable *dataStructure, i64 key, const volatile i64* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddI64PI64(HashTable *dataStructure, const volatile i64* key, i64 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddI64PI64P(HashTable *dataStructure, const volatile i64* key, const volatile i64* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddI64U64(HashTable *dataStructure, i64 key, u64 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU64);
}
static inline HashTableNode* htAddI64U64P(HashTable *dataStructure, i64 key, const volatile u64* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddI64PU64(HashTable *dataStructure, const volatile i64* key, u64 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddI64PU64P(HashTable *dataStructure, const volatile i64* key, const volatile u64* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddI64Float(HashTable *dataStructure, i64 key, float value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline HashTableNode* htAddI64FloatP(HashTable *dataStructure, i64 key, const volatile float* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddI64PFloat(HashTable *dataStructure, const volatile i64* key, float value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddI64PFloatP(HashTable *dataStructure, const volatile i64* key, const volatile float* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddI64Double(HashTable *dataStructure, i64 key, double value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline HashTableNode* htAddI64DoubleP(HashTable *dataStructure, i64 key, const volatile double* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddI64PDouble(HashTable *dataStructure, const volatile i64* key, double value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddI64PDoubleP(HashTable *dataStructure, const volatile i64* key, const volatile double* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddI64LongDouble(HashTable *dataStructure, i64 key, long double value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline HashTableNode* htAddI64LongDoubleP(HashTable *dataStructure, i64 key, const volatile long double* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddI64PLongDouble(HashTable *dataStructure, const volatile i64* key, long double value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddI64PLongDoubleP(HashTable *dataStructure, const volatile i64* key, const volatile long double* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddI64List(HashTable *dataStructure, i64 key, List value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeList);
}
static inline HashTableNode* htAddI64ListP(HashTable *dataStructure, i64 key, const volatile List* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline HashTableNode* htAddI64PList(HashTable *dataStructure, const volatile i64* key, List value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddI64PListP(HashTable *dataStructure, const volatile i64* key, const volatile List* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddI64Queue(HashTable *dataStructure, i64 key, Queue value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline HashTableNode* htAddI64QueueP(HashTable *dataStructure, i64 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddI64PQueue(HashTable *dataStructure, const volatile i64* key, Queue value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddI64PQueueP(HashTable *dataStructure, const volatile i64* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddI64Stack(HashTable *dataStructure, i64 key, Stack value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeStack);
}
static inline HashTableNode* htAddI64StackP(HashTable *dataStructure, i64 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddI64PStack(HashTable *dataStructure, const volatile i64* key, Stack value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddI64PStackP(HashTable *dataStructure, const volatile i64* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddI64RedBlackTree(HashTable *dataStructure, i64 key, RedBlackTree value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddI64RedBlackTreeP(HashTable *dataStructure, i64 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddI64PRedBlackTree(HashTable *dataStructure, const volatile i64* key, RedBlackTree value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddI64PRedBlackTreeP(HashTable *dataStructure, const volatile i64* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddI64HashTable(HashTable *dataStructure, i64 key, HashTable value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline HashTableNode* htAddI64HashTableP(HashTable *dataStructure, i64 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddI64PHashTable(HashTable *dataStructure, const volatile i64* key, HashTable value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddI64PHashTableP(HashTable *dataStructure, const volatile i64* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddI64Vector(HashTable *dataStructure, i64 key, Vector value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeVector);
}
static inline HashTableNode* htAddI64VectorP(HashTable *dataStructure, i64 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddI64PVector(HashTable *dataStructure, const volatile i64* key, Vector value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddI64PVectorP(HashTable *dataStructure, const volatile i64* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddI64String(HashTable *dataStructure, i64 key, const volatile char* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeString);
}
static inline HashTableNode* htAddI64StringP(HashTable *dataStructure, i64 key, const volatile char** value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddI64PString(HashTable *dataStructure, const volatile i64* key, const volatile char* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddI64PStringP(HashTable *dataStructure, const volatile i64* key, const volatile char** value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddI64Bytes(HashTable *dataStructure, i64 key, Bytes value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBytes);
}
static inline HashTableNode* htAddI64BytesP(HashTable *dataStructure, i64 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddI64PBytes(HashTable *dataStructure, const volatile i64* key, Bytes value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddI64PBytesP(HashTable *dataStructure, const volatile i64* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddI64Pointer(HashTable *dataStructure, i64 key, void* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typePointer);
}
static inline HashTableNode* htAddI64PointerP(HashTable *dataStructure, i64 key, const volatile void** value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddI64PPointer(HashTable *dataStructure, const volatile i64* key, void* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddI64PPointerP(HashTable *dataStructure, const volatile i64* key, const volatile void** value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddI64I8(HashTable *dataStructure, i64 key, i8 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI8);
}
static inline HashTableNode* htAddI64PI8(HashTable *dataStructure, const volatile i64* key, i8 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddI64U8(HashTable *dataStructure, i64 key, u8 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU8);
}
static inline HashTableNode* htAddI64PU8(HashTable *dataStructure, const volatile i64* key, u8 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}
static inline HashTableNode* htAddU64Bool(HashTable *dataStructure, u64 key, bool value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeBool);
}
static inline HashTableNode* htAddU64BoolP(HashTable *dataStructure, u64 key, const volatile bool* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddU64PBool(HashTable *dataStructure, const volatile u64* key, bool value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddU64PBoolP(HashTable *dataStructure, const volatile u64* key, const volatile bool* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddU64I16(HashTable *dataStructure, u64 key, i16 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI16);
}
static inline HashTableNode* htAddU64I16P(HashTable *dataStructure, u64 key, const volatile i16* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddU64PI16(HashTable *dataStructure, const volatile u64* key, i16 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddU64PI16P(HashTable *dataStructure, const volatile u64* key, const volatile i16* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddU64U16(HashTable *dataStructure, u64 key, u16 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU16);
}
static inline HashTableNode* htAddU64U16P(HashTable *dataStructure, u64 key, const volatile u16* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddU64PU16(HashTable *dataStructure, const volatile u64* key, u16 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddU64PU16P(HashTable *dataStructure, const volatile u64* key, const volatile u16* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddU64I32(HashTable *dataStructure, u64 key, i32 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI32);
}
static inline HashTableNode* htAddU64I32P(HashTable *dataStructure, u64 key, const volatile i32* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddU64PI32(HashTable *dataStructure, const volatile u64* key, i32 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddU64PI32P(HashTable *dataStructure, const volatile u64* key, const volatile i32* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddU64U32(HashTable *dataStructure, u64 key, u32 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU32);
}
static inline HashTableNode* htAddU64U32P(HashTable *dataStructure, u64 key, const volatile u32* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddU64PU32(HashTable *dataStructure, const volatile u64* key, u32 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddU64PU32P(HashTable *dataStructure, const volatile u64* key, const volatile u32* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddU64I64(HashTable *dataStructure, u64 key, i64 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI64);
}
static inline HashTableNode* htAddU64I64P(HashTable *dataStructure, u64 key, const volatile i64* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddU64PI64(HashTable *dataStructure, const volatile u64* key, i64 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddU64PI64P(HashTable *dataStructure, const volatile u64* key, const volatile i64* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddU64U64(HashTable *dataStructure, u64 key, u64 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU64);
}
static inline HashTableNode* htAddU64U64P(HashTable *dataStructure, u64 key, const volatile u64* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddU64PU64(HashTable *dataStructure, const volatile u64* key, u64 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddU64PU64P(HashTable *dataStructure, const volatile u64* key, const volatile u64* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddU64Float(HashTable *dataStructure, u64 key, float value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline HashTableNode* htAddU64FloatP(HashTable *dataStructure, u64 key, const volatile float* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddU64PFloat(HashTable *dataStructure, const volatile u64* key, float value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddU64PFloatP(HashTable *dataStructure, const volatile u64* key, const volatile float* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddU64Double(HashTable *dataStructure, u64 key, double value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline HashTableNode* htAddU64DoubleP(HashTable *dataStructure, u64 key, const volatile double* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddU64PDouble(HashTable *dataStructure, const volatile u64* key, double value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddU64PDoubleP(HashTable *dataStructure, const volatile u64* key, const volatile double* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddU64LongDouble(HashTable *dataStructure, u64 key, long double value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline HashTableNode* htAddU64LongDoubleP(HashTable *dataStructure, u64 key, const volatile long double* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddU64PLongDouble(HashTable *dataStructure, const volatile u64* key, long double value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddU64PLongDoubleP(HashTable *dataStructure, const volatile u64* key, const volatile long double* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddU64List(HashTable *dataStructure, u64 key, List value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeList);
}
static inline HashTableNode* htAddU64ListP(HashTable *dataStructure, u64 key, const volatile List* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline HashTableNode* htAddU64PList(HashTable *dataStructure, const volatile u64* key, List value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddU64PListP(HashTable *dataStructure, const volatile u64* key, const volatile List* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddU64Queue(HashTable *dataStructure, u64 key, Queue value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline HashTableNode* htAddU64QueueP(HashTable *dataStructure, u64 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddU64PQueue(HashTable *dataStructure, const volatile u64* key, Queue value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddU64PQueueP(HashTable *dataStructure, const volatile u64* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddU64Stack(HashTable *dataStructure, u64 key, Stack value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeStack);
}
static inline HashTableNode* htAddU64StackP(HashTable *dataStructure, u64 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddU64PStack(HashTable *dataStructure, const volatile u64* key, Stack value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddU64PStackP(HashTable *dataStructure, const volatile u64* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddU64RedBlackTree(HashTable *dataStructure, u64 key, RedBlackTree value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddU64RedBlackTreeP(HashTable *dataStructure, u64 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddU64PRedBlackTree(HashTable *dataStructure, const volatile u64* key, RedBlackTree value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddU64PRedBlackTreeP(HashTable *dataStructure, const volatile u64* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddU64HashTable(HashTable *dataStructure, u64 key, HashTable value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline HashTableNode* htAddU64HashTableP(HashTable *dataStructure, u64 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddU64PHashTable(HashTable *dataStructure, const volatile u64* key, HashTable value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddU64PHashTableP(HashTable *dataStructure, const volatile u64* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddU64Vector(HashTable *dataStructure, u64 key, Vector value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeVector);
}
static inline HashTableNode* htAddU64VectorP(HashTable *dataStructure, u64 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddU64PVector(HashTable *dataStructure, const volatile u64* key, Vector value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddU64PVectorP(HashTable *dataStructure, const volatile u64* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddU64String(HashTable *dataStructure, u64 key, const volatile char* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeString);
}
static inline HashTableNode* htAddU64StringP(HashTable *dataStructure, u64 key, const volatile char** value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddU64PString(HashTable *dataStructure, const volatile u64* key, const volatile char* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddU64PStringP(HashTable *dataStructure, const volatile u64* key, const volatile char** value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddU64Bytes(HashTable *dataStructure, u64 key, Bytes value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBytes);
}
static inline HashTableNode* htAddU64BytesP(HashTable *dataStructure, u64 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddU64PBytes(HashTable *dataStructure, const volatile u64* key, Bytes value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddU64PBytesP(HashTable *dataStructure, const volatile u64* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddU64Pointer(HashTable *dataStructure, u64 key, void* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typePointer);
}
static inline HashTableNode* htAddU64PointerP(HashTable *dataStructure, u64 key, const volatile void** value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddU64PPointer(HashTable *dataStructure, const volatile u64* key, void* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddU64PPointerP(HashTable *dataStructure, const volatile u64* key, const volatile void** value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddU64I8(HashTable *dataStructure, u64 key, i8 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI8);
}
static inline HashTableNode* htAddU64PI8(HashTable *dataStructure, const volatile u64* key, i8 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddU64U8(HashTable *dataStructure, u64 key, u8 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU8);
}
static inline HashTableNode* htAddU64PU8(HashTable *dataStructure, const volatile u64* key, u8 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}
static inline HashTableNode* htAddFloatBool(HashTable *dataStructure, float key, bool value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeBool);
}
static inline HashTableNode* htAddFloatBoolP(HashTable *dataStructure, float key, const volatile bool* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddFloatPBool(HashTable *dataStructure, const volatile float* key, bool value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddFloatPBoolP(HashTable *dataStructure, const volatile float* key, const volatile bool* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddFloatI16(HashTable *dataStructure, float key, i16 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI16);
}
static inline HashTableNode* htAddFloatI16P(HashTable *dataStructure, float key, const volatile i16* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddFloatPI16(HashTable *dataStructure, const volatile float* key, i16 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddFloatPI16P(HashTable *dataStructure, const volatile float* key, const volatile i16* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddFloatU16(HashTable *dataStructure, float key, u16 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU16);
}
static inline HashTableNode* htAddFloatU16P(HashTable *dataStructure, float key, const volatile u16* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddFloatPU16(HashTable *dataStructure, const volatile float* key, u16 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddFloatPU16P(HashTable *dataStructure, const volatile float* key, const volatile u16* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddFloatI32(HashTable *dataStructure, float key, i32 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI32);
}
static inline HashTableNode* htAddFloatI32P(HashTable *dataStructure, float key, const volatile i32* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddFloatPI32(HashTable *dataStructure, const volatile float* key, i32 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddFloatPI32P(HashTable *dataStructure, const volatile float* key, const volatile i32* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddFloatU32(HashTable *dataStructure, float key, u32 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU32);
}
static inline HashTableNode* htAddFloatU32P(HashTable *dataStructure, float key, const volatile u32* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddFloatPU32(HashTable *dataStructure, const volatile float* key, u32 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddFloatPU32P(HashTable *dataStructure, const volatile float* key, const volatile u32* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddFloatI64(HashTable *dataStructure, float key, i64 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI64);
}
static inline HashTableNode* htAddFloatI64P(HashTable *dataStructure, float key, const volatile i64* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddFloatPI64(HashTable *dataStructure, const volatile float* key, i64 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddFloatPI64P(HashTable *dataStructure, const volatile float* key, const volatile i64* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddFloatU64(HashTable *dataStructure, float key, u64 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU64);
}
static inline HashTableNode* htAddFloatU64P(HashTable *dataStructure, float key, const volatile u64* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddFloatPU64(HashTable *dataStructure, const volatile float* key, u64 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddFloatPU64P(HashTable *dataStructure, const volatile float* key, const volatile u64* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddFloatFloat(HashTable *dataStructure, float key, float value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline HashTableNode* htAddFloatFloatP(HashTable *dataStructure, float key, const volatile float* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddFloatPFloat(HashTable *dataStructure, const volatile float* key, float value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddFloatPFloatP(HashTable *dataStructure, const volatile float* key, const volatile float* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddFloatDouble(HashTable *dataStructure, float key, double value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline HashTableNode* htAddFloatDoubleP(HashTable *dataStructure, float key, const volatile double* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddFloatPDouble(HashTable *dataStructure, const volatile float* key, double value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddFloatPDoubleP(HashTable *dataStructure, const volatile float* key, const volatile double* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddFloatLongDouble(HashTable *dataStructure, float key, long double value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline HashTableNode* htAddFloatLongDoubleP(HashTable *dataStructure, float key, const volatile long double* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddFloatPLongDouble(HashTable *dataStructure, const volatile float* key, long double value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddFloatPLongDoubleP(HashTable *dataStructure, const volatile float* key, const volatile long double* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddFloatList(HashTable *dataStructure, float key, List value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeList);
}
static inline HashTableNode* htAddFloatListP(HashTable *dataStructure, float key, const volatile List* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline HashTableNode* htAddFloatPList(HashTable *dataStructure, const volatile float* key, List value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddFloatPListP(HashTable *dataStructure, const volatile float* key, const volatile List* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddFloatQueue(HashTable *dataStructure, float key, Queue value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline HashTableNode* htAddFloatQueueP(HashTable *dataStructure, float key, const volatile Queue* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddFloatPQueue(HashTable *dataStructure, const volatile float* key, Queue value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddFloatPQueueP(HashTable *dataStructure, const volatile float* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddFloatStack(HashTable *dataStructure, float key, Stack value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeStack);
}
static inline HashTableNode* htAddFloatStackP(HashTable *dataStructure, float key, const volatile Stack* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddFloatPStack(HashTable *dataStructure, const volatile float* key, Stack value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddFloatPStackP(HashTable *dataStructure, const volatile float* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddFloatRedBlackTree(HashTable *dataStructure, float key, RedBlackTree value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddFloatRedBlackTreeP(HashTable *dataStructure, float key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddFloatPRedBlackTree(HashTable *dataStructure, const volatile float* key, RedBlackTree value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddFloatPRedBlackTreeP(HashTable *dataStructure, const volatile float* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddFloatHashTable(HashTable *dataStructure, float key, HashTable value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline HashTableNode* htAddFloatHashTableP(HashTable *dataStructure, float key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddFloatPHashTable(HashTable *dataStructure, const volatile float* key, HashTable value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddFloatPHashTableP(HashTable *dataStructure, const volatile float* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddFloatVector(HashTable *dataStructure, float key, Vector value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeVector);
}
static inline HashTableNode* htAddFloatVectorP(HashTable *dataStructure, float key, const volatile Vector* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddFloatPVector(HashTable *dataStructure, const volatile float* key, Vector value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddFloatPVectorP(HashTable *dataStructure, const volatile float* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddFloatString(HashTable *dataStructure, float key, const volatile char* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeString);
}
static inline HashTableNode* htAddFloatStringP(HashTable *dataStructure, float key, const volatile char** value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddFloatPString(HashTable *dataStructure, const volatile float* key, const volatile char* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddFloatPStringP(HashTable *dataStructure, const volatile float* key, const volatile char** value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddFloatBytes(HashTable *dataStructure, float key, Bytes value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBytes);
}
static inline HashTableNode* htAddFloatBytesP(HashTable *dataStructure, float key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddFloatPBytes(HashTable *dataStructure, const volatile float* key, Bytes value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddFloatPBytesP(HashTable *dataStructure, const volatile float* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddFloatPointer(HashTable *dataStructure, float key, void* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typePointer);
}
static inline HashTableNode* htAddFloatPointerP(HashTable *dataStructure, float key, const volatile void** value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddFloatPPointer(HashTable *dataStructure, const volatile float* key, void* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddFloatPPointerP(HashTable *dataStructure, const volatile float* key, const volatile void** value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddFloatI8(HashTable *dataStructure, float key, i8 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI8);
}
static inline HashTableNode* htAddFloatPI8(HashTable *dataStructure, const volatile float* key, i8 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddFloatU8(HashTable *dataStructure, float key, u8 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU8);
}
static inline HashTableNode* htAddFloatPU8(HashTable *dataStructure, const volatile float* key, u8 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}
static inline HashTableNode* htAddDoubleBool(HashTable *dataStructure, double key, bool value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeBool);
}
static inline HashTableNode* htAddDoubleBoolP(HashTable *dataStructure, double key, const volatile bool* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddDoublePBool(HashTable *dataStructure, const volatile double* key, bool value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddDoublePBoolP(HashTable *dataStructure, const volatile double* key, const volatile bool* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddDoubleI16(HashTable *dataStructure, double key, i16 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI16);
}
static inline HashTableNode* htAddDoubleI16P(HashTable *dataStructure, double key, const volatile i16* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddDoublePI16(HashTable *dataStructure, const volatile double* key, i16 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddDoublePI16P(HashTable *dataStructure, const volatile double* key, const volatile i16* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddDoubleU16(HashTable *dataStructure, double key, u16 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU16);
}
static inline HashTableNode* htAddDoubleU16P(HashTable *dataStructure, double key, const volatile u16* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddDoublePU16(HashTable *dataStructure, const volatile double* key, u16 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddDoublePU16P(HashTable *dataStructure, const volatile double* key, const volatile u16* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddDoubleI32(HashTable *dataStructure, double key, i32 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI32);
}
static inline HashTableNode* htAddDoubleI32P(HashTable *dataStructure, double key, const volatile i32* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddDoublePI32(HashTable *dataStructure, const volatile double* key, i32 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddDoublePI32P(HashTable *dataStructure, const volatile double* key, const volatile i32* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddDoubleU32(HashTable *dataStructure, double key, u32 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU32);
}
static inline HashTableNode* htAddDoubleU32P(HashTable *dataStructure, double key, const volatile u32* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddDoublePU32(HashTable *dataStructure, const volatile double* key, u32 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddDoublePU32P(HashTable *dataStructure, const volatile double* key, const volatile u32* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddDoubleI64(HashTable *dataStructure, double key, i64 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI64);
}
static inline HashTableNode* htAddDoubleI64P(HashTable *dataStructure, double key, const volatile i64* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddDoublePI64(HashTable *dataStructure, const volatile double* key, i64 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddDoublePI64P(HashTable *dataStructure, const volatile double* key, const volatile i64* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddDoubleU64(HashTable *dataStructure, double key, u64 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU64);
}
static inline HashTableNode* htAddDoubleU64P(HashTable *dataStructure, double key, const volatile u64* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddDoublePU64(HashTable *dataStructure, const volatile double* key, u64 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddDoublePU64P(HashTable *dataStructure, const volatile double* key, const volatile u64* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddDoubleFloat(HashTable *dataStructure, double key, float value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline HashTableNode* htAddDoubleFloatP(HashTable *dataStructure, double key, const volatile float* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddDoublePFloat(HashTable *dataStructure, const volatile double* key, float value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddDoublePFloatP(HashTable *dataStructure, const volatile double* key, const volatile float* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddDoubleDouble(HashTable *dataStructure, double key, double value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline HashTableNode* htAddDoubleDoubleP(HashTable *dataStructure, double key, const volatile double* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddDoublePDouble(HashTable *dataStructure, const volatile double* key, double value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddDoublePDoubleP(HashTable *dataStructure, const volatile double* key, const volatile double* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddDoubleLongDouble(HashTable *dataStructure, double key, long double value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline HashTableNode* htAddDoubleLongDoubleP(HashTable *dataStructure, double key, const volatile long double* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddDoublePLongDouble(HashTable *dataStructure, const volatile double* key, long double value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddDoublePLongDoubleP(HashTable *dataStructure, const volatile double* key, const volatile long double* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddDoubleList(HashTable *dataStructure, double key, List value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeList);
}
static inline HashTableNode* htAddDoubleListP(HashTable *dataStructure, double key, const volatile List* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline HashTableNode* htAddDoublePList(HashTable *dataStructure, const volatile double* key, List value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddDoublePListP(HashTable *dataStructure, const volatile double* key, const volatile List* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddDoubleQueue(HashTable *dataStructure, double key, Queue value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline HashTableNode* htAddDoubleQueueP(HashTable *dataStructure, double key, const volatile Queue* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddDoublePQueue(HashTable *dataStructure, const volatile double* key, Queue value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddDoublePQueueP(HashTable *dataStructure, const volatile double* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddDoubleStack(HashTable *dataStructure, double key, Stack value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeStack);
}
static inline HashTableNode* htAddDoubleStackP(HashTable *dataStructure, double key, const volatile Stack* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddDoublePStack(HashTable *dataStructure, const volatile double* key, Stack value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddDoublePStackP(HashTable *dataStructure, const volatile double* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddDoubleRedBlackTree(HashTable *dataStructure, double key, RedBlackTree value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddDoubleRedBlackTreeP(HashTable *dataStructure, double key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddDoublePRedBlackTree(HashTable *dataStructure, const volatile double* key, RedBlackTree value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddDoublePRedBlackTreeP(HashTable *dataStructure, const volatile double* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddDoubleHashTable(HashTable *dataStructure, double key, HashTable value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline HashTableNode* htAddDoubleHashTableP(HashTable *dataStructure, double key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddDoublePHashTable(HashTable *dataStructure, const volatile double* key, HashTable value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddDoublePHashTableP(HashTable *dataStructure, const volatile double* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddDoubleVector(HashTable *dataStructure, double key, Vector value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeVector);
}
static inline HashTableNode* htAddDoubleVectorP(HashTable *dataStructure, double key, const volatile Vector* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddDoublePVector(HashTable *dataStructure, const volatile double* key, Vector value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddDoublePVectorP(HashTable *dataStructure, const volatile double* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddDoubleString(HashTable *dataStructure, double key, const volatile char* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeString);
}
static inline HashTableNode* htAddDoubleStringP(HashTable *dataStructure, double key, const volatile char** value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddDoublePString(HashTable *dataStructure, const volatile double* key, const volatile char* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddDoublePStringP(HashTable *dataStructure, const volatile double* key, const volatile char** value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddDoubleBytes(HashTable *dataStructure, double key, Bytes value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBytes);
}
static inline HashTableNode* htAddDoubleBytesP(HashTable *dataStructure, double key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddDoublePBytes(HashTable *dataStructure, const volatile double* key, Bytes value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddDoublePBytesP(HashTable *dataStructure, const volatile double* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddDoublePointer(HashTable *dataStructure, double key, void* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typePointer);
}
static inline HashTableNode* htAddDoublePointerP(HashTable *dataStructure, double key, const volatile void** value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddDoublePPointer(HashTable *dataStructure, const volatile double* key, void* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddDoublePPointerP(HashTable *dataStructure, const volatile double* key, const volatile void** value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddDoubleI8(HashTable *dataStructure, double key, i8 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI8);
}
static inline HashTableNode* htAddDoublePI8(HashTable *dataStructure, const volatile double* key, i8 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddDoubleU8(HashTable *dataStructure, double key, u8 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU8);
}
static inline HashTableNode* htAddDoublePU8(HashTable *dataStructure, const volatile double* key, u8 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}
static inline HashTableNode* htAddLongDoubleBool(HashTable *dataStructure, long double key, bool value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeBool);
}
static inline HashTableNode* htAddLongDoubleBoolP(HashTable *dataStructure, long double key, const volatile bool* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddLongDoublePBool(HashTable *dataStructure, const volatile long double* key, bool value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddLongDoublePBoolP(HashTable *dataStructure, const volatile long double* key, const volatile bool* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddLongDoubleI16(HashTable *dataStructure, long double key, i16 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI16);
}
static inline HashTableNode* htAddLongDoubleI16P(HashTable *dataStructure, long double key, const volatile i16* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddLongDoublePI16(HashTable *dataStructure, const volatile long double* key, i16 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddLongDoublePI16P(HashTable *dataStructure, const volatile long double* key, const volatile i16* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddLongDoubleU16(HashTable *dataStructure, long double key, u16 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU16);
}
static inline HashTableNode* htAddLongDoubleU16P(HashTable *dataStructure, long double key, const volatile u16* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddLongDoublePU16(HashTable *dataStructure, const volatile long double* key, u16 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddLongDoublePU16P(HashTable *dataStructure, const volatile long double* key, const volatile u16* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddLongDoubleI32(HashTable *dataStructure, long double key, i32 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI32);
}
static inline HashTableNode* htAddLongDoubleI32P(HashTable *dataStructure, long double key, const volatile i32* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddLongDoublePI32(HashTable *dataStructure, const volatile long double* key, i32 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddLongDoublePI32P(HashTable *dataStructure, const volatile long double* key, const volatile i32* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddLongDoubleU32(HashTable *dataStructure, long double key, u32 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU32);
}
static inline HashTableNode* htAddLongDoubleU32P(HashTable *dataStructure, long double key, const volatile u32* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddLongDoublePU32(HashTable *dataStructure, const volatile long double* key, u32 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddLongDoublePU32P(HashTable *dataStructure, const volatile long double* key, const volatile u32* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddLongDoubleI64(HashTable *dataStructure, long double key, i64 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI64);
}
static inline HashTableNode* htAddLongDoubleI64P(HashTable *dataStructure, long double key, const volatile i64* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddLongDoublePI64(HashTable *dataStructure, const volatile long double* key, i64 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddLongDoublePI64P(HashTable *dataStructure, const volatile long double* key, const volatile i64* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddLongDoubleU64(HashTable *dataStructure, long double key, u64 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU64);
}
static inline HashTableNode* htAddLongDoubleU64P(HashTable *dataStructure, long double key, const volatile u64* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddLongDoublePU64(HashTable *dataStructure, const volatile long double* key, u64 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddLongDoublePU64P(HashTable *dataStructure, const volatile long double* key, const volatile u64* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddLongDoubleFloat(HashTable *dataStructure, long double key, float value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline HashTableNode* htAddLongDoubleFloatP(HashTable *dataStructure, long double key, const volatile float* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddLongDoublePFloat(HashTable *dataStructure, const volatile long double* key, float value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddLongDoublePFloatP(HashTable *dataStructure, const volatile long double* key, const volatile float* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddLongDoubleDouble(HashTable *dataStructure, long double key, double value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline HashTableNode* htAddLongDoubleDoubleP(HashTable *dataStructure, long double key, const volatile double* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddLongDoublePDouble(HashTable *dataStructure, const volatile long double* key, double value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddLongDoublePDoubleP(HashTable *dataStructure, const volatile long double* key, const volatile double* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddLongDoubleLongDouble(HashTable *dataStructure, long double key, long double value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline HashTableNode* htAddLongDoubleLongDoubleP(HashTable *dataStructure, long double key, const volatile long double* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddLongDoublePLongDouble(HashTable *dataStructure, const volatile long double* key, long double value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddLongDoublePLongDoubleP(HashTable *dataStructure, const volatile long double* key, const volatile long double* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddLongDoubleList(HashTable *dataStructure, long double key, List value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeList);
}
static inline HashTableNode* htAddLongDoubleListP(HashTable *dataStructure, long double key, const volatile List* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline HashTableNode* htAddLongDoublePList(HashTable *dataStructure, const volatile long double* key, List value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddLongDoublePListP(HashTable *dataStructure, const volatile long double* key, const volatile List* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddLongDoubleQueue(HashTable *dataStructure, long double key, Queue value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline HashTableNode* htAddLongDoubleQueueP(HashTable *dataStructure, long double key, const volatile Queue* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddLongDoublePQueue(HashTable *dataStructure, const volatile long double* key, Queue value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddLongDoublePQueueP(HashTable *dataStructure, const volatile long double* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddLongDoubleStack(HashTable *dataStructure, long double key, Stack value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeStack);
}
static inline HashTableNode* htAddLongDoubleStackP(HashTable *dataStructure, long double key, const volatile Stack* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddLongDoublePStack(HashTable *dataStructure, const volatile long double* key, Stack value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddLongDoublePStackP(HashTable *dataStructure, const volatile long double* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddLongDoubleRedBlackTree(HashTable *dataStructure, long double key, RedBlackTree value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddLongDoubleRedBlackTreeP(HashTable *dataStructure, long double key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddLongDoublePRedBlackTree(HashTable *dataStructure, const volatile long double* key, RedBlackTree value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddLongDoublePRedBlackTreeP(HashTable *dataStructure, const volatile long double* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddLongDoubleHashTable(HashTable *dataStructure, long double key, HashTable value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline HashTableNode* htAddLongDoubleHashTableP(HashTable *dataStructure, long double key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddLongDoublePHashTable(HashTable *dataStructure, const volatile long double* key, HashTable value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddLongDoublePHashTableP(HashTable *dataStructure, const volatile long double* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddLongDoubleVector(HashTable *dataStructure, long double key, Vector value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeVector);
}
static inline HashTableNode* htAddLongDoubleVectorP(HashTable *dataStructure, long double key, const volatile Vector* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddLongDoublePVector(HashTable *dataStructure, const volatile long double* key, Vector value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddLongDoublePVectorP(HashTable *dataStructure, const volatile long double* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddLongDoubleString(HashTable *dataStructure, long double key, const volatile char* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeString);
}
static inline HashTableNode* htAddLongDoubleStringP(HashTable *dataStructure, long double key, const volatile char** value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddLongDoublePString(HashTable *dataStructure, const volatile long double* key, const volatile char* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddLongDoublePStringP(HashTable *dataStructure, const volatile long double* key, const volatile char** value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddLongDoubleBytes(HashTable *dataStructure, long double key, Bytes value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBytes);
}
static inline HashTableNode* htAddLongDoubleBytesP(HashTable *dataStructure, long double key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddLongDoublePBytes(HashTable *dataStructure, const volatile long double* key, Bytes value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddLongDoublePBytesP(HashTable *dataStructure, const volatile long double* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddLongDoublePointer(HashTable *dataStructure, long double key, void* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typePointer);
}
static inline HashTableNode* htAddLongDoublePointerP(HashTable *dataStructure, long double key, const volatile void** value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddLongDoublePPointer(HashTable *dataStructure, const volatile long double* key, void* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddLongDoublePPointerP(HashTable *dataStructure, const volatile long double* key, const volatile void** value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddLongDoubleI8(HashTable *dataStructure, long double key, i8 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI8);
}
static inline HashTableNode* htAddLongDoublePI8(HashTable *dataStructure, const volatile long double* key, i8 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddLongDoubleU8(HashTable *dataStructure, long double key, u8 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU8);
}
static inline HashTableNode* htAddLongDoublePU8(HashTable *dataStructure, const volatile long double* key, u8 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}
static inline HashTableNode* htAddListBool(HashTable *dataStructure, List key, bool value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeBool);
}
static inline HashTableNode* htAddListBoolP(HashTable *dataStructure, List key, const volatile bool* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddListPBool(HashTable *dataStructure, const volatile List* key, bool value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddListPBoolP(HashTable *dataStructure, const volatile List* key, const volatile bool* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddListI16(HashTable *dataStructure, List key, i16 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI16);
}
static inline HashTableNode* htAddListI16P(HashTable *dataStructure, List key, const volatile i16* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddListPI16(HashTable *dataStructure, const volatile List* key, i16 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddListPI16P(HashTable *dataStructure, const volatile List* key, const volatile i16* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddListU16(HashTable *dataStructure, List key, u16 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU16);
}
static inline HashTableNode* htAddListU16P(HashTable *dataStructure, List key, const volatile u16* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddListPU16(HashTable *dataStructure, const volatile List* key, u16 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddListPU16P(HashTable *dataStructure, const volatile List* key, const volatile u16* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddListI32(HashTable *dataStructure, List key, i32 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI32);
}
static inline HashTableNode* htAddListI32P(HashTable *dataStructure, List key, const volatile i32* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddListPI32(HashTable *dataStructure, const volatile List* key, i32 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddListPI32P(HashTable *dataStructure, const volatile List* key, const volatile i32* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddListU32(HashTable *dataStructure, List key, u32 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU32);
}
static inline HashTableNode* htAddListU32P(HashTable *dataStructure, List key, const volatile u32* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddListPU32(HashTable *dataStructure, const volatile List* key, u32 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddListPU32P(HashTable *dataStructure, const volatile List* key, const volatile u32* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddListI64(HashTable *dataStructure, List key, i64 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI64);
}
static inline HashTableNode* htAddListI64P(HashTable *dataStructure, List key, const volatile i64* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddListPI64(HashTable *dataStructure, const volatile List* key, i64 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddListPI64P(HashTable *dataStructure, const volatile List* key, const volatile i64* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddListU64(HashTable *dataStructure, List key, u64 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU64);
}
static inline HashTableNode* htAddListU64P(HashTable *dataStructure, List key, const volatile u64* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddListPU64(HashTable *dataStructure, const volatile List* key, u64 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddListPU64P(HashTable *dataStructure, const volatile List* key, const volatile u64* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddListFloat(HashTable *dataStructure, List key, float value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline HashTableNode* htAddListFloatP(HashTable *dataStructure, List key, const volatile float* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddListPFloat(HashTable *dataStructure, const volatile List* key, float value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddListPFloatP(HashTable *dataStructure, const volatile List* key, const volatile float* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddListDouble(HashTable *dataStructure, List key, double value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline HashTableNode* htAddListDoubleP(HashTable *dataStructure, List key, const volatile double* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddListPDouble(HashTable *dataStructure, const volatile List* key, double value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddListPDoubleP(HashTable *dataStructure, const volatile List* key, const volatile double* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddListLongDouble(HashTable *dataStructure, List key, long double value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline HashTableNode* htAddListLongDoubleP(HashTable *dataStructure, List key, const volatile long double* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddListPLongDouble(HashTable *dataStructure, const volatile List* key, long double value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddListPLongDoubleP(HashTable *dataStructure, const volatile List* key, const volatile long double* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddListList(HashTable *dataStructure, List key, List value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeList);
}
static inline HashTableNode* htAddListListP(HashTable *dataStructure, List key, const volatile List* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline HashTableNode* htAddListPList(HashTable *dataStructure, const volatile List* key, List value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddListPListP(HashTable *dataStructure, const volatile List* key, const volatile List* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddListQueue(HashTable *dataStructure, List key, Queue value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline HashTableNode* htAddListQueueP(HashTable *dataStructure, List key, const volatile Queue* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddListPQueue(HashTable *dataStructure, const volatile List* key, Queue value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddListPQueueP(HashTable *dataStructure, const volatile List* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddListStack(HashTable *dataStructure, List key, Stack value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeStack);
}
static inline HashTableNode* htAddListStackP(HashTable *dataStructure, List key, const volatile Stack* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddListPStack(HashTable *dataStructure, const volatile List* key, Stack value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddListPStackP(HashTable *dataStructure, const volatile List* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddListRedBlackTree(HashTable *dataStructure, List key, RedBlackTree value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddListRedBlackTreeP(HashTable *dataStructure, List key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddListPRedBlackTree(HashTable *dataStructure, const volatile List* key, RedBlackTree value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddListPRedBlackTreeP(HashTable *dataStructure, const volatile List* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddListHashTable(HashTable *dataStructure, List key, HashTable value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline HashTableNode* htAddListHashTableP(HashTable *dataStructure, List key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddListPHashTable(HashTable *dataStructure, const volatile List* key, HashTable value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddListPHashTableP(HashTable *dataStructure, const volatile List* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddListVector(HashTable *dataStructure, List key, Vector value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeVector);
}
static inline HashTableNode* htAddListVectorP(HashTable *dataStructure, List key, const volatile Vector* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddListPVector(HashTable *dataStructure, const volatile List* key, Vector value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddListPVectorP(HashTable *dataStructure, const volatile List* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddListString(HashTable *dataStructure, List key, const volatile char* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeString);
}
static inline HashTableNode* htAddListStringP(HashTable *dataStructure, List key, const volatile char** value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddListPString(HashTable *dataStructure, const volatile List* key, const volatile char* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddListPStringP(HashTable *dataStructure, const volatile List* key, const volatile char** value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddListBytes(HashTable *dataStructure, List key, Bytes value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBytes);
}
static inline HashTableNode* htAddListBytesP(HashTable *dataStructure, List key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddListPBytes(HashTable *dataStructure, const volatile List* key, Bytes value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddListPBytesP(HashTable *dataStructure, const volatile List* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddListPointer(HashTable *dataStructure, List key, void* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typePointer);
}
static inline HashTableNode* htAddListPointerP(HashTable *dataStructure, List key, const volatile void** value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddListPPointer(HashTable *dataStructure, const volatile List* key, void* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddListPPointerP(HashTable *dataStructure, const volatile List* key, const volatile void** value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddListI8(HashTable *dataStructure, List key, i8 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI8);
}
static inline HashTableNode* htAddListPI8(HashTable *dataStructure, const volatile List* key, i8 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddListU8(HashTable *dataStructure, List key, u8 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU8);
}
static inline HashTableNode* htAddListPU8(HashTable *dataStructure, const volatile List* key, u8 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}
static inline HashTableNode* htAddQueueBool(HashTable *dataStructure, Queue key, bool value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeBool);
}
static inline HashTableNode* htAddQueueBoolP(HashTable *dataStructure, Queue key, const volatile bool* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddQueuePBool(HashTable *dataStructure, const volatile Queue* key, bool value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddQueuePBoolP(HashTable *dataStructure, const volatile Queue* key, const volatile bool* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddQueueI16(HashTable *dataStructure, Queue key, i16 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI16);
}
static inline HashTableNode* htAddQueueI16P(HashTable *dataStructure, Queue key, const volatile i16* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddQueuePI16(HashTable *dataStructure, const volatile Queue* key, i16 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddQueuePI16P(HashTable *dataStructure, const volatile Queue* key, const volatile i16* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddQueueU16(HashTable *dataStructure, Queue key, u16 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU16);
}
static inline HashTableNode* htAddQueueU16P(HashTable *dataStructure, Queue key, const volatile u16* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddQueuePU16(HashTable *dataStructure, const volatile Queue* key, u16 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddQueuePU16P(HashTable *dataStructure, const volatile Queue* key, const volatile u16* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddQueueI32(HashTable *dataStructure, Queue key, i32 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI32);
}
static inline HashTableNode* htAddQueueI32P(HashTable *dataStructure, Queue key, const volatile i32* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddQueuePI32(HashTable *dataStructure, const volatile Queue* key, i32 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddQueuePI32P(HashTable *dataStructure, const volatile Queue* key, const volatile i32* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddQueueU32(HashTable *dataStructure, Queue key, u32 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU32);
}
static inline HashTableNode* htAddQueueU32P(HashTable *dataStructure, Queue key, const volatile u32* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddQueuePU32(HashTable *dataStructure, const volatile Queue* key, u32 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddQueuePU32P(HashTable *dataStructure, const volatile Queue* key, const volatile u32* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddQueueI64(HashTable *dataStructure, Queue key, i64 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI64);
}
static inline HashTableNode* htAddQueueI64P(HashTable *dataStructure, Queue key, const volatile i64* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddQueuePI64(HashTable *dataStructure, const volatile Queue* key, i64 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddQueuePI64P(HashTable *dataStructure, const volatile Queue* key, const volatile i64* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddQueueU64(HashTable *dataStructure, Queue key, u64 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU64);
}
static inline HashTableNode* htAddQueueU64P(HashTable *dataStructure, Queue key, const volatile u64* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddQueuePU64(HashTable *dataStructure, const volatile Queue* key, u64 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddQueuePU64P(HashTable *dataStructure, const volatile Queue* key, const volatile u64* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddQueueFloat(HashTable *dataStructure, Queue key, float value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline HashTableNode* htAddQueueFloatP(HashTable *dataStructure, Queue key, const volatile float* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddQueuePFloat(HashTable *dataStructure, const volatile Queue* key, float value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddQueuePFloatP(HashTable *dataStructure, const volatile Queue* key, const volatile float* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddQueueDouble(HashTable *dataStructure, Queue key, double value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline HashTableNode* htAddQueueDoubleP(HashTable *dataStructure, Queue key, const volatile double* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddQueuePDouble(HashTable *dataStructure, const volatile Queue* key, double value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddQueuePDoubleP(HashTable *dataStructure, const volatile Queue* key, const volatile double* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddQueueLongDouble(HashTable *dataStructure, Queue key, long double value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline HashTableNode* htAddQueueLongDoubleP(HashTable *dataStructure, Queue key, const volatile long double* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddQueuePLongDouble(HashTable *dataStructure, const volatile Queue* key, long double value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddQueuePLongDoubleP(HashTable *dataStructure, const volatile Queue* key, const volatile long double* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddQueueList(HashTable *dataStructure, Queue key, List value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeList);
}
static inline HashTableNode* htAddQueueListP(HashTable *dataStructure, Queue key, const volatile List* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline HashTableNode* htAddQueuePList(HashTable *dataStructure, const volatile Queue* key, List value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddQueuePListP(HashTable *dataStructure, const volatile Queue* key, const volatile List* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddQueueQueue(HashTable *dataStructure, Queue key, Queue value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline HashTableNode* htAddQueueQueueP(HashTable *dataStructure, Queue key, const volatile Queue* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddQueuePQueue(HashTable *dataStructure, const volatile Queue* key, Queue value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddQueuePQueueP(HashTable *dataStructure, const volatile Queue* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddQueueStack(HashTable *dataStructure, Queue key, Stack value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeStack);
}
static inline HashTableNode* htAddQueueStackP(HashTable *dataStructure, Queue key, const volatile Stack* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddQueuePStack(HashTable *dataStructure, const volatile Queue* key, Stack value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddQueuePStackP(HashTable *dataStructure, const volatile Queue* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddQueueRedBlackTree(HashTable *dataStructure, Queue key, RedBlackTree value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddQueueRedBlackTreeP(HashTable *dataStructure, Queue key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddQueuePRedBlackTree(HashTable *dataStructure, const volatile Queue* key, RedBlackTree value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddQueuePRedBlackTreeP(HashTable *dataStructure, const volatile Queue* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddQueueHashTable(HashTable *dataStructure, Queue key, HashTable value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline HashTableNode* htAddQueueHashTableP(HashTable *dataStructure, Queue key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddQueuePHashTable(HashTable *dataStructure, const volatile Queue* key, HashTable value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddQueuePHashTableP(HashTable *dataStructure, const volatile Queue* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddQueueVector(HashTable *dataStructure, Queue key, Vector value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeVector);
}
static inline HashTableNode* htAddQueueVectorP(HashTable *dataStructure, Queue key, const volatile Vector* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddQueuePVector(HashTable *dataStructure, const volatile Queue* key, Vector value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddQueuePVectorP(HashTable *dataStructure, const volatile Queue* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddQueueString(HashTable *dataStructure, Queue key, const volatile char* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeString);
}
static inline HashTableNode* htAddQueueStringP(HashTable *dataStructure, Queue key, const volatile char** value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddQueuePString(HashTable *dataStructure, const volatile Queue* key, const volatile char* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddQueuePStringP(HashTable *dataStructure, const volatile Queue* key, const volatile char** value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddQueueBytes(HashTable *dataStructure, Queue key, Bytes value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBytes);
}
static inline HashTableNode* htAddQueueBytesP(HashTable *dataStructure, Queue key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddQueuePBytes(HashTable *dataStructure, const volatile Queue* key, Bytes value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddQueuePBytesP(HashTable *dataStructure, const volatile Queue* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddQueuePointer(HashTable *dataStructure, Queue key, void* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typePointer);
}
static inline HashTableNode* htAddQueuePointerP(HashTable *dataStructure, Queue key, const volatile void** value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddQueuePPointer(HashTable *dataStructure, const volatile Queue* key, void* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddQueuePPointerP(HashTable *dataStructure, const volatile Queue* key, const volatile void** value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddQueueI8(HashTable *dataStructure, Queue key, i8 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI8);
}
static inline HashTableNode* htAddQueuePI8(HashTable *dataStructure, const volatile Queue* key, i8 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddQueueU8(HashTable *dataStructure, Queue key, u8 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU8);
}
static inline HashTableNode* htAddQueuePU8(HashTable *dataStructure, const volatile Queue* key, u8 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}
static inline HashTableNode* htAddStackBool(HashTable *dataStructure, Stack key, bool value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeBool);
}
static inline HashTableNode* htAddStackBoolP(HashTable *dataStructure, Stack key, const volatile bool* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddStackPBool(HashTable *dataStructure, const volatile Stack* key, bool value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddStackPBoolP(HashTable *dataStructure, const volatile Stack* key, const volatile bool* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddStackI16(HashTable *dataStructure, Stack key, i16 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI16);
}
static inline HashTableNode* htAddStackI16P(HashTable *dataStructure, Stack key, const volatile i16* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddStackPI16(HashTable *dataStructure, const volatile Stack* key, i16 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddStackPI16P(HashTable *dataStructure, const volatile Stack* key, const volatile i16* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddStackU16(HashTable *dataStructure, Stack key, u16 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU16);
}
static inline HashTableNode* htAddStackU16P(HashTable *dataStructure, Stack key, const volatile u16* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddStackPU16(HashTable *dataStructure, const volatile Stack* key, u16 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddStackPU16P(HashTable *dataStructure, const volatile Stack* key, const volatile u16* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddStackI32(HashTable *dataStructure, Stack key, i32 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI32);
}
static inline HashTableNode* htAddStackI32P(HashTable *dataStructure, Stack key, const volatile i32* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddStackPI32(HashTable *dataStructure, const volatile Stack* key, i32 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddStackPI32P(HashTable *dataStructure, const volatile Stack* key, const volatile i32* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddStackU32(HashTable *dataStructure, Stack key, u32 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU32);
}
static inline HashTableNode* htAddStackU32P(HashTable *dataStructure, Stack key, const volatile u32* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddStackPU32(HashTable *dataStructure, const volatile Stack* key, u32 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddStackPU32P(HashTable *dataStructure, const volatile Stack* key, const volatile u32* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddStackI64(HashTable *dataStructure, Stack key, i64 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI64);
}
static inline HashTableNode* htAddStackI64P(HashTable *dataStructure, Stack key, const volatile i64* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddStackPI64(HashTable *dataStructure, const volatile Stack* key, i64 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddStackPI64P(HashTable *dataStructure, const volatile Stack* key, const volatile i64* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddStackU64(HashTable *dataStructure, Stack key, u64 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU64);
}
static inline HashTableNode* htAddStackU64P(HashTable *dataStructure, Stack key, const volatile u64* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddStackPU64(HashTable *dataStructure, const volatile Stack* key, u64 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddStackPU64P(HashTable *dataStructure, const volatile Stack* key, const volatile u64* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddStackFloat(HashTable *dataStructure, Stack key, float value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline HashTableNode* htAddStackFloatP(HashTable *dataStructure, Stack key, const volatile float* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddStackPFloat(HashTable *dataStructure, const volatile Stack* key, float value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddStackPFloatP(HashTable *dataStructure, const volatile Stack* key, const volatile float* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddStackDouble(HashTable *dataStructure, Stack key, double value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline HashTableNode* htAddStackDoubleP(HashTable *dataStructure, Stack key, const volatile double* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddStackPDouble(HashTable *dataStructure, const volatile Stack* key, double value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddStackPDoubleP(HashTable *dataStructure, const volatile Stack* key, const volatile double* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddStackLongDouble(HashTable *dataStructure, Stack key, long double value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline HashTableNode* htAddStackLongDoubleP(HashTable *dataStructure, Stack key, const volatile long double* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddStackPLongDouble(HashTable *dataStructure, const volatile Stack* key, long double value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddStackPLongDoubleP(HashTable *dataStructure, const volatile Stack* key, const volatile long double* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddStackList(HashTable *dataStructure, Stack key, List value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeList);
}
static inline HashTableNode* htAddStackListP(HashTable *dataStructure, Stack key, const volatile List* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline HashTableNode* htAddStackPList(HashTable *dataStructure, const volatile Stack* key, List value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddStackPListP(HashTable *dataStructure, const volatile Stack* key, const volatile List* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddStackQueue(HashTable *dataStructure, Stack key, Queue value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline HashTableNode* htAddStackQueueP(HashTable *dataStructure, Stack key, const volatile Queue* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddStackPQueue(HashTable *dataStructure, const volatile Stack* key, Queue value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddStackPQueueP(HashTable *dataStructure, const volatile Stack* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddStackStack(HashTable *dataStructure, Stack key, Stack value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeStack);
}
static inline HashTableNode* htAddStackStackP(HashTable *dataStructure, Stack key, const volatile Stack* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddStackPStack(HashTable *dataStructure, const volatile Stack* key, Stack value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddStackPStackP(HashTable *dataStructure, const volatile Stack* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddStackRedBlackTree(HashTable *dataStructure, Stack key, RedBlackTree value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddStackRedBlackTreeP(HashTable *dataStructure, Stack key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddStackPRedBlackTree(HashTable *dataStructure, const volatile Stack* key, RedBlackTree value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddStackPRedBlackTreeP(HashTable *dataStructure, const volatile Stack* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddStackHashTable(HashTable *dataStructure, Stack key, HashTable value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline HashTableNode* htAddStackHashTableP(HashTable *dataStructure, Stack key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddStackPHashTable(HashTable *dataStructure, const volatile Stack* key, HashTable value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddStackPHashTableP(HashTable *dataStructure, const volatile Stack* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddStackVector(HashTable *dataStructure, Stack key, Vector value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeVector);
}
static inline HashTableNode* htAddStackVectorP(HashTable *dataStructure, Stack key, const volatile Vector* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddStackPVector(HashTable *dataStructure, const volatile Stack* key, Vector value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddStackPVectorP(HashTable *dataStructure, const volatile Stack* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddStackString(HashTable *dataStructure, Stack key, const volatile char* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeString);
}
static inline HashTableNode* htAddStackStringP(HashTable *dataStructure, Stack key, const volatile char** value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddStackPString(HashTable *dataStructure, const volatile Stack* key, const volatile char* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddStackPStringP(HashTable *dataStructure, const volatile Stack* key, const volatile char** value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddStackBytes(HashTable *dataStructure, Stack key, Bytes value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBytes);
}
static inline HashTableNode* htAddStackBytesP(HashTable *dataStructure, Stack key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddStackPBytes(HashTable *dataStructure, const volatile Stack* key, Bytes value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddStackPBytesP(HashTable *dataStructure, const volatile Stack* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddStackPointer(HashTable *dataStructure, Stack key, void* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typePointer);
}
static inline HashTableNode* htAddStackPointerP(HashTable *dataStructure, Stack key, const volatile void** value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddStackPPointer(HashTable *dataStructure, const volatile Stack* key, void* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddStackPPointerP(HashTable *dataStructure, const volatile Stack* key, const volatile void** value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddStackI8(HashTable *dataStructure, Stack key, i8 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI8);
}
static inline HashTableNode* htAddStackPI8(HashTable *dataStructure, const volatile Stack* key, i8 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddStackU8(HashTable *dataStructure, Stack key, u8 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU8);
}
static inline HashTableNode* htAddStackPU8(HashTable *dataStructure, const volatile Stack* key, u8 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}
static inline HashTableNode* htAddRedBlackTreeBool(HashTable *dataStructure, RedBlackTree key, bool value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeBool);
}
static inline HashTableNode* htAddRedBlackTreeBoolP(HashTable *dataStructure, RedBlackTree key, const volatile bool* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddRedBlackTreePBool(HashTable *dataStructure, const volatile RedBlackTree* key, bool value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddRedBlackTreePBoolP(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile bool* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddRedBlackTreeI16(HashTable *dataStructure, RedBlackTree key, i16 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI16);
}
static inline HashTableNode* htAddRedBlackTreeI16P(HashTable *dataStructure, RedBlackTree key, const volatile i16* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddRedBlackTreePI16(HashTable *dataStructure, const volatile RedBlackTree* key, i16 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddRedBlackTreePI16P(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile i16* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddRedBlackTreeU16(HashTable *dataStructure, RedBlackTree key, u16 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU16);
}
static inline HashTableNode* htAddRedBlackTreeU16P(HashTable *dataStructure, RedBlackTree key, const volatile u16* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddRedBlackTreePU16(HashTable *dataStructure, const volatile RedBlackTree* key, u16 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddRedBlackTreePU16P(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile u16* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddRedBlackTreeI32(HashTable *dataStructure, RedBlackTree key, i32 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI32);
}
static inline HashTableNode* htAddRedBlackTreeI32P(HashTable *dataStructure, RedBlackTree key, const volatile i32* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddRedBlackTreePI32(HashTable *dataStructure, const volatile RedBlackTree* key, i32 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddRedBlackTreePI32P(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile i32* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddRedBlackTreeU32(HashTable *dataStructure, RedBlackTree key, u32 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU32);
}
static inline HashTableNode* htAddRedBlackTreeU32P(HashTable *dataStructure, RedBlackTree key, const volatile u32* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddRedBlackTreePU32(HashTable *dataStructure, const volatile RedBlackTree* key, u32 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddRedBlackTreePU32P(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile u32* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddRedBlackTreeI64(HashTable *dataStructure, RedBlackTree key, i64 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI64);
}
static inline HashTableNode* htAddRedBlackTreeI64P(HashTable *dataStructure, RedBlackTree key, const volatile i64* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddRedBlackTreePI64(HashTable *dataStructure, const volatile RedBlackTree* key, i64 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddRedBlackTreePI64P(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile i64* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddRedBlackTreeU64(HashTable *dataStructure, RedBlackTree key, u64 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU64);
}
static inline HashTableNode* htAddRedBlackTreeU64P(HashTable *dataStructure, RedBlackTree key, const volatile u64* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddRedBlackTreePU64(HashTable *dataStructure, const volatile RedBlackTree* key, u64 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddRedBlackTreePU64P(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile u64* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddRedBlackTreeFloat(HashTable *dataStructure, RedBlackTree key, float value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline HashTableNode* htAddRedBlackTreeFloatP(HashTable *dataStructure, RedBlackTree key, const volatile float* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddRedBlackTreePFloat(HashTable *dataStructure, const volatile RedBlackTree* key, float value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddRedBlackTreePFloatP(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile float* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddRedBlackTreeDouble(HashTable *dataStructure, RedBlackTree key, double value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline HashTableNode* htAddRedBlackTreeDoubleP(HashTable *dataStructure, RedBlackTree key, const volatile double* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddRedBlackTreePDouble(HashTable *dataStructure, const volatile RedBlackTree* key, double value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddRedBlackTreePDoubleP(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile double* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddRedBlackTreeLongDouble(HashTable *dataStructure, RedBlackTree key, long double value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline HashTableNode* htAddRedBlackTreeLongDoubleP(HashTable *dataStructure, RedBlackTree key, const volatile long double* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddRedBlackTreePLongDouble(HashTable *dataStructure, const volatile RedBlackTree* key, long double value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddRedBlackTreePLongDoubleP(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile long double* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddRedBlackTreeList(HashTable *dataStructure, RedBlackTree key, List value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeList);
}
static inline HashTableNode* htAddRedBlackTreeListP(HashTable *dataStructure, RedBlackTree key, const volatile List* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline HashTableNode* htAddRedBlackTreePList(HashTable *dataStructure, const volatile RedBlackTree* key, List value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddRedBlackTreePListP(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile List* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddRedBlackTreeQueue(HashTable *dataStructure, RedBlackTree key, Queue value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline HashTableNode* htAddRedBlackTreeQueueP(HashTable *dataStructure, RedBlackTree key, const volatile Queue* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddRedBlackTreePQueue(HashTable *dataStructure, const volatile RedBlackTree* key, Queue value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddRedBlackTreePQueueP(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddRedBlackTreeStack(HashTable *dataStructure, RedBlackTree key, Stack value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeStack);
}
static inline HashTableNode* htAddRedBlackTreeStackP(HashTable *dataStructure, RedBlackTree key, const volatile Stack* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddRedBlackTreePStack(HashTable *dataStructure, const volatile RedBlackTree* key, Stack value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddRedBlackTreePStackP(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddRedBlackTreeRedBlackTree(HashTable *dataStructure, RedBlackTree key, RedBlackTree value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddRedBlackTreeRedBlackTreeP(HashTable *dataStructure, RedBlackTree key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddRedBlackTreePRedBlackTree(HashTable *dataStructure, const volatile RedBlackTree* key, RedBlackTree value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddRedBlackTreePRedBlackTreeP(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddRedBlackTreeHashTable(HashTable *dataStructure, RedBlackTree key, HashTable value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline HashTableNode* htAddRedBlackTreeHashTableP(HashTable *dataStructure, RedBlackTree key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddRedBlackTreePHashTable(HashTable *dataStructure, const volatile RedBlackTree* key, HashTable value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddRedBlackTreePHashTableP(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddRedBlackTreeVector(HashTable *dataStructure, RedBlackTree key, Vector value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeVector);
}
static inline HashTableNode* htAddRedBlackTreeVectorP(HashTable *dataStructure, RedBlackTree key, const volatile Vector* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddRedBlackTreePVector(HashTable *dataStructure, const volatile RedBlackTree* key, Vector value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddRedBlackTreePVectorP(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddRedBlackTreeString(HashTable *dataStructure, RedBlackTree key, const volatile char* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeString);
}
static inline HashTableNode* htAddRedBlackTreeStringP(HashTable *dataStructure, RedBlackTree key, const volatile char** value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddRedBlackTreePString(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile char* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddRedBlackTreePStringP(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile char** value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddRedBlackTreeBytes(HashTable *dataStructure, RedBlackTree key, Bytes value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBytes);
}
static inline HashTableNode* htAddRedBlackTreeBytesP(HashTable *dataStructure, RedBlackTree key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddRedBlackTreePBytes(HashTable *dataStructure, const volatile RedBlackTree* key, Bytes value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddRedBlackTreePBytesP(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddRedBlackTreePointer(HashTable *dataStructure, RedBlackTree key, void* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typePointer);
}
static inline HashTableNode* htAddRedBlackTreePointerP(HashTable *dataStructure, RedBlackTree key, const volatile void** value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddRedBlackTreePPointer(HashTable *dataStructure, const volatile RedBlackTree* key, void* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddRedBlackTreePPointerP(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile void** value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddRedBlackTreeI8(HashTable *dataStructure, RedBlackTree key, i8 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI8);
}
static inline HashTableNode* htAddRedBlackTreePI8(HashTable *dataStructure, const volatile RedBlackTree* key, i8 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddRedBlackTreeU8(HashTable *dataStructure, RedBlackTree key, u8 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU8);
}
static inline HashTableNode* htAddRedBlackTreePU8(HashTable *dataStructure, const volatile RedBlackTree* key, u8 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}
static inline HashTableNode* htAddHashTableBool(HashTable *dataStructure, HashTable key, bool value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeBool);
}
static inline HashTableNode* htAddHashTableBoolP(HashTable *dataStructure, HashTable key, const volatile bool* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddHashTablePBool(HashTable *dataStructure, const volatile HashTable* key, bool value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddHashTablePBoolP(HashTable *dataStructure, const volatile HashTable* key, const volatile bool* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddHashTableI16(HashTable *dataStructure, HashTable key, i16 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI16);
}
static inline HashTableNode* htAddHashTableI16P(HashTable *dataStructure, HashTable key, const volatile i16* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddHashTablePI16(HashTable *dataStructure, const volatile HashTable* key, i16 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddHashTablePI16P(HashTable *dataStructure, const volatile HashTable* key, const volatile i16* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddHashTableU16(HashTable *dataStructure, HashTable key, u16 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU16);
}
static inline HashTableNode* htAddHashTableU16P(HashTable *dataStructure, HashTable key, const volatile u16* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddHashTablePU16(HashTable *dataStructure, const volatile HashTable* key, u16 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddHashTablePU16P(HashTable *dataStructure, const volatile HashTable* key, const volatile u16* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddHashTableI32(HashTable *dataStructure, HashTable key, i32 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI32);
}
static inline HashTableNode* htAddHashTableI32P(HashTable *dataStructure, HashTable key, const volatile i32* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddHashTablePI32(HashTable *dataStructure, const volatile HashTable* key, i32 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddHashTablePI32P(HashTable *dataStructure, const volatile HashTable* key, const volatile i32* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddHashTableU32(HashTable *dataStructure, HashTable key, u32 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU32);
}
static inline HashTableNode* htAddHashTableU32P(HashTable *dataStructure, HashTable key, const volatile u32* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddHashTablePU32(HashTable *dataStructure, const volatile HashTable* key, u32 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddHashTablePU32P(HashTable *dataStructure, const volatile HashTable* key, const volatile u32* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddHashTableI64(HashTable *dataStructure, HashTable key, i64 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI64);
}
static inline HashTableNode* htAddHashTableI64P(HashTable *dataStructure, HashTable key, const volatile i64* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddHashTablePI64(HashTable *dataStructure, const volatile HashTable* key, i64 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddHashTablePI64P(HashTable *dataStructure, const volatile HashTable* key, const volatile i64* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddHashTableU64(HashTable *dataStructure, HashTable key, u64 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU64);
}
static inline HashTableNode* htAddHashTableU64P(HashTable *dataStructure, HashTable key, const volatile u64* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddHashTablePU64(HashTable *dataStructure, const volatile HashTable* key, u64 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddHashTablePU64P(HashTable *dataStructure, const volatile HashTable* key, const volatile u64* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddHashTableFloat(HashTable *dataStructure, HashTable key, float value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline HashTableNode* htAddHashTableFloatP(HashTable *dataStructure, HashTable key, const volatile float* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddHashTablePFloat(HashTable *dataStructure, const volatile HashTable* key, float value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddHashTablePFloatP(HashTable *dataStructure, const volatile HashTable* key, const volatile float* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddHashTableDouble(HashTable *dataStructure, HashTable key, double value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline HashTableNode* htAddHashTableDoubleP(HashTable *dataStructure, HashTable key, const volatile double* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddHashTablePDouble(HashTable *dataStructure, const volatile HashTable* key, double value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddHashTablePDoubleP(HashTable *dataStructure, const volatile HashTable* key, const volatile double* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddHashTableLongDouble(HashTable *dataStructure, HashTable key, long double value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline HashTableNode* htAddHashTableLongDoubleP(HashTable *dataStructure, HashTable key, const volatile long double* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddHashTablePLongDouble(HashTable *dataStructure, const volatile HashTable* key, long double value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddHashTablePLongDoubleP(HashTable *dataStructure, const volatile HashTable* key, const volatile long double* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddHashTableList(HashTable *dataStructure, HashTable key, List value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeList);
}
static inline HashTableNode* htAddHashTableListP(HashTable *dataStructure, HashTable key, const volatile List* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline HashTableNode* htAddHashTablePList(HashTable *dataStructure, const volatile HashTable* key, List value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddHashTablePListP(HashTable *dataStructure, const volatile HashTable* key, const volatile List* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddHashTableQueue(HashTable *dataStructure, HashTable key, Queue value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline HashTableNode* htAddHashTableQueueP(HashTable *dataStructure, HashTable key, const volatile Queue* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddHashTablePQueue(HashTable *dataStructure, const volatile HashTable* key, Queue value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddHashTablePQueueP(HashTable *dataStructure, const volatile HashTable* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddHashTableStack(HashTable *dataStructure, HashTable key, Stack value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeStack);
}
static inline HashTableNode* htAddHashTableStackP(HashTable *dataStructure, HashTable key, const volatile Stack* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddHashTablePStack(HashTable *dataStructure, const volatile HashTable* key, Stack value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddHashTablePStackP(HashTable *dataStructure, const volatile HashTable* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddHashTableRedBlackTree(HashTable *dataStructure, HashTable key, RedBlackTree value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddHashTableRedBlackTreeP(HashTable *dataStructure, HashTable key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddHashTablePRedBlackTree(HashTable *dataStructure, const volatile HashTable* key, RedBlackTree value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddHashTablePRedBlackTreeP(HashTable *dataStructure, const volatile HashTable* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddHashTableHashTable(HashTable *dataStructure, HashTable key, HashTable value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline HashTableNode* htAddHashTableHashTableP(HashTable *dataStructure, HashTable key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddHashTablePHashTable(HashTable *dataStructure, const volatile HashTable* key, HashTable value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddHashTablePHashTableP(HashTable *dataStructure, const volatile HashTable* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddHashTableVector(HashTable *dataStructure, HashTable key, Vector value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeVector);
}
static inline HashTableNode* htAddHashTableVectorP(HashTable *dataStructure, HashTable key, const volatile Vector* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddHashTablePVector(HashTable *dataStructure, const volatile HashTable* key, Vector value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddHashTablePVectorP(HashTable *dataStructure, const volatile HashTable* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddHashTableString(HashTable *dataStructure, HashTable key, const volatile char* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeString);
}
static inline HashTableNode* htAddHashTableStringP(HashTable *dataStructure, HashTable key, const volatile char** value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddHashTablePString(HashTable *dataStructure, const volatile HashTable* key, const volatile char* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddHashTablePStringP(HashTable *dataStructure, const volatile HashTable* key, const volatile char** value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddHashTableBytes(HashTable *dataStructure, HashTable key, Bytes value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBytes);
}
static inline HashTableNode* htAddHashTableBytesP(HashTable *dataStructure, HashTable key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddHashTablePBytes(HashTable *dataStructure, const volatile HashTable* key, Bytes value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddHashTablePBytesP(HashTable *dataStructure, const volatile HashTable* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddHashTablePointer(HashTable *dataStructure, HashTable key, void* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typePointer);
}
static inline HashTableNode* htAddHashTablePointerP(HashTable *dataStructure, HashTable key, const volatile void** value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddHashTablePPointer(HashTable *dataStructure, const volatile HashTable* key, void* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddHashTablePPointerP(HashTable *dataStructure, const volatile HashTable* key, const volatile void** value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddHashTableI8(HashTable *dataStructure, HashTable key, i8 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI8);
}
static inline HashTableNode* htAddHashTablePI8(HashTable *dataStructure, const volatile HashTable* key, i8 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddHashTableU8(HashTable *dataStructure, HashTable key, u8 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU8);
}
static inline HashTableNode* htAddHashTablePU8(HashTable *dataStructure, const volatile HashTable* key, u8 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}
static inline HashTableNode* htAddVectorBool(HashTable *dataStructure, Vector key, bool value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeBool);
}
static inline HashTableNode* htAddVectorBoolP(HashTable *dataStructure, Vector key, const volatile bool* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddVectorPBool(HashTable *dataStructure, const volatile Vector* key, bool value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddVectorPBoolP(HashTable *dataStructure, const volatile Vector* key, const volatile bool* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddVectorI16(HashTable *dataStructure, Vector key, i16 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI16);
}
static inline HashTableNode* htAddVectorI16P(HashTable *dataStructure, Vector key, const volatile i16* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddVectorPI16(HashTable *dataStructure, const volatile Vector* key, i16 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddVectorPI16P(HashTable *dataStructure, const volatile Vector* key, const volatile i16* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddVectorU16(HashTable *dataStructure, Vector key, u16 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU16);
}
static inline HashTableNode* htAddVectorU16P(HashTable *dataStructure, Vector key, const volatile u16* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddVectorPU16(HashTable *dataStructure, const volatile Vector* key, u16 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddVectorPU16P(HashTable *dataStructure, const volatile Vector* key, const volatile u16* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddVectorI32(HashTable *dataStructure, Vector key, i32 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI32);
}
static inline HashTableNode* htAddVectorI32P(HashTable *dataStructure, Vector key, const volatile i32* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddVectorPI32(HashTable *dataStructure, const volatile Vector* key, i32 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddVectorPI32P(HashTable *dataStructure, const volatile Vector* key, const volatile i32* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddVectorU32(HashTable *dataStructure, Vector key, u32 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU32);
}
static inline HashTableNode* htAddVectorU32P(HashTable *dataStructure, Vector key, const volatile u32* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddVectorPU32(HashTable *dataStructure, const volatile Vector* key, u32 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddVectorPU32P(HashTable *dataStructure, const volatile Vector* key, const volatile u32* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddVectorI64(HashTable *dataStructure, Vector key, i64 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI64);
}
static inline HashTableNode* htAddVectorI64P(HashTable *dataStructure, Vector key, const volatile i64* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddVectorPI64(HashTable *dataStructure, const volatile Vector* key, i64 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddVectorPI64P(HashTable *dataStructure, const volatile Vector* key, const volatile i64* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddVectorU64(HashTable *dataStructure, Vector key, u64 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU64);
}
static inline HashTableNode* htAddVectorU64P(HashTable *dataStructure, Vector key, const volatile u64* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddVectorPU64(HashTable *dataStructure, const volatile Vector* key, u64 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddVectorPU64P(HashTable *dataStructure, const volatile Vector* key, const volatile u64* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddVectorFloat(HashTable *dataStructure, Vector key, float value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline HashTableNode* htAddVectorFloatP(HashTable *dataStructure, Vector key, const volatile float* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddVectorPFloat(HashTable *dataStructure, const volatile Vector* key, float value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddVectorPFloatP(HashTable *dataStructure, const volatile Vector* key, const volatile float* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddVectorDouble(HashTable *dataStructure, Vector key, double value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline HashTableNode* htAddVectorDoubleP(HashTable *dataStructure, Vector key, const volatile double* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddVectorPDouble(HashTable *dataStructure, const volatile Vector* key, double value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddVectorPDoubleP(HashTable *dataStructure, const volatile Vector* key, const volatile double* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddVectorLongDouble(HashTable *dataStructure, Vector key, long double value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline HashTableNode* htAddVectorLongDoubleP(HashTable *dataStructure, Vector key, const volatile long double* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddVectorPLongDouble(HashTable *dataStructure, const volatile Vector* key, long double value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddVectorPLongDoubleP(HashTable *dataStructure, const volatile Vector* key, const volatile long double* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddVectorList(HashTable *dataStructure, Vector key, List value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeList);
}
static inline HashTableNode* htAddVectorListP(HashTable *dataStructure, Vector key, const volatile List* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline HashTableNode* htAddVectorPList(HashTable *dataStructure, const volatile Vector* key, List value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddVectorPListP(HashTable *dataStructure, const volatile Vector* key, const volatile List* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddVectorQueue(HashTable *dataStructure, Vector key, Queue value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline HashTableNode* htAddVectorQueueP(HashTable *dataStructure, Vector key, const volatile Queue* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddVectorPQueue(HashTable *dataStructure, const volatile Vector* key, Queue value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddVectorPQueueP(HashTable *dataStructure, const volatile Vector* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddVectorStack(HashTable *dataStructure, Vector key, Stack value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeStack);
}
static inline HashTableNode* htAddVectorStackP(HashTable *dataStructure, Vector key, const volatile Stack* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddVectorPStack(HashTable *dataStructure, const volatile Vector* key, Stack value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddVectorPStackP(HashTable *dataStructure, const volatile Vector* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddVectorRedBlackTree(HashTable *dataStructure, Vector key, RedBlackTree value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddVectorRedBlackTreeP(HashTable *dataStructure, Vector key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddVectorPRedBlackTree(HashTable *dataStructure, const volatile Vector* key, RedBlackTree value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddVectorPRedBlackTreeP(HashTable *dataStructure, const volatile Vector* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddVectorHashTable(HashTable *dataStructure, Vector key, HashTable value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline HashTableNode* htAddVectorHashTableP(HashTable *dataStructure, Vector key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddVectorPHashTable(HashTable *dataStructure, const volatile Vector* key, HashTable value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddVectorPHashTableP(HashTable *dataStructure, const volatile Vector* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddVectorVector(HashTable *dataStructure, Vector key, Vector value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeVector);
}
static inline HashTableNode* htAddVectorVectorP(HashTable *dataStructure, Vector key, const volatile Vector* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddVectorPVector(HashTable *dataStructure, const volatile Vector* key, Vector value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddVectorPVectorP(HashTable *dataStructure, const volatile Vector* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddVectorString(HashTable *dataStructure, Vector key, const volatile char* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeString);
}
static inline HashTableNode* htAddVectorStringP(HashTable *dataStructure, Vector key, const volatile char** value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddVectorPString(HashTable *dataStructure, const volatile Vector* key, const volatile char* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddVectorPStringP(HashTable *dataStructure, const volatile Vector* key, const volatile char** value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddVectorBytes(HashTable *dataStructure, Vector key, Bytes value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBytes);
}
static inline HashTableNode* htAddVectorBytesP(HashTable *dataStructure, Vector key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddVectorPBytes(HashTable *dataStructure, const volatile Vector* key, Bytes value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddVectorPBytesP(HashTable *dataStructure, const volatile Vector* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddVectorPointer(HashTable *dataStructure, Vector key, void* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typePointer);
}
static inline HashTableNode* htAddVectorPointerP(HashTable *dataStructure, Vector key, const volatile void** value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddVectorPPointer(HashTable *dataStructure, const volatile Vector* key, void* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddVectorPPointerP(HashTable *dataStructure, const volatile Vector* key, const volatile void** value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddVectorI8(HashTable *dataStructure, Vector key, i8 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI8);
}
static inline HashTableNode* htAddVectorPI8(HashTable *dataStructure, const volatile Vector* key, i8 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddVectorU8(HashTable *dataStructure, Vector key, u8 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU8);
}
static inline HashTableNode* htAddVectorPU8(HashTable *dataStructure, const volatile Vector* key, u8 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}

static inline HashTableNode* htAddStringBool(HashTable *dataStructure, const volatile char* key, bool value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddStringBoolP(HashTable *dataStructure, const volatile char* key, const volatile bool* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddStringPBool(HashTable *dataStructure, const volatile char** key, bool value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeBool);
}
static inline HashTableNode* htAddStringPBoolP(HashTable *dataStructure, const volatile char** key, const volatile bool* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddStringI16(HashTable *dataStructure, const volatile char* key, i16 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddStringI16P(HashTable *dataStructure, const volatile char* key, const volatile i16* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddStringPI16(HashTable *dataStructure, const volatile char** key, i16 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeI16);
}
static inline HashTableNode* htAddStringPI16P(HashTable *dataStructure, const volatile char** key, const volatile i16* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddStringU16(HashTable *dataStructure, const volatile char* key, u16 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddStringU16P(HashTable *dataStructure, const volatile char* key, const volatile u16* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddStringPU16(HashTable *dataStructure, const volatile char** key, u16 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeU16);
}
static inline HashTableNode* htAddStringPU16P(HashTable *dataStructure, const volatile char** key, const volatile u16* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddStringI32(HashTable *dataStructure, const volatile char* key, i32 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddStringI32P(HashTable *dataStructure, const volatile char* key, const volatile i32* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddStringPI32(HashTable *dataStructure, const volatile char** key, i32 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeI32);
}
static inline HashTableNode* htAddStringPI32P(HashTable *dataStructure, const volatile char** key, const volatile i32* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddStringU32(HashTable *dataStructure, const volatile char* key, u32 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddStringU32P(HashTable *dataStructure, const volatile char* key, const volatile u32* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddStringPU32(HashTable *dataStructure, const volatile char** key, u32 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeU32);
}
static inline HashTableNode* htAddStringPU32P(HashTable *dataStructure, const volatile char** key, const volatile u32* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddStringI64(HashTable *dataStructure, const volatile char* key, i64 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddStringI64P(HashTable *dataStructure, const volatile char* key, const volatile i64* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddStringPI64(HashTable *dataStructure, const volatile char** key, i64 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeI64);
}
static inline HashTableNode* htAddStringPI64P(HashTable *dataStructure, const volatile char** key, const volatile i64* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddStringU64(HashTable *dataStructure, const volatile char* key, u64 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddStringU64P(HashTable *dataStructure, const volatile char* key, const volatile u64* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddStringPU64(HashTable *dataStructure, const volatile char** key, u64 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeU64);
}
static inline HashTableNode* htAddStringPU64P(HashTable *dataStructure, const volatile char** key, const volatile u64* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddStringFloat(HashTable *dataStructure, const volatile char* key, float value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddStringFloatP(HashTable *dataStructure, const volatile char* key, const volatile float* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddStringPFloat(HashTable *dataStructure, const volatile char** key, float value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeFloat);
}
static inline HashTableNode* htAddStringPFloatP(HashTable *dataStructure, const volatile char** key, const volatile float* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddStringDouble(HashTable *dataStructure, const volatile char* key, double value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddStringDoubleP(HashTable *dataStructure, const volatile char* key, const volatile double* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddStringPDouble(HashTable *dataStructure, const volatile char** key, double value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeDouble);
}
static inline HashTableNode* htAddStringPDoubleP(HashTable *dataStructure, const volatile char** key, const volatile double* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddStringLongDouble(HashTable *dataStructure, const volatile char* key, long double value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddStringLongDoubleP(HashTable *dataStructure, const volatile char* key, const volatile long double* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddStringPLongDouble(HashTable *dataStructure, const volatile char** key, long double value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeLongDouble);
}
static inline HashTableNode* htAddStringPLongDoubleP(HashTable *dataStructure, const volatile char** key, const volatile long double* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddStringList(HashTable *dataStructure, const volatile char* key, List value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddStringListP(HashTable *dataStructure, const volatile char* key, const volatile List* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddStringPList(HashTable *dataStructure, const volatile char** key, List value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeList);
}
static inline HashTableNode* htAddStringPListP(HashTable *dataStructure, const volatile char** key, const volatile List* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeListNoCopy);
}
static inline HashTableNode* htAddStringQueue(HashTable *dataStructure, const volatile char* key, Queue value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddStringQueueP(HashTable *dataStructure, const volatile char* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddStringPQueue(HashTable *dataStructure, const volatile char** key, Queue value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeQueue);
}
static inline HashTableNode* htAddStringPQueueP(HashTable *dataStructure, const volatile char** key, const volatile Queue* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddStringStack(HashTable *dataStructure, const volatile char* key, Stack value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddStringStackP(HashTable *dataStructure, const volatile char* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddStringPStack(HashTable *dataStructure, const volatile char** key, Stack value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeStack);
}
static inline HashTableNode* htAddStringPStackP(HashTable *dataStructure, const volatile char** key, const volatile Stack* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddStringRedBlackTree(HashTable *dataStructure, const volatile char* key, RedBlackTree value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddStringRedBlackTreeP(HashTable *dataStructure, const volatile char* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddStringPRedBlackTree(HashTable *dataStructure, const volatile char** key, RedBlackTree value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddStringPRedBlackTreeP(HashTable *dataStructure, const volatile char** key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddStringHashTable(HashTable *dataStructure, const volatile char* key, HashTable value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddStringHashTableP(HashTable *dataStructure, const volatile char* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddStringPHashTable(HashTable *dataStructure, const volatile char** key, HashTable value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeHashTable);
}
static inline HashTableNode* htAddStringPHashTableP(HashTable *dataStructure, const volatile char** key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddStringVector(HashTable *dataStructure, const volatile char* key, Vector value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddStringVectorP(HashTable *dataStructure, const volatile char* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddStringPVector(HashTable *dataStructure, const volatile char** key, Vector value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeVector);
}
static inline HashTableNode* htAddStringPVectorP(HashTable *dataStructure, const volatile char** key, const volatile Vector* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddStringString(HashTable *dataStructure, const volatile char* key, const volatile char* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddStringStringP(HashTable *dataStructure, const volatile char* key, const volatile char** value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddStringPString(HashTable *dataStructure, const volatile char** key, const volatile char* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeString);
}
static inline HashTableNode* htAddStringPStringP(HashTable *dataStructure, const volatile char** key, const volatile char** value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddStringBytes(HashTable *dataStructure, const volatile char* key, Bytes value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddStringBytesP(HashTable *dataStructure, const volatile char* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddStringPBytes(HashTable *dataStructure, const volatile char** key, Bytes value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeBytes);
}
static inline HashTableNode* htAddStringPBytesP(HashTable *dataStructure, const volatile char** key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddStringPointer(HashTable *dataStructure, const volatile char* key, void* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddStringPointerP(HashTable *dataStructure, const volatile char* key, const volatile void** value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddStringPPointer(HashTable *dataStructure, const volatile char** key, void* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typePointer);
}
static inline HashTableNode* htAddStringPPointerP(HashTable *dataStructure, const volatile char** key, const volatile void** value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddStringI8(HashTable *dataStructure, const volatile char* key, i8 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddStringPI8(HashTable *dataStructure, const volatile char** key, i8 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeI8);
}
static inline HashTableNode* htAddStringU8(HashTable *dataStructure, const volatile char* key, u8 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}
static inline HashTableNode* htAddStringPU8(HashTable *dataStructure, const volatile char** key, u8 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeU8);
}

static inline HashTableNode* htAddBytesBool(HashTable *dataStructure, Bytes key, bool value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddBytesBoolP(HashTable *dataStructure, Bytes key, const volatile bool* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddBytesPBool(HashTable *dataStructure, const volatile Bytes* key, bool value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeBool);
}
static inline HashTableNode* htAddBytesPBoolP(HashTable *dataStructure, const volatile Bytes* key, const volatile bool* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddBytesI16(HashTable *dataStructure, Bytes key, i16 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddBytesI16P(HashTable *dataStructure, Bytes key, const volatile i16* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddBytesPI16(HashTable *dataStructure, const volatile Bytes* key, i16 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeI16);
}
static inline HashTableNode* htAddBytesPI16P(HashTable *dataStructure, const volatile Bytes* key, const volatile i16* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddBytesU16(HashTable *dataStructure, Bytes key, u16 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddBytesU16P(HashTable *dataStructure, Bytes key, const volatile u16* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddBytesPU16(HashTable *dataStructure, const volatile Bytes* key, u16 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeU16);
}
static inline HashTableNode* htAddBytesPU16P(HashTable *dataStructure, const volatile Bytes* key, const volatile u16* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddBytesI32(HashTable *dataStructure, Bytes key, i32 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddBytesI32P(HashTable *dataStructure, Bytes key, const volatile i32* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddBytesPI32(HashTable *dataStructure, const volatile Bytes* key, i32 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeI32);
}
static inline HashTableNode* htAddBytesPI32P(HashTable *dataStructure, const volatile Bytes* key, const volatile i32* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddBytesU32(HashTable *dataStructure, Bytes key, u32 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddBytesU32P(HashTable *dataStructure, Bytes key, const volatile u32* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddBytesPU32(HashTable *dataStructure, const volatile Bytes* key, u32 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeU32);
}
static inline HashTableNode* htAddBytesPU32P(HashTable *dataStructure, const volatile Bytes* key, const volatile u32* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddBytesI64(HashTable *dataStructure, Bytes key, i64 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddBytesI64P(HashTable *dataStructure, Bytes key, const volatile i64* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddBytesPI64(HashTable *dataStructure, const volatile Bytes* key, i64 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeI64);
}
static inline HashTableNode* htAddBytesPI64P(HashTable *dataStructure, const volatile Bytes* key, const volatile i64* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddBytesU64(HashTable *dataStructure, Bytes key, u64 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddBytesU64P(HashTable *dataStructure, Bytes key, const volatile u64* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddBytesPU64(HashTable *dataStructure, const volatile Bytes* key, u64 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeU64);
}
static inline HashTableNode* htAddBytesPU64P(HashTable *dataStructure, const volatile Bytes* key, const volatile u64* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddBytesFloat(HashTable *dataStructure, Bytes key, float value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddBytesFloatP(HashTable *dataStructure, Bytes key, const volatile float* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddBytesPFloat(HashTable *dataStructure, const volatile Bytes* key, float value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeFloat);
}
static inline HashTableNode* htAddBytesPFloatP(HashTable *dataStructure, const volatile Bytes* key, const volatile float* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddBytesDouble(HashTable *dataStructure, Bytes key, double value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddBytesDoubleP(HashTable *dataStructure, Bytes key, const volatile double* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddBytesPDouble(HashTable *dataStructure, const volatile Bytes* key, double value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeDouble);
}
static inline HashTableNode* htAddBytesPDoubleP(HashTable *dataStructure, const volatile Bytes* key, const volatile double* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddBytesLongDouble(HashTable *dataStructure, Bytes key, long double value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddBytesLongDoubleP(HashTable *dataStructure, Bytes key, const volatile long double* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddBytesPLongDouble(HashTable *dataStructure, const volatile Bytes* key, long double value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeLongDouble);
}
static inline HashTableNode* htAddBytesPLongDoubleP(HashTable *dataStructure, const volatile Bytes* key, const volatile long double* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddBytesList(HashTable *dataStructure, Bytes key, List value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddBytesListP(HashTable *dataStructure, Bytes key, const volatile List* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddBytesPList(HashTable *dataStructure, const volatile Bytes* key, List value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeList);
}
static inline HashTableNode* htAddBytesPListP(HashTable *dataStructure, const volatile Bytes* key, const volatile List* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeListNoCopy);
}
static inline HashTableNode* htAddBytesQueue(HashTable *dataStructure, Bytes key, Queue value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddBytesQueueP(HashTable *dataStructure, Bytes key, const volatile Queue* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddBytesPQueue(HashTable *dataStructure, const volatile Bytes* key, Queue value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeQueue);
}
static inline HashTableNode* htAddBytesPQueueP(HashTable *dataStructure, const volatile Bytes* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddBytesStack(HashTable *dataStructure, Bytes key, Stack value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddBytesStackP(HashTable *dataStructure, Bytes key, const volatile Stack* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddBytesPStack(HashTable *dataStructure, const volatile Bytes* key, Stack value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeStack);
}
static inline HashTableNode* htAddBytesPStackP(HashTable *dataStructure, const volatile Bytes* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddBytesRedBlackTree(HashTable *dataStructure, Bytes key, RedBlackTree value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddBytesRedBlackTreeP(HashTable *dataStructure, Bytes key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddBytesPRedBlackTree(HashTable *dataStructure, const volatile Bytes* key, RedBlackTree value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddBytesPRedBlackTreeP(HashTable *dataStructure, const volatile Bytes* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddBytesHashTable(HashTable *dataStructure, Bytes key, HashTable value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddBytesHashTableP(HashTable *dataStructure, Bytes key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddBytesPHashTable(HashTable *dataStructure, const volatile Bytes* key, HashTable value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeHashTable);
}
static inline HashTableNode* htAddBytesPHashTableP(HashTable *dataStructure, const volatile Bytes* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddBytesVector(HashTable *dataStructure, Bytes key, Vector value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddBytesVectorP(HashTable *dataStructure, Bytes key, const volatile Vector* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddBytesPVector(HashTable *dataStructure, const volatile Bytes* key, Vector value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeVector);
}
static inline HashTableNode* htAddBytesPVectorP(HashTable *dataStructure, const volatile Bytes* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddBytesString(HashTable *dataStructure, Bytes key, const volatile char* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddBytesStringP(HashTable *dataStructure, Bytes key, const volatile char** value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddBytesPString(HashTable *dataStructure, const volatile Bytes* key, const volatile char* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeString);
}
static inline HashTableNode* htAddBytesPStringP(HashTable *dataStructure, const volatile Bytes* key, const volatile char** value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddBytesBytes(HashTable *dataStructure, Bytes key, Bytes value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddBytesBytesP(HashTable *dataStructure, Bytes key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddBytesPBytes(HashTable *dataStructure, const volatile Bytes* key, Bytes value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeBytes);
}
static inline HashTableNode* htAddBytesPBytesP(HashTable *dataStructure, const volatile Bytes* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddBytesPointer(HashTable *dataStructure, Bytes key, void* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddBytesPointerP(HashTable *dataStructure, Bytes key, const volatile void** value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddBytesPPointer(HashTable *dataStructure, const volatile Bytes* key, void* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typePointer);
}
static inline HashTableNode* htAddBytesPPointerP(HashTable *dataStructure, const volatile Bytes* key, const volatile void** value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddBytesI8(HashTable *dataStructure, Bytes key, i8 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddBytesPI8(HashTable *dataStructure, const volatile Bytes* key, i8 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeI8);
}
static inline HashTableNode* htAddBytesU8(HashTable *dataStructure, Bytes key, u8 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}
static inline HashTableNode* htAddBytesPU8(HashTable *dataStructure, const volatile Bytes* key, u8 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeU8);
}

static inline HashTableNode* htAddPointerBool(HashTable *dataStructure, void* key, bool value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeBool);
}
static inline HashTableNode* htAddPointerBoolP(HashTable *dataStructure, void* key, const volatile bool* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddPointerPBool(HashTable *dataStructure, const volatile void** key, bool value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeBool);
}
static inline HashTableNode* htAddPointerPBoolP(HashTable *dataStructure, const volatile void** key, const volatile bool* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddPointerI16(HashTable *dataStructure, void* key, i16 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI16);
}
static inline HashTableNode* htAddPointerI16P(HashTable *dataStructure, void* key, const volatile i16* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddPointerPI16(HashTable *dataStructure, const volatile void** key, i16 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeI16);
}
static inline HashTableNode* htAddPointerPI16P(HashTable *dataStructure, const volatile void** key, const volatile i16* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddPointerU16(HashTable *dataStructure, void* key, u16 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU16);
}
static inline HashTableNode* htAddPointerU16P(HashTable *dataStructure, void* key, const volatile u16* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddPointerPU16(HashTable *dataStructure, const volatile void** key, u16 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeU16);
}
static inline HashTableNode* htAddPointerPU16P(HashTable *dataStructure, const volatile void** key, const volatile u16* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddPointerI32(HashTable *dataStructure, void* key, i32 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI32);
}
static inline HashTableNode* htAddPointerI32P(HashTable *dataStructure, void* key, const volatile i32* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddPointerPI32(HashTable *dataStructure, const volatile void** key, i32 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeI32);
}
static inline HashTableNode* htAddPointerPI32P(HashTable *dataStructure, const volatile void** key, const volatile i32* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddPointerU32(HashTable *dataStructure, void* key, u32 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU32);
}
static inline HashTableNode* htAddPointerU32P(HashTable *dataStructure, void* key, const volatile u32* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddPointerPU32(HashTable *dataStructure, const volatile void** key, u32 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeU32);
}
static inline HashTableNode* htAddPointerPU32P(HashTable *dataStructure, const volatile void** key, const volatile u32* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddPointerI64(HashTable *dataStructure, void* key, i64 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI64);
}
static inline HashTableNode* htAddPointerI64P(HashTable *dataStructure, void* key, const volatile i64* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddPointerPI64(HashTable *dataStructure, const volatile void** key, i64 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeI64);
}
static inline HashTableNode* htAddPointerPI64P(HashTable *dataStructure, const volatile void** key, const volatile i64* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddPointerU64(HashTable *dataStructure, void* key, u64 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU64);
}
static inline HashTableNode* htAddPointerU64P(HashTable *dataStructure, void* key, const volatile u64* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddPointerPU64(HashTable *dataStructure, const volatile void** key, u64 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeU64);
}
static inline HashTableNode* htAddPointerPU64P(HashTable *dataStructure, const volatile void** key, const volatile u64* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddPointerFloat(HashTable *dataStructure, void* key, float value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeFloat);
}
static inline HashTableNode* htAddPointerFloatP(HashTable *dataStructure, void* key, const volatile float* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddPointerPFloat(HashTable *dataStructure, const volatile void** key, float value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeFloat);
}
static inline HashTableNode* htAddPointerPFloatP(HashTable *dataStructure, const volatile void** key, const volatile float* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddPointerDouble(HashTable *dataStructure, void* key, double value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeDouble);
}
static inline HashTableNode* htAddPointerDoubleP(HashTable *dataStructure, void* key, const volatile double* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddPointerPDouble(HashTable *dataStructure, const volatile void** key, double value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeDouble);
}
static inline HashTableNode* htAddPointerPDoubleP(HashTable *dataStructure, const volatile void** key, const volatile double* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddPointerLongDouble(HashTable *dataStructure, void* key, long double value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline HashTableNode* htAddPointerLongDoubleP(HashTable *dataStructure, void* key, const volatile long double* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddPointerPLongDouble(HashTable *dataStructure, const volatile void** key, long double value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeLongDouble);
}
static inline HashTableNode* htAddPointerPLongDoubleP(HashTable *dataStructure, const volatile void** key, const volatile long double* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddPointerList(HashTable *dataStructure, void* key, List value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeList);
}
static inline HashTableNode* htAddPointerListP(HashTable *dataStructure, void* key, const volatile List* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline HashTableNode* htAddPointerPList(HashTable *dataStructure, const volatile void** key, List value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeList);
}
static inline HashTableNode* htAddPointerPListP(HashTable *dataStructure, const volatile void** key, const volatile List* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeListNoCopy);
}
static inline HashTableNode* htAddPointerQueue(HashTable *dataStructure, void* key, Queue value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeQueue);
}
static inline HashTableNode* htAddPointerQueueP(HashTable *dataStructure, void* key, const volatile Queue* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddPointerPQueue(HashTable *dataStructure, const volatile void** key, Queue value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeQueue);
}
static inline HashTableNode* htAddPointerPQueueP(HashTable *dataStructure, const volatile void** key, const volatile Queue* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddPointerStack(HashTable *dataStructure, void* key, Stack value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeStack);
}
static inline HashTableNode* htAddPointerStackP(HashTable *dataStructure, void* key, const volatile Stack* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddPointerPStack(HashTable *dataStructure, const volatile void** key, Stack value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeStack);
}
static inline HashTableNode* htAddPointerPStackP(HashTable *dataStructure, const volatile void** key, const volatile Stack* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddPointerRedBlackTree(HashTable *dataStructure, void* key, RedBlackTree value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddPointerRedBlackTreeP(HashTable *dataStructure, void* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddPointerPRedBlackTree(HashTable *dataStructure, const volatile void** key, RedBlackTree value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddPointerPRedBlackTreeP(HashTable *dataStructure, const volatile void** key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddPointerHashTable(HashTable *dataStructure, void* key, HashTable value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline HashTableNode* htAddPointerHashTableP(HashTable *dataStructure, void* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddPointerPHashTable(HashTable *dataStructure, const volatile void** key, HashTable value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeHashTable);
}
static inline HashTableNode* htAddPointerPHashTableP(HashTable *dataStructure, const volatile void** key, const volatile HashTable* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddPointerVector(HashTable *dataStructure, void* key, Vector value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeVector);
}
static inline HashTableNode* htAddPointerVectorP(HashTable *dataStructure, void* key, const volatile Vector* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddPointerPVector(HashTable *dataStructure, const volatile void** key, Vector value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeVector);
}
static inline HashTableNode* htAddPointerPVectorP(HashTable *dataStructure, const volatile void** key, const volatile Vector* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddPointerString(HashTable *dataStructure, void* key, const volatile char* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeString);
}
static inline HashTableNode* htAddPointerStringP(HashTable *dataStructure, void* key, const volatile char** value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddPointerPString(HashTable *dataStructure, const volatile void** key, const volatile char* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeString);
}
static inline HashTableNode* htAddPointerPStringP(HashTable *dataStructure, const volatile void** key, const volatile char** value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddPointerBytes(HashTable *dataStructure, void* key, Bytes value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typeBytes);
}
static inline HashTableNode* htAddPointerBytesP(HashTable *dataStructure, void* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddPointerPBytes(HashTable *dataStructure, const volatile void** key, Bytes value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typeBytes);
}
static inline HashTableNode* htAddPointerPBytesP(HashTable *dataStructure, const volatile void** key, const volatile Bytes* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddPointerPointer(HashTable *dataStructure, void* key, void* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, value, typePointer);
}
static inline HashTableNode* htAddPointerPointerP(HashTable *dataStructure, void* key, const volatile void** value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddPointerPPointer(HashTable *dataStructure, const volatile void** key, void* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, value, typePointer);
}
static inline HashTableNode* htAddPointerPPointerP(HashTable *dataStructure, const volatile void** key, const volatile void** value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddPointerI8(HashTable *dataStructure, void* key, i8 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeI8);
}
static inline HashTableNode* htAddPointerPI8(HashTable *dataStructure, const volatile void** key, i8 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeI8);
}
static inline HashTableNode* htAddPointerU8(HashTable *dataStructure, void* key, u8 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, key, &value, typeU8);
}
static inline HashTableNode* htAddPointerPU8(HashTable *dataStructure, const volatile void** key, u8 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, *key, &value, typeU8);
}

static inline HashTableNode* htAddI8Bool(HashTable *dataStructure, i8 key, bool value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeBool);
}
static inline HashTableNode* htAddI8BoolP(HashTable *dataStructure, i8 key, const volatile bool* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddI8I16(HashTable *dataStructure, i8 key, i16 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI16);
}
static inline HashTableNode* htAddI8I16P(HashTable *dataStructure, i8 key, const volatile i16* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddI8U16(HashTable *dataStructure, i8 key, u16 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU16);
}
static inline HashTableNode* htAddI8U16P(HashTable *dataStructure, i8 key, const volatile u16* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddI8I32(HashTable *dataStructure, i8 key, i32 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI32);
}
static inline HashTableNode* htAddI8I32P(HashTable *dataStructure, i8 key, const volatile i32* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddI8U32(HashTable *dataStructure, i8 key, u32 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU32);
}
static inline HashTableNode* htAddI8U32P(HashTable *dataStructure, i8 key, const volatile u32* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddI8I64(HashTable *dataStructure, i8 key, i64 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI64);
}
static inline HashTableNode* htAddI8I64P(HashTable *dataStructure, i8 key, const volatile i64* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddI8U64(HashTable *dataStructure, i8 key, u64 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU64);
}
static inline HashTableNode* htAddI8U64P(HashTable *dataStructure, i8 key, const volatile u64* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddI8Float(HashTable *dataStructure, i8 key, float value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline HashTableNode* htAddI8FloatP(HashTable *dataStructure, i8 key, const volatile float* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddI8Double(HashTable *dataStructure, i8 key, double value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline HashTableNode* htAddI8DoubleP(HashTable *dataStructure, i8 key, const volatile double* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddI8LongDouble(HashTable *dataStructure, i8 key, long double value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline HashTableNode* htAddI8LongDoubleP(HashTable *dataStructure, i8 key, const volatile long double* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddI8List(HashTable *dataStructure, i8 key, List value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeList);
}
static inline HashTableNode* htAddI8ListP(HashTable *dataStructure, i8 key, const volatile List* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline HashTableNode* htAddI8Queue(HashTable *dataStructure, i8 key, Queue value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline HashTableNode* htAddI8QueueP(HashTable *dataStructure, i8 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddI8Stack(HashTable *dataStructure, i8 key, Stack value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeStack);
}
static inline HashTableNode* htAddI8StackP(HashTable *dataStructure, i8 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddI8RedBlackTree(HashTable *dataStructure, i8 key, RedBlackTree value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddI8RedBlackTreeP(HashTable *dataStructure, i8 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddI8HashTable(HashTable *dataStructure, i8 key, HashTable value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline HashTableNode* htAddI8HashTableP(HashTable *dataStructure, i8 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddI8Vector(HashTable *dataStructure, i8 key, Vector value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeVector);
}
static inline HashTableNode* htAddI8VectorP(HashTable *dataStructure, i8 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddI8String(HashTable *dataStructure, i8 key, const volatile char* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeString);
}
static inline HashTableNode* htAddI8StringP(HashTable *dataStructure, i8 key, const volatile char** value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddI8Bytes(HashTable *dataStructure, i8 key, Bytes value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBytes);
}
static inline HashTableNode* htAddI8BytesP(HashTable *dataStructure, i8 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddI8Pointer(HashTable *dataStructure, i8 key, void* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typePointer);
}
static inline HashTableNode* htAddI8PointerP(HashTable *dataStructure, i8 key, const volatile void** value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddI8I8(HashTable *dataStructure, i8 key, i8 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI8);
}
static inline HashTableNode* htAddI8U8(HashTable *dataStructure, i8 key, u8 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU8);
}

static inline HashTableNode* htAddU8Bool(HashTable *dataStructure, u8 key, bool value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeBool);
}
static inline HashTableNode* htAddU8BoolP(HashTable *dataStructure, u8 key, const volatile bool* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline HashTableNode* htAddU8I16(HashTable *dataStructure, u8 key, i16 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI16);
}
static inline HashTableNode* htAddU8I16P(HashTable *dataStructure, u8 key, const volatile i16* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline HashTableNode* htAddU8U16(HashTable *dataStructure, u8 key, u16 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU16);
}
static inline HashTableNode* htAddU8U16P(HashTable *dataStructure, u8 key, const volatile u16* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline HashTableNode* htAddU8I32(HashTable *dataStructure, u8 key, i32 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI32);
}
static inline HashTableNode* htAddU8I32P(HashTable *dataStructure, u8 key, const volatile i32* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline HashTableNode* htAddU8U32(HashTable *dataStructure, u8 key, u32 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU32);
}
static inline HashTableNode* htAddU8U32P(HashTable *dataStructure, u8 key, const volatile u32* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline HashTableNode* htAddU8I64(HashTable *dataStructure, u8 key, i64 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI64);
}
static inline HashTableNode* htAddU8I64P(HashTable *dataStructure, u8 key, const volatile i64* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline HashTableNode* htAddU8U64(HashTable *dataStructure, u8 key, u64 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU64);
}
static inline HashTableNode* htAddU8U64P(HashTable *dataStructure, u8 key, const volatile u64* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline HashTableNode* htAddU8Float(HashTable *dataStructure, u8 key, float value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline HashTableNode* htAddU8FloatP(HashTable *dataStructure, u8 key, const volatile float* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline HashTableNode* htAddU8Double(HashTable *dataStructure, u8 key, double value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline HashTableNode* htAddU8DoubleP(HashTable *dataStructure, u8 key, const volatile double* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline HashTableNode* htAddU8LongDouble(HashTable *dataStructure, u8 key, long double value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline HashTableNode* htAddU8LongDoubleP(HashTable *dataStructure, u8 key, const volatile long double* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline HashTableNode* htAddU8List(HashTable *dataStructure, u8 key, List value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeList);
}
static inline HashTableNode* htAddU8ListP(HashTable *dataStructure, u8 key, const volatile List* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline HashTableNode* htAddU8Queue(HashTable *dataStructure, u8 key, Queue value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline HashTableNode* htAddU8QueueP(HashTable *dataStructure, u8 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline HashTableNode* htAddU8Stack(HashTable *dataStructure, u8 key, Stack value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeStack);
}
static inline HashTableNode* htAddU8StackP(HashTable *dataStructure, u8 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline HashTableNode* htAddU8RedBlackTree(HashTable *dataStructure, u8 key, RedBlackTree value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline HashTableNode* htAddU8RedBlackTreeP(HashTable *dataStructure, u8 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline HashTableNode* htAddU8HashTable(HashTable *dataStructure, u8 key, HashTable value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline HashTableNode* htAddU8HashTableP(HashTable *dataStructure, u8 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline HashTableNode* htAddU8Vector(HashTable *dataStructure, u8 key, Vector value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeVector);
}
static inline HashTableNode* htAddU8VectorP(HashTable *dataStructure, u8 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline HashTableNode* htAddU8String(HashTable *dataStructure, u8 key, const volatile char* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeString);
}
static inline HashTableNode* htAddU8StringP(HashTable *dataStructure, u8 key, const volatile char** value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline HashTableNode* htAddU8Bytes(HashTable *dataStructure, u8 key, Bytes value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typeBytes);
}
static inline HashTableNode* htAddU8BytesP(HashTable *dataStructure, u8 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline HashTableNode* htAddU8Pointer(HashTable *dataStructure, u8 key, void* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, value, typePointer);
}
static inline HashTableNode* htAddU8PointerP(HashTable *dataStructure, u8 key, const volatile void** value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline HashTableNode* htAddU8I8(HashTable *dataStructure, u8 key, i8 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeI8);
}
static inline HashTableNode* htAddU8U8(HashTable *dataStructure, u8 key, u8 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return htAddEntry(dataStructure, &key, &value, typeU8);
}

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#if defined __STDC_VERSION__

#if __STDC_VERSION__ >= 201710L
#define TYPE_SAFE_HASH_TABLE

#define HT_ADD_GENERIC_CASES_BOOL_KEY(dataStructure, key, value) \
  bool:                  htAddBoolBool,                              \
  bool*:                 htAddBoolBoolP,                             \
  const volatile bool*:  htAddBoolBoolP,                             \
  i16:                   htAddBoolI16,                               \
  i16*:                  htAddBoolI16P,                              \
  const volatile i16*:   htAddBoolI16P,                              \
  u16:                   htAddBoolU16,                               \
  u16*:                  htAddBoolU16P,                              \
  const volatile u16*:   htAddBoolU16P,                              \
  i32:                   htAddBoolI32,                               \
  i32*:                  htAddBoolI32P,                              \
  const volatile i32*:   htAddBoolI32P,                              \
  u32:                   htAddBoolU32,                               \
  u32*:                  htAddBoolU32P,                              \
  const volatile u32*:   htAddBoolU32P,                              \
  i64:                   htAddBoolI64,                               \
  i64*:                  htAddBoolI64P,                              \
  const volatile i64*:   htAddBoolI64P,                              \
  u64:                   htAddBoolU64,                               \
  u64*:                  htAddBoolU64P,                              \
  const volatile u64*:   htAddBoolU64P,                              \
  float:                 htAddBoolFloat,                             \
  float*:                htAddBoolFloatP,                            \
  const volatile float*: htAddBoolFloatP,                            \
  double:                htAddBoolDouble,                            \
  double*:               htAddBoolDoubleP,                           \
  const volatile double*: htAddBoolDoubleP,                           \
  long double:           htAddBoolLongDouble,                        \
  long double*:          htAddBoolLongDoubleP,                       \
  const volatile long double*: htAddBoolLongDoubleP,                       \
  List:                  htAddBoolList,                              \
  List*:                 htAddBoolListP,                             \
  const volatile List*:  htAddBoolListP,                             \
  Queue:                 htAddBoolQueue,                             \
  Queue*:                htAddBoolQueueP,                            \
  const volatile Queue*: htAddBoolQueueP,                            \
  Stack:                 htAddBoolStack,                             \
  Stack*:                htAddBoolStackP,                            \
  const volatile Stack*: htAddBoolStackP,                            \
  RedBlackTree:          htAddBoolRedBlackTree,                      \
  RedBlackTree*:         htAddBoolRedBlackTreeP,                     \
  const volatile RedBlackTree*: htAddBoolRedBlackTreeP,                     \
  HashTable:             htAddBoolHashTable,                         \
  HashTable*:            htAddBoolHashTableP,                        \
  const volatile HashTable*: htAddBoolHashTableP,                        \
  Vector:                htAddBoolVector,                            \
  Vector*:               htAddBoolVectorP,                           \
  const volatile Vector*: htAddBoolVectorP,                           \
  char*:                 htAddBoolString,                            \
  const volatile char*:  htAddBoolString,                            \
  char**:                htAddBoolStringP,                           \
  const volatile char**: htAddBoolStringP,                           \
  Bytes:                 htAddBoolBytes,                             \
  Bytes*:                htAddBoolBytesP,                            \
  const volatile Bytes*: htAddBoolBytesP,                            \
  void*:                 htAddBoolPointer,                           \
  void**:                htAddBoolPointerP,                          \
  const volatile void**: htAddBoolPointerP,                          \
  i8:                    htAddBoolI8,                                \
  u8:                    htAddBoolU8                                 \

#define htAddBool(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_BOOL_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_I16_KEY(dataStructure, key, value) \
  bool:                  htAddI16Bool,                               \
  bool*:                 htAddI16BoolP,                              \
  const volatile bool*:  htAddI16BoolP,                              \
  i16:                   htAddI16I16,                                \
  i16*:                  htAddI16I16P,                               \
  const volatile i16*:   htAddI16I16P,                               \
  u16:                   htAddI16U16,                                \
  u16*:                  htAddI16U16P,                               \
  const volatile u16*:   htAddI16U16P,                               \
  i32:                   htAddI16I32,                                \
  i32*:                  htAddI16I32P,                               \
  const volatile i32*:   htAddI16I32P,                               \
  u32:                   htAddI16U32,                                \
  u32*:                  htAddI16U32P,                               \
  const volatile u32*:   htAddI16U32P,                               \
  i64:                   htAddI16I64,                                \
  i64*:                  htAddI16I64P,                               \
  const volatile i64*:   htAddI16I64P,                               \
  u64:                   htAddI16U64,                                \
  u64*:                  htAddI16U64P,                               \
  const volatile u64*:   htAddI16U64P,                               \
  float:                 htAddI16Float,                              \
  float*:                htAddI16FloatP,                             \
  const volatile float*: htAddI16FloatP,                             \
  double:                htAddI16Double,                             \
  double*:               htAddI16DoubleP,                            \
  const volatile double*: htAddI16DoubleP,                            \
  long double:           htAddI16LongDouble,                         \
  long double*:          htAddI16LongDoubleP,                        \
  const volatile long double*: htAddI16LongDoubleP,                        \
  List:                  htAddI16List,                               \
  List*:                 htAddI16ListP,                              \
  const volatile List*:  htAddI16ListP,                              \
  Queue:                 htAddI16Queue,                              \
  Queue*:                htAddI16QueueP,                             \
  const volatile Queue*: htAddI16QueueP,                             \
  Stack:                 htAddI16Stack,                              \
  Stack*:                htAddI16StackP,                             \
  const volatile Stack*: htAddI16StackP,                             \
  RedBlackTree:          htAddI16RedBlackTree,                       \
  RedBlackTree*:         htAddI16RedBlackTreeP,                      \
  const volatile RedBlackTree*: htAddI16RedBlackTreeP,                      \
  HashTable:             htAddI16HashTable,                          \
  HashTable*:            htAddI16HashTableP,                         \
  const volatile HashTable*: htAddI16HashTableP,                         \
  Vector:                htAddI16Vector,                             \
  Vector*:               htAddI16VectorP,                            \
  const volatile Vector*: htAddI16VectorP,                            \
  char*:                 htAddI16String,                             \
  const volatile char*:  htAddI16String,                             \
  char**:                htAddI16StringP,                            \
  const volatile char**: htAddI16StringP,                            \
  Bytes:                 htAddI16Bytes,                              \
  Bytes*:                htAddI16BytesP,                             \
  const volatile Bytes*: htAddI16BytesP,                             \
  void*:                 htAddI16Pointer,                            \
  void**:                htAddI16PointerP,                           \
  const volatile void**: htAddI16PointerP,                           \
  i8:                    htAddI16I8,                                 \
  u8:                    htAddI16U8                                  \

#define htAddI16(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_I16_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_U16_KEY(dataStructure, key, value) \
  bool:                  htAddU16Bool,                               \
  bool*:                 htAddU16BoolP,                              \
  const volatile bool*:  htAddU16BoolP,                              \
  i16:                   htAddU16I16,                                \
  i16*:                  htAddU16I16P,                               \
  const volatile i16*:   htAddU16I16P,                               \
  u16:                   htAddU16U16,                                \
  u16*:                  htAddU16U16P,                               \
  const volatile u16*:   htAddU16U16P,                               \
  i32:                   htAddU16I32,                                \
  i32*:                  htAddU16I32P,                               \
  const volatile i32*:   htAddU16I32P,                               \
  u32:                   htAddU16U32,                                \
  u32*:                  htAddU16U32P,                               \
  const volatile u32*:   htAddU16U32P,                               \
  i64:                   htAddU16I64,                                \
  i64*:                  htAddU16I64P,                               \
  const volatile i64*:   htAddU16I64P,                               \
  u64:                   htAddU16U64,                                \
  u64*:                  htAddU16U64P,                               \
  const volatile u64*:   htAddU16U64P,                               \
  float:                 htAddU16Float,                              \
  float*:                htAddU16FloatP,                             \
  const volatile float*: htAddU16FloatP,                             \
  double:                htAddU16Double,                             \
  double*:               htAddU16DoubleP,                            \
  const volatile double*: htAddU16DoubleP,                            \
  long double:           htAddU16LongDouble,                         \
  long double*:          htAddU16LongDoubleP,                        \
  const volatile long double*: htAddU16LongDoubleP,                        \
  List:                  htAddU16List,                               \
  List*:                 htAddU16ListP,                              \
  const volatile List*:  htAddU16ListP,                              \
  Queue:                 htAddU16Queue,                              \
  Queue*:                htAddU16QueueP,                             \
  const volatile Queue*: htAddU16QueueP,                             \
  Stack:                 htAddU16Stack,                              \
  Stack*:                htAddU16StackP,                             \
  const volatile Stack*: htAddU16StackP,                             \
  RedBlackTree:          htAddU16RedBlackTree,                       \
  RedBlackTree*:         htAddU16RedBlackTreeP,                      \
  const volatile RedBlackTree*: htAddU16RedBlackTreeP,                      \
  HashTable:             htAddU16HashTable,                          \
  HashTable*:            htAddU16HashTableP,                         \
  const volatile HashTable*: htAddU16HashTableP,                         \
  Vector:                htAddU16Vector,                             \
  Vector*:               htAddU16VectorP,                            \
  const volatile Vector*: htAddU16VectorP,                            \
  char*:                 htAddU16String,                             \
  const volatile char*:  htAddU16String,                             \
  char**:                htAddU16StringP,                            \
  const volatile char**: htAddU16StringP,                            \
  Bytes:                 htAddU16Bytes,                              \
  Bytes*:                htAddU16BytesP,                             \
  const volatile Bytes*: htAddU16BytesP,                             \
  void*:                 htAddU16Pointer,                            \
  void**:                htAddU16PointerP,                           \
  const volatile void**: htAddU16PointerP,                           \
  i8:                    htAddU16I8,                                 \
  u8:                    htAddU16U8                                  \

#define htAddU16(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_U16_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_I32_KEY(dataStructure, key, value) \
  bool:                  htAddI32Bool,                               \
  bool*:                 htAddI32BoolP,                              \
  const volatile bool*:  htAddI32BoolP,                              \
  i16:                   htAddI32I16,                                \
  i16*:                  htAddI32I16P,                               \
  const volatile i16*:   htAddI32I16P,                               \
  u16:                   htAddI32U16,                                \
  u16*:                  htAddI32U16P,                               \
  const volatile u16*:   htAddI32U16P,                               \
  i32:                   htAddI32I32,                                \
  i32*:                  htAddI32I32P,                               \
  const volatile i32*:   htAddI32I32P,                               \
  u32:                   htAddI32U32,                                \
  u32*:                  htAddI32U32P,                               \
  const volatile u32*:   htAddI32U32P,                               \
  i64:                   htAddI32I64,                                \
  i64*:                  htAddI32I64P,                               \
  const volatile i64*:   htAddI32I64P,                               \
  u64:                   htAddI32U64,                                \
  u64*:                  htAddI32U64P,                               \
  const volatile u64*:   htAddI32U64P,                               \
  float:                 htAddI32Float,                              \
  float*:                htAddI32FloatP,                             \
  const volatile float*: htAddI32FloatP,                             \
  double:                htAddI32Double,                             \
  double*:               htAddI32DoubleP,                            \
  const volatile double*: htAddI32DoubleP,                            \
  long double:           htAddI32LongDouble,                         \
  long double*:          htAddI32LongDoubleP,                        \
  const volatile long double*: htAddI32LongDoubleP,                        \
  List:                  htAddI32List,                               \
  List*:                 htAddI32ListP,                              \
  const volatile List*:  htAddI32ListP,                              \
  Queue:                 htAddI32Queue,                              \
  Queue*:                htAddI32QueueP,                             \
  const volatile Queue*: htAddI32QueueP,                             \
  Stack:                 htAddI32Stack,                              \
  Stack*:                htAddI32StackP,                             \
  const volatile Stack*: htAddI32StackP,                             \
  RedBlackTree:          htAddI32RedBlackTree,                       \
  RedBlackTree*:         htAddI32RedBlackTreeP,                      \
  const volatile RedBlackTree*: htAddI32RedBlackTreeP,                      \
  HashTable:             htAddI32HashTable,                          \
  HashTable*:            htAddI32HashTableP,                         \
  const volatile HashTable*: htAddI32HashTableP,                         \
  Vector:                htAddI32Vector,                             \
  Vector*:               htAddI32VectorP,                            \
  const volatile Vector*: htAddI32VectorP,                            \
  char*:                 htAddI32String,                             \
  const volatile char*:  htAddI32String,                             \
  char**:                htAddI32StringP,                            \
  const volatile char**: htAddI32StringP,                            \
  Bytes:                 htAddI32Bytes,                              \
  Bytes*:                htAddI32BytesP,                             \
  const volatile Bytes*: htAddI32BytesP,                             \
  void*:                 htAddI32Pointer,                            \
  void**:                htAddI32PointerP,                           \
  const volatile void**: htAddI32PointerP,                           \
  i8:                    htAddI32I8,                                 \
  u8:                    htAddI32U8                                  \

#define htAddI32(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_I32_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_U32_KEY(dataStructure, key, value) \
  bool:                  htAddU32Bool,                               \
  bool*:                 htAddU32BoolP,                              \
  const volatile bool*:  htAddU32BoolP,                              \
  i16:                   htAddU32I16,                                \
  i16*:                  htAddU32I16P,                               \
  const volatile i16*:   htAddU32I16P,                               \
  u16:                   htAddU32U16,                                \
  u16*:                  htAddU32U16P,                               \
  const volatile u16*:   htAddU32U16P,                               \
  i32:                   htAddU32I32,                                \
  i32*:                  htAddU32I32P,                               \
  const volatile i32*:   htAddU32I32P,                               \
  u32:                   htAddU32U32,                                \
  u32*:                  htAddU32U32P,                               \
  const volatile u32*:   htAddU32U32P,                               \
  i64:                   htAddU32I64,                                \
  i64*:                  htAddU32I64P,                               \
  const volatile i64*:   htAddU32I64P,                               \
  u64:                   htAddU32U64,                                \
  u64*:                  htAddU32U64P,                               \
  const volatile u64*:   htAddU32U64P,                               \
  float:                 htAddU32Float,                              \
  float*:                htAddU32FloatP,                             \
  const volatile float*: htAddU32FloatP,                             \
  double:                htAddU32Double,                             \
  double*:               htAddU32DoubleP,                            \
  const volatile double*: htAddU32DoubleP,                            \
  long double:           htAddU32LongDouble,                         \
  long double*:          htAddU32LongDoubleP,                        \
  const volatile long double*: htAddU32LongDoubleP,                        \
  List:                  htAddU32List,                               \
  List*:                 htAddU32ListP,                              \
  const volatile List*:  htAddU32ListP,                              \
  Queue:                 htAddU32Queue,                              \
  Queue*:                htAddU32QueueP,                             \
  const volatile Queue*: htAddU32QueueP,                             \
  Stack:                 htAddU32Stack,                              \
  Stack*:                htAddU32StackP,                             \
  const volatile Stack*: htAddU32StackP,                             \
  RedBlackTree:          htAddU32RedBlackTree,                       \
  RedBlackTree*:         htAddU32RedBlackTreeP,                      \
  const volatile RedBlackTree*: htAddU32RedBlackTreeP,                      \
  HashTable:             htAddU32HashTable,                          \
  HashTable*:            htAddU32HashTableP,                         \
  const volatile HashTable*: htAddU32HashTableP,                         \
  Vector:                htAddU32Vector,                             \
  Vector*:               htAddU32VectorP,                            \
  const volatile Vector*: htAddU32VectorP,                            \
  char*:                 htAddU32String,                             \
  const volatile char*:  htAddU32String,                             \
  char**:                htAddU32StringP,                            \
  const volatile char**: htAddU32StringP,                            \
  Bytes:                 htAddU32Bytes,                              \
  Bytes*:                htAddU32BytesP,                             \
  const volatile Bytes*: htAddU32BytesP,                             \
  void*:                 htAddU32Pointer,                            \
  void**:                htAddU32PointerP,                           \
  const volatile void**: htAddU32PointerP,                           \
  i8:                    htAddU32I8,                                 \
  u8:                    htAddU32U8                                  \

#define htAddU32(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_U32_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_I64_KEY(dataStructure, key, value) \
  bool:                  htAddI64Bool,                               \
  bool*:                 htAddI64BoolP,                              \
  const volatile bool*:  htAddI64BoolP,                              \
  i16:                   htAddI64I16,                                \
  i16*:                  htAddI64I16P,                               \
  const volatile i16*:   htAddI64I16P,                               \
  u16:                   htAddI64U16,                                \
  u16*:                  htAddI64U16P,                               \
  const volatile u16*:   htAddI64U16P,                               \
  i32:                   htAddI64I32,                                \
  i32*:                  htAddI64I32P,                               \
  const volatile i32*:   htAddI64I32P,                               \
  u32:                   htAddI64U32,                                \
  u32*:                  htAddI64U32P,                               \
  const volatile u32*:   htAddI64U32P,                               \
  i64:                   htAddI64I64,                                \
  i64*:                  htAddI64I64P,                               \
  const volatile i64*:   htAddI64I64P,                               \
  u64:                   htAddI64U64,                                \
  u64*:                  htAddI64U64P,                               \
  const volatile u64*:   htAddI64U64P,                               \
  float:                 htAddI64Float,                              \
  float*:                htAddI64FloatP,                             \
  const volatile float*: htAddI64FloatP,                             \
  double:                htAddI64Double,                             \
  double*:               htAddI64DoubleP,                            \
  const volatile double*: htAddI64DoubleP,                            \
  long double:           htAddI64LongDouble,                         \
  long double*:          htAddI64LongDoubleP,                        \
  const volatile long double*: htAddI64LongDoubleP,                        \
  List:                  htAddI64List,                               \
  List*:                 htAddI64ListP,                              \
  const volatile List*:  htAddI64ListP,                              \
  Queue:                 htAddI64Queue,                              \
  Queue*:                htAddI64QueueP,                             \
  const volatile Queue*: htAddI64QueueP,                             \
  Stack:                 htAddI64Stack,                              \
  Stack*:                htAddI64StackP,                             \
  const volatile Stack*: htAddI64StackP,                             \
  RedBlackTree:          htAddI64RedBlackTree,                       \
  RedBlackTree*:         htAddI64RedBlackTreeP,                      \
  const volatile RedBlackTree*: htAddI64RedBlackTreeP,                      \
  HashTable:             htAddI64HashTable,                          \
  HashTable*:            htAddI64HashTableP,                         \
  const volatile HashTable*: htAddI64HashTableP,                         \
  Vector:                htAddI64Vector,                             \
  Vector*:               htAddI64VectorP,                            \
  const volatile Vector*: htAddI64VectorP,                            \
  char*:                 htAddI64String,                             \
  const volatile char*:  htAddI64String,                             \
  char**:                htAddI64StringP,                            \
  const volatile char**: htAddI64StringP,                            \
  Bytes:                 htAddI64Bytes,                              \
  Bytes*:                htAddI64BytesP,                             \
  const volatile Bytes*: htAddI64BytesP,                             \
  void*:                 htAddI64Pointer,                            \
  void**:                htAddI64PointerP,                           \
  const volatile void**: htAddI64PointerP,                           \
  i8:                    htAddI64I8,                                 \
  u8:                    htAddI64U8                                  \

#define htAddI64(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_I64_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_U64_KEY(dataStructure, key, value) \
  bool:                  htAddU64Bool,                               \
  bool*:                 htAddU64BoolP,                              \
  const volatile bool*:  htAddU64BoolP,                              \
  i16:                   htAddU64I16,                                \
  i16*:                  htAddU64I16P,                               \
  const volatile i16*:   htAddU64I16P,                               \
  u16:                   htAddU64U16,                                \
  u16*:                  htAddU64U16P,                               \
  const volatile u16*:   htAddU64U16P,                               \
  i32:                   htAddU64I32,                                \
  i32*:                  htAddU64I32P,                               \
  const volatile i32*:   htAddU64I32P,                               \
  u32:                   htAddU64U32,                                \
  u32*:                  htAddU64U32P,                               \
  const volatile u32*:   htAddU64U32P,                               \
  i64:                   htAddU64I64,                                \
  i64*:                  htAddU64I64P,                               \
  const volatile i64*:   htAddU64I64P,                               \
  u64:                   htAddU64U64,                                \
  u64*:                  htAddU64U64P,                               \
  const volatile u64*:   htAddU64U64P,                               \
  float:                 htAddU64Float,                              \
  float*:                htAddU64FloatP,                             \
  const volatile float*: htAddU64FloatP,                             \
  double:                htAddU64Double,                             \
  double*:               htAddU64DoubleP,                            \
  const volatile double*: htAddU64DoubleP,                            \
  long double:           htAddU64LongDouble,                         \
  long double*:          htAddU64LongDoubleP,                        \
  const volatile long double*: htAddU64LongDoubleP,                        \
  List:                  htAddU64List,                               \
  List*:                 htAddU64ListP,                              \
  const volatile List*:  htAddU64ListP,                              \
  Queue:                 htAddU64Queue,                              \
  Queue*:                htAddU64QueueP,                             \
  const volatile Queue*: htAddU64QueueP,                             \
  Stack:                 htAddU64Stack,                              \
  Stack*:                htAddU64StackP,                             \
  const volatile Stack*: htAddU64StackP,                             \
  RedBlackTree:          htAddU64RedBlackTree,                       \
  RedBlackTree*:         htAddU64RedBlackTreeP,                      \
  const volatile RedBlackTree*: htAddU64RedBlackTreeP,                      \
  HashTable:             htAddU64HashTable,                          \
  HashTable*:            htAddU64HashTableP,                         \
  const volatile HashTable*: htAddU64HashTableP,                         \
  Vector:                htAddU64Vector,                             \
  Vector*:               htAddU64VectorP,                            \
  const volatile Vector*: htAddU64VectorP,                            \
  char*:                 htAddU64String,                             \
  const volatile char*:  htAddU64String,                             \
  char**:                htAddU64StringP,                            \
  const volatile char**: htAddU64StringP,                            \
  Bytes:                 htAddU64Bytes,                              \
  Bytes*:                htAddU64BytesP,                             \
  const volatile Bytes*: htAddU64BytesP,                             \
  void*:                 htAddU64Pointer,                            \
  void**:                htAddU64PointerP,                           \
  const volatile void**: htAddU64PointerP,                           \
  i8:                    htAddU64I8,                                 \
  u8:                    htAddU64U8                                  \

#define htAddU64(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_U64_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_FLOAT_KEY(dataStructure, key, value) \
  bool:                  htAddFloatBool,                             \
  bool*:                 htAddFloatBoolP,                            \
  const volatile bool*:  htAddFloatBoolP,                            \
  i16:                   htAddFloatI16,                              \
  i16*:                  htAddFloatI16P,                             \
  const volatile i16*:   htAddFloatI16P,                             \
  u16:                   htAddFloatU16,                              \
  u16*:                  htAddFloatU16P,                             \
  const volatile u16*:   htAddFloatU16P,                             \
  i32:                   htAddFloatI32,                              \
  i32*:                  htAddFloatI32P,                             \
  const volatile i32*:   htAddFloatI32P,                             \
  u32:                   htAddFloatU32,                              \
  u32*:                  htAddFloatU32P,                             \
  const volatile u32*:   htAddFloatU32P,                             \
  i64:                   htAddFloatI64,                              \
  i64*:                  htAddFloatI64P,                             \
  const volatile i64*:   htAddFloatI64P,                             \
  u64:                   htAddFloatU64,                              \
  u64*:                  htAddFloatU64P,                             \
  const volatile u64*:   htAddFloatU64P,                             \
  float:                 htAddFloatFloat,                            \
  float*:                htAddFloatFloatP,                           \
  const volatile float*: htAddFloatFloatP,                           \
  double:                htAddFloatDouble,                           \
  double*:               htAddFloatDoubleP,                          \
  const volatile double*: htAddFloatDoubleP,                          \
  long double:           htAddFloatLongDouble,                       \
  long double*:          htAddFloatLongDoubleP,                      \
  const volatile long double*: htAddFloatLongDoubleP,                      \
  List:                  htAddFloatList,                             \
  List*:                 htAddFloatListP,                            \
  const volatile List*:  htAddFloatListP,                            \
  Queue:                 htAddFloatQueue,                            \
  Queue*:                htAddFloatQueueP,                           \
  const volatile Queue*: htAddFloatQueueP,                           \
  Stack:                 htAddFloatStack,                            \
  Stack*:                htAddFloatStackP,                           \
  const volatile Stack*: htAddFloatStackP,                           \
  RedBlackTree:          htAddFloatRedBlackTree,                     \
  RedBlackTree*:         htAddFloatRedBlackTreeP,                    \
  const volatile RedBlackTree*: htAddFloatRedBlackTreeP,                    \
  HashTable:             htAddFloatHashTable,                        \
  HashTable*:            htAddFloatHashTableP,                       \
  const volatile HashTable*: htAddFloatHashTableP,                       \
  Vector:                htAddFloatVector,                           \
  Vector*:               htAddFloatVectorP,                          \
  const volatile Vector*: htAddFloatVectorP,                          \
  char*:                 htAddFloatString,                           \
  const volatile char*:  htAddFloatString,                           \
  char**:                htAddFloatStringP,                          \
  const volatile char**: htAddFloatStringP,                          \
  Bytes:                 htAddFloatBytes,                            \
  Bytes*:                htAddFloatBytesP,                           \
  const volatile Bytes*: htAddFloatBytesP,                           \
  void*:                 htAddFloatPointer,                          \
  void**:                htAddFloatPointerP,                         \
  const volatile void**: htAddFloatPointerP,                         \
  i8:                    htAddFloatI8,                               \
  u8:                    htAddFloatU8                                \

#define htAddFloat(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_FLOAT_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_DOUBLE_KEY(dataStructure, key, value) \
  bool:                  htAddDoubleBool,                            \
  bool*:                 htAddDoubleBoolP,                           \
  const volatile bool*:  htAddDoubleBoolP,                           \
  i16:                   htAddDoubleI16,                             \
  i16*:                  htAddDoubleI16P,                            \
  const volatile i16*:   htAddDoubleI16P,                            \
  u16:                   htAddDoubleU16,                             \
  u16*:                  htAddDoubleU16P,                            \
  const volatile u16*:   htAddDoubleU16P,                            \
  i32:                   htAddDoubleI32,                             \
  i32*:                  htAddDoubleI32P,                            \
  const volatile i32*:   htAddDoubleI32P,                            \
  u32:                   htAddDoubleU32,                             \
  u32*:                  htAddDoubleU32P,                            \
  const volatile u32*:   htAddDoubleU32P,                            \
  i64:                   htAddDoubleI64,                             \
  i64*:                  htAddDoubleI64P,                            \
  const volatile i64*:   htAddDoubleI64P,                            \
  u64:                   htAddDoubleU64,                             \
  u64*:                  htAddDoubleU64P,                            \
  const volatile u64*:   htAddDoubleU64P,                            \
  float:                 htAddDoubleFloat,                           \
  float*:                htAddDoubleFloatP,                          \
  const volatile float*: htAddDoubleFloatP,                          \
  double:                htAddDoubleDouble,                          \
  double*:               htAddDoubleDoubleP,                         \
  const volatile double*: htAddDoubleDoubleP,                         \
  long double:           htAddDoubleLongDouble,                      \
  long double*:          htAddDoubleLongDoubleP,                     \
  const volatile long double*: htAddDoubleLongDoubleP,                     \
  List:                  htAddDoubleList,                            \
  List*:                 htAddDoubleListP,                           \
  const volatile List*:  htAddDoubleListP,                           \
  Queue:                 htAddDoubleQueue,                           \
  Queue*:                htAddDoubleQueueP,                          \
  const volatile Queue*: htAddDoubleQueueP,                          \
  Stack:                 htAddDoubleStack,                           \
  Stack*:                htAddDoubleStackP,                          \
  const volatile Stack*: htAddDoubleStackP,                          \
  RedBlackTree:          htAddDoubleRedBlackTree,                    \
  RedBlackTree*:         htAddDoubleRedBlackTreeP,                   \
  const volatile RedBlackTree*: htAddDoubleRedBlackTreeP,                   \
  HashTable:             htAddDoubleHashTable,                       \
  HashTable*:            htAddDoubleHashTableP,                      \
  const volatile HashTable*: htAddDoubleHashTableP,                      \
  Vector:                htAddDoubleVector,                          \
  Vector*:               htAddDoubleVectorP,                         \
  const volatile Vector*: htAddDoubleVectorP,                         \
  char*:                 htAddDoubleString,                          \
  const volatile char*:  htAddDoubleString,                          \
  char**:                htAddDoubleStringP,                         \
  const volatile char**: htAddDoubleStringP,                         \
  Bytes:                 htAddDoubleBytes,                           \
  Bytes*:                htAddDoubleBytesP,                          \
  const volatile Bytes*: htAddDoubleBytesP,                          \
  void*:                 htAddDoublePointer,                         \
  void**:                htAddDoublePointerP,                        \
  const volatile void**: htAddDoublePointerP,                        \
  i8:                    htAddDoubleI8,                              \
  u8:                    htAddDoubleU8                               \

#define htAddDouble(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_DOUBLE_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_LONG_DOUBLE_KEY(dataStructure, key, value) \
  bool:                  htAddLongDoubleBool,                        \
  bool*:                 htAddLongDoubleBoolP,                       \
  const volatile bool*:  htAddLongDoubleBoolP,                       \
  i16:                   htAddLongDoubleI16,                         \
  i16*:                  htAddLongDoubleI16P,                        \
  const volatile i16*:   htAddLongDoubleI16P,                        \
  u16:                   htAddLongDoubleU16,                         \
  u16*:                  htAddLongDoubleU16P,                        \
  const volatile u16*:   htAddLongDoubleU16P,                        \
  i32:                   htAddLongDoubleI32,                         \
  i32*:                  htAddLongDoubleI32P,                        \
  const volatile i32*:   htAddLongDoubleI32P,                        \
  u32:                   htAddLongDoubleU32,                         \
  u32*:                  htAddLongDoubleU32P,                        \
  const volatile u32*:   htAddLongDoubleU32P,                        \
  i64:                   htAddLongDoubleI64,                         \
  i64*:                  htAddLongDoubleI64P,                        \
  const volatile i64*:   htAddLongDoubleI64P,                        \
  u64:                   htAddLongDoubleU64,                         \
  u64*:                  htAddLongDoubleU64P,                        \
  const volatile u64*:   htAddLongDoubleU64P,                        \
  float:                 htAddLongDoubleFloat,                       \
  float*:                htAddLongDoubleFloatP,                      \
  const volatile float*: htAddLongDoubleFloatP,                      \
  double:                htAddLongDoubleDouble,                      \
  double*:               htAddLongDoubleDoubleP,                     \
  const volatile double*: htAddLongDoubleDoubleP,                     \
  long double:           htAddLongDoubleLongDouble,                  \
  long double*:          htAddLongDoubleLongDoubleP,                 \
  const volatile long double*: htAddLongDoubleLongDoubleP,                 \
  List:                  htAddLongDoubleList,                        \
  List*:                 htAddLongDoubleListP,                       \
  const volatile List*:  htAddLongDoubleListP,                       \
  Queue:                 htAddLongDoubleQueue,                       \
  Queue*:                htAddLongDoubleQueueP,                      \
  const volatile Queue*: htAddLongDoubleQueueP,                      \
  Stack:                 htAddLongDoubleStack,                       \
  Stack*:                htAddLongDoubleStackP,                      \
  const volatile Stack*: htAddLongDoubleStackP,                      \
  RedBlackTree:          htAddLongDoubleRedBlackTree,                \
  RedBlackTree*:         htAddLongDoubleRedBlackTreeP,               \
  const volatile RedBlackTree*: htAddLongDoubleRedBlackTreeP,               \
  HashTable:             htAddLongDoubleHashTable,                   \
  HashTable*:            htAddLongDoubleHashTableP,                  \
  const volatile HashTable*: htAddLongDoubleHashTableP,                  \
  Vector:                htAddLongDoubleVector,                      \
  Vector*:               htAddLongDoubleVectorP,                     \
  const volatile Vector*: htAddLongDoubleVectorP,                     \
  char*:                 htAddLongDoubleString,                      \
  const volatile char*:  htAddLongDoubleString,                      \
  char**:                htAddLongDoubleStringP,                     \
  const volatile char**: htAddLongDoubleStringP,                     \
  Bytes:                 htAddLongDoubleBytes,                       \
  Bytes*:                htAddLongDoubleBytesP,                      \
  const volatile Bytes*: htAddLongDoubleBytesP,                      \
  void*:                 htAddLongDoublePointer,                     \
  void**:                htAddLongDoublePointerP,                    \
  const volatile void**: htAddLongDoublePointerP,                    \
  i8:                    htAddLongDoubleI8,                          \
  u8:                    htAddLongDoubleU8                           \

#define htAddLongDouble(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_LONG_DOUBLE_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_LIST_KEY(dataStructure, key, value) \
  bool:                  htAddListBool,                              \
  bool*:                 htAddListBoolP,                             \
  const volatile bool*:  htAddListBoolP,                             \
  i16:                   htAddListI16,                               \
  i16*:                  htAddListI16P,                              \
  const volatile i16*:   htAddListI16P,                              \
  u16:                   htAddListU16,                               \
  u16*:                  htAddListU16P,                              \
  const volatile u16*:   htAddListU16P,                              \
  i32:                   htAddListI32,                               \
  i32*:                  htAddListI32P,                              \
  const volatile i32*:   htAddListI32P,                              \
  u32:                   htAddListU32,                               \
  u32*:                  htAddListU32P,                              \
  const volatile u32*:   htAddListU32P,                              \
  i64:                   htAddListI64,                               \
  i64*:                  htAddListI64P,                              \
  const volatile i64*:   htAddListI64P,                              \
  u64:                   htAddListU64,                               \
  u64*:                  htAddListU64P,                              \
  const volatile u64*:   htAddListU64P,                              \
  float:                 htAddListFloat,                             \
  float*:                htAddListFloatP,                            \
  const volatile float*: htAddListFloatP,                            \
  double:                htAddListDouble,                            \
  double*:               htAddListDoubleP,                           \
  const volatile double*: htAddListDoubleP,                           \
  long double:           htAddListLongDouble,                        \
  long double*:          htAddListLongDoubleP,                       \
  const volatile long double*: htAddListLongDoubleP,                       \
  List:                  htAddListList,                              \
  List*:                 htAddListListP,                             \
  const volatile List*:  htAddListListP,                             \
  Queue:                 htAddListQueue,                             \
  Queue*:                htAddListQueueP,                            \
  const volatile Queue*: htAddListQueueP,                            \
  Stack:                 htAddListStack,                             \
  Stack*:                htAddListStackP,                            \
  const volatile Stack*: htAddListStackP,                            \
  RedBlackTree:          htAddListRedBlackTree,                      \
  RedBlackTree*:         htAddListRedBlackTreeP,                     \
  const volatile RedBlackTree*: htAddListRedBlackTreeP,                     \
  HashTable:             htAddListHashTable,                         \
  HashTable*:            htAddListHashTableP,                        \
  const volatile HashTable*: htAddListHashTableP,                        \
  Vector:                htAddListVector,                            \
  Vector*:               htAddListVectorP,                           \
  const volatile Vector*: htAddListVectorP,                           \
  char*:                 htAddListString,                            \
  const volatile char*:  htAddListString,                            \
  char**:                htAddListStringP,                           \
  const volatile char**: htAddListStringP,                           \
  Bytes:                 htAddListBytes,                             \
  Bytes*:                htAddListBytesP,                            \
  const volatile Bytes*: htAddListBytesP,                            \
  void*:                 htAddListPointer,                           \
  void**:                htAddListPointerP,                          \
  const volatile void**: htAddListPointerP,                          \
  i8:                    htAddListI8,                                \
  u8:                    htAddListU8                                 \

#define htAddList(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_LIST_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_QUEUE_KEY(dataStructure, key, value) \
  bool:                  htAddQueueBool,                             \
  bool*:                 htAddQueueBoolP,                            \
  const volatile bool*:  htAddQueueBoolP,                            \
  i16:                   htAddQueueI16,                              \
  i16*:                  htAddQueueI16P,                             \
  const volatile i16*:   htAddQueueI16P,                             \
  u16:                   htAddQueueU16,                              \
  u16*:                  htAddQueueU16P,                             \
  const volatile u16*:   htAddQueueU16P,                             \
  i32:                   htAddQueueI32,                              \
  i32*:                  htAddQueueI32P,                             \
  const volatile i32*:   htAddQueueI32P,                             \
  u32:                   htAddQueueU32,                              \
  u32*:                  htAddQueueU32P,                             \
  const volatile u32*:   htAddQueueU32P,                             \
  i64:                   htAddQueueI64,                              \
  i64*:                  htAddQueueI64P,                             \
  const volatile i64*:   htAddQueueI64P,                             \
  u64:                   htAddQueueU64,                              \
  u64*:                  htAddQueueU64P,                             \
  const volatile u64*:   htAddQueueU64P,                             \
  float:                 htAddQueueFloat,                            \
  float*:                htAddQueueFloatP,                           \
  const volatile float*: htAddQueueFloatP,                           \
  double:                htAddQueueDouble,                           \
  double*:               htAddQueueDoubleP,                          \
  const volatile double*: htAddQueueDoubleP,                          \
  long double:           htAddQueueLongDouble,                       \
  long double*:          htAddQueueLongDoubleP,                      \
  const volatile long double*: htAddQueueLongDoubleP,                      \
  List:                  htAddQueueList,                             \
  List*:                 htAddQueueListP,                            \
  const volatile List*:  htAddQueueListP,                            \
  Queue:                 htAddQueueQueue,                            \
  Queue*:                htAddQueueQueueP,                           \
  const volatile Queue*: htAddQueueQueueP,                           \
  Stack:                 htAddQueueStack,                            \
  Stack*:                htAddQueueStackP,                           \
  const volatile Stack*: htAddQueueStackP,                           \
  RedBlackTree:          htAddQueueRedBlackTree,                     \
  RedBlackTree*:         htAddQueueRedBlackTreeP,                    \
  const volatile RedBlackTree*: htAddQueueRedBlackTreeP,                    \
  HashTable:             htAddQueueHashTable,                        \
  HashTable*:            htAddQueueHashTableP,                       \
  const volatile HashTable*: htAddQueueHashTableP,                       \
  Vector:                htAddQueueVector,                           \
  Vector*:               htAddQueueVectorP,                          \
  const volatile Vector*: htAddQueueVectorP,                          \
  char*:                 htAddQueueString,                           \
  const volatile char*:  htAddQueueString,                           \
  char**:                htAddQueueStringP,                          \
  const volatile char**: htAddQueueStringP,                          \
  Bytes:                 htAddQueueBytes,                            \
  Bytes*:                htAddQueueBytesP,                           \
  const volatile Bytes*: htAddQueueBytesP,                           \
  void*:                 htAddQueuePointer,                          \
  void**:                htAddQueuePointerP,                         \
  const volatile void**: htAddQueuePointerP,                         \
  i8:                    htAddQueueI8,                               \
  u8:                    htAddQueueU8                                \

#define htAddQueue(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_QUEUE_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_STACK_KEY(dataStructure, key, value) \
  bool:                  htAddStackBool,                             \
  bool*:                 htAddStackBoolP,                            \
  const volatile bool*:  htAddStackBoolP,                            \
  i16:                   htAddStackI16,                              \
  i16*:                  htAddStackI16P,                             \
  const volatile i16*:   htAddStackI16P,                             \
  u16:                   htAddStackU16,                              \
  u16*:                  htAddStackU16P,                             \
  const volatile u16*:   htAddStackU16P,                             \
  i32:                   htAddStackI32,                              \
  i32*:                  htAddStackI32P,                             \
  const volatile i32*:   htAddStackI32P,                             \
  u32:                   htAddStackU32,                              \
  u32*:                  htAddStackU32P,                             \
  const volatile u32*:   htAddStackU32P,                             \
  i64:                   htAddStackI64,                              \
  i64*:                  htAddStackI64P,                             \
  const volatile i64*:   htAddStackI64P,                             \
  u64:                   htAddStackU64,                              \
  u64*:                  htAddStackU64P,                             \
  const volatile u64*:   htAddStackU64P,                             \
  float:                 htAddStackFloat,                            \
  float*:                htAddStackFloatP,                           \
  const volatile float*: htAddStackFloatP,                           \
  double:                htAddStackDouble,                           \
  double*:               htAddStackDoubleP,                          \
  const volatile double*: htAddStackDoubleP,                          \
  long double:           htAddStackLongDouble,                       \
  long double*:          htAddStackLongDoubleP,                      \
  const volatile long double*: htAddStackLongDoubleP,                      \
  List:                  htAddStackList,                             \
  List*:                 htAddStackListP,                            \
  const volatile List*:  htAddStackListP,                            \
  Queue:                 htAddStackQueue,                            \
  Queue*:                htAddStackQueueP,                           \
  const volatile Queue*: htAddStackQueueP,                           \
  Stack:                 htAddStackStack,                            \
  Stack*:                htAddStackStackP,                           \
  const volatile Stack*: htAddStackStackP,                           \
  RedBlackTree:          htAddStackRedBlackTree,                     \
  RedBlackTree*:         htAddStackRedBlackTreeP,                    \
  const volatile RedBlackTree*: htAddStackRedBlackTreeP,                    \
  HashTable:             htAddStackHashTable,                        \
  HashTable*:            htAddStackHashTableP,                       \
  const volatile HashTable*: htAddStackHashTableP,                       \
  Vector:                htAddStackVector,                           \
  Vector*:               htAddStackVectorP,                          \
  const volatile Vector*: htAddStackVectorP,                          \
  char*:                 htAddStackString,                           \
  const volatile char*:  htAddStackString,                           \
  char**:                htAddStackStringP,                          \
  const volatile char**: htAddStackStringP,                          \
  Bytes:                 htAddStackBytes,                            \
  Bytes*:                htAddStackBytesP,                           \
  const volatile Bytes*: htAddStackBytesP,                           \
  void*:                 htAddStackPointer,                          \
  void**:                htAddStackPointerP,                         \
  const volatile void**: htAddStackPointerP,                         \
  i8:                    htAddStackI8,                               \
  u8:                    htAddStackU8                                \

#define htAddStack(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_STACK_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_RED_BLACK_TREE_KEY(dataStructure, key, value) \
  bool:                  htAddRedBlackTreeBool,                      \
  bool*:                 htAddRedBlackTreeBoolP,                     \
  const volatile bool*:  htAddRedBlackTreeBoolP,                     \
  i16:                   htAddRedBlackTreeI16,                       \
  i16*:                  htAddRedBlackTreeI16P,                      \
  const volatile i16*:   htAddRedBlackTreeI16P,                      \
  u16:                   htAddRedBlackTreeU16,                       \
  u16*:                  htAddRedBlackTreeU16P,                      \
  const volatile u16*:   htAddRedBlackTreeU16P,                      \
  i32:                   htAddRedBlackTreeI32,                       \
  i32*:                  htAddRedBlackTreeI32P,                      \
  const volatile i32*:   htAddRedBlackTreeI32P,                      \
  u32:                   htAddRedBlackTreeU32,                       \
  u32*:                  htAddRedBlackTreeU32P,                      \
  const volatile u32*:   htAddRedBlackTreeU32P,                      \
  i64:                   htAddRedBlackTreeI64,                       \
  i64*:                  htAddRedBlackTreeI64P,                      \
  const volatile i64*:   htAddRedBlackTreeI64P,                      \
  u64:                   htAddRedBlackTreeU64,                       \
  u64*:                  htAddRedBlackTreeU64P,                      \
  const volatile u64*:   htAddRedBlackTreeU64P,                      \
  float:                 htAddRedBlackTreeFloat,                     \
  float*:                htAddRedBlackTreeFloatP,                    \
  const volatile float*: htAddRedBlackTreeFloatP,                    \
  double:                htAddRedBlackTreeDouble,                    \
  double*:               htAddRedBlackTreeDoubleP,                   \
  const volatile double*: htAddRedBlackTreeDoubleP,                   \
  long double:           htAddRedBlackTreeLongDouble,                \
  long double*:          htAddRedBlackTreeLongDoubleP,               \
  const volatile long double*: htAddRedBlackTreeLongDoubleP,               \
  List:                  htAddRedBlackTreeList,                      \
  List*:                 htAddRedBlackTreeListP,                     \
  const volatile List*:  htAddRedBlackTreeListP,                     \
  Queue:                 htAddRedBlackTreeQueue,                     \
  Queue*:                htAddRedBlackTreeQueueP,                    \
  const volatile Queue*: htAddRedBlackTreeQueueP,                    \
  Stack:                 htAddRedBlackTreeStack,                     \
  Stack*:                htAddRedBlackTreeStackP,                    \
  const volatile Stack*: htAddRedBlackTreeStackP,                    \
  RedBlackTree:          htAddRedBlackTreeRedBlackTree,              \
  RedBlackTree*:         htAddRedBlackTreeRedBlackTreeP,             \
  const volatile RedBlackTree*: htAddRedBlackTreeRedBlackTreeP,             \
  HashTable:             htAddRedBlackTreeHashTable,                 \
  HashTable*:            htAddRedBlackTreeHashTableP,                \
  const volatile HashTable*: htAddRedBlackTreeHashTableP,                \
  Vector:                htAddRedBlackTreeVector,                    \
  Vector*:               htAddRedBlackTreeVectorP,                   \
  const volatile Vector*: htAddRedBlackTreeVectorP,                   \
  char*:                 htAddRedBlackTreeString,                    \
  const volatile char*:  htAddRedBlackTreeString,                    \
  char**:                htAddRedBlackTreeStringP,                   \
  const volatile char**: htAddRedBlackTreeStringP,                   \
  Bytes:                 htAddRedBlackTreeBytes,                     \
  Bytes*:                htAddRedBlackTreeBytesP,                    \
  const volatile Bytes*: htAddRedBlackTreeBytesP,                    \
  void*:                 htAddRedBlackTreePointer,                   \
  void**:                htAddRedBlackTreePointerP,                  \
  const volatile void**: htAddRedBlackTreePointerP,                  \
  i8:                    htAddRedBlackTreeI8,                        \
  u8:                    htAddRedBlackTreeU8                         \

#define htAddRedBlackTree(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_RED_BLACK_TREE_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_HASH_TABLE_KEY(dataStructure, key, value) \
  bool:                  htAddHashTableBool,                         \
  bool*:                 htAddHashTableBoolP,                        \
  const volatile bool*:  htAddHashTableBoolP,                        \
  i16:                   htAddHashTableI16,                          \
  i16*:                  htAddHashTableI16P,                         \
  const volatile i16*:   htAddHashTableI16P,                         \
  u16:                   htAddHashTableU16,                          \
  u16*:                  htAddHashTableU16P,                         \
  const volatile u16*:   htAddHashTableU16P,                         \
  i32:                   htAddHashTableI32,                          \
  i32*:                  htAddHashTableI32P,                         \
  const volatile i32*:   htAddHashTableI32P,                         \
  u32:                   htAddHashTableU32,                          \
  u32*:                  htAddHashTableU32P,                         \
  const volatile u32*:   htAddHashTableU32P,                         \
  i64:                   htAddHashTableI64,                          \
  i64*:                  htAddHashTableI64P,                         \
  const volatile i64*:   htAddHashTableI64P,                         \
  u64:                   htAddHashTableU64,                          \
  u64*:                  htAddHashTableU64P,                         \
  const volatile u64*:   htAddHashTableU64P,                         \
  float:                 htAddHashTableFloat,                        \
  float*:                htAddHashTableFloatP,                       \
  const volatile float*: htAddHashTableFloatP,                       \
  double:                htAddHashTableDouble,                       \
  double*:               htAddHashTableDoubleP,                      \
  const volatile double*: htAddHashTableDoubleP,                      \
  long double:           htAddHashTableLongDouble,                   \
  long double*:          htAddHashTableLongDoubleP,                  \
  const volatile long double*: htAddHashTableLongDoubleP,                  \
  List:                  htAddHashTableList,                         \
  List*:                 htAddHashTableListP,                        \
  const volatile List*:  htAddHashTableListP,                        \
  Queue:                 htAddHashTableQueue,                        \
  Queue*:                htAddHashTableQueueP,                       \
  const volatile Queue*: htAddHashTableQueueP,                       \
  Stack:                 htAddHashTableStack,                        \
  Stack*:                htAddHashTableStackP,                       \
  const volatile Stack*: htAddHashTableStackP,                       \
  RedBlackTree:          htAddHashTableRedBlackTree,                 \
  RedBlackTree*:         htAddHashTableRedBlackTreeP,                \
  const volatile RedBlackTree*: htAddHashTableRedBlackTreeP,                \
  HashTable:             htAddHashTableHashTable,                    \
  HashTable*:            htAddHashTableHashTableP,                   \
  const volatile HashTable*: htAddHashTableHashTableP,                   \
  Vector:                htAddHashTableVector,                       \
  Vector*:               htAddHashTableVectorP,                      \
  const volatile Vector*: htAddHashTableVectorP,                      \
  char*:                 htAddHashTableString,                       \
  const volatile char*:  htAddHashTableString,                       \
  char**:                htAddHashTableStringP,                      \
  const volatile char**: htAddHashTableStringP,                      \
  Bytes:                 htAddHashTableBytes,                        \
  Bytes*:                htAddHashTableBytesP,                       \
  const volatile Bytes*: htAddHashTableBytesP,                       \
  void*:                 htAddHashTablePointer,                      \
  void**:                htAddHashTablePointerP,                     \
  const volatile void**: htAddHashTablePointerP,                     \
  i8:                    htAddHashTableI8,                           \
  u8:                    htAddHashTableU8                            \

#define htAddHashTable(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_HASH_TABLE_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_VECTOR_KEY(dataStructure, key, value) \
  bool:                  htAddVectorBool,                            \
  bool*:                 htAddVectorBoolP,                           \
  const volatile bool*:  htAddVectorBoolP,                           \
  i16:                   htAddVectorI16,                             \
  i16*:                  htAddVectorI16P,                            \
  const volatile i16*:   htAddVectorI16P,                            \
  u16:                   htAddVectorU16,                             \
  u16*:                  htAddVectorU16P,                            \
  const volatile u16*:   htAddVectorU16P,                            \
  i32:                   htAddVectorI32,                             \
  i32*:                  htAddVectorI32P,                            \
  const volatile i32*:   htAddVectorI32P,                            \
  u32:                   htAddVectorU32,                             \
  u32*:                  htAddVectorU32P,                            \
  const volatile u32*:   htAddVectorU32P,                            \
  i64:                   htAddVectorI64,                             \
  i64*:                  htAddVectorI64P,                            \
  const volatile i64*:   htAddVectorI64P,                            \
  u64:                   htAddVectorU64,                             \
  u64*:                  htAddVectorU64P,                            \
  const volatile u64*:   htAddVectorU64P,                            \
  float:                 htAddVectorFloat,                           \
  float*:                htAddVectorFloatP,                          \
  const volatile float*: htAddVectorFloatP,                          \
  double:                htAddVectorDouble,                          \
  double*:               htAddVectorDoubleP,                         \
  const volatile double*: htAddVectorDoubleP,                         \
  long double:           htAddVectorLongDouble,                      \
  long double*:          htAddVectorLongDoubleP,                     \
  const volatile long double*: htAddVectorLongDoubleP,                     \
  List:                  htAddVectorList,                            \
  List*:                 htAddVectorListP,                           \
  const volatile List*:  htAddVectorListP,                           \
  Queue:                 htAddVectorQueue,                           \
  Queue*:                htAddVectorQueueP,                          \
  const volatile Queue*: htAddVectorQueueP,                          \
  Stack:                 htAddVectorStack,                           \
  Stack*:                htAddVectorStackP,                          \
  const volatile Stack*: htAddVectorStackP,                          \
  RedBlackTree:          htAddVectorRedBlackTree,                    \
  RedBlackTree*:         htAddVectorRedBlackTreeP,                   \
  const volatile RedBlackTree*: htAddVectorRedBlackTreeP,                   \
  HashTable:             htAddVectorHashTable,                       \
  HashTable*:            htAddVectorHashTableP,                      \
  const volatile HashTable*: htAddVectorHashTableP,                      \
  Vector:                htAddVectorVector,                          \
  Vector*:               htAddVectorVectorP,                         \
  const volatile Vector*: htAddVectorVectorP,                         \
  char*:                 htAddVectorString,                          \
  const volatile char*:  htAddVectorString,                          \
  char**:                htAddVectorStringP,                         \
  const volatile char**: htAddVectorStringP,                         \
  Bytes:                 htAddVectorBytes,                           \
  Bytes*:                htAddVectorBytesP,                          \
  const volatile Bytes*: htAddVectorBytesP,                          \
  void*:                 htAddVectorPointer,                         \
  void**:                htAddVectorPointerP,                        \
  const volatile void**: htAddVectorPointerP,                        \
  i8:                    htAddVectorI8,                              \
  u8:                    htAddVectorU8                               \

#define htAddVector(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_VECTOR_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_STRING_KEY(dataStructure, key, value) \
  bool:                  htAddStringBool,                            \
  const volatile bool:   htAddStringBool,                            \
  bool*:                 htAddStringBoolP,                           \
  const volatile bool*:  htAddStringBoolP,                           \
  i16:                   htAddStringI16,                             \
  const volatile i16:    htAddStringI16,                             \
  i16*:                  htAddStringI16P,                            \
  const volatile i16*:   htAddStringI16P,                            \
  u16:                   htAddStringU16,                             \
  const volatile u16:    htAddStringU16,                             \
  u16*:                  htAddStringU16P,                            \
  const volatile u16*:   htAddStringU16P,                            \
  i32:                   htAddStringI32,                             \
  const volatile i32:    htAddStringI32,                             \
  i32*:                  htAddStringI32P,                            \
  const volatile i32*:   htAddStringI32P,                            \
  u32:                   htAddStringU32,                             \
  const volatile u32:    htAddStringU32,                             \
  u32*:                  htAddStringU32P,                            \
  const volatile u32*:   htAddStringU32P,                            \
  i64:                   htAddStringI64,                             \
  const volatile i64:    htAddStringI64,                             \
  i64*:                  htAddStringI64P,                            \
  const volatile i64*:   htAddStringI64P,                            \
  u64:                   htAddStringU64,                             \
  const volatile u64:    htAddStringU64,                             \
  u64*:                  htAddStringU64P,                            \
  const volatile u64*:   htAddStringU64P,                            \
  float:                 htAddStringFloat,                           \
  const volatile float:  htAddStringFloat,                           \
  float*:                htAddStringFloatP,                          \
  const volatile float*: htAddStringFloatP,                          \
  double:                htAddStringDouble,                          \
  const volatile double: htAddStringDouble,                          \
  double*:               htAddStringDoubleP,                         \
  const volatile double*: htAddStringDoubleP,                         \
  long double:           htAddStringLongDouble,                      \
  const volatile long double: htAddStringLongDouble,                      \
  long double*:          htAddStringLongDoubleP,                     \
  const volatile long double*: htAddStringLongDoubleP,                     \
  List:                  htAddStringList,                            \
  const volatile List:   htAddStringList,                            \
  List*:                 htAddStringListP,                           \
  const volatile List*:  htAddStringListP,                           \
  Queue:                 htAddStringQueue,                           \
  const volatile Queue:  htAddStringQueue,                           \
  Queue*:                htAddStringQueueP,                          \
  const volatile Queue*: htAddStringQueueP,                          \
  Stack:                 htAddStringStack,                           \
  const volatile Stack:  htAddStringStack,                           \
  Stack*:                htAddStringStackP,                          \
  const volatile Stack*: htAddStringStackP,                          \
  RedBlackTree:          htAddStringRedBlackTree,                    \
  const volatile RedBlackTree: htAddStringRedBlackTree,                    \
  RedBlackTree*:         htAddStringRedBlackTreeP,                   \
  const volatile RedBlackTree*: htAddStringRedBlackTreeP,                   \
  HashTable:             htAddStringHashTable,                       \
  const volatile HashTable: htAddStringHashTable,                       \
  HashTable*:            htAddStringHashTableP,                      \
  const volatile HashTable*: htAddStringHashTableP,                      \
  Vector:                htAddStringVector,                          \
  const volatile Vector: htAddStringVector,                          \
  Vector*:               htAddStringVectorP,                         \
  const volatile Vector*: htAddStringVectorP,                         \
  char*:                 htAddStringString,                          \
  const volatile char*:  htAddStringString,                          \
  char**:                htAddStringStringP,                         \
  const volatile char**: htAddStringStringP,                         \
  Bytes:                 htAddStringBytes,                           \
  Bytes*:                htAddStringBytesP,                          \
  const volatile Bytes*: htAddStringBytesP,                          \
  void*:                 htAddStringPointer,                         \
  void**:                htAddStringPointerP,                        \
  const volatile void**: htAddStringPointerP,                        \
  i8:                    htAddStringI8,                              \
  u8:                    htAddStringU8                               \

#define htAddString(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_STRING_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_BYTES_KEY(dataStructure, key, value) \
  bool:                  htAddBytesBool,                             \
  bool*:                 htAddBytesBoolP,                            \
  const volatile bool*:  htAddBytesBoolP,                            \
  i16:                   htAddBytesI16,                              \
  i16*:                  htAddBytesI16P,                             \
  const volatile i16*:   htAddBytesI16P,                             \
  u16:                   htAddBytesU16,                              \
  u16*:                  htAddBytesU16P,                             \
  const volatile u16*:   htAddBytesU16P,                             \
  i32:                   htAddBytesI32,                              \
  i32*:                  htAddBytesI32P,                             \
  const volatile i32*:   htAddBytesI32P,                             \
  u32:                   htAddBytesU32,                              \
  u32*:                  htAddBytesU32P,                             \
  const volatile u32*:   htAddBytesU32P,                             \
  i64:                   htAddBytesI64,                              \
  i64*:                  htAddBytesI64P,                             \
  const volatile i64*:   htAddBytesI64P,                             \
  u64:                   htAddBytesU64,                              \
  u64*:                  htAddBytesU64P,                             \
  const volatile u64*:   htAddBytesU64P,                             \
  float:                 htAddBytesFloat,                            \
  float*:                htAddBytesFloatP,                           \
  const volatile float*: htAddBytesFloatP,                           \
  double:                htAddBytesDouble,                           \
  double*:               htAddBytesDoubleP,                          \
  const volatile double*: htAddBytesDoubleP,                          \
  long double:           htAddBytesLongDouble,                       \
  long double*:          htAddBytesLongDoubleP,                      \
  const volatile long double*: htAddBytesLongDoubleP,                      \
  List:                  htAddBytesList,                             \
  List*:                 htAddBytesListP,                            \
  const volatile List*:  htAddBytesListP,                            \
  Queue:                 htAddBytesQueue,                            \
  Queue*:                htAddBytesQueueP,                           \
  const volatile Queue*: htAddBytesQueueP,                           \
  Stack:                 htAddBytesStack,                            \
  Stack*:                htAddBytesStackP,                           \
  const volatile Stack*: htAddBytesStackP,                           \
  RedBlackTree:          htAddBytesRedBlackTree,                     \
  RedBlackTree*:         htAddBytesRedBlackTreeP,                    \
  const volatile RedBlackTree*: htAddBytesRedBlackTreeP,                    \
  HashTable:             htAddBytesHashTable,                        \
  HashTable*:            htAddBytesHashTableP,                       \
  const volatile HashTable*: htAddBytesHashTableP,                       \
  Vector:                htAddBytesVector,                           \
  Vector*:               htAddBytesVectorP,                          \
  const volatile Vector*: htAddBytesVectorP,                          \
  char*:                 htAddBytesString,                           \
  const volatile char*:  htAddBytesString,                           \
  char**:                htAddBytesStringP,                          \
  const volatile char**: htAddBytesStringP,                          \
  Bytes:                 htAddBytesBytes,                            \
  Bytes*:                htAddBytesBytesP,                           \
  const volatile Bytes*: htAddBytesBytesP,                           \
  void*:                 htAddBytesPointer,                          \
  void**:                htAddBytesPointerP,                         \
  const volatile void**: htAddBytesPointerP,                         \
  i8:                    htAddBytesI8,                               \
  u8:                    htAddBytesU8                                \

#define htAddBytes(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_BYTES_KEY(dataStructure, key, value) \
  )


#define HT_ADD_GENERIC_CASES_POINTER_KEY(dataStructure, key, value) \
  bool:                  htAddPointerBool,                           \
  bool*:                 htAddPointerBoolP,                          \
  const volatile bool*:  htAddPointerBoolP,                          \
  i16:                   htAddPointerI16,                            \
  i16*:                  htAddPointerI16P,                           \
  const volatile i16*:   htAddPointerI16P,                           \
  u16:                   htAddPointerU16,                            \
  u16*:                  htAddPointerU16P,                           \
  const volatile u16*:   htAddPointerU16P,                           \
  i32:                   htAddPointerI32,                            \
  i32*:                  htAddPointerI32P,                           \
  const volatile i32*:   htAddPointerI32P,                           \
  u32:                   htAddPointerU32,                            \
  u32*:                  htAddPointerU32P,                           \
  const volatile u32*:   htAddPointerU32P,                           \
  i64:                   htAddPointerI64,                            \
  i64*:                  htAddPointerI64P,                           \
  const volatile i64*:   htAddPointerI64P,                           \
  u64:                   htAddPointerU64,                            \
  u64*:                  htAddPointerU64P,                           \
  const volatile u64*:   htAddPointerU64P,                           \
  float:                 htAddPointerFloat,                          \
  float*:                htAddPointerFloatP,                         \
  const volatile float*: htAddPointerFloatP,                         \
  double:                htAddPointerDouble,                         \
  double*:               htAddPointerDoubleP,                        \
  const volatile double*: htAddPointerDoubleP,                        \
  long double:           htAddPointerLongDouble,                     \
  long double*:          htAddPointerLongDoubleP,                    \
  const volatile long double*: htAddPointerLongDoubleP,                    \
  List:                  htAddPointerList,                           \
  List*:                 htAddPointerListP,                          \
  const volatile List*:  htAddPointerListP,                          \
  Queue:                 htAddPointerQueue,                          \
  Queue*:                htAddPointerQueueP,                         \
  const volatile Queue*: htAddPointerQueueP,                         \
  Stack:                 htAddPointerStack,                          \
  Stack*:                htAddPointerStackP,                         \
  const volatile Stack*: htAddPointerStackP,                         \
  RedBlackTree:          htAddPointerRedBlackTree,                   \
  RedBlackTree*:         htAddPointerRedBlackTreeP,                  \
  const volatile RedBlackTree*: htAddPointerRedBlackTreeP,                  \
  HashTable:             htAddPointerHashTable,                      \
  HashTable*:            htAddPointerHashTableP,                     \
  const volatile HashTable*: htAddPointerHashTableP,                     \
  Vector:                htAddPointerVector,                         \
  Vector*:               htAddPointerVectorP,                        \
  const volatile Vector*: htAddPointerVectorP,                        \
  char*:                 htAddPointerString,                         \
  const volatile char*:  htAddPointerString,                         \
  char**:                htAddPointerStringP,                        \
  const volatile char**: htAddPointerStringP,                        \
  Bytes:                 htAddPointerBytes,                          \
  Bytes*:                htAddPointerBytesP,                         \
  const volatile Bytes*: htAddPointerBytesP,                         \
  void*:                 htAddPointerPointer,                        \
  void**:                htAddPointerPointerP,                       \
  const volatile void**: htAddPointerPointerP,                       \
  i8:                    htAddPointerI8,                             \
  u8:                    htAddPointerU8                              \

#define htAddPointer(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_POINTER_KEY(dataStructure, key, value) \
  )


#define HT_ADD_GENERIC_CASES_I8_KEY(dataStructure, key, value) \
  bool:                  htAddI8Bool,                                \
  bool*:                 htAddI8BoolP,                               \
  const volatile bool*:  htAddI8BoolP,                               \
  i16:                   htAddI8I16,                                 \
  i16*:                  htAddI8I16P,                                \
  const volatile i16*:   htAddI8I16P,                                \
  u16:                   htAddI8U16,                                 \
  u16*:                  htAddI8U16P,                                \
  const volatile u16*:   htAddI8U16P,                                \
  i32:                   htAddI8I32,                                 \
  i32*:                  htAddI8I32P,                                \
  const volatile i32*:   htAddI8I32P,                                \
  u32:                   htAddI8U32,                                 \
  u32*:                  htAddI8U32P,                                \
  const volatile u32*:   htAddI8U32P,                                \
  i64:                   htAddI8I64,                                 \
  i64*:                  htAddI8I64P,                                \
  const volatile i64*:   htAddI8I64P,                                \
  u64:                   htAddI8U64,                                 \
  u64*:                  htAddI8U64P,                                \
  const volatile u64*:   htAddI8U64P,                                \
  float:                 htAddI8Float,                               \
  float*:                htAddI8FloatP,                              \
  const volatile float*: htAddI8FloatP,                              \
  double:                htAddI8Double,                              \
  double*:               htAddI8DoubleP,                             \
  const volatile double*: htAddI8DoubleP,                             \
  long double:           htAddI8LongDouble,                          \
  long double*:          htAddI8LongDoubleP,                         \
  const volatile long double*: htAddI8LongDoubleP,                         \
  List:                  htAddI8List,                                \
  List*:                 htAddI8ListP,                               \
  const volatile List*:  htAddI8ListP,                               \
  Queue:                 htAddI8Queue,                               \
  Queue*:                htAddI8QueueP,                              \
  const volatile Queue*: htAddI8QueueP,                              \
  Stack:                 htAddI8Stack,                               \
  Stack*:                htAddI8StackP,                              \
  const volatile Stack*: htAddI8StackP,                              \
  RedBlackTree:          htAddI8RedBlackTree,                        \
  RedBlackTree*:         htAddI8RedBlackTreeP,                       \
  const volatile RedBlackTree*: htAddI8RedBlackTreeP,                       \
  HashTable:             htAddI8HashTable,                           \
  HashTable*:            htAddI8HashTableP,                          \
  const volatile HashTable*: htAddI8HashTableP,                          \
  Vector:                htAddI8Vector,                              \
  Vector*:               htAddI8VectorP,                             \
  const volatile Vector*: htAddI8VectorP,                             \
  char*:                 htAddI8String,                              \
  const volatile char*:  htAddI8String,                              \
  char**:                htAddI8StringP,                             \
  const volatile char**: htAddI8StringP,                             \
  Bytes:                 htAddI8Bytes,                               \
  Bytes*:                htAddI8BytesP,                              \
  const volatile Bytes*: htAddI8BytesP,                              \
  void*:                 htAddI8Pointer,                             \
  void**:                htAddI8PointerP,                            \
  const volatile void**: htAddI8PointerP,                            \
  i8:                    htAddI8I8,                                  \
  u8:                    htAddI8U8                                   \

#define htAddI8(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_I8_KEY(dataStructure, key, value) \
  )


#define HT_ADD_GENERIC_CASES_U8_KEY(dataStructure, key, value) \
  bool:                  htAddU8Bool,                                \
  bool*:                 htAddU8BoolP,                               \
  const volatile bool*:  htAddU8BoolP,                               \
  i16:                   htAddU8I16,                                 \
  i16*:                  htAddU8I16P,                                \
  const volatile i16*:   htAddU8I16P,                                \
  u16:                   htAddU8U16,                                 \
  u16*:                  htAddU8U16P,                                \
  const volatile u16*:   htAddU8U16P,                                \
  i32:                   htAddU8I32,                                 \
  i32*:                  htAddU8I32P,                                \
  const volatile i32*:   htAddU8I32P,                                \
  u32:                   htAddU8U32,                                 \
  u32*:                  htAddU8U32P,                                \
  const volatile u32*:   htAddU8U32P,                                \
  i64:                   htAddU8I64,                                 \
  i64*:                  htAddU8I64P,                                \
  const volatile i64*:   htAddU8I64P,                                \
  u64:                   htAddU8U64,                                 \
  u64*:                  htAddU8U64P,                                \
  const volatile u64*:   htAddU8U64P,                                \
  float:                 htAddU8Float,                               \
  float*:                htAddU8FloatP,                              \
  const volatile float*: htAddU8FloatP,                              \
  double:                htAddU8Double,                              \
  double*:               htAddU8DoubleP,                             \
  const volatile double*: htAddU8DoubleP,                             \
  long double:           htAddU8LongDouble,                          \
  long double*:          htAddU8LongDoubleP,                         \
  const volatile long double*: htAddU8LongDoubleP,                         \
  List:                  htAddU8List,                                \
  List*:                 htAddU8ListP,                               \
  const volatile List*:  htAddU8ListP,                               \
  Queue:                 htAddU8Queue,                               \
  Queue*:                htAddU8QueueP,                              \
  const volatile Queue*: htAddU8QueueP,                              \
  Stack:                 htAddU8Stack,                               \
  Stack*:                htAddU8StackP,                              \
  const volatile Stack*: htAddU8StackP,                              \
  RedBlackTree:          htAddU8RedBlackTree,                        \
  RedBlackTree*:         htAddU8RedBlackTreeP,                       \
  const volatile RedBlackTree*: htAddU8RedBlackTreeP,                       \
  HashTable:             htAddU8HashTable,                           \
  HashTable*:            htAddU8HashTableP,                          \
  const volatile HashTable*: htAddU8HashTableP,                          \
  Vector:                htAddU8Vector,                              \
  Vector*:               htAddU8VectorP,                             \
  const volatile Vector*: htAddU8VectorP,                             \
  char*:                 htAddU8String,                              \
  const volatile char*:  htAddU8String,                              \
  char**:                htAddU8StringP,                             \
  const volatile char**: htAddU8StringP,                             \
  Bytes:                 htAddU8Bytes,                               \
  Bytes*:                htAddU8BytesP,                              \
  const volatile Bytes*: htAddU8BytesP,                              \
  void*:                 htAddU8Pointer,                             \
  void**:                htAddU8PointerP,                            \
  const volatile void**: htAddU8PointerP,                            \
  i8:                    htAddU8I8,                                  \
  u8:                    htAddU8U8                                   \

#define htAddU8(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_U8_KEY(dataStructure, key, value) \
  )


#define HT_ADD_GENERIC_CASES_BOOLP_KEY(dataStructure, key, value) \
  bool:                  htAddBoolPBool,                             \
  bool*:                 htAddBoolPBoolP,                            \
  const volatile bool*:  htAddBoolPBoolP,                            \
  i16:                   htAddBoolPI16,                              \
  i16*:                  htAddBoolPI16P,                             \
  const volatile i16*:   htAddBoolPI16P,                             \
  u16:                   htAddBoolPU16,                              \
  u16*:                  htAddBoolPU16P,                             \
  const volatile u16*:   htAddBoolPU16P,                             \
  i32:                   htAddBoolPI32,                              \
  i32*:                  htAddBoolPI32P,                             \
  const volatile i32*:   htAddBoolPI32P,                             \
  u32:                   htAddBoolPU32,                              \
  u32*:                  htAddBoolPU32P,                             \
  const volatile u32*:   htAddBoolPU32P,                             \
  i64:                   htAddBoolPI64,                              \
  i64*:                  htAddBoolPI64P,                             \
  const volatile i64*:   htAddBoolPI64P,                             \
  u64:                   htAddBoolPU64,                              \
  u64*:                  htAddBoolPU64P,                             \
  const volatile u64*:   htAddBoolPU64P,                             \
  float:                 htAddBoolPFloat,                            \
  float*:                htAddBoolPFloatP,                           \
  const volatile float*: htAddBoolPFloatP,                           \
  double:                htAddBoolPDouble,                           \
  double*:               htAddBoolPDoubleP,                          \
  const volatile double*: htAddBoolPDoubleP,                          \
  long double:           htAddBoolPLongDouble,                       \
  long double*:          htAddBoolPLongDoubleP,                      \
  const volatile long double*: htAddBoolPLongDoubleP,                      \
  List:                  htAddBoolPList,                             \
  List*:                 htAddBoolPListP,                            \
  const volatile List*:  htAddBoolPListP,                            \
  Queue:                 htAddBoolPQueue,                            \
  Queue*:                htAddBoolPQueueP,                           \
  const volatile Queue*: htAddBoolPQueueP,                           \
  Stack:                 htAddBoolPStack,                            \
  Stack*:                htAddBoolPStackP,                           \
  const volatile Stack*: htAddBoolPStackP,                           \
  RedBlackTree:          htAddBoolPRedBlackTree,                     \
  RedBlackTree*:         htAddBoolPRedBlackTreeP,                    \
  const volatile RedBlackTree*: htAddBoolPRedBlackTreeP,                    \
  HashTable:             htAddBoolPHashTable,                        \
  HashTable*:            htAddBoolPHashTableP,                       \
  const volatile HashTable*: htAddBoolPHashTableP,                       \
  Vector:                htAddBoolPVector,                           \
  Vector*:               htAddBoolPVectorP,                          \
  const volatile Vector*: htAddBoolPVectorP,                          \
  char*:                 htAddBoolPString,                           \
  const volatile char*:  htAddBoolPString,                           \
  char**:                htAddBoolPStringP,                          \
  const volatile char**: htAddBoolPStringP,                          \
  Bytes:                 htAddBoolPBytes,                            \
  Bytes*:                htAddBoolPBytesP,                           \
  const volatile Bytes*: htAddBoolPBytesP,                           \
  void*:                 htAddBoolPPointer,                          \
  void**:                htAddBoolPPointerP,                         \
  const volatile void**: htAddBoolPPointerP,                         \
  i8:                    htAddBoolI8,                                \
  u8:                    htAddBoolU8                                 \

#define htAddBoolP(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_BOOLP_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_I16P_KEY(dataStructure, key, value) \
  bool:                  htAddI16PBool,                              \
  bool*:                 htAddI16PBoolP,                             \
  const volatile bool*:  htAddI16PBoolP,                             \
  i16:                   htAddI16PI16,                               \
  i16*:                  htAddI16PI16P,                              \
  const volatile i16*:   htAddI16PI16P,                              \
  u16:                   htAddI16PU16,                               \
  u16*:                  htAddI16PU16P,                              \
  const volatile u16*:   htAddI16PU16P,                              \
  i32:                   htAddI16PI32,                               \
  i32*:                  htAddI16PI32P,                              \
  const volatile i32*:   htAddI16PI32P,                              \
  u32:                   htAddI16PU32,                               \
  u32*:                  htAddI16PU32P,                              \
  const volatile u32*:   htAddI16PU32P,                              \
  i64:                   htAddI16PI64,                               \
  i64*:                  htAddI16PI64P,                              \
  const volatile i64*:   htAddI16PI64P,                              \
  u64:                   htAddI16PU64,                               \
  u64*:                  htAddI16PU64P,                              \
  const volatile u64*:   htAddI16PU64P,                              \
  float:                 htAddI16PFloat,                             \
  float*:                htAddI16PFloatP,                            \
  const volatile float*: htAddI16PFloatP,                            \
  double:                htAddI16PDouble,                            \
  double*:               htAddI16PDoubleP,                           \
  const volatile double*: htAddI16PDoubleP,                           \
  long double:           htAddI16PLongDouble,                        \
  long double*:          htAddI16PLongDoubleP,                       \
  const volatile long double*: htAddI16PLongDoubleP,                       \
  List:                  htAddI16PList,                              \
  List*:                 htAddI16PListP,                             \
  const volatile List*:  htAddI16PListP,                             \
  Queue:                 htAddI16PQueue,                             \
  Queue*:                htAddI16PQueueP,                            \
  const volatile Queue*: htAddI16PQueueP,                            \
  Stack:                 htAddI16PStack,                             \
  Stack*:                htAddI16PStackP,                            \
  const volatile Stack*: htAddI16PStackP,                            \
  RedBlackTree:          htAddI16PRedBlackTree,                      \
  RedBlackTree*:         htAddI16PRedBlackTreeP,                     \
  const volatile RedBlackTree*: htAddI16PRedBlackTreeP,                     \
  HashTable:             htAddI16PHashTable,                         \
  HashTable*:            htAddI16PHashTableP,                        \
  const volatile HashTable*: htAddI16PHashTableP,                        \
  Vector:                htAddI16PVector,                            \
  Vector*:               htAddI16PVectorP,                           \
  const volatile Vector*: htAddI16PVectorP,                           \
  char*:                 htAddI16PString,                            \
  const volatile char*:  htAddI16PString,                            \
  char**:                htAddI16PStringP,                           \
  const volatile char**: htAddI16PStringP,                           \
  Bytes:                 htAddI16PBytes,                             \
  Bytes*:                htAddI16PBytesP,                            \
  const volatile Bytes*: htAddI16PBytesP,                            \
  void*:                 htAddI16PPointer,                           \
  void**:                htAddI16PPointerP,                          \
  const volatile void**: htAddI16PPointerP,                          \
  i8:                    htAddI16I8,                                 \
  u8:                    htAddI16U8                                  \

#define htAddI16P(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_I16P_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_U16P_KEY(dataStructure, key, value) \
  bool:                  htAddU16PBool,                              \
  bool*:                 htAddU16PBoolP,                             \
  const volatile bool*:  htAddU16PBoolP,                             \
  i16:                   htAddU16PI16,                               \
  i16*:                  htAddU16PI16P,                              \
  const volatile i16*:   htAddU16PI16P,                              \
  u16:                   htAddU16PU16,                               \
  u16*:                  htAddU16PU16P,                              \
  const volatile u16*:   htAddU16PU16P,                              \
  i32:                   htAddU16PI32,                               \
  i32*:                  htAddU16PI32P,                              \
  const volatile i32*:   htAddU16PI32P,                              \
  u32:                   htAddU16PU32,                               \
  u32*:                  htAddU16PU32P,                              \
  const volatile u32*:   htAddU16PU32P,                              \
  i64:                   htAddU16PI64,                               \
  i64*:                  htAddU16PI64P,                              \
  const volatile i64*:   htAddU16PI64P,                              \
  u64:                   htAddU16PU64,                               \
  u64*:                  htAddU16PU64P,                              \
  const volatile u64*:   htAddU16PU64P,                              \
  float:                 htAddU16PFloat,                             \
  float*:                htAddU16PFloatP,                            \
  const volatile float*: htAddU16PFloatP,                            \
  double:                htAddU16PDouble,                            \
  double*:               htAddU16PDoubleP,                           \
  const volatile double*: htAddU16PDoubleP,                           \
  long double:           htAddU16PLongDouble,                        \
  long double*:          htAddU16PLongDoubleP,                       \
  const volatile long double*: htAddU16PLongDoubleP,                       \
  List:                  htAddU16PList,                              \
  List*:                 htAddU16PListP,                             \
  const volatile List*:  htAddU16PListP,                             \
  Queue:                 htAddU16PQueue,                             \
  Queue*:                htAddU16PQueueP,                            \
  const volatile Queue*: htAddU16PQueueP,                            \
  Stack:                 htAddU16PStack,                             \
  Stack*:                htAddU16PStackP,                            \
  const volatile Stack*: htAddU16PStackP,                            \
  RedBlackTree:          htAddU16PRedBlackTree,                      \
  RedBlackTree*:         htAddU16PRedBlackTreeP,                     \
  const volatile RedBlackTree*: htAddU16PRedBlackTreeP,                     \
  HashTable:             htAddU16PHashTable,                         \
  HashTable*:            htAddU16PHashTableP,                        \
  const volatile HashTable*: htAddU16PHashTableP,                        \
  Vector:                htAddU16PVector,                            \
  Vector*:               htAddU16PVectorP,                           \
  const volatile Vector*: htAddU16PVectorP,                           \
  char*:                 htAddU16PString,                            \
  const volatile char*:  htAddU16PString,                            \
  char**:                htAddU16PStringP,                           \
  const volatile char**: htAddU16PStringP,                           \
  Bytes:                 htAddU16PBytes,                             \
  Bytes*:                htAddU16PBytesP,                            \
  const volatile Bytes*: htAddU16PBytesP,                            \
  void*:                 htAddU16PPointer,                           \
  void**:                htAddU16PPointerP,                          \
  const volatile void**: htAddU16PPointerP,                          \
  i8:                    htAddU16I8,                                 \
  u8:                    htAddU16U8                                  \

#define htAddU16P(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_U16P_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_I32P_KEY(dataStructure, key, value) \
  bool:                  htAddI32PBool,                              \
  bool*:                 htAddI32PBoolP,                             \
  const volatile bool*:  htAddI32PBoolP,                             \
  i16:                   htAddI32PI16,                               \
  i16*:                  htAddI32PI16P,                              \
  const volatile i16*:   htAddI32PI16P,                              \
  u16:                   htAddI32PU16,                               \
  u16*:                  htAddI32PU16P,                              \
  const volatile u16*:   htAddI32PU16P,                              \
  i32:                   htAddI32PI32,                               \
  i32*:                  htAddI32PI32P,                              \
  const volatile i32*:   htAddI32PI32P,                              \
  u32:                   htAddI32PU32,                               \
  u32*:                  htAddI32PU32P,                              \
  const volatile u32*:   htAddI32PU32P,                              \
  i64:                   htAddI32PI64,                               \
  i64*:                  htAddI32PI64P,                              \
  const volatile i64*:   htAddI32PI64P,                              \
  u64:                   htAddI32PU64,                               \
  u64*:                  htAddI32PU64P,                              \
  const volatile u64*:   htAddI32PU64P,                              \
  float:                 htAddI32PFloat,                             \
  float*:                htAddI32PFloatP,                            \
  const volatile float*: htAddI32PFloatP,                            \
  double:                htAddI32PDouble,                            \
  double*:               htAddI32PDoubleP,                           \
  const volatile double*: htAddI32PDoubleP,                           \
  long double:           htAddI32PLongDouble,                        \
  long double*:          htAddI32PLongDoubleP,                       \
  const volatile long double*: htAddI32PLongDoubleP,                       \
  List:                  htAddI32PList,                              \
  List*:                 htAddI32PListP,                             \
  const volatile List*:  htAddI32PListP,                             \
  Queue:                 htAddI32PQueue,                             \
  Queue*:                htAddI32PQueueP,                            \
  const volatile Queue*: htAddI32PQueueP,                            \
  Stack:                 htAddI32PStack,                             \
  Stack*:                htAddI32PStackP,                            \
  const volatile Stack*: htAddI32PStackP,                            \
  RedBlackTree:          htAddI32PRedBlackTree,                      \
  RedBlackTree*:         htAddI32PRedBlackTreeP,                     \
  const volatile RedBlackTree*: htAddI32PRedBlackTreeP,                     \
  HashTable:             htAddI32PHashTable,                         \
  HashTable*:            htAddI32PHashTableP,                        \
  const volatile HashTable*: htAddI32PHashTableP,                        \
  Vector:                htAddI32PVector,                            \
  Vector*:               htAddI32PVectorP,                           \
  const volatile Vector*: htAddI32PVectorP,                           \
  char*:                 htAddI32PString,                            \
  const volatile char*:  htAddI32PString,                            \
  char**:                htAddI32PStringP,                           \
  const volatile char**: htAddI32PStringP,                           \
  Bytes:                 htAddI32PBytes,                             \
  Bytes*:                htAddI32PBytesP,                            \
  const volatile Bytes*: htAddI32PBytesP,                            \
  void*:                 htAddI32PPointer,                           \
  void**:                htAddI32PPointerP,                          \
  const volatile void**: htAddI32PPointerP,                          \
  i8:                    htAddI32I8,                                 \
  u8:                    htAddI32U8                                  \

#define htAddI32P(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_I32P_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_U32P_KEY(dataStructure, key, value) \
  bool:                  htAddU32PBool,                              \
  bool*:                 htAddU32PBoolP,                             \
  const volatile bool*:  htAddU32PBoolP,                             \
  i16:                   htAddU32PI16,                               \
  i16*:                  htAddU32PI16P,                              \
  const volatile i16*:   htAddU32PI16P,                              \
  u16:                   htAddU32PU16,                               \
  u16*:                  htAddU32PU16P,                              \
  const volatile u16*:   htAddU32PU16P,                              \
  i32:                   htAddU32PI32,                               \
  i32*:                  htAddU32PI32P,                              \
  const volatile i32*:   htAddU32PI32P,                              \
  u32:                   htAddU32PU32,                               \
  u32*:                  htAddU32PU32P,                              \
  const volatile u32*:   htAddU32PU32P,                              \
  i64:                   htAddU32PI64,                               \
  i64*:                  htAddU32PI64P,                              \
  const volatile i64*:   htAddU32PI64P,                              \
  u64:                   htAddU32PU64,                               \
  u64*:                  htAddU32PU64P,                              \
  const volatile u64*:   htAddU32PU64P,                              \
  float:                 htAddU32PFloat,                             \
  float*:                htAddU32PFloatP,                            \
  const volatile float*: htAddU32PFloatP,                            \
  double:                htAddU32PDouble,                            \
  double*:               htAddU32PDoubleP,                           \
  const volatile double*: htAddU32PDoubleP,                           \
  long double:           htAddU32PLongDouble,                        \
  long double*:          htAddU32PLongDoubleP,                       \
  const volatile long double*: htAddU32PLongDoubleP,                       \
  List:                  htAddU32PList,                              \
  List*:                 htAddU32PListP,                             \
  const volatile List*:  htAddU32PListP,                             \
  Queue:                 htAddU32PQueue,                             \
  Queue*:                htAddU32PQueueP,                            \
  const volatile Queue*: htAddU32PQueueP,                            \
  Stack:                 htAddU32PStack,                             \
  Stack*:                htAddU32PStackP,                            \
  const volatile Stack*: htAddU32PStackP,                            \
  RedBlackTree:          htAddU32PRedBlackTree,                      \
  RedBlackTree*:         htAddU32PRedBlackTreeP,                     \
  const volatile RedBlackTree*: htAddU32PRedBlackTreeP,                     \
  HashTable:             htAddU32PHashTable,                         \
  HashTable*:            htAddU32PHashTableP,                        \
  const volatile HashTable*: htAddU32PHashTableP,                        \
  Vector:                htAddU32PVector,                            \
  Vector*:               htAddU32PVectorP,                           \
  const volatile Vector*: htAddU32PVectorP,                           \
  char*:                 htAddU32PString,                            \
  const volatile char*:  htAddU32PString,                            \
  char**:                htAddU32PStringP,                           \
  const volatile char**: htAddU32PStringP,                           \
  Bytes:                 htAddU32PBytes,                             \
  Bytes*:                htAddU32PBytesP,                            \
  const volatile Bytes*: htAddU32PBytesP,                            \
  void*:                 htAddU32PPointer,                           \
  void**:                htAddU32PPointerP,                          \
  const volatile void**: htAddU32PPointerP,                          \
  i8:                    htAddU32I8,                                 \
  u8:                    htAddU32U8                                  \

#define htAddU32P(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_U32P_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_I64P_KEY(dataStructure, key, value) \
  bool:                  htAddI64PBool,                              \
  bool*:                 htAddI64PBoolP,                             \
  const volatile bool*:  htAddI64PBoolP,                             \
  i16:                   htAddI64PI16,                               \
  i16*:                  htAddI64PI16P,                              \
  const volatile i16*:   htAddI64PI16P,                              \
  u16:                   htAddI64PU16,                               \
  u16*:                  htAddI64PU16P,                              \
  const volatile u16*:   htAddI64PU16P,                              \
  i32:                   htAddI64PI32,                               \
  i32*:                  htAddI64PI32P,                              \
  const volatile i32*:   htAddI64PI32P,                              \
  u32:                   htAddI64PU32,                               \
  u32*:                  htAddI64PU32P,                              \
  const volatile u32*:   htAddI64PU32P,                              \
  i64:                   htAddI64PI64,                               \
  i64*:                  htAddI64PI64P,                              \
  const volatile i64*:   htAddI64PI64P,                              \
  u64:                   htAddI64PU64,                               \
  u64*:                  htAddI64PU64P,                              \
  const volatile u64*:   htAddI64PU64P,                              \
  float:                 htAddI64PFloat,                             \
  float*:                htAddI64PFloatP,                            \
  const volatile float*: htAddI64PFloatP,                            \
  double:                htAddI64PDouble,                            \
  double*:               htAddI64PDoubleP,                           \
  const volatile double*: htAddI64PDoubleP,                           \
  long double:           htAddI64PLongDouble,                        \
  long double*:          htAddI64PLongDoubleP,                       \
  const volatile long double*: htAddI64PLongDoubleP,                       \
  List:                  htAddI64PList,                              \
  List*:                 htAddI64PListP,                             \
  const volatile List*:  htAddI64PListP,                             \
  Queue:                 htAddI64PQueue,                             \
  Queue*:                htAddI64PQueueP,                            \
  const volatile Queue*: htAddI64PQueueP,                            \
  Stack:                 htAddI64PStack,                             \
  Stack*:                htAddI64PStackP,                            \
  const volatile Stack*: htAddI64PStackP,                            \
  RedBlackTree:          htAddI64PRedBlackTree,                      \
  RedBlackTree*:         htAddI64PRedBlackTreeP,                     \
  const volatile RedBlackTree*: htAddI64PRedBlackTreeP,                     \
  HashTable:             htAddI64PHashTable,                         \
  HashTable*:            htAddI64PHashTableP,                        \
  const volatile HashTable*: htAddI64PHashTableP,                        \
  Vector:                htAddI64PVector,                            \
  Vector*:               htAddI64PVectorP,                           \
  const volatile Vector*: htAddI64PVectorP,                           \
  char*:                 htAddI64PString,                            \
  const volatile char*:  htAddI64PString,                            \
  char**:                htAddI64PStringP,                           \
  const volatile char**: htAddI64PStringP,                           \
  Bytes:                 htAddI64PBytes,                             \
  Bytes*:                htAddI64PBytesP,                            \
  const volatile Bytes*: htAddI64PBytesP,                            \
  void*:                 htAddI64PPointer,                           \
  void**:                htAddI64PPointerP,                          \
  const volatile void**: htAddI64PPointerP,                          \
  i8:                    htAddI64I8,                                 \
  u8:                    htAddI64U8                                  \

#define htAddI64P(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_I64P_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_U64P_KEY(dataStructure, key, value) \
  bool:                  htAddU64PBool,                              \
  bool*:                 htAddU64PBoolP,                             \
  const volatile bool*:  htAddU64PBoolP,                             \
  i16:                   htAddU64PI16,                               \
  i16*:                  htAddU64PI16P,                              \
  const volatile i16*:   htAddU64PI16P,                              \
  u16:                   htAddU64PU16,                               \
  u16*:                  htAddU64PU16P,                              \
  const volatile u16*:   htAddU64PU16P,                              \
  i32:                   htAddU64PI32,                               \
  i32*:                  htAddU64PI32P,                              \
  const volatile i32*:   htAddU64PI32P,                              \
  u32:                   htAddU64PU32,                               \
  u32*:                  htAddU64PU32P,                              \
  const volatile u32*:   htAddU64PU32P,                              \
  i64:                   htAddU64PI64,                               \
  i64*:                  htAddU64PI64P,                              \
  const volatile i64*:   htAddU64PI64P,                              \
  u64:                   htAddU64PU64,                               \
  u64*:                  htAddU64PU64P,                              \
  const volatile u64*:   htAddU64PU64P,                              \
  float:                 htAddU64PFloat,                             \
  float*:                htAddU64PFloatP,                            \
  const volatile float*: htAddU64PFloatP,                            \
  double:                htAddU64PDouble,                            \
  double*:               htAddU64PDoubleP,                           \
  const volatile double*: htAddU64PDoubleP,                           \
  long double:           htAddU64PLongDouble,                        \
  long double*:          htAddU64PLongDoubleP,                       \
  const volatile long double*: htAddU64PLongDoubleP,                       \
  List:                  htAddU64PList,                              \
  List*:                 htAddU64PListP,                             \
  const volatile List*:  htAddU64PListP,                             \
  Queue:                 htAddU64PQueue,                             \
  Queue*:                htAddU64PQueueP,                            \
  const volatile Queue*: htAddU64PQueueP,                            \
  Stack:                 htAddU64PStack,                             \
  Stack*:                htAddU64PStackP,                            \
  const volatile Stack*: htAddU64PStackP,                            \
  RedBlackTree:          htAddU64PRedBlackTree,                      \
  RedBlackTree*:         htAddU64PRedBlackTreeP,                     \
  const volatile RedBlackTree*: htAddU64PRedBlackTreeP,                     \
  HashTable:             htAddU64PHashTable,                         \
  HashTable*:            htAddU64PHashTableP,                        \
  const volatile HashTable*: htAddU64PHashTableP,                        \
  Vector:                htAddU64PVector,                            \
  Vector*:               htAddU64PVectorP,                           \
  const volatile Vector*: htAddU64PVectorP,                           \
  char*:                 htAddU64PString,                            \
  const volatile char*:  htAddU64PString,                            \
  char**:                htAddU64PStringP,                           \
  const volatile char**: htAddU64PStringP,                           \
  Bytes:                 htAddU64PBytes,                             \
  Bytes*:                htAddU64PBytesP,                            \
  const volatile Bytes*: htAddU64PBytesP,                            \
  void*:                 htAddU64PPointer,                           \
  void**:                htAddU64PPointerP,                          \
  const volatile void**: htAddU64PPointerP,                          \
  i8:                    htAddU64I8,                                 \
  u8:                    htAddU64U8                                  \

#define htAddU64P(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_U64P_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_FLOATP_KEY(dataStructure, key, value) \
  bool:                  htAddFloatPBool,                            \
  bool*:                 htAddFloatPBoolP,                           \
  const volatile bool*:  htAddFloatPBoolP,                           \
  i16:                   htAddFloatPI16,                             \
  i16*:                  htAddFloatPI16P,                            \
  const volatile i16*:   htAddFloatPI16P,                            \
  u16:                   htAddFloatPU16,                             \
  u16*:                  htAddFloatPU16P,                            \
  const volatile u16*:   htAddFloatPU16P,                            \
  i32:                   htAddFloatPI32,                             \
  i32*:                  htAddFloatPI32P,                            \
  const volatile i32*:   htAddFloatPI32P,                            \
  u32:                   htAddFloatPU32,                             \
  u32*:                  htAddFloatPU32P,                            \
  const volatile u32*:   htAddFloatPU32P,                            \
  i64:                   htAddFloatPI64,                             \
  i64*:                  htAddFloatPI64P,                            \
  const volatile i64*:   htAddFloatPI64P,                            \
  u64:                   htAddFloatPU64,                             \
  u64*:                  htAddFloatPU64P,                            \
  const volatile u64*:   htAddFloatPU64P,                            \
  float:                 htAddFloatPFloat,                           \
  float*:                htAddFloatPFloatP,                          \
  const volatile float*: htAddFloatPFloatP,                          \
  double:                htAddFloatPDouble,                          \
  double*:               htAddFloatPDoubleP,                         \
  const volatile double*: htAddFloatPDoubleP,                         \
  long double:           htAddFloatPLongDouble,                      \
  long double*:          htAddFloatPLongDoubleP,                     \
  const volatile long double*: htAddFloatPLongDoubleP,                     \
  List:                  htAddFloatPList,                            \
  List*:                 htAddFloatPListP,                           \
  const volatile List*:  htAddFloatPListP,                           \
  Queue:                 htAddFloatPQueue,                           \
  Queue*:                htAddFloatPQueueP,                          \
  const volatile Queue*: htAddFloatPQueueP,                          \
  Stack:                 htAddFloatPStack,                           \
  Stack*:                htAddFloatPStackP,                          \
  const volatile Stack*: htAddFloatPStackP,                          \
  RedBlackTree:          htAddFloatPRedBlackTree,                    \
  RedBlackTree*:         htAddFloatPRedBlackTreeP,                   \
  const volatile RedBlackTree*: htAddFloatPRedBlackTreeP,                   \
  HashTable:             htAddFloatPHashTable,                       \
  HashTable*:            htAddFloatPHashTableP,                      \
  const volatile HashTable*: htAddFloatPHashTableP,                      \
  Vector:                htAddFloatPVector,                          \
  Vector*:               htAddFloatPVectorP,                         \
  const volatile Vector*: htAddFloatPVectorP,                         \
  char*:                 htAddFloatPString,                          \
  const volatile char*:  htAddFloatPString,                          \
  char**:                htAddFloatPStringP,                         \
  const volatile char**: htAddFloatPStringP,                         \
  Bytes:                 htAddFloatPBytes,                           \
  Bytes*:                htAddFloatPBytesP,                          \
  const volatile Bytes*: htAddFloatPBytesP,                          \
  void*:                 htAddFloatPPointer,                         \
  void**:                htAddFloatPPointerP,                        \
  const volatile void**: htAddFloatPPointerP,                        \
  i8:                    htAddFloatI8,                               \
  u8:                    htAddFloatU8                                \

#define htAddFloatP(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_FLOATP_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_DOUBLEP_KEY(dataStructure, key, value) \
  bool:                  htAddDoublePBool,                           \
  bool*:                 htAddDoublePBoolP,                          \
  const volatile bool*:  htAddDoublePBoolP,                          \
  i16:                   htAddDoublePI16,                            \
  i16*:                  htAddDoublePI16P,                           \
  const volatile i16*:   htAddDoublePI16P,                           \
  u16:                   htAddDoublePU16,                            \
  u16*:                  htAddDoublePU16P,                           \
  const volatile u16*:   htAddDoublePU16P,                           \
  i32:                   htAddDoublePI32,                            \
  i32*:                  htAddDoublePI32P,                           \
  const volatile i32*:   htAddDoublePI32P,                           \
  u32:                   htAddDoublePU32,                            \
  u32*:                  htAddDoublePU32P,                           \
  const volatile u32*:   htAddDoublePU32P,                           \
  i64:                   htAddDoublePI64,                            \
  i64*:                  htAddDoublePI64P,                           \
  const volatile i64*:   htAddDoublePI64P,                           \
  u64:                   htAddDoublePU64,                            \
  u64*:                  htAddDoublePU64P,                           \
  const volatile u64*:   htAddDoublePU64P,                           \
  float:                 htAddDoublePFloat,                          \
  float*:                htAddDoublePFloatP,                         \
  const volatile float*: htAddDoublePFloatP,                         \
  double:                htAddDoublePDouble,                         \
  double*:               htAddDoublePDoubleP,                        \
  const volatile double*: htAddDoublePDoubleP,                        \
  long double:           htAddDoublePLongDouble,                     \
  long double*:          htAddDoublePLongDoubleP,                    \
  const volatile long double*: htAddDoublePLongDoubleP,                    \
  List:                  htAddDoublePList,                           \
  List*:                 htAddDoublePListP,                          \
  const volatile List*:  htAddDoublePListP,                          \
  Queue:                 htAddDoublePQueue,                          \
  Queue*:                htAddDoublePQueueP,                         \
  const volatile Queue*: htAddDoublePQueueP,                         \
  Stack:                 htAddDoublePStack,                          \
  Stack*:                htAddDoublePStackP,                         \
  const volatile Stack*: htAddDoublePStackP,                         \
  RedBlackTree:          htAddDoublePRedBlackTree,                   \
  RedBlackTree*:         htAddDoublePRedBlackTreeP,                  \
  const volatile RedBlackTree*: htAddDoublePRedBlackTreeP,                  \
  HashTable:             htAddDoublePHashTable,                      \
  HashTable*:            htAddDoublePHashTableP,                     \
  const volatile HashTable*: htAddDoublePHashTableP,                     \
  Vector:                htAddDoublePVector,                         \
  Vector*:               htAddDoublePVectorP,                        \
  const volatile Vector*: htAddDoublePVectorP,                        \
  char*:                 htAddDoublePString,                         \
  const volatile char*:  htAddDoublePString,                         \
  char**:                htAddDoublePStringP,                        \
  const volatile char**: htAddDoublePStringP,                        \
  Bytes:                 htAddDoublePBytes,                          \
  Bytes*:                htAddDoublePBytesP,                         \
  const volatile Bytes*: htAddDoublePBytesP,                         \
  void*:                 htAddDoublePPointer,                        \
  void**:                htAddDoublePPointerP,                       \
  const volatile void**: htAddDoublePPointerP,                       \
  i8:                    htAddDoubleI8,                              \
  u8:                    htAddDoubleU8                               \

#define htAddDoubleP(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_DOUBLEP_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_LONG_DOUBLEP_KEY(dataStructure, key, value) \
  bool:                  htAddLongDoublePBool,                       \
  bool*:                 htAddLongDoublePBoolP,                      \
  const volatile bool*:  htAddLongDoublePBoolP,                      \
  i16:                   htAddLongDoublePI16,                        \
  i16*:                  htAddLongDoublePI16P,                       \
  const volatile i16*:   htAddLongDoublePI16P,                       \
  u16:                   htAddLongDoublePU16,                        \
  u16*:                  htAddLongDoublePU16P,                       \
  const volatile u16*:   htAddLongDoublePU16P,                       \
  i32:                   htAddLongDoublePI32,                        \
  i32*:                  htAddLongDoublePI32P,                       \
  const volatile i32*:   htAddLongDoublePI32P,                       \
  u32:                   htAddLongDoublePU32,                        \
  u32*:                  htAddLongDoublePU32P,                       \
  const volatile u32*:   htAddLongDoublePU32P,                       \
  i64:                   htAddLongDoublePI64,                        \
  i64*:                  htAddLongDoublePI64P,                       \
  const volatile i64*:   htAddLongDoublePI64P,                       \
  u64:                   htAddLongDoublePU64,                        \
  u64*:                  htAddLongDoublePU64P,                       \
  const volatile u64*:   htAddLongDoublePU64P,                       \
  float:                 htAddLongDoublePFloat,                      \
  float*:                htAddLongDoublePFloatP,                     \
  const volatile float*: htAddLongDoublePFloatP,                     \
  double:                htAddLongDoublePDouble,                     \
  double*:               htAddLongDoublePDoubleP,                    \
  const volatile double*: htAddLongDoublePDoubleP,                    \
  long double:           htAddLongDoublePLongDouble,                 \
  long double*:          htAddLongDoublePLongDoubleP,                \
  const volatile long double*: htAddLongDoublePLongDoubleP,                \
  List:                  htAddLongDoublePList,                       \
  List*:                 htAddLongDoublePListP,                      \
  const volatile List*:  htAddLongDoublePListP,                      \
  Queue:                 htAddLongDoublePQueue,                      \
  Queue*:                htAddLongDoublePQueueP,                     \
  const volatile Queue*: htAddLongDoublePQueueP,                     \
  Stack:                 htAddLongDoublePStack,                      \
  Stack*:                htAddLongDoublePStackP,                     \
  const volatile Stack*: htAddLongDoublePStackP,                     \
  RedBlackTree:          htAddLongDoublePRedBlackTree,               \
  RedBlackTree*:         htAddLongDoublePRedBlackTreeP,              \
  const volatile RedBlackTree*: htAddLongDoublePRedBlackTreeP,              \
  HashTable:             htAddLongDoublePHashTable,                  \
  HashTable*:            htAddLongDoublePHashTableP,                 \
  const volatile HashTable*: htAddLongDoublePHashTableP,                 \
  Vector:                htAddLongDoublePVector,                     \
  Vector*:               htAddLongDoublePVectorP,                    \
  const volatile Vector*: htAddLongDoublePVectorP,                    \
  char*:                 htAddLongDoublePString,                     \
  const volatile char*:  htAddLongDoublePString,                     \
  char**:                htAddLongDoublePStringP,                    \
  const volatile char**: htAddLongDoublePStringP,                    \
  Bytes:                 htAddLongDoublePBytes,                      \
  Bytes*:                htAddLongDoublePBytesP,                     \
  const volatile Bytes*: htAddLongDoublePBytesP,                     \
  void*:                 htAddLongDoublePPointer,                    \
  void**:                htAddLongDoublePPointerP,                   \
  const volatile void**: htAddLongDoublePPointerP,                   \
  i8:                    htAddLongDoubleI8,                          \
  u8:                    htAddLongDoubleU8                           \

#define htAddLongDoubleP(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_LONG_DOUBLEP_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_LISTP_KEY(dataStructure, key, value) \
  bool:                  htAddListPBool,                             \
  bool*:                 htAddListPBoolP,                            \
  const volatile bool*:  htAddListPBoolP,                            \
  i16:                   htAddListPI16,                              \
  i16*:                  htAddListPI16P,                             \
  const volatile i16*:   htAddListPI16P,                             \
  u16:                   htAddListPU16,                              \
  u16*:                  htAddListPU16P,                             \
  const volatile u16*:   htAddListPU16P,                             \
  i32:                   htAddListPI32,                              \
  i32*:                  htAddListPI32P,                             \
  const volatile i32*:   htAddListPI32P,                             \
  u32:                   htAddListPU32,                              \
  u32*:                  htAddListPU32P,                             \
  const volatile u32*:   htAddListPU32P,                             \
  i64:                   htAddListPI64,                              \
  i64*:                  htAddListPI64P,                             \
  const volatile i64*:   htAddListPI64P,                             \
  u64:                   htAddListPU64,                              \
  u64*:                  htAddListPU64P,                             \
  const volatile u64*:   htAddListPU64P,                             \
  float:                 htAddListPFloat,                            \
  float*:                htAddListPFloatP,                           \
  const volatile float*: htAddListPFloatP,                           \
  double:                htAddListPDouble,                           \
  double*:               htAddListPDoubleP,                          \
  const volatile double*: htAddListPDoubleP,                          \
  long double:           htAddListPLongDouble,                       \
  long double*:          htAddListPLongDoubleP,                      \
  const volatile long double*: htAddListPLongDoubleP,                      \
  List:                  htAddListPList,                             \
  List*:                 htAddListPListP,                            \
  const volatile List*:  htAddListPListP,                            \
  Queue:                 htAddListPQueue,                            \
  Queue*:                htAddListPQueueP,                           \
  const volatile Queue*: htAddListPQueueP,                           \
  Stack:                 htAddListPStack,                            \
  Stack*:                htAddListPStackP,                           \
  const volatile Stack*: htAddListPStackP,                           \
  RedBlackTree:          htAddListPRedBlackTree,                     \
  RedBlackTree*:         htAddListPRedBlackTreeP,                    \
  const volatile RedBlackTree*: htAddListPRedBlackTreeP,                    \
  HashTable:             htAddListPHashTable,                        \
  HashTable*:            htAddListPHashTableP,                       \
  const volatile HashTable*: htAddListPHashTableP,                       \
  Vector:                htAddListPVector,                           \
  Vector*:               htAddListPVectorP,                          \
  const volatile Vector*: htAddListPVectorP,                          \
  char*:                 htAddListPString,                           \
  const volatile char*:  htAddListPString,                           \
  char**:                htAddListPStringP,                          \
  const volatile char**: htAddListPStringP,                          \
  Bytes:                 htAddListPBytes,                            \
  Bytes*:                htAddListPBytesP,                           \
  const volatile Bytes*: htAddListPBytesP,                           \
  void*:                 htAddListPPointer,                          \
  void**:                htAddListPPointerP,                         \
  const volatile void**: htAddListPPointerP,                         \
  i8:                    htAddListI8,                                \
  u8:                    htAddListU8                                 \

#define htAddListP(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_LISTP_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_QUEUEP_KEY(dataStructure, key, value) \
  bool:                  htAddQueuePBool,                            \
  bool*:                 htAddQueuePBoolP,                           \
  const volatile bool*:  htAddQueuePBoolP,                           \
  i16:                   htAddQueuePI16,                             \
  i16*:                  htAddQueuePI16P,                            \
  const volatile i16*:   htAddQueuePI16P,                            \
  u16:                   htAddQueuePU16,                             \
  u16*:                  htAddQueuePU16P,                            \
  const volatile u16*:   htAddQueuePU16P,                            \
  i32:                   htAddQueuePI32,                             \
  i32*:                  htAddQueuePI32P,                            \
  const volatile i32*:   htAddQueuePI32P,                            \
  u32:                   htAddQueuePU32,                             \
  u32*:                  htAddQueuePU32P,                            \
  const volatile u32*:   htAddQueuePU32P,                            \
  i64:                   htAddQueuePI64,                             \
  i64*:                  htAddQueuePI64P,                            \
  const volatile i64*:   htAddQueuePI64P,                            \
  u64:                   htAddQueuePU64,                             \
  u64*:                  htAddQueuePU64P,                            \
  const volatile u64*:   htAddQueuePU64P,                            \
  float:                 htAddQueuePFloat,                           \
  float*:                htAddQueuePFloatP,                          \
  const volatile float*: htAddQueuePFloatP,                          \
  double:                htAddQueuePDouble,                          \
  double*:               htAddQueuePDoubleP,                         \
  const volatile double*: htAddQueuePDoubleP,                         \
  long double:           htAddQueuePLongDouble,                      \
  long double*:          htAddQueuePLongDoubleP,                     \
  const volatile long double*: htAddQueuePLongDoubleP,                     \
  List:                  htAddQueuePList,                            \
  List*:                 htAddQueuePListP,                           \
  const volatile List*:  htAddQueuePListP,                           \
  Queue:                 htAddQueuePQueue,                           \
  Queue*:                htAddQueuePQueueP,                          \
  const volatile Queue*: htAddQueuePQueueP,                          \
  Stack:                 htAddQueuePStack,                           \
  Stack*:                htAddQueuePStackP,                          \
  const volatile Stack*: htAddQueuePStackP,                          \
  RedBlackTree:          htAddQueuePRedBlackTree,                    \
  RedBlackTree*:         htAddQueuePRedBlackTreeP,                   \
  const volatile RedBlackTree*: htAddQueuePRedBlackTreeP,                   \
  HashTable:             htAddQueuePHashTable,                       \
  HashTable*:            htAddQueuePHashTableP,                      \
  const volatile HashTable*: htAddQueuePHashTableP,                      \
  Vector:                htAddQueuePVector,                          \
  Vector*:               htAddQueuePVectorP,                         \
  const volatile Vector*: htAddQueuePVectorP,                         \
  char*:                 htAddQueuePString,                          \
  const volatile char*:  htAddQueuePString,                          \
  char**:                htAddQueuePStringP,                         \
  const volatile char**: htAddQueuePStringP,                         \
  Bytes:                 htAddQueuePBytes,                           \
  Bytes*:                htAddQueuePBytesP,                          \
  const volatile Bytes*: htAddQueuePBytesP,                          \
  void*:                 htAddQueuePPointer,                         \
  void**:                htAddQueuePPointerP,                        \
  const volatile void**: htAddQueuePPointerP,                        \
  i8:                    htAddQueueI8,                               \
  u8:                    htAddQueueU8                                \

#define htAddQueueP(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_QUEUEP_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_STACKP_KEY(dataStructure, key, value) \
  bool:                  htAddStackPBool,                            \
  bool*:                 htAddStackPBoolP,                           \
  const volatile bool*:  htAddStackPBoolP,                           \
  i16:                   htAddStackPI16,                             \
  i16*:                  htAddStackPI16P,                            \
  const volatile i16*:   htAddStackPI16P,                            \
  u16:                   htAddStackPU16,                             \
  u16*:                  htAddStackPU16P,                            \
  const volatile u16*:   htAddStackPU16P,                            \
  i32:                   htAddStackPI32,                             \
  i32*:                  htAddStackPI32P,                            \
  const volatile i32*:   htAddStackPI32P,                            \
  u32:                   htAddStackPU32,                             \
  u32*:                  htAddStackPU32P,                            \
  const volatile u32*:   htAddStackPU32P,                            \
  i64:                   htAddStackPI64,                             \
  i64*:                  htAddStackPI64P,                            \
  const volatile i64*:   htAddStackPI64P,                            \
  u64:                   htAddStackPU64,                             \
  u64*:                  htAddStackPU64P,                            \
  const volatile u64*:   htAddStackPU64P,                            \
  float:                 htAddStackPFloat,                           \
  float*:                htAddStackPFloatP,                          \
  const volatile float*: htAddStackPFloatP,                          \
  double:                htAddStackPDouble,                          \
  double*:               htAddStackPDoubleP,                         \
  const volatile double*: htAddStackPDoubleP,                         \
  long double:           htAddStackPLongDouble,                      \
  long double*:          htAddStackPLongDoubleP,                     \
  const volatile long double*: htAddStackPLongDoubleP,                     \
  List:                  htAddStackPList,                            \
  List*:                 htAddStackPListP,                           \
  const volatile List*:  htAddStackPListP,                           \
  Queue:                 htAddStackPQueue,                           \
  Queue*:                htAddStackPQueueP,                          \
  const volatile Queue*: htAddStackPQueueP,                          \
  Stack:                 htAddStackPStack,                           \
  Stack*:                htAddStackPStackP,                          \
  const volatile Stack*: htAddStackPStackP,                          \
  RedBlackTree:          htAddStackPRedBlackTree,                    \
  RedBlackTree*:         htAddStackPRedBlackTreeP,                   \
  const volatile RedBlackTree*: htAddStackPRedBlackTreeP,                   \
  HashTable:             htAddStackPHashTable,                       \
  HashTable*:            htAddStackPHashTableP,                      \
  const volatile HashTable*: htAddStackPHashTableP,                      \
  Vector:                htAddStackPVector,                          \
  Vector*:               htAddStackPVectorP,                         \
  const volatile Vector*: htAddStackPVectorP,                         \
  char*:                 htAddStackPString,                          \
  const volatile char*:  htAddStackPString,                          \
  char**:                htAddStackPStringP,                         \
  const volatile char**: htAddStackPStringP,                         \
  Bytes:                 htAddStackPBytes,                           \
  Bytes*:                htAddStackPBytesP,                          \
  const volatile Bytes*: htAddStackPBytesP,                          \
  void*:                 htAddStackPPointer,                         \
  void**:                htAddStackPPointerP,                        \
  const volatile void**: htAddStackPPointerP,                        \
  i8:                    htAddStackI8,                               \
  u8:                    htAddStackU8                                \

#define htAddStackP(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_STACKP_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_RED_BLACK_TREEP_KEY(dataStructure, key, value) \
  bool:                  htAddRedBlackTreePBool,                     \
  bool*:                 htAddRedBlackTreePBoolP,                    \
  const volatile bool*:  htAddRedBlackTreePBoolP,                    \
  i16:                   htAddRedBlackTreePI16,                      \
  i16*:                  htAddRedBlackTreePI16P,                     \
  const volatile i16*:   htAddRedBlackTreePI16P,                     \
  u16:                   htAddRedBlackTreePU16,                      \
  u16*:                  htAddRedBlackTreePU16P,                     \
  const volatile u16*:   htAddRedBlackTreePU16P,                     \
  i32:                   htAddRedBlackTreePI32,                      \
  i32*:                  htAddRedBlackTreePI32P,                     \
  const volatile i32*:   htAddRedBlackTreePI32P,                     \
  u32:                   htAddRedBlackTreePU32,                      \
  u32*:                  htAddRedBlackTreePU32P,                     \
  const volatile u32*:   htAddRedBlackTreePU32P,                     \
  i64:                   htAddRedBlackTreePI64,                      \
  i64*:                  htAddRedBlackTreePI64P,                     \
  const volatile i64*:   htAddRedBlackTreePI64P,                     \
  u64:                   htAddRedBlackTreePU64,                      \
  u64*:                  htAddRedBlackTreePU64P,                     \
  const volatile u64*:   htAddRedBlackTreePU64P,                     \
  float:                 htAddRedBlackTreePFloat,                    \
  float*:                htAddRedBlackTreePFloatP,                   \
  const volatile float*: htAddRedBlackTreePFloatP,                   \
  double:                htAddRedBlackTreePDouble,                   \
  double*:               htAddRedBlackTreePDoubleP,                  \
  const volatile double*: htAddRedBlackTreePDoubleP,                  \
  long double:           htAddRedBlackTreePLongDouble,               \
  long double*:          htAddRedBlackTreePLongDoubleP,              \
  const volatile long double*: htAddRedBlackTreePLongDoubleP,              \
  List:                  htAddRedBlackTreePList,                     \
  List*:                 htAddRedBlackTreePListP,                    \
  const volatile List*:  htAddRedBlackTreePListP,                    \
  Queue:                 htAddRedBlackTreePQueue,                    \
  Queue*:                htAddRedBlackTreePQueueP,                   \
  const volatile Queue*: htAddRedBlackTreePQueueP,                   \
  Stack:                 htAddRedBlackTreePStack,                    \
  Stack*:                htAddRedBlackTreePStackP,                   \
  const volatile Stack*: htAddRedBlackTreePStackP,                   \
  RedBlackTree:          htAddRedBlackTreePRedBlackTree,             \
  RedBlackTree*:         htAddRedBlackTreePRedBlackTreeP,            \
  const volatile RedBlackTree*: htAddRedBlackTreePRedBlackTreeP,            \
  HashTable:             htAddRedBlackTreePHashTable,                \
  HashTable*:            htAddRedBlackTreePHashTableP,               \
  const volatile HashTable*: htAddRedBlackTreePHashTableP,               \
  Vector:                htAddRedBlackTreePVector,                   \
  Vector*:               htAddRedBlackTreePVectorP,                  \
  const volatile Vector*: htAddRedBlackTreePVectorP,                  \
  char*:                 htAddRedBlackTreePString,                   \
  const volatile char*:  htAddRedBlackTreePString,                   \
  char**:                htAddRedBlackTreePStringP,                  \
  const volatile char**: htAddRedBlackTreePStringP,                  \
  Bytes:                 htAddRedBlackTreePBytes,                    \
  Bytes*:                htAddRedBlackTreePBytesP,                   \
  const volatile Bytes*: htAddRedBlackTreePBytesP,                   \
  void*:                 htAddRedBlackTreePPointer,                  \
  void**:                htAddRedBlackTreePPointerP,                 \
  const volatile void**: htAddRedBlackTreePPointerP,                 \
  i8:                    htAddRedBlackTreeI8,                        \
  u8:                    htAddRedBlackTreeU8                         \

#define htAddRedBlackTreeP(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_RED_BLACK_TREEP_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_HASH_TABLEP_KEY(dataStructure, key, value) \
  bool:                  htAddHashTablePBool,                        \
  bool*:                 htAddHashTablePBoolP,                       \
  const volatile bool*:  htAddHashTablePBoolP,                       \
  i16:                   htAddHashTablePI16,                         \
  i16*:                  htAddHashTablePI16P,                        \
  const volatile i16*:   htAddHashTablePI16P,                        \
  u16:                   htAddHashTablePU16,                         \
  u16*:                  htAddHashTablePU16P,                        \
  const volatile u16*:   htAddHashTablePU16P,                        \
  i32:                   htAddHashTablePI32,                         \
  i32*:                  htAddHashTablePI32P,                        \
  const volatile i32*:   htAddHashTablePI32P,                        \
  u32:                   htAddHashTablePU32,                         \
  u32*:                  htAddHashTablePU32P,                        \
  const volatile u32*:   htAddHashTablePU32P,                        \
  i64:                   htAddHashTablePI64,                         \
  i64*:                  htAddHashTablePI64P,                        \
  const volatile i64*:   htAddHashTablePI64P,                        \
  u64:                   htAddHashTablePU64,                         \
  u64*:                  htAddHashTablePU64P,                        \
  const volatile u64*:   htAddHashTablePU64P,                        \
  float:                 htAddHashTablePFloat,                       \
  float*:                htAddHashTablePFloatP,                      \
  const volatile float*: htAddHashTablePFloatP,                      \
  double:                htAddHashTablePDouble,                      \
  double*:               htAddHashTablePDoubleP,                     \
  const volatile double*: htAddHashTablePDoubleP,                     \
  long double:           htAddHashTablePLongDouble,                  \
  long double*:          htAddHashTablePLongDoubleP,                 \
  const volatile long double*: htAddHashTablePLongDoubleP,                 \
  List:                  htAddHashTablePList,                        \
  List*:                 htAddHashTablePListP,                       \
  const volatile List*:  htAddHashTablePListP,                       \
  Queue:                 htAddHashTablePQueue,                       \
  Queue*:                htAddHashTablePQueueP,                      \
  const volatile Queue*: htAddHashTablePQueueP,                      \
  Stack:                 htAddHashTablePStack,                       \
  Stack*:                htAddHashTablePStackP,                      \
  const volatile Stack*: htAddHashTablePStackP,                      \
  RedBlackTree:          htAddHashTablePRedBlackTree,                \
  RedBlackTree*:         htAddHashTablePRedBlackTreeP,               \
  const volatile RedBlackTree*: htAddHashTablePRedBlackTreeP,               \
  HashTable:             htAddHashTablePHashTable,                   \
  HashTable*:            htAddHashTablePHashTableP,                  \
  const volatile HashTable*: htAddHashTablePHashTableP,                  \
  Vector:                htAddHashTablePVector,                      \
  Vector*:               htAddHashTablePVectorP,                     \
  const volatile Vector*: htAddHashTablePVectorP,                     \
  char*:                 htAddHashTablePString,                      \
  const volatile char*:  htAddHashTablePString,                      \
  char**:                htAddHashTablePStringP,                     \
  const volatile char**: htAddHashTablePStringP,                     \
  Bytes:                 htAddHashTablePBytes,                       \
  Bytes*:                htAddHashTablePBytesP,                      \
  const volatile Bytes*: htAddHashTablePBytesP,                      \
  void*:                 htAddHashTablePPointer,                     \
  void**:                htAddHashTablePPointerP,                    \
  const volatile void**: htAddHashTablePPointerP,                    \
  i8:                    htAddHashTableI8,                           \
  u8:                    htAddHashTableU8                            \

#define htAddHashTableP(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_HASH_TABLEP_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_VECTORP_KEY(dataStructure, key, value) \
  bool:                  htAddVectorPBool,                           \
  bool*:                 htAddVectorPBoolP,                          \
  const volatile bool*:  htAddVectorPBoolP,                          \
  i16:                   htAddVectorPI16,                            \
  i16*:                  htAddVectorPI16P,                           \
  const volatile i16*:   htAddVectorPI16P,                           \
  u16:                   htAddVectorPU16,                            \
  u16*:                  htAddVectorPU16P,                           \
  const volatile u16*:   htAddVectorPU16P,                           \
  i32:                   htAddVectorPI32,                            \
  i32*:                  htAddVectorPI32P,                           \
  const volatile i32*:   htAddVectorPI32P,                           \
  u32:                   htAddVectorPU32,                            \
  u32*:                  htAddVectorPU32P,                           \
  const volatile u32*:   htAddVectorPU32P,                           \
  i64:                   htAddVectorPI64,                            \
  i64*:                  htAddVectorPI64P,                           \
  const volatile i64*:   htAddVectorPI64P,                           \
  u64:                   htAddVectorPU64,                            \
  u64*:                  htAddVectorPU64P,                           \
  const volatile u64*:   htAddVectorPU64P,                           \
  float:                 htAddVectorPFloat,                          \
  float*:                htAddVectorPFloatP,                         \
  const volatile float*: htAddVectorPFloatP,                         \
  double:                htAddVectorPDouble,                         \
  double*:               htAddVectorPDoubleP,                        \
  const volatile double*: htAddVectorPDoubleP,                        \
  long double:           htAddVectorPLongDouble,                     \
  long double*:          htAddVectorPLongDoubleP,                    \
  const volatile long double*: htAddVectorPLongDoubleP,                    \
  List:                  htAddVectorPList,                           \
  List*:                 htAddVectorPListP,                          \
  const volatile List*:  htAddVectorPListP,                          \
  Queue:                 htAddVectorPQueue,                          \
  Queue*:                htAddVectorPQueueP,                         \
  const volatile Queue*: htAddVectorPQueueP,                         \
  Stack:                 htAddVectorPStack,                          \
  Stack*:                htAddVectorPStackP,                         \
  const volatile Stack*: htAddVectorPStackP,                         \
  RedBlackTree:          htAddVectorPRedBlackTree,                   \
  RedBlackTree*:         htAddVectorPRedBlackTreeP,                  \
  const volatile RedBlackTree*: htAddVectorPRedBlackTreeP,                  \
  HashTable:             htAddVectorPHashTable,                      \
  HashTable*:            htAddVectorPHashTableP,                     \
  const volatile HashTable*: htAddVectorPHashTableP,                     \
  Vector:                htAddVectorPVector,                         \
  Vector*:               htAddVectorPVectorP,                        \
  const volatile Vector*: htAddVectorPVectorP,                        \
  char*:                 htAddVectorPString,                         \
  const volatile char*:  htAddVectorPString,                         \
  char**:                htAddVectorPStringP,                        \
  const volatile char**: htAddVectorPStringP,                        \
  Bytes:                 htAddVectorPBytes,                          \
  Bytes*:                htAddVectorPBytesP,                         \
  const volatile Bytes*: htAddVectorPBytesP,                         \
  void*:                 htAddVectorPPointer,                        \
  void**:                htAddVectorPPointerP,                       \
  const volatile void**: htAddVectorPPointerP,                       \
  i8:                    htAddVectorI8,                              \
  u8:                    htAddVectorU8                               \

#define htAddVectorP(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_VECTORP_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_STRINGP_KEY(dataStructure, key, value) \
  bool:                  htAddStringPBool,                           \
  bool*:                 htAddStringPBoolP,                          \
  const volatile bool*:  htAddStringPBoolP,                          \
  i16:                   htAddStringPI16,                            \
  i16*:                  htAddStringPI16P,                           \
  const volatile i16*:   htAddStringPI16P,                           \
  u16:                   htAddStringPU16,                            \
  u16*:                  htAddStringPU16P,                           \
  const volatile u16*:   htAddStringPU16P,                           \
  i32:                   htAddStringPI32,                            \
  i32*:                  htAddStringPI32P,                           \
  const volatile i32*:   htAddStringPI32P,                           \
  u32:                   htAddStringPU32,                            \
  u32*:                  htAddStringPU32P,                           \
  const volatile u32*:   htAddStringPU32P,                           \
  i64:                   htAddStringPI64,                            \
  i64*:                  htAddStringPI64P,                           \
  const volatile i64*:   htAddStringPI64P,                           \
  u64:                   htAddStringPU64,                            \
  u64*:                  htAddStringPU64P,                           \
  const volatile u64*:   htAddStringPU64P,                           \
  float:                 htAddStringPFloat,                          \
  float*:                htAddStringPFloatP,                         \
  const volatile float*: htAddStringPFloatP,                         \
  double:                htAddStringPDouble,                         \
  double*:               htAddStringPDoubleP,                        \
  const volatile double*: htAddStringPDoubleP,                        \
  long double:           htAddStringPLongDouble,                     \
  long double*:          htAddStringPLongDoubleP,                    \
  const volatile long double*: htAddStringPLongDoubleP,                    \
  List:                  htAddStringPList,                           \
  List*:                 htAddStringPListP,                          \
  const volatile List*:  htAddStringPListP,                          \
  Queue:                 htAddStringPQueue,                          \
  Queue*:                htAddStringPQueueP,                         \
  const volatile Queue*: htAddStringPQueueP,                         \
  Stack:                 htAddStringPStack,                          \
  Stack*:                htAddStringPStackP,                         \
  const volatile Stack*: htAddStringPStackP,                         \
  RedBlackTree:          htAddStringPRedBlackTree,                   \
  RedBlackTree*:         htAddStringPRedBlackTreeP,                  \
  const volatile RedBlackTree*: htAddStringPRedBlackTreeP,                  \
  HashTable:             htAddStringPHashTable,                      \
  HashTable*:            htAddStringPHashTableP,                     \
  const volatile HashTable*: htAddStringPHashTableP,                     \
  Vector:                htAddStringPVector,                         \
  Vector*:               htAddStringPVectorP,                        \
  const volatile Vector*: htAddStringPVectorP,                        \
  char*:                 htAddStringPString,                         \
  const volatile char*:  htAddStringPString,                         \
  char**:                htAddStringPStringP,                        \
  const volatile char**: htAddStringPStringP,                        \
  Bytes:                 htAddStringPBytes,                          \
  Bytes*:                htAddStringPBytesP,                         \
  const volatile Bytes*: htAddStringPBytesP,                         \
  void*:                 htAddStringPPointer,                        \
  void**:                htAddStringPPointerP,                       \
  const volatile void**: htAddStringPPointerP,                       \
  i8:                    htAddStringI8,                              \
  u8:                    htAddStringU8                               \

#define htAddStringP(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_STRINGP_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_BYTESP_KEY(dataStructure, key, value) \
  bool:                  htAddBytesPBool,                            \
  bool*:                 htAddBytesPBoolP,                           \
  const volatile bool*:  htAddBytesPBoolP,                           \
  i16:                   htAddBytesPI16,                             \
  i16*:                  htAddBytesPI16P,                            \
  const volatile i16*:   htAddBytesPI16P,                            \
  u16:                   htAddBytesPU16,                             \
  u16*:                  htAddBytesPU16P,                            \
  const volatile u16*:   htAddBytesPU16P,                            \
  i32:                   htAddBytesPI32,                             \
  i32*:                  htAddBytesPI32P,                            \
  const volatile i32*:   htAddBytesPI32P,                            \
  u32:                   htAddBytesPU32,                             \
  u32*:                  htAddBytesPU32P,                            \
  const volatile u32*:   htAddBytesPU32P,                            \
  i64:                   htAddBytesPI64,                             \
  i64*:                  htAddBytesPI64P,                            \
  const volatile i64*:   htAddBytesPI64P,                            \
  u64:                   htAddBytesPU64,                             \
  u64*:                  htAddBytesPU64P,                            \
  const volatile u64*:   htAddBytesPU64P,                            \
  float:                 htAddBytesPFloat,                           \
  float*:                htAddBytesPFloatP,                          \
  const volatile float*: htAddBytesPFloatP,                          \
  double:                htAddBytesPDouble,                          \
  double*:               htAddBytesPDoubleP,                         \
  const volatile double*: htAddBytesPDoubleP,                         \
  long double:           htAddBytesPLongDouble,                      \
  long double*:          htAddBytesPLongDoubleP,                     \
  const volatile long double*: htAddBytesPLongDoubleP,                     \
  List:                  htAddBytesPList,                            \
  List*:                 htAddBytesPListP,                           \
  const volatile List*:  htAddBytesPListP,                           \
  Queue:                 htAddBytesPQueue,                           \
  Queue*:                htAddBytesPQueueP,                          \
  const volatile Queue*: htAddBytesPQueueP,                          \
  Stack:                 htAddBytesPStack,                           \
  Stack*:                htAddBytesPStackP,                          \
  const volatile Stack*: htAddBytesPStackP,                          \
  RedBlackTree:          htAddBytesPRedBlackTree,                    \
  RedBlackTree*:         htAddBytesPRedBlackTreeP,                   \
  const volatile RedBlackTree*: htAddBytesPRedBlackTreeP,                   \
  HashTable:             htAddBytesPHashTable,                       \
  HashTable*:            htAddBytesPHashTableP,                      \
  const volatile HashTable*: htAddBytesPHashTableP,                      \
  Vector:                htAddBytesPVector,                          \
  Vector*:               htAddBytesPVectorP,                         \
  const volatile Vector*: htAddBytesPVectorP,                         \
  char*:                 htAddBytesPString,                          \
  const volatile char*:  htAddBytesPString,                          \
  char**:                htAddBytesPStringP,                         \
  const volatile char**: htAddBytesPStringP,                         \
  Bytes:                 htAddBytesPBytes,                           \
  Bytes*:                htAddBytesPBytesP,                          \
  const volatile Bytes*: htAddBytesPBytesP,                          \
  void*:                 htAddBytesPPointer,                         \
  void**:                htAddBytesPPointerP,                        \
  const volatile void**: htAddBytesPPointerP,                        \
  i8:                    htAddBytesI8,                               \
  u8:                    htAddBytesU8                                \

#define htAddBytesP(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_BYTESP_KEY(dataStructure, key, value) \
  )

#define HT_ADD_GENERIC_CASES_POINTERP_KEY(dataStructure, key, value) \
  bool:                  htAddPointerPBool,                          \
  bool*:                 htAddPointerPBoolP,                         \
  const volatile bool*:  htAddPointerPBoolP,                         \
  i16:                   htAddPointerPI16,                           \
  i16*:                  htAddPointerPI16P,                          \
  const volatile i16*:   htAddPointerPI16P,                          \
  u16:                   htAddPointerPU16,                           \
  u16*:                  htAddPointerPU16P,                          \
  const volatile u16*:   htAddPointerPU16P,                          \
  i32:                   htAddPointerPI32,                           \
  i32*:                  htAddPointerPI32P,                          \
  const volatile i32*:   htAddPointerPI32P,                          \
  u32:                   htAddPointerPU32,                           \
  u32*:                  htAddPointerPU32P,                          \
  const volatile u32*:   htAddPointerPU32P,                          \
  i64:                   htAddPointerPI64,                           \
  i64*:                  htAddPointerPI64P,                          \
  const volatile i64*:   htAddPointerPI64P,                          \
  u64:                   htAddPointerPU64,                           \
  u64*:                  htAddPointerPU64P,                          \
  const volatile u64*:   htAddPointerPU64P,                          \
  float:                 htAddPointerPFloat,                         \
  float*:                htAddPointerPFloatP,                        \
  const volatile float*: htAddPointerPFloatP,                        \
  double:                htAddPointerPDouble,                        \
  double*:               htAddPointerPDoubleP,                       \
  const volatile double*: htAddPointerPDoubleP,                       \
  long double:           htAddPointerPLongDouble,                    \
  long double*:          htAddPointerPLongDoubleP,                   \
  const volatile long double*: htAddPointerPLongDoubleP,                   \
  List:                  htAddPointerPList,                          \
  List*:                 htAddPointerPListP,                         \
  const volatile List*:  htAddPointerPListP,                         \
  Queue:                 htAddPointerPQueue,                         \
  Queue*:                htAddPointerPQueueP,                        \
  const volatile Queue*: htAddPointerPQueueP,                        \
  Stack:                 htAddPointerPStack,                         \
  Stack*:                htAddPointerPStackP,                        \
  const volatile Stack*: htAddPointerPStackP,                        \
  RedBlackTree:          htAddPointerPRedBlackTree,                  \
  RedBlackTree*:         htAddPointerPRedBlackTreeP,                 \
  const volatile RedBlackTree*: htAddPointerPRedBlackTreeP,                 \
  HashTable:             htAddPointerPHashTable,                     \
  HashTable*:            htAddPointerPHashTableP,                    \
  const volatile HashTable*: htAddPointerPHashTableP,                    \
  Vector:                htAddPointerPVector,                        \
  Vector*:               htAddPointerPVectorP,                       \
  const volatile Vector*: htAddPointerPVectorP,                       \
  char*:                 htAddPointerPString,                        \
  const volatile char*:  htAddPointerPString,                        \
  char**:                htAddPointerPStringP,                       \
  const volatile char**: htAddPointerPStringP,                       \
  Bytes:                 htAddPointerPBytes,                         \
  Bytes*:                htAddPointerPBytesP,                        \
  const volatile Bytes*: htAddPointerPBytesP,                        \
  void*:                 htAddPointerPPointer,                       \
  void**:                htAddPointerPPointerP,                      \
  const volatile void**: htAddPointerPPointerP,                      \
  i8:                    htAddPointerI8,                             \
  u8:                    htAddPointerU8                              \

#define htAddPointerP(dataStructure, key, value) _Generic((value), \
  HT_ADD_GENERIC_CASES_POINTERP_KEY(dataStructure, key, value) \
  )


#define HT_ADD_GENERIC_CASES(dataStructure, key, value) \
  bool:                  htAddBool(dataStructure, key, value),       \
  bool*:                 htAddBoolP(dataStructure, key, value),      \
  const volatile bool*:  htAddBoolP(dataStructure, key, value),      \
  i16:                   htAddI16(dataStructure, key, value),        \
  i16*:                  htAddI16P(dataStructure, key, value),       \
  const volatile i16*:   htAddI16P(dataStructure, key, value),       \
  u16:                   htAddU16(dataStructure, key, value),        \
  u16*:                  htAddU16P(dataStructure, key, value),       \
  const volatile u16*:   htAddU16P(dataStructure, key, value),       \
  i32:                   htAddI32(dataStructure, key, value),        \
  i32*:                  htAddI32P(dataStructure, key, value),       \
  const volatile i32*:   htAddI32P(dataStructure, key, value),       \
  u32:                   htAddU32(dataStructure, key, value),        \
  u32*:                  htAddU32P(dataStructure, key, value),       \
  const volatile u32*:   htAddU32P(dataStructure, key, value),       \
  i64:                   htAddI64(dataStructure, key, value),        \
  i64*:                  htAddI64P(dataStructure, key, value),       \
  const volatile i64*:   htAddI64P(dataStructure, key, value),       \
  u64:                   htAddU64(dataStructure, key, value),        \
  u64*:                  htAddU64P(dataStructure, key, value),       \
  const volatile u64*:   htAddU64P(dataStructure, key, value),       \
  float:                 htAddFloat(dataStructure, key, value),      \
  float*:                htAddFloatP(dataStructure, key, value),     \
  const volatile float*: htAddFloatP(dataStructure, key, value),     \
  double:                htAddDouble(dataStructure, key, value),     \
  double*:               htAddDoubleP(dataStructure, key, value),    \
  const volatile double*: htAddDoubleP(dataStructure, key, value),    \
  long double:           htAddLongDouble(dataStructure, key, value), \
  long double*:          htAddLongDoubleP(dataStructure, key, value), \
  const volatile long double*: htAddLongDoubleP(dataStructure, key, value), \
  List:                  htAddList(dataStructure, key, value),       \
  List*:                 htAddListP(dataStructure, key, value),      \
  const volatile List*:  htAddListP(dataStructure, key, value),      \
  Queue:                 htAddQueue(dataStructure, key, value),      \
  Queue*:                htAddQueueP(dataStructure, key, value),     \
  const volatile Queue*: htAddQueueP(dataStructure, key, value),     \
  Stack:                 htAddStack(dataStructure, key, value),      \
  Stack*:                htAddStackP(dataStructure, key, value),     \
  const volatile Stack*: htAddStackP(dataStructure, key, value),     \
  RedBlackTree:          htAddRedBlackTree(dataStructure, key, value), \
  RedBlackTree*:         htAddRedBlackTreeP(dataStructure, key, value), \
  const volatile RedBlackTree*: htAddRedBlackTreeP(dataStructure, key, value), \
  HashTable:             htAddHashTable(dataStructure, key, value),  \
  HashTable*:            htAddHashTableP(dataStructure, key, value), \
  const volatile HashTable*: htAddHashTableP(dataStructure, key, value), \
  Vector:                htAddVector(dataStructure, key, value),     \
  Vector*:               htAddVectorP(dataStructure, key, value),    \
  const volatile Vector*: htAddVectorP(dataStructure, key, value),    \
  char*:                 htAddString(dataStructure, key, value),     \
  const volatile char*:  htAddString(dataStructure, key, value),     \
  char**:                htAddStringP(dataStructure, key, value),    \
  const volatile char**: htAddStringP(dataStructure, key, value),    \
  Bytes:                 htAddBytes(dataStructure, key, value),      \
  Bytes*:                htAddBytesP(dataStructure, key, value),     \
  const volatile Bytes*: htAddBytesP(dataStructure, key, value),     \
  void*:                 htAddPointer(dataStructure, key, value),    \
  void**:                htAddPointerP(dataStructure, key, value),   \
  const volatile void**: htAddPointerP(dataStructure, key, value),   \
  i8:                    htAddI8(dataStructure, key, value),         \
  u8:                    htAddU8(dataStructure, key, value)          \

#define htAdd(dataStructure, key, value) _Generic((key), \
  HT_ADD_GENERIC_CASES(dataStructure, key, value) \
  )(dataStructure, key, value)

#endif // __STDC_VERSION__

#elif defined __cplusplus // __STDC_VERSION__ is *NOT* defined
#define TYPE_SAFE_HASH_TABLE

// Define the C++ function overloads.

static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, bool value) {
  return htAddBoolBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile bool* value) {
  return htAddBoolBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, bool value) {
  return htAddBoolPBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile bool* value) {
  return htAddBoolPBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, i16 value) {
  return htAddBoolI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile i16* value) {
  return htAddBoolI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, i16 value) {
  return htAddBoolPI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile i16* value) {
  return htAddBoolPI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, u16 value) {
  return htAddBoolU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile u16* value) {
  return htAddBoolU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, u16 value) {
  return htAddBoolPU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile u16* value) {
  return htAddBoolPU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, i32 value) {
  return htAddBoolI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile i32* value) {
  return htAddBoolI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, i32 value) {
  return htAddBoolPI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile i32* value) {
  return htAddBoolPI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, u32 value) {
  return htAddBoolU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile u32* value) {
  return htAddBoolU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, u32 value) {
  return htAddBoolPU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile u32* value) {
  return htAddBoolPU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, i64 value) {
  return htAddBoolI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile i64* value) {
  return htAddBoolI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, i64 value) {
  return htAddBoolPI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile i64* value) {
  return htAddBoolPI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, u64 value) {
  return htAddBoolU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile u64* value) {
  return htAddBoolU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, u64 value) {
  return htAddBoolPU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile u64* value) {
  return htAddBoolPU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, float value) {
  return htAddBoolFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile float* value) {
  return htAddBoolFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, float value) {
  return htAddBoolPFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile float* value) {
  return htAddBoolPFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, double value) {
  return htAddBoolDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile double* value) {
  return htAddBoolDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, double value) {
  return htAddBoolPDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile double* value) {
  return htAddBoolPDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, long double value) {
  return htAddBoolLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile long double* value) {
  return htAddBoolLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, long double value) {
  return htAddBoolPLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile long double* value) {
  return htAddBoolPLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, List value) {
  return htAddBoolList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile List* value) {
  return htAddBoolListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, List value) {
  return htAddBoolPList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile List* value) {
  return htAddBoolPListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, Queue value) {
  return htAddBoolQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile Queue* value) {
  return htAddBoolQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, Queue value) {
  return htAddBoolPQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile Queue* value) {
  return htAddBoolPQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, Stack value) {
  return htAddBoolStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile Stack* value) {
  return htAddBoolStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, Stack value) {
  return htAddBoolPStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile Stack* value) {
  return htAddBoolPStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, RedBlackTree value) {
  return htAddBoolRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile RedBlackTree* value) {
  return htAddBoolRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, RedBlackTree value) {
  return htAddBoolPRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile RedBlackTree* value) {
  return htAddBoolPRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, HashTable value) {
  return htAddBoolHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile HashTable* value) {
  return htAddBoolHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, HashTable value) {
  return htAddBoolPHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile HashTable* value) {
  return htAddBoolPHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, Vector value) {
  return htAddBoolVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile Vector* value) {
  return htAddBoolVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, Vector value) {
  return htAddBoolPVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile Vector* value) {
  return htAddBoolPVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile char* value) {
  return htAddBoolString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile char** value) {
  return htAddBoolStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile char* value) {
  return htAddBoolPString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile char** value) {
  return htAddBoolPStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, Bytes value) {
  return htAddBoolBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile Bytes* value) {
  return htAddBoolBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, Bytes value) {
  return htAddBoolPBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile Bytes* value) {
  return htAddBoolPBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, void* value) {
  return htAddBoolPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, const volatile void** value) {
  return htAddBoolPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, void* value) {
  return htAddBoolPPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, const volatile void** value) {
  return htAddBoolPPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, i8 value) {
  return htAddBoolI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, i8 value) {
  return htAddBoolPI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, bool key, u8 value) {
  return htAddBoolU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile bool* key, u8 value) {
  return htAddBoolPU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, bool value) {
  return htAddI16Bool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile bool* value) {
  return htAddI16BoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, bool value) {
  return htAddI16PBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile bool* value) {
  return htAddI16PBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, i16 value) {
  return htAddI16I16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile i16* value) {
  return htAddI16I16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, i16 value) {
  return htAddI16PI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile i16* value) {
  return htAddI16PI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, u16 value) {
  return htAddI16U16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile u16* value) {
  return htAddI16U16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, u16 value) {
  return htAddI16PU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile u16* value) {
  return htAddI16PU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, i32 value) {
  return htAddI16I32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile i32* value) {
  return htAddI16I32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, i32 value) {
  return htAddI16PI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile i32* value) {
  return htAddI16PI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, u32 value) {
  return htAddI16U32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile u32* value) {
  return htAddI16U32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, u32 value) {
  return htAddI16PU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile u32* value) {
  return htAddI16PU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, i64 value) {
  return htAddI16I64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile i64* value) {
  return htAddI16I64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, i64 value) {
  return htAddI16PI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile i64* value) {
  return htAddI16PI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, u64 value) {
  return htAddI16U64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile u64* value) {
  return htAddI16U64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, u64 value) {
  return htAddI16PU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile u64* value) {
  return htAddI16PU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, float value) {
  return htAddI16Float(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile float* value) {
  return htAddI16FloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, float value) {
  return htAddI16PFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile float* value) {
  return htAddI16PFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, double value) {
  return htAddI16Double(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile double* value) {
  return htAddI16DoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, double value) {
  return htAddI16PDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile double* value) {
  return htAddI16PDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, long double value) {
  return htAddI16LongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile long double* value) {
  return htAddI16LongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, long double value) {
  return htAddI16PLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile long double* value) {
  return htAddI16PLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, List value) {
  return htAddI16List(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile List* value) {
  return htAddI16ListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, List value) {
  return htAddI16PList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile List* value) {
  return htAddI16PListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, Queue value) {
  return htAddI16Queue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile Queue* value) {
  return htAddI16QueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, Queue value) {
  return htAddI16PQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile Queue* value) {
  return htAddI16PQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, Stack value) {
  return htAddI16Stack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile Stack* value) {
  return htAddI16StackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, Stack value) {
  return htAddI16PStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile Stack* value) {
  return htAddI16PStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, RedBlackTree value) {
  return htAddI16RedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile RedBlackTree* value) {
  return htAddI16RedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, RedBlackTree value) {
  return htAddI16PRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile RedBlackTree* value) {
  return htAddI16PRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, HashTable value) {
  return htAddI16HashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile HashTable* value) {
  return htAddI16HashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, HashTable value) {
  return htAddI16PHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile HashTable* value) {
  return htAddI16PHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, Vector value) {
  return htAddI16Vector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile Vector* value) {
  return htAddI16VectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, Vector value) {
  return htAddI16PVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile Vector* value) {
  return htAddI16PVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile char* value) {
  return htAddI16String(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile char** value) {
  return htAddI16StringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile char* value) {
  return htAddI16PString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile char** value) {
  return htAddI16PStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, Bytes value) {
  return htAddI16Bytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile Bytes* value) {
  return htAddI16BytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, Bytes value) {
  return htAddI16PBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile Bytes* value) {
  return htAddI16PBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, void* value) {
  return htAddI16Pointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, const volatile void** value) {
  return htAddI16PointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, void* value) {
  return htAddI16PPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, const volatile void** value) {
  return htAddI16PPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, i8 value) {
  return htAddI16I8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, i8 value) {
  return htAddI16PI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i16 key, u8 value) {
  return htAddI16U8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i16* key, u8 value) {
  return htAddI16PU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, bool value) {
  return htAddU16Bool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile bool* value) {
  return htAddU16BoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, bool value) {
  return htAddU16PBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile bool* value) {
  return htAddU16PBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, i16 value) {
  return htAddU16I16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile i16* value) {
  return htAddU16I16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, i16 value) {
  return htAddU16PI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile i16* value) {
  return htAddU16PI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, u16 value) {
  return htAddU16U16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile u16* value) {
  return htAddU16U16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, u16 value) {
  return htAddU16PU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile u16* value) {
  return htAddU16PU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, i32 value) {
  return htAddU16I32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile i32* value) {
  return htAddU16I32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, i32 value) {
  return htAddU16PI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile i32* value) {
  return htAddU16PI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, u32 value) {
  return htAddU16U32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile u32* value) {
  return htAddU16U32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, u32 value) {
  return htAddU16PU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile u32* value) {
  return htAddU16PU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, i64 value) {
  return htAddU16I64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile i64* value) {
  return htAddU16I64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, i64 value) {
  return htAddU16PI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile i64* value) {
  return htAddU16PI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, u64 value) {
  return htAddU16U64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile u64* value) {
  return htAddU16U64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, u64 value) {
  return htAddU16PU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile u64* value) {
  return htAddU16PU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, float value) {
  return htAddU16Float(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile float* value) {
  return htAddU16FloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, float value) {
  return htAddU16PFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile float* value) {
  return htAddU16PFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, double value) {
  return htAddU16Double(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile double* value) {
  return htAddU16DoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, double value) {
  return htAddU16PDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile double* value) {
  return htAddU16PDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, long double value) {
  return htAddU16LongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile long double* value) {
  return htAddU16LongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, long double value) {
  return htAddU16PLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile long double* value) {
  return htAddU16PLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, List value) {
  return htAddU16List(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile List* value) {
  return htAddU16ListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, List value) {
  return htAddU16PList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile List* value) {
  return htAddU16PListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, Queue value) {
  return htAddU16Queue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile Queue* value) {
  return htAddU16QueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, Queue value) {
  return htAddU16PQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile Queue* value) {
  return htAddU16PQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, Stack value) {
  return htAddU16Stack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile Stack* value) {
  return htAddU16StackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, Stack value) {
  return htAddU16PStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile Stack* value) {
  return htAddU16PStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, RedBlackTree value) {
  return htAddU16RedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile RedBlackTree* value) {
  return htAddU16RedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, RedBlackTree value) {
  return htAddU16PRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile RedBlackTree* value) {
  return htAddU16PRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, HashTable value) {
  return htAddU16HashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile HashTable* value) {
  return htAddU16HashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, HashTable value) {
  return htAddU16PHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile HashTable* value) {
  return htAddU16PHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, Vector value) {
  return htAddU16Vector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile Vector* value) {
  return htAddU16VectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, Vector value) {
  return htAddU16PVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile Vector* value) {
  return htAddU16PVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile char* value) {
  return htAddU16String(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile char** value) {
  return htAddU16StringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile char* value) {
  return htAddU16PString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile char** value) {
  return htAddU16PStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, Bytes value) {
  return htAddU16Bytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile Bytes* value) {
  return htAddU16BytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, Bytes value) {
  return htAddU16PBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile Bytes* value) {
  return htAddU16PBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, void* value) {
  return htAddU16Pointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, const volatile void** value) {
  return htAddU16PointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, void* value) {
  return htAddU16PPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, const volatile void** value) {
  return htAddU16PPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, i8 value) {
  return htAddU16I8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, i8 value) {
  return htAddU16PI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u16 key, u8 value) {
  return htAddU16U8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u16* key, u8 value) {
  return htAddU16PU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, bool value) {
  return htAddI32Bool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile bool* value) {
  return htAddI32BoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, bool value) {
  return htAddI32PBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile bool* value) {
  return htAddI32PBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, i16 value) {
  return htAddI32I16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile i16* value) {
  return htAddI32I16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, i16 value) {
  return htAddI32PI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile i16* value) {
  return htAddI32PI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, u16 value) {
  return htAddI32U16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile u16* value) {
  return htAddI32U16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, u16 value) {
  return htAddI32PU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile u16* value) {
  return htAddI32PU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, i32 value) {
  return htAddI32I32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile i32* value) {
  return htAddI32I32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, i32 value) {
  return htAddI32PI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile i32* value) {
  return htAddI32PI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, u32 value) {
  return htAddI32U32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile u32* value) {
  return htAddI32U32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, u32 value) {
  return htAddI32PU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile u32* value) {
  return htAddI32PU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, i64 value) {
  return htAddI32I64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile i64* value) {
  return htAddI32I64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, i64 value) {
  return htAddI32PI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile i64* value) {
  return htAddI32PI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, u64 value) {
  return htAddI32U64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile u64* value) {
  return htAddI32U64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, u64 value) {
  return htAddI32PU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile u64* value) {
  return htAddI32PU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, float value) {
  return htAddI32Float(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile float* value) {
  return htAddI32FloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, float value) {
  return htAddI32PFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile float* value) {
  return htAddI32PFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, double value) {
  return htAddI32Double(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile double* value) {
  return htAddI32DoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, double value) {
  return htAddI32PDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile double* value) {
  return htAddI32PDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, long double value) {
  return htAddI32LongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile long double* value) {
  return htAddI32LongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, long double value) {
  return htAddI32PLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile long double* value) {
  return htAddI32PLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, List value) {
  return htAddI32List(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile List* value) {
  return htAddI32ListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, List value) {
  return htAddI32PList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile List* value) {
  return htAddI32PListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, Queue value) {
  return htAddI32Queue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile Queue* value) {
  return htAddI32QueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, Queue value) {
  return htAddI32PQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile Queue* value) {
  return htAddI32PQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, Stack value) {
  return htAddI32Stack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile Stack* value) {
  return htAddI32StackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, Stack value) {
  return htAddI32PStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile Stack* value) {
  return htAddI32PStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, RedBlackTree value) {
  return htAddI32RedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile RedBlackTree* value) {
  return htAddI32RedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, RedBlackTree value) {
  return htAddI32PRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile RedBlackTree* value) {
  return htAddI32PRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, HashTable value) {
  return htAddI32HashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile HashTable* value) {
  return htAddI32HashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, HashTable value) {
  return htAddI32PHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile HashTable* value) {
  return htAddI32PHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, Vector value) {
  return htAddI32Vector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile Vector* value) {
  return htAddI32VectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, Vector value) {
  return htAddI32PVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile Vector* value) {
  return htAddI32PVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile char* value) {
  return htAddI32String(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile char** value) {
  return htAddI32StringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile char* value) {
  return htAddI32PString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile char** value) {
  return htAddI32PStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, Bytes value) {
  return htAddI32Bytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile Bytes* value) {
  return htAddI32BytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, Bytes value) {
  return htAddI32PBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile Bytes* value) {
  return htAddI32PBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, void* value) {
  return htAddI32Pointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, const volatile void** value) {
  return htAddI32PointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, void* value) {
  return htAddI32PPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, const volatile void** value) {
  return htAddI32PPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, i8 value) {
  return htAddI32I8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, i8 value) {
  return htAddI32PI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i32 key, u8 value) {
  return htAddI32U8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i32* key, u8 value) {
  return htAddI32PU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, bool value) {
  return htAddU32Bool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile bool* value) {
  return htAddU32BoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, bool value) {
  return htAddU32PBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile bool* value) {
  return htAddU32PBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, i16 value) {
  return htAddU32I16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile i16* value) {
  return htAddU32I16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, i16 value) {
  return htAddU32PI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile i16* value) {
  return htAddU32PI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, u16 value) {
  return htAddU32U16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile u16* value) {
  return htAddU32U16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, u16 value) {
  return htAddU32PU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile u16* value) {
  return htAddU32PU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, i32 value) {
  return htAddU32I32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile i32* value) {
  return htAddU32I32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, i32 value) {
  return htAddU32PI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile i32* value) {
  return htAddU32PI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, u32 value) {
  return htAddU32U32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile u32* value) {
  return htAddU32U32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, u32 value) {
  return htAddU32PU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile u32* value) {
  return htAddU32PU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, i64 value) {
  return htAddU32I64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile i64* value) {
  return htAddU32I64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, i64 value) {
  return htAddU32PI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile i64* value) {
  return htAddU32PI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, u64 value) {
  return htAddU32U64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile u64* value) {
  return htAddU32U64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, u64 value) {
  return htAddU32PU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile u64* value) {
  return htAddU32PU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, float value) {
  return htAddU32Float(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile float* value) {
  return htAddU32FloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, float value) {
  return htAddU32PFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile float* value) {
  return htAddU32PFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, double value) {
  return htAddU32Double(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile double* value) {
  return htAddU32DoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, double value) {
  return htAddU32PDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile double* value) {
  return htAddU32PDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, long double value) {
  return htAddU32LongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile long double* value) {
  return htAddU32LongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, long double value) {
  return htAddU32PLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile long double* value) {
  return htAddU32PLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, List value) {
  return htAddU32List(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile List* value) {
  return htAddU32ListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, List value) {
  return htAddU32PList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile List* value) {
  return htAddU32PListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, Queue value) {
  return htAddU32Queue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile Queue* value) {
  return htAddU32QueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, Queue value) {
  return htAddU32PQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile Queue* value) {
  return htAddU32PQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, Stack value) {
  return htAddU32Stack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile Stack* value) {
  return htAddU32StackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, Stack value) {
  return htAddU32PStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile Stack* value) {
  return htAddU32PStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, RedBlackTree value) {
  return htAddU32RedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile RedBlackTree* value) {
  return htAddU32RedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, RedBlackTree value) {
  return htAddU32PRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile RedBlackTree* value) {
  return htAddU32PRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, HashTable value) {
  return htAddU32HashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile HashTable* value) {
  return htAddU32HashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, HashTable value) {
  return htAddU32PHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile HashTable* value) {
  return htAddU32PHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, Vector value) {
  return htAddU32Vector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile Vector* value) {
  return htAddU32VectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, Vector value) {
  return htAddU32PVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile Vector* value) {
  return htAddU32PVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile char* value) {
  return htAddU32String(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile char** value) {
  return htAddU32StringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile char* value) {
  return htAddU32PString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile char** value) {
  return htAddU32PStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, Bytes value) {
  return htAddU32Bytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile Bytes* value) {
  return htAddU32BytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, Bytes value) {
  return htAddU32PBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile Bytes* value) {
  return htAddU32PBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, void* value) {
  return htAddU32Pointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, const volatile void** value) {
  return htAddU32PointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, void* value) {
  return htAddU32PPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, const volatile void** value) {
  return htAddU32PPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, i8 value) {
  return htAddU32I8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, i8 value) {
  return htAddU32PI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u32 key, u8 value) {
  return htAddU32U8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u32* key, u8 value) {
  return htAddU32PU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, bool value) {
  return htAddI64Bool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile bool* value) {
  return htAddI64BoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, bool value) {
  return htAddI64PBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile bool* value) {
  return htAddI64PBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, i16 value) {
  return htAddI64I16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile i16* value) {
  return htAddI64I16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, i16 value) {
  return htAddI64PI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile i16* value) {
  return htAddI64PI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, u16 value) {
  return htAddI64U16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile u16* value) {
  return htAddI64U16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, u16 value) {
  return htAddI64PU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile u16* value) {
  return htAddI64PU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, i32 value) {
  return htAddI64I32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile i32* value) {
  return htAddI64I32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, i32 value) {
  return htAddI64PI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile i32* value) {
  return htAddI64PI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, u32 value) {
  return htAddI64U32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile u32* value) {
  return htAddI64U32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, u32 value) {
  return htAddI64PU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile u32* value) {
  return htAddI64PU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, i64 value) {
  return htAddI64I64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile i64* value) {
  return htAddI64I64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, i64 value) {
  return htAddI64PI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile i64* value) {
  return htAddI64PI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, u64 value) {
  return htAddI64U64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile u64* value) {
  return htAddI64U64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, u64 value) {
  return htAddI64PU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile u64* value) {
  return htAddI64PU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, float value) {
  return htAddI64Float(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile float* value) {
  return htAddI64FloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, float value) {
  return htAddI64PFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile float* value) {
  return htAddI64PFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, double value) {
  return htAddI64Double(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile double* value) {
  return htAddI64DoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, double value) {
  return htAddI64PDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile double* value) {
  return htAddI64PDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, long double value) {
  return htAddI64LongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile long double* value) {
  return htAddI64LongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, long double value) {
  return htAddI64PLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile long double* value) {
  return htAddI64PLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, List value) {
  return htAddI64List(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile List* value) {
  return htAddI64ListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, List value) {
  return htAddI64PList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile List* value) {
  return htAddI64PListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, Queue value) {
  return htAddI64Queue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile Queue* value) {
  return htAddI64QueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, Queue value) {
  return htAddI64PQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile Queue* value) {
  return htAddI64PQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, Stack value) {
  return htAddI64Stack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile Stack* value) {
  return htAddI64StackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, Stack value) {
  return htAddI64PStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile Stack* value) {
  return htAddI64PStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, RedBlackTree value) {
  return htAddI64RedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile RedBlackTree* value) {
  return htAddI64RedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, RedBlackTree value) {
  return htAddI64PRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile RedBlackTree* value) {
  return htAddI64PRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, HashTable value) {
  return htAddI64HashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile HashTable* value) {
  return htAddI64HashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, HashTable value) {
  return htAddI64PHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile HashTable* value) {
  return htAddI64PHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, Vector value) {
  return htAddI64Vector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile Vector* value) {
  return htAddI64VectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, Vector value) {
  return htAddI64PVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile Vector* value) {
  return htAddI64PVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile char* value) {
  return htAddI64String(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile char** value) {
  return htAddI64StringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile char* value) {
  return htAddI64PString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile char** value) {
  return htAddI64PStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, Bytes value) {
  return htAddI64Bytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile Bytes* value) {
  return htAddI64BytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, Bytes value) {
  return htAddI64PBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile Bytes* value) {
  return htAddI64PBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, void* value) {
  return htAddI64Pointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, const volatile void** value) {
  return htAddI64PointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, void* value) {
  return htAddI64PPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, const volatile void** value) {
  return htAddI64PPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, i8 value) {
  return htAddI64I8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, i8 value) {
  return htAddI64PI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i64 key, u8 value) {
  return htAddI64U8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile i64* key, u8 value) {
  return htAddI64PU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, bool value) {
  return htAddU64Bool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile bool* value) {
  return htAddU64BoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, bool value) {
  return htAddU64PBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile bool* value) {
  return htAddU64PBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, i16 value) {
  return htAddU64I16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile i16* value) {
  return htAddU64I16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, i16 value) {
  return htAddU64PI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile i16* value) {
  return htAddU64PI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, u16 value) {
  return htAddU64U16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile u16* value) {
  return htAddU64U16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, u16 value) {
  return htAddU64PU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile u16* value) {
  return htAddU64PU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, i32 value) {
  return htAddU64I32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile i32* value) {
  return htAddU64I32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, i32 value) {
  return htAddU64PI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile i32* value) {
  return htAddU64PI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, u32 value) {
  return htAddU64U32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile u32* value) {
  return htAddU64U32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, u32 value) {
  return htAddU64PU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile u32* value) {
  return htAddU64PU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, i64 value) {
  return htAddU64I64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile i64* value) {
  return htAddU64I64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, i64 value) {
  return htAddU64PI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile i64* value) {
  return htAddU64PI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, u64 value) {
  return htAddU64U64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile u64* value) {
  return htAddU64U64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, u64 value) {
  return htAddU64PU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile u64* value) {
  return htAddU64PU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, float value) {
  return htAddU64Float(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile float* value) {
  return htAddU64FloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, float value) {
  return htAddU64PFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile float* value) {
  return htAddU64PFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, double value) {
  return htAddU64Double(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile double* value) {
  return htAddU64DoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, double value) {
  return htAddU64PDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile double* value) {
  return htAddU64PDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, long double value) {
  return htAddU64LongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile long double* value) {
  return htAddU64LongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, long double value) {
  return htAddU64PLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile long double* value) {
  return htAddU64PLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, List value) {
  return htAddU64List(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile List* value) {
  return htAddU64ListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, List value) {
  return htAddU64PList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile List* value) {
  return htAddU64PListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, Queue value) {
  return htAddU64Queue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile Queue* value) {
  return htAddU64QueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, Queue value) {
  return htAddU64PQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile Queue* value) {
  return htAddU64PQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, Stack value) {
  return htAddU64Stack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile Stack* value) {
  return htAddU64StackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, Stack value) {
  return htAddU64PStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile Stack* value) {
  return htAddU64PStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, RedBlackTree value) {
  return htAddU64RedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile RedBlackTree* value) {
  return htAddU64RedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, RedBlackTree value) {
  return htAddU64PRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile RedBlackTree* value) {
  return htAddU64PRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, HashTable value) {
  return htAddU64HashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile HashTable* value) {
  return htAddU64HashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, HashTable value) {
  return htAddU64PHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile HashTable* value) {
  return htAddU64PHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, Vector value) {
  return htAddU64Vector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile Vector* value) {
  return htAddU64VectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, Vector value) {
  return htAddU64PVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile Vector* value) {
  return htAddU64PVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile char* value) {
  return htAddU64String(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile char** value) {
  return htAddU64StringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile char* value) {
  return htAddU64PString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile char** value) {
  return htAddU64PStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, Bytes value) {
  return htAddU64Bytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile Bytes* value) {
  return htAddU64BytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, Bytes value) {
  return htAddU64PBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile Bytes* value) {
  return htAddU64PBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, void* value) {
  return htAddU64Pointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, const volatile void** value) {
  return htAddU64PointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, void* value) {
  return htAddU64PPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, const volatile void** value) {
  return htAddU64PPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, i8 value) {
  return htAddU64I8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, i8 value) {
  return htAddU64PI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u64 key, u8 value) {
  return htAddU64U8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile u64* key, u8 value) {
  return htAddU64PU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, bool value) {
  return htAddFloatBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile bool* value) {
  return htAddFloatBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, bool value) {
  return htAddFloatPBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile bool* value) {
  return htAddFloatPBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, i16 value) {
  return htAddFloatI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile i16* value) {
  return htAddFloatI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, i16 value) {
  return htAddFloatPI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile i16* value) {
  return htAddFloatPI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, u16 value) {
  return htAddFloatU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile u16* value) {
  return htAddFloatU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, u16 value) {
  return htAddFloatPU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile u16* value) {
  return htAddFloatPU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, i32 value) {
  return htAddFloatI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile i32* value) {
  return htAddFloatI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, i32 value) {
  return htAddFloatPI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile i32* value) {
  return htAddFloatPI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, u32 value) {
  return htAddFloatU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile u32* value) {
  return htAddFloatU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, u32 value) {
  return htAddFloatPU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile u32* value) {
  return htAddFloatPU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, i64 value) {
  return htAddFloatI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile i64* value) {
  return htAddFloatI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, i64 value) {
  return htAddFloatPI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile i64* value) {
  return htAddFloatPI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, u64 value) {
  return htAddFloatU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile u64* value) {
  return htAddFloatU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, u64 value) {
  return htAddFloatPU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile u64* value) {
  return htAddFloatPU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, float value) {
  return htAddFloatFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile float* value) {
  return htAddFloatFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, float value) {
  return htAddFloatPFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile float* value) {
  return htAddFloatPFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, double value) {
  return htAddFloatDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile double* value) {
  return htAddFloatDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, double value) {
  return htAddFloatPDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile double* value) {
  return htAddFloatPDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, long double value) {
  return htAddFloatLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile long double* value) {
  return htAddFloatLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, long double value) {
  return htAddFloatPLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile long double* value) {
  return htAddFloatPLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, List value) {
  return htAddFloatList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile List* value) {
  return htAddFloatListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, List value) {
  return htAddFloatPList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile List* value) {
  return htAddFloatPListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, Queue value) {
  return htAddFloatQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile Queue* value) {
  return htAddFloatQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, Queue value) {
  return htAddFloatPQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile Queue* value) {
  return htAddFloatPQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, Stack value) {
  return htAddFloatStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile Stack* value) {
  return htAddFloatStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, Stack value) {
  return htAddFloatPStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile Stack* value) {
  return htAddFloatPStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, RedBlackTree value) {
  return htAddFloatRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile RedBlackTree* value) {
  return htAddFloatRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, RedBlackTree value) {
  return htAddFloatPRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile RedBlackTree* value) {
  return htAddFloatPRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, HashTable value) {
  return htAddFloatHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile HashTable* value) {
  return htAddFloatHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, HashTable value) {
  return htAddFloatPHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile HashTable* value) {
  return htAddFloatPHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, Vector value) {
  return htAddFloatVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile Vector* value) {
  return htAddFloatVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, Vector value) {
  return htAddFloatPVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile Vector* value) {
  return htAddFloatPVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile char* value) {
  return htAddFloatString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile char** value) {
  return htAddFloatStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile char* value) {
  return htAddFloatPString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile char** value) {
  return htAddFloatPStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, Bytes value) {
  return htAddFloatBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile Bytes* value) {
  return htAddFloatBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, Bytes value) {
  return htAddFloatPBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile Bytes* value) {
  return htAddFloatPBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, void* value) {
  return htAddFloatPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, const volatile void** value) {
  return htAddFloatPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, void* value) {
  return htAddFloatPPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, const volatile void** value) {
  return htAddFloatPPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, i8 value) {
  return htAddFloatI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, i8 value) {
  return htAddFloatPI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, float key, u8 value) {
  return htAddFloatU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile float* key, u8 value) {
  return htAddFloatPU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, bool value) {
  return htAddDoubleBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile bool* value) {
  return htAddDoubleBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, bool value) {
  return htAddDoublePBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile bool* value) {
  return htAddDoublePBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, i16 value) {
  return htAddDoubleI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile i16* value) {
  return htAddDoubleI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, i16 value) {
  return htAddDoublePI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile i16* value) {
  return htAddDoublePI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, u16 value) {
  return htAddDoubleU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile u16* value) {
  return htAddDoubleU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, u16 value) {
  return htAddDoublePU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile u16* value) {
  return htAddDoublePU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, i32 value) {
  return htAddDoubleI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile i32* value) {
  return htAddDoubleI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, i32 value) {
  return htAddDoublePI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile i32* value) {
  return htAddDoublePI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, u32 value) {
  return htAddDoubleU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile u32* value) {
  return htAddDoubleU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, u32 value) {
  return htAddDoublePU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile u32* value) {
  return htAddDoublePU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, i64 value) {
  return htAddDoubleI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile i64* value) {
  return htAddDoubleI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, i64 value) {
  return htAddDoublePI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile i64* value) {
  return htAddDoublePI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, u64 value) {
  return htAddDoubleU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile u64* value) {
  return htAddDoubleU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, u64 value) {
  return htAddDoublePU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile u64* value) {
  return htAddDoublePU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, float value) {
  return htAddDoubleFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile float* value) {
  return htAddDoubleFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, float value) {
  return htAddDoublePFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile float* value) {
  return htAddDoublePFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, double value) {
  return htAddDoubleDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile double* value) {
  return htAddDoubleDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, double value) {
  return htAddDoublePDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile double* value) {
  return htAddDoublePDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, long double value) {
  return htAddDoubleLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile long double* value) {
  return htAddDoubleLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, long double value) {
  return htAddDoublePLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile long double* value) {
  return htAddDoublePLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, List value) {
  return htAddDoubleList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile List* value) {
  return htAddDoubleListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, List value) {
  return htAddDoublePList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile List* value) {
  return htAddDoublePListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, Queue value) {
  return htAddDoubleQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile Queue* value) {
  return htAddDoubleQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, Queue value) {
  return htAddDoublePQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile Queue* value) {
  return htAddDoublePQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, Stack value) {
  return htAddDoubleStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile Stack* value) {
  return htAddDoubleStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, Stack value) {
  return htAddDoublePStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile Stack* value) {
  return htAddDoublePStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, RedBlackTree value) {
  return htAddDoubleRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile RedBlackTree* value) {
  return htAddDoubleRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, RedBlackTree value) {
  return htAddDoublePRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile RedBlackTree* value) {
  return htAddDoublePRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, HashTable value) {
  return htAddDoubleHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile HashTable* value) {
  return htAddDoubleHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, HashTable value) {
  return htAddDoublePHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile HashTable* value) {
  return htAddDoublePHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, Vector value) {
  return htAddDoubleVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile Vector* value) {
  return htAddDoubleVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, Vector value) {
  return htAddDoublePVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile Vector* value) {
  return htAddDoublePVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile char* value) {
  return htAddDoubleString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile char** value) {
  return htAddDoubleStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile char* value) {
  return htAddDoublePString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile char** value) {
  return htAddDoublePStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, Bytes value) {
  return htAddDoubleBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile Bytes* value) {
  return htAddDoubleBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, Bytes value) {
  return htAddDoublePBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile Bytes* value) {
  return htAddDoublePBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, void* value) {
  return htAddDoublePointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, const volatile void** value) {
  return htAddDoublePointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, void* value) {
  return htAddDoublePPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, const volatile void** value) {
  return htAddDoublePPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, i8 value) {
  return htAddDoubleI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, i8 value) {
  return htAddDoublePI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, double key, u8 value) {
  return htAddDoubleU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile double* key, u8 value) {
  return htAddDoublePU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, bool value) {
  return htAddLongDoubleBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile bool* value) {
  return htAddLongDoubleBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, bool value) {
  return htAddLongDoublePBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile bool* value) {
  return htAddLongDoublePBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, i16 value) {
  return htAddLongDoubleI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile i16* value) {
  return htAddLongDoubleI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, i16 value) {
  return htAddLongDoublePI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile i16* value) {
  return htAddLongDoublePI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, u16 value) {
  return htAddLongDoubleU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile u16* value) {
  return htAddLongDoubleU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, u16 value) {
  return htAddLongDoublePU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile u16* value) {
  return htAddLongDoublePU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, i32 value) {
  return htAddLongDoubleI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile i32* value) {
  return htAddLongDoubleI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, i32 value) {
  return htAddLongDoublePI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile i32* value) {
  return htAddLongDoublePI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, u32 value) {
  return htAddLongDoubleU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile u32* value) {
  return htAddLongDoubleU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, u32 value) {
  return htAddLongDoublePU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile u32* value) {
  return htAddLongDoublePU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, i64 value) {
  return htAddLongDoubleI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile i64* value) {
  return htAddLongDoubleI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, i64 value) {
  return htAddLongDoublePI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile i64* value) {
  return htAddLongDoublePI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, u64 value) {
  return htAddLongDoubleU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile u64* value) {
  return htAddLongDoubleU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, u64 value) {
  return htAddLongDoublePU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile u64* value) {
  return htAddLongDoublePU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, float value) {
  return htAddLongDoubleFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile float* value) {
  return htAddLongDoubleFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, float value) {
  return htAddLongDoublePFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile float* value) {
  return htAddLongDoublePFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, double value) {
  return htAddLongDoubleDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile double* value) {
  return htAddLongDoubleDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, double value) {
  return htAddLongDoublePDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile double* value) {
  return htAddLongDoublePDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, long double value) {
  return htAddLongDoubleLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile long double* value) {
  return htAddLongDoubleLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, long double value) {
  return htAddLongDoublePLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile long double* value) {
  return htAddLongDoublePLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, List value) {
  return htAddLongDoubleList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile List* value) {
  return htAddLongDoubleListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, List value) {
  return htAddLongDoublePList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile List* value) {
  return htAddLongDoublePListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, Queue value) {
  return htAddLongDoubleQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile Queue* value) {
  return htAddLongDoubleQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, Queue value) {
  return htAddLongDoublePQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile Queue* value) {
  return htAddLongDoublePQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, Stack value) {
  return htAddLongDoubleStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile Stack* value) {
  return htAddLongDoubleStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, Stack value) {
  return htAddLongDoublePStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile Stack* value) {
  return htAddLongDoublePStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, RedBlackTree value) {
  return htAddLongDoubleRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile RedBlackTree* value) {
  return htAddLongDoubleRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, RedBlackTree value) {
  return htAddLongDoublePRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile RedBlackTree* value) {
  return htAddLongDoublePRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, HashTable value) {
  return htAddLongDoubleHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile HashTable* value) {
  return htAddLongDoubleHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, HashTable value) {
  return htAddLongDoublePHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile HashTable* value) {
  return htAddLongDoublePHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, Vector value) {
  return htAddLongDoubleVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile Vector* value) {
  return htAddLongDoubleVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, Vector value) {
  return htAddLongDoublePVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile Vector* value) {
  return htAddLongDoublePVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile char* value) {
  return htAddLongDoubleString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile char** value) {
  return htAddLongDoubleStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile char* value) {
  return htAddLongDoublePString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile char** value) {
  return htAddLongDoublePStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, Bytes value) {
  return htAddLongDoubleBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile Bytes* value) {
  return htAddLongDoubleBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, Bytes value) {
  return htAddLongDoublePBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile Bytes* value) {
  return htAddLongDoublePBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, void* value) {
  return htAddLongDoublePointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, const volatile void** value) {
  return htAddLongDoublePointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, void* value) {
  return htAddLongDoublePPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, const volatile void** value) {
  return htAddLongDoublePPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, i8 value) {
  return htAddLongDoubleI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, i8 value) {
  return htAddLongDoublePI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, long double key, u8 value) {
  return htAddLongDoubleU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile long double* key, u8 value) {
  return htAddLongDoublePU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, bool value) {
  return htAddListBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile bool* value) {
  return htAddListBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, bool value) {
  return htAddListPBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile bool* value) {
  return htAddListPBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, i16 value) {
  return htAddListI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile i16* value) {
  return htAddListI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, i16 value) {
  return htAddListPI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile i16* value) {
  return htAddListPI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, u16 value) {
  return htAddListU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile u16* value) {
  return htAddListU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, u16 value) {
  return htAddListPU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile u16* value) {
  return htAddListPU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, i32 value) {
  return htAddListI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile i32* value) {
  return htAddListI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, i32 value) {
  return htAddListPI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile i32* value) {
  return htAddListPI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, u32 value) {
  return htAddListU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile u32* value) {
  return htAddListU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, u32 value) {
  return htAddListPU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile u32* value) {
  return htAddListPU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, i64 value) {
  return htAddListI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile i64* value) {
  return htAddListI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, i64 value) {
  return htAddListPI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile i64* value) {
  return htAddListPI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, u64 value) {
  return htAddListU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile u64* value) {
  return htAddListU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, u64 value) {
  return htAddListPU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile u64* value) {
  return htAddListPU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, float value) {
  return htAddListFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile float* value) {
  return htAddListFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, float value) {
  return htAddListPFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile float* value) {
  return htAddListPFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, double value) {
  return htAddListDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile double* value) {
  return htAddListDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, double value) {
  return htAddListPDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile double* value) {
  return htAddListPDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, long double value) {
  return htAddListLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile long double* value) {
  return htAddListLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, long double value) {
  return htAddListPLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile long double* value) {
  return htAddListPLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, List value) {
  return htAddListList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile List* value) {
  return htAddListListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, List value) {
  return htAddListPList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile List* value) {
  return htAddListPListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, Queue value) {
  return htAddListQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile Queue* value) {
  return htAddListQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, Queue value) {
  return htAddListPQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile Queue* value) {
  return htAddListPQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, Stack value) {
  return htAddListStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile Stack* value) {
  return htAddListStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, Stack value) {
  return htAddListPStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile Stack* value) {
  return htAddListPStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, RedBlackTree value) {
  return htAddListRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile RedBlackTree* value) {
  return htAddListRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, RedBlackTree value) {
  return htAddListPRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile RedBlackTree* value) {
  return htAddListPRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, HashTable value) {
  return htAddListHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile HashTable* value) {
  return htAddListHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, HashTable value) {
  return htAddListPHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile HashTable* value) {
  return htAddListPHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, Vector value) {
  return htAddListVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile Vector* value) {
  return htAddListVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, Vector value) {
  return htAddListPVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile Vector* value) {
  return htAddListPVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile char* value) {
  return htAddListString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile char** value) {
  return htAddListStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile char* value) {
  return htAddListPString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile char** value) {
  return htAddListPStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, Bytes value) {
  return htAddListBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile Bytes* value) {
  return htAddListBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, Bytes value) {
  return htAddListPBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile Bytes* value) {
  return htAddListPBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, void* value) {
  return htAddListPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, const volatile void** value) {
  return htAddListPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, void* value) {
  return htAddListPPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, const volatile void** value) {
  return htAddListPPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, i8 value) {
  return htAddListI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, i8 value) {
  return htAddListPI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, List key, u8 value) {
  return htAddListU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile List* key, u8 value) {
  return htAddListPU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, bool value) {
  return htAddQueueBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile bool* value) {
  return htAddQueueBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, bool value) {
  return htAddQueuePBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile bool* value) {
  return htAddQueuePBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, i16 value) {
  return htAddQueueI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile i16* value) {
  return htAddQueueI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, i16 value) {
  return htAddQueuePI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile i16* value) {
  return htAddQueuePI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, u16 value) {
  return htAddQueueU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile u16* value) {
  return htAddQueueU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, u16 value) {
  return htAddQueuePU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile u16* value) {
  return htAddQueuePU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, i32 value) {
  return htAddQueueI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile i32* value) {
  return htAddQueueI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, i32 value) {
  return htAddQueuePI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile i32* value) {
  return htAddQueuePI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, u32 value) {
  return htAddQueueU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile u32* value) {
  return htAddQueueU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, u32 value) {
  return htAddQueuePU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile u32* value) {
  return htAddQueuePU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, i64 value) {
  return htAddQueueI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile i64* value) {
  return htAddQueueI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, i64 value) {
  return htAddQueuePI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile i64* value) {
  return htAddQueuePI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, u64 value) {
  return htAddQueueU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile u64* value) {
  return htAddQueueU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, u64 value) {
  return htAddQueuePU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile u64* value) {
  return htAddQueuePU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, float value) {
  return htAddQueueFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile float* value) {
  return htAddQueueFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, float value) {
  return htAddQueuePFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile float* value) {
  return htAddQueuePFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, double value) {
  return htAddQueueDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile double* value) {
  return htAddQueueDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, double value) {
  return htAddQueuePDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile double* value) {
  return htAddQueuePDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, long double value) {
  return htAddQueueLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile long double* value) {
  return htAddQueueLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, long double value) {
  return htAddQueuePLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile long double* value) {
  return htAddQueuePLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, List value) {
  return htAddQueueList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile List* value) {
  return htAddQueueListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, List value) {
  return htAddQueuePList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile List* value) {
  return htAddQueuePListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, Queue value) {
  return htAddQueueQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile Queue* value) {
  return htAddQueueQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, Queue value) {
  return htAddQueuePQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile Queue* value) {
  return htAddQueuePQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, Stack value) {
  return htAddQueueStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile Stack* value) {
  return htAddQueueStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, Stack value) {
  return htAddQueuePStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile Stack* value) {
  return htAddQueuePStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, RedBlackTree value) {
  return htAddQueueRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile RedBlackTree* value) {
  return htAddQueueRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, RedBlackTree value) {
  return htAddQueuePRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile RedBlackTree* value) {
  return htAddQueuePRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, HashTable value) {
  return htAddQueueHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile HashTable* value) {
  return htAddQueueHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, HashTable value) {
  return htAddQueuePHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile HashTable* value) {
  return htAddQueuePHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, Vector value) {
  return htAddQueueVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile Vector* value) {
  return htAddQueueVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, Vector value) {
  return htAddQueuePVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile Vector* value) {
  return htAddQueuePVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile char* value) {
  return htAddQueueString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile char** value) {
  return htAddQueueStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile char* value) {
  return htAddQueuePString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile char** value) {
  return htAddQueuePStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, Bytes value) {
  return htAddQueueBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile Bytes* value) {
  return htAddQueueBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, Bytes value) {
  return htAddQueuePBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile Bytes* value) {
  return htAddQueuePBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, void* value) {
  return htAddQueuePointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, const volatile void** value) {
  return htAddQueuePointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, void* value) {
  return htAddQueuePPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, const volatile void** value) {
  return htAddQueuePPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, i8 value) {
  return htAddQueueI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, i8 value) {
  return htAddQueuePI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Queue key, u8 value) {
  return htAddQueueU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Queue* key, u8 value) {
  return htAddQueuePU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, bool value) {
  return htAddStackBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile bool* value) {
  return htAddStackBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, bool value) {
  return htAddStackPBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile bool* value) {
  return htAddStackPBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, i16 value) {
  return htAddStackI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile i16* value) {
  return htAddStackI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, i16 value) {
  return htAddStackPI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile i16* value) {
  return htAddStackPI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, u16 value) {
  return htAddStackU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile u16* value) {
  return htAddStackU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, u16 value) {
  return htAddStackPU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile u16* value) {
  return htAddStackPU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, i32 value) {
  return htAddStackI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile i32* value) {
  return htAddStackI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, i32 value) {
  return htAddStackPI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile i32* value) {
  return htAddStackPI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, u32 value) {
  return htAddStackU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile u32* value) {
  return htAddStackU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, u32 value) {
  return htAddStackPU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile u32* value) {
  return htAddStackPU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, i64 value) {
  return htAddStackI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile i64* value) {
  return htAddStackI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, i64 value) {
  return htAddStackPI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile i64* value) {
  return htAddStackPI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, u64 value) {
  return htAddStackU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile u64* value) {
  return htAddStackU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, u64 value) {
  return htAddStackPU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile u64* value) {
  return htAddStackPU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, float value) {
  return htAddStackFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile float* value) {
  return htAddStackFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, float value) {
  return htAddStackPFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile float* value) {
  return htAddStackPFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, double value) {
  return htAddStackDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile double* value) {
  return htAddStackDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, double value) {
  return htAddStackPDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile double* value) {
  return htAddStackPDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, long double value) {
  return htAddStackLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile long double* value) {
  return htAddStackLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, long double value) {
  return htAddStackPLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile long double* value) {
  return htAddStackPLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, List value) {
  return htAddStackList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile List* value) {
  return htAddStackListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, List value) {
  return htAddStackPList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile List* value) {
  return htAddStackPListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, Queue value) {
  return htAddStackQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile Queue* value) {
  return htAddStackQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, Queue value) {
  return htAddStackPQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile Queue* value) {
  return htAddStackPQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, Stack value) {
  return htAddStackStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile Stack* value) {
  return htAddStackStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, Stack value) {
  return htAddStackPStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile Stack* value) {
  return htAddStackPStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, RedBlackTree value) {
  return htAddStackRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile RedBlackTree* value) {
  return htAddStackRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, RedBlackTree value) {
  return htAddStackPRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile RedBlackTree* value) {
  return htAddStackPRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, HashTable value) {
  return htAddStackHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile HashTable* value) {
  return htAddStackHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, HashTable value) {
  return htAddStackPHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile HashTable* value) {
  return htAddStackPHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, Vector value) {
  return htAddStackVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile Vector* value) {
  return htAddStackVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, Vector value) {
  return htAddStackPVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile Vector* value) {
  return htAddStackPVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile char* value) {
  return htAddStackString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile char** value) {
  return htAddStackStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile char* value) {
  return htAddStackPString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile char** value) {
  return htAddStackPStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, Bytes value) {
  return htAddStackBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile Bytes* value) {
  return htAddStackBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, Bytes value) {
  return htAddStackPBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile Bytes* value) {
  return htAddStackPBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, void* value) {
  return htAddStackPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, const volatile void** value) {
  return htAddStackPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, void* value) {
  return htAddStackPPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, const volatile void** value) {
  return htAddStackPPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, i8 value) {
  return htAddStackI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, i8 value) {
  return htAddStackPI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Stack key, u8 value) {
  return htAddStackU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Stack* key, u8 value) {
  return htAddStackPU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, bool value) {
  return htAddRedBlackTreeBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile bool* value) {
  return htAddRedBlackTreeBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, bool value) {
  return htAddRedBlackTreePBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile bool* value) {
  return htAddRedBlackTreePBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, i16 value) {
  return htAddRedBlackTreeI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile i16* value) {
  return htAddRedBlackTreeI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, i16 value) {
  return htAddRedBlackTreePI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile i16* value) {
  return htAddRedBlackTreePI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, u16 value) {
  return htAddRedBlackTreeU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile u16* value) {
  return htAddRedBlackTreeU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, u16 value) {
  return htAddRedBlackTreePU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile u16* value) {
  return htAddRedBlackTreePU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, i32 value) {
  return htAddRedBlackTreeI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile i32* value) {
  return htAddRedBlackTreeI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, i32 value) {
  return htAddRedBlackTreePI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile i32* value) {
  return htAddRedBlackTreePI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, u32 value) {
  return htAddRedBlackTreeU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile u32* value) {
  return htAddRedBlackTreeU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, u32 value) {
  return htAddRedBlackTreePU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile u32* value) {
  return htAddRedBlackTreePU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, i64 value) {
  return htAddRedBlackTreeI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile i64* value) {
  return htAddRedBlackTreeI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, i64 value) {
  return htAddRedBlackTreePI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile i64* value) {
  return htAddRedBlackTreePI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, u64 value) {
  return htAddRedBlackTreeU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile u64* value) {
  return htAddRedBlackTreeU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, u64 value) {
  return htAddRedBlackTreePU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile u64* value) {
  return htAddRedBlackTreePU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, float value) {
  return htAddRedBlackTreeFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile float* value) {
  return htAddRedBlackTreeFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, float value) {
  return htAddRedBlackTreePFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile float* value) {
  return htAddRedBlackTreePFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, double value) {
  return htAddRedBlackTreeDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile double* value) {
  return htAddRedBlackTreeDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, double value) {
  return htAddRedBlackTreePDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile double* value) {
  return htAddRedBlackTreePDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, long double value) {
  return htAddRedBlackTreeLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile long double* value) {
  return htAddRedBlackTreeLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, long double value) {
  return htAddRedBlackTreePLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile long double* value) {
  return htAddRedBlackTreePLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, List value) {
  return htAddRedBlackTreeList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile List* value) {
  return htAddRedBlackTreeListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, List value) {
  return htAddRedBlackTreePList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile List* value) {
  return htAddRedBlackTreePListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, Queue value) {
  return htAddRedBlackTreeQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile Queue* value) {
  return htAddRedBlackTreeQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, Queue value) {
  return htAddRedBlackTreePQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile Queue* value) {
  return htAddRedBlackTreePQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, Stack value) {
  return htAddRedBlackTreeStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile Stack* value) {
  return htAddRedBlackTreeStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, Stack value) {
  return htAddRedBlackTreePStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile Stack* value) {
  return htAddRedBlackTreePStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, RedBlackTree value) {
  return htAddRedBlackTreeRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile RedBlackTree* value) {
  return htAddRedBlackTreeRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, RedBlackTree value) {
  return htAddRedBlackTreePRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile RedBlackTree* value) {
  return htAddRedBlackTreePRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, HashTable value) {
  return htAddRedBlackTreeHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile HashTable* value) {
  return htAddRedBlackTreeHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, HashTable value) {
  return htAddRedBlackTreePHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile HashTable* value) {
  return htAddRedBlackTreePHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, Vector value) {
  return htAddRedBlackTreeVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile Vector* value) {
  return htAddRedBlackTreeVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, Vector value) {
  return htAddRedBlackTreePVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile Vector* value) {
  return htAddRedBlackTreePVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile char* value) {
  return htAddRedBlackTreeString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile char** value) {
  return htAddRedBlackTreeStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile char* value) {
  return htAddRedBlackTreePString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile char** value) {
  return htAddRedBlackTreePStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, Bytes value) {
  return htAddRedBlackTreeBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile Bytes* value) {
  return htAddRedBlackTreeBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, Bytes value) {
  return htAddRedBlackTreePBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile Bytes* value) {
  return htAddRedBlackTreePBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, void* value) {
  return htAddRedBlackTreePointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, const volatile void** value) {
  return htAddRedBlackTreePointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, void* value) {
  return htAddRedBlackTreePPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, const volatile void** value) {
  return htAddRedBlackTreePPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, i8 value) {
  return htAddRedBlackTreeI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, i8 value) {
  return htAddRedBlackTreePI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, RedBlackTree key, u8 value) {
  return htAddRedBlackTreeU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile RedBlackTree* key, u8 value) {
  return htAddRedBlackTreePU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, bool value) {
  return htAddHashTableBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile bool* value) {
  return htAddHashTableBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, bool value) {
  return htAddHashTablePBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile bool* value) {
  return htAddHashTablePBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, i16 value) {
  return htAddHashTableI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile i16* value) {
  return htAddHashTableI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, i16 value) {
  return htAddHashTablePI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile i16* value) {
  return htAddHashTablePI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, u16 value) {
  return htAddHashTableU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile u16* value) {
  return htAddHashTableU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, u16 value) {
  return htAddHashTablePU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile u16* value) {
  return htAddHashTablePU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, i32 value) {
  return htAddHashTableI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile i32* value) {
  return htAddHashTableI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, i32 value) {
  return htAddHashTablePI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile i32* value) {
  return htAddHashTablePI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, u32 value) {
  return htAddHashTableU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile u32* value) {
  return htAddHashTableU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, u32 value) {
  return htAddHashTablePU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile u32* value) {
  return htAddHashTablePU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, i64 value) {
  return htAddHashTableI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile i64* value) {
  return htAddHashTableI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, i64 value) {
  return htAddHashTablePI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile i64* value) {
  return htAddHashTablePI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, u64 value) {
  return htAddHashTableU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile u64* value) {
  return htAddHashTableU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, u64 value) {
  return htAddHashTablePU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile u64* value) {
  return htAddHashTablePU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, float value) {
  return htAddHashTableFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile float* value) {
  return htAddHashTableFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, float value) {
  return htAddHashTablePFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile float* value) {
  return htAddHashTablePFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, double value) {
  return htAddHashTableDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile double* value) {
  return htAddHashTableDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, double value) {
  return htAddHashTablePDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile double* value) {
  return htAddHashTablePDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, long double value) {
  return htAddHashTableLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile long double* value) {
  return htAddHashTableLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, long double value) {
  return htAddHashTablePLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile long double* value) {
  return htAddHashTablePLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, List value) {
  return htAddHashTableList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile List* value) {
  return htAddHashTableListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, List value) {
  return htAddHashTablePList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile List* value) {
  return htAddHashTablePListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, Queue value) {
  return htAddHashTableQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile Queue* value) {
  return htAddHashTableQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, Queue value) {
  return htAddHashTablePQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile Queue* value) {
  return htAddHashTablePQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, Stack value) {
  return htAddHashTableStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile Stack* value) {
  return htAddHashTableStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, Stack value) {
  return htAddHashTablePStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile Stack* value) {
  return htAddHashTablePStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, RedBlackTree value) {
  return htAddHashTableRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile RedBlackTree* value) {
  return htAddHashTableRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, RedBlackTree value) {
  return htAddHashTablePRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile RedBlackTree* value) {
  return htAddHashTablePRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, HashTable value) {
  return htAddHashTableHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile HashTable* value) {
  return htAddHashTableHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, HashTable value) {
  return htAddHashTablePHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile HashTable* value) {
  return htAddHashTablePHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, Vector value) {
  return htAddHashTableVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile Vector* value) {
  return htAddHashTableVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, Vector value) {
  return htAddHashTablePVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile Vector* value) {
  return htAddHashTablePVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile char* value) {
  return htAddHashTableString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile char** value) {
  return htAddHashTableStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile char* value) {
  return htAddHashTablePString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile char** value) {
  return htAddHashTablePStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, Bytes value) {
  return htAddHashTableBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile Bytes* value) {
  return htAddHashTableBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, Bytes value) {
  return htAddHashTablePBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile Bytes* value) {
  return htAddHashTablePBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, void* value) {
  return htAddHashTablePointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, const volatile void** value) {
  return htAddHashTablePointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, void* value) {
  return htAddHashTablePPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, const volatile void** value) {
  return htAddHashTablePPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, i8 value) {
  return htAddHashTableI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, i8 value) {
  return htAddHashTablePI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, HashTable key, u8 value) {
  return htAddHashTableU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile HashTable* key, u8 value) {
  return htAddHashTablePU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, bool value) {
  return htAddVectorBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile bool* value) {
  return htAddVectorBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, bool value) {
  return htAddVectorPBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile bool* value) {
  return htAddVectorPBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, i16 value) {
  return htAddVectorI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile i16* value) {
  return htAddVectorI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, i16 value) {
  return htAddVectorPI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile i16* value) {
  return htAddVectorPI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, u16 value) {
  return htAddVectorU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile u16* value) {
  return htAddVectorU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, u16 value) {
  return htAddVectorPU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile u16* value) {
  return htAddVectorPU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, i32 value) {
  return htAddVectorI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile i32* value) {
  return htAddVectorI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, i32 value) {
  return htAddVectorPI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile i32* value) {
  return htAddVectorPI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, u32 value) {
  return htAddVectorU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile u32* value) {
  return htAddVectorU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, u32 value) {
  return htAddVectorPU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile u32* value) {
  return htAddVectorPU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, i64 value) {
  return htAddVectorI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile i64* value) {
  return htAddVectorI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, i64 value) {
  return htAddVectorPI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile i64* value) {
  return htAddVectorPI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, u64 value) {
  return htAddVectorU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile u64* value) {
  return htAddVectorU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, u64 value) {
  return htAddVectorPU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile u64* value) {
  return htAddVectorPU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, float value) {
  return htAddVectorFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile float* value) {
  return htAddVectorFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, float value) {
  return htAddVectorPFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile float* value) {
  return htAddVectorPFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, double value) {
  return htAddVectorDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile double* value) {
  return htAddVectorDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, double value) {
  return htAddVectorPDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile double* value) {
  return htAddVectorPDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, long double value) {
  return htAddVectorLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile long double* value) {
  return htAddVectorLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, long double value) {
  return htAddVectorPLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile long double* value) {
  return htAddVectorPLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, List value) {
  return htAddVectorList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile List* value) {
  return htAddVectorListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, List value) {
  return htAddVectorPList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile List* value) {
  return htAddVectorPListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, Queue value) {
  return htAddVectorQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile Queue* value) {
  return htAddVectorQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, Queue value) {
  return htAddVectorPQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile Queue* value) {
  return htAddVectorPQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, Stack value) {
  return htAddVectorStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile Stack* value) {
  return htAddVectorStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, Stack value) {
  return htAddVectorPStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile Stack* value) {
  return htAddVectorPStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, RedBlackTree value) {
  return htAddVectorRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile RedBlackTree* value) {
  return htAddVectorRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, RedBlackTree value) {
  return htAddVectorPRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile RedBlackTree* value) {
  return htAddVectorPRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, HashTable value) {
  return htAddVectorHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile HashTable* value) {
  return htAddVectorHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, HashTable value) {
  return htAddVectorPHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile HashTable* value) {
  return htAddVectorPHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, Vector value) {
  return htAddVectorVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile Vector* value) {
  return htAddVectorVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, Vector value) {
  return htAddVectorPVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile Vector* value) {
  return htAddVectorPVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile char* value) {
  return htAddVectorString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile char** value) {
  return htAddVectorStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile char* value) {
  return htAddVectorPString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile char** value) {
  return htAddVectorPStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, Bytes value) {
  return htAddVectorBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile Bytes* value) {
  return htAddVectorBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, Bytes value) {
  return htAddVectorPBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile Bytes* value) {
  return htAddVectorPBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, void* value) {
  return htAddVectorPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, const volatile void** value) {
  return htAddVectorPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, void* value) {
  return htAddVectorPPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, const volatile void** value) {
  return htAddVectorPPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, i8 value) {
  return htAddVectorI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, i8 value) {
  return htAddVectorPI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Vector key, u8 value) {
  return htAddVectorU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Vector* key, u8 value) {
  return htAddVectorPU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, bool value) {
  return htAddStringBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile bool* value) {
  return htAddStringBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, bool value) {
  return htAddStringPBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile bool* value) {
  return htAddStringPBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, i16 value) {
  return htAddStringI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile i16* value) {
  return htAddStringI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, i16 value) {
  return htAddStringPI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile i16* value) {
  return htAddStringPI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, u16 value) {
  return htAddStringU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile u16* value) {
  return htAddStringU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, u16 value) {
  return htAddStringPU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile u16* value) {
  return htAddStringPU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, i32 value) {
  return htAddStringI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile i32* value) {
  return htAddStringI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, i32 value) {
  return htAddStringPI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile i32* value) {
  return htAddStringPI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, u32 value) {
  return htAddStringU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile u32* value) {
  return htAddStringU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, u32 value) {
  return htAddStringPU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile u32* value) {
  return htAddStringPU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, i64 value) {
  return htAddStringI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile i64* value) {
  return htAddStringI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, i64 value) {
  return htAddStringPI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile i64* value) {
  return htAddStringPI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, u64 value) {
  return htAddStringU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile u64* value) {
  return htAddStringU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, u64 value) {
  return htAddStringPU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile u64* value) {
  return htAddStringPU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, float value) {
  return htAddStringFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile float* value) {
  return htAddStringFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, float value) {
  return htAddStringPFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile float* value) {
  return htAddStringPFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, double value) {
  return htAddStringDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile double* value) {
  return htAddStringDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, double value) {
  return htAddStringPDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile double* value) {
  return htAddStringPDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, long double value) {
  return htAddStringLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile long double* value) {
  return htAddStringLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, long double value) {
  return htAddStringPLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile long double* value) {
  return htAddStringPLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, List value) {
  return htAddStringList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile List* value) {
  return htAddStringListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, List value) {
  return htAddStringPList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile List* value) {
  return htAddStringPListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, Queue value) {
  return htAddStringQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile Queue* value) {
  return htAddStringQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, Queue value) {
  return htAddStringPQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile Queue* value) {
  return htAddStringPQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, Stack value) {
  return htAddStringStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile Stack* value) {
  return htAddStringStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, Stack value) {
  return htAddStringPStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile Stack* value) {
  return htAddStringPStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, RedBlackTree value) {
  return htAddStringRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile RedBlackTree* value) {
  return htAddStringRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, RedBlackTree value) {
  return htAddStringPRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile RedBlackTree* value) {
  return htAddStringPRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, HashTable value) {
  return htAddStringHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile HashTable* value) {
  return htAddStringHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, HashTable value) {
  return htAddStringPHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile HashTable* value) {
  return htAddStringPHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, Vector value) {
  return htAddStringVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile Vector* value) {
  return htAddStringVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, Vector value) {
  return htAddStringPVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile Vector* value) {
  return htAddStringPVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile char* value) {
  return htAddStringString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile char** value) {
  return htAddStringStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile char* value) {
  return htAddStringPString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile char** value) {
  return htAddStringPStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, Bytes value) {
  return htAddStringBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile Bytes* value) {
  return htAddStringBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, Bytes value) {
  return htAddStringPBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile Bytes* value) {
  return htAddStringPBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, void* value) {
  return htAddStringPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, const volatile void** value) {
  return htAddStringPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, void* value) {
  return htAddStringPPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, const volatile void** value) {
  return htAddStringPPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, i8 value) {
  return htAddStringI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, i8 value) {
  return htAddStringPI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char* key, u8 value) {
  return htAddStringU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile char** key, u8 value) {
  return htAddStringPU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, bool value) {
  return htAddBytesBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile bool* value) {
  return htAddBytesBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, bool value) {
  return htAddBytesPBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile bool* value) {
  return htAddBytesPBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, i16 value) {
  return htAddBytesI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile i16* value) {
  return htAddBytesI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, i16 value) {
  return htAddBytesPI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile i16* value) {
  return htAddBytesPI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, u16 value) {
  return htAddBytesU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile u16* value) {
  return htAddBytesU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, u16 value) {
  return htAddBytesPU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile u16* value) {
  return htAddBytesPU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, i32 value) {
  return htAddBytesI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile i32* value) {
  return htAddBytesI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, i32 value) {
  return htAddBytesPI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile i32* value) {
  return htAddBytesPI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, u32 value) {
  return htAddBytesU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile u32* value) {
  return htAddBytesU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, u32 value) {
  return htAddBytesPU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile u32* value) {
  return htAddBytesPU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, i64 value) {
  return htAddBytesI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile i64* value) {
  return htAddBytesI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, i64 value) {
  return htAddBytesPI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile i64* value) {
  return htAddBytesPI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, u64 value) {
  return htAddBytesU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile u64* value) {
  return htAddBytesU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, u64 value) {
  return htAddBytesPU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile u64* value) {
  return htAddBytesPU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, float value) {
  return htAddBytesFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile float* value) {
  return htAddBytesFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, float value) {
  return htAddBytesPFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile float* value) {
  return htAddBytesPFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, double value) {
  return htAddBytesDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile double* value) {
  return htAddBytesDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, double value) {
  return htAddBytesPDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile double* value) {
  return htAddBytesPDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, long double value) {
  return htAddBytesLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile long double* value) {
  return htAddBytesLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, long double value) {
  return htAddBytesPLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile long double* value) {
  return htAddBytesPLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, List value) {
  return htAddBytesList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile List* value) {
  return htAddBytesListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, List value) {
  return htAddBytesPList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile List* value) {
  return htAddBytesPListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, Queue value) {
  return htAddBytesQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile Queue* value) {
  return htAddBytesQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, Queue value) {
  return htAddBytesPQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile Queue* value) {
  return htAddBytesPQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, Stack value) {
  return htAddBytesStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile Stack* value) {
  return htAddBytesStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, Stack value) {
  return htAddBytesPStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile Stack* value) {
  return htAddBytesPStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, RedBlackTree value) {
  return htAddBytesRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile RedBlackTree* value) {
  return htAddBytesRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, RedBlackTree value) {
  return htAddBytesPRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile RedBlackTree* value) {
  return htAddBytesPRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, HashTable value) {
  return htAddBytesHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile HashTable* value) {
  return htAddBytesHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, HashTable value) {
  return htAddBytesPHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile HashTable* value) {
  return htAddBytesPHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, Vector value) {
  return htAddBytesVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile Vector* value) {
  return htAddBytesVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, Vector value) {
  return htAddBytesPVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile Vector* value) {
  return htAddBytesPVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile char* value) {
  return htAddBytesString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile char** value) {
  return htAddBytesStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile char* value) {
  return htAddBytesPString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile char** value) {
  return htAddBytesPStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, Bytes value) {
  return htAddBytesBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile Bytes* value) {
  return htAddBytesBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, Bytes value) {
  return htAddBytesPBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile Bytes* value) {
  return htAddBytesPBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, void* value) {
  return htAddBytesPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, const volatile void** value) {
  return htAddBytesPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, void* value) {
  return htAddBytesPPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, const volatile void** value) {
  return htAddBytesPPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, i8 value) {
  return htAddBytesI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, i8 value) {
  return htAddBytesPI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, Bytes key, u8 value) {
  return htAddBytesU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile Bytes* key, u8 value) {
  return htAddBytesPU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, bool value) {
  return htAddPointerBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile bool* value) {
  return htAddPointerBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, bool value) {
  return htAddPointerPBool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile bool* value) {
  return htAddPointerPBoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, i16 value) {
  return htAddPointerI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile i16* value) {
  return htAddPointerI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, i16 value) {
  return htAddPointerPI16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile i16* value) {
  return htAddPointerPI16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, u16 value) {
  return htAddPointerU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile u16* value) {
  return htAddPointerU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, u16 value) {
  return htAddPointerPU16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile u16* value) {
  return htAddPointerPU16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, i32 value) {
  return htAddPointerI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile i32* value) {
  return htAddPointerI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, i32 value) {
  return htAddPointerPI32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile i32* value) {
  return htAddPointerPI32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, u32 value) {
  return htAddPointerU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile u32* value) {
  return htAddPointerU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, u32 value) {
  return htAddPointerPU32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile u32* value) {
  return htAddPointerPU32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, i64 value) {
  return htAddPointerI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile i64* value) {
  return htAddPointerI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, i64 value) {
  return htAddPointerPI64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile i64* value) {
  return htAddPointerPI64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, u64 value) {
  return htAddPointerU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile u64* value) {
  return htAddPointerU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, u64 value) {
  return htAddPointerPU64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile u64* value) {
  return htAddPointerPU64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, float value) {
  return htAddPointerFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile float* value) {
  return htAddPointerFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, float value) {
  return htAddPointerPFloat(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile float* value) {
  return htAddPointerPFloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, double value) {
  return htAddPointerDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile double* value) {
  return htAddPointerDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, double value) {
  return htAddPointerPDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile double* value) {
  return htAddPointerPDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, long double value) {
  return htAddPointerLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile long double* value) {
  return htAddPointerLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, long double value) {
  return htAddPointerPLongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile long double* value) {
  return htAddPointerPLongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, List value) {
  return htAddPointerList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile List* value) {
  return htAddPointerListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, List value) {
  return htAddPointerPList(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile List* value) {
  return htAddPointerPListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, Queue value) {
  return htAddPointerQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile Queue* value) {
  return htAddPointerQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, Queue value) {
  return htAddPointerPQueue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile Queue* value) {
  return htAddPointerPQueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, Stack value) {
  return htAddPointerStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile Stack* value) {
  return htAddPointerStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, Stack value) {
  return htAddPointerPStack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile Stack* value) {
  return htAddPointerPStackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, RedBlackTree value) {
  return htAddPointerRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile RedBlackTree* value) {
  return htAddPointerRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, RedBlackTree value) {
  return htAddPointerPRedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile RedBlackTree* value) {
  return htAddPointerPRedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, HashTable value) {
  return htAddPointerHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile HashTable* value) {
  return htAddPointerHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, HashTable value) {
  return htAddPointerPHashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile HashTable* value) {
  return htAddPointerPHashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, Vector value) {
  return htAddPointerVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile Vector* value) {
  return htAddPointerVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, Vector value) {
  return htAddPointerPVector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile Vector* value) {
  return htAddPointerPVectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile char* value) {
  return htAddPointerString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile char** value) {
  return htAddPointerStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile char* value) {
  return htAddPointerPString(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile char** value) {
  return htAddPointerPStringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, Bytes value) {
  return htAddPointerBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile Bytes* value) {
  return htAddPointerBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, Bytes value) {
  return htAddPointerPBytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile Bytes* value) {
  return htAddPointerPBytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, void* value) {
  return htAddPointerPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, const volatile void** value) {
  return htAddPointerPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, void* value) {
  return htAddPointerPPointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, const volatile void** value) {
  return htAddPointerPPointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, i8 value) {
  return htAddPointerI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, i8 value) {
  return htAddPointerPI8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, void* key, u8 value) {
  return htAddPointerU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, const volatile void** key, u8 value) {
  return htAddPointerPU8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, bool value) {
  return htAddI8Bool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile bool* value) {
  return htAddI8BoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, i16 value) {
  return htAddI8I16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile i16* value) {
  return htAddI8I16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, u16 value) {
  return htAddI8U16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile u16* value) {
  return htAddI8U16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, i32 value) {
  return htAddI8I32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile i32* value) {
  return htAddI8I32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, u32 value) {
  return htAddI8U32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile u32* value) {
  return htAddI8U32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, i64 value) {
  return htAddI8I64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile i64* value) {
  return htAddI8I64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, u64 value) {
  return htAddI8U64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile u64* value) {
  return htAddI8U64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, float value) {
  return htAddI8Float(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile float* value) {
  return htAddI8FloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, double value) {
  return htAddI8Double(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile double* value) {
  return htAddI8DoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, long double value) {
  return htAddI8LongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile long double* value) {
  return htAddI8LongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, List value) {
  return htAddI8List(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile List* value) {
  return htAddI8ListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, Queue value) {
  return htAddI8Queue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile Queue* value) {
  return htAddI8QueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, Stack value) {
  return htAddI8Stack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile Stack* value) {
  return htAddI8StackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, RedBlackTree value) {
  return htAddI8RedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile RedBlackTree* value) {
  return htAddI8RedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, HashTable value) {
  return htAddI8HashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile HashTable* value) {
  return htAddI8HashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, Vector value) {
  return htAddI8Vector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile Vector* value) {
  return htAddI8VectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile char* value) {
  return htAddI8String(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile char** value) {
  return htAddI8StringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, Bytes value) {
  return htAddI8Bytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile Bytes* value) {
  return htAddI8BytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, void* value) {
  return htAddI8Pointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, const volatile void** value) {
  return htAddI8PointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, i8 value) {
  return htAddI8I8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, i8 key, u8 value) {
  return htAddI8U8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, bool value) {
  return htAddU8Bool(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile bool* value) {
  return htAddU8BoolP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, i16 value) {
  return htAddU8I16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile i16* value) {
  return htAddU8I16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, u16 value) {
  return htAddU8U16(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile u16* value) {
  return htAddU8U16P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, i32 value) {
  return htAddU8I32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile i32* value) {
  return htAddU8I32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, u32 value) {
  return htAddU8U32(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile u32* value) {
  return htAddU8U32P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, i64 value) {
  return htAddU8I64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile i64* value) {
  return htAddU8I64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, u64 value) {
  return htAddU8U64(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile u64* value) {
  return htAddU8U64P(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, float value) {
  return htAddU8Float(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile float* value) {
  return htAddU8FloatP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, double value) {
  return htAddU8Double(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile double* value) {
  return htAddU8DoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, long double value) {
  return htAddU8LongDouble(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile long double* value) {
  return htAddU8LongDoubleP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, List value) {
  return htAddU8List(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile List* value) {
  return htAddU8ListP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, Queue value) {
  return htAddU8Queue(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile Queue* value) {
  return htAddU8QueueP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, Stack value) {
  return htAddU8Stack(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile Stack* value) {
  return htAddU8StackP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, RedBlackTree value) {
  return htAddU8RedBlackTree(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile RedBlackTree* value) {
  return htAddU8RedBlackTreeP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, HashTable value) {
  return htAddU8HashTable(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile HashTable* value) {
  return htAddU8HashTableP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, Vector value) {
  return htAddU8Vector(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile Vector* value) {
  return htAddU8VectorP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile char* value) {
  return htAddU8String(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile char** value) {
  return htAddU8StringP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, Bytes value) {
  return htAddU8Bytes(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile Bytes* value) {
  return htAddU8BytesP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, void* value) {
  return htAddU8Pointer(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, const volatile void** value) {
  return htAddU8PointerP(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, i8 value) {
  return htAddU8I8(dataStructure, key, value);
}
static inline HashTableNode* htAdd(HashTable *dataStructure, u8 key, u8 value) {
  return htAddU8U8(dataStructure, key, value);
}

#endif // __cplusplus

#endif // TYPE_SAFE_HT_ADD_H

