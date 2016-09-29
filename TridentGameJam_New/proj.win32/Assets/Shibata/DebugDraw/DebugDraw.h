#pragma once

#include<cocos2d.h>
#include"../CollisionSystem/CSworld/CSWorld.h"
#include"../CollisionSystem/CSShape/AABB/AABB.h"

class DebugDraw
{
	/*==============================
	�V���O���g��
	===============================*/
private:
	static DebugDraw* m_pInstance;

	//! �R���X�g���N�^����
	DebugDraw() = default;
	~DebugDraw() = default;
	DebugDraw(DebugDraw&) = delete;
	DebugDraw(DebugDraw&&) = delete;
	DebugDraw& operator+(const DebugDraw&) = delete;

public:
	//! @brief �C���X�^���X���擾
	//! @return �C���X�^���X
	static DebugDraw* getInstance();

	//! @brief �C���X�^���X�����
	void release();

private:
	//! �`��Ώۂ̃m�[�h
	cocos2d::Node* m_pTargetNode;
	//! �`��m�[�h
	cocos2d::DrawNode* m_drawNode;

public:
	//! @brief �m�[�h��������
	void initialize(cocos2d::Node* pTargetNode);

	//! @brief �`��m�[�h�擾
	cocos2d::DrawNode* getDrawNode()const;

};
