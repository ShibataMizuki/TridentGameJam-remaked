/*
* îwåiÉåÉCÉÑÅ[
*/
#include <Harada/background/backgroundLayer.h>

using namespace std;

USING_NS_CC;


bool backgroundLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	// âÊñ ÉTÉCÉYéÊìæ
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// îwåi1ÇâÊñ ç∂í[Ç…çáÇÌÇπÇƒê›íu
	_background1 = Sprite::create("Backgrounds/plain.jpg");
	_background1->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	_background1->setPosition(Vec2(0, 0));
	this->addChild(_background1);
	// îwåi2Çîwåi1ÇÃâEó◊Ç…ê›íu
	_background2 = Sprite::create("Backgrounds/plain.jpg");
	_background2->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	_background2->setPosition(Vec2(_background1->getContentSize().width, 0));
	this->addChild(_background2);

	// çXêV
	scheduleUpdate();
	return true;
}

void backgroundLayer::update(float dt)
{
	// îwåiÇñàÉtÉåÅ[ÉÄ3pxç∂Ç…ÉXÉNÉçÅ[Éã
	_background1->setPositionX(_background1->getPositionX() - 3);
	_background2->setPositionX(_background2->getPositionX() - 3);

	if (_background2->getPositionX() < 0) 
	{
		// îwåi1Ç™âÊñ ç∂äOÇ…èoÇ´Ç¡ÇΩèÍçáÅAîwåi1Çîwåi2ÇÃâEó◊Ç…à⁄Ç∑
		_background1->setPositionX(_background2->getPositionX() + _background2->getContentSize().width);

		// îwåi1Ç∆2ÇÃïœêîÇì¸ÇÍë÷Ç¶ÇÈ
		auto s = _background2;
		_background2 = _background1;
		_background1 = s;
	}

}

bool backgroundLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// É^ÉbÉ`ç¿ïWÇéÊìæ
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