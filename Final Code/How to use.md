# Features of the Script

## PWM Input and Output
- Reads PWM inputs from the receiver for channels (e.g., pitch, roll, yaw, throttle).
- Adjusts the outputs based on gain settings and writes them back.

## Gain Adjustment
- Dynamically adjusts gains using sliders (e.g., `ls1`, `ls2`, `ls3`).

## Flight Mode Selection
- Uses a 3-position switch (`sa`) to toggle between Beginner, Intermediate, and Expert modes.

## Real-Time Display
- Shows the current flight mode, gains, and other parameters on the transmitter's screen.

---

# How to Use

## Load Script
1. Save the script as a `.lua` file.
2. Upload it to the FrSky X20S under the appropriate directory (e.g., `/SCRIPTS/TOOLS/`).

## Assign Controls
1. Map sliders (`ls1`, `ls2`, `ls3`) and switches (`sa`) in the transmitter’s configuration to match the script.

## Test PWM Outputs
1. Verify that the PWM values adjust correctly.
2. Ensure outputs are sent to the receiver or directly to servos.
