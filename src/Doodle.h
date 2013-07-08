//
//  Doodle.h
//  Lemur
//
//  Created by Omer Shapira on 07/07/13.
//
//

#pragma once
#include "Drawable.h"
#include "ofNoise.h"
#include <complex>

#define RESOLUTION 0.001 //TODO: Make this a param

class Doodle : public Drawable {
    ofPolyline bounds, line;
    ofPoint start, end;
public:
    
    Doodle(string name="Random Doodle"){
        Drawable::name=name;
        setup();
    }
    
    Doodle(ofPoint lineBegin, ofPoint lineEnd, string name="Directed Doodle"):start(lineBegin), end(lineEnd){
        Drawable::name=name;
        setup();
    }
    
    void setup(){
        Poly p;
        polys.push_back(p);
        buildLine();
    }
    
    void setBounds(ofPolyline& l){
        bounds = l;
    }
    
    void buildLine(){
        for (float i = 0.0; i <= 1.0; i += RESOLUTION){
            line.addVertex(getAt(start.getInterpolated(end, i)));
        }
    }
    
    ofPoint getAt(const ofPoint& at, int seed=0){
    	//TODO: Worry about seed a little later
    	complex<float> c = polar(_slang_library_noise1(at.x-1), _slang_library_noise1(at.y+100));
    	return (at + ofPoint(c.real(), c.imag(), 0));
    }
    
    void update(){
        //dirty, dirty, c++
        vector<ofPoint>& verts = polys.back().getVertices();
        verts.clear();
        //find the "percentage"
        int stopIndex = (int) floor(time*line.size());
        stopIndex = MIN(stopIndex, line.size());
        verts.insert(verts.begin(), line.getVertices().begin(), line.getVertices().begin() + stopIndex);
    }
    
};