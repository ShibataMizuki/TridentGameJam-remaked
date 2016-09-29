/*
パーティの定義
*/
#pragma once

using uint = unsigned int;

#include"Shibata/GameObject/AllyCharacter/AllyCharacter.h"

enum class PartyIndex : uint
{
	_1, _2, _3, _4, 
	Max,
};

enum class FormationIndex :uint
{
	_1, _2, _3, _4,
	Max
};

class Party :public cocos2d::Node
{
	/*==============================
	Nodeオーバーライド
	===============================*/
public:
	bool init()override;
	void update(float dt)override;
	CREATE_FUNC(Party);

	/*==============================
	メンバーの管理
	===============================*/
private:
	//! パーティメンバー
	AllyCharacter* m_partyMembers[(uint)PartyIndex::Max];
	//! パーティメンバーの相対座標
	cocos2d::Vec2 m_partyMemberPositions[(uint)PartyIndex::Max];

public:
	//! @brief パーティメンバーを設定する
	//! @param ally 設定するパーティメンバー
	//! @param index パーティメンバー番号
	//! @param pos 座標
	void setPartyMember(AllyCharacter* ally, PartyIndex index);

	//! @brief パーティメンバーを取得する
	//! @param index ぱｒｔｙ
	AllyCharacter* getPartyMember(PartyIndex index);

	//! @brief パーティメンバーを外す
	//! @param index パーティメンバー番号
	void removePartyMember(PartyIndex index);

	/*==============================
	陣形
	===============================*/
public:
	cocos2d::Vec2 m_formationData[(uint)PartyIndex::Max];
private:
public:
	//! @brief 即座に陣形を変更する
	void changeFormationInstantly();

	/*==============================
	移動用
	===============================*/
private:
	cocos2d::Vec2 m_oldPos;
public:
	bool onTouchBegin(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
};