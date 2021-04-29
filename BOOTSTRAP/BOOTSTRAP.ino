#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>   //Содержится в пакете
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <ESP8266SSDP.h>        //Содержится в пакете
#include <FS.h>                 //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step4-fswebserver
#include <ArduinoJson.h>        //Установить из менеджера библиотек.
//                    ЗАПИСЬ И ЧТЕНИЕ ПАРАМЕТРОВ КОНФИГУРАЦИИ В ФАЙЛ. Видео с уроком http://esp8266-arduinoide.ru/step7-fileconfig/
#include <ESP8266HTTPUpdateServer.h>  //Содержится в пакете.

/////////////Options/////////////////

// Web интерфейс для устройства
ESP8266WebServer HTTP;

// Для файловой системы
File fsUploadFile;

// Определяем переменные wifi
String _ssid = "Room666"; // Для хранения SSID
String _password = "17031703"; // Для хранения пароля сети
String _ssidAP = "ESP8266"; // SSID AP точки доступа
String _passwordAP = ""; // пароль точки доступа
String SSDP_Name = "Update-Time"; // Имя SSDP
int timezone = 3;                      // часовой пояс GTM

String jsonConfig = "{}";
int port = 80;
/////////////Setup///////////////////

void setup() {
  ESP8266WebServer(port);
  Serial.begin(115200);
  Serial.println("");
  /////////////WIFI/////////////
  Serial.println("Start WIFI");
  WIFIinit();
  /////////////FS/////////////
  Serial.println("Start FileSystem");
  FS_init();
  /////////////FileConfig/////////////
  Serial.println("File Configuration");
  loadConfig();
  /////////////OTA/////////////
  Serial.println("Start OTA");
  OTA_init();
  ////////////Time/////////////
  Serial.println("Start 8-Time");
  // Получаем время из сети
  Time_init();
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
