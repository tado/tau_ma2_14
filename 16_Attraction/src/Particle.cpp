#include "Particle.h"

Particle::Particle(){
    radius = 5.0;
    friction = 0.01;
    mass = 1.0;
    bFixed = false;
}

void Particle::setup(ofVec2f _position, ofVec2f _velocity){
    // 位置を設定
    position = _position;
    // 初期速度を設定
    velocity = _velocity;
}
void Particle::setup(float positionX, float positionY, float velocityX, float velocityY){
    // 位置を設定
    position = ofVec2f(positionX, positionY);
    // 初期速度を設定
    velocity = ofVec2f(velocityX, velocityY);
}

// 力をリセット
void Particle::resetForce(){
    force.set(0, 0);
}

// 力を加える
void Particle::addForce(ofVec2f _force){
    force += _force / mass;
}
void Particle::addForce(float forceX, float forceY){
    force += ofVec2f(forceX, forceY);
}

// 摩擦力の更新
void Particle::updateForce(){
    force -= velocity * friction;
}

// 位置の更新
void Particle::updatePos(){
    if (!bFixed) {
        velocity += force;
        position += velocity;
    }
}

// 力の更新と座標の更新をupdateとしてまとめる
void Particle::update(){
    updateForce();
    updatePos();
}


// 画面の端でバウンドする(改定版)
void Particle::bounceOffWalls(){
    bool bDampedOnCollision = false;
    bool bDidICollide = false;
    
    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();
    
    if (position.x > maxx){
        position.x = maxx;
        velocity.x *= -1;
        bDidICollide = true;
    } else if (position.x < minx){
        position.x = minx;
        velocity.x *= -1;
        bDidICollide = true;
    }
    
    if (position.y > maxy){
        position.y = maxy;
        velocity.y *= -1;
        bDidICollide = true;
    } else if (position.y < miny){
        position.y = miny;
        velocity.y *= -1;
        bDidICollide = true;
    }
    
    if (bDidICollide == true && bDampedOnCollision == true){
        velocity *= 0.3;
    }
}

void Particle::throughOfWalls(){
    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();
    if (position.x < minx) {
        position.x = maxx;
    }
    if (position.y < miny) {
        position.y = maxy;
    }
    if (position.x > maxx) {
        position.x = minx;
    }
    if (position.y > maxy) {
        position.y = miny;
    }
}

// 描画
void Particle::draw(){
    ofCircle(position, radius);
}

// 反発する力
void Particle::addRepulsionForce(float x, float y, float radius, float scale){
    // 力の中心点を設定
    ofVec2f posOfForce;
    posOfForce.set(x,y);
    // パーティクルと力の中心点との距離を計算
    ofVec2f diff = position - posOfForce;
    float length = diff.length();
    // 力が働く範囲かどうか判定する変数
    bool bAmCloseEnough = true;
    // もし設定した半径より外側だったら、計算しない
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    // 設定した半径の内側だったら
    if (bAmCloseEnough == true){
        // 距離から点にかかる力ベクトルを計算
        float pct = 1 - (length / radius);
        diff.normalize();
        force.x = force.x + diff.x * scale * pct;
        force.y = force.y + diff.y * scale * pct;
    }
}

// 引き付けあう力
void Particle::addAttractionForce(float x, float y, float radius, float scale){
    // 力の中心点を設定
    ofVec2f posOfForce;
    posOfForce.set(x,y);
    // パーティクルと力の中心点との距離を計算
    ofVec2f diff = position - posOfForce;
    float length = diff.length();
    // 力が働く範囲かどうか判定する変数
    bool bAmCloseEnough = true;
    // もし設定した半径より外側だったら、計算しない
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    // 設定した半径の内側だったら
    if (bAmCloseEnough == true){
        // 距離から点にかかる力ベクトルを計算
        float pct = 1 - (length / radius);
        diff.normalize();
        force.x = force.x - diff.x * scale * pct;
        force.y = force.y - diff.y * scale * pct;
    }
}