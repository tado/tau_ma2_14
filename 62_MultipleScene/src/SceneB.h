#pragma once

#include "ofMain.h"
#include "BaseScene.h"

// BaseSceneを継承したSceneB
class SceneB : public BaseScene {
    
public:
    void setup();
    void update();
    void draw();
    
    ofTrueTypeFont font;
};
