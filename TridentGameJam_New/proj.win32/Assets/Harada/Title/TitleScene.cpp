/*
* タイトルシーン
*/

#include <Harada/Title/TitleScene.h>
#include <Harada/Title/TitleLayer.h>
#include <Harada/background/backgroundLayer.h>

USING_NS_CC;


bool TitleScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto Titlelayer = TitleLayer::create();
	auto backgroundlayer = backgroundLayer::create();

	this->addChild(backgroundlayer);
	this->addChild(Titlelayer);

	return true;
}