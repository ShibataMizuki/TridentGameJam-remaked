/*
* タイトルレイヤー
*/

#ifndef __TITLE_LAYER_H__
#define __TITLE_LAYER_H__

# include"cocos2d.h"

class TitleLayer :public cocos2d::Layer
{
private:


public:
	virtual bool init();
	CREATE_FUNC(TitleLayer);

	void update(float dt);

	// タッチ開始
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	// タッチ移動
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	// タッチ終了
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	// タッチキャンセル
	void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);
};

#endif