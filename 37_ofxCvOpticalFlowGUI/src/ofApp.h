#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    ofVideoGrabber camera;
    ofxCv::FlowFarneback farneback;
    ofxCv::FlowPyrLK pyrLk;
    ofxCv::Flow* curFlow;
    
    ofxPanel gui;
    ofxFloatSlider pyrScale;
    ofxIntSlider levels;
    ofxIntSlider winsize;
    ofxIntSlider iterations;
    ofxIntSlider polyN;
    ofxFloatSlider polySigma;
    ofxToggle OPTFLOW_FARNEBACK_GAUSSIAN;

    ofxToggle useFarneback;
    ofxIntSlider winSize;
    ofxIntSlider maxLevel;

    ofxFloatSlider maxFeatures;
    ofxFloatSlider qualityLevel;
    ofxFloatSlider minDistance;
};
