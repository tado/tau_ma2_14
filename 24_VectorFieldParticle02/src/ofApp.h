#pragma once

#include "ofMain.h"
#include "VectorField.h"
#include "Particle.h"

class ofApp : public ofSimpleApp{
	
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

    // ベクターフィールド
	VectorField VF;
    // ベクターフィールドのモード
	int addMode;
    // パーティクル
    vector <Particle> particles;
    // VBOメッシュ
    ofVboMesh mesh;
    // パーティクルの数
    int particlesNum;
    // マウスボタンを押しているか
    bool mousePress;
};
