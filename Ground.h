#pragma once
#include "Engine/GameObject.h"

class Ground :
    public GameObject
{
    int hModel_;

public:

	Ground(GameObject* parent);

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
       
};

