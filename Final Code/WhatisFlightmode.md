# Flight Mode Explanation

## What is `flightMode`?

The `flightMode` variable represents different **stabilization levels** for your system. It allows you to switch between predefined flight behavior configurations, adjusting how the plane responds to inputs.

---

## How `flightMode` Works

### 1. **Reads Input from a Potentiometer**

- The potentiometer connected to `MODE_POT_PIN` provides an **analog input (0--1023)**.

- The value is mapped to **three flight modes (1, 2, or 3)** using the `map()` function:

  flightMode = map(analogRead(MODE_POT_PIN), 0, 1023, 1, 3);

| Mode | Description |

| --- | --- |

| **Mode 1 (Beginner Mode)** | High stabilization, reduced control sensitivity. Ideal for assisted flight. |

| **Mode 2 (Intermediate Mode)** | Moderate stabilization, balance between manual input and automatic correction. |

| **Mode 3 (Expert Mode)** | Minimal or no stabilization, full manual control for experienced pilots. |

How to Use `flightMode`

-----------------------

### **1\. Adjust the Flight Mode Potentiometer**

-   Turning the potentiometer changes the selected flight mode.

### **2\. Monitor Flight Mode in the Serial Output**

-   The current flight mode is displayed in the serial monitor:

    `Serial.print(", Flight Mode: ");

    Serial.println(flightMode);`

### **3\. Modify Flight Behavior in Code (Optional)**

-   Customize how stabilization is applied in each mode.

* * * * *

Example Logic Based on `flightMode`

-----------------------------------

`if (flightMode == 1) {

    // Beginner Mode: Strong auto-stabilization

    pitchGain = constrain(pitchGain + 20, 0, 100);

    rollGain = constrain(rollGain + 20, 0, 100);

}

else if (flightMode == 2) {

    // Intermediate Mode: Moderate assistance

    pitchGain = constrain(pitchGain + 10, 0, 100);

    rollGain = constrain(rollGain + 10, 0, 100);

}

else {

    // Expert Mode: Full manual control

    pitchGain = pitchGain;  // No modification

    rollGain = rollGain;

}`