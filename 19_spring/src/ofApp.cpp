#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){	
	
	ofBackground(0,0,0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	//Particle A 初期設定
    particle_a.setup(ofVec2f(400, 400), ofVec2f(0,0));
    particle_a.friction = 0.04;
	
	//Particle B 初期設定
    particle_b.setup(ofVec2f(500, 500), ofVec2f(0,0));
    particle_b.friction = 0.04;

	//ばね(spring)を、パーティクル間に張る
	mySpring.distance = 100; //ばねの長さ
	mySpring.springiness = 0.1; //ばねの硬さ
	mySpring.particleA = &particle_a;
	mySpring.particleB = &particle_b;
}

//--------------------------------------------------------------
void ofApp::update(){
	//力をリセット
	particle_a.resetForce();
	particle_b.resetForce();
	
	//バネを更新
	mySpring.update();
	
	//パーティクルの状態を更新 (壁でバウンド)
    particle_a.bounceOffWalls();
	particle_a.update();

    particle_b.bounceOffWalls();
	particle_b.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255);
	
	//ばねを描画
    ofSetColor(191);
	mySpring.draw();
	
	//particleを描画
    ofSetHexColor(0x3399ff);
	particle_a.draw();
	particle_b.draw();
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
    // マウスドラッグで、Particle Aの位置を移動
    particle_a.position.set(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    // マウスを押すと、Particle Aの位置を固定
	particle_a.bFixed = true;   
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    // マウスを離すと、Particle Aの固定を開放
	particle_a.bFixed = false;   
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