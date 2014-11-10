#pragma once

#include "ofxState.h"
#include "SharedData.h"

class BoxState : public itg::ofxState<SharedData> {
    void setup();
    void update();
    void draw();
    string getName();
    
    float rotation;
    ofBoxPrimitive box;
    ofLight light;
};