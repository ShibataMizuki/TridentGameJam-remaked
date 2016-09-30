#include "TestEnemyBullet.h"

USING_NS_CC;

TestEnemyBullet::TestEnemyBullet()
{
	//	オブジェクトの生成
	m_obj = new GameObject();

	// ボディの生成
	m_pBody = CSBody::createShared();
	// サイズを設定
	m_rad = 50.0f;
	auto circleA = CSCircle::createShared(m_rad);
	m_pBody->addShape(circleA);
	// ボディの位置設定
	m_pos = CSVec2(150.0f, 150.0f);
	m_pBody->setPosition(m_pos);

	// グループ
	m_type = 3;
	m_pBody->setCollisionGroup(m_type);

	// スピード設定
	m_spd = CSVec2(1.5f, 0.0f);

	// スプライト
	m_sprite = Sprite::create("Example/effect.png");
	this->addChild(m_sprite);

	// ボディ設定
	m_obj->setBody(m_pBody);

	// 位置設定
	m_obj->setPosition(100, 100);
	m_sprite->setPosition(m_obj->getPosition());

	// 同期
	m_obj->syncBody();
}

TestEnemyBullet::~TestEnemyBullet()
{
	delete m_obj;
	delete m_sprite;
}

void TestEnemyBullet::update(float dt)
{
	// 弾の移動
	m_pBody->setPosition(m_pos - m_spd);
	m_sprite->setPosition(m_obj->getPosition());

	// 同期
	m_obj->syncBody();
}
