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

    typedef ofPtr <Drawable> drawableRef;
    
    class LemurDraw{
        vector<drawableRef> drawables;
        ofxIlda::Frame ildaFrame;
        ofxEtherdream etherdream;
    protected:
        float masterTime;
        
    public:
        LemurDraw(int endCount=0, int blankCount=20, int pps=25000, int targetPointCount=400){
            etherdream.setup();
            etherdream.setPPS(pps);
            
            ildaFrame.params.output.doCapX=true;
            ildaFrame.params.output.doCapY=true;
            ildaFrame.params.output.blankCount=blankCount;
            ildaFrame.params.output.endCount=endCount;
            ildaFrame.polyProcessor.params.smoothAmount = 0;
            ildaFrame.polyProcessor.params.spacing = 0.00001;
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
                vector<ofxIlda::Poly> polysToInsert = drawables[i]->getPolys();
                for (int j = 0; j < polysToInsert.size(); j++) {
                    ildaFrame.addPoly(polysToInsert[j]);
                }
            }
            ildaFrame.update();
            
        }
        
        void update(){
            masterTime = ofGetElapsedTimef();
            for (int i = 0 ; i < drawables.size() ; i++){
                drawables[i]->setTime(masterTime);
                drawables[i]->update();
            }
        }
        
        void draw(){
            drawToIlda();
//            ildaFrame.update();
            for(int i = 0; i < drawables.size();i++){
                drawables[i]->draw();
            }
            // draw to the screen
            ildaFrame.draw(0, 0, ofGetWidth(), ofGetHeight());
            
            // send points to the etherdream
            etherdream.setPoints(ildaFrame);
            
            ofSetColor(255);
        }
        
        void add(drawableRef d){
            drawables.push_back(d);
        }
        
        
    };
}
