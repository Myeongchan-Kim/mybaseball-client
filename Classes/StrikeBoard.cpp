#include "header.h"
#include "StrikeBoard.h"
#include "ConstVar.h"

StrikeBoard::StrikeBoard()
{
	m_defaultRect = Rect(
		ConstVar::countBoardRect.getMinX(),
		ConstVar::countBoardRect.getMinY() + ConstVar::countBoardRect.size.height / 3 * 2,
		ConstVar::countBoardRect.size.width,
		ConstVar::countBoardRect.size.height / 3
		);

	m_spr = Sprite::create(ConstVar::SQUARE_IMG, Rect(0,0,m_defaultRect.size.width, m_defaultRect.size.height));
	
	SetScaleAndPos();

	//set letter 'S'
	auto letter = Label::create("S", "arial", 15);
	letter->setColor({ 200, 100, 100 });
	letter->setPosition(Point(8, 8));
	m_spr->addChild(letter);
	//set contents.
	for (int i = 0; i < 3; i++)
	{
		auto light = Sprite::create(ConstVar::OFFLIGHT_IMG);
		light->setPosition(23 + 15 * i, 8);
		m_spr->addChild(light);
	}
	m_spr->setName(ConstVar::STRIKEBOARD_NAME);
	m_spr->retain();
}

StrikeBoard::~StrikeBoard()
{
	m_spr->release();
}
