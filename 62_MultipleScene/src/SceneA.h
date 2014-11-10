#pragma once

#include "ofMain.h"
#include "BaseScene.h"

// BaseSceneを継承したSceneA
class SceneA : public BaseScene {
    
public:
    void setup();
    void update();
    void draw();
    
    ofTrueTypeFont font;
};
