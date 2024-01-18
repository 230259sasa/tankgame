#pragma once
#include "Engine\GameObject.h"
class Tank :
    public GameObject
{
    int hModel_;
    XMVECTOR front_;
    float speed_;
    int camState_;//カメラタイプの指定
public:
    Tank(GameObject* parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

