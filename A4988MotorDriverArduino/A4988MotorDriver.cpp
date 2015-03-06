//
//  A4988MotorDriver.cpp
//  
//
//  Created by Pedro on 03/03/15.
//
//

#include "Arduino.h"
#include "A4988MotorDriver.h"

A4988MotorDriver::A4988MotorDriver(int stepPin, int dirPin, int steps) {
   
    pinMode(stepPin,OUTPUT);
    pinMode(dirPin,OUTPUT);
    digitalWrite(dirPin, HIGH);
    
    _stepPin=stepPin;
    _dirPin=dirPin;
    _steps=steps;
    
}

void A4988MotorDriver::step(int stepNum, uint8_t dir,  uint8_t style){
    
    if (dir==BACKWARD){
        digitalWrite(_dirPin, LOW);
    }
    else if (dir==FORWARD){
        digitalWrite(_dirPin, HIGH);
    }
    else {
        Serial.println("Error in A4988MotorDriver::step() function");
        
    }
    
    //if (style==DOUBLE) {
    //    stepNum=stepNum*2;
    //}
    
    for (int i=1; i<=stepNum;i++){
        digitalWrite(_stepPin,HIGH);
        //delayMicroseconds(2);//Hold at high for 10 microsecs
         delay(_delayTime);
        digitalWrite(_stepPin,LOW);
        //delay(_delayTime);
        delayMicroseconds(10);
        
        //Serial.println(_delayTime);
        //delayMicroseconds(10);
    }
    
}


void A4988MotorDriver::setSpeed(float rpmmotor) {
    _speedRPM=rpmmotor;
    _delayTime=1e3*60/(_speedRPM*_steps);
    // 60/(speed*steps) gives the time, in seconds, per pulse, for a given value of RPM
    // multiplying for 1e6 gives the same value in microseconds
    //Serial.println(_delayTime);
    //Serial.println(_speedRPM);
    //Serial.println(_steps);

    
}


int A4988MotorDriver::PrintStepPin(){
    
    return _stepPin;
}

int A4988MotorDriver::PrintDirPin(){
    
    return _dirPin;
}

float A4988MotorDriver::PrintMotorVelocity(){
    
    return _speedRPM;
}


float A4988MotorDriver::PrintDelayTime(){
    
    return _delayTime;
}


int A4988MotorDriver::PrintSteps(){
    
    return _steps;
}