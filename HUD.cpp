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
	tHub_.scale_.x = 0.2;
	tHub_.scale_.y = 0.1;
	tHub_.position_ = { -0.8,0.9,0 };
}

void HUD::Update()
{
}

void HUD::Draw()
{
	
	Image::SetTransform(hImage_, tHub_);
	Image::Draw(hImage_);
}

void HUD::Release()
{
}
