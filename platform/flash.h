#ifndef PLATFORM_FLASH_H
#define PLATFORM_FLASH_H
#include <stddef.h>
#include <stdint.h>

// Đọc dữ liệu từ flash
int flash_read(uint32_t address, uint8_t* buffer, size_t length);
// Ghi dữ liệu vào flash
int flash_write(uint32_t address, const uint8_t* data, size_t length);

#endif // PLATFORM_FLASH_H
