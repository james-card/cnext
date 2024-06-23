# C.next: *What C++ should have been.*

C is an incomplete language.  It lacks standard mechanisms for doing several systems operations and it lacks standadized data structures.  Bjarne Stroustrup recognized this and was driven to create C++.  C++ was a good idea, but the most recent versions have evolved syntax that has gotten away from C.  C++ is also notoriously difficult to debug.

I use C in my own work day in and day out.  Over the years, I've developed many of the things that C++ provides and that C lacks.  With generics in C17, it finally became possible to have generic, type-safe data structures, and so I completed my data structures libraries using that ability.  At that point, I realized that I had the part of C that C++ was initially intended to provide.

In the continued theme of one iteration past C, I'm now releasing this work to the public as "C.next" in the hopes that other people find it useful.

## StringLib

C's string.h really only supports charcter arrays.  For doing anything practical with strings, you really need dynamic memory.  I created StringLib for this purpose.  This library contains utilities for dynamically resizing and appending to string, getting text within a string, etc.

### Bytes Objects

The problem with strings is that they're slow.  When repeatedly concatenating strings, calculating the amout of memory currently used requries traversing each string repeatedly.  To address this, I created a Bytes type that is a pointer to an unsigned char value with metadata about the string stored *BEFORE* the pointer.  This allows for quick computation of the amount of memory a string is currently using and also where to do concatenations.  This also allows for optimizing allocations to reduce the total number of calls to realloc.  Bytes objects can be used anywhere a regular C string can be used, except with a call to `free()`.  All of my data types have their own destructors that return NULL, including strings and Bytes objects.  Use of `free()` is *HIGHLY DISCOURAGED* with these libraries.  You should always use the appropriate destructor for an object instead.

## Scope

Unlike C++, variables that go out of scope aren't automatically destructed.  The classic way of handling this in C is to use goto statements that point to the end of the function where the code responsible for teardown is.  However, since C99, it's been possible to declare variables other than at the beginning of functions and putting a goto before a variable declaration won't work.  So, we've been left to either continue to declare all our variables at the tops of our functions or painstakingly destroy all our allocated variables on every return statement.  I finally got fed up with this and created a Scope object to handle this problem.  This allows for tracking of variables that are to be destroyed before the function exits.  Having this as an independent object gives the programmer control over what gets cleaned up in this way and what does not.  Just put `scopeBegin();` at the beginning of your function, add pointers to it with `scopeAdd(pointer, destructor);`, and call `scopeEnd();` to cleanup everyting before a return statement.  *MUCH* cleaner.  If you add something to scope that you later want to remove from tracking and keep a valid pointer for, just call `scopeRemove(pointer);`.  If you want to remove it from tracking *AND* call its destructor, call `scopeDestroy(pointer);`.

`scopeBegin()` is a macro that declares a Scope object on the stack.  By default, it's large enough to accommodate 512 variables, which is the minimum maximum number of variables permitted by the C specification.  If you'd like to have a different number of variables, simply define `MAX_SCOPE_VARS` to the value of your choice before including Scope.h.  Note, however, that if you attempt to exceed the capcity of the object that scopeAdd will both fail *AND* call the provided destructor since there would be a memory leak otherwise.  For that reason, it's always best to check the return value of scopeAdd.

In theory, scopeRemove or scopeDestroy could be costly operations since removal of a value in the middle of the array would requrie moving all the elements after that down by one index.  In practice, however, this doesn't really happen.  The times that this is done are usually within loops that would be adding and removing from the end of the array, so there's virtually no cost in practice.

## General-Purpose Data Structures

Data structures provided by this library are list, queue, stack, vector, red-black tree, and hash table.  The libraries achieve general-purpose use by specifiying a TypeDescriptor for the keys and values.  All the keys of a data structure have to be of the same type, but the values may be any type.  The type of the value is determined when the value is added to the data structure.

Each data structure has a function that inserts a value into it.  These functions take `void*` parameters for keys and values.  For key-value data structures, this is a `*Add` function, for stacks and queues, this is a `*Push` function, and for vectors, this is the `vectorSet` function.  The raw implementations of these functions are appended with `Entry_`.  The `*Entry_` functions take a `TypeDescriptor*` as the last parameter that tells the data structure about the type of value that's being inserted.  Each function has a wrapper macro of the same name, minus the trailing underscore, that makes the `TypeDescriptor*` parameter optional.  If it is omitted, the macro provides NULL for the `TypeDescriptor*` parameter, which will cause the operation to use the last type provided for that operation on that data structure.

In C17 and beyond, the data structures achieve type safety by providing header files that define wrappers that take typed values (and keys for the key-value structures) rather than `void*` parameters.  The wrappers provide the correct TypeDescriptor for the given type.  The wrappers are the same names as the insertion functions for the data structures, minus the trailing `Entry`.  Note that for data structures that take keys, the insertion operation will fail if the provided key is not of the same type as the key of the data structure.

### Passing by Value vs. Pasing by Reference

When passing key and value parameters by value to the type-safe insertion functions, memory is allocated for the value in the data structure and a copy is made to hold in the data structure.  When passing by reference, only the pointer to the value is stored.  This means that the data structure does not make a copy of the value and the pointer *is not owned or freed by the data structure upon destruction*.  If you want the data structure to store a pointer to your value *and take ownership of it such that it is freed upon data structure destruction*, cast your value to a `void*` on add.

### A Note about Character Pointers

Because `int8_t` can be defined to `char` and `uint8_t` can be defined to `unsigned char` in `stdint.h`, I'm not able to treat pointers to these values as pointers to integers.  In C, pointers to character values are commonly understood to be string values and have to be treated as such.  In my libraries, I define a `Bytes` type to be a pointer to an unsigned character that is backward-compatible to C strings except that there is metadata about the value stored before the pointer that allows size operations to be more efficient.  The simplest way to manage pointers to 8-bit values would be to use the `*Entry` versions of the functions with the apprppriate `TypeDescriptor*` parameters.

### TypeDescriptors

TypeDescriptors allow for determining type at runtime and have application outside of the data structures libraries.  In my other libraries, I sometimes use them to determine the type of arguments in variable argument functions.  For example:

```
int myFunction(int lastArgument, ...) {
  scopeEnter();

  char *key = NULL;
  TypeDescriptor *type = NULL;
  void *value = NULL;
  List *list = listCreate(typeString);
  va_list args;
  va_start(args, lastArgument);

  // Consume all the arguments.
  key = va_arg(args, char*);
  while (key != NULL) {
    type = va_arg(args, TypeDescriptor*);
    int typeIndex = getIndexFromTypeDescriptor(type);

    bool  boolParam = false;
    bool *boolParamP = NULL;
    i8  i8Param = 0;
    i8 *i8ParamP = NULL;
    u8  u8Param = 0;
    u8 *u8ParamP = NULL;
    i16  i16Param = 0;
    i16 *i16ParamP = NULL;
    u16  u16Param = 0;
    u16 *u16ParamP = NULL;
    i32  i32Param = 0;
    i32 *i32ParamP = NULL;
    u32  u32Param = 0;
    u32 *u32ParamP = NULL;
    i64  i64Param = false;
    i64 *i64ParamP = NULL;
    u64  u64Param = false;
    u64 *u64ParamP = NULL;
    float  floatParam = false;
    float *floatParamP = NULL;
    double  doubleParam = false;
    double *doubleParamP = NULL;
    long double  longDoubleParam = false;
    long double *longDoubleParamP = NULL;
    char *stringParam = NULL;
    Bytes bytesParam = NULL;

    switch (typeIndex) {
      case TYPE_BOOL: {
        boolParam = va_arg(args, int);
        value = &boolParam;
        break;
      }
      case TYPE_BOOL_NO_COPY: {
        boolParamP = va_arg(args, bool*);
        value = boolParamP;
        break;
      }
      case TYPE_I8: {
        i8Param = va_arg(args, int);
        value = &i8Param;
        break;
      }
      case TYPE_I8_NO_COPY: {
        i8ParamP = va_arg(args, i8*);
        value = i8ParamP;
        break;
      }
      case TYPE_U8: {
        u8Param = va_arg(args, unsigned int);
        value = &u8Param;
        break;
      }
      case TYPE_U8_NO_COPY: {
        u8ParamP = va_arg(args, u8*);
        value = u8ParamP;
        break;
      }
      case TYPE_I16: {
        i16Param = va_arg(args, int);
        value = &i16Param;
        break;
      }
      case TYPE_I16_NO_COPY: {
        i16ParamP = va_arg(args, i16*);
        value = i16ParamP;
        break;
      }
      case TYPE_U16: {
        u16Param = va_arg(args, unsigned int);
        value = &u16Param;
        break;
      }
      case TYPE_U16_NO_COPY: {
        u16ParamP = va_arg(args, u16*);
        value = u16ParamP;
        break;
      }
      case TYPE_I32: {
        i32Param = va_arg(args, i32);
        value = &i32Param;
        break;
      }
      case TYPE_I32_NO_COPY: {
        i32ParamP = va_arg(args, i32*);
        value = i32ParamP;
        break;
      }
      case TYPE_U32: {
        u32Param = va_arg(args, u32);
        value = &u32Param;
        break;
      }
      case TYPE_U32_NO_COPY: {
        u32ParamP = va_arg(args, u32*);
        value = u32ParamP;
        break;
      }
      case TYPE_I64: {
        i64Param = va_arg(args, i64);
        value = &i64Param;
        break;
      }
      case TYPE_I64_NO_COPY: {
        i64ParamP = va_arg(args, i64*);
        value = i64ParamP;
        break;
      }
     case TYPE_U64: {
        u64Param = va_arg(args, u64);
        value = &u64Param;
        break;
      }
      case TYPE_U64_NO_COPY: {
        u64ParamP = va_arg(args, u64*);
        value = u64ParamP;
        break;
      }
     case TYPE_FLOAT: {
        floatParam = va_arg(args, double);
        value = &floatParam;
        break;
      }
      case TYPE_FLOAT_NO_COPY: {
        floatParamP = va_arg(args, float*);
        value = floatParamP;
        break;
      }
      case TYPE_DOUBLE: {
        doubleParam = va_arg(args, double);
        value = &doubleParam;
        break;
      }
      case TYPE_DOUBLE_NO_COPY: {
        doubleParamP = va_arg(args, double*);
        value = doubleParamP;
        break;
      }
      case TYPE_LONG_DOUBLE: {
        longDoubleParam = va_arg(args, long double);
        value = &longDoubleParam;
        break;
      }
      case TYPE_LONG_DOUBLE_NO_COPY: {
        longDoubleParamP = va_arg(args, long double*);
        value = longDoubleParamP;
        break;
      }
      case TYPE_STRING:
      case TYPE_STRING_NO_COPY:
      case TYPE_STRING_CI:
      case TYPE_STRING_CI_NO_COPY: {
        stringParam = va_arg(args, char*);
        value = stringParam;
        type = typeStringNoCopy;
        break;
      }
      case TYPE_BYTES:
      case TYPE_BYTES_NO_COPY: {
        bytesParam = va_arg(args, Bytes);
        value = (void*) bytesParam;
        type = typeBytesNoCopy;
        break;
      }
    }

    listAddBackEntry(list, key, value, type);
    key = va_arg(args, char*);
  }

  va_end(args);

  scopeAdd(list, listDestroy);

  int returnValue = doSomething(lastArgument, list);

  scopeEnd();
  return returnValue;
}
```

### Disclaimer

I will not claim this is an optimized implementation of a data structures library.  I know there are things that could be done to make these libraries more efficient.  My goal was generic functionality and safety, not optimization.  My expectation is that the implementation will be optimized over time.

## Systems Libraries

C11 finally introduced standard support for most threading operations, however there are several other standard systems functions that it has ignored.  Even with the specification providing standardized thread support, there are still compilers that don't support it (most notably MSVC).  I finally gave up waiting for the language and compiler vendors to create what I needed and made my own libraries, both for the missing threads support and other things.

### CThreads

CThreads.h includes the correct header based on the compiler, either PosixCTheads.h or WinCThreads.h.  The corresponding C libraries have the standard C functions for threading.  The libraries ensure functionality that conforms to the C specification.  I have also added thrd_terminate to the supported functions in these libraries.  Even though it is not a best practice to terminate a thread, there are situations where it is necessary and the language should not constrain programmers from necessary operations.  Without a cross-platform way to do this, developers would still have to rely on OS-specific mechanisms for the times that this is necesary.

### Coroutines

It's not clear to me why support for coroutines was never added to the C specification considering their use in cooperative multitasking operating systems.  To fill this void, I have created a pure C coroutines library that works by subdividing the main stack.  This approach removes the need for dynamic memory of any kind and is well-suited to embedded environments, which is the primary audience of C.

### Processes

For whatever reason, C has never come up with standard functions for processes that allow both stdin and stdout/stderr of a process to be captured.  This is not acceptable to me as a systems language.  I created a Processes.h header that automatically includes either PosixProcess.h or WinProcesses.h and provides basic functionality for interacting with external processes.  The libraries provide consistent functionality across systems.

### Sockets

Despite the fact that networking has existed since the 1960s, C has never standardized network operations.  Each operating system has its own definitions of how socket connections work.  Even worse, there's no support for security which is a must in today's world.  So, I created a Sockets library to provide consistent operations across platforms.  To get secure sockets, define `TLS_SOCKETS_ENABLED` and link with RsaLib, SslKey, SslCertificate, and OpenSSL.

### DirectoryLib

Every major filesystem supports directories, but support for them has never been standardized in C.  To fix that, I created DirectoryLib that provides cross-platform functionality for interacting with directories, most notably creating and removing them.

