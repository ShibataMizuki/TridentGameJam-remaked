#include "AllyCharacter.h"
#include"Shibata/Defines.h"

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

	float width = CHARA_PIC_SIZE_W / (float)CHARA_PIC_DIV_X;
	float height = CHARA_PIC_SIZE_H / (float)CHARA_PIC_DIV_Y;

	auto origin = Sprite::create();
	addChild(origin);

	SpriteFrame* sprites[CHARA_PIC_DIV_X*CHARA_PIC_DIV_Y];

	int cnt = 0;

	for (int y = 0; y < CHARA_PIC_DIV_Y; y++)
	{
		for (int x = 0; x < CHARA_PIC_DIV_X; x++)
		{
			sprites[cnt]=SpriteFrame::create(filename, Rect(width*x, height*y, width,height));
			cnt++;
		}
	}

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

bool AllyCharacter::isSkillEnabled()const
{
	return m_skillEnabled;
}
