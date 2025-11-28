# Hardware Support

## Supported Platforms

### WiFi Devices

- Photon
- P1
- Argon

### Cellular Devices

- Electron
- E-Series
- Boron
- B-Series

### Tracker

- Tracker One
- Tracker SoM

## Pin Mappings

### Photon/P1

- D0-D7: Digital I/O
- A0-A7: Analog Input
- DAC: A6 (DAC1), A3 (DAC2)
- PWM: D0, D1, D2, D3, A4, A5, WKP, RX, TX

### Boron

- D0-D8: Digital I/O
- A0-A5: Analog Input
- PWM: D2, D3, D4, D5, D6, D7, A0, A1

## Communication Interfaces

### I2C

- Wire (D0/D1)
- Wire1 (D2/D3) - select devices

### SPI

- SPI (A2-A5)
- SPI1 - select devices

### UART

- Serial1 (TX/RX)
- Serial2 - select devices

## Power Requirements

### Input Voltage

- USB: 5V
- VIN: 3.6V - 5.5V (Photon)
- Li-Po: 3.7V (Boron, Electron)

### Current Draw

- Active (WiFi): ~80mA
- Active (Cellular): ~180mA
- Sleep: <1mA
- Deep Sleep: <100µA

## Hardware Setup Guide

### General Setup Instructions

1. **Power Supply**: Ensure the device is connected to a stable power source.
2. **Pin Connections**: Verify all pin connections are secure and match the pin mappings provided above.
3. **Firmware Installation**: Flash the latest firmware using the Particle CLI or Workbench.
4. **Network Configuration**: Configure WiFi or Cellular settings as per the device type.

### Troubleshooting Tips

- **Device Not Powering On**: Check the power supply and USB cable.
- **No Network Connectivity**: Verify network credentials and signal strength.
- **Pin Mapping Issues**: Double-check the pin mappings for your specific device model.

## See Also

- [Pin Diagrams](https://docs.particle.io/)
- [Datasheets](https://docs.particle.io/datasheets/)
