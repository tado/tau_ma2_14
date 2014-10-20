#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();

	//ofImageをインスタンス化
	ofImage myImage;
	string pixelString;
    ofTrueTypeFont font;
};
