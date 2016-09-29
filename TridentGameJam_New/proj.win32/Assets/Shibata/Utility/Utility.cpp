#include "Utility.h"

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
