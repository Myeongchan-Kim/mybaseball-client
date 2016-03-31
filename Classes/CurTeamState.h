#pragma once
class Batter;
class Pitcher;
class Fielder;
class Player;

static class CurTeamState
{
public:
	CurTeamState();
	~CurTeamState();

	Pitcher* curPictcher = nullptr;
	
	Batter* curBatter = nullptr;
	Batter* curBatList[9] = { nullptr, };
	
	Fielder* curFielder[9] = { nullptr, };

	Player* HomeTeam[25];
	Player* AwayTeam[25];

};

