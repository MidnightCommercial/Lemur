//
//  GMLPath.h
//  Lemur
//
//  Created by Dan Moore on 7/7/13.
//
//

#pragma once
#include "ofxSVG.h"
#include "Drawable.h"
#include "ofxIldaPoly.h"
#include "tagReader.h"
using namespace Lemur;


class GMLPath : public Drawable{
    string filepath;
    
public:
    GMLPath();
    GMLPath(string _filepath){
        loadFile(_filepath);
    }
    void loadFile(string _filepath);
    void draw();
    tagReader reader;
};
