#include "Example.h"

//! 1. include CollisionSystem.h
#include"../CollisionSystem/CollisionSystem.h"

//! (optional) include CollisionSystemDebugDraw.h
#include"../CollisionSystemDebugDraw/CollisionSystemDebugDraw.h"

#include"../GameObject/AllyCharacter/AllyCharacter.h"

#include"Shibata/Party/Party.h"

USING_NS_CC;


enum class ObjectType:int
{
	Player,
	Enemy,
};

/*==============================
味方キャラクターの作り方
===============================*/
//! AllyCharacterを継承したクラスを作る
class TestCharacter :public AllyCharacter
{
public:
	CREATE_FUNC(TestCharacter);

	bool init()override
	{
		//! 親クラスの初期化チェックをする
		if (!AllyCharacter::init())
			return false;
		scheduleUpdate();

		return true;
	}

	void update(float dt)override
	{
		//! syncBodyでCSBodyとキャラの座標を同期させる
		syncBody();
	}

	//! 攻撃方法を定義する
	void executeAttack(float dt)override
	{

	}

	//! スキルを定義する
	void skillAttack()override
	{

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
	m_pWorld = new CSWorld();
	//! 3. create body
	auto bodyA = CSBody::createShared();
	//! 4. create shape and setting to body
	auto circleA = CSCircle::createShared(70.f);
	bodyA->addShape(circleA);
	//! 5. set position
	bodyA->setPosition(CSVec2(250.f, 200.f));
	//! 6. set collision group. This is used for a hit judgment rule
	bodyA->setCollisionGroup((int)ObjectType::Player);
	//! 7. registering body to world
	m_pWorld->addBody(bodyA);

	auto bodyB = CSBody::createShared();
	auto circleB = CSCircle::createShared(50.f);
	bodyB->addShape(circleB);
	bodyB->setPosition(CSVec2(150.f, 150.f));
	bodyB->setCollisionGroup((int)ObjectType::Enemy);

	m_pWorld->addBody(bodyB);

	//! 8. create callback and setting two groups of the object which collide
	auto callback = CSHitCallback::createShared((int)ObjectType::Player, (int)ObjectType::Enemy);

	//! 9. setting callback
	callback->HitBegin = [](const std::shared_ptr<CSBody>& bodyA,const std::shared_ptr<CSBody>& bodyB)
	{
		cocos2d::log("Hit!");
	};

	//! 10. registering callback to world
	m_pWorld->addHitCallback(callback);

	//! (optional) debug draw setting
	DebugDraw::getInstance()->initialize(this);
	auto debugDraw=CollisionSystemDebugDraw::create();
	debugDraw->setCSWorld(m_pWorld);
	addChild(debugDraw);

	auto background = Sprite::create("Backgrounds/plain.jpg");
	background->setAnchorPoint(Vec2(0.f, 0.f));
	addChild(background);

	Party* party = Party::create();

	for (int f1 = 0; f1 < 2; f1++)
	{
		TestCharacter* chara = TestCharacter::create();
		auto body = CSBody::createShared();
		body->addShape(CSCircle::createShared(20.f));
		m_pWorld->addBody(body);
		chara->setBody(body);
		chara->setPosition(Vec2(0.f,f1*60.f));
		chara->setSpriteAnimation("Characters/Character01.png");
		party->setPartyMember(chara, (PartyIndex)f1, Vec2(0.f, 0.f));
		chara->setScale(2.0f);
	}
	for (int f1 = 0; f1 < 2; f1++)
	{
		TestCharacter* chara = TestCharacter::create();
		auto body = CSBody::createShared();
		body->addShape(CSCircle::createShared(20.f));
		m_pWorld->addBody(body);
		chara->setBody(body);
		chara->setPosition(Vec2(0.f, (f1+2)*60.f));
		chara->setSpriteAnimation("Characters/Character02.png");
		party->setPartyMember(chara, (PartyIndex)(f1+2), Vec2(0.f, 0.f));
		chara->setScale(2.0f);
	}
	
	addChild(party);
	this->scheduleUpdate();

	return true;
}

void Example::update(float dt)
{
	//! 11. call every frame this
	m_pWorld->executeCollision();
}
