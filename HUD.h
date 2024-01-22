#pragma once
#include "Engine\GameObject.h"
class HUD :
    public GameObject
{
    int hImage_;
public:
    HUD(GameObject* parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

