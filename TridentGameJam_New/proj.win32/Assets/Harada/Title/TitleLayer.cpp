/*
* タイトルレイヤー
*/

#include <Harada/Title/TitleLayer.h>
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

USING_NS_CC;


bool TitleLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	

	// イベントリスナー作成
	auto Listener = EventListenerTouchOneByOne::create();
	// リスナーに設定
	Listener->onTouchBegan = CC_CALLBACK_2(TitleLayer::onTouchBegan, this);
	Listener->onTouchMoved = CC_CALLBACK_2(TitleLayer::onTouchMoved, this);
	Listener->onTouchEnded = CC_CALLBACK_2(TitleLayer::onTouchEnded, this);
	Listener->onTouchCancelled = CC_CALLBACK_2(TitleLayer::onTouchCancelled, this);
	// イベントディスパッチャー
	auto eventDispatcher = this->getEventDispatcher();
	// イベントリスナー追加
	eventDispatcher->addEventListenerWithSceneGraphPriority(Listener, this);


	scheduleUpdate();
	return true;
}

void TitleLayer::update(float dt)
{

}

bool TitleLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// タッチ座標取得
	Vec2 touchPos = touch->getLocation();

	return true;
}

void TitleLayer::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{

}

void TitleLayer::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// アップデートを止める
	this->unscheduleUpdate();
	/*auto nextScene = ::create();
	Director::getInstance()->replaceScene(TransitionPageTurn::create(2.0f ,nextScene,0));*/
}

void TitleLayer::onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event)
{

}