#pragma once
#include "Engine/GameObject.h"
class Bullet :
	public GameObject
{

	int hModel_;
	float Bullet_Speed_;
	XMFLOAT3 moveDir_;

public:

	Bullet(GameObject* parent);
	~Bullet();

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;

	void SetMoveDir(XMFLOAT3 _move) { moveDir_ = _move; }
	void SetSpeed(float _speed) { Bullet_Speed_ = _speed; }
};

