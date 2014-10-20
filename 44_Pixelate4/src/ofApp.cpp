#include "ofApp.h"

void ofApp::setup(){
	ofBackground(255, 255, 255);
	//ビットマップ画像の読みこみ
	myImage.loadImage("t_hero.png");
    //フォントを読みこみ
    font.loadFont("Miguta.otf", 8);
	
	//文字の濃度を文字列に
	pixelString = "0123456789";
	
}

void ofApp::update(){	
}

void ofApp::draw(){
	int left = (ofGetWidth() - myImage.width) / 2;
	int top = (ofGetHeight() - myImage.height) / 2;
	ofTranslate(left, top);
	unsigned char * pixels = myImage.getPixels();

	int skip = 11;
	ofSetColor(0, 0, 0);
	
	for (int i = 0; i < myImage.width; i = i + skip){
		for (int j = 0; j < myImage.height; j = j + skip){
            //グレイスケールの濃度を取得
			int brightness = pixels[j * myImage.width + i];
			//濃度の応じた文字をとりだし
            int num = ofMap(brightness, 0, 255, 9, 0);
            string str = ofToString(num);
			//文字を描画
            font.drawString(str, i, j);
		}
	}
}