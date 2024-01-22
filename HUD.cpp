#include "HUD.h"
#include"Engine\Image.h"

HUD::HUD(GameObject* parent)
	:GameObject(parent,"HUD"),hImage_(-1)
{
}

void HUD::Initialize()
{
	hImage_ = Image::Load("Image\\tekinoyatu.png");
	assert(hImage_ >= 0);
}

void HUD::Update()
{
}

void HUD::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

void HUD::Release()
{
}
