# Arduino Elevator Control System (3 Floors)

This project is a simple Arduino-based elevator prototype controlling a 3-floor system using motors, buttons, and IR sensors.

It is inspired by an Instructables project and rebuilt to better understand embedded systems and control logic.

## 🚀 Features

* 3-floor control system
* Floor selection using push buttons
* IR sensors for floor detection
* Motor control for upward and downward movement
* 7-segment display showing current floor

## 🧠 How It Works

Each floor has:

* A button to request the elevator
* An IR sensor to detect when the elevator reaches that floor

When a button is pressed:

* The system checks the current position
* Moves the elevator in the correct direction
* Stops when the corresponding sensor is triggered

## 🔌 Components Used

* Arduino (Uno or similar)
* Motor driver module
* DC motor
* IR sensors (x3)
* Push buttons (x3)
* 7-segment display
* Resistors and wires

## ⚠️ Limitations

* Uses blocking `while()` loops (not optimized)
* No queue system for multiple requests
* Basic control logic (not state-based)
* Minimal safety handling

## 🛠️ Future Improvements

* Replace 7-segment display with LCD
* Implement a request queue system
* Add smooth acceleration/deceleration
* Refactor code using a state machine
* Improve responsiveness (remove blocking loops)

## 📌 Note

This is a learning project and an early prototype. Improvements and refactoring are planned.

## 📷 Demo

(Add images or videos here)

---
