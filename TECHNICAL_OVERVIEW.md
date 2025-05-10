# Arduino Stopwatch & Countdown Timer – Technical Overview

This document provides a detailed explanation of the core technologies, communication protocols, hardware concepts, and development tools used in the Arduino Stopwatch & Countdown Timer project. It serves as a quick reference for recruiters, collaborators, or anyone exploring the repository.

---

## 🔧 Development Tools & Languages

### **Arduino IDE (Integrated Development Environment)**

An all-in-one software platform used to write, compile, upload, and monitor Arduino programs.

**Usage:**

* Wrote the full project logic in a `.ino` file
* Compiled and uploaded the code to Arduino Uno
* Used serial monitor for debugging and interaction (if needed)

### **C++ Programming (Arduino)**

Arduino sketches are written in simplified C++, allowing object-oriented design alongside procedural logic.

**Usage:**

* Defined variables, functions, and structures using C++ syntax
* Used C++ features like `enum`, constructors (e.g., `LiquidCrystal_I2C lcd(...)`), and libraries

---

## 🔌 Communication Protocols

### **I²C Protocol (Inter-Integrated Circuit)**

A two-wire serial communication protocol used to communicate between microcontroller and peripherals.

**Usage:**

* Used to communicate with the 16x2 LCD module
* Enabled display of menus, time values, and real-time updates
* Implemented via the `LiquidCrystal_I2C` library using pins SDA and SCL

---

## ⚡ Hardware Interfaces

### **GPIO (General Purpose Input/Output)**

Digital pins used to receive inputs and send signals to connected components.

**Usage:**

* **Inputs:** Connected to three push buttons (Start, Stop, Reset) with `INPUT_PULLUP` configuration
* **Output:** Used for driving a piezo buzzer for audio feedback using the `tone()` function

### **Buzzer Control**

Controlled via digital pin using Arduino's `tone()` function.

**Usage:**

* Played short tones every 30 seconds
* Played a long tone when the countdown reached 00:00

---

## 🔁 Software Architecture

### **FSM (Finite State Machine) Design**

A structured approach to managing system behavior based on defined states and transitions.

**Usage:**

* Implemented states: Mode Selection → Countdown/Stopwatch → Time Setup → Running Timer
* Transitions based on button inputs and time logic
* Managed via an `enum Mode` and Boolean flags (`running`, `timeConfigured`, `modeSelected`)
* Enabled intuitive flow and clear structure in the main loop

---

## 🎮 Hardware-Based User Experience (UX)

### **Physical Interaction Logic**

Interaction with the system happens entirely through hardware: buttons, screen, and buzzer.

**Usage:**

* LCD displays real-time feedback: current mode, countdown value, stopwatch time
* Blinking colon creates visual animation like a real clock
* Multi-function buttons for navigating menu, setting time, starting/stopping/resetting the timer
* Long press on Reset returns user to mode selection menu

---

## 🧠 Key Concepts Demonstrated

* Real-time logic using `millis()` (non-blocking time tracking)
* State machine (FSM) architecture for managing user flow
* Embedded UX via physical components
* I²C-based LCD communication
* Modular code design with reusable logic blocks
* Event-driven control with GPIO
* Use of enums and timing flags to manage asynchronous events

---

This project demonstrates core embedded system skills, combining hardware control with software logic, effective user experience design, and communication protocols.

🔗 [Back to Project Repository](https://github.com/Asaf-Alber/arduino-stopwatch-countdown)
