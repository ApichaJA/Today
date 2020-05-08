#include <RH_ASK.h>
#include <SPI.h>
#include <String.h>

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define WIFI_SSID "Japan@Home2.4GHz"
#define WIFI_PASSWORD "Hbd19970523"
#define FIREBASE_HOST "japanapi-b8124.firebaseio.com"
#define FIREBASE_AUTH "ZrO6xk1qo5yM9I6r8h8dyc97wWVGSKtdL75ctD9w"

RH_ASK driver(2000, 4, 2, 5);

void setup()
{
    Serial.begin(9600);
    if (!driver.init()){
         Serial.println("init failed");}
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("connecting");
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);}
      Serial.println();
      Serial.print("connected: ");
      Serial.println(WiFi.localIP());
      Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
      Firebase.setInt("temperature", 0);
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) {
    String receiveData;

       for (int rec = 0; rec < buflen; rec++){
          receiveData += (char)buf[rec];
      }
      float pressure = receiveData.substring(0,8).toFloat();
      float humidity = receiveData.substring(10,14).toFloat();
      float temperature = receiveData.substring(16,20).toFloat();
      String smoke_gas = receiveData.substring(22,26);
     Serial.print("Pressure: ");
     Serial.println(pressure);
     Firebase.setFloat("Pressure/", pressure);
     Serial.print("Humidity: ");
     Serial.println(humidity);
     Firebase.setFloat("Humidity/", humidity);
     Serial.print("Temperature: ");
     Serial.println(temperature);
     Firebase.setFloat("Temperature/", temperature);
     Serial.print("Smoke/Gas Level: ");
     Serial.println(smoke_gas);
     Firebase.setString("Smoke_Gas/", smoke_gas);
    }
}
