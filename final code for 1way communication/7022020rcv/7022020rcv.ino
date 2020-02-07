#include <RH_ASK.h>
#include <SPI.h> 
RH_ASK driver;
int ledPin = 2;

void setup()
{
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);  
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    uint8_t buf[12];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) 
    {
      int i;
       digitalWrite(ledPin, HIGH);
      
      Serial.print("Message: ");
      Serial.println((char*)buf);  
            delay(100); 
      digitalWrite(ledPin, LOW);              
    }
}
