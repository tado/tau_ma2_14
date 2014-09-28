#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);

    // パーティクルの初期位置を設定
    particleA.position = ofVec2f(10, 10);
    particleB.position = ofVec2f(10, 110);
    particleB.velocity = ofVec2f(10, 0);
    particleC.position = ofVec2f(10, 210);
    
    // B:参照渡しは、コンストラクタで渡す
    mover = new Mover(particleB);
    
    // A: オブジェクトの値渡し
    mover->setParticle(particleA);
    
    // C: オブジェクトのポインタ渡し
    mover->setParticlePtr(&particleC);
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
    // B: 参照渡しの描画
    ofSetColor(ofColor::blue);
    particleB.draw();
    // C: ポインタ渡しの描画
    ofSetColor(ofColor::yellow);
    particleC.draw();
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