#include "main/config.h"
#include "services/services.h"
#include "services/logger.h"
#include "system.h"
#include "bootloader.h"
#include "module_data.h"
#include "logging.h"
#include "dynalib.h"
#include "communication/protocol.h"
#include "hal/watchdog.h"
#include "config/config.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <functional>
#include <future>

void execute_with_watchdog(const std::function<void()>& task) {
    try {
        watchdog_start(5000);
        task();
        watchdog_stop();
    } catch (const std::exception& e) {
        log_error(std::string("Task failed: ") + e.what());
        watchdog_stop();
        throw;
    }
}

int main() {
    HAL_Status status = HAL_SUCCESS;

    Config config;
    if (!config.load("config.json")) {
        log_error("Failed to load configuration file.");
        return -1;
    }

    std::string log_level = config.get("log_level", "INFO");
    if (log_level == "DEBUG") {
        set_log_level(LOG_DEBUG);
    } else if (log_level == "INFO") {
        set_log_level(LOG_INFO);
    } else if (log_level == "WARN") {
        set_log_level(LOG_WARN);
    } else if (log_level == "ERROR") {
        set_log_level(LOG_ERROR);
    }

    set_log_format("%TIME% [%LEVEL%] %MSG%");
    log_info("Configuration loaded successfully.");

    bootloader_initialize(); // Use the refactored initialization logic
    print_firmware_version();
    log_info("System starting...");

    auto protocol_task = std::async(std::launch::async, []() {
        Protocol protocol;
        protocol.initialize();
        protocol.send("Hello, Protocol!");
        std::string response = protocol.receive();
        log_info("Protocol response: " + response);
    });

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

    DeviceConfig device_config;
    if (!device_config.load("device.cfg")) {
        log_error("Failed to load device configuration.");
        return -1;
    }

    log_info("System initialized successfully.");

    // Ensure the protocol task completes before exiting
    protocol_task.wait();

    return 0;
}
