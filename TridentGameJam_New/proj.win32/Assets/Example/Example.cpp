#include "Example.h"

//! 1. include CollisionSystem.h
#include"Shibata/CollisionSystem/CollisionSystem.h"

//! (optional) include CollisionSystemDebugDraw.h
#include"Shibata/CollisionSystemDebugDraw/CollisionSystemDebugDraw.h"

#include"Shibata/GameObject/AllyCharacter/AllyCharacter.h"

#include"Shibata/Party/Party.h"

USING_NS_CC;

static CSWorld* g_pWorld;

enum ObjectType
{
	Player,
	Bullet,
	Wall,
};

/*==============================
味方の弾
===============================*/
class TestBullet :public GameObject
{
private:
public:
	CREATE_FUNC(TestBullet);

	bool init()override
	{
		if (!GameObject::init())
			return false;
		scheduleUpdate();
		
		auto body = CSBody::createShared();
		body->addShape(CSCircle::createShared(10.f));
		body->setCollisionGroup(ObjectType::Bullet);
		setBody(body);
		g_pWorld->addBody(body);

		addChild(Sprite::create("Example/effect.png"));
		setScale(0.5f);

		return true;
	}

	void update(float dt)override
	{
		auto pos = getPosition();
		pos.x += 15;
		setPosition(pos);
		syncBody();
	}

};

/*==============================
味方キャラクターの作り方
===============================*/
//! AllyCharacterを継承したクラスを作る
class TestCharacter :public AllyCharacter
{
private:
	//! 経過時間
	float m_elapsedTime;
	//! 射撃間隔
	float m_shotInterval;

public:
	CREATE_FUNC(TestCharacter);

	bool init()override
	{
		//! 親クラスの初期化チェックをする
		if (!AllyCharacter::init())
			return false;
		scheduleUpdate();
		m_elapsedTime = 0.f;

		m_shotInterval = 0.2f;

		return true;
	}

	void update(float dt)override
	{
		m_elapsedTime += dt;
		if (m_elapsedTime >= m_shotInterval)
		{
			auto bullet = TestBullet::create();
			bullet->setPosition(getParent()->convertToWorldSpace(getPosition()));
			getParent()->getParent()->addChild(bullet);
			m_elapsedTime = 0.0f;
		}
		//! syncBodyでCSBodyとキャラの座標を同期させる
		syncBody();
	}
};


cocos2d::Scene * Example::createScene()
{
	auto scene = Scene::create();
	auto layer = Example::create();
	scene->addChild(layer);
	return scene;
}

bool Example::init()
{
	if (!Layer::init())return false;
	//! 2. create world
	g_pWorld = new CSWorld();
	//! 3. create body
	auto bodyA = CSBody::createShared();
	//! 4. create shape and setting to body
	auto circleA = CSCircle::createShared(70.f);
	bodyA->addShape(circleA);
	//! 5. set position
	bodyA->setPosition(CSVec2(450.f, 200.f));
	//! 6. set collision group. This is used for a hit judgment rule
	bodyA->setCollisionGroup(ObjectType::Wall);
	//! 7. registering body to world
	g_pWorld->addBody(bodyA);

	auto bodyB = CSBody::createShared();
	auto circleB = CSCircle::createShared(50.f);
	bodyB->addShape(circleB);
	bodyB->setPosition(CSVec2(450.f, 400.f));
	bodyB->setCollisionGroup(ObjectType::Wall);

	g_pWorld->addBody(bodyB);

	//! 8. create callback and setting two groups of the object which collide
	auto callback = CSHitCallback::createShared(ObjectType::Bullet, ObjectType::Wall);

	//! 9. setting callback
	callback->HitBegin = [](const std::shared_ptr<CSBody>& bodyA,const std::shared_ptr<CSBody>& bodyB)
	{
		auto bullet = bodyA->getCastedUserData<TestBullet>();
		bullet->removeFromParent();
		g_pWorld->destroyBody(bodyA);
	};

	//! 10. registering callback to world
	g_pWorld->addHitCallback(callback);

	//! (optional) debug draw setting
	DebugDraw::getInstance()->initialize(this);
	auto debugDraw=CollisionSystemDebugDraw::create();
	debugDraw->setCSWorld(g_pWorld);
	addChild(debugDraw);

	auto background = Sprite::create("Backgrounds/plain.jpg");
	background->setAnchorPoint(Vec2(0.f, 0.f));
	addChild(background);

	Party* party = Party::create();
	auto testChara = TestCharacter::create();
	auto body = CSBody::createShared();
	body->addShape(CSCircle::createShared(30.f));
	g_pWorld->addBody(body);
	testChara->setBody(body);
	testChara->setSpriteAnimation("Characters/Character01.png");
	party->setPartyMember(testChara, PartyIndex::_1);
	

	addChild(party);
	this->scheduleUpdate();

	return true;
}

void Example::update(float dt)
{
	//! 11. call every frame this
	g_pWorld->executeCollision();
}
