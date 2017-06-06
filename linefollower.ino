#define lmotorf 2
#define lmotorb 3
#define rmotorf 4
#define rmotorb 5

 
void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT); 
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  Serial.begin(9600);
}

void loop()
{
  int lsensor=digitalRead(6);
  int rsensor=digitalRead(7);
  if((lsensor==LOW)&&(rsensor==LOW))
  {
    digitalWrite(lmotorf,LOW);
    digitalWrite(rmotorf,LOW);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,LOW);
  }
  else if((lsensor==HIGH)&&(rsensor==LOW))
  {
    digitalWrite(lmotorf,HIGH);
    digitalWrite(rmotorf,LOW);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,HIGH);   
  }
  else if((lsensor==LOW)&&(rsensor==HIGH))
  {
    digitalWrite(lmotorf,LOW);
    digitalWrite(rmotorf,HIGH);
    digitalWrite(lmotorb,HIGH);
    digitalWrite(rmotorb,LOW);   
  }
  else 
  {
    digitalWrite(lmotorf,HIGH);
    digitalWrite(rmotorf,HIGH);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,LOW);   
  }
  delay(50);
  }


