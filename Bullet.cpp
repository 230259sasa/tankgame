#include "Bullet.h"
#include"Engine\Model.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent,"Bullet"),hModel_(-1),speed_(0)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Model\\Bullet.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,0 };
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.5f);
	AddCollider(collision);
}

void Bullet::Update()
{
	transform_.position_.x += moveDir_.x * speed_;
	transform_.position_.y += moveDir_.y * speed_;
	transform_.position_.z += moveDir_.z * speed_;

	moveDir_.y -= 0.03f;

	if (transform_.position_.y < -3) {
		KillMe();
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

	CollisionDraw();
}

void Bullet::Release()
{
}
