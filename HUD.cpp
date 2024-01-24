#include "HUD.h"
#include"Engine\Image.h"

namespace HS = HUDSetting;

HUD::HUD(GameObject* parent)
	:GameObject(parent,"HUD"),hImage_(-1),hNumber_(-1)
{
}

void HUD::Initialize()
{
	hImage_ = Image::Load("Image\\tekinoyatu.png");
	assert(hImage_ >= 0);
	tHub_.scale_.x = 0.2;
	tHub_.scale_.y = 0.1;
	tHub_.position_ = { -0.8,0.9,1.0 };

	hNumber_ = Image::Load("char88.png");
	assert(hNumber_ >= 0);
	tNumbers[0].position_ = { -0.65,0.9,1.0 };
	tNumbers[1].position_ = { -0.7,0.9,1.0 };
}

void HUD::Update()
{
}

void HUD::Draw()
{
	Image::SetTransform(hImage_, tHub_);
	Image::Draw(hImage_);

	Image::SetRect(hNumber_, HS::NWidth * (num_ /  10) , 0, HS::NWidth, HS::NHeight);
	Image::SetTransform(hNumber_,tNumbers[0]);
	Image::Draw(hNumber_);

	Image::SetRect(hNumber_, HS::NWidth * (num_ / 10 ), 0, HS::NWidth, HS::NHeight);
	Image::SetTransform(hNumber_, tNumbers[1]);
	Image::Draw(hNumber_);
}

void HUD::Release()
{
}
