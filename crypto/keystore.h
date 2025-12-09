#ifndef CRYPTO_KEYSTORE_H
#define CRYPTO_KEYSTORE_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MAX_KEY_ID_SIZE 32
#define MAX_KEY_SIZE 64

typedef struct {
    char key_id[MAX_KEY_ID_SIZE];
    uint8_t key_data[MAX_KEY_SIZE];
    size_t key_size;
} KeyStore;

bool keystore_add_key(const char* key_id, const uint8_t* key_data, size_t key_size);
bool keystore_get_key(const char* key_id, uint8_t* key_data, size_t* key_size);

#endif // CRYPTO_KEYSTORE_H

// ...existing code...