#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetCircleResolution(4);
    
    //画面の更新をOFFに
    ofSetBackgroundAuto(false);
    
    // メッシュを点で描画
    mesh.setMode(OF_PRIMITIVE_POINTS);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < particles.size(); i++){
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // 画面をフェード
    ofSetColor(0, 0, 0, 15);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());

    // メッシュを点で描く
    mesh.clear();
    ofSetColor(255, 63);
    for (int i = 0; i < particles.size(); i++) {
        mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y, 0));
    }
    mesh.draw();
    
    //文字の背景
    ofSetColor(0, 127);
    ofRect(0, 0, 200, 60);
    
    // ログを表示
    ofSetColor(255);
    ofDrawBitmapString("fps = " + ofToString(ofGetFrameRate()), 10, 20);
    ofDrawBitmapString("Particle num = " + ofToString(particles.size()), 10, 40);
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
    for (int i = 0; i < 400; i++) {
        Particle p;
        // 摩擦係数を設定
        p.friction = 0.001;
        // 重力を設定
        p.gravity.set(0, 0);
        // 初期位置を設定
        p.setInit(ofVec2f(x, y));
        // 初期速度を設定
        float length = ofRandom(1);
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
