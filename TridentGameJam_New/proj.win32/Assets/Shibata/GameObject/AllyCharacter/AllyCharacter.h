/*
味方キャラクターの定義
*/

#pragma once

#include"Shibata/GameObject/GameObject.h"

class AllyCharacter :public GameObject
{
	/*==============================
	GameObjectオーバライド
	===============================*/
public:
	bool init()override;
	virtual void update(float dt)override;

	/*==============================
	スプライトの管理
	===============================*/
public:
	void AllyCharacter::setSpriteAnimation(const std::string& filename);

	/*==============================
	HP/SPの管理
	===============================*/
protected:
	//! 現在HP/最大HP
	float m_currentHp, m_maxHp;
	//! 現在SP/最大HP
	float m_currentSp, m_maxSp;
public:
	//! @brief 現在HP setter/getter
	void setCurrentHp(float hp);
	float getCurrentHp()const;

	//! @brief 最大HP setter/getter
	void setMaxHp(float hp);
	float getMaxHp()const;

	//! @brief 現在SP setter/getter
	void setCurrentSp(float sp);
	float getCurrentSp()const;
	
	//! @brief 最大SP setter/getter
	void setMaxSp(float sp);
	float getMaxSp()const;

	//! @brief HPにダメージを与える
	void takeDamage(float damageValue);
	//! @brief HPを回復する
	void healHp(float healValue);
	//! @brief SPを使用する
	//! @return 使用SPが現在SPを超えていたらfalseを返す
	bool useSp(float useValue);
	//! @brief SPを回復する
	void healSp(float healValue);

	//! @brief 生存判定
	//! @return 生存しているならtrue,死亡しているならfalse
	bool isArrive()const;

	/*==============================
	行動管理
	===============================*/
protected:
	bool m_skillEnabled;
public:
	//! スキル有効化
	void enableSkill();
	//! スキル無効化
	void disableSkill();
	//! スキルが有効かどうか
	bool isSkillEnabled()const;
};