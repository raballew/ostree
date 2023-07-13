/*
 * SPDX-License-Identifier: LGPL-2.0+
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include "config.h"

#include "otutil.h"
#include <stdbool.h>

#ifdef HAVE_LIBSODIUM
#include <sodium.h>
#define USE_LIBSODIUM
#elif defined(HAVE_OPENSSL)
#include <openssl/evp.h>
#define USE_OPENSSL
#endif

// Length of a signature in bytes
#define OSTREE_SIGN_ED25519_SIG_SIZE 64U
// Length of a public key in bytes
#define OSTREE_SIGN_ED25519_PUBKEY_SIZE 32U
// This key is stored inside commit metadata.
#define OSTREE_SIGN_METADATA_ED25519_KEY "ostree.sign.ed25519"
// The variant type
#define OSTREE_SIGN_METADATA_ED25519_TYPE "aay"

bool otcore_ed25519_init (void);
gboolean otcore_validate_ed25519_signature (GBytes *data, GBytes *pubkey, GBytes *signature,
                                            bool *out_valid, GError **error);

// The name of the composefs metadata root
#define OSTREE_COMPOSEFS_NAME ".ostree.cfs"