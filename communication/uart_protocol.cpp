#include "uart_protocol.h"
#include <iostream>
#include <cstring>

static uint32_t current_baud_rate = 0;

bool uart_init(uint32_t baud_rate) {
    // Simulate UART initialization
    current_baud_rate = baud_rate;
    std::cout << "UART initialized with baud rate: " << baud_rate << std::endl;
    return true;
}

size_t uart_send(const uint8_t* data, size_t length) {
    if (data == nullptr || length == 0) {
        std::cerr << "UART send error: Invalid data or length." << std::endl;
        return 0;
    }

    // Simulate sending data over UART
    std::cout << "UART sending data: ";
    for (size_t i = 0; i < length; ++i) {
        std::cout << std::hex << static_cast<int>(data[i]) << " ";
    }
    std::cout << std::dec << std::endl;

    return length;
}

size_t uart_receive(uint8_t* buffer, size_t length) {
    if (buffer == nullptr || length == 0) {
        std::cerr << "UART receive error: Invalid buffer or length." << std::endl;
        return 0;
    }

    // Simulate receiving data over UART
    const char* simulated_data = "Hello, UART!";
    size_t simulated_length = std::min(length, strlen(simulated_data));
    std::memcpy(buffer, simulated_data, simulated_length);

    std::cout << "UART received data: ";
    for (size_t i = 0; i < simulated_length; ++i) {
        std::cout << simulated_data[i];
    }
    std::cout << std::endl;

    return simulated_length;
}