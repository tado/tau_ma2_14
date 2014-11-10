#pragma once

#include "ofxState.h"
#include "SharedData.h"

class CircleState : public itg::ofxState<SharedData> {
    void setup();
    void update();
    void draw();
    string getName();
    
    float radius;
};