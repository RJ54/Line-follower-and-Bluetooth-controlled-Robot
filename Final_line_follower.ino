#define lmotorf 2                                //Step-1:  motor driver m2-a into arduino pin2
#define lmotorb 3                                //Step-2:  motor driver m2-b into arduino pin3
#define rmotorf 4                                //Step-3:  motor driver m1-a into arduino pin4
#define rmotorb 5                                //Step-4:  motor driver m1-b into arduino pin5
                                                 //Step-5:  Connect battery to motor driver(+12,GND,+5V) and to arduino (in pin 'Vin' +5V)  ***  Use IC-7805 to supply +5V  ***
                                                 //Step-6:  connect bluetooth module RX pin to arduino TX pin
                                                 //Step-7:  connect bluetooth module TX pin to arduino RX pin and supply +3V vcc and GND to respective pins in bluetooth module
                                                 //Step-8:  Power the left and right IR sensor (+5V) and connect O/Ps of left and Right IR to arduino pin 6 and 7 respectively
                                                 //Step-9:  Connect the battery to IC-7805
                                                 //Step-10: Turn on the bluetooth and paired up the devices ..........Download the software 'Blue control' or 'Arduino control'

                                                // *****************************************************************************************************************
                                                //**** CAUTION: Don't plug-in the battery when arduino connected with the laptop.   ********************************
                                                // **** CAUTION: UNPLUG the VCC of bluetooth module while uploading the program.    ********************************
                                                //******************************************************************************************************************
 void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT); 
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(6,INPUT);                             //Input for left IR sensor
  pinMode(7,INPUT);                             //Input for right IR sensor
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available()==0);                  //waiting for bluetooth signal
  char c=Serial.read();                          //reading the bluetooth signal
  while(c=='W'||c=='A')                          //Checking conditions for while loop
  {
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    loop1();
  }

  while(c=='B'||c=='V')                          //same here
  {
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    loop2();
  }
}
void loop1()                                                      //function loop for IR mode
{
  
  int lsensor=digitalRead(6);
  int rsensor=digitalRead(7);
  if((lsensor==LOW)&&(rsensor==LOW))                              //Stop
  {
    digitalWrite(lmotorf,LOW);
    digitalWrite(rmotorf,LOW);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,LOW);
  }
  else if((lsensor==HIGH)&&(rsensor==LOW))                        //Rightward
  {
    digitalWrite(lmotorf,HIGH);
    digitalWrite(rmotorf,LOW);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,HIGH);   
  }
  else if((lsensor==LOW)&&(rsensor==HIGH))                        //Leftward
  {
    digitalWrite(lmotorf,LOW);
    digitalWrite(rmotorf,HIGH);
    digitalWrite(lmotorb,HIGH);
    digitalWrite(rmotorb,LOW);   
  }
  else                                                            //Forward
  {
    digitalWrite(lmotorf,HIGH);
    digitalWrite(rmotorf,HIGH);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,LOW);   
  }
  delay(50);//Optional
  }

  void loop2()                                                   //function loop for Bluetooth mode
  {
    char val=Serial.read();
    if(val=='F'||val=='U')                                       //forward
    {
    digitalWrite(lmotorf,HIGH);
    digitalWrite(rmotorf,HIGH);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,LOW);
    }

    if(val=='B'||val=='D')                                        //Backward
    {
    digitalWrite(lmotorf,LOW);
    digitalWrite(rmotorf,LOW);
    digitalWrite(lmotorb,HIGH);
    digitalWrite(rmotorb,HIGH);
    }

    if(val=='L')                                                  //Leftward
    {
    digitalWrite(lmotorf,LOW);
    digitalWrite(rmotorf,HIGH);
    digitalWrite(lmotorb,HIGH);
    digitalWrite(rmotorb,LOW);    
    }

    if(val=='R')                                                  //Rightward
    {
    digitalWrite(lmotorf,HIGH);
    digitalWrite(rmotorf,LOW);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,HIGH);
    }

    if(val=='C'||val=='S')                                        //stop
    {
    digitalWrite(lmotorf,LOW);
    digitalWrite(rmotorf,LOW);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,LOW);
    }
  }


  //******************************
  //******************************
  //******  DONE! :)  ************
  //******************************
  //******************************


