//
//  LemurTimeFunction.h
//  Lemur
//
//  Created by Omer Shapira on 01/07/13.
//
//

#pragma once

namespace Lemur {
    //redefinition for typedef to work
    //TODO: find a better solution
    class TimeFunction;
    
    typedef ofPtr<TimeFunction> timeFuncRef;
    class TimeFunction {
        //Is this the right place to put this? (OmerShapira)
        
    public:
        typedef ofPtr<TimeFunction> timeFuncRef;
    protected:
        timeFuncRef prevLink;
        bool chained;
    public:
        TimeFunction(){
            chained = false;
        }
        TimeFunction(timeFuncRef chain){
            chained = true;
            prevLink = chain;
        }
        
        virtual float computeTime(float t){
            return t;
        }
        
        float get(float t){
            float frac = chained ? prevLink->get(t) : t;
            if ((frac > 1.0) || (frac < 0.0)){
                //TODO: Check if the math is correct (OmerShapira)
                frac = abs(frac - ((int) frac));
                
                return computeTime(frac);
            }
            
        }
    };
}
