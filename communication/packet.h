#ifndef COMMUNICATION_PACKET_H
#define COMMUNICATION_PACKET_H

#include <cstdint>
#include <cstddef>

const uint32_t PACKET_MAGIC = 0x12345678;
const size_t MIN_PACKET_SIZE = 8;
const size_t MAX_PAYLOAD_SIZE = 256;

struct PacketHeader {
    uint32_t magic;
    uint16_t type;
    uint16_t length;
};

struct Packet {
    PacketHeader header;
    uint8_t payload[MAX_PAYLOAD_SIZE];
    size_t payload_size;
};

bool parse_packet(const uint8_t* data, size_t length, Packet& packet);

#endif // COMMUNICATION_PACKET_H

// ...existing code...