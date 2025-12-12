/**
 * @file secure_boot.h
 * @brief Secure boot verification interface.
 *
 * This file contains the declarations for secure boot verification.
 */

#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @brief Verifies the integrity of the bootloader.
 *
 * @param bootloader_data Pointer to the bootloader data.
 * @param length Length of the bootloader data.
 * @param signature Pointer to the signature.
 * @return true if the verification is successful, false otherwise.
 */
bool secure_boot_verify(const uint8_t* bootloader_data, size_t length, const uint8_t* signature);