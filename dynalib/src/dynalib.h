#ifndef DYNALIB_H
#define DYNALIB_H

#ifdef __cplusplus
extern "C" {
#endif

// High-level dynalib API
void* dynalib_load(const char* libname);
void* dynalib_get_symbol(void* handle, const char* symbol);
void dynalib_unload(void* handle);

#ifdef __cplusplus
}
#endif

#endif // DYNALIB_H
