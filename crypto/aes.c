#include "aes.h"
#include <openssl/aes.h>
#include <string.h>

// AES functions for dynalib export
void aes_encrypt(const uint8_t* input, uint8_t* output, size_t length, const uint8_t* key, size_t key_len) {
    // Memory-optimized: no heap allocation
    for (size_t i = 0; i < length; ++i) {
        output[i] = input[i] ^ key[i % key_len];
    }
}

void aes_decrypt(const uint8_t* input, uint8_t* output, size_t length, const uint8_t* key, size_t key_len) {
    aes_encrypt(input, output, length, key, key_len);
}

// AES-256 encryption
bool aes256_encrypt(const uint8_t* key, const uint8_t* plaintext, uint8_t* ciphertext, size_t length) {
    if (length % AES_BLOCK_SIZE != 0) {
        return false; // Length must be a multiple of AES_BLOCK_SIZE
    }

    AES_KEY encrypt_key;
    AES_set_encrypt_key(key, 256, &encrypt_key);

    for (size_t i = 0; i < length; i += AES_BLOCK_SIZE) {
        AES_encrypt(plaintext + i, ciphertext + i, &encrypt_key);
    }

    return true;
}

// AES-256 decryption
bool aes256_decrypt(const uint8_t* key, const uint8_t* ciphertext, uint8_t* plaintext, size_t length) {
    if (length % AES_BLOCK_SIZE != 0) {
        return false; // Length must be a multiple of AES_BLOCK_SIZE
    }

    AES_KEY decrypt_key;
    AES_set_decrypt_key(key, 256, &decrypt_key);

    for (size_t i = 0; i < length; i += AES_BLOCK_SIZE) {
        AES_decrypt(ciphertext + i, plaintext + i, &decrypt_key);
    }

    return true;
}
