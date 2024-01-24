#include "HUD.h"
#include"Engine/Image.h"
#include <cassert>

HUD::HUD(GameObject* parent)
	:GameObject(parent,"HUD"),hHUD_(-1),hNumber_(-1)
{
}

void HUD::Initialize()
{
	hHUD_ = Image::Load("Count.png");
	assert(hHUD_ >= 0);
	hNumber_ = Image::Load("Number.png");
	assert(hHUD_ >= 0);

}

void HUD::Update()
{
	tHud_.scale_ = { 0.5,0.5,1.0 };
	tHud_.position_ = { -0.8,0.92,0 };//écÇËÅZÅZëÃ
}

void HUD::Draw()
{
	Image::SetTransform(hHUD_, tHud_);
	Image::Draw(hHUD_);

	Transform trans;
	trans.scale_ = { 0.5,0.5,1.0 };
	trans.position_ = { -0.79,0.91,0 };

	Image::SetRect(hNumber_, 51.2 *9, 0, 51.2, 99);
	Image::SetTransform(hNumber_, trans);
	Image::Draw(hNumber_);

	trans.position_ = { -0.76,0.91,0 };
	Image::SetRect(hNumber_, 51.2 * 6, 0, 51.2, 99);
	Image::SetTransform(hNumber_, trans);
	Image::Draw(hNumber_);
}

void HUD::Release()
{
}
