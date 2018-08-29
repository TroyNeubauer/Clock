#include "displaymanager.h"

template<int T> DisplayManager<T>::DisplayManager(uint8_t pins,...) {
	va_list valist;
	double sum = 0.0;
	int i;

	va_start(valist, pins);

	for (i = 0; i < pins / 12; i++) {
		Display display (va_arg(valist, uint8_t), va_arg(valist, uint8_t), va_arg(valist, uint8_t), va_arg(valist, uint8_t), 
						 va_arg(valist, uint8_t), va_arg(valist, uint8_t), va_arg(valist, uint8_t), va_arg(valist, uint8_t), 
						 va_arg(valist, uint8_t), va_arg(valist, uint8_t), va_arg(valist, uint8_t), va_arg(valist, uint8_t));
		displays[i] = display;
	}
	
	va_end(valist);
}



template<int T> void DisplayManager<T>::setTime(uint32_t millis) {

}
template<int T> void DisplayManager<T>::setFloat(float value) {

}

template<int T> void DisplayManager<T>::setValue(uint32_t value) {
	for(int i = 0; i < T && value > 0; i++) {
		Display display = displays[i];
		display.setNumber(value);
		value /= 10000;
	}
}

template<int T> void  DisplayManager<T>::display() {
	for(int i = 0; i < T; i++) {
		displays[i].display();
	}
}