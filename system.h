#ifndef SYSTEM_H
#define SYSTEM_H

#include "hal/hal_platform.h"
#include "logging.h"
#include "bootloader.h"
#include "crypto.h"
#include "hal/hal_thread.h"

#ifdef __cplusplus
extern "C" {
#endif

void system_init(void);
void system_kick_watchdog(void);
void system_stop_watchdog(void);
void system_secure_boot(void);

// System health monitoring
bool system_health_check(void);
void execute_with_watchdog(const std::function<void()>& task);

#ifdef __cplusplus
}
#endif

#endif // SYSTEM_H
