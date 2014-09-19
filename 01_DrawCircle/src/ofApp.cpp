#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
    ofSetCircleResolution(32);
    
    // 画面内のランダムな場所を指定
    position.x = ofRandom(ofGetWidth());
    position.y = ofRandom(ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // 設定した場所に円を描く
    ofSetHexColor(0x3399cc);
    ofCircle(position.x, position.y, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
