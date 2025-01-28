#include <Servo.h>

// Create servo objects for each channel
Servo pitchServo;
Servo rollServo;
Servo yawServo;
Servo throttleServo;

// Define potentiometer and output pins
const int potPins[] = {A0, A1, A2, A3}; // Potentiometer inputs
const int pwmPins[] = {3, 5, 6, 9};     // PWM outputs for Pitch, Roll, Yaw, Throttle

void setup() {
  // Attach PWM outputs to servo objects
  pitchServo.attach(pwmPins[0]);
  rollServo.attach(pwmPins[1]);
  yawServo.attach(pwmPins[2]);
  throttleServo.attach(pwmPins[3]);

  // Initialize serial for debugging
  Serial.begin(9600);
}

void loop() {
  // Read and map potentiometer values
  int pitchValue = map(analogRead(potPins[0]), 0, 1023, 1000, 2000);
  int rollValue = map(analogRead(potPins[1]), 0, 1023, 1000, 2000);
  int yawValue = map(analogRead(potPins[2]), 0, 1023, 1000, 2000);
  int throttleValue = map(analogRead(potPins[3]), 0, 1023, 1000, 2000);

  // Output PWM signals
  pitchServo.writeMicroseconds(pitchValue);
  rollServo.writeMicroseconds(rollValue);
  yawServo.writeMicroseconds(yawValue);
  throttleServo.writeMicroseconds(throttleValue);

  // Debug output
  Serial.print("Pitch: "); Serial.print(pitchValue);
  Serial.print(" Roll: "); Serial.print(rollValue);
  Serial.print(" Yaw: "); Serial.print(yawValue);
  Serial.print(" Throttle: "); Serial.println(throttleValue);

  delay(20); // Small delay for stability
}
