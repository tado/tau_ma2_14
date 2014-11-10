#include "SceneA.h"

void SceneA::setup(){
    font.loadFont("NotoSans-Bold.ttf", 50);
}

void SceneA::update(){
	
}

void SceneA::draw(){
	ofBackgroundHex(0xFF0000);
	ofSetHexColor(0xFFFFFF);
    font.drawString("Hi, I am SceneA!", 40, ofGetHeight() / 2.0);
}