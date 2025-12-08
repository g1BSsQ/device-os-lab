#include "system.h"
#include "platform/watchdog.h"

void system_init(void) {
    watchdog_init(5000); // 5 seconds timeout
}

void system_kick_watchdog(void) {
    watchdog_kick();
}

void system_stop_watchdog(void) {
    watchdog_stop();
}
