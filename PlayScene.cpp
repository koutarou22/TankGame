#include "PlayScene.h"
#include"Ground.h"
#include"Tank.h"



PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"), hModel_(-1)
{
}

PlayScene::~PlayScene()
{

}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	Instantiate<Tank>(this);
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
	
}

void PlayScene::Release()
{
}
