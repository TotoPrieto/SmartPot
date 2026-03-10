#include "LightSensor.hpp"

LightSensor::LightSensor(I2C& display) : dsp(display) {}

void LightSensor::begin() {
	bh1750.begin(BH1750::CONTINUOUS_HIGH_RES_MODE);
}

void LightSensor::checkLux() {
	currentLux = bh1750.readLightLevel();
  int porcentaje = map(currentLux, 0, 50000, 0, 100);
	if (porcentaje < 100) {
		dsp.lightLowValue();
	} else if (porcentaje > 1000) {
		dsp.lightHighValue();
	} else {
		dsp.lightMidValue(currentLux);
	}
}

float LightSensor::getLux() {
	return currentLux;
}

