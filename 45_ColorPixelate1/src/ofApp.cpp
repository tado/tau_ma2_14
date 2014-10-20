#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0, 0, 0);
	
	//ビットマップ画像の読みこみ
	myImage.loadImage("jobs_color.png");
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

	//10ピクセル毎に明度を取り出し、その色でRectを描画
	int skip = 10;
	for (int i = 0; i < myImage.width; i = i + skip){
		for (int j = 0; j < myImage.height; j = j + skip){
			//RGBの順でデータをとりだす
			int r = pixels[j * myImage.width * 3 + i * 3];
			int g = pixels[j * myImage.width * 3 + i * 3 + 1];
			int b = pixels[j * myImage.width * 3 + i * 3 + 2];
			//取得した色で、四角形を描画
			ofSetColor(r, g, b);
			ofRect(i, j, skip, skip);	
		}
	}
}