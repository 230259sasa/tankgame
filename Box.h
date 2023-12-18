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

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

