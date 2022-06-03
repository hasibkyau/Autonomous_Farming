#include "jarvisSetup.h"
//#include "jarvisInterface.h"
#include "jarvisWeatherStation.h"
#include "jarvisClock.h"

void setup() {
  jarvisSetup();    
}

void loop() {
  jarvisWeatherStation();
  delay(2000);
  jarvisClock();
  delay(2000);
}
