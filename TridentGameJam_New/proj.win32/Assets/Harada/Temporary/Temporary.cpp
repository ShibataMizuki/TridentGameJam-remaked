#include "Temporary.h"

//! 1. include CollisionSystem.h
#include"Shibata/CollisionSystem/CollisionSystem.h"

//! (optional) include CollisionSystemDebugDraw.h
#include"Shibata/CollisionSystemDebugDraw/CollisionSystemDebugDraw.h"

#include"Shibata/GameObject/AllyCharacter/AllyCharacter.h"

#include"Shibata/Party/Party.h"

// ========================================================== //
#include"Harada\background\backgroundLayer.h"
// ========================================================== //



USING_NS_CC;

static CSWorld* g_pWorld;

enum ObjectType
{
	Player,
	Bullet,
	Wall,
};

/*==============================
�����̒e
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
�����L�����N�^�[�̍���
===============================*/
//! AllyCharacter���p�������N���X�����
class TestCharacter :public AllyCharacter
{
private:
	//! �o�ߎ���
	float m_elapsedTime;
	//! �ˌ��Ԋu
	float m_shotInterval;

public:
	CREATE_FUNC(TestCharacter);

	bool init()override
	{
		//! �e�N���X�̏������`�F�b�N������
		if (!AllyCharacter::init())
			return false;
		scheduleUpdate();
		m_elapsedTime = 0.f;

		m_shotInterval = 0.2f;

		// �ǉ�
		m_maxSp = 50.0f;
		m_currentSp = 50.0f;

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
		//! syncBody��CSBody�ƃL�����̍��W�𓯊�������
		syncBody();
	}
};


cocos2d::Scene * Temporary::createScene()
{
	auto scene = Scene::create();
	auto layer = Temporary::create();
	scene->addChild(layer, 2);
	// ========================================================== //
	auto backgroundlayer = backgroundLayer::create();
	scene->addChild(backgroundlayer);
	// ========================================================== //
	return scene;
}

bool Temporary::init()
{
	// ========================================================== //
	// ��ʃT�C�Y
	Size visibleSize = Director::getInstance()->getVisibleSize();
	// �C�x���g���X�i�[�쐬
	auto Listener = EventListenerTouchOneByOne::create();
	// ���X�i�[�ɐݒ�
	Listener->onTouchBegan = CC_CALLBACK_2(Temporary::onTouchBegan, this);
	Listener->onTouchMoved = CC_CALLBACK_2(Temporary::onTouchMoved, this);
	Listener->onTouchEnded = CC_CALLBACK_2(Temporary::onTouchEnded, this);
	Listener->onTouchCancelled = CC_CALLBACK_2(Temporary::onTouchCancelled, this);
	// �C�x���g�f�B�X�p�b�`���[
	auto eventDispatcher = this->getEventDispatcher();
	// �C�x���g���X�i�[�ǉ�
	eventDispatcher->addEventListenerWithSceneGraphPriority(Listener, this);
	// ========================================================== //



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
	callback->HitBegin = [](const std::shared_ptr<CSBody>& bodyA, const std::shared_ptr<CSBody>& bodyB)
	{
		auto bullet = bodyA->getCastedUserData<TestBullet>();
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

	//Party* party = Party::create();
	g_party = Party::create();
	auto testChara = TestCharacter::create();
	auto body = CSBody::createShared();
	body->addShape(CSCircle::createShared(30.f));
	g_pWorld->addBody(body);
	testChara->setBody(body);
	testChara->setSpriteAnimation("Characters/Character01.png");
	g_party->setPartyMember(testChara, PartyIndex::_1);

	// ========================================================== //
	auto testChara2 = TestCharacter::create();
	auto body2 = CSBody::createShared();
	body2->addShape(CSCircle::createShared(30.f));
	g_pWorld->addBody(body2);
	testChara2->setBody(body2);
	testChara2->setSpriteAnimation("Characters/Character02.png");
	g_party->setPartyMember(testChara2, PartyIndex::_2);


	for (int i = 0; i < 4; i++) {
		// �{�^��(��200,�c160)
		m_button[i] = ui::Button::create("Backgrounds/button1.png", "Backgrounds/button2.png");
		m_button[i]->setPosition(Vec2(visibleSize.width - 100, visibleSize.height - 80 - 160 * i));
		this->addChild(m_button[i],2);
		//m_button[i]->addTouchEventListener(CC_CALLBACK_2(Temporary::ButtonEvent, this));
	}
	// �悭�킩��Ȃ�����Ƃ肠�����ʂ�
	m_button[0]->addTouchEventListener(CC_CALLBACK_2(Temporary::ButtonEvent1, this));
	m_button[1]->addTouchEventListener(CC_CALLBACK_2(Temporary::ButtonEvent2, this));

	for (int i = 0; i < 4; i++) {
		// SP�o�[(��150)
		m_SPbar[i] = Sprite::create("Backgrounds/spbar.png");
		m_SPbar[i]->setAnchorPoint(Vec2(0.f, 0.f));
		m_SPbar[i]->setPosition(Vec2(visibleSize.width - 75 - 100, visibleSize.height - 80  - 160 * i));
		this->addChild(m_SPbar[i],3);
	}
	for (int i = 0; i < 4; i++) {
		// HP�o�[(��150)
		m_HPbar[i] = Sprite::create("Backgrounds/hpbar.png");
		m_HPbar[i]->setAnchorPoint(Vec2(0.f, 0.f));
		m_HPbar[i]->setPosition(Vec2(visibleSize.width - 75 - 100, visibleSize.height - 100 - 160 * i));
		this->addChild(m_HPbar[i],3);
	}
	// ========================================================== //


	addChild(g_party);
	this->scheduleUpdate();

	return true;
}

void Temporary::update(float dt)
{
	//! 11. call every frame this
	g_pWorld->executeCollision();
}

bool Temporary::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// �^�b�`���W�擾
	Vec2 touchPos = touch->getLocation();

	// �p�[�e�B�N��(�Ȉ�)
	CCParticleSystemQuad* particle = CCParticleSystemQuad::create("Effects/ontouch.plist");
	particle->resetSystem();
	particle->setPosition(touchPos);
	this->addChild(particle, 2);

	return true;
}

void Temporary::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// �^�b�`���W�擾
	Vec2 touchPos = touch->getLocation();

	// �p�[�e�B�N��(�Ȉ�)
	CCParticleSystemQuad* particle = CCParticleSystemQuad::create("Effects/ontouch.plist");
	particle->resetSystem();
	particle->setPosition(touchPos);
	this->addChild(particle, 2);
}

void Temporary::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// �A�b�v�f�[�g���~�߂�
	//this->unscheduleUpdate();
	/*auto nextScene = ::create();
	Director::getInstance()->replaceScene(TransitionPageTurn::create(2.0f ,nextScene,0));*/
}

void Temporary::onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event)
{

}



void Temporary::ButtonEvent1(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN:
		if (g_party->getPartyMember(PartyIndex::_1)->isSkillEnabled() == false)
		{
			// �X�L���L����
			g_party->getPartyMember(PartyIndex::_1)->enableSkill();
			// SP����
			g_party->getPartyMember(PartyIndex::_1)->useSp(5.0f);
			// ��
			log("pushed");
			float num = g_party->getPartyMember(PartyIndex::_1)->getCurrentSp();
			float num2 = g_party->getPartyMember(PartyIndex::_1)->getMaxSp();
			// SP�c�ʂɂ���ăT�C�Y�ύX
			m_SPbar[0]->setScaleX(num/num2);
			log("%f:%f", num, num2);
			// �X�L��������
			g_party->getPartyMember(PartyIndex::_1)->disableSkill();
		}
		break;
	case ui::Widget::TouchEventType::MOVED:
		break;
	case ui::Widget::TouchEventType::ENDED:
		break;
	}
}
void Temporary::ButtonEvent2(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN:
		if (g_party->getPartyMember(PartyIndex::_2)->isSkillEnabled() == false)
		{
			// �X�L���L����
			g_party->getPartyMember(PartyIndex::_2)->enableSkill();
			// SP����
			g_party->getPartyMember(PartyIndex::_2)->useSp(5.0f);
			// ��
			log("pushed");
			float num = g_party->getPartyMember(PartyIndex::_2)->getCurrentSp();
			float num2 = g_party->getPartyMember(PartyIndex::_2)->getMaxSp();
			// SP�c�ʂɂ���ăT�C�Y�ύX
			m_SPbar[1]->setScaleX(num / num2);
			log("%f:%f", num, num2);
			// �X�L��������
			g_party->getPartyMember(PartyIndex::_2)->disableSkill();
		}
		break;
	case ui::Widget::TouchEventType::MOVED:
		break;
	case ui::Widget::TouchEventType::ENDED:
		break;
	}
}