#include "main/config.h"
#include "services/services.h"
#include "services/logger.h"
#include "system.h"
#include "bootloader.h"
#include "module_data.h"
#include "logging.h"
#include "dynalib.h"
#include <iostream>

int main() {
    HAL_Status status = HAL_SUCCESS;

    bootloader_initialize(); // Use the refactored initialization logic
    print_firmware_version();
    set_log_level(LOG_DEBUG);
    set_log_format("%TIME% [%LEVEL%] %MSG%");
    log_info("System starting...");

    try {
        void* lib = dynalib_load("example_library");
        void (*example_function)() = (void (*)())dynalib_get_symbol(lib, "example_function");
        example_function();
        dynalib_unload(lib);
    } catch (const std::exception& e) {
        log_error(std::string("Dynamic library error: ") + e.what());
        return -1;
    }

    status = system_init();
    if (status != HAL_SUCCESS) {
        log_error("System initialization failed with error code: " + std::to_string(status));
        return status;
    }

    DeviceConfig config;
    if (!config.load("device.cfg")) {
        log_warn("No config found, creating default.");
        config.set("device_id", "12345");
        config.set("mode", "default");
        config.save("device.cfg");
    }
    log_debug("Device ID: " + config.get("device_id"));
    log_debug("Mode: " + config.get("mode"));
    Service::initialize();

    // Add system health monitoring
    if (!system_health_check()) {
        log_error("System health check failed.");
        return -1;
    }

    Service::execute();
    system_kick_watchdog();
    log_info("System finished.");
    return 0;
}
