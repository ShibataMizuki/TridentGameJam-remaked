#include "JussiTestScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include <Jussi/MessageSystem/MessageSystem.h>

USING_NS_CC;

Scene* JussiTestScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = JussiTestScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool JussiTestScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//Create layers
	auto messageSystem = MessageSystem::create(MessageType::YESNO, "Test");

	//Add layers as a child
	//add background
	this->addChild(messageSystem);

	return true;
}
