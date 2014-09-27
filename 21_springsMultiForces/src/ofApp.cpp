#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0,0,0);
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    // 初期位置でParticleを円形に配置
    for (int i = 0; i < 200; i++){
        Particle myParticle;
        myParticle.friction = 0.02;
        myParticle.radius = 2;
        float x = ofGetWidth()/2 + 100 * cos ( (i / 200.0) * TWO_PI);
        float y = ofGetHeight()/2 + 100 * sin ( (i / 200.0) * TWO_PI);
        myParticle.setup(ofVec2f(x, y), ofVec2f(0, 0));
        particles.push_back(myParticle);
    }
    
    //全ての配列を順番にspringで接続していく
    for (int i = 0; i < particles.size(); i++){
        Spring mySpring;
        mySpring.distance = 4;
        mySpring.springiness = 0.5;
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
    
    // Particleにかかる引力と反発力
    for (int i = 0; i < particles.size(); i++){
        if(pressed){
            // マウスの位置に反発する力
            particles[i].addAttractionForce(mouseX, mouseY, 200, 1.0);
        } else {
            // マウスの位置に引きつけられる力
            particles[i].addRepulsionForce(mouseX, mouseY, 200, 1.0);
        }
        // パーティクル同士の反発する力
        for (int j = 0; j < i; j++){
            particles[i].addRepulsionForce(particles[j], 50, 0.1);
        }
    }
    
    //バネを更新
    for (int i = 0; i < springs.size(); i++){
        springs[i].update();
    }
    
    //パーティクルの状態を更新 (壁でバウンド)
    for (int i = 0; i < particles.size(); i++){
        particles[i].updateForce();
        particles[i].update();
        particles[i].bounceOffWalls();
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
    // スペースキーでリセット
    if (key == ' ') {
        for (int i = 0; i < particles.size(); i++){
            particles[i].setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
        }
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
    pressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    pressed = false;
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