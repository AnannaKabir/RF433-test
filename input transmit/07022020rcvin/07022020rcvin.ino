#include <RH_ASK.h>
#include <SPI.h> 
RH_ASK driver;
//char data= "";
int ledPin = 2;
  //char buf="";
    //uint8_t buflen = sizeof(buf);
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
      Serial.println("hi");
      }
//   {
//      //memcpy(&data,&buf,buflen);
//     digitalWrite(ledPin, HIGH);
//    
//    Serial.print("message: ");
//    Serial.println((uint8_t *)buf);  
//           delay(20); 
//     digitalWrite(ledPin, LOW);              
//   }
}
