#include "SHT3x.hpp"

SHT3xSensor::SHT3xSensor() {}

bool SHT3xSensor::begin() {
    if (!sht31.begin(0x44)) {  // Dirección I2C por defecto para SHT3x
        Serial.println("No se pudo encontrar el sensor SHT3x");
        return false;
    }
    Serial.println("Sensor SHT3x inicializado correctamente");
    return true;
}

float SHT3xSensor::getTemperature() {
    return sht31.readTemperature();
}

float SHT3xSensor::getHumidity() {
    return sht31.readHumidity();
}

void SHT3xSensor::checkTemperatureHumidity(I2C &dsp) {
    float temp = getTemperature();
    float hum = getHumidity();
    dsp.temperatureValue(temp);
    dsp.humidityValue(hum);
}