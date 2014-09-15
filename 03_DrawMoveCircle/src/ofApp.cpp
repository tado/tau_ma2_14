#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
    ofSetCircleResolution(32);
    
    // ランダムな場所と速度を指定
    positionX = ofRandom(ofGetWidth());
    positionY = ofRandom(ofGetHeight());
    velocityX = ofRandom(-10, 10);
    velocityY = ofRandom(-10, 10);
}

//--------------------------------------------------------------
void ofApp::update(){
    // 円の座標を更新
    positionX += velocityX;
    positionY += velocityY;

    // 画面からはみ出ないように
    if (positionX < 0 || positionX > ofGetWidth()) {
        velocityX *= -1;
    }
    if (positionY < 0 || positionY > ofGetHeight()) {
        velocityY *= -1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0x3399cc);
    // 円を描画
    ofCircle(positionX, positionY, 20);
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
