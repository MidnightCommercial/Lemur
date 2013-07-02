//
//  TimeFunction.h
//  Lemur
//
//  Created by Omer Shapira on 01/07/13.
//
//

#pragma once

namespace Lemur {
    
    class TimeFunction {
        TimeFunction* prevLink;
        bool chained;
        
    public:
        TimeFunction(){
            chained = false;
        }
        TimeFunction(TimeFunction& chain){
            chained = true;
            prevLink = &chain;
        }
        
        virtual float computeTime(float t){
            return t;
        }
        
        float get(float t){
            float frac = chained ? prevLink->get(t) : t;
            if ((frac > 1.0) || (frac < 0.0)){
                //TODO: Check if you're not a complete idiot
                frac = abs(frac - ((int) frac));
                
                return computeTime(frac);
            }
            
        }
    };
}
