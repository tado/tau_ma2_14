#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {
	
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	
	void reset();	
	ofImage img;
	ofImageQualityType quality;
	ofVideoGrabber myVideo;
};
