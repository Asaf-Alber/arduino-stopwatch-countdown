# Arduino Stopwatch & Countdown Timer ⏱️

An interactive real-time stopwatch and countdown timer built with Arduino Uno, LCD (I²C), buzzer, and button interface.

## 🚀 Features
- ⏲️ Dual modes: Stopwatch and Countdown
- 🧭 Menu navigation with buttons (Start / Stop / Reset)
- 🔄 Time configuration via buttons (for countdown)
- 🔔 Buzzer alerts every 30 seconds and when time is up
- 🎛️ Return-to-menu with long-press
- ✨ Blinking colon animation on LCD

## 📷 Demo
_Add a photo or GIF of your working circuit here if you have one!_

## 🛠️ Technologies Used
- Arduino Uno
- C++ (Arduino IDE)
- I²C communication protocol (LiquidCrystal_I2C)
- Digital I/O with pull-up buttons
- Buzzer via tone()
- Non-blocking timing with `millis()`
- Finite State Machine (FSM) for menu and mode control

## 🧠 Skills Demonstrated
- Embedded systems programming (real-time logic)
- Hardware-software integration (buttons, buzzer, LCD)
- UX logic on microcontroller
- Code modularity and maintainability
- Functional design without delay()

## 🗂️ File Structure

