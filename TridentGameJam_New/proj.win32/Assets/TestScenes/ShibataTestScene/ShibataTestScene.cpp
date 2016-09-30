#include "ShibataTestScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

//! 1. include CollisionSystem.h
#include"Shibata/CollisionSystem/CollisionSystem.h"

//! (optional) include CollisionSystemDebugDraw.h
#include"Shibata/CollisionSystemDebugDraw/CollisionSystemDebugDraw.h"
#include"Shibata/GameObject/AllyCharacter/AllyCharacter.h"
#include"Shibata/Party/Party.h"
#include"Shibata/Utility/Utility.h"
#include"Shibata/Defines.h"

#include<vector>

USING_NS_CC;
using namespace std;
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
class TestBullet2 :public GameObject
{
private:
public:
	CREATE_FUNC(TestBullet2);

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
class TestCharacter2 :public AllyCharacter
{
private:
	//! 経過時間
	float m_elapsedTime;
	//! 射撃間隔
	float m_shotInterval;

public:
	CREATE_FUNC(TestCharacter2);

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
			auto bullet = TestBullet2::create();
			bullet->setPosition(getParent()->convertToWorldSpace(getPosition()));
			getParent()->getParent()->addChild(bullet);
			m_elapsedTime = 0.0f;
		}
		//! syncBodyでCSBodyとキャラの座標を同期させる
		syncBody();
	}
};

Scene* ShibataTestScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = ShibataTestScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool ShibataTestScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

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
	callback->HitBegin = [](const std::shared_ptr<CSBody>& bodyA, const std::shared_ptr<CSBody>& bodyB)
	{
		auto bullet = bodyA->getCastedUserData<TestBullet2>();
		bullet->removeFromParent();
		g_pWorld->destroyBody(bodyA);
	};

	//! 10. registering callback to world
	g_pWorld->addHitCallback(callback);

	//! (optional) debug draw setting
	DebugDraw::getInstance()->initialize(this);
	auto debugDraw = CollisionSystemDebugDraw::create();
	debugDraw->setCSWorld(g_pWorld);
	addChild(debugDraw);

	auto background = Sprite::create("Backgrounds/plain.jpg");
	background->setAnchorPoint(Vec2(0.f, 0.f));
	addChild(background);

	Party* party = Party::create();
	auto testChara = TestCharacter2::create();
	auto body = CSBody::createShared();
	body->addShape(CSCircle::createShared(50.f));
	g_pWorld->addBody(body);
	testChara->setBody(body);

	auto sprites = divideSprite(Sprite::create("Characters/Character01.png"), CHARA_PIC_DIV_X, CHARA_PIC_DIV_Y);
	vector<int> indexes = { 6, 7, 8 };
	testChara->runAnimation(makeAnimation(move(sprites),indexes,0.1f, -1));
	//testChara->setSpriteAnimation("Characters/Character01.png");
	party->setPartyMember(testChara, PartyIndex::_1);

	addChild(party);

	this->scheduleUpdate();

	return true;
}

void ShibataTestScene::update(float dt)
{
	//! 11. call every frame this
	g_pWorld->executeCollision();
}
