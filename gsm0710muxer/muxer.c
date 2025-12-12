#include "muxer.h"
#include <stdio.h>
#include <stdint.h>
#include "crc.h" // Assume a CRC library is available

static MuxerState current_state = MUXER_STATE_IDLE;

void muxer_init() {
    current_state = MUXER_STATE_IDLE;
    printf("Muxer initialized.\n");
}

MuxerState muxer_get_state() {
    return current_state;
}

void muxer_set_state(MuxerState state) {
    current_state = state;
    printf("Muxer state changed to: %d\n", state);
}

bool muxer_validate_crc(const uint8_t* data, size_t len, uint16_t expected_crc) {
    uint16_t calculated_crc = crc16(data, len); // Assume crc16 is a function in crc.h
    return calculated_crc == expected_crc;
}

void muxer_process(const uint8_t* data, size_t len) {
    if (current_state == MUXER_STATE_ERROR) {
        printf("Cannot process data. Muxer is in ERROR state.\n");
        return;
    }

    muxer_set_state(MUXER_STATE_PROCESSING);

    // Validate CRC before processing
    uint16_t expected_crc = 0xFFFF; // Example expected CRC value
    if (!muxer_validate_crc(data, len, expected_crc)) {
        printf("CRC validation failed.\n");
        muxer_set_state(MUXER_STATE_ERROR);
        return;
    }

    // Process data
    printf("Processing %zu bytes in muxer.\n", len);

    muxer_set_state(MUXER_STATE_IDLE);
}
