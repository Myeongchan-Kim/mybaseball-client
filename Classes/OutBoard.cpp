#include "header.h"
#include "OutBoard.h"
#include "ConstVar.h"

OutBoard::OutBoard()
{
	m_defaultRect = Rect(
		ConstVar::countBoardRect.getMinX(),
		ConstVar::countBoardRect.getMinY(),
		ConstVar::countBoardRect.size.width,
		ConstVar::countBoardRect.size.height / 3
		);

	m_spr = Sprite::create(ConstVar::SQUARE_IMG, Rect(0,0,m_defaultRect.size.width, m_defaultRect.size.height));
	
	SetScaleAndPos();

	//set letter 'O'
	auto letterO = Label::create("O", "arial", 15);
	letterO->setColor({ 200, 100, 100 });
	letterO->setPosition(Point(8, 8));
	m_spr->addChild(letterO);
	//set contents.
	for (int i = 0; i < 3; i++)
	{
		auto outLight = Sprite::create(ConstVar::OFFLIGHT_IMG);
		outLight->setPosition(23 + 15*i, 8);
		m_spr->addChild(outLight);
	}
	m_spr->setName(ConstVar::OUTBOARD_NAME);
	m_spr->retain();
}

OutBoard::~OutBoard()
{
	m_spr->release();
}
