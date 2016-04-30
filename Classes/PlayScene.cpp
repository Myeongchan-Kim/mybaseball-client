#include "header.h"
#include "ConstVar.h"
#include "PlayScene.h"
#include "GameController.h"
#include "TodoInfo.h"

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
	groundSpr->setScaleX(ConstVar::goundLayerRect.size.width / groundSpr->getContentSize().width);
	groundSpr->setScaleY(ConstVar::goundLayerRect.size.height / groundSpr->getContentSize().height );
	groundSpr->setColor(Color3B(80, 100, 100));
	groundSpr->setAnchorPoint(Point(0,0));

	//set Count Board
	auto outBoard = Sprite::create(ConstVar::SQUARE_IMG);
	outBoard->setScaleX(ConstVar::countBoardRect.size.width / outBoard->getContentSize().width);
	outBoard->setScaleY(ConstVar::countBoardRect.size.height / 3 / outBoard->getContentSize().height);
	outBoard->setPosition(ConstVar::countBoardRect.getMidX(), ConstVar::countBoardRect.getMidY());


	m_groundLayer->addChild(groundSpr);

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

	Sprite* spr = GetObjectByTodoInfo(todo);
	Action* action = GetActionByTodoInfo(todo, spr);
	Sequence* seq = Sequence::create(start, action, finish, NULL);

	spr->runAction(seq);
}

Sprite* PlayScene::GetObjectByTodoInfo(P_TodoInfo todo)
{
	Sprite * spr = nullptr;
	if (todo->m_doName == TodoInfo::CREATE)
	{
		switch (todo->m_obj){
		case TodoInfo::OUTCOUNT:
			spr = Sprite::create(ConstVar::SQUARE_IMG);
			spr->setScaleX(ConstVar::countBoardRect.size.width / spr->getContentSize().width);
			spr->setScaleY(ConstVar::countBoardRect.size.height / 3 / spr->getContentSize().height);
			spr->setPosition(ConstVar::countBoardRect.getMidX(), ConstVar::countBoardRect.getMidY() - ConstVar::countBoardRect.size.height / 3);
			break;
		case TodoInfo::BALL:
			spr = Sprite::create(ConstVar::SQUARE_IMG);
			spr->setScaleX(ConstVar::countBoardRect.size.width / spr->getContentSize().width);
			spr->setScaleY(ConstVar::countBoardRect.size.height / 3 / spr->getContentSize().height);
			spr->setPosition(ConstVar::countBoardRect.getMidX(), ConstVar::countBoardRect.getMidY());
			break;
		case TodoInfo::STRIKE:
			spr = Sprite::create(ConstVar::SQUARE_IMG);
			spr->setScaleX(ConstVar::countBoardRect.size.width / spr->getContentSize().width);
			spr->setScaleY(ConstVar::countBoardRect.size.height / 3 / spr->getContentSize().height);
			spr->setPosition(ConstVar::countBoardRect.getMidX(), ConstVar::countBoardRect.getMidY());
			break;
		case TodoInfo::OBJ_TYPE::AWAY_SCORE:
			spr = Sprite::create(ConstVar::OUT_IMG);
			break;
		case TodoInfo::OBJ_TYPE::HOME_SCORE:
			spr = Sprite::create(ConstVar::OUT_IMG);
			break;
		case TodoInfo::OBJ_TYPE::BATTER:
			spr = Sprite::create(ConstVar::OUT_IMG);
			break;
		case TodoInfo::OBJ_TYPE::FIELDER:
			spr = Sprite::create(ConstVar::OUT_IMG);
			break;
		case TodoInfo::OBJ_TYPE::PITCHER:
			spr = Sprite::create(ConstVar::OUT_IMG);
			break;
		case TodoInfo::OBJ_TYPE::RUNNER:
			spr = Sprite::create(ConstVar::OUT_IMG);
			break;
		case TodoInfo::OBJ_TYPE::NOW_OFFENCE:
			spr = Sprite::create(ConstVar::OUT_IMG);
			break;
		default:
			throw "Unknown type";
			break;

		}

		spr->setName(todo->m_objName);
	}
	
	return spr;
}

Point PlayScene::GetDefaultPosition(P_TodoInfo todo)
{
	return Point(ConstVar::countBoardRect.getMidX(), ConstVar::countBoardRect.getMidY());
}

Action* PlayScene::GetActionByTodoInfo(P_TodoInfo todo, Sprite* spr)
{
	Action* action = DelayTime::create(0.0f);
	if (todo->m_doName == TodoInfo::CREATE)
	{
		m_groundLayer->addChild(spr);
	}
	else if (todo->m_doName == TodoInfo::REMOVE)
	{

	}
	else if (todo->m_doName == TodoInfo::SET_ZERO)
	{

	}
	else if (todo->m_doName == TodoInfo::PLUS_ONE)
	{

	}
	else if (todo->m_doName == TodoInfo::MINUS_ONE)
	{
	}
	else if (todo->m_doName == TodoInfo::MOVE_TO_1)
	{

	}
	else if (todo->m_doName == TodoInfo::MOVE_TO_2)
	{

	}
	else if (todo->m_doName == TodoInfo::MOVE_TO_3)
	{

	}
	else if (todo->m_doName == TodoInfo::MOVE_TO_H)
	{

	}
	else if (todo->m_doName == TodoInfo::CHANGE_SIDE)
	{

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