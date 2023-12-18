#include "TankObject.h"
#include"Engine/Model.h"

TankObject::TankObject(GameObject* parent)
	:GameObject(parent, "Tank"), hModel_(-1),hModelBody_(-1)
{
}

void TankObject::Initialize()
{
	hModelBody_ = Model::Load("Model\\tankbody.fbx");
	assert(hModelBody_ >= 0);
	hModel_ = Model::Load("Model\\tank.fbx");
	assert(hModel_ >= 0);
}

void TankObject::Update()
{
}

void TankObject::Draw()
{
	Transform f = transform_;
	f.position_.y += 0.2;
	Model::SetTransform(hModelBody_, transform_);
	Model::SetTransform(hModel_, f);
	Model::Draw(hModelBody_);
	Model::Draw(hModel_);
}

void TankObject::Release()
{
}
