### **🚀 How to Use All Your Files to Get Started**

Now that you have **your gimbal (4 servos) and plane (servos + gyros) built**, here's a step-by-step guide to setting up and running your **Fly-By-Wire system with telemetry and AI stabilization**.

* * * * *

**🛠️ 1️⃣ Hardware Connections**
--------------------------------

### **✅ Wiring the Teensy 4.1**

-   **Connect the servos to PWM output pins on the Teensy:**
    -   **Roll Servo** → PWM Pin 6
    -   **Pitch Servo** → PWM Pin 7
    -   **Yaw Servo** → PWM Pin 8
    -   **Throttle Servo** → PWM Pin 9
-   **Connect the Archer Plus SR8 Gyro Receiver to Teensy:**
    -   **PWM Signals from Receiver** → Analog Input Pins (A1, A2, A3, A4)
    -   **Power and Ground** → Teensy 4.1 5V & GND Pins
-   **Connect the FrSky X20S Transmitter (for telemetry)**
    -   **Serial Communication (Telemetry)** → `Serial1` on Teensy
-   **Connect the SD Card (for logging)**
    -   **CS Pin** → Teensy **BUILTIN_SDCARD**
    -   **Power (VCC) & Ground (GND)** → 3.3V & GND

* * * * *

**💾 2️⃣ Uploading the Code to the Teensy 4.1**
-----------------------------------------------

1️⃣ **Install Required Software**:

-   **Arduino IDE** with **Teensyduino Add-on**
-   Ensure **Serial, SD, and Servo Libraries** are installed.

2️⃣ **Flash These Files in Order**:

1.  **`MLModel.h`** → Handles AI-based flight stability & adaptive tuning.
2.  **`FrSkyTelemetry.h`** → Sends live data to the FrSky X20S transmitter.
3.  **`main.ino` (or equivalent)** → The main Fly-By-Wire loop that:
    -   Reads gyro + pilot inputs.
    -   Adjusts servo movements.
    -   Handles failsafe recovery & AI stabilization.

* * * * *

**🛠️ 3️⃣ Running the System**
------------------------------

### **✅ Power On & Calibration**

1️⃣ **Turn on the Teensy & Plane**

-   The servos should **initialize**.
-   Gyro will **self-calibrate** (hold the plane steady for 5 sec).

2️⃣ **Start the FrSky X20S Transmitter**

-   Navigate to **Telemetry Page** → You should see **flight mode, battery, gains**.

3️⃣ **Gimbal Test Mode**

-   Move the plane manually → The gimbal should counteract movement.
-   Adjust gains using **transmitter sliders** (Beginner, Intermediate, Expert).

* * * * *

**📊 4️⃣ Testing AI-Based Stabilization**
-----------------------------------------

1️⃣ **Enable AI Stabilization**

-   The system automatically **adjusts gains based on flight data**.
-   If the pilot struggles with control, **it smooths movements**.

2️⃣ **Test Emergency Failover**

-   **Turn off the transmitter** → The system should **auto-level and hold position**.
-   **Reduce battery voltage manually** → The system should **trigger Return-To-Home (RTH) if available**.

3️⃣ **Check Data Logging**

-   SD Card logs **servo positions, gains, battery status** for later analysis.

* * * * *

**🎯 Next Steps**
-----------------

✅ **Test how well the AI tuning adapts to your flight**.\
✅ **Review logs for stability & servo corrections**.\
✅ **Fine-tune gains based on different flight modes**.

Your **Fly-By-Wire system is ready!** Let me know if you need **debugging support or feature improvements!** 🚀✈️