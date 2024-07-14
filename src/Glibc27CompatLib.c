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

#include "Glibc27CompatLib.h"


#ifndef __MINGW32__
#ifdef __GNUC__
#undef _GNU_SOURCE
#define _GNU_SOURCE

#ifdef __cplusplus
extern "C"
{
#endif

//// // Break the dependency on GLIBC 2.38 in newer versions of gcc.
//// #ifdef __x86_64__
////   asm (".symver ___strtoll, strtoll@GLIBC_2.2.5");
////   asm (".symver ___strtol, strtol@GLIBC_2.2.5");
//// #else // 32-bit
////   asm (".symver ___strtoll, strtoll@GLIBC_2.0");
////   asm (".symver ___strtol, strtol@GLIBC_2.0");
//// #endif // __x86_64__
//// asm (".symver ___vsscanf, __isoc99_vsscanf@GLIBC_2.7");
//// 
//// long long strtoll(const char *nptr, char **endptr, int base) {
////   long long ___strtoll(const char *nptr, char **endptr, int base);
////   return ___strtoll(nptr, endptr, base);
//// }
//// 
//// long strtol(const char *nptr, char **endptr, int base) {
////   long ___strtol(const char *nptr, char **endptr, int base);
////   return ___strtol(nptr, endptr, base);
//// }
//// 
//// int sscanf(const char *str, const char *format, ...) {
////   int ___vsscanf(const char *str, const char *format, va_list ap);
////   va_list args;
////   va_start(args, format);
////   int returnValue = ___vsscanf(str, format, args);
////   va_end(args);
////   
////   return returnValue;
//// }


// Break the dependency on GLIBC 2.34 in newer versions of gcc.

#ifndef __USE_GNU
#define __USE_GNU
#endif // __USE_GNU

#include <dlfcn.h>

#ifdef __x86_64__
  asm (".symver __libc_start_main, __libc_start_main@GLIBC_2.2.5");
  asm (".symver dlsym, dlsym@GLIBC_2.2.5");
  asm (".symver dlopen, dlopen@GLIBC_2.2.5");
  asm (".symver dladdr, dladdr@GLIBC_2.2.5");
  asm (".symver dlclose, dlclose@GLIBC_2.2.5");
  asm (".symver dlerror, dlerror@GLIBC_2.2.5");
  asm (".symver dlvsym, dlvsym@GLIBC_2.2.5");
  asm (".symver pthread_create, pthread_create@GLIBC_2.2.5");
  asm (".symver pthread_detach, pthread_detach@GLIBC_2.2.5");
  asm (".symver pthread_getspecific, pthread_getspecific@GLIBC_2.2.5");
  asm (".symver pthread_join, pthread_join@GLIBC_2.2.5");
  asm (".symver pthread_key_create, pthread_key_create@GLIBC_2.2.5");
  asm (".symver pthread_key_delete, pthread_key_delete@GLIBC_2.2.5");
  asm (".symver pthread_mutexattr_destroy, pthread_mutexattr_destroy@GLIBC_2.2.5");
  asm (".symver pthread_mutexattr_init, pthread_mutexattr_init@GLIBC_2.2.5");
  asm (".symver pthread_mutexattr_settype, pthread_mutexattr_settype@GLIBC_2.2.5");
  asm (".symver pthread_mutex_timedlock, pthread_mutex_timedlock@GLIBC_2.2.5");
  asm (".symver pthread_mutex_trylock, pthread_mutex_trylock@GLIBC_2.2.5");
  asm (".symver pthread_once, pthread_once@GLIBC_2.2.5");
  asm (".symver pthread_rwlock_destroy, pthread_rwlock_destroy@GLIBC_2.2.5");
  asm (".symver pthread_rwlock_init, pthread_rwlock_init@GLIBC_2.2.5");
  asm (".symver pthread_rwlock_rdlock, pthread_rwlock_rdlock@GLIBC_2.2.5");
  asm (".symver pthread_rwlock_unlock, pthread_rwlock_unlock@GLIBC_2.2.5");
  asm (".symver pthread_rwlock_wrlock, pthread_rwlock_wrlock@GLIBC_2.2.5");
  asm (".symver pthread_setspecific, pthread_setspecific@GLIBC_2.2.5");
  asm (".symver pthread_cancel, pthread_cancel@GLIBC_2.2.5");
#else // 32-bit
  asm (".symver __libc_start_main, __libc_start_main@GLIBC_2.0");
  asm (".symver dlsym, dlsym@GLIBC_2.0");
  asm (".symver dlopen, dlopen@GLIBC_2.1");
  asm (".symver dladdr, dladdr@GLIBC_2.0");
  asm (".symver dlclose, dlclose@GLIBC_2.0");
  asm (".symver dlerror, dlerror@GLIBC_2.0");
  asm (".symver dlvsym, dlvsym@GLIBC_2.1");
  asm (".symver pthread_create, pthread_create@GLIBC_2.1");
  asm (".symver pthread_detach, pthread_detach@GLIBC_2.0");
  asm (".symver pthread_getspecific, pthread_getspecific@GLIBC_2.0");
  asm (".symver pthread_join, pthread_join@GLIBC_2.0");
  asm (".symver pthread_key_create, pthread_key_create@GLIBC_2.0");
  asm (".symver pthread_key_delete, pthread_key_delete@GLIBC_2.0");
  asm (".symver pthread_mutexattr_destroy, pthread_mutexattr_destroy@GLIBC_2.0");
  asm (".symver pthread_mutexattr_init, pthread_mutexattr_init@GLIBC_2.0");
  asm (".symver pthread_mutexattr_settype, pthread_mutexattr_settype@GLIBC_2.1");
  asm (".symver pthread_mutex_timedlock, pthread_mutex_timedlock@GLIBC_2.2");
  asm (".symver pthread_mutex_trylock, pthread_mutex_trylock@GLIBC_2.0");
  asm (".symver pthread_once, pthread_once@GLIBC_2.0");
  asm (".symver pthread_rwlock_destroy, pthread_rwlock_destroy@GLIBC_2.1");
  asm (".symver pthread_rwlock_init, pthread_rwlock_init@GLIBC_2.1");
  asm (".symver pthread_rwlock_rdlock, pthread_rwlock_rdlock@GLIBC_2.1");
  asm (".symver pthread_rwlock_unlock, pthread_rwlock_unlock@GLIBC_2.1");
  asm (".symver pthread_rwlock_wrlock, pthread_rwlock_wrlock@GLIBC_2.1");
  asm (".symver pthread_setspecific, pthread_setspecific@GLIBC_2.0");
  asm (".symver pthread_cancel, pthread_cancel@GLIBC_2.0");
#endif // __x86_64__

// __libc_start_main contains a compile-time optional parameter called auxvec
// between argv and init.  This parameter is currently only defined for PowerPC
// architectures, which I don't support today.
// JBC 2023-01-28
int __libc_start_main(int (*main)(int, char**, char**),
  int argc,
  char **argv,
  __typeof(main) init,
  void (*fini)(void),
  void (*rtld_fini)(void),
  void *stack_end
) __attribute__((noreturn));

int __wrap___libc_start_main(
  int (*main)(int, char**, char**),
  int argc,
  char **argv,
  __typeof(main) init,
  void (*fini)(void),
  void (*rtld_fini)(void),
  void *stack_end
) {
  __libc_start_main(main, argc, argv, init, fini, rtld_fini, stack_end);
}

void *__wrap_dlsym(void *__restrict __handle, const char *__restrict __name) {
  return dlsym(__handle, __name);
}

void *__wrap_dlopen(const char *__file, int __mode) {
  return dlopen(__file, __mode);
}

int __wrap_dladdr(const void *__address, Dl_info *__info) {
  return dladdr(__address, __info);
}

int __wrap_dlclose(void *__handle) {
  return dlclose(__handle);
}

char *__wrap_dlerror(void) {
  return dlerror();
}

void *__wrap_dlvsym(void *__restrict __handle,
  const char *__restrict __name,
  const char *__restrict __version
) {
  return dlvsym(__handle, __name, __version);
}

int __wrap_pthread_create(pthread_t *__restrict __newthread,
  const pthread_attr_t *__restrict __attr,
  void *(*__start_routine) (void *),
  void *__restrict __arg
) {
  return pthread_create(__newthread, __attr, __start_routine, __arg);
}

int __wrap_pthread_detach(pthread_t __th) {
  return pthread_detach(__th);
}

void *__wrap_pthread_getspecific(pthread_key_t __key) {
  return pthread_getspecific(__key);
}

int __wrap_pthread_join(pthread_t __th, void **__thread_return) {
  return pthread_join(__th, __thread_return);
}

int __wrap_pthread_key_create(pthread_key_t *__key,
  void (*__destr_function) (void *)
) {
  return pthread_key_create(__key, __destr_function);
}

int __wrap_pthread_key_delete(pthread_key_t __key) {
  return pthread_key_delete(__key);
}

int __wrap_pthread_mutexattr_destroy(pthread_mutexattr_t *__attr) {
  return pthread_mutexattr_destroy(__attr);
}

int __wrap_pthread_mutexattr_init(pthread_mutexattr_t *__attr) {
  return pthread_mutexattr_init(__attr);
}

int __wrap_pthread_mutexattr_settype(pthread_mutexattr_t *__attr, int __kind) {
  return pthread_mutexattr_settype(__attr, __kind);
}

int __wrap_pthread_mutex_timedlock(pthread_mutex_t *__restrict __mutex,
  const struct timespec *__restrict __abstime
) {
  return pthread_mutex_timedlock(__mutex, __abstime);
}

int __wrap_pthread_mutex_trylock(pthread_mutex_t *__mutex) {
  return pthread_mutex_trylock(__mutex);
}

int __wrap_pthread_once(pthread_once_t *__once_control,
  void (*__init_routine) (void)
) {
  return pthread_once(__once_control, __init_routine);
}

int __wrap_pthread_rwlock_destroy(pthread_rwlock_t *__rwlock) {
  return pthread_rwlock_destroy(__rwlock);
}

int __wrap_pthread_rwlock_init(pthread_rwlock_t *__restrict __rwlock,
  const pthread_rwlockattr_t *__restrict __attr
) {
  return pthread_rwlock_init(__rwlock, __attr);
}

int __wrap_pthread_rwlock_rdlock(pthread_rwlock_t *__rwlock) {
  return pthread_rwlock_rdlock(__rwlock);
}

int __wrap_pthread_rwlock_unlock(pthread_rwlock_t *__rwlock) {
  return pthread_rwlock_unlock(__rwlock);
}

int __wrap_pthread_rwlock_wrlock(pthread_rwlock_t *__rwlock) {
  return pthread_rwlock_wrlock(__rwlock);
}

int __wrap_pthread_setspecific(pthread_key_t __key, const void *__pointer) {
  return pthread_setspecific(__key, __pointer);
}

// Break the dependency on GLIBC 2.33 in newer versions of gcc.
// Taking the definitions from sys/stat.h and bits/stat.h in older versions of
// gcc.

#define __fxstat ___fxstat
#define __xstat ___xstat
#define __lxstat ___lxstat
#define __fxstat64 ___fxstat64
#define __xstat64 ___xstat64
#define __lxstat64 ___lxstat64
#include <sys/stat.h>
#undef __fxstat
#undef __xstat
#undef __lxstat
#undef __fxstat64
#undef __xstat64
#undef __lxstat64

#ifndef __x86_64__
# define _STAT_VER_LINUX_OLD    1
# define _STAT_VER_KERNEL       1
# define _STAT_VER_SVR4         2
# define _STAT_VER_LINUX        3

/* i386 versions of the `xmknod' interface.  */
# define _MKNOD_VER_LINUX       1
# define _MKNOD_VER_SVR4        2
# define _MKNOD_VER             _MKNOD_VER_LINUX /* The bits defined below.  */
#else
# define _STAT_VER_KERNEL       0
# define _STAT_VER_LINUX        1

/* x86-64 versions of the `xmknod' interface.  */
# define _MKNOD_VER_LINUX       0
#endif // __x86_64__

#define _STAT_VER               _STAT_VER_LINUX

struct old_stat
{
    __dev_t st_dev;		/* Device.  */
#ifndef __x86_64__
    unsigned short int __pad1;
#endif
#if defined __x86_64__ || !defined __USE_FILE_OFFSET64
    __ino_t st_ino;		/* File serial number.	*/
#else
    __ino_t __st_ino;			/* 32bit file serial number.	*/
#endif
#ifndef __x86_64__
    __mode_t st_mode;			/* File mode.  */
    __nlink_t st_nlink;			/* Link count.  */
#else
    __nlink_t st_nlink;		/* Link count.  */
    __mode_t st_mode;		/* File mode.  */
#endif
    __uid_t st_uid;		/* User ID of the file's owner.	*/
    __gid_t st_gid;		/* Group ID of the file's group.*/
#ifdef __x86_64__
    int __pad0;
#endif
    __dev_t st_rdev;		/* Device number, if device.  */
#ifndef __x86_64__
    unsigned short int __pad2;
#endif
#if defined __x86_64__ || !defined __USE_FILE_OFFSET64
    __off_t st_size;			/* Size of file, in bytes.  */
#else
    __off64_t st_size;			/* Size of file, in bytes.  */
#endif
    __blksize_t st_blksize;	/* Optimal block size for I/O.  */
#if defined __x86_64__  || !defined __USE_FILE_OFFSET64
    __blkcnt_t st_blocks;		/* Number 512-byte blocks allocated. */
#else
    __blkcnt64_t st_blocks;		/* Number 512-byte blocks allocated. */
#endif
#ifdef __USE_XOPEN2K8
    /* Nanosecond resolution timestamps are stored in a format
       equivalent to 'struct timespec'.  This is the type used
       whenever possible but the Unix namespace rules do not allow the
       identifier 'timespec' to appear in the <sys/stat.h> header.
       Therefore we have to handle the use of this header in strictly
       standard-compliant sources special.  */
    struct timespec st_atim;		/* Time of last access.  */
    struct timespec st_mtim;		/* Time of last modification.  */
    struct timespec st_ctim;		/* Time of last status change.  */
# define st_atime st_atim.tv_sec	/* Backward compatibility.  */
# define st_mtime st_mtim.tv_sec
# define st_ctime st_ctim.tv_sec
#else
    __time_t st_atime;			/* Time of last access.  */
    __syscall_ulong_t st_atimensec;	/* Nscecs of last access.  */
    __time_t st_mtime;			/* Time of last modification.  */
    __syscall_ulong_t st_mtimensec;	/* Nsecs of last modification.  */
    __time_t st_ctime;			/* Time of last status change.  */
    __syscall_ulong_t st_ctimensec;	/* Nsecs of last status change.  */
#endif
#ifdef __x86_64__
    __syscall_slong_t __glibc_reserved[3];
#else
# ifndef __USE_FILE_OFFSET64
    unsigned long int __glibc_reserved4;
    unsigned long int __glibc_reserved5;
# else
    __ino64_t st_ino;			/* File serial number.	*/
# endif
#endif
};

void statToOldStat(const struct stat *statbuf, struct old_stat *oldStatbuf) {
  oldStatbuf->st_dev = statbuf->st_dev;
#ifndef __x86_64__
  oldStatbuf->__pad1 = statbuf->__pad1;
#endif
#if defined __x86_64__ || !defined __USE_FILE_OFFSET64
  oldStatbuf->st_ino = statbuf->st_ino;
#else
  oldStatbuf->__st_ino = statbuf->__st_ino;
#endif
#ifndef __x86_64__
  oldStatbuf->st_mode = statbuf->st_mode;
  oldStatbuf->st_nlink = statbuf->st_nlink;
#else
  oldStatbuf->st_nlink = statbuf->st_nlink;
  oldStatbuf->st_mode = statbuf->st_mode;
#endif
  oldStatbuf->st_uid = statbuf->st_uid;
  oldStatbuf->st_gid = statbuf->st_gid;
#ifdef __x86_64__
  oldStatbuf->__pad0 = statbuf->__pad0;
#endif
  oldStatbuf->st_rdev = statbuf->st_rdev;
#ifndef __x86_64__
  oldStatbuf->__pad2 = statbuf->__pad2;
#endif
#if defined __x86_64__ || !defined __USE_FILE_OFFSET64
  oldStatbuf->st_size = statbuf->st_size;
#else
  oldStatbuf->st_size = statbuf->st_size;
#endif
  oldStatbuf->st_blksize = statbuf->st_blksize;
#if defined __x86_64__  || !defined __USE_FILE_OFFSET64
  oldStatbuf->st_blocks = statbuf->st_blocks;
#else
  oldStatbuf->st_blocks = statbuf->st_blocks;
#endif
#ifdef __USE_XOPEN2K8
  oldStatbuf->st_atim = statbuf->st_atim;
  oldStatbuf->st_mtim = statbuf->st_mtim;
  oldStatbuf->st_ctim = statbuf->st_ctim;
#else
  oldStatbuf->st_atime = statbuf->st_atime;
  oldStatbuf->st_atimensec = statbuf->st_atimensec;
  oldStatbuf->st_mtime = statbuf->st_mtime;
  oldStatbuf->st_mtimensec = statbuf->st_mtimensec;
  oldStatbuf->st_ctime = statbuf->st_ctime;
  oldStatbuf->st_ctimensec = statbuf->st_ctimensec;
#endif
#ifdef __x86_64__
  oldStatbuf->__glibc_reserved[0] = statbuf->__glibc_reserved[0];
  oldStatbuf->__glibc_reserved[1] = statbuf->__glibc_reserved[1];
  oldStatbuf->__glibc_reserved[2] = statbuf->__glibc_reserved[2];
#else
# ifndef __USE_FILE_OFFSET64
  oldStatbuf->__glibc_reserved4 = statbuf->__glibc_reserved4;
  oldStatbuf->__glibc_reserved5 = statbuf->__glibc_reserved5;
# else
  oldStatbuf->st_ino = statbuf->st_ino;
# endif
#endif
}

void oldStatToStat(const struct old_stat *oldStatbuf, struct stat *statbuf) {
  statbuf->st_dev = oldStatbuf->st_dev;
#ifndef __x86_64__
  statbuf->__pad1 = oldStatbuf->__pad1;
#endif
#if defined __x86_64__ || !defined __USE_FILE_OFFSET64
  statbuf->st_ino = oldStatbuf->st_ino;
#else
  statbuf->__st_ino = oldStatbuf->__st_ino;
#endif
#ifndef __x86_64__
  statbuf->st_mode = oldStatbuf->st_mode;
  statbuf->st_nlink = oldStatbuf->st_nlink;
#else
  statbuf->st_nlink = oldStatbuf->st_nlink;
  statbuf->st_mode = oldStatbuf->st_mode;
#endif
  statbuf->st_uid = oldStatbuf->st_uid;
  statbuf->st_gid = oldStatbuf->st_gid;
#ifdef __x86_64__
  statbuf->__pad0 = oldStatbuf->__pad0;
#endif
  statbuf->st_rdev = oldStatbuf->st_rdev;
#ifndef __x86_64__
  statbuf->__pad2 = oldStatbuf->__pad2;
#endif
#if defined __x86_64__ || !defined __USE_FILE_OFFSET64
  statbuf->st_size = oldStatbuf->st_size;
#else
  statbuf->st_size = oldStatbuf->st_size;
#endif
  statbuf->st_blksize = oldStatbuf->st_blksize;
#if defined __x86_64__  || !defined __USE_FILE_OFFSET64
  statbuf->st_blocks = oldStatbuf->st_blocks;
#else
  statbuf->st_blocks = oldStatbuf->st_blocks;
#endif
#ifdef __USE_XOPEN2K8
  statbuf->st_atim = oldStatbuf->st_atim;
  statbuf->st_mtim = oldStatbuf->st_mtim;
  statbuf->st_ctim = oldStatbuf->st_ctim;
#else
  statbuf->st_atime = oldStatbuf->st_atime;
  statbuf->st_atimensec = oldStatbuf->st_atimensec;
  statbuf->st_mtime = oldStatbuf->st_mtime;
  statbuf->st_mtimensec = oldStatbuf->st_mtimensec;
  statbuf->st_ctime = oldStatbuf->st_ctime;
  statbuf->st_ctimensec = oldStatbuf->st_ctimensec;
#endif
#ifdef __x86_64__
  statbuf->__glibc_reserved[0] = oldStatbuf->__glibc_reserved[0];
  statbuf->__glibc_reserved[1] = oldStatbuf->__glibc_reserved[1];
  statbuf->__glibc_reserved[2] = oldStatbuf->__glibc_reserved[2];
#else
# ifndef __USE_FILE_OFFSET64
  statbuf->__glibc_reserved4 = oldStatbuf->__glibc_reserved4;
  statbuf->__glibc_reserved5 = oldStatbuf->__glibc_reserved5;
# else
  statbuf->st_ino = oldStatbuf->st_ino;
# endif
#endif
}

extern int stat(const char *path, struct stat *statbuf) {
  extern int __xstat (int __ver, const char *__filename,
                      struct old_stat *__stat_buf) __THROW __nonnull ((2, 3));
  struct old_stat oldStatbuf;
  statToOldStat(statbuf, &oldStatbuf);
  int rc = __xstat(_STAT_VER, path, &oldStatbuf);
  oldStatToStat(&oldStatbuf, statbuf);
  return rc;
}

extern int fstat(int fd, struct stat *statbuf) {
  extern int __fxstat (int __ver, int __fildes, struct old_stat *__stat_buf)
       __THROW __nonnull ((3));
  struct old_stat oldStatbuf;
  statToOldStat(statbuf, &oldStatbuf);
  int rc = __fxstat(_STAT_VER, fd, &oldStatbuf);
  oldStatToStat(&oldStatbuf, statbuf);
  return rc;
}

extern int lstat(const char *path, struct stat *statbuf) {
  extern int __lxstat (int __ver, const char *__filename,
                       struct old_stat *__stat_buf) __THROW __nonnull ((2, 3));
  struct old_stat oldStatbuf;
  statToOldStat(statbuf, &oldStatbuf);
  int rc = __lxstat(_STAT_VER, path, &oldStatbuf);
  oldStatToStat(&oldStatbuf, statbuf);
  return rc;
}

#ifdef __x86_64__
asm (".symver __xstat, __xstat@GLIBC_2.2.5");
asm (".symver __fxstat, __fxstat@GLIBC_2.2.5");
asm (".symver __lxstat, __lxstat@GLIBC_2.2.5");
#else // 32-bit
asm (".symver __xstat, __xstat@GLIBC_2.0");
asm (".symver __fxstat, __fxstat@GLIBC_2.0");
asm (".symver __lxstat, __lxstat@GLIBC_2.0");
#endif // __x86_64__

// 64-bit extensions

struct old_stat64
{
    __dev_t st_dev;		/* Device.  */
# ifdef __x86_64__
    __ino64_t st_ino;		/* File serial number.  */
    __nlink_t st_nlink;		/* Link count.  */
    __mode_t st_mode;		/* File mode.  */
# else
    unsigned int __pad1;
    __ino_t __st_ino;			/* 32bit file serial number.	*/
    __mode_t st_mode;			/* File mode.  */
    __nlink_t st_nlink;			/* Link count.  */
# endif
    __uid_t st_uid;		/* User ID of the file's owner.	*/
    __gid_t st_gid;		/* Group ID of the file's group.*/
# ifdef __x86_64__
    int __pad0;
    __dev_t st_rdev;		/* Device number, if device.  */
    __off_t st_size;		/* Size of file, in bytes.  */
# else
    __dev_t st_rdev;			/* Device number, if device.  */
    unsigned int __pad2;
    __off64_t st_size;			/* Size of file, in bytes.  */
# endif
    __blksize_t st_blksize;	/* Optimal block size for I/O.  */
    __blkcnt64_t st_blocks;	/* Nr. 512-byte blocks allocated.  */
# ifdef __USE_XOPEN2K8
    /* Nanosecond resolution timestamps are stored in a format
       equivalent to 'struct timespec'.  This is the type used
       whenever possible but the Unix namespace rules do not allow the
       identifier 'timespec' to appear in the <sys/stat.h> header.
       Therefore we have to handle the use of this header in strictly
       standard-compliant sources special.  */
    struct timespec st_atim;		/* Time of last access.  */
    struct timespec st_mtim;		/* Time of last modification.  */
    struct timespec st_ctim;		/* Time of last status change.  */
# else
    __time_t st_atime;			/* Time of last access.  */
    __syscall_ulong_t st_atimensec;	/* Nscecs of last access.  */
    __time_t st_mtime;			/* Time of last modification.  */
    __syscall_ulong_t st_mtimensec;	/* Nsecs of last modification.  */
    __time_t st_ctime;			/* Time of last status change.  */
    __syscall_ulong_t st_ctimensec;	/* Nsecs of last status change.  */
# endif
# ifdef __x86_64__
    __syscall_slong_t __glibc_reserved[3];
# else
    __ino64_t st_ino;			/* File serial number.		*/
# endif
};

void stat64ToOldStat64(const struct stat64 *statbuf, struct old_stat64 *oldStatbuf) {
  oldStatbuf->st_dev = statbuf->st_dev;
# ifdef __x86_64__
  oldStatbuf->st_ino = statbuf->st_ino;
  oldStatbuf->st_nlink = statbuf->st_nlink;
  oldStatbuf->st_mode = statbuf->st_mode;
# else
  oldStatbuf->__pad1 = statbuf->__pad1;
  oldStatbuf->__st_ino = statbuf->__st_ino;
  oldStatbuf->st_mode = statbuf->st_mode;
  oldStatbuf->st_nlink = statbuf->st_nlink;
# endif
  oldStatbuf->st_uid = statbuf->st_uid;
  oldStatbuf->st_gid = statbuf->st_gid;
# ifdef __x86_64__
  oldStatbuf->__pad0 = statbuf->__pad0;
  oldStatbuf->st_rdev = statbuf->st_rdev;
  oldStatbuf->st_size = statbuf->st_size;
# else
  oldStatbuf->st_rdev = statbuf->st_rdev;
  oldStatbuf->__pad2 = statbuf->__pad2;
  oldStatbuf->st_size = statbuf->st_size;
# endif
  oldStatbuf->st_blksize = statbuf->st_blksize;
  oldStatbuf->st_blocks = statbuf->st_blocks;
# ifdef __USE_XOPEN2K8
  oldStatbuf->st_atim = statbuf->st_atim;
  oldStatbuf->st_mtim = statbuf->st_mtim;
  oldStatbuf->st_ctim = statbuf->st_ctim;
# else
  oldStatbuf->st_atime = statbuf->st_atime;
  oldStatbuf->st_atimensec = statbuf->st_atimensec;
  oldStatbuf->st_mtime = statbuf->st_mtime;
  oldStatbuf->st_mtimensec = statbuf->st_mtimensec;
  oldStatbuf->st_ctime = statbuf->st_ctime;
  oldStatbuf->st_ctimensec = statbuf->st_ctimensec;
# endif
# ifdef __x86_64__
  oldStatbuf->__glibc_reserved[0] = statbuf->__glibc_reserved[0];
  oldStatbuf->__glibc_reserved[1] = statbuf->__glibc_reserved[1];
  oldStatbuf->__glibc_reserved[2] = statbuf->__glibc_reserved[2];
# else
  oldStatbuf->st_ino = statbuf->st_ino;
# endif
}

void oldStat64ToStat64(const struct old_stat64 *oldStatbuf, struct stat64 *statbuf) {
  statbuf->st_dev = oldStatbuf->st_dev;
# ifdef __x86_64__
  statbuf->st_ino = oldStatbuf->st_ino;
  statbuf->st_nlink = oldStatbuf->st_nlink;
  statbuf->st_mode = oldStatbuf->st_mode;
# else
  statbuf->__pad1 = oldStatbuf->__pad1;
  statbuf->__st_ino = oldStatbuf->__st_ino;
  statbuf->st_mode = oldStatbuf->st_mode;
  statbuf->st_nlink = oldStatbuf->st_nlink;
# endif
  statbuf->st_uid = oldStatbuf->st_uid;
  statbuf->st_gid = oldStatbuf->st_gid;
# ifdef __x86_64__
  statbuf->__pad0 = oldStatbuf->__pad0;
  statbuf->st_rdev = oldStatbuf->st_rdev;
  statbuf->st_size = oldStatbuf->st_size;
# else
  statbuf->st_rdev = oldStatbuf->st_rdev;
  statbuf->__pad2 = oldStatbuf->__pad2;
  statbuf->st_size = oldStatbuf->st_size;
# endif
  statbuf->st_blksize = oldStatbuf->st_blksize;
  statbuf->st_blocks = oldStatbuf->st_blocks;
# ifdef __USE_XOPEN2K8
  statbuf->st_atim = oldStatbuf->st_atim;
  statbuf->st_mtim = oldStatbuf->st_mtim;
  statbuf->st_ctim = oldStatbuf->st_ctim;
# else
  statbuf->st_atime = oldStatbuf->st_atime;
  statbuf->st_atimensec = oldStatbuf->st_atimensec;
  statbuf->st_mtime = oldStatbuf->st_mtime;
  statbuf->st_mtimensec = oldStatbuf->st_mtimensec;
  statbuf->st_ctime = oldStatbuf->st_ctime;
  statbuf->st_ctimensec = oldStatbuf->st_ctimensec;
# endif
# ifdef __x86_64__
  statbuf->__glibc_reserved[0] = oldStatbuf->__glibc_reserved[0];
  statbuf->__glibc_reserved[1] = oldStatbuf->__glibc_reserved[1];
  statbuf->__glibc_reserved[2] = oldStatbuf->__glibc_reserved[2];
# else
  statbuf->st_ino = oldStatbuf->st_ino;
# endif
}

extern int stat64(const char *path, struct stat64 *statbuf) {
  extern int __xstat64 (int __ver, const char *__filename,
                        struct old_stat64 *__stat_buf) __THROW __nonnull ((2, 3));
  struct old_stat64 oldStatbuf;
  stat64ToOldStat64(statbuf, &oldStatbuf);
  int rc = __xstat64(_STAT_VER, path, &oldStatbuf);
  oldStat64ToStat64(&oldStatbuf, statbuf);
  return rc;
}

extern int fstat64(int fd, struct stat64 *statbuf) {
  extern int __fxstat64 (int __ver, int __fildes, struct old_stat64 *__stat_buf)
       __THROW __nonnull ((3));
  struct old_stat64 oldStatbuf;
  stat64ToOldStat64(statbuf, &oldStatbuf);
  int rc = __fxstat64(_STAT_VER, fd, &oldStatbuf);
  oldStat64ToStat64(&oldStatbuf, statbuf);
  return rc;
}

extern int lstat64(const char *path, struct stat64 *statbuf) {
  extern int __lxstat64 (int __ver, const char *__filename,
                         struct old_stat64 *__stat_buf) __THROW __nonnull ((2, 3));
  struct old_stat64 oldStatbuf;
  stat64ToOldStat64(statbuf, &oldStatbuf);
  int rc = __lxstat64(_STAT_VER, path, &oldStatbuf);
  oldStat64ToStat64(&oldStatbuf, statbuf);
  return rc;
}

#ifdef __x86_64__
asm (".symver __xstat64, __xstat64@GLIBC_2.2.5");
asm (".symver __fxstat64, __fxstat64@GLIBC_2.2.5");
asm (".symver __lxstat64, __lxstat64@GLIBC_2.2.5");
#else // 32-bit
asm (".symver __xstat64, __xstat64@GLIBC_2.2");
asm (".symver __fxstat64, __fxstat64@GLIBC_2.2");
asm (".symver __lxstat64, __lxstat64@GLIBC_2.2");
#endif // __x86_64__

// WARNING:  The fix for the 2038 bug (providing a 64-bit time_t) was provided
// in GLIBC 2.32.  Code above this line will therefore contain that fix, however
// code below this point will be linking against functions that use 32-bit
// time_t values and contain the bug.  Most notably, the clock_gettime wrapper
// below will contain the bug.  This will have to be fixed before the bug
// becomes an issue.

// Break the dependency on GLIBC 2.28 in newer versions of gcc.
#include <fcntl.h>
int __fcntl(int fd, int cmd, ... /* arg */ );

#ifndef __x86_64__
asm (".symver __fcntl, __fcntl@GLIBC_2.0");

int fcntl(int fd, int cmd, ... /* arg */ ) {
  int rc = 0;
  va_list args;
  va_start(args, cmd);
  
  // Process the command.
  switch (cmd) {
    case F_GETFD:
    case F_GETFL:
    case F_GETOWN:
      {
        // Get information from the file descriptor.  No argument.
        rc = __fcntl(fd, cmd);
      }
      break;
    
    case F_DUPFD:
    case F_DUPFD_CLOEXEC:
    case F_SETFD:
    case F_SETFL:
    case F_SETOWN:
      {
        // Interact with the file descriptor using an int argument.
        int arg = va_arg(args, int);
        rc = __fcntl(fd, cmd, arg);
      }
      break;
    
    case F_SETLK:
    case F_SETLKW:
    case F_GETLK:
      {
        // Interact with the file descriptor using a pointer.
        void *arg = va_arg(args, void*);
        rc = __fcntl(fd, cmd, arg);
      }
      break;
    
    default:
      break;
  }
  
  va_end(args);
  
  return rc;
}

#else

asm (".symver __fcntl, fcntl@GLIBC_2.2.5");

#endif // __x86_64__

int fcntl64(int fd, int cmd, ... /* arg */ ) {
  int rc = 0;
  va_list args;
  va_start(args, cmd);
  
  // Process the command.
  switch (cmd) {
    case F_GETFD:
    case F_GETFL:
    case F_GETOWN:
      {
        // Get information from the file descriptor.  No argument.
        rc = __fcntl(fd, cmd);
      }
      break;
    
    case F_DUPFD:
    case F_DUPFD_CLOEXEC:
    case F_SETFD:
    case F_SETFL:
    case F_SETOWN:
      {
        // Interact with the file descriptor using an int argument.
        int arg = va_arg(args, int);
        rc = __fcntl(fd, cmd, arg);
      }
      break;
    
    case F_SETLK:
    case F_SETLKW:
    case F_GETLK:
      {
        // Interact with the file descriptor using a pointer.
        void *arg = va_arg(args, void*);
        rc = __fcntl(fd, cmd, arg);
      }
      break;
    
    default:
      break;
  }
  
  va_end(args);
  
  return rc;
}

// Break the dependency on GLIBC 2.25 in newer versions of gcc.
int getentropy(void *buffer, size_t length) {
  if (length > 256) {
    errno = EIO;
    return -1;
  }
  
  Bytes binaryData = getFileContent("/dev/random", 0, (i64) length);
  if (bytesLength(binaryData) != length) {
    errno = ENOSYS;
    return -1;
  }
  
  memcpy(buffer, (const void*) binaryData, length);
  binaryData = bytesDestroy(binaryData);
  
  return 0;
}

// Break the dependency on GLIBC 2.17 in newer versions of gcc.
#include <sys/time.h>
#ifdef __x86_64__
asm (".symver clock_gettime, clock_gettime@GLIBC_2.2.5");
#else // 32-bit
asm (".symver clock_gettime, clock_gettime@GLIBC_2.2");
#endif

int __wrap_clock_gettime(clockid_t clockid, struct timespec *tp) {
  int clock_gettime(clockid_t clockid, struct timespec *tp);
  return clock_gettime(clockid, tp);
}

/*
#ifndef __USE_GNU
#define __USE_GNU
#endif
#include <dlfcn.h>
*/
char* getenv(const char *name);
char *secure_getenv(const char *name) {
  return getenv(name);
}

// Break the dependency on GLIBC 2.15 in newer versions of gcc.
#include <signal.h>
long int __fdelt_chk(long int d) {
  if ((d < 0) || (d >= FD_SETSIZE)) {
    fprintf(stderr, "buffer overflow detected");
    raise(SIGABRT);
  }
  
  return d / __NFDBITS;
}

// Break the dependency on GLIBC 2.14 in newer versions of gcc.
void* __memcpy_chk(void *dest, const void *src, size_t srclen, size_t destlen);
void* memcpy(void *dest, const void *src, size_t n) {
  return __memcpy_chk(dest, src, n, n);
}


#ifdef __cplusplus
}
#endif

#endif // __GNUC__
#endif // __MINGW32__


