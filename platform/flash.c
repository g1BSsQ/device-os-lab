#include "flash.h"
#include <stdio.h>
#include <string.h>

// Giả lập vùng flash
#define FLASH_SIZE 4096
static uint8_t fake_flash[FLASH_SIZE];

int flash_read(uint32_t address, void* buffer, size_t size) {
    if (address + size > FLASH_SIZE) return -1;
    memcpy(buffer, &fake_flash[address], size);
    printf("Read %zu bytes from flash at 0x%08X\n", size, address);
    return 0;
}

int flash_write(uint32_t address, const void* data, size_t size) {
    if (address + size > FLASH_SIZE) return -1;
    memcpy(&fake_flash[address], data, size);
    printf("Wrote %zu bytes to flash at 0x%08X\n", size, address);
    return 0;
}
