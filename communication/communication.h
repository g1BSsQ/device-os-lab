/**
 * @file communication.h
 * @brief Communication module API definitions.
 *
 * This file contains the declarations of communication protocols.
 */

#pragma once

#include <cstddef>
#include "message_queue.h"

/**
 * @brief Initializes the communication module.
 */
void communication_init();

/**
 * @brief Sends data using the new communication protocol.
 *
 * This function validates the input data, ensures it does not exceed the maximum buffer size,
 * and logs the operation.
 *
 * @param data The data to send (must not be null).
 * @param length The length of the data (must be greater than 0 and less than MAX_BUFFER_SIZE).
 * @return int Returns 0 on success, or -1 on failure.
 */
int communication_send(const char* data, size_t length);

/**
 * @brief Pushes a message to the communication queue.
 *
 * @param message The message to push.
 * @return true if the message was successfully pushed, false otherwise.
 */
bool communication_queue_push(const char* message);

/**
 * @brief Pops a message from the communication queue.
 *
 * @param buffer The buffer to store the popped message.
 * @return true if a message was successfully popped, false otherwise.
 */
bool communication_queue_pop(char* buffer);
