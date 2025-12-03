#define DYNALIB_IMPORT
#include "crypto_dynalib.h"
#include <string.h>
#include <stdint.h>

// Example encryption function
void encrypt_data(const uint8_t* input, uint8_t* output, size_t length, const uint8_t* key) {
    for (size_t i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i % strlen((const char*)key)];
    }
}

// Example decryption function
void decrypt_data(const uint8_t* input, uint8_t* output, size_t length, const uint8_t* key) {
    for (size_t i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i % strlen((const char*)key)];
    }
}

