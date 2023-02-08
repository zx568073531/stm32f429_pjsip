/**
 * @file acme_client_certificate.h
 * @brief Certificate management
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2019-2022 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneACME Open.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @author Oryx Embedded SARL (www.oryx-embedded.com)
 * @version 2.1.4
 **/

#ifndef _ACME_CLIENT_CERTIFICATE_H
#define _ACME_CLIENT_CERTIFICATE_H

//Dependencies
#include "acme/acme_client.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//ACME client related functions
error_t acmeClientSendDownloadCertRequest(AcmeClientContext *context,
   char_t *buffer, size_t size, size_t *length);

error_t acmeClientFormatDownloadCertRequest(AcmeClientContext *context);

error_t acmeClientParseDownloadCertResponse(AcmeClientContext *context,
   char_t *buffer, size_t size, size_t *length);

error_t acmeClientSendRevokeCertRequest(AcmeClientContext *context,
   const char_t *cert, size_t certLen, AcmeReasonCode reason);

error_t acmeClientFormatRevokeCertRequest(AcmeClientContext *context,
   const char_t *cert, size_t certLen, AcmeReasonCode reason);

error_t acmeClientParseRevokeCertResponse(AcmeClientContext *context);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
