#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(60);
	quality = OF_IMAGE_QUALITY_WORST;
	//カメラを初期化
	myVideo.initGrabber(320, 240, true);
	//スクリーンをキャプチャしてofImageに格納
	img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
}

void ofApp::reset() {
	//ビデオをアップデート
	myVideo.update();
	//ビデオのフレームを1コマ読込み
	myVideo.draw(0, 0, ofGetWidth(), ofGetHeight());
	//スクリーンをキャプチャしてofImageに格納
	img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
}

void ofApp::update() {
	//Jpeg圧縮したデータの保存ファイル名
	string compressedFilename = "compressed.jpg";
	//Jpeg形式でファイルを保存
	img.saveImage(compressedFilename, quality);
	ofBuffer file = ofBufferFromFile(compressedFilename);
	int fileSize = file.size();
	//Jepgファイルをバッファーに読込み
	char * buffer = file.getBinaryBuffer();
	//データを破壊する場所をランダムに決定
	int whichByte = (int) ofRandom(fileSize);
	//ONにするbitをランダムに決定
	int whichBit = ofRandom(8);
	//ビットシフト(データを破壊?)
	char bitMask = 1 << whichBit;
	buffer[whichByte] |= bitMask;
	//glitchしたファイルを保存
	ofBufferToFile(compressedFilename, file);
	//再度読込み
	img.loadImage(compressedFilename);
	//ランダムなタイミングで自動的にリセット
	float coin = ofRandom(100);
	if (coin > 95) {
		reset();
	}
}

void ofApp::draw() {
	//glitchしたイメージを描画
	ofSetColor(255);
	img.draw(0, 0, ofGetWidth(), ofGetHeight());
}

void ofApp::keyPressed  (int key){
	reset();
}

void ofApp::mousePressed(int x, int y, int button){
	reset();
}