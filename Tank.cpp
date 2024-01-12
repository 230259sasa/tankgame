#include "Tank.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Debug.h"
#include"Ground.h"
#include"TankHead.h"

Tank::Tank(GameObject* parent)
	:GameObject(parent, "Tank"), hModel_(-1), front_({ 0,0,1 }),speed_(0.1)
{
}

void Tank::Initialize()
{
	hModel_ = Model::Load("Model\\TankBody.fbx");
	assert(hModel_ >= 0);
	front_ = { 0,0,1 };
	speed_ = 0.1;

	Instantiate<TankHead>(this);
}

void Tank::Update()
{
	if (Input::IsKey(DIK_A)) {
		transform_.rotate_.y -= 1.0f;
	}
	if (Input::IsKey(DIK_D)) {
		transform_.rotate_.y += 1.0f;
	}
	//‰ñ“]‚µ‚½•ûŒü‚É‘Oi
	//Debug::Log("angle = ", true);
	//Debug::Log(transform_.rotate_.y, true);
	if (Input::IsKey(DIK_W)) {
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));//radian Šp“xH
		XMVECTOR rotvec = XMVector3TransformCoord(front_, rotY);
		XMVECTOR move = speed_ * rotvec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos + move;
		XMStoreFloat3(&(transform_.position_), pos);
	}
	if (Input::IsKey(DIK_S)) {
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		XMVECTOR rotvec = XMVector3TransformCoord(front_, rotY);
		XMVECTOR move = speed_ * rotvec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos - move;
		XMStoreFloat3(&(transform_.position_), pos);
	}
	
	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();
	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true) {
		transform_.position_.y = -data.dist;
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
