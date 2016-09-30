#pragma once

#include<cocos2d.h>
#include"Shibata/CollisionSystem/CollisionSystem.h"
#include"Shibata/Party/Party.h"


// �{�^���p
#include "ui/CocosGUI.h"

class Temporary :public cocos2d::Layer
{
private:
	CSWorld* m_pWorld;
	// ========================================================== //
	// SP�o�[
	cocos2d::Sprite* m_SPbar[4];
	// HP�o�[
	cocos2d::Sprite* m_HPbar[4];
	// �{�^��
	cocos2d::ui::Button* m_button[4];
	// ========================================================== //

public:
	//! @brief �V�[���쐬
	static cocos2d::Scene* createScene();

	//! @brief ������
	virtual bool init();

	//! @brief �X�V
	void update(float dt)override;

	// ========================================================== //
	// �p�[�e�B
	Party* g_party;

	// �{�^��
	void ButtonEvent1(Ref *pSender, cocos2d::ui::Widget::TouchEventType type );
	void ButtonEvent2(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);

	// �^�b�`�J�n
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	// �^�b�`�ړ�
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	// �^�b�`�I��
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	// �^�b�`�L�����Z��
	void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);
	// ========================================================== //


	CREATE_FUNC(Temporary);
};