#include "TankHead.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

TankHead::TankHead(GameObject* parent)
	:GameObject(parent,"TankHead"),hModel_(-1)
{
	
}

TankHead::~TankHead()
{
}

void TankHead::Initialize()
{
	hModel_ = Model::Load("Model\\TankHead.fbx");
	assert(hModel_ >= 0);
}

void TankHead::Update()
{
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.rotate_.y += 1.0f;
	}
	if (Input::IsKey(DIK_LEFT))
	{
		transform_.rotate_.y -= 1.0f;
	}
}

void TankHead::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankHead::Release()
{
}
