#include "module_data.h"
#include "bootloader.h"
#include <string>
#include <iostream>
#include <fstream>

/**
 * @brief Validates the firmware version.
 *
 * This function checks if the firmware version is valid by ensuring
 * that the major, minor, and patch versions are non-negative.
 *
 * @param version The firmware version to validate.
 * @return true if the version is valid, false otherwise.
 */
bool validate_firmware_version(const FirmwareVersion& version) {
    return version.major >= 0 && version.minor >= 0 && version.patch >= 0;
}

/**
 * @brief Retrieves the firmware version as a string.
 *
 * This function fetches the firmware version from the bootloader and
 * converts it into a human-readable string format.
 *
 * @return A string representation of the firmware version.
 */
std::string get_firmware_version_string() {
    FirmwareVersion v = bootloader_get_version();
    if (!validate_firmware_version(v)) {
        return "Invalid Version";
    }
    return "v" + std::to_string(v.major) + "." + std::to_string(v.minor) + "." + std::to_string(v.patch);
}

/**
 * @brief Prints the firmware version to the console.
 *
 * This function retrieves the firmware version and prints it to the
 * standard output for debugging or informational purposes.
 */
void print_firmware_version() {
    std::cout << "Firmware Version: " << get_firmware_version_string() << std::endl;
}

/**
 * @brief Loads module data from a file.
 *
 * This function reads module data from the specified file and populates
 * the provided ModuleData structure. It handles file opening, reading,
 * and error reporting.
 *
 * @param filePath The path to the module data file.
 * @param data The ModuleData structure to populate.
 * @return true if the data was loaded successfully, false otherwise.
 */
bool load_module_data(const std::string& filePath, ModuleData& data) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open module data file: " << filePath << std::endl;
        return false;
    }

    try {
        // Example parsing logic
        file >> data;
    } catch (const std::exception& e) {
        std::cerr << "Error: Failed to parse module data. Exception: " << e.what() << std::endl;
        return false;
    }

    file.close();
    return true;
}

/**
 * @brief Performs a system health check.
 *
 * This function performs a basic health check of the system and logs
 * the result. It is a placeholder for more comprehensive diagnostics.
 *
 * @return true if the system is healthy, false otherwise.
 */
bool system_health_check() {
    // Example health check logic
    std::cout << "Performing system health check..." << std::endl;
    return true; // Assume the system is healthy
}

static ModuleVersion currentModuleVersion = {1, 0, 0};

/**
 * @brief Sets the module version.
 *
 * This function sets the module version to the specified major, minor,
 * and patch values.
 *
 * @param major The major version number.
 * @param minor The minor version number.
 * @param patch The patch version number.
 */
void set_module_version(int major, int minor, int patch) {
    currentModuleVersion.major = major;
    currentModuleVersion.minor = minor;
    currentModuleVersion.patch = patch;
}

/**
 * @brief Retrieves the current module version.
 *
 * This function returns the current module version as a ModuleVersion
 * structure.
 *
 * @return The current module version.
 */
ModuleVersion get_module_version() {
    return currentModuleVersion;
}

/**
 * @brief Retrieves the module version as a string.
 *
 * This function converts the current module version into a human-readable
 * string format.
 *
 * @return A string representation of the module version.
 */
std::string get_module_version_string() {
    return "v" + std::to_string(currentModuleVersion.major) + "." +
           std::to_string(currentModuleVersion.minor) + "." +
           std::to_string(currentModuleVersion.patch);
}

/**
 * @brief Prints the module version to the console.
 *
 * This function retrieves the module version and prints it to the
 * standard output for debugging or informational purposes.
 */
void print_module_version() {
    std::cout << "Module Version: " << get_module_version_string() << std::endl;
}
