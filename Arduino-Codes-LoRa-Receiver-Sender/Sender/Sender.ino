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
String data = "Subscribe Tech Vegan";
void setup()
{
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Sender Host");
  LoRa.setPins(SS, RST, DIO0);
  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa Error");
    delay(100);
    while (1);
  }
}
void loop()
{
  Serial.print("Sending Data: ");
  Serial.println(data);
  LoRa.beginPacket();
  LoRa.print(data);
  LoRa.endPacket();
  delay(3000);
}
