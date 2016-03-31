#include "PlayScene.h"
#include "GameController.h"
USING_NS_CC;

Scene* PlayScene::createScene()
{
	auto scene = Scene::create();
	auto layer = PlayScene::create();
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

	m_gameLogLayer = Layer::create();
	m_messegaeLayer = Layer::create();

	m_game = new GameController();

	scheduleUpdate();
	return true;
}

void PlayScene::update(float dt)
{
	while (!m_game->IsTodoListEmpty())
	{
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

PlayScene::~PlayScene()
{
	destroy();
}
