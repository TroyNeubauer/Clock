#include <Arduino.h>

int PIN = 2;
long start;


void setup() {
  // declare pin 9 to be an output:
  pinMode(PIN, OUTPUT);
  start = millis();
}

void loop() {
    double inital = (millis() - start) / 1000.0;
    double postSin = (sin(inital) + 1.0) / 2.0;
    int value = (int)(postSin * 255.0);
    analogWrite(PIN, value);
    delay(30);
}