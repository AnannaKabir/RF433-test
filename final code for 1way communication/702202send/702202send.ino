#include <RH_ASK.h>
#include <SPI.h> 
 
RH_ASK rf_driver;
int ledPin = 2;

void setup()
{
    pinMode(ledPin, OUTPUT);
    rf_driver.init();
        Serial.begin(9600);   
}
 
void loop()
{
    const char *msg = "hgr590";
    
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();

    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(500);
}
