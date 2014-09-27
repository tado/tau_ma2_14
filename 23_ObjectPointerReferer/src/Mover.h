#pragma once
#include "ofMain.h"
#include "Particle.h"

class Mover{
public:
    void setParticle(Particle p);
    void setParticleRef(Particle &p);
    void setParticlePtr(Particle *p);
    
    void update();
    
    Particle particleA;
    Particle particleB;
    Particle *particleC;
};