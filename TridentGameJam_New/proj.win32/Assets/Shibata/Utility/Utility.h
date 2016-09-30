#pragma once

#include<cocos2d.h>
#include<vector>
#include"../CollisionSystem/CSVec2/CSVec2.h"

//! @brief CSVec2をcocos2d::Vec2に変換する
cocos2d::Vec2 toCocosVec2(const CSVec2& vec2);

//! @brief cocos2d::Vec2をCSVec2に変換する
CSVec2 toCSVec2(const cocos2d::Vec2& vec2);

//! @brief スプライトを分割する
//! @param pSprite 分割するスプライト
//! @param divX X方向の分割数
//! @param divY Y方向の分割数
//! @return 分割後の画像の配列
std::vector<cocos2d::SpriteFrame*> divideSprite(cocos2d::Sprite* pSprite, int divX, int divY);

//! @brief アニメーションを作成する
//! @param sprites 使用するスプライト群
//! @param indexes 使用する要素番号
//! @param delayPerUnit 次のスプライトに切り替わるまでの遅延時間
//! @param loops ループ回数
cocos2d::Animation* makeAnimation(std::vector<cocos2d::SpriteFrame*> sprites, std::vector<int> indexes, float delayPerUnit,int loops);