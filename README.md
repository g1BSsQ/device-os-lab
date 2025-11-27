[![CircleCI](https://circleci.com/gh/particle-iot/device-os/tree/develop.svg?style=svg)](https://circleci.com/gh/particle-iot/device-os/tree/develop)
[![License](https://img.shields.io/badge/license-LGPL--3.0-blue.svg)](LICENSE)
[![GitHub Issues](https://img.shields.io/github/issues/particle-iot/device-os.svg)](https://github.com/particle-iot/device-os/issues)
[![GitHub Stars](https://img.shields.io/github/stars/particle-iot/device-os.svg)](https://github.com/particle-iot/device-os/stargazers)

# Particle Device OS Firmware

This is the main source code repository of the Particle firmware libraries.

# Device OS

Device OS is the operating system for Particle devices. It provides a robust and secure foundation for IoT applications.

## New Features

### Power Consumption Logging
- Logs battery level and power consumption metrics.
- Helps monitor and optimize energy usage.

### Custom LED Blink Patterns
- Allows users to define and apply custom LED blink patterns.
- Useful for signaling device states or events.

### Improved Network State Transitions
- Enhances the reliability of network connectivity.
- Handles state transitions more robustly to ensure seamless operation.

## Getting Started

To get started with Device OS, follow the instructions below:

1. Clone the repository:
   ```bash
   git clone https://github.com/uniquelo05/device-os-lab.git
   ```
2. Build the project:
   ```bash
   make all
   ```
3. Flash the firmware to your device:
   ```bash
   make flash
   ```

For more details, refer to the [documentation](docs/gettingstarted.md).

## Code Examples

Check out the [Code Examples](docs/code_examples.md) for common use cases and best practices.

## Troubleshooting

If you encounter issues, refer to the [Troubleshooting Guide](docs/troubleshooting.md) for solutions to common problems.

## Contributing

We welcome contributions! Please see [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines on how to contribute to this project.

# Resources

- [Latest Release](http://github.com/particle-iot/device-os/releases/)
- [Changelog](CHANGELOG.md)

## Build System

- [Requirements/Dependencies](docs/dependencies.md)

## Application Firmware Development

- [Debugging support](docs/debugging.md)
- [make command syntax](docs/build.md)
- [Firmware API](http://docs.particle.io/)

## System Firmware Development

- [System Flags](system/system-flags.md)
- [Continuous Integration](ci/README.md)
- [Module Descriptor linking and retrieval](dynalib/src/readme.md)
- [Testing](user/tests/readme.md)
- [build test suite](build/test/readme.md)
- [System Threading](system/system-threading.md)
- [system versions and releases](system/system-versions.md)

### Modules

- [Bootloader](bootloader/README.md)
- [Cloud Communications](communication/README.md)

### Platforms

- [Virtual Device](hal/src/gcc/readme.md)
- [Starting a New Platform Hardware Abstraction Layer](hal/src/newhal/readme.md)

### CREDITS AND ATTRIBUTIONS

The firmware uses the GNU GCC toolchain for ARM Cortex-M processors, ARM's CMSIS libraries, and Arduino's implementation of Wiring.

### LICENSE

Unless stated elsewhere, file headers or otherwise, all files herein are licensed under an LGPLv3 license. For more information, please read the LICENSE file.

If you have questions about software licensing, please contact Particle [support](https://support.particle.io/).


### LICENSE FAQ

**This firmware is released under LGPL version 3, what does that mean for you?**

 * You may use this commercially to build applications for your devices!  You **DO NOT** need to distribute your object files or the source code of your Application under LGPL.  Your source code belongs to you when you build an Application using this System Firmware.

**When am I required to share my code?**

 * You are **NOT required** to share your Application Firmware or object files when linking against libraries or System Firmware licensed under LGPL.

 * If you make and distribute changes to System Firmware licensed under LGPL, you must release the source code and documentation for those changes under a LGPL license.

**Why?**

 * This license allows businesses to confidently build firmware and make devices without risk to their intellectual property, while at the same time helping the community benefit from non-proprietary contributions to the shared System Firmware.

**Questions / Concerns?**

 * Particle intends for this firmware to be commercially useful and safe for our community of makers and enterprises.  Please [Contact Us](https://support.particle.io/) if you have any questions or concerns, or if you require special licensing.

_(Note!  This FAQ isn't meant to be legal advice, if you're unsure, please consult an attorney)_


### CONTRIBUTE

Want to contribute to the Particle firmware project? Follow [this link](CONTRIBUTING.md) to find out how.

### CONNECT

Having problems or have awesome suggestions? Connect with us [here.](https://community.particle.io/)

## Tinker Application

The Tinker application provides a simple interface for interacting with the pins and features of your Particle device. It includes functions for digital and analog I/O, as well as WiFi signal strength and battery level monitoring.

### Available Functions

1. **Digital Read**
   - Reads the digital value of a pin.
   - Example:
     ```bash
     particle call <device_name> digitalread D7
     ```

2. **Digital Write**
   - Sets a pin to HIGH or LOW.
   - Example:
     ```bash
     particle call <device_name> digitalwrite D7,HIGH
     ```

3. **Analog Read**
   - Reads the analog value of a pin.
   - Example:
     ```bash
     particle call <device_name> analogread A0
     ```

4. **Analog Write**
   - Writes an analog value (PWM) to a pin.
   - Example:
     ```bash
     particle call <device_name> analogwrite D0,128
     ```

5. **WiFi Signal Strength**
   - Retrieves the current WiFi signal strength in dBm.
   - Example:
     ```bash
     particle call <device_name> wifiSignal
     ```

6. **Battery Level**
   - Retrieves the current battery level as a percentage.
   - Example:
     ```bash
     particle call <device_name> batteryLevel
     ```

### Notes
- Ensure your device is connected to the Particle Cloud before using these functions.
- For more details, refer to the inline comments in the source code.

## I2C Scanner Utility

The I2C scanner utility allows you to detect devices connected to the I2C bus. It scans all valid I2C addresses and returns the addresses of the detected devices.

### Usage Example

```cpp
#include "spark_wiring_i2c.h"

void setup() {
    uint8_t addresses[10];
    int count = I2CScan(addresses, 10);

    if (count > 0) {
        for (int i = 0; i < count; i++) {
            Serial.printf("Found device at address: 0x%02X\n", addresses[i]);
        }
    } else {
        Serial.println("No I2C devices found.");
    }
}

void loop() {
    // Your code here
}
```

## Performance Improvements

### Optimized String Operations
- Improved `String::concat` for efficient concatenation.
- Added optimized `String::substring` for extracting substrings.
- Enhanced `Print::print` for better handling of `String` objects.

### Usage Examples

#### String Concatenation
```cpp
String str("Hello");
str.concat(" World");
Serial.println(str); // Output: Hello World
```

#### String Substring
```cpp
String str("Hello World");
String sub = str.substring(6, 11);
Serial.println(sub); // Output: World
```

#### Printing Strings
```cpp
String str("Hello World");
Serial.print(str); // Output: Hello World
```

## ADC Calibration Process

Analog-to-Digital Converter (ADC) calibration ensures accurate analog readings by compensating for hardware variations. This process is essential for applications requiring precise analog measurements.

### When to Calibrate
- After manufacturing or hardware changes.
- When using a new device for the first time.
- Periodically, to maintain accuracy over time.

### How to Calibrate
1. Use the `adcCalibrate()` function provided in the wiring API.
2. Ensure the ADC input pins are in a known state (e.g., connected to ground or a reference voltage).
3. Call the function in your setup code:

```cpp
#include "spark_wiring_adc.h"

void setup() {
    if (adcCalibrate()) {
        Serial.println("ADC Calibration Successful");
    } else {
        Serial.println("ADC Calibration Failed");
    }
}

void loop() {
    // Your code here
}
```

### Notes
- Calibration may take a few seconds to complete.
- Ensure stable power supply during calibration.
- Refer to the detailed guide in `docs/adc_calibration.md` for more information.

## Cloud Reconnection Retry Logic

This feature introduces retry logic for reconnecting to the cloud in case of disconnection. It attempts to reconnect multiple times with a fixed interval between attempts.

### Configuration
- **Maximum Retries**: 5
- **Retry Interval**: 5000 ms (5 seconds)

### Usage Example

```cpp
#include "system_cloud.h"

void setup() {
    cloud_reconnection_init();
    if (cloud_reconnect_with_retry()) {
        Serial.println("Reconnected to the cloud successfully.");
    } else {
        Serial.println("Failed to reconnect to the cloud.");
    }
}

void loop() {
    // Your code here
}
```
