//
//  LemurDraw.h
//  Lemur
//
//  Created by Omer Shapira on 01/07/13.
//
//

#pragma once

#import "ofxIldaFrame.h"
#import "ofxEtherdream.h"

namespace Lemur {

    typedef ofPtr <Drawable> lemurDrawableRef;
    
    class LemurDraw{
        vector<lemurDrawableRef> drawables;
        ofxIlda::Frame ildaFrame;
        ofxEtherdream etherdream;
        
    public:
        LemurDraw(int endCount=10, int blankCount=10, int pps=25000, int targetPointCount=400){
            etherdream.setup();
            etherdream.setPPS(pps);
            
            ildaFrame.params.output.doCapX=true;
            ildaFrame.params.output.doCapY=true;
            ildaFrame.params.output.blankCount=blankCount;
            ildaFrame.params.output.endCount=endCount;
            
            ildaFrame.polyProcessor.params.targetPointCount=targetPointCount;
            
        }
        
        void drawToScreen(){
            for (int i = 0; i < drawables.size(); ++i)
            {
                drawables[i]->draw();
            }
        }
        
        void drawToIlda(){
            ildaFrame.clear();
            for (int i = 0; i < drawables.size(); i++) {
                const vector<ofxIlda::Poly>& polysToInsert = drawables[i].get()->getPolys(); //Fuck you, Stroustrup
                for (int j = 0; j < polysToInsert.size(); j++) {
                    //TODO: Remove color, this is just a test
                    ildaFrame.addPoly(polysToInsert[j], ofFloatColor(1,1,1,1));
                }
            }
            ildaFrame.update();
            
        }
        
        void update();
        
        void add(lemurDrawableRef d){
            drawables.push_back(d);
        }
        
        
    };
}
