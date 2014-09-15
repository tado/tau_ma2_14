#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
    ofSetCircleResolution(32);
    
    // 画面内のランダムな場所と速度を円の数だけ指定
    for (int i = 0; i < CIRCLE_NUM; i++) {
        posX[i] = ofRandom(ofGetWidth());
        posY[i] = ofRandom(ofGetHeight());
        speedX[i] = ofRandom(-10, 10);
        speedY[i] = ofRandom(-10, 10);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    // 円の座標を全て更新
    for (int i = 0; i < CIRCLE_NUM; i++) {
        posX[i] += speedX[i];
        posY[i] += speedY[i];
        
        // 画面からはみ出たらバウンドさせる
        if (posX[i] < 0 || posX[i] > ofGetWidth()) {
            speedX[i] *= -1;
        }
        if (posY[i] < 0 || posY[i] > ofGetHeight()) {
            speedY[i] *= -1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0x3399cc);
    // 画面内のランダムな場所を円の数だけ描画
    for (int i = 0; i < CIRCLE_NUM; i++) {
        ofCircle(posX[i], posY[i], 20);
    }
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
