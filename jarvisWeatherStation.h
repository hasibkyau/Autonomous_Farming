//this is for displaying weather status

#ifndef WEATHER_A
#define WEATHER_A

//#include <Arduino.h> //needed for Serial.println
//#include "jarvisSetup.h"

void jarvisWeatherStation()
{
  Serial.print("Temp = ");
  Serial.print(bme.readTemperature());
  Serial.println("*C");
  Serial.print("Press = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  display.clearDisplay();
  display.setCursor(10,5);
  display.println("*Weather Station*");
  display.println("------------------");
  
  //temperature
  display.print("Temp     : ");
  display.print(bme.readTemperature(),0);
  display.println("*C");

  //pressure
  display.print("Press    : ");
  display.print(bme.readPressure() / 100.0F,0);
  display.println(" hPa");

  //Altitude
  display.print("Altitude : ");
  display.print(bme.readAltitude(SEALEVELPRESSURE_HPA),0);
  display.println(" m");

  //Humidity
  display.print("Humidity : ");
  display.print(bme.readHumidity(),0);
  display.println(" %");
  
  display.display();
}

#endif
