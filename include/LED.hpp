#ifndef LED_HPP
#define LED_HPP

#include <Arduino.h>

class LED {
public:
    LED();
    void begin();
    void setRed(bool state);
    void setYellow(bool state);

private:
    const int redPin = D5;    // GPIO14
    const int yellowPin = D6; // GPIO12
};

#endif