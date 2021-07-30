#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";     //Byte of array representing the address. This is the address where we will send the data. This should be same on the receiving side.
char signalString[10];
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
radio.begin();                  //Starting the Wireless communication
radio.openWritingPipe(address); //Setting the address where we will send the data
radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
radio.stopListening();          //This sets the module as transmitter
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available())
{
   
   //itoa(Serial.read().toInt(), signalString, 10);
   
  //radio.write((char)Serial.read(),1); //Sending the message to receiver
   Serial.println((char)Serial.read());
}

}