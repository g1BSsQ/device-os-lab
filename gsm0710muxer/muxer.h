#ifndef GSM0710MUXER_MUXER_H
#define GSM0710MUXER_MUXER_H
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

void muxer_process(const uint8_t* data, size_t len);
void muxer_init();
bool muxer_validate_crc(const uint8_t* data, size_t len, uint16_t expected_crc);

#endif // GSM0710MUXER_MUXER_H
