#include <stdint.h>
#define ON 0
#define OFF 1
#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
#define F 6
#define G 7
#define DOT 8

class Display {
    uint8_t data[8];



	void setDigit(uint8_t value, uint8_t digit);

	void setNumber(int number);

	void display();

	void setImpl(uint8_t segment, uint8_t digit);
};