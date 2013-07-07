//
//  LemurTimeFunction.h
//  Lemur
//
//  Created by Omer Shapira on 01/07/13.
//
//

#pragma once

namespace Lemur {
    
    
    class TimeFunction {
    protected:
        typedef ofPtr<TimeFunction> timeFuncRef;
        timeFuncRef prevLink;
        bool chained;
        string name;
    public:
        TimeFunction(string name=""): chained(false), name(name) {}
        TimeFunction(timeFuncRef chain,string name="") : chained(true), prevLink(chain), name(name){}
        
        virtual float computeTime(float t){ return t; }
        
        float get(float t){
            float frac = chained ? prevLink->get(t) : t;
            if ((frac > 1.0) || (frac < 0.0)){
                //TODO: Check if the math is correct (OmerShapira)
                frac = abs(frac - ((int) frac));
                
                return computeTime(frac);
            }
        }
        string getChain(){
            if (!chained){
                return name;
            } else {
                //recursive
                return prevLink->getChain() + " --> " + name;
            }
        }
};
    //redefinition for typedef to work
    //TODO: find a better solution
    //    class TimeFunction;
    
typedef ofPtr<TimeFunction> timeFuncRef;
}
