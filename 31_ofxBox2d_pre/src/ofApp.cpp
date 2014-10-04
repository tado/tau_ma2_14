#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面の基本設定
    ofSetFrameRate(60);
    ofBackground(0);
    
    // Box2Dの世界の設定
    box2d.init();               // 初期化
    box2d.setGravity(0, 10);    // 重力
    box2d.createBounds();       // 画面の周囲に壁を作成
    box2d.setFPS(30.0);         // box2Dの世界でのFPS
    box2d.registerGrabbing();   // 物体をつかめるようにする
}

//--------------------------------------------------------------
void ofApp::update(){
    box2d.update();             // box2Dの更新
}

//--------------------------------------------------------------
void ofApp::draw(){

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
