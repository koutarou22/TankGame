#pragma once
#include "Engine/GameObject.h"
class Enemy :
    public GameObject
{
	int hModel_;
	XMVECTOR front_;
	float speed_;
public:
	Enemy(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void OnCollision(GameObject* pTarget) override;
};

