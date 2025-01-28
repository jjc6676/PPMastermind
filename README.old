# PPMastermind
 
# Project: Teensy-Based RC Transmitter Emulator

## Overview
This project uses a **Teensy 4.1 microcontroller** to emulate an RC transmitter by generating a PPM signal. The system is designed to interface with an **Archer Plus SR8 receiver** and provide dynamic control via potentiometers acting as joysticks. The setup is suitable for testing and calibration purposes, simulating wind effects on a gimbal-mounted plane, and general RC applications.

---

## Features
- Reads inputs from up to **4 potentiometers** to control channels (Pitch, Roll, Yaw, Throttle).
- Generates a **PPM signal** compatible with most RC receivers, including the Archer Plus SR8.
- Includes **data logging** via serial monitor or optional SD card.
- Provides a base framework for integration with Lua scripting for further customization.

---

## Hardware Components
1. **Teensy 4.1** (Microcontroller for signal generation)
2. **Rotary Potentiometers (4)** (Input control for Pitch, Roll, Yaw, and Throttle)
3. **Archer Plus SR8 Receiver** (PPM-compatible receiver with integrated gyro)
4. **Power Supply (5V, 5A)** (For Teensy and potentiometer power)
5. **Wires and Connectors**
6. Optional: **SD Card Module** (For data logging)

---

## Wiring Diagram
### Connections:
- **Potentiometers**:
  - Left Pin: **GND**
  - Middle Pin: **Analog Input** (A0, A1, A2, A3)
  - Right Pin: **3.3V**
- **Teensy**:
  - PPM Output: Digital Pin 9
  - Potentiometer Inputs: A0, A1, A2, A3
  - GND: Common ground with power supply and receiver
  - 5V: Shared with receiver (via power supply)
- **Archer Plus SR8**:
  - PPM Input: Connect to Teensy Digital Pin 9
  - GND: Common ground

---

## Software Setup
### Required Libraries
- **Servo.h**: For PWM signal generation (if used in debugging or extensions). [Install Servo.h](https://www.arduino.cc/reference/en/libraries/servo/)
- **SD.h**: For data logging (optional). [Install SD.h](https://www.arduino.cc/reference/en/libraries/sd/)

### Arduino IDE Configuration
1. Install the **Teensyduino** add-on. [Get Teensyduino](https://www.pjrc.com/teensy/teensyduino.html)
2. Select the board: `Teensy 4.1`.
3. Choose the appropriate COM port.

---

## Code Overview
### 1. **Potentiometer Input Reading**
- Reads analog values from potentiometers.
- Maps values to the range 1000–2000 µs for PPM.

### 2. **PPM Signal Generation**
- Combines multiple channels (Pitch, Roll, Yaw, Throttle) into a single PPM output.
- Ensures compatibility with the Archer Plus SR8 receiver.

### 3. **Debugging and Data Logging**
- Logs potentiometer values and PPM outputs to the serial monitor.
- Optionally writes data to an SD card.

### 4. **Lua Script Integration**
- Processes and simulates PPM data in Lua for use in RC simulations or game engines.

---

## Example Usage
1. **Connect the Hardware**:
   - Wire the potentiometers, Teensy, and receiver as per the wiring diagram.
2. **Upload the Code**:
   - Use the Arduino IDE to upload the provided code to the Teensy.
3. **Monitor Data**:
   - Open the serial monitor to view real-time data (optional).
4. **Test Receiver Integration**:
   - Connect the PPM output to the Archer Plus SR8 and observe channel responses.

---

## Troubleshooting
1. **PPM Signal Not Detected**:
   - Ensure the Teensy and receiver share a common ground.
   - Verify the PPM output pin is correctly connected.
2. **Incorrect Channel Responses**:
   - Check the potentiometer connections.
   - Verify the mapping ranges in the code.
3. **Power Issues**:
   - Use a sufficient 5V power supply (at least 5A for stable operation).

---

## Future Enhancements
1. Add **additional channels** (e.g., switches or buttons).
2. Integrate **PID control** for stabilization testing.
3. Enhance data logging with timestamps and telemetry.
4. Expand Lua script functionality for advanced RC applications.

---

## References
- [Teensy Documentation](https://www.pjrc.com/teensy/)
- [Archer Plus SR8 Manual](https://www.frsky-rc.com/archer-plus-sr8/)
- [PPM Protocol Guide](https://oscarliang.com/ppm-signals/)

---

## Author
This project documentation was tailored for your custom Teensy-based RC transmitter emulator. If you need additional assistance, feel free to reach out!
