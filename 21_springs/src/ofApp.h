#pragma once


#include "ofMain.h"
#include "Particle.h"
#include "Spring.h"

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
    
    vector<Spring> springs;     // ばねの配列
    vector<Particle> particles; // パーティクルの配列
};

