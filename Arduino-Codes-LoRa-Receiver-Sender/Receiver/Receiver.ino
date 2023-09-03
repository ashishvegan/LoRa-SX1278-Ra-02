/*
 * Subscribe Tech Vegan for More Hardware & Software Tech Videos
 * Program by: Ashish Vegan https://www.ashishvegan.com
 * For Help - Contact WhatsApp +919890345539
 * technologyvegan@gmail.com
 * Get Harware & Software Academic Projects
 * Code Courtesy: Lora.h
 */
#include <LoRa.h>
#define SS 15
#define RST 16
#define DIO0 2
void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Receiver Host");
  LoRa.setPins(SS, RST, DIO0);
  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa Error");
    while (1);
  }
}
void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Receiving Data: ");
    while (LoRa.available()) {
      String data = LoRa.readString();
      Serial.println(data);
    }
  }
}
