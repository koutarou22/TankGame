#include "TitleScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
//コンストラクタ
TitleScene::TitleScene(GameObject * parent)
	: GameObject(parent, "TitleScene")
{
}

//初期化
void TitleScene::Initialize()
{
}
//更新
void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
      SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	  pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
	
}

//描画
void TitleScene::Draw()
{
}

//開放
void TitleScene::Release()
{
}
