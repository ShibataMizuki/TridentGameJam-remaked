/*
�����L�����N�^�[�̒�`
*/

#pragma once

#include"Shibata/GameObject/GameObject.h"

class AllyCharacter :public GameObject
{
	/*==============================
	GameObject�I�[�o���C�h
	===============================*/
public:
	bool init()override;
	virtual void update(float dt)override;

	/*==============================
	�X�v���C�g�̊Ǘ�
	===============================*/
public:
	void AllyCharacter::setSpriteAnimation(const std::string& filename);

	/*==============================
	HP/SP�̊Ǘ�
	===============================*/
protected:
	//! ����HP/�ő�HP
	float m_currentHp, m_maxHp;
	//! ����SP/�ő�HP
	float m_currentSp, m_maxSp;
public:
	//! @brief ����HP setter/getter
	void setCurrentHp(float hp);
	float getCurrentHp()const;

	//! @brief �ő�HP setter/getter
	void setMaxHp(float hp);
	float getMaxHp()const;

	//! @brief ����SP setter/getter
	void setCurrentSp(float sp);
	float getCurrentSp()const;
	
	//! @brief �ő�SP setter/getter
	void setMaxSp(float sp);
	float getMaxSp()const;

	//! @brief HP�Ƀ_���[�W��^����
	void takeDamage(float damageValue);
	//! @brief HP���񕜂���
	void healHp(float healValue);
	//! @brief SP���g�p����
	//! @return �g�pSP������SP�𒴂��Ă�����false��Ԃ�
	bool useSp(float useValue);
	//! @brief SP���񕜂���
	void healSp(float healValue);

	//! @brief ��������
	//! @return �������Ă���Ȃ�true,���S���Ă���Ȃ�false
	bool isArrive()const;

	/*==============================
	�s���Ǘ�
	===============================*/
protected:
	bool m_skillEnabled;
public:
	//! �X�L���L����
	void enableSkill();
	//! �X�L��������
	void disableSkill();
	//! �X�L�����L�����ǂ���
	bool isSkillEnabled()const;
};