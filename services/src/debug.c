/*
 * debug.c
 *
 *  Created on: Jan 31, 2014
 *      Author: david_s5
 */

#include "debug.h"
#include "logging.h"

#if defined(DEBUG_BUILD)
#define LOG_LEVEL_AT_RUN_TIME LOG_LEVEL
#endif

#if defined(RELEASE_BUILD)
#define LOG_LEVEL_AT_RUN_TIME ERROR_LEVEL
#endif

LoggerOutputLevel log_compat_level = LOG_LEVEL_AT_RUN_TIME;
debug_output_fn log_compat_callback = NULL;

thread_current_fn system_thread_current_ = NULL;
thread_current_fn main_thread_current_ = NULL;
thread_current_fn application_thread_current_ = NULL;

void set_logger_output(debug_output_fn output, LoggerOutputLevel level) {
    if (level == DEFAULT_LEVEL) {
        level = LOG_LEVEL_AT_RUN_TIME;
    }
    log_compat_level = level;
    log_compat_callback = output;
}

void log_message(int level, const char *format, ...) {
    if (level <= log_compat_level && log_compat_callback) {
        va_list args;
        va_start(args, format);
        log_compat_callback(format, args);
        va_end(args);
    }
}

void set_thread_current_function_pointers(void* c1, void* c2, void* c3, void* c4, void* c5) {
    (void)c4;
    (void)c5;
    main_thread_current_ = (thread_current_fn)c1;
    system_thread_current_ = (thread_current_fn)c2;
    application_thread_current_ = (thread_current_fn)c3;
}
