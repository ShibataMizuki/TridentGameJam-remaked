#pragma once

#include<cocos2d.h>
#include"Shibata/CollisionSystem/CollisionSystem.h"

class Example :public cocos2d::Layer
{
private:
	CSWorld* m_pWorld;
public:
	//! @brief シーン作成
	static cocos2d::Scene* createScene();

	//! @brief 初期化
	virtual bool init();

	//! @brief 更新
	void update(float dt)override;

	CREATE_FUNC(Example);
};