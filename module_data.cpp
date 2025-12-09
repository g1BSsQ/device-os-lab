#include "module_data.h"
#include "bootloader.h"
#include <string>
#include <iostream>

bool validate_firmware_version(const FirmwareVersion& version) {
    return version.major >= 0 && version.minor >= 0 && version.patch >= 0;
}

std::string get_firmware_version_string() {
    FirmwareVersion v = bootloader_get_version();
    if (!validate_firmware_version(v)) {
        return "Invalid Version";
    }
    return "v" + std::to_string(v.major) + "." + std::to_string(v.minor) + "." + std::to_string(v.patch);
}

void print_firmware_version() {
    std::cout << "Firmware Version: " << get_firmware_version_string() << std::endl;
}
