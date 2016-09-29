#include "EnemyCharacter.h"

bool EnemyCharacter::init()
{
	if (!GameObject::init())
		return false;
	return true;
}

void EnemyCharacter::setCurrentHp(float hp)
{
	m_currentHp = hp;
}

float EnemyCharacter::getCurrentHp() const
{
	return m_currentHp;
}

void EnemyCharacter::setMaxHp(float hp)
{
	m_maxHp = hp;
}

float EnemyCharacter::getMaxHp() const
{
	return m_maxHp;
}

void EnemyCharacter::takeDamage(float damageValue)
{
	if (damageValue < 0)
		return;
	m_currentHp -= damageValue;
}

void EnemyCharacter::healHp(float healValue)
{
	if (healValue < 0)
		return;
	m_currentHp += healValue;
	if (m_currentHp > m_maxHp)
		m_currentHp = m_maxHp;
}

bool EnemyCharacter::isArrive() const
{
	return m_currentHp > 0;
}
