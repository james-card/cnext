# C.next: *What C++ should have been.*

C is an incomplete language.  It lacks standard mechanisms for doing several systems operations and it lacks standadized data structures.  Bjarne Stroustrup recognized this and was driven to create C++.  C++ was a good idea, but the most recent versions have evolved syntax that has gotten away from C.  C++ is also notoriously difficult to debug.

I use C in my own work day in and day out.  Over the years, I've developed many of the things that C++ provides and that C lacks.  With generics in C17, it finally became possible to have generic, type-safe data structures, and so I completed my data structures libraries using that ability.  At that point, I realized that I had the part of C that C++ was initially intended to provide.

I'm now releasing this work to the public in the hopes that other people find it useful.

## General-Purpose Data Structures

Data structures provided by this library are list, queue, stack, vector, red-black tree, and hash table.  The libraries achieve general-purpose use by specifiying a TypeDescriptor for the keys and values.  All the keys of a data structure have to be of the same type, but the values may be any type.  The type of the value is determined when the value is added to the data structure.

Each data structure has a function that inserts a value into it.  These functions take `void*` parameters for keys and values.  For key-value data structures, this is a `*Add` function, for stacks and queues, this is a `*Push` function, and for vectors, this is the `vectorSet` function.  The raw implementations of these functions are appended with `Entry_`.  The `*Entry_` functions take a `TypeDescriptor*` as the last parameter that tells the data structure about the type of value that's being inserted.  Each function has a wrapper macro of the same name, minus the trailing underscore, that makes the `TypeDescriptor*` parameter optional.  If it is omitted, the macro provides NULL for the `TypeDescriptor*` parameter, which will cause the operation to use the last type provided for that operation on that data structure.

In C17 and beyond, the data structures achieve type safety by providing header files that define wrappers that take typed values (and keys for the key-value structures) rather than `void*` parameters.  The wrappers provide the correct TypeDescriptor for the given type.  The wrappers are the same names as the insertion functions for the data structures, minus the trailing `Entry`.  Note that for data structures that take keys, the insertion operation will fail if the provided key is not of the same type as the key of the data structure.

### Passing by Value vs. Pasing by Reference

When passing key and value parameters by value to the type-safe insertion functions, memory is allocated for the value in the data structure and a copy is made to hold in the data structure.  When passing by reference, only the pointer to the value is stored.  This means that the data structure does not make a copy of the value and the pointer *is not owned or freed by the data structure upon destruction*.  If you want the data structure to store a pointer to your value *and take ownership of it such that it is freed upon data structure destruction*, cast your value to a `void*` on add.

### A Note about Character Pointers

Because `int8_t` can be defined to `char` and `uint8_t` can be defined to `unsigned char` in `stdint.h`, I'm not able to treat pointers to these values as pointers to integers.  In C, pointers to character values are commonly understood to be string values and have to be treated as such.  In my libraries, I define a `Bytes` type to be a pointer to an unsigned character that is backward-compatible to C strings except that there is metadata about the value stored before the pointer that allows size operations to be more efficient.  The simplest way to manage pointers to 8-bit values would be to use the `*Entry` versions of the functions with the apprppriate `TypeDescriptor*` parameters.

### Disclaimer

I will not claim this is an optimized implementation of a data structures library.  I know there are things that could be done to make these libraries more efficient.  My goal was generic functionality and safety, not optimization.  My expectation is that the implementation will be optimized over time.

