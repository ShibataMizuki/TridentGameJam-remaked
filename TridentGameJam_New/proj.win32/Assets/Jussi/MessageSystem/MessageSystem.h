#pragma once

#include <cocos2d.h>
#include <ui/CocosGUI.h>



#include <string>
#include <vector>

enum class MessageType {SINGLE, YESNO};

class MessageSystem : public cocos2d::Layer
{
public:
	MessageSystem(MessageType messageType, std::string text);

	virtual bool init();

	void createMenuButtons(MessageType messageType);

	void buttonSelectedOK(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType eventType);
	void buttonSelectedYes(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType eventType);
	void buttonSelectedNo(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType eventType);

	//void touchCallBack(cocos2d::EventListenerTouchOneByOne::, cocos2d::Event* event);

private:
	//Attributes for the MessageBox
	MessageType m_MessageType;
	std::string m_Text;
	cocos2d::Sprite* m_Sprite;
	bool m_IsButtonHighlighted;

	cocos2d::Point m_TouchPosition;
	bool m_IsTouching;

	//int m_Height;
	//int m_Width;

	//Label
	cocos2d::Label* m_Label;
	//int m_LabelPosX;
	//int m_LabelPosY;

	//Buttons
	cocos2d::ui::Button* m_ButtonOK;
	cocos2d::ui::Button* m_ButtonYes;
	cocos2d::ui::Button* m_ButtonNo;
};
