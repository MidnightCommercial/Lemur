//
//  Square.h
//  Lemur
//
//  Created by Omer Shapira on 06/07/13.
//
//

#pragma once
#import "ofMain.h"

class Square : public Drawable {
    
    ofRectangle bounds;
    float numLines;
    
public:
    
       Square(ofRectangle rect, float numLines=4): numLines(numLines){
           //this is the square
           polys.push_back(ofxIlda::Poly());
           bounds = rect;
    }
    
    void setTime(float t){
        Drawable::setTime(timeFunc->get(t));
        update();
    }
    
private:
    
    void update(){
        Poly& p = polys.front();
        //is this really the best way to reset the data structure?
        p.clear();
        ofPoint c;
        float m;
        int s;
        for (int i = 0 ; i < numLines; i++ ){
            s = i < numLines/2; //evals to 0 or 1
            if (s){
                c = bounds.getTopRight();
                m = 0;
            } else {
                c = bounds.getBottomLeft();
                m = numLines/2;
            }
            
            ofPoint p1 = c.getInterpolated(bounds.getBottomRight(), ofMap(i+time, m, m + numLines/2 , !s, s));
            ofPoint p2 = c.getInterpolated(bounds.getTopLeft(),     ofMap(i+time, m, m + numLines/2 , !s, s));
            p.lineTo((i%2)? p1 : p2);
            p.lineTo((i%2)? p2 : p1);
        }
    }
    
    
};