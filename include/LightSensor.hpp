#pragma once
#include <BH1750.h>
#include <Wire.h>
#include "I2C.hpp"

class LightSensor {
  public:
	  LightSensor(I2C& display);
  	void begin();
  	void checkLux();
  	float getLux();

  private:
    BH1750 bh1750;
    I2C& dsp;
    float currentLux;
};

