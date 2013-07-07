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
    TimeStep(float steps=2.0, string name="Time Step"): steps(steps) {
        TimeFunction(name);
    }
    TimeStep(float steps, timefuncRef chain,string name="Time Step"): steps(steps){
        TimeFunction(chain,name);
    }
    
    float computeTime(float t){
        return (steps > 0) ? t - (t % (1 / steps)) : t;
    }
};

class Speed : public TimeFunction {
    float coeff;
public:
    TimeStep(float coeff=2.0, string name="Speed"): coeff(coeff) {
        TimeFunction(name);
    }
    TimeStep(float coeff, timefuncRef chain,string name="Speed"): coeff(coeff){
        TimeFunction(chain,name);
    }

    float computeTime(float t){
        return t*coeff;
    }
};

class Offset : public TimeFunction {
    float offset;
public:
    TimeStep(float offset=2.0, string name="Offset"): offset(offset) {
        TimeFunction(name);
    }
    TimeStep(float offset, timefuncRef chain,string name="Offset"): offset(offset){
        TimeFunction(chain,name);
    }

    float computeTime(float t){
        return (t+offset)%(1.0);
    }
};