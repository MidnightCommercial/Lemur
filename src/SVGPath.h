//
//  SVGPath.h
//  Lemur
//
//  Created by Omer Shapira on 01/07/13.
//
//

#pragma once
#include "ofxSVG.h"
#include "Drawable.h"
#include "ofxIldaPoly.h"

using namespace Lemur;
    
    
    class SVGPath : public Drawable{
        string filepath;
        
    public:
        SVGPath();
        SVGPath(string _filepath){
            loadFile(_filepath);
        }
        void loadFile(string _filepath);
        void draw();
        const vector<ofxIlda::Poly>& getPolys();
private:
    
};

