#include "convert.h"
#include <assert.h>
#include <stdio.h>

void test_convert() {
    char hex[16];
    int_to_hex(123456, hex, sizeof(hex));
    printf("123456 to hex: %s\n", hex);
    uint32_t val = hex_to_int(hex);
    printf("%s to int: %u\n", hex, val);
    assert(val == 123456);
    printf("Convert test passed!\n");
}

int main() {
    test_convert();
    return 0;
}
