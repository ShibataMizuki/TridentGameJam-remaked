#pragma once

#include<cocos2d.h>
#include"Shibata/CollisionSystem/CollisionSystem.h"

class Temporary :public cocos2d::Layer
{
private:
	CSWorld* m_pWorld;
public:
	//! @brief �V�[���쐬
	static cocos2d::Scene* createScene();

	//! @brief ������
	virtual bool init();

	//! @brief �X�V
	void update(float dt)override;

	// ========================================================== //
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