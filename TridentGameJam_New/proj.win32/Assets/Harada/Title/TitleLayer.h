/*
* �^�C�g�����C���[
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

	// �^�b�`�J�n
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	// �^�b�`�ړ�
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	// �^�b�`�I��
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	// �^�b�`�L�����Z��
	void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);
};

#endif