#pragma once
#include "Engine/GameObject.h"
class Box :
    public GameObject
{
    int hModel_;
    int hImage_;
public:
    Box(GameObject* parent);

    ~Box();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

