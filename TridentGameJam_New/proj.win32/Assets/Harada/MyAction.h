/*
* 便利アクション
*/
#ifndef __MY_ACTION_H__
#define __MY_ACTION_H__

#include "cocos2d.h"

class MyAction :public cocos2d::Layer
{
public:
	// パーティクル(簡易)
	void SetParticle(cocos2d::Vec2 pos);

};

#endif // __MY_ACTION_H__