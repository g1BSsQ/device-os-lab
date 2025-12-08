/**
 * @file communication_dynalib.h
 * @brief Dynamic library API definitions for communication module.
 *
 * This file contains the declarations of dynamic library support for communication protocols.
 */

#pragma once

#include <cstddef>

/**
 * @brief Initializes the communication module (dynamic library).
 */
void communication_dynalib_init();

/**
 * @brief Sends data using the new communication protocol (dynamic library).
 *
 * This function validates the input data and logs the operation.
 *
 * @param data The data to send (must not be null).
 * @param length The length of the data (must be greater than 0).
 * @return int Returns 0 on success, or -1 on failure.
 */
int communication_dynalib_send(const char* data, size_t length);

/**
 * @brief Get error string for communication error code (dynalib).
 * @param code Error code.
 * @return const char* Error string.
 */
const char* communication_dynalib_error_str(int code);
