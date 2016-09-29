#pragma once

#include"../../CSVec2/CSVec2.h"

//! @brief AABB�N���X
class AABB
{
	/*==============================
	���S���W
	===============================*/
private:
	CSVec2 m_centerPos;
	CSVec2 m_centerPosOrigin;
public:
	//! @brief ���S���W�̎擾
	//! @return ���S���W
	const CSVec2& getCenterPosition()const;
	
	//! @brief ���S���W�̐ݒ�
	//! @param centerPos ���S���W
	void setCenterPosition(const CSVec2& centerPos);

	//! @brief ���Ƃ��Ƃ̒��S���W���擾����
	const CSVec2& getCenterPositionOrigin()const;

	/*==============================
	��,����
	===============================*/
private:
	float m_width;
	float m_height;
public:
	//! @brief ���̎擾
	//! @return ��
	float getWidth()const;

	//! @brief �����̎擾
	//! @return ����
	float getHeight()const;

	//! @brief ���̐ݒ�
	//! @param width ��
	void setWidth(float width);

	//! @brief �����̐ݒ�
	//! @param height ����
	void setHeight(float height);

	/*==============================
	�ŏ����W,�ő���W
	===============================*/
private:
	CSVec2 m_upper;
	CSVec2 m_lower;
public:
	//! @brief �ő���W�̎擾
	//! @return �ő���W
	const CSVec2& getUpper()const;

	//! @brief �ŏ����W�̎擾
	//! @return �ŏ����W
	const CSVec2& getLower()const;

	/*==============================
	�R���X�g���N�^,�f�X�g���N�^
	===============================*/
public:
	AABB() = default;

	//! @param centerPos ���S���W
	//! @param width ��
	//! @param height ����
	AABB(const CSVec2& centerPos, float width, float height);

	//! @param lower �ŏ����W
	//! @param upper �ő���W
	AABB(const CSVec2& lower, const CSVec2& upper);

	~AABB() = default;

	/*==============================
	���̑��֐�
	===============================*/
public:
	//! @brief AABB��AABB�̐ڐG����
	//! @param aabb AABB
	bool isIntersect(const AABB& aabb)const;

	void dump()const;
};