#ifndef SERVICES_H
#define SERVICES_H

#include "logging.h"

class Service {
public:
    static void initialize();
    static void execute();
};

#endif // SERVICES_H