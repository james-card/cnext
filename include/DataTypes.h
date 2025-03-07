///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              03.02.2019
///
/// @file              DataTypes.h
///
/// @brief             This library contains the function and structure
///                    definitions that data structure libraries make use
///                    of.
///
/// @details
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

#ifndef DATA_TYPES_H
#define DATA_TYPES_H

#include "TypeDefinitions.h"
#include "CThreads.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

/// @def REGISTER_INT
///
/// @brief Unsigned integer type that is the optimal width of the processor.
/// We're assuming we're not running on anything smaller than a 32-bit processor
/// so the only options are 32-bit or 64-bit.  Note that this type *MUST* be an
/// unsinged type for everything to work correctly.  The user can provide a
/// different type than we determine here by defining REGISTER_INT on the
/// command line if desired.

/// @def REGISTER_BIT_WIDTH
/// Number of bits in a REGISTER_INT integer.  This is used for hash table
///   calculations.

#ifndef REGISTER_INT

#ifdef _MSC_VER
// MSVC
#ifdef _WIN64
#define REGISTER_INT u64
#define REGISTER_BIT_WIDTH 64
#else
#define REGISTER_INT u32
#define REGISTER_BIT_WIDTH 32
#endif

#elif __GNUC__
// gcc
#if __x86_64__ || __ppc64__
#define REGISTER_INT u64
#define REGISTER_BIT_WIDTH 64
#else
#define REGISTER_INT u32
#define REGISTER_BIT_WIDTH 32
#endif

#else
// Unknown compiler.  Assume 32-bit.
#define REGISTER_INT u32
#define REGISTER_BIT_WIDTH 32

#endif // compiler check

#endif // REGISTER_INT

/// @def literal
/// Convenience macro for defining a literal constant value.
#if (REGISTER_INT == u64)
#define literal(x) ((u64) x)
#else
#define literal(x) (x)
#endif

extern const bool       boolZero;
extern const i8         i8Zero;
extern const u8         u8Zero;
extern const i16        i16Zero;
extern const u16        u16Zero;
extern const i32        i32Zero;
extern const u32        u32Zero;
extern const i64        i64Zero;
extern const u64        u64Zero;
extern const i128       i128Zero;
extern const u128       u128Zero;
extern const float      floatZero;
extern const double     doubleZero;
extern const longDouble longDoubleZero;

extern const char *boolNames[2];

bool stringIsInteger(const char *str);
bool stringIsFloat(const char *str);
bool stringIsNumber(const char *str);
bool stringIsBoolean(const char *str);
bool strtobool(const char *str, char **endptr);

/// @struct TypeDescriptor
/// @brief This is the set of information required to describe any type of
///   data in the general data structures.
/// @param name The C-string representation of the name of the type.
/// @param xmlName The name of the XML type that is used to describe this type.
/// @param dataIsPointer Whether or not the data type is managed by its pointer
///   instead of the value at the pointer.  This will be true for strings,
///   Bytes, and raw pointer values.
/// @param toString Pointer to the function that will return a C-string
///   representation of the value.
/// @param toBytes Pointer to the function that will return a Bytes object
///   representation of the value.
/// @param compare Pointer to the function that will commpare two values of
///   this type and evaluate them.  Will return <0 if valueA < valueB, 0 if
///   valueA = valueB, or >0 if valueA > valueB.
/// @param create Pointer to the function that will allocate and initialize
///   a value of this type.
/// @param copy Pointer to the function that will create a new value of this
///   type and initialize it to the same value as the input value.
/// @param destroy Pointer to the function that will deallocate a value of
///   this type and return NULL on success.
/// @param size A function that returns the amount of space in memory occupied
///   by a specific instance of this type.  Note that this must be a function
///   to account for variable-length types such as strings and UTF-8 characters.
/// @param toBlob A function that converts the data into an array of bytes
///   that can then be exported or converted back into a data element via
///   fromBlob.
/// @param fromBlob A function that converts an array of bytes output by
///   toBlob back into a data element of the data type.
/// @param hashFunction A function that hashes the data of the type into an
///   integer value.  This member is optional.  The default hash algorithm will
///   be used in the hash table logic if it's omitted.
/// @param clear A function the clears but does not deallocate the value.
/// @param toXml A function that converts the data to an XML representation.
/// @param toJson A function that converts the data to a JSON representation.
typedef struct TypeDescriptor {
  const char    *name;
  const char    *xmlName;
  bool           dataIsPointer;
  char*        (*toString)(const volatile void *value);
  Bytes        (*toBytes)(const volatile void *value);
  int          (*compare)(const volatile void *valueA, const volatile void *valueB);
  void*        (*create)(const volatile void *parameter1, ...);
  void*        (*copy)(const volatile void *value);
  void*        (*destroy)(volatile void *value);
  size_t       (*size)(const volatile void *value);
  Bytes        (*toBlob)(const volatile void *value);
  void*        (*fromBlob)(const volatile void *value, u64 *length, bool inPlaceData, bool disableThreadSafety);
  u64          (*hashFunction)(const volatile void *value);
  i32          (*clear)(volatile void *value);
  Bytes        (*toXml)(const volatile void*, const char *elementName, bool indent, ...);
  Bytes        (*toJson)(const volatile void*);
} TypeDescriptor;

/// @struct Variant
///
/// @brief Structure representing a single value of a specified type.
///
/// @param type A pointer to a TypeDescriptor describing the value stored in
///   the node.
/// @param value Pointer to the value stored in this node.
typedef struct Variant {
  volatile void *value;
  TypeDescriptor *type;
} Variant;

/// @struct ListNode
///
/// @brief Structure representing a single element of a linked list.
///
/// @note The first two elements of this structure *MUST* match a Variant.
///
/// @param type A pointer to a TypeDescriptor describing the value stored in
///   the node.
/// @param value Pointer to the value stored in this node.
/// @param key A pointer to the key associated with this node (if any).
/// @param prev A pointer to the previous node in the list.
/// @param next A pointer to the next node in the list.
/// @param byteOffset The offset into a file where the value is located
///   (if any).
typedef struct ListNode {
  // The first two items must be compatible with Variant.
  volatile void *value;
  TypeDescriptor *type;
  void *key;
  struct ListNode *prev;
  struct ListNode *next;
  i64 byteOffset; // Must be signed to be compatible with fseeko64.
} ListNode;

/// @struct List
///
/// @brief Structure representing a full linked list.
///
/// @param head A pointer to the first ListNode in the list.
/// @param tail A pointer to the last ListNode in the list.
/// @param size The number of elements in the list.
/// @param keyType A pointer to a TypeDescriptor describing the keys used in
///   the list.
/// @param filePointer A pointer to the on-disk data for the list.
/// @param lock A pointer to a mutex that guards access to this list.
typedef struct List {
  ListNode *head;
  ListNode *tail;
  u64 size;
  TypeDescriptor *keyType;
  FILE *filePointer;
  mtx_t *lock;
} List;

typedef struct ListNode QueueNode;

/// @struct Queue
///
/// @brief Structure representing a full queue.
///
/// @note This structure must be defined identically to the List structure.
///
/// @param head A pointer to the first QueueNode in the queue.
/// @param tail A pointer to the last QueueNode in the queue.
/// @param size The number of elements in the queue.
/// @param keyType A pointer to a TypeDescriptor describing the keys used in
///   the queue.
/// @param filePointer A pointer to the on-disk data for the queue.
/// @param lock A pointer to a mutex that guards access to this queue.
typedef struct Queue {
  QueueNode *head;
  QueueNode *tail;
  u64 size;
  TypeDescriptor *keyType;
  FILE *filePointer;
  mtx_t *lock;
} Queue;

typedef struct ListNode StackNode;

/// @struct Stack
///
/// @brief Structure representing a full stack.
///
/// @note This structure must be defined identically to the List structure.
///
/// @param head A pointer to the first StackNode in the queue.
/// @param tail A pointer to the last StackNode in the queue.
/// @param size The number of elements in the queue.
/// @param keyType A pointer to a TypeDescriptor describing the keys used in
///   the queue.
/// @param filePointer A pointer to the on-disk data for the queue.
/// @param lock A pointer to a mutex that guards access to this queue.
typedef struct Stack {
  StackNode *head;
  StackNode *tail;
  u64 size;
  TypeDescriptor *keyType;
  FILE *filePointer;
  mtx_t *lock;
} Stack;

/// @struct RedBlackNode
///
/// @brief Node for containing data in a red-black tree.
///
/// @note The beginning of this structure *MUST* match a ListNode.
///
/// @param type A pointer to a TypeDescriptor describing the data in the
///   value pointer.
/// @param value A pointer to the data held by this node.
/// @param key A pointer to the key associated with this value.
/// @param prev A pointer to the predecessor node in the tree.
/// @param next A pointer to the successor node in the tree.
/// @param byteOffset The offset into a file where the value is located
///   (if any).
/// @param red A boolean to indicate whether the node is red or black.  If
///   red == false then the node is black.
/// @param left A pointer to the node to the left of this one in the tree.
/// @param right A pointer to the node to the right of this one.
/// @param parent A pointer to the parent of this node in the tree.
typedef struct RedBlackNode {
  // The first six items must be compatible with ListNode.
  volatile void *value;
  TypeDescriptor *type;
  void *key;
  struct RedBlackNode *prev;
  struct RedBlackNode *next;
  i64 byteOffset; // Must be signed to be compatible with fseeko64.
  bool red; // if red == false then the node is black
  struct RedBlackNode *left;
  struct RedBlackNode *right;
  struct RedBlackNode *parent;
} RedBlackNode;
#define RedBlackTreeNode RedBlackNode

/// @struct RedBlackTree
///
/// @brief Structure defining the contents of a red-black tree.
///
/// @note The beginning of this structure *MUST* match a List.
///
/// @param head The head of the linked-list version of the tree.
/// @param tail The tail of the linked-list version of the tree.
/// @param size A count of the number of data nodes in the tree.
/// @param keyType A pointer to a TypeDescriptor describing how to interact
///   with the keys in this tree.
/// @param filePointer A pointer to an on-disk representation of the tree
///   (if any).
/// @param lock A pointer to a mutex that guards the tree in multi-threaded
///   environments.
/// @param lastAddedType TypeDescriptor describing the kind data for the last
///   value added.
/// @param root A pointer to the root node of the tree.
/// @param nil A pointer to a terminating node in the tree.
typedef struct RedBlackTree {
  // The first six items must be compatible with List.
  RedBlackNode *head;
  RedBlackNode *tail;
  u64 size;
  TypeDescriptor *keyType;
  FILE *filePointer;
  mtx_t *lock;
  TypeDescriptor *lastAddedType;
  // A sentinel is used for root and for nil.  These sentinels are
  // created when rbTreeCreate is caled.  root->left should always
  // point to the node which is the root of the tree.  nil points to a
  // node which should always be black but has aribtrary children and
  // parent and no key or value.  The point of using these sentinels is so
  // that the root and nil nodes do not require special cases in the code.
  RedBlackNode *root;             
  RedBlackNode *nil;              
} RedBlackTree;

typedef struct RedBlackNode HashNode;

/// @struct HashTable
///
/// @brief Hash table object definition.  The first six elements must be
/// compatible with List.
///
/// @param head A pointer to the first HashNode in the hash table.
/// @param tail A pointer to the last HashNode in the hash table.
/// @param size The number of elements in the hash table.  This number will
///   equal the sum of the sizes of all red-black trees in the table.
/// @param keyType A pointer to a TypeDescriptor describing the keys used in
///   the hash table.
/// @param filePointer A pointer to the on-disk data for the hash table.
/// @param lock A pointer to a mutex that guards access to this hash table.
/// @param lastAddedType TypeDescriptor describing the kind data for the last
///   value added.
/// @param tableSize The number of red-black trees in the table.
/// @param table The array of red-black trees for the table.
typedef struct HashTable {
  HashNode *head;
  HashNode *tail;
  u64 size;
  TypeDescriptor *keyType;
  FILE *filePointer;
  mtx_t *lock;
  TypeDescriptor *lastAddedType;
  u64 tableSize;
  RedBlackTree **table;
} HashTable;

/// @struct VectorNode
///
/// @brief Structure representing a single element of a vector.
///
/// @note The first six elements of this structure *MUST* match ListNode.
///
/// @param type A pointer to a TypeDescriptor describing the value stored in
///   the node.
/// @param value Pointer to the value stored in this node.
/// @param key A pointer to the key associated with this node (if any).
/// @param prev A pointer to the previous node in the list.
/// @param next A pointer to the next node in the list.
/// @param byteOffset The offset into a file where the value is located
///   (if any).
/// @param allocated Whether or not the value at this node is allocated and
///   valid.
typedef struct VectorNode {
  // The first two items must be compatible with Variant.
  volatile void *value;
  TypeDescriptor *type;
  void *key;
  struct VectorNode *prev;
  struct VectorNode *next;
  i64 byteOffset; // Must be signed to be compatible with fseeko64.
  bool allocated;
  u64 index; // For sorting algorithm.
} VectorNode;

typedef VectorNode KvVectorNode;
typedef VectorNode ArrayNode;
typedef VectorNode KvArrayNode;

/// @struct Vector
///
/// @brief Structure representing a full vector.
///
/// @param head A pointer to the first VectorNode in the vector.
/// @param tail A pointer to the last VectorNode in the vector.
/// @param size The number of elements in the vector.  This value is less than
///   or equal to the value of arraySize.
/// @param keyType A pointer to a TypeDescriptor describing the keys used in
///   the vector (if any).
/// @param filePointer A pointer to a FILE object for on-disk data (if any).
/// @param lock A pointer to a mutex to guard the Vector in multi-threaded
///   environments.
/// @param valueType A pointer to a TypeDescriptor describing the values used
///   in the vector.  This value may be NULL initially.  It may only be set
///   once.
/// @param arraySize The number of VectorNodes allocated in the array element.
/// @param array An array of VectorNodes for indexed lookup of vector content.
/// @param data A pointer to the actual data that's stored by the vector.
typedef struct Vector {
  // The first six items must be compatible with List.
  VectorNode *head;
  VectorNode *tail;
  u64 size;
  TypeDescriptor *keyType;
  FILE *filePointer;
  mtx_t *lock;
  TypeDescriptor *valueType;
  u64 arraySize;
  VectorNode *array;
  void *data;
} Vector;

typedef Vector KvVector;

/// @struct Array
///
/// @brief Structure representing a full array.
///
/// @param head A pointer to the first ArrayNode in the array.
/// @param tail A pointer to the last ArrayNode in the array.
/// @param size The number of elements in the array.  This value is less than
///   or equal to the value of arraySize.
/// @param keyType A pointer to a TypeDescriptor describing the keys used in
///   the array (if any).
/// @param filePointer A pointer to a FILE object for on-disk data (if any).
/// @param lock An embedded mutex to guard the Array in multi-threaded
///   environments.
/// @param lockInitialized A boolean to keep track of whether or not the lock
///   member variable has been initialized and may be used for mutual exclusion.
/// @param arraySize The number of ArrayNodes allocated in the array element.
/// @param data An array of ArrayNodes for indexed lookup of array content.
///   This is a flexible array member.  C++ doesn't allow flexible array
///   member variables of structs, so we can't declare it to be empty like it
///   should be and still have this code compile in C++.  Declare an embedded
///   array of size 1 here.  When we do the malloc, we'll declare the real size.
///   We can still access any number of elements as long as the memory is there.
typedef struct Array {
  // The first six items must be compatible with List.
  ArrayNode *head;
  ArrayNode *tail;
  u64 size;
  TypeDescriptor *keyType;
  FILE *filePointer;
  mtx_t lock;
  bool lockInitialized;
  u64 arraySize;
  ArrayNode data[1];
} Array;

#define EMPTY_ARRAY_SIZE (sizeof(Array) - sizeof(ArrayNode))

typedef Array KvArray;


extern TypeDescriptor *typeBool;
extern TypeDescriptor *typeBoolNoCopy;
extern TypeDescriptor *typeU8;
extern TypeDescriptor *typeU8NoCopy;
extern TypeDescriptor *typeU16;
extern TypeDescriptor *typeU16NoCopy;
extern TypeDescriptor *typeU32;
extern TypeDescriptor *typeU32NoCopy;
extern TypeDescriptor *typeU64;
extern TypeDescriptor *typeU64NoCopy;
extern TypeDescriptor *typeU128;
extern TypeDescriptor *typeU128NoCopy;
extern TypeDescriptor *typeI8;
extern TypeDescriptor *typeI8NoCopy;
extern TypeDescriptor *typeI16;
extern TypeDescriptor *typeI16NoCopy;
extern TypeDescriptor *typeI32;
extern TypeDescriptor *typeI32NoCopy;
extern TypeDescriptor *typeI64;
extern TypeDescriptor *typeI64NoCopy;
extern TypeDescriptor *typeI128;
extern TypeDescriptor *typeI128NoCopy;
extern TypeDescriptor *typeFloat;
extern TypeDescriptor *typeFloatNoCopy;
extern TypeDescriptor *typeDouble;
extern TypeDescriptor *typeDoubleNoCopy;
extern TypeDescriptor *typeLongDouble;
extern TypeDescriptor *typeLongDoubleNoCopy;
extern TypeDescriptor *typeString;
extern TypeDescriptor *typeStringNoCopy;
extern TypeDescriptor *typeStringCi;
extern TypeDescriptor *typeStringCiNoCopy;
extern TypeDescriptor *typeBytes;
extern TypeDescriptor *typeBytesNoCopy;
extern TypeDescriptor *typeList;
extern TypeDescriptor *typeListNoCopy;
extern TypeDescriptor *typeQueue;
extern TypeDescriptor *typeQueueNoCopy;
extern TypeDescriptor *typeStack;
extern TypeDescriptor *typeStackNoCopy;
extern TypeDescriptor *typeRbTree;
extern TypeDescriptor *typeRbTreeNoCopy;
#define typeRedBlackTree typeRbTree
#define typeRedBlackTreeNoCopy typeRbTreeNoCopy
extern TypeDescriptor *typeHashTable;
extern TypeDescriptor *typeHashTableNoCopy;
extern TypeDescriptor *typeVector;
extern TypeDescriptor *typeVectorNoCopy;
#define typeKvVector typeVector
#define typeKvVectorNoCopy typeVectorNoCopy
extern TypeDescriptor *typeArray;
extern TypeDescriptor *typeArrayNoCopy;
#define typeKvArray typeArray
#define typeKvArrayNoCopy typeArrayNoCopy
extern TypeDescriptor *typePointer;
extern TypeDescriptor *typePointerNoCopy;
extern TypeDescriptor *typePointerNoOwn;
extern TypeDescriptor *typeDescriptors[];

/// @def TypeDescriptorIndexes
///
/// @brief Mapping of type names to their indexes as returned by
/// getIndexFromTypeDescriptor.
typedef enum TypeDescriptorIndexes {
  TYPE_BOOL = 0,
  TYPE_BOOL_NO_COPY,
  TYPE_I8,
  TYPE_I8_NO_COPY,
  TYPE_U8,
  TYPE_U8_NO_COPY,
  TYPE_I16,
  TYPE_I16_NO_COPY,
  TYPE_U16,
  TYPE_U16_NO_COPY,
  TYPE_I32,
  TYPE_I32_NO_COPY,
  TYPE_U32,
  TYPE_U32_NO_COPY,
  TYPE_I64,
  TYPE_I64_NO_COPY,
  TYPE_U64,
  TYPE_U64_NO_COPY,
  TYPE_I128,
  TYPE_I128_NO_COPY,
  TYPE_U128,
  TYPE_U128_NO_COPY,
  TYPE_FLOAT,
  TYPE_FLOAT_NO_COPY,
  TYPE_DOUBLE,
  TYPE_DOUBLE_NO_COPY,
  TYPE_LONG_DOUBLE,
  TYPE_LONG_DOUBLE_NO_COPY,
  TYPE_STRING,
  TYPE_STRING_NO_COPY,
  TYPE_STRING_CI,
  TYPE_STRING_CI_NO_COPY,
  TYPE_BYTES,
  TYPE_BYTES_NO_COPY,
  TYPE_LIST,
  TYPE_LIST_NO_COPY,
  TYPE_QUEUE,
  TYPE_QUEUE_NO_COPY,
  TYPE_STACK,
  TYPE_STACK_NO_COPY,
  TYPE_RB_TREE,
  TYPE_RB_TREE_NO_COPY,
  TYPE_HASH_TABLE,
  TYPE_HASH_TABLE_NO_COPY,
  TYPE_VECTOR,
  TYPE_VECTOR_NO_COPY,
  //// TYPE_ARRAY,
  //// TYPE_ARRAY_NO_COPY,
  TYPE_POINTER, // Must be next-to-last
  TYPE_POINTER_NO_COPY, // Must be last
  NUM_TYPE_DESCRIPTOR_INDEXES
} TypeDescriptorIndexes;

/// @union EndianUnion
///
/// @brief Union for determining whether or not the host is a little endian
/// system.
typedef union EndianUnion {
  int integer;
  char character;
} EndianUnion;

/// @var littleEndianUnion
///
/// @brief Constant variable that concretely identifies whether or not the
/// system is little endian.
extern const EndianUnion littleEndianUnion;

/// @def HOST_IS_LITTLE_ENDIAN
///
/// @brief Define that can be used to determine whether or not the system is
/// little endian from anywhere that links to this library.
#define HOST_IS_LITTLE_ENDIAN littleEndianUnion.character

// C and C++ treat the empty part of the ?: differently.
#ifdef __cplusplus
#define TRINARY_ZERO (( 0 ))
#else // C
#define TRINARY_ZERO ((void) 0)
#endif

void *shallowCopy(const volatile void *value);
void *nullFunction(volatile void *value, ...);
i32 clearNull(volatile void *value);
i64 getIndexFromTypeDescriptor(TypeDescriptor *typeDescriptor);
u64 getNumTypeDescriptors();
int registerTypeDescriptor(TypeDescriptor *typeDescriptor);
TypeDescriptor* getTypeDescriptorFromIndex(i64 typeDescriptorIndex);
#define pointerDestroy(pointer) ((void*) (free((void*) pointer), NULL))
void* pointerDestroyFunction(volatile void *pointer);
#define stringDestroyFunction pointerDestroyFunction
char *pointerToString(const volatile void *value);
Bytes pointerToBytes(const volatile void *value);
int pointerCompare(const volatile void *valueA, const volatile void *valueB);
Bytes pointerToBlob(const volatile void *value);
void* pointerFromBlob(const volatile void *array, u64 *length, bool inPlaceData,
  bool disableThreadSafety);

// Endianness functions and macros
//
// These functions and macros are used to guarantee that data is correct when
// being convereted to/from byte arrays.  The *ToBlob functions encode all
// integer data in little endian format based on the assumption that most
// systems are little endian (because that's generally more optimal) and the
// *FromBlob functions all guarantee that the data is in the correct
// endianness before returning the data.  Since the underlying assumption here
// is that most systems will be little endian on both the encoding and decoding
// sides, it really makes no sense to even enter the byte swap operation if the
// system is already little endian.  Therefore, while the byteSwapIfNot*
// functions do need to check the endianness of the system in order to gurantee
// correctness, the hostTo* and *ToHost calls would be better off not even
// calling the byteSwap* functions if there's no need.  Because of this, the
// macros check the endianness before even calling the byteSwap* functions.
//
// The big endian versions of these calls are provided for completeness but are
// not used by this library.
int byteSwapIfNotLittleEndian(volatile void *value, size_t size);
#define hostToLittleEndian(value, size) \
  (HOST_IS_LITTLE_ENDIAN) \
    ? TRINARY_ZERO \
    : byteSwapIfNotLittleEndian(value, size)
#define littleEndianToHost(value, size) \
  (HOST_IS_LITTLE_ENDIAN) \
    ? TRINARY_ZERO \
    : byteSwapIfNotLittleEndian(value, size)
int byteSwapIfNotBigEndian(volatile void *value, size_t size);
#define hostToBigEndian(value, size) \
  (HOST_IS_LITTLE_ENDIAN) \
    ? byteSwapIfNotBigEndian(value, size) \
    : TRINARY_ZERO
#define bigEndianToHost(value, size) \
  (HOST_IS_LITTLE_ENDIAN) \
    ? byteSwapIfNotBigEndian(value, size) \
    : TRINARY_ZERO

bool boolUnitTest();
bool u8UnitTest();
bool u16UnitTest();
bool u32UnitTest();
bool u64UnitTest();
bool i8UnitTest();
bool i16UnitTest();
bool i32UnitTest();
bool i64UnitTest();
bool floatUnitTest();
bool doubleUnitTest();
bool longDoubleUnitTest();
bool stringUnitTest();
bool pointerUnitTest();
bool bytesUnitTest();
bool structUnitTest();
bool valueToStringUnitTest();

extern u16 DsMarker;
extern u32 DsVersion;

#define JSON_TO_DATA_STRUCTURE(Type, prefix) \
/** @fn Type* jsonTo##Type(const char *jsonText, long long int *position) { */ \
/** */ \
/** @brief Converts a JSON-formatted string to a data structure. */ \
/** */ \
/** @param jsonText The text to convert. */ \
/** @param position A pointer to the current byte postion within the jsonText. */ \
/** */ \
/** @return Returns a pointer to a new data structure on success, NULL on failure. */ \
Type* jsonTo##Type(const char *jsonText, long long int *position) { \
  printLog(TRACE, "ENTER jsonTo" #Type "(jsonText=\"%s\", position=%p)\n", \
    (jsonText != NULL) ? jsonText : "NULL", position); \
  Type *returnValue = NULL; \
   \
  if (jsonText == NULL) { \
    printLog(ERR, "jsonText parameter is NULL.\n"); \
    printLog(TRACE, \
      "EXIT jsonTo" #Type "(jsonText=NULL, position=%p) = {NULL}\n", \
      position); \
    return NULL; \
  } else if (position == NULL) { \
    printLog(ERR, "position parameter is NULL.\n"); \
    printLog(TRACE, \
      "EXIT jsonTo" #Type "(jsonText=\"%s\", position=NULL) = {NULL}\n", \
      jsonText); \
    return NULL; \
  } \
   \
  const char *charAt \
    = &(jsonText[*position + strspn(&jsonText[*position], " \t\r\n")]); \
  if (*charAt != '{') { \
    printLog(ERR, "No opening brace in jsonText.  Malformed JSON input.\n"); \
    printLog(TRACE, \
      "EXIT jsonTo" #Type "(jsonText=\"%s\", position=%lld) = {NULL}\n", \
      jsonText, *position); \
    return NULL; \
  } \
   \
  returnValue = prefix##Create(typeString); \
   \
  *position += ((long long int) ((intptr_t) charAt)) \
    - ((long long int) ((intptr_t) &jsonText[*position])); \
  (*position)++; \
  while ((*position >= 0) && (jsonText[*position] != '\0')) { \
    *position += strspn(&jsonText[*position], " \t\r\n"); \
    char charAtPosition = jsonText[*position]; \
    if (charAtPosition == '}') { \
      /* End of object. */ \
      (*position)++; \
      break; \
    } else if (charAtPosition != '"') { \
      printLog(ERR, "Malformed JSON input.\n"); \
      returnValue = prefix##Destroy(returnValue);; \
      printLog(TRACE, \
        "EXIT jsonTo" #Type "(jsonText=\"%s\", position=%lld) = {NULL}\n", \
        jsonText, *position); \
      return NULL; \
    } \
    Bytes key = getBytesBetween(&jsonText[*position], "\"", "\":"); \
    if (key == NULL) { \
      printLog(ERR, "Malformed JSON input.\n"); \
      returnValue = prefix##Destroy(returnValue);; \
      printLog(TRACE, \
        "EXIT jsonToList(jsonText=\"%s\", position=%lld) = {NULL}\n", \
        jsonText, *position); \
      return returnValue; \
    } \
    printLog(DEBUG, "Getting value for \"%s\".\n", key); \
     \
    /* Start of value is 3 past the start of name plus the name due to the */ \
    /* double quotes, and colon. */ \
    *position += bytesLength(key) + 3; \
    *position += strspn(&jsonText[*position], " \t\r\n"); \
    charAtPosition = jsonText[*position]; \
    if ((charAtPosition != '"') && (charAtPosition != '{') \
      && (charAtPosition != '[') && !stringIsNumber(&jsonText[*position]) \
      && !stringIsBoolean(&jsonText[*position]) \
      && (*((u32*) &jsonText[*position]) != *((u32*) "null")) \
    ) { \
      printLog(ERR, "Malformed JSON input.\n"); \
      key = bytesDestroy(key); \
      returnValue = prefix##Destroy(returnValue);; \
      printLog(TRACE, \
        "EXIT jsonTo" #Type "(jsonText=\"%s\", position=%lld) = {NULL}\n", \
        jsonText, *position); \
      return NULL; \
    } \
    if (charAtPosition == '"') { \
      /* Get the string between the quotes. */ \
      const char *startQuoteAt = &jsonText[*position]; \
      const char *endQuoteAt = startQuoteAt + 1; \
      while (*endQuoteAt != '"') { \
        if (*endQuoteAt != '\\') { \
          endQuoteAt++; \
        } else { \
          endQuoteAt += 2; \
        } \
      } \
      Bytes stringValue = NULL; \
      if (((uintptr_t) endQuoteAt) > ((uintptr_t) startQuoteAt)) { \
        startQuoteAt++; \
        u64 stringLength \
          = ((uintptr_t) endQuoteAt) - ((uintptr_t) startQuoteAt); \
        if (stringLength > 0) { \
          /* The usual case. */ \
          bytesAddData(&stringValue, startQuoteAt, stringLength); \
        } else { \
          /* Empty string. */ \
          bytesAddStr(&stringValue, ""); \
        } \
      } \
      if (stringValue == NULL) { \
        printLog(ERR, "Malformed JSON input.\n"); \
        key = bytesDestroy(key); \
        returnValue = prefix##Destroy(returnValue);; \
        printLog(TRACE, \
          "EXIT jsonTo" #Type "(jsonText=\"%s\", position=%lld) = {NULL}\n", \
          jsonText, *position); \
        return NULL; \
      } \
      u64 skipLength = bytesLength(stringValue); \
      /* Remove any backslash escapes that were injected by the protocol. */ \
      u64 i = 0; \
      for (u64 j = 0; j < skipLength; i++, j++) { \
        if (stringValue[j] == '\\') { \
          j++; \
          if (stringValue[j] == 'n') { \
            stringValue[i] = '\n'; \
            continue; \
          } \
        } \
        stringValue[i] = stringValue[j]; \
      } \
      bytesSetLength(stringValue, i); \
      unescapeBytes(stringValue); \
      Type##Node *node = prefix##AddEntry(returnValue, key, stringValue, typeBytesNoCopy); \
      if (node != NULL) { \
        node->type = typeBytes; \
      } else { \
        LOG_MALLOC_FAILURE(); \
        returnValue = prefix##Destroy(returnValue); \
        printLog(NEVER, \
          "EXIT jsonTo" #Type "(jsonText=\"%s\", position=%lld) = {NULL}\n", \
          jsonText, *position); \
        return returnValue; \
      } \
      *position += skipLength + 2; \
    } else if (stringIsNumber(&jsonText[*position])) { \
      /* Parse the number. */ \
      char *endpos = NULL; \
      if (stringIsFloat(&jsonText[*position])) { \
        double doubleValue = strtod(&jsonText[*position], &endpos); \
        prefix##AddEntry(returnValue, key, &doubleValue, typeDouble); \
      } else { /* stringIsInteger(&jsonText[*position]) */ \
        i64 longLongValue = (i64) strtoll(&jsonText[*position], &endpos, 10); \
        prefix##AddEntry(returnValue, key, &longLongValue, typeI64); \
      } \
      *position \
        += ((long long int) ((intptr_t) endpos)) \
        - ((long long int) ((intptr_t) &jsonText[*position])); \
    } else if (stringIsBoolean(&jsonText[*position])) { \
      /* Parse the boolean. */ \
      char *endpos = NULL; \
      bool boolValue = strtobool(&jsonText[*position], &endpos); \
      prefix##AddEntry(returnValue, key, &boolValue, typeBool); \
      *position \
        += ((long long int) ((intptr_t) endpos)) \
        - ((long long int) ((intptr_t) &jsonText[*position])); \
    } else if (charAtPosition == '{') { \
      /* Parse the key-value data structure. */ \
      Type *dataStructure = jsonTo##Type(jsonText, position); \
      if (dataStructure == NULL) { \
        printLog(ERR, "Malformed JSON input.\n"); \
        key = bytesDestroy(key); \
        returnValue = prefix##Destroy(returnValue); \
        printLog(TRACE, \
          "EXIT jsonTo" #Type "(jsonText=\"%s\", position=%lld) = {NULL}\n", \
          jsonText, *position); \
        return returnValue; \
      } \
      Type##Node *node = prefix##AddEntry(returnValue, key, dataStructure, \
        type##Type##NoCopy); \
      node->type = type##Type; \
      /* position is automatically updated in this case. */ \
    } else if (charAtPosition == '[') { \
      /* Parse the vector. */ \
      Vector *vector = jsonToVector(jsonText, position); \
      if (vector == NULL) { \
        printLog(ERR, "Malformed JSON input.\n"); \
        key = bytesDestroy(key); \
        returnValue = prefix##Destroy(returnValue); \
        printLog(TRACE, \
          "EXIT jsonToList(jsonText=\"%s\", position=%lld) = {NULL}\n", \
          jsonText, *position); \
        return returnValue; \
      } \
      Type##Node *node = prefix##AddEntry(returnValue, key, vector, \
        typeVectorNoCopy); \
      node->type = typeVector; \
      /* position is automatically updated in this case. */ \
    } else { /* (strncmp(&jsonText[*position], "null", 4) == 0) */ \
      prefix##AddEntry(returnValue, key, NULL, typePointer); \
      *position += 4; \
    } \
    *position += strspn(&jsonText[*position], " \t\r\n"); \
    if (jsonText[*position] == ',') { \
      (*position)++; \
    } \
    key = bytesDestroy(key); \
  } \
   \
  printLog(TRACE, \
    "EXIT jsonTo" #Type "(jsonText=\"%s\", position=%lld) = {%p}\n", \
    jsonText, *position, returnValue); \
  return returnValue; \
}

#define reverseMemory(value, length) \
  do { \
    u8 *bytes = (u8*) value; \
    ssize_t i = 0, j = 0; \
    u8 temp = '\0'; \
    for (i = 0, j = ((ssize_t) length) - 1; i < j; ++i, --j) { \
      temp     = bytes[i]; \
      bytes[i] = bytes[j]; \
      bytes[j] = temp; \
    } \
  } while(0)

#define stringIsTrue(string) \
  ((string != NULL) && ((*((u32*) string)) == (*((u32*) boolNames[true]))))

#ifdef __cplusplus
} // extern "C"
#endif

// This must come last and must come outside the extern "C" block.
#include "TypeSafeValueToString.h"

#endif // DATA_TYPES_H

