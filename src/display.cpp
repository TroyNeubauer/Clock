#include "display.h"
#include <stdio.h>
#include <string.h>
#include <Arduino.h>

const uint8_t POWER_OF_TWO[] = {0b1, 0b10, 0b100, 0b1000};

Display::Display(uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD, uint8_t pinE, uint8_t pinF, uint8_t pinG, 
		uint8_t pinDot, uint8_t pinD1, uint8_t pinD2, uint8_t pinD3, uint8_t pinD4) : 

		pinA(pinA), pinB(pinB), pinC(pinC), pinD(pinD), pinE(pinE), pinF(pinF), pinG(pinG), pinDot(pinDot), 
		pinD1(pinD1), pinD2(pinD2), pinD3(pinD3), pinD4(pinD4), data {0, 0, 0, 0, 0, 0, 0, 0}, lastNumber(UINT32_MAX) {}

Display::Display() : data {0, 0, 0, 0, 0, 0, 0, 0}, lastNumber(UINT32_MAX) {}

void Display::setDigit(uint8_t value, uint8_t digit) {
	switch(value){
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

void Display::setNumber(uint32_t number) {
	//Serial.print("Setting number: ");
	//Serial.println(number);
	if(lastNumber == UINT32_MAX || lastNumber != number) {
		clear();
		if(number > 0) setDigit(number % 10, 0);
		number /= 10;
		if(number > 0) setDigit(number % 10, 1);
		number /= 10;
		if(number > 0) setDigit(number % 10, 2);
		number /= 10;
		if(number > 0) setDigit(number % 10, 3);
		lastNumber = number;
	}
}

void Display::display() {
	if(data[DISPLAY_A]) {
		digitalWrite(pinD4, ((data[DISPLAY_A] >> 0) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD3, ((data[DISPLAY_A] >> 1) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD2, ((data[DISPLAY_A] >> 2) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD1, ((data[DISPLAY_A] >> 3) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinA, HIGH);
		digitalWrite(pinA, LOW);
		digitalWrite(pinD4, HIGH);
		digitalWrite(pinD3, HIGH);
		digitalWrite(pinD2, HIGH);
		digitalWrite(pinD1, HIGH);
	}
	if(data[DISPLAY_B]) {
		digitalWrite(pinD4, ((data[DISPLAY_B] >> 0) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD3, ((data[DISPLAY_B] >> 1) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD2, ((data[DISPLAY_B] >> 2) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD1, ((data[DISPLAY_B] >> 3) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinB, HIGH);
		digitalWrite(pinB, LOW);
		digitalWrite(pinD4, HIGH);
		digitalWrite(pinD3, HIGH);
		digitalWrite(pinD2, HIGH);
		digitalWrite(pinD1, HIGH);
	}
	if(data[DISPLAY_C]) {
		digitalWrite(pinD4, ((data[DISPLAY_C] >> 0) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD3, ((data[DISPLAY_C] >> 1) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD2, ((data[DISPLAY_C] >> 2) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD1, ((data[DISPLAY_C] >> 3) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinC, HIGH);
		digitalWrite(pinC, LOW);
		digitalWrite(pinD4, HIGH);
		digitalWrite(pinD3, HIGH);
		digitalWrite(pinD2, HIGH);
		digitalWrite(pinD1, HIGH);
	}
	if(data[DISPLAY_D]) {
		digitalWrite(pinD4, ((data[DISPLAY_D] >> 0) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD3, ((data[DISPLAY_D] >> 1) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD2, ((data[DISPLAY_D] >> 2) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD1, ((data[DISPLAY_D] >> 3) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD, HIGH);
		digitalWrite(pinD, LOW);
		digitalWrite(pinD4, HIGH);
		digitalWrite(pinD3, HIGH);
		digitalWrite(pinD2, HIGH);
		digitalWrite(pinD1, HIGH);
	}
	if(data[DISPLAY_E]) {
		digitalWrite(pinD4, ((data[DISPLAY_E] >> 0) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD3, ((data[DISPLAY_E] >> 1) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD2, ((data[DISPLAY_E] >> 2) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD1, ((data[DISPLAY_E] >> 3) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinE, HIGH);
		digitalWrite(pinE, LOW);
		digitalWrite(pinD4, HIGH);
		digitalWrite(pinD3, HIGH);
		digitalWrite(pinD2, HIGH);
		digitalWrite(pinD1, HIGH);
	}
	if(data[DISPLAY_F]) {
		digitalWrite(pinD4, ((data[DISPLAY_F] >> 0) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD3, ((data[DISPLAY_F] >> 1) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD2, ((data[DISPLAY_F] >> 2) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD1, ((data[DISPLAY_F] >> 3) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinF, HIGH);
		digitalWrite(pinF, LOW);
		digitalWrite(pinD4, HIGH);
		digitalWrite(pinD3, HIGH);
		digitalWrite(pinD2, HIGH);
		digitalWrite(pinD1, HIGH);
	}
	if(data[DISPLAY_G]) {
		digitalWrite(pinD4, ((data[DISPLAY_G] >> 0) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD3, ((data[DISPLAY_G] >> 1) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD2, ((data[DISPLAY_G] >> 2) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD1, ((data[DISPLAY_G] >> 3) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinG, HIGH);
		digitalWrite(pinG, LOW);
		digitalWrite(pinD4, HIGH);
		digitalWrite(pinD3, HIGH);
		digitalWrite(pinD2, HIGH);
		digitalWrite(pinD1, HIGH);
	}
	if(data[DISPLAY_DOT]) {
		digitalWrite(pinD4, ((data[DISPLAY_DOT] >> 0) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD3, ((data[DISPLAY_DOT] >> 1) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD2, ((data[DISPLAY_DOT] >> 2) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinD1, ((data[DISPLAY_DOT] >> 3) & 0b0001) ? LOW : HIGH);
		digitalWrite(pinDot, HIGH);
		digitalWrite(pinDot, LOW);
		digitalWrite(pinD4, HIGH);
		digitalWrite(pinD3, HIGH);
		digitalWrite(pinD2, HIGH);
		digitalWrite(pinD1, HIGH);
	}
}

inline void Display::setImpl(uint8_t segment, uint8_t digit) {//Digits go 0 for 1's, 1 for 10's, 2 for 100's and 3 for 1000's
	data[segment] |= POWER_OF_TWO[digit];
}

void Display::clear() {
	memset(&data, 0, sizeof(data));
}