#pragma once
#include <Arduino.h>

class I2C {
  public:
    I2C();
    void setupDisplay();
    void turnOff();
    void updateDisplay();
    void cleanDisplay();

    void soilMidValue(int soilmoisturepercent);
    void soilLowValue();
    void soilHighValue();

    void lightValue(float lux);

    void showWaterMessage();

    void displayOn();
    void displayOff();

};