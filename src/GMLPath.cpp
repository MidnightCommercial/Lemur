//
//  GMLPath.cpp
//  Lemur
//
//  Created by Dan Moore on 7/7/13.
//
//

#include "GMLPath.h"

//
//
//  This Needs LOTS of work.
//  To-Do:
//      Auto Flip
//      Scale Better
//      Read and add Color
//  


void GMLPath::loadFile(string path){
    reader.loadFile(path);
    if(reader.tags.size() > 0){
        for(int i = 0; i < reader.tags[0].strokes.size(); i++){
            ofxIlda::Poly p1 = ofxIlda::Poly(reader.tags[0].strokes[i]);
            polys.push_back(p1);
        }
    }
}

void GMLPath::draw(){
    for(int i = 0; i < polys.size(); i++){
        polys[i].draw();
    }
}