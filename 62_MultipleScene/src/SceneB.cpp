#include "SceneB.h"

void SceneB::setup(){
    font.loadFont("NotoSans-Bold.ttf", 50);
}

void SceneB::update(){
	
}

void SceneB::draw(){
	ofBackgroundHex(0x00FF00);
	ofSetHexColor(0xFFFFFF);
    font.drawString("Hi, I am SceneB!", 40, ofGetHeight() / 2.0);
}