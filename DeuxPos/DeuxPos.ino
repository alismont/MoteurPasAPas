

#include <AccelStepper.h>
long pos;
int st=0;

int motorPin1 = 8;    // Blue   - 28BYJ48 pin 1
int motorPin2 = 9;    // Pink   - 28BYJ48 pin 2
int motorPin3 = 10;    // Yellow - 28BYJ48 pin 3
int motorPin4 = 11; 

AccelStepper stepper(4,8,9,10,11); // Defaults to 4 pins on 2, 3, 4, 5


void setup()
{  
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  
//Serial.begin(115200);
}

void loop()
{  

  pos= stepper.currentPosition();
if(pos==0 && st==0)
{

   stepper.setAcceleration(90.0);
   stepper.setMaxSpeed(500.0);
   stepper.moveTo(1000);

   st=1;

}

if(pos==1000 && st==1)
{
   stepper.setAcceleration(90.0);
   stepper.setMaxSpeed(100.0);
   stepper.moveTo(500);
   
   st=2;

}

if(pos==500 && st==2)
{
   stepper.setAcceleration(10.0);
   stepper.setMaxSpeed(300.0);
   stepper.moveTo(0);
   
   st=0;

}
   stepper.run();  
   //Serial.print("currentPosition");
   //Serial.println(stepper.currentPosition());
   //Serial.print("runSpeed");
   //Serial.println(stepper.runSpeed());
   
   //Faire autre chose
   
  if (st==0) digitalWrite(13,LOW);
  if (st==1) digitalWrite(13,HIGH);
    if (st==2) digitalWrite(13,LOW);
}
