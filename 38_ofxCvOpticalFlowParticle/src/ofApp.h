#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"
#include "Particle.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    // Optical Flow
    ofVideoGrabber camera;
    ofxCv::FlowFarneback flow;
    
    // GUI
    ofxPanel gui;
    ofxFloatSlider pyrScale;
    ofxIntSlider levels;
    ofxIntSlider winsize;
    ofxIntSlider iterations;
    ofxIntSlider polyN;
    ofxFloatSlider polySigma;
    ofxFloatSlider flowScale;
    ofxToggle drawFlow;
    ofxToggle fullscreen;
    ofxButton resetParticleButton;
    
    void resetParticlePressed();
    
    // Particle
    vector<Particle> particles;
    static const int NUM = 20000;
    ofVboMesh mesh;
};
