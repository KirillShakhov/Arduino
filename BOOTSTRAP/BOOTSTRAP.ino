/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com
  Arduino IDE example: Examples > Arduino OTA > BasicOTA.ino
*********/

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>   //Содержится в пакете
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <ESP8266SSDP.h>        //Содержится в пакете


// Options
IPAddress apIP(192, 168, 4, 1);
// Web интерфейс для устройства
ESP8266WebServer HTTP(80);
// Определяем переменные wifi
const String _ssid     = "Room666"; // Для хранения SSID
const String _password = "17031703"; // Для хранения пароля сети
const String _ssidAP = "ESP8266";   // SSID AP точки доступа
const String _passwordAP = ""; // пароль точки доступа
const String SSDP_Name="SSDP-test"; // Имя SSDP

// Порт диода
const int ESP_BUILTIN_LED = 2;

void setup() {
  Serial.begin(115200);
  Serial.println("");
  /////////////WIFI/////////////
  Serial.println("Start WIFI");
  WIFIinit();
  /////////////OTA/////////////
  Serial.println("Start OTA");
  OTA_init();
  /////////////SSDP/////////////
  Serial.println("Start SSDP");
  SSDP_init();
  /////////////HTTP/////////////
  //Настраиваем и запускаем HTTP интерфейс
  Serial.println("Start WebServer");
  HTTP_init();
}

void loop() {
  ArduinoOTA.handle();
  HTTP.handleClient();
  delay(1);
}
