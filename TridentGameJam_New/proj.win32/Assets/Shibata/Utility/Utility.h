#pragma once

#include<cocos2d.h>
#include<vector>
#include"../CollisionSystem/CSVec2/CSVec2.h"

//! @brief CSVec2��cocos2d::Vec2�ɕϊ�����
cocos2d::Vec2 toCocosVec2(const CSVec2& vec2);

//! @brief cocos2d::Vec2��CSVec2�ɕϊ�����
CSVec2 toCSVec2(const cocos2d::Vec2& vec2);

//! @brief �X�v���C�g�𕪊�����
//! @param pSprite ��������X�v���C�g
//! @param divX X�����̕�����
//! @param divY Y�����̕�����
//! @return ������̉摜�̔z��
std::vector<cocos2d::SpriteFrame*> divideSprite(cocos2d::Sprite* pSprite, int divX, int divY);