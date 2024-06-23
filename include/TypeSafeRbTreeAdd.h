///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              04.21.2024
///
/// @file              TypeSafeRbTreeAdd.h
///
/// @brief             This header contains type-safe versions of the
///                    rbTreeAdd function.
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


#ifndef TYPE_SAFE_RB_TREE_ADD_H
#define TYPE_SAFE_RB_TREE_ADD_H

#include "DataTypes.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Type-safe inline functions.

static inline RedBlackTreeNode* rbTreeAddBoolBool(RedBlackTree *dataStructure, bool key, bool value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddBoolBoolP(RedBlackTree *dataStructure, bool key, const volatile bool* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPBool(RedBlackTree *dataStructure, const volatile bool* key, bool value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddBoolPBoolP(RedBlackTree *dataStructure, const volatile bool* key, const volatile bool* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolI16(RedBlackTree *dataStructure, bool key, i16 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddBoolI16P(RedBlackTree *dataStructure, bool key, const volatile i16* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPI16(RedBlackTree *dataStructure, const volatile bool* key, i16 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddBoolPI16P(RedBlackTree *dataStructure, const volatile bool* key, const volatile i16* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolU16(RedBlackTree *dataStructure, bool key, u16 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddBoolU16P(RedBlackTree *dataStructure, bool key, const volatile u16* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPU16(RedBlackTree *dataStructure, const volatile bool* key, u16 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddBoolPU16P(RedBlackTree *dataStructure, const volatile bool* key, const volatile u16* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolI32(RedBlackTree *dataStructure, bool key, i32 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddBoolI32P(RedBlackTree *dataStructure, bool key, const volatile i32* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPI32(RedBlackTree *dataStructure, const volatile bool* key, i32 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddBoolPI32P(RedBlackTree *dataStructure, const volatile bool* key, const volatile i32* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolU32(RedBlackTree *dataStructure, bool key, u32 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddBoolU32P(RedBlackTree *dataStructure, bool key, const volatile u32* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPU32(RedBlackTree *dataStructure, const volatile bool* key, u32 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddBoolPU32P(RedBlackTree *dataStructure, const volatile bool* key, const volatile u32* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolI64(RedBlackTree *dataStructure, bool key, i64 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddBoolI64P(RedBlackTree *dataStructure, bool key, const volatile i64* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPI64(RedBlackTree *dataStructure, const volatile bool* key, i64 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddBoolPI64P(RedBlackTree *dataStructure, const volatile bool* key, const volatile i64* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolU64(RedBlackTree *dataStructure, bool key, u64 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddBoolU64P(RedBlackTree *dataStructure, bool key, const volatile u64* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPU64(RedBlackTree *dataStructure, const volatile bool* key, u64 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddBoolPU64P(RedBlackTree *dataStructure, const volatile bool* key, const volatile u64* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolFloat(RedBlackTree *dataStructure, bool key, float value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddBoolFloatP(RedBlackTree *dataStructure, bool key, const volatile float* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPFloat(RedBlackTree *dataStructure, const volatile bool* key, float value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddBoolPFloatP(RedBlackTree *dataStructure, const volatile bool* key, const volatile float* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolDouble(RedBlackTree *dataStructure, bool key, double value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddBoolDoubleP(RedBlackTree *dataStructure, bool key, const volatile double* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPDouble(RedBlackTree *dataStructure, const volatile bool* key, double value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddBoolPDoubleP(RedBlackTree *dataStructure, const volatile bool* key, const volatile double* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolLongDouble(RedBlackTree *dataStructure, bool key, long double value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddBoolLongDoubleP(RedBlackTree *dataStructure, bool key, const volatile long double* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPLongDouble(RedBlackTree *dataStructure, const volatile bool* key, long double value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddBoolPLongDoubleP(RedBlackTree *dataStructure, const volatile bool* key, const volatile long double* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolList(RedBlackTree *dataStructure, bool key, List value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddBoolListP(RedBlackTree *dataStructure, bool key, const volatile List* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPList(RedBlackTree *dataStructure, const volatile bool* key, List value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddBoolPListP(RedBlackTree *dataStructure, const volatile bool* key, const volatile List* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolQueue(RedBlackTree *dataStructure, bool key, Queue value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddBoolQueueP(RedBlackTree *dataStructure, bool key, const volatile Queue* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPQueue(RedBlackTree *dataStructure, const volatile bool* key, Queue value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddBoolPQueueP(RedBlackTree *dataStructure, const volatile bool* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolStack(RedBlackTree *dataStructure, bool key, Stack value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddBoolStackP(RedBlackTree *dataStructure, bool key, const volatile Stack* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPStack(RedBlackTree *dataStructure, const volatile bool* key, Stack value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddBoolPStackP(RedBlackTree *dataStructure, const volatile bool* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolRedBlackTree(RedBlackTree *dataStructure, bool key, RedBlackTree value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddBoolRedBlackTreeP(RedBlackTree *dataStructure, bool key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPRedBlackTree(RedBlackTree *dataStructure, const volatile bool* key, RedBlackTree value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddBoolPRedBlackTreeP(RedBlackTree *dataStructure, const volatile bool* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolHashTable(RedBlackTree *dataStructure, bool key, HashTable value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddBoolHashTableP(RedBlackTree *dataStructure, bool key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPHashTable(RedBlackTree *dataStructure, const volatile bool* key, HashTable value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddBoolPHashTableP(RedBlackTree *dataStructure, const volatile bool* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolVector(RedBlackTree *dataStructure, bool key, Vector value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddBoolVectorP(RedBlackTree *dataStructure, bool key, const volatile Vector* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPVector(RedBlackTree *dataStructure, const volatile bool* key, Vector value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddBoolPVectorP(RedBlackTree *dataStructure, const volatile bool* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolString(RedBlackTree *dataStructure, bool key, const volatile char* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddBoolStringP(RedBlackTree *dataStructure, bool key, const volatile char** value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPString(RedBlackTree *dataStructure, const volatile bool* key, const volatile char* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddBoolPStringP(RedBlackTree *dataStructure, const volatile bool* key, const volatile char** value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolBytes(RedBlackTree *dataStructure, bool key, Bytes value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddBoolBytesP(RedBlackTree *dataStructure, bool key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPBytes(RedBlackTree *dataStructure, const volatile bool* key, Bytes value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddBoolPBytesP(RedBlackTree *dataStructure, const volatile bool* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPointer(RedBlackTree *dataStructure, bool key, void* value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddBoolPointerP(RedBlackTree *dataStructure, bool key, const volatile void** value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolPPointer(RedBlackTree *dataStructure, const volatile bool* key, void* value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddBoolPPointerP(RedBlackTree *dataStructure, const volatile bool* key, const volatile void** value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBoolI8(RedBlackTree *dataStructure, bool key, i8 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddBoolPI8(RedBlackTree *dataStructure, const volatile bool* key, i8 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddBoolU8(RedBlackTree *dataStructure, bool key, u8 value) {
  if (dataStructure->keyType != typeBool) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddBoolPU8(RedBlackTree *dataStructure, const volatile bool* key, u8 value) {
  if (dataStructure->keyType != typeBoolNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddI16Bool(RedBlackTree *dataStructure, i16 key, bool value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddI16BoolP(RedBlackTree *dataStructure, i16 key, const volatile bool* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PBool(RedBlackTree *dataStructure, const volatile i16* key, bool value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddI16PBoolP(RedBlackTree *dataStructure, const volatile i16* key, const volatile bool* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16I16(RedBlackTree *dataStructure, i16 key, i16 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddI16I16P(RedBlackTree *dataStructure, i16 key, const volatile i16* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PI16(RedBlackTree *dataStructure, const volatile i16* key, i16 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddI16PI16P(RedBlackTree *dataStructure, const volatile i16* key, const volatile i16* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16U16(RedBlackTree *dataStructure, i16 key, u16 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddI16U16P(RedBlackTree *dataStructure, i16 key, const volatile u16* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PU16(RedBlackTree *dataStructure, const volatile i16* key, u16 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddI16PU16P(RedBlackTree *dataStructure, const volatile i16* key, const volatile u16* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16I32(RedBlackTree *dataStructure, i16 key, i32 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddI16I32P(RedBlackTree *dataStructure, i16 key, const volatile i32* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PI32(RedBlackTree *dataStructure, const volatile i16* key, i32 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddI16PI32P(RedBlackTree *dataStructure, const volatile i16* key, const volatile i32* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16U32(RedBlackTree *dataStructure, i16 key, u32 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddI16U32P(RedBlackTree *dataStructure, i16 key, const volatile u32* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PU32(RedBlackTree *dataStructure, const volatile i16* key, u32 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddI16PU32P(RedBlackTree *dataStructure, const volatile i16* key, const volatile u32* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16I64(RedBlackTree *dataStructure, i16 key, i64 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddI16I64P(RedBlackTree *dataStructure, i16 key, const volatile i64* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PI64(RedBlackTree *dataStructure, const volatile i16* key, i64 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddI16PI64P(RedBlackTree *dataStructure, const volatile i16* key, const volatile i64* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16U64(RedBlackTree *dataStructure, i16 key, u64 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddI16U64P(RedBlackTree *dataStructure, i16 key, const volatile u64* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PU64(RedBlackTree *dataStructure, const volatile i16* key, u64 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddI16PU64P(RedBlackTree *dataStructure, const volatile i16* key, const volatile u64* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16Float(RedBlackTree *dataStructure, i16 key, float value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddI16FloatP(RedBlackTree *dataStructure, i16 key, const volatile float* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PFloat(RedBlackTree *dataStructure, const volatile i16* key, float value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddI16PFloatP(RedBlackTree *dataStructure, const volatile i16* key, const volatile float* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16Double(RedBlackTree *dataStructure, i16 key, double value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddI16DoubleP(RedBlackTree *dataStructure, i16 key, const volatile double* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PDouble(RedBlackTree *dataStructure, const volatile i16* key, double value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddI16PDoubleP(RedBlackTree *dataStructure, const volatile i16* key, const volatile double* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16LongDouble(RedBlackTree *dataStructure, i16 key, long double value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddI16LongDoubleP(RedBlackTree *dataStructure, i16 key, const volatile long double* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PLongDouble(RedBlackTree *dataStructure, const volatile i16* key, long double value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddI16PLongDoubleP(RedBlackTree *dataStructure, const volatile i16* key, const volatile long double* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16List(RedBlackTree *dataStructure, i16 key, List value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddI16ListP(RedBlackTree *dataStructure, i16 key, const volatile List* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PList(RedBlackTree *dataStructure, const volatile i16* key, List value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddI16PListP(RedBlackTree *dataStructure, const volatile i16* key, const volatile List* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16Queue(RedBlackTree *dataStructure, i16 key, Queue value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddI16QueueP(RedBlackTree *dataStructure, i16 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PQueue(RedBlackTree *dataStructure, const volatile i16* key, Queue value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddI16PQueueP(RedBlackTree *dataStructure, const volatile i16* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16Stack(RedBlackTree *dataStructure, i16 key, Stack value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddI16StackP(RedBlackTree *dataStructure, i16 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PStack(RedBlackTree *dataStructure, const volatile i16* key, Stack value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddI16PStackP(RedBlackTree *dataStructure, const volatile i16* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16RedBlackTree(RedBlackTree *dataStructure, i16 key, RedBlackTree value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddI16RedBlackTreeP(RedBlackTree *dataStructure, i16 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PRedBlackTree(RedBlackTree *dataStructure, const volatile i16* key, RedBlackTree value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddI16PRedBlackTreeP(RedBlackTree *dataStructure, const volatile i16* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16HashTable(RedBlackTree *dataStructure, i16 key, HashTable value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddI16HashTableP(RedBlackTree *dataStructure, i16 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PHashTable(RedBlackTree *dataStructure, const volatile i16* key, HashTable value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddI16PHashTableP(RedBlackTree *dataStructure, const volatile i16* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16Vector(RedBlackTree *dataStructure, i16 key, Vector value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddI16VectorP(RedBlackTree *dataStructure, i16 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PVector(RedBlackTree *dataStructure, const volatile i16* key, Vector value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddI16PVectorP(RedBlackTree *dataStructure, const volatile i16* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16String(RedBlackTree *dataStructure, i16 key, const volatile char* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddI16StringP(RedBlackTree *dataStructure, i16 key, const volatile char** value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PString(RedBlackTree *dataStructure, const volatile i16* key, const volatile char* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddI16PStringP(RedBlackTree *dataStructure, const volatile i16* key, const volatile char** value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16Bytes(RedBlackTree *dataStructure, i16 key, Bytes value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddI16BytesP(RedBlackTree *dataStructure, i16 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PBytes(RedBlackTree *dataStructure, const volatile i16* key, Bytes value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddI16PBytesP(RedBlackTree *dataStructure, const volatile i16* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16Pointer(RedBlackTree *dataStructure, i16 key, void* value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddI16PointerP(RedBlackTree *dataStructure, i16 key, const volatile void** value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16PPointer(RedBlackTree *dataStructure, const volatile i16* key, void* value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddI16PPointerP(RedBlackTree *dataStructure, const volatile i16* key, const volatile void** value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI16I8(RedBlackTree *dataStructure, i16 key, i8 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddI16PI8(RedBlackTree *dataStructure, const volatile i16* key, i8 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddI16U8(RedBlackTree *dataStructure, i16 key, u8 value) {
  if (dataStructure->keyType != typeI16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddI16PU8(RedBlackTree *dataStructure, const volatile i16* key, u8 value) {
  if (dataStructure->keyType != typeI16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddU16Bool(RedBlackTree *dataStructure, u16 key, bool value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddU16BoolP(RedBlackTree *dataStructure, u16 key, const volatile bool* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PBool(RedBlackTree *dataStructure, const volatile u16* key, bool value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddU16PBoolP(RedBlackTree *dataStructure, const volatile u16* key, const volatile bool* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16I16(RedBlackTree *dataStructure, u16 key, i16 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddU16I16P(RedBlackTree *dataStructure, u16 key, const volatile i16* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PI16(RedBlackTree *dataStructure, const volatile u16* key, i16 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddU16PI16P(RedBlackTree *dataStructure, const volatile u16* key, const volatile i16* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16U16(RedBlackTree *dataStructure, u16 key, u16 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddU16U16P(RedBlackTree *dataStructure, u16 key, const volatile u16* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PU16(RedBlackTree *dataStructure, const volatile u16* key, u16 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddU16PU16P(RedBlackTree *dataStructure, const volatile u16* key, const volatile u16* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16I32(RedBlackTree *dataStructure, u16 key, i32 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddU16I32P(RedBlackTree *dataStructure, u16 key, const volatile i32* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PI32(RedBlackTree *dataStructure, const volatile u16* key, i32 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddU16PI32P(RedBlackTree *dataStructure, const volatile u16* key, const volatile i32* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16U32(RedBlackTree *dataStructure, u16 key, u32 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddU16U32P(RedBlackTree *dataStructure, u16 key, const volatile u32* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PU32(RedBlackTree *dataStructure, const volatile u16* key, u32 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddU16PU32P(RedBlackTree *dataStructure, const volatile u16* key, const volatile u32* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16I64(RedBlackTree *dataStructure, u16 key, i64 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddU16I64P(RedBlackTree *dataStructure, u16 key, const volatile i64* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PI64(RedBlackTree *dataStructure, const volatile u16* key, i64 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddU16PI64P(RedBlackTree *dataStructure, const volatile u16* key, const volatile i64* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16U64(RedBlackTree *dataStructure, u16 key, u64 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddU16U64P(RedBlackTree *dataStructure, u16 key, const volatile u64* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PU64(RedBlackTree *dataStructure, const volatile u16* key, u64 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddU16PU64P(RedBlackTree *dataStructure, const volatile u16* key, const volatile u64* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16Float(RedBlackTree *dataStructure, u16 key, float value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddU16FloatP(RedBlackTree *dataStructure, u16 key, const volatile float* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PFloat(RedBlackTree *dataStructure, const volatile u16* key, float value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddU16PFloatP(RedBlackTree *dataStructure, const volatile u16* key, const volatile float* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16Double(RedBlackTree *dataStructure, u16 key, double value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddU16DoubleP(RedBlackTree *dataStructure, u16 key, const volatile double* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PDouble(RedBlackTree *dataStructure, const volatile u16* key, double value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddU16PDoubleP(RedBlackTree *dataStructure, const volatile u16* key, const volatile double* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16LongDouble(RedBlackTree *dataStructure, u16 key, long double value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddU16LongDoubleP(RedBlackTree *dataStructure, u16 key, const volatile long double* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PLongDouble(RedBlackTree *dataStructure, const volatile u16* key, long double value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddU16PLongDoubleP(RedBlackTree *dataStructure, const volatile u16* key, const volatile long double* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16List(RedBlackTree *dataStructure, u16 key, List value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddU16ListP(RedBlackTree *dataStructure, u16 key, const volatile List* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PList(RedBlackTree *dataStructure, const volatile u16* key, List value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddU16PListP(RedBlackTree *dataStructure, const volatile u16* key, const volatile List* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16Queue(RedBlackTree *dataStructure, u16 key, Queue value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddU16QueueP(RedBlackTree *dataStructure, u16 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PQueue(RedBlackTree *dataStructure, const volatile u16* key, Queue value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddU16PQueueP(RedBlackTree *dataStructure, const volatile u16* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16Stack(RedBlackTree *dataStructure, u16 key, Stack value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddU16StackP(RedBlackTree *dataStructure, u16 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PStack(RedBlackTree *dataStructure, const volatile u16* key, Stack value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddU16PStackP(RedBlackTree *dataStructure, const volatile u16* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16RedBlackTree(RedBlackTree *dataStructure, u16 key, RedBlackTree value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddU16RedBlackTreeP(RedBlackTree *dataStructure, u16 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PRedBlackTree(RedBlackTree *dataStructure, const volatile u16* key, RedBlackTree value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddU16PRedBlackTreeP(RedBlackTree *dataStructure, const volatile u16* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16HashTable(RedBlackTree *dataStructure, u16 key, HashTable value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddU16HashTableP(RedBlackTree *dataStructure, u16 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PHashTable(RedBlackTree *dataStructure, const volatile u16* key, HashTable value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddU16PHashTableP(RedBlackTree *dataStructure, const volatile u16* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16Vector(RedBlackTree *dataStructure, u16 key, Vector value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddU16VectorP(RedBlackTree *dataStructure, u16 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PVector(RedBlackTree *dataStructure, const volatile u16* key, Vector value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddU16PVectorP(RedBlackTree *dataStructure, const volatile u16* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16String(RedBlackTree *dataStructure, u16 key, const volatile char* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddU16StringP(RedBlackTree *dataStructure, u16 key, const volatile char** value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PString(RedBlackTree *dataStructure, const volatile u16* key, const volatile char* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddU16PStringP(RedBlackTree *dataStructure, const volatile u16* key, const volatile char** value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16Bytes(RedBlackTree *dataStructure, u16 key, Bytes value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddU16BytesP(RedBlackTree *dataStructure, u16 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PBytes(RedBlackTree *dataStructure, const volatile u16* key, Bytes value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddU16PBytesP(RedBlackTree *dataStructure, const volatile u16* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16Pointer(RedBlackTree *dataStructure, u16 key, void* value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddU16PointerP(RedBlackTree *dataStructure, u16 key, const volatile void** value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16PPointer(RedBlackTree *dataStructure, const volatile u16* key, void* value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddU16PPointerP(RedBlackTree *dataStructure, const volatile u16* key, const volatile void** value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU16I8(RedBlackTree *dataStructure, u16 key, i8 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddU16PI8(RedBlackTree *dataStructure, const volatile u16* key, i8 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddU16U8(RedBlackTree *dataStructure, u16 key, u8 value) {
  if (dataStructure->keyType != typeU16) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddU16PU8(RedBlackTree *dataStructure, const volatile u16* key, u8 value) {
  if (dataStructure->keyType != typeU16NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddI32Bool(RedBlackTree *dataStructure, i32 key, bool value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddI32BoolP(RedBlackTree *dataStructure, i32 key, const volatile bool* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PBool(RedBlackTree *dataStructure, const volatile i32* key, bool value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddI32PBoolP(RedBlackTree *dataStructure, const volatile i32* key, const volatile bool* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32I16(RedBlackTree *dataStructure, i32 key, i16 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddI32I16P(RedBlackTree *dataStructure, i32 key, const volatile i16* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PI16(RedBlackTree *dataStructure, const volatile i32* key, i16 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddI32PI16P(RedBlackTree *dataStructure, const volatile i32* key, const volatile i16* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32U16(RedBlackTree *dataStructure, i32 key, u16 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddI32U16P(RedBlackTree *dataStructure, i32 key, const volatile u16* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PU16(RedBlackTree *dataStructure, const volatile i32* key, u16 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddI32PU16P(RedBlackTree *dataStructure, const volatile i32* key, const volatile u16* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32I32(RedBlackTree *dataStructure, i32 key, i32 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddI32I32P(RedBlackTree *dataStructure, i32 key, const volatile i32* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PI32(RedBlackTree *dataStructure, const volatile i32* key, i32 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddI32PI32P(RedBlackTree *dataStructure, const volatile i32* key, const volatile i32* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32U32(RedBlackTree *dataStructure, i32 key, u32 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddI32U32P(RedBlackTree *dataStructure, i32 key, const volatile u32* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PU32(RedBlackTree *dataStructure, const volatile i32* key, u32 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddI32PU32P(RedBlackTree *dataStructure, const volatile i32* key, const volatile u32* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32I64(RedBlackTree *dataStructure, i32 key, i64 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddI32I64P(RedBlackTree *dataStructure, i32 key, const volatile i64* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PI64(RedBlackTree *dataStructure, const volatile i32* key, i64 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddI32PI64P(RedBlackTree *dataStructure, const volatile i32* key, const volatile i64* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32U64(RedBlackTree *dataStructure, i32 key, u64 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddI32U64P(RedBlackTree *dataStructure, i32 key, const volatile u64* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PU64(RedBlackTree *dataStructure, const volatile i32* key, u64 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddI32PU64P(RedBlackTree *dataStructure, const volatile i32* key, const volatile u64* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32Float(RedBlackTree *dataStructure, i32 key, float value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddI32FloatP(RedBlackTree *dataStructure, i32 key, const volatile float* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PFloat(RedBlackTree *dataStructure, const volatile i32* key, float value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddI32PFloatP(RedBlackTree *dataStructure, const volatile i32* key, const volatile float* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32Double(RedBlackTree *dataStructure, i32 key, double value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddI32DoubleP(RedBlackTree *dataStructure, i32 key, const volatile double* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PDouble(RedBlackTree *dataStructure, const volatile i32* key, double value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddI32PDoubleP(RedBlackTree *dataStructure, const volatile i32* key, const volatile double* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32LongDouble(RedBlackTree *dataStructure, i32 key, long double value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddI32LongDoubleP(RedBlackTree *dataStructure, i32 key, const volatile long double* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PLongDouble(RedBlackTree *dataStructure, const volatile i32* key, long double value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddI32PLongDoubleP(RedBlackTree *dataStructure, const volatile i32* key, const volatile long double* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32List(RedBlackTree *dataStructure, i32 key, List value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddI32ListP(RedBlackTree *dataStructure, i32 key, const volatile List* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PList(RedBlackTree *dataStructure, const volatile i32* key, List value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddI32PListP(RedBlackTree *dataStructure, const volatile i32* key, const volatile List* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32Queue(RedBlackTree *dataStructure, i32 key, Queue value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddI32QueueP(RedBlackTree *dataStructure, i32 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PQueue(RedBlackTree *dataStructure, const volatile i32* key, Queue value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddI32PQueueP(RedBlackTree *dataStructure, const volatile i32* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32Stack(RedBlackTree *dataStructure, i32 key, Stack value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddI32StackP(RedBlackTree *dataStructure, i32 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PStack(RedBlackTree *dataStructure, const volatile i32* key, Stack value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddI32PStackP(RedBlackTree *dataStructure, const volatile i32* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32RedBlackTree(RedBlackTree *dataStructure, i32 key, RedBlackTree value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddI32RedBlackTreeP(RedBlackTree *dataStructure, i32 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PRedBlackTree(RedBlackTree *dataStructure, const volatile i32* key, RedBlackTree value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddI32PRedBlackTreeP(RedBlackTree *dataStructure, const volatile i32* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32HashTable(RedBlackTree *dataStructure, i32 key, HashTable value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddI32HashTableP(RedBlackTree *dataStructure, i32 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PHashTable(RedBlackTree *dataStructure, const volatile i32* key, HashTable value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddI32PHashTableP(RedBlackTree *dataStructure, const volatile i32* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32Vector(RedBlackTree *dataStructure, i32 key, Vector value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddI32VectorP(RedBlackTree *dataStructure, i32 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PVector(RedBlackTree *dataStructure, const volatile i32* key, Vector value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddI32PVectorP(RedBlackTree *dataStructure, const volatile i32* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32String(RedBlackTree *dataStructure, i32 key, const volatile char* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddI32StringP(RedBlackTree *dataStructure, i32 key, const volatile char** value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PString(RedBlackTree *dataStructure, const volatile i32* key, const volatile char* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddI32PStringP(RedBlackTree *dataStructure, const volatile i32* key, const volatile char** value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32Bytes(RedBlackTree *dataStructure, i32 key, Bytes value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddI32BytesP(RedBlackTree *dataStructure, i32 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PBytes(RedBlackTree *dataStructure, const volatile i32* key, Bytes value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddI32PBytesP(RedBlackTree *dataStructure, const volatile i32* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32Pointer(RedBlackTree *dataStructure, i32 key, void* value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddI32PointerP(RedBlackTree *dataStructure, i32 key, const volatile void** value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32PPointer(RedBlackTree *dataStructure, const volatile i32* key, void* value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddI32PPointerP(RedBlackTree *dataStructure, const volatile i32* key, const volatile void** value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI32I8(RedBlackTree *dataStructure, i32 key, i8 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddI32PI8(RedBlackTree *dataStructure, const volatile i32* key, i8 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddI32U8(RedBlackTree *dataStructure, i32 key, u8 value) {
  if (dataStructure->keyType != typeI32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddI32PU8(RedBlackTree *dataStructure, const volatile i32* key, u8 value) {
  if (dataStructure->keyType != typeI32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddU32Bool(RedBlackTree *dataStructure, u32 key, bool value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddU32BoolP(RedBlackTree *dataStructure, u32 key, const volatile bool* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PBool(RedBlackTree *dataStructure, const volatile u32* key, bool value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddU32PBoolP(RedBlackTree *dataStructure, const volatile u32* key, const volatile bool* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32I16(RedBlackTree *dataStructure, u32 key, i16 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddU32I16P(RedBlackTree *dataStructure, u32 key, const volatile i16* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PI16(RedBlackTree *dataStructure, const volatile u32* key, i16 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddU32PI16P(RedBlackTree *dataStructure, const volatile u32* key, const volatile i16* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32U16(RedBlackTree *dataStructure, u32 key, u16 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddU32U16P(RedBlackTree *dataStructure, u32 key, const volatile u16* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PU16(RedBlackTree *dataStructure, const volatile u32* key, u16 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddU32PU16P(RedBlackTree *dataStructure, const volatile u32* key, const volatile u16* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32I32(RedBlackTree *dataStructure, u32 key, i32 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddU32I32P(RedBlackTree *dataStructure, u32 key, const volatile i32* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PI32(RedBlackTree *dataStructure, const volatile u32* key, i32 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddU32PI32P(RedBlackTree *dataStructure, const volatile u32* key, const volatile i32* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32U32(RedBlackTree *dataStructure, u32 key, u32 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddU32U32P(RedBlackTree *dataStructure, u32 key, const volatile u32* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PU32(RedBlackTree *dataStructure, const volatile u32* key, u32 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddU32PU32P(RedBlackTree *dataStructure, const volatile u32* key, const volatile u32* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32I64(RedBlackTree *dataStructure, u32 key, i64 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddU32I64P(RedBlackTree *dataStructure, u32 key, const volatile i64* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PI64(RedBlackTree *dataStructure, const volatile u32* key, i64 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddU32PI64P(RedBlackTree *dataStructure, const volatile u32* key, const volatile i64* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32U64(RedBlackTree *dataStructure, u32 key, u64 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddU32U64P(RedBlackTree *dataStructure, u32 key, const volatile u64* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PU64(RedBlackTree *dataStructure, const volatile u32* key, u64 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddU32PU64P(RedBlackTree *dataStructure, const volatile u32* key, const volatile u64* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32Float(RedBlackTree *dataStructure, u32 key, float value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddU32FloatP(RedBlackTree *dataStructure, u32 key, const volatile float* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PFloat(RedBlackTree *dataStructure, const volatile u32* key, float value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddU32PFloatP(RedBlackTree *dataStructure, const volatile u32* key, const volatile float* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32Double(RedBlackTree *dataStructure, u32 key, double value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddU32DoubleP(RedBlackTree *dataStructure, u32 key, const volatile double* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PDouble(RedBlackTree *dataStructure, const volatile u32* key, double value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddU32PDoubleP(RedBlackTree *dataStructure, const volatile u32* key, const volatile double* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32LongDouble(RedBlackTree *dataStructure, u32 key, long double value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddU32LongDoubleP(RedBlackTree *dataStructure, u32 key, const volatile long double* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PLongDouble(RedBlackTree *dataStructure, const volatile u32* key, long double value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddU32PLongDoubleP(RedBlackTree *dataStructure, const volatile u32* key, const volatile long double* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32List(RedBlackTree *dataStructure, u32 key, List value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddU32ListP(RedBlackTree *dataStructure, u32 key, const volatile List* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PList(RedBlackTree *dataStructure, const volatile u32* key, List value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddU32PListP(RedBlackTree *dataStructure, const volatile u32* key, const volatile List* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32Queue(RedBlackTree *dataStructure, u32 key, Queue value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddU32QueueP(RedBlackTree *dataStructure, u32 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PQueue(RedBlackTree *dataStructure, const volatile u32* key, Queue value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddU32PQueueP(RedBlackTree *dataStructure, const volatile u32* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32Stack(RedBlackTree *dataStructure, u32 key, Stack value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddU32StackP(RedBlackTree *dataStructure, u32 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PStack(RedBlackTree *dataStructure, const volatile u32* key, Stack value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddU32PStackP(RedBlackTree *dataStructure, const volatile u32* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32RedBlackTree(RedBlackTree *dataStructure, u32 key, RedBlackTree value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddU32RedBlackTreeP(RedBlackTree *dataStructure, u32 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PRedBlackTree(RedBlackTree *dataStructure, const volatile u32* key, RedBlackTree value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddU32PRedBlackTreeP(RedBlackTree *dataStructure, const volatile u32* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32HashTable(RedBlackTree *dataStructure, u32 key, HashTable value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddU32HashTableP(RedBlackTree *dataStructure, u32 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PHashTable(RedBlackTree *dataStructure, const volatile u32* key, HashTable value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddU32PHashTableP(RedBlackTree *dataStructure, const volatile u32* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32Vector(RedBlackTree *dataStructure, u32 key, Vector value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddU32VectorP(RedBlackTree *dataStructure, u32 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PVector(RedBlackTree *dataStructure, const volatile u32* key, Vector value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddU32PVectorP(RedBlackTree *dataStructure, const volatile u32* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32String(RedBlackTree *dataStructure, u32 key, const volatile char* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddU32StringP(RedBlackTree *dataStructure, u32 key, const volatile char** value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PString(RedBlackTree *dataStructure, const volatile u32* key, const volatile char* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddU32PStringP(RedBlackTree *dataStructure, const volatile u32* key, const volatile char** value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32Bytes(RedBlackTree *dataStructure, u32 key, Bytes value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddU32BytesP(RedBlackTree *dataStructure, u32 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PBytes(RedBlackTree *dataStructure, const volatile u32* key, Bytes value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddU32PBytesP(RedBlackTree *dataStructure, const volatile u32* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32Pointer(RedBlackTree *dataStructure, u32 key, void* value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddU32PointerP(RedBlackTree *dataStructure, u32 key, const volatile void** value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32PPointer(RedBlackTree *dataStructure, const volatile u32* key, void* value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddU32PPointerP(RedBlackTree *dataStructure, const volatile u32* key, const volatile void** value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU32I8(RedBlackTree *dataStructure, u32 key, i8 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddU32PI8(RedBlackTree *dataStructure, const volatile u32* key, i8 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddU32U8(RedBlackTree *dataStructure, u32 key, u8 value) {
  if (dataStructure->keyType != typeU32) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddU32PU8(RedBlackTree *dataStructure, const volatile u32* key, u8 value) {
  if (dataStructure->keyType != typeU32NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddI64Bool(RedBlackTree *dataStructure, i64 key, bool value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddI64BoolP(RedBlackTree *dataStructure, i64 key, const volatile bool* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PBool(RedBlackTree *dataStructure, const volatile i64* key, bool value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddI64PBoolP(RedBlackTree *dataStructure, const volatile i64* key, const volatile bool* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64I16(RedBlackTree *dataStructure, i64 key, i16 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddI64I16P(RedBlackTree *dataStructure, i64 key, const volatile i16* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PI16(RedBlackTree *dataStructure, const volatile i64* key, i16 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddI64PI16P(RedBlackTree *dataStructure, const volatile i64* key, const volatile i16* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64U16(RedBlackTree *dataStructure, i64 key, u16 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddI64U16P(RedBlackTree *dataStructure, i64 key, const volatile u16* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PU16(RedBlackTree *dataStructure, const volatile i64* key, u16 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddI64PU16P(RedBlackTree *dataStructure, const volatile i64* key, const volatile u16* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64I32(RedBlackTree *dataStructure, i64 key, i32 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddI64I32P(RedBlackTree *dataStructure, i64 key, const volatile i32* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PI32(RedBlackTree *dataStructure, const volatile i64* key, i32 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddI64PI32P(RedBlackTree *dataStructure, const volatile i64* key, const volatile i32* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64U32(RedBlackTree *dataStructure, i64 key, u32 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddI64U32P(RedBlackTree *dataStructure, i64 key, const volatile u32* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PU32(RedBlackTree *dataStructure, const volatile i64* key, u32 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddI64PU32P(RedBlackTree *dataStructure, const volatile i64* key, const volatile u32* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64I64(RedBlackTree *dataStructure, i64 key, i64 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddI64I64P(RedBlackTree *dataStructure, i64 key, const volatile i64* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PI64(RedBlackTree *dataStructure, const volatile i64* key, i64 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddI64PI64P(RedBlackTree *dataStructure, const volatile i64* key, const volatile i64* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64U64(RedBlackTree *dataStructure, i64 key, u64 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddI64U64P(RedBlackTree *dataStructure, i64 key, const volatile u64* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PU64(RedBlackTree *dataStructure, const volatile i64* key, u64 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddI64PU64P(RedBlackTree *dataStructure, const volatile i64* key, const volatile u64* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64Float(RedBlackTree *dataStructure, i64 key, float value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddI64FloatP(RedBlackTree *dataStructure, i64 key, const volatile float* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PFloat(RedBlackTree *dataStructure, const volatile i64* key, float value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddI64PFloatP(RedBlackTree *dataStructure, const volatile i64* key, const volatile float* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64Double(RedBlackTree *dataStructure, i64 key, double value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddI64DoubleP(RedBlackTree *dataStructure, i64 key, const volatile double* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PDouble(RedBlackTree *dataStructure, const volatile i64* key, double value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddI64PDoubleP(RedBlackTree *dataStructure, const volatile i64* key, const volatile double* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64LongDouble(RedBlackTree *dataStructure, i64 key, long double value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddI64LongDoubleP(RedBlackTree *dataStructure, i64 key, const volatile long double* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PLongDouble(RedBlackTree *dataStructure, const volatile i64* key, long double value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddI64PLongDoubleP(RedBlackTree *dataStructure, const volatile i64* key, const volatile long double* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64List(RedBlackTree *dataStructure, i64 key, List value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddI64ListP(RedBlackTree *dataStructure, i64 key, const volatile List* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PList(RedBlackTree *dataStructure, const volatile i64* key, List value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddI64PListP(RedBlackTree *dataStructure, const volatile i64* key, const volatile List* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64Queue(RedBlackTree *dataStructure, i64 key, Queue value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddI64QueueP(RedBlackTree *dataStructure, i64 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PQueue(RedBlackTree *dataStructure, const volatile i64* key, Queue value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddI64PQueueP(RedBlackTree *dataStructure, const volatile i64* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64Stack(RedBlackTree *dataStructure, i64 key, Stack value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddI64StackP(RedBlackTree *dataStructure, i64 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PStack(RedBlackTree *dataStructure, const volatile i64* key, Stack value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddI64PStackP(RedBlackTree *dataStructure, const volatile i64* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64RedBlackTree(RedBlackTree *dataStructure, i64 key, RedBlackTree value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddI64RedBlackTreeP(RedBlackTree *dataStructure, i64 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PRedBlackTree(RedBlackTree *dataStructure, const volatile i64* key, RedBlackTree value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddI64PRedBlackTreeP(RedBlackTree *dataStructure, const volatile i64* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64HashTable(RedBlackTree *dataStructure, i64 key, HashTable value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddI64HashTableP(RedBlackTree *dataStructure, i64 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PHashTable(RedBlackTree *dataStructure, const volatile i64* key, HashTable value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddI64PHashTableP(RedBlackTree *dataStructure, const volatile i64* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64Vector(RedBlackTree *dataStructure, i64 key, Vector value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddI64VectorP(RedBlackTree *dataStructure, i64 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PVector(RedBlackTree *dataStructure, const volatile i64* key, Vector value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddI64PVectorP(RedBlackTree *dataStructure, const volatile i64* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64String(RedBlackTree *dataStructure, i64 key, const volatile char* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddI64StringP(RedBlackTree *dataStructure, i64 key, const volatile char** value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PString(RedBlackTree *dataStructure, const volatile i64* key, const volatile char* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddI64PStringP(RedBlackTree *dataStructure, const volatile i64* key, const volatile char** value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64Bytes(RedBlackTree *dataStructure, i64 key, Bytes value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddI64BytesP(RedBlackTree *dataStructure, i64 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PBytes(RedBlackTree *dataStructure, const volatile i64* key, Bytes value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddI64PBytesP(RedBlackTree *dataStructure, const volatile i64* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64Pointer(RedBlackTree *dataStructure, i64 key, void* value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddI64PointerP(RedBlackTree *dataStructure, i64 key, const volatile void** value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64PPointer(RedBlackTree *dataStructure, const volatile i64* key, void* value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddI64PPointerP(RedBlackTree *dataStructure, const volatile i64* key, const volatile void** value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI64I8(RedBlackTree *dataStructure, i64 key, i8 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddI64PI8(RedBlackTree *dataStructure, const volatile i64* key, i8 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddI64U8(RedBlackTree *dataStructure, i64 key, u8 value) {
  if (dataStructure->keyType != typeI64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddI64PU8(RedBlackTree *dataStructure, const volatile i64* key, u8 value) {
  if (dataStructure->keyType != typeI64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddU64Bool(RedBlackTree *dataStructure, u64 key, bool value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddU64BoolP(RedBlackTree *dataStructure, u64 key, const volatile bool* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PBool(RedBlackTree *dataStructure, const volatile u64* key, bool value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddU64PBoolP(RedBlackTree *dataStructure, const volatile u64* key, const volatile bool* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64I16(RedBlackTree *dataStructure, u64 key, i16 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddU64I16P(RedBlackTree *dataStructure, u64 key, const volatile i16* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PI16(RedBlackTree *dataStructure, const volatile u64* key, i16 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddU64PI16P(RedBlackTree *dataStructure, const volatile u64* key, const volatile i16* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64U16(RedBlackTree *dataStructure, u64 key, u16 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddU64U16P(RedBlackTree *dataStructure, u64 key, const volatile u16* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PU16(RedBlackTree *dataStructure, const volatile u64* key, u16 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddU64PU16P(RedBlackTree *dataStructure, const volatile u64* key, const volatile u16* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64I32(RedBlackTree *dataStructure, u64 key, i32 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddU64I32P(RedBlackTree *dataStructure, u64 key, const volatile i32* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PI32(RedBlackTree *dataStructure, const volatile u64* key, i32 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddU64PI32P(RedBlackTree *dataStructure, const volatile u64* key, const volatile i32* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64U32(RedBlackTree *dataStructure, u64 key, u32 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddU64U32P(RedBlackTree *dataStructure, u64 key, const volatile u32* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PU32(RedBlackTree *dataStructure, const volatile u64* key, u32 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddU64PU32P(RedBlackTree *dataStructure, const volatile u64* key, const volatile u32* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64I64(RedBlackTree *dataStructure, u64 key, i64 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddU64I64P(RedBlackTree *dataStructure, u64 key, const volatile i64* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PI64(RedBlackTree *dataStructure, const volatile u64* key, i64 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddU64PI64P(RedBlackTree *dataStructure, const volatile u64* key, const volatile i64* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64U64(RedBlackTree *dataStructure, u64 key, u64 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddU64U64P(RedBlackTree *dataStructure, u64 key, const volatile u64* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PU64(RedBlackTree *dataStructure, const volatile u64* key, u64 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddU64PU64P(RedBlackTree *dataStructure, const volatile u64* key, const volatile u64* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64Float(RedBlackTree *dataStructure, u64 key, float value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddU64FloatP(RedBlackTree *dataStructure, u64 key, const volatile float* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PFloat(RedBlackTree *dataStructure, const volatile u64* key, float value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddU64PFloatP(RedBlackTree *dataStructure, const volatile u64* key, const volatile float* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64Double(RedBlackTree *dataStructure, u64 key, double value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddU64DoubleP(RedBlackTree *dataStructure, u64 key, const volatile double* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PDouble(RedBlackTree *dataStructure, const volatile u64* key, double value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddU64PDoubleP(RedBlackTree *dataStructure, const volatile u64* key, const volatile double* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64LongDouble(RedBlackTree *dataStructure, u64 key, long double value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddU64LongDoubleP(RedBlackTree *dataStructure, u64 key, const volatile long double* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PLongDouble(RedBlackTree *dataStructure, const volatile u64* key, long double value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddU64PLongDoubleP(RedBlackTree *dataStructure, const volatile u64* key, const volatile long double* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64List(RedBlackTree *dataStructure, u64 key, List value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddU64ListP(RedBlackTree *dataStructure, u64 key, const volatile List* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PList(RedBlackTree *dataStructure, const volatile u64* key, List value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddU64PListP(RedBlackTree *dataStructure, const volatile u64* key, const volatile List* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64Queue(RedBlackTree *dataStructure, u64 key, Queue value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddU64QueueP(RedBlackTree *dataStructure, u64 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PQueue(RedBlackTree *dataStructure, const volatile u64* key, Queue value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddU64PQueueP(RedBlackTree *dataStructure, const volatile u64* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64Stack(RedBlackTree *dataStructure, u64 key, Stack value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddU64StackP(RedBlackTree *dataStructure, u64 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PStack(RedBlackTree *dataStructure, const volatile u64* key, Stack value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddU64PStackP(RedBlackTree *dataStructure, const volatile u64* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64RedBlackTree(RedBlackTree *dataStructure, u64 key, RedBlackTree value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddU64RedBlackTreeP(RedBlackTree *dataStructure, u64 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PRedBlackTree(RedBlackTree *dataStructure, const volatile u64* key, RedBlackTree value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddU64PRedBlackTreeP(RedBlackTree *dataStructure, const volatile u64* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64HashTable(RedBlackTree *dataStructure, u64 key, HashTable value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddU64HashTableP(RedBlackTree *dataStructure, u64 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PHashTable(RedBlackTree *dataStructure, const volatile u64* key, HashTable value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddU64PHashTableP(RedBlackTree *dataStructure, const volatile u64* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64Vector(RedBlackTree *dataStructure, u64 key, Vector value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddU64VectorP(RedBlackTree *dataStructure, u64 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PVector(RedBlackTree *dataStructure, const volatile u64* key, Vector value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddU64PVectorP(RedBlackTree *dataStructure, const volatile u64* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64String(RedBlackTree *dataStructure, u64 key, const volatile char* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddU64StringP(RedBlackTree *dataStructure, u64 key, const volatile char** value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PString(RedBlackTree *dataStructure, const volatile u64* key, const volatile char* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddU64PStringP(RedBlackTree *dataStructure, const volatile u64* key, const volatile char** value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64Bytes(RedBlackTree *dataStructure, u64 key, Bytes value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddU64BytesP(RedBlackTree *dataStructure, u64 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PBytes(RedBlackTree *dataStructure, const volatile u64* key, Bytes value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddU64PBytesP(RedBlackTree *dataStructure, const volatile u64* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64Pointer(RedBlackTree *dataStructure, u64 key, void* value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddU64PointerP(RedBlackTree *dataStructure, u64 key, const volatile void** value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64PPointer(RedBlackTree *dataStructure, const volatile u64* key, void* value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddU64PPointerP(RedBlackTree *dataStructure, const volatile u64* key, const volatile void** value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU64I8(RedBlackTree *dataStructure, u64 key, i8 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddU64PI8(RedBlackTree *dataStructure, const volatile u64* key, i8 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddU64U8(RedBlackTree *dataStructure, u64 key, u8 value) {
  if (dataStructure->keyType != typeU64) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddU64PU8(RedBlackTree *dataStructure, const volatile u64* key, u8 value) {
  if (dataStructure->keyType != typeU64NoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddFloatBool(RedBlackTree *dataStructure, float key, bool value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddFloatBoolP(RedBlackTree *dataStructure, float key, const volatile bool* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPBool(RedBlackTree *dataStructure, const volatile float* key, bool value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddFloatPBoolP(RedBlackTree *dataStructure, const volatile float* key, const volatile bool* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatI16(RedBlackTree *dataStructure, float key, i16 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddFloatI16P(RedBlackTree *dataStructure, float key, const volatile i16* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPI16(RedBlackTree *dataStructure, const volatile float* key, i16 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddFloatPI16P(RedBlackTree *dataStructure, const volatile float* key, const volatile i16* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatU16(RedBlackTree *dataStructure, float key, u16 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddFloatU16P(RedBlackTree *dataStructure, float key, const volatile u16* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPU16(RedBlackTree *dataStructure, const volatile float* key, u16 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddFloatPU16P(RedBlackTree *dataStructure, const volatile float* key, const volatile u16* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatI32(RedBlackTree *dataStructure, float key, i32 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddFloatI32P(RedBlackTree *dataStructure, float key, const volatile i32* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPI32(RedBlackTree *dataStructure, const volatile float* key, i32 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddFloatPI32P(RedBlackTree *dataStructure, const volatile float* key, const volatile i32* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatU32(RedBlackTree *dataStructure, float key, u32 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddFloatU32P(RedBlackTree *dataStructure, float key, const volatile u32* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPU32(RedBlackTree *dataStructure, const volatile float* key, u32 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddFloatPU32P(RedBlackTree *dataStructure, const volatile float* key, const volatile u32* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatI64(RedBlackTree *dataStructure, float key, i64 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddFloatI64P(RedBlackTree *dataStructure, float key, const volatile i64* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPI64(RedBlackTree *dataStructure, const volatile float* key, i64 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddFloatPI64P(RedBlackTree *dataStructure, const volatile float* key, const volatile i64* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatU64(RedBlackTree *dataStructure, float key, u64 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddFloatU64P(RedBlackTree *dataStructure, float key, const volatile u64* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPU64(RedBlackTree *dataStructure, const volatile float* key, u64 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddFloatPU64P(RedBlackTree *dataStructure, const volatile float* key, const volatile u64* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatFloat(RedBlackTree *dataStructure, float key, float value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddFloatFloatP(RedBlackTree *dataStructure, float key, const volatile float* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPFloat(RedBlackTree *dataStructure, const volatile float* key, float value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddFloatPFloatP(RedBlackTree *dataStructure, const volatile float* key, const volatile float* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatDouble(RedBlackTree *dataStructure, float key, double value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddFloatDoubleP(RedBlackTree *dataStructure, float key, const volatile double* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPDouble(RedBlackTree *dataStructure, const volatile float* key, double value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddFloatPDoubleP(RedBlackTree *dataStructure, const volatile float* key, const volatile double* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatLongDouble(RedBlackTree *dataStructure, float key, long double value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddFloatLongDoubleP(RedBlackTree *dataStructure, float key, const volatile long double* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPLongDouble(RedBlackTree *dataStructure, const volatile float* key, long double value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddFloatPLongDoubleP(RedBlackTree *dataStructure, const volatile float* key, const volatile long double* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatList(RedBlackTree *dataStructure, float key, List value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddFloatListP(RedBlackTree *dataStructure, float key, const volatile List* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPList(RedBlackTree *dataStructure, const volatile float* key, List value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddFloatPListP(RedBlackTree *dataStructure, const volatile float* key, const volatile List* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatQueue(RedBlackTree *dataStructure, float key, Queue value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddFloatQueueP(RedBlackTree *dataStructure, float key, const volatile Queue* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPQueue(RedBlackTree *dataStructure, const volatile float* key, Queue value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddFloatPQueueP(RedBlackTree *dataStructure, const volatile float* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatStack(RedBlackTree *dataStructure, float key, Stack value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddFloatStackP(RedBlackTree *dataStructure, float key, const volatile Stack* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPStack(RedBlackTree *dataStructure, const volatile float* key, Stack value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddFloatPStackP(RedBlackTree *dataStructure, const volatile float* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatRedBlackTree(RedBlackTree *dataStructure, float key, RedBlackTree value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddFloatRedBlackTreeP(RedBlackTree *dataStructure, float key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPRedBlackTree(RedBlackTree *dataStructure, const volatile float* key, RedBlackTree value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddFloatPRedBlackTreeP(RedBlackTree *dataStructure, const volatile float* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatHashTable(RedBlackTree *dataStructure, float key, HashTable value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddFloatHashTableP(RedBlackTree *dataStructure, float key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPHashTable(RedBlackTree *dataStructure, const volatile float* key, HashTable value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddFloatPHashTableP(RedBlackTree *dataStructure, const volatile float* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatVector(RedBlackTree *dataStructure, float key, Vector value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddFloatVectorP(RedBlackTree *dataStructure, float key, const volatile Vector* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPVector(RedBlackTree *dataStructure, const volatile float* key, Vector value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddFloatPVectorP(RedBlackTree *dataStructure, const volatile float* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatString(RedBlackTree *dataStructure, float key, const volatile char* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddFloatStringP(RedBlackTree *dataStructure, float key, const volatile char** value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPString(RedBlackTree *dataStructure, const volatile float* key, const volatile char* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddFloatPStringP(RedBlackTree *dataStructure, const volatile float* key, const volatile char** value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatBytes(RedBlackTree *dataStructure, float key, Bytes value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddFloatBytesP(RedBlackTree *dataStructure, float key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPBytes(RedBlackTree *dataStructure, const volatile float* key, Bytes value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddFloatPBytesP(RedBlackTree *dataStructure, const volatile float* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPointer(RedBlackTree *dataStructure, float key, void* value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddFloatPointerP(RedBlackTree *dataStructure, float key, const volatile void** value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatPPointer(RedBlackTree *dataStructure, const volatile float* key, void* value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddFloatPPointerP(RedBlackTree *dataStructure, const volatile float* key, const volatile void** value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddFloatI8(RedBlackTree *dataStructure, float key, i8 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddFloatPI8(RedBlackTree *dataStructure, const volatile float* key, i8 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddFloatU8(RedBlackTree *dataStructure, float key, u8 value) {
  if (dataStructure->keyType != typeFloat) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddFloatPU8(RedBlackTree *dataStructure, const volatile float* key, u8 value) {
  if (dataStructure->keyType != typeFloatNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddDoubleBool(RedBlackTree *dataStructure, double key, bool value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddDoubleBoolP(RedBlackTree *dataStructure, double key, const volatile bool* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePBool(RedBlackTree *dataStructure, const volatile double* key, bool value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddDoublePBoolP(RedBlackTree *dataStructure, const volatile double* key, const volatile bool* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoubleI16(RedBlackTree *dataStructure, double key, i16 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddDoubleI16P(RedBlackTree *dataStructure, double key, const volatile i16* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePI16(RedBlackTree *dataStructure, const volatile double* key, i16 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddDoublePI16P(RedBlackTree *dataStructure, const volatile double* key, const volatile i16* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoubleU16(RedBlackTree *dataStructure, double key, u16 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddDoubleU16P(RedBlackTree *dataStructure, double key, const volatile u16* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePU16(RedBlackTree *dataStructure, const volatile double* key, u16 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddDoublePU16P(RedBlackTree *dataStructure, const volatile double* key, const volatile u16* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoubleI32(RedBlackTree *dataStructure, double key, i32 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddDoubleI32P(RedBlackTree *dataStructure, double key, const volatile i32* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePI32(RedBlackTree *dataStructure, const volatile double* key, i32 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddDoublePI32P(RedBlackTree *dataStructure, const volatile double* key, const volatile i32* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoubleU32(RedBlackTree *dataStructure, double key, u32 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddDoubleU32P(RedBlackTree *dataStructure, double key, const volatile u32* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePU32(RedBlackTree *dataStructure, const volatile double* key, u32 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddDoublePU32P(RedBlackTree *dataStructure, const volatile double* key, const volatile u32* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoubleI64(RedBlackTree *dataStructure, double key, i64 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddDoubleI64P(RedBlackTree *dataStructure, double key, const volatile i64* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePI64(RedBlackTree *dataStructure, const volatile double* key, i64 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddDoublePI64P(RedBlackTree *dataStructure, const volatile double* key, const volatile i64* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoubleU64(RedBlackTree *dataStructure, double key, u64 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddDoubleU64P(RedBlackTree *dataStructure, double key, const volatile u64* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePU64(RedBlackTree *dataStructure, const volatile double* key, u64 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddDoublePU64P(RedBlackTree *dataStructure, const volatile double* key, const volatile u64* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoubleFloat(RedBlackTree *dataStructure, double key, float value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddDoubleFloatP(RedBlackTree *dataStructure, double key, const volatile float* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePFloat(RedBlackTree *dataStructure, const volatile double* key, float value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddDoublePFloatP(RedBlackTree *dataStructure, const volatile double* key, const volatile float* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoubleDouble(RedBlackTree *dataStructure, double key, double value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddDoubleDoubleP(RedBlackTree *dataStructure, double key, const volatile double* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePDouble(RedBlackTree *dataStructure, const volatile double* key, double value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddDoublePDoubleP(RedBlackTree *dataStructure, const volatile double* key, const volatile double* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoubleLongDouble(RedBlackTree *dataStructure, double key, long double value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddDoubleLongDoubleP(RedBlackTree *dataStructure, double key, const volatile long double* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePLongDouble(RedBlackTree *dataStructure, const volatile double* key, long double value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddDoublePLongDoubleP(RedBlackTree *dataStructure, const volatile double* key, const volatile long double* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoubleList(RedBlackTree *dataStructure, double key, List value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddDoubleListP(RedBlackTree *dataStructure, double key, const volatile List* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePList(RedBlackTree *dataStructure, const volatile double* key, List value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddDoublePListP(RedBlackTree *dataStructure, const volatile double* key, const volatile List* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoubleQueue(RedBlackTree *dataStructure, double key, Queue value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddDoubleQueueP(RedBlackTree *dataStructure, double key, const volatile Queue* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePQueue(RedBlackTree *dataStructure, const volatile double* key, Queue value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddDoublePQueueP(RedBlackTree *dataStructure, const volatile double* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoubleStack(RedBlackTree *dataStructure, double key, Stack value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddDoubleStackP(RedBlackTree *dataStructure, double key, const volatile Stack* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePStack(RedBlackTree *dataStructure, const volatile double* key, Stack value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddDoublePStackP(RedBlackTree *dataStructure, const volatile double* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoubleRedBlackTree(RedBlackTree *dataStructure, double key, RedBlackTree value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddDoubleRedBlackTreeP(RedBlackTree *dataStructure, double key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePRedBlackTree(RedBlackTree *dataStructure, const volatile double* key, RedBlackTree value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddDoublePRedBlackTreeP(RedBlackTree *dataStructure, const volatile double* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoubleHashTable(RedBlackTree *dataStructure, double key, HashTable value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddDoubleHashTableP(RedBlackTree *dataStructure, double key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePHashTable(RedBlackTree *dataStructure, const volatile double* key, HashTable value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddDoublePHashTableP(RedBlackTree *dataStructure, const volatile double* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoubleVector(RedBlackTree *dataStructure, double key, Vector value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddDoubleVectorP(RedBlackTree *dataStructure, double key, const volatile Vector* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePVector(RedBlackTree *dataStructure, const volatile double* key, Vector value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddDoublePVectorP(RedBlackTree *dataStructure, const volatile double* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoubleString(RedBlackTree *dataStructure, double key, const volatile char* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddDoubleStringP(RedBlackTree *dataStructure, double key, const volatile char** value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePString(RedBlackTree *dataStructure, const volatile double* key, const volatile char* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddDoublePStringP(RedBlackTree *dataStructure, const volatile double* key, const volatile char** value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoubleBytes(RedBlackTree *dataStructure, double key, Bytes value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddDoubleBytesP(RedBlackTree *dataStructure, double key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePBytes(RedBlackTree *dataStructure, const volatile double* key, Bytes value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddDoublePBytesP(RedBlackTree *dataStructure, const volatile double* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePointer(RedBlackTree *dataStructure, double key, void* value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddDoublePointerP(RedBlackTree *dataStructure, double key, const volatile void** value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoublePPointer(RedBlackTree *dataStructure, const volatile double* key, void* value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddDoublePPointerP(RedBlackTree *dataStructure, const volatile double* key, const volatile void** value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddDoubleI8(RedBlackTree *dataStructure, double key, i8 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddDoublePI8(RedBlackTree *dataStructure, const volatile double* key, i8 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddDoubleU8(RedBlackTree *dataStructure, double key, u8 value) {
  if (dataStructure->keyType != typeDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddDoublePU8(RedBlackTree *dataStructure, const volatile double* key, u8 value) {
  if (dataStructure->keyType != typeDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleBool(RedBlackTree *dataStructure, long double key, bool value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleBoolP(RedBlackTree *dataStructure, long double key, const volatile bool* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePBool(RedBlackTree *dataStructure, const volatile long double* key, bool value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePBoolP(RedBlackTree *dataStructure, const volatile long double* key, const volatile bool* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleI16(RedBlackTree *dataStructure, long double key, i16 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleI16P(RedBlackTree *dataStructure, long double key, const volatile i16* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePI16(RedBlackTree *dataStructure, const volatile long double* key, i16 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePI16P(RedBlackTree *dataStructure, const volatile long double* key, const volatile i16* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleU16(RedBlackTree *dataStructure, long double key, u16 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleU16P(RedBlackTree *dataStructure, long double key, const volatile u16* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePU16(RedBlackTree *dataStructure, const volatile long double* key, u16 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePU16P(RedBlackTree *dataStructure, const volatile long double* key, const volatile u16* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleI32(RedBlackTree *dataStructure, long double key, i32 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleI32P(RedBlackTree *dataStructure, long double key, const volatile i32* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePI32(RedBlackTree *dataStructure, const volatile long double* key, i32 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePI32P(RedBlackTree *dataStructure, const volatile long double* key, const volatile i32* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleU32(RedBlackTree *dataStructure, long double key, u32 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleU32P(RedBlackTree *dataStructure, long double key, const volatile u32* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePU32(RedBlackTree *dataStructure, const volatile long double* key, u32 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePU32P(RedBlackTree *dataStructure, const volatile long double* key, const volatile u32* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleI64(RedBlackTree *dataStructure, long double key, i64 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleI64P(RedBlackTree *dataStructure, long double key, const volatile i64* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePI64(RedBlackTree *dataStructure, const volatile long double* key, i64 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePI64P(RedBlackTree *dataStructure, const volatile long double* key, const volatile i64* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleU64(RedBlackTree *dataStructure, long double key, u64 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleU64P(RedBlackTree *dataStructure, long double key, const volatile u64* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePU64(RedBlackTree *dataStructure, const volatile long double* key, u64 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePU64P(RedBlackTree *dataStructure, const volatile long double* key, const volatile u64* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleFloat(RedBlackTree *dataStructure, long double key, float value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleFloatP(RedBlackTree *dataStructure, long double key, const volatile float* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePFloat(RedBlackTree *dataStructure, const volatile long double* key, float value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePFloatP(RedBlackTree *dataStructure, const volatile long double* key, const volatile float* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleDouble(RedBlackTree *dataStructure, long double key, double value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleDoubleP(RedBlackTree *dataStructure, long double key, const volatile double* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePDouble(RedBlackTree *dataStructure, const volatile long double* key, double value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePDoubleP(RedBlackTree *dataStructure, const volatile long double* key, const volatile double* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleLongDouble(RedBlackTree *dataStructure, long double key, long double value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleLongDoubleP(RedBlackTree *dataStructure, long double key, const volatile long double* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePLongDouble(RedBlackTree *dataStructure, const volatile long double* key, long double value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePLongDoubleP(RedBlackTree *dataStructure, const volatile long double* key, const volatile long double* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleList(RedBlackTree *dataStructure, long double key, List value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleListP(RedBlackTree *dataStructure, long double key, const volatile List* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePList(RedBlackTree *dataStructure, const volatile long double* key, List value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePListP(RedBlackTree *dataStructure, const volatile long double* key, const volatile List* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleQueue(RedBlackTree *dataStructure, long double key, Queue value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleQueueP(RedBlackTree *dataStructure, long double key, const volatile Queue* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePQueue(RedBlackTree *dataStructure, const volatile long double* key, Queue value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePQueueP(RedBlackTree *dataStructure, const volatile long double* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleStack(RedBlackTree *dataStructure, long double key, Stack value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleStackP(RedBlackTree *dataStructure, long double key, const volatile Stack* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePStack(RedBlackTree *dataStructure, const volatile long double* key, Stack value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePStackP(RedBlackTree *dataStructure, const volatile long double* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleRedBlackTree(RedBlackTree *dataStructure, long double key, RedBlackTree value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleRedBlackTreeP(RedBlackTree *dataStructure, long double key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePRedBlackTree(RedBlackTree *dataStructure, const volatile long double* key, RedBlackTree value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePRedBlackTreeP(RedBlackTree *dataStructure, const volatile long double* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleHashTable(RedBlackTree *dataStructure, long double key, HashTable value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleHashTableP(RedBlackTree *dataStructure, long double key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePHashTable(RedBlackTree *dataStructure, const volatile long double* key, HashTable value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePHashTableP(RedBlackTree *dataStructure, const volatile long double* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleVector(RedBlackTree *dataStructure, long double key, Vector value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleVectorP(RedBlackTree *dataStructure, long double key, const volatile Vector* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePVector(RedBlackTree *dataStructure, const volatile long double* key, Vector value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePVectorP(RedBlackTree *dataStructure, const volatile long double* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleString(RedBlackTree *dataStructure, long double key, const volatile char* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleStringP(RedBlackTree *dataStructure, long double key, const volatile char** value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePString(RedBlackTree *dataStructure, const volatile long double* key, const volatile char* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePStringP(RedBlackTree *dataStructure, const volatile long double* key, const volatile char** value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleBytes(RedBlackTree *dataStructure, long double key, Bytes value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleBytesP(RedBlackTree *dataStructure, long double key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePBytes(RedBlackTree *dataStructure, const volatile long double* key, Bytes value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePBytesP(RedBlackTree *dataStructure, const volatile long double* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePointer(RedBlackTree *dataStructure, long double key, void* value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePointerP(RedBlackTree *dataStructure, long double key, const volatile void** value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePPointer(RedBlackTree *dataStructure, const volatile long double* key, void* value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePPointerP(RedBlackTree *dataStructure, const volatile long double* key, const volatile void** value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleI8(RedBlackTree *dataStructure, long double key, i8 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePI8(RedBlackTree *dataStructure, const volatile long double* key, i8 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddLongDoubleU8(RedBlackTree *dataStructure, long double key, u8 value) {
  if (dataStructure->keyType != typeLongDouble) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddLongDoublePU8(RedBlackTree *dataStructure, const volatile long double* key, u8 value) {
  if (dataStructure->keyType != typeLongDoubleNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddListBool(RedBlackTree *dataStructure, List key, bool value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddListBoolP(RedBlackTree *dataStructure, List key, const volatile bool* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPBool(RedBlackTree *dataStructure, const volatile List* key, bool value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddListPBoolP(RedBlackTree *dataStructure, const volatile List* key, const volatile bool* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListI16(RedBlackTree *dataStructure, List key, i16 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddListI16P(RedBlackTree *dataStructure, List key, const volatile i16* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPI16(RedBlackTree *dataStructure, const volatile List* key, i16 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddListPI16P(RedBlackTree *dataStructure, const volatile List* key, const volatile i16* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListU16(RedBlackTree *dataStructure, List key, u16 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddListU16P(RedBlackTree *dataStructure, List key, const volatile u16* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPU16(RedBlackTree *dataStructure, const volatile List* key, u16 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddListPU16P(RedBlackTree *dataStructure, const volatile List* key, const volatile u16* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListI32(RedBlackTree *dataStructure, List key, i32 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddListI32P(RedBlackTree *dataStructure, List key, const volatile i32* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPI32(RedBlackTree *dataStructure, const volatile List* key, i32 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddListPI32P(RedBlackTree *dataStructure, const volatile List* key, const volatile i32* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListU32(RedBlackTree *dataStructure, List key, u32 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddListU32P(RedBlackTree *dataStructure, List key, const volatile u32* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPU32(RedBlackTree *dataStructure, const volatile List* key, u32 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddListPU32P(RedBlackTree *dataStructure, const volatile List* key, const volatile u32* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListI64(RedBlackTree *dataStructure, List key, i64 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddListI64P(RedBlackTree *dataStructure, List key, const volatile i64* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPI64(RedBlackTree *dataStructure, const volatile List* key, i64 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddListPI64P(RedBlackTree *dataStructure, const volatile List* key, const volatile i64* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListU64(RedBlackTree *dataStructure, List key, u64 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddListU64P(RedBlackTree *dataStructure, List key, const volatile u64* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPU64(RedBlackTree *dataStructure, const volatile List* key, u64 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddListPU64P(RedBlackTree *dataStructure, const volatile List* key, const volatile u64* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListFloat(RedBlackTree *dataStructure, List key, float value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddListFloatP(RedBlackTree *dataStructure, List key, const volatile float* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPFloat(RedBlackTree *dataStructure, const volatile List* key, float value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddListPFloatP(RedBlackTree *dataStructure, const volatile List* key, const volatile float* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListDouble(RedBlackTree *dataStructure, List key, double value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddListDoubleP(RedBlackTree *dataStructure, List key, const volatile double* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPDouble(RedBlackTree *dataStructure, const volatile List* key, double value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddListPDoubleP(RedBlackTree *dataStructure, const volatile List* key, const volatile double* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListLongDouble(RedBlackTree *dataStructure, List key, long double value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddListLongDoubleP(RedBlackTree *dataStructure, List key, const volatile long double* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPLongDouble(RedBlackTree *dataStructure, const volatile List* key, long double value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddListPLongDoubleP(RedBlackTree *dataStructure, const volatile List* key, const volatile long double* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListList(RedBlackTree *dataStructure, List key, List value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddListListP(RedBlackTree *dataStructure, List key, const volatile List* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPList(RedBlackTree *dataStructure, const volatile List* key, List value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddListPListP(RedBlackTree *dataStructure, const volatile List* key, const volatile List* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListQueue(RedBlackTree *dataStructure, List key, Queue value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddListQueueP(RedBlackTree *dataStructure, List key, const volatile Queue* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPQueue(RedBlackTree *dataStructure, const volatile List* key, Queue value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddListPQueueP(RedBlackTree *dataStructure, const volatile List* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListStack(RedBlackTree *dataStructure, List key, Stack value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddListStackP(RedBlackTree *dataStructure, List key, const volatile Stack* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPStack(RedBlackTree *dataStructure, const volatile List* key, Stack value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddListPStackP(RedBlackTree *dataStructure, const volatile List* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListRedBlackTree(RedBlackTree *dataStructure, List key, RedBlackTree value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddListRedBlackTreeP(RedBlackTree *dataStructure, List key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPRedBlackTree(RedBlackTree *dataStructure, const volatile List* key, RedBlackTree value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddListPRedBlackTreeP(RedBlackTree *dataStructure, const volatile List* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListHashTable(RedBlackTree *dataStructure, List key, HashTable value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddListHashTableP(RedBlackTree *dataStructure, List key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPHashTable(RedBlackTree *dataStructure, const volatile List* key, HashTable value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddListPHashTableP(RedBlackTree *dataStructure, const volatile List* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListVector(RedBlackTree *dataStructure, List key, Vector value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddListVectorP(RedBlackTree *dataStructure, List key, const volatile Vector* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPVector(RedBlackTree *dataStructure, const volatile List* key, Vector value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddListPVectorP(RedBlackTree *dataStructure, const volatile List* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListString(RedBlackTree *dataStructure, List key, const volatile char* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddListStringP(RedBlackTree *dataStructure, List key, const volatile char** value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPString(RedBlackTree *dataStructure, const volatile List* key, const volatile char* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddListPStringP(RedBlackTree *dataStructure, const volatile List* key, const volatile char** value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListBytes(RedBlackTree *dataStructure, List key, Bytes value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddListBytesP(RedBlackTree *dataStructure, List key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPBytes(RedBlackTree *dataStructure, const volatile List* key, Bytes value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddListPBytesP(RedBlackTree *dataStructure, const volatile List* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPointer(RedBlackTree *dataStructure, List key, void* value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddListPointerP(RedBlackTree *dataStructure, List key, const volatile void** value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListPPointer(RedBlackTree *dataStructure, const volatile List* key, void* value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddListPPointerP(RedBlackTree *dataStructure, const volatile List* key, const volatile void** value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddListI8(RedBlackTree *dataStructure, List key, i8 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddListPI8(RedBlackTree *dataStructure, const volatile List* key, i8 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddListU8(RedBlackTree *dataStructure, List key, u8 value) {
  if (dataStructure->keyType != typeList) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddListPU8(RedBlackTree *dataStructure, const volatile List* key, u8 value) {
  if (dataStructure->keyType != typeListNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddQueueBool(RedBlackTree *dataStructure, Queue key, bool value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddQueueBoolP(RedBlackTree *dataStructure, Queue key, const volatile bool* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePBool(RedBlackTree *dataStructure, const volatile Queue* key, bool value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddQueuePBoolP(RedBlackTree *dataStructure, const volatile Queue* key, const volatile bool* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueueI16(RedBlackTree *dataStructure, Queue key, i16 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddQueueI16P(RedBlackTree *dataStructure, Queue key, const volatile i16* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePI16(RedBlackTree *dataStructure, const volatile Queue* key, i16 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddQueuePI16P(RedBlackTree *dataStructure, const volatile Queue* key, const volatile i16* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueueU16(RedBlackTree *dataStructure, Queue key, u16 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddQueueU16P(RedBlackTree *dataStructure, Queue key, const volatile u16* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePU16(RedBlackTree *dataStructure, const volatile Queue* key, u16 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddQueuePU16P(RedBlackTree *dataStructure, const volatile Queue* key, const volatile u16* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueueI32(RedBlackTree *dataStructure, Queue key, i32 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddQueueI32P(RedBlackTree *dataStructure, Queue key, const volatile i32* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePI32(RedBlackTree *dataStructure, const volatile Queue* key, i32 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddQueuePI32P(RedBlackTree *dataStructure, const volatile Queue* key, const volatile i32* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueueU32(RedBlackTree *dataStructure, Queue key, u32 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddQueueU32P(RedBlackTree *dataStructure, Queue key, const volatile u32* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePU32(RedBlackTree *dataStructure, const volatile Queue* key, u32 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddQueuePU32P(RedBlackTree *dataStructure, const volatile Queue* key, const volatile u32* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueueI64(RedBlackTree *dataStructure, Queue key, i64 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddQueueI64P(RedBlackTree *dataStructure, Queue key, const volatile i64* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePI64(RedBlackTree *dataStructure, const volatile Queue* key, i64 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddQueuePI64P(RedBlackTree *dataStructure, const volatile Queue* key, const volatile i64* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueueU64(RedBlackTree *dataStructure, Queue key, u64 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddQueueU64P(RedBlackTree *dataStructure, Queue key, const volatile u64* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePU64(RedBlackTree *dataStructure, const volatile Queue* key, u64 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddQueuePU64P(RedBlackTree *dataStructure, const volatile Queue* key, const volatile u64* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueueFloat(RedBlackTree *dataStructure, Queue key, float value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddQueueFloatP(RedBlackTree *dataStructure, Queue key, const volatile float* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePFloat(RedBlackTree *dataStructure, const volatile Queue* key, float value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddQueuePFloatP(RedBlackTree *dataStructure, const volatile Queue* key, const volatile float* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueueDouble(RedBlackTree *dataStructure, Queue key, double value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddQueueDoubleP(RedBlackTree *dataStructure, Queue key, const volatile double* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePDouble(RedBlackTree *dataStructure, const volatile Queue* key, double value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddQueuePDoubleP(RedBlackTree *dataStructure, const volatile Queue* key, const volatile double* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueueLongDouble(RedBlackTree *dataStructure, Queue key, long double value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddQueueLongDoubleP(RedBlackTree *dataStructure, Queue key, const volatile long double* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePLongDouble(RedBlackTree *dataStructure, const volatile Queue* key, long double value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddQueuePLongDoubleP(RedBlackTree *dataStructure, const volatile Queue* key, const volatile long double* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueueList(RedBlackTree *dataStructure, Queue key, List value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddQueueListP(RedBlackTree *dataStructure, Queue key, const volatile List* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePList(RedBlackTree *dataStructure, const volatile Queue* key, List value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddQueuePListP(RedBlackTree *dataStructure, const volatile Queue* key, const volatile List* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueueQueue(RedBlackTree *dataStructure, Queue key, Queue value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddQueueQueueP(RedBlackTree *dataStructure, Queue key, const volatile Queue* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePQueue(RedBlackTree *dataStructure, const volatile Queue* key, Queue value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddQueuePQueueP(RedBlackTree *dataStructure, const volatile Queue* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueueStack(RedBlackTree *dataStructure, Queue key, Stack value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddQueueStackP(RedBlackTree *dataStructure, Queue key, const volatile Stack* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePStack(RedBlackTree *dataStructure, const volatile Queue* key, Stack value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddQueuePStackP(RedBlackTree *dataStructure, const volatile Queue* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueueRedBlackTree(RedBlackTree *dataStructure, Queue key, RedBlackTree value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddQueueRedBlackTreeP(RedBlackTree *dataStructure, Queue key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePRedBlackTree(RedBlackTree *dataStructure, const volatile Queue* key, RedBlackTree value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddQueuePRedBlackTreeP(RedBlackTree *dataStructure, const volatile Queue* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueueHashTable(RedBlackTree *dataStructure, Queue key, HashTable value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddQueueHashTableP(RedBlackTree *dataStructure, Queue key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePHashTable(RedBlackTree *dataStructure, const volatile Queue* key, HashTable value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddQueuePHashTableP(RedBlackTree *dataStructure, const volatile Queue* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueueVector(RedBlackTree *dataStructure, Queue key, Vector value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddQueueVectorP(RedBlackTree *dataStructure, Queue key, const volatile Vector* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePVector(RedBlackTree *dataStructure, const volatile Queue* key, Vector value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddQueuePVectorP(RedBlackTree *dataStructure, const volatile Queue* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueueString(RedBlackTree *dataStructure, Queue key, const volatile char* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddQueueStringP(RedBlackTree *dataStructure, Queue key, const volatile char** value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePString(RedBlackTree *dataStructure, const volatile Queue* key, const volatile char* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddQueuePStringP(RedBlackTree *dataStructure, const volatile Queue* key, const volatile char** value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueueBytes(RedBlackTree *dataStructure, Queue key, Bytes value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddQueueBytesP(RedBlackTree *dataStructure, Queue key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePBytes(RedBlackTree *dataStructure, const volatile Queue* key, Bytes value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddQueuePBytesP(RedBlackTree *dataStructure, const volatile Queue* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePointer(RedBlackTree *dataStructure, Queue key, void* value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddQueuePointerP(RedBlackTree *dataStructure, Queue key, const volatile void** value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueuePPointer(RedBlackTree *dataStructure, const volatile Queue* key, void* value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddQueuePPointerP(RedBlackTree *dataStructure, const volatile Queue* key, const volatile void** value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddQueueI8(RedBlackTree *dataStructure, Queue key, i8 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddQueuePI8(RedBlackTree *dataStructure, const volatile Queue* key, i8 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddQueueU8(RedBlackTree *dataStructure, Queue key, u8 value) {
  if (dataStructure->keyType != typeQueue) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddQueuePU8(RedBlackTree *dataStructure, const volatile Queue* key, u8 value) {
  if (dataStructure->keyType != typeQueueNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddStackBool(RedBlackTree *dataStructure, Stack key, bool value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddStackBoolP(RedBlackTree *dataStructure, Stack key, const volatile bool* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPBool(RedBlackTree *dataStructure, const volatile Stack* key, bool value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddStackPBoolP(RedBlackTree *dataStructure, const volatile Stack* key, const volatile bool* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackI16(RedBlackTree *dataStructure, Stack key, i16 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddStackI16P(RedBlackTree *dataStructure, Stack key, const volatile i16* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPI16(RedBlackTree *dataStructure, const volatile Stack* key, i16 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddStackPI16P(RedBlackTree *dataStructure, const volatile Stack* key, const volatile i16* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackU16(RedBlackTree *dataStructure, Stack key, u16 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddStackU16P(RedBlackTree *dataStructure, Stack key, const volatile u16* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPU16(RedBlackTree *dataStructure, const volatile Stack* key, u16 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddStackPU16P(RedBlackTree *dataStructure, const volatile Stack* key, const volatile u16* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackI32(RedBlackTree *dataStructure, Stack key, i32 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddStackI32P(RedBlackTree *dataStructure, Stack key, const volatile i32* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPI32(RedBlackTree *dataStructure, const volatile Stack* key, i32 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddStackPI32P(RedBlackTree *dataStructure, const volatile Stack* key, const volatile i32* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackU32(RedBlackTree *dataStructure, Stack key, u32 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddStackU32P(RedBlackTree *dataStructure, Stack key, const volatile u32* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPU32(RedBlackTree *dataStructure, const volatile Stack* key, u32 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddStackPU32P(RedBlackTree *dataStructure, const volatile Stack* key, const volatile u32* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackI64(RedBlackTree *dataStructure, Stack key, i64 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddStackI64P(RedBlackTree *dataStructure, Stack key, const volatile i64* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPI64(RedBlackTree *dataStructure, const volatile Stack* key, i64 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddStackPI64P(RedBlackTree *dataStructure, const volatile Stack* key, const volatile i64* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackU64(RedBlackTree *dataStructure, Stack key, u64 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddStackU64P(RedBlackTree *dataStructure, Stack key, const volatile u64* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPU64(RedBlackTree *dataStructure, const volatile Stack* key, u64 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddStackPU64P(RedBlackTree *dataStructure, const volatile Stack* key, const volatile u64* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackFloat(RedBlackTree *dataStructure, Stack key, float value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddStackFloatP(RedBlackTree *dataStructure, Stack key, const volatile float* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPFloat(RedBlackTree *dataStructure, const volatile Stack* key, float value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddStackPFloatP(RedBlackTree *dataStructure, const volatile Stack* key, const volatile float* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackDouble(RedBlackTree *dataStructure, Stack key, double value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddStackDoubleP(RedBlackTree *dataStructure, Stack key, const volatile double* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPDouble(RedBlackTree *dataStructure, const volatile Stack* key, double value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddStackPDoubleP(RedBlackTree *dataStructure, const volatile Stack* key, const volatile double* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackLongDouble(RedBlackTree *dataStructure, Stack key, long double value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddStackLongDoubleP(RedBlackTree *dataStructure, Stack key, const volatile long double* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPLongDouble(RedBlackTree *dataStructure, const volatile Stack* key, long double value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddStackPLongDoubleP(RedBlackTree *dataStructure, const volatile Stack* key, const volatile long double* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackList(RedBlackTree *dataStructure, Stack key, List value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddStackListP(RedBlackTree *dataStructure, Stack key, const volatile List* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPList(RedBlackTree *dataStructure, const volatile Stack* key, List value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddStackPListP(RedBlackTree *dataStructure, const volatile Stack* key, const volatile List* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackQueue(RedBlackTree *dataStructure, Stack key, Queue value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddStackQueueP(RedBlackTree *dataStructure, Stack key, const volatile Queue* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPQueue(RedBlackTree *dataStructure, const volatile Stack* key, Queue value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddStackPQueueP(RedBlackTree *dataStructure, const volatile Stack* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackStack(RedBlackTree *dataStructure, Stack key, Stack value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddStackStackP(RedBlackTree *dataStructure, Stack key, const volatile Stack* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPStack(RedBlackTree *dataStructure, const volatile Stack* key, Stack value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddStackPStackP(RedBlackTree *dataStructure, const volatile Stack* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackRedBlackTree(RedBlackTree *dataStructure, Stack key, RedBlackTree value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddStackRedBlackTreeP(RedBlackTree *dataStructure, Stack key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPRedBlackTree(RedBlackTree *dataStructure, const volatile Stack* key, RedBlackTree value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddStackPRedBlackTreeP(RedBlackTree *dataStructure, const volatile Stack* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackHashTable(RedBlackTree *dataStructure, Stack key, HashTable value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddStackHashTableP(RedBlackTree *dataStructure, Stack key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPHashTable(RedBlackTree *dataStructure, const volatile Stack* key, HashTable value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddStackPHashTableP(RedBlackTree *dataStructure, const volatile Stack* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackVector(RedBlackTree *dataStructure, Stack key, Vector value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddStackVectorP(RedBlackTree *dataStructure, Stack key, const volatile Vector* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPVector(RedBlackTree *dataStructure, const volatile Stack* key, Vector value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddStackPVectorP(RedBlackTree *dataStructure, const volatile Stack* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackString(RedBlackTree *dataStructure, Stack key, const volatile char* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddStackStringP(RedBlackTree *dataStructure, Stack key, const volatile char** value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPString(RedBlackTree *dataStructure, const volatile Stack* key, const volatile char* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddStackPStringP(RedBlackTree *dataStructure, const volatile Stack* key, const volatile char** value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackBytes(RedBlackTree *dataStructure, Stack key, Bytes value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddStackBytesP(RedBlackTree *dataStructure, Stack key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPBytes(RedBlackTree *dataStructure, const volatile Stack* key, Bytes value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddStackPBytesP(RedBlackTree *dataStructure, const volatile Stack* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPointer(RedBlackTree *dataStructure, Stack key, void* value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddStackPointerP(RedBlackTree *dataStructure, Stack key, const volatile void** value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackPPointer(RedBlackTree *dataStructure, const volatile Stack* key, void* value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddStackPPointerP(RedBlackTree *dataStructure, const volatile Stack* key, const volatile void** value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStackI8(RedBlackTree *dataStructure, Stack key, i8 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddStackPI8(RedBlackTree *dataStructure, const volatile Stack* key, i8 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddStackU8(RedBlackTree *dataStructure, Stack key, u8 value) {
  if (dataStructure->keyType != typeStack) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddStackPU8(RedBlackTree *dataStructure, const volatile Stack* key, u8 value) {
  if (dataStructure->keyType != typeStackNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeBool(RedBlackTree *dataStructure, RedBlackTree key, bool value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeBoolP(RedBlackTree *dataStructure, RedBlackTree key, const volatile bool* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePBool(RedBlackTree *dataStructure, const volatile RedBlackTree* key, bool value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePBoolP(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile bool* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeI16(RedBlackTree *dataStructure, RedBlackTree key, i16 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeI16P(RedBlackTree *dataStructure, RedBlackTree key, const volatile i16* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePI16(RedBlackTree *dataStructure, const volatile RedBlackTree* key, i16 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePI16P(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile i16* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeU16(RedBlackTree *dataStructure, RedBlackTree key, u16 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeU16P(RedBlackTree *dataStructure, RedBlackTree key, const volatile u16* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePU16(RedBlackTree *dataStructure, const volatile RedBlackTree* key, u16 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePU16P(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile u16* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeI32(RedBlackTree *dataStructure, RedBlackTree key, i32 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeI32P(RedBlackTree *dataStructure, RedBlackTree key, const volatile i32* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePI32(RedBlackTree *dataStructure, const volatile RedBlackTree* key, i32 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePI32P(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile i32* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeU32(RedBlackTree *dataStructure, RedBlackTree key, u32 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeU32P(RedBlackTree *dataStructure, RedBlackTree key, const volatile u32* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePU32(RedBlackTree *dataStructure, const volatile RedBlackTree* key, u32 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePU32P(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile u32* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeI64(RedBlackTree *dataStructure, RedBlackTree key, i64 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeI64P(RedBlackTree *dataStructure, RedBlackTree key, const volatile i64* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePI64(RedBlackTree *dataStructure, const volatile RedBlackTree* key, i64 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePI64P(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile i64* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeU64(RedBlackTree *dataStructure, RedBlackTree key, u64 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeU64P(RedBlackTree *dataStructure, RedBlackTree key, const volatile u64* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePU64(RedBlackTree *dataStructure, const volatile RedBlackTree* key, u64 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePU64P(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile u64* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeFloat(RedBlackTree *dataStructure, RedBlackTree key, float value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeFloatP(RedBlackTree *dataStructure, RedBlackTree key, const volatile float* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePFloat(RedBlackTree *dataStructure, const volatile RedBlackTree* key, float value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePFloatP(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile float* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeDouble(RedBlackTree *dataStructure, RedBlackTree key, double value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeDoubleP(RedBlackTree *dataStructure, RedBlackTree key, const volatile double* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePDouble(RedBlackTree *dataStructure, const volatile RedBlackTree* key, double value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePDoubleP(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile double* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeLongDouble(RedBlackTree *dataStructure, RedBlackTree key, long double value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeLongDoubleP(RedBlackTree *dataStructure, RedBlackTree key, const volatile long double* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePLongDouble(RedBlackTree *dataStructure, const volatile RedBlackTree* key, long double value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePLongDoubleP(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile long double* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeList(RedBlackTree *dataStructure, RedBlackTree key, List value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeListP(RedBlackTree *dataStructure, RedBlackTree key, const volatile List* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePList(RedBlackTree *dataStructure, const volatile RedBlackTree* key, List value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePListP(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile List* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeQueue(RedBlackTree *dataStructure, RedBlackTree key, Queue value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeQueueP(RedBlackTree *dataStructure, RedBlackTree key, const volatile Queue* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePQueue(RedBlackTree *dataStructure, const volatile RedBlackTree* key, Queue value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePQueueP(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeStack(RedBlackTree *dataStructure, RedBlackTree key, Stack value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeStackP(RedBlackTree *dataStructure, RedBlackTree key, const volatile Stack* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePStack(RedBlackTree *dataStructure, const volatile RedBlackTree* key, Stack value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePStackP(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeRedBlackTree(RedBlackTree *dataStructure, RedBlackTree key, RedBlackTree value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeRedBlackTreeP(RedBlackTree *dataStructure, RedBlackTree key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePRedBlackTree(RedBlackTree *dataStructure, const volatile RedBlackTree* key, RedBlackTree value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePRedBlackTreeP(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeHashTable(RedBlackTree *dataStructure, RedBlackTree key, HashTable value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeHashTableP(RedBlackTree *dataStructure, RedBlackTree key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePHashTable(RedBlackTree *dataStructure, const volatile RedBlackTree* key, HashTable value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePHashTableP(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeVector(RedBlackTree *dataStructure, RedBlackTree key, Vector value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeVectorP(RedBlackTree *dataStructure, RedBlackTree key, const volatile Vector* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePVector(RedBlackTree *dataStructure, const volatile RedBlackTree* key, Vector value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePVectorP(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeString(RedBlackTree *dataStructure, RedBlackTree key, const volatile char* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeStringP(RedBlackTree *dataStructure, RedBlackTree key, const volatile char** value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePString(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile char* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePStringP(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile char** value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeBytes(RedBlackTree *dataStructure, RedBlackTree key, Bytes value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeBytesP(RedBlackTree *dataStructure, RedBlackTree key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePBytes(RedBlackTree *dataStructure, const volatile RedBlackTree* key, Bytes value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePBytesP(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePointer(RedBlackTree *dataStructure, RedBlackTree key, void* value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePointerP(RedBlackTree *dataStructure, RedBlackTree key, const volatile void** value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePPointer(RedBlackTree *dataStructure, const volatile RedBlackTree* key, void* value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePPointerP(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile void** value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeI8(RedBlackTree *dataStructure, RedBlackTree key, i8 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePI8(RedBlackTree *dataStructure, const volatile RedBlackTree* key, i8 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreeU8(RedBlackTree *dataStructure, RedBlackTree key, u8 value) {
  if (dataStructure->keyType != typeRedBlackTree) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddRedBlackTreePU8(RedBlackTree *dataStructure, const volatile RedBlackTree* key, u8 value) {
  if (dataStructure->keyType != typeRedBlackTreeNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddHashTableBool(RedBlackTree *dataStructure, HashTable key, bool value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddHashTableBoolP(RedBlackTree *dataStructure, HashTable key, const volatile bool* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePBool(RedBlackTree *dataStructure, const volatile HashTable* key, bool value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePBoolP(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile bool* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTableI16(RedBlackTree *dataStructure, HashTable key, i16 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddHashTableI16P(RedBlackTree *dataStructure, HashTable key, const volatile i16* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePI16(RedBlackTree *dataStructure, const volatile HashTable* key, i16 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePI16P(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile i16* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTableU16(RedBlackTree *dataStructure, HashTable key, u16 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddHashTableU16P(RedBlackTree *dataStructure, HashTable key, const volatile u16* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePU16(RedBlackTree *dataStructure, const volatile HashTable* key, u16 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePU16P(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile u16* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTableI32(RedBlackTree *dataStructure, HashTable key, i32 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddHashTableI32P(RedBlackTree *dataStructure, HashTable key, const volatile i32* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePI32(RedBlackTree *dataStructure, const volatile HashTable* key, i32 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePI32P(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile i32* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTableU32(RedBlackTree *dataStructure, HashTable key, u32 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddHashTableU32P(RedBlackTree *dataStructure, HashTable key, const volatile u32* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePU32(RedBlackTree *dataStructure, const volatile HashTable* key, u32 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePU32P(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile u32* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTableI64(RedBlackTree *dataStructure, HashTable key, i64 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddHashTableI64P(RedBlackTree *dataStructure, HashTable key, const volatile i64* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePI64(RedBlackTree *dataStructure, const volatile HashTable* key, i64 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePI64P(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile i64* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTableU64(RedBlackTree *dataStructure, HashTable key, u64 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddHashTableU64P(RedBlackTree *dataStructure, HashTable key, const volatile u64* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePU64(RedBlackTree *dataStructure, const volatile HashTable* key, u64 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePU64P(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile u64* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTableFloat(RedBlackTree *dataStructure, HashTable key, float value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddHashTableFloatP(RedBlackTree *dataStructure, HashTable key, const volatile float* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePFloat(RedBlackTree *dataStructure, const volatile HashTable* key, float value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePFloatP(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile float* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTableDouble(RedBlackTree *dataStructure, HashTable key, double value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddHashTableDoubleP(RedBlackTree *dataStructure, HashTable key, const volatile double* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePDouble(RedBlackTree *dataStructure, const volatile HashTable* key, double value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePDoubleP(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile double* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTableLongDouble(RedBlackTree *dataStructure, HashTable key, long double value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddHashTableLongDoubleP(RedBlackTree *dataStructure, HashTable key, const volatile long double* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePLongDouble(RedBlackTree *dataStructure, const volatile HashTable* key, long double value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePLongDoubleP(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile long double* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTableList(RedBlackTree *dataStructure, HashTable key, List value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddHashTableListP(RedBlackTree *dataStructure, HashTable key, const volatile List* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePList(RedBlackTree *dataStructure, const volatile HashTable* key, List value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePListP(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile List* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTableQueue(RedBlackTree *dataStructure, HashTable key, Queue value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddHashTableQueueP(RedBlackTree *dataStructure, HashTable key, const volatile Queue* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePQueue(RedBlackTree *dataStructure, const volatile HashTable* key, Queue value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePQueueP(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTableStack(RedBlackTree *dataStructure, HashTable key, Stack value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddHashTableStackP(RedBlackTree *dataStructure, HashTable key, const volatile Stack* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePStack(RedBlackTree *dataStructure, const volatile HashTable* key, Stack value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePStackP(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTableRedBlackTree(RedBlackTree *dataStructure, HashTable key, RedBlackTree value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddHashTableRedBlackTreeP(RedBlackTree *dataStructure, HashTable key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePRedBlackTree(RedBlackTree *dataStructure, const volatile HashTable* key, RedBlackTree value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePRedBlackTreeP(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTableHashTable(RedBlackTree *dataStructure, HashTable key, HashTable value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddHashTableHashTableP(RedBlackTree *dataStructure, HashTable key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePHashTable(RedBlackTree *dataStructure, const volatile HashTable* key, HashTable value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePHashTableP(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTableVector(RedBlackTree *dataStructure, HashTable key, Vector value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddHashTableVectorP(RedBlackTree *dataStructure, HashTable key, const volatile Vector* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePVector(RedBlackTree *dataStructure, const volatile HashTable* key, Vector value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePVectorP(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTableString(RedBlackTree *dataStructure, HashTable key, const volatile char* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddHashTableStringP(RedBlackTree *dataStructure, HashTable key, const volatile char** value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePString(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile char* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePStringP(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile char** value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTableBytes(RedBlackTree *dataStructure, HashTable key, Bytes value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddHashTableBytesP(RedBlackTree *dataStructure, HashTable key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePBytes(RedBlackTree *dataStructure, const volatile HashTable* key, Bytes value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePBytesP(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePointer(RedBlackTree *dataStructure, HashTable key, void* value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePointerP(RedBlackTree *dataStructure, HashTable key, const volatile void** value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePPointer(RedBlackTree *dataStructure, const volatile HashTable* key, void* value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePPointerP(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile void** value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddHashTableI8(RedBlackTree *dataStructure, HashTable key, i8 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePI8(RedBlackTree *dataStructure, const volatile HashTable* key, i8 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddHashTableU8(RedBlackTree *dataStructure, HashTable key, u8 value) {
  if (dataStructure->keyType != typeHashTable) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddHashTablePU8(RedBlackTree *dataStructure, const volatile HashTable* key, u8 value) {
  if (dataStructure->keyType != typeHashTableNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddVectorBool(RedBlackTree *dataStructure, Vector key, bool value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddVectorBoolP(RedBlackTree *dataStructure, Vector key, const volatile bool* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPBool(RedBlackTree *dataStructure, const volatile Vector* key, bool value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddVectorPBoolP(RedBlackTree *dataStructure, const volatile Vector* key, const volatile bool* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorI16(RedBlackTree *dataStructure, Vector key, i16 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddVectorI16P(RedBlackTree *dataStructure, Vector key, const volatile i16* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPI16(RedBlackTree *dataStructure, const volatile Vector* key, i16 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddVectorPI16P(RedBlackTree *dataStructure, const volatile Vector* key, const volatile i16* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorU16(RedBlackTree *dataStructure, Vector key, u16 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddVectorU16P(RedBlackTree *dataStructure, Vector key, const volatile u16* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPU16(RedBlackTree *dataStructure, const volatile Vector* key, u16 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddVectorPU16P(RedBlackTree *dataStructure, const volatile Vector* key, const volatile u16* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorI32(RedBlackTree *dataStructure, Vector key, i32 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddVectorI32P(RedBlackTree *dataStructure, Vector key, const volatile i32* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPI32(RedBlackTree *dataStructure, const volatile Vector* key, i32 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddVectorPI32P(RedBlackTree *dataStructure, const volatile Vector* key, const volatile i32* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorU32(RedBlackTree *dataStructure, Vector key, u32 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddVectorU32P(RedBlackTree *dataStructure, Vector key, const volatile u32* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPU32(RedBlackTree *dataStructure, const volatile Vector* key, u32 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddVectorPU32P(RedBlackTree *dataStructure, const volatile Vector* key, const volatile u32* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorI64(RedBlackTree *dataStructure, Vector key, i64 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddVectorI64P(RedBlackTree *dataStructure, Vector key, const volatile i64* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPI64(RedBlackTree *dataStructure, const volatile Vector* key, i64 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddVectorPI64P(RedBlackTree *dataStructure, const volatile Vector* key, const volatile i64* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorU64(RedBlackTree *dataStructure, Vector key, u64 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddVectorU64P(RedBlackTree *dataStructure, Vector key, const volatile u64* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPU64(RedBlackTree *dataStructure, const volatile Vector* key, u64 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddVectorPU64P(RedBlackTree *dataStructure, const volatile Vector* key, const volatile u64* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorFloat(RedBlackTree *dataStructure, Vector key, float value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddVectorFloatP(RedBlackTree *dataStructure, Vector key, const volatile float* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPFloat(RedBlackTree *dataStructure, const volatile Vector* key, float value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddVectorPFloatP(RedBlackTree *dataStructure, const volatile Vector* key, const volatile float* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorDouble(RedBlackTree *dataStructure, Vector key, double value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddVectorDoubleP(RedBlackTree *dataStructure, Vector key, const volatile double* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPDouble(RedBlackTree *dataStructure, const volatile Vector* key, double value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddVectorPDoubleP(RedBlackTree *dataStructure, const volatile Vector* key, const volatile double* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorLongDouble(RedBlackTree *dataStructure, Vector key, long double value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddVectorLongDoubleP(RedBlackTree *dataStructure, Vector key, const volatile long double* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPLongDouble(RedBlackTree *dataStructure, const volatile Vector* key, long double value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddVectorPLongDoubleP(RedBlackTree *dataStructure, const volatile Vector* key, const volatile long double* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorList(RedBlackTree *dataStructure, Vector key, List value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddVectorListP(RedBlackTree *dataStructure, Vector key, const volatile List* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPList(RedBlackTree *dataStructure, const volatile Vector* key, List value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddVectorPListP(RedBlackTree *dataStructure, const volatile Vector* key, const volatile List* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorQueue(RedBlackTree *dataStructure, Vector key, Queue value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddVectorQueueP(RedBlackTree *dataStructure, Vector key, const volatile Queue* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPQueue(RedBlackTree *dataStructure, const volatile Vector* key, Queue value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddVectorPQueueP(RedBlackTree *dataStructure, const volatile Vector* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorStack(RedBlackTree *dataStructure, Vector key, Stack value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddVectorStackP(RedBlackTree *dataStructure, Vector key, const volatile Stack* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPStack(RedBlackTree *dataStructure, const volatile Vector* key, Stack value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddVectorPStackP(RedBlackTree *dataStructure, const volatile Vector* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorRedBlackTree(RedBlackTree *dataStructure, Vector key, RedBlackTree value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddVectorRedBlackTreeP(RedBlackTree *dataStructure, Vector key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPRedBlackTree(RedBlackTree *dataStructure, const volatile Vector* key, RedBlackTree value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddVectorPRedBlackTreeP(RedBlackTree *dataStructure, const volatile Vector* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorHashTable(RedBlackTree *dataStructure, Vector key, HashTable value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddVectorHashTableP(RedBlackTree *dataStructure, Vector key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPHashTable(RedBlackTree *dataStructure, const volatile Vector* key, HashTable value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddVectorPHashTableP(RedBlackTree *dataStructure, const volatile Vector* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorVector(RedBlackTree *dataStructure, Vector key, Vector value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddVectorVectorP(RedBlackTree *dataStructure, Vector key, const volatile Vector* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPVector(RedBlackTree *dataStructure, const volatile Vector* key, Vector value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddVectorPVectorP(RedBlackTree *dataStructure, const volatile Vector* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorString(RedBlackTree *dataStructure, Vector key, const volatile char* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddVectorStringP(RedBlackTree *dataStructure, Vector key, const volatile char** value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPString(RedBlackTree *dataStructure, const volatile Vector* key, const volatile char* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddVectorPStringP(RedBlackTree *dataStructure, const volatile Vector* key, const volatile char** value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorBytes(RedBlackTree *dataStructure, Vector key, Bytes value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddVectorBytesP(RedBlackTree *dataStructure, Vector key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPBytes(RedBlackTree *dataStructure, const volatile Vector* key, Bytes value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddVectorPBytesP(RedBlackTree *dataStructure, const volatile Vector* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPointer(RedBlackTree *dataStructure, Vector key, void* value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddVectorPointerP(RedBlackTree *dataStructure, Vector key, const volatile void** value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorPPointer(RedBlackTree *dataStructure, const volatile Vector* key, void* value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddVectorPPointerP(RedBlackTree *dataStructure, const volatile Vector* key, const volatile void** value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddVectorI8(RedBlackTree *dataStructure, Vector key, i8 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddVectorPI8(RedBlackTree *dataStructure, const volatile Vector* key, i8 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddVectorU8(RedBlackTree *dataStructure, Vector key, u8 value) {
  if (dataStructure->keyType != typeVector) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddVectorPU8(RedBlackTree *dataStructure, const volatile Vector* key, u8 value) {
  if (dataStructure->keyType != typeVectorNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}

static inline RedBlackTreeNode* rbTreeAddStringBool(RedBlackTree *dataStructure, const volatile char* key, bool value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddStringBoolP(RedBlackTree *dataStructure, const volatile char* key, const volatile bool* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPBool(RedBlackTree *dataStructure, const volatile char** key, bool value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddStringPBoolP(RedBlackTree *dataStructure, const volatile char** key, const volatile bool* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringI16(RedBlackTree *dataStructure, const volatile char* key, i16 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddStringI16P(RedBlackTree *dataStructure, const volatile char* key, const volatile i16* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPI16(RedBlackTree *dataStructure, const volatile char** key, i16 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddStringPI16P(RedBlackTree *dataStructure, const volatile char** key, const volatile i16* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringU16(RedBlackTree *dataStructure, const volatile char* key, u16 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddStringU16P(RedBlackTree *dataStructure, const volatile char* key, const volatile u16* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPU16(RedBlackTree *dataStructure, const volatile char** key, u16 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddStringPU16P(RedBlackTree *dataStructure, const volatile char** key, const volatile u16* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringI32(RedBlackTree *dataStructure, const volatile char* key, i32 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddStringI32P(RedBlackTree *dataStructure, const volatile char* key, const volatile i32* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPI32(RedBlackTree *dataStructure, const volatile char** key, i32 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddStringPI32P(RedBlackTree *dataStructure, const volatile char** key, const volatile i32* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringU32(RedBlackTree *dataStructure, const volatile char* key, u32 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddStringU32P(RedBlackTree *dataStructure, const volatile char* key, const volatile u32* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPU32(RedBlackTree *dataStructure, const volatile char** key, u32 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddStringPU32P(RedBlackTree *dataStructure, const volatile char** key, const volatile u32* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringI64(RedBlackTree *dataStructure, const volatile char* key, i64 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddStringI64P(RedBlackTree *dataStructure, const volatile char* key, const volatile i64* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPI64(RedBlackTree *dataStructure, const volatile char** key, i64 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddStringPI64P(RedBlackTree *dataStructure, const volatile char** key, const volatile i64* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringU64(RedBlackTree *dataStructure, const volatile char* key, u64 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddStringU64P(RedBlackTree *dataStructure, const volatile char* key, const volatile u64* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPU64(RedBlackTree *dataStructure, const volatile char** key, u64 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddStringPU64P(RedBlackTree *dataStructure, const volatile char** key, const volatile u64* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringFloat(RedBlackTree *dataStructure, const volatile char* key, float value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddStringFloatP(RedBlackTree *dataStructure, const volatile char* key, const volatile float* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPFloat(RedBlackTree *dataStructure, const volatile char** key, float value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddStringPFloatP(RedBlackTree *dataStructure, const volatile char** key, const volatile float* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringDouble(RedBlackTree *dataStructure, const volatile char* key, double value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddStringDoubleP(RedBlackTree *dataStructure, const volatile char* key, const volatile double* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPDouble(RedBlackTree *dataStructure, const volatile char** key, double value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddStringPDoubleP(RedBlackTree *dataStructure, const volatile char** key, const volatile double* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringLongDouble(RedBlackTree *dataStructure, const volatile char* key, long double value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddStringLongDoubleP(RedBlackTree *dataStructure, const volatile char* key, const volatile long double* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPLongDouble(RedBlackTree *dataStructure, const volatile char** key, long double value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddStringPLongDoubleP(RedBlackTree *dataStructure, const volatile char** key, const volatile long double* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringList(RedBlackTree *dataStructure, const volatile char* key, List value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddStringListP(RedBlackTree *dataStructure, const volatile char* key, const volatile List* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPList(RedBlackTree *dataStructure, const volatile char** key, List value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddStringPListP(RedBlackTree *dataStructure, const volatile char** key, const volatile List* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringQueue(RedBlackTree *dataStructure, const volatile char* key, Queue value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddStringQueueP(RedBlackTree *dataStructure, const volatile char* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPQueue(RedBlackTree *dataStructure, const volatile char** key, Queue value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddStringPQueueP(RedBlackTree *dataStructure, const volatile char** key, const volatile Queue* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringStack(RedBlackTree *dataStructure, const volatile char* key, Stack value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddStringStackP(RedBlackTree *dataStructure, const volatile char* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPStack(RedBlackTree *dataStructure, const volatile char** key, Stack value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddStringPStackP(RedBlackTree *dataStructure, const volatile char** key, const volatile Stack* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringRedBlackTree(RedBlackTree *dataStructure, const volatile char* key, RedBlackTree value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddStringRedBlackTreeP(RedBlackTree *dataStructure, const volatile char* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPRedBlackTree(RedBlackTree *dataStructure, const volatile char** key, RedBlackTree value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddStringPRedBlackTreeP(RedBlackTree *dataStructure, const volatile char** key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringHashTable(RedBlackTree *dataStructure, const volatile char* key, HashTable value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddStringHashTableP(RedBlackTree *dataStructure, const volatile char* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPHashTable(RedBlackTree *dataStructure, const volatile char** key, HashTable value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddStringPHashTableP(RedBlackTree *dataStructure, const volatile char** key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringVector(RedBlackTree *dataStructure, const volatile char* key, Vector value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddStringVectorP(RedBlackTree *dataStructure, const volatile char* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPVector(RedBlackTree *dataStructure, const volatile char** key, Vector value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddStringPVectorP(RedBlackTree *dataStructure, const volatile char** key, const volatile Vector* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringString(RedBlackTree *dataStructure, const volatile char* key, const volatile char* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddStringStringP(RedBlackTree *dataStructure, const volatile char* key, const volatile char** value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPString(RedBlackTree *dataStructure, const volatile char** key, const volatile char* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddStringPStringP(RedBlackTree *dataStructure, const volatile char** key, const volatile char** value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringBytes(RedBlackTree *dataStructure, const volatile char* key, Bytes value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddStringBytesP(RedBlackTree *dataStructure, const volatile char* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPBytes(RedBlackTree *dataStructure, const volatile char** key, Bytes value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddStringPBytesP(RedBlackTree *dataStructure, const volatile char** key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPointer(RedBlackTree *dataStructure, const volatile char* key, void* value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddStringPointerP(RedBlackTree *dataStructure, const volatile char* key, const volatile void** value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringPPointer(RedBlackTree *dataStructure, const volatile char** key, void* value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddStringPPointerP(RedBlackTree *dataStructure, const volatile char** key, const volatile void** value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddStringI8(RedBlackTree *dataStructure, const volatile char* key, i8 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddStringPI8(RedBlackTree *dataStructure, const volatile char** key, i8 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddStringU8(RedBlackTree *dataStructure, const volatile char* key, u8 value) {
  if (dataStructure->keyType != typeString) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddStringPU8(RedBlackTree *dataStructure, const volatile char** key, u8 value) {
  if (dataStructure->keyType != typeStringNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeU8);
}

static inline RedBlackTreeNode* rbTreeAddBytesBool(RedBlackTree *dataStructure, Bytes key, bool value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddBytesBoolP(RedBlackTree *dataStructure, Bytes key, const volatile bool* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPBool(RedBlackTree *dataStructure, const volatile Bytes* key, bool value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddBytesPBoolP(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile bool* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesI16(RedBlackTree *dataStructure, Bytes key, i16 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddBytesI16P(RedBlackTree *dataStructure, Bytes key, const volatile i16* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPI16(RedBlackTree *dataStructure, const volatile Bytes* key, i16 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddBytesPI16P(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile i16* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesU16(RedBlackTree *dataStructure, Bytes key, u16 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddBytesU16P(RedBlackTree *dataStructure, Bytes key, const volatile u16* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPU16(RedBlackTree *dataStructure, const volatile Bytes* key, u16 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddBytesPU16P(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile u16* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesI32(RedBlackTree *dataStructure, Bytes key, i32 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddBytesI32P(RedBlackTree *dataStructure, Bytes key, const volatile i32* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPI32(RedBlackTree *dataStructure, const volatile Bytes* key, i32 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddBytesPI32P(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile i32* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesU32(RedBlackTree *dataStructure, Bytes key, u32 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddBytesU32P(RedBlackTree *dataStructure, Bytes key, const volatile u32* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPU32(RedBlackTree *dataStructure, const volatile Bytes* key, u32 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddBytesPU32P(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile u32* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesI64(RedBlackTree *dataStructure, Bytes key, i64 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddBytesI64P(RedBlackTree *dataStructure, Bytes key, const volatile i64* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPI64(RedBlackTree *dataStructure, const volatile Bytes* key, i64 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddBytesPI64P(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile i64* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesU64(RedBlackTree *dataStructure, Bytes key, u64 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddBytesU64P(RedBlackTree *dataStructure, Bytes key, const volatile u64* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPU64(RedBlackTree *dataStructure, const volatile Bytes* key, u64 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddBytesPU64P(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile u64* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesFloat(RedBlackTree *dataStructure, Bytes key, float value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddBytesFloatP(RedBlackTree *dataStructure, Bytes key, const volatile float* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPFloat(RedBlackTree *dataStructure, const volatile Bytes* key, float value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddBytesPFloatP(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile float* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesDouble(RedBlackTree *dataStructure, Bytes key, double value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddBytesDoubleP(RedBlackTree *dataStructure, Bytes key, const volatile double* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPDouble(RedBlackTree *dataStructure, const volatile Bytes* key, double value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddBytesPDoubleP(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile double* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesLongDouble(RedBlackTree *dataStructure, Bytes key, long double value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddBytesLongDoubleP(RedBlackTree *dataStructure, Bytes key, const volatile long double* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPLongDouble(RedBlackTree *dataStructure, const volatile Bytes* key, long double value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddBytesPLongDoubleP(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile long double* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesList(RedBlackTree *dataStructure, Bytes key, List value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddBytesListP(RedBlackTree *dataStructure, Bytes key, const volatile List* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPList(RedBlackTree *dataStructure, const volatile Bytes* key, List value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddBytesPListP(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile List* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesQueue(RedBlackTree *dataStructure, Bytes key, Queue value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddBytesQueueP(RedBlackTree *dataStructure, Bytes key, const volatile Queue* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPQueue(RedBlackTree *dataStructure, const volatile Bytes* key, Queue value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddBytesPQueueP(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile Queue* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesStack(RedBlackTree *dataStructure, Bytes key, Stack value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddBytesStackP(RedBlackTree *dataStructure, Bytes key, const volatile Stack* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPStack(RedBlackTree *dataStructure, const volatile Bytes* key, Stack value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddBytesPStackP(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile Stack* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesRedBlackTree(RedBlackTree *dataStructure, Bytes key, RedBlackTree value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddBytesRedBlackTreeP(RedBlackTree *dataStructure, Bytes key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPRedBlackTree(RedBlackTree *dataStructure, const volatile Bytes* key, RedBlackTree value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddBytesPRedBlackTreeP(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesHashTable(RedBlackTree *dataStructure, Bytes key, HashTable value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddBytesHashTableP(RedBlackTree *dataStructure, Bytes key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPHashTable(RedBlackTree *dataStructure, const volatile Bytes* key, HashTable value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddBytesPHashTableP(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesVector(RedBlackTree *dataStructure, Bytes key, Vector value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddBytesVectorP(RedBlackTree *dataStructure, Bytes key, const volatile Vector* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPVector(RedBlackTree *dataStructure, const volatile Bytes* key, Vector value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddBytesPVectorP(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile Vector* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesString(RedBlackTree *dataStructure, Bytes key, const volatile char* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddBytesStringP(RedBlackTree *dataStructure, Bytes key, const volatile char** value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPString(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile char* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddBytesPStringP(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile char** value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesBytes(RedBlackTree *dataStructure, Bytes key, Bytes value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddBytesBytesP(RedBlackTree *dataStructure, Bytes key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPBytes(RedBlackTree *dataStructure, const volatile Bytes* key, Bytes value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddBytesPBytesP(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPointer(RedBlackTree *dataStructure, Bytes key, void* value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddBytesPointerP(RedBlackTree *dataStructure, Bytes key, const volatile void** value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesPPointer(RedBlackTree *dataStructure, const volatile Bytes* key, void* value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddBytesPPointerP(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile void** value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddBytesI8(RedBlackTree *dataStructure, Bytes key, i8 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddBytesPI8(RedBlackTree *dataStructure, const volatile Bytes* key, i8 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddBytesU8(RedBlackTree *dataStructure, Bytes key, u8 value) {
  if (dataStructure->keyType != typeBytes) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddBytesPU8(RedBlackTree *dataStructure, const volatile Bytes* key, u8 value) {
  if (dataStructure->keyType != typeBytesNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeU8);
}

static inline RedBlackTreeNode* rbTreeAddPointerBool(RedBlackTree *dataStructure, void* key, bool value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddPointerBoolP(RedBlackTree *dataStructure, void* key, const volatile bool* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPBool(RedBlackTree *dataStructure, const volatile void** key, bool value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddPointerPBoolP(RedBlackTree *dataStructure, const volatile void** key, const volatile bool* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerI16(RedBlackTree *dataStructure, void* key, i16 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddPointerI16P(RedBlackTree *dataStructure, void* key, const volatile i16* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPI16(RedBlackTree *dataStructure, const volatile void** key, i16 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddPointerPI16P(RedBlackTree *dataStructure, const volatile void** key, const volatile i16* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerU16(RedBlackTree *dataStructure, void* key, u16 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddPointerU16P(RedBlackTree *dataStructure, void* key, const volatile u16* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPU16(RedBlackTree *dataStructure, const volatile void** key, u16 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddPointerPU16P(RedBlackTree *dataStructure, const volatile void** key, const volatile u16* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerI32(RedBlackTree *dataStructure, void* key, i32 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddPointerI32P(RedBlackTree *dataStructure, void* key, const volatile i32* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPI32(RedBlackTree *dataStructure, const volatile void** key, i32 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddPointerPI32P(RedBlackTree *dataStructure, const volatile void** key, const volatile i32* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerU32(RedBlackTree *dataStructure, void* key, u32 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddPointerU32P(RedBlackTree *dataStructure, void* key, const volatile u32* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPU32(RedBlackTree *dataStructure, const volatile void** key, u32 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddPointerPU32P(RedBlackTree *dataStructure, const volatile void** key, const volatile u32* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerI64(RedBlackTree *dataStructure, void* key, i64 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddPointerI64P(RedBlackTree *dataStructure, void* key, const volatile i64* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPI64(RedBlackTree *dataStructure, const volatile void** key, i64 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddPointerPI64P(RedBlackTree *dataStructure, const volatile void** key, const volatile i64* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerU64(RedBlackTree *dataStructure, void* key, u64 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddPointerU64P(RedBlackTree *dataStructure, void* key, const volatile u64* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPU64(RedBlackTree *dataStructure, const volatile void** key, u64 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddPointerPU64P(RedBlackTree *dataStructure, const volatile void** key, const volatile u64* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerFloat(RedBlackTree *dataStructure, void* key, float value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddPointerFloatP(RedBlackTree *dataStructure, void* key, const volatile float* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPFloat(RedBlackTree *dataStructure, const volatile void** key, float value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddPointerPFloatP(RedBlackTree *dataStructure, const volatile void** key, const volatile float* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerDouble(RedBlackTree *dataStructure, void* key, double value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddPointerDoubleP(RedBlackTree *dataStructure, void* key, const volatile double* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPDouble(RedBlackTree *dataStructure, const volatile void** key, double value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddPointerPDoubleP(RedBlackTree *dataStructure, const volatile void** key, const volatile double* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerLongDouble(RedBlackTree *dataStructure, void* key, long double value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddPointerLongDoubleP(RedBlackTree *dataStructure, void* key, const volatile long double* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPLongDouble(RedBlackTree *dataStructure, const volatile void** key, long double value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddPointerPLongDoubleP(RedBlackTree *dataStructure, const volatile void** key, const volatile long double* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerList(RedBlackTree *dataStructure, void* key, List value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddPointerListP(RedBlackTree *dataStructure, void* key, const volatile List* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPList(RedBlackTree *dataStructure, const volatile void** key, List value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddPointerPListP(RedBlackTree *dataStructure, const volatile void** key, const volatile List* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerQueue(RedBlackTree *dataStructure, void* key, Queue value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddPointerQueueP(RedBlackTree *dataStructure, void* key, const volatile Queue* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPQueue(RedBlackTree *dataStructure, const volatile void** key, Queue value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddPointerPQueueP(RedBlackTree *dataStructure, const volatile void** key, const volatile Queue* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerStack(RedBlackTree *dataStructure, void* key, Stack value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddPointerStackP(RedBlackTree *dataStructure, void* key, const volatile Stack* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPStack(RedBlackTree *dataStructure, const volatile void** key, Stack value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddPointerPStackP(RedBlackTree *dataStructure, const volatile void** key, const volatile Stack* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerRedBlackTree(RedBlackTree *dataStructure, void* key, RedBlackTree value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddPointerRedBlackTreeP(RedBlackTree *dataStructure, void* key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPRedBlackTree(RedBlackTree *dataStructure, const volatile void** key, RedBlackTree value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddPointerPRedBlackTreeP(RedBlackTree *dataStructure, const volatile void** key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerHashTable(RedBlackTree *dataStructure, void* key, HashTable value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddPointerHashTableP(RedBlackTree *dataStructure, void* key, const volatile HashTable* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPHashTable(RedBlackTree *dataStructure, const volatile void** key, HashTable value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddPointerPHashTableP(RedBlackTree *dataStructure, const volatile void** key, const volatile HashTable* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerVector(RedBlackTree *dataStructure, void* key, Vector value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddPointerVectorP(RedBlackTree *dataStructure, void* key, const volatile Vector* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPVector(RedBlackTree *dataStructure, const volatile void** key, Vector value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddPointerPVectorP(RedBlackTree *dataStructure, const volatile void** key, const volatile Vector* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerString(RedBlackTree *dataStructure, void* key, const volatile char* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddPointerStringP(RedBlackTree *dataStructure, void* key, const volatile char** value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPString(RedBlackTree *dataStructure, const volatile void** key, const volatile char* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddPointerPStringP(RedBlackTree *dataStructure, const volatile void** key, const volatile char** value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerBytes(RedBlackTree *dataStructure, void* key, Bytes value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddPointerBytesP(RedBlackTree *dataStructure, void* key, const volatile Bytes* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPBytes(RedBlackTree *dataStructure, const volatile void** key, Bytes value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddPointerPBytesP(RedBlackTree *dataStructure, const volatile void** key, const volatile Bytes* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPointer(RedBlackTree *dataStructure, void* key, void* value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddPointerPointerP(RedBlackTree *dataStructure, void* key, const volatile void** value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerPPointer(RedBlackTree *dataStructure, const volatile void** key, void* value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddPointerPPointerP(RedBlackTree *dataStructure, const volatile void** key, const volatile void** value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddPointerI8(RedBlackTree *dataStructure, void* key, i8 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddPointerPI8(RedBlackTree *dataStructure, const volatile void** key, i8 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddPointerU8(RedBlackTree *dataStructure, void* key, u8 value) {
  if (dataStructure->keyType != typePointer) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, key, &value, typeU8);
}
static inline RedBlackTreeNode* rbTreeAddPointerPU8(RedBlackTree *dataStructure, const volatile void** key, u8 value) {
  if (dataStructure->keyType != typePointerNoCopy) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, *key, &value, typeU8);
}

static inline RedBlackTreeNode* rbTreeAddI8Bool(RedBlackTree *dataStructure, i8 key, bool value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddI8BoolP(RedBlackTree *dataStructure, i8 key, const volatile bool* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8I16(RedBlackTree *dataStructure, i8 key, i16 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddI8I16P(RedBlackTree *dataStructure, i8 key, const volatile i16* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8U16(RedBlackTree *dataStructure, i8 key, u16 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddI8U16P(RedBlackTree *dataStructure, i8 key, const volatile u16* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8I32(RedBlackTree *dataStructure, i8 key, i32 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddI8I32P(RedBlackTree *dataStructure, i8 key, const volatile i32* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8U32(RedBlackTree *dataStructure, i8 key, u32 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddI8U32P(RedBlackTree *dataStructure, i8 key, const volatile u32* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8I64(RedBlackTree *dataStructure, i8 key, i64 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddI8I64P(RedBlackTree *dataStructure, i8 key, const volatile i64* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8U64(RedBlackTree *dataStructure, i8 key, u64 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddI8U64P(RedBlackTree *dataStructure, i8 key, const volatile u64* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8Float(RedBlackTree *dataStructure, i8 key, float value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddI8FloatP(RedBlackTree *dataStructure, i8 key, const volatile float* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8Double(RedBlackTree *dataStructure, i8 key, double value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddI8DoubleP(RedBlackTree *dataStructure, i8 key, const volatile double* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8LongDouble(RedBlackTree *dataStructure, i8 key, long double value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddI8LongDoubleP(RedBlackTree *dataStructure, i8 key, const volatile long double* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8List(RedBlackTree *dataStructure, i8 key, List value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddI8ListP(RedBlackTree *dataStructure, i8 key, const volatile List* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8Queue(RedBlackTree *dataStructure, i8 key, Queue value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddI8QueueP(RedBlackTree *dataStructure, i8 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8Stack(RedBlackTree *dataStructure, i8 key, Stack value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddI8StackP(RedBlackTree *dataStructure, i8 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8RedBlackTree(RedBlackTree *dataStructure, i8 key, RedBlackTree value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddI8RedBlackTreeP(RedBlackTree *dataStructure, i8 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8HashTable(RedBlackTree *dataStructure, i8 key, HashTable value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddI8HashTableP(RedBlackTree *dataStructure, i8 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8Vector(RedBlackTree *dataStructure, i8 key, Vector value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddI8VectorP(RedBlackTree *dataStructure, i8 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8String(RedBlackTree *dataStructure, i8 key, const volatile char* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddI8StringP(RedBlackTree *dataStructure, i8 key, const volatile char** value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8Bytes(RedBlackTree *dataStructure, i8 key, Bytes value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddI8BytesP(RedBlackTree *dataStructure, i8 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8Pointer(RedBlackTree *dataStructure, i8 key, void* value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddI8PointerP(RedBlackTree *dataStructure, i8 key, const volatile void** value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddI8I8(RedBlackTree *dataStructure, i8 key, i8 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddI8U8(RedBlackTree *dataStructure, i8 key, u8 value) {
  if (dataStructure->keyType != typeI8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU8);
}

static inline RedBlackTreeNode* rbTreeAddU8Bool(RedBlackTree *dataStructure, u8 key, bool value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeBool);
}
static inline RedBlackTreeNode* rbTreeAddU8BoolP(RedBlackTree *dataStructure, u8 key, const volatile bool* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBoolNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8I16(RedBlackTree *dataStructure, u8 key, i16 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI16);
}
static inline RedBlackTreeNode* rbTreeAddU8I16P(RedBlackTree *dataStructure, u8 key, const volatile i16* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8U16(RedBlackTree *dataStructure, u8 key, u16 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU16);
}
static inline RedBlackTreeNode* rbTreeAddU8U16P(RedBlackTree *dataStructure, u8 key, const volatile u16* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU16NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8I32(RedBlackTree *dataStructure, u8 key, i32 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI32);
}
static inline RedBlackTreeNode* rbTreeAddU8I32P(RedBlackTree *dataStructure, u8 key, const volatile i32* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8U32(RedBlackTree *dataStructure, u8 key, u32 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU32);
}
static inline RedBlackTreeNode* rbTreeAddU8U32P(RedBlackTree *dataStructure, u8 key, const volatile u32* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU32NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8I64(RedBlackTree *dataStructure, u8 key, i64 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI64);
}
static inline RedBlackTreeNode* rbTreeAddU8I64P(RedBlackTree *dataStructure, u8 key, const volatile i64* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeI64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8U64(RedBlackTree *dataStructure, u8 key, u64 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU64);
}
static inline RedBlackTreeNode* rbTreeAddU8U64P(RedBlackTree *dataStructure, u8 key, const volatile u64* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeU64NoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8Float(RedBlackTree *dataStructure, u8 key, float value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeFloat);
}
static inline RedBlackTreeNode* rbTreeAddU8FloatP(RedBlackTree *dataStructure, u8 key, const volatile float* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeFloatNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8Double(RedBlackTree *dataStructure, u8 key, double value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeDouble);
}
static inline RedBlackTreeNode* rbTreeAddU8DoubleP(RedBlackTree *dataStructure, u8 key, const volatile double* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8LongDouble(RedBlackTree *dataStructure, u8 key, long double value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeLongDouble);
}
static inline RedBlackTreeNode* rbTreeAddU8LongDoubleP(RedBlackTree *dataStructure, u8 key, const volatile long double* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeLongDoubleNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8List(RedBlackTree *dataStructure, u8 key, List value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeList);
}
static inline RedBlackTreeNode* rbTreeAddU8ListP(RedBlackTree *dataStructure, u8 key, const volatile List* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeListNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8Queue(RedBlackTree *dataStructure, u8 key, Queue value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeQueue);
}
static inline RedBlackTreeNode* rbTreeAddU8QueueP(RedBlackTree *dataStructure, u8 key, const volatile Queue* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeQueueNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8Stack(RedBlackTree *dataStructure, u8 key, Stack value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeStack);
}
static inline RedBlackTreeNode* rbTreeAddU8StackP(RedBlackTree *dataStructure, u8 key, const volatile Stack* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeStackNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8RedBlackTree(RedBlackTree *dataStructure, u8 key, RedBlackTree value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeRedBlackTree);
}
static inline RedBlackTreeNode* rbTreeAddU8RedBlackTreeP(RedBlackTree *dataStructure, u8 key, const volatile RedBlackTree* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeRedBlackTreeNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8HashTable(RedBlackTree *dataStructure, u8 key, HashTable value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeHashTable);
}
static inline RedBlackTreeNode* rbTreeAddU8HashTableP(RedBlackTree *dataStructure, u8 key, const volatile HashTable* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeHashTableNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8Vector(RedBlackTree *dataStructure, u8 key, Vector value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeVector);
}
static inline RedBlackTreeNode* rbTreeAddU8VectorP(RedBlackTree *dataStructure, u8 key, const volatile Vector* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeVectorNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8String(RedBlackTree *dataStructure, u8 key, const volatile char* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeString);
}
static inline RedBlackTreeNode* rbTreeAddU8StringP(RedBlackTree *dataStructure, u8 key, const volatile char** value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeStringNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8Bytes(RedBlackTree *dataStructure, u8 key, Bytes value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typeBytes);
}
static inline RedBlackTreeNode* rbTreeAddU8BytesP(RedBlackTree *dataStructure, u8 key, const volatile Bytes* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typeBytesNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8Pointer(RedBlackTree *dataStructure, u8 key, void* value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, value, typePointer);
}
static inline RedBlackTreeNode* rbTreeAddU8PointerP(RedBlackTree *dataStructure, u8 key, const volatile void** value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, *value, typePointerNoCopy);
}
static inline RedBlackTreeNode* rbTreeAddU8I8(RedBlackTree *dataStructure, u8 key, i8 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeI8);
}
static inline RedBlackTreeNode* rbTreeAddU8U8(RedBlackTree *dataStructure, u8 key, u8 value) {
  if (dataStructure->keyType != typeU8) {
    // Key types do not match.  Error.
    return NULL;
  }
  return rbTreeAddEntry(dataStructure, &key, &value, typeU8);
}

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#if defined __STDC_VERSION__

#if __STDC_VERSION__ >= 201710L
#define TYPE_SAFE_RED_BLACK_TREE

#define RB_TREE_ADD_GENERIC_CASES_BOOL_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddBoolBool,                          \
  bool*:                 rbTreeAddBoolBoolP,                         \
  const volatile bool*:  rbTreeAddBoolBoolP,                         \
  i16:                   rbTreeAddBoolI16,                           \
  i16*:                  rbTreeAddBoolI16P,                          \
  const volatile i16*:   rbTreeAddBoolI16P,                          \
  u16:                   rbTreeAddBoolU16,                           \
  u16*:                  rbTreeAddBoolU16P,                          \
  const volatile u16*:   rbTreeAddBoolU16P,                          \
  i32:                   rbTreeAddBoolI32,                           \
  i32*:                  rbTreeAddBoolI32P,                          \
  const volatile i32*:   rbTreeAddBoolI32P,                          \
  u32:                   rbTreeAddBoolU32,                           \
  u32*:                  rbTreeAddBoolU32P,                          \
  const volatile u32*:   rbTreeAddBoolU32P,                          \
  i64:                   rbTreeAddBoolI64,                           \
  i64*:                  rbTreeAddBoolI64P,                          \
  const volatile i64*:   rbTreeAddBoolI64P,                          \
  u64:                   rbTreeAddBoolU64,                           \
  u64*:                  rbTreeAddBoolU64P,                          \
  const volatile u64*:   rbTreeAddBoolU64P,                          \
  float:                 rbTreeAddBoolFloat,                         \
  float*:                rbTreeAddBoolFloatP,                        \
  const volatile float*: rbTreeAddBoolFloatP,                        \
  double:                rbTreeAddBoolDouble,                        \
  double*:               rbTreeAddBoolDoubleP,                       \
  const volatile double*: rbTreeAddBoolDoubleP,                       \
  long double:           rbTreeAddBoolLongDouble,                    \
  long double*:          rbTreeAddBoolLongDoubleP,                   \
  const volatile long double*: rbTreeAddBoolLongDoubleP,                   \
  List:                  rbTreeAddBoolList,                          \
  List*:                 rbTreeAddBoolListP,                         \
  const volatile List*:  rbTreeAddBoolListP,                         \
  Queue:                 rbTreeAddBoolQueue,                         \
  Queue*:                rbTreeAddBoolQueueP,                        \
  const volatile Queue*: rbTreeAddBoolQueueP,                        \
  Stack:                 rbTreeAddBoolStack,                         \
  Stack*:                rbTreeAddBoolStackP,                        \
  const volatile Stack*: rbTreeAddBoolStackP,                        \
  RedBlackTree:          rbTreeAddBoolRedBlackTree,                  \
  RedBlackTree*:         rbTreeAddBoolRedBlackTreeP,                 \
  const volatile RedBlackTree*: rbTreeAddBoolRedBlackTreeP,                 \
  HashTable:             rbTreeAddBoolHashTable,                     \
  HashTable*:            rbTreeAddBoolHashTableP,                    \
  const volatile HashTable*: rbTreeAddBoolHashTableP,                    \
  Vector:                rbTreeAddBoolVector,                        \
  Vector*:               rbTreeAddBoolVectorP,                       \
  const volatile Vector*: rbTreeAddBoolVectorP,                       \
  char*:                 rbTreeAddBoolString,                        \
  const volatile char*:  rbTreeAddBoolString,                        \
  char**:                rbTreeAddBoolStringP,                       \
  const volatile char**: rbTreeAddBoolStringP,                       \
  Bytes:                 rbTreeAddBoolBytes,                         \
  Bytes*:                rbTreeAddBoolBytesP,                        \
  const volatile Bytes*: rbTreeAddBoolBytesP,                        \
  void*:                 rbTreeAddBoolPointer,                       \
  void**:                rbTreeAddBoolPointerP,                      \
  const volatile void**: rbTreeAddBoolPointerP,                      \
  i8:                    rbTreeAddBoolI8,                            \
  u8:                    rbTreeAddBoolU8                             \

#define rbTreeAddBool(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_BOOL_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_I16_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddI16Bool,                           \
  bool*:                 rbTreeAddI16BoolP,                          \
  const volatile bool*:  rbTreeAddI16BoolP,                          \
  i16:                   rbTreeAddI16I16,                            \
  i16*:                  rbTreeAddI16I16P,                           \
  const volatile i16*:   rbTreeAddI16I16P,                           \
  u16:                   rbTreeAddI16U16,                            \
  u16*:                  rbTreeAddI16U16P,                           \
  const volatile u16*:   rbTreeAddI16U16P,                           \
  i32:                   rbTreeAddI16I32,                            \
  i32*:                  rbTreeAddI16I32P,                           \
  const volatile i32*:   rbTreeAddI16I32P,                           \
  u32:                   rbTreeAddI16U32,                            \
  u32*:                  rbTreeAddI16U32P,                           \
  const volatile u32*:   rbTreeAddI16U32P,                           \
  i64:                   rbTreeAddI16I64,                            \
  i64*:                  rbTreeAddI16I64P,                           \
  const volatile i64*:   rbTreeAddI16I64P,                           \
  u64:                   rbTreeAddI16U64,                            \
  u64*:                  rbTreeAddI16U64P,                           \
  const volatile u64*:   rbTreeAddI16U64P,                           \
  float:                 rbTreeAddI16Float,                          \
  float*:                rbTreeAddI16FloatP,                         \
  const volatile float*: rbTreeAddI16FloatP,                         \
  double:                rbTreeAddI16Double,                         \
  double*:               rbTreeAddI16DoubleP,                        \
  const volatile double*: rbTreeAddI16DoubleP,                        \
  long double:           rbTreeAddI16LongDouble,                     \
  long double*:          rbTreeAddI16LongDoubleP,                    \
  const volatile long double*: rbTreeAddI16LongDoubleP,                    \
  List:                  rbTreeAddI16List,                           \
  List*:                 rbTreeAddI16ListP,                          \
  const volatile List*:  rbTreeAddI16ListP,                          \
  Queue:                 rbTreeAddI16Queue,                          \
  Queue*:                rbTreeAddI16QueueP,                         \
  const volatile Queue*: rbTreeAddI16QueueP,                         \
  Stack:                 rbTreeAddI16Stack,                          \
  Stack*:                rbTreeAddI16StackP,                         \
  const volatile Stack*: rbTreeAddI16StackP,                         \
  RedBlackTree:          rbTreeAddI16RedBlackTree,                   \
  RedBlackTree*:         rbTreeAddI16RedBlackTreeP,                  \
  const volatile RedBlackTree*: rbTreeAddI16RedBlackTreeP,                  \
  HashTable:             rbTreeAddI16HashTable,                      \
  HashTable*:            rbTreeAddI16HashTableP,                     \
  const volatile HashTable*: rbTreeAddI16HashTableP,                     \
  Vector:                rbTreeAddI16Vector,                         \
  Vector*:               rbTreeAddI16VectorP,                        \
  const volatile Vector*: rbTreeAddI16VectorP,                        \
  char*:                 rbTreeAddI16String,                         \
  const volatile char*:  rbTreeAddI16String,                         \
  char**:                rbTreeAddI16StringP,                        \
  const volatile char**: rbTreeAddI16StringP,                        \
  Bytes:                 rbTreeAddI16Bytes,                          \
  Bytes*:                rbTreeAddI16BytesP,                         \
  const volatile Bytes*: rbTreeAddI16BytesP,                         \
  void*:                 rbTreeAddI16Pointer,                        \
  void**:                rbTreeAddI16PointerP,                       \
  const volatile void**: rbTreeAddI16PointerP,                       \
  i8:                    rbTreeAddI16I8,                             \
  u8:                    rbTreeAddI16U8                              \

#define rbTreeAddI16(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_I16_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_U16_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddU16Bool,                           \
  bool*:                 rbTreeAddU16BoolP,                          \
  const volatile bool*:  rbTreeAddU16BoolP,                          \
  i16:                   rbTreeAddU16I16,                            \
  i16*:                  rbTreeAddU16I16P,                           \
  const volatile i16*:   rbTreeAddU16I16P,                           \
  u16:                   rbTreeAddU16U16,                            \
  u16*:                  rbTreeAddU16U16P,                           \
  const volatile u16*:   rbTreeAddU16U16P,                           \
  i32:                   rbTreeAddU16I32,                            \
  i32*:                  rbTreeAddU16I32P,                           \
  const volatile i32*:   rbTreeAddU16I32P,                           \
  u32:                   rbTreeAddU16U32,                            \
  u32*:                  rbTreeAddU16U32P,                           \
  const volatile u32*:   rbTreeAddU16U32P,                           \
  i64:                   rbTreeAddU16I64,                            \
  i64*:                  rbTreeAddU16I64P,                           \
  const volatile i64*:   rbTreeAddU16I64P,                           \
  u64:                   rbTreeAddU16U64,                            \
  u64*:                  rbTreeAddU16U64P,                           \
  const volatile u64*:   rbTreeAddU16U64P,                           \
  float:                 rbTreeAddU16Float,                          \
  float*:                rbTreeAddU16FloatP,                         \
  const volatile float*: rbTreeAddU16FloatP,                         \
  double:                rbTreeAddU16Double,                         \
  double*:               rbTreeAddU16DoubleP,                        \
  const volatile double*: rbTreeAddU16DoubleP,                        \
  long double:           rbTreeAddU16LongDouble,                     \
  long double*:          rbTreeAddU16LongDoubleP,                    \
  const volatile long double*: rbTreeAddU16LongDoubleP,                    \
  List:                  rbTreeAddU16List,                           \
  List*:                 rbTreeAddU16ListP,                          \
  const volatile List*:  rbTreeAddU16ListP,                          \
  Queue:                 rbTreeAddU16Queue,                          \
  Queue*:                rbTreeAddU16QueueP,                         \
  const volatile Queue*: rbTreeAddU16QueueP,                         \
  Stack:                 rbTreeAddU16Stack,                          \
  Stack*:                rbTreeAddU16StackP,                         \
  const volatile Stack*: rbTreeAddU16StackP,                         \
  RedBlackTree:          rbTreeAddU16RedBlackTree,                   \
  RedBlackTree*:         rbTreeAddU16RedBlackTreeP,                  \
  const volatile RedBlackTree*: rbTreeAddU16RedBlackTreeP,                  \
  HashTable:             rbTreeAddU16HashTable,                      \
  HashTable*:            rbTreeAddU16HashTableP,                     \
  const volatile HashTable*: rbTreeAddU16HashTableP,                     \
  Vector:                rbTreeAddU16Vector,                         \
  Vector*:               rbTreeAddU16VectorP,                        \
  const volatile Vector*: rbTreeAddU16VectorP,                        \
  char*:                 rbTreeAddU16String,                         \
  const volatile char*:  rbTreeAddU16String,                         \
  char**:                rbTreeAddU16StringP,                        \
  const volatile char**: rbTreeAddU16StringP,                        \
  Bytes:                 rbTreeAddU16Bytes,                          \
  Bytes*:                rbTreeAddU16BytesP,                         \
  const volatile Bytes*: rbTreeAddU16BytesP,                         \
  void*:                 rbTreeAddU16Pointer,                        \
  void**:                rbTreeAddU16PointerP,                       \
  const volatile void**: rbTreeAddU16PointerP,                       \
  i8:                    rbTreeAddU16I8,                             \
  u8:                    rbTreeAddU16U8                              \

#define rbTreeAddU16(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_U16_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_I32_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddI32Bool,                           \
  bool*:                 rbTreeAddI32BoolP,                          \
  const volatile bool*:  rbTreeAddI32BoolP,                          \
  i16:                   rbTreeAddI32I16,                            \
  i16*:                  rbTreeAddI32I16P,                           \
  const volatile i16*:   rbTreeAddI32I16P,                           \
  u16:                   rbTreeAddI32U16,                            \
  u16*:                  rbTreeAddI32U16P,                           \
  const volatile u16*:   rbTreeAddI32U16P,                           \
  i32:                   rbTreeAddI32I32,                            \
  i32*:                  rbTreeAddI32I32P,                           \
  const volatile i32*:   rbTreeAddI32I32P,                           \
  u32:                   rbTreeAddI32U32,                            \
  u32*:                  rbTreeAddI32U32P,                           \
  const volatile u32*:   rbTreeAddI32U32P,                           \
  i64:                   rbTreeAddI32I64,                            \
  i64*:                  rbTreeAddI32I64P,                           \
  const volatile i64*:   rbTreeAddI32I64P,                           \
  u64:                   rbTreeAddI32U64,                            \
  u64*:                  rbTreeAddI32U64P,                           \
  const volatile u64*:   rbTreeAddI32U64P,                           \
  float:                 rbTreeAddI32Float,                          \
  float*:                rbTreeAddI32FloatP,                         \
  const volatile float*: rbTreeAddI32FloatP,                         \
  double:                rbTreeAddI32Double,                         \
  double*:               rbTreeAddI32DoubleP,                        \
  const volatile double*: rbTreeAddI32DoubleP,                        \
  long double:           rbTreeAddI32LongDouble,                     \
  long double*:          rbTreeAddI32LongDoubleP,                    \
  const volatile long double*: rbTreeAddI32LongDoubleP,                    \
  List:                  rbTreeAddI32List,                           \
  List*:                 rbTreeAddI32ListP,                          \
  const volatile List*:  rbTreeAddI32ListP,                          \
  Queue:                 rbTreeAddI32Queue,                          \
  Queue*:                rbTreeAddI32QueueP,                         \
  const volatile Queue*: rbTreeAddI32QueueP,                         \
  Stack:                 rbTreeAddI32Stack,                          \
  Stack*:                rbTreeAddI32StackP,                         \
  const volatile Stack*: rbTreeAddI32StackP,                         \
  RedBlackTree:          rbTreeAddI32RedBlackTree,                   \
  RedBlackTree*:         rbTreeAddI32RedBlackTreeP,                  \
  const volatile RedBlackTree*: rbTreeAddI32RedBlackTreeP,                  \
  HashTable:             rbTreeAddI32HashTable,                      \
  HashTable*:            rbTreeAddI32HashTableP,                     \
  const volatile HashTable*: rbTreeAddI32HashTableP,                     \
  Vector:                rbTreeAddI32Vector,                         \
  Vector*:               rbTreeAddI32VectorP,                        \
  const volatile Vector*: rbTreeAddI32VectorP,                        \
  char*:                 rbTreeAddI32String,                         \
  const volatile char*:  rbTreeAddI32String,                         \
  char**:                rbTreeAddI32StringP,                        \
  const volatile char**: rbTreeAddI32StringP,                        \
  Bytes:                 rbTreeAddI32Bytes,                          \
  Bytes*:                rbTreeAddI32BytesP,                         \
  const volatile Bytes*: rbTreeAddI32BytesP,                         \
  void*:                 rbTreeAddI32Pointer,                        \
  void**:                rbTreeAddI32PointerP,                       \
  const volatile void**: rbTreeAddI32PointerP,                       \
  i8:                    rbTreeAddI32I8,                             \
  u8:                    rbTreeAddI32U8                              \

#define rbTreeAddI32(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_I32_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_U32_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddU32Bool,                           \
  bool*:                 rbTreeAddU32BoolP,                          \
  const volatile bool*:  rbTreeAddU32BoolP,                          \
  i16:                   rbTreeAddU32I16,                            \
  i16*:                  rbTreeAddU32I16P,                           \
  const volatile i16*:   rbTreeAddU32I16P,                           \
  u16:                   rbTreeAddU32U16,                            \
  u16*:                  rbTreeAddU32U16P,                           \
  const volatile u16*:   rbTreeAddU32U16P,                           \
  i32:                   rbTreeAddU32I32,                            \
  i32*:                  rbTreeAddU32I32P,                           \
  const volatile i32*:   rbTreeAddU32I32P,                           \
  u32:                   rbTreeAddU32U32,                            \
  u32*:                  rbTreeAddU32U32P,                           \
  const volatile u32*:   rbTreeAddU32U32P,                           \
  i64:                   rbTreeAddU32I64,                            \
  i64*:                  rbTreeAddU32I64P,                           \
  const volatile i64*:   rbTreeAddU32I64P,                           \
  u64:                   rbTreeAddU32U64,                            \
  u64*:                  rbTreeAddU32U64P,                           \
  const volatile u64*:   rbTreeAddU32U64P,                           \
  float:                 rbTreeAddU32Float,                          \
  float*:                rbTreeAddU32FloatP,                         \
  const volatile float*: rbTreeAddU32FloatP,                         \
  double:                rbTreeAddU32Double,                         \
  double*:               rbTreeAddU32DoubleP,                        \
  const volatile double*: rbTreeAddU32DoubleP,                        \
  long double:           rbTreeAddU32LongDouble,                     \
  long double*:          rbTreeAddU32LongDoubleP,                    \
  const volatile long double*: rbTreeAddU32LongDoubleP,                    \
  List:                  rbTreeAddU32List,                           \
  List*:                 rbTreeAddU32ListP,                          \
  const volatile List*:  rbTreeAddU32ListP,                          \
  Queue:                 rbTreeAddU32Queue,                          \
  Queue*:                rbTreeAddU32QueueP,                         \
  const volatile Queue*: rbTreeAddU32QueueP,                         \
  Stack:                 rbTreeAddU32Stack,                          \
  Stack*:                rbTreeAddU32StackP,                         \
  const volatile Stack*: rbTreeAddU32StackP,                         \
  RedBlackTree:          rbTreeAddU32RedBlackTree,                   \
  RedBlackTree*:         rbTreeAddU32RedBlackTreeP,                  \
  const volatile RedBlackTree*: rbTreeAddU32RedBlackTreeP,                  \
  HashTable:             rbTreeAddU32HashTable,                      \
  HashTable*:            rbTreeAddU32HashTableP,                     \
  const volatile HashTable*: rbTreeAddU32HashTableP,                     \
  Vector:                rbTreeAddU32Vector,                         \
  Vector*:               rbTreeAddU32VectorP,                        \
  const volatile Vector*: rbTreeAddU32VectorP,                        \
  char*:                 rbTreeAddU32String,                         \
  const volatile char*:  rbTreeAddU32String,                         \
  char**:                rbTreeAddU32StringP,                        \
  const volatile char**: rbTreeAddU32StringP,                        \
  Bytes:                 rbTreeAddU32Bytes,                          \
  Bytes*:                rbTreeAddU32BytesP,                         \
  const volatile Bytes*: rbTreeAddU32BytesP,                         \
  void*:                 rbTreeAddU32Pointer,                        \
  void**:                rbTreeAddU32PointerP,                       \
  const volatile void**: rbTreeAddU32PointerP,                       \
  i8:                    rbTreeAddU32I8,                             \
  u8:                    rbTreeAddU32U8                              \

#define rbTreeAddU32(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_U32_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_I64_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddI64Bool,                           \
  bool*:                 rbTreeAddI64BoolP,                          \
  const volatile bool*:  rbTreeAddI64BoolP,                          \
  i16:                   rbTreeAddI64I16,                            \
  i16*:                  rbTreeAddI64I16P,                           \
  const volatile i16*:   rbTreeAddI64I16P,                           \
  u16:                   rbTreeAddI64U16,                            \
  u16*:                  rbTreeAddI64U16P,                           \
  const volatile u16*:   rbTreeAddI64U16P,                           \
  i32:                   rbTreeAddI64I32,                            \
  i32*:                  rbTreeAddI64I32P,                           \
  const volatile i32*:   rbTreeAddI64I32P,                           \
  u32:                   rbTreeAddI64U32,                            \
  u32*:                  rbTreeAddI64U32P,                           \
  const volatile u32*:   rbTreeAddI64U32P,                           \
  i64:                   rbTreeAddI64I64,                            \
  i64*:                  rbTreeAddI64I64P,                           \
  const volatile i64*:   rbTreeAddI64I64P,                           \
  u64:                   rbTreeAddI64U64,                            \
  u64*:                  rbTreeAddI64U64P,                           \
  const volatile u64*:   rbTreeAddI64U64P,                           \
  float:                 rbTreeAddI64Float,                          \
  float*:                rbTreeAddI64FloatP,                         \
  const volatile float*: rbTreeAddI64FloatP,                         \
  double:                rbTreeAddI64Double,                         \
  double*:               rbTreeAddI64DoubleP,                        \
  const volatile double*: rbTreeAddI64DoubleP,                        \
  long double:           rbTreeAddI64LongDouble,                     \
  long double*:          rbTreeAddI64LongDoubleP,                    \
  const volatile long double*: rbTreeAddI64LongDoubleP,                    \
  List:                  rbTreeAddI64List,                           \
  List*:                 rbTreeAddI64ListP,                          \
  const volatile List*:  rbTreeAddI64ListP,                          \
  Queue:                 rbTreeAddI64Queue,                          \
  Queue*:                rbTreeAddI64QueueP,                         \
  const volatile Queue*: rbTreeAddI64QueueP,                         \
  Stack:                 rbTreeAddI64Stack,                          \
  Stack*:                rbTreeAddI64StackP,                         \
  const volatile Stack*: rbTreeAddI64StackP,                         \
  RedBlackTree:          rbTreeAddI64RedBlackTree,                   \
  RedBlackTree*:         rbTreeAddI64RedBlackTreeP,                  \
  const volatile RedBlackTree*: rbTreeAddI64RedBlackTreeP,                  \
  HashTable:             rbTreeAddI64HashTable,                      \
  HashTable*:            rbTreeAddI64HashTableP,                     \
  const volatile HashTable*: rbTreeAddI64HashTableP,                     \
  Vector:                rbTreeAddI64Vector,                         \
  Vector*:               rbTreeAddI64VectorP,                        \
  const volatile Vector*: rbTreeAddI64VectorP,                        \
  char*:                 rbTreeAddI64String,                         \
  const volatile char*:  rbTreeAddI64String,                         \
  char**:                rbTreeAddI64StringP,                        \
  const volatile char**: rbTreeAddI64StringP,                        \
  Bytes:                 rbTreeAddI64Bytes,                          \
  Bytes*:                rbTreeAddI64BytesP,                         \
  const volatile Bytes*: rbTreeAddI64BytesP,                         \
  void*:                 rbTreeAddI64Pointer,                        \
  void**:                rbTreeAddI64PointerP,                       \
  const volatile void**: rbTreeAddI64PointerP,                       \
  i8:                    rbTreeAddI64I8,                             \
  u8:                    rbTreeAddI64U8                              \

#define rbTreeAddI64(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_I64_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_U64_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddU64Bool,                           \
  bool*:                 rbTreeAddU64BoolP,                          \
  const volatile bool*:  rbTreeAddU64BoolP,                          \
  i16:                   rbTreeAddU64I16,                            \
  i16*:                  rbTreeAddU64I16P,                           \
  const volatile i16*:   rbTreeAddU64I16P,                           \
  u16:                   rbTreeAddU64U16,                            \
  u16*:                  rbTreeAddU64U16P,                           \
  const volatile u16*:   rbTreeAddU64U16P,                           \
  i32:                   rbTreeAddU64I32,                            \
  i32*:                  rbTreeAddU64I32P,                           \
  const volatile i32*:   rbTreeAddU64I32P,                           \
  u32:                   rbTreeAddU64U32,                            \
  u32*:                  rbTreeAddU64U32P,                           \
  const volatile u32*:   rbTreeAddU64U32P,                           \
  i64:                   rbTreeAddU64I64,                            \
  i64*:                  rbTreeAddU64I64P,                           \
  const volatile i64*:   rbTreeAddU64I64P,                           \
  u64:                   rbTreeAddU64U64,                            \
  u64*:                  rbTreeAddU64U64P,                           \
  const volatile u64*:   rbTreeAddU64U64P,                           \
  float:                 rbTreeAddU64Float,                          \
  float*:                rbTreeAddU64FloatP,                         \
  const volatile float*: rbTreeAddU64FloatP,                         \
  double:                rbTreeAddU64Double,                         \
  double*:               rbTreeAddU64DoubleP,                        \
  const volatile double*: rbTreeAddU64DoubleP,                        \
  long double:           rbTreeAddU64LongDouble,                     \
  long double*:          rbTreeAddU64LongDoubleP,                    \
  const volatile long double*: rbTreeAddU64LongDoubleP,                    \
  List:                  rbTreeAddU64List,                           \
  List*:                 rbTreeAddU64ListP,                          \
  const volatile List*:  rbTreeAddU64ListP,                          \
  Queue:                 rbTreeAddU64Queue,                          \
  Queue*:                rbTreeAddU64QueueP,                         \
  const volatile Queue*: rbTreeAddU64QueueP,                         \
  Stack:                 rbTreeAddU64Stack,                          \
  Stack*:                rbTreeAddU64StackP,                         \
  const volatile Stack*: rbTreeAddU64StackP,                         \
  RedBlackTree:          rbTreeAddU64RedBlackTree,                   \
  RedBlackTree*:         rbTreeAddU64RedBlackTreeP,                  \
  const volatile RedBlackTree*: rbTreeAddU64RedBlackTreeP,                  \
  HashTable:             rbTreeAddU64HashTable,                      \
  HashTable*:            rbTreeAddU64HashTableP,                     \
  const volatile HashTable*: rbTreeAddU64HashTableP,                     \
  Vector:                rbTreeAddU64Vector,                         \
  Vector*:               rbTreeAddU64VectorP,                        \
  const volatile Vector*: rbTreeAddU64VectorP,                        \
  char*:                 rbTreeAddU64String,                         \
  const volatile char*:  rbTreeAddU64String,                         \
  char**:                rbTreeAddU64StringP,                        \
  const volatile char**: rbTreeAddU64StringP,                        \
  Bytes:                 rbTreeAddU64Bytes,                          \
  Bytes*:                rbTreeAddU64BytesP,                         \
  const volatile Bytes*: rbTreeAddU64BytesP,                         \
  void*:                 rbTreeAddU64Pointer,                        \
  void**:                rbTreeAddU64PointerP,                       \
  const volatile void**: rbTreeAddU64PointerP,                       \
  i8:                    rbTreeAddU64I8,                             \
  u8:                    rbTreeAddU64U8                              \

#define rbTreeAddU64(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_U64_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_FLOAT_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddFloatBool,                         \
  bool*:                 rbTreeAddFloatBoolP,                        \
  const volatile bool*:  rbTreeAddFloatBoolP,                        \
  i16:                   rbTreeAddFloatI16,                          \
  i16*:                  rbTreeAddFloatI16P,                         \
  const volatile i16*:   rbTreeAddFloatI16P,                         \
  u16:                   rbTreeAddFloatU16,                          \
  u16*:                  rbTreeAddFloatU16P,                         \
  const volatile u16*:   rbTreeAddFloatU16P,                         \
  i32:                   rbTreeAddFloatI32,                          \
  i32*:                  rbTreeAddFloatI32P,                         \
  const volatile i32*:   rbTreeAddFloatI32P,                         \
  u32:                   rbTreeAddFloatU32,                          \
  u32*:                  rbTreeAddFloatU32P,                         \
  const volatile u32*:   rbTreeAddFloatU32P,                         \
  i64:                   rbTreeAddFloatI64,                          \
  i64*:                  rbTreeAddFloatI64P,                         \
  const volatile i64*:   rbTreeAddFloatI64P,                         \
  u64:                   rbTreeAddFloatU64,                          \
  u64*:                  rbTreeAddFloatU64P,                         \
  const volatile u64*:   rbTreeAddFloatU64P,                         \
  float:                 rbTreeAddFloatFloat,                        \
  float*:                rbTreeAddFloatFloatP,                       \
  const volatile float*: rbTreeAddFloatFloatP,                       \
  double:                rbTreeAddFloatDouble,                       \
  double*:               rbTreeAddFloatDoubleP,                      \
  const volatile double*: rbTreeAddFloatDoubleP,                      \
  long double:           rbTreeAddFloatLongDouble,                   \
  long double*:          rbTreeAddFloatLongDoubleP,                  \
  const volatile long double*: rbTreeAddFloatLongDoubleP,                  \
  List:                  rbTreeAddFloatList,                         \
  List*:                 rbTreeAddFloatListP,                        \
  const volatile List*:  rbTreeAddFloatListP,                        \
  Queue:                 rbTreeAddFloatQueue,                        \
  Queue*:                rbTreeAddFloatQueueP,                       \
  const volatile Queue*: rbTreeAddFloatQueueP,                       \
  Stack:                 rbTreeAddFloatStack,                        \
  Stack*:                rbTreeAddFloatStackP,                       \
  const volatile Stack*: rbTreeAddFloatStackP,                       \
  RedBlackTree:          rbTreeAddFloatRedBlackTree,                 \
  RedBlackTree*:         rbTreeAddFloatRedBlackTreeP,                \
  const volatile RedBlackTree*: rbTreeAddFloatRedBlackTreeP,                \
  HashTable:             rbTreeAddFloatHashTable,                    \
  HashTable*:            rbTreeAddFloatHashTableP,                   \
  const volatile HashTable*: rbTreeAddFloatHashTableP,                   \
  Vector:                rbTreeAddFloatVector,                       \
  Vector*:               rbTreeAddFloatVectorP,                      \
  const volatile Vector*: rbTreeAddFloatVectorP,                      \
  char*:                 rbTreeAddFloatString,                       \
  const volatile char*:  rbTreeAddFloatString,                       \
  char**:                rbTreeAddFloatStringP,                      \
  const volatile char**: rbTreeAddFloatStringP,                      \
  Bytes:                 rbTreeAddFloatBytes,                        \
  Bytes*:                rbTreeAddFloatBytesP,                       \
  const volatile Bytes*: rbTreeAddFloatBytesP,                       \
  void*:                 rbTreeAddFloatPointer,                      \
  void**:                rbTreeAddFloatPointerP,                     \
  const volatile void**: rbTreeAddFloatPointerP,                     \
  i8:                    rbTreeAddFloatI8,                           \
  u8:                    rbTreeAddFloatU8                            \

#define rbTreeAddFloat(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_FLOAT_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_DOUBLE_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddDoubleBool,                        \
  bool*:                 rbTreeAddDoubleBoolP,                       \
  const volatile bool*:  rbTreeAddDoubleBoolP,                       \
  i16:                   rbTreeAddDoubleI16,                         \
  i16*:                  rbTreeAddDoubleI16P,                        \
  const volatile i16*:   rbTreeAddDoubleI16P,                        \
  u16:                   rbTreeAddDoubleU16,                         \
  u16*:                  rbTreeAddDoubleU16P,                        \
  const volatile u16*:   rbTreeAddDoubleU16P,                        \
  i32:                   rbTreeAddDoubleI32,                         \
  i32*:                  rbTreeAddDoubleI32P,                        \
  const volatile i32*:   rbTreeAddDoubleI32P,                        \
  u32:                   rbTreeAddDoubleU32,                         \
  u32*:                  rbTreeAddDoubleU32P,                        \
  const volatile u32*:   rbTreeAddDoubleU32P,                        \
  i64:                   rbTreeAddDoubleI64,                         \
  i64*:                  rbTreeAddDoubleI64P,                        \
  const volatile i64*:   rbTreeAddDoubleI64P,                        \
  u64:                   rbTreeAddDoubleU64,                         \
  u64*:                  rbTreeAddDoubleU64P,                        \
  const volatile u64*:   rbTreeAddDoubleU64P,                        \
  float:                 rbTreeAddDoubleFloat,                       \
  float*:                rbTreeAddDoubleFloatP,                      \
  const volatile float*: rbTreeAddDoubleFloatP,                      \
  double:                rbTreeAddDoubleDouble,                      \
  double*:               rbTreeAddDoubleDoubleP,                     \
  const volatile double*: rbTreeAddDoubleDoubleP,                     \
  long double:           rbTreeAddDoubleLongDouble,                  \
  long double*:          rbTreeAddDoubleLongDoubleP,                 \
  const volatile long double*: rbTreeAddDoubleLongDoubleP,                 \
  List:                  rbTreeAddDoubleList,                        \
  List*:                 rbTreeAddDoubleListP,                       \
  const volatile List*:  rbTreeAddDoubleListP,                       \
  Queue:                 rbTreeAddDoubleQueue,                       \
  Queue*:                rbTreeAddDoubleQueueP,                      \
  const volatile Queue*: rbTreeAddDoubleQueueP,                      \
  Stack:                 rbTreeAddDoubleStack,                       \
  Stack*:                rbTreeAddDoubleStackP,                      \
  const volatile Stack*: rbTreeAddDoubleStackP,                      \
  RedBlackTree:          rbTreeAddDoubleRedBlackTree,                \
  RedBlackTree*:         rbTreeAddDoubleRedBlackTreeP,               \
  const volatile RedBlackTree*: rbTreeAddDoubleRedBlackTreeP,               \
  HashTable:             rbTreeAddDoubleHashTable,                   \
  HashTable*:            rbTreeAddDoubleHashTableP,                  \
  const volatile HashTable*: rbTreeAddDoubleHashTableP,                  \
  Vector:                rbTreeAddDoubleVector,                      \
  Vector*:               rbTreeAddDoubleVectorP,                     \
  const volatile Vector*: rbTreeAddDoubleVectorP,                     \
  char*:                 rbTreeAddDoubleString,                      \
  const volatile char*:  rbTreeAddDoubleString,                      \
  char**:                rbTreeAddDoubleStringP,                     \
  const volatile char**: rbTreeAddDoubleStringP,                     \
  Bytes:                 rbTreeAddDoubleBytes,                       \
  Bytes*:                rbTreeAddDoubleBytesP,                      \
  const volatile Bytes*: rbTreeAddDoubleBytesP,                      \
  void*:                 rbTreeAddDoublePointer,                     \
  void**:                rbTreeAddDoublePointerP,                    \
  const volatile void**: rbTreeAddDoublePointerP,                    \
  i8:                    rbTreeAddDoubleI8,                          \
  u8:                    rbTreeAddDoubleU8                           \

#define rbTreeAddDouble(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_DOUBLE_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_LONG_DOUBLE_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddLongDoubleBool,                    \
  bool*:                 rbTreeAddLongDoubleBoolP,                   \
  const volatile bool*:  rbTreeAddLongDoubleBoolP,                   \
  i16:                   rbTreeAddLongDoubleI16,                     \
  i16*:                  rbTreeAddLongDoubleI16P,                    \
  const volatile i16*:   rbTreeAddLongDoubleI16P,                    \
  u16:                   rbTreeAddLongDoubleU16,                     \
  u16*:                  rbTreeAddLongDoubleU16P,                    \
  const volatile u16*:   rbTreeAddLongDoubleU16P,                    \
  i32:                   rbTreeAddLongDoubleI32,                     \
  i32*:                  rbTreeAddLongDoubleI32P,                    \
  const volatile i32*:   rbTreeAddLongDoubleI32P,                    \
  u32:                   rbTreeAddLongDoubleU32,                     \
  u32*:                  rbTreeAddLongDoubleU32P,                    \
  const volatile u32*:   rbTreeAddLongDoubleU32P,                    \
  i64:                   rbTreeAddLongDoubleI64,                     \
  i64*:                  rbTreeAddLongDoubleI64P,                    \
  const volatile i64*:   rbTreeAddLongDoubleI64P,                    \
  u64:                   rbTreeAddLongDoubleU64,                     \
  u64*:                  rbTreeAddLongDoubleU64P,                    \
  const volatile u64*:   rbTreeAddLongDoubleU64P,                    \
  float:                 rbTreeAddLongDoubleFloat,                   \
  float*:                rbTreeAddLongDoubleFloatP,                  \
  const volatile float*: rbTreeAddLongDoubleFloatP,                  \
  double:                rbTreeAddLongDoubleDouble,                  \
  double*:               rbTreeAddLongDoubleDoubleP,                 \
  const volatile double*: rbTreeAddLongDoubleDoubleP,                 \
  long double:           rbTreeAddLongDoubleLongDouble,              \
  long double*:          rbTreeAddLongDoubleLongDoubleP,             \
  const volatile long double*: rbTreeAddLongDoubleLongDoubleP,             \
  List:                  rbTreeAddLongDoubleList,                    \
  List*:                 rbTreeAddLongDoubleListP,                   \
  const volatile List*:  rbTreeAddLongDoubleListP,                   \
  Queue:                 rbTreeAddLongDoubleQueue,                   \
  Queue*:                rbTreeAddLongDoubleQueueP,                  \
  const volatile Queue*: rbTreeAddLongDoubleQueueP,                  \
  Stack:                 rbTreeAddLongDoubleStack,                   \
  Stack*:                rbTreeAddLongDoubleStackP,                  \
  const volatile Stack*: rbTreeAddLongDoubleStackP,                  \
  RedBlackTree:          rbTreeAddLongDoubleRedBlackTree,            \
  RedBlackTree*:         rbTreeAddLongDoubleRedBlackTreeP,           \
  const volatile RedBlackTree*: rbTreeAddLongDoubleRedBlackTreeP,           \
  HashTable:             rbTreeAddLongDoubleHashTable,               \
  HashTable*:            rbTreeAddLongDoubleHashTableP,              \
  const volatile HashTable*: rbTreeAddLongDoubleHashTableP,              \
  Vector:                rbTreeAddLongDoubleVector,                  \
  Vector*:               rbTreeAddLongDoubleVectorP,                 \
  const volatile Vector*: rbTreeAddLongDoubleVectorP,                 \
  char*:                 rbTreeAddLongDoubleString,                  \
  const volatile char*:  rbTreeAddLongDoubleString,                  \
  char**:                rbTreeAddLongDoubleStringP,                 \
  const volatile char**: rbTreeAddLongDoubleStringP,                 \
  Bytes:                 rbTreeAddLongDoubleBytes,                   \
  Bytes*:                rbTreeAddLongDoubleBytesP,                  \
  const volatile Bytes*: rbTreeAddLongDoubleBytesP,                  \
  void*:                 rbTreeAddLongDoublePointer,                 \
  void**:                rbTreeAddLongDoublePointerP,                \
  const volatile void**: rbTreeAddLongDoublePointerP,                \
  i8:                    rbTreeAddLongDoubleI8,                      \
  u8:                    rbTreeAddLongDoubleU8                       \

#define rbTreeAddLongDouble(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_LONG_DOUBLE_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_LIST_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddListBool,                          \
  bool*:                 rbTreeAddListBoolP,                         \
  const volatile bool*:  rbTreeAddListBoolP,                         \
  i16:                   rbTreeAddListI16,                           \
  i16*:                  rbTreeAddListI16P,                          \
  const volatile i16*:   rbTreeAddListI16P,                          \
  u16:                   rbTreeAddListU16,                           \
  u16*:                  rbTreeAddListU16P,                          \
  const volatile u16*:   rbTreeAddListU16P,                          \
  i32:                   rbTreeAddListI32,                           \
  i32*:                  rbTreeAddListI32P,                          \
  const volatile i32*:   rbTreeAddListI32P,                          \
  u32:                   rbTreeAddListU32,                           \
  u32*:                  rbTreeAddListU32P,                          \
  const volatile u32*:   rbTreeAddListU32P,                          \
  i64:                   rbTreeAddListI64,                           \
  i64*:                  rbTreeAddListI64P,                          \
  const volatile i64*:   rbTreeAddListI64P,                          \
  u64:                   rbTreeAddListU64,                           \
  u64*:                  rbTreeAddListU64P,                          \
  const volatile u64*:   rbTreeAddListU64P,                          \
  float:                 rbTreeAddListFloat,                         \
  float*:                rbTreeAddListFloatP,                        \
  const volatile float*: rbTreeAddListFloatP,                        \
  double:                rbTreeAddListDouble,                        \
  double*:               rbTreeAddListDoubleP,                       \
  const volatile double*: rbTreeAddListDoubleP,                       \
  long double:           rbTreeAddListLongDouble,                    \
  long double*:          rbTreeAddListLongDoubleP,                   \
  const volatile long double*: rbTreeAddListLongDoubleP,                   \
  List:                  rbTreeAddListList,                          \
  List*:                 rbTreeAddListListP,                         \
  const volatile List*:  rbTreeAddListListP,                         \
  Queue:                 rbTreeAddListQueue,                         \
  Queue*:                rbTreeAddListQueueP,                        \
  const volatile Queue*: rbTreeAddListQueueP,                        \
  Stack:                 rbTreeAddListStack,                         \
  Stack*:                rbTreeAddListStackP,                        \
  const volatile Stack*: rbTreeAddListStackP,                        \
  RedBlackTree:          rbTreeAddListRedBlackTree,                  \
  RedBlackTree*:         rbTreeAddListRedBlackTreeP,                 \
  const volatile RedBlackTree*: rbTreeAddListRedBlackTreeP,                 \
  HashTable:             rbTreeAddListHashTable,                     \
  HashTable*:            rbTreeAddListHashTableP,                    \
  const volatile HashTable*: rbTreeAddListHashTableP,                    \
  Vector:                rbTreeAddListVector,                        \
  Vector*:               rbTreeAddListVectorP,                       \
  const volatile Vector*: rbTreeAddListVectorP,                       \
  char*:                 rbTreeAddListString,                        \
  const volatile char*:  rbTreeAddListString,                        \
  char**:                rbTreeAddListStringP,                       \
  const volatile char**: rbTreeAddListStringP,                       \
  Bytes:                 rbTreeAddListBytes,                         \
  Bytes*:                rbTreeAddListBytesP,                        \
  const volatile Bytes*: rbTreeAddListBytesP,                        \
  void*:                 rbTreeAddListPointer,                       \
  void**:                rbTreeAddListPointerP,                      \
  const volatile void**: rbTreeAddListPointerP,                      \
  i8:                    rbTreeAddListI8,                            \
  u8:                    rbTreeAddListU8                             \

#define rbTreeAddList(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_LIST_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_QUEUE_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddQueueBool,                         \
  bool*:                 rbTreeAddQueueBoolP,                        \
  const volatile bool*:  rbTreeAddQueueBoolP,                        \
  i16:                   rbTreeAddQueueI16,                          \
  i16*:                  rbTreeAddQueueI16P,                         \
  const volatile i16*:   rbTreeAddQueueI16P,                         \
  u16:                   rbTreeAddQueueU16,                          \
  u16*:                  rbTreeAddQueueU16P,                         \
  const volatile u16*:   rbTreeAddQueueU16P,                         \
  i32:                   rbTreeAddQueueI32,                          \
  i32*:                  rbTreeAddQueueI32P,                         \
  const volatile i32*:   rbTreeAddQueueI32P,                         \
  u32:                   rbTreeAddQueueU32,                          \
  u32*:                  rbTreeAddQueueU32P,                         \
  const volatile u32*:   rbTreeAddQueueU32P,                         \
  i64:                   rbTreeAddQueueI64,                          \
  i64*:                  rbTreeAddQueueI64P,                         \
  const volatile i64*:   rbTreeAddQueueI64P,                         \
  u64:                   rbTreeAddQueueU64,                          \
  u64*:                  rbTreeAddQueueU64P,                         \
  const volatile u64*:   rbTreeAddQueueU64P,                         \
  float:                 rbTreeAddQueueFloat,                        \
  float*:                rbTreeAddQueueFloatP,                       \
  const volatile float*: rbTreeAddQueueFloatP,                       \
  double:                rbTreeAddQueueDouble,                       \
  double*:               rbTreeAddQueueDoubleP,                      \
  const volatile double*: rbTreeAddQueueDoubleP,                      \
  long double:           rbTreeAddQueueLongDouble,                   \
  long double*:          rbTreeAddQueueLongDoubleP,                  \
  const volatile long double*: rbTreeAddQueueLongDoubleP,                  \
  List:                  rbTreeAddQueueList,                         \
  List*:                 rbTreeAddQueueListP,                        \
  const volatile List*:  rbTreeAddQueueListP,                        \
  Queue:                 rbTreeAddQueueQueue,                        \
  Queue*:                rbTreeAddQueueQueueP,                       \
  const volatile Queue*: rbTreeAddQueueQueueP,                       \
  Stack:                 rbTreeAddQueueStack,                        \
  Stack*:                rbTreeAddQueueStackP,                       \
  const volatile Stack*: rbTreeAddQueueStackP,                       \
  RedBlackTree:          rbTreeAddQueueRedBlackTree,                 \
  RedBlackTree*:         rbTreeAddQueueRedBlackTreeP,                \
  const volatile RedBlackTree*: rbTreeAddQueueRedBlackTreeP,                \
  HashTable:             rbTreeAddQueueHashTable,                    \
  HashTable*:            rbTreeAddQueueHashTableP,                   \
  const volatile HashTable*: rbTreeAddQueueHashTableP,                   \
  Vector:                rbTreeAddQueueVector,                       \
  Vector*:               rbTreeAddQueueVectorP,                      \
  const volatile Vector*: rbTreeAddQueueVectorP,                      \
  char*:                 rbTreeAddQueueString,                       \
  const volatile char*:  rbTreeAddQueueString,                       \
  char**:                rbTreeAddQueueStringP,                      \
  const volatile char**: rbTreeAddQueueStringP,                      \
  Bytes:                 rbTreeAddQueueBytes,                        \
  Bytes*:                rbTreeAddQueueBytesP,                       \
  const volatile Bytes*: rbTreeAddQueueBytesP,                       \
  void*:                 rbTreeAddQueuePointer,                      \
  void**:                rbTreeAddQueuePointerP,                     \
  const volatile void**: rbTreeAddQueuePointerP,                     \
  i8:                    rbTreeAddQueueI8,                           \
  u8:                    rbTreeAddQueueU8                            \

#define rbTreeAddQueue(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_QUEUE_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_STACK_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddStackBool,                         \
  bool*:                 rbTreeAddStackBoolP,                        \
  const volatile bool*:  rbTreeAddStackBoolP,                        \
  i16:                   rbTreeAddStackI16,                          \
  i16*:                  rbTreeAddStackI16P,                         \
  const volatile i16*:   rbTreeAddStackI16P,                         \
  u16:                   rbTreeAddStackU16,                          \
  u16*:                  rbTreeAddStackU16P,                         \
  const volatile u16*:   rbTreeAddStackU16P,                         \
  i32:                   rbTreeAddStackI32,                          \
  i32*:                  rbTreeAddStackI32P,                         \
  const volatile i32*:   rbTreeAddStackI32P,                         \
  u32:                   rbTreeAddStackU32,                          \
  u32*:                  rbTreeAddStackU32P,                         \
  const volatile u32*:   rbTreeAddStackU32P,                         \
  i64:                   rbTreeAddStackI64,                          \
  i64*:                  rbTreeAddStackI64P,                         \
  const volatile i64*:   rbTreeAddStackI64P,                         \
  u64:                   rbTreeAddStackU64,                          \
  u64*:                  rbTreeAddStackU64P,                         \
  const volatile u64*:   rbTreeAddStackU64P,                         \
  float:                 rbTreeAddStackFloat,                        \
  float*:                rbTreeAddStackFloatP,                       \
  const volatile float*: rbTreeAddStackFloatP,                       \
  double:                rbTreeAddStackDouble,                       \
  double*:               rbTreeAddStackDoubleP,                      \
  const volatile double*: rbTreeAddStackDoubleP,                      \
  long double:           rbTreeAddStackLongDouble,                   \
  long double*:          rbTreeAddStackLongDoubleP,                  \
  const volatile long double*: rbTreeAddStackLongDoubleP,                  \
  List:                  rbTreeAddStackList,                         \
  List*:                 rbTreeAddStackListP,                        \
  const volatile List*:  rbTreeAddStackListP,                        \
  Queue:                 rbTreeAddStackQueue,                        \
  Queue*:                rbTreeAddStackQueueP,                       \
  const volatile Queue*: rbTreeAddStackQueueP,                       \
  Stack:                 rbTreeAddStackStack,                        \
  Stack*:                rbTreeAddStackStackP,                       \
  const volatile Stack*: rbTreeAddStackStackP,                       \
  RedBlackTree:          rbTreeAddStackRedBlackTree,                 \
  RedBlackTree*:         rbTreeAddStackRedBlackTreeP,                \
  const volatile RedBlackTree*: rbTreeAddStackRedBlackTreeP,                \
  HashTable:             rbTreeAddStackHashTable,                    \
  HashTable*:            rbTreeAddStackHashTableP,                   \
  const volatile HashTable*: rbTreeAddStackHashTableP,                   \
  Vector:                rbTreeAddStackVector,                       \
  Vector*:               rbTreeAddStackVectorP,                      \
  const volatile Vector*: rbTreeAddStackVectorP,                      \
  char*:                 rbTreeAddStackString,                       \
  const volatile char*:  rbTreeAddStackString,                       \
  char**:                rbTreeAddStackStringP,                      \
  const volatile char**: rbTreeAddStackStringP,                      \
  Bytes:                 rbTreeAddStackBytes,                        \
  Bytes*:                rbTreeAddStackBytesP,                       \
  const volatile Bytes*: rbTreeAddStackBytesP,                       \
  void*:                 rbTreeAddStackPointer,                      \
  void**:                rbTreeAddStackPointerP,                     \
  const volatile void**: rbTreeAddStackPointerP,                     \
  i8:                    rbTreeAddStackI8,                           \
  u8:                    rbTreeAddStackU8                            \

#define rbTreeAddStack(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_STACK_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_RED_BLACK_TREE_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddRedBlackTreeBool,                  \
  bool*:                 rbTreeAddRedBlackTreeBoolP,                 \
  const volatile bool*:  rbTreeAddRedBlackTreeBoolP,                 \
  i16:                   rbTreeAddRedBlackTreeI16,                   \
  i16*:                  rbTreeAddRedBlackTreeI16P,                  \
  const volatile i16*:   rbTreeAddRedBlackTreeI16P,                  \
  u16:                   rbTreeAddRedBlackTreeU16,                   \
  u16*:                  rbTreeAddRedBlackTreeU16P,                  \
  const volatile u16*:   rbTreeAddRedBlackTreeU16P,                  \
  i32:                   rbTreeAddRedBlackTreeI32,                   \
  i32*:                  rbTreeAddRedBlackTreeI32P,                  \
  const volatile i32*:   rbTreeAddRedBlackTreeI32P,                  \
  u32:                   rbTreeAddRedBlackTreeU32,                   \
  u32*:                  rbTreeAddRedBlackTreeU32P,                  \
  const volatile u32*:   rbTreeAddRedBlackTreeU32P,                  \
  i64:                   rbTreeAddRedBlackTreeI64,                   \
  i64*:                  rbTreeAddRedBlackTreeI64P,                  \
  const volatile i64*:   rbTreeAddRedBlackTreeI64P,                  \
  u64:                   rbTreeAddRedBlackTreeU64,                   \
  u64*:                  rbTreeAddRedBlackTreeU64P,                  \
  const volatile u64*:   rbTreeAddRedBlackTreeU64P,                  \
  float:                 rbTreeAddRedBlackTreeFloat,                 \
  float*:                rbTreeAddRedBlackTreeFloatP,                \
  const volatile float*: rbTreeAddRedBlackTreeFloatP,                \
  double:                rbTreeAddRedBlackTreeDouble,                \
  double*:               rbTreeAddRedBlackTreeDoubleP,               \
  const volatile double*: rbTreeAddRedBlackTreeDoubleP,               \
  long double:           rbTreeAddRedBlackTreeLongDouble,            \
  long double*:          rbTreeAddRedBlackTreeLongDoubleP,           \
  const volatile long double*: rbTreeAddRedBlackTreeLongDoubleP,           \
  List:                  rbTreeAddRedBlackTreeList,                  \
  List*:                 rbTreeAddRedBlackTreeListP,                 \
  const volatile List*:  rbTreeAddRedBlackTreeListP,                 \
  Queue:                 rbTreeAddRedBlackTreeQueue,                 \
  Queue*:                rbTreeAddRedBlackTreeQueueP,                \
  const volatile Queue*: rbTreeAddRedBlackTreeQueueP,                \
  Stack:                 rbTreeAddRedBlackTreeStack,                 \
  Stack*:                rbTreeAddRedBlackTreeStackP,                \
  const volatile Stack*: rbTreeAddRedBlackTreeStackP,                \
  RedBlackTree:          rbTreeAddRedBlackTreeRedBlackTree,          \
  RedBlackTree*:         rbTreeAddRedBlackTreeRedBlackTreeP,         \
  const volatile RedBlackTree*: rbTreeAddRedBlackTreeRedBlackTreeP,         \
  HashTable:             rbTreeAddRedBlackTreeHashTable,             \
  HashTable*:            rbTreeAddRedBlackTreeHashTableP,            \
  const volatile HashTable*: rbTreeAddRedBlackTreeHashTableP,            \
  Vector:                rbTreeAddRedBlackTreeVector,                \
  Vector*:               rbTreeAddRedBlackTreeVectorP,               \
  const volatile Vector*: rbTreeAddRedBlackTreeVectorP,               \
  char*:                 rbTreeAddRedBlackTreeString,                \
  const volatile char*:  rbTreeAddRedBlackTreeString,                \
  char**:                rbTreeAddRedBlackTreeStringP,               \
  const volatile char**: rbTreeAddRedBlackTreeStringP,               \
  Bytes:                 rbTreeAddRedBlackTreeBytes,                 \
  Bytes*:                rbTreeAddRedBlackTreeBytesP,                \
  const volatile Bytes*: rbTreeAddRedBlackTreeBytesP,                \
  void*:                 rbTreeAddRedBlackTreePointer,               \
  void**:                rbTreeAddRedBlackTreePointerP,              \
  const volatile void**: rbTreeAddRedBlackTreePointerP,              \
  i8:                    rbTreeAddRedBlackTreeI8,                    \
  u8:                    rbTreeAddRedBlackTreeU8                     \

#define rbTreeAddRedBlackTree(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_RED_BLACK_TREE_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_HASH_TABLE_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddHashTableBool,                     \
  bool*:                 rbTreeAddHashTableBoolP,                    \
  const volatile bool*:  rbTreeAddHashTableBoolP,                    \
  i16:                   rbTreeAddHashTableI16,                      \
  i16*:                  rbTreeAddHashTableI16P,                     \
  const volatile i16*:   rbTreeAddHashTableI16P,                     \
  u16:                   rbTreeAddHashTableU16,                      \
  u16*:                  rbTreeAddHashTableU16P,                     \
  const volatile u16*:   rbTreeAddHashTableU16P,                     \
  i32:                   rbTreeAddHashTableI32,                      \
  i32*:                  rbTreeAddHashTableI32P,                     \
  const volatile i32*:   rbTreeAddHashTableI32P,                     \
  u32:                   rbTreeAddHashTableU32,                      \
  u32*:                  rbTreeAddHashTableU32P,                     \
  const volatile u32*:   rbTreeAddHashTableU32P,                     \
  i64:                   rbTreeAddHashTableI64,                      \
  i64*:                  rbTreeAddHashTableI64P,                     \
  const volatile i64*:   rbTreeAddHashTableI64P,                     \
  u64:                   rbTreeAddHashTableU64,                      \
  u64*:                  rbTreeAddHashTableU64P,                     \
  const volatile u64*:   rbTreeAddHashTableU64P,                     \
  float:                 rbTreeAddHashTableFloat,                    \
  float*:                rbTreeAddHashTableFloatP,                   \
  const volatile float*: rbTreeAddHashTableFloatP,                   \
  double:                rbTreeAddHashTableDouble,                   \
  double*:               rbTreeAddHashTableDoubleP,                  \
  const volatile double*: rbTreeAddHashTableDoubleP,                  \
  long double:           rbTreeAddHashTableLongDouble,               \
  long double*:          rbTreeAddHashTableLongDoubleP,              \
  const volatile long double*: rbTreeAddHashTableLongDoubleP,              \
  List:                  rbTreeAddHashTableList,                     \
  List*:                 rbTreeAddHashTableListP,                    \
  const volatile List*:  rbTreeAddHashTableListP,                    \
  Queue:                 rbTreeAddHashTableQueue,                    \
  Queue*:                rbTreeAddHashTableQueueP,                   \
  const volatile Queue*: rbTreeAddHashTableQueueP,                   \
  Stack:                 rbTreeAddHashTableStack,                    \
  Stack*:                rbTreeAddHashTableStackP,                   \
  const volatile Stack*: rbTreeAddHashTableStackP,                   \
  RedBlackTree:          rbTreeAddHashTableRedBlackTree,             \
  RedBlackTree*:         rbTreeAddHashTableRedBlackTreeP,            \
  const volatile RedBlackTree*: rbTreeAddHashTableRedBlackTreeP,            \
  HashTable:             rbTreeAddHashTableHashTable,                \
  HashTable*:            rbTreeAddHashTableHashTableP,               \
  const volatile HashTable*: rbTreeAddHashTableHashTableP,               \
  Vector:                rbTreeAddHashTableVector,                   \
  Vector*:               rbTreeAddHashTableVectorP,                  \
  const volatile Vector*: rbTreeAddHashTableVectorP,                  \
  char*:                 rbTreeAddHashTableString,                   \
  const volatile char*:  rbTreeAddHashTableString,                   \
  char**:                rbTreeAddHashTableStringP,                  \
  const volatile char**: rbTreeAddHashTableStringP,                  \
  Bytes:                 rbTreeAddHashTableBytes,                    \
  Bytes*:                rbTreeAddHashTableBytesP,                   \
  const volatile Bytes*: rbTreeAddHashTableBytesP,                   \
  void*:                 rbTreeAddHashTablePointer,                  \
  void**:                rbTreeAddHashTablePointerP,                 \
  const volatile void**: rbTreeAddHashTablePointerP,                 \
  i8:                    rbTreeAddHashTableI8,                       \
  u8:                    rbTreeAddHashTableU8                        \

#define rbTreeAddHashTable(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_HASH_TABLE_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_VECTOR_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddVectorBool,                        \
  bool*:                 rbTreeAddVectorBoolP,                       \
  const volatile bool*:  rbTreeAddVectorBoolP,                       \
  i16:                   rbTreeAddVectorI16,                         \
  i16*:                  rbTreeAddVectorI16P,                        \
  const volatile i16*:   rbTreeAddVectorI16P,                        \
  u16:                   rbTreeAddVectorU16,                         \
  u16*:                  rbTreeAddVectorU16P,                        \
  const volatile u16*:   rbTreeAddVectorU16P,                        \
  i32:                   rbTreeAddVectorI32,                         \
  i32*:                  rbTreeAddVectorI32P,                        \
  const volatile i32*:   rbTreeAddVectorI32P,                        \
  u32:                   rbTreeAddVectorU32,                         \
  u32*:                  rbTreeAddVectorU32P,                        \
  const volatile u32*:   rbTreeAddVectorU32P,                        \
  i64:                   rbTreeAddVectorI64,                         \
  i64*:                  rbTreeAddVectorI64P,                        \
  const volatile i64*:   rbTreeAddVectorI64P,                        \
  u64:                   rbTreeAddVectorU64,                         \
  u64*:                  rbTreeAddVectorU64P,                        \
  const volatile u64*:   rbTreeAddVectorU64P,                        \
  float:                 rbTreeAddVectorFloat,                       \
  float*:                rbTreeAddVectorFloatP,                      \
  const volatile float*: rbTreeAddVectorFloatP,                      \
  double:                rbTreeAddVectorDouble,                      \
  double*:               rbTreeAddVectorDoubleP,                     \
  const volatile double*: rbTreeAddVectorDoubleP,                     \
  long double:           rbTreeAddVectorLongDouble,                  \
  long double*:          rbTreeAddVectorLongDoubleP,                 \
  const volatile long double*: rbTreeAddVectorLongDoubleP,                 \
  List:                  rbTreeAddVectorList,                        \
  List*:                 rbTreeAddVectorListP,                       \
  const volatile List*:  rbTreeAddVectorListP,                       \
  Queue:                 rbTreeAddVectorQueue,                       \
  Queue*:                rbTreeAddVectorQueueP,                      \
  const volatile Queue*: rbTreeAddVectorQueueP,                      \
  Stack:                 rbTreeAddVectorStack,                       \
  Stack*:                rbTreeAddVectorStackP,                      \
  const volatile Stack*: rbTreeAddVectorStackP,                      \
  RedBlackTree:          rbTreeAddVectorRedBlackTree,                \
  RedBlackTree*:         rbTreeAddVectorRedBlackTreeP,               \
  const volatile RedBlackTree*: rbTreeAddVectorRedBlackTreeP,               \
  HashTable:             rbTreeAddVectorHashTable,                   \
  HashTable*:            rbTreeAddVectorHashTableP,                  \
  const volatile HashTable*: rbTreeAddVectorHashTableP,                  \
  Vector:                rbTreeAddVectorVector,                      \
  Vector*:               rbTreeAddVectorVectorP,                     \
  const volatile Vector*: rbTreeAddVectorVectorP,                     \
  char*:                 rbTreeAddVectorString,                      \
  const volatile char*:  rbTreeAddVectorString,                      \
  char**:                rbTreeAddVectorStringP,                     \
  const volatile char**: rbTreeAddVectorStringP,                     \
  Bytes:                 rbTreeAddVectorBytes,                       \
  Bytes*:                rbTreeAddVectorBytesP,                      \
  const volatile Bytes*: rbTreeAddVectorBytesP,                      \
  void*:                 rbTreeAddVectorPointer,                     \
  void**:                rbTreeAddVectorPointerP,                    \
  const volatile void**: rbTreeAddVectorPointerP,                    \
  i8:                    rbTreeAddVectorI8,                          \
  u8:                    rbTreeAddVectorU8                           \

#define rbTreeAddVector(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_VECTOR_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_STRING_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddStringBool,                        \
  const volatile bool:   rbTreeAddStringBool,                        \
  bool*:                 rbTreeAddStringBoolP,                       \
  const volatile bool*:  rbTreeAddStringBoolP,                       \
  i16:                   rbTreeAddStringI16,                         \
  const volatile i16:    rbTreeAddStringI16,                         \
  i16*:                  rbTreeAddStringI16P,                        \
  const volatile i16*:   rbTreeAddStringI16P,                        \
  u16:                   rbTreeAddStringU16,                         \
  const volatile u16:    rbTreeAddStringU16,                         \
  u16*:                  rbTreeAddStringU16P,                        \
  const volatile u16*:   rbTreeAddStringU16P,                        \
  i32:                   rbTreeAddStringI32,                         \
  const volatile i32:    rbTreeAddStringI32,                         \
  i32*:                  rbTreeAddStringI32P,                        \
  const volatile i32*:   rbTreeAddStringI32P,                        \
  u32:                   rbTreeAddStringU32,                         \
  const volatile u32:    rbTreeAddStringU32,                         \
  u32*:                  rbTreeAddStringU32P,                        \
  const volatile u32*:   rbTreeAddStringU32P,                        \
  i64:                   rbTreeAddStringI64,                         \
  const volatile i64:    rbTreeAddStringI64,                         \
  i64*:                  rbTreeAddStringI64P,                        \
  const volatile i64*:   rbTreeAddStringI64P,                        \
  u64:                   rbTreeAddStringU64,                         \
  const volatile u64:    rbTreeAddStringU64,                         \
  u64*:                  rbTreeAddStringU64P,                        \
  const volatile u64*:   rbTreeAddStringU64P,                        \
  float:                 rbTreeAddStringFloat,                       \
  const volatile float:  rbTreeAddStringFloat,                       \
  float*:                rbTreeAddStringFloatP,                      \
  const volatile float*: rbTreeAddStringFloatP,                      \
  double:                rbTreeAddStringDouble,                      \
  const volatile double: rbTreeAddStringDouble,                      \
  double*:               rbTreeAddStringDoubleP,                     \
  const volatile double*: rbTreeAddStringDoubleP,                     \
  long double:           rbTreeAddStringLongDouble,                  \
  const volatile long double: rbTreeAddStringLongDouble,                  \
  long double*:          rbTreeAddStringLongDoubleP,                 \
  const volatile long double*: rbTreeAddStringLongDoubleP,                 \
  List:                  rbTreeAddStringList,                        \
  const volatile List:   rbTreeAddStringList,                        \
  List*:                 rbTreeAddStringListP,                       \
  const volatile List*:  rbTreeAddStringListP,                       \
  Queue:                 rbTreeAddStringQueue,                       \
  const volatile Queue:  rbTreeAddStringQueue,                       \
  Queue*:                rbTreeAddStringQueueP,                      \
  const volatile Queue*: rbTreeAddStringQueueP,                      \
  Stack:                 rbTreeAddStringStack,                       \
  const volatile Stack:  rbTreeAddStringStack,                       \
  Stack*:                rbTreeAddStringStackP,                      \
  const volatile Stack*: rbTreeAddStringStackP,                      \
  RedBlackTree:          rbTreeAddStringRedBlackTree,                \
  const volatile RedBlackTree: rbTreeAddStringRedBlackTree,                \
  RedBlackTree*:         rbTreeAddStringRedBlackTreeP,               \
  const volatile RedBlackTree*: rbTreeAddStringRedBlackTreeP,               \
  HashTable:             rbTreeAddStringHashTable,                   \
  const volatile HashTable: rbTreeAddStringHashTable,                   \
  HashTable*:            rbTreeAddStringHashTableP,                  \
  const volatile HashTable*: rbTreeAddStringHashTableP,                  \
  Vector:                rbTreeAddStringVector,                      \
  const volatile Vector: rbTreeAddStringVector,                      \
  Vector*:               rbTreeAddStringVectorP,                     \
  const volatile Vector*: rbTreeAddStringVectorP,                     \
  char*:                 rbTreeAddStringString,                      \
  const volatile char*:  rbTreeAddStringString,                      \
  char**:                rbTreeAddStringStringP,                     \
  const volatile char**: rbTreeAddStringStringP,                     \
  Bytes:                 rbTreeAddStringBytes,                       \
  Bytes*:                rbTreeAddStringBytesP,                      \
  const volatile Bytes*: rbTreeAddStringBytesP,                      \
  void*:                 rbTreeAddStringPointer,                     \
  void**:                rbTreeAddStringPointerP,                    \
  const volatile void**: rbTreeAddStringPointerP,                    \
  i8:                    rbTreeAddStringI8,                          \
  u8:                    rbTreeAddStringU8                           \

#define rbTreeAddString(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_STRING_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_BYTES_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddBytesBool,                         \
  bool*:                 rbTreeAddBytesBoolP,                        \
  const volatile bool*:  rbTreeAddBytesBoolP,                        \
  i16:                   rbTreeAddBytesI16,                          \
  i16*:                  rbTreeAddBytesI16P,                         \
  const volatile i16*:   rbTreeAddBytesI16P,                         \
  u16:                   rbTreeAddBytesU16,                          \
  u16*:                  rbTreeAddBytesU16P,                         \
  const volatile u16*:   rbTreeAddBytesU16P,                         \
  i32:                   rbTreeAddBytesI32,                          \
  i32*:                  rbTreeAddBytesI32P,                         \
  const volatile i32*:   rbTreeAddBytesI32P,                         \
  u32:                   rbTreeAddBytesU32,                          \
  u32*:                  rbTreeAddBytesU32P,                         \
  const volatile u32*:   rbTreeAddBytesU32P,                         \
  i64:                   rbTreeAddBytesI64,                          \
  i64*:                  rbTreeAddBytesI64P,                         \
  const volatile i64*:   rbTreeAddBytesI64P,                         \
  u64:                   rbTreeAddBytesU64,                          \
  u64*:                  rbTreeAddBytesU64P,                         \
  const volatile u64*:   rbTreeAddBytesU64P,                         \
  float:                 rbTreeAddBytesFloat,                        \
  float*:                rbTreeAddBytesFloatP,                       \
  const volatile float*: rbTreeAddBytesFloatP,                       \
  double:                rbTreeAddBytesDouble,                       \
  double*:               rbTreeAddBytesDoubleP,                      \
  const volatile double*: rbTreeAddBytesDoubleP,                      \
  long double:           rbTreeAddBytesLongDouble,                   \
  long double*:          rbTreeAddBytesLongDoubleP,                  \
  const volatile long double*: rbTreeAddBytesLongDoubleP,                  \
  List:                  rbTreeAddBytesList,                         \
  List*:                 rbTreeAddBytesListP,                        \
  const volatile List*:  rbTreeAddBytesListP,                        \
  Queue:                 rbTreeAddBytesQueue,                        \
  Queue*:                rbTreeAddBytesQueueP,                       \
  const volatile Queue*: rbTreeAddBytesQueueP,                       \
  Stack:                 rbTreeAddBytesStack,                        \
  Stack*:                rbTreeAddBytesStackP,                       \
  const volatile Stack*: rbTreeAddBytesStackP,                       \
  RedBlackTree:          rbTreeAddBytesRedBlackTree,                 \
  RedBlackTree*:         rbTreeAddBytesRedBlackTreeP,                \
  const volatile RedBlackTree*: rbTreeAddBytesRedBlackTreeP,                \
  HashTable:             rbTreeAddBytesHashTable,                    \
  HashTable*:            rbTreeAddBytesHashTableP,                   \
  const volatile HashTable*: rbTreeAddBytesHashTableP,                   \
  Vector:                rbTreeAddBytesVector,                       \
  Vector*:               rbTreeAddBytesVectorP,                      \
  const volatile Vector*: rbTreeAddBytesVectorP,                      \
  char*:                 rbTreeAddBytesString,                       \
  const volatile char*:  rbTreeAddBytesString,                       \
  char**:                rbTreeAddBytesStringP,                      \
  const volatile char**: rbTreeAddBytesStringP,                      \
  Bytes:                 rbTreeAddBytesBytes,                        \
  Bytes*:                rbTreeAddBytesBytesP,                       \
  const volatile Bytes*: rbTreeAddBytesBytesP,                       \
  void*:                 rbTreeAddBytesPointer,                      \
  void**:                rbTreeAddBytesPointerP,                     \
  const volatile void**: rbTreeAddBytesPointerP,                     \
  i8:                    rbTreeAddBytesI8,                           \
  u8:                    rbTreeAddBytesU8                            \

#define rbTreeAddBytes(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_BYTES_KEY(dataStructure, key, value) \
  )


#define RB_TREE_ADD_GENERIC_CASES_POINTER_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddPointerBool,                       \
  bool*:                 rbTreeAddPointerBoolP,                      \
  const volatile bool*:  rbTreeAddPointerBoolP,                      \
  i16:                   rbTreeAddPointerI16,                        \
  i16*:                  rbTreeAddPointerI16P,                       \
  const volatile i16*:   rbTreeAddPointerI16P,                       \
  u16:                   rbTreeAddPointerU16,                        \
  u16*:                  rbTreeAddPointerU16P,                       \
  const volatile u16*:   rbTreeAddPointerU16P,                       \
  i32:                   rbTreeAddPointerI32,                        \
  i32*:                  rbTreeAddPointerI32P,                       \
  const volatile i32*:   rbTreeAddPointerI32P,                       \
  u32:                   rbTreeAddPointerU32,                        \
  u32*:                  rbTreeAddPointerU32P,                       \
  const volatile u32*:   rbTreeAddPointerU32P,                       \
  i64:                   rbTreeAddPointerI64,                        \
  i64*:                  rbTreeAddPointerI64P,                       \
  const volatile i64*:   rbTreeAddPointerI64P,                       \
  u64:                   rbTreeAddPointerU64,                        \
  u64*:                  rbTreeAddPointerU64P,                       \
  const volatile u64*:   rbTreeAddPointerU64P,                       \
  float:                 rbTreeAddPointerFloat,                      \
  float*:                rbTreeAddPointerFloatP,                     \
  const volatile float*: rbTreeAddPointerFloatP,                     \
  double:                rbTreeAddPointerDouble,                     \
  double*:               rbTreeAddPointerDoubleP,                    \
  const volatile double*: rbTreeAddPointerDoubleP,                    \
  long double:           rbTreeAddPointerLongDouble,                 \
  long double*:          rbTreeAddPointerLongDoubleP,                \
  const volatile long double*: rbTreeAddPointerLongDoubleP,                \
  List:                  rbTreeAddPointerList,                       \
  List*:                 rbTreeAddPointerListP,                      \
  const volatile List*:  rbTreeAddPointerListP,                      \
  Queue:                 rbTreeAddPointerQueue,                      \
  Queue*:                rbTreeAddPointerQueueP,                     \
  const volatile Queue*: rbTreeAddPointerQueueP,                     \
  Stack:                 rbTreeAddPointerStack,                      \
  Stack*:                rbTreeAddPointerStackP,                     \
  const volatile Stack*: rbTreeAddPointerStackP,                     \
  RedBlackTree:          rbTreeAddPointerRedBlackTree,               \
  RedBlackTree*:         rbTreeAddPointerRedBlackTreeP,              \
  const volatile RedBlackTree*: rbTreeAddPointerRedBlackTreeP,              \
  HashTable:             rbTreeAddPointerHashTable,                  \
  HashTable*:            rbTreeAddPointerHashTableP,                 \
  const volatile HashTable*: rbTreeAddPointerHashTableP,                 \
  Vector:                rbTreeAddPointerVector,                     \
  Vector*:               rbTreeAddPointerVectorP,                    \
  const volatile Vector*: rbTreeAddPointerVectorP,                    \
  char*:                 rbTreeAddPointerString,                     \
  const volatile char*:  rbTreeAddPointerString,                     \
  char**:                rbTreeAddPointerStringP,                    \
  const volatile char**: rbTreeAddPointerStringP,                    \
  Bytes:                 rbTreeAddPointerBytes,                      \
  Bytes*:                rbTreeAddPointerBytesP,                     \
  const volatile Bytes*: rbTreeAddPointerBytesP,                     \
  void*:                 rbTreeAddPointerPointer,                    \
  void**:                rbTreeAddPointerPointerP,                   \
  const volatile void**: rbTreeAddPointerPointerP,                   \
  i8:                    rbTreeAddPointerI8,                         \
  u8:                    rbTreeAddPointerU8                          \

#define rbTreeAddPointer(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_POINTER_KEY(dataStructure, key, value) \
  )


#define RB_TREE_ADD_GENERIC_CASES_I8_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddI8Bool,                            \
  bool*:                 rbTreeAddI8BoolP,                           \
  const volatile bool*:  rbTreeAddI8BoolP,                           \
  i16:                   rbTreeAddI8I16,                             \
  i16*:                  rbTreeAddI8I16P,                            \
  const volatile i16*:   rbTreeAddI8I16P,                            \
  u16:                   rbTreeAddI8U16,                             \
  u16*:                  rbTreeAddI8U16P,                            \
  const volatile u16*:   rbTreeAddI8U16P,                            \
  i32:                   rbTreeAddI8I32,                             \
  i32*:                  rbTreeAddI8I32P,                            \
  const volatile i32*:   rbTreeAddI8I32P,                            \
  u32:                   rbTreeAddI8U32,                             \
  u32*:                  rbTreeAddI8U32P,                            \
  const volatile u32*:   rbTreeAddI8U32P,                            \
  i64:                   rbTreeAddI8I64,                             \
  i64*:                  rbTreeAddI8I64P,                            \
  const volatile i64*:   rbTreeAddI8I64P,                            \
  u64:                   rbTreeAddI8U64,                             \
  u64*:                  rbTreeAddI8U64P,                            \
  const volatile u64*:   rbTreeAddI8U64P,                            \
  float:                 rbTreeAddI8Float,                           \
  float*:                rbTreeAddI8FloatP,                          \
  const volatile float*: rbTreeAddI8FloatP,                          \
  double:                rbTreeAddI8Double,                          \
  double*:               rbTreeAddI8DoubleP,                         \
  const volatile double*: rbTreeAddI8DoubleP,                         \
  long double:           rbTreeAddI8LongDouble,                      \
  long double*:          rbTreeAddI8LongDoubleP,                     \
  const volatile long double*: rbTreeAddI8LongDoubleP,                     \
  List:                  rbTreeAddI8List,                            \
  List*:                 rbTreeAddI8ListP,                           \
  const volatile List*:  rbTreeAddI8ListP,                           \
  Queue:                 rbTreeAddI8Queue,                           \
  Queue*:                rbTreeAddI8QueueP,                          \
  const volatile Queue*: rbTreeAddI8QueueP,                          \
  Stack:                 rbTreeAddI8Stack,                           \
  Stack*:                rbTreeAddI8StackP,                          \
  const volatile Stack*: rbTreeAddI8StackP,                          \
  RedBlackTree:          rbTreeAddI8RedBlackTree,                    \
  RedBlackTree*:         rbTreeAddI8RedBlackTreeP,                   \
  const volatile RedBlackTree*: rbTreeAddI8RedBlackTreeP,                   \
  HashTable:             rbTreeAddI8HashTable,                       \
  HashTable*:            rbTreeAddI8HashTableP,                      \
  const volatile HashTable*: rbTreeAddI8HashTableP,                      \
  Vector:                rbTreeAddI8Vector,                          \
  Vector*:               rbTreeAddI8VectorP,                         \
  const volatile Vector*: rbTreeAddI8VectorP,                         \
  char*:                 rbTreeAddI8String,                          \
  const volatile char*:  rbTreeAddI8String,                          \
  char**:                rbTreeAddI8StringP,                         \
  const volatile char**: rbTreeAddI8StringP,                         \
  Bytes:                 rbTreeAddI8Bytes,                           \
  Bytes*:                rbTreeAddI8BytesP,                          \
  const volatile Bytes*: rbTreeAddI8BytesP,                          \
  void*:                 rbTreeAddI8Pointer,                         \
  void**:                rbTreeAddI8PointerP,                        \
  const volatile void**: rbTreeAddI8PointerP,                        \
  i8:                    rbTreeAddI8I8,                              \
  u8:                    rbTreeAddI8U8                               \

#define rbTreeAddI8(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_I8_KEY(dataStructure, key, value) \
  )


#define RB_TREE_ADD_GENERIC_CASES_U8_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddU8Bool,                            \
  bool*:                 rbTreeAddU8BoolP,                           \
  const volatile bool*:  rbTreeAddU8BoolP,                           \
  i16:                   rbTreeAddU8I16,                             \
  i16*:                  rbTreeAddU8I16P,                            \
  const volatile i16*:   rbTreeAddU8I16P,                            \
  u16:                   rbTreeAddU8U16,                             \
  u16*:                  rbTreeAddU8U16P,                            \
  const volatile u16*:   rbTreeAddU8U16P,                            \
  i32:                   rbTreeAddU8I32,                             \
  i32*:                  rbTreeAddU8I32P,                            \
  const volatile i32*:   rbTreeAddU8I32P,                            \
  u32:                   rbTreeAddU8U32,                             \
  u32*:                  rbTreeAddU8U32P,                            \
  const volatile u32*:   rbTreeAddU8U32P,                            \
  i64:                   rbTreeAddU8I64,                             \
  i64*:                  rbTreeAddU8I64P,                            \
  const volatile i64*:   rbTreeAddU8I64P,                            \
  u64:                   rbTreeAddU8U64,                             \
  u64*:                  rbTreeAddU8U64P,                            \
  const volatile u64*:   rbTreeAddU8U64P,                            \
  float:                 rbTreeAddU8Float,                           \
  float*:                rbTreeAddU8FloatP,                          \
  const volatile float*: rbTreeAddU8FloatP,                          \
  double:                rbTreeAddU8Double,                          \
  double*:               rbTreeAddU8DoubleP,                         \
  const volatile double*: rbTreeAddU8DoubleP,                         \
  long double:           rbTreeAddU8LongDouble,                      \
  long double*:          rbTreeAddU8LongDoubleP,                     \
  const volatile long double*: rbTreeAddU8LongDoubleP,                     \
  List:                  rbTreeAddU8List,                            \
  List*:                 rbTreeAddU8ListP,                           \
  const volatile List*:  rbTreeAddU8ListP,                           \
  Queue:                 rbTreeAddU8Queue,                           \
  Queue*:                rbTreeAddU8QueueP,                          \
  const volatile Queue*: rbTreeAddU8QueueP,                          \
  Stack:                 rbTreeAddU8Stack,                           \
  Stack*:                rbTreeAddU8StackP,                          \
  const volatile Stack*: rbTreeAddU8StackP,                          \
  RedBlackTree:          rbTreeAddU8RedBlackTree,                    \
  RedBlackTree*:         rbTreeAddU8RedBlackTreeP,                   \
  const volatile RedBlackTree*: rbTreeAddU8RedBlackTreeP,                   \
  HashTable:             rbTreeAddU8HashTable,                       \
  HashTable*:            rbTreeAddU8HashTableP,                      \
  const volatile HashTable*: rbTreeAddU8HashTableP,                      \
  Vector:                rbTreeAddU8Vector,                          \
  Vector*:               rbTreeAddU8VectorP,                         \
  const volatile Vector*: rbTreeAddU8VectorP,                         \
  char*:                 rbTreeAddU8String,                          \
  const volatile char*:  rbTreeAddU8String,                          \
  char**:                rbTreeAddU8StringP,                         \
  const volatile char**: rbTreeAddU8StringP,                         \
  Bytes:                 rbTreeAddU8Bytes,                           \
  Bytes*:                rbTreeAddU8BytesP,                          \
  const volatile Bytes*: rbTreeAddU8BytesP,                          \
  void*:                 rbTreeAddU8Pointer,                         \
  void**:                rbTreeAddU8PointerP,                        \
  const volatile void**: rbTreeAddU8PointerP,                        \
  i8:                    rbTreeAddU8I8,                              \
  u8:                    rbTreeAddU8U8                               \

#define rbTreeAddU8(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_U8_KEY(dataStructure, key, value) \
  )


#define RB_TREE_ADD_GENERIC_CASES_BOOLP_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddBoolPBool,                         \
  bool*:                 rbTreeAddBoolPBoolP,                        \
  const volatile bool*:  rbTreeAddBoolPBoolP,                        \
  i16:                   rbTreeAddBoolPI16,                          \
  i16*:                  rbTreeAddBoolPI16P,                         \
  const volatile i16*:   rbTreeAddBoolPI16P,                         \
  u16:                   rbTreeAddBoolPU16,                          \
  u16*:                  rbTreeAddBoolPU16P,                         \
  const volatile u16*:   rbTreeAddBoolPU16P,                         \
  i32:                   rbTreeAddBoolPI32,                          \
  i32*:                  rbTreeAddBoolPI32P,                         \
  const volatile i32*:   rbTreeAddBoolPI32P,                         \
  u32:                   rbTreeAddBoolPU32,                          \
  u32*:                  rbTreeAddBoolPU32P,                         \
  const volatile u32*:   rbTreeAddBoolPU32P,                         \
  i64:                   rbTreeAddBoolPI64,                          \
  i64*:                  rbTreeAddBoolPI64P,                         \
  const volatile i64*:   rbTreeAddBoolPI64P,                         \
  u64:                   rbTreeAddBoolPU64,                          \
  u64*:                  rbTreeAddBoolPU64P,                         \
  const volatile u64*:   rbTreeAddBoolPU64P,                         \
  float:                 rbTreeAddBoolPFloat,                        \
  float*:                rbTreeAddBoolPFloatP,                       \
  const volatile float*: rbTreeAddBoolPFloatP,                       \
  double:                rbTreeAddBoolPDouble,                       \
  double*:               rbTreeAddBoolPDoubleP,                      \
  const volatile double*: rbTreeAddBoolPDoubleP,                      \
  long double:           rbTreeAddBoolPLongDouble,                   \
  long double*:          rbTreeAddBoolPLongDoubleP,                  \
  const volatile long double*: rbTreeAddBoolPLongDoubleP,                  \
  List:                  rbTreeAddBoolPList,                         \
  List*:                 rbTreeAddBoolPListP,                        \
  const volatile List*:  rbTreeAddBoolPListP,                        \
  Queue:                 rbTreeAddBoolPQueue,                        \
  Queue*:                rbTreeAddBoolPQueueP,                       \
  const volatile Queue*: rbTreeAddBoolPQueueP,                       \
  Stack:                 rbTreeAddBoolPStack,                        \
  Stack*:                rbTreeAddBoolPStackP,                       \
  const volatile Stack*: rbTreeAddBoolPStackP,                       \
  RedBlackTree:          rbTreeAddBoolPRedBlackTree,                 \
  RedBlackTree*:         rbTreeAddBoolPRedBlackTreeP,                \
  const volatile RedBlackTree*: rbTreeAddBoolPRedBlackTreeP,                \
  HashTable:             rbTreeAddBoolPHashTable,                    \
  HashTable*:            rbTreeAddBoolPHashTableP,                   \
  const volatile HashTable*: rbTreeAddBoolPHashTableP,                   \
  Vector:                rbTreeAddBoolPVector,                       \
  Vector*:               rbTreeAddBoolPVectorP,                      \
  const volatile Vector*: rbTreeAddBoolPVectorP,                      \
  char*:                 rbTreeAddBoolPString,                       \
  const volatile char*:  rbTreeAddBoolPString,                       \
  char**:                rbTreeAddBoolPStringP,                      \
  const volatile char**: rbTreeAddBoolPStringP,                      \
  Bytes:                 rbTreeAddBoolPBytes,                        \
  Bytes*:                rbTreeAddBoolPBytesP,                       \
  const volatile Bytes*: rbTreeAddBoolPBytesP,                       \
  void*:                 rbTreeAddBoolPPointer,                      \
  void**:                rbTreeAddBoolPPointerP,                     \
  const volatile void**: rbTreeAddBoolPPointerP,                     \
  i8:                    rbTreeAddBoolI8,                            \
  u8:                    rbTreeAddBoolU8                             \

#define rbTreeAddBoolP(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_BOOLP_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_I16P_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddI16PBool,                          \
  bool*:                 rbTreeAddI16PBoolP,                         \
  const volatile bool*:  rbTreeAddI16PBoolP,                         \
  i16:                   rbTreeAddI16PI16,                           \
  i16*:                  rbTreeAddI16PI16P,                          \
  const volatile i16*:   rbTreeAddI16PI16P,                          \
  u16:                   rbTreeAddI16PU16,                           \
  u16*:                  rbTreeAddI16PU16P,                          \
  const volatile u16*:   rbTreeAddI16PU16P,                          \
  i32:                   rbTreeAddI16PI32,                           \
  i32*:                  rbTreeAddI16PI32P,                          \
  const volatile i32*:   rbTreeAddI16PI32P,                          \
  u32:                   rbTreeAddI16PU32,                           \
  u32*:                  rbTreeAddI16PU32P,                          \
  const volatile u32*:   rbTreeAddI16PU32P,                          \
  i64:                   rbTreeAddI16PI64,                           \
  i64*:                  rbTreeAddI16PI64P,                          \
  const volatile i64*:   rbTreeAddI16PI64P,                          \
  u64:                   rbTreeAddI16PU64,                           \
  u64*:                  rbTreeAddI16PU64P,                          \
  const volatile u64*:   rbTreeAddI16PU64P,                          \
  float:                 rbTreeAddI16PFloat,                         \
  float*:                rbTreeAddI16PFloatP,                        \
  const volatile float*: rbTreeAddI16PFloatP,                        \
  double:                rbTreeAddI16PDouble,                        \
  double*:               rbTreeAddI16PDoubleP,                       \
  const volatile double*: rbTreeAddI16PDoubleP,                       \
  long double:           rbTreeAddI16PLongDouble,                    \
  long double*:          rbTreeAddI16PLongDoubleP,                   \
  const volatile long double*: rbTreeAddI16PLongDoubleP,                   \
  List:                  rbTreeAddI16PList,                          \
  List*:                 rbTreeAddI16PListP,                         \
  const volatile List*:  rbTreeAddI16PListP,                         \
  Queue:                 rbTreeAddI16PQueue,                         \
  Queue*:                rbTreeAddI16PQueueP,                        \
  const volatile Queue*: rbTreeAddI16PQueueP,                        \
  Stack:                 rbTreeAddI16PStack,                         \
  Stack*:                rbTreeAddI16PStackP,                        \
  const volatile Stack*: rbTreeAddI16PStackP,                        \
  RedBlackTree:          rbTreeAddI16PRedBlackTree,                  \
  RedBlackTree*:         rbTreeAddI16PRedBlackTreeP,                 \
  const volatile RedBlackTree*: rbTreeAddI16PRedBlackTreeP,                 \
  HashTable:             rbTreeAddI16PHashTable,                     \
  HashTable*:            rbTreeAddI16PHashTableP,                    \
  const volatile HashTable*: rbTreeAddI16PHashTableP,                    \
  Vector:                rbTreeAddI16PVector,                        \
  Vector*:               rbTreeAddI16PVectorP,                       \
  const volatile Vector*: rbTreeAddI16PVectorP,                       \
  char*:                 rbTreeAddI16PString,                        \
  const volatile char*:  rbTreeAddI16PString,                        \
  char**:                rbTreeAddI16PStringP,                       \
  const volatile char**: rbTreeAddI16PStringP,                       \
  Bytes:                 rbTreeAddI16PBytes,                         \
  Bytes*:                rbTreeAddI16PBytesP,                        \
  const volatile Bytes*: rbTreeAddI16PBytesP,                        \
  void*:                 rbTreeAddI16PPointer,                       \
  void**:                rbTreeAddI16PPointerP,                      \
  const volatile void**: rbTreeAddI16PPointerP,                      \
  i8:                    rbTreeAddI16I8,                             \
  u8:                    rbTreeAddI16U8                              \

#define rbTreeAddI16P(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_I16P_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_U16P_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddU16PBool,                          \
  bool*:                 rbTreeAddU16PBoolP,                         \
  const volatile bool*:  rbTreeAddU16PBoolP,                         \
  i16:                   rbTreeAddU16PI16,                           \
  i16*:                  rbTreeAddU16PI16P,                          \
  const volatile i16*:   rbTreeAddU16PI16P,                          \
  u16:                   rbTreeAddU16PU16,                           \
  u16*:                  rbTreeAddU16PU16P,                          \
  const volatile u16*:   rbTreeAddU16PU16P,                          \
  i32:                   rbTreeAddU16PI32,                           \
  i32*:                  rbTreeAddU16PI32P,                          \
  const volatile i32*:   rbTreeAddU16PI32P,                          \
  u32:                   rbTreeAddU16PU32,                           \
  u32*:                  rbTreeAddU16PU32P,                          \
  const volatile u32*:   rbTreeAddU16PU32P,                          \
  i64:                   rbTreeAddU16PI64,                           \
  i64*:                  rbTreeAddU16PI64P,                          \
  const volatile i64*:   rbTreeAddU16PI64P,                          \
  u64:                   rbTreeAddU16PU64,                           \
  u64*:                  rbTreeAddU16PU64P,                          \
  const volatile u64*:   rbTreeAddU16PU64P,                          \
  float:                 rbTreeAddU16PFloat,                         \
  float*:                rbTreeAddU16PFloatP,                        \
  const volatile float*: rbTreeAddU16PFloatP,                        \
  double:                rbTreeAddU16PDouble,                        \
  double*:               rbTreeAddU16PDoubleP,                       \
  const volatile double*: rbTreeAddU16PDoubleP,                       \
  long double:           rbTreeAddU16PLongDouble,                    \
  long double*:          rbTreeAddU16PLongDoubleP,                   \
  const volatile long double*: rbTreeAddU16PLongDoubleP,                   \
  List:                  rbTreeAddU16PList,                          \
  List*:                 rbTreeAddU16PListP,                         \
  const volatile List*:  rbTreeAddU16PListP,                         \
  Queue:                 rbTreeAddU16PQueue,                         \
  Queue*:                rbTreeAddU16PQueueP,                        \
  const volatile Queue*: rbTreeAddU16PQueueP,                        \
  Stack:                 rbTreeAddU16PStack,                         \
  Stack*:                rbTreeAddU16PStackP,                        \
  const volatile Stack*: rbTreeAddU16PStackP,                        \
  RedBlackTree:          rbTreeAddU16PRedBlackTree,                  \
  RedBlackTree*:         rbTreeAddU16PRedBlackTreeP,                 \
  const volatile RedBlackTree*: rbTreeAddU16PRedBlackTreeP,                 \
  HashTable:             rbTreeAddU16PHashTable,                     \
  HashTable*:            rbTreeAddU16PHashTableP,                    \
  const volatile HashTable*: rbTreeAddU16PHashTableP,                    \
  Vector:                rbTreeAddU16PVector,                        \
  Vector*:               rbTreeAddU16PVectorP,                       \
  const volatile Vector*: rbTreeAddU16PVectorP,                       \
  char*:                 rbTreeAddU16PString,                        \
  const volatile char*:  rbTreeAddU16PString,                        \
  char**:                rbTreeAddU16PStringP,                       \
  const volatile char**: rbTreeAddU16PStringP,                       \
  Bytes:                 rbTreeAddU16PBytes,                         \
  Bytes*:                rbTreeAddU16PBytesP,                        \
  const volatile Bytes*: rbTreeAddU16PBytesP,                        \
  void*:                 rbTreeAddU16PPointer,                       \
  void**:                rbTreeAddU16PPointerP,                      \
  const volatile void**: rbTreeAddU16PPointerP,                      \
  i8:                    rbTreeAddU16I8,                             \
  u8:                    rbTreeAddU16U8                              \

#define rbTreeAddU16P(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_U16P_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_I32P_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddI32PBool,                          \
  bool*:                 rbTreeAddI32PBoolP,                         \
  const volatile bool*:  rbTreeAddI32PBoolP,                         \
  i16:                   rbTreeAddI32PI16,                           \
  i16*:                  rbTreeAddI32PI16P,                          \
  const volatile i16*:   rbTreeAddI32PI16P,                          \
  u16:                   rbTreeAddI32PU16,                           \
  u16*:                  rbTreeAddI32PU16P,                          \
  const volatile u16*:   rbTreeAddI32PU16P,                          \
  i32:                   rbTreeAddI32PI32,                           \
  i32*:                  rbTreeAddI32PI32P,                          \
  const volatile i32*:   rbTreeAddI32PI32P,                          \
  u32:                   rbTreeAddI32PU32,                           \
  u32*:                  rbTreeAddI32PU32P,                          \
  const volatile u32*:   rbTreeAddI32PU32P,                          \
  i64:                   rbTreeAddI32PI64,                           \
  i64*:                  rbTreeAddI32PI64P,                          \
  const volatile i64*:   rbTreeAddI32PI64P,                          \
  u64:                   rbTreeAddI32PU64,                           \
  u64*:                  rbTreeAddI32PU64P,                          \
  const volatile u64*:   rbTreeAddI32PU64P,                          \
  float:                 rbTreeAddI32PFloat,                         \
  float*:                rbTreeAddI32PFloatP,                        \
  const volatile float*: rbTreeAddI32PFloatP,                        \
  double:                rbTreeAddI32PDouble,                        \
  double*:               rbTreeAddI32PDoubleP,                       \
  const volatile double*: rbTreeAddI32PDoubleP,                       \
  long double:           rbTreeAddI32PLongDouble,                    \
  long double*:          rbTreeAddI32PLongDoubleP,                   \
  const volatile long double*: rbTreeAddI32PLongDoubleP,                   \
  List:                  rbTreeAddI32PList,                          \
  List*:                 rbTreeAddI32PListP,                         \
  const volatile List*:  rbTreeAddI32PListP,                         \
  Queue:                 rbTreeAddI32PQueue,                         \
  Queue*:                rbTreeAddI32PQueueP,                        \
  const volatile Queue*: rbTreeAddI32PQueueP,                        \
  Stack:                 rbTreeAddI32PStack,                         \
  Stack*:                rbTreeAddI32PStackP,                        \
  const volatile Stack*: rbTreeAddI32PStackP,                        \
  RedBlackTree:          rbTreeAddI32PRedBlackTree,                  \
  RedBlackTree*:         rbTreeAddI32PRedBlackTreeP,                 \
  const volatile RedBlackTree*: rbTreeAddI32PRedBlackTreeP,                 \
  HashTable:             rbTreeAddI32PHashTable,                     \
  HashTable*:            rbTreeAddI32PHashTableP,                    \
  const volatile HashTable*: rbTreeAddI32PHashTableP,                    \
  Vector:                rbTreeAddI32PVector,                        \
  Vector*:               rbTreeAddI32PVectorP,                       \
  const volatile Vector*: rbTreeAddI32PVectorP,                       \
  char*:                 rbTreeAddI32PString,                        \
  const volatile char*:  rbTreeAddI32PString,                        \
  char**:                rbTreeAddI32PStringP,                       \
  const volatile char**: rbTreeAddI32PStringP,                       \
  Bytes:                 rbTreeAddI32PBytes,                         \
  Bytes*:                rbTreeAddI32PBytesP,                        \
  const volatile Bytes*: rbTreeAddI32PBytesP,                        \
  void*:                 rbTreeAddI32PPointer,                       \
  void**:                rbTreeAddI32PPointerP,                      \
  const volatile void**: rbTreeAddI32PPointerP,                      \
  i8:                    rbTreeAddI32I8,                             \
  u8:                    rbTreeAddI32U8                              \

#define rbTreeAddI32P(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_I32P_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_U32P_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddU32PBool,                          \
  bool*:                 rbTreeAddU32PBoolP,                         \
  const volatile bool*:  rbTreeAddU32PBoolP,                         \
  i16:                   rbTreeAddU32PI16,                           \
  i16*:                  rbTreeAddU32PI16P,                          \
  const volatile i16*:   rbTreeAddU32PI16P,                          \
  u16:                   rbTreeAddU32PU16,                           \
  u16*:                  rbTreeAddU32PU16P,                          \
  const volatile u16*:   rbTreeAddU32PU16P,                          \
  i32:                   rbTreeAddU32PI32,                           \
  i32*:                  rbTreeAddU32PI32P,                          \
  const volatile i32*:   rbTreeAddU32PI32P,                          \
  u32:                   rbTreeAddU32PU32,                           \
  u32*:                  rbTreeAddU32PU32P,                          \
  const volatile u32*:   rbTreeAddU32PU32P,                          \
  i64:                   rbTreeAddU32PI64,                           \
  i64*:                  rbTreeAddU32PI64P,                          \
  const volatile i64*:   rbTreeAddU32PI64P,                          \
  u64:                   rbTreeAddU32PU64,                           \
  u64*:                  rbTreeAddU32PU64P,                          \
  const volatile u64*:   rbTreeAddU32PU64P,                          \
  float:                 rbTreeAddU32PFloat,                         \
  float*:                rbTreeAddU32PFloatP,                        \
  const volatile float*: rbTreeAddU32PFloatP,                        \
  double:                rbTreeAddU32PDouble,                        \
  double*:               rbTreeAddU32PDoubleP,                       \
  const volatile double*: rbTreeAddU32PDoubleP,                       \
  long double:           rbTreeAddU32PLongDouble,                    \
  long double*:          rbTreeAddU32PLongDoubleP,                   \
  const volatile long double*: rbTreeAddU32PLongDoubleP,                   \
  List:                  rbTreeAddU32PList,                          \
  List*:                 rbTreeAddU32PListP,                         \
  const volatile List*:  rbTreeAddU32PListP,                         \
  Queue:                 rbTreeAddU32PQueue,                         \
  Queue*:                rbTreeAddU32PQueueP,                        \
  const volatile Queue*: rbTreeAddU32PQueueP,                        \
  Stack:                 rbTreeAddU32PStack,                         \
  Stack*:                rbTreeAddU32PStackP,                        \
  const volatile Stack*: rbTreeAddU32PStackP,                        \
  RedBlackTree:          rbTreeAddU32PRedBlackTree,                  \
  RedBlackTree*:         rbTreeAddU32PRedBlackTreeP,                 \
  const volatile RedBlackTree*: rbTreeAddU32PRedBlackTreeP,                 \
  HashTable:             rbTreeAddU32PHashTable,                     \
  HashTable*:            rbTreeAddU32PHashTableP,                    \
  const volatile HashTable*: rbTreeAddU32PHashTableP,                    \
  Vector:                rbTreeAddU32PVector,                        \
  Vector*:               rbTreeAddU32PVectorP,                       \
  const volatile Vector*: rbTreeAddU32PVectorP,                       \
  char*:                 rbTreeAddU32PString,                        \
  const volatile char*:  rbTreeAddU32PString,                        \
  char**:                rbTreeAddU32PStringP,                       \
  const volatile char**: rbTreeAddU32PStringP,                       \
  Bytes:                 rbTreeAddU32PBytes,                         \
  Bytes*:                rbTreeAddU32PBytesP,                        \
  const volatile Bytes*: rbTreeAddU32PBytesP,                        \
  void*:                 rbTreeAddU32PPointer,                       \
  void**:                rbTreeAddU32PPointerP,                      \
  const volatile void**: rbTreeAddU32PPointerP,                      \
  i8:                    rbTreeAddU32I8,                             \
  u8:                    rbTreeAddU32U8                              \

#define rbTreeAddU32P(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_U32P_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_I64P_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddI64PBool,                          \
  bool*:                 rbTreeAddI64PBoolP,                         \
  const volatile bool*:  rbTreeAddI64PBoolP,                         \
  i16:                   rbTreeAddI64PI16,                           \
  i16*:                  rbTreeAddI64PI16P,                          \
  const volatile i16*:   rbTreeAddI64PI16P,                          \
  u16:                   rbTreeAddI64PU16,                           \
  u16*:                  rbTreeAddI64PU16P,                          \
  const volatile u16*:   rbTreeAddI64PU16P,                          \
  i32:                   rbTreeAddI64PI32,                           \
  i32*:                  rbTreeAddI64PI32P,                          \
  const volatile i32*:   rbTreeAddI64PI32P,                          \
  u32:                   rbTreeAddI64PU32,                           \
  u32*:                  rbTreeAddI64PU32P,                          \
  const volatile u32*:   rbTreeAddI64PU32P,                          \
  i64:                   rbTreeAddI64PI64,                           \
  i64*:                  rbTreeAddI64PI64P,                          \
  const volatile i64*:   rbTreeAddI64PI64P,                          \
  u64:                   rbTreeAddI64PU64,                           \
  u64*:                  rbTreeAddI64PU64P,                          \
  const volatile u64*:   rbTreeAddI64PU64P,                          \
  float:                 rbTreeAddI64PFloat,                         \
  float*:                rbTreeAddI64PFloatP,                        \
  const volatile float*: rbTreeAddI64PFloatP,                        \
  double:                rbTreeAddI64PDouble,                        \
  double*:               rbTreeAddI64PDoubleP,                       \
  const volatile double*: rbTreeAddI64PDoubleP,                       \
  long double:           rbTreeAddI64PLongDouble,                    \
  long double*:          rbTreeAddI64PLongDoubleP,                   \
  const volatile long double*: rbTreeAddI64PLongDoubleP,                   \
  List:                  rbTreeAddI64PList,                          \
  List*:                 rbTreeAddI64PListP,                         \
  const volatile List*:  rbTreeAddI64PListP,                         \
  Queue:                 rbTreeAddI64PQueue,                         \
  Queue*:                rbTreeAddI64PQueueP,                        \
  const volatile Queue*: rbTreeAddI64PQueueP,                        \
  Stack:                 rbTreeAddI64PStack,                         \
  Stack*:                rbTreeAddI64PStackP,                        \
  const volatile Stack*: rbTreeAddI64PStackP,                        \
  RedBlackTree:          rbTreeAddI64PRedBlackTree,                  \
  RedBlackTree*:         rbTreeAddI64PRedBlackTreeP,                 \
  const volatile RedBlackTree*: rbTreeAddI64PRedBlackTreeP,                 \
  HashTable:             rbTreeAddI64PHashTable,                     \
  HashTable*:            rbTreeAddI64PHashTableP,                    \
  const volatile HashTable*: rbTreeAddI64PHashTableP,                    \
  Vector:                rbTreeAddI64PVector,                        \
  Vector*:               rbTreeAddI64PVectorP,                       \
  const volatile Vector*: rbTreeAddI64PVectorP,                       \
  char*:                 rbTreeAddI64PString,                        \
  const volatile char*:  rbTreeAddI64PString,                        \
  char**:                rbTreeAddI64PStringP,                       \
  const volatile char**: rbTreeAddI64PStringP,                       \
  Bytes:                 rbTreeAddI64PBytes,                         \
  Bytes*:                rbTreeAddI64PBytesP,                        \
  const volatile Bytes*: rbTreeAddI64PBytesP,                        \
  void*:                 rbTreeAddI64PPointer,                       \
  void**:                rbTreeAddI64PPointerP,                      \
  const volatile void**: rbTreeAddI64PPointerP,                      \
  i8:                    rbTreeAddI64I8,                             \
  u8:                    rbTreeAddI64U8                              \

#define rbTreeAddI64P(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_I64P_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_U64P_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddU64PBool,                          \
  bool*:                 rbTreeAddU64PBoolP,                         \
  const volatile bool*:  rbTreeAddU64PBoolP,                         \
  i16:                   rbTreeAddU64PI16,                           \
  i16*:                  rbTreeAddU64PI16P,                          \
  const volatile i16*:   rbTreeAddU64PI16P,                          \
  u16:                   rbTreeAddU64PU16,                           \
  u16*:                  rbTreeAddU64PU16P,                          \
  const volatile u16*:   rbTreeAddU64PU16P,                          \
  i32:                   rbTreeAddU64PI32,                           \
  i32*:                  rbTreeAddU64PI32P,                          \
  const volatile i32*:   rbTreeAddU64PI32P,                          \
  u32:                   rbTreeAddU64PU32,                           \
  u32*:                  rbTreeAddU64PU32P,                          \
  const volatile u32*:   rbTreeAddU64PU32P,                          \
  i64:                   rbTreeAddU64PI64,                           \
  i64*:                  rbTreeAddU64PI64P,                          \
  const volatile i64*:   rbTreeAddU64PI64P,                          \
  u64:                   rbTreeAddU64PU64,                           \
  u64*:                  rbTreeAddU64PU64P,                          \
  const volatile u64*:   rbTreeAddU64PU64P,                          \
  float:                 rbTreeAddU64PFloat,                         \
  float*:                rbTreeAddU64PFloatP,                        \
  const volatile float*: rbTreeAddU64PFloatP,                        \
  double:                rbTreeAddU64PDouble,                        \
  double*:               rbTreeAddU64PDoubleP,                       \
  const volatile double*: rbTreeAddU64PDoubleP,                       \
  long double:           rbTreeAddU64PLongDouble,                    \
  long double*:          rbTreeAddU64PLongDoubleP,                   \
  const volatile long double*: rbTreeAddU64PLongDoubleP,                   \
  List:                  rbTreeAddU64PList,                          \
  List*:                 rbTreeAddU64PListP,                         \
  const volatile List*:  rbTreeAddU64PListP,                         \
  Queue:                 rbTreeAddU64PQueue,                         \
  Queue*:                rbTreeAddU64PQueueP,                        \
  const volatile Queue*: rbTreeAddU64PQueueP,                        \
  Stack:                 rbTreeAddU64PStack,                         \
  Stack*:                rbTreeAddU64PStackP,                        \
  const volatile Stack*: rbTreeAddU64PStackP,                        \
  RedBlackTree:          rbTreeAddU64PRedBlackTree,                  \
  RedBlackTree*:         rbTreeAddU64PRedBlackTreeP,                 \
  const volatile RedBlackTree*: rbTreeAddU64PRedBlackTreeP,                 \
  HashTable:             rbTreeAddU64PHashTable,                     \
  HashTable*:            rbTreeAddU64PHashTableP,                    \
  const volatile HashTable*: rbTreeAddU64PHashTableP,                    \
  Vector:                rbTreeAddU64PVector,                        \
  Vector*:               rbTreeAddU64PVectorP,                       \
  const volatile Vector*: rbTreeAddU64PVectorP,                       \
  char*:                 rbTreeAddU64PString,                        \
  const volatile char*:  rbTreeAddU64PString,                        \
  char**:                rbTreeAddU64PStringP,                       \
  const volatile char**: rbTreeAddU64PStringP,                       \
  Bytes:                 rbTreeAddU64PBytes,                         \
  Bytes*:                rbTreeAddU64PBytesP,                        \
  const volatile Bytes*: rbTreeAddU64PBytesP,                        \
  void*:                 rbTreeAddU64PPointer,                       \
  void**:                rbTreeAddU64PPointerP,                      \
  const volatile void**: rbTreeAddU64PPointerP,                      \
  i8:                    rbTreeAddU64I8,                             \
  u8:                    rbTreeAddU64U8                              \

#define rbTreeAddU64P(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_U64P_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_FLOATP_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddFloatPBool,                        \
  bool*:                 rbTreeAddFloatPBoolP,                       \
  const volatile bool*:  rbTreeAddFloatPBoolP,                       \
  i16:                   rbTreeAddFloatPI16,                         \
  i16*:                  rbTreeAddFloatPI16P,                        \
  const volatile i16*:   rbTreeAddFloatPI16P,                        \
  u16:                   rbTreeAddFloatPU16,                         \
  u16*:                  rbTreeAddFloatPU16P,                        \
  const volatile u16*:   rbTreeAddFloatPU16P,                        \
  i32:                   rbTreeAddFloatPI32,                         \
  i32*:                  rbTreeAddFloatPI32P,                        \
  const volatile i32*:   rbTreeAddFloatPI32P,                        \
  u32:                   rbTreeAddFloatPU32,                         \
  u32*:                  rbTreeAddFloatPU32P,                        \
  const volatile u32*:   rbTreeAddFloatPU32P,                        \
  i64:                   rbTreeAddFloatPI64,                         \
  i64*:                  rbTreeAddFloatPI64P,                        \
  const volatile i64*:   rbTreeAddFloatPI64P,                        \
  u64:                   rbTreeAddFloatPU64,                         \
  u64*:                  rbTreeAddFloatPU64P,                        \
  const volatile u64*:   rbTreeAddFloatPU64P,                        \
  float:                 rbTreeAddFloatPFloat,                       \
  float*:                rbTreeAddFloatPFloatP,                      \
  const volatile float*: rbTreeAddFloatPFloatP,                      \
  double:                rbTreeAddFloatPDouble,                      \
  double*:               rbTreeAddFloatPDoubleP,                     \
  const volatile double*: rbTreeAddFloatPDoubleP,                     \
  long double:           rbTreeAddFloatPLongDouble,                  \
  long double*:          rbTreeAddFloatPLongDoubleP,                 \
  const volatile long double*: rbTreeAddFloatPLongDoubleP,                 \
  List:                  rbTreeAddFloatPList,                        \
  List*:                 rbTreeAddFloatPListP,                       \
  const volatile List*:  rbTreeAddFloatPListP,                       \
  Queue:                 rbTreeAddFloatPQueue,                       \
  Queue*:                rbTreeAddFloatPQueueP,                      \
  const volatile Queue*: rbTreeAddFloatPQueueP,                      \
  Stack:                 rbTreeAddFloatPStack,                       \
  Stack*:                rbTreeAddFloatPStackP,                      \
  const volatile Stack*: rbTreeAddFloatPStackP,                      \
  RedBlackTree:          rbTreeAddFloatPRedBlackTree,                \
  RedBlackTree*:         rbTreeAddFloatPRedBlackTreeP,               \
  const volatile RedBlackTree*: rbTreeAddFloatPRedBlackTreeP,               \
  HashTable:             rbTreeAddFloatPHashTable,                   \
  HashTable*:            rbTreeAddFloatPHashTableP,                  \
  const volatile HashTable*: rbTreeAddFloatPHashTableP,                  \
  Vector:                rbTreeAddFloatPVector,                      \
  Vector*:               rbTreeAddFloatPVectorP,                     \
  const volatile Vector*: rbTreeAddFloatPVectorP,                     \
  char*:                 rbTreeAddFloatPString,                      \
  const volatile char*:  rbTreeAddFloatPString,                      \
  char**:                rbTreeAddFloatPStringP,                     \
  const volatile char**: rbTreeAddFloatPStringP,                     \
  Bytes:                 rbTreeAddFloatPBytes,                       \
  Bytes*:                rbTreeAddFloatPBytesP,                      \
  const volatile Bytes*: rbTreeAddFloatPBytesP,                      \
  void*:                 rbTreeAddFloatPPointer,                     \
  void**:                rbTreeAddFloatPPointerP,                    \
  const volatile void**: rbTreeAddFloatPPointerP,                    \
  i8:                    rbTreeAddFloatI8,                           \
  u8:                    rbTreeAddFloatU8                            \

#define rbTreeAddFloatP(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_FLOATP_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_DOUBLEP_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddDoublePBool,                       \
  bool*:                 rbTreeAddDoublePBoolP,                      \
  const volatile bool*:  rbTreeAddDoublePBoolP,                      \
  i16:                   rbTreeAddDoublePI16,                        \
  i16*:                  rbTreeAddDoublePI16P,                       \
  const volatile i16*:   rbTreeAddDoublePI16P,                       \
  u16:                   rbTreeAddDoublePU16,                        \
  u16*:                  rbTreeAddDoublePU16P,                       \
  const volatile u16*:   rbTreeAddDoublePU16P,                       \
  i32:                   rbTreeAddDoublePI32,                        \
  i32*:                  rbTreeAddDoublePI32P,                       \
  const volatile i32*:   rbTreeAddDoublePI32P,                       \
  u32:                   rbTreeAddDoublePU32,                        \
  u32*:                  rbTreeAddDoublePU32P,                       \
  const volatile u32*:   rbTreeAddDoublePU32P,                       \
  i64:                   rbTreeAddDoublePI64,                        \
  i64*:                  rbTreeAddDoublePI64P,                       \
  const volatile i64*:   rbTreeAddDoublePI64P,                       \
  u64:                   rbTreeAddDoublePU64,                        \
  u64*:                  rbTreeAddDoublePU64P,                       \
  const volatile u64*:   rbTreeAddDoublePU64P,                       \
  float:                 rbTreeAddDoublePFloat,                      \
  float*:                rbTreeAddDoublePFloatP,                     \
  const volatile float*: rbTreeAddDoublePFloatP,                     \
  double:                rbTreeAddDoublePDouble,                     \
  double*:               rbTreeAddDoublePDoubleP,                    \
  const volatile double*: rbTreeAddDoublePDoubleP,                    \
  long double:           rbTreeAddDoublePLongDouble,                 \
  long double*:          rbTreeAddDoublePLongDoubleP,                \
  const volatile long double*: rbTreeAddDoublePLongDoubleP,                \
  List:                  rbTreeAddDoublePList,                       \
  List*:                 rbTreeAddDoublePListP,                      \
  const volatile List*:  rbTreeAddDoublePListP,                      \
  Queue:                 rbTreeAddDoublePQueue,                      \
  Queue*:                rbTreeAddDoublePQueueP,                     \
  const volatile Queue*: rbTreeAddDoublePQueueP,                     \
  Stack:                 rbTreeAddDoublePStack,                      \
  Stack*:                rbTreeAddDoublePStackP,                     \
  const volatile Stack*: rbTreeAddDoublePStackP,                     \
  RedBlackTree:          rbTreeAddDoublePRedBlackTree,               \
  RedBlackTree*:         rbTreeAddDoublePRedBlackTreeP,              \
  const volatile RedBlackTree*: rbTreeAddDoublePRedBlackTreeP,              \
  HashTable:             rbTreeAddDoublePHashTable,                  \
  HashTable*:            rbTreeAddDoublePHashTableP,                 \
  const volatile HashTable*: rbTreeAddDoublePHashTableP,                 \
  Vector:                rbTreeAddDoublePVector,                     \
  Vector*:               rbTreeAddDoublePVectorP,                    \
  const volatile Vector*: rbTreeAddDoublePVectorP,                    \
  char*:                 rbTreeAddDoublePString,                     \
  const volatile char*:  rbTreeAddDoublePString,                     \
  char**:                rbTreeAddDoublePStringP,                    \
  const volatile char**: rbTreeAddDoublePStringP,                    \
  Bytes:                 rbTreeAddDoublePBytes,                      \
  Bytes*:                rbTreeAddDoublePBytesP,                     \
  const volatile Bytes*: rbTreeAddDoublePBytesP,                     \
  void*:                 rbTreeAddDoublePPointer,                    \
  void**:                rbTreeAddDoublePPointerP,                   \
  const volatile void**: rbTreeAddDoublePPointerP,                   \
  i8:                    rbTreeAddDoubleI8,                          \
  u8:                    rbTreeAddDoubleU8                           \

#define rbTreeAddDoubleP(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_DOUBLEP_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_LONG_DOUBLEP_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddLongDoublePBool,                   \
  bool*:                 rbTreeAddLongDoublePBoolP,                  \
  const volatile bool*:  rbTreeAddLongDoublePBoolP,                  \
  i16:                   rbTreeAddLongDoublePI16,                    \
  i16*:                  rbTreeAddLongDoublePI16P,                   \
  const volatile i16*:   rbTreeAddLongDoublePI16P,                   \
  u16:                   rbTreeAddLongDoublePU16,                    \
  u16*:                  rbTreeAddLongDoublePU16P,                   \
  const volatile u16*:   rbTreeAddLongDoublePU16P,                   \
  i32:                   rbTreeAddLongDoublePI32,                    \
  i32*:                  rbTreeAddLongDoublePI32P,                   \
  const volatile i32*:   rbTreeAddLongDoublePI32P,                   \
  u32:                   rbTreeAddLongDoublePU32,                    \
  u32*:                  rbTreeAddLongDoublePU32P,                   \
  const volatile u32*:   rbTreeAddLongDoublePU32P,                   \
  i64:                   rbTreeAddLongDoublePI64,                    \
  i64*:                  rbTreeAddLongDoublePI64P,                   \
  const volatile i64*:   rbTreeAddLongDoublePI64P,                   \
  u64:                   rbTreeAddLongDoublePU64,                    \
  u64*:                  rbTreeAddLongDoublePU64P,                   \
  const volatile u64*:   rbTreeAddLongDoublePU64P,                   \
  float:                 rbTreeAddLongDoublePFloat,                  \
  float*:                rbTreeAddLongDoublePFloatP,                 \
  const volatile float*: rbTreeAddLongDoublePFloatP,                 \
  double:                rbTreeAddLongDoublePDouble,                 \
  double*:               rbTreeAddLongDoublePDoubleP,                \
  const volatile double*: rbTreeAddLongDoublePDoubleP,                \
  long double:           rbTreeAddLongDoublePLongDouble,             \
  long double*:          rbTreeAddLongDoublePLongDoubleP,            \
  const volatile long double*: rbTreeAddLongDoublePLongDoubleP,            \
  List:                  rbTreeAddLongDoublePList,                   \
  List*:                 rbTreeAddLongDoublePListP,                  \
  const volatile List*:  rbTreeAddLongDoublePListP,                  \
  Queue:                 rbTreeAddLongDoublePQueue,                  \
  Queue*:                rbTreeAddLongDoublePQueueP,                 \
  const volatile Queue*: rbTreeAddLongDoublePQueueP,                 \
  Stack:                 rbTreeAddLongDoublePStack,                  \
  Stack*:                rbTreeAddLongDoublePStackP,                 \
  const volatile Stack*: rbTreeAddLongDoublePStackP,                 \
  RedBlackTree:          rbTreeAddLongDoublePRedBlackTree,           \
  RedBlackTree*:         rbTreeAddLongDoublePRedBlackTreeP,          \
  const volatile RedBlackTree*: rbTreeAddLongDoublePRedBlackTreeP,          \
  HashTable:             rbTreeAddLongDoublePHashTable,              \
  HashTable*:            rbTreeAddLongDoublePHashTableP,             \
  const volatile HashTable*: rbTreeAddLongDoublePHashTableP,             \
  Vector:                rbTreeAddLongDoublePVector,                 \
  Vector*:               rbTreeAddLongDoublePVectorP,                \
  const volatile Vector*: rbTreeAddLongDoublePVectorP,                \
  char*:                 rbTreeAddLongDoublePString,                 \
  const volatile char*:  rbTreeAddLongDoublePString,                 \
  char**:                rbTreeAddLongDoublePStringP,                \
  const volatile char**: rbTreeAddLongDoublePStringP,                \
  Bytes:                 rbTreeAddLongDoublePBytes,                  \
  Bytes*:                rbTreeAddLongDoublePBytesP,                 \
  const volatile Bytes*: rbTreeAddLongDoublePBytesP,                 \
  void*:                 rbTreeAddLongDoublePPointer,                \
  void**:                rbTreeAddLongDoublePPointerP,               \
  const volatile void**: rbTreeAddLongDoublePPointerP,               \
  i8:                    rbTreeAddLongDoubleI8,                      \
  u8:                    rbTreeAddLongDoubleU8                       \

#define rbTreeAddLongDoubleP(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_LONG_DOUBLEP_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_LISTP_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddListPBool,                         \
  bool*:                 rbTreeAddListPBoolP,                        \
  const volatile bool*:  rbTreeAddListPBoolP,                        \
  i16:                   rbTreeAddListPI16,                          \
  i16*:                  rbTreeAddListPI16P,                         \
  const volatile i16*:   rbTreeAddListPI16P,                         \
  u16:                   rbTreeAddListPU16,                          \
  u16*:                  rbTreeAddListPU16P,                         \
  const volatile u16*:   rbTreeAddListPU16P,                         \
  i32:                   rbTreeAddListPI32,                          \
  i32*:                  rbTreeAddListPI32P,                         \
  const volatile i32*:   rbTreeAddListPI32P,                         \
  u32:                   rbTreeAddListPU32,                          \
  u32*:                  rbTreeAddListPU32P,                         \
  const volatile u32*:   rbTreeAddListPU32P,                         \
  i64:                   rbTreeAddListPI64,                          \
  i64*:                  rbTreeAddListPI64P,                         \
  const volatile i64*:   rbTreeAddListPI64P,                         \
  u64:                   rbTreeAddListPU64,                          \
  u64*:                  rbTreeAddListPU64P,                         \
  const volatile u64*:   rbTreeAddListPU64P,                         \
  float:                 rbTreeAddListPFloat,                        \
  float*:                rbTreeAddListPFloatP,                       \
  const volatile float*: rbTreeAddListPFloatP,                       \
  double:                rbTreeAddListPDouble,                       \
  double*:               rbTreeAddListPDoubleP,                      \
  const volatile double*: rbTreeAddListPDoubleP,                      \
  long double:           rbTreeAddListPLongDouble,                   \
  long double*:          rbTreeAddListPLongDoubleP,                  \
  const volatile long double*: rbTreeAddListPLongDoubleP,                  \
  List:                  rbTreeAddListPList,                         \
  List*:                 rbTreeAddListPListP,                        \
  const volatile List*:  rbTreeAddListPListP,                        \
  Queue:                 rbTreeAddListPQueue,                        \
  Queue*:                rbTreeAddListPQueueP,                       \
  const volatile Queue*: rbTreeAddListPQueueP,                       \
  Stack:                 rbTreeAddListPStack,                        \
  Stack*:                rbTreeAddListPStackP,                       \
  const volatile Stack*: rbTreeAddListPStackP,                       \
  RedBlackTree:          rbTreeAddListPRedBlackTree,                 \
  RedBlackTree*:         rbTreeAddListPRedBlackTreeP,                \
  const volatile RedBlackTree*: rbTreeAddListPRedBlackTreeP,                \
  HashTable:             rbTreeAddListPHashTable,                    \
  HashTable*:            rbTreeAddListPHashTableP,                   \
  const volatile HashTable*: rbTreeAddListPHashTableP,                   \
  Vector:                rbTreeAddListPVector,                       \
  Vector*:               rbTreeAddListPVectorP,                      \
  const volatile Vector*: rbTreeAddListPVectorP,                      \
  char*:                 rbTreeAddListPString,                       \
  const volatile char*:  rbTreeAddListPString,                       \
  char**:                rbTreeAddListPStringP,                      \
  const volatile char**: rbTreeAddListPStringP,                      \
  Bytes:                 rbTreeAddListPBytes,                        \
  Bytes*:                rbTreeAddListPBytesP,                       \
  const volatile Bytes*: rbTreeAddListPBytesP,                       \
  void*:                 rbTreeAddListPPointer,                      \
  void**:                rbTreeAddListPPointerP,                     \
  const volatile void**: rbTreeAddListPPointerP,                     \
  i8:                    rbTreeAddListI8,                            \
  u8:                    rbTreeAddListU8                             \

#define rbTreeAddListP(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_LISTP_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_QUEUEP_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddQueuePBool,                        \
  bool*:                 rbTreeAddQueuePBoolP,                       \
  const volatile bool*:  rbTreeAddQueuePBoolP,                       \
  i16:                   rbTreeAddQueuePI16,                         \
  i16*:                  rbTreeAddQueuePI16P,                        \
  const volatile i16*:   rbTreeAddQueuePI16P,                        \
  u16:                   rbTreeAddQueuePU16,                         \
  u16*:                  rbTreeAddQueuePU16P,                        \
  const volatile u16*:   rbTreeAddQueuePU16P,                        \
  i32:                   rbTreeAddQueuePI32,                         \
  i32*:                  rbTreeAddQueuePI32P,                        \
  const volatile i32*:   rbTreeAddQueuePI32P,                        \
  u32:                   rbTreeAddQueuePU32,                         \
  u32*:                  rbTreeAddQueuePU32P,                        \
  const volatile u32*:   rbTreeAddQueuePU32P,                        \
  i64:                   rbTreeAddQueuePI64,                         \
  i64*:                  rbTreeAddQueuePI64P,                        \
  const volatile i64*:   rbTreeAddQueuePI64P,                        \
  u64:                   rbTreeAddQueuePU64,                         \
  u64*:                  rbTreeAddQueuePU64P,                        \
  const volatile u64*:   rbTreeAddQueuePU64P,                        \
  float:                 rbTreeAddQueuePFloat,                       \
  float*:                rbTreeAddQueuePFloatP,                      \
  const volatile float*: rbTreeAddQueuePFloatP,                      \
  double:                rbTreeAddQueuePDouble,                      \
  double*:               rbTreeAddQueuePDoubleP,                     \
  const volatile double*: rbTreeAddQueuePDoubleP,                     \
  long double:           rbTreeAddQueuePLongDouble,                  \
  long double*:          rbTreeAddQueuePLongDoubleP,                 \
  const volatile long double*: rbTreeAddQueuePLongDoubleP,                 \
  List:                  rbTreeAddQueuePList,                        \
  List*:                 rbTreeAddQueuePListP,                       \
  const volatile List*:  rbTreeAddQueuePListP,                       \
  Queue:                 rbTreeAddQueuePQueue,                       \
  Queue*:                rbTreeAddQueuePQueueP,                      \
  const volatile Queue*: rbTreeAddQueuePQueueP,                      \
  Stack:                 rbTreeAddQueuePStack,                       \
  Stack*:                rbTreeAddQueuePStackP,                      \
  const volatile Stack*: rbTreeAddQueuePStackP,                      \
  RedBlackTree:          rbTreeAddQueuePRedBlackTree,                \
  RedBlackTree*:         rbTreeAddQueuePRedBlackTreeP,               \
  const volatile RedBlackTree*: rbTreeAddQueuePRedBlackTreeP,               \
  HashTable:             rbTreeAddQueuePHashTable,                   \
  HashTable*:            rbTreeAddQueuePHashTableP,                  \
  const volatile HashTable*: rbTreeAddQueuePHashTableP,                  \
  Vector:                rbTreeAddQueuePVector,                      \
  Vector*:               rbTreeAddQueuePVectorP,                     \
  const volatile Vector*: rbTreeAddQueuePVectorP,                     \
  char*:                 rbTreeAddQueuePString,                      \
  const volatile char*:  rbTreeAddQueuePString,                      \
  char**:                rbTreeAddQueuePStringP,                     \
  const volatile char**: rbTreeAddQueuePStringP,                     \
  Bytes:                 rbTreeAddQueuePBytes,                       \
  Bytes*:                rbTreeAddQueuePBytesP,                      \
  const volatile Bytes*: rbTreeAddQueuePBytesP,                      \
  void*:                 rbTreeAddQueuePPointer,                     \
  void**:                rbTreeAddQueuePPointerP,                    \
  const volatile void**: rbTreeAddQueuePPointerP,                    \
  i8:                    rbTreeAddQueueI8,                           \
  u8:                    rbTreeAddQueueU8                            \

#define rbTreeAddQueueP(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_QUEUEP_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_STACKP_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddStackPBool,                        \
  bool*:                 rbTreeAddStackPBoolP,                       \
  const volatile bool*:  rbTreeAddStackPBoolP,                       \
  i16:                   rbTreeAddStackPI16,                         \
  i16*:                  rbTreeAddStackPI16P,                        \
  const volatile i16*:   rbTreeAddStackPI16P,                        \
  u16:                   rbTreeAddStackPU16,                         \
  u16*:                  rbTreeAddStackPU16P,                        \
  const volatile u16*:   rbTreeAddStackPU16P,                        \
  i32:                   rbTreeAddStackPI32,                         \
  i32*:                  rbTreeAddStackPI32P,                        \
  const volatile i32*:   rbTreeAddStackPI32P,                        \
  u32:                   rbTreeAddStackPU32,                         \
  u32*:                  rbTreeAddStackPU32P,                        \
  const volatile u32*:   rbTreeAddStackPU32P,                        \
  i64:                   rbTreeAddStackPI64,                         \
  i64*:                  rbTreeAddStackPI64P,                        \
  const volatile i64*:   rbTreeAddStackPI64P,                        \
  u64:                   rbTreeAddStackPU64,                         \
  u64*:                  rbTreeAddStackPU64P,                        \
  const volatile u64*:   rbTreeAddStackPU64P,                        \
  float:                 rbTreeAddStackPFloat,                       \
  float*:                rbTreeAddStackPFloatP,                      \
  const volatile float*: rbTreeAddStackPFloatP,                      \
  double:                rbTreeAddStackPDouble,                      \
  double*:               rbTreeAddStackPDoubleP,                     \
  const volatile double*: rbTreeAddStackPDoubleP,                     \
  long double:           rbTreeAddStackPLongDouble,                  \
  long double*:          rbTreeAddStackPLongDoubleP,                 \
  const volatile long double*: rbTreeAddStackPLongDoubleP,                 \
  List:                  rbTreeAddStackPList,                        \
  List*:                 rbTreeAddStackPListP,                       \
  const volatile List*:  rbTreeAddStackPListP,                       \
  Queue:                 rbTreeAddStackPQueue,                       \
  Queue*:                rbTreeAddStackPQueueP,                      \
  const volatile Queue*: rbTreeAddStackPQueueP,                      \
  Stack:                 rbTreeAddStackPStack,                       \
  Stack*:                rbTreeAddStackPStackP,                      \
  const volatile Stack*: rbTreeAddStackPStackP,                      \
  RedBlackTree:          rbTreeAddStackPRedBlackTree,                \
  RedBlackTree*:         rbTreeAddStackPRedBlackTreeP,               \
  const volatile RedBlackTree*: rbTreeAddStackPRedBlackTreeP,               \
  HashTable:             rbTreeAddStackPHashTable,                   \
  HashTable*:            rbTreeAddStackPHashTableP,                  \
  const volatile HashTable*: rbTreeAddStackPHashTableP,                  \
  Vector:                rbTreeAddStackPVector,                      \
  Vector*:               rbTreeAddStackPVectorP,                     \
  const volatile Vector*: rbTreeAddStackPVectorP,                     \
  char*:                 rbTreeAddStackPString,                      \
  const volatile char*:  rbTreeAddStackPString,                      \
  char**:                rbTreeAddStackPStringP,                     \
  const volatile char**: rbTreeAddStackPStringP,                     \
  Bytes:                 rbTreeAddStackPBytes,                       \
  Bytes*:                rbTreeAddStackPBytesP,                      \
  const volatile Bytes*: rbTreeAddStackPBytesP,                      \
  void*:                 rbTreeAddStackPPointer,                     \
  void**:                rbTreeAddStackPPointerP,                    \
  const volatile void**: rbTreeAddStackPPointerP,                    \
  i8:                    rbTreeAddStackI8,                           \
  u8:                    rbTreeAddStackU8                            \

#define rbTreeAddStackP(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_STACKP_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_RED_BLACK_TREEP_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddRedBlackTreePBool,                 \
  bool*:                 rbTreeAddRedBlackTreePBoolP,                \
  const volatile bool*:  rbTreeAddRedBlackTreePBoolP,                \
  i16:                   rbTreeAddRedBlackTreePI16,                  \
  i16*:                  rbTreeAddRedBlackTreePI16P,                 \
  const volatile i16*:   rbTreeAddRedBlackTreePI16P,                 \
  u16:                   rbTreeAddRedBlackTreePU16,                  \
  u16*:                  rbTreeAddRedBlackTreePU16P,                 \
  const volatile u16*:   rbTreeAddRedBlackTreePU16P,                 \
  i32:                   rbTreeAddRedBlackTreePI32,                  \
  i32*:                  rbTreeAddRedBlackTreePI32P,                 \
  const volatile i32*:   rbTreeAddRedBlackTreePI32P,                 \
  u32:                   rbTreeAddRedBlackTreePU32,                  \
  u32*:                  rbTreeAddRedBlackTreePU32P,                 \
  const volatile u32*:   rbTreeAddRedBlackTreePU32P,                 \
  i64:                   rbTreeAddRedBlackTreePI64,                  \
  i64*:                  rbTreeAddRedBlackTreePI64P,                 \
  const volatile i64*:   rbTreeAddRedBlackTreePI64P,                 \
  u64:                   rbTreeAddRedBlackTreePU64,                  \
  u64*:                  rbTreeAddRedBlackTreePU64P,                 \
  const volatile u64*:   rbTreeAddRedBlackTreePU64P,                 \
  float:                 rbTreeAddRedBlackTreePFloat,                \
  float*:                rbTreeAddRedBlackTreePFloatP,               \
  const volatile float*: rbTreeAddRedBlackTreePFloatP,               \
  double:                rbTreeAddRedBlackTreePDouble,               \
  double*:               rbTreeAddRedBlackTreePDoubleP,              \
  const volatile double*: rbTreeAddRedBlackTreePDoubleP,              \
  long double:           rbTreeAddRedBlackTreePLongDouble,           \
  long double*:          rbTreeAddRedBlackTreePLongDoubleP,          \
  const volatile long double*: rbTreeAddRedBlackTreePLongDoubleP,          \
  List:                  rbTreeAddRedBlackTreePList,                 \
  List*:                 rbTreeAddRedBlackTreePListP,                \
  const volatile List*:  rbTreeAddRedBlackTreePListP,                \
  Queue:                 rbTreeAddRedBlackTreePQueue,                \
  Queue*:                rbTreeAddRedBlackTreePQueueP,               \
  const volatile Queue*: rbTreeAddRedBlackTreePQueueP,               \
  Stack:                 rbTreeAddRedBlackTreePStack,                \
  Stack*:                rbTreeAddRedBlackTreePStackP,               \
  const volatile Stack*: rbTreeAddRedBlackTreePStackP,               \
  RedBlackTree:          rbTreeAddRedBlackTreePRedBlackTree,         \
  RedBlackTree*:         rbTreeAddRedBlackTreePRedBlackTreeP,        \
  const volatile RedBlackTree*: rbTreeAddRedBlackTreePRedBlackTreeP,        \
  HashTable:             rbTreeAddRedBlackTreePHashTable,            \
  HashTable*:            rbTreeAddRedBlackTreePHashTableP,           \
  const volatile HashTable*: rbTreeAddRedBlackTreePHashTableP,           \
  Vector:                rbTreeAddRedBlackTreePVector,               \
  Vector*:               rbTreeAddRedBlackTreePVectorP,              \
  const volatile Vector*: rbTreeAddRedBlackTreePVectorP,              \
  char*:                 rbTreeAddRedBlackTreePString,               \
  const volatile char*:  rbTreeAddRedBlackTreePString,               \
  char**:                rbTreeAddRedBlackTreePStringP,              \
  const volatile char**: rbTreeAddRedBlackTreePStringP,              \
  Bytes:                 rbTreeAddRedBlackTreePBytes,                \
  Bytes*:                rbTreeAddRedBlackTreePBytesP,               \
  const volatile Bytes*: rbTreeAddRedBlackTreePBytesP,               \
  void*:                 rbTreeAddRedBlackTreePPointer,              \
  void**:                rbTreeAddRedBlackTreePPointerP,             \
  const volatile void**: rbTreeAddRedBlackTreePPointerP,             \
  i8:                    rbTreeAddRedBlackTreeI8,                    \
  u8:                    rbTreeAddRedBlackTreeU8                     \

#define rbTreeAddRedBlackTreeP(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_RED_BLACK_TREEP_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_HASH_TABLEP_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddHashTablePBool,                    \
  bool*:                 rbTreeAddHashTablePBoolP,                   \
  const volatile bool*:  rbTreeAddHashTablePBoolP,                   \
  i16:                   rbTreeAddHashTablePI16,                     \
  i16*:                  rbTreeAddHashTablePI16P,                    \
  const volatile i16*:   rbTreeAddHashTablePI16P,                    \
  u16:                   rbTreeAddHashTablePU16,                     \
  u16*:                  rbTreeAddHashTablePU16P,                    \
  const volatile u16*:   rbTreeAddHashTablePU16P,                    \
  i32:                   rbTreeAddHashTablePI32,                     \
  i32*:                  rbTreeAddHashTablePI32P,                    \
  const volatile i32*:   rbTreeAddHashTablePI32P,                    \
  u32:                   rbTreeAddHashTablePU32,                     \
  u32*:                  rbTreeAddHashTablePU32P,                    \
  const volatile u32*:   rbTreeAddHashTablePU32P,                    \
  i64:                   rbTreeAddHashTablePI64,                     \
  i64*:                  rbTreeAddHashTablePI64P,                    \
  const volatile i64*:   rbTreeAddHashTablePI64P,                    \
  u64:                   rbTreeAddHashTablePU64,                     \
  u64*:                  rbTreeAddHashTablePU64P,                    \
  const volatile u64*:   rbTreeAddHashTablePU64P,                    \
  float:                 rbTreeAddHashTablePFloat,                   \
  float*:                rbTreeAddHashTablePFloatP,                  \
  const volatile float*: rbTreeAddHashTablePFloatP,                  \
  double:                rbTreeAddHashTablePDouble,                  \
  double*:               rbTreeAddHashTablePDoubleP,                 \
  const volatile double*: rbTreeAddHashTablePDoubleP,                 \
  long double:           rbTreeAddHashTablePLongDouble,              \
  long double*:          rbTreeAddHashTablePLongDoubleP,             \
  const volatile long double*: rbTreeAddHashTablePLongDoubleP,             \
  List:                  rbTreeAddHashTablePList,                    \
  List*:                 rbTreeAddHashTablePListP,                   \
  const volatile List*:  rbTreeAddHashTablePListP,                   \
  Queue:                 rbTreeAddHashTablePQueue,                   \
  Queue*:                rbTreeAddHashTablePQueueP,                  \
  const volatile Queue*: rbTreeAddHashTablePQueueP,                  \
  Stack:                 rbTreeAddHashTablePStack,                   \
  Stack*:                rbTreeAddHashTablePStackP,                  \
  const volatile Stack*: rbTreeAddHashTablePStackP,                  \
  RedBlackTree:          rbTreeAddHashTablePRedBlackTree,            \
  RedBlackTree*:         rbTreeAddHashTablePRedBlackTreeP,           \
  const volatile RedBlackTree*: rbTreeAddHashTablePRedBlackTreeP,           \
  HashTable:             rbTreeAddHashTablePHashTable,               \
  HashTable*:            rbTreeAddHashTablePHashTableP,              \
  const volatile HashTable*: rbTreeAddHashTablePHashTableP,              \
  Vector:                rbTreeAddHashTablePVector,                  \
  Vector*:               rbTreeAddHashTablePVectorP,                 \
  const volatile Vector*: rbTreeAddHashTablePVectorP,                 \
  char*:                 rbTreeAddHashTablePString,                  \
  const volatile char*:  rbTreeAddHashTablePString,                  \
  char**:                rbTreeAddHashTablePStringP,                 \
  const volatile char**: rbTreeAddHashTablePStringP,                 \
  Bytes:                 rbTreeAddHashTablePBytes,                   \
  Bytes*:                rbTreeAddHashTablePBytesP,                  \
  const volatile Bytes*: rbTreeAddHashTablePBytesP,                  \
  void*:                 rbTreeAddHashTablePPointer,                 \
  void**:                rbTreeAddHashTablePPointerP,                \
  const volatile void**: rbTreeAddHashTablePPointerP,                \
  i8:                    rbTreeAddHashTableI8,                       \
  u8:                    rbTreeAddHashTableU8                        \

#define rbTreeAddHashTableP(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_HASH_TABLEP_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_VECTORP_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddVectorPBool,                       \
  bool*:                 rbTreeAddVectorPBoolP,                      \
  const volatile bool*:  rbTreeAddVectorPBoolP,                      \
  i16:                   rbTreeAddVectorPI16,                        \
  i16*:                  rbTreeAddVectorPI16P,                       \
  const volatile i16*:   rbTreeAddVectorPI16P,                       \
  u16:                   rbTreeAddVectorPU16,                        \
  u16*:                  rbTreeAddVectorPU16P,                       \
  const volatile u16*:   rbTreeAddVectorPU16P,                       \
  i32:                   rbTreeAddVectorPI32,                        \
  i32*:                  rbTreeAddVectorPI32P,                       \
  const volatile i32*:   rbTreeAddVectorPI32P,                       \
  u32:                   rbTreeAddVectorPU32,                        \
  u32*:                  rbTreeAddVectorPU32P,                       \
  const volatile u32*:   rbTreeAddVectorPU32P,                       \
  i64:                   rbTreeAddVectorPI64,                        \
  i64*:                  rbTreeAddVectorPI64P,                       \
  const volatile i64*:   rbTreeAddVectorPI64P,                       \
  u64:                   rbTreeAddVectorPU64,                        \
  u64*:                  rbTreeAddVectorPU64P,                       \
  const volatile u64*:   rbTreeAddVectorPU64P,                       \
  float:                 rbTreeAddVectorPFloat,                      \
  float*:                rbTreeAddVectorPFloatP,                     \
  const volatile float*: rbTreeAddVectorPFloatP,                     \
  double:                rbTreeAddVectorPDouble,                     \
  double*:               rbTreeAddVectorPDoubleP,                    \
  const volatile double*: rbTreeAddVectorPDoubleP,                    \
  long double:           rbTreeAddVectorPLongDouble,                 \
  long double*:          rbTreeAddVectorPLongDoubleP,                \
  const volatile long double*: rbTreeAddVectorPLongDoubleP,                \
  List:                  rbTreeAddVectorPList,                       \
  List*:                 rbTreeAddVectorPListP,                      \
  const volatile List*:  rbTreeAddVectorPListP,                      \
  Queue:                 rbTreeAddVectorPQueue,                      \
  Queue*:                rbTreeAddVectorPQueueP,                     \
  const volatile Queue*: rbTreeAddVectorPQueueP,                     \
  Stack:                 rbTreeAddVectorPStack,                      \
  Stack*:                rbTreeAddVectorPStackP,                     \
  const volatile Stack*: rbTreeAddVectorPStackP,                     \
  RedBlackTree:          rbTreeAddVectorPRedBlackTree,               \
  RedBlackTree*:         rbTreeAddVectorPRedBlackTreeP,              \
  const volatile RedBlackTree*: rbTreeAddVectorPRedBlackTreeP,              \
  HashTable:             rbTreeAddVectorPHashTable,                  \
  HashTable*:            rbTreeAddVectorPHashTableP,                 \
  const volatile HashTable*: rbTreeAddVectorPHashTableP,                 \
  Vector:                rbTreeAddVectorPVector,                     \
  Vector*:               rbTreeAddVectorPVectorP,                    \
  const volatile Vector*: rbTreeAddVectorPVectorP,                    \
  char*:                 rbTreeAddVectorPString,                     \
  const volatile char*:  rbTreeAddVectorPString,                     \
  char**:                rbTreeAddVectorPStringP,                    \
  const volatile char**: rbTreeAddVectorPStringP,                    \
  Bytes:                 rbTreeAddVectorPBytes,                      \
  Bytes*:                rbTreeAddVectorPBytesP,                     \
  const volatile Bytes*: rbTreeAddVectorPBytesP,                     \
  void*:                 rbTreeAddVectorPPointer,                    \
  void**:                rbTreeAddVectorPPointerP,                   \
  const volatile void**: rbTreeAddVectorPPointerP,                   \
  i8:                    rbTreeAddVectorI8,                          \
  u8:                    rbTreeAddVectorU8                           \

#define rbTreeAddVectorP(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_VECTORP_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_STRINGP_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddStringPBool,                       \
  bool*:                 rbTreeAddStringPBoolP,                      \
  const volatile bool*:  rbTreeAddStringPBoolP,                      \
  i16:                   rbTreeAddStringPI16,                        \
  i16*:                  rbTreeAddStringPI16P,                       \
  const volatile i16*:   rbTreeAddStringPI16P,                       \
  u16:                   rbTreeAddStringPU16,                        \
  u16*:                  rbTreeAddStringPU16P,                       \
  const volatile u16*:   rbTreeAddStringPU16P,                       \
  i32:                   rbTreeAddStringPI32,                        \
  i32*:                  rbTreeAddStringPI32P,                       \
  const volatile i32*:   rbTreeAddStringPI32P,                       \
  u32:                   rbTreeAddStringPU32,                        \
  u32*:                  rbTreeAddStringPU32P,                       \
  const volatile u32*:   rbTreeAddStringPU32P,                       \
  i64:                   rbTreeAddStringPI64,                        \
  i64*:                  rbTreeAddStringPI64P,                       \
  const volatile i64*:   rbTreeAddStringPI64P,                       \
  u64:                   rbTreeAddStringPU64,                        \
  u64*:                  rbTreeAddStringPU64P,                       \
  const volatile u64*:   rbTreeAddStringPU64P,                       \
  float:                 rbTreeAddStringPFloat,                      \
  float*:                rbTreeAddStringPFloatP,                     \
  const volatile float*: rbTreeAddStringPFloatP,                     \
  double:                rbTreeAddStringPDouble,                     \
  double*:               rbTreeAddStringPDoubleP,                    \
  const volatile double*: rbTreeAddStringPDoubleP,                    \
  long double:           rbTreeAddStringPLongDouble,                 \
  long double*:          rbTreeAddStringPLongDoubleP,                \
  const volatile long double*: rbTreeAddStringPLongDoubleP,                \
  List:                  rbTreeAddStringPList,                       \
  List*:                 rbTreeAddStringPListP,                      \
  const volatile List*:  rbTreeAddStringPListP,                      \
  Queue:                 rbTreeAddStringPQueue,                      \
  Queue*:                rbTreeAddStringPQueueP,                     \
  const volatile Queue*: rbTreeAddStringPQueueP,                     \
  Stack:                 rbTreeAddStringPStack,                      \
  Stack*:                rbTreeAddStringPStackP,                     \
  const volatile Stack*: rbTreeAddStringPStackP,                     \
  RedBlackTree:          rbTreeAddStringPRedBlackTree,               \
  RedBlackTree*:         rbTreeAddStringPRedBlackTreeP,              \
  const volatile RedBlackTree*: rbTreeAddStringPRedBlackTreeP,              \
  HashTable:             rbTreeAddStringPHashTable,                  \
  HashTable*:            rbTreeAddStringPHashTableP,                 \
  const volatile HashTable*: rbTreeAddStringPHashTableP,                 \
  Vector:                rbTreeAddStringPVector,                     \
  Vector*:               rbTreeAddStringPVectorP,                    \
  const volatile Vector*: rbTreeAddStringPVectorP,                    \
  char*:                 rbTreeAddStringPString,                     \
  const volatile char*:  rbTreeAddStringPString,                     \
  char**:                rbTreeAddStringPStringP,                    \
  const volatile char**: rbTreeAddStringPStringP,                    \
  Bytes:                 rbTreeAddStringPBytes,                      \
  Bytes*:                rbTreeAddStringPBytesP,                     \
  const volatile Bytes*: rbTreeAddStringPBytesP,                     \
  void*:                 rbTreeAddStringPPointer,                    \
  void**:                rbTreeAddStringPPointerP,                   \
  const volatile void**: rbTreeAddStringPPointerP,                   \
  i8:                    rbTreeAddStringI8,                          \
  u8:                    rbTreeAddStringU8                           \

#define rbTreeAddStringP(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_STRINGP_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_BYTESP_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddBytesPBool,                        \
  bool*:                 rbTreeAddBytesPBoolP,                       \
  const volatile bool*:  rbTreeAddBytesPBoolP,                       \
  i16:                   rbTreeAddBytesPI16,                         \
  i16*:                  rbTreeAddBytesPI16P,                        \
  const volatile i16*:   rbTreeAddBytesPI16P,                        \
  u16:                   rbTreeAddBytesPU16,                         \
  u16*:                  rbTreeAddBytesPU16P,                        \
  const volatile u16*:   rbTreeAddBytesPU16P,                        \
  i32:                   rbTreeAddBytesPI32,                         \
  i32*:                  rbTreeAddBytesPI32P,                        \
  const volatile i32*:   rbTreeAddBytesPI32P,                        \
  u32:                   rbTreeAddBytesPU32,                         \
  u32*:                  rbTreeAddBytesPU32P,                        \
  const volatile u32*:   rbTreeAddBytesPU32P,                        \
  i64:                   rbTreeAddBytesPI64,                         \
  i64*:                  rbTreeAddBytesPI64P,                        \
  const volatile i64*:   rbTreeAddBytesPI64P,                        \
  u64:                   rbTreeAddBytesPU64,                         \
  u64*:                  rbTreeAddBytesPU64P,                        \
  const volatile u64*:   rbTreeAddBytesPU64P,                        \
  float:                 rbTreeAddBytesPFloat,                       \
  float*:                rbTreeAddBytesPFloatP,                      \
  const volatile float*: rbTreeAddBytesPFloatP,                      \
  double:                rbTreeAddBytesPDouble,                      \
  double*:               rbTreeAddBytesPDoubleP,                     \
  const volatile double*: rbTreeAddBytesPDoubleP,                     \
  long double:           rbTreeAddBytesPLongDouble,                  \
  long double*:          rbTreeAddBytesPLongDoubleP,                 \
  const volatile long double*: rbTreeAddBytesPLongDoubleP,                 \
  List:                  rbTreeAddBytesPList,                        \
  List*:                 rbTreeAddBytesPListP,                       \
  const volatile List*:  rbTreeAddBytesPListP,                       \
  Queue:                 rbTreeAddBytesPQueue,                       \
  Queue*:                rbTreeAddBytesPQueueP,                      \
  const volatile Queue*: rbTreeAddBytesPQueueP,                      \
  Stack:                 rbTreeAddBytesPStack,                       \
  Stack*:                rbTreeAddBytesPStackP,                      \
  const volatile Stack*: rbTreeAddBytesPStackP,                      \
  RedBlackTree:          rbTreeAddBytesPRedBlackTree,                \
  RedBlackTree*:         rbTreeAddBytesPRedBlackTreeP,               \
  const volatile RedBlackTree*: rbTreeAddBytesPRedBlackTreeP,               \
  HashTable:             rbTreeAddBytesPHashTable,                   \
  HashTable*:            rbTreeAddBytesPHashTableP,                  \
  const volatile HashTable*: rbTreeAddBytesPHashTableP,                  \
  Vector:                rbTreeAddBytesPVector,                      \
  Vector*:               rbTreeAddBytesPVectorP,                     \
  const volatile Vector*: rbTreeAddBytesPVectorP,                     \
  char*:                 rbTreeAddBytesPString,                      \
  const volatile char*:  rbTreeAddBytesPString,                      \
  char**:                rbTreeAddBytesPStringP,                     \
  const volatile char**: rbTreeAddBytesPStringP,                     \
  Bytes:                 rbTreeAddBytesPBytes,                       \
  Bytes*:                rbTreeAddBytesPBytesP,                      \
  const volatile Bytes*: rbTreeAddBytesPBytesP,                      \
  void*:                 rbTreeAddBytesPPointer,                     \
  void**:                rbTreeAddBytesPPointerP,                    \
  const volatile void**: rbTreeAddBytesPPointerP,                    \
  i8:                    rbTreeAddBytesI8,                           \
  u8:                    rbTreeAddBytesU8                            \

#define rbTreeAddBytesP(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_BYTESP_KEY(dataStructure, key, value) \
  )

#define RB_TREE_ADD_GENERIC_CASES_POINTERP_KEY(dataStructure, key, value) \
  bool:                  rbTreeAddPointerPBool,                      \
  bool*:                 rbTreeAddPointerPBoolP,                     \
  const volatile bool*:  rbTreeAddPointerPBoolP,                     \
  i16:                   rbTreeAddPointerPI16,                       \
  i16*:                  rbTreeAddPointerPI16P,                      \
  const volatile i16*:   rbTreeAddPointerPI16P,                      \
  u16:                   rbTreeAddPointerPU16,                       \
  u16*:                  rbTreeAddPointerPU16P,                      \
  const volatile u16*:   rbTreeAddPointerPU16P,                      \
  i32:                   rbTreeAddPointerPI32,                       \
  i32*:                  rbTreeAddPointerPI32P,                      \
  const volatile i32*:   rbTreeAddPointerPI32P,                      \
  u32:                   rbTreeAddPointerPU32,                       \
  u32*:                  rbTreeAddPointerPU32P,                      \
  const volatile u32*:   rbTreeAddPointerPU32P,                      \
  i64:                   rbTreeAddPointerPI64,                       \
  i64*:                  rbTreeAddPointerPI64P,                      \
  const volatile i64*:   rbTreeAddPointerPI64P,                      \
  u64:                   rbTreeAddPointerPU64,                       \
  u64*:                  rbTreeAddPointerPU64P,                      \
  const volatile u64*:   rbTreeAddPointerPU64P,                      \
  float:                 rbTreeAddPointerPFloat,                     \
  float*:                rbTreeAddPointerPFloatP,                    \
  const volatile float*: rbTreeAddPointerPFloatP,                    \
  double:                rbTreeAddPointerPDouble,                    \
  double*:               rbTreeAddPointerPDoubleP,                   \
  const volatile double*: rbTreeAddPointerPDoubleP,                   \
  long double:           rbTreeAddPointerPLongDouble,                \
  long double*:          rbTreeAddPointerPLongDoubleP,               \
  const volatile long double*: rbTreeAddPointerPLongDoubleP,               \
  List:                  rbTreeAddPointerPList,                      \
  List*:                 rbTreeAddPointerPListP,                     \
  const volatile List*:  rbTreeAddPointerPListP,                     \
  Queue:                 rbTreeAddPointerPQueue,                     \
  Queue*:                rbTreeAddPointerPQueueP,                    \
  const volatile Queue*: rbTreeAddPointerPQueueP,                    \
  Stack:                 rbTreeAddPointerPStack,                     \
  Stack*:                rbTreeAddPointerPStackP,                    \
  const volatile Stack*: rbTreeAddPointerPStackP,                    \
  RedBlackTree:          rbTreeAddPointerPRedBlackTree,              \
  RedBlackTree*:         rbTreeAddPointerPRedBlackTreeP,             \
  const volatile RedBlackTree*: rbTreeAddPointerPRedBlackTreeP,             \
  HashTable:             rbTreeAddPointerPHashTable,                 \
  HashTable*:            rbTreeAddPointerPHashTableP,                \
  const volatile HashTable*: rbTreeAddPointerPHashTableP,                \
  Vector:                rbTreeAddPointerPVector,                    \
  Vector*:               rbTreeAddPointerPVectorP,                   \
  const volatile Vector*: rbTreeAddPointerPVectorP,                   \
  char*:                 rbTreeAddPointerPString,                    \
  const volatile char*:  rbTreeAddPointerPString,                    \
  char**:                rbTreeAddPointerPStringP,                   \
  const volatile char**: rbTreeAddPointerPStringP,                   \
  Bytes:                 rbTreeAddPointerPBytes,                     \
  Bytes*:                rbTreeAddPointerPBytesP,                    \
  const volatile Bytes*: rbTreeAddPointerPBytesP,                    \
  void*:                 rbTreeAddPointerPPointer,                   \
  void**:                rbTreeAddPointerPPointerP,                  \
  const volatile void**: rbTreeAddPointerPPointerP,                  \
  i8:                    rbTreeAddPointerI8,                         \
  u8:                    rbTreeAddPointerU8                          \

#define rbTreeAddPointerP(dataStructure, key, value) _Generic((value), \
  RB_TREE_ADD_GENERIC_CASES_POINTERP_KEY(dataStructure, key, value) \
  )


#define RB_TREE_ADD_GENERIC_CASES(dataStructure, key, value) \
  bool:                  rbTreeAddBool(dataStructure, key, value),   \
  bool*:                 rbTreeAddBoolP(dataStructure, key, value),  \
  const volatile bool*:  rbTreeAddBoolP(dataStructure, key, value),  \
  i16:                   rbTreeAddI16(dataStructure, key, value),    \
  i16*:                  rbTreeAddI16P(dataStructure, key, value),   \
  const volatile i16*:   rbTreeAddI16P(dataStructure, key, value),   \
  u16:                   rbTreeAddU16(dataStructure, key, value),    \
  u16*:                  rbTreeAddU16P(dataStructure, key, value),   \
  const volatile u16*:   rbTreeAddU16P(dataStructure, key, value),   \
  i32:                   rbTreeAddI32(dataStructure, key, value),    \
  i32*:                  rbTreeAddI32P(dataStructure, key, value),   \
  const volatile i32*:   rbTreeAddI32P(dataStructure, key, value),   \
  u32:                   rbTreeAddU32(dataStructure, key, value),    \
  u32*:                  rbTreeAddU32P(dataStructure, key, value),   \
  const volatile u32*:   rbTreeAddU32P(dataStructure, key, value),   \
  i64:                   rbTreeAddI64(dataStructure, key, value),    \
  i64*:                  rbTreeAddI64P(dataStructure, key, value),   \
  const volatile i64*:   rbTreeAddI64P(dataStructure, key, value),   \
  u64:                   rbTreeAddU64(dataStructure, key, value),    \
  u64*:                  rbTreeAddU64P(dataStructure, key, value),   \
  const volatile u64*:   rbTreeAddU64P(dataStructure, key, value),   \
  float:                 rbTreeAddFloat(dataStructure, key, value),  \
  float*:                rbTreeAddFloatP(dataStructure, key, value), \
  const volatile float*: rbTreeAddFloatP(dataStructure, key, value), \
  double:                rbTreeAddDouble(dataStructure, key, value), \
  double*:               rbTreeAddDoubleP(dataStructure, key, value), \
  const volatile double*: rbTreeAddDoubleP(dataStructure, key, value), \
  long double:           rbTreeAddLongDouble(dataStructure, key, value), \
  long double*:          rbTreeAddLongDoubleP(dataStructure, key, value), \
  const volatile long double*: rbTreeAddLongDoubleP(dataStructure, key, value), \
  List:                  rbTreeAddList(dataStructure, key, value),   \
  List*:                 rbTreeAddListP(dataStructure, key, value),  \
  const volatile List*:  rbTreeAddListP(dataStructure, key, value),  \
  Queue:                 rbTreeAddQueue(dataStructure, key, value),  \
  Queue*:                rbTreeAddQueueP(dataStructure, key, value), \
  const volatile Queue*: rbTreeAddQueueP(dataStructure, key, value), \
  Stack:                 rbTreeAddStack(dataStructure, key, value),  \
  Stack*:                rbTreeAddStackP(dataStructure, key, value), \
  const volatile Stack*: rbTreeAddStackP(dataStructure, key, value), \
  RedBlackTree:          rbTreeAddRedBlackTree(dataStructure, key, value), \
  RedBlackTree*:         rbTreeAddRedBlackTreeP(dataStructure, key, value), \
  const volatile RedBlackTree*: rbTreeAddRedBlackTreeP(dataStructure, key, value), \
  HashTable:             rbTreeAddHashTable(dataStructure, key, value), \
  HashTable*:            rbTreeAddHashTableP(dataStructure, key, value), \
  const volatile HashTable*: rbTreeAddHashTableP(dataStructure, key, value), \
  Vector:                rbTreeAddVector(dataStructure, key, value), \
  Vector*:               rbTreeAddVectorP(dataStructure, key, value), \
  const volatile Vector*: rbTreeAddVectorP(dataStructure, key, value), \
  char*:                 rbTreeAddString(dataStructure, key, value), \
  const volatile char*:  rbTreeAddString(dataStructure, key, value), \
  char**:                rbTreeAddStringP(dataStructure, key, value), \
  const volatile char**: rbTreeAddStringP(dataStructure, key, value), \
  Bytes:                 rbTreeAddBytes(dataStructure, key, value),  \
  Bytes*:                rbTreeAddBytesP(dataStructure, key, value), \
  const volatile Bytes*: rbTreeAddBytesP(dataStructure, key, value), \
  void*:                 rbTreeAddPointer(dataStructure, key, value), \
  void**:                rbTreeAddPointerP(dataStructure, key, value), \
  const volatile void**: rbTreeAddPointerP(dataStructure, key, value), \
  i8:                    rbTreeAddI8(dataStructure, key, value),     \
  u8:                    rbTreeAddU8(dataStructure, key, value)      \

#define rbTreeAdd(dataStructure, key, value) _Generic((key), \
  RB_TREE_ADD_GENERIC_CASES(dataStructure, key, value) \
  )(dataStructure, key, value)

#endif // __STDC_VERSION__

#elif defined __cplusplus // __STDC_VERSION__ is *NOT* defined
#define TYPE_SAFE_RED_BLACK_TREE

// Define the C++ function overloads.

static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, bool value) {
  return rbTreeAddBoolBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile bool* value) {
  return rbTreeAddBoolBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, bool value) {
  return rbTreeAddBoolPBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile bool* value) {
  return rbTreeAddBoolPBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, i16 value) {
  return rbTreeAddBoolI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile i16* value) {
  return rbTreeAddBoolI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, i16 value) {
  return rbTreeAddBoolPI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile i16* value) {
  return rbTreeAddBoolPI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, u16 value) {
  return rbTreeAddBoolU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile u16* value) {
  return rbTreeAddBoolU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, u16 value) {
  return rbTreeAddBoolPU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile u16* value) {
  return rbTreeAddBoolPU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, i32 value) {
  return rbTreeAddBoolI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile i32* value) {
  return rbTreeAddBoolI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, i32 value) {
  return rbTreeAddBoolPI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile i32* value) {
  return rbTreeAddBoolPI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, u32 value) {
  return rbTreeAddBoolU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile u32* value) {
  return rbTreeAddBoolU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, u32 value) {
  return rbTreeAddBoolPU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile u32* value) {
  return rbTreeAddBoolPU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, i64 value) {
  return rbTreeAddBoolI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile i64* value) {
  return rbTreeAddBoolI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, i64 value) {
  return rbTreeAddBoolPI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile i64* value) {
  return rbTreeAddBoolPI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, u64 value) {
  return rbTreeAddBoolU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile u64* value) {
  return rbTreeAddBoolU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, u64 value) {
  return rbTreeAddBoolPU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile u64* value) {
  return rbTreeAddBoolPU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, float value) {
  return rbTreeAddBoolFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile float* value) {
  return rbTreeAddBoolFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, float value) {
  return rbTreeAddBoolPFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile float* value) {
  return rbTreeAddBoolPFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, double value) {
  return rbTreeAddBoolDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile double* value) {
  return rbTreeAddBoolDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, double value) {
  return rbTreeAddBoolPDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile double* value) {
  return rbTreeAddBoolPDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, long double value) {
  return rbTreeAddBoolLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile long double* value) {
  return rbTreeAddBoolLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, long double value) {
  return rbTreeAddBoolPLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile long double* value) {
  return rbTreeAddBoolPLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, List value) {
  return rbTreeAddBoolList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile List* value) {
  return rbTreeAddBoolListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, List value) {
  return rbTreeAddBoolPList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile List* value) {
  return rbTreeAddBoolPListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, Queue value) {
  return rbTreeAddBoolQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile Queue* value) {
  return rbTreeAddBoolQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, Queue value) {
  return rbTreeAddBoolPQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile Queue* value) {
  return rbTreeAddBoolPQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, Stack value) {
  return rbTreeAddBoolStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile Stack* value) {
  return rbTreeAddBoolStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, Stack value) {
  return rbTreeAddBoolPStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile Stack* value) {
  return rbTreeAddBoolPStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, RedBlackTree value) {
  return rbTreeAddBoolRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile RedBlackTree* value) {
  return rbTreeAddBoolRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, RedBlackTree value) {
  return rbTreeAddBoolPRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile RedBlackTree* value) {
  return rbTreeAddBoolPRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, HashTable value) {
  return rbTreeAddBoolHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile HashTable* value) {
  return rbTreeAddBoolHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, HashTable value) {
  return rbTreeAddBoolPHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile HashTable* value) {
  return rbTreeAddBoolPHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, Vector value) {
  return rbTreeAddBoolVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile Vector* value) {
  return rbTreeAddBoolVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, Vector value) {
  return rbTreeAddBoolPVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile Vector* value) {
  return rbTreeAddBoolPVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile char* value) {
  return rbTreeAddBoolString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile char** value) {
  return rbTreeAddBoolStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile char* value) {
  return rbTreeAddBoolPString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile char** value) {
  return rbTreeAddBoolPStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, Bytes value) {
  return rbTreeAddBoolBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile Bytes* value) {
  return rbTreeAddBoolBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, Bytes value) {
  return rbTreeAddBoolPBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile Bytes* value) {
  return rbTreeAddBoolPBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, void* value) {
  return rbTreeAddBoolPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, const volatile void** value) {
  return rbTreeAddBoolPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, void* value) {
  return rbTreeAddBoolPPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, const volatile void** value) {
  return rbTreeAddBoolPPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, i8 value) {
  return rbTreeAddBoolI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, i8 value) {
  return rbTreeAddBoolPI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, bool key, u8 value) {
  return rbTreeAddBoolU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile bool* key, u8 value) {
  return rbTreeAddBoolPU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, bool value) {
  return rbTreeAddI16Bool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile bool* value) {
  return rbTreeAddI16BoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, bool value) {
  return rbTreeAddI16PBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile bool* value) {
  return rbTreeAddI16PBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, i16 value) {
  return rbTreeAddI16I16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile i16* value) {
  return rbTreeAddI16I16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, i16 value) {
  return rbTreeAddI16PI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile i16* value) {
  return rbTreeAddI16PI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, u16 value) {
  return rbTreeAddI16U16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile u16* value) {
  return rbTreeAddI16U16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, u16 value) {
  return rbTreeAddI16PU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile u16* value) {
  return rbTreeAddI16PU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, i32 value) {
  return rbTreeAddI16I32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile i32* value) {
  return rbTreeAddI16I32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, i32 value) {
  return rbTreeAddI16PI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile i32* value) {
  return rbTreeAddI16PI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, u32 value) {
  return rbTreeAddI16U32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile u32* value) {
  return rbTreeAddI16U32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, u32 value) {
  return rbTreeAddI16PU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile u32* value) {
  return rbTreeAddI16PU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, i64 value) {
  return rbTreeAddI16I64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile i64* value) {
  return rbTreeAddI16I64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, i64 value) {
  return rbTreeAddI16PI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile i64* value) {
  return rbTreeAddI16PI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, u64 value) {
  return rbTreeAddI16U64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile u64* value) {
  return rbTreeAddI16U64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, u64 value) {
  return rbTreeAddI16PU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile u64* value) {
  return rbTreeAddI16PU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, float value) {
  return rbTreeAddI16Float(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile float* value) {
  return rbTreeAddI16FloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, float value) {
  return rbTreeAddI16PFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile float* value) {
  return rbTreeAddI16PFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, double value) {
  return rbTreeAddI16Double(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile double* value) {
  return rbTreeAddI16DoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, double value) {
  return rbTreeAddI16PDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile double* value) {
  return rbTreeAddI16PDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, long double value) {
  return rbTreeAddI16LongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile long double* value) {
  return rbTreeAddI16LongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, long double value) {
  return rbTreeAddI16PLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile long double* value) {
  return rbTreeAddI16PLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, List value) {
  return rbTreeAddI16List(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile List* value) {
  return rbTreeAddI16ListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, List value) {
  return rbTreeAddI16PList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile List* value) {
  return rbTreeAddI16PListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, Queue value) {
  return rbTreeAddI16Queue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile Queue* value) {
  return rbTreeAddI16QueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, Queue value) {
  return rbTreeAddI16PQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile Queue* value) {
  return rbTreeAddI16PQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, Stack value) {
  return rbTreeAddI16Stack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile Stack* value) {
  return rbTreeAddI16StackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, Stack value) {
  return rbTreeAddI16PStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile Stack* value) {
  return rbTreeAddI16PStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, RedBlackTree value) {
  return rbTreeAddI16RedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile RedBlackTree* value) {
  return rbTreeAddI16RedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, RedBlackTree value) {
  return rbTreeAddI16PRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile RedBlackTree* value) {
  return rbTreeAddI16PRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, HashTable value) {
  return rbTreeAddI16HashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile HashTable* value) {
  return rbTreeAddI16HashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, HashTable value) {
  return rbTreeAddI16PHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile HashTable* value) {
  return rbTreeAddI16PHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, Vector value) {
  return rbTreeAddI16Vector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile Vector* value) {
  return rbTreeAddI16VectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, Vector value) {
  return rbTreeAddI16PVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile Vector* value) {
  return rbTreeAddI16PVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile char* value) {
  return rbTreeAddI16String(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile char** value) {
  return rbTreeAddI16StringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile char* value) {
  return rbTreeAddI16PString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile char** value) {
  return rbTreeAddI16PStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, Bytes value) {
  return rbTreeAddI16Bytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile Bytes* value) {
  return rbTreeAddI16BytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, Bytes value) {
  return rbTreeAddI16PBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile Bytes* value) {
  return rbTreeAddI16PBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, void* value) {
  return rbTreeAddI16Pointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, const volatile void** value) {
  return rbTreeAddI16PointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, void* value) {
  return rbTreeAddI16PPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, const volatile void** value) {
  return rbTreeAddI16PPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, i8 value) {
  return rbTreeAddI16I8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, i8 value) {
  return rbTreeAddI16PI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i16 key, u8 value) {
  return rbTreeAddI16U8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i16* key, u8 value) {
  return rbTreeAddI16PU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, bool value) {
  return rbTreeAddU16Bool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile bool* value) {
  return rbTreeAddU16BoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, bool value) {
  return rbTreeAddU16PBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile bool* value) {
  return rbTreeAddU16PBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, i16 value) {
  return rbTreeAddU16I16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile i16* value) {
  return rbTreeAddU16I16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, i16 value) {
  return rbTreeAddU16PI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile i16* value) {
  return rbTreeAddU16PI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, u16 value) {
  return rbTreeAddU16U16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile u16* value) {
  return rbTreeAddU16U16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, u16 value) {
  return rbTreeAddU16PU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile u16* value) {
  return rbTreeAddU16PU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, i32 value) {
  return rbTreeAddU16I32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile i32* value) {
  return rbTreeAddU16I32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, i32 value) {
  return rbTreeAddU16PI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile i32* value) {
  return rbTreeAddU16PI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, u32 value) {
  return rbTreeAddU16U32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile u32* value) {
  return rbTreeAddU16U32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, u32 value) {
  return rbTreeAddU16PU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile u32* value) {
  return rbTreeAddU16PU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, i64 value) {
  return rbTreeAddU16I64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile i64* value) {
  return rbTreeAddU16I64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, i64 value) {
  return rbTreeAddU16PI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile i64* value) {
  return rbTreeAddU16PI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, u64 value) {
  return rbTreeAddU16U64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile u64* value) {
  return rbTreeAddU16U64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, u64 value) {
  return rbTreeAddU16PU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile u64* value) {
  return rbTreeAddU16PU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, float value) {
  return rbTreeAddU16Float(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile float* value) {
  return rbTreeAddU16FloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, float value) {
  return rbTreeAddU16PFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile float* value) {
  return rbTreeAddU16PFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, double value) {
  return rbTreeAddU16Double(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile double* value) {
  return rbTreeAddU16DoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, double value) {
  return rbTreeAddU16PDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile double* value) {
  return rbTreeAddU16PDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, long double value) {
  return rbTreeAddU16LongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile long double* value) {
  return rbTreeAddU16LongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, long double value) {
  return rbTreeAddU16PLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile long double* value) {
  return rbTreeAddU16PLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, List value) {
  return rbTreeAddU16List(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile List* value) {
  return rbTreeAddU16ListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, List value) {
  return rbTreeAddU16PList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile List* value) {
  return rbTreeAddU16PListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, Queue value) {
  return rbTreeAddU16Queue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile Queue* value) {
  return rbTreeAddU16QueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, Queue value) {
  return rbTreeAddU16PQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile Queue* value) {
  return rbTreeAddU16PQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, Stack value) {
  return rbTreeAddU16Stack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile Stack* value) {
  return rbTreeAddU16StackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, Stack value) {
  return rbTreeAddU16PStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile Stack* value) {
  return rbTreeAddU16PStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, RedBlackTree value) {
  return rbTreeAddU16RedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile RedBlackTree* value) {
  return rbTreeAddU16RedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, RedBlackTree value) {
  return rbTreeAddU16PRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile RedBlackTree* value) {
  return rbTreeAddU16PRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, HashTable value) {
  return rbTreeAddU16HashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile HashTable* value) {
  return rbTreeAddU16HashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, HashTable value) {
  return rbTreeAddU16PHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile HashTable* value) {
  return rbTreeAddU16PHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, Vector value) {
  return rbTreeAddU16Vector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile Vector* value) {
  return rbTreeAddU16VectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, Vector value) {
  return rbTreeAddU16PVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile Vector* value) {
  return rbTreeAddU16PVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile char* value) {
  return rbTreeAddU16String(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile char** value) {
  return rbTreeAddU16StringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile char* value) {
  return rbTreeAddU16PString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile char** value) {
  return rbTreeAddU16PStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, Bytes value) {
  return rbTreeAddU16Bytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile Bytes* value) {
  return rbTreeAddU16BytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, Bytes value) {
  return rbTreeAddU16PBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile Bytes* value) {
  return rbTreeAddU16PBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, void* value) {
  return rbTreeAddU16Pointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, const volatile void** value) {
  return rbTreeAddU16PointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, void* value) {
  return rbTreeAddU16PPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, const volatile void** value) {
  return rbTreeAddU16PPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, i8 value) {
  return rbTreeAddU16I8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, i8 value) {
  return rbTreeAddU16PI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u16 key, u8 value) {
  return rbTreeAddU16U8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u16* key, u8 value) {
  return rbTreeAddU16PU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, bool value) {
  return rbTreeAddI32Bool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile bool* value) {
  return rbTreeAddI32BoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, bool value) {
  return rbTreeAddI32PBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile bool* value) {
  return rbTreeAddI32PBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, i16 value) {
  return rbTreeAddI32I16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile i16* value) {
  return rbTreeAddI32I16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, i16 value) {
  return rbTreeAddI32PI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile i16* value) {
  return rbTreeAddI32PI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, u16 value) {
  return rbTreeAddI32U16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile u16* value) {
  return rbTreeAddI32U16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, u16 value) {
  return rbTreeAddI32PU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile u16* value) {
  return rbTreeAddI32PU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, i32 value) {
  return rbTreeAddI32I32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile i32* value) {
  return rbTreeAddI32I32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, i32 value) {
  return rbTreeAddI32PI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile i32* value) {
  return rbTreeAddI32PI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, u32 value) {
  return rbTreeAddI32U32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile u32* value) {
  return rbTreeAddI32U32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, u32 value) {
  return rbTreeAddI32PU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile u32* value) {
  return rbTreeAddI32PU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, i64 value) {
  return rbTreeAddI32I64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile i64* value) {
  return rbTreeAddI32I64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, i64 value) {
  return rbTreeAddI32PI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile i64* value) {
  return rbTreeAddI32PI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, u64 value) {
  return rbTreeAddI32U64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile u64* value) {
  return rbTreeAddI32U64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, u64 value) {
  return rbTreeAddI32PU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile u64* value) {
  return rbTreeAddI32PU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, float value) {
  return rbTreeAddI32Float(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile float* value) {
  return rbTreeAddI32FloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, float value) {
  return rbTreeAddI32PFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile float* value) {
  return rbTreeAddI32PFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, double value) {
  return rbTreeAddI32Double(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile double* value) {
  return rbTreeAddI32DoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, double value) {
  return rbTreeAddI32PDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile double* value) {
  return rbTreeAddI32PDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, long double value) {
  return rbTreeAddI32LongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile long double* value) {
  return rbTreeAddI32LongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, long double value) {
  return rbTreeAddI32PLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile long double* value) {
  return rbTreeAddI32PLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, List value) {
  return rbTreeAddI32List(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile List* value) {
  return rbTreeAddI32ListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, List value) {
  return rbTreeAddI32PList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile List* value) {
  return rbTreeAddI32PListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, Queue value) {
  return rbTreeAddI32Queue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile Queue* value) {
  return rbTreeAddI32QueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, Queue value) {
  return rbTreeAddI32PQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile Queue* value) {
  return rbTreeAddI32PQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, Stack value) {
  return rbTreeAddI32Stack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile Stack* value) {
  return rbTreeAddI32StackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, Stack value) {
  return rbTreeAddI32PStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile Stack* value) {
  return rbTreeAddI32PStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, RedBlackTree value) {
  return rbTreeAddI32RedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile RedBlackTree* value) {
  return rbTreeAddI32RedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, RedBlackTree value) {
  return rbTreeAddI32PRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile RedBlackTree* value) {
  return rbTreeAddI32PRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, HashTable value) {
  return rbTreeAddI32HashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile HashTable* value) {
  return rbTreeAddI32HashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, HashTable value) {
  return rbTreeAddI32PHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile HashTable* value) {
  return rbTreeAddI32PHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, Vector value) {
  return rbTreeAddI32Vector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile Vector* value) {
  return rbTreeAddI32VectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, Vector value) {
  return rbTreeAddI32PVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile Vector* value) {
  return rbTreeAddI32PVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile char* value) {
  return rbTreeAddI32String(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile char** value) {
  return rbTreeAddI32StringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile char* value) {
  return rbTreeAddI32PString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile char** value) {
  return rbTreeAddI32PStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, Bytes value) {
  return rbTreeAddI32Bytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile Bytes* value) {
  return rbTreeAddI32BytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, Bytes value) {
  return rbTreeAddI32PBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile Bytes* value) {
  return rbTreeAddI32PBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, void* value) {
  return rbTreeAddI32Pointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, const volatile void** value) {
  return rbTreeAddI32PointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, void* value) {
  return rbTreeAddI32PPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, const volatile void** value) {
  return rbTreeAddI32PPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, i8 value) {
  return rbTreeAddI32I8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, i8 value) {
  return rbTreeAddI32PI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i32 key, u8 value) {
  return rbTreeAddI32U8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i32* key, u8 value) {
  return rbTreeAddI32PU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, bool value) {
  return rbTreeAddU32Bool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile bool* value) {
  return rbTreeAddU32BoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, bool value) {
  return rbTreeAddU32PBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile bool* value) {
  return rbTreeAddU32PBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, i16 value) {
  return rbTreeAddU32I16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile i16* value) {
  return rbTreeAddU32I16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, i16 value) {
  return rbTreeAddU32PI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile i16* value) {
  return rbTreeAddU32PI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, u16 value) {
  return rbTreeAddU32U16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile u16* value) {
  return rbTreeAddU32U16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, u16 value) {
  return rbTreeAddU32PU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile u16* value) {
  return rbTreeAddU32PU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, i32 value) {
  return rbTreeAddU32I32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile i32* value) {
  return rbTreeAddU32I32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, i32 value) {
  return rbTreeAddU32PI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile i32* value) {
  return rbTreeAddU32PI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, u32 value) {
  return rbTreeAddU32U32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile u32* value) {
  return rbTreeAddU32U32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, u32 value) {
  return rbTreeAddU32PU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile u32* value) {
  return rbTreeAddU32PU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, i64 value) {
  return rbTreeAddU32I64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile i64* value) {
  return rbTreeAddU32I64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, i64 value) {
  return rbTreeAddU32PI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile i64* value) {
  return rbTreeAddU32PI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, u64 value) {
  return rbTreeAddU32U64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile u64* value) {
  return rbTreeAddU32U64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, u64 value) {
  return rbTreeAddU32PU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile u64* value) {
  return rbTreeAddU32PU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, float value) {
  return rbTreeAddU32Float(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile float* value) {
  return rbTreeAddU32FloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, float value) {
  return rbTreeAddU32PFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile float* value) {
  return rbTreeAddU32PFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, double value) {
  return rbTreeAddU32Double(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile double* value) {
  return rbTreeAddU32DoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, double value) {
  return rbTreeAddU32PDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile double* value) {
  return rbTreeAddU32PDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, long double value) {
  return rbTreeAddU32LongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile long double* value) {
  return rbTreeAddU32LongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, long double value) {
  return rbTreeAddU32PLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile long double* value) {
  return rbTreeAddU32PLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, List value) {
  return rbTreeAddU32List(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile List* value) {
  return rbTreeAddU32ListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, List value) {
  return rbTreeAddU32PList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile List* value) {
  return rbTreeAddU32PListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, Queue value) {
  return rbTreeAddU32Queue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile Queue* value) {
  return rbTreeAddU32QueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, Queue value) {
  return rbTreeAddU32PQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile Queue* value) {
  return rbTreeAddU32PQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, Stack value) {
  return rbTreeAddU32Stack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile Stack* value) {
  return rbTreeAddU32StackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, Stack value) {
  return rbTreeAddU32PStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile Stack* value) {
  return rbTreeAddU32PStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, RedBlackTree value) {
  return rbTreeAddU32RedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile RedBlackTree* value) {
  return rbTreeAddU32RedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, RedBlackTree value) {
  return rbTreeAddU32PRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile RedBlackTree* value) {
  return rbTreeAddU32PRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, HashTable value) {
  return rbTreeAddU32HashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile HashTable* value) {
  return rbTreeAddU32HashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, HashTable value) {
  return rbTreeAddU32PHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile HashTable* value) {
  return rbTreeAddU32PHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, Vector value) {
  return rbTreeAddU32Vector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile Vector* value) {
  return rbTreeAddU32VectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, Vector value) {
  return rbTreeAddU32PVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile Vector* value) {
  return rbTreeAddU32PVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile char* value) {
  return rbTreeAddU32String(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile char** value) {
  return rbTreeAddU32StringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile char* value) {
  return rbTreeAddU32PString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile char** value) {
  return rbTreeAddU32PStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, Bytes value) {
  return rbTreeAddU32Bytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile Bytes* value) {
  return rbTreeAddU32BytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, Bytes value) {
  return rbTreeAddU32PBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile Bytes* value) {
  return rbTreeAddU32PBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, void* value) {
  return rbTreeAddU32Pointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, const volatile void** value) {
  return rbTreeAddU32PointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, void* value) {
  return rbTreeAddU32PPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, const volatile void** value) {
  return rbTreeAddU32PPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, i8 value) {
  return rbTreeAddU32I8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, i8 value) {
  return rbTreeAddU32PI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u32 key, u8 value) {
  return rbTreeAddU32U8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u32* key, u8 value) {
  return rbTreeAddU32PU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, bool value) {
  return rbTreeAddI64Bool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile bool* value) {
  return rbTreeAddI64BoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, bool value) {
  return rbTreeAddI64PBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile bool* value) {
  return rbTreeAddI64PBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, i16 value) {
  return rbTreeAddI64I16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile i16* value) {
  return rbTreeAddI64I16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, i16 value) {
  return rbTreeAddI64PI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile i16* value) {
  return rbTreeAddI64PI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, u16 value) {
  return rbTreeAddI64U16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile u16* value) {
  return rbTreeAddI64U16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, u16 value) {
  return rbTreeAddI64PU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile u16* value) {
  return rbTreeAddI64PU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, i32 value) {
  return rbTreeAddI64I32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile i32* value) {
  return rbTreeAddI64I32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, i32 value) {
  return rbTreeAddI64PI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile i32* value) {
  return rbTreeAddI64PI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, u32 value) {
  return rbTreeAddI64U32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile u32* value) {
  return rbTreeAddI64U32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, u32 value) {
  return rbTreeAddI64PU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile u32* value) {
  return rbTreeAddI64PU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, i64 value) {
  return rbTreeAddI64I64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile i64* value) {
  return rbTreeAddI64I64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, i64 value) {
  return rbTreeAddI64PI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile i64* value) {
  return rbTreeAddI64PI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, u64 value) {
  return rbTreeAddI64U64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile u64* value) {
  return rbTreeAddI64U64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, u64 value) {
  return rbTreeAddI64PU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile u64* value) {
  return rbTreeAddI64PU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, float value) {
  return rbTreeAddI64Float(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile float* value) {
  return rbTreeAddI64FloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, float value) {
  return rbTreeAddI64PFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile float* value) {
  return rbTreeAddI64PFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, double value) {
  return rbTreeAddI64Double(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile double* value) {
  return rbTreeAddI64DoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, double value) {
  return rbTreeAddI64PDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile double* value) {
  return rbTreeAddI64PDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, long double value) {
  return rbTreeAddI64LongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile long double* value) {
  return rbTreeAddI64LongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, long double value) {
  return rbTreeAddI64PLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile long double* value) {
  return rbTreeAddI64PLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, List value) {
  return rbTreeAddI64List(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile List* value) {
  return rbTreeAddI64ListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, List value) {
  return rbTreeAddI64PList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile List* value) {
  return rbTreeAddI64PListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, Queue value) {
  return rbTreeAddI64Queue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile Queue* value) {
  return rbTreeAddI64QueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, Queue value) {
  return rbTreeAddI64PQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile Queue* value) {
  return rbTreeAddI64PQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, Stack value) {
  return rbTreeAddI64Stack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile Stack* value) {
  return rbTreeAddI64StackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, Stack value) {
  return rbTreeAddI64PStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile Stack* value) {
  return rbTreeAddI64PStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, RedBlackTree value) {
  return rbTreeAddI64RedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile RedBlackTree* value) {
  return rbTreeAddI64RedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, RedBlackTree value) {
  return rbTreeAddI64PRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile RedBlackTree* value) {
  return rbTreeAddI64PRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, HashTable value) {
  return rbTreeAddI64HashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile HashTable* value) {
  return rbTreeAddI64HashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, HashTable value) {
  return rbTreeAddI64PHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile HashTable* value) {
  return rbTreeAddI64PHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, Vector value) {
  return rbTreeAddI64Vector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile Vector* value) {
  return rbTreeAddI64VectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, Vector value) {
  return rbTreeAddI64PVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile Vector* value) {
  return rbTreeAddI64PVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile char* value) {
  return rbTreeAddI64String(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile char** value) {
  return rbTreeAddI64StringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile char* value) {
  return rbTreeAddI64PString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile char** value) {
  return rbTreeAddI64PStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, Bytes value) {
  return rbTreeAddI64Bytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile Bytes* value) {
  return rbTreeAddI64BytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, Bytes value) {
  return rbTreeAddI64PBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile Bytes* value) {
  return rbTreeAddI64PBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, void* value) {
  return rbTreeAddI64Pointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, const volatile void** value) {
  return rbTreeAddI64PointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, void* value) {
  return rbTreeAddI64PPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, const volatile void** value) {
  return rbTreeAddI64PPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, i8 value) {
  return rbTreeAddI64I8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, i8 value) {
  return rbTreeAddI64PI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i64 key, u8 value) {
  return rbTreeAddI64U8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile i64* key, u8 value) {
  return rbTreeAddI64PU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, bool value) {
  return rbTreeAddU64Bool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile bool* value) {
  return rbTreeAddU64BoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, bool value) {
  return rbTreeAddU64PBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile bool* value) {
  return rbTreeAddU64PBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, i16 value) {
  return rbTreeAddU64I16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile i16* value) {
  return rbTreeAddU64I16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, i16 value) {
  return rbTreeAddU64PI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile i16* value) {
  return rbTreeAddU64PI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, u16 value) {
  return rbTreeAddU64U16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile u16* value) {
  return rbTreeAddU64U16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, u16 value) {
  return rbTreeAddU64PU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile u16* value) {
  return rbTreeAddU64PU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, i32 value) {
  return rbTreeAddU64I32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile i32* value) {
  return rbTreeAddU64I32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, i32 value) {
  return rbTreeAddU64PI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile i32* value) {
  return rbTreeAddU64PI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, u32 value) {
  return rbTreeAddU64U32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile u32* value) {
  return rbTreeAddU64U32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, u32 value) {
  return rbTreeAddU64PU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile u32* value) {
  return rbTreeAddU64PU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, i64 value) {
  return rbTreeAddU64I64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile i64* value) {
  return rbTreeAddU64I64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, i64 value) {
  return rbTreeAddU64PI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile i64* value) {
  return rbTreeAddU64PI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, u64 value) {
  return rbTreeAddU64U64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile u64* value) {
  return rbTreeAddU64U64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, u64 value) {
  return rbTreeAddU64PU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile u64* value) {
  return rbTreeAddU64PU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, float value) {
  return rbTreeAddU64Float(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile float* value) {
  return rbTreeAddU64FloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, float value) {
  return rbTreeAddU64PFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile float* value) {
  return rbTreeAddU64PFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, double value) {
  return rbTreeAddU64Double(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile double* value) {
  return rbTreeAddU64DoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, double value) {
  return rbTreeAddU64PDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile double* value) {
  return rbTreeAddU64PDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, long double value) {
  return rbTreeAddU64LongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile long double* value) {
  return rbTreeAddU64LongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, long double value) {
  return rbTreeAddU64PLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile long double* value) {
  return rbTreeAddU64PLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, List value) {
  return rbTreeAddU64List(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile List* value) {
  return rbTreeAddU64ListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, List value) {
  return rbTreeAddU64PList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile List* value) {
  return rbTreeAddU64PListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, Queue value) {
  return rbTreeAddU64Queue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile Queue* value) {
  return rbTreeAddU64QueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, Queue value) {
  return rbTreeAddU64PQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile Queue* value) {
  return rbTreeAddU64PQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, Stack value) {
  return rbTreeAddU64Stack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile Stack* value) {
  return rbTreeAddU64StackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, Stack value) {
  return rbTreeAddU64PStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile Stack* value) {
  return rbTreeAddU64PStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, RedBlackTree value) {
  return rbTreeAddU64RedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile RedBlackTree* value) {
  return rbTreeAddU64RedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, RedBlackTree value) {
  return rbTreeAddU64PRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile RedBlackTree* value) {
  return rbTreeAddU64PRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, HashTable value) {
  return rbTreeAddU64HashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile HashTable* value) {
  return rbTreeAddU64HashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, HashTable value) {
  return rbTreeAddU64PHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile HashTable* value) {
  return rbTreeAddU64PHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, Vector value) {
  return rbTreeAddU64Vector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile Vector* value) {
  return rbTreeAddU64VectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, Vector value) {
  return rbTreeAddU64PVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile Vector* value) {
  return rbTreeAddU64PVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile char* value) {
  return rbTreeAddU64String(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile char** value) {
  return rbTreeAddU64StringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile char* value) {
  return rbTreeAddU64PString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile char** value) {
  return rbTreeAddU64PStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, Bytes value) {
  return rbTreeAddU64Bytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile Bytes* value) {
  return rbTreeAddU64BytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, Bytes value) {
  return rbTreeAddU64PBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile Bytes* value) {
  return rbTreeAddU64PBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, void* value) {
  return rbTreeAddU64Pointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, const volatile void** value) {
  return rbTreeAddU64PointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, void* value) {
  return rbTreeAddU64PPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, const volatile void** value) {
  return rbTreeAddU64PPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, i8 value) {
  return rbTreeAddU64I8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, i8 value) {
  return rbTreeAddU64PI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u64 key, u8 value) {
  return rbTreeAddU64U8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile u64* key, u8 value) {
  return rbTreeAddU64PU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, bool value) {
  return rbTreeAddFloatBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile bool* value) {
  return rbTreeAddFloatBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, bool value) {
  return rbTreeAddFloatPBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile bool* value) {
  return rbTreeAddFloatPBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, i16 value) {
  return rbTreeAddFloatI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile i16* value) {
  return rbTreeAddFloatI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, i16 value) {
  return rbTreeAddFloatPI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile i16* value) {
  return rbTreeAddFloatPI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, u16 value) {
  return rbTreeAddFloatU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile u16* value) {
  return rbTreeAddFloatU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, u16 value) {
  return rbTreeAddFloatPU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile u16* value) {
  return rbTreeAddFloatPU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, i32 value) {
  return rbTreeAddFloatI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile i32* value) {
  return rbTreeAddFloatI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, i32 value) {
  return rbTreeAddFloatPI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile i32* value) {
  return rbTreeAddFloatPI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, u32 value) {
  return rbTreeAddFloatU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile u32* value) {
  return rbTreeAddFloatU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, u32 value) {
  return rbTreeAddFloatPU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile u32* value) {
  return rbTreeAddFloatPU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, i64 value) {
  return rbTreeAddFloatI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile i64* value) {
  return rbTreeAddFloatI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, i64 value) {
  return rbTreeAddFloatPI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile i64* value) {
  return rbTreeAddFloatPI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, u64 value) {
  return rbTreeAddFloatU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile u64* value) {
  return rbTreeAddFloatU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, u64 value) {
  return rbTreeAddFloatPU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile u64* value) {
  return rbTreeAddFloatPU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, float value) {
  return rbTreeAddFloatFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile float* value) {
  return rbTreeAddFloatFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, float value) {
  return rbTreeAddFloatPFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile float* value) {
  return rbTreeAddFloatPFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, double value) {
  return rbTreeAddFloatDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile double* value) {
  return rbTreeAddFloatDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, double value) {
  return rbTreeAddFloatPDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile double* value) {
  return rbTreeAddFloatPDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, long double value) {
  return rbTreeAddFloatLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile long double* value) {
  return rbTreeAddFloatLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, long double value) {
  return rbTreeAddFloatPLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile long double* value) {
  return rbTreeAddFloatPLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, List value) {
  return rbTreeAddFloatList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile List* value) {
  return rbTreeAddFloatListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, List value) {
  return rbTreeAddFloatPList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile List* value) {
  return rbTreeAddFloatPListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, Queue value) {
  return rbTreeAddFloatQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile Queue* value) {
  return rbTreeAddFloatQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, Queue value) {
  return rbTreeAddFloatPQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile Queue* value) {
  return rbTreeAddFloatPQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, Stack value) {
  return rbTreeAddFloatStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile Stack* value) {
  return rbTreeAddFloatStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, Stack value) {
  return rbTreeAddFloatPStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile Stack* value) {
  return rbTreeAddFloatPStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, RedBlackTree value) {
  return rbTreeAddFloatRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile RedBlackTree* value) {
  return rbTreeAddFloatRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, RedBlackTree value) {
  return rbTreeAddFloatPRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile RedBlackTree* value) {
  return rbTreeAddFloatPRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, HashTable value) {
  return rbTreeAddFloatHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile HashTable* value) {
  return rbTreeAddFloatHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, HashTable value) {
  return rbTreeAddFloatPHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile HashTable* value) {
  return rbTreeAddFloatPHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, Vector value) {
  return rbTreeAddFloatVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile Vector* value) {
  return rbTreeAddFloatVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, Vector value) {
  return rbTreeAddFloatPVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile Vector* value) {
  return rbTreeAddFloatPVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile char* value) {
  return rbTreeAddFloatString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile char** value) {
  return rbTreeAddFloatStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile char* value) {
  return rbTreeAddFloatPString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile char** value) {
  return rbTreeAddFloatPStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, Bytes value) {
  return rbTreeAddFloatBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile Bytes* value) {
  return rbTreeAddFloatBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, Bytes value) {
  return rbTreeAddFloatPBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile Bytes* value) {
  return rbTreeAddFloatPBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, void* value) {
  return rbTreeAddFloatPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, const volatile void** value) {
  return rbTreeAddFloatPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, void* value) {
  return rbTreeAddFloatPPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, const volatile void** value) {
  return rbTreeAddFloatPPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, i8 value) {
  return rbTreeAddFloatI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, i8 value) {
  return rbTreeAddFloatPI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, float key, u8 value) {
  return rbTreeAddFloatU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile float* key, u8 value) {
  return rbTreeAddFloatPU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, bool value) {
  return rbTreeAddDoubleBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile bool* value) {
  return rbTreeAddDoubleBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, bool value) {
  return rbTreeAddDoublePBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile bool* value) {
  return rbTreeAddDoublePBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, i16 value) {
  return rbTreeAddDoubleI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile i16* value) {
  return rbTreeAddDoubleI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, i16 value) {
  return rbTreeAddDoublePI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile i16* value) {
  return rbTreeAddDoublePI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, u16 value) {
  return rbTreeAddDoubleU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile u16* value) {
  return rbTreeAddDoubleU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, u16 value) {
  return rbTreeAddDoublePU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile u16* value) {
  return rbTreeAddDoublePU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, i32 value) {
  return rbTreeAddDoubleI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile i32* value) {
  return rbTreeAddDoubleI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, i32 value) {
  return rbTreeAddDoublePI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile i32* value) {
  return rbTreeAddDoublePI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, u32 value) {
  return rbTreeAddDoubleU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile u32* value) {
  return rbTreeAddDoubleU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, u32 value) {
  return rbTreeAddDoublePU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile u32* value) {
  return rbTreeAddDoublePU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, i64 value) {
  return rbTreeAddDoubleI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile i64* value) {
  return rbTreeAddDoubleI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, i64 value) {
  return rbTreeAddDoublePI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile i64* value) {
  return rbTreeAddDoublePI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, u64 value) {
  return rbTreeAddDoubleU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile u64* value) {
  return rbTreeAddDoubleU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, u64 value) {
  return rbTreeAddDoublePU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile u64* value) {
  return rbTreeAddDoublePU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, float value) {
  return rbTreeAddDoubleFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile float* value) {
  return rbTreeAddDoubleFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, float value) {
  return rbTreeAddDoublePFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile float* value) {
  return rbTreeAddDoublePFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, double value) {
  return rbTreeAddDoubleDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile double* value) {
  return rbTreeAddDoubleDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, double value) {
  return rbTreeAddDoublePDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile double* value) {
  return rbTreeAddDoublePDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, long double value) {
  return rbTreeAddDoubleLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile long double* value) {
  return rbTreeAddDoubleLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, long double value) {
  return rbTreeAddDoublePLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile long double* value) {
  return rbTreeAddDoublePLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, List value) {
  return rbTreeAddDoubleList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile List* value) {
  return rbTreeAddDoubleListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, List value) {
  return rbTreeAddDoublePList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile List* value) {
  return rbTreeAddDoublePListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, Queue value) {
  return rbTreeAddDoubleQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile Queue* value) {
  return rbTreeAddDoubleQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, Queue value) {
  return rbTreeAddDoublePQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile Queue* value) {
  return rbTreeAddDoublePQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, Stack value) {
  return rbTreeAddDoubleStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile Stack* value) {
  return rbTreeAddDoubleStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, Stack value) {
  return rbTreeAddDoublePStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile Stack* value) {
  return rbTreeAddDoublePStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, RedBlackTree value) {
  return rbTreeAddDoubleRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile RedBlackTree* value) {
  return rbTreeAddDoubleRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, RedBlackTree value) {
  return rbTreeAddDoublePRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile RedBlackTree* value) {
  return rbTreeAddDoublePRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, HashTable value) {
  return rbTreeAddDoubleHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile HashTable* value) {
  return rbTreeAddDoubleHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, HashTable value) {
  return rbTreeAddDoublePHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile HashTable* value) {
  return rbTreeAddDoublePHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, Vector value) {
  return rbTreeAddDoubleVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile Vector* value) {
  return rbTreeAddDoubleVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, Vector value) {
  return rbTreeAddDoublePVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile Vector* value) {
  return rbTreeAddDoublePVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile char* value) {
  return rbTreeAddDoubleString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile char** value) {
  return rbTreeAddDoubleStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile char* value) {
  return rbTreeAddDoublePString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile char** value) {
  return rbTreeAddDoublePStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, Bytes value) {
  return rbTreeAddDoubleBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile Bytes* value) {
  return rbTreeAddDoubleBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, Bytes value) {
  return rbTreeAddDoublePBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile Bytes* value) {
  return rbTreeAddDoublePBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, void* value) {
  return rbTreeAddDoublePointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, const volatile void** value) {
  return rbTreeAddDoublePointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, void* value) {
  return rbTreeAddDoublePPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, const volatile void** value) {
  return rbTreeAddDoublePPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, i8 value) {
  return rbTreeAddDoubleI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, i8 value) {
  return rbTreeAddDoublePI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, double key, u8 value) {
  return rbTreeAddDoubleU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile double* key, u8 value) {
  return rbTreeAddDoublePU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, bool value) {
  return rbTreeAddLongDoubleBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile bool* value) {
  return rbTreeAddLongDoubleBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, bool value) {
  return rbTreeAddLongDoublePBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile bool* value) {
  return rbTreeAddLongDoublePBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, i16 value) {
  return rbTreeAddLongDoubleI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile i16* value) {
  return rbTreeAddLongDoubleI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, i16 value) {
  return rbTreeAddLongDoublePI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile i16* value) {
  return rbTreeAddLongDoublePI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, u16 value) {
  return rbTreeAddLongDoubleU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile u16* value) {
  return rbTreeAddLongDoubleU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, u16 value) {
  return rbTreeAddLongDoublePU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile u16* value) {
  return rbTreeAddLongDoublePU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, i32 value) {
  return rbTreeAddLongDoubleI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile i32* value) {
  return rbTreeAddLongDoubleI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, i32 value) {
  return rbTreeAddLongDoublePI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile i32* value) {
  return rbTreeAddLongDoublePI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, u32 value) {
  return rbTreeAddLongDoubleU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile u32* value) {
  return rbTreeAddLongDoubleU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, u32 value) {
  return rbTreeAddLongDoublePU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile u32* value) {
  return rbTreeAddLongDoublePU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, i64 value) {
  return rbTreeAddLongDoubleI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile i64* value) {
  return rbTreeAddLongDoubleI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, i64 value) {
  return rbTreeAddLongDoublePI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile i64* value) {
  return rbTreeAddLongDoublePI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, u64 value) {
  return rbTreeAddLongDoubleU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile u64* value) {
  return rbTreeAddLongDoubleU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, u64 value) {
  return rbTreeAddLongDoublePU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile u64* value) {
  return rbTreeAddLongDoublePU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, float value) {
  return rbTreeAddLongDoubleFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile float* value) {
  return rbTreeAddLongDoubleFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, float value) {
  return rbTreeAddLongDoublePFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile float* value) {
  return rbTreeAddLongDoublePFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, double value) {
  return rbTreeAddLongDoubleDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile double* value) {
  return rbTreeAddLongDoubleDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, double value) {
  return rbTreeAddLongDoublePDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile double* value) {
  return rbTreeAddLongDoublePDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, long double value) {
  return rbTreeAddLongDoubleLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile long double* value) {
  return rbTreeAddLongDoubleLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, long double value) {
  return rbTreeAddLongDoublePLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile long double* value) {
  return rbTreeAddLongDoublePLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, List value) {
  return rbTreeAddLongDoubleList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile List* value) {
  return rbTreeAddLongDoubleListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, List value) {
  return rbTreeAddLongDoublePList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile List* value) {
  return rbTreeAddLongDoublePListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, Queue value) {
  return rbTreeAddLongDoubleQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile Queue* value) {
  return rbTreeAddLongDoubleQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, Queue value) {
  return rbTreeAddLongDoublePQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile Queue* value) {
  return rbTreeAddLongDoublePQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, Stack value) {
  return rbTreeAddLongDoubleStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile Stack* value) {
  return rbTreeAddLongDoubleStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, Stack value) {
  return rbTreeAddLongDoublePStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile Stack* value) {
  return rbTreeAddLongDoublePStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, RedBlackTree value) {
  return rbTreeAddLongDoubleRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile RedBlackTree* value) {
  return rbTreeAddLongDoubleRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, RedBlackTree value) {
  return rbTreeAddLongDoublePRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile RedBlackTree* value) {
  return rbTreeAddLongDoublePRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, HashTable value) {
  return rbTreeAddLongDoubleHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile HashTable* value) {
  return rbTreeAddLongDoubleHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, HashTable value) {
  return rbTreeAddLongDoublePHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile HashTable* value) {
  return rbTreeAddLongDoublePHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, Vector value) {
  return rbTreeAddLongDoubleVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile Vector* value) {
  return rbTreeAddLongDoubleVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, Vector value) {
  return rbTreeAddLongDoublePVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile Vector* value) {
  return rbTreeAddLongDoublePVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile char* value) {
  return rbTreeAddLongDoubleString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile char** value) {
  return rbTreeAddLongDoubleStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile char* value) {
  return rbTreeAddLongDoublePString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile char** value) {
  return rbTreeAddLongDoublePStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, Bytes value) {
  return rbTreeAddLongDoubleBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile Bytes* value) {
  return rbTreeAddLongDoubleBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, Bytes value) {
  return rbTreeAddLongDoublePBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile Bytes* value) {
  return rbTreeAddLongDoublePBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, void* value) {
  return rbTreeAddLongDoublePointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, const volatile void** value) {
  return rbTreeAddLongDoublePointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, void* value) {
  return rbTreeAddLongDoublePPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, const volatile void** value) {
  return rbTreeAddLongDoublePPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, i8 value) {
  return rbTreeAddLongDoubleI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, i8 value) {
  return rbTreeAddLongDoublePI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, long double key, u8 value) {
  return rbTreeAddLongDoubleU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile long double* key, u8 value) {
  return rbTreeAddLongDoublePU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, bool value) {
  return rbTreeAddListBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile bool* value) {
  return rbTreeAddListBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, bool value) {
  return rbTreeAddListPBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile bool* value) {
  return rbTreeAddListPBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, i16 value) {
  return rbTreeAddListI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile i16* value) {
  return rbTreeAddListI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, i16 value) {
  return rbTreeAddListPI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile i16* value) {
  return rbTreeAddListPI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, u16 value) {
  return rbTreeAddListU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile u16* value) {
  return rbTreeAddListU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, u16 value) {
  return rbTreeAddListPU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile u16* value) {
  return rbTreeAddListPU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, i32 value) {
  return rbTreeAddListI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile i32* value) {
  return rbTreeAddListI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, i32 value) {
  return rbTreeAddListPI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile i32* value) {
  return rbTreeAddListPI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, u32 value) {
  return rbTreeAddListU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile u32* value) {
  return rbTreeAddListU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, u32 value) {
  return rbTreeAddListPU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile u32* value) {
  return rbTreeAddListPU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, i64 value) {
  return rbTreeAddListI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile i64* value) {
  return rbTreeAddListI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, i64 value) {
  return rbTreeAddListPI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile i64* value) {
  return rbTreeAddListPI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, u64 value) {
  return rbTreeAddListU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile u64* value) {
  return rbTreeAddListU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, u64 value) {
  return rbTreeAddListPU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile u64* value) {
  return rbTreeAddListPU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, float value) {
  return rbTreeAddListFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile float* value) {
  return rbTreeAddListFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, float value) {
  return rbTreeAddListPFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile float* value) {
  return rbTreeAddListPFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, double value) {
  return rbTreeAddListDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile double* value) {
  return rbTreeAddListDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, double value) {
  return rbTreeAddListPDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile double* value) {
  return rbTreeAddListPDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, long double value) {
  return rbTreeAddListLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile long double* value) {
  return rbTreeAddListLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, long double value) {
  return rbTreeAddListPLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile long double* value) {
  return rbTreeAddListPLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, List value) {
  return rbTreeAddListList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile List* value) {
  return rbTreeAddListListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, List value) {
  return rbTreeAddListPList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile List* value) {
  return rbTreeAddListPListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, Queue value) {
  return rbTreeAddListQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile Queue* value) {
  return rbTreeAddListQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, Queue value) {
  return rbTreeAddListPQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile Queue* value) {
  return rbTreeAddListPQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, Stack value) {
  return rbTreeAddListStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile Stack* value) {
  return rbTreeAddListStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, Stack value) {
  return rbTreeAddListPStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile Stack* value) {
  return rbTreeAddListPStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, RedBlackTree value) {
  return rbTreeAddListRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile RedBlackTree* value) {
  return rbTreeAddListRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, RedBlackTree value) {
  return rbTreeAddListPRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile RedBlackTree* value) {
  return rbTreeAddListPRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, HashTable value) {
  return rbTreeAddListHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile HashTable* value) {
  return rbTreeAddListHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, HashTable value) {
  return rbTreeAddListPHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile HashTable* value) {
  return rbTreeAddListPHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, Vector value) {
  return rbTreeAddListVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile Vector* value) {
  return rbTreeAddListVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, Vector value) {
  return rbTreeAddListPVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile Vector* value) {
  return rbTreeAddListPVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile char* value) {
  return rbTreeAddListString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile char** value) {
  return rbTreeAddListStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile char* value) {
  return rbTreeAddListPString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile char** value) {
  return rbTreeAddListPStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, Bytes value) {
  return rbTreeAddListBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile Bytes* value) {
  return rbTreeAddListBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, Bytes value) {
  return rbTreeAddListPBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile Bytes* value) {
  return rbTreeAddListPBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, void* value) {
  return rbTreeAddListPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, const volatile void** value) {
  return rbTreeAddListPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, void* value) {
  return rbTreeAddListPPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, const volatile void** value) {
  return rbTreeAddListPPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, i8 value) {
  return rbTreeAddListI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, i8 value) {
  return rbTreeAddListPI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, List key, u8 value) {
  return rbTreeAddListU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile List* key, u8 value) {
  return rbTreeAddListPU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, bool value) {
  return rbTreeAddQueueBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile bool* value) {
  return rbTreeAddQueueBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, bool value) {
  return rbTreeAddQueuePBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile bool* value) {
  return rbTreeAddQueuePBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, i16 value) {
  return rbTreeAddQueueI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile i16* value) {
  return rbTreeAddQueueI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, i16 value) {
  return rbTreeAddQueuePI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile i16* value) {
  return rbTreeAddQueuePI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, u16 value) {
  return rbTreeAddQueueU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile u16* value) {
  return rbTreeAddQueueU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, u16 value) {
  return rbTreeAddQueuePU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile u16* value) {
  return rbTreeAddQueuePU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, i32 value) {
  return rbTreeAddQueueI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile i32* value) {
  return rbTreeAddQueueI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, i32 value) {
  return rbTreeAddQueuePI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile i32* value) {
  return rbTreeAddQueuePI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, u32 value) {
  return rbTreeAddQueueU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile u32* value) {
  return rbTreeAddQueueU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, u32 value) {
  return rbTreeAddQueuePU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile u32* value) {
  return rbTreeAddQueuePU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, i64 value) {
  return rbTreeAddQueueI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile i64* value) {
  return rbTreeAddQueueI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, i64 value) {
  return rbTreeAddQueuePI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile i64* value) {
  return rbTreeAddQueuePI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, u64 value) {
  return rbTreeAddQueueU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile u64* value) {
  return rbTreeAddQueueU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, u64 value) {
  return rbTreeAddQueuePU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile u64* value) {
  return rbTreeAddQueuePU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, float value) {
  return rbTreeAddQueueFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile float* value) {
  return rbTreeAddQueueFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, float value) {
  return rbTreeAddQueuePFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile float* value) {
  return rbTreeAddQueuePFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, double value) {
  return rbTreeAddQueueDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile double* value) {
  return rbTreeAddQueueDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, double value) {
  return rbTreeAddQueuePDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile double* value) {
  return rbTreeAddQueuePDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, long double value) {
  return rbTreeAddQueueLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile long double* value) {
  return rbTreeAddQueueLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, long double value) {
  return rbTreeAddQueuePLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile long double* value) {
  return rbTreeAddQueuePLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, List value) {
  return rbTreeAddQueueList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile List* value) {
  return rbTreeAddQueueListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, List value) {
  return rbTreeAddQueuePList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile List* value) {
  return rbTreeAddQueuePListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, Queue value) {
  return rbTreeAddQueueQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile Queue* value) {
  return rbTreeAddQueueQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, Queue value) {
  return rbTreeAddQueuePQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile Queue* value) {
  return rbTreeAddQueuePQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, Stack value) {
  return rbTreeAddQueueStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile Stack* value) {
  return rbTreeAddQueueStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, Stack value) {
  return rbTreeAddQueuePStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile Stack* value) {
  return rbTreeAddQueuePStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, RedBlackTree value) {
  return rbTreeAddQueueRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile RedBlackTree* value) {
  return rbTreeAddQueueRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, RedBlackTree value) {
  return rbTreeAddQueuePRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile RedBlackTree* value) {
  return rbTreeAddQueuePRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, HashTable value) {
  return rbTreeAddQueueHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile HashTable* value) {
  return rbTreeAddQueueHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, HashTable value) {
  return rbTreeAddQueuePHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile HashTable* value) {
  return rbTreeAddQueuePHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, Vector value) {
  return rbTreeAddQueueVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile Vector* value) {
  return rbTreeAddQueueVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, Vector value) {
  return rbTreeAddQueuePVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile Vector* value) {
  return rbTreeAddQueuePVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile char* value) {
  return rbTreeAddQueueString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile char** value) {
  return rbTreeAddQueueStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile char* value) {
  return rbTreeAddQueuePString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile char** value) {
  return rbTreeAddQueuePStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, Bytes value) {
  return rbTreeAddQueueBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile Bytes* value) {
  return rbTreeAddQueueBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, Bytes value) {
  return rbTreeAddQueuePBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile Bytes* value) {
  return rbTreeAddQueuePBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, void* value) {
  return rbTreeAddQueuePointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, const volatile void** value) {
  return rbTreeAddQueuePointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, void* value) {
  return rbTreeAddQueuePPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, const volatile void** value) {
  return rbTreeAddQueuePPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, i8 value) {
  return rbTreeAddQueueI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, i8 value) {
  return rbTreeAddQueuePI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Queue key, u8 value) {
  return rbTreeAddQueueU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Queue* key, u8 value) {
  return rbTreeAddQueuePU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, bool value) {
  return rbTreeAddStackBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile bool* value) {
  return rbTreeAddStackBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, bool value) {
  return rbTreeAddStackPBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile bool* value) {
  return rbTreeAddStackPBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, i16 value) {
  return rbTreeAddStackI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile i16* value) {
  return rbTreeAddStackI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, i16 value) {
  return rbTreeAddStackPI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile i16* value) {
  return rbTreeAddStackPI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, u16 value) {
  return rbTreeAddStackU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile u16* value) {
  return rbTreeAddStackU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, u16 value) {
  return rbTreeAddStackPU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile u16* value) {
  return rbTreeAddStackPU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, i32 value) {
  return rbTreeAddStackI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile i32* value) {
  return rbTreeAddStackI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, i32 value) {
  return rbTreeAddStackPI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile i32* value) {
  return rbTreeAddStackPI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, u32 value) {
  return rbTreeAddStackU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile u32* value) {
  return rbTreeAddStackU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, u32 value) {
  return rbTreeAddStackPU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile u32* value) {
  return rbTreeAddStackPU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, i64 value) {
  return rbTreeAddStackI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile i64* value) {
  return rbTreeAddStackI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, i64 value) {
  return rbTreeAddStackPI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile i64* value) {
  return rbTreeAddStackPI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, u64 value) {
  return rbTreeAddStackU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile u64* value) {
  return rbTreeAddStackU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, u64 value) {
  return rbTreeAddStackPU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile u64* value) {
  return rbTreeAddStackPU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, float value) {
  return rbTreeAddStackFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile float* value) {
  return rbTreeAddStackFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, float value) {
  return rbTreeAddStackPFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile float* value) {
  return rbTreeAddStackPFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, double value) {
  return rbTreeAddStackDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile double* value) {
  return rbTreeAddStackDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, double value) {
  return rbTreeAddStackPDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile double* value) {
  return rbTreeAddStackPDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, long double value) {
  return rbTreeAddStackLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile long double* value) {
  return rbTreeAddStackLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, long double value) {
  return rbTreeAddStackPLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile long double* value) {
  return rbTreeAddStackPLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, List value) {
  return rbTreeAddStackList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile List* value) {
  return rbTreeAddStackListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, List value) {
  return rbTreeAddStackPList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile List* value) {
  return rbTreeAddStackPListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, Queue value) {
  return rbTreeAddStackQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile Queue* value) {
  return rbTreeAddStackQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, Queue value) {
  return rbTreeAddStackPQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile Queue* value) {
  return rbTreeAddStackPQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, Stack value) {
  return rbTreeAddStackStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile Stack* value) {
  return rbTreeAddStackStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, Stack value) {
  return rbTreeAddStackPStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile Stack* value) {
  return rbTreeAddStackPStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, RedBlackTree value) {
  return rbTreeAddStackRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile RedBlackTree* value) {
  return rbTreeAddStackRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, RedBlackTree value) {
  return rbTreeAddStackPRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile RedBlackTree* value) {
  return rbTreeAddStackPRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, HashTable value) {
  return rbTreeAddStackHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile HashTable* value) {
  return rbTreeAddStackHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, HashTable value) {
  return rbTreeAddStackPHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile HashTable* value) {
  return rbTreeAddStackPHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, Vector value) {
  return rbTreeAddStackVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile Vector* value) {
  return rbTreeAddStackVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, Vector value) {
  return rbTreeAddStackPVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile Vector* value) {
  return rbTreeAddStackPVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile char* value) {
  return rbTreeAddStackString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile char** value) {
  return rbTreeAddStackStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile char* value) {
  return rbTreeAddStackPString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile char** value) {
  return rbTreeAddStackPStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, Bytes value) {
  return rbTreeAddStackBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile Bytes* value) {
  return rbTreeAddStackBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, Bytes value) {
  return rbTreeAddStackPBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile Bytes* value) {
  return rbTreeAddStackPBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, void* value) {
  return rbTreeAddStackPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, const volatile void** value) {
  return rbTreeAddStackPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, void* value) {
  return rbTreeAddStackPPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, const volatile void** value) {
  return rbTreeAddStackPPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, i8 value) {
  return rbTreeAddStackI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, i8 value) {
  return rbTreeAddStackPI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Stack key, u8 value) {
  return rbTreeAddStackU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Stack* key, u8 value) {
  return rbTreeAddStackPU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, bool value) {
  return rbTreeAddRedBlackTreeBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile bool* value) {
  return rbTreeAddRedBlackTreeBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, bool value) {
  return rbTreeAddRedBlackTreePBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile bool* value) {
  return rbTreeAddRedBlackTreePBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, i16 value) {
  return rbTreeAddRedBlackTreeI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile i16* value) {
  return rbTreeAddRedBlackTreeI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, i16 value) {
  return rbTreeAddRedBlackTreePI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile i16* value) {
  return rbTreeAddRedBlackTreePI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, u16 value) {
  return rbTreeAddRedBlackTreeU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile u16* value) {
  return rbTreeAddRedBlackTreeU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, u16 value) {
  return rbTreeAddRedBlackTreePU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile u16* value) {
  return rbTreeAddRedBlackTreePU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, i32 value) {
  return rbTreeAddRedBlackTreeI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile i32* value) {
  return rbTreeAddRedBlackTreeI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, i32 value) {
  return rbTreeAddRedBlackTreePI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile i32* value) {
  return rbTreeAddRedBlackTreePI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, u32 value) {
  return rbTreeAddRedBlackTreeU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile u32* value) {
  return rbTreeAddRedBlackTreeU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, u32 value) {
  return rbTreeAddRedBlackTreePU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile u32* value) {
  return rbTreeAddRedBlackTreePU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, i64 value) {
  return rbTreeAddRedBlackTreeI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile i64* value) {
  return rbTreeAddRedBlackTreeI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, i64 value) {
  return rbTreeAddRedBlackTreePI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile i64* value) {
  return rbTreeAddRedBlackTreePI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, u64 value) {
  return rbTreeAddRedBlackTreeU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile u64* value) {
  return rbTreeAddRedBlackTreeU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, u64 value) {
  return rbTreeAddRedBlackTreePU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile u64* value) {
  return rbTreeAddRedBlackTreePU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, float value) {
  return rbTreeAddRedBlackTreeFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile float* value) {
  return rbTreeAddRedBlackTreeFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, float value) {
  return rbTreeAddRedBlackTreePFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile float* value) {
  return rbTreeAddRedBlackTreePFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, double value) {
  return rbTreeAddRedBlackTreeDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile double* value) {
  return rbTreeAddRedBlackTreeDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, double value) {
  return rbTreeAddRedBlackTreePDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile double* value) {
  return rbTreeAddRedBlackTreePDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, long double value) {
  return rbTreeAddRedBlackTreeLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile long double* value) {
  return rbTreeAddRedBlackTreeLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, long double value) {
  return rbTreeAddRedBlackTreePLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile long double* value) {
  return rbTreeAddRedBlackTreePLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, List value) {
  return rbTreeAddRedBlackTreeList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile List* value) {
  return rbTreeAddRedBlackTreeListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, List value) {
  return rbTreeAddRedBlackTreePList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile List* value) {
  return rbTreeAddRedBlackTreePListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, Queue value) {
  return rbTreeAddRedBlackTreeQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile Queue* value) {
  return rbTreeAddRedBlackTreeQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, Queue value) {
  return rbTreeAddRedBlackTreePQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile Queue* value) {
  return rbTreeAddRedBlackTreePQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, Stack value) {
  return rbTreeAddRedBlackTreeStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile Stack* value) {
  return rbTreeAddRedBlackTreeStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, Stack value) {
  return rbTreeAddRedBlackTreePStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile Stack* value) {
  return rbTreeAddRedBlackTreePStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, RedBlackTree value) {
  return rbTreeAddRedBlackTreeRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile RedBlackTree* value) {
  return rbTreeAddRedBlackTreeRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, RedBlackTree value) {
  return rbTreeAddRedBlackTreePRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile RedBlackTree* value) {
  return rbTreeAddRedBlackTreePRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, HashTable value) {
  return rbTreeAddRedBlackTreeHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile HashTable* value) {
  return rbTreeAddRedBlackTreeHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, HashTable value) {
  return rbTreeAddRedBlackTreePHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile HashTable* value) {
  return rbTreeAddRedBlackTreePHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, Vector value) {
  return rbTreeAddRedBlackTreeVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile Vector* value) {
  return rbTreeAddRedBlackTreeVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, Vector value) {
  return rbTreeAddRedBlackTreePVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile Vector* value) {
  return rbTreeAddRedBlackTreePVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile char* value) {
  return rbTreeAddRedBlackTreeString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile char** value) {
  return rbTreeAddRedBlackTreeStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile char* value) {
  return rbTreeAddRedBlackTreePString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile char** value) {
  return rbTreeAddRedBlackTreePStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, Bytes value) {
  return rbTreeAddRedBlackTreeBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile Bytes* value) {
  return rbTreeAddRedBlackTreeBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, Bytes value) {
  return rbTreeAddRedBlackTreePBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile Bytes* value) {
  return rbTreeAddRedBlackTreePBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, void* value) {
  return rbTreeAddRedBlackTreePointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, const volatile void** value) {
  return rbTreeAddRedBlackTreePointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, void* value) {
  return rbTreeAddRedBlackTreePPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, const volatile void** value) {
  return rbTreeAddRedBlackTreePPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, i8 value) {
  return rbTreeAddRedBlackTreeI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, i8 value) {
  return rbTreeAddRedBlackTreePI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, RedBlackTree key, u8 value) {
  return rbTreeAddRedBlackTreeU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile RedBlackTree* key, u8 value) {
  return rbTreeAddRedBlackTreePU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, bool value) {
  return rbTreeAddHashTableBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile bool* value) {
  return rbTreeAddHashTableBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, bool value) {
  return rbTreeAddHashTablePBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile bool* value) {
  return rbTreeAddHashTablePBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, i16 value) {
  return rbTreeAddHashTableI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile i16* value) {
  return rbTreeAddHashTableI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, i16 value) {
  return rbTreeAddHashTablePI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile i16* value) {
  return rbTreeAddHashTablePI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, u16 value) {
  return rbTreeAddHashTableU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile u16* value) {
  return rbTreeAddHashTableU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, u16 value) {
  return rbTreeAddHashTablePU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile u16* value) {
  return rbTreeAddHashTablePU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, i32 value) {
  return rbTreeAddHashTableI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile i32* value) {
  return rbTreeAddHashTableI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, i32 value) {
  return rbTreeAddHashTablePI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile i32* value) {
  return rbTreeAddHashTablePI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, u32 value) {
  return rbTreeAddHashTableU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile u32* value) {
  return rbTreeAddHashTableU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, u32 value) {
  return rbTreeAddHashTablePU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile u32* value) {
  return rbTreeAddHashTablePU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, i64 value) {
  return rbTreeAddHashTableI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile i64* value) {
  return rbTreeAddHashTableI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, i64 value) {
  return rbTreeAddHashTablePI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile i64* value) {
  return rbTreeAddHashTablePI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, u64 value) {
  return rbTreeAddHashTableU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile u64* value) {
  return rbTreeAddHashTableU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, u64 value) {
  return rbTreeAddHashTablePU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile u64* value) {
  return rbTreeAddHashTablePU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, float value) {
  return rbTreeAddHashTableFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile float* value) {
  return rbTreeAddHashTableFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, float value) {
  return rbTreeAddHashTablePFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile float* value) {
  return rbTreeAddHashTablePFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, double value) {
  return rbTreeAddHashTableDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile double* value) {
  return rbTreeAddHashTableDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, double value) {
  return rbTreeAddHashTablePDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile double* value) {
  return rbTreeAddHashTablePDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, long double value) {
  return rbTreeAddHashTableLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile long double* value) {
  return rbTreeAddHashTableLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, long double value) {
  return rbTreeAddHashTablePLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile long double* value) {
  return rbTreeAddHashTablePLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, List value) {
  return rbTreeAddHashTableList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile List* value) {
  return rbTreeAddHashTableListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, List value) {
  return rbTreeAddHashTablePList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile List* value) {
  return rbTreeAddHashTablePListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, Queue value) {
  return rbTreeAddHashTableQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile Queue* value) {
  return rbTreeAddHashTableQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, Queue value) {
  return rbTreeAddHashTablePQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile Queue* value) {
  return rbTreeAddHashTablePQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, Stack value) {
  return rbTreeAddHashTableStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile Stack* value) {
  return rbTreeAddHashTableStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, Stack value) {
  return rbTreeAddHashTablePStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile Stack* value) {
  return rbTreeAddHashTablePStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, RedBlackTree value) {
  return rbTreeAddHashTableRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile RedBlackTree* value) {
  return rbTreeAddHashTableRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, RedBlackTree value) {
  return rbTreeAddHashTablePRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile RedBlackTree* value) {
  return rbTreeAddHashTablePRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, HashTable value) {
  return rbTreeAddHashTableHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile HashTable* value) {
  return rbTreeAddHashTableHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, HashTable value) {
  return rbTreeAddHashTablePHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile HashTable* value) {
  return rbTreeAddHashTablePHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, Vector value) {
  return rbTreeAddHashTableVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile Vector* value) {
  return rbTreeAddHashTableVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, Vector value) {
  return rbTreeAddHashTablePVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile Vector* value) {
  return rbTreeAddHashTablePVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile char* value) {
  return rbTreeAddHashTableString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile char** value) {
  return rbTreeAddHashTableStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile char* value) {
  return rbTreeAddHashTablePString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile char** value) {
  return rbTreeAddHashTablePStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, Bytes value) {
  return rbTreeAddHashTableBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile Bytes* value) {
  return rbTreeAddHashTableBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, Bytes value) {
  return rbTreeAddHashTablePBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile Bytes* value) {
  return rbTreeAddHashTablePBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, void* value) {
  return rbTreeAddHashTablePointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, const volatile void** value) {
  return rbTreeAddHashTablePointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, void* value) {
  return rbTreeAddHashTablePPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, const volatile void** value) {
  return rbTreeAddHashTablePPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, i8 value) {
  return rbTreeAddHashTableI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, i8 value) {
  return rbTreeAddHashTablePI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, HashTable key, u8 value) {
  return rbTreeAddHashTableU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile HashTable* key, u8 value) {
  return rbTreeAddHashTablePU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, bool value) {
  return rbTreeAddVectorBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile bool* value) {
  return rbTreeAddVectorBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, bool value) {
  return rbTreeAddVectorPBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile bool* value) {
  return rbTreeAddVectorPBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, i16 value) {
  return rbTreeAddVectorI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile i16* value) {
  return rbTreeAddVectorI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, i16 value) {
  return rbTreeAddVectorPI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile i16* value) {
  return rbTreeAddVectorPI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, u16 value) {
  return rbTreeAddVectorU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile u16* value) {
  return rbTreeAddVectorU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, u16 value) {
  return rbTreeAddVectorPU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile u16* value) {
  return rbTreeAddVectorPU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, i32 value) {
  return rbTreeAddVectorI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile i32* value) {
  return rbTreeAddVectorI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, i32 value) {
  return rbTreeAddVectorPI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile i32* value) {
  return rbTreeAddVectorPI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, u32 value) {
  return rbTreeAddVectorU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile u32* value) {
  return rbTreeAddVectorU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, u32 value) {
  return rbTreeAddVectorPU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile u32* value) {
  return rbTreeAddVectorPU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, i64 value) {
  return rbTreeAddVectorI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile i64* value) {
  return rbTreeAddVectorI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, i64 value) {
  return rbTreeAddVectorPI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile i64* value) {
  return rbTreeAddVectorPI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, u64 value) {
  return rbTreeAddVectorU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile u64* value) {
  return rbTreeAddVectorU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, u64 value) {
  return rbTreeAddVectorPU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile u64* value) {
  return rbTreeAddVectorPU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, float value) {
  return rbTreeAddVectorFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile float* value) {
  return rbTreeAddVectorFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, float value) {
  return rbTreeAddVectorPFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile float* value) {
  return rbTreeAddVectorPFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, double value) {
  return rbTreeAddVectorDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile double* value) {
  return rbTreeAddVectorDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, double value) {
  return rbTreeAddVectorPDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile double* value) {
  return rbTreeAddVectorPDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, long double value) {
  return rbTreeAddVectorLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile long double* value) {
  return rbTreeAddVectorLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, long double value) {
  return rbTreeAddVectorPLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile long double* value) {
  return rbTreeAddVectorPLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, List value) {
  return rbTreeAddVectorList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile List* value) {
  return rbTreeAddVectorListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, List value) {
  return rbTreeAddVectorPList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile List* value) {
  return rbTreeAddVectorPListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, Queue value) {
  return rbTreeAddVectorQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile Queue* value) {
  return rbTreeAddVectorQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, Queue value) {
  return rbTreeAddVectorPQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile Queue* value) {
  return rbTreeAddVectorPQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, Stack value) {
  return rbTreeAddVectorStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile Stack* value) {
  return rbTreeAddVectorStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, Stack value) {
  return rbTreeAddVectorPStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile Stack* value) {
  return rbTreeAddVectorPStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, RedBlackTree value) {
  return rbTreeAddVectorRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile RedBlackTree* value) {
  return rbTreeAddVectorRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, RedBlackTree value) {
  return rbTreeAddVectorPRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile RedBlackTree* value) {
  return rbTreeAddVectorPRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, HashTable value) {
  return rbTreeAddVectorHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile HashTable* value) {
  return rbTreeAddVectorHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, HashTable value) {
  return rbTreeAddVectorPHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile HashTable* value) {
  return rbTreeAddVectorPHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, Vector value) {
  return rbTreeAddVectorVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile Vector* value) {
  return rbTreeAddVectorVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, Vector value) {
  return rbTreeAddVectorPVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile Vector* value) {
  return rbTreeAddVectorPVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile char* value) {
  return rbTreeAddVectorString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile char** value) {
  return rbTreeAddVectorStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile char* value) {
  return rbTreeAddVectorPString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile char** value) {
  return rbTreeAddVectorPStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, Bytes value) {
  return rbTreeAddVectorBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile Bytes* value) {
  return rbTreeAddVectorBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, Bytes value) {
  return rbTreeAddVectorPBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile Bytes* value) {
  return rbTreeAddVectorPBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, void* value) {
  return rbTreeAddVectorPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, const volatile void** value) {
  return rbTreeAddVectorPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, void* value) {
  return rbTreeAddVectorPPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, const volatile void** value) {
  return rbTreeAddVectorPPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, i8 value) {
  return rbTreeAddVectorI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, i8 value) {
  return rbTreeAddVectorPI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Vector key, u8 value) {
  return rbTreeAddVectorU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Vector* key, u8 value) {
  return rbTreeAddVectorPU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, bool value) {
  return rbTreeAddStringBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile bool* value) {
  return rbTreeAddStringBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, bool value) {
  return rbTreeAddStringPBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile bool* value) {
  return rbTreeAddStringPBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, i16 value) {
  return rbTreeAddStringI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile i16* value) {
  return rbTreeAddStringI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, i16 value) {
  return rbTreeAddStringPI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile i16* value) {
  return rbTreeAddStringPI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, u16 value) {
  return rbTreeAddStringU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile u16* value) {
  return rbTreeAddStringU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, u16 value) {
  return rbTreeAddStringPU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile u16* value) {
  return rbTreeAddStringPU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, i32 value) {
  return rbTreeAddStringI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile i32* value) {
  return rbTreeAddStringI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, i32 value) {
  return rbTreeAddStringPI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile i32* value) {
  return rbTreeAddStringPI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, u32 value) {
  return rbTreeAddStringU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile u32* value) {
  return rbTreeAddStringU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, u32 value) {
  return rbTreeAddStringPU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile u32* value) {
  return rbTreeAddStringPU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, i64 value) {
  return rbTreeAddStringI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile i64* value) {
  return rbTreeAddStringI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, i64 value) {
  return rbTreeAddStringPI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile i64* value) {
  return rbTreeAddStringPI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, u64 value) {
  return rbTreeAddStringU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile u64* value) {
  return rbTreeAddStringU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, u64 value) {
  return rbTreeAddStringPU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile u64* value) {
  return rbTreeAddStringPU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, float value) {
  return rbTreeAddStringFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile float* value) {
  return rbTreeAddStringFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, float value) {
  return rbTreeAddStringPFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile float* value) {
  return rbTreeAddStringPFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, double value) {
  return rbTreeAddStringDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile double* value) {
  return rbTreeAddStringDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, double value) {
  return rbTreeAddStringPDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile double* value) {
  return rbTreeAddStringPDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, long double value) {
  return rbTreeAddStringLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile long double* value) {
  return rbTreeAddStringLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, long double value) {
  return rbTreeAddStringPLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile long double* value) {
  return rbTreeAddStringPLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, List value) {
  return rbTreeAddStringList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile List* value) {
  return rbTreeAddStringListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, List value) {
  return rbTreeAddStringPList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile List* value) {
  return rbTreeAddStringPListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, Queue value) {
  return rbTreeAddStringQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile Queue* value) {
  return rbTreeAddStringQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, Queue value) {
  return rbTreeAddStringPQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile Queue* value) {
  return rbTreeAddStringPQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, Stack value) {
  return rbTreeAddStringStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile Stack* value) {
  return rbTreeAddStringStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, Stack value) {
  return rbTreeAddStringPStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile Stack* value) {
  return rbTreeAddStringPStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, RedBlackTree value) {
  return rbTreeAddStringRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile RedBlackTree* value) {
  return rbTreeAddStringRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, RedBlackTree value) {
  return rbTreeAddStringPRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile RedBlackTree* value) {
  return rbTreeAddStringPRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, HashTable value) {
  return rbTreeAddStringHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile HashTable* value) {
  return rbTreeAddStringHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, HashTable value) {
  return rbTreeAddStringPHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile HashTable* value) {
  return rbTreeAddStringPHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, Vector value) {
  return rbTreeAddStringVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile Vector* value) {
  return rbTreeAddStringVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, Vector value) {
  return rbTreeAddStringPVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile Vector* value) {
  return rbTreeAddStringPVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile char* value) {
  return rbTreeAddStringString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile char** value) {
  return rbTreeAddStringStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile char* value) {
  return rbTreeAddStringPString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile char** value) {
  return rbTreeAddStringPStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, Bytes value) {
  return rbTreeAddStringBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile Bytes* value) {
  return rbTreeAddStringBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, Bytes value) {
  return rbTreeAddStringPBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile Bytes* value) {
  return rbTreeAddStringPBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, void* value) {
  return rbTreeAddStringPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, const volatile void** value) {
  return rbTreeAddStringPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, void* value) {
  return rbTreeAddStringPPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, const volatile void** value) {
  return rbTreeAddStringPPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, i8 value) {
  return rbTreeAddStringI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, i8 value) {
  return rbTreeAddStringPI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char* key, u8 value) {
  return rbTreeAddStringU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile char** key, u8 value) {
  return rbTreeAddStringPU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, bool value) {
  return rbTreeAddBytesBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile bool* value) {
  return rbTreeAddBytesBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, bool value) {
  return rbTreeAddBytesPBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile bool* value) {
  return rbTreeAddBytesPBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, i16 value) {
  return rbTreeAddBytesI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile i16* value) {
  return rbTreeAddBytesI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, i16 value) {
  return rbTreeAddBytesPI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile i16* value) {
  return rbTreeAddBytesPI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, u16 value) {
  return rbTreeAddBytesU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile u16* value) {
  return rbTreeAddBytesU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, u16 value) {
  return rbTreeAddBytesPU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile u16* value) {
  return rbTreeAddBytesPU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, i32 value) {
  return rbTreeAddBytesI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile i32* value) {
  return rbTreeAddBytesI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, i32 value) {
  return rbTreeAddBytesPI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile i32* value) {
  return rbTreeAddBytesPI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, u32 value) {
  return rbTreeAddBytesU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile u32* value) {
  return rbTreeAddBytesU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, u32 value) {
  return rbTreeAddBytesPU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile u32* value) {
  return rbTreeAddBytesPU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, i64 value) {
  return rbTreeAddBytesI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile i64* value) {
  return rbTreeAddBytesI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, i64 value) {
  return rbTreeAddBytesPI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile i64* value) {
  return rbTreeAddBytesPI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, u64 value) {
  return rbTreeAddBytesU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile u64* value) {
  return rbTreeAddBytesU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, u64 value) {
  return rbTreeAddBytesPU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile u64* value) {
  return rbTreeAddBytesPU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, float value) {
  return rbTreeAddBytesFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile float* value) {
  return rbTreeAddBytesFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, float value) {
  return rbTreeAddBytesPFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile float* value) {
  return rbTreeAddBytesPFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, double value) {
  return rbTreeAddBytesDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile double* value) {
  return rbTreeAddBytesDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, double value) {
  return rbTreeAddBytesPDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile double* value) {
  return rbTreeAddBytesPDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, long double value) {
  return rbTreeAddBytesLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile long double* value) {
  return rbTreeAddBytesLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, long double value) {
  return rbTreeAddBytesPLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile long double* value) {
  return rbTreeAddBytesPLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, List value) {
  return rbTreeAddBytesList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile List* value) {
  return rbTreeAddBytesListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, List value) {
  return rbTreeAddBytesPList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile List* value) {
  return rbTreeAddBytesPListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, Queue value) {
  return rbTreeAddBytesQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile Queue* value) {
  return rbTreeAddBytesQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, Queue value) {
  return rbTreeAddBytesPQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile Queue* value) {
  return rbTreeAddBytesPQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, Stack value) {
  return rbTreeAddBytesStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile Stack* value) {
  return rbTreeAddBytesStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, Stack value) {
  return rbTreeAddBytesPStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile Stack* value) {
  return rbTreeAddBytesPStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, RedBlackTree value) {
  return rbTreeAddBytesRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile RedBlackTree* value) {
  return rbTreeAddBytesRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, RedBlackTree value) {
  return rbTreeAddBytesPRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile RedBlackTree* value) {
  return rbTreeAddBytesPRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, HashTable value) {
  return rbTreeAddBytesHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile HashTable* value) {
  return rbTreeAddBytesHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, HashTable value) {
  return rbTreeAddBytesPHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile HashTable* value) {
  return rbTreeAddBytesPHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, Vector value) {
  return rbTreeAddBytesVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile Vector* value) {
  return rbTreeAddBytesVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, Vector value) {
  return rbTreeAddBytesPVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile Vector* value) {
  return rbTreeAddBytesPVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile char* value) {
  return rbTreeAddBytesString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile char** value) {
  return rbTreeAddBytesStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile char* value) {
  return rbTreeAddBytesPString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile char** value) {
  return rbTreeAddBytesPStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, Bytes value) {
  return rbTreeAddBytesBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile Bytes* value) {
  return rbTreeAddBytesBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, Bytes value) {
  return rbTreeAddBytesPBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile Bytes* value) {
  return rbTreeAddBytesPBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, void* value) {
  return rbTreeAddBytesPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, const volatile void** value) {
  return rbTreeAddBytesPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, void* value) {
  return rbTreeAddBytesPPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, const volatile void** value) {
  return rbTreeAddBytesPPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, i8 value) {
  return rbTreeAddBytesI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, i8 value) {
  return rbTreeAddBytesPI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, Bytes key, u8 value) {
  return rbTreeAddBytesU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile Bytes* key, u8 value) {
  return rbTreeAddBytesPU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, bool value) {
  return rbTreeAddPointerBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile bool* value) {
  return rbTreeAddPointerBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, bool value) {
  return rbTreeAddPointerPBool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile bool* value) {
  return rbTreeAddPointerPBoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, i16 value) {
  return rbTreeAddPointerI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile i16* value) {
  return rbTreeAddPointerI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, i16 value) {
  return rbTreeAddPointerPI16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile i16* value) {
  return rbTreeAddPointerPI16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, u16 value) {
  return rbTreeAddPointerU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile u16* value) {
  return rbTreeAddPointerU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, u16 value) {
  return rbTreeAddPointerPU16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile u16* value) {
  return rbTreeAddPointerPU16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, i32 value) {
  return rbTreeAddPointerI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile i32* value) {
  return rbTreeAddPointerI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, i32 value) {
  return rbTreeAddPointerPI32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile i32* value) {
  return rbTreeAddPointerPI32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, u32 value) {
  return rbTreeAddPointerU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile u32* value) {
  return rbTreeAddPointerU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, u32 value) {
  return rbTreeAddPointerPU32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile u32* value) {
  return rbTreeAddPointerPU32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, i64 value) {
  return rbTreeAddPointerI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile i64* value) {
  return rbTreeAddPointerI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, i64 value) {
  return rbTreeAddPointerPI64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile i64* value) {
  return rbTreeAddPointerPI64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, u64 value) {
  return rbTreeAddPointerU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile u64* value) {
  return rbTreeAddPointerU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, u64 value) {
  return rbTreeAddPointerPU64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile u64* value) {
  return rbTreeAddPointerPU64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, float value) {
  return rbTreeAddPointerFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile float* value) {
  return rbTreeAddPointerFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, float value) {
  return rbTreeAddPointerPFloat(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile float* value) {
  return rbTreeAddPointerPFloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, double value) {
  return rbTreeAddPointerDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile double* value) {
  return rbTreeAddPointerDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, double value) {
  return rbTreeAddPointerPDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile double* value) {
  return rbTreeAddPointerPDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, long double value) {
  return rbTreeAddPointerLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile long double* value) {
  return rbTreeAddPointerLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, long double value) {
  return rbTreeAddPointerPLongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile long double* value) {
  return rbTreeAddPointerPLongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, List value) {
  return rbTreeAddPointerList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile List* value) {
  return rbTreeAddPointerListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, List value) {
  return rbTreeAddPointerPList(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile List* value) {
  return rbTreeAddPointerPListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, Queue value) {
  return rbTreeAddPointerQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile Queue* value) {
  return rbTreeAddPointerQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, Queue value) {
  return rbTreeAddPointerPQueue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile Queue* value) {
  return rbTreeAddPointerPQueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, Stack value) {
  return rbTreeAddPointerStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile Stack* value) {
  return rbTreeAddPointerStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, Stack value) {
  return rbTreeAddPointerPStack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile Stack* value) {
  return rbTreeAddPointerPStackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, RedBlackTree value) {
  return rbTreeAddPointerRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile RedBlackTree* value) {
  return rbTreeAddPointerRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, RedBlackTree value) {
  return rbTreeAddPointerPRedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile RedBlackTree* value) {
  return rbTreeAddPointerPRedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, HashTable value) {
  return rbTreeAddPointerHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile HashTable* value) {
  return rbTreeAddPointerHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, HashTable value) {
  return rbTreeAddPointerPHashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile HashTable* value) {
  return rbTreeAddPointerPHashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, Vector value) {
  return rbTreeAddPointerVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile Vector* value) {
  return rbTreeAddPointerVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, Vector value) {
  return rbTreeAddPointerPVector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile Vector* value) {
  return rbTreeAddPointerPVectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile char* value) {
  return rbTreeAddPointerString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile char** value) {
  return rbTreeAddPointerStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile char* value) {
  return rbTreeAddPointerPString(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile char** value) {
  return rbTreeAddPointerPStringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, Bytes value) {
  return rbTreeAddPointerBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile Bytes* value) {
  return rbTreeAddPointerBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, Bytes value) {
  return rbTreeAddPointerPBytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile Bytes* value) {
  return rbTreeAddPointerPBytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, void* value) {
  return rbTreeAddPointerPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, const volatile void** value) {
  return rbTreeAddPointerPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, void* value) {
  return rbTreeAddPointerPPointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, const volatile void** value) {
  return rbTreeAddPointerPPointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, i8 value) {
  return rbTreeAddPointerI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, i8 value) {
  return rbTreeAddPointerPI8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, void* key, u8 value) {
  return rbTreeAddPointerU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, const volatile void** key, u8 value) {
  return rbTreeAddPointerPU8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, bool value) {
  return rbTreeAddI8Bool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile bool* value) {
  return rbTreeAddI8BoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, i16 value) {
  return rbTreeAddI8I16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile i16* value) {
  return rbTreeAddI8I16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, u16 value) {
  return rbTreeAddI8U16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile u16* value) {
  return rbTreeAddI8U16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, i32 value) {
  return rbTreeAddI8I32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile i32* value) {
  return rbTreeAddI8I32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, u32 value) {
  return rbTreeAddI8U32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile u32* value) {
  return rbTreeAddI8U32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, i64 value) {
  return rbTreeAddI8I64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile i64* value) {
  return rbTreeAddI8I64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, u64 value) {
  return rbTreeAddI8U64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile u64* value) {
  return rbTreeAddI8U64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, float value) {
  return rbTreeAddI8Float(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile float* value) {
  return rbTreeAddI8FloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, double value) {
  return rbTreeAddI8Double(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile double* value) {
  return rbTreeAddI8DoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, long double value) {
  return rbTreeAddI8LongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile long double* value) {
  return rbTreeAddI8LongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, List value) {
  return rbTreeAddI8List(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile List* value) {
  return rbTreeAddI8ListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, Queue value) {
  return rbTreeAddI8Queue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile Queue* value) {
  return rbTreeAddI8QueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, Stack value) {
  return rbTreeAddI8Stack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile Stack* value) {
  return rbTreeAddI8StackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, RedBlackTree value) {
  return rbTreeAddI8RedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile RedBlackTree* value) {
  return rbTreeAddI8RedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, HashTable value) {
  return rbTreeAddI8HashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile HashTable* value) {
  return rbTreeAddI8HashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, Vector value) {
  return rbTreeAddI8Vector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile Vector* value) {
  return rbTreeAddI8VectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile char* value) {
  return rbTreeAddI8String(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile char** value) {
  return rbTreeAddI8StringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, Bytes value) {
  return rbTreeAddI8Bytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile Bytes* value) {
  return rbTreeAddI8BytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, void* value) {
  return rbTreeAddI8Pointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, const volatile void** value) {
  return rbTreeAddI8PointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, i8 value) {
  return rbTreeAddI8I8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, i8 key, u8 value) {
  return rbTreeAddI8U8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, bool value) {
  return rbTreeAddU8Bool(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile bool* value) {
  return rbTreeAddU8BoolP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, i16 value) {
  return rbTreeAddU8I16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile i16* value) {
  return rbTreeAddU8I16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, u16 value) {
  return rbTreeAddU8U16(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile u16* value) {
  return rbTreeAddU8U16P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, i32 value) {
  return rbTreeAddU8I32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile i32* value) {
  return rbTreeAddU8I32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, u32 value) {
  return rbTreeAddU8U32(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile u32* value) {
  return rbTreeAddU8U32P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, i64 value) {
  return rbTreeAddU8I64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile i64* value) {
  return rbTreeAddU8I64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, u64 value) {
  return rbTreeAddU8U64(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile u64* value) {
  return rbTreeAddU8U64P(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, float value) {
  return rbTreeAddU8Float(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile float* value) {
  return rbTreeAddU8FloatP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, double value) {
  return rbTreeAddU8Double(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile double* value) {
  return rbTreeAddU8DoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, long double value) {
  return rbTreeAddU8LongDouble(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile long double* value) {
  return rbTreeAddU8LongDoubleP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, List value) {
  return rbTreeAddU8List(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile List* value) {
  return rbTreeAddU8ListP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, Queue value) {
  return rbTreeAddU8Queue(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile Queue* value) {
  return rbTreeAddU8QueueP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, Stack value) {
  return rbTreeAddU8Stack(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile Stack* value) {
  return rbTreeAddU8StackP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, RedBlackTree value) {
  return rbTreeAddU8RedBlackTree(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile RedBlackTree* value) {
  return rbTreeAddU8RedBlackTreeP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, HashTable value) {
  return rbTreeAddU8HashTable(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile HashTable* value) {
  return rbTreeAddU8HashTableP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, Vector value) {
  return rbTreeAddU8Vector(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile Vector* value) {
  return rbTreeAddU8VectorP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile char* value) {
  return rbTreeAddU8String(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile char** value) {
  return rbTreeAddU8StringP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, Bytes value) {
  return rbTreeAddU8Bytes(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile Bytes* value) {
  return rbTreeAddU8BytesP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, void* value) {
  return rbTreeAddU8Pointer(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, const volatile void** value) {
  return rbTreeAddU8PointerP(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, i8 value) {
  return rbTreeAddU8I8(dataStructure, key, value);
}
static inline RedBlackTreeNode* rbTreeAdd(RedBlackTree *dataStructure, u8 key, u8 value) {
  return rbTreeAddU8U8(dataStructure, key, value);
}

#endif // __cplusplus

#endif // TYPE_SAFE_RB_TREE_ADD_H

