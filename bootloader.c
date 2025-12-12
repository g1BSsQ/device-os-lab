#include "bootloader.h"
#include "system.h"
#include "crypto.h"
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

void bootloader_secure_boot(void) {
    const char* boot_key = "secure_boot_key";
    const char* boot_signature = "boot_signature";

    if (!crypto_verify_signature(boot_key, boot_signature)) {
        printf("Secure boot failed: Invalid signature\n");
        while (1) {
            // Halt the system
        }
    }

    printf("Secure boot passed\n");
}

void bootloader_init(void) {
    if (system_init() != 0) {
        printf("Error: System initialization failed\n");
        return;
    }

    if (!bootloader_secure_boot()) {
        printf("Error: Secure boot failed\n");
        return;
    }

    bootloader_fast_init();
    bootloader_print_version();
}
