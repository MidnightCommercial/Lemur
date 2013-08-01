#pragma once

#include "ofMain.h"
#include "LemurUtils.h"
#include "ofxIldaFrame.h"
#include "ofxEtherdream.h"
#include "SVGPath.h"
#include "LemurDraw.h"
#include "LSystem.h"
#include "Square.h"
#include "GMLPath.h"
#include "Doodle.h"
#include "Bird.h"
#include "BaseTimeFunctions.h"


using namespace Lemur;

class testApp : public ofBaseApp{
    
    float w, h;
    drawableRef eye1, eye2, lsys;
    LemurDraw lemur;
    
	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

};
