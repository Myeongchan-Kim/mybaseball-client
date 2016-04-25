#pragma once
#include <deque>
#include <memory>
#include "TodoInfo.h"

typedef std::shared_ptr<TodoInfo> P_TodoInfo;

class GameController
{
public:
	GameController();
	~GameController();
	P_TodoInfo PopTodoList();
	bool IsTodoListEmpty();
	void next();

private:

	std::deque<P_TodoInfo>m_todoList;
};