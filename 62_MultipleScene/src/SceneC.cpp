#include "SceneC.h"

void SceneC::setup(){
    font.loadFont("NotoSans-Bold.ttf", 50);
}

void SceneC::update(){
	
}

void SceneC::draw(){
	ofBackgroundHex(0x0000FF);
	ofSetHexColor(0xFFFFFF);
    font.drawString("Hi, I am SceneC!", 40, ofGetHeight() / 2.0);
}