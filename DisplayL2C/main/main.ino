//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int charcount = 0;

void setup()
{
	lcd.init();
	lcd.backlight();
  
  // Print a message to the LCD.
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
  lcd.setCursor(0,1);
  lcd.print("Digite no Serial:");

	// Initialize the serial port at a speed of 9600 baud
	Serial.begin(9600);
}

void loop()
{
	// If characters arrived over the serial port...
	if (Serial.available()) {
		// Wait a bit for the entire message to arrive
		delay(100);
		// Clear the screen
		lcd.clear();

		// Write all characters received with the serial port to the LCD.
		charcount = 0;
    lcd.setCursor(0,0);

    //String SerialMessage = Serial.readString();
    //lcd.printstr(SerialMessage.c_str());
    while (Serial.available() > 0) {
      lcd.write(Serial.read());
    }
    

	}
}