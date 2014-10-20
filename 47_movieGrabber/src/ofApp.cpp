#include "ofApp.h"

void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(0, 0, 0);

	//640x480 pixelでカメラの映像をキャプチャー
    myVideo.initGrabber(640, 480, true);    
}

void ofApp::update(){
	//カメラの取得を更新
    myVideo.update();
}

void ofApp::draw(){
	//位置を補整
	int left = (ofGetWidth() - myVideo.width) / 2;
	int top = (ofGetHeight() - myVideo.height) / 2;
	ofTranslate(left, top);
	
	//カメラの映像を描画
	myVideo.draw(0, 0);
}