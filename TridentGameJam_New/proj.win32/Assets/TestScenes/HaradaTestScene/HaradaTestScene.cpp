#include "HaradaTestScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include"Harada\Temporary\Temporary.h"
#include"Harada\background\backgroundLayer.h"
USING_NS_CC;

Scene* HaradaTestScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Temporary::create();
	auto backlayer = backgroundLayer::create();
	// add layer as a child to scene
	scene->addChild(layer,2);
	scene->addChild(backlayer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HaradaTestScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}
