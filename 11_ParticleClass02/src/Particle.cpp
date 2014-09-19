#include "Particle.h"

// 更新
void Particle::update(){
    resetForce();
    addForce(gravity);
    updateForce();
    updatePos();
}

// 描画
void Particle::draw(){
    ofCircle(position, 2);
}

// 初期設定
void Particle::setInit(ofVec2f initPos){
    position.x = initPos.x;
    position.y = initPos.y;
    force.set(0, 0);
}

// 力をリセット
void Particle::resetForce(){
    force.set(0, 0);
}

// 力を加える
void Particle::addForce(ofVec2f _force){
    force += _force;
}

// 力を更新
void Particle::updateForce(){
    force -= velocity * friction;
}

// 位置の更新
void Particle::updatePos(){
    velocity += force;
    position += velocity;
}

// 画面からはみ出たらバウンドさせる
void Particle::checkBounds(float xmin, float ymin, float xmax, float ymax){
    if (position.x < xmin || position.x > xmax) {
        velocity.x *= -1;
    }
    if (position.y < ymin || position.y > ymax) {
        velocity.y *= -1;
    }
}

// 位置を枠内に収める
void Particle::constrain(float xmin, float ymin, float xmax, float ymax){
    if (position.x < xmin) {
        position.x = xmin + (xmin - position.x);
    }
    if (position.x > xmax) {
        position.x = xmax - (position.x - xmax);
    }
    if (position.y < ymin) {
        position.y = ymin + (ymin - position.y);
    }
    if (position.y > ymax) {
        position.y = ymax - (position.y - ymax);
    }
}