///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              11.02.2019
///
/// @file              RsaLib.h
///
/// @brief             These are the support functions that handle RSA
///                    encryption and decryption.
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

#ifndef RSA_LIB_H
#define RSA_LIB_H

#include <stdio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include "StringLib.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define RSA_LIB_KEY_LENGTH 8192
#define RSA_LIB_BUFFER_SIZE (RSA_LIB_KEY_LENGTH / 8)
#define RSA_LIB_MAX_PLAINTEXT_SIZE 980

EVP_PKEY *rsaLoadKeyFromString(const unsigned char *key);
EVP_PKEY *rsaLoadKeyFromFile(const char *fileName);
Bytes rsaEncrypt(const volatile void *data, u64 length, EVP_PKEY *pkey);
Bytes rsaDecrypt(const volatile void *data, u64 length, EVP_PKEY *pkey);
void rsaPrintLastError();

#ifdef __cplusplus
} // extern "C"
#endif

#endif // RSA_LiB_H

