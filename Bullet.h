#pragma once
#include "Engine\GameObject.h"
class Bullet :
    public GameObject
{
    int hModel_;
    XMFLOAT3 moveDir_;
    float speed_;
public:
    Bullet(GameObject* parent);

    ~Bullet();
    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void SetMoveDir(XMFLOAT3 _move) { moveDir_ = _move; }
    void SetSpeed(float _speed) { speed_ = _speed; }
};

