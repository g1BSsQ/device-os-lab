/**
 ******************************************************************************
 Copyright (c) 2013-2017 Particle Industries, Inc.  All rights reserved.

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation, either
 version 3 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************
 */

#include "mbedtls_util.h"
#include "mbedtls/timing.h"
#include "mbedtls/x509_crt.h"
#include "mbedtls/pk.h"
#include <cstring>
#include <stdlib.h>

#include "rng_hal.h"
#include "timer_hal.h"
#include "system_error.h"
#include "platforms.h"

int mbedtls_default_rng(void*, unsigned char* data, size_t size) {
    while (size >= 4) {
        *((uint32_t*)data) = HAL_RNG_GetRandomNumber();
        data += 4;
        size -= 4;
    }
    while (size-- > 0) {
        *data++ = HAL_RNG_GetRandomNumber();
    }
    return 0;
}

// At least millis should be provided
static mbedtls_callbacks_t s_callbacks = {};

__attribute__((weak)) int mbedtls_set_callbacks(mbedtls_callbacks_t* callbacks, void* reserved)
{
    memcpy(&s_callbacks, callbacks, sizeof(mbedtls_callbacks_t));
    return 0;
}

__attribute__((weak)) mbedtls_callbacks_t* mbedtls_get_callbacks(void* reserved)
{
    return &s_callbacks;
}

#if PLATFORM_ID != PLATFORM_GCC
unsigned long mbedtls_timing_hardclock()
{
    return HAL_Timer_Microseconds();
}
#endif

int mbedtls_x509_crt_pem_to_der(const char* pem_crt, size_t pem_len, uint8_t** der_crt, size_t* der_len)
{
    int ret = -1;
    mbedtls_x509_crt crt;
    mbedtls_x509_crt_init(&crt);
    ret = mbedtls_x509_crt_parse(&crt, (const uint8_t*)pem_crt, pem_len);

    *der_crt = NULL;
    *der_len = 0;

    if (ret != 0) {
        return ret;
    }

    ret = -1;

    size_t total_len = 0;
    for (mbedtls_x509_crt* c = &crt; c != NULL; c = c->next) {
        if (c->raw.p && c->raw.len) {
            total_len += c->raw.len;
        }
    }

    if (total_len && total_len == crt.raw.len) {
        // Single certificate
        *der_crt = crt.raw.p;
        *der_len = total_len;
        crt.raw.p = NULL;
        crt.raw.len = 0;
        ret = 0;
    } else if (total_len) {
        // Multiple certificates, concatenate
        uint8_t* der = (uint8_t*)calloc(1, total_len);
        if (der) {
            *der_crt = der;
            for (mbedtls_x509_crt* c = &crt; c != NULL; c = c->next) {
                if (c->raw.p && c->raw.len) {
                    memcpy(der, c->raw.p, c->raw.len);
                    der += c->raw.len;
                }
            }
            *der_len = total_len;
            ret = 0;
        } else {
            ret = -1;
        }
    }

    mbedtls_x509_crt_free(&crt);

    return ret;
}

// Added helper function for memory allocation with error handling
static uint8_t* allocate_memory(size_t size) {
    uint8_t* memory = (uint8_t*)calloc(1, size);
    if (!memory) {
        // Handle memory allocation failure
        return NULL;
    }
    return memory;
}

int mbedtls_pk_pem_to_der(const char* pem_key, size_t pem_len, uint8_t** der_key, size_t* der_len)
{
    mbedtls_pk_context pkctx;
    mbedtls_pk_init(&pkctx);

    *der_key = nullptr;
    *der_len = 0;

    int ret = mbedtls_pk_parse_key(&pkctx, (const uint8_t*)pem_key, pem_len, nullptr, 0);
    if (ret != 0) {
        mbedtls_pk_free(&pkctx);
        return SYSTEM_ERROR_KEY_INVALID_FORMAT;
    }

    size_t len = pem_len * 3 / 4;
    if (len == 0) {
        mbedtls_pk_free(&pkctx);
        return SYSTEM_ERROR_NO_MEMORY;
    }

    std::unique_ptr<uint8_t[]> der(new (std::nothrow) uint8_t[len]);
    if (!der) {
        mbedtls_pk_free(&pkctx);
        return SYSTEM_ERROR_NO_MEMORY;
    }

    ret = mbedtls_pk_write_key_der(&pkctx, der.get(), len);
    if (ret > 0) {
        if ((size_t)ret != len) {
            std::memmove(der.get(), der.get() + (len - ret), ret);
        }
        *der_key = der.release();
        *der_len = ret;
        ret = 0;
    } else {
        ret = SYSTEM_ERROR_CRYPTO;
    }

    mbedtls_pk_free(&pkctx);
    return ret;
}

int mbedtls_x509_read_length(const uint8_t* der, size_t length, int concatenated)
{
    size_t len = 0;
    size_t total_len = 0;
    int ret = 0;
    uint8_t* p = (uint8_t*)der;
    uint8_t* pp = p;

    while (total_len < length && ret == 0) {
        if ((ret = mbedtls_asn1_get_tag(&p, der + length, &len, 0x30)) == 0) {
            total_len += len + (p - pp);
            p = (uint8_t*)(der + total_len);
            pp = p;
        }
        if (!concatenated) {
            break;
        }
    }

    return total_len;
}

// Refactored mbedtls_to_system_error to handle more specific error codes
int mbedtls_to_system_error(int error) {
    switch (error) {
        case 0:
            return SYSTEM_ERROR_NONE;
        case MBEDTLS_ERR_X509_CERT_VERIFY_FAILED:
            return SYSTEM_ERROR_CERT_VERIFY_FAILED;
        case MBEDTLS_ERR_PK_KEY_INVALID_FORMAT:
            return SYSTEM_ERROR_KEY_INVALID_FORMAT;
        case MBEDTLS_ERR_ASN1_OUT_OF_DATA:
            return SYSTEM_ERROR_ASN1_OUT_OF_DATA;
        default:
            return SYSTEM_ERROR_CRYPTO;
    }
}
