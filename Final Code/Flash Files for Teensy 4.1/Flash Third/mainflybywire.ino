/*
   Fly-By-Wire (FBW) System for RC Aircraft - Teensy 4.1
   ----------------------------------------------------
   Features:
   - Gyro-Assisted Stability using Archer Plus SR8 Receiver
   - Fly-By-Wire Control with Beginner, Intermediate, and Expert Modes
   - Automatic Failsafe Recovery
   - Real-Time Data Logging and Telemetry
*/

#include <Servo.h>
#include <Wire.h>
#include <SD.h>

// Define Pins
#define ROLL_SERVO_PIN 6
#define PITCH_SERVO_PIN 7
#define YAW_SERVO_PIN 8
#define THROTTLE_SERVO_PIN 9
#define MODE_POT_PIN A0
#define SD_CS_PIN BUILTIN_SDCARD

// Create Servo Objects
Servo rollServo, pitchServo, yawServo, throttleServo;

// Gyro Data Variables
float gyroRoll, gyroPitch, gyroYaw;
float rollGain = 50, pitchGain = 50, yawGain = 50;
int flightMode = 1; // Default to Beginner Mode
bool signalLost = false;

// SD Card Logging File
File logFile;

void setup() {
    Serial.begin(115200);
    
    // Attach Servos
    rollServo.attach(ROLL_SERVO_PIN);
    pitchServo.attach(PITCH_SERVO_PIN);
    yawServo.attach(YAW_SERVO_PIN);
    throttleServo.attach(THROTTLE_SERVO_PIN);
    
    // Initialize SD Card
    if (!SD.begin(SD_CS_PIN)) {
        Serial.println("SD Card Initialization Failed!");
    } else {
        logFile = SD.open("flight_log.csv", FILE_WRITE);
        logFile.println("Time,FlightMode,RollGain,PitchGain,YawGain,GyroRoll,GyroPitch,GyroYaw");
        logFile.close();
    }
    Serial.println("Fly-By-Wire System Initialized");
}

void loop() {
    // Read Pilot Inputs
    int pilotRollInput = analogRead(A1);
    int pilotPitchInput = analogRead(A2);
    int pilotYawInput = analogRead(A3);
    int pilotThrottleInput = analogRead(A4);

    // Read Gyro Data (Simulated for now)
    gyroRoll = random(-5, 5) / 10.0; // Simulated small roll variations
    gyroPitch = random(-5, 5) / 10.0;
    gyroYaw = random(-5, 5) / 10.0;

    // Adjust Gains Based on Flight Mode
    flightMode = map(analogRead(MODE_POT_PIN), 0, 1023, 1, 3);
    if (flightMode == 1) { // Beginner Mode
        rollGain = 80;
        pitchGain = 80;
    } else if (flightMode == 2) { // Intermediate Mode
        rollGain = 50;
        pitchGain = 50;
    } else { // Expert Mode
        rollGain = 20;
        pitchGain = 20;
    }

    // Auto-Stabilization Using Gyro Data
    float rollCorrection = gyroRoll * rollGain;
    float pitchCorrection = gyroPitch * pitchGain;
    float yawCorrection = gyroYaw * yawGain;

    // Apply Corrections to Servo Outputs
    rollServo.writeMicroseconds(map(pilotRollInput + rollCorrection, 0, 1023, 1000, 2000));
    pitchServo.writeMicroseconds(map(pilotPitchInput + pitchCorrection, 0, 1023, 1000, 2000));
    yawServo.writeMicroseconds(map(pilotYawInput + yawCorrection, 0, 1023, 1000, 2000));
    throttleServo.writeMicroseconds(map(pilotThrottleInput, 0, 1023, 1000, 2000));

    // Failsafe: If signal is lost, switch to Beginner Mode
    if (signalLost) {
        flightMode = 1;
        rollGain = 100;
        pitchGain = 100;
        Serial.println("Failsafe Activated: Beginner Mode");
    }

    // Log Data to SD Card
    logFile = SD.open("flight_log.csv", FILE_WRITE);
    if (logFile) {
        logFile.print(millis());
        logFile.print(",");
        logFile.print(flightMode);
        logFile.print(",");
        logFile.print(rollGain);
        logFile.print(",");
        logFile.print(pitchGain);
        logFile.print(",");
        logFile.print(yawGain);
        logFile.print(",");
        logFile.print(gyroRoll);
        logFile.print(",");
        logFile.print(gyroPitch);
        logFile.print(",");
        logFile.println(gyroYaw);
        logFile.close();
    }

    // Debug Output
    Serial.print("Mode: "); Serial.print(flightMode);
    Serial.print(" | Roll Gain: "); Serial.print(rollGain);
    Serial.print(" | Pitch Gain: "); Serial.print(pitchGain);
    Serial.print(" | Yaw Gain: "); Serial.println(yawGain);
    
    delay(50); // Adjust loop speed as needed
}
