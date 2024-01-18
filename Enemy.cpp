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
	hModel_ = Model::Load("Model\\Enemy.fbx");
	assert(hModel_ >= 0);

	SphereCollider* collision = new SphereCollider({ 0, 0, 0 }, 1.0f);
	AddCollider(collision);
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
		transform_.position_.y = -data.dist;
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
