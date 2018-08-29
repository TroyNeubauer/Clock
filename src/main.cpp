#include <Arduino.h>
#include "mymath.h"
#include "displaymanager.h"

#define D1A 42
#define A1 44
#define F1 46
#define D2A 48
#define D3A 50
#define B1 52
#define E1 22
#define D1 24
#define DEC1 26
#define C1 28
#define G1 30
#define D4A 32

#define D1B 43
#define A2 45
#define F2 47
#define D2B 49
#define D3B 51
#define B2 53
#define E2 23
#define D2 25
#define DEC2 27
#define C2 29
#define G2 31
#define D4B 33

void setOutput(int min,int max) {
	for(int i = min; i <= max; i++) {
		pinMode(i, OUTPUT);
	}
}

DisplayManager* display = nullptr;

void setup() {
	Serial.begin(9600);
	setOutput(42, 53);
	setOutput(22, 33);

	display = new DisplayManager(A1, B1, C1, D1, E1, F1, G1, DEC1, D1A, D2A, D3A, D4A);
}

void loop() {
	//display->setValue(millis() % 100000000);
	//display->display();
}