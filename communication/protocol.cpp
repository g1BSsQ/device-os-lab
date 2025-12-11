#include "protocol.h"
#include <iostream>

void Protocol::initialize() {
    std::cout << "[Protocol] Initializing new communication protocol..." << std::endl;
}

void Protocol::send(const std::string& message) {
    std::cout << "[Protocol] Sending message: " << message << std::endl;
}

std::string Protocol::receive() {
    std::cout << "[Protocol] Receiving message..." << std::endl;
    return "[Protocol] Received message";
}