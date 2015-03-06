//
//  A4988MotorDriver.h
//  
//
//  Created by Pedro on 03/03/15.
//
//

#ifndef _A4988MotorDriver_h
#define _A4988MotorDriver_h

#define FORWARD 1
#define BACKWARD 2

#define SINGLE 1
#define DOUBLE 2
#define INTERLEAVE 3
#define MICROSTEP 4
guyg

#include "Arduino.h"

class A4988MotorDrive{
    
public:
    
    A4988MotorDriver(int stepPin, int dirPin, int steps);
    void step(int stepNum, uint8_t dir,  uint8_t style = SINGLE);
    void setSpeed(float rpmmotor);
   // void PrintMotorInfo();
    int PrintStepPin();
    int PrintDirPin();
    int PrintSteps();
    float PrintMotorVelocity();
    float PrintDelayTime();
    
private:
    int _stepPin;
    int _dirPin;
    int _steps;
    float _speedRPM;
    float _delayTime;
    
    //    void Step(int n, char[] dir, char[] interleave ){
    //
    //      digitalWrite(stepPin,HIGH);
    //      delayMicroseconds(1);//Hold at high for 2 microsecs
    //      digitalWrite(stepPin,LOW);
    //      delayMicroseconds(1);
    //    }
};




#endif
