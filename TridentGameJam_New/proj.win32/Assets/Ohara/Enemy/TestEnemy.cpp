#include "TestEnemy.h"
#include "Ohara/Enemy/EnemyBullet/TestEnemyBullet.h"
bool TestEnemyCharacter::init()
{
	//! �e�N���X�̏������`�F�b�N������
	if (!EnemyCharacter::init())
	{
		return false;
	}
	scheduleUpdate();
	
	m_elapsedTime = 0.0f;
	m_Interval = 0.2f;

	srand((unsigned int)time(NULL));

	return true;
	
}

void TestEnemyCharacter::update(float dt)
{
	
	m_elapsedTime += dt;
	if (m_elapsedTime >= m_Interval)
	{
		
		switch (int randNum = rand() % 3)
		{
		case 1:
			progression();
			break;
		case 2:
			attack();
			break;
		default:
			break;
		}
	}
	//! syncBody��CSBody�ƃL�����̍��W�𓯊�������
	syncBody();

}

void TestEnemyCharacter::progression()
{
	
}

void TestEnemyCharacter::attack()
{
	auto bullet = TestEnemyBullet::create();
	bullet->setPosition(getParent()->convertToWorldSpace(getPosition()));
	getParent()->getParent()->addChild(bullet);
	m_elapsedTime = 0.0f;
}
