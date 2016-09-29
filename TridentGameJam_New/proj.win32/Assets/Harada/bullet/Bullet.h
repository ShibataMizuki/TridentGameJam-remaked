/*
* 弾クラス
*/
#pragma once

#include<Shibata/GameObject/GameObject.h>
#include"cocos2d.h"


class Bullet : public GameObject
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

public:
	Bullet();
	~Bullet();

	virtual void update(float dt)override;
};

