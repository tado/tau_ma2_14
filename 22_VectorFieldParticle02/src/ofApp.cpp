#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    ofSetCircleResolution(3);
    
    // パーティクルの数
    particlesNum = 100000;
    
    //パーティクルを10000個生成
    for (int i = 0; i < particlesNum; i++){
        Particle myParticle;
        myParticle.friction = 0.004;
        myParticle.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
        particles.push_back(myParticle);
    }
    
    //ベクトル場の初期化 (画面いっぱいに、横102コ、縦76コのベクトル)
    VF.setupField(102, 76, ofGetWidth(), ofGetHeight());
    
    //初期状態は、引き付ける力
    addMode = 2;
    
    // メッシュを点で描画
    mesh.setMode(OF_PRIMITIVE_POINTS);
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
        particles[i].update();
        particles[i].throughOfWalls();
    }
    if (mousePress) {
        //モードに応じてベクトル場に力を加える
        float strength = 0.1;
        float radius = ofGetWidth() / 2.0;
        switch (addMode) {
            case 1:
                //外向き
                VF.addOutwardCircle(mouseX, mouseY, radius, strength);
                break;
                
            case 2:
                //内向き
                VF.addInwardCircle(mouseX, mouseY, radius, strength);
                break;
                
            case 3:
                //時計回り
                VF.addClockwiseCircle(mouseX, mouseY, radius / 4.0, strength);
                break;
                
            case 4:
                //反時計回り
                VF.addCounterClockwiseCircle(mouseX, mouseY, radius / 4.0, strength);
                break;
                
            default:
                break;
        }
    }
    
    VF.fadeField(0.99);
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
    ofSetColor(255);
    ofDrawBitmapString("key 1 - 4 : change vector mode", 20, 20);
    ofDrawBitmapString(msg, 20, 40);
    
    /*
    //ベクトル場を描画
    ofSetColor(0,127,255, 200);
    VF.draw();
     */
    
    //ベクトル場に配置されたparticleを描画
    ofSetColor(255);
    mesh.clear();
    for (int i = 0; i < particles.size(); i++){
        mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y, 0));
    }
    mesh.draw();
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
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mousePress = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mousePress = false;
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
