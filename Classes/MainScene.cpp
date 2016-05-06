#include "header.h"
#include "ConstVar.h"
#include "MainScene.h"
#include "TeamState.h"
#include "PlayScene.h"
#include "Player.h"


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

	Vector<MenuItem*> menuItems;

	//stadium
	auto groundSpr = Sprite::create(ConstVar::STADIUM_IMG);
	groundSpr->setName("Ground");
	groundSpr->setScaleX(ConstVar::goundLayerRect.size.width / groundSpr->getContentSize().width);
	groundSpr->setScaleY(ConstVar::goundLayerRect.size.height / groundSpr->getContentSize().height);
	groundSpr->setColor(Color3B(80, 100, 100));
	groundSpr->setAnchorPoint(Point(0, 0));
	addChild(groundSpr);
	
	m_teamInfo = new TeamState();
	m_teamInfo->SetSampleList();
	std::string AwayTeamName = m_teamInfo->m_teamNameA;
	std::string HomeTeamName = m_teamInfo->m_teamNameH;
	
	//selected player list
	auto selectedPlayerBG = Sprite::create(ConstVar::SQUARE_IMG,
		Rect(0, 0, ConstVar::batterListLayerRect.size.width, ConstVar::batterListLayerRect.size.height));
	selectedPlayerBG->setPosition(ConstVar::batterListLayerRect.getMidX(), ConstVar::batterListLayerRect.getMidY());
	selectedPlayerBG->setColor({ 100, 100, 100 });
	//Vector<MenuItem*> selectedList;
	//auto selectedPlayerMenu = Menu::createWithArray(selectedList);
	//selectedPlayerBG->addChild(selectedPlayerMenu);
	addChild(selectedPlayerBG);

	//all player list
	auto allPlayerBG = Sprite::create(ConstVar::SQUARE_IMG,
		Rect(0, 0, ConstVar::AllPlayersLayerRect.size.width, ConstVar::AllPlayersLayerRect.size.height));
	allPlayerBG->setPosition(ConstVar::AllPlayersLayerRect.getMidX(), ConstVar::AllPlayersLayerRect.getMidY());
	allPlayerBG->setColor({ 50, 50, 50 });
	
	Vector<MenuItem*> playerList;
	for (int i = 0; i < 25; i++)
	{
		Player* player = m_teamInfo->GetPlayer(m_teamInfo->m_teamNameH, i);
		auto playerItem = MakeMenuItemFromPlayer(player);
		playerItem->setPosition(
			ConstVar::AllPlayersLayerRect.getMidX(),
			ConstVar::AllPlayersLayerRect.getMaxY() - ConstVar::playerRect.size.height / 2 *(2*i+1) );
		playerList.pushBack(playerItem);
	}
	auto playerMenu = Menu::createWithArray(playerList);
	playerMenu->setPosition(Vec2::ZERO);
	playerMenu->setName("playerList");
	addChild(allPlayerBG);
	addChild(playerMenu);

	auto _mouseListener = EventListenerMouse::create();
	_mouseListener->onMouseScroll = CC_CALLBACK_1(MainScene::onMouseScroll, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);


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
	menuItems.pushBack(closeItem);

	///start button
	auto startItem = MenuItemImage::create();
	startItem->setNormalImage(
		Sprite::create(
			ConstVar::SQUARE_IMG, 
			Rect(0, 0, ConstVar::startMenuRect.size.width, ConstVar::startMenuRect.size.height)));
	startItem->setCallback(CC_CALLBACK_1(MainScene::StartGame, this, m_teamInfo));
	auto startLabel = Label::create("START", "arial", 30);
	startLabel->setPosition(ConstVar::startMenuRect.size.width/2, ConstVar::startMenuRect.size.height/2);
	startItem->addChild(startLabel);
	startItem->setPosition(ConstVar::startMenuRect.getMidX(), ConstVar::startMenuRect.getMidY());
	menuItems.pushBack(startItem);
	
	auto menu = Menu::createWithArray(menuItems);
	menu->setPosition(Vec2::ZERO);
	addChild(menu);

    return true;
}

MenuItemImage* MainScene::MakeMenuItemFromPlayer(Player * p)
{
	auto playerItem = MenuItemImage::create();
	playerItem->setNormalImage(p->GetSprite());
	playerItem->setAnchorPoint({ 0.5, 0.5 });
	auto nameTag = Label::create(p->m_name, "arial", 12);
	nameTag->setPosition(ConstVar::playerRect.getMidX(), ConstVar::playerRect.getMidY());
	playerItem->addChild(nameTag);
	return playerItem;
}

void MainScene::onMouseScroll(Event *ev)
{
	EventMouse* e = (EventMouse*)ev;
	if (e->getScrollY())
	{
		auto scrollAmount = e->getScrollY();
		auto playerList = getChildByName("playerList");
		auto pos = playerList->getPositionY();
		pos += scrollAmount*3;
		playerList->setPositionY(pos);
	}
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
