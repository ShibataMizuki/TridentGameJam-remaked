#pragma once

#include<cocos2d.h>
#include"../CollisionSystem/CSworld/CSWorld.h"
#include"Shibata/DebugDraw/DebugDraw.h"

class CollisionSystemDebugDraw:public cocos2d::Node
{
private:
	//! �Q�Ƃ��郏�[���h
	CSWorld* m_pWorld;
public:
	CREATE_FUNC(CollisionSystemDebugDraw);

	CollisionSystemDebugDraw();

	~CollisionSystemDebugDraw();

	//! @brief ������
	bool init();
	
	//! @brief �X�V����
	void update(float dt);

	//! @brief ���[���h�Z�b�g
	void setCSWorld(CSWorld* pWorld);
};