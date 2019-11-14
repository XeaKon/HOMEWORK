
const int knockSensor=A0;
int knockVal=0;
int th=400;
int past=0;

int ok=0;
const int buzPin=10;
const int buttonPin=2;
int reading=0;
int buttonState=0;
int lastButtonState=0;

unsigned int lastDebounceTime=0;
unsigned int debounceDelay=50;


void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(knockSensor,INPUT);
  pinMode(buzPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
knockVal=analogRead(knockSensor);
Serial.print(knockVal);


//if(photonVal>=highTh)
//{
//  analogWrite(ledPin,255);
//}


if(ok==0&&knockVal<800)
{
  past=millis();
  ok=1;

}

int reading=digitalRead(buttonPin);
Serial.print("  ");  Serial.print(reading);  Serial.print("\n");

if(ok==1&&millis()-past>=5000)
{
tone(buzPin,1109);





if(reading!=lastButtonState)
{
  lastDebounceTime=millis();
  }

  if(millis()-lastDebounceTime>debounceDelay)
  {
    if(reading!=buttonState)
   {
    buttonState=reading;
    if(buttonState==HIGH)
    {
      ok=!ok;
      
    }
   }
   
  }
 if(ok==0)
 {
  noTone(buzPin);
  
 }
  lastButtonState=reading;

  
}



}
