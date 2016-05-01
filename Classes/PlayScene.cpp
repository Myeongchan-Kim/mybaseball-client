#include "header.h"
#include "ConstVar.h"
#include "PlayScene.h"
#include "GameController.h"
#include "TodoInfo.h"
#include "OutBoard.h"
#include "BallBoard.h"
#include "StrikeBoard.h"
#include "ScoreBoard.h"
#include <assert.h>

USING_NS_CC;

Scene* PlayScene::createScene(TeamState* teamInfo)
{
	auto scene = Scene::create();
	auto layer = PlayScene::create(teamInfo);
	scene->addChild(layer);

	return scene;
}

PlayScene* PlayScene::create(TeamState* teamInfo)
{
	PlayScene *pRet = new(std::nothrow) PlayScene(teamInfo);
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool PlayScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	m_groundLayer = LayerColor::create(Color4B(0,20,20,255));
	m_groundLayer->setPosition(0, 0);

	//stadium
	auto groundSpr = Sprite::create(ConstVar::STADIUM_IMG);
	groundSpr->setName("Ground");
	groundSpr->setScaleX(ConstVar::goundLayerRect.size.width / groundSpr->getContentSize().width);
	groundSpr->setScaleY(ConstVar::goundLayerRect.size.height / groundSpr->getContentSize().height );
	groundSpr->setColor(Color3B(80, 100, 100));
	groundSpr->setAnchorPoint(Point(0,0));
	m_groundLayer->addChild(groundSpr);

	//set Count Board
	P_Unit outBoard = std::make_shared<OutBoard>();
	m_groundLayer->addChild(outBoard->GetSprite());
	m_unitList.insert(std::pair<std::string, P_Unit>(std::to_string(TodoInfo::OUTCOUNT), outBoard));
	
	P_Unit strikeBoard = std::make_shared<StrikeBoard>();
	m_groundLayer->addChild(strikeBoard->GetSprite());
	m_unitList.insert(std::pair<std::string, P_Unit>(std::to_string(TodoInfo::STRIKE), strikeBoard));
	
	P_Unit ballBoard = std::make_shared<BallBoard>();
	m_groundLayer->addChild(ballBoard->GetSprite());
	m_unitList.insert(std::pair<std::string, P_Unit>(std::to_string(TodoInfo::BALL), ballBoard));

	//set Score Board
	P_Unit HscoreBoard = std::make_shared<ScoreBoard>(TodoInfo::HOME_SCORE);
	m_groundLayer->addChild(HscoreBoard->GetSprite());
	m_unitList.insert(std::pair<std::string, P_Unit>(std::to_string(TodoInfo::HOME_SCORE), HscoreBoard));
	P_Unit AscoreBoard = std::make_shared<ScoreBoard>(TodoInfo::AWAY_SCORE);
	m_groundLayer->addChild(AscoreBoard->GetSprite());
	m_unitList.insert(std::pair<std::string, P_Unit>(std::to_string(TodoInfo::AWAY_SCORE), AscoreBoard));

	m_batterListLayer = Layer::create();
	//auto batterListBackground = Sprite::create(ConstVar::SQUARE_IMG, Rect(200, 0 , 200, 200));
	//m_batterListLayer->addChild(batterListBackground);

	m_gameLogLayer = Layer::create();
	m_messegaeLayer = Layer::create();

	m_game = new GameController();


	addChild(m_groundLayer);
	addChild(m_batterListLayer);
	addChild(m_gameLogLayer);
	addChild(m_messegaeLayer);
	scheduleUpdate();
	return true;
}

void PlayScene::update(float dt)
{
	if (m_actionCounter == 0)
	{
		m_game->next();

		while (!m_game->IsTodoListEmpty())
		{
			Excute(m_game->PopTodoList());
		}
		return;
	}

	if (m_actionCounter < 0)
	{
		CCLOG("******RUNNING COUNT ERROR!*****");
		throw true;
	}
}

void PlayScene::Excute(P_TodoInfo todo)
{
	//playing Action counter
	CallFunc* start = CallFunc::create(CC_CALLBACK_0(PlayScene::IncreseActionCounter, this));
	CallFunc* finish = CallFunc::create(CC_CALLBACK_0(PlayScene::DecreseActionCounter, this));

	Sprite* spr = GetSpriteByTodoInfo(todo);
	Action* action = GetActionByTodoInfo(todo);
	Sequence* seq = Sequence::create(start, action, finish, NULL);

	spr->runAction(seq);
}

Sprite* PlayScene::GetSpriteByTodoInfo(P_TodoInfo todo)
{
	Sprite * spr = nullptr;
	if (todo->m_doName == TodoInfo::CREATE)
	{
		
	}
	else{
		auto pair = m_unitList.find(todo->m_objName);
		if (pair != m_unitList.end())
			spr = pair->second->GetSprite();
		else
			throw "Unknown obj";
	}
	
	assert(spr != nullptr);
	return spr;
}

Point PlayScene::GetDefaultPosition(P_Unit unit)
{
	return Point(ConstVar::countBoardRect.getMidX(), ConstVar::countBoardRect.getMidY());
}

Action* PlayScene::GetActionByTodoInfo(P_TodoInfo todo)
{
	auto pair = m_unitList.find(todo->m_objName);
	if (pair == m_unitList.end())
		throw "No unit";
	auto unit = pair->second;

	Action* action = DelayTime::create(0.0f);
	if (todo->m_doName == TodoInfo::CREATE)
	{
		m_groundLayer->addChild(unit->GetSprite());
	}
	else if (todo->m_doName == TodoInfo::REMOVE)
	{
		m_groundLayer->removeChild(unit->GetSprite());
	}
	else if (todo->m_doName == TodoInfo::SET_ZERO)
	{
		action = unit->SetZero();
	}
	else if (todo->m_doName == TodoInfo::PLUS_ONE)
	{
		action = unit->PlusOne();
	}
	else if (todo->m_doName == TodoInfo::MINUS_ONE)
	{
		action = unit->MinusOne();
	}
	else if (todo->m_doName == TodoInfo::MOVE_TO_1)
	{
		action = unit->MoveTo1();
	}
	else if (todo->m_doName == TodoInfo::MOVE_TO_2)
	{
		action = unit->MoveTo2();
	}
	else if (todo->m_doName == TodoInfo::MOVE_TO_3)
	{
		action = unit->MoveTo3();
	}
	else if (todo->m_doName == TodoInfo::MOVE_TO_H)
	{
		action = unit->MoveToH();
	}
	else if (todo->m_doName == TodoInfo::CHANGE_SIDE)
	{
		action = unit->ChangeSide();
	}
	else{
		throw "Unknown action";
	}

	return action;
}

bool PlayScene::destroy()
{
	delete m_game;
	return false;
}


PlayScene::PlayScene(TeamState* teamInfo) : m_teamInfo(teamInfo)
{
};


PlayScene::~PlayScene()
{
	destroy();
}


void PlayScene::IncreseActionCounter()
{
	++m_actionCounter;
}

void PlayScene::DecreseActionCounter()
{
	--m_actionCounter;
}

//
//void PlayScene::AppendSprite(Ref* pSender, Sprite* spr)
//{
//	this->addChild(spr);
//}