#pragma once
#include "Engine/GameObject.h"
class PlayScene :
    public GameObject
{
public:

	int hModel_;

	PlayScene(GameObject* parent);

	~PlayScene();

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
};

