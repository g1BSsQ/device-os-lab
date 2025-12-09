#include "keystore.h"
#include <string.h>
#include <stdio.h>

#define MAX_KEYS 10

static KeyStore g_keystore[MAX_KEYS];
static size_t g_key_count = 0;

bool keystore_add_key(const char* key_id, const uint8_t* key_data, size_t key_size) {
    if (g_key_count >= MAX_KEYS || key_size > MAX_KEY_SIZE) {
        return false; // Key store full or key too large
    }

    for (size_t i = 0; i < g_key_count; ++i) {
        if (strcmp(g_keystore[i].key_id, key_id) == 0) {
            return false; // Duplicate key ID
        }
    }

    strncpy(g_keystore[g_key_count].key_id, key_id, MAX_KEY_ID_SIZE);
    memcpy(g_keystore[g_key_count].key_data, key_data, key_size);
    g_keystore[g_key_count].key_size = key_size;
    g_key_count++;

    return true;
}

bool keystore_get_key(const char* key_id, uint8_t* key_data, size_t* key_size) {
    for (size_t i = 0; i < g_key_count; ++i) {
        if (strcmp(g_keystore[i].key_id, key_id) == 0) {
            memcpy(key_data, g_keystore[i].key_data, g_keystore[i].key_size);
            *key_size = g_keystore[i].key_size;
            return true;
        }
    }

    return false; // Key not found
}

// ...existing code...