#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0, 0, 0);
//    eye1 = lemurDrawableRef(new SVGPath("Assets/Test/Eye-Brown.svg"));
    //    eye2 = lemurDrawableRef(new SVGPath("Assets/Test/Yesilelma_eye.svg"));
    //    lsys = lemurDrawableRef(new LSystem());
    lemurDrawableRef sq = lemurDrawableRef(new Square(ofRectangle(ofPoint(0.2,0.2,0),ofPoint(0.8,0.8,0)), 8.0 ));
    sq->setTimeFunction(Lemur::TimeFunction::timeFuncRef(new TimeFunction()));
//    eye1->fitToCanvas();
//    lemur.add(eye1);
    lemur.add(sq);
    
    //    cout<< "Center: "<<eye2->center<<endl;
    //    cout<< "Size: "<<eye2->size<<endl;
    //    lemur.add(eye2);
    
    
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