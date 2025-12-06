#ifndef PLATFORM_FLASH_H
#define PLATFORM_FLASH_H
#include <stddef.h>
#include <stdint.h>

// Đọc dữ liệu từ flash
int flash_read(uint32_t address, void* buffer, size_t size);
// Ghi dữ liệu vào flash
int flash_write(uint32_t address, const void* data, size_t size);

#endif // PLATFORM_FLASH_H
