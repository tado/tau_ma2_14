#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    for (int i = 0; i < NUM; i++) {
        Particle p;
        p.friction = 0.001;
        p.mass = ofRandom(3.0);
        p.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())),
                ofVec2f(0, 0));
        particles.push_back(p);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        // パーティクル同士の引き付けあう力
        for (int j = 0; j < i; j++){
            // 2つの点の質量から、引力の強さを計算
            float strength = particles[j].mass * particles[i].mass * 0.001;
            particles[i].addAttractionForce(particles[j], 200, strength);
        }
        particles[i].update();
        particles[i].throughOfWalls();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // 画面をフェード
    ofSetColor(0, 15);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    // パーティクルを円で描く
    ofSetColor(255);
    for (int i = 0; i < particles.size(); i++) {
        ofCircle(particles[i].position.x, particles[i].position.y, particles[i].mass);
    }
    
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
    particles.clear();
    for (int i = 0; i < NUM; i++) {
        Particle p;
        p.friction = 0.001;
        p.mass = ofRandom(3.0);
        p.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())),
                ofVec2f(0, 0));
        particles.push_back(p);
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
