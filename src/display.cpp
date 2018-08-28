#include "display.h"
#include <stdio.h>
#include <string.h>
#include <Arduino.h>

const uint8_t POWER_OF_TWO[] = {1, 2, 4, 8};

void Display::setDigit(uint8_t value, uint8_t digit) {

}

void Display::setNumber(int number) {

}

void Display::display() {

}

void Display::setImpl(uint8_t segment, uint8_t digit) {
	data[segment] |= POWER_OF_TWO[digit];
}

void Display::clear() {
	memset(&data, 0, sizeof(data));
}