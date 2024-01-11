#pragma once
#include "Engine\\GameObject.h"
class TankHead :
    public GameObject
{
    int hModel_;
    bool isdown_;
public:
    TankHead(GameObject* parent);
    ~TankHead();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    /// <summary>
    /// モデル番号を返す
    /// </summary>
    /// <returns>int hModel_;モデル番号</returns>
    int GetModelHandle() { return hModel_; }
};

