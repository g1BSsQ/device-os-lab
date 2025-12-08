
#include "convert.h"
#include <stdio.h>
#include <stdlib.h>

void int_to_hex(uint32_t value, char* out, size_t out_size) {
    snprintf(out, out_size, "%08X", value);
}

uint32_t hex_to_int(const char* hex) {
    return (uint32_t)strtoul(hex, NULL, 16);
}
