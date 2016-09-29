#pragma once

#include"Shibata/GameObject/GameObject.h"

class EnemyCharacter :public GameObject
{
	/*==============================
	ゲームオブジェクトオーバーライド
	===============================*/
public:
	bool init()override;

	/*==============================
	HP/SPの管理
	===============================*/
protected:
	//! 現在HP/最大HP
	float m_currentHp, m_maxHp;
public:
	//! @brief 現在HP setter/getter
	void setCurrentHp(float hp);
	float getCurrentHp()const;

	//! @brief 最大HP setter/getter
	void setMaxHp(float hp);
	float getMaxHp()const;

	//! @brief HPにダメージを与える
	void takeDamage(float damageValue);
	//! @brief HPを回復する
	void healHp(float healValue);

	//! @brief 生存判定
	//! @return 生存しているならtrue,死亡しているならfalse
	bool isArrive()const;

};