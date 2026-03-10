#include <SPI.h>
#include "I2C.hpp"
#include "Button.hpp"
#include "LightSensor.hpp"
#include "SoilSensor.hpp"
#include "LED.hpp"
#include "Ultrasonic.hpp"
#include <Wire.h>

#define BUTTON_PIN    0
bool systemOn = true;
unsigned long lastDetectionTime = 0;


I2C dsp;
SoilSensor soilMoistureSensor(dsp);
LightSensor lightSensor(dsp);
LED led;
Ultrasonic ultrasonic(D7, D8);  // Trig D7, Echo D8

Button powerButton(BUTTON_PIN,true,[](){
  systemOn = !systemOn;
    if (!systemOn) {
        dsp.turnOff();
    }else {
        dsp.setupDisplay();
    }
  });


void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  Wire.begin(D2, D1); // SDA, SCL para ESP8266
  dsp.setupDisplay();
  lightSensor.begin();
  led.begin();
  ultrasonic.begin();

  // --- I2C Scanner ---
  Serial.println("\nEscaneando bus I2C...");
  byte count = 0;
  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("Dispositivo I2C encontrado en 0x");
      if (address < 16) Serial.print("0");
      Serial.print(address, HEX);
      Serial.println();
      count++;
      delay(5);
    }
  }
  if (count == 0) Serial.println("No se encontraron dispositivos I2C\n");
  else Serial.println("Escaneo I2C finalizado\n");

}
void loop(){
  // Detección ultrasónica
  if (ultrasonic.detectPresence()) {
    lastDetectionTime = millis();
    if (!systemOn) {
      systemOn = true;
      dsp.setupDisplay();
    }
  }

  // Apagar después de 1 minuto sin detección
  if (systemOn && millis() - lastDetectionTime > 60000) {
    systemOn = false;
    dsp.turnOff();
  }

  powerButton.update();
  if(systemOn) {
    soilMoistureSensor.checkSoilMoistureLevel();
    //lightSensor.checkLux();
    led.setRed(soilMoistureSensor.getSoilMoistureLevel() < 50);  // Rojo si humedad < 50%
    
    //led.setYellow(lightSensor.getLux() < 100);  // Amarillo si luz < 100 lux
    dsp.updateDisplay();
    dsp.cleanDisplay();
  }
}