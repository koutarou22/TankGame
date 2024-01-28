#include "ClearScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include"Engine/Image.h"
//�R���X�g���N�^
ClearScene::ClearScene(GameObject* parent)
	: GameObject(parent, "ClearScene"), hImage_(-1)
{
}

//������
void ClearScene::Initialize()
{
}
//�X�V
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

//�`��
void ClearScene::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

//�J��
void ClearScene::Release()
{
}