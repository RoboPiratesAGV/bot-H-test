// bot 1
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";
int mr1=4;
int mr2=5;
int ml1=2;
int ml2=3;
int c1=6;
int c2=7;
void setup() {
  pinMode(mr1,OUTPUT);
   pinMode(mr2,OUTPUT);
  pinMode(ml1,OUTPUT);
  pinMode(ml2,OUTPUT);
  pinMode(c1,OUTPUT);
  pinMode(c2, OUTPUT);
  // put your setup code here, to run once:
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0, address);   //Setting the address at which we will receive the data
radio.setPALevel(RF24_PA_MIN);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
radio.startListening();              //This sets th the module as receiver
}

void loop() {
  // put your main code here, to run repeatedly:
  
  while(radio.available())              //Looking for the data.
{
    //Saving the incoming data
char text;
radio.read(&text, sizeof(text));    //Reading the data
Serial.println(text);
if(text=='0')   //0= halt
{

          Serial.println("stop");
           halt();
}
else if(text=='1')  //1= forward
{
            Serial.println("forward");
          forward();
}
else if(text=='2') //2=reverse
 {
            Serial.println("reverse");
             reverse();
 }
else if(text=='3')//3=forward-left-turn
{
  fleft();
  delay(2000);
  halt(); 
}
else if(text=='4')//4=forward-right-turn
{
  fright();
  delay(2000);
  halt();
}
else if(text=='5')//5=reverse-left-turn
{
  rleft();
  delay(2000);
  halt();
}
else if(text=='6')//6=reverse-right-turn
{
  rright();
  delay(2000);
  halt();
}
else if(text=='7')//7= conveyor forward
{
  cforward();
}
else if(text=='8')//8=conveyor reverse
{
  creverse();
}
}
}
void halt()
{
  digitalWrite(mr1, LOW);
  digitalWrite(mr2, LOW);
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,LOW);
}
void forward()
{
  digitalWrite(mr1,HIGH);
  digitalWrite(mr2,LOW);
  digitalWrite(ml1,HIGH);
   digitalWrite(ml2,LOW);
}
void reverse()
{
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,HIGH);
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,HIGH);
}
void fright()
{
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,HIGH);
  digitalWrite(ml1,HIGH);
  digitalWrite(ml2,LOW);
}
void fleft()
{
  digitalWrite(mr1,HIGH);
  digitalWrite(mr2,LOW);
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,HIGH);
}
void rright()
{
  digitalWrite(mr1,HIGH);
  digitalWrite(mr2,LOW);
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,HIGH);
}
void rleft()
{
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,HIGH);
  digitalWrite(ml1,HIGH);
  digitalWrite(ml2,LOW);
}
void cforward()
{
  digitalWrite(c1,HIGH);
  digitalWrite(c2,LOW);
  delay(2000);
  digitalWrite(c1,LOW);
  digitalWrite(c2,LOW);
}
void creverse()
{
  digitalWrite(c1,LOW);
  digitalWrite(c2,HIGH);
  delay(2000);
  digitalWrite(c1,LOW);
  digitalWrite(c2,LOW);
}
