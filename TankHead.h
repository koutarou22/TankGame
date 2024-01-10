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

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
	int GetModelHandle() { return( hModel_ ); }
};

