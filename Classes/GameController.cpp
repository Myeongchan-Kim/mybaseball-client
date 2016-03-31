#include "GameController.h"


GameController::GameController()
{
}


GameController::~GameController()
{
}

TodoInfo* GameController::PopTodoList(){
	auto todo = m_todoList.front();
	m_todoList.pop_front();

	return todo;
}

bool GameController::IsTodoListEmpty(){
	return m_todoList.empty();
}