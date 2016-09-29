#include "AllyCharacter.h"
#include"Shibata/Defines.h"
#include"Shibata/Utility/Utility.h"

USING_NS_CC;

bool AllyCharacter::init()
{
	if (!GameObject::init())return false;
	scheduleUpdate();
	return true;
}

void AllyCharacter::update(float dt)
{
}


void AllyCharacter::setSpriteAnimation(const std::string& filename)
{
	auto animation = Animation::create();
	auto origin = Sprite::create();
	addChild(origin);

	int cnt = 0;

	auto sprites = divideSprite(Sprite::create(filename), CHARA_PIC_DIV_X, CHARA_PIC_DIV_Y);

	animation->addSpriteFrame(sprites[6]);
	animation->addSpriteFrame(sprites[7]);
	animation->addSpriteFrame(sprites[8]);
	animation->setDelayPerUnit(0.1f);

	auto animate = Animate::create(animation);
	auto repeat = RepeatForever::create(animate);
	origin->runAction(repeat);
}


void AllyCharacter::setCurrentHp(float hp)
{
	m_currentHp = hp;
}

float AllyCharacter::getCurrentHp() const
{
	return m_currentHp;
}

void AllyCharacter::setMaxHp(float hp)
{
	m_maxHp = hp;
}

float AllyCharacter::getMaxHp()const
{
	return m_maxHp;
}

void AllyCharacter::setCurrentSp(float sp)
{
	m_currentSp = sp;
}

float AllyCharacter::getCurrentSp() const
{
	return m_currentSp;
}

void AllyCharacter::setMaxSp(float sp)
{
	m_maxSp = sp;
}

float AllyCharacter::getMaxSp() const
{
	return m_maxSp;
}

void AllyCharacter::takeDamage(float damageValue)
{
	if (damageValue < 0)
		return;
	m_currentHp -= damageValue;
}

void AllyCharacter::healHp(float healValue)
{
	if (healValue < 0)
		return;
	m_currentHp += healValue;
	if (m_currentHp > m_maxHp)
		m_currentHp = m_maxHp;
}

bool AllyCharacter::useSp(float useValue)
{
	if (useValue > m_currentSp)
		return false;
	m_currentSp -= useValue;
	return true;
}

void AllyCharacter::healSp(float healValue)
{
	if (healValue < 0)
		return;
	m_currentSp += healValue;
	if (m_currentSp > m_maxSp)
		m_currentSp = m_maxSp;
}

bool AllyCharacter::isArrive() const
{
	return m_currentHp <= 0.0;
}

void AllyCharacter::enableSkill()
{
	m_skillEnabled = true;
}

void AllyCharacter::disableSkill()
{
	m_skillEnabled = false;
}

bool AllyCharacter::isSkillEnabled()const
{
	return m_skillEnabled;
}
