#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#include "I2C.hpp"

// Implementación del constructor de I2C
I2C::I2C() {
  // Inicialización si es necesaria
}

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void I2C::setupDisplay() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Initialize with the I2C addr 0x3C (128x64)
  display.clearDisplay();
}


void I2C::turnOff() {
  display.clearDisplay();
  display.display(); // Update the display to show the cleared screen
}


void I2C::soilMidValue(int soilmoisturepercent){

  display.setCursor(10,0);  //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Humedad");

  display.setCursor(70,0);  //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.println(soilmoisturepercent);
  display.setCursor(80,0);
  display.setTextSize(1);
  display.println(" %");
 
}

void I2C::soilLowValue() {

  display.setCursor(10,0);  //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Humedad");

  display.setCursor(70,0);  //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("0 %");
 
}

void I2C::soilHighValue(){

  display.setCursor(10,0);  //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Humedad");

  display.setCursor(70,0);  //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("100 %");
  
}

void I2C::lightMidValue(int lightpercent){

  display.setCursor(10,0);  //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Luz");

  display.setCursor(70,10);  //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.println(lightpercent);
  display.setCursor(80,10);
  display.setTextSize(1);
  display.println(" %");
 
}

void I2C::lightLowValue() {

  display.setCursor(10,10);  //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Luz");

  display.setCursor(70,10);  //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("0 %");
 
}

void I2C::lightHighValue(){

  display.setCursor(10,10);  //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Luz");

  display.setCursor(70,10);  //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("100 %");
  
}
void I2C::updateDisplay() {
  display.display();
}

void I2C::cleanDisplay() {
  delay(250);
  display.clearDisplay();
}