#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "YourDeviceName"
#define BLYNK_AUTH_TOKEN "YourAuthToken"
char ssid[] = "YourWiFiSSID";      
char pass[] = "YourWiFiPassword";  

#define LIGHT_PIN D1   
#define FAN_PIN D2    

void setup() {
 
  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  digitalWrite(LIGHT_PIN, LOW);
  digitalWrite(FAN_PIN, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}
BLYNK_WRITE(V1) {
  int lightState = param.asInt();
  digitalWrite(LIGHT_PIN, lightState);
}

BLYNK_WRITE(V2) {
  int fanState = param.asInt(); 
  digitalWrite(FAN_PIN, fanState);
}
void loop() {
  Blynk.run(); /
}
