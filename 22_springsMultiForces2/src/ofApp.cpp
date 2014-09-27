#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){	
	
	ofBackground(0,0,0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

    for (int i = 0; i < 100; i++){
		Particle myParticle;
        myParticle.friction = 0.04;
        myParticle.radius = 2;
		float x = 500 + 100 * cos ( (i / 200.0) * TWO_PI);
		float y = 500 + 100 * sin ( (i / 200.0) * TWO_PI);
        myParticle.setup(ofVec2f(x, y), ofVec2f(0, 0));
		particles.push_back(myParticle);
	}
    
	//全ての配列を順番にspringで接続していく
	for (int i = 0; i < particles.size(); i++){
		Spring mySpring;
		mySpring.distance = 0;
		mySpring.springiness = 0.6;
		mySpring.particleA = &(particles[i]);
		mySpring.particleB = &(particles[(i+1) % particles.size()]);
		springs.push_back(mySpring);
	}    
}

//--------------------------------------------------------------
void ofApp::update(){
	//全てのparticleの力をリセット
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}

	for (int i = 0; i < particles.size(); i++){
        if(pressed){
            // マウスの位置に反発する力
            particles[i].addAttractionForce(mouseX, mouseY, 200, 4.0);
        } else {
            // マウスの位置に引きつけられる力
            particles[i].addRepulsionForce(mouseX, mouseY, 200, 4.0);
        }

        // パーティクル同士の反発する力
		for (int j = 0; j < i; j++){
			particles[i].addRepulsionForce(particles[j], 100, 1.0);
		}
	}
	
	//バネを更新
    for (int i = 0; i < springs.size(); i++){
        springs[i].update();
    }
	
	//パーティクルの状態を更新 (壁でバウンド)
    for (int i = 0; i < particles.size(); i++){
        particles[i].updateForce();
        particles[i].update();
        particles[i].bounceOffWalls();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofBeginShape();
    for (int i = 0; i < particles.size(); i++){
        ofVertex(particles[i].position.x, particles[i].position.y);
    }
    ofEndShape();
    
    if(pressed){
        ofSetColor(255, 0, 0);
    } else {
        ofSetColor(0, 255, 255);
    }
    ofCircle(mouseX, mouseY, 4);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        for (int i = 0; i < particles.size(); i++){
            particles[i].setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    pressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    pressed = false;
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}