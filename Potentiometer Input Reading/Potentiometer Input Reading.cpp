// Define analog input pins for potentiometers
const int potPins[] = {A0, A1, A2, A3}; // Potentiometers for pitch, roll, yaw, and throttle

// Array to store mapped PWM values for each channel
int pwmValues[4];

void setup() {
  Serial.begin(9600); // Start serial communication for debugging
  for (int i = 0; i < 4; i++) {
    pinMode(potPins[i], INPUT); // Set potentiometer pins as input
  }
}

void loop() {
  // Read potentiometer values and map them to PWM range (1000-2000 µs)
  for (int i = 0; i < 4; i++) {
    int potValue = analogRead(potPins[i]); // Read analog value (0-1023)
    pwmValues[i] = map(potValue, 0, 1023, 1000, 2000); // Map to PWM range
  }

  // Print the values to the Serial Monitor for debugging
  Serial.print("Pitch: ");
  Serial.print(pwmValues[0]);
  Serial.print(" Roll: ");
  Serial.print(pwmValues[1]);
  Serial.print(" Yaw: ");
  Serial.print(pwmValues[2]);
  Serial.print(" Throttle: ");
  Serial.println(pwmValues[3]);

  delay(100); // Small delay for stability
}
