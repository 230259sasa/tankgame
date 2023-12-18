#include "PlayScene.h"
#include"Ground.h"
#include"Engine/Camera.h"
#include"Tank.h"

PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	Instantiate<Tank>(this);

	//Camera::SetPosition();
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
