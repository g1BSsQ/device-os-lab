#pragma once

#include <stdint.h>
#include "hal_platform.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initializes the GPIO pin.
 * 
 * @param pin The GPIO pin to initialize.
 * @param direction The direction of the GPIO pin (input or output).
 * @return int 0 on success, negative value on failure.
 */
int hal_gpio_init(hal_pin_t pin, hal_gpio_direction_t direction);

/**
 * @brief Deinitializes the GPIO pin.
 * 
 * @param pin The GPIO pin to deinitialize.
 * @return int 0 on success, negative value on failure.
 */
int hal_gpio_deinit(hal_pin_t pin);

/**
 * @brief Reads the current state of a GPIO pin.
 * 
 * @param pin The GPIO pin to read.
 * @param value Pointer to store the read value (0 or 1).
 * @return int 0 on success, negative value on failure.
 */
int hal_gpio_read(hal_pin_t pin, uint8_t *value);

/**
 * @brief Writes a value to a GPIO pin.
 * 
 * @param pin The GPIO pin to write to.
 * @param value The value to write (0 or 1).
 * @return int 0 on success, negative value on failure.
 */
int hal_gpio_write(hal_pin_t pin, uint8_t value);

/**
 * @brief Toggles the state of a GPIO pin.
 * 
 * @param pin The GPIO pin to toggle.
 * @return int 0 on success, negative value on failure.
 */
int hal_gpio_toggle(hal_pin_t pin);

/**
 * @brief Sets a GPIO pin to HIGH for a specified duration, then LOW.
 * 
 * @param pin The GPIO pin to pulse.
 * @param duration_ms The duration of the pulse in milliseconds.
 * @return int 0 on success, negative value on failure.
 */
int hal_gpio_pulse(hal_pin_t pin, uint32_t duration_ms);

#ifdef __cplusplus
}
#endif