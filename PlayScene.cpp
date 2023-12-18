#include "PlayScene.h"
#include"Ground.h"
#include"Engine/Camera.h"
#include"TankObject.h"

PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	Instantiate<TankObject>(this);
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
