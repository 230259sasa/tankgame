#pragma once
#include "Engine\GameObject.h"

namespace HUDSetting {
    const int NWidth(256 / 10);
    const int NHeight(35 / 1);
}



class HUD :
    public GameObject
{
    int hImage_;
    int hNumber_;
    Transform tHub_;
    Transform tNumbers[2];
    int num_;
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
    void SetEnemyNum(int _num) { num_ = _num; }
};

