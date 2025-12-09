#ifndef MODULE_DATA_H
#define MODULE_DATA_H

#include <string>
#include "bootloader.h"

bool validate_firmware_version(const FirmwareVersion& version);
std::string get_firmware_version_string();
void print_firmware_version();

#endif // MODULE_DATA_H
