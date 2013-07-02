#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0, 0, 0);
    eye1 = lemurDrawableRef(new SVGPath("Assets/Test/Eye-Brown.svg"));
    eye2 = lemurDrawableRef(new SVGPath("Assets/Test/Yesilelma_eye.svg"));
    
    lemur.add(eye1);
    lemur.add(eye2);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

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