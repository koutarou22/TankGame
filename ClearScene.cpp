#include "ClearScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include"Engine/Image.h"
//コンストラクタ
ClearScene::ClearScene(GameObject* parent)
	: GameObject(parent, "ClearScene"), hImage_(-1)
{
}

//初期化
void ClearScene::Initialize()
{
}
//更新
void ClearScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}

	hImage_ = Image::Load("Clear.jpg");
	assert(hImage_ >= 0);
}

//描画
void ClearScene::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

//開放
void ClearScene::Release()
{
}