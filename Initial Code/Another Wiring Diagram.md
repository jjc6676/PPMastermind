# Wiring Diagram for Teensy-Based RC Transmitter Emulator

This document provides **step-by-step wiring instructions** for the components in the Teensy-based RC transmitter emulator project.

---

## Overview
The wiring diagram includes connections for:
1. **Teensy 4.1 microcontroller**
2. **Rotary potentiometers** for Pitch, Roll, Yaw, and Throttle inputs
3. **Archer Plus SR8 receiver**
4. **Power supply** for all components
5. Optional **capacitors** for power stability

---

## Wiring Instructions

### **1. Potentiometers**
Each potentiometer has three pins:
- **Left Pin (GND)**: Connect to the **GND** pin on the Teensy.
- **Middle Pin (Signal)**: Connect to the following Teensy analog input pins:
  - **Pitch**: Middle pin to **A0**
  - **Roll**: Middle pin to **A1**
  - **Yaw**: Middle pin to **A2**
  - **Throttle**: Middle pin to **A3**
- **Right Pin (VCC)**: Connect to the **3.3V** pin on the Teensy.

### **2. Teensy 4.1 Connections**
- **PPM Output**: Digital pin **9** on the Teensy. Connect this pin to the PPM input pin on the Archer Plus SR8 receiver.
- **Analog Inputs**: Connect to the middle pins of the potentiometers as specified above.
- **GND**: Connect to the common ground shared with the power supply and receiver.
- **Power Input (5V)**: Connect the 5V pin to the regulated power supply (e.g., UBEC or adapter).

### **3. Archer Plus SR8 Receiver**
- **PPM Input**: Connect to the PPM signal from Digital Pin **9** on the Teensy.
- **GND**: Connect to the shared ground with the Teensy and power supply.
- **Power (5V)**: Connect to the 5V output of the power supply.

### **4. Power Supply**
- Use a stable **5V, 5A power supply** to power all components:
  - Connect the power supply’s **5V output** to the Teensy’s 5V pin and the Archer Plus SR8.
  - Connect the **GND** of the power supply to the Teensy and Archer Plus SR8.
- Add a **1000µF capacitor** across the power lines to stabilize voltage and prevent noise.

---

## Optional Components
1. **Push Buttons or Toggle Switches**:
   - Use additional digital pins on the Teensy for extra control inputs.
2. **SD Card Module**:
   - Connect the SD card module to the Teensy for data logging. Use SPI pins (CS, MOSI, MISO, SCK) for the connection.
3. **PPM Tester**:
   - Attach the PPM signal to a tester for debugging before connecting to the receiver.

---

## Visual Overview
1. **Potentiometers**: Inputs for analog signals (Pitch, Roll, Yaw, Throttle).
2. **Teensy**: Processes inputs and generates PPM output.
3. **Archer Plus SR8**: Receives the PPM signal for RC control and stabilization.
4. **Power Supply**: Provides stable power to all components.

---

## Notes
- Ensure all components share a common ground to avoid erratic behavior.
- Verify connections with a multimeter to prevent short circuits.
- Use heat shrink tubing or electrical tape to insulate exposed wires.

---

For additional details or troubleshooting, refer to the main [README file](README.md).

