#pragma once
#include "ofMain.h"
#include "Particle.h"

class Mover{
    
public:
    void setParticle(Particle p);       // 値渡し
    void setParticlePtr(Particle *p);   // ポインタ渡し
    void update();
    
    Particle particleA;     // 値渡しされるParticle
    Particle *particleB;    // ポインタ渡しされるParticle
};