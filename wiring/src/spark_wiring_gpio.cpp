#include "spark_wiring_gpio.h"
#include "hal_gpio.h"
#include "delay_hal.h"

// ...existing code...

int gpioToggle(pin_t pin) {
    if (pin >= TOTAL_PINS) {
        return -1;  // Invalid pin
    }
    return hal_gpio_toggle((hal_pin_t)pin);
}

int gpioPulse(pin_t pin, uint32_t duration_ms) {
    if (pin >= TOTAL_PINS || duration_ms == 0 || duration_ms > 60000) {
        return -1;  // Invalid pin or duration (max 60 seconds)
    }
    return hal_gpio_pulse((hal_pin_t)pin, duration_ms);
}

// ...existing code...