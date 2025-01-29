#include <Servo.h>
#include <SD.h>
#include "config.h"

// Servo objects for each axis
Servo pitchServo, rollServo, yawServo;

// Variables for potentiometer readings
int pitchGain, rollGain, yawGain, flightMode;
int prevPitchGain = -1, prevRollGain = -1, prevYawGain = -1, prevFlightMode = -1; // For optimized serial printing

// SD card setup
File logFile;

void setup() {
    Serial.begin(115200);

    // Attach servos to designated pins
    pitchServo.attach(6); // Pin for Pitch
    rollServo.attach(7);  // Pin for Roll
    yawServo.attach(8);   // Pin for Yaw

    // Initialize SD card
    if (!SD.begin(BUILTIN_SDCARD)) {
        Serial.println("SD initialization failed!");
        while (1);
    }
    logFile = SD.open("log.csv", FILE_WRITE);
    if (logFile) {
        logFile.println("Timestamp,PitchGain,RollGain,YawGain,FlightMode");
        logFile.close();
    }

    Serial.println("System Initialized");
}

void loop() {
    // Read potentiometer values (0–1023)
    pitchGain = analogRead(PITCH_POT_PIN);
    rollGain = analogRead(ROLL_POT_PIN);
    yawGain = analogRead(YAW_POT_PIN);
    flightMode = analogRead(MODE_POT_PIN);

    // Map potentiometer values to meaningful ranges
    pitchGain = map(pitchGain, 0, 1023, 0, 100);
    rollGain = map(rollGain, 0, 1023, 0, 100);
    yawGain = map(yawGain, 0, 1023, 0, 100);
    flightMode = map(flightMode, 0, 1023, 1, 3);

    // Write adjusted values to servos, ensuring they stay within valid range
    pitchServo.write(constrain(map(pitchGain, 0, 100, 0, 180), 0, 180));
    rollServo.write(constrain(map(rollGain, 0, 100, 0, 180), 0, 180));
    yawServo.write(constrain(map(yawGain, 0, 100, 0, 180), 0, 180));

    // Open SD card file only if logging is enabled
    logFile = SD.open("log.csv", FILE_WRITE);
    if (logFile) {
        logFile.print(millis()); // Timestamp for better tracking
        logFile.print(",");
        logFile.print(pitchGain);
        logFile.print(",");
        logFile.print(rollGain);
        logFile.print(",");
        logFile.print(yawGain);
        logFile.print(",");
        logFile.println(flightMode);
        logFile.flush(); // Ensure data is saved properly
        logFile.close();
    }

    // Only print values if they change, to reduce redundant output
    if (pitchGain != prevPitchGain || rollGain != prevRollGain || yawGain != prevYawGain || flightMode != prevFlightMode) {
        Serial.print("Pitch Gain: "); Serial.print(pitchGain);
        Serial.print(", Roll Gain: "); Serial.print(rollGain);
        Serial.print(", Yaw Gain: "); Serial.print(yawGain);
        Serial.print(", Flight Mode: "); Serial.println(flightMode);

        prevPitchGain = pitchGain;
        prevRollGain = rollGain;
        prevYawGain = yawGain;
        prevFlightMode = flightMode;
    }

    delay(100); // Adjust as needed
}