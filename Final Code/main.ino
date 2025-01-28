#include <SD.h>

// Pin definitions for potentiometers
#define PITCH_POT A0
#define ROLL_POT A1
#define YAW_POT A2
#define MODE_POT A3

// Variables for potentiometer readings
int pitchGain, rollGain, yawGain, flightMode;

// SD card setup
File logFile;

void setup() {
  Serial.begin(115200);

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
  pitchGain = analogRead(PITCH_POT);
  rollGain = analogRead(ROLL_POT);
  yawGain = analogRead(YAW_POT);
  flightMode = analogRead(MODE_POT);

  // Map potentiometer values to meaningful ranges
  pitchGain = map(pitchGain, 0, 1023, 0, 100);  // 0% to 100% gain
  rollGain = map(rollGain, 0, 1023, 0, 100);
  yawGain = map(yawGain, 0, 1023, 0, 100);
  flightMode = map(flightMode, 0, 1023, 1, 3);  // 1 to 3 flight modes

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
