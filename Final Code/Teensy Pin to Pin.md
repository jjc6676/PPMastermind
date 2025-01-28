### Pin-to-Pin Wiring Diagram for Teensy 4.1 with Archer Plus SR8 and Potentiometers

#### **Teensy 4.1 Connections**
1. **Power**:
   - Vin (Teensy) -> 5V Power Supply (Shared with SR8 Receiver and Servos)
   - GND (Teensy) -> Common Ground (Shared with SR8 Receiver, Servos, and Potentiometers)

2. **Potentiometers**:
   - **Pitch Potentiometer**:
     - Signal (Middle Pin) -> A0 (Teensy)
     - VCC (Left Pin) -> 3.3V (Teensy)
     - GND (Right Pin) -> GND (Teensy)
   - **Roll Potentiometer**:
     - Signal (Middle Pin) -> A1 (Teensy)
     - VCC (Left Pin) -> 3.3V (Teensy)
     - GND (Right Pin) -> GND (Teensy)
   - **Yaw Potentiometer**:
     - Signal (Middle Pin) -> A2 (Teensy)
     - VCC (Left Pin) -> 3.3V (Teensy)
     - GND (Right Pin) -> GND (Teensy)
   - **Mode Potentiometer**:
     - Signal (Middle Pin) -> A3 (Teensy)
     - VCC (Left Pin) -> 3.3V (Teensy)
     - GND (Right Pin) -> GND (Teensy)

3. **Archer Plus SR8 Receiver**:
   - S.Bus Output (SR8) -> Pin 7 (Teensy) [Optional for Custom Telemetry or Signal Processing]
   - Power (SR8):
     - VCC (SR8) -> 5V Power Supply
     - GND (SR8) -> Common Ground

4. **Optional SD Card for Logging**:
   - The Teensy 4.1 has a built-in MicroSD slot; no additional wiring needed.

---

#### **Archer Plus SR8 Receiver to Servos**
1. **Servo Connections**:
   - CH1 (SR8) -> Ailerons (Servo 1)
   - CH2 (SR8) -> Elevator (Servo 2)
   - CH4 (SR8) -> Rudder (Servo 3)
   - CH3 (SR8) -> Throttle (if ESC is used)

2. **Power for Servos**:
   - External 5V Power Supply -> VCC (All Servos)
   - Common Ground -> GND (All Servos)

---

#### **Power Supply Details**
- Use a regulated 5V power supply capable of handling the current demands of:
  - Teensy 4.1
  - SR8 Receiver
  - Connected Servos