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

    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MainScene::menuCloseCallback, this));

	TeamState* tmpTeam = new TeamState();
	
	auto closeItemWidth = closeItem->getContentSize().width;
	auto closeItemHeight = closeItem->getContentSize().height;
	auto closeItemPosX = origin.x + visibleSize.width - closeItemWidth/2;
	auto closeItemPosY = origin.y + closeItemHeight/2;
	closeItem->setPosition(Point(closeItemPosX, closeItemPosY));

	auto startItem = MenuItemImage::create(ConstVar::SQAURE_IMG, ConstVar::SQAURE_IMG, CC_CALLBACK_1(MainScene::StartGame, this, tmpTeam));
	startItem->setScaleX(1.0);
	startItem->setScaleY(0.5);
	auto startItemWidth = startItem->getContentSize().width;
	startItem->setPosition(closeItem->getPosition() - Point(closeItemWidth + startItemWidth, 0)/2);

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
