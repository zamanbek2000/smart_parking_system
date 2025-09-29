#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set LCD address (usually 0x27 or 0x3F)
// If unsure, run an I2C scanner sketch to find it
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define ENTRY_SENSOR 8
#define EXIT_SENSOR 9

int totalSpaces = 20;
int availableSpaces = 20;

void setup() {
  pinMode(ENTRY_SENSOR, INPUT);
  pinMode(EXIT_SENSOR, INPUT);

  lcd.init();       // initialize LCD
  lcd.backlight();  // turn on backlight

  lcd.setCursor(0, 0);
  lcd.print("Smart Parking");
  delay(2000);
  updateLCD();
}

void loop() {
  // Entry detection
  if (digitalRead(ENTRY_SENSOR) == LOW) {  // sensor active LOW
    if (availableSpaces > 0) {
      availableSpaces--;
      updateLCD();
      delay(1000); // debounce delay
    }
  }

  // Exit detection
  if (digitalRead(EXIT_SENSOR) == LOW) {
    if (availableSpaces < totalSpaces) {
      availableSpaces++;
      updateLCD();
      delay(1000); // debounce delay
    }
  }
}

void updateLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Free: ");
  lcd.print(availableSpaces);
  lcd.print("/");
  lcd.print(totalSpaces);

  lcd.setCursor(0, 1);
  if (availableSpaces == 0) {
    lcd.print("Parking Busy");
  } else {
    lcd.print("Available");
  }
}
