#pragma once
#include "ofMain.h"
#include "Particle.h"

class Mover{
    
public:
    // 参照渡しは、コンストラクタのイニシャライザで
    Mover(Particle &particleB):particleB(particleB){};

    void setParticle(Particle p);       // 値渡し
    void setParticlePtr(Particle *p);   // ポインタ渡し
    
    void update();
    
    Particle particleA;
    Particle &particleB;
    Particle *particleC;
};