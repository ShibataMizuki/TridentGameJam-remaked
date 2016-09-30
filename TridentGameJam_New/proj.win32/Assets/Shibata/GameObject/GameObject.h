/*
�Q�[���I�u�W�F�N�g�̒�`
*/

#pragma once

#include<cocos2d.h>
#include"../CollisionSystem/CollisionSystem.h"

enum class ObjectGroup
{
	AllyCharacter,
	EnemyCharacter,
	AllyBullet,
	EnemyBullet,
	DropItem,
};

//! @brief �Q�[���ɏo������I�u�W�F�N�g�̊��
class GameObject :public cocos2d::Node
{
	/*==============================
	cocos2d-x
	===============================*/
public:
	//! @brief ����������
	virtual bool init();

	/*==============================
	�����蔻��p
	===============================*/
protected:
	//! �{�f�B
	std::shared_ptr<CSBody> m_pBody;
public:
	//! @brief �{�f�B��ݒ�
	void setBody(const std::shared_ptr<CSBody>& pBody);
	//! @brief �{�f�B���擾
	const std::shared_ptr<CSBody>& getBody()const;
	//! @brief �{�f�B��Ǐ]������
	void syncBody();

	/*==============================
	�X�v���C�g�A�j���[�V�����̊Ǘ�
	===============================*/
protected:
	//! �X�v���C�g
	cocos2d::Sprite* m_pSprite;
public:
	//! @brief �X�v���C�g���擾
	cocos2d::Sprite* getSprite()const;

	//! @brief �A�j���[�V���������s
	//! @param ���s����A�j���[�V����
	void runAnimation(cocos2d::Animation* pAnimation);
	

	/*==============================
	�R���X�g���N�^/�f�X�g���N�^
	===============================*/
public:
	virtual ~GameObject() = default;
};