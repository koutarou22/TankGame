#include "PlayScene.h"
#include"ClearScene.h"
#include"TitleScene.h"
#include"Ground.h"
#include"Tank.h"
#include"Bullet.h"
#include"Enemy.h"
#include"HUD.h"
#include "Engine/SceneManager.h"
//#include"TankHead.h"

//namespace
//{
//	const int ENEMY_NUM{ 10 };
//}


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

	/* pText = new Text;
	 pText->Initialize();*/

	 Instantiate<HUD>(this);
}

void PlayScene::Update()
{
	if (FindObject("Enemy") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
	
}

void PlayScene::Release()
{
}
