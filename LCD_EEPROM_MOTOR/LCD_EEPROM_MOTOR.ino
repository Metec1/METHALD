#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define up 3
#define down 4
#define onay 5
#define resetPin 6
unsigned long prevtime1 = millis();
int a = 0;


void setup() {
  Serial.begin(9600);
  pinMode(up, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
  pinMode(onay, INPUT_PULLUP);
  pinMode(resetPin, INPUT_PULLUP); // Set reset pin as input
  pinMode(10, OUTPUT);
  lcd.init();
  lcd.backlight();
  a = EEPROM.read(0);
}

void ekran() {
  lcd.setCursor(0, 0);
  lcd.print(a);
}

void resetSystem() {
  EEPROM.write(0,0);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Restarting");
  delay(1000); // Optional delay for visual effect
  asm volatile ("  jmp 0"); // Soft reset
  

  analogWrite(10, 0);
  // Optionally, print a message to indicate reset
  
  
}

void loop() {
  if (digitalRead(down) == LOW) {
    lcd.clear();
    a = a - 10;
    if (a < 0) {
      a = 0;
    }
    if (a > 255) {
      a = 255;
    }
    while (digitalRead(down) == LOW);
  }

  if (digitalRead(up) == LOW) {
    lcd.clear();
    a = a + 10;
    if (a < 0) {
      a = 0;
    }
    if (a > 255) {
      a = 255;
    }
    while (digitalRead(up) == LOW);
  }

  if (digitalRead(onay) == LOW) {
    analogWrite(10, a);
    EEPROM.write(0, a);
    while (digitalRead(onay) == LOW);
  }


   if (digitalRead(resetPin) == LOW) {
    unsigned long currentTime = millis();
    if (currentTime - prevtime1 >= 4000) {
      resetSystem(); 
    }
  } else {
    prevtime1 = millis(); 
  }

  ekran();
}
