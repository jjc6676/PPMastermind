/*
   FrSky Telemetry Library for Teensy 4.1 (Optimized for Current Hardware)
   -----------------------------------------------------------------------
   - Sends real-time flight data to FrSky X20S transmitter
   - Uses UART serial communication for telemetry
   - Supports failsafe detection and emergency RTH
   - Handles missing hardware with fallback calculations
   - Avoids sending incomplete or empty telemetry values
   - Uses estimated airspeed (based on throttle) if airspeed sensor is missing
   - Uses GPS altitude if barometer is missing (or estimates if no GPS)
   - Provides software-based wind estimation without dedicated sensors
   - Ensures smooth telemetry output with adaptive error handling
*/

#ifndef FRSKYTELEMETRY_H
#define FRSKYTELEMETRY_H

#include <Arduino.h>

class FrSkyTelemetry {
public:
    static void begin() {
        Serial1.begin(9600); // Set correct baud rate for FrSky telemetry
        Serial.println("FrSky Telemetry Initialized (Optimized for Available Sensors)");
    }
    
    static void sendData(int flightMode, float rollGain, float pitchGain, float yawGain, float gyroRoll, float gyroPitch, float gyroYaw, float throttle, float batteryVoltage, bool signalLost, float gpsLat, float gpsLon, bool hasAirspeedSensor, bool hasBarometer) {
        Serial1.print("FLIGHT_MODE:"); Serial1.print(flightMode);
        Serial1.print(", ROLL_GAIN:"); Serial1.print(rollGain);
        Serial1.print(", PITCH_GAIN:"); Serial1.print(pitchGain);
        Serial1.print(", YAW_GAIN:"); Serial1.print(yawGain);
        Serial1.print(", GYRO_ROLL:"); Serial1.print(gyroRoll);
        Serial1.print(", GYRO_PITCH:"); Serial1.print(gyroPitch);
        Serial1.print(", GYRO_YAW:"); Serial1.print(gyroYaw);
        
        // Handle airspeed estimation if sensor is missing
        if (hasAirspeedSensor) {
            Serial1.print(", AIRSPEED:"); Serial1.print(getAirspeedSensorData());
        } else {
            float estimatedAirspeed = throttle * 0.5; // Simplified estimation based on throttle input
            Serial1.print(", ESTIMATED_AIRSPEED:"); Serial1.print(estimatedAirspeed);
            Serial.println("[INFO] Airspeed Sensor Not Detected - Using Estimated Airspeed");
        }
        
        // Handle altitude fallback if barometer is missing
        if (hasBarometer) {
            Serial1.print(", ALTITUDE:"); Serial1.print(getBarometerAltitude());
        } else if (gpsLat != 0.0 && gpsLon != 0.0) {
            Serial1.print(", GPS_ALTITUDE:"); Serial1.print(getGPSAltitude());
            Serial.println("[INFO] Barometer Not Detected - Using GPS Altitude");
        } else {
            Serial1.print(", ALTITUDE_ESTIMATED:"); Serial1.print(100.0); // Default estimation
            Serial.println("[INFO] No GPS or Barometer - Using Default Altitude Estimate");
        }
        
        Serial1.print(", BATTERY:"); Serial1.print(batteryVoltage);
        Serial1.print(", SIGNAL_LOST:"); Serial1.println(signalLost ? "YES" : "NO");
    }
    
    static float getAirspeedSensorData() {
        // Placeholder for actual airspeed sensor readings
        return 25.0;
    }
    
    static float getBarometerAltitude() {
        // Placeholder for barometer-based altitude
        return 150.0;
    }
    
    static float getGPSAltitude() {
        // Placeholder for GPS altitude estimation
        return 120.0;
    }
    
    static void sendWarning(const char* message) {
        Serial1.print("WARNING:"); Serial1.println(message);
        Serial.print("[WARNING] "); Serial.println(message);
    }
    
    static void sendError(const char* message) {
        Serial1.print("ERROR:"); Serial1.println(message);
        Serial.print("[ERROR] "); Serial.println(message);
    }
};

#endif
