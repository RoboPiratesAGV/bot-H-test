#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0, address);   //Setting the address at which we will receive the data
radio.setPALevel(RF24_PA_MIN);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
radio.startListening();              //This sets the module as receiver
}

void loop() {
  // put your main code here, to run repeatedly:
if (radio.available())              //Looking for the data.
{
    //Saving the incoming data
char text;
radio.read(&text, sizeof(text));    //Reading the data
Serial.println(text);

}
}
