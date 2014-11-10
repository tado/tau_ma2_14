#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    
    //シーンを新規の生成し、配列に追加
    // A
    BaseScene *sa = new SceneA();
    sa->setup();
    scenes.push_back(sa);
    // B
    BaseScene *sb = new SceneB();
    sb->setup();
    scenes.push_back(sb);
    // C
    BaseScene *sc = new SceneC();
    sc->setup();
    scenes.push_back(sc);
    
    //現在のシーンを0に
    currentScene = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    scenes[currentScene]->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //現在表示しているシーンを描画
    scenes[currentScene]->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // キー入力でシーンを変更
    switch (key) {
        case '1':
            currentScene = 0;
            break;
        case '2':
            currentScene = 1;
            break;
        case '3':
            currentScene = 2;
            break;
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
