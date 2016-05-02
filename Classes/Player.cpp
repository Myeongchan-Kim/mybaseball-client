#include "header.h"
#include "Player.h"
#include "Batter.h"
#include "Pitcher.h"
#include "Fielder.h"

Player::Player(int id, int batELO, int pitELO)
{

	m_batter = new Batter(batELO);
	m_pitcher = new Pitcher(pitELO);
	m_fielder = new Fielder();

	request_stat(id);
}


Player::~Player()
{
	delete m_batter;
	delete m_pitcher;
	delete m_fielder;
}

void Player::request_stat(int id)
{

}