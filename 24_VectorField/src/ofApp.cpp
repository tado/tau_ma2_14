#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    
    //ベクトル場の初期化 (画面いっぱいに、横102コ、縦76コのベクトル)
    VF.setupField(102, 76, ofGetWidth(), ofGetHeight());
    
    //初期状態は、外向きの力
    addMode = 1;
}

//--------------------------------------------------------------
void ofApp::update(){
    VF.fadeField(0.998f);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //現在のモードを画面に表示
    string msg;
    switch (addMode) {
        case 1:
            msg = "mode : Outward";
            break;
            
        case 2:
            msg = "mode : Inward";
            break;
            
        case 3:
            msg = "mode : Clockwise";
            break;
            
        case 4:
            msg = "mode : Counter Clockwise";
            break;
            
        default:
            break;
    }
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("key 1 - 4 : change vector mode", 20, 20);
    ofDrawBitmapString(msg, 20, 40);
    
    //ベクトル場を描画
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetColor(0,130,130, 200);
    VF.draw();
    ofDisableBlendMode();    
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    
    // 1 - 4のキーでベクトル場のモードを変更
    switch (key) {
        case '1':
            //外向き
            addMode = 1;
            break;
            
        case '2':
            //内向き
            addMode = 2;
            break;
            
        case '3':
            //時計回り
            addMode = 3;
            break;
            
        case '4':
            //反時計回り
            addMode = 4;
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    //モードに応じてベクトル場に力を加える
    switch (addMode) {
            
        case 1:
            //外向き
            VF.addOutwardCircle(x,y, 100, 0.5);
            break;
            
        case 2:
            //内向き
            VF.addInwardCircle(x,y, 100, 0.5);
            break;
            
        case 3:
            //時計回り
            VF.addClockwiseCircle(x, y, 200, 0.5);
            break;
            
        case 4:
            //反時計回り
            VF.addCounterClockwiseCircle(x, y, 200, 0.5);
            break;
            
        default:
            break;
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
