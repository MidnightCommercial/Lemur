//
//  Drawable.h
//  Lemur
//
//  Created by Omer Shapira on 01/07/13.
//
//

#pragma once
#include "ofxIldaPoly.h"
#include "LemurTimeFunction.h"
using namespace ofxIlda;

namespace Lemur {
    
    class Drawable {
    protected:
        float time;
        vector<ofxIlda::Poly> polys;
        //TODO: Simplify this address (OmerShapira)
        Lemur::TimeFunction::timeFuncRef timeFunc;
    public:
        
        ofPoint center;
        float size;
        
        Drawable(){
            timeFunc = Lemur::TimeFunction::timeFuncRef(new Lemur::TimeFunction());
        }
        
        void setTime(float t){
            //ask the time function what time it really is
            time = timeFunc->get(t);
        }
        
        virtual void update(){}
        
        virtual void draw(){
            
        }
        
        const vector<ofxIlda::Poly>& getPolys(){
            update();
            //TODO: I'm not sure this really returns what it's supposed to (OmerShapira)
            return polys;
        }
        
        void setTimeFunction(Lemur::TimeFunction::timeFuncRef t){
            timeFunc = t;
        }
        
        void setup(){}
        void scale(float scaleBy){
            findCenter();
            for (int i = 0; i<polys.size(); i++) {
                polys[i].scaleAboutPoint(scaleBy, center);
            }
            findCenter();
        }
        
        void fitToCanvas(){
            //TODO: Move to center
            findCenter();
            scale(50/size);
            translate(ofPoint(0.5,0.5,0));
        }
        
        void translate(ofPoint p){
            for (int i = 0 ; i<polys.size() ; i++)
            {
                polys[i].translate(p);
            }
            //TODO: make "Changed"
            findCenter();
        }
        
        ofRectangle getBoundingBox(){
            ofRectangle rect = ofRectangle(0,0,0,0);
            for (int i = 0 ; i< polys.size(); i++){
                ofRectangle b = polys[i].getBoundingBox();
                rect.growToInclude(b);
            }
            return rect;
        }
        void findCenter(){
            ofRectangle b = getBoundingBox();
            //TODO: Check if this is correct
            center = b.getPosition();
            size = MAX(b.getWidth(), b.getHeight());
        }
        
    };
}

//TODO: Must find a way to sequence the Polys inside one drawable. Do they move independently? Are they locked? (OmerShapira)
