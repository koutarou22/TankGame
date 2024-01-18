#include "PlayScene.h"
#include"Ground.h"
#include"Tank.h"
#include"Bullet.h"
#include"Enemy.h"
//#include"TankHead.h"



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

		Instantiate<Enemy>(this) ->SetPosition(5, 0, 21);
		Instantiate<Enemy>(this)->SetPosition(-5, 0, 17);
		Instantiate<Enemy>(this)->SetPosition(9, 0, 13);
		Instantiate<Enemy>(this)->SetPosition(0, 0, 9);
		Instantiate<Enemy>(this)->SetPosition(-11, 0, 9);
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
