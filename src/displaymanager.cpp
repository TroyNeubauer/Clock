#include "displaymanager.h"

DisplayManager::DisplayManager(uint8_t pinA1, uint8_t pinB1, uint8_t pinC1, uint8_t pinD1, uint8_t pinE1, uint8_t pinF1, uint8_t pinG1, 
	uint8_t pinDot1, uint8_t pinD1A, uint8_t pinD2A, uint8_t pinD3A, uint8_t pinD4A) {
	displayCount = 1;

}

DisplayManager::DisplayManager(uint8_t pinA1, uint8_t pinB1, uint8_t pinC1, uint8_t pinD1, uint8_t pinE1, uint8_t pinF1, uint8_t pinG1, 
	uint8_t pinDot1, uint8_t pinD1A, uint8_t pinD2A, uint8_t pinD3A, uint8_t pinD4A,
	uint8_t pinA2, uint8_t pinB2, uint8_t pinC2, uint8_t pinD2, uint8_t pinE2, uint8_t pinF2, uint8_t pinG2, 
	uint8_t pinDot2, uint8_t pinD1B, uint8_t pinD2B, uint8_t pinD3B, uint8_t pinD4B) {
	displayCount = 2;
}



void DisplayManager::setTime(uint32_t millis) {

}
void DisplayManager::setFloat(float value) {

}

void DisplayManager::setValue(uint32_t value) {
	for(int i = 0; i < displayCount && value > 0; i++) {
		Display display = displays[i];
		display.setNumber(value);
		value /= 10000;
	}
}

void DisplayManager::display() {
	for(int i = 0; i < displayCount; i++) {
		displays[i].display();
	}
}

DisplayManager::~DisplayManager() {
	delete[] displays;
}