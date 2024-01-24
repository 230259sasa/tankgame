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
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	PlayScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

