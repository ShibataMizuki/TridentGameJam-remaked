/*
* 背景レイヤー
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
	// 画面サイズ取得
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// 背景1を画面左端に合わせて設置
	_background1 = Sprite::create("Backgrounds/plain.jpg");
	_background1->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	_background1->setPosition(Vec2(0, 0));
	this->addChild(_background1);
	// 背景2を背景1の右隣に設置
	_background2 = Sprite::create("Backgrounds/plain.jpg");
	_background2->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	_background2->setPosition(Vec2(_background1->getContentSize().width, 0));
	this->addChild(_background2);

	// 更新
	scheduleUpdate();
	return true;
}

void backgroundLayer::update(float dt)
{
	// 背景を毎フレーム3px左にスクロール
	_background1->setPositionX(_background1->getPositionX() - 2);
	_background2->setPositionX(_background2->getPositionX() - 2);

	if (_background2->getPositionX() < 0) 
	{
		// 背景1が画面左外に出きった場合、背景1を背景2の右隣に移す
		_background1->setPositionX(_background2->getPositionX() + _background2->getContentSize().width);

		// 背景1と2の変数を入れ替える
		auto s = _background2;
		_background2 = _background1;
		_background1 = s;
	}

}

bool backgroundLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// タッチ座標を取得
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