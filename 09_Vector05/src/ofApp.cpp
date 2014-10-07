#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
    ofSetCircleResolution(4);
    
    // 摩擦係数を設定
    friction = 0.002;
    // 円を初期化
    setInit(ofVec2f(ofGetWidth()/2, ofGetHeight()/2));
}

//--------------------------------------------------------------
void ofApp::update(){
    // 力をリセット
    resetForce();
    // 重力を加える
    addForce(ofVec2f(0, 0.25));
    // 力の更新 (摩擦)
    updateForce();
    // 円の座標を全て更新
    updatePos();
    // 画面からはみ出たらバウンドさせる
    bounceOffWalls();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    // 画面内のランダムな場所を円の数だけ描画
    for (int i = 0; i < CIRCLE_NUM; i++) {
        ofCircle(position[i], 2);
    }
}

//--------------------------------------------------------------

void ofApp::setInit(ofVec2f initPos){
    // 画面内のランダムな場所と速度を円の数だけ指定
    for (int i = 0; i < CIRCLE_NUM; i++) {
        position[i].x = initPos.x;
        position[i].y = initPos.y;
        float length = ofRandom(20);
        float angle = ofRandom(PI * 2);
        velocity[i].x = cos(angle) * length;
        velocity[i].y = sin(angle) * length;
        force[i].set(0, 0);
    }
}

//--------------------------------------------------------------
void ofApp::resetForce(){
    // 力をリセット
    for (int i = 0; i < CIRCLE_NUM; i++) {
        force[i].set(0, 0);
    }
}

//--------------------------------------------------------------
void ofApp::addForce(ofVec2f _force){
    // 力を加える
    for (int i = 0; i < CIRCLE_NUM; i++) {
        force[i] += _force;
    }
}

//--------------------------------------------------------------
void ofApp::updateForce(){
    // 力の更新 (摩擦)
    for (int i = 0; i < CIRCLE_NUM; i++) {
        force[i] -= velocity[i] * friction;
    }
}

//--------------------------------------------------------------
void ofApp::updatePos(){
    // 円の座標を全て更新
    for (int i = 0; i < CIRCLE_NUM; i++) {
        velocity[i] += force[i];
        position[i] += velocity[i];
    }
}

//--------------------------------------------------------------
// 画面の端でバウンドする(改定版)
void ofApp::bounceOffWalls(){
    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();
    for (int i = 0; i < CIRCLE_NUM; i++) {
        if (position[i].x > maxx){
            position[i].x = maxx;
            velocity[i].x *= -1;
        }
        if (position[i].x < minx){
            position[i].x = minx;
            velocity[i].x *= -1;
        }
        
        if (position[i].y > maxy){
            position[i].y = maxy;
            velocity[i].y *= -1;
        }
        if (position[i].y < miny){
            position[i].y = miny;
            velocity[i].y *= -1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f') {
        ofToggleFullscreen();
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
    setInit(ofVec2f(x, y));
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
