#include <RH_ASK.h>   // Include the RH_ASK library
#include <SPI.h>      // Not actually used but needed to compile the RH_ASK library
 
RH_ASK radio(1000, 11, 12);

char signalString[10];
 
void setup()
{
    Serial.begin(9600);   // Use this for debugging
    Serial.setTimeout(50);
 
    // Speed of 2000 bits per second
    // Use pin 11 for reception
    // Use pin 12 for transmission
    
    if (!radio.init())
    {
         Serial.println("Radio module failed to initialize");
    }
}
 
void loop()
{
    // Reading from Serial
    while (!Serial.available());
    itoa(Serial.readString().toInt(), signalString, 10);
 
    // Send our signal
    radio.send((uint8_t*)signalString, strlen(signalString));
 
    // Wait until the data has been sent
    radio.waitPacketSent();
 
 
    // Also inform the serial port that we are done!
    Serial.println(signalString);
}
