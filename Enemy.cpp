#include "Enemy.h"
#include "Ground.h"
#include "Engine/Model.h"
#include"Engine/Collider.h"


Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel_(-1)
{

}

void Enemy::Initialize()
{
	

	hModel_ = Model::Load("Model\\kinoko.fbx");
	assert(hModel_ >= 0);

	Model::SetAnimFrame(hModel_, 0, 60, 1);
	float x = (float)rand() / RAND_MAX;

	x = 2.0 * x;
	transform_.position_.x = 25.0 * (x - 1.0);
	float z = (float)rand() / RAND_MAX;
	z = 2.0 * z;
	transform_.position_.z = 25.0 * (z - 1.0);
	transform_.position_.y = 0;

	SphereCollider* collision = new SphereCollider({ 0, 0, 0 }, 1.0f);
	AddCollider(collision);

	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();
	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true)
	{
		transform_.position_.y = -data.dist + 0.5;
	}

	
}

void Enemy::Update()
{
	XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	XMVECTOR rotVec = XMVector3TransformCoord(front_,rotY);

	XMVECTOR move;
	move = speed_ * rotVec;
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	pos = pos - move;
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
		transform_.position_.y = -data.dist + 0.5;
	}

	transform_.rotate_.x - 4.0f;
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet") {
		this->KillMe();
		pTarget->KillMe();
	}
}
