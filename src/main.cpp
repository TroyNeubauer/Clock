#include <Arduino.h>
#include "mymath.h"

int PIN = 2;
long start;


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

void setOutput(int min, int max) {
	for(int i = min; i <= max; i++) {
		pinMode(i, OUTPUT);
	}
}

void setup() {
	// declare pin 9 to be an output:
	pinMode(PIN, OUTPUT);
	start = millis();
	setOutput(42, 53);
	setOutput(22, 33);
}

void loop() {

	digitalWrite(D1A, HIGH);
	digitalWrite(A1, HIGH);


    /*double inital = (millis() - start) / 10000.0;
    double postSin = map(sin(inital), -1.0, 1.0, 0.001, 1.0);
    int value = (int)(postSin * 255.0);
    analogWrite(PIN, value);
    delay(30);*/
}