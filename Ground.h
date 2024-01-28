#pragma once
#include "Engine/GameObject.h"

class Ground :
    public GameObject
{
    int hModel_;

public:

	Ground(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	/// <summary>
	/// ���f���ԍ���Ԃ��֐�
	/// </summary>
	/// <returns>���f���ԍ�</returns>
	int GetModelHandle() { return(hModel_); }

	void EnemyCount();
       
};

