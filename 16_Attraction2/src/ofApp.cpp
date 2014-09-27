#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    // メッシュを点で描画
    mesh.setMode(OF_PRIMITIVE_POINTS);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(2.0);
    
    for (int i = 0; i < NUM; i++) {
        Particle p;
        p.friction = 0.0005;
        p.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())),
                ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1)));
        particles.push_back(p);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < particles.size(); i++){
        // 力をリセット
        particles[i].resetForce();
        // パーティクル同士の反発する力
        for (int j = 0; j < i; j++){
            particles[i].addAttractionForce(particles[j], 120.0, 0.001);
        }
        // マウスをクリックした点に引力を加える
        if (atraction) {
            particles[i].addAttractionForce(mouseX, mouseY, ofGetWidth(), 0.1);
        }
        // 力と位置の更新
        particles[i].update();
        // 壁の端にきたら、反対側へ
        particles[i].throughOfWalls();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // 画面をフェード
    ofSetColor(0, 15);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    // メッシュを点で描く
    mesh.clear();
    ofSetColor(255);
    for (int i = 0; i < particles.size(); i++) {
        mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y, 0));
    }
    mesh.draw();
    
    // 重力の点を描く
    if (atraction) {
        ofSetColor(255, 0, 0);
    } else {
        ofSetColor(0, 255, 255);
    }
    ofCircle(mouseX, mouseY, 4);
    
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
    if (key == 'c') {
        particles.clear();
        for (int i = 0; i < NUM; i++) {
            Particle p;
            p.friction = 0.0005;
            p.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())),
                    ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1)));
            particles.push_back(p);
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
    atraction = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    atraction = false;
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
