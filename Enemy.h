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

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;

	void OnCollision(GameObject* pTarget) override;
};

