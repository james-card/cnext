///////////////////////////////////////////////////////////////////////////////
///
/// @author            James Card
/// @date              11.13.2020
///
/// @file              Sockets.h
///
/// @brief             This is the root header that can be included from
///                    libraries that make use of sockets.  This header will
///                    determine the system and include the correct system-
///                    specific headers.
///
/// @details
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

#ifndef SOCKETS_H
#define SOCKETS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>

#ifdef TLS_SOCKETS_ENABLED
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/conf.h>
#endif // TLS_SOCKETS_ENABLED

#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>

#include "StringLib.h"

/// @def rawSocketClose
///
/// @brief Forcible socket close define for Windows systems.
///
/// @detail
/// We want to close the socket irrespective of this return value of shutdown,
/// so the call to close() is not dependent on the return value of shutdown().
#define rawSocketClose(socket) \
  (shutdown(socket, SD_BOTH), closesocket(socket))

#define MSG_NOSIGNAL 0

#define poll WSAPoll

#ifdef _MSC_VER
#pragma comment (lib, "Ws2_32.lib")
#endif // _MSC_VER

#else // POSIX

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> // superset of previous
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <fcntl.h>
#include <poll.h>
#include <sys/ioctl.h>

#include "CThreads.h"

#ifdef __cplusplus
extern "C"
{
#endif

/// @def rawSocketClose
///
/// @brief Forcible socket close define for POSIX systems.
///
/// @detail
/// On UDP sockets, calling shutdown will result in an error because there's no
/// connection.  We want to close the socket irrespective of this situation, so
/// the call to close() is not dependent on the return value of shutdown().
#define rawSocketClose(socket) \
  (shutdown(socket, SHUT_RDWR), close(socket))
#define NO_ERROR 0

#endif // _WIN32


// Value definitions
#define JUMBO_FRAME_SIZE 9000

// Type definitions
typedef enum SocketType {
  SERVER,
  CLIENT,
  NUM_SOCKET_TYPES
} SocketType;
extern const char *SocketTypeNames[];

typedef enum SocketMode {
  PLAIN,
  TLS,
  NUM_SOCKET_MODES
} SocketMode;
extern const char *SocketModeNames[];

typedef enum SocketProtocol {
  TCP,
  UDP,
  NUM_SOCKET_PROTOCOLS
} SocketProtocol;
extern const char *SocketProtocolNames[];

typedef struct Socket {
  int sockfd;
  SocketType socketType;
  SocketProtocol socketProtocol;
  SocketMode socketMode;
  char *address;
  struct sockaddr_in sockaddr;
  bool blocking;
  bool tcpConnected;
  mtx_t lock;
#ifdef TLS_SOCKETS_ENABLED
  SSL_CTX *sslContext;
  SSL *ssl;
  BIO *sslBio;
  bool sslAccepted;
#endif // TLS_SOCKETS_ENABLED
  char *_str;
} Socket;

// Raw sockets functions.  Provided in case a user wants to make use of the
// low-level functionality.
int rawSocketsInit();
int rawSocketConnect(int sockfd, const struct sockaddr *address,
  int addressLength, int timeoutMilliseconds);

// Sockets functions
int socketSetNonblocking(Socket *sock);
int socketSetBlocking(Socket *sock);
bool tlsSocketsEnabled();
Socket* socketCreate_(SocketType socketType, SocketProtocol socketProtocol,
  const char *address,
  int socketMode, const char *certificate, const char *key,
  int timeoutMilliseconds, ...);
#define socketCreate(socketType, socketProtocol, address, ...) \
  socketCreate_(socketType, socketProtocol, address, ##__VA_ARGS__, 0, 0, 0, 0)
void getIpAddress(char **address);
size_t getAddressSize(const char *address);
char *getNetworkAddress(const char *address, size_t numFixedBits);
Socket* socketDestroy(Socket *sock);
int socketSend(Socket *sock, const volatile void *buf, int len);
int socketReceive_(Socket *sock, volatile void *buf, int len, int timeoutMilliseconds,
  ...);
#define socketReceive(sock, buf, len, ...) \
  socketReceive_(sock, buf, len, ##__VA_ARGS__, -1)
Socket* socketAccept_(Socket *serverSocket, void *buf, int len, ...);
#define socketAccept(serverSocket, ...) \
  socketAccept_(serverSocket, ##__VA_ARGS__, 0, 0)
const char* socketAddress(Socket *sock);
const char* socketToString(Socket *sock);
#ifdef TLS_SOCKETS_ENABLED
int configureTlsClientSocket(Socket *sock, int timeoutMilliseconds);
bool tlsKeyAndCertificateValid(const char *certificate, const char *key);
#endif // TLS_SOCKETS_ENABLED

#ifdef __cplusplus
}
#endif

#endif // SOCKETS_H

