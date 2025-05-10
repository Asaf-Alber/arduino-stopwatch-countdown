# ⏱️ Arduino Stopwatch & Countdown Timer

A real-time embedded system built with Arduino Uno that functions as both a **stopwatch** and a **countdown timer**, using an I²C LCD, buzzer alerts, and interactive button control. Designed to demonstrate hardware-software integration, user interface logic, and modular embedded programming.

---

## 🚀 Features

- 🧭 **Dual Modes**: Stopwatch & Countdown
- 🎛️ **Mode Selection Menu** at startup
- 🔧 **Time Setting UI** using buttons (for countdown)
- ⏱️ **Real-Time Logic** using `millis()` (non-blocking)
- 🔔 **Buzzer Alerts**:
  - Every 30 seconds
  - When countdown reaches 0
- 🔁 **Return to Main Menu** via long-press on Reset
- ✨ **Blinking Colon Animation** on LCD display
- 📟 LCD interface via **I²C communication**

---

## 🎮 Controls

| Button       | Function (in Menu)         | Function (in Operation)        |
|--------------|----------------------------|--------------------------------|
| **Start**    | Select Stopwatch           | Start timer / Add minutes      |
| **Stop**     | Select Countdown           | Pause timer / Add seconds      |
| **Reset**    | Confirm mode selection     | Short press = reset<br>Long press = return to menu |

---

## 🛠️ Technologies Used

- **Arduino Uno**
- **C++ (Arduino IDE)**
- **I²C protocol** (LCD communication)
- **Digital I/O** (buttons with pull-up resistors)
- **Buzzer output** using `tone()`
- **Real-time timing** using `millis()`
- **Finite State Machine (FSM)** for menu logic

---

## 📁 File Structure

├── stopwatch_countdown.ino // Main Arduino sketch
├── README.md // Project documentation
└── images/ // (Optional) Photos or demo GIFs


---

## 📷 Demo

![Hardware Demo](images/IMG_9317.jpg)


---

## 💡 How It Works

1. On power-up, the user selects between **Stopwatch** and **Countdown** using the buttons.
2. In **Countdown Mode**, the user configures time before starting (in minutes/seconds).
3. The system tracks time using `millis()` (no delays), with dynamic LCD display and buzzer signals.
4. A long press on Reset returns to the main menu.

---

## 🧠 Skills Demonstrated

- Embedded C++ development
- Real-time system design
- User interface logic on microcontrollers
- Hardware integration: I²C, buzzer, button inputs
- Modular, maintainable code structure
- Practical use of finite state machines (FSM)

---

## 🗣️ Author

**Asaf Alber**  
[GitHub Profile](https://github.com/Asaf-Alber)  
Built as a personal embedded systems learning project using Arduino.

---

## 📌 License

MIT License (if you want to allow others to use your code)
