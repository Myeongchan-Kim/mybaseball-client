#pragma once
#include "Unit.h"

class Batter;
class Pitcher;
class Fielder;

class Player : public Unit
{
public:
	Player(int id);
	virtual ~Player();

private:
	void request_stat(int id);

	Batter* batter = nullptr;
	Pitcher* pitcher = nullptr;
	Fielder* Fielder = nullptr;
};

