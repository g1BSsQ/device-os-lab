# Troubleshooting Guide

This guide provides solutions to common issues encountered while working with Device OS.

## Common Issues

### 1. Build Failures
**Symptoms:**
- Compilation errors during the build process.
- Missing dependencies or tools.

**Solutions:**
- Ensure all required tools are installed (e.g., GCC, Make).
- Run the following command to install dependencies:
  ```bash
  ./ci/install_boost.sh
  ```
- Check the `build/` directory for detailed logs.

### 2. Device Not Connecting to Network
**Symptoms:**
- Device fails to connect to Wi-Fi or cellular network.
- Network state stuck in `DISCONNECTED`.

**Solutions:**
- Verify network credentials are correct.
- Check if the network is available and has sufficient signal strength.
- Use the following command to reset network settings:
  ```bash
  particle device wifi
  ```

### 3. LED Blink Patterns Not Working
**Symptoms:**
- Custom LED patterns are not applied.
- LED remains off or blinks unexpectedly.

**Solutions:**
- Ensure the pattern string is valid (e.g., `"1010"` for on/off sequence).
- Check the `spark_wiring_led.cpp` file for errors.

### 4. Power Consumption Logs Missing
**Symptoms:**
- No logs related to power consumption appear.
- Battery level always shows `-1`.

**Solutions:**
- Verify the device is running on battery power.
- Check the `spark_wiring_power.cpp` file for issues.

### 5. Common Error Codes
**Error Code: -1 (SYSTEM_ERROR_UNKNOWN)**
- General unknown error
- Check device logs for more details

**Error Code: -2 (SYSTEM_ERROR_BUSY)**
- System is busy processing another operation
- Wait and retry the operation

**Error Code: -3 (SYSTEM_ERROR_NOT_SUPPORTED)**
- Feature not supported on this device
- Check device capabilities

**Error Code: -4 (SYSTEM_ERROR_INVALID_ARGUMENT)**
- Invalid argument passed to function
- Verify function parameters

## Debugging Tips
- Use the `Log.info()` function to add debug logs in the code.
- Check the `logs/` directory for runtime logs.
- Use the Particle CLI for device diagnostics:
  ```bash
  particle device doctor
  ```
- Enable verbose logging with `Log.level(LOG_LEVEL_ALL)`
- Use `Serial.println()` for immediate console output during development

## Additional Resources
- [Debugging Guide](debugging.md) - Comprehensive debugging documentation
- [Build Documentation](build.md) - Build system troubleshooting
- [Community Forum](https://community.particle.io/) - Ask questions and get help

## Contact Support
If the issue persists, please contact the support team with the following information:
- Device model and OS version.
- Steps to reproduce the issue.
- Relevant logs or error messages.