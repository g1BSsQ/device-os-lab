#ifndef BOOTLOADER_H
#define BOOTLOADER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdalign.h>

typedef struct {
    alignas(4) int major;
    alignas(4) int minor;
    alignas(4) int patch;
} FirmwareVersion;

void bootloader_set_version(int major, int minor, int patch);
FirmwareVersion bootloader_get_version(void);
void bootloader_print_version(void);
void bootloader_init(void);
int bootloader_secure_boot(void);

#ifdef __cplusplus
}
#endif

#endif // BOOTLOADER_H
