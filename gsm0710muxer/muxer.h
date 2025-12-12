#ifndef GSM0710MUXER_MUXER_H
#define GSM0710MUXER_MUXER_H
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
    MUXER_STATE_IDLE,
    MUXER_STATE_START,
    MUXER_STATE_PROCESSING,
    MUXER_STATE_ERROR
} MuxerState;

void muxer_process(const uint8_t* data, size_t len);
void muxer_init();
bool muxer_validate_crc(const uint8_t* data, size_t len, uint16_t expected_crc);
MuxerState muxer_get_state();
void muxer_set_state(MuxerState state);

#endif // GSM0710MUXER_MUXER_H
