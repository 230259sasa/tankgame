#pragma once
#include "Engine\GameObject.h"
class HUD :
    public GameObject
{
    int hImage_;
    Transform tHub_;
public:
    HUD(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

