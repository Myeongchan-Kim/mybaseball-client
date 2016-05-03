#pragma once
#include "Unit.h"

class Batter;
class Pitcher;
class Fielder;

class Player : public Unit
{
public:
	Player(int id,std::string name, int batELO, int pitELO);
	virtual ~Player();
	std::string m_name;

private:
	void request_stat(int id);

	Batter* m_batter = nullptr;
	Pitcher* m_pitcher = nullptr;
	Fielder* m_fielder = nullptr;
};

