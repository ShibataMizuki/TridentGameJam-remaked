#pragma once
#include "Shibata\GameObject\EnemyCharacter\EnemyCharacter.h"

class TestEnemyCharacter : public EnemyCharacter
{
private:

	float m_elapsedTime;

	float m_Interval;

public:
	
	bool init()override;

	void update(float dt)override;

	void  progression();

	void attack();

	CREATE_FUNC(TestEnemyCharacter);
};