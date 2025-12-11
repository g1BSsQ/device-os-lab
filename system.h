#ifndef SYSTEM_H
#define SYSTEM_H

#include "hal/hal_platform.h"
#include "logging.h"
#include "bootloader.h"

#ifdef __cplusplus
extern "C" {
#endif

void system_init(void);
void system_kick_watchdog(void);
void system_stop_watchdog(void);

// System health monitoring
bool system_health_check(void);

#ifdef __cplusplus
}
#endif

#endif // SYSTEM_H
