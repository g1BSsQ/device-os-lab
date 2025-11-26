#pragma once

#include "application.h"

/**
 * @brief Initializes the GPIO pin.
 * 
 * @param pin The GPIO pin to initialize.
 * @param mode The mode to set for the pin (INPUT, OUTPUT, etc.).
 * @return int 0 on success, negative value on failure.
 */
int gpioInit(pin_t pin, int mode);

/**
 * @brief Reads the state of a GPIO pin.
 * 
 * @param pin The GPIO pin to read.
 * @return int The state of the pin (HIGH or LOW), negative value on failure.
 */
int gpioRead(pin_t pin);

/**
 * @brief Writes a state to a GPIO pin.
 * 
 * @param pin The GPIO pin to write to.
 * @param state The state to write to the pin (HIGH or LOW).
 * @return int 0 on success, negative value on failure.
 */
int gpioWrite(pin_t pin, int state);

/**
 * @brief Toggles the state of a GPIO pin.
 * 
 * @param pin The GPIO pin to toggle.
 * @return int 0 on success, negative value on failure.
 */
int gpioToggle(pin_t pin);

/**
 * @brief Sets a GPIO pin to HIGH for a specified duration, then LOW.
 * 
 * @param pin The GPIO pin to pulse.
 * @param duration_ms The duration of the pulse in milliseconds.
 * @return int 0 on success, negative value on failure.
 */
int gpioPulse(pin_t pin, uint32_t duration_ms);