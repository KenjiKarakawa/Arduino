/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

/*

AUTHOR: Hazim Bitar (techbitar)
DATE: Aug 29, 2013
LICENSE: Public domain (use at your own risk)
CONTACT: techbitar at gmail dot com (techbitar.com)

*/


#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

void setup()
{
  //pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  //digitalWrite(9, HIGH);
  Serial.begin(9600);
  Serial.println("Enter AT commands2:");
  BTSerial.begin(9600);  // HC-05 default speed in AT command more
}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());
}


// #include <LiquidCrystal.h>
// #include <SoftwareSerial.h>

// // initialize the library by associating any needed LCD interface pin
// // with the arduino pin number it is connected to
// const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// String MessageL0 = "";
// String MessageL1 = "";

// SoftwareSerial BTSerial(9, 10); // RX | TX

// void printLCD(String &Message, int line = 0)
// { 
//   lcd.setCursor(0, 2 - line);
//   lcd.print(Message);
// }

// void setup()
// {
//   // Print a message to the LCD.
//   MessageL0 = "Teste de Tempo:";
//   printLCD(MessageL0);
 
//   pinMode(8, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
//   digitalWrite(8, HIGH);
//   //digitalWrite(8, LOW);
//   Serial.begin(300);
//   Serial.println("Enter AT commands:");
//   BTSerial.begin(9600);  // HC-05 default speed in AT command more
// }

// void loop()
// {

//   // Keep reading from HC-05 and send to Arduino Serial Monitor
//   if (BTSerial.available())
//   {
//     //String Teste = BTSerial.readString();
//     //Serial.write(BTSerial.read());
//     //printLCD(Teste, 2);
//   }

//   // Keep reading from Arduino Serial Monitor and send to HC-05
//   if (Serial.available())
//   {
//     // String Teste = Serial.readString();
//     // Serial.println(Teste);
//     // printLCD(Teste, 2);
//     BTSerial.write(Serial.read());
//   }
// }
