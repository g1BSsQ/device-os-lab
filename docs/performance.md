# Performance Optimization Guide

## Overview

This document provides guidelines for optimizing performance in Device OS applications.

## Table of Contents

1. [Memory Optimization](#memory-optimization)
2. [CPU Optimization](#cpu-optimization)
3. [Power Optimization](#power-optimization)
4. [Network Optimization](#network-optimization)
5. [Storage Optimization](#storage-optimization)

## Memory Optimization

### Check Available Memory

```cpp
void setup() {
    Serial.printlnf("Free memory: %d bytes", System.freeMemory());
}
```

### Best Practices

1. **Use `const` for read-only data**
```cpp
const char* const DEVICE_NAME = "MyDevice";  // Stored in flash, not RAM
```

2. **Avoid dynamic allocation in loops**
```cpp
// Bad
void loop() {
    String msg = "Hello";  // Allocates every loop
}

// Good
String msg;
void loop() {
    msg = "Hello";  // Reuses existing allocation
}
```

3. **Use stack allocation when possible**
```cpp
// Bad - heap allocation
char* buffer = new char[100];

// Good - stack allocation
char buffer[100];
```

4. **Free unused objects**
```cpp
String* data = new String("large data");
// ... use data ...
delete data;
data = nullptr;
```

## CPU Optimization

### Minimize Serial Output

```cpp
// Bad - prints every loop iteration
void loop() {
    Serial.println("Running...");
    delay(1);
}

// Good - prints periodically
void loop() {
    static unsigned long lastPrint = 0;
    if (millis() - lastPrint > 1000) {
        Serial.println("Running...");
        lastPrint = millis();
    }
}
```

### Use Interrupts for Time-Critical Tasks

```cpp
volatile bool buttonPressed = false;

void buttonHandler() {
    buttonPressed = true;
}

void setup() {
    attachInterrupt(D2, buttonHandler, FALLING);
}

void loop() {
    if (buttonPressed) {
        buttonPressed = false;
        // Handle button press
    }
}
```

### Optimize Loop Performance

```cpp
// Bad - multiple function calls
void loop() {
    if (digitalRead(D2) == HIGH && digitalRead(D3) == HIGH) {
        // ...
    }
}

// Good - cache values
void loop() {
    bool d2 = digitalRead(D2);
    bool d3 = digitalRead(D3);
    if (d2 && d3) {
        // ...
    }
}
```

## Power Optimization

### Use Sleep Modes

```cpp
// Sleep for 60 seconds
SystemSleepConfiguration config;
config.mode(SystemSleepMode::STOP)
      .duration(60s);
System.sleep(config);
```

### Disable Unused Peripherals

```cpp
// Disable WiFi when not needed
WiFi.off();

// Disable serial when not debugging
Serial.end();
```

### Optimize Sensor Reading Frequency

```cpp
void loop() {
    static unsigned long lastRead = 0;
    
    // Read sensor every 5 seconds instead of continuously
    if (millis() - lastRead > 5000) {
        int value = analogRead(A0);
        // Process value
        lastRead = millis();
    }
}
```

## Network Optimization

### Batch Cloud Publications

```cpp
// Bad - publish frequently
void loop() {
    Particle.publish("temp", String(temp));
    delay(100);
}

// Good - batch and rate limit
void loop() {
    static unsigned long lastPublish = 0;
    static String dataBuffer;
    
    dataBuffer += String(temp) + ",";
    
    if (millis() - lastPublish > 60000) {
        Particle.publish("data", dataBuffer);
        dataBuffer = "";
        lastPublish = millis();
    }
}
```

### Use Webhooks for External APIs

Instead of HTTP requests from device, use Particle webhooks to reduce device processing.

### Optimize Payload Size

```cpp
// Bad - verbose JSON
Particle.publish("data", "{\"temperature\":25,\"humidity\":60}");

// Good - compact format
Particle.publish("data", "25,60");
```

## Storage Optimization

### Use EEPROM Efficiently

```cpp
// Write only when value changes
int lastValue = -1;
void saveValue(int value) {
    if (value != lastValue) {
        EEPROM.put(0, value);
        lastValue = value;
    }
}
```

### Compress Data Before Storage

```cpp
// Store booleans as bit flags
uint8_t flags = 0;
flags |= (sensor1Active << 0);
flags |= (sensor2Active << 1);
flags |= (alarmEnabled << 2);
EEPROM.write(0, flags);
```

## Profiling Tools

### Measure Execution Time

```cpp
void measurePerformance() {
    unsigned long start = micros();
    
    // Code to measure
    performTask();
    
    unsigned long duration = micros() - start;
    Serial.printlnf("Execution time: %lu microseconds", duration);
}
```

### Monitor System Health

```cpp
void loop() {
    static unsigned long lastCheck = 0;
    
    if (millis() - lastCheck > 10000) {
        Serial.printlnf("Free memory: %d", System.freeMemory());
        Serial.printlnf("Uptime: %lu", millis() / 1000);
        lastCheck = millis();
    }
}
```

## See Also

- [Debugging Guide](debugging.md)
- [Code Examples](code_examples.md)
- [Best Practices](STYLE_GUIDE.md)
