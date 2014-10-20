#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
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
    ofTranslate(left, top);
    
    //全てのピクセルの値を取得
    unsigned char * pixels = myVideo.getPixels();
    
    int skip = 12;
    for (int i = 0; i < myVideo.width; i = i + skip){
        for (int j = 0; j < myVideo.height; j = j + skip){
            
            //RGBごとのピクセルの値を取得
            int r = pixels[j * myVideo.width * 3 + i * 3];
            int g = pixels[j * myVideo.width * 3 + i * 3 + 1];
            int b = pixels[j * myVideo.width * 3 + i * 3 + 2];
            //明度を算出
            int brightness = (r + g + b) / 3.0f * 255.0f;
            float pct = (r + g + b) / 3.0f / 255.0f;
            //四角形の角度と大きさで画像を再現
            ofSetColor(255,255,255);
            ofPushMatrix();
            ofTranslate(i, j);
            ofRotateZ(pct * 180);
            ofRect(0, 0, skip * pct, skip * pct);
            ofPopMatrix();
        }
    }
}