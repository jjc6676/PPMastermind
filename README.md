# PPMastermind: Fly-By-Wire System for RC Aircraft

## 🚀 Overview
This project implements a **Fly-By-Wire (FBW) stabilization system** using a **Teensy 4.1 microcontroller**. It is designed to enhance RC aircraft control by integrating **AI-driven flight stability, telemetry, and adaptive tuning**. The system interacts with an **Archer Plus SR8 receiver**, **FrSky X20S telemetry**, and **real-time AI processing** to improve flight dynamics and provide intelligent automation.

---

## 🎯 Features
✅ **Gyro-Assisted Flight Stabilization** (Auto-Corrects Roll, Pitch, and Yaw)  
✅ **Adaptive AI Tuning** (Real-Time Flight Mode Adjustments)  
✅ **FrSky X20S Telemetry Integration** (Live Flight Data Monitoring)  
✅ **Failsafe Auto-Recovery & Emergency Return-to-Home (RTH)**  
✅ **Manual Gain Adjustments via FrSky or Potentiometers**  
✅ **SD Card Data Logging for Post-Flight Analysis**  

---

## 🛠️ Hardware Components
1️⃣ **Teensy 4.1** - Core Flight Controller (Processes PWM, AI, and Telemetry)  
2️⃣ **Archer Plus SR8 Receiver** - Provides PWM Signals & Gyro Feedback  
3️⃣ **FrSky X20S Transmitter** - Displays Live Telemetry & Adjusts Gains  
4️⃣ **4x Servos** - Control Gimbal & Aircraft Stabilization  
5️⃣ **Potentiometers (Optional)** - Manual Gain Control  
6️⃣ **SD Card (Optional)** - Flight Data Logging  
7️⃣ **Power Supply (5V, 5A)** - Ensures Stable Operation  

---

## 🔌 Wiring Diagram
### **Connections:**
- **Teensy 4.1**:
  - PWM Outputs: **Servos (Pins 6, 7, 8, 9)**
  - Analog Inputs: **Potentiometers (A0, A1, A2, A3)**
  - Serial1: **FrSky X20S Telemetry**
  - SD Card: **SPI Bus (CS = BUILTIN_SDCARD)**
- **Archer Plus SR8 Receiver**:
  - PWM Inputs: **Teensy Digital Pins**
  - GND: **Common Ground**
- **FrSky X20S**:
  - Displays **Flight Data & Adjusts AI Gains**

---

## 💾 Software Setup
### **Required Libraries**
- **Servo.h**: PWM Signal Generation  
- **SD.h**: Data Logging  
- **Wire.h**: I2C Communication  
- **FrSkyTelemetry.h**: Custom Telemetry Handling  
- **MLModel.h**: AI-Based Flight Optimization  

### **Arduino IDE Configuration**
1️⃣ Install **Teensyduino** Add-on  
2️⃣ Select **Board: Teensy 4.1**  
3️⃣ Choose **COM Port & Upload the Code**  

---

## 📜 Code Overview
### **1️⃣ AI Flight Stability (`MLModel.h`)**
- Adjusts **servo response dynamically** based on flight conditions.
- Detects **stalls, turbulence, and overcorrections**.
- Automatically **optimizes flight gains** for smoother control.

### **2️⃣ FrSky Telemetry (`FrSkyTelemetry.h`)**
- Sends **live data** to the FrSky X20S transmitter.
- Logs **flight performance metrics**.
- Adapts to **missing hardware** (e.g., estimates airspeed if sensor is absent).

### **3️⃣ Failsafe & Auto-Recovery**
- If **signal is lost**, system **switches to Beginner Mode**.
- If **battery is critically low**, system **triggers Return-To-Home (RTH)**.

---

## 🎮 How to Use
1️⃣ **Assemble the Hardware** (Connect Servos, Receiver, & Telemetry)  
2️⃣ **Upload the Code to Teensy**  
3️⃣ **Power On the System & Hold Plane Still for Calibration**  
4️⃣ **Monitor Live Data on FrSky X20S & Adjust Gains**  
5️⃣ **Test Gimbal Response to Movement & AI Adaptation**  
6️⃣ **Check Data Logging on SD Card (If Enabled)**  

---

## ❗ Troubleshooting
🛠️ **No Servo Response?** Check **PWM connections & power supply.**  
🛠️ **Telemetry Not Showing?** Ensure **FrSky X20S is paired correctly.**  
🛠️ **AI Not Adjusting Gains?** Verify **MLModel.h is included & enabled.**  

---

## 🚀 Future Enhancements
✅ **Add GPS for More Accurate Return-To-Home (RTH)**  
✅ **Integrate Wind Compensation Using Additional Sensors**  
✅ **Improve AI-Based Adaptive Control with Machine Learning**  
✅ **Implement Autonomous Flight Mode with Waypoints**  

---

## 📚 References
📌 [Teensy 4.1 Documentation](https://www.pjrc.com/teensy/)  
📌 [Archer Plus SR8 Receiver](https://www.frsky-rc.com/archer-plus-sr8/)  
📌 [FrSky X20S User Guide](https://www.frsky-rc.com/product/tandem-x20s/)  

---

## 👨‍💻 Author & Contributions
This project is designed for **advanced RC flight systems** and **Fly-By-Wire automation**. Contributions & feedback are always welcome! 🚀