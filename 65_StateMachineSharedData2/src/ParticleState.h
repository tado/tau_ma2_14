#pragma once

#include "ofVbo.h"
#include "ofxState.h"
#include "SharedData.h"

#define	NUM_BILLBOARDS	40000

class ParticleState : public itg::ofxState<SharedData> {
	
public:
	
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
    string getName();
    
	ofEasyCam cam;
	float zoom;
	float zoomTarget;
	ofImage texture;
	ofVbo billboardVbo;
	ofVec3f billboardVerts[NUM_BILLBOARDS];
	ofFloatColor billboardColor[NUM_BILLBOARDS];
	ofVec3f billboardVels[NUM_BILLBOARDS];
};