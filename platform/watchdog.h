#ifndef WATCHDOG_H
#define WATCHDOG_H

#ifdef __cplusplus
extern "C" {
#endif

void watchdog_init(unsigned int timeout_ms);
void watchdog_kick(void);
void watchdog_stop(void);

#ifdef __cplusplus
}
#endif

#endif // WATCHDOG_H
