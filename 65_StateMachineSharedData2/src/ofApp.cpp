#include "ofApp.h"
#include "CircleState.h"
#include "BoxState.h"
#include "ParticleState.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // StateMachineを初期化
    stateMachine.addState<CircleState>();
    stateMachine.addState<BoxState>();
    stateMachine.addState<ParticleState>();
    
    stateMachine.changeState("circle");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') {
        stateMachine.changeState("circle");
    }
    if (key == '2') {
        stateMachine.changeState("box");
    }
    if (key == '3') {
        stateMachine.changeState("particle");
    }
    
    // fキーでフルスクリーン表示
    if(key == 'f'){
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
