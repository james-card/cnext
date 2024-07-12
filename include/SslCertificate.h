///////////////////////////////////////////////////////////////////////////////
///
/// @author            James B. Card
/// @date              11.28.2021
///
/// @file              SslCertificate.h
///
/// @brief             Header for defaultSslCertificate.
///
/// @copyright
///       (c) Copyright 2012-2021 James B. Card  All Rights Reserved.
///
///  This software contains confidential information and trade secrets of
/// James B. Card.  Use, disclosure, or reproduction is prohibited without
///         the prior express written permission of James B. Card.
///
///                       James B. Card
///                  http://www.jamescard.org
///
///////////////////////////////////////////////////////////////////////////////

#ifndef DEFAULT_SSL_CERTIFICATE_H
#define DEFAULT_SSL_CERTIFICATE_H

#ifdef __cplusplus
extern "C"
{
#endif

/// @var defaultSslCertificate
///
/// @brief The default certificate to use if none is specified when the database
/// is initialized.
extern const char *defaultSslCertificate;

#ifdef __cplusplus
} // extern "C"
#endif

#endif // DEFAULT_SSL_CERTIFICATE_H

