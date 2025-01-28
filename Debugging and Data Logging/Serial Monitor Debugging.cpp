void logToSerial() {
  Serial.print("PPM Values: ");
  for (int i = 0; i < NUM_CHANNELS; i++) {
    Serial.print("Ch");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(channels[i]);
    Serial.print(" ");
  }
  Serial.println(); // Newline for readability
}
