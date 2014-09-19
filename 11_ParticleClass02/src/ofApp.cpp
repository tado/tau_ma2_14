#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
    ofSetCircleResolution(4);

}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < particles.size(); i++){
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    for (int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }
    
    // ログを表示
    ofDrawBitmapString("Particle num = " + ofToString(particles.size()), 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f') {
        ofToggleFullscreen();
    }
    if (key == 'c') {
        particles.clear();
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
    for (int i = 0; i < 10; i++){
        Particle p;
        // 摩擦係数を設定
        p.friction = 0.01;
        // 重力は0に
        p.gravity.set(0, 0);
        // 初期位置を設定
        p.setInit(ofVec2f(x, y));
        // 初期速度を設定
        float length = ofRandom(3.0);
        float angle = ofRandom(PI * 2);
        p.velocity.x = cos(angle) * length;
        p.velocity.y = sin(angle) * length;
        // Vectorに追加
        particles.push_back(p);
    }
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
