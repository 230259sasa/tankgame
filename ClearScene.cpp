#include "ClearScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include"Engine/Image.h"

ClearScene::ClearScene(GameObject* parent)
	: GameObject(parent, "ClearScene"), hImage_(-1)
{
}

void ClearScene::Initialize()
{
	hImage_ = Image::Load("Image\\Clear.jpg");
	assert(hImage_ >= 0);
}

void ClearScene::Update()
{
	if (Input::IsKeyDown(DIK_F)) {
		SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
		pSM->ChangeScene(SCENE_ID_PLAY);
	}
}

void ClearScene::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

void ClearScene::Release()
{
}
