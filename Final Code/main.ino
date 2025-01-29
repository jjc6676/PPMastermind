#include <Servo.h>

#include <SD.h>
#include "config.h"

// Servo objects for each axis
Servo pitchServo, rollServo, yawServo;

// Variables for potentiometer readings
int pitchGain, rollGain, yawGain, flightMode;

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
  logFile.println("PitchGain,RollGain,YawGain,FlightMode");
  logFile.close();

  Serial.println("System Initialized");
}

void loop() {
  // Read potentiometer values (0–1023)
  pitchGain = analogRead(PITCH_POT_PIN);
  rollGain = analogRead(ROLL_POT_PIN);
  yawGain = analogRead(YAW_POT_PIN);
  flightMode = analogRead(MODE_POT_PIN);

  // Map potentiometer values to meaningful ranges
  pitchGain = map(pitchGain, 0, 1023, 0, 100);  // 0% to 100% gain
  rollGain = map(rollGain, 0, 1023, 0, 100);
  yawGain = map(yawGain, 0, 1023, 0, 100);
  flightMode = map(flightMode, 0, 1023, 1, 3);  // 1 to 3 flight modes

  // Write adjusted values to servos
  pitchServo.write(map(pitchGain, 0, 100, 0, 180)); // Map gain to 0–180 degrees
  rollServo.write(map(rollGain, 0, 100, 0, 180));
  yawServo.write(map(yawGain, 0, 100, 0, 180));

  // Optional: Log values to SD card
  logFile = SD.open("log.csv", FILE_WRITE);
  if (logFile) {
    logFile.print(pitchGain);
    logFile.print(",");
    logFile.print(rollGain);
    logFile.print(",");
    logFile.print(yawGain);
    logFile.print(",");
    logFile.println(flightMode);
    logFile.close();
  }

  // Debugging output
  Serial.print("Pitch Gain: "); Serial.print(pitchGain);
  Serial.print(", Roll Gain: "); Serial.print(rollGain);
  Serial.print(", Yaw Gain: "); Serial.print(yawGain);
  Serial.print(", Flight Mode: "); Serial.println(flightMode);

  delay(100); // Adjust as needed
}
