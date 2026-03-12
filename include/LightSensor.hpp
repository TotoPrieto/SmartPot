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
    bool noSunForWhile();

  private:
    BH1750 bh1750;
    I2C& dsp;
    float currentLux;
    unsigned long lastSunTime = 0;
    bool isSun = false;
    const unsigned long SUN_CONFIRM_TIME = 30000UL;  // 30 segundos de sol continuo para confirmar
    unsigned long sunStartCandidate = 0;  // cuando empezó a detectar sol
    bool sunConfirmed = false;            // si ya se confirmó la salida al sol
  };

