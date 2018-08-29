#include "display.h"
#include "stdint.h"
#include <stdarg.h>

template<int T> class DisplayManager {
private:
	Display displays[T];
	uint32_t lastValue;
public:
	DisplayManager(uint8_t pins,...);

	void setTime(uint32_t millis);
	void setFloat(float value);
	void setValue(uint32_t value);
	void display();
};