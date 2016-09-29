#pragma once

#include<cocos2d.h>
#include"Shibata/CollisionSystem/CollisionSystem.h"

// ボタン用
#include "ui/CocosGUI.h"

class Temporary :public cocos2d::Layer
{
private:
	CSWorld* m_pWorld;
public:
	//! @brief シーン作成
	static cocos2d::Scene* createScene();

	//! @brief 初期化
	virtual bool init();

	//! @brief 更新
	void update(float dt)override;

	// ========================================================== //
	// ボタン
	void ButtonEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);

	// タッチ開始
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	// タッチ移動
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	// タッチ終了
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	// タッチキャンセル
	void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);
	// ========================================================== //


	CREATE_FUNC(Temporary);
};