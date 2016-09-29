/*
* ”wŒiƒŒƒCƒ„[
*/
#include "backgroundLayer.h"

using namespace std;

USING_NS_CC;


bool backgroundLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	// ‰æ–ÊƒTƒCƒYŽæ“¾
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// ”wŒi1‚ð‰æ–Ê¶’[‚É‡‚í‚¹‚ÄÝ’u
	_background1 = Sprite::create("background.png");
	_background1->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	_background1->setPosition(Vec2(0, 0));
	this->addChild(_background1);
	// ”wŒi2‚ð”wŒi1‚Ì‰E—×‚ÉÝ’u
	_background2 = Sprite::create("background.png");
	_background2->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	_background2->setPosition(Vec2(_background1->getContentSize().width, 0));
	this->addChild(_background2);

	// XV
	scheduleUpdate();
	return true;
}

void backgroundLayer::update(float dt)
{
	// ”wŒi‚ð–ˆƒtƒŒ[ƒ€3px¶‚ÉƒXƒNƒ[ƒ‹
	_background1->setPositionX(_background1->getPositionX() - 3);
	_background2->setPositionX(_background2->getPositionX() - 3);

	if (_background2->getPositionX() < 0) 
	{
		// ”wŒi1‚ª‰æ–Ê¶ŠO‚Éo‚«‚Á‚½ê‡A”wŒi1‚ð”wŒi2‚Ì‰E—×‚ÉˆÚ‚·
		_background1->setPositionX(_background2->getPositionX() + _background2->getContentSize().width);

		// ”wŒi1‚Æ2‚Ì•Ï”‚ð“ü‚ê‘Ö‚¦‚é
		auto s = _background2;
		_background2 = _background1;
		_background1 = s;
	}

}

bool backgroundLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// ƒ^ƒbƒ`À•W‚ðŽæ“¾
	Vec2 touchPos = touch->getLocation();

	return true;
}

void backgroundLayer::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{

}

void backgroundLayer::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{

}

void backgroundLayer::onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event)
{

}