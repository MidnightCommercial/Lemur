//
//  Step.h
//  Lemur
//
//  Created by Omer Shapira on 07/07/13.
//
//

#pragma once
#include "LemurTimeFunction.h"
#include "ofMain.h"

class TimeStep : public TimeFunction {
    float steps;
public:
    TimeStep(float steps=2.0, string _name="Time Step"): steps(steps) {
        name=_name;
    }
    TimeStep(float steps, timeFuncRef chain, string _name="Time Step"): steps(steps){
        TimeFunction(chain,_name);
    }
    
    float computeTime(float t){
        return (steps > 0) ? t - fmod(t, 1/steps) : t;
    }
};

class Speed : public TimeFunction {
    float coeff;
public:
    Speed(float coeff=2.0, string _name="Speed"): coeff(coeff) {
        name=_name;
    }
    Speed(float coeff, timeFuncRef chain,string _name="Speed"): coeff(coeff){
        TimeFunction(chain,_name);
    }

    float computeTime(float t){
        return fmod(t*coeff,1);
    }
};

class Offset : public TimeFunction {
    float offset;
public:
    Offset(float offset=2.0, string _name="Offset"): offset(offset) {
        name = _name;
    }
    Offset(float offset, timeFuncRef chain,string _name="Offset"): offset(offset){
        TimeFunction(chain,_name);
    }

    float computeTime(float t){
        float f; // That's the way C++ wants it
        //FIXME: Math won't accept 1.0
        return modf(t+offset, &f);
    }
};