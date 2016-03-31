#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"
class GameController;
class TodoInfo;

class PlayScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	virtual bool destroy();

	CREATE_FUNC(PlayScene);

private:
	Layer* m_groundLayer = nullptr;
	Layer* m_batterListLayer = nullptr;
	Layer* m_gameLogLayer = nullptr;
	Layer* m_messegaeLayer = nullptr;
	GameController* m_game = nullptr;


	virtual void update(float dt) override;
	void Excute(TodoInfo*);

	~PlayScene();
};

#endif // __HELLOWORLD_SCENE_H__
