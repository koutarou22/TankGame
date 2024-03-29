#include "TitleScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include"Engine/Image.h"

TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene"), hImage_(-1)
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
	
	hImage_ = Image::Load("Title.jpg");
	assert(hImage_ >= 0);
}

//描画
void TitleScene::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

//開放
void TitleScene::Release()
{
}
