#pragma once

#include "display.h"
#include "stdint.h"

#define MAX_DISPLAYS 8

class DisplayManager {

private:
	Display* displays[MAX_DISPLAYS];
	uint32_t lastValue = UINT32_MAX;
	uint8_t displayCount = 0;
public:
	DisplayManager();
	void addDisplay(Display* display);
	void setTime(uint32_t millis);
	void setFloat(float value);
	void setValue(uint32_t value);
	void display();
};