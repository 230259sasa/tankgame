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

    //‰Šú‰»
    void Initialize() override;

    //XV
    void Update() override;

    //•`‰æ
    void Draw() override;

    //ŠJ•ú
    void Release() override;
};

