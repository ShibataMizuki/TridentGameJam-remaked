#pragma once

#include"../CSVec2/CSVec2.h"
#include"AABB/AABB.h"

class CSShape
{
protected:
	//! ���W
	CSVec2 m_position;
	//! AABB
	AABB m_aabb;

public:
	/*==============================
	�R���X�g���N�^�E�f�X�g���N�^
	===============================*/
	CSShape() = default;
	CSShape(const CSVec2& pos);
	virtual ~CSShape() = default;

	/*==============================
	���W�̊Ǘ�
	===============================*/
	//! ���W��ݒ�
	void setPosition(const CSVec2& pos);
	//! ���W���擾
	const CSVec2& getPosition()const;

	//! @brief �}�`������AABB���擾
	//! @return AABB
	const AABB& getAABB()const;
};