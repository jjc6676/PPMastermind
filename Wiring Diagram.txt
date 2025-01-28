# Detailed Wiring Diagram for Teensy-Based RC Transmitter Emulator

## Components Overview:
1. **Teensy 4.1** (Microcontroller)
2. **Rotary Potentiometers** (4 total, for Pitch, Roll, Yaw, Throttle)
3. **Archer Plus SR8 Receiver**
4. **Power Supply (5V)**
5. **Wiring** (Jumper wires, connectors, etc.)

---

## Wiring Connections:

### 1. **Potentiometers**
Each potentiometer has 3 pins:
- **Left Pin**: Connect to **GND** (Teensy Ground).
- **Middle Pin**: Connect to Teensy **Analog Input Pins**:
  - **Pitch**: A0
  - **Roll**: A1
  - **Yaw**: A2
  - **Throttle**: A3
- **Right Pin**: Connect to **3.3V** (Teensy).

### 2. **Teensy 4.1**
- **Analog Inputs**: A0, A1, A2, A3 for potentiometer signals.
- **PPM Output Pin**: Digital Pin 9 (PPM signal to the Archer Plus SR8 receiver).
- **GND**: Connect to the common ground of the system (shared with power supply and receiver).
- **VIN/USB**: Powered via USB (for testing) or VIN (5V from power supply).

### 3. **Archer Plus SR8 Receiver**
- **PPM Input**: Connect to Teensy Digital Pin 9 (PPM Output).
- **GND**: Connect to the common ground of the system.
- **5V Input**: Connect to the 5V power supply.

### 4. **Power Supply (5V)**
- **GND**: Connect to the common ground shared by the Teensy, potentiometers, and receiver.
- **5V**: Power the receiver and optionally the Teensy (via VIN). Do not exceed the Teensy’s input voltage specifications.

---

## Notes:
1. **Common Ground**:
   - Ensure all components share a common ground (Teensy, receiver, potentiometers, power supply) to avoid signal issues.

2. **Powering the Teensy**:
   - For testing, you can power the Teensy via USB.
   - For standalone use, power the Teensy through VIN using the 5V power supply.

3. **PPM Output Timing**:
   - Ensure Digital Pin 9 on the Teensy outputs the correct PPM signal format (default is 1000–2000 µs pulses).

4. **Safety**:
   - Use a stable, regulated power supply to avoid damaging components.
   - Double-check all connections before powering the system.

---

## Diagram Summary:
- **Potentiometers**: A0, A1, A2, A3 (signal), GND, 3.3V.
- **PPM Signal**: Digital Pin 9 to Archer Plus SR8 PPM Input.
- **Power**: Shared 5V supply for Teensy (VIN) and receiver, with GND as a common reference.

Ensure you verify your connections step by step before running the code or powering the system. Let me know if further clarification is needed!