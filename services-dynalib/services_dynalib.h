#ifndef SERVICES_DYNALIB_H
#define SERVICES_DYNALIB_H

#include "logging.h"

class DynamicService {
public:
    static void load();
    static void unload();
};

#endif // SERVICES_DYNALIB_H