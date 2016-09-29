#pragma once

#include"Shibata/GameObject/GameObject.h"

class EnemyObject :public GameObject
{
	/*==============================
	ゲームオブジェクトオーバーライド
	===============================*/
private:
	bool init()override;
	void update(float dt)override;

public:
};