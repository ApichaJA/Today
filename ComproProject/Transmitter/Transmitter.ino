#include <RH_ASK.h>
#include <SPI.h>
#include <Wire.h>
#include <String.h>
#include "Adafruit_Si7021.h"
#include "Seeed_BME280.h"

RH_ASK driver(2000, 4, 2, 5);
Adafruit_Si7021 sensor = Adafruit_Si7021();
BME280 bme280;

void setup()
{
    Serial.begin(9600);
    if (!driver.init()){
         Serial.println("init failed");
    }
    if (!sensor.begin()||!bme280.init()){
    Serial.println("sensor error!");
    while (true);
  }
}

void loop()
{
  float pressure;
  float altitude;
  float humidity;
  float temperature;
  char* gassmoke;

  Serial.print("Pressure: ");
  Serial.print(pressure = bme280.getPressure());
  Serial.println("Pa");

  Serial.print("Altitude: ");
  Serial.print(altitude = bme280.calcAltitude(pressure));
  Serial.println("m");
  
  Serial.print("Humidity: ");
  Serial.println(humidity = sensor.readHumidity(), 2);
  Serial.print("Temperature: ");
  Serial.println(temperature = sensor.readTemperature(), 2);

  if (analogRead(A0) > 500) {
    Serial.println("Gas/Smoke: High");
    gassmoke = "Bad";
  }
  else if(analogRead(A0) > 200) {
    Serial.println("Gas/Smoke: Medium");
    gassmoke = "Medium";
  }
  else {
    Serial.println("Gas/Smoke: Good");
    gassmoke = "Good";
  }
    String final_data = String(pressure) + "|" + String(humidity) + "|" + String(temperature) + "|" + gassmoke + "|" + String(altitude);
    const char *dataTransmit = final_data.c_str();
    
    driver.send((uint8_t *)dataTransmit, strlen(dataTransmit));
    driver.waitPacketSent();
    delay(2000);
    Serial.println();
}
