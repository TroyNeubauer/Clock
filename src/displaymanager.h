#include "display.h"
#include "stdint.h"

class DisplayManager {
private:
	Display displays[8];
	uint32_t lastValue;
	uint8_t displayCount;
public:
	DisplayManager(uint8_t pinA1, uint8_t pinB1, uint8_t pinC1, uint8_t pinD1, uint8_t pinE1, uint8_t pinF1, uint8_t pinG1, 
		uint8_t pinDot1, uint8_t pinD1A, uint8_t pinD2A, uint8_t pinD3A, uint8_t pinD4A);

	DisplayManager(uint8_t pinA1, uint8_t pinB1, uint8_t pinC1, uint8_t pinD1, uint8_t pinE1, uint8_t pinF1, uint8_t pinG1, 
		uint8_t pinDot1, uint8_t pinD1A, uint8_t pinD2A, uint8_t pinD3A, uint8_t pinD4A,
		uint8_t pinA2, uint8_t pinB2, uint8_t pinC2, uint8_t pinD2, uint8_t pinE2, uint8_t pinF2, uint8_t pinG2, 
		uint8_t pinDot2, uint8_t pinD1B, uint8_t pinD2B, uint8_t pinD3B, uint8_t pinD4B);

	void setTime(uint32_t millis);
	void setFloat(float value);
	void setValue(uint32_t value);
	void display();

	~DisplayManager();
};