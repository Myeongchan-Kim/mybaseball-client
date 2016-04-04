#pragma once
#include <iostream>

class TodoInfo
{
public:

	enum OBJ_NAME
	{
		STRIKE,
		BALL,
		OUTCOUNT,
		RUNNER,
		BATTER,
		PITCHER,
		FIELDER,
		HOME_SCORE,
		AWAY_SCORE,
		NOW_OFFENCE,
		
	};

	enum DO_NAME
	{
		CREATE,
		REMOVE,
		SET_ZERO,
		PLUS_ONE,
		MINUS_ONE,
		MOVE_TO_1,
		MOVE_TO_2,
		MOVE_TO_3,
		MOVE_TO_H,
		CHANGE_SIDE
	};

	TodoInfo();
	~TodoInfo();

	OBJ_NAME m_obj;
	std::string m_objName;
	
	DO_NAME m_doName;

};

