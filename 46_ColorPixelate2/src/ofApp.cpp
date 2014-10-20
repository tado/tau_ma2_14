#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0, 0, 0);
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	
	//ビットマップ画像の読みこみ
	myImage.loadImage("jobs_color.png");
}

void ofApp::update(){	
}

void ofApp::draw(){
	int left = (ofGetWidth() - myImage.width) / 2;
	int top = (ofGetHeight() - myImage.height) / 2;
	ofTranslate(left, top);
	unsigned char * pixels = myImage.getPixels();

	int skip = 4;
	for (int i = 0; i < myImage.width; i = i + skip){
		for (int j = 0; j < myImage.height; j = j + skip){
			int r = pixels[j * myImage.width * 3 + i * 3];
			int g = pixels[j * myImage.width * 3 + i * 3 + 1];
			int b = pixels[j * myImage.width * 3 + i * 3 + 2];
			//明度を算出
			int brightness = (r + g + b) / 3.0f * 255.0f;
			float pct = 1.0 - (r + g + b) / 3.0f / 255.0f;
			//線の角度と長さで画像を再現
			ofSetColor(r, g, b);
			ofPushMatrix();
			ofTranslate(i, j);
			ofRotateZ(pct * 20);
			ofLine(-pct*skip*4, 0, pct*skip*4, 0);
			ofPopMatrix();
		}
	}
}