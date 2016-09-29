/*
�p�[�e�B�̒�`
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
	Node�I�[�o�[���C�h
	===============================*/
public:
	bool init()override;
	void update(float dt)override;
	CREATE_FUNC(Party);

	/*==============================
	�����o�[�̊Ǘ�
	===============================*/
private:
	//! �p�[�e�B�����o�[
	AllyCharacter* m_partyMembers[(uint)PartyIndex::Max];
	//! �p�[�e�B�����o�[�̑��΍��W
	cocos2d::Vec2 m_partyMemberPositions[(uint)PartyIndex::Max];

public:
	//! @brief �p�[�e�B�����o�[��ݒ肷��
	//! @param ally �ݒ肷��p�[�e�B�����o�[
	//! @param index �p�[�e�B�����o�[�ԍ�
	//! @param pos ���W
	void setPartyMember(AllyCharacter* ally, PartyIndex index);

	//! @brief �p�[�e�B�����o�[���擾����
	//! @param index �ς�����
	AllyCharacter* getPartyMember(PartyIndex index);

	//! @brief �p�[�e�B�����o�[���O��
	//! @param index �p�[�e�B�����o�[�ԍ�
	void removePartyMember(PartyIndex index);

	/*==============================
	�w�`
	===============================*/
public:
	cocos2d::Vec2 m_formationData[(uint)PartyIndex::Max];
private:
public:
	//! @brief �����ɐw�`��ύX����
	void changeFormationInstantly();

	/*==============================
	�ړ��p
	===============================*/
private:
	cocos2d::Vec2 m_oldPos;
public:
	bool onTouchBegin(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
};