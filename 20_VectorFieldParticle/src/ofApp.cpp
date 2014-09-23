#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    ofSetCircleResolution(3);
    
    //パーティクルを10000個生成
    for (int i = 0; i < 5000; i++){
        Particle myParticle;
        myParticle.friction = 0.01;
        myParticle.radius = 2;
        myParticle.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
        particles.push_back(myParticle);
    }
    
    //ベクトル場の初期化 (画面いっぱいに、横102コ、縦76コのベクトル)
    VF.setupField(102, 76, ofGetWidth(), ofGetHeight());
    
    //初期状態は、時計回りの力
    addMode = 3;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < particles.size(); i++){
        //particleの力をリセット
        particles[i].resetForce();
        
        //ベクトル場から、それぞれのparticleにかかる力を算出
        ofVec2f force;
        force = VF.getForceFromPos(particles[i].position.x, particles[i].position.y);
        
        //Particleの状態を更新
        particles[i].addForce(ofVec2f(force.x, force.y));
        particles[i].updateForce();
        particles[i].bounceOffWalls();
        particles[i].update();
    }
    
    //ベクトル場の力の減衰
    VF.fadeField(0.998f);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //現在のモードを画面に表示
    string msg;
    switch (addMode) {
        case 1:
            msg = "mode : Outward";
            break;
            
        case 2:
            msg = "mode : Inward";
            break;
            
        case 3:
            msg = "mode : Clockwise";
            break;
            
        case 4:
            msg = "mode : Counter Clockwise";
            break;
            
        default:
            break;
    }
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("key 1 - 4 : change vector mode", 20, 20);
    ofDrawBitmapString(msg, 20, 40);
    
    //ベクトル場を描画
    ofSetColor(0,130,130, 127);
    VF.draw();
    
    //ベクトル場に配置されたparticleを描画
    ofSetColor(255);
    for (int i = 0; i < particles.size(); i++){
        particles[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    
    // 1 - 4のキーでベクトル場のモードを変更
    switch (key) {
        case '1':
            //外向き
            addMode = 1;
            break;
            
        case '2':
            //内向き
            addMode = 2;
            break;
            
        case '3':
            //時計回り
            addMode = 3;
            break;
            
        case '4':
            //反時計回り
            addMode = 4;
            break;
            
        case ' ':
            //パーティクルの場所を初期化
            for (int i = 0; i < particles.size(); i++){
                particles[i].setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
            }
            VF.setupField(102, 76, ofGetWidth(), ofGetHeight());
            VF.clear();
            break;
            
        case 'r':
            //ベクターフィールドをランダムに
            VF.randomizeField(4.0);
            break;
            
        case 'f':
            //フルスクリーン
            ofToggleFullscreen();
            break;
            
        default:
            break;
    }
}


//--------------------------------------------------------------
void ofApp::keyReleased  (int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    //モードに応じてベクトル場に力を加える
    switch (addMode) {
        case 1:
            //外向き
            VF.addOutwardCircle(x,y, 100, 0.5);
            break;
            
        case 2:
            //内向き
            VF.addInwardCircle(x,y, 100, 0.5);
            break;
            
        case 3:
            //時計回り
            VF.addClockwiseCircle(x, y, 200, 0.5);
            break;
            
        case 4:
            //反時計回り
            VF.addCounterClockwiseCircle(x, y, 200, 0.5);
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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
