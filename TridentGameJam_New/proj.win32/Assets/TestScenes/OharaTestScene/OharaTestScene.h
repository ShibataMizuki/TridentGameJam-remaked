#pragma once

#include "cocos2d.h"
#include"Shibata/CollisionSystem/CollisionSystem.h"

class OharaTestScene : public cocos2d::Layer
{
private:
	CSWorld* m_pWorld;
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(OharaTestScene);
};
