#include "packet.h"
#include <cstring>
#include <algorithm>

// Optimized packet parsing function
bool parse_packet(const uint8_t* data, size_t length, Packet& packet) {
    if (length < MIN_PACKET_SIZE) {
        return false; // Invalid packet size
    }

    // Extract header
    std::memcpy(&packet.header, data, sizeof(PacketHeader));

    // Validate header
    if (packet.header.magic != PACKET_MAGIC) {
        return false; // Invalid packet
    }

    // Extract payload
    size_t payload_size = std::min(length - sizeof(PacketHeader), MAX_PAYLOAD_SIZE);
    std::memcpy(packet.payload, data + sizeof(PacketHeader), payload_size);
    packet.payload_size = payload_size;

    return true;
}

// ...existing code...