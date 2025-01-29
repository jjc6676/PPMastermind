#include <SD.h>

File logFile;

void setup() {
  SD.begin(10); // SD card module connected to pin 10
  logFile = SD.open("log.txt", FILE_WRITE); // Open log file
}

void logToSD() {
  logFile.print("PPM Values: ");
  for (int i = 0; i < NUM_CHANNELS; i++) {
    logFile.print("Ch");
    logFile.print(i + 1);
    logFile.print(": ");
    logFile.print(channels[i]);
    logFile.print(" ");
  }
  logFile.println(); // Newline for readability
  logFile.flush();   // Save data to file
}
