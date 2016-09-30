#include "Jussi/MessageSystem/MessageSystem.h"



USING_NS_CC;


MessageSystem* MessageSystem::create(MessageType mtype, std::string mtext)
{
	auto messageSystem = new MessageSystem();
	
	//MessageType m_MessageType = mtype;
	//std::string m_Text = mtext;
	//messageSystem->init(m_MessageType, m_Text);

	messageSystem->init(mtype, mtext);

	return messageSystem;
}

bool MessageSystem::init(MessageType mtype, std::string mtext)
{
	if (!Layer::init()) 
		return false;

	m_MessageType = mtype;
	m_Text = mtext;

	m_Sprite = Sprite::create("TextureJussi/textureMessageBox.png");
	m_Sprite->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
	//m_Sprite->setPosition(Director::getInstance()->getOpenGLView()->getFrameSize() / 2);
	//m_Sprite->setPosition(480, 320);
	//this->getContentSize();
	//use these
	//Director::getInstance()->getVisibleSize().height;
	//Director::getInstance()->getVisibleSize().width;
	this->addChild(m_Sprite);
	m_Sprite->setLocalZOrder(-10);

	m_Label = cocos2d::Label::createWithSystemFont(m_Text, "Arial", 22);
	m_Label->setPosition(Director::getInstance()->getVisibleSize().width / 2, (Director::getInstance()->getVisibleSize().height / 3) * 2);
	m_Label->setColor(Color3B::BLACK);
	this->addChild(m_Label);

	//buttonit
	createMenuButtons(m_MessageType);

	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	listener = cocos2d::EventListenerTouchOneByOne::create();

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}


void MessageSystem::createMenuButtons(MessageType messageType)
{
	if (messageType == MessageType::SINGLE)
	{
		//OK
		m_ButtonOK = ui::Button::create();
		m_ButtonOK->loadTextures("TextureJussi/ButtonNormal.png", "TextureJussi/ButtonSelected.png");
		m_ButtonOK->setPosition(Point(Director::getInstance()->getVisibleSize().width / 2, (Director::getInstance()->getVisibleSize().height / 3) * 1));
		m_ButtonOK->setTitleText("OK");
		m_ButtonOK->setTitleFontSize(22);
		m_ButtonOK->setTitleColor(Color3B::BLACK);
		m_ButtonOK->setTouchEnabled(true);
		m_ButtonOK->addTouchEventListener(CC_CALLBACK_2(MessageSystem::buttonSelectedOK, this));

		this->addChild(m_ButtonOK);
	}
	if (messageType == MessageType::YESNO)
	{
		//YES
		m_ButtonYes = ui::Button::create();
		m_ButtonYes->loadTextures("TextureJussi/ButtonNormal.png", "TextureJussi/ButtonSelected.png");
		m_ButtonYes->setPosition(Point((Director::getInstance()->getVisibleSize().width / 6) * 2, (Director::getInstance()->getVisibleSize().height / 3) * 1));
		m_ButtonYes->setTitleText("YES");
		m_ButtonYes->setTitleFontSize(22);
		m_ButtonYes->setTitleColor(Color3B::BLACK);
		m_ButtonYes->setTouchEnabled(true);
		m_ButtonYes->addTouchEventListener(CC_CALLBACK_2(MessageSystem::buttonSelectedYes, this));

		//NO
		m_ButtonNo = ui::Button::create();
		m_ButtonNo->loadTextures("TextureJussi/ButtonNormal.png", "TextureJussi/ButtonSelected.png");
		m_ButtonNo->setPosition(Point((Director::getInstance()->getVisibleSize().width / 6) * 4, (Director::getInstance()->getVisibleSize().height / 3) * 1));
		m_ButtonNo->setTitleText("NO");
		m_ButtonNo->setTitleFontSize(22);
		m_ButtonNo->setTitleColor(Color3B::BLACK);
		m_ButtonNo->setTouchEnabled(true);
		m_ButtonNo->addTouchEventListener(CC_CALLBACK_2(MessageSystem::buttonSelectedNo, this));

		this->addChild(m_ButtonYes);
		this->addChild(m_ButtonNo);

	}
}

void MessageSystem::buttonSelectedOK(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType eventType)
{
	if (eventType != cocos2d::ui::Widget::TouchEventType::ENDED) return;

	CCLOG("OK button touched");
}

void MessageSystem::buttonSelectedYes(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType eventType)
{
	if (eventType != cocos2d::ui::Widget::TouchEventType::ENDED) return;

	CCLOG("YES button touched");
}

void MessageSystem::buttonSelectedNo(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType eventType)
{
	if (eventType != cocos2d::ui::Widget::TouchEventType::ENDED) return;

	CCLOG("NO button touched");
}


void MessageSystem::setMessageType(MessageType mtype)
{
	m_MessageType = mtype;
}

void MessageSystem::setMessageText(std::string mtext)
{
	m_Text = mtext;
}