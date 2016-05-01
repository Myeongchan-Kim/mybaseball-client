#pragma once
#include "header.h"

class TeamState;

class MainScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);
private:
	void StartGame(Ref* pSender, TeamState* team);
	TeamState* m_teamInfo;
};
