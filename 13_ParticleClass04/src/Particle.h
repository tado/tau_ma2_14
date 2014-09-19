#pragma once // インクルードガード（コンパイルの際に一度しか読みこまれないように）
#include "ofMain.h" // openFrameworksの機能を使えるように

class Particle {
    
public: // 外部に公開する領域
    
    // ------- Method（手続）---------------------------------------------
    
    // 更新
    void update();
    // 描画
    void draw();
    // 初期設定
    void setInit(ofVec2f initPos);
    // 力をリセット
    void resetForce();
    // 力を加える
    void addForce(ofVec2f force);
    // 力を更新
    void updateForce();
    // 位置の更新
    void updatePos();
    // 画面からはみ出たらバウンドさせる
    void checkBounds(float xmin, float ymin, float xmax, float ymax);
    // 位置を枠内に収める
    void constrain(float xmin, float ymin, float xmax, float ymax);
    
    
    // ------- Property（属性）--------------------------------------------

    // 位置ベクトルの配列
    ofVec2f position;
    // 速度ベクトルの配列
    ofVec2f velocity;
    // 力ベクトルの配列
    ofVec2f force;
    // 摩擦係数
    float friction;
    // 重力
    ofVec2f gravity;
};