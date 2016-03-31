#pragma once
class Batter;
class Pitcher;
class Fielder;

class Player
{
public:
	Player();
	~Player();

private:
	Batter* batter;
	Pitcher* pitcher;
	Fielder* Fielder;
};

