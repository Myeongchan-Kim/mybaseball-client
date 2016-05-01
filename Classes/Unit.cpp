#include "header.h"
#include "Unit.h"
#include "ConstVar.h"

USING_NS_CC;

Unit::Unit()
{
	m_defaultRect = Rect(0, 0, 100, 100);
	m_spr = Sprite::create(ConstVar::SQUARE_IMG);
};

Unit::~Unit(){};

void Unit::SetName(std::string name)
{
	m_spr->setName(name);
}


void Unit::SetScaleAndPos()
{
	m_spr->setScaleX(m_defaultRect.size.width / m_spr->getContentSize().width);
	m_spr->setScaleY(m_defaultRect.size.height / m_spr->getContentSize().height);
	m_spr->setPosition(m_defaultRect.getMidX(), m_defaultRect.getMidY());
}


cocos2d::Action* Unit::SetZero()
{
	return DelayTime::create(0.0f);
}
cocos2d::Action* Unit::PlusOne()
{
	return DelayTime::create(0.0f);
}

cocos2d::Action* Unit::MinusOne()
{
	return DelayTime::create(0.0f);
}

cocos2d::Action* Unit::MoveTo1()
{
	return DelayTime::create(0.0f);
}

cocos2d::Action* Unit::MoveTo2()
{
	return DelayTime::create(0.0f);
}

cocos2d::Action* Unit::MoveTo3()
{
	return DelayTime::create(0.0f);
}

cocos2d::Action* Unit::MoveToH()
{
	return DelayTime::create(0.0f);
}

cocos2d::Action* Unit::ChangeSide()
{
	return DelayTime::create(0.0f);
}
