#include "ofApp.h"

void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetLineWidth(3);
	
	//ビットマップ画像の読みこみ
	myImage.loadImage("t_hero.png");
}

void ofApp::update(){	
}

void ofApp::draw(){
	int left = (ofGetWidth() - myImage.width) / 2;
	int top = (ofGetHeight() - myImage.height) / 2;
	ofTranslate(left, top);
	unsigned char * pixels = myImage.getPixels();

	int skip = 12;
	ofSetColor(0, 0, 0);
	
	for (int i = 0; i < myImage.width; i = i + skip){
		for (int j = 0; j < myImage.height; j = j + skip){
			int brightness = pixels[j*myImage.width + i];
			float pct = 1.0 - brightness / 255.0f;
			//角度を変化させて線を描く
			ofPushMatrix();
			ofTranslate(i, j);
			ofRotateZ(pct * 90);
			ofSetLineWidth(pct * skip / 2 + 1);
			ofLine(-skip/2, 0, skip/2, 0);
			ofPopMatrix();
		}
	}
}