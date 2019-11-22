const int sw=A2;
const int axis=A1;
const int ayis=A0;

int xVal=0;
int yVal=0;
int swVal=0;
int xchanged=0;
int ychanged=0;



const int E=2;
const int dot=6;
const int D=9;
const int B=8;
const int A=3;
const int F=4;
const int G=5;
const int C=7;

const int ssize=8;
int segments[ssize]={A,B,C,D,E,F,G,dot};
int i=0;
const int ten=11;
byte M[ten][ssize-1]={
 //a  b  c  d  e  f  g
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}, //9
  {0, 0, 0, 0, 0, 0, 0} // out
};

const int D1=13;
const int D2=10;
const int D3=12;
const int D4=11;
const int noofdisplays=4;
int displays[noofdisplays]={D1,D2,D3,D4};
int thedisplay=0;

int swState=0;
int lastswState=0;
unsigned int lastDebounceTime=0;
unsigned int debounceDelay=50;
int ok=0;
int dxchanged=0;
int count[noofdisplays]={0,1,2,3};


void setup() {
  // put your setup code here, to run once:
pinMode(sw,INPUT_PULLUP);
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(dot,OUTPUT);
  for(int i=0;i<noofdisplays;i++)
  {
    pinMode(displays[i],OUTPUT);
  }
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
xVal=analogRead(axis);
yVal=analogRead(ayis);
swVal=digitalRead(sw);

int reading=swVal;


  if(reading!=lastswState)
{
  lastDebounceTime=millis();
  }

  if(millis()-lastDebounceTime>debounceDelay)
  {
    if(reading!=swState)
   {
    swState=reading;
    if(swState==HIGH) //era high
    {
      ok=(ok+1)%2;
    }
   }
   
  }
  //digitalWrite(ledPin,ledState);
if(ok==0)
{
if(xVal<300&&xchanged==0)
{
 count[thedisplay]--;
 if(count[thedisplay]<0)
  {count[thedisplay]=9;}
 xchanged=1;
}
else
{
  if(xVal>700&&xchanged==0)
  {
    count[thedisplay]++;
     xchanged=1;
  }
  else
  {if(xVal>=300&&xVal<=700)
   xchanged=0; 
  }
}
}
else
{
//ok==1, adica mutam diplayul
  
if(xVal<300&&dxchanged==0)
{
 thedisplay--;
 if(thedisplay<0)
 thedisplay=3;
 dxchanged=1;
}
else
{
  if(xVal>700&&dxchanged==0)
  {
    thedisplay++;
    if(thedisplay>3)
      thedisplay=0;
     dxchanged=1;
  }
  else
  {if(xVal>=300&&xVal<=700)
   dxchanged=0; 
  }
}


  
}

  
  lastswState=reading;



  Serial.print("Switch:  ");
  //Serial.print(swVal);
  Serial.print(count[thedisplay]);
  Serial.print("  |  ");
  Serial.print("X-axis: ");
  //Serial.print(xVal);
  Serial.print(ok);
  Serial.print("  |  ");
  Serial.print("Y-axis: ");
  //Serial.print(yVal);
  Serial.print(thedisplay);
  Serial.println("  |  ");
  
  
  if(ok==0)
  {
    
    digitalWrite(displays[0],HIGH);//high este pt stins
    digitalWrite(displays[1],HIGH);
    digitalWrite(displays[2],HIGH);
    digitalWrite(displays[3],HIGH);
    display2(thedisplay,count[thedisplay]%10,HIGH);
    
    
    delay(200);
    }
  else
  {

//    digitalWrite(displays[0],LOW);//high este pt stins, si era high
//    digitalWrite(displays[1],LOW);
//    digitalWrite(displays[2],LOW);
//    digitalWrite(displays[3],LOW);
    
    
    display3((thedisplay+1)%4,count[(thedisplay+2)%4]%10,LOW);
    display3((thedisplay+2)%4,count[(thedisplay+2)%4]%10,LOW);
    display3((thedisplay+3)%4,count[(thedisplay+3)%4]%10,LOW);
    display3(thedisplay,count[(thedisplay)%4]%10,LOW);
    
  }
  

}

void display2 (int displayVal, int digit,int dotVal)
{
  digitalWrite(displays[(displayVal)%4],LOW);
  digitalWrite(displays[(displayVal+1)%4],HIGH);//high este pt stins
  digitalWrite(displays[(displayVal+2)%4],HIGH);
  digitalWrite(displays[(displayVal+3)%4],HIGH);
  
 for(int l=0;l<ssize-1;l++)
 {
 digitalWrite(segments[l],M[digit][l]);
 }

 digitalWrite(segments[ssize-1],dotVal);
 
}


void display3 (int displayVal, int digit,int dotVal)
{
  digitalWrite(displays[(displayVal)%4],LOW);

  digitalWrite(displays[(displayVal+1)%4],HIGH);//high este pt stins
  digitalWrite(displays[(displayVal+2)%4],HIGH);
  digitalWrite(displays[(displayVal+3)%4],HIGH);
  

  
 for(int l=0;l<ssize-1;l++)
 {
 digitalWrite(segments[l],M[digit][l]);
 }


 digitalWrite(segments[ssize-1],dotVal); //dot avea, ! in fata
 
}
