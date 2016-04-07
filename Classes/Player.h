#pragma once
class Batter;
class Pitcher;
class Fielder;

class Player
{
public:
	Player(int id);
	~Player();

private:
	void request_stat(int id);

	Batter* batter = nullptr;
	Pitcher* pitcher = nullptr;
	Fielder* Fielder = nullptr;
};

