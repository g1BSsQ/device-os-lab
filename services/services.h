#ifndef SERVICES_H
#define SERVICES_H

#include "logger.h"
#include "sync.h"
#include "main/config.h"

class Service {
public:
    static void initialize();
    static void execute();
    // Device configuration management
    static DeviceConfig& config();
};

#endif // SERVICES_H