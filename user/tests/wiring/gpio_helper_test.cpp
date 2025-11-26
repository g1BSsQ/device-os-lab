#include "spark_wiring_gpio.h"
#include "unit_test.h"

test(GPIO_Toggle) {
    pin_t testPin = D7; // Example pin
    pinMode(testPin, OUTPUT);
    digitalWrite(testPin, LOW);

    int result = gpioToggle(testPin);
    assertEqual(result, 0);
    assertEqual(digitalRead(testPin), HIGH);

    result = gpioToggle(testPin);
    assertEqual(result, 0);
    assertEqual(digitalRead(testPin), LOW);
}

test(GPIO_Pulse) {
    pin_t testPin = D7; // Example pin
    pinMode(testPin, OUTPUT);
    digitalWrite(testPin, LOW);

    int result = gpioPulse(testPin, 100); // 100ms pulse
    assertEqual(result, 0);
    assertEqual(digitalRead(testPin), LOW); // Ensure pin is LOW after pulse
}