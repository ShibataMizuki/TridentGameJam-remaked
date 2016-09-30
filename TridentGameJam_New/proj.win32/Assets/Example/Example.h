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
	virtual bool init(/*param*/);

	//! @brief 更新
	void update(float dt)override;

	//CREATE_FUNC(Example);

	static Example* create(/*param*/)
	{
		Example* pRet = new(std::nothrow) Example();
		if (pRet&&pRet->init(/*param*/))
		{
			pRet->autorelease();
			return pRet;
		}
		else
		{
			delete pRet;
			pRet = nullptr;
			return nullptr;
		}
	}
};