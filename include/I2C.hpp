#pragma once
#include <Arduino.h>

class I2C {
  public:
    I2C();
    void setupDisplay();
    void midValue(int soilmoisturepercent);
    void lowValue();
    void highValue();
    void turnOff();


};