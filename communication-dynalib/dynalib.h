#ifndef COMMUNICATION_DYNALIB_H
#define COMMUNICATION_DYNALIB_H

#include "communication/packet.h"

// Export optimized packet parsing function
bool parse_packet(const uint8_t* data, size_t length, Packet& packet);

#endif // COMMUNICATION_DYNALIB_H

// ...existing code...