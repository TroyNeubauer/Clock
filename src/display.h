#include <stdint.h>
#define ON 1
#define OFF 0

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define DOT 7

class Display {
    uint8_t data[8];

	void setDigit(uint8_t value, uint8_t digit);

	void setNumber(int number);

	void display();

	void setImpl(uint8_t segment, uint8_t digit);

	void clear();
};