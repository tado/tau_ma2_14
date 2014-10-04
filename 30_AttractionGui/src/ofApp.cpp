#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);

    // イベントリスナー
    num.addListener(this, &ofApp::onNumChanged);
    friction.addListener(this, &ofApp::onFrictionChanged);
    
    ofColor minColor = ofColor(0, 0, 0, 0);
    ofColor maxColor = ofColor(255, 255, 255, 255);
    
    // GUI
    gui.setup();
    gui.add(num.setup("particle number", 100000, 0, 200000));
    gui.add(size.setup("particle size", 1.0, 0.0, 3.0));
    gui.add(friction.setup("friction", 0.002, 0.0, 0.02));
    gui.add(attraction.setup("attraction", 0.1, 0.0, 1.0));
    gui.add(bgColor.setup("bg color", ofColor(0), minColor, maxColor));
    gui.add(fgColor.setup("fg color", ofColor(255), minColor, maxColor));
    
    // 保存したパラメータ読み込み
    gui.loadFromFile("settings.xml");
    
    // メッシュを点で描画
    mesh.setMode(OF_PRIMITIVE_POINTS);
    glPointSize(1.0);
    
    for (int i = 0; i < num; i++) {
        Particle p;
        p.friction = friction;
        p.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
        particles.push_back(p);
    }
}

//--------------------------------------------------------------
// イベントリスナー

// 摩擦を変更
void ofApp::onFrictionChanged(float &friction){
    for (int i = 0; i < particles.size (); i++) {
        particles[i].friction = friction;
    }
}

// パーティクルの数を変更
void ofApp::onNumChanged(int &num){
    // もしパーティクルの数が設定数よりも少ない場合
    if (num < particles.size()) {
        // パーティクルを削除
        for (int i = 0; i < particles.size() - num; i++) {
            particles.pop_back();
        }
    }
    // もしパーティクルの数が設定数よりも多い場合
    if (num > particles.size()) {
        // パーティクルを追加
        int addNum = num - particles.size();
        for (int i = 0; i < addNum; i++) {
            Particle p;
            p.friction = friction;
            p.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
            particles.push_back(p);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    // パーティクルの数だけ計算
    for (int i = 0; i < particles.size(); i++){
        // 力をリセット
        particles[i].resetForce();
        // もし引力がはたらいていたら
        if (atraction) {
            // マウスの位置に引力を加える
            particles[i].addAttractionForce(mouseX, mouseY, ofGetWidth(), attraction);
        }
        // パーティクル更新
        particles[i].update();
        // 画面の端にきたら反対側へ
        particles[i].throughOfWalls();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // 背景
    ofBackground(bgColor);
    
    // メッシュを点で描く
    mesh.clear();
    ofSetColor(fgColor);
    glPointSize(size);
    for (int i = 0; i < particles.size(); i++) {
        mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y, 0));
    }
    mesh.draw();
    
    // 重力の点を描く
    if (atraction) {
        ofSetColor(255, 0, 0);
    } else {
        ofSetColor(0, 255, 255);
    }
    ofCircle(mouseX, mouseY, 4);
    
    //GUI
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c') {
        particles.clear();
        for (int i = 0; i < num; i++) {
            Particle p;
            p.friction = 0.002;
            p.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
            particles.push_back(p);
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
    atraction = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    atraction = false;
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
