#include "Jussi/MessageSystem/MessageSystem.h"



USING_NS_CC;

MessageSystem::MessageSystem(MessageType messageType, std::string text) :
	m_Sprite(),
	m_Label(),
	m_ButtonOK(),
	m_ButtonYes(),
	m_ButtonNo(),
	m_TouchPosition(0.0f, 0.0f),
	m_IsButtonHighlighted(false)
{
	m_MessageType = messageType;
	m_Text = text;
}

bool MessageSystem::init()
{
	if (!Layer::init()) 
		return false;

	m_Sprite = Sprite::create("textureMessageBox.png");
	m_Sprite->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
	//m_Sprite->setPosition(Director::getInstance()->getOpenGLView()->getFrameSize() / 2);
	//m_Sprite->setPosition(480, 320);
	//this->getContentSize();
	//use these
	//Director::getInstance()->getVisibleSize().height;
	//Director::getInstance()->getVisibleSize().width;
	this->addChild(m_Sprite);

	m_Label = cocos2d::Label::createWithSystemFont(m_Text, "Arial", 22);
	m_Label->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 3);
	//m_Label->setPosition(m_LabelPosX, m_LabelPosX);
	//m_Label->setPosition(m_Width / 2, m_Height / 3);
	m_Label->setColor(Color3B::BLACK);
	this->addChild(m_Label);

	//buttonit
	createMenuButtons(m_MessageType);

	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	listener = cocos2d::EventListenerTouchOneByOne::create();
	//listener->onTouchBegan
	//listener->onTouchBegan = CC_CALLBACK_2(MessageSystem::touchCallBack, this);

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void MessageSystem::createMenuButtons(MessageType messageType)
{
	if (messageType == MessageType::SINGLE)
	{
		//OK
		m_ButtonOK = ui::Button::create();
		m_ButtonOK->loadTextures("ButtonNormal.png", "ButtonSelected.png");
		m_ButtonOK->setPosition(Point(Director::getInstance()->getVisibleSize().width / 2, (Director::getInstance()->getVisibleSize().height / 3) * 2));
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
		m_ButtonYes->loadTextures("ButtonNormal.png", "ButtonSelected.png");
		m_ButtonYes->setPosition(Point((Director::getInstance()->getVisibleSize().width / 6) * 2, (Director::getInstance()->getVisibleSize().height / 3) * 2));
		m_ButtonYes->setTitleText("YES");
		m_ButtonYes->setTitleFontSize(22);
		m_ButtonYes->setTitleColor(Color3B::BLACK);
		m_ButtonYes->setTouchEnabled(true);
		m_ButtonOK->addTouchEventListener(CC_CALLBACK_2(MessageSystem::buttonSelectedYes, this));

		//NO
		m_ButtonNo = ui::Button::create();
		m_ButtonNo->loadTextures("ButtonNormal.png", "ButtonSelected.png");
		m_ButtonNo->setPosition(Point((Director::getInstance()->getVisibleSize().width / 6) * 4, (Director::getInstance()->getVisibleSize().height / 3) * 2));
		m_ButtonNo->setTitleText("NO");
		m_ButtonNo->setTitleFontSize(22);
		m_ButtonNo->setTitleColor(Color3B::BLACK);
		m_ButtonNo->setTouchEnabled(true);
		m_ButtonOK->addTouchEventListener(CC_CALLBACK_2(MessageSystem::buttonSelectedNo, this));

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