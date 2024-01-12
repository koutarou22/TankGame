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

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void SetMoveDir(XMFLOAT3 _move) { moveDir_ = _move; }
	void SetSpeed(float _speed) { Bullet_Speed_ = _speed; }
};

