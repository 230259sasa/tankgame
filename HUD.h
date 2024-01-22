#pragma once
#include "Engine\GameObject.h"
class HUD :
    public GameObject
{
    int hImage_;
public:
    HUD(GameObject* parent);

    //‰Šú‰»
    void Initialize() override;

    //XV
    void Update() override;

    //•`‰æ
    void Draw() override;

    //ŠJ•ú
    void Release() override;
};

