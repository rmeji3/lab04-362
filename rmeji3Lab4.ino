/*
// Rafael Mejia, 679124181 rmeji3
// Lab 4 - Analog Input: Photoresistor (LDR – Light Dependent Resistor)
// Description - Create a circuit and program that will use a photoresistor and the 16x2 display.
The display should state the relative amount of light in the room as one of 5 predefined text values based
on the value read from the photocell. The 5 predefined text values are:
• dark
• partially dark
• medium
• fully lit
• brightly lit
These values are to be displayed on the top line of the 16x2 LCD display.
On the bottom line of the LCD display, you are to display the number of milliseconds since that reset of
the Arduino. This value must be continuously updating.
// References - https://www.circuitbasics.com/how-to-use-photoresistors-to-detect-light-on-an-arduino/
https://docs.arduino.cc/learn/electronics/lcd-displays/
*/
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int photoPin = A0;
int dark = 20, partiallyDark = 35 , medium = 60, fullyLit = 85;
unsigned long previousMillisSensor = 0; // stores last time sensor was read
const long sensorInterval = 1000;  // interval for reading the photoresistor (1 second)

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillisSensor >= sensorInterval) {
    previousMillisSensor = currentMillis;
    int light = analogRead(photoPin);
    lcd.setCursor(0, 0);
    lcd.print("                "); // Clear the line
    lcd.setCursor(0, 0);
    if(light <= dark){
      lcd.print("dark");
    } else if(light <= partiallyDark){
      lcd.print("partially dark");
    } else if(light <= medium){
      lcd.print("medium");
    } else if(light <= fullyLit){
      lcd.print("fully lit");
    } else {
      lcd.print("brightly lit");
    }
    // lcd.print(analogRead(photoPin));
  } 
  lcd.setCursor(0, 1);
  lcd.setCursor(0, 1);
  lcd.print(currentMillis);      // Print the updated millis value
}