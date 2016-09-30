#pragma once
#include <Shibata/GameObject/GameObject.h>
#include "cocos2d.h"

class TestEnemyBullet : public GameObject
{
private:
	// オブジェクト
	GameObject* m_obj;
	// スプライト
	cocos2d::Sprite* m_sprite;
	// サイズ
	float m_rad;
	// タイプ
	int m_type;
	// ポジション
	CSVec2 m_pos;
	// スピード
	CSVec2 m_spd;

public :
	TestEnemyBullet();
	~TestEnemyBullet();

	virtual void update(float dt)override;
};