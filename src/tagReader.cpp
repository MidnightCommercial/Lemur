//
//  tagReader.cpp
//  tag_Capture_simple
//
//  Created by Dan Moore on 3/13/13.
//
//

#include "tagReader.h"


void tagReader::loadFile(string path){
    playbackTag tag;
    tag.name = path;
    tag.offsetY = 0;
    tag.offsetX = 0;
    ofxXmlSettings foo;
    foo.loadFile(path);
    if(foo.tagExists("GML")){
        foo.pushTag("GML");
        
        if(foo.tagExists("tag")){
            foo.pushTag("tag");
            
            
            if(foo.tagExists("environment")){
                foo.pushTag("environment");
                foo.pushTag("offset");
                tag.offsetX = foo.getValue("x", 0.0);
                tag.offsetY = foo.getValue("y", 0.0);
                foo.popTag();
                foo.popTag();
            }
            
            

            if(foo.tagExists("drawing")){
                foo.pushTag("drawing");
        
                
                
                count = foo.getNumTags("brush");
                
                for(int i = 0; i < count; i++){
                    ofColor color;
                    brush foobar;
                    
                    foo.pushTag("brush", i);
                    foo.pushTag("color");
                    
                    
                    float r = foo.getValue("red", 0.0);
                    float b = foo.getValue("blue", 0.0);
                    float g = foo.getValue("green", 0.0);
                    foo.popTag();
                    int size = foo.getValue("size", 30);
                    int num = foo.getValue("number", 4);
                    float t = foo.getValue("time", 0.0);
                    
                    
                    color.set(r, g, b);
                    
                    foobar.num = num;
                    foobar.size = size;
                    foobar.time = t;
                    
                    tag.brushes.push_back(foobar);
                    tag.colors.push_back(color);
                    foo.popTag();
                }


                
                count = foo.getNumTags("stroke");
                for(int i = 0; i < foo.getNumTags("stroke"); i++){
                    foo.pushTag("stroke", i);
                    cout<<"STROKE: "<<i<<endl;
                    ofPolyline line;
                    int numPtTags = foo.getNumTags("pt");
                    for(int j = 0; j < numPtTags; j++){
                        double x = foo.getValue("pt:x", 0.0, j);
                        double y = foo.getValue("pt:y", 0.0, j);
                        double t = foo.getValue("pt:t", 0.0, j);
                        line.addVertex(ofPoint(x, y, t));
                    }
                    tag.strokes.push_back(line);
                    foo.popTag();
                }
                tags.push_back(tag);
            }else{
                cout<<"cannot load file 1"<<endl;
            }
        }else{
            cout<<"cannot load file 2"<<endl;
        }
    }else{
        cout<<"cannot load file 3"<<endl;
    }
    
    
}

void tagReader::clear(){
    tags.clear();
}

