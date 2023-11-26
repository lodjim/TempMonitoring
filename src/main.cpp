#include <Arduino.h>
#include <Arduino_MKRIoTCarrier.h>
#include "High_Temp.h"

HighTemp ht(A1, A0);

MKRIoTCarrier carrier;

void setup() {
  // Initialize the carrier and its display
  CARRIER_CASE = false;
  carrier.begin();
  ht.begin();
  carrier.display.fillScreen(ST77XX_BLACK);
  carrier.display.setTextSize(2);
  carrier.display.setTextColor(ST77XX_WHITE);
    
}

void loop() {
  carrier.display.fillScreen(ST77XX_BLACK);
  float temperature = carrier.Env.readTemperature();
  carrier.display.setCursor(20,100);
  carrier.display.println("Probe tempature:");
  carrier.display.setCursor(100,120);
  carrier.display.println(ht.getThmc()-76);
  carrier.display.setCursor(20,140);
  carrier.display.println("Local tempature:");
  carrier.display.setCursor(100,160);
  carrier.display.println(temperature);  
  delay(10000);
}
