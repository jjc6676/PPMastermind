# Components and Connections

## Teensy 4.1
- Acts as the central controller.
- Interfaces with potentiometers for input and the Archer Plus SR8 for stabilization adjustments.

## Potentiometers
- Provide analog input for manual gain adjustments (Pitch, Roll, Yaw) and mode selection.
- Each potentiometer connects its signal pin to one of the Teensy's analog input pins (e.g., A0, A1, A2, A3).

## Archer Plus SR8 Receiver
- Receives stabilization adjustments from the Teensy.
- Controls servos directly based on its built-in gyro and the Teensy's inputs.

## Servos (Control Surfaces)
- Controlled by the SR8 receiver to stabilize or maneuver the RC plane.
