#include "dynalib.h"
#include "rt_dynalib.h"
#include <stdio.h>
#include <stdexcept>

void* dynalib_load(const char* libname) {
    printf("[dynalib] Load: %s\n", libname);
    void* handle = rt_dynalib_load(libname);
    if (!handle) {
        throw std::runtime_error("Failed to load library: " + std::string(libname));
    }
    return handle;
}

void* dynalib_get_symbol(void* handle, const char* symbol) {
    printf("[dynalib] Get symbol: %s\n", symbol);
    void* sym = rt_dynalib_get_symbol(handle, symbol);
    if (!sym) {
        throw std::runtime_error("Failed to get symbol: " + std::string(symbol));
    }
    return sym;
}

void dynalib_unload(void* handle) {
    printf("[dynalib] Unload\n");
    rt_dynalib_unload(handle);
}
