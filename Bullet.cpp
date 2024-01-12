#include "Bullet.h"
#include"Engine\Model.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent,"Bullet"),hModel_(-1)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Model\\Bullet.fbx");
	assert(hModel_ >= 0);
}

void Bullet::Update()
{
	transform_.position_.x = transform_.position_.x + moveDir_.x * speed_;
	transform_.position_.y = transform_.position_.y + moveDir_.y * speed_;
	transform_.position_.z = transform_.position_.z + moveDir_.z * speed_;

	moveDir_.y -= 0.05;

	if (transform_.position_.y < -10) {
		KillMe();
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
