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

	Pitcher* m_curPitcher;
	Fielder* m_curFielder[9] = {};

	Batter* m_curBatter;
	Batter* m_curBatList[9] = {};
	
	Player* m_homeTeam[25] = {};
	Player* m_awayTeam[25] = {};
	
	Pitcher* m_homePitcher;
	Pitcher* m_awayPitcher;

	Fielder* m_homeFielder[9] = {};
	Fielder* m_awayFielder[9] = {};

	Batter* m_homeBatList[9] = {};
	Batter* m_awayBatList[9] = {};

};

