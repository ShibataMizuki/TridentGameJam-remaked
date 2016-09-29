#include "GameObject.h"
#include"Shibata/Utility/Utility.h"

bool GameObject::init()
{
	if (!Node::init())
		return false;
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