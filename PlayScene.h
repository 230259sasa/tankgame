#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include <sstream>
#include<vector>

class Tank;
class Enemy;
class HUD;

class PlayScene :
    public GameObject
{
	Tank* player;
	HUD* phud;
	std::vector<Enemy*> enemy;
	int eCount_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	PlayScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

