#pragma once
#include "Engine\GameObject.h"

namespace HUDSetting {
    const int NWidth(256 / 10);
    const int NHeight(70 / 1);
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

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
    void SetEnemyNum(int _num) { num_ = _num; }
};

