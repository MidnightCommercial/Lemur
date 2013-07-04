//
//  Drawable.h
//  Lemur
//
//  Created by Omer Shapira on 01/07/13.
//
//

#pragma once
namespace Lemur {
    
#include "ofxIldaPoly.h"
#include "LemurTimeFunction.h"
    
    
    class Drawable {
    protected:
        float time;
        vector<ofxIlda::Poly> polys;
        //TODO: Simplify this address (OmerShapira)
        Lemur::TimeFunction::timeFuncRef timeFunc;
    public:
        
        ofVec2f scale, position, center;
        
        Drawable(){
            timeFunc = Lemur::TimeFunction::timeFuncRef(new Lemur::TimeFunction());
        }
        
        void setTime(float t){
            //ask the time function what time it really is
            time = timeFunc->get(t);
        }
        
        virtual void draw(){
        
        }
        
        const vector<ofxIlda::Poly>& getPolys(){
            //TODO: I'm not sure this really returns what it's supposed to (OmerShapira)
            return polys;
        }
        
        void setTimeFunction(Lemur::TimeFunction::timeFuncRef t){
            timeFunc = t;
        }
    
    void setup(){}
    
    };
}

//TODO: Must find a way to sequence the Polys inside one drawable. Do they move independently? Are they locked? (OmerShapira)
