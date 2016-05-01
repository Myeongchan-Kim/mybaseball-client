#include "header.h"
#include "BallBoard.h"
#include "ConstVar.h"

BallBoard::BallBoard()
{
	m_defaultRect = Rect(
		ConstVar::countBoardRect.getMinX(),
		ConstVar::countBoardRect.getMinY() + ConstVar::countBoardRect.size.height / 3,
		ConstVar::countBoardRect.size.width,
		ConstVar::countBoardRect.size.height / 3
		);

	m_spr = Sprite::create(ConstVar::SQUARE_IMG, Rect(0,0,m_defaultRect.size.width, m_defaultRect.size.height));
	
	SetScaleAndPos();

	//set letter 'B'
	auto letter = Label::create("B", "arial", 15);
	letter->setColor({ 200, 100, 100 });
	letter->setPosition(Point(8, 8));
	m_spr->addChild(letter);
	//set contents.
	for (int i = 0; i < 4; i++)
	{
		auto light = Sprite::create(ConstVar::OFFLIGHT_IMG);
		light->setPosition(23 + 15 * i, 8);
		m_spr->addChild(light);
	}
	m_spr->setName(ConstVar::BALLBOARD_NAME);
	m_spr->retain();
}

BallBoard::~BallBoard()
{
	m_spr->release();
}
