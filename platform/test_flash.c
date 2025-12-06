#include "flash.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void test_flash() {
    uint8_t data[8] = {1,2,3,4,5,6,7,8};
    uint8_t buffer[8] = {0};
    assert(flash_write(100, data, sizeof(data)) == 0);
    assert(flash_read(100, buffer, sizeof(buffer)) == 0);
    assert(memcmp(data, buffer, sizeof(data)) == 0);
    printf("Flash read/write test passed!\n");
}

int main() {
    test_flash();
    return 0;
}
