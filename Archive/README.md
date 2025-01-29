# PPMastermind

# Project: Teensy-Based RC Transmitter Emulator with PWM Control

## Overview
This project uses a **Teensy 4.1 microcontroller** to emulate an RC transmitter by generating and processing PWM signals. The system integrates an **Archer Plus SR8 receiver** and rotary potentiometers for manual adjustments to stabilization gains and flight modes. It is designed for advanced RC applications, including testing and calibration of servos and simulating flight dynamics.

---

## Features
- Reads inputs from up to **4 potentiometers** for real-time gain control (Pitch, Roll, Yaw, Throttle).
- Generates **PWM signals** compatible with most RC receivers, including the Archer Plus SR8.
- Supports **dynamic flight mode selection** via switches.
- Includes **data logging** to an SD card for debugging and performance tracking.
- Provides compatibility with **Lua scripts** for further customization on FrSky X20S transmitters.

---

## Hardware Components
1. **Teensy 4.1** (Microcontroller for signal processing)
2. **Rotary Potentiometers (4)** (Input control for Pitch, Roll, Yaw, and Throttle)
3. **Archer Plus SR8 Receiver** (PWM-compatible receiver with integrated gyro)
4. **Power Supply (5V, 5A)** (For Teensy, potentiometers, and servos)
5. **Servos (Control Surfaces)** (For stabilization and testing)
6. Optional: **SD Card Module** (For data logging)

---

## Wiring Diagram
### Connections:
- **Potentiometers**:
  - Left Pin: **GND**
  - Middle Pin: **Analog Input** (A0, A1, A2, A3)
  - Right Pin: **3.3V**
- **Teensy**:
  - PWM Outputs: Digital Pins (e.g., 6, 7, 8, 9)
  - Potentiometer Inputs: A0, A1, A2, A3
  - GND: Common ground with power supply and receiver
  - 5V: Shared with receiver (via power supply)
- **Archer Plus SR8**:
  - PWM Inputs: Teensy Digital Pins (as configured)
  - GND: Common ground
- **Servos**:
  - Signal Wires: From SR8 to each servo channel (CH1, CH2, etc.)
  - Power: External 5V power supply
  - GND: Common ground with receiver

---

## Software Setup
### Required Libraries
- **Servo.h**: For PWM signal generation. [Install Servo.h](https://www.arduino.cc/reference/en/libraries/servo/)
- **SD.h**: For data logging. [Install SD.h](https://www.arduino.cc/reference/en/libraries/sd/)

### Arduino IDE Configuration
1. Install the **Teensyduino** add-on. [Get Teensyduino](https://www.pjrc.com/teensy/teensyduino.html)
2. Select the board: `Teensy 4.1`.
3. Choose the appropriate COM port.

---

## Code Overview
### 1. **Potentiometer Input Reading**
- Reads analog values from potentiometers.
- Maps values to the appropriate range for gain adjustments and PWM outputs.

### 2. **PWM Signal Processing**
- Dynamically adjusts PWM signals based on potentiometer values.
- Outputs the adjusted PWM signals to the Archer Plus SR8 or servos directly.

### 3. **Debugging and Data Logging**
- Logs potentiometer values and PWM outputs to an SD card or serial monitor.

### 4. **Lua Script Integration**
- Provides additional functionality for FrSky X20S transmitters.

---

## Example Usage
1. **Connect the Hardware**:
   - Wire the potentiometers, Teensy, servos, and receiver as per the wiring diagram.
2. **Upload the Code**:
   - Use the Arduino IDE to upload the provided code to the Teensy.
3. **Monitor Data**:
   - Use the serial monitor or check the SD card logs for debugging.
4. **Test Receiver Integration**:
   - Connect PWM outputs to the Archer Plus SR8 and verify servo responses.

---

## Troubleshooting
1. **PWM Signal Not Detected**:
   - Ensure the Teensy and receiver share a common ground.
   - Verify the PWM output pins are correctly connected.
2. **Incorrect Channel Responses**:
   - Check the potentiometer connections.
   - Verify the mapping ranges in the code.
3. **Power Issues**:
   - Use a sufficient 5V power supply (at least 5A for stable operation).

---

## Future Enhancements
1. Add **additional channels** (e.g., switches or buttons).
2. Enhance data logging with timestamps and telemetry.
3. Integrate visual feedback using an OLED or TFT display.
4. Design a custom PCB for a more compact and robust solution.

---

## References
- [Teensy Documentation](https://www.pjrc.com/teensy/)
- [Archer Plus SR8 Manual](https://www.frsky-rc.com/archer-plus-sr8/)
- [PWM Signal Guide](https://oscarliang.com/pwm-signals/)

---

## Author
This project is tailored for advanced RC applications. Contributions and suggestions are always welcome!
