#include "ofApp.h"

const int ofApp::WIDTH;
const int ofApp::HEIGHT;
const int ofApp::NUM_PARTICLES;

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面の設定
    ofBackground(0);
    ofEnableDepthTest();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    cam.setDistance(100);
    
    // 頂点情報を初期化
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            myVerts[j * WIDTH + i].set(i - WIDTH/2, j - HEIGHT/2, 0);
            myColor[j * WIDTH + i].set(0.5, 0.8, 1.0, 1.0);
        }
    }
    
    // 頂点バッファに位置と色の情報を設定
    myVbo.setVertexData(myVerts, NUM_PARTICLES, GL_DYNAMIC_DRAW);
    myVbo.setColorData(myColor, NUM_PARTICLES, GL_DYNAMIC_DRAW);
}

//--------------------------------------------------------------
void ofApp::update(){
    // 頂点の座標を更新
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            float x = sin(i * 0.1 + ofGetElapsedTimef()) * 10.0;
            float y = sin(j * 0.15 + ofGetElapsedTimef()) * 10.0;
            float z = x + y;
            myVerts[j * WIDTH + i] = ofVec3f(i - WIDTH/2, j - HEIGHT/2, z);
        }
    }
    
    // 頂点バッファの頂点の座標情報を更新
    myVbo.updateVertexData(myVerts, NUM_PARTICLES);
}

//--------------------------------------------------------------
void ofApp::draw(){
    // VBOの頂点を描画
    cam.begin();
    glPointSize(2);
    myVbo.draw(GL_POINTS, 0, NUM_PARTICLES);
    cam.end();
    
    // ログの表示
    string info;
    info = "Vertex num = " + ofToString(NUM_PARTICLES, 0) + "\n";
    info += "FPS = " + ofToString(ofGetFrameRate(), 2);
    ofDrawBitmapString(info, 30, 30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // fキーでフルスクリーン表示
    if (key == 'f') {
        ofToggleFullscreen();
    }
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