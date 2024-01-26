#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"
#include "Engine/Camera.h"
#include "Ground.h"
#include "TankHead.h"

enum CAM_TYPE
{
	FIXED_TYPE,
	TPS_NOROT_TYPE,
	TPS_TYPE,
	FPS_TYPE,
	MAX_TYPE //番兵(チェック用)
};

Tank::Tank(GameObject* parent)
	:GameObject(parent, "Tank"), hModel_(-1), front_({ 0,0,1,0 }), speed_(0.05f),camState_(CAM_TYPE::FIXED_TYPE)
{

}

void Tank::Initialize()
{
	hModel_ = Model::Load("Model\\Tankbody.fbx");
	assert(hModel_ >= 0);

	Instantiate<TankHead>(this);
}

void Tank::Update()
{
	XMMATRIX rotY = XMMatrixIdentity();
	XMVECTOR move{0,0,0,0};
	XMVECTOR rotVec{0,0,0,0};

	float dir = 0;


	if (Input::IsKey(DIK_D))
	{
		transform_.rotate_.y += 1.0f;
	}
	if (Input::IsKey(DIK_A))
	{
		transform_.rotate_.y -= 1.0f;
	}

	if (Input::IsKey(DIK_W))
	{
	/* rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		 rotVec = XMVector3TransformCoord(front_, rotY);

		XMVECTOR move;
		move = speed_ * rotVec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos + move;
		XMStoreFloat3(&(transform_.position_), pos);*/

		dir += 2.0;

	}
	if (Input::IsKey(DIK_S))
	{
	/*	XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		XMVECTOR rotVec = XMVector3TransformCoord(front_, rotY);*/

		dir -= 2.0;
	
	}

	rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	rotVec = XMVector3TransformCoord(front_, rotY);

	move = speed_ * rotVec;
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	pos = pos + dir * move;
	XMStoreFloat3(&(transform_.position_), pos);

	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();

	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true)
	{
		transform_.position_.y = -data.dist + 0.5f;
	}

	if (Input::IsKeyDown(DIK_Z))
	{
		camState_++;
		if (camState_ == CAM_TYPE::MAX_TYPE)
			camState_ == CAM_TYPE::FIXED_TYPE;
	}

	switch (camState_)
	{

	 case CAM_TYPE::FIXED_TYPE:
	 {
		 Camera::SetPosition(XMFLOAT3(0, 25, -20));
		 Camera::SetTarget(XMFLOAT3(0, 0, 0));
		 break;
	 } 
	 
	 case CAM_TYPE::TPS_NOROT_TYPE:
	 {
		 XMFLOAT3 camPos = transform_.position_;
		 camPos.y = transform_.position_.y + 15.0f;
		 camPos.z = transform_.position_.z - 10.0f;
		 Camera::SetPosition(camPos);
		 Camera::SetTarget(transform_.position_);
		 break;

	 }
	 case CAM_TYPE::TPS_TYPE:
	 {
		 Camera::SetTarget(transform_.position_);
		 XMVECTOR vEve{ 0,5,-10,0 };
		 vEve = XMVector3TransformCoord(vEve, rotY);
		 XMFLOAT3 camPos;
		 XMStoreFloat3(&camPos, pos + vEve);
		 Camera::SetPosition(camPos);
		 
		 break;
	 }
	
	 case CAM_TYPE::FPS_TYPE:
	 {
		 Camera::SetPosition(transform_.position_);
		 XMFLOAT3 camTarget;

		 XMStoreFloat3(&camTarget, pos + move);
		 Camera::SetTarget(camTarget);
		 break;
	 }
	default:
		break;
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
