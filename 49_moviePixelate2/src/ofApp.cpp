#include "ofApp.h"

void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetRectMode(OF_RECTMODE_CENTER);
    //フォントを読みこみ
    font.loadFont("Miguta.otf", 8);
	//640x480 pixelでカメラの映像をキャプチャー
    myVideo.initGrabber(800, 600, true);    
}

void ofApp::update(){
	//カメラの取得を更新
    myVideo.update();
}

void ofApp::draw(){
	//位置を補整
	int left = (ofGetWidth() - myVideo.width) / 2;
	int top = (ofGetHeight() - myVideo.height) / 2;
	//全てのピクセルの値を取得
	unsigned char * pixels = myVideo.getPixels();
	
	int skip = 11;
	ofTranslate(left, top+skip);
	ofSetColor(0, 0, 0);
	for (int i = 0; i < myVideo.width; i = i + skip){
		for (int j = 0; j < myVideo.height; j = j + skip){
            //RGBごとのピクセルの値を取得
            int r = pixels[j * myVideo.width * 3 + i * 3];
			int g = pixels[j * myVideo.width * 3 + i * 3 + 1];
			int b = pixels[j * myVideo.width * 3 + i * 3 + 2];
			//明度を算出
			int brightness = (r + g + b) / 3.0f;
			//濃度の応じた文字をとりだし
            int num = ofMap(brightness, 0, 255, 0, 9);
            string str = ofToString(num);
			//文字を描画
            ofSetColor(r,g,b);
            font.drawString(str, i, j);
		}
	}
}