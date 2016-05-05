#pragma once

class Batter;
class Pitcher;
class Fielder;
class Player;

class TeamState
{
public:
	TeamState();
	~TeamState();

	Player* m_homeTeam[25] = {};
	Player* m_awayTeam[25] = {};

	Player* m_homeFielder[9] = {};
	Player* m_awayFielder[9] = {};

	Player* m_homeBatList[9] = {};
	Player* m_awayBatList[9] = {};

	Player* m_homePitcher;
	Player* m_awayPitcher;

	Player* m_curPitcher;
	Player* m_curFielder[9] = {};

	Player* m_curBatter;
	Player* m_curBatList[9] = {};
	
	
	std::string m_teamNameH;
	std::string m_teamNameA;

	void SetSampleList();
	Player* GetPlayer(std::string teamName, int idx);
};
