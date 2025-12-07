#include "hal_gpio.h"
#include "hal_pinmap.h"
#include "delay_hal.h"

// ...existing code...

int hal_gpio_toggle(hal_pin_t pin) {
    if (!hal_pin_validate(pin)) {
        return -1; // Invalid pin
    }
    pinMode(pin, OUTPUT);
    digitalWrite(pin, !digitalRead(pin)); // Toggle the pin state
    return 0;
}

int hal_gpio_pulse(hal_pin_t pin, uint32_t duration_ms) {
    if (!hal_pin_validate(pin) || duration_ms == 0) {
        return -1;  // Invalid pin or duration
    }
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    HAL_Delay_Milliseconds(duration_ms); // Pulse duration
    digitalWrite(pin, LOW);
    return 0;
}

// ...existing code...