#include "main/config.h"
#include "services/services.h"
#include "system.h"
#include <iostream>

int main() {
    system_init();
    DeviceConfig config;
    if (!config.load("device.cfg")) {
        std::cout << "No config found, creating default." << std::endl;
        config.set("device_id", "12345");
        config.set("mode", "default");
        config.save("device.cfg");
    }
    std::cout << "Device ID: " << config.get("device_id") << std::endl;
    std::cout << "Mode: " << config.get("mode") << std::endl;
    Service::initialize();
    Service::execute();
    system_kick_watchdog();
    return 0;
}
