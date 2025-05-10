#include <Wire.h>                 // Include library for I2C communication
#include <LiquidCrystal_I2C.h>    // Include library for LCD control via I2C

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Create LCD object: address 0x27, 16 columns, 2 rows

// Button and buzzer pins
const int startBtn = 2;  // Start button (connected to pin 2)
const int stopBtn  = 3;  // Stop button (connected to pin 3)
const int resetBtn = 4;  // Reset/Menu button (connected to pin 4)
const int buzzer   = 5;  // Buzzer pin

// Mode selection enum
enum Mode { STOPWATCH, COUNTDOWN };
Mode currentMode = STOPWATCH;  // Default mode is Stopwatch

// State flags
bool running = false;           // Is the timer currently running?
bool modeSelected = false;      // Has the user selected a mode?
bool timeConfigured = false;    // Has time been configured for countdown?
bool colonVisible = true;       // Whether to show or blink the colon on display

// Time variables
int minutes = 0;
int seconds = 0;
unsigned long previousMillis = 0;  // For non-blocking time tracking


void setup() {
  lcd.init();              // Initialize the LCD
  lcd.backlight();         // Turn on backlight

  // Set up buttons as input with internal pull-up resistors
  pinMode(startBtn, INPUT_PULLUP);
  pinMode(stopBtn,  INPUT_PULLUP);
  pinMode(resetBtn, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT); // Set buzzer as output

  showModeMenu();          // Show initial mode selection screen
}


void loop() {
  // --- Mode selection menu ---
  if (!modeSelected) {
    if (digitalRead(startBtn) == LOW) {
      currentMode = STOPWATCH;     // If Start pressed → select Stopwatch
      showModeMenu();
      delay(200);
    }

    if (digitalRead(stopBtn) == LOW) {
      currentMode = COUNTDOWN;     // If Stop pressed → select Countdown
      showModeMenu();
      delay(200);
    }

    if (digitalRead(resetBtn) == LOW) {
      modeSelected = true;         // Confirm mode selection
      lcd.clear();

      if (currentMode == COUNTDOWN) {
        configureCountdown();      // Go to time-setting screen
      } else {
        initializeMode();          // Start Stopwatch mode
      }
      delay(200);
    }

    return; // Stop here until mode is selected
  }

  // --- Start button ---
  if (digitalRead(startBtn) == LOW) {
    if (currentMode == COUNTDOWN && !timeConfigured) {
      lcd.setCursor(0, 0);
      lcd.print("Set time first!");  // Prevent start if countdown time not set
      delay(800);
    } else {
      running = true;               // Start the timer
    }
    delay(200);
  }

  // --- Stop button ---
  if (digitalRead(stopBtn) == LOW) {
    running = false;               // Pause the timer
    delay(200);
  }

  // --- Reset/Menu button ---
  if (digitalRead(resetBtn) == LOW) {
    unsigned long holdStart = millis();       // Track when button was pressed

    while (digitalRead(resetBtn) == LOW);     // Wait until button is released

    if (millis() - holdStart > 1000) {
      // Long press → return to menu
      modeSelected = false;
      timeConfigured = false;
      running = false;
      showModeMenu();
    } else {
      // Short press → reset time
      running = false;

      if (currentMode == COUNTDOWN) {
        configureCountdown();  // Go back to time configuration
      } else {
        minutes = 0;
        seconds = 0;
        displayTime();         // Reset to 00:00
      }
    }

    delay(200);
  }

  // --- Timer logic ---
  if (running) {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= 1000) {
      previousMillis = currentMillis;
      colonVisible = !colonVisible;  // Toggle colon every second for blinking

      if (currentMode == STOPWATCH) {
        seconds++;
        if (seconds == 60) {
          seconds = 0;
          minutes++;
        }

        if (seconds % 30 == 0 && seconds != 0) {
          tone(buzzer, 1000, 300);  // Beep every 30 seconds
        }
      }

      else if (currentMode == COUNTDOWN) {
        if (seconds == 0) {
          if (minutes == 0) {
            running = false;                        // Time's up!
            lcd.setCursor(0, 0);
            lcd.print("   TIME'S UP!   ");
            tone(buzzer, 1000, 1500);               // Long beep
            return;
          } else {
            minutes--;
            seconds = 59;
          }
        } else {
          seconds--;
        }
      }

      displayTime();  // Update display each second
    }
  }
}



void showModeMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select Mode:");  // Menu title

  lcd.setCursor(0, 1);
  if (currentMode == STOPWATCH)
    lcd.print("> Stopwatch");
  else
    lcd.print("> Countdown");
}


void initializeMode() {
  lcd.clear();
  minutes = 0;
  seconds = 0;

  lcd.setCursor(0, 0);
  if (currentMode == COUNTDOWN)
    lcd.print("Countdown Mode");
  else
    lcd.print("Stopwatch Mode");

  displayTime();
}


void displayTime() {
  lcd.setCursor(0, 1);

  if (minutes < 10) lcd.print("0");
  lcd.print(minutes);

  if (colonVisible) lcd.print(":");
  else              lcd.print(" ");

  if (seconds < 10) lcd.print("0");
  lcd.print(seconds);

  lcd.print("     ");  // Clear leftover characters
}


void configureCountdown() {
  minutes = 0;
  seconds = 0;
  timeConfigured = false;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Set Time:");

  unsigned long lastUpdate = 0;
  colonVisible = true;

  displayTime();

  while (true) {
    unsigned long now = millis();

    if (now - lastUpdate >= 500) {
      colonVisible = !colonVisible;
      displayTime();         // Blink colon while setting time
      lastUpdate = now;
    }

    if (digitalRead(startBtn) == LOW) {
      minutes++;
      if (minutes > 59) minutes = 0;
      displayTime();
      delay(250);
    }

    if (digitalRead(stopBtn) == LOW) {
      seconds += 10;
      if (seconds >= 60) seconds = 0;
      displayTime();
      delay(250);
    }

    if (digitalRead(resetBtn) == LOW) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Countdown Set!");
      delay(800);
      timeConfigured = true;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Countdown Mode");
      displayTime();
      break;  // Exit setup loop
    }
  }
}


