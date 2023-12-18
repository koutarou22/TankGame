#include "Tank.h"
#include"Engine/Model.h"
#include"Engine/Input.h"

Tank::Tank(GameObject* parent)
	:GameObject(parent,"Tank"),hModel_(-1)
{

}

void Tank::Initialize()
{
	hModel_ = Model::Load("Model\\Tankbody.fbx");
	assert(hModel_ >= 0);
}

void Tank::Update()
{
	if (Input::IsKey(DIK_D))
	{
		transform_.rotate_.y += 1.0f;
	}
	if (Input::IsKey(DIK_A))
	{
		transform_.rotate_.y -= 1.0f;
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
