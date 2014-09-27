#include "Mover.h"

// A: オブジェクトの値渡し
void Mover::setParticle(Particle p){
    particleA = p;
    particleA.velocity = ofVec2f(10.0, 0);
}

// B: オブジェクトの参照渡し
void Mover::setParticleRef(Particle &p){
    particleB = p;
    particleB.velocity = ofVec2f(10.0, 0);
}

// C: オブジェクトのポインタ渡し
void Mover::setParticlePtr(Particle *p){
    particleC = p;
    particleC->velocity = ofVec2f(10.0, 0);
}

// それぞれのオブジェクトを更新
void Mover::update(){
    particleA.resetForce();
    particleA.update();

    particleB.resetForce();
    particleB.update();

    particleC->resetForce();
    particleC->update();
}