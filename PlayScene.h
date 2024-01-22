#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include <sstream>
#include<vector>

class Tank;
class Enemy;

class PlayScene :
    public GameObject
{
	int hImage_;
	Text* pText;
	Tank* player;
	std::vector<Enemy*> enemy;
	std::stringstream str;
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

