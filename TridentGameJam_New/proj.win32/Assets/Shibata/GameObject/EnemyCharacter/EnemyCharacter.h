#pragma once

#include"Shibata/GameObject/GameObject.h"

class EnemyCharacter :public GameObject
{
	/*==============================
	�Q�[���I�u�W�F�N�g�I�[�o�[���C�h
	===============================*/
public:
	bool init()override;

	/*==============================
	HP/SP�̊Ǘ�
	===============================*/
protected:
	//! ����HP/�ő�HP
	float m_currentHp, m_maxHp;
public:
	//! @brief ����HP setter/getter
	void setCurrentHp(float hp);
	float getCurrentHp()const;

	//! @brief �ő�HP setter/getter
	void setMaxHp(float hp);
	float getMaxHp()const;

	//! @brief HP�Ƀ_���[�W��^����
	void takeDamage(float damageValue);
	//! @brief HP���񕜂���
	void healHp(float healValue);

	//! @brief ��������
	//! @return �������Ă���Ȃ�true,���S���Ă���Ȃ�false
	bool isArrive()const;

};