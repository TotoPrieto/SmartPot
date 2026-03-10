#include "LED.hpp"

LED::LED() {}

void LED::begin() {
    pinMode(redPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    digitalWrite(redPin, LOW);    // Apagado inicialmente
    digitalWrite(yellowPin, LOW);
}

void LED::setRed(bool state) {
    digitalWrite(redPin, state ? HIGH : LOW);
}

void LED::setYellow(bool state) {
    digitalWrite(yellowPin, state ? HIGH : LOW);
}