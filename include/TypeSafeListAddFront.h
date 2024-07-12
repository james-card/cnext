///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              04.21.2024
///
/// @file              TypeSafeListAddFront.h
///
/// @brief             This header contains type-safe versions of the
///                    listAddFront function.
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


#ifndef TYPE_SAFE_LIST_ADD_FRONT_H
#define TYPE_SAFE_LIST_ADD_FRONT_H

#include "DataTypes.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Type-safe inline functions.

static inline ListNode* listAddFrontBoolBool(List *dataStructure, bool key, bool value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddFrontBoolBoolP(List *dataStructure, bool key, const volatile bool* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontBoolPBool(List *dataStructure, const volatile bool* key, bool value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontBoolPBoolP(List *dataStructure, const volatile bool* key, const volatile bool* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontBoolI16(List *dataStructure, bool key, i16 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddFrontBoolI16P(List *dataStructure, bool key, const volatile i16* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontBoolPI16(List *dataStructure, const volatile bool* key, i16 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontBoolPI16P(List *dataStructure, const volatile bool* key, const volatile i16* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontBoolU16(List *dataStructure, bool key, u16 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddFrontBoolU16P(List *dataStructure, bool key, const volatile u16* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontBoolPU16(List *dataStructure, const volatile bool* key, u16 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontBoolPU16P(List *dataStructure, const volatile bool* key, const volatile u16* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontBoolI32(List *dataStructure, bool key, i32 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddFrontBoolI32P(List *dataStructure, bool key, const volatile i32* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontBoolPI32(List *dataStructure, const volatile bool* key, i32 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontBoolPI32P(List *dataStructure, const volatile bool* key, const volatile i32* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontBoolU32(List *dataStructure, bool key, u32 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddFrontBoolU32P(List *dataStructure, bool key, const volatile u32* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontBoolPU32(List *dataStructure, const volatile bool* key, u32 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontBoolPU32P(List *dataStructure, const volatile bool* key, const volatile u32* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontBoolI64(List *dataStructure, bool key, i64 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddFrontBoolI64P(List *dataStructure, bool key, const volatile i64* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontBoolPI64(List *dataStructure, const volatile bool* key, i64 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontBoolPI64P(List *dataStructure, const volatile bool* key, const volatile i64* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontBoolU64(List *dataStructure, bool key, u64 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddFrontBoolU64P(List *dataStructure, bool key, const volatile u64* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontBoolPU64(List *dataStructure, const volatile bool* key, u64 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontBoolPU64P(List *dataStructure, const volatile bool* key, const volatile u64* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontBoolFloat(List *dataStructure, bool key, float value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddFrontBoolFloatP(List *dataStructure, bool key, const volatile float* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontBoolPFloat(List *dataStructure, const volatile bool* key, float value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontBoolPFloatP(List *dataStructure, const volatile bool* key, const volatile float* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontBoolDouble(List *dataStructure, bool key, double value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddFrontBoolDoubleP(List *dataStructure, bool key, const volatile double* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontBoolPDouble(List *dataStructure, const volatile bool* key, double value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontBoolPDoubleP(List *dataStructure, const volatile bool* key, const volatile double* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontBoolLongDouble(List *dataStructure, bool key, long double value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontBoolLongDoubleP(List *dataStructure, bool key, const volatile long double* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontBoolPLongDouble(List *dataStructure, const volatile bool* key, long double value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontBoolPLongDoubleP(List *dataStructure, const volatile bool* key, const volatile long double* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontBoolList(List *dataStructure, bool key, List value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddFrontBoolListP(List *dataStructure, bool key, const volatile List* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontBoolPList(List *dataStructure, const volatile bool* key, List value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontBoolPListP(List *dataStructure, const volatile bool* key, const volatile List* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontBoolQueue(List *dataStructure, bool key, Queue value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddFrontBoolQueueP(List *dataStructure, bool key, const volatile Queue* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontBoolPQueue(List *dataStructure, const volatile bool* key, Queue value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontBoolPQueueP(List *dataStructure, const volatile bool* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontBoolStack(List *dataStructure, bool key, Stack value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddFrontBoolStackP(List *dataStructure, bool key, const volatile Stack* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontBoolPStack(List *dataStructure, const volatile bool* key, Stack value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontBoolPStackP(List *dataStructure, const volatile bool* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontBoolRedBlackTree(List *dataStructure, bool key, RedBlackTree value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontBoolRedBlackTreeP(List *dataStructure, bool key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontBoolPRedBlackTree(List *dataStructure, const volatile bool* key, RedBlackTree value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontBoolPRedBlackTreeP(List *dataStructure, const volatile bool* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontBoolHashTable(List *dataStructure, bool key, HashTable value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddFrontBoolHashTableP(List *dataStructure, bool key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontBoolPHashTable(List *dataStructure, const volatile bool* key, HashTable value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontBoolPHashTableP(List *dataStructure, const volatile bool* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontBoolVector(List *dataStructure, bool key, Vector value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddFrontBoolVectorP(List *dataStructure, bool key, const volatile Vector* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontBoolPVector(List *dataStructure, const volatile bool* key, Vector value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontBoolPVectorP(List *dataStructure, const volatile bool* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontBoolString(List *dataStructure, bool key, const volatile char* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddFrontBoolStringP(List *dataStructure, bool key, const volatile char** value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontBoolPString(List *dataStructure, const volatile bool* key, const volatile char* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontBoolPStringP(List *dataStructure, const volatile bool* key, const volatile char** value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontBoolBytes(List *dataStructure, bool key, Bytes value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddFrontBoolBytesP(List *dataStructure, bool key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontBoolPBytes(List *dataStructure, const volatile bool* key, Bytes value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontBoolPBytesP(List *dataStructure, const volatile bool* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontBoolPointer(List *dataStructure, bool key, void* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddFrontBoolPointerP(List *dataStructure, bool key, const volatile void** value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontBoolPPointer(List *dataStructure, const volatile bool* key, void* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontBoolPPointerP(List *dataStructure, const volatile bool* key, const volatile void** value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontBoolI8(List *dataStructure, bool key, i8 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddFrontBoolPI8(List *dataStructure, const volatile bool* key, i8 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontBoolU8(List *dataStructure, bool key, u8 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddFrontBoolPU8(List *dataStructure, const volatile bool* key, u8 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddFrontI16Bool(List *dataStructure, i16 key, bool value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddFrontI16BoolP(List *dataStructure, i16 key, const volatile bool* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontI16PBool(List *dataStructure, const volatile i16* key, bool value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontI16PBoolP(List *dataStructure, const volatile i16* key, const volatile bool* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontI16I16(List *dataStructure, i16 key, i16 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddFrontI16I16P(List *dataStructure, i16 key, const volatile i16* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontI16PI16(List *dataStructure, const volatile i16* key, i16 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontI16PI16P(List *dataStructure, const volatile i16* key, const volatile i16* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontI16U16(List *dataStructure, i16 key, u16 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddFrontI16U16P(List *dataStructure, i16 key, const volatile u16* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontI16PU16(List *dataStructure, const volatile i16* key, u16 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontI16PU16P(List *dataStructure, const volatile i16* key, const volatile u16* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontI16I32(List *dataStructure, i16 key, i32 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddFrontI16I32P(List *dataStructure, i16 key, const volatile i32* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontI16PI32(List *dataStructure, const volatile i16* key, i32 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontI16PI32P(List *dataStructure, const volatile i16* key, const volatile i32* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontI16U32(List *dataStructure, i16 key, u32 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddFrontI16U32P(List *dataStructure, i16 key, const volatile u32* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontI16PU32(List *dataStructure, const volatile i16* key, u32 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontI16PU32P(List *dataStructure, const volatile i16* key, const volatile u32* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontI16I64(List *dataStructure, i16 key, i64 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddFrontI16I64P(List *dataStructure, i16 key, const volatile i64* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontI16PI64(List *dataStructure, const volatile i16* key, i64 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontI16PI64P(List *dataStructure, const volatile i16* key, const volatile i64* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontI16U64(List *dataStructure, i16 key, u64 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddFrontI16U64P(List *dataStructure, i16 key, const volatile u64* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontI16PU64(List *dataStructure, const volatile i16* key, u64 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontI16PU64P(List *dataStructure, const volatile i16* key, const volatile u64* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontI16Float(List *dataStructure, i16 key, float value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddFrontI16FloatP(List *dataStructure, i16 key, const volatile float* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontI16PFloat(List *dataStructure, const volatile i16* key, float value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontI16PFloatP(List *dataStructure, const volatile i16* key, const volatile float* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontI16Double(List *dataStructure, i16 key, double value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddFrontI16DoubleP(List *dataStructure, i16 key, const volatile double* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontI16PDouble(List *dataStructure, const volatile i16* key, double value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontI16PDoubleP(List *dataStructure, const volatile i16* key, const volatile double* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontI16LongDouble(List *dataStructure, i16 key, long double value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontI16LongDoubleP(List *dataStructure, i16 key, const volatile long double* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontI16PLongDouble(List *dataStructure, const volatile i16* key, long double value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontI16PLongDoubleP(List *dataStructure, const volatile i16* key, const volatile long double* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontI16List(List *dataStructure, i16 key, List value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddFrontI16ListP(List *dataStructure, i16 key, const volatile List* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontI16PList(List *dataStructure, const volatile i16* key, List value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontI16PListP(List *dataStructure, const volatile i16* key, const volatile List* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontI16Queue(List *dataStructure, i16 key, Queue value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddFrontI16QueueP(List *dataStructure, i16 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontI16PQueue(List *dataStructure, const volatile i16* key, Queue value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontI16PQueueP(List *dataStructure, const volatile i16* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontI16Stack(List *dataStructure, i16 key, Stack value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddFrontI16StackP(List *dataStructure, i16 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontI16PStack(List *dataStructure, const volatile i16* key, Stack value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontI16PStackP(List *dataStructure, const volatile i16* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontI16RedBlackTree(List *dataStructure, i16 key, RedBlackTree value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontI16RedBlackTreeP(List *dataStructure, i16 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontI16PRedBlackTree(List *dataStructure, const volatile i16* key, RedBlackTree value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontI16PRedBlackTreeP(List *dataStructure, const volatile i16* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontI16HashTable(List *dataStructure, i16 key, HashTable value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddFrontI16HashTableP(List *dataStructure, i16 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontI16PHashTable(List *dataStructure, const volatile i16* key, HashTable value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontI16PHashTableP(List *dataStructure, const volatile i16* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontI16Vector(List *dataStructure, i16 key, Vector value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddFrontI16VectorP(List *dataStructure, i16 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontI16PVector(List *dataStructure, const volatile i16* key, Vector value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontI16PVectorP(List *dataStructure, const volatile i16* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontI16String(List *dataStructure, i16 key, const volatile char* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddFrontI16StringP(List *dataStructure, i16 key, const volatile char** value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontI16PString(List *dataStructure, const volatile i16* key, const volatile char* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontI16PStringP(List *dataStructure, const volatile i16* key, const volatile char** value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontI16Bytes(List *dataStructure, i16 key, Bytes value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddFrontI16BytesP(List *dataStructure, i16 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontI16PBytes(List *dataStructure, const volatile i16* key, Bytes value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontI16PBytesP(List *dataStructure, const volatile i16* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontI16Pointer(List *dataStructure, i16 key, void* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddFrontI16PointerP(List *dataStructure, i16 key, const volatile void** value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontI16PPointer(List *dataStructure, const volatile i16* key, void* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontI16PPointerP(List *dataStructure, const volatile i16* key, const volatile void** value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontI16I8(List *dataStructure, i16 key, i8 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddFrontI16PI8(List *dataStructure, const volatile i16* key, i8 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontI16U8(List *dataStructure, i16 key, u8 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddFrontI16PU8(List *dataStructure, const volatile i16* key, u8 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddFrontU16Bool(List *dataStructure, u16 key, bool value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddFrontU16BoolP(List *dataStructure, u16 key, const volatile bool* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontU16PBool(List *dataStructure, const volatile u16* key, bool value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontU16PBoolP(List *dataStructure, const volatile u16* key, const volatile bool* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontU16I16(List *dataStructure, u16 key, i16 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddFrontU16I16P(List *dataStructure, u16 key, const volatile i16* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontU16PI16(List *dataStructure, const volatile u16* key, i16 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontU16PI16P(List *dataStructure, const volatile u16* key, const volatile i16* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontU16U16(List *dataStructure, u16 key, u16 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddFrontU16U16P(List *dataStructure, u16 key, const volatile u16* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontU16PU16(List *dataStructure, const volatile u16* key, u16 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontU16PU16P(List *dataStructure, const volatile u16* key, const volatile u16* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontU16I32(List *dataStructure, u16 key, i32 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddFrontU16I32P(List *dataStructure, u16 key, const volatile i32* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontU16PI32(List *dataStructure, const volatile u16* key, i32 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontU16PI32P(List *dataStructure, const volatile u16* key, const volatile i32* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontU16U32(List *dataStructure, u16 key, u32 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddFrontU16U32P(List *dataStructure, u16 key, const volatile u32* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontU16PU32(List *dataStructure, const volatile u16* key, u32 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontU16PU32P(List *dataStructure, const volatile u16* key, const volatile u32* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontU16I64(List *dataStructure, u16 key, i64 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddFrontU16I64P(List *dataStructure, u16 key, const volatile i64* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontU16PI64(List *dataStructure, const volatile u16* key, i64 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontU16PI64P(List *dataStructure, const volatile u16* key, const volatile i64* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontU16U64(List *dataStructure, u16 key, u64 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddFrontU16U64P(List *dataStructure, u16 key, const volatile u64* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontU16PU64(List *dataStructure, const volatile u16* key, u64 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontU16PU64P(List *dataStructure, const volatile u16* key, const volatile u64* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontU16Float(List *dataStructure, u16 key, float value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddFrontU16FloatP(List *dataStructure, u16 key, const volatile float* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontU16PFloat(List *dataStructure, const volatile u16* key, float value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontU16PFloatP(List *dataStructure, const volatile u16* key, const volatile float* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontU16Double(List *dataStructure, u16 key, double value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddFrontU16DoubleP(List *dataStructure, u16 key, const volatile double* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontU16PDouble(List *dataStructure, const volatile u16* key, double value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontU16PDoubleP(List *dataStructure, const volatile u16* key, const volatile double* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontU16LongDouble(List *dataStructure, u16 key, long double value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontU16LongDoubleP(List *dataStructure, u16 key, const volatile long double* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontU16PLongDouble(List *dataStructure, const volatile u16* key, long double value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontU16PLongDoubleP(List *dataStructure, const volatile u16* key, const volatile long double* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontU16List(List *dataStructure, u16 key, List value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddFrontU16ListP(List *dataStructure, u16 key, const volatile List* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontU16PList(List *dataStructure, const volatile u16* key, List value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontU16PListP(List *dataStructure, const volatile u16* key, const volatile List* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontU16Queue(List *dataStructure, u16 key, Queue value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddFrontU16QueueP(List *dataStructure, u16 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontU16PQueue(List *dataStructure, const volatile u16* key, Queue value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontU16PQueueP(List *dataStructure, const volatile u16* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontU16Stack(List *dataStructure, u16 key, Stack value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddFrontU16StackP(List *dataStructure, u16 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontU16PStack(List *dataStructure, const volatile u16* key, Stack value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontU16PStackP(List *dataStructure, const volatile u16* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontU16RedBlackTree(List *dataStructure, u16 key, RedBlackTree value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontU16RedBlackTreeP(List *dataStructure, u16 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontU16PRedBlackTree(List *dataStructure, const volatile u16* key, RedBlackTree value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontU16PRedBlackTreeP(List *dataStructure, const volatile u16* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontU16HashTable(List *dataStructure, u16 key, HashTable value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddFrontU16HashTableP(List *dataStructure, u16 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontU16PHashTable(List *dataStructure, const volatile u16* key, HashTable value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontU16PHashTableP(List *dataStructure, const volatile u16* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontU16Vector(List *dataStructure, u16 key, Vector value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddFrontU16VectorP(List *dataStructure, u16 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontU16PVector(List *dataStructure, const volatile u16* key, Vector value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontU16PVectorP(List *dataStructure, const volatile u16* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontU16String(List *dataStructure, u16 key, const volatile char* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddFrontU16StringP(List *dataStructure, u16 key, const volatile char** value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontU16PString(List *dataStructure, const volatile u16* key, const volatile char* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontU16PStringP(List *dataStructure, const volatile u16* key, const volatile char** value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontU16Bytes(List *dataStructure, u16 key, Bytes value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddFrontU16BytesP(List *dataStructure, u16 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontU16PBytes(List *dataStructure, const volatile u16* key, Bytes value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontU16PBytesP(List *dataStructure, const volatile u16* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontU16Pointer(List *dataStructure, u16 key, void* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddFrontU16PointerP(List *dataStructure, u16 key, const volatile void** value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontU16PPointer(List *dataStructure, const volatile u16* key, void* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontU16PPointerP(List *dataStructure, const volatile u16* key, const volatile void** value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontU16I8(List *dataStructure, u16 key, i8 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddFrontU16PI8(List *dataStructure, const volatile u16* key, i8 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontU16U8(List *dataStructure, u16 key, u8 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddFrontU16PU8(List *dataStructure, const volatile u16* key, u8 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddFrontI32Bool(List *dataStructure, i32 key, bool value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddFrontI32BoolP(List *dataStructure, i32 key, const volatile bool* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontI32PBool(List *dataStructure, const volatile i32* key, bool value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontI32PBoolP(List *dataStructure, const volatile i32* key, const volatile bool* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontI32I16(List *dataStructure, i32 key, i16 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddFrontI32I16P(List *dataStructure, i32 key, const volatile i16* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontI32PI16(List *dataStructure, const volatile i32* key, i16 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontI32PI16P(List *dataStructure, const volatile i32* key, const volatile i16* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontI32U16(List *dataStructure, i32 key, u16 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddFrontI32U16P(List *dataStructure, i32 key, const volatile u16* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontI32PU16(List *dataStructure, const volatile i32* key, u16 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontI32PU16P(List *dataStructure, const volatile i32* key, const volatile u16* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontI32I32(List *dataStructure, i32 key, i32 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddFrontI32I32P(List *dataStructure, i32 key, const volatile i32* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontI32PI32(List *dataStructure, const volatile i32* key, i32 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontI32PI32P(List *dataStructure, const volatile i32* key, const volatile i32* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontI32U32(List *dataStructure, i32 key, u32 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddFrontI32U32P(List *dataStructure, i32 key, const volatile u32* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontI32PU32(List *dataStructure, const volatile i32* key, u32 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontI32PU32P(List *dataStructure, const volatile i32* key, const volatile u32* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontI32I64(List *dataStructure, i32 key, i64 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddFrontI32I64P(List *dataStructure, i32 key, const volatile i64* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontI32PI64(List *dataStructure, const volatile i32* key, i64 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontI32PI64P(List *dataStructure, const volatile i32* key, const volatile i64* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontI32U64(List *dataStructure, i32 key, u64 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddFrontI32U64P(List *dataStructure, i32 key, const volatile u64* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontI32PU64(List *dataStructure, const volatile i32* key, u64 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontI32PU64P(List *dataStructure, const volatile i32* key, const volatile u64* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontI32Float(List *dataStructure, i32 key, float value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddFrontI32FloatP(List *dataStructure, i32 key, const volatile float* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontI32PFloat(List *dataStructure, const volatile i32* key, float value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontI32PFloatP(List *dataStructure, const volatile i32* key, const volatile float* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontI32Double(List *dataStructure, i32 key, double value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddFrontI32DoubleP(List *dataStructure, i32 key, const volatile double* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontI32PDouble(List *dataStructure, const volatile i32* key, double value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontI32PDoubleP(List *dataStructure, const volatile i32* key, const volatile double* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontI32LongDouble(List *dataStructure, i32 key, long double value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontI32LongDoubleP(List *dataStructure, i32 key, const volatile long double* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontI32PLongDouble(List *dataStructure, const volatile i32* key, long double value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontI32PLongDoubleP(List *dataStructure, const volatile i32* key, const volatile long double* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontI32List(List *dataStructure, i32 key, List value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddFrontI32ListP(List *dataStructure, i32 key, const volatile List* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontI32PList(List *dataStructure, const volatile i32* key, List value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontI32PListP(List *dataStructure, const volatile i32* key, const volatile List* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontI32Queue(List *dataStructure, i32 key, Queue value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddFrontI32QueueP(List *dataStructure, i32 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontI32PQueue(List *dataStructure, const volatile i32* key, Queue value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontI32PQueueP(List *dataStructure, const volatile i32* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontI32Stack(List *dataStructure, i32 key, Stack value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddFrontI32StackP(List *dataStructure, i32 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontI32PStack(List *dataStructure, const volatile i32* key, Stack value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontI32PStackP(List *dataStructure, const volatile i32* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontI32RedBlackTree(List *dataStructure, i32 key, RedBlackTree value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontI32RedBlackTreeP(List *dataStructure, i32 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontI32PRedBlackTree(List *dataStructure, const volatile i32* key, RedBlackTree value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontI32PRedBlackTreeP(List *dataStructure, const volatile i32* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontI32HashTable(List *dataStructure, i32 key, HashTable value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddFrontI32HashTableP(List *dataStructure, i32 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontI32PHashTable(List *dataStructure, const volatile i32* key, HashTable value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontI32PHashTableP(List *dataStructure, const volatile i32* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontI32Vector(List *dataStructure, i32 key, Vector value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddFrontI32VectorP(List *dataStructure, i32 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontI32PVector(List *dataStructure, const volatile i32* key, Vector value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontI32PVectorP(List *dataStructure, const volatile i32* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontI32String(List *dataStructure, i32 key, const volatile char* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddFrontI32StringP(List *dataStructure, i32 key, const volatile char** value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontI32PString(List *dataStructure, const volatile i32* key, const volatile char* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontI32PStringP(List *dataStructure, const volatile i32* key, const volatile char** value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontI32Bytes(List *dataStructure, i32 key, Bytes value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddFrontI32BytesP(List *dataStructure, i32 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontI32PBytes(List *dataStructure, const volatile i32* key, Bytes value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontI32PBytesP(List *dataStructure, const volatile i32* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontI32Pointer(List *dataStructure, i32 key, void* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddFrontI32PointerP(List *dataStructure, i32 key, const volatile void** value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontI32PPointer(List *dataStructure, const volatile i32* key, void* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontI32PPointerP(List *dataStructure, const volatile i32* key, const volatile void** value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontI32I8(List *dataStructure, i32 key, i8 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddFrontI32PI8(List *dataStructure, const volatile i32* key, i8 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontI32U8(List *dataStructure, i32 key, u8 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddFrontI32PU8(List *dataStructure, const volatile i32* key, u8 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddFrontU32Bool(List *dataStructure, u32 key, bool value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddFrontU32BoolP(List *dataStructure, u32 key, const volatile bool* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontU32PBool(List *dataStructure, const volatile u32* key, bool value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontU32PBoolP(List *dataStructure, const volatile u32* key, const volatile bool* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontU32I16(List *dataStructure, u32 key, i16 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddFrontU32I16P(List *dataStructure, u32 key, const volatile i16* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontU32PI16(List *dataStructure, const volatile u32* key, i16 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontU32PI16P(List *dataStructure, const volatile u32* key, const volatile i16* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontU32U16(List *dataStructure, u32 key, u16 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddFrontU32U16P(List *dataStructure, u32 key, const volatile u16* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontU32PU16(List *dataStructure, const volatile u32* key, u16 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontU32PU16P(List *dataStructure, const volatile u32* key, const volatile u16* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontU32I32(List *dataStructure, u32 key, i32 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddFrontU32I32P(List *dataStructure, u32 key, const volatile i32* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontU32PI32(List *dataStructure, const volatile u32* key, i32 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontU32PI32P(List *dataStructure, const volatile u32* key, const volatile i32* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontU32U32(List *dataStructure, u32 key, u32 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddFrontU32U32P(List *dataStructure, u32 key, const volatile u32* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontU32PU32(List *dataStructure, const volatile u32* key, u32 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontU32PU32P(List *dataStructure, const volatile u32* key, const volatile u32* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontU32I64(List *dataStructure, u32 key, i64 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddFrontU32I64P(List *dataStructure, u32 key, const volatile i64* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontU32PI64(List *dataStructure, const volatile u32* key, i64 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontU32PI64P(List *dataStructure, const volatile u32* key, const volatile i64* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontU32U64(List *dataStructure, u32 key, u64 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddFrontU32U64P(List *dataStructure, u32 key, const volatile u64* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontU32PU64(List *dataStructure, const volatile u32* key, u64 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontU32PU64P(List *dataStructure, const volatile u32* key, const volatile u64* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontU32Float(List *dataStructure, u32 key, float value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddFrontU32FloatP(List *dataStructure, u32 key, const volatile float* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontU32PFloat(List *dataStructure, const volatile u32* key, float value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontU32PFloatP(List *dataStructure, const volatile u32* key, const volatile float* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontU32Double(List *dataStructure, u32 key, double value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddFrontU32DoubleP(List *dataStructure, u32 key, const volatile double* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontU32PDouble(List *dataStructure, const volatile u32* key, double value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontU32PDoubleP(List *dataStructure, const volatile u32* key, const volatile double* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontU32LongDouble(List *dataStructure, u32 key, long double value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontU32LongDoubleP(List *dataStructure, u32 key, const volatile long double* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontU32PLongDouble(List *dataStructure, const volatile u32* key, long double value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontU32PLongDoubleP(List *dataStructure, const volatile u32* key, const volatile long double* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontU32List(List *dataStructure, u32 key, List value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddFrontU32ListP(List *dataStructure, u32 key, const volatile List* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontU32PList(List *dataStructure, const volatile u32* key, List value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontU32PListP(List *dataStructure, const volatile u32* key, const volatile List* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontU32Queue(List *dataStructure, u32 key, Queue value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddFrontU32QueueP(List *dataStructure, u32 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontU32PQueue(List *dataStructure, const volatile u32* key, Queue value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontU32PQueueP(List *dataStructure, const volatile u32* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontU32Stack(List *dataStructure, u32 key, Stack value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddFrontU32StackP(List *dataStructure, u32 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontU32PStack(List *dataStructure, const volatile u32* key, Stack value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontU32PStackP(List *dataStructure, const volatile u32* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontU32RedBlackTree(List *dataStructure, u32 key, RedBlackTree value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontU32RedBlackTreeP(List *dataStructure, u32 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontU32PRedBlackTree(List *dataStructure, const volatile u32* key, RedBlackTree value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontU32PRedBlackTreeP(List *dataStructure, const volatile u32* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontU32HashTable(List *dataStructure, u32 key, HashTable value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddFrontU32HashTableP(List *dataStructure, u32 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontU32PHashTable(List *dataStructure, const volatile u32* key, HashTable value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontU32PHashTableP(List *dataStructure, const volatile u32* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontU32Vector(List *dataStructure, u32 key, Vector value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddFrontU32VectorP(List *dataStructure, u32 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontU32PVector(List *dataStructure, const volatile u32* key, Vector value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontU32PVectorP(List *dataStructure, const volatile u32* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontU32String(List *dataStructure, u32 key, const volatile char* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddFrontU32StringP(List *dataStructure, u32 key, const volatile char** value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontU32PString(List *dataStructure, const volatile u32* key, const volatile char* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontU32PStringP(List *dataStructure, const volatile u32* key, const volatile char** value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontU32Bytes(List *dataStructure, u32 key, Bytes value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddFrontU32BytesP(List *dataStructure, u32 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontU32PBytes(List *dataStructure, const volatile u32* key, Bytes value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontU32PBytesP(List *dataStructure, const volatile u32* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontU32Pointer(List *dataStructure, u32 key, void* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddFrontU32PointerP(List *dataStructure, u32 key, const volatile void** value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontU32PPointer(List *dataStructure, const volatile u32* key, void* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontU32PPointerP(List *dataStructure, const volatile u32* key, const volatile void** value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontU32I8(List *dataStructure, u32 key, i8 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddFrontU32PI8(List *dataStructure, const volatile u32* key, i8 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontU32U8(List *dataStructure, u32 key, u8 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddFrontU32PU8(List *dataStructure, const volatile u32* key, u8 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddFrontI64Bool(List *dataStructure, i64 key, bool value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddFrontI64BoolP(List *dataStructure, i64 key, const volatile bool* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontI64PBool(List *dataStructure, const volatile i64* key, bool value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontI64PBoolP(List *dataStructure, const volatile i64* key, const volatile bool* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontI64I16(List *dataStructure, i64 key, i16 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddFrontI64I16P(List *dataStructure, i64 key, const volatile i16* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontI64PI16(List *dataStructure, const volatile i64* key, i16 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontI64PI16P(List *dataStructure, const volatile i64* key, const volatile i16* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontI64U16(List *dataStructure, i64 key, u16 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddFrontI64U16P(List *dataStructure, i64 key, const volatile u16* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontI64PU16(List *dataStructure, const volatile i64* key, u16 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontI64PU16P(List *dataStructure, const volatile i64* key, const volatile u16* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontI64I32(List *dataStructure, i64 key, i32 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddFrontI64I32P(List *dataStructure, i64 key, const volatile i32* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontI64PI32(List *dataStructure, const volatile i64* key, i32 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontI64PI32P(List *dataStructure, const volatile i64* key, const volatile i32* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontI64U32(List *dataStructure, i64 key, u32 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddFrontI64U32P(List *dataStructure, i64 key, const volatile u32* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontI64PU32(List *dataStructure, const volatile i64* key, u32 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontI64PU32P(List *dataStructure, const volatile i64* key, const volatile u32* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontI64I64(List *dataStructure, i64 key, i64 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddFrontI64I64P(List *dataStructure, i64 key, const volatile i64* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontI64PI64(List *dataStructure, const volatile i64* key, i64 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontI64PI64P(List *dataStructure, const volatile i64* key, const volatile i64* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontI64U64(List *dataStructure, i64 key, u64 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddFrontI64U64P(List *dataStructure, i64 key, const volatile u64* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontI64PU64(List *dataStructure, const volatile i64* key, u64 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontI64PU64P(List *dataStructure, const volatile i64* key, const volatile u64* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontI64Float(List *dataStructure, i64 key, float value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddFrontI64FloatP(List *dataStructure, i64 key, const volatile float* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontI64PFloat(List *dataStructure, const volatile i64* key, float value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontI64PFloatP(List *dataStructure, const volatile i64* key, const volatile float* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontI64Double(List *dataStructure, i64 key, double value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddFrontI64DoubleP(List *dataStructure, i64 key, const volatile double* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontI64PDouble(List *dataStructure, const volatile i64* key, double value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontI64PDoubleP(List *dataStructure, const volatile i64* key, const volatile double* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontI64LongDouble(List *dataStructure, i64 key, long double value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontI64LongDoubleP(List *dataStructure, i64 key, const volatile long double* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontI64PLongDouble(List *dataStructure, const volatile i64* key, long double value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontI64PLongDoubleP(List *dataStructure, const volatile i64* key, const volatile long double* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontI64List(List *dataStructure, i64 key, List value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddFrontI64ListP(List *dataStructure, i64 key, const volatile List* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontI64PList(List *dataStructure, const volatile i64* key, List value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontI64PListP(List *dataStructure, const volatile i64* key, const volatile List* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontI64Queue(List *dataStructure, i64 key, Queue value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddFrontI64QueueP(List *dataStructure, i64 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontI64PQueue(List *dataStructure, const volatile i64* key, Queue value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontI64PQueueP(List *dataStructure, const volatile i64* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontI64Stack(List *dataStructure, i64 key, Stack value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddFrontI64StackP(List *dataStructure, i64 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontI64PStack(List *dataStructure, const volatile i64* key, Stack value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontI64PStackP(List *dataStructure, const volatile i64* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontI64RedBlackTree(List *dataStructure, i64 key, RedBlackTree value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontI64RedBlackTreeP(List *dataStructure, i64 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontI64PRedBlackTree(List *dataStructure, const volatile i64* key, RedBlackTree value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontI64PRedBlackTreeP(List *dataStructure, const volatile i64* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontI64HashTable(List *dataStructure, i64 key, HashTable value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddFrontI64HashTableP(List *dataStructure, i64 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontI64PHashTable(List *dataStructure, const volatile i64* key, HashTable value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontI64PHashTableP(List *dataStructure, const volatile i64* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontI64Vector(List *dataStructure, i64 key, Vector value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddFrontI64VectorP(List *dataStructure, i64 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontI64PVector(List *dataStructure, const volatile i64* key, Vector value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontI64PVectorP(List *dataStructure, const volatile i64* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontI64String(List *dataStructure, i64 key, const volatile char* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddFrontI64StringP(List *dataStructure, i64 key, const volatile char** value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontI64PString(List *dataStructure, const volatile i64* key, const volatile char* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontI64PStringP(List *dataStructure, const volatile i64* key, const volatile char** value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontI64Bytes(List *dataStructure, i64 key, Bytes value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddFrontI64BytesP(List *dataStructure, i64 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontI64PBytes(List *dataStructure, const volatile i64* key, Bytes value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontI64PBytesP(List *dataStructure, const volatile i64* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontI64Pointer(List *dataStructure, i64 key, void* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddFrontI64PointerP(List *dataStructure, i64 key, const volatile void** value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontI64PPointer(List *dataStructure, const volatile i64* key, void* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontI64PPointerP(List *dataStructure, const volatile i64* key, const volatile void** value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontI64I8(List *dataStructure, i64 key, i8 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddFrontI64PI8(List *dataStructure, const volatile i64* key, i8 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontI64U8(List *dataStructure, i64 key, u8 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddFrontI64PU8(List *dataStructure, const volatile i64* key, u8 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddFrontU64Bool(List *dataStructure, u64 key, bool value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddFrontU64BoolP(List *dataStructure, u64 key, const volatile bool* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontU64PBool(List *dataStructure, const volatile u64* key, bool value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontU64PBoolP(List *dataStructure, const volatile u64* key, const volatile bool* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontU64I16(List *dataStructure, u64 key, i16 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddFrontU64I16P(List *dataStructure, u64 key, const volatile i16* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontU64PI16(List *dataStructure, const volatile u64* key, i16 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontU64PI16P(List *dataStructure, const volatile u64* key, const volatile i16* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontU64U16(List *dataStructure, u64 key, u16 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddFrontU64U16P(List *dataStructure, u64 key, const volatile u16* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontU64PU16(List *dataStructure, const volatile u64* key, u16 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontU64PU16P(List *dataStructure, const volatile u64* key, const volatile u16* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontU64I32(List *dataStructure, u64 key, i32 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddFrontU64I32P(List *dataStructure, u64 key, const volatile i32* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontU64PI32(List *dataStructure, const volatile u64* key, i32 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontU64PI32P(List *dataStructure, const volatile u64* key, const volatile i32* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontU64U32(List *dataStructure, u64 key, u32 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddFrontU64U32P(List *dataStructure, u64 key, const volatile u32* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontU64PU32(List *dataStructure, const volatile u64* key, u32 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontU64PU32P(List *dataStructure, const volatile u64* key, const volatile u32* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontU64I64(List *dataStructure, u64 key, i64 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddFrontU64I64P(List *dataStructure, u64 key, const volatile i64* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontU64PI64(List *dataStructure, const volatile u64* key, i64 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontU64PI64P(List *dataStructure, const volatile u64* key, const volatile i64* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontU64U64(List *dataStructure, u64 key, u64 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddFrontU64U64P(List *dataStructure, u64 key, const volatile u64* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontU64PU64(List *dataStructure, const volatile u64* key, u64 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontU64PU64P(List *dataStructure, const volatile u64* key, const volatile u64* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontU64Float(List *dataStructure, u64 key, float value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddFrontU64FloatP(List *dataStructure, u64 key, const volatile float* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontU64PFloat(List *dataStructure, const volatile u64* key, float value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontU64PFloatP(List *dataStructure, const volatile u64* key, const volatile float* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontU64Double(List *dataStructure, u64 key, double value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddFrontU64DoubleP(List *dataStructure, u64 key, const volatile double* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontU64PDouble(List *dataStructure, const volatile u64* key, double value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontU64PDoubleP(List *dataStructure, const volatile u64* key, const volatile double* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontU64LongDouble(List *dataStructure, u64 key, long double value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontU64LongDoubleP(List *dataStructure, u64 key, const volatile long double* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontU64PLongDouble(List *dataStructure, const volatile u64* key, long double value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontU64PLongDoubleP(List *dataStructure, const volatile u64* key, const volatile long double* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontU64List(List *dataStructure, u64 key, List value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddFrontU64ListP(List *dataStructure, u64 key, const volatile List* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontU64PList(List *dataStructure, const volatile u64* key, List value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontU64PListP(List *dataStructure, const volatile u64* key, const volatile List* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontU64Queue(List *dataStructure, u64 key, Queue value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddFrontU64QueueP(List *dataStructure, u64 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontU64PQueue(List *dataStructure, const volatile u64* key, Queue value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontU64PQueueP(List *dataStructure, const volatile u64* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontU64Stack(List *dataStructure, u64 key, Stack value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddFrontU64StackP(List *dataStructure, u64 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontU64PStack(List *dataStructure, const volatile u64* key, Stack value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontU64PStackP(List *dataStructure, const volatile u64* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontU64RedBlackTree(List *dataStructure, u64 key, RedBlackTree value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontU64RedBlackTreeP(List *dataStructure, u64 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontU64PRedBlackTree(List *dataStructure, const volatile u64* key, RedBlackTree value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontU64PRedBlackTreeP(List *dataStructure, const volatile u64* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontU64HashTable(List *dataStructure, u64 key, HashTable value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddFrontU64HashTableP(List *dataStructure, u64 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontU64PHashTable(List *dataStructure, const volatile u64* key, HashTable value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontU64PHashTableP(List *dataStructure, const volatile u64* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontU64Vector(List *dataStructure, u64 key, Vector value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddFrontU64VectorP(List *dataStructure, u64 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontU64PVector(List *dataStructure, const volatile u64* key, Vector value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontU64PVectorP(List *dataStructure, const volatile u64* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontU64String(List *dataStructure, u64 key, const volatile char* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddFrontU64StringP(List *dataStructure, u64 key, const volatile char** value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontU64PString(List *dataStructure, const volatile u64* key, const volatile char* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontU64PStringP(List *dataStructure, const volatile u64* key, const volatile char** value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontU64Bytes(List *dataStructure, u64 key, Bytes value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddFrontU64BytesP(List *dataStructure, u64 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontU64PBytes(List *dataStructure, const volatile u64* key, Bytes value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontU64PBytesP(List *dataStructure, const volatile u64* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontU64Pointer(List *dataStructure, u64 key, void* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddFrontU64PointerP(List *dataStructure, u64 key, const volatile void** value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontU64PPointer(List *dataStructure, const volatile u64* key, void* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontU64PPointerP(List *dataStructure, const volatile u64* key, const volatile void** value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontU64I8(List *dataStructure, u64 key, i8 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddFrontU64PI8(List *dataStructure, const volatile u64* key, i8 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontU64U8(List *dataStructure, u64 key, u8 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddFrontU64PU8(List *dataStructure, const volatile u64* key, u8 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddFrontFloatBool(List *dataStructure, float key, bool value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddFrontFloatBoolP(List *dataStructure, float key, const volatile bool* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontFloatPBool(List *dataStructure, const volatile float* key, bool value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontFloatPBoolP(List *dataStructure, const volatile float* key, const volatile bool* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontFloatI16(List *dataStructure, float key, i16 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddFrontFloatI16P(List *dataStructure, float key, const volatile i16* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontFloatPI16(List *dataStructure, const volatile float* key, i16 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontFloatPI16P(List *dataStructure, const volatile float* key, const volatile i16* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontFloatU16(List *dataStructure, float key, u16 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddFrontFloatU16P(List *dataStructure, float key, const volatile u16* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontFloatPU16(List *dataStructure, const volatile float* key, u16 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontFloatPU16P(List *dataStructure, const volatile float* key, const volatile u16* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontFloatI32(List *dataStructure, float key, i32 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddFrontFloatI32P(List *dataStructure, float key, const volatile i32* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontFloatPI32(List *dataStructure, const volatile float* key, i32 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontFloatPI32P(List *dataStructure, const volatile float* key, const volatile i32* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontFloatU32(List *dataStructure, float key, u32 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddFrontFloatU32P(List *dataStructure, float key, const volatile u32* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontFloatPU32(List *dataStructure, const volatile float* key, u32 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontFloatPU32P(List *dataStructure, const volatile float* key, const volatile u32* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontFloatI64(List *dataStructure, float key, i64 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddFrontFloatI64P(List *dataStructure, float key, const volatile i64* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontFloatPI64(List *dataStructure, const volatile float* key, i64 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontFloatPI64P(List *dataStructure, const volatile float* key, const volatile i64* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontFloatU64(List *dataStructure, float key, u64 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddFrontFloatU64P(List *dataStructure, float key, const volatile u64* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontFloatPU64(List *dataStructure, const volatile float* key, u64 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontFloatPU64P(List *dataStructure, const volatile float* key, const volatile u64* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontFloatFloat(List *dataStructure, float key, float value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddFrontFloatFloatP(List *dataStructure, float key, const volatile float* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontFloatPFloat(List *dataStructure, const volatile float* key, float value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontFloatPFloatP(List *dataStructure, const volatile float* key, const volatile float* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontFloatDouble(List *dataStructure, float key, double value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddFrontFloatDoubleP(List *dataStructure, float key, const volatile double* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontFloatPDouble(List *dataStructure, const volatile float* key, double value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontFloatPDoubleP(List *dataStructure, const volatile float* key, const volatile double* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontFloatLongDouble(List *dataStructure, float key, long double value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontFloatLongDoubleP(List *dataStructure, float key, const volatile long double* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontFloatPLongDouble(List *dataStructure, const volatile float* key, long double value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontFloatPLongDoubleP(List *dataStructure, const volatile float* key, const volatile long double* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontFloatList(List *dataStructure, float key, List value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddFrontFloatListP(List *dataStructure, float key, const volatile List* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontFloatPList(List *dataStructure, const volatile float* key, List value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontFloatPListP(List *dataStructure, const volatile float* key, const volatile List* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontFloatQueue(List *dataStructure, float key, Queue value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddFrontFloatQueueP(List *dataStructure, float key, const volatile Queue* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontFloatPQueue(List *dataStructure, const volatile float* key, Queue value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontFloatPQueueP(List *dataStructure, const volatile float* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontFloatStack(List *dataStructure, float key, Stack value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddFrontFloatStackP(List *dataStructure, float key, const volatile Stack* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontFloatPStack(List *dataStructure, const volatile float* key, Stack value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontFloatPStackP(List *dataStructure, const volatile float* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontFloatRedBlackTree(List *dataStructure, float key, RedBlackTree value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontFloatRedBlackTreeP(List *dataStructure, float key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontFloatPRedBlackTree(List *dataStructure, const volatile float* key, RedBlackTree value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontFloatPRedBlackTreeP(List *dataStructure, const volatile float* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontFloatHashTable(List *dataStructure, float key, HashTable value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddFrontFloatHashTableP(List *dataStructure, float key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontFloatPHashTable(List *dataStructure, const volatile float* key, HashTable value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontFloatPHashTableP(List *dataStructure, const volatile float* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontFloatVector(List *dataStructure, float key, Vector value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddFrontFloatVectorP(List *dataStructure, float key, const volatile Vector* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontFloatPVector(List *dataStructure, const volatile float* key, Vector value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontFloatPVectorP(List *dataStructure, const volatile float* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontFloatString(List *dataStructure, float key, const volatile char* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddFrontFloatStringP(List *dataStructure, float key, const volatile char** value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontFloatPString(List *dataStructure, const volatile float* key, const volatile char* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontFloatPStringP(List *dataStructure, const volatile float* key, const volatile char** value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontFloatBytes(List *dataStructure, float key, Bytes value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddFrontFloatBytesP(List *dataStructure, float key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontFloatPBytes(List *dataStructure, const volatile float* key, Bytes value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontFloatPBytesP(List *dataStructure, const volatile float* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontFloatPointer(List *dataStructure, float key, void* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddFrontFloatPointerP(List *dataStructure, float key, const volatile void** value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontFloatPPointer(List *dataStructure, const volatile float* key, void* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontFloatPPointerP(List *dataStructure, const volatile float* key, const volatile void** value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontFloatI8(List *dataStructure, float key, i8 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddFrontFloatPI8(List *dataStructure, const volatile float* key, i8 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontFloatU8(List *dataStructure, float key, u8 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddFrontFloatPU8(List *dataStructure, const volatile float* key, u8 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddFrontDoubleBool(List *dataStructure, double key, bool value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddFrontDoubleBoolP(List *dataStructure, double key, const volatile bool* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontDoublePBool(List *dataStructure, const volatile double* key, bool value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontDoublePBoolP(List *dataStructure, const volatile double* key, const volatile bool* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontDoubleI16(List *dataStructure, double key, i16 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddFrontDoubleI16P(List *dataStructure, double key, const volatile i16* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontDoublePI16(List *dataStructure, const volatile double* key, i16 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontDoublePI16P(List *dataStructure, const volatile double* key, const volatile i16* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontDoubleU16(List *dataStructure, double key, u16 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddFrontDoubleU16P(List *dataStructure, double key, const volatile u16* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontDoublePU16(List *dataStructure, const volatile double* key, u16 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontDoublePU16P(List *dataStructure, const volatile double* key, const volatile u16* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontDoubleI32(List *dataStructure, double key, i32 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddFrontDoubleI32P(List *dataStructure, double key, const volatile i32* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontDoublePI32(List *dataStructure, const volatile double* key, i32 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontDoublePI32P(List *dataStructure, const volatile double* key, const volatile i32* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontDoubleU32(List *dataStructure, double key, u32 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddFrontDoubleU32P(List *dataStructure, double key, const volatile u32* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontDoublePU32(List *dataStructure, const volatile double* key, u32 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontDoublePU32P(List *dataStructure, const volatile double* key, const volatile u32* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontDoubleI64(List *dataStructure, double key, i64 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddFrontDoubleI64P(List *dataStructure, double key, const volatile i64* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontDoublePI64(List *dataStructure, const volatile double* key, i64 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontDoublePI64P(List *dataStructure, const volatile double* key, const volatile i64* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontDoubleU64(List *dataStructure, double key, u64 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddFrontDoubleU64P(List *dataStructure, double key, const volatile u64* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontDoublePU64(List *dataStructure, const volatile double* key, u64 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontDoublePU64P(List *dataStructure, const volatile double* key, const volatile u64* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontDoubleFloat(List *dataStructure, double key, float value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddFrontDoubleFloatP(List *dataStructure, double key, const volatile float* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontDoublePFloat(List *dataStructure, const volatile double* key, float value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontDoublePFloatP(List *dataStructure, const volatile double* key, const volatile float* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontDoubleDouble(List *dataStructure, double key, double value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddFrontDoubleDoubleP(List *dataStructure, double key, const volatile double* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontDoublePDouble(List *dataStructure, const volatile double* key, double value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontDoublePDoubleP(List *dataStructure, const volatile double* key, const volatile double* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontDoubleLongDouble(List *dataStructure, double key, long double value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontDoubleLongDoubleP(List *dataStructure, double key, const volatile long double* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontDoublePLongDouble(List *dataStructure, const volatile double* key, long double value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontDoublePLongDoubleP(List *dataStructure, const volatile double* key, const volatile long double* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontDoubleList(List *dataStructure, double key, List value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddFrontDoubleListP(List *dataStructure, double key, const volatile List* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontDoublePList(List *dataStructure, const volatile double* key, List value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontDoublePListP(List *dataStructure, const volatile double* key, const volatile List* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontDoubleQueue(List *dataStructure, double key, Queue value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddFrontDoubleQueueP(List *dataStructure, double key, const volatile Queue* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontDoublePQueue(List *dataStructure, const volatile double* key, Queue value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontDoublePQueueP(List *dataStructure, const volatile double* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontDoubleStack(List *dataStructure, double key, Stack value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddFrontDoubleStackP(List *dataStructure, double key, const volatile Stack* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontDoublePStack(List *dataStructure, const volatile double* key, Stack value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontDoublePStackP(List *dataStructure, const volatile double* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontDoubleRedBlackTree(List *dataStructure, double key, RedBlackTree value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontDoubleRedBlackTreeP(List *dataStructure, double key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontDoublePRedBlackTree(List *dataStructure, const volatile double* key, RedBlackTree value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontDoublePRedBlackTreeP(List *dataStructure, const volatile double* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontDoubleHashTable(List *dataStructure, double key, HashTable value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddFrontDoubleHashTableP(List *dataStructure, double key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontDoublePHashTable(List *dataStructure, const volatile double* key, HashTable value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontDoublePHashTableP(List *dataStructure, const volatile double* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontDoubleVector(List *dataStructure, double key, Vector value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddFrontDoubleVectorP(List *dataStructure, double key, const volatile Vector* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontDoublePVector(List *dataStructure, const volatile double* key, Vector value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontDoublePVectorP(List *dataStructure, const volatile double* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontDoubleString(List *dataStructure, double key, const volatile char* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddFrontDoubleStringP(List *dataStructure, double key, const volatile char** value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontDoublePString(List *dataStructure, const volatile double* key, const volatile char* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontDoublePStringP(List *dataStructure, const volatile double* key, const volatile char** value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontDoubleBytes(List *dataStructure, double key, Bytes value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddFrontDoubleBytesP(List *dataStructure, double key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontDoublePBytes(List *dataStructure, const volatile double* key, Bytes value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontDoublePBytesP(List *dataStructure, const volatile double* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontDoublePointer(List *dataStructure, double key, void* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddFrontDoublePointerP(List *dataStructure, double key, const volatile void** value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontDoublePPointer(List *dataStructure, const volatile double* key, void* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontDoublePPointerP(List *dataStructure, const volatile double* key, const volatile void** value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontDoubleI8(List *dataStructure, double key, i8 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddFrontDoublePI8(List *dataStructure, const volatile double* key, i8 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontDoubleU8(List *dataStructure, double key, u8 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddFrontDoublePU8(List *dataStructure, const volatile double* key, u8 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddFrontLongDoubleBool(List *dataStructure, long double key, bool value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddFrontLongDoubleBoolP(List *dataStructure, long double key, const volatile bool* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontLongDoublePBool(List *dataStructure, const volatile long double* key, bool value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontLongDoublePBoolP(List *dataStructure, const volatile long double* key, const volatile bool* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontLongDoubleI16(List *dataStructure, long double key, i16 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddFrontLongDoubleI16P(List *dataStructure, long double key, const volatile i16* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontLongDoublePI16(List *dataStructure, const volatile long double* key, i16 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontLongDoublePI16P(List *dataStructure, const volatile long double* key, const volatile i16* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontLongDoubleU16(List *dataStructure, long double key, u16 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddFrontLongDoubleU16P(List *dataStructure, long double key, const volatile u16* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontLongDoublePU16(List *dataStructure, const volatile long double* key, u16 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontLongDoublePU16P(List *dataStructure, const volatile long double* key, const volatile u16* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontLongDoubleI32(List *dataStructure, long double key, i32 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddFrontLongDoubleI32P(List *dataStructure, long double key, const volatile i32* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontLongDoublePI32(List *dataStructure, const volatile long double* key, i32 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontLongDoublePI32P(List *dataStructure, const volatile long double* key, const volatile i32* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontLongDoubleU32(List *dataStructure, long double key, u32 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddFrontLongDoubleU32P(List *dataStructure, long double key, const volatile u32* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontLongDoublePU32(List *dataStructure, const volatile long double* key, u32 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontLongDoublePU32P(List *dataStructure, const volatile long double* key, const volatile u32* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontLongDoubleI64(List *dataStructure, long double key, i64 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddFrontLongDoubleI64P(List *dataStructure, long double key, const volatile i64* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontLongDoublePI64(List *dataStructure, const volatile long double* key, i64 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontLongDoublePI64P(List *dataStructure, const volatile long double* key, const volatile i64* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontLongDoubleU64(List *dataStructure, long double key, u64 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddFrontLongDoubleU64P(List *dataStructure, long double key, const volatile u64* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontLongDoublePU64(List *dataStructure, const volatile long double* key, u64 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontLongDoublePU64P(List *dataStructure, const volatile long double* key, const volatile u64* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontLongDoubleFloat(List *dataStructure, long double key, float value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddFrontLongDoubleFloatP(List *dataStructure, long double key, const volatile float* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontLongDoublePFloat(List *dataStructure, const volatile long double* key, float value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontLongDoublePFloatP(List *dataStructure, const volatile long double* key, const volatile float* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontLongDoubleDouble(List *dataStructure, long double key, double value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddFrontLongDoubleDoubleP(List *dataStructure, long double key, const volatile double* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontLongDoublePDouble(List *dataStructure, const volatile long double* key, double value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontLongDoublePDoubleP(List *dataStructure, const volatile long double* key, const volatile double* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontLongDoubleLongDouble(List *dataStructure, long double key, long double value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontLongDoubleLongDoubleP(List *dataStructure, long double key, const volatile long double* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontLongDoublePLongDouble(List *dataStructure, const volatile long double* key, long double value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontLongDoublePLongDoubleP(List *dataStructure, const volatile long double* key, const volatile long double* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontLongDoubleList(List *dataStructure, long double key, List value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddFrontLongDoubleListP(List *dataStructure, long double key, const volatile List* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontLongDoublePList(List *dataStructure, const volatile long double* key, List value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontLongDoublePListP(List *dataStructure, const volatile long double* key, const volatile List* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontLongDoubleQueue(List *dataStructure, long double key, Queue value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddFrontLongDoubleQueueP(List *dataStructure, long double key, const volatile Queue* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontLongDoublePQueue(List *dataStructure, const volatile long double* key, Queue value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontLongDoublePQueueP(List *dataStructure, const volatile long double* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontLongDoubleStack(List *dataStructure, long double key, Stack value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddFrontLongDoubleStackP(List *dataStructure, long double key, const volatile Stack* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontLongDoublePStack(List *dataStructure, const volatile long double* key, Stack value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontLongDoublePStackP(List *dataStructure, const volatile long double* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontLongDoubleRedBlackTree(List *dataStructure, long double key, RedBlackTree value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontLongDoubleRedBlackTreeP(List *dataStructure, long double key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontLongDoublePRedBlackTree(List *dataStructure, const volatile long double* key, RedBlackTree value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontLongDoublePRedBlackTreeP(List *dataStructure, const volatile long double* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontLongDoubleHashTable(List *dataStructure, long double key, HashTable value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddFrontLongDoubleHashTableP(List *dataStructure, long double key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontLongDoublePHashTable(List *dataStructure, const volatile long double* key, HashTable value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontLongDoublePHashTableP(List *dataStructure, const volatile long double* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontLongDoubleVector(List *dataStructure, long double key, Vector value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddFrontLongDoubleVectorP(List *dataStructure, long double key, const volatile Vector* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontLongDoublePVector(List *dataStructure, const volatile long double* key, Vector value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontLongDoublePVectorP(List *dataStructure, const volatile long double* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontLongDoubleString(List *dataStructure, long double key, const volatile char* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddFrontLongDoubleStringP(List *dataStructure, long double key, const volatile char** value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontLongDoublePString(List *dataStructure, const volatile long double* key, const volatile char* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontLongDoublePStringP(List *dataStructure, const volatile long double* key, const volatile char** value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontLongDoubleBytes(List *dataStructure, long double key, Bytes value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddFrontLongDoubleBytesP(List *dataStructure, long double key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontLongDoublePBytes(List *dataStructure, const volatile long double* key, Bytes value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontLongDoublePBytesP(List *dataStructure, const volatile long double* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontLongDoublePointer(List *dataStructure, long double key, void* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddFrontLongDoublePointerP(List *dataStructure, long double key, const volatile void** value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontLongDoublePPointer(List *dataStructure, const volatile long double* key, void* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontLongDoublePPointerP(List *dataStructure, const volatile long double* key, const volatile void** value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontLongDoubleI8(List *dataStructure, long double key, i8 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddFrontLongDoublePI8(List *dataStructure, const volatile long double* key, i8 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontLongDoubleU8(List *dataStructure, long double key, u8 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddFrontLongDoublePU8(List *dataStructure, const volatile long double* key, u8 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddFrontListBool(List *dataStructure, List key, bool value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddFrontListBoolP(List *dataStructure, List key, const volatile bool* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontListPBool(List *dataStructure, const volatile List* key, bool value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontListPBoolP(List *dataStructure, const volatile List* key, const volatile bool* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontListI16(List *dataStructure, List key, i16 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddFrontListI16P(List *dataStructure, List key, const volatile i16* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontListPI16(List *dataStructure, const volatile List* key, i16 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontListPI16P(List *dataStructure, const volatile List* key, const volatile i16* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontListU16(List *dataStructure, List key, u16 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddFrontListU16P(List *dataStructure, List key, const volatile u16* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontListPU16(List *dataStructure, const volatile List* key, u16 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontListPU16P(List *dataStructure, const volatile List* key, const volatile u16* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontListI32(List *dataStructure, List key, i32 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddFrontListI32P(List *dataStructure, List key, const volatile i32* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontListPI32(List *dataStructure, const volatile List* key, i32 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontListPI32P(List *dataStructure, const volatile List* key, const volatile i32* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontListU32(List *dataStructure, List key, u32 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddFrontListU32P(List *dataStructure, List key, const volatile u32* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontListPU32(List *dataStructure, const volatile List* key, u32 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontListPU32P(List *dataStructure, const volatile List* key, const volatile u32* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontListI64(List *dataStructure, List key, i64 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddFrontListI64P(List *dataStructure, List key, const volatile i64* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontListPI64(List *dataStructure, const volatile List* key, i64 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontListPI64P(List *dataStructure, const volatile List* key, const volatile i64* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontListU64(List *dataStructure, List key, u64 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddFrontListU64P(List *dataStructure, List key, const volatile u64* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontListPU64(List *dataStructure, const volatile List* key, u64 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontListPU64P(List *dataStructure, const volatile List* key, const volatile u64* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontListFloat(List *dataStructure, List key, float value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddFrontListFloatP(List *dataStructure, List key, const volatile float* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontListPFloat(List *dataStructure, const volatile List* key, float value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontListPFloatP(List *dataStructure, const volatile List* key, const volatile float* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontListDouble(List *dataStructure, List key, double value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddFrontListDoubleP(List *dataStructure, List key, const volatile double* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontListPDouble(List *dataStructure, const volatile List* key, double value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontListPDoubleP(List *dataStructure, const volatile List* key, const volatile double* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontListLongDouble(List *dataStructure, List key, long double value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontListLongDoubleP(List *dataStructure, List key, const volatile long double* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontListPLongDouble(List *dataStructure, const volatile List* key, long double value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontListPLongDoubleP(List *dataStructure, const volatile List* key, const volatile long double* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontListList(List *dataStructure, List key, List value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddFrontListListP(List *dataStructure, List key, const volatile List* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontListPList(List *dataStructure, const volatile List* key, List value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontListPListP(List *dataStructure, const volatile List* key, const volatile List* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontListQueue(List *dataStructure, List key, Queue value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddFrontListQueueP(List *dataStructure, List key, const volatile Queue* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontListPQueue(List *dataStructure, const volatile List* key, Queue value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontListPQueueP(List *dataStructure, const volatile List* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontListStack(List *dataStructure, List key, Stack value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddFrontListStackP(List *dataStructure, List key, const volatile Stack* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontListPStack(List *dataStructure, const volatile List* key, Stack value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontListPStackP(List *dataStructure, const volatile List* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontListRedBlackTree(List *dataStructure, List key, RedBlackTree value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontListRedBlackTreeP(List *dataStructure, List key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontListPRedBlackTree(List *dataStructure, const volatile List* key, RedBlackTree value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontListPRedBlackTreeP(List *dataStructure, const volatile List* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontListHashTable(List *dataStructure, List key, HashTable value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddFrontListHashTableP(List *dataStructure, List key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontListPHashTable(List *dataStructure, const volatile List* key, HashTable value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontListPHashTableP(List *dataStructure, const volatile List* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontListVector(List *dataStructure, List key, Vector value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddFrontListVectorP(List *dataStructure, List key, const volatile Vector* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontListPVector(List *dataStructure, const volatile List* key, Vector value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontListPVectorP(List *dataStructure, const volatile List* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontListString(List *dataStructure, List key, const volatile char* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddFrontListStringP(List *dataStructure, List key, const volatile char** value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontListPString(List *dataStructure, const volatile List* key, const volatile char* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontListPStringP(List *dataStructure, const volatile List* key, const volatile char** value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontListBytes(List *dataStructure, List key, Bytes value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddFrontListBytesP(List *dataStructure, List key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontListPBytes(List *dataStructure, const volatile List* key, Bytes value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontListPBytesP(List *dataStructure, const volatile List* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontListPointer(List *dataStructure, List key, void* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddFrontListPointerP(List *dataStructure, List key, const volatile void** value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontListPPointer(List *dataStructure, const volatile List* key, void* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontListPPointerP(List *dataStructure, const volatile List* key, const volatile void** value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontListI8(List *dataStructure, List key, i8 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddFrontListPI8(List *dataStructure, const volatile List* key, i8 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontListU8(List *dataStructure, List key, u8 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddFrontListPU8(List *dataStructure, const volatile List* key, u8 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddFrontQueueBool(List *dataStructure, Queue key, bool value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddFrontQueueBoolP(List *dataStructure, Queue key, const volatile bool* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontQueuePBool(List *dataStructure, const volatile Queue* key, bool value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontQueuePBoolP(List *dataStructure, const volatile Queue* key, const volatile bool* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontQueueI16(List *dataStructure, Queue key, i16 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddFrontQueueI16P(List *dataStructure, Queue key, const volatile i16* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontQueuePI16(List *dataStructure, const volatile Queue* key, i16 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontQueuePI16P(List *dataStructure, const volatile Queue* key, const volatile i16* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontQueueU16(List *dataStructure, Queue key, u16 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddFrontQueueU16P(List *dataStructure, Queue key, const volatile u16* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontQueuePU16(List *dataStructure, const volatile Queue* key, u16 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontQueuePU16P(List *dataStructure, const volatile Queue* key, const volatile u16* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontQueueI32(List *dataStructure, Queue key, i32 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddFrontQueueI32P(List *dataStructure, Queue key, const volatile i32* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontQueuePI32(List *dataStructure, const volatile Queue* key, i32 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontQueuePI32P(List *dataStructure, const volatile Queue* key, const volatile i32* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontQueueU32(List *dataStructure, Queue key, u32 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddFrontQueueU32P(List *dataStructure, Queue key, const volatile u32* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontQueuePU32(List *dataStructure, const volatile Queue* key, u32 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontQueuePU32P(List *dataStructure, const volatile Queue* key, const volatile u32* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontQueueI64(List *dataStructure, Queue key, i64 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddFrontQueueI64P(List *dataStructure, Queue key, const volatile i64* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontQueuePI64(List *dataStructure, const volatile Queue* key, i64 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontQueuePI64P(List *dataStructure, const volatile Queue* key, const volatile i64* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontQueueU64(List *dataStructure, Queue key, u64 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddFrontQueueU64P(List *dataStructure, Queue key, const volatile u64* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontQueuePU64(List *dataStructure, const volatile Queue* key, u64 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontQueuePU64P(List *dataStructure, const volatile Queue* key, const volatile u64* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontQueueFloat(List *dataStructure, Queue key, float value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddFrontQueueFloatP(List *dataStructure, Queue key, const volatile float* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontQueuePFloat(List *dataStructure, const volatile Queue* key, float value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontQueuePFloatP(List *dataStructure, const volatile Queue* key, const volatile float* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontQueueDouble(List *dataStructure, Queue key, double value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddFrontQueueDoubleP(List *dataStructure, Queue key, const volatile double* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontQueuePDouble(List *dataStructure, const volatile Queue* key, double value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontQueuePDoubleP(List *dataStructure, const volatile Queue* key, const volatile double* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontQueueLongDouble(List *dataStructure, Queue key, long double value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontQueueLongDoubleP(List *dataStructure, Queue key, const volatile long double* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontQueuePLongDouble(List *dataStructure, const volatile Queue* key, long double value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontQueuePLongDoubleP(List *dataStructure, const volatile Queue* key, const volatile long double* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontQueueList(List *dataStructure, Queue key, List value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddFrontQueueListP(List *dataStructure, Queue key, const volatile List* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontQueuePList(List *dataStructure, const volatile Queue* key, List value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontQueuePListP(List *dataStructure, const volatile Queue* key, const volatile List* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontQueueQueue(List *dataStructure, Queue key, Queue value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddFrontQueueQueueP(List *dataStructure, Queue key, const volatile Queue* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontQueuePQueue(List *dataStructure, const volatile Queue* key, Queue value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontQueuePQueueP(List *dataStructure, const volatile Queue* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontQueueStack(List *dataStructure, Queue key, Stack value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddFrontQueueStackP(List *dataStructure, Queue key, const volatile Stack* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontQueuePStack(List *dataStructure, const volatile Queue* key, Stack value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontQueuePStackP(List *dataStructure, const volatile Queue* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontQueueRedBlackTree(List *dataStructure, Queue key, RedBlackTree value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontQueueRedBlackTreeP(List *dataStructure, Queue key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontQueuePRedBlackTree(List *dataStructure, const volatile Queue* key, RedBlackTree value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontQueuePRedBlackTreeP(List *dataStructure, const volatile Queue* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontQueueHashTable(List *dataStructure, Queue key, HashTable value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddFrontQueueHashTableP(List *dataStructure, Queue key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontQueuePHashTable(List *dataStructure, const volatile Queue* key, HashTable value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontQueuePHashTableP(List *dataStructure, const volatile Queue* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontQueueVector(List *dataStructure, Queue key, Vector value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddFrontQueueVectorP(List *dataStructure, Queue key, const volatile Vector* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontQueuePVector(List *dataStructure, const volatile Queue* key, Vector value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontQueuePVectorP(List *dataStructure, const volatile Queue* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontQueueString(List *dataStructure, Queue key, const volatile char* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddFrontQueueStringP(List *dataStructure, Queue key, const volatile char** value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontQueuePString(List *dataStructure, const volatile Queue* key, const volatile char* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontQueuePStringP(List *dataStructure, const volatile Queue* key, const volatile char** value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontQueueBytes(List *dataStructure, Queue key, Bytes value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddFrontQueueBytesP(List *dataStructure, Queue key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontQueuePBytes(List *dataStructure, const volatile Queue* key, Bytes value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontQueuePBytesP(List *dataStructure, const volatile Queue* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontQueuePointer(List *dataStructure, Queue key, void* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddFrontQueuePointerP(List *dataStructure, Queue key, const volatile void** value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontQueuePPointer(List *dataStructure, const volatile Queue* key, void* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontQueuePPointerP(List *dataStructure, const volatile Queue* key, const volatile void** value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontQueueI8(List *dataStructure, Queue key, i8 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddFrontQueuePI8(List *dataStructure, const volatile Queue* key, i8 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontQueueU8(List *dataStructure, Queue key, u8 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddFrontQueuePU8(List *dataStructure, const volatile Queue* key, u8 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddFrontStackBool(List *dataStructure, Stack key, bool value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddFrontStackBoolP(List *dataStructure, Stack key, const volatile bool* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontStackPBool(List *dataStructure, const volatile Stack* key, bool value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontStackPBoolP(List *dataStructure, const volatile Stack* key, const volatile bool* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontStackI16(List *dataStructure, Stack key, i16 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddFrontStackI16P(List *dataStructure, Stack key, const volatile i16* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontStackPI16(List *dataStructure, const volatile Stack* key, i16 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontStackPI16P(List *dataStructure, const volatile Stack* key, const volatile i16* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontStackU16(List *dataStructure, Stack key, u16 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddFrontStackU16P(List *dataStructure, Stack key, const volatile u16* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontStackPU16(List *dataStructure, const volatile Stack* key, u16 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontStackPU16P(List *dataStructure, const volatile Stack* key, const volatile u16* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontStackI32(List *dataStructure, Stack key, i32 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddFrontStackI32P(List *dataStructure, Stack key, const volatile i32* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontStackPI32(List *dataStructure, const volatile Stack* key, i32 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontStackPI32P(List *dataStructure, const volatile Stack* key, const volatile i32* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontStackU32(List *dataStructure, Stack key, u32 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddFrontStackU32P(List *dataStructure, Stack key, const volatile u32* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontStackPU32(List *dataStructure, const volatile Stack* key, u32 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontStackPU32P(List *dataStructure, const volatile Stack* key, const volatile u32* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontStackI64(List *dataStructure, Stack key, i64 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddFrontStackI64P(List *dataStructure, Stack key, const volatile i64* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontStackPI64(List *dataStructure, const volatile Stack* key, i64 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontStackPI64P(List *dataStructure, const volatile Stack* key, const volatile i64* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontStackU64(List *dataStructure, Stack key, u64 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddFrontStackU64P(List *dataStructure, Stack key, const volatile u64* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontStackPU64(List *dataStructure, const volatile Stack* key, u64 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontStackPU64P(List *dataStructure, const volatile Stack* key, const volatile u64* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontStackFloat(List *dataStructure, Stack key, float value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddFrontStackFloatP(List *dataStructure, Stack key, const volatile float* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontStackPFloat(List *dataStructure, const volatile Stack* key, float value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontStackPFloatP(List *dataStructure, const volatile Stack* key, const volatile float* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontStackDouble(List *dataStructure, Stack key, double value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddFrontStackDoubleP(List *dataStructure, Stack key, const volatile double* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontStackPDouble(List *dataStructure, const volatile Stack* key, double value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontStackPDoubleP(List *dataStructure, const volatile Stack* key, const volatile double* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontStackLongDouble(List *dataStructure, Stack key, long double value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontStackLongDoubleP(List *dataStructure, Stack key, const volatile long double* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontStackPLongDouble(List *dataStructure, const volatile Stack* key, long double value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontStackPLongDoubleP(List *dataStructure, const volatile Stack* key, const volatile long double* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontStackList(List *dataStructure, Stack key, List value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddFrontStackListP(List *dataStructure, Stack key, const volatile List* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontStackPList(List *dataStructure, const volatile Stack* key, List value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontStackPListP(List *dataStructure, const volatile Stack* key, const volatile List* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontStackQueue(List *dataStructure, Stack key, Queue value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddFrontStackQueueP(List *dataStructure, Stack key, const volatile Queue* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontStackPQueue(List *dataStructure, const volatile Stack* key, Queue value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontStackPQueueP(List *dataStructure, const volatile Stack* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontStackStack(List *dataStructure, Stack key, Stack value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddFrontStackStackP(List *dataStructure, Stack key, const volatile Stack* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontStackPStack(List *dataStructure, const volatile Stack* key, Stack value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontStackPStackP(List *dataStructure, const volatile Stack* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontStackRedBlackTree(List *dataStructure, Stack key, RedBlackTree value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontStackRedBlackTreeP(List *dataStructure, Stack key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontStackPRedBlackTree(List *dataStructure, const volatile Stack* key, RedBlackTree value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontStackPRedBlackTreeP(List *dataStructure, const volatile Stack* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontStackHashTable(List *dataStructure, Stack key, HashTable value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddFrontStackHashTableP(List *dataStructure, Stack key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontStackPHashTable(List *dataStructure, const volatile Stack* key, HashTable value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontStackPHashTableP(List *dataStructure, const volatile Stack* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontStackVector(List *dataStructure, Stack key, Vector value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddFrontStackVectorP(List *dataStructure, Stack key, const volatile Vector* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontStackPVector(List *dataStructure, const volatile Stack* key, Vector value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontStackPVectorP(List *dataStructure, const volatile Stack* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontStackString(List *dataStructure, Stack key, const volatile char* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddFrontStackStringP(List *dataStructure, Stack key, const volatile char** value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontStackPString(List *dataStructure, const volatile Stack* key, const volatile char* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontStackPStringP(List *dataStructure, const volatile Stack* key, const volatile char** value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontStackBytes(List *dataStructure, Stack key, Bytes value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddFrontStackBytesP(List *dataStructure, Stack key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontStackPBytes(List *dataStructure, const volatile Stack* key, Bytes value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontStackPBytesP(List *dataStructure, const volatile Stack* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontStackPointer(List *dataStructure, Stack key, void* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddFrontStackPointerP(List *dataStructure, Stack key, const volatile void** value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontStackPPointer(List *dataStructure, const volatile Stack* key, void* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontStackPPointerP(List *dataStructure, const volatile Stack* key, const volatile void** value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontStackI8(List *dataStructure, Stack key, i8 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddFrontStackPI8(List *dataStructure, const volatile Stack* key, i8 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontStackU8(List *dataStructure, Stack key, u8 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddFrontStackPU8(List *dataStructure, const volatile Stack* key, u8 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddFrontRedBlackTreeBool(List *dataStructure, RedBlackTree key, bool value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddFrontRedBlackTreeBoolP(List *dataStructure, RedBlackTree key, const volatile bool* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePBool(List *dataStructure, const volatile RedBlackTree* key, bool value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontRedBlackTreePBoolP(List *dataStructure, const volatile RedBlackTree* key, const volatile bool* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreeI16(List *dataStructure, RedBlackTree key, i16 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddFrontRedBlackTreeI16P(List *dataStructure, RedBlackTree key, const volatile i16* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePI16(List *dataStructure, const volatile RedBlackTree* key, i16 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontRedBlackTreePI16P(List *dataStructure, const volatile RedBlackTree* key, const volatile i16* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontRedBlackTreeU16(List *dataStructure, RedBlackTree key, u16 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddFrontRedBlackTreeU16P(List *dataStructure, RedBlackTree key, const volatile u16* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePU16(List *dataStructure, const volatile RedBlackTree* key, u16 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontRedBlackTreePU16P(List *dataStructure, const volatile RedBlackTree* key, const volatile u16* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontRedBlackTreeI32(List *dataStructure, RedBlackTree key, i32 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddFrontRedBlackTreeI32P(List *dataStructure, RedBlackTree key, const volatile i32* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePI32(List *dataStructure, const volatile RedBlackTree* key, i32 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontRedBlackTreePI32P(List *dataStructure, const volatile RedBlackTree* key, const volatile i32* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontRedBlackTreeU32(List *dataStructure, RedBlackTree key, u32 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddFrontRedBlackTreeU32P(List *dataStructure, RedBlackTree key, const volatile u32* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePU32(List *dataStructure, const volatile RedBlackTree* key, u32 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontRedBlackTreePU32P(List *dataStructure, const volatile RedBlackTree* key, const volatile u32* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontRedBlackTreeI64(List *dataStructure, RedBlackTree key, i64 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddFrontRedBlackTreeI64P(List *dataStructure, RedBlackTree key, const volatile i64* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePI64(List *dataStructure, const volatile RedBlackTree* key, i64 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontRedBlackTreePI64P(List *dataStructure, const volatile RedBlackTree* key, const volatile i64* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontRedBlackTreeU64(List *dataStructure, RedBlackTree key, u64 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddFrontRedBlackTreeU64P(List *dataStructure, RedBlackTree key, const volatile u64* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePU64(List *dataStructure, const volatile RedBlackTree* key, u64 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontRedBlackTreePU64P(List *dataStructure, const volatile RedBlackTree* key, const volatile u64* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontRedBlackTreeFloat(List *dataStructure, RedBlackTree key, float value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddFrontRedBlackTreeFloatP(List *dataStructure, RedBlackTree key, const volatile float* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePFloat(List *dataStructure, const volatile RedBlackTree* key, float value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontRedBlackTreePFloatP(List *dataStructure, const volatile RedBlackTree* key, const volatile float* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreeDouble(List *dataStructure, RedBlackTree key, double value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddFrontRedBlackTreeDoubleP(List *dataStructure, RedBlackTree key, const volatile double* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePDouble(List *dataStructure, const volatile RedBlackTree* key, double value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontRedBlackTreePDoubleP(List *dataStructure, const volatile RedBlackTree* key, const volatile double* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreeLongDouble(List *dataStructure, RedBlackTree key, long double value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontRedBlackTreeLongDoubleP(List *dataStructure, RedBlackTree key, const volatile long double* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePLongDouble(List *dataStructure, const volatile RedBlackTree* key, long double value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontRedBlackTreePLongDoubleP(List *dataStructure, const volatile RedBlackTree* key, const volatile long double* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreeList(List *dataStructure, RedBlackTree key, List value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddFrontRedBlackTreeListP(List *dataStructure, RedBlackTree key, const volatile List* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePList(List *dataStructure, const volatile RedBlackTree* key, List value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontRedBlackTreePListP(List *dataStructure, const volatile RedBlackTree* key, const volatile List* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreeQueue(List *dataStructure, RedBlackTree key, Queue value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddFrontRedBlackTreeQueueP(List *dataStructure, RedBlackTree key, const volatile Queue* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePQueue(List *dataStructure, const volatile RedBlackTree* key, Queue value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontRedBlackTreePQueueP(List *dataStructure, const volatile RedBlackTree* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreeStack(List *dataStructure, RedBlackTree key, Stack value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddFrontRedBlackTreeStackP(List *dataStructure, RedBlackTree key, const volatile Stack* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePStack(List *dataStructure, const volatile RedBlackTree* key, Stack value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontRedBlackTreePStackP(List *dataStructure, const volatile RedBlackTree* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreeRedBlackTree(List *dataStructure, RedBlackTree key, RedBlackTree value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontRedBlackTreeRedBlackTreeP(List *dataStructure, RedBlackTree key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePRedBlackTree(List *dataStructure, const volatile RedBlackTree* key, RedBlackTree value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontRedBlackTreePRedBlackTreeP(List *dataStructure, const volatile RedBlackTree* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreeHashTable(List *dataStructure, RedBlackTree key, HashTable value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddFrontRedBlackTreeHashTableP(List *dataStructure, RedBlackTree key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePHashTable(List *dataStructure, const volatile RedBlackTree* key, HashTable value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontRedBlackTreePHashTableP(List *dataStructure, const volatile RedBlackTree* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreeVector(List *dataStructure, RedBlackTree key, Vector value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddFrontRedBlackTreeVectorP(List *dataStructure, RedBlackTree key, const volatile Vector* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePVector(List *dataStructure, const volatile RedBlackTree* key, Vector value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontRedBlackTreePVectorP(List *dataStructure, const volatile RedBlackTree* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreeString(List *dataStructure, RedBlackTree key, const volatile char* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddFrontRedBlackTreeStringP(List *dataStructure, RedBlackTree key, const volatile char** value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePString(List *dataStructure, const volatile RedBlackTree* key, const volatile char* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontRedBlackTreePStringP(List *dataStructure, const volatile RedBlackTree* key, const volatile char** value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreeBytes(List *dataStructure, RedBlackTree key, Bytes value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddFrontRedBlackTreeBytesP(List *dataStructure, RedBlackTree key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePBytes(List *dataStructure, const volatile RedBlackTree* key, Bytes value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontRedBlackTreePBytesP(List *dataStructure, const volatile RedBlackTree* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePointer(List *dataStructure, RedBlackTree key, void* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddFrontRedBlackTreePointerP(List *dataStructure, RedBlackTree key, const volatile void** value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreePPointer(List *dataStructure, const volatile RedBlackTree* key, void* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontRedBlackTreePPointerP(List *dataStructure, const volatile RedBlackTree* key, const volatile void** value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontRedBlackTreeI8(List *dataStructure, RedBlackTree key, i8 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddFrontRedBlackTreePI8(List *dataStructure, const volatile RedBlackTree* key, i8 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontRedBlackTreeU8(List *dataStructure, RedBlackTree key, u8 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddFrontRedBlackTreePU8(List *dataStructure, const volatile RedBlackTree* key, u8 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddFrontHashTableBool(List *dataStructure, HashTable key, bool value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddFrontHashTableBoolP(List *dataStructure, HashTable key, const volatile bool* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontHashTablePBool(List *dataStructure, const volatile HashTable* key, bool value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontHashTablePBoolP(List *dataStructure, const volatile HashTable* key, const volatile bool* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontHashTableI16(List *dataStructure, HashTable key, i16 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddFrontHashTableI16P(List *dataStructure, HashTable key, const volatile i16* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontHashTablePI16(List *dataStructure, const volatile HashTable* key, i16 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontHashTablePI16P(List *dataStructure, const volatile HashTable* key, const volatile i16* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontHashTableU16(List *dataStructure, HashTable key, u16 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddFrontHashTableU16P(List *dataStructure, HashTable key, const volatile u16* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontHashTablePU16(List *dataStructure, const volatile HashTable* key, u16 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontHashTablePU16P(List *dataStructure, const volatile HashTable* key, const volatile u16* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontHashTableI32(List *dataStructure, HashTable key, i32 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddFrontHashTableI32P(List *dataStructure, HashTable key, const volatile i32* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontHashTablePI32(List *dataStructure, const volatile HashTable* key, i32 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontHashTablePI32P(List *dataStructure, const volatile HashTable* key, const volatile i32* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontHashTableU32(List *dataStructure, HashTable key, u32 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddFrontHashTableU32P(List *dataStructure, HashTable key, const volatile u32* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontHashTablePU32(List *dataStructure, const volatile HashTable* key, u32 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontHashTablePU32P(List *dataStructure, const volatile HashTable* key, const volatile u32* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontHashTableI64(List *dataStructure, HashTable key, i64 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddFrontHashTableI64P(List *dataStructure, HashTable key, const volatile i64* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontHashTablePI64(List *dataStructure, const volatile HashTable* key, i64 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontHashTablePI64P(List *dataStructure, const volatile HashTable* key, const volatile i64* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontHashTableU64(List *dataStructure, HashTable key, u64 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddFrontHashTableU64P(List *dataStructure, HashTable key, const volatile u64* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontHashTablePU64(List *dataStructure, const volatile HashTable* key, u64 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontHashTablePU64P(List *dataStructure, const volatile HashTable* key, const volatile u64* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontHashTableFloat(List *dataStructure, HashTable key, float value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddFrontHashTableFloatP(List *dataStructure, HashTable key, const volatile float* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontHashTablePFloat(List *dataStructure, const volatile HashTable* key, float value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontHashTablePFloatP(List *dataStructure, const volatile HashTable* key, const volatile float* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontHashTableDouble(List *dataStructure, HashTable key, double value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddFrontHashTableDoubleP(List *dataStructure, HashTable key, const volatile double* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontHashTablePDouble(List *dataStructure, const volatile HashTable* key, double value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontHashTablePDoubleP(List *dataStructure, const volatile HashTable* key, const volatile double* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontHashTableLongDouble(List *dataStructure, HashTable key, long double value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontHashTableLongDoubleP(List *dataStructure, HashTable key, const volatile long double* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontHashTablePLongDouble(List *dataStructure, const volatile HashTable* key, long double value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontHashTablePLongDoubleP(List *dataStructure, const volatile HashTable* key, const volatile long double* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontHashTableList(List *dataStructure, HashTable key, List value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddFrontHashTableListP(List *dataStructure, HashTable key, const volatile List* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontHashTablePList(List *dataStructure, const volatile HashTable* key, List value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontHashTablePListP(List *dataStructure, const volatile HashTable* key, const volatile List* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontHashTableQueue(List *dataStructure, HashTable key, Queue value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddFrontHashTableQueueP(List *dataStructure, HashTable key, const volatile Queue* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontHashTablePQueue(List *dataStructure, const volatile HashTable* key, Queue value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontHashTablePQueueP(List *dataStructure, const volatile HashTable* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontHashTableStack(List *dataStructure, HashTable key, Stack value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddFrontHashTableStackP(List *dataStructure, HashTable key, const volatile Stack* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontHashTablePStack(List *dataStructure, const volatile HashTable* key, Stack value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontHashTablePStackP(List *dataStructure, const volatile HashTable* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontHashTableRedBlackTree(List *dataStructure, HashTable key, RedBlackTree value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontHashTableRedBlackTreeP(List *dataStructure, HashTable key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontHashTablePRedBlackTree(List *dataStructure, const volatile HashTable* key, RedBlackTree value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontHashTablePRedBlackTreeP(List *dataStructure, const volatile HashTable* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontHashTableHashTable(List *dataStructure, HashTable key, HashTable value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddFrontHashTableHashTableP(List *dataStructure, HashTable key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontHashTablePHashTable(List *dataStructure, const volatile HashTable* key, HashTable value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontHashTablePHashTableP(List *dataStructure, const volatile HashTable* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontHashTableVector(List *dataStructure, HashTable key, Vector value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddFrontHashTableVectorP(List *dataStructure, HashTable key, const volatile Vector* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontHashTablePVector(List *dataStructure, const volatile HashTable* key, Vector value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontHashTablePVectorP(List *dataStructure, const volatile HashTable* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontHashTableString(List *dataStructure, HashTable key, const volatile char* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddFrontHashTableStringP(List *dataStructure, HashTable key, const volatile char** value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontHashTablePString(List *dataStructure, const volatile HashTable* key, const volatile char* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontHashTablePStringP(List *dataStructure, const volatile HashTable* key, const volatile char** value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontHashTableBytes(List *dataStructure, HashTable key, Bytes value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddFrontHashTableBytesP(List *dataStructure, HashTable key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontHashTablePBytes(List *dataStructure, const volatile HashTable* key, Bytes value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontHashTablePBytesP(List *dataStructure, const volatile HashTable* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontHashTablePointer(List *dataStructure, HashTable key, void* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddFrontHashTablePointerP(List *dataStructure, HashTable key, const volatile void** value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontHashTablePPointer(List *dataStructure, const volatile HashTable* key, void* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontHashTablePPointerP(List *dataStructure, const volatile HashTable* key, const volatile void** value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontHashTableI8(List *dataStructure, HashTable key, i8 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddFrontHashTablePI8(List *dataStructure, const volatile HashTable* key, i8 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontHashTableU8(List *dataStructure, HashTable key, u8 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddFrontHashTablePU8(List *dataStructure, const volatile HashTable* key, u8 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddFrontVectorBool(List *dataStructure, Vector key, bool value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddFrontVectorBoolP(List *dataStructure, Vector key, const volatile bool* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontVectorPBool(List *dataStructure, const volatile Vector* key, bool value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontVectorPBoolP(List *dataStructure, const volatile Vector* key, const volatile bool* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontVectorI16(List *dataStructure, Vector key, i16 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddFrontVectorI16P(List *dataStructure, Vector key, const volatile i16* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontVectorPI16(List *dataStructure, const volatile Vector* key, i16 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontVectorPI16P(List *dataStructure, const volatile Vector* key, const volatile i16* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontVectorU16(List *dataStructure, Vector key, u16 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddFrontVectorU16P(List *dataStructure, Vector key, const volatile u16* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontVectorPU16(List *dataStructure, const volatile Vector* key, u16 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontVectorPU16P(List *dataStructure, const volatile Vector* key, const volatile u16* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontVectorI32(List *dataStructure, Vector key, i32 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddFrontVectorI32P(List *dataStructure, Vector key, const volatile i32* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontVectorPI32(List *dataStructure, const volatile Vector* key, i32 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontVectorPI32P(List *dataStructure, const volatile Vector* key, const volatile i32* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontVectorU32(List *dataStructure, Vector key, u32 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddFrontVectorU32P(List *dataStructure, Vector key, const volatile u32* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontVectorPU32(List *dataStructure, const volatile Vector* key, u32 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontVectorPU32P(List *dataStructure, const volatile Vector* key, const volatile u32* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontVectorI64(List *dataStructure, Vector key, i64 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddFrontVectorI64P(List *dataStructure, Vector key, const volatile i64* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontVectorPI64(List *dataStructure, const volatile Vector* key, i64 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontVectorPI64P(List *dataStructure, const volatile Vector* key, const volatile i64* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontVectorU64(List *dataStructure, Vector key, u64 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddFrontVectorU64P(List *dataStructure, Vector key, const volatile u64* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontVectorPU64(List *dataStructure, const volatile Vector* key, u64 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontVectorPU64P(List *dataStructure, const volatile Vector* key, const volatile u64* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontVectorFloat(List *dataStructure, Vector key, float value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddFrontVectorFloatP(List *dataStructure, Vector key, const volatile float* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontVectorPFloat(List *dataStructure, const volatile Vector* key, float value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontVectorPFloatP(List *dataStructure, const volatile Vector* key, const volatile float* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontVectorDouble(List *dataStructure, Vector key, double value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddFrontVectorDoubleP(List *dataStructure, Vector key, const volatile double* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontVectorPDouble(List *dataStructure, const volatile Vector* key, double value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontVectorPDoubleP(List *dataStructure, const volatile Vector* key, const volatile double* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontVectorLongDouble(List *dataStructure, Vector key, long double value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontVectorLongDoubleP(List *dataStructure, Vector key, const volatile long double* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontVectorPLongDouble(List *dataStructure, const volatile Vector* key, long double value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontVectorPLongDoubleP(List *dataStructure, const volatile Vector* key, const volatile long double* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontVectorList(List *dataStructure, Vector key, List value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddFrontVectorListP(List *dataStructure, Vector key, const volatile List* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontVectorPList(List *dataStructure, const volatile Vector* key, List value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontVectorPListP(List *dataStructure, const volatile Vector* key, const volatile List* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontVectorQueue(List *dataStructure, Vector key, Queue value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddFrontVectorQueueP(List *dataStructure, Vector key, const volatile Queue* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontVectorPQueue(List *dataStructure, const volatile Vector* key, Queue value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontVectorPQueueP(List *dataStructure, const volatile Vector* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontVectorStack(List *dataStructure, Vector key, Stack value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddFrontVectorStackP(List *dataStructure, Vector key, const volatile Stack* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontVectorPStack(List *dataStructure, const volatile Vector* key, Stack value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontVectorPStackP(List *dataStructure, const volatile Vector* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontVectorRedBlackTree(List *dataStructure, Vector key, RedBlackTree value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontVectorRedBlackTreeP(List *dataStructure, Vector key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontVectorPRedBlackTree(List *dataStructure, const volatile Vector* key, RedBlackTree value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontVectorPRedBlackTreeP(List *dataStructure, const volatile Vector* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontVectorHashTable(List *dataStructure, Vector key, HashTable value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddFrontVectorHashTableP(List *dataStructure, Vector key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontVectorPHashTable(List *dataStructure, const volatile Vector* key, HashTable value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontVectorPHashTableP(List *dataStructure, const volatile Vector* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontVectorVector(List *dataStructure, Vector key, Vector value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddFrontVectorVectorP(List *dataStructure, Vector key, const volatile Vector* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontVectorPVector(List *dataStructure, const volatile Vector* key, Vector value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontVectorPVectorP(List *dataStructure, const volatile Vector* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontVectorString(List *dataStructure, Vector key, const volatile char* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddFrontVectorStringP(List *dataStructure, Vector key, const volatile char** value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontVectorPString(List *dataStructure, const volatile Vector* key, const volatile char* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontVectorPStringP(List *dataStructure, const volatile Vector* key, const volatile char** value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontVectorBytes(List *dataStructure, Vector key, Bytes value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddFrontVectorBytesP(List *dataStructure, Vector key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontVectorPBytes(List *dataStructure, const volatile Vector* key, Bytes value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontVectorPBytesP(List *dataStructure, const volatile Vector* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontVectorPointer(List *dataStructure, Vector key, void* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddFrontVectorPointerP(List *dataStructure, Vector key, const volatile void** value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontVectorPPointer(List *dataStructure, const volatile Vector* key, void* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontVectorPPointerP(List *dataStructure, const volatile Vector* key, const volatile void** value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontVectorI8(List *dataStructure, Vector key, i8 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddFrontVectorPI8(List *dataStructure, const volatile Vector* key, i8 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontVectorU8(List *dataStructure, Vector key, u8 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU8);
}
static inline ListNode* listAddFrontVectorPU8(List *dataStructure, const volatile Vector* key, u8 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}

static inline ListNode* listAddFrontStringBool(List *dataStructure, const volatile char* key, bool value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontStringBoolP(List *dataStructure, const volatile char* key, const volatile bool* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontStringPBool(List *dataStructure, const volatile char** key, bool value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeBool);
}
static inline ListNode* listAddFrontStringPBoolP(List *dataStructure, const volatile char** key, const volatile bool* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontStringI16(List *dataStructure, const volatile char* key, i16 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontStringI16P(List *dataStructure, const volatile char* key, const volatile i16* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontStringPI16(List *dataStructure, const volatile char** key, i16 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeI16);
}
static inline ListNode* listAddFrontStringPI16P(List *dataStructure, const volatile char** key, const volatile i16* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontStringU16(List *dataStructure, const volatile char* key, u16 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontStringU16P(List *dataStructure, const volatile char* key, const volatile u16* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontStringPU16(List *dataStructure, const volatile char** key, u16 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeU16);
}
static inline ListNode* listAddFrontStringPU16P(List *dataStructure, const volatile char** key, const volatile u16* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontStringI32(List *dataStructure, const volatile char* key, i32 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontStringI32P(List *dataStructure, const volatile char* key, const volatile i32* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontStringPI32(List *dataStructure, const volatile char** key, i32 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeI32);
}
static inline ListNode* listAddFrontStringPI32P(List *dataStructure, const volatile char** key, const volatile i32* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontStringU32(List *dataStructure, const volatile char* key, u32 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontStringU32P(List *dataStructure, const volatile char* key, const volatile u32* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontStringPU32(List *dataStructure, const volatile char** key, u32 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeU32);
}
static inline ListNode* listAddFrontStringPU32P(List *dataStructure, const volatile char** key, const volatile u32* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontStringI64(List *dataStructure, const volatile char* key, i64 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontStringI64P(List *dataStructure, const volatile char* key, const volatile i64* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontStringPI64(List *dataStructure, const volatile char** key, i64 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeI64);
}
static inline ListNode* listAddFrontStringPI64P(List *dataStructure, const volatile char** key, const volatile i64* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontStringU64(List *dataStructure, const volatile char* key, u64 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontStringU64P(List *dataStructure, const volatile char* key, const volatile u64* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontStringPU64(List *dataStructure, const volatile char** key, u64 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeU64);
}
static inline ListNode* listAddFrontStringPU64P(List *dataStructure, const volatile char** key, const volatile u64* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontStringFloat(List *dataStructure, const volatile char* key, float value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontStringFloatP(List *dataStructure, const volatile char* key, const volatile float* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontStringPFloat(List *dataStructure, const volatile char** key, float value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeFloat);
}
static inline ListNode* listAddFrontStringPFloatP(List *dataStructure, const volatile char** key, const volatile float* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontStringDouble(List *dataStructure, const volatile char* key, double value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontStringDoubleP(List *dataStructure, const volatile char* key, const volatile double* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontStringPDouble(List *dataStructure, const volatile char** key, double value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeDouble);
}
static inline ListNode* listAddFrontStringPDoubleP(List *dataStructure, const volatile char** key, const volatile double* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontStringLongDouble(List *dataStructure, const volatile char* key, long double value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontStringLongDoubleP(List *dataStructure, const volatile char* key, const volatile long double* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontStringPLongDouble(List *dataStructure, const volatile char** key, long double value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontStringPLongDoubleP(List *dataStructure, const volatile char** key, const volatile long double* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontStringList(List *dataStructure, const volatile char* key, List value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontStringListP(List *dataStructure, const volatile char* key, const volatile List* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontStringPList(List *dataStructure, const volatile char** key, List value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeList);
}
static inline ListNode* listAddFrontStringPListP(List *dataStructure, const volatile char** key, const volatile List* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontStringQueue(List *dataStructure, const volatile char* key, Queue value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontStringQueueP(List *dataStructure, const volatile char* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontStringPQueue(List *dataStructure, const volatile char** key, Queue value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeQueue);
}
static inline ListNode* listAddFrontStringPQueueP(List *dataStructure, const volatile char** key, const volatile Queue* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontStringStack(List *dataStructure, const volatile char* key, Stack value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontStringStackP(List *dataStructure, const volatile char* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontStringPStack(List *dataStructure, const volatile char** key, Stack value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeStack);
}
static inline ListNode* listAddFrontStringPStackP(List *dataStructure, const volatile char** key, const volatile Stack* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontStringRedBlackTree(List *dataStructure, const volatile char* key, RedBlackTree value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontStringRedBlackTreeP(List *dataStructure, const volatile char* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontStringPRedBlackTree(List *dataStructure, const volatile char** key, RedBlackTree value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontStringPRedBlackTreeP(List *dataStructure, const volatile char** key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontStringHashTable(List *dataStructure, const volatile char* key, HashTable value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontStringHashTableP(List *dataStructure, const volatile char* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontStringPHashTable(List *dataStructure, const volatile char** key, HashTable value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeHashTable);
}
static inline ListNode* listAddFrontStringPHashTableP(List *dataStructure, const volatile char** key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontStringVector(List *dataStructure, const volatile char* key, Vector value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontStringVectorP(List *dataStructure, const volatile char* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontStringPVector(List *dataStructure, const volatile char** key, Vector value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeVector);
}
static inline ListNode* listAddFrontStringPVectorP(List *dataStructure, const volatile char** key, const volatile Vector* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontStringString(List *dataStructure, const volatile char* key, const volatile char* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontStringStringP(List *dataStructure, const volatile char* key, const volatile char** value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontStringPString(List *dataStructure, const volatile char** key, const volatile char* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeString);
}
static inline ListNode* listAddFrontStringPStringP(List *dataStructure, const volatile char** key, const volatile char** value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontStringBytes(List *dataStructure, const volatile char* key, Bytes value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontStringBytesP(List *dataStructure, const volatile char* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontStringPBytes(List *dataStructure, const volatile char** key, Bytes value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeBytes);
}
static inline ListNode* listAddFrontStringPBytesP(List *dataStructure, const volatile char** key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontStringPointer(List *dataStructure, const volatile char* key, void* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontStringPointerP(List *dataStructure, const volatile char* key, const volatile void** value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontStringPPointer(List *dataStructure, const volatile char** key, void* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typePointer);
}
static inline ListNode* listAddFrontStringPPointerP(List *dataStructure, const volatile char** key, const volatile void** value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontStringI8(List *dataStructure, const volatile char* key, i8 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontStringPI8(List *dataStructure, const volatile char** key, i8 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeI8);
}
static inline ListNode* listAddFrontStringU8(List *dataStructure, const volatile char* key, u8 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddFrontStringPU8(List *dataStructure, const volatile char** key, u8 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeU8);
}

static inline ListNode* listAddFrontBytesBool(List *dataStructure, Bytes key, bool value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontBytesBoolP(List *dataStructure, Bytes key, const volatile bool* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontBytesPBool(List *dataStructure, const volatile Bytes* key, bool value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeBool);
}
static inline ListNode* listAddFrontBytesPBoolP(List *dataStructure, const volatile Bytes* key, const volatile bool* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontBytesI16(List *dataStructure, Bytes key, i16 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontBytesI16P(List *dataStructure, Bytes key, const volatile i16* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontBytesPI16(List *dataStructure, const volatile Bytes* key, i16 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeI16);
}
static inline ListNode* listAddFrontBytesPI16P(List *dataStructure, const volatile Bytes* key, const volatile i16* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontBytesU16(List *dataStructure, Bytes key, u16 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontBytesU16P(List *dataStructure, Bytes key, const volatile u16* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontBytesPU16(List *dataStructure, const volatile Bytes* key, u16 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeU16);
}
static inline ListNode* listAddFrontBytesPU16P(List *dataStructure, const volatile Bytes* key, const volatile u16* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontBytesI32(List *dataStructure, Bytes key, i32 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontBytesI32P(List *dataStructure, Bytes key, const volatile i32* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontBytesPI32(List *dataStructure, const volatile Bytes* key, i32 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeI32);
}
static inline ListNode* listAddFrontBytesPI32P(List *dataStructure, const volatile Bytes* key, const volatile i32* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontBytesU32(List *dataStructure, Bytes key, u32 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontBytesU32P(List *dataStructure, Bytes key, const volatile u32* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontBytesPU32(List *dataStructure, const volatile Bytes* key, u32 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeU32);
}
static inline ListNode* listAddFrontBytesPU32P(List *dataStructure, const volatile Bytes* key, const volatile u32* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontBytesI64(List *dataStructure, Bytes key, i64 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontBytesI64P(List *dataStructure, Bytes key, const volatile i64* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontBytesPI64(List *dataStructure, const volatile Bytes* key, i64 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeI64);
}
static inline ListNode* listAddFrontBytesPI64P(List *dataStructure, const volatile Bytes* key, const volatile i64* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontBytesU64(List *dataStructure, Bytes key, u64 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontBytesU64P(List *dataStructure, Bytes key, const volatile u64* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontBytesPU64(List *dataStructure, const volatile Bytes* key, u64 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeU64);
}
static inline ListNode* listAddFrontBytesPU64P(List *dataStructure, const volatile Bytes* key, const volatile u64* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontBytesFloat(List *dataStructure, Bytes key, float value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontBytesFloatP(List *dataStructure, Bytes key, const volatile float* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontBytesPFloat(List *dataStructure, const volatile Bytes* key, float value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeFloat);
}
static inline ListNode* listAddFrontBytesPFloatP(List *dataStructure, const volatile Bytes* key, const volatile float* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontBytesDouble(List *dataStructure, Bytes key, double value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontBytesDoubleP(List *dataStructure, Bytes key, const volatile double* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontBytesPDouble(List *dataStructure, const volatile Bytes* key, double value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeDouble);
}
static inline ListNode* listAddFrontBytesPDoubleP(List *dataStructure, const volatile Bytes* key, const volatile double* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontBytesLongDouble(List *dataStructure, Bytes key, long double value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontBytesLongDoubleP(List *dataStructure, Bytes key, const volatile long double* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontBytesPLongDouble(List *dataStructure, const volatile Bytes* key, long double value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontBytesPLongDoubleP(List *dataStructure, const volatile Bytes* key, const volatile long double* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontBytesList(List *dataStructure, Bytes key, List value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontBytesListP(List *dataStructure, Bytes key, const volatile List* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontBytesPList(List *dataStructure, const volatile Bytes* key, List value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeList);
}
static inline ListNode* listAddFrontBytesPListP(List *dataStructure, const volatile Bytes* key, const volatile List* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontBytesQueue(List *dataStructure, Bytes key, Queue value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontBytesQueueP(List *dataStructure, Bytes key, const volatile Queue* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontBytesPQueue(List *dataStructure, const volatile Bytes* key, Queue value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeQueue);
}
static inline ListNode* listAddFrontBytesPQueueP(List *dataStructure, const volatile Bytes* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontBytesStack(List *dataStructure, Bytes key, Stack value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontBytesStackP(List *dataStructure, Bytes key, const volatile Stack* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontBytesPStack(List *dataStructure, const volatile Bytes* key, Stack value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeStack);
}
static inline ListNode* listAddFrontBytesPStackP(List *dataStructure, const volatile Bytes* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontBytesRedBlackTree(List *dataStructure, Bytes key, RedBlackTree value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontBytesRedBlackTreeP(List *dataStructure, Bytes key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontBytesPRedBlackTree(List *dataStructure, const volatile Bytes* key, RedBlackTree value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontBytesPRedBlackTreeP(List *dataStructure, const volatile Bytes* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontBytesHashTable(List *dataStructure, Bytes key, HashTable value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontBytesHashTableP(List *dataStructure, Bytes key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontBytesPHashTable(List *dataStructure, const volatile Bytes* key, HashTable value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeHashTable);
}
static inline ListNode* listAddFrontBytesPHashTableP(List *dataStructure, const volatile Bytes* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontBytesVector(List *dataStructure, Bytes key, Vector value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontBytesVectorP(List *dataStructure, Bytes key, const volatile Vector* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontBytesPVector(List *dataStructure, const volatile Bytes* key, Vector value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeVector);
}
static inline ListNode* listAddFrontBytesPVectorP(List *dataStructure, const volatile Bytes* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontBytesString(List *dataStructure, Bytes key, const volatile char* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontBytesStringP(List *dataStructure, Bytes key, const volatile char** value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontBytesPString(List *dataStructure, const volatile Bytes* key, const volatile char* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeString);
}
static inline ListNode* listAddFrontBytesPStringP(List *dataStructure, const volatile Bytes* key, const volatile char** value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontBytesBytes(List *dataStructure, Bytes key, Bytes value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontBytesBytesP(List *dataStructure, Bytes key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontBytesPBytes(List *dataStructure, const volatile Bytes* key, Bytes value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeBytes);
}
static inline ListNode* listAddFrontBytesPBytesP(List *dataStructure, const volatile Bytes* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontBytesPointer(List *dataStructure, Bytes key, void* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontBytesPointerP(List *dataStructure, Bytes key, const volatile void** value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontBytesPPointer(List *dataStructure, const volatile Bytes* key, void* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typePointer);
}
static inline ListNode* listAddFrontBytesPPointerP(List *dataStructure, const volatile Bytes* key, const volatile void** value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontBytesI8(List *dataStructure, Bytes key, i8 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontBytesPI8(List *dataStructure, const volatile Bytes* key, i8 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeI8);
}
static inline ListNode* listAddFrontBytesU8(List *dataStructure, Bytes key, u8 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddFrontBytesPU8(List *dataStructure, const volatile Bytes* key, u8 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeU8);
}

static inline ListNode* listAddFrontPointerBool(List *dataStructure, void* key, bool value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeBool);
}
static inline ListNode* listAddFrontPointerBoolP(List *dataStructure, void* key, const volatile bool* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontPointerPBool(List *dataStructure, const volatile void** key, bool value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeBool);
}
static inline ListNode* listAddFrontPointerPBoolP(List *dataStructure, const volatile void** key, const volatile bool* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontPointerI16(List *dataStructure, void* key, i16 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI16);
}
static inline ListNode* listAddFrontPointerI16P(List *dataStructure, void* key, const volatile i16* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontPointerPI16(List *dataStructure, const volatile void** key, i16 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeI16);
}
static inline ListNode* listAddFrontPointerPI16P(List *dataStructure, const volatile void** key, const volatile i16* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontPointerU16(List *dataStructure, void* key, u16 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU16);
}
static inline ListNode* listAddFrontPointerU16P(List *dataStructure, void* key, const volatile u16* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontPointerPU16(List *dataStructure, const volatile void** key, u16 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeU16);
}
static inline ListNode* listAddFrontPointerPU16P(List *dataStructure, const volatile void** key, const volatile u16* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontPointerI32(List *dataStructure, void* key, i32 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI32);
}
static inline ListNode* listAddFrontPointerI32P(List *dataStructure, void* key, const volatile i32* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontPointerPI32(List *dataStructure, const volatile void** key, i32 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeI32);
}
static inline ListNode* listAddFrontPointerPI32P(List *dataStructure, const volatile void** key, const volatile i32* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontPointerU32(List *dataStructure, void* key, u32 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU32);
}
static inline ListNode* listAddFrontPointerU32P(List *dataStructure, void* key, const volatile u32* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontPointerPU32(List *dataStructure, const volatile void** key, u32 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeU32);
}
static inline ListNode* listAddFrontPointerPU32P(List *dataStructure, const volatile void** key, const volatile u32* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontPointerI64(List *dataStructure, void* key, i64 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI64);
}
static inline ListNode* listAddFrontPointerI64P(List *dataStructure, void* key, const volatile i64* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontPointerPI64(List *dataStructure, const volatile void** key, i64 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeI64);
}
static inline ListNode* listAddFrontPointerPI64P(List *dataStructure, const volatile void** key, const volatile i64* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontPointerU64(List *dataStructure, void* key, u64 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU64);
}
static inline ListNode* listAddFrontPointerU64P(List *dataStructure, void* key, const volatile u64* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontPointerPU64(List *dataStructure, const volatile void** key, u64 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeU64);
}
static inline ListNode* listAddFrontPointerPU64P(List *dataStructure, const volatile void** key, const volatile u64* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontPointerFloat(List *dataStructure, void* key, float value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeFloat);
}
static inline ListNode* listAddFrontPointerFloatP(List *dataStructure, void* key, const volatile float* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontPointerPFloat(List *dataStructure, const volatile void** key, float value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeFloat);
}
static inline ListNode* listAddFrontPointerPFloatP(List *dataStructure, const volatile void** key, const volatile float* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontPointerDouble(List *dataStructure, void* key, double value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeDouble);
}
static inline ListNode* listAddFrontPointerDoubleP(List *dataStructure, void* key, const volatile double* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontPointerPDouble(List *dataStructure, const volatile void** key, double value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeDouble);
}
static inline ListNode* listAddFrontPointerPDoubleP(List *dataStructure, const volatile void** key, const volatile double* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontPointerLongDouble(List *dataStructure, void* key, long double value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontPointerLongDoubleP(List *dataStructure, void* key, const volatile long double* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontPointerPLongDouble(List *dataStructure, const volatile void** key, long double value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontPointerPLongDoubleP(List *dataStructure, const volatile void** key, const volatile long double* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontPointerList(List *dataStructure, void* key, List value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeList);
}
static inline ListNode* listAddFrontPointerListP(List *dataStructure, void* key, const volatile List* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontPointerPList(List *dataStructure, const volatile void** key, List value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeList);
}
static inline ListNode* listAddFrontPointerPListP(List *dataStructure, const volatile void** key, const volatile List* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontPointerQueue(List *dataStructure, void* key, Queue value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeQueue);
}
static inline ListNode* listAddFrontPointerQueueP(List *dataStructure, void* key, const volatile Queue* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontPointerPQueue(List *dataStructure, const volatile void** key, Queue value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeQueue);
}
static inline ListNode* listAddFrontPointerPQueueP(List *dataStructure, const volatile void** key, const volatile Queue* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontPointerStack(List *dataStructure, void* key, Stack value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeStack);
}
static inline ListNode* listAddFrontPointerStackP(List *dataStructure, void* key, const volatile Stack* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontPointerPStack(List *dataStructure, const volatile void** key, Stack value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeStack);
}
static inline ListNode* listAddFrontPointerPStackP(List *dataStructure, const volatile void** key, const volatile Stack* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontPointerRedBlackTree(List *dataStructure, void* key, RedBlackTree value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontPointerRedBlackTreeP(List *dataStructure, void* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontPointerPRedBlackTree(List *dataStructure, const volatile void** key, RedBlackTree value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontPointerPRedBlackTreeP(List *dataStructure, const volatile void** key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontPointerHashTable(List *dataStructure, void* key, HashTable value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeHashTable);
}
static inline ListNode* listAddFrontPointerHashTableP(List *dataStructure, void* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontPointerPHashTable(List *dataStructure, const volatile void** key, HashTable value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeHashTable);
}
static inline ListNode* listAddFrontPointerPHashTableP(List *dataStructure, const volatile void** key, const volatile HashTable* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontPointerVector(List *dataStructure, void* key, Vector value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeVector);
}
static inline ListNode* listAddFrontPointerVectorP(List *dataStructure, void* key, const volatile Vector* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontPointerPVector(List *dataStructure, const volatile void** key, Vector value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeVector);
}
static inline ListNode* listAddFrontPointerPVectorP(List *dataStructure, const volatile void** key, const volatile Vector* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontPointerString(List *dataStructure, void* key, const volatile char* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeString);
}
static inline ListNode* listAddFrontPointerStringP(List *dataStructure, void* key, const volatile char** value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontPointerPString(List *dataStructure, const volatile void** key, const volatile char* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeString);
}
static inline ListNode* listAddFrontPointerPStringP(List *dataStructure, const volatile void** key, const volatile char** value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontPointerBytes(List *dataStructure, void* key, Bytes value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typeBytes);
}
static inline ListNode* listAddFrontPointerBytesP(List *dataStructure, void* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontPointerPBytes(List *dataStructure, const volatile void** key, Bytes value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typeBytes);
}
static inline ListNode* listAddFrontPointerPBytesP(List *dataStructure, const volatile void** key, const volatile Bytes* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontPointerPointer(List *dataStructure, void* key, void* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, value, typePointer);
}
static inline ListNode* listAddFrontPointerPointerP(List *dataStructure, void* key, const volatile void** value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontPointerPPointer(List *dataStructure, const volatile void** key, void* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, value, typePointer);
}
static inline ListNode* listAddFrontPointerPPointerP(List *dataStructure, const volatile void** key, const volatile void** value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontPointerI8(List *dataStructure, void* key, i8 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeI8);
}
static inline ListNode* listAddFrontPointerPI8(List *dataStructure, const volatile void** key, i8 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeI8);
}
static inline ListNode* listAddFrontPointerU8(List *dataStructure, void* key, u8 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, key, &value, typeU8);
}
static inline ListNode* listAddFrontPointerPU8(List *dataStructure, const volatile void** key, u8 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, *key, &value, typeU8);
}

static inline ListNode* listAddFrontI8Bool(List *dataStructure, i8 key, bool value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddFrontI8BoolP(List *dataStructure, i8 key, const volatile bool* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontI8I16(List *dataStructure, i8 key, i16 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddFrontI8I16P(List *dataStructure, i8 key, const volatile i16* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontI8U16(List *dataStructure, i8 key, u16 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddFrontI8U16P(List *dataStructure, i8 key, const volatile u16* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontI8I32(List *dataStructure, i8 key, i32 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddFrontI8I32P(List *dataStructure, i8 key, const volatile i32* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontI8U32(List *dataStructure, i8 key, u32 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddFrontI8U32P(List *dataStructure, i8 key, const volatile u32* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontI8I64(List *dataStructure, i8 key, i64 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddFrontI8I64P(List *dataStructure, i8 key, const volatile i64* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontI8U64(List *dataStructure, i8 key, u64 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddFrontI8U64P(List *dataStructure, i8 key, const volatile u64* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontI8Float(List *dataStructure, i8 key, float value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddFrontI8FloatP(List *dataStructure, i8 key, const volatile float* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontI8Double(List *dataStructure, i8 key, double value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddFrontI8DoubleP(List *dataStructure, i8 key, const volatile double* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontI8LongDouble(List *dataStructure, i8 key, long double value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontI8LongDoubleP(List *dataStructure, i8 key, const volatile long double* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontI8List(List *dataStructure, i8 key, List value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddFrontI8ListP(List *dataStructure, i8 key, const volatile List* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontI8Queue(List *dataStructure, i8 key, Queue value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddFrontI8QueueP(List *dataStructure, i8 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontI8Stack(List *dataStructure, i8 key, Stack value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddFrontI8StackP(List *dataStructure, i8 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontI8RedBlackTree(List *dataStructure, i8 key, RedBlackTree value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontI8RedBlackTreeP(List *dataStructure, i8 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontI8HashTable(List *dataStructure, i8 key, HashTable value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddFrontI8HashTableP(List *dataStructure, i8 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontI8Vector(List *dataStructure, i8 key, Vector value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddFrontI8VectorP(List *dataStructure, i8 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontI8String(List *dataStructure, i8 key, const volatile char* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddFrontI8StringP(List *dataStructure, i8 key, const volatile char** value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontI8Bytes(List *dataStructure, i8 key, Bytes value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddFrontI8BytesP(List *dataStructure, i8 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontI8Pointer(List *dataStructure, i8 key, void* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddFrontI8PointerP(List *dataStructure, i8 key, const volatile void** value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontI8I8(List *dataStructure, i8 key, i8 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddFrontI8U8(List *dataStructure, i8 key, u8 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU8);
}

static inline ListNode* listAddFrontU8Bool(List *dataStructure, u8 key, bool value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeBool);
}
static inline ListNode* listAddFrontU8BoolP(List *dataStructure, u8 key, const volatile bool* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline ListNode* listAddFrontU8I16(List *dataStructure, u8 key, i16 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI16);
}
static inline ListNode* listAddFrontU8I16P(List *dataStructure, u8 key, const volatile i16* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline ListNode* listAddFrontU8U16(List *dataStructure, u8 key, u16 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU16);
}
static inline ListNode* listAddFrontU8U16P(List *dataStructure, u8 key, const volatile u16* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline ListNode* listAddFrontU8I32(List *dataStructure, u8 key, i32 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI32);
}
static inline ListNode* listAddFrontU8I32P(List *dataStructure, u8 key, const volatile i32* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline ListNode* listAddFrontU8U32(List *dataStructure, u8 key, u32 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU32);
}
static inline ListNode* listAddFrontU8U32P(List *dataStructure, u8 key, const volatile u32* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline ListNode* listAddFrontU8I64(List *dataStructure, u8 key, i64 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI64);
}
static inline ListNode* listAddFrontU8I64P(List *dataStructure, u8 key, const volatile i64* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline ListNode* listAddFrontU8U64(List *dataStructure, u8 key, u64 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU64);
}
static inline ListNode* listAddFrontU8U64P(List *dataStructure, u8 key, const volatile u64* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline ListNode* listAddFrontU8Float(List *dataStructure, u8 key, float value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeFloat);
}
static inline ListNode* listAddFrontU8FloatP(List *dataStructure, u8 key, const volatile float* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline ListNode* listAddFrontU8Double(List *dataStructure, u8 key, double value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeDouble);
}
static inline ListNode* listAddFrontU8DoubleP(List *dataStructure, u8 key, const volatile double* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline ListNode* listAddFrontU8LongDouble(List *dataStructure, u8 key, long double value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline ListNode* listAddFrontU8LongDoubleP(List *dataStructure, u8 key, const volatile long double* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline ListNode* listAddFrontU8List(List *dataStructure, u8 key, List value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeList);
}
static inline ListNode* listAddFrontU8ListP(List *dataStructure, u8 key, const volatile List* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline ListNode* listAddFrontU8Queue(List *dataStructure, u8 key, Queue value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeQueue);
}
static inline ListNode* listAddFrontU8QueueP(List *dataStructure, u8 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline ListNode* listAddFrontU8Stack(List *dataStructure, u8 key, Stack value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeStack);
}
static inline ListNode* listAddFrontU8StackP(List *dataStructure, u8 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline ListNode* listAddFrontU8RedBlackTree(List *dataStructure, u8 key, RedBlackTree value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline ListNode* listAddFrontU8RedBlackTreeP(List *dataStructure, u8 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline ListNode* listAddFrontU8HashTable(List *dataStructure, u8 key, HashTable value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeHashTable);
}
static inline ListNode* listAddFrontU8HashTableP(List *dataStructure, u8 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline ListNode* listAddFrontU8Vector(List *dataStructure, u8 key, Vector value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeVector);
}
static inline ListNode* listAddFrontU8VectorP(List *dataStructure, u8 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline ListNode* listAddFrontU8String(List *dataStructure, u8 key, const volatile char* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeString);
}
static inline ListNode* listAddFrontU8StringP(List *dataStructure, u8 key, const volatile char** value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline ListNode* listAddFrontU8Bytes(List *dataStructure, u8 key, Bytes value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typeBytes);
}
static inline ListNode* listAddFrontU8BytesP(List *dataStructure, u8 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline ListNode* listAddFrontU8Pointer(List *dataStructure, u8 key, void* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, value, typePointer);
}
static inline ListNode* listAddFrontU8PointerP(List *dataStructure, u8 key, const volatile void** value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline ListNode* listAddFrontU8I8(List *dataStructure, u8 key, i8 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeI8);
}
static inline ListNode* listAddFrontU8U8(List *dataStructure, u8 key, u8 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return listAddFrontEntry(dataStructure, &key, &value, typeU8);
}

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#if defined __STDC_VERSION__

#if __STDC_VERSION__ >= 201710L
#define TYPE_SAFE_LIST

#define LIST_ADD_FRONT_GENERIC_CASES_BOOL_KEY(dataStructure, key, value) \
  bool:                  listAddFrontBoolBool,                       \
  bool*:                 listAddFrontBoolBoolP,                      \
  const volatile bool*:  listAddFrontBoolBoolP,                      \
  i16:                   listAddFrontBoolI16,                        \
  i16*:                  listAddFrontBoolI16P,                       \
  const volatile i16*:   listAddFrontBoolI16P,                       \
  u16:                   listAddFrontBoolU16,                        \
  u16*:                  listAddFrontBoolU16P,                       \
  const volatile u16*:   listAddFrontBoolU16P,                       \
  i32:                   listAddFrontBoolI32,                        \
  i32*:                  listAddFrontBoolI32P,                       \
  const volatile i32*:   listAddFrontBoolI32P,                       \
  u32:                   listAddFrontBoolU32,                        \
  u32*:                  listAddFrontBoolU32P,                       \
  const volatile u32*:   listAddFrontBoolU32P,                       \
  i64:                   listAddFrontBoolI64,                        \
  i64*:                  listAddFrontBoolI64P,                       \
  const volatile i64*:   listAddFrontBoolI64P,                       \
  u64:                   listAddFrontBoolU64,                        \
  u64*:                  listAddFrontBoolU64P,                       \
  const volatile u64*:   listAddFrontBoolU64P,                       \
  float:                 listAddFrontBoolFloat,                      \
  float*:                listAddFrontBoolFloatP,                     \
  const volatile float*: listAddFrontBoolFloatP,                     \
  double:                listAddFrontBoolDouble,                     \
  double*:               listAddFrontBoolDoubleP,                    \
  const volatile double*: listAddFrontBoolDoubleP,                    \
  long double:           listAddFrontBoolLongDouble,                 \
  long double*:          listAddFrontBoolLongDoubleP,                \
  const volatile long double*: listAddFrontBoolLongDoubleP,                \
  List:                  listAddFrontBoolList,                       \
  List*:                 listAddFrontBoolListP,                      \
  const volatile List*:  listAddFrontBoolListP,                      \
  Queue:                 listAddFrontBoolQueue,                      \
  Queue*:                listAddFrontBoolQueueP,                     \
  const volatile Queue*: listAddFrontBoolQueueP,                     \
  Stack:                 listAddFrontBoolStack,                      \
  Stack*:                listAddFrontBoolStackP,                     \
  const volatile Stack*: listAddFrontBoolStackP,                     \
  RedBlackTree:          listAddFrontBoolRedBlackTree,               \
  RedBlackTree*:         listAddFrontBoolRedBlackTreeP,              \
  const volatile RedBlackTree*: listAddFrontBoolRedBlackTreeP,              \
  HashTable:             listAddFrontBoolHashTable,                  \
  HashTable*:            listAddFrontBoolHashTableP,                 \
  const volatile HashTable*: listAddFrontBoolHashTableP,                 \
  Vector:                listAddFrontBoolVector,                     \
  Vector*:               listAddFrontBoolVectorP,                    \
  const volatile Vector*: listAddFrontBoolVectorP,                    \
  char*:                 listAddFrontBoolString,                     \
  const volatile char*:  listAddFrontBoolString,                     \
  char**:                listAddFrontBoolStringP,                    \
  const volatile char**: listAddFrontBoolStringP,                    \
  Bytes:                 listAddFrontBoolBytes,                      \
  Bytes*:                listAddFrontBoolBytesP,                     \
  const volatile Bytes*: listAddFrontBoolBytesP,                     \
  void*:                 listAddFrontBoolPointer,                    \
  void**:                listAddFrontBoolPointerP,                   \
  const volatile void**: listAddFrontBoolPointerP,                   \
  i8:                    listAddFrontBoolI8,                         \
  u8:                    listAddFrontBoolU8                          \

#define listAddFrontBool(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_BOOL_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_I16_KEY(dataStructure, key, value) \
  bool:                  listAddFrontI16Bool,                        \
  bool*:                 listAddFrontI16BoolP,                       \
  const volatile bool*:  listAddFrontI16BoolP,                       \
  i16:                   listAddFrontI16I16,                         \
  i16*:                  listAddFrontI16I16P,                        \
  const volatile i16*:   listAddFrontI16I16P,                        \
  u16:                   listAddFrontI16U16,                         \
  u16*:                  listAddFrontI16U16P,                        \
  const volatile u16*:   listAddFrontI16U16P,                        \
  i32:                   listAddFrontI16I32,                         \
  i32*:                  listAddFrontI16I32P,                        \
  const volatile i32*:   listAddFrontI16I32P,                        \
  u32:                   listAddFrontI16U32,                         \
  u32*:                  listAddFrontI16U32P,                        \
  const volatile u32*:   listAddFrontI16U32P,                        \
  i64:                   listAddFrontI16I64,                         \
  i64*:                  listAddFrontI16I64P,                        \
  const volatile i64*:   listAddFrontI16I64P,                        \
  u64:                   listAddFrontI16U64,                         \
  u64*:                  listAddFrontI16U64P,                        \
  const volatile u64*:   listAddFrontI16U64P,                        \
  float:                 listAddFrontI16Float,                       \
  float*:                listAddFrontI16FloatP,                      \
  const volatile float*: listAddFrontI16FloatP,                      \
  double:                listAddFrontI16Double,                      \
  double*:               listAddFrontI16DoubleP,                     \
  const volatile double*: listAddFrontI16DoubleP,                     \
  long double:           listAddFrontI16LongDouble,                  \
  long double*:          listAddFrontI16LongDoubleP,                 \
  const volatile long double*: listAddFrontI16LongDoubleP,                 \
  List:                  listAddFrontI16List,                        \
  List*:                 listAddFrontI16ListP,                       \
  const volatile List*:  listAddFrontI16ListP,                       \
  Queue:                 listAddFrontI16Queue,                       \
  Queue*:                listAddFrontI16QueueP,                      \
  const volatile Queue*: listAddFrontI16QueueP,                      \
  Stack:                 listAddFrontI16Stack,                       \
  Stack*:                listAddFrontI16StackP,                      \
  const volatile Stack*: listAddFrontI16StackP,                      \
  RedBlackTree:          listAddFrontI16RedBlackTree,                \
  RedBlackTree*:         listAddFrontI16RedBlackTreeP,               \
  const volatile RedBlackTree*: listAddFrontI16RedBlackTreeP,               \
  HashTable:             listAddFrontI16HashTable,                   \
  HashTable*:            listAddFrontI16HashTableP,                  \
  const volatile HashTable*: listAddFrontI16HashTableP,                  \
  Vector:                listAddFrontI16Vector,                      \
  Vector*:               listAddFrontI16VectorP,                     \
  const volatile Vector*: listAddFrontI16VectorP,                     \
  char*:                 listAddFrontI16String,                      \
  const volatile char*:  listAddFrontI16String,                      \
  char**:                listAddFrontI16StringP,                     \
  const volatile char**: listAddFrontI16StringP,                     \
  Bytes:                 listAddFrontI16Bytes,                       \
  Bytes*:                listAddFrontI16BytesP,                      \
  const volatile Bytes*: listAddFrontI16BytesP,                      \
  void*:                 listAddFrontI16Pointer,                     \
  void**:                listAddFrontI16PointerP,                    \
  const volatile void**: listAddFrontI16PointerP,                    \
  i8:                    listAddFrontI16I8,                          \
  u8:                    listAddFrontI16U8                           \

#define listAddFrontI16(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_I16_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_U16_KEY(dataStructure, key, value) \
  bool:                  listAddFrontU16Bool,                        \
  bool*:                 listAddFrontU16BoolP,                       \
  const volatile bool*:  listAddFrontU16BoolP,                       \
  i16:                   listAddFrontU16I16,                         \
  i16*:                  listAddFrontU16I16P,                        \
  const volatile i16*:   listAddFrontU16I16P,                        \
  u16:                   listAddFrontU16U16,                         \
  u16*:                  listAddFrontU16U16P,                        \
  const volatile u16*:   listAddFrontU16U16P,                        \
  i32:                   listAddFrontU16I32,                         \
  i32*:                  listAddFrontU16I32P,                        \
  const volatile i32*:   listAddFrontU16I32P,                        \
  u32:                   listAddFrontU16U32,                         \
  u32*:                  listAddFrontU16U32P,                        \
  const volatile u32*:   listAddFrontU16U32P,                        \
  i64:                   listAddFrontU16I64,                         \
  i64*:                  listAddFrontU16I64P,                        \
  const volatile i64*:   listAddFrontU16I64P,                        \
  u64:                   listAddFrontU16U64,                         \
  u64*:                  listAddFrontU16U64P,                        \
  const volatile u64*:   listAddFrontU16U64P,                        \
  float:                 listAddFrontU16Float,                       \
  float*:                listAddFrontU16FloatP,                      \
  const volatile float*: listAddFrontU16FloatP,                      \
  double:                listAddFrontU16Double,                      \
  double*:               listAddFrontU16DoubleP,                     \
  const volatile double*: listAddFrontU16DoubleP,                     \
  long double:           listAddFrontU16LongDouble,                  \
  long double*:          listAddFrontU16LongDoubleP,                 \
  const volatile long double*: listAddFrontU16LongDoubleP,                 \
  List:                  listAddFrontU16List,                        \
  List*:                 listAddFrontU16ListP,                       \
  const volatile List*:  listAddFrontU16ListP,                       \
  Queue:                 listAddFrontU16Queue,                       \
  Queue*:                listAddFrontU16QueueP,                      \
  const volatile Queue*: listAddFrontU16QueueP,                      \
  Stack:                 listAddFrontU16Stack,                       \
  Stack*:                listAddFrontU16StackP,                      \
  const volatile Stack*: listAddFrontU16StackP,                      \
  RedBlackTree:          listAddFrontU16RedBlackTree,                \
  RedBlackTree*:         listAddFrontU16RedBlackTreeP,               \
  const volatile RedBlackTree*: listAddFrontU16RedBlackTreeP,               \
  HashTable:             listAddFrontU16HashTable,                   \
  HashTable*:            listAddFrontU16HashTableP,                  \
  const volatile HashTable*: listAddFrontU16HashTableP,                  \
  Vector:                listAddFrontU16Vector,                      \
  Vector*:               listAddFrontU16VectorP,                     \
  const volatile Vector*: listAddFrontU16VectorP,                     \
  char*:                 listAddFrontU16String,                      \
  const volatile char*:  listAddFrontU16String,                      \
  char**:                listAddFrontU16StringP,                     \
  const volatile char**: listAddFrontU16StringP,                     \
  Bytes:                 listAddFrontU16Bytes,                       \
  Bytes*:                listAddFrontU16BytesP,                      \
  const volatile Bytes*: listAddFrontU16BytesP,                      \
  void*:                 listAddFrontU16Pointer,                     \
  void**:                listAddFrontU16PointerP,                    \
  const volatile void**: listAddFrontU16PointerP,                    \
  i8:                    listAddFrontU16I8,                          \
  u8:                    listAddFrontU16U8                           \

#define listAddFrontU16(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_U16_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_I32_KEY(dataStructure, key, value) \
  bool:                  listAddFrontI32Bool,                        \
  bool*:                 listAddFrontI32BoolP,                       \
  const volatile bool*:  listAddFrontI32BoolP,                       \
  i16:                   listAddFrontI32I16,                         \
  i16*:                  listAddFrontI32I16P,                        \
  const volatile i16*:   listAddFrontI32I16P,                        \
  u16:                   listAddFrontI32U16,                         \
  u16*:                  listAddFrontI32U16P,                        \
  const volatile u16*:   listAddFrontI32U16P,                        \
  i32:                   listAddFrontI32I32,                         \
  i32*:                  listAddFrontI32I32P,                        \
  const volatile i32*:   listAddFrontI32I32P,                        \
  u32:                   listAddFrontI32U32,                         \
  u32*:                  listAddFrontI32U32P,                        \
  const volatile u32*:   listAddFrontI32U32P,                        \
  i64:                   listAddFrontI32I64,                         \
  i64*:                  listAddFrontI32I64P,                        \
  const volatile i64*:   listAddFrontI32I64P,                        \
  u64:                   listAddFrontI32U64,                         \
  u64*:                  listAddFrontI32U64P,                        \
  const volatile u64*:   listAddFrontI32U64P,                        \
  float:                 listAddFrontI32Float,                       \
  float*:                listAddFrontI32FloatP,                      \
  const volatile float*: listAddFrontI32FloatP,                      \
  double:                listAddFrontI32Double,                      \
  double*:               listAddFrontI32DoubleP,                     \
  const volatile double*: listAddFrontI32DoubleP,                     \
  long double:           listAddFrontI32LongDouble,                  \
  long double*:          listAddFrontI32LongDoubleP,                 \
  const volatile long double*: listAddFrontI32LongDoubleP,                 \
  List:                  listAddFrontI32List,                        \
  List*:                 listAddFrontI32ListP,                       \
  const volatile List*:  listAddFrontI32ListP,                       \
  Queue:                 listAddFrontI32Queue,                       \
  Queue*:                listAddFrontI32QueueP,                      \
  const volatile Queue*: listAddFrontI32QueueP,                      \
  Stack:                 listAddFrontI32Stack,                       \
  Stack*:                listAddFrontI32StackP,                      \
  const volatile Stack*: listAddFrontI32StackP,                      \
  RedBlackTree:          listAddFrontI32RedBlackTree,                \
  RedBlackTree*:         listAddFrontI32RedBlackTreeP,               \
  const volatile RedBlackTree*: listAddFrontI32RedBlackTreeP,               \
  HashTable:             listAddFrontI32HashTable,                   \
  HashTable*:            listAddFrontI32HashTableP,                  \
  const volatile HashTable*: listAddFrontI32HashTableP,                  \
  Vector:                listAddFrontI32Vector,                      \
  Vector*:               listAddFrontI32VectorP,                     \
  const volatile Vector*: listAddFrontI32VectorP,                     \
  char*:                 listAddFrontI32String,                      \
  const volatile char*:  listAddFrontI32String,                      \
  char**:                listAddFrontI32StringP,                     \
  const volatile char**: listAddFrontI32StringP,                     \
  Bytes:                 listAddFrontI32Bytes,                       \
  Bytes*:                listAddFrontI32BytesP,                      \
  const volatile Bytes*: listAddFrontI32BytesP,                      \
  void*:                 listAddFrontI32Pointer,                     \
  void**:                listAddFrontI32PointerP,                    \
  const volatile void**: listAddFrontI32PointerP,                    \
  i8:                    listAddFrontI32I8,                          \
  u8:                    listAddFrontI32U8                           \

#define listAddFrontI32(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_I32_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_U32_KEY(dataStructure, key, value) \
  bool:                  listAddFrontU32Bool,                        \
  bool*:                 listAddFrontU32BoolP,                       \
  const volatile bool*:  listAddFrontU32BoolP,                       \
  i16:                   listAddFrontU32I16,                         \
  i16*:                  listAddFrontU32I16P,                        \
  const volatile i16*:   listAddFrontU32I16P,                        \
  u16:                   listAddFrontU32U16,                         \
  u16*:                  listAddFrontU32U16P,                        \
  const volatile u16*:   listAddFrontU32U16P,                        \
  i32:                   listAddFrontU32I32,                         \
  i32*:                  listAddFrontU32I32P,                        \
  const volatile i32*:   listAddFrontU32I32P,                        \
  u32:                   listAddFrontU32U32,                         \
  u32*:                  listAddFrontU32U32P,                        \
  const volatile u32*:   listAddFrontU32U32P,                        \
  i64:                   listAddFrontU32I64,                         \
  i64*:                  listAddFrontU32I64P,                        \
  const volatile i64*:   listAddFrontU32I64P,                        \
  u64:                   listAddFrontU32U64,                         \
  u64*:                  listAddFrontU32U64P,                        \
  const volatile u64*:   listAddFrontU32U64P,                        \
  float:                 listAddFrontU32Float,                       \
  float*:                listAddFrontU32FloatP,                      \
  const volatile float*: listAddFrontU32FloatP,                      \
  double:                listAddFrontU32Double,                      \
  double*:               listAddFrontU32DoubleP,                     \
  const volatile double*: listAddFrontU32DoubleP,                     \
  long double:           listAddFrontU32LongDouble,                  \
  long double*:          listAddFrontU32LongDoubleP,                 \
  const volatile long double*: listAddFrontU32LongDoubleP,                 \
  List:                  listAddFrontU32List,                        \
  List*:                 listAddFrontU32ListP,                       \
  const volatile List*:  listAddFrontU32ListP,                       \
  Queue:                 listAddFrontU32Queue,                       \
  Queue*:                listAddFrontU32QueueP,                      \
  const volatile Queue*: listAddFrontU32QueueP,                      \
  Stack:                 listAddFrontU32Stack,                       \
  Stack*:                listAddFrontU32StackP,                      \
  const volatile Stack*: listAddFrontU32StackP,                      \
  RedBlackTree:          listAddFrontU32RedBlackTree,                \
  RedBlackTree*:         listAddFrontU32RedBlackTreeP,               \
  const volatile RedBlackTree*: listAddFrontU32RedBlackTreeP,               \
  HashTable:             listAddFrontU32HashTable,                   \
  HashTable*:            listAddFrontU32HashTableP,                  \
  const volatile HashTable*: listAddFrontU32HashTableP,                  \
  Vector:                listAddFrontU32Vector,                      \
  Vector*:               listAddFrontU32VectorP,                     \
  const volatile Vector*: listAddFrontU32VectorP,                     \
  char*:                 listAddFrontU32String,                      \
  const volatile char*:  listAddFrontU32String,                      \
  char**:                listAddFrontU32StringP,                     \
  const volatile char**: listAddFrontU32StringP,                     \
  Bytes:                 listAddFrontU32Bytes,                       \
  Bytes*:                listAddFrontU32BytesP,                      \
  const volatile Bytes*: listAddFrontU32BytesP,                      \
  void*:                 listAddFrontU32Pointer,                     \
  void**:                listAddFrontU32PointerP,                    \
  const volatile void**: listAddFrontU32PointerP,                    \
  i8:                    listAddFrontU32I8,                          \
  u8:                    listAddFrontU32U8                           \

#define listAddFrontU32(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_U32_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_I64_KEY(dataStructure, key, value) \
  bool:                  listAddFrontI64Bool,                        \
  bool*:                 listAddFrontI64BoolP,                       \
  const volatile bool*:  listAddFrontI64BoolP,                       \
  i16:                   listAddFrontI64I16,                         \
  i16*:                  listAddFrontI64I16P,                        \
  const volatile i16*:   listAddFrontI64I16P,                        \
  u16:                   listAddFrontI64U16,                         \
  u16*:                  listAddFrontI64U16P,                        \
  const volatile u16*:   listAddFrontI64U16P,                        \
  i32:                   listAddFrontI64I32,                         \
  i32*:                  listAddFrontI64I32P,                        \
  const volatile i32*:   listAddFrontI64I32P,                        \
  u32:                   listAddFrontI64U32,                         \
  u32*:                  listAddFrontI64U32P,                        \
  const volatile u32*:   listAddFrontI64U32P,                        \
  i64:                   listAddFrontI64I64,                         \
  i64*:                  listAddFrontI64I64P,                        \
  const volatile i64*:   listAddFrontI64I64P,                        \
  u64:                   listAddFrontI64U64,                         \
  u64*:                  listAddFrontI64U64P,                        \
  const volatile u64*:   listAddFrontI64U64P,                        \
  float:                 listAddFrontI64Float,                       \
  float*:                listAddFrontI64FloatP,                      \
  const volatile float*: listAddFrontI64FloatP,                      \
  double:                listAddFrontI64Double,                      \
  double*:               listAddFrontI64DoubleP,                     \
  const volatile double*: listAddFrontI64DoubleP,                     \
  long double:           listAddFrontI64LongDouble,                  \
  long double*:          listAddFrontI64LongDoubleP,                 \
  const volatile long double*: listAddFrontI64LongDoubleP,                 \
  List:                  listAddFrontI64List,                        \
  List*:                 listAddFrontI64ListP,                       \
  const volatile List*:  listAddFrontI64ListP,                       \
  Queue:                 listAddFrontI64Queue,                       \
  Queue*:                listAddFrontI64QueueP,                      \
  const volatile Queue*: listAddFrontI64QueueP,                      \
  Stack:                 listAddFrontI64Stack,                       \
  Stack*:                listAddFrontI64StackP,                      \
  const volatile Stack*: listAddFrontI64StackP,                      \
  RedBlackTree:          listAddFrontI64RedBlackTree,                \
  RedBlackTree*:         listAddFrontI64RedBlackTreeP,               \
  const volatile RedBlackTree*: listAddFrontI64RedBlackTreeP,               \
  HashTable:             listAddFrontI64HashTable,                   \
  HashTable*:            listAddFrontI64HashTableP,                  \
  const volatile HashTable*: listAddFrontI64HashTableP,                  \
  Vector:                listAddFrontI64Vector,                      \
  Vector*:               listAddFrontI64VectorP,                     \
  const volatile Vector*: listAddFrontI64VectorP,                     \
  char*:                 listAddFrontI64String,                      \
  const volatile char*:  listAddFrontI64String,                      \
  char**:                listAddFrontI64StringP,                     \
  const volatile char**: listAddFrontI64StringP,                     \
  Bytes:                 listAddFrontI64Bytes,                       \
  Bytes*:                listAddFrontI64BytesP,                      \
  const volatile Bytes*: listAddFrontI64BytesP,                      \
  void*:                 listAddFrontI64Pointer,                     \
  void**:                listAddFrontI64PointerP,                    \
  const volatile void**: listAddFrontI64PointerP,                    \
  i8:                    listAddFrontI64I8,                          \
  u8:                    listAddFrontI64U8                           \

#define listAddFrontI64(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_I64_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_U64_KEY(dataStructure, key, value) \
  bool:                  listAddFrontU64Bool,                        \
  bool*:                 listAddFrontU64BoolP,                       \
  const volatile bool*:  listAddFrontU64BoolP,                       \
  i16:                   listAddFrontU64I16,                         \
  i16*:                  listAddFrontU64I16P,                        \
  const volatile i16*:   listAddFrontU64I16P,                        \
  u16:                   listAddFrontU64U16,                         \
  u16*:                  listAddFrontU64U16P,                        \
  const volatile u16*:   listAddFrontU64U16P,                        \
  i32:                   listAddFrontU64I32,                         \
  i32*:                  listAddFrontU64I32P,                        \
  const volatile i32*:   listAddFrontU64I32P,                        \
  u32:                   listAddFrontU64U32,                         \
  u32*:                  listAddFrontU64U32P,                        \
  const volatile u32*:   listAddFrontU64U32P,                        \
  i64:                   listAddFrontU64I64,                         \
  i64*:                  listAddFrontU64I64P,                        \
  const volatile i64*:   listAddFrontU64I64P,                        \
  u64:                   listAddFrontU64U64,                         \
  u64*:                  listAddFrontU64U64P,                        \
  const volatile u64*:   listAddFrontU64U64P,                        \
  float:                 listAddFrontU64Float,                       \
  float*:                listAddFrontU64FloatP,                      \
  const volatile float*: listAddFrontU64FloatP,                      \
  double:                listAddFrontU64Double,                      \
  double*:               listAddFrontU64DoubleP,                     \
  const volatile double*: listAddFrontU64DoubleP,                     \
  long double:           listAddFrontU64LongDouble,                  \
  long double*:          listAddFrontU64LongDoubleP,                 \
  const volatile long double*: listAddFrontU64LongDoubleP,                 \
  List:                  listAddFrontU64List,                        \
  List*:                 listAddFrontU64ListP,                       \
  const volatile List*:  listAddFrontU64ListP,                       \
  Queue:                 listAddFrontU64Queue,                       \
  Queue*:                listAddFrontU64QueueP,                      \
  const volatile Queue*: listAddFrontU64QueueP,                      \
  Stack:                 listAddFrontU64Stack,                       \
  Stack*:                listAddFrontU64StackP,                      \
  const volatile Stack*: listAddFrontU64StackP,                      \
  RedBlackTree:          listAddFrontU64RedBlackTree,                \
  RedBlackTree*:         listAddFrontU64RedBlackTreeP,               \
  const volatile RedBlackTree*: listAddFrontU64RedBlackTreeP,               \
  HashTable:             listAddFrontU64HashTable,                   \
  HashTable*:            listAddFrontU64HashTableP,                  \
  const volatile HashTable*: listAddFrontU64HashTableP,                  \
  Vector:                listAddFrontU64Vector,                      \
  Vector*:               listAddFrontU64VectorP,                     \
  const volatile Vector*: listAddFrontU64VectorP,                     \
  char*:                 listAddFrontU64String,                      \
  const volatile char*:  listAddFrontU64String,                      \
  char**:                listAddFrontU64StringP,                     \
  const volatile char**: listAddFrontU64StringP,                     \
  Bytes:                 listAddFrontU64Bytes,                       \
  Bytes*:                listAddFrontU64BytesP,                      \
  const volatile Bytes*: listAddFrontU64BytesP,                      \
  void*:                 listAddFrontU64Pointer,                     \
  void**:                listAddFrontU64PointerP,                    \
  const volatile void**: listAddFrontU64PointerP,                    \
  i8:                    listAddFrontU64I8,                          \
  u8:                    listAddFrontU64U8                           \

#define listAddFrontU64(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_U64_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_FLOAT_KEY(dataStructure, key, value) \
  bool:                  listAddFrontFloatBool,                      \
  bool*:                 listAddFrontFloatBoolP,                     \
  const volatile bool*:  listAddFrontFloatBoolP,                     \
  i16:                   listAddFrontFloatI16,                       \
  i16*:                  listAddFrontFloatI16P,                      \
  const volatile i16*:   listAddFrontFloatI16P,                      \
  u16:                   listAddFrontFloatU16,                       \
  u16*:                  listAddFrontFloatU16P,                      \
  const volatile u16*:   listAddFrontFloatU16P,                      \
  i32:                   listAddFrontFloatI32,                       \
  i32*:                  listAddFrontFloatI32P,                      \
  const volatile i32*:   listAddFrontFloatI32P,                      \
  u32:                   listAddFrontFloatU32,                       \
  u32*:                  listAddFrontFloatU32P,                      \
  const volatile u32*:   listAddFrontFloatU32P,                      \
  i64:                   listAddFrontFloatI64,                       \
  i64*:                  listAddFrontFloatI64P,                      \
  const volatile i64*:   listAddFrontFloatI64P,                      \
  u64:                   listAddFrontFloatU64,                       \
  u64*:                  listAddFrontFloatU64P,                      \
  const volatile u64*:   listAddFrontFloatU64P,                      \
  float:                 listAddFrontFloatFloat,                     \
  float*:                listAddFrontFloatFloatP,                    \
  const volatile float*: listAddFrontFloatFloatP,                    \
  double:                listAddFrontFloatDouble,                    \
  double*:               listAddFrontFloatDoubleP,                   \
  const volatile double*: listAddFrontFloatDoubleP,                   \
  long double:           listAddFrontFloatLongDouble,                \
  long double*:          listAddFrontFloatLongDoubleP,               \
  const volatile long double*: listAddFrontFloatLongDoubleP,               \
  List:                  listAddFrontFloatList,                      \
  List*:                 listAddFrontFloatListP,                     \
  const volatile List*:  listAddFrontFloatListP,                     \
  Queue:                 listAddFrontFloatQueue,                     \
  Queue*:                listAddFrontFloatQueueP,                    \
  const volatile Queue*: listAddFrontFloatQueueP,                    \
  Stack:                 listAddFrontFloatStack,                     \
  Stack*:                listAddFrontFloatStackP,                    \
  const volatile Stack*: listAddFrontFloatStackP,                    \
  RedBlackTree:          listAddFrontFloatRedBlackTree,              \
  RedBlackTree*:         listAddFrontFloatRedBlackTreeP,             \
  const volatile RedBlackTree*: listAddFrontFloatRedBlackTreeP,             \
  HashTable:             listAddFrontFloatHashTable,                 \
  HashTable*:            listAddFrontFloatHashTableP,                \
  const volatile HashTable*: listAddFrontFloatHashTableP,                \
  Vector:                listAddFrontFloatVector,                    \
  Vector*:               listAddFrontFloatVectorP,                   \
  const volatile Vector*: listAddFrontFloatVectorP,                   \
  char*:                 listAddFrontFloatString,                    \
  const volatile char*:  listAddFrontFloatString,                    \
  char**:                listAddFrontFloatStringP,                   \
  const volatile char**: listAddFrontFloatStringP,                   \
  Bytes:                 listAddFrontFloatBytes,                     \
  Bytes*:                listAddFrontFloatBytesP,                    \
  const volatile Bytes*: listAddFrontFloatBytesP,                    \
  void*:                 listAddFrontFloatPointer,                   \
  void**:                listAddFrontFloatPointerP,                  \
  const volatile void**: listAddFrontFloatPointerP,                  \
  i8:                    listAddFrontFloatI8,                        \
  u8:                    listAddFrontFloatU8                         \

#define listAddFrontFloat(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_FLOAT_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_DOUBLE_KEY(dataStructure, key, value) \
  bool:                  listAddFrontDoubleBool,                     \
  bool*:                 listAddFrontDoubleBoolP,                    \
  const volatile bool*:  listAddFrontDoubleBoolP,                    \
  i16:                   listAddFrontDoubleI16,                      \
  i16*:                  listAddFrontDoubleI16P,                     \
  const volatile i16*:   listAddFrontDoubleI16P,                     \
  u16:                   listAddFrontDoubleU16,                      \
  u16*:                  listAddFrontDoubleU16P,                     \
  const volatile u16*:   listAddFrontDoubleU16P,                     \
  i32:                   listAddFrontDoubleI32,                      \
  i32*:                  listAddFrontDoubleI32P,                     \
  const volatile i32*:   listAddFrontDoubleI32P,                     \
  u32:                   listAddFrontDoubleU32,                      \
  u32*:                  listAddFrontDoubleU32P,                     \
  const volatile u32*:   listAddFrontDoubleU32P,                     \
  i64:                   listAddFrontDoubleI64,                      \
  i64*:                  listAddFrontDoubleI64P,                     \
  const volatile i64*:   listAddFrontDoubleI64P,                     \
  u64:                   listAddFrontDoubleU64,                      \
  u64*:                  listAddFrontDoubleU64P,                     \
  const volatile u64*:   listAddFrontDoubleU64P,                     \
  float:                 listAddFrontDoubleFloat,                    \
  float*:                listAddFrontDoubleFloatP,                   \
  const volatile float*: listAddFrontDoubleFloatP,                   \
  double:                listAddFrontDoubleDouble,                   \
  double*:               listAddFrontDoubleDoubleP,                  \
  const volatile double*: listAddFrontDoubleDoubleP,                  \
  long double:           listAddFrontDoubleLongDouble,               \
  long double*:          listAddFrontDoubleLongDoubleP,              \
  const volatile long double*: listAddFrontDoubleLongDoubleP,              \
  List:                  listAddFrontDoubleList,                     \
  List*:                 listAddFrontDoubleListP,                    \
  const volatile List*:  listAddFrontDoubleListP,                    \
  Queue:                 listAddFrontDoubleQueue,                    \
  Queue*:                listAddFrontDoubleQueueP,                   \
  const volatile Queue*: listAddFrontDoubleQueueP,                   \
  Stack:                 listAddFrontDoubleStack,                    \
  Stack*:                listAddFrontDoubleStackP,                   \
  const volatile Stack*: listAddFrontDoubleStackP,                   \
  RedBlackTree:          listAddFrontDoubleRedBlackTree,             \
  RedBlackTree*:         listAddFrontDoubleRedBlackTreeP,            \
  const volatile RedBlackTree*: listAddFrontDoubleRedBlackTreeP,            \
  HashTable:             listAddFrontDoubleHashTable,                \
  HashTable*:            listAddFrontDoubleHashTableP,               \
  const volatile HashTable*: listAddFrontDoubleHashTableP,               \
  Vector:                listAddFrontDoubleVector,                   \
  Vector*:               listAddFrontDoubleVectorP,                  \
  const volatile Vector*: listAddFrontDoubleVectorP,                  \
  char*:                 listAddFrontDoubleString,                   \
  const volatile char*:  listAddFrontDoubleString,                   \
  char**:                listAddFrontDoubleStringP,                  \
  const volatile char**: listAddFrontDoubleStringP,                  \
  Bytes:                 listAddFrontDoubleBytes,                    \
  Bytes*:                listAddFrontDoubleBytesP,                   \
  const volatile Bytes*: listAddFrontDoubleBytesP,                   \
  void*:                 listAddFrontDoublePointer,                  \
  void**:                listAddFrontDoublePointerP,                 \
  const volatile void**: listAddFrontDoublePointerP,                 \
  i8:                    listAddFrontDoubleI8,                       \
  u8:                    listAddFrontDoubleU8                        \

#define listAddFrontDouble(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_DOUBLE_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_LONG_DOUBLE_KEY(dataStructure, key, value) \
  bool:                  listAddFrontLongDoubleBool,                 \
  bool*:                 listAddFrontLongDoubleBoolP,                \
  const volatile bool*:  listAddFrontLongDoubleBoolP,                \
  i16:                   listAddFrontLongDoubleI16,                  \
  i16*:                  listAddFrontLongDoubleI16P,                 \
  const volatile i16*:   listAddFrontLongDoubleI16P,                 \
  u16:                   listAddFrontLongDoubleU16,                  \
  u16*:                  listAddFrontLongDoubleU16P,                 \
  const volatile u16*:   listAddFrontLongDoubleU16P,                 \
  i32:                   listAddFrontLongDoubleI32,                  \
  i32*:                  listAddFrontLongDoubleI32P,                 \
  const volatile i32*:   listAddFrontLongDoubleI32P,                 \
  u32:                   listAddFrontLongDoubleU32,                  \
  u32*:                  listAddFrontLongDoubleU32P,                 \
  const volatile u32*:   listAddFrontLongDoubleU32P,                 \
  i64:                   listAddFrontLongDoubleI64,                  \
  i64*:                  listAddFrontLongDoubleI64P,                 \
  const volatile i64*:   listAddFrontLongDoubleI64P,                 \
  u64:                   listAddFrontLongDoubleU64,                  \
  u64*:                  listAddFrontLongDoubleU64P,                 \
  const volatile u64*:   listAddFrontLongDoubleU64P,                 \
  float:                 listAddFrontLongDoubleFloat,                \
  float*:                listAddFrontLongDoubleFloatP,               \
  const volatile float*: listAddFrontLongDoubleFloatP,               \
  double:                listAddFrontLongDoubleDouble,               \
  double*:               listAddFrontLongDoubleDoubleP,              \
  const volatile double*: listAddFrontLongDoubleDoubleP,              \
  long double:           listAddFrontLongDoubleLongDouble,           \
  long double*:          listAddFrontLongDoubleLongDoubleP,          \
  const volatile long double*: listAddFrontLongDoubleLongDoubleP,          \
  List:                  listAddFrontLongDoubleList,                 \
  List*:                 listAddFrontLongDoubleListP,                \
  const volatile List*:  listAddFrontLongDoubleListP,                \
  Queue:                 listAddFrontLongDoubleQueue,                \
  Queue*:                listAddFrontLongDoubleQueueP,               \
  const volatile Queue*: listAddFrontLongDoubleQueueP,               \
  Stack:                 listAddFrontLongDoubleStack,                \
  Stack*:                listAddFrontLongDoubleStackP,               \
  const volatile Stack*: listAddFrontLongDoubleStackP,               \
  RedBlackTree:          listAddFrontLongDoubleRedBlackTree,         \
  RedBlackTree*:         listAddFrontLongDoubleRedBlackTreeP,        \
  const volatile RedBlackTree*: listAddFrontLongDoubleRedBlackTreeP,        \
  HashTable:             listAddFrontLongDoubleHashTable,            \
  HashTable*:            listAddFrontLongDoubleHashTableP,           \
  const volatile HashTable*: listAddFrontLongDoubleHashTableP,           \
  Vector:                listAddFrontLongDoubleVector,               \
  Vector*:               listAddFrontLongDoubleVectorP,              \
  const volatile Vector*: listAddFrontLongDoubleVectorP,              \
  char*:                 listAddFrontLongDoubleString,               \
  const volatile char*:  listAddFrontLongDoubleString,               \
  char**:                listAddFrontLongDoubleStringP,              \
  const volatile char**: listAddFrontLongDoubleStringP,              \
  Bytes:                 listAddFrontLongDoubleBytes,                \
  Bytes*:                listAddFrontLongDoubleBytesP,               \
  const volatile Bytes*: listAddFrontLongDoubleBytesP,               \
  void*:                 listAddFrontLongDoublePointer,              \
  void**:                listAddFrontLongDoublePointerP,             \
  const volatile void**: listAddFrontLongDoublePointerP,             \
  i8:                    listAddFrontLongDoubleI8,                   \
  u8:                    listAddFrontLongDoubleU8                    \

#define listAddFrontLongDouble(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_LONG_DOUBLE_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_LIST_KEY(dataStructure, key, value) \
  bool:                  listAddFrontListBool,                       \
  bool*:                 listAddFrontListBoolP,                      \
  const volatile bool*:  listAddFrontListBoolP,                      \
  i16:                   listAddFrontListI16,                        \
  i16*:                  listAddFrontListI16P,                       \
  const volatile i16*:   listAddFrontListI16P,                       \
  u16:                   listAddFrontListU16,                        \
  u16*:                  listAddFrontListU16P,                       \
  const volatile u16*:   listAddFrontListU16P,                       \
  i32:                   listAddFrontListI32,                        \
  i32*:                  listAddFrontListI32P,                       \
  const volatile i32*:   listAddFrontListI32P,                       \
  u32:                   listAddFrontListU32,                        \
  u32*:                  listAddFrontListU32P,                       \
  const volatile u32*:   listAddFrontListU32P,                       \
  i64:                   listAddFrontListI64,                        \
  i64*:                  listAddFrontListI64P,                       \
  const volatile i64*:   listAddFrontListI64P,                       \
  u64:                   listAddFrontListU64,                        \
  u64*:                  listAddFrontListU64P,                       \
  const volatile u64*:   listAddFrontListU64P,                       \
  float:                 listAddFrontListFloat,                      \
  float*:                listAddFrontListFloatP,                     \
  const volatile float*: listAddFrontListFloatP,                     \
  double:                listAddFrontListDouble,                     \
  double*:               listAddFrontListDoubleP,                    \
  const volatile double*: listAddFrontListDoubleP,                    \
  long double:           listAddFrontListLongDouble,                 \
  long double*:          listAddFrontListLongDoubleP,                \
  const volatile long double*: listAddFrontListLongDoubleP,                \
  List:                  listAddFrontListList,                       \
  List*:                 listAddFrontListListP,                      \
  const volatile List*:  listAddFrontListListP,                      \
  Queue:                 listAddFrontListQueue,                      \
  Queue*:                listAddFrontListQueueP,                     \
  const volatile Queue*: listAddFrontListQueueP,                     \
  Stack:                 listAddFrontListStack,                      \
  Stack*:                listAddFrontListStackP,                     \
  const volatile Stack*: listAddFrontListStackP,                     \
  RedBlackTree:          listAddFrontListRedBlackTree,               \
  RedBlackTree*:         listAddFrontListRedBlackTreeP,              \
  const volatile RedBlackTree*: listAddFrontListRedBlackTreeP,              \
  HashTable:             listAddFrontListHashTable,                  \
  HashTable*:            listAddFrontListHashTableP,                 \
  const volatile HashTable*: listAddFrontListHashTableP,                 \
  Vector:                listAddFrontListVector,                     \
  Vector*:               listAddFrontListVectorP,                    \
  const volatile Vector*: listAddFrontListVectorP,                    \
  char*:                 listAddFrontListString,                     \
  const volatile char*:  listAddFrontListString,                     \
  char**:                listAddFrontListStringP,                    \
  const volatile char**: listAddFrontListStringP,                    \
  Bytes:                 listAddFrontListBytes,                      \
  Bytes*:                listAddFrontListBytesP,                     \
  const volatile Bytes*: listAddFrontListBytesP,                     \
  void*:                 listAddFrontListPointer,                    \
  void**:                listAddFrontListPointerP,                   \
  const volatile void**: listAddFrontListPointerP,                   \
  i8:                    listAddFrontListI8,                         \
  u8:                    listAddFrontListU8                          \

#define listAddFrontList(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_LIST_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_QUEUE_KEY(dataStructure, key, value) \
  bool:                  listAddFrontQueueBool,                      \
  bool*:                 listAddFrontQueueBoolP,                     \
  const volatile bool*:  listAddFrontQueueBoolP,                     \
  i16:                   listAddFrontQueueI16,                       \
  i16*:                  listAddFrontQueueI16P,                      \
  const volatile i16*:   listAddFrontQueueI16P,                      \
  u16:                   listAddFrontQueueU16,                       \
  u16*:                  listAddFrontQueueU16P,                      \
  const volatile u16*:   listAddFrontQueueU16P,                      \
  i32:                   listAddFrontQueueI32,                       \
  i32*:                  listAddFrontQueueI32P,                      \
  const volatile i32*:   listAddFrontQueueI32P,                      \
  u32:                   listAddFrontQueueU32,                       \
  u32*:                  listAddFrontQueueU32P,                      \
  const volatile u32*:   listAddFrontQueueU32P,                      \
  i64:                   listAddFrontQueueI64,                       \
  i64*:                  listAddFrontQueueI64P,                      \
  const volatile i64*:   listAddFrontQueueI64P,                      \
  u64:                   listAddFrontQueueU64,                       \
  u64*:                  listAddFrontQueueU64P,                      \
  const volatile u64*:   listAddFrontQueueU64P,                      \
  float:                 listAddFrontQueueFloat,                     \
  float*:                listAddFrontQueueFloatP,                    \
  const volatile float*: listAddFrontQueueFloatP,                    \
  double:                listAddFrontQueueDouble,                    \
  double*:               listAddFrontQueueDoubleP,                   \
  const volatile double*: listAddFrontQueueDoubleP,                   \
  long double:           listAddFrontQueueLongDouble,                \
  long double*:          listAddFrontQueueLongDoubleP,               \
  const volatile long double*: listAddFrontQueueLongDoubleP,               \
  List:                  listAddFrontQueueList,                      \
  List*:                 listAddFrontQueueListP,                     \
  const volatile List*:  listAddFrontQueueListP,                     \
  Queue:                 listAddFrontQueueQueue,                     \
  Queue*:                listAddFrontQueueQueueP,                    \
  const volatile Queue*: listAddFrontQueueQueueP,                    \
  Stack:                 listAddFrontQueueStack,                     \
  Stack*:                listAddFrontQueueStackP,                    \
  const volatile Stack*: listAddFrontQueueStackP,                    \
  RedBlackTree:          listAddFrontQueueRedBlackTree,              \
  RedBlackTree*:         listAddFrontQueueRedBlackTreeP,             \
  const volatile RedBlackTree*: listAddFrontQueueRedBlackTreeP,             \
  HashTable:             listAddFrontQueueHashTable,                 \
  HashTable*:            listAddFrontQueueHashTableP,                \
  const volatile HashTable*: listAddFrontQueueHashTableP,                \
  Vector:                listAddFrontQueueVector,                    \
  Vector*:               listAddFrontQueueVectorP,                   \
  const volatile Vector*: listAddFrontQueueVectorP,                   \
  char*:                 listAddFrontQueueString,                    \
  const volatile char*:  listAddFrontQueueString,                    \
  char**:                listAddFrontQueueStringP,                   \
  const volatile char**: listAddFrontQueueStringP,                   \
  Bytes:                 listAddFrontQueueBytes,                     \
  Bytes*:                listAddFrontQueueBytesP,                    \
  const volatile Bytes*: listAddFrontQueueBytesP,                    \
  void*:                 listAddFrontQueuePointer,                   \
  void**:                listAddFrontQueuePointerP,                  \
  const volatile void**: listAddFrontQueuePointerP,                  \
  i8:                    listAddFrontQueueI8,                        \
  u8:                    listAddFrontQueueU8                         \

#define listAddFrontQueue(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_QUEUE_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_STACK_KEY(dataStructure, key, value) \
  bool:                  listAddFrontStackBool,                      \
  bool*:                 listAddFrontStackBoolP,                     \
  const volatile bool*:  listAddFrontStackBoolP,                     \
  i16:                   listAddFrontStackI16,                       \
  i16*:                  listAddFrontStackI16P,                      \
  const volatile i16*:   listAddFrontStackI16P,                      \
  u16:                   listAddFrontStackU16,                       \
  u16*:                  listAddFrontStackU16P,                      \
  const volatile u16*:   listAddFrontStackU16P,                      \
  i32:                   listAddFrontStackI32,                       \
  i32*:                  listAddFrontStackI32P,                      \
  const volatile i32*:   listAddFrontStackI32P,                      \
  u32:                   listAddFrontStackU32,                       \
  u32*:                  listAddFrontStackU32P,                      \
  const volatile u32*:   listAddFrontStackU32P,                      \
  i64:                   listAddFrontStackI64,                       \
  i64*:                  listAddFrontStackI64P,                      \
  const volatile i64*:   listAddFrontStackI64P,                      \
  u64:                   listAddFrontStackU64,                       \
  u64*:                  listAddFrontStackU64P,                      \
  const volatile u64*:   listAddFrontStackU64P,                      \
  float:                 listAddFrontStackFloat,                     \
  float*:                listAddFrontStackFloatP,                    \
  const volatile float*: listAddFrontStackFloatP,                    \
  double:                listAddFrontStackDouble,                    \
  double*:               listAddFrontStackDoubleP,                   \
  const volatile double*: listAddFrontStackDoubleP,                   \
  long double:           listAddFrontStackLongDouble,                \
  long double*:          listAddFrontStackLongDoubleP,               \
  const volatile long double*: listAddFrontStackLongDoubleP,               \
  List:                  listAddFrontStackList,                      \
  List*:                 listAddFrontStackListP,                     \
  const volatile List*:  listAddFrontStackListP,                     \
  Queue:                 listAddFrontStackQueue,                     \
  Queue*:                listAddFrontStackQueueP,                    \
  const volatile Queue*: listAddFrontStackQueueP,                    \
  Stack:                 listAddFrontStackStack,                     \
  Stack*:                listAddFrontStackStackP,                    \
  const volatile Stack*: listAddFrontStackStackP,                    \
  RedBlackTree:          listAddFrontStackRedBlackTree,              \
  RedBlackTree*:         listAddFrontStackRedBlackTreeP,             \
  const volatile RedBlackTree*: listAddFrontStackRedBlackTreeP,             \
  HashTable:             listAddFrontStackHashTable,                 \
  HashTable*:            listAddFrontStackHashTableP,                \
  const volatile HashTable*: listAddFrontStackHashTableP,                \
  Vector:                listAddFrontStackVector,                    \
  Vector*:               listAddFrontStackVectorP,                   \
  const volatile Vector*: listAddFrontStackVectorP,                   \
  char*:                 listAddFrontStackString,                    \
  const volatile char*:  listAddFrontStackString,                    \
  char**:                listAddFrontStackStringP,                   \
  const volatile char**: listAddFrontStackStringP,                   \
  Bytes:                 listAddFrontStackBytes,                     \
  Bytes*:                listAddFrontStackBytesP,                    \
  const volatile Bytes*: listAddFrontStackBytesP,                    \
  void*:                 listAddFrontStackPointer,                   \
  void**:                listAddFrontStackPointerP,                  \
  const volatile void**: listAddFrontStackPointerP,                  \
  i8:                    listAddFrontStackI8,                        \
  u8:                    listAddFrontStackU8                         \

#define listAddFrontStack(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_STACK_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_RED_BLACK_TREE_KEY(dataStructure, key, value) \
  bool:                  listAddFrontRedBlackTreeBool,               \
  bool*:                 listAddFrontRedBlackTreeBoolP,              \
  const volatile bool*:  listAddFrontRedBlackTreeBoolP,              \
  i16:                   listAddFrontRedBlackTreeI16,                \
  i16*:                  listAddFrontRedBlackTreeI16P,               \
  const volatile i16*:   listAddFrontRedBlackTreeI16P,               \
  u16:                   listAddFrontRedBlackTreeU16,                \
  u16*:                  listAddFrontRedBlackTreeU16P,               \
  const volatile u16*:   listAddFrontRedBlackTreeU16P,               \
  i32:                   listAddFrontRedBlackTreeI32,                \
  i32*:                  listAddFrontRedBlackTreeI32P,               \
  const volatile i32*:   listAddFrontRedBlackTreeI32P,               \
  u32:                   listAddFrontRedBlackTreeU32,                \
  u32*:                  listAddFrontRedBlackTreeU32P,               \
  const volatile u32*:   listAddFrontRedBlackTreeU32P,               \
  i64:                   listAddFrontRedBlackTreeI64,                \
  i64*:                  listAddFrontRedBlackTreeI64P,               \
  const volatile i64*:   listAddFrontRedBlackTreeI64P,               \
  u64:                   listAddFrontRedBlackTreeU64,                \
  u64*:                  listAddFrontRedBlackTreeU64P,               \
  const volatile u64*:   listAddFrontRedBlackTreeU64P,               \
  float:                 listAddFrontRedBlackTreeFloat,              \
  float*:                listAddFrontRedBlackTreeFloatP,             \
  const volatile float*: listAddFrontRedBlackTreeFloatP,             \
  double:                listAddFrontRedBlackTreeDouble,             \
  double*:               listAddFrontRedBlackTreeDoubleP,            \
  const volatile double*: listAddFrontRedBlackTreeDoubleP,            \
  long double:           listAddFrontRedBlackTreeLongDouble,         \
  long double*:          listAddFrontRedBlackTreeLongDoubleP,        \
  const volatile long double*: listAddFrontRedBlackTreeLongDoubleP,        \
  List:                  listAddFrontRedBlackTreeList,               \
  List*:                 listAddFrontRedBlackTreeListP,              \
  const volatile List*:  listAddFrontRedBlackTreeListP,              \
  Queue:                 listAddFrontRedBlackTreeQueue,              \
  Queue*:                listAddFrontRedBlackTreeQueueP,             \
  const volatile Queue*: listAddFrontRedBlackTreeQueueP,             \
  Stack:                 listAddFrontRedBlackTreeStack,              \
  Stack*:                listAddFrontRedBlackTreeStackP,             \
  const volatile Stack*: listAddFrontRedBlackTreeStackP,             \
  RedBlackTree:          listAddFrontRedBlackTreeRedBlackTree,       \
  RedBlackTree*:         listAddFrontRedBlackTreeRedBlackTreeP,      \
  const volatile RedBlackTree*: listAddFrontRedBlackTreeRedBlackTreeP,      \
  HashTable:             listAddFrontRedBlackTreeHashTable,          \
  HashTable*:            listAddFrontRedBlackTreeHashTableP,         \
  const volatile HashTable*: listAddFrontRedBlackTreeHashTableP,         \
  Vector:                listAddFrontRedBlackTreeVector,             \
  Vector*:               listAddFrontRedBlackTreeVectorP,            \
  const volatile Vector*: listAddFrontRedBlackTreeVectorP,            \
  char*:                 listAddFrontRedBlackTreeString,             \
  const volatile char*:  listAddFrontRedBlackTreeString,             \
  char**:                listAddFrontRedBlackTreeStringP,            \
  const volatile char**: listAddFrontRedBlackTreeStringP,            \
  Bytes:                 listAddFrontRedBlackTreeBytes,              \
  Bytes*:                listAddFrontRedBlackTreeBytesP,             \
  const volatile Bytes*: listAddFrontRedBlackTreeBytesP,             \
  void*:                 listAddFrontRedBlackTreePointer,            \
  void**:                listAddFrontRedBlackTreePointerP,           \
  const volatile void**: listAddFrontRedBlackTreePointerP,           \
  i8:                    listAddFrontRedBlackTreeI8,                 \
  u8:                    listAddFrontRedBlackTreeU8                  \

#define listAddFrontRedBlackTree(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_RED_BLACK_TREE_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_HASH_TABLE_KEY(dataStructure, key, value) \
  bool:                  listAddFrontHashTableBool,                  \
  bool*:                 listAddFrontHashTableBoolP,                 \
  const volatile bool*:  listAddFrontHashTableBoolP,                 \
  i16:                   listAddFrontHashTableI16,                   \
  i16*:                  listAddFrontHashTableI16P,                  \
  const volatile i16*:   listAddFrontHashTableI16P,                  \
  u16:                   listAddFrontHashTableU16,                   \
  u16*:                  listAddFrontHashTableU16P,                  \
  const volatile u16*:   listAddFrontHashTableU16P,                  \
  i32:                   listAddFrontHashTableI32,                   \
  i32*:                  listAddFrontHashTableI32P,                  \
  const volatile i32*:   listAddFrontHashTableI32P,                  \
  u32:                   listAddFrontHashTableU32,                   \
  u32*:                  listAddFrontHashTableU32P,                  \
  const volatile u32*:   listAddFrontHashTableU32P,                  \
  i64:                   listAddFrontHashTableI64,                   \
  i64*:                  listAddFrontHashTableI64P,                  \
  const volatile i64*:   listAddFrontHashTableI64P,                  \
  u64:                   listAddFrontHashTableU64,                   \
  u64*:                  listAddFrontHashTableU64P,                  \
  const volatile u64*:   listAddFrontHashTableU64P,                  \
  float:                 listAddFrontHashTableFloat,                 \
  float*:                listAddFrontHashTableFloatP,                \
  const volatile float*: listAddFrontHashTableFloatP,                \
  double:                listAddFrontHashTableDouble,                \
  double*:               listAddFrontHashTableDoubleP,               \
  const volatile double*: listAddFrontHashTableDoubleP,               \
  long double:           listAddFrontHashTableLongDouble,            \
  long double*:          listAddFrontHashTableLongDoubleP,           \
  const volatile long double*: listAddFrontHashTableLongDoubleP,           \
  List:                  listAddFrontHashTableList,                  \
  List*:                 listAddFrontHashTableListP,                 \
  const volatile List*:  listAddFrontHashTableListP,                 \
  Queue:                 listAddFrontHashTableQueue,                 \
  Queue*:                listAddFrontHashTableQueueP,                \
  const volatile Queue*: listAddFrontHashTableQueueP,                \
  Stack:                 listAddFrontHashTableStack,                 \
  Stack*:                listAddFrontHashTableStackP,                \
  const volatile Stack*: listAddFrontHashTableStackP,                \
  RedBlackTree:          listAddFrontHashTableRedBlackTree,          \
  RedBlackTree*:         listAddFrontHashTableRedBlackTreeP,         \
  const volatile RedBlackTree*: listAddFrontHashTableRedBlackTreeP,         \
  HashTable:             listAddFrontHashTableHashTable,             \
  HashTable*:            listAddFrontHashTableHashTableP,            \
  const volatile HashTable*: listAddFrontHashTableHashTableP,            \
  Vector:                listAddFrontHashTableVector,                \
  Vector*:               listAddFrontHashTableVectorP,               \
  const volatile Vector*: listAddFrontHashTableVectorP,               \
  char*:                 listAddFrontHashTableString,                \
  const volatile char*:  listAddFrontHashTableString,                \
  char**:                listAddFrontHashTableStringP,               \
  const volatile char**: listAddFrontHashTableStringP,               \
  Bytes:                 listAddFrontHashTableBytes,                 \
  Bytes*:                listAddFrontHashTableBytesP,                \
  const volatile Bytes*: listAddFrontHashTableBytesP,                \
  void*:                 listAddFrontHashTablePointer,               \
  void**:                listAddFrontHashTablePointerP,              \
  const volatile void**: listAddFrontHashTablePointerP,              \
  i8:                    listAddFrontHashTableI8,                    \
  u8:                    listAddFrontHashTableU8                     \

#define listAddFrontHashTable(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_HASH_TABLE_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_VECTOR_KEY(dataStructure, key, value) \
  bool:                  listAddFrontVectorBool,                     \
  bool*:                 listAddFrontVectorBoolP,                    \
  const volatile bool*:  listAddFrontVectorBoolP,                    \
  i16:                   listAddFrontVectorI16,                      \
  i16*:                  listAddFrontVectorI16P,                     \
  const volatile i16*:   listAddFrontVectorI16P,                     \
  u16:                   listAddFrontVectorU16,                      \
  u16*:                  listAddFrontVectorU16P,                     \
  const volatile u16*:   listAddFrontVectorU16P,                     \
  i32:                   listAddFrontVectorI32,                      \
  i32*:                  listAddFrontVectorI32P,                     \
  const volatile i32*:   listAddFrontVectorI32P,                     \
  u32:                   listAddFrontVectorU32,                      \
  u32*:                  listAddFrontVectorU32P,                     \
  const volatile u32*:   listAddFrontVectorU32P,                     \
  i64:                   listAddFrontVectorI64,                      \
  i64*:                  listAddFrontVectorI64P,                     \
  const volatile i64*:   listAddFrontVectorI64P,                     \
  u64:                   listAddFrontVectorU64,                      \
  u64*:                  listAddFrontVectorU64P,                     \
  const volatile u64*:   listAddFrontVectorU64P,                     \
  float:                 listAddFrontVectorFloat,                    \
  float*:                listAddFrontVectorFloatP,                   \
  const volatile float*: listAddFrontVectorFloatP,                   \
  double:                listAddFrontVectorDouble,                   \
  double*:               listAddFrontVectorDoubleP,                  \
  const volatile double*: listAddFrontVectorDoubleP,                  \
  long double:           listAddFrontVectorLongDouble,               \
  long double*:          listAddFrontVectorLongDoubleP,              \
  const volatile long double*: listAddFrontVectorLongDoubleP,              \
  List:                  listAddFrontVectorList,                     \
  List*:                 listAddFrontVectorListP,                    \
  const volatile List*:  listAddFrontVectorListP,                    \
  Queue:                 listAddFrontVectorQueue,                    \
  Queue*:                listAddFrontVectorQueueP,                   \
  const volatile Queue*: listAddFrontVectorQueueP,                   \
  Stack:                 listAddFrontVectorStack,                    \
  Stack*:                listAddFrontVectorStackP,                   \
  const volatile Stack*: listAddFrontVectorStackP,                   \
  RedBlackTree:          listAddFrontVectorRedBlackTree,             \
  RedBlackTree*:         listAddFrontVectorRedBlackTreeP,            \
  const volatile RedBlackTree*: listAddFrontVectorRedBlackTreeP,            \
  HashTable:             listAddFrontVectorHashTable,                \
  HashTable*:            listAddFrontVectorHashTableP,               \
  const volatile HashTable*: listAddFrontVectorHashTableP,               \
  Vector:                listAddFrontVectorVector,                   \
  Vector*:               listAddFrontVectorVectorP,                  \
  const volatile Vector*: listAddFrontVectorVectorP,                  \
  char*:                 listAddFrontVectorString,                   \
  const volatile char*:  listAddFrontVectorString,                   \
  char**:                listAddFrontVectorStringP,                  \
  const volatile char**: listAddFrontVectorStringP,                  \
  Bytes:                 listAddFrontVectorBytes,                    \
  Bytes*:                listAddFrontVectorBytesP,                   \
  const volatile Bytes*: listAddFrontVectorBytesP,                   \
  void*:                 listAddFrontVectorPointer,                  \
  void**:                listAddFrontVectorPointerP,                 \
  const volatile void**: listAddFrontVectorPointerP,                 \
  i8:                    listAddFrontVectorI8,                       \
  u8:                    listAddFrontVectorU8                        \

#define listAddFrontVector(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_VECTOR_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_STRING_KEY(dataStructure, key, value) \
  bool:                  listAddFrontStringBool,                     \
  const volatile bool:   listAddFrontStringBool,                     \
  bool*:                 listAddFrontStringBoolP,                    \
  const volatile bool*:  listAddFrontStringBoolP,                    \
  i16:                   listAddFrontStringI16,                      \
  const volatile i16:    listAddFrontStringI16,                      \
  i16*:                  listAddFrontStringI16P,                     \
  const volatile i16*:   listAddFrontStringI16P,                     \
  u16:                   listAddFrontStringU16,                      \
  const volatile u16:    listAddFrontStringU16,                      \
  u16*:                  listAddFrontStringU16P,                     \
  const volatile u16*:   listAddFrontStringU16P,                     \
  i32:                   listAddFrontStringI32,                      \
  const volatile i32:    listAddFrontStringI32,                      \
  i32*:                  listAddFrontStringI32P,                     \
  const volatile i32*:   listAddFrontStringI32P,                     \
  u32:                   listAddFrontStringU32,                      \
  const volatile u32:    listAddFrontStringU32,                      \
  u32*:                  listAddFrontStringU32P,                     \
  const volatile u32*:   listAddFrontStringU32P,                     \
  i64:                   listAddFrontStringI64,                      \
  const volatile i64:    listAddFrontStringI64,                      \
  i64*:                  listAddFrontStringI64P,                     \
  const volatile i64*:   listAddFrontStringI64P,                     \
  u64:                   listAddFrontStringU64,                      \
  const volatile u64:    listAddFrontStringU64,                      \
  u64*:                  listAddFrontStringU64P,                     \
  const volatile u64*:   listAddFrontStringU64P,                     \
  float:                 listAddFrontStringFloat,                    \
  const volatile float:  listAddFrontStringFloat,                    \
  float*:                listAddFrontStringFloatP,                   \
  const volatile float*: listAddFrontStringFloatP,                   \
  double:                listAddFrontStringDouble,                   \
  const volatile double: listAddFrontStringDouble,                   \
  double*:               listAddFrontStringDoubleP,                  \
  const volatile double*: listAddFrontStringDoubleP,                  \
  long double:           listAddFrontStringLongDouble,               \
  const volatile long double: listAddFrontStringLongDouble,               \
  long double*:          listAddFrontStringLongDoubleP,              \
  const volatile long double*: listAddFrontStringLongDoubleP,              \
  List:                  listAddFrontStringList,                     \
  const volatile List:   listAddFrontStringList,                     \
  List*:                 listAddFrontStringListP,                    \
  const volatile List*:  listAddFrontStringListP,                    \
  Queue:                 listAddFrontStringQueue,                    \
  const volatile Queue:  listAddFrontStringQueue,                    \
  Queue*:                listAddFrontStringQueueP,                   \
  const volatile Queue*: listAddFrontStringQueueP,                   \
  Stack:                 listAddFrontStringStack,                    \
  const volatile Stack:  listAddFrontStringStack,                    \
  Stack*:                listAddFrontStringStackP,                   \
  const volatile Stack*: listAddFrontStringStackP,                   \
  RedBlackTree:          listAddFrontStringRedBlackTree,             \
  const volatile RedBlackTree: listAddFrontStringRedBlackTree,             \
  RedBlackTree*:         listAddFrontStringRedBlackTreeP,            \
  const volatile RedBlackTree*: listAddFrontStringRedBlackTreeP,            \
  HashTable:             listAddFrontStringHashTable,                \
  const volatile HashTable: listAddFrontStringHashTable,                \
  HashTable*:            listAddFrontStringHashTableP,               \
  const volatile HashTable*: listAddFrontStringHashTableP,               \
  Vector:                listAddFrontStringVector,                   \
  const volatile Vector: listAddFrontStringVector,                   \
  Vector*:               listAddFrontStringVectorP,                  \
  const volatile Vector*: listAddFrontStringVectorP,                  \
  char*:                 listAddFrontStringString,                   \
  const volatile char*:  listAddFrontStringString,                   \
  char**:                listAddFrontStringStringP,                  \
  const volatile char**: listAddFrontStringStringP,                  \
  Bytes:                 listAddFrontStringBytes,                    \
  Bytes*:                listAddFrontStringBytesP,                   \
  const volatile Bytes*: listAddFrontStringBytesP,                   \
  void*:                 listAddFrontStringPointer,                  \
  void**:                listAddFrontStringPointerP,                 \
  const volatile void**: listAddFrontStringPointerP,                 \
  i8:                    listAddFrontStringI8,                       \
  u8:                    listAddFrontStringU8                        \

#define listAddFrontString(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_STRING_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_BYTES_KEY(dataStructure, key, value) \
  bool:                  listAddFrontBytesBool,                      \
  bool*:                 listAddFrontBytesBoolP,                     \
  const volatile bool*:  listAddFrontBytesBoolP,                     \
  i16:                   listAddFrontBytesI16,                       \
  i16*:                  listAddFrontBytesI16P,                      \
  const volatile i16*:   listAddFrontBytesI16P,                      \
  u16:                   listAddFrontBytesU16,                       \
  u16*:                  listAddFrontBytesU16P,                      \
  const volatile u16*:   listAddFrontBytesU16P,                      \
  i32:                   listAddFrontBytesI32,                       \
  i32*:                  listAddFrontBytesI32P,                      \
  const volatile i32*:   listAddFrontBytesI32P,                      \
  u32:                   listAddFrontBytesU32,                       \
  u32*:                  listAddFrontBytesU32P,                      \
  const volatile u32*:   listAddFrontBytesU32P,                      \
  i64:                   listAddFrontBytesI64,                       \
  i64*:                  listAddFrontBytesI64P,                      \
  const volatile i64*:   listAddFrontBytesI64P,                      \
  u64:                   listAddFrontBytesU64,                       \
  u64*:                  listAddFrontBytesU64P,                      \
  const volatile u64*:   listAddFrontBytesU64P,                      \
  float:                 listAddFrontBytesFloat,                     \
  float*:                listAddFrontBytesFloatP,                    \
  const volatile float*: listAddFrontBytesFloatP,                    \
  double:                listAddFrontBytesDouble,                    \
  double*:               listAddFrontBytesDoubleP,                   \
  const volatile double*: listAddFrontBytesDoubleP,                   \
  long double:           listAddFrontBytesLongDouble,                \
  long double*:          listAddFrontBytesLongDoubleP,               \
  const volatile long double*: listAddFrontBytesLongDoubleP,               \
  List:                  listAddFrontBytesList,                      \
  List*:                 listAddFrontBytesListP,                     \
  const volatile List*:  listAddFrontBytesListP,                     \
  Queue:                 listAddFrontBytesQueue,                     \
  Queue*:                listAddFrontBytesQueueP,                    \
  const volatile Queue*: listAddFrontBytesQueueP,                    \
  Stack:                 listAddFrontBytesStack,                     \
  Stack*:                listAddFrontBytesStackP,                    \
  const volatile Stack*: listAddFrontBytesStackP,                    \
  RedBlackTree:          listAddFrontBytesRedBlackTree,              \
  RedBlackTree*:         listAddFrontBytesRedBlackTreeP,             \
  const volatile RedBlackTree*: listAddFrontBytesRedBlackTreeP,             \
  HashTable:             listAddFrontBytesHashTable,                 \
  HashTable*:            listAddFrontBytesHashTableP,                \
  const volatile HashTable*: listAddFrontBytesHashTableP,                \
  Vector:                listAddFrontBytesVector,                    \
  Vector*:               listAddFrontBytesVectorP,                   \
  const volatile Vector*: listAddFrontBytesVectorP,                   \
  char*:                 listAddFrontBytesString,                    \
  const volatile char*:  listAddFrontBytesString,                    \
  char**:                listAddFrontBytesStringP,                   \
  const volatile char**: listAddFrontBytesStringP,                   \
  Bytes:                 listAddFrontBytesBytes,                     \
  Bytes*:                listAddFrontBytesBytesP,                    \
  const volatile Bytes*: listAddFrontBytesBytesP,                    \
  void*:                 listAddFrontBytesPointer,                   \
  void**:                listAddFrontBytesPointerP,                  \
  const volatile void**: listAddFrontBytesPointerP,                  \
  i8:                    listAddFrontBytesI8,                        \
  u8:                    listAddFrontBytesU8                         \

#define listAddFrontBytes(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_BYTES_KEY(dataStructure, key, value) \
  )


#define LIST_ADD_FRONT_GENERIC_CASES_POINTER_KEY(dataStructure, key, value) \
  bool:                  listAddFrontPointerBool,                    \
  bool*:                 listAddFrontPointerBoolP,                   \
  const volatile bool*:  listAddFrontPointerBoolP,                   \
  i16:                   listAddFrontPointerI16,                     \
  i16*:                  listAddFrontPointerI16P,                    \
  const volatile i16*:   listAddFrontPointerI16P,                    \
  u16:                   listAddFrontPointerU16,                     \
  u16*:                  listAddFrontPointerU16P,                    \
  const volatile u16*:   listAddFrontPointerU16P,                    \
  i32:                   listAddFrontPointerI32,                     \
  i32*:                  listAddFrontPointerI32P,                    \
  const volatile i32*:   listAddFrontPointerI32P,                    \
  u32:                   listAddFrontPointerU32,                     \
  u32*:                  listAddFrontPointerU32P,                    \
  const volatile u32*:   listAddFrontPointerU32P,                    \
  i64:                   listAddFrontPointerI64,                     \
  i64*:                  listAddFrontPointerI64P,                    \
  const volatile i64*:   listAddFrontPointerI64P,                    \
  u64:                   listAddFrontPointerU64,                     \
  u64*:                  listAddFrontPointerU64P,                    \
  const volatile u64*:   listAddFrontPointerU64P,                    \
  float:                 listAddFrontPointerFloat,                   \
  float*:                listAddFrontPointerFloatP,                  \
  const volatile float*: listAddFrontPointerFloatP,                  \
  double:                listAddFrontPointerDouble,                  \
  double*:               listAddFrontPointerDoubleP,                 \
  const volatile double*: listAddFrontPointerDoubleP,                 \
  long double:           listAddFrontPointerLongDouble,              \
  long double*:          listAddFrontPointerLongDoubleP,             \
  const volatile long double*: listAddFrontPointerLongDoubleP,             \
  List:                  listAddFrontPointerList,                    \
  List*:                 listAddFrontPointerListP,                   \
  const volatile List*:  listAddFrontPointerListP,                   \
  Queue:                 listAddFrontPointerQueue,                   \
  Queue*:                listAddFrontPointerQueueP,                  \
  const volatile Queue*: listAddFrontPointerQueueP,                  \
  Stack:                 listAddFrontPointerStack,                   \
  Stack*:                listAddFrontPointerStackP,                  \
  const volatile Stack*: listAddFrontPointerStackP,                  \
  RedBlackTree:          listAddFrontPointerRedBlackTree,            \
  RedBlackTree*:         listAddFrontPointerRedBlackTreeP,           \
  const volatile RedBlackTree*: listAddFrontPointerRedBlackTreeP,           \
  HashTable:             listAddFrontPointerHashTable,               \
  HashTable*:            listAddFrontPointerHashTableP,              \
  const volatile HashTable*: listAddFrontPointerHashTableP,              \
  Vector:                listAddFrontPointerVector,                  \
  Vector*:               listAddFrontPointerVectorP,                 \
  const volatile Vector*: listAddFrontPointerVectorP,                 \
  char*:                 listAddFrontPointerString,                  \
  const volatile char*:  listAddFrontPointerString,                  \
  char**:                listAddFrontPointerStringP,                 \
  const volatile char**: listAddFrontPointerStringP,                 \
  Bytes:                 listAddFrontPointerBytes,                   \
  Bytes*:                listAddFrontPointerBytesP,                  \
  const volatile Bytes*: listAddFrontPointerBytesP,                  \
  void*:                 listAddFrontPointerPointer,                 \
  void**:                listAddFrontPointerPointerP,                \
  const volatile void**: listAddFrontPointerPointerP,                \
  i8:                    listAddFrontPointerI8,                      \
  u8:                    listAddFrontPointerU8                       \

#define listAddFrontPointer(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_POINTER_KEY(dataStructure, key, value) \
  )


#define LIST_ADD_FRONT_GENERIC_CASES_I8_KEY(dataStructure, key, value) \
  bool:                  listAddFrontI8Bool,                         \
  bool*:                 listAddFrontI8BoolP,                        \
  const volatile bool*:  listAddFrontI8BoolP,                        \
  i16:                   listAddFrontI8I16,                          \
  i16*:                  listAddFrontI8I16P,                         \
  const volatile i16*:   listAddFrontI8I16P,                         \
  u16:                   listAddFrontI8U16,                          \
  u16*:                  listAddFrontI8U16P,                         \
  const volatile u16*:   listAddFrontI8U16P,                         \
  i32:                   listAddFrontI8I32,                          \
  i32*:                  listAddFrontI8I32P,                         \
  const volatile i32*:   listAddFrontI8I32P,                         \
  u32:                   listAddFrontI8U32,                          \
  u32*:                  listAddFrontI8U32P,                         \
  const volatile u32*:   listAddFrontI8U32P,                         \
  i64:                   listAddFrontI8I64,                          \
  i64*:                  listAddFrontI8I64P,                         \
  const volatile i64*:   listAddFrontI8I64P,                         \
  u64:                   listAddFrontI8U64,                          \
  u64*:                  listAddFrontI8U64P,                         \
  const volatile u64*:   listAddFrontI8U64P,                         \
  float:                 listAddFrontI8Float,                        \
  float*:                listAddFrontI8FloatP,                       \
  const volatile float*: listAddFrontI8FloatP,                       \
  double:                listAddFrontI8Double,                       \
  double*:               listAddFrontI8DoubleP,                      \
  const volatile double*: listAddFrontI8DoubleP,                      \
  long double:           listAddFrontI8LongDouble,                   \
  long double*:          listAddFrontI8LongDoubleP,                  \
  const volatile long double*: listAddFrontI8LongDoubleP,                  \
  List:                  listAddFrontI8List,                         \
  List*:                 listAddFrontI8ListP,                        \
  const volatile List*:  listAddFrontI8ListP,                        \
  Queue:                 listAddFrontI8Queue,                        \
  Queue*:                listAddFrontI8QueueP,                       \
  const volatile Queue*: listAddFrontI8QueueP,                       \
  Stack:                 listAddFrontI8Stack,                        \
  Stack*:                listAddFrontI8StackP,                       \
  const volatile Stack*: listAddFrontI8StackP,                       \
  RedBlackTree:          listAddFrontI8RedBlackTree,                 \
  RedBlackTree*:         listAddFrontI8RedBlackTreeP,                \
  const volatile RedBlackTree*: listAddFrontI8RedBlackTreeP,                \
  HashTable:             listAddFrontI8HashTable,                    \
  HashTable*:            listAddFrontI8HashTableP,                   \
  const volatile HashTable*: listAddFrontI8HashTableP,                   \
  Vector:                listAddFrontI8Vector,                       \
  Vector*:               listAddFrontI8VectorP,                      \
  const volatile Vector*: listAddFrontI8VectorP,                      \
  char*:                 listAddFrontI8String,                       \
  const volatile char*:  listAddFrontI8String,                       \
  char**:                listAddFrontI8StringP,                      \
  const volatile char**: listAddFrontI8StringP,                      \
  Bytes:                 listAddFrontI8Bytes,                        \
  Bytes*:                listAddFrontI8BytesP,                       \
  const volatile Bytes*: listAddFrontI8BytesP,                       \
  void*:                 listAddFrontI8Pointer,                      \
  void**:                listAddFrontI8PointerP,                     \
  const volatile void**: listAddFrontI8PointerP,                     \
  i8:                    listAddFrontI8I8,                           \
  u8:                    listAddFrontI8U8                            \

#define listAddFrontI8(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_I8_KEY(dataStructure, key, value) \
  )


#define LIST_ADD_FRONT_GENERIC_CASES_U8_KEY(dataStructure, key, value) \
  bool:                  listAddFrontU8Bool,                         \
  bool*:                 listAddFrontU8BoolP,                        \
  const volatile bool*:  listAddFrontU8BoolP,                        \
  i16:                   listAddFrontU8I16,                          \
  i16*:                  listAddFrontU8I16P,                         \
  const volatile i16*:   listAddFrontU8I16P,                         \
  u16:                   listAddFrontU8U16,                          \
  u16*:                  listAddFrontU8U16P,                         \
  const volatile u16*:   listAddFrontU8U16P,                         \
  i32:                   listAddFrontU8I32,                          \
  i32*:                  listAddFrontU8I32P,                         \
  const volatile i32*:   listAddFrontU8I32P,                         \
  u32:                   listAddFrontU8U32,                          \
  u32*:                  listAddFrontU8U32P,                         \
  const volatile u32*:   listAddFrontU8U32P,                         \
  i64:                   listAddFrontU8I64,                          \
  i64*:                  listAddFrontU8I64P,                         \
  const volatile i64*:   listAddFrontU8I64P,                         \
  u64:                   listAddFrontU8U64,                          \
  u64*:                  listAddFrontU8U64P,                         \
  const volatile u64*:   listAddFrontU8U64P,                         \
  float:                 listAddFrontU8Float,                        \
  float*:                listAddFrontU8FloatP,                       \
  const volatile float*: listAddFrontU8FloatP,                       \
  double:                listAddFrontU8Double,                       \
  double*:               listAddFrontU8DoubleP,                      \
  const volatile double*: listAddFrontU8DoubleP,                      \
  long double:           listAddFrontU8LongDouble,                   \
  long double*:          listAddFrontU8LongDoubleP,                  \
  const volatile long double*: listAddFrontU8LongDoubleP,                  \
  List:                  listAddFrontU8List,                         \
  List*:                 listAddFrontU8ListP,                        \
  const volatile List*:  listAddFrontU8ListP,                        \
  Queue:                 listAddFrontU8Queue,                        \
  Queue*:                listAddFrontU8QueueP,                       \
  const volatile Queue*: listAddFrontU8QueueP,                       \
  Stack:                 listAddFrontU8Stack,                        \
  Stack*:                listAddFrontU8StackP,                       \
  const volatile Stack*: listAddFrontU8StackP,                       \
  RedBlackTree:          listAddFrontU8RedBlackTree,                 \
  RedBlackTree*:         listAddFrontU8RedBlackTreeP,                \
  const volatile RedBlackTree*: listAddFrontU8RedBlackTreeP,                \
  HashTable:             listAddFrontU8HashTable,                    \
  HashTable*:            listAddFrontU8HashTableP,                   \
  const volatile HashTable*: listAddFrontU8HashTableP,                   \
  Vector:                listAddFrontU8Vector,                       \
  Vector*:               listAddFrontU8VectorP,                      \
  const volatile Vector*: listAddFrontU8VectorP,                      \
  char*:                 listAddFrontU8String,                       \
  const volatile char*:  listAddFrontU8String,                       \
  char**:                listAddFrontU8StringP,                      \
  const volatile char**: listAddFrontU8StringP,                      \
  Bytes:                 listAddFrontU8Bytes,                        \
  Bytes*:                listAddFrontU8BytesP,                       \
  const volatile Bytes*: listAddFrontU8BytesP,                       \
  void*:                 listAddFrontU8Pointer,                      \
  void**:                listAddFrontU8PointerP,                     \
  const volatile void**: listAddFrontU8PointerP,                     \
  i8:                    listAddFrontU8I8,                           \
  u8:                    listAddFrontU8U8                            \

#define listAddFrontU8(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_U8_KEY(dataStructure, key, value) \
  )


#define LIST_ADD_FRONT_GENERIC_CASES_BOOLP_KEY(dataStructure, key, value) \
  bool:                  listAddFrontBoolPBool,                      \
  bool*:                 listAddFrontBoolPBoolP,                     \
  const volatile bool*:  listAddFrontBoolPBoolP,                     \
  i16:                   listAddFrontBoolPI16,                       \
  i16*:                  listAddFrontBoolPI16P,                      \
  const volatile i16*:   listAddFrontBoolPI16P,                      \
  u16:                   listAddFrontBoolPU16,                       \
  u16*:                  listAddFrontBoolPU16P,                      \
  const volatile u16*:   listAddFrontBoolPU16P,                      \
  i32:                   listAddFrontBoolPI32,                       \
  i32*:                  listAddFrontBoolPI32P,                      \
  const volatile i32*:   listAddFrontBoolPI32P,                      \
  u32:                   listAddFrontBoolPU32,                       \
  u32*:                  listAddFrontBoolPU32P,                      \
  const volatile u32*:   listAddFrontBoolPU32P,                      \
  i64:                   listAddFrontBoolPI64,                       \
  i64*:                  listAddFrontBoolPI64P,                      \
  const volatile i64*:   listAddFrontBoolPI64P,                      \
  u64:                   listAddFrontBoolPU64,                       \
  u64*:                  listAddFrontBoolPU64P,                      \
  const volatile u64*:   listAddFrontBoolPU64P,                      \
  float:                 listAddFrontBoolPFloat,                     \
  float*:                listAddFrontBoolPFloatP,                    \
  const volatile float*: listAddFrontBoolPFloatP,                    \
  double:                listAddFrontBoolPDouble,                    \
  double*:               listAddFrontBoolPDoubleP,                   \
  const volatile double*: listAddFrontBoolPDoubleP,                   \
  long double:           listAddFrontBoolPLongDouble,                \
  long double*:          listAddFrontBoolPLongDoubleP,               \
  const volatile long double*: listAddFrontBoolPLongDoubleP,               \
  List:                  listAddFrontBoolPList,                      \
  List*:                 listAddFrontBoolPListP,                     \
  const volatile List*:  listAddFrontBoolPListP,                     \
  Queue:                 listAddFrontBoolPQueue,                     \
  Queue*:                listAddFrontBoolPQueueP,                    \
  const volatile Queue*: listAddFrontBoolPQueueP,                    \
  Stack:                 listAddFrontBoolPStack,                     \
  Stack*:                listAddFrontBoolPStackP,                    \
  const volatile Stack*: listAddFrontBoolPStackP,                    \
  RedBlackTree:          listAddFrontBoolPRedBlackTree,              \
  RedBlackTree*:         listAddFrontBoolPRedBlackTreeP,             \
  const volatile RedBlackTree*: listAddFrontBoolPRedBlackTreeP,             \
  HashTable:             listAddFrontBoolPHashTable,                 \
  HashTable*:            listAddFrontBoolPHashTableP,                \
  const volatile HashTable*: listAddFrontBoolPHashTableP,                \
  Vector:                listAddFrontBoolPVector,                    \
  Vector*:               listAddFrontBoolPVectorP,                   \
  const volatile Vector*: listAddFrontBoolPVectorP,                   \
  char*:                 listAddFrontBoolPString,                    \
  const volatile char*:  listAddFrontBoolPString,                    \
  char**:                listAddFrontBoolPStringP,                   \
  const volatile char**: listAddFrontBoolPStringP,                   \
  Bytes:                 listAddFrontBoolPBytes,                     \
  Bytes*:                listAddFrontBoolPBytesP,                    \
  const volatile Bytes*: listAddFrontBoolPBytesP,                    \
  void*:                 listAddFrontBoolPPointer,                   \
  void**:                listAddFrontBoolPPointerP,                  \
  const volatile void**: listAddFrontBoolPPointerP,                  \
  i8:                    listAddFrontBoolI8,                         \
  u8:                    listAddFrontBoolU8                          \

#define listAddFrontBoolP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_BOOLP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_I16P_KEY(dataStructure, key, value) \
  bool:                  listAddFrontI16PBool,                       \
  bool*:                 listAddFrontI16PBoolP,                      \
  const volatile bool*:  listAddFrontI16PBoolP,                      \
  i16:                   listAddFrontI16PI16,                        \
  i16*:                  listAddFrontI16PI16P,                       \
  const volatile i16*:   listAddFrontI16PI16P,                       \
  u16:                   listAddFrontI16PU16,                        \
  u16*:                  listAddFrontI16PU16P,                       \
  const volatile u16*:   listAddFrontI16PU16P,                       \
  i32:                   listAddFrontI16PI32,                        \
  i32*:                  listAddFrontI16PI32P,                       \
  const volatile i32*:   listAddFrontI16PI32P,                       \
  u32:                   listAddFrontI16PU32,                        \
  u32*:                  listAddFrontI16PU32P,                       \
  const volatile u32*:   listAddFrontI16PU32P,                       \
  i64:                   listAddFrontI16PI64,                        \
  i64*:                  listAddFrontI16PI64P,                       \
  const volatile i64*:   listAddFrontI16PI64P,                       \
  u64:                   listAddFrontI16PU64,                        \
  u64*:                  listAddFrontI16PU64P,                       \
  const volatile u64*:   listAddFrontI16PU64P,                       \
  float:                 listAddFrontI16PFloat,                      \
  float*:                listAddFrontI16PFloatP,                     \
  const volatile float*: listAddFrontI16PFloatP,                     \
  double:                listAddFrontI16PDouble,                     \
  double*:               listAddFrontI16PDoubleP,                    \
  const volatile double*: listAddFrontI16PDoubleP,                    \
  long double:           listAddFrontI16PLongDouble,                 \
  long double*:          listAddFrontI16PLongDoubleP,                \
  const volatile long double*: listAddFrontI16PLongDoubleP,                \
  List:                  listAddFrontI16PList,                       \
  List*:                 listAddFrontI16PListP,                      \
  const volatile List*:  listAddFrontI16PListP,                      \
  Queue:                 listAddFrontI16PQueue,                      \
  Queue*:                listAddFrontI16PQueueP,                     \
  const volatile Queue*: listAddFrontI16PQueueP,                     \
  Stack:                 listAddFrontI16PStack,                      \
  Stack*:                listAddFrontI16PStackP,                     \
  const volatile Stack*: listAddFrontI16PStackP,                     \
  RedBlackTree:          listAddFrontI16PRedBlackTree,               \
  RedBlackTree*:         listAddFrontI16PRedBlackTreeP,              \
  const volatile RedBlackTree*: listAddFrontI16PRedBlackTreeP,              \
  HashTable:             listAddFrontI16PHashTable,                  \
  HashTable*:            listAddFrontI16PHashTableP,                 \
  const volatile HashTable*: listAddFrontI16PHashTableP,                 \
  Vector:                listAddFrontI16PVector,                     \
  Vector*:               listAddFrontI16PVectorP,                    \
  const volatile Vector*: listAddFrontI16PVectorP,                    \
  char*:                 listAddFrontI16PString,                     \
  const volatile char*:  listAddFrontI16PString,                     \
  char**:                listAddFrontI16PStringP,                    \
  const volatile char**: listAddFrontI16PStringP,                    \
  Bytes:                 listAddFrontI16PBytes,                      \
  Bytes*:                listAddFrontI16PBytesP,                     \
  const volatile Bytes*: listAddFrontI16PBytesP,                     \
  void*:                 listAddFrontI16PPointer,                    \
  void**:                listAddFrontI16PPointerP,                   \
  const volatile void**: listAddFrontI16PPointerP,                   \
  i8:                    listAddFrontI16I8,                          \
  u8:                    listAddFrontI16U8                           \

#define listAddFrontI16P(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_I16P_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_U16P_KEY(dataStructure, key, value) \
  bool:                  listAddFrontU16PBool,                       \
  bool*:                 listAddFrontU16PBoolP,                      \
  const volatile bool*:  listAddFrontU16PBoolP,                      \
  i16:                   listAddFrontU16PI16,                        \
  i16*:                  listAddFrontU16PI16P,                       \
  const volatile i16*:   listAddFrontU16PI16P,                       \
  u16:                   listAddFrontU16PU16,                        \
  u16*:                  listAddFrontU16PU16P,                       \
  const volatile u16*:   listAddFrontU16PU16P,                       \
  i32:                   listAddFrontU16PI32,                        \
  i32*:                  listAddFrontU16PI32P,                       \
  const volatile i32*:   listAddFrontU16PI32P,                       \
  u32:                   listAddFrontU16PU32,                        \
  u32*:                  listAddFrontU16PU32P,                       \
  const volatile u32*:   listAddFrontU16PU32P,                       \
  i64:                   listAddFrontU16PI64,                        \
  i64*:                  listAddFrontU16PI64P,                       \
  const volatile i64*:   listAddFrontU16PI64P,                       \
  u64:                   listAddFrontU16PU64,                        \
  u64*:                  listAddFrontU16PU64P,                       \
  const volatile u64*:   listAddFrontU16PU64P,                       \
  float:                 listAddFrontU16PFloat,                      \
  float*:                listAddFrontU16PFloatP,                     \
  const volatile float*: listAddFrontU16PFloatP,                     \
  double:                listAddFrontU16PDouble,                     \
  double*:               listAddFrontU16PDoubleP,                    \
  const volatile double*: listAddFrontU16PDoubleP,                    \
  long double:           listAddFrontU16PLongDouble,                 \
  long double*:          listAddFrontU16PLongDoubleP,                \
  const volatile long double*: listAddFrontU16PLongDoubleP,                \
  List:                  listAddFrontU16PList,                       \
  List*:                 listAddFrontU16PListP,                      \
  const volatile List*:  listAddFrontU16PListP,                      \
  Queue:                 listAddFrontU16PQueue,                      \
  Queue*:                listAddFrontU16PQueueP,                     \
  const volatile Queue*: listAddFrontU16PQueueP,                     \
  Stack:                 listAddFrontU16PStack,                      \
  Stack*:                listAddFrontU16PStackP,                     \
  const volatile Stack*: listAddFrontU16PStackP,                     \
  RedBlackTree:          listAddFrontU16PRedBlackTree,               \
  RedBlackTree*:         listAddFrontU16PRedBlackTreeP,              \
  const volatile RedBlackTree*: listAddFrontU16PRedBlackTreeP,              \
  HashTable:             listAddFrontU16PHashTable,                  \
  HashTable*:            listAddFrontU16PHashTableP,                 \
  const volatile HashTable*: listAddFrontU16PHashTableP,                 \
  Vector:                listAddFrontU16PVector,                     \
  Vector*:               listAddFrontU16PVectorP,                    \
  const volatile Vector*: listAddFrontU16PVectorP,                    \
  char*:                 listAddFrontU16PString,                     \
  const volatile char*:  listAddFrontU16PString,                     \
  char**:                listAddFrontU16PStringP,                    \
  const volatile char**: listAddFrontU16PStringP,                    \
  Bytes:                 listAddFrontU16PBytes,                      \
  Bytes*:                listAddFrontU16PBytesP,                     \
  const volatile Bytes*: listAddFrontU16PBytesP,                     \
  void*:                 listAddFrontU16PPointer,                    \
  void**:                listAddFrontU16PPointerP,                   \
  const volatile void**: listAddFrontU16PPointerP,                   \
  i8:                    listAddFrontU16I8,                          \
  u8:                    listAddFrontU16U8                           \

#define listAddFrontU16P(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_U16P_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_I32P_KEY(dataStructure, key, value) \
  bool:                  listAddFrontI32PBool,                       \
  bool*:                 listAddFrontI32PBoolP,                      \
  const volatile bool*:  listAddFrontI32PBoolP,                      \
  i16:                   listAddFrontI32PI16,                        \
  i16*:                  listAddFrontI32PI16P,                       \
  const volatile i16*:   listAddFrontI32PI16P,                       \
  u16:                   listAddFrontI32PU16,                        \
  u16*:                  listAddFrontI32PU16P,                       \
  const volatile u16*:   listAddFrontI32PU16P,                       \
  i32:                   listAddFrontI32PI32,                        \
  i32*:                  listAddFrontI32PI32P,                       \
  const volatile i32*:   listAddFrontI32PI32P,                       \
  u32:                   listAddFrontI32PU32,                        \
  u32*:                  listAddFrontI32PU32P,                       \
  const volatile u32*:   listAddFrontI32PU32P,                       \
  i64:                   listAddFrontI32PI64,                        \
  i64*:                  listAddFrontI32PI64P,                       \
  const volatile i64*:   listAddFrontI32PI64P,                       \
  u64:                   listAddFrontI32PU64,                        \
  u64*:                  listAddFrontI32PU64P,                       \
  const volatile u64*:   listAddFrontI32PU64P,                       \
  float:                 listAddFrontI32PFloat,                      \
  float*:                listAddFrontI32PFloatP,                     \
  const volatile float*: listAddFrontI32PFloatP,                     \
  double:                listAddFrontI32PDouble,                     \
  double*:               listAddFrontI32PDoubleP,                    \
  const volatile double*: listAddFrontI32PDoubleP,                    \
  long double:           listAddFrontI32PLongDouble,                 \
  long double*:          listAddFrontI32PLongDoubleP,                \
  const volatile long double*: listAddFrontI32PLongDoubleP,                \
  List:                  listAddFrontI32PList,                       \
  List*:                 listAddFrontI32PListP,                      \
  const volatile List*:  listAddFrontI32PListP,                      \
  Queue:                 listAddFrontI32PQueue,                      \
  Queue*:                listAddFrontI32PQueueP,                     \
  const volatile Queue*: listAddFrontI32PQueueP,                     \
  Stack:                 listAddFrontI32PStack,                      \
  Stack*:                listAddFrontI32PStackP,                     \
  const volatile Stack*: listAddFrontI32PStackP,                     \
  RedBlackTree:          listAddFrontI32PRedBlackTree,               \
  RedBlackTree*:         listAddFrontI32PRedBlackTreeP,              \
  const volatile RedBlackTree*: listAddFrontI32PRedBlackTreeP,              \
  HashTable:             listAddFrontI32PHashTable,                  \
  HashTable*:            listAddFrontI32PHashTableP,                 \
  const volatile HashTable*: listAddFrontI32PHashTableP,                 \
  Vector:                listAddFrontI32PVector,                     \
  Vector*:               listAddFrontI32PVectorP,                    \
  const volatile Vector*: listAddFrontI32PVectorP,                    \
  char*:                 listAddFrontI32PString,                     \
  const volatile char*:  listAddFrontI32PString,                     \
  char**:                listAddFrontI32PStringP,                    \
  const volatile char**: listAddFrontI32PStringP,                    \
  Bytes:                 listAddFrontI32PBytes,                      \
  Bytes*:                listAddFrontI32PBytesP,                     \
  const volatile Bytes*: listAddFrontI32PBytesP,                     \
  void*:                 listAddFrontI32PPointer,                    \
  void**:                listAddFrontI32PPointerP,                   \
  const volatile void**: listAddFrontI32PPointerP,                   \
  i8:                    listAddFrontI32I8,                          \
  u8:                    listAddFrontI32U8                           \

#define listAddFrontI32P(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_I32P_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_U32P_KEY(dataStructure, key, value) \
  bool:                  listAddFrontU32PBool,                       \
  bool*:                 listAddFrontU32PBoolP,                      \
  const volatile bool*:  listAddFrontU32PBoolP,                      \
  i16:                   listAddFrontU32PI16,                        \
  i16*:                  listAddFrontU32PI16P,                       \
  const volatile i16*:   listAddFrontU32PI16P,                       \
  u16:                   listAddFrontU32PU16,                        \
  u16*:                  listAddFrontU32PU16P,                       \
  const volatile u16*:   listAddFrontU32PU16P,                       \
  i32:                   listAddFrontU32PI32,                        \
  i32*:                  listAddFrontU32PI32P,                       \
  const volatile i32*:   listAddFrontU32PI32P,                       \
  u32:                   listAddFrontU32PU32,                        \
  u32*:                  listAddFrontU32PU32P,                       \
  const volatile u32*:   listAddFrontU32PU32P,                       \
  i64:                   listAddFrontU32PI64,                        \
  i64*:                  listAddFrontU32PI64P,                       \
  const volatile i64*:   listAddFrontU32PI64P,                       \
  u64:                   listAddFrontU32PU64,                        \
  u64*:                  listAddFrontU32PU64P,                       \
  const volatile u64*:   listAddFrontU32PU64P,                       \
  float:                 listAddFrontU32PFloat,                      \
  float*:                listAddFrontU32PFloatP,                     \
  const volatile float*: listAddFrontU32PFloatP,                     \
  double:                listAddFrontU32PDouble,                     \
  double*:               listAddFrontU32PDoubleP,                    \
  const volatile double*: listAddFrontU32PDoubleP,                    \
  long double:           listAddFrontU32PLongDouble,                 \
  long double*:          listAddFrontU32PLongDoubleP,                \
  const volatile long double*: listAddFrontU32PLongDoubleP,                \
  List:                  listAddFrontU32PList,                       \
  List*:                 listAddFrontU32PListP,                      \
  const volatile List*:  listAddFrontU32PListP,                      \
  Queue:                 listAddFrontU32PQueue,                      \
  Queue*:                listAddFrontU32PQueueP,                     \
  const volatile Queue*: listAddFrontU32PQueueP,                     \
  Stack:                 listAddFrontU32PStack,                      \
  Stack*:                listAddFrontU32PStackP,                     \
  const volatile Stack*: listAddFrontU32PStackP,                     \
  RedBlackTree:          listAddFrontU32PRedBlackTree,               \
  RedBlackTree*:         listAddFrontU32PRedBlackTreeP,              \
  const volatile RedBlackTree*: listAddFrontU32PRedBlackTreeP,              \
  HashTable:             listAddFrontU32PHashTable,                  \
  HashTable*:            listAddFrontU32PHashTableP,                 \
  const volatile HashTable*: listAddFrontU32PHashTableP,                 \
  Vector:                listAddFrontU32PVector,                     \
  Vector*:               listAddFrontU32PVectorP,                    \
  const volatile Vector*: listAddFrontU32PVectorP,                    \
  char*:                 listAddFrontU32PString,                     \
  const volatile char*:  listAddFrontU32PString,                     \
  char**:                listAddFrontU32PStringP,                    \
  const volatile char**: listAddFrontU32PStringP,                    \
  Bytes:                 listAddFrontU32PBytes,                      \
  Bytes*:                listAddFrontU32PBytesP,                     \
  const volatile Bytes*: listAddFrontU32PBytesP,                     \
  void*:                 listAddFrontU32PPointer,                    \
  void**:                listAddFrontU32PPointerP,                   \
  const volatile void**: listAddFrontU32PPointerP,                   \
  i8:                    listAddFrontU32I8,                          \
  u8:                    listAddFrontU32U8                           \

#define listAddFrontU32P(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_U32P_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_I64P_KEY(dataStructure, key, value) \
  bool:                  listAddFrontI64PBool,                       \
  bool*:                 listAddFrontI64PBoolP,                      \
  const volatile bool*:  listAddFrontI64PBoolP,                      \
  i16:                   listAddFrontI64PI16,                        \
  i16*:                  listAddFrontI64PI16P,                       \
  const volatile i16*:   listAddFrontI64PI16P,                       \
  u16:                   listAddFrontI64PU16,                        \
  u16*:                  listAddFrontI64PU16P,                       \
  const volatile u16*:   listAddFrontI64PU16P,                       \
  i32:                   listAddFrontI64PI32,                        \
  i32*:                  listAddFrontI64PI32P,                       \
  const volatile i32*:   listAddFrontI64PI32P,                       \
  u32:                   listAddFrontI64PU32,                        \
  u32*:                  listAddFrontI64PU32P,                       \
  const volatile u32*:   listAddFrontI64PU32P,                       \
  i64:                   listAddFrontI64PI64,                        \
  i64*:                  listAddFrontI64PI64P,                       \
  const volatile i64*:   listAddFrontI64PI64P,                       \
  u64:                   listAddFrontI64PU64,                        \
  u64*:                  listAddFrontI64PU64P,                       \
  const volatile u64*:   listAddFrontI64PU64P,                       \
  float:                 listAddFrontI64PFloat,                      \
  float*:                listAddFrontI64PFloatP,                     \
  const volatile float*: listAddFrontI64PFloatP,                     \
  double:                listAddFrontI64PDouble,                     \
  double*:               listAddFrontI64PDoubleP,                    \
  const volatile double*: listAddFrontI64PDoubleP,                    \
  long double:           listAddFrontI64PLongDouble,                 \
  long double*:          listAddFrontI64PLongDoubleP,                \
  const volatile long double*: listAddFrontI64PLongDoubleP,                \
  List:                  listAddFrontI64PList,                       \
  List*:                 listAddFrontI64PListP,                      \
  const volatile List*:  listAddFrontI64PListP,                      \
  Queue:                 listAddFrontI64PQueue,                      \
  Queue*:                listAddFrontI64PQueueP,                     \
  const volatile Queue*: listAddFrontI64PQueueP,                     \
  Stack:                 listAddFrontI64PStack,                      \
  Stack*:                listAddFrontI64PStackP,                     \
  const volatile Stack*: listAddFrontI64PStackP,                     \
  RedBlackTree:          listAddFrontI64PRedBlackTree,               \
  RedBlackTree*:         listAddFrontI64PRedBlackTreeP,              \
  const volatile RedBlackTree*: listAddFrontI64PRedBlackTreeP,              \
  HashTable:             listAddFrontI64PHashTable,                  \
  HashTable*:            listAddFrontI64PHashTableP,                 \
  const volatile HashTable*: listAddFrontI64PHashTableP,                 \
  Vector:                listAddFrontI64PVector,                     \
  Vector*:               listAddFrontI64PVectorP,                    \
  const volatile Vector*: listAddFrontI64PVectorP,                    \
  char*:                 listAddFrontI64PString,                     \
  const volatile char*:  listAddFrontI64PString,                     \
  char**:                listAddFrontI64PStringP,                    \
  const volatile char**: listAddFrontI64PStringP,                    \
  Bytes:                 listAddFrontI64PBytes,                      \
  Bytes*:                listAddFrontI64PBytesP,                     \
  const volatile Bytes*: listAddFrontI64PBytesP,                     \
  void*:                 listAddFrontI64PPointer,                    \
  void**:                listAddFrontI64PPointerP,                   \
  const volatile void**: listAddFrontI64PPointerP,                   \
  i8:                    listAddFrontI64I8,                          \
  u8:                    listAddFrontI64U8                           \

#define listAddFrontI64P(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_I64P_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_U64P_KEY(dataStructure, key, value) \
  bool:                  listAddFrontU64PBool,                       \
  bool*:                 listAddFrontU64PBoolP,                      \
  const volatile bool*:  listAddFrontU64PBoolP,                      \
  i16:                   listAddFrontU64PI16,                        \
  i16*:                  listAddFrontU64PI16P,                       \
  const volatile i16*:   listAddFrontU64PI16P,                       \
  u16:                   listAddFrontU64PU16,                        \
  u16*:                  listAddFrontU64PU16P,                       \
  const volatile u16*:   listAddFrontU64PU16P,                       \
  i32:                   listAddFrontU64PI32,                        \
  i32*:                  listAddFrontU64PI32P,                       \
  const volatile i32*:   listAddFrontU64PI32P,                       \
  u32:                   listAddFrontU64PU32,                        \
  u32*:                  listAddFrontU64PU32P,                       \
  const volatile u32*:   listAddFrontU64PU32P,                       \
  i64:                   listAddFrontU64PI64,                        \
  i64*:                  listAddFrontU64PI64P,                       \
  const volatile i64*:   listAddFrontU64PI64P,                       \
  u64:                   listAddFrontU64PU64,                        \
  u64*:                  listAddFrontU64PU64P,                       \
  const volatile u64*:   listAddFrontU64PU64P,                       \
  float:                 listAddFrontU64PFloat,                      \
  float*:                listAddFrontU64PFloatP,                     \
  const volatile float*: listAddFrontU64PFloatP,                     \
  double:                listAddFrontU64PDouble,                     \
  double*:               listAddFrontU64PDoubleP,                    \
  const volatile double*: listAddFrontU64PDoubleP,                    \
  long double:           listAddFrontU64PLongDouble,                 \
  long double*:          listAddFrontU64PLongDoubleP,                \
  const volatile long double*: listAddFrontU64PLongDoubleP,                \
  List:                  listAddFrontU64PList,                       \
  List*:                 listAddFrontU64PListP,                      \
  const volatile List*:  listAddFrontU64PListP,                      \
  Queue:                 listAddFrontU64PQueue,                      \
  Queue*:                listAddFrontU64PQueueP,                     \
  const volatile Queue*: listAddFrontU64PQueueP,                     \
  Stack:                 listAddFrontU64PStack,                      \
  Stack*:                listAddFrontU64PStackP,                     \
  const volatile Stack*: listAddFrontU64PStackP,                     \
  RedBlackTree:          listAddFrontU64PRedBlackTree,               \
  RedBlackTree*:         listAddFrontU64PRedBlackTreeP,              \
  const volatile RedBlackTree*: listAddFrontU64PRedBlackTreeP,              \
  HashTable:             listAddFrontU64PHashTable,                  \
  HashTable*:            listAddFrontU64PHashTableP,                 \
  const volatile HashTable*: listAddFrontU64PHashTableP,                 \
  Vector:                listAddFrontU64PVector,                     \
  Vector*:               listAddFrontU64PVectorP,                    \
  const volatile Vector*: listAddFrontU64PVectorP,                    \
  char*:                 listAddFrontU64PString,                     \
  const volatile char*:  listAddFrontU64PString,                     \
  char**:                listAddFrontU64PStringP,                    \
  const volatile char**: listAddFrontU64PStringP,                    \
  Bytes:                 listAddFrontU64PBytes,                      \
  Bytes*:                listAddFrontU64PBytesP,                     \
  const volatile Bytes*: listAddFrontU64PBytesP,                     \
  void*:                 listAddFrontU64PPointer,                    \
  void**:                listAddFrontU64PPointerP,                   \
  const volatile void**: listAddFrontU64PPointerP,                   \
  i8:                    listAddFrontU64I8,                          \
  u8:                    listAddFrontU64U8                           \

#define listAddFrontU64P(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_U64P_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_FLOATP_KEY(dataStructure, key, value) \
  bool:                  listAddFrontFloatPBool,                     \
  bool*:                 listAddFrontFloatPBoolP,                    \
  const volatile bool*:  listAddFrontFloatPBoolP,                    \
  i16:                   listAddFrontFloatPI16,                      \
  i16*:                  listAddFrontFloatPI16P,                     \
  const volatile i16*:   listAddFrontFloatPI16P,                     \
  u16:                   listAddFrontFloatPU16,                      \
  u16*:                  listAddFrontFloatPU16P,                     \
  const volatile u16*:   listAddFrontFloatPU16P,                     \
  i32:                   listAddFrontFloatPI32,                      \
  i32*:                  listAddFrontFloatPI32P,                     \
  const volatile i32*:   listAddFrontFloatPI32P,                     \
  u32:                   listAddFrontFloatPU32,                      \
  u32*:                  listAddFrontFloatPU32P,                     \
  const volatile u32*:   listAddFrontFloatPU32P,                     \
  i64:                   listAddFrontFloatPI64,                      \
  i64*:                  listAddFrontFloatPI64P,                     \
  const volatile i64*:   listAddFrontFloatPI64P,                     \
  u64:                   listAddFrontFloatPU64,                      \
  u64*:                  listAddFrontFloatPU64P,                     \
  const volatile u64*:   listAddFrontFloatPU64P,                     \
  float:                 listAddFrontFloatPFloat,                    \
  float*:                listAddFrontFloatPFloatP,                   \
  const volatile float*: listAddFrontFloatPFloatP,                   \
  double:                listAddFrontFloatPDouble,                   \
  double*:               listAddFrontFloatPDoubleP,                  \
  const volatile double*: listAddFrontFloatPDoubleP,                  \
  long double:           listAddFrontFloatPLongDouble,               \
  long double*:          listAddFrontFloatPLongDoubleP,              \
  const volatile long double*: listAddFrontFloatPLongDoubleP,              \
  List:                  listAddFrontFloatPList,                     \
  List*:                 listAddFrontFloatPListP,                    \
  const volatile List*:  listAddFrontFloatPListP,                    \
  Queue:                 listAddFrontFloatPQueue,                    \
  Queue*:                listAddFrontFloatPQueueP,                   \
  const volatile Queue*: listAddFrontFloatPQueueP,                   \
  Stack:                 listAddFrontFloatPStack,                    \
  Stack*:                listAddFrontFloatPStackP,                   \
  const volatile Stack*: listAddFrontFloatPStackP,                   \
  RedBlackTree:          listAddFrontFloatPRedBlackTree,             \
  RedBlackTree*:         listAddFrontFloatPRedBlackTreeP,            \
  const volatile RedBlackTree*: listAddFrontFloatPRedBlackTreeP,            \
  HashTable:             listAddFrontFloatPHashTable,                \
  HashTable*:            listAddFrontFloatPHashTableP,               \
  const volatile HashTable*: listAddFrontFloatPHashTableP,               \
  Vector:                listAddFrontFloatPVector,                   \
  Vector*:               listAddFrontFloatPVectorP,                  \
  const volatile Vector*: listAddFrontFloatPVectorP,                  \
  char*:                 listAddFrontFloatPString,                   \
  const volatile char*:  listAddFrontFloatPString,                   \
  char**:                listAddFrontFloatPStringP,                  \
  const volatile char**: listAddFrontFloatPStringP,                  \
  Bytes:                 listAddFrontFloatPBytes,                    \
  Bytes*:                listAddFrontFloatPBytesP,                   \
  const volatile Bytes*: listAddFrontFloatPBytesP,                   \
  void*:                 listAddFrontFloatPPointer,                  \
  void**:                listAddFrontFloatPPointerP,                 \
  const volatile void**: listAddFrontFloatPPointerP,                 \
  i8:                    listAddFrontFloatI8,                        \
  u8:                    listAddFrontFloatU8                         \

#define listAddFrontFloatP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_FLOATP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_DOUBLEP_KEY(dataStructure, key, value) \
  bool:                  listAddFrontDoublePBool,                    \
  bool*:                 listAddFrontDoublePBoolP,                   \
  const volatile bool*:  listAddFrontDoublePBoolP,                   \
  i16:                   listAddFrontDoublePI16,                     \
  i16*:                  listAddFrontDoublePI16P,                    \
  const volatile i16*:   listAddFrontDoublePI16P,                    \
  u16:                   listAddFrontDoublePU16,                     \
  u16*:                  listAddFrontDoublePU16P,                    \
  const volatile u16*:   listAddFrontDoublePU16P,                    \
  i32:                   listAddFrontDoublePI32,                     \
  i32*:                  listAddFrontDoublePI32P,                    \
  const volatile i32*:   listAddFrontDoublePI32P,                    \
  u32:                   listAddFrontDoublePU32,                     \
  u32*:                  listAddFrontDoublePU32P,                    \
  const volatile u32*:   listAddFrontDoublePU32P,                    \
  i64:                   listAddFrontDoublePI64,                     \
  i64*:                  listAddFrontDoublePI64P,                    \
  const volatile i64*:   listAddFrontDoublePI64P,                    \
  u64:                   listAddFrontDoublePU64,                     \
  u64*:                  listAddFrontDoublePU64P,                    \
  const volatile u64*:   listAddFrontDoublePU64P,                    \
  float:                 listAddFrontDoublePFloat,                   \
  float*:                listAddFrontDoublePFloatP,                  \
  const volatile float*: listAddFrontDoublePFloatP,                  \
  double:                listAddFrontDoublePDouble,                  \
  double*:               listAddFrontDoublePDoubleP,                 \
  const volatile double*: listAddFrontDoublePDoubleP,                 \
  long double:           listAddFrontDoublePLongDouble,              \
  long double*:          listAddFrontDoublePLongDoubleP,             \
  const volatile long double*: listAddFrontDoublePLongDoubleP,             \
  List:                  listAddFrontDoublePList,                    \
  List*:                 listAddFrontDoublePListP,                   \
  const volatile List*:  listAddFrontDoublePListP,                   \
  Queue:                 listAddFrontDoublePQueue,                   \
  Queue*:                listAddFrontDoublePQueueP,                  \
  const volatile Queue*: listAddFrontDoublePQueueP,                  \
  Stack:                 listAddFrontDoublePStack,                   \
  Stack*:                listAddFrontDoublePStackP,                  \
  const volatile Stack*: listAddFrontDoublePStackP,                  \
  RedBlackTree:          listAddFrontDoublePRedBlackTree,            \
  RedBlackTree*:         listAddFrontDoublePRedBlackTreeP,           \
  const volatile RedBlackTree*: listAddFrontDoublePRedBlackTreeP,           \
  HashTable:             listAddFrontDoublePHashTable,               \
  HashTable*:            listAddFrontDoublePHashTableP,              \
  const volatile HashTable*: listAddFrontDoublePHashTableP,              \
  Vector:                listAddFrontDoublePVector,                  \
  Vector*:               listAddFrontDoublePVectorP,                 \
  const volatile Vector*: listAddFrontDoublePVectorP,                 \
  char*:                 listAddFrontDoublePString,                  \
  const volatile char*:  listAddFrontDoublePString,                  \
  char**:                listAddFrontDoublePStringP,                 \
  const volatile char**: listAddFrontDoublePStringP,                 \
  Bytes:                 listAddFrontDoublePBytes,                   \
  Bytes*:                listAddFrontDoublePBytesP,                  \
  const volatile Bytes*: listAddFrontDoublePBytesP,                  \
  void*:                 listAddFrontDoublePPointer,                 \
  void**:                listAddFrontDoublePPointerP,                \
  const volatile void**: listAddFrontDoublePPointerP,                \
  i8:                    listAddFrontDoubleI8,                       \
  u8:                    listAddFrontDoubleU8                        \

#define listAddFrontDoubleP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_DOUBLEP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_LONG_DOUBLEP_KEY(dataStructure, key, value) \
  bool:                  listAddFrontLongDoublePBool,                \
  bool*:                 listAddFrontLongDoublePBoolP,               \
  const volatile bool*:  listAddFrontLongDoublePBoolP,               \
  i16:                   listAddFrontLongDoublePI16,                 \
  i16*:                  listAddFrontLongDoublePI16P,                \
  const volatile i16*:   listAddFrontLongDoublePI16P,                \
  u16:                   listAddFrontLongDoublePU16,                 \
  u16*:                  listAddFrontLongDoublePU16P,                \
  const volatile u16*:   listAddFrontLongDoublePU16P,                \
  i32:                   listAddFrontLongDoublePI32,                 \
  i32*:                  listAddFrontLongDoublePI32P,                \
  const volatile i32*:   listAddFrontLongDoublePI32P,                \
  u32:                   listAddFrontLongDoublePU32,                 \
  u32*:                  listAddFrontLongDoublePU32P,                \
  const volatile u32*:   listAddFrontLongDoublePU32P,                \
  i64:                   listAddFrontLongDoublePI64,                 \
  i64*:                  listAddFrontLongDoublePI64P,                \
  const volatile i64*:   listAddFrontLongDoublePI64P,                \
  u64:                   listAddFrontLongDoublePU64,                 \
  u64*:                  listAddFrontLongDoublePU64P,                \
  const volatile u64*:   listAddFrontLongDoublePU64P,                \
  float:                 listAddFrontLongDoublePFloat,               \
  float*:                listAddFrontLongDoublePFloatP,              \
  const volatile float*: listAddFrontLongDoublePFloatP,              \
  double:                listAddFrontLongDoublePDouble,              \
  double*:               listAddFrontLongDoublePDoubleP,             \
  const volatile double*: listAddFrontLongDoublePDoubleP,             \
  long double:           listAddFrontLongDoublePLongDouble,          \
  long double*:          listAddFrontLongDoublePLongDoubleP,         \
  const volatile long double*: listAddFrontLongDoublePLongDoubleP,         \
  List:                  listAddFrontLongDoublePList,                \
  List*:                 listAddFrontLongDoublePListP,               \
  const volatile List*:  listAddFrontLongDoublePListP,               \
  Queue:                 listAddFrontLongDoublePQueue,               \
  Queue*:                listAddFrontLongDoublePQueueP,              \
  const volatile Queue*: listAddFrontLongDoublePQueueP,              \
  Stack:                 listAddFrontLongDoublePStack,               \
  Stack*:                listAddFrontLongDoublePStackP,              \
  const volatile Stack*: listAddFrontLongDoublePStackP,              \
  RedBlackTree:          listAddFrontLongDoublePRedBlackTree,        \
  RedBlackTree*:         listAddFrontLongDoublePRedBlackTreeP,       \
  const volatile RedBlackTree*: listAddFrontLongDoublePRedBlackTreeP,       \
  HashTable:             listAddFrontLongDoublePHashTable,           \
  HashTable*:            listAddFrontLongDoublePHashTableP,          \
  const volatile HashTable*: listAddFrontLongDoublePHashTableP,          \
  Vector:                listAddFrontLongDoublePVector,              \
  Vector*:               listAddFrontLongDoublePVectorP,             \
  const volatile Vector*: listAddFrontLongDoublePVectorP,             \
  char*:                 listAddFrontLongDoublePString,              \
  const volatile char*:  listAddFrontLongDoublePString,              \
  char**:                listAddFrontLongDoublePStringP,             \
  const volatile char**: listAddFrontLongDoublePStringP,             \
  Bytes:                 listAddFrontLongDoublePBytes,               \
  Bytes*:                listAddFrontLongDoublePBytesP,              \
  const volatile Bytes*: listAddFrontLongDoublePBytesP,              \
  void*:                 listAddFrontLongDoublePPointer,             \
  void**:                listAddFrontLongDoublePPointerP,            \
  const volatile void**: listAddFrontLongDoublePPointerP,            \
  i8:                    listAddFrontLongDoubleI8,                   \
  u8:                    listAddFrontLongDoubleU8                    \

#define listAddFrontLongDoubleP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_LONG_DOUBLEP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_LISTP_KEY(dataStructure, key, value) \
  bool:                  listAddFrontListPBool,                      \
  bool*:                 listAddFrontListPBoolP,                     \
  const volatile bool*:  listAddFrontListPBoolP,                     \
  i16:                   listAddFrontListPI16,                       \
  i16*:                  listAddFrontListPI16P,                      \
  const volatile i16*:   listAddFrontListPI16P,                      \
  u16:                   listAddFrontListPU16,                       \
  u16*:                  listAddFrontListPU16P,                      \
  const volatile u16*:   listAddFrontListPU16P,                      \
  i32:                   listAddFrontListPI32,                       \
  i32*:                  listAddFrontListPI32P,                      \
  const volatile i32*:   listAddFrontListPI32P,                      \
  u32:                   listAddFrontListPU32,                       \
  u32*:                  listAddFrontListPU32P,                      \
  const volatile u32*:   listAddFrontListPU32P,                      \
  i64:                   listAddFrontListPI64,                       \
  i64*:                  listAddFrontListPI64P,                      \
  const volatile i64*:   listAddFrontListPI64P,                      \
  u64:                   listAddFrontListPU64,                       \
  u64*:                  listAddFrontListPU64P,                      \
  const volatile u64*:   listAddFrontListPU64P,                      \
  float:                 listAddFrontListPFloat,                     \
  float*:                listAddFrontListPFloatP,                    \
  const volatile float*: listAddFrontListPFloatP,                    \
  double:                listAddFrontListPDouble,                    \
  double*:               listAddFrontListPDoubleP,                   \
  const volatile double*: listAddFrontListPDoubleP,                   \
  long double:           listAddFrontListPLongDouble,                \
  long double*:          listAddFrontListPLongDoubleP,               \
  const volatile long double*: listAddFrontListPLongDoubleP,               \
  List:                  listAddFrontListPList,                      \
  List*:                 listAddFrontListPListP,                     \
  const volatile List*:  listAddFrontListPListP,                     \
  Queue:                 listAddFrontListPQueue,                     \
  Queue*:                listAddFrontListPQueueP,                    \
  const volatile Queue*: listAddFrontListPQueueP,                    \
  Stack:                 listAddFrontListPStack,                     \
  Stack*:                listAddFrontListPStackP,                    \
  const volatile Stack*: listAddFrontListPStackP,                    \
  RedBlackTree:          listAddFrontListPRedBlackTree,              \
  RedBlackTree*:         listAddFrontListPRedBlackTreeP,             \
  const volatile RedBlackTree*: listAddFrontListPRedBlackTreeP,             \
  HashTable:             listAddFrontListPHashTable,                 \
  HashTable*:            listAddFrontListPHashTableP,                \
  const volatile HashTable*: listAddFrontListPHashTableP,                \
  Vector:                listAddFrontListPVector,                    \
  Vector*:               listAddFrontListPVectorP,                   \
  const volatile Vector*: listAddFrontListPVectorP,                   \
  char*:                 listAddFrontListPString,                    \
  const volatile char*:  listAddFrontListPString,                    \
  char**:                listAddFrontListPStringP,                   \
  const volatile char**: listAddFrontListPStringP,                   \
  Bytes:                 listAddFrontListPBytes,                     \
  Bytes*:                listAddFrontListPBytesP,                    \
  const volatile Bytes*: listAddFrontListPBytesP,                    \
  void*:                 listAddFrontListPPointer,                   \
  void**:                listAddFrontListPPointerP,                  \
  const volatile void**: listAddFrontListPPointerP,                  \
  i8:                    listAddFrontListI8,                         \
  u8:                    listAddFrontListU8                          \

#define listAddFrontListP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_LISTP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_QUEUEP_KEY(dataStructure, key, value) \
  bool:                  listAddFrontQueuePBool,                     \
  bool*:                 listAddFrontQueuePBoolP,                    \
  const volatile bool*:  listAddFrontQueuePBoolP,                    \
  i16:                   listAddFrontQueuePI16,                      \
  i16*:                  listAddFrontQueuePI16P,                     \
  const volatile i16*:   listAddFrontQueuePI16P,                     \
  u16:                   listAddFrontQueuePU16,                      \
  u16*:                  listAddFrontQueuePU16P,                     \
  const volatile u16*:   listAddFrontQueuePU16P,                     \
  i32:                   listAddFrontQueuePI32,                      \
  i32*:                  listAddFrontQueuePI32P,                     \
  const volatile i32*:   listAddFrontQueuePI32P,                     \
  u32:                   listAddFrontQueuePU32,                      \
  u32*:                  listAddFrontQueuePU32P,                     \
  const volatile u32*:   listAddFrontQueuePU32P,                     \
  i64:                   listAddFrontQueuePI64,                      \
  i64*:                  listAddFrontQueuePI64P,                     \
  const volatile i64*:   listAddFrontQueuePI64P,                     \
  u64:                   listAddFrontQueuePU64,                      \
  u64*:                  listAddFrontQueuePU64P,                     \
  const volatile u64*:   listAddFrontQueuePU64P,                     \
  float:                 listAddFrontQueuePFloat,                    \
  float*:                listAddFrontQueuePFloatP,                   \
  const volatile float*: listAddFrontQueuePFloatP,                   \
  double:                listAddFrontQueuePDouble,                   \
  double*:               listAddFrontQueuePDoubleP,                  \
  const volatile double*: listAddFrontQueuePDoubleP,                  \
  long double:           listAddFrontQueuePLongDouble,               \
  long double*:          listAddFrontQueuePLongDoubleP,              \
  const volatile long double*: listAddFrontQueuePLongDoubleP,              \
  List:                  listAddFrontQueuePList,                     \
  List*:                 listAddFrontQueuePListP,                    \
  const volatile List*:  listAddFrontQueuePListP,                    \
  Queue:                 listAddFrontQueuePQueue,                    \
  Queue*:                listAddFrontQueuePQueueP,                   \
  const volatile Queue*: listAddFrontQueuePQueueP,                   \
  Stack:                 listAddFrontQueuePStack,                    \
  Stack*:                listAddFrontQueuePStackP,                   \
  const volatile Stack*: listAddFrontQueuePStackP,                   \
  RedBlackTree:          listAddFrontQueuePRedBlackTree,             \
  RedBlackTree*:         listAddFrontQueuePRedBlackTreeP,            \
  const volatile RedBlackTree*: listAddFrontQueuePRedBlackTreeP,            \
  HashTable:             listAddFrontQueuePHashTable,                \
  HashTable*:            listAddFrontQueuePHashTableP,               \
  const volatile HashTable*: listAddFrontQueuePHashTableP,               \
  Vector:                listAddFrontQueuePVector,                   \
  Vector*:               listAddFrontQueuePVectorP,                  \
  const volatile Vector*: listAddFrontQueuePVectorP,                  \
  char*:                 listAddFrontQueuePString,                   \
  const volatile char*:  listAddFrontQueuePString,                   \
  char**:                listAddFrontQueuePStringP,                  \
  const volatile char**: listAddFrontQueuePStringP,                  \
  Bytes:                 listAddFrontQueuePBytes,                    \
  Bytes*:                listAddFrontQueuePBytesP,                   \
  const volatile Bytes*: listAddFrontQueuePBytesP,                   \
  void*:                 listAddFrontQueuePPointer,                  \
  void**:                listAddFrontQueuePPointerP,                 \
  const volatile void**: listAddFrontQueuePPointerP,                 \
  i8:                    listAddFrontQueueI8,                        \
  u8:                    listAddFrontQueueU8                         \

#define listAddFrontQueueP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_QUEUEP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_STACKP_KEY(dataStructure, key, value) \
  bool:                  listAddFrontStackPBool,                     \
  bool*:                 listAddFrontStackPBoolP,                    \
  const volatile bool*:  listAddFrontStackPBoolP,                    \
  i16:                   listAddFrontStackPI16,                      \
  i16*:                  listAddFrontStackPI16P,                     \
  const volatile i16*:   listAddFrontStackPI16P,                     \
  u16:                   listAddFrontStackPU16,                      \
  u16*:                  listAddFrontStackPU16P,                     \
  const volatile u16*:   listAddFrontStackPU16P,                     \
  i32:                   listAddFrontStackPI32,                      \
  i32*:                  listAddFrontStackPI32P,                     \
  const volatile i32*:   listAddFrontStackPI32P,                     \
  u32:                   listAddFrontStackPU32,                      \
  u32*:                  listAddFrontStackPU32P,                     \
  const volatile u32*:   listAddFrontStackPU32P,                     \
  i64:                   listAddFrontStackPI64,                      \
  i64*:                  listAddFrontStackPI64P,                     \
  const volatile i64*:   listAddFrontStackPI64P,                     \
  u64:                   listAddFrontStackPU64,                      \
  u64*:                  listAddFrontStackPU64P,                     \
  const volatile u64*:   listAddFrontStackPU64P,                     \
  float:                 listAddFrontStackPFloat,                    \
  float*:                listAddFrontStackPFloatP,                   \
  const volatile float*: listAddFrontStackPFloatP,                   \
  double:                listAddFrontStackPDouble,                   \
  double*:               listAddFrontStackPDoubleP,                  \
  const volatile double*: listAddFrontStackPDoubleP,                  \
  long double:           listAddFrontStackPLongDouble,               \
  long double*:          listAddFrontStackPLongDoubleP,              \
  const volatile long double*: listAddFrontStackPLongDoubleP,              \
  List:                  listAddFrontStackPList,                     \
  List*:                 listAddFrontStackPListP,                    \
  const volatile List*:  listAddFrontStackPListP,                    \
  Queue:                 listAddFrontStackPQueue,                    \
  Queue*:                listAddFrontStackPQueueP,                   \
  const volatile Queue*: listAddFrontStackPQueueP,                   \
  Stack:                 listAddFrontStackPStack,                    \
  Stack*:                listAddFrontStackPStackP,                   \
  const volatile Stack*: listAddFrontStackPStackP,                   \
  RedBlackTree:          listAddFrontStackPRedBlackTree,             \
  RedBlackTree*:         listAddFrontStackPRedBlackTreeP,            \
  const volatile RedBlackTree*: listAddFrontStackPRedBlackTreeP,            \
  HashTable:             listAddFrontStackPHashTable,                \
  HashTable*:            listAddFrontStackPHashTableP,               \
  const volatile HashTable*: listAddFrontStackPHashTableP,               \
  Vector:                listAddFrontStackPVector,                   \
  Vector*:               listAddFrontStackPVectorP,                  \
  const volatile Vector*: listAddFrontStackPVectorP,                  \
  char*:                 listAddFrontStackPString,                   \
  const volatile char*:  listAddFrontStackPString,                   \
  char**:                listAddFrontStackPStringP,                  \
  const volatile char**: listAddFrontStackPStringP,                  \
  Bytes:                 listAddFrontStackPBytes,                    \
  Bytes*:                listAddFrontStackPBytesP,                   \
  const volatile Bytes*: listAddFrontStackPBytesP,                   \
  void*:                 listAddFrontStackPPointer,                  \
  void**:                listAddFrontStackPPointerP,                 \
  const volatile void**: listAddFrontStackPPointerP,                 \
  i8:                    listAddFrontStackI8,                        \
  u8:                    listAddFrontStackU8                         \

#define listAddFrontStackP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_STACKP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_RED_BLACK_TREEP_KEY(dataStructure, key, value) \
  bool:                  listAddFrontRedBlackTreePBool,              \
  bool*:                 listAddFrontRedBlackTreePBoolP,             \
  const volatile bool*:  listAddFrontRedBlackTreePBoolP,             \
  i16:                   listAddFrontRedBlackTreePI16,               \
  i16*:                  listAddFrontRedBlackTreePI16P,              \
  const volatile i16*:   listAddFrontRedBlackTreePI16P,              \
  u16:                   listAddFrontRedBlackTreePU16,               \
  u16*:                  listAddFrontRedBlackTreePU16P,              \
  const volatile u16*:   listAddFrontRedBlackTreePU16P,              \
  i32:                   listAddFrontRedBlackTreePI32,               \
  i32*:                  listAddFrontRedBlackTreePI32P,              \
  const volatile i32*:   listAddFrontRedBlackTreePI32P,              \
  u32:                   listAddFrontRedBlackTreePU32,               \
  u32*:                  listAddFrontRedBlackTreePU32P,              \
  const volatile u32*:   listAddFrontRedBlackTreePU32P,              \
  i64:                   listAddFrontRedBlackTreePI64,               \
  i64*:                  listAddFrontRedBlackTreePI64P,              \
  const volatile i64*:   listAddFrontRedBlackTreePI64P,              \
  u64:                   listAddFrontRedBlackTreePU64,               \
  u64*:                  listAddFrontRedBlackTreePU64P,              \
  const volatile u64*:   listAddFrontRedBlackTreePU64P,              \
  float:                 listAddFrontRedBlackTreePFloat,             \
  float*:                listAddFrontRedBlackTreePFloatP,            \
  const volatile float*: listAddFrontRedBlackTreePFloatP,            \
  double:                listAddFrontRedBlackTreePDouble,            \
  double*:               listAddFrontRedBlackTreePDoubleP,           \
  const volatile double*: listAddFrontRedBlackTreePDoubleP,           \
  long double:           listAddFrontRedBlackTreePLongDouble,        \
  long double*:          listAddFrontRedBlackTreePLongDoubleP,       \
  const volatile long double*: listAddFrontRedBlackTreePLongDoubleP,       \
  List:                  listAddFrontRedBlackTreePList,              \
  List*:                 listAddFrontRedBlackTreePListP,             \
  const volatile List*:  listAddFrontRedBlackTreePListP,             \
  Queue:                 listAddFrontRedBlackTreePQueue,             \
  Queue*:                listAddFrontRedBlackTreePQueueP,            \
  const volatile Queue*: listAddFrontRedBlackTreePQueueP,            \
  Stack:                 listAddFrontRedBlackTreePStack,             \
  Stack*:                listAddFrontRedBlackTreePStackP,            \
  const volatile Stack*: listAddFrontRedBlackTreePStackP,            \
  RedBlackTree:          listAddFrontRedBlackTreePRedBlackTree,      \
  RedBlackTree*:         listAddFrontRedBlackTreePRedBlackTreeP,     \
  const volatile RedBlackTree*: listAddFrontRedBlackTreePRedBlackTreeP,     \
  HashTable:             listAddFrontRedBlackTreePHashTable,         \
  HashTable*:            listAddFrontRedBlackTreePHashTableP,        \
  const volatile HashTable*: listAddFrontRedBlackTreePHashTableP,        \
  Vector:                listAddFrontRedBlackTreePVector,            \
  Vector*:               listAddFrontRedBlackTreePVectorP,           \
  const volatile Vector*: listAddFrontRedBlackTreePVectorP,           \
  char*:                 listAddFrontRedBlackTreePString,            \
  const volatile char*:  listAddFrontRedBlackTreePString,            \
  char**:                listAddFrontRedBlackTreePStringP,           \
  const volatile char**: listAddFrontRedBlackTreePStringP,           \
  Bytes:                 listAddFrontRedBlackTreePBytes,             \
  Bytes*:                listAddFrontRedBlackTreePBytesP,            \
  const volatile Bytes*: listAddFrontRedBlackTreePBytesP,            \
  void*:                 listAddFrontRedBlackTreePPointer,           \
  void**:                listAddFrontRedBlackTreePPointerP,          \
  const volatile void**: listAddFrontRedBlackTreePPointerP,          \
  i8:                    listAddFrontRedBlackTreeI8,                 \
  u8:                    listAddFrontRedBlackTreeU8                  \

#define listAddFrontRedBlackTreeP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_RED_BLACK_TREEP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_HASH_TABLEP_KEY(dataStructure, key, value) \
  bool:                  listAddFrontHashTablePBool,                 \
  bool*:                 listAddFrontHashTablePBoolP,                \
  const volatile bool*:  listAddFrontHashTablePBoolP,                \
  i16:                   listAddFrontHashTablePI16,                  \
  i16*:                  listAddFrontHashTablePI16P,                 \
  const volatile i16*:   listAddFrontHashTablePI16P,                 \
  u16:                   listAddFrontHashTablePU16,                  \
  u16*:                  listAddFrontHashTablePU16P,                 \
  const volatile u16*:   listAddFrontHashTablePU16P,                 \
  i32:                   listAddFrontHashTablePI32,                  \
  i32*:                  listAddFrontHashTablePI32P,                 \
  const volatile i32*:   listAddFrontHashTablePI32P,                 \
  u32:                   listAddFrontHashTablePU32,                  \
  u32*:                  listAddFrontHashTablePU32P,                 \
  const volatile u32*:   listAddFrontHashTablePU32P,                 \
  i64:                   listAddFrontHashTablePI64,                  \
  i64*:                  listAddFrontHashTablePI64P,                 \
  const volatile i64*:   listAddFrontHashTablePI64P,                 \
  u64:                   listAddFrontHashTablePU64,                  \
  u64*:                  listAddFrontHashTablePU64P,                 \
  const volatile u64*:   listAddFrontHashTablePU64P,                 \
  float:                 listAddFrontHashTablePFloat,                \
  float*:                listAddFrontHashTablePFloatP,               \
  const volatile float*: listAddFrontHashTablePFloatP,               \
  double:                listAddFrontHashTablePDouble,               \
  double*:               listAddFrontHashTablePDoubleP,              \
  const volatile double*: listAddFrontHashTablePDoubleP,              \
  long double:           listAddFrontHashTablePLongDouble,           \
  long double*:          listAddFrontHashTablePLongDoubleP,          \
  const volatile long double*: listAddFrontHashTablePLongDoubleP,          \
  List:                  listAddFrontHashTablePList,                 \
  List*:                 listAddFrontHashTablePListP,                \
  const volatile List*:  listAddFrontHashTablePListP,                \
  Queue:                 listAddFrontHashTablePQueue,                \
  Queue*:                listAddFrontHashTablePQueueP,               \
  const volatile Queue*: listAddFrontHashTablePQueueP,               \
  Stack:                 listAddFrontHashTablePStack,                \
  Stack*:                listAddFrontHashTablePStackP,               \
  const volatile Stack*: listAddFrontHashTablePStackP,               \
  RedBlackTree:          listAddFrontHashTablePRedBlackTree,         \
  RedBlackTree*:         listAddFrontHashTablePRedBlackTreeP,        \
  const volatile RedBlackTree*: listAddFrontHashTablePRedBlackTreeP,        \
  HashTable:             listAddFrontHashTablePHashTable,            \
  HashTable*:            listAddFrontHashTablePHashTableP,           \
  const volatile HashTable*: listAddFrontHashTablePHashTableP,           \
  Vector:                listAddFrontHashTablePVector,               \
  Vector*:               listAddFrontHashTablePVectorP,              \
  const volatile Vector*: listAddFrontHashTablePVectorP,              \
  char*:                 listAddFrontHashTablePString,               \
  const volatile char*:  listAddFrontHashTablePString,               \
  char**:                listAddFrontHashTablePStringP,              \
  const volatile char**: listAddFrontHashTablePStringP,              \
  Bytes:                 listAddFrontHashTablePBytes,                \
  Bytes*:                listAddFrontHashTablePBytesP,               \
  const volatile Bytes*: listAddFrontHashTablePBytesP,               \
  void*:                 listAddFrontHashTablePPointer,              \
  void**:                listAddFrontHashTablePPointerP,             \
  const volatile void**: listAddFrontHashTablePPointerP,             \
  i8:                    listAddFrontHashTableI8,                    \
  u8:                    listAddFrontHashTableU8                     \

#define listAddFrontHashTableP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_HASH_TABLEP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_VECTORP_KEY(dataStructure, key, value) \
  bool:                  listAddFrontVectorPBool,                    \
  bool*:                 listAddFrontVectorPBoolP,                   \
  const volatile bool*:  listAddFrontVectorPBoolP,                   \
  i16:                   listAddFrontVectorPI16,                     \
  i16*:                  listAddFrontVectorPI16P,                    \
  const volatile i16*:   listAddFrontVectorPI16P,                    \
  u16:                   listAddFrontVectorPU16,                     \
  u16*:                  listAddFrontVectorPU16P,                    \
  const volatile u16*:   listAddFrontVectorPU16P,                    \
  i32:                   listAddFrontVectorPI32,                     \
  i32*:                  listAddFrontVectorPI32P,                    \
  const volatile i32*:   listAddFrontVectorPI32P,                    \
  u32:                   listAddFrontVectorPU32,                     \
  u32*:                  listAddFrontVectorPU32P,                    \
  const volatile u32*:   listAddFrontVectorPU32P,                    \
  i64:                   listAddFrontVectorPI64,                     \
  i64*:                  listAddFrontVectorPI64P,                    \
  const volatile i64*:   listAddFrontVectorPI64P,                    \
  u64:                   listAddFrontVectorPU64,                     \
  u64*:                  listAddFrontVectorPU64P,                    \
  const volatile u64*:   listAddFrontVectorPU64P,                    \
  float:                 listAddFrontVectorPFloat,                   \
  float*:                listAddFrontVectorPFloatP,                  \
  const volatile float*: listAddFrontVectorPFloatP,                  \
  double:                listAddFrontVectorPDouble,                  \
  double*:               listAddFrontVectorPDoubleP,                 \
  const volatile double*: listAddFrontVectorPDoubleP,                 \
  long double:           listAddFrontVectorPLongDouble,              \
  long double*:          listAddFrontVectorPLongDoubleP,             \
  const volatile long double*: listAddFrontVectorPLongDoubleP,             \
  List:                  listAddFrontVectorPList,                    \
  List*:                 listAddFrontVectorPListP,                   \
  const volatile List*:  listAddFrontVectorPListP,                   \
  Queue:                 listAddFrontVectorPQueue,                   \
  Queue*:                listAddFrontVectorPQueueP,                  \
  const volatile Queue*: listAddFrontVectorPQueueP,                  \
  Stack:                 listAddFrontVectorPStack,                   \
  Stack*:                listAddFrontVectorPStackP,                  \
  const volatile Stack*: listAddFrontVectorPStackP,                  \
  RedBlackTree:          listAddFrontVectorPRedBlackTree,            \
  RedBlackTree*:         listAddFrontVectorPRedBlackTreeP,           \
  const volatile RedBlackTree*: listAddFrontVectorPRedBlackTreeP,           \
  HashTable:             listAddFrontVectorPHashTable,               \
  HashTable*:            listAddFrontVectorPHashTableP,              \
  const volatile HashTable*: listAddFrontVectorPHashTableP,              \
  Vector:                listAddFrontVectorPVector,                  \
  Vector*:               listAddFrontVectorPVectorP,                 \
  const volatile Vector*: listAddFrontVectorPVectorP,                 \
  char*:                 listAddFrontVectorPString,                  \
  const volatile char*:  listAddFrontVectorPString,                  \
  char**:                listAddFrontVectorPStringP,                 \
  const volatile char**: listAddFrontVectorPStringP,                 \
  Bytes:                 listAddFrontVectorPBytes,                   \
  Bytes*:                listAddFrontVectorPBytesP,                  \
  const volatile Bytes*: listAddFrontVectorPBytesP,                  \
  void*:                 listAddFrontVectorPPointer,                 \
  void**:                listAddFrontVectorPPointerP,                \
  const volatile void**: listAddFrontVectorPPointerP,                \
  i8:                    listAddFrontVectorI8,                       \
  u8:                    listAddFrontVectorU8                        \

#define listAddFrontVectorP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_VECTORP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_STRINGP_KEY(dataStructure, key, value) \
  bool:                  listAddFrontStringPBool,                    \
  bool*:                 listAddFrontStringPBoolP,                   \
  const volatile bool*:  listAddFrontStringPBoolP,                   \
  i16:                   listAddFrontStringPI16,                     \
  i16*:                  listAddFrontStringPI16P,                    \
  const volatile i16*:   listAddFrontStringPI16P,                    \
  u16:                   listAddFrontStringPU16,                     \
  u16*:                  listAddFrontStringPU16P,                    \
  const volatile u16*:   listAddFrontStringPU16P,                    \
  i32:                   listAddFrontStringPI32,                     \
  i32*:                  listAddFrontStringPI32P,                    \
  const volatile i32*:   listAddFrontStringPI32P,                    \
  u32:                   listAddFrontStringPU32,                     \
  u32*:                  listAddFrontStringPU32P,                    \
  const volatile u32*:   listAddFrontStringPU32P,                    \
  i64:                   listAddFrontStringPI64,                     \
  i64*:                  listAddFrontStringPI64P,                    \
  const volatile i64*:   listAddFrontStringPI64P,                    \
  u64:                   listAddFrontStringPU64,                     \
  u64*:                  listAddFrontStringPU64P,                    \
  const volatile u64*:   listAddFrontStringPU64P,                    \
  float:                 listAddFrontStringPFloat,                   \
  float*:                listAddFrontStringPFloatP,                  \
  const volatile float*: listAddFrontStringPFloatP,                  \
  double:                listAddFrontStringPDouble,                  \
  double*:               listAddFrontStringPDoubleP,                 \
  const volatile double*: listAddFrontStringPDoubleP,                 \
  long double:           listAddFrontStringPLongDouble,              \
  long double*:          listAddFrontStringPLongDoubleP,             \
  const volatile long double*: listAddFrontStringPLongDoubleP,             \
  List:                  listAddFrontStringPList,                    \
  List*:                 listAddFrontStringPListP,                   \
  const volatile List*:  listAddFrontStringPListP,                   \
  Queue:                 listAddFrontStringPQueue,                   \
  Queue*:                listAddFrontStringPQueueP,                  \
  const volatile Queue*: listAddFrontStringPQueueP,                  \
  Stack:                 listAddFrontStringPStack,                   \
  Stack*:                listAddFrontStringPStackP,                  \
  const volatile Stack*: listAddFrontStringPStackP,                  \
  RedBlackTree:          listAddFrontStringPRedBlackTree,            \
  RedBlackTree*:         listAddFrontStringPRedBlackTreeP,           \
  const volatile RedBlackTree*: listAddFrontStringPRedBlackTreeP,           \
  HashTable:             listAddFrontStringPHashTable,               \
  HashTable*:            listAddFrontStringPHashTableP,              \
  const volatile HashTable*: listAddFrontStringPHashTableP,              \
  Vector:                listAddFrontStringPVector,                  \
  Vector*:               listAddFrontStringPVectorP,                 \
  const volatile Vector*: listAddFrontStringPVectorP,                 \
  char*:                 listAddFrontStringPString,                  \
  const volatile char*:  listAddFrontStringPString,                  \
  char**:                listAddFrontStringPStringP,                 \
  const volatile char**: listAddFrontStringPStringP,                 \
  Bytes:                 listAddFrontStringPBytes,                   \
  Bytes*:                listAddFrontStringPBytesP,                  \
  const volatile Bytes*: listAddFrontStringPBytesP,                  \
  void*:                 listAddFrontStringPPointer,                 \
  void**:                listAddFrontStringPPointerP,                \
  const volatile void**: listAddFrontStringPPointerP,                \
  i8:                    listAddFrontStringI8,                       \
  u8:                    listAddFrontStringU8                        \

#define listAddFrontStringP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_STRINGP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_BYTESP_KEY(dataStructure, key, value) \
  bool:                  listAddFrontBytesPBool,                     \
  bool*:                 listAddFrontBytesPBoolP,                    \
  const volatile bool*:  listAddFrontBytesPBoolP,                    \
  i16:                   listAddFrontBytesPI16,                      \
  i16*:                  listAddFrontBytesPI16P,                     \
  const volatile i16*:   listAddFrontBytesPI16P,                     \
  u16:                   listAddFrontBytesPU16,                      \
  u16*:                  listAddFrontBytesPU16P,                     \
  const volatile u16*:   listAddFrontBytesPU16P,                     \
  i32:                   listAddFrontBytesPI32,                      \
  i32*:                  listAddFrontBytesPI32P,                     \
  const volatile i32*:   listAddFrontBytesPI32P,                     \
  u32:                   listAddFrontBytesPU32,                      \
  u32*:                  listAddFrontBytesPU32P,                     \
  const volatile u32*:   listAddFrontBytesPU32P,                     \
  i64:                   listAddFrontBytesPI64,                      \
  i64*:                  listAddFrontBytesPI64P,                     \
  const volatile i64*:   listAddFrontBytesPI64P,                     \
  u64:                   listAddFrontBytesPU64,                      \
  u64*:                  listAddFrontBytesPU64P,                     \
  const volatile u64*:   listAddFrontBytesPU64P,                     \
  float:                 listAddFrontBytesPFloat,                    \
  float*:                listAddFrontBytesPFloatP,                   \
  const volatile float*: listAddFrontBytesPFloatP,                   \
  double:                listAddFrontBytesPDouble,                   \
  double*:               listAddFrontBytesPDoubleP,                  \
  const volatile double*: listAddFrontBytesPDoubleP,                  \
  long double:           listAddFrontBytesPLongDouble,               \
  long double*:          listAddFrontBytesPLongDoubleP,              \
  const volatile long double*: listAddFrontBytesPLongDoubleP,              \
  List:                  listAddFrontBytesPList,                     \
  List*:                 listAddFrontBytesPListP,                    \
  const volatile List*:  listAddFrontBytesPListP,                    \
  Queue:                 listAddFrontBytesPQueue,                    \
  Queue*:                listAddFrontBytesPQueueP,                   \
  const volatile Queue*: listAddFrontBytesPQueueP,                   \
  Stack:                 listAddFrontBytesPStack,                    \
  Stack*:                listAddFrontBytesPStackP,                   \
  const volatile Stack*: listAddFrontBytesPStackP,                   \
  RedBlackTree:          listAddFrontBytesPRedBlackTree,             \
  RedBlackTree*:         listAddFrontBytesPRedBlackTreeP,            \
  const volatile RedBlackTree*: listAddFrontBytesPRedBlackTreeP,            \
  HashTable:             listAddFrontBytesPHashTable,                \
  HashTable*:            listAddFrontBytesPHashTableP,               \
  const volatile HashTable*: listAddFrontBytesPHashTableP,               \
  Vector:                listAddFrontBytesPVector,                   \
  Vector*:               listAddFrontBytesPVectorP,                  \
  const volatile Vector*: listAddFrontBytesPVectorP,                  \
  char*:                 listAddFrontBytesPString,                   \
  const volatile char*:  listAddFrontBytesPString,                   \
  char**:                listAddFrontBytesPStringP,                  \
  const volatile char**: listAddFrontBytesPStringP,                  \
  Bytes:                 listAddFrontBytesPBytes,                    \
  Bytes*:                listAddFrontBytesPBytesP,                   \
  const volatile Bytes*: listAddFrontBytesPBytesP,                   \
  void*:                 listAddFrontBytesPPointer,                  \
  void**:                listAddFrontBytesPPointerP,                 \
  const volatile void**: listAddFrontBytesPPointerP,                 \
  i8:                    listAddFrontBytesI8,                        \
  u8:                    listAddFrontBytesU8                         \

#define listAddFrontBytesP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_BYTESP_KEY(dataStructure, key, value) \
  )

#define LIST_ADD_FRONT_GENERIC_CASES_POINTERP_KEY(dataStructure, key, value) \
  bool:                  listAddFrontPointerPBool,                   \
  bool*:                 listAddFrontPointerPBoolP,                  \
  const volatile bool*:  listAddFrontPointerPBoolP,                  \
  i16:                   listAddFrontPointerPI16,                    \
  i16*:                  listAddFrontPointerPI16P,                   \
  const volatile i16*:   listAddFrontPointerPI16P,                   \
  u16:                   listAddFrontPointerPU16,                    \
  u16*:                  listAddFrontPointerPU16P,                   \
  const volatile u16*:   listAddFrontPointerPU16P,                   \
  i32:                   listAddFrontPointerPI32,                    \
  i32*:                  listAddFrontPointerPI32P,                   \
  const volatile i32*:   listAddFrontPointerPI32P,                   \
  u32:                   listAddFrontPointerPU32,                    \
  u32*:                  listAddFrontPointerPU32P,                   \
  const volatile u32*:   listAddFrontPointerPU32P,                   \
  i64:                   listAddFrontPointerPI64,                    \
  i64*:                  listAddFrontPointerPI64P,                   \
  const volatile i64*:   listAddFrontPointerPI64P,                   \
  u64:                   listAddFrontPointerPU64,                    \
  u64*:                  listAddFrontPointerPU64P,                   \
  const volatile u64*:   listAddFrontPointerPU64P,                   \
  float:                 listAddFrontPointerPFloat,                  \
  float*:                listAddFrontPointerPFloatP,                 \
  const volatile float*: listAddFrontPointerPFloatP,                 \
  double:                listAddFrontPointerPDouble,                 \
  double*:               listAddFrontPointerPDoubleP,                \
  const volatile double*: listAddFrontPointerPDoubleP,                \
  long double:           listAddFrontPointerPLongDouble,             \
  long double*:          listAddFrontPointerPLongDoubleP,            \
  const volatile long double*: listAddFrontPointerPLongDoubleP,            \
  List:                  listAddFrontPointerPList,                   \
  List*:                 listAddFrontPointerPListP,                  \
  const volatile List*:  listAddFrontPointerPListP,                  \
  Queue:                 listAddFrontPointerPQueue,                  \
  Queue*:                listAddFrontPointerPQueueP,                 \
  const volatile Queue*: listAddFrontPointerPQueueP,                 \
  Stack:                 listAddFrontPointerPStack,                  \
  Stack*:                listAddFrontPointerPStackP,                 \
  const volatile Stack*: listAddFrontPointerPStackP,                 \
  RedBlackTree:          listAddFrontPointerPRedBlackTree,           \
  RedBlackTree*:         listAddFrontPointerPRedBlackTreeP,          \
  const volatile RedBlackTree*: listAddFrontPointerPRedBlackTreeP,          \
  HashTable:             listAddFrontPointerPHashTable,              \
  HashTable*:            listAddFrontPointerPHashTableP,             \
  const volatile HashTable*: listAddFrontPointerPHashTableP,             \
  Vector:                listAddFrontPointerPVector,                 \
  Vector*:               listAddFrontPointerPVectorP,                \
  const volatile Vector*: listAddFrontPointerPVectorP,                \
  char*:                 listAddFrontPointerPString,                 \
  const volatile char*:  listAddFrontPointerPString,                 \
  char**:                listAddFrontPointerPStringP,                \
  const volatile char**: listAddFrontPointerPStringP,                \
  Bytes:                 listAddFrontPointerPBytes,                  \
  Bytes*:                listAddFrontPointerPBytesP,                 \
  const volatile Bytes*: listAddFrontPointerPBytesP,                 \
  void*:                 listAddFrontPointerPPointer,                \
  void**:                listAddFrontPointerPPointerP,               \
  const volatile void**: listAddFrontPointerPPointerP,               \
  i8:                    listAddFrontPointerI8,                      \
  u8:                    listAddFrontPointerU8                       \

#define listAddFrontPointerP(dataStructure, key, value) _Generic((value), \
  LIST_ADD_FRONT_GENERIC_CASES_POINTERP_KEY(dataStructure, key, value) \
  )


#define LIST_ADD_FRONT_GENERIC_CASES(dataStructure, key, value) \
  bool:                  listAddFrontBool(dataStructure, key, value), \
  bool*:                 listAddFrontBoolP(dataStructure, key, value), \
  const volatile bool*:  listAddFrontBoolP(dataStructure, key, value), \
  i16:                   listAddFrontI16(dataStructure, key, value), \
  i16*:                  listAddFrontI16P(dataStructure, key, value), \
  const volatile i16*:   listAddFrontI16P(dataStructure, key, value), \
  u16:                   listAddFrontU16(dataStructure, key, value), \
  u16*:                  listAddFrontU16P(dataStructure, key, value), \
  const volatile u16*:   listAddFrontU16P(dataStructure, key, value), \
  i32:                   listAddFrontI32(dataStructure, key, value), \
  i32*:                  listAddFrontI32P(dataStructure, key, value), \
  const volatile i32*:   listAddFrontI32P(dataStructure, key, value), \
  u32:                   listAddFrontU32(dataStructure, key, value), \
  u32*:                  listAddFrontU32P(dataStructure, key, value), \
  const volatile u32*:   listAddFrontU32P(dataStructure, key, value), \
  i64:                   listAddFrontI64(dataStructure, key, value), \
  i64*:                  listAddFrontI64P(dataStructure, key, value), \
  const volatile i64*:   listAddFrontI64P(dataStructure, key, value), \
  u64:                   listAddFrontU64(dataStructure, key, value), \
  u64*:                  listAddFrontU64P(dataStructure, key, value), \
  const volatile u64*:   listAddFrontU64P(dataStructure, key, value), \
  float:                 listAddFrontFloat(dataStructure, key, value), \
  float*:                listAddFrontFloatP(dataStructure, key, value), \
  const volatile float*: listAddFrontFloatP(dataStructure, key, value), \
  double:                listAddFrontDouble(dataStructure, key, value), \
  double*:               listAddFrontDoubleP(dataStructure, key, value), \
  const volatile double*: listAddFrontDoubleP(dataStructure, key, value), \
  long double:           listAddFrontLongDouble(dataStructure, key, value), \
  long double*:          listAddFrontLongDoubleP(dataStructure, key, value), \
  const volatile long double*: listAddFrontLongDoubleP(dataStructure, key, value), \
  List:                  listAddFrontList(dataStructure, key, value), \
  List*:                 listAddFrontListP(dataStructure, key, value), \
  const volatile List*:  listAddFrontListP(dataStructure, key, value), \
  Queue:                 listAddFrontQueue(dataStructure, key, value), \
  Queue*:                listAddFrontQueueP(dataStructure, key, value), \
  const volatile Queue*: listAddFrontQueueP(dataStructure, key, value), \
  Stack:                 listAddFrontStack(dataStructure, key, value), \
  Stack*:                listAddFrontStackP(dataStructure, key, value), \
  const volatile Stack*: listAddFrontStackP(dataStructure, key, value), \
  RedBlackTree:          listAddFrontRedBlackTree(dataStructure, key, value), \
  RedBlackTree*:         listAddFrontRedBlackTreeP(dataStructure, key, value), \
  const volatile RedBlackTree*: listAddFrontRedBlackTreeP(dataStructure, key, value), \
  HashTable:             listAddFrontHashTable(dataStructure, key, value), \
  HashTable*:            listAddFrontHashTableP(dataStructure, key, value), \
  const volatile HashTable*: listAddFrontHashTableP(dataStructure, key, value), \
  Vector:                listAddFrontVector(dataStructure, key, value), \
  Vector*:               listAddFrontVectorP(dataStructure, key, value), \
  const volatile Vector*: listAddFrontVectorP(dataStructure, key, value), \
  char*:                 listAddFrontString(dataStructure, key, value), \
  const volatile char*:  listAddFrontString(dataStructure, key, value), \
  char**:                listAddFrontStringP(dataStructure, key, value), \
  const volatile char**: listAddFrontStringP(dataStructure, key, value), \
  Bytes:                 listAddFrontBytes(dataStructure, key, value), \
  Bytes*:                listAddFrontBytesP(dataStructure, key, value), \
  const volatile Bytes*: listAddFrontBytesP(dataStructure, key, value), \
  void*:                 listAddFrontPointer(dataStructure, key, value), \
  void**:                listAddFrontPointerP(dataStructure, key, value), \
  const volatile void**: listAddFrontPointerP(dataStructure, key, value), \
  i8:                    listAddFrontI8(dataStructure, key, value),  \
  u8:                    listAddFrontU8(dataStructure, key, value)   \

#define listAddFront(dataStructure, key, value) _Generic((key), \
  LIST_ADD_FRONT_GENERIC_CASES(dataStructure, key, value) \
  )(dataStructure, key, value)

#endif // __STDC_VERSION__

#elif defined __cplusplus // __STDC_VERSION__ is *NOT* defined
#define TYPE_SAFE_LIST

// Define the C++ function overloads.

static inline ListNode* listAddFront(List *dataStructure, bool key, bool value) {
  return listAddFrontBoolBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile bool* value) {
  return listAddFrontBoolBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, bool value) {
  return listAddFrontBoolPBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile bool* value) {
  return listAddFrontBoolPBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, i16 value) {
  return listAddFrontBoolI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile i16* value) {
  return listAddFrontBoolI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, i16 value) {
  return listAddFrontBoolPI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile i16* value) {
  return listAddFrontBoolPI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, u16 value) {
  return listAddFrontBoolU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile u16* value) {
  return listAddFrontBoolU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, u16 value) {
  return listAddFrontBoolPU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile u16* value) {
  return listAddFrontBoolPU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, i32 value) {
  return listAddFrontBoolI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile i32* value) {
  return listAddFrontBoolI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, i32 value) {
  return listAddFrontBoolPI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile i32* value) {
  return listAddFrontBoolPI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, u32 value) {
  return listAddFrontBoolU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile u32* value) {
  return listAddFrontBoolU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, u32 value) {
  return listAddFrontBoolPU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile u32* value) {
  return listAddFrontBoolPU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, i64 value) {
  return listAddFrontBoolI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile i64* value) {
  return listAddFrontBoolI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, i64 value) {
  return listAddFrontBoolPI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile i64* value) {
  return listAddFrontBoolPI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, u64 value) {
  return listAddFrontBoolU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile u64* value) {
  return listAddFrontBoolU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, u64 value) {
  return listAddFrontBoolPU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile u64* value) {
  return listAddFrontBoolPU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, float value) {
  return listAddFrontBoolFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile float* value) {
  return listAddFrontBoolFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, float value) {
  return listAddFrontBoolPFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile float* value) {
  return listAddFrontBoolPFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, double value) {
  return listAddFrontBoolDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile double* value) {
  return listAddFrontBoolDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, double value) {
  return listAddFrontBoolPDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile double* value) {
  return listAddFrontBoolPDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, long double value) {
  return listAddFrontBoolLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile long double* value) {
  return listAddFrontBoolLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, long double value) {
  return listAddFrontBoolPLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile long double* value) {
  return listAddFrontBoolPLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, List value) {
  return listAddFrontBoolList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile List* value) {
  return listAddFrontBoolListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, List value) {
  return listAddFrontBoolPList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile List* value) {
  return listAddFrontBoolPListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, Queue value) {
  return listAddFrontBoolQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile Queue* value) {
  return listAddFrontBoolQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, Queue value) {
  return listAddFrontBoolPQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile Queue* value) {
  return listAddFrontBoolPQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, Stack value) {
  return listAddFrontBoolStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile Stack* value) {
  return listAddFrontBoolStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, Stack value) {
  return listAddFrontBoolPStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile Stack* value) {
  return listAddFrontBoolPStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, RedBlackTree value) {
  return listAddFrontBoolRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile RedBlackTree* value) {
  return listAddFrontBoolRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, RedBlackTree value) {
  return listAddFrontBoolPRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile RedBlackTree* value) {
  return listAddFrontBoolPRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, HashTable value) {
  return listAddFrontBoolHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile HashTable* value) {
  return listAddFrontBoolHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, HashTable value) {
  return listAddFrontBoolPHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile HashTable* value) {
  return listAddFrontBoolPHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, Vector value) {
  return listAddFrontBoolVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile Vector* value) {
  return listAddFrontBoolVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, Vector value) {
  return listAddFrontBoolPVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile Vector* value) {
  return listAddFrontBoolPVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile char* value) {
  return listAddFrontBoolString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile char** value) {
  return listAddFrontBoolStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile char* value) {
  return listAddFrontBoolPString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile char** value) {
  return listAddFrontBoolPStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, Bytes value) {
  return listAddFrontBoolBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile Bytes* value) {
  return listAddFrontBoolBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, Bytes value) {
  return listAddFrontBoolPBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile Bytes* value) {
  return listAddFrontBoolPBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, void* value) {
  return listAddFrontBoolPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, const volatile void** value) {
  return listAddFrontBoolPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, void* value) {
  return listAddFrontBoolPPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, const volatile void** value) {
  return listAddFrontBoolPPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, i8 value) {
  return listAddFrontBoolI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, i8 value) {
  return listAddFrontBoolPI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, bool key, u8 value) {
  return listAddFrontBoolU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile bool* key, u8 value) {
  return listAddFrontBoolPU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, bool value) {
  return listAddFrontI16Bool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile bool* value) {
  return listAddFrontI16BoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, bool value) {
  return listAddFrontI16PBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile bool* value) {
  return listAddFrontI16PBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, i16 value) {
  return listAddFrontI16I16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile i16* value) {
  return listAddFrontI16I16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, i16 value) {
  return listAddFrontI16PI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile i16* value) {
  return listAddFrontI16PI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, u16 value) {
  return listAddFrontI16U16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile u16* value) {
  return listAddFrontI16U16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, u16 value) {
  return listAddFrontI16PU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile u16* value) {
  return listAddFrontI16PU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, i32 value) {
  return listAddFrontI16I32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile i32* value) {
  return listAddFrontI16I32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, i32 value) {
  return listAddFrontI16PI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile i32* value) {
  return listAddFrontI16PI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, u32 value) {
  return listAddFrontI16U32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile u32* value) {
  return listAddFrontI16U32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, u32 value) {
  return listAddFrontI16PU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile u32* value) {
  return listAddFrontI16PU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, i64 value) {
  return listAddFrontI16I64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile i64* value) {
  return listAddFrontI16I64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, i64 value) {
  return listAddFrontI16PI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile i64* value) {
  return listAddFrontI16PI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, u64 value) {
  return listAddFrontI16U64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile u64* value) {
  return listAddFrontI16U64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, u64 value) {
  return listAddFrontI16PU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile u64* value) {
  return listAddFrontI16PU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, float value) {
  return listAddFrontI16Float(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile float* value) {
  return listAddFrontI16FloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, float value) {
  return listAddFrontI16PFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile float* value) {
  return listAddFrontI16PFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, double value) {
  return listAddFrontI16Double(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile double* value) {
  return listAddFrontI16DoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, double value) {
  return listAddFrontI16PDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile double* value) {
  return listAddFrontI16PDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, long double value) {
  return listAddFrontI16LongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile long double* value) {
  return listAddFrontI16LongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, long double value) {
  return listAddFrontI16PLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile long double* value) {
  return listAddFrontI16PLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, List value) {
  return listAddFrontI16List(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile List* value) {
  return listAddFrontI16ListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, List value) {
  return listAddFrontI16PList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile List* value) {
  return listAddFrontI16PListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, Queue value) {
  return listAddFrontI16Queue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile Queue* value) {
  return listAddFrontI16QueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, Queue value) {
  return listAddFrontI16PQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile Queue* value) {
  return listAddFrontI16PQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, Stack value) {
  return listAddFrontI16Stack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile Stack* value) {
  return listAddFrontI16StackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, Stack value) {
  return listAddFrontI16PStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile Stack* value) {
  return listAddFrontI16PStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, RedBlackTree value) {
  return listAddFrontI16RedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile RedBlackTree* value) {
  return listAddFrontI16RedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, RedBlackTree value) {
  return listAddFrontI16PRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile RedBlackTree* value) {
  return listAddFrontI16PRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, HashTable value) {
  return listAddFrontI16HashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile HashTable* value) {
  return listAddFrontI16HashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, HashTable value) {
  return listAddFrontI16PHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile HashTable* value) {
  return listAddFrontI16PHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, Vector value) {
  return listAddFrontI16Vector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile Vector* value) {
  return listAddFrontI16VectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, Vector value) {
  return listAddFrontI16PVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile Vector* value) {
  return listAddFrontI16PVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile char* value) {
  return listAddFrontI16String(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile char** value) {
  return listAddFrontI16StringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile char* value) {
  return listAddFrontI16PString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile char** value) {
  return listAddFrontI16PStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, Bytes value) {
  return listAddFrontI16Bytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile Bytes* value) {
  return listAddFrontI16BytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, Bytes value) {
  return listAddFrontI16PBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile Bytes* value) {
  return listAddFrontI16PBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, void* value) {
  return listAddFrontI16Pointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, const volatile void** value) {
  return listAddFrontI16PointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, void* value) {
  return listAddFrontI16PPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, const volatile void** value) {
  return listAddFrontI16PPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, i8 value) {
  return listAddFrontI16I8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, i8 value) {
  return listAddFrontI16PI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i16 key, u8 value) {
  return listAddFrontI16U8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i16* key, u8 value) {
  return listAddFrontI16PU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, bool value) {
  return listAddFrontU16Bool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile bool* value) {
  return listAddFrontU16BoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, bool value) {
  return listAddFrontU16PBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile bool* value) {
  return listAddFrontU16PBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, i16 value) {
  return listAddFrontU16I16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile i16* value) {
  return listAddFrontU16I16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, i16 value) {
  return listAddFrontU16PI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile i16* value) {
  return listAddFrontU16PI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, u16 value) {
  return listAddFrontU16U16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile u16* value) {
  return listAddFrontU16U16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, u16 value) {
  return listAddFrontU16PU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile u16* value) {
  return listAddFrontU16PU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, i32 value) {
  return listAddFrontU16I32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile i32* value) {
  return listAddFrontU16I32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, i32 value) {
  return listAddFrontU16PI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile i32* value) {
  return listAddFrontU16PI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, u32 value) {
  return listAddFrontU16U32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile u32* value) {
  return listAddFrontU16U32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, u32 value) {
  return listAddFrontU16PU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile u32* value) {
  return listAddFrontU16PU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, i64 value) {
  return listAddFrontU16I64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile i64* value) {
  return listAddFrontU16I64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, i64 value) {
  return listAddFrontU16PI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile i64* value) {
  return listAddFrontU16PI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, u64 value) {
  return listAddFrontU16U64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile u64* value) {
  return listAddFrontU16U64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, u64 value) {
  return listAddFrontU16PU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile u64* value) {
  return listAddFrontU16PU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, float value) {
  return listAddFrontU16Float(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile float* value) {
  return listAddFrontU16FloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, float value) {
  return listAddFrontU16PFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile float* value) {
  return listAddFrontU16PFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, double value) {
  return listAddFrontU16Double(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile double* value) {
  return listAddFrontU16DoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, double value) {
  return listAddFrontU16PDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile double* value) {
  return listAddFrontU16PDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, long double value) {
  return listAddFrontU16LongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile long double* value) {
  return listAddFrontU16LongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, long double value) {
  return listAddFrontU16PLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile long double* value) {
  return listAddFrontU16PLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, List value) {
  return listAddFrontU16List(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile List* value) {
  return listAddFrontU16ListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, List value) {
  return listAddFrontU16PList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile List* value) {
  return listAddFrontU16PListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, Queue value) {
  return listAddFrontU16Queue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile Queue* value) {
  return listAddFrontU16QueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, Queue value) {
  return listAddFrontU16PQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile Queue* value) {
  return listAddFrontU16PQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, Stack value) {
  return listAddFrontU16Stack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile Stack* value) {
  return listAddFrontU16StackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, Stack value) {
  return listAddFrontU16PStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile Stack* value) {
  return listAddFrontU16PStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, RedBlackTree value) {
  return listAddFrontU16RedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile RedBlackTree* value) {
  return listAddFrontU16RedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, RedBlackTree value) {
  return listAddFrontU16PRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile RedBlackTree* value) {
  return listAddFrontU16PRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, HashTable value) {
  return listAddFrontU16HashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile HashTable* value) {
  return listAddFrontU16HashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, HashTable value) {
  return listAddFrontU16PHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile HashTable* value) {
  return listAddFrontU16PHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, Vector value) {
  return listAddFrontU16Vector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile Vector* value) {
  return listAddFrontU16VectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, Vector value) {
  return listAddFrontU16PVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile Vector* value) {
  return listAddFrontU16PVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile char* value) {
  return listAddFrontU16String(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile char** value) {
  return listAddFrontU16StringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile char* value) {
  return listAddFrontU16PString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile char** value) {
  return listAddFrontU16PStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, Bytes value) {
  return listAddFrontU16Bytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile Bytes* value) {
  return listAddFrontU16BytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, Bytes value) {
  return listAddFrontU16PBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile Bytes* value) {
  return listAddFrontU16PBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, void* value) {
  return listAddFrontU16Pointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, const volatile void** value) {
  return listAddFrontU16PointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, void* value) {
  return listAddFrontU16PPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, const volatile void** value) {
  return listAddFrontU16PPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, i8 value) {
  return listAddFrontU16I8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, i8 value) {
  return listAddFrontU16PI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u16 key, u8 value) {
  return listAddFrontU16U8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u16* key, u8 value) {
  return listAddFrontU16PU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, bool value) {
  return listAddFrontI32Bool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile bool* value) {
  return listAddFrontI32BoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, bool value) {
  return listAddFrontI32PBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile bool* value) {
  return listAddFrontI32PBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, i16 value) {
  return listAddFrontI32I16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile i16* value) {
  return listAddFrontI32I16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, i16 value) {
  return listAddFrontI32PI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile i16* value) {
  return listAddFrontI32PI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, u16 value) {
  return listAddFrontI32U16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile u16* value) {
  return listAddFrontI32U16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, u16 value) {
  return listAddFrontI32PU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile u16* value) {
  return listAddFrontI32PU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, i32 value) {
  return listAddFrontI32I32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile i32* value) {
  return listAddFrontI32I32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, i32 value) {
  return listAddFrontI32PI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile i32* value) {
  return listAddFrontI32PI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, u32 value) {
  return listAddFrontI32U32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile u32* value) {
  return listAddFrontI32U32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, u32 value) {
  return listAddFrontI32PU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile u32* value) {
  return listAddFrontI32PU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, i64 value) {
  return listAddFrontI32I64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile i64* value) {
  return listAddFrontI32I64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, i64 value) {
  return listAddFrontI32PI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile i64* value) {
  return listAddFrontI32PI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, u64 value) {
  return listAddFrontI32U64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile u64* value) {
  return listAddFrontI32U64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, u64 value) {
  return listAddFrontI32PU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile u64* value) {
  return listAddFrontI32PU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, float value) {
  return listAddFrontI32Float(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile float* value) {
  return listAddFrontI32FloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, float value) {
  return listAddFrontI32PFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile float* value) {
  return listAddFrontI32PFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, double value) {
  return listAddFrontI32Double(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile double* value) {
  return listAddFrontI32DoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, double value) {
  return listAddFrontI32PDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile double* value) {
  return listAddFrontI32PDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, long double value) {
  return listAddFrontI32LongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile long double* value) {
  return listAddFrontI32LongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, long double value) {
  return listAddFrontI32PLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile long double* value) {
  return listAddFrontI32PLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, List value) {
  return listAddFrontI32List(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile List* value) {
  return listAddFrontI32ListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, List value) {
  return listAddFrontI32PList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile List* value) {
  return listAddFrontI32PListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, Queue value) {
  return listAddFrontI32Queue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile Queue* value) {
  return listAddFrontI32QueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, Queue value) {
  return listAddFrontI32PQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile Queue* value) {
  return listAddFrontI32PQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, Stack value) {
  return listAddFrontI32Stack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile Stack* value) {
  return listAddFrontI32StackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, Stack value) {
  return listAddFrontI32PStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile Stack* value) {
  return listAddFrontI32PStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, RedBlackTree value) {
  return listAddFrontI32RedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile RedBlackTree* value) {
  return listAddFrontI32RedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, RedBlackTree value) {
  return listAddFrontI32PRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile RedBlackTree* value) {
  return listAddFrontI32PRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, HashTable value) {
  return listAddFrontI32HashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile HashTable* value) {
  return listAddFrontI32HashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, HashTable value) {
  return listAddFrontI32PHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile HashTable* value) {
  return listAddFrontI32PHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, Vector value) {
  return listAddFrontI32Vector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile Vector* value) {
  return listAddFrontI32VectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, Vector value) {
  return listAddFrontI32PVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile Vector* value) {
  return listAddFrontI32PVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile char* value) {
  return listAddFrontI32String(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile char** value) {
  return listAddFrontI32StringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile char* value) {
  return listAddFrontI32PString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile char** value) {
  return listAddFrontI32PStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, Bytes value) {
  return listAddFrontI32Bytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile Bytes* value) {
  return listAddFrontI32BytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, Bytes value) {
  return listAddFrontI32PBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile Bytes* value) {
  return listAddFrontI32PBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, void* value) {
  return listAddFrontI32Pointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, const volatile void** value) {
  return listAddFrontI32PointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, void* value) {
  return listAddFrontI32PPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, const volatile void** value) {
  return listAddFrontI32PPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, i8 value) {
  return listAddFrontI32I8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, i8 value) {
  return listAddFrontI32PI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i32 key, u8 value) {
  return listAddFrontI32U8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i32* key, u8 value) {
  return listAddFrontI32PU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, bool value) {
  return listAddFrontU32Bool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile bool* value) {
  return listAddFrontU32BoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, bool value) {
  return listAddFrontU32PBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile bool* value) {
  return listAddFrontU32PBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, i16 value) {
  return listAddFrontU32I16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile i16* value) {
  return listAddFrontU32I16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, i16 value) {
  return listAddFrontU32PI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile i16* value) {
  return listAddFrontU32PI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, u16 value) {
  return listAddFrontU32U16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile u16* value) {
  return listAddFrontU32U16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, u16 value) {
  return listAddFrontU32PU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile u16* value) {
  return listAddFrontU32PU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, i32 value) {
  return listAddFrontU32I32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile i32* value) {
  return listAddFrontU32I32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, i32 value) {
  return listAddFrontU32PI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile i32* value) {
  return listAddFrontU32PI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, u32 value) {
  return listAddFrontU32U32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile u32* value) {
  return listAddFrontU32U32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, u32 value) {
  return listAddFrontU32PU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile u32* value) {
  return listAddFrontU32PU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, i64 value) {
  return listAddFrontU32I64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile i64* value) {
  return listAddFrontU32I64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, i64 value) {
  return listAddFrontU32PI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile i64* value) {
  return listAddFrontU32PI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, u64 value) {
  return listAddFrontU32U64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile u64* value) {
  return listAddFrontU32U64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, u64 value) {
  return listAddFrontU32PU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile u64* value) {
  return listAddFrontU32PU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, float value) {
  return listAddFrontU32Float(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile float* value) {
  return listAddFrontU32FloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, float value) {
  return listAddFrontU32PFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile float* value) {
  return listAddFrontU32PFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, double value) {
  return listAddFrontU32Double(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile double* value) {
  return listAddFrontU32DoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, double value) {
  return listAddFrontU32PDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile double* value) {
  return listAddFrontU32PDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, long double value) {
  return listAddFrontU32LongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile long double* value) {
  return listAddFrontU32LongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, long double value) {
  return listAddFrontU32PLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile long double* value) {
  return listAddFrontU32PLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, List value) {
  return listAddFrontU32List(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile List* value) {
  return listAddFrontU32ListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, List value) {
  return listAddFrontU32PList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile List* value) {
  return listAddFrontU32PListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, Queue value) {
  return listAddFrontU32Queue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile Queue* value) {
  return listAddFrontU32QueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, Queue value) {
  return listAddFrontU32PQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile Queue* value) {
  return listAddFrontU32PQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, Stack value) {
  return listAddFrontU32Stack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile Stack* value) {
  return listAddFrontU32StackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, Stack value) {
  return listAddFrontU32PStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile Stack* value) {
  return listAddFrontU32PStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, RedBlackTree value) {
  return listAddFrontU32RedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile RedBlackTree* value) {
  return listAddFrontU32RedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, RedBlackTree value) {
  return listAddFrontU32PRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile RedBlackTree* value) {
  return listAddFrontU32PRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, HashTable value) {
  return listAddFrontU32HashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile HashTable* value) {
  return listAddFrontU32HashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, HashTable value) {
  return listAddFrontU32PHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile HashTable* value) {
  return listAddFrontU32PHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, Vector value) {
  return listAddFrontU32Vector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile Vector* value) {
  return listAddFrontU32VectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, Vector value) {
  return listAddFrontU32PVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile Vector* value) {
  return listAddFrontU32PVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile char* value) {
  return listAddFrontU32String(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile char** value) {
  return listAddFrontU32StringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile char* value) {
  return listAddFrontU32PString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile char** value) {
  return listAddFrontU32PStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, Bytes value) {
  return listAddFrontU32Bytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile Bytes* value) {
  return listAddFrontU32BytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, Bytes value) {
  return listAddFrontU32PBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile Bytes* value) {
  return listAddFrontU32PBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, void* value) {
  return listAddFrontU32Pointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, const volatile void** value) {
  return listAddFrontU32PointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, void* value) {
  return listAddFrontU32PPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, const volatile void** value) {
  return listAddFrontU32PPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, i8 value) {
  return listAddFrontU32I8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, i8 value) {
  return listAddFrontU32PI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u32 key, u8 value) {
  return listAddFrontU32U8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u32* key, u8 value) {
  return listAddFrontU32PU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, bool value) {
  return listAddFrontI64Bool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile bool* value) {
  return listAddFrontI64BoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, bool value) {
  return listAddFrontI64PBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile bool* value) {
  return listAddFrontI64PBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, i16 value) {
  return listAddFrontI64I16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile i16* value) {
  return listAddFrontI64I16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, i16 value) {
  return listAddFrontI64PI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile i16* value) {
  return listAddFrontI64PI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, u16 value) {
  return listAddFrontI64U16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile u16* value) {
  return listAddFrontI64U16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, u16 value) {
  return listAddFrontI64PU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile u16* value) {
  return listAddFrontI64PU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, i32 value) {
  return listAddFrontI64I32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile i32* value) {
  return listAddFrontI64I32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, i32 value) {
  return listAddFrontI64PI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile i32* value) {
  return listAddFrontI64PI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, u32 value) {
  return listAddFrontI64U32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile u32* value) {
  return listAddFrontI64U32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, u32 value) {
  return listAddFrontI64PU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile u32* value) {
  return listAddFrontI64PU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, i64 value) {
  return listAddFrontI64I64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile i64* value) {
  return listAddFrontI64I64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, i64 value) {
  return listAddFrontI64PI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile i64* value) {
  return listAddFrontI64PI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, u64 value) {
  return listAddFrontI64U64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile u64* value) {
  return listAddFrontI64U64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, u64 value) {
  return listAddFrontI64PU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile u64* value) {
  return listAddFrontI64PU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, float value) {
  return listAddFrontI64Float(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile float* value) {
  return listAddFrontI64FloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, float value) {
  return listAddFrontI64PFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile float* value) {
  return listAddFrontI64PFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, double value) {
  return listAddFrontI64Double(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile double* value) {
  return listAddFrontI64DoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, double value) {
  return listAddFrontI64PDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile double* value) {
  return listAddFrontI64PDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, long double value) {
  return listAddFrontI64LongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile long double* value) {
  return listAddFrontI64LongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, long double value) {
  return listAddFrontI64PLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile long double* value) {
  return listAddFrontI64PLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, List value) {
  return listAddFrontI64List(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile List* value) {
  return listAddFrontI64ListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, List value) {
  return listAddFrontI64PList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile List* value) {
  return listAddFrontI64PListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, Queue value) {
  return listAddFrontI64Queue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile Queue* value) {
  return listAddFrontI64QueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, Queue value) {
  return listAddFrontI64PQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile Queue* value) {
  return listAddFrontI64PQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, Stack value) {
  return listAddFrontI64Stack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile Stack* value) {
  return listAddFrontI64StackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, Stack value) {
  return listAddFrontI64PStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile Stack* value) {
  return listAddFrontI64PStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, RedBlackTree value) {
  return listAddFrontI64RedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile RedBlackTree* value) {
  return listAddFrontI64RedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, RedBlackTree value) {
  return listAddFrontI64PRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile RedBlackTree* value) {
  return listAddFrontI64PRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, HashTable value) {
  return listAddFrontI64HashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile HashTable* value) {
  return listAddFrontI64HashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, HashTable value) {
  return listAddFrontI64PHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile HashTable* value) {
  return listAddFrontI64PHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, Vector value) {
  return listAddFrontI64Vector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile Vector* value) {
  return listAddFrontI64VectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, Vector value) {
  return listAddFrontI64PVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile Vector* value) {
  return listAddFrontI64PVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile char* value) {
  return listAddFrontI64String(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile char** value) {
  return listAddFrontI64StringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile char* value) {
  return listAddFrontI64PString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile char** value) {
  return listAddFrontI64PStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, Bytes value) {
  return listAddFrontI64Bytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile Bytes* value) {
  return listAddFrontI64BytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, Bytes value) {
  return listAddFrontI64PBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile Bytes* value) {
  return listAddFrontI64PBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, void* value) {
  return listAddFrontI64Pointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, const volatile void** value) {
  return listAddFrontI64PointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, void* value) {
  return listAddFrontI64PPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, const volatile void** value) {
  return listAddFrontI64PPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, i8 value) {
  return listAddFrontI64I8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, i8 value) {
  return listAddFrontI64PI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i64 key, u8 value) {
  return listAddFrontI64U8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile i64* key, u8 value) {
  return listAddFrontI64PU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, bool value) {
  return listAddFrontU64Bool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile bool* value) {
  return listAddFrontU64BoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, bool value) {
  return listAddFrontU64PBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile bool* value) {
  return listAddFrontU64PBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, i16 value) {
  return listAddFrontU64I16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile i16* value) {
  return listAddFrontU64I16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, i16 value) {
  return listAddFrontU64PI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile i16* value) {
  return listAddFrontU64PI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, u16 value) {
  return listAddFrontU64U16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile u16* value) {
  return listAddFrontU64U16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, u16 value) {
  return listAddFrontU64PU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile u16* value) {
  return listAddFrontU64PU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, i32 value) {
  return listAddFrontU64I32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile i32* value) {
  return listAddFrontU64I32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, i32 value) {
  return listAddFrontU64PI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile i32* value) {
  return listAddFrontU64PI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, u32 value) {
  return listAddFrontU64U32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile u32* value) {
  return listAddFrontU64U32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, u32 value) {
  return listAddFrontU64PU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile u32* value) {
  return listAddFrontU64PU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, i64 value) {
  return listAddFrontU64I64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile i64* value) {
  return listAddFrontU64I64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, i64 value) {
  return listAddFrontU64PI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile i64* value) {
  return listAddFrontU64PI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, u64 value) {
  return listAddFrontU64U64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile u64* value) {
  return listAddFrontU64U64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, u64 value) {
  return listAddFrontU64PU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile u64* value) {
  return listAddFrontU64PU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, float value) {
  return listAddFrontU64Float(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile float* value) {
  return listAddFrontU64FloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, float value) {
  return listAddFrontU64PFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile float* value) {
  return listAddFrontU64PFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, double value) {
  return listAddFrontU64Double(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile double* value) {
  return listAddFrontU64DoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, double value) {
  return listAddFrontU64PDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile double* value) {
  return listAddFrontU64PDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, long double value) {
  return listAddFrontU64LongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile long double* value) {
  return listAddFrontU64LongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, long double value) {
  return listAddFrontU64PLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile long double* value) {
  return listAddFrontU64PLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, List value) {
  return listAddFrontU64List(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile List* value) {
  return listAddFrontU64ListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, List value) {
  return listAddFrontU64PList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile List* value) {
  return listAddFrontU64PListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, Queue value) {
  return listAddFrontU64Queue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile Queue* value) {
  return listAddFrontU64QueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, Queue value) {
  return listAddFrontU64PQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile Queue* value) {
  return listAddFrontU64PQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, Stack value) {
  return listAddFrontU64Stack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile Stack* value) {
  return listAddFrontU64StackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, Stack value) {
  return listAddFrontU64PStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile Stack* value) {
  return listAddFrontU64PStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, RedBlackTree value) {
  return listAddFrontU64RedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile RedBlackTree* value) {
  return listAddFrontU64RedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, RedBlackTree value) {
  return listAddFrontU64PRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile RedBlackTree* value) {
  return listAddFrontU64PRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, HashTable value) {
  return listAddFrontU64HashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile HashTable* value) {
  return listAddFrontU64HashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, HashTable value) {
  return listAddFrontU64PHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile HashTable* value) {
  return listAddFrontU64PHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, Vector value) {
  return listAddFrontU64Vector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile Vector* value) {
  return listAddFrontU64VectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, Vector value) {
  return listAddFrontU64PVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile Vector* value) {
  return listAddFrontU64PVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile char* value) {
  return listAddFrontU64String(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile char** value) {
  return listAddFrontU64StringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile char* value) {
  return listAddFrontU64PString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile char** value) {
  return listAddFrontU64PStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, Bytes value) {
  return listAddFrontU64Bytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile Bytes* value) {
  return listAddFrontU64BytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, Bytes value) {
  return listAddFrontU64PBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile Bytes* value) {
  return listAddFrontU64PBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, void* value) {
  return listAddFrontU64Pointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, const volatile void** value) {
  return listAddFrontU64PointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, void* value) {
  return listAddFrontU64PPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, const volatile void** value) {
  return listAddFrontU64PPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, i8 value) {
  return listAddFrontU64I8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, i8 value) {
  return listAddFrontU64PI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u64 key, u8 value) {
  return listAddFrontU64U8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile u64* key, u8 value) {
  return listAddFrontU64PU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, bool value) {
  return listAddFrontFloatBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile bool* value) {
  return listAddFrontFloatBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, bool value) {
  return listAddFrontFloatPBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile bool* value) {
  return listAddFrontFloatPBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, i16 value) {
  return listAddFrontFloatI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile i16* value) {
  return listAddFrontFloatI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, i16 value) {
  return listAddFrontFloatPI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile i16* value) {
  return listAddFrontFloatPI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, u16 value) {
  return listAddFrontFloatU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile u16* value) {
  return listAddFrontFloatU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, u16 value) {
  return listAddFrontFloatPU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile u16* value) {
  return listAddFrontFloatPU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, i32 value) {
  return listAddFrontFloatI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile i32* value) {
  return listAddFrontFloatI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, i32 value) {
  return listAddFrontFloatPI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile i32* value) {
  return listAddFrontFloatPI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, u32 value) {
  return listAddFrontFloatU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile u32* value) {
  return listAddFrontFloatU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, u32 value) {
  return listAddFrontFloatPU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile u32* value) {
  return listAddFrontFloatPU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, i64 value) {
  return listAddFrontFloatI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile i64* value) {
  return listAddFrontFloatI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, i64 value) {
  return listAddFrontFloatPI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile i64* value) {
  return listAddFrontFloatPI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, u64 value) {
  return listAddFrontFloatU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile u64* value) {
  return listAddFrontFloatU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, u64 value) {
  return listAddFrontFloatPU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile u64* value) {
  return listAddFrontFloatPU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, float value) {
  return listAddFrontFloatFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile float* value) {
  return listAddFrontFloatFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, float value) {
  return listAddFrontFloatPFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile float* value) {
  return listAddFrontFloatPFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, double value) {
  return listAddFrontFloatDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile double* value) {
  return listAddFrontFloatDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, double value) {
  return listAddFrontFloatPDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile double* value) {
  return listAddFrontFloatPDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, long double value) {
  return listAddFrontFloatLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile long double* value) {
  return listAddFrontFloatLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, long double value) {
  return listAddFrontFloatPLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile long double* value) {
  return listAddFrontFloatPLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, List value) {
  return listAddFrontFloatList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile List* value) {
  return listAddFrontFloatListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, List value) {
  return listAddFrontFloatPList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile List* value) {
  return listAddFrontFloatPListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, Queue value) {
  return listAddFrontFloatQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile Queue* value) {
  return listAddFrontFloatQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, Queue value) {
  return listAddFrontFloatPQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile Queue* value) {
  return listAddFrontFloatPQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, Stack value) {
  return listAddFrontFloatStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile Stack* value) {
  return listAddFrontFloatStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, Stack value) {
  return listAddFrontFloatPStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile Stack* value) {
  return listAddFrontFloatPStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, RedBlackTree value) {
  return listAddFrontFloatRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile RedBlackTree* value) {
  return listAddFrontFloatRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, RedBlackTree value) {
  return listAddFrontFloatPRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile RedBlackTree* value) {
  return listAddFrontFloatPRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, HashTable value) {
  return listAddFrontFloatHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile HashTable* value) {
  return listAddFrontFloatHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, HashTable value) {
  return listAddFrontFloatPHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile HashTable* value) {
  return listAddFrontFloatPHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, Vector value) {
  return listAddFrontFloatVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile Vector* value) {
  return listAddFrontFloatVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, Vector value) {
  return listAddFrontFloatPVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile Vector* value) {
  return listAddFrontFloatPVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile char* value) {
  return listAddFrontFloatString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile char** value) {
  return listAddFrontFloatStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile char* value) {
  return listAddFrontFloatPString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile char** value) {
  return listAddFrontFloatPStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, Bytes value) {
  return listAddFrontFloatBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile Bytes* value) {
  return listAddFrontFloatBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, Bytes value) {
  return listAddFrontFloatPBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile Bytes* value) {
  return listAddFrontFloatPBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, void* value) {
  return listAddFrontFloatPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, const volatile void** value) {
  return listAddFrontFloatPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, void* value) {
  return listAddFrontFloatPPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, const volatile void** value) {
  return listAddFrontFloatPPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, i8 value) {
  return listAddFrontFloatI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, i8 value) {
  return listAddFrontFloatPI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, float key, u8 value) {
  return listAddFrontFloatU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile float* key, u8 value) {
  return listAddFrontFloatPU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, bool value) {
  return listAddFrontDoubleBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile bool* value) {
  return listAddFrontDoubleBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, bool value) {
  return listAddFrontDoublePBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile bool* value) {
  return listAddFrontDoublePBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, i16 value) {
  return listAddFrontDoubleI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile i16* value) {
  return listAddFrontDoubleI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, i16 value) {
  return listAddFrontDoublePI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile i16* value) {
  return listAddFrontDoublePI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, u16 value) {
  return listAddFrontDoubleU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile u16* value) {
  return listAddFrontDoubleU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, u16 value) {
  return listAddFrontDoublePU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile u16* value) {
  return listAddFrontDoublePU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, i32 value) {
  return listAddFrontDoubleI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile i32* value) {
  return listAddFrontDoubleI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, i32 value) {
  return listAddFrontDoublePI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile i32* value) {
  return listAddFrontDoublePI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, u32 value) {
  return listAddFrontDoubleU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile u32* value) {
  return listAddFrontDoubleU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, u32 value) {
  return listAddFrontDoublePU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile u32* value) {
  return listAddFrontDoublePU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, i64 value) {
  return listAddFrontDoubleI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile i64* value) {
  return listAddFrontDoubleI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, i64 value) {
  return listAddFrontDoublePI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile i64* value) {
  return listAddFrontDoublePI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, u64 value) {
  return listAddFrontDoubleU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile u64* value) {
  return listAddFrontDoubleU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, u64 value) {
  return listAddFrontDoublePU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile u64* value) {
  return listAddFrontDoublePU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, float value) {
  return listAddFrontDoubleFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile float* value) {
  return listAddFrontDoubleFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, float value) {
  return listAddFrontDoublePFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile float* value) {
  return listAddFrontDoublePFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, double value) {
  return listAddFrontDoubleDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile double* value) {
  return listAddFrontDoubleDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, double value) {
  return listAddFrontDoublePDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile double* value) {
  return listAddFrontDoublePDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, long double value) {
  return listAddFrontDoubleLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile long double* value) {
  return listAddFrontDoubleLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, long double value) {
  return listAddFrontDoublePLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile long double* value) {
  return listAddFrontDoublePLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, List value) {
  return listAddFrontDoubleList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile List* value) {
  return listAddFrontDoubleListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, List value) {
  return listAddFrontDoublePList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile List* value) {
  return listAddFrontDoublePListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, Queue value) {
  return listAddFrontDoubleQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile Queue* value) {
  return listAddFrontDoubleQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, Queue value) {
  return listAddFrontDoublePQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile Queue* value) {
  return listAddFrontDoublePQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, Stack value) {
  return listAddFrontDoubleStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile Stack* value) {
  return listAddFrontDoubleStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, Stack value) {
  return listAddFrontDoublePStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile Stack* value) {
  return listAddFrontDoublePStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, RedBlackTree value) {
  return listAddFrontDoubleRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile RedBlackTree* value) {
  return listAddFrontDoubleRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, RedBlackTree value) {
  return listAddFrontDoublePRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile RedBlackTree* value) {
  return listAddFrontDoublePRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, HashTable value) {
  return listAddFrontDoubleHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile HashTable* value) {
  return listAddFrontDoubleHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, HashTable value) {
  return listAddFrontDoublePHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile HashTable* value) {
  return listAddFrontDoublePHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, Vector value) {
  return listAddFrontDoubleVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile Vector* value) {
  return listAddFrontDoubleVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, Vector value) {
  return listAddFrontDoublePVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile Vector* value) {
  return listAddFrontDoublePVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile char* value) {
  return listAddFrontDoubleString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile char** value) {
  return listAddFrontDoubleStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile char* value) {
  return listAddFrontDoublePString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile char** value) {
  return listAddFrontDoublePStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, Bytes value) {
  return listAddFrontDoubleBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile Bytes* value) {
  return listAddFrontDoubleBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, Bytes value) {
  return listAddFrontDoublePBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile Bytes* value) {
  return listAddFrontDoublePBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, void* value) {
  return listAddFrontDoublePointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, const volatile void** value) {
  return listAddFrontDoublePointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, void* value) {
  return listAddFrontDoublePPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, const volatile void** value) {
  return listAddFrontDoublePPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, i8 value) {
  return listAddFrontDoubleI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, i8 value) {
  return listAddFrontDoublePI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, double key, u8 value) {
  return listAddFrontDoubleU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile double* key, u8 value) {
  return listAddFrontDoublePU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, bool value) {
  return listAddFrontLongDoubleBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile bool* value) {
  return listAddFrontLongDoubleBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, bool value) {
  return listAddFrontLongDoublePBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile bool* value) {
  return listAddFrontLongDoublePBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, i16 value) {
  return listAddFrontLongDoubleI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile i16* value) {
  return listAddFrontLongDoubleI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, i16 value) {
  return listAddFrontLongDoublePI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile i16* value) {
  return listAddFrontLongDoublePI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, u16 value) {
  return listAddFrontLongDoubleU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile u16* value) {
  return listAddFrontLongDoubleU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, u16 value) {
  return listAddFrontLongDoublePU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile u16* value) {
  return listAddFrontLongDoublePU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, i32 value) {
  return listAddFrontLongDoubleI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile i32* value) {
  return listAddFrontLongDoubleI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, i32 value) {
  return listAddFrontLongDoublePI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile i32* value) {
  return listAddFrontLongDoublePI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, u32 value) {
  return listAddFrontLongDoubleU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile u32* value) {
  return listAddFrontLongDoubleU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, u32 value) {
  return listAddFrontLongDoublePU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile u32* value) {
  return listAddFrontLongDoublePU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, i64 value) {
  return listAddFrontLongDoubleI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile i64* value) {
  return listAddFrontLongDoubleI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, i64 value) {
  return listAddFrontLongDoublePI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile i64* value) {
  return listAddFrontLongDoublePI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, u64 value) {
  return listAddFrontLongDoubleU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile u64* value) {
  return listAddFrontLongDoubleU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, u64 value) {
  return listAddFrontLongDoublePU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile u64* value) {
  return listAddFrontLongDoublePU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, float value) {
  return listAddFrontLongDoubleFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile float* value) {
  return listAddFrontLongDoubleFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, float value) {
  return listAddFrontLongDoublePFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile float* value) {
  return listAddFrontLongDoublePFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, double value) {
  return listAddFrontLongDoubleDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile double* value) {
  return listAddFrontLongDoubleDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, double value) {
  return listAddFrontLongDoublePDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile double* value) {
  return listAddFrontLongDoublePDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, long double value) {
  return listAddFrontLongDoubleLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile long double* value) {
  return listAddFrontLongDoubleLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, long double value) {
  return listAddFrontLongDoublePLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile long double* value) {
  return listAddFrontLongDoublePLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, List value) {
  return listAddFrontLongDoubleList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile List* value) {
  return listAddFrontLongDoubleListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, List value) {
  return listAddFrontLongDoublePList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile List* value) {
  return listAddFrontLongDoublePListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, Queue value) {
  return listAddFrontLongDoubleQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile Queue* value) {
  return listAddFrontLongDoubleQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, Queue value) {
  return listAddFrontLongDoublePQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile Queue* value) {
  return listAddFrontLongDoublePQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, Stack value) {
  return listAddFrontLongDoubleStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile Stack* value) {
  return listAddFrontLongDoubleStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, Stack value) {
  return listAddFrontLongDoublePStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile Stack* value) {
  return listAddFrontLongDoublePStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, RedBlackTree value) {
  return listAddFrontLongDoubleRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile RedBlackTree* value) {
  return listAddFrontLongDoubleRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, RedBlackTree value) {
  return listAddFrontLongDoublePRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile RedBlackTree* value) {
  return listAddFrontLongDoublePRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, HashTable value) {
  return listAddFrontLongDoubleHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile HashTable* value) {
  return listAddFrontLongDoubleHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, HashTable value) {
  return listAddFrontLongDoublePHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile HashTable* value) {
  return listAddFrontLongDoublePHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, Vector value) {
  return listAddFrontLongDoubleVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile Vector* value) {
  return listAddFrontLongDoubleVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, Vector value) {
  return listAddFrontLongDoublePVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile Vector* value) {
  return listAddFrontLongDoublePVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile char* value) {
  return listAddFrontLongDoubleString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile char** value) {
  return listAddFrontLongDoubleStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile char* value) {
  return listAddFrontLongDoublePString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile char** value) {
  return listAddFrontLongDoublePStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, Bytes value) {
  return listAddFrontLongDoubleBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile Bytes* value) {
  return listAddFrontLongDoubleBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, Bytes value) {
  return listAddFrontLongDoublePBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile Bytes* value) {
  return listAddFrontLongDoublePBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, void* value) {
  return listAddFrontLongDoublePointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, const volatile void** value) {
  return listAddFrontLongDoublePointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, void* value) {
  return listAddFrontLongDoublePPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, const volatile void** value) {
  return listAddFrontLongDoublePPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, i8 value) {
  return listAddFrontLongDoubleI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, i8 value) {
  return listAddFrontLongDoublePI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, long double key, u8 value) {
  return listAddFrontLongDoubleU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile long double* key, u8 value) {
  return listAddFrontLongDoublePU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, bool value) {
  return listAddFrontListBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile bool* value) {
  return listAddFrontListBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, bool value) {
  return listAddFrontListPBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile bool* value) {
  return listAddFrontListPBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, i16 value) {
  return listAddFrontListI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile i16* value) {
  return listAddFrontListI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, i16 value) {
  return listAddFrontListPI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile i16* value) {
  return listAddFrontListPI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, u16 value) {
  return listAddFrontListU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile u16* value) {
  return listAddFrontListU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, u16 value) {
  return listAddFrontListPU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile u16* value) {
  return listAddFrontListPU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, i32 value) {
  return listAddFrontListI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile i32* value) {
  return listAddFrontListI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, i32 value) {
  return listAddFrontListPI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile i32* value) {
  return listAddFrontListPI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, u32 value) {
  return listAddFrontListU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile u32* value) {
  return listAddFrontListU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, u32 value) {
  return listAddFrontListPU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile u32* value) {
  return listAddFrontListPU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, i64 value) {
  return listAddFrontListI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile i64* value) {
  return listAddFrontListI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, i64 value) {
  return listAddFrontListPI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile i64* value) {
  return listAddFrontListPI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, u64 value) {
  return listAddFrontListU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile u64* value) {
  return listAddFrontListU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, u64 value) {
  return listAddFrontListPU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile u64* value) {
  return listAddFrontListPU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, float value) {
  return listAddFrontListFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile float* value) {
  return listAddFrontListFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, float value) {
  return listAddFrontListPFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile float* value) {
  return listAddFrontListPFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, double value) {
  return listAddFrontListDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile double* value) {
  return listAddFrontListDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, double value) {
  return listAddFrontListPDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile double* value) {
  return listAddFrontListPDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, long double value) {
  return listAddFrontListLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile long double* value) {
  return listAddFrontListLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, long double value) {
  return listAddFrontListPLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile long double* value) {
  return listAddFrontListPLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, List value) {
  return listAddFrontListList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile List* value) {
  return listAddFrontListListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, List value) {
  return listAddFrontListPList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile List* value) {
  return listAddFrontListPListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, Queue value) {
  return listAddFrontListQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile Queue* value) {
  return listAddFrontListQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, Queue value) {
  return listAddFrontListPQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile Queue* value) {
  return listAddFrontListPQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, Stack value) {
  return listAddFrontListStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile Stack* value) {
  return listAddFrontListStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, Stack value) {
  return listAddFrontListPStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile Stack* value) {
  return listAddFrontListPStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, RedBlackTree value) {
  return listAddFrontListRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile RedBlackTree* value) {
  return listAddFrontListRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, RedBlackTree value) {
  return listAddFrontListPRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile RedBlackTree* value) {
  return listAddFrontListPRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, HashTable value) {
  return listAddFrontListHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile HashTable* value) {
  return listAddFrontListHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, HashTable value) {
  return listAddFrontListPHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile HashTable* value) {
  return listAddFrontListPHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, Vector value) {
  return listAddFrontListVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile Vector* value) {
  return listAddFrontListVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, Vector value) {
  return listAddFrontListPVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile Vector* value) {
  return listAddFrontListPVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile char* value) {
  return listAddFrontListString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile char** value) {
  return listAddFrontListStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile char* value) {
  return listAddFrontListPString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile char** value) {
  return listAddFrontListPStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, Bytes value) {
  return listAddFrontListBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile Bytes* value) {
  return listAddFrontListBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, Bytes value) {
  return listAddFrontListPBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile Bytes* value) {
  return listAddFrontListPBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, void* value) {
  return listAddFrontListPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, const volatile void** value) {
  return listAddFrontListPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, void* value) {
  return listAddFrontListPPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, const volatile void** value) {
  return listAddFrontListPPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, i8 value) {
  return listAddFrontListI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, i8 value) {
  return listAddFrontListPI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, List key, u8 value) {
  return listAddFrontListU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile List* key, u8 value) {
  return listAddFrontListPU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, bool value) {
  return listAddFrontQueueBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile bool* value) {
  return listAddFrontQueueBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, bool value) {
  return listAddFrontQueuePBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile bool* value) {
  return listAddFrontQueuePBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, i16 value) {
  return listAddFrontQueueI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile i16* value) {
  return listAddFrontQueueI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, i16 value) {
  return listAddFrontQueuePI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile i16* value) {
  return listAddFrontQueuePI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, u16 value) {
  return listAddFrontQueueU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile u16* value) {
  return listAddFrontQueueU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, u16 value) {
  return listAddFrontQueuePU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile u16* value) {
  return listAddFrontQueuePU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, i32 value) {
  return listAddFrontQueueI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile i32* value) {
  return listAddFrontQueueI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, i32 value) {
  return listAddFrontQueuePI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile i32* value) {
  return listAddFrontQueuePI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, u32 value) {
  return listAddFrontQueueU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile u32* value) {
  return listAddFrontQueueU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, u32 value) {
  return listAddFrontQueuePU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile u32* value) {
  return listAddFrontQueuePU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, i64 value) {
  return listAddFrontQueueI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile i64* value) {
  return listAddFrontQueueI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, i64 value) {
  return listAddFrontQueuePI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile i64* value) {
  return listAddFrontQueuePI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, u64 value) {
  return listAddFrontQueueU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile u64* value) {
  return listAddFrontQueueU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, u64 value) {
  return listAddFrontQueuePU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile u64* value) {
  return listAddFrontQueuePU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, float value) {
  return listAddFrontQueueFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile float* value) {
  return listAddFrontQueueFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, float value) {
  return listAddFrontQueuePFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile float* value) {
  return listAddFrontQueuePFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, double value) {
  return listAddFrontQueueDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile double* value) {
  return listAddFrontQueueDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, double value) {
  return listAddFrontQueuePDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile double* value) {
  return listAddFrontQueuePDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, long double value) {
  return listAddFrontQueueLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile long double* value) {
  return listAddFrontQueueLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, long double value) {
  return listAddFrontQueuePLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile long double* value) {
  return listAddFrontQueuePLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, List value) {
  return listAddFrontQueueList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile List* value) {
  return listAddFrontQueueListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, List value) {
  return listAddFrontQueuePList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile List* value) {
  return listAddFrontQueuePListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, Queue value) {
  return listAddFrontQueueQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile Queue* value) {
  return listAddFrontQueueQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, Queue value) {
  return listAddFrontQueuePQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile Queue* value) {
  return listAddFrontQueuePQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, Stack value) {
  return listAddFrontQueueStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile Stack* value) {
  return listAddFrontQueueStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, Stack value) {
  return listAddFrontQueuePStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile Stack* value) {
  return listAddFrontQueuePStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, RedBlackTree value) {
  return listAddFrontQueueRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile RedBlackTree* value) {
  return listAddFrontQueueRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, RedBlackTree value) {
  return listAddFrontQueuePRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile RedBlackTree* value) {
  return listAddFrontQueuePRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, HashTable value) {
  return listAddFrontQueueHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile HashTable* value) {
  return listAddFrontQueueHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, HashTable value) {
  return listAddFrontQueuePHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile HashTable* value) {
  return listAddFrontQueuePHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, Vector value) {
  return listAddFrontQueueVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile Vector* value) {
  return listAddFrontQueueVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, Vector value) {
  return listAddFrontQueuePVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile Vector* value) {
  return listAddFrontQueuePVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile char* value) {
  return listAddFrontQueueString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile char** value) {
  return listAddFrontQueueStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile char* value) {
  return listAddFrontQueuePString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile char** value) {
  return listAddFrontQueuePStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, Bytes value) {
  return listAddFrontQueueBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile Bytes* value) {
  return listAddFrontQueueBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, Bytes value) {
  return listAddFrontQueuePBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile Bytes* value) {
  return listAddFrontQueuePBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, void* value) {
  return listAddFrontQueuePointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, const volatile void** value) {
  return listAddFrontQueuePointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, void* value) {
  return listAddFrontQueuePPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, const volatile void** value) {
  return listAddFrontQueuePPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, i8 value) {
  return listAddFrontQueueI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, i8 value) {
  return listAddFrontQueuePI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Queue key, u8 value) {
  return listAddFrontQueueU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Queue* key, u8 value) {
  return listAddFrontQueuePU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, bool value) {
  return listAddFrontStackBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile bool* value) {
  return listAddFrontStackBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, bool value) {
  return listAddFrontStackPBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile bool* value) {
  return listAddFrontStackPBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, i16 value) {
  return listAddFrontStackI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile i16* value) {
  return listAddFrontStackI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, i16 value) {
  return listAddFrontStackPI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile i16* value) {
  return listAddFrontStackPI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, u16 value) {
  return listAddFrontStackU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile u16* value) {
  return listAddFrontStackU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, u16 value) {
  return listAddFrontStackPU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile u16* value) {
  return listAddFrontStackPU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, i32 value) {
  return listAddFrontStackI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile i32* value) {
  return listAddFrontStackI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, i32 value) {
  return listAddFrontStackPI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile i32* value) {
  return listAddFrontStackPI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, u32 value) {
  return listAddFrontStackU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile u32* value) {
  return listAddFrontStackU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, u32 value) {
  return listAddFrontStackPU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile u32* value) {
  return listAddFrontStackPU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, i64 value) {
  return listAddFrontStackI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile i64* value) {
  return listAddFrontStackI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, i64 value) {
  return listAddFrontStackPI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile i64* value) {
  return listAddFrontStackPI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, u64 value) {
  return listAddFrontStackU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile u64* value) {
  return listAddFrontStackU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, u64 value) {
  return listAddFrontStackPU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile u64* value) {
  return listAddFrontStackPU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, float value) {
  return listAddFrontStackFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile float* value) {
  return listAddFrontStackFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, float value) {
  return listAddFrontStackPFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile float* value) {
  return listAddFrontStackPFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, double value) {
  return listAddFrontStackDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile double* value) {
  return listAddFrontStackDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, double value) {
  return listAddFrontStackPDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile double* value) {
  return listAddFrontStackPDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, long double value) {
  return listAddFrontStackLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile long double* value) {
  return listAddFrontStackLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, long double value) {
  return listAddFrontStackPLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile long double* value) {
  return listAddFrontStackPLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, List value) {
  return listAddFrontStackList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile List* value) {
  return listAddFrontStackListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, List value) {
  return listAddFrontStackPList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile List* value) {
  return listAddFrontStackPListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, Queue value) {
  return listAddFrontStackQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile Queue* value) {
  return listAddFrontStackQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, Queue value) {
  return listAddFrontStackPQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile Queue* value) {
  return listAddFrontStackPQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, Stack value) {
  return listAddFrontStackStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile Stack* value) {
  return listAddFrontStackStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, Stack value) {
  return listAddFrontStackPStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile Stack* value) {
  return listAddFrontStackPStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, RedBlackTree value) {
  return listAddFrontStackRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile RedBlackTree* value) {
  return listAddFrontStackRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, RedBlackTree value) {
  return listAddFrontStackPRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile RedBlackTree* value) {
  return listAddFrontStackPRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, HashTable value) {
  return listAddFrontStackHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile HashTable* value) {
  return listAddFrontStackHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, HashTable value) {
  return listAddFrontStackPHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile HashTable* value) {
  return listAddFrontStackPHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, Vector value) {
  return listAddFrontStackVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile Vector* value) {
  return listAddFrontStackVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, Vector value) {
  return listAddFrontStackPVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile Vector* value) {
  return listAddFrontStackPVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile char* value) {
  return listAddFrontStackString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile char** value) {
  return listAddFrontStackStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile char* value) {
  return listAddFrontStackPString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile char** value) {
  return listAddFrontStackPStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, Bytes value) {
  return listAddFrontStackBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile Bytes* value) {
  return listAddFrontStackBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, Bytes value) {
  return listAddFrontStackPBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile Bytes* value) {
  return listAddFrontStackPBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, void* value) {
  return listAddFrontStackPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, const volatile void** value) {
  return listAddFrontStackPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, void* value) {
  return listAddFrontStackPPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, const volatile void** value) {
  return listAddFrontStackPPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, i8 value) {
  return listAddFrontStackI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, i8 value) {
  return listAddFrontStackPI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Stack key, u8 value) {
  return listAddFrontStackU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Stack* key, u8 value) {
  return listAddFrontStackPU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, bool value) {
  return listAddFrontRedBlackTreeBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile bool* value) {
  return listAddFrontRedBlackTreeBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, bool value) {
  return listAddFrontRedBlackTreePBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile bool* value) {
  return listAddFrontRedBlackTreePBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, i16 value) {
  return listAddFrontRedBlackTreeI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile i16* value) {
  return listAddFrontRedBlackTreeI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, i16 value) {
  return listAddFrontRedBlackTreePI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile i16* value) {
  return listAddFrontRedBlackTreePI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, u16 value) {
  return listAddFrontRedBlackTreeU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile u16* value) {
  return listAddFrontRedBlackTreeU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, u16 value) {
  return listAddFrontRedBlackTreePU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile u16* value) {
  return listAddFrontRedBlackTreePU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, i32 value) {
  return listAddFrontRedBlackTreeI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile i32* value) {
  return listAddFrontRedBlackTreeI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, i32 value) {
  return listAddFrontRedBlackTreePI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile i32* value) {
  return listAddFrontRedBlackTreePI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, u32 value) {
  return listAddFrontRedBlackTreeU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile u32* value) {
  return listAddFrontRedBlackTreeU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, u32 value) {
  return listAddFrontRedBlackTreePU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile u32* value) {
  return listAddFrontRedBlackTreePU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, i64 value) {
  return listAddFrontRedBlackTreeI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile i64* value) {
  return listAddFrontRedBlackTreeI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, i64 value) {
  return listAddFrontRedBlackTreePI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile i64* value) {
  return listAddFrontRedBlackTreePI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, u64 value) {
  return listAddFrontRedBlackTreeU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile u64* value) {
  return listAddFrontRedBlackTreeU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, u64 value) {
  return listAddFrontRedBlackTreePU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile u64* value) {
  return listAddFrontRedBlackTreePU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, float value) {
  return listAddFrontRedBlackTreeFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile float* value) {
  return listAddFrontRedBlackTreeFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, float value) {
  return listAddFrontRedBlackTreePFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile float* value) {
  return listAddFrontRedBlackTreePFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, double value) {
  return listAddFrontRedBlackTreeDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile double* value) {
  return listAddFrontRedBlackTreeDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, double value) {
  return listAddFrontRedBlackTreePDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile double* value) {
  return listAddFrontRedBlackTreePDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, long double value) {
  return listAddFrontRedBlackTreeLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile long double* value) {
  return listAddFrontRedBlackTreeLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, long double value) {
  return listAddFrontRedBlackTreePLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile long double* value) {
  return listAddFrontRedBlackTreePLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, List value) {
  return listAddFrontRedBlackTreeList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile List* value) {
  return listAddFrontRedBlackTreeListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, List value) {
  return listAddFrontRedBlackTreePList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile List* value) {
  return listAddFrontRedBlackTreePListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, Queue value) {
  return listAddFrontRedBlackTreeQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile Queue* value) {
  return listAddFrontRedBlackTreeQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, Queue value) {
  return listAddFrontRedBlackTreePQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile Queue* value) {
  return listAddFrontRedBlackTreePQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, Stack value) {
  return listAddFrontRedBlackTreeStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile Stack* value) {
  return listAddFrontRedBlackTreeStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, Stack value) {
  return listAddFrontRedBlackTreePStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile Stack* value) {
  return listAddFrontRedBlackTreePStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, RedBlackTree value) {
  return listAddFrontRedBlackTreeRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile RedBlackTree* value) {
  return listAddFrontRedBlackTreeRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, RedBlackTree value) {
  return listAddFrontRedBlackTreePRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile RedBlackTree* value) {
  return listAddFrontRedBlackTreePRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, HashTable value) {
  return listAddFrontRedBlackTreeHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile HashTable* value) {
  return listAddFrontRedBlackTreeHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, HashTable value) {
  return listAddFrontRedBlackTreePHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile HashTable* value) {
  return listAddFrontRedBlackTreePHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, Vector value) {
  return listAddFrontRedBlackTreeVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile Vector* value) {
  return listAddFrontRedBlackTreeVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, Vector value) {
  return listAddFrontRedBlackTreePVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile Vector* value) {
  return listAddFrontRedBlackTreePVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile char* value) {
  return listAddFrontRedBlackTreeString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile char** value) {
  return listAddFrontRedBlackTreeStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile char* value) {
  return listAddFrontRedBlackTreePString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile char** value) {
  return listAddFrontRedBlackTreePStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, Bytes value) {
  return listAddFrontRedBlackTreeBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile Bytes* value) {
  return listAddFrontRedBlackTreeBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, Bytes value) {
  return listAddFrontRedBlackTreePBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile Bytes* value) {
  return listAddFrontRedBlackTreePBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, void* value) {
  return listAddFrontRedBlackTreePointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, const volatile void** value) {
  return listAddFrontRedBlackTreePointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, void* value) {
  return listAddFrontRedBlackTreePPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, const volatile void** value) {
  return listAddFrontRedBlackTreePPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, i8 value) {
  return listAddFrontRedBlackTreeI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, i8 value) {
  return listAddFrontRedBlackTreePI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, RedBlackTree key, u8 value) {
  return listAddFrontRedBlackTreeU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile RedBlackTree* key, u8 value) {
  return listAddFrontRedBlackTreePU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, bool value) {
  return listAddFrontHashTableBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile bool* value) {
  return listAddFrontHashTableBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, bool value) {
  return listAddFrontHashTablePBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile bool* value) {
  return listAddFrontHashTablePBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, i16 value) {
  return listAddFrontHashTableI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile i16* value) {
  return listAddFrontHashTableI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, i16 value) {
  return listAddFrontHashTablePI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile i16* value) {
  return listAddFrontHashTablePI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, u16 value) {
  return listAddFrontHashTableU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile u16* value) {
  return listAddFrontHashTableU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, u16 value) {
  return listAddFrontHashTablePU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile u16* value) {
  return listAddFrontHashTablePU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, i32 value) {
  return listAddFrontHashTableI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile i32* value) {
  return listAddFrontHashTableI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, i32 value) {
  return listAddFrontHashTablePI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile i32* value) {
  return listAddFrontHashTablePI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, u32 value) {
  return listAddFrontHashTableU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile u32* value) {
  return listAddFrontHashTableU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, u32 value) {
  return listAddFrontHashTablePU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile u32* value) {
  return listAddFrontHashTablePU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, i64 value) {
  return listAddFrontHashTableI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile i64* value) {
  return listAddFrontHashTableI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, i64 value) {
  return listAddFrontHashTablePI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile i64* value) {
  return listAddFrontHashTablePI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, u64 value) {
  return listAddFrontHashTableU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile u64* value) {
  return listAddFrontHashTableU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, u64 value) {
  return listAddFrontHashTablePU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile u64* value) {
  return listAddFrontHashTablePU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, float value) {
  return listAddFrontHashTableFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile float* value) {
  return listAddFrontHashTableFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, float value) {
  return listAddFrontHashTablePFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile float* value) {
  return listAddFrontHashTablePFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, double value) {
  return listAddFrontHashTableDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile double* value) {
  return listAddFrontHashTableDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, double value) {
  return listAddFrontHashTablePDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile double* value) {
  return listAddFrontHashTablePDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, long double value) {
  return listAddFrontHashTableLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile long double* value) {
  return listAddFrontHashTableLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, long double value) {
  return listAddFrontHashTablePLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile long double* value) {
  return listAddFrontHashTablePLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, List value) {
  return listAddFrontHashTableList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile List* value) {
  return listAddFrontHashTableListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, List value) {
  return listAddFrontHashTablePList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile List* value) {
  return listAddFrontHashTablePListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, Queue value) {
  return listAddFrontHashTableQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile Queue* value) {
  return listAddFrontHashTableQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, Queue value) {
  return listAddFrontHashTablePQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile Queue* value) {
  return listAddFrontHashTablePQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, Stack value) {
  return listAddFrontHashTableStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile Stack* value) {
  return listAddFrontHashTableStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, Stack value) {
  return listAddFrontHashTablePStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile Stack* value) {
  return listAddFrontHashTablePStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, RedBlackTree value) {
  return listAddFrontHashTableRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile RedBlackTree* value) {
  return listAddFrontHashTableRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, RedBlackTree value) {
  return listAddFrontHashTablePRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile RedBlackTree* value) {
  return listAddFrontHashTablePRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, HashTable value) {
  return listAddFrontHashTableHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile HashTable* value) {
  return listAddFrontHashTableHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, HashTable value) {
  return listAddFrontHashTablePHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile HashTable* value) {
  return listAddFrontHashTablePHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, Vector value) {
  return listAddFrontHashTableVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile Vector* value) {
  return listAddFrontHashTableVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, Vector value) {
  return listAddFrontHashTablePVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile Vector* value) {
  return listAddFrontHashTablePVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile char* value) {
  return listAddFrontHashTableString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile char** value) {
  return listAddFrontHashTableStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile char* value) {
  return listAddFrontHashTablePString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile char** value) {
  return listAddFrontHashTablePStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, Bytes value) {
  return listAddFrontHashTableBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile Bytes* value) {
  return listAddFrontHashTableBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, Bytes value) {
  return listAddFrontHashTablePBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile Bytes* value) {
  return listAddFrontHashTablePBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, void* value) {
  return listAddFrontHashTablePointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, const volatile void** value) {
  return listAddFrontHashTablePointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, void* value) {
  return listAddFrontHashTablePPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, const volatile void** value) {
  return listAddFrontHashTablePPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, i8 value) {
  return listAddFrontHashTableI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, i8 value) {
  return listAddFrontHashTablePI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, HashTable key, u8 value) {
  return listAddFrontHashTableU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile HashTable* key, u8 value) {
  return listAddFrontHashTablePU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, bool value) {
  return listAddFrontVectorBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile bool* value) {
  return listAddFrontVectorBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, bool value) {
  return listAddFrontVectorPBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile bool* value) {
  return listAddFrontVectorPBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, i16 value) {
  return listAddFrontVectorI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile i16* value) {
  return listAddFrontVectorI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, i16 value) {
  return listAddFrontVectorPI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile i16* value) {
  return listAddFrontVectorPI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, u16 value) {
  return listAddFrontVectorU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile u16* value) {
  return listAddFrontVectorU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, u16 value) {
  return listAddFrontVectorPU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile u16* value) {
  return listAddFrontVectorPU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, i32 value) {
  return listAddFrontVectorI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile i32* value) {
  return listAddFrontVectorI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, i32 value) {
  return listAddFrontVectorPI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile i32* value) {
  return listAddFrontVectorPI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, u32 value) {
  return listAddFrontVectorU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile u32* value) {
  return listAddFrontVectorU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, u32 value) {
  return listAddFrontVectorPU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile u32* value) {
  return listAddFrontVectorPU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, i64 value) {
  return listAddFrontVectorI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile i64* value) {
  return listAddFrontVectorI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, i64 value) {
  return listAddFrontVectorPI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile i64* value) {
  return listAddFrontVectorPI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, u64 value) {
  return listAddFrontVectorU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile u64* value) {
  return listAddFrontVectorU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, u64 value) {
  return listAddFrontVectorPU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile u64* value) {
  return listAddFrontVectorPU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, float value) {
  return listAddFrontVectorFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile float* value) {
  return listAddFrontVectorFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, float value) {
  return listAddFrontVectorPFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile float* value) {
  return listAddFrontVectorPFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, double value) {
  return listAddFrontVectorDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile double* value) {
  return listAddFrontVectorDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, double value) {
  return listAddFrontVectorPDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile double* value) {
  return listAddFrontVectorPDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, long double value) {
  return listAddFrontVectorLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile long double* value) {
  return listAddFrontVectorLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, long double value) {
  return listAddFrontVectorPLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile long double* value) {
  return listAddFrontVectorPLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, List value) {
  return listAddFrontVectorList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile List* value) {
  return listAddFrontVectorListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, List value) {
  return listAddFrontVectorPList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile List* value) {
  return listAddFrontVectorPListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, Queue value) {
  return listAddFrontVectorQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile Queue* value) {
  return listAddFrontVectorQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, Queue value) {
  return listAddFrontVectorPQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile Queue* value) {
  return listAddFrontVectorPQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, Stack value) {
  return listAddFrontVectorStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile Stack* value) {
  return listAddFrontVectorStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, Stack value) {
  return listAddFrontVectorPStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile Stack* value) {
  return listAddFrontVectorPStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, RedBlackTree value) {
  return listAddFrontVectorRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile RedBlackTree* value) {
  return listAddFrontVectorRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, RedBlackTree value) {
  return listAddFrontVectorPRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile RedBlackTree* value) {
  return listAddFrontVectorPRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, HashTable value) {
  return listAddFrontVectorHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile HashTable* value) {
  return listAddFrontVectorHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, HashTable value) {
  return listAddFrontVectorPHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile HashTable* value) {
  return listAddFrontVectorPHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, Vector value) {
  return listAddFrontVectorVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile Vector* value) {
  return listAddFrontVectorVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, Vector value) {
  return listAddFrontVectorPVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile Vector* value) {
  return listAddFrontVectorPVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile char* value) {
  return listAddFrontVectorString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile char** value) {
  return listAddFrontVectorStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile char* value) {
  return listAddFrontVectorPString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile char** value) {
  return listAddFrontVectorPStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, Bytes value) {
  return listAddFrontVectorBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile Bytes* value) {
  return listAddFrontVectorBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, Bytes value) {
  return listAddFrontVectorPBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile Bytes* value) {
  return listAddFrontVectorPBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, void* value) {
  return listAddFrontVectorPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, const volatile void** value) {
  return listAddFrontVectorPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, void* value) {
  return listAddFrontVectorPPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, const volatile void** value) {
  return listAddFrontVectorPPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, i8 value) {
  return listAddFrontVectorI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, i8 value) {
  return listAddFrontVectorPI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Vector key, u8 value) {
  return listAddFrontVectorU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Vector* key, u8 value) {
  return listAddFrontVectorPU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, bool value) {
  return listAddFrontStringBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile bool* value) {
  return listAddFrontStringBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, bool value) {
  return listAddFrontStringPBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile bool* value) {
  return listAddFrontStringPBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, i16 value) {
  return listAddFrontStringI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile i16* value) {
  return listAddFrontStringI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, i16 value) {
  return listAddFrontStringPI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile i16* value) {
  return listAddFrontStringPI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, u16 value) {
  return listAddFrontStringU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile u16* value) {
  return listAddFrontStringU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, u16 value) {
  return listAddFrontStringPU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile u16* value) {
  return listAddFrontStringPU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, i32 value) {
  return listAddFrontStringI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile i32* value) {
  return listAddFrontStringI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, i32 value) {
  return listAddFrontStringPI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile i32* value) {
  return listAddFrontStringPI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, u32 value) {
  return listAddFrontStringU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile u32* value) {
  return listAddFrontStringU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, u32 value) {
  return listAddFrontStringPU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile u32* value) {
  return listAddFrontStringPU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, i64 value) {
  return listAddFrontStringI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile i64* value) {
  return listAddFrontStringI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, i64 value) {
  return listAddFrontStringPI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile i64* value) {
  return listAddFrontStringPI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, u64 value) {
  return listAddFrontStringU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile u64* value) {
  return listAddFrontStringU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, u64 value) {
  return listAddFrontStringPU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile u64* value) {
  return listAddFrontStringPU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, float value) {
  return listAddFrontStringFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile float* value) {
  return listAddFrontStringFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, float value) {
  return listAddFrontStringPFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile float* value) {
  return listAddFrontStringPFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, double value) {
  return listAddFrontStringDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile double* value) {
  return listAddFrontStringDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, double value) {
  return listAddFrontStringPDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile double* value) {
  return listAddFrontStringPDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, long double value) {
  return listAddFrontStringLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile long double* value) {
  return listAddFrontStringLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, long double value) {
  return listAddFrontStringPLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile long double* value) {
  return listAddFrontStringPLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, List value) {
  return listAddFrontStringList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile List* value) {
  return listAddFrontStringListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, List value) {
  return listAddFrontStringPList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile List* value) {
  return listAddFrontStringPListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, Queue value) {
  return listAddFrontStringQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile Queue* value) {
  return listAddFrontStringQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, Queue value) {
  return listAddFrontStringPQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile Queue* value) {
  return listAddFrontStringPQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, Stack value) {
  return listAddFrontStringStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile Stack* value) {
  return listAddFrontStringStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, Stack value) {
  return listAddFrontStringPStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile Stack* value) {
  return listAddFrontStringPStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, RedBlackTree value) {
  return listAddFrontStringRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile RedBlackTree* value) {
  return listAddFrontStringRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, RedBlackTree value) {
  return listAddFrontStringPRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile RedBlackTree* value) {
  return listAddFrontStringPRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, HashTable value) {
  return listAddFrontStringHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile HashTable* value) {
  return listAddFrontStringHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, HashTable value) {
  return listAddFrontStringPHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile HashTable* value) {
  return listAddFrontStringPHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, Vector value) {
  return listAddFrontStringVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile Vector* value) {
  return listAddFrontStringVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, Vector value) {
  return listAddFrontStringPVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile Vector* value) {
  return listAddFrontStringPVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile char* value) {
  return listAddFrontStringString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile char** value) {
  return listAddFrontStringStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile char* value) {
  return listAddFrontStringPString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile char** value) {
  return listAddFrontStringPStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, Bytes value) {
  return listAddFrontStringBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile Bytes* value) {
  return listAddFrontStringBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, Bytes value) {
  return listAddFrontStringPBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile Bytes* value) {
  return listAddFrontStringPBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, void* value) {
  return listAddFrontStringPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, const volatile void** value) {
  return listAddFrontStringPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, void* value) {
  return listAddFrontStringPPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, const volatile void** value) {
  return listAddFrontStringPPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, i8 value) {
  return listAddFrontStringI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, i8 value) {
  return listAddFrontStringPI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char* key, u8 value) {
  return listAddFrontStringU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile char** key, u8 value) {
  return listAddFrontStringPU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, bool value) {
  return listAddFrontBytesBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile bool* value) {
  return listAddFrontBytesBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, bool value) {
  return listAddFrontBytesPBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile bool* value) {
  return listAddFrontBytesPBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, i16 value) {
  return listAddFrontBytesI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile i16* value) {
  return listAddFrontBytesI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, i16 value) {
  return listAddFrontBytesPI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile i16* value) {
  return listAddFrontBytesPI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, u16 value) {
  return listAddFrontBytesU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile u16* value) {
  return listAddFrontBytesU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, u16 value) {
  return listAddFrontBytesPU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile u16* value) {
  return listAddFrontBytesPU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, i32 value) {
  return listAddFrontBytesI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile i32* value) {
  return listAddFrontBytesI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, i32 value) {
  return listAddFrontBytesPI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile i32* value) {
  return listAddFrontBytesPI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, u32 value) {
  return listAddFrontBytesU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile u32* value) {
  return listAddFrontBytesU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, u32 value) {
  return listAddFrontBytesPU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile u32* value) {
  return listAddFrontBytesPU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, i64 value) {
  return listAddFrontBytesI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile i64* value) {
  return listAddFrontBytesI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, i64 value) {
  return listAddFrontBytesPI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile i64* value) {
  return listAddFrontBytesPI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, u64 value) {
  return listAddFrontBytesU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile u64* value) {
  return listAddFrontBytesU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, u64 value) {
  return listAddFrontBytesPU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile u64* value) {
  return listAddFrontBytesPU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, float value) {
  return listAddFrontBytesFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile float* value) {
  return listAddFrontBytesFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, float value) {
  return listAddFrontBytesPFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile float* value) {
  return listAddFrontBytesPFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, double value) {
  return listAddFrontBytesDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile double* value) {
  return listAddFrontBytesDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, double value) {
  return listAddFrontBytesPDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile double* value) {
  return listAddFrontBytesPDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, long double value) {
  return listAddFrontBytesLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile long double* value) {
  return listAddFrontBytesLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, long double value) {
  return listAddFrontBytesPLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile long double* value) {
  return listAddFrontBytesPLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, List value) {
  return listAddFrontBytesList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile List* value) {
  return listAddFrontBytesListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, List value) {
  return listAddFrontBytesPList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile List* value) {
  return listAddFrontBytesPListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, Queue value) {
  return listAddFrontBytesQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile Queue* value) {
  return listAddFrontBytesQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, Queue value) {
  return listAddFrontBytesPQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile Queue* value) {
  return listAddFrontBytesPQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, Stack value) {
  return listAddFrontBytesStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile Stack* value) {
  return listAddFrontBytesStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, Stack value) {
  return listAddFrontBytesPStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile Stack* value) {
  return listAddFrontBytesPStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, RedBlackTree value) {
  return listAddFrontBytesRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile RedBlackTree* value) {
  return listAddFrontBytesRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, RedBlackTree value) {
  return listAddFrontBytesPRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile RedBlackTree* value) {
  return listAddFrontBytesPRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, HashTable value) {
  return listAddFrontBytesHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile HashTable* value) {
  return listAddFrontBytesHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, HashTable value) {
  return listAddFrontBytesPHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile HashTable* value) {
  return listAddFrontBytesPHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, Vector value) {
  return listAddFrontBytesVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile Vector* value) {
  return listAddFrontBytesVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, Vector value) {
  return listAddFrontBytesPVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile Vector* value) {
  return listAddFrontBytesPVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile char* value) {
  return listAddFrontBytesString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile char** value) {
  return listAddFrontBytesStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile char* value) {
  return listAddFrontBytesPString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile char** value) {
  return listAddFrontBytesPStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, Bytes value) {
  return listAddFrontBytesBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile Bytes* value) {
  return listAddFrontBytesBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, Bytes value) {
  return listAddFrontBytesPBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile Bytes* value) {
  return listAddFrontBytesPBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, void* value) {
  return listAddFrontBytesPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, const volatile void** value) {
  return listAddFrontBytesPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, void* value) {
  return listAddFrontBytesPPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, const volatile void** value) {
  return listAddFrontBytesPPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, i8 value) {
  return listAddFrontBytesI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, i8 value) {
  return listAddFrontBytesPI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, Bytes key, u8 value) {
  return listAddFrontBytesU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile Bytes* key, u8 value) {
  return listAddFrontBytesPU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, bool value) {
  return listAddFrontPointerBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile bool* value) {
  return listAddFrontPointerBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, bool value) {
  return listAddFrontPointerPBool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile bool* value) {
  return listAddFrontPointerPBoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, i16 value) {
  return listAddFrontPointerI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile i16* value) {
  return listAddFrontPointerI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, i16 value) {
  return listAddFrontPointerPI16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile i16* value) {
  return listAddFrontPointerPI16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, u16 value) {
  return listAddFrontPointerU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile u16* value) {
  return listAddFrontPointerU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, u16 value) {
  return listAddFrontPointerPU16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile u16* value) {
  return listAddFrontPointerPU16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, i32 value) {
  return listAddFrontPointerI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile i32* value) {
  return listAddFrontPointerI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, i32 value) {
  return listAddFrontPointerPI32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile i32* value) {
  return listAddFrontPointerPI32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, u32 value) {
  return listAddFrontPointerU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile u32* value) {
  return listAddFrontPointerU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, u32 value) {
  return listAddFrontPointerPU32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile u32* value) {
  return listAddFrontPointerPU32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, i64 value) {
  return listAddFrontPointerI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile i64* value) {
  return listAddFrontPointerI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, i64 value) {
  return listAddFrontPointerPI64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile i64* value) {
  return listAddFrontPointerPI64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, u64 value) {
  return listAddFrontPointerU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile u64* value) {
  return listAddFrontPointerU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, u64 value) {
  return listAddFrontPointerPU64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile u64* value) {
  return listAddFrontPointerPU64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, float value) {
  return listAddFrontPointerFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile float* value) {
  return listAddFrontPointerFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, float value) {
  return listAddFrontPointerPFloat(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile float* value) {
  return listAddFrontPointerPFloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, double value) {
  return listAddFrontPointerDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile double* value) {
  return listAddFrontPointerDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, double value) {
  return listAddFrontPointerPDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile double* value) {
  return listAddFrontPointerPDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, long double value) {
  return listAddFrontPointerLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile long double* value) {
  return listAddFrontPointerLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, long double value) {
  return listAddFrontPointerPLongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile long double* value) {
  return listAddFrontPointerPLongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, List value) {
  return listAddFrontPointerList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile List* value) {
  return listAddFrontPointerListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, List value) {
  return listAddFrontPointerPList(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile List* value) {
  return listAddFrontPointerPListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, Queue value) {
  return listAddFrontPointerQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile Queue* value) {
  return listAddFrontPointerQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, Queue value) {
  return listAddFrontPointerPQueue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile Queue* value) {
  return listAddFrontPointerPQueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, Stack value) {
  return listAddFrontPointerStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile Stack* value) {
  return listAddFrontPointerStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, Stack value) {
  return listAddFrontPointerPStack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile Stack* value) {
  return listAddFrontPointerPStackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, RedBlackTree value) {
  return listAddFrontPointerRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile RedBlackTree* value) {
  return listAddFrontPointerRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, RedBlackTree value) {
  return listAddFrontPointerPRedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile RedBlackTree* value) {
  return listAddFrontPointerPRedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, HashTable value) {
  return listAddFrontPointerHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile HashTable* value) {
  return listAddFrontPointerHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, HashTable value) {
  return listAddFrontPointerPHashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile HashTable* value) {
  return listAddFrontPointerPHashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, Vector value) {
  return listAddFrontPointerVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile Vector* value) {
  return listAddFrontPointerVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, Vector value) {
  return listAddFrontPointerPVector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile Vector* value) {
  return listAddFrontPointerPVectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile char* value) {
  return listAddFrontPointerString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile char** value) {
  return listAddFrontPointerStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile char* value) {
  return listAddFrontPointerPString(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile char** value) {
  return listAddFrontPointerPStringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, Bytes value) {
  return listAddFrontPointerBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile Bytes* value) {
  return listAddFrontPointerBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, Bytes value) {
  return listAddFrontPointerPBytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile Bytes* value) {
  return listAddFrontPointerPBytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, void* value) {
  return listAddFrontPointerPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, const volatile void** value) {
  return listAddFrontPointerPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, void* value) {
  return listAddFrontPointerPPointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, const volatile void** value) {
  return listAddFrontPointerPPointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, i8 value) {
  return listAddFrontPointerI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, i8 value) {
  return listAddFrontPointerPI8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, void* key, u8 value) {
  return listAddFrontPointerU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, const volatile void** key, u8 value) {
  return listAddFrontPointerPU8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, bool value) {
  return listAddFrontI8Bool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile bool* value) {
  return listAddFrontI8BoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, i16 value) {
  return listAddFrontI8I16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile i16* value) {
  return listAddFrontI8I16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, u16 value) {
  return listAddFrontI8U16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile u16* value) {
  return listAddFrontI8U16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, i32 value) {
  return listAddFrontI8I32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile i32* value) {
  return listAddFrontI8I32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, u32 value) {
  return listAddFrontI8U32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile u32* value) {
  return listAddFrontI8U32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, i64 value) {
  return listAddFrontI8I64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile i64* value) {
  return listAddFrontI8I64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, u64 value) {
  return listAddFrontI8U64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile u64* value) {
  return listAddFrontI8U64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, float value) {
  return listAddFrontI8Float(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile float* value) {
  return listAddFrontI8FloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, double value) {
  return listAddFrontI8Double(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile double* value) {
  return listAddFrontI8DoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, long double value) {
  return listAddFrontI8LongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile long double* value) {
  return listAddFrontI8LongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, List value) {
  return listAddFrontI8List(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile List* value) {
  return listAddFrontI8ListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, Queue value) {
  return listAddFrontI8Queue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile Queue* value) {
  return listAddFrontI8QueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, Stack value) {
  return listAddFrontI8Stack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile Stack* value) {
  return listAddFrontI8StackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, RedBlackTree value) {
  return listAddFrontI8RedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile RedBlackTree* value) {
  return listAddFrontI8RedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, HashTable value) {
  return listAddFrontI8HashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile HashTable* value) {
  return listAddFrontI8HashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, Vector value) {
  return listAddFrontI8Vector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile Vector* value) {
  return listAddFrontI8VectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile char* value) {
  return listAddFrontI8String(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile char** value) {
  return listAddFrontI8StringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, Bytes value) {
  return listAddFrontI8Bytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile Bytes* value) {
  return listAddFrontI8BytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, void* value) {
  return listAddFrontI8Pointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, const volatile void** value) {
  return listAddFrontI8PointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, i8 value) {
  return listAddFrontI8I8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, i8 key, u8 value) {
  return listAddFrontI8U8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, bool value) {
  return listAddFrontU8Bool(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile bool* value) {
  return listAddFrontU8BoolP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, i16 value) {
  return listAddFrontU8I16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile i16* value) {
  return listAddFrontU8I16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, u16 value) {
  return listAddFrontU8U16(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile u16* value) {
  return listAddFrontU8U16P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, i32 value) {
  return listAddFrontU8I32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile i32* value) {
  return listAddFrontU8I32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, u32 value) {
  return listAddFrontU8U32(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile u32* value) {
  return listAddFrontU8U32P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, i64 value) {
  return listAddFrontU8I64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile i64* value) {
  return listAddFrontU8I64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, u64 value) {
  return listAddFrontU8U64(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile u64* value) {
  return listAddFrontU8U64P(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, float value) {
  return listAddFrontU8Float(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile float* value) {
  return listAddFrontU8FloatP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, double value) {
  return listAddFrontU8Double(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile double* value) {
  return listAddFrontU8DoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, long double value) {
  return listAddFrontU8LongDouble(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile long double* value) {
  return listAddFrontU8LongDoubleP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, List value) {
  return listAddFrontU8List(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile List* value) {
  return listAddFrontU8ListP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, Queue value) {
  return listAddFrontU8Queue(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile Queue* value) {
  return listAddFrontU8QueueP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, Stack value) {
  return listAddFrontU8Stack(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile Stack* value) {
  return listAddFrontU8StackP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, RedBlackTree value) {
  return listAddFrontU8RedBlackTree(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile RedBlackTree* value) {
  return listAddFrontU8RedBlackTreeP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, HashTable value) {
  return listAddFrontU8HashTable(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile HashTable* value) {
  return listAddFrontU8HashTableP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, Vector value) {
  return listAddFrontU8Vector(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile Vector* value) {
  return listAddFrontU8VectorP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile char* value) {
  return listAddFrontU8String(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile char** value) {
  return listAddFrontU8StringP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, Bytes value) {
  return listAddFrontU8Bytes(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile Bytes* value) {
  return listAddFrontU8BytesP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, void* value) {
  return listAddFrontU8Pointer(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, const volatile void** value) {
  return listAddFrontU8PointerP(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, i8 value) {
  return listAddFrontU8I8(dataStructure, key, value);
}
static inline ListNode* listAddFront(List *dataStructure, u8 key, u8 value) {
  return listAddFrontU8U8(dataStructure, key, value);
}

#endif // __cplusplus

#endif // TYPE_SAFE_LIST_ADD_FRONT_H

