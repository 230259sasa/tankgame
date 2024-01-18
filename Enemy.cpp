#include "Enemy.h"
#include"Engine\Model.h"
#include"Ground.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel_(-1),speed_(0)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Model\\Enemy.fbx");
	assert(hModel_ >= 0);

	float x = rand() % 28 - rand() % 28;
	float z = rand() % 28 - rand() % 28;

	transform_.position_.x = x;
	transform_.position_.z = z;

	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.6f);
	AddCollider(collision);
	Model::SetAnimFrame(hModel_, 1, 60, 1);
}

void Enemy::Update()
{
	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();
	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true) {
		transform_.position_.y = -data.dist + 0.5;
	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

	CollisionDraw();
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet")
	{
		this->KillMe();
		pTarget->KillMe();
	}
}
