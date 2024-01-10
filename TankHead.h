#pragma once
#include "Engine/GameObject.h"
class TankHead :
    public GameObject
{
private:

	int hModel_;
	XMVECTOR front_;
	float speed_;

public:

	TankHead(GameObject* parent);
	~TankHead();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
	int GetModelHandle() { return( hModel_ ); }
};

