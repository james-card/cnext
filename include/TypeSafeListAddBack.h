///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              04.21.2024
///
/// @file              TypeSafeListAddBack.h
///
/// @brief             This header contains type-safe versions of the
///                    listAddBack function.
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


#ifndef TYPE_SAFE_LIST_ADD_BACK_H
#define TYPE_SAFE_LIST_ADD_BACK_H

#include "DataTypes.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Type-safe inline functions.

static inline ListNode* listAddBackBoolBool(List *dataStructure, bool key, bool value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddBackBoolBoolP(List *dataStructure, bool key, const volatile bool* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackBoolPBool(List *dataStructure, const volatile bool* key, bool value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackBoolPBoolP(List *dataStructure, const volatile bool* key, const volatile bool* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackBoolI16(List *dataStructure, bool key, i16 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddBackBoolI16P(List *dataStructure, bool key, const volatile i16* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackBoolPI16(List *dataStructure, const volatile bool* key, i16 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackBoolPI16P(List *dataStructure, const volatile bool* key, const volatile i16* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackBoolU16(List *dataStructure, bool key, u16 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddBackBoolU16P(List *dataStructure, bool key, const volatile u16* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackBoolPU16(List *dataStructure, const volatile bool* key, u16 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackBoolPU16P(List *dataStructure, const volatile bool* key, const volatile u16* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackBoolI32(List *dataStructure, bool key, i32 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddBackBoolI32P(List *dataStructure, bool key, const volatile i32* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackBoolPI32(List *dataStructure, const volatile bool* key, i32 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackBoolPI32P(List *dataStructure, const volatile bool* key, const volatile i32* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackBoolU32(List *dataStructure, bool key, u32 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddBackBoolU32P(List *dataStructure, bool key, const volatile u32* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackBoolPU32(List *dataStructure, const volatile bool* key, u32 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackBoolPU32P(List *dataStructure, const volatile bool* key, const volatile u32* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackBoolI64(List *dataStructure, bool key, i64 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddBackBoolI64P(List *dataStructure, bool key, const volatile i64* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackBoolPI64(List *dataStructure, const volatile bool* key, i64 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackBoolPI64P(List *dataStructure, const volatile bool* key, const volatile i64* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackBoolU64(List *dataStructure, bool key, u64 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddBackBoolU64P(List *dataStructure, bool key, const volatile u64* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackBoolPU64(List *dataStructure, const volatile bool* key, u64 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackBoolPU64P(List *dataStructure, const volatile bool* key, const volatile u64* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackBoolFloat(List *dataStructure, bool key, float value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddBackBoolFloatP(List *dataStructure, bool key, const volatile float* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackBoolPFloat(List *dataStructure, const volatile bool* key, float value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackBoolPFloatP(List *dataStructure, const volatile bool* key, const volatile float* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackBoolDouble(List *dataStructure, bool key, double value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddBackBoolDoubleP(List *dataStructure, bool key, const volatile double* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackBoolPDouble(List *dataStructure, const volatile bool* key, double value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackBoolPDoubleP(List *dataStructure, const volatile bool* key, const volatile double* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackBoolLongDouble(List *dataStructure, bool key, long double value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddBackBoolLongDoubleP(List *dataStructure, bool key, const volatile long double* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackBoolPLongDouble(List *dataStructure, const volatile bool* key, long double value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackBoolPLongDoubleP(List *dataStructure, const volatile bool* key, const volatile long double* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackBoolList(List *dataStructure, bool key, List value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddBackBoolListP(List *dataStructure, bool key, const volatile List* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddBackBoolPList(List *dataStructure, const volatile bool* key, List value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackBoolPListP(List *dataStructure, const volatile bool* key, const volatile List* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackBoolQueue(List *dataStructure, bool key, Queue value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddBackBoolQueueP(List *dataStructure, bool key, const volatile Queue* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackBoolPQueue(List *dataStructure, const volatile bool* key, Queue value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackBoolPQueueP(List *dataStructure, const volatile bool* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackBoolStack(List *dataStructure, bool key, Stack value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddBackBoolStackP(List *dataStructure, bool key, const volatile Stack* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackBoolPStack(List *dataStructure, const volatile bool* key, Stack value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackBoolPStackP(List *dataStructure, const volatile bool* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackBoolRedBlackTree(List *dataStructure, bool key, RedBlackTree value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackBoolRedBlackTreeP(List *dataStructure, bool key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackBoolPRedBlackTree(List *dataStructure, const volatile bool* key, RedBlackTree value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackBoolPRedBlackTreeP(List *dataStructure, const volatile bool* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackBoolHashTable(List *dataStructure, bool key, HashTable value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddBackBoolHashTableP(List *dataStructure, bool key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackBoolPHashTable(List *dataStructure, const volatile bool* key, HashTable value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackBoolPHashTableP(List *dataStructure, const volatile bool* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackBoolVector(List *dataStructure, bool key, Vector value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddBackBoolVectorP(List *dataStructure, bool key, const volatile Vector* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackBoolPVector(List *dataStructure, const volatile bool* key, Vector value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackBoolPVectorP(List *dataStructure, const volatile bool* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackBoolString(List *dataStructure, bool key, const volatile char* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddBackBoolStringP(List *dataStructure, bool key, const volatile char** value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackBoolPString(List *dataStructure, const volatile bool* key, const volatile char* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackBoolPStringP(List *dataStructure, const volatile bool* key, const volatile char** value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackBoolBytes(List *dataStructure, bool key, Bytes value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddBackBoolBytesP(List *dataStructure, bool key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackBoolPBytes(List *dataStructure, const volatile bool* key, Bytes value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackBoolPBytesP(List *dataStructure, const volatile bool* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackBoolPointer(List *dataStructure, bool key, void* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddBackBoolPointerP(List *dataStructure, bool key, const volatile void** value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackBoolPPointer(List *dataStructure, const volatile bool* key, void* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackBoolPPointerP(List *dataStructure, const volatile bool* key, const volatile void** value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackBoolI8(List *dataStructure, bool key, i8 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddBackBoolPI8(List *dataStructure, const volatile bool* key, i8 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackBoolU8(List *dataStructure, bool key, u8 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddBackBoolPU8(List *dataStructure, const volatile bool* key, u8 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddBackI16Bool(List *dataStructure, i16 key, bool value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddBackI16BoolP(List *dataStructure, i16 key, const volatile bool* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackI16PBool(List *dataStructure, const volatile i16* key, bool value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackI16PBoolP(List *dataStructure, const volatile i16* key, const volatile bool* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackI16I16(List *dataStructure, i16 key, i16 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddBackI16I16P(List *dataStructure, i16 key, const volatile i16* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackI16PI16(List *dataStructure, const volatile i16* key, i16 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackI16PI16P(List *dataStructure, const volatile i16* key, const volatile i16* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackI16U16(List *dataStructure, i16 key, u16 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddBackI16U16P(List *dataStructure, i16 key, const volatile u16* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackI16PU16(List *dataStructure, const volatile i16* key, u16 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackI16PU16P(List *dataStructure, const volatile i16* key, const volatile u16* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackI16I32(List *dataStructure, i16 key, i32 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddBackI16I32P(List *dataStructure, i16 key, const volatile i32* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackI16PI32(List *dataStructure, const volatile i16* key, i32 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackI16PI32P(List *dataStructure, const volatile i16* key, const volatile i32* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackI16U32(List *dataStructure, i16 key, u32 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddBackI16U32P(List *dataStructure, i16 key, const volatile u32* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackI16PU32(List *dataStructure, const volatile i16* key, u32 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackI16PU32P(List *dataStructure, const volatile i16* key, const volatile u32* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackI16I64(List *dataStructure, i16 key, i64 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddBackI16I64P(List *dataStructure, i16 key, const volatile i64* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackI16PI64(List *dataStructure, const volatile i16* key, i64 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackI16PI64P(List *dataStructure, const volatile i16* key, const volatile i64* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackI16U64(List *dataStructure, i16 key, u64 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddBackI16U64P(List *dataStructure, i16 key, const volatile u64* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackI16PU64(List *dataStructure, const volatile i16* key, u64 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackI16PU64P(List *dataStructure, const volatile i16* key, const volatile u64* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackI16Float(List *dataStructure, i16 key, float value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddBackI16FloatP(List *dataStructure, i16 key, const volatile float* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackI16PFloat(List *dataStructure, const volatile i16* key, float value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackI16PFloatP(List *dataStructure, const volatile i16* key, const volatile float* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackI16Double(List *dataStructure, i16 key, double value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddBackI16DoubleP(List *dataStructure, i16 key, const volatile double* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackI16PDouble(List *dataStructure, const volatile i16* key, double value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackI16PDoubleP(List *dataStructure, const volatile i16* key, const volatile double* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackI16LongDouble(List *dataStructure, i16 key, long double value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddBackI16LongDoubleP(List *dataStructure, i16 key, const volatile long double* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackI16PLongDouble(List *dataStructure, const volatile i16* key, long double value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackI16PLongDoubleP(List *dataStructure, const volatile i16* key, const volatile long double* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackI16List(List *dataStructure, i16 key, List value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddBackI16ListP(List *dataStructure, i16 key, const volatile List* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddBackI16PList(List *dataStructure, const volatile i16* key, List value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackI16PListP(List *dataStructure, const volatile i16* key, const volatile List* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackI16Queue(List *dataStructure, i16 key, Queue value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddBackI16QueueP(List *dataStructure, i16 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackI16PQueue(List *dataStructure, const volatile i16* key, Queue value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackI16PQueueP(List *dataStructure, const volatile i16* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackI16Stack(List *dataStructure, i16 key, Stack value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddBackI16StackP(List *dataStructure, i16 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackI16PStack(List *dataStructure, const volatile i16* key, Stack value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackI16PStackP(List *dataStructure, const volatile i16* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackI16RedBlackTree(List *dataStructure, i16 key, RedBlackTree value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackI16RedBlackTreeP(List *dataStructure, i16 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackI16PRedBlackTree(List *dataStructure, const volatile i16* key, RedBlackTree value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackI16PRedBlackTreeP(List *dataStructure, const volatile i16* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackI16HashTable(List *dataStructure, i16 key, HashTable value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddBackI16HashTableP(List *dataStructure, i16 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackI16PHashTable(List *dataStructure, const volatile i16* key, HashTable value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackI16PHashTableP(List *dataStructure, const volatile i16* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackI16Vector(List *dataStructure, i16 key, Vector value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddBackI16VectorP(List *dataStructure, i16 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackI16PVector(List *dataStructure, const volatile i16* key, Vector value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackI16PVectorP(List *dataStructure, const volatile i16* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackI16String(List *dataStructure, i16 key, const volatile char* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddBackI16StringP(List *dataStructure, i16 key, const volatile char** value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackI16PString(List *dataStructure, const volatile i16* key, const volatile char* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackI16PStringP(List *dataStructure, const volatile i16* key, const volatile char** value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackI16Bytes(List *dataStructure, i16 key, Bytes value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddBackI16BytesP(List *dataStructure, i16 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackI16PBytes(List *dataStructure, const volatile i16* key, Bytes value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackI16PBytesP(List *dataStructure, const volatile i16* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackI16Pointer(List *dataStructure, i16 key, void* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddBackI16PointerP(List *dataStructure, i16 key, const volatile void** value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackI16PPointer(List *dataStructure, const volatile i16* key, void* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackI16PPointerP(List *dataStructure, const volatile i16* key, const volatile void** value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackI16I8(List *dataStructure, i16 key, i8 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddBackI16PI8(List *dataStructure, const volatile i16* key, i8 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackI16U8(List *dataStructure, i16 key, u8 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddBackI16PU8(List *dataStructure, const volatile i16* key, u8 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddBackU16Bool(List *dataStructure, u16 key, bool value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddBackU16BoolP(List *dataStructure, u16 key, const volatile bool* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackU16PBool(List *dataStructure, const volatile u16* key, bool value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackU16PBoolP(List *dataStructure, const volatile u16* key, const volatile bool* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackU16I16(List *dataStructure, u16 key, i16 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddBackU16I16P(List *dataStructure, u16 key, const volatile i16* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackU16PI16(List *dataStructure, const volatile u16* key, i16 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackU16PI16P(List *dataStructure, const volatile u16* key, const volatile i16* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackU16U16(List *dataStructure, u16 key, u16 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddBackU16U16P(List *dataStructure, u16 key, const volatile u16* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackU16PU16(List *dataStructure, const volatile u16* key, u16 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackU16PU16P(List *dataStructure, const volatile u16* key, const volatile u16* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackU16I32(List *dataStructure, u16 key, i32 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddBackU16I32P(List *dataStructure, u16 key, const volatile i32* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackU16PI32(List *dataStructure, const volatile u16* key, i32 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackU16PI32P(List *dataStructure, const volatile u16* key, const volatile i32* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackU16U32(List *dataStructure, u16 key, u32 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddBackU16U32P(List *dataStructure, u16 key, const volatile u32* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackU16PU32(List *dataStructure, const volatile u16* key, u32 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackU16PU32P(List *dataStructure, const volatile u16* key, const volatile u32* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackU16I64(List *dataStructure, u16 key, i64 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddBackU16I64P(List *dataStructure, u16 key, const volatile i64* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackU16PI64(List *dataStructure, const volatile u16* key, i64 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackU16PI64P(List *dataStructure, const volatile u16* key, const volatile i64* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackU16U64(List *dataStructure, u16 key, u64 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddBackU16U64P(List *dataStructure, u16 key, const volatile u64* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackU16PU64(List *dataStructure, const volatile u16* key, u64 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackU16PU64P(List *dataStructure, const volatile u16* key, const volatile u64* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackU16Float(List *dataStructure, u16 key, float value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddBackU16FloatP(List *dataStructure, u16 key, const volatile float* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackU16PFloat(List *dataStructure, const volatile u16* key, float value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackU16PFloatP(List *dataStructure, const volatile u16* key, const volatile float* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackU16Double(List *dataStructure, u16 key, double value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddBackU16DoubleP(List *dataStructure, u16 key, const volatile double* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackU16PDouble(List *dataStructure, const volatile u16* key, double value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackU16PDoubleP(List *dataStructure, const volatile u16* key, const volatile double* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackU16LongDouble(List *dataStructure, u16 key, long double value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddBackU16LongDoubleP(List *dataStructure, u16 key, const volatile long double* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackU16PLongDouble(List *dataStructure, const volatile u16* key, long double value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackU16PLongDoubleP(List *dataStructure, const volatile u16* key, const volatile long double* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackU16List(List *dataStructure, u16 key, List value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddBackU16ListP(List *dataStructure, u16 key, const volatile List* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddBackU16PList(List *dataStructure, const volatile u16* key, List value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackU16PListP(List *dataStructure, const volatile u16* key, const volatile List* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackU16Queue(List *dataStructure, u16 key, Queue value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddBackU16QueueP(List *dataStructure, u16 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackU16PQueue(List *dataStructure, const volatile u16* key, Queue value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackU16PQueueP(List *dataStructure, const volatile u16* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackU16Stack(List *dataStructure, u16 key, Stack value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddBackU16StackP(List *dataStructure, u16 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackU16PStack(List *dataStructure, const volatile u16* key, Stack value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackU16PStackP(List *dataStructure, const volatile u16* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackU16RedBlackTree(List *dataStructure, u16 key, RedBlackTree value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackU16RedBlackTreeP(List *dataStructure, u16 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackU16PRedBlackTree(List *dataStructure, const volatile u16* key, RedBlackTree value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackU16PRedBlackTreeP(List *dataStructure, const volatile u16* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackU16HashTable(List *dataStructure, u16 key, HashTable value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddBackU16HashTableP(List *dataStructure, u16 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackU16PHashTable(List *dataStructure, const volatile u16* key, HashTable value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackU16PHashTableP(List *dataStructure, const volatile u16* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackU16Vector(List *dataStructure, u16 key, Vector value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddBackU16VectorP(List *dataStructure, u16 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackU16PVector(List *dataStructure, const volatile u16* key, Vector value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackU16PVectorP(List *dataStructure, const volatile u16* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackU16String(List *dataStructure, u16 key, const volatile char* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddBackU16StringP(List *dataStructure, u16 key, const volatile char** value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackU16PString(List *dataStructure, const volatile u16* key, const volatile char* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackU16PStringP(List *dataStructure, const volatile u16* key, const volatile char** value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackU16Bytes(List *dataStructure, u16 key, Bytes value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddBackU16BytesP(List *dataStructure, u16 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackU16PBytes(List *dataStructure, const volatile u16* key, Bytes value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackU16PBytesP(List *dataStructure, const volatile u16* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackU16Pointer(List *dataStructure, u16 key, void* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddBackU16PointerP(List *dataStructure, u16 key, const volatile void** value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackU16PPointer(List *dataStructure, const volatile u16* key, void* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackU16PPointerP(List *dataStructure, const volatile u16* key, const volatile void** value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackU16I8(List *dataStructure, u16 key, i8 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddBackU16PI8(List *dataStructure, const volatile u16* key, i8 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackU16U8(List *dataStructure, u16 key, u8 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddBackU16PU8(List *dataStructure, const volatile u16* key, u8 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddBackI32Bool(List *dataStructure, i32 key, bool value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddBackI32BoolP(List *dataStructure, i32 key, const volatile bool* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackI32PBool(List *dataStructure, const volatile i32* key, bool value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackI32PBoolP(List *dataStructure, const volatile i32* key, const volatile bool* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackI32I16(List *dataStructure, i32 key, i16 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddBackI32I16P(List *dataStructure, i32 key, const volatile i16* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackI32PI16(List *dataStructure, const volatile i32* key, i16 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackI32PI16P(List *dataStructure, const volatile i32* key, const volatile i16* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackI32U16(List *dataStructure, i32 key, u16 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddBackI32U16P(List *dataStructure, i32 key, const volatile u16* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackI32PU16(List *dataStructure, const volatile i32* key, u16 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackI32PU16P(List *dataStructure, const volatile i32* key, const volatile u16* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackI32I32(List *dataStructure, i32 key, i32 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddBackI32I32P(List *dataStructure, i32 key, const volatile i32* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackI32PI32(List *dataStructure, const volatile i32* key, i32 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackI32PI32P(List *dataStructure, const volatile i32* key, const volatile i32* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackI32U32(List *dataStructure, i32 key, u32 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddBackI32U32P(List *dataStructure, i32 key, const volatile u32* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackI32PU32(List *dataStructure, const volatile i32* key, u32 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackI32PU32P(List *dataStructure, const volatile i32* key, const volatile u32* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackI32I64(List *dataStructure, i32 key, i64 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddBackI32I64P(List *dataStructure, i32 key, const volatile i64* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackI32PI64(List *dataStructure, const volatile i32* key, i64 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackI32PI64P(List *dataStructure, const volatile i32* key, const volatile i64* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackI32U64(List *dataStructure, i32 key, u64 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddBackI32U64P(List *dataStructure, i32 key, const volatile u64* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackI32PU64(List *dataStructure, const volatile i32* key, u64 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackI32PU64P(List *dataStructure, const volatile i32* key, const volatile u64* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackI32Float(List *dataStructure, i32 key, float value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddBackI32FloatP(List *dataStructure, i32 key, const volatile float* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackI32PFloat(List *dataStructure, const volatile i32* key, float value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackI32PFloatP(List *dataStructure, const volatile i32* key, const volatile float* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackI32Double(List *dataStructure, i32 key, double value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddBackI32DoubleP(List *dataStructure, i32 key, const volatile double* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackI32PDouble(List *dataStructure, const volatile i32* key, double value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackI32PDoubleP(List *dataStructure, const volatile i32* key, const volatile double* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackI32LongDouble(List *dataStructure, i32 key, long double value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddBackI32LongDoubleP(List *dataStructure, i32 key, const volatile long double* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackI32PLongDouble(List *dataStructure, const volatile i32* key, long double value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackI32PLongDoubleP(List *dataStructure, const volatile i32* key, const volatile long double* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackI32List(List *dataStructure, i32 key, List value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddBackI32ListP(List *dataStructure, i32 key, const volatile List* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddBackI32PList(List *dataStructure, const volatile i32* key, List value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackI32PListP(List *dataStructure, const volatile i32* key, const volatile List* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackI32Queue(List *dataStructure, i32 key, Queue value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddBackI32QueueP(List *dataStructure, i32 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackI32PQueue(List *dataStructure, const volatile i32* key, Queue value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackI32PQueueP(List *dataStructure, const volatile i32* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackI32Stack(List *dataStructure, i32 key, Stack value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddBackI32StackP(List *dataStructure, i32 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackI32PStack(List *dataStructure, const volatile i32* key, Stack value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackI32PStackP(List *dataStructure, const volatile i32* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackI32RedBlackTree(List *dataStructure, i32 key, RedBlackTree value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackI32RedBlackTreeP(List *dataStructure, i32 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackI32PRedBlackTree(List *dataStructure, const volatile i32* key, RedBlackTree value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackI32PRedBlackTreeP(List *dataStructure, const volatile i32* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackI32HashTable(List *dataStructure, i32 key, HashTable value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddBackI32HashTableP(List *dataStructure, i32 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackI32PHashTable(List *dataStructure, const volatile i32* key, HashTable value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackI32PHashTableP(List *dataStructure, const volatile i32* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackI32Vector(List *dataStructure, i32 key, Vector value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddBackI32VectorP(List *dataStructure, i32 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackI32PVector(List *dataStructure, const volatile i32* key, Vector value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackI32PVectorP(List *dataStructure, const volatile i32* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackI32String(List *dataStructure, i32 key, const volatile char* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddBackI32StringP(List *dataStructure, i32 key, const volatile char** value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackI32PString(List *dataStructure, const volatile i32* key, const volatile char* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackI32PStringP(List *dataStructure, const volatile i32* key, const volatile char** value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackI32Bytes(List *dataStructure, i32 key, Bytes value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddBackI32BytesP(List *dataStructure, i32 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackI32PBytes(List *dataStructure, const volatile i32* key, Bytes value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackI32PBytesP(List *dataStructure, const volatile i32* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackI32Pointer(List *dataStructure, i32 key, void* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddBackI32PointerP(List *dataStructure, i32 key, const volatile void** value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackI32PPointer(List *dataStructure, const volatile i32* key, void* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackI32PPointerP(List *dataStructure, const volatile i32* key, const volatile void** value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackI32I8(List *dataStructure, i32 key, i8 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddBackI32PI8(List *dataStructure, const volatile i32* key, i8 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackI32U8(List *dataStructure, i32 key, u8 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddBackI32PU8(List *dataStructure, const volatile i32* key, u8 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddBackU32Bool(List *dataStructure, u32 key, bool value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddBackU32BoolP(List *dataStructure, u32 key, const volatile bool* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackU32PBool(List *dataStructure, const volatile u32* key, bool value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackU32PBoolP(List *dataStructure, const volatile u32* key, const volatile bool* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackU32I16(List *dataStructure, u32 key, i16 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddBackU32I16P(List *dataStructure, u32 key, const volatile i16* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackU32PI16(List *dataStructure, const volatile u32* key, i16 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackU32PI16P(List *dataStructure, const volatile u32* key, const volatile i16* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackU32U16(List *dataStructure, u32 key, u16 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddBackU32U16P(List *dataStructure, u32 key, const volatile u16* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackU32PU16(List *dataStructure, const volatile u32* key, u16 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackU32PU16P(List *dataStructure, const volatile u32* key, const volatile u16* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackU32I32(List *dataStructure, u32 key, i32 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddBackU32I32P(List *dataStructure, u32 key, const volatile i32* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackU32PI32(List *dataStructure, const volatile u32* key, i32 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackU32PI32P(List *dataStructure, const volatile u32* key, const volatile i32* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackU32U32(List *dataStructure, u32 key, u32 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddBackU32U32P(List *dataStructure, u32 key, const volatile u32* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackU32PU32(List *dataStructure, const volatile u32* key, u32 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackU32PU32P(List *dataStructure, const volatile u32* key, const volatile u32* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackU32I64(List *dataStructure, u32 key, i64 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddBackU32I64P(List *dataStructure, u32 key, const volatile i64* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackU32PI64(List *dataStructure, const volatile u32* key, i64 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackU32PI64P(List *dataStructure, const volatile u32* key, const volatile i64* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackU32U64(List *dataStructure, u32 key, u64 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddBackU32U64P(List *dataStructure, u32 key, const volatile u64* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackU32PU64(List *dataStructure, const volatile u32* key, u64 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackU32PU64P(List *dataStructure, const volatile u32* key, const volatile u64* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackU32Float(List *dataStructure, u32 key, float value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddBackU32FloatP(List *dataStructure, u32 key, const volatile float* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackU32PFloat(List *dataStructure, const volatile u32* key, float value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackU32PFloatP(List *dataStructure, const volatile u32* key, const volatile float* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackU32Double(List *dataStructure, u32 key, double value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddBackU32DoubleP(List *dataStructure, u32 key, const volatile double* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackU32PDouble(List *dataStructure, const volatile u32* key, double value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackU32PDoubleP(List *dataStructure, const volatile u32* key, const volatile double* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackU32LongDouble(List *dataStructure, u32 key, long double value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddBackU32LongDoubleP(List *dataStructure, u32 key, const volatile long double* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackU32PLongDouble(List *dataStructure, const volatile u32* key, long double value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackU32PLongDoubleP(List *dataStructure, const volatile u32* key, const volatile long double* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackU32List(List *dataStructure, u32 key, List value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddBackU32ListP(List *dataStructure, u32 key, const volatile List* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddBackU32PList(List *dataStructure, const volatile u32* key, List value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackU32PListP(List *dataStructure, const volatile u32* key, const volatile List* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackU32Queue(List *dataStructure, u32 key, Queue value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddBackU32QueueP(List *dataStructure, u32 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackU32PQueue(List *dataStructure, const volatile u32* key, Queue value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackU32PQueueP(List *dataStructure, const volatile u32* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackU32Stack(List *dataStructure, u32 key, Stack value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddBackU32StackP(List *dataStructure, u32 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackU32PStack(List *dataStructure, const volatile u32* key, Stack value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackU32PStackP(List *dataStructure, const volatile u32* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackU32RedBlackTree(List *dataStructure, u32 key, RedBlackTree value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackU32RedBlackTreeP(List *dataStructure, u32 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackU32PRedBlackTree(List *dataStructure, const volatile u32* key, RedBlackTree value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackU32PRedBlackTreeP(List *dataStructure, const volatile u32* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackU32HashTable(List *dataStructure, u32 key, HashTable value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddBackU32HashTableP(List *dataStructure, u32 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackU32PHashTable(List *dataStructure, const volatile u32* key, HashTable value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackU32PHashTableP(List *dataStructure, const volatile u32* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackU32Vector(List *dataStructure, u32 key, Vector value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddBackU32VectorP(List *dataStructure, u32 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackU32PVector(List *dataStructure, const volatile u32* key, Vector value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackU32PVectorP(List *dataStructure, const volatile u32* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackU32String(List *dataStructure, u32 key, const volatile char* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddBackU32StringP(List *dataStructure, u32 key, const volatile char** value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackU32PString(List *dataStructure, const volatile u32* key, const volatile char* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackU32PStringP(List *dataStructure, const volatile u32* key, const volatile char** value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackU32Bytes(List *dataStructure, u32 key, Bytes value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddBackU32BytesP(List *dataStructure, u32 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackU32PBytes(List *dataStructure, const volatile u32* key, Bytes value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackU32PBytesP(List *dataStructure, const volatile u32* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackU32Pointer(List *dataStructure, u32 key, void* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddBackU32PointerP(List *dataStructure, u32 key, const volatile void** value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackU32PPointer(List *dataStructure, const volatile u32* key, void* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackU32PPointerP(List *dataStructure, const volatile u32* key, const volatile void** value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackU32I8(List *dataStructure, u32 key, i8 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddBackU32PI8(List *dataStructure, const volatile u32* key, i8 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackU32U8(List *dataStructure, u32 key, u8 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddBackU32PU8(List *dataStructure, const volatile u32* key, u8 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddBackI64Bool(List *dataStructure, i64 key, bool value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddBackI64BoolP(List *dataStructure, i64 key, const volatile bool* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackI64PBool(List *dataStructure, const volatile i64* key, bool value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackI64PBoolP(List *dataStructure, const volatile i64* key, const volatile bool* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackI64I16(List *dataStructure, i64 key, i16 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddBackI64I16P(List *dataStructure, i64 key, const volatile i16* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackI64PI16(List *dataStructure, const volatile i64* key, i16 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackI64PI16P(List *dataStructure, const volatile i64* key, const volatile i16* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackI64U16(List *dataStructure, i64 key, u16 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddBackI64U16P(List *dataStructure, i64 key, const volatile u16* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackI64PU16(List *dataStructure, const volatile i64* key, u16 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackI64PU16P(List *dataStructure, const volatile i64* key, const volatile u16* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackI64I32(List *dataStructure, i64 key, i32 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddBackI64I32P(List *dataStructure, i64 key, const volatile i32* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackI64PI32(List *dataStructure, const volatile i64* key, i32 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackI64PI32P(List *dataStructure, const volatile i64* key, const volatile i32* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackI64U32(List *dataStructure, i64 key, u32 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddBackI64U32P(List *dataStructure, i64 key, const volatile u32* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackI64PU32(List *dataStructure, const volatile i64* key, u32 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackI64PU32P(List *dataStructure, const volatile i64* key, const volatile u32* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackI64I64(List *dataStructure, i64 key, i64 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddBackI64I64P(List *dataStructure, i64 key, const volatile i64* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackI64PI64(List *dataStructure, const volatile i64* key, i64 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackI64PI64P(List *dataStructure, const volatile i64* key, const volatile i64* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackI64U64(List *dataStructure, i64 key, u64 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddBackI64U64P(List *dataStructure, i64 key, const volatile u64* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackI64PU64(List *dataStructure, const volatile i64* key, u64 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackI64PU64P(List *dataStructure, const volatile i64* key, const volatile u64* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackI64Float(List *dataStructure, i64 key, float value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddBackI64FloatP(List *dataStructure, i64 key, const volatile float* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackI64PFloat(List *dataStructure, const volatile i64* key, float value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackI64PFloatP(List *dataStructure, const volatile i64* key, const volatile float* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackI64Double(List *dataStructure, i64 key, double value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddBackI64DoubleP(List *dataStructure, i64 key, const volatile double* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackI64PDouble(List *dataStructure, const volatile i64* key, double value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackI64PDoubleP(List *dataStructure, const volatile i64* key, const volatile double* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackI64LongDouble(List *dataStructure, i64 key, long double value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddBackI64LongDoubleP(List *dataStructure, i64 key, const volatile long double* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackI64PLongDouble(List *dataStructure, const volatile i64* key, long double value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackI64PLongDoubleP(List *dataStructure, const volatile i64* key, const volatile long double* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackI64List(List *dataStructure, i64 key, List value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddBackI64ListP(List *dataStructure, i64 key, const volatile List* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddBackI64PList(List *dataStructure, const volatile i64* key, List value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackI64PListP(List *dataStructure, const volatile i64* key, const volatile List* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackI64Queue(List *dataStructure, i64 key, Queue value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddBackI64QueueP(List *dataStructure, i64 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackI64PQueue(List *dataStructure, const volatile i64* key, Queue value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackI64PQueueP(List *dataStructure, const volatile i64* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackI64Stack(List *dataStructure, i64 key, Stack value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddBackI64StackP(List *dataStructure, i64 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackI64PStack(List *dataStructure, const volatile i64* key, Stack value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackI64PStackP(List *dataStructure, const volatile i64* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackI64RedBlackTree(List *dataStructure, i64 key, RedBlackTree value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackI64RedBlackTreeP(List *dataStructure, i64 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackI64PRedBlackTree(List *dataStructure, const volatile i64* key, RedBlackTree value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackI64PRedBlackTreeP(List *dataStructure, const volatile i64* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackI64HashTable(List *dataStructure, i64 key, HashTable value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddBackI64HashTableP(List *dataStructure, i64 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackI64PHashTable(List *dataStructure, const volatile i64* key, HashTable value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackI64PHashTableP(List *dataStructure, const volatile i64* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackI64Vector(List *dataStructure, i64 key, Vector value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddBackI64VectorP(List *dataStructure, i64 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackI64PVector(List *dataStructure, const volatile i64* key, Vector value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackI64PVectorP(List *dataStructure, const volatile i64* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackI64String(List *dataStructure, i64 key, const volatile char* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddBackI64StringP(List *dataStructure, i64 key, const volatile char** value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackI64PString(List *dataStructure, const volatile i64* key, const volatile char* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackI64PStringP(List *dataStructure, const volatile i64* key, const volatile char** value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackI64Bytes(List *dataStructure, i64 key, Bytes value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddBackI64BytesP(List *dataStructure, i64 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackI64PBytes(List *dataStructure, const volatile i64* key, Bytes value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackI64PBytesP(List *dataStructure, const volatile i64* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackI64Pointer(List *dataStructure, i64 key, void* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddBackI64PointerP(List *dataStructure, i64 key, const volatile void** value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackI64PPointer(List *dataStructure, const volatile i64* key, void* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackI64PPointerP(List *dataStructure, const volatile i64* key, const volatile void** value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackI64I8(List *dataStructure, i64 key, i8 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddBackI64PI8(List *dataStructure, const volatile i64* key, i8 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackI64U8(List *dataStructure, i64 key, u8 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddBackI64PU8(List *dataStructure, const volatile i64* key, u8 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddBackU64Bool(List *dataStructure, u64 key, bool value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddBackU64BoolP(List *dataStructure, u64 key, const volatile bool* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackU64PBool(List *dataStructure, const volatile u64* key, bool value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackU64PBoolP(List *dataStructure, const volatile u64* key, const volatile bool* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackU64I16(List *dataStructure, u64 key, i16 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddBackU64I16P(List *dataStructure, u64 key, const volatile i16* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackU64PI16(List *dataStructure, const volatile u64* key, i16 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackU64PI16P(List *dataStructure, const volatile u64* key, const volatile i16* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackU64U16(List *dataStructure, u64 key, u16 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddBackU64U16P(List *dataStructure, u64 key, const volatile u16* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackU64PU16(List *dataStructure, const volatile u64* key, u16 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackU64PU16P(List *dataStructure, const volatile u64* key, const volatile u16* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackU64I32(List *dataStructure, u64 key, i32 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddBackU64I32P(List *dataStructure, u64 key, const volatile i32* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackU64PI32(List *dataStructure, const volatile u64* key, i32 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackU64PI32P(List *dataStructure, const volatile u64* key, const volatile i32* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackU64U32(List *dataStructure, u64 key, u32 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddBackU64U32P(List *dataStructure, u64 key, const volatile u32* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackU64PU32(List *dataStructure, const volatile u64* key, u32 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackU64PU32P(List *dataStructure, const volatile u64* key, const volatile u32* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackU64I64(List *dataStructure, u64 key, i64 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddBackU64I64P(List *dataStructure, u64 key, const volatile i64* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackU64PI64(List *dataStructure, const volatile u64* key, i64 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackU64PI64P(List *dataStructure, const volatile u64* key, const volatile i64* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackU64U64(List *dataStructure, u64 key, u64 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddBackU64U64P(List *dataStructure, u64 key, const volatile u64* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackU64PU64(List *dataStructure, const volatile u64* key, u64 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackU64PU64P(List *dataStructure, const volatile u64* key, const volatile u64* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackU64Float(List *dataStructure, u64 key, float value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddBackU64FloatP(List *dataStructure, u64 key, const volatile float* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackU64PFloat(List *dataStructure, const volatile u64* key, float value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackU64PFloatP(List *dataStructure, const volatile u64* key, const volatile float* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackU64Double(List *dataStructure, u64 key, double value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddBackU64DoubleP(List *dataStructure, u64 key, const volatile double* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackU64PDouble(List *dataStructure, const volatile u64* key, double value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackU64PDoubleP(List *dataStructure, const volatile u64* key, const volatile double* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackU64LongDouble(List *dataStructure, u64 key, long double value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddBackU64LongDoubleP(List *dataStructure, u64 key, const volatile long double* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackU64PLongDouble(List *dataStructure, const volatile u64* key, long double value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackU64PLongDoubleP(List *dataStructure, const volatile u64* key, const volatile long double* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackU64List(List *dataStructure, u64 key, List value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddBackU64ListP(List *dataStructure, u64 key, const volatile List* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddBackU64PList(List *dataStructure, const volatile u64* key, List value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackU64PListP(List *dataStructure, const volatile u64* key, const volatile List* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackU64Queue(List *dataStructure, u64 key, Queue value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddBackU64QueueP(List *dataStructure, u64 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackU64PQueue(List *dataStructure, const volatile u64* key, Queue value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackU64PQueueP(List *dataStructure, const volatile u64* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackU64Stack(List *dataStructure, u64 key, Stack value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddBackU64StackP(List *dataStructure, u64 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackU64PStack(List *dataStructure, const volatile u64* key, Stack value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackU64PStackP(List *dataStructure, const volatile u64* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackU64RedBlackTree(List *dataStructure, u64 key, RedBlackTree value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackU64RedBlackTreeP(List *dataStructure, u64 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackU64PRedBlackTree(List *dataStructure, const volatile u64* key, RedBlackTree value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackU64PRedBlackTreeP(List *dataStructure, const volatile u64* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackU64HashTable(List *dataStructure, u64 key, HashTable value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddBackU64HashTableP(List *dataStructure, u64 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackU64PHashTable(List *dataStructure, const volatile u64* key, HashTable value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackU64PHashTableP(List *dataStructure, const volatile u64* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackU64Vector(List *dataStructure, u64 key, Vector value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddBackU64VectorP(List *dataStructure, u64 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackU64PVector(List *dataStructure, const volatile u64* key, Vector value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackU64PVectorP(List *dataStructure, const volatile u64* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackU64String(List *dataStructure, u64 key, const volatile char* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddBackU64StringP(List *dataStructure, u64 key, const volatile char** value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackU64PString(List *dataStructure, const volatile u64* key, const volatile char* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackU64PStringP(List *dataStructure, const volatile u64* key, const volatile char** value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackU64Bytes(List *dataStructure, u64 key, Bytes value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddBackU64BytesP(List *dataStructure, u64 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackU64PBytes(List *dataStructure, const volatile u64* key, Bytes value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackU64PBytesP(List *dataStructure, const volatile u64* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackU64Pointer(List *dataStructure, u64 key, void* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddBackU64PointerP(List *dataStructure, u64 key, const volatile void** value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackU64PPointer(List *dataStructure, const volatile u64* key, void* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackU64PPointerP(List *dataStructure, const volatile u64* key, const volatile void** value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackU64I8(List *dataStructure, u64 key, i8 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddBackU64PI8(List *dataStructure, const volatile u64* key, i8 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackU64U8(List *dataStructure, u64 key, u8 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddBackU64PU8(List *dataStructure, const volatile u64* key, u8 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddBackFloatBool(List *dataStructure, float key, bool value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddBackFloatBoolP(List *dataStructure, float key, const volatile bool* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackFloatPBool(List *dataStructure, const volatile float* key, bool value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackFloatPBoolP(List *dataStructure, const volatile float* key, const volatile bool* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackFloatI16(List *dataStructure, float key, i16 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddBackFloatI16P(List *dataStructure, float key, const volatile i16* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackFloatPI16(List *dataStructure, const volatile float* key, i16 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackFloatPI16P(List *dataStructure, const volatile float* key, const volatile i16* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackFloatU16(List *dataStructure, float key, u16 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddBackFloatU16P(List *dataStructure, float key, const volatile u16* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackFloatPU16(List *dataStructure, const volatile float* key, u16 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackFloatPU16P(List *dataStructure, const volatile float* key, const volatile u16* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackFloatI32(List *dataStructure, float key, i32 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddBackFloatI32P(List *dataStructure, float key, const volatile i32* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackFloatPI32(List *dataStructure, const volatile float* key, i32 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackFloatPI32P(List *dataStructure, const volatile float* key, const volatile i32* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackFloatU32(List *dataStructure, float key, u32 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddBackFloatU32P(List *dataStructure, float key, const volatile u32* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackFloatPU32(List *dataStructure, const volatile float* key, u32 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackFloatPU32P(List *dataStructure, const volatile float* key, const volatile u32* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackFloatI64(List *dataStructure, float key, i64 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddBackFloatI64P(List *dataStructure, float key, const volatile i64* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackFloatPI64(List *dataStructure, const volatile float* key, i64 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackFloatPI64P(List *dataStructure, const volatile float* key, const volatile i64* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackFloatU64(List *dataStructure, float key, u64 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddBackFloatU64P(List *dataStructure, float key, const volatile u64* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackFloatPU64(List *dataStructure, const volatile float* key, u64 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackFloatPU64P(List *dataStructure, const volatile float* key, const volatile u64* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackFloatFloat(List *dataStructure, float key, float value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddBackFloatFloatP(List *dataStructure, float key, const volatile float* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackFloatPFloat(List *dataStructure, const volatile float* key, float value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackFloatPFloatP(List *dataStructure, const volatile float* key, const volatile float* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackFloatDouble(List *dataStructure, float key, double value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddBackFloatDoubleP(List *dataStructure, float key, const volatile double* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackFloatPDouble(List *dataStructure, const volatile float* key, double value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackFloatPDoubleP(List *dataStructure, const volatile float* key, const volatile double* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackFloatLongDouble(List *dataStructure, float key, long double value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddBackFloatLongDoubleP(List *dataStructure, float key, const volatile long double* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackFloatPLongDouble(List *dataStructure, const volatile float* key, long double value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackFloatPLongDoubleP(List *dataStructure, const volatile float* key, const volatile long double* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackFloatList(List *dataStructure, float key, List value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddBackFloatListP(List *dataStructure, float key, const volatile List* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddBackFloatPList(List *dataStructure, const volatile float* key, List value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackFloatPListP(List *dataStructure, const volatile float* key, const volatile List* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackFloatQueue(List *dataStructure, float key, Queue value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddBackFloatQueueP(List *dataStructure, float key, const volatile Queue* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackFloatPQueue(List *dataStructure, const volatile float* key, Queue value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackFloatPQueueP(List *dataStructure, const volatile float* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackFloatStack(List *dataStructure, float key, Stack value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddBackFloatStackP(List *dataStructure, float key, const volatile Stack* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackFloatPStack(List *dataStructure, const volatile float* key, Stack value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackFloatPStackP(List *dataStructure, const volatile float* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackFloatRedBlackTree(List *dataStructure, float key, RedBlackTree value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackFloatRedBlackTreeP(List *dataStructure, float key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackFloatPRedBlackTree(List *dataStructure, const volatile float* key, RedBlackTree value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackFloatPRedBlackTreeP(List *dataStructure, const volatile float* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackFloatHashTable(List *dataStructure, float key, HashTable value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddBackFloatHashTableP(List *dataStructure, float key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackFloatPHashTable(List *dataStructure, const volatile float* key, HashTable value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackFloatPHashTableP(List *dataStructure, const volatile float* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackFloatVector(List *dataStructure, float key, Vector value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddBackFloatVectorP(List *dataStructure, float key, const volatile Vector* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackFloatPVector(List *dataStructure, const volatile float* key, Vector value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackFloatPVectorP(List *dataStructure, const volatile float* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackFloatString(List *dataStructure, float key, const volatile char* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddBackFloatStringP(List *dataStructure, float key, const volatile char** value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackFloatPString(List *dataStructure, const volatile float* key, const volatile char* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackFloatPStringP(List *dataStructure, const volatile float* key, const volatile char** value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackFloatBytes(List *dataStructure, float key, Bytes value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddBackFloatBytesP(List *dataStructure, float key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackFloatPBytes(List *dataStructure, const volatile float* key, Bytes value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackFloatPBytesP(List *dataStructure, const volatile float* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackFloatPointer(List *dataStructure, float key, void* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddBackFloatPointerP(List *dataStructure, float key, const volatile void** value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackFloatPPointer(List *dataStructure, const volatile float* key, void* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackFloatPPointerP(List *dataStructure, const volatile float* key, const volatile void** value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackFloatI8(List *dataStructure, float key, i8 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddBackFloatPI8(List *dataStructure, const volatile float* key, i8 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackFloatU8(List *dataStructure, float key, u8 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddBackFloatPU8(List *dataStructure, const volatile float* key, u8 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddBackDoubleBool(List *dataStructure, double key, bool value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddBackDoubleBoolP(List *dataStructure, double key, const volatile bool* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackDoublePBool(List *dataStructure, const volatile double* key, bool value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackDoublePBoolP(List *dataStructure, const volatile double* key, const volatile bool* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackDoubleI16(List *dataStructure, double key, i16 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddBackDoubleI16P(List *dataStructure, double key, const volatile i16* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackDoublePI16(List *dataStructure, const volatile double* key, i16 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackDoublePI16P(List *dataStructure, const volatile double* key, const volatile i16* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackDoubleU16(List *dataStructure, double key, u16 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddBackDoubleU16P(List *dataStructure, double key, const volatile u16* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackDoublePU16(List *dataStructure, const volatile double* key, u16 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackDoublePU16P(List *dataStructure, const volatile double* key, const volatile u16* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackDoubleI32(List *dataStructure, double key, i32 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddBackDoubleI32P(List *dataStructure, double key, const volatile i32* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackDoublePI32(List *dataStructure, const volatile double* key, i32 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackDoublePI32P(List *dataStructure, const volatile double* key, const volatile i32* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackDoubleU32(List *dataStructure, double key, u32 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddBackDoubleU32P(List *dataStructure, double key, const volatile u32* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackDoublePU32(List *dataStructure, const volatile double* key, u32 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackDoublePU32P(List *dataStructure, const volatile double* key, const volatile u32* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackDoubleI64(List *dataStructure, double key, i64 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddBackDoubleI64P(List *dataStructure, double key, const volatile i64* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackDoublePI64(List *dataStructure, const volatile double* key, i64 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackDoublePI64P(List *dataStructure, const volatile double* key, const volatile i64* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackDoubleU64(List *dataStructure, double key, u64 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddBackDoubleU64P(List *dataStructure, double key, const volatile u64* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackDoublePU64(List *dataStructure, const volatile double* key, u64 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackDoublePU64P(List *dataStructure, const volatile double* key, const volatile u64* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackDoubleFloat(List *dataStructure, double key, float value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddBackDoubleFloatP(List *dataStructure, double key, const volatile float* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackDoublePFloat(List *dataStructure, const volatile double* key, float value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackDoublePFloatP(List *dataStructure, const volatile double* key, const volatile float* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackDoubleDouble(List *dataStructure, double key, double value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddBackDoubleDoubleP(List *dataStructure, double key, const volatile double* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackDoublePDouble(List *dataStructure, const volatile double* key, double value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackDoublePDoubleP(List *dataStructure, const volatile double* key, const volatile double* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackDoubleLongDouble(List *dataStructure, double key, long double value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddBackDoubleLongDoubleP(List *dataStructure, double key, const volatile long double* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackDoublePLongDouble(List *dataStructure, const volatile double* key, long double value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackDoublePLongDoubleP(List *dataStructure, const volatile double* key, const volatile long double* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackDoubleList(List *dataStructure, double key, List value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddBackDoubleListP(List *dataStructure, double key, const volatile List* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddBackDoublePList(List *dataStructure, const volatile double* key, List value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackDoublePListP(List *dataStructure, const volatile double* key, const volatile List* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackDoubleQueue(List *dataStructure, double key, Queue value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddBackDoubleQueueP(List *dataStructure, double key, const volatile Queue* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackDoublePQueue(List *dataStructure, const volatile double* key, Queue value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackDoublePQueueP(List *dataStructure, const volatile double* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackDoubleStack(List *dataStructure, double key, Stack value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddBackDoubleStackP(List *dataStructure, double key, const volatile Stack* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackDoublePStack(List *dataStructure, const volatile double* key, Stack value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackDoublePStackP(List *dataStructure, const volatile double* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackDoubleRedBlackTree(List *dataStructure, double key, RedBlackTree value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackDoubleRedBlackTreeP(List *dataStructure, double key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackDoublePRedBlackTree(List *dataStructure, const volatile double* key, RedBlackTree value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackDoublePRedBlackTreeP(List *dataStructure, const volatile double* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackDoubleHashTable(List *dataStructure, double key, HashTable value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddBackDoubleHashTableP(List *dataStructure, double key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackDoublePHashTable(List *dataStructure, const volatile double* key, HashTable value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackDoublePHashTableP(List *dataStructure, const volatile double* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackDoubleVector(List *dataStructure, double key, Vector value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddBackDoubleVectorP(List *dataStructure, double key, const volatile Vector* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackDoublePVector(List *dataStructure, const volatile double* key, Vector value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackDoublePVectorP(List *dataStructure, const volatile double* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackDoubleString(List *dataStructure, double key, const volatile char* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddBackDoubleStringP(List *dataStructure, double key, const volatile char** value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackDoublePString(List *dataStructure, const volatile double* key, const volatile char* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackDoublePStringP(List *dataStructure, const volatile double* key, const volatile char** value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackDoubleBytes(List *dataStructure, double key, Bytes value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddBackDoubleBytesP(List *dataStructure, double key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackDoublePBytes(List *dataStructure, const volatile double* key, Bytes value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackDoublePBytesP(List *dataStructure, const volatile double* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackDoublePointer(List *dataStructure, double key, void* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddBackDoublePointerP(List *dataStructure, double key, const volatile void** value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackDoublePPointer(List *dataStructure, const volatile double* key, void* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackDoublePPointerP(List *dataStructure, const volatile double* key, const volatile void** value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackDoubleI8(List *dataStructure, double key, i8 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddBackDoublePI8(List *dataStructure, const volatile double* key, i8 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackDoubleU8(List *dataStructure, double key, u8 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddBackDoublePU8(List *dataStructure, const volatile double* key, u8 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddBackLongDoubleBool(List *dataStructure, long double key, bool value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddBackLongDoubleBoolP(List *dataStructure, long double key, const volatile bool* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackLongDoublePBool(List *dataStructure, const volatile long double* key, bool value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackLongDoublePBoolP(List *dataStructure, const volatile long double* key, const volatile bool* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackLongDoubleI16(List *dataStructure, long double key, i16 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddBackLongDoubleI16P(List *dataStructure, long double key, const volatile i16* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackLongDoublePI16(List *dataStructure, const volatile long double* key, i16 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackLongDoublePI16P(List *dataStructure, const volatile long double* key, const volatile i16* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackLongDoubleU16(List *dataStructure, long double key, u16 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddBackLongDoubleU16P(List *dataStructure, long double key, const volatile u16* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackLongDoublePU16(List *dataStructure, const volatile long double* key, u16 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackLongDoublePU16P(List *dataStructure, const volatile long double* key, const volatile u16* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackLongDoubleI32(List *dataStructure, long double key, i32 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddBackLongDoubleI32P(List *dataStructure, long double key, const volatile i32* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackLongDoublePI32(List *dataStructure, const volatile long double* key, i32 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackLongDoublePI32P(List *dataStructure, const volatile long double* key, const volatile i32* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackLongDoubleU32(List *dataStructure, long double key, u32 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddBackLongDoubleU32P(List *dataStructure, long double key, const volatile u32* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackLongDoublePU32(List *dataStructure, const volatile long double* key, u32 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackLongDoublePU32P(List *dataStructure, const volatile long double* key, const volatile u32* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackLongDoubleI64(List *dataStructure, long double key, i64 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddBackLongDoubleI64P(List *dataStructure, long double key, const volatile i64* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackLongDoublePI64(List *dataStructure, const volatile long double* key, i64 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackLongDoublePI64P(List *dataStructure, const volatile long double* key, const volatile i64* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackLongDoubleU64(List *dataStructure, long double key, u64 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddBackLongDoubleU64P(List *dataStructure, long double key, const volatile u64* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackLongDoublePU64(List *dataStructure, const volatile long double* key, u64 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackLongDoublePU64P(List *dataStructure, const volatile long double* key, const volatile u64* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackLongDoubleFloat(List *dataStructure, long double key, float value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddBackLongDoubleFloatP(List *dataStructure, long double key, const volatile float* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackLongDoublePFloat(List *dataStructure, const volatile long double* key, float value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackLongDoublePFloatP(List *dataStructure, const volatile long double* key, const volatile float* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackLongDoubleDouble(List *dataStructure, long double key, double value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddBackLongDoubleDoubleP(List *dataStructure, long double key, const volatile double* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackLongDoublePDouble(List *dataStructure, const volatile long double* key, double value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackLongDoublePDoubleP(List *dataStructure, const volatile long double* key, const volatile double* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackLongDoubleLongDouble(List *dataStructure, long double key, long double value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddBackLongDoubleLongDoubleP(List *dataStructure, long double key, const volatile long double* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackLongDoublePLongDouble(List *dataStructure, const volatile long double* key, long double value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackLongDoublePLongDoubleP(List *dataStructure, const volatile long double* key, const volatile long double* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackLongDoubleList(List *dataStructure, long double key, List value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddBackLongDoubleListP(List *dataStructure, long double key, const volatile List* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddBackLongDoublePList(List *dataStructure, const volatile long double* key, List value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackLongDoublePListP(List *dataStructure, const volatile long double* key, const volatile List* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackLongDoubleQueue(List *dataStructure, long double key, Queue value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddBackLongDoubleQueueP(List *dataStructure, long double key, const volatile Queue* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackLongDoublePQueue(List *dataStructure, const volatile long double* key, Queue value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackLongDoublePQueueP(List *dataStructure, const volatile long double* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackLongDoubleStack(List *dataStructure, long double key, Stack value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddBackLongDoubleStackP(List *dataStructure, long double key, const volatile Stack* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackLongDoublePStack(List *dataStructure, const volatile long double* key, Stack value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackLongDoublePStackP(List *dataStructure, const volatile long double* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackLongDoubleRedBlackTree(List *dataStructure, long double key, RedBlackTree value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackLongDoubleRedBlackTreeP(List *dataStructure, long double key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackLongDoublePRedBlackTree(List *dataStructure, const volatile long double* key, RedBlackTree value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackLongDoublePRedBlackTreeP(List *dataStructure, const volatile long double* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackLongDoubleHashTable(List *dataStructure, long double key, HashTable value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddBackLongDoubleHashTableP(List *dataStructure, long double key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackLongDoublePHashTable(List *dataStructure, const volatile long double* key, HashTable value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackLongDoublePHashTableP(List *dataStructure, const volatile long double* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackLongDoubleVector(List *dataStructure, long double key, Vector value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddBackLongDoubleVectorP(List *dataStructure, long double key, const volatile Vector* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackLongDoublePVector(List *dataStructure, const volatile long double* key, Vector value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackLongDoublePVectorP(List *dataStructure, const volatile long double* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackLongDoubleString(List *dataStructure, long double key, const volatile char* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddBackLongDoubleStringP(List *dataStructure, long double key, const volatile char** value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackLongDoublePString(List *dataStructure, const volatile long double* key, const volatile char* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackLongDoublePStringP(List *dataStructure, const volatile long double* key, const volatile char** value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackLongDoubleBytes(List *dataStructure, long double key, Bytes value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddBackLongDoubleBytesP(List *dataStructure, long double key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackLongDoublePBytes(List *dataStructure, const volatile long double* key, Bytes value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackLongDoublePBytesP(List *dataStructure, const volatile long double* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackLongDoublePointer(List *dataStructure, long double key, void* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddBackLongDoublePointerP(List *dataStructure, long double key, const volatile void** value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackLongDoublePPointer(List *dataStructure, const volatile long double* key, void* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackLongDoublePPointerP(List *dataStructure, const volatile long double* key, const volatile void** value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackLongDoubleI8(List *dataStructure, long double key, i8 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddBackLongDoublePI8(List *dataStructure, const volatile long double* key, i8 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackLongDoubleU8(List *dataStructure, long double key, u8 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddBackLongDoublePU8(List *dataStructure, const volatile long double* key, u8 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddBackListBool(List *dataStructure, List key, bool value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddBackListBoolP(List *dataStructure, List key, const volatile bool* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackListPBool(List *dataStructure, const volatile List* key, bool value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackListPBoolP(List *dataStructure, const volatile List* key, const volatile bool* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackListI16(List *dataStructure, List key, i16 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddBackListI16P(List *dataStructure, List key, const volatile i16* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackListPI16(List *dataStructure, const volatile List* key, i16 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackListPI16P(List *dataStructure, const volatile List* key, const volatile i16* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackListU16(List *dataStructure, List key, u16 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddBackListU16P(List *dataStructure, List key, const volatile u16* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackListPU16(List *dataStructure, const volatile List* key, u16 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackListPU16P(List *dataStructure, const volatile List* key, const volatile u16* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackListI32(List *dataStructure, List key, i32 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddBackListI32P(List *dataStructure, List key, const volatile i32* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackListPI32(List *dataStructure, const volatile List* key, i32 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackListPI32P(List *dataStructure, const volatile List* key, const volatile i32* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackListU32(List *dataStructure, List key, u32 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddBackListU32P(List *dataStructure, List key, const volatile u32* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackListPU32(List *dataStructure, const volatile List* key, u32 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackListPU32P(List *dataStructure, const volatile List* key, const volatile u32* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackListI64(List *dataStructure, List key, i64 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddBackListI64P(List *dataStructure, List key, const volatile i64* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackListPI64(List *dataStructure, const volatile List* key, i64 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackListPI64P(List *dataStructure, const volatile List* key, const volatile i64* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackListU64(List *dataStructure, List key, u64 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddBackListU64P(List *dataStructure, List key, const volatile u64* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackListPU64(List *dataStructure, const volatile List* key, u64 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackListPU64P(List *dataStructure, const volatile List* key, const volatile u64* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackListFloat(List *dataStructure, List key, float value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddBackListFloatP(List *dataStructure, List key, const volatile float* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackListPFloat(List *dataStructure, const volatile List* key, float value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackListPFloatP(List *dataStructure, const volatile List* key, const volatile float* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackListDouble(List *dataStructure, List key, double value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddBackListDoubleP(List *dataStructure, List key, const volatile double* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackListPDouble(List *dataStructure, const volatile List* key, double value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackListPDoubleP(List *dataStructure, const volatile List* key, const volatile double* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackListLongDouble(List *dataStructure, List key, long double value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddBackListLongDoubleP(List *dataStructure, List key, const volatile long double* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackListPLongDouble(List *dataStructure, const volatile List* key, long double value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackListPLongDoubleP(List *dataStructure, const volatile List* key, const volatile long double* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackListList(List *dataStructure, List key, List value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddBackListListP(List *dataStructure, List key, const volatile List* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddBackListPList(List *dataStructure, const volatile List* key, List value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackListPListP(List *dataStructure, const volatile List* key, const volatile List* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackListQueue(List *dataStructure, List key, Queue value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddBackListQueueP(List *dataStructure, List key, const volatile Queue* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackListPQueue(List *dataStructure, const volatile List* key, Queue value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackListPQueueP(List *dataStructure, const volatile List* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackListStack(List *dataStructure, List key, Stack value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddBackListStackP(List *dataStructure, List key, const volatile Stack* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackListPStack(List *dataStructure, const volatile List* key, Stack value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackListPStackP(List *dataStructure, const volatile List* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackListRedBlackTree(List *dataStructure, List key, RedBlackTree value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackListRedBlackTreeP(List *dataStructure, List key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackListPRedBlackTree(List *dataStructure, const volatile List* key, RedBlackTree value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackListPRedBlackTreeP(List *dataStructure, const volatile List* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackListHashTable(List *dataStructure, List key, HashTable value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddBackListHashTableP(List *dataStructure, List key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackListPHashTable(List *dataStructure, const volatile List* key, HashTable value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackListPHashTableP(List *dataStructure, const volatile List* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackListVector(List *dataStructure, List key, Vector value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddBackListVectorP(List *dataStructure, List key, const volatile Vector* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackListPVector(List *dataStructure, const volatile List* key, Vector value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackListPVectorP(List *dataStructure, const volatile List* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackListString(List *dataStructure, List key, const volatile char* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddBackListStringP(List *dataStructure, List key, const volatile char** value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackListPString(List *dataStructure, const volatile List* key, const volatile char* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackListPStringP(List *dataStructure, const volatile List* key, const volatile char** value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackListBytes(List *dataStructure, List key, Bytes value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddBackListBytesP(List *dataStructure, List key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackListPBytes(List *dataStructure, const volatile List* key, Bytes value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackListPBytesP(List *dataStructure, const volatile List* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackListPointer(List *dataStructure, List key, void* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddBackListPointerP(List *dataStructure, List key, const volatile void** value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackListPPointer(List *dataStructure, const volatile List* key, void* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackListPPointerP(List *dataStructure, const volatile List* key, const volatile void** value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackListI8(List *dataStructure, List key, i8 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddBackListPI8(List *dataStructure, const volatile List* key, i8 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackListU8(List *dataStructure, List key, u8 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddBackListPU8(List *dataStructure, const volatile List* key, u8 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddBackQueueBool(List *dataStructure, Queue key, bool value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddBackQueueBoolP(List *dataStructure, Queue key, const volatile bool* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackQueuePBool(List *dataStructure, const volatile Queue* key, bool value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackQueuePBoolP(List *dataStructure, const volatile Queue* key, const volatile bool* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackQueueI16(List *dataStructure, Queue key, i16 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddBackQueueI16P(List *dataStructure, Queue key, const volatile i16* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackQueuePI16(List *dataStructure, const volatile Queue* key, i16 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackQueuePI16P(List *dataStructure, const volatile Queue* key, const volatile i16* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackQueueU16(List *dataStructure, Queue key, u16 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddBackQueueU16P(List *dataStructure, Queue key, const volatile u16* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackQueuePU16(List *dataStructure, const volatile Queue* key, u16 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackQueuePU16P(List *dataStructure, const volatile Queue* key, const volatile u16* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackQueueI32(List *dataStructure, Queue key, i32 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddBackQueueI32P(List *dataStructure, Queue key, const volatile i32* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackQueuePI32(List *dataStructure, const volatile Queue* key, i32 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackQueuePI32P(List *dataStructure, const volatile Queue* key, const volatile i32* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackQueueU32(List *dataStructure, Queue key, u32 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddBackQueueU32P(List *dataStructure, Queue key, const volatile u32* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackQueuePU32(List *dataStructure, const volatile Queue* key, u32 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackQueuePU32P(List *dataStructure, const volatile Queue* key, const volatile u32* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackQueueI64(List *dataStructure, Queue key, i64 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddBackQueueI64P(List *dataStructure, Queue key, const volatile i64* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackQueuePI64(List *dataStructure, const volatile Queue* key, i64 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackQueuePI64P(List *dataStructure, const volatile Queue* key, const volatile i64* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackQueueU64(List *dataStructure, Queue key, u64 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddBackQueueU64P(List *dataStructure, Queue key, const volatile u64* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackQueuePU64(List *dataStructure, const volatile Queue* key, u64 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackQueuePU64P(List *dataStructure, const volatile Queue* key, const volatile u64* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackQueueFloat(List *dataStructure, Queue key, float value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddBackQueueFloatP(List *dataStructure, Queue key, const volatile float* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackQueuePFloat(List *dataStructure, const volatile Queue* key, float value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackQueuePFloatP(List *dataStructure, const volatile Queue* key, const volatile float* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackQueueDouble(List *dataStructure, Queue key, double value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddBackQueueDoubleP(List *dataStructure, Queue key, const volatile double* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackQueuePDouble(List *dataStructure, const volatile Queue* key, double value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackQueuePDoubleP(List *dataStructure, const volatile Queue* key, const volatile double* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackQueueLongDouble(List *dataStructure, Queue key, long double value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddBackQueueLongDoubleP(List *dataStructure, Queue key, const volatile long double* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackQueuePLongDouble(List *dataStructure, const volatile Queue* key, long double value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackQueuePLongDoubleP(List *dataStructure, const volatile Queue* key, const volatile long double* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackQueueList(List *dataStructure, Queue key, List value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddBackQueueListP(List *dataStructure, Queue key, const volatile List* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddBackQueuePList(List *dataStructure, const volatile Queue* key, List value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackQueuePListP(List *dataStructure, const volatile Queue* key, const volatile List* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackQueueQueue(List *dataStructure, Queue key, Queue value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddBackQueueQueueP(List *dataStructure, Queue key, const volatile Queue* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackQueuePQueue(List *dataStructure, const volatile Queue* key, Queue value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackQueuePQueueP(List *dataStructure, const volatile Queue* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackQueueStack(List *dataStructure, Queue key, Stack value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddBackQueueStackP(List *dataStructure, Queue key, const volatile Stack* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackQueuePStack(List *dataStructure, const volatile Queue* key, Stack value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackQueuePStackP(List *dataStructure, const volatile Queue* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackQueueRedBlackTree(List *dataStructure, Queue key, RedBlackTree value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackQueueRedBlackTreeP(List *dataStructure, Queue key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackQueuePRedBlackTree(List *dataStructure, const volatile Queue* key, RedBlackTree value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackQueuePRedBlackTreeP(List *dataStructure, const volatile Queue* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackQueueHashTable(List *dataStructure, Queue key, HashTable value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddBackQueueHashTableP(List *dataStructure, Queue key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackQueuePHashTable(List *dataStructure, const volatile Queue* key, HashTable value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackQueuePHashTableP(List *dataStructure, const volatile Queue* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackQueueVector(List *dataStructure, Queue key, Vector value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddBackQueueVectorP(List *dataStructure, Queue key, const volatile Vector* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackQueuePVector(List *dataStructure, const volatile Queue* key, Vector value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackQueuePVectorP(List *dataStructure, const volatile Queue* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackQueueString(List *dataStructure, Queue key, const volatile char* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddBackQueueStringP(List *dataStructure, Queue key, const volatile char** value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackQueuePString(List *dataStructure, const volatile Queue* key, const volatile char* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackQueuePStringP(List *dataStructure, const volatile Queue* key, const volatile char** value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackQueueBytes(List *dataStructure, Queue key, Bytes value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddBackQueueBytesP(List *dataStructure, Queue key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackQueuePBytes(List *dataStructure, const volatile Queue* key, Bytes value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackQueuePBytesP(List *dataStructure, const volatile Queue* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackQueuePointer(List *dataStructure, Queue key, void* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddBackQueuePointerP(List *dataStructure, Queue key, const volatile void** value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackQueuePPointer(List *dataStructure, const volatile Queue* key, void* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackQueuePPointerP(List *dataStructure, const volatile Queue* key, const volatile void** value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackQueueI8(List *dataStructure, Queue key, i8 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddBackQueuePI8(List *dataStructure, const volatile Queue* key, i8 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackQueueU8(List *dataStructure, Queue key, u8 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddBackQueuePU8(List *dataStructure, const volatile Queue* key, u8 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddBackStackBool(List *dataStructure, Stack key, bool value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddBackStackBoolP(List *dataStructure, Stack key, const volatile bool* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackStackPBool(List *dataStructure, const volatile Stack* key, bool value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackStackPBoolP(List *dataStructure, const volatile Stack* key, const volatile bool* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackStackI16(List *dataStructure, Stack key, i16 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddBackStackI16P(List *dataStructure, Stack key, const volatile i16* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackStackPI16(List *dataStructure, const volatile Stack* key, i16 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackStackPI16P(List *dataStructure, const volatile Stack* key, const volatile i16* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackStackU16(List *dataStructure, Stack key, u16 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddBackStackU16P(List *dataStructure, Stack key, const volatile u16* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackStackPU16(List *dataStructure, const volatile Stack* key, u16 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackStackPU16P(List *dataStructure, const volatile Stack* key, const volatile u16* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackStackI32(List *dataStructure, Stack key, i32 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddBackStackI32P(List *dataStructure, Stack key, const volatile i32* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackStackPI32(List *dataStructure, const volatile Stack* key, i32 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackStackPI32P(List *dataStructure, const volatile Stack* key, const volatile i32* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackStackU32(List *dataStructure, Stack key, u32 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddBackStackU32P(List *dataStructure, Stack key, const volatile u32* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackStackPU32(List *dataStructure, const volatile Stack* key, u32 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackStackPU32P(List *dataStructure, const volatile Stack* key, const volatile u32* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackStackI64(List *dataStructure, Stack key, i64 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddBackStackI64P(List *dataStructure, Stack key, const volatile i64* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackStackPI64(List *dataStructure, const volatile Stack* key, i64 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackStackPI64P(List *dataStructure, const volatile Stack* key, const volatile i64* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackStackU64(List *dataStructure, Stack key, u64 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddBackStackU64P(List *dataStructure, Stack key, const volatile u64* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackStackPU64(List *dataStructure, const volatile Stack* key, u64 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackStackPU64P(List *dataStructure, const volatile Stack* key, const volatile u64* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackStackFloat(List *dataStructure, Stack key, float value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddBackStackFloatP(List *dataStructure, Stack key, const volatile float* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackStackPFloat(List *dataStructure, const volatile Stack* key, float value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackStackPFloatP(List *dataStructure, const volatile Stack* key, const volatile float* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackStackDouble(List *dataStructure, Stack key, double value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddBackStackDoubleP(List *dataStructure, Stack key, const volatile double* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackStackPDouble(List *dataStructure, const volatile Stack* key, double value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackStackPDoubleP(List *dataStructure, const volatile Stack* key, const volatile double* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackStackLongDouble(List *dataStructure, Stack key, long double value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddBackStackLongDoubleP(List *dataStructure, Stack key, const volatile long double* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackStackPLongDouble(List *dataStructure, const volatile Stack* key, long double value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackStackPLongDoubleP(List *dataStructure, const volatile Stack* key, const volatile long double* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackStackList(List *dataStructure, Stack key, List value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddBackStackListP(List *dataStructure, Stack key, const volatile List* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddBackStackPList(List *dataStructure, const volatile Stack* key, List value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackStackPListP(List *dataStructure, const volatile Stack* key, const volatile List* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackStackQueue(List *dataStructure, Stack key, Queue value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddBackStackQueueP(List *dataStructure, Stack key, const volatile Queue* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackStackPQueue(List *dataStructure, const volatile Stack* key, Queue value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackStackPQueueP(List *dataStructure, const volatile Stack* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackStackStack(List *dataStructure, Stack key, Stack value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddBackStackStackP(List *dataStructure, Stack key, const volatile Stack* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackStackPStack(List *dataStructure, const volatile Stack* key, Stack value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackStackPStackP(List *dataStructure, const volatile Stack* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackStackRedBlackTree(List *dataStructure, Stack key, RedBlackTree value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackStackRedBlackTreeP(List *dataStructure, Stack key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackStackPRedBlackTree(List *dataStructure, const volatile Stack* key, RedBlackTree value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackStackPRedBlackTreeP(List *dataStructure, const volatile Stack* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackStackHashTable(List *dataStructure, Stack key, HashTable value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddBackStackHashTableP(List *dataStructure, Stack key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackStackPHashTable(List *dataStructure, const volatile Stack* key, HashTable value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackStackPHashTableP(List *dataStructure, const volatile Stack* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackStackVector(List *dataStructure, Stack key, Vector value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddBackStackVectorP(List *dataStructure, Stack key, const volatile Vector* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackStackPVector(List *dataStructure, const volatile Stack* key, Vector value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackStackPVectorP(List *dataStructure, const volatile Stack* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackStackString(List *dataStructure, Stack key, const volatile char* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddBackStackStringP(List *dataStructure, Stack key, const volatile char** value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackStackPString(List *dataStructure, const volatile Stack* key, const volatile char* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackStackPStringP(List *dataStructure, const volatile Stack* key, const volatile char** value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackStackBytes(List *dataStructure, Stack key, Bytes value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddBackStackBytesP(List *dataStructure, Stack key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackStackPBytes(List *dataStructure, const volatile Stack* key, Bytes value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackStackPBytesP(List *dataStructure, const volatile Stack* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackStackPointer(List *dataStructure, Stack key, void* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddBackStackPointerP(List *dataStructure, Stack key, const volatile void** value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackStackPPointer(List *dataStructure, const volatile Stack* key, void* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackStackPPointerP(List *dataStructure, const volatile Stack* key, const volatile void** value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackStackI8(List *dataStructure, Stack key, i8 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddBackStackPI8(List *dataStructure, const volatile Stack* key, i8 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackStackU8(List *dataStructure, Stack key, u8 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddBackStackPU8(List *dataStructure, const volatile Stack* key, u8 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddBackRedBlackTreeBool(List *dataStructure, RedBlackTree key, bool value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddBackRedBlackTreeBoolP(List *dataStructure, RedBlackTree key, const volatile bool* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackRedBlackTreePBool(List *dataStructure, const volatile RedBlackTree* key, bool value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackRedBlackTreePBoolP(List *dataStructure, const volatile RedBlackTree* key, const volatile bool* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackRedBlackTreeI16(List *dataStructure, RedBlackTree key, i16 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddBackRedBlackTreeI16P(List *dataStructure, RedBlackTree key, const volatile i16* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackRedBlackTreePI16(List *dataStructure, const volatile RedBlackTree* key, i16 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackRedBlackTreePI16P(List *dataStructure, const volatile RedBlackTree* key, const volatile i16* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackRedBlackTreeU16(List *dataStructure, RedBlackTree key, u16 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddBackRedBlackTreeU16P(List *dataStructure, RedBlackTree key, const volatile u16* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackRedBlackTreePU16(List *dataStructure, const volatile RedBlackTree* key, u16 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackRedBlackTreePU16P(List *dataStructure, const volatile RedBlackTree* key, const volatile u16* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackRedBlackTreeI32(List *dataStructure, RedBlackTree key, i32 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddBackRedBlackTreeI32P(List *dataStructure, RedBlackTree key, const volatile i32* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackRedBlackTreePI32(List *dataStructure, const volatile RedBlackTree* key, i32 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackRedBlackTreePI32P(List *dataStructure, const volatile RedBlackTree* key, const volatile i32* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackRedBlackTreeU32(List *dataStructure, RedBlackTree key, u32 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddBackRedBlackTreeU32P(List *dataStructure, RedBlackTree key, const volatile u32* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackRedBlackTreePU32(List *dataStructure, const volatile RedBlackTree* key, u32 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackRedBlackTreePU32P(List *dataStructure, const volatile RedBlackTree* key, const volatile u32* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackRedBlackTreeI64(List *dataStructure, RedBlackTree key, i64 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddBackRedBlackTreeI64P(List *dataStructure, RedBlackTree key, const volatile i64* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackRedBlackTreePI64(List *dataStructure, const volatile RedBlackTree* key, i64 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackRedBlackTreePI64P(List *dataStructure, const volatile RedBlackTree* key, const volatile i64* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackRedBlackTreeU64(List *dataStructure, RedBlackTree key, u64 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddBackRedBlackTreeU64P(List *dataStructure, RedBlackTree key, const volatile u64* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackRedBlackTreePU64(List *dataStructure, const volatile RedBlackTree* key, u64 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackRedBlackTreePU64P(List *dataStructure, const volatile RedBlackTree* key, const volatile u64* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackRedBlackTreeFloat(List *dataStructure, RedBlackTree key, float value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddBackRedBlackTreeFloatP(List *dataStructure, RedBlackTree key, const volatile float* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackRedBlackTreePFloat(List *dataStructure, const volatile RedBlackTree* key, float value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackRedBlackTreePFloatP(List *dataStructure, const volatile RedBlackTree* key, const volatile float* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackRedBlackTreeDouble(List *dataStructure, RedBlackTree key, double value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddBackRedBlackTreeDoubleP(List *dataStructure, RedBlackTree key, const volatile double* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackRedBlackTreePDouble(List *dataStructure, const volatile RedBlackTree* key, double value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackRedBlackTreePDoubleP(List *dataStructure, const volatile RedBlackTree* key, const volatile double* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackRedBlackTreeLongDouble(List *dataStructure, RedBlackTree key, long double value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddBackRedBlackTreeLongDoubleP(List *dataStructure, RedBlackTree key, const volatile long double* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackRedBlackTreePLongDouble(List *dataStructure, const volatile RedBlackTree* key, long double value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackRedBlackTreePLongDoubleP(List *dataStructure, const volatile RedBlackTree* key, const volatile long double* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackRedBlackTreeList(List *dataStructure, RedBlackTree key, List value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddBackRedBlackTreeListP(List *dataStructure, RedBlackTree key, const volatile List* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddBackRedBlackTreePList(List *dataStructure, const volatile RedBlackTree* key, List value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackRedBlackTreePListP(List *dataStructure, const volatile RedBlackTree* key, const volatile List* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackRedBlackTreeQueue(List *dataStructure, RedBlackTree key, Queue value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddBackRedBlackTreeQueueP(List *dataStructure, RedBlackTree key, const volatile Queue* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackRedBlackTreePQueue(List *dataStructure, const volatile RedBlackTree* key, Queue value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackRedBlackTreePQueueP(List *dataStructure, const volatile RedBlackTree* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackRedBlackTreeStack(List *dataStructure, RedBlackTree key, Stack value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddBackRedBlackTreeStackP(List *dataStructure, RedBlackTree key, const volatile Stack* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackRedBlackTreePStack(List *dataStructure, const volatile RedBlackTree* key, Stack value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackRedBlackTreePStackP(List *dataStructure, const volatile RedBlackTree* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackRedBlackTreeRedBlackTree(List *dataStructure, RedBlackTree key, RedBlackTree value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackRedBlackTreeRedBlackTreeP(List *dataStructure, RedBlackTree key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackRedBlackTreePRedBlackTree(List *dataStructure, const volatile RedBlackTree* key, RedBlackTree value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackRedBlackTreePRedBlackTreeP(List *dataStructure, const volatile RedBlackTree* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackRedBlackTreeHashTable(List *dataStructure, RedBlackTree key, HashTable value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddBackRedBlackTreeHashTableP(List *dataStructure, RedBlackTree key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackRedBlackTreePHashTable(List *dataStructure, const volatile RedBlackTree* key, HashTable value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackRedBlackTreePHashTableP(List *dataStructure, const volatile RedBlackTree* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackRedBlackTreeVector(List *dataStructure, RedBlackTree key, Vector value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddBackRedBlackTreeVectorP(List *dataStructure, RedBlackTree key, const volatile Vector* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackRedBlackTreePVector(List *dataStructure, const volatile RedBlackTree* key, Vector value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackRedBlackTreePVectorP(List *dataStructure, const volatile RedBlackTree* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackRedBlackTreeString(List *dataStructure, RedBlackTree key, const volatile char* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddBackRedBlackTreeStringP(List *dataStructure, RedBlackTree key, const volatile char** value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackRedBlackTreePString(List *dataStructure, const volatile RedBlackTree* key, const volatile char* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackRedBlackTreePStringP(List *dataStructure, const volatile RedBlackTree* key, const volatile char** value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackRedBlackTreeBytes(List *dataStructure, RedBlackTree key, Bytes value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddBackRedBlackTreeBytesP(List *dataStructure, RedBlackTree key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackRedBlackTreePBytes(List *dataStructure, const volatile RedBlackTree* key, Bytes value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackRedBlackTreePBytesP(List *dataStructure, const volatile RedBlackTree* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackRedBlackTreePointer(List *dataStructure, RedBlackTree key, void* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddBackRedBlackTreePointerP(List *dataStructure, RedBlackTree key, const volatile void** value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackRedBlackTreePPointer(List *dataStructure, const volatile RedBlackTree* key, void* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackRedBlackTreePPointerP(List *dataStructure, const volatile RedBlackTree* key, const volatile void** value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackRedBlackTreeI8(List *dataStructure, RedBlackTree key, i8 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddBackRedBlackTreePI8(List *dataStructure, const volatile RedBlackTree* key, i8 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackRedBlackTreeU8(List *dataStructure, RedBlackTree key, u8 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddBackRedBlackTreePU8(List *dataStructure, const volatile RedBlackTree* key, u8 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddBackHashTableBool(List *dataStructure, HashTable key, bool value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddBackHashTableBoolP(List *dataStructure, HashTable key, const volatile bool* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackHashTablePBool(List *dataStructure, const volatile HashTable* key, bool value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackHashTablePBoolP(List *dataStructure, const volatile HashTable* key, const volatile bool* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackHashTableI16(List *dataStructure, HashTable key, i16 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddBackHashTableI16P(List *dataStructure, HashTable key, const volatile i16* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackHashTablePI16(List *dataStructure, const volatile HashTable* key, i16 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackHashTablePI16P(List *dataStructure, const volatile HashTable* key, const volatile i16* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackHashTableU16(List *dataStructure, HashTable key, u16 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddBackHashTableU16P(List *dataStructure, HashTable key, const volatile u16* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackHashTablePU16(List *dataStructure, const volatile HashTable* key, u16 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackHashTablePU16P(List *dataStructure, const volatile HashTable* key, const volatile u16* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackHashTableI32(List *dataStructure, HashTable key, i32 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddBackHashTableI32P(List *dataStructure, HashTable key, const volatile i32* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackHashTablePI32(List *dataStructure, const volatile HashTable* key, i32 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackHashTablePI32P(List *dataStructure, const volatile HashTable* key, const volatile i32* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackHashTableU32(List *dataStructure, HashTable key, u32 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddBackHashTableU32P(List *dataStructure, HashTable key, const volatile u32* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackHashTablePU32(List *dataStructure, const volatile HashTable* key, u32 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackHashTablePU32P(List *dataStructure, const volatile HashTable* key, const volatile u32* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackHashTableI64(List *dataStructure, HashTable key, i64 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddBackHashTableI64P(List *dataStructure, HashTable key, const volatile i64* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackHashTablePI64(List *dataStructure, const volatile HashTable* key, i64 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackHashTablePI64P(List *dataStructure, const volatile HashTable* key, const volatile i64* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackHashTableU64(List *dataStructure, HashTable key, u64 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddBackHashTableU64P(List *dataStructure, HashTable key, const volatile u64* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackHashTablePU64(List *dataStructure, const volatile HashTable* key, u64 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackHashTablePU64P(List *dataStructure, const volatile HashTable* key, const volatile u64* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackHashTableFloat(List *dataStructure, HashTable key, float value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddBackHashTableFloatP(List *dataStructure, HashTable key, const volatile float* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackHashTablePFloat(List *dataStructure, const volatile HashTable* key, float value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackHashTablePFloatP(List *dataStructure, const volatile HashTable* key, const volatile float* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackHashTableDouble(List *dataStructure, HashTable key, double value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddBackHashTableDoubleP(List *dataStructure, HashTable key, const volatile double* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackHashTablePDouble(List *dataStructure, const volatile HashTable* key, double value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackHashTablePDoubleP(List *dataStructure, const volatile HashTable* key, const volatile double* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackHashTableLongDouble(List *dataStructure, HashTable key, long double value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddBackHashTableLongDoubleP(List *dataStructure, HashTable key, const volatile long double* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackHashTablePLongDouble(List *dataStructure, const volatile HashTable* key, long double value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackHashTablePLongDoubleP(List *dataStructure, const volatile HashTable* key, const volatile long double* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackHashTableList(List *dataStructure, HashTable key, List value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddBackHashTableListP(List *dataStructure, HashTable key, const volatile List* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddBackHashTablePList(List *dataStructure, const volatile HashTable* key, List value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackHashTablePListP(List *dataStructure, const volatile HashTable* key, const volatile List* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackHashTableQueue(List *dataStructure, HashTable key, Queue value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddBackHashTableQueueP(List *dataStructure, HashTable key, const volatile Queue* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackHashTablePQueue(List *dataStructure, const volatile HashTable* key, Queue value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackHashTablePQueueP(List *dataStructure, const volatile HashTable* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackHashTableStack(List *dataStructure, HashTable key, Stack value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddBackHashTableStackP(List *dataStructure, HashTable key, const volatile Stack* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackHashTablePStack(List *dataStructure, const volatile HashTable* key, Stack value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackHashTablePStackP(List *dataStructure, const volatile HashTable* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackHashTableRedBlackTree(List *dataStructure, HashTable key, RedBlackTree value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackHashTableRedBlackTreeP(List *dataStructure, HashTable key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackHashTablePRedBlackTree(List *dataStructure, const volatile HashTable* key, RedBlackTree value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackHashTablePRedBlackTreeP(List *dataStructure, const volatile HashTable* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackHashTableHashTable(List *dataStructure, HashTable key, HashTable value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddBackHashTableHashTableP(List *dataStructure, HashTable key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackHashTablePHashTable(List *dataStructure, const volatile HashTable* key, HashTable value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackHashTablePHashTableP(List *dataStructure, const volatile HashTable* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackHashTableVector(List *dataStructure, HashTable key, Vector value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddBackHashTableVectorP(List *dataStructure, HashTable key, const volatile Vector* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackHashTablePVector(List *dataStructure, const volatile HashTable* key, Vector value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackHashTablePVectorP(List *dataStructure, const volatile HashTable* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackHashTableString(List *dataStructure, HashTable key, const volatile char* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddBackHashTableStringP(List *dataStructure, HashTable key, const volatile char** value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackHashTablePString(List *dataStructure, const volatile HashTable* key, const volatile char* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackHashTablePStringP(List *dataStructure, const volatile HashTable* key, const volatile char** value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackHashTableBytes(List *dataStructure, HashTable key, Bytes value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddBackHashTableBytesP(List *dataStructure, HashTable key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackHashTablePBytes(List *dataStructure, const volatile HashTable* key, Bytes value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackHashTablePBytesP(List *dataStructure, const volatile HashTable* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackHashTablePointer(List *dataStructure, HashTable key, void* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddBackHashTablePointerP(List *dataStructure, HashTable key, const volatile void** value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackHashTablePPointer(List *dataStructure, const volatile HashTable* key, void* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackHashTablePPointerP(List *dataStructure, const volatile HashTable* key, const volatile void** value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackHashTableI8(List *dataStructure, HashTable key, i8 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddBackHashTablePI8(List *dataStructure, const volatile HashTable* key, i8 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackHashTableU8(List *dataStructure, HashTable key, u8 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddBackHashTablePU8(List *dataStructure, const volatile HashTable* key, u8 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddBackVectorBool(List *dataStructure, Vector key, bool value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddBackVectorBoolP(List *dataStructure, Vector key, const volatile bool* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackVectorPBool(List *dataStructure, const volatile Vector* key, bool value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackVectorPBoolP(List *dataStructure, const volatile Vector* key, const volatile bool* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackVectorI16(List *dataStructure, Vector key, i16 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddBackVectorI16P(List *dataStructure, Vector key, const volatile i16* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackVectorPI16(List *dataStructure, const volatile Vector* key, i16 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackVectorPI16P(List *dataStructure, const volatile Vector* key, const volatile i16* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackVectorU16(List *dataStructure, Vector key, u16 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddBackVectorU16P(List *dataStructure, Vector key, const volatile u16* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackVectorPU16(List *dataStructure, const volatile Vector* key, u16 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackVectorPU16P(List *dataStructure, const volatile Vector* key, const volatile u16* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackVectorI32(List *dataStructure, Vector key, i32 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddBackVectorI32P(List *dataStructure, Vector key, const volatile i32* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackVectorPI32(List *dataStructure, const volatile Vector* key, i32 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackVectorPI32P(List *dataStructure, const volatile Vector* key, const volatile i32* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackVectorU32(List *dataStructure, Vector key, u32 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddBackVectorU32P(List *dataStructure, Vector key, const volatile u32* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackVectorPU32(List *dataStructure, const volatile Vector* key, u32 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackVectorPU32P(List *dataStructure, const volatile Vector* key, const volatile u32* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackVectorI64(List *dataStructure, Vector key, i64 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddBackVectorI64P(List *dataStructure, Vector key, const volatile i64* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackVectorPI64(List *dataStructure, const volatile Vector* key, i64 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackVectorPI64P(List *dataStructure, const volatile Vector* key, const volatile i64* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackVectorU64(List *dataStructure, Vector key, u64 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddBackVectorU64P(List *dataStructure, Vector key, const volatile u64* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackVectorPU64(List *dataStructure, const volatile Vector* key, u64 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackVectorPU64P(List *dataStructure, const volatile Vector* key, const volatile u64* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackVectorFloat(List *dataStructure, Vector key, float value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddBackVectorFloatP(List *dataStructure, Vector key, const volatile float* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackVectorPFloat(List *dataStructure, const volatile Vector* key, float value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackVectorPFloatP(List *dataStructure, const volatile Vector* key, const volatile float* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackVectorDouble(List *dataStructure, Vector key, double value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddBackVectorDoubleP(List *dataStructure, Vector key, const volatile double* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackVectorPDouble(List *dataStructure, const volatile Vector* key, double value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackVectorPDoubleP(List *dataStructure, const volatile Vector* key, const volatile double* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackVectorLongDouble(List *dataStructure, Vector key, long double value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddBackVectorLongDoubleP(List *dataStructure, Vector key, const volatile long double* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackVectorPLongDouble(List *dataStructure, const volatile Vector* key, long double value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackVectorPLongDoubleP(List *dataStructure, const volatile Vector* key, const volatile long double* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackVectorList(List *dataStructure, Vector key, List value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddBackVectorListP(List *dataStructure, Vector key, const volatile List* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddBackVectorPList(List *dataStructure, const volatile Vector* key, List value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackVectorPListP(List *dataStructure, const volatile Vector* key, const volatile List* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackVectorQueue(List *dataStructure, Vector key, Queue value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddBackVectorQueueP(List *dataStructure, Vector key, const volatile Queue* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackVectorPQueue(List *dataStructure, const volatile Vector* key, Queue value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackVectorPQueueP(List *dataStructure, const volatile Vector* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackVectorStack(List *dataStructure, Vector key, Stack value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddBackVectorStackP(List *dataStructure, Vector key, const volatile Stack* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackVectorPStack(List *dataStructure, const volatile Vector* key, Stack value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackVectorPStackP(List *dataStructure, const volatile Vector* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackVectorRedBlackTree(List *dataStructure, Vector key, RedBlackTree value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackVectorRedBlackTreeP(List *dataStructure, Vector key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackVectorPRedBlackTree(List *dataStructure, const volatile Vector* key, RedBlackTree value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackVectorPRedBlackTreeP(List *dataStructure, const volatile Vector* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackVectorHashTable(List *dataStructure, Vector key, HashTable value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddBackVectorHashTableP(List *dataStructure, Vector key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackVectorPHashTable(List *dataStructure, const volatile Vector* key, HashTable value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackVectorPHashTableP(List *dataStructure, const volatile Vector* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackVectorVector(List *dataStructure, Vector key, Vector value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddBackVectorVectorP(List *dataStructure, Vector key, const volatile Vector* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackVectorPVector(List *dataStructure, const volatile Vector* key, Vector value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackVectorPVectorP(List *dataStructure, const volatile Vector* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackVectorString(List *dataStructure, Vector key, const volatile char* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddBackVectorStringP(List *dataStructure, Vector key, const volatile char** value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackVectorPString(List *dataStructure, const volatile Vector* key, const volatile char* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackVectorPStringP(List *dataStructure, const volatile Vector* key, const volatile char** value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackVectorBytes(List *dataStructure, Vector key, Bytes value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddBackVectorBytesP(List *dataStructure, Vector key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackVectorPBytes(List *dataStructure, const volatile Vector* key, Bytes value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackVectorPBytesP(List *dataStructure, const volatile Vector* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackVectorPointer(List *dataStructure, Vector key, void* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddBackVectorPointerP(List *dataStructure, Vector key, const volatile void** value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackVectorPPointer(List *dataStructure, const volatile Vector* key, void* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackVectorPPointerP(List *dataStructure, const volatile Vector* key, const volatile void** value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackVectorI8(List *dataStructure, Vector key, i8 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddBackVectorPI8(List *dataStructure, const volatile Vector* key, i8 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackVectorU8(List *dataStructure, Vector key, u8 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddBackVectorPU8(List *dataStructure, const volatile Vector* key, u8 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}

static inline ListNode* listAddBackStringBool(List *dataStructure, const volatile char* key, bool value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackStringBoolP(List *dataStructure, const volatile char* key, const volatile bool* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackStringPBool(List *dataStructure, const volatile char** key, bool value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeBool);
}
static inline ListNode* listAddBackStringPBoolP(List *dataStructure, const volatile char** key, const volatile bool* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackStringI16(List *dataStructure, const volatile char* key, i16 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackStringI16P(List *dataStructure, const volatile char* key, const volatile i16* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackStringPI16(List *dataStructure, const volatile char** key, i16 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeI16);
}
static inline ListNode* listAddBackStringPI16P(List *dataStructure, const volatile char** key, const volatile i16* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackStringU16(List *dataStructure, const volatile char* key, u16 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackStringU16P(List *dataStructure, const volatile char* key, const volatile u16* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackStringPU16(List *dataStructure, const volatile char** key, u16 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeU16);
}
static inline ListNode* listAddBackStringPU16P(List *dataStructure, const volatile char** key, const volatile u16* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackStringI32(List *dataStructure, const volatile char* key, i32 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackStringI32P(List *dataStructure, const volatile char* key, const volatile i32* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackStringPI32(List *dataStructure, const volatile char** key, i32 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeI32);
}
static inline ListNode* listAddBackStringPI32P(List *dataStructure, const volatile char** key, const volatile i32* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackStringU32(List *dataStructure, const volatile char* key, u32 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackStringU32P(List *dataStructure, const volatile char* key, const volatile u32* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackStringPU32(List *dataStructure, const volatile char** key, u32 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeU32);
}
static inline ListNode* listAddBackStringPU32P(List *dataStructure, const volatile char** key, const volatile u32* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackStringI64(List *dataStructure, const volatile char* key, i64 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackStringI64P(List *dataStructure, const volatile char* key, const volatile i64* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackStringPI64(List *dataStructure, const volatile char** key, i64 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeI64);
}
static inline ListNode* listAddBackStringPI64P(List *dataStructure, const volatile char** key, const volatile i64* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackStringU64(List *dataStructure, const volatile char* key, u64 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackStringU64P(List *dataStructure, const volatile char* key, const volatile u64* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackStringPU64(List *dataStructure, const volatile char** key, u64 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeU64);
}
static inline ListNode* listAddBackStringPU64P(List *dataStructure, const volatile char** key, const volatile u64* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackStringFloat(List *dataStructure, const volatile char* key, float value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackStringFloatP(List *dataStructure, const volatile char* key, const volatile float* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackStringPFloat(List *dataStructure, const volatile char** key, float value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeFloat);
}
static inline ListNode* listAddBackStringPFloatP(List *dataStructure, const volatile char** key, const volatile float* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackStringDouble(List *dataStructure, const volatile char* key, double value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackStringDoubleP(List *dataStructure, const volatile char* key, const volatile double* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackStringPDouble(List *dataStructure, const volatile char** key, double value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeDouble);
}
static inline ListNode* listAddBackStringPDoubleP(List *dataStructure, const volatile char** key, const volatile double* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackStringLongDouble(List *dataStructure, const volatile char* key, long double value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackStringLongDoubleP(List *dataStructure, const volatile char* key, const volatile long double* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackStringPLongDouble(List *dataStructure, const volatile char** key, long double value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeLongDouble);
}
static inline ListNode* listAddBackStringPLongDoubleP(List *dataStructure, const volatile char** key, const volatile long double* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackStringList(List *dataStructure, const volatile char* key, List value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackStringListP(List *dataStructure, const volatile char* key, const volatile List* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackStringPList(List *dataStructure, const volatile char** key, List value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeList);
}
static inline ListNode* listAddBackStringPListP(List *dataStructure, const volatile char** key, const volatile List* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeListNoCopy);
}
static inline ListNode* listAddBackStringQueue(List *dataStructure, const volatile char* key, Queue value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackStringQueueP(List *dataStructure, const volatile char* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackStringPQueue(List *dataStructure, const volatile char** key, Queue value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeQueue);
}
static inline ListNode* listAddBackStringPQueueP(List *dataStructure, const volatile char** key, const volatile Queue* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackStringStack(List *dataStructure, const volatile char* key, Stack value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackStringStackP(List *dataStructure, const volatile char* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackStringPStack(List *dataStructure, const volatile char** key, Stack value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeStack);
}
static inline ListNode* listAddBackStringPStackP(List *dataStructure, const volatile char** key, const volatile Stack* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackStringRedBlackTree(List *dataStructure, const volatile char* key, RedBlackTree value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackStringRedBlackTreeP(List *dataStructure, const volatile char* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackStringPRedBlackTree(List *dataStructure, const volatile char** key, RedBlackTree value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackStringPRedBlackTreeP(List *dataStructure, const volatile char** key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackStringHashTable(List *dataStructure, const volatile char* key, HashTable value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackStringHashTableP(List *dataStructure, const volatile char* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackStringPHashTable(List *dataStructure, const volatile char** key, HashTable value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeHashTable);
}
static inline ListNode* listAddBackStringPHashTableP(List *dataStructure, const volatile char** key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackStringVector(List *dataStructure, const volatile char* key, Vector value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackStringVectorP(List *dataStructure, const volatile char* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackStringPVector(List *dataStructure, const volatile char** key, Vector value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeVector);
}
static inline ListNode* listAddBackStringPVectorP(List *dataStructure, const volatile char** key, const volatile Vector* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackStringString(List *dataStructure, const volatile char* key, const volatile char* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackStringStringP(List *dataStructure, const volatile char* key, const volatile char** value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackStringPString(List *dataStructure, const volatile char** key, const volatile char* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeString);
}
static inline ListNode* listAddBackStringPStringP(List *dataStructure, const volatile char** key, const volatile char** value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackStringBytes(List *dataStructure, const volatile char* key, Bytes value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackStringBytesP(List *dataStructure, const volatile char* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackStringPBytes(List *dataStructure, const volatile char** key, Bytes value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeBytes);
}
static inline ListNode* listAddBackStringPBytesP(List *dataStructure, const volatile char** key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackStringPointer(List *dataStructure, const volatile char* key, void* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackStringPointerP(List *dataStructure, const volatile char* key, const volatile void** value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackStringPPointer(List *dataStructure, const volatile char** key, void* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typePointer);
}
static inline ListNode* listAddBackStringPPointerP(List *dataStructure, const volatile char** key, const volatile void** value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackStringI8(List *dataStructure, const volatile char* key, i8 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackStringPI8(List *dataStructure, const volatile char** key, i8 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeI8);
}
static inline ListNode* listAddBackStringU8(List *dataStructure, const volatile char* key, u8 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddBackStringPU8(List *dataStructure, const volatile char** key, u8 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeU8);
}

static inline ListNode* listAddBackBytesBool(List *dataStructure, Bytes key, bool value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackBytesBoolP(List *dataStructure, Bytes key, const volatile bool* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackBytesPBool(List *dataStructure, const volatile Bytes* key, bool value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeBool);
}
static inline ListNode* listAddBackBytesPBoolP(List *dataStructure, const volatile Bytes* key, const volatile bool* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackBytesI16(List *dataStructure, Bytes key, i16 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackBytesI16P(List *dataStructure, Bytes key, const volatile i16* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackBytesPI16(List *dataStructure, const volatile Bytes* key, i16 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeI16);
}
static inline ListNode* listAddBackBytesPI16P(List *dataStructure, const volatile Bytes* key, const volatile i16* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackBytesU16(List *dataStructure, Bytes key, u16 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackBytesU16P(List *dataStructure, Bytes key, const volatile u16* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackBytesPU16(List *dataStructure, const volatile Bytes* key, u16 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeU16);
}
static inline ListNode* listAddBackBytesPU16P(List *dataStructure, const volatile Bytes* key, const volatile u16* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackBytesI32(List *dataStructure, Bytes key, i32 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackBytesI32P(List *dataStructure, Bytes key, const volatile i32* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackBytesPI32(List *dataStructure, const volatile Bytes* key, i32 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeI32);
}
static inline ListNode* listAddBackBytesPI32P(List *dataStructure, const volatile Bytes* key, const volatile i32* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackBytesU32(List *dataStructure, Bytes key, u32 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackBytesU32P(List *dataStructure, Bytes key, const volatile u32* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackBytesPU32(List *dataStructure, const volatile Bytes* key, u32 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeU32);
}
static inline ListNode* listAddBackBytesPU32P(List *dataStructure, const volatile Bytes* key, const volatile u32* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackBytesI64(List *dataStructure, Bytes key, i64 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackBytesI64P(List *dataStructure, Bytes key, const volatile i64* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackBytesPI64(List *dataStructure, const volatile Bytes* key, i64 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeI64);
}
static inline ListNode* listAddBackBytesPI64P(List *dataStructure, const volatile Bytes* key, const volatile i64* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackBytesU64(List *dataStructure, Bytes key, u64 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackBytesU64P(List *dataStructure, Bytes key, const volatile u64* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackBytesPU64(List *dataStructure, const volatile Bytes* key, u64 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeU64);
}
static inline ListNode* listAddBackBytesPU64P(List *dataStructure, const volatile Bytes* key, const volatile u64* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackBytesFloat(List *dataStructure, Bytes key, float value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackBytesFloatP(List *dataStructure, Bytes key, const volatile float* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackBytesPFloat(List *dataStructure, const volatile Bytes* key, float value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeFloat);
}
static inline ListNode* listAddBackBytesPFloatP(List *dataStructure, const volatile Bytes* key, const volatile float* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackBytesDouble(List *dataStructure, Bytes key, double value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackBytesDoubleP(List *dataStructure, Bytes key, const volatile double* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackBytesPDouble(List *dataStructure, const volatile Bytes* key, double value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeDouble);
}
static inline ListNode* listAddBackBytesPDoubleP(List *dataStructure, const volatile Bytes* key, const volatile double* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackBytesLongDouble(List *dataStructure, Bytes key, long double value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackBytesLongDoubleP(List *dataStructure, Bytes key, const volatile long double* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackBytesPLongDouble(List *dataStructure, const volatile Bytes* key, long double value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeLongDouble);
}
static inline ListNode* listAddBackBytesPLongDoubleP(List *dataStructure, const volatile Bytes* key, const volatile long double* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackBytesList(List *dataStructure, Bytes key, List value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackBytesListP(List *dataStructure, Bytes key, const volatile List* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackBytesPList(List *dataStructure, const volatile Bytes* key, List value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeList);
}
static inline ListNode* listAddBackBytesPListP(List *dataStructure, const volatile Bytes* key, const volatile List* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeListNoCopy);
}
static inline ListNode* listAddBackBytesQueue(List *dataStructure, Bytes key, Queue value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackBytesQueueP(List *dataStructure, Bytes key, const volatile Queue* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackBytesPQueue(List *dataStructure, const volatile Bytes* key, Queue value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeQueue);
}
static inline ListNode* listAddBackBytesPQueueP(List *dataStructure, const volatile Bytes* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackBytesStack(List *dataStructure, Bytes key, Stack value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackBytesStackP(List *dataStructure, Bytes key, const volatile Stack* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackBytesPStack(List *dataStructure, const volatile Bytes* key, Stack value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeStack);
}
static inline ListNode* listAddBackBytesPStackP(List *dataStructure, const volatile Bytes* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackBytesRedBlackTree(List *dataStructure, Bytes key, RedBlackTree value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackBytesRedBlackTreeP(List *dataStructure, Bytes key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackBytesPRedBlackTree(List *dataStructure, const volatile Bytes* key, RedBlackTree value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackBytesPRedBlackTreeP(List *dataStructure, const volatile Bytes* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackBytesHashTable(List *dataStructure, Bytes key, HashTable value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackBytesHashTableP(List *dataStructure, Bytes key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackBytesPHashTable(List *dataStructure, const volatile Bytes* key, HashTable value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeHashTable);
}
static inline ListNode* listAddBackBytesPHashTableP(List *dataStructure, const volatile Bytes* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackBytesVector(List *dataStructure, Bytes key, Vector value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackBytesVectorP(List *dataStructure, Bytes key, const volatile Vector* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackBytesPVector(List *dataStructure, const volatile Bytes* key, Vector value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeVector);
}
static inline ListNode* listAddBackBytesPVectorP(List *dataStructure, const volatile Bytes* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackBytesString(List *dataStructure, Bytes key, const volatile char* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackBytesStringP(List *dataStructure, Bytes key, const volatile char** value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackBytesPString(List *dataStructure, const volatile Bytes* key, const volatile char* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeString);
}
static inline ListNode* listAddBackBytesPStringP(List *dataStructure, const volatile Bytes* key, const volatile char** value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackBytesBytes(List *dataStructure, Bytes key, Bytes value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackBytesBytesP(List *dataStructure, Bytes key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackBytesPBytes(List *dataStructure, const volatile Bytes* key, Bytes value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeBytes);
}
static inline ListNode* listAddBackBytesPBytesP(List *dataStructure, const volatile Bytes* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackBytesPointer(List *dataStructure, Bytes key, void* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackBytesPointerP(List *dataStructure, Bytes key, const volatile void** value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackBytesPPointer(List *dataStructure, const volatile Bytes* key, void* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typePointer);
}
static inline ListNode* listAddBackBytesPPointerP(List *dataStructure, const volatile Bytes* key, const volatile void** value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackBytesI8(List *dataStructure, Bytes key, i8 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackBytesPI8(List *dataStructure, const volatile Bytes* key, i8 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeI8);
}
static inline ListNode* listAddBackBytesU8(List *dataStructure, Bytes key, u8 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddBackBytesPU8(List *dataStructure, const volatile Bytes* key, u8 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeU8);
}

static inline ListNode* listAddBackPointerBool(List *dataStructure, void* key, bool value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddBackPointerBoolP(List *dataStructure, void* key, const volatile bool* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackPointerPBool(List *dataStructure, const volatile void** key, bool value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeBool);
}
static inline ListNode* listAddBackPointerPBoolP(List *dataStructure, const volatile void** key, const volatile bool* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackPointerI16(List *dataStructure, void* key, i16 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddBackPointerI16P(List *dataStructure, void* key, const volatile i16* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackPointerPI16(List *dataStructure, const volatile void** key, i16 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeI16);
}
static inline ListNode* listAddBackPointerPI16P(List *dataStructure, const volatile void** key, const volatile i16* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackPointerU16(List *dataStructure, void* key, u16 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddBackPointerU16P(List *dataStructure, void* key, const volatile u16* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackPointerPU16(List *dataStructure, const volatile void** key, u16 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeU16);
}
static inline ListNode* listAddBackPointerPU16P(List *dataStructure, const volatile void** key, const volatile u16* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackPointerI32(List *dataStructure, void* key, i32 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddBackPointerI32P(List *dataStructure, void* key, const volatile i32* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackPointerPI32(List *dataStructure, const volatile void** key, i32 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeI32);
}
static inline ListNode* listAddBackPointerPI32P(List *dataStructure, const volatile void** key, const volatile i32* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackPointerU32(List *dataStructure, void* key, u32 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddBackPointerU32P(List *dataStructure, void* key, const volatile u32* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackPointerPU32(List *dataStructure, const volatile void** key, u32 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeU32);
}
static inline ListNode* listAddBackPointerPU32P(List *dataStructure, const volatile void** key, const volatile u32* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackPointerI64(List *dataStructure, void* key, i64 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddBackPointerI64P(List *dataStructure, void* key, const volatile i64* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackPointerPI64(List *dataStructure, const volatile void** key, i64 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeI64);
}
static inline ListNode* listAddBackPointerPI64P(List *dataStructure, const volatile void** key, const volatile i64* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackPointerU64(List *dataStructure, void* key, u64 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddBackPointerU64P(List *dataStructure, void* key, const volatile u64* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackPointerPU64(List *dataStructure, const volatile void** key, u64 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeU64);
}
static inline ListNode* listAddBackPointerPU64P(List *dataStructure, const volatile void** key, const volatile u64* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackPointerFloat(List *dataStructure, void* key, float value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddBackPointerFloatP(List *dataStructure, void* key, const volatile float* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackPointerPFloat(List *dataStructure, const volatile void** key, float value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeFloat);
}
static inline ListNode* listAddBackPointerPFloatP(List *dataStructure, const volatile void** key, const volatile float* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackPointerDouble(List *dataStructure, void* key, double value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddBackPointerDoubleP(List *dataStructure, void* key, const volatile double* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackPointerPDouble(List *dataStructure, const volatile void** key, double value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeDouble);
}
static inline ListNode* listAddBackPointerPDoubleP(List *dataStructure, const volatile void** key, const volatile double* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackPointerLongDouble(List *dataStructure, void* key, long double value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddBackPointerLongDoubleP(List *dataStructure, void* key, const volatile long double* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackPointerPLongDouble(List *dataStructure, const volatile void** key, long double value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeLongDouble);
}
static inline ListNode* listAddBackPointerPLongDoubleP(List *dataStructure, const volatile void** key, const volatile long double* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackPointerList(List *dataStructure, void* key, List value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddBackPointerListP(List *dataStructure, void* key, const volatile List* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddBackPointerPList(List *dataStructure, const volatile void** key, List value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeList);
}
static inline ListNode* listAddBackPointerPListP(List *dataStructure, const volatile void** key, const volatile List* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeListNoCopy);
}
static inline ListNode* listAddBackPointerQueue(List *dataStructure, void* key, Queue value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddBackPointerQueueP(List *dataStructure, void* key, const volatile Queue* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackPointerPQueue(List *dataStructure, const volatile void** key, Queue value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeQueue);
}
static inline ListNode* listAddBackPointerPQueueP(List *dataStructure, const volatile void** key, const volatile Queue* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackPointerStack(List *dataStructure, void* key, Stack value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddBackPointerStackP(List *dataStructure, void* key, const volatile Stack* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackPointerPStack(List *dataStructure, const volatile void** key, Stack value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeStack);
}
static inline ListNode* listAddBackPointerPStackP(List *dataStructure, const volatile void** key, const volatile Stack* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackPointerRedBlackTree(List *dataStructure, void* key, RedBlackTree value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackPointerRedBlackTreeP(List *dataStructure, void* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackPointerPRedBlackTree(List *dataStructure, const volatile void** key, RedBlackTree value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackPointerPRedBlackTreeP(List *dataStructure, const volatile void** key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackPointerHashTable(List *dataStructure, void* key, HashTable value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddBackPointerHashTableP(List *dataStructure, void* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackPointerPHashTable(List *dataStructure, const volatile void** key, HashTable value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeHashTable);
}
static inline ListNode* listAddBackPointerPHashTableP(List *dataStructure, const volatile void** key, const volatile HashTable* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackPointerVector(List *dataStructure, void* key, Vector value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddBackPointerVectorP(List *dataStructure, void* key, const volatile Vector* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackPointerPVector(List *dataStructure, const volatile void** key, Vector value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeVector);
}
static inline ListNode* listAddBackPointerPVectorP(List *dataStructure, const volatile void** key, const volatile Vector* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackPointerString(List *dataStructure, void* key, const volatile char* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddBackPointerStringP(List *dataStructure, void* key, const volatile char** value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackPointerPString(List *dataStructure, const volatile void** key, const volatile char* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeString);
}
static inline ListNode* listAddBackPointerPStringP(List *dataStructure, const volatile void** key, const volatile char** value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackPointerBytes(List *dataStructure, void* key, Bytes value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddBackPointerBytesP(List *dataStructure, void* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackPointerPBytes(List *dataStructure, const volatile void** key, Bytes value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typeBytes);
}
static inline ListNode* listAddBackPointerPBytesP(List *dataStructure, const volatile void** key, const volatile Bytes* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackPointerPointer(List *dataStructure, void* key, void* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddBackPointerPointerP(List *dataStructure, void* key, const volatile void** value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackPointerPPointer(List *dataStructure, const volatile void** key, void* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, value, typePointer);
}
static inline ListNode* listAddBackPointerPPointerP(List *dataStructure, const volatile void** key, const volatile void** value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackPointerI8(List *dataStructure, void* key, i8 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddBackPointerPI8(List *dataStructure, const volatile void** key, i8 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeI8);
}
static inline ListNode* listAddBackPointerU8(List *dataStructure, void* key, u8 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddBackPointerPU8(List *dataStructure, const volatile void** key, u8 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, *key, &value, typeU8);
}

static inline ListNode* listAddBackI8Bool(List *dataStructure, i8 key, bool value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddBackI8BoolP(List *dataStructure, i8 key, const volatile bool* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackI8I16(List *dataStructure, i8 key, i16 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddBackI8I16P(List *dataStructure, i8 key, const volatile i16* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackI8U16(List *dataStructure, i8 key, u16 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddBackI8U16P(List *dataStructure, i8 key, const volatile u16* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackI8I32(List *dataStructure, i8 key, i32 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddBackI8I32P(List *dataStructure, i8 key, const volatile i32* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackI8U32(List *dataStructure, i8 key, u32 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddBackI8U32P(List *dataStructure, i8 key, const volatile u32* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackI8I64(List *dataStructure, i8 key, i64 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddBackI8I64P(List *dataStructure, i8 key, const volatile i64* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackI8U64(List *dataStructure, i8 key, u64 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddBackI8U64P(List *dataStructure, i8 key, const volatile u64* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackI8Float(List *dataStructure, i8 key, float value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddBackI8FloatP(List *dataStructure, i8 key, const volatile float* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackI8Double(List *dataStructure, i8 key, double value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddBackI8DoubleP(List *dataStructure, i8 key, const volatile double* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackI8LongDouble(List *dataStructure, i8 key, long double value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddBackI8LongDoubleP(List *dataStructure, i8 key, const volatile long double* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackI8List(List *dataStructure, i8 key, List value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddBackI8ListP(List *dataStructure, i8 key, const volatile List* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddBackI8Queue(List *dataStructure, i8 key, Queue value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddBackI8QueueP(List *dataStructure, i8 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackI8Stack(List *dataStructure, i8 key, Stack value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddBackI8StackP(List *dataStructure, i8 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackI8RedBlackTree(List *dataStructure, i8 key, RedBlackTree value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackI8RedBlackTreeP(List *dataStructure, i8 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackI8HashTable(List *dataStructure, i8 key, HashTable value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddBackI8HashTableP(List *dataStructure, i8 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackI8Vector(List *dataStructure, i8 key, Vector value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddBackI8VectorP(List *dataStructure, i8 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackI8String(List *dataStructure, i8 key, const volatile char* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddBackI8StringP(List *dataStructure, i8 key, const volatile char** value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackI8Bytes(List *dataStructure, i8 key, Bytes value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddBackI8BytesP(List *dataStructure, i8 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackI8Pointer(List *dataStructure, i8 key, void* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddBackI8PointerP(List *dataStructure, i8 key, const volatile void** value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackI8I8(List *dataStructure, i8 key, i8 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddBackI8U8(List *dataStructure, i8 key, u8 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU8);
}

static inline ListNode* listAddBackU8Bool(List *dataStructure, u8 key, bool value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddBackU8BoolP(List *dataStructure, u8 key, const volatile bool* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddBackU8I16(List *dataStructure, u8 key, i16 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddBackU8I16P(List *dataStructure, u8 key, const volatile i16* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddBackU8U16(List *dataStructure, u8 key, u16 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddBackU8U16P(List *dataStructure, u8 key, const volatile u16* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddBackU8I32(List *dataStructure, u8 key, i32 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddBackU8I32P(List *dataStructure, u8 key, const volatile i32* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddBackU8U32(List *dataStructure, u8 key, u32 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddBackU8U32P(List *dataStructure, u8 key, const volatile u32* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddBackU8I64(List *dataStructure, u8 key, i64 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddBackU8I64P(List *dataStructure, u8 key, const volatile i64* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddBackU8U64(List *dataStructure, u8 key, u64 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddBackU8U64P(List *dataStructure, u8 key, const volatile u64* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddBackU8Float(List *dataStructure, u8 key, float value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddBackU8FloatP(List *dataStructure, u8 key, const volatile float* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddBackU8Double(List *dataStructure, u8 key, double value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddBackU8DoubleP(List *dataStructure, u8 key, const volatile double* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddBackU8LongDouble(List *dataStructure, u8 key, long double value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddBackU8LongDoubleP(List *dataStructure, u8 key, const volatile long double* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddBackU8List(List *dataStructure, u8 key, List value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddBackU8ListP(List *dataStructure, u8 key, const volatile List* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddBackU8Queue(List *dataStructure, u8 key, Queue value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddBackU8QueueP(List *dataStructure, u8 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddBackU8Stack(List *dataStructure, u8 key, Stack value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddBackU8StackP(List *dataStructure, u8 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddBackU8RedBlackTree(List *dataStructure, u8 key, RedBlackTree value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddBackU8RedBlackTreeP(List *dataStructure, u8 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddBackU8HashTable(List *dataStructure, u8 key, HashTable value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddBackU8HashTableP(List *dataStructure, u8 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddBackU8Vector(List *dataStructure, u8 key, Vector value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddBackU8VectorP(List *dataStructure, u8 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddBackU8String(List *dataStructure, u8 key, const volatile char* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddBackU8StringP(List *dataStructure, u8 key, const volatile char** value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddBackU8Bytes(List *dataStructure, u8 key, Bytes value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddBackU8BytesP(List *dataStructure, u8 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddBackU8Pointer(List *dataStructure, u8 key, void* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddBackU8PointerP(List *dataStructure, u8 key, const volatile void** value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddBackU8I8(List *dataStructure, u8 key, i8 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddBackU8U8(List *dataStructure, u8 key, u8 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddBackEntry(dataStructure, &key, &value, typeU8);
}

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#if defined __STDC_VERSION__

#if __STDC_VERSION__ >= 201710L
#define TYPE_SAFE_LIST

#define LIST_ADD_BACK_GENERIC_CASES_BOOL_KEY(dataStructure, key, value) \
  bool:                  listAddBackBoolBool,                        \
  bool*:                 listAddBackBoolBoolP,                       \
  const volatile bool*:  listAddBackBoolBoolP,                       \
  i16:                   listAddBackBoolI16,                         \
  i16*:                  listAddBackBoolI16P,                        \
  const volatile i16*:   listAddBackBoolI16P,                        \
  u16:                   listAddBackBoolU16,                         \
  u16*:                  listAddBackBoolU16P,                        \
  const volatile u16*:   listAddBackBoolU16P,                        \
  i32:                   listAddBackBoolI32,                         \
  i32*:                  listAddBackBoolI32P,                        \
  const volatile i32*:   listAddBackBoolI32P,                        \
  u32:                   listAddBackBoolU32,                         \
  u32*:                  listAddBackBoolU32P,                        \
  const volatile u32*:   listAddBackBoolU32P,                        \
  i64:                   listAddBackBoolI64,                         \
  i64*:                  listAddBackBoolI64P,                        \
  const volatile i64*:   listAddBackBoolI64P,                        \
  u64:                   listAddBackBoolU64,                         \
  u64*:                  listAddBackBoolU64P,                        \
  const volatile u64*:   listAddBackBoolU64P,                        \
  float:                 listAddBackBoolFloat,                       \
  float*:                listAddBackBoolFloatP,                      \
  const volatile float*: listAddBackBoolFloatP,                      \
  double:                listAddBackBoolDouble,                      \
  double*:               listAddBackBoolDoubleP,                     \
  const volatile double*: listAddBackBoolDoubleP,                     \
  long double:           listAddBackBoolLongDouble,                  \
  long double*:          listAddBackBoolLongDoubleP,                 \
  const volatile long double*: listAddBackBoolLongDoubleP,                 \
  List:                  listAddBackBoolList,                        \
  List*:                 listAddBackBoolListP,                       \
  const volatile List*:  listAddBackBoolListP,                       \
  Queue:                 listAddBackBoolQueue,                       \
  Queue*:                listAddBackBoolQueueP,                      \
  const volatile Queue*: listAddBackBoolQueueP,                      \
  Stack:                 listAddBackBoolStack,                       \
  Stack*:                listAddBackBoolStackP,                      \
  const volatile Stack*: listAddBackBoolStackP,                      \
  RedBlackTree:          listAddBackBoolRedBlackTree,                \
  RedBlackTree*:         listAddBackBoolRedBlackTreeP,               \
  const volatile RedBlackTree*: listAddBackBoolRedBlackTreeP,               \
  HashTable:             listAddBackBoolHashTable,                   \
  HashTable*:            listAddBackBoolHashTableP,                  \
  const volatile HashTable*: listAddBackBoolHashTableP,                  \
  Vector:                listAddBackBoolVector,                      \
  Vector*:               listAddBackBoolVectorP,                     \
  const volatile Vector*: listAddBackBoolVectorP,                     \
  char*:                 listAddBackBoolString,                      \
  const volatile char*:  listAddBackBoolString,                      \
  char**:                listAddBackBoolStringP,                     \
  const volatile char**: listAddBackBoolStringP,                     \
  Bytes:                 listAddBackBoolBytes,                       \
  Bytes*:                listAddBackBoolBytesP,                      \
  const volatile Bytes*: listAddBackBoolBytesP,                      \
  void*:                 listAddBackBoolPointer,                     \
  void**:                listAddBackBoolPointerP,                    \
  const volatile void**: listAddBackBoolPointerP,                    \
  i8:                    listAddBackBoolI8,                          \
  u8:                    listAddBackBoolU8                           \

#define listAddBackBool(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_BOOL_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_I16_KEY(dataStructure, key, value) \
  bool:                  listAddBackI16Bool,                         \
  bool*:                 listAddBackI16BoolP,                        \
  const volatile bool*:  listAddBackI16BoolP,                        \
  i16:                   listAddBackI16I16,                          \
  i16*:                  listAddBackI16I16P,                         \
  const volatile i16*:   listAddBackI16I16P,                         \
  u16:                   listAddBackI16U16,                          \
  u16*:                  listAddBackI16U16P,                         \
  const volatile u16*:   listAddBackI16U16P,                         \
  i32:                   listAddBackI16I32,                          \
  i32*:                  listAddBackI16I32P,                         \
  const volatile i32*:   listAddBackI16I32P,                         \
  u32:                   listAddBackI16U32,                          \
  u32*:                  listAddBackI16U32P,                         \
  const volatile u32*:   listAddBackI16U32P,                         \
  i64:                   listAddBackI16I64,                          \
  i64*:                  listAddBackI16I64P,                         \
  const volatile i64*:   listAddBackI16I64P,                         \
  u64:                   listAddBackI16U64,                          \
  u64*:                  listAddBackI16U64P,                         \
  const volatile u64*:   listAddBackI16U64P,                         \
  float:                 listAddBackI16Float,                        \
  float*:                listAddBackI16FloatP,                       \
  const volatile float*: listAddBackI16FloatP,                       \
  double:                listAddBackI16Double,                       \
  double*:               listAddBackI16DoubleP,                      \
  const volatile double*: listAddBackI16DoubleP,                      \
  long double:           listAddBackI16LongDouble,                   \
  long double*:          listAddBackI16LongDoubleP,                  \
  const volatile long double*: listAddBackI16LongDoubleP,                  \
  List:                  listAddBackI16List,                         \
  List*:                 listAddBackI16ListP,                        \
  const volatile List*:  listAddBackI16ListP,                        \
  Queue:                 listAddBackI16Queue,                        \
  Queue*:                listAddBackI16QueueP,                       \
  const volatile Queue*: listAddBackI16QueueP,                       \
  Stack:                 listAddBackI16Stack,                        \
  Stack*:                listAddBackI16StackP,                       \
  const volatile Stack*: listAddBackI16StackP,                       \
  RedBlackTree:          listAddBackI16RedBlackTree,                 \
  RedBlackTree*:         listAddBackI16RedBlackTreeP,                \
  const volatile RedBlackTree*: listAddBackI16RedBlackTreeP,                \
  HashTable:             listAddBackI16HashTable,                    \
  HashTable*:            listAddBackI16HashTableP,                   \
  const volatile HashTable*: listAddBackI16HashTableP,                   \
  Vector:                listAddBackI16Vector,                       \
  Vector*:               listAddBackI16VectorP,                      \
  const volatile Vector*: listAddBackI16VectorP,                      \
  char*:                 listAddBackI16String,                       \
  const volatile char*:  listAddBackI16String,                       \
  char**:                listAddBackI16StringP,                      \
  const volatile char**: listAddBackI16StringP,                      \
  Bytes:                 listAddBackI16Bytes,                        \
  Bytes*:                listAddBackI16BytesP,                       \
  const volatile Bytes*: listAddBackI16BytesP,                       \
  void*:                 listAddBackI16Pointer,                      \
  void**:                listAddBackI16PointerP,                     \
  const volatile void**: listAddBackI16PointerP,                     \
  i8:                    listAddBackI16I8,                           \
  u8:                    listAddBackI16U8                            \

#define listAddBackI16(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_I16_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_U16_KEY(dataStructure, key, value) \
  bool:                  listAddBackU16Bool,                         \
  bool*:                 listAddBackU16BoolP,                        \
  const volatile bool*:  listAddBackU16BoolP,                        \
  i16:                   listAddBackU16I16,                          \
  i16*:                  listAddBackU16I16P,                         \
  const volatile i16*:   listAddBackU16I16P,                         \
  u16:                   listAddBackU16U16,                          \
  u16*:                  listAddBackU16U16P,                         \
  const volatile u16*:   listAddBackU16U16P,                         \
  i32:                   listAddBackU16I32,                          \
  i32*:                  listAddBackU16I32P,                         \
  const volatile i32*:   listAddBackU16I32P,                         \
  u32:                   listAddBackU16U32,                          \
  u32*:                  listAddBackU16U32P,                         \
  const volatile u32*:   listAddBackU16U32P,                         \
  i64:                   listAddBackU16I64,                          \
  i64*:                  listAddBackU16I64P,                         \
  const volatile i64*:   listAddBackU16I64P,                         \
  u64:                   listAddBackU16U64,                          \
  u64*:                  listAddBackU16U64P,                         \
  const volatile u64*:   listAddBackU16U64P,                         \
  float:                 listAddBackU16Float,                        \
  float*:                listAddBackU16FloatP,                       \
  const volatile float*: listAddBackU16FloatP,                       \
  double:                listAddBackU16Double,                       \
  double*:               listAddBackU16DoubleP,                      \
  const volatile double*: listAddBackU16DoubleP,                      \
  long double:           listAddBackU16LongDouble,                   \
  long double*:          listAddBackU16LongDoubleP,                  \
  const volatile long double*: listAddBackU16LongDoubleP,                  \
  List:                  listAddBackU16List,                         \
  List*:                 listAddBackU16ListP,                        \
  const volatile List*:  listAddBackU16ListP,                        \
  Queue:                 listAddBackU16Queue,                        \
  Queue*:                listAddBackU16QueueP,                       \
  const volatile Queue*: listAddBackU16QueueP,                       \
  Stack:                 listAddBackU16Stack,                        \
  Stack*:                listAddBackU16StackP,                       \
  const volatile Stack*: listAddBackU16StackP,                       \
  RedBlackTree:          listAddBackU16RedBlackTree,                 \
  RedBlackTree*:         listAddBackU16RedBlackTreeP,                \
  const volatile RedBlackTree*: listAddBackU16RedBlackTreeP,                \
  HashTable:             listAddBackU16HashTable,                    \
  HashTable*:            listAddBackU16HashTableP,                   \
  const volatile HashTable*: listAddBackU16HashTableP,                   \
  Vector:                listAddBackU16Vector,                       \
  Vector*:               listAddBackU16VectorP,                      \
  const volatile Vector*: listAddBackU16VectorP,                      \
  char*:                 listAddBackU16String,                       \
  const volatile char*:  listAddBackU16String,                       \
  char**:                listAddBackU16StringP,                      \
  const volatile char**: listAddBackU16StringP,                      \
  Bytes:                 listAddBackU16Bytes,                        \
  Bytes*:                listAddBackU16BytesP,                       \
  const volatile Bytes*: listAddBackU16BytesP,                       \
  void*:                 listAddBackU16Pointer,                      \
  void**:                listAddBackU16PointerP,                     \
  const volatile void**: listAddBackU16PointerP,                     \
  i8:                    listAddBackU16I8,                           \
  u8:                    listAddBackU16U8                            \

#define listAddBackU16(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_U16_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_I32_KEY(dataStructure, key, value) \
  bool:                  listAddBackI32Bool,                         \
  bool*:                 listAddBackI32BoolP,                        \
  const volatile bool*:  listAddBackI32BoolP,                        \
  i16:                   listAddBackI32I16,                          \
  i16*:                  listAddBackI32I16P,                         \
  const volatile i16*:   listAddBackI32I16P,                         \
  u16:                   listAddBackI32U16,                          \
  u16*:                  listAddBackI32U16P,                         \
  const volatile u16*:   listAddBackI32U16P,                         \
  i32:                   listAddBackI32I32,                          \
  i32*:                  listAddBackI32I32P,                         \
  const volatile i32*:   listAddBackI32I32P,                         \
  u32:                   listAddBackI32U32,                          \
  u32*:                  listAddBackI32U32P,                         \
  const volatile u32*:   listAddBackI32U32P,                         \
  i64:                   listAddBackI32I64,                          \
  i64*:                  listAddBackI32I64P,                         \
  const volatile i64*:   listAddBackI32I64P,                         \
  u64:                   listAddBackI32U64,                          \
  u64*:                  listAddBackI32U64P,                         \
  const volatile u64*:   listAddBackI32U64P,                         \
  float:                 listAddBackI32Float,                        \
  float*:                listAddBackI32FloatP,                       \
  const volatile float*: listAddBackI32FloatP,                       \
  double:                listAddBackI32Double,                       \
  double*:               listAddBackI32DoubleP,                      \
  const volatile double*: listAddBackI32DoubleP,                      \
  long double:           listAddBackI32LongDouble,                   \
  long double*:          listAddBackI32LongDoubleP,                  \
  const volatile long double*: listAddBackI32LongDoubleP,                  \
  List:                  listAddBackI32List,                         \
  List*:                 listAddBackI32ListP,                        \
  const volatile List*:  listAddBackI32ListP,                        \
  Queue:                 listAddBackI32Queue,                        \
  Queue*:                listAddBackI32QueueP,                       \
  const volatile Queue*: listAddBackI32QueueP,                       \
  Stack:                 listAddBackI32Stack,                        \
  Stack*:                listAddBackI32StackP,                       \
  const volatile Stack*: listAddBackI32StackP,                       \
  RedBlackTree:          listAddBackI32RedBlackTree,                 \
  RedBlackTree*:         listAddBackI32RedBlackTreeP,                \
  const volatile RedBlackTree*: listAddBackI32RedBlackTreeP,                \
  HashTable:             listAddBackI32HashTable,                    \
  HashTable*:            listAddBackI32HashTableP,                   \
  const volatile HashTable*: listAddBackI32HashTableP,                   \
  Vector:                listAddBackI32Vector,                       \
  Vector*:               listAddBackI32VectorP,                      \
  const volatile Vector*: listAddBackI32VectorP,                      \
  char*:                 listAddBackI32String,                       \
  const volatile char*:  listAddBackI32String,                       \
  char**:                listAddBackI32StringP,                      \
  const volatile char**: listAddBackI32StringP,                      \
  Bytes:                 listAddBackI32Bytes,                        \
  Bytes*:                listAddBackI32BytesP,                       \
  const volatile Bytes*: listAddBackI32BytesP,                       \
  void*:                 listAddBackI32Pointer,                      \
  void**:                listAddBackI32PointerP,                     \
  const volatile void**: listAddBackI32PointerP,                     \
  i8:                    listAddBackI32I8,                           \
  u8:                    listAddBackI32U8                            \

#define listAddBackI32(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_I32_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_U32_KEY(dataStructure, key, value) \
  bool:                  listAddBackU32Bool,                         \
  bool*:                 listAddBackU32BoolP,                        \
  const volatile bool*:  listAddBackU32BoolP,                        \
  i16:                   listAddBackU32I16,                          \
  i16*:                  listAddBackU32I16P,                         \
  const volatile i16*:   listAddBackU32I16P,                         \
  u16:                   listAddBackU32U16,                          \
  u16*:                  listAddBackU32U16P,                         \
  const volatile u16*:   listAddBackU32U16P,                         \
  i32:                   listAddBackU32I32,                          \
  i32*:                  listAddBackU32I32P,                         \
  const volatile i32*:   listAddBackU32I32P,                         \
  u32:                   listAddBackU32U32,                          \
  u32*:                  listAddBackU32U32P,                         \
  const volatile u32*:   listAddBackU32U32P,                         \
  i64:                   listAddBackU32I64,                          \
  i64*:                  listAddBackU32I64P,                         \
  const volatile i64*:   listAddBackU32I64P,                         \
  u64:                   listAddBackU32U64,                          \
  u64*:                  listAddBackU32U64P,                         \
  const volatile u64*:   listAddBackU32U64P,                         \
  float:                 listAddBackU32Float,                        \
  float*:                listAddBackU32FloatP,                       \
  const volatile float*: listAddBackU32FloatP,                       \
  double:                listAddBackU32Double,                       \
  double*:               listAddBackU32DoubleP,                      \
  const volatile double*: listAddBackU32DoubleP,                      \
  long double:           listAddBackU32LongDouble,                   \
  long double*:          listAddBackU32LongDoubleP,                  \
  const volatile long double*: listAddBackU32LongDoubleP,                  \
  List:                  listAddBackU32List,                         \
  List*:                 listAddBackU32ListP,                        \
  const volatile List*:  listAddBackU32ListP,                        \
  Queue:                 listAddBackU32Queue,                        \
  Queue*:                listAddBackU32QueueP,                       \
  const volatile Queue*: listAddBackU32QueueP,                       \
  Stack:                 listAddBackU32Stack,                        \
  Stack*:                listAddBackU32StackP,                       \
  const volatile Stack*: listAddBackU32StackP,                       \
  RedBlackTree:          listAddBackU32RedBlackTree,                 \
  RedBlackTree*:         listAddBackU32RedBlackTreeP,                \
  const volatile RedBlackTree*: listAddBackU32RedBlackTreeP,                \
  HashTable:             listAddBackU32HashTable,                    \
  HashTable*:            listAddBackU32HashTableP,                   \
  const volatile HashTable*: listAddBackU32HashTableP,                   \
  Vector:                listAddBackU32Vector,                       \
  Vector*:               listAddBackU32VectorP,                      \
  const volatile Vector*: listAddBackU32VectorP,                      \
  char*:                 listAddBackU32String,                       \
  const volatile char*:  listAddBackU32String,                       \
  char**:                listAddBackU32StringP,                      \
  const volatile char**: listAddBackU32StringP,                      \
  Bytes:                 listAddBackU32Bytes,                        \
  Bytes*:                listAddBackU32BytesP,                       \
  const volatile Bytes*: listAddBackU32BytesP,                       \
  void*:                 listAddBackU32Pointer,                      \
  void**:                listAddBackU32PointerP,                     \
  const volatile void**: listAddBackU32PointerP,                     \
  i8:                    listAddBackU32I8,                           \
  u8:                    listAddBackU32U8                            \

#define listAddBackU32(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_U32_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_I64_KEY(dataStructure, key, value) \
  bool:                  listAddBackI64Bool,                         \
  bool*:                 listAddBackI64BoolP,                        \
  const volatile bool*:  listAddBackI64BoolP,                        \
  i16:                   listAddBackI64I16,                          \
  i16*:                  listAddBackI64I16P,                         \
  const volatile i16*:   listAddBackI64I16P,                         \
  u16:                   listAddBackI64U16,                          \
  u16*:                  listAddBackI64U16P,                         \
  const volatile u16*:   listAddBackI64U16P,                         \
  i32:                   listAddBackI64I32,                          \
  i32*:                  listAddBackI64I32P,                         \
  const volatile i32*:   listAddBackI64I32P,                         \
  u32:                   listAddBackI64U32,                          \
  u32*:                  listAddBackI64U32P,                         \
  const volatile u32*:   listAddBackI64U32P,                         \
  i64:                   listAddBackI64I64,                          \
  i64*:                  listAddBackI64I64P,                         \
  const volatile i64*:   listAddBackI64I64P,                         \
  u64:                   listAddBackI64U64,                          \
  u64*:                  listAddBackI64U64P,                         \
  const volatile u64*:   listAddBackI64U64P,                         \
  float:                 listAddBackI64Float,                        \
  float*:                listAddBackI64FloatP,                       \
  const volatile float*: listAddBackI64FloatP,                       \
  double:                listAddBackI64Double,                       \
  double*:               listAddBackI64DoubleP,                      \
  const volatile double*: listAddBackI64DoubleP,                      \
  long double:           listAddBackI64LongDouble,                   \
  long double*:          listAddBackI64LongDoubleP,                  \
  const volatile long double*: listAddBackI64LongDoubleP,                  \
  List:                  listAddBackI64List,                         \
  List*:                 listAddBackI64ListP,                        \
  const volatile List*:  listAddBackI64ListP,                        \
  Queue:                 listAddBackI64Queue,                        \
  Queue*:                listAddBackI64QueueP,                       \
  const volatile Queue*: listAddBackI64QueueP,                       \
  Stack:                 listAddBackI64Stack,                        \
  Stack*:                listAddBackI64StackP,                       \
  const volatile Stack*: listAddBackI64StackP,                       \
  RedBlackTree:          listAddBackI64RedBlackTree,                 \
  RedBlackTree*:         listAddBackI64RedBlackTreeP,                \
  const volatile RedBlackTree*: listAddBackI64RedBlackTreeP,                \
  HashTable:             listAddBackI64HashTable,                    \
  HashTable*:            listAddBackI64HashTableP,                   \
  const volatile HashTable*: listAddBackI64HashTableP,                   \
  Vector:                listAddBackI64Vector,                       \
  Vector*:               listAddBackI64VectorP,                      \
  const volatile Vector*: listAddBackI64VectorP,                      \
  char*:                 listAddBackI64String,                       \
  const volatile char*:  listAddBackI64String,                       \
  char**:                listAddBackI64StringP,                      \
  const volatile char**: listAddBackI64StringP,                      \
  Bytes:                 listAddBackI64Bytes,                        \
  Bytes*:                listAddBackI64BytesP,                       \
  const volatile Bytes*: listAddBackI64BytesP,                       \
  void*:                 listAddBackI64Pointer,                      \
  void**:                listAddBackI64PointerP,                     \
  const volatile void**: listAddBackI64PointerP,                     \
  i8:                    listAddBackI64I8,                           \
  u8:                    listAddBackI64U8                            \

#define listAddBackI64(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_I64_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_U64_KEY(dataStructure, key, value) \
  bool:                  listAddBackU64Bool,                         \
  bool*:                 listAddBackU64BoolP,                        \
  const volatile bool*:  listAddBackU64BoolP,                        \
  i16:                   listAddBackU64I16,                          \
  i16*:                  listAddBackU64I16P,                         \
  const volatile i16*:   listAddBackU64I16P,                         \
  u16:                   listAddBackU64U16,                          \
  u16*:                  listAddBackU64U16P,                         \
  const volatile u16*:   listAddBackU64U16P,                         \
  i32:                   listAddBackU64I32,                          \
  i32*:                  listAddBackU64I32P,                         \
  const volatile i32*:   listAddBackU64I32P,                         \
  u32:                   listAddBackU64U32,                          \
  u32*:                  listAddBackU64U32P,                         \
  const volatile u32*:   listAddBackU64U32P,                         \
  i64:                   listAddBackU64I64,                          \
  i64*:                  listAddBackU64I64P,                         \
  const volatile i64*:   listAddBackU64I64P,                         \
  u64:                   listAddBackU64U64,                          \
  u64*:                  listAddBackU64U64P,                         \
  const volatile u64*:   listAddBackU64U64P,                         \
  float:                 listAddBackU64Float,                        \
  float*:                listAddBackU64FloatP,                       \
  const volatile float*: listAddBackU64FloatP,                       \
  double:                listAddBackU64Double,                       \
  double*:               listAddBackU64DoubleP,                      \
  const volatile double*: listAddBackU64DoubleP,                      \
  long double:           listAddBackU64LongDouble,                   \
  long double*:          listAddBackU64LongDoubleP,                  \
  const volatile long double*: listAddBackU64LongDoubleP,                  \
  List:                  listAddBackU64List,                         \
  List*:                 listAddBackU64ListP,                        \
  const volatile List*:  listAddBackU64ListP,                        \
  Queue:                 listAddBackU64Queue,                        \
  Queue*:                listAddBackU64QueueP,                       \
  const volatile Queue*: listAddBackU64QueueP,                       \
  Stack:                 listAddBackU64Stack,                        \
  Stack*:                listAddBackU64StackP,                       \
  const volatile Stack*: listAddBackU64StackP,                       \
  RedBlackTree:          listAddBackU64RedBlackTree,                 \
  RedBlackTree*:         listAddBackU64RedBlackTreeP,                \
  const volatile RedBlackTree*: listAddBackU64RedBlackTreeP,                \
  HashTable:             listAddBackU64HashTable,                    \
  HashTable*:            listAddBackU64HashTableP,                   \
  const volatile HashTable*: listAddBackU64HashTableP,                   \
  Vector:                listAddBackU64Vector,                       \
  Vector*:               listAddBackU64VectorP,                      \
  const volatile Vector*: listAddBackU64VectorP,                      \
  char*:                 listAddBackU64String,                       \
  const volatile char*:  listAddBackU64String,                       \
  char**:                listAddBackU64StringP,                      \
  const volatile char**: listAddBackU64StringP,                      \
  Bytes:                 listAddBackU64Bytes,                        \
  Bytes*:                listAddBackU64BytesP,                       \
  const volatile Bytes*: listAddBackU64BytesP,                       \
  void*:                 listAddBackU64Pointer,                      \
  void**:                listAddBackU64PointerP,                     \
  const volatile void**: listAddBackU64PointerP,                     \
  i8:                    listAddBackU64I8,                           \
  u8:                    listAddBackU64U8                            \

#define listAddBackU64(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_U64_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_FLOAT_KEY(dataStructure, key, value) \
  bool:                  listAddBackFloatBool,                       \
  bool*:                 listAddBackFloatBoolP,                      \
  const volatile bool*:  listAddBackFloatBoolP,                      \
  i16:                   listAddBackFloatI16,                        \
  i16*:                  listAddBackFloatI16P,                       \
  const volatile i16*:   listAddBackFloatI16P,                       \
  u16:                   listAddBackFloatU16,                        \
  u16*:                  listAddBackFloatU16P,                       \
  const volatile u16*:   listAddBackFloatU16P,                       \
  i32:                   listAddBackFloatI32,                        \
  i32*:                  listAddBackFloatI32P,                       \
  const volatile i32*:   listAddBackFloatI32P,                       \
  u32:                   listAddBackFloatU32,                        \
  u32*:                  listAddBackFloatU32P,                       \
  const volatile u32*:   listAddBackFloatU32P,                       \
  i64:                   listAddBackFloatI64,                        \
  i64*:                  listAddBackFloatI64P,                       \
  const volatile i64*:   listAddBackFloatI64P,                       \
  u64:                   listAddBackFloatU64,                        \
  u64*:                  listAddBackFloatU64P,                       \
  const volatile u64*:   listAddBackFloatU64P,                       \
  float:                 listAddBackFloatFloat,                      \
  float*:                listAddBackFloatFloatP,                     \
  const volatile float*: listAddBackFloatFloatP,                     \
  double:                listAddBackFloatDouble,                     \
  double*:               listAddBackFloatDoubleP,                    \
  const volatile double*: listAddBackFloatDoubleP,                    \
  long double:           listAddBackFloatLongDouble,                 \
  long double*:          listAddBackFloatLongDoubleP,                \
  const volatile long double*: listAddBackFloatLongDoubleP,                \
  List:                  listAddBackFloatList,                       \
  List*:                 listAddBackFloatListP,                      \
  const volatile List*:  listAddBackFloatListP,                      \
  Queue:                 listAddBackFloatQueue,                      \
  Queue*:                listAddBackFloatQueueP,                     \
  const volatile Queue*: listAddBackFloatQueueP,                     \
  Stack:                 listAddBackFloatStack,                      \
  Stack*:                listAddBackFloatStackP,                     \
  const volatile Stack*: listAddBackFloatStackP,                     \
  RedBlackTree:          listAddBackFloatRedBlackTree,               \
  RedBlackTree*:         listAddBackFloatRedBlackTreeP,              \
  const volatile RedBlackTree*: listAddBackFloatRedBlackTreeP,              \
  HashTable:             listAddBackFloatHashTable,                  \
  HashTable*:            listAddBackFloatHashTableP,                 \
  const volatile HashTable*: listAddBackFloatHashTableP,                 \
  Vector:                listAddBackFloatVector,                     \
  Vector*:               listAddBackFloatVectorP,                    \
  const volatile Vector*: listAddBackFloatVectorP,                    \
  char*:                 listAddBackFloatString,                     \
  const volatile char*:  listAddBackFloatString,                     \
  char**:                listAddBackFloatStringP,                    \
  const volatile char**: listAddBackFloatStringP,                    \
  Bytes:                 listAddBackFloatBytes,                      \
  Bytes*:                listAddBackFloatBytesP,                     \
  const volatile Bytes*: listAddBackFloatBytesP,                     \
  void*:                 listAddBackFloatPointer,                    \
  void**:                listAddBackFloatPointerP,                   \
  const volatile void**: listAddBackFloatPointerP,                   \
  i8:                    listAddBackFloatI8,                         \
  u8:                    listAddBackFloatU8                          \

#define listAddBackFloat(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_FLOAT_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_DOUBLE_KEY(dataStructure, key, value) \
  bool:                  listAddBackDoubleBool,                      \
  bool*:                 listAddBackDoubleBoolP,                     \
  const volatile bool*:  listAddBackDoubleBoolP,                     \
  i16:                   listAddBackDoubleI16,                       \
  i16*:                  listAddBackDoubleI16P,                      \
  const volatile i16*:   listAddBackDoubleI16P,                      \
  u16:                   listAddBackDoubleU16,                       \
  u16*:                  listAddBackDoubleU16P,                      \
  const volatile u16*:   listAddBackDoubleU16P,                      \
  i32:                   listAddBackDoubleI32,                       \
  i32*:                  listAddBackDoubleI32P,                      \
  const volatile i32*:   listAddBackDoubleI32P,                      \
  u32:                   listAddBackDoubleU32,                       \
  u32*:                  listAddBackDoubleU32P,                      \
  const volatile u32*:   listAddBackDoubleU32P,                      \
  i64:                   listAddBackDoubleI64,                       \
  i64*:                  listAddBackDoubleI64P,                      \
  const volatile i64*:   listAddBackDoubleI64P,                      \
  u64:                   listAddBackDoubleU64,                       \
  u64*:                  listAddBackDoubleU64P,                      \
  const volatile u64*:   listAddBackDoubleU64P,                      \
  float:                 listAddBackDoubleFloat,                     \
  float*:                listAddBackDoubleFloatP,                    \
  const volatile float*: listAddBackDoubleFloatP,                    \
  double:                listAddBackDoubleDouble,                    \
  double*:               listAddBackDoubleDoubleP,                   \
  const volatile double*: listAddBackDoubleDoubleP,                   \
  long double:           listAddBackDoubleLongDouble,                \
  long double*:          listAddBackDoubleLongDoubleP,               \
  const volatile long double*: listAddBackDoubleLongDoubleP,               \
  List:                  listAddBackDoubleList,                      \
  List*:                 listAddBackDoubleListP,                     \
  const volatile List*:  listAddBackDoubleListP,                     \
  Queue:                 listAddBackDoubleQueue,                     \
  Queue*:                listAddBackDoubleQueueP,                    \
  const volatile Queue*: listAddBackDoubleQueueP,                    \
  Stack:                 listAddBackDoubleStack,                     \
  Stack*:                listAddBackDoubleStackP,                    \
  const volatile Stack*: listAddBackDoubleStackP,                    \
  RedBlackTree:          listAddBackDoubleRedBlackTree,              \
  RedBlackTree*:         listAddBackDoubleRedBlackTreeP,             \
  const volatile RedBlackTree*: listAddBackDoubleRedBlackTreeP,             \
  HashTable:             listAddBackDoubleHashTable,                 \
  HashTable*:            listAddBackDoubleHashTableP,                \
  const volatile HashTable*: listAddBackDoubleHashTableP,                \
  Vector:                listAddBackDoubleVector,                    \
  Vector*:               listAddBackDoubleVectorP,                   \
  const volatile Vector*: listAddBackDoubleVectorP,                   \
  char*:                 listAddBackDoubleString,                    \
  const volatile char*:  listAddBackDoubleString,                    \
  char**:                listAddBackDoubleStringP,                   \
  const volatile char**: listAddBackDoubleStringP,                   \
  Bytes:                 listAddBackDoubleBytes,                     \
  Bytes*:                listAddBackDoubleBytesP,                    \
  const volatile Bytes*: listAddBackDoubleBytesP,                    \
  void*:                 listAddBackDoublePointer,                   \
  void**:                listAddBackDoublePointerP,                  \
  const volatile void**: listAddBackDoublePointerP,                  \
  i8:                    listAddBackDoubleI8,                        \
  u8:                    listAddBackDoubleU8                         \

#define listAddBackDouble(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_DOUBLE_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_LONG_DOUBLE_KEY(dataStructure, key, value) \
  bool:                  listAddBackLongDoubleBool,                  \
  bool*:                 listAddBackLongDoubleBoolP,                 \
  const volatile bool*:  listAddBackLongDoubleBoolP,                 \
  i16:                   listAddBackLongDoubleI16,                   \
  i16*:                  listAddBackLongDoubleI16P,                  \
  const volatile i16*:   listAddBackLongDoubleI16P,                  \
  u16:                   listAddBackLongDoubleU16,                   \
  u16*:                  listAddBackLongDoubleU16P,                  \
  const volatile u16*:   listAddBackLongDoubleU16P,                  \
  i32:                   listAddBackLongDoubleI32,                   \
  i32*:                  listAddBackLongDoubleI32P,                  \
  const volatile i32*:   listAddBackLongDoubleI32P,                  \
  u32:                   listAddBackLongDoubleU32,                   \
  u32*:                  listAddBackLongDoubleU32P,                  \
  const volatile u32*:   listAddBackLongDoubleU32P,                  \
  i64:                   listAddBackLongDoubleI64,                   \
  i64*:                  listAddBackLongDoubleI64P,                  \
  const volatile i64*:   listAddBackLongDoubleI64P,                  \
  u64:                   listAddBackLongDoubleU64,                   \
  u64*:                  listAddBackLongDoubleU64P,                  \
  const volatile u64*:   listAddBackLongDoubleU64P,                  \
  float:                 listAddBackLongDoubleFloat,                 \
  float*:                listAddBackLongDoubleFloatP,                \
  const volatile float*: listAddBackLongDoubleFloatP,                \
  double:                listAddBackLongDoubleDouble,                \
  double*:               listAddBackLongDoubleDoubleP,               \
  const volatile double*: listAddBackLongDoubleDoubleP,               \
  long double:           listAddBackLongDoubleLongDouble,            \
  long double*:          listAddBackLongDoubleLongDoubleP,           \
  const volatile long double*: listAddBackLongDoubleLongDoubleP,           \
  List:                  listAddBackLongDoubleList,                  \
  List*:                 listAddBackLongDoubleListP,                 \
  const volatile List*:  listAddBackLongDoubleListP,                 \
  Queue:                 listAddBackLongDoubleQueue,                 \
  Queue*:                listAddBackLongDoubleQueueP,                \
  const volatile Queue*: listAddBackLongDoubleQueueP,                \
  Stack:                 listAddBackLongDoubleStack,                 \
  Stack*:                listAddBackLongDoubleStackP,                \
  const volatile Stack*: listAddBackLongDoubleStackP,                \
  RedBlackTree:          listAddBackLongDoubleRedBlackTree,          \
  RedBlackTree*:         listAddBackLongDoubleRedBlackTreeP,         \
  const volatile RedBlackTree*: listAddBackLongDoubleRedBlackTreeP,         \
  HashTable:             listAddBackLongDoubleHashTable,             \
  HashTable*:            listAddBackLongDoubleHashTableP,            \
  const volatile HashTable*: listAddBackLongDoubleHashTableP,            \
  Vector:                listAddBackLongDoubleVector,                \
  Vector*:               listAddBackLongDoubleVectorP,               \
  const volatile Vector*: listAddBackLongDoubleVectorP,               \
  char*:                 listAddBackLongDoubleString,                \
  const volatile char*:  listAddBackLongDoubleString,                \
  char**:                listAddBackLongDoubleStringP,               \
  const volatile char**: listAddBackLongDoubleStringP,               \
  Bytes:                 listAddBackLongDoubleBytes,                 \
  Bytes*:                listAddBackLongDoubleBytesP,                \
  const volatile Bytes*: listAddBackLongDoubleBytesP,                \
  void*:                 listAddBackLongDoublePointer,               \
  void**:                listAddBackLongDoublePointerP,              \
  const volatile void**: listAddBackLongDoublePointerP,              \
  i8:                    listAddBackLongDoubleI8,                    \
  u8:                    listAddBackLongDoubleU8                     \

#define listAddBackLongDouble(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_LONG_DOUBLE_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_LIST_KEY(dataStructure, key, value) \
  bool:                  listAddBackListBool,                        \
  bool*:                 listAddBackListBoolP,                       \
  const volatile bool*:  listAddBackListBoolP,                       \
  i16:                   listAddBackListI16,                         \
  i16*:                  listAddBackListI16P,                        \
  const volatile i16*:   listAddBackListI16P,                        \
  u16:                   listAddBackListU16,                         \
  u16*:                  listAddBackListU16P,                        \
  const volatile u16*:   listAddBackListU16P,                        \
  i32:                   listAddBackListI32,                         \
  i32*:                  listAddBackListI32P,                        \
  const volatile i32*:   listAddBackListI32P,                        \
  u32:                   listAddBackListU32,                         \
  u32*:                  listAddBackListU32P,                        \
  const volatile u32*:   listAddBackListU32P,                        \
  i64:                   listAddBackListI64,                         \
  i64*:                  listAddBackListI64P,                        \
  const volatile i64*:   listAddBackListI64P,                        \
  u64:                   listAddBackListU64,                         \
  u64*:                  listAddBackListU64P,                        \
  const volatile u64*:   listAddBackListU64P,                        \
  float:                 listAddBackListFloat,                       \
  float*:                listAddBackListFloatP,                      \
  const volatile float*: listAddBackListFloatP,                      \
  double:                listAddBackListDouble,                      \
  double*:               listAddBackListDoubleP,                     \
  const volatile double*: listAddBackListDoubleP,                     \
  long double:           listAddBackListLongDouble,                  \
  long double*:          listAddBackListLongDoubleP,                 \
  const volatile long double*: listAddBackListLongDoubleP,                 \
  List:                  listAddBackListList,                        \
  List*:                 listAddBackListListP,                       \
  const volatile List*:  listAddBackListListP,                       \
  Queue:                 listAddBackListQueue,                       \
  Queue*:                listAddBackListQueueP,                      \
  const volatile Queue*: listAddBackListQueueP,                      \
  Stack:                 listAddBackListStack,                       \
  Stack*:                listAddBackListStackP,                      \
  const volatile Stack*: listAddBackListStackP,                      \
  RedBlackTree:          listAddBackListRedBlackTree,                \
  RedBlackTree*:         listAddBackListRedBlackTreeP,               \
  const volatile RedBlackTree*: listAddBackListRedBlackTreeP,               \
  HashTable:             listAddBackListHashTable,                   \
  HashTable*:            listAddBackListHashTableP,                  \
  const volatile HashTable*: listAddBackListHashTableP,                  \
  Vector:                listAddBackListVector,                      \
  Vector*:               listAddBackListVectorP,                     \
  const volatile Vector*: listAddBackListVectorP,                     \
  char*:                 listAddBackListString,                      \
  const volatile char*:  listAddBackListString,                      \
  char**:                listAddBackListStringP,                     \
  const volatile char**: listAddBackListStringP,                     \
  Bytes:                 listAddBackListBytes,                       \
  Bytes*:                listAddBackListBytesP,                      \
  const volatile Bytes*: listAddBackListBytesP,                      \
  void*:                 listAddBackListPointer,                     \
  void**:                listAddBackListPointerP,                    \
  const volatile void**: listAddBackListPointerP,                    \
  i8:                    listAddBackListI8,                          \
  u8:                    listAddBackListU8                           \

#define listAddBackList(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_LIST_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_QUEUE_KEY(dataStructure, key, value) \
  bool:                  listAddBackQueueBool,                       \
  bool*:                 listAddBackQueueBoolP,                      \
  const volatile bool*:  listAddBackQueueBoolP,                      \
  i16:                   listAddBackQueueI16,                        \
  i16*:                  listAddBackQueueI16P,                       \
  const volatile i16*:   listAddBackQueueI16P,                       \
  u16:                   listAddBackQueueU16,                        \
  u16*:                  listAddBackQueueU16P,                       \
  const volatile u16*:   listAddBackQueueU16P,                       \
  i32:                   listAddBackQueueI32,                        \
  i32*:                  listAddBackQueueI32P,                       \
  const volatile i32*:   listAddBackQueueI32P,                       \
  u32:                   listAddBackQueueU32,                        \
  u32*:                  listAddBackQueueU32P,                       \
  const volatile u32*:   listAddBackQueueU32P,                       \
  i64:                   listAddBackQueueI64,                        \
  i64*:                  listAddBackQueueI64P,                       \
  const volatile i64*:   listAddBackQueueI64P,                       \
  u64:                   listAddBackQueueU64,                        \
  u64*:                  listAddBackQueueU64P,                       \
  const volatile u64*:   listAddBackQueueU64P,                       \
  float:                 listAddBackQueueFloat,                      \
  float*:                listAddBackQueueFloatP,                     \
  const volatile float*: listAddBackQueueFloatP,                     \
  double:                listAddBackQueueDouble,                     \
  double*:               listAddBackQueueDoubleP,                    \
  const volatile double*: listAddBackQueueDoubleP,                    \
  long double:           listAddBackQueueLongDouble,                 \
  long double*:          listAddBackQueueLongDoubleP,                \
  const volatile long double*: listAddBackQueueLongDoubleP,                \
  List:                  listAddBackQueueList,                       \
  List*:                 listAddBackQueueListP,                      \
  const volatile List*:  listAddBackQueueListP,                      \
  Queue:                 listAddBackQueueQueue,                      \
  Queue*:                listAddBackQueueQueueP,                     \
  const volatile Queue*: listAddBackQueueQueueP,                     \
  Stack:                 listAddBackQueueStack,                      \
  Stack*:                listAddBackQueueStackP,                     \
  const volatile Stack*: listAddBackQueueStackP,                     \
  RedBlackTree:          listAddBackQueueRedBlackTree,               \
  RedBlackTree*:         listAddBackQueueRedBlackTreeP,              \
  const volatile RedBlackTree*: listAddBackQueueRedBlackTreeP,              \
  HashTable:             listAddBackQueueHashTable,                  \
  HashTable*:            listAddBackQueueHashTableP,                 \
  const volatile HashTable*: listAddBackQueueHashTableP,                 \
  Vector:                listAddBackQueueVector,                     \
  Vector*:               listAddBackQueueVectorP,                    \
  const volatile Vector*: listAddBackQueueVectorP,                    \
  char*:                 listAddBackQueueString,                     \
  const volatile char*:  listAddBackQueueString,                     \
  char**:                listAddBackQueueStringP,                    \
  const volatile char**: listAddBackQueueStringP,                    \
  Bytes:                 listAddBackQueueBytes,                      \
  Bytes*:                listAddBackQueueBytesP,                     \
  const volatile Bytes*: listAddBackQueueBytesP,                     \
  void*:                 listAddBackQueuePointer,                    \
  void**:                listAddBackQueuePointerP,                   \
  const volatile void**: listAddBackQueuePointerP,                   \
  i8:                    listAddBackQueueI8,                         \
  u8:                    listAddBackQueueU8                          \

#define listAddBackQueue(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_QUEUE_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_STACK_KEY(dataStructure, key, value) \
  bool:                  listAddBackStackBool,                       \
  bool*:                 listAddBackStackBoolP,                      \
  const volatile bool*:  listAddBackStackBoolP,                      \
  i16:                   listAddBackStackI16,                        \
  i16*:                  listAddBackStackI16P,                       \
  const volatile i16*:   listAddBackStackI16P,                       \
  u16:                   listAddBackStackU16,                        \
  u16*:                  listAddBackStackU16P,                       \
  const volatile u16*:   listAddBackStackU16P,                       \
  i32:                   listAddBackStackI32,                        \
  i32*:                  listAddBackStackI32P,                       \
  const volatile i32*:   listAddBackStackI32P,                       \
  u32:                   listAddBackStackU32,                        \
  u32*:                  listAddBackStackU32P,                       \
  const volatile u32*:   listAddBackStackU32P,                       \
  i64:                   listAddBackStackI64,                        \
  i64*:                  listAddBackStackI64P,                       \
  const volatile i64*:   listAddBackStackI64P,                       \
  u64:                   listAddBackStackU64,                        \
  u64*:                  listAddBackStackU64P,                       \
  const volatile u64*:   listAddBackStackU64P,                       \
  float:                 listAddBackStackFloat,                      \
  float*:                listAddBackStackFloatP,                     \
  const volatile float*: listAddBackStackFloatP,                     \
  double:                listAddBackStackDouble,                     \
  double*:               listAddBackStackDoubleP,                    \
  const volatile double*: listAddBackStackDoubleP,                    \
  long double:           listAddBackStackLongDouble,                 \
  long double*:          listAddBackStackLongDoubleP,                \
  const volatile long double*: listAddBackStackLongDoubleP,                \
  List:                  listAddBackStackList,                       \
  List*:                 listAddBackStackListP,                      \
  const volatile List*:  listAddBackStackListP,                      \
  Queue:                 listAddBackStackQueue,                      \
  Queue*:                listAddBackStackQueueP,                     \
  const volatile Queue*: listAddBackStackQueueP,                     \
  Stack:                 listAddBackStackStack,                      \
  Stack*:                listAddBackStackStackP,                     \
  const volatile Stack*: listAddBackStackStackP,                     \
  RedBlackTree:          listAddBackStackRedBlackTree,               \
  RedBlackTree*:         listAddBackStackRedBlackTreeP,              \
  const volatile RedBlackTree*: listAddBackStackRedBlackTreeP,              \
  HashTable:             listAddBackStackHashTable,                  \
  HashTable*:            listAddBackStackHashTableP,                 \
  const volatile HashTable*: listAddBackStackHashTableP,                 \
  Vector:                listAddBackStackVector,                     \
  Vector*:               listAddBackStackVectorP,                    \
  const volatile Vector*: listAddBackStackVectorP,                    \
  char*:                 listAddBackStackString,                     \
  const volatile char*:  listAddBackStackString,                     \
  char**:                listAddBackStackStringP,                    \
  const volatile char**: listAddBackStackStringP,                    \
  Bytes:                 listAddBackStackBytes,                      \
  Bytes*:                listAddBackStackBytesP,                     \
  const volatile Bytes*: listAddBackStackBytesP,                     \
  void*:                 listAddBackStackPointer,                    \
  void**:                listAddBackStackPointerP,                   \
  const volatile void**: listAddBackStackPointerP,                   \
  i8:                    listAddBackStackI8,                         \
  u8:                    listAddBackStackU8                          \

#define listAddBackStack(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_STACK_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_RED_BLACK_TREE_KEY(dataStructure, key, value) \
  bool:                  listAddBackRedBlackTreeBool,                \
  bool*:                 listAddBackRedBlackTreeBoolP,               \
  const volatile bool*:  listAddBackRedBlackTreeBoolP,               \
  i16:                   listAddBackRedBlackTreeI16,                 \
  i16*:                  listAddBackRedBlackTreeI16P,                \
  const volatile i16*:   listAddBackRedBlackTreeI16P,                \
  u16:                   listAddBackRedBlackTreeU16,                 \
  u16*:                  listAddBackRedBlackTreeU16P,                \
  const volatile u16*:   listAddBackRedBlackTreeU16P,                \
  i32:                   listAddBackRedBlackTreeI32,                 \
  i32*:                  listAddBackRedBlackTreeI32P,                \
  const volatile i32*:   listAddBackRedBlackTreeI32P,                \
  u32:                   listAddBackRedBlackTreeU32,                 \
  u32*:                  listAddBackRedBlackTreeU32P,                \
  const volatile u32*:   listAddBackRedBlackTreeU32P,                \
  i64:                   listAddBackRedBlackTreeI64,                 \
  i64*:                  listAddBackRedBlackTreeI64P,                \
  const volatile i64*:   listAddBackRedBlackTreeI64P,                \
  u64:                   listAddBackRedBlackTreeU64,                 \
  u64*:                  listAddBackRedBlackTreeU64P,                \
  const volatile u64*:   listAddBackRedBlackTreeU64P,                \
  float:                 listAddBackRedBlackTreeFloat,               \
  float*:                listAddBackRedBlackTreeFloatP,              \
  const volatile float*: listAddBackRedBlackTreeFloatP,              \
  double:                listAddBackRedBlackTreeDouble,              \
  double*:               listAddBackRedBlackTreeDoubleP,             \
  const volatile double*: listAddBackRedBlackTreeDoubleP,             \
  long double:           listAddBackRedBlackTreeLongDouble,          \
  long double*:          listAddBackRedBlackTreeLongDoubleP,         \
  const volatile long double*: listAddBackRedBlackTreeLongDoubleP,         \
  List:                  listAddBackRedBlackTreeList,                \
  List*:                 listAddBackRedBlackTreeListP,               \
  const volatile List*:  listAddBackRedBlackTreeListP,               \
  Queue:                 listAddBackRedBlackTreeQueue,               \
  Queue*:                listAddBackRedBlackTreeQueueP,              \
  const volatile Queue*: listAddBackRedBlackTreeQueueP,              \
  Stack:                 listAddBackRedBlackTreeStack,               \
  Stack*:                listAddBackRedBlackTreeStackP,              \
  const volatile Stack*: listAddBackRedBlackTreeStackP,              \
  RedBlackTree:          listAddBackRedBlackTreeRedBlackTree,        \
  RedBlackTree*:         listAddBackRedBlackTreeRedBlackTreeP,       \
  const volatile RedBlackTree*: listAddBackRedBlackTreeRedBlackTreeP,       \
  HashTable:             listAddBackRedBlackTreeHashTable,           \
  HashTable*:            listAddBackRedBlackTreeHashTableP,          \
  const volatile HashTable*: listAddBackRedBlackTreeHashTableP,          \
  Vector:                listAddBackRedBlackTreeVector,              \
  Vector*:               listAddBackRedBlackTreeVectorP,             \
  const volatile Vector*: listAddBackRedBlackTreeVectorP,             \
  char*:                 listAddBackRedBlackTreeString,              \
  const volatile char*:  listAddBackRedBlackTreeString,              \
  char**:                listAddBackRedBlackTreeStringP,             \
  const volatile char**: listAddBackRedBlackTreeStringP,             \
  Bytes:                 listAddBackRedBlackTreeBytes,               \
  Bytes*:                listAddBackRedBlackTreeBytesP,              \
  const volatile Bytes*: listAddBackRedBlackTreeBytesP,              \
  void*:                 listAddBackRedBlackTreePointer,             \
  void**:                listAddBackRedBlackTreePointerP,            \
  const volatile void**: listAddBackRedBlackTreePointerP,            \
  i8:                    listAddBackRedBlackTreeI8,                  \
  u8:                    listAddBackRedBlackTreeU8                   \

#define listAddBackRedBlackTree(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_RED_BLACK_TREE_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_HASH_TABLE_KEY(dataStructure, key, value) \
  bool:                  listAddBackHashTableBool,                   \
  bool*:                 listAddBackHashTableBoolP,                  \
  const volatile bool*:  listAddBackHashTableBoolP,                  \
  i16:                   listAddBackHashTableI16,                    \
  i16*:                  listAddBackHashTableI16P,                   \
  const volatile i16*:   listAddBackHashTableI16P,                   \
  u16:                   listAddBackHashTableU16,                    \
  u16*:                  listAddBackHashTableU16P,                   \
  const volatile u16*:   listAddBackHashTableU16P,                   \
  i32:                   listAddBackHashTableI32,                    \
  i32*:                  listAddBackHashTableI32P,                   \
  const volatile i32*:   listAddBackHashTableI32P,                   \
  u32:                   listAddBackHashTableU32,                    \
  u32*:                  listAddBackHashTableU32P,                   \
  const volatile u32*:   listAddBackHashTableU32P,                   \
  i64:                   listAddBackHashTableI64,                    \
  i64*:                  listAddBackHashTableI64P,                   \
  const volatile i64*:   listAddBackHashTableI64P,                   \
  u64:                   listAddBackHashTableU64,                    \
  u64*:                  listAddBackHashTableU64P,                   \
  const volatile u64*:   listAddBackHashTableU64P,                   \
  float:                 listAddBackHashTableFloat,                  \
  float*:                listAddBackHashTableFloatP,                 \
  const volatile float*: listAddBackHashTableFloatP,                 \
  double:                listAddBackHashTableDouble,                 \
  double*:               listAddBackHashTableDoubleP,                \
  const volatile double*: listAddBackHashTableDoubleP,                \
  long double:           listAddBackHashTableLongDouble,             \
  long double*:          listAddBackHashTableLongDoubleP,            \
  const volatile long double*: listAddBackHashTableLongDoubleP,            \
  List:                  listAddBackHashTableList,                   \
  List*:                 listAddBackHashTableListP,                  \
  const volatile List*:  listAddBackHashTableListP,                  \
  Queue:                 listAddBackHashTableQueue,                  \
  Queue*:                listAddBackHashTableQueueP,                 \
  const volatile Queue*: listAddBackHashTableQueueP,                 \
  Stack:                 listAddBackHashTableStack,                  \
  Stack*:                listAddBackHashTableStackP,                 \
  const volatile Stack*: listAddBackHashTableStackP,                 \
  RedBlackTree:          listAddBackHashTableRedBlackTree,           \
  RedBlackTree*:         listAddBackHashTableRedBlackTreeP,          \
  const volatile RedBlackTree*: listAddBackHashTableRedBlackTreeP,          \
  HashTable:             listAddBackHashTableHashTable,              \
  HashTable*:            listAddBackHashTableHashTableP,             \
  const volatile HashTable*: listAddBackHashTableHashTableP,             \
  Vector:                listAddBackHashTableVector,                 \
  Vector*:               listAddBackHashTableVectorP,                \
  const volatile Vector*: listAddBackHashTableVectorP,                \
  char*:                 listAddBackHashTableString,                 \
  const volatile char*:  listAddBackHashTableString,                 \
  char**:                listAddBackHashTableStringP,                \
  const volatile char**: listAddBackHashTableStringP,                \
  Bytes:                 listAddBackHashTableBytes,                  \
  Bytes*:                listAddBackHashTableBytesP,                 \
  const volatile Bytes*: listAddBackHashTableBytesP,                 \
  void*:                 listAddBackHashTablePointer,                \
  void**:                listAddBackHashTablePointerP,               \
  const volatile void**: listAddBackHashTablePointerP,               \
  i8:                    listAddBackHashTableI8,                     \
  u8:                    listAddBackHashTableU8                      \

#define listAddBackHashTable(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_HASH_TABLE_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_VECTOR_KEY(dataStructure, key, value) \
  bool:                  listAddBackVectorBool,                      \
  bool*:                 listAddBackVectorBoolP,                     \
  const volatile bool*:  listAddBackVectorBoolP,                     \
  i16:                   listAddBackVectorI16,                       \
  i16*:                  listAddBackVectorI16P,                      \
  const volatile i16*:   listAddBackVectorI16P,                      \
  u16:                   listAddBackVectorU16,                       \
  u16*:                  listAddBackVectorU16P,                      \
  const volatile u16*:   listAddBackVectorU16P,                      \
  i32:                   listAddBackVectorI32,                       \
  i32*:                  listAddBackVectorI32P,                      \
  const volatile i32*:   listAddBackVectorI32P,                      \
  u32:                   listAddBackVectorU32,                       \
  u32*:                  listAddBackVectorU32P,                      \
  const volatile u32*:   listAddBackVectorU32P,                      \
  i64:                   listAddBackVectorI64,                       \
  i64*:                  listAddBackVectorI64P,                      \
  const volatile i64*:   listAddBackVectorI64P,                      \
  u64:                   listAddBackVectorU64,                       \
  u64*:                  listAddBackVectorU64P,                      \
  const volatile u64*:   listAddBackVectorU64P,                      \
  float:                 listAddBackVectorFloat,                     \
  float*:                listAddBackVectorFloatP,                    \
  const volatile float*: listAddBackVectorFloatP,                    \
  double:                listAddBackVectorDouble,                    \
  double*:               listAddBackVectorDoubleP,                   \
  const volatile double*: listAddBackVectorDoubleP,                   \
  long double:           listAddBackVectorLongDouble,                \
  long double*:          listAddBackVectorLongDoubleP,               \
  const volatile long double*: listAddBackVectorLongDoubleP,               \
  List:                  listAddBackVectorList,                      \
  List*:                 listAddBackVectorListP,                     \
  const volatile List*:  listAddBackVectorListP,                     \
  Queue:                 listAddBackVectorQueue,                     \
  Queue*:                listAddBackVectorQueueP,                    \
  const volatile Queue*: listAddBackVectorQueueP,                    \
  Stack:                 listAddBackVectorStack,                     \
  Stack*:                listAddBackVectorStackP,                    \
  const volatile Stack*: listAddBackVectorStackP,                    \
  RedBlackTree:          listAddBackVectorRedBlackTree,              \
  RedBlackTree*:         listAddBackVectorRedBlackTreeP,             \
  const volatile RedBlackTree*: listAddBackVectorRedBlackTreeP,             \
  HashTable:             listAddBackVectorHashTable,                 \
  HashTable*:            listAddBackVectorHashTableP,                \
  const volatile HashTable*: listAddBackVectorHashTableP,                \
  Vector:                listAddBackVectorVector,                    \
  Vector*:               listAddBackVectorVectorP,                   \
  const volatile Vector*: listAddBackVectorVectorP,                   \
  char*:                 listAddBackVectorString,                    \
  const volatile char*:  listAddBackVectorString,                    \
  char**:                listAddBackVectorStringP,                   \
  const volatile char**: listAddBackVectorStringP,                   \
  Bytes:                 listAddBackVectorBytes,                     \
  Bytes*:                listAddBackVectorBytesP,                    \
  const volatile Bytes*: listAddBackVectorBytesP,                    \
  void*:                 listAddBackVectorPointer,                   \
  void**:                listAddBackVectorPointerP,                  \
  const volatile void**: listAddBackVectorPointerP,                  \
  i8:                    listAddBackVectorI8,                        \
  u8:                    listAddBackVectorU8                         \

#define listAddBackVector(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_VECTOR_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_STRING_KEY(dataStructure, key, value) \
  bool:                  listAddBackStringBool,                      \
  const volatile bool:   listAddBackStringBool,                      \
  bool*:                 listAddBackStringBoolP,                     \
  const volatile bool*:  listAddBackStringBoolP,                     \
  i16:                   listAddBackStringI16,                       \
  const volatile i16:    listAddBackStringI16,                       \
  i16*:                  listAddBackStringI16P,                      \
  const volatile i16*:   listAddBackStringI16P,                      \
  u16:                   listAddBackStringU16,                       \
  const volatile u16:    listAddBackStringU16,                       \
  u16*:                  listAddBackStringU16P,                      \
  const volatile u16*:   listAddBackStringU16P,                      \
  i32:                   listAddBackStringI32,                       \
  const volatile i32:    listAddBackStringI32,                       \
  i32*:                  listAddBackStringI32P,                      \
  const volatile i32*:   listAddBackStringI32P,                      \
  u32:                   listAddBackStringU32,                       \
  const volatile u32:    listAddBackStringU32,                       \
  u32*:                  listAddBackStringU32P,                      \
  const volatile u32*:   listAddBackStringU32P,                      \
  i64:                   listAddBackStringI64,                       \
  const volatile i64:    listAddBackStringI64,                       \
  i64*:                  listAddBackStringI64P,                      \
  const volatile i64*:   listAddBackStringI64P,                      \
  u64:                   listAddBackStringU64,                       \
  const volatile u64:    listAddBackStringU64,                       \
  u64*:                  listAddBackStringU64P,                      \
  const volatile u64*:   listAddBackStringU64P,                      \
  float:                 listAddBackStringFloat,                     \
  const volatile float:  listAddBackStringFloat,                     \
  float*:                listAddBackStringFloatP,                    \
  const volatile float*: listAddBackStringFloatP,                    \
  double:                listAddBackStringDouble,                    \
  const volatile double: listAddBackStringDouble,                    \
  double*:               listAddBackStringDoubleP,                   \
  const volatile double*: listAddBackStringDoubleP,                   \
  long double:           listAddBackStringLongDouble,                \
  const volatile long double: listAddBackStringLongDouble,                \
  long double*:          listAddBackStringLongDoubleP,               \
  const volatile long double*: listAddBackStringLongDoubleP,               \
  List:                  listAddBackStringList,                      \
  const volatile List:   listAddBackStringList,                      \
  List*:                 listAddBackStringListP,                     \
  const volatile List*:  listAddBackStringListP,                     \
  Queue:                 listAddBackStringQueue,                     \
  const volatile Queue:  listAddBackStringQueue,                     \
  Queue*:                listAddBackStringQueueP,                    \
  const volatile Queue*: listAddBackStringQueueP,                    \
  Stack:                 listAddBackStringStack,                     \
  const volatile Stack:  listAddBackStringStack,                     \
  Stack*:                listAddBackStringStackP,                    \
  const volatile Stack*: listAddBackStringStackP,                    \
  RedBlackTree:          listAddBackStringRedBlackTree,              \
  const volatile RedBlackTree: listAddBackStringRedBlackTree,              \
  RedBlackTree*:         listAddBackStringRedBlackTreeP,             \
  const volatile RedBlackTree*: listAddBackStringRedBlackTreeP,             \
  HashTable:             listAddBackStringHashTable,                 \
  const volatile HashTable: listAddBackStringHashTable,                 \
  HashTable*:            listAddBackStringHashTableP,                \
  const volatile HashTable*: listAddBackStringHashTableP,                \
  Vector:                listAddBackStringVector,                    \
  const volatile Vector: listAddBackStringVector,                    \
  Vector*:               listAddBackStringVectorP,                   \
  const volatile Vector*: listAddBackStringVectorP,                   \
  char*:                 listAddBackStringString,                    \
  const volatile char*:  listAddBackStringString,                    \
  char**:                listAddBackStringStringP,                   \
  const volatile char**: listAddBackStringStringP,                   \
  Bytes:                 listAddBackStringBytes,                     \
  Bytes*:                listAddBackStringBytesP,                    \
  const volatile Bytes*: listAddBackStringBytesP,                    \
  void*:                 listAddBackStringPointer,                   \
  void**:                listAddBackStringPointerP,                  \
  const volatile void**: listAddBackStringPointerP,                  \
  i8:                    listAddBackStringI8,                        \
  u8:                    listAddBackStringU8                         \

#define listAddBackString(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_STRING_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_BYTES_KEY(dataStructure, key, value) \
  bool:                  listAddBackBytesBool,                       \
  bool*:                 listAddBackBytesBoolP,                      \
  const volatile bool*:  listAddBackBytesBoolP,                      \
  i16:                   listAddBackBytesI16,                        \
  i16*:                  listAddBackBytesI16P,                       \
  const volatile i16*:   listAddBackBytesI16P,                       \
  u16:                   listAddBackBytesU16,                        \
  u16*:                  listAddBackBytesU16P,                       \
  const volatile u16*:   listAddBackBytesU16P,                       \
  i32:                   listAddBackBytesI32,                        \
  i32*:                  listAddBackBytesI32P,                       \
  const volatile i32*:   listAddBackBytesI32P,                       \
  u32:                   listAddBackBytesU32,                        \
  u32*:                  listAddBackBytesU32P,                       \
  const volatile u32*:   listAddBackBytesU32P,                       \
  i64:                   listAddBackBytesI64,                        \
  i64*:                  listAddBackBytesI64P,                       \
  const volatile i64*:   listAddBackBytesI64P,                       \
  u64:                   listAddBackBytesU64,                        \
  u64*:                  listAddBackBytesU64P,                       \
  const volatile u64*:   listAddBackBytesU64P,                       \
  float:                 listAddBackBytesFloat,                      \
  float*:                listAddBackBytesFloatP,                     \
  const volatile float*: listAddBackBytesFloatP,                     \
  double:                listAddBackBytesDouble,                     \
  double*:               listAddBackBytesDoubleP,                    \
  const volatile double*: listAddBackBytesDoubleP,                    \
  long double:           listAddBackBytesLongDouble,                 \
  long double*:          listAddBackBytesLongDoubleP,                \
  const volatile long double*: listAddBackBytesLongDoubleP,                \
  List:                  listAddBackBytesList,                       \
  List*:                 listAddBackBytesListP,                      \
  const volatile List*:  listAddBackBytesListP,                      \
  Queue:                 listAddBackBytesQueue,                      \
  Queue*:                listAddBackBytesQueueP,                     \
  const volatile Queue*: listAddBackBytesQueueP,                     \
  Stack:                 listAddBackBytesStack,                      \
  Stack*:                listAddBackBytesStackP,                     \
  const volatile Stack*: listAddBackBytesStackP,                     \
  RedBlackTree:          listAddBackBytesRedBlackTree,               \
  RedBlackTree*:         listAddBackBytesRedBlackTreeP,              \
  const volatile RedBlackTree*: listAddBackBytesRedBlackTreeP,              \
  HashTable:             listAddBackBytesHashTable,                  \
  HashTable*:            listAddBackBytesHashTableP,                 \
  const volatile HashTable*: listAddBackBytesHashTableP,                 \
  Vector:                listAddBackBytesVector,                     \
  Vector*:               listAddBackBytesVectorP,                    \
  const volatile Vector*: listAddBackBytesVectorP,                    \
  char*:                 listAddBackBytesString,                     \
  const volatile char*:  listAddBackBytesString,                     \
  char**:                listAddBackBytesStringP,                    \
  const volatile char**: listAddBackBytesStringP,                    \
  Bytes:                 listAddBackBytesBytes,                      \
  Bytes*:                listAddBackBytesBytesP,                     \
  const volatile Bytes*: listAddBackBytesBytesP,                     \
  void*:                 listAddBackBytesPointer,                    \
  void**:                listAddBackBytesPointerP,                   \
  const volatile void**: listAddBackBytesPointerP,                   \
  i8:                    listAddBackBytesI8,                         \
  u8:                    listAddBackBytesU8                          \

#define listAddBackBytes(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_BYTES_KEY(dataStructure, key, value) \
  )


#define LIST_ADD_BACK_GENERIC_CASES_POINTER_KEY(dataStructure, key, value) \
  bool:                  listAddBackPointerBool,                     \
  bool*:                 listAddBackPointerBoolP,                    \
  const volatile bool*:  listAddBackPointerBoolP,                    \
  i16:                   listAddBackPointerI16,                      \
  i16*:                  listAddBackPointerI16P,                     \
  const volatile i16*:   listAddBackPointerI16P,                     \
  u16:                   listAddBackPointerU16,                      \
  u16*:                  listAddBackPointerU16P,                     \
  const volatile u16*:   listAddBackPointerU16P,                     \
  i32:                   listAddBackPointerI32,                      \
  i32*:                  listAddBackPointerI32P,                     \
  const volatile i32*:   listAddBackPointerI32P,                     \
  u32:                   listAddBackPointerU32,                      \
  u32*:                  listAddBackPointerU32P,                     \
  const volatile u32*:   listAddBackPointerU32P,                     \
  i64:                   listAddBackPointerI64,                      \
  i64*:                  listAddBackPointerI64P,                     \
  const volatile i64*:   listAddBackPointerI64P,                     \
  u64:                   listAddBackPointerU64,                      \
  u64*:                  listAddBackPointerU64P,                     \
  const volatile u64*:   listAddBackPointerU64P,                     \
  float:                 listAddBackPointerFloat,                    \
  float*:                listAddBackPointerFloatP,                   \
  const volatile float*: listAddBackPointerFloatP,                   \
  double:                listAddBackPointerDouble,                   \
  double*:               listAddBackPointerDoubleP,                  \
  const volatile double*: listAddBackPointerDoubleP,                  \
  long double:           listAddBackPointerLongDouble,               \
  long double*:          listAddBackPointerLongDoubleP,              \
  const volatile long double*: listAddBackPointerLongDoubleP,              \
  List:                  listAddBackPointerList,                     \
  List*:                 listAddBackPointerListP,                    \
  const volatile List*:  listAddBackPointerListP,                    \
  Queue:                 listAddBackPointerQueue,                    \
  Queue*:                listAddBackPointerQueueP,                   \
  const volatile Queue*: listAddBackPointerQueueP,                   \
  Stack:                 listAddBackPointerStack,                    \
  Stack*:                listAddBackPointerStackP,                   \
  const volatile Stack*: listAddBackPointerStackP,                   \
  RedBlackTree:          listAddBackPointerRedBlackTree,             \
  RedBlackTree*:         listAddBackPointerRedBlackTreeP,            \
  const volatile RedBlackTree*: listAddBackPointerRedBlackTreeP,            \
  HashTable:             listAddBackPointerHashTable,                \
  HashTable*:            listAddBackPointerHashTableP,               \
  const volatile HashTable*: listAddBackPointerHashTableP,               \
  Vector:                listAddBackPointerVector,                   \
  Vector*:               listAddBackPointerVectorP,                  \
  const volatile Vector*: listAddBackPointerVectorP,                  \
  char*:                 listAddBackPointerString,                   \
  const volatile char*:  listAddBackPointerString,                   \
  char**:                listAddBackPointerStringP,                  \
  const volatile char**: listAddBackPointerStringP,                  \
  Bytes:                 listAddBackPointerBytes,                    \
  Bytes*:                listAddBackPointerBytesP,                   \
  const volatile Bytes*: listAddBackPointerBytesP,                   \
  void*:                 listAddBackPointerPointer,                  \
  void**:                listAddBackPointerPointerP,                 \
  const volatile void**: listAddBackPointerPointerP,                 \
  i8:                    listAddBackPointerI8,                       \
  u8:                    listAddBackPointerU8                        \

#define listAddBackPointer(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_POINTER_KEY(dataStructure, key, value) \
  )


#define LIST_ADD_BACK_GENERIC_CASES_I8_KEY(dataStructure, key, value) \
  bool:                  listAddBackI8Bool,                          \
  bool*:                 listAddBackI8BoolP,                         \
  const volatile bool*:  listAddBackI8BoolP,                         \
  i16:                   listAddBackI8I16,                           \
  i16*:                  listAddBackI8I16P,                          \
  const volatile i16*:   listAddBackI8I16P,                          \
  u16:                   listAddBackI8U16,                           \
  u16*:                  listAddBackI8U16P,                          \
  const volatile u16*:   listAddBackI8U16P,                          \
  i32:                   listAddBackI8I32,                           \
  i32*:                  listAddBackI8I32P,                          \
  const volatile i32*:   listAddBackI8I32P,                          \
  u32:                   listAddBackI8U32,                           \
  u32*:                  listAddBackI8U32P,                          \
  const volatile u32*:   listAddBackI8U32P,                          \
  i64:                   listAddBackI8I64,                           \
  i64*:                  listAddBackI8I64P,                          \
  const volatile i64*:   listAddBackI8I64P,                          \
  u64:                   listAddBackI8U64,                           \
  u64*:                  listAddBackI8U64P,                          \
  const volatile u64*:   listAddBackI8U64P,                          \
  float:                 listAddBackI8Float,                         \
  float*:                listAddBackI8FloatP,                        \
  const volatile float*: listAddBackI8FloatP,                        \
  double:                listAddBackI8Double,                        \
  double*:               listAddBackI8DoubleP,                       \
  const volatile double*: listAddBackI8DoubleP,                       \
  long double:           listAddBackI8LongDouble,                    \
  long double*:          listAddBackI8LongDoubleP,                   \
  const volatile long double*: listAddBackI8LongDoubleP,                   \
  List:                  listAddBackI8List,                          \
  List*:                 listAddBackI8ListP,                         \
  const volatile List*:  listAddBackI8ListP,                         \
  Queue:                 listAddBackI8Queue,                         \
  Queue*:                listAddBackI8QueueP,                        \
  const volatile Queue*: listAddBackI8QueueP,                        \
  Stack:                 listAddBackI8Stack,                         \
  Stack*:                listAddBackI8StackP,                        \
  const volatile Stack*: listAddBackI8StackP,                        \
  RedBlackTree:          listAddBackI8RedBlackTree,                  \
  RedBlackTree*:         listAddBackI8RedBlackTreeP,                 \
  const volatile RedBlackTree*: listAddBackI8RedBlackTreeP,                 \
  HashTable:             listAddBackI8HashTable,                     \
  HashTable*:            listAddBackI8HashTableP,                    \
  const volatile HashTable*: listAddBackI8HashTableP,                    \
  Vector:                listAddBackI8Vector,                        \
  Vector*:               listAddBackI8VectorP,                       \
  const volatile Vector*: listAddBackI8VectorP,                       \
  char*:                 listAddBackI8String,                        \
  const volatile char*:  listAddBackI8String,                        \
  char**:                listAddBackI8StringP,                       \
  const volatile char**: listAddBackI8StringP,                       \
  Bytes:                 listAddBackI8Bytes,                         \
  Bytes*:                listAddBackI8BytesP,                        \
  const volatile Bytes*: listAddBackI8BytesP,                        \
  void*:                 listAddBackI8Pointer,                       \
  void**:                listAddBackI8PointerP,                      \
  const volatile void**: listAddBackI8PointerP,                      \
  i8:                    listAddBackI8I8,                            \
  u8:                    listAddBackI8U8                             \

#define listAddBackI8(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_I8_KEY(dataStructure, key, value) \
  )


#define LIST_ADD_BACK_GENERIC_CASES_U8_KEY(dataStructure, key, value) \
  bool:                  listAddBackU8Bool,                          \
  bool*:                 listAddBackU8BoolP,                         \
  const volatile bool*:  listAddBackU8BoolP,                         \
  i16:                   listAddBackU8I16,                           \
  i16*:                  listAddBackU8I16P,                          \
  const volatile i16*:   listAddBackU8I16P,                          \
  u16:                   listAddBackU8U16,                           \
  u16*:                  listAddBackU8U16P,                          \
  const volatile u16*:   listAddBackU8U16P,                          \
  i32:                   listAddBackU8I32,                           \
  i32*:                  listAddBackU8I32P,                          \
  const volatile i32*:   listAddBackU8I32P,                          \
  u32:                   listAddBackU8U32,                           \
  u32*:                  listAddBackU8U32P,                          \
  const volatile u32*:   listAddBackU8U32P,                          \
  i64:                   listAddBackU8I64,                           \
  i64*:                  listAddBackU8I64P,                          \
  const volatile i64*:   listAddBackU8I64P,                          \
  u64:                   listAddBackU8U64,                           \
  u64*:                  listAddBackU8U64P,                          \
  const volatile u64*:   listAddBackU8U64P,                          \
  float:                 listAddBackU8Float,                         \
  float*:                listAddBackU8FloatP,                        \
  const volatile float*: listAddBackU8FloatP,                        \
  double:                listAddBackU8Double,                        \
  double*:               listAddBackU8DoubleP,                       \
  const volatile double*: listAddBackU8DoubleP,                       \
  long double:           listAddBackU8LongDouble,                    \
  long double*:          listAddBackU8LongDoubleP,                   \
  const volatile long double*: listAddBackU8LongDoubleP,                   \
  List:                  listAddBackU8List,                          \
  List*:                 listAddBackU8ListP,                         \
  const volatile List*:  listAddBackU8ListP,                         \
  Queue:                 listAddBackU8Queue,                         \
  Queue*:                listAddBackU8QueueP,                        \
  const volatile Queue*: listAddBackU8QueueP,                        \
  Stack:                 listAddBackU8Stack,                         \
  Stack*:                listAddBackU8StackP,                        \
  const volatile Stack*: listAddBackU8StackP,                        \
  RedBlackTree:          listAddBackU8RedBlackTree,                  \
  RedBlackTree*:         listAddBackU8RedBlackTreeP,                 \
  const volatile RedBlackTree*: listAddBackU8RedBlackTreeP,                 \
  HashTable:             listAddBackU8HashTable,                     \
  HashTable*:            listAddBackU8HashTableP,                    \
  const volatile HashTable*: listAddBackU8HashTableP,                    \
  Vector:                listAddBackU8Vector,                        \
  Vector*:               listAddBackU8VectorP,                       \
  const volatile Vector*: listAddBackU8VectorP,                       \
  char*:                 listAddBackU8String,                        \
  const volatile char*:  listAddBackU8String,                        \
  char**:                listAddBackU8StringP,                       \
  const volatile char**: listAddBackU8StringP,                       \
  Bytes:                 listAddBackU8Bytes,                         \
  Bytes*:                listAddBackU8BytesP,                        \
  const volatile Bytes*: listAddBackU8BytesP,                        \
  void*:                 listAddBackU8Pointer,                       \
  void**:                listAddBackU8PointerP,                      \
  const volatile void**: listAddBackU8PointerP,                      \
  i8:                    listAddBackU8I8,                            \
  u8:                    listAddBackU8U8                             \

#define listAddBackU8(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_U8_KEY(dataStructure, key, value) \
  )


#define LIST_ADD_BACK_GENERIC_CASES_BOOLP_KEY(dataStructure, key, value) \
  bool:                  listAddBackBoolPBool,                       \
  bool*:                 listAddBackBoolPBoolP,                      \
  const volatile bool*:  listAddBackBoolPBoolP,                      \
  i16:                   listAddBackBoolPI16,                        \
  i16*:                  listAddBackBoolPI16P,                       \
  const volatile i16*:   listAddBackBoolPI16P,                       \
  u16:                   listAddBackBoolPU16,                        \
  u16*:                  listAddBackBoolPU16P,                       \
  const volatile u16*:   listAddBackBoolPU16P,                       \
  i32:                   listAddBackBoolPI32,                        \
  i32*:                  listAddBackBoolPI32P,                       \
  const volatile i32*:   listAddBackBoolPI32P,                       \
  u32:                   listAddBackBoolPU32,                        \
  u32*:                  listAddBackBoolPU32P,                       \
  const volatile u32*:   listAddBackBoolPU32P,                       \
  i64:                   listAddBackBoolPI64,                        \
  i64*:                  listAddBackBoolPI64P,                       \
  const volatile i64*:   listAddBackBoolPI64P,                       \
  u64:                   listAddBackBoolPU64,                        \
  u64*:                  listAddBackBoolPU64P,                       \
  const volatile u64*:   listAddBackBoolPU64P,                       \
  float:                 listAddBackBoolPFloat,                      \
  float*:                listAddBackBoolPFloatP,                     \
  const volatile float*: listAddBackBoolPFloatP,                     \
  double:                listAddBackBoolPDouble,                     \
  double*:               listAddBackBoolPDoubleP,                    \
  const volatile double*: listAddBackBoolPDoubleP,                    \
  long double:           listAddBackBoolPLongDouble,                 \
  long double*:          listAddBackBoolPLongDoubleP,                \
  const volatile long double*: listAddBackBoolPLongDoubleP,                \
  List:                  listAddBackBoolPList,                       \
  List*:                 listAddBackBoolPListP,                      \
  const volatile List*:  listAddBackBoolPListP,                      \
  Queue:                 listAddBackBoolPQueue,                      \
  Queue*:                listAddBackBoolPQueueP,                     \
  const volatile Queue*: listAddBackBoolPQueueP,                     \
  Stack:                 listAddBackBoolPStack,                      \
  Stack*:                listAddBackBoolPStackP,                     \
  const volatile Stack*: listAddBackBoolPStackP,                     \
  RedBlackTree:          listAddBackBoolPRedBlackTree,               \
  RedBlackTree*:         listAddBackBoolPRedBlackTreeP,              \
  const volatile RedBlackTree*: listAddBackBoolPRedBlackTreeP,              \
  HashTable:             listAddBackBoolPHashTable,                  \
  HashTable*:            listAddBackBoolPHashTableP,                 \
  const volatile HashTable*: listAddBackBoolPHashTableP,                 \
  Vector:                listAddBackBoolPVector,                     \
  Vector*:               listAddBackBoolPVectorP,                    \
  const volatile Vector*: listAddBackBoolPVectorP,                    \
  char*:                 listAddBackBoolPString,                     \
  const volatile char*:  listAddBackBoolPString,                     \
  char**:                listAddBackBoolPStringP,                    \
  const volatile char**: listAddBackBoolPStringP,                    \
  Bytes:                 listAddBackBoolPBytes,                      \
  Bytes*:                listAddBackBoolPBytesP,                     \
  const volatile Bytes*: listAddBackBoolPBytesP,                     \
  void*:                 listAddBackBoolPPointer,                    \
  void**:                listAddBackBoolPPointerP,                   \
  const volatile void**: listAddBackBoolPPointerP,                   \
  i8:                    listAddBackBoolI8,                          \
  u8:                    listAddBackBoolU8                           \

#define listAddBackBoolP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_BOOLP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_I16P_KEY(dataStructure, key, value) \
  bool:                  listAddBackI16PBool,                        \
  bool*:                 listAddBackI16PBoolP,                       \
  const volatile bool*:  listAddBackI16PBoolP,                       \
  i16:                   listAddBackI16PI16,                         \
  i16*:                  listAddBackI16PI16P,                        \
  const volatile i16*:   listAddBackI16PI16P,                        \
  u16:                   listAddBackI16PU16,                         \
  u16*:                  listAddBackI16PU16P,                        \
  const volatile u16*:   listAddBackI16PU16P,                        \
  i32:                   listAddBackI16PI32,                         \
  i32*:                  listAddBackI16PI32P,                        \
  const volatile i32*:   listAddBackI16PI32P,                        \
  u32:                   listAddBackI16PU32,                         \
  u32*:                  listAddBackI16PU32P,                        \
  const volatile u32*:   listAddBackI16PU32P,                        \
  i64:                   listAddBackI16PI64,                         \
  i64*:                  listAddBackI16PI64P,                        \
  const volatile i64*:   listAddBackI16PI64P,                        \
  u64:                   listAddBackI16PU64,                         \
  u64*:                  listAddBackI16PU64P,                        \
  const volatile u64*:   listAddBackI16PU64P,                        \
  float:                 listAddBackI16PFloat,                       \
  float*:                listAddBackI16PFloatP,                      \
  const volatile float*: listAddBackI16PFloatP,                      \
  double:                listAddBackI16PDouble,                      \
  double*:               listAddBackI16PDoubleP,                     \
  const volatile double*: listAddBackI16PDoubleP,                     \
  long double:           listAddBackI16PLongDouble,                  \
  long double*:          listAddBackI16PLongDoubleP,                 \
  const volatile long double*: listAddBackI16PLongDoubleP,                 \
  List:                  listAddBackI16PList,                        \
  List*:                 listAddBackI16PListP,                       \
  const volatile List*:  listAddBackI16PListP,                       \
  Queue:                 listAddBackI16PQueue,                       \
  Queue*:                listAddBackI16PQueueP,                      \
  const volatile Queue*: listAddBackI16PQueueP,                      \
  Stack:                 listAddBackI16PStack,                       \
  Stack*:                listAddBackI16PStackP,                      \
  const volatile Stack*: listAddBackI16PStackP,                      \
  RedBlackTree:          listAddBackI16PRedBlackTree,                \
  RedBlackTree*:         listAddBackI16PRedBlackTreeP,               \
  const volatile RedBlackTree*: listAddBackI16PRedBlackTreeP,               \
  HashTable:             listAddBackI16PHashTable,                   \
  HashTable*:            listAddBackI16PHashTableP,                  \
  const volatile HashTable*: listAddBackI16PHashTableP,                  \
  Vector:                listAddBackI16PVector,                      \
  Vector*:               listAddBackI16PVectorP,                     \
  const volatile Vector*: listAddBackI16PVectorP,                     \
  char*:                 listAddBackI16PString,                      \
  const volatile char*:  listAddBackI16PString,                      \
  char**:                listAddBackI16PStringP,                     \
  const volatile char**: listAddBackI16PStringP,                     \
  Bytes:                 listAddBackI16PBytes,                       \
  Bytes*:                listAddBackI16PBytesP,                      \
  const volatile Bytes*: listAddBackI16PBytesP,                      \
  void*:                 listAddBackI16PPointer,                     \
  void**:                listAddBackI16PPointerP,                    \
  const volatile void**: listAddBackI16PPointerP,                    \
  i8:                    listAddBackI16I8,                           \
  u8:                    listAddBackI16U8                            \

#define listAddBackI16P(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_I16P_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_U16P_KEY(dataStructure, key, value) \
  bool:                  listAddBackU16PBool,                        \
  bool*:                 listAddBackU16PBoolP,                       \
  const volatile bool*:  listAddBackU16PBoolP,                       \
  i16:                   listAddBackU16PI16,                         \
  i16*:                  listAddBackU16PI16P,                        \
  const volatile i16*:   listAddBackU16PI16P,                        \
  u16:                   listAddBackU16PU16,                         \
  u16*:                  listAddBackU16PU16P,                        \
  const volatile u16*:   listAddBackU16PU16P,                        \
  i32:                   listAddBackU16PI32,                         \
  i32*:                  listAddBackU16PI32P,                        \
  const volatile i32*:   listAddBackU16PI32P,                        \
  u32:                   listAddBackU16PU32,                         \
  u32*:                  listAddBackU16PU32P,                        \
  const volatile u32*:   listAddBackU16PU32P,                        \
  i64:                   listAddBackU16PI64,                         \
  i64*:                  listAddBackU16PI64P,                        \
  const volatile i64*:   listAddBackU16PI64P,                        \
  u64:                   listAddBackU16PU64,                         \
  u64*:                  listAddBackU16PU64P,                        \
  const volatile u64*:   listAddBackU16PU64P,                        \
  float:                 listAddBackU16PFloat,                       \
  float*:                listAddBackU16PFloatP,                      \
  const volatile float*: listAddBackU16PFloatP,                      \
  double:                listAddBackU16PDouble,                      \
  double*:               listAddBackU16PDoubleP,                     \
  const volatile double*: listAddBackU16PDoubleP,                     \
  long double:           listAddBackU16PLongDouble,                  \
  long double*:          listAddBackU16PLongDoubleP,                 \
  const volatile long double*: listAddBackU16PLongDoubleP,                 \
  List:                  listAddBackU16PList,                        \
  List*:                 listAddBackU16PListP,                       \
  const volatile List*:  listAddBackU16PListP,                       \
  Queue:                 listAddBackU16PQueue,                       \
  Queue*:                listAddBackU16PQueueP,                      \
  const volatile Queue*: listAddBackU16PQueueP,                      \
  Stack:                 listAddBackU16PStack,                       \
  Stack*:                listAddBackU16PStackP,                      \
  const volatile Stack*: listAddBackU16PStackP,                      \
  RedBlackTree:          listAddBackU16PRedBlackTree,                \
  RedBlackTree*:         listAddBackU16PRedBlackTreeP,               \
  const volatile RedBlackTree*: listAddBackU16PRedBlackTreeP,               \
  HashTable:             listAddBackU16PHashTable,                   \
  HashTable*:            listAddBackU16PHashTableP,                  \
  const volatile HashTable*: listAddBackU16PHashTableP,                  \
  Vector:                listAddBackU16PVector,                      \
  Vector*:               listAddBackU16PVectorP,                     \
  const volatile Vector*: listAddBackU16PVectorP,                     \
  char*:                 listAddBackU16PString,                      \
  const volatile char*:  listAddBackU16PString,                      \
  char**:                listAddBackU16PStringP,                     \
  const volatile char**: listAddBackU16PStringP,                     \
  Bytes:                 listAddBackU16PBytes,                       \
  Bytes*:                listAddBackU16PBytesP,                      \
  const volatile Bytes*: listAddBackU16PBytesP,                      \
  void*:                 listAddBackU16PPointer,                     \
  void**:                listAddBackU16PPointerP,                    \
  const volatile void**: listAddBackU16PPointerP,                    \
  i8:                    listAddBackU16I8,                           \
  u8:                    listAddBackU16U8                            \

#define listAddBackU16P(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_U16P_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_I32P_KEY(dataStructure, key, value) \
  bool:                  listAddBackI32PBool,                        \
  bool*:                 listAddBackI32PBoolP,                       \
  const volatile bool*:  listAddBackI32PBoolP,                       \
  i16:                   listAddBackI32PI16,                         \
  i16*:                  listAddBackI32PI16P,                        \
  const volatile i16*:   listAddBackI32PI16P,                        \
  u16:                   listAddBackI32PU16,                         \
  u16*:                  listAddBackI32PU16P,                        \
  const volatile u16*:   listAddBackI32PU16P,                        \
  i32:                   listAddBackI32PI32,                         \
  i32*:                  listAddBackI32PI32P,                        \
  const volatile i32*:   listAddBackI32PI32P,                        \
  u32:                   listAddBackI32PU32,                         \
  u32*:                  listAddBackI32PU32P,                        \
  const volatile u32*:   listAddBackI32PU32P,                        \
  i64:                   listAddBackI32PI64,                         \
  i64*:                  listAddBackI32PI64P,                        \
  const volatile i64*:   listAddBackI32PI64P,                        \
  u64:                   listAddBackI32PU64,                         \
  u64*:                  listAddBackI32PU64P,                        \
  const volatile u64*:   listAddBackI32PU64P,                        \
  float:                 listAddBackI32PFloat,                       \
  float*:                listAddBackI32PFloatP,                      \
  const volatile float*: listAddBackI32PFloatP,                      \
  double:                listAddBackI32PDouble,                      \
  double*:               listAddBackI32PDoubleP,                     \
  const volatile double*: listAddBackI32PDoubleP,                     \
  long double:           listAddBackI32PLongDouble,                  \
  long double*:          listAddBackI32PLongDoubleP,                 \
  const volatile long double*: listAddBackI32PLongDoubleP,                 \
  List:                  listAddBackI32PList,                        \
  List*:                 listAddBackI32PListP,                       \
  const volatile List*:  listAddBackI32PListP,                       \
  Queue:                 listAddBackI32PQueue,                       \
  Queue*:                listAddBackI32PQueueP,                      \
  const volatile Queue*: listAddBackI32PQueueP,                      \
  Stack:                 listAddBackI32PStack,                       \
  Stack*:                listAddBackI32PStackP,                      \
  const volatile Stack*: listAddBackI32PStackP,                      \
  RedBlackTree:          listAddBackI32PRedBlackTree,                \
  RedBlackTree*:         listAddBackI32PRedBlackTreeP,               \
  const volatile RedBlackTree*: listAddBackI32PRedBlackTreeP,               \
  HashTable:             listAddBackI32PHashTable,                   \
  HashTable*:            listAddBackI32PHashTableP,                  \
  const volatile HashTable*: listAddBackI32PHashTableP,                  \
  Vector:                listAddBackI32PVector,                      \
  Vector*:               listAddBackI32PVectorP,                     \
  const volatile Vector*: listAddBackI32PVectorP,                     \
  char*:                 listAddBackI32PString,                      \
  const volatile char*:  listAddBackI32PString,                      \
  char**:                listAddBackI32PStringP,                     \
  const volatile char**: listAddBackI32PStringP,                     \
  Bytes:                 listAddBackI32PBytes,                       \
  Bytes*:                listAddBackI32PBytesP,                      \
  const volatile Bytes*: listAddBackI32PBytesP,                      \
  void*:                 listAddBackI32PPointer,                     \
  void**:                listAddBackI32PPointerP,                    \
  const volatile void**: listAddBackI32PPointerP,                    \
  i8:                    listAddBackI32I8,                           \
  u8:                    listAddBackI32U8                            \

#define listAddBackI32P(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_I32P_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_U32P_KEY(dataStructure, key, value) \
  bool:                  listAddBackU32PBool,                        \
  bool*:                 listAddBackU32PBoolP,                       \
  const volatile bool*:  listAddBackU32PBoolP,                       \
  i16:                   listAddBackU32PI16,                         \
  i16*:                  listAddBackU32PI16P,                        \
  const volatile i16*:   listAddBackU32PI16P,                        \
  u16:                   listAddBackU32PU16,                         \
  u16*:                  listAddBackU32PU16P,                        \
  const volatile u16*:   listAddBackU32PU16P,                        \
  i32:                   listAddBackU32PI32,                         \
  i32*:                  listAddBackU32PI32P,                        \
  const volatile i32*:   listAddBackU32PI32P,                        \
  u32:                   listAddBackU32PU32,                         \
  u32*:                  listAddBackU32PU32P,                        \
  const volatile u32*:   listAddBackU32PU32P,                        \
  i64:                   listAddBackU32PI64,                         \
  i64*:                  listAddBackU32PI64P,                        \
  const volatile i64*:   listAddBackU32PI64P,                        \
  u64:                   listAddBackU32PU64,                         \
  u64*:                  listAddBackU32PU64P,                        \
  const volatile u64*:   listAddBackU32PU64P,                        \
  float:                 listAddBackU32PFloat,                       \
  float*:                listAddBackU32PFloatP,                      \
  const volatile float*: listAddBackU32PFloatP,                      \
  double:                listAddBackU32PDouble,                      \
  double*:               listAddBackU32PDoubleP,                     \
  const volatile double*: listAddBackU32PDoubleP,                     \
  long double:           listAddBackU32PLongDouble,                  \
  long double*:          listAddBackU32PLongDoubleP,                 \
  const volatile long double*: listAddBackU32PLongDoubleP,                 \
  List:                  listAddBackU32PList,                        \
  List*:                 listAddBackU32PListP,                       \
  const volatile List*:  listAddBackU32PListP,                       \
  Queue:                 listAddBackU32PQueue,                       \
  Queue*:                listAddBackU32PQueueP,                      \
  const volatile Queue*: listAddBackU32PQueueP,                      \
  Stack:                 listAddBackU32PStack,                       \
  Stack*:                listAddBackU32PStackP,                      \
  const volatile Stack*: listAddBackU32PStackP,                      \
  RedBlackTree:          listAddBackU32PRedBlackTree,                \
  RedBlackTree*:         listAddBackU32PRedBlackTreeP,               \
  const volatile RedBlackTree*: listAddBackU32PRedBlackTreeP,               \
  HashTable:             listAddBackU32PHashTable,                   \
  HashTable*:            listAddBackU32PHashTableP,                  \
  const volatile HashTable*: listAddBackU32PHashTableP,                  \
  Vector:                listAddBackU32PVector,                      \
  Vector*:               listAddBackU32PVectorP,                     \
  const volatile Vector*: listAddBackU32PVectorP,                     \
  char*:                 listAddBackU32PString,                      \
  const volatile char*:  listAddBackU32PString,                      \
  char**:                listAddBackU32PStringP,                     \
  const volatile char**: listAddBackU32PStringP,                     \
  Bytes:                 listAddBackU32PBytes,                       \
  Bytes*:                listAddBackU32PBytesP,                      \
  const volatile Bytes*: listAddBackU32PBytesP,                      \
  void*:                 listAddBackU32PPointer,                     \
  void**:                listAddBackU32PPointerP,                    \
  const volatile void**: listAddBackU32PPointerP,                    \
  i8:                    listAddBackU32I8,                           \
  u8:                    listAddBackU32U8                            \

#define listAddBackU32P(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_U32P_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_I64P_KEY(dataStructure, key, value) \
  bool:                  listAddBackI64PBool,                        \
  bool*:                 listAddBackI64PBoolP,                       \
  const volatile bool*:  listAddBackI64PBoolP,                       \
  i16:                   listAddBackI64PI16,                         \
  i16*:                  listAddBackI64PI16P,                        \
  const volatile i16*:   listAddBackI64PI16P,                        \
  u16:                   listAddBackI64PU16,                         \
  u16*:                  listAddBackI64PU16P,                        \
  const volatile u16*:   listAddBackI64PU16P,                        \
  i32:                   listAddBackI64PI32,                         \
  i32*:                  listAddBackI64PI32P,                        \
  const volatile i32*:   listAddBackI64PI32P,                        \
  u32:                   listAddBackI64PU32,                         \
  u32*:                  listAddBackI64PU32P,                        \
  const volatile u32*:   listAddBackI64PU32P,                        \
  i64:                   listAddBackI64PI64,                         \
  i64*:                  listAddBackI64PI64P,                        \
  const volatile i64*:   listAddBackI64PI64P,                        \
  u64:                   listAddBackI64PU64,                         \
  u64*:                  listAddBackI64PU64P,                        \
  const volatile u64*:   listAddBackI64PU64P,                        \
  float:                 listAddBackI64PFloat,                       \
  float*:                listAddBackI64PFloatP,                      \
  const volatile float*: listAddBackI64PFloatP,                      \
  double:                listAddBackI64PDouble,                      \
  double*:               listAddBackI64PDoubleP,                     \
  const volatile double*: listAddBackI64PDoubleP,                     \
  long double:           listAddBackI64PLongDouble,                  \
  long double*:          listAddBackI64PLongDoubleP,                 \
  const volatile long double*: listAddBackI64PLongDoubleP,                 \
  List:                  listAddBackI64PList,                        \
  List*:                 listAddBackI64PListP,                       \
  const volatile List*:  listAddBackI64PListP,                       \
  Queue:                 listAddBackI64PQueue,                       \
  Queue*:                listAddBackI64PQueueP,                      \
  const volatile Queue*: listAddBackI64PQueueP,                      \
  Stack:                 listAddBackI64PStack,                       \
  Stack*:                listAddBackI64PStackP,                      \
  const volatile Stack*: listAddBackI64PStackP,                      \
  RedBlackTree:          listAddBackI64PRedBlackTree,                \
  RedBlackTree*:         listAddBackI64PRedBlackTreeP,               \
  const volatile RedBlackTree*: listAddBackI64PRedBlackTreeP,               \
  HashTable:             listAddBackI64PHashTable,                   \
  HashTable*:            listAddBackI64PHashTableP,                  \
  const volatile HashTable*: listAddBackI64PHashTableP,                  \
  Vector:                listAddBackI64PVector,                      \
  Vector*:               listAddBackI64PVectorP,                     \
  const volatile Vector*: listAddBackI64PVectorP,                     \
  char*:                 listAddBackI64PString,                      \
  const volatile char*:  listAddBackI64PString,                      \
  char**:                listAddBackI64PStringP,                     \
  const volatile char**: listAddBackI64PStringP,                     \
  Bytes:                 listAddBackI64PBytes,                       \
  Bytes*:                listAddBackI64PBytesP,                      \
  const volatile Bytes*: listAddBackI64PBytesP,                      \
  void*:                 listAddBackI64PPointer,                     \
  void**:                listAddBackI64PPointerP,                    \
  const volatile void**: listAddBackI64PPointerP,                    \
  i8:                    listAddBackI64I8,                           \
  u8:                    listAddBackI64U8                            \

#define listAddBackI64P(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_I64P_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_U64P_KEY(dataStructure, key, value) \
  bool:                  listAddBackU64PBool,                        \
  bool*:                 listAddBackU64PBoolP,                       \
  const volatile bool*:  listAddBackU64PBoolP,                       \
  i16:                   listAddBackU64PI16,                         \
  i16*:                  listAddBackU64PI16P,                        \
  const volatile i16*:   listAddBackU64PI16P,                        \
  u16:                   listAddBackU64PU16,                         \
  u16*:                  listAddBackU64PU16P,                        \
  const volatile u16*:   listAddBackU64PU16P,                        \
  i32:                   listAddBackU64PI32,                         \
  i32*:                  listAddBackU64PI32P,                        \
  const volatile i32*:   listAddBackU64PI32P,                        \
  u32:                   listAddBackU64PU32,                         \
  u32*:                  listAddBackU64PU32P,                        \
  const volatile u32*:   listAddBackU64PU32P,                        \
  i64:                   listAddBackU64PI64,                         \
  i64*:                  listAddBackU64PI64P,                        \
  const volatile i64*:   listAddBackU64PI64P,                        \
  u64:                   listAddBackU64PU64,                         \
  u64*:                  listAddBackU64PU64P,                        \
  const volatile u64*:   listAddBackU64PU64P,                        \
  float:                 listAddBackU64PFloat,                       \
  float*:                listAddBackU64PFloatP,                      \
  const volatile float*: listAddBackU64PFloatP,                      \
  double:                listAddBackU64PDouble,                      \
  double*:               listAddBackU64PDoubleP,                     \
  const volatile double*: listAddBackU64PDoubleP,                     \
  long double:           listAddBackU64PLongDouble,                  \
  long double*:          listAddBackU64PLongDoubleP,                 \
  const volatile long double*: listAddBackU64PLongDoubleP,                 \
  List:                  listAddBackU64PList,                        \
  List*:                 listAddBackU64PListP,                       \
  const volatile List*:  listAddBackU64PListP,                       \
  Queue:                 listAddBackU64PQueue,                       \
  Queue*:                listAddBackU64PQueueP,                      \
  const volatile Queue*: listAddBackU64PQueueP,                      \
  Stack:                 listAddBackU64PStack,                       \
  Stack*:                listAddBackU64PStackP,                      \
  const volatile Stack*: listAddBackU64PStackP,                      \
  RedBlackTree:          listAddBackU64PRedBlackTree,                \
  RedBlackTree*:         listAddBackU64PRedBlackTreeP,               \
  const volatile RedBlackTree*: listAddBackU64PRedBlackTreeP,               \
  HashTable:             listAddBackU64PHashTable,                   \
  HashTable*:            listAddBackU64PHashTableP,                  \
  const volatile HashTable*: listAddBackU64PHashTableP,                  \
  Vector:                listAddBackU64PVector,                      \
  Vector*:               listAddBackU64PVectorP,                     \
  const volatile Vector*: listAddBackU64PVectorP,                     \
  char*:                 listAddBackU64PString,                      \
  const volatile char*:  listAddBackU64PString,                      \
  char**:                listAddBackU64PStringP,                     \
  const volatile char**: listAddBackU64PStringP,                     \
  Bytes:                 listAddBackU64PBytes,                       \
  Bytes*:                listAddBackU64PBytesP,                      \
  const volatile Bytes*: listAddBackU64PBytesP,                      \
  void*:                 listAddBackU64PPointer,                     \
  void**:                listAddBackU64PPointerP,                    \
  const volatile void**: listAddBackU64PPointerP,                    \
  i8:                    listAddBackU64I8,                           \
  u8:                    listAddBackU64U8                            \

#define listAddBackU64P(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_U64P_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_FLOATP_KEY(dataStructure, key, value) \
  bool:                  listAddBackFloatPBool,                      \
  bool*:                 listAddBackFloatPBoolP,                     \
  const volatile bool*:  listAddBackFloatPBoolP,                     \
  i16:                   listAddBackFloatPI16,                       \
  i16*:                  listAddBackFloatPI16P,                      \
  const volatile i16*:   listAddBackFloatPI16P,                      \
  u16:                   listAddBackFloatPU16,                       \
  u16*:                  listAddBackFloatPU16P,                      \
  const volatile u16*:   listAddBackFloatPU16P,                      \
  i32:                   listAddBackFloatPI32,                       \
  i32*:                  listAddBackFloatPI32P,                      \
  const volatile i32*:   listAddBackFloatPI32P,                      \
  u32:                   listAddBackFloatPU32,                       \
  u32*:                  listAddBackFloatPU32P,                      \
  const volatile u32*:   listAddBackFloatPU32P,                      \
  i64:                   listAddBackFloatPI64,                       \
  i64*:                  listAddBackFloatPI64P,                      \
  const volatile i64*:   listAddBackFloatPI64P,                      \
  u64:                   listAddBackFloatPU64,                       \
  u64*:                  listAddBackFloatPU64P,                      \
  const volatile u64*:   listAddBackFloatPU64P,                      \
  float:                 listAddBackFloatPFloat,                     \
  float*:                listAddBackFloatPFloatP,                    \
  const volatile float*: listAddBackFloatPFloatP,                    \
  double:                listAddBackFloatPDouble,                    \
  double*:               listAddBackFloatPDoubleP,                   \
  const volatile double*: listAddBackFloatPDoubleP,                   \
  long double:           listAddBackFloatPLongDouble,                \
  long double*:          listAddBackFloatPLongDoubleP,               \
  const volatile long double*: listAddBackFloatPLongDoubleP,               \
  List:                  listAddBackFloatPList,                      \
  List*:                 listAddBackFloatPListP,                     \
  const volatile List*:  listAddBackFloatPListP,                     \
  Queue:                 listAddBackFloatPQueue,                     \
  Queue*:                listAddBackFloatPQueueP,                    \
  const volatile Queue*: listAddBackFloatPQueueP,                    \
  Stack:                 listAddBackFloatPStack,                     \
  Stack*:                listAddBackFloatPStackP,                    \
  const volatile Stack*: listAddBackFloatPStackP,                    \
  RedBlackTree:          listAddBackFloatPRedBlackTree,              \
  RedBlackTree*:         listAddBackFloatPRedBlackTreeP,             \
  const volatile RedBlackTree*: listAddBackFloatPRedBlackTreeP,             \
  HashTable:             listAddBackFloatPHashTable,                 \
  HashTable*:            listAddBackFloatPHashTableP,                \
  const volatile HashTable*: listAddBackFloatPHashTableP,                \
  Vector:                listAddBackFloatPVector,                    \
  Vector*:               listAddBackFloatPVectorP,                   \
  const volatile Vector*: listAddBackFloatPVectorP,                   \
  char*:                 listAddBackFloatPString,                    \
  const volatile char*:  listAddBackFloatPString,                    \
  char**:                listAddBackFloatPStringP,                   \
  const volatile char**: listAddBackFloatPStringP,                   \
  Bytes:                 listAddBackFloatPBytes,                     \
  Bytes*:                listAddBackFloatPBytesP,                    \
  const volatile Bytes*: listAddBackFloatPBytesP,                    \
  void*:                 listAddBackFloatPPointer,                   \
  void**:                listAddBackFloatPPointerP,                  \
  const volatile void**: listAddBackFloatPPointerP,                  \
  i8:                    listAddBackFloatI8,                         \
  u8:                    listAddBackFloatU8                          \

#define listAddBackFloatP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_FLOATP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_DOUBLEP_KEY(dataStructure, key, value) \
  bool:                  listAddBackDoublePBool,                     \
  bool*:                 listAddBackDoublePBoolP,                    \
  const volatile bool*:  listAddBackDoublePBoolP,                    \
  i16:                   listAddBackDoublePI16,                      \
  i16*:                  listAddBackDoublePI16P,                     \
  const volatile i16*:   listAddBackDoublePI16P,                     \
  u16:                   listAddBackDoublePU16,                      \
  u16*:                  listAddBackDoublePU16P,                     \
  const volatile u16*:   listAddBackDoublePU16P,                     \
  i32:                   listAddBackDoublePI32,                      \
  i32*:                  listAddBackDoublePI32P,                     \
  const volatile i32*:   listAddBackDoublePI32P,                     \
  u32:                   listAddBackDoublePU32,                      \
  u32*:                  listAddBackDoublePU32P,                     \
  const volatile u32*:   listAddBackDoublePU32P,                     \
  i64:                   listAddBackDoublePI64,                      \
  i64*:                  listAddBackDoublePI64P,                     \
  const volatile i64*:   listAddBackDoublePI64P,                     \
  u64:                   listAddBackDoublePU64,                      \
  u64*:                  listAddBackDoublePU64P,                     \
  const volatile u64*:   listAddBackDoublePU64P,                     \
  float:                 listAddBackDoublePFloat,                    \
  float*:                listAddBackDoublePFloatP,                   \
  const volatile float*: listAddBackDoublePFloatP,                   \
  double:                listAddBackDoublePDouble,                   \
  double*:               listAddBackDoublePDoubleP,                  \
  const volatile double*: listAddBackDoublePDoubleP,                  \
  long double:           listAddBackDoublePLongDouble,               \
  long double*:          listAddBackDoublePLongDoubleP,              \
  const volatile long double*: listAddBackDoublePLongDoubleP,              \
  List:                  listAddBackDoublePList,                     \
  List*:                 listAddBackDoublePListP,                    \
  const volatile List*:  listAddBackDoublePListP,                    \
  Queue:                 listAddBackDoublePQueue,                    \
  Queue*:                listAddBackDoublePQueueP,                   \
  const volatile Queue*: listAddBackDoublePQueueP,                   \
  Stack:                 listAddBackDoublePStack,                    \
  Stack*:                listAddBackDoublePStackP,                   \
  const volatile Stack*: listAddBackDoublePStackP,                   \
  RedBlackTree:          listAddBackDoublePRedBlackTree,             \
  RedBlackTree*:         listAddBackDoublePRedBlackTreeP,            \
  const volatile RedBlackTree*: listAddBackDoublePRedBlackTreeP,            \
  HashTable:             listAddBackDoublePHashTable,                \
  HashTable*:            listAddBackDoublePHashTableP,               \
  const volatile HashTable*: listAddBackDoublePHashTableP,               \
  Vector:                listAddBackDoublePVector,                   \
  Vector*:               listAddBackDoublePVectorP,                  \
  const volatile Vector*: listAddBackDoublePVectorP,                  \
  char*:                 listAddBackDoublePString,                   \
  const volatile char*:  listAddBackDoublePString,                   \
  char**:                listAddBackDoublePStringP,                  \
  const volatile char**: listAddBackDoublePStringP,                  \
  Bytes:                 listAddBackDoublePBytes,                    \
  Bytes*:                listAddBackDoublePBytesP,                   \
  const volatile Bytes*: listAddBackDoublePBytesP,                   \
  void*:                 listAddBackDoublePPointer,                  \
  void**:                listAddBackDoublePPointerP,                 \
  const volatile void**: listAddBackDoublePPointerP,                 \
  i8:                    listAddBackDoubleI8,                        \
  u8:                    listAddBackDoubleU8                         \

#define listAddBackDoubleP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_DOUBLEP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_LONG_DOUBLEP_KEY(dataStructure, key, value) \
  bool:                  listAddBackLongDoublePBool,                 \
  bool*:                 listAddBackLongDoublePBoolP,                \
  const volatile bool*:  listAddBackLongDoublePBoolP,                \
  i16:                   listAddBackLongDoublePI16,                  \
  i16*:                  listAddBackLongDoublePI16P,                 \
  const volatile i16*:   listAddBackLongDoublePI16P,                 \
  u16:                   listAddBackLongDoublePU16,                  \
  u16*:                  listAddBackLongDoublePU16P,                 \
  const volatile u16*:   listAddBackLongDoublePU16P,                 \
  i32:                   listAddBackLongDoublePI32,                  \
  i32*:                  listAddBackLongDoublePI32P,                 \
  const volatile i32*:   listAddBackLongDoublePI32P,                 \
  u32:                   listAddBackLongDoublePU32,                  \
  u32*:                  listAddBackLongDoublePU32P,                 \
  const volatile u32*:   listAddBackLongDoublePU32P,                 \
  i64:                   listAddBackLongDoublePI64,                  \
  i64*:                  listAddBackLongDoublePI64P,                 \
  const volatile i64*:   listAddBackLongDoublePI64P,                 \
  u64:                   listAddBackLongDoublePU64,                  \
  u64*:                  listAddBackLongDoublePU64P,                 \
  const volatile u64*:   listAddBackLongDoublePU64P,                 \
  float:                 listAddBackLongDoublePFloat,                \
  float*:                listAddBackLongDoublePFloatP,               \
  const volatile float*: listAddBackLongDoublePFloatP,               \
  double:                listAddBackLongDoublePDouble,               \
  double*:               listAddBackLongDoublePDoubleP,              \
  const volatile double*: listAddBackLongDoublePDoubleP,              \
  long double:           listAddBackLongDoublePLongDouble,           \
  long double*:          listAddBackLongDoublePLongDoubleP,          \
  const volatile long double*: listAddBackLongDoublePLongDoubleP,          \
  List:                  listAddBackLongDoublePList,                 \
  List*:                 listAddBackLongDoublePListP,                \
  const volatile List*:  listAddBackLongDoublePListP,                \
  Queue:                 listAddBackLongDoublePQueue,                \
  Queue*:                listAddBackLongDoublePQueueP,               \
  const volatile Queue*: listAddBackLongDoublePQueueP,               \
  Stack:                 listAddBackLongDoublePStack,                \
  Stack*:                listAddBackLongDoublePStackP,               \
  const volatile Stack*: listAddBackLongDoublePStackP,               \
  RedBlackTree:          listAddBackLongDoublePRedBlackTree,         \
  RedBlackTree*:         listAddBackLongDoublePRedBlackTreeP,        \
  const volatile RedBlackTree*: listAddBackLongDoublePRedBlackTreeP,        \
  HashTable:             listAddBackLongDoublePHashTable,            \
  HashTable*:            listAddBackLongDoublePHashTableP,           \
  const volatile HashTable*: listAddBackLongDoublePHashTableP,           \
  Vector:                listAddBackLongDoublePVector,               \
  Vector*:               listAddBackLongDoublePVectorP,              \
  const volatile Vector*: listAddBackLongDoublePVectorP,              \
  char*:                 listAddBackLongDoublePString,               \
  const volatile char*:  listAddBackLongDoublePString,               \
  char**:                listAddBackLongDoublePStringP,              \
  const volatile char**: listAddBackLongDoublePStringP,              \
  Bytes:                 listAddBackLongDoublePBytes,                \
  Bytes*:                listAddBackLongDoublePBytesP,               \
  const volatile Bytes*: listAddBackLongDoublePBytesP,               \
  void*:                 listAddBackLongDoublePPointer,              \
  void**:                listAddBackLongDoublePPointerP,             \
  const volatile void**: listAddBackLongDoublePPointerP,             \
  i8:                    listAddBackLongDoubleI8,                    \
  u8:                    listAddBackLongDoubleU8                     \

#define listAddBackLongDoubleP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_LONG_DOUBLEP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_LISTP_KEY(dataStructure, key, value) \
  bool:                  listAddBackListPBool,                       \
  bool*:                 listAddBackListPBoolP,                      \
  const volatile bool*:  listAddBackListPBoolP,                      \
  i16:                   listAddBackListPI16,                        \
  i16*:                  listAddBackListPI16P,                       \
  const volatile i16*:   listAddBackListPI16P,                       \
  u16:                   listAddBackListPU16,                        \
  u16*:                  listAddBackListPU16P,                       \
  const volatile u16*:   listAddBackListPU16P,                       \
  i32:                   listAddBackListPI32,                        \
  i32*:                  listAddBackListPI32P,                       \
  const volatile i32*:   listAddBackListPI32P,                       \
  u32:                   listAddBackListPU32,                        \
  u32*:                  listAddBackListPU32P,                       \
  const volatile u32*:   listAddBackListPU32P,                       \
  i64:                   listAddBackListPI64,                        \
  i64*:                  listAddBackListPI64P,                       \
  const volatile i64*:   listAddBackListPI64P,                       \
  u64:                   listAddBackListPU64,                        \
  u64*:                  listAddBackListPU64P,                       \
  const volatile u64*:   listAddBackListPU64P,                       \
  float:                 listAddBackListPFloat,                      \
  float*:                listAddBackListPFloatP,                     \
  const volatile float*: listAddBackListPFloatP,                     \
  double:                listAddBackListPDouble,                     \
  double*:               listAddBackListPDoubleP,                    \
  const volatile double*: listAddBackListPDoubleP,                    \
  long double:           listAddBackListPLongDouble,                 \
  long double*:          listAddBackListPLongDoubleP,                \
  const volatile long double*: listAddBackListPLongDoubleP,                \
  List:                  listAddBackListPList,                       \
  List*:                 listAddBackListPListP,                      \
  const volatile List*:  listAddBackListPListP,                      \
  Queue:                 listAddBackListPQueue,                      \
  Queue*:                listAddBackListPQueueP,                     \
  const volatile Queue*: listAddBackListPQueueP,                     \
  Stack:                 listAddBackListPStack,                      \
  Stack*:                listAddBackListPStackP,                     \
  const volatile Stack*: listAddBackListPStackP,                     \
  RedBlackTree:          listAddBackListPRedBlackTree,               \
  RedBlackTree*:         listAddBackListPRedBlackTreeP,              \
  const volatile RedBlackTree*: listAddBackListPRedBlackTreeP,              \
  HashTable:             listAddBackListPHashTable,                  \
  HashTable*:            listAddBackListPHashTableP,                 \
  const volatile HashTable*: listAddBackListPHashTableP,                 \
  Vector:                listAddBackListPVector,                     \
  Vector*:               listAddBackListPVectorP,                    \
  const volatile Vector*: listAddBackListPVectorP,                    \
  char*:                 listAddBackListPString,                     \
  const volatile char*:  listAddBackListPString,                     \
  char**:                listAddBackListPStringP,                    \
  const volatile char**: listAddBackListPStringP,                    \
  Bytes:                 listAddBackListPBytes,                      \
  Bytes*:                listAddBackListPBytesP,                     \
  const volatile Bytes*: listAddBackListPBytesP,                     \
  void*:                 listAddBackListPPointer,                    \
  void**:                listAddBackListPPointerP,                   \
  const volatile void**: listAddBackListPPointerP,                   \
  i8:                    listAddBackListI8,                          \
  u8:                    listAddBackListU8                           \

#define listAddBackListP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_LISTP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_QUEUEP_KEY(dataStructure, key, value) \
  bool:                  listAddBackQueuePBool,                      \
  bool*:                 listAddBackQueuePBoolP,                     \
  const volatile bool*:  listAddBackQueuePBoolP,                     \
  i16:                   listAddBackQueuePI16,                       \
  i16*:                  listAddBackQueuePI16P,                      \
  const volatile i16*:   listAddBackQueuePI16P,                      \
  u16:                   listAddBackQueuePU16,                       \
  u16*:                  listAddBackQueuePU16P,                      \
  const volatile u16*:   listAddBackQueuePU16P,                      \
  i32:                   listAddBackQueuePI32,                       \
  i32*:                  listAddBackQueuePI32P,                      \
  const volatile i32*:   listAddBackQueuePI32P,                      \
  u32:                   listAddBackQueuePU32,                       \
  u32*:                  listAddBackQueuePU32P,                      \
  const volatile u32*:   listAddBackQueuePU32P,                      \
  i64:                   listAddBackQueuePI64,                       \
  i64*:                  listAddBackQueuePI64P,                      \
  const volatile i64*:   listAddBackQueuePI64P,                      \
  u64:                   listAddBackQueuePU64,                       \
  u64*:                  listAddBackQueuePU64P,                      \
  const volatile u64*:   listAddBackQueuePU64P,                      \
  float:                 listAddBackQueuePFloat,                     \
  float*:                listAddBackQueuePFloatP,                    \
  const volatile float*: listAddBackQueuePFloatP,                    \
  double:                listAddBackQueuePDouble,                    \
  double*:               listAddBackQueuePDoubleP,                   \
  const volatile double*: listAddBackQueuePDoubleP,                   \
  long double:           listAddBackQueuePLongDouble,                \
  long double*:          listAddBackQueuePLongDoubleP,               \
  const volatile long double*: listAddBackQueuePLongDoubleP,               \
  List:                  listAddBackQueuePList,                      \
  List*:                 listAddBackQueuePListP,                     \
  const volatile List*:  listAddBackQueuePListP,                     \
  Queue:                 listAddBackQueuePQueue,                     \
  Queue*:                listAddBackQueuePQueueP,                    \
  const volatile Queue*: listAddBackQueuePQueueP,                    \
  Stack:                 listAddBackQueuePStack,                     \
  Stack*:                listAddBackQueuePStackP,                    \
  const volatile Stack*: listAddBackQueuePStackP,                    \
  RedBlackTree:          listAddBackQueuePRedBlackTree,              \
  RedBlackTree*:         listAddBackQueuePRedBlackTreeP,             \
  const volatile RedBlackTree*: listAddBackQueuePRedBlackTreeP,             \
  HashTable:             listAddBackQueuePHashTable,                 \
  HashTable*:            listAddBackQueuePHashTableP,                \
  const volatile HashTable*: listAddBackQueuePHashTableP,                \
  Vector:                listAddBackQueuePVector,                    \
  Vector*:               listAddBackQueuePVectorP,                   \
  const volatile Vector*: listAddBackQueuePVectorP,                   \
  char*:                 listAddBackQueuePString,                    \
  const volatile char*:  listAddBackQueuePString,                    \
  char**:                listAddBackQueuePStringP,                   \
  const volatile char**: listAddBackQueuePStringP,                   \
  Bytes:                 listAddBackQueuePBytes,                     \
  Bytes*:                listAddBackQueuePBytesP,                    \
  const volatile Bytes*: listAddBackQueuePBytesP,                    \
  void*:                 listAddBackQueuePPointer,                   \
  void**:                listAddBackQueuePPointerP,                  \
  const volatile void**: listAddBackQueuePPointerP,                  \
  i8:                    listAddBackQueueI8,                         \
  u8:                    listAddBackQueueU8                          \

#define listAddBackQueueP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_QUEUEP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_STACKP_KEY(dataStructure, key, value) \
  bool:                  listAddBackStackPBool,                      \
  bool*:                 listAddBackStackPBoolP,                     \
  const volatile bool*:  listAddBackStackPBoolP,                     \
  i16:                   listAddBackStackPI16,                       \
  i16*:                  listAddBackStackPI16P,                      \
  const volatile i16*:   listAddBackStackPI16P,                      \
  u16:                   listAddBackStackPU16,                       \
  u16*:                  listAddBackStackPU16P,                      \
  const volatile u16*:   listAddBackStackPU16P,                      \
  i32:                   listAddBackStackPI32,                       \
  i32*:                  listAddBackStackPI32P,                      \
  const volatile i32*:   listAddBackStackPI32P,                      \
  u32:                   listAddBackStackPU32,                       \
  u32*:                  listAddBackStackPU32P,                      \
  const volatile u32*:   listAddBackStackPU32P,                      \
  i64:                   listAddBackStackPI64,                       \
  i64*:                  listAddBackStackPI64P,                      \
  const volatile i64*:   listAddBackStackPI64P,                      \
  u64:                   listAddBackStackPU64,                       \
  u64*:                  listAddBackStackPU64P,                      \
  const volatile u64*:   listAddBackStackPU64P,                      \
  float:                 listAddBackStackPFloat,                     \
  float*:                listAddBackStackPFloatP,                    \
  const volatile float*: listAddBackStackPFloatP,                    \
  double:                listAddBackStackPDouble,                    \
  double*:               listAddBackStackPDoubleP,                   \
  const volatile double*: listAddBackStackPDoubleP,                   \
  long double:           listAddBackStackPLongDouble,                \
  long double*:          listAddBackStackPLongDoubleP,               \
  const volatile long double*: listAddBackStackPLongDoubleP,               \
  List:                  listAddBackStackPList,                      \
  List*:                 listAddBackStackPListP,                     \
  const volatile List*:  listAddBackStackPListP,                     \
  Queue:                 listAddBackStackPQueue,                     \
  Queue*:                listAddBackStackPQueueP,                    \
  const volatile Queue*: listAddBackStackPQueueP,                    \
  Stack:                 listAddBackStackPStack,                     \
  Stack*:                listAddBackStackPStackP,                    \
  const volatile Stack*: listAddBackStackPStackP,                    \
  RedBlackTree:          listAddBackStackPRedBlackTree,              \
  RedBlackTree*:         listAddBackStackPRedBlackTreeP,             \
  const volatile RedBlackTree*: listAddBackStackPRedBlackTreeP,             \
  HashTable:             listAddBackStackPHashTable,                 \
  HashTable*:            listAddBackStackPHashTableP,                \
  const volatile HashTable*: listAddBackStackPHashTableP,                \
  Vector:                listAddBackStackPVector,                    \
  Vector*:               listAddBackStackPVectorP,                   \
  const volatile Vector*: listAddBackStackPVectorP,                   \
  char*:                 listAddBackStackPString,                    \
  const volatile char*:  listAddBackStackPString,                    \
  char**:                listAddBackStackPStringP,                   \
  const volatile char**: listAddBackStackPStringP,                   \
  Bytes:                 listAddBackStackPBytes,                     \
  Bytes*:                listAddBackStackPBytesP,                    \
  const volatile Bytes*: listAddBackStackPBytesP,                    \
  void*:                 listAddBackStackPPointer,                   \
  void**:                listAddBackStackPPointerP,                  \
  const volatile void**: listAddBackStackPPointerP,                  \
  i8:                    listAddBackStackI8,                         \
  u8:                    listAddBackStackU8                          \

#define listAddBackStackP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_STACKP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_RED_BLACK_TREEP_KEY(dataStructure, key, value) \
  bool:                  listAddBackRedBlackTreePBool,               \
  bool*:                 listAddBackRedBlackTreePBoolP,              \
  const volatile bool*:  listAddBackRedBlackTreePBoolP,              \
  i16:                   listAddBackRedBlackTreePI16,                \
  i16*:                  listAddBackRedBlackTreePI16P,               \
  const volatile i16*:   listAddBackRedBlackTreePI16P,               \
  u16:                   listAddBackRedBlackTreePU16,                \
  u16*:                  listAddBackRedBlackTreePU16P,               \
  const volatile u16*:   listAddBackRedBlackTreePU16P,               \
  i32:                   listAddBackRedBlackTreePI32,                \
  i32*:                  listAddBackRedBlackTreePI32P,               \
  const volatile i32*:   listAddBackRedBlackTreePI32P,               \
  u32:                   listAddBackRedBlackTreePU32,                \
  u32*:                  listAddBackRedBlackTreePU32P,               \
  const volatile u32*:   listAddBackRedBlackTreePU32P,               \
  i64:                   listAddBackRedBlackTreePI64,                \
  i64*:                  listAddBackRedBlackTreePI64P,               \
  const volatile i64*:   listAddBackRedBlackTreePI64P,               \
  u64:                   listAddBackRedBlackTreePU64,                \
  u64*:                  listAddBackRedBlackTreePU64P,               \
  const volatile u64*:   listAddBackRedBlackTreePU64P,               \
  float:                 listAddBackRedBlackTreePFloat,              \
  float*:                listAddBackRedBlackTreePFloatP,             \
  const volatile float*: listAddBackRedBlackTreePFloatP,             \
  double:                listAddBackRedBlackTreePDouble,             \
  double*:               listAddBackRedBlackTreePDoubleP,            \
  const volatile double*: listAddBackRedBlackTreePDoubleP,            \
  long double:           listAddBackRedBlackTreePLongDouble,         \
  long double*:          listAddBackRedBlackTreePLongDoubleP,        \
  const volatile long double*: listAddBackRedBlackTreePLongDoubleP,        \
  List:                  listAddBackRedBlackTreePList,               \
  List*:                 listAddBackRedBlackTreePListP,              \
  const volatile List*:  listAddBackRedBlackTreePListP,              \
  Queue:                 listAddBackRedBlackTreePQueue,              \
  Queue*:                listAddBackRedBlackTreePQueueP,             \
  const volatile Queue*: listAddBackRedBlackTreePQueueP,             \
  Stack:                 listAddBackRedBlackTreePStack,              \
  Stack*:                listAddBackRedBlackTreePStackP,             \
  const volatile Stack*: listAddBackRedBlackTreePStackP,             \
  RedBlackTree:          listAddBackRedBlackTreePRedBlackTree,       \
  RedBlackTree*:         listAddBackRedBlackTreePRedBlackTreeP,      \
  const volatile RedBlackTree*: listAddBackRedBlackTreePRedBlackTreeP,      \
  HashTable:             listAddBackRedBlackTreePHashTable,          \
  HashTable*:            listAddBackRedBlackTreePHashTableP,         \
  const volatile HashTable*: listAddBackRedBlackTreePHashTableP,         \
  Vector:                listAddBackRedBlackTreePVector,             \
  Vector*:               listAddBackRedBlackTreePVectorP,            \
  const volatile Vector*: listAddBackRedBlackTreePVectorP,            \
  char*:                 listAddBackRedBlackTreePString,             \
  const volatile char*:  listAddBackRedBlackTreePString,             \
  char**:                listAddBackRedBlackTreePStringP,            \
  const volatile char**: listAddBackRedBlackTreePStringP,            \
  Bytes:                 listAddBackRedBlackTreePBytes,              \
  Bytes*:                listAddBackRedBlackTreePBytesP,             \
  const volatile Bytes*: listAddBackRedBlackTreePBytesP,             \
  void*:                 listAddBackRedBlackTreePPointer,            \
  void**:                listAddBackRedBlackTreePPointerP,           \
  const volatile void**: listAddBackRedBlackTreePPointerP,           \
  i8:                    listAddBackRedBlackTreeI8,                  \
  u8:                    listAddBackRedBlackTreeU8                   \

#define listAddBackRedBlackTreeP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_RED_BLACK_TREEP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_HASH_TABLEP_KEY(dataStructure, key, value) \
  bool:                  listAddBackHashTablePBool,                  \
  bool*:                 listAddBackHashTablePBoolP,                 \
  const volatile bool*:  listAddBackHashTablePBoolP,                 \
  i16:                   listAddBackHashTablePI16,                   \
  i16*:                  listAddBackHashTablePI16P,                  \
  const volatile i16*:   listAddBackHashTablePI16P,                  \
  u16:                   listAddBackHashTablePU16,                   \
  u16*:                  listAddBackHashTablePU16P,                  \
  const volatile u16*:   listAddBackHashTablePU16P,                  \
  i32:                   listAddBackHashTablePI32,                   \
  i32*:                  listAddBackHashTablePI32P,                  \
  const volatile i32*:   listAddBackHashTablePI32P,                  \
  u32:                   listAddBackHashTablePU32,                   \
  u32*:                  listAddBackHashTablePU32P,                  \
  const volatile u32*:   listAddBackHashTablePU32P,                  \
  i64:                   listAddBackHashTablePI64,                   \
  i64*:                  listAddBackHashTablePI64P,                  \
  const volatile i64*:   listAddBackHashTablePI64P,                  \
  u64:                   listAddBackHashTablePU64,                   \
  u64*:                  listAddBackHashTablePU64P,                  \
  const volatile u64*:   listAddBackHashTablePU64P,                  \
  float:                 listAddBackHashTablePFloat,                 \
  float*:                listAddBackHashTablePFloatP,                \
  const volatile float*: listAddBackHashTablePFloatP,                \
  double:                listAddBackHashTablePDouble,                \
  double*:               listAddBackHashTablePDoubleP,               \
  const volatile double*: listAddBackHashTablePDoubleP,               \
  long double:           listAddBackHashTablePLongDouble,            \
  long double*:          listAddBackHashTablePLongDoubleP,           \
  const volatile long double*: listAddBackHashTablePLongDoubleP,           \
  List:                  listAddBackHashTablePList,                  \
  List*:                 listAddBackHashTablePListP,                 \
  const volatile List*:  listAddBackHashTablePListP,                 \
  Queue:                 listAddBackHashTablePQueue,                 \
  Queue*:                listAddBackHashTablePQueueP,                \
  const volatile Queue*: listAddBackHashTablePQueueP,                \
  Stack:                 listAddBackHashTablePStack,                 \
  Stack*:                listAddBackHashTablePStackP,                \
  const volatile Stack*: listAddBackHashTablePStackP,                \
  RedBlackTree:          listAddBackHashTablePRedBlackTree,          \
  RedBlackTree*:         listAddBackHashTablePRedBlackTreeP,         \
  const volatile RedBlackTree*: listAddBackHashTablePRedBlackTreeP,         \
  HashTable:             listAddBackHashTablePHashTable,             \
  HashTable*:            listAddBackHashTablePHashTableP,            \
  const volatile HashTable*: listAddBackHashTablePHashTableP,            \
  Vector:                listAddBackHashTablePVector,                \
  Vector*:               listAddBackHashTablePVectorP,               \
  const volatile Vector*: listAddBackHashTablePVectorP,               \
  char*:                 listAddBackHashTablePString,                \
  const volatile char*:  listAddBackHashTablePString,                \
  char**:                listAddBackHashTablePStringP,               \
  const volatile char**: listAddBackHashTablePStringP,               \
  Bytes:                 listAddBackHashTablePBytes,                 \
  Bytes*:                listAddBackHashTablePBytesP,                \
  const volatile Bytes*: listAddBackHashTablePBytesP,                \
  void*:                 listAddBackHashTablePPointer,               \
  void**:                listAddBackHashTablePPointerP,              \
  const volatile void**: listAddBackHashTablePPointerP,              \
  i8:                    listAddBackHashTableI8,                     \
  u8:                    listAddBackHashTableU8                      \

#define listAddBackHashTableP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_HASH_TABLEP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_VECTORP_KEY(dataStructure, key, value) \
  bool:                  listAddBackVectorPBool,                     \
  bool*:                 listAddBackVectorPBoolP,                    \
  const volatile bool*:  listAddBackVectorPBoolP,                    \
  i16:                   listAddBackVectorPI16,                      \
  i16*:                  listAddBackVectorPI16P,                     \
  const volatile i16*:   listAddBackVectorPI16P,                     \
  u16:                   listAddBackVectorPU16,                      \
  u16*:                  listAddBackVectorPU16P,                     \
  const volatile u16*:   listAddBackVectorPU16P,                     \
  i32:                   listAddBackVectorPI32,                      \
  i32*:                  listAddBackVectorPI32P,                     \
  const volatile i32*:   listAddBackVectorPI32P,                     \
  u32:                   listAddBackVectorPU32,                      \
  u32*:                  listAddBackVectorPU32P,                     \
  const volatile u32*:   listAddBackVectorPU32P,                     \
  i64:                   listAddBackVectorPI64,                      \
  i64*:                  listAddBackVectorPI64P,                     \
  const volatile i64*:   listAddBackVectorPI64P,                     \
  u64:                   listAddBackVectorPU64,                      \
  u64*:                  listAddBackVectorPU64P,                     \
  const volatile u64*:   listAddBackVectorPU64P,                     \
  float:                 listAddBackVectorPFloat,                    \
  float*:                listAddBackVectorPFloatP,                   \
  const volatile float*: listAddBackVectorPFloatP,                   \
  double:                listAddBackVectorPDouble,                   \
  double*:               listAddBackVectorPDoubleP,                  \
  const volatile double*: listAddBackVectorPDoubleP,                  \
  long double:           listAddBackVectorPLongDouble,               \
  long double*:          listAddBackVectorPLongDoubleP,              \
  const volatile long double*: listAddBackVectorPLongDoubleP,              \
  List:                  listAddBackVectorPList,                     \
  List*:                 listAddBackVectorPListP,                    \
  const volatile List*:  listAddBackVectorPListP,                    \
  Queue:                 listAddBackVectorPQueue,                    \
  Queue*:                listAddBackVectorPQueueP,                   \
  const volatile Queue*: listAddBackVectorPQueueP,                   \
  Stack:                 listAddBackVectorPStack,                    \
  Stack*:                listAddBackVectorPStackP,                   \
  const volatile Stack*: listAddBackVectorPStackP,                   \
  RedBlackTree:          listAddBackVectorPRedBlackTree,             \
  RedBlackTree*:         listAddBackVectorPRedBlackTreeP,            \
  const volatile RedBlackTree*: listAddBackVectorPRedBlackTreeP,            \
  HashTable:             listAddBackVectorPHashTable,                \
  HashTable*:            listAddBackVectorPHashTableP,               \
  const volatile HashTable*: listAddBackVectorPHashTableP,               \
  Vector:                listAddBackVectorPVector,                   \
  Vector*:               listAddBackVectorPVectorP,                  \
  const volatile Vector*: listAddBackVectorPVectorP,                  \
  char*:                 listAddBackVectorPString,                   \
  const volatile char*:  listAddBackVectorPString,                   \
  char**:                listAddBackVectorPStringP,                  \
  const volatile char**: listAddBackVectorPStringP,                  \
  Bytes:                 listAddBackVectorPBytes,                    \
  Bytes*:                listAddBackVectorPBytesP,                   \
  const volatile Bytes*: listAddBackVectorPBytesP,                   \
  void*:                 listAddBackVectorPPointer,                  \
  void**:                listAddBackVectorPPointerP,                 \
  const volatile void**: listAddBackVectorPPointerP,                 \
  i8:                    listAddBackVectorI8,                        \
  u8:                    listAddBackVectorU8                         \

#define listAddBackVectorP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_VECTORP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_STRINGP_KEY(dataStructure, key, value) \
  bool:                  listAddBackStringPBool,                     \
  bool*:                 listAddBackStringPBoolP,                    \
  const volatile bool*:  listAddBackStringPBoolP,                    \
  i16:                   listAddBackStringPI16,                      \
  i16*:                  listAddBackStringPI16P,                     \
  const volatile i16*:   listAddBackStringPI16P,                     \
  u16:                   listAddBackStringPU16,                      \
  u16*:                  listAddBackStringPU16P,                     \
  const volatile u16*:   listAddBackStringPU16P,                     \
  i32:                   listAddBackStringPI32,                      \
  i32*:                  listAddBackStringPI32P,                     \
  const volatile i32*:   listAddBackStringPI32P,                     \
  u32:                   listAddBackStringPU32,                      \
  u32*:                  listAddBackStringPU32P,                     \
  const volatile u32*:   listAddBackStringPU32P,                     \
  i64:                   listAddBackStringPI64,                      \
  i64*:                  listAddBackStringPI64P,                     \
  const volatile i64*:   listAddBackStringPI64P,                     \
  u64:                   listAddBackStringPU64,                      \
  u64*:                  listAddBackStringPU64P,                     \
  const volatile u64*:   listAddBackStringPU64P,                     \
  float:                 listAddBackStringPFloat,                    \
  float*:                listAddBackStringPFloatP,                   \
  const volatile float*: listAddBackStringPFloatP,                   \
  double:                listAddBackStringPDouble,                   \
  double*:               listAddBackStringPDoubleP,                  \
  const volatile double*: listAddBackStringPDoubleP,                  \
  long double:           listAddBackStringPLongDouble,               \
  long double*:          listAddBackStringPLongDoubleP,              \
  const volatile long double*: listAddBackStringPLongDoubleP,              \
  List:                  listAddBackStringPList,                     \
  List*:                 listAddBackStringPListP,                    \
  const volatile List*:  listAddBackStringPListP,                    \
  Queue:                 listAddBackStringPQueue,                    \
  Queue*:                listAddBackStringPQueueP,                   \
  const volatile Queue*: listAddBackStringPQueueP,                   \
  Stack:                 listAddBackStringPStack,                    \
  Stack*:                listAddBackStringPStackP,                   \
  const volatile Stack*: listAddBackStringPStackP,                   \
  RedBlackTree:          listAddBackStringPRedBlackTree,             \
  RedBlackTree*:         listAddBackStringPRedBlackTreeP,            \
  const volatile RedBlackTree*: listAddBackStringPRedBlackTreeP,            \
  HashTable:             listAddBackStringPHashTable,                \
  HashTable*:            listAddBackStringPHashTableP,               \
  const volatile HashTable*: listAddBackStringPHashTableP,               \
  Vector:                listAddBackStringPVector,                   \
  Vector*:               listAddBackStringPVectorP,                  \
  const volatile Vector*: listAddBackStringPVectorP,                  \
  char*:                 listAddBackStringPString,                   \
  const volatile char*:  listAddBackStringPString,                   \
  char**:                listAddBackStringPStringP,                  \
  const volatile char**: listAddBackStringPStringP,                  \
  Bytes:                 listAddBackStringPBytes,                    \
  Bytes*:                listAddBackStringPBytesP,                   \
  const volatile Bytes*: listAddBackStringPBytesP,                   \
  void*:                 listAddBackStringPPointer,                  \
  void**:                listAddBackStringPPointerP,                 \
  const volatile void**: listAddBackStringPPointerP,                 \
  i8:                    listAddBackStringI8,                        \
  u8:                    listAddBackStringU8                         \

#define listAddBackStringP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_STRINGP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_BYTESP_KEY(dataStructure, key, value) \
  bool:                  listAddBackBytesPBool,                      \
  bool*:                 listAddBackBytesPBoolP,                     \
  const volatile bool*:  listAddBackBytesPBoolP,                     \
  i16:                   listAddBackBytesPI16,                       \
  i16*:                  listAddBackBytesPI16P,                      \
  const volatile i16*:   listAddBackBytesPI16P,                      \
  u16:                   listAddBackBytesPU16,                       \
  u16*:                  listAddBackBytesPU16P,                      \
  const volatile u16*:   listAddBackBytesPU16P,                      \
  i32:                   listAddBackBytesPI32,                       \
  i32*:                  listAddBackBytesPI32P,                      \
  const volatile i32*:   listAddBackBytesPI32P,                      \
  u32:                   listAddBackBytesPU32,                       \
  u32*:                  listAddBackBytesPU32P,                      \
  const volatile u32*:   listAddBackBytesPU32P,                      \
  i64:                   listAddBackBytesPI64,                       \
  i64*:                  listAddBackBytesPI64P,                      \
  const volatile i64*:   listAddBackBytesPI64P,                      \
  u64:                   listAddBackBytesPU64,                       \
  u64*:                  listAddBackBytesPU64P,                      \
  const volatile u64*:   listAddBackBytesPU64P,                      \
  float:                 listAddBackBytesPFloat,                     \
  float*:                listAddBackBytesPFloatP,                    \
  const volatile float*: listAddBackBytesPFloatP,                    \
  double:                listAddBackBytesPDouble,                    \
  double*:               listAddBackBytesPDoubleP,                   \
  const volatile double*: listAddBackBytesPDoubleP,                   \
  long double:           listAddBackBytesPLongDouble,                \
  long double*:          listAddBackBytesPLongDoubleP,               \
  const volatile long double*: listAddBackBytesPLongDoubleP,               \
  List:                  listAddBackBytesPList,                      \
  List*:                 listAddBackBytesPListP,                     \
  const volatile List*:  listAddBackBytesPListP,                     \
  Queue:                 listAddBackBytesPQueue,                     \
  Queue*:                listAddBackBytesPQueueP,                    \
  const volatile Queue*: listAddBackBytesPQueueP,                    \
  Stack:                 listAddBackBytesPStack,                     \
  Stack*:                listAddBackBytesPStackP,                    \
  const volatile Stack*: listAddBackBytesPStackP,                    \
  RedBlackTree:          listAddBackBytesPRedBlackTree,              \
  RedBlackTree*:         listAddBackBytesPRedBlackTreeP,             \
  const volatile RedBlackTree*: listAddBackBytesPRedBlackTreeP,             \
  HashTable:             listAddBackBytesPHashTable,                 \
  HashTable*:            listAddBackBytesPHashTableP,                \
  const volatile HashTable*: listAddBackBytesPHashTableP,                \
  Vector:                listAddBackBytesPVector,                    \
  Vector*:               listAddBackBytesPVectorP,                   \
  const volatile Vector*: listAddBackBytesPVectorP,                   \
  char*:                 listAddBackBytesPString,                    \
  const volatile char*:  listAddBackBytesPString,                    \
  char**:                listAddBackBytesPStringP,                   \
  const volatile char**: listAddBackBytesPStringP,                   \
  Bytes:                 listAddBackBytesPBytes,                     \
  Bytes*:                listAddBackBytesPBytesP,                    \
  const volatile Bytes*: listAddBackBytesPBytesP,                    \
  void*:                 listAddBackBytesPPointer,                   \
  void**:                listAddBackBytesPPointerP,                  \
  const volatile void**: listAddBackBytesPPointerP,                  \
  i8:                    listAddBackBytesI8,                         \
  u8:                    listAddBackBytesU8                          \

#define listAddBackBytesP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_BYTESP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_BACK_GENERIC_CASES_POINTERP_KEY(dataStructure, key, value) \
  bool:                  listAddBackPointerPBool,                    \
  bool*:                 listAddBackPointerPBoolP,                   \
  const volatile bool*:  listAddBackPointerPBoolP,                   \
  i16:                   listAddBackPointerPI16,                     \
  i16*:                  listAddBackPointerPI16P,                    \
  const volatile i16*:   listAddBackPointerPI16P,                    \
  u16:                   listAddBackPointerPU16,                     \
  u16*:                  listAddBackPointerPU16P,                    \
  const volatile u16*:   listAddBackPointerPU16P,                    \
  i32:                   listAddBackPointerPI32,                     \
  i32*:                  listAddBackPointerPI32P,                    \
  const volatile i32*:   listAddBackPointerPI32P,                    \
  u32:                   listAddBackPointerPU32,                     \
  u32*:                  listAddBackPointerPU32P,                    \
  const volatile u32*:   listAddBackPointerPU32P,                    \
  i64:                   listAddBackPointerPI64,                     \
  i64*:                  listAddBackPointerPI64P,                    \
  const volatile i64*:   listAddBackPointerPI64P,                    \
  u64:                   listAddBackPointerPU64,                     \
  u64*:                  listAddBackPointerPU64P,                    \
  const volatile u64*:   listAddBackPointerPU64P,                    \
  float:                 listAddBackPointerPFloat,                   \
  float*:                listAddBackPointerPFloatP,                  \
  const volatile float*: listAddBackPointerPFloatP,                  \
  double:                listAddBackPointerPDouble,                  \
  double*:               listAddBackPointerPDoubleP,                 \
  const volatile double*: listAddBackPointerPDoubleP,                 \
  long double:           listAddBackPointerPLongDouble,              \
  long double*:          listAddBackPointerPLongDoubleP,             \
  const volatile long double*: listAddBackPointerPLongDoubleP,             \
  List:                  listAddBackPointerPList,                    \
  List*:                 listAddBackPointerPListP,                   \
  const volatile List*:  listAddBackPointerPListP,                   \
  Queue:                 listAddBackPointerPQueue,                   \
  Queue*:                listAddBackPointerPQueueP,                  \
  const volatile Queue*: listAddBackPointerPQueueP,                  \
  Stack:                 listAddBackPointerPStack,                   \
  Stack*:                listAddBackPointerPStackP,                  \
  const volatile Stack*: listAddBackPointerPStackP,                  \
  RedBlackTree:          listAddBackPointerPRedBlackTree,            \
  RedBlackTree*:         listAddBackPointerPRedBlackTreeP,           \
  const volatile RedBlackTree*: listAddBackPointerPRedBlackTreeP,           \
  HashTable:             listAddBackPointerPHashTable,               \
  HashTable*:            listAddBackPointerPHashTableP,              \
  const volatile HashTable*: listAddBackPointerPHashTableP,              \
  Vector:                listAddBackPointerPVector,                  \
  Vector*:               listAddBackPointerPVectorP,                 \
  const volatile Vector*: listAddBackPointerPVectorP,                 \
  char*:                 listAddBackPointerPString,                  \
  const volatile char*:  listAddBackPointerPString,                  \
  char**:                listAddBackPointerPStringP,                 \
  const volatile char**: listAddBackPointerPStringP,                 \
  Bytes:                 listAddBackPointerPBytes,                   \
  Bytes*:                listAddBackPointerPBytesP,                  \
  const volatile Bytes*: listAddBackPointerPBytesP,                  \
  void*:                 listAddBackPointerPPointer,                 \
  void**:                listAddBackPointerPPointerP,                \
  const volatile void**: listAddBackPointerPPointerP,                \
  i8:                    listAddBackPointerI8,                       \
  u8:                    listAddBackPointerU8                        \

#define listAddBackPointerP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_BACK_GENERIC_CASES_POINTERP_KEY(dataStructure, key, value) \
  )


#define LIST_ADD_BACK_GENERIC_CASES(dataStructure, key, value) \
  bool:                  listAddBackBool(dataStructure, key, value), \
  bool*:                 listAddBackBoolP(dataStructure, key, value), \
  const volatile bool*:  listAddBackBoolP(dataStructure, key, value), \
  i16:                   listAddBackI16(dataStructure, key, value),  \
  i16*:                  listAddBackI16P(dataStructure, key, value), \
  const volatile i16*:   listAddBackI16P(dataStructure, key, value), \
  u16:                   listAddBackU16(dataStructure, key, value),  \
  u16*:                  listAddBackU16P(dataStructure, key, value), \
  const volatile u16*:   listAddBackU16P(dataStructure, key, value), \
  i32:                   listAddBackI32(dataStructure, key, value),  \
  i32*:                  listAddBackI32P(dataStructure, key, value), \
  const volatile i32*:   listAddBackI32P(dataStructure, key, value), \
  u32:                   listAddBackU32(dataStructure, key, value),  \
  u32*:                  listAddBackU32P(dataStructure, key, value), \
  const volatile u32*:   listAddBackU32P(dataStructure, key, value), \
  i64:                   listAddBackI64(dataStructure, key, value),  \
  i64*:                  listAddBackI64P(dataStructure, key, value), \
  const volatile i64*:   listAddBackI64P(dataStructure, key, value), \
  u64:                   listAddBackU64(dataStructure, key, value),  \
  u64*:                  listAddBackU64P(dataStructure, key, value), \
  const volatile u64*:   listAddBackU64P(dataStructure, key, value), \
  float:                 listAddBackFloat(dataStructure, key, value), \
  float*:                listAddBackFloatP(dataStructure, key, value), \
  const volatile float*: listAddBackFloatP(dataStructure, key, value), \
  double:                listAddBackDouble(dataStructure, key, value), \
  double*:               listAddBackDoubleP(dataStructure, key, value), \
  const volatile double*: listAddBackDoubleP(dataStructure, key, value), \
  long double:           listAddBackLongDouble(dataStructure, key, value), \
  long double*:          listAddBackLongDoubleP(dataStructure, key, value), \
  const volatile long double*: listAddBackLongDoubleP(dataStructure, key, value), \
  List:                  listAddBackList(dataStructure, key, value), \
  List*:                 listAddBackListP(dataStructure, key, value), \
  const volatile List*:  listAddBackListP(dataStructure, key, value), \
  Queue:                 listAddBackQueue(dataStructure, key, value), \
  Queue*:                listAddBackQueueP(dataStructure, key, value), \
  const volatile Queue*: listAddBackQueueP(dataStructure, key, value), \
  Stack:                 listAddBackStack(dataStructure, key, value), \
  Stack*:                listAddBackStackP(dataStructure, key, value), \
  const volatile Stack*: listAddBackStackP(dataStructure, key, value), \
  RedBlackTree:          listAddBackRedBlackTree(dataStructure, key, value), \
  RedBlackTree*:         listAddBackRedBlackTreeP(dataStructure, key, value), \
  const volatile RedBlackTree*: listAddBackRedBlackTreeP(dataStructure, key, value), \
  HashTable:             listAddBackHashTable(dataStructure, key, value), \
  HashTable*:            listAddBackHashTableP(dataStructure, key, value), \
  const volatile HashTable*: listAddBackHashTableP(dataStructure, key, value), \
  Vector:                listAddBackVector(dataStructure, key, value), \
  Vector*:               listAddBackVectorP(dataStructure, key, value), \
  const volatile Vector*: listAddBackVectorP(dataStructure, key, value), \
  char*:                 listAddBackString(dataStructure, key, value), \
  const volatile char*:  listAddBackString(dataStructure, key, value), \
  char**:                listAddBackStringP(dataStructure, key, value), \
  const volatile char**: listAddBackStringP(dataStructure, key, value), \
  Bytes:                 listAddBackBytes(dataStructure, key, value), \
  Bytes*:                listAddBackBytesP(dataStructure, key, value), \
  const volatile Bytes*: listAddBackBytesP(dataStructure, key, value), \
  void*:                 listAddBackPointer(dataStructure, key, value), \
  void**:                listAddBackPointerP(dataStructure, key, value), \
  const volatile void**: listAddBackPointerP(dataStructure, key, value), \
  i8:                    listAddBackI8(dataStructure, key, value),   \
  u8:                    listAddBackU8(dataStructure, key, value)    \

#define listAddBack(dataStructure, key, value) _Generic((key), \
  LIST_ADD_BACK_GENERIC_CASES(dataStructure, key, value) \
  )(dataStructure, key, value)

#endif // __STDC_VERSION__

#elif defined __cplusplus // __STDC_VERSION__ is *NOT* defined
#define TYPE_SAFE_LIST

// Define the C++ function overloads.

static inline ListNode* listAddBack(List *dataStructure, bool key, bool value) {
  return listAddBackBoolBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile bool* value) {
  return listAddBackBoolBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, bool value) {
  return listAddBackBoolPBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile bool* value) {
  return listAddBackBoolPBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, i16 value) {
  return listAddBackBoolI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile i16* value) {
  return listAddBackBoolI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, i16 value) {
  return listAddBackBoolPI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile i16* value) {
  return listAddBackBoolPI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, u16 value) {
  return listAddBackBoolU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile u16* value) {
  return listAddBackBoolU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, u16 value) {
  return listAddBackBoolPU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile u16* value) {
  return listAddBackBoolPU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, i32 value) {
  return listAddBackBoolI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile i32* value) {
  return listAddBackBoolI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, i32 value) {
  return listAddBackBoolPI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile i32* value) {
  return listAddBackBoolPI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, u32 value) {
  return listAddBackBoolU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile u32* value) {
  return listAddBackBoolU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, u32 value) {
  return listAddBackBoolPU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile u32* value) {
  return listAddBackBoolPU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, i64 value) {
  return listAddBackBoolI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile i64* value) {
  return listAddBackBoolI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, i64 value) {
  return listAddBackBoolPI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile i64* value) {
  return listAddBackBoolPI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, u64 value) {
  return listAddBackBoolU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile u64* value) {
  return listAddBackBoolU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, u64 value) {
  return listAddBackBoolPU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile u64* value) {
  return listAddBackBoolPU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, float value) {
  return listAddBackBoolFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile float* value) {
  return listAddBackBoolFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, float value) {
  return listAddBackBoolPFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile float* value) {
  return listAddBackBoolPFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, double value) {
  return listAddBackBoolDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile double* value) {
  return listAddBackBoolDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, double value) {
  return listAddBackBoolPDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile double* value) {
  return listAddBackBoolPDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, long double value) {
  return listAddBackBoolLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile long double* value) {
  return listAddBackBoolLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, long double value) {
  return listAddBackBoolPLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile long double* value) {
  return listAddBackBoolPLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, List value) {
  return listAddBackBoolList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile List* value) {
  return listAddBackBoolListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, List value) {
  return listAddBackBoolPList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile List* value) {
  return listAddBackBoolPListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, Queue value) {
  return listAddBackBoolQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile Queue* value) {
  return listAddBackBoolQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, Queue value) {
  return listAddBackBoolPQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile Queue* value) {
  return listAddBackBoolPQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, Stack value) {
  return listAddBackBoolStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile Stack* value) {
  return listAddBackBoolStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, Stack value) {
  return listAddBackBoolPStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile Stack* value) {
  return listAddBackBoolPStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, RedBlackTree value) {
  return listAddBackBoolRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile RedBlackTree* value) {
  return listAddBackBoolRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, RedBlackTree value) {
  return listAddBackBoolPRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile RedBlackTree* value) {
  return listAddBackBoolPRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, HashTable value) {
  return listAddBackBoolHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile HashTable* value) {
  return listAddBackBoolHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, HashTable value) {
  return listAddBackBoolPHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile HashTable* value) {
  return listAddBackBoolPHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, Vector value) {
  return listAddBackBoolVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile Vector* value) {
  return listAddBackBoolVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, Vector value) {
  return listAddBackBoolPVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile Vector* value) {
  return listAddBackBoolPVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile char* value) {
  return listAddBackBoolString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile char** value) {
  return listAddBackBoolStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile char* value) {
  return listAddBackBoolPString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile char** value) {
  return listAddBackBoolPStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, Bytes value) {
  return listAddBackBoolBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile Bytes* value) {
  return listAddBackBoolBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, Bytes value) {
  return listAddBackBoolPBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile Bytes* value) {
  return listAddBackBoolPBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, void* value) {
  return listAddBackBoolPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, const volatile void** value) {
  return listAddBackBoolPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, void* value) {
  return listAddBackBoolPPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, const volatile void** value) {
  return listAddBackBoolPPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, i8 value) {
  return listAddBackBoolI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, i8 value) {
  return listAddBackBoolPI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, bool key, u8 value) {
  return listAddBackBoolU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile bool* key, u8 value) {
  return listAddBackBoolPU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, bool value) {
  return listAddBackI16Bool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile bool* value) {
  return listAddBackI16BoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, bool value) {
  return listAddBackI16PBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile bool* value) {
  return listAddBackI16PBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, i16 value) {
  return listAddBackI16I16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile i16* value) {
  return listAddBackI16I16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, i16 value) {
  return listAddBackI16PI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile i16* value) {
  return listAddBackI16PI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, u16 value) {
  return listAddBackI16U16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile u16* value) {
  return listAddBackI16U16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, u16 value) {
  return listAddBackI16PU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile u16* value) {
  return listAddBackI16PU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, i32 value) {
  return listAddBackI16I32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile i32* value) {
  return listAddBackI16I32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, i32 value) {
  return listAddBackI16PI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile i32* value) {
  return listAddBackI16PI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, u32 value) {
  return listAddBackI16U32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile u32* value) {
  return listAddBackI16U32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, u32 value) {
  return listAddBackI16PU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile u32* value) {
  return listAddBackI16PU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, i64 value) {
  return listAddBackI16I64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile i64* value) {
  return listAddBackI16I64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, i64 value) {
  return listAddBackI16PI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile i64* value) {
  return listAddBackI16PI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, u64 value) {
  return listAddBackI16U64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile u64* value) {
  return listAddBackI16U64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, u64 value) {
  return listAddBackI16PU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile u64* value) {
  return listAddBackI16PU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, float value) {
  return listAddBackI16Float(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile float* value) {
  return listAddBackI16FloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, float value) {
  return listAddBackI16PFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile float* value) {
  return listAddBackI16PFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, double value) {
  return listAddBackI16Double(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile double* value) {
  return listAddBackI16DoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, double value) {
  return listAddBackI16PDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile double* value) {
  return listAddBackI16PDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, long double value) {
  return listAddBackI16LongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile long double* value) {
  return listAddBackI16LongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, long double value) {
  return listAddBackI16PLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile long double* value) {
  return listAddBackI16PLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, List value) {
  return listAddBackI16List(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile List* value) {
  return listAddBackI16ListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, List value) {
  return listAddBackI16PList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile List* value) {
  return listAddBackI16PListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, Queue value) {
  return listAddBackI16Queue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile Queue* value) {
  return listAddBackI16QueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, Queue value) {
  return listAddBackI16PQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile Queue* value) {
  return listAddBackI16PQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, Stack value) {
  return listAddBackI16Stack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile Stack* value) {
  return listAddBackI16StackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, Stack value) {
  return listAddBackI16PStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile Stack* value) {
  return listAddBackI16PStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, RedBlackTree value) {
  return listAddBackI16RedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile RedBlackTree* value) {
  return listAddBackI16RedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, RedBlackTree value) {
  return listAddBackI16PRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile RedBlackTree* value) {
  return listAddBackI16PRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, HashTable value) {
  return listAddBackI16HashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile HashTable* value) {
  return listAddBackI16HashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, HashTable value) {
  return listAddBackI16PHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile HashTable* value) {
  return listAddBackI16PHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, Vector value) {
  return listAddBackI16Vector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile Vector* value) {
  return listAddBackI16VectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, Vector value) {
  return listAddBackI16PVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile Vector* value) {
  return listAddBackI16PVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile char* value) {
  return listAddBackI16String(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile char** value) {
  return listAddBackI16StringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile char* value) {
  return listAddBackI16PString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile char** value) {
  return listAddBackI16PStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, Bytes value) {
  return listAddBackI16Bytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile Bytes* value) {
  return listAddBackI16BytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, Bytes value) {
  return listAddBackI16PBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile Bytes* value) {
  return listAddBackI16PBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, void* value) {
  return listAddBackI16Pointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, const volatile void** value) {
  return listAddBackI16PointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, void* value) {
  return listAddBackI16PPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, const volatile void** value) {
  return listAddBackI16PPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, i8 value) {
  return listAddBackI16I8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, i8 value) {
  return listAddBackI16PI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i16 key, u8 value) {
  return listAddBackI16U8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i16* key, u8 value) {
  return listAddBackI16PU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, bool value) {
  return listAddBackU16Bool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile bool* value) {
  return listAddBackU16BoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, bool value) {
  return listAddBackU16PBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile bool* value) {
  return listAddBackU16PBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, i16 value) {
  return listAddBackU16I16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile i16* value) {
  return listAddBackU16I16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, i16 value) {
  return listAddBackU16PI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile i16* value) {
  return listAddBackU16PI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, u16 value) {
  return listAddBackU16U16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile u16* value) {
  return listAddBackU16U16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, u16 value) {
  return listAddBackU16PU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile u16* value) {
  return listAddBackU16PU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, i32 value) {
  return listAddBackU16I32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile i32* value) {
  return listAddBackU16I32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, i32 value) {
  return listAddBackU16PI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile i32* value) {
  return listAddBackU16PI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, u32 value) {
  return listAddBackU16U32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile u32* value) {
  return listAddBackU16U32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, u32 value) {
  return listAddBackU16PU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile u32* value) {
  return listAddBackU16PU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, i64 value) {
  return listAddBackU16I64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile i64* value) {
  return listAddBackU16I64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, i64 value) {
  return listAddBackU16PI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile i64* value) {
  return listAddBackU16PI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, u64 value) {
  return listAddBackU16U64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile u64* value) {
  return listAddBackU16U64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, u64 value) {
  return listAddBackU16PU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile u64* value) {
  return listAddBackU16PU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, float value) {
  return listAddBackU16Float(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile float* value) {
  return listAddBackU16FloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, float value) {
  return listAddBackU16PFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile float* value) {
  return listAddBackU16PFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, double value) {
  return listAddBackU16Double(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile double* value) {
  return listAddBackU16DoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, double value) {
  return listAddBackU16PDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile double* value) {
  return listAddBackU16PDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, long double value) {
  return listAddBackU16LongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile long double* value) {
  return listAddBackU16LongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, long double value) {
  return listAddBackU16PLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile long double* value) {
  return listAddBackU16PLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, List value) {
  return listAddBackU16List(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile List* value) {
  return listAddBackU16ListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, List value) {
  return listAddBackU16PList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile List* value) {
  return listAddBackU16PListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, Queue value) {
  return listAddBackU16Queue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile Queue* value) {
  return listAddBackU16QueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, Queue value) {
  return listAddBackU16PQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile Queue* value) {
  return listAddBackU16PQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, Stack value) {
  return listAddBackU16Stack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile Stack* value) {
  return listAddBackU16StackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, Stack value) {
  return listAddBackU16PStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile Stack* value) {
  return listAddBackU16PStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, RedBlackTree value) {
  return listAddBackU16RedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile RedBlackTree* value) {
  return listAddBackU16RedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, RedBlackTree value) {
  return listAddBackU16PRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile RedBlackTree* value) {
  return listAddBackU16PRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, HashTable value) {
  return listAddBackU16HashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile HashTable* value) {
  return listAddBackU16HashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, HashTable value) {
  return listAddBackU16PHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile HashTable* value) {
  return listAddBackU16PHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, Vector value) {
  return listAddBackU16Vector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile Vector* value) {
  return listAddBackU16VectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, Vector value) {
  return listAddBackU16PVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile Vector* value) {
  return listAddBackU16PVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile char* value) {
  return listAddBackU16String(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile char** value) {
  return listAddBackU16StringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile char* value) {
  return listAddBackU16PString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile char** value) {
  return listAddBackU16PStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, Bytes value) {
  return listAddBackU16Bytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile Bytes* value) {
  return listAddBackU16BytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, Bytes value) {
  return listAddBackU16PBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile Bytes* value) {
  return listAddBackU16PBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, void* value) {
  return listAddBackU16Pointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, const volatile void** value) {
  return listAddBackU16PointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, void* value) {
  return listAddBackU16PPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, const volatile void** value) {
  return listAddBackU16PPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, i8 value) {
  return listAddBackU16I8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, i8 value) {
  return listAddBackU16PI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u16 key, u8 value) {
  return listAddBackU16U8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u16* key, u8 value) {
  return listAddBackU16PU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, bool value) {
  return listAddBackI32Bool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile bool* value) {
  return listAddBackI32BoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, bool value) {
  return listAddBackI32PBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile bool* value) {
  return listAddBackI32PBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, i16 value) {
  return listAddBackI32I16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile i16* value) {
  return listAddBackI32I16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, i16 value) {
  return listAddBackI32PI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile i16* value) {
  return listAddBackI32PI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, u16 value) {
  return listAddBackI32U16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile u16* value) {
  return listAddBackI32U16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, u16 value) {
  return listAddBackI32PU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile u16* value) {
  return listAddBackI32PU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, i32 value) {
  return listAddBackI32I32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile i32* value) {
  return listAddBackI32I32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, i32 value) {
  return listAddBackI32PI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile i32* value) {
  return listAddBackI32PI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, u32 value) {
  return listAddBackI32U32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile u32* value) {
  return listAddBackI32U32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, u32 value) {
  return listAddBackI32PU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile u32* value) {
  return listAddBackI32PU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, i64 value) {
  return listAddBackI32I64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile i64* value) {
  return listAddBackI32I64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, i64 value) {
  return listAddBackI32PI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile i64* value) {
  return listAddBackI32PI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, u64 value) {
  return listAddBackI32U64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile u64* value) {
  return listAddBackI32U64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, u64 value) {
  return listAddBackI32PU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile u64* value) {
  return listAddBackI32PU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, float value) {
  return listAddBackI32Float(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile float* value) {
  return listAddBackI32FloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, float value) {
  return listAddBackI32PFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile float* value) {
  return listAddBackI32PFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, double value) {
  return listAddBackI32Double(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile double* value) {
  return listAddBackI32DoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, double value) {
  return listAddBackI32PDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile double* value) {
  return listAddBackI32PDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, long double value) {
  return listAddBackI32LongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile long double* value) {
  return listAddBackI32LongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, long double value) {
  return listAddBackI32PLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile long double* value) {
  return listAddBackI32PLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, List value) {
  return listAddBackI32List(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile List* value) {
  return listAddBackI32ListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, List value) {
  return listAddBackI32PList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile List* value) {
  return listAddBackI32PListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, Queue value) {
  return listAddBackI32Queue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile Queue* value) {
  return listAddBackI32QueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, Queue value) {
  return listAddBackI32PQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile Queue* value) {
  return listAddBackI32PQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, Stack value) {
  return listAddBackI32Stack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile Stack* value) {
  return listAddBackI32StackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, Stack value) {
  return listAddBackI32PStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile Stack* value) {
  return listAddBackI32PStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, RedBlackTree value) {
  return listAddBackI32RedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile RedBlackTree* value) {
  return listAddBackI32RedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, RedBlackTree value) {
  return listAddBackI32PRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile RedBlackTree* value) {
  return listAddBackI32PRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, HashTable value) {
  return listAddBackI32HashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile HashTable* value) {
  return listAddBackI32HashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, HashTable value) {
  return listAddBackI32PHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile HashTable* value) {
  return listAddBackI32PHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, Vector value) {
  return listAddBackI32Vector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile Vector* value) {
  return listAddBackI32VectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, Vector value) {
  return listAddBackI32PVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile Vector* value) {
  return listAddBackI32PVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile char* value) {
  return listAddBackI32String(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile char** value) {
  return listAddBackI32StringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile char* value) {
  return listAddBackI32PString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile char** value) {
  return listAddBackI32PStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, Bytes value) {
  return listAddBackI32Bytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile Bytes* value) {
  return listAddBackI32BytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, Bytes value) {
  return listAddBackI32PBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile Bytes* value) {
  return listAddBackI32PBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, void* value) {
  return listAddBackI32Pointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, const volatile void** value) {
  return listAddBackI32PointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, void* value) {
  return listAddBackI32PPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, const volatile void** value) {
  return listAddBackI32PPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, i8 value) {
  return listAddBackI32I8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, i8 value) {
  return listAddBackI32PI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i32 key, u8 value) {
  return listAddBackI32U8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i32* key, u8 value) {
  return listAddBackI32PU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, bool value) {
  return listAddBackU32Bool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile bool* value) {
  return listAddBackU32BoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, bool value) {
  return listAddBackU32PBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile bool* value) {
  return listAddBackU32PBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, i16 value) {
  return listAddBackU32I16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile i16* value) {
  return listAddBackU32I16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, i16 value) {
  return listAddBackU32PI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile i16* value) {
  return listAddBackU32PI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, u16 value) {
  return listAddBackU32U16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile u16* value) {
  return listAddBackU32U16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, u16 value) {
  return listAddBackU32PU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile u16* value) {
  return listAddBackU32PU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, i32 value) {
  return listAddBackU32I32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile i32* value) {
  return listAddBackU32I32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, i32 value) {
  return listAddBackU32PI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile i32* value) {
  return listAddBackU32PI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, u32 value) {
  return listAddBackU32U32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile u32* value) {
  return listAddBackU32U32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, u32 value) {
  return listAddBackU32PU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile u32* value) {
  return listAddBackU32PU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, i64 value) {
  return listAddBackU32I64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile i64* value) {
  return listAddBackU32I64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, i64 value) {
  return listAddBackU32PI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile i64* value) {
  return listAddBackU32PI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, u64 value) {
  return listAddBackU32U64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile u64* value) {
  return listAddBackU32U64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, u64 value) {
  return listAddBackU32PU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile u64* value) {
  return listAddBackU32PU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, float value) {
  return listAddBackU32Float(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile float* value) {
  return listAddBackU32FloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, float value) {
  return listAddBackU32PFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile float* value) {
  return listAddBackU32PFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, double value) {
  return listAddBackU32Double(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile double* value) {
  return listAddBackU32DoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, double value) {
  return listAddBackU32PDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile double* value) {
  return listAddBackU32PDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, long double value) {
  return listAddBackU32LongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile long double* value) {
  return listAddBackU32LongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, long double value) {
  return listAddBackU32PLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile long double* value) {
  return listAddBackU32PLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, List value) {
  return listAddBackU32List(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile List* value) {
  return listAddBackU32ListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, List value) {
  return listAddBackU32PList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile List* value) {
  return listAddBackU32PListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, Queue value) {
  return listAddBackU32Queue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile Queue* value) {
  return listAddBackU32QueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, Queue value) {
  return listAddBackU32PQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile Queue* value) {
  return listAddBackU32PQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, Stack value) {
  return listAddBackU32Stack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile Stack* value) {
  return listAddBackU32StackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, Stack value) {
  return listAddBackU32PStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile Stack* value) {
  return listAddBackU32PStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, RedBlackTree value) {
  return listAddBackU32RedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile RedBlackTree* value) {
  return listAddBackU32RedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, RedBlackTree value) {
  return listAddBackU32PRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile RedBlackTree* value) {
  return listAddBackU32PRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, HashTable value) {
  return listAddBackU32HashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile HashTable* value) {
  return listAddBackU32HashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, HashTable value) {
  return listAddBackU32PHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile HashTable* value) {
  return listAddBackU32PHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, Vector value) {
  return listAddBackU32Vector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile Vector* value) {
  return listAddBackU32VectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, Vector value) {
  return listAddBackU32PVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile Vector* value) {
  return listAddBackU32PVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile char* value) {
  return listAddBackU32String(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile char** value) {
  return listAddBackU32StringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile char* value) {
  return listAddBackU32PString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile char** value) {
  return listAddBackU32PStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, Bytes value) {
  return listAddBackU32Bytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile Bytes* value) {
  return listAddBackU32BytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, Bytes value) {
  return listAddBackU32PBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile Bytes* value) {
  return listAddBackU32PBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, void* value) {
  return listAddBackU32Pointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, const volatile void** value) {
  return listAddBackU32PointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, void* value) {
  return listAddBackU32PPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, const volatile void** value) {
  return listAddBackU32PPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, i8 value) {
  return listAddBackU32I8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, i8 value) {
  return listAddBackU32PI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u32 key, u8 value) {
  return listAddBackU32U8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u32* key, u8 value) {
  return listAddBackU32PU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, bool value) {
  return listAddBackI64Bool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile bool* value) {
  return listAddBackI64BoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, bool value) {
  return listAddBackI64PBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile bool* value) {
  return listAddBackI64PBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, i16 value) {
  return listAddBackI64I16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile i16* value) {
  return listAddBackI64I16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, i16 value) {
  return listAddBackI64PI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile i16* value) {
  return listAddBackI64PI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, u16 value) {
  return listAddBackI64U16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile u16* value) {
  return listAddBackI64U16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, u16 value) {
  return listAddBackI64PU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile u16* value) {
  return listAddBackI64PU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, i32 value) {
  return listAddBackI64I32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile i32* value) {
  return listAddBackI64I32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, i32 value) {
  return listAddBackI64PI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile i32* value) {
  return listAddBackI64PI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, u32 value) {
  return listAddBackI64U32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile u32* value) {
  return listAddBackI64U32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, u32 value) {
  return listAddBackI64PU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile u32* value) {
  return listAddBackI64PU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, i64 value) {
  return listAddBackI64I64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile i64* value) {
  return listAddBackI64I64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, i64 value) {
  return listAddBackI64PI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile i64* value) {
  return listAddBackI64PI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, u64 value) {
  return listAddBackI64U64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile u64* value) {
  return listAddBackI64U64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, u64 value) {
  return listAddBackI64PU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile u64* value) {
  return listAddBackI64PU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, float value) {
  return listAddBackI64Float(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile float* value) {
  return listAddBackI64FloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, float value) {
  return listAddBackI64PFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile float* value) {
  return listAddBackI64PFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, double value) {
  return listAddBackI64Double(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile double* value) {
  return listAddBackI64DoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, double value) {
  return listAddBackI64PDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile double* value) {
  return listAddBackI64PDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, long double value) {
  return listAddBackI64LongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile long double* value) {
  return listAddBackI64LongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, long double value) {
  return listAddBackI64PLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile long double* value) {
  return listAddBackI64PLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, List value) {
  return listAddBackI64List(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile List* value) {
  return listAddBackI64ListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, List value) {
  return listAddBackI64PList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile List* value) {
  return listAddBackI64PListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, Queue value) {
  return listAddBackI64Queue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile Queue* value) {
  return listAddBackI64QueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, Queue value) {
  return listAddBackI64PQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile Queue* value) {
  return listAddBackI64PQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, Stack value) {
  return listAddBackI64Stack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile Stack* value) {
  return listAddBackI64StackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, Stack value) {
  return listAddBackI64PStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile Stack* value) {
  return listAddBackI64PStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, RedBlackTree value) {
  return listAddBackI64RedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile RedBlackTree* value) {
  return listAddBackI64RedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, RedBlackTree value) {
  return listAddBackI64PRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile RedBlackTree* value) {
  return listAddBackI64PRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, HashTable value) {
  return listAddBackI64HashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile HashTable* value) {
  return listAddBackI64HashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, HashTable value) {
  return listAddBackI64PHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile HashTable* value) {
  return listAddBackI64PHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, Vector value) {
  return listAddBackI64Vector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile Vector* value) {
  return listAddBackI64VectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, Vector value) {
  return listAddBackI64PVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile Vector* value) {
  return listAddBackI64PVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile char* value) {
  return listAddBackI64String(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile char** value) {
  return listAddBackI64StringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile char* value) {
  return listAddBackI64PString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile char** value) {
  return listAddBackI64PStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, Bytes value) {
  return listAddBackI64Bytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile Bytes* value) {
  return listAddBackI64BytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, Bytes value) {
  return listAddBackI64PBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile Bytes* value) {
  return listAddBackI64PBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, void* value) {
  return listAddBackI64Pointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, const volatile void** value) {
  return listAddBackI64PointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, void* value) {
  return listAddBackI64PPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, const volatile void** value) {
  return listAddBackI64PPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, i8 value) {
  return listAddBackI64I8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, i8 value) {
  return listAddBackI64PI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i64 key, u8 value) {
  return listAddBackI64U8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile i64* key, u8 value) {
  return listAddBackI64PU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, bool value) {
  return listAddBackU64Bool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile bool* value) {
  return listAddBackU64BoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, bool value) {
  return listAddBackU64PBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile bool* value) {
  return listAddBackU64PBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, i16 value) {
  return listAddBackU64I16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile i16* value) {
  return listAddBackU64I16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, i16 value) {
  return listAddBackU64PI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile i16* value) {
  return listAddBackU64PI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, u16 value) {
  return listAddBackU64U16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile u16* value) {
  return listAddBackU64U16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, u16 value) {
  return listAddBackU64PU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile u16* value) {
  return listAddBackU64PU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, i32 value) {
  return listAddBackU64I32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile i32* value) {
  return listAddBackU64I32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, i32 value) {
  return listAddBackU64PI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile i32* value) {
  return listAddBackU64PI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, u32 value) {
  return listAddBackU64U32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile u32* value) {
  return listAddBackU64U32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, u32 value) {
  return listAddBackU64PU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile u32* value) {
  return listAddBackU64PU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, i64 value) {
  return listAddBackU64I64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile i64* value) {
  return listAddBackU64I64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, i64 value) {
  return listAddBackU64PI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile i64* value) {
  return listAddBackU64PI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, u64 value) {
  return listAddBackU64U64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile u64* value) {
  return listAddBackU64U64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, u64 value) {
  return listAddBackU64PU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile u64* value) {
  return listAddBackU64PU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, float value) {
  return listAddBackU64Float(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile float* value) {
  return listAddBackU64FloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, float value) {
  return listAddBackU64PFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile float* value) {
  return listAddBackU64PFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, double value) {
  return listAddBackU64Double(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile double* value) {
  return listAddBackU64DoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, double value) {
  return listAddBackU64PDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile double* value) {
  return listAddBackU64PDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, long double value) {
  return listAddBackU64LongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile long double* value) {
  return listAddBackU64LongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, long double value) {
  return listAddBackU64PLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile long double* value) {
  return listAddBackU64PLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, List value) {
  return listAddBackU64List(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile List* value) {
  return listAddBackU64ListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, List value) {
  return listAddBackU64PList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile List* value) {
  return listAddBackU64PListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, Queue value) {
  return listAddBackU64Queue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile Queue* value) {
  return listAddBackU64QueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, Queue value) {
  return listAddBackU64PQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile Queue* value) {
  return listAddBackU64PQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, Stack value) {
  return listAddBackU64Stack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile Stack* value) {
  return listAddBackU64StackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, Stack value) {
  return listAddBackU64PStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile Stack* value) {
  return listAddBackU64PStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, RedBlackTree value) {
  return listAddBackU64RedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile RedBlackTree* value) {
  return listAddBackU64RedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, RedBlackTree value) {
  return listAddBackU64PRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile RedBlackTree* value) {
  return listAddBackU64PRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, HashTable value) {
  return listAddBackU64HashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile HashTable* value) {
  return listAddBackU64HashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, HashTable value) {
  return listAddBackU64PHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile HashTable* value) {
  return listAddBackU64PHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, Vector value) {
  return listAddBackU64Vector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile Vector* value) {
  return listAddBackU64VectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, Vector value) {
  return listAddBackU64PVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile Vector* value) {
  return listAddBackU64PVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile char* value) {
  return listAddBackU64String(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile char** value) {
  return listAddBackU64StringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile char* value) {
  return listAddBackU64PString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile char** value) {
  return listAddBackU64PStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, Bytes value) {
  return listAddBackU64Bytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile Bytes* value) {
  return listAddBackU64BytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, Bytes value) {
  return listAddBackU64PBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile Bytes* value) {
  return listAddBackU64PBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, void* value) {
  return listAddBackU64Pointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, const volatile void** value) {
  return listAddBackU64PointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, void* value) {
  return listAddBackU64PPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, const volatile void** value) {
  return listAddBackU64PPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, i8 value) {
  return listAddBackU64I8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, i8 value) {
  return listAddBackU64PI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u64 key, u8 value) {
  return listAddBackU64U8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile u64* key, u8 value) {
  return listAddBackU64PU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, bool value) {
  return listAddBackFloatBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile bool* value) {
  return listAddBackFloatBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, bool value) {
  return listAddBackFloatPBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile bool* value) {
  return listAddBackFloatPBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, i16 value) {
  return listAddBackFloatI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile i16* value) {
  return listAddBackFloatI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, i16 value) {
  return listAddBackFloatPI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile i16* value) {
  return listAddBackFloatPI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, u16 value) {
  return listAddBackFloatU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile u16* value) {
  return listAddBackFloatU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, u16 value) {
  return listAddBackFloatPU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile u16* value) {
  return listAddBackFloatPU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, i32 value) {
  return listAddBackFloatI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile i32* value) {
  return listAddBackFloatI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, i32 value) {
  return listAddBackFloatPI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile i32* value) {
  return listAddBackFloatPI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, u32 value) {
  return listAddBackFloatU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile u32* value) {
  return listAddBackFloatU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, u32 value) {
  return listAddBackFloatPU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile u32* value) {
  return listAddBackFloatPU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, i64 value) {
  return listAddBackFloatI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile i64* value) {
  return listAddBackFloatI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, i64 value) {
  return listAddBackFloatPI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile i64* value) {
  return listAddBackFloatPI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, u64 value) {
  return listAddBackFloatU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile u64* value) {
  return listAddBackFloatU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, u64 value) {
  return listAddBackFloatPU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile u64* value) {
  return listAddBackFloatPU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, float value) {
  return listAddBackFloatFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile float* value) {
  return listAddBackFloatFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, float value) {
  return listAddBackFloatPFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile float* value) {
  return listAddBackFloatPFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, double value) {
  return listAddBackFloatDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile double* value) {
  return listAddBackFloatDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, double value) {
  return listAddBackFloatPDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile double* value) {
  return listAddBackFloatPDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, long double value) {
  return listAddBackFloatLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile long double* value) {
  return listAddBackFloatLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, long double value) {
  return listAddBackFloatPLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile long double* value) {
  return listAddBackFloatPLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, List value) {
  return listAddBackFloatList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile List* value) {
  return listAddBackFloatListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, List value) {
  return listAddBackFloatPList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile List* value) {
  return listAddBackFloatPListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, Queue value) {
  return listAddBackFloatQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile Queue* value) {
  return listAddBackFloatQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, Queue value) {
  return listAddBackFloatPQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile Queue* value) {
  return listAddBackFloatPQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, Stack value) {
  return listAddBackFloatStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile Stack* value) {
  return listAddBackFloatStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, Stack value) {
  return listAddBackFloatPStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile Stack* value) {
  return listAddBackFloatPStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, RedBlackTree value) {
  return listAddBackFloatRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile RedBlackTree* value) {
  return listAddBackFloatRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, RedBlackTree value) {
  return listAddBackFloatPRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile RedBlackTree* value) {
  return listAddBackFloatPRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, HashTable value) {
  return listAddBackFloatHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile HashTable* value) {
  return listAddBackFloatHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, HashTable value) {
  return listAddBackFloatPHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile HashTable* value) {
  return listAddBackFloatPHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, Vector value) {
  return listAddBackFloatVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile Vector* value) {
  return listAddBackFloatVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, Vector value) {
  return listAddBackFloatPVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile Vector* value) {
  return listAddBackFloatPVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile char* value) {
  return listAddBackFloatString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile char** value) {
  return listAddBackFloatStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile char* value) {
  return listAddBackFloatPString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile char** value) {
  return listAddBackFloatPStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, Bytes value) {
  return listAddBackFloatBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile Bytes* value) {
  return listAddBackFloatBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, Bytes value) {
  return listAddBackFloatPBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile Bytes* value) {
  return listAddBackFloatPBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, void* value) {
  return listAddBackFloatPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, const volatile void** value) {
  return listAddBackFloatPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, void* value) {
  return listAddBackFloatPPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, const volatile void** value) {
  return listAddBackFloatPPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, i8 value) {
  return listAddBackFloatI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, i8 value) {
  return listAddBackFloatPI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, float key, u8 value) {
  return listAddBackFloatU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile float* key, u8 value) {
  return listAddBackFloatPU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, bool value) {
  return listAddBackDoubleBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile bool* value) {
  return listAddBackDoubleBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, bool value) {
  return listAddBackDoublePBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile bool* value) {
  return listAddBackDoublePBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, i16 value) {
  return listAddBackDoubleI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile i16* value) {
  return listAddBackDoubleI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, i16 value) {
  return listAddBackDoublePI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile i16* value) {
  return listAddBackDoublePI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, u16 value) {
  return listAddBackDoubleU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile u16* value) {
  return listAddBackDoubleU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, u16 value) {
  return listAddBackDoublePU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile u16* value) {
  return listAddBackDoublePU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, i32 value) {
  return listAddBackDoubleI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile i32* value) {
  return listAddBackDoubleI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, i32 value) {
  return listAddBackDoublePI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile i32* value) {
  return listAddBackDoublePI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, u32 value) {
  return listAddBackDoubleU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile u32* value) {
  return listAddBackDoubleU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, u32 value) {
  return listAddBackDoublePU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile u32* value) {
  return listAddBackDoublePU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, i64 value) {
  return listAddBackDoubleI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile i64* value) {
  return listAddBackDoubleI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, i64 value) {
  return listAddBackDoublePI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile i64* value) {
  return listAddBackDoublePI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, u64 value) {
  return listAddBackDoubleU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile u64* value) {
  return listAddBackDoubleU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, u64 value) {
  return listAddBackDoublePU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile u64* value) {
  return listAddBackDoublePU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, float value) {
  return listAddBackDoubleFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile float* value) {
  return listAddBackDoubleFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, float value) {
  return listAddBackDoublePFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile float* value) {
  return listAddBackDoublePFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, double value) {
  return listAddBackDoubleDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile double* value) {
  return listAddBackDoubleDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, double value) {
  return listAddBackDoublePDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile double* value) {
  return listAddBackDoublePDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, long double value) {
  return listAddBackDoubleLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile long double* value) {
  return listAddBackDoubleLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, long double value) {
  return listAddBackDoublePLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile long double* value) {
  return listAddBackDoublePLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, List value) {
  return listAddBackDoubleList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile List* value) {
  return listAddBackDoubleListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, List value) {
  return listAddBackDoublePList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile List* value) {
  return listAddBackDoublePListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, Queue value) {
  return listAddBackDoubleQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile Queue* value) {
  return listAddBackDoubleQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, Queue value) {
  return listAddBackDoublePQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile Queue* value) {
  return listAddBackDoublePQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, Stack value) {
  return listAddBackDoubleStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile Stack* value) {
  return listAddBackDoubleStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, Stack value) {
  return listAddBackDoublePStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile Stack* value) {
  return listAddBackDoublePStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, RedBlackTree value) {
  return listAddBackDoubleRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile RedBlackTree* value) {
  return listAddBackDoubleRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, RedBlackTree value) {
  return listAddBackDoublePRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile RedBlackTree* value) {
  return listAddBackDoublePRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, HashTable value) {
  return listAddBackDoubleHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile HashTable* value) {
  return listAddBackDoubleHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, HashTable value) {
  return listAddBackDoublePHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile HashTable* value) {
  return listAddBackDoublePHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, Vector value) {
  return listAddBackDoubleVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile Vector* value) {
  return listAddBackDoubleVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, Vector value) {
  return listAddBackDoublePVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile Vector* value) {
  return listAddBackDoublePVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile char* value) {
  return listAddBackDoubleString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile char** value) {
  return listAddBackDoubleStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile char* value) {
  return listAddBackDoublePString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile char** value) {
  return listAddBackDoublePStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, Bytes value) {
  return listAddBackDoubleBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile Bytes* value) {
  return listAddBackDoubleBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, Bytes value) {
  return listAddBackDoublePBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile Bytes* value) {
  return listAddBackDoublePBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, void* value) {
  return listAddBackDoublePointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, const volatile void** value) {
  return listAddBackDoublePointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, void* value) {
  return listAddBackDoublePPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, const volatile void** value) {
  return listAddBackDoublePPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, i8 value) {
  return listAddBackDoubleI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, i8 value) {
  return listAddBackDoublePI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, double key, u8 value) {
  return listAddBackDoubleU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile double* key, u8 value) {
  return listAddBackDoublePU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, bool value) {
  return listAddBackLongDoubleBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile bool* value) {
  return listAddBackLongDoubleBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, bool value) {
  return listAddBackLongDoublePBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile bool* value) {
  return listAddBackLongDoublePBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, i16 value) {
  return listAddBackLongDoubleI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile i16* value) {
  return listAddBackLongDoubleI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, i16 value) {
  return listAddBackLongDoublePI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile i16* value) {
  return listAddBackLongDoublePI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, u16 value) {
  return listAddBackLongDoubleU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile u16* value) {
  return listAddBackLongDoubleU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, u16 value) {
  return listAddBackLongDoublePU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile u16* value) {
  return listAddBackLongDoublePU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, i32 value) {
  return listAddBackLongDoubleI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile i32* value) {
  return listAddBackLongDoubleI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, i32 value) {
  return listAddBackLongDoublePI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile i32* value) {
  return listAddBackLongDoublePI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, u32 value) {
  return listAddBackLongDoubleU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile u32* value) {
  return listAddBackLongDoubleU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, u32 value) {
  return listAddBackLongDoublePU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile u32* value) {
  return listAddBackLongDoublePU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, i64 value) {
  return listAddBackLongDoubleI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile i64* value) {
  return listAddBackLongDoubleI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, i64 value) {
  return listAddBackLongDoublePI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile i64* value) {
  return listAddBackLongDoublePI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, u64 value) {
  return listAddBackLongDoubleU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile u64* value) {
  return listAddBackLongDoubleU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, u64 value) {
  return listAddBackLongDoublePU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile u64* value) {
  return listAddBackLongDoublePU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, float value) {
  return listAddBackLongDoubleFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile float* value) {
  return listAddBackLongDoubleFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, float value) {
  return listAddBackLongDoublePFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile float* value) {
  return listAddBackLongDoublePFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, double value) {
  return listAddBackLongDoubleDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile double* value) {
  return listAddBackLongDoubleDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, double value) {
  return listAddBackLongDoublePDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile double* value) {
  return listAddBackLongDoublePDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, long double value) {
  return listAddBackLongDoubleLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile long double* value) {
  return listAddBackLongDoubleLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, long double value) {
  return listAddBackLongDoublePLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile long double* value) {
  return listAddBackLongDoublePLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, List value) {
  return listAddBackLongDoubleList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile List* value) {
  return listAddBackLongDoubleListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, List value) {
  return listAddBackLongDoublePList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile List* value) {
  return listAddBackLongDoublePListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, Queue value) {
  return listAddBackLongDoubleQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile Queue* value) {
  return listAddBackLongDoubleQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, Queue value) {
  return listAddBackLongDoublePQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile Queue* value) {
  return listAddBackLongDoublePQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, Stack value) {
  return listAddBackLongDoubleStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile Stack* value) {
  return listAddBackLongDoubleStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, Stack value) {
  return listAddBackLongDoublePStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile Stack* value) {
  return listAddBackLongDoublePStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, RedBlackTree value) {
  return listAddBackLongDoubleRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile RedBlackTree* value) {
  return listAddBackLongDoubleRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, RedBlackTree value) {
  return listAddBackLongDoublePRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile RedBlackTree* value) {
  return listAddBackLongDoublePRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, HashTable value) {
  return listAddBackLongDoubleHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile HashTable* value) {
  return listAddBackLongDoubleHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, HashTable value) {
  return listAddBackLongDoublePHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile HashTable* value) {
  return listAddBackLongDoublePHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, Vector value) {
  return listAddBackLongDoubleVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile Vector* value) {
  return listAddBackLongDoubleVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, Vector value) {
  return listAddBackLongDoublePVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile Vector* value) {
  return listAddBackLongDoublePVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile char* value) {
  return listAddBackLongDoubleString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile char** value) {
  return listAddBackLongDoubleStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile char* value) {
  return listAddBackLongDoublePString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile char** value) {
  return listAddBackLongDoublePStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, Bytes value) {
  return listAddBackLongDoubleBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile Bytes* value) {
  return listAddBackLongDoubleBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, Bytes value) {
  return listAddBackLongDoublePBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile Bytes* value) {
  return listAddBackLongDoublePBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, void* value) {
  return listAddBackLongDoublePointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, const volatile void** value) {
  return listAddBackLongDoublePointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, void* value) {
  return listAddBackLongDoublePPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, const volatile void** value) {
  return listAddBackLongDoublePPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, i8 value) {
  return listAddBackLongDoubleI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, i8 value) {
  return listAddBackLongDoublePI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, long double key, u8 value) {
  return listAddBackLongDoubleU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile long double* key, u8 value) {
  return listAddBackLongDoublePU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, bool value) {
  return listAddBackListBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile bool* value) {
  return listAddBackListBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, bool value) {
  return listAddBackListPBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile bool* value) {
  return listAddBackListPBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, i16 value) {
  return listAddBackListI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile i16* value) {
  return listAddBackListI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, i16 value) {
  return listAddBackListPI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile i16* value) {
  return listAddBackListPI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, u16 value) {
  return listAddBackListU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile u16* value) {
  return listAddBackListU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, u16 value) {
  return listAddBackListPU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile u16* value) {
  return listAddBackListPU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, i32 value) {
  return listAddBackListI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile i32* value) {
  return listAddBackListI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, i32 value) {
  return listAddBackListPI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile i32* value) {
  return listAddBackListPI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, u32 value) {
  return listAddBackListU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile u32* value) {
  return listAddBackListU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, u32 value) {
  return listAddBackListPU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile u32* value) {
  return listAddBackListPU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, i64 value) {
  return listAddBackListI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile i64* value) {
  return listAddBackListI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, i64 value) {
  return listAddBackListPI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile i64* value) {
  return listAddBackListPI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, u64 value) {
  return listAddBackListU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile u64* value) {
  return listAddBackListU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, u64 value) {
  return listAddBackListPU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile u64* value) {
  return listAddBackListPU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, float value) {
  return listAddBackListFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile float* value) {
  return listAddBackListFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, float value) {
  return listAddBackListPFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile float* value) {
  return listAddBackListPFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, double value) {
  return listAddBackListDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile double* value) {
  return listAddBackListDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, double value) {
  return listAddBackListPDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile double* value) {
  return listAddBackListPDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, long double value) {
  return listAddBackListLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile long double* value) {
  return listAddBackListLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, long double value) {
  return listAddBackListPLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile long double* value) {
  return listAddBackListPLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, List value) {
  return listAddBackListList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile List* value) {
  return listAddBackListListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, List value) {
  return listAddBackListPList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile List* value) {
  return listAddBackListPListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, Queue value) {
  return listAddBackListQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile Queue* value) {
  return listAddBackListQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, Queue value) {
  return listAddBackListPQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile Queue* value) {
  return listAddBackListPQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, Stack value) {
  return listAddBackListStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile Stack* value) {
  return listAddBackListStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, Stack value) {
  return listAddBackListPStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile Stack* value) {
  return listAddBackListPStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, RedBlackTree value) {
  return listAddBackListRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile RedBlackTree* value) {
  return listAddBackListRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, RedBlackTree value) {
  return listAddBackListPRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile RedBlackTree* value) {
  return listAddBackListPRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, HashTable value) {
  return listAddBackListHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile HashTable* value) {
  return listAddBackListHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, HashTable value) {
  return listAddBackListPHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile HashTable* value) {
  return listAddBackListPHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, Vector value) {
  return listAddBackListVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile Vector* value) {
  return listAddBackListVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, Vector value) {
  return listAddBackListPVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile Vector* value) {
  return listAddBackListPVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile char* value) {
  return listAddBackListString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile char** value) {
  return listAddBackListStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile char* value) {
  return listAddBackListPString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile char** value) {
  return listAddBackListPStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, Bytes value) {
  return listAddBackListBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile Bytes* value) {
  return listAddBackListBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, Bytes value) {
  return listAddBackListPBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile Bytes* value) {
  return listAddBackListPBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, void* value) {
  return listAddBackListPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, const volatile void** value) {
  return listAddBackListPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, void* value) {
  return listAddBackListPPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, const volatile void** value) {
  return listAddBackListPPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, i8 value) {
  return listAddBackListI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, i8 value) {
  return listAddBackListPI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, List key, u8 value) {
  return listAddBackListU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile List* key, u8 value) {
  return listAddBackListPU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, bool value) {
  return listAddBackQueueBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile bool* value) {
  return listAddBackQueueBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, bool value) {
  return listAddBackQueuePBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile bool* value) {
  return listAddBackQueuePBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, i16 value) {
  return listAddBackQueueI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile i16* value) {
  return listAddBackQueueI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, i16 value) {
  return listAddBackQueuePI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile i16* value) {
  return listAddBackQueuePI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, u16 value) {
  return listAddBackQueueU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile u16* value) {
  return listAddBackQueueU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, u16 value) {
  return listAddBackQueuePU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile u16* value) {
  return listAddBackQueuePU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, i32 value) {
  return listAddBackQueueI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile i32* value) {
  return listAddBackQueueI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, i32 value) {
  return listAddBackQueuePI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile i32* value) {
  return listAddBackQueuePI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, u32 value) {
  return listAddBackQueueU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile u32* value) {
  return listAddBackQueueU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, u32 value) {
  return listAddBackQueuePU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile u32* value) {
  return listAddBackQueuePU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, i64 value) {
  return listAddBackQueueI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile i64* value) {
  return listAddBackQueueI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, i64 value) {
  return listAddBackQueuePI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile i64* value) {
  return listAddBackQueuePI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, u64 value) {
  return listAddBackQueueU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile u64* value) {
  return listAddBackQueueU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, u64 value) {
  return listAddBackQueuePU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile u64* value) {
  return listAddBackQueuePU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, float value) {
  return listAddBackQueueFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile float* value) {
  return listAddBackQueueFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, float value) {
  return listAddBackQueuePFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile float* value) {
  return listAddBackQueuePFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, double value) {
  return listAddBackQueueDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile double* value) {
  return listAddBackQueueDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, double value) {
  return listAddBackQueuePDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile double* value) {
  return listAddBackQueuePDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, long double value) {
  return listAddBackQueueLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile long double* value) {
  return listAddBackQueueLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, long double value) {
  return listAddBackQueuePLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile long double* value) {
  return listAddBackQueuePLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, List value) {
  return listAddBackQueueList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile List* value) {
  return listAddBackQueueListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, List value) {
  return listAddBackQueuePList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile List* value) {
  return listAddBackQueuePListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, Queue value) {
  return listAddBackQueueQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile Queue* value) {
  return listAddBackQueueQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, Queue value) {
  return listAddBackQueuePQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile Queue* value) {
  return listAddBackQueuePQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, Stack value) {
  return listAddBackQueueStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile Stack* value) {
  return listAddBackQueueStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, Stack value) {
  return listAddBackQueuePStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile Stack* value) {
  return listAddBackQueuePStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, RedBlackTree value) {
  return listAddBackQueueRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile RedBlackTree* value) {
  return listAddBackQueueRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, RedBlackTree value) {
  return listAddBackQueuePRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile RedBlackTree* value) {
  return listAddBackQueuePRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, HashTable value) {
  return listAddBackQueueHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile HashTable* value) {
  return listAddBackQueueHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, HashTable value) {
  return listAddBackQueuePHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile HashTable* value) {
  return listAddBackQueuePHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, Vector value) {
  return listAddBackQueueVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile Vector* value) {
  return listAddBackQueueVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, Vector value) {
  return listAddBackQueuePVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile Vector* value) {
  return listAddBackQueuePVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile char* value) {
  return listAddBackQueueString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile char** value) {
  return listAddBackQueueStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile char* value) {
  return listAddBackQueuePString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile char** value) {
  return listAddBackQueuePStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, Bytes value) {
  return listAddBackQueueBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile Bytes* value) {
  return listAddBackQueueBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, Bytes value) {
  return listAddBackQueuePBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile Bytes* value) {
  return listAddBackQueuePBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, void* value) {
  return listAddBackQueuePointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, const volatile void** value) {
  return listAddBackQueuePointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, void* value) {
  return listAddBackQueuePPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, const volatile void** value) {
  return listAddBackQueuePPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, i8 value) {
  return listAddBackQueueI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, i8 value) {
  return listAddBackQueuePI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Queue key, u8 value) {
  return listAddBackQueueU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Queue* key, u8 value) {
  return listAddBackQueuePU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, bool value) {
  return listAddBackStackBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile bool* value) {
  return listAddBackStackBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, bool value) {
  return listAddBackStackPBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile bool* value) {
  return listAddBackStackPBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, i16 value) {
  return listAddBackStackI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile i16* value) {
  return listAddBackStackI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, i16 value) {
  return listAddBackStackPI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile i16* value) {
  return listAddBackStackPI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, u16 value) {
  return listAddBackStackU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile u16* value) {
  return listAddBackStackU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, u16 value) {
  return listAddBackStackPU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile u16* value) {
  return listAddBackStackPU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, i32 value) {
  return listAddBackStackI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile i32* value) {
  return listAddBackStackI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, i32 value) {
  return listAddBackStackPI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile i32* value) {
  return listAddBackStackPI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, u32 value) {
  return listAddBackStackU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile u32* value) {
  return listAddBackStackU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, u32 value) {
  return listAddBackStackPU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile u32* value) {
  return listAddBackStackPU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, i64 value) {
  return listAddBackStackI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile i64* value) {
  return listAddBackStackI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, i64 value) {
  return listAddBackStackPI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile i64* value) {
  return listAddBackStackPI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, u64 value) {
  return listAddBackStackU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile u64* value) {
  return listAddBackStackU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, u64 value) {
  return listAddBackStackPU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile u64* value) {
  return listAddBackStackPU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, float value) {
  return listAddBackStackFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile float* value) {
  return listAddBackStackFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, float value) {
  return listAddBackStackPFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile float* value) {
  return listAddBackStackPFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, double value) {
  return listAddBackStackDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile double* value) {
  return listAddBackStackDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, double value) {
  return listAddBackStackPDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile double* value) {
  return listAddBackStackPDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, long double value) {
  return listAddBackStackLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile long double* value) {
  return listAddBackStackLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, long double value) {
  return listAddBackStackPLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile long double* value) {
  return listAddBackStackPLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, List value) {
  return listAddBackStackList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile List* value) {
  return listAddBackStackListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, List value) {
  return listAddBackStackPList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile List* value) {
  return listAddBackStackPListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, Queue value) {
  return listAddBackStackQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile Queue* value) {
  return listAddBackStackQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, Queue value) {
  return listAddBackStackPQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile Queue* value) {
  return listAddBackStackPQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, Stack value) {
  return listAddBackStackStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile Stack* value) {
  return listAddBackStackStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, Stack value) {
  return listAddBackStackPStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile Stack* value) {
  return listAddBackStackPStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, RedBlackTree value) {
  return listAddBackStackRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile RedBlackTree* value) {
  return listAddBackStackRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, RedBlackTree value) {
  return listAddBackStackPRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile RedBlackTree* value) {
  return listAddBackStackPRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, HashTable value) {
  return listAddBackStackHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile HashTable* value) {
  return listAddBackStackHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, HashTable value) {
  return listAddBackStackPHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile HashTable* value) {
  return listAddBackStackPHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, Vector value) {
  return listAddBackStackVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile Vector* value) {
  return listAddBackStackVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, Vector value) {
  return listAddBackStackPVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile Vector* value) {
  return listAddBackStackPVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile char* value) {
  return listAddBackStackString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile char** value) {
  return listAddBackStackStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile char* value) {
  return listAddBackStackPString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile char** value) {
  return listAddBackStackPStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, Bytes value) {
  return listAddBackStackBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile Bytes* value) {
  return listAddBackStackBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, Bytes value) {
  return listAddBackStackPBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile Bytes* value) {
  return listAddBackStackPBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, void* value) {
  return listAddBackStackPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, const volatile void** value) {
  return listAddBackStackPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, void* value) {
  return listAddBackStackPPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, const volatile void** value) {
  return listAddBackStackPPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, i8 value) {
  return listAddBackStackI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, i8 value) {
  return listAddBackStackPI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Stack key, u8 value) {
  return listAddBackStackU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Stack* key, u8 value) {
  return listAddBackStackPU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, bool value) {
  return listAddBackRedBlackTreeBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile bool* value) {
  return listAddBackRedBlackTreeBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, bool value) {
  return listAddBackRedBlackTreePBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile bool* value) {
  return listAddBackRedBlackTreePBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, i16 value) {
  return listAddBackRedBlackTreeI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile i16* value) {
  return listAddBackRedBlackTreeI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, i16 value) {
  return listAddBackRedBlackTreePI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile i16* value) {
  return listAddBackRedBlackTreePI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, u16 value) {
  return listAddBackRedBlackTreeU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile u16* value) {
  return listAddBackRedBlackTreeU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, u16 value) {
  return listAddBackRedBlackTreePU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile u16* value) {
  return listAddBackRedBlackTreePU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, i32 value) {
  return listAddBackRedBlackTreeI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile i32* value) {
  return listAddBackRedBlackTreeI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, i32 value) {
  return listAddBackRedBlackTreePI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile i32* value) {
  return listAddBackRedBlackTreePI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, u32 value) {
  return listAddBackRedBlackTreeU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile u32* value) {
  return listAddBackRedBlackTreeU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, u32 value) {
  return listAddBackRedBlackTreePU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile u32* value) {
  return listAddBackRedBlackTreePU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, i64 value) {
  return listAddBackRedBlackTreeI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile i64* value) {
  return listAddBackRedBlackTreeI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, i64 value) {
  return listAddBackRedBlackTreePI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile i64* value) {
  return listAddBackRedBlackTreePI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, u64 value) {
  return listAddBackRedBlackTreeU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile u64* value) {
  return listAddBackRedBlackTreeU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, u64 value) {
  return listAddBackRedBlackTreePU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile u64* value) {
  return listAddBackRedBlackTreePU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, float value) {
  return listAddBackRedBlackTreeFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile float* value) {
  return listAddBackRedBlackTreeFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, float value) {
  return listAddBackRedBlackTreePFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile float* value) {
  return listAddBackRedBlackTreePFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, double value) {
  return listAddBackRedBlackTreeDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile double* value) {
  return listAddBackRedBlackTreeDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, double value) {
  return listAddBackRedBlackTreePDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile double* value) {
  return listAddBackRedBlackTreePDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, long double value) {
  return listAddBackRedBlackTreeLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile long double* value) {
  return listAddBackRedBlackTreeLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, long double value) {
  return listAddBackRedBlackTreePLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile long double* value) {
  return listAddBackRedBlackTreePLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, List value) {
  return listAddBackRedBlackTreeList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile List* value) {
  return listAddBackRedBlackTreeListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, List value) {
  return listAddBackRedBlackTreePList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile List* value) {
  return listAddBackRedBlackTreePListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, Queue value) {
  return listAddBackRedBlackTreeQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile Queue* value) {
  return listAddBackRedBlackTreeQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, Queue value) {
  return listAddBackRedBlackTreePQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile Queue* value) {
  return listAddBackRedBlackTreePQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, Stack value) {
  return listAddBackRedBlackTreeStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile Stack* value) {
  return listAddBackRedBlackTreeStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, Stack value) {
  return listAddBackRedBlackTreePStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile Stack* value) {
  return listAddBackRedBlackTreePStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, RedBlackTree value) {
  return listAddBackRedBlackTreeRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile RedBlackTree* value) {
  return listAddBackRedBlackTreeRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, RedBlackTree value) {
  return listAddBackRedBlackTreePRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile RedBlackTree* value) {
  return listAddBackRedBlackTreePRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, HashTable value) {
  return listAddBackRedBlackTreeHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile HashTable* value) {
  return listAddBackRedBlackTreeHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, HashTable value) {
  return listAddBackRedBlackTreePHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile HashTable* value) {
  return listAddBackRedBlackTreePHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, Vector value) {
  return listAddBackRedBlackTreeVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile Vector* value) {
  return listAddBackRedBlackTreeVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, Vector value) {
  return listAddBackRedBlackTreePVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile Vector* value) {
  return listAddBackRedBlackTreePVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile char* value) {
  return listAddBackRedBlackTreeString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile char** value) {
  return listAddBackRedBlackTreeStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile char* value) {
  return listAddBackRedBlackTreePString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile char** value) {
  return listAddBackRedBlackTreePStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, Bytes value) {
  return listAddBackRedBlackTreeBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile Bytes* value) {
  return listAddBackRedBlackTreeBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, Bytes value) {
  return listAddBackRedBlackTreePBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile Bytes* value) {
  return listAddBackRedBlackTreePBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, void* value) {
  return listAddBackRedBlackTreePointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, const volatile void** value) {
  return listAddBackRedBlackTreePointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, void* value) {
  return listAddBackRedBlackTreePPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, const volatile void** value) {
  return listAddBackRedBlackTreePPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, i8 value) {
  return listAddBackRedBlackTreeI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, i8 value) {
  return listAddBackRedBlackTreePI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, RedBlackTree key, u8 value) {
  return listAddBackRedBlackTreeU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile RedBlackTree* key, u8 value) {
  return listAddBackRedBlackTreePU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, bool value) {
  return listAddBackHashTableBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile bool* value) {
  return listAddBackHashTableBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, bool value) {
  return listAddBackHashTablePBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile bool* value) {
  return listAddBackHashTablePBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, i16 value) {
  return listAddBackHashTableI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile i16* value) {
  return listAddBackHashTableI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, i16 value) {
  return listAddBackHashTablePI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile i16* value) {
  return listAddBackHashTablePI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, u16 value) {
  return listAddBackHashTableU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile u16* value) {
  return listAddBackHashTableU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, u16 value) {
  return listAddBackHashTablePU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile u16* value) {
  return listAddBackHashTablePU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, i32 value) {
  return listAddBackHashTableI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile i32* value) {
  return listAddBackHashTableI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, i32 value) {
  return listAddBackHashTablePI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile i32* value) {
  return listAddBackHashTablePI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, u32 value) {
  return listAddBackHashTableU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile u32* value) {
  return listAddBackHashTableU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, u32 value) {
  return listAddBackHashTablePU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile u32* value) {
  return listAddBackHashTablePU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, i64 value) {
  return listAddBackHashTableI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile i64* value) {
  return listAddBackHashTableI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, i64 value) {
  return listAddBackHashTablePI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile i64* value) {
  return listAddBackHashTablePI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, u64 value) {
  return listAddBackHashTableU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile u64* value) {
  return listAddBackHashTableU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, u64 value) {
  return listAddBackHashTablePU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile u64* value) {
  return listAddBackHashTablePU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, float value) {
  return listAddBackHashTableFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile float* value) {
  return listAddBackHashTableFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, float value) {
  return listAddBackHashTablePFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile float* value) {
  return listAddBackHashTablePFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, double value) {
  return listAddBackHashTableDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile double* value) {
  return listAddBackHashTableDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, double value) {
  return listAddBackHashTablePDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile double* value) {
  return listAddBackHashTablePDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, long double value) {
  return listAddBackHashTableLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile long double* value) {
  return listAddBackHashTableLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, long double value) {
  return listAddBackHashTablePLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile long double* value) {
  return listAddBackHashTablePLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, List value) {
  return listAddBackHashTableList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile List* value) {
  return listAddBackHashTableListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, List value) {
  return listAddBackHashTablePList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile List* value) {
  return listAddBackHashTablePListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, Queue value) {
  return listAddBackHashTableQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile Queue* value) {
  return listAddBackHashTableQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, Queue value) {
  return listAddBackHashTablePQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile Queue* value) {
  return listAddBackHashTablePQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, Stack value) {
  return listAddBackHashTableStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile Stack* value) {
  return listAddBackHashTableStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, Stack value) {
  return listAddBackHashTablePStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile Stack* value) {
  return listAddBackHashTablePStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, RedBlackTree value) {
  return listAddBackHashTableRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile RedBlackTree* value) {
  return listAddBackHashTableRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, RedBlackTree value) {
  return listAddBackHashTablePRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile RedBlackTree* value) {
  return listAddBackHashTablePRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, HashTable value) {
  return listAddBackHashTableHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile HashTable* value) {
  return listAddBackHashTableHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, HashTable value) {
  return listAddBackHashTablePHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile HashTable* value) {
  return listAddBackHashTablePHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, Vector value) {
  return listAddBackHashTableVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile Vector* value) {
  return listAddBackHashTableVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, Vector value) {
  return listAddBackHashTablePVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile Vector* value) {
  return listAddBackHashTablePVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile char* value) {
  return listAddBackHashTableString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile char** value) {
  return listAddBackHashTableStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile char* value) {
  return listAddBackHashTablePString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile char** value) {
  return listAddBackHashTablePStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, Bytes value) {
  return listAddBackHashTableBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile Bytes* value) {
  return listAddBackHashTableBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, Bytes value) {
  return listAddBackHashTablePBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile Bytes* value) {
  return listAddBackHashTablePBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, void* value) {
  return listAddBackHashTablePointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, const volatile void** value) {
  return listAddBackHashTablePointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, void* value) {
  return listAddBackHashTablePPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, const volatile void** value) {
  return listAddBackHashTablePPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, i8 value) {
  return listAddBackHashTableI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, i8 value) {
  return listAddBackHashTablePI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, HashTable key, u8 value) {
  return listAddBackHashTableU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile HashTable* key, u8 value) {
  return listAddBackHashTablePU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, bool value) {
  return listAddBackVectorBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile bool* value) {
  return listAddBackVectorBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, bool value) {
  return listAddBackVectorPBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile bool* value) {
  return listAddBackVectorPBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, i16 value) {
  return listAddBackVectorI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile i16* value) {
  return listAddBackVectorI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, i16 value) {
  return listAddBackVectorPI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile i16* value) {
  return listAddBackVectorPI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, u16 value) {
  return listAddBackVectorU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile u16* value) {
  return listAddBackVectorU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, u16 value) {
  return listAddBackVectorPU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile u16* value) {
  return listAddBackVectorPU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, i32 value) {
  return listAddBackVectorI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile i32* value) {
  return listAddBackVectorI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, i32 value) {
  return listAddBackVectorPI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile i32* value) {
  return listAddBackVectorPI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, u32 value) {
  return listAddBackVectorU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile u32* value) {
  return listAddBackVectorU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, u32 value) {
  return listAddBackVectorPU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile u32* value) {
  return listAddBackVectorPU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, i64 value) {
  return listAddBackVectorI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile i64* value) {
  return listAddBackVectorI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, i64 value) {
  return listAddBackVectorPI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile i64* value) {
  return listAddBackVectorPI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, u64 value) {
  return listAddBackVectorU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile u64* value) {
  return listAddBackVectorU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, u64 value) {
  return listAddBackVectorPU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile u64* value) {
  return listAddBackVectorPU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, float value) {
  return listAddBackVectorFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile float* value) {
  return listAddBackVectorFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, float value) {
  return listAddBackVectorPFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile float* value) {
  return listAddBackVectorPFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, double value) {
  return listAddBackVectorDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile double* value) {
  return listAddBackVectorDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, double value) {
  return listAddBackVectorPDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile double* value) {
  return listAddBackVectorPDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, long double value) {
  return listAddBackVectorLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile long double* value) {
  return listAddBackVectorLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, long double value) {
  return listAddBackVectorPLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile long double* value) {
  return listAddBackVectorPLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, List value) {
  return listAddBackVectorList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile List* value) {
  return listAddBackVectorListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, List value) {
  return listAddBackVectorPList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile List* value) {
  return listAddBackVectorPListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, Queue value) {
  return listAddBackVectorQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile Queue* value) {
  return listAddBackVectorQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, Queue value) {
  return listAddBackVectorPQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile Queue* value) {
  return listAddBackVectorPQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, Stack value) {
  return listAddBackVectorStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile Stack* value) {
  return listAddBackVectorStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, Stack value) {
  return listAddBackVectorPStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile Stack* value) {
  return listAddBackVectorPStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, RedBlackTree value) {
  return listAddBackVectorRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile RedBlackTree* value) {
  return listAddBackVectorRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, RedBlackTree value) {
  return listAddBackVectorPRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile RedBlackTree* value) {
  return listAddBackVectorPRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, HashTable value) {
  return listAddBackVectorHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile HashTable* value) {
  return listAddBackVectorHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, HashTable value) {
  return listAddBackVectorPHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile HashTable* value) {
  return listAddBackVectorPHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, Vector value) {
  return listAddBackVectorVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile Vector* value) {
  return listAddBackVectorVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, Vector value) {
  return listAddBackVectorPVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile Vector* value) {
  return listAddBackVectorPVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile char* value) {
  return listAddBackVectorString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile char** value) {
  return listAddBackVectorStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile char* value) {
  return listAddBackVectorPString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile char** value) {
  return listAddBackVectorPStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, Bytes value) {
  return listAddBackVectorBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile Bytes* value) {
  return listAddBackVectorBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, Bytes value) {
  return listAddBackVectorPBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile Bytes* value) {
  return listAddBackVectorPBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, void* value) {
  return listAddBackVectorPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, const volatile void** value) {
  return listAddBackVectorPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, void* value) {
  return listAddBackVectorPPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, const volatile void** value) {
  return listAddBackVectorPPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, i8 value) {
  return listAddBackVectorI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, i8 value) {
  return listAddBackVectorPI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Vector key, u8 value) {
  return listAddBackVectorU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Vector* key, u8 value) {
  return listAddBackVectorPU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, bool value) {
  return listAddBackStringBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile bool* value) {
  return listAddBackStringBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, bool value) {
  return listAddBackStringPBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile bool* value) {
  return listAddBackStringPBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, i16 value) {
  return listAddBackStringI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile i16* value) {
  return listAddBackStringI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, i16 value) {
  return listAddBackStringPI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile i16* value) {
  return listAddBackStringPI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, u16 value) {
  return listAddBackStringU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile u16* value) {
  return listAddBackStringU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, u16 value) {
  return listAddBackStringPU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile u16* value) {
  return listAddBackStringPU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, i32 value) {
  return listAddBackStringI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile i32* value) {
  return listAddBackStringI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, i32 value) {
  return listAddBackStringPI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile i32* value) {
  return listAddBackStringPI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, u32 value) {
  return listAddBackStringU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile u32* value) {
  return listAddBackStringU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, u32 value) {
  return listAddBackStringPU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile u32* value) {
  return listAddBackStringPU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, i64 value) {
  return listAddBackStringI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile i64* value) {
  return listAddBackStringI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, i64 value) {
  return listAddBackStringPI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile i64* value) {
  return listAddBackStringPI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, u64 value) {
  return listAddBackStringU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile u64* value) {
  return listAddBackStringU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, u64 value) {
  return listAddBackStringPU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile u64* value) {
  return listAddBackStringPU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, float value) {
  return listAddBackStringFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile float* value) {
  return listAddBackStringFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, float value) {
  return listAddBackStringPFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile float* value) {
  return listAddBackStringPFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, double value) {
  return listAddBackStringDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile double* value) {
  return listAddBackStringDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, double value) {
  return listAddBackStringPDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile double* value) {
  return listAddBackStringPDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, long double value) {
  return listAddBackStringLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile long double* value) {
  return listAddBackStringLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, long double value) {
  return listAddBackStringPLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile long double* value) {
  return listAddBackStringPLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, List value) {
  return listAddBackStringList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile List* value) {
  return listAddBackStringListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, List value) {
  return listAddBackStringPList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile List* value) {
  return listAddBackStringPListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, Queue value) {
  return listAddBackStringQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile Queue* value) {
  return listAddBackStringQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, Queue value) {
  return listAddBackStringPQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile Queue* value) {
  return listAddBackStringPQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, Stack value) {
  return listAddBackStringStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile Stack* value) {
  return listAddBackStringStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, Stack value) {
  return listAddBackStringPStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile Stack* value) {
  return listAddBackStringPStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, RedBlackTree value) {
  return listAddBackStringRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile RedBlackTree* value) {
  return listAddBackStringRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, RedBlackTree value) {
  return listAddBackStringPRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile RedBlackTree* value) {
  return listAddBackStringPRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, HashTable value) {
  return listAddBackStringHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile HashTable* value) {
  return listAddBackStringHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, HashTable value) {
  return listAddBackStringPHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile HashTable* value) {
  return listAddBackStringPHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, Vector value) {
  return listAddBackStringVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile Vector* value) {
  return listAddBackStringVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, Vector value) {
  return listAddBackStringPVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile Vector* value) {
  return listAddBackStringPVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile char* value) {
  return listAddBackStringString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile char** value) {
  return listAddBackStringStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile char* value) {
  return listAddBackStringPString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile char** value) {
  return listAddBackStringPStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, Bytes value) {
  return listAddBackStringBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile Bytes* value) {
  return listAddBackStringBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, Bytes value) {
  return listAddBackStringPBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile Bytes* value) {
  return listAddBackStringPBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, void* value) {
  return listAddBackStringPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, const volatile void** value) {
  return listAddBackStringPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, void* value) {
  return listAddBackStringPPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, const volatile void** value) {
  return listAddBackStringPPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, i8 value) {
  return listAddBackStringI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, i8 value) {
  return listAddBackStringPI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char* key, u8 value) {
  return listAddBackStringU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile char** key, u8 value) {
  return listAddBackStringPU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, bool value) {
  return listAddBackBytesBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile bool* value) {
  return listAddBackBytesBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, bool value) {
  return listAddBackBytesPBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile bool* value) {
  return listAddBackBytesPBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, i16 value) {
  return listAddBackBytesI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile i16* value) {
  return listAddBackBytesI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, i16 value) {
  return listAddBackBytesPI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile i16* value) {
  return listAddBackBytesPI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, u16 value) {
  return listAddBackBytesU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile u16* value) {
  return listAddBackBytesU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, u16 value) {
  return listAddBackBytesPU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile u16* value) {
  return listAddBackBytesPU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, i32 value) {
  return listAddBackBytesI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile i32* value) {
  return listAddBackBytesI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, i32 value) {
  return listAddBackBytesPI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile i32* value) {
  return listAddBackBytesPI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, u32 value) {
  return listAddBackBytesU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile u32* value) {
  return listAddBackBytesU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, u32 value) {
  return listAddBackBytesPU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile u32* value) {
  return listAddBackBytesPU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, i64 value) {
  return listAddBackBytesI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile i64* value) {
  return listAddBackBytesI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, i64 value) {
  return listAddBackBytesPI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile i64* value) {
  return listAddBackBytesPI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, u64 value) {
  return listAddBackBytesU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile u64* value) {
  return listAddBackBytesU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, u64 value) {
  return listAddBackBytesPU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile u64* value) {
  return listAddBackBytesPU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, float value) {
  return listAddBackBytesFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile float* value) {
  return listAddBackBytesFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, float value) {
  return listAddBackBytesPFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile float* value) {
  return listAddBackBytesPFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, double value) {
  return listAddBackBytesDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile double* value) {
  return listAddBackBytesDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, double value) {
  return listAddBackBytesPDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile double* value) {
  return listAddBackBytesPDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, long double value) {
  return listAddBackBytesLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile long double* value) {
  return listAddBackBytesLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, long double value) {
  return listAddBackBytesPLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile long double* value) {
  return listAddBackBytesPLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, List value) {
  return listAddBackBytesList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile List* value) {
  return listAddBackBytesListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, List value) {
  return listAddBackBytesPList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile List* value) {
  return listAddBackBytesPListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, Queue value) {
  return listAddBackBytesQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile Queue* value) {
  return listAddBackBytesQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, Queue value) {
  return listAddBackBytesPQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile Queue* value) {
  return listAddBackBytesPQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, Stack value) {
  return listAddBackBytesStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile Stack* value) {
  return listAddBackBytesStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, Stack value) {
  return listAddBackBytesPStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile Stack* value) {
  return listAddBackBytesPStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, RedBlackTree value) {
  return listAddBackBytesRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile RedBlackTree* value) {
  return listAddBackBytesRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, RedBlackTree value) {
  return listAddBackBytesPRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile RedBlackTree* value) {
  return listAddBackBytesPRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, HashTable value) {
  return listAddBackBytesHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile HashTable* value) {
  return listAddBackBytesHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, HashTable value) {
  return listAddBackBytesPHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile HashTable* value) {
  return listAddBackBytesPHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, Vector value) {
  return listAddBackBytesVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile Vector* value) {
  return listAddBackBytesVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, Vector value) {
  return listAddBackBytesPVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile Vector* value) {
  return listAddBackBytesPVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile char* value) {
  return listAddBackBytesString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile char** value) {
  return listAddBackBytesStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile char* value) {
  return listAddBackBytesPString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile char** value) {
  return listAddBackBytesPStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, Bytes value) {
  return listAddBackBytesBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile Bytes* value) {
  return listAddBackBytesBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, Bytes value) {
  return listAddBackBytesPBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile Bytes* value) {
  return listAddBackBytesPBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, void* value) {
  return listAddBackBytesPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, const volatile void** value) {
  return listAddBackBytesPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, void* value) {
  return listAddBackBytesPPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, const volatile void** value) {
  return listAddBackBytesPPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, i8 value) {
  return listAddBackBytesI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, i8 value) {
  return listAddBackBytesPI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, Bytes key, u8 value) {
  return listAddBackBytesU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile Bytes* key, u8 value) {
  return listAddBackBytesPU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, bool value) {
  return listAddBackPointerBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile bool* value) {
  return listAddBackPointerBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, bool value) {
  return listAddBackPointerPBool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile bool* value) {
  return listAddBackPointerPBoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, i16 value) {
  return listAddBackPointerI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile i16* value) {
  return listAddBackPointerI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, i16 value) {
  return listAddBackPointerPI16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile i16* value) {
  return listAddBackPointerPI16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, u16 value) {
  return listAddBackPointerU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile u16* value) {
  return listAddBackPointerU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, u16 value) {
  return listAddBackPointerPU16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile u16* value) {
  return listAddBackPointerPU16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, i32 value) {
  return listAddBackPointerI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile i32* value) {
  return listAddBackPointerI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, i32 value) {
  return listAddBackPointerPI32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile i32* value) {
  return listAddBackPointerPI32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, u32 value) {
  return listAddBackPointerU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile u32* value) {
  return listAddBackPointerU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, u32 value) {
  return listAddBackPointerPU32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile u32* value) {
  return listAddBackPointerPU32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, i64 value) {
  return listAddBackPointerI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile i64* value) {
  return listAddBackPointerI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, i64 value) {
  return listAddBackPointerPI64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile i64* value) {
  return listAddBackPointerPI64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, u64 value) {
  return listAddBackPointerU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile u64* value) {
  return listAddBackPointerU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, u64 value) {
  return listAddBackPointerPU64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile u64* value) {
  return listAddBackPointerPU64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, float value) {
  return listAddBackPointerFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile float* value) {
  return listAddBackPointerFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, float value) {
  return listAddBackPointerPFloat(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile float* value) {
  return listAddBackPointerPFloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, double value) {
  return listAddBackPointerDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile double* value) {
  return listAddBackPointerDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, double value) {
  return listAddBackPointerPDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile double* value) {
  return listAddBackPointerPDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, long double value) {
  return listAddBackPointerLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile long double* value) {
  return listAddBackPointerLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, long double value) {
  return listAddBackPointerPLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile long double* value) {
  return listAddBackPointerPLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, List value) {
  return listAddBackPointerList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile List* value) {
  return listAddBackPointerListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, List value) {
  return listAddBackPointerPList(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile List* value) {
  return listAddBackPointerPListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, Queue value) {
  return listAddBackPointerQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile Queue* value) {
  return listAddBackPointerQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, Queue value) {
  return listAddBackPointerPQueue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile Queue* value) {
  return listAddBackPointerPQueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, Stack value) {
  return listAddBackPointerStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile Stack* value) {
  return listAddBackPointerStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, Stack value) {
  return listAddBackPointerPStack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile Stack* value) {
  return listAddBackPointerPStackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, RedBlackTree value) {
  return listAddBackPointerRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile RedBlackTree* value) {
  return listAddBackPointerRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, RedBlackTree value) {
  return listAddBackPointerPRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile RedBlackTree* value) {
  return listAddBackPointerPRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, HashTable value) {
  return listAddBackPointerHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile HashTable* value) {
  return listAddBackPointerHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, HashTable value) {
  return listAddBackPointerPHashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile HashTable* value) {
  return listAddBackPointerPHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, Vector value) {
  return listAddBackPointerVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile Vector* value) {
  return listAddBackPointerVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, Vector value) {
  return listAddBackPointerPVector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile Vector* value) {
  return listAddBackPointerPVectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile char* value) {
  return listAddBackPointerString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile char** value) {
  return listAddBackPointerStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile char* value) {
  return listAddBackPointerPString(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile char** value) {
  return listAddBackPointerPStringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, Bytes value) {
  return listAddBackPointerBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile Bytes* value) {
  return listAddBackPointerBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, Bytes value) {
  return listAddBackPointerPBytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile Bytes* value) {
  return listAddBackPointerPBytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, void* value) {
  return listAddBackPointerPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, const volatile void** value) {
  return listAddBackPointerPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, void* value) {
  return listAddBackPointerPPointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, const volatile void** value) {
  return listAddBackPointerPPointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, i8 value) {
  return listAddBackPointerI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, i8 value) {
  return listAddBackPointerPI8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, void* key, u8 value) {
  return listAddBackPointerU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, const volatile void** key, u8 value) {
  return listAddBackPointerPU8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, bool value) {
  return listAddBackI8Bool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile bool* value) {
  return listAddBackI8BoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, i16 value) {
  return listAddBackI8I16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile i16* value) {
  return listAddBackI8I16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, u16 value) {
  return listAddBackI8U16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile u16* value) {
  return listAddBackI8U16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, i32 value) {
  return listAddBackI8I32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile i32* value) {
  return listAddBackI8I32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, u32 value) {
  return listAddBackI8U32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile u32* value) {
  return listAddBackI8U32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, i64 value) {
  return listAddBackI8I64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile i64* value) {
  return listAddBackI8I64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, u64 value) {
  return listAddBackI8U64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile u64* value) {
  return listAddBackI8U64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, float value) {
  return listAddBackI8Float(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile float* value) {
  return listAddBackI8FloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, double value) {
  return listAddBackI8Double(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile double* value) {
  return listAddBackI8DoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, long double value) {
  return listAddBackI8LongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile long double* value) {
  return listAddBackI8LongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, List value) {
  return listAddBackI8List(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile List* value) {
  return listAddBackI8ListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, Queue value) {
  return listAddBackI8Queue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile Queue* value) {
  return listAddBackI8QueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, Stack value) {
  return listAddBackI8Stack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile Stack* value) {
  return listAddBackI8StackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, RedBlackTree value) {
  return listAddBackI8RedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile RedBlackTree* value) {
  return listAddBackI8RedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, HashTable value) {
  return listAddBackI8HashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile HashTable* value) {
  return listAddBackI8HashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, Vector value) {
  return listAddBackI8Vector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile Vector* value) {
  return listAddBackI8VectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile char* value) {
  return listAddBackI8String(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile char** value) {
  return listAddBackI8StringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, Bytes value) {
  return listAddBackI8Bytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile Bytes* value) {
  return listAddBackI8BytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, void* value) {
  return listAddBackI8Pointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, const volatile void** value) {
  return listAddBackI8PointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, i8 value) {
  return listAddBackI8I8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, i8 key, u8 value) {
  return listAddBackI8U8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, bool value) {
  return listAddBackU8Bool(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile bool* value) {
  return listAddBackU8BoolP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, i16 value) {
  return listAddBackU8I16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile i16* value) {
  return listAddBackU8I16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, u16 value) {
  return listAddBackU8U16(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile u16* value) {
  return listAddBackU8U16P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, i32 value) {
  return listAddBackU8I32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile i32* value) {
  return listAddBackU8I32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, u32 value) {
  return listAddBackU8U32(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile u32* value) {
  return listAddBackU8U32P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, i64 value) {
  return listAddBackU8I64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile i64* value) {
  return listAddBackU8I64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, u64 value) {
  return listAddBackU8U64(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile u64* value) {
  return listAddBackU8U64P(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, float value) {
  return listAddBackU8Float(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile float* value) {
  return listAddBackU8FloatP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, double value) {
  return listAddBackU8Double(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile double* value) {
  return listAddBackU8DoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, long double value) {
  return listAddBackU8LongDouble(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile long double* value) {
  return listAddBackU8LongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, List value) {
  return listAddBackU8List(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile List* value) {
  return listAddBackU8ListP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, Queue value) {
  return listAddBackU8Queue(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile Queue* value) {
  return listAddBackU8QueueP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, Stack value) {
  return listAddBackU8Stack(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile Stack* value) {
  return listAddBackU8StackP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, RedBlackTree value) {
  return listAddBackU8RedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile RedBlackTree* value) {
  return listAddBackU8RedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, HashTable value) {
  return listAddBackU8HashTable(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile HashTable* value) {
  return listAddBackU8HashTableP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, Vector value) {
  return listAddBackU8Vector(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile Vector* value) {
  return listAddBackU8VectorP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile char* value) {
  return listAddBackU8String(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile char** value) {
  return listAddBackU8StringP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, Bytes value) {
  return listAddBackU8Bytes(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile Bytes* value) {
  return listAddBackU8BytesP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, void* value) {
  return listAddBackU8Pointer(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, const volatile void** value) {
  return listAddBackU8PointerP(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, i8 value) {
  return listAddBackU8I8(dataStructure, key, value);
}
static inline ListNode* listAddBack(List *dataStructure, u8 key, u8 value) {
  return listAddBackU8U8(dataStructure, key, value);
}

#endif // __cplusplus

#endif // TYPE_SAFE_LIST_ADD_BACK_H

