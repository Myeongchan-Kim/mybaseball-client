#pragma once
class Batter;
class Pitcher;
class Fielder;
class Player;

class TeamState
{
public:
	TeamState()
	{};
	~TeamState();

	Pitcher* m_curPictcher;
	Fielder* m_curFielder[9] = {};

	Batter* m_curBatter;
	Batter* m_curBatList[9] = {};
	
	Player* m_homeTeam[25] = {};
	Player* m_awayTeam[25] = {};
};

