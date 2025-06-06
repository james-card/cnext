////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                     Copyright (c) 2012-2025 James Card                     //
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

#include <errno.h>

#include "DirectoryLib.h"
#include "StringLib.h"

#ifdef LOGGING_ENABLED
#include "LoggingLib.h"
#else
#undef printLog
#define printLog(...) {}
#define LOG_MALLOC_FAILURE(...) {}
#define logFile stderr
#endif

#ifdef _WIN32

/*
 * Open directory stream DIRNAME for read and return a pointer to the
 * internal working area that is used to retrieve individual directory
 * entries.
 */
_WDIR *_wopendir(const wchar_t *dirname)
{
	wchar_t *p;

	/* Must have directory name */
	if (dirname == NULL || dirname[0] == '\0') {
		dirent_set_errno(ENOENT);
		return NULL;
	}

	/* Allocate new _WDIR structure */
	_WDIR *dirp = (_WDIR*) malloc(sizeof(struct _WDIR));
	if (!dirp)
		return NULL;

	/* Reset _WDIR structure */
	dirp->handle = INVALID_HANDLE_VALUE;
	dirp->patt = NULL;
	dirp->cached = 0;

	/*
	 * Compute the length of full path plus zero terminator
	 *
	 * Note that on WinRT there's no way to convert relative paths
	 * into absolute paths, so just assume it is an absolute path.
	 */
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
	/* Desktop */
	DWORD n = GetFullPathNameW(dirname, 0, NULL, NULL);
#else
	/* WinRT */
	size_t n = wcslen(dirname);
#endif

	/* Allocate room for absolute directory name and search pattern */
	dirp->patt = (wchar_t*) malloc(sizeof(wchar_t) * n + 16);
	if (dirp->patt == NULL)
		goto exit_closedir;

	/*
	 * Convert relative directory name to an absolute one.  This
	 * allows rewinddir() to function correctly even when current
	 * working directory is changed between opendir() and rewinddir().
	 *
	 * Note that on WinRT there's no way to convert relative paths
	 * into absolute paths, so just assume it is an absolute path.
	 */
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
	/* Desktop */
	n = GetFullPathNameW(dirname, n, dirp->patt, NULL);
	if (n <= 0)
		goto exit_closedir;
#else
	/* WinRT */
	wcsncpy_s(dirp->patt, n+1, dirname, n);
#endif

	/* Append search pattern \* to the directory name */
	p = dirp->patt + n;
	switch (p[-1]) {
	case '\\':
	case '/':
	case ':':
		/* Directory ends in path separator, e.g. c:\temp\ */
		/*NOP*/;
		break;

	default:
		/* Directory name doesn't end in path separator */
		*p++ = '\\';
	}
	*p++ = '*';
	*p = '\0';

	/* Open directory stream and retrieve the first entry */
	if (!dirent_first(dirp))
		goto exit_closedir;

	/* Success */
	return dirp;

	/* Failure */
exit_closedir:
	_wclosedir(dirp);
	return NULL;
}

/*
 * Read next directory entry.
 *
 * Returns pointer to static directory entry which may be overwritten by
 * subsequent calls to _wreaddir().
 */
struct _wdirent *_wreaddir(_WDIR *dirp)
{
	/*
	 * Read directory entry to buffer.  We can safely ignore the return
	 * value as entry will be set to NULL in case of error.
	 */
	struct _wdirent *entry;
	(void) _wreaddir_r(dirp, &dirp->ent, &entry);

	/* Return pointer to statically allocated directory entry */
	return entry;
}

/*
 * Read next directory entry.
 *
 * Returns zero on success.  If end of directory stream is reached, then sets
 * result to NULL and returns zero.
 */
int _wreaddir_r(
	_WDIR *dirp, struct _wdirent *entry, struct _wdirent **result)
{
	/* Read next directory entry */
	WIN32_FIND_DATAW *datap = dirent_next(dirp);
	if (!datap) {
		/* Return NULL to indicate end of directory */
		*result = NULL;
		return /*OK*/0;
	}

	/*
	 * Copy file name as wide-character string.  If the file name is too
	 * long to fit in to the destination buffer, then truncate file name
	 * to PATH_MAX characters and zero-terminate the buffer.
	 */
	size_t n = 0;
	while (n < PATH_MAX && datap->cFileName[n] != 0) {
		entry->d_name[n] = datap->cFileName[n];
		n++;
	}
	entry->d_name[n] = 0;

	/* Length of file name excluding zero terminator */
	entry->d_namlen = n;

	/* File type */
	DWORD attr = datap->dwFileAttributes;
	if ((attr & FILE_ATTRIBUTE_DEVICE) != 0)
		entry->d_type = DT_CHR;
	else if ((attr & FILE_ATTRIBUTE_DIRECTORY) != 0)
		entry->d_type = DT_DIR;
	else
		entry->d_type = DT_REG;

	/* Reset dummy fields */
	entry->d_ino = 0;
	entry->d_off = 0;
	entry->d_reclen = sizeof(struct _wdirent);

	/* Set result address */
	*result = entry;
	return /*OK*/0;
}

/*
 * Close directory stream opened by opendir() function.  This invalidates the
 * DIR structure as well as any directory entry read previously by
 * _wreaddir().
 */
int _wclosedir(_WDIR *dirp)
{
	if (!dirp) {
		dirent_set_errno(EBADF);
		return /*failure*/-1;
	}

	/* Release search handle */
	if (dirp->handle != INVALID_HANDLE_VALUE)
		FindClose(dirp->handle);

	/* Release search pattern */
	dirp->patt = pointerDestroy(dirp->patt);

	/* Release directory structure */
	dirp = pointerDestroy(dirp);
	return /*success*/0;
}

/*
 * Rewind directory stream such that _wreaddir() returns the very first
 * file name again.
 */
void _wrewinddir(_WDIR* dirp)
{
	if (!dirp)
		return;

	/* Release existing search handle */
	if (dirp->handle != INVALID_HANDLE_VALUE)
		FindClose(dirp->handle);

	/* Open new search handle */
	dirent_first(dirp);
}

/* Get first directory entry */
WIN32_FIND_DATAW *dirent_first(_WDIR *dirp)
{
	if (!dirp)
		return NULL;

	/* Open directory and retrieve the first entry */
	dirp->handle = FindFirstFileExW(
		dirp->patt, FindExInfoStandard, &dirp->data,
		FindExSearchNameMatch, NULL, 0);
	if (dirp->handle == INVALID_HANDLE_VALUE)
		goto error;

	/* A directory entry is now waiting in memory */
	dirp->cached = 1;
	return &dirp->data;

error:
	/* Failed to open directory: no directory entry in memory */
	dirp->cached = 0;

	/* Set error code */
	DWORD errorcode = GetLastError();
	switch (errorcode) {
	case ERROR_ACCESS_DENIED:
		/* No read access to directory */
		dirent_set_errno(EACCES);
		break;

	case ERROR_DIRECTORY:
		/* Directory name is invalid */
		dirent_set_errno(ENOTDIR);
		break;

	case ERROR_PATH_NOT_FOUND:
	default:
		/* Cannot find the file */
		dirent_set_errno(ENOENT);
	}
	return NULL;
}

/* Get next directory entry */
WIN32_FIND_DATAW *dirent_next(_WDIR *dirp)
{
	/* Is the next directory entry already in cache? */
	if (dirp->cached) {
		/* Yes, a valid directory entry found in memory */
		dirp->cached = 0;
		return &dirp->data;
	}

	/* No directory entry in cache */
	if (dirp->handle == INVALID_HANDLE_VALUE)
		return NULL;

	/* Read the next directory entry from stream */
	if (FindNextFileW(dirp->handle, &dirp->data) == FALSE)
		goto exit_close;

	/* Success */
	return &dirp->data;

	/* Failure */
exit_close:
	FindClose(dirp->handle);
	dirp->handle = INVALID_HANDLE_VALUE;
	return NULL;
}

/* Open directory stream using plain old C-string */
DIR *opendir(const char *dirname)
{
	/* Must have directory name */
	if (dirname == NULL || dirname[0] == '\0') {
		dirent_set_errno(ENOENT);
		return NULL;
	}

	/* Allocate memory for DIR structure */
	struct DIR *dirp = (DIR*) malloc(sizeof(struct DIR));
	if (!dirp)
		return NULL;

	/* Convert directory name to wide-character string */
	wchar_t wname[PATH_MAX + 1];
	size_t n;
	int error = mbstowcs_s(&n, wname, PATH_MAX + 1, dirname, PATH_MAX+1);
	if (error)
		goto exit_failure;

	/* Open directory stream using wide-character name */
	dirp->wdirp = _wopendir(wname);
	if (!dirp->wdirp)
		goto exit_failure;

	/* Success */
	return dirp;

	/* Failure */
exit_failure:
	dirp = pointerDestroy(dirp);
	return NULL;
}

/* Read next directory entry */
struct dirent *readdir(DIR *dirp)
{
	/*
	 * Read directory entry to buffer.  We can safely ignore the return
	 * value as entry will be set to NULL in case of error.
	 */
	struct dirent *entry;
	(void) readdir_r(dirp, &dirp->ent, &entry);

	/* Return pointer to statically allocated directory entry */
	return entry;
}

/*
 * Read next directory entry into called-allocated buffer.
 *
 * Returns zero on success.  If the end of directory stream is reached, then
 * sets result to NULL and returns zero.
 */
int readdir_r(
	DIR *dirp, struct dirent *entry, struct dirent **result)
{
	/* Read next directory entry */
	WIN32_FIND_DATAW *datap = dirent_next(dirp->wdirp);
	if (!datap) {
		/* No more directory entries */
		*result = NULL;
		return /*OK*/0;
	}

	/* Attempt to convert file name to multi-byte string */
	size_t n;
	int error = wcstombs_s(
		&n, entry->d_name, PATH_MAX + 1,
		datap->cFileName, PATH_MAX + 1);

	/*
	 * If the file name cannot be represented by a multi-byte string, then
	 * attempt to use old 8+3 file name.  This allows the program to
	 * access files although file names may seem unfamiliar to the user.
	 *
	 * Be ware that the code below cannot come up with a short file name
	 * unless the file system provides one.  At least VirtualBox shared
	 * folders fail to do this.
	 */
	if (error && datap->cAlternateFileName[0] != '\0') {
		error = wcstombs_s(
			&n, entry->d_name, PATH_MAX + 1,
			datap->cAlternateFileName, PATH_MAX + 1);
	}

	if (!error) {
		/* Length of file name excluding zero terminator */
		entry->d_namlen = n - 1;

		/* File attributes */
		DWORD attr = datap->dwFileAttributes;
		if ((attr & FILE_ATTRIBUTE_DEVICE) != 0)
			entry->d_type = DT_CHR;
		else if ((attr & FILE_ATTRIBUTE_DIRECTORY) != 0)
			entry->d_type = DT_DIR;
		else
			entry->d_type = DT_REG;

		/* Reset dummy fields */
		entry->d_ino = 0;
		entry->d_off = 0;
		entry->d_reclen = sizeof(struct dirent);
	} else {
		/*
		 * Cannot convert file name to multi-byte string so construct
		 * an erroneous directory entry and return that.  Note that
		 * we cannot return NULL as that would stop the processing
		 * of directory entries completely.
		 */
		entry->d_name[0] = '?';
		entry->d_name[1] = '\0';
		entry->d_namlen = 1;
		entry->d_type = DT_UNKNOWN;
		entry->d_ino = 0;
		entry->d_off = -1;
		entry->d_reclen = 0;
	}

	/* Return pointer to directory entry */
	*result = entry;
	return /*OK*/0;
}

/* Close directory stream */
int closedir(DIR *dirp)
{
	int ok;

	if (!dirp)
		goto exit_failure;

	/* Close wide-character directory stream */
	ok = _wclosedir(dirp->wdirp);
	dirp->wdirp = NULL;

	/* Release multi-byte character version */
	dirp = pointerDestroy(dirp);
	return ok;

exit_failure:
	/* Invalid directory stream */
	dirent_set_errno(EBADF);
	return /*failure*/-1;
}

/* Rewind directory stream to beginning */
void rewinddir(DIR* dirp)
{
	if (!dirp)
		return;

	/* Rewind wide-character string directory stream */
	_wrewinddir(dirp->wdirp);
}

/* Scan directory for entries */
int scandir(
	const char *dirname, struct dirent ***namelist,
	int (*filter)(const struct dirent*),
	int (*compare)(const struct dirent**, const struct dirent**))
{
	int result;

	/* Open directory stream */
	DIR *dir = opendir(dirname);
	if (!dir) {
		/* Cannot open directory */
		return /*Error*/ -1;
	}

	/* Read directory entries to memory */
	struct dirent *tmp = NULL;
	struct dirent **files = NULL;
	size_t size = 0;
	size_t allocated = 0;
	while (1) {
		/* Allocate room for a temporary directory entry */
		if (!tmp) {
			tmp = (struct dirent*) malloc(sizeof(struct dirent));
			if (!tmp)
				goto exit_failure;
		}

		/* Read directory entry to temporary area */
		struct dirent *entry;
		if (readdir_r(dir, tmp, &entry) != /*OK*/0)
			goto exit_failure;

		/* Stop if we already read the last directory entry */
		if (entry == NULL)
			goto exit_success;

		/* Determine whether to include the entry in results */
		if (filter && !filter(tmp))
			continue;

		/* Enlarge pointer table to make room for another pointer */
		if (size >= allocated) {
			/* Compute number of entries in the new table */
			size_t num_entries = size * 2 + 16;

			/* Allocate new pointer table or enlarge existing */
			void *p = realloc(files, sizeof(void*) * num_entries);
			if (!p)
				goto exit_failure;

			/* Got the memory */
			files = (dirent**) p;
			allocated = num_entries;
		}

		/* Store the temporary entry to ptr table */
		files[size++] = tmp;
		tmp = NULL;
	}

exit_failure:
	/* Release allocated file entries */
	for (size_t i = 0; i < size; i++) {
		files[i] = pointerDestroy(files[i]);
	}

	/* Release the pointer table */
	files = pointerDestroy(files);
	files = NULL;

	/* Exit with error code */
	result = /*error*/ -1;
	goto exit_status;

exit_success:
	/* Sort directory entries */
	qsort(files, size, sizeof(void*),
		(int (*) (const void*, const void*)) compare);

	/* Pass pointer table to caller */
	if (namelist)
		*namelist = files;

	/* Return the number of directory entries read */
	result = (int) size;

exit_status:
	/* Release temporary directory entry, if we had one */
	tmp = pointerDestroy(tmp);

	/* Close directory stream */
	closedir(dir);
	return result;
}

/* Alphabetical sorting */
int alphasort(const struct dirent **a, const struct dirent **b)
{
	return strcoll((*a)->d_name, (*b)->d_name);
}

/* Sort versions */
int versionsort(const struct dirent **a, const struct dirent **b)
{
	return strverscmp((*a)->d_name, (*b)->d_name);
}

/* Compare strings */
int strverscmp(const char *a, const char *b)
{
	size_t i = 0;
	size_t j;

	/* Find first difference */
	while (a[i] == b[i]) {
		if (a[i] == '\0') {
			/* No difference */
			return 0;
		}
		++i;
	}

	/* Count backwards and find the leftmost digit */
	j = i;
	while (j > 0 && isdigit(a[j-1])) {
		--j;
	}

	/* Determine mode of comparison */
	if (a[j] == '0' || b[j] == '0') {
		/* Find the next non-zero digit */
		while (a[j] == '0' && a[j] == b[j]) {
			j++;
		}

		/* String with more digits is smaller, e.g 002 < 01 */
		if (isdigit(a[j])) {
			if (!isdigit(b[j])) {
				return -1;
			}
		} else if (isdigit(b[j])) {
			return 1;
		}
	} else if (isdigit(a[j]) && isdigit(b[j])) {
		/* Numeric comparison */
		size_t k1 = j;
		size_t k2 = j;

		/* Compute number of digits in each string */
		while (isdigit(a[k1])) {
			k1++;
		}
		while (isdigit(b[k2])) {
			k2++;
		}

		/* Number with more digits is bigger, e.g 999 < 1000 */
		if (k1 < k2)
			return -1;
		else if (k1 > k2)
			return 1;
	}

	/* Alphabetical comparison */
	return (int) ((unsigned char) a[i]) - ((unsigned char) b[i]);
}

/* Convert multi-byte string to wide character string */
#if !defined(_MSC_VER) || _MSC_VER < 1400
int dirent_mbstowcs_s(
	size_t *pReturnValue, wchar_t *wcstr,
	size_t sizeInWords, const char *mbstr, size_t count)
{
	/* Older Visual Studio or non-Microsoft compiler */
	size_t n = mbstowcs(wcstr, mbstr, sizeInWords);
	if (wcstr && n >= count)
		return /*error*/ 1;

	/* Zero-terminate output buffer */
	if (wcstr && sizeInWords) {
		if (n >= sizeInWords)
			n = sizeInWords - 1;
		wcstr[n] = 0;
	}

	/* Length of multi-byte string with zero terminator */
	if (pReturnValue) {
		*pReturnValue = n + 1;
	}

	/* Success */
	return 0;
}
#endif

/* Convert wide-character string to multi-byte string */
#if !defined(_MSC_VER) || _MSC_VER < 1400
int dirent_wcstombs_s(
	size_t *pReturnValue, char *mbstr,
	size_t sizeInBytes, const wchar_t *wcstr, size_t count)
{
	/* Older Visual Studio or non-Microsoft compiler */
	size_t n = wcstombs(mbstr, wcstr, sizeInBytes);
	if (mbstr && n >= count)
		return /*error*/1;

	/* Zero-terminate output buffer */
	if (mbstr && sizeInBytes) {
		if (n >= sizeInBytes) {
			n = sizeInBytes - 1;
		}
		mbstr[n] = '\0';
	}

	/* Length of resulting multi-Bytes string WITH zero-terminator */
	if (pReturnValue) {
		*pReturnValue = n + 1;
	}

	/* Success */
	return 0;
}
#endif

/* Set errno variable */
#if !defined(_MSC_VER) || _MSC_VER < 1400
void dirent_set_errno(int error)
{
	/* Non-Microsoft compiler or older Microsoft compiler */
	errno = error;
}
#endif

#endif // _WIN32

/// @fn bool isDirectory(const char *path)
///
/// @brief Determine whether or not a provided path is a directory.
///
/// @path The path to the directory.  This may be either an absolute path or
///   a path relative to the running program's current working directory.
///
/// @return Returns true if the provided path can be determined to be a
/// directory, false otherwise.
bool isDirectory(const char *path) {
  DIR *dir = opendir(path);
  if (dir == NULL) {
    return false;
  }
  closedir(dir); dir = NULL;
  return true;
}

/// @fn int mkpath(const char *path, mode_t mode)
///
/// @param path The full path to create.  Trailing '/' is optional.
/// @param mode The mode to create the path directories with as required by the
///   mkdir call.
///
/// @return Returns 0 on success, the value of errno on failure.
int mkpath(const char *path, int mode) {
  int returnValue = 0;
  
  if (mkdir(path, mode) != 0) {
    if (errno == ENOENT) {
      char *subPath = NULL;
      straddstr(&subPath, path);
      char *slashAt = strrchr(subPath, '/');
      if (slashAt == &subPath[strlen(subPath) - 1]) {
        // The expected case
        *slashAt = '\0';
        slashAt = strrchr(subPath, '/');
      }
      if (slashAt == NULL) {
        // We're at root.  Nothing we can do.
        subPath = stringDestroy(subPath);
        return ENOENT; // The value of errno.
      }
      slashAt++;
      *slashAt = '\0';
      returnValue = mkpath(subPath, mode);
      subPath = stringDestroy(subPath);
      if (returnValue == 0) {
        returnValue = mkdir(path, mode);
      } // else we cascade the value returned by mkpath upward
    } else if (errno == EEXIST) {
      // Make sure it's a directory.
      DIR *dir = opendir(path);
      if (dir == NULL) {
        // Cannot open the directory.  Error.
        printLog(ERR, "Cannot create directory.  Non-directory already exists.\n");
        return EEXIST; // The value of errno.
      }
      closedir(dir); dir = NULL;
      // returnValue is 0, indicating success since the directory already exists
    } else {
      returnValue = errno;
    }
  }
  
  return returnValue;
}

/// @fn int rmdirRecursive(const char *directory)
///
/// @brief Recursively remove a directory and all of its contents.
///
/// @param directory The full path to the directory.  Trailing '/' is optional.
///
/// @return Returns 0 on success, -1 on failure.
int rmdirRecursive(const char *directory) {
  if ((directory == NULL) || (*directory == '\0')) {
    printLog(ERR, "NULL or empty directory provided.\n");
    return -1;
  }
  
  DIR *dir = NULL;
  struct dirent *entry = NULL;
  
  char *directoryName = NULL;
  straddstr(&directoryName, directory);
  if (directoryName[strlen(directoryName) - 1] != '/') {
    straddstr(&directoryName, "/");
  }
  
  dir = opendir(directoryName);
  if (dir == NULL) {
    // Cannot open the directory.  Error.
    printLog(ERR, "Cannot open directory \"%s\".\n", directoryName);
    printLog(ERR, "%s\n", strerror(errno));
    directoryName = stringDestroy(directoryName);
    return -1;
  }
  
  int returnValue = 0;
  entry = readdir(dir);
  while (entry != NULL) {
    char *entryName = entry->d_name;
    if ((strcmp(entryName, "..") == 0) || (strcmp(entryName, ".") == 0)) {
      // AVOID THESE AT ALL COSTS!  RECURSING INTO THEM WILL DESTROY US!!!
      entry = readdir(dir);
      continue;
    }
    char *fullPath = NULL;
    straddstr(&fullPath, directoryName);
    straddstr(&fullPath, entryName);
    DIR *tryDir = opendir(fullPath);
    if (tryDir != NULL) {
      closedir(tryDir);
      straddchr(&fullPath, '/');
      returnValue |= rmdirRecursive(fullPath);
    } else {
      returnValue |= remove(fullPath);
    }
    if (returnValue != 0) {
      printLog(ERR, "Could not remove \"%s\".\n", fullPath);
    }
    fullPath = stringDestroy(fullPath);
    entry = readdir(dir);
  }
  closedir(dir); dir = NULL;
  
  returnValue |= rmdir(directoryName);
  
  directoryName = stringDestroy(directoryName);
  return returnValue;
}

/// @fn char** destroyDirectoryEntries(char **directoryEntries)
///
/// @brief Destroy a previously-allocated array of directory entries.
///
/// @param directoryEntries The array previously allocated.
///
/// @return This function always returns NULL.
char** destroyDirectoryEntries(char **directoryEntries) {
  if (directoryEntries == NULL) {
    // Nothing to do.
    return NULL;
  }
  
  for (uint64_t ii = 0; directoryEntries[ii] != NULL; ii++) {
    directoryEntries[ii] = stringDestroy(directoryEntries[ii]);
  }
  
  directoryEntries = (char**) pointerDestroy(directoryEntries);
  return directoryEntries;
}

/// @fn char** getDirectoryEntries(const char *path)
///
/// @brief Get the entries (file names and directory names) in a specified
/// directrory, excluding "." and ".." which are part of every directory.
///
/// @param path The full path to the directory.  Trailing '/' is optional.
///
/// @return Returns a NULL-terminated array of entries on success, NULL on
/// failure.
char** getDirectoryEntries(const char *path) {
  if ((path == NULL) || (*path == '\0')) {
    printLog(ERR, "NULL or empty path provided.\n");
    return NULL;
  }
  
  DIR *dir = NULL;
  struct dirent *entry = NULL;
  
  char *pathName = NULL;
  straddstr(&pathName, path);
  if (pathName[strlen(pathName) - 1] != '/') {
    straddstr(&pathName, "/");
  }
  
  dir = opendir(pathName);
  if (dir == NULL) {
    // Cannot open the path.  Error.
    printLog(ERR, "Cannot open path \"%s\".\n", pathName);
    printLog(ERR, "%s\n", strerror(errno));
    pathName = stringDestroy(pathName);
    return NULL;
  }
  
  uint64_t numEntries = 0;
  char **returnValue = (char**) calloc(1, sizeof(char*));
  entry = readdir(dir);
  while (entry != NULL) {
    char *entryName = entry->d_name;
    if ((strcmp(entryName, "..") == 0) || (strcmp(entryName, ".") == 0)) {
      // AVOID THESE AT ALL COSTS!  RECURSING INTO THEM WILL DESTROY US!!!
      entry = readdir(dir);
      continue;
    }
    numEntries++;
    
    void *check = realloc(returnValue, (numEntries + 1) * sizeof(char*));
    if (check == NULL) {
      LOG_MALLOC_FAILURE();
      returnValue = destroyDirectoryEntries(returnValue);
      return NULL;
    }
    returnValue = (char**) check;
    
    returnValue[numEntries] = NULL;
    // returnValue[numEntries - 1] is already NULL.
    straddstr(&returnValue[numEntries - 1], entryName);
    
    entry = readdir(dir);
  }
  closedir(dir); dir = NULL;
  
  pathName = stringDestroy(pathName);
  return returnValue;
}

/// @fn char** selectDirectoryEntries(const char *path, const char **directoryEntries, DirectoryEntryType entryType)
///
/// @brief Select only the directory entries that are interesting.
///
/// @param path The full path to the directory.
/// @param directoryEntries The previously-collected list of entries in the
///   directory.
/// @param entryType A DirectoryEntryType value indicating the kind of entry
///   of interest.  Only entries of this type will be returned.
char** selectDirectoryEntries(const char *path, const char **directoryEntries,
  DirectoryEntryType entryType
) {
  if ((path == NULL) || (*path == '\0')) {
    printLog(ERR, "NULL or empty path provided.\n");
    return NULL;
  } else if (directoryEntries == NULL) {
    printLog(ERR, "NULL directoryEntries provided.\n");
    return NULL;
  }
  
  char *pathName = NULL;
  straddstr(&pathName, path);
  if (pathName[strlen(pathName) - 1] != '/') {
    straddstr(&pathName, "/");
  }
  
  uint64_t numEntries = 0;
  char **returnValue = (char**) calloc(1, sizeof(char*));
  
  for (uint64_t ii = 0; directoryEntries[ii] != NULL; ii++) {
    const char *entryName = directoryEntries[ii];
    char *fullPath = NULL;
    straddstr(&fullPath, pathName);
    straddstr(&fullPath, entryName);
    DIR *tryDir = opendir(fullPath);
    if (tryDir != NULL) {
      // Entry is a directory.  See if the user wants it.
      closedir(tryDir);
      if (entryType == ENTRY_TYPE_DIRECTORY) {
        numEntries++;
        void *check = realloc(returnValue, (numEntries + 1) * sizeof(char*));
        if (check == NULL) {
          LOG_MALLOC_FAILURE();
          returnValue = destroyDirectoryEntries(returnValue);
          return NULL;
        }
        returnValue = (char**) check;
        
        returnValue[numEntries] = NULL;
        // returnValue[numEntries - 1] is already NULL.
        straddstr(&returnValue[numEntries - 1], entryName);
      } // else the user is not interested in this entry
    } else if (entryType == ENTRY_TYPE_FILE) {
      // Entry is a file and the user wants it.
      numEntries++;
      void *check = realloc(returnValue, (numEntries + 1) * sizeof(char*));
      if (check == NULL) {
        LOG_MALLOC_FAILURE();
        returnValue = destroyDirectoryEntries(returnValue);
        return NULL;
      }
      returnValue = (char**) check;
      
      returnValue[numEntries] = NULL;
      // returnValue[numEntries - 1] is already NULL.
      straddstr(&returnValue[numEntries - 1], entryName);
    } // else the user is not interested in this entry.
    
    fullPath = stringDestroy(fullPath);
  }
  
  pathName = stringDestroy(pathName);
  return returnValue;
}

/// @fn char** getDirectoryFiles(const char *path)
///
/// @brief Get the only the files in a directory.
///
/// @param path The full path to the directory.  Trailing '/' is optional.
///
/// @return Returns a NULL-terminated array of entries on success, NULL on
/// failure.
char** getDirectoryFiles(const char *path) {
  char **entries = getDirectoryEntries(path);
  char **returnValue = selectDirectoryEntries(path, (const char**) entries, ENTRY_TYPE_FILE);
  entries = destroyDirectoryEntries(entries);
  
  return returnValue;
}

/// @fn char** getDirectoryDirectories(const char *path)
///
/// @brief Get the only the directories in a directory.
///
/// @param path The full path to the directory.  Trailing '/' is optional.
///
/// @return Returns a NULL-terminated array of entries on success, NULL on
/// failure.
char** getDirectoryDirectories(const char *path) {
  char **entries = getDirectoryEntries(path);
  char **returnValue
    = selectDirectoryEntries(path, (const char**) entries, ENTRY_TYPE_DIRECTORY);
  entries = destroyDirectoryEntries(entries);
  
  return returnValue;
}

