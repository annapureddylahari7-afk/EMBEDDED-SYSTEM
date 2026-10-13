#include <ESP8266WiFi.h>
#include <espnow.h>

#define SOIL_PIN A0

uint8_t receiverMAC[] = {0x68, 0xC6, 0x3A, 0xF6, 0x3F, 0x81};

typedef struct {
  int soilValue;
} SensorData;

SensorData data;

void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus)
{
  Serial.print("Send Status : ");

  if (sendStatus == 0)
    Serial.println("Success");
  else
    Serial.println("Failed");
}

void setup()
{
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != 0)
  {
    Serial.println("ESP-NOW Init Failed");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);

  esp_now_register_send_cb(OnDataSent);

  esp_now_add_peer(receiverMAC, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}

void loop()
{
  data.soilValue = analogRead(SOIL_PIN);

  Serial.print("Soil Value : ");
  Serial.println(data.soilValue);

  esp_now_send(receiverMAC, (uint8_t *)&data, sizeof(data));

  delay(1000);
}