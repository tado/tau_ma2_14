#include "TemplateState.h"

void TemplateState::setup(){
    font.loadFont("NotoSans-Bold.ttf", 50);
}

void TemplateState::update(){
}

void TemplateState::draw(){
    ofBackground(64);
    ofSetColor(255);
    font.drawString("Hi, I'm State Machine!", 20, ofGetHeight() / 2);
}

string TemplateState::getName(){
    return "template";
}
