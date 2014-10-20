#include "ofApp.h"

void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofEnableSmoothing();
	
	//ビットマップ画像の読みこみ
	myImage.loadImage("t_hero.png");
}

void ofApp::update(){	
}

void ofApp::draw(){
	//画像の位置を調整
	int left = (ofGetWidth() - myImage.width) / 2;
	int top = (ofGetHeight() - myImage.height) / 2;
	ofTranslate(left, top);
	
	//ピクセル情報をとりだす
	unsigned char * pixels = myImage.getPixels();

	//12ピクセル毎に明度を取り出し、その色でRectを描画
	int skip = 12;
	ofSetColor(0, 0, 0);
	for (int i = 0; i < myImage.width; i = i + skip){
		for (int j = 0; j < myImage.height; j = j + skip){
			int brightness = pixels[j*myImage.width + i];
			//大きさの割合(%)を算出
			float pct = 1.0 - brightness / 255.0f;
			//円を描く
			ofCircle(i, j, pct * skip * 0.5);
		}
	}
}