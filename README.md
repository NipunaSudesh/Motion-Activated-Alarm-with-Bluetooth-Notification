# Motion-Activated Alarm with Bluetooth Notification

## Project Overview

This project implements a motion-activated alarm system that uses a PIR sensor to detect motion, a buzzer to sound an alert, and an HC-06 Bluetooth module to send a notification message to a connected device. The system is useful for security applications where real-time alerts are needed.

## Components Used

- Arduino Uno
- PIR Sensor
- HC-06 Bluetooth Module
- Buzzer Module
- Breadboard
- Jumper Wires

## Circuit Setup

1. **PIR Sensor Connections:**
   - VCC: Connect to 5V on the Arduino.
   - GND: Connect to GND.
   - OUT: Connect to digital pin `2`.

2. **Buzzer Module Connections:**
   - Positive terminal: Connect to digital pin `7`.
   - Negative terminal: Connect to GND.

3. **HC-06 Bluetooth Module Connections:**
   - VCC: Connect to 5V.
   - GND: Connect to GND.
   - TX: Connect to RX (pin 0) on the Arduino.
   - RX: Connect to TX (pin 1) on the Arduino.

## How It Works

1. The PIR sensor detects motion within its range and sends a signal to the Arduino.
2. When motion is detected:
   - The buzzer sounds an alert.
   - A Bluetooth notification message ("Detected!!!...") is sent via the HC-06 module to a connected smartphone or computer.
3. The message can be received using a serial Bluetooth terminal app on a smartphone or a Bluetooth terminal on a computer.
