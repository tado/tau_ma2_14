#include "Spring.h"

//---------------------------------------------------------------------
Spring::Spring(){
    // 初期化、最初はばねを空(NULL)に
	particleA = NULL;
	particleB = NULL;
}

//---------------------------------------------------------------------
void Spring::update(){
    // もし両端にParticleが設定されていない場合、何もしない
	if ((particleA == NULL) || (particleB == NULL)){
		return;
	}
    // 両端のParticleの位置を取得
	ofVec2f pta = particleA->position;
	ofVec2f ptb = particleB->position;
    // 距離を算出
	float theirDistance = (pta - ptb).length();
    // 距離からばねにかかる力を計算（フックの法則）
	float springForce = (springiness * (distance - theirDistance));
    // ばねの力から、両端への力ベクトルを計算
	ofVec2f frcToAdd = (pta-ptb).normalized() * springForce;
    // それぞれのParticleに力を加える
	particleA->addForce(ofVec2f(frcToAdd.x, frcToAdd.y));
	particleB->addForce(ofVec2f(-frcToAdd.x, -frcToAdd.y));
}

//---------------------------------------------------------------------
void Spring::draw(){
    // もし両端にParticleが設定されていない場合、何もしない
	if ((particleA == NULL) || (particleB == NULL)){
		return;
	}
    // ばねを描画
	ofLine(particleA->position.x, particleA->position.y, particleB->position.x, particleB->position.y);
}