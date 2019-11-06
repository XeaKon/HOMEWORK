int redLed=9;
int greenLed=10;
int blueLed=11;
int redPot=A0;
int greenPot=A1;
int bluePot=A2;
int redVal=0;
int greenVal=0;
int blueVal=0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(redLed,OUTPUT);
pinMode(greenLed,OUTPUT);
pinMode(blueLed,OUTPUT);
pinMode(redPot,INPUT);
pinMode(greenPot,INPUT);
pinMode(bluePot,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
redVal=analogRead(redPot);
greenVal=analogRead(greenPot);
blueVal=analogRead(bluePot);

colour(redVal/4,greenVal/4,blueVal/4);
Serial.print(redVal/4); Serial.print("  "); Serial.print(greenVal/4); Serial.print("  "); Serial.print(blueVal/4); Serial.print("\n");


}

void colour(int red, int green, int blue)
{
 analogWrite(redLed,red);
 analogWrite(greenLed,green);
 analogWrite(blueLed,blue);
 }
