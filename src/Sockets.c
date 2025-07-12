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

#ifdef LOGGING_ENABLED
#include "LoggingLib.h"
#else
#undef printLog
#define printLog(...) {}
#define printStackTrace(...) {}
#define logFile stderr
#define LOG_MALLOC_FAILURE(...) {}
#endif

#include "Sockets.h"
#ifdef TLS_SOCKETS_ENABLED
#include "RsaLib.h"
#endif

const char *SocketTypeNames[NUM_SOCKET_TYPES] = {
  "SERVER",
  "CLIENT"
};

const char *SocketModeNames[NUM_SOCKET_MODES] = {
  "PLAIN",
  "TLS"
};

const char *SocketProtocolNames[NUM_SOCKET_PROTOCOLS] = {
  "TCP",
  "UDP"
};

/// @var rawSocketsInitialized
/// @brief State variable to track whehter or not this library has been
/// initialized.
static bool rawSocketsInitialized = false;

// Defined in other files.
extern const char *defaultSslKey;
extern const char *defaultSslCertificate;

/// @fn void updateSocketString(Socket *sock)
///
/// @brief Update the _str component of a Socket object with the string
/// representation of the socket.
///
/// @param sock The Socket to update.
///
/// @return This function returns no value.
void updateSocketString(Socket *sock) {
  if (sock->_str != NULL) {
    sock->_str = stringDestroy(sock->_str);
  }
  
  if (asprintf(&sock->_str,
    "Socket(%p) = {\n  socketType=%s\n  socketProtocol=%s\n  address=%s\n"
    "  socketMode=%s\n  blocking=%s\n  tcpConnected=%s\n  sockfd=%d\n"
    "  lock=%p\n"
#ifdef TLS_SOCKETS_ENABLED
    "  sslContext=%p\n  ssl=%p\n  sslBio=%p\n  sslAccepted=%s\n"
#endif
    "}",
    sock,
    SocketTypeNames[sock->socketType],
    SocketProtocolNames[sock->socketProtocol],
    sock->address,
    SocketModeNames[sock->socketMode],
    (sock->blocking == true) ? "true" : "false",
    (sock->tcpConnected== true) ? "true" : "false",
    sock->sockfd,
    &sock->lock
#ifdef TLS_SOCKETS_ENABLED
    ,sock->sslContext,
    sock->ssl,
    sock->sslBio,
    (sock->sslAccepted == true) ? "true" : "false"
#endif
    ) < 0
  ) {
    sock->_str = NULL;
  }
  
  return;
}

/// @fn int socketsMsleep(int milliseconds)
///
/// @brief Sleep for the specified number of milliseconds.
///
/// @param milliseconds The number of milliseconds to sleep.
///
/// @return Returns 0 on success, negative value on failure.
int socketsMsleep(int milliseconds) {
  int returnValue = 0;
  
#ifdef _WIN32
  Sleep(milliseconds);
#else // POSIX
  struct timespec sleepTime = {0, milliseconds * 1000000};
  returnValue = nanosleep(&sleepTime, NULL);
#endif
  
  return returnValue;
}

/// @fn int rawSocketsInit()
///
/// @brief Initialize sockets mechanisms.  This is a no-op on POSIX systems.
///
/// @return Returns 0 on success, negative error on failure.
int rawSocketsInit() {
  printLog(TRACE, "ENTER rawSocketsInit()\n");
  
  if (rawSocketsInitialized == false) {
#ifndef _WIN32
    // Ignore SIGPIPE errors.
    signal(SIGPIPE, SIG_IGN);
#endif
    
#ifdef _WIN32
    WSADATA wsaData = { 0 };
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        fprintf(logFile, "[ERROR] WSAStartup failed with error: %d\n", iResult);
        fflush(logFile);
        printLog(TRACE, "EXIT rawSocketsInit() = {-1}\n");
        return -1;
    }
#endif
  }
  rawSocketsInitialized = true;
  
  printLog(TRACE, "EXIT rawSocketsInit() = {0}\n");
  return 0;
}

/// @fn int socketSetNonblocking(Socket *sock)
///
/// @brief Put the specified socket in non-blocking mode.
///
/// @param socket The socket to put into non-blocking mode.
///
/// @return Returns NO_ERROR on success, error code on failure.
int socketSetNonblocking(Socket *sock) {
  printLog(FLOOD, "ENTER socketSetNonblocking(sock=%s)\n",
    socketToString(sock));
  
  if (sock == NULL) {
    printLog(ERR, "Socket provided is NULL.\n");
    printLog(FLOOD, "EXIT socketSetNonblocking(sock=%s) = {-1}\n",
      socketToString(sock));
    return -1;
  }
  
  if (sock->blocking == false) {
    printLog(DEBUG, "Socket is already non-blocking.  Doing nothing.\n");
    printLog(FLOOD, "EXIT socketSetNonblocking(sock=%s) = {0}\n",
      socketToString(sock));
    return 0;
  }
  
  int returnValue = 0;
  
  mtx_lock(&sock->lock);
#ifdef _WIN32
  u_long nonblocking = 1;
  returnValue = ioctlsocket(sock->sockfd, FIONBIO, &nonblocking);
#else // POSIX
  returnValue
    = fcntl(sock->sockfd, F_SETFL, fcntl(sock->sockfd, F_GETFL) | O_NONBLOCK);
#endif // _WIN32
  
  if (returnValue == NO_ERROR) {
    // Mark the socket as non-blocking.
    sock->blocking = false;
    updateSocketString(sock);
  } else {
    printLog(ERR, "Could not set socket to non-blocking mode.\n");
  }
  mtx_unlock(&sock->lock);
  
  printLog(FLOOD, "EXIT socketSetNonblocking(sock=%s) = {%d}\n",
    socketToString(sock), returnValue);
  return returnValue;
}

/// @fn int socketSetBlocking(Socket *sock)
///
/// @brief Put the specified socket in blocking mode.
///
/// @param socket The socket to put into blocking mode.
///
/// @return Returns NO_ERROR on success, error code on failure.
int socketSetBlocking(Socket *sock) {
  printLog(FLOOD, "ENTER socketSetBlocking(sock=%s)\n", socketToString(sock));
  
  if (sock == NULL) {
    printLog(ERR, "Socket provided is NULL.\n");
    printLog(FLOOD, "EXIT socketSetBlocking(sock=%s) = {-1}\n",
      socketToString(sock));
    return -1;
  }
  
  if (sock->blocking == true) {
    printLog(DEBUG, "Socket is already blocking.  Doing nothing.\n");
    printLog(FLOOD, "EXIT socketSetBlocking(sock=%s) = {0}\n",
      socketToString(sock));
    return 0;
  }
  
  int returnValue = 0;
  
  mtx_lock(&sock->lock);
#ifdef _WIN32
  u_long nonblocking = 0;
  returnValue = ioctlsocket(sock->sockfd, FIONBIO, &nonblocking);
#else // POSIX
  returnValue
    = fcntl(sock->sockfd, F_SETFL,
      fcntl(sock->sockfd, F_GETFL) & (~O_NONBLOCK));
#endif // _WIN32
  
  if (returnValue == NO_ERROR) {
    // Mark the socket as blocking.
    sock->blocking = true;
    updateSocketString(sock);
  } else {
    printLog(ERR, "Could not set socket to blocking mode.\n");
  }
  mtx_unlock(&sock->lock);
  
  printLog(FLOOD, "EXIT socketSetBlocking(sock=%s) = {%d}\n",
    socketToString(sock), returnValue);
  return returnValue;
}

/// @struct RawSocketConnectWatchArgs
/// @brief Arguments for the rawSocketConnectWatch thread.
/// @param sockfd The socket file descriptor to close if a connection isn't
///   established in a suitable amount of time.
/// @param connected A boolean to indicate whether or not the socket has been
///   connected on the main thread.
/// @param timeoutMilliseconds The number of milliseconds to wait before
///   forcibly closing the socket if it's not connected.
typedef struct RawSocketConnectWatchArgs {
  int sockfd;
  bool connected;
  int timeoutMilliseconds;
} RawSocketConnectWatchArgs;

/// @fn int rawSocketConnectWatch(void *args)
///
/// @brief Thread that watches for a connection to be established.  Forcibly
/// closes the socket for the connection if it doesn't connect by the specified
/// timeout.
///
/// @param args A pointer to a RawSocketConnectWatchArgs structure with the
///   parameters for this function.  The structure and any dynamic memory
///   associated with its parameters must be freed by this function (the thread
///   owns it).
///
/// @return Returns 0 on success, negative error code on failure.
int rawSocketConnectWatch(void *args) {
  RawSocketConnectWatchArgs *rawSocketConnectWatchArgs
    = (RawSocketConnectWatchArgs*) args;
  bool *connected = &rawSocketConnectWatchArgs->connected;
  int timeoutMilliseconds = rawSocketConnectWatchArgs->timeoutMilliseconds;
  int sockfd = rawSocketConnectWatchArgs->sockfd;
  printLog(TRACE,
    "ENTER rawSocketConnectWatch(sockfd=%d, connected=%s, "
      "timeoutMilliseconds=%d)\n",
    sockfd, (*connected == true) ? "true" : "false", timeoutMilliseconds);
  
  for (int i = 0; (i < timeoutMilliseconds) && (*connected == false); i++) {
    socketsMsleep(1);
  }
  
  int returnValue = 0;
  if (*connected == false) {
    printLog(WARN, "Connection timed out after %d milliseconds.\n",
      timeoutMilliseconds);
    rawSocketClose(sockfd);
    returnValue = -1;
  }
  
  bool connectedCopy = *connected;
  (void) connectedCopy; // In case logging isn't enabled.
  rawSocketConnectWatchArgs = NULL;
  
  printLog(TRACE,
    "EXIT rawSocketConnectWatch(sockfd=%d, connected=%s, "
      "timeoutMilliseconds=%d) = {%d}\n",
    sockfd, (connectedCopy == true) ? "true" : "false", timeoutMilliseconds,
    returnValue);
  return returnValue;
}

/// @fn int rawSocketConnect(int sockfd, const struct sockaddr *address, int addressLength, int timeoutMilliseconds)
///
/// @brief Connect a socket to an address within the specified timeout.  If
/// timeeoutSeconds is zero, block until connect would normally timeout.
///
/// @param sockfd The socket file descriptor to connect.
/// @param addr A sockaddr structure describing the address to connect to.
/// @param addressLength The size, in bytes, of the sockaddr pointed to by addr.
/// @param timeoutMilliseconds The number of milliseconds to wait for the
///   connection to be established before timing out.
///
/// @return Returns 0 on success, -1 on failure.
int rawSocketConnect(int sockfd, const struct sockaddr *address,
  int addressLength, int timeoutMilliseconds
) {
  printLog(TRACE,
    "ENTER rawSocketConnect(sockfd=%d, address=%p, addressLength=%d, "
    "timeoutMilliseconds=%d)\n", sockfd, address, addressLength,
    timeoutMilliseconds);
  
  ZEROINIT(thrd_t rawSocketConnectWatchThread);
  RawSocketConnectWatchArgs *rawSocketConnectWatchArgs = NULL;
  
  if (timeoutMilliseconds > 0) {
    rawSocketConnectWatchArgs
      = (RawSocketConnectWatchArgs*) malloc(sizeof(RawSocketConnectWatchArgs));
    if (rawSocketConnectWatchArgs == NULL) {
      // Out of memory.  Don't try to log our exit.
      return -1;
    }
    rawSocketConnectWatchArgs->sockfd = sockfd;
    rawSocketConnectWatchArgs->connected = false;
    rawSocketConnectWatchArgs->timeoutMilliseconds = timeoutMilliseconds;
    
    if (thrd_create(&rawSocketConnectWatchThread, rawSocketConnectWatch,
      (void*) rawSocketConnectWatchArgs) != thrd_success
    ) {
      // Starting the thread failed.  Free the memory it was supposed to free.
      rawSocketConnectWatchArgs = (RawSocketConnectWatchArgs*)
        pointerDestroy(rawSocketConnectWatchArgs);
    }
  }
  
  int returnValue = connect(sockfd, address, addressLength);
  if ((timeoutMilliseconds > 0) && (rawSocketConnectWatchArgs != NULL)) {
    rawSocketConnectWatchArgs->connected = true;
    // We don't actually need the return value of rawSocketConnectWatch.  If
    // it forcibly closes the socket, the return value of connect will be -1.
    // We can therefore skip the thrd_join and save ourselves time in the
    // success case, which is the expected normal case.
    thrd_join(rawSocketConnectWatchThread, NULL);
    rawSocketConnectWatchArgs = (RawSocketConnectWatchArgs*)
      pointerDestroy(rawSocketConnectWatchArgs);
  }
  
  if (returnValue < 0) {
    printLog(ERR, "%s", strerror(errno));
  }
  
  printLog(TRACE,
    "EXIT rawSocketConnect(sockfd=%d, address=%p, addressLength=%d, "
    "timeoutMilliseconds=%d) = {%d}\n",
    sockfd, address, addressLength, timeoutMilliseconds, returnValue);
  return returnValue;
}

#ifdef TLS_SOCKETS_ENABLED
/// @var _tlsSocketsEnabled
///
/// @brief State variable to keep track of whether or not we've already created
/// a TLS socket.  This will allow us to bypass any further SSL operations in
/// tlsSocketsEnabled.
static bool _tlsSocketsEnabled = false;
#endif

/// @fn bool tlsSocketsEnabled()
///
/// @brief Determine whether or not TLS sockets are enabled and operational.
///
/// @return Returns true if TLS sockets are compile-time enabled and runtime
/// operational, false otherwise.
bool tlsSocketsEnabled() {
  printLog(TRACE, "ENTER tlsSocketsEnabled()\n");
  
  bool returnValue = false;
  
#ifdef TLS_SOCKETS_ENABLED
  if (_tlsSocketsEnabled == true) {
    // This is the expected case.
    returnValue = true;
  } else {
    SSL_library_init();
    
    const SSL_METHOD *method = TLS_server_method();
    SSL_CTX *sslContext = SSL_CTX_new(method);
    if (sslContext != NULL) {
      returnValue = true;
      _tlsSocketsEnabled = true;
      SSL_CTX_free(sslContext); sslContext = NULL;
    }
  }
#endif
  
  printLog(TRACE, "EXIT tlsSocketsEnabled() = {%s}\n", boolNames[returnValue]);
  return returnValue;
}

#ifdef TLS_SOCKETS_ENABLED

/// @struct SslBioHandshakeWatchArgs
/// @brief Arguments for the sslBioHandshakeWatch thread.
/// @param sockfd The socket file descriptor to close if a connection isn't
///   established in a suitable amount of time.
/// @param connected A boolean to indicate whether or not the socket has been
///   connected on the main thread.
/// @param timeoutMilliseconds The number of seconds to wait before forcibly
///   closing the socket if it's not connected.
typedef struct SslBioHandshakeWatchArgs {
  BIO *bio;
  bool connected;
  int timeoutMilliseconds;
} SslBioHandshakeWatchArgs;

/// @fn int sslBioHandshakeWatch(void *args)
///
/// @brief Thread that watches for a connection to be established.  Forcibly
/// closes the SSL BIO for the connection if it doesn't connect by the specified
/// timeout.
///
/// @param args A pointer to a SslBioHandshakeWatchArgs structure with the
///   parameters for this function.  The structure and any dynamic memory
///   associated with its parameters must be freed by this function (the thread
///   owns it).
///
/// @return Returns 0 on success, negative error code on failure.
int sslBioHandshakeWatch(void *args) {
  SslBioHandshakeWatchArgs *sslBioSslBioHandshakeWatchArgs
    = (SslBioHandshakeWatchArgs*) args;
  bool *connected = &sslBioSslBioHandshakeWatchArgs->connected;
  int timeoutMilliseconds = sslBioSslBioHandshakeWatchArgs->timeoutMilliseconds;
  printLog(TRACE,
    "ENTER sslBioHandshakeWatch(bio=%p, connected=%s, timeoutMilliseconds=%d)\n",
    (void*) sslBioSslBioHandshakeWatchArgs->bio,
    (*connected == true) ? "true" : "false", timeoutMilliseconds);
  
  int returnValue = 0;
  if (timeoutMilliseconds < 0) {
    // Infinite timeout.  Just exit the thread gracefully.
    printLog(TRACE,
      "EXIT sslBioHandshakeWatch(bio=%p, connected=%s, timeoutMilliseconds=%d) "
        "= {%d}\n",
      (void*) sslBioSslBioHandshakeWatchArgs->bio,
      (*connected == true) ? "true" : "false",
      timeoutMilliseconds, returnValue);
    return returnValue;
  }
  
  for (int i = 0; (i < timeoutMilliseconds) && (*connected == false); i++) {
    socketsMsleep(1);
  }
  
  if (*connected == false) {
    printLog(WARN, "Connection timed out after %d milliseconds.\n",
      timeoutMilliseconds);
    if (sslBioSslBioHandshakeWatchArgs->bio != NULL) {
      int sockfd = BIO_get_fd(sslBioSslBioHandshakeWatchArgs->bio, NULL);
      rawSocketClose(sockfd);
    }
    returnValue = -1;
  }
  
  printLog(TRACE,
    "EXIT sslBioHandshakeWatch(bio=%p, connected=%s, timeoutMilliseconds=%d) = "
      "{%d}\n",
    (void*) sslBioSslBioHandshakeWatchArgs->bio,
    (*connected == true) ? "true" : "false",
    timeoutMilliseconds, returnValue);
  return returnValue;
}

// Internal support functions for socketCreate_.  socketCreate_ does full
// parameter checking, and these functions are only called from socketCreate_,
// so all parameters are guaranteed to be good.  No need to check again.

// SSL functions

/// @def MAX_SSL_ERROR_SIZE
///
/// @brief Maximum size, in bytes, to allocate for an SSL error message.
#define MAX_SSL_ERROR_SIZE 4096

/// @fn void sslGetLastError()
///
/// @brief Get the last error generated by the SSL libraries.
///
/// @return Returns a string with the last SSL error produced.
char* sslGetLastError() {
  printLog(TRACE, "ENTER sslGetLastError()\n");
  
  char *error = (char*) malloc(MAX_SSL_ERROR_SIZE);
  if (error != NULL) {
    ERR_load_crypto_strings();
    ERR_error_string(ERR_get_error(), error);
  }
  
  printLog(TRACE, "EXIT sslGetLastError()\n = {%s}", error);
  return error;
}

/// @fn int configureTlsServerSocket(Socket *sock, const char *certificate, const char *key)
///
/// @brief Configure a SERVER socket for use with TLS.
///
/// @param sock The Socket data structure to configure.
/// @param certificate The content of a PEM file for an X509 certificate.
/// @param key The content of a PEM file for an RSA private key.
///
/// @return Returns 0 on success, negative value on error.
int configureTlsServerSocket(Socket *sock,
  const char *certificate, const char *key
) {
  printLog(TRACE,
    "ENTER configureTlsServerSocket(sock=%s, certificate=%p, key=%p)\n",
    socketToString(sock), certificate, key);
  
  SSL_library_init();
  ////SSL_load_error_strings();
  ////OpenSSL_add_ssl_algorithms();
  
  if ((certificate == NULL) || (key == NULL)
    || (*certificate == '\0') || (*key == '\0')
  ) {
    certificate = defaultSslCertificate;
    key = defaultSslKey;
    printLog(DEBUG, "certificate = \"%s\"\n", certificate);
    printLog(DEBUG, "key = \"%s\"\n", key);
  }
  
  const SSL_METHOD *method = TLS_server_method();
  SSL_CTX *sslContext = SSL_CTX_new(method);
  if (sslContext == NULL) {
    // SSL is completely unconfigured, so we can't use sslGetLastError here.
    printLog(ERR, "Unable to create SSL context.\n");
    printLog(TRACE,
      "EXIT configureTlsServerSocket(sock=%s, certificate=%p, key=%p) = {%d}\n",
      socketToString(sock), certificate, key, -1);
    return -1;
  }
  
  SSL_CTX_set_ecdh_auto(sslContext, 1);
  
  // Set the cert
  BIO *bio = BIO_new_mem_buf((void*) certificate, -1);
  X509 *x509Cert = PEM_read_bio_X509(bio, NULL, 0, NULL);
  if (SSL_CTX_use_certificate(sslContext, x509Cert) <= 0) {
    char* error = sslGetLastError();
    printLog(ERR, "Unable to set certificate on context.\n");
    if (error != NULL) {
      printLog(ERR, "%s\n", error);
    }
    error = stringDestroy(error);
    X509_free(x509Cert); x509Cert = NULL;
    BIO_free(bio); bio = NULL;
    SSL_CTX_free(sslContext); sslContext = NULL;
    printLog(TRACE,
      "EXIT configureTlsServerSocket(sock=%s, certificate=%p, key=%p) = {%d}\n",
      socketToString(sock), certificate, key, -2);
    return -2;
  }
  X509_free(x509Cert); x509Cert = NULL;
  BIO_free(bio); bio = NULL;
  
  // Set the key
  EVP_PKEY *rsaKey = rsaLoadKeyFromString((unsigned char*) key);
  if (rsaKey == NULL) {
    char* error = sslGetLastError();
    printLog(ERR, "Unable to get rsaKey.\n");
    if (error != NULL) {
      printLog(ERR, "%s\n", error);
    }
    error = stringDestroy(error);
    SSL_CTX_free(sslContext); sslContext = NULL;
    printLog(TRACE,
      "EXIT configureTlsServerSocket(sock=%s, certificate=%p, key=%p) = {%d}\n",
      socketToString(sock), certificate, key, -3);
    return -3;
  }
  
  if (SSL_CTX_use_PrivateKey(sslContext, rsaKey) <= 0) {
    char* error = sslGetLastError();
    printLog(ERR, "Unable to set rsaKey on context.\n");
    if (error != NULL) {
      printLog(ERR, "%s\n", error);
    }
    error = stringDestroy(error);
    EVP_PKEY_free(rsaKey); rsaKey = NULL;
    SSL_CTX_free(sslContext); sslContext = NULL;
    printLog(TRACE,
      "EXIT configureTlsServerSocket(sock=%s, certificate=%p, key=%p) = {%d}\n",
      socketToString(sock), certificate, key, -3);
    return -4;
  }
  EVP_PKEY_free(rsaKey); rsaKey = NULL;
  
  sock->sslContext = sslContext;
  _tlsSocketsEnabled = true;
  
  printLog(TRACE,
    "EXIT configureTlsServerSocket(sock=%s, certificate=%p, key=%p) = {%d}\n",
    socketToString(sock), certificate, key, 0);
  return 0;
}

/// @fn bool tlsKeyAndCertificateValid(const char *certificate, const char *key)
///
/// @brief Determine if a certificate and key pair are valid.
///
/// @param certificate The content of a PEM file for an X509 certificate.
/// @param key The content of a PEM file for an RSA private key.
///
/// @return Returns true if the pair is valid, false if not.
bool tlsKeyAndCertificateValid(const char *certificate, const char *key) {
  printLog(TRACE,
    "ENTER tlsKeyAndCertificateValid(certificate=%p, key=%p)\n",
    certificate, key);
  
  bool returnValue = true;
  
  SSL_library_init();
  ////SSL_load_error_strings();
  ////OpenSSL_add_ssl_algorithms();
  
  if ((certificate == NULL) || (key == NULL)
    || (*certificate == '\0') || (*key == '\0')
  ) {
    printLog(ERR, "One or more missing parameters.\n");
    returnValue = false;
    printLog(TRACE,
      "EXIT tlsKeyAndCertificateValid(certificate=%p, key=%p) = {%s}\n",
      certificate, key, boolNames[returnValue]);
    return returnValue; // false
  }
  
  const SSL_METHOD *method = TLS_server_method();
  SSL_CTX *sslContext = SSL_CTX_new(method);
  if (sslContext == NULL) {
    // SSL is completely unconfigured, so we can't use sslGetLastError here.
    printLog(ERR, "Unable to create SSL context.\n");
    returnValue = false;
    printLog(TRACE,
      "EXIT tlsKeyAndCertificateValid(certificate=%p, key=%p) = {%s}\n",
      certificate, key, boolNames[returnValue]);
    return returnValue; // false
  }
  
  SSL_CTX_set_ecdh_auto(sslContext, 1);
  
  // Set the cert
  BIO *bio = BIO_new_mem_buf((void*) certificate, -1);
  X509 *x509Cert = PEM_read_bio_X509(bio, NULL, 0, NULL);
  if (SSL_CTX_use_certificate(sslContext, x509Cert) <= 0) {
    char* error = sslGetLastError();
    printLog(ERR, "Unable to set certificate on context.\n");
    if (error != NULL) {
      printLog(ERR, "%s\n", error);
    }
    error = stringDestroy(error);
    X509_free(x509Cert); x509Cert = NULL;
    BIO_free(bio); bio = NULL;
    SSL_CTX_free(sslContext); sslContext = NULL;
    returnValue = false;
    printLog(TRACE,
      "EXIT tlsKeyAndCertificateValid(certificate=%p, key=%p) = {%s}\n",
      certificate, key, boolNames[returnValue]);
    return returnValue; // false
  }
  X509_free(x509Cert); x509Cert = NULL;
  BIO_free(bio); bio = NULL;
  
  // Set the key
  EVP_PKEY *rsaKey = rsaLoadKeyFromString((unsigned char*) key);
  if (rsaKey == NULL) {
    char* error = sslGetLastError();
    printLog(ERR, "Unable to get rsaKey.\n");
    if (error != NULL) {
      printLog(ERR, "%s\n", error);
    }
    error = stringDestroy(error);
    SSL_CTX_free(sslContext); sslContext = NULL;
    returnValue = false;
    printLog(TRACE,
      "EXIT tlsKeyAndCertificateValid(certificate=%p, key=%p) = {%s}\n",
      certificate, key, boolNames[returnValue]);
    return returnValue; // false
  }
  
  if (SSL_CTX_use_PrivateKey(sslContext, rsaKey) <= 0) {
    char* error = sslGetLastError();
    printLog(ERR, "Unable to set rsaKey on context.\n");
    if (error != NULL) {
      printLog(ERR, "%s\n", error);
    }
    error = stringDestroy(error);
    EVP_PKEY_free(rsaKey); rsaKey = NULL;
    SSL_CTX_free(sslContext); sslContext = NULL;
    returnValue = false;
    printLog(TRACE,
      "EXIT tlsKeyAndCertificateValid(certificate=%p, key=%p) = {%s}\n",
      certificate, key, boolNames[returnValue]);
    return returnValue; // false
  }
  EVP_PKEY_free(rsaKey); rsaKey = NULL;
  SSL_CTX_free(sslContext); sslContext = NULL;
  
  _tlsSocketsEnabled = true;
  
  printLog(TRACE,
    "EXIT tlsKeyAndCertificateValid(certificate=%p, key=%p) = {%s}\n",
    certificate, key, boolNames[returnValue]);
  return returnValue; // true
}

#endif // TLS_SOCKETS_ENABLED

// SocketType helper functions.

/// @fn Socket* createServerSocket(SocketProtocol socketProtocol, const char *address, SocketMode socketMode, const char *certificate, const char *key)
///
/// @brief Create a server socket with the specified mode.
///
/// @param socketProtocol Either TCP or UDP.
/// @param address The IP address and port to listen on.
/// @param socketMode Either PLAIN or TLS.
/// @param certificate The content of a PEM file for an X509 certificate if
///   socketMode is SECURE, NULL otherwise.
/// @param key The content of a PEM file for an RSA private key if socketMode
///   is SECURE, NULL otherwise.
///
/// @return Returns a newly allocated and opened socket on success,
/// NULL on failure.
Socket* createServerSocket(SocketProtocol socketProtocol, const char *address,
  SocketMode socketMode, const char *certificate, const char *key
) {
  (void) certificate; // In case logging isn't enabled.
  (void) key; // In case logging isn't enabled.
  
  printLog(TRACE,
    "ENTER createServerSocket(socketProtocol=%s, address=%s, socketMode=%s, "
    "certificate=%p, key=%p)\n",
    (socketProtocol < NUM_SOCKET_PROTOCOLS) ?
      SocketProtocolNames[socketProtocol] : "UNKNOWN",
    address,
    (socketMode < NUM_SOCKET_MODES) ? SocketModeNames[socketMode] : "UNKNOWN",
    (void*) certificate, (void*) key);
  
  if (socketProtocol >= NUM_SOCKET_PROTOCOLS) {
    printLog(ERR, "Invalid socketProtocol %d.\n", socketProtocol);
    printLog(TRACE,
      "EXIT createServerSocket(socketProtocol=%s, address=%s, socketMode=%s, "
      "certificate=%p, key=%p) = {%p}\n",
      (socketProtocol < NUM_SOCKET_PROTOCOLS) ?
        SocketProtocolNames[socketProtocol] : "UNKNOWN",
      address,
      (socketMode < NUM_SOCKET_MODES) ? SocketModeNames[socketMode] : "UNKNOWN",
      (void*) certificate, (void*) key,
      (void*) NULL);
    return NULL;
  } else if (socketMode >= NUM_SOCKET_MODES) {
    printLog(ERR, "Invalid socketMode%d.\n", socketMode);
    printLog(TRACE,
      "EXIT createServerSocket(socketProtocol=%s, address=%s, socketMode=%s, "
      "certificate=%p, key=%p) = {%p}\n",
      (socketProtocol < NUM_SOCKET_PROTOCOLS) ?
        SocketProtocolNames[socketProtocol] : "UNKNOWN",
      address,
      (socketMode < NUM_SOCKET_MODES) ? SocketModeNames[socketMode] : "UNKNOWN",
      (void*) certificate, (void*) key,
      (void*) NULL);
    return NULL;
  }
  
  Socket *returnValue = (Socket*) calloc(1, sizeof(Socket));
  if (returnValue == NULL) {
    printLog(ERR, "Could not allocate memory for Socket.\n");
    printLog(TRACE,
      "EXIT createServerSocket(socketProtocol=%s, address=%s, socketMode=%s, "
      "certificate=%p, key=%p) = {%p}\n",
      SocketProtocolNames[socketProtocol],
      address,
      SocketModeNames[socketMode],
      (void*) certificate, (void*) key,
      (void*) NULL);
    return NULL;
  }
  if (mtx_init(&returnValue->lock, mtx_recursive) != thrd_success) {
    printLog(ERR, "Could initialize Socket lock.\n");
    returnValue = (Socket*) pointerDestroy(returnValue);
    printLog(TRACE,
      "EXIT createServerSocket(socketProtocol=%s, address=%s, socketMode=%s, "
      "certificate=%p, key=%p) = {%p}\n",
      SocketProtocolNames[socketProtocol],
      address,
      SocketModeNames[socketMode],
      (void*) certificate, (void*) key,
      (void*) NULL);
    return NULL;
  }
  
  returnValue->socketType = SERVER;
  returnValue->socketProtocol = socketProtocol;
  returnValue->socketMode = socketMode;
  returnValue->address = (char*) malloc(strlen(address) + 1);
  strcpy(returnValue->address, address);
  returnValue->blocking = true;
  
  int port = 0;
  char *portStart = strrchr(returnValue->address, ':');
  if (portStart != NULL) {
    *portStart = '\0';
    portStart++;
    port = strtol(portStart, NULL, 10);
  } else {
    // Default value.
    port = 80;
  }
  
  int sockfd = 0;
  int optionValue = 1;
  
  if (socketProtocol == TCP) {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char*) &optionValue,
      sizeof(optionValue)) < 0
    ) {
      printLog(WARN, "Could not set socket to allow for reusing address.\n");
    }
  } else if (socketProtocol == UDP) {
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  }
  
  if (sockfd < 0) {
    printLog(ERR, "Could not create socket file descriptor.\n");
    mtx_destroy(&returnValue->lock);
    returnValue->address = stringDestroy(returnValue->address);
    returnValue = (Socket*) pointerDestroy(returnValue);
    printLog(TRACE,
      "EXIT createServerSocket(socketProtocol=%s, address=%s, socketMode=%s, "
      "certificate=%p, key=%p) = {NULL}\n",
      SocketProtocolNames[socketProtocol],
      address,
      SocketModeNames[socketMode],
      (void*) certificate, (void*) key);
    return NULL;
  }
  returnValue->sockaddr.sin_family = AF_INET;
  returnValue->sockaddr.sin_addr.s_addr = inet_addr(returnValue->address);
  returnValue->sockaddr.sin_port = htons(port);
  
  if (bind(sockfd, (struct sockaddr *) &returnValue->sockaddr,
    sizeof(returnValue->sockaddr)) < 0
  ) {
    printLog(ERR, "Error binding socket.  (Are you root?)\n");
    mtx_destroy(&returnValue->lock);
    returnValue->address = stringDestroy(returnValue->address);
    returnValue = (Socket*) pointerDestroy(returnValue);
    printLog(TRACE,
      "EXIT createServerSocket(socketProtocol=%s, address=%s, socketMode=%s, "
      "certificate=%p, key=%p) = {NULL}\n",
      SocketProtocolNames[socketProtocol],
      address,
      SocketModeNames[socketMode],
      (void*) certificate, (void*) key);
    return NULL;
  }
  
  if (socketProtocol == TCP) {
    // Listen for client connections.
    listen(sockfd, SOMAXCONN);
  }
  
  returnValue->sockfd = sockfd;
  returnValue->blocking = true;
  
#ifdef TLS_SOCKETS_ENABLED
  if ((socketMode == TLS) && (tlsSocketsEnabled() == true)) {
    if (configureTlsServerSocket(returnValue, certificate, key) < 0) {
      printLog(ERR, "Could not configure socket for TLS.  Failing.\n");
      rawSocketClose(returnValue->sockfd);
      mtx_destroy(&returnValue->lock);
      returnValue->address = stringDestroy(returnValue->address);
      returnValue = (Socket*) pointerDestroy(returnValue);
      // certificate and key must be defined in this case, so changing the
      // printLog to print their contents instead of their pointer values here.
      // This may help catch situations when they're not defined but should be.
      printLog(TRACE,
        "EXIT createServerSocket(socketProtocol=%s, address=%s, socketMode=%s, "
        "certificate=%p, key=%p) = {NULL}\n",
        SocketProtocolNames[socketProtocol],
        address,
        SocketModeNames[socketMode],
        certificate, key);
      return NULL;
    }
    if (socketProtocol == UDP) {
      // In this case, there's no "accept" call.  We'll want to receive
      // directly from the server socket we just created.  Bind the SSL
      // data structures to that.
      returnValue->ssl = SSL_new(returnValue->sslContext);
      SSL_set_fd(returnValue->ssl, returnValue->sockfd);
    }
  } else if (socketMode == TLS) {
    returnValue->socketMode = PLAIN;
    printLog(WARN, "Local system does not support TLS.  Using plaintext.\n");
  }
#endif // TLS_SOCKETS_ENABLED
  
  // Return the socket's address to the full version with the port.
  returnValue->address = stringDestroy(returnValue->address);
  straddstr(&returnValue->address, address);
  
  printLog(TRACE,
    "EXIT createServerSocket(socketProtocol=%s, address=%s, socketMode=%s, "
    "certificate=%p, key=%p) = {%p}\n",
    SocketProtocolNames[socketProtocol],
    address,
    SocketModeNames[socketMode],
    (void*) certificate, (void*) key,
    (void*) returnValue);
  return returnValue;
}

#ifdef TLS_SOCKETS_ENABLED

/// @var clientSslInitialized
///
/// @brief Keep track of whether or not SSL is initialized for client sockets
/// so that we don't initialize repeatedly.
static bool clientSslInitialized = false;

/// @fn int configureTlsClientSocket(Socket *sock, int timeoutMilliseconds)
///
/// @brief Configure a client socket for use with TLS transport.
///
/// @param sock The Socket to configure.
/// @param timeoutMilliseconds The number of milliseconds before timing out when
///   trying to establish a connection.
///
/// @return Returns 0 on success, negative error code on failure.
int configureTlsClientSocket(Socket *sock, int timeoutMilliseconds) {
  // Can't use socketToString here because we're in the middle of creating
  // it and it's _str pointer hasn't been set yet.
  printLog(TRACE,
    "ENTER configureTlsClientSocket(sock=%p, timeoutMilliseconds=%d)\n",
    (void*) sock, timeoutMilliseconds);
  
  char *portStart = strrchr(sock->address, ':');
  if (portStart == NULL) {
    // Supply the default HTTP TLS port
    straddstr(&sock->address, ":443");
  }
  
  if (clientSslInitialized == false) {
    SSL_library_init();
    
    if (CONF_modules_load_file(NULL, NULL,
      CONF_MFLAGS_IGNORE_MISSING_FILE) <= 0
    ) {
      printLog(ERR, "CONF_modules_load_file failed.\n");
      char* error = sslGetLastError();
      if (error != NULL) {
        printLog(ERR, "%s\n", error);
      }
      error = stringDestroy(error);
      printLog(TRACE,
        "EXIT configureTlsClientSocket(sock=%p, timeoutMilliseconds=%d) "
        "= {-1}\n", (void*) sock, timeoutMilliseconds);
      return -1;
    }
    clientSslInitialized = true;
  }
  
  const SSL_METHOD* method = TLS_method();
  if (method == NULL) {
    printLog(ERR, "Could not get TLS method.\n");
    char* error = sslGetLastError();
    if (error != NULL) {
      printLog(ERR, "%s\n", error);
    }
    error = stringDestroy(error);
    printLog(TRACE,
      "EXIT configureTlsClientSocket(sock=%p, timeoutMilliseconds=%d) = {-2}\n",
      (void*) sock, timeoutMilliseconds);
    return -2;
  }
  
  SSL_CTX *sslContext = SSL_CTX_new(method);
  if (sslContext == NULL) {
    printLog(ERR, "Could not get SSL context.\n");
    char* error = sslGetLastError();
    if (error != NULL) {
      printLog(ERR, "%s\n", error);
    }
    error = stringDestroy(error);
    printLog(TRACE,
      "EXIT configureTlsClientSocket(sock=%p, timeoutMilliseconds=%d) = {-3}\n",
      (void*) sock, timeoutMilliseconds);
    return -3;
  }
  
  BIO *bio = NULL;
  if (sock->sockfd < 0) {
    // Create a new connection.  Use BIO_new_ssl_connect to create the BIO
    // chain automatically.
    bio = BIO_new_ssl_connect(sslContext);
    if (bio == NULL) {
      printLog(ERR, "Could not connect bio BIO to context.\n");
      char* error = sslGetLastError();
      if (error != NULL) {
        printLog(ERR, "%s\n", error);
      }
      error = stringDestroy(error);
      SSL_CTX_free(sslContext);
      printLog(TRACE,
        "EXIT configureTlsClientSocket(sock=%p, timeoutMilliseconds=%d) "
        "= {-4}\n",
        (void*) sock, timeoutMilliseconds);
      return -4;
    }
    
    if (BIO_set_conn_hostname(bio, sock->address) <= 0) {
      if (sock->ssl != NULL) {
        SSL_shutdown(sock->ssl);
        SSL_free(sock->ssl); sock->ssl = NULL;
      } else {
        BIO_free_all(bio); bio = NULL;
      }
      printLog(ERR, "Could not set BIO connection to %s.\n", sock->address);
      char* error = sslGetLastError();
      if (error != NULL) {
        printLog(ERR, "%s\n", error);
      }
      error = stringDestroy(error);
      SSL_CTX_free(sslContext);
      printLog(TRACE,
        "EXIT configureTlsClientSocket(sock=%p, timeoutMilliseconds=%d) "
        "= {-5}\n", (void*) sock, timeoutMilliseconds);
      return -5;
    }
  } else {
    // Convert the existing socket.  Create the BIO chain manually.
    BIO *socketBio = BIO_new_socket(sock->sockfd, BIO_NOCLOSE);
    if (socketBio == NULL) {
      printLog(ERR, "Could not connect bio BIO to socket.\n");
      char* error = sslGetLastError();
      if (error != NULL) {
        printLog(ERR, "%s\n", error);
      }
      error = stringDestroy(error);
      BIO_free_all(bio); bio = NULL;
      SSL_CTX_free(sslContext);
      printLog(TRACE,
        "EXIT configureTlsClientSocket(sock=%p, timeoutMilliseconds=%d) "
        "= {-4}\n", (void*) sock, timeoutMilliseconds);
      return -4;
    }
    // true sets the BIO to client mode.
    BIO_set_ssl_mode(socketBio, true);
    // No need to call BIO_set_conn_hostname since we're not establishing a
    // new connection.
    
    // true sets the BIO to client mode.
    BIO *sslBio = BIO_new_ssl(sslContext, true);
    if (sslBio == NULL) {
      printLog(ERR, "Could not connect bio BIO to socket.\n");
      char* error = sslGetLastError();
      if (error != NULL) {
        printLog(ERR, "%s\n", error);
      }
      error = stringDestroy(error);
      BIO_free_all(bio); bio = NULL;
      SSL_CTX_free(sslContext);
      printLog(TRACE,
        "EXIT configureTlsClientSocket(sock=%p, timeoutMilliseconds=%d) "
        "= {-4}\n", (void*) sock, timeoutMilliseconds);
      return -4;
    }
    bio = BIO_push(sslBio, socketBio);
  }
  SSL_CTX_free(sslContext);
  
  if (sock->socketProtocol == TCP) {
    SslBioHandshakeWatchArgs *sslBioHandshakeWatchArgs
      = (SslBioHandshakeWatchArgs*) malloc(sizeof(SslBioHandshakeWatchArgs));
    if (sslBioHandshakeWatchArgs == NULL) {
      // Out of memory.  Don't try to log our exit.
      return -6;
    }
    sslBioHandshakeWatchArgs->bio = bio;
    sslBioHandshakeWatchArgs->connected = false;
    sslBioHandshakeWatchArgs->timeoutMilliseconds = timeoutMilliseconds;
    
    ZEROINIT(thrd_t sslBioHandshakeWatchThread);
    thrd_create(&sslBioHandshakeWatchThread, sslBioHandshakeWatch,
      (void*) sslBioHandshakeWatchArgs);
    int threadReturnValue = 0;
    if (BIO_do_handshake(bio) <= 0) {
      sslBioHandshakeWatchArgs->bio = NULL;
      // This next line is so that we exit the loop in sslBioHandshakeWatch.
      sslBioHandshakeWatchArgs->connected = true;
      thrd_join(sslBioHandshakeWatchThread, &threadReturnValue);
      free(sslBioHandshakeWatchArgs); sslBioHandshakeWatchArgs = NULL;
      if (sock->ssl != NULL) {
        SSL_shutdown(sock->ssl);
        SSL_free(sock->ssl); sock->ssl = NULL;
      } else {
        BIO_free_all(bio); bio = NULL;
      }
      printLog(ERR, "Error connecting to server.\n");
      char* error = sslGetLastError();
      if (error != NULL) {
        printLog(ERR, "%s\n", error);
      }
      free(error); error = NULL;
      printLog(TRACE,
        "EXIT configureTlsClientSocket(sock=%p, timeoutMilliseconds=%d) "
        "= {-7}\n", (void*) sock, timeoutMilliseconds);
      return -7;
    }
    if (sslBioHandshakeWatchArgs != NULL) {
      sslBioHandshakeWatchArgs->connected = true;
      thrd_join(sslBioHandshakeWatchThread, &threadReturnValue);
      free(sslBioHandshakeWatchArgs); sslBioHandshakeWatchArgs = NULL;
    }
    
    sock->tcpConnected = true;
    sock->sslAccepted = true;
    printLog(DEBUG, "Successfully performed SSL handshake with the server.\n");
  }
  
  sock->sslBio = bio;
  sock->socketMode = TLS;
  updateSocketString(sock);
  _tlsSocketsEnabled = true;
  
  printLog(TRACE,
    "EXIT configureTlsClientSocket(sock=%p, timeoutMilliseconds=%d) = {0}\n",
    (void*) sock, timeoutMilliseconds);
  return 0;
}

#endif // TLS_SOCKETS_ENABLED

/// @fn Socket* createClientSocket(SocketProtocol socketProtocol, const char *address, SocketMode socketMode, int timeoutMilliseconds)
///
/// @brief Create a client socket and connect it to the specified address,
/// if appropriate.
///
/// @param socketProtocol Either TCP or UDP.
/// @param address The IP address and port to connect to.
/// @param socketMode Either PLAIN or TLS.
/// @param timeoutMilliseconds The number of milliseconds before timing out when
///   trying to establish a connection.
///
/// @return Returns a newly allocated and connected (if appropriate) socket
/// on success, NULL on failure.
Socket* createClientSocket(SocketProtocol socketProtocol, const char *address,
  SocketMode socketMode, int timeoutMilliseconds
) {
  printLog(TRACE,
    "ENTER createClientSocket(socketProtocol=%s, address=%s, socketMode=%s, "
    "timeoutMilliseconds=%d)\n", SocketProtocolNames[socketProtocol], address,
    SocketModeNames[socketMode], timeoutMilliseconds);
  
  if (socketProtocol >= NUM_SOCKET_PROTOCOLS) {
    printLog(ERR, "Invalid socketProtocol %d.\n", socketProtocol);
    printLog(TRACE,
      "EXIT createClientSocket(socketProtocol=%s, address=%s, socketMode=%s, "
      "timeoutMilliseconds=%d)  = {%p}\n",
      (socketProtocol < NUM_SOCKET_PROTOCOLS) ?
        SocketProtocolNames[socketProtocol] : "UNKNOWN",
      address,
      (socketMode < NUM_SOCKET_MODES) ? SocketModeNames[socketMode] : "UNKNOWN",
      timeoutMilliseconds,
      (void*) NULL);
    return NULL;
  } else if (socketMode >= NUM_SOCKET_MODES) {
    printLog(ERR, "Invalid socketMode%d.\n", socketMode);
    printLog(TRACE,
      "EXIT createClientSocket(socketProtocol=%s, address=%s, socketMode=%s, "
      "timeoutMilliseconds=%d)  = {%p}\n",
      (socketProtocol < NUM_SOCKET_PROTOCOLS) ?
        SocketProtocolNames[socketProtocol] : "UNKNOWN",
      address,
      (socketMode < NUM_SOCKET_MODES) ? SocketModeNames[socketMode] : "UNKNOWN",
      timeoutMilliseconds,
      (void*) NULL);
    return NULL;
  }
  
  Socket *returnValue = (Socket*) calloc(1, sizeof(Socket));
  if (returnValue == NULL) {
    printLog(ERR, "Could not allocate memory for Socket.\n");
    printLog(TRACE,
      "EXIT createClientSocket(socketProtocol=%s, address=%s, socketMode=%s, "
      "timeoutMilliseconds=%d) = {%p}\n",
      SocketProtocolNames[socketProtocol], address, SocketModeNames[socketMode],
      timeoutMilliseconds, (void*) NULL);
    return NULL;
  }
  if (mtx_init(&returnValue->lock, mtx_recursive) != thrd_success) {
    printLog(ERR, "Could initialize Socket lock.\n");
    free(returnValue); returnValue = NULL;
    printLog(TRACE,
      "EXIT createClientSocket(socketProtocol=%s, address=%s, socketMode=%s, "
      "timeoutMilliseconds=%d) = {%p}\n",
      SocketProtocolNames[socketProtocol], address, SocketModeNames[socketMode],
      timeoutMilliseconds, (void*) NULL);
    return NULL;
  }
  
  returnValue->socketType = CLIENT;
  returnValue->socketProtocol = socketProtocol;
  returnValue->socketMode = socketMode;
  // Address is NULL due to calloc above.
  straddstr(&returnValue->address, address); 
  
  if (returnValue->socketMode == PLAIN) {
    int port = 0;
    char *address = NULL; // Shadows parameter value.
    straddstr(&address, returnValue->address);
    char *portStart = strrchr(address, ':');
    if (portStart != NULL) {
      *portStart = '\0';
      portStart++;
      port = strtol(portStart, NULL, 10);
    } else {
      // Default value.
      port = 80;
    }
    getIpAddress(&address);
    
    int sockfd = 0;
    if (socketProtocol == TCP) {
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
    } else if (socketProtocol == UDP) {
      sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    }
    
    if (sockfd < 0) {
      printLog(ERR, "Could not create raw socket.\n");
      free(address); address = NULL;
      printLog(TRACE,
        "EXIT createClientSocket(socketProtocol=%s, address=%s, socketMode=%s, "
        "timeoutMilliseconds=%d) = {%p}\n",
        SocketProtocolNames[socketProtocol],
        returnValue->address,
        SocketModeNames[socketMode],
        timeoutMilliseconds,
        (void*) NULL);
      mtx_destroy(&returnValue->lock);
      free(returnValue->address); returnValue->address = NULL;
      free(returnValue); returnValue = NULL;
      return NULL;
    }
    printLog(DEBUG, "Socket created\n");
    
    returnValue->sockaddr.sin_addr.s_addr = inet_addr(address);
    returnValue->sockaddr.sin_family = AF_INET;
    returnValue->sockaddr.sin_port = htons(port);
    
    if (socketProtocol == TCP) {
      // Connect to remote host.
      if (rawSocketConnect(sockfd, (struct sockaddr*) &returnValue->sockaddr,
        // This value is too large to be practical.  It's set like this to allow
        // for this library to work when valgrind is in use.
        // WARNING: This is a magic number.  I really need to come up with a
        // better way to set this.
        // JBC 2021-06-02
        sizeof(returnValue->sockaddr), timeoutMilliseconds) < 0
      ) {
        printLog(ERR, "Connect to remote host failed.\n");
        rawSocketClose(sockfd);
        free(address); address = NULL;
        printLog(TRACE,
          "EXIT createClientSocket(socketProtocol=%s, address=%s, "
          "socketMode=%s, timeoutMilliseconds=%d) = {%p}\n",
          SocketProtocolNames[socketProtocol], returnValue->address,
          SocketModeNames[socketMode],
          timeoutMilliseconds,
          (void*) NULL);
        mtx_destroy(&returnValue->lock);
        free(returnValue->address); returnValue->address = NULL;
        free(returnValue); returnValue = NULL;
        return NULL;
      }
      returnValue->tcpConnected = true;
      printLog(DEBUG, "Connected\n");
    }
    returnValue->sockfd = sockfd;
    free(address); address = NULL;
  }
  
  returnValue->blocking = true;
  
#ifdef TLS_SOCKETS_ENABLED
  if ((returnValue->socketMode == TLS) && (tlsSocketsEnabled() == true)) {
    returnValue->sockfd = -1; // sockfd is not valid in this case
    if (configureTlsClientSocket(returnValue, timeoutMilliseconds) < 0) {
      printLog(ERR, "Could not configure client socket for TLS.\n");
      mtx_destroy(&returnValue->lock);
      free(returnValue->address); returnValue->address = NULL;
      free(returnValue); returnValue = NULL;
      printLog(TRACE,
        "EXIT createClientSocket(socketProtocol=%s, address=%s, socketMode=%s, "
        "timeoutMilliseconds=%d) = {%p}\n",
        SocketProtocolNames[socketProtocol],
        address,
        SocketModeNames[socketMode],
        timeoutMilliseconds,
       (void*) NULL);
      return returnValue;
    }
  } else if (returnValue->socketMode == TLS) {
    returnValue->socketMode = PLAIN;
    printLog(WARN, "Local system does not support TLS.  Using plaintext.\n");
  }
#endif // TLS_SOCKETS_ENABLED
  
  printLog(TRACE,
    "EXIT createClientSocket(socketProtocol=%s, address=%s, socketMode=%s, "
    "timeoutMilliseconds=%d) = {%p}\n",
    SocketProtocolNames[socketProtocol], address, SocketModeNames[socketMode],
      timeoutMilliseconds, (void*) returnValue);
  return returnValue;
}

/// @fn Socket* socketCreate_(SocketType socketType, SocketProtocol socketProtocol, const char *address, int socketMode, const char *certificate, const char *key, int timeoutMilliseconds, ...)
///
/// @brief Create a new socket for use.
///
/// @param socketType Either CLIENT or SERVER.
/// @param socketProtocol Either TCP or UDP.
/// @param address The IP address and port to connect to for a client or
///   to bind to for a server.
/// @param socketMode Either PLAIN or TLS.
/// @param certificate The content of a PEM file for an X509 certificate if
///   socketMode is SECURE, NULL otherwise.
/// @param key The content of a PEM file for an RSA private key if socketMode
///   is SECURE, NULL otherwise.
/// @param timeoutMilliseconds The number of milliseconds to wait before timing
///   out waiting for a client connection to be established.  A value of <= 0
///   will default to a 30 second timeout.
/// @param ... Any addtional parameters (provided by the wrapper macro) are
///   ignored.
///
/// @note This function is wrapped by the socketCreate macro which automatically
/// provides NULLs for the certificate ane key so that it is not necessary to
/// provide those parametrs if socketMode is PLAIN.  PLAIN is also the default
/// mode for sockets so it's not necessary to specify that parameter either.
///
/// @return Returns a new instance of a Socket type on success, NULL on failure.
Socket* socketCreate_(SocketType socketType, SocketProtocol socketProtocol,
  const char *address,
  int socketMode, const char *certificate, const char *key, int timeoutMilliseconds,
  ...
) {
  printLog(TRACE,
    "ENTER socketCreate(socketType=%s, socketProtocol=%s, address=%s, "
    "socketMode=%s, certificate=%p, key=%p, timeoutMilliseconds=%d)\n",
    (socketType >= NUM_SOCKET_TYPES) ?
      "UNKNOWN" : SocketTypeNames[socketType],
    (socketProtocol >= NUM_SOCKET_PROTOCOLS) ?
      "UNKNOWN" : SocketProtocolNames[socketProtocol],
    (address != NULL) ? address : "NULL",
    (socketMode >= NUM_SOCKET_MODES) ?
      "UNKNOWN" : SocketModeNames[socketMode],
    (void*) certificate, (void*) key, timeoutMilliseconds);
  
  if (rawSocketsInit() != 0) {
    printLog(ERR, "rawSocketsInit failed.  Cannot create socket.\n");
    printLog(TRACE,
      "EXIT socketCreate(socketType=%s, socketProtocol=%s, address=%s, "
      "socketMode=%s, certificate=%p, key=%p, timeoutMilliseconds=%d) = {%p}\n",
      (socketType >= NUM_SOCKET_TYPES) ?
        "UNKNOWN" : SocketTypeNames[socketType],
      (socketProtocol >= NUM_SOCKET_PROTOCOLS) ?
        "UNKNOWN" : SocketProtocolNames[socketProtocol],
      (address != NULL) ? address : "NULL",
      (socketMode >= NUM_SOCKET_MODES) ?
        "UNKNOWN" : SocketModeNames[socketMode],
      (void*) certificate, (void*) key, timeoutMilliseconds,
      (void*) NULL);
    return NULL;
  }
  
  if (socketType >= NUM_SOCKET_TYPES) {
    printLog(ERR,
      "Received unexpected socket type %d.  Only %d are supported.\n",
      socketType, NUM_SOCKET_TYPES);
    printLog(TRACE,
      "EXIT socketCreate(socketType=%s, socketProtocol=%s, address=%s, "
      "socketMode=%s, certificate=%p, key=%p, timeoutMilliseconds=%d) = {%p}\n",
      (socketType >= NUM_SOCKET_TYPES) ?
        "UNKNOWN" : SocketTypeNames[socketType],
      (socketProtocol >= NUM_SOCKET_PROTOCOLS) ?
        "UNKNOWN" : SocketProtocolNames[socketProtocol],
      (address != NULL) ? address : "NULL",
      (socketMode >= NUM_SOCKET_MODES) ?
        "UNKNOWN" : SocketModeNames[socketMode],
      (void*) certificate, (void*) key, timeoutMilliseconds,
      (void*) NULL);
    return NULL;
  }
  
  if (socketProtocol >= NUM_SOCKET_PROTOCOLS) {
    printLog(ERR,
      "Received unexpected socket protocol %d.  Only %d are supported.\n",
      socketProtocol, NUM_SOCKET_PROTOCOLS);
    printLog(TRACE,
      "EXIT socketCreate(socketType=%s, socketProtocol=%s, address=%s, "
      "socketMode=%s, certificate=%p, key=%p, timeoutMilliseconds=%d) = {%p}\n",
      (socketType >= NUM_SOCKET_TYPES) ?
        "UNKNOWN" : SocketTypeNames[socketType],
      (socketProtocol >= NUM_SOCKET_PROTOCOLS) ?
        "UNKNOWN" : SocketProtocolNames[socketProtocol],
      (address != NULL) ? address : "NULL",
      (socketMode >= NUM_SOCKET_MODES) ?
        "UNKNOWN" : SocketModeNames[socketMode],
      (void*) certificate, (void*) key, timeoutMilliseconds,
      (void*) NULL);
    return NULL;
  }
  
  if (socketMode >= NUM_SOCKET_MODES) {
    printLog(ERR,
      "Received unexpected security mode%d.  Only %d are supported.\n",
      socketMode, NUM_SOCKET_MODES);
    printLog(TRACE,
      "EXIT socketCreate(socketType=%s, socketProtocol=%s, address=%s, "
      "socketMode=%s, certificate=%p, key=%p, timeoutMilliseconds=%d) = {%p}\n",
      (socketType >= NUM_SOCKET_TYPES) ?
        "UNKNOWN" : SocketTypeNames[socketType],
      (socketProtocol >= NUM_SOCKET_PROTOCOLS) ?
        "UNKNOWN" : SocketProtocolNames[socketProtocol],
      (address != NULL) ? address : "NULL",
      (socketMode >= NUM_SOCKET_MODES) ?
        "UNKNOWN" : SocketModeNames[socketMode],
      (void*) certificate, (void*) key, timeoutMilliseconds,
      (void*) NULL);
    return NULL;
  }
  
  if (address == NULL) {
    printLog(ERR, "Address parameter is NULL.\n");
    printLog(TRACE,
      "EXIT socketCreate(socketType=%s, socketProtocol=%s, address=%s, "
      "socketMode=%s, certificate=%p, key=%p, timeoutMilliseconds=%d) = {%p}\n",
      (socketType >= NUM_SOCKET_TYPES) ?
        "UNKNOWN" : SocketTypeNames[socketType],
      (socketProtocol >= NUM_SOCKET_PROTOCOLS) ?
        "UNKNOWN" : SocketProtocolNames[socketProtocol],
      (address != NULL) ? address : "NULL",
      (socketMode >= NUM_SOCKET_MODES) ?
        "UNKNOWN" : SocketModeNames[socketMode],
      (void*) certificate, (void*) key, timeoutMilliseconds,
      (void*) NULL);
    return NULL;
  }
  
  Socket *socket = NULL;
  if (socketType == SERVER) {
    socket = createServerSocket(socketProtocol, address,
      (SocketMode) socketMode, certificate, key);
  } else if (socketType == CLIENT) {
    socket = createClientSocket(socketProtocol, address,
      (SocketMode) socketMode,
      // Default the timeout to 30 seconds if none was provided.
      // This value is too large to be practical.  It's set like this to allow
      // for this library to work when valgrind is in use.
      // WARNING: This is a magic number.  I really need to come up with a
      // better way to set this.
      // JBC 2021-06-02
      (timeoutMilliseconds == 0) ? 30000 : timeoutMilliseconds);
  }
  // No need for an else here since this value was already checked above.
  if (socket == NULL) {
    printLog(ERR, "Creating %s socket failed.\n", SocketTypeNames[socketType]);
    printLog(TRACE,
      "EXIT socketCreate(socketType=%s, socketProtocol=%s, address=%s, "
      "socketMode=%s, certificate=%p, key=%p, timeoutMilliseconds=%d) = {%p}\n",
      (socketType >= NUM_SOCKET_TYPES) ?
        "UNKNOWN" : SocketTypeNames[socketType],
      (socketProtocol >= NUM_SOCKET_PROTOCOLS) ?
        "UNKNOWN" : SocketProtocolNames[socketProtocol],
      (address != NULL) ? address : "NULL",
      (socketMode >= NUM_SOCKET_MODES) ?
        "UNKNOWN" : SocketModeNames[socketMode],
      (void*) certificate, (void*) key, timeoutMilliseconds,
      (void*) socket);
    return NULL;
  }
  
  // All fields are vaild.  Make a string representation of the Socket.
  updateSocketString(socket);
  
  // We don't need all the parameter checks and "UNKNOWN" here, but I'm lazy.
  printLog(TRACE,
    "EXIT socketCreate(socketType=%s, socketProtocol=%s, address=%s, "
    "socketMode=%s, certificate=%p, key=%p, timeoutMilliseconds=%d) = {%p}\n",
    (socketType >= NUM_SOCKET_TYPES) ?
      "UNKNOWN" : SocketTypeNames[socketType],
    (socketProtocol >= NUM_SOCKET_PROTOCOLS) ?
      "UNKNOWN" : SocketProtocolNames[socketProtocol],
    (address != NULL) ? address : "NULL",
    (socketMode >= NUM_SOCKET_MODES) ?
      "UNKNOWN" : SocketModeNames[socketMode],
    (void*) certificate, (void*) key, timeoutMilliseconds,
    (void*) socket);
  return socket;
}

/// @fn void getIpAddress(char **address)
///
/// @brief If the user provides us a host name then we need to convert it to an
/// IP address.  If the user provides an IP address then we leave the address
/// unchanged.
///
/// @param address is the address of the system to look up (either the IPv4 address
///   or the host name).  Buffer provided is modified in place.
///
/// @return This function returns no value.
void getIpAddress(char **address) {
  if (address == NULL) {
    // Nothing we can do.  We can't even print out the address intended.
    printLog(TRACE, "ENTER getIpAddress(address=NULL)\n");
    printLog(TRACE, "EXIT getIpAddress(address=NULL) = {}\n");
    return;
  }
  
  printLog(TRACE, "ENTER getIpAddress(*address=\"%s\")\n", *address);
  
  int byte1 = 0;
  int byte2 = 0;
  int byte3 = 0;
  int byte4 = 0;
  
  sscanf(*address, "%d.%d.%d.%d", &byte1, &byte2, &byte3, &byte4);
  char *ipAddress = NULL;
  if (asprintf(&ipAddress, "%d.%d.%d.%d", byte1, byte2, byte3, byte4) < 0) {
    printLog(ERR, "Cannot allocate memory for ipAddress.\n");
    printLog(TRACE, "EXIT getIpAddress(*address=\"%s\") = {}\n", *address);
    return;
  }
  if (strcmp(*address, ipAddress) == 0) {
    free(ipAddress); ipAddress = NULL;
    printLog(DEBUG, "IP address detected.  Changing nothing.\n");
    printLog(TRACE, "EXIT getIpAddress(*address=\"%s\") = {}\n", *address);
    return;
  } else {
    printLog(DEBUG, "Non-IP address detected.  Looking up host name.\n");
  }
  free(ipAddress); ipAddress = NULL;
  
  struct addrinfo *addressInfo = NULL;
  if (getaddrinfo(*address, NULL, NULL, &addressInfo) != 0) {
    printLog(WARN, "Could not get IP address for \"%s\"\n", *address);
    // Do not alter the address passed in.
    freeaddrinfo(addressInfo);
    printLog(TRACE, "EXIT getIpAddress(*address=\"%s\") = {}\n", *address);
    return;
  }
  
  if (addressInfo->ai_family == AF_INET) {
    struct sockaddr_in *ipv4Address
      = (struct sockaddr_in*) addressInfo->ai_addr;
    free(*address); *address = NULL;
    *address = (char*) malloc(strlen(inet_ntoa(ipv4Address->sin_addr)) + 1);
    strcpy(*address, inet_ntoa(ipv4Address->sin_addr));
  /*
   * } else if (addressInfo->ai_family == AF_INET6) {
   *   struct sockaddr_in6 *ipv6Address
   *     = (struct sockaddr_in6*) addressInfo->ai_addr;
   *   // Convert the address to it's IPV6 string representation.
   */
  } else {
    printLog(ERR, "Could not get address for \"%s\"\n", *address);
    // Do not alter the address passed in.
  }
  freeaddrinfo(addressInfo);
  
  printLog(TRACE, "EXIT getIpAddress(*address=\"%s\") = {}\n", *address);
  return;
}

/// @fn size_t getAddressSize(const char *address)
///
/// @brief Get the size, in bits, of an IP address (32 for IPv4, 128 for IPv6).
///
/// @param address The IP address to check.
///
/// @return Returns a size_t with the size, in bits, of the address.
size_t getAddressSize(const char *address) {
  printLog(TRACE, "ENTER getAddressSize(address=%s)\n", strOrNull(address));
  
  size_t numAddressBits = 0;
  
  if (address == NULL) {
    // No address.  Nothing we can do.
    printLog(TRACE, "EXIT getAddressSize(address=NULL) = {0}\n");
    return numAddressBits;
  }
  
  int byte1 = 0;
  int byte2 = 0;
  int byte3 = 0;
  int byte4 = 0;
  
  numAddressBits = 128;
  if (sscanf(address, "%d.%d.%d.%d", &byte1, &byte2, &byte3, &byte4) == 4) {
    numAddressBits = 32;
  }
  
  printLog(TRACE, "EXIT getAddressSize(address=\"%s\") = {%llu}\n",
    address, llu(numAddressBits));
  return numAddressBits;
}

/// @fn char *getNetworkAddress(const char *ipAddress, size_t numFixedBits)
///
/// @brief Make an address netmask given an IP address in string form and the
/// number of fixed bits in the address.
///
/// @param ipAddress An IPv4 or IPv6 address in string form.
/// @param numFixedBits The number of fixed bits in the address.
///
/// @note IPv6 is not yet supported by this function.
///
/// @return Returns a string representation of the network's address.
char *getNetworkAddress(const char *ipAddress, size_t numFixedBits) {
  printLog(TRACE, "ENTER getNetworkAddress(ipAddress=%s, numFixedBits=%llu)\n",
    strOrNull(ipAddress), llu(numFixedBits));
  
  char *netmask = NULL;
  if (ipAddress == NULL) {
    // No ipAddress.  Nothing we can do.
    straddstr(&netmask, "");
    printLog(TRACE,
      "EXIT getNetworkAddress(ipAddress=%s, numFixedBits=%llu) = {%s}\n",
      strOrNull(ipAddress), llu(numFixedBits), netmask);
    return netmask;
  }
  
  size_t addressSize = getAddressSize(ipAddress);
  if (addressSize == 0) {
    printLog(ERR, "Could not determine size of address \"%s\".\n", ipAddress);
    straddstr(&netmask, "");
    printLog(TRACE,
      "EXIT getNetworkAddress(ipAddress=%s, numFixedBits=%llu) = {%s}\n",
      strOrNull(ipAddress), llu(numFixedBits), netmask);
    return netmask;
  } else if (numFixedBits > addressSize) {
    printLog(ERR,
      "Number of requested fixed bits %llu is larger than address size %llu.\n",
      llu(numFixedBits), llu(addressSize));
    straddstr(&netmask, "");
    printLog(TRACE,
      "EXIT getNetworkAddress(ipAddress=%s, numFixedBits=%llu) = {%s}\n",
      strOrNull(ipAddress), llu(numFixedBits), netmask);
    return netmask;
  } else if (addressSize == 128) {
    printLog(ERR,
      "IPv6 addresses are not currently supported by this function.\n");
    straddstr(&netmask, "");
    printLog(TRACE,
      "EXIT getNetworkAddress(ipAddress=%s, numFixedBits=%llu) = {%s}\n",
      strOrNull(ipAddress), llu(numFixedBits), netmask);
    return netmask;
  }
  
  // OK.  We have a usable IPv4 network address.  Make the network address.
  // First, parse the address into a 32-bit number.
  uint32_t addressBytes[4];
  if (sscanf(ipAddress, "%u.%u.%u.%u",
    &addressBytes[0], &addressBytes[1], &addressBytes[2], &addressBytes[3])
    != 4
  ) {
    printLog(ERR, "Could not parse IP address \"%s\".\n", ipAddress);
    straddstr(&netmask, "");
    printLog(TRACE,
      "EXIT getNetworkAddress(ipAddress=%s, numFixedBits=%llu) = {%s}\n",
      strOrNull(ipAddress), llu(numFixedBits), netmask);
    return netmask;
  }
  uint32_t addressInt
    = (addressBytes[0] << 24)
    | (addressBytes[1] << 16)
    | (addressBytes[2] <<  8)
    | (addressBytes[3] <<  0);
  uint32_t netmaskInt = 0xffffffff << (32 - numFixedBits);
  addressInt &= netmaskInt;
  addressBytes[0] = (addressInt & 0xff000000) >> 24;
  addressBytes[1] = (addressInt & 0x00ff0000) >> 16;
  addressBytes[2] = (addressInt & 0x0000ff00) >>  8;
  addressBytes[3] = (addressInt & 0x000000ff) >>  0;
  
  (void) asprintf(&netmask, "%u.%u.%u.%u/%llu",
    addressBytes[0], addressBytes[1], addressBytes[2], addressBytes[3],
    llu(numFixedBits));
  
  printLog(TRACE,
    "EXIT getNetworkAddress(ipAddress=%s, numFixedBits=%llu) = {%s}\n",
    strOrNull(ipAddress), llu(numFixedBits), netmask);
  return netmask;
}

/// @fn Socket* socketDestroy(Socket *sock)
///
/// @brief Close and deallocate the relevant portions of a Socket data
/// structure.  Free the Socket itself and return NULL.
///
/// @param sock The Socket to close and deallocate.
///
/// @return This function always returns NULL.
Socket* socketDestroy(Socket *sock) {
  printLog(TRACE, "ENTER socketDestroy(sock=%s)\n", socketToString(sock));
  
  if (sock == NULL) {
    // Nothing to do.
    printLog(TRACE, "EXIT socketDestroy(sock=NULL) = {NULL}\n");
    return NULL;
  }
  
#ifdef TLS_SOCKETS_ENABLED
  if (sock->socketMode == TLS) {
    if (sock->ssl != NULL) {
      SSL_shutdown(sock->ssl);
      SSL_free(sock->ssl); sock->ssl = NULL;
      // If there was also a BIO associated with this socket, it was freed by
      // SSL_free.
      sock->sslBio = NULL;
    }
    if (sock->sslContext != NULL) {
      SSL_CTX_free(sock->sslContext); sock->sslContext = NULL;
    }
    if (sock->sslBio != NULL) {
      BIO_free_all(sock->sslBio); sock->sslBio = NULL;
    }
  }
#endif // TLS_SOCKETS_ENABLED
  
  if (sock->sockfd > -1) {
    rawSocketClose(sock->sockfd);
  }
  mtx_destroy(&sock->lock);
  free(sock->address); sock->address = NULL;
  free(sock->_str); sock->_str = NULL;
  free(sock); sock = NULL;
  
  printLog(TRACE, "EXIT socketDestroy(sock=%p) = {NULL}\n", (void*) sock);
  return NULL;
}

/// @fn int socketSend(Socket *sock, const volatile void *buf, int len)
///
/// @brief Send the provided data to the specified socket.
///
/// @param sock The Socket created by a prior call to socketCreate.
/// @param buf A pointer to the buffer to send.
/// @param len The length, in bytes, of the data pointed to by buf.
///
/// @return Returns the number of bytes sent on success,
/// negative value on error.
int socketSend(Socket *sock, const volatile void *buf, int len) {
  printLog(TRACE, "ENTER socketSend(sock=%s, buf=%p, len=%d)\n",
    socketToString(sock), (void*) buf, len);
  
  int returnValue = 0;
  ssize_t bytesSent = 0, totalBytesSent = 0;
  const char *bufferPointer = (const char*) buf;
  int flags = 0;
#ifndef _WIN32
  // Ignore sigpipe errors on the POSIX send command
  flags = MSG_NOSIGNAL;
#endif
  
  if (sock == NULL) {
    printLog(ERR, "NULL Socket provided.\n");
    printLog(TRACE, "EXIT socketSend(sock=NULL, buf=%p, len=%d) = {%d}\n",
      (void*) buf, len, -1);
    return -1;
  }
  
  if (buf == NULL) {
    printLog(ERR, "NULL buf pointer provided.\n");
    printLog(TRACE, "EXIT socketSend(sock=%s, buf=%p, len=%d) = {%d}\n",
      socketToString(sock), (void*) buf, len, -1);
    return -1;
  }
  
  bool wasBlocking = sock->blocking;
  // Put the socket in blocking mode:
  if (socketSetBlocking(sock) != NO_ERROR) {
    printLog(ERR, "Could not put socket in blocking mode.\n");
  }
  
  mtx_lock(&sock->lock);
  if ((sock->socketProtocol == TCP) && (sock->tcpConnected == true)) {
    while (len > 0) {
        if (sock->socketMode == PLAIN) {
          bytesSent = send(sock->sockfd, bufferPointer, len, flags);
#ifdef TLS_SOCKETS_ENABLED
        } else if ((sock->socketMode == TLS)
          && (sock->socketType == CLIENT) && (sock->sslBio != NULL)
        ) {
          bytesSent = BIO_write(sock->sslBio, bufferPointer, len);
          printLog(DEBUG, "Sent %llu Bytes over BIO.\n", llu(bytesSent));
        } else if ((sock->socketMode == TLS)
          && (sock->socketType == SERVER) && (sock->ssl != NULL)
        ) {
          bytesSent = SSL_write(sock->ssl, bufferPointer, len);
          printLog(DEBUG, "Sent %llu Bytes over SSL.\n", llu(bytesSent));
#endif // TLS_SOCKETS_ENABLED
        } else {
          // Invalid state of socket.
          printLog(ERR, "Invalid socket in socketSend.\n");
          printLog(ERR, "%s\n", socketToString(sock));
          bytesSent = -1;
        }
        if (bytesSent <= 0) {
          break;
        }
        totalBytesSent += bytesSent;
        bufferPointer += bytesSent;
        len -= bytesSent;
    }
  } else if (sock->socketProtocol == UDP) {
    while (len > 0) {
        if (sock->socketMode == PLAIN) {
          bytesSent = sendto(sock->sockfd, bufferPointer, len, flags,
            (struct sockaddr*) &sock->sockaddr, sizeof(sock->sockaddr));
        } else {
          // Invalid state of socket.
          printLog(ERR, "Invalid socket in socketSend.\n");
          printLog(ERR, "%s\n", socketToString(sock));
          bytesSent = -1;
        }
        if (bytesSent <= 0) {
          break;
        }
        totalBytesSent += bytesSent;
        bufferPointer += bytesSent;
        len -= bytesSent;
    }
  }
  mtx_unlock(&sock->lock);
  
  if (bytesSent > 0) {
    // The expected case.
    returnValue = (int) totalBytesSent;
  } else {
    // Error case.
    if (totalBytesSent > 0) {
      // Indicate partial send.
      returnValue = (int) totalBytesSent;
    } else {
      // Indicate send failure.
      returnValue = -1;
    }
    if ((bytesSent < 0) && (sock->socketProtocol == TCP)) {
      // bytesSent < 0, so we got a send error.  There is a problem with
      // the socket.
      sock->tcpConnected = false;
      // Close the socket to force any in-progress recvs to exit.
      rawSocketClose(sock->sockfd);
      sock->sockfd = -1;
      updateSocketString(sock);
    }
  }
  
  if (wasBlocking == false) {
    if (socketSetNonblocking(sock) != NO_ERROR) {
      printLog(ERR, "Could not return socket to non-blocking mode.\n");
    }
  }
  
  printLog(TRACE, "EXIT socketSend(sock=%s, buf=%p, len=%d) = {%d}\n",
    socketToString(sock), (void*) buf, len, returnValue);
  return returnValue;
}

/// @struct SslAcceptWatchArgs
/// @brief Arguments for the sslAcceptWatch thread.
/// @param sockfd The socket file descriptor to close if a connection isn't
///   established in a suitable amount of time.
/// @param accepted A boolean to indicate whether or not the socket has been
///   accepted on the main thread.
/// @param timeoutMilliseconds The number of milliseconds to wait before
///   forcibly closing the socket if it's not accepted.
typedef struct SslAcceptWatchArgs {
  int sockfd;
  bool accepted;
  int timeoutMilliseconds;
} SslAcceptWatchArgs;

/// @fn int sslAcceptWatch(void *args)
///
/// @brief Thread that watches for a connection to be established.  Forcibly
/// closes the socket for the connection if it doesn't connect by the specified
/// timeout.
///
/// @param args A pointer to a SslAcceptWatchArgs structure with the
///   parameters for this function.  The structure and any dynamic memory
///   associated with its parameters must be freed by this function (the thread
///   owns it).
///
/// @return Returns 0 on success, negative error code on failure.
int sslAcceptWatch(void *args) {
  SslAcceptWatchArgs *sslAcceptWatchArgs = (SslAcceptWatchArgs*) args;
  bool *accepted = &sslAcceptWatchArgs->accepted;
  int timeoutMilliseconds = sslAcceptWatchArgs->timeoutMilliseconds;
  int sockfd = sslAcceptWatchArgs->sockfd;
  printLog(TRACE,
    "ENTER sslAcceptWatch(sockfd=%d, accepted=%s, timeoutMilliseconds=%d)\n",
    sockfd, (*accepted == true) ? "true" : "false", timeoutMilliseconds);
  
  for (int i = 0; (i < timeoutMilliseconds) && (*accepted == false); i++) {
    socketsMsleep(1);
  }
  
  int returnValue = 0;
  if (*accepted == false) {
    printLog(WARN, "Connection timed out after %d milliseconds.\n",
      timeoutMilliseconds);
    rawSocketClose(sockfd);
    returnValue = -1;
  }
  
  bool acceptedCopy = *accepted;
  (void) acceptedCopy; // In case logging isn't enabled.
  free(args); args = NULL; sslAcceptWatchArgs = NULL;
  
  printLog(TRACE,
    "EXIT sslAcceptWatch(sockfd=%d, accepted=%s, timeoutMilliseconds=%d) "
      "= {%d}\n",
    sockfd, (acceptedCopy == true) ? "true" : "false", timeoutMilliseconds,
    returnValue);
  return returnValue;
}

/// @fn int socketReceive_(Socket *sock, volatile void *buf, int len, int timeout, ...)
///
/// @brief Send the provided data to the specified socket.
///
/// @param sock The Socket created by a prior call to socketCreate.
/// @param buf A pointer to the buffer to receive data into.
/// @param len The length, in bytes, of the buffer pointed to by buf.
/// @param timeoutMilliseconds The number of milliseconds to wait before
///   returning if the socket is blocking.  If the socket is blocking and this
///   value is -1, this funciton blocks indefinitely.  If the socket is
///   non-blocking, this value is ignored.
///
/// @return Returns the number of bytes received on success,
/// negative value on error.
int socketReceive_(Socket *sock, volatile void *buf, int len,
  int timeoutMilliseconds, ...
) {
  printLog(FLOOD,
    "ENTER socketReceive(sock=%s, buf=%p, len=%d, timeoutMilliseconds=%d)\n",
    socketToString(sock), (void*) buf, len, timeoutMilliseconds);
  
  if (sock == NULL) {
    printLog(ERR, "NULL Socket provided.\n");
    printLog(FLOOD,
      "EXIT socketReceive(sock=NULL, buf=%p, len=%d, "
      "timeoutMilliseconds=%d) = {%d}\n",
      (void*) buf, len, timeoutMilliseconds, -1);
    return -1;
  }
  
  if (buf == NULL) {
    printLog(ERR, "NULL buf pointer provided.\n");
    printLog(FLOOD,
      "EXIT socketReceive(sock=%s, buf=%p, len=%d, "
      "timeoutMilliseconds=%d) = {%d}\n",
      socketToString(sock), (void*) buf, len, timeoutMilliseconds, -1);
    return -1;
  }
  
  bool socketWasBlocking = sock->blocking;
  
#ifdef TLS_SOCKETS_ENABLED
  if ((sock->socketMode == TLS) && (sock->sslAccepted == false)
    && (sock->ssl != NULL)
  ) {
    // We haven't gone through the TLS accept and handshake.  Complete the
    // process.
    if (socketWasBlocking == false) {
      socketSetBlocking(sock);
    }
#ifdef _WIN32
    DWORD timeout = 0;
#else // POSIX
    ZEROINIT(struct timeval timeout);
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;
#endif // _WIN32
    // Set our timeout to infinite
    if (setsockopt(sock->sockfd, SOL_SOCKET, SO_RCVTIMEO, (char*) &timeout,
      sizeof(timeout)) < 0
    ) {
      printLog(WARN,
        "Could not set timeout for blocking socket to infinite.\n");
    }
    
    SslAcceptWatchArgs *sslAcceptWatchArgs
      = (SslAcceptWatchArgs*) malloc(sizeof(SslAcceptWatchArgs));
    if (sslAcceptWatchArgs == NULL) {
      // Out of memory.
      SSL_shutdown(sock->ssl);
      SSL_free(sock->ssl); sock->ssl = NULL;
      rawSocketClose(sock->sockfd); sock->sockfd = -1;
      if (socketWasBlocking == false) {
        socketSetNonblocking(sock);
      }
      updateSocketString(sock);
      printLog(FLOOD,
        "EXIT socketReceive(sock=%s, buf=%p, len=%d, "
        "timeoutMilliseconds=%d) = {-1}\n",
        socketToString(sock), (void*) buf, len, timeoutMilliseconds);
      return -1;
    }
    sslAcceptWatchArgs->sockfd = sock->sockfd;
    sslAcceptWatchArgs->accepted = false;
    // This value is too large to be practical.  It's set like this to allow
    // for this library to work when valgrind is in use.
    // WARNING: This is a magic number.  I really need to come up with a
    // better way to set this.
    // JBC 2021-06-02
    sslAcceptWatchArgs->timeoutMilliseconds = 15000;
    
    ZEROINIT(thrd_t sslAcceptThread);
    if (thrd_create(&sslAcceptThread, sslAcceptWatch,
      (void*) sslAcceptWatchArgs) == thrd_success
    ) {
      // We don't actually need the return value of sslAccept.  If
      // it forcibly closes the socket, the return value of SSL_accept will be
      // -1. We can therefore skip the thrd_join and save ourselves time in the
      // success case, which is the expected normal case.
      thrd_detach(sslAcceptThread);
    } else {
      // Starting the thread failed.  Free the memory it was supposed to free.
      printLog(WARN, "Could not start sslAcceptWatch thread.\n");
      free(sslAcceptWatchArgs); sslAcceptWatchArgs = NULL;
    }
    if (SSL_accept(sock->ssl) <= 0) {
      printLog(ERR, "Could not accept from SSL.\n");
      char* error = sslGetLastError();
      if (error != NULL) {
        printLog(ERR, "%s\n", error);
      }
      free(error); error = NULL;
      SSL_shutdown(sock->ssl);
      SSL_free(sock->ssl); sock->ssl = NULL;
      rawSocketClose(sock->sockfd); sock->sockfd = -1;
      if (socketWasBlocking == false) {
        socketSetNonblocking(sock);
      }
      updateSocketString(sock);
      printLog(FLOOD,
        "EXIT socketReceive(sock=%s, buf=%p, len=%d, "
        "timeoutMilliseconds=%d) = {-1}\n",
        socketToString(sock), (void*) buf, len, timeoutMilliseconds);
      return -1;
    }
    if (sslAcceptWatchArgs != NULL) {
      sslAcceptWatchArgs->accepted = true;
    }
    sock->sslAccepted = true;
    if (socketWasBlocking == false) {
      socketSetNonblocking(sock);
    }
    updateSocketString(sock);
  }
#endif // TLS_SOCKETS_ENABLED
  
  if ((sock->blocking == true) && (timeoutMilliseconds != 0)) {
    // Honor the timeout.
    if (timeoutMilliseconds < 0) {
      // Assume indefinitie timeout is desired (consistent with poll).
      timeoutMilliseconds = 0;
    }
    
#ifdef _WIN32
    DWORD timeout = timeoutMilliseconds;
#else // POSIX
    ZEROINIT(struct timeval timeout);
    timeout.tv_sec = timeoutMilliseconds / 1000;
    timeout.tv_usec = (timeoutMilliseconds % 1000) * 1000;
#endif // _WIN32
    // This call seems to always report failure even though it succeeds.
    // Deliberately ignoring the return value here.
    setsockopt(sock->sockfd, SOL_SOCKET, SO_RCVTIMEO, (char*) &timeout,
      sizeof(timeout));
  } else if ((sock->blocking == true) && (timeoutMilliseconds == 0)) {
    // socketWasBlocking was already set at the beginning of the function.
    socketSetNonblocking(sock);
  }
  
  int bytesReceived = 0;
  mtx_lock(&sock->lock);
  if ((sock->socketProtocol == TCP) && (sock->tcpConnected == true)) {
    if (sock->socketMode == PLAIN) {
      bytesReceived = (int) recv(sock->sockfd, (void*) buf, len, 0);
#ifdef TLS_SOCKETS_ENABLED
    } else if ((sock->socketMode == TLS)
      && (sock->socketType == CLIENT) && (sock->sslBio != NULL)
    ) {
      bytesReceived = BIO_read(sock->sslBio, (void*) buf, len);
    } else if ((sock->socketMode == TLS)
      && (sock->socketType == SERVER) && (sock->ssl != NULL)
    ) {
      bytesReceived = SSL_read(sock->ssl, (void*) buf, len);
#endif // TLS_SOCKETS_ENABLED
    } else {
      // Invalid state of socket.
      printLog(ERR, "Invalid socket in socketReceive.\n");
      printLog(ERR, "%s\n", socketToString(sock));
      bytesReceived = -1;
    }
  } else if (sock->socketProtocol == UDP) {
    // We're only receiving one packet in this case.
    struct sockaddr_in srcAddr = sock->sockaddr;
#ifdef _WIN32
    int srcAddrLen = sizeof(srcAddr);
#else // POSIX
    socklen_t srcAddrLen = sizeof(srcAddr);
#endif
    if (sock->socketMode == PLAIN) {
      bytesReceived = (int) recvfrom(sock->sockfd, (void*) buf, len, 0,
        (struct sockaddr*) &srcAddr, &srcAddrLen);
    }
  }
  mtx_unlock(&sock->lock);
  
  if ((bytesReceived < 0) && (socketWasBlocking == false)) {
    // This may not actually be an error.  Correct if not.
#ifndef _WIN32
    // On POSIX, errno is either EAGAIN or EWOULDBLOCK.
    if ((errno == EAGAIN) || (errno == EWOULDBLOCK))
#else // _WIN32 defined
    // On Windows, the non-blocking socket should make WSAGetLastError
    // return WSAEWOULDBLOCK.
    if (WSAGetLastError() == WSAEWOULDBLOCK)
#endif
    { // Putting this here so vim doesn't get confused about mathcing braces.
      bytesReceived = 0;
    }
  }
  
  if ((socketWasBlocking == true) && (sock->blocking == false)) {
    // We were provided a timeout of 0 milliseconds and set the socket to
    // nonblocking to accommodate.  Reset.
    socketSetBlocking(sock);
  }
  
  printLog(FLOOD,
    "EXIT socketReceive(sock=%s, buf=%p, len=%d, "
    "timeoutMilliseconds=%d) = {%d}\n",
    socketToString(sock), (void*) buf, len, timeoutMilliseconds, bytesReceived);
  return bytesReceived;
}

/// @fn Socket* socketAccept_(Socket *serverSocket, void *buf, int len, ...)
///
/// @brief Accept an incoming TCP client connection on a SERVER socket.
///
/// @param serverSocket The Socket to accept a connection from.
///
/// @param Returns a Socket of the client connection on success,
/// NULL on failure.
Socket* socketAccept_(Socket *serverSocket, void *buf, int len, ...) {
  printLog(TRACE, "ENTER socketAccept(serverSocket=%s, buf=%p, len=%d)\n",
    socketToString(serverSocket), (void*) buf, len);
  
  if (serverSocket == NULL) {
    printLog(ERR, "serverSocket is NULL.\n");
    printLog(TRACE,
      "EXIT socketAccept(serverSocket=NULL, buf=%p, len=%d) = {NULL}\n",
      (void*) buf, len);
    return NULL;
  } else if (serverSocket->socketType != SERVER) {
    printLog(ERR, "Socket is not a SERVER socket.\n");
    printLog(TRACE,
      "EXIT socketAccept(serverSocket=%s, buf=%p, len=%d) = {NULL}\n",
      socketToString(serverSocket), (void*) buf, len);
    return NULL;
  } else if ((serverSocket->socketProtocol == UDP) 
    && ((buf == NULL) || (len == 0))
  ) {
    printLog(ERR, "Socket is a UDP socket and extra parameters are missing.\n");
    printLog(TRACE,
      "EXIT socketAccept(serverSocket=%s, buf=%p, len=%d) = {NULL}\n",
      socketToString(serverSocket), (void*) buf, len);
    return NULL;
  }
  
  SocketType socketType = serverSocket->socketType;
  SocketProtocol socketProtocol = serverSocket->socketProtocol;
  SocketMode socketMode = serverSocket->socketMode;
  int sockfd = serverSocket->sockfd;
#ifdef TLS_SOCKETS_ENABLED
  SSL *clientSsl = NULL;
  if ((socketMode == TLS) && (tlsSocketsEnabled() == true)) {
    // We want to avoid segfaults.  At this point in the function, we're pretty
    // much guaranteed that the socket still exists, as does its sslContext.
    // However, after the accept() call, that may no longer be true because the
    // expected use model is that to end an acccept, the socket is destroyed.
    // So, we can't create a client's SSL object after the accept, we have to
    // go ahead and create it now.  If we don't need it, we'll delete it, but
    // if we do, we can just attach it to the client socket when it's created
    // after the accept().
    clientSsl = SSL_new(serverSocket->sslContext);
    if (clientSsl == NULL) {
      // Out of memory.
      printLog(TRACE,
        "EXIT socketAccept(serverSocket=%s, buf=%p, len=%d) = {NULL}\n",
        socketToString(serverSocket), (void*) buf, len);
      return NULL;
    }
  } else if (socketMode == TLS) {
    printLog(WARN, "Local system does not support TLS.  Using plaintext.\n");
    socketMode = PLAIN;
  }
#endif // TLS_SOCKETS_ENABLED
  
  ZEROINIT(struct sockaddr_in clientAddress);
  socklen_t clientAddressLength = sizeof(clientAddress);
  int clientSockfd = 0;
  if (socketProtocol == TCP) {
    while (clientSockfd == 0) {
      // Call listen to drop connections beyond the end of our connection queue.
      ZEROINIT(struct pollfd pollDescriptor);
      pollDescriptor.fd = sockfd;
      pollDescriptor.events = POLLRDNORM;
      int pollReturnValue = poll(&pollDescriptor, 1, -1);
      if (pollReturnValue == 0) {
        break;
      } else if (pollReturnValue < 0) {
        clientSockfd = -1;
        
#ifndef _WIN32
        // On POSIX, errno is either EAGAIN or EWOULDBLOCK.
        if ((errno == EAGAIN) || (errno == EWOULDBLOCK))
#else // _WIN32 defined
        // On Windows, the non-blocking socket should make WSAGetLastError
        // return WSAEWOULDBLOCK.
        if (WSAGetLastError() == WSAEWOULDBLOCK)
#endif
        {
          clientSockfd = 0;
          socketsMsleep(1);
        } else {
          printLog(ERR, "Unexpected error: %s\n", strerror(errno));
          break;
        }
      }
      clientSockfd = accept(sockfd,
        (struct sockaddr *) &clientAddress, &clientAddressLength);
    }
    if (clientSockfd < 0) {
      printLog(ERR, "Could not accept client connection.\n");
      // We may be in this state because the socket was destroyed.
      // Don't call socketToString.
#ifdef TLS_SOCKETS_ENABLED
      SSL_free(clientSsl); clientSsl = NULL;
#endif
      printLog(TRACE,
        "EXIT socketAccept(serverSocket=%p, buf=%p, len=%d) = {NULL}\n",
        (void*) serverSocket, (void*) buf, len);
      return NULL;
    }
  } else { // serverSocket->socketProtocol == UDP
    recvfrom(sockfd, buf, (size_t) len, 0,
      (struct sockaddr*) &clientAddress, &clientAddressLength);
    clientSockfd = socket(AF_INET, SOCK_DGRAM, 0);
  }
  
  Socket *clientSocket = (Socket*) calloc(1, sizeof(Socket));
  if (clientSocket == NULL) {
    // Out of memory.  Don't attempt to log our exit.
    LOG_MALLOC_FAILURE();
    rawSocketClose(clientSockfd);
    return NULL;
  }
  if (mtx_init(&clientSocket->lock, mtx_recursive) != thrd_success) {
    printLog(ERR, "Could initialize Socket lock.\n");
    free(clientSocket); clientSocket = NULL;
#ifdef TLS_SOCKETS_ENABLED
    SSL_free(clientSsl); clientSsl = NULL;
#endif
    rawSocketClose(clientSockfd);
    printLog(TRACE,
      "EXIT socketAccept(serverSocket=%p, buf=%p, len=%d) = {NULL}\n",
      (void*) serverSocket, (void*) buf, len);
    return NULL;
  }
  clientSocket->socketType = socketType;
  clientSocket->socketProtocol = socketProtocol;
  clientSocket->socketMode = socketMode;
  clientSocket->sockfd = clientSockfd;
  clientSocket->blocking = true;
  clientSocket->sockaddr = clientAddress;
  clientSocket->tcpConnected
    = (clientSocket->socketProtocol == TCP) ? true : false;
  
  char ipAddressString[INET_ADDRSTRLEN];
  struct in_addr ipAddress = clientAddress.sin_addr;
  inet_ntop(AF_INET, &ipAddress, ipAddressString, INET_ADDRSTRLEN);
  if (asprintf(&clientSocket->address, "%s:%d", ipAddressString,
    ntohs(clientAddress.sin_port)) < 0
  ) {
    clientSocket->address = NULL;
  }
  
  // For ipv6:
  // struct sockaddr_in6* pV6Address = (struct sockaddr_in6*) &clientAddress;
  // struct in6_addr ipAddress = pV6Address->sin6_addr;
  // char ipAddressString[INET6_ADDRSTRLEN];
  // inet_ntop(AF_INET6, &ipAddress, ipAddressString, INET6_ADDRSTRLEN);
  
#ifdef TLS_SOCKETS_ENABLED
  if ((socketMode == TLS) && (tlsSocketsEnabled() == true)) {
    clientSocket->ssl = clientSsl;
    SSL_set_fd(clientSocket->ssl, clientSocket->sockfd);
  } // else the clientSsl object was never created.
#endif // TLS_SOCKETS_ENABLED
  
  // Update the string representation of the socket.
  updateSocketString(clientSocket);
  
  printLog(TRACE, "EXIT socketAccept(serverSocket=%s, buf=%p, len=%d) = {%s}\n",
    socketToString(serverSocket), (void*) buf, len,
    socketToString(clientSocket));
  return clientSocket;
}

/// @fn const char* socketAddress(Socket *sock)
///
/// @brief Get the address associated with a socket.
///
/// @param sock The socket to get the address from.
///
/// @return Returns a string representation of the address of the socket.
const char* socketAddress(Socket *sock) {
  printLog(TRACE, "ENTER socketAddress(sock=%s)\n", socketToString(sock));
  
  const char *returnValue = "";
  if ((sock != NULL) && (sock->address != NULL)) {
    returnValue = sock->address;
  }
  
  printLog(TRACE, "EXIT socketAddress(sock=%s) = {%s}\n", socketToString(sock),
    returnValue);
  return returnValue;
}

/// @var _emptySocketString
///
/// @brief The function socketToString below does not allocate a new string.
/// In the event that the Socket passed in is NULL, it has to return a static
/// empty string.  This variable provides that vaule.
static const char *_emptySocketString = "";

/// @fn const char* socketToString(Socket *sock)
///
/// @brief Get a string representation of a Socket.
///
/// @param sock The socket to get the representation of.
///
/// @return Returns a string representation of the socket.
const char* socketToString(Socket *sock) {
  printLog(FLOOD, "ENTER socketToString(sock=%p)\n", (void*) sock);
  
  const char *returnValue = _emptySocketString;
  if ((sock != NULL) && (sock->_str != NULL)) {
    returnValue = sock->_str;
  }
  
  printLog(FLOOD, "EXIT socketToString(sock=%p) = {%s}\n", (void*) sock,
    returnValue);
  return returnValue;
}

