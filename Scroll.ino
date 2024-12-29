#include <LiquidCrystal.h>

// Pin definitions
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int contrastPin = 6;
const int contrast = 160;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Scrolling parameters
bool scrollingLeft = true;  // Direction flag
const int scrollDelay = 500;  // Adjust for scroll speed
const String message = "Utkarsh Bhau Maza avishkar!";  // Added spaces for better scrolling effect

void setup() {
  // Initialize serial for debugging
  Serial.begin(9600);
  Serial.println("LCD Test Starting...");
  
  // Set contrast
  pinMode(contrastPin, OUTPUT);
  analogWrite(contrastPin, contrast);
  
  // Initialize LCD
  lcd.begin(16, 2);
  delay(100);
  lcd.clear();
  
  // Display initial message
  lcd.home();
  lcd.print(message);
  Serial.println("Initial text displayed");
  
  delay(1000);
}

void loop() {
  if (scrollingLeft) {
    lcd.scrollDisplayLeft();
  } else {
    lcd.scrollDisplayRight();
  }
  
  // Switch direction when text reaches the edge
  static int position = 0;
  if (scrollingLeft) {
    position++;
    if (position >= message.length()) {
      scrollingLeft = false;
      position = message.length();
    }
  } else {
    position--;
    if (position <= 0) {
      scrollingLeft = true;
      position = 0;
    }
  }
  
  delay(scrollDelay);  // Control scrolling speed
}