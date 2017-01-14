

#include <AccelStepper.h>
long pos;
long pos2;
long DiffPos;
float cofCorrVit;
 
long csg=0;
long csg2=0;

int st=0;
int motorPin1 = 8;    // Blue   - 28BYJ48 pin 1
int motorPin2 = 9;    // Pink   - 28BYJ48 pin 2
int motorPin3 = 10;    // Yellow - 28BYJ48 pin 3
int motorPin4 = 11; 

int motorPin5 = 3;    // Yellow - 28BYJ48 pin 3
int motorPin6 = 4; 


AccelStepper stepper(4,8,9,10,11); // Defaults to 4 pins on 2, 3, 4, 5
AccelStepper stepper2(1,4,3); // Defaults to 4 pins on 2, 3, 4, 5

void setup()
{  
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  
  pinMode(motorPin5, OUTPUT);
  pinMode(motorPin6, OUTPUT);
  
Serial.begin(115200);
}

void loop()
{  

  pos= stepper.currentPosition();
  pos2= stepper2.currentPosition();  
if((pos==0) && (st==0))
{
csg=1000;
csg2=1000;

  stepper.setAcceleration(40.0);
   stepper.setMaxSpeed(600.0);
   stepper.moveTo(csg);
   
   stepper2.setAcceleration(40.0);
   stepper2.setMaxSpeed(600.0);
   stepper2.moveTo(csg2);
   
   st=1;

}

if(pos==1000 && st==1)
{
csg=0;
csg2=0;
   stepper.setAcceleration(40.0);
   stepper.setMaxSpeed(600.0);
   stepper.moveTo(csg);
   
      stepper2.setAcceleration(40.0);
   stepper2.setMaxSpeed(600.0);
   stepper2.moveTo(csg2);

   st=0;

}

DiffPos=(600*(stepper2.currentPosition())/(stepper.currentPosition()));
cofCorrVit=(600)*0.2;
stepper2.setMaxSpeed(cofCorrVit);




   stepper.run(); 
     //Serial.println(digitalRead(motorPin1)); 
   Serial.print("currentPosition: ");
   Serial.println(stepper.currentPosition());
   Serial.print("currentPosition2: ");
   Serial.println(stepper2.currentPosition());
   //Serial.print("runSpeed");
   //Serial.println(stepper.runSpeed());
   //Serial.println(pos);
   
   //stepper2.setAcceleration(40.0);
   //stepper2.setMaxSpeed(300.0);
   //stepper2.moveTo(pos);
   stepper2.run(); 
   

}