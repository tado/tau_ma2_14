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
    // 円を描画
    for(int i=0; i<circles.size(); i++) {
        ofFill();
        ofSetHexColor(0xf6c738);
        circles[i].get()->draw();
    }
    // 四角を描画
    for(int i=0; i<boxes.size(); i++) {
        ofFill();
        ofSetHexColor(0xBF2545);
        boxes[i].get()->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // cキーで円を追加
    if(key == 'c') {
        float r = ofRandom(4, 20);
        circles.push_back(ofPtr<ofxBox2dCircle>(new ofxBox2dCircle));
        circles.back().get()->setPhysics(3.0, 0.53, 0.1);
        circles.back().get()->setup(box2d.getWorld(), mouseX, mouseY, r);
        
    }
    // bキーで四角を追加
    if(key == 'b') {
        float w = ofRandom(4, 20);
        float h = ofRandom(4, 20);
        boxes.push_back(ofPtr<ofxBox2dRect>(new ofxBox2dRect));
        boxes.back().get()->setPhysics(3.0, 0.53, 0.1);
        boxes.back().get()->setup(box2d.getWorld(), mouseX, mouseY, w, h);
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
