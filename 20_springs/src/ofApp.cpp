#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0,0,0);
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    //particleの配列を生成
    for (int i = 0; i < 20; i++) {
        Particle p;
        p.radius = 5;
        p.friction = 0.01;
        p.setup(ofVec2f(ofGetWidth()/2, i * 20 + 100), ofVec2f(0,0));
        particles.push_back(p);
    }
    
    //全ての配列を順番にspringで接続していく
    for (int i = 0; i < (particles.size()-1); i++){
        Spring mySpring;
        mySpring.distance = 10;
        mySpring.springiness = 0.1;
        mySpring.particleA = &(particles[i]);
        mySpring.particleB = &(particles[(i+1) % particles.size()]);
        springs.push_back(mySpring);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //全てのparticleの力をリセット
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
    }
    
    //バネを更新
    for (int i = 0; i < springs.size(); i++){
        springs[i].update();
    }
    
    //パーティクルの状態を更新 (壁でバウンド)
    for (int i = 0; i < particles.size(); i++){
        particles[i].updateForce();
        particles[i].addForce(ofVec2f(0, 0.1));
        particles[i].bounceOffWalls();
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //全てのばねを描画
    ofSetColor(127, 127, 127);
    for (int i = 0; i < springs.size(); i++){
        springs[i].draw();
    }
    
    //全てのparticleを描画
    ofSetColor(0, 127, 255);
    for (int i = 0; i < particles.size(); i++){
        particles[i].draw();
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
    particles[0].position.set(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    particles[0].bFixed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    particles[0].bFixed = false;
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