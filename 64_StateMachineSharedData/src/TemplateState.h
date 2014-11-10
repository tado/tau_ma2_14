#pragma once
#include "ofxState.h"
#include "SharedData.h"

class TemplateState : public itg::ofxState<SharedData> {

public:
    void setup();
    void update();
    void draw();

    string getName();
    
    ofTrueTypeFont font;
};