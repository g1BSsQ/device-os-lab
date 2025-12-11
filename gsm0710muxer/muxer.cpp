#include "muxer.h"
#include <vector>
#include <algorithm>
#include <iostream>

static std::vector<uint8_t> buffer;

void muxer_init() {
    buffer.clear();
    buffer.reserve(1024); // Pre-allocate memory for performance
}

void muxer_process(const uint8_t* data, size_t len) {
    if (!data || len == 0) {
        return;
    }

    buffer.insert(buffer.end(), data, data + len);

    // Simulate processing
    std::for_each(buffer.begin(), buffer.end(), [](uint8_t& byte) {
        byte ^= 0xFF; // Example transformation
    });

    std::cout << "Processed " << len << " bytes." << std::endl;
    buffer.clear();
}

bool muxer_validate_crc(const uint8_t* data, size_t len, uint16_t expected_crc) {
    uint16_t crc = 0;
    for (size_t i = 0; i < len; ++i) {
        crc ^= data[i];
    }
    return crc == expected_crc;
}