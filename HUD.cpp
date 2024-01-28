#include "HUD.h"
#include "Enemy.h"
#include"PlayScene.h"
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

	EnemyCount_ = ENEMY_NUM;

}

void HUD::Update()
{
	tHud_.scale_ = { 0.5,0.5,1.0 };
	tHud_.position_ = { -0.8,0.92,0 };//Žc‚èZZ‘Ì
}

void HUD::Draw()
{
	Image::SetTransform(hHUD_, tHud_);
	Image::Draw(hHUD_);

	Transform trans;
	trans.scale_ = { 0.5,0.5,1.0 };
	trans.position_ = { -0.79,0.91,0 };

	float ImageWidth = 51.2f;
	float spriteX1 = ImageWidth * (EnemyCount_ % 10);

	
	Image::SetRect(hNumber_, spriteX1, 0, ImageWidth, 85);
	Image::SetTransform(hNumber_, trans);
	Image::Draw(hNumber_);

	
	if (EnemyCount_ >= 10) {
		trans.position_ = { -0.76,0.91,0 };
		float spriteX2 = ImageWidth * (EnemyCount_ / 10);  

	
		Image::SetRect(hNumber_, spriteX2, 0, ImageWidth, 85);
		Image::SetTransform(hNumber_, trans);
		Image::Draw(hNumber_);
	}
}



void HUD::Release()
{
}

void HUD::EnemyDeleteCount()
{
	--EnemyCount_;

	NumberUpdete();
}

void HUD::NumberUpdete()
{
	float ImageWidth = 51.2f; 
	float Image1 = ImageWidth * (EnemyCount_ % 10);  
	float Image2 = ImageWidth * (EnemyCount_ / 10); 

	
	Image::SetRect(hNumber_, Image1, 0, ImageWidth, 85);

	

	if (EnemyCount_ >= 10) {
		Image::SetRect(hNumber_, Image2, 0, ImageWidth, 85);
	}
}


