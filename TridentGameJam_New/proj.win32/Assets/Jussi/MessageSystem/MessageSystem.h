#pragma once

#include <cocos2d.h>
#include <ui/CocosGUI.h>

#include <string>
#include <vector>

enum class MessageType {SINGLE, YESNO};

class MessageSystem : public cocos2d::Layer
{
public:
	static MessageSystem* create(MessageType mtype, std::string mtext);
	virtual bool init(MessageType mtype, std::string mtext);

	void createMenuButtons(MessageType messageType);

	void buttonSelectedOK(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType eventType);
	void buttonSelectedYes(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType eventType);
	void buttonSelectedNo(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType eventType);

	void setMessageType(MessageType mtype);
	void setMessageText(std::string mtext);
	


private:
	//Attributes for the MessageBox
	MessageType m_MessageType;
	std::string m_Text;
	cocos2d::Sprite* m_Sprite;
	bool m_IsButtonHighlighted;

	cocos2d::Point m_TouchPosition;
	bool m_IsTouching;

	//Label
	cocos2d::Label* m_Label;

	//Buttons
	cocos2d::ui::Button* m_ButtonOK;
	cocos2d::ui::Button* m_ButtonYes;
	cocos2d::ui::Button* m_ButtonNo;
};
