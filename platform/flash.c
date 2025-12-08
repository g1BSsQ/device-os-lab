#include "flash.h"
#include <stdio.h>
#include <string.h>

// Giả lập vùng flash
#define FLASH_SIZE 4096
static uint8_t fake_flash[FLASH_SIZE];

int flash_read(uint32_t address, uint8_t* buffer, size_t length) {
    if (address + length > FLASH_SIZE) return -1;
    memcpy(buffer, &fake_flash[address], length);
    printf("Read %zu bytes from flash at 0x%08X\n", length, address);
    return 0;
}

int flash_write(uint32_t address, const uint8_t* data, size_t length) {
    if (address + length > FLASH_SIZE) return -1;
    memcpy(&fake_flash[address], data, length);
    printf("Wrote %zu bytes to flash at 0x%08X\n", length, address);
    return 0;
}
