# Arduino Stopwatch & Countdown Timer – Technical Overview

This document provides a brief explanation of the core technologies, protocols, and concepts implemented in the Arduino Stopwatch & Countdown Timer project. It serves as a quick reference for recruiters, collaborators, or anyone exploring the repository.

---

## 🔧 Development Tools

### **Arduino IDE (Integrated Development Environment)**
An all-in-one software for writing, compiling, uploading, and monitoring Arduino code. It was used to develop the entire project logic in a `.ino` sketch.

**Usage:**
- Write and save code
- Compile and upload to the Arduino Uno
- Monitor debug output

---

## 🔌 Communication Protocols

### **I²C Protocol (Inter-Integrated Circuit)**
A two-wire serial communication protocol used to connect multiple peripherals to a microcontroller.

**Usage in the Project:**
- Used to interface the 16x2 LCD display via only 2 wires (SCL & SDA)
- Enabled clean, efficient connection using the `LiquidCrystal_I2C` library

---

## ⚡ Hardware Interfaces

### **GPIO (General Purpose Input/Output)**
Digital pins on the Arduino configured as either inputs or outputs.

**Usage in the Project:**
- **Input:** 3 pushbuttons connected to GPIO with internal pull-up resistors
- **Output:** A buzzer connected to a GPIO pin, triggered using the `tone()` function

---

## 🔁 Software Architecture

### **FSM (Finite State Machine) Design**
A programming pattern where the system transitions between defined states based on user input or events.

**Usage in the Project:**
- Managed navigation between modes: Menu, Stopwatch, Countdown, and Time Setup
- Used flags (`running`, `modeSelected`, `timeConfigured`) and an `enum` for mode logic
- Enabled long-press and short-press functionality on the Reset button

---

## 🎮 Hardware-Based User Experience (UX)

### **What is it?**
Designing intuitive interactions between users and hardware systems through physical components.

**Usage in the Project:**
- LCD shows mode selection, current time, and prompts
- Blinking colon animation improves visual feedback
- Buttons provide multi-function input (set time, start, stop, reset)
- Buzzer offers auditory feedback at 30-second intervals and timeout

---

This project demonstrates core embedded system skills such as real-time logic, physical UX design, hardware/software interfacing, and state-driven architecture.

🔗 [Back to Project Repository](https://github.com/Asaf-Alber/arduino-stopwatch-countdown)
