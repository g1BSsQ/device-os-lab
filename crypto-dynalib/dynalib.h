#ifndef CRYPTO_DYNALIB_H
#define CRYPTO_DYNALIB_H

#include "crypto/aes.h"

// Export AES-256 encryption and decryption functions
bool aes256_encrypt(const uint8_t* key, const uint8_t* plaintext, uint8_t* ciphertext, size_t length);
bool aes256_decrypt(const uint8_t* key, const uint8_t* ciphertext, uint8_t* plaintext, size_t length);

#endif // CRYPTO_DYNALIB_H

// ...existing code...