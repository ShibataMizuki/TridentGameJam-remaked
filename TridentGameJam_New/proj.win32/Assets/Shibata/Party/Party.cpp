#include "Party.h"

USING_NS_CC;

bool Party::init()
{
	if (!Node::init())return false;

	for (uint f1 = 0; f1 < (uint)PartyIndex::Max; f1++)
	{
		m_partyMembers[f1] = nullptr;
	}

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = std::bind(&Party::onTouchBegin, this, std::placeholders::_1, std::placeholders::_2);
	listener->onTouchMoved = std::bind(&Party::onTouchMoved, this, std::placeholders::_1, std::placeholders::_2);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	this->scheduleUpdate();

	return true;
}

void Party::update(float dt)
{
}

void Party::setPartyMember(AllyCharacter * ally, PartyIndex index)
{
	m_partyMembers[(uint)index] = ally;
	this->addChild(m_partyMembers[(uint)index]);
}

AllyCharacter * Party::getPartyMember(PartyIndex index)
{
	return m_partyMembers[(uint)index];
}

void Party::removePartyMember(PartyIndex index)
{
	m_partyMembers[(uint)index]->removeFromParent();
	m_partyMembers[(uint)index] = nullptr;
}

bool Party::onTouchBegin(cocos2d::Touch * touch, cocos2d::Event * event)
{
	m_oldPos = touch->getLocation();
	return true;
}

void Party::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto currentPos = touch->getLocation();
	this->setPosition(this->getPosition() + currentPos - m_oldPos);
	m_oldPos = currentPos;
}