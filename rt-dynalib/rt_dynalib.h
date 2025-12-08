#ifndef RT_DYNALIB_H
#define RT_DYNALIB_H

#ifdef __cplusplus
extern "C" {
#endif

// Load a dynamic library at runtime
void* rt_dynalib_load(const char* libname);
// Get a symbol from a loaded library
void* rt_dynalib_get_symbol(void* handle, const char* symbol);
// Unload a dynamic library
void rt_dynalib_unload(void* handle);

#ifdef __cplusplus
}
#endif

#endif // RT_DYNALIB_H
