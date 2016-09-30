#include "Example.h"

//! 1. include CollisionSystem.h
#include"Shibata/CollisionSystem/CollisionSystem.h"

//! (optional) include CollisionSystemDebugDraw.h
#include"Shibata/CollisionSystemDebugDraw/CollisionSystemDebugDraw.h"
#include"Shibata/GameObject/AllyCharacter/AllyCharacter.h"
#include"Shibata/Party/Party.h"
#include"Shibata/Utility/Utility.h"

USING_NS_CC;


cocos2d::Scene * Example::createScene()
{
	auto scene = Scene::create();
	auto layer = Example::create();
	scene->addChild(layer);
	return scene;
}

bool Example::init()
{

	if (!Layer::init())return false;

}

void Example::update(float dt)
{
}
