#include "Shibata/CollisionSystemDebugDraw/CollisionSystemDebugDraw.h"
#include"../CollisionSystem/CSBody/CSBody.h"
#include"../CollisionSystem/CSShape/CSCircle/CSCircle.h"
#include"../Utility/Utility.h"

CollisionSystemDebugDraw::CollisionSystemDebugDraw()
{
}

CollisionSystemDebugDraw::~CollisionSystemDebugDraw()
{
}

bool CollisionSystemDebugDraw::init()
{
	if (!Node::init())return false;

	scheduleUpdate();

	return true;
}

void CollisionSystemDebugDraw::update(float dt)
{
	auto drawNode = DebugDraw::getInstance()->getDrawNode();

	drawNode->clear();

	auto& bodyList = m_pWorld->getBodyList();
	for (auto& body : bodyList)
	{
		AABB aabb = body->getAABB();
		drawNode->drawRect(toCocosVec2(aabb.getLower()), toCocosVec2(aabb.getUpper()), cocos2d::Color4F::GREEN);

		for (auto& shape : body->getShapeList())
		{
			if (typeid(*shape.get()) == typeid(CSCircle))
			{
				auto circle = dynamic_cast<CSCircle*>(shape.get());
				drawNode->drawCircle(toCocosVec2(body->getPosition() + shape->getPosition()), circle->getRadius(), 0.0f, 18.f, false, cocos2d::Color4F::RED);
			}		
		}
	}
}

void CollisionSystemDebugDraw::setCSWorld(CSWorld * pWorld)
{
	m_pWorld = pWorld;
}
