/*
* �e�N���X
*/
#pragma once

#include<Shibata/GameObject/GameObject.h>
#include"cocos2d.h"


class Bullet : public GameObject
{
private:
	// �I�u�W�F�N�g
	GameObject* m_obj;
	// �X�v���C�g
	cocos2d::Sprite* m_sprite;
	// �T�C�Y
	float m_rad;
	// �^�C�v
	int m_type;
	// �|�W�V����
	CSVec2 m_pos;
	// �X�s�[�h
	CSVec2 m_spd;

public:
	Bullet();
	~Bullet();

	virtual void update(float dt)override;
};

