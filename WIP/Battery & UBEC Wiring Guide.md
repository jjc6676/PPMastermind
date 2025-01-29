### **📌 Battery & UBEC Wiring Guide**

1️⃣ **Battery (3S/4S LiPo)**

-   🔴 **Positive (+)** → Connect to **UBEC Input (+)**
-   ⚫ **Negative (-)** → Connect to **UBEC Input (-)**

2️⃣ **UBEC (5V 5A) Output**

-   🔴 **5V Output** → Connect to:
    -   **Teensy 4.1 VIN**
    -   **Servo Power (Red Wires)**
    -   **Receiver Power (VIN)**
-   ⚫ **GND Output** → Connect to:
    -   **Teensy 4.1 GND**
    -   **Servo GND (Black Wires)**
    -   **Receiver GND**

3️⃣ **Teensy 4.1 Connections**

-   **Servo Signal Pins** → Connected to **Teensy PWM Outputs (Pins 6, 7, 8, 9)**
-   **FrSky X20S Telemetry** → Connected via **Serial1 (TX/RX)**