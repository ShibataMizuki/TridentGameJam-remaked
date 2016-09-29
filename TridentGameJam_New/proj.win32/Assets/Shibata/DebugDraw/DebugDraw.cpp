#include "DebugDraw.h"
USING_NS_CC;

DebugDraw* DebugDraw::m_pInstance = nullptr;

DebugDraw * DebugDraw::getInstance()
{
	if (!m_pInstance)m_pInstance = new DebugDraw();
	return m_pInstance;
}

void DebugDraw::release()
{
	delete m_pInstance;
}

void DebugDraw::initialize(cocos2d::Node* pTargetNode)
{
	m_drawNode = DrawNode::create();
	pTargetNode->addChild(m_drawNode,1000);
	m_pTargetNode = pTargetNode;
}

DrawNode * DebugDraw::getDrawNode()const
{
	return m_drawNode;
}
