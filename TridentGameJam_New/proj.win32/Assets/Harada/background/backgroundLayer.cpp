/*
* �w�i���C���[
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
	// ��ʃT�C�Y�擾
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// �w�i1����ʍ��[�ɍ��킹�Đݒu
	_background1 = Sprite::create("Backgrounds/plain.jpg");
	_background1->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	_background1->setPosition(Vec2(0, 0));
	this->addChild(_background1);
	// �w�i2��w�i1�̉E�ׂɐݒu
	_background2 = Sprite::create("Backgrounds/plain.jpg");
	_background2->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	_background2->setPosition(Vec2(_background1->getContentSize().width, 0));
	this->addChild(_background2);

	// �X�V
	scheduleUpdate();
	return true;
}

void backgroundLayer::update(float dt)
{
	// �w�i�𖈃t���[��3px���ɃX�N���[��
	_background1->setPositionX(_background1->getPositionX() - 3);
	_background2->setPositionX(_background2->getPositionX() - 3);

	if (_background2->getPositionX() < 0) 
	{
		// �w�i1����ʍ��O�ɏo�������ꍇ�A�w�i1��w�i2�̉E�ׂɈڂ�
		_background1->setPositionX(_background2->getPositionX() + _background2->getContentSize().width);

		// �w�i1��2�̕ϐ������ւ���
		auto s = _background2;
		_background2 = _background1;
		_background1 = s;
	}

}

bool backgroundLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// �^�b�`���W���擾
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