#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>   //Содержится в пакете
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <ArduinoJson.h>
#include "vk_api.h"
/////////////Options/////////////////
// Определяем переменные wifi
String _ssid = "Room666"; // Для хранения SSID
String _password = "17031703"; // Для хранения пароля сети
String _ssidAP = "ESP8266"; // SSID AP точки доступа
String _passwordAP = ""; // пароль точки доступа

String access_token = "b04d5cd927d757a13d67f89e10ffd8019f5de70959665e459e879513c1af1898ff838312805c4011f5f48";
vk_api_host api;
/////////////Setup///////////////////
void setup() {
  ESP8266WebServer(port);
  Serial.begin(115200);
  Serial.println("");
  /////////////WIFI/////////////
  Serial.println("Start WIFI");
  WIFIinit();
  /////////////OTA/////////////
  Serial.println("Start OTA");
  OTA_init();

  api.server("");
  api.url("");   
  api.token(access_token);
  api.new_messages();
  Serial.println("messages new"); 
  Serial.println(api.messages_new);
}

void loop() {
  ArduinoOTA.handle();
  delay(1);
}
