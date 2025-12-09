#ifndef SYSTEM_H
#define SYSTEM_H

#include "hal/hal_platform.h"

#ifdef __cplusplus
extern "C" {
#endif

void system_init(void);
void system_kick_watchdog(void);
void system_stop_watchdog(void);

#ifdef __cplusplus
}
#endif

#endif // SYSTEM_H
