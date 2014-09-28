#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);

    // パーティクルの初期位置を設定
    particleA.position = ofVec2f(10, 100);
    particleB.position = ofVec2f(10, 200);

    // Moverのインスタンス化
    mover = new Mover();
    
    // A: オブジェクトの値渡し
    mover->setParticle(particleA);
    // B: オブジェクトのポインタ渡し
    mover->setParticlePtr(&particleB);
}

//--------------------------------------------------------------
void ofApp::update(){
    mover->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    // A: 値渡しの描画
    ofSetColor(ofColor::red);
    particleA.draw();
    // B: ポインタ渡しの描画
    ofSetColor(ofColor::blue);
    particleB.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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