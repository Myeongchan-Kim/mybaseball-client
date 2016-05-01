#include "header.h"
#include "GameController.h"
#include "TodoInfo.h"

GameController::GameController()
{
}


GameController::~GameController()
{
}

void GameController::next()
{
	static bool tmpFlag = false;
	if (tmpFlag == false)
	{
		P_TodoInfo todo = std::make_shared<TodoInfo>();

		todo->m_obj = TodoInfo::OBJ_TYPE::OUTCOUNT;
		todo->m_objName = std::to_string(TodoInfo::OBJ_TYPE::OUTCOUNT);
		todo->m_doName = TodoInfo::DO_NAME::PLUS_ONE;
		m_todoList.push_back(todo);

		todo->m_obj = TodoInfo::OBJ_TYPE::OUTCOUNT;
		todo->m_objName = std::to_string(TodoInfo::OBJ_TYPE::OUTCOUNT);
		todo->m_doName = TodoInfo::DO_NAME::PLUS_ONE;
		m_todoList.push_back(todo);

		todo->m_obj = TodoInfo::OBJ_TYPE::OUTCOUNT;
		todo->m_objName = std::to_string(TodoInfo::OBJ_TYPE::OUTCOUNT);
		todo->m_doName = TodoInfo::DO_NAME::PLUS_ONE;
		m_todoList.push_back(todo);
		tmpFlag = true;
	}
}

P_TodoInfo GameController::PopTodoList(){
	auto todo = m_todoList.front();
	m_todoList.pop_front();

	return todo;
}

bool GameController::IsTodoListEmpty(){
	return m_todoList.empty();
}