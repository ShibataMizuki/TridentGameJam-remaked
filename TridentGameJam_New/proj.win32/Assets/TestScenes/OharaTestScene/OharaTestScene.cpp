#include "OharaTestScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
//! (optional) include CollisionSystemDebugDraw.h
#include"Shibata/CollisionSystemDebugDraw/CollisionSystemDebugDraw.h"

#include "Ohara/Enemy/TestEnemy.h"

USING_NS_CC;

Scene* OharaTestScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = OharaTestScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool OharaTestScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	m_pWorld = new CSWorld();

	DebugDraw::getInstance()->initialize(this);
	auto debugDraw = CollisionSystemDebugDraw::create();
	debugDraw->setCSWorld(m_pWorld);
	addChild(debugDraw);

	auto background = Sprite::create("Backgrounds/plain.jpg");
	background->setAnchorPoint(Vec2(0.f, 0.f));
	addChild(background);

	auto testEnemy = TestEnemyCharacter::create();
	auto body = CSBody::createShared();
	body->addShape(CSCircle::createShared(50.0f));
	m_pWorld->addBody(body);
	testEnemy->setBody(body);
	addChild(testEnemy);
	this->scheduleUpdate();
	return true;
}

