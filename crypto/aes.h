#ifndef CRYPTO_AES_H
#define CRYPTO_AES_H
#include <stddef.h>
#include <stdint.h>

const size_t AES_BLOCK_SIZE = 16;

// Memory-optimized AES (no heap allocation)
void aes_encrypt(const uint8_t* input, uint8_t* output, size_t length, const uint8_t* key, size_t key_len);
void aes_decrypt(const uint8_t* input, uint8_t* output, size_t length, const uint8_t* key, size_t key_len);

// AES-256 encryption and decryption
bool aes256_encrypt(const uint8_t* key, const uint8_t* plaintext, uint8_t* ciphertext, size_t length);
bool aes256_decrypt(const uint8_t* key, const uint8_t* ciphertext, uint8_t* plaintext, size_t length);

#endif // CRYPTO_AES_H
