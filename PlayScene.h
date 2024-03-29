#pragma once
#include "Engine/GameObject.h"


const int ENEMY_NUM = 5;


class PlayScene :
    public GameObject
{
public:

	
	
	int hModel_;

	PlayScene(GameObject* parent);

	~PlayScene();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

