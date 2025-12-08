#ifndef SERVICES_H
#define SERVICES_H

#include "logger.h"
#include "sync.h"

class Service {
public:
    static void initialize();
    static void execute();
};

#endif // SERVICES_H