#include "PlayScene.h"
#include"Ground.h"
#include"Engine/Camera.h"
#include"Tank.h"
#include"TankHead.h"
#include"Enemy.h"
#include"Engine\Image.h"

namespace {
	const int ENEMY_NUM{ 30 };
}

PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene"), hPict_(-1), pText(nullptr)
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	player = Instantiate<Tank>(this);
	Instantiate<Enemy>(this);
	//Instantiate<TankHead>(this);
	//Camera::SetPosition();

	for (int i = 0; i < ENEMY_NUM; i++) {
		Instantiate<Enemy>(this);
	}

	hPict_ = Image::Load("char.png");
	assert(hPict_ >= 0);

	pText = new Text;
	pText->Initialize();
}

void PlayScene::Update()
{
	Camera::SetTarget(player->GetPosition());
	XMFLOAT3 camPos = player->GetPosition();
	camPos.y += 8;
	camPos.z -= 15;
	Camera::SetPosition(camPos);

	//Image::SetRect(hPict_, 50, 100, 256, );
	//Enemy”‚¦‚é
	//if (FindObject("Enemy") != nullptr)
}

void PlayScene::Draw()
{
	pText->Draw(30, 30, "Enemy:");

	//pText->Draw(125, 30, str);
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void PlayScene::Release()
{
}
