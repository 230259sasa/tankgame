#include "PlayScene.h"
#include"Ground.h"
#include"Engine/Camera.h"
#include"Tank.h"
#include"TankHead.h"
#include"Enemy.h"
#include"Engine\Image.h"
#include"HUD.h"
#include "Engine/SceneManager.h"

namespace {
	const int ENEMY_NUM{ 30 };
}

PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	player = Instantiate<Tank>(this);
	//Instantiate<Enemy>(this);
	//Instantiate<TankHead>(this);
	//Camera::SetPosition();

	for (int i = 0; i < ENEMY_NUM; i++) {
		Enemy* e;
		e = Instantiate<Enemy>(this);
		enemy.push_back(e);
	}

	phud = Instantiate<HUD>(this);
}

void PlayScene::Update()
{
	/*Camera::SetTarget(player->GetPosition());
	XMFLOAT3 camPos = player->GetPosition();
	camPos.y += 8;
	camPos.z -= 15;
	Camera::SetPosition(camPos);*/

	//Image::SetRect(hPict_, 50, 100, 256, );
	//EnemyêîÇ¶ÇÈ
	eCount_ = 0;
	for (int i = 0; i < enemy.size(); i++) {
		if (!enemy[i]->IsDead()) {
			eCount_++;
		}
	}

	phud->SetEnemyNum(eCount_);
	if (eCount_ <= 0) {
		SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
		pSM->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
