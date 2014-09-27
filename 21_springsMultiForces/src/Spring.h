#pragma once

#include "ofMain.h"
#include "Particle.h"

class Spring {
    
public:
    // コンストラクタ
    Spring();
    
    // 両端のParticleへの参照
    Particle *particleA;
    Particle *particleB;
    
    // 力をかけていない状態のばねの長さ
    float distance;
    // ばね定数
    float springiness;
    
    void update();
    void draw();
};