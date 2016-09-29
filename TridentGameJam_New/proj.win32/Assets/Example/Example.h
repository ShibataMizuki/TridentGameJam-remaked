#pragma once

#include<cocos2d.h>
#include"Shibata/CollisionSystem/CollisionSystem.h"

class Example :public cocos2d::Layer
{
private:
	CSWorld* m_pWorld;
public:
	//! @brief �V�[���쐬
	static cocos2d::Scene* createScene();

	//! @brief ������
	virtual bool init();

	//! @brief �X�V
	void update(float dt)override;

	CREATE_FUNC(Example);
};