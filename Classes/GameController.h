#pragma once
#include <deque>
class TodoInfo;

class GameController
{
public:
	GameController();
	~GameController();
	TodoInfo* PopTodoList();
	bool IsTodoListEmpty();

private:

	std::deque<TodoInfo*>m_todoList;
};