#include <stdint.h>
#define ON 1
#define OFF 0

#define DISPLAY_A 0
#define DISPLAY_B 1
#define DISPLAY_C 2
#define DISPLAY_D 3
#define DISPLAY_E 4
#define DISPLAY_F 5
#define DISPLAY_G 6
#define DISPLAY_DOT 7

class Display {
    uint8_t data[8];
	uint8_t pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDot, pinD1, pinD2, pinD3, pinD4;

	void setDigit(uint8_t value, uint8_t digit);

	void setNumber(int number);

	void display();

	void setImpl(uint8_t segment, uint8_t digit);

	void clear();
};