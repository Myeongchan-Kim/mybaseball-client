#pragma once
#include "header.h"
#include "TodoInfo.h"

class GameController;
class TeamState;
typedef std::shared_ptr<TodoInfo> P_TodoInfo;

class PlayScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene(TeamState* teamInfo);
	static PlayScene* create(TeamState* teamInfo);

	virtual bool init();
	virtual bool destroy();

private:
	Layer* m_groundLayer = nullptr;
	Layer* m_batterListLayer = nullptr;
	Layer* m_gameLogLayer = nullptr;
	Layer* m_messegaeLayer = nullptr;
	GameController* m_game = nullptr;
	TeamState* m_teamInfo = nullptr;
	int m_actionCounter = 0;

	virtual void update(float dt) override;

	void Excute(P_TodoInfo todo);
	cocos2d::Sprite* GetObjectByTodoInfo(P_TodoInfo todo);
	cocos2d::Action* GetActionByTodoInfo(P_TodoInfo todo, cocos2d::Sprite* spr);
	void IncreseActionCounter();
	void DecreseActionCounter();
	//void AppendSprite(Ref* pSender, cocos2d::Sprite* spr);

	PlayScene(TeamState* teamInfo);
	~PlayScene();
};
 