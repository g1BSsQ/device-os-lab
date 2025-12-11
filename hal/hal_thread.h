#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Creates a new thread.
 * @param thread_func The function to execute in the thread.
 * @param name The name of the thread.
 */
void hal_thread_create(void (*thread_func)(void), const char* name);

#ifdef __cplusplus
}
#endif
