#pragma once

#include<cocos2d.h>
#include"../CollisionSystem/CSworld/CSWorld.h"
#include"Shibata/DebugDraw/DebugDraw.h"

class CollisionSystemDebugDraw:public cocos2d::Node
{
private:
	//! 参照するワールド
	CSWorld* m_pWorld;
public:
	CREATE_FUNC(CollisionSystemDebugDraw);

	CollisionSystemDebugDraw();

	~CollisionSystemDebugDraw();

	//! @brief 初期化
	bool init();
	
	//! @brief 更新処理
	void update(float dt);

	//! @brief ワールドセット
	void setCSWorld(CSWorld* pWorld);
};