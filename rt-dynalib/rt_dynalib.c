#include "rt_dynalib.h"
#include <stdio.h>
#include <string.h>

// Dummy implementation for embedded/no-OS
void* rt_dynalib_load(const char* libname) {
    printf("Loading dynalib: %s\n", libname);
    return (void*)libname; // Just return the name as a handle
}

void* rt_dynalib_get_symbol(void* handle, const char* symbol) {
    printf("Getting symbol: %s from %s\n", symbol, (const char*)handle);
    return NULL; // Not implemented
}

void rt_dynalib_unload(void* handle) {
    printf("Unloading dynalib: %s\n", (const char*)handle);
}
