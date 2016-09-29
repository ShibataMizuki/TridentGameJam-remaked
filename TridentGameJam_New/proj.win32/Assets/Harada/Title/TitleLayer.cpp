/*
* �^�C�g�����C���[
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
	

	// �C�x���g���X�i�[�쐬
	auto Listener = EventListenerTouchOneByOne::create();
	// ���X�i�[�ɐݒ�
	Listener->onTouchBegan = CC_CALLBACK_2(TitleLayer::onTouchBegan, this);
	Listener->onTouchMoved = CC_CALLBACK_2(TitleLayer::onTouchMoved, this);
	Listener->onTouchEnded = CC_CALLBACK_2(TitleLayer::onTouchEnded, this);
	Listener->onTouchCancelled = CC_CALLBACK_2(TitleLayer::onTouchCancelled, this);
	// �C�x���g�f�B�X�p�b�`���[
	auto eventDispatcher = this->getEventDispatcher();
	// �C�x���g���X�i�[�ǉ�
	eventDispatcher->addEventListenerWithSceneGraphPriority(Listener, this);


	scheduleUpdate();
	return true;
}

void TitleLayer::update(float dt)
{

}

bool TitleLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// �^�b�`���W�擾
	Vec2 touchPos = touch->getLocation();

	return true;
}

void TitleLayer::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{

}

void TitleLayer::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// �A�b�v�f�[�g���~�߂�
	this->unscheduleUpdate();
	/*auto nextScene = ::create();
	Director::getInstance()->replaceScene(TransitionPageTurn::create(2.0f ,nextScene,0));*/
}

void TitleLayer::onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event)
{

}