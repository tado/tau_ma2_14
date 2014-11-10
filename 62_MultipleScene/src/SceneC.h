#pragma once

#include "ofMain.h"
#include "BaseScene.h"

// BaseSceneを継承したSceneC
class SceneC : public BaseScene {
    
public:
    void setup();
    void update();
    void draw();
    
    ofTrueTypeFont font;
};
