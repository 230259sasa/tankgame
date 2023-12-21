#include "Tank.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Debug.h"

Tank::Tank(GameObject* parent)
	:GameObject(parent, "Tank"), hModel_(-1)
{
}

void Tank::Initialize()
{
	hModel_ = Model::Load("Model\\tankbody.fbx");
	assert(hModel_ >= 0);
	front_ = { 0,0,1 };
	speed_ = 0.1;
}

void Tank::Update()
{
	if (Input::IsKey(DIK_A)) {
		transform_.rotate_.y += 1.0f;
	}
	if (Input::IsKey(DIK_D)) {
		transform_.rotate_.y -= 1.0f;
	}
	//âÒì]ÇµÇΩï˚å¸Ç…ëOêi
	Debug::Log("angle = ", true);
	Debug::Log(transform_.rotate_.y, true);
	if (Input::IsKey(DIK_W)) {
		XMMATRIX rotY = transform_.matRotate_;
		XMVECTOR rotvec = XMVector3TransformCoord(front_, rotY);
		XMVECTOR move;
		move = speed_ * rotvec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos + move;
		XMStoreFloat3(&(transform_.position_), pos);
	}
	if (Input::IsKey(DIK_S)) {
		XMMATRIX rotY = transform_.matRotate_;
		XMVECTOR rotvec = XMVector3TransformCoord(front_, rotY);
		XMVECTOR move;
		move = speed_ * rotvec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos - move;
		XMStoreFloat3(&(transform_.position_), pos);
	}
}

void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Tank::Release()
{
}
