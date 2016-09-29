/*
* 背景レイヤー
*/
#ifndef __BACKGROUND_LAYER_H__
#define __BACKGROUND_LAYER_H__

#include"cocos2d.h"


class backgroundLayer :public cocos2d::Layer
{
private:
	// 背景
	cocos2d::Sprite* _background1;
	cocos2d::Sprite* _background2;


public:
	virtual bool init();
	CREATE_FUNC(backgroundLayer);

	void update(float dt);

	// タッチイベント
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);

};
#endif