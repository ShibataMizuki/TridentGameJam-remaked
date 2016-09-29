/*
* タイトルシーン
*/

#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include"cocos2d.h"


class TitleScene :public cocos2d::Scene
{
private:

public:
	virtual bool init();

	CREATE_FUNC(TitleScene);
};

#endif  //__TITLE_SCENE_H__