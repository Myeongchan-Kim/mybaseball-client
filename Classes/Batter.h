#pragma once
#include "Unit.h"

class Batter : public Unit
{
public:
	Batter();
	Batter(int elo);
	~Batter();

	int m_batELO = 0;
};

