#pragma once

#include"Shibata/GameObject/GameObject.h"

class EnemyObject :public GameObject
{
	/*==============================
	�Q�[���I�u�W�F�N�g�I�[�o�[���C�h
	===============================*/
private:
	bool init()override;
	void update(float dt)override;

public:
};