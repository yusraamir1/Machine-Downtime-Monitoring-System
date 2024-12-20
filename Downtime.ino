#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = ""; // Network SSID 
const char* password = ""; // Network password
const char* host = "https://script.google.com/macros/s/AKfycbzQq9QihF3L3X6tTGbjiGeJd2Qq4BwXrWrZB_6k3g3ChcOcwlagwflKNR5I4bm9Fr4/exec";
const char* device_id = "Esp32-1";

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  float voltage = (float)analogRead(34);
  Serial.println(voltage);
  delay(2000); 

  if (voltage == 4095) {
    sendData(voltage);
  }
  delay(5000);  
}

void sendData(float voltage) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    Serial.print("Connecting to ");
    Serial.println(host);

    String string_volt = "ON";
    String url = String(host) + "?voltage=" + string_volt + "&device_id=" + device_id;

    http.begin(url); 
    int httpResponseCode = http.GET(); 

  }
}