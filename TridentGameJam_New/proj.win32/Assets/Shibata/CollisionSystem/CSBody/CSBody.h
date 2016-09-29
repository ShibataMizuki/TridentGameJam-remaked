#pragma once

#include<list>
#include<memory>
#include<string>
#include"../CSShape/CSShape.h"

class CSBody
{
	/*==============================
	�R���X�g���N�^
	===============================*/
public:
	CSBody();

	/*==============================
	���W�̊Ǘ�
	===============================*/
protected:
	CSVec2 m_pos;
public:
	//! ���W��ݒ�
	void setPosition(const CSVec2& pos);
	//! ���W���擾
	const CSVec2& getPosition()const;

	/*==============================
	�p�x�̊Ǘ�
	===============================*/
protected:
	float m_angle;
public:
	//! �p�x��ݒ�
	void setAngle(float angle);
	//! �p�x���擾
	float getAngle()const;

	/*==============================
	�}�`���X�g�̊Ǘ�
	===============================*/
protected:
	std::list<std::shared_ptr<CSShape>> m_shapeList;
public:
	//! �}�`����ǉ�
	void addShape(const std::shared_ptr<CSShape>& pShape);
	//! �}�`���X�g���擾
	const std::list<std::shared_ptr<CSShape>>& getShapeList()const;
	//! �}�`���X�g�̐擪�C�e���[�^���擾
	std::list<std::shared_ptr<CSShape>>::iterator getShapeBegin();
	//! �}�`���X�g�̖����C�e���[�^���擾
	std::list<std::shared_ptr<CSShape>>::iterator getShapeEnd();

	/*==============================
	�Փ˃O���[�v�̊Ǘ�
	===============================*/
protected:
	int m_collisionGroup;
public:
	//! �Փ˃O���[�v��ݒ�
	void setCollisionGroup(int group);
	//! �Փ˃O���[�v���擾
	int getCollisionGroup()const;

	/*==============================
	�^�O�̊Ǘ�
	===============================*/
protected:
	std::string m_tag;
public:
	//! �^�O��ݒ�
	void setTag(const std::string& tag);
	//! �^�O���擾
	std::string getTag()const;

	/*==============================
	���[�U�[�f�[�^�̊Ǘ�
	===============================*/
protected:
	void* m_pUserData;
public:
	//! ���[�U�[�f�[�^��ݒ�
	void setUserData(void* pUserData);
	//! ���[�U�[�f�[�^���擾
	void* getUserData()const;
	//! �L���X�g�ς݂̃��[�U�[�f�[�^���擾
	template<class T>
	T* getCastedUserData()const;

	////////////////////////////////////////
public:
	//! �X�}�[�g�|�C���^�쐬
	static std::shared_ptr<CSBody> createShared(const CSVec2& pos);
	static std::shared_ptr<CSBody> createShared();

	//! AABB
	AABB m_aabb;
	//! @brief AABB���擾
	const AABB& getAABB()const;
};

template<class T>
inline T * CSBody::getCastedUserData() const
{
	return static_cast<T*>(m_pUserData);
}
