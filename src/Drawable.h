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
        string name;
        float time;
        vector<ofxIlda::Poly> polys;
        timeFuncRef timeFunc;
        ofPoint center;
        float size;
        
    public:
        
        void setup(){}
        virtual void update(){}
        virtual void draw(){}
        
        Drawable(string name=""): name(name) { timeFunc = timeFuncRef(new TimeFunction()); }
        Drawable(timeFuncRef timeFunc, string name=""): name(name), timeFunc(timeFunc){}
        
        void setTime(float t){time = timeFunc->get(t);}
        
        void setName(string &s) { name = s; }
        const string& getName(){ return name; }
        
        const vector<ofxIlda::Poly>& getPolys(){return polys;}
        
        void setTimeFunction(timeFuncRef t){timeFunc = t;}
        
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
            scale(1/size);
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
