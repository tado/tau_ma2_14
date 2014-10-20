#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
	//カメラからの映像取得のためのクラス
    ofVideoGrabber myVideo;
	string pixelString;
    ofTrueTypeFont font;
};
