#ifndef BOOTLOADER_H
#define BOOTLOADER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int major;
    int minor;
    int patch;
} FirmwareVersion;

void bootloader_set_version(int major, int minor, int patch);
FirmwareVersion bootloader_get_version(void);
void bootloader_print_version(void);
void bootloader_init(void);

#ifdef __cplusplus
}
#endif

#endif // BOOTLOADER_H
