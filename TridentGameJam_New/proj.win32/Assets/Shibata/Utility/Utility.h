#pragma once

#include<cocos2d.h>
#include"../CollisionSystem/CSVec2/CSVec2.h"

cocos2d::Vec2 toCocosVec2(const CSVec2& vec2);
CSVec2 toCSVec2(const cocos2d::Vec2& vec2);