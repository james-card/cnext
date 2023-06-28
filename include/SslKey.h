///////////////////////////////////////////////////////////////////////////////
///
/// @author            James B. Card
/// @date              11.28.2021
///
/// @file              SslKey.h
///
/// @brief             Header for defaultSslKey.
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

#ifndef DEFAULT_SSL_KEY_H
#define DEFAULT_SSL_KEY_H

#ifdef __cplusplus
extern "C"
{
#endif

/// @var defaultSslKey
///
/// @brief The default key to use if none is specified when the database is
/// initialized.
extern const char *defaultSslKey;

#ifdef __cplusplus
} // extern "C"
#endif

#endif // DEFAULT_SSL_KEY_H

