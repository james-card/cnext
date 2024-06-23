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
/// @file rsaLib.c

#include "RsaLib.h"
#include <openssl/engine.h>
#include <openssl/decoder.h>

#define PADDING RSA_PKCS1_OAEP_PADDING

/// @def LOG_MALLOC_FAILURE
///
/// @brief Attempt to log a memory allocation failure to standard error.
/// Cannot make use of anything that would allocate memory.
/// This is intended to be a last gasp for the program.
#define LOG_MALLOC_FAILURE() \
    do { \
      fputs(__FILE__, stderr); \
      fputs(":", stderr); \
      fputs(__func__, stderr); \
      fputs(".", stderr); \
      fputs(STRINGIFY(__LINE__) ": malloc failure\n", stderr); \
    } while (0)

/// @note To generate a new private key:
/// openssl genrsa -out private.pem <RSA_LIB_KEY_LENGTH>
/// To generate a public key from the new private key:
/// openssl rsa -in private.pem -outform PEM -pubout -out public.pem

/// @note These functions are intended to be used with the logging library,
/// so standard printLog calls are avoided in this libary.

/// @fn EVP_PKEY *rsaLoadKeyFromString(const unsigned char *key)
///
/// @brief Load the key that will be used by an instance of this
/// library from a C string.
///
/// @param key A C string containing the text to use for the key.
///
/// @return Returns an EVP_PKEY key on success, NULL on failure.
EVP_PKEY *rsaLoadKeyFromString(const unsigned char *key) {
  OSSL_DECODER_CTX *dctx= NULL;
  
  EVP_PKEY *pkey = NULL;
  const char *format = "PEM";       // NULL for any format
  const char *structure = NULL;     // any structure
  const char *keytype = "RSA";      // NULL for any key
  dctx = OSSL_DECODER_CTX_new_for_pkey(&pkey, format, structure,
                                       keytype,
                                       EVP_PKEY_KEYPAIR,
                                       NULL, NULL);
  if (dctx == NULL) {
    fprintf(stderr, "Failed to instantiate RSA key.\n");
    rsaPrintLastError();
    return NULL;
  }
  
  BIO *bio = BIO_new_mem_buf((void*) key, -1);
  if (bio == NULL) {
    fprintf(stderr, "Failed to create key BIO.\n");
    rsaPrintLastError();
    OSSL_DECODER_CTX_free(dctx);
    return NULL;
  }
  
  if (!OSSL_DECODER_from_bio(dctx, bio)) {
    fprintf(stderr, "Failed to instantiate RSA key.\n");
    rsaPrintLastError();
    OSSL_DECODER_CTX_free(dctx);
    BIO_free(bio); bio = NULL;
    return NULL;
  } else if (pkey == NULL) {
    fprintf(stderr, "Failed to allocate EVP_PKEY for RSA key.\n");
    rsaPrintLastError();
    return NULL;
  }
  
  OSSL_DECODER_CTX_free(dctx);
  BIO_free(bio); bio = NULL;
  
  return pkey;
}

/// @fn EVP_PKEY *rsaLoadKeyFromFile(const char *fileName)
///
/// @brief Load the key that will be used by an instance of this
/// library from a file.
///
/// @param fileName The name of the file to load the key from.
///
/// @return Returns an EVP_PKEY key on success, NULL on failure.
EVP_PKEY *rsaLoadKeyFromFile(const char *fileName) {
  Bytes key = getFileContent(fileName);
  EVP_PKEY *pkey = rsaLoadKeyFromString(ustr(key));
  key = bytesDestroy(key);
  
  return pkey;
}

/// @fn Bytes rsaEncrypt(const volatile void *data, u64 length, EVP_PKEY *pkey)
///
/// @brief Peform public key encryption on data of arbitrary length.
///
/// @param data The plaintext data to encrypt.
/// @param length The length of the plaintext data.
/// @param pkey A pointer to a previously-initialized EVP_PKEY object.
///
/// @return Returns a Bytes object with the cyphertext on success, NULL on
/// failure.
Bytes rsaEncrypt(const volatile void *data, u64 length, EVP_PKEY *pkey) {
  Bytes cyphertext = NULL;
  EVP_PKEY_CTX *context = NULL;
  size_t cyphertextLength = 0;
  
  if (pkey == NULL) {
    fprintf(stderr, "Key not loaded.  Cannot encrypt.\n");
    goto exit; // return NULL
  }
  
  // Setup the context.
  context = EVP_PKEY_CTX_new(pkey, NULL);
  if (context == NULL) {
    fprintf(stderr, "Could not get key context.  Cannot encrypt.\n");
    rsaPrintLastError();
    goto exit; // return NULL
  } else if (EVP_PKEY_encrypt_init(context) <= 0) {
    fprintf(stderr,
      "Could not initialize encryption context.  Cannot encrypt.\n");
    rsaPrintLastError();
    goto evpPkeyCtxFree; // return NULL
  } else if (EVP_PKEY_CTX_set_rsa_padding(context, PADDING) <= 0) {
    fprintf(stderr,
      "Could not set padding on encryption context.  Cannot encrypt.\n");
    rsaPrintLastError();
    goto evpPkeyCtxFree; // return NULL
  }
  
  if (EVP_PKEY_encrypt(context, NULL, &cyphertextLength,
    ustr(data), length) <= 0
  ) {
    fprintf(stderr,
      "Could not determine length of cyphertext.  Cannot encrypt.\n");
    rsaPrintLastError();
    goto evpPkeyCtxFree; // return NULL
  }
  
  if (cyphertextLength == 0) {
    fprintf(stderr, "Invalid input data.  Cannot decrypt.\n");
    rsaPrintLastError();
    goto evpPkeyCtxFree; // return NULL
  }
  
  bytesAllocate(&cyphertext, (u64) cyphertextLength);
  if (cyphertext == NULL) {
    LOG_MALLOC_FAILURE();
    goto evpPkeyCtxFree; // return NULL
  }
  
  if (EVP_PKEY_encrypt(context, ustr(cyphertext), &cyphertextLength,
    ustr(data), length) <= 0
  ) {
    fprintf(stderr, "Could not encrypt data.\n");
    rsaPrintLastError();
    cyphertext = bytesDestroy(cyphertext);
    goto evpPkeyCtxFree; // return NULL
  }
  bytesSetLength(cyphertext, (u64) cyphertextLength);
  cyphertext[cyphertextLength] = '\0';
  
evpPkeyCtxFree:
  EVP_PKEY_CTX_free(context);
exit:
  return cyphertext;
}

/// @fn Bytes rsaDecrypt(const volatile void *data, u64 length, EVP_PKEY *pkey)
///
/// @brief Peform private key decryption on data of arbitrary length.
///
/// @param data The encrypted data to decrypt.
/// @param length The length of the data data.
/// @param pkey A pointer to a previously-initialized EVP_PKEY object.
///
/// @return Returns a Bytes object with the plaintext data on success, NULL on
/// failure.
Bytes rsaDecrypt(const volatile void *data, u64 length, EVP_PKEY *pkey) {
  Bytes plaintext = NULL;
  EVP_PKEY_CTX *context = NULL;
  size_t plaintextLength = 0;
  
  if (pkey == NULL) {
    fprintf(stderr, "Key not loaded.  Cannot decrypt.\n");
    goto exit; // return NULL
  }
  
  // Setup the context.
  context = EVP_PKEY_CTX_new(pkey, NULL);
  if (context == NULL) {
    fprintf(stderr, "Could not get key context.  Cannot decrypt.\n");
    rsaPrintLastError();
    goto exit; // return NULL
  } else if (EVP_PKEY_decrypt_init(context) <= 0) {
    fprintf(stderr,
      "Could not initialize decryption context.  Cannot decrypt.\n");
    rsaPrintLastError();
    goto evpPkeyCtxFree; // return NULL
  } else if (EVP_PKEY_CTX_set_rsa_padding(context, PADDING) <= 0) {
    fprintf(stderr,
      "Could not set padding on decryption context.  Cannot decrypt.\n");
    rsaPrintLastError();
    goto evpPkeyCtxFree; // return NULL
  }
  
  if (EVP_PKEY_decrypt(context, NULL, &plaintextLength,
    ustr(data), length) <= 0
  ) {
    fprintf(stderr,
      "Could not determine length of plaintext.  Cannot decrypt.\n");
    rsaPrintLastError();
    goto evpPkeyCtxFree; // return NULL
  }
  
  if (plaintextLength == 0) {
    fprintf(stderr, "Invalid cyphertext.  Cannot decrypt.\n");
    rsaPrintLastError();
    goto evpPkeyCtxFree; // return NULL
  }
  
  bytesAllocate(&plaintext, (u64) plaintextLength);
  if (plaintext == NULL) {
    LOG_MALLOC_FAILURE();
    goto evpPkeyCtxFree; // return NULL
  }
  
  if (EVP_PKEY_decrypt(context, ustr(plaintext), &plaintextLength,
    ustr(data), length) <= 0
  ) {
    fprintf(stderr, "Could not decrypt data.\n");
    rsaPrintLastError();
    plaintext = bytesDestroy(plaintext);
    goto evpPkeyCtxFree; // return NULL
  }
  bytesSetLength(plaintext, (u64) plaintextLength);
  plaintext[plaintextLength] = '\0';
  
evpPkeyCtxFree:
  EVP_PKEY_CTX_free(context);
exit:
  return plaintext;
}

/// @fn void rsaPrintLastError()
///
/// @brief Print the last error generated by the EVP_PKEY libraries.
///
/// @return This function returns no value.
void rsaPrintLastError() {
  char error[4096];
  ERR_load_crypto_strings();
  ERR_error_string(ERR_get_error(), error);
  fputs(error, stderr);
  fputs("\n", stderr);
}

