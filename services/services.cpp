#include "services.h"
#include "services-dynalib/services_dynalib.h"
#include "logger.h"
#include "main/config.h"
#include <mutex>


// Mutex for thread-safe service operations
std::mutex service_mutex;

static DeviceConfig service_config;

DeviceConfig& Service::config() {
    return service_config;
}

void Service::initialize() {
    sync_lock();
    // Initialize service components
    service_config.load("device.cfg");
    log_info("Service initialized successfully.");
    sync_unlock();
}

void Service::execute() {
    sync_lock();
    // Example: update config
    service_config.set("last_run", "executed");
    service_config.save("device.cfg");
    log_info("Service executed successfully.");
    sync_unlock();
}