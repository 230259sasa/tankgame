#pragma once
#include "Engine/GameObject.h"
class TankObject :
    public GameObject
{
    int hModelBody_;
    int hModel_;
public:
    TankObject(GameObject* parent);

    //‰Šú‰»
    void Initialize() override;

    //XV
    void Update() override;

    //•`‰æ
    void Draw() override;

    //ŠJ•ú
    void Release() override;
};

