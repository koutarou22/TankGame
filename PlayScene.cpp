#include "PlayScene.h"
#include"Ground.h"
#include"Tank.h"
#include"Bullet.h"
#include"Enemy.h"
//#include"TankHead.h"

namespace
{
	const int ENEMY_NUM{ 30 };
}


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
	//Instantiate<TankHead>(this);
	//Instantiate<Bullet>(this);
	/*Instantiate<Enemy>(this);*/

	 int enmyNum = ENEMY_NUM;

	 for (int i = 0; i < enmyNum; i++)
		 Instantiate<Enemy>(this);
	
	 pText
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
