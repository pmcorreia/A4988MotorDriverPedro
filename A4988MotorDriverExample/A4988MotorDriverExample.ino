#include <A4988MotorDriver.h>

int steps=200;
float rpm=100;

A4988MotorDriver * top_motor = new A4988MotorDriver(A4,A5,steps);

void setup()
{
  Serial.begin(9600);
  top_motor->setSpeed(rpm);
}

void loop()
{
  
  Serial.println("Variables");
  Serial.println(top_motor->PrintStepPin());
  Serial.println(top_motor->PrintDirPin());
  Serial.println(top_motor->PrintSteps());
  Serial.println(top_motor->PrintMotorVelocity());
  Serial.println("Time hold in each step, in ms:");
  Serial.println(top_motor->PrintDelayTime()/1e3);
  int a=0;
  while (a<200){
    
    if (a<100){
    top_motor->step(360, BACKWARD, DOUBLE);
    delay(1000);
    }
    else{
       if (a==200){
       //delay(100);
     }
       top_motor->step(1, FORWARD, INTERLEAVE);
       delay(1000);
    }
    a++;
  }
 
  delayMicroseconds(2);
 
  delay(100);
}

//#include <AccelStepper.h>
//
//AccelStepper Stepper1(1,13,12); //use pin 12 and 13 for dir and step, 1 is the "external driver" mode (A4988)
//int dir = 1; //used to switch direction
//
//void setup() {
//  int rpm=250;
//  Stepper1.setMaxSpeed(rpm*200/60); //set max speed the motor will turn (steps/second)
//  Stepper1.setAcceleration(500); //set acceleration (steps/second^2)
//}
//
//void loop() {
//  if(Stepper1.distanceToGo()==0){ //check if motor has already finished his last move
//    Stepper1.move(200*dir); //set next movement to 1600 steps (if dir is -1 it will move -1600 -> opposite direction)
//    //dir = dir*(-1); //negate dir to make the next movement go in opposite direction
//    delay(100); //wait 1 second
//  }
//  
//  Stepper1.run(); //run the stepper. this has to be done over and over again to continously move the stepper
//}


