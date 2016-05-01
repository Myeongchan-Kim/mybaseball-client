#include "header.h"
#include "ConstVar.h"
#include "MainScene.h"
#include "TeamState.h"
#include "PlayScene.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainScene::create();
    scene->addChild(layer);

    return scene;
}

bool MainScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	m_teamInfo = new TeamState();
	m_teamInfo->SetSampleList();

	//stadium
	auto groundSpr = Sprite::create(ConstVar::STADIUM_IMG);
	groundSpr->setName("Ground");
	groundSpr->setScaleX(ConstVar::goundLayerRect.size.width / groundSpr->getContentSize().width);
	groundSpr->setScaleY(ConstVar::goundLayerRect.size.height / groundSpr->getContentSize().height);
	groundSpr->setColor(Color3B(80, 100, 100));
	groundSpr->setAnchorPoint(Point(0, 0));
	addChild(groundSpr);

	//selected player list
	auto selectedPlayerBG = Sprite::create(ConstVar::SQUARE_IMG,
		Rect(0, 0, ConstVar::batterListLayerRect.size.width, ConstVar::batterListLayerRect.size.height));
	selectedPlayerBG->setPosition(ConstVar::batterListLayerRect.getMidX(), ConstVar::batterListLayerRect.getMidY());
	selectedPlayerBG->setColor({ 100, 100, 100 });
	addChild(selectedPlayerBG);

	//all player list
	auto allPlayerBG = Sprite::create(ConstVar::SQUARE_IMG,
		Rect(0, 0, ConstVar::AllPlayersLayerRect.size.width, ConstVar::AllPlayersLayerRect.size.height));
	allPlayerBG->setPosition(ConstVar::AllPlayersLayerRect.getMidX(), ConstVar::AllPlayersLayerRect.getMidY());
	allPlayerBG->setColor({ 50, 50, 50 });
	addChild(allPlayerBG);

	//quit button
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(MainScene::menuCloseCallback, this));
	auto closeItemWidth = closeItem->getContentSize().width;
	auto closeItemHeight = closeItem->getContentSize().height;
	auto closeItemPosX = origin.x + visibleSize.width - closeItemWidth/2;
	auto closeItemPosY = origin.y + closeItemHeight/2;
	closeItem->setPosition(Point(closeItemPosX, closeItemPosY));

	///start button
	auto startItem = MenuItemImage::create();
	startItem->setNormalImage(
		Sprite::create(
			ConstVar::SQUARE_IMG, 
			Rect(0, 0, ConstVar::startMenuRect.size.width, ConstVar::startMenuRect.size.height)));
	startItem->setCallback(CC_CALLBACK_1(MainScene::StartGame, this, m_teamInfo));
	auto startLabel = Label::create("START", "arail", 30);
	startLabel->setPosition(ConstVar::startMenuRect.size.width/2, ConstVar::startMenuRect.size.height/2);
	startItem->addChild(startLabel);
	startItem->setPosition(ConstVar::startMenuRect.getMidX(), ConstVar::startMenuRect.getMidY());

    auto menu = Menu::create(closeItem, startItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    return true;
}

void MainScene::StartGame(Ref* pSender, TeamState* team)
{
	auto playScene = PlayScene::createScene(team);
	Director::getInstance()->replaceScene(playScene);
}

void MainScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
