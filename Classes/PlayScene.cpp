#include "header.h"
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

bool PlayScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	m_groundLayer = LayerColor::create(Color4B(0,20,20,255));

	auto groundSpr = Sprite::create();
	m_groundLayer->addChild(groundSpr);

	m_batterListLayer = Layer::create();
	auto batterListBackground = Sprite::create();
	m_batterListLayer->addChild(batterListBackground);

	m_gameLogLayer = Layer::create();
	m_messegaeLayer = Layer::create();

	m_game = new GameController();

	scheduleUpdate();
	return true;
}

void PlayScene::update(float dt)
{
	while (!m_game->IsTodoListEmpty() && running_obj == 0)
	{
		if (running_obj < 0)
		{
			CCLOG("******RUNNING COUNT ERROR!*****");
			throw true;
		}
			
		Excute(m_game->PopTodoList());
	}
}

void PlayScene::Excute(TodoInfo* todo)
{

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
