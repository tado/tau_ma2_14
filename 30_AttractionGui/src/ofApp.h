#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "ofxGui.h"

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
    
    // パーティクルクラスをインスタンス化
    vector<Particle> particles;
    // メッシュ
    ofVboMesh mesh;
    // 引力が働いているか
    bool atraction;
    
    // GUI
    ofxPanel gui;
    ofxIntSlider num;
    ofxFloatSlider size;
    ofxFloatSlider friction;
    ofxFloatSlider attraction;
    ofxColorSlider bgColor;
    ofxColorSlider fgColor;
    
    // イベントリスナー
    void onNumChanged(int &num);
    void onFrictionChanged(float &friction);
};
