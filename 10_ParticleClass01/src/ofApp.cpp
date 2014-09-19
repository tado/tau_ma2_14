#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
    ofSetCircleResolution(4);
    
    for (int i = 0; i < CIRCLE_NUM; i++){
        // 摩擦係数を設定
        particle[i].friction = 0.002;
        particle[i].gravity.set(0, 0.25);
        // 初期位置を設定
        particle[i].setInit(ofVec2f(ofGetWidth()/2, ofGetHeight()/2));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < CIRCLE_NUM; i++){
        particle[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    for (int i = 0; i < CIRCLE_NUM; i++) {
        particle[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f') {
        ofToggleFullscreen();
    }
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
    for (int i = 0; i < CIRCLE_NUM; i++){
        // 初期位置を設定
        particle[i].setInit(ofVec2f(x, y));
    }
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
