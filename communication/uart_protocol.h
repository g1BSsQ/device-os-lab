#ifndef UART_PROTOCOL_H
#define UART_PROTOCOL_H

#include <cstdint>
#include <cstddef>

/**
 * @brief Initializes the UART communication protocol.
 *
 * This function sets up the UART hardware and prepares it for communication.
 *
 * @param baud_rate The baud rate for UART communication.
 * @return true if initialization was successful, false otherwise.
 */
bool uart_init(uint32_t baud_rate);

/**
 * @brief Sends data over UART.
 *
 * This function transmits the specified data over the UART interface.
 *
 * @param data A pointer to the data buffer to send.
 * @param length The length of the data buffer in bytes.
 * @return The number of bytes successfully sent.
 */
size_t uart_send(const uint8_t* data, size_t length);

/**
 * @brief Receives data over UART.
 *
 * This function reads data from the UART interface into the specified buffer.
 *
 * @param buffer A pointer to the buffer to store received data.
 * @param length The maximum number of bytes to receive.
 * @return The number of bytes successfully received.
 */
size_t uart_receive(uint8_t* buffer, size_t length);

#endif // UART_PROTOCOL_H