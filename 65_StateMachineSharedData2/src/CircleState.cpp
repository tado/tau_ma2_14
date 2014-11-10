#include "CircleState.h"

void CircleState::setup(){
    ofSetCircleResolution(64);
    radius = 200;
}

void CircleState::update(){
    radius = sin(ofGetElapsedTimef()) * 100 + 200;
}

void CircleState::draw(){
    ofPushStyle();
    ofBackground(255,0,0);
    ofSetColor(0, 255, 0);
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, radius);
    ofPopStyle();
}

string CircleState::getName(){
    return "circle";
}