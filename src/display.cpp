#include "display.h"
#include <stdio.h>
#include <string.h>
#include <Arduino.h>

const uint8_t POWER_OF_TWO[] = {0b1, 0b10, 0b100, 0b1000};

void Display::setDigit(uint8_t value, uint8_t digit) {
	switch(digit){
		case 0:
			setImpl(DISPLAY_A,digit);setImpl(DISPLAY_B,digit);setImpl(DISPLAY_C,digit);setImpl(DISPLAY_D,digit);setImpl(DISPLAY_E,digit);setImpl(DISPLAY_F,digit);
			break;
		case 1:
			setImpl(DISPLAY_B,digit);setImpl(DISPLAY_C,digit);
			break;
		case 2:
			setImpl(DISPLAY_A,digit);setImpl(DISPLAY_B,digit);setImpl(DISPLAY_G,digit);setImpl(DISPLAY_E,digit);setImpl(DISPLAY_D,digit);
			break;
		case 3:
			setImpl(DISPLAY_A,digit);setImpl(DISPLAY_B,digit);setImpl(DISPLAY_G,digit);setImpl(DISPLAY_C,digit);setImpl(DISPLAY_D,digit);
			break;
		case 4:
			setImpl(DISPLAY_B,digit);setImpl(DISPLAY_C,digit);setImpl(DISPLAY_G,digit);setImpl(DISPLAY_F,digit);
			break;
		case 5:
			setImpl(DISPLAY_A,digit);setImpl(DISPLAY_C,digit);setImpl(DISPLAY_D,digit);setImpl(DISPLAY_F,digit);setImpl(DISPLAY_G,digit);
			break;
		case 6:
			setImpl(DISPLAY_A,digit);setImpl(DISPLAY_C,digit);setImpl(DISPLAY_D,digit);setImpl(DISPLAY_E,digit);setImpl(DISPLAY_F,digit);setImpl(DISPLAY_G,digit);
			break;
		case 7:
			setImpl(DISPLAY_A,digit);setImpl(DISPLAY_B,digit);setImpl(DISPLAY_C,digit);
			break;
		case 8:
			setImpl(DISPLAY_A,digit);setImpl(DISPLAY_B,digit);setImpl(DISPLAY_C,digit);setImpl(DISPLAY_D,digit);setImpl(DISPLAY_E,digit);setImpl(DISPLAY_F,digit);setImpl(DISPLAY_G,digit);
			break;
		case 9:
			setImpl(DISPLAY_A,digit);setImpl(DISPLAY_B,digit);setImpl(DISPLAY_C,digit);setImpl(DISPLAY_D,digit);setImpl(DISPLAY_F,digit);setImpl(DISPLAY_G,digit);
			break;
  	}
}

void Display::setNumber(int number) {

}

void Display::display() {
	if(data[DISPLAY_A]) {
		digitalWrite(pinD4, ((data[DISPLAY_A] >> 0) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD3, ((data[DISPLAY_A] >> 1) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD2, ((data[DISPLAY_A] >> 2) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD1, ((data[DISPLAY_A] >> 3) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinA, HIGH);
		digitalWrite(pinD4, LOW);
		digitalWrite(pinD3, LOW);
		digitalWrite(pinD2, LOW);
		digitalWrite(pinD1, LOW);
		digitalWrite(pinA, LOW);
	}
	if(data[DISPLAY_B]) {
		
	}
	if(data[DISPLAY_C]) {
		
	}
	if(data[DISPLAY_D]) {
		
	}
	if(data[DISPLAY_E]) {
		
	}
	if(data[DISPLAY_F]) {
		
	}
	if(data[DISPLAY_G]) {
		
	}
	if(data[DISPLAY_DOT]) {
		
	}
}

inline void Display::setImpl(uint8_t segment, uint8_t digit) {//Digits go 0 for 1's, 1 for 10's, 2 for 100's and 3 for 1000's
	data[segment] |= POWER_OF_TWO[digit];
}

void Display::clear() {
	memset(&data, 0, sizeof(data));
}