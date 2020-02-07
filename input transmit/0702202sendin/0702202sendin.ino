#include <RH_ASK.h>
#include <SPI.h>

RH_ASK rf_driver;
int ledPin = 2;
//char rx_byte = 0;

void setup()
{

  pinMode(ledPin, OUTPUT);
  rf_driver.init();
  Serial.begin(9600);
}

void loop()
{

  if (Serial.available())
  {
    char data = Serial.read();
    Serial.print(data);
    digitalWrite(ledPin, HIGH);

    rf_driver.send((uint8_t *)data, strlen(data));
    rf_driver.waitPacketSent();
    delay(20);

    digitalWrite(ledPin, LOW);

  }


}
