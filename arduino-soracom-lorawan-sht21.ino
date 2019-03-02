#define SENSOR_PIN 0 //analog pin
#define PROBE_INTERVAL 5000 //msec

#include <lorawan_client.h>
LoRaWANClient lorawan;

void setup() {
  Serial.begin(9600);
  if(! lorawan.connect(true))
  {
    Serial.println(" failed to connect. Halt...");
    for(;;){};
  }
  Serial.println("\nConnected.\n");
}

void loop() {
  float t;
  t = 3.14;
  char buf[7];
  dtostrf(t, -1, 2, buf); /* Arduino UNO R3 cannot cast float to char */
  Serial.println(buf);
  char json[13];
  sprintf(json, "{\"t\":%s}", buf);
  Serial.println(json);
  lorawan.sendData(json);
  delay(PROBE_INTERVAL);
}
