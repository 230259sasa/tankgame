#pragma once
#include "Engine/GameObject.h"
class Ground :
    public GameObject
{
    int hModel_;
public:
    Ground(GameObject* parent);

    ~Ground();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};
