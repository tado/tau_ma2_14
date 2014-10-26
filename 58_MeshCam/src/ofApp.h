#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    // クラス定数
    static const int WIDTH = 640;
    static const int HEIGHT = 480;
    static const int NUM_PARTICLES = WIDTH * HEIGHT;
    
    ofEasyCam cam; // カメラ
    ofLight light; // ライト
    ofVbo myVbo; // VBO
    ofVec3f myVerts[NUM_PARTICLES]; // 頂点の座標
    ofFloatColor myColor[NUM_PARTICLES]; // 頂点の色情報
    ofVideoGrabber myVideo;	// ビデオキャプチャ
};
