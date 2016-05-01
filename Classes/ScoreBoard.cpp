#include "header.h"
#include "ScoreBoard.h"
#include "ConstVar.h"
#include "TodoInfo.h"

USING_NS_CC;

ScoreBoard::ScoreBoard(TodoInfo::OBJ_TYPE type)
{
	if (type == TodoInfo::AWAY_SCORE)
	{
		m_defaultRect = Rect(
			ConstVar::scoreBoardRect.getMinX(),
			ConstVar::scoreBoardRect.getMinY(),
			ConstVar::scoreBoardRect.size.width,
			ConstVar::scoreBoardRect.size.height / 2
			);
	}
	else if (type == TodoInfo::HOME_SCORE)
	{
		m_defaultRect = Rect(
			ConstVar::scoreBoardRect.getMinX(),
			ConstVar::scoreBoardRect.getMinY() + ConstVar::scoreBoardRect.size.height / 2,
			ConstVar::scoreBoardRect.size.width,
			ConstVar::scoreBoardRect.size.height / 2
			);
	}
	else
	{
		throw "Wrong Type";
	}
	
	m_spr = Sprite::create(ConstVar::SQUARE_IMG, Rect(0,0,m_defaultRect.size.width, m_defaultRect.size.height));
	
	SetScaleAndPos();

	//set letter
	Label* letter;
	if (type == TodoInfo::AWAY_SCORE)
	{
		letter = Label::create("A", "arail", 20);
		letter->setColor({ 200, 100, 100 });
	}
	else if (type == TodoInfo::HOME_SCORE)
	{
		letter = Label::create("H", "arail", 20);
		letter->setColor({ 100, 200, 200 });
	}
	letter->setPosition(Point(11, 11));
	SetScore(0);
	m_spr->addChild(letter);

	if (type == TodoInfo::AWAY_SCORE)
	{
		m_spr->setName(std::to_string(TodoInfo::AWAY_SCORE));
	}
	else if (type == TodoInfo::HOME_SCORE)
	{
		m_spr->setName(std::to_string(TodoInfo::HOME_SCORE));
	}
	m_spr->retain();
}

ScoreBoard::~ScoreBoard()
{
	m_spr->release();
}

void ScoreBoard::SetScore(int score)
{
	Node* scoreLabel = m_spr->getChildByName("score");
	if( scoreLabel != nullptr)
		scoreLabel->removeFromParent();
	scoreLabel = Label::create(std::to_string(score), "arail", 20);
	scoreLabel->setName("score");
	scoreLabel->setPosition({ 50, 11 });
	m_spr->addChild(scoreLabel);
}

Action* ScoreBoard::PlusOne()
{
	std::string lable = "";
	Label* scoreLabel = static_cast<Label*>(m_spr->getChildByName("score"));
	if (scoreLabel != nullptr)
		lable = scoreLabel->getString();
	int score = std::stoi(lable);
	++score;
	SetScore(score);
	return DelayTime::create(0.0f);
}