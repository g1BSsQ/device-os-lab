#include "spark_wiring_gpio.h"
#include "hal_gpio.h"
#include "delay_hal.h"

// ...existing code...

int gpioToggle(pin_t pin) {
    return hal_gpio_toggle((hal_pin_t)pin);
}

int gpioPulse(pin_t pin, uint32_t duration_ms) {
    return hal_gpio_pulse((hal_pin_t)pin, duration_ms);
}

// ...existing code...