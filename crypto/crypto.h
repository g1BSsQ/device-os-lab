/**
 * @file crypto.h
 * @brief Cryptographic algorithm definitions.
 *
 * This file contains the declarations of cryptographic algorithms for Device OS.
 */

#pragma once

#include <string>

/**
 * @brief Encrypts the given plaintext using the specified key.
 *
 * This function logs the plaintext, key, and encrypted result for debugging purposes.
 *
 * @param plaintext The input text to encrypt.
 * @param key The encryption key.
 * @return std::string The encrypted text.
 */
std::string encrypt(const std::string& plaintext, const std::string& key);

/**
 * @brief Decrypts the given ciphertext using the specified key.
 *
 * This function logs the ciphertext, key, and decrypted result for debugging purposes.
 *
 * @param ciphertext The input text to decrypt.
 * @param key The decryption key.
 * @return std::string The decrypted text.
 */
std::string decrypt(const std::string& ciphertext, const std::string& key);
