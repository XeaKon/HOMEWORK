
#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <IRremote.h>

const int d4=5;
const int d5=4;
const int d6=3;
const int d7=2;
const int rs=12;
const int enable=11;

const int trig=8;
const int echo=9;
int duration=0;
int distance=0;

LiquidCrystal lcd(rs,enable,d4,d5,d6,d7);
const int receiver=10;
IRrecv irrecv(receiver);
decode_results results;
int bbyte=0;
int optiune=0;



void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
irrecv.enableIRIn();
irrecv.blink13(true);
}

void loop() {
  // put your main code here, to run repeatedly:
{
lcd.setCursor(3,0); lcd.print("Start game");
lcd.setCursor(1,1); lcd.print("Best ");
lcd.setCursor(8,1); lcd.print("Settings");
//loc pt indicator
delay(200);
}


}
