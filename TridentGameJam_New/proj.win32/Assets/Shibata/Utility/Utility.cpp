#include "Utility.h"

USING_NS_CC;
using namespace std;

cocos2d::Vec2 toCocosVec2(const CSVec2 & vec2)
{
	cocos2d::Vec2 ret(vec2.x, vec2.y);
	return std::move(ret);
}

CSVec2 toCSVec2(const cocos2d::Vec2 & vec2)
{
	CSVec2 ret(vec2.x, vec2.y);
	return std::move(ret);
}

std::vector<cocos2d::SpriteFrame*> divideSprite(cocos2d::Sprite * pSprite, int divX, int divY)
{
	vector<SpriteFrame*> ret;

	auto contentSize = pSprite->getContentSize();
	float width = contentSize.width / divX;
	float height = contentSize.height / divY;

	for (int y = 0; y < divY; y++)
	{
		for (int x = 0; x < divX; x++)
		{
			ret.push_back(SpriteFrame::createWithTexture(
				pSprite->getTexture(), Rect(width*x, height*y, width, height)));
		}
	}

	return move(ret);
}

cocos2d::Animation * makeAnimation(std::vector<cocos2d::SpriteFrame*> sprites, std::vector<int> indexes, float delayPerUnit,int loops)
{
	Animation* pAnimation = Animation::create();
	for (auto index : indexes)
	{
		pAnimation->addSpriteFrame(sprites[index]);
	}
	pAnimation->setDelayPerUnit(delayPerUnit);
	pAnimation->setLoops(loops);
	return pAnimation;
}
