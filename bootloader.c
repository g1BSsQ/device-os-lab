#include "bootloader.h"
#include "system.h"
#include <stdio.h>
#include <stdalign.h>

static alignas(4) FirmwareVersion current_fw_version = {1, 0, 0};

void bootloader_set_version(int major, int minor, int patch) {
    current_fw_version.major = major;
    current_fw_version.minor = minor;
    current_fw_version.patch = patch;
}

FirmwareVersion bootloader_get_version(void) {
    return current_fw_version;
}

void bootloader_print_version(void) {
    printf("Firmware Version: v%d.%d.%d\n", current_fw_version.major, current_fw_version.minor, current_fw_version.patch);
}

void bootloader_fast_init(void) {
    // Fast initialization path for reduced startup time
    bootloader_set_version(1, 0, 0);
}

void bootloader_init(void) {
    system_init();
    bootloader_fast_init();
    bootloader_print_version();
}
