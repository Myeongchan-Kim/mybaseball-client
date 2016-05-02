#pragma once
#include "Unit.h"

class Pitcher :public Unit
{
public:
	Pitcher();
	Pitcher(int elo);
	~Pitcher();

	int m_pitELO = 0;
};

