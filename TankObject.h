#pragma once
#include "Engine/GameObject.h"
class TankObject :
    public GameObject
{
    int hModelBody_;
    int hModel_;
public:
    TankObject(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

