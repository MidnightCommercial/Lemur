#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    ofBackground(0, 0, 0);
//    eye1 = drawableRef(new SVGPath("Assets/Test/Gun_outline.svg"));
        drawableRef fat = drawableRef(new SVGPath(ofToDataPath("fat.svg")));
    eye1 = drawableRef(new GMLPath(ofToDataPath("159.gml")));
    //    lsys = drawableRef(new LSystem());
    
    drawableRef bird = drawableRef(new Bird(ofPoint(0.5,0.5),0.1));
    
    drawableRef sq = drawableRef(new Square(ofRectangle(0,0,0.5,0.5),8));
    drawableRef doodle = drawableRef(new Doodle(ofPoint(0.2,0.5,0), ofPoint(0.8,0.5,0),6.17,8.5));
//    doodle->rfreq=0.5;
//    doodle->setTimeFunction(timeFuncRef(new Speed(0.5)));

    
    for (int i = 10 ; i > 0 ; i--){
        float x = ofRandom(1.0);
        float y = ofRandom(1.0);
        float s = ofRandom(0.05,0.15);
        drawableRef b = drawableRef(new Bird(ofPoint(x,y),s));
        b->setTime(ofRandom(1.0));
        lemur.add(b);
    }
    
    //    lsys->setup();
    //    lemur.add(lsys);
    
}

//--------------------------------------------------------------
void testApp::update(){
    lemur.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    lemur.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}