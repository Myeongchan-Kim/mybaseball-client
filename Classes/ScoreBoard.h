#pragma once
#include "Unit.h"
#include "TodoInfo.h"

class ScoreBoard : public Unit
{
public:
	ScoreBoard(TodoInfo::OBJ_TYPE type);
	~ScoreBoard();

	void SetScore(int score);
	virtual cocos2d::Action* PlusOne() override;
private:
};

