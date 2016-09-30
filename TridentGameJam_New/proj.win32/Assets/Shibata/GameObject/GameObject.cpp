#include "GameObject.h"
#include"Shibata/Utility/Utility.h"

USING_NS_CC;

bool GameObject::init()
{
	if (!Node::init())
		return false;
	m_pSprite = Sprite::create();
	addChild(m_pSprite);
	return true;
}

void GameObject::setBody(const std::shared_ptr<CSBody>& pBody)
{
	m_pBody = pBody;
	m_pBody->setUserData(this);
}

const std::shared_ptr<CSBody>& GameObject::getBody() const
{
	return m_pBody;
}

void GameObject::syncBody()
{
	if (this->getParent() != nullptr)
		m_pBody->setPosition(toCSVec2(this->getParent()->convertToWorldSpace(this->getPosition())));
	else
		m_pBody->setPosition(toCSVec2(this->getPosition()));
}

cocos2d::Sprite * GameObject::getSprite() const
{
	return m_pSprite;
}

void GameObject::runAnimation(cocos2d::Animation * pAnimation)
{
	auto animate = Animate::create(pAnimation);
	m_pSprite->runAction(animate);
}
