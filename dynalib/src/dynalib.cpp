#include "dynalib.h"
#include "rt_dynalib.h"
#include <stdio.h>

void* dynalib_load(const char* libname) {
    printf("[dynalib] Load: %s\n", libname);
    return rt_dynalib_load(libname);
}

void* dynalib_get_symbol(void* handle, const char* symbol) {
    printf("[dynalib] Get symbol: %s\n", symbol);
    return rt_dynalib_get_symbol(handle, symbol);
}

void dynalib_unload(void* handle) {
    printf("[dynalib] Unload\n");
    rt_dynalib_unload(handle);
}
