#pragma once

#include "ofMain.h"
#include "BaseScene.h"
#include "SceneA.h"
#include "SceneB.h"
#include "SceneC.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //複数のシーンを格納する動的配列
    vector <BaseScene *> scenes;
    //現在のシーン番号
    int currentScene;
};
