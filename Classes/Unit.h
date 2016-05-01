#pragma once
#include "header.h"

class Unit
{
public:
	Unit();
	virtual ~Unit();

	virtual void SetScaleAndPos();
	virtual void RemoveProc(){};
	virtual void SetName(std::string name);
	virtual cocos2d::Action* SetZero();
	virtual cocos2d::Action* PlusOne();
	virtual cocos2d::Action* MinusOne();
	virtual cocos2d::Action* MoveTo1();
	virtual cocos2d::Action* MoveTo2();
	virtual cocos2d::Action* MoveTo3();
	virtual cocos2d::Action* MoveToH();
	virtual cocos2d::Action* ChangeSide();
	virtual cocos2d::Sprite* GetSprite(){ return m_spr; };
protected:
	cocos2d::Sprite* m_spr;
	cocos2d::Rect m_defaultRect;
};

