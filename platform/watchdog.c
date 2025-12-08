#include "watchdog.h"
#include <stdio.h>
#include <time.h>

static unsigned int wd_timeout = 0;
static time_t wd_last_kick = 0;
static int wd_active = 0;

void watchdog_init(unsigned int timeout_ms) {
    wd_timeout = timeout_ms;
    wd_last_kick = time(NULL);
    wd_active = 1;
    printf("Watchdog initialized with timeout %u ms\n", timeout_ms);
}

void watchdog_kick(void) {
    if (wd_active) {
        wd_last_kick = time(NULL);
        printf("Watchdog kicked\n");
    }
}

void watchdog_stop(void) {
    wd_active = 0;
    printf("Watchdog stopped\n");
}
