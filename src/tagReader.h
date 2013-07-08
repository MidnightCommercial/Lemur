//
//  tagReader.h
//  tag_Capture_simple
//
//  Created by Dan Moore on 3/13/13.
//
//
#pragma once
#include "ofMain.h"
#include "ofxXmlSettings.h"

class tagReader{
    
public:
    
    
    struct brush{
        int num;
        int size;
        float time;
    };
    
    struct playbackTag{
        vector<ofColor> colors;
        vector<brush> brushes;
        vector<ofPolyline> strokes;
        deque<float> stops;
        float startTime;
        float endTime;
        float offsetX;
        float offsetY;
        string name;
    };
    

    
    void loadFile(string path);
    void clear();
    
    
    vector<playbackTag> tags;
protected:
    int count;
    
    
};