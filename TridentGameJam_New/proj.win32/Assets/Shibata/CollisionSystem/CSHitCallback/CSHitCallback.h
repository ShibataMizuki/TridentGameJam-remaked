#pragma once

#include<memory>
#include<functional>

class CSBody;

//! �Փ˂�����̏���
class CSHitCallback
{
	/*==============================
	�R���X�g���N�^
	===============================*/
public:
	CSHitCallback(int collisionGroupA, int collisionGroupB);

	/*==============================
	�Փ˃O���[�v�̊Ǘ�
	===============================*/
private:
	int m_collisionGroupA;
	int m_collisionGroupB;
public:
	//! �Փ˃O���[�vA��ݒ�
	void setCollisionGroupA(int group);
	//! �Փ˃O���[�vB��ݒ�
	void setCollisionGroupB(int group);
	//! �Փ˃O���[�vA���擾
	int getCollisionGroupA()const;
	//! �Փ˃O���[�vB���擾
	int getCollisionGroupB()const;

public:
	//! �Փ˒���̏���
	std::function<void(const std::shared_ptr<CSBody>& bodyA, const std::shared_ptr<CSBody>& bodyB)> HitBegin;

	//! �X�}�[�g�|�C���^����
	static std::shared_ptr<CSHitCallback> createShared(int collisionGroupA, int collisionGroupB);
};