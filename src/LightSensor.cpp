#include "LightSensor.hpp"

LightSensor::LightSensor(I2C& display) : dsp(display) {}

void LightSensor::begin() {
	bh1750.begin(BH1750::CONTINUOUS_HIGH_RES_MODE, 0x23);
}

void LightSensor::checkLux() {
    currentLux = bh1750.readLightLevel();
    dsp.lightValue(currentLux);

    if (currentLux >= 10000) {
        // Sol directo
        if (!isSun) {
            sunStartCandidate = millis();
            isSun = true;
            sunConfirmed = false;
        }
        if (!sunConfirmed && (millis() - sunStartCandidate >= SUN_CONFIRM_TIME)) {
            sunConfirmed = true;
        }
        if (sunConfirmed) {
            lastSunTime = millis();
        }
    } else if (currentLux >= 2000) {
        // Nublado momentáneo
        if (sunConfirmed) {
            lastSunTime = millis();        // no arranca el contador de sombra
            sunStartCandidate += 500UL;   // extiende el tiempo de confirmación
        }
        // si aún no estaba confirmado, no hace nada (pausa)
    } else {
        // Oscuridad real < 2000
        isSun = false;
    }
}

float LightSensor::getLux() {
	return currentLux;
}

bool LightSensor::noSunForWhile() {
    return !isSun && (millis() - lastSunTime >= 60000UL);
}