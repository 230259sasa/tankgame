#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include <strstream>

class Tank;

class PlayScene :
    public GameObject
{
	int hPict_;
	Text* pText;
	Tank* player;
	//std::stringstream str;
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

