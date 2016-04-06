/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	Aqua_Mate
	Aquarium controler 
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

(C) 22/03/2016

 Arduino	NANO

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

RGB LEDs  WS2801
#include <Adafruit_NeoPixel.h>
-------------------------------
data in:			-> D13
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 Real Time Clock (RTC) DS1307
 #include <DS1307.h>
 ----------------------------
          SDA pin   -> A4 (SDA)
          SCL pin   -> A5 (SCL)
 example: DS1307_Serial_Easy 
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

20x4 LCD Display
#include <LiquidCrystal.h>
--------------------------
 LCD:     DB7       -> D2
          DB6       -> D3
          DB5       -> D4
          DB4       -> D5
          E         -> D6
          RS        -> D7
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

//  Include drivers ******************************************************************

#include <Adafruit_NeoPixel.h>
#include <DS1307.h>
#include <LiquidCrystal.h>
#include <string.h>
#include <stdio.h>

// Dim Global variables **************************************************************

int Red = 0;			// value for Red led
int Green = 0;			// value for Green led
int Blue = 0;			// value for Blue led
int Pin = 13;			// Data pin for led control
int counter = 0;		// time counter 
bool M = true;			// marker for Morning
bool D = false;			// marker for Daytime
bool E = false;			// marker for Evening
bool N = false;			// marker for Night
bool Light_on = false;  // turn LEDs on if true

// Initialise modules ****************************************************************

// Init RGB LEDs library
Adafruit_NeoPixel strip = Adafruit_NeoPixel(11, Pin, NEO_GRB + NEO_KHZ800);
// Init the DS1307 library
//DS1307 rtc(SDA, SCL);
// Init the LCD library
//LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

//** Setup Program *******************************************************************
void setup()
{
	//** LEDs set up
	strip.begin();
	strip.show(); // Initialize all pixels to 'off'

	//** Setup Serial connection
	//Serial.begin(115200);

    //** Set Date and Time ********
	// Initialize the rtc object
	//rtc.begin();

	//** Set the clock to run-mode
	//rtc.halt(false);

	// The following lines can be uncommented to set the time
	// rtc.setDOW(SATURDAY);           // Set Day-of-Week to SUNDAY
	// rtc.setTime(22,43, 00);     // Set the time to 12:00:00 (24hr format)
	// rtc.setDate(26, 3, 2016);    // Set the date to October 3th, 2010

	// Setup LCD to 20x4 characters
	//lcd.begin(20, 4);
	
}

// Main Program Loop *****************************************************************
void loop()
{
	
	// Send Date and Time to serial port
	//Read_Time();
	//Display_Time();

	if (M == true) {
		RGB_Control_White();
	}
/*
	if (G == true) {
		RGB_Control_Green();
	}

	if (B == true) {
		RGB_Control_Blue();
	}
*/
	//Display_RGB();
		
	// Wait one second before repeating :)
	delay (1000);

}

//** END OF PROGRAM LOOP *******************************************************

//** SUB ROUTINES  *************************************************************

//** Set pin for LED board *****************************************************
void Set_LEDBoard() {
	Adafruit_NeoPixel strip = Adafruit_NeoPixel(11, Pin, NEO_GRB + NEO_KHZ800);
}

//** Send Date and Time to coms ************************************************
void Read_Time(){

	/*String Time_H = String(4);		    //local variable for hours mins and seconds
	String Time_M = String(4);		    //
	String Time_S = String(4);		    //

	Time_H[0] = rtc.getTimeStr()[0];	//
	Time_H[1] = rtc.getTimeStr()[1];	//

	lcd.setCursor(4, 2);
	lcd.print(Time_H);
	//lcd.setCursor(5, 2);
	//lcd.print(Time_H[0]);
		
	Time_M = rtc.getTimeStr()[4];		//
	Time_S = rtc.getTimeStr()[7];		//
	
	
	lcd.setCursor(8, 2);
	lcd.print(Time_M);
	lcd.setCursor(12, 2);
	lcd.print(Time_S);
	*/
}

//** Send Date and Time to coms ************************************************
void Display_Time(){
	/*
	// Display abbreviated Day-of-Week in the lower left corner
	lcd.setCursor(0, 0);
	lcd.print(rtc.getDOWStr(FORMAT_SHORT));

	lcd.setCursor(4, 0);
	lcd.print(rtc.getDateStr());

	lcd.setCursor(4, 1);
	lcd.print(rtc.getTimeStr());
	*/
}

//**  RGB LED White **********************************************************
void RGB_Control_White() {

	// Adafruit_NeoPixel strip = Adafruit_NeoPixel(250, Pin, NEO_GRB + NEO_KHZ800);
// fade in orange
	if (Red < 25) {
		Red++;
		Green++;
		//Blue++;
        colorWipe(strip.Color(Red, Green, Blue, 0), 0); // White RGBW
	}
// fade in white
	if (Red > 24) {
		Red++;
		Green++;
		Blue++;
		colorWipe(strip.Color(Red, Green, Blue, 0), 0); // White RGBW
	}
// fade in blue
	if (Red > 31) {
		Red = 33;
		Green = 33;
		Blue++;
		colorWipe(strip.Color(Red, Green, Blue, 0), 0); // White RGBW
	}

	if (Blue > 50) {
		while (Red > 1) {
			colorWipe(strip.Color(Red, Green, Blue, 0), 0); 
			Red--;
			Green--;
			Blue--;
			Display_RGB();
			delay (1000);
		}

		
	}

}
//**  RGB LED Green **********************************************************
void RGB_Control_Green() {

	// Adafruit_NeoPixel strip = Adafruit_NeoPixel(250, Pin, NEO_GRB + NEO_KHZ800);
	
	if (Green < 25) {
		colorWipe(strip.Color(Red, Green, Blue, 0), 0); // White RGBW
														//Red++;
		Green++;
		//Blue++;
	}

	if (Green > 24) {
		colorWipe(strip.Color(Red, Green, Blue, 0), 0); // White RGBW
														//Red++;
		Green++;
		Blue++;
	}

	if (Green > 31) {
		
		Green = 30;
		Blue = 30;
		
	}

}
//**  RGB LED Green **********************************************************
void RGB_Control_Blue() {

	// Adafruit_NeoPixel strip = Adafruit_NeoPixel(250, Pin, NEO_GRB + NEO_KHZ800);
	
	if (Red < 25) {
		colorWipe(strip.Color(Red, Green, Blue, 0), 0); // White RGBW
														//Red++;
		Green++;
		//Blue++;
	}

	if (Red > 24) {
		colorWipe(strip.Color(Red, Green, Blue, 0), 0); // White RGBW
														//Red++;
		Green++;
		Blue++;
	}

	if (Red > 31) {
		//Red = 30;
		Green = 30;
		Blue = 30;
		//G = false;
		//B = true;
	}

}
//** Display RGB values on LCD *************************************************
void Display_RGB() {
/*
	lcd.setCursor(0, 3);
	lcd.print("R ");
	lcd.print(Red);

	lcd.setCursor(7, 3);
	lcd.print("G ");
	lcd.print(Green);

	lcd.setCursor(14, 3);
	lcd.print("B ");
	lcd.print(Blue);
	*/

}

//** Fill the LED dots one after the other with a color ************************
void colorWipe(uint32_t c, uint8_t wait) {
	for (uint16_t i = 0; i < strip.numPixels(); i++) {
		strip.setPixelColor(i, c);
		strip.show();
		//delay(10);
	}
}


