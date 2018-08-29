#include "Arduino.h"
#include "displaymanager.h"

DisplayManager::DisplayManager() : displays() {}

void DisplayManager::addDisplay(Display* display) {
	if(displayCount >= MAX_DISPLAYS) {
		Serial.println("TOO MANY DISPLAYS");
	}
	displays[displayCount++] = display;
}

void DisplayManager::setTime(uint32_t millis) {

}
void DisplayManager::setFloat(float value) {

}

void DisplayManager::setValue(uint32_t value) {
	if(lastValue == UINT32_MAX || lastValue != value) {
		for(int i = 0; i < displayCount; i++) {
			displays[i]->setNumber(value);
		}
	}
}

void DisplayManager::display() {
	for(int i = 0; i < displayCount; i++) {
		displays[i]->display();
	}
}