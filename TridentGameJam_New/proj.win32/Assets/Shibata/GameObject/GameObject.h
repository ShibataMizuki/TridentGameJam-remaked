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
	�R���X�g���N�^/�f�X�g���N�^
	===============================*/
public:
	virtual ~GameObject() = default;
};