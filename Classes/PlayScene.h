#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"
class GameController;
class TodoInfo;
class TeamState;

class PlayScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene(TeamState* teamInfo);
	static PlayScene* create(TeamState* teamInfo)
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
	};

	virtual bool init();
	virtual bool destroy();

private:
	Layer* m_groundLayer = nullptr;
	Layer* m_batterListLayer = nullptr;
	Layer* m_gameLogLayer = nullptr;
	Layer* m_messegaeLayer = nullptr;
	GameController* m_game = nullptr;
	TeamState* m_teamInfo = nullptr;


	virtual void update(float dt) override;
	void Excute(TodoInfo*);

	PlayScene(TeamState* teamInfo);
	~PlayScene();
};

#endif // __HELLOWORLD_SCENE_H__
