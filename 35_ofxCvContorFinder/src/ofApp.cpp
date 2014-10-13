#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    cam.initGrabber(ofGetWidth(), ofGetHeight());
    contourFinder.setMinAreaRadius(10);
    contourFinder.setMaxAreaRadius(200);
}

void ofApp::update() {
    cam.update();
    if(cam.isFrameNew()) {
        contourFinder.setThreshold(ofMap(mouseX, 0, ofGetWidth(), 0, 255));
        contourFinder.findContours(cam);
    }
}

void ofApp::draw() {
    ofSetColor(255);
    cam.draw(0, 0);
    contourFinder.draw();
}
