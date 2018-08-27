#include <Arduino.h>

int PIN = 2;           // the PWM pin the LED is attached to
long start;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(PIN, OUTPUT);
  start = millis();
}

// the loop routine runs over and over again forever:
void loop() {
    double inital = (millis() - start) / 1000.0;
    double postSin = (sin(inital) + 1.0) / 2.0;
    int value = (int)(postSin * 255.0);
    analogWrite(PIN, value);
    delay(30);
}