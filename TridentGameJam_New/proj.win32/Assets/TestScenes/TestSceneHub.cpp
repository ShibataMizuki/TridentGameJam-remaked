#include "TestSceneHub.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include"ShibataTestScene/ShibataTestScene.h"
#include"JussiTestScene/JussiTestScene.h"
#include"HaradaTestScene/HaradaTestScene.h"
#include"OharaTestScene/OharaTestScene.h"

USING_NS_CC;
using namespace std;

Scene* TestSceneHub::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = TestSceneHub::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool TestSceneHub::init()
{
	if (!Layer::init())
	{
		return false;
	}

	tuple<function<void(cocos2d::Ref*, cocos2d::ui::Widget::TouchEventType)>, string, Vec2> gate[4];

	get<0>(gate[0]) = [](Ref* sender, ui::Widget::TouchEventType type) 
	{if(type==ui::Widget::TouchEventType::ENDED)Director::getInstance()->pushScene(ShibataTestScene::createScene()); };
	get<0>(gate[1]) = [](Ref* sender, ui::Widget::TouchEventType type) 
	{if (type == ui::Widget::TouchEventType::ENDED)Director::getInstance()->pushScene(JussiTestScene::createScene()); };
	get<0>(gate[2]) = [](Ref* sender, ui::Widget::TouchEventType type) 
	{if (type == ui::Widget::TouchEventType::ENDED)Director::getInstance()->pushScene(HaradaTestScene::createScene()); };
	get<0>(gate[3]) = [](Ref* sender, ui::Widget::TouchEventType type)
	{if (type == ui::Widget::TouchEventType::ENDED)Director::getInstance()->pushScene(OharaTestScene::createScene()); };
	get<1>(gate[0]) = "GOTO ShibataTestScene";get<1>(gate[1]) = "GOTO JussiTestScene";
	get<1>(gate[2]) = "GOTO HaradaTestScene";get<1>(gate[3]) = "GOTO OharaTestScene";
	get<2>(gate[0]) = Vec2(150.f, 150.f);get<2>(gate[1]) = Vec2(600.f, 150.f);
	get<2>(gate[2]) = Vec2(150.f, 500.f);get<2>(gate[3]) = Vec2(600.f, 500.f);

	for (int f1 = 0; f1 < 4; f1++)
	{
		auto button = ui::Button::create("TestScene/doge1.jpg");
		button->addTouchEventListener(get<0>(gate[f1]));
		button->setScale(0.7f);
		button->setPosition(get<2>(gate[f1]));
		auto label = Label::createWithSystemFont(get<1>(gate[f1]), "Arial", 32);
		label->setAnchorPoint(Vec2(0.f, 0.f));
		label->setPosition(0.f, -32.f);
		button->addChild(label);
		addChild(button);
	}
	return true;
}
