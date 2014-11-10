#include "BoxState.h"

void BoxState::setup(){
    rotation = 0;
    box.set(300);
    light.enable();
}

void BoxState::update(){
}

void BoxState::draw(){
    ofPushStyle();
    ofBackground(63);
    ofSetColor(31, 127, 255);
    ofEnableLighting();
    ofEnableDepthTest();
    box.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
    box.rotate(4, 0.5, 1.0, 0.2);
    box.draw();
    ofDisableDepthTest();
    ofDisableLighting();
    ofPopStyle();
}

string BoxState::getName(){
    return "box";
}