//left motor has more SPEED than right motor
//black line following 
int x,y,z,p,q; //white--0, black--1
void setup() {
  //This sets frequecny as 7812.5 hz.
  //TCCR0B = TCCR0B & B11111000 | B00000010 ;
  
  pinMode(10,OUTPUT);//left motor1 input1
  pinMode(11,OUTPUT);//left motor1 input2
  pinMode(5,OUTPUT);//right motor2 input1
  pinMode(6,OUTPUT);//right motor2 input1
  pinMode(12,OUTPUT);//right enable
  pinMode(9,OUTPUT);//left enable
  pinMode(2,INPUT);//ir1
  pinMode(3,INPUT);//ir2
  pinMode(4,INPUT);//ir3--middle one
  pinMode(7,INPUT);//ir4--extreme left
  //pinMode(13,OUTPUT);//ir4 vcc
  pinMode(A4,INPUT);//ir5 -- extreme right
  //pinMode(A1,INPUT);//ir5 ground

  pinMode(13,OUTPUT);//blue 
  pinMode(8,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(9,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(8,LOW);//led grnd
 // digitalWrite(13,HIGH);//vcc for ir4
  //digitalWrite(A1,LOW);//grnd for ir5
  
  x=digitalRead(2);//left ir
  y=digitalRead(3);//right ir
  z=digitalRead(4);//middle ir
  p=digitalRead(7);//extreme left ir
  q=digitalRead(A4);//extreme right ir
  Serial.println(x);
  Serial.println(y);
  Serial.println(z);
  
 // go straight 
  if(x==0 && y==0 && z==1)
{
  analogWrite(10,220);
  analogWrite(11,0);
   
  analogWrite(5,250);
  analogWrite(6,0);
   //delay(20);
  }
else if(x==0 && y==0 && z==0)
{
//  digitalWrite(green,HIGH);
  delay(50);
  analogWrite(10,220);
  analogWrite(11,0);
   
  analogWrite(5,250);
  analogWrite(6,0);
  //delay(20);
  }
// stop
  if(x==0 && y==0 && z==0 && p==0 && q==0){
   analogWrite(10,0);
   analogWrite(11,0);
   
   analogWrite(5,0);
   analogWrite(6,0);
  
}
//right turn
if( y==1 || q==1){
   analogWrite(10,220);
   analogWrite(11,0);
   
   analogWrite(5,0);
   analogWrite(6,0);
  
}
// left turn
if(x==1 || p==1){
   analogWrite(10,0);
   analogWrite(11,0);
   
   analogWrite(5,250);
   analogWrite(6,0);
  }

// speed slow
if(x==1 && y==1 && z==1 && p==1 && q==1){

  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  
   analogWrite(10,180);
  analogWrite(11,0);
   
   analogWrite(5,150);
   analogWrite(6,0);
   
 }
 //digitalWrite(13,LOW);
}
