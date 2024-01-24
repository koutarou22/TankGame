#pragma once
#include "Engine/GameObject.h"
#include<vector>
#include <string>

using std::string;

class HUD :
    public GameObject
{
	string CountructEnemyNumberString();
public:

	HUD(GameObject* parent);
	int hHUD_;
	int hNumber_;

	Transform tHud_;

	std::vector<Transform> tNumbers_;

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

