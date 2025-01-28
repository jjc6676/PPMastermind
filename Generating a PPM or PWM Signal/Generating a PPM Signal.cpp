#define PPM_OUTPUT_PIN 9 // Define the pin for PPM output
#define NUM_CHANNELS 4   // Number of channels (pitch, roll, yaw, throttle)
#define PPM_FRAME_LENGTH 22500 // Total frame length in microseconds
#define CHANNEL_DEFAULT 1500   // Default pulse width in microseconds
#define PPM_PULSE_LENGTH 500   // Pulse length in microseconds

// Array to store PWM values for each channel
int channels[NUM_CHANNELS] = {1500, 1500, 1500, 1500};

void setup() {
  pinMode(PPM_OUTPUT_PIN, OUTPUT); // Set PPM output pin
  digitalWrite(PPM_OUTPUT_PIN, LOW); // Initialize pin state
}

void loop() {
  // Update channel values (simulate input from potentiometers)
  for (int i = 0; i < NUM_CHANNELS; i++) {
    channels[i] = map(analogRead(potPins[i]), 0, 1023, 1000, 2000);
  }

  // Generate the PPM signal
  createPPM();
}

void createPPM() {
  unsigned long frameStart = micros(); // Track the start of the PPM frame

  for (int i = 0; i < NUM_CHANNELS; i++) {
    digitalWrite(PPM_OUTPUT_PIN, HIGH);           // Start channel pulse
    delayMicroseconds(channels[i]);              // Hold for channel pulse width
    digitalWrite(PPM_OUTPUT_PIN, LOW);           // Pulse end
    delayMicroseconds(PPM_PULSE_LENGTH);         // Separator pulse
  }

  // Wait until the frame length is complete
  while (micros() - frameStart < PPM_FRAME_LENGTH);
}
