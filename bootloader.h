#ifndef BOOTLOADER_H
#define BOOTLOADER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdalign.h>

typedef enum {
    BOOTLOADER_OK = 0,
    BOOTLOADER_ERROR_SYSTEM_INIT = -1,
    BOOTLOADER_ERROR_SECURE_BOOT = -2,
    BOOTLOADER_ERROR_VERSION_INVALID = -3,
    BOOTLOADER_ERROR_NULL_POINTER = -4,
    BOOTLOADER_ERROR_MEMORY = -5
} BootloaderError;

typedef struct {
    alignas(4) int major;
    alignas(4) int minor;
    alignas(4) int patch;
} FirmwareVersion;

int bootloader_set_version(int major, int minor, int patch);
FirmwareVersion bootloader_get_version(void);
int bootloader_print_version(void);
int bootloader_init(void);
int bootloader_secure_boot(void);
const char* bootloader_error_string(int error_code);

#ifdef __cplusplus
}
#endif

#endif // BOOTLOADER_H
