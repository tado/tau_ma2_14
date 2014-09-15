#pragma once

#include "ofMain.h"

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
    
    // 描画する円の数を指定
    static const int CIRCLE_NUM = 400;
    
    // 位置ベクトルの配列
    ofVec2f position[CIRCLE_NUM];
    
    // 速度ベクトルの配列
    ofVec2f velocity[CIRCLE_NUM];
};
