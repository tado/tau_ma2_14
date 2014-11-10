#pragma once
#include "ofxState.h"

class TemplateState : public itg::ofxState<> {

public:
    void setup();
    void update();
    void draw();

    string getName();
    
    ofTrueTypeFont font;
};