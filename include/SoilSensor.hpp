#pragma once
#include "I2C.hpp"
#include <SPI.h>

class SoilSensor {
  public:
    SoilSensor(I2C& display);
    void begin();
    void checkSoilMoistureLevel();
    int getSoilMoistureLevel();

  private:
    I2C& dsp;
    int soilMoisturePercent;
};
