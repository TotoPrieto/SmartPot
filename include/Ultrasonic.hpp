#ifndef ULTRASONIC_HPP
#define ULTRASONIC_HPP

#include <Arduino.h>

class Ultrasonic {
public:
    Ultrasonic(int trigPin, int echoPin);
    void begin();
    float getDistance();
    bool detectPresence(float threshold = 50.0);  // Detecta si distancia < threshold cm

private:
    int trigPin;
    int echoPin;
};

#endif