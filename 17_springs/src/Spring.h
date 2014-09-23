#pragma once

#include "ofMain.h"
#include "Particle.h"

class Spring {
	
public:
	
	Spring();
	
	Particle *particleA;
	Particle *particleB;
	
	float distance;
	float springiness;
	
	void update();
	void draw();	
};