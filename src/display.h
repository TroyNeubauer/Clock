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
private:
    uint8_t data[8];
	uint8_t pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDot, pinD1, pinD2, pinD3, pinD4;
	int lastNumber;
public:
	Display(uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD, uint8_t pinE, uint8_t pinF, uint8_t pinG, 
		uint8_t pinDot, uint8_t pinD1, uint8_t pinD2, uint8_t pinD3, uint8_t pinD4);

	void setDigit(uint8_t value, uint8_t digit);

	void setNumber(int number);

	void display();

	void setImpl(uint8_t segment, uint8_t digit);

	void clear();
};