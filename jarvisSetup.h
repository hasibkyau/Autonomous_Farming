/*
 * this file setups every external components used with arduino
 */

#ifndef SETUP_A
#define SETUP_A

#include <Arduino.h> //needed for Serial.println

//including wifi and local time grabber library
#include <ezTime.h>
#include <WiFi.h>

//INCLUDING OLED DISPLAY LIBRARY
#include <Wire.h>                 // I2C
#include <Adafruit_GFX.h>         // OLED
#include <Adafruit_SSD1306.h>     // Graphic

//INCLUDING BME SENSOR LIBRARY
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

//DEFINING FOR OLED DISPLAY
#define OLED_RESET 4 // not used nicht genutzt bei diesem Display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//DEFININF FOR BME SENSOR
#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10
#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME280 bme; // I2C
unsigned long delayTime;

Timezone myTZ;

void jarvisSetup()
{
  Serial.begin(115200);

  /**setup display**/
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Wire.begin();
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(INVERSE);

  /**setup bme sensor**/
  unsigned status;
  // default settings
  status = bme.begin(0x76);
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
    while (1) delay(10);
  }
  delayTime = 1000;
  
  /**setup wifi and local time zone**/
  WiFi.begin("IceCube", "admin123"); //provide your wifi SSID and password
  while (!Serial) {};
  waitForSync();
  // Provide official timezone names
  // https://en.wikipedia.org/wiki/List_of_tz_database_time_zones
  myTZ.setLocation(F("Asia/Dhaka"));
  Serial.print(F("Dhaka:     "));
  Serial.println(myTZ.dateTime());
  // Wait a little bit to not trigger DDoS protection on server
  delay(5000);  
}

#endif
