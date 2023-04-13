////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                     Copyright (c) 2012-2023 James Card                     //
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

EVP_PKEY *(*rsaLoadPublicKeyFromString)(const unsigned char *key)
  = rsaLoadKeyFromString;
EVP_PKEY *(*rsaLoadPrivateKeyFromString)(const unsigned char *key)
  = rsaLoadKeyFromString;

/// @fn EVP_PKEY *rsaLoadPublicKeyFromFile(const char *fileName)
///
/// @brief Load the public key that will be used by an instance of this
/// library from a file.
///
/// @param fileName The path to PEM-fomratted text representing the public key.
///
/// @return Returns an EVP_PKEY public key on success, NULL on failure.
EVP_PKEY *rsaLoadPublicKeyFromFile(const char *fileName) {
  Bytes key = getFileContent(fileName);
  bytesAddData(&key, "", 1); // Make a string from the bytes.
  EVP_PKEY *publicKey = rsaLoadPublicKeyFromString(ustr(key));
  key = bytesDestroy(key);
  return publicKey;
}

/// @fn int EVP_PKEY *rsaLoadPrivateKeyFromFile(const char *fileName)
///
/// @brief Load the private key that will be used by an instance of this
/// library.
///
/// @param fileName The path to PEM-fomratted text representing the private key.
///
/// @return Returns an EVP_PKEY private key on success, NULL on failure.
EVP_PKEY *rsaLoadPrivateKeyFromFile(const char *fileName) {
  Bytes key = getFileContent(fileName);
  bytesAddData(&key, "", 1); // Make a string from the bytes.
  EVP_PKEY *privateKey = rsaLoadPrivateKeyFromString(ustr(key));
  key = bytesDestroy(key);
  return privateKey;
}

/*******************************************************************************

/// @fn void *rsaEncrypt(void *data, u32 *length, EVP_PKEY *publicKey)
///
/// @brief Peform public key encryption on data of arbitrary length.
///
/// @param data The plaintext data to encrypt.
/// @param length The length of the plaintext data.
///
/// @return On success, a pointer to the cyphertext is returned and the value
/// of length is modified to reflect the size of the cyphertext.  On failure,
/// NULL is returned and the value of length is set to 0.
void *rsaEncrypt(void *data, u32 *length, EVP_PKEY *publicKey) {
  if (publicKey == NULL) {
    fprintf(stderr, "Key not loaded.  Cannot encrypt.\n");
    *length = 0;
    return NULL;
  }
  
  // Get an encryption engine to work with.
  ENGINE_load_builtin_engines();
  ENGINE *eng = ENGINE_get_first();
  if (eng == NULL) {
    fprintf(stderr, "Engine not loaded.  Cannot encrypt.\n");
    *length = 0;
    return NULL;
  } else if (!ENGINE_init(eng)) {
    fprintf(stderr, "Engine not initialized.  Cannot encrypt.\n");
    ENGINE_free(eng);
    *length = 0;
    return NULL;
  } else if (!ENGINE_set_default_RSA(eng)) {
    fprintf(stderr, "Could not set default RSA on engine.  Cannot encrypt.\n");
    ENGINE_finish(eng);
    ENGINE_free(eng);
    *length = 0;
    return NULL;
  }
  ENGINE_set_default_DSA(eng);
  ENGINE_set_default_ciphers(eng);
  
  // Setup the context.
  EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new(publicKey, eng);
  if (ctx == NULL) {
    fprintf(stderr, "Could not get key context.  Cannot encrypt.\n");
    ENGINE_finish(eng);
    ENGINE_free(eng);
    *length = 0;
    return NULL;
  } else if (EVP_PKEY_encrypt_init(ctx) <= 0) {
    fprintf(stderr,
      "Could not initialize encryption context.  Cannot encrypt.\n");
    EVP_PKEY_CTX_free(ctx);
    ENGINE_finish(eng);
    ENGINE_free(eng);
    *length = 0;
    return NULL;
  } else if (EVP_PKEY_CTX_set_rsa_padding(ctx, PADDING) <= 0) {
    fprintf(stderr,
      "Could not set padding on encryption context.  Cannot encrypt.\n");
    EVP_PKEY_CTX_free(ctx);
    ENGINE_finish(eng);
    ENGINE_free(eng);
    *length = 0;
    return NULL;
  }
  
  ZEROINIT(unsigned char buffer[RSA_LIB_BUFFER_SIZE]);
  int inputLength = *length;
  char *encryptedData = NULL;
  int outputLength = RSA_LIB_BUFFER_SIZE;
  int bytesEncrypted = 0;
  int returnValue = 0;
  while (inputLength > RSA_LIB_MAX_PLAINTEXT_SIZE) {
    returnValue = EVP_PKEY_encrypt(ctx, buffer, &outputLength,
      (unsigned char*) data, RSA_LIB_MAX_PLAINTEXT_SIZE);
    if (returnValue < 0) {
      fprintf(stderr, "Encrypt failed.\n");
      rsaPrintLastError();
      encryptedData = (char*) pointerDestroy(encryptedData);
      EVP_PKEY_CTX_free(ctx);
      ENGINE_finish(eng);
      ENGINE_free(eng);
      *length = 0;
      return NULL;
    }
    data = (void*) ((char*) data + RSA_LIB_MAX_PLAINTEXT_SIZE);
    inputLength -= RSA_LIB_MAX_PLAINTEXT_SIZE;
    dataAddData((void**) &encryptedData, outputLength, buffer, bytesEncrypted);
    outputLength += bytesEncrypted;
  }
  returnValue = EVP_PKEY_encrypt(ctx, buffer, &outputLength,
    (unsigned char*) data, RSA_LIB_MAX_PLAINTEXT_SIZE);
  if (returnValue < 0) {
    fprintf(stderr, "Encrypt failed.\n");
    rsaPrintLastError();
    encryptedData = (char*) pointerDestroy(encryptedData);
    EVP_PKEY_CTX_free(ctx);
    ENGINE_finish(eng);
    ENGINE_free(eng);
    *length = 0;
    return NULL;
  }
  dataAddData((void**) &encryptedData, outputLength, buffer, bytesEncrypted);
  outputLength += bytesEncrypted;
  
  EVP_PKEY_CTX_free(ctx);
  ENGINE_finish(eng);
  ENGINE_free(eng);
  *length = outputLength;
  return encryptedData;
}

void *(*rsaPublicEncrypt)(void *data, u32 *length, EVP_PKEY *publicKey)
  = rsaEncrypt;
void *(*rsaPrivateDecrypt)(void *data, u32 *length, EVP_PKEY *privateKey)
  = rsaEncrypt;

/// @fn void *rsaPrivateDecrypt(void *data, u32 *length, EVP_PKEY *privateKey)
///
/// @brief Peform private key decryption on data of arbitrary length.
///
/// @param data The cyphertext data to encrypt.
/// @param length The length of the cyphertext data.
///
/// @return On success, a pointer to the plaintext is returned and the value
/// of length is modified to reflect the size of the plaintext.  On failure,
/// NULL is returned and the value of length is set to 0.
void *rsaPrivateDecrypt(void *data, u32 *length, EVP_PKEY *privateKey) {
  if (privateKey == NULL) {
    fprintf(stderr, "Private key not loaded.  Cannot decrypt.\n");
    return NULL;
  }

  ZEROINIT(unsigned char buffer[RSA_LIB_BUFFER_SIZE]);
  int inputLength = *length;
  char *decryptedData = NULL;
  int outputLength = 0;
  int returnValue = 0;
  while (inputLength > RSA_LIB_BUFFER_SIZE) {
    returnValue = RSA_private_decrypt(RSA_LIB_BUFFER_SIZE, (unsigned char*) data, buffer, privateKey, PADDING);
    if (returnValue < 0) {
      fprintf(stderr, "Private decrypt failed.\n");
      rsaPrintLastError();
      decryptedData = (char*) pointerDestroy(decryptedData);
      *length = 0;
      return NULL;
    }
    data = (void*) ((char*) data + RSA_LIB_BUFFER_SIZE);
    inputLength -= RSA_LIB_BUFFER_SIZE;
    dataAddData((void**) &decryptedData, outputLength, buffer, returnValue);
    outputLength += returnValue;
  }
  returnValue = RSA_private_decrypt(inputLength, (unsigned char*) data, buffer, privateKey, PADDING);
  if (returnValue < 0) {
    fprintf(stderr, "Private decrypt failed.\n");
    rsaPrintLastError();
    decryptedData = (char*) pointerDestroy(decryptedData);
    *length = 0;
    return NULL;
  }
  dataAddData((void**) &decryptedData, outputLength, buffer, returnValue);
  outputLength += returnValue;
  
  *length = outputLength;
  return decryptedData;
}

/// @note Private key encryption only supports RSA_PKCS1_PADDING and
/// RSA_NO_PADDING.  RSA_NO_PADDING is insecure, so defautlting to
/// RSA_PKCS1_PADDING.

/// @fn void *rsaPrivateEncrypt(void *data, u32 *length, EVP_PKEY *privateKey)
///
/// @brief Peform private key encryption on data of arbitrary length.
///
/// @param data The plaintext data to encrypt.
/// @param length The length of the plaintext data.
///
/// @return On success, a pointer to the cyphertext is returned and the value
/// of length is modified to reflect the size of the cyphertext.  On failure,
/// NULL is returned and the value of length is set to 0.
void *rsaPrivateEncrypt(void *data, u32 *length, EVP_PKEY *privateKey) {
  if (privateKey == NULL) {
    fprintf(stderr, "Private key not loaded.  Cannot encrypt.\n");
    *length = 0;
    return NULL;
  }

  ZEROINIT(unsigned char buffer[RSA_LIB_BUFFER_SIZE]);
  int inputLength = *length;
  char *encryptedData = NULL;
  int outputLength = 0;
  int returnValue = 0;
  while (inputLength > RSA_LIB_MAX_PLAINTEXT_SIZE) {
    returnValue = RSA_private_encrypt(RSA_LIB_MAX_PLAINTEXT_SIZE, (unsigned char*) data, buffer, privateKey, RSA_PKCS1_PADDING);
    if (returnValue < 0) {
      fprintf(stderr, "Private encrypt failed.\n");
      rsaPrintLastError();
      encryptedData = (char*) pointerDestroy(encryptedData);
      *length = 0;
      return NULL;
    }
    data = (void*) ((char*) data + RSA_LIB_MAX_PLAINTEXT_SIZE);
    inputLength -= RSA_LIB_MAX_PLAINTEXT_SIZE;
    dataAddData((void**) &encryptedData, outputLength, buffer, returnValue);
    outputLength += returnValue;
  }
  returnValue = RSA_private_encrypt(inputLength, (unsigned char*) data, buffer, privateKey, RSA_PKCS1_PADDING);
  if (returnValue < 0) {
    fprintf(stderr, "Private encrypt failed.\n");
    rsaPrintLastError();
    encryptedData = (char*) pointerDestroy(encryptedData);
    *length = 0;
    return NULL;
  }
  dataAddData((void**) &encryptedData, outputLength, buffer, returnValue);
  outputLength += returnValue;
  
  *length = outputLength;
  return encryptedData;
}

/// @fn void *rsaPublicDecrypt(void *data, u32 *length, EVP_PKEY *publicKey)
///
/// @brief Peform public key decryption on data of arbitrary length.
///
/// @param data The cyphertext data to encrypt.
/// @param length The length of the cyphertext data.
///
/// @return On success, a pointer to the plaintext is returned and the value
/// of length is modified to reflect the size of the plaintext.  On failure,
/// NULL is returned and the value of length is set to 0.
void *rsaPublicDecrypt(void *data, u32 *length, EVP_PKEY *publicKey) {
  if (publicKey == NULL) {
    fprintf(stderr, "Public key not loaded.  Cannot decrypt.\n");
    return NULL;
  }

  ZEROINIT(unsigned char buffer[RSA_LIB_BUFFER_SIZE]);
  int inputLength = *length;
  char *decryptedData = NULL;
  int outputLength = 0;
  int returnValue = 0;
  while (inputLength > RSA_LIB_BUFFER_SIZE) {
    returnValue = RSA_public_decrypt(RSA_LIB_BUFFER_SIZE, (unsigned char*) data, buffer, publicKey, RSA_PKCS1_PADDING);
    if (returnValue < 0) {
      fprintf(stderr, "Public decrypt failed.\n");
      rsaPrintLastError();
      decryptedData = (char*) pointerDestroy(decryptedData);
      *length = 0;
      return NULL;
    }
    data = (void*) ((char*) data + RSA_LIB_BUFFER_SIZE);
    inputLength -= RSA_LIB_BUFFER_SIZE;
    dataAddData((void**) &decryptedData, outputLength, buffer, returnValue);
    outputLength += returnValue;
  }
  returnValue = RSA_public_decrypt(inputLength, (unsigned char*) data, buffer, publicKey, RSA_PKCS1_PADDING);
  if (returnValue < 0) {
    fprintf(stderr, "Public decrypt failed.\n");
    rsaPrintLastError();
    decryptedData = (char*) pointerDestroy(decryptedData);
    *length = 0;
    return NULL;
  }
  dataAddData((void**) &decryptedData, outputLength, buffer, returnValue);
  outputLength += returnValue;
  
  *length = outputLength;
  return decryptedData;
}

*******************************************************************************/

/// @fn void rsaPrintLastError()
///
/// @brief Print the last error generated by the EVP_PKEY libraries.
///
/// @return This function returns no value.
void rsaPrintLastError() {
  char *error = (char*) malloc(130);
  ERR_load_crypto_strings();
  ERR_error_string(ERR_get_error(), error);
  fprintf(stderr, "%s\n", error);
  error = stringDestroy(error);
}

