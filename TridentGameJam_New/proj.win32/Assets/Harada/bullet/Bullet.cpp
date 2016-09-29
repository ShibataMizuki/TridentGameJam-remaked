/*
* �e�N���X
*/
#include "Bullet.h"

USING_NS_CC;


Bullet::Bullet()
{
	//	�I�u�W�F�N�g�̐���
	m_obj = new GameObject();

	// �{�f�B�̐���
	m_pBody = CSBody::createShared();
	// �T�C�Y��ݒ�
	m_rad = 50.0f;
	auto circleA = CSCircle::createShared(m_rad);
	m_pBody->addShape(circleA);
	// �{�f�B�̈ʒu�ݒ�
	m_pos = CSVec2(150.0f, 150.0f);
	m_pBody->setPosition(m_pos);

	// �O���[�v
	m_type = 1;
	m_pBody->setCollisionGroup(m_type);

	// �X�s�[�h�ݒ�
	m_spd = CSVec2(1.5f, 0.0f);

	// �X�v���C�g
	m_sprite = Sprite::create("CloseNormal.png");
	this->addChild(m_sprite);

	// �{�f�B�ݒ�
	m_obj->setBody(m_pBody);

	// �ʒu�ݒ�
	m_obj->setPosition(10,10);
	m_sprite->setPosition(m_obj->getPosition());

	// ����
	m_obj->syncBody();

}

Bullet::~Bullet()
{
	delete m_obj;
	delete m_sprite;
}

void Bullet::update(float dt)
{
	// �e�̈ړ�
	m_pBody->setPosition(m_pos + m_spd);
	m_sprite->setPosition(m_obj->getPosition());

	// ����
	m_obj->syncBody();
}