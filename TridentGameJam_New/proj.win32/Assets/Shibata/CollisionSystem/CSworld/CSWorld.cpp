#include "CSWorld.h"
#include"../CSHitCallback/CSHitCallback.h"
#include"../CSBody/CSBody.h"
#include"../CSShape/CollisionDetection.h"

#include<algorithm>
#include<iostream>

using namespace std;

void CSWorld::addBody(const std::shared_ptr<CSBody>& pBody)
{
	m_bodyMap[pBody->getCollisionGroup()].push_back(pBody);
}

bool CSWorld::destroyBody(const std::shared_ptr<CSBody>& pBody)
{
	if (m_bodyMap.find(pBody->getCollisionGroup()) == m_bodyMap.end())return false;
	m_bodyMap.at(pBody->getCollisionGroup()).remove(pBody);
	return true;
}

const std::list<std::shared_ptr<CSBody>>& CSWorld::getBodyList(int group)const
{
	if (m_bodyMap.find(group) == m_bodyMap.end())return m_bodyMap.begin()->second;
	return m_bodyMap.at(group);
}

std::list<std::shared_ptr<CSBody>> CSWorld::getBodyList()
{
	list<shared_ptr<CSBody>> result;
	for (auto& bodyList : m_bodyMap)
	{
		result.insert(result.begin(), bodyList.second.begin(), bodyList.second.end());
	}
	return move(result);
}

CSWorld::Iterator CSWorld::getIterator()
{
	return Iterator(this);
}

void CSWorld::addHitCallback(const std::shared_ptr<CSHitCallback>& pCallback)
{
	m_hitCallbackList.push_back(pCallback);
}

std::list<std::shared_ptr<CSHitCallback>>::iterator CSWorld::getCallbackListBegin()
{
	return m_hitCallbackList.begin();
}

std::list<std::shared_ptr<CSHitCallback>>::iterator CSWorld::getCallbackListEnd()
{
	return m_hitCallbackList.end();
}

const std::list<std::shared_ptr<CSHitCallback>>& CSWorld::getCallbackList() const
{
	return m_hitCallbackList;
}

bool CSWorld::isCollision(CSBody * bodyA, CSBody * bodyB)
{
	if (!bodyA->getAABB().isIntersect(bodyB->getAABB()))return false;

	auto& listA = bodyA->getShapeList();
	auto& listB = bodyB->getShapeList();

	for (auto& shapeA : listA)
	{
		for (auto& shapeB : listB)
		{
			if (CollisionDetection(shapeA.get(), shapeB.get(), bodyA->getPosition(), bodyB->getPosition()))
			{
				return true;
			}
		}
	}
	return false;
}

void CSWorld::executeCollision()
{
	for (auto& callback : m_hitCallbackList)
	{
		if (m_bodyMap.find(callback->getCollisionGroupA()) != m_bodyMap.end() &&
			m_bodyMap.find(callback->getCollisionGroupB()) != m_bodyMap.end())
		{
			for (auto& bodyA : m_bodyMap[callback->getCollisionGroupA()])
			{
				for (auto& bodyB : m_bodyMap[callback->getCollisionGroupB()])
				{
					if (bodyA == bodyB)continue;
					if (isCollision(bodyA.get(), bodyB.get()))
					{
						callback->HitBegin(bodyA, bodyB);
					}
				}
			}
		}
	}
}

CSWorld::Iterator::Iterator(CSWorld * pWorld)
{
	m_pWorld = pWorld;
	m_bodyIt = m_pWorld->m_bodyMap.begin()->second.begin();
	m_mapIt = m_pWorld->m_bodyMap.begin();
}

void CSWorld::Iterator::next()
{
	m_bodyIt++;
	if (m_bodyIt == m_mapIt->second.end())
	{
		m_mapIt++;
		if (m_mapIt == m_pWorld->m_bodyMap.end())return;
		m_bodyIt = m_mapIt->second.begin();
	}
}

bool CSWorld::Iterator::hasNext()
{
	return !(m_mapIt == m_pWorld->m_bodyMap.end());
}

std::shared_ptr<CSBody> CSWorld::Iterator::getBody() const
{
	return *m_bodyIt;
}
