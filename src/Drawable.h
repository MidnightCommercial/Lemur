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
        vector<ofxIlda::Poly> polys;
        Lemur::TimeFunction* time;
    public:
        
        ofVec2f scale, position, center;
        
        virtual void draw(){
        
        }
        
        const vector<ofxIlda::Poly>& getPolys(){
            //TODO: I'm not sure this is true
            return polys;
        }
        
        void setTimeFunction(Lemur::TimeFunction& t){
            time = &t;
        }
        
    };
}

//TODO: Must find a way to sequence the Polys inside one drawable. Do they move independently? Are they locked?
