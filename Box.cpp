#include "Box.h"
#include"Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Image.h"

Box::Box(GameObject* parent)
	:GameObject(parent,"Box"),hModel_(-1)
{
}

Box::~Box()
{
}

void Box::Initialize()
{
	hModel_ = Model::Load("Model\\box.fbx");
	assert(hModel_ >= 0);//hModel‚ª0–¢–ž‚È‚çƒGƒ‰[
	transform_.position_ = { 0.0f,0.0f,0.0f };
	hImage_ = Image::Load("Image\\hamuhamu.png");
	assert(hImage_ >= 0);
}

void Box::Update()
{
	/*if (Input::IsKey(DIK_LEFT))
	{
		transform_.rotate_.y++;
		transform_.position_.x-=0.01;
	}
	
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.rotate_.y--;
		transform_.position_.x += 0.01;
	}*/
}

void Box::Draw()
{
	/*Transform itr;
	itr.position_ = { 0,0,0 };
	itr.scale_ = { 1,1,1 };

	Image::SetTransform(hImage_, itr);
	Image::Draw(hImage_);

	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);*/
}

void Box::Release()
{
}
