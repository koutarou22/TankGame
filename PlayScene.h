#pragma once
#include "Engine/GameObject.h"
class PlayScene :
    public GameObject
{
public:

	int hModel_;

	PlayScene(GameObject* parent);

	~PlayScene();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

