#include "Ultrasonic.hpp"

Ultrasonic::Ultrasonic(int trigPin, int echoPin) : trigPin(trigPin), echoPin(echoPin) {}

void Ultrasonic::begin() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float Ultrasonic::getDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    float distance = duration * 0.034 / 2;  // cm
    return distance;
}

bool Ultrasonic::detectPresence(float threshold) {
    float dist = getDistance();
    return (dist > 0 && dist < threshold);
}